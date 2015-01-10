/* cx_sequence.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef cx_sequence_H
#define cx_sequence_H

#include "cortex.h"
#include "cx_collection.h"
#include "cx__type.h"

#include "cx__api.h"

#include "cx__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* callback ::cortex::lang::class::construct(object object) -> ::cortex::lang::sequence::construct(sequence object) */
cx_int16 cx_sequence_construct(cx_sequence object);

/* callback ::cortex::lang::type::init(object object) -> ::cortex::lang::sequence::init(sequence object) */
cx_int16 cx_sequence_init(cx_sequence object);

/* ::cortex::lang::sequence::size(uint32 size) */
cx_void cx_sequence_size(cx_any _this, cx_uint32 size);

#ifdef __cplusplus
}
#endif
#endif

