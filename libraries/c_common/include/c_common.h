/*
 * c_common.h
 *
 *  Created on: Dec 21, 2012
 *      Author: sander
 */

#ifndef C_COMMON_H_
#define C_COMMON_H_

#include "corto.h"
#include "cx_generator.h"

#ifdef __cplusplus
extern "c" {
#endif

/* Translate id to C-id */
cx_string corto_genId(cx_string str, cx_id id);

/* Return string with C type for primitive */
cx_char* c_primitiveId(cx_primitive t, cx_char* buff);

/* Parse type into C-specifier */
cx_int16 c_specifierId(cx_generator g, cx_type t, cx_char* specifier, cx_bool* prefix, cx_char* postfix);

/* Translate constant to C-language id */
cx_char* c_constantId(cx_generator g, cx_constant* c, cx_char* buffer);

/* Translate string to c-compatible string (do escaping of ") */
cx_char* c_escapeString(cx_string str, cx_id id);

cx_bool c_procedureHasThis(cx_function o);

cx_char* c_topath(cx_object o, cx_id id, cx_char separator);

cx_string c_paramName(cx_string name, cx_string buffer);

#ifdef __cplusplus
}
#endif

#endif /* C_COMMON_H_ */
