#include "json_composites.h"

#include "json_deser.h"
#include "json_references.h"

static corto_bool json_deserComposite_isJsonBaseMember(const char* name) {
    return !strncmp(name, "@", 1);
}

static corto_bool json_deserComposite_getBaseName(JSON_Object* jsonObj, const char** out) {
    corto_bool error = FALSE;
    size_t count = json_object_get_count(jsonObj);
    if (!count) {
        corto_error("empty composite value");
        error = TRUE;
        goto error;
    }
    size_t i = 0;
    for (i = 0; i < count; i++) {
        const char* baseName = json_object_get_name(jsonObj, 0);
        if (json_deserComposite_isJsonBaseMember(baseName)) {
            *out = baseName;
            break;
        }
    }
error:
    return error;
}

static corto_bool json_deserComposite_getBase(JSON_Object* jsonObj, JSON_Value** out) {
    const char* baseName = NULL;
    if (json_deserComposite_getBaseName(jsonObj, &baseName)) {
        goto error;
    }
    if (baseName) {
        *out = json_object_get_value(jsonObj, baseName);
        if (*out == NULL) {
            corto_error("cannot retrieve base member");
            goto error;
        }
    }
    return FALSE;
error:
    return TRUE;
}

static corto_bool json_deserComposite_tryDeserBase(void* p, corto_type t, JSON_Value* v) {
    JSON_Object* o = json_value_get_object(v);
    if (!o) {
        corto_error("composite value not a JSON object");
        goto error;
    }

    JSON_Value* baseValue = NULL;
    if (json_deserComposite_getBase(o, &baseValue)) {
        goto error;
    }
    if (baseValue) {
        corto_interface baseInterface = corto_interface(t)->base;
        if (!baseInterface) {
            corto_error("type %s does not have base type", corto_nameof(t));
            goto error;
        }
        if (json_deserComposite(p, corto_type(baseInterface), baseValue)) {
            goto error;
        }
    }
    return FALSE;
error:
    return TRUE;
}

corto_bool json_deserComposite(void* p, corto_type t, JSON_Value *v) {
    corto_assert(t->kind == CORTO_COMPOSITE, "not deserializing composite");
    if (json_value_get_type(v) != JSONObject) {
        corto_error("composite value is not JSON object");
        goto error;
    }
    if (json_deserComposite_tryDeserBase(p, t, v)) {
        corto_error("cannot deserialie base");
        goto error;
    }

    JSON_Object* o = json_value_get_object(v);
    size_t count = json_object_get_count(o);
    size_t i;
    for (i = 0; i < count; i++) {
        const char* memberName = json_object_get_name(o, i);
        if (json_deserComposite_isJsonBaseMember(memberName)) {
            continue;
        }
        corto_member member;
        JSON_Value* memberJsonValue;
        member = corto_lookup(t, (corto_string)memberName);
        if (!member) {
            corto_id typeFullname;
            corto_fullname(t, typeFullname);
            corto_error("cannot find member %s in type %s", memberName, typeFullname);
            goto error;
        }
        memberJsonValue = json_object_get_value(o, memberName);
        void *offset = CORTO_OFFSET(p, member->offset);
        corto_bool error;
        if (member->type->reference) {
            error = json_deserReference(offset, member->type, memberJsonValue);
        } else {
            error = json_deser_forward(offset, member->type, memberJsonValue);
        }
        corto_release(member);
        if (error) {
            corto_error("cannot deserialize member %s", memberName);
            goto error;
        }
    }
    return FALSE;
error:
    return TRUE;
}
