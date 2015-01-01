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
db_char* cpp_primitiveId(db_primitive t, db_char* buff);

/* Parse type into C-specifier */
db_char* cpp_specifierId(db_generator g, db_typedef t, db_char* specifier);
db_char* cpp_specifierDecl(db_generator g, db_typedef t, db_char* specifier);

/* Translate constant to C-language id */
db_char* cpp_constantId(db_generator g, db_constant* c, db_char* buffer);

/* Open a scope */
void cpp_openScope(g_file file, db_object o);
void cpp_closeScope(g_file file);

/* Translate a scope to a path */
db_char* cpp_topath(db_object o, db_id id);

typedef enum cpp_metaIdKind {
	CPP_DEFAULT,
	CPP_HANDLE,
	CPP_OBJECT
}cpp_metaIdKind;

/* Get meta-object identifier */
db_char* cpp_metaFullname(db_generator g, db_object o, cpp_metaIdKind kind, db_id id);

/* Get meta-object identifier */
db_char* cpp_metaName(db_generator g, db_object o, cpp_metaIdKind kind, db_id id);

/* Get procedure id (without parameterlist */
db_char* cpp_procId(db_generator g, db_function o, db_id id);

#ifdef __cplusplus
}
#endif

#endif /* C_COMMON_H_ */
