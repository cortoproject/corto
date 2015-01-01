/* db_procedure.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef db_procedure_H
#define db_procedure_H

#include "cortex.h"
#include "db_struct.h"
#include "db__type.h"

#include "db__api.h"

#include "db__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* delegate ::cortex::lang::procedure::bind(lang::object object), obtain callback */
db_bool db_procedure_bind_hasCallback(db_procedure _this);

/* ::cortex::lang::procedure::bind(lang::object object) */
db_int16 db_procedure_bind(db_procedure _this, db_object object);

/* callback ::cortex::lang::type::init(lang::object object) -> ::cortex::lang::procedure::init(lang::procedure object) */
db_int16 db_procedure_init(db_procedure object);

/* ::cortex::lang::procedure::unbind(lang::object object) */
db_void db_procedure_unbind(db_procedure _this, db_object object);

#ifdef __cplusplus
}
#endif
#endif

