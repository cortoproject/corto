/* _type.h
 *
 * This file contains generated C type definitions.
 * You should not manually modify the contents of this file.
 */

#ifndef CORTO_SECURE__TYPE_H
#define CORTO_SECURE__TYPE_H

#include <corto/lang/_type.h>
#ifdef __cplusplus
extern "C" {
#endif

/* Casting macro's */
#define corto_secure_accessKind(o) ((corto_secure_accessKind*)corto_assert_type((corto_type)corto_secure_accessKind_o, o))
#define corto_secure_actionKind(o) ((corto_secure_actionKind*)corto_assert_type((corto_type)corto_secure_actionKind_o, o))
#define corto_secure_key(o) ((corto_secure_key)corto_assert_type((corto_type)corto_secure_key_o, o))
#define corto_secure_lock(o) ((corto_secure_lock)corto_assert_type((corto_type)corto_secure_lock_o, o))

/* Native types */
#ifndef CORTO_SECURE_H
#endif

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
typedef struct corto_secure_key_s *corto_secure_key;

struct corto_secure_key_s {
    int8_t __dummy;
};

/*  /corto/secure/lock */
typedef struct corto_secure_lock_s *corto_secure_lock;

struct corto_secure_lock_s {
    corto_string mount;
    corto_string expr;
    int16_t priority;
};

#ifdef __cplusplus
}
#endif
#endif

