/*
 * corto_load.h
 *
 *  Created on: Aug 6, 2012
 *      Author: sander
 */

#ifndef CORTO_NATIVE_META_H_
#define CORTO_NATIVE_META_H_

#include "corto/lang/_type.h"
#include "corto/core/_type.h"

#ifdef __cplusplus
extern "C" {
#endif

#define CORTO_META_NATIVE_OBJECT(type, name) CORTO_EXPORT extern corto_##type corto_native_##name##_o

CORTO_EXPORT extern corto_package corto_native_o;

/* Forward declarations of classes */
CORTO_META_NATIVE_OBJECT(class, type);

#ifdef __cplusplus
}
#endif

#endif /* CORTO_NATIVE_META_H_ */
