/*
 * c_common.h
 *
 *  Created on: Dec 21, 2012
 *      Author: sander
 */

#ifndef C_COMMON_H_
#define C_COMMON_H_

#include "cortex.h"
#include "cx_generator.h"

#ifdef __cplusplus
extern "c" {
#endif

/* Translate id to C-id */
cx_string cortex_genId(cx_string str, cx_id id);

/* Return string with C type for primitive */
cx_char* cpp_primitiveId(cx_primitive t, cx_char* buff);

/* Parse type into C-specifier */
cx_char* cpp_specifierId(cx_generator g, cx_typedef t, cx_char* specifier);
cx_char* cpp_specifierDecl(cx_generator g, cx_typedef t, cx_char* specifier);

/* Translate constant to C-language id */
cx_char* cpp_constantId(cx_generator g, cx_constant* c, cx_char* buffer);

/* Open a scope */
void cpp_openScope(g_file file, cx_object o);
void cpp_closeScope(g_file file);

/* Translate a scope to a path */
cx_char* cpp_topath(cx_object o, cx_id id);

typedef enum cpp_metaIdKind {
	CPP_DEFAULT,
	CPP_HANDLE,
	CPP_OBJECT
}cpp_metaIdKind;

/* Get meta-object identifier */
cx_char* cpp_metaFullname(cx_generator g, cx_object o, cpp_metaIdKind kind, cx_id id);

/* Get meta-object identifier */
cx_char* cpp_metaName(cx_generator g, cx_object o, cpp_metaIdKind kind, cx_id id);

/* Get procedure id (without parameterlist */
cx_char* cpp_procId(cx_generator g, cx_function o, cx_id id);

#ifdef __cplusplus
}
#endif

#endif /* C_COMMON_H_ */
