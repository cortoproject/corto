/* Fast_Binary.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef Fast_Binary_H
#define Fast_Binary_H

#include "cortex.h"
#include "Fast_Expression.h"
#include "Fast__type.h"

#include "Fast__api.h"

#include "Fast__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::cortex::Fast::Binary::construct() */
cx_int16 Fast_Binary_construct(Fast_Binary _this);

/* ::cortex::Fast::Binary::fold() */
Fast_Expression Fast_Binary_fold(Fast_Binary _this);

/* virtual ::cortex::Fast::Binary::hasSideEffects() */
cx_bool Fast_Binary_hasSideEffects(Fast_Binary _this);

/* ::cortex::Fast::Binary::hasSideEffects() */
cx_bool Fast_Binary_hasSideEffects_v(Fast_Binary _this);

/* ::cortex::Fast::Binary::setOperator(operatorKind kind) */
cx_void Fast_Binary_setOperator(Fast_Binary _this, cx_operatorKind kind);

/* virtual ::cortex::Fast::Binary::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_Binary_toIc(Fast_Binary _this, cx_icProgram program, cx_icStorage storage, cx_bool stored);

/* ::cortex::Fast::Binary::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_Binary_toIc_v(Fast_Binary _this, cx_icProgram program, cx_icStorage storage, cx_bool stored);

#ifdef __cplusplus
}
#endif
#endif

