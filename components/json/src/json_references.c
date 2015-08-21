
#include "json_references.h"

cx_bool json_deserReference(void* p, cx_type t, JSON_Value* v) {
    const char* reference = json_value_get_string(v);
    if (!reference) {
        cx_error("not deserializing JSON string");
        goto error;
    }
    cx_object o = cx_resolve(NULL, (cx_string)reference);
    if (!o) {
        cx_error("cannot find reference \"%s\"", reference);
        goto error;
    }
    if (!cx_instanceof(t, o)) {
        cx_error("%s is not an instance of %s", reference, cx_nameof(t));
    }
    *(cx_object *)p = o; // TODO does this require cx_setref?
    return FALSE;
error:
    return TRUE;
}
