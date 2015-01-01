/* db_typedef.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef db_typedef_H
#define db_typedef_H

#include "cortex.h"
#include "db__type.h"

#include "db__api.h"

#include "db__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* callback ::cortex::lang::class::construct(lang::object object) -> ::cortex::lang::typedef::construct(lang::typedef object) */
db_int16 db_typedef_construct(db_typedef object);

/* callback ::cortex::lang::class::destruct(lang::object object) -> ::cortex::lang::typedef::destruct(lang::typedef object) */
db_void db_typedef_destruct(db_typedef object);

/* callback ::cortex::lang::type::init(lang::object object) -> ::cortex::lang::typedef::init(lang::typedef object) */
db_int16 db_typedef_init(db_typedef object);

/* ::cortex::lang::typedef::realType() */
db_type db_typedef_realType(db_typedef _this);

#ifdef __cplusplus
}
#endif
#endif

