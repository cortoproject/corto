/*
 * c_common.h
 *
 *  Created on: Dec 21, 2012
 *      Author: sander
 */

#ifndef C_COMMON_H_
#define C_COMMON_H_

#include "cortex.h"
#include "db_generator.h"

#ifdef __cplusplus
extern "c" {
#endif

/* Translate id to C-id */
db_string cortex_genId(db_string str, db_id id);

/* Return string with C type for primitive */
db_char* c_primitiveId(db_primitive t, db_char* buff);

/* Parse type into C-specifier */
db_int16 c_specifierId(db_generator g, db_typedef t, db_char* specifier, db_bool* prefix, db_char* postfix);

/* Translate constant to C-language id */
db_char* c_constantId(db_generator g, db_constant* c, db_char* buffer);

/* Translate string to c-compatible string (do escaping of ") */
db_char* c_escapeString(db_string str, db_id id);

db_bool c_procedureHasThis(db_function o);

db_char* c_topath(db_object o, db_id id);

#ifdef __cplusplus
}
#endif

#endif /* C_COMMON_H_ */
