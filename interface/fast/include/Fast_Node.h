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

/* callback ::cortex::lang::type::init(lang::object object) -> ::cortex::Fast::Node::init(Node object) */
cx_int16 Fast_Node_init(Fast_Node object);

/* virtual ::cortex::Fast::Node::toIc(lang::alias{"cx_icProgram"} program,lang::alias{"cx_icStorage"} storage,lang::bool stored) */
cx_ic Fast_Node_toIc(Fast_Node _this, cx_icProgram program, cx_icStorage storage, cx_bool stored);

/* ::cortex::Fast::Node::toIc(lang::alias{"cx_icProgram"} program,lang::alias{"cx_icStorage"} storage,lang::bool stored) */
cx_ic Fast_Node_toIc_v(Fast_Node _this, cx_icProgram program, cx_icStorage storage, cx_bool stored);

#ifdef __cplusplus
}
#endif
#endif

