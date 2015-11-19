#include "corto.h"

corto_object cxstr_define(corto_object result, corto_string value) {

    if (corto_typeof(result)->kind != CORTO_VOID) {
        corto_fromStr(&result, value);
    }

    if (corto_define(result)) {
        goto error;
    }
    
    return result; 
error:
    corto_delete(result);
    return NULL;
}

corto_object cxstr_create(corto_string type, corto_string value) {
    corto_object result = cxstr_declare(type);
    if (!result) {
        goto error;
    }
	return cxstr_define(result, value);
error:
    return NULL;
}

corto_object cxstr_createChild(corto_string parent, corto_string name, corto_string type, corto_string value) {
    corto_object result = cxstr_declareChild(parent, name, type);
    if (!result) {
        goto error;
    }
    return cxstr_define(result, value);
error:
    return NULL;
}

corto_object cxstr_declare(corto_string type) {
    corto_object result, typeObject;

    if (!(typeObject = corto_resolve(NULL, type))) {
        corto_error("type '%s' not found", type);
        goto error;
    }

    if (!(result = corto_declare(typeObject))) {
        corto_error("failed to declare object of type '%s'", type);
        goto error_declare;
    }

    corto_release(typeObject);

    return result;
error_declare:
    corto_release(typeObject);
error:
    return NULL;
}

corto_object cxstr_declareChild(corto_string parent, corto_string name, corto_string type) {
    corto_object result, typeObject, parentObject;

    if (!(typeObject = corto_resolve(NULL, type))) {
        corto_error("type '%s' not found", type);
        goto error;
    }

    if (!parent) {
        parent = "::";
    }
    if (!(parentObject = corto_resolve(NULL, parent))) {
        corto_error("parent '%s' not found", parent);
        goto error_parent;
    }

    if (!(result = corto_declareChild(parentObject, name, typeObject))) {
        corto_error("failed to declare object of type '%s'", type);
        goto error_declare;
    }

    corto_release(typeObject);
    corto_release(parentObject);

    return result;
error_declare:
    corto_release(parentObject);
error_parent:
    corto_release(typeObject);
error:
    return NULL;
}

void cxstr_update(corto_object o, corto_string value) {
    corto_updateBegin(o);
    corto_fromStr(&o, value);
    corto_updateEnd(o);
}
