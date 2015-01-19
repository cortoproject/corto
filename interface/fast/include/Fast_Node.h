/* Fast_Node.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef Fast_Node_H
#define Fast_Node_H

#include "cortex.h"
#include "Fast__type.h"

#include "Fast__api.h"

#include "Fast__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* $header() */
Fast_Expression Fast_Node_optimizeCondition(Fast_Expression condition, cx_bool *result, cx_bool *inverse);
/* $end */

/* ::cortex::Fast::Node::init() */
cx_int16 Fast_Node_init(Fast_Node _this);

/* virtual ::cortex::Fast::Node::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_Node_toIc(Fast_Node _this, cx_icProgram program, cx_icStorage storage, cx_bool stored);

/* ::cortex::Fast::Node::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_Node_toIc_v(Fast_Node _this, cx_icProgram program, cx_icStorage storage, cx_bool stored);

#ifdef __cplusplus
}
#endif
#endif

