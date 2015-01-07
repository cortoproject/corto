/*
 * cx_string_deser.h
 *
 *  Created on: Sep 6, 2012
 *      Author: sander
 */

#ifndef CX_STRING_DESER_H_
#define CX_STRING_DESER_H_

#include "cx__type.h"
#include "cx_ll.h"

#ifdef __cplusplus
extern "C" {
#endif

#define CX_STRING_DESER_TOKEN_MAX (1024) /* Specifies the maximum length for a token */

struct cx_indexInfo;

/* Deserializer data */
typedef struct cx_string_deser_t {
    /* Public */
    void *out;
    cx_object scope;
    cx_type type;

    /* Private */
    cx_iter currentIter;
    cx_uint32 current;
    cx_ll index;
    cx_void* ptr;
    cx_ll anonymousObjects;
}cx_string_deser_t;

/* Deserialize string */
cx_string cx_string_deser(cx_string str, cx_string_deser_t* data);

#ifdef __cplusplus
}
#endif

#endif /* CX_STRING_DESER_H_ */
