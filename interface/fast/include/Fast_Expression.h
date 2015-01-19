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

/* $header() */
cx_type Fast_Expression_narrowType(Fast_Expression expr);
Fast_Expression Fast_Expression_narrow(Fast_Expression expr, cx_type target);
cx_int8 Fast_Expression_getTypeScore(cx_primitive t);
cx_int8 Fast_Expression_getCastScore(cx_primitive t);
cx_icDerefMode Fast_Expression_getDerefMode(Fast_Expression _this, Fast_Expression rvalue, cx_int32 *check);
/* $end */

/* ::cortex::Fast::Expression::cast(type type,bool isReference) */
Fast_Expression Fast_Expression_cast(Fast_Expression _this, cx_type type, cx_bool isReference);

/* ::cortex::Fast::Expression::cleanList(list{Expression} list) */
cx_void Fast_Expression_cleanList(Fast_Expression_list list);

/* virtual ::cortex::Fast::Expression::fold() */
Fast_Expression Fast_Expression_fold(Fast_Expression _this);

/* ::cortex::Fast::Expression::fold() */
Fast_Expression Fast_Expression_fold_v(Fast_Expression _this);

/* ::cortex::Fast::Expression::fromList(list{Expression} list) */
Fast_Expression Fast_Expression_fromList(Fast_Expression_list list);

/* ::cortex::Fast::Expression::getType() */
cx_type Fast_Expression_getType(Fast_Expression _this);

/* ::cortex::Fast::Expression::getType_expr(Expression target) */
cx_type Fast_Expression_getType_expr(Fast_Expression _this, Fast_Expression target);

/* ::cortex::Fast::Expression::getType_type(type target) */
cx_type Fast_Expression_getType_type(Fast_Expression _this, cx_type target);

/* virtual ::cortex::Fast::Expression::getValue() */
cx_word Fast_Expression_getValue(Fast_Expression _this);

/* ::cortex::Fast::Expression::getValue() */
cx_word Fast_Expression_getValue_v(Fast_Expression _this);

/* virtual ::cortex::Fast::Expression::hasSideEffects() */
cx_bool Fast_Expression_hasSideEffects(Fast_Expression _this);

/* ::cortex::Fast::Expression::hasSideEffects() */
cx_bool Fast_Expression_hasSideEffects_v(Fast_Expression _this);

/* virtual ::cortex::Fast::Expression::serialize(type dstType,word dst) */
cx_int16 Fast_Expression_serialize(Fast_Expression _this, cx_type dstType, cx_word dst);

/* ::cortex::Fast::Expression::serialize(type dstType,word dst) */
cx_int16 Fast_Expression_serialize_v(Fast_Expression _this, cx_type dstType, cx_word dst);

/* virtual ::cortex::Fast::Expression::toList() */
Fast_Expression_list Fast_Expression_toList(Fast_Expression _this);

/* ::cortex::Fast::Expression::toList() */
Fast_Expression_list Fast_Expression_toList_v(Fast_Expression _this);

#ifdef __cplusplus
}
#endif
#endif

