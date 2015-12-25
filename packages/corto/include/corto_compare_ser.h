/*
 * corto_compare_ser.h
 *
 *  Created on: Aug 27, 2012
 *      Author: sander
 */

#ifndef CORTO_COMPARE_SER_H_
#define CORTO_COMPARE_SER_H_

#include "corto/corto_serializer.h"

#ifdef __cplusplus
extern "C" {
#endif

/* String serializer data */
typedef struct corto_compare_ser_t {
    corto_equalityKind equals;
    corto_value value;
    corto_equalityKind result;

    /* Private members */
    void *base;
}corto_compare_ser_t;

struct corto_serializer_s corto_compare_ser(corto_modifier access, corto_operatorKind accessKind, corto_serializerTraceKind trace);

#ifdef __cplusplus
}
#endif

#endif /* CORTO_COMPARE_SER_H_ */
