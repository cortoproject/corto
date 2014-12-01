/* db_procedure.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef db_procedure_H
#define db_procedure_H

#include "hyve.h"
#include "db_struct.h"
#include "db__type.h"

#ifdef __cplusplus
extern "C" {
#endif

/* delegate ::hyve::lang::procedure::bind(lang::object object), obtain callback */
db_callback db_procedure_bind_callback(db_procedure _this);

/* delegate ::hyve::lang::procedure::bind(lang::object object), supply callback */
db_int16 db_procedure_bind_w_callback(db_callback __callback, db_procedure _this, db_object object);

/* ::hyve::lang::procedure::bind(lang::object object) */
db_int16 db_procedure_bind(db_procedure _this, db_object object);

/* callback ::hyve::lang::type::init(lang::object object) -> ::hyve::lang::procedure::init(lang::procedure object) */
db_int16 db_procedure_init(db_procedure object);

/* ::hyve::lang::procedure::unbind(lang::object object) */
db_void db_procedure_unbind(db_procedure _this, db_object object);

#ifdef __cplusplus
}
#endif
#endif

