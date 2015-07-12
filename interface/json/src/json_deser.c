
#include "parson.h"

#include "cortex.h"

#include "json_primitives.h"
#include "json_composites.h"

static cx_object cx_json_checkRoot(const char* parent, const char* name, const char* type) {
    cx_bool isRoot = !strcmp(parent, "");
    isRoot = isRoot && !strcmp(name, "::");
    isRoot = isRoot && !strcmp(type, cx_nameof(cx_typeof(root_o)));
    return isRoot ? root_o : NULL;
}

static cx_object cx_json_declare(JSON_Object *meta) {
    const char *parentName = json_object_get_string(meta, "parent");
    const char *name = json_object_get_string(meta, "name");
    const char *typeName = json_object_get_string(meta, "type");
    cx_object object, parent, type;
    object = parent = type = NULL;

    if (!(name && parentName && typeName)) {
        cx_error("meta does not have name, parent, or type");
        goto error;
    }
    if ((object = cx_json_checkRoot(parentName, name, typeName))) {
        goto finished;
    }
    parent = cx_resolve(NULL, (cx_string)parentName);
    if (!parent) {
        cx_error("parent %s could not be resolved", parentName);
        goto error;
    }
    type = cx_resolve(NULL, (cx_string)typeName);
    if (!type) {
        cx_free(parent);
        cx_error("type %s could not be resolved", typeName);
        goto error;
    }
    object = cx_declare(parent, (cx_string)name, type);
    cx_free(parent);
    cx_free(type);
finished:
    return object;
error:
    return NULL;
}

cx_bool json_deser_forward(void* p, cx_type t, JSON_Value* v) {
    cx_bool error = FALSE;
    switch (t->kind) {
        case CX_VOID:
            break;
        case CX_ANY:
            error = TRUE;
            cx_error("deserialization of JSON of \"any\" type not supported");
            break;
        case CX_PRIMITIVE:
            error = json_deserPrimitive(p, t, v);
            break;
        case CX_COMPOSITE:
            error = json_deserComposite(p, t, v);
            break;
        case CX_COLLECTION:
            break;
        case CX_ITERATOR:
            cx_error("deserialization of JSON of \"iterator\" type not supported");
            break;
    }
    return error;
}

cx_object cx_json_deser(cx_string s) {
    JSON_Object *jsonObject;
    JSON_Object *meta;
    JSON_Value *value;
    cx_object o = NULL;
    cx_id fullname;
    JSON_Value *jsonValue = json_parse_string(s);
    if (!jsonValue || json_value_get_type(jsonValue) != JSONObject) {
        cx_error("invalid top level JSON object");
        goto error;
    }
    jsonObject = json_value_get_object(jsonValue);
    meta = json_object_get_object(jsonObject, "meta");
    value = json_object_get_value(jsonObject, "value");
    if (!(meta && value)) {
        cx_error("did not find meta or value as objects");
        goto error;
    }
    if (!(o = cx_json_declare(meta))) {
        cx_error("cannot not declare object");
        goto error;
    }
    cx_fullname(o, fullname);
    if (json_deser_forward(o, cx_typeof(o), value)) {
        cx_error("cannot not set value of %s", fullname);
        goto error;
    }
    if (cx_define(o)) {
        cx_error("cannot not define %s", fullname);
        goto error;
    }
error:
    if (jsonValue) {
        json_value_free(jsonValue);
    }
    return o;
}
