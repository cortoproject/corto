/* Fast__api.h
 *
 *    API convenience functions for C-language.
 *    This file contains generated code. Do not modify!
 */

#ifndef Fast__API_H
#define Fast__API_H

#include "Fast__type.h"
#include "cortex.h"

#ifdef __cplusplus
extern "C" {
#endif
/* ::cortex::Fast::Binary */
Fast_Binary Fast_Binary__new(void);
Fast_Binary Fast_Binary__declare(cx_object _parent, cx_string _name);
int Fast_Binary__define(Fast_Binary _this, Fast_Expression lvalue, Fast_Expression rvalue, cx_operatorKind operator);
Fast_Binary Fast_Binary__create(Fast_Expression lvalue, Fast_Expression rvalue, cx_operatorKind operator);

/* ::cortex::Fast::Binding */
void Fast_Binding__init(Fast_Binding *_this, cx_function function, Fast_Block impl);
void Fast_Binding__deinit(Fast_Binding *_this);

/* ::cortex::Fast::Block */
Fast_Block Fast_Block__new(void);
Fast_Block Fast_Block__declare(cx_object _parent, cx_string _name);
int Fast_Block__define(Fast_Block _this, Fast_Block parent);
Fast_Block Fast_Block__create(Fast_Block parent);

/* ::cortex::Fast::Boolean */
Fast_Boolean Fast_Boolean__new(void);
Fast_Boolean Fast_Boolean__declare(cx_object _parent, cx_string _name);
int Fast_Boolean__define(Fast_Boolean _this, cx_bool value);
Fast_Boolean Fast_Boolean__create(cx_bool value);

/* ::cortex::Fast::Call */
Fast_Call Fast_Call__new(void);
Fast_Call Fast_Call__declare(cx_object _parent, cx_string _name);
int Fast_Call__define(Fast_Call _this, Fast_Expression instanceExpr, Fast_Expression arguments);
Fast_Call Fast_Call__create(Fast_Expression instanceExpr, Fast_Expression arguments);

/* ::cortex::Fast::CallBuilder */
void Fast_CallBuilder__init(Fast_CallBuilder *_this, cx_string name, Fast_Expression arguments, Fast_Expression instance, cx_object scope, Fast_Block block);
void Fast_CallBuilder__deinit(Fast_CallBuilder *_this);

/* ::cortex::Fast::Cast */
Fast_Cast Fast_Cast__new(void);
Fast_Cast Fast_Cast__declare(cx_object _parent, cx_string _name);
int Fast_Cast__define(Fast_Cast _this, Fast_Expression lvalue, Fast_Expression rvalue);
Fast_Cast Fast_Cast__create(Fast_Expression lvalue, Fast_Expression rvalue);

/* ::cortex::Fast::Character */
Fast_Character Fast_Character__new(void);
Fast_Character Fast_Character__declare(cx_object _parent, cx_string _name);
int Fast_Character__define(Fast_Character _this, cx_char value);
Fast_Character Fast_Character__create(cx_char value);

/* ::cortex::Fast::Comma */
Fast_Comma Fast_Comma__new(void);
Fast_Comma Fast_Comma__declare(cx_object _parent, cx_string _name);
int Fast_Comma__define(Fast_Comma _this);
Fast_Comma Fast_Comma__create(void);

/* ::cortex::Fast::Define */
Fast_Define Fast_Define__new(void);
Fast_Define Fast_Define__declare(cx_object _parent, cx_string _name);
int Fast_Define__define(Fast_Define _this, Fast_Expression object);
Fast_Define Fast_Define__create(Fast_Expression object);

/* ::cortex::Fast::DelegateCall */
Fast_DelegateCall Fast_DelegateCall__new(void);
Fast_DelegateCall Fast_DelegateCall__declare(cx_object _parent, cx_string _name);
int Fast_DelegateCall__define(Fast_DelegateCall _this, Fast_Expression instanceExpr, Fast_Expression arguments, Fast_Expression expr);
Fast_DelegateCall Fast_DelegateCall__create(Fast_Expression instanceExpr, Fast_Expression arguments, Fast_Expression expr);

/* ::cortex::Fast::DynamicInitializer */
Fast_DynamicInitializer Fast_DynamicInitializer__new(void);
Fast_DynamicInitializer Fast_DynamicInitializer__declare(cx_object _parent, cx_string _name);
int Fast_DynamicInitializer__define(Fast_DynamicInitializer _this, Fast_InitializerVariable_array64 variables, cx_uint8 variableCount, cx_bool assignValue);
Fast_DynamicInitializer Fast_DynamicInitializer__create(Fast_InitializerVariable_array64 variables, cx_uint8 variableCount, cx_bool assignValue);

/* ::cortex::Fast::DynamicInitializerFrame */
void Fast_DynamicInitializerFrame__init(Fast_DynamicInitializerFrame *_this, Fast_Expression_array64 expr, Fast_Expression_array64 keyExpr, Fast_Integer sequenceSize);
void Fast_DynamicInitializerFrame__deinit(Fast_DynamicInitializerFrame *_this);

/* ::cortex::Fast::Element */
Fast_Element Fast_Element__new(void);
Fast_Element Fast_Element__declare(cx_object _parent, cx_string _name);
int Fast_Element__define(Fast_Element _this, Fast_Expression lvalue, Fast_Expression rvalue);
Fast_Element Fast_Element__create(Fast_Expression lvalue, Fast_Expression rvalue);

/* ::cortex::Fast::Expression */
Fast_Expression Fast_Expression__new(void);
Fast_Expression Fast_Expression__declare(cx_object _parent, cx_string _name);
int Fast_Expression__define(Fast_Expression _this, Fast_nodeKind kind);
Fast_Expression Fast_Expression__create(Fast_nodeKind kind);

/* ::cortex::Fast::FloatingPoint */
Fast_FloatingPoint Fast_FloatingPoint__new(void);
Fast_FloatingPoint Fast_FloatingPoint__declare(cx_object _parent, cx_string _name);
int Fast_FloatingPoint__define(Fast_FloatingPoint _this, cx_float64 value);
Fast_FloatingPoint Fast_FloatingPoint__create(cx_float64 value);

/* ::cortex::Fast::If */
Fast_If Fast_If__new(void);
Fast_If Fast_If__declare(cx_object _parent, cx_string _name);
int Fast_If__define(Fast_If _this, Fast_Expression condition, Fast_Block trueBranch, Fast_If falseBranch);
Fast_If Fast_If__create(Fast_Expression condition, Fast_Block trueBranch, Fast_If falseBranch);

/* ::cortex::Fast::Initializer */
Fast_Initializer Fast_Initializer__new(void);
Fast_Initializer Fast_Initializer__declare(cx_object _parent, cx_string _name);
int Fast_Initializer__define(Fast_Initializer _this, Fast_InitializerVariable_array64 variables, cx_uint8 variableCount);
Fast_Initializer Fast_Initializer__create(Fast_InitializerVariable_array64 variables, cx_uint8 variableCount);

/* ::cortex::Fast::InitializerExpression */
Fast_InitializerExpression Fast_InitializerExpression__new(void);
Fast_InitializerExpression Fast_InitializerExpression__declare(cx_object _parent, cx_string _name);
int Fast_InitializerExpression__define(Fast_InitializerExpression _this, Fast_InitializerVariable_array64 variables, cx_uint8 variableCount, cx_bool assignValue);
Fast_InitializerExpression Fast_InitializerExpression__create(Fast_InitializerVariable_array64 variables, cx_uint8 variableCount, cx_bool assignValue);

/* ::cortex::Fast::InitializerFrame */
void Fast_InitializerFrame__init(Fast_InitializerFrame *_this, cx_uint32 location, cx_type type, cx_bool isKey, cx_member member);
void Fast_InitializerFrame__deinit(Fast_InitializerFrame *_this);

/* ::cortex::Fast::InitializerVariable */
void Fast_InitializerVariable__init(Fast_InitializerVariable *_this, cx_word offset, Fast_Expression object, cx_word key);
void Fast_InitializerVariable__deinit(Fast_InitializerVariable *_this);

/* ::cortex::Fast::InitOper */
void Fast_InitOper__init(Fast_InitOper *_this, Fast_InitOperKind kind, Fast_Expression expr, cx_string name);
void Fast_InitOper__deinit(Fast_InitOper *_this);

/* ::cortex::Fast::Integer */
Fast_Integer Fast_Integer__new(void);
Fast_Integer Fast_Integer__declare(cx_object _parent, cx_string _name);
int Fast_Integer__define(Fast_Integer _this, cx_uint64 value);
Fast_Integer Fast_Integer__create(cx_uint64 value);

/* ::cortex::Fast::Literal */
Fast_Literal Fast_Literal__new(void);
Fast_Literal Fast_Literal__declare(cx_object _parent, cx_string _name);
int Fast_Literal__define(Fast_Literal _this, Fast_valueKind kind_1);
Fast_Literal Fast_Literal__create(Fast_valueKind kind_1);

/* ::cortex::Fast::Local */
Fast_Local Fast_Local__new(void);
Fast_Local Fast_Local__declare(cx_object _parent, cx_string _name);
int Fast_Local__define(Fast_Local _this, cx_string name, Fast_Variable type_1, Fast_LocalKind kind_2, cx_bool reference);
Fast_Local Fast_Local__create(cx_string name, Fast_Variable type_1, Fast_LocalKind kind_2, cx_bool reference);

/* ::cortex::Fast::Lvalue */
void Fast_Lvalue__init(Fast_Lvalue *_this, Fast_Expression expr, cx_bool isAssignment);
void Fast_Lvalue__deinit(Fast_Lvalue *_this);

/* ::cortex::Fast::Member */
Fast_Member Fast_Member__new(void);
Fast_Member Fast_Member__declare(cx_object _parent, cx_string _name);
int Fast_Member__define(Fast_Member _this, Fast_Expression lvalue, Fast_Expression rvalue);
Fast_Member Fast_Member__create(Fast_Expression lvalue, Fast_Expression rvalue);

/* ::cortex::Fast::New */
Fast_New Fast_New__new(void);
Fast_New Fast_New__declare(cx_object _parent, cx_string _name);
int Fast_New__define(Fast_New _this, Fast_Expression type_1, Fast_Expression attributes);
Fast_New Fast_New__create(Fast_Expression type_1, Fast_Expression attributes);

/* ::cortex::Fast::Node */
Fast_Node Fast_Node__new(void);
Fast_Node Fast_Node__declare(cx_object _parent, cx_string _name);
int Fast_Node__define(Fast_Node _this, Fast_nodeKind kind);
Fast_Node Fast_Node__create(Fast_nodeKind kind);

/* ::cortex::Fast::Null */
Fast_Null Fast_Null__new(void);
Fast_Null Fast_Null__declare(cx_object _parent, cx_string _name);
int Fast_Null__define(Fast_Null _this);
Fast_Null Fast_Null__create(void);

/* ::cortex::Fast::Object */
Fast_Object Fast_Object__new(void);
Fast_Object Fast_Object__declare(cx_object _parent, cx_string _name);
int Fast_Object__define(Fast_Object _this, cx_object value);
Fast_Object Fast_Object__create(cx_object value);

/* ::cortex::Fast::ObjectBase */
Fast_ObjectBase Fast_ObjectBase__new(void);
Fast_ObjectBase Fast_ObjectBase__declare(cx_object _parent, cx_string _name);
int Fast_ObjectBase__define(Fast_ObjectBase _this, cx_object value);
Fast_ObjectBase Fast_ObjectBase__create(cx_object value);

/* ::cortex::Fast::Parser */
Fast_Parser Fast_Parser__new(void);
Fast_Parser Fast_Parser__declare(cx_object _parent, cx_string _name);
int Fast_Parser__define(Fast_Parser _this, cx_string source, cx_string filename);
Fast_Parser Fast_Parser__create(cx_string source, cx_string filename);

/* ::cortex::Fast::Parser::stagedId */
void Fast_Parser_stagedId__init(Fast_Parser_stagedId *_this, cx_string name, cx_bool found, cx_uint32 line, cx_uint32 column);
void Fast_Parser_stagedId__deinit(Fast_Parser_stagedId *_this);

/* ::cortex::Fast::ParserDeclaration */
void Fast_ParserDeclaration__init(Fast_ParserDeclaration *_this, cx_string name, Fast_Variable variable);
void Fast_ParserDeclaration__deinit(Fast_ParserDeclaration *_this);

/* ::cortex::Fast::ParserNew */
void Fast_ParserNew__init(Fast_ParserNew *_this, Fast_nodeKind kind, Fast_Expression parent, Fast_Expression name, Fast_Expression attr);
void Fast_ParserNew__deinit(Fast_ParserNew *_this);

/* ::cortex::Fast::PostFix */
Fast_PostFix Fast_PostFix__new(void);
Fast_PostFix Fast_PostFix__declare(cx_object _parent, cx_string _name);
int Fast_PostFix__define(Fast_PostFix _this, Fast_Expression lvalue, cx_operatorKind operator);
Fast_PostFix Fast_PostFix__create(Fast_Expression lvalue, cx_operatorKind operator);

/* ::cortex::Fast::SignedInteger */
Fast_SignedInteger Fast_SignedInteger__new(void);
Fast_SignedInteger Fast_SignedInteger__declare(cx_object _parent, cx_string _name);
int Fast_SignedInteger__define(Fast_SignedInteger _this, cx_int64 value);
Fast_SignedInteger Fast_SignedInteger__create(cx_int64 value);

/* ::cortex::Fast::StaticCall */
Fast_StaticCall Fast_StaticCall__new(void);
Fast_StaticCall Fast_StaticCall__declare(cx_object _parent, cx_string _name);
int Fast_StaticCall__define(Fast_StaticCall _this, Fast_Expression instanceExpr, Fast_Expression arguments, cx_function function);
Fast_StaticCall Fast_StaticCall__create(Fast_Expression instanceExpr, Fast_Expression arguments, cx_function function);

/* ::cortex::Fast::StaticInitializer */
Fast_StaticInitializer Fast_StaticInitializer__new(void);
Fast_StaticInitializer Fast_StaticInitializer__declare(cx_object _parent, cx_string _name);
int Fast_StaticInitializer__define(Fast_StaticInitializer _this, Fast_InitializerVariable_array64 variables, cx_uint8 variableCount);
Fast_StaticInitializer Fast_StaticInitializer__create(Fast_InitializerVariable_array64 variables, cx_uint8 variableCount);

/* ::cortex::Fast::StaticInitializerFrame */
void Fast_StaticInitializerFrame__init(Fast_StaticInitializerFrame *_this, cx_word_array64 ptr, cx_word_array64 keyPtr);
void Fast_StaticInitializerFrame__deinit(Fast_StaticInitializerFrame *_this);

/* ::cortex::Fast::String */
Fast_String Fast_String__new(void);
Fast_String Fast_String__declare(cx_object _parent, cx_string _name);
int Fast_String__define(Fast_String _this, cx_string value);
Fast_String Fast_String__create(cx_string value);

/* ::cortex::Fast::Template */
Fast_Template Fast_Template__new(void);
Fast_Template Fast_Template__declare(cx_object _parent, cx_string _name);
int Fast_Template__define(Fast_Template _this, cx_string name, Fast_Variable type_1, Fast_LocalKind kind_2, cx_bool reference);
Fast_Template Fast_Template__create(cx_string name, Fast_Variable type_1, Fast_LocalKind kind_2, cx_bool reference);

/* ::cortex::Fast::Ternary */
Fast_Ternary Fast_Ternary__new(void);
Fast_Ternary Fast_Ternary__declare(cx_object _parent, cx_string _name);
int Fast_Ternary__define(Fast_Ternary _this, Fast_Expression condition, Fast_Expression ifTrue, Fast_Expression ifFalse, Fast_Expression result);
Fast_Ternary Fast_Ternary__create(Fast_Expression condition, Fast_Expression ifTrue, Fast_Expression ifFalse, Fast_Expression result);

/* ::cortex::Fast::Unary */
Fast_Unary Fast_Unary__new(void);
Fast_Unary Fast_Unary__declare(cx_object _parent, cx_string _name);
int Fast_Unary__define(Fast_Unary _this, Fast_Expression lvalue, cx_operatorKind operator);
Fast_Unary Fast_Unary__create(Fast_Expression lvalue, cx_operatorKind operator);

/* ::cortex::Fast::Update */
Fast_Update Fast_Update__new(void);
Fast_Update Fast_Update__declare(cx_object _parent, cx_string _name);
int Fast_Update__define(Fast_Update _this, Fast_Expression_list exprList, Fast_Block block, Fast_Expression from, Fast_UpdateKind kind_1);
Fast_Update Fast_Update__create(Fast_Expression_list exprList, Fast_Block block, Fast_Expression from, Fast_UpdateKind kind_1);

/* ::cortex::Fast::Variable */
Fast_Variable Fast_Variable__new(void);
Fast_Variable Fast_Variable__declare(cx_object _parent, cx_string _name);
int Fast_Variable__define(Fast_Variable _this, Fast_variableKind kind_1);
Fast_Variable Fast_Variable__create(Fast_variableKind kind_1);

/* ::cortex::Fast::Wait */
Fast_Wait Fast_Wait__new(void);
Fast_Wait Fast_Wait__declare(cx_object _parent, cx_string _name);
int Fast_Wait__define(Fast_Wait _this, Fast_Expression_list exprList, Fast_Expression timeout);
Fast_Wait Fast_Wait__create(Fast_Expression_list exprList, Fast_Expression timeout);

/* ::cortex::Fast::While */
Fast_While Fast_While__new(void);
Fast_While Fast_While__declare(cx_object _parent, cx_string _name);
int Fast_While__define(Fast_While _this, Fast_Expression condition, Fast_Block trueBranch, cx_bool isUntil);
Fast_While Fast_While__create(Fast_Expression condition, Fast_Block trueBranch, cx_bool isUntil);


/* <0x7fbd73d5e538> */
#define Fast_Binding_list__foreach(list, elem) \
    cx_iter elem##_iter = cx_llIter(list);\
    Fast_Binding *elem;\
    while(cx_iterHasNext(&elem##_iter)) {\
        elem = cx_iterNext(&elem##_iter);

Fast_Binding* Fast_Binding_list__insert(Fast_Binding_list list);
Fast_Binding* Fast_Binding_list__append(Fast_Binding_list list);
Fast_Binding* Fast_Binding_list__takeFirst(Fast_Binding_list list);
Fast_Binding* Fast_Binding_list__last(Fast_Binding_list list);
void Fast_Binding_list__clear(Fast_Binding_list list);
Fast_Binding* Fast_Binding_list__get(Fast_Binding_list list, cx_uint32 index);
cx_uint32 Fast_Binding_list__size(Fast_Binding_list list);

/* <0x7fbd73e676d8> */
#define Fast_Expression_list__foreach(list, elem) \
    cx_iter elem##_iter = cx_llIter(list);\
    Fast_Expression elem;\
    while(cx_iterHasNext(&elem##_iter)) {\
        elem = cx_iterNext(&elem##_iter);

void Fast_Expression_list__insert(Fast_Expression_list list, Fast_Expression element);
void Fast_Expression_list__append(Fast_Expression_list list, Fast_Expression element);
Fast_Expression Fast_Expression_list__takeFirst(Fast_Expression_list list);
Fast_Expression Fast_Expression_list__last(Fast_Expression_list list);
void Fast_Expression_list__clear(Fast_Expression_list list);
Fast_Expression Fast_Expression_list__get(Fast_Expression_list list, cx_uint32 index);
cx_uint32 Fast_Expression_list__size(Fast_Expression_list list);

/* <0x7fbd73d56448> */
#define Fast_InitOper_list__foreach(list, elem) \
    cx_iter elem##_iter = cx_llIter(list);\
    Fast_InitOper *elem;\
    while(cx_iterHasNext(&elem##_iter)) {\
        elem = cx_iterNext(&elem##_iter);

Fast_InitOper* Fast_InitOper_list__insert(Fast_InitOper_list list);
Fast_InitOper* Fast_InitOper_list__append(Fast_InitOper_list list);
Fast_InitOper* Fast_InitOper_list__takeFirst(Fast_InitOper_list list);
Fast_InitOper* Fast_InitOper_list__last(Fast_InitOper_list list);
void Fast_InitOper_list__clear(Fast_InitOper_list list);
Fast_InitOper* Fast_InitOper_list__get(Fast_InitOper_list list, cx_uint32 index);
cx_uint32 Fast_InitOper_list__size(Fast_InitOper_list list);

/* <0x7fbd73d219d8> */
#define Fast_Local_list__foreach(list, elem) \
    cx_iter elem##_iter = cx_llIter(list);\
    Fast_Local elem;\
    while(cx_iterHasNext(&elem##_iter)) {\
        elem = cx_iterNext(&elem##_iter);

void Fast_Local_list__insert(Fast_Local_list list, Fast_Local element);
void Fast_Local_list__append(Fast_Local_list list, Fast_Local element);
Fast_Local Fast_Local_list__takeFirst(Fast_Local_list list);
Fast_Local Fast_Local_list__last(Fast_Local_list list);
void Fast_Local_list__clear(Fast_Local_list list);
Fast_Local Fast_Local_list__get(Fast_Local_list list, cx_uint32 index);
cx_uint32 Fast_Local_list__size(Fast_Local_list list);

/* <0x7fbd73d21548> */
#define Fast_Node_list__foreach(list, elem) \
    cx_iter elem##_iter = cx_llIter(list);\
    Fast_Node elem;\
    while(cx_iterHasNext(&elem##_iter)) {\
        elem = cx_iterNext(&elem##_iter);

void Fast_Node_list__insert(Fast_Node_list list, Fast_Node element);
void Fast_Node_list__append(Fast_Node_list list, Fast_Node element);
Fast_Node Fast_Node_list__takeFirst(Fast_Node_list list);
Fast_Node Fast_Node_list__last(Fast_Node_list list);
void Fast_Node_list__clear(Fast_Node_list list);
Fast_Node Fast_Node_list__get(Fast_Node_list list, cx_uint32 index);
cx_uint32 Fast_Node_list__size(Fast_Node_list list);

/* ::cortex::Fast::ParserDeclarationSeq */
#define Fast_ParserDeclarationSeq__foreach(seq, elem) \
    cx_uint32 elem##_iter;\
    Fast_ParserDeclaration *elem;\
    for(elem##_iter=0; elem##_iter<seq.length; elem##_iter++) {\
        elem = &seq.buffer[elem##_iter];

Fast_ParserDeclaration* Fast_ParserDeclarationSeq__append(Fast_ParserDeclarationSeq *seq);
void Fast_ParserDeclarationSeq__size(Fast_ParserDeclarationSeq *seq, cx_uint32 length);
void Fast_ParserDeclarationSeq__clear(Fast_ParserDeclarationSeq *seq);

/* <0x7fbd73d2ae68> */
#define cx_parameter_seq__foreach(seq, elem) \
    cx_uint32 elem##_iter;\
    cx_parameter *elem;\
    for(elem##_iter=0; elem##_iter<seq.length; elem##_iter++) {\
        elem = &seq.buffer[elem##_iter];

cx_parameter* cx_parameter_seq__append(cx_parameter_seq *seq);
void cx_parameter_seq__size(cx_parameter_seq *seq, cx_uint32 length);
void cx_parameter_seq__clear(cx_parameter_seq *seq);

/* <0x7fbd73d5fe18> */
#define cx_object_list__foreach(list, elem) \
    cx_iter elem##_iter = cx_llIter(list);\
    cx_object elem;\
    while(cx_iterHasNext(&elem##_iter)) {\
        elem = cx_iterNext(&elem##_iter);

void cx_object_list__insert(cx_object_list list, cx_object element);
void cx_object_list__append(cx_object_list list, cx_object element);
cx_object cx_object_list__takeFirst(cx_object_list list);
cx_object cx_object_list__last(cx_object_list list);
void cx_object_list__clear(cx_object_list list);
cx_object cx_object_list__get(cx_object_list list, cx_uint32 index);
cx_uint32 cx_object_list__size(cx_object_list list);

/* <0x7fbd73d5fd48> */
#define cx_word_list__foreach(list, elem) \
    cx_iter elem##_iter = cx_llIter(list);\
    cx_word *elem;\
    while(cx_iterHasNext(&elem##_iter)) {\
        elem = cx_iterNext(&elem##_iter);

void cx_word_list__insert(cx_word_list list, cx_word element);
void cx_word_list__append(cx_word_list list, cx_word element);
cx_word cx_word_list__takeFirst(cx_word_list list);
cx_word cx_word_list__last(cx_word_list list);
void cx_word_list__clear(cx_word_list list);
cx_word cx_word_list__get(cx_word_list list, cx_uint32 index);
cx_uint32 cx_word_list__size(cx_word_list list);

#ifdef __cplusplus
}
#endif
#endif

