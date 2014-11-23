/*
 * db__equals.h
 *
 *  Created on: Aug 1, 2013
 *      Author: sander
 */

#ifndef DB__EQUALS_H_
#define DB__EQUALS_H_

#include "db__type.h"

#ifdef __cplusplus
extern "C" {
#endif

db_equalityKind db_any_equals(db_any value1, db_any value2);
db_equalityKind db_object_equals(db_any value1, db_any value2);
db_equalityKind db_octet_equals(db_any value1, db_any value2);
db_equalityKind db_bool_equals(db_any value1, db_any value2);
db_equalityKind db_char_equals(db_any value1, db_any value2);
db_equalityKind db_uint8_equals(db_any value1, db_any value2);
db_equalityKind db_uint16_equals(db_any value1, db_any value2);
db_equalityKind db_uint32_equals(db_any value1, db_any value2);
db_equalityKind db_uint64_equals(db_any value1, db_any value2);
db_equalityKind db_int8_equals(db_any value1, db_any value2);
db_equalityKind db_int16_equals(db_any value1, db_any value2);
db_equalityKind db_int32_equals(db_any value1, db_any value2);
db_equalityKind db_int64_equals(db_any value1, db_any value2);
db_equalityKind db_float32_equals(db_any value1, db_any value2);
db_equalityKind db_float64_equals(db_any value1, db_any value2);
db_equalityKind db_word_equals(db_any value1, db_any value2);
db_equalityKind db_constant_equals(db_any value1, db_any value2);
db_equalityKind db_string_equals(db_any value1, db_any value2);

#ifdef __cplusplus
}
#endif

#endif /* DB__EQUALS_H_ */
