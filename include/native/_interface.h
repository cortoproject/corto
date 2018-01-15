/* _interface.h
 *
 * This file contains generated package function and method declarations.
 * You should not manually modify the contents of this file.
 */

#ifndef CORTO_NATIVE_INTERFACE_H
#define CORTO_NATIVE_INTERFACE_H

#include <corto/_project.h>

#include <corto/native/_type.h>
#include <corto/native/_interface.h>
#include <corto/native/_load.h>

#ifdef __cplusplus
extern "C" {
#endif

/* -- Procudure declarations -- */


/* class corto/native/type */

CORTO_EXPORT
int16_t _corto_native_type_init(
    corto_native_type _this);

/* -- Support macro's -- */
#ifndef BUILDING_CORTO
#define corto_native_type_init(_this) _corto_native_type_init(corto_native_type(_this))
#else
#define corto_native_type_init _corto_native_type_init
#ifndef __cplusplus
#endif
#endif
#define safe_corto_native_type_init(_this) _corto_native_type_init(corto_native_type(_this))

#ifdef __cplusplus
}
#endif

#endif

