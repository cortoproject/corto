
#include "cortex.h"

cx_object cxstr_define(cx_object result, cx_string value) {

    cx_fromStr(&result, value);

    if (cx_define(result)) {
        goto error;
    }
    
    return result; 
error:
    cx_delete(result);
    return NULL;
}

cx_object cxstr_create(cx_string type, cx_string value) {
    cx_object result = cxstr_declare(type);
    if (!result) {
        goto error;
    }
	return cxstr_define(result, value);
error:
    return NULL;
}

cx_object cxstr_createChild(cx_string parent, cx_string name, cx_string type, cx_string value) {
    cx_object result = cxstr_declareChild(parent, name, type);
    if (!result) {
        goto error;
    }
    return cxstr_define(result, value);
error:
    return NULL;
}

cx_object cxstr_declare(cx_string type) {
    cx_object result, typeObject;

    if (!(typeObject = cx_resolve(NULL, type))) {
        cx_error("type '%s' not found", type);
        goto error;
    }

    if (!(result = cx_declare(typeObject))) {
        cx_error("failed to declare object of type '%s'", type);
        goto error_declare;
    }

    cx_release(typeObject);

    return result;
error_declare:
    cx_release(typeObject);
error:
    return NULL;
}

cx_object cxstr_declareChild(cx_string parent, cx_string name, cx_string type) {
    cx_object result, typeObject, parentObject;

    if (!(typeObject = cx_resolve(NULL, type))) {
        cx_error("type '%s' not found", type);
        goto error;
    }

    if (!parent) {
        parent = "::";
    }
    if (!(parentObject = cx_resolve(NULL, parent))) {
        cx_error("parent '%s' not found", parent);
        goto error_parent;
    }

    if (!(result = cx_declareChild(parentObject, name, typeObject))) {
        cx_error("failed to declare object of type '%s'", type);
        goto error_declare;
    }

    cx_release(typeObject);
    cx_release(parentObject);

    return result;
error_declare:
    cx_release(parentObject);
error_parent:
    cx_release(typeObject);
error:
    return NULL;
}

void cxstr_update(cx_object o, cx_string value) {
    cx_updateBegin(o);
    cx_fromStr(&o, value);
    cx_updateEnd(o);
}
