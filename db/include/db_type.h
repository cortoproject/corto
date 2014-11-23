/*
 * db_type.h
 *
 *  Created on: Aug 3, 2012
 *      Author: sander
 */

#ifndef DB_TYPE_H_
#define DB_TYPE_H_

#include "db__type.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Methods */
db_uint32 db_type_sizeof(db_type _this);
db_uint16 db_type_alignmentof(db_type _this);
db_bool db_type_compatible(db_type _this, db_type type);
db_bool db_type_castable(db_type _this, db_type type);
db_equalityKind db_type_compare(db_any _this, db_any value);
db_int16 db_type_copy(db_any _this, db_any value);
db_function db_type_resolveProcedure(db_type _this, db_string name);
db_int16 db_type_bindMetaprocedure(db_type _this, db_metaprocedure procedure);

/* Virtuals */
db_uint32 db_type_allocSize(db_type _this);
db_bool db_type_compatible_v(db_type _this, db_type type);

/* Delegates */
db_int16 db_type_init(db_type _this, db_object object);

/* Callbacks */
db_int16 db_type__init(db_type object);
db_int16 db_type_construct(db_type object);
void db_type_destruct(db_type object);

/* Metaprocedures */
db_string db_type_nameof(db_any object);
db_type db_type_typeof(db_any object);
db_string db_type_fullname(db_any object);
db_string db_type_relname(db_any object, db_object from);
db_object db_type_parentof(db_any object);
db_string db_type_toString(db_any object);

db_int16 db_template_construct(db_template object);

#ifdef __cplusplus
}
#endif

#endif /* DB_TYPE_H_ */
