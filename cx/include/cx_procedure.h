/* cx_procedure.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef cx_procedure_H
#define cx_procedure_H

#include "cortex.h"
#include "cx_struct.h"
#include "cx__type.h"

#include "cx__api.h"

#include "cx__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* delegate ::cortex::lang::procedure::bind(object object), obtain callback */
cx_bool cx_procedure_bind_hasCallback(cx_procedure _this);

/* callback ::cortex::lang::type::init(object object) -> ::cortex::lang::procedure::init(procedure object) */
cx_int16 cx_procedure_init(cx_procedure object);

/* ::cortex::lang::procedure::unbind(object object) */
cx_void cx_procedure_unbind(cx_procedure _this, cx_object object);

#ifdef __cplusplus
}
#endif
#endif

