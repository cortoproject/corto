/*
 * corto_serializer.c
 *
 *  Created on: Aug 23, 2012
 *      Author: sander
 */

#include "corto/corto.h"
#include "_object.h"
#include "lang/_collection.h"

/*#define CORTO_SERIALIZER_TRACING*/
#ifdef CORTO_SERIALIZER_TRACING
static int indent = 0;
#endif

/* Forward value to the right callback function */
corto_int16 corto_serializeValue(corto_serializer this, corto_value* info, void* userData) {
    corto_type t;
    corto_int16 result;
    corto_serializerCallback cb;

    t = corto_value_getType(info);

    cb = NULL;

    if (!this->initialized) {
        corto_assert(0, "serializer is not initialized!");
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
    if (t->reference && (info->kind != CORTO_OBJECT) && (info->kind != CORTO_BASE)) {
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

void corto_serializerInit(corto_serializer this) {
    memset(this, 0, sizeof(struct corto_serializer_s));
    this->program[CORTO_ANY] = corto_serializeAny;
    this->program[CORTO_COMPOSITE] = corto_serializeMembers;
    this->program[CORTO_COLLECTION] = corto_serializeElements;
    this->metaprogram[CORTO_BASE] = corto_serializeValue;
    this->initialized = TRUE;
    this->constructed = FALSE;
    this->access = CORTO_GLOBAL;
    this->accessKind = CORTO_XOR;
    this->aliasAction = CORTO_SERIALIZER_ALIAS_FOLLOW;
    this->optionalAction = CORTO_SERIALIZER_OPTIONAL_IF_SET;
}

/* Start serializing */
corto_int16 corto_serialize(corto_serializer this, corto_object o, void* userData) {
    corto_value info;
    corto_serializerCallback cb;
    corto_int16 result;

    if (this->initialized != TRUE) {
        corto_assert(0, "serializer is not initialized!");
    }

    info.kind = CORTO_OBJECT;
    info.parent = NULL;
    info.is.object.o = o;
    info.is.object.t = corto_typeof(o);

    if (this->construct) {
        if (this->construct(this, &info, userData)) {
            goto error;
        }
    }

    this->constructed = TRUE;

    if (!(cb = this->metaprogram[CORTO_OBJECT])) {
        cb = corto_serializeValue;
    }

#ifdef CORTO_SERIALIZER_TRACING
    {
        corto_id id, id2;
        printf("%*sserialize(%s : %s // %s)\n",
               indent, " ", corto_fullname(o, id), corto_fullname(corto_typeof(o), id2), corto_checkState(o, CORTO_DESTRUCTED)?"destructed":"valid"); fflush(stdout);
        indent++;
    }
#endif

    result = cb(this, &info, userData);

#ifdef CORTO_SERIALIZER_TRACING
    indent--;
#endif

    return result;
error:
    return -1;
}

/* Destruct serializerdata */
corto_int16 corto_serializeDestruct(corto_serializer this, void* userData) {
    if (this->destruct) {
        if (this->destruct(this, userData)) {
            goto error;
        }
    }
error:
    return -1;
}

corto_bool corto_serializeMatchAccess(corto_operatorKind accessKind, corto_modifier sa, corto_modifier a) {
    corto_bool result;

    switch(accessKind) {
    case CORTO_OR:
        result = (sa & a);
        break;
    case CORTO_XOR:
        result = (sa & a) == sa;
        break;
    case CORTO_NOT:
        result = !(sa & a);
        break;
    default:
        corto_error("unsupported operator %s for serializer accessKind.", corto_idof(corto_enum_constant(corto_operatorKind_o, accessKind)));
        result = FALSE;
        break;
    }

    return result;
}

/* Serialize any-value */
corto_int16 corto_serializeAny(corto_serializer this, corto_value* info, void* userData) {
    corto_value v;
    corto_any *any;
    corto_int16 result = 0;

    any = corto_value_getPtr(info);

    if (any->type) {
        v.parent = info;
        v = corto_value_value(corto_type(any->type), any->value);
        result = corto_serializeValue(this, &v, userData);
    }

    return result;
}

/* Serialize a single member */
static corto_int16 corto_serializeMember(
    corto_serializer this,
    corto_member m,
    corto_object o,
    void *v,
    corto_serializerCallback cb,
    corto_value *info,
    void *userData)
{
    corto_value member;
    corto_modifier modifiers = m->modifiers;
    corto_bool isAlias = corto_instanceof(corto_alias_o, m);

    if (isAlias && (this->aliasAction == CORTO_SERIALIZER_ALIAS_FOLLOW)) {
        while (corto_instanceof(corto_alias_o, m)) {
            m = corto_alias(m)->member;
        }
    }

    if (!isAlias || (this->aliasAction != CORTO_SERIALIZER_ALIAS_IGNORE)) {
        if (corto_serializeMatchAccess(this->accessKind, this->access, modifiers)) {
            member.kind = CORTO_MEMBER;
            member.parent = info;
            member.is.member.o = o;
            member.is.member.t = m;
            if (modifiers & CORTO_OPTIONAL) {
                member.is.member.v = *(void**)CORTO_OFFSET(v, m->offset);
            } else {
                member.is.member.v = CORTO_OFFSET(v, m->offset);
            }
#ifdef CORTO_SERIALIZER_TRACING
            {
                corto_id id, id2;
                printf("%*smember(%s : %s)\n", indent, " ",
                    corto_fullname(m, id2),
                    corto_fullname(member.is.member.t->type, id));
                fflush(stdout);
            }
            indent++;
#endif
            /* Don't serialize if member is optional and not set */
            if (!(modifiers & CORTO_OPTIONAL) ||
                (this->optionalAction == CORTO_SERIALIZER_OPTIONAL_ALWAYS) ||
                member.is.member.v)
            {
                if (cb(this, &member, userData)) {
                    goto error;
                }
            }
#ifdef CORTO_SERIALIZER_TRACING
            indent--;
#endif
        }
    }

    return 0;
error:
    return -1;
}

/* Serialize members */
corto_int16 corto_serializeMembers(corto_serializer this, corto_value* info, void* userData) {
    corto_interface t;
    corto_void* v;
    corto_uint32 i;
    corto_member m;
    corto_serializerCallback cb;
    corto_object o;

    t = corto_interface(corto_value_getType(info));
    v = corto_value_getPtr(info);
    o = corto_value_getObject(info);

    /* Process inheritance */
    if (corto_class_instanceof(corto_struct_o, t) &&
        corto_serializeMatchAccess(this->accessKind, this->access, corto_struct(t)->baseAccess))
    {
        corto_value base;

        cb = this->metaprogram[CORTO_BASE];

        if (cb && corto_interface(t)->base) {
            base.kind = CORTO_BASE;
            base.parent = info;
            base.is.base.v = v;
            base.is.base.t = corto_type(corto_interface(t)->base);
            base.is.base.o = o;
#ifdef CORTO_SERIALIZER_TRACING
            {
                corto_id id;
                printf("%*sbase(%s)\n", indent, " ", corto_fullname(base.is.base.t, id)); fflush(stdout);
            }
            indent++;
#endif
            if (cb(this, &base, userData)) {
                goto error;
            }
#ifdef CORTO_SERIALIZER_TRACING
            indent--;
#endif
        }
    }

    cb = this->metaprogram[CORTO_MEMBER];
    if (!cb) {
        cb = corto_serializeValue;
    }

    /* Process members */
    if (corto_typeof(t) == corto_type(corto_union_o)) {
        corto_int32 discriminator = *(corto_int32*)v;
        corto_member member = corto_union_findCase(t, discriminator);
        if (member) {
            if (corto_serializeMember(this, member, o, v, cb, info, userData)) {
                goto error;
            }
        } else {
            /* Member not found? That means the discriminator is invalid. */
            corto_seterr("discriminator %d invalid for union '%s'\n",
                discriminator,
                corto_fullpath(NULL, t));
            goto error;
        }
    } else {
        for(i = 0; i < t->members.length; i  ++) {
            m = t->members.buffer[i];
            if (corto_serializeMember(this, m, o, v, cb, info, userData)) {
                goto error;
            }
        }
    }

    return 0;
error:
    return -1;
}

struct corto_serializeElement_t {
    corto_serializer this;
    void* userData;
    corto_value* info;
    corto_serializerCallback cb;
};

/* Serialize element */
int corto_serializeElement(void* e, void* userData) {
    struct corto_serializeElement_t* data;
    corto_serializer this;
    corto_value* info;

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
corto_int16 corto_serializeElements(corto_serializer this, corto_value* info, void* userData) {
    struct corto_serializeElement_t walkData;
    corto_collection t;
    corto_void* v;
    corto_value elementInfo;

    t = corto_collection(corto_value_getType(info));
    v = corto_value_getPtr(info);

    /* Value object for element */
    elementInfo.kind = CORTO_ELEMENT;
    elementInfo.is.element.o = corto_value_getObject(info);
    elementInfo.parent = info;
    elementInfo.is.element.t.type = t->elementType;
    elementInfo.is.element.t.index = 0;

    walkData.this = this;
    walkData.userData = userData;
    walkData.info = &elementInfo;

    /* Determine callback now, instead of having to do this in the element callback */
    walkData.cb = this->metaprogram[CORTO_ELEMENT];
    if (!walkData.cb) {
        walkData.cb = corto_serializeValue;
    }

    /* Walk elements */
    if (!corto_walk(t, v, corto_serializeElement, &walkData)) {
        goto error;
    }

    return 0;
error:
    return -1;
}
