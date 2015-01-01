/* Fast_Expression.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef Fast_Expression_H
#define Fast_Expression_H

#include "cortex.h"
#include "Fast_Node.h"
#include "Fast__type.h"

#include "Fast__api.h"

#include "Fast__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::cortex::Fast::Expression::cast(lang::type type) */
Fast_Expression Fast_Expression_cast(Fast_Expression _this, db_type type);

/* ::cortex::Fast::Expression::cleanList(list{Expression} list) */
void Fast_Expression_cleanList(Fast_Expression_list list);

/* virtual ::cortex::Fast::Expression::fold() */
Fast_Expression Fast_Expression_fold(Fast_Expression _this);

/* ::cortex::Fast::Expression::fold() */
Fast_Expression Fast_Expression_fold_v(Fast_Expression _this);

/* ::cortex::Fast::Expression::fromList(list{Expression} list) */
Fast_Expression Fast_Expression_fromList(Fast_Expression_list list);

/* ::cortex::Fast::Expression::getType() */
db_type Fast_Expression_getType(Fast_Expression _this);

/* ::cortex::Fast::Expression::getType_expr(Expression target) */
db_type Fast_Expression_getType_expr(Fast_Expression _this, Fast_Expression target);

/* ::cortex::Fast::Expression::getType_type(lang::type target) */
db_type Fast_Expression_getType_type(Fast_Expression _this, db_type target);

/* virtual ::cortex::Fast::Expression::getValue() */
db_word Fast_Expression_getValue(Fast_Expression _this);

/* ::cortex::Fast::Expression::getValue() */
db_word Fast_Expression_getValue_v(Fast_Expression _this);

/* virtual ::cortex::Fast::Expression::hasSideEffects() */
db_bool Fast_Expression_hasSideEffects(Fast_Expression _this);

/* ::cortex::Fast::Expression::hasSideEffects() */
db_bool Fast_Expression_hasSideEffects_v(Fast_Expression _this);

/* callback ::cortex::lang::type::init(lang::object object) -> ::cortex::Fast::Expression::init(Expression object) */
db_int16 Fast_Expression_init(Fast_Expression object);

/* virtual ::cortex::Fast::Expression::serialize(lang::type dstType,lang::word dst) */
db_int16 Fast_Expression_serialize(Fast_Expression _this, db_type dstType, db_word dst);

/* ::cortex::Fast::Expression::serialize(lang::type dstType,lang::word dst) */
db_int16 Fast_Expression_serialize_v(Fast_Expression _this, db_type dstType, db_word dst);

/* virtual ::cortex::Fast::Expression::toList() */
Fast_Expression_list Fast_Expression_toList(Fast_Expression _this);

/* ::cortex::Fast::Expression::toList() */
Fast_Expression_list Fast_Expression_toList_v(Fast_Expression _this);

#ifdef __cplusplus
}
#endif
#endif

