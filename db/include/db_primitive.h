/*
 * db_primitive.h
 *
 *  Created on: Aug 9, 2012
 *      Author: sander
 */

#ifndef DB_PRIMITIVE_H_
#define DB_PRIMITIVE_H_

#include "db__type.h"

#ifdef __cplusplus
extern "C" {
#endif

/* type::init -> primitive::init */
db_int16 db_primitive_init(db_primitive object);

/* class::construct -> primitive::construct */
db_int16 db_primitive_construct(db_primitive object);

/* class::destruct -> primitive::destruct */
void db_primitive_destruct(db_primitive object);

/* virtual primitive::compatible */
db_bool db_primitive_compatible(db_primitive _this, db_type type);

/* virtual primitive::castable */
db_bool db_primitive_castable(db_primitive _this, db_type type);

/* metaprocedure primitive::equals */
db_equalityKind db_primitive_compare(db_any _this, db_any value);

/* type::init -> binary::init */
db_int16 db_binary_init(db_binary object);

/* type::init -> boolean::init */
db_int16 db_boolean_init(db_boolean object);

/* type::init -> char::init */
db_int16 db_character_init(db_character object);

/* type::init -> int::init */
db_int16 db_int_init(db_int object);

/* type::init -> uint::init */
db_int16 db_uint_init(db_uint object);

/* type::init -> float::init */
db_int16 db_float_init(db_float object);

/* type::init -> text::init */
db_int16 db_text_init(db_text object);

/* type::init -> enum::init */
db_int16 db_enum_init(db_enum object);

/* type::init -> bitmask::init */
db_int16 db_bitmask_init(db_bitmask object);

/* type::init -> alias::init */
db_int16 db_alias_init(db_alias object);

/* type->init -> constant::init */
db_int16 db_constant_init(db_constant* object);

/* enum::constant */
db_object db_enum_constant(db_enum _this, db_int32 value);

/* enum::construct */
db_int16 db_enum_construct(db_enum object);

/* enum::destruct */
void db_enum_destruct(db_enum object);

#ifdef __cplusplus
}
#endif

#endif /* DB_PRIMITIVE_H_ */
