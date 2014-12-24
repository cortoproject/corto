/* Fast__api.h
 *
 *    API convenience functions for C-language.
 *    This file contains generated code. Do not modify!
 */

#ifndef Fast__API_H
#define Fast__API_H

#include "Fast__type.h"
#include "hyve.h"

#ifdef __cplusplus
extern "C" {
#endif
/* ::hyve::Fast::BinaryExpr */
Fast_BinaryExpr Fast_BinaryExpr__new(void);
Fast_BinaryExpr Fast_BinaryExpr__declare(db_object _parent, db_string _name);
int Fast_BinaryExpr__define(Fast_BinaryExpr _this, Fast_Expression lvalue, Fast_Expression rvalue, db_operatorKind operator);
Fast_BinaryExpr Fast_BinaryExpr__create(Fast_Expression lvalue, Fast_Expression rvalue, db_operatorKind operator);

/* ::hyve::Fast::Binding */
void Fast_Binding__init(Fast_Binding *_this, db_function function, Fast_Block impl);
void Fast_Binding__deinit(Fast_Binding *_this);

/* ::hyve::Fast::Block */
Fast_Block Fast_Block__new(void);
Fast_Block Fast_Block__declare(db_object _parent, db_string _name);
int Fast_Block__define(Fast_Block _this, Fast_Block parent);
Fast_Block Fast_Block__create(Fast_Block parent);

/* ::hyve::Fast::Boolean */
Fast_Boolean Fast_Boolean__new(void);
Fast_Boolean Fast_Boolean__declare(db_object _parent, db_string _name);
int Fast_Boolean__define(Fast_Boolean _this, db_bool value);
Fast_Boolean Fast_Boolean__create(db_bool value);

/* ::hyve::Fast::Call */
Fast_Call Fast_Call__new(void);
Fast_Call Fast_Call__declare(db_object _parent, db_string _name);
int Fast_Call__define(Fast_Call _this, Fast_Expression function, Fast_Expression arguments);
Fast_Call Fast_Call__create(Fast_Expression function, Fast_Expression arguments);

/* ::hyve::Fast::CastExpr */
Fast_CastExpr Fast_CastExpr__new(void);
Fast_CastExpr Fast_CastExpr__declare(db_object _parent, db_string _name);
int Fast_CastExpr__define(Fast_CastExpr _this, Fast_Expression lvalue, Fast_Expression rvalue);
Fast_CastExpr Fast_CastExpr__create(Fast_Expression lvalue, Fast_Expression rvalue);

/* ::hyve::Fast::Character */
Fast_Character Fast_Character__new(void);
Fast_Character Fast_Character__declare(db_object _parent, db_string _name);
int Fast_Character__define(Fast_Character _this, db_char value);
Fast_Character Fast_Character__create(db_char value);

/* ::hyve::Fast::CommaExpr */
Fast_CommaExpr Fast_CommaExpr__new(void);
Fast_CommaExpr Fast_CommaExpr__declare(db_object _parent, db_string _name);
int Fast_CommaExpr__define(Fast_CommaExpr _this);
Fast_CommaExpr Fast_CommaExpr__create(void);

/* ::hyve::Fast::Define */
Fast_Define Fast_Define__new(void);
Fast_Define Fast_Define__declare(db_object _parent, db_string _name);
int Fast_Define__define(Fast_Define _this, Fast_Expression object);
Fast_Define Fast_Define__create(Fast_Expression object);

/* ::hyve::Fast::DynamicInitializer */
Fast_DynamicInitializer Fast_DynamicInitializer__new(void);
Fast_DynamicInitializer Fast_DynamicInitializer__declare(db_object _parent, db_string _name);
int Fast_DynamicInitializer__define(Fast_DynamicInitializer _this, Fast_InitializerVariable_array64 variables, db_uint8 variableCount, db_bool assignValue);
Fast_DynamicInitializer Fast_DynamicInitializer__create(Fast_InitializerVariable_array64 variables, db_uint8 variableCount, db_bool assignValue);

/* ::hyve::Fast::DynamicInitializerFrame */
void Fast_DynamicInitializerFrame__init(Fast_DynamicInitializerFrame *_this, Fast_Expression_array64 expr, Fast_Expression_array64 keyExpr, Fast_Integer sequenceSize);
void Fast_DynamicInitializerFrame__deinit(Fast_DynamicInitializerFrame *_this);

/* ::hyve::Fast::ElementExpr */
Fast_ElementExpr Fast_ElementExpr__new(void);
Fast_ElementExpr Fast_ElementExpr__declare(db_object _parent, db_string _name);
int Fast_ElementExpr__define(Fast_ElementExpr _this, Fast_Expression lvalue, Fast_Expression rvalue);
Fast_ElementExpr Fast_ElementExpr__create(Fast_Expression lvalue, Fast_Expression rvalue);

/* ::hyve::Fast::Expression */
Fast_Expression Fast_Expression__new(void);
Fast_Expression Fast_Expression__declare(db_object _parent, db_string _name);
int Fast_Expression__define(Fast_Expression _this, Fast_nodeKind kind);
Fast_Expression Fast_Expression__create(Fast_nodeKind kind);

/* ::hyve::Fast::FloatingPoint */
Fast_FloatingPoint Fast_FloatingPoint__new(void);
Fast_FloatingPoint Fast_FloatingPoint__declare(db_object _parent, db_string _name);
int Fast_FloatingPoint__define(Fast_FloatingPoint _this, db_float64 value);
Fast_FloatingPoint Fast_FloatingPoint__create(db_float64 value);

/* ::hyve::Fast::If */
Fast_If Fast_If__new(void);
Fast_If Fast_If__declare(db_object _parent, db_string _name);
int Fast_If__define(Fast_If _this, Fast_Expression condition, Fast_Block trueBranch, Fast_If falseBranch);
Fast_If Fast_If__create(Fast_Expression condition, Fast_Block trueBranch, Fast_If falseBranch);

/* ::hyve::Fast::Initializer */
Fast_Initializer Fast_Initializer__new(void);
Fast_Initializer Fast_Initializer__declare(db_object _parent, db_string _name);
int Fast_Initializer__define(Fast_Initializer _this, Fast_InitializerVariable_array64 variables, db_uint8 variableCount);
Fast_Initializer Fast_Initializer__create(Fast_InitializerVariable_array64 variables, db_uint8 variableCount);

/* ::hyve::Fast::InitializerExpr */
Fast_InitializerExpr Fast_InitializerExpr__new(void);
Fast_InitializerExpr Fast_InitializerExpr__declare(db_object _parent, db_string _name);
int Fast_InitializerExpr__define(Fast_InitializerExpr _this, Fast_InitializerVariable_array64 variables, db_uint8 variableCount, db_bool assignValue);
Fast_InitializerExpr Fast_InitializerExpr__create(Fast_InitializerVariable_array64 variables, db_uint8 variableCount, db_bool assignValue);

/* ::hyve::Fast::InitializerFrame */
void Fast_InitializerFrame__init(Fast_InitializerFrame *_this, db_uint32 location, db_type type, db_bool isKey, db_member member);
void Fast_InitializerFrame__deinit(Fast_InitializerFrame *_this);

/* ::hyve::Fast::InitializerVariable */
void Fast_InitializerVariable__init(Fast_InitializerVariable *_this, db_word offset, Fast_Expression object, db_word key);
void Fast_InitializerVariable__deinit(Fast_InitializerVariable *_this);

/* ::hyve::Fast::InitOper */
void Fast_InitOper__init(Fast_InitOper *_this, Fast_InitOperKind kind, Fast_Expression expr, db_string name);
void Fast_InitOper__deinit(Fast_InitOper *_this);

/* ::hyve::Fast::Integer */
Fast_Integer Fast_Integer__new(void);
Fast_Integer Fast_Integer__declare(db_object _parent, db_string _name);
int Fast_Integer__define(Fast_Integer _this, db_uint64 value);
Fast_Integer Fast_Integer__create(db_uint64 value);

/* ::hyve::Fast::Literal */
Fast_Literal Fast_Literal__new(void);
Fast_Literal Fast_Literal__declare(db_object _parent, db_string _name);
int Fast_Literal__define(Fast_Literal _this, Fast_valueKind kind_1);
Fast_Literal Fast_Literal__create(Fast_valueKind kind_1);

/* ::hyve::Fast::Local */
Fast_Local Fast_Local__new(void);
Fast_Local Fast_Local__declare(db_object _parent, db_string _name);
int Fast_Local__define(Fast_Local _this, db_string name, Fast_Variable type_1, Fast_LocalKind kind_2, db_bool isReference_1);
Fast_Local Fast_Local__create(db_string name, Fast_Variable type_1, Fast_LocalKind kind_2, db_bool isReference_1);

/* ::hyve::Fast::Lvalue */
void Fast_Lvalue__init(Fast_Lvalue *_this, Fast_Expression expr, db_bool isAssignment);
void Fast_Lvalue__deinit(Fast_Lvalue *_this);

/* ::hyve::Fast::MemberExpr */
Fast_MemberExpr Fast_MemberExpr__new(void);
Fast_MemberExpr Fast_MemberExpr__declare(db_object _parent, db_string _name);
int Fast_MemberExpr__define(Fast_MemberExpr _this, Fast_Expression lvalue, Fast_Expression rvalue);
Fast_MemberExpr Fast_MemberExpr__create(Fast_Expression lvalue, Fast_Expression rvalue);

/* ::hyve::Fast::NewExpr */
Fast_NewExpr Fast_NewExpr__new(void);
Fast_NewExpr Fast_NewExpr__declare(db_object _parent, db_string _name);
int Fast_NewExpr__define(Fast_NewExpr _this, Fast_Expression type_1, Fast_Expression attributes);
Fast_NewExpr Fast_NewExpr__create(Fast_Expression type_1, Fast_Expression attributes);

/* ::hyve::Fast::Node */
Fast_Node Fast_Node__new(void);
Fast_Node Fast_Node__declare(db_object _parent, db_string _name);
int Fast_Node__define(Fast_Node _this, Fast_nodeKind kind);
Fast_Node Fast_Node__create(Fast_nodeKind kind);

/* ::hyve::Fast::Null */
Fast_Null Fast_Null__new(void);
Fast_Null Fast_Null__declare(db_object _parent, db_string _name);
int Fast_Null__define(Fast_Null _this);
Fast_Null Fast_Null__create(void);

/* ::hyve::Fast::Object */
Fast_Object Fast_Object__new(void);
Fast_Object Fast_Object__declare(db_object _parent, db_string _name);
int Fast_Object__define(Fast_Object _this, db_object value);
Fast_Object Fast_Object__create(db_object value);

/* ::hyve::Fast::ObjectBase */
Fast_ObjectBase Fast_ObjectBase__new(void);
Fast_ObjectBase Fast_ObjectBase__declare(db_object _parent, db_string _name);
int Fast_ObjectBase__define(Fast_ObjectBase _this, db_object value);
Fast_ObjectBase Fast_ObjectBase__create(db_object value);

/* ::hyve::Fast::Parser */
Fast_Parser Fast_Parser__new(void);
Fast_Parser Fast_Parser__declare(db_object _parent, db_string _name);
int Fast_Parser__define(Fast_Parser _this, db_string source, db_string filename);
Fast_Parser Fast_Parser__create(db_string source, db_string filename);

/* ::hyve::Fast::Parser::stagedId */
void Fast_Parser_stagedId__init(Fast_Parser_stagedId *_this, db_string name, db_bool found, db_uint32 line, db_uint32 column);
void Fast_Parser_stagedId__deinit(Fast_Parser_stagedId *_this);

/* ::hyve::Fast::ParserDeclaration */
void Fast_ParserDeclaration__init(Fast_ParserDeclaration *_this, db_string name, Fast_Variable variable);
void Fast_ParserDeclaration__deinit(Fast_ParserDeclaration *_this);

/* ::hyve::Fast::ParserNew */
void Fast_ParserNew__init(Fast_ParserNew *_this, Fast_nodeKind kind, Fast_Expression parent, Fast_Expression name, Fast_Expression attr);
void Fast_ParserNew__deinit(Fast_ParserNew *_this);

/* ::hyve::Fast::PostfixExpr */
Fast_PostfixExpr Fast_PostfixExpr__new(void);
Fast_PostfixExpr Fast_PostfixExpr__declare(db_object _parent, db_string _name);
int Fast_PostfixExpr__define(Fast_PostfixExpr _this, Fast_Expression lvalue, db_operatorKind operator);
Fast_PostfixExpr Fast_PostfixExpr__create(Fast_Expression lvalue, db_operatorKind operator);

/* ::hyve::Fast::SignedInteger */
Fast_SignedInteger Fast_SignedInteger__new(void);
Fast_SignedInteger Fast_SignedInteger__declare(db_object _parent, db_string _name);
int Fast_SignedInteger__define(Fast_SignedInteger _this, db_int64 value);
Fast_SignedInteger Fast_SignedInteger__create(db_int64 value);

/* ::hyve::Fast::StaticInitializer */
Fast_StaticInitializer Fast_StaticInitializer__new(void);
Fast_StaticInitializer Fast_StaticInitializer__declare(db_object _parent, db_string _name);
int Fast_StaticInitializer__define(Fast_StaticInitializer _this, Fast_InitializerVariable_array64 variables, db_uint8 variableCount);
Fast_StaticInitializer Fast_StaticInitializer__create(Fast_InitializerVariable_array64 variables, db_uint8 variableCount);

/* ::hyve::Fast::StaticInitializerFrame */
void Fast_StaticInitializerFrame__init(Fast_StaticInitializerFrame *_this, db_word_array64 ptr, db_word_array64 keyPtr);
void Fast_StaticInitializerFrame__deinit(Fast_StaticInitializerFrame *_this);

/* ::hyve::Fast::String */
Fast_String Fast_String__new(void);
Fast_String Fast_String__declare(db_object _parent, db_string _name);
int Fast_String__define(Fast_String _this, db_string value);
Fast_String Fast_String__create(db_string value);

/* ::hyve::Fast::Template */
Fast_Template Fast_Template__new(void);
Fast_Template Fast_Template__declare(db_object _parent, db_string _name);
int Fast_Template__define(Fast_Template _this, db_string name, Fast_Variable type_1, Fast_LocalKind kind_2, db_bool isReference_1);
Fast_Template Fast_Template__create(db_string name, Fast_Variable type_1, Fast_LocalKind kind_2, db_bool isReference_1);

/* ::hyve::Fast::TernaryExpr */
Fast_TernaryExpr Fast_TernaryExpr__new(void);
Fast_TernaryExpr Fast_TernaryExpr__declare(db_object _parent, db_string _name);
int Fast_TernaryExpr__define(Fast_TernaryExpr _this, Fast_Expression condition, Fast_Expression ifTrue, Fast_Expression ifFalse, Fast_Expression result);
Fast_TernaryExpr Fast_TernaryExpr__create(Fast_Expression condition, Fast_Expression ifTrue, Fast_Expression ifFalse, Fast_Expression result);

/* ::hyve::Fast::UnaryExpr */
Fast_UnaryExpr Fast_UnaryExpr__new(void);
Fast_UnaryExpr Fast_UnaryExpr__declare(db_object _parent, db_string _name);
int Fast_UnaryExpr__define(Fast_UnaryExpr _this, Fast_Expression lvalue, db_operatorKind operator);
Fast_UnaryExpr Fast_UnaryExpr__create(Fast_Expression lvalue, db_operatorKind operator);

/* ::hyve::Fast::Update */
Fast_Update Fast_Update__new(void);
Fast_Update Fast_Update__declare(db_object _parent, db_string _name);
int Fast_Update__define(Fast_Update _this, Fast_Expression_list exprList, Fast_Block block, Fast_Expression from);
Fast_Update Fast_Update__create(Fast_Expression_list exprList, Fast_Block block, Fast_Expression from);

/* ::hyve::Fast::Variable */
Fast_Variable Fast_Variable__new(void);
Fast_Variable Fast_Variable__declare(db_object _parent, db_string _name);
int Fast_Variable__define(Fast_Variable _this, Fast_variableKind kind_1);
Fast_Variable Fast_Variable__create(Fast_variableKind kind_1);

/* ::hyve::Fast::Wait */
Fast_Wait Fast_Wait__new(void);
Fast_Wait Fast_Wait__declare(db_object _parent, db_string _name);
int Fast_Wait__define(Fast_Wait _this, Fast_Expression_list exprList, Fast_Expression timeout);
Fast_Wait Fast_Wait__create(Fast_Expression_list exprList, Fast_Expression timeout);

/* ::hyve::Fast::While */
Fast_While Fast_While__new(void);
Fast_While Fast_While__declare(db_object _parent, db_string _name);
int Fast_While__define(Fast_While _this, Fast_Expression condition, Fast_Block trueBranch, db_bool isUntil);
Fast_While Fast_While__create(Fast_Expression condition, Fast_Block trueBranch, db_bool isUntil);


/* <0x9c73420> */
#define Fast_Binding_list__foreach(list, elem) \
    db_iter elem##_iter = db_llIter(list);\
    Fast_Binding *elem;\
    while(db_iterHasNext(&elem##_iter)) {\
        elem = db_iterNext(&elem##_iter);

Fast_Binding* Fast_Binding_list__insert(Fast_Binding_list list);
Fast_Binding* Fast_Binding_list__append(Fast_Binding_list list);
Fast_Binding* Fast_Binding_list__takeFirst(Fast_Binding_list list);
Fast_Binding* Fast_Binding_list__last(Fast_Binding_list list);
void Fast_Binding_list__clear(Fast_Binding_list list);
Fast_Binding* Fast_Binding_list__get(Fast_Binding_list list, db_uint32 index);
db_uint32 Fast_Binding_list__size(Fast_Binding_list list);

/* <0x9c198e8> */
#define Fast_Expression_list__foreach(list, elem) \
    db_iter elem##_iter = db_llIter(list);\
    Fast_Expression elem;\
    while(db_iterHasNext(&elem##_iter)) {\
        elem = db_iterNext(&elem##_iter);

void Fast_Expression_list__insert(Fast_Expression_list list, Fast_Expression element);
void Fast_Expression_list__append(Fast_Expression_list list, Fast_Expression element);
Fast_Expression Fast_Expression_list__takeFirst(Fast_Expression_list list);
Fast_Expression Fast_Expression_list__last(Fast_Expression_list list);
void Fast_Expression_list__clear(Fast_Expression_list list);
Fast_Expression Fast_Expression_list__get(Fast_Expression_list list, db_uint32 index);
db_uint32 Fast_Expression_list__size(Fast_Expression_list list);

/* <0x9c708f0> */
#define Fast_InitOper_list__foreach(list, elem) \
    db_iter elem##_iter = db_llIter(list);\
    Fast_InitOper *elem;\
    while(db_iterHasNext(&elem##_iter)) {\
        elem = db_iterNext(&elem##_iter);

Fast_InitOper* Fast_InitOper_list__insert(Fast_InitOper_list list);
Fast_InitOper* Fast_InitOper_list__append(Fast_InitOper_list list);
Fast_InitOper* Fast_InitOper_list__takeFirst(Fast_InitOper_list list);
Fast_InitOper* Fast_InitOper_list__last(Fast_InitOper_list list);
void Fast_InitOper_list__clear(Fast_InitOper_list list);
Fast_InitOper* Fast_InitOper_list__get(Fast_InitOper_list list, db_uint32 index);
db_uint32 Fast_InitOper_list__size(Fast_InitOper_list list);

/* <0x9c670c0> */
#define Fast_Local_list__foreach(list, elem) \
    db_iter elem##_iter = db_llIter(list);\
    Fast_Local elem;\
    while(db_iterHasNext(&elem##_iter)) {\
        elem = db_iterNext(&elem##_iter);

void Fast_Local_list__insert(Fast_Local_list list, Fast_Local element);
void Fast_Local_list__append(Fast_Local_list list, Fast_Local element);
Fast_Local Fast_Local_list__takeFirst(Fast_Local_list list);
Fast_Local Fast_Local_list__last(Fast_Local_list list);
void Fast_Local_list__clear(Fast_Local_list list);
Fast_Local Fast_Local_list__get(Fast_Local_list list, db_uint32 index);
db_uint32 Fast_Local_list__size(Fast_Local_list list);

/* <0x9c66ed0> */
#define Fast_Node_list__foreach(list, elem) \
    db_iter elem##_iter = db_llIter(list);\
    Fast_Node elem;\
    while(db_iterHasNext(&elem##_iter)) {\
        elem = db_iterNext(&elem##_iter);

void Fast_Node_list__insert(Fast_Node_list list, Fast_Node element);
void Fast_Node_list__append(Fast_Node_list list, Fast_Node element);
Fast_Node Fast_Node_list__takeFirst(Fast_Node_list list);
Fast_Node Fast_Node_list__last(Fast_Node_list list);
void Fast_Node_list__clear(Fast_Node_list list);
Fast_Node Fast_Node_list__get(Fast_Node_list list, db_uint32 index);
db_uint32 Fast_Node_list__size(Fast_Node_list list);

/* <0x9c73a90> */
#define Fast_Object_list__foreach(list, elem) \
    db_iter elem##_iter = db_llIter(list);\
    Fast_Object elem;\
    while(db_iterHasNext(&elem##_iter)) {\
        elem = db_iterNext(&elem##_iter);

void Fast_Object_list__insert(Fast_Object_list list, Fast_Object element);
void Fast_Object_list__append(Fast_Object_list list, Fast_Object element);
Fast_Object Fast_Object_list__takeFirst(Fast_Object_list list);
Fast_Object Fast_Object_list__last(Fast_Object_list list);
void Fast_Object_list__clear(Fast_Object_list list);
Fast_Object Fast_Object_list__get(Fast_Object_list list, db_uint32 index);
db_uint32 Fast_Object_list__size(Fast_Object_list list);

/* <0x9c71548> */
#define Fast_ParserDeclaration_seq256__foreach(seq, elem) \
    db_uint32 elem##_iter;\
    Fast_ParserDeclaration *elem;\
    for(elem##_iter=0; elem##_iter<seq.length; elem##_iter++) {\
        elem = &seq.buffer[elem##_iter];

Fast_ParserDeclaration* Fast_ParserDeclaration_seq256__append(Fast_ParserDeclaration_seq256 *seq);
void Fast_ParserDeclaration_seq256__size(Fast_ParserDeclaration_seq256 *seq, db_uint32 length);
void Fast_ParserDeclaration_seq256__clear(Fast_ParserDeclaration_seq256 *seq);

/* <0x9c738f0> */
#define db_word_list__foreach(list, elem) \
    db_iter elem##_iter = db_llIter(list);\
    db_word *elem;\
    while(db_iterHasNext(&elem##_iter)) {\
        elem = db_iterNext(&elem##_iter);

void db_word_list__insert(db_word_list list, db_word element);
void db_word_list__append(db_word_list list, db_word element);
db_word db_word_list__takeFirst(db_word_list list);
db_word db_word_list__last(db_word_list list);
void db_word_list__clear(db_word_list list);
db_word db_word_list__get(db_word_list list, db_uint32 index);
db_uint32 db_word_list__size(db_word_list list);

#ifdef __cplusplus
}
#endif
#endif

