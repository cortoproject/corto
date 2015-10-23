
#include "parson.h"

#include "corto.h"

#include "json_primitives.h"
#include "json_composites.h"

static corto_object corto_json_checkRoot(const char* parent, const char* name, const char* type) {
    corto_bool isRoot = !strcmp(parent, "");
    isRoot = isRoot && !strcmp(name, "::");
    isRoot = isRoot && !strcmp(type, corto_nameof(corto_typeof(root_o)));
    return isRoot ? root_o : NULL;
}

static corto_object corto_json_declare(JSON_Object *meta) {
    const char *parentName = json_object_get_string(meta, "parent");
    const char *name = json_object_get_string(meta, "name");
    const char *typeName = json_object_get_string(meta, "type");
    corto_object object, parent, type;
    object = parent = type = NULL;

    if (!(name && parentName && typeName)) {
        corto_error("meta does not have name, parent, or type");
        goto error;
    }
    if ((object = corto_json_checkRoot(parentName, name, typeName))) {
        goto finished;
    }
    parent = corto_resolve(NULL, (corto_string)parentName);
    if (!parent) {
        corto_error("parent %s could not be resolved", parentName);
        goto error;
    }
    type = corto_resolve(NULL, (corto_string)typeName);
    if (!type) {
        corto_release(parent);
        corto_error("type %s could not be resolved", typeName);
        goto error;
    }
    object = corto_declareChild(parent, (corto_string)name, type);
    corto_release(parent);
    corto_release(type);
finished:
    return object;
error:
    return NULL;
}

corto_bool json_deser_forward(void* p, corto_type t, JSON_Value* v) {
    corto_bool error = FALSE;
    switch (t->kind) {
        case CORTO_VOID:
            break;
        case CORTO_ANY:
            error = TRUE;
            corto_error("deserialization of JSON of \"any\" type not supported");
            break;
        case CORTO_PRIMITIVE:
            error = json_deserPrimitive(p, t, v);
            break;
        case CORTO_COMPOSITE:
            error = json_deserComposite(p, t, v);
            break;
        case CORTO_COLLECTION:
            break;
        case CORTO_ITERATOR:
            corto_error("deserialization of JSON of \"iterator\" type not supported");
            break;
    }
    return error;
}

corto_object corto_json_deser(corto_string s) {
    JSON_Object *jsonObject;
    JSON_Object *meta;
    JSON_Value *value;
    corto_object o = NULL;
    corto_id fullname;
    JSON_Value *jsonValue = json_parse_string(s);
    if (!jsonValue || json_value_get_type(jsonValue) != JSONObject) {
        corto_error("invalid top level JSON object");
        goto error;
    }
    jsonObject = json_value_get_object(jsonValue);
    meta = json_object_get_object(jsonObject, "meta");
    value = json_object_get_value(jsonObject, "value");
    if (!(meta && value)) {
        corto_error("did not find meta or value as objects");
        goto error;
    }
    if (!(o = corto_json_declare(meta))) {
        corto_error("cannot not declare object");
        goto error;
    }
    corto_fullname(o, fullname);
    if (json_deser_forward(o, corto_typeof(o), value)) {
        corto_error("cannot not set value of %s", fullname);
        goto error;
    }
    if (corto_define(o)) {
        corto_error("cannot not define %s", fullname);
        goto error;
    }
error:
    if (jsonValue) {
        json_value_free(jsonValue);
    }
    return o;
}
