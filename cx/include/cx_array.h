/* cx_array.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef cx_array_H
#define cx_array_H

#include "cortex.h"
#include "cx_collection.h"
#include "cx__type.h"

#include "cx__api.h"

#include "cx__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* callback ::cortex::lang::class::construct(object object) -> ::cortex::lang::array::construct(array object) */
cx_int16 cx_array_construct(cx_array object);

/* callback ::cortex::lang::class::destruct(object object) -> ::cortex::lang::array::destruct(array object) */
cx_void cx_array_destruct(cx_array object);

/* callback ::cortex::lang::type::init(object object) -> ::cortex::lang::array::init(array object) */
cx_int16 cx_array_init(cx_array object);

#ifdef __cplusplus
}
#endif
#endif

