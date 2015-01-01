/*
 * cx_copy_ser.h
 *
 *  Created on: Sep 20, 2014
 *      Author: sander
 */

#ifndef CX_COPY_SER_H_
#define CX_COPY_SER_H_

#include "cx_serializer.h"

#ifdef __cplusplus
extern "C" {
#endif
    
    /* String serializer data */
    typedef struct cx_copy_ser_t {
        cx_value value;
        
        /* Private members */
        void *base;
    }cx_copy_ser_t;
    
    struct cx_serializer_s cx_copy_ser(cx_modifier access, cx_operatorKind accessKind, cx_serializerTraceKind trace);
    
#ifdef __cplusplus
}
#endif

#endif /* CX_COPY_SER_H_ */
