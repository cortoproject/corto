/*
 * cx_deserxml.c
 *
 *  Created on: Mar 19, 2012
 *      Author: sander
 */

#include "cx_xml_deser.h"
#include "cortex.h"
#include "cx_class.h"
#include "cx_xmlreader.h"
#include "cx_loader.h"

#include "stdlib.h"
#include "string.h"

typedef struct deser_xmldata_s* deser_xmldata;
typedef struct deser_xmldata_s {
    cx_xmlnode reader;
    cx_xmlnode node;
    cx_object scope;
    cx_object cur;
    cx_string file;
    cx_uint32 line;
    cx_ll attrParsed;
    cx_ll using;
}deser_xmldata_s;

typedef enum cx_deserXmlScope {
    XML_OBJECT,
    XML_ELEMENT,
    XML_MEMBER
}cx_deserXmlScope;

#define xml_error(data, ...) printf("%s: %d: ", data->file, data->line); cx_error(__VA_ARGS__);
#define xml_warning(data, ...) printf("%s: %d: ", data->file, data->line); cx_warning(__VA_ARGS__);

#define XML_NODE(nodePtr, data) (data)->line = cx_xmlnodeLine(nodePtr); (data)->node = nodePtr;

int cx_deserXmlMeta(cx_xmlnode node, cx_deserXmlScope scope, deser_xmldata data);
int cx_deserXmlMetaExt(cx_xmlnode node, cx_deserXmlScope scope, cx_type t, void* o, deser_xmldata data);
int cx_deserXmlValue(cx_xmlnode node, cx_deserXmlScope scope, cx_type t, void* o, deser_xmldata data);
int cx_deserXmlNode(cx_xmlnode node, deser_xmldata data);

/* Set parsed attribute */
void cx_deserXmlMemberSet(cx_string name, deser_xmldata data) {
    if (!data->attrParsed) {
        data->attrParsed = cx_llNew();
    }
    cx_llInsert(data->attrParsed, name);
}

/* Check if attribute is parsed */
int cx_deserXmlMemberCheck(cx_string name, deser_xmldata data) {
    if (data->attrParsed) {
        cx_string result = (cx_string)cx_llFind(data->attrParsed, (cx_walkAction)strcmp, name);
        return result != 0;
    } else {
        return 0;
    }
}

/* Set parsed attribute */
void cx_deserXmlNsUse(cx_string ns, deser_xmldata data) {
    cx_object o;
    if (!data->using) {
        data->using = cx_llNew();
    }

    o = cx_lookup(data->scope, ns);
    if (!o) {
        xml_error(data, "namespace '%s' unresolved.", ns);
    } else {
        cx_llAppend(data->using, o);
        cx_release(o);
    }
}

/* Resolve object, and if object is not found, look it up in 'using' namespaces */
cx_object cx_deserXmlNsResolve(cx_object src, cx_string name, deser_xmldata data) {
    cx_object o, ns;

    CX_UNUSED(src);

    o = cx_resolve(data->scope, name);
    if (!o) {
        if (data->using) {
            cx_iter iter;

            iter = cx_llIter(data->using);
            while(!o && cx_iterHasNext(&iter)) {
                ns = cx_iterNext(&iter);
                o = cx_lookup(ns, name);
            }
        }
    }
    return o;
}

/* Clone deserdata */
deser_xmldata_s cx_deserXmlDataClone(deser_xmldata data) {
    deser_xmldata_s result;

    result = *data;
    result.attrParsed = 0;
    if (data->scope) {
        cx_claim(data->scope);
    }
    return result;
}

/* Free deserdata */
void cx_deserXmlDataFree(deser_xmldata data) {
    if (data->attrParsed) {
        cx_llFree(data->attrParsed);
        data->attrParsed = (void*)-1; /* Will crash if attempts are made to dereference it */
    }
    if (data->scope) {
        cx_release(data->scope);
    }
}

/* (Forward) declare object */
cx_object cx_deserXmlDeclare(deser_xmldata data, cx_string name, cx_type t) {
    cx_object o;

    /* Find or create object */
    if (!(o = cx_lookup(data->scope, name))) {
        o = cx_declareChild(data->scope, name, t);
    } else {
        cx_release(o);
    }

    return o;
}

/* Deserialize reference */
int cx_deserXmlReference(const char* str, cx_type t, void* o, deser_xmldata data) {
    if (!strcmp(str, "<null>")) {
        *(cx_void**)o = 0;
    } else {
        cx_object ref;
        cx_id fullname_1;
        cx_id fullname_2;
        cx_id fullname_3;

        ref = cx_resolve(data->scope, (cx_string)str);
        if (ref) {
            /* Check if resolved object has the right type */
            if ((cx_typeof(ref) == t) || (cx_class_instanceof(cx_class_o, t) && cx_class_instanceof(cx_class(t), ref)) || (t->kind == CX_VOID)) {
                *(cx_void**)o = ref;
            } else {
                xml_error(data, "reference to object '%s' of type '%s' does not match reference type '%s'.",
                        cx_fullname(ref, fullname_1),
                        cx_fullname(cx_typeof(ref), fullname_2),
                        cx_fullname(t, fullname_3)); goto error;
            }
        } else {
            xml_error(data, "unresolved object '%s'.", str); goto error;
        }
    }

    return 0;
error:
    return -1;
}

/* Deserialize primitive */
int cx_deserXmlPrimitive(const char* str, cx_type t, void* o, deser_xmldata data) {
    cx_void* toValue;
    cx_type type;

    if (!str) {
        cx_id fullname;
        xml_error(data, "invalid value for primitive of type '%s'.", cx_fullname(t, fullname));
        goto error;
    }
    type = t;

    /* Parse reference string, take into account scoping */
    if (strlen(str)) {
        if (type->reference) {
            if (cx_deserXmlReference(str, (cx_type)type, o, data)) {
                goto error;
            }
        } else {
            /* Transform string to value using database transformations */
            if (cx_convert(cx_primitive(cx_string_o), (char**)&str, cx_primitive(t), &toValue)) {
                cx_id fullname;
                xml_error(data, "transformation from string to primitive type '%s' failed.", cx_fullname(t, fullname));
                goto error;
            } else {
                /* Copy new value */
                memcpy(o, &toValue, t->size);
            }
        }
    }

    return 0;
error:
    return -1;
}

/* Create new collection */
int cx_deserXmlCollectionNew(cx_type t, void* o) {
    cx_collection ctype;

    ctype = (cx_collection)t;

    switch(ctype->kind) {
    case CX_ARRAY:
        break;
    case CX_SEQUENCE:
        ((cx_objectSeq*)o)->length = 0;
        ((cx_objectSeq*)o)->buffer = 0;
        break;
    case CX_LIST:
        *((cx_ll*)o) = cx_llNew();
        break;
    case CX_MAP:
        *((cx_rbtree*)o) = cx_rbtreeNew(((cx_map)ctype)->keyType);
        break;
    default:
        cx_error("parser error: not a valid collection kind for 'cx_deserXmlCollectionNew'.");
        goto error;
    }

    return 0;
error:
    return -1;
}

typedef struct deser_xmlElementData {
    void* collection;
    cx_type t;
    deser_xmldata data;
    cx_uint32 count;
    cx_bool othersAllowed;
}deser_xmlElementData;

/* Create new element */
void* cx_deserXmlCollectionNewElement(deser_xmlElementData* data) {
    cx_collection ctype;
    cx_objectSeq* seq;
    cx_uint32 elementSize;
    void* result;

    ctype = (cx_collection)data->t;
    elementSize = cx_type_sizeof(ctype->elementType);
    result = 0;

    cx_assert(elementSize, "collection has elementType of size 0.");

    switch(ctype->kind) {
    case CX_ARRAY:
        result = data->collection;
        data->collection = CX_OFFSET(data->collection, elementSize);
        break;
    case CX_SEQUENCE:
        seq = (cx_objectSeq*)data->collection;
        seq->buffer = cx_realloc(seq->buffer, (seq->length+1) * elementSize);
        result = CX_OFFSET(seq->buffer, elementSize * seq->length);
        seq->length++;
        break;
    case CX_LIST:
    case CX_MAP:
        result = cx_alloc(elementSize);
        break;
    default:
        {
            cx_id fullname;
            xml_error(data->data, "cannot create element for type '%s' that is not a collection.", cx_fullname(data->t, fullname));
        }
        break;
    }

    /* Initialize elements to zero */
    if (result) {
        memset(result, 0, elementSize);
    }

    return result;
}

/* Insert new element */
int cx_deserXmlCollectionInsertElement(cx_xmlnode node, void* o, deser_xmlElementData* data) {
    cx_collection ctype;

    ctype = (cx_collection)data->t;

    switch(ctype->kind) {
    case CX_ARRAY:
    case CX_SEQUENCE:
        /* Do nothing */
        break;
    case CX_LIST:
        /* Insert element in list */
        cx_llAppend(*(cx_ll*)data->collection, o);
        break;
    case CX_MAP:
        {
            cx_string key;
            cx_void* toValue;

            /* Retrieve key */
            key = cx_xmlnodeAttrStr(node, "key");

            /* Cast string to key value */
            if (cx_convert(cx_primitive(cx_string_o), &key, cx_primitive(cx_rbtreeKeyType(*(cx_rbtree*)data->collection)), &toValue)) {
                cx_id fullname;
                xml_error(data->data, "transformation from string to primitive map keytype '%s' failed.",
                        cx_fullname(cx_rbtreeKeyType(*(cx_rbtree*)data->collection), fullname));
                goto error;
            }

            /* Insert element in map */
            cx_rbtreeSet(*(cx_rbtree*)data->collection, toValue, o);
            break;
        }
    default:
        xml_error(data->data, "parser error: not a collectiontype in cx_deserXmlCollectionInsertElement.");
        goto error;
    }

    return 0;
error:
    return -1;
}

/* Deserialize elements */
int cx_deserXmlElement(cx_xmlnode node, deser_xmlElementData* userData) {
    cx_collection ctype;
    cx_type subtype;
    void* o;

    XML_NODE(node, userData->data);

    ctype = (cx_collection)userData->t;
    subtype = ((cx_collection)ctype)->elementType;

    /* Check if element belongs to collection */
    if (cx_xmlnodeNs(node) && !strcmp(cx_xmlnodeNs(node), "meta")) {
        if (!strcmp(cx_xmlnodeName(node), "object") || !strcmp(cx_xmlnodeName(node), "element")) {
            /* Acquire pointer to new element */
            o = cx_deserXmlCollectionNewElement(userData);
            if (!o) {
                xml_error(userData->data, "parser erorr: failed to create collection element.");
                goto error;
            }
            /* Deserialize collection */
            if (cx_deserXmlMetaExt(node, XML_ELEMENT, subtype, o, userData->data)) {
                xml_error(userData->data, "failed to deserialize element.");
                goto error;
            }
        } else {
            if (userData->othersAllowed) {
                goto ok;
            } else {
                xml_error(userData->data, "invalid meta-tag for element (expected 'meta:object', 'meta:element' or elementType name).");
                goto error;
            }
        }

    /* Element subtype is used as tagname */
    } else if (cx_checkAttr(subtype, CX_ATTR_SCOPED) && !strcmp(cx_nameof(subtype), cx_xmlnodeName(node))) {
        deser_xmldata_s privateData;

        privateData = cx_deserXmlDataClone(userData->data);

        /* Acquire pointer to new element */
        o = cx_deserXmlCollectionNewElement(userData);
        if (!o) {
            xml_error(userData->data, "couldn't obtain pointer to element.")
            goto error;
        }

        /* If collection is a map, mark the 'key' attribute as processed so it won't be read as member */
        if (cx_collection(userData->t)->kind == CX_MAP) {
            cx_deserXmlMemberSet("key", &privateData);
        }
        if (cx_deserXmlValue(node, XML_ELEMENT, subtype, o, &privateData)) {
            xml_error(userData->data, "failed to deserialize value of element.");
            goto error;
        }
        cx_deserXmlDataFree(&privateData);

    /* Node that does not belong to this collection */
    } else {
        if (userData->othersAllowed) {
            /* node is a member or element of other collection type */
            goto ok;
        } else {
            xml_error(userData->data, "unexpected element tag '%s' in collection.", cx_xmlnodeName(node));
            goto error;
        }
    }

    /* Insert element */
    if (cx_deserXmlCollectionInsertElement(node, o, userData)) {
        goto error;
    }

ok:
    return 1;
error:
    xml_error(userData->data, "failed to deserialize element.");
    return 0;
}

/* Deserialize collection - using regular notation */
int cx_deserXmlCollection(cx_xmlnode node, cx_type t, void* o, cx_bool othersAllowed, deser_xmldata data) {
    deser_xmlElementData walkData;
    deser_xmldata_s privateData;

    privateData = cx_deserXmlDataClone(data);

    /* Create collection */
    if (cx_deserXmlCollectionNew(t, o)) {
        goto error;
    }

    /* Walk elements */
    walkData.collection = o;
    walkData.t = t;
    walkData.data = &privateData;
    walkData.count = 0;
    walkData.othersAllowed = othersAllowed; /* Don't allow members or elements from other collections within scope */
    if (!cx_xmlnodeWalkChildren(node, (cx_xmlreaderWalkCallback)cx_deserXmlElement, &walkData)) {
        xml_error(data, "An error occured while deserializing elements of collection '%s'.", cx_xmlnodeName(node));
        goto error;
    }

    cx_deserXmlDataFree(&privateData);
    return 0;
error:
    cx_deserXmlDataFree(&privateData);
    return -1;
}

typedef struct deser_xmlMemberData_s* deser_xmlMemberData;
typedef struct deser_xmlMemberData_s {
    cx_type t;
    void* o;
    deser_xmldata data;
}deser_xmlMemberData_s;

/* Deserialize attribute */
static int cx_deserXmlAttrWalk(cx_string ns, cx_string attr, cx_string content, deser_xmlMemberData userData) {
    cx_member member;
    cx_type t;
    CX_UNUSED(ns);

    /* Check if attribute has not been consumed yet */
    if (cx_deserXmlMemberCheck(attr, userData->data)) {
        goto ok;
    }

    /* Lookup member */
    member = cx_interface_resolveMember(cx_interface(userData->t), attr);
    if (member) {
        t = member->type;
        /* Check if member is of a primitive type */
        if ((t->kind == CX_PRIMITIVE) || t->reference) {
            if (cx_deserXmlPrimitive(content, member->type, CX_OFFSET(userData->o, member->offset), userData->data)) {
                goto error;
            }
        } else {
            xml_error(userData->data, "non-primitive member '%s' cannot be specified as attribute.", attr);
            goto error;
        }
    } else {
        cx_id fullname;
        xml_error(userData->data, "type '%s' has no member '%s'.", cx_fullname(userData->t, fullname), attr);
        goto error;
    }

    /* Mark attribute as consumed */
    cx_deserXmlMemberSet(attr, userData->data );

ok:
    return 1;
error:
    return 0;
}

/* Check if node is element of inlined collection */
cx_string cx_deserXmlIsInlinedElement(cx_string type, deser_xmlMemberData userData) {
    cx_interface s;
    cx_type subtype;
    cx_uint32 i;
    cx_string result;
    cx_member m;


    s = cx_interface(userData->t);
    result = 0;

    /* Look for collections that can be used inlined */
    for(i=0; i<s->members.length; i++) {
        m = s->members.buffer[i];
        if (m->type->kind == CX_COLLECTION) {
            subtype = ((cx_collection)m->type)->elementType;
            if (cx_checkAttr(subtype, CX_ATTR_SCOPED) && !strcmp(cx_nameof(subtype), type)) {
                result = cx_nameof(s->members.buffer[i]);
                break;

            /* Compare fully qualified names */
            } else {
                cx_id subtypeName;
                cx_id typeName;
                cx_object o;

                o = cx_lookup(userData->data->scope, type);
                if (o) {
                    if (!strcmp(cx_fullname(subtype, subtypeName), cx_fullname(o, typeName))) {
                        result = cx_nameof(s->members.buffer[i]);
                        break;
                    }
                    cx_release(o);
                }
            }
        }
    }

    return result;
}

/* Deserialize inlined member */
int cx_deserXmlInlinedMember(cx_xmlnode node, cx_string name, deser_xmlMemberData userData) {
    cx_member member;
    cx_string memberName;

    memberName = 0;

    /* Check if this node is actually an element of an inlined collection */
    if ((memberName = cx_deserXmlIsInlinedElement((cx_string)name, userData))) {
        if (!cx_deserXmlMemberCheck(memberName, userData->data)) {

            /* Lookup member */
            member = cx_resolve(userData->t, memberName);
            if (member) {

                /* Deserialize collection */
                if (cx_deserXmlCollection(cx_xmlnodeParent(node), member->type, CX_OFFSET(userData->o, member->offset), 1, userData->data)) {
                    cx_release(member);
                    goto error;
                }
                cx_release(member);
            }
        }

        /* Set member as processed - so collection won't be parsed again. */
        cx_deserXmlMemberSet(memberName, userData->data);
    } else {
        cx_id fullname;
        xml_error(userData->data, "type '%s' has no member named- or inlined collection with subtype '%s'.", cx_fullname(userData->t, fullname), name);
        goto error;
    }

    return 0;
error:
    return -1;
}

/* Deserialize membernodes */
static int cx_deserXmlMemberWalk(cx_xmlnode node, deser_xmlMemberData userData) {
    cx_member member;

    XML_NODE(node, userData->data);

    if (cx_xmlnodeNs(node) && !strcmp(cx_xmlnodeNs(node), "meta")) {
        if (cx_deserXmlMetaExt(node, XML_MEMBER, userData->t, userData->o, userData->data)) {
            goto error;
        }
    } else {

        /* Lookup member */
        member = cx_interface_resolveMember(cx_interface(userData->t), (cx_string)cx_xmlnodeName(node));
        if (member) {
            deser_xmldata_s privateData = *userData->data;

            privateData.attrParsed = 0;
            if (cx_deserXmlValue(node, XML_MEMBER, member->type, CX_OFFSET(userData->o, member->offset), &privateData)) {
                goto error;
            }
            if (privateData.attrParsed) {
                cx_llFree(privateData.attrParsed);
            }
        } else {
            if (cx_deserXmlInlinedMember(node, (cx_string)cx_xmlnodeName(node), userData)) {
                goto error;
            }
        }
    }

    return 1;
error:
    return 0;
}

/* Deserialize complex type */
int cx_deserXmlComplex(cx_xmlnode node, cx_type t, void* o, deser_xmldata data) {
    deser_xmlMemberData_s walkData;

    walkData.o = o;
    walkData.t = t;
    walkData.data = data;

    /* Deserialize attributes */
    if (!cx_xmlnodeWalkAttr(node, (cx_xmlreaderWalkAttrCallback)cx_deserXmlAttrWalk, &walkData)) {
        goto error;
    }

    /* Deserialize childnodes */
    if (!cx_xmlnodeWalkChildren(node, (cx_xmlreaderWalkCallback)cx_deserXmlMemberWalk, &walkData)) {
        goto error;
    }

    return 0;
error:
    return -1;
}

/* Deserialize xml value */
int cx_deserXmlValue(cx_xmlnode node, cx_deserXmlScope scope, cx_type type, void* o, deser_xmldata data) {
    cx_type t;

    t = type;

    /* Deserialize primitive */
    if ((t->kind == CX_PRIMITIVE) || (t->reference && (scope != XML_OBJECT))) {
        cx_string content;
        if (cx_deserXmlPrimitive((content = cx_xmlnodeContent(node)), type, o, data)) {
            goto error;
        }

        cx_dealloc(content);

    /* Deserialize collection */
    } else if (t->kind == CX_COLLECTION) {
        if (cx_deserXmlCollection(node, type, o, 0, data)) {
            goto error;
        }
    }

    /* Deserialize complex type */
    else if ((t->kind == CX_COMPOSITE) || (t->reference && (scope == XML_OBJECT))) {
        if (cx_deserXmlComplex(node, type, o, data)) {
            goto error;
        }
    }

    return 0;
error:
    return -1;
}

/* Deserialize object */
int cx_deserXmlObject(cx_xmlnode node, cx_string name, cx_string type, deser_xmldata data) {
    cx_type t;
    cx_object o;

    /* Lookup type */
    t = cx_deserXmlNsResolve(NULL, type, data);
    if (!t) {
        xml_error(data, "unknown type '%s'.", type); goto error;
    } else if (!cx_instanceof(cx_type(cx_type_o), t)) {
        cx_id id;
        xml_error(data, "object '%s' is not a type", cx_fullname(t, id)); goto error;
    }

    /* Declare object */
    o = cx_deserXmlDeclare(data, name, t);
    cx_release(t); /* Free reference to t obtained by resolve */
    if (!o) {
        xml_error(data, "failed to create object '%s : %s'.", name, type); goto error;
    }
    /* Deserialize value */
    data->cur = o;
    if (cx_deserXmlValue(node, XML_OBJECT, t, o, data)) {
        cx_invalidate(o);
        goto error;
    }

    /* Construct(finalize) object */
    if (cx_define(o)) {
        xml_error(data, "failed to construct object '%s : %s'.", name, type); goto error;
    }

    return 0;
error:
    return -1;
}

/* Deserialize meta-directive */
int cx_deserXmlMeta(cx_xmlnode node, cx_deserXmlScope scope, deser_xmldata data) {
    return cx_deserXmlMetaExt(node, scope, 0, 0, data);
}

/* Deserialize meta-directive */
int cx_deserXmlMetaExt(cx_xmlnode node, cx_deserXmlScope scope, cx_type t, void* o, deser_xmldata data) {
    cx_string oper;
    cx_string type;
    cx_string name;
    cx_xmlnode object;

    oper = (cx_string)cx_xmlnodeName(node);

    /* meta:object */
    if (!strcmp(oper, "object")) {
        type = cx_xmlnodeAttrStr(node, "type");

        /* Get value node */
        object = cx_xmlnodeFind(node, "value");
        if (object) {
            /* Parse new object */
            if (scope == XML_OBJECT) {
                name = cx_xmlnodeAttrStr(node, "name");

                /* Deserialize object */
                if (cx_deserXmlObject(object, name, type, data)) {
                    goto error;
                }

                free(name);

            /* Serialize collection element */
            } else if (scope == XML_ELEMENT) {
                if (cx_deserXmlValue(object, scope, t, o, data)) {
                    goto error;
                }

            /* Serialize collection element using short verbose object notation */
            } else if (scope == XML_MEMBER) {
                deser_xmlMemberData_s memberData;
                cx_string type = cx_xmlnodeAttrStr(node, "type");

                memberData.t = t;
                memberData.o = o;
                memberData.data = data;
                if (cx_deserXmlInlinedMember(node, type, &memberData)) {
                    goto error;
                }
            }
        } else {
            if (scope == XML_OBJECT) {
                cx_type t;
                /* Forward declaration */
                name = cx_xmlnodeAttrStr(node, "name");
                t = cx_deserXmlNsResolve(NULL, type, data);
                if ((scope == XML_OBJECT) && !cx_deserXmlDeclare(data, name, t)) {
                    goto error;
                }
                free(name);
                cx_release(t);
            } else {
                xml_error(data, "missing value-element for meta:object element.");
                goto error;
            }
        }

        free(type);

    /* Serialize collection element */
    } else if (!strcmp(oper, "element")) {

        /* Deserialize value of element - no value-tag needed. */
        if (cx_deserXmlValue(node, scope, t, o, data)) {
            goto error;
        }

    /* meta:include */
    } else if (!strcmp(oper, "include")) {
        cx_string filename = cx_xmlnodeAttrStr(node, "file");
        if (filename) {
            cx_load(filename);
            free(filename);
        } else {
            xml_error(data, "missing 'file' attribute for meta:include.");
            goto error;
        }

    /* meta:scope */
    } else if (!strcmp(oper, "scope") || !strcmp(oper, "package")) {
        cx_object s;
        deser_xmldata_s privateData;

        /* Lookup scope if the scope of the element is an object */
        if (scope == XML_OBJECT) {
            cx_string name;

            /* Resolve name attribute */
            name = cx_xmlnodeAttrStr(node, "name");

            /* first try to resolve scope */
            s = cx_lookup(data->scope, name);
            if (!s) {
                if (!strcmp(oper, "package")) {
                    s = cx_declareChild(data->scope, name, (cx_type)cx_package_o);
                    cx_claim(s);
                    cx_package(s)->url = cx_xmlnodeAttrStr(node, "url");
                    cx_define(s);
                } else {
                    s = cx_declareChild(data->scope, name, (cx_type)cx_void_o);
                    cx_claim(s);
                }
            }

            free(name);
        }
        /* If the elementscope is a member, the current object will be the scope. */
        else if (scope == XML_MEMBER) {
            s = data->cur;
            cx_claim(s);
        } else {
            s = NULL;
            xml_error(data, "invalid use of meta:scope.");
            goto error;
        }

        name = cx_nameof(s);

        /* resolve objects in scope */
        privateData = *data;
        privateData.scope = s;
        privateData.attrParsed = NULL;

        /* Walk root */
        if (!cx_xmlnodeWalkChildren(node, (cx_xmlreaderWalkCallback)cx_deserXmlNode, &privateData)) {
            xml_error(data, "error(s) occured while deserializing scope '%s'.", name); goto error;
        }

        cx_deserXmlDataFree(&privateData);

    /* meta:super */
    } else if (!strcmp(oper, "super")) {
        /* Check if type supports inheritance */
        if (!cx_class_instanceof(cx_class_o, cx_typeof(t))) {
            cx_type extend;

            /* Check if type inherits */
            if ((extend = (cx_type)cx_interface(t)->base)) {
                deser_xmldata_s privateData;

                privateData = cx_deserXmlDataClone(data);
                if (cx_deserXmlValue(node, XML_OBJECT, extend, o, &privateData)) {
                    goto error;
                }
                cx_deserXmlDataFree(&privateData);
            } else {
                cx_id fullname;
                xml_error(data, "Invalid super-tag: type '%s' has no base type.", cx_fullname(t, fullname));
            }
        } else {
            cx_id fullname;
            xml_error(data, "Invalid super-tag: type-kind of '%s' does not support inheritance.", cx_fullname(t, fullname));
        }

    /* using */
    } else if (!strcmp(oper, "using")) {
        cx_string ns = cx_xmlnodeAttrStr(node, "namespace");
        cx_deserXmlNsUse(ns, data);
    } else {
        xml_warning(data, "unknown operation '%s'.", oper);
    }

    return 0;
error:
    return -1;
}

/* Deserialize node */
int cx_deserXmlNode(cx_xmlnode node, deser_xmldata data) {
    cx_string ns;
    cx_string name;
    deser_xmldata_s privateData;

    XML_NODE(node, data);

    privateData = cx_deserXmlDataClone(data);

    ns = (cx_string)cx_xmlnodeNs(node);
    if (ns) {
        /* Deserialize meta-directive */
        if (!strcmp(ns, "meta")) {
            if (cx_deserXmlMeta(node, XML_OBJECT, &privateData)) {
                goto error;
            }
        } else {
            xml_warning(data, "unknown namespace '%s'.", ns);
        }
    } else {
        /* Deserialize object */
        name = cx_xmlnodeAttrStr(node, "name");

        /* Mark attribute as consumed */
        cx_deserXmlMemberSet("name", &privateData);

        if (cx_deserXmlObject(node, name, (cx_string)cx_xmlnodeName(node), &privateData)) {
            goto error;
        }
        free(name);
    }

    cx_deserXmlDataFree(&privateData);

    return 1;
error:
    cx_deserXmlDataFree(&privateData);
    return 0;
}

/* Deserialize xml */
int cx_deserXml(cx_string file, void* udata) {
    deser_xmldata_s data;

    CX_UNUSED(udata);

    /* Load reader */
    data.reader = cx_xmlreaderNew(file, "meta");
    if (data.reader) {
        data.node = cx_xmlreaderRoot(data.reader);
        data.scope = root_o;
        data.file = file;
        data.line = 0;
        data.attrParsed = 0;
        data.using = cx_llNew();

        if (!cx_xmlnodeWalkChildren(data.node, (cx_xmlreaderWalkCallback)cx_deserXmlNode, &data)) {
            cx_error("error(s) occured while deserializing file '%s'.", file);
            goto error;
        }

        /* Free using */
        cx_llFree(data.using);

        /* Free attrParsed */
        if (data.attrParsed) {
            cx_llFree(data.attrParsed);
        };

        /* Free reader */
        cx_xmlreaderFree(data.reader);
    } else {
        goto error;
    }

    return 0;
error:
    return -1;
}

