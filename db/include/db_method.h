/* db_method.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef db_method_H
#define db_method_H

#include "cortex.h"
#include "db__type.h"

#include "db__api.h"

#include "db__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* callback ::cortex::lang::procedure::bind(lang::object object) -> ::cortex::lang::method::bind(lang::method object) */
db_int16 db_method_bind(db_method object);

/* callback ::cortex::lang::type::init(lang::object object) -> ::cortex::lang::method::init(lang::method object) */
db_int16 db_method_init(db_method object);

#ifdef __cplusplus
}
#endif
#endif

