/* _type.h
 *
 * Type definitions for C-language.
 * This file contains generated code. Do not modify!
 */

#ifndef CORTO_SECURE__TYPE_H
#define CORTO_SECURE__TYPE_H

#include <corto/lang/_type.h>
#ifdef __cplusplus
extern "C" {
#endif

/* Casting macro's */
#define corto_secure_accessKind(o) ((corto_secure_accessKind*)corto_assertType((corto_type)corto_secure_accessKind_o, o))
#define corto_secure_actionKind(o) ((corto_secure_actionKind*)corto_assertType((corto_type)corto_secure_actionKind_o, o))
#define corto_secure_key(o) ((corto_secure_key)corto_assertType((corto_type)corto_secure_key_o, o))
#define corto_secure_lock(o) ((corto_secure_lock)corto_assertType((corto_type)corto_secure_lock_o, o))

/* Type definitions */
/* /corto/secure/accessKind */
typedef enum corto_secure_accessKind {
    CORTO_SECURE_ACCESS_GRANTED = 0,
    CORTO_SECURE_ACCESS_DENIED = 1,
    CORTO_SECURE_ACCESS_UNDEFINED = 2
} corto_secure_accessKind;

/* /corto/secure/actionKind */
typedef enum corto_secure_actionKind {
    CORTO_SECURE_ACTION_CREATE = 0,
    CORTO_SECURE_ACTION_READ = 1,
    CORTO_SECURE_ACTION_UPDATE = 2,
    CORTO_SECURE_ACTION_DELETE = 3
} corto_secure_actionKind;

/*  /corto/secure/key */
CORTO_CLASS(corto_secure_key);

CORTO_CLASS_DEF(corto_secure_key) {
    corto_int8 __dummy;
};

/*  /corto/secure/lock */
CORTO_CLASS(corto_secure_lock);

CORTO_CLASS_DEF(corto_secure_lock) {
    corto_string mount;
    corto_string expr;
    corto_int16 priority;
};

#ifdef __cplusplus
}
#endif
#endif

