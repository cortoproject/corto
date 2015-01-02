/* cx_function.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef cx_function_H
#define cx_function_H

#include "cortex.h"
#include "cx__type.h"

#include "cx__api.h"

#include "cx__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* callback ::cortex::lang::procedure::bind(lang::object object) -> ::cortex::lang::function::bind(lang::function object) */
cx_int16 cx_function_bind(cx_function object);

/* callback ::cortex::lang::type::init(lang::object object) -> ::cortex::lang::function::init(lang::function object) */
cx_int16 cx_function_init(cx_function object);

/* ::cortex::lang::function::stringToParameterSeq(lang::string name,lang::object scope) */
cx_parameterSeq cx_function_stringToParameterSeq(cx_string name, cx_object scope);

/* ::cortex::lang::function::unbind(lang::function object) */
cx_void cx_function_unbind(cx_function object);

#ifdef __cplusplus
}
#endif
#endif

