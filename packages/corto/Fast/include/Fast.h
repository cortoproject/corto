/* Fast.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef Fast_H
#define Fast_H

#include "corto.h"
#include "Fast__type.h"
#include "Fast__api.h"
#include "Fast__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::corto::Fast::isOperatorAssignment(operatorKind operator) */
cx_bool _Fast_isOperatorAssignment(cx_operatorKind operator);
#define Fast_isOperatorAssignment(operator) _Fast_isOperatorAssignment(operator)

/* ::corto::Fast::report(string kind,string filename,uint32 line,uint32 column,string error,string token) */
cx_void _Fast_report(cx_string kind, cx_string filename, cx_uint32 line, cx_uint32 column, cx_string error, cx_string token);
#define Fast_report(kind, filename, line, column, error, token) _Fast_report(kind, filename, line, column, error, token)

/* ::corto::Fast::reportError(string filename,uint32 line,uint32 column,string error,string token) */
cx_void _Fast_reportError(cx_string filename, cx_uint32 line, cx_uint32 column, cx_string error, cx_string token);
#define Fast_reportError(filename, line, column, error, token) _Fast_reportError(filename, line, column, error, token)

/* ::corto::Fast::reportWarning(string filename,uint32 line,uint32 column,string error,string token) */
cx_void _Fast_reportWarning(cx_string filename, cx_uint32 line, cx_uint32 column, cx_string error, cx_string token);
#define Fast_reportWarning(filename, line, column, error, token) _Fast_reportWarning(filename, line, column, error, token)

/* ::corto::Fast::valueKindFromType(type type) */
Fast_valueKind _Fast_valueKindFromType(cx_type type);
#define Fast_valueKindFromType(type) _Fast_valueKindFromType(cx_type(type))

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
#include "Fast_Deinit.h"
#include "Fast_DelegateCall.h"
#include "Fast_DynamicInitializer.h"
#include "Fast_DynamicInitializerFrame.h"
#include "Fast_Element.h"
#include "Fast_Expression.h"
#include "Fast_FloatingPoint.h"
#include "Fast_If.h"
#include "Fast_Init.h"
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
#include "Fast_Temporary.h"
#include "Fast_Ternary.h"
#include "Fast_Unary.h"
#include "Fast_Update.h"
#include "Fast_Wait.h"
#include "Fast_While.h"
#include "ic.h"
