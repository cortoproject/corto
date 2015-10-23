/*
 * corto_deserxml.c
 *
 *  Created on: Mar 19, 2012
 *      Author: sander
 */

#include "xml_deser.h"
#include "corto.h"
#include "corto_class.h"
#include "xmlreader.h"
#include "corto_loader.h"

#include "stdlib.h"
#include "string.h"

typedef struct deser_xmldata_s* deser_xmldata;
typedef struct deser_xmldata_s {
    corto_xmlnode reader;
    corto_xmlnode node;
    corto_object scope;
    corto_object cur;
    corto_string file;
    corto_uint32 line;
    corto_ll attrParsed;
    corto_ll using;
}deser_xmldata_s;

typedef enum corto_deserXmlScope {
    XML_OBJECT,
    XML_ELEMENT,
    XML_MEMBER
}corto_deserXmlScope;

#define xml_error(data, ...) fprintf(stderr, "%s: %d: ", data->file, data->line); corto_error(__VA_ARGS__);
#define xml_warning(data, ...) fprintf(stderr, "%s: %d: ", data->file, data->line); corto_warning(__VA_ARGS__);

#define XML_NODE(nodePtr, data) (data)->line = corto_xmlnodeLine(nodePtr); (data)->node = nodePtr;

int corto_deserXmlMeta(corto_xmlnode node, corto_deserXmlScope scope, deser_xmldata data);
int corto_deserXmlMetaExt(corto_xmlnode node, corto_deserXmlScope scope, corto_type t, void* o, deser_xmldata data);
int corto_deserXmlValue(corto_xmlnode node, corto_deserXmlScope scope, corto_type t, void* o, deser_xmldata data);
int corto_deserXmlNode(corto_xmlnode node, deser_xmldata data);

/* Set parsed attribute */
void corto_deserXmlMemberSet(corto_string name, deser_xmldata data) {
    if (!data->attrParsed) {
        data->attrParsed = corto_llNew();
    }
    corto_llInsert(data->attrParsed, name);
}

/* Check if attribute is parsed */
int corto_deserXmlMemberCheck(corto_string name, deser_xmldata data) {
    if (data->attrParsed) {
        corto_string result = (corto_string)corto_llFind(data->attrParsed, (corto_walkAction)strcmp, name);
        return result != 0;
    } else {
        return 0;
    }
}

/* Set parsed attribute */
void corto_deserXmlNsUse(corto_string ns, deser_xmldata data) {
    corto_object o;
    if (!data->using) {
        data->using = corto_llNew();
    }

    o = corto_lookup(data->scope, ns);
    if (!o) {
        xml_error(data, "namespace '%s' unresolved.", ns);
    } else {
        corto_llAppend(data->using, o);
        corto_release(o);
    }
}

/* Resolve object, and if object is not found, look it up in 'using' namespaces */
corto_object corto_deserXmlNsResolve(corto_object src, corto_string name, deser_xmldata data) {
    corto_object o, ns;

    CORTO_UNUSED(src);

    o = corto_resolve(data->scope, name);
    if (!o) {
        if (data->using) {
            corto_iter iter;

            iter = corto_llIter(data->using);
            while(!o && corto_iterHasNext(&iter)) {
                ns = corto_iterNext(&iter);
                o = corto_lookup(ns, name);
            }
        }
    }
    return o;
}

/* Clone deserdata */
deser_xmldata_s corto_deserXmlDataClone(deser_xmldata data) {
    deser_xmldata_s result;

    result = *data;
    result.attrParsed = 0;
    if (data->scope) {
        corto_claim(data->scope);
    }
    return result;
}

/* Free deserdata */
void corto_deserXmlDataFree(deser_xmldata data) {
    if (data->attrParsed) {
        corto_llFree(data->attrParsed);
        data->attrParsed = (void*)-1; /* Will crash if attempts are made to dereference it */
    }
    if (data->scope) {
        corto_release(data->scope);
    }
}

/* (Forward) declare object */
corto_object corto_deserXmlDeclare(deser_xmldata data, corto_string name, corto_type t) {
    corto_object o;

    /* Find or create object */
    if (!(o = corto_lookup(data->scope, name))) {
        o = corto_declareChild(data->scope, name, t);
    } else {
        corto_release(o);
    }

    return o;
}

/* Deserialize reference */
int corto_deserXmlReference(const char* str, corto_type t, void* o, deser_xmldata data) {
    if (!strcmp(str, "<null>")) {
        *(corto_void**)o = 0;
    } else {
        corto_object ref;
        corto_id fullname_1;
        corto_id fullname_2;
        corto_id fullname_3;

        ref = corto_resolve(data->scope, (corto_string)str);
        if (ref) {
            /* Check if resolved object has the right type */
            if ((corto_typeof(ref) == t) || (corto_class_instanceof(corto_class_o, t) && corto_class_instanceof(corto_class(t), ref)) || (t->kind == CORTO_VOID)) {
                *(corto_void**)o = ref;
            } else {
                xml_error(data, "reference to object '%s' of type '%s' does not match reference type '%s'.",
                        corto_fullname(ref, fullname_1),
                        corto_fullname(corto_typeof(ref), fullname_2),
                        corto_fullname(t, fullname_3)); goto error;
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
int corto_deserXmlPrimitive(const char* str, corto_type t, void* o, deser_xmldata data) {
    corto_void* toValue;
    corto_type type;

    if (!str) {
        corto_id fullname;
        xml_error(data, "invalid value for primitive of type '%s'.", corto_fullname(t, fullname));
        goto error;
    }
    type = t;

    /* Parse reference string, take into account scoping */
    if (strlen(str)) {
        if (type->reference) {
            if (corto_deserXmlReference(str, (corto_type)type, o, data)) {
                goto error;
            }
        } else {
            /* Transform string to value using database transformations */
            if (corto_convert(corto_primitive(corto_string_o), (char**)&str, corto_primitive(t), &toValue)) {
                corto_id fullname;
                xml_error(data, "transformation from string to primitive type '%s' failed.", corto_fullname(t, fullname));
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
int corto_deserXmlCollectionNew(corto_type t, void* o) {
    corto_collection ctype;

    ctype = (corto_collection)t;

    switch(ctype->kind) {
    case CORTO_ARRAY:
        break;
    case CORTO_SEQUENCE:
        ((corto_objectseq*)o)->length = 0;
        ((corto_objectseq*)o)->buffer = 0;
        break;
    case CORTO_LIST:
        *((corto_ll*)o) = corto_llNew();
        break;
    case CORTO_MAP:
        *((corto_rbtree*)o) = corto_rbtreeNew(((corto_map)ctype)->keyType);
        break;
    default:
        corto_error("parser error: not a valid collection kind for 'corto_deserXmlCollectionNew'.");
        goto error;
    }

    return 0;
error:
    return -1;
}

typedef struct deser_xmlElementData {
    void* collection;
    corto_type t;
    deser_xmldata data;
    corto_uint32 count;
    corto_bool othersAllowed;
}deser_xmlElementData;

/* Create new element */
void* corto_deserXmlCollectionNewElement(deser_xmlElementData* data) {
    corto_collection ctype;
    corto_objectseq* seq;
    corto_uint32 elementSize;
    void* result;

    ctype = (corto_collection)data->t;
    elementSize = corto_type_sizeof(ctype->elementType);
    result = 0;

    corto_assert(elementSize, "collection has elementType of size 0.");

    switch(ctype->kind) {
    case CORTO_ARRAY:
        result = data->collection;
        data->collection = CORTO_OFFSET(data->collection, elementSize);
        break;
    case CORTO_SEQUENCE:
        seq = (corto_objectseq*)data->collection;
        seq->buffer = corto_realloc(seq->buffer, (seq->length+1) * elementSize);
        result = CORTO_OFFSET(seq->buffer, elementSize * seq->length);
        seq->length++;
        break;
    case CORTO_LIST:
    case CORTO_MAP:
        result = corto_alloc(elementSize);
        break;
    default:
        {
            corto_id fullname;
            xml_error(data->data, "cannot create element for type '%s' that is not a collection.", corto_fullname(data->t, fullname));
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
int corto_deserXmlCollectionInsertElement(corto_xmlnode node, void* o, deser_xmlElementData* data) {
    corto_collection ctype;

    ctype = (corto_collection)data->t;

    switch(ctype->kind) {
    case CORTO_ARRAY:
    case CORTO_SEQUENCE:
        /* Do nothing */
        break;
    case CORTO_LIST:
        /* Insert element in list */
        corto_llAppend(*(corto_ll*)data->collection, o);
        break;
    case CORTO_MAP:
        {
            corto_string key;
            corto_void* toValue;

            /* Retrieve key */
            key = corto_xmlnodeAttrStr(node, "key");

            /* Cast string to key value */
            if (corto_convert(corto_primitive(corto_string_o), &key, corto_primitive(corto_rbtreeKeyType(*(corto_rbtree*)data->collection)), &toValue)) {
                corto_id fullname;
                xml_error(data->data, "transformation from string to primitive map keytype '%s' failed.",
                        corto_fullname(corto_rbtreeKeyType(*(corto_rbtree*)data->collection), fullname));
                goto error;
            }

            /* Insert element in map */
            corto_rbtreeSet(*(corto_rbtree*)data->collection, toValue, o);
            break;
        }
    default:
        xml_error(data->data, "parser error: not a collectiontype in corto_deserXmlCollectionInsertElement.");
        goto error;
    }

    return 0;
error:
    return -1;
}

/* Deserialize elements */
int corto_deserXmlElement(corto_xmlnode node, deser_xmlElementData* userData) {
    corto_collection ctype;
    corto_type subtype;
    void* o;

    XML_NODE(node, userData->data);

    ctype = (corto_collection)userData->t;
    subtype = ((corto_collection)ctype)->elementType;

    /* Check if element belongs to collection */
    if (corto_xmlnodeNs(node) && !strcmp(corto_xmlnodeNs(node), "meta")) {
        if (!strcmp(corto_xmlnodeName(node), "object") || !strcmp(corto_xmlnodeName(node), "element")) {
            /* Acquire pointer to new element */
            o = corto_deserXmlCollectionNewElement(userData);
            if (!o) {
                xml_error(userData->data, "parser erorr: failed to create collection element.");
                goto error;
            }
            /* Deserialize collection */
            if (corto_deserXmlMetaExt(node, XML_ELEMENT, subtype, o, userData->data)) {
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
    } else if (corto_checkAttr(subtype, CORTO_ATTR_SCOPED) && !strcmp(corto_nameof(subtype), corto_xmlnodeName(node))) {
        deser_xmldata_s privateData;

        privateData = corto_deserXmlDataClone(userData->data);

        /* Acquire pointer to new element */
        o = corto_deserXmlCollectionNewElement(userData);
        if (!o) {
            xml_error(userData->data, "couldn't obtain pointer to element.")
            goto error;
        }

        /* If collection is a map, mark the 'key' attribute as processed so it won't be read as member */
        if (corto_collection(userData->t)->kind == CORTO_MAP) {
            corto_deserXmlMemberSet("key", &privateData);
        }
        if (corto_deserXmlValue(node, XML_ELEMENT, subtype, o, &privateData)) {
            xml_error(userData->data, "failed to deserialize value of element.");
            goto error;
        }
        corto_deserXmlDataFree(&privateData);

    /* Node that does not belong to this collection */
    } else {
        if (userData->othersAllowed) {
            /* node is a member or element of other collection type */
            goto ok;
        } else {
            xml_error(userData->data, "unexpected element tag '%s' in collection.", corto_xmlnodeName(node));
            goto error;
        }
    }

    /* Insert element */
    if (corto_deserXmlCollectionInsertElement(node, o, userData)) {
        goto error;
    }

ok:
    return 1;
error:
    xml_error(userData->data, "failed to deserialize element.");
    return 0;
}

/* Deserialize collection - using regular notation */
int corto_deserXmlCollection(corto_xmlnode node, corto_type t, void* o, corto_bool othersAllowed, deser_xmldata data) {
    deser_xmlElementData walkData;
    deser_xmldata_s privateData;

    privateData = corto_deserXmlDataClone(data);

    /* Create collection */
    if (corto_deserXmlCollectionNew(t, o)) {
        goto error;
    }

    /* Walk elements */
    walkData.collection = o;
    walkData.t = t;
    walkData.data = &privateData;
    walkData.count = 0;
    walkData.othersAllowed = othersAllowed; /* Don't allow members or elements from other collections within scope */
    if (!corto_xmlnodeWalkChildren(node, (corto_xmlreaderWalkCallback)corto_deserXmlElement, &walkData)) {
        xml_error(data, "An error occured while deserializing elements of collection '%s'.", corto_xmlnodeName(node));
        goto error;
    }

    corto_deserXmlDataFree(&privateData);
    return 0;
error:
    corto_deserXmlDataFree(&privateData);
    return -1;
}

typedef struct deser_xmlMemberData_s* deser_xmlMemberData;
typedef struct deser_xmlMemberData_s {
    corto_type t;
    void* o;
    deser_xmldata data;
}deser_xmlMemberData_s;

/* Deserialize attribute */
static int corto_deserXmlAttrWalk(corto_string ns, corto_string attr, corto_string content, deser_xmlMemberData userData) {
    corto_member member;
    corto_type t;
    CORTO_UNUSED(ns);

    /* Check if attribute has not been consumed yet */
    if (corto_deserXmlMemberCheck(attr, userData->data)) {
        goto ok;
    }

    /* Lookup member */
    member = corto_interface_resolveMember(corto_interface(userData->t), attr);
    if (member) {
        t = member->type;
        /* Check if member is of a primitive type */
        if ((t->kind == CORTO_PRIMITIVE) || t->reference) {
            if (corto_deserXmlPrimitive(content, member->type, CORTO_OFFSET(userData->o, member->offset), userData->data)) {
                goto error;
            }
        } else {
            xml_error(userData->data, "non-primitive member '%s' cannot be specified as attribute.", attr);
            goto error;
        }
    } else {
        corto_id fullname;
        xml_error(userData->data, "type '%s' has no member '%s'.", corto_fullname(userData->t, fullname), attr);
        goto error;
    }

    /* Mark attribute as consumed */
    corto_deserXmlMemberSet(attr, userData->data );

ok:
    return 1;
error:
    return 0;
}

/* Check if node is element of inlined collection */
corto_string corto_deserXmlIsInlinedElement(corto_string type, deser_xmlMemberData userData) {
    corto_interface s;
    corto_type subtype;
    corto_uint32 i;
    corto_string result;
    corto_member m;


    s = corto_interface(userData->t);
    result = 0;

    /* Look for collections that can be used inlined */
    for(i=0; i<s->members.length; i++) {
        m = s->members.buffer[i];
        if (m->type->kind == CORTO_COLLECTION) {
            subtype = ((corto_collection)m->type)->elementType;
            if (corto_checkAttr(subtype, CORTO_ATTR_SCOPED) && !strcmp(corto_nameof(subtype), type)) {
                result = corto_nameof(s->members.buffer[i]);
                break;

            /* Compare fully qualified names */
            } else {
                corto_id subtypeName;
                corto_id typeName;
                corto_object o;

                o = corto_lookup(userData->data->scope, type);
                if (o) {
                    if (!strcmp(corto_fullname(subtype, subtypeName), corto_fullname(o, typeName))) {
                        result = corto_nameof(s->members.buffer[i]);
                        break;
                    }
                    corto_release(o);
                }
            }
        }
    }

    return result;
}

/* Deserialize inlined member */
int corto_deserXmlInlinedMember(corto_xmlnode node, corto_string name, deser_xmlMemberData userData) {
    corto_member member;
    corto_string memberName;

    memberName = 0;

    /* Check if this node is actually an element of an inlined collection */
    if ((memberName = corto_deserXmlIsInlinedElement((corto_string)name, userData))) {
        if (!corto_deserXmlMemberCheck(memberName, userData->data)) {

            /* Lookup member */
            member = corto_resolve(userData->t, memberName);
            if (member) {

                /* Deserialize collection */
                if (corto_deserXmlCollection(corto_xmlnodeParent(node), member->type, CORTO_OFFSET(userData->o, member->offset), 1, userData->data)) {
                    corto_release(member);
                    goto error;
                }
                corto_release(member);
            }
        }

        /* Set member as processed - so collection won't be parsed again. */
        corto_deserXmlMemberSet(memberName, userData->data);
    } else {
        corto_id fullname;
        xml_error(userData->data, "type '%s' has no member named- or inlined collection with subtype '%s'.", corto_fullname(userData->t, fullname), name);
        goto error;
    }

    return 0;
error:
    return -1;
}

/* Deserialize membernodes */
static int corto_deserXmlMemberWalk(corto_xmlnode node, deser_xmlMemberData userData) {
    corto_member member;

    XML_NODE(node, userData->data);

    if (corto_xmlnodeNs(node) && !strcmp(corto_xmlnodeNs(node), "meta")) {
        if (corto_deserXmlMetaExt(node, XML_MEMBER, userData->t, userData->o, userData->data)) {
            goto error;
        }
    } else {

        /* Lookup member */
        member = corto_interface_resolveMember(corto_interface(userData->t), (corto_string)corto_xmlnodeName(node));
        if (member) {
            deser_xmldata_s privateData = *userData->data;

            privateData.attrParsed = 0;
            if (corto_deserXmlValue(node, XML_MEMBER, member->type, CORTO_OFFSET(userData->o, member->offset), &privateData)) {
                goto error;
            }
            if (privateData.attrParsed) {
                corto_llFree(privateData.attrParsed);
            }
        } else {
            if (corto_deserXmlInlinedMember(node, (corto_string)corto_xmlnodeName(node), userData)) {
                goto error;
            }
        }
    }

    return 1;
error:
    return 0;
}

/* Deserialize complex type */
int corto_deserXmlComplex(corto_xmlnode node, corto_type t, void* o, deser_xmldata data) {
    deser_xmlMemberData_s walkData;

    walkData.o = o;
    walkData.t = t;
    walkData.data = data;

    /* Deserialize attributes */
    if (!corto_xmlnodeWalkAttr(node, (corto_xmlreaderWalkAttrCallback)corto_deserXmlAttrWalk, &walkData)) {
        goto error;
    }

    /* Deserialize childnodes */
    if (!corto_xmlnodeWalkChildren(node, (corto_xmlreaderWalkCallback)corto_deserXmlMemberWalk, &walkData)) {
        goto error;
    }

    return 0;
error:
    return -1;
}

/* Deserialize xml value */
int corto_deserXmlValue(corto_xmlnode node, corto_deserXmlScope scope, corto_type type, void* o, deser_xmldata data) {
    corto_type t;

    t = type;

    /* Deserialize primitive */
    if ((t->kind == CORTO_PRIMITIVE) || (t->reference && (scope != XML_OBJECT))) {
        corto_string content;
        if (corto_deserXmlPrimitive((content = corto_xmlnodeContent(node)), type, o, data)) {
            goto error;
        }

        corto_dealloc(content);

    /* Deserialize collection */
    } else if (t->kind == CORTO_COLLECTION) {
        if (corto_deserXmlCollection(node, type, o, 0, data)) {
            goto error;
        }
    }

    /* Deserialize complex type */
    else if ((t->kind == CORTO_COMPOSITE) || (t->reference && (scope == XML_OBJECT))) {
        if (corto_deserXmlComplex(node, type, o, data)) {
            goto error;
        }
    }

    return 0;
error:
    return -1;
}

/* Deserialize object */
int corto_deserXmlObject(corto_xmlnode node, corto_string name, corto_string type, deser_xmldata data) {
    corto_type t;
    corto_object o;

    /* Lookup type */
    t = corto_deserXmlNsResolve(NULL, type, data);
    if (!t) {
        xml_error(data, "unknown type '%s'.", type); goto error;
    } else if (!corto_instanceof(corto_type(corto_type_o), t)) {
        corto_id id;
        xml_error(data, "object '%s' is not a type", corto_fullname(t, id)); goto error;
    }

    /* Declare object */
    o = corto_deserXmlDeclare(data, name, t);
    corto_release(t); /* Free reference to t obtained by resolve */
    if (!o) {
        xml_error(data, "failed to create '%s : %s' (%s)", name, type, corto_lasterr()); goto error;
    }
    /* Deserialize value */
    data->cur = o;
    if (corto_deserXmlValue(node, XML_OBJECT, t, o, data)) {
        corto_invalidate(o);
        goto error;
    }

    /* Construct(finalize) object */
    if (corto_define(o)) {
        xml_error(data, "failed to construct object '%s : %s'.", name, type); goto error;
    }

    return 0;
error:
    return -1;
}

/* Deserialize meta-directive */
int corto_deserXmlMeta(corto_xmlnode node, corto_deserXmlScope scope, deser_xmldata data) {
    return corto_deserXmlMetaExt(node, scope, 0, 0, data);
}

/* Deserialize meta-directive */
int corto_deserXmlMetaExt(corto_xmlnode node, corto_deserXmlScope scope, corto_type t, void* o, deser_xmldata data) {
    corto_string oper;
    corto_string type;
    corto_string name;
    corto_xmlnode object;

    oper = (corto_string)corto_xmlnodeName(node);

    /* meta:object */
    if (!strcmp(oper, "object")) {
        type = corto_xmlnodeAttrStr(node, "type");

        /* Get value node */
        object = corto_xmlnodeFind(node, "value");
        if (object) {
            /* Parse new object */
            if (scope == XML_OBJECT) {
                name = corto_xmlnodeAttrStr(node, "name");

                /* Deserialize object */
                if (corto_deserXmlObject(object, name, type, data)) {
                    goto error;
                }

                free(name);

            /* Serialize collection element */
            } else if (scope == XML_ELEMENT) {
                if (corto_deserXmlValue(object, scope, t, o, data)) {
                    goto error;
                }

            /* Serialize collection element using short verbose object notation */
            } else if (scope == XML_MEMBER) {
                deser_xmlMemberData_s memberData;
                corto_string type = corto_xmlnodeAttrStr(node, "type");

                memberData.t = t;
                memberData.o = o;
                memberData.data = data;
                if (corto_deserXmlInlinedMember(node, type, &memberData)) {
                    goto error;
                }
            }
        } else {
            if (scope == XML_OBJECT) {
                corto_type t;
                /* Forward declaration */
                name = corto_xmlnodeAttrStr(node, "name");
                t = corto_deserXmlNsResolve(NULL, type, data);
                if ((scope == XML_OBJECT) && !corto_deserXmlDeclare(data, name, t)) {
                    goto error;
                }
                free(name);
                corto_release(t);
            } else {
                xml_error(data, "missing value-element for meta:object element.");
                goto error;
            }
        }

        free(type);

    /* Serialize collection element */
    } else if (!strcmp(oper, "element")) {

        /* Deserialize value of element - no value-tag needed. */
        if (corto_deserXmlValue(node, scope, t, o, data)) {
            goto error;
        }

    /* meta:include */
    } else if (!strcmp(oper, "include")) {
        corto_string filename = corto_xmlnodeAttrStr(node, "file");
        if (filename) {
            corto_load(filename, 0, NULL);
            free(filename);
        } else {
            xml_error(data, "missing 'file' attribute for meta:include.");
            goto error;
        }

    /* meta:scope */
    } else if (!strcmp(oper, "scope") || !strcmp(oper, "package")) {
        corto_object s;
        deser_xmldata_s privateData;

        /* Lookup scope if the scope of the element is an object */
        if (scope == XML_OBJECT) {
            corto_string name;

            /* Resolve name attribute */
            name = corto_xmlnodeAttrStr(node, "name");

            /* first try to resolve scope */
            s = corto_lookup(data->scope, name);
            if (!s) {
                if (!strcmp(oper, "package")) {
                    s = corto_declareChild(data->scope, name, corto_package_o);
                    corto_claim(s);
                    corto_package(s)->url = corto_xmlnodeAttrStr(node, "url");
                    corto_define(s);
                } else {
                    s = corto_declareChild(data->scope, name, corto_void_o);
                    corto_claim(s);
                }
            }

            free(name);
        }
        /* If the elementscope is a member, the current object will be the scope. */
        else if (scope == XML_MEMBER) {
            s = data->cur;
            corto_claim(s);
        } else {
            s = NULL;
            xml_error(data, "invalid use of meta:scope.");
            goto error;
        }

        name = corto_nameof(s);

        /* resolve objects in scope */
        privateData = *data;
        privateData.scope = s;
        privateData.attrParsed = NULL;

        /* Walk root */
        if (!corto_xmlnodeWalkChildren(node, (corto_xmlreaderWalkCallback)corto_deserXmlNode, &privateData)) {
            xml_error(data, "error(s) occured while deserializing scope '%s'.", name); goto error;
        }

        corto_deserXmlDataFree(&privateData);

    /* meta:super */
    } else if (!strcmp(oper, "super")) {
        /* Check if type supports inheritance */
        if (!corto_class_instanceof(corto_class_o, corto_typeof(t))) {
            corto_type extend;

            /* Check if type inherits */
            if ((extend = (corto_type)corto_interface(t)->base)) {
                deser_xmldata_s privateData;

                privateData = corto_deserXmlDataClone(data);
                if (corto_deserXmlValue(node, XML_OBJECT, extend, o, &privateData)) {
                    goto error;
                }
                corto_deserXmlDataFree(&privateData);
            } else {
                corto_id fullname;
                xml_error(data, "Invalid super-tag: type '%s' has no base type.", corto_fullname(t, fullname));
            }
        } else {
            corto_id fullname;
            xml_error(data, "Invalid super-tag: type-kind of '%s' does not support inheritance.", corto_fullname(t, fullname));
        }

    /* using */
    } else if (!strcmp(oper, "using")) {
        corto_string ns = corto_xmlnodeAttrStr(node, "namespace");
        corto_deserXmlNsUse(ns, data);
    } else {
        xml_warning(data, "unknown operation '%s'.", oper);
    }

    return 0;
error:
    return -1;
}

/* Deserialize node */
int corto_deserXmlNode(corto_xmlnode node, deser_xmldata data) {
    corto_string ns;
    corto_string name;
    deser_xmldata_s privateData;

    XML_NODE(node, data);

    privateData = corto_deserXmlDataClone(data);

    ns = (corto_string)corto_xmlnodeNs(node);
    if (ns) {
        /* Deserialize meta-directive */
        if (!strcmp(ns, "meta")) {
            if (corto_deserXmlMeta(node, XML_OBJECT, &privateData)) {
                goto error;
            }
        } else {
            xml_warning(data, "unknown namespace '%s'.", ns);
        }
    } else {
        /* Deserialize object */
        name = corto_xmlnodeAttrStr(node, "name");

        /* Mark attribute as consumed */
        corto_deserXmlMemberSet("name", &privateData);

        if (corto_deserXmlObject(node, name, (corto_string)corto_xmlnodeName(node), &privateData)) {
            goto error;
        }
        free(name);
    }

    corto_deserXmlDataFree(&privateData);

    return 1;
error:
    corto_deserXmlDataFree(&privateData);
    return 0;
}

/* Deserialize xml */
int corto_deserXml(corto_string file, int argc, char* argv[], void* udata) {
    deser_xmldata_s data;

    CORTO_UNUSED(udata);
    CORTO_UNUSED(argc);
    CORTO_UNUSED(argv);

    /* Load reader */
    data.reader = corto_xmlreaderNew(file, "meta");
    if (data.reader) {
        data.node = corto_xmlreaderRoot(data.reader);
        data.scope = root_o;
        data.file = file;
        data.line = 0;
        data.attrParsed = 0;
        data.using = corto_llNew();

        if (!corto_xmlnodeWalkChildren(data.node, (corto_xmlreaderWalkCallback)corto_deserXmlNode, &data)) {
            corto_error("error(s) occured while deserializing file '%s'.", file);
            goto error;
        }

        /* Free using */
        corto_llFree(data.using);

        /* Free attrParsed */
        if (data.attrParsed) {
            corto_llFree(data.attrParsed);
        };

        /* Free reader */
        corto_xmlreaderFree(data.reader);
    } else {
        goto error;
    }

    return 0;
error:
    return -1;
}

