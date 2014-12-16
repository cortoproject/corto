/* db_array.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef db_array_H
#define db_array_H

#include "hyve.h"
#include "db_collection.h"
#include "db__type.h"

#include "db__api.h"

#include "db__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* callback ::hyve::lang::class::construct(lang::object object) -> ::hyve::lang::array::construct(lang::array object) */
db_int16 db_array_construct(db_array object);

/* callback ::hyve::lang::class::destruct(lang::object object) -> ::hyve::lang::array::destruct(lang::array object) */
db_void db_array_destruct(db_array object);

/* callback ::hyve::lang::type::init(lang::object object) -> ::hyve::lang::array::init(lang::array object) */
db_int16 db_array_init(db_array object);

#ifdef __cplusplus
}
#endif
#endif

