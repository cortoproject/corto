/* Fast.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef Fast_H
#define Fast_H

#include "hyve.h"
#include "Fast__type.h"

#include "Fast__api.h"

#include "Fast__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* $header() */
Fast_Call Fast_createMethodCall(Fast_Expression obj, db_string function, db_uint32 numArgs, ...);
/* $end */

/* ::hyve::Fast::valueKindFromType(lang::type type) */
Fast_valueKind Fast_valueKindFromType(db_type type);

#ifdef __cplusplus
}
#endif
#endif

#include "Fast_BinaryExpr.h"
#include "Fast_Binding.h"
#include "Fast_Block.h"
#include "Fast_Boolean.h"
#include "Fast_Call.h"
#include "Fast_CastExpr.h"
#include "Fast_Character.h"
#include "Fast_CommaExpr.h"
#include "Fast_Define.h"
#include "Fast_DynamicInitializer.h"
#include "Fast_DynamicInitializerFrame.h"
#include "Fast_ElementExpr.h"
#include "Fast_Expression.h"
#include "Fast_FloatingPoint.h"
#include "Fast_If.h"
#include "Fast_Initializer.h"
#include "Fast_InitializerExpr.h"
#include "Fast_InitializerFrame.h"
#include "Fast_InitializerVariable.h"
#include "Fast_InitOper.h"
#include "Fast_Integer.h"
#include "Fast_Literal.h"
#include "Fast_Local.h"
#include "Fast_Lvalue.h"
#include "Fast_MemberExpr.h"
#include "Fast_NewExpr.h"
#include "Fast_Node.h"
#include "Fast_Null.h"
#include "Fast_Object.h"
#include "Fast_ObjectBase.h"
#include "Fast_Parser.h"
#include "Fast_Parser_stagedId.h"
#include "Fast_ParserDeclaration.h"
#include "Fast_ParserNew.h"
#include "Fast_PostfixExpr.h"
#include "Fast_SignedInteger.h"
#include "Fast_StaticInitializer.h"
#include "Fast_StaticInitializerFrame.h"
#include "Fast_String.h"
#include "Fast_Template.h"
#include "Fast_TernaryExpr.h"
#include "Fast_UnaryExpr.h"
#include "Fast_Update.h"
#include "Fast_Variable.h"
#include "Fast_Wait.h"
#include "Fast_While.h"
