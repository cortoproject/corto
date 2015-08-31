/* cx_sequence.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef cx_sequence_H
#define cx_sequence_H

#include "corto.h"
#include "cx_collection.h"
#include "cx__type.h"
#include "cx__api.h"
#include "cx__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::corto::lang::sequence::construct() */
cx_int16 _cx_sequence_construct(cx_sequence _this);
#define cx_sequence_construct(_this) _cx_sequence_construct(cx_sequence(_this))

/* ::corto::lang::sequence::init() */
cx_int16 _cx_sequence_init(cx_sequence _this);
#define cx_sequence_init(_this) _cx_sequence_init(cx_sequence(_this))

/* ::corto::lang::sequence::size(uint32 size) */
cx_void _cx_sequence_size(cx_any _this, cx_uint32 size);
#define cx_sequence_size(_this, size) _cx_sequence_size(_this, size)

#ifdef __cplusplus
}
#endif
#endif

