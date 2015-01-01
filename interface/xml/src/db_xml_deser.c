/*
 * db_deserxml.c
 *
 *  Created on: Mar 19, 2012
 *      Author: sander
 */

#include "db_xml_deser.h"
#include "cortex.h"
#include "db_class.h"
#include "db_xmlreader.h"
#include "db_loader.h"

#include "stdlib.h"
#include "string.h"

typedef struct deser_xmldata_s* deser_xmldata;
typedef struct deser_xmldata_s {
	db_xmlnode reader;
	db_xmlnode node;
	db_object scope;
	db_object cur;
	db_string file;
	db_uint32 line;
	db_ll attrParsed;
	db_ll using;
}deser_xmldata_s;

typedef enum db_deserXmlScope {
	XML_OBJECT,
	XML_ELEMENT,
	XML_MEMBER
}db_deserXmlScope;

#define xml_error(data, ...) printf("%s: %d: ", data->file, data->line); db_error(__VA_ARGS__);
#define xml_warning(data, ...) printf("%s: %d: ", data->file, data->line); db_warning(__VA_ARGS__);

#define XML_NODE(nodePtr, data) (data)->line = db_xmlnodeLine(nodePtr); (data)->node = nodePtr;

int db_deserXmlMeta(db_xmlnode node, db_deserXmlScope scope, deser_xmldata data);
int db_deserXmlMetaExt(db_xmlnode node, db_deserXmlScope scope, db_typedef t, void* o, deser_xmldata data);
int db_deserXmlValue(db_xmlnode node, db_deserXmlScope scope, db_typedef t, void* o, deser_xmldata data);
int db_deserXmlNode(db_xmlnode node, deser_xmldata data);

/* Set parsed attribute */
void db_deserXmlMemberSet(db_string name, deser_xmldata data) {
	if (!data->attrParsed) {
		data->attrParsed = db_llNew();
	}
	db_llInsert(data->attrParsed, name);
}

/* Check if attribute is parsed */
int db_deserXmlMemberCheck(db_string name, deser_xmldata data) {
	if (data->attrParsed) {
		db_string result = (db_string)db_llFind(data->attrParsed, (db_walkAction)strcmp, name);
		return result != 0;
	} else {
		return 0;
	}
}

/* Set parsed attribute */
void db_deserXmlNsUse(db_string ns, deser_xmldata data) {
	db_object o;
	if (!data->using) {
		data->using = db_llNew();
	}

	o = db_lookup(data->scope, ns);
	if (!o) {
		xml_error(data, "namespace '%s' unresolved.", ns);
	} else {
		db_llAppend(data->using, o);
		db_free(o);
	}
}

/* Resolve object, and if object is not found, look it up in 'using' namespaces */
db_object db_deserXmlNsResolve(db_object src, db_string name, deser_xmldata data) {
	db_object o, ns;

	DB_UNUSED(src);

	o = db_resolve(data->scope, name);
	if (!o) {
		if (data->using) {
			db_iter iter;

			iter = db_llIter(data->using);
			while(!o && db_iterHasNext(&iter)) {
				ns = db_iterNext(&iter);
				o = db_lookup(ns, name);
			}
		}
	}
	return o;
}

/* Clone deserdata */
deser_xmldata_s db_deserXmlDataClone(deser_xmldata data) {
	deser_xmldata_s result;

	result = *data;
	result.attrParsed = 0;
	if (data->scope) {
	    db_keep(data->scope);
	}
	return result;
}

/* Free deserdata */
void db_deserXmlDataFree(deser_xmldata data) {
	if (data->attrParsed) {
		db_llFree(data->attrParsed);
		data->attrParsed = (void*)-1; /* Will crash if attempts are made to dereference it */
	}
	if (data->scope) {
	    db_free(data->scope);
	}
}

/* (Forward) declare object */
db_object db_deserXmlDeclare(deser_xmldata data, db_string name, db_typedef t) {
	db_object o;

	/* Find or create object */
	if (!(o = db_lookup(data->scope, name))) {
		o = db_declare(data->scope, name, t);
	} else {
		db_free(o);
	}

	return o;
}

/* Deserialize reference */
int db_deserXmlReference(const char* str, db_typedef t, void* o, deser_xmldata data) {
	if (!strcmp(str, "<null>")) {
		*(db_void**)o = 0;
	} else {
		db_object ref;
		db_id fullname_1;
		db_id fullname_2;
		db_id fullname_3;

		ref = db_resolve(data->scope, (db_string)str);
		if (ref) {
			/* Check if resolved object has the right type */
			if ((db_typeof(ref)->real == t->real) || (db_class_instanceof(db_class_o, t) && db_class_instanceof(db_class(t), ref)) || (t->real->kind == DB_VOID)) {
				*(db_void**)o = ref;
			} else {
				xml_error(data, "reference to object '%s' of type '%s' does not match reference type '%s'.",
						db_fullname(ref, fullname_1),
						db_fullname(db_typeof(ref), fullname_2),
						db_fullname(t, fullname_3)); goto error;
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
int db_deserXmlPrimitive(const char* str, db_typedef t, void* o, deser_xmldata data) {
	db_void* toValue;
	db_type type;

	if (!str) {
		db_id fullname;
		xml_error(data, "invalid value for primitive of type '%s'.", db_fullname(t, fullname));
		goto error;
	}
	type = t->real;

	/* Parse reference string, take into account scoping */
	if (strlen(str)) {
        if (type->reference) {
            if (db_deserXmlReference(str, (db_typedef)type, o, data)) {
                goto error;
            }
        } else {
            /* Transform string to value using database transformations */
            if (db_convert(db_primitive(db_string_o), (char**)&str, db_primitive(t->real), &toValue)) {
                db_id fullname;
                xml_error(data, "transformation from string to primitive type '%s' failed.", db_fullname(t, fullname));
                goto error;
            } else {
                /* Copy new value */
                memcpy(o, &toValue, t->real->size);
            }
        }
	}

	return 0;
error:
	return -1;
}

/* Create new collection */
int db_deserXmlCollectionNew(db_typedef t, void* o) {
	db_collection ctype;

	ctype = (db_collection)t->real;

	switch(ctype->kind) {
	case DB_ARRAY:
		break;
	case DB_SEQUENCE:
		((db_objectSeq*)o)->length = 0;
		((db_objectSeq*)o)->buffer = 0;
		break;
	case DB_LIST:
		*((db_ll*)o) = db_llNew();
		break;
	case DB_MAP:
		*((db_rbtree*)o) = db_rbtreeNew(((db_map)ctype)->keyType->real);
		break;
	default:
		db_error("parser error: not a valid collection kind for 'db_deserXmlCollectionNew'.");
		goto error;
	}

	return 0;
error:
	return -1;
}

typedef struct deser_xmlElementData {
	void* collection;
	db_typedef t;
	deser_xmldata data;
	db_uint32 count;
	db_bool othersAllowed;
}deser_xmlElementData;

/* Create new element */
void* db_deserXmlCollectionNewElement(deser_xmlElementData* data) {
	db_collection ctype;
	db_objectSeq* seq;
	db_uint32 elementSize;
	void* result;

	ctype = (db_collection)data->t->real;
	elementSize = db_type_sizeof(ctype->elementType->real);
	result = 0;

	db_assert(elementSize, "collection has elementType of size 0.");

	switch(ctype->kind) {
	case DB_ARRAY:
		result = data->collection;
		data->collection = DB_OFFSET(data->collection, elementSize);
		break;
	case DB_SEQUENCE:
		seq = (db_objectSeq*)data->collection;
		seq->buffer = db_realloc(seq->buffer, (seq->length+1) * elementSize);
		result = DB_OFFSET(seq->buffer, elementSize * seq->length);
		seq->length++;
		break;
	case DB_LIST:
	case DB_MAP:
		result = db_malloc(elementSize);
		break;
	default:
		{
			db_id fullname;
			xml_error(data->data, "cannot create element for type '%s' that is not a collection.", db_fullname(data->t, fullname));
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
int db_deserXmlCollectionInsertElement(db_xmlnode node, void* o, deser_xmlElementData* data) {
	db_collection ctype;

	ctype = (db_collection)data->t->real;

	switch(ctype->kind) {
	case DB_ARRAY:
	case DB_SEQUENCE:
		/* Do nothing */
		break;
	case DB_LIST:
		/* Insert element in list */
		db_llAppend(*(db_ll*)data->collection, o);
		break;
	case DB_MAP:
		{
			db_string key;
			db_void* toValue;

			/* Retrieve key */
			key = db_xmlnodeAttrStr(node, "key");

			/* Cast string to key value */
			if (db_convert(db_primitive(db_string_o), &key, db_primitive(db_rbtreeKeyType(*(db_rbtree*)data->collection)->real), &toValue)) {
				db_id fullname;
				xml_error(data->data, "transformation from string to primitive map keytype '%s' failed.",
						db_fullname(db_rbtreeKeyType(*(db_rbtree*)data->collection), fullname));
				goto error;
			}

			/* Insert element in map */
			db_rbtreeSet(*(db_rbtree*)data->collection, toValue, o);
			break;
		}
	default:
		xml_error(data->data, "parser error: not a collectiontype in db_deserXmlCollectionInsertElement.");
		goto error;
	}

	return 0;
error:
	return -1;
}

/* Deserialize elements */
int db_deserXmlElement(db_xmlnode node, deser_xmlElementData* userData) {
	db_collection ctype;
	db_typedef subtype;
	void* o;

	XML_NODE(node, userData->data);

	ctype = (db_collection)userData->t->real;
	subtype = ((db_collection)ctype)->elementType;

	/* Check if element belongs to collection */
	if (db_xmlnodeNs(node) && !strcmp(db_xmlnodeNs(node), "meta")) {
		if (!strcmp(db_xmlnodeName(node), "object") || !strcmp(db_xmlnodeName(node), "element")) {
			/* Acquire pointer to new element */
			o = db_deserXmlCollectionNewElement(userData);
			if (!o) {
				xml_error(userData->data, "parser erorr: failed to create collection element.");
				goto error;
			}
			/* Deserialize collection */
			if (db_deserXmlMetaExt(node, XML_ELEMENT, subtype, o, userData->data)) {
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
	} else if (db_checkAttr(subtype, DB_ATTR_SCOPED) && !strcmp(db_nameof(subtype), db_xmlnodeName(node))) {
		deser_xmldata_s privateData;

		privateData = db_deserXmlDataClone(userData->data);

		/* Acquire pointer to new element */
		o = db_deserXmlCollectionNewElement(userData);
		if (!o) {
		    xml_error(userData->data, "couldn't obtain pointer to element.")
			goto error;
		}

		/* If collection is a map, mark the 'key' attribute as processed so it won't be read as member */
		if (db_collection(userData->t->real)->kind == DB_MAP) {
		    db_deserXmlMemberSet("key", &privateData);
		}
		if (db_deserXmlValue(node, XML_ELEMENT, subtype, o, &privateData)) {
		    xml_error(userData->data, "failed to deserialize value of element.");
			goto error;
		}
		db_deserXmlDataFree(&privateData);

	/* Node that does not belong to this collection */
	} else {
		if (userData->othersAllowed) {
			/* node is a member or element of other collection type */
			goto ok;
		} else {
			xml_error(userData->data, "unexpected element tag '%s' in collection.", db_xmlnodeName(node));
			goto error;
		}
	}

	/* Insert element */
	if (db_deserXmlCollectionInsertElement(node, o, userData)) {
		goto error;
	}

ok:
	return 1;
error:
	xml_error(userData->data, "failed to deserialize element.");
	return 0;
}

/* Deserialize collection - using regular notation */
int db_deserXmlCollection(db_xmlnode node, db_typedef t, void* o, db_bool othersAllowed, deser_xmldata data) {
	deser_xmlElementData walkData;
	deser_xmldata_s privateData;

	privateData = db_deserXmlDataClone(data);

	/* Create collection */
	if (db_deserXmlCollectionNew(t, o)) {
		goto error;
	}

	/* Walk elements */
	walkData.collection = o;
	walkData.t = t;
	walkData.data = &privateData;
	walkData.count = 0;
	walkData.othersAllowed = othersAllowed; /* Don't allow members or elements from other collections within scope */
	if (!db_xmlnodeWalkChildren(node, (db_xmlreaderWalkCallback)db_deserXmlElement, &walkData)) {
		xml_error(data, "An error occured while deserializing elements of collection '%s'.", db_xmlnodeName(node));
		goto error;
	}

	db_deserXmlDataFree(&privateData);
	return 0;
error:
	db_deserXmlDataFree(&privateData);
	return -1;
}

typedef struct deser_xmlMemberData_s* deser_xmlMemberData;
typedef struct deser_xmlMemberData_s {
	db_typedef t;
	void* o;
	deser_xmldata data;
}deser_xmlMemberData_s;

/* Deserialize attribute */
static int db_deserXmlAttrWalk(db_string ns, db_string attr, db_string content, deser_xmlMemberData userData) {
	db_member member;
	db_type t;
	DB_UNUSED(ns);

	/* Check if attribute has not been consumed yet */
	if (db_deserXmlMemberCheck(attr, userData->data)) {
		goto ok;
	}

	/* Lookup member */
	member = db_interface_resolveMember(db_interface(userData->t->real), attr);
	if (member) {
		t = member->type->real;
		/* Check if member is of a primitive type */
		if ((t->kind == DB_PRIMITIVE) || t->reference) {
			if (db_deserXmlPrimitive(content, member->type, DB_OFFSET(userData->o, member->offset), userData->data)) {
				goto error;
			}
		} else {
			xml_error(userData->data, "non-primitive member '%s' cannot be specified as attribute.", attr);
			goto error;
		}
	} else {
		db_id fullname;
		xml_error(userData->data, "type '%s' has no member '%s'.", db_fullname(userData->t, fullname), attr);
		goto error;
	}

	/* Mark attribute as consumed */
	db_deserXmlMemberSet(attr, userData->data );

ok:
	return 1;
error:
	return 0;
}

/* Check if node is element of inlined collection */
db_string db_deserXmlIsInlinedElement(db_string type, deser_xmlMemberData userData) {
	db_interface s;
	db_typedef subtype;
	db_uint32 i;
	db_string result;
	db_member m;


	s = db_interface(userData->t->real);
	result = 0;

	/* Look for collections that can be used inlined */
	for(i=0; i<s->members.length; i++) {
		m = s->members.buffer[i];
		if (m->type->real->kind == DB_COLLECTION) {
			subtype = ((db_collection)m->type->real)->elementType;
			if (db_checkAttr(subtype, DB_ATTR_SCOPED) && !strcmp(db_nameof(subtype), type)) {
				result = db_nameof(s->members.buffer[i]);
				break;

			/* Compare fully qualified names */
			} else {
				db_id subtypeName;
				db_id typeName;
				db_object o;

				o = db_lookup(userData->data->scope, type);
				if (o) {
					if (!strcmp(db_fullname(subtype, subtypeName), db_fullname(o, typeName))) {
						result = db_nameof(s->members.buffer[i]);
						break;
					}
					db_free(o);
				}
			}
		}
	}

	return result;
}

/* Deserialize inlined member */
int db_deserXmlInlinedMember(db_xmlnode node, db_string name, deser_xmlMemberData userData) {
	db_member member;
	db_string memberName;

	memberName = 0;

	/* Check if this node is actually an element of an inlined collection */
	if ((memberName = db_deserXmlIsInlinedElement((db_string)name, userData))) {
		if (!db_deserXmlMemberCheck(memberName, userData->data)) {

			/* Lookup member */
			member = db_resolve(userData->t->real, memberName);
			if (member) {

				/* Deserialize collection */
				if (db_deserXmlCollection(db_xmlnodeParent(node), member->type, DB_OFFSET(userData->o, member->offset), 1, userData->data)) {
				    db_free(member);
					goto error;
				}
				db_free(member);
			}
		}

		/* Set member as processed - so collection won't be parsed again. */
		db_deserXmlMemberSet(memberName, userData->data);
	} else {
		db_id fullname;
		xml_error(userData->data, "type '%s' has no member named- or inlined collection with subtype '%s'.", db_fullname(userData->t, fullname), name);
		goto error;
	}

	return 0;
error:
	return -1;
}

/* Deserialize membernodes */
static int db_deserXmlMemberWalk(db_xmlnode node, deser_xmlMemberData userData) {
	db_member member;

	XML_NODE(node, userData->data);

	if (db_xmlnodeNs(node) && !strcmp(db_xmlnodeNs(node), "meta")) {
		if (db_deserXmlMetaExt(node, XML_MEMBER, userData->t, userData->o, userData->data)) {
			goto error;
		}
	} else {

		/* Lookup member */
		member = db_interface_resolveMember(db_interface(userData->t->real), (db_string)db_xmlnodeName(node));
		if (member) {
			deser_xmldata_s privateData = *userData->data;

			privateData.attrParsed = 0;
			if (db_deserXmlValue(node, XML_MEMBER, member->type, DB_OFFSET(userData->o, member->offset), &privateData)) {
				goto error;
			}
			if (privateData.attrParsed) {
				db_llFree(privateData.attrParsed);
			}
		} else {
			if (db_deserXmlInlinedMember(node, (db_string)db_xmlnodeName(node), userData)) {
				goto error;
			}
		}
	}

	return 1;
error:
	return 0;
}

/* Deserialize complex type */
int db_deserXmlComplex(db_xmlnode node, db_typedef t, void* o, deser_xmldata data) {
	deser_xmlMemberData_s walkData;

	walkData.o = o;
	walkData.t = t;
	walkData.data = data;

	/* Deserialize attributes */
	if (!db_xmlnodeWalkAttr(node, (db_xmlreaderWalkAttrCallback)db_deserXmlAttrWalk, &walkData)) {
		goto error;
	}

	/* Deserialize childnodes */
	if (!db_xmlnodeWalkChildren(node, (db_xmlreaderWalkCallback)db_deserXmlMemberWalk, &walkData)) {
		goto error;
	}

	return 0;
error:
	return -1;
}

/* Deserialize xml value */
int db_deserXmlValue(db_xmlnode node, db_deserXmlScope scope, db_typedef type, void* o, deser_xmldata data) {
	db_type t;

	t = type->real;

	/* Deserialize primitive */
	if ((t->kind == DB_PRIMITIVE) || (t->reference && (scope != XML_OBJECT))) {
		db_string content;
		if (db_deserXmlPrimitive((content = db_xmlnodeContent(node)), type, o, data)) {
			goto error;
		}

		db_dealloc(content);

	/* Deserialize collection */
	} else if (t->kind == DB_COLLECTION) {
		if (db_deserXmlCollection(node, type, o, 0, data)) {
			goto error;
		}
	}

	/* Deserialize complex type */
	else if ((t->kind == DB_COMPOSITE) || (t->reference && (scope == XML_OBJECT))) {
		if (db_deserXmlComplex(node, type, o, data)) {
			goto error;
		}
	}

	return 0;
error:
	return -1;
}

/* Deserialize object */
int db_deserXmlObject(db_xmlnode node, db_string name, db_string type, deser_xmldata data) {
	db_typedef t;
	db_object o;

	/* Lookup type */
	t = db_deserXmlNsResolve(NULL, type, data);
	if (!t) {
		xml_error(data, "unknown type '%s'.", type); goto error;
	} else if (!db_instanceof(db_typedef(db_typedef_o), t)) {
		db_id id;
		xml_error(data, "object '%s' is not a type", db_fullname(t, id)); goto error;
	}

	/* Declare object */
	o = db_deserXmlDeclare(data, name, t);
	db_free(t); /* Free reference to t obtained by resolve */
	if (!o) {
		xml_error(data, "failed to create object '%s : %s'.", name, type); goto error;
	}
	/* Deserialize value */
	data->cur = o;
	if (db_deserXmlValue(node, XML_OBJECT, t, o, data)) {
	    db_invalidate(o);
		goto error;
	}

	/* Construct(finalize) object */
	if (db_define(o)) {
		xml_error(data, "failed to construct object '%s : %s'.", name, type); goto error;
	}

	return 0;
error:
	return -1;
}

/* Deserialize meta-directive */
int db_deserXmlMeta(db_xmlnode node, db_deserXmlScope scope, deser_xmldata data) {
	return db_deserXmlMetaExt(node, scope, 0, 0, data);
}

/* Deserialize meta-directive */
int db_deserXmlMetaExt(db_xmlnode node, db_deserXmlScope scope, db_typedef t, void* o, deser_xmldata data) {
	db_string oper;
	db_string type;
	db_string name;
	db_xmlnode object;

	oper = (db_string)db_xmlnodeName(node);

	/* meta:object */
	if (!strcmp(oper, "object")) {
		type = db_xmlnodeAttrStr(node, "type");

		/* Get value node */
		object = db_xmlnodeFind(node, "value");
		if (object) {
			/* Parse new object */
			if (scope == XML_OBJECT) {
				name = db_xmlnodeAttrStr(node, "name");

				/* Deserialize object */
				if (db_deserXmlObject(object, name, type, data)) {
					goto error;
				}

				free(name);

			/* Serialize collection element */
			} else if (scope == XML_ELEMENT) {
				if (db_deserXmlValue(object, scope, t, o, data)) {
					goto error;
				}

			/* Serialize collection element using short verbose object notation */
			} else if (scope == XML_MEMBER) {
				deser_xmlMemberData_s memberData;
				db_string type = db_xmlnodeAttrStr(node, "type");

				memberData.t = t;
				memberData.o = o;
				memberData.data = data;
				if (db_deserXmlInlinedMember(node, type, &memberData)) {
					goto error;
				}
			}
		} else {
			if (scope == XML_OBJECT) {
				db_typedef t;
				/* Forward declaration */
				name = db_xmlnodeAttrStr(node, "name");
				t = db_deserXmlNsResolve(NULL, type, data);
				if ((scope == XML_OBJECT) && !db_deserXmlDeclare(data, name, t)) {
					goto error;
				}
				free(name);
				db_free(t);
			} else {
				xml_error(data, "missing value-element for meta:object element.");
				goto error;
			}
		}

		free(type);

	/* Serialize collection element */
	} else if (!strcmp(oper, "element")) {

		/* Deserialize value of element - no value-tag needed. */
		if (db_deserXmlValue(node, scope, t, o, data)) {
			goto error;
		}

	/* meta:include */
	} else if (!strcmp(oper, "include")) {
		db_string filename = db_xmlnodeAttrStr(node, "file");
		if (filename) {
			db_load(filename);
			free(filename);
		} else {
			xml_error(data, "missing 'file' attribute for meta:include.");
			goto error;
		}

	/* meta:scope */
	} else if (!strcmp(oper, "scope") || !strcmp(oper, "namespace")){
		db_object s;
		deser_xmldata_s privateData;

		/* Lookup scope if the scope of the element is an object */
		if (scope == XML_OBJECT) {
            db_string name;

            /* Resolve name attribute */
            name = db_xmlnodeAttrStr(node, "name");

            /* first try to resolve scope */
            s = db_lookup(data->scope, name);
            if (!s) {
                s = db_declare(data->scope, name, (db_typedef)db_void_o);
                db_keep(s);
            }

            free(name);
		}
		/* If the elementscope is a member, the current object will be the scope. */
		else if (scope == XML_MEMBER) {
		    s = data->cur;
		    db_keep(s);
		} else {
		    s = NULL;
		    xml_error(data, "invalid use of meta:scope.");
		    goto error;
		}

		name = db_nameof(s);

		/* resolve objects in scope */
		privateData = *data;
		privateData.scope = s;
		privateData.attrParsed = NULL;

		/* Walk root */
		if (!db_xmlnodeWalkChildren(node, (db_xmlreaderWalkCallback)db_deserXmlNode, &privateData)) {
			xml_error(data, "error(s) occured while deserializing scope '%s'.", name); goto error;
		}

		db_deserXmlDataFree(&privateData);

	/* meta:super */
	} else if (!strcmp(oper, "super")) {
		/* Check if type supports inheritance */
		if (!db_class_instanceof(db_class_o, db_typeof(t)->real)) {
			db_typedef extend;

			/* Check if type inherits */
			if ((extend = (db_typedef)db_interface(t->real)->base)) {
				deser_xmldata_s privateData;

				privateData = db_deserXmlDataClone(data);
				if (db_deserXmlValue(node, XML_OBJECT, extend, o, &privateData)) {
					goto error;
				}
				db_deserXmlDataFree(&privateData);
			} else {
				db_id fullname;
				xml_error(data, "Invalid super-tag: type '%s' has no base type.", db_fullname(t, fullname));
			}
		} else {
			db_id fullname;
			xml_error(data, "Invalid super-tag: type-kind of '%s' does not support inheritance.", db_fullname(t, fullname));
		}

	/* using */
	} else if (!strcmp(oper, "using")) {
		db_string ns = db_xmlnodeAttrStr(node, "namespace");
		db_deserXmlNsUse(ns, data);
	} else {
		xml_warning(data, "unknown operation '%s'.", oper);
	}

	return 0;
error:
	return -1;
}

/* Deserialize node */
int db_deserXmlNode(db_xmlnode node, deser_xmldata data) {
	db_string ns;
	db_string name;
	deser_xmldata_s privateData;

	XML_NODE(node, data);

	privateData = db_deserXmlDataClone(data);

	ns = (db_string)db_xmlnodeNs(node);
	if (ns) {
		/* Deserialize meta-directive */
		if (!strcmp(ns, "meta")) {
			if (db_deserXmlMeta(node, XML_OBJECT, &privateData)) {
				goto error;
			}
		} else {
			xml_warning(data, "unknown namespace '%s'.", ns);
		}
	} else {
		/* Deserialize object */
		name = db_xmlnodeAttrStr(node, "name");

		/* Mark attribute as consumed */
		db_deserXmlMemberSet("name", &privateData);

		if (db_deserXmlObject(node, name, (db_string)db_xmlnodeName(node), &privateData)) {
			goto error;
		}
		free(name);
	}

	db_deserXmlDataFree(&privateData);

	return 1;
error:
	db_deserXmlDataFree(&privateData);
	return 0;
}

/* Deserialize xml */
int db_deserXml(db_string file, void* udata) {
	deser_xmldata_s data;

	DB_UNUSED(udata);

	/* Load reader */
	data.reader = db_xmlreaderNew(file, "meta");
	if (data.reader) {
		data.node = db_xmlreaderRoot(data.reader);
		data.scope = root_o;
		data.file = file;
		data.line = 0;
		data.attrParsed = 0;
		data.using = db_llNew();

		if (!db_xmlnodeWalkChildren(data.node, (db_xmlreaderWalkCallback)db_deserXmlNode, &data)) {
			db_error("error(s) occured while deserializing file '%s'.", file);
			goto error;
		}

		/* Free using */
		db_llFree(data.using);

		/* Free attrParsed */
		if (data.attrParsed) {
			db_llFree(data.attrParsed);
		};

		/* Free reader */
		db_xmlreaderFree(data.reader);
	} else {
		goto error;
	}

	return 0;
error:
	return -1;
}

