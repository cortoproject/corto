/* Fast__type.h
 *
 *    Type-definitions for C-language.
 *    This file contains generated code. Do not modify!
 */

#ifndef Fast__type_H
#define Fast__type_H

#include "cortex.h"


/* $header() */
#include "cx_ic.h"
/* $end */

#ifdef __cplusplus
extern "C" {
#endif

/* Casting macro's for classes */
#define Fast_Binary(o) ((Fast_Binary)o)
#define Fast_Block(o) ((Fast_Block)o)
#define Fast_Boolean(o) ((Fast_Boolean)o)
#define Fast_Call(o) ((Fast_Call)o)
#define Fast_Cast(o) ((Fast_Cast)o)
#define Fast_Character(o) ((Fast_Character)o)
#define Fast_Comma(o) ((Fast_Comma)o)
#define Fast_Define(o) ((Fast_Define)o)
#define Fast_DelegateCall(o) ((Fast_DelegateCall)o)
#define Fast_DynamicInitializer(o) ((Fast_DynamicInitializer)o)
#define Fast_Element(o) ((Fast_Element)o)
#define Fast_Expression(o) ((Fast_Expression)o)
#define Fast_FloatingPoint(o) ((Fast_FloatingPoint)o)
#define Fast_If(o) ((Fast_If)o)
#define Fast_Initializer(o) ((Fast_Initializer)o)
#define Fast_InitializerExpression(o) ((Fast_InitializerExpression)o)
#define Fast_Integer(o) ((Fast_Integer)o)
#define Fast_Literal(o) ((Fast_Literal)o)
#define Fast_Local(o) ((Fast_Local)o)
#define Fast_Member(o) ((Fast_Member)o)
#define Fast_New(o) ((Fast_New)o)
#define Fast_Node(o) ((Fast_Node)o)
#define Fast_Null(o) ((Fast_Null)o)
#define Fast_Object(o) ((Fast_Object)o)
#define Fast_ObjectBase(o) ((Fast_ObjectBase)o)
#define Fast_Parser(o) ((Fast_Parser)o)
#define Fast_PostFix(o) ((Fast_PostFix)o)
#define Fast_SignedInteger(o) ((Fast_SignedInteger)o)
#define Fast_StaticCall(o) ((Fast_StaticCall)o)
#define Fast_StaticInitializer(o) ((Fast_StaticInitializer)o)
#define Fast_String(o) ((Fast_String)o)
#define Fast_Template(o) ((Fast_Template)o)
#define Fast_Ternary(o) ((Fast_Ternary)o)
#define Fast_Unary(o) ((Fast_Unary)o)
#define Fast_Update(o) ((Fast_Update)o)
#define Fast_Variable(o) ((Fast_Variable)o)
#define Fast_Wait(o) ((Fast_Wait)o)
#define Fast_While(o) ((Fast_While)o)

/* Type definitions */
/* ::cortex::Fast::nodeKind */
typedef enum Fast_nodeKind {
    Fast_BinaryExpr = 0,
    Fast_CallExpr = 1,
    Fast_CastExpr = 2,
    Fast_CommaExpr = 3,
    Fast_DeclarationExpr = 4,
    Fast_DeclareExpr = 5,
    Fast_DefineExpr = 6,
    Fast_ElementExpr = 7,
    Fast_IfExpr = 8,
    Fast_InitializerExpr = 9,
    Fast_LiteralExpr = 10,
    Fast_MemberExpr = 11,
    Fast_MethodExpr = 12,
    Fast_NewExpr = 13,
    Fast_PostfixExpr = 14,
    Fast_TernaryExpr = 15,
    Fast_UnaryExpr = 16,
    Fast_UpdateExpr = 17,
    Fast_VariableExpr = 18,
    Fast_WaitExpr = 19,
    Fast_WhileExpr = 20
} Fast_nodeKind;

/*  ::cortex::Fast::Node */
CX_CLASS(Fast_Node);

CX_CLASS_DEF(Fast_Node) {
    Fast_nodeKind kind;
    cx_uint32 line;
    cx_uint32 column;
};

/*  ::cortex::Fast::Variable */
CX_CLASS(Fast_Variable);

/*  ::cortex::Fast::Expression */
CX_CLASS(Fast_Expression);

CX_CLASS_DEF(Fast_Expression) {
    CX_EXTEND(Fast_Node);
    Fast_Variable type;
    cx_bool isReference;
    cx_bool forceReference;
};

/*  ::cortex::Fast::Binary */
CX_CLASS(Fast_Binary);

CX_CLASS_DEF(Fast_Binary) {
    CX_EXTEND(Fast_Expression);
    Fast_Expression lvalue;
    Fast_Expression rvalue;
    cx_operatorKind operator;
};

/*  ::cortex::Fast::Block */
CX_CLASS(Fast_Block);

CX_LIST(Fast_Node_list);

/* ::cortex::Fast::variableKind */
typedef enum Fast_variableKind {
    Fast_LocalExpr = 0,
    Fast_TemplateExpr = 1,
    Fast_ObjectExpr = 2
} Fast_variableKind;

CX_CLASS_DEF(Fast_Variable) {
    CX_EXTEND(Fast_Expression);
    Fast_variableKind kind;
};

/* ::cortex::Fast::LocalKind */
typedef enum Fast_LocalKind {
    Fast_LocalDefault = 0,
    Fast_LocalParameter = 1,
    Fast_LocalReturn = 2
} Fast_LocalKind;

/*  ::cortex::Fast::Local */
CX_CLASS(Fast_Local);

CX_CLASS_DEF(Fast_Local) {
    CX_EXTEND(Fast_Variable);
    cx_string name;
    Fast_Variable type;
    Fast_LocalKind kind;
    cx_bool reference;
};

CX_LIST(Fast_Local_list);

/*  ::cortex::Fast::While */
CX_CLASS(Fast_While);

CX_CLASS_DEF(Fast_While) {
    CX_EXTEND(Fast_Node);
    Fast_Expression condition;
    Fast_Block trueBranch;
    cx_bool isUntil;
};

CX_CLASS_DEF(Fast_Block) {
    CX_EXTEND(Fast_Node);
    Fast_Block parent;
    cx_bool isRoot;
    Fast_Node_list statements;
    Fast_Local_list locals;
    cx_function function;
    Fast_While _while;
};

/*  ::cortex::Fast::Binding */
typedef struct Fast_Binding Fast_Binding;

struct Fast_Binding {
    cx_function function;
    Fast_Block impl;
};

/* ::cortex::Fast::valueKind */
typedef enum Fast_valueKind {
    Fast_Bool = 0,
    Fast_Char = 1,
    Fast_Int = 2,
    Fast_SignedInt = 3,
    Fast_Float = 4,
    Fast_Text = 5,
    Fast_Enum = 6,
    Fast_Ref = 7,
    Fast_Nothing = 8
} Fast_valueKind;

/*  ::cortex::Fast::Literal */
CX_CLASS(Fast_Literal);

CX_CLASS_DEF(Fast_Literal) {
    CX_EXTEND(Fast_Expression);
    Fast_valueKind kind;
};

/*  ::cortex::Fast::Boolean */
CX_CLASS(Fast_Boolean);

CX_CLASS_DEF(Fast_Boolean) {
    CX_EXTEND(Fast_Literal);
    cx_bool value;
};

CX_SEQUENCE(cx_parameter_seq, cx_parameter,);

/*  ::cortex::Fast::Call */
CX_CLASS(Fast_Call);

CX_CLASS_DEF(Fast_Call) {
    CX_EXTEND(Fast_Expression);
    Fast_Expression instanceExpr;
    Fast_Expression arguments;
    Fast_Expression functionExpr;
    cx_bool instanceIsAny;
    cx_type returnType;
    cx_bool returnsReference;
    cx_parameter_seq parameters;
    cx_bool overloaded;
};

/*  ::cortex::Fast::CallBuilder */
typedef struct Fast_CallBuilder Fast_CallBuilder;

struct Fast_CallBuilder {
    cx_string name;
    Fast_Expression arguments;
    Fast_Expression instance;
    cx_object scope;
    Fast_Block block;
    cx_bool overloaded;
    cx_string signature;
};

/*  ::cortex::Fast::Cast */
CX_CLASS(Fast_Cast);

CX_CLASS_DEF(Fast_Cast) {
    CX_EXTEND(Fast_Expression);
    Fast_Expression lvalue;
    Fast_Expression rvalue;
};

/*  ::cortex::Fast::Character */
CX_CLASS(Fast_Character);

CX_CLASS_DEF(Fast_Character) {
    CX_EXTEND(Fast_Literal);
    cx_char value;
};

CX_LIST(Fast_Expression_list);

/*  ::cortex::Fast::Comma */
CX_CLASS(Fast_Comma);

CX_CLASS_DEF(Fast_Comma) {
    CX_EXTEND(Fast_Expression);
    Fast_Expression_list expressions;
};

/*  ::cortex::Fast::Define */
CX_CLASS(Fast_Define);

CX_CLASS_DEF(Fast_Define) {
    CX_EXTEND(Fast_Node);
    Fast_Expression object;
};

/*  ::cortex::Fast::DelegateCall */
CX_CLASS(Fast_DelegateCall);

CX_CLASS_DEF(Fast_DelegateCall) {
    CX_EXTEND(Fast_Call);
    Fast_Expression expr;
};

/*  ::cortex::Fast::InitializerVariable */
typedef struct Fast_InitializerVariable Fast_InitializerVariable;

struct Fast_InitializerVariable {
    cx_word offset;
    Fast_Expression object;
    cx_word key;
};

typedef Fast_InitializerVariable Fast_InitializerVariable_array64[64];

/*  ::cortex::Fast::InitializerFrame */
typedef struct Fast_InitializerFrame Fast_InitializerFrame;

struct Fast_InitializerFrame {
    cx_uint32 location;
    cx_type type;
    cx_bool isKey;
    cx_member member;
};

typedef Fast_InitializerFrame Fast_InitializerFrame_array64[64];

/*  ::cortex::Fast::Initializer */
CX_CLASS(Fast_Initializer);

CX_CLASS_DEF(Fast_Initializer) {
    CX_EXTEND(Fast_Expression);
    Fast_InitializerVariable_array64 variables;
    cx_uint8 variableCount;
    Fast_InitializerFrame_array64 frames;
    cx_uint8 fp;
};

typedef Fast_Expression Fast_Expression_array64[64];

/*  ::cortex::Fast::Integer */
CX_CLASS(Fast_Integer);

CX_CLASS_DEF(Fast_Integer) {
    CX_EXTEND(Fast_Literal);
    cx_uint64 value;
};

/*  ::cortex::Fast::DynamicInitializerFrame */
typedef struct Fast_DynamicInitializerFrame Fast_DynamicInitializerFrame;

struct Fast_DynamicInitializerFrame {
    Fast_Expression_array64 expr;
    Fast_Expression_array64 keyExpr;
    Fast_Integer sequenceSize;
};

typedef Fast_DynamicInitializerFrame Fast_DynamicInitializerFrame_array64[64];

/*  ::cortex::Fast::DynamicInitializer */
CX_CLASS(Fast_DynamicInitializer);

CX_CLASS_DEF(Fast_DynamicInitializer) {
    CX_EXTEND(Fast_Initializer);
    cx_bool assignValue;
    Fast_DynamicInitializerFrame_array64 frames;
};

/*  ::cortex::Fast::Element */
CX_CLASS(Fast_Element);

CX_CLASS_DEF(Fast_Element) {
    CX_EXTEND(Fast_Expression);
    Fast_Expression lvalue;
    Fast_Expression rvalue;
};

/*  ::cortex::Fast::FloatingPoint */
CX_CLASS(Fast_FloatingPoint);

CX_CLASS_DEF(Fast_FloatingPoint) {
    CX_EXTEND(Fast_Literal);
    cx_float64 value;
};

/*  ::cortex::Fast::If */
CX_CLASS(Fast_If);

CX_CLASS_DEF(Fast_If) {
    CX_EXTEND(Fast_Node);
    Fast_Expression condition;
    Fast_Block trueBranch;
    Fast_If falseBranch;
    cx_bool warnUnreachable;
};

/* ::cortex::Fast::InitOperKind */
typedef enum Fast_InitOperKind {
    Fast_InitPush = 0,
    Fast_InitPop = 1,
    Fast_InitDefine = 2,
    Fast_InitValue = 3,
    Fast_InitMember = 4
} Fast_InitOperKind;

/*  ::cortex::Fast::InitOper */
typedef struct Fast_InitOper Fast_InitOper;

struct Fast_InitOper {
    Fast_InitOperKind kind;
    Fast_Expression expr;
    cx_string name;
};

CX_LIST(Fast_InitOper_list);

/*  ::cortex::Fast::InitializerExpression */
CX_CLASS(Fast_InitializerExpression);

CX_CLASS_DEF(Fast_InitializerExpression) {
    CX_EXTEND(Fast_Initializer);
    cx_bool assignValue;
    Fast_InitOper_list operations;
};

/* ::cortex::Fast::InitializerKind */
typedef enum Fast_InitializerKind {
    Fast_InitStatic = 0,
    Fast_InitDynamic = 1,
    Fast_InitExpression = 2
} Fast_InitializerKind;

/*  ::cortex::Fast::Lvalue */
typedef struct Fast_Lvalue Fast_Lvalue;

struct Fast_Lvalue {
    Fast_Expression expr;
    cx_bool isAssignment;
};

/*  ::cortex::Fast::Member */
CX_CLASS(Fast_Member);

CX_CLASS_DEF(Fast_Member) {
    CX_EXTEND(Fast_Expression);
    Fast_Expression lvalue;
    Fast_Expression rvalue;
    cx_bool superMember;
    cx_object member;
};

/*  ::cortex::Fast::New */
CX_CLASS(Fast_New);

CX_CLASS_DEF(Fast_New) {
    CX_EXTEND(Fast_Expression);
    Fast_Expression type;
    Fast_Expression attributes;
};

/*  ::cortex::Fast::Null */
CX_CLASS(Fast_Null);

CX_CLASS_DEF(Fast_Null) {
    CX_EXTEND(Fast_Literal);
};

/*  ::cortex::Fast::ObjectBase */
CX_CLASS(Fast_ObjectBase);

CX_CLASS_DEF(Fast_ObjectBase) {
    CX_EXTEND(Fast_Variable);
    cx_object value;
};

/*  ::cortex::Fast::Object */
CX_CLASS(Fast_Object);

CX_CLASS_DEF(Fast_Object) {
    CX_EXTEND(Fast_ObjectBase);
};

CX_LIST(Fast_Binding_list);

CX_LIST(cx_word_list);

CX_LIST(cx_object_list);

typedef Fast_Variable Fast_Variable_array64[64];

typedef Fast_Initializer Fast_Initializer_array64[64];

/*  ::cortex::Fast::Parser::stagedId */
typedef struct Fast_Parser_stagedId Fast_Parser_stagedId;

struct Fast_Parser_stagedId {
    cx_string name;
    cx_bool found;
    cx_uint32 line;
    cx_uint32 column;
};

typedef Fast_Parser_stagedId Fast_Parser_stagedId_array64[64];

typedef Fast_Lvalue Fast_Lvalue_array64[64];

typedef cx_type cx_type_array64[64];

/*  ::cortex::Fast::Parser */
CX_CLASS(Fast_Parser);

CX_CLASS_DEF(Fast_Parser) {
    cx_string source;
    cx_string preprocessed;
    cx_string filename;
    cx_uint32 repl;
    cx_uint32 line;
    cx_uint32 column;
    cx_string token;
    Fast_Block block;
    cx_uint32 blockCount;
    Fast_Variable scope;
    cx_uint32 errors;
    cx_uint32 warnings;
    cx_bool errSet;
    cx_uint32 errLine;
    cx_bool abort;
    Fast_Binding_list bindings;
    cx_uint32 pass;
    cx_word_list heapCollected;
    cx_object_list collected;
    cx_bool blockPreset;
    cx_bool isLocal;
    cx_bool parseSingleExpr;
    Fast_Expression singleExpr;
    cx_string lastFailedResolve;
    Fast_Variable_array64 variables;
    cx_uint32 variableCount;
    cx_bool variablesInitialized;
    cx_bool variablePushed;
    Fast_Initializer_array64 initializers;
    cx_int8 initializerCount;
    cx_uint32 initAnonymousId;
    cx_bool initDynamic;
    Fast_Parser_stagedId_array64 staged;
    cx_uint32 stagedCount;
    cx_bool stagingAllowed;
    Fast_Lvalue_array64 lvalue;
    cx_int32 lvalueSp;
    cx_type_array64 complexType;
    cx_int32 complexTypeSp;
};

/*  ::cortex::Fast::ParserDeclaration */
typedef struct Fast_ParserDeclaration Fast_ParserDeclaration;

struct Fast_ParserDeclaration {
    cx_string name;
    Fast_Variable variable;
};

CX_SEQUENCE(Fast_ParserDeclarationSeq, Fast_ParserDeclaration,);

/*  ::cortex::Fast::ParserNew */
typedef struct Fast_ParserNew Fast_ParserNew;

struct Fast_ParserNew {
    Fast_nodeKind kind;
    Fast_Expression parent;
    Fast_Expression name;
    Fast_Expression attr;
};

/*  ::cortex::Fast::PostFix */
CX_CLASS(Fast_PostFix);

CX_CLASS_DEF(Fast_PostFix) {
    CX_EXTEND(Fast_Expression);
    Fast_Expression lvalue;
    cx_operatorKind operator;
};

/*  ::cortex::Fast::SignedInteger */
CX_CLASS(Fast_SignedInteger);

CX_CLASS_DEF(Fast_SignedInteger) {
    CX_EXTEND(Fast_Literal);
    cx_int64 value;
};

/*  ::cortex::Fast::StaticCall */
CX_CLASS(Fast_StaticCall);

CX_CLASS_DEF(Fast_StaticCall) {
    CX_EXTEND(Fast_Call);
    cx_function function;
};

typedef cx_word cx_word_array64[64];

/*  ::cortex::Fast::StaticInitializerFrame */
typedef struct Fast_StaticInitializerFrame Fast_StaticInitializerFrame;

struct Fast_StaticInitializerFrame {
    cx_word_array64 ptr;
    cx_word_array64 keyPtr;
};

typedef Fast_StaticInitializerFrame Fast_StaticInitializerFrame_array64[64];

/*  ::cortex::Fast::StaticInitializer */
CX_CLASS(Fast_StaticInitializer);

CX_CLASS_DEF(Fast_StaticInitializer) {
    CX_EXTEND(Fast_Initializer);
    Fast_StaticInitializerFrame_array64 frames;
};

/*  ::cortex::Fast::String */
CX_CLASS(Fast_String);

CX_CLASS_DEF(Fast_String) {
    CX_EXTEND(Fast_Literal);
    cx_string value;
    Fast_Expression_list elements;
    Fast_Block block;
    Fast_Variable scope;
};

/*  ::cortex::Fast::Template */
CX_CLASS(Fast_Template);

CX_CLASS_DEF(Fast_Template) {
    CX_EXTEND(Fast_Local);
};

/*  ::cortex::Fast::Ternary */
CX_CLASS(Fast_Ternary);

CX_CLASS_DEF(Fast_Ternary) {
    CX_EXTEND(Fast_Expression);
    Fast_Expression condition;
    Fast_Expression ifTrue;
    Fast_Expression ifFalse;
    Fast_Expression ifTrueExpr;
    Fast_Expression ifFalseExpr;
    Fast_Expression result;
    Fast_If ifstmt;
};

/*  ::cortex::Fast::Unary */
CX_CLASS(Fast_Unary);

CX_CLASS_DEF(Fast_Unary) {
    CX_EXTEND(Fast_Expression);
    Fast_Expression lvalue;
    cx_operatorKind operator;
};

/* ::cortex::Fast::UpdateKind */
typedef enum Fast_UpdateKind {
    Fast_UpdateDefault = 0,
    Fast_UpdateBegin = 1,
    Fast_UpdateEnd = 2
} Fast_UpdateKind;

/*  ::cortex::Fast::Update */
CX_CLASS(Fast_Update);

CX_CLASS_DEF(Fast_Update) {
    CX_EXTEND(Fast_Node);
    Fast_Expression_list exprList;
    Fast_Block block;
    Fast_Expression from;
    Fast_UpdateKind kind;
};

/*  ::cortex::Fast::Wait */
CX_CLASS(Fast_Wait);

CX_CLASS_DEF(Fast_Wait) {
    CX_EXTEND(Fast_Expression);
    Fast_Expression_list exprList;
    Fast_Expression timeout;
};

#ifdef __cplusplus
}
#endif
#endif

