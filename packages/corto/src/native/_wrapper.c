/* _wrapper.c
 *
 * This file contains wrapper functions for /corto/native.
 */

#include "corto/native/native.h"
#include "corto/native/_meta.h"

void __corto_native_type_init(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    *(corto_int16*)result = _corto_native_type_init(
        corto_native_type(*(void**)args));
}
