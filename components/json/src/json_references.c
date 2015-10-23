
#include "json_references.h"

corto_bool json_deserReference(void* p, corto_type t, JSON_Value* v) {
    const char* reference = json_value_get_string(v);
    if (!reference) {
        corto_error("not deserializing JSON string");
        goto error;
    }
    corto_object o = corto_resolve(NULL, (corto_string)reference);
    if (!o) {
        corto_error("cannot find reference \"%s\"", reference);
        goto error;
    }
    if (!corto_instanceof(t, o)) {
        corto_error("%s is not an instance of %s", reference, corto_nameof(t));
    }
    *(corto_object *)p = o; // TODO does this require corto_setref?
    return FALSE;
error:
    return TRUE;
}
