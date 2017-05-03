/*
 * corto_string_ser.h
 *
 *  Created on: Aug 27, 2012
 *      Author: sander
 */

#ifndef CORTO_STRING_SER_H_
#define CORTO_STRING_SER_H_

#ifdef __cplusplus
extern "C" {
#endif

/* String serializer data */
typedef struct corto_string_ser_t {
    /* Public */
    corto_buffer buffer;
    corto_bool prefixType;
    corto_bool enableColors;

    /* Private */
    char* ptr;
    unsigned int itemCount;
    corto_bool compactNotation;
    corto_ll anonymousObjects;
} corto_string_ser_t;

CORTO_EXPORT corto_walk_opt corto_string_ser(corto_modifier access, corto_operatorKind accessKind, corto_walk_traceKind trace);

#ifdef __cplusplus
}
#endif

#endif /* CORTO_STRING_SER_H_ */
