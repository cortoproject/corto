/*
 * cx_compare_ser.h
 *
 *  Created on: Aug 27, 2012
 *      Author: sander
 */

#ifndef DB_COMPARE_SER_H_
#define DB_COMPARE_SER_H_

#include "cx_serializer.h"

#ifdef __cplusplus
extern "C" {
#endif
    
/* String serializer data */
typedef struct cx_compare_ser_t {
    cx_equalityKind equals;
    cx_value value;
    cx_equalityKind result;
    
    /* Private members */
    void *base;
}cx_compare_ser_t;

struct cx_serializer_s cx_compare_ser(cx_modifier access, cx_operatorKind accessKind, cx_serializerTraceKind trace);
    
#ifdef __cplusplus
}
#endif

#endif /* DB_COMPARE_SER_H_ */
