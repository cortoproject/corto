
#include "parson.h"

#include "cortex.h"
#include "json_primitives.h"

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
    parent = cx_resolve(NULL, (cx_string)parentName);
    if (!parent) {
        cx_error("parent %s could not be resolved", parentName);
        goto error;
    }
    type = cx_resolve(NULL, (cx_string)typeName);
    if (!type) {
        cx_error("type %s could not be resolved", typeName);
    }
    object = cx_declare(parent, (cx_string)name, type);
    return object;
error:
    return NULL;
}

static void cx_json_define_primitive(cx_object o, JSON_Value *value) {
    cx_assert(cx_typeof(o)->kind == CX_PRIMITIVE, "not serializing a primitive");
    switch (cx_primitive(cx_typeof(o))->kind) {
        case CX_BINARY:
            break;
        case CX_BOOLEAN:
            break;
        case CX_CHARACTER:
            break;
        case CX_INTEGER:
        case CX_UINTEGER:
        case CX_FLOAT:
            json_deserNumber(o, value);
            break;
        case CX_TEXT:
            json_deserText(o, value);
            break;
        case CX_ENUM:
            break;
        case CX_BITMASK:
            break;
        case CX_ALIAS:
            cx_critical("alias type not supported");
            break;
    }
}

static void cx_json_define_composite(cx_object o, JSON_Value *value) {
    cx_assert(cx_typeof(o)->kind == CX_COMPOSITE, "not serializing a composite");
    CX_UNUSED(value);
}

static void cx_json_define_collection(cx_object o, JSON_Value *value) {
    cx_assert(cx_typeof(o)->kind == CX_COLLECTION, "not serializing a collection");
    CX_UNUSED(value);
}


static void cx_json_define(cx_object o, JSON_Value *value) {
    switch (cx_typeof(o)->kind) {
        case CX_VOID:
            break;
        case CX_ANY:
            cx_error("deserialization of JSON of \"any\" type not supported");
            break;
        case CX_PRIMITIVE:
            cx_json_define_primitive(o, value);
            break;
        case CX_COMPOSITE:
            cx_json_define_composite(o, value);
            break;
        case CX_COLLECTION:
            cx_json_define_collection(o, value);
            break;
        case CX_ITERATOR:
            cx_error("deserialization of JSON of \"iterator\" type not supported");
            break;
    }
}

cx_object cx_json_deser(cx_string s) {
    JSON_Value *jsonValue = json_parse_string(s);
    JSON_Object *jsonObject;
    JSON_Object *meta;
    JSON_Value *value;
    cx_object o = NULL;

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

    o = cx_json_declare(meta);
    cx_json_define(o, value);

error:
    json_value_free(jsonValue);
    return o;
}
