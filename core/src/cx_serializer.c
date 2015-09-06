/*
 * cx_serializer.c
 *
 *  Created on: Aug 23, 2012
 *      Author: sander
 */

#include "cx_serializer.h"
#include "cx_util.h"
#include "cx_err.h"
#include "cx_object.h"
#include "cx__object.h"
#include "cx__meta.h"
#include "cx__collection.h"
#include "cx.h"

#include "alloca.h"
#include "string.h"

/*#define CX_SERIALIZER_TRACING*/
#ifdef CX_SERIALIZER_TRACING
static int indent = 0;
#endif

/* Forward value to the right callback function */
cx_int16 cx_serializeValue(cx_serializer this, cx_value* info, void* userData) {
    cx_type t;
    cx_int16 result;
    cx_serializerCallback cb;

    t = cx_valueType(info);

    cb = NULL;

    if (!this->initialized) {
        cx_assert(0, "serializer is not initialized!");
    }

    if (!this->constructed) {
        if (this->construct) {
            if (this->construct(this, info, userData)) {
                goto error;
            }
        }
        this->constructed = TRUE;
    }

    /* If the serializer has a special handler for reference types, use it in case the
     * type is a reference type. */
    if (t->reference && (info->kind != CX_OBJECT) && (info->kind != CX_BASE)) {
        cb = this->reference;
    } else
    /* ..otherwise use the program-handler */
    if (!cb) {
        cb = this->program[t->kind];
    }

    result = 0;
    if (cb) {
        result = cb(this, info, userData);
    }

    return result;
error:
    return -1;
}

void cx_serializerInit(cx_serializer this) {
    memset(this, 0, sizeof(struct cx_serializer_s));
    this->program[CX_ANY] = cx_serializeAny;
    this->program[CX_COMPOSITE] = cx_serializeMembers;
    this->program[CX_COLLECTION] = cx_serializeElements;
    this->initialized = TRUE;
    this->constructed = FALSE;
    this->access = CX_GLOBAL;
    this->accessKind = CX_XOR;
}

/* Start serializing */
cx_int16 cx_serialize(cx_serializer this, cx_object o, void* userData) {
    cx_value info;
    cx_serializerCallback cb;
    cx_int16 result;
    
    if (this->initialized != TRUE) {
        cx_assert(0, "serializer is not initialized!");
    }
    
    info.kind = CX_OBJECT;
    info.parent = NULL;
    info.is.object.o = o;
    info.is.object.t = cx_typeof(o);

    if (this->construct) {
        if (this->construct(this, &info, userData)) {
            goto error;
        }
    }

    this->constructed = TRUE;

    if (!(cb = this->metaprogram[CX_OBJECT])) {
        cb = cx_serializeValue;
    }
    
#ifdef CX_SERIALIZER_TRACING
    {
        cx_id id, id2;
        printf("%*sserialize(%s : %s // %s)\n",
               indent, " ", cx_fullname(o, id), cx_fullname(cx_typeof(o), id2), cx_checkState(o, CX_DESTRUCTED)?"destructed":"valid"); fflush(stdout);
        indent++;
    }
#endif

    result = cb(this, &info, userData);
    
#ifdef CX_SERIALIZER_TRACING
    indent--;
#endif
    
    return result;
error:
    return -1;
}

/* Destruct serializerdata */
cx_int16 cx_serializeDestruct(cx_serializer this, void* userData) {
    if (this->destruct) {
        if (this->destruct(this, userData)) {
            goto error;
        }
    }
error:
    return -1;
}

cx_bool cx_serializeMatchAccess(cx_operatorKind accessKind, cx_modifier sa, cx_modifier a) {
    cx_bool result;

    switch(accessKind) {
    case CX_OR:
        result = (sa & a);
        break;
    case CX_XOR:
        result = (sa & a) == sa;
        break;
    case CX_NOT:
        result = !(sa & a);
        break;
    default:
        cx_error("unsupported operator %s for serializer accessKind.", cx_nameof(cx_enum_constant(cx_operatorKind_o, accessKind)));
        result = FALSE;
        break;
    }

    return result;
}

/* Serialize any-value */
cx_int16 cx_serializeAny(cx_serializer this, cx_value* info, void* userData) {
    cx_value v;
    cx_any *any;
    cx_int16 result = 0;

    any = cx_valueValue(info);

    if (any->type) {
        v.parent = info;
        cx_valueValueInit(&v, cx_valueObject(info), (cx_type)any->type, any->value);
        result = cx_serializeValue(this, &v, userData);
    }

    return result;
}

/* Serialize members */
cx_int16 cx_serializeMembers(cx_serializer this, cx_value* info, void* userData) {
    cx_interface t;
    cx_void* v;
    cx_uint32 i;
    cx_value member;
    cx_member m;
    cx_serializerCallback cb;
    cx_object o;

    t = cx_interface(cx_valueType(info));
    v = cx_valueValue(info);
    o = cx_valueObject(info);


    /* Process inheritance */
    if (cx_class_instanceof(cx_struct_o, t) && cx_serializeMatchAccess(this->accessKind, this->access, cx_struct(t)->baseAccess)) {
        cx_value base;

        cb = this->metaprogram[CX_BASE];
        if (!cb) {
            cb = cx_serializeValue;
        }

        if (cx_interface(t)->base) {
            base.kind = CX_BASE;
            base.parent = info;
            base.is.base.v = v;
            base.is.base.t = cx_type(cx_interface(t)->base);
            base.is.base.o = o;
#ifdef CX_SERIALIZER_TRACING
            {
                cx_id id;
                printf("%*sbase(%s)\n", indent, " ", cx_fullname(base.is.base.t, id)); fflush(stdout);
            }
            indent++;
#endif
            if (cb(this, &base, userData)) {
                goto error;
            }
#ifdef CX_SERIALIZER_TRACING
            indent--;
#endif
        }
    }

    cb = this->metaprogram[CX_MEMBER];
    if (!cb) {
        cb = cx_serializeValue;
    }

    /* Process members */
    for(i=0; i<t->members.length; i++) {
        m = t->members.buffer[i];
        if (cx_serializeMatchAccess(this->accessKind, this->access, m->modifiers)) {
            member.kind = CX_MEMBER;
            member.parent = info;
            member.is.member.o = o;
            member.is.member.t = m;
            member.is.member.v = CX_OFFSET(v, m->offset);
#ifdef CX_SERIALIZER_TRACING
            {
                cx_id id, id2;
                printf("%*smember(%s : %s)\n", indent, " ", cx_fullname(m, id2), cx_fullname(member.is.member.t->type, id)); fflush(stdout);
            }
            indent++;
#endif
            if (cb(this, &member, userData)) {
                goto error;
            }
#ifdef CX_SERIALIZER_TRACING
            indent--;
#endif
        }
    }

    return 0;
error:
    return -1;
}

struct cx_serializeElement_t {
    cx_serializer this;
    void* userData;
    cx_value* info;
    cx_serializerCallback cb;
};

/* Serialize element */
int cx_serializeElement(void* e, void* userData) {
    struct cx_serializeElement_t* data;
    cx_serializer this;
    cx_value* info;

    data = userData;
    this = data->this;
    info = data->info;

    /* Set element value */
    info->is.element.v = e;

    /* Forward element to serializer callback */
    if (data->cb(this, info, data->userData)) {
        goto error;
    }

    /* Increase index */
    info->is.element.t.index++;

    return 1;
error:
    return 0;
}

/* Serialize elements */
cx_int16 cx_serializeElements(cx_serializer this, cx_value* info, void* userData) {
    struct cx_serializeElement_t walkData;
    cx_collection t;
    cx_void* v;
    cx_value elementInfo;

    t = cx_collection(cx_valueType(info));
    v = cx_valueValue(info);

    /* Value object for element */
    elementInfo.kind = CX_ELEMENT;
    elementInfo.is.element.o = cx_valueObject(info);
    elementInfo.parent = info;
    elementInfo.is.element.t.type = t->elementType;
    elementInfo.is.element.t.index = 0;

    walkData.this = this;
    walkData.userData = userData;
    walkData.info = &elementInfo;

    /* Determine callback now, instead of having to do this in the element callback */
    walkData.cb = this->metaprogram[CX_ELEMENT];
    if (!walkData.cb) {
        walkData.cb = cx_serializeValue;
    }

    /* Walk elements */
    if (!cx_walk(t, v, cx_serializeElement, &walkData)) {
        goto error;
    }

    return 0;
error:
    return -1;
}





