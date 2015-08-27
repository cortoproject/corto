/* Fast_Comma.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef Fast_Comma_H
#define Fast_Comma_H

#include "corto.h"
#include "Fast_Expression.h"
#include "Fast__type.h"
#include "Fast__api.h"
#include "Fast__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::corto::Fast::Comma::addExpression(Expression expr) */
cx_int16 _Fast_Comma_addExpression(Fast_Comma _this, Fast_Expression expr);
#define Fast_Comma_addExpression(_this, expr) _Fast_Comma_addExpression(Fast_Comma(_this), Fast_Expression(expr))

/* ::corto::Fast::Comma::addOrCreate(Expression list,Expression expr) */
Fast_Expression _Fast_Comma_addOrCreate(Fast_Expression list, Fast_Expression expr);
#define Fast_Comma_addOrCreate(list, expr) _Fast_Comma_addOrCreate(Fast_Expression(list), Fast_Expression(expr))

/* ::corto::Fast::Comma::construct() */
cx_int16 _Fast_Comma_construct(Fast_Comma _this);
#define Fast_Comma_construct(_this) _Fast_Comma_construct(Fast_Comma(_this))

/* virtual ::corto::Fast::Comma::hasReturnedResource() */
cx_bool Fast_Comma_hasReturnedResource(Fast_Comma _this);

/* ::corto::Fast::Comma::hasReturnedResource() */
cx_bool _Fast_Comma_hasReturnedResource_v(Fast_Comma _this);
#define Fast_Comma_hasReturnedResource_v(_this) _Fast_Comma_hasReturnedResource_v(Fast_Comma(_this))

/* virtual ::corto::Fast::Comma::hasSideEffects() */
cx_bool Fast_Comma_hasSideEffects(Fast_Comma _this);

/* ::corto::Fast::Comma::hasSideEffects() */
cx_bool _Fast_Comma_hasSideEffects_v(Fast_Comma _this);
#define Fast_Comma_hasSideEffects_v(_this) _Fast_Comma_hasSideEffects_v(Fast_Comma(_this))

/* ::corto::Fast::Comma::init() */
cx_int16 _Fast_Comma_init(Fast_Comma _this);
#define Fast_Comma_init(_this) _Fast_Comma_init(Fast_Comma(_this))

/* ::corto::Fast::Comma::insertOrCreate(Expression list,Expression expr) */
Fast_Expression _Fast_Comma_insertOrCreate(Fast_Expression list, Fast_Expression expr);
#define Fast_Comma_insertOrCreate(list, expr) _Fast_Comma_insertOrCreate(Fast_Expression(list), Fast_Expression(expr))

/* virtual ::corto::Fast::Comma::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node Fast_Comma_toIc(Fast_Comma _this, ic_program program, ic_storage storage, cx_bool stored);

/* ::corto::Fast::Comma::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node _Fast_Comma_toIc_v(Fast_Comma _this, ic_program program, ic_storage storage, cx_bool stored);
#define Fast_Comma_toIc_v(_this, program, storage, stored) _Fast_Comma_toIc_v(Fast_Comma(_this), ic_program(program), ic_storage(storage), stored)

/* ::corto::Fast::Comma::toList() */
Fast_Node_list _Fast_Comma_toList(Fast_Comma _this);
#define Fast_Comma_toList(_this) _Fast_Comma_toList(Fast_Comma(_this))

#ifdef __cplusplus
}
#endif
#endif

