/* db_callback.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef db_callback_H
#define db_callback_H

#include "cortex.h"
#include "db__type.h"

#include "db__api.h"

#include "db__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* callback ::cortex::lang::procedure::bind(lang::object object) -> ::cortex::lang::callback::bind(lang::callback object) */
db_int16 db_callback_bind(db_callback object);

/* callback ::cortex::lang::type::init(lang::object object) -> ::cortex::lang::callback::init(lang::callback object) */
db_int16 db_callback_init(db_callback object);

#ifdef __cplusplus
}
#endif
#endif

