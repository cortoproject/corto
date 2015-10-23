/*
 * c_common.h
 *
 *  Created on: Dec 21, 2012
 *      Author: sander
 */

#ifndef C_COMMON_H_
#define C_COMMON_H_

#include "corto.h"
#include "corto_generator.h"

#ifdef __cplusplus
extern "c" {
#endif

/* Translate id to C-id */
corto_string corto_genId(corto_string str, corto_id id);

/* Return string with C type for primitive */
corto_char* c_primitiveId(corto_primitive t, corto_char* buff);

/* Parse type into C-specifier */
corto_int16 c_specifierId(corto_generator g, corto_type t, corto_char* specifier, corto_bool* prefix, corto_char* postfix);

/* Translate constant to C-language id */
corto_char* c_constantId(corto_generator g, corto_constant* c, corto_char* buffer);

/* Translate string to c-compatible string (do escaping of ") */
corto_char* c_escapeString(corto_string str, corto_id id);

corto_bool c_procedureHasThis(corto_function o);

corto_char* c_topath(corto_object o, corto_id id, corto_char separator);

corto_string c_paramName(corto_string name, corto_string buffer);

corto_char* c_usingName(corto_generator g, corto_object o, corto_id id);

corto_char* c_usingConstant(corto_generator g, corto_id id);

void c_writeExport(corto_generator g, g_file file);

#ifdef __cplusplus
}
#endif

#endif /* C_COMMON_H_ */
