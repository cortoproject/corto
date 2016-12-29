/*
 * corto_load.h
 *
 *  Created on: Aug 6, 2012
 *      Author: sander
 */

#ifndef CORTO_SECURE_META_H_
#define CORTO_SECURE_META_H_

#include "corto/lang/_type.h"
#include "corto/core/_type.h"

#ifdef __cplusplus
extern "C" {
#endif

#define CORTO_META_SECURE_OBJECT(type, name) CORTO_EXPORT extern corto_##type corto_secure_##name##_o

CORTO_EXPORT extern corto_package corto_secure_o;

CORTO_META_SECURE_OBJECT(class, key);
CORTO_META_SECURE_OBJECT(class, lock);
CORTO_META_SECURE_OBJECT(enum, accessKind);
CORTO_META_SECURE_OBJECT(enum, actionKind);

#ifdef __cplusplus
}
#endif

#endif /* CORTO_NATIVE_META_H_ */
