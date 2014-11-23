/*
 * db_string_deser.h
 *
 *  Created on: Sep 6, 2012
 *      Author: sander
 */

#ifndef DB_STRING_DESER_H_
#define DB_STRING_DESER_H_

#include "db__type.h"
#include "db_ll.h"

#ifdef __cplusplus
extern "C" {
#endif

#define DB_STRING_DESER_TOKEN_MAX (1024) /* Specifies the maximum length for a token */

struct db_indexInfo;

/* Deserializer data */
typedef struct db_string_deser_t {
    /* Public */
    void *out;
    db_object scope;
    db_type type;

    /* Private */
    db_iter currentIter;
    db_uint32 current;
    db_ll index;
    db_void* ptr;
    db_ll anonymousObjects;
}db_string_deser_t;

/* Deserialize string */
db_string db_string_deser(db_string str, db_string_deser_t* data);

#ifdef __cplusplus
}
#endif

#endif /* DB_STRING_DESER_H_ */
