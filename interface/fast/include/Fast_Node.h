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
Fast_Expression Fast_Node_optimizeCondition(Fast_Expression condition, db_bool *result, db_bool *inverse);
/* $end */

/* callback ::cortex::lang::type::init(lang::object object) -> ::cortex::Fast::Node::init(Node object) */
db_int16 Fast_Node_init(Fast_Node object);

/* virtual ::cortex::Fast::Node::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_Node_toIc(Fast_Node _this, db_icProgram program, db_icStorage storage, db_bool stored);

/* ::cortex::Fast::Node::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_Node_toIc_v(Fast_Node _this, db_icProgram program, db_icStorage storage, db_bool stored);

#ifdef __cplusplus
}
#endif
#endif

