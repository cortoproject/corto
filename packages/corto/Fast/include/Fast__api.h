/* Fast__api.h
 *
 * API convenience functions for C-language.
 * This file contains generated code. Do not modify!
 */

#ifndef Fast__API_H
#define Fast__API_H

#include "Fast__type.h"
#include "corto.h"

#ifdef __cplusplus
extern "C" {
#endif
/* ::corto::Fast::Binary */
Fast_Binary Fast_Binary__create(Fast_Expression lvalue, Fast_Expression rvalue, cx_operatorKind operator);
Fast_Binary Fast_Binary__createChild(cx_object _parent, cx_string _name, Fast_Expression lvalue, Fast_Expression rvalue, cx_operatorKind operator);

Fast_Binary Fast_Binary__declare(void);
Fast_Binary Fast_Binary__declareChild(cx_object _parent, cx_string _name);
cx_int16 Fast_Binary__define(Fast_Binary _this, Fast_Expression lvalue, Fast_Expression rvalue, cx_operatorKind operator);
void Fast_Binary__update(Fast_Binary _this, Fast_Expression lvalue, Fast_Expression rvalue, cx_operatorKind operator);
void Fast_Binary__set(Fast_Binary _this, Fast_Expression lvalue, Fast_Expression rvalue, cx_operatorKind operator);
cx_string Fast_Binary__str(Fast_Binary value);
Fast_Binary Fast_Binary__fromStr(Fast_Binary value, cx_string str);
cx_int16 Fast_Binary__copy(Fast_Binary *dst, Fast_Binary src);
cx_int16 Fast_Binary__compare(Fast_Binary dst, Fast_Binary src);

/* ::corto::Fast::Binding */
Fast_Binding* Fast_Binding__create(cx_function function, Fast_Block impl);
Fast_Binding* Fast_Binding__createChild(cx_object _parent, cx_string _name, cx_function function, Fast_Block impl);

Fast_Binding* Fast_Binding__declare(void);
Fast_Binding* Fast_Binding__declareChild(cx_object _parent, cx_string _name);
cx_int16 Fast_Binding__define(Fast_Binding* _this, cx_function function, Fast_Block impl);
void Fast_Binding__update(Fast_Binding* _this, cx_function function, Fast_Block impl);
void Fast_Binding__set(Fast_Binding* _this, cx_function function, Fast_Block impl);
cx_string Fast_Binding__str(Fast_Binding* value);
Fast_Binding* Fast_Binding__fromStr(Fast_Binding* value, cx_string str);
cx_int16 Fast_Binding__copy(Fast_Binding* *dst, Fast_Binding* src);
cx_int16 Fast_Binding__compare(Fast_Binding* dst, Fast_Binding* src);

cx_int16 Fast_Binding__init(Fast_Binding* value);
cx_int16 Fast_Binding__deinit(Fast_Binding* value);

/* ::corto::Fast::Block */
Fast_Block Fast_Block__create(Fast_Block parent);
Fast_Block Fast_Block__createChild(cx_object _parent, cx_string _name, Fast_Block parent);

Fast_Block Fast_Block__declare(void);
Fast_Block Fast_Block__declareChild(cx_object _parent, cx_string _name);
cx_int16 Fast_Block__define(Fast_Block _this, Fast_Block parent);
void Fast_Block__update(Fast_Block _this, Fast_Block parent);
void Fast_Block__set(Fast_Block _this, Fast_Block parent);
cx_string Fast_Block__str(Fast_Block value);
Fast_Block Fast_Block__fromStr(Fast_Block value, cx_string str);
cx_int16 Fast_Block__copy(Fast_Block *dst, Fast_Block src);
cx_int16 Fast_Block__compare(Fast_Block dst, Fast_Block src);

/* ::corto::Fast::Boolean */
Fast_Boolean Fast_Boolean__create(cx_bool value);
Fast_Boolean Fast_Boolean__createChild(cx_object _parent, cx_string _name, cx_bool value);

Fast_Boolean Fast_Boolean__declare(void);
Fast_Boolean Fast_Boolean__declareChild(cx_object _parent, cx_string _name);
cx_int16 Fast_Boolean__define(Fast_Boolean _this, cx_bool value);
void Fast_Boolean__update(Fast_Boolean _this, cx_bool value);
void Fast_Boolean__set(Fast_Boolean _this, cx_bool value);
cx_string Fast_Boolean__str(Fast_Boolean value);
Fast_Boolean Fast_Boolean__fromStr(Fast_Boolean value, cx_string str);
cx_int16 Fast_Boolean__copy(Fast_Boolean *dst, Fast_Boolean src);
cx_int16 Fast_Boolean__compare(Fast_Boolean dst, Fast_Boolean src);

/* ::corto::Fast::Call */
Fast_Call Fast_Call__create(Fast_Expression instanceExpr, Fast_Expression arguments);
Fast_Call Fast_Call__createChild(cx_object _parent, cx_string _name, Fast_Expression instanceExpr, Fast_Expression arguments);

Fast_Call Fast_Call__declare(void);
Fast_Call Fast_Call__declareChild(cx_object _parent, cx_string _name);
cx_int16 Fast_Call__define(Fast_Call _this, Fast_Expression instanceExpr, Fast_Expression arguments);
void Fast_Call__update(Fast_Call _this, Fast_Expression instanceExpr, Fast_Expression arguments);
void Fast_Call__set(Fast_Call _this, Fast_Expression instanceExpr, Fast_Expression arguments);
cx_string Fast_Call__str(Fast_Call value);
Fast_Call Fast_Call__fromStr(Fast_Call value, cx_string str);
cx_int16 Fast_Call__copy(Fast_Call *dst, Fast_Call src);
cx_int16 Fast_Call__compare(Fast_Call dst, Fast_Call src);

/* ::corto::Fast::CallBuilder */
Fast_CallBuilder* Fast_CallBuilder__create(cx_string name, Fast_Expression arguments, Fast_Expression instance, cx_object scope, Fast_Block block);
Fast_CallBuilder* Fast_CallBuilder__createChild(cx_object _parent, cx_string _name, cx_string name, Fast_Expression arguments, Fast_Expression instance, cx_object scope, Fast_Block block);

Fast_CallBuilder* Fast_CallBuilder__declare(void);
Fast_CallBuilder* Fast_CallBuilder__declareChild(cx_object _parent, cx_string _name);
cx_int16 Fast_CallBuilder__define(Fast_CallBuilder* _this, cx_string name, Fast_Expression arguments, Fast_Expression instance, cx_object scope, Fast_Block block);
void Fast_CallBuilder__update(Fast_CallBuilder* _this, cx_string name, Fast_Expression arguments, Fast_Expression instance, cx_object scope, Fast_Block block);
void Fast_CallBuilder__set(Fast_CallBuilder* _this, cx_string name, Fast_Expression arguments, Fast_Expression instance, cx_object scope, Fast_Block block);
cx_string Fast_CallBuilder__str(Fast_CallBuilder* value);
Fast_CallBuilder* Fast_CallBuilder__fromStr(Fast_CallBuilder* value, cx_string str);
cx_int16 Fast_CallBuilder__copy(Fast_CallBuilder* *dst, Fast_CallBuilder* src);
cx_int16 Fast_CallBuilder__compare(Fast_CallBuilder* dst, Fast_CallBuilder* src);

cx_int16 Fast_CallBuilder__init(Fast_CallBuilder* value);
cx_int16 Fast_CallBuilder__deinit(Fast_CallBuilder* value);

/* ::corto::Fast::Cast */
Fast_Cast Fast_Cast__create(cx_type lvalue, Fast_Expression rvalue, cx_bool isReference_1);
Fast_Cast Fast_Cast__createChild(cx_object _parent, cx_string _name, cx_type lvalue, Fast_Expression rvalue, cx_bool isReference_1);

Fast_Cast Fast_Cast__declare(void);
Fast_Cast Fast_Cast__declareChild(cx_object _parent, cx_string _name);
cx_int16 Fast_Cast__define(Fast_Cast _this, cx_type lvalue, Fast_Expression rvalue, cx_bool isReference_1);
void Fast_Cast__update(Fast_Cast _this, cx_type lvalue, Fast_Expression rvalue, cx_bool isReference_1);
void Fast_Cast__set(Fast_Cast _this, cx_type lvalue, Fast_Expression rvalue, cx_bool isReference_1);
cx_string Fast_Cast__str(Fast_Cast value);
Fast_Cast Fast_Cast__fromStr(Fast_Cast value, cx_string str);
cx_int16 Fast_Cast__copy(Fast_Cast *dst, Fast_Cast src);
cx_int16 Fast_Cast__compare(Fast_Cast dst, Fast_Cast src);

/* ::corto::Fast::Character */
Fast_Character Fast_Character__create(cx_char value);
Fast_Character Fast_Character__createChild(cx_object _parent, cx_string _name, cx_char value);

Fast_Character Fast_Character__declare(void);
Fast_Character Fast_Character__declareChild(cx_object _parent, cx_string _name);
cx_int16 Fast_Character__define(Fast_Character _this, cx_char value);
void Fast_Character__update(Fast_Character _this, cx_char value);
void Fast_Character__set(Fast_Character _this, cx_char value);
cx_string Fast_Character__str(Fast_Character value);
Fast_Character Fast_Character__fromStr(Fast_Character value, cx_string str);
cx_int16 Fast_Character__copy(Fast_Character *dst, Fast_Character src);
cx_int16 Fast_Character__compare(Fast_Character dst, Fast_Character src);

/* ::corto::Fast::Comma */
Fast_Comma Fast_Comma__create(void);
Fast_Comma Fast_Comma__createChild(cx_object _parent, cx_string _name);

Fast_Comma Fast_Comma__declare(void);
Fast_Comma Fast_Comma__declareChild(cx_object _parent, cx_string _name);
cx_int16 Fast_Comma__define(Fast_Comma _this);
void Fast_Comma__update(Fast_Comma _this);
void Fast_Comma__set(Fast_Comma _this);
cx_string Fast_Comma__str(Fast_Comma value);
Fast_Comma Fast_Comma__fromStr(Fast_Comma value, cx_string str);
cx_int16 Fast_Comma__copy(Fast_Comma *dst, Fast_Comma src);
cx_int16 Fast_Comma__compare(Fast_Comma dst, Fast_Comma src);

/* ::corto::Fast::Define */
Fast_Define Fast_Define__create(Fast_Expression object);
Fast_Define Fast_Define__createChild(cx_object _parent, cx_string _name, Fast_Expression object);

Fast_Define Fast_Define__declare(void);
Fast_Define Fast_Define__declareChild(cx_object _parent, cx_string _name);
cx_int16 Fast_Define__define(Fast_Define _this, Fast_Expression object);
void Fast_Define__update(Fast_Define _this, Fast_Expression object);
void Fast_Define__set(Fast_Define _this, Fast_Expression object);
cx_string Fast_Define__str(Fast_Define value);
Fast_Define Fast_Define__fromStr(Fast_Define value, cx_string str);
cx_int16 Fast_Define__copy(Fast_Define *dst, Fast_Define src);
cx_int16 Fast_Define__compare(Fast_Define dst, Fast_Define src);

/* ::corto::Fast::Deinit */
Fast_Deinit Fast_Deinit__create(Fast_Storage storage);
Fast_Deinit Fast_Deinit__createChild(cx_object _parent, cx_string _name, Fast_Storage storage);

Fast_Deinit Fast_Deinit__declare(void);
Fast_Deinit Fast_Deinit__declareChild(cx_object _parent, cx_string _name);
cx_int16 Fast_Deinit__define(Fast_Deinit _this, Fast_Storage storage);
void Fast_Deinit__update(Fast_Deinit _this, Fast_Storage storage);
void Fast_Deinit__set(Fast_Deinit _this, Fast_Storage storage);
cx_string Fast_Deinit__str(Fast_Deinit value);
Fast_Deinit Fast_Deinit__fromStr(Fast_Deinit value, cx_string str);
cx_int16 Fast_Deinit__copy(Fast_Deinit *dst, Fast_Deinit src);
cx_int16 Fast_Deinit__compare(Fast_Deinit dst, Fast_Deinit src);

/* ::corto::Fast::DelegateCall */
Fast_DelegateCall Fast_DelegateCall__create(Fast_Expression instanceExpr, Fast_Expression arguments, Fast_Expression expr);
Fast_DelegateCall Fast_DelegateCall__createChild(cx_object _parent, cx_string _name, Fast_Expression instanceExpr, Fast_Expression arguments, Fast_Expression expr);

Fast_DelegateCall Fast_DelegateCall__declare(void);
Fast_DelegateCall Fast_DelegateCall__declareChild(cx_object _parent, cx_string _name);
cx_int16 Fast_DelegateCall__define(Fast_DelegateCall _this, Fast_Expression instanceExpr, Fast_Expression arguments, Fast_Expression expr);
void Fast_DelegateCall__update(Fast_DelegateCall _this, Fast_Expression instanceExpr, Fast_Expression arguments, Fast_Expression expr);
void Fast_DelegateCall__set(Fast_DelegateCall _this, Fast_Expression instanceExpr, Fast_Expression arguments, Fast_Expression expr);
cx_string Fast_DelegateCall__str(Fast_DelegateCall value);
Fast_DelegateCall Fast_DelegateCall__fromStr(Fast_DelegateCall value, cx_string str);
cx_int16 Fast_DelegateCall__copy(Fast_DelegateCall *dst, Fast_DelegateCall src);
cx_int16 Fast_DelegateCall__compare(Fast_DelegateCall dst, Fast_DelegateCall src);

/* ::corto::Fast::derefKind */
Fast_derefKind* Fast_derefKind__create(void);
Fast_derefKind* Fast_derefKind__createChild(cx_object _parent, cx_string _name);

Fast_derefKind* Fast_derefKind__declare(void);
Fast_derefKind* Fast_derefKind__declareChild(cx_object _parent, cx_string _name);
cx_int16 Fast_derefKind__define(Fast_derefKind* _this, Fast_derefKind value);
void Fast_derefKind__update(Fast_derefKind* _this, Fast_derefKind value);
void Fast_derefKind__set(Fast_derefKind* _this, Fast_derefKind value);
cx_string Fast_derefKind__str(Fast_derefKind value);
Fast_derefKind* Fast_derefKind__fromStr(Fast_derefKind* value, cx_string str);
cx_int16 Fast_derefKind__copy(Fast_derefKind* *dst, Fast_derefKind* src);
cx_int16 Fast_derefKind__compare(Fast_derefKind* dst, Fast_derefKind* src);

cx_int16 Fast_derefKind__init(Fast_derefKind* value);
cx_int16 Fast_derefKind__deinit(Fast_derefKind* value);

/* ::corto::Fast::DynamicInitializer */
Fast_DynamicInitializer Fast_DynamicInitializer__create(Fast_InitializerVariable_array64 variables, cx_uint8 variableCount, cx_bool assignValue);
Fast_DynamicInitializer Fast_DynamicInitializer__createChild(cx_object _parent, cx_string _name, Fast_InitializerVariable_array64 variables, cx_uint8 variableCount, cx_bool assignValue);

Fast_DynamicInitializer Fast_DynamicInitializer__declare(void);
Fast_DynamicInitializer Fast_DynamicInitializer__declareChild(cx_object _parent, cx_string _name);
cx_int16 Fast_DynamicInitializer__define(Fast_DynamicInitializer _this, Fast_InitializerVariable_array64 variables, cx_uint8 variableCount, cx_bool assignValue);
void Fast_DynamicInitializer__update(Fast_DynamicInitializer _this, Fast_InitializerVariable_array64 variables, cx_uint8 variableCount, cx_bool assignValue);
void Fast_DynamicInitializer__set(Fast_DynamicInitializer _this, Fast_InitializerVariable_array64 variables, cx_uint8 variableCount, cx_bool assignValue);
cx_string Fast_DynamicInitializer__str(Fast_DynamicInitializer value);
Fast_DynamicInitializer Fast_DynamicInitializer__fromStr(Fast_DynamicInitializer value, cx_string str);
cx_int16 Fast_DynamicInitializer__copy(Fast_DynamicInitializer *dst, Fast_DynamicInitializer src);
cx_int16 Fast_DynamicInitializer__compare(Fast_DynamicInitializer dst, Fast_DynamicInitializer src);

/* ::corto::Fast::DynamicInitializerFrame */
Fast_DynamicInitializerFrame* Fast_DynamicInitializerFrame__create(Fast_Expression_array64 expr, Fast_Expression_array64 keyExpr, Fast_Integer sequenceSize);
Fast_DynamicInitializerFrame* Fast_DynamicInitializerFrame__createChild(cx_object _parent, cx_string _name, Fast_Expression_array64 expr, Fast_Expression_array64 keyExpr, Fast_Integer sequenceSize);

Fast_DynamicInitializerFrame* Fast_DynamicInitializerFrame__declare(void);
Fast_DynamicInitializerFrame* Fast_DynamicInitializerFrame__declareChild(cx_object _parent, cx_string _name);
cx_int16 Fast_DynamicInitializerFrame__define(Fast_DynamicInitializerFrame* _this, Fast_Expression_array64 expr, Fast_Expression_array64 keyExpr, Fast_Integer sequenceSize);
void Fast_DynamicInitializerFrame__update(Fast_DynamicInitializerFrame* _this, Fast_Expression_array64 expr, Fast_Expression_array64 keyExpr, Fast_Integer sequenceSize);
void Fast_DynamicInitializerFrame__set(Fast_DynamicInitializerFrame* _this, Fast_Expression_array64 expr, Fast_Expression_array64 keyExpr, Fast_Integer sequenceSize);
cx_string Fast_DynamicInitializerFrame__str(Fast_DynamicInitializerFrame* value);
Fast_DynamicInitializerFrame* Fast_DynamicInitializerFrame__fromStr(Fast_DynamicInitializerFrame* value, cx_string str);
cx_int16 Fast_DynamicInitializerFrame__copy(Fast_DynamicInitializerFrame* *dst, Fast_DynamicInitializerFrame* src);
cx_int16 Fast_DynamicInitializerFrame__compare(Fast_DynamicInitializerFrame* dst, Fast_DynamicInitializerFrame* src);

cx_int16 Fast_DynamicInitializerFrame__init(Fast_DynamicInitializerFrame* value);
cx_int16 Fast_DynamicInitializerFrame__deinit(Fast_DynamicInitializerFrame* value);

/* ::corto::Fast::Element */
Fast_Element Fast_Element__create(Fast_Expression lvalue, Fast_Expression rvalue);
Fast_Element Fast_Element__createChild(cx_object _parent, cx_string _name, Fast_Expression lvalue, Fast_Expression rvalue);

Fast_Element Fast_Element__declare(void);
Fast_Element Fast_Element__declareChild(cx_object _parent, cx_string _name);
cx_int16 Fast_Element__define(Fast_Element _this, Fast_Expression lvalue, Fast_Expression rvalue);
void Fast_Element__update(Fast_Element _this, Fast_Expression lvalue, Fast_Expression rvalue);
void Fast_Element__set(Fast_Element _this, Fast_Expression lvalue, Fast_Expression rvalue);
cx_string Fast_Element__str(Fast_Element value);
Fast_Element Fast_Element__fromStr(Fast_Element value, cx_string str);
cx_int16 Fast_Element__copy(Fast_Element *dst, Fast_Element src);
cx_int16 Fast_Element__compare(Fast_Element dst, Fast_Element src);

/* ::corto::Fast::Expression */
Fast_Expression Fast_Expression__create(Fast_nodeKind kind);
Fast_Expression Fast_Expression__createChild(cx_object _parent, cx_string _name, Fast_nodeKind kind);

Fast_Expression Fast_Expression__declare(void);
Fast_Expression Fast_Expression__declareChild(cx_object _parent, cx_string _name);
cx_int16 Fast_Expression__define(Fast_Expression _this, Fast_nodeKind kind);
void Fast_Expression__update(Fast_Expression _this, Fast_nodeKind kind);
void Fast_Expression__set(Fast_Expression _this, Fast_nodeKind kind);
cx_string Fast_Expression__str(Fast_Expression value);
Fast_Expression Fast_Expression__fromStr(Fast_Expression value, cx_string str);
cx_int16 Fast_Expression__copy(Fast_Expression *dst, Fast_Expression src);
cx_int16 Fast_Expression__compare(Fast_Expression dst, Fast_Expression src);

/* ::corto::Fast::FloatingPoint */
Fast_FloatingPoint Fast_FloatingPoint__create(cx_float64 value);
Fast_FloatingPoint Fast_FloatingPoint__createChild(cx_object _parent, cx_string _name, cx_float64 value);

Fast_FloatingPoint Fast_FloatingPoint__declare(void);
Fast_FloatingPoint Fast_FloatingPoint__declareChild(cx_object _parent, cx_string _name);
cx_int16 Fast_FloatingPoint__define(Fast_FloatingPoint _this, cx_float64 value);
void Fast_FloatingPoint__update(Fast_FloatingPoint _this, cx_float64 value);
void Fast_FloatingPoint__set(Fast_FloatingPoint _this, cx_float64 value);
cx_string Fast_FloatingPoint__str(Fast_FloatingPoint value);
Fast_FloatingPoint Fast_FloatingPoint__fromStr(Fast_FloatingPoint value, cx_string str);
cx_int16 Fast_FloatingPoint__copy(Fast_FloatingPoint *dst, Fast_FloatingPoint src);
cx_int16 Fast_FloatingPoint__compare(Fast_FloatingPoint dst, Fast_FloatingPoint src);

/* ::corto::Fast::If */
Fast_If Fast_If__create(Fast_Expression condition, Fast_Block trueBranch, Fast_If falseBranch);
Fast_If Fast_If__createChild(cx_object _parent, cx_string _name, Fast_Expression condition, Fast_Block trueBranch, Fast_If falseBranch);

Fast_If Fast_If__declare(void);
Fast_If Fast_If__declareChild(cx_object _parent, cx_string _name);
cx_int16 Fast_If__define(Fast_If _this, Fast_Expression condition, Fast_Block trueBranch, Fast_If falseBranch);
void Fast_If__update(Fast_If _this, Fast_Expression condition, Fast_Block trueBranch, Fast_If falseBranch);
void Fast_If__set(Fast_If _this, Fast_Expression condition, Fast_Block trueBranch, Fast_If falseBranch);
cx_string Fast_If__str(Fast_If value);
Fast_If Fast_If__fromStr(Fast_If value, cx_string str);
cx_int16 Fast_If__copy(Fast_If *dst, Fast_If src);
cx_int16 Fast_If__compare(Fast_If dst, Fast_If src);

/* ::corto::Fast::Init */
Fast_Init Fast_Init__create(Fast_Storage storage);
Fast_Init Fast_Init__createChild(cx_object _parent, cx_string _name, Fast_Storage storage);

Fast_Init Fast_Init__declare(void);
Fast_Init Fast_Init__declareChild(cx_object _parent, cx_string _name);
cx_int16 Fast_Init__define(Fast_Init _this, Fast_Storage storage);
void Fast_Init__update(Fast_Init _this, Fast_Storage storage);
void Fast_Init__set(Fast_Init _this, Fast_Storage storage);
cx_string Fast_Init__str(Fast_Init value);
Fast_Init Fast_Init__fromStr(Fast_Init value, cx_string str);
cx_int16 Fast_Init__copy(Fast_Init *dst, Fast_Init src);
cx_int16 Fast_Init__compare(Fast_Init dst, Fast_Init src);

/* ::corto::Fast::Initializer */
Fast_Initializer Fast_Initializer__create(Fast_InitializerVariable_array64 variables, cx_uint8 variableCount);
Fast_Initializer Fast_Initializer__createChild(cx_object _parent, cx_string _name, Fast_InitializerVariable_array64 variables, cx_uint8 variableCount);

Fast_Initializer Fast_Initializer__declare(void);
Fast_Initializer Fast_Initializer__declareChild(cx_object _parent, cx_string _name);
cx_int16 Fast_Initializer__define(Fast_Initializer _this, Fast_InitializerVariable_array64 variables, cx_uint8 variableCount);
void Fast_Initializer__update(Fast_Initializer _this, Fast_InitializerVariable_array64 variables, cx_uint8 variableCount);
void Fast_Initializer__set(Fast_Initializer _this, Fast_InitializerVariable_array64 variables, cx_uint8 variableCount);
cx_string Fast_Initializer__str(Fast_Initializer value);
Fast_Initializer Fast_Initializer__fromStr(Fast_Initializer value, cx_string str);
cx_int16 Fast_Initializer__copy(Fast_Initializer *dst, Fast_Initializer src);
cx_int16 Fast_Initializer__compare(Fast_Initializer dst, Fast_Initializer src);

/* ::corto::Fast::InitializerExpression */
Fast_InitializerExpression Fast_InitializerExpression__create(Fast_InitializerVariable_array64 variables, cx_uint8 variableCount, cx_bool assignValue);
Fast_InitializerExpression Fast_InitializerExpression__createChild(cx_object _parent, cx_string _name, Fast_InitializerVariable_array64 variables, cx_uint8 variableCount, cx_bool assignValue);

Fast_InitializerExpression Fast_InitializerExpression__declare(void);
Fast_InitializerExpression Fast_InitializerExpression__declareChild(cx_object _parent, cx_string _name);
cx_int16 Fast_InitializerExpression__define(Fast_InitializerExpression _this, Fast_InitializerVariable_array64 variables, cx_uint8 variableCount, cx_bool assignValue);
void Fast_InitializerExpression__update(Fast_InitializerExpression _this, Fast_InitializerVariable_array64 variables, cx_uint8 variableCount, cx_bool assignValue);
void Fast_InitializerExpression__set(Fast_InitializerExpression _this, Fast_InitializerVariable_array64 variables, cx_uint8 variableCount, cx_bool assignValue);
cx_string Fast_InitializerExpression__str(Fast_InitializerExpression value);
Fast_InitializerExpression Fast_InitializerExpression__fromStr(Fast_InitializerExpression value, cx_string str);
cx_int16 Fast_InitializerExpression__copy(Fast_InitializerExpression *dst, Fast_InitializerExpression src);
cx_int16 Fast_InitializerExpression__compare(Fast_InitializerExpression dst, Fast_InitializerExpression src);

/* ::corto::Fast::InitializerFrame */
Fast_InitializerFrame* Fast_InitializerFrame__create(cx_uint32 location, cx_type type, cx_bool isKey, cx_member member);
Fast_InitializerFrame* Fast_InitializerFrame__createChild(cx_object _parent, cx_string _name, cx_uint32 location, cx_type type, cx_bool isKey, cx_member member);

Fast_InitializerFrame* Fast_InitializerFrame__declare(void);
Fast_InitializerFrame* Fast_InitializerFrame__declareChild(cx_object _parent, cx_string _name);
cx_int16 Fast_InitializerFrame__define(Fast_InitializerFrame* _this, cx_uint32 location, cx_type type, cx_bool isKey, cx_member member);
void Fast_InitializerFrame__update(Fast_InitializerFrame* _this, cx_uint32 location, cx_type type, cx_bool isKey, cx_member member);
void Fast_InitializerFrame__set(Fast_InitializerFrame* _this, cx_uint32 location, cx_type type, cx_bool isKey, cx_member member);
cx_string Fast_InitializerFrame__str(Fast_InitializerFrame* value);
Fast_InitializerFrame* Fast_InitializerFrame__fromStr(Fast_InitializerFrame* value, cx_string str);
cx_int16 Fast_InitializerFrame__copy(Fast_InitializerFrame* *dst, Fast_InitializerFrame* src);
cx_int16 Fast_InitializerFrame__compare(Fast_InitializerFrame* dst, Fast_InitializerFrame* src);

cx_int16 Fast_InitializerFrame__init(Fast_InitializerFrame* value);
cx_int16 Fast_InitializerFrame__deinit(Fast_InitializerFrame* value);

/* ::corto::Fast::InitializerKind */
Fast_InitializerKind* Fast_InitializerKind__create(void);
Fast_InitializerKind* Fast_InitializerKind__createChild(cx_object _parent, cx_string _name);

Fast_InitializerKind* Fast_InitializerKind__declare(void);
Fast_InitializerKind* Fast_InitializerKind__declareChild(cx_object _parent, cx_string _name);
cx_int16 Fast_InitializerKind__define(Fast_InitializerKind* _this, Fast_InitializerKind value);
void Fast_InitializerKind__update(Fast_InitializerKind* _this, Fast_InitializerKind value);
void Fast_InitializerKind__set(Fast_InitializerKind* _this, Fast_InitializerKind value);
cx_string Fast_InitializerKind__str(Fast_InitializerKind value);
Fast_InitializerKind* Fast_InitializerKind__fromStr(Fast_InitializerKind* value, cx_string str);
cx_int16 Fast_InitializerKind__copy(Fast_InitializerKind* *dst, Fast_InitializerKind* src);
cx_int16 Fast_InitializerKind__compare(Fast_InitializerKind* dst, Fast_InitializerKind* src);

cx_int16 Fast_InitializerKind__init(Fast_InitializerKind* value);
cx_int16 Fast_InitializerKind__deinit(Fast_InitializerKind* value);

/* ::corto::Fast::InitializerVariable */
Fast_InitializerVariable* Fast_InitializerVariable__create(cx_word offset, Fast_Expression object, cx_word key);
Fast_InitializerVariable* Fast_InitializerVariable__createChild(cx_object _parent, cx_string _name, cx_word offset, Fast_Expression object, cx_word key);

Fast_InitializerVariable* Fast_InitializerVariable__declare(void);
Fast_InitializerVariable* Fast_InitializerVariable__declareChild(cx_object _parent, cx_string _name);
cx_int16 Fast_InitializerVariable__define(Fast_InitializerVariable* _this, cx_word offset, Fast_Expression object, cx_word key);
void Fast_InitializerVariable__update(Fast_InitializerVariable* _this, cx_word offset, Fast_Expression object, cx_word key);
void Fast_InitializerVariable__set(Fast_InitializerVariable* _this, cx_word offset, Fast_Expression object, cx_word key);
cx_string Fast_InitializerVariable__str(Fast_InitializerVariable* value);
Fast_InitializerVariable* Fast_InitializerVariable__fromStr(Fast_InitializerVariable* value, cx_string str);
cx_int16 Fast_InitializerVariable__copy(Fast_InitializerVariable* *dst, Fast_InitializerVariable* src);
cx_int16 Fast_InitializerVariable__compare(Fast_InitializerVariable* dst, Fast_InitializerVariable* src);

cx_int16 Fast_InitializerVariable__init(Fast_InitializerVariable* value);
cx_int16 Fast_InitializerVariable__deinit(Fast_InitializerVariable* value);

/* ::corto::Fast::InitOper */
Fast_InitOper* Fast_InitOper__create(Fast_InitOperKind kind, Fast_Expression expr, cx_string name);
Fast_InitOper* Fast_InitOper__createChild(cx_object _parent, cx_string _name, Fast_InitOperKind kind, Fast_Expression expr, cx_string name);

Fast_InitOper* Fast_InitOper__declare(void);
Fast_InitOper* Fast_InitOper__declareChild(cx_object _parent, cx_string _name);
cx_int16 Fast_InitOper__define(Fast_InitOper* _this, Fast_InitOperKind kind, Fast_Expression expr, cx_string name);
void Fast_InitOper__update(Fast_InitOper* _this, Fast_InitOperKind kind, Fast_Expression expr, cx_string name);
void Fast_InitOper__set(Fast_InitOper* _this, Fast_InitOperKind kind, Fast_Expression expr, cx_string name);
cx_string Fast_InitOper__str(Fast_InitOper* value);
Fast_InitOper* Fast_InitOper__fromStr(Fast_InitOper* value, cx_string str);
cx_int16 Fast_InitOper__copy(Fast_InitOper* *dst, Fast_InitOper* src);
cx_int16 Fast_InitOper__compare(Fast_InitOper* dst, Fast_InitOper* src);

cx_int16 Fast_InitOper__init(Fast_InitOper* value);
cx_int16 Fast_InitOper__deinit(Fast_InitOper* value);

/* ::corto::Fast::InitOperKind */
Fast_InitOperKind* Fast_InitOperKind__create(void);
Fast_InitOperKind* Fast_InitOperKind__createChild(cx_object _parent, cx_string _name);

Fast_InitOperKind* Fast_InitOperKind__declare(void);
Fast_InitOperKind* Fast_InitOperKind__declareChild(cx_object _parent, cx_string _name);
cx_int16 Fast_InitOperKind__define(Fast_InitOperKind* _this, Fast_InitOperKind value);
void Fast_InitOperKind__update(Fast_InitOperKind* _this, Fast_InitOperKind value);
void Fast_InitOperKind__set(Fast_InitOperKind* _this, Fast_InitOperKind value);
cx_string Fast_InitOperKind__str(Fast_InitOperKind value);
Fast_InitOperKind* Fast_InitOperKind__fromStr(Fast_InitOperKind* value, cx_string str);
cx_int16 Fast_InitOperKind__copy(Fast_InitOperKind* *dst, Fast_InitOperKind* src);
cx_int16 Fast_InitOperKind__compare(Fast_InitOperKind* dst, Fast_InitOperKind* src);

cx_int16 Fast_InitOperKind__init(Fast_InitOperKind* value);
cx_int16 Fast_InitOperKind__deinit(Fast_InitOperKind* value);

/* ::corto::Fast::Integer */
Fast_Integer Fast_Integer__create(cx_uint64 value);
Fast_Integer Fast_Integer__createChild(cx_object _parent, cx_string _name, cx_uint64 value);

Fast_Integer Fast_Integer__declare(void);
Fast_Integer Fast_Integer__declareChild(cx_object _parent, cx_string _name);
cx_int16 Fast_Integer__define(Fast_Integer _this, cx_uint64 value);
void Fast_Integer__update(Fast_Integer _this, cx_uint64 value);
void Fast_Integer__set(Fast_Integer _this, cx_uint64 value);
cx_string Fast_Integer__str(Fast_Integer value);
Fast_Integer Fast_Integer__fromStr(Fast_Integer value, cx_string str);
cx_int16 Fast_Integer__copy(Fast_Integer *dst, Fast_Integer src);
cx_int16 Fast_Integer__compare(Fast_Integer dst, Fast_Integer src);

/* ::corto::Fast::Literal */
Fast_Literal Fast_Literal__create(Fast_valueKind kind_1);
Fast_Literal Fast_Literal__createChild(cx_object _parent, cx_string _name, Fast_valueKind kind_1);

Fast_Literal Fast_Literal__declare(void);
Fast_Literal Fast_Literal__declareChild(cx_object _parent, cx_string _name);
cx_int16 Fast_Literal__define(Fast_Literal _this, Fast_valueKind kind_1);
void Fast_Literal__update(Fast_Literal _this, Fast_valueKind kind_1);
void Fast_Literal__set(Fast_Literal _this, Fast_valueKind kind_1);
cx_string Fast_Literal__str(Fast_Literal value);
Fast_Literal Fast_Literal__fromStr(Fast_Literal value, cx_string str);
cx_int16 Fast_Literal__copy(Fast_Literal *dst, Fast_Literal src);
cx_int16 Fast_Literal__compare(Fast_Literal dst, Fast_Literal src);

/* ::corto::Fast::Local */
Fast_Local Fast_Local__create(cx_string name, cx_type type_1, Fast_LocalKind kind_2, cx_bool reference);
Fast_Local Fast_Local__createChild(cx_object _parent, cx_string _name, cx_string name, cx_type type_1, Fast_LocalKind kind_2, cx_bool reference);

Fast_Local Fast_Local__declare(void);
Fast_Local Fast_Local__declareChild(cx_object _parent, cx_string _name);
cx_int16 Fast_Local__define(Fast_Local _this, cx_string name, cx_type type_1, Fast_LocalKind kind_2, cx_bool reference);
void Fast_Local__update(Fast_Local _this, cx_string name, cx_type type_1, Fast_LocalKind kind_2, cx_bool reference);
void Fast_Local__set(Fast_Local _this, cx_string name, cx_type type_1, Fast_LocalKind kind_2, cx_bool reference);
cx_string Fast_Local__str(Fast_Local value);
Fast_Local Fast_Local__fromStr(Fast_Local value, cx_string str);
cx_int16 Fast_Local__copy(Fast_Local *dst, Fast_Local src);
cx_int16 Fast_Local__compare(Fast_Local dst, Fast_Local src);

/* ::corto::Fast::LocalKind */
Fast_LocalKind* Fast_LocalKind__create(void);
Fast_LocalKind* Fast_LocalKind__createChild(cx_object _parent, cx_string _name);

Fast_LocalKind* Fast_LocalKind__declare(void);
Fast_LocalKind* Fast_LocalKind__declareChild(cx_object _parent, cx_string _name);
cx_int16 Fast_LocalKind__define(Fast_LocalKind* _this, Fast_LocalKind value);
void Fast_LocalKind__update(Fast_LocalKind* _this, Fast_LocalKind value);
void Fast_LocalKind__set(Fast_LocalKind* _this, Fast_LocalKind value);
cx_string Fast_LocalKind__str(Fast_LocalKind value);
Fast_LocalKind* Fast_LocalKind__fromStr(Fast_LocalKind* value, cx_string str);
cx_int16 Fast_LocalKind__copy(Fast_LocalKind* *dst, Fast_LocalKind* src);
cx_int16 Fast_LocalKind__compare(Fast_LocalKind* dst, Fast_LocalKind* src);

cx_int16 Fast_LocalKind__init(Fast_LocalKind* value);
cx_int16 Fast_LocalKind__deinit(Fast_LocalKind* value);

/* ::corto::Fast::Lvalue */
Fast_Lvalue* Fast_Lvalue__create(Fast_Expression expr, cx_bool isAssignment);
Fast_Lvalue* Fast_Lvalue__createChild(cx_object _parent, cx_string _name, Fast_Expression expr, cx_bool isAssignment);

Fast_Lvalue* Fast_Lvalue__declare(void);
Fast_Lvalue* Fast_Lvalue__declareChild(cx_object _parent, cx_string _name);
cx_int16 Fast_Lvalue__define(Fast_Lvalue* _this, Fast_Expression expr, cx_bool isAssignment);
void Fast_Lvalue__update(Fast_Lvalue* _this, Fast_Expression expr, cx_bool isAssignment);
void Fast_Lvalue__set(Fast_Lvalue* _this, Fast_Expression expr, cx_bool isAssignment);
cx_string Fast_Lvalue__str(Fast_Lvalue* value);
Fast_Lvalue* Fast_Lvalue__fromStr(Fast_Lvalue* value, cx_string str);
cx_int16 Fast_Lvalue__copy(Fast_Lvalue* *dst, Fast_Lvalue* src);
cx_int16 Fast_Lvalue__compare(Fast_Lvalue* dst, Fast_Lvalue* src);

cx_int16 Fast_Lvalue__init(Fast_Lvalue* value);
cx_int16 Fast_Lvalue__deinit(Fast_Lvalue* value);

/* ::corto::Fast::Member */
Fast_Member Fast_Member__create(Fast_Expression lvalue, Fast_Expression rvalue);
Fast_Member Fast_Member__createChild(cx_object _parent, cx_string _name, Fast_Expression lvalue, Fast_Expression rvalue);

Fast_Member Fast_Member__declare(void);
Fast_Member Fast_Member__declareChild(cx_object _parent, cx_string _name);
cx_int16 Fast_Member__define(Fast_Member _this, Fast_Expression lvalue, Fast_Expression rvalue);
void Fast_Member__update(Fast_Member _this, Fast_Expression lvalue, Fast_Expression rvalue);
void Fast_Member__set(Fast_Member _this, Fast_Expression lvalue, Fast_Expression rvalue);
cx_string Fast_Member__str(Fast_Member value);
Fast_Member Fast_Member__fromStr(Fast_Member value, cx_string str);
cx_int16 Fast_Member__copy(Fast_Member *dst, Fast_Member src);
cx_int16 Fast_Member__compare(Fast_Member dst, Fast_Member src);

/* ::corto::Fast::New */
Fast_New Fast_New__create(cx_type type_1, Fast_Expression attributes);
Fast_New Fast_New__createChild(cx_object _parent, cx_string _name, cx_type type_1, Fast_Expression attributes);

Fast_New Fast_New__declare(void);
Fast_New Fast_New__declareChild(cx_object _parent, cx_string _name);
cx_int16 Fast_New__define(Fast_New _this, cx_type type_1, Fast_Expression attributes);
void Fast_New__update(Fast_New _this, cx_type type_1, Fast_Expression attributes);
void Fast_New__set(Fast_New _this, cx_type type_1, Fast_Expression attributes);
cx_string Fast_New__str(Fast_New value);
Fast_New Fast_New__fromStr(Fast_New value, cx_string str);
cx_int16 Fast_New__copy(Fast_New *dst, Fast_New src);
cx_int16 Fast_New__compare(Fast_New dst, Fast_New src);

/* ::corto::Fast::Node */
Fast_Node Fast_Node__create(Fast_nodeKind kind);
Fast_Node Fast_Node__createChild(cx_object _parent, cx_string _name, Fast_nodeKind kind);

Fast_Node Fast_Node__declare(void);
Fast_Node Fast_Node__declareChild(cx_object _parent, cx_string _name);
cx_int16 Fast_Node__define(Fast_Node _this, Fast_nodeKind kind);
void Fast_Node__update(Fast_Node _this, Fast_nodeKind kind);
void Fast_Node__set(Fast_Node _this, Fast_nodeKind kind);
cx_string Fast_Node__str(Fast_Node value);
Fast_Node Fast_Node__fromStr(Fast_Node value, cx_string str);
cx_int16 Fast_Node__copy(Fast_Node *dst, Fast_Node src);
cx_int16 Fast_Node__compare(Fast_Node dst, Fast_Node src);

/* ::corto::Fast::nodeKind */
Fast_nodeKind* Fast_nodeKind__create(void);
Fast_nodeKind* Fast_nodeKind__createChild(cx_object _parent, cx_string _name);

Fast_nodeKind* Fast_nodeKind__declare(void);
Fast_nodeKind* Fast_nodeKind__declareChild(cx_object _parent, cx_string _name);
cx_int16 Fast_nodeKind__define(Fast_nodeKind* _this, Fast_nodeKind value);
void Fast_nodeKind__update(Fast_nodeKind* _this, Fast_nodeKind value);
void Fast_nodeKind__set(Fast_nodeKind* _this, Fast_nodeKind value);
cx_string Fast_nodeKind__str(Fast_nodeKind value);
Fast_nodeKind* Fast_nodeKind__fromStr(Fast_nodeKind* value, cx_string str);
cx_int16 Fast_nodeKind__copy(Fast_nodeKind* *dst, Fast_nodeKind* src);
cx_int16 Fast_nodeKind__compare(Fast_nodeKind* dst, Fast_nodeKind* src);

cx_int16 Fast_nodeKind__init(Fast_nodeKind* value);
cx_int16 Fast_nodeKind__deinit(Fast_nodeKind* value);

/* ::corto::Fast::Null */
Fast_Null Fast_Null__create(void);
Fast_Null Fast_Null__createChild(cx_object _parent, cx_string _name);

Fast_Null Fast_Null__declare(void);
Fast_Null Fast_Null__declareChild(cx_object _parent, cx_string _name);
cx_int16 Fast_Null__define(Fast_Null _this);
void Fast_Null__update(Fast_Null _this);
void Fast_Null__set(Fast_Null _this);
cx_string Fast_Null__str(Fast_Null value);
Fast_Null Fast_Null__fromStr(Fast_Null value, cx_string str);
cx_int16 Fast_Null__copy(Fast_Null *dst, Fast_Null src);
cx_int16 Fast_Null__compare(Fast_Null dst, Fast_Null src);

/* ::corto::Fast::Object */
Fast_Object Fast_Object__create(cx_object value);
Fast_Object Fast_Object__createChild(cx_object _parent, cx_string _name, cx_object value);

Fast_Object Fast_Object__declare(void);
Fast_Object Fast_Object__declareChild(cx_object _parent, cx_string _name);
cx_int16 Fast_Object__define(Fast_Object _this, cx_object value);
void Fast_Object__update(Fast_Object _this, cx_object value);
void Fast_Object__set(Fast_Object _this, cx_object value);
cx_string Fast_Object__str(Fast_Object value);
Fast_Object Fast_Object__fromStr(Fast_Object value, cx_string str);
cx_int16 Fast_Object__copy(Fast_Object *dst, Fast_Object src);
cx_int16 Fast_Object__compare(Fast_Object dst, Fast_Object src);

/* ::corto::Fast::Parser */
Fast_Parser Fast_Parser__create(cx_string source, cx_string filename);
Fast_Parser Fast_Parser__createChild(cx_object _parent, cx_string _name, cx_string source, cx_string filename);

Fast_Parser Fast_Parser__declare(void);
Fast_Parser Fast_Parser__declareChild(cx_object _parent, cx_string _name);
cx_int16 Fast_Parser__define(Fast_Parser _this, cx_string source, cx_string filename);
void Fast_Parser__update(Fast_Parser _this, cx_string source, cx_string filename);
void Fast_Parser__set(Fast_Parser _this, cx_string source, cx_string filename);
cx_string Fast_Parser__str(Fast_Parser value);
Fast_Parser Fast_Parser__fromStr(Fast_Parser value, cx_string str);
cx_int16 Fast_Parser__copy(Fast_Parser *dst, Fast_Parser src);
cx_int16 Fast_Parser__compare(Fast_Parser dst, Fast_Parser src);

/* ::corto::Fast::Parser::stagedId */
Fast_Parser_stagedId* Fast_Parser_stagedId__create(cx_string name, cx_bool found, cx_uint32 line, cx_uint32 column);
Fast_Parser_stagedId* Fast_Parser_stagedId__createChild(cx_object _parent, cx_string _name, cx_string name, cx_bool found, cx_uint32 line, cx_uint32 column);

Fast_Parser_stagedId* Fast_Parser_stagedId__declare(void);
Fast_Parser_stagedId* Fast_Parser_stagedId__declareChild(cx_object _parent, cx_string _name);
cx_int16 Fast_Parser_stagedId__define(Fast_Parser_stagedId* _this, cx_string name, cx_bool found, cx_uint32 line, cx_uint32 column);
void Fast_Parser_stagedId__update(Fast_Parser_stagedId* _this, cx_string name, cx_bool found, cx_uint32 line, cx_uint32 column);
void Fast_Parser_stagedId__set(Fast_Parser_stagedId* _this, cx_string name, cx_bool found, cx_uint32 line, cx_uint32 column);
cx_string Fast_Parser_stagedId__str(Fast_Parser_stagedId* value);
Fast_Parser_stagedId* Fast_Parser_stagedId__fromStr(Fast_Parser_stagedId* value, cx_string str);
cx_int16 Fast_Parser_stagedId__copy(Fast_Parser_stagedId* *dst, Fast_Parser_stagedId* src);
cx_int16 Fast_Parser_stagedId__compare(Fast_Parser_stagedId* dst, Fast_Parser_stagedId* src);

cx_int16 Fast_Parser_stagedId__init(Fast_Parser_stagedId* value);
cx_int16 Fast_Parser_stagedId__deinit(Fast_Parser_stagedId* value);

/* ::corto::Fast::ParserDeclaration */
Fast_ParserDeclaration* Fast_ParserDeclaration__create(cx_string name, Fast_Storage storage);
Fast_ParserDeclaration* Fast_ParserDeclaration__createChild(cx_object _parent, cx_string _name, cx_string name, Fast_Storage storage);

Fast_ParserDeclaration* Fast_ParserDeclaration__declare(void);
Fast_ParserDeclaration* Fast_ParserDeclaration__declareChild(cx_object _parent, cx_string _name);
cx_int16 Fast_ParserDeclaration__define(Fast_ParserDeclaration* _this, cx_string name, Fast_Storage storage);
void Fast_ParserDeclaration__update(Fast_ParserDeclaration* _this, cx_string name, Fast_Storage storage);
void Fast_ParserDeclaration__set(Fast_ParserDeclaration* _this, cx_string name, Fast_Storage storage);
cx_string Fast_ParserDeclaration__str(Fast_ParserDeclaration* value);
Fast_ParserDeclaration* Fast_ParserDeclaration__fromStr(Fast_ParserDeclaration* value, cx_string str);
cx_int16 Fast_ParserDeclaration__copy(Fast_ParserDeclaration* *dst, Fast_ParserDeclaration* src);
cx_int16 Fast_ParserDeclaration__compare(Fast_ParserDeclaration* dst, Fast_ParserDeclaration* src);

cx_int16 Fast_ParserDeclaration__init(Fast_ParserDeclaration* value);
cx_int16 Fast_ParserDeclaration__deinit(Fast_ParserDeclaration* value);

/* ::corto::Fast::ParserDeclarationSeq */
Fast_ParserDeclarationSeq* Fast_ParserDeclarationSeq__create(void);
Fast_ParserDeclarationSeq* Fast_ParserDeclarationSeq__createChild(cx_object _parent, cx_string _name);

Fast_ParserDeclarationSeq* Fast_ParserDeclarationSeq__declare(void);
Fast_ParserDeclarationSeq* Fast_ParserDeclarationSeq__declareChild(cx_object _parent, cx_string _name);
cx_int16 Fast_ParserDeclarationSeq__define(Fast_ParserDeclarationSeq* _this, Fast_ParserDeclarationSeq value);
void Fast_ParserDeclarationSeq__update(Fast_ParserDeclarationSeq* _this, Fast_ParserDeclarationSeq value);
void Fast_ParserDeclarationSeq__set(Fast_ParserDeclarationSeq* _this, Fast_ParserDeclarationSeq value);
cx_string Fast_ParserDeclarationSeq__str(Fast_ParserDeclarationSeq value);
Fast_ParserDeclarationSeq* Fast_ParserDeclarationSeq__fromStr(Fast_ParserDeclarationSeq* value, cx_string str);
cx_int16 Fast_ParserDeclarationSeq__copy(Fast_ParserDeclarationSeq* *dst, Fast_ParserDeclarationSeq* src);
cx_int16 Fast_ParserDeclarationSeq__compare(Fast_ParserDeclarationSeq* dst, Fast_ParserDeclarationSeq* src);

cx_int16 Fast_ParserDeclarationSeq__init(Fast_ParserDeclarationSeq* value);
cx_int16 Fast_ParserDeclarationSeq__deinit(Fast_ParserDeclarationSeq* value);

/* ::corto::Fast::ParserNew */
Fast_ParserNew* Fast_ParserNew__create(Fast_nodeKind kind, Fast_Expression parent, Fast_Expression name, Fast_Expression attr);
Fast_ParserNew* Fast_ParserNew__createChild(cx_object _parent, cx_string _name, Fast_nodeKind kind, Fast_Expression parent, Fast_Expression name, Fast_Expression attr);

Fast_ParserNew* Fast_ParserNew__declare(void);
Fast_ParserNew* Fast_ParserNew__declareChild(cx_object _parent, cx_string _name);
cx_int16 Fast_ParserNew__define(Fast_ParserNew* _this, Fast_nodeKind kind, Fast_Expression parent, Fast_Expression name, Fast_Expression attr);
void Fast_ParserNew__update(Fast_ParserNew* _this, Fast_nodeKind kind, Fast_Expression parent, Fast_Expression name, Fast_Expression attr);
void Fast_ParserNew__set(Fast_ParserNew* _this, Fast_nodeKind kind, Fast_Expression parent, Fast_Expression name, Fast_Expression attr);
cx_string Fast_ParserNew__str(Fast_ParserNew* value);
Fast_ParserNew* Fast_ParserNew__fromStr(Fast_ParserNew* value, cx_string str);
cx_int16 Fast_ParserNew__copy(Fast_ParserNew* *dst, Fast_ParserNew* src);
cx_int16 Fast_ParserNew__compare(Fast_ParserNew* dst, Fast_ParserNew* src);

cx_int16 Fast_ParserNew__init(Fast_ParserNew* value);
cx_int16 Fast_ParserNew__deinit(Fast_ParserNew* value);

/* ::corto::Fast::PostFix */
Fast_PostFix Fast_PostFix__create(Fast_Expression lvalue, cx_operatorKind operator);
Fast_PostFix Fast_PostFix__createChild(cx_object _parent, cx_string _name, Fast_Expression lvalue, cx_operatorKind operator);

Fast_PostFix Fast_PostFix__declare(void);
Fast_PostFix Fast_PostFix__declareChild(cx_object _parent, cx_string _name);
cx_int16 Fast_PostFix__define(Fast_PostFix _this, Fast_Expression lvalue, cx_operatorKind operator);
void Fast_PostFix__update(Fast_PostFix _this, Fast_Expression lvalue, cx_operatorKind operator);
void Fast_PostFix__set(Fast_PostFix _this, Fast_Expression lvalue, cx_operatorKind operator);
cx_string Fast_PostFix__str(Fast_PostFix value);
Fast_PostFix Fast_PostFix__fromStr(Fast_PostFix value, cx_string str);
cx_int16 Fast_PostFix__copy(Fast_PostFix *dst, Fast_PostFix src);
cx_int16 Fast_PostFix__compare(Fast_PostFix dst, Fast_PostFix src);

/* ::corto::Fast::SignedInteger */
Fast_SignedInteger Fast_SignedInteger__create(cx_int64 value);
Fast_SignedInteger Fast_SignedInteger__createChild(cx_object _parent, cx_string _name, cx_int64 value);

Fast_SignedInteger Fast_SignedInteger__declare(void);
Fast_SignedInteger Fast_SignedInteger__declareChild(cx_object _parent, cx_string _name);
cx_int16 Fast_SignedInteger__define(Fast_SignedInteger _this, cx_int64 value);
void Fast_SignedInteger__update(Fast_SignedInteger _this, cx_int64 value);
void Fast_SignedInteger__set(Fast_SignedInteger _this, cx_int64 value);
cx_string Fast_SignedInteger__str(Fast_SignedInteger value);
Fast_SignedInteger Fast_SignedInteger__fromStr(Fast_SignedInteger value, cx_string str);
cx_int16 Fast_SignedInteger__copy(Fast_SignedInteger *dst, Fast_SignedInteger src);
cx_int16 Fast_SignedInteger__compare(Fast_SignedInteger dst, Fast_SignedInteger src);

/* ::corto::Fast::StaticCall */
Fast_StaticCall Fast_StaticCall__create(Fast_Expression instanceExpr, Fast_Expression arguments, cx_function function);
Fast_StaticCall Fast_StaticCall__createChild(cx_object _parent, cx_string _name, Fast_Expression instanceExpr, Fast_Expression arguments, cx_function function);

Fast_StaticCall Fast_StaticCall__declare(void);
Fast_StaticCall Fast_StaticCall__declareChild(cx_object _parent, cx_string _name);
cx_int16 Fast_StaticCall__define(Fast_StaticCall _this, Fast_Expression instanceExpr, Fast_Expression arguments, cx_function function);
void Fast_StaticCall__update(Fast_StaticCall _this, Fast_Expression instanceExpr, Fast_Expression arguments, cx_function function);
void Fast_StaticCall__set(Fast_StaticCall _this, Fast_Expression instanceExpr, Fast_Expression arguments, cx_function function);
cx_string Fast_StaticCall__str(Fast_StaticCall value);
Fast_StaticCall Fast_StaticCall__fromStr(Fast_StaticCall value, cx_string str);
cx_int16 Fast_StaticCall__copy(Fast_StaticCall *dst, Fast_StaticCall src);
cx_int16 Fast_StaticCall__compare(Fast_StaticCall dst, Fast_StaticCall src);

/* ::corto::Fast::StaticInitializer */
Fast_StaticInitializer Fast_StaticInitializer__create(Fast_InitializerVariable_array64 variables, cx_uint8 variableCount);
Fast_StaticInitializer Fast_StaticInitializer__createChild(cx_object _parent, cx_string _name, Fast_InitializerVariable_array64 variables, cx_uint8 variableCount);

Fast_StaticInitializer Fast_StaticInitializer__declare(void);
Fast_StaticInitializer Fast_StaticInitializer__declareChild(cx_object _parent, cx_string _name);
cx_int16 Fast_StaticInitializer__define(Fast_StaticInitializer _this, Fast_InitializerVariable_array64 variables, cx_uint8 variableCount);
void Fast_StaticInitializer__update(Fast_StaticInitializer _this, Fast_InitializerVariable_array64 variables, cx_uint8 variableCount);
void Fast_StaticInitializer__set(Fast_StaticInitializer _this, Fast_InitializerVariable_array64 variables, cx_uint8 variableCount);
cx_string Fast_StaticInitializer__str(Fast_StaticInitializer value);
Fast_StaticInitializer Fast_StaticInitializer__fromStr(Fast_StaticInitializer value, cx_string str);
cx_int16 Fast_StaticInitializer__copy(Fast_StaticInitializer *dst, Fast_StaticInitializer src);
cx_int16 Fast_StaticInitializer__compare(Fast_StaticInitializer dst, Fast_StaticInitializer src);

/* ::corto::Fast::StaticInitializerFrame */
Fast_StaticInitializerFrame* Fast_StaticInitializerFrame__create(cx_word_array64 ptr, cx_word_array64 keyPtr);
Fast_StaticInitializerFrame* Fast_StaticInitializerFrame__createChild(cx_object _parent, cx_string _name, cx_word_array64 ptr, cx_word_array64 keyPtr);

Fast_StaticInitializerFrame* Fast_StaticInitializerFrame__declare(void);
Fast_StaticInitializerFrame* Fast_StaticInitializerFrame__declareChild(cx_object _parent, cx_string _name);
cx_int16 Fast_StaticInitializerFrame__define(Fast_StaticInitializerFrame* _this, cx_word_array64 ptr, cx_word_array64 keyPtr);
void Fast_StaticInitializerFrame__update(Fast_StaticInitializerFrame* _this, cx_word_array64 ptr, cx_word_array64 keyPtr);
void Fast_StaticInitializerFrame__set(Fast_StaticInitializerFrame* _this, cx_word_array64 ptr, cx_word_array64 keyPtr);
cx_string Fast_StaticInitializerFrame__str(Fast_StaticInitializerFrame* value);
Fast_StaticInitializerFrame* Fast_StaticInitializerFrame__fromStr(Fast_StaticInitializerFrame* value, cx_string str);
cx_int16 Fast_StaticInitializerFrame__copy(Fast_StaticInitializerFrame* *dst, Fast_StaticInitializerFrame* src);
cx_int16 Fast_StaticInitializerFrame__compare(Fast_StaticInitializerFrame* dst, Fast_StaticInitializerFrame* src);

cx_int16 Fast_StaticInitializerFrame__init(Fast_StaticInitializerFrame* value);
cx_int16 Fast_StaticInitializerFrame__deinit(Fast_StaticInitializerFrame* value);

/* ::corto::Fast::Storage */
Fast_Storage Fast_Storage__create(Fast_storageKind kind_1);
Fast_Storage Fast_Storage__createChild(cx_object _parent, cx_string _name, Fast_storageKind kind_1);

Fast_Storage Fast_Storage__declare(void);
Fast_Storage Fast_Storage__declareChild(cx_object _parent, cx_string _name);
cx_int16 Fast_Storage__define(Fast_Storage _this, Fast_storageKind kind_1);
void Fast_Storage__update(Fast_Storage _this, Fast_storageKind kind_1);
void Fast_Storage__set(Fast_Storage _this, Fast_storageKind kind_1);
cx_string Fast_Storage__str(Fast_Storage value);
Fast_Storage Fast_Storage__fromStr(Fast_Storage value, cx_string str);
cx_int16 Fast_Storage__copy(Fast_Storage *dst, Fast_Storage src);
cx_int16 Fast_Storage__compare(Fast_Storage dst, Fast_Storage src);

/* ::corto::Fast::storageKind */
Fast_storageKind* Fast_storageKind__create(void);
Fast_storageKind* Fast_storageKind__createChild(cx_object _parent, cx_string _name);

Fast_storageKind* Fast_storageKind__declare(void);
Fast_storageKind* Fast_storageKind__declareChild(cx_object _parent, cx_string _name);
cx_int16 Fast_storageKind__define(Fast_storageKind* _this, Fast_storageKind value);
void Fast_storageKind__update(Fast_storageKind* _this, Fast_storageKind value);
void Fast_storageKind__set(Fast_storageKind* _this, Fast_storageKind value);
cx_string Fast_storageKind__str(Fast_storageKind value);
Fast_storageKind* Fast_storageKind__fromStr(Fast_storageKind* value, cx_string str);
cx_int16 Fast_storageKind__copy(Fast_storageKind* *dst, Fast_storageKind* src);
cx_int16 Fast_storageKind__compare(Fast_storageKind* dst, Fast_storageKind* src);

cx_int16 Fast_storageKind__init(Fast_storageKind* value);
cx_int16 Fast_storageKind__deinit(Fast_storageKind* value);

/* ::corto::Fast::String */
Fast_String Fast_String__create(cx_string value);
Fast_String Fast_String__createChild(cx_object _parent, cx_string _name, cx_string value);

Fast_String Fast_String__declare(void);
Fast_String Fast_String__declareChild(cx_object _parent, cx_string _name);
cx_int16 Fast_String__define(Fast_String _this, cx_string value);
void Fast_String__update(Fast_String _this, cx_string value);
void Fast_String__set(Fast_String _this, cx_string value);
cx_string Fast_String__str(Fast_String value);
Fast_String Fast_String__fromStr(Fast_String value, cx_string str);
cx_int16 Fast_String__copy(Fast_String *dst, Fast_String src);
cx_int16 Fast_String__compare(Fast_String dst, Fast_String src);

/* ::corto::Fast::Template */
Fast_Template Fast_Template__create(cx_string name, cx_type type_1, Fast_LocalKind kind_2, cx_bool reference);
Fast_Template Fast_Template__createChild(cx_object _parent, cx_string _name, cx_string name, cx_type type_1, Fast_LocalKind kind_2, cx_bool reference);

Fast_Template Fast_Template__declare(void);
Fast_Template Fast_Template__declareChild(cx_object _parent, cx_string _name);
cx_int16 Fast_Template__define(Fast_Template _this, cx_string name, cx_type type_1, Fast_LocalKind kind_2, cx_bool reference);
void Fast_Template__update(Fast_Template _this, cx_string name, cx_type type_1, Fast_LocalKind kind_2, cx_bool reference);
void Fast_Template__set(Fast_Template _this, cx_string name, cx_type type_1, Fast_LocalKind kind_2, cx_bool reference);
cx_string Fast_Template__str(Fast_Template value);
Fast_Template Fast_Template__fromStr(Fast_Template value, cx_string str);
cx_int16 Fast_Template__copy(Fast_Template *dst, Fast_Template src);
cx_int16 Fast_Template__compare(Fast_Template dst, Fast_Template src);

/* ::corto::Fast::Temporary */
Fast_Temporary Fast_Temporary__create(cx_type type_1, cx_bool reference);
Fast_Temporary Fast_Temporary__createChild(cx_object _parent, cx_string _name, cx_type type_1, cx_bool reference);

Fast_Temporary Fast_Temporary__declare(void);
Fast_Temporary Fast_Temporary__declareChild(cx_object _parent, cx_string _name);
cx_int16 Fast_Temporary__define(Fast_Temporary _this, cx_type type_1, cx_bool reference);
void Fast_Temporary__update(Fast_Temporary _this, cx_type type_1, cx_bool reference);
void Fast_Temporary__set(Fast_Temporary _this, cx_type type_1, cx_bool reference);
cx_string Fast_Temporary__str(Fast_Temporary value);
Fast_Temporary Fast_Temporary__fromStr(Fast_Temporary value, cx_string str);
cx_int16 Fast_Temporary__copy(Fast_Temporary *dst, Fast_Temporary src);
cx_int16 Fast_Temporary__compare(Fast_Temporary dst, Fast_Temporary src);

/* ::corto::Fast::Ternary */
Fast_Ternary Fast_Ternary__create(Fast_Expression condition, Fast_Expression ifTrue, Fast_Expression ifFalse, Fast_Expression result);
Fast_Ternary Fast_Ternary__createChild(cx_object _parent, cx_string _name, Fast_Expression condition, Fast_Expression ifTrue, Fast_Expression ifFalse, Fast_Expression result);

Fast_Ternary Fast_Ternary__declare(void);
Fast_Ternary Fast_Ternary__declareChild(cx_object _parent, cx_string _name);
cx_int16 Fast_Ternary__define(Fast_Ternary _this, Fast_Expression condition, Fast_Expression ifTrue, Fast_Expression ifFalse, Fast_Expression result);
void Fast_Ternary__update(Fast_Ternary _this, Fast_Expression condition, Fast_Expression ifTrue, Fast_Expression ifFalse, Fast_Expression result);
void Fast_Ternary__set(Fast_Ternary _this, Fast_Expression condition, Fast_Expression ifTrue, Fast_Expression ifFalse, Fast_Expression result);
cx_string Fast_Ternary__str(Fast_Ternary value);
Fast_Ternary Fast_Ternary__fromStr(Fast_Ternary value, cx_string str);
cx_int16 Fast_Ternary__copy(Fast_Ternary *dst, Fast_Ternary src);
cx_int16 Fast_Ternary__compare(Fast_Ternary dst, Fast_Ternary src);

/* ::corto::Fast::Unary */
Fast_Unary Fast_Unary__create(Fast_Expression lvalue, cx_operatorKind operator);
Fast_Unary Fast_Unary__createChild(cx_object _parent, cx_string _name, Fast_Expression lvalue, cx_operatorKind operator);

Fast_Unary Fast_Unary__declare(void);
Fast_Unary Fast_Unary__declareChild(cx_object _parent, cx_string _name);
cx_int16 Fast_Unary__define(Fast_Unary _this, Fast_Expression lvalue, cx_operatorKind operator);
void Fast_Unary__update(Fast_Unary _this, Fast_Expression lvalue, cx_operatorKind operator);
void Fast_Unary__set(Fast_Unary _this, Fast_Expression lvalue, cx_operatorKind operator);
cx_string Fast_Unary__str(Fast_Unary value);
Fast_Unary Fast_Unary__fromStr(Fast_Unary value, cx_string str);
cx_int16 Fast_Unary__copy(Fast_Unary *dst, Fast_Unary src);
cx_int16 Fast_Unary__compare(Fast_Unary dst, Fast_Unary src);

/* ::corto::Fast::Update */
Fast_Update Fast_Update__create(Fast_Expression_list exprList, Fast_Block block, Fast_Expression from, Fast_UpdateKind kind_1);
Fast_Update Fast_Update__createChild(cx_object _parent, cx_string _name, Fast_Expression_list exprList, Fast_Block block, Fast_Expression from, Fast_UpdateKind kind_1);

Fast_Update Fast_Update__declare(void);
Fast_Update Fast_Update__declareChild(cx_object _parent, cx_string _name);
cx_int16 Fast_Update__define(Fast_Update _this, Fast_Expression_list exprList, Fast_Block block, Fast_Expression from, Fast_UpdateKind kind_1);
void Fast_Update__update(Fast_Update _this, Fast_Expression_list exprList, Fast_Block block, Fast_Expression from, Fast_UpdateKind kind_1);
void Fast_Update__set(Fast_Update _this, Fast_Expression_list exprList, Fast_Block block, Fast_Expression from, Fast_UpdateKind kind_1);
cx_string Fast_Update__str(Fast_Update value);
Fast_Update Fast_Update__fromStr(Fast_Update value, cx_string str);
cx_int16 Fast_Update__copy(Fast_Update *dst, Fast_Update src);
cx_int16 Fast_Update__compare(Fast_Update dst, Fast_Update src);

/* ::corto::Fast::UpdateKind */
Fast_UpdateKind* Fast_UpdateKind__create(void);
Fast_UpdateKind* Fast_UpdateKind__createChild(cx_object _parent, cx_string _name);

Fast_UpdateKind* Fast_UpdateKind__declare(void);
Fast_UpdateKind* Fast_UpdateKind__declareChild(cx_object _parent, cx_string _name);
cx_int16 Fast_UpdateKind__define(Fast_UpdateKind* _this, Fast_UpdateKind value);
void Fast_UpdateKind__update(Fast_UpdateKind* _this, Fast_UpdateKind value);
void Fast_UpdateKind__set(Fast_UpdateKind* _this, Fast_UpdateKind value);
cx_string Fast_UpdateKind__str(Fast_UpdateKind value);
Fast_UpdateKind* Fast_UpdateKind__fromStr(Fast_UpdateKind* value, cx_string str);
cx_int16 Fast_UpdateKind__copy(Fast_UpdateKind* *dst, Fast_UpdateKind* src);
cx_int16 Fast_UpdateKind__compare(Fast_UpdateKind* dst, Fast_UpdateKind* src);

cx_int16 Fast_UpdateKind__init(Fast_UpdateKind* value);
cx_int16 Fast_UpdateKind__deinit(Fast_UpdateKind* value);

/* ::corto::Fast::valueKind */
Fast_valueKind* Fast_valueKind__create(void);
Fast_valueKind* Fast_valueKind__createChild(cx_object _parent, cx_string _name);

Fast_valueKind* Fast_valueKind__declare(void);
Fast_valueKind* Fast_valueKind__declareChild(cx_object _parent, cx_string _name);
cx_int16 Fast_valueKind__define(Fast_valueKind* _this, Fast_valueKind value);
void Fast_valueKind__update(Fast_valueKind* _this, Fast_valueKind value);
void Fast_valueKind__set(Fast_valueKind* _this, Fast_valueKind value);
cx_string Fast_valueKind__str(Fast_valueKind value);
Fast_valueKind* Fast_valueKind__fromStr(Fast_valueKind* value, cx_string str);
cx_int16 Fast_valueKind__copy(Fast_valueKind* *dst, Fast_valueKind* src);
cx_int16 Fast_valueKind__compare(Fast_valueKind* dst, Fast_valueKind* src);

cx_int16 Fast_valueKind__init(Fast_valueKind* value);
cx_int16 Fast_valueKind__deinit(Fast_valueKind* value);

/* ::corto::Fast::Wait */
Fast_Wait Fast_Wait__create(Fast_Expression_list exprList, Fast_Expression timeout);
Fast_Wait Fast_Wait__createChild(cx_object _parent, cx_string _name, Fast_Expression_list exprList, Fast_Expression timeout);

Fast_Wait Fast_Wait__declare(void);
Fast_Wait Fast_Wait__declareChild(cx_object _parent, cx_string _name);
cx_int16 Fast_Wait__define(Fast_Wait _this, Fast_Expression_list exprList, Fast_Expression timeout);
void Fast_Wait__update(Fast_Wait _this, Fast_Expression_list exprList, Fast_Expression timeout);
void Fast_Wait__set(Fast_Wait _this, Fast_Expression_list exprList, Fast_Expression timeout);
cx_string Fast_Wait__str(Fast_Wait value);
Fast_Wait Fast_Wait__fromStr(Fast_Wait value, cx_string str);
cx_int16 Fast_Wait__copy(Fast_Wait *dst, Fast_Wait src);
cx_int16 Fast_Wait__compare(Fast_Wait dst, Fast_Wait src);

/* ::corto::Fast::While */
Fast_While Fast_While__create(Fast_Expression condition, Fast_Block trueBranch, cx_bool isUntil);
Fast_While Fast_While__createChild(cx_object _parent, cx_string _name, Fast_Expression condition, Fast_Block trueBranch, cx_bool isUntil);

Fast_While Fast_While__declare(void);
Fast_While Fast_While__declareChild(cx_object _parent, cx_string _name);
cx_int16 Fast_While__define(Fast_While _this, Fast_Expression condition, Fast_Block trueBranch, cx_bool isUntil);
void Fast_While__update(Fast_While _this, Fast_Expression condition, Fast_Block trueBranch, cx_bool isUntil);
void Fast_While__set(Fast_While _this, Fast_Expression condition, Fast_Block trueBranch, cx_bool isUntil);
cx_string Fast_While__str(Fast_While value);
Fast_While Fast_While__fromStr(Fast_While value, cx_string str);
cx_int16 Fast_While__copy(Fast_While *dst, Fast_While src);
cx_int16 Fast_While__compare(Fast_While dst, Fast_While src);


/* <0x7f8391c11a68> */
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

/* <0x7f8391e2fa88> */
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

/* <0x7f8391d91a08> */
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

/* <0x7f8391e54a88> */
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

/* <0x7f8391e53f48> */
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

/* ::corto::Fast::ParserDeclarationSeq */
#define Fast_ParserDeclarationSeq__foreach(seq, elem) \
    cx_uint32 elem##_iter;\
    Fast_ParserDeclaration *elem;\
    for(elem##_iter=0; elem##_iter<seq.length; elem##_iter++) {\
        elem = &seq.buffer[elem##_iter];

Fast_ParserDeclaration* Fast_ParserDeclarationSeq__append(Fast_ParserDeclarationSeq *seq);
void Fast_ParserDeclarationSeq__size(Fast_ParserDeclarationSeq *seq, cx_uint32 length);
void Fast_ParserDeclarationSeq__clear(Fast_ParserDeclarationSeq *seq);

/* <0x7f8391e64d38> */
#define cx_parameter_seq__foreach(seq, elem) \
    cx_uint32 elem##_iter;\
    cx_parameter *elem;\
    for(elem##_iter=0; elem##_iter<seq.length; elem##_iter++) {\
        elem = &seq.buffer[elem##_iter];

cx_parameter* cx_parameter_seq__append(cx_parameter_seq *seq);
void cx_parameter_seq__size(cx_parameter_seq *seq, cx_uint32 length);
void cx_parameter_seq__clear(cx_parameter_seq *seq);

/* <0x7f8391c135c8> */
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

/* <0x7f8391c12f18> */
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

