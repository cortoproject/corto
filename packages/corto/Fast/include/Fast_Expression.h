/* Fast_Expression.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef Fast_Expression_H
#define Fast_Expression_H

#include "corto.h"
#include "Fast_Node.h"
#include "Fast__type.h"
#include "Fast__api.h"
#include "Fast__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::corto::Fast::Expression::cast(type type,bool isReference) */
Fast_Expression _Fast_Expression_cast(Fast_Expression _this, cx_type type, cx_bool isReference);
#define Fast_Expression_cast(_this, type, isReference) _Fast_Expression_cast(Fast_Expression(_this), cx_type(type), isReference)

/* ::corto::Fast::Expression::cleanList(list{Expression} list) */
cx_void _Fast_Expression_cleanList(Fast_Expression_list list);
#define Fast_Expression_cleanList(list) _Fast_Expression_cleanList(list)

/* virtual ::corto::Fast::Expression::fold() */
Fast_Expression Fast_Expression_fold(Fast_Expression _this);

/* ::corto::Fast::Expression::fold() */
Fast_Expression _Fast_Expression_fold_v(Fast_Expression _this);
#define Fast_Expression_fold_v(_this) _Fast_Expression_fold_v(Fast_Expression(_this))

/* ::corto::Fast::Expression::fromList(list{Expression} list) */
Fast_Expression _Fast_Expression_fromList(Fast_Expression_list list);
#define Fast_Expression_fromList(list) _Fast_Expression_fromList(list)

/* ::corto::Fast::Expression::getType() */
cx_type _Fast_Expression_getType(Fast_Expression _this);
#define Fast_Expression_getType(_this) _Fast_Expression_getType(Fast_Expression(_this))

/* ::corto::Fast::Expression::getType_expr(Expression target) */
cx_type _Fast_Expression_getType_expr(Fast_Expression _this, Fast_Expression target);
#define Fast_Expression_getType_expr(_this, target) _Fast_Expression_getType_expr(Fast_Expression(_this), Fast_Expression(target))

/* ::corto::Fast::Expression::getType_type(type target) */
cx_type _Fast_Expression_getType_type(Fast_Expression _this, cx_type target);
#define Fast_Expression_getType_type(_this, target) _Fast_Expression_getType_type(Fast_Expression(_this), cx_type(target))

/* virtual ::corto::Fast::Expression::getValue() */
cx_word Fast_Expression_getValue(Fast_Expression _this);

/* ::corto::Fast::Expression::getValue() */
cx_word _Fast_Expression_getValue_v(Fast_Expression _this);
#define Fast_Expression_getValue_v(_this) _Fast_Expression_getValue_v(Fast_Expression(_this))

/* virtual ::corto::Fast::Expression::hasReturnedResource() */
cx_bool Fast_Expression_hasReturnedResource(Fast_Expression _this);

/* ::corto::Fast::Expression::hasReturnedResource() */
cx_bool _Fast_Expression_hasReturnedResource_v(Fast_Expression _this);
#define Fast_Expression_hasReturnedResource_v(_this) _Fast_Expression_hasReturnedResource_v(Fast_Expression(_this))

/* virtual ::corto::Fast::Expression::hasSideEffects() */
cx_bool Fast_Expression_hasSideEffects(Fast_Expression _this);

/* ::corto::Fast::Expression::hasSideEffects() */
cx_bool _Fast_Expression_hasSideEffects_v(Fast_Expression _this);
#define Fast_Expression_hasSideEffects_v(_this) _Fast_Expression_hasSideEffects_v(Fast_Expression(_this))

/* virtual ::corto::Fast::Expression::serialize(type dstType,word dst) */
cx_int16 Fast_Expression_serialize(Fast_Expression _this, cx_type dstType, cx_word dst);

/* ::corto::Fast::Expression::serialize(type dstType,word dst) */
cx_int16 _Fast_Expression_serialize_v(Fast_Expression _this, cx_type dstType, cx_word dst);
#define Fast_Expression_serialize_v(_this, dstType, dst) _Fast_Expression_serialize_v(Fast_Expression(_this), cx_type(dstType), dst)

/* virtual ::corto::Fast::Expression::toList() */
Fast_Expression_list Fast_Expression_toList(Fast_Expression _this);

/* ::corto::Fast::Expression::toList() */
Fast_Expression_list _Fast_Expression_toList_v(Fast_Expression _this);
#define Fast_Expression_toList_v(_this) _Fast_Expression_toList_v(Fast_Expression(_this))

#ifdef __cplusplus
}
#endif
#endif

