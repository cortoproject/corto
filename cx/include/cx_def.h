/*
 * cx_def.h
 *
 *  Created on: Aug 2, 2012
 *      Author: sander
 */

#ifndef CX_DEF_H_
#define CX_DEF_H_

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

#define CX_NULL_STRING ("null")

typedef int (*cx_compareAction)(void* o1, void* o2);
typedef int (*cx_walkAction)(void* o, void* userData);

/* Builtin collection-implementation definitions */
typedef struct cx_rbtree_s* cx_rbtree;
typedef struct cx_ll_s* cx_ll;

/* Configuration parameters */
#define CX_MAX_SCOPE_DEPTH (256)
#define CX_MAX_TYPE_DEPTH (32)
#define CX_MAX_INHERITANCE_DEPTH (32)
#define CX_MAX_BINDINGS (256)
#define CX_MAX_THREADS (512)
#define CX_MAX_NOTIFY_DEPTH (32)
#define CX_MAX_STRING_LITERAL_LENGTH (512)
#define CX_MAX_WAIT_FOR_OBJECTS (256)

/* #define CX_TRACE_NOTIFICATIONS */
/* #define CX_SERIALIZER_TRACING */
#define CX_IC_TRACING
#define CX_VM_DEBUG
#define CX_VM
#define CX_API
#define CX_GENERATOR
#define CX_CONVERSIONS
#define CX_OPERATORS
#define CX_LOADER
#define CX_VM_BOUNDSCHECK

#define CX_PROCEDURE_STUB (0)
#define CX_PROCEDURE_CDECL (1)
#define CX_PROCEDURE_VM    (2)

/* C language binding type definition macro's */
#define CX_ANY(__type) typedef struct __type {cx_type type; void *value; cx_bool owner;} __type
#define CX_ITERATOR(__type) typedef struct __type {\
    void *current;\
    cx_collection type;\
    cx_bool (*next)(void* iterator);\
    union {\
        struct { /* CX_ARRAY and CX_SEQUENCE */\
            void *array;\
            int32_t elementSize;\
            void* max;\
        } array;\
        struct {\
        	cx_iter iter;\
        } ll;\
    } is;\
} __type
#define CX_BITMASK(type) typedef uint32_t type

#define CX_STRUCT(type) typedef struct type type
#define CX_INTERFACE(type) typedef void *type
#define CX_CLASS(type) typedef struct type##_s *type
#define CX_PROCEDURE(type) typedef struct type##_s* type

#define CX_STRUCT_DEF(type) struct type
#define CX_CLASS_DEF(type) struct type##_s
#define CX_PROCEDURE_DEF(type) struct type##_s
#define CX_EXTEND(type) struct type##_s _parent

#define _(txt) /* This macro prevents expansion of type-casting macro's */
#define CX_SEQUENCE(type, subtype, postexpr) typedef struct type {uint32_t length; subtype _()(*buffer) postexpr;} type
#define CX_SEQUENCE_ANONYMOUS(subtype, postexpr) struct {uint32_t length; subtype _()(*buffer) postexpr;}
#define CX_LIST(type) typedef cx_ll type

#define CX_OBSERVER_DEF(name)\
    void name(cx_object, cx_object, cx_object);\
    void __##name(cx_function f, void *result, void *args) {\
        CX_UNUSED(f);\
        CX_UNUSED(result);\
        name(\
            *(void**)args,\
            *(void**)((intptr_t)args + sizeof(void*)),\
            *(void**)((intptr_t)args + sizeof(void*) + sizeof(void*)));\
    }\
    void name

#define CX_OBSERVER_SET_CALLBACK(observer, func)\
    cx_function(observer)->impl = (cx_word)__##func;

#ifdef __cplusplus
}
#endif

#endif /* CX_DEF_H_ */
