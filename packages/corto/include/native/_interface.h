/* _interface.h
 *
 * This file contains generated package function and method declarations.
 * You should not manually modify the contents of this file.
 */

#ifndef CORTO_NATIVE_INTERFACE_H
#define CORTO_NATIVE_INTERFACE_H

#include <corto/_project.h>

#ifdef __cplusplus
extern "C" {
#endif

/* forward declaration of the function. the '_' in front of the name allows
 * insertion of type-safe casts */
CORTO_EXPORT
int16_t _corto_native_type_init(
    corto_native_type _this);

/* implicit type-safe macro (not available for project implementation) */
#ifndef BUILDING_CORTO
#define corto_native_type_init(_this) _corto_native_type_init(corto_native_type(_this))
#else
#define corto_native_type_init _corto_native_type_init
#endif

/* explicit type-safe macro */
#define safe_corto_native_type_init(_this) _corto_native_type_init(corto_native_type(_this))

#ifdef __cplusplus
}
#endif

#endif

