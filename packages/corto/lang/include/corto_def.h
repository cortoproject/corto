/*
 * corto_def.h
 *
 *  Created on: Aug 2, 2012
 *      Author: sander
 */

#ifndef CORTO_DEF_H_
#define CORTO_DEF_H_

#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <alloca.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef NULL
#define NULL (0x0)
#endif

#ifndef FALSE
#define FALSE (0)
#endif

#ifndef TRUE
#define TRUE (!FALSE)
#endif

/* Macro used to prevent type checking macro's from expanding */
#define ___

#define CORTO_NULL_STRING ("null")

extern const char* CORTO_VERSION;
extern const char* CORTO_VERSION_MAJOR;
extern const char* CORTO_VERSION_MINOR;
extern const char* CORTO_VERSION_PATCH;
extern const char* CORTO_VERSION_SUFFIX;

typedef int (*corto_compareAction)(void* o1, void* o2);
typedef int (*corto_walkAction)(void* o, void* userData);

/* Builtin collection-implementation definitions */
typedef struct corto_rbtree_s* corto_rbtree;
typedef struct corto_ll_s* corto_ll;

/*
 * Configuration parameters
 *   Increasing these numbers will increase memory usage of Corto in various
 *   scenario's.
 */

/* The maximum nesting level of objects in the hierarchy. There are in total
 * 62 orders of magnitude in the universe, so 64 should be adequate to organize
 * most information sets.
 */
#define CORTO_MAX_SCOPE_DEPTH (64)

/* The maximum inheritance depth. Think 16 is too small? The Java world record
 * is set at 12 levels of inheritance:
 * http://www.javaspecialists.eu/records/index.jsp
 *
 * Please don't use 16 levels of inheritance.
 */
#define CORTO_MAX_INHERITANCE_DEPTH (16)

/* The maximum number of languages you can bind to a single Corto process. */
#define CORTO_MAX_BINDINGS (16)

/* The maximum number of threads that can make use of the Corto API. */
#define CORTO_MAX_THREADS (64)

/* The maximum number of nested notifications. */
#define CORTO_MAX_NOTIFY_DEPTH (16)

/* The max length of a scoped identifier (incl \0). When combining this with the
 * MAX_SCOPE_DEPTH, and taking into consideration the scope separator (/) you
 * can have a tree that is 64 levels deep, where each object has a 7-character
 * name, and one object with 6, to compensate for \0. Or, you can have an object
 * in the root with a 510 character name with no children. */
#define CORTO_MAX_PATH_LENGTH (512)

/* The maximum number of objects that a thread can wait for simultaneously */
#define CORTO_MAX_WAIT_FOR_OBJECTS (32)

/* Corto can't load files with extensions longer than 16 characters */
#define CORTO_MAX_FILE_EXTENSION (16)

/* Maximum number of OLS extensions that is supported by the core */
#define CORTO_MAX_OLS_KEY (256)

/* The maximum number of arguments that can be passed to the Corto arg parser */
#define CORTO_ARG_MAX (256)

/* The maximum number of TLS strings that can exist simultaneously */
#define CORTO_MAX_TLS_STRINGS (5)

/* Maximum retained buffer length for TLS string. This ensures that when a very
 * large string is stored in TLS, it will be cleaned up eventually. Keeping it
 * around would be wasteful since chances are low that a string of similar
 * length will take advantage of the memory. */
#define CORTO_MAX_TLS_STRINGS_MAX (1024)

/* #define CORTO_TRACE_NOTIFICATIONS */
/* #define CORTO_SERIALIZER_TRACING */
#define CORTO_IC_TRACING
#define CORTO_VM_DEBUG
#define CORTO_VM
#define CORTO_API
#define CORTO_GENERATOR
#define CORTO_CONVERSIONS
#define CORTO_OPERATORS
#define CORTO_LOADER
#define CORTO_VM_BOUNDSCHECK
extern int8_t CORTO_DEBUG_ENABLED;

#define CORTO_PROCEDURE_STUB (0)
#define CORTO_PROCEDURE_CDECL (1)

/* C language binding type definition macro's */
#define CORTO_ANY(__type) typedef struct __type {corto_type type; void *value; uint8_t owner;} __type
#define CORTO_ITERATOR(__type) typedef struct __type {\
    void *current;\
    corto_collection type;\
    corto_bool ___ (*next)(void* iterator);\
    union {\
        struct { /* CORTO_ARRAY and CORTO_SEQUENCE */\
            void *array;\
            int32_t elementSize;\
            void* max;\
        } array;\
        struct {\
        	corto_iter iter;\
        } ll;\
    } is;\
} __type
#define CORTO_BITMASK(type) typedef uint32_t type

#define CORTO_STRUCT(type) typedef struct type type
#define CORTO_INTERFACE(type) typedef void *type
#define CORTO_CLASS(type) typedef struct type##_s *type
#define CORTO_PROCEDURE(type) typedef struct type##_s* type

#define CORTO_STRUCT_DEF(type) struct type
#define CORTO_CLASS_DEF(type) struct type##_s
#define CORTO_PROCEDURE_DEF(type) struct type##_s
#define CORTO_EXTEND(type) struct type##_s _base

#define _(txt) /* This macro prevents expansion of type-casting macro's */
#define CORTO_SEQUENCE(type, subtype, postexpr) typedef struct type {uint32_t length; subtype _()(*buffer) postexpr;} type
#define CORTO_SEQUENCE_ANONYMOUS(subtype, postexpr) struct {uint32_t length; subtype _()(*buffer) postexpr;}
#define CORTO_SEQUENCE_EMPTY(name) (name){0, NULL}
#define CORTO_LIST(type) typedef corto_ll type

#define CORTO_OBSERVER(name)\
    void __##name (corto_object, corto_object);\
    void name (corto_function f, void *result, void *args) {\
        CORTO_UNUSED(f);\
        CORTO_UNUSED(result);\
        __##name (\
            *(void**)args,\
            *(void**)((intptr_t)args + sizeof(void*)));\
    }\
    void __##name (corto_object this, corto_object observable)

#ifdef __cplusplus
}
#endif

#endif /* CORTO_DEF_H_ */
