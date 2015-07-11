#include "json_composites.h"

#include "json_deser.h"

static cx_bool json_deserComposite_isJsonBaseMember(const char* name) {
    return !strncmp(name, "@", 1);
}

static cx_bool json_deserComposite_getBaseName(JSON_Object* jsonObj, const char** out) {
    cx_bool error = FALSE;
    size_t count = json_object_get_count(jsonObj);
    if (!count) {
        cx_error("empty composite value");
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

static cx_bool json_deserComposite_getBase(JSON_Object* jsonObj, JSON_Object** out) {
    cx_bool error = FALSE;
    const char* baseName = NULL;
    if (json_deserComposite_getBaseName(jsonObj, &baseName)) {
        error = TRUE;
        goto error;
    }
    if (baseName) {
        if ((*out = json_object_get_object(jsonObj, baseName))) {
            error = TRUE;
            goto error;
        }
    }
    error:
return error;
}

static cx_bool json_deserComposite_recursive(cx_object o, JSON_Object *jsonObj, cx_interface interface) {
    cx_bool error = FALSE;
    JSON_Object* base = NULL;
    if (json_deserComposite_getBase(jsonObj, &base)) {
        goto error;
    }
    if (base) {
        cx_interface baseInterface = interface->base;
        json_deserComposite_recursive(o, base, baseInterface);
    }
    size_t count = json_object_get_count(jsonObj);
    size_t i;
    for (i = 0; i < count; i++) {
        const char* memberName = json_object_get_name(jsonObj, i);
        if (json_deserComposite_isJsonBaseMember(memberName)) {
            continue;
        }
        // TODO we need resolve exclusively in the scope without cx_resolve magic
        cx_member member;
        JSON_Value* memberJsonValue;
        member = cx_resolve(interface, (cx_string)memberName);
        if (!member) {
            cx_id typeFullname;
            cx_fullname(cx_typeof(o), typeFullname);
            cx_error("cannot find member %s in type %s", memberName, typeFullname);
            goto error;
        }
        memberJsonValue = json_object_get_value(jsonObj, memberName);
        void *offset = CX_OFFSET(o, member->offset);
        if ((error = json_deser_forward(offset, member->type, memberJsonValue))) {
            cx_error("cannot deserialize member %s", memberName);
            goto error;
        }
    }
error:;
    return error;
}

cx_bool json_deserComposite(cx_object o, JSON_Value *value) {
    cx_bool error = FALSE;
    JSON_Object *jsonObject = json_value_get_object(value);
    if ((error = !jsonObject)) {
        cx_error("Composite JSON value not a JSON object");
        goto error;
    }
    json_deserComposite_recursive(o, jsonObject, cx_interface(cx_typeof(o)));
error:
    return error;
}
