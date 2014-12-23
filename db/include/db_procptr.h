/* db_procptr.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef db_procptr_H
#define db_procptr_H

#include "hyve.h"
#include "db_struct.h"
#include "db__type.h"

#include "db__api.h"

#include "db__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* virtual ::hyve::lang::procptr::compatible(lang::type type) */
db_bool db_procptr_compatible(db_procptr _this, db_type type);

/* ::hyve::lang::procptr::compatible(lang::type type) */
db_bool db_procptr_compatible_v(db_procptr _this, db_type type);

/* callback ::hyve::lang::type::init(lang::object object) -> ::hyve::lang::procptr::init(lang::procptr object) */
db_int16 db_procptr_init(db_procptr object);

#ifdef __cplusplus
}
#endif
#endif

