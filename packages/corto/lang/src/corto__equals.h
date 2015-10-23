/*
 * corto__equals.h
 *
 *  Created on: Aug 1, 2013
 *      Author: sander
 */

#ifndef CORTO__EQUALS_H_
#define CORTO__EQUALS_H_

#include "corto__type.h"

#ifdef __cplusplus
extern "C" {
#endif

corto_equalityKind corto_any_equals(corto_any value1, corto_any value2);
corto_equalityKind corto_object_equals(corto_any value1, corto_any value2);
corto_equalityKind corto_octet_equals(corto_any value1, corto_any value2);
corto_equalityKind corto_bool_equals(corto_any value1, corto_any value2);
corto_equalityKind corto_char_equals(corto_any value1, corto_any value2);
corto_equalityKind corto_uint8_equals(corto_any value1, corto_any value2);
corto_equalityKind corto_uint16_equals(corto_any value1, corto_any value2);
corto_equalityKind corto_uint32_equals(corto_any value1, corto_any value2);
corto_equalityKind corto_uint64_equals(corto_any value1, corto_any value2);
corto_equalityKind corto_int8_equals(corto_any value1, corto_any value2);
corto_equalityKind corto_int16_equals(corto_any value1, corto_any value2);
corto_equalityKind corto_int32_equals(corto_any value1, corto_any value2);
corto_equalityKind corto_int64_equals(corto_any value1, corto_any value2);
corto_equalityKind corto_float32_equals(corto_any value1, corto_any value2);
corto_equalityKind corto_float64_equals(corto_any value1, corto_any value2);
corto_equalityKind corto_word_equals(corto_any value1, corto_any value2);
corto_equalityKind corto_constant_equals(corto_any value1, corto_any value2);
corto_equalityKind corto_string_equals(corto_any value1, corto_any value2);

#ifdef __cplusplus
}
#endif

#endif /* CORTO__EQUALS_H_ */
