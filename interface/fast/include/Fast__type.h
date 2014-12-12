/* Fast__type.h
 *
 *  Generated on Dec  3 2014
 *    Type-definitions for C-language.
 *    This file contains generated code. Do not modify!
 */

#ifndef Fast__type_H
#define Fast__type_H

#include "hyve.h"

/* $header() */
#include "db_ic.h"
/* $end */

#ifdef __cplusplus
extern "C" {
#endif

/* Casting macro's for classes */
#define Fast_BinaryExpr(o) ((Fast_BinaryExpr)o)
#define Fast_Block(o) ((Fast_Block)o)
#define Fast_Boolean(o) ((Fast_Boolean)o)
#define Fast_Call(o) ((Fast_Call)o)
#define Fast_CastExpr(o) ((Fast_CastExpr)o)
#define Fast_Character(o) ((Fast_Character)o)
#define Fast_CommaExpr(o) ((Fast_CommaExpr)o)
#define Fast_Define(o) ((Fast_Define)o)
#define Fast_DynamicInitializer(o) ((Fast_DynamicInitializer)o)
#define Fast_ElementExpr(o) ((Fast_ElementExpr)o)
#define Fast_Expression(o) ((Fast_Expression)o)
#define Fast_FloatingPoint(o) ((Fast_FloatingPoint)o)
#define Fast_If(o) ((Fast_If)o)
#define Fast_Initializer(o) ((Fast_Initializer)o)
#define Fast_InitializerExpr(o) ((Fast_InitializerExpr)o)
#define Fast_Integer(o) ((Fast_Integer)o)
#define Fast_Literal(o) ((Fast_Literal)o)
#define Fast_Local(o) ((Fast_Local)o)
#define Fast_MemberExpr(o) ((Fast_MemberExpr)o)
#define Fast_NewExpr(o) ((Fast_NewExpr)o)
#define Fast_Node(o) ((Fast_Node)o)
#define Fast_Null(o) ((Fast_Null)o)
#define Fast_Object(o) ((Fast_Object)o)
#define Fast_ObjectBase(o) ((Fast_ObjectBase)o)
#define Fast_Parser(o) ((Fast_Parser)o)
#define Fast_PostfixExpr(o) ((Fast_PostfixExpr)o)
#define Fast_SignedInteger(o) ((Fast_SignedInteger)o)
#define Fast_StaticInitializer(o) ((Fast_StaticInitializer)o)
#define Fast_String(o) ((Fast_String)o)
#define Fast_Template(o) ((Fast_Template)o)
#define Fast_TernaryExpr(o) ((Fast_TernaryExpr)o)
#define Fast_UnaryExpr(o) ((Fast_UnaryExpr)o)
#define Fast_Update(o) ((Fast_Update)o)
#define Fast_Variable(o) ((Fast_Variable)o)
#define Fast_Wait(o) ((Fast_Wait)o)
#define Fast_While(o) ((Fast_While)o)

/* Type definitions */

/* ::hyve::Fast::nodeKind */
typedef enum Fast_nodeKind {
    FAST_Binary = 0,
    FAST_Call = 1,
    FAST_Cast = 2,
    FAST_CommaExpr = 3,
    FAST_Declaration = 4,
    FAST_Declare = 5,
    FAST_Define = 6,
    FAST_Element = 7,
    FAST_If = 8,
    FAST_Initializer = 9,
    FAST_Literal = 10,
    FAST_Member = 11,
    FAST_Method = 12,
    FAST_New = 13,
    FAST_Postfix = 14,
    FAST_Ternary = 15,
    FAST_Unary = 16,
    FAST_Update = 17,
    FAST_Variable = 18,
    FAST_Wait = 19,
    FAST_While = 20
} Fast_nodeKind;

/*  ::hyve::Fast::Node */
DB_CLASS(Fast_Node);
DB_CLASS_DEF(Fast_Node) {
    Fast_nodeKind kind;
    db_uint32 line;
    db_uint32 column;
};

/*  ::hyve::Fast::Variable */
DB_CLASS(Fast_Variable);

/*  ::hyve::Fast::Expression */
DB_CLASS(Fast_Expression);
DB_CLASS_DEF(Fast_Expression) {
    DB_EXTEND(Fast_Node);
    Fast_Variable type;
    db_bool isReference;
    db_bool forceReference;
};

/*  ::hyve::Fast::BinaryExpr */
DB_CLASS(Fast_BinaryExpr);
DB_CLASS_DEF(Fast_BinaryExpr) {
    DB_EXTEND(Fast_Expression);
    Fast_Expression lvalue;
    Fast_Expression rvalue;
    db_operatorKind operator;
};

/*  ::hyve::Fast::Block */
DB_CLASS(Fast_Block);
DB_LIST(Fast_Node_list);
/* ::hyve::Fast::variableKind */
typedef enum Fast_variableKind {
    FAST_Local = 0,
    FAST_Template = 1,
    FAST_Object = 2
} Fast_variableKind;
DB_CLASS_DEF(Fast_Variable) {
    DB_EXTEND(Fast_Expression);
    Fast_variableKind kind;
};
/* ::hyve::Fast::LocalKind */
typedef enum Fast_LocalKind {
    FAST_LocalDefault = 0,
    FAST_LocalParameter = 1,
    FAST_LocalReturn = 2
} Fast_LocalKind;

/*  ::hyve::Fast::Local */
DB_CLASS(Fast_Local);
DB_CLASS_DEF(Fast_Local) {
    DB_EXTEND(Fast_Variable);
    db_string name;
    Fast_Variable type;
    Fast_LocalKind kind;
    db_bool isReference;
};
DB_LIST(Fast_Local_list);

/*  ::hyve::Fast::While */
DB_CLASS(Fast_While);
DB_CLASS_DEF(Fast_While) {
    DB_EXTEND(Fast_Node);
    Fast_Expression condition;
    Fast_Block trueBranch;
    db_bool isUntil;
};
DB_CLASS_DEF(Fast_Block) {
    DB_EXTEND(Fast_Node);
    Fast_Block parent;
    Fast_Node_list statements;
    Fast_Local_list locals;
    db_function function;
    Fast_While _while;
};

/*  ::hyve::Fast::Binding */
typedef struct Fast_Binding Fast_Binding;
struct Fast_Binding {
    db_function function;
    Fast_Block impl;
};
/* ::hyve::Fast::valueKind */
typedef enum Fast_valueKind {
    FAST_Boolean = 0,
    FAST_Character = 1,
    FAST_Integer = 2,
    FAST_SignedInteger = 3,
    FAST_FloatingPoint = 4,
    FAST_String = 5,
    FAST_Enumerated = 6,
    FAST_Reference = 7,
    FAST_Null = 8
} Fast_valueKind;

/*  ::hyve::Fast::Literal */
DB_CLASS(Fast_Literal);
DB_CLASS_DEF(Fast_Literal) {
    DB_EXTEND(Fast_Expression);
    Fast_valueKind kind;
};

/*  ::hyve::Fast::Boolean */
DB_CLASS(Fast_Boolean);
DB_CLASS_DEF(Fast_Boolean) {
    DB_EXTEND(Fast_Literal);
    db_bool value;
};

/*  ::hyve::Fast::Call */
DB_CLASS(Fast_Call);
DB_CLASS_DEF(Fast_Call) {
    DB_EXTEND(Fast_Expression);
    Fast_Expression function;
    Fast_Expression arguments;
    db_string signature;
    db_function actualFunction;
};

/*  ::hyve::Fast::CastExpr */
DB_CLASS(Fast_CastExpr);
DB_CLASS_DEF(Fast_CastExpr) {
    DB_EXTEND(Fast_Expression);
    Fast_Expression lvalue;
    Fast_Expression rvalue;
};

/*  ::hyve::Fast::Character */
DB_CLASS(Fast_Character);
DB_CLASS_DEF(Fast_Character) {
    DB_EXTEND(Fast_Literal);
    db_char value;
};
DB_LIST(Fast_Expression_list);

/*  ::hyve::Fast::CommaExpr */
DB_CLASS(Fast_CommaExpr);
DB_CLASS_DEF(Fast_CommaExpr) {
    DB_EXTEND(Fast_Expression);
    Fast_Expression_list expressions;
};

/*  ::hyve::Fast::Define */
DB_CLASS(Fast_Define);
DB_CLASS_DEF(Fast_Define) {
    DB_EXTEND(Fast_Node);
    Fast_Expression object;
};

/*  ::hyve::Fast::InitializerVariable */
typedef struct Fast_InitializerVariable Fast_InitializerVariable;
struct Fast_InitializerVariable {
    db_word offset;
    Fast_Expression object;
    db_word key;
};
typedef Fast_InitializerVariable Fast_InitializerVariable_array64[64];

/*  ::hyve::Fast::InitializerFrame */
typedef struct Fast_InitializerFrame Fast_InitializerFrame;
struct Fast_InitializerFrame {
    db_uint32 location;
    db_type type;
    db_bool isKey;
    db_member member;
};
typedef Fast_InitializerFrame Fast_InitializerFrame_array64[64];

/*  ::hyve::Fast::Initializer */
DB_CLASS(Fast_Initializer);
DB_CLASS_DEF(Fast_Initializer) {
    DB_EXTEND(Fast_Expression);
    Fast_InitializerVariable_array64 variables;
    db_uint8 variableCount;
    Fast_InitializerFrame_array64 frames;
    db_uint8 fp;
};
typedef Fast_Expression Fast_Expression_array64[64];

/*  ::hyve::Fast::Integer */
DB_CLASS(Fast_Integer);
DB_CLASS_DEF(Fast_Integer) {
    DB_EXTEND(Fast_Literal);
    db_uint64 value;
};

/*  ::hyve::Fast::DynamicInitializerFrame */
typedef struct Fast_DynamicInitializerFrame Fast_DynamicInitializerFrame;
struct Fast_DynamicInitializerFrame {
    Fast_Expression_array64 expr;
    Fast_Expression_array64 keyExpr;
    Fast_Integer sequenceSize;
};
typedef Fast_DynamicInitializerFrame Fast_DynamicInitializerFrame_array64[64];

/*  ::hyve::Fast::DynamicInitializer */
DB_CLASS(Fast_DynamicInitializer);
DB_CLASS_DEF(Fast_DynamicInitializer) {
    DB_EXTEND(Fast_Initializer);
    db_bool assignValue;
    Fast_DynamicInitializerFrame_array64 frames;
};

/*  ::hyve::Fast::ElementExpr */
DB_CLASS(Fast_ElementExpr);
DB_CLASS_DEF(Fast_ElementExpr) {
    DB_EXTEND(Fast_Expression);
    Fast_Expression lvalue;
    Fast_Expression rvalue;
};

/*  ::hyve::Fast::FloatingPoint */
DB_CLASS(Fast_FloatingPoint);
DB_CLASS_DEF(Fast_FloatingPoint) {
    DB_EXTEND(Fast_Literal);
    db_float64 value;
};

/*  ::hyve::Fast::If */
DB_CLASS(Fast_If);
DB_CLASS_DEF(Fast_If) {
    DB_EXTEND(Fast_Node);
    Fast_Expression condition;
    Fast_Block trueBranch;
    Fast_If falseBranch;
    db_bool warnUnreachable;
};
/* ::hyve::Fast::InitOperKind */
typedef enum Fast_InitOperKind {
    FAST_InitPush = 0,
    FAST_InitPop = 1,
    FAST_InitDefine = 2,
    FAST_InitValue = 3,
    FAST_InitMember = 4
} Fast_InitOperKind;

/*  ::hyve::Fast::InitOper */
typedef struct Fast_InitOper Fast_InitOper;
struct Fast_InitOper {
    Fast_InitOperKind kind;
    Fast_Expression expr;
    db_string name;
};
DB_LIST(Fast_InitOper_list);

/*  ::hyve::Fast::InitializerExpr */
DB_CLASS(Fast_InitializerExpr);
DB_CLASS_DEF(Fast_InitializerExpr) {
    DB_EXTEND(Fast_Initializer);
    db_bool assignValue;
    Fast_InitOper_list operations;
};
/* ::hyve::Fast::InitializerKind */
typedef enum Fast_InitializerKind {
    FAST_InitStatic = 0,
    FAST_InitDynamic = 1,
    FAST_InitExpression = 2
} Fast_InitializerKind;

/*  ::hyve::Fast::Lvalue */
typedef struct Fast_Lvalue Fast_Lvalue;
struct Fast_Lvalue {
    Fast_Expression expr;
    db_bool isAssignment;
};

/*  ::hyve::Fast::MemberExpr */
DB_CLASS(Fast_MemberExpr);
DB_CLASS_DEF(Fast_MemberExpr) {
    DB_EXTEND(Fast_Expression);
    Fast_Expression lvalue;
    Fast_Expression rvalue;
    db_bool superMember;
    db_object member;
};

/*  ::hyve::Fast::NewExpr */
DB_CLASS(Fast_NewExpr);
DB_CLASS_DEF(Fast_NewExpr) {
    DB_EXTEND(Fast_Expression);
    Fast_Expression type;
    Fast_Expression attributes;
};

/*  ::hyve::Fast::Null */
DB_CLASS(Fast_Null);
DB_CLASS_DEF(Fast_Null) {
    DB_EXTEND(Fast_Literal);
};

/*  ::hyve::Fast::ObjectBase */
DB_CLASS(Fast_ObjectBase);
DB_CLASS_DEF(Fast_ObjectBase) {
    DB_EXTEND(Fast_Variable);
    db_object value;
};

/*  ::hyve::Fast::Object */
DB_CLASS(Fast_Object);
DB_CLASS_DEF(Fast_Object) {
    DB_EXTEND(Fast_ObjectBase);
};
DB_LIST(Fast_Binding_list);
DB_LIST(db_word_list);
DB_LIST(Fast_Object_list);
typedef Fast_Variable Fast_Variable_array64[64];
typedef Fast_Initializer Fast_Initializer_array64[64];

/*  ::hyve::Fast::Parser::stagedId */
typedef struct Fast_Parser_stagedId Fast_Parser_stagedId;
struct Fast_Parser_stagedId {
    db_string name;
    db_bool found;
    db_uint32 line;
    db_uint32 column;
};
typedef Fast_Parser_stagedId Fast_Parser_stagedId_array64[64];
typedef Fast_Lvalue Fast_Lvalue_array64[64];
typedef db_type db_type_array64[64];

/*  ::hyve::Fast::Parser */
DB_CLASS(Fast_Parser);
DB_CLASS_DEF(Fast_Parser) {
    db_string source;
    db_string preprocessed;
    db_string filename;
    db_uint32 line;
    db_uint32 column;
    db_string token;
    Fast_Block block;
    Fast_Variable scope;
    db_uint32 errors;
    db_uint32 warnings;
    db_bool errSet;
    db_uint32 errLine;
    db_bool abort;
    Fast_Binding_list bindings;
    db_uint32 pass;
    db_word_list heapCollected;
    Fast_Object_list collected;
    db_bool blockPreset;
    db_bool isLocal;
    db_bool parseSingleExpr;
    Fast_Expression singleExpr;
    db_string lastFailedResolve;
    Fast_Variable_array64 variables;
    db_uint32 variableCount;
    db_bool variablesInitialized;
    db_bool variablePushed;
    Fast_Initializer_array64 initializers;
    db_int8 initializerCount;
    db_uint32 initAnonymousId;
    db_bool initDynamic;
    Fast_Parser_stagedId_array64 staged;
    db_uint32 stagedCount;
    db_bool stagingAllowed;
    Fast_Lvalue_array64 lvalue;
    db_int32 lvalueSp;
    db_type_array64 complexType;
    db_int32 complexTypeSp;
};

/*  ::hyve::Fast::ParserDeclaration */
typedef struct Fast_ParserDeclaration Fast_ParserDeclaration;
struct Fast_ParserDeclaration {
    db_string name;
    Fast_Variable variable;
};
DB_SEQUENCE(Fast_ParserDeclaration_seq256, Fast_ParserDeclaration,);
typedef Fast_ParserDeclaration_seq256 Fast_ParserDeclarationSeq;

/*  ::hyve::Fast::ParserNew */
typedef struct Fast_ParserNew Fast_ParserNew;
struct Fast_ParserNew {
    Fast_nodeKind kind;
    Fast_Expression parent;
    Fast_Expression name;
    Fast_Expression attr;
};

/*  ::hyve::Fast::PostfixExpr */
DB_CLASS(Fast_PostfixExpr);
DB_CLASS_DEF(Fast_PostfixExpr) {
    DB_EXTEND(Fast_Expression);
    Fast_Expression lvalue;
    db_operatorKind operator;
};

/*  ::hyve::Fast::SignedInteger */
DB_CLASS(Fast_SignedInteger);
DB_CLASS_DEF(Fast_SignedInteger) {
    DB_EXTEND(Fast_Literal);
    db_int64 value;
};
typedef db_word db_word_array64[64];

/*  ::hyve::Fast::StaticInitializerFrame */
typedef struct Fast_StaticInitializerFrame Fast_StaticInitializerFrame;
struct Fast_StaticInitializerFrame {
    db_word_array64 ptr;
    db_word_array64 keyPtr;
};
typedef Fast_StaticInitializerFrame Fast_StaticInitializerFrame_array64[64];

/*  ::hyve::Fast::StaticInitializer */
DB_CLASS(Fast_StaticInitializer);
DB_CLASS_DEF(Fast_StaticInitializer) {
    DB_EXTEND(Fast_Initializer);
    Fast_StaticInitializerFrame_array64 frames;
};

/*  ::hyve::Fast::String */
DB_CLASS(Fast_String);
DB_CLASS_DEF(Fast_String) {
    DB_EXTEND(Fast_Literal);
    db_string value;
    Fast_Expression_list elements;
    Fast_Block block;
    Fast_Variable scope;
};

/*  ::hyve::Fast::Template */
DB_CLASS(Fast_Template);
DB_CLASS_DEF(Fast_Template) {
    DB_EXTEND(Fast_Local);
};

/*  ::hyve::Fast::TernaryExpr */
DB_CLASS(Fast_TernaryExpr);
DB_CLASS_DEF(Fast_TernaryExpr) {
    DB_EXTEND(Fast_Expression);
    Fast_Expression condition;
    Fast_Expression ifTrue;
    Fast_Expression ifFalse;
    Fast_Expression ifTrueExpr;
    Fast_Expression ifFalseExpr;
    Fast_Expression result;
    Fast_If ifstmt;
};

/*  ::hyve::Fast::UnaryExpr */
DB_CLASS(Fast_UnaryExpr);
DB_CLASS_DEF(Fast_UnaryExpr) {
    DB_EXTEND(Fast_Expression);
    Fast_Expression lvalue;
    db_operatorKind operator;
};

/*  ::hyve::Fast::Update */
DB_CLASS(Fast_Update);
DB_CLASS_DEF(Fast_Update) {
    DB_EXTEND(Fast_Node);
    Fast_Expression_list exprList;
    Fast_Block block;
    Fast_Expression from;
};

/*  ::hyve::Fast::Wait */
DB_CLASS(Fast_Wait);
DB_CLASS_DEF(Fast_Wait) {
    DB_EXTEND(Fast_Expression);
    Fast_Expression_list exprList;
    Fast_Expression timeout;
};

#ifdef __cplusplus
}
#endif
#endif

