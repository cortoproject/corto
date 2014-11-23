/*
 * db_serializer.c
 *
 *  Created on: Aug 23, 2012
 *      Author: sander
 */

#include "db_serializer.h"
#include "db_util.h"
#include "db_err.h"
#include "db_object.h"
#include "db__object.h"
#include "db__meta.h"
#include "db_class.h"
#include "db_primitive.h"

#include "alloca.h"
#include "string.h"

/*#define DB_SERIALIZER_TRACING*/
#ifdef DB_SERIALIZER_TRACING
static int indent = 0;
#endif

/* Forward value to the right callback function */
db_int16 db_serializeValue(db_serializer _this, db_value* info, void* userData) {
    db_type t;
    db_int16 result;
    db_serializerCallback cb;

    t = db_valueType(info)->real;

    cb = NULL;

    if (!_this->initialized) {
    	db_assert(0, "serializer is not initialized!");
    }

    if (!_this->constructed) {
        if (_this->construct) {
            if (_this->construct(_this, info, userData)) {
                goto error;
            }
        }
        _this->constructed = TRUE;
    }

    /* If the serializer has a special handler for reference types, use it in case the
     * type is a reference type. */
    if (t->reference && (info->kind != DB_OBJECT) && (info->kind != DB_BASE)) {
        cb = _this->reference;
    } else
    /* ..otherwise use the program-handler */
    if (!cb) {
        cb = _this->program[t->kind];
    }

    result = 0;
    if (cb) {
        result = cb(_this, info, userData);
    }

    return result;
error:
	return -1;
}

void db_serializerInit(db_serializer _this) {
    memset(_this, 0, sizeof(struct db_serializer_s));
    _this->program[DB_ANY] = db_serializeAny;
    _this->program[DB_BASE] = db_serializeValue;
	_this->program[DB_COMPOSITE] = db_serializeMembers;
	_this->program[DB_COLLECTION] = db_serializeElements;
	_this->initialized = TRUE;
	_this->constructed = FALSE;
	_this->access = DB_GLOBAL;
	_this->accessKind = DB_XOR;
}

/* Start serializing */
db_int16 db_serialize(db_serializer _this, db_object o, void* userData) {
    db_value info;
    db_serializerCallback cb;
    db_int16 result;
    
    if (_this->initialized != TRUE) {
    	db_assert(0, "serializer is not initialized!");
    }
    
    info.kind = DB_OBJECT;
    info.parent = NULL;
    info.is.o = o;

    if (_this->construct) {
        if (_this->construct(_this, &info, userData)) {
            goto error;
        }
    }

    _this->constructed = TRUE;

    if (!(cb = _this->metaprogram[DB_OBJECT])) {
    	cb = db_serializeValue;
    }
    
#ifdef DB_SERIALIZER_TRACING
    {
        db_id id, id2;
        printf("%*sserialize(%s : %s // %s)\n",
               indent, " ", db_fullname(o, id), db_fullname(db_typeof(o), id2), db_checkState(o, DB_DESTRUCTED)?"destructed":"valid"); fflush(stdout);
        indent++;
    }
#endif

    result = cb(_this, &info, userData);
    
#ifdef DB_SERIALIZER_TRACING
    indent--;
#endif
    
    return result;
error:
    return -1;
}

/* Destruct serializerdata */
db_int16 db_serializeDestruct(db_serializer _this, void* userData) {
    if (_this->destruct) {
        if (_this->destruct(_this, userData)) {
            goto error;
        }
    }
error:
    return -1;
}

db_bool db_serializeMatchAccess(db_operatorKind accessKind, db_modifier sa, db_modifier a) {
    db_bool result;

    switch(accessKind) {
    case DB_OR:
    	result = (sa & a);
    	break;
    case DB_XOR:
    	result = (sa & a) == sa;
    	break;
    case DB_NOT:
    	result = !(sa & a);
    	break;
    default:
    	db_error("unsupported operator %s for serializer accessKind.", db_nameof(db_enum_constant(db_operatorKind_o, accessKind)));
    	result = FALSE;
    	break;
    }

    return result;
}

/* Serialize any-value */
db_int16 db_serializeAny(db_serializer _this, db_value* info, void* userData) {
    db_value v;
    db_any *any;

    any = db_valueValue(info);
    v.parent = info;
    db_valueValueInit(&v, db_valueObject(info), (db_typedef)any->type, any->value);

    return db_serializeValue(_this, &v, userData);
}

/* Serialize members */
db_int16 db_serializeMembers(db_serializer _this, db_value* info, void* userData) {
    db_interface t;
    db_void* v;
    db_uint32 i;
    db_value member;
    db_member m;
    db_serializerCallback cb;
    db_object o;

    t = db_interface(db_valueType(info)->real);
    v = db_valueValue(info);
    o = db_valueObject(info);


    /* Process inheritance */
    if (db_class_instanceof(db_struct_o, t) && db_serializeMatchAccess(_this->accessKind, _this->access, db_struct(t)->baseAccess)) {
        db_value base;

        cb = _this->metaprogram[DB_BASE];
        if (!cb) {
            cb = db_serializeValue;
        }

        if (db_interface(t)->base) {
            base.kind = DB_BASE;
            base.parent = info;
            base.is.base.v = v;
            base.is.base.t = db_typedef(db_interface(t)->base);
            base.is.base.o = o;
#ifdef DB_SERIALIZER_TRACING
            {
                db_id id;
                printf("%*sbase(%s)\n", indent, " ", db_fullname(base.is.base.t, id)); fflush(stdout);
			}
            indent++;
#endif
            if (cb(_this, &base, userData)) {
				goto error;
			}
#ifdef DB_SERIALIZER_TRACING
            indent--;
#endif
        }
    }

    cb = _this->metaprogram[DB_MEMBER];
    if (!cb) {
        cb = db_serializeValue;
    }

    /* Process members */
    for(i=0; i<t->members.length; i++) {
        m = t->members.buffer[i];
        if (db_serializeMatchAccess(_this->accessKind, _this->access, m->modifiers)) {
            member.kind = DB_MEMBER;
            member.parent = info;
            member.is.member.o = o;
            member.is.member.t = m;
            member.is.member.v = DB_OFFSET(v, m->offset);
#ifdef DB_SERIALIZER_TRACING
            {
                db_id id, id2;
                printf("%*smember(%s : %s)\n", indent, " ", db_fullname(m, id2), db_fullname(member.is.member.t->type, id)); fflush(stdout);
			}
            indent++;
#endif
            if (cb(_this, &member, userData)) {
                goto error;
            }
#ifdef DB_SERIALIZER_TRACING
            indent--;
#endif
        }
    }

    return 0;
error:
    return -1;
}

struct db_serializeElement_t {
    db_serializer _this;
    void* userData;
    db_value* info;
    db_serializerCallback cb;
};

/* Serialize element */
int db_serializeElement(void* e, void* userData) {
    struct db_serializeElement_t* data;
    db_serializer _this;
    db_value* info;
    db_type t;

    data = userData;
    _this = data->_this;
    info = data->info;
    t = db_valueType(info->parent)->real;

    /* Set element value */
    if ((db_collection(t)->kind == DB_ARRAY) || (db_collection(t)->kind == DB_SEQUENCE)) {
        info->is.element.v = e;
    } else {
        info->is.element.v = e;
    }

    /* Forward element to serializer callback */
    if (data->cb(_this, info, data->userData)) {
        goto error;
    }

    /* Increase index */
    info->is.element.t.index++;

    return 1;
error:
    return 0;
}

/* Serialize elements */
db_int16 db_serializeElements(db_serializer _this, db_value* info, void* userData) {
    struct db_serializeElement_t walkData;
    db_collection t;
    db_void* v;
    db_value elementInfo;

    t = db_collection(db_valueType(info)->real);
    v = db_valueValue(info);

    /* Value object for element */
    elementInfo.kind = DB_ELEMENT;
    elementInfo.is.element.o = db_valueObject(info);
    elementInfo.parent = info;
    elementInfo.is.element.t.type = t->elementType;
    elementInfo.is.element.t.index = 0;

    walkData._this = _this;
    walkData.userData = userData;
    walkData.info = &elementInfo;

    /* Determine callback now, instead of having to do this in the element callback */
    walkData.cb = _this->metaprogram[DB_ELEMENT];
    if (!walkData.cb) {
        walkData.cb = db_serializeValue;
    }

    /* Walk elements */
    if (!db_walk(t, v, db_serializeElement, &walkData)) {
        goto error;
    }

    return 0;
error:
    return -1;
}





