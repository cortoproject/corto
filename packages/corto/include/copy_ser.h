/*
 * corto_copy_ser.h
 *
 *  Created on: Sep 20, 2014
 *      Author: sander
 */

#ifndef CORTO_COPY_SER_H_
#define CORTO_COPY_SER_H_

#include "corto/serializer.h"

#ifdef __cplusplus
extern "C" {
#endif

    /* String serializer data */
    typedef struct corto_copy_ser_t {
        corto_value value;

        /* Private members */
        void *base;
    }corto_copy_ser_t;

    struct corto_serializer_s corto_copy_ser(corto_modifier access, corto_operatorKind accessKind, corto_serializerTraceKind trace);

#ifdef __cplusplus
}
#endif

#endif /* CORTO_COPY_SER_H_ */
