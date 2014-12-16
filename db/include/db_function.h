/* db_function.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef db_function_H
#define db_function_H

#include "hyve.h"
#include "db__type.h"

#include "db__api.h"

#include "db__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* callback ::hyve::lang::procedure::bind(lang::object object) -> ::hyve::lang::function::bind(lang::function object) */
db_int16 db_function_bind(db_function object);

/* callback ::hyve::lang::type::init(lang::object object) -> ::hyve::lang::function::init(lang::function object) */
db_int16 db_function_init(db_function object);

/* ::hyve::lang::function::unbind(lang::function object) */
db_void db_function_unbind(db_function object);

#ifdef __cplusplus
}
#endif
#endif

