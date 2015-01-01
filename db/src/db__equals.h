/*
 * cx__equals.h
 *
 *  Created on: Aug 1, 2013
 *      Author: sander
 */

#ifndef DB__EQUALS_H_
#define DB__EQUALS_H_

#include "cx__type.h"

#ifdef __cplusplus
extern "C" {
#endif

cx_equalityKind cx_any_equals(cx_any value1, cx_any value2);
cx_equalityKind cx_object_equals(cx_any value1, cx_any value2);
cx_equalityKind cx_octet_equals(cx_any value1, cx_any value2);
cx_equalityKind cx_bool_equals(cx_any value1, cx_any value2);
cx_equalityKind cx_char_equals(cx_any value1, cx_any value2);
cx_equalityKind cx_uint8_equals(cx_any value1, cx_any value2);
cx_equalityKind cx_uint16_equals(cx_any value1, cx_any value2);
cx_equalityKind cx_uint32_equals(cx_any value1, cx_any value2);
cx_equalityKind cx_uint64_equals(cx_any value1, cx_any value2);
cx_equalityKind cx_int8_equals(cx_any value1, cx_any value2);
cx_equalityKind cx_int16_equals(cx_any value1, cx_any value2);
cx_equalityKind cx_int32_equals(cx_any value1, cx_any value2);
cx_equalityKind cx_int64_equals(cx_any value1, cx_any value2);
cx_equalityKind cx_float32_equals(cx_any value1, cx_any value2);
cx_equalityKind cx_float64_equals(cx_any value1, cx_any value2);
cx_equalityKind cx_word_equals(cx_any value1, cx_any value2);
cx_equalityKind cx_constant_equals(cx_any value1, cx_any value2);
cx_equalityKind cx_string_equals(cx_any value1, cx_any value2);

#ifdef __cplusplus
}
#endif

#endif /* DB__EQUALS_H_ */
