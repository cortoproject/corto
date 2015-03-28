/* Fast.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef Fast_H
#define Fast_H

#include "cortex.h"
#include "Fast__type.h"

#include "Fast__api.h"

#include "Fast__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* $header() */
Fast_Call Fast_createCall(Fast_Expression instance, cx_string function, cx_uint32 numArgs, ...);
Fast_Call Fast_createCallWithArguments(Fast_Expression instance, cx_string function, Fast_Expression arguments);
Fast_Call Fast_createCallFromExpr(Fast_Expression f, Fast_Expression arguments);
Fast_Parser yparser(void);
void Fast_Parser_error(Fast_Parser _this, char* fmt, ...);
void Fast_Parser_warning(Fast_Parser _this, char* fmt, ...);
/* $end */

/* ::cortex::Fast::report(string kind,string filename,uint32 line,uint32 column,string error,string token) */
cx_void Fast_report(cx_string kind, cx_string filename, cx_uint32 line, cx_uint32 column, cx_string error, cx_string token);

/* ::cortex::Fast::reportError(string filename,uint32 line,uint32 column,string error,string token) */
cx_void Fast_reportError(cx_string filename, cx_uint32 line, cx_uint32 column, cx_string error, cx_string token);

/* ::cortex::Fast::reportWarning(string filename,uint32 line,uint32 column,string error,string token) */
cx_void Fast_reportWarning(cx_string filename, cx_uint32 line, cx_uint32 column, cx_string error, cx_string token);

/* ::cortex::Fast::valueKindFromType(lang::type type) */
Fast_valueKind Fast_valueKindFromType(cx_type type);

#ifdef __cplusplus
}
#endif
#endif

#include "Fast_Binary.h"
#include "Fast_Binding.h"
#include "Fast_Block.h"
#include "Fast_Boolean.h"
#include "Fast_Call.h"
#include "Fast_CallBuilder.h"
#include "Fast_Cast.h"
#include "Fast_Character.h"
#include "Fast_Comma.h"
#include "Fast_Define.h"
#include "Fast_DelegateCall.h"
#include "Fast_DynamicInitializer.h"
#include "Fast_DynamicInitializerFrame.h"
#include "Fast_Element.h"
#include "Fast_Expression.h"
#include "Fast_FloatingPoint.h"
#include "Fast_If.h"
#include "Fast_Initializer.h"
#include "Fast_InitializerExpression.h"
#include "Fast_InitializerFrame.h"
#include "Fast_InitializerVariable.h"
#include "Fast_InitOper.h"
#include "Fast_Integer.h"
#include "Fast_Literal.h"
#include "Fast_Local.h"
#include "Fast_Lvalue.h"
#include "Fast_Member.h"
#include "Fast_New.h"
#include "Fast_Node.h"
#include "Fast_Null.h"
#include "Fast_Object.h"
#include "Fast_Parser.h"
#include "Fast_Parser_stagedId.h"
#include "Fast_ParserDeclaration.h"
#include "Fast_ParserNew.h"
#include "Fast_PostFix.h"
#include "Fast_SignedInteger.h"
#include "Fast_StaticCall.h"
#include "Fast_StaticInitializer.h"
#include "Fast_StaticInitializerFrame.h"
#include "Fast_Storage.h"
#include "Fast_String.h"
#include "Fast_Template.h"
#include "Fast_Ternary.h"
#include "Fast_Unary.h"
#include "Fast_Update.h"
#include "Fast_Wait.h"
#include "Fast_While.h"
