/* Fast_Parser.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef Fast_Parser_H
#define Fast_Parser_H

#include "corto.h"
#include "Fast__type.h"
#include "Fast__api.h"
#include "Fast__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::corto::Fast::Parser::addStatement(Fast::Node statement) */
cx_void _Fast_Parser_addStatement(Fast_Parser _this, Fast_Node statement);
#define Fast_Parser_addStatement(_this, statement) _Fast_Parser_addStatement(Fast_Parser(_this), Fast_Node(statement))

/* ::corto::Fast::Parser::argumentToString(type type,string id,bool reference) */
cx_string _Fast_Parser_argumentToString(Fast_Parser _this, cx_type type, cx_string id, cx_bool reference);
#define Fast_Parser_argumentToString(_this, type, id, reference) _Fast_Parser_argumentToString(Fast_Parser(_this), cx_type(type), id, reference)

/* ::corto::Fast::Parser::binaryExpr(Fast::Expression lvalues,Fast::Expression rvalues,operatorKind operator) */
Fast_Node _Fast_Parser_binaryExpr(Fast_Parser _this, Fast_Expression lvalues, Fast_Expression rvalues, cx_operatorKind operator);
#define Fast_Parser_binaryExpr(_this, lvalues, rvalues, operator) _Fast_Parser_binaryExpr(Fast_Parser(_this), Fast_Expression(lvalues), Fast_Expression(rvalues), operator)

/* ::corto::Fast::Parser::bind(Fast::Storage function,Fast::Block block) */
cx_int16 _Fast_Parser_bind(Fast_Parser _this, Fast_Storage function, Fast_Block block);
#define Fast_Parser_bind(_this, function, block) _Fast_Parser_bind(Fast_Parser(_this), Fast_Storage(function), Fast_Block(block))

/* ::corto::Fast::Parser::bindOneliner(Fast::Storage function,Fast::Block block,Fast::Expression expr) */
cx_int16 _Fast_Parser_bindOneliner(Fast_Parser _this, Fast_Storage function, Fast_Block block, Fast_Expression expr);
#define Fast_Parser_bindOneliner(_this, function, block, expr) _Fast_Parser_bindOneliner(Fast_Parser(_this), Fast_Storage(function), Fast_Block(block), Fast_Expression(expr))

/* ::corto::Fast::Parser::blockPop() */
cx_void _Fast_Parser_blockPop(Fast_Parser _this);
#define Fast_Parser_blockPop(_this) _Fast_Parser_blockPop(Fast_Parser(_this))

/* ::corto::Fast::Parser::blockPush(bool presetBlock) */
Fast_Block _Fast_Parser_blockPush(Fast_Parser _this, cx_bool presetBlock);
#define Fast_Parser_blockPush(_this, presetBlock) _Fast_Parser_blockPush(Fast_Parser(_this), presetBlock)

/* ::corto::Fast::Parser::callExpr(Fast::Expression function,Fast::Expression arguments) */
Fast_Expression _Fast_Parser_callExpr(Fast_Parser _this, Fast_Expression function, Fast_Expression arguments);
#define Fast_Parser_callExpr(_this, function, arguments) _Fast_Parser_callExpr(Fast_Parser(_this), Fast_Expression(function), Fast_Expression(arguments))

/* ::corto::Fast::Parser::castExpr(type lvalue,Fast::Expression rvalue) */
Fast_Expression _Fast_Parser_castExpr(Fast_Parser _this, cx_type lvalue, Fast_Expression rvalue);
#define Fast_Parser_castExpr(_this, lvalue, rvalue) _Fast_Parser_castExpr(Fast_Parser(_this), cx_type(lvalue), Fast_Expression(rvalue))

/* ::corto::Fast::Parser::collect(object o) */
cx_void _Fast_Parser_collect(Fast_Parser _this, cx_object o);
#define Fast_Parser_collect(_this, o) _Fast_Parser_collect(Fast_Parser(_this), o)

/* ::corto::Fast::Parser::collectHeap(word addr) */
cx_void _Fast_Parser_collectHeap(Fast_Parser _this, cx_word addr);
#define Fast_Parser_collectHeap(_this, addr) _Fast_Parser_collectHeap(Fast_Parser(_this), addr)

/* ::corto::Fast::Parser::construct() */
cx_int16 _Fast_Parser_construct(Fast_Parser _this);
#define Fast_Parser_construct(_this) _Fast_Parser_construct(Fast_Parser(_this))

/* ::corto::Fast::Parser::declaration(type type,string id,bool isReference) */
Fast_Storage _Fast_Parser_declaration(Fast_Parser _this, cx_type type, cx_string id, cx_bool isReference);
#define Fast_Parser_declaration(_this, type, id, isReference) _Fast_Parser_declaration(Fast_Parser(_this), cx_type(type), id, isReference)

/* ::corto::Fast::Parser::declareFunction(type returnType,string id,type kind,bool returnsReference) */
Fast_Storage _Fast_Parser_declareFunction(Fast_Parser _this, cx_type returnType, cx_string id, cx_type kind, cx_bool returnsReference);
#define Fast_Parser_declareFunction(_this, returnType, id, kind, returnsReference) _Fast_Parser_declareFunction(Fast_Parser(_this), cx_type(returnType), id, cx_type(kind), returnsReference)

/* ::corto::Fast::Parser::declareFunctionParams(Storage function) */
Fast_Block _Fast_Parser_declareFunctionParams(Fast_Parser _this, Fast_Storage function);
#define Fast_Parser_declareFunctionParams(_this, function) _Fast_Parser_declareFunctionParams(Fast_Parser(_this), Fast_Storage(function))

/* ::corto::Fast::Parser::define() */
cx_int16 _Fast_Parser_define(Fast_Parser _this);
#define Fast_Parser_define(_this) _Fast_Parser_define(Fast_Parser(_this))

/* ::corto::Fast::Parser::defineScope() */
cx_int16 _Fast_Parser_defineScope(Fast_Parser _this);
#define Fast_Parser_defineScope(_this) _Fast_Parser_defineScope(Fast_Parser(_this))

/* ::corto::Fast::Parser::defineVariable(Storage object) */
cx_int16 _Fast_Parser_defineVariable(Fast_Parser _this, Fast_Storage object);
#define Fast_Parser_defineVariable(_this, object) _Fast_Parser_defineVariable(Fast_Parser(_this), Fast_Storage(object))

/* ::corto::Fast::Parser::destruct() */
cx_void _Fast_Parser_destruct(Fast_Parser _this);
#define Fast_Parser_destruct(_this) _Fast_Parser_destruct(Fast_Parser(_this))

/* ::corto::Fast::Parser::elementExpr(Fast::Expression lvalue,Fast::Expression rvalue) */
Fast_Expression _Fast_Parser_elementExpr(Fast_Parser _this, Fast_Expression lvalue, Fast_Expression rvalue);
#define Fast_Parser_elementExpr(_this, lvalue, rvalue) _Fast_Parser_elementExpr(Fast_Parser(_this), Fast_Expression(lvalue), Fast_Expression(rvalue))

/* ::corto::Fast::Parser::finalize(ic::program program) */
cx_int16 _Fast_Parser_finalize(Fast_Parser _this, ic_program program);
#define Fast_Parser_finalize(_this, program) _Fast_Parser_finalize(Fast_Parser(_this), ic_program(program))

/* ::corto::Fast::Parser::foreach(string loopId,Fast::Expression collection) */
cx_int16 _Fast_Parser_foreach(Fast_Parser _this, cx_string loopId, Fast_Expression collection);
#define Fast_Parser_foreach(_this, loopId, collection) _Fast_Parser_foreach(Fast_Parser(_this), loopId, Fast_Expression(collection))

/* ::corto::Fast::Parser::getComplexType() */
cx_type _Fast_Parser_getComplexType(Fast_Parser _this);
#define Fast_Parser_getComplexType(_this) _Fast_Parser_getComplexType(Fast_Parser(_this))

/* ::corto::Fast::Parser::getLvalue(bool assignment) */
Fast_Expression _Fast_Parser_getLvalue(Fast_Parser _this, cx_bool assignment);
#define Fast_Parser_getLvalue(_this, assignment) _Fast_Parser_getLvalue(Fast_Parser(_this), assignment)

/* ::corto::Fast::Parser::getLvalueType(bool assignment) */
cx_type _Fast_Parser_getLvalueType(Fast_Parser _this, cx_bool assignment);
#define Fast_Parser_getLvalueType(_this, assignment) _Fast_Parser_getLvalueType(Fast_Parser(_this), assignment)

/* ::corto::Fast::Parser::ifStatement(Fast::Expression condition,Fast::Block trueBranch,Fast::If falseBranch) */
Fast_Node _Fast_Parser_ifStatement(Fast_Parser _this, Fast_Expression condition, Fast_Block trueBranch, Fast_If falseBranch);
#define Fast_Parser_ifStatement(_this, condition, trueBranch, falseBranch) _Fast_Parser_ifStatement(Fast_Parser(_this), Fast_Expression(condition), Fast_Block(trueBranch), Fast_If(falseBranch))

/* ::corto::Fast::Parser::initDeclareStaged(Fast::Expression expr) */
cx_void _Fast_Parser_initDeclareStaged(Fast_Parser _this, Fast_Expression expr);
#define Fast_Parser_initDeclareStaged(_this, expr) _Fast_Parser_initDeclareStaged(Fast_Parser(_this), Fast_Expression(expr))

/* ::corto::Fast::Parser::initKeyValuePop() */
cx_int16 _Fast_Parser_initKeyValuePop(Fast_Parser _this);
#define Fast_Parser_initKeyValuePop(_this) _Fast_Parser_initKeyValuePop(Fast_Parser(_this))

/* ::corto::Fast::Parser::initKeyValuePush() */
cx_int16 _Fast_Parser_initKeyValuePush(Fast_Parser _this);
#define Fast_Parser_initKeyValuePush(_this) _Fast_Parser_initKeyValuePush(Fast_Parser(_this))

/* ::corto::Fast::Parser::initKeyValueSet(Fast::Expression expr) */
cx_int16 _Fast_Parser_initKeyValueSet(Fast_Parser _this, Fast_Expression expr);
#define Fast_Parser_initKeyValueSet(_this, expr) _Fast_Parser_initKeyValueSet(Fast_Parser(_this), Fast_Expression(expr))

/* ::corto::Fast::Parser::initMember(string member) */
cx_int16 _Fast_Parser_initMember(Fast_Parser _this, cx_string member);
#define Fast_Parser_initMember(_this, member) _Fast_Parser_initMember(Fast_Parser(_this), member)

/* ::corto::Fast::Parser::initPop() */
cx_int16 _Fast_Parser_initPop(Fast_Parser _this);
#define Fast_Parser_initPop(_this) _Fast_Parser_initPop(Fast_Parser(_this))

/* ::corto::Fast::Parser::initPush() */
cx_int16 _Fast_Parser_initPush(Fast_Parser _this);
#define Fast_Parser_initPush(_this) _Fast_Parser_initPush(Fast_Parser(_this))

/* ::corto::Fast::Parser::initPushExpression() */
Fast_Expression _Fast_Parser_initPushExpression(Fast_Parser _this);
#define Fast_Parser_initPushExpression(_this) _Fast_Parser_initPushExpression(Fast_Parser(_this))

/* ::corto::Fast::Parser::initPushIdentifier(Expression type) */
Fast_Expression _Fast_Parser_initPushIdentifier(Fast_Parser _this, Fast_Expression type);
#define Fast_Parser_initPushIdentifier(_this, type) _Fast_Parser_initPushIdentifier(Fast_Parser(_this), Fast_Expression(type))

/* ::corto::Fast::Parser::initPushStatic() */
cx_int16 _Fast_Parser_initPushStatic(Fast_Parser _this);
#define Fast_Parser_initPushStatic(_this) _Fast_Parser_initPushStatic(Fast_Parser(_this))

/* ::corto::Fast::Parser::initStage(string id,bool found) */
cx_void _Fast_Parser_initStage(Fast_Parser _this, cx_string id, cx_bool found);
#define Fast_Parser_initStage(_this, id, found) _Fast_Parser_initStage(Fast_Parser(_this), id, found)

/* ::corto::Fast::Parser::initValue(Expression expr) */
cx_int16 _Fast_Parser_initValue(Fast_Parser _this, Fast_Expression expr);
#define Fast_Parser_initValue(_this, expr) _Fast_Parser_initValue(Fast_Parser(_this), Fast_Expression(expr))

/* ::corto::Fast::Parser::isAbortSet() */
cx_bool _Fast_Parser_isAbortSet(Fast_Parser _this);
#define Fast_Parser_isAbortSet(_this) _Fast_Parser_isAbortSet(Fast_Parser(_this))

/* ::corto::Fast::Parser::isErrSet() */
cx_bool _Fast_Parser_isErrSet(Fast_Parser _this);
#define Fast_Parser_isErrSet(_this) _Fast_Parser_isErrSet(Fast_Parser(_this))

/* ::corto::Fast::Parser::lookup(string id) */
Fast_Expression _Fast_Parser_lookup(Fast_Parser _this, cx_string id);
#define Fast_Parser_lookup(_this, id) _Fast_Parser_lookup(Fast_Parser(_this), id)

/* ::corto::Fast::Parser::memberExpr(Fast::Expression lvalue,Fast::Expression rvalue) */
Fast_Expression _Fast_Parser_memberExpr(Fast_Parser _this, Fast_Expression lvalue, Fast_Expression rvalue);
#define Fast_Parser_memberExpr(_this, lvalue, rvalue) _Fast_Parser_memberExpr(Fast_Parser(_this), Fast_Expression(lvalue), Fast_Expression(rvalue))

/* ::corto::Fast::Parser::observerDeclaration(string id,Fast::Expression object,eventMask mask,Fast::Object dispatcher) */
Fast_Storage _Fast_Parser_observerDeclaration(Fast_Parser _this, cx_string id, Fast_Expression object, cx_eventMask mask, Fast_Object dispatcher);
#define Fast_Parser_observerDeclaration(_this, id, object, mask, dispatcher) _Fast_Parser_observerDeclaration(Fast_Parser(_this), id, Fast_Expression(object), mask, Fast_Object(dispatcher))

/* ::corto::Fast::Parser::observerPush() */
cx_void _Fast_Parser_observerPush(Fast_Parser _this);
#define Fast_Parser_observerPush(_this) _Fast_Parser_observerPush(Fast_Parser(_this))

/* ::corto::Fast::Parser::parse() */
cx_uint32 _Fast_Parser_parse(Fast_Parser _this);
#define Fast_Parser_parse(_this) _Fast_Parser_parse(Fast_Parser(_this))

/* ::corto::Fast::Parser::parseExpression(string expr,Fast::Block block,object scope,uint32 line,uint32 column) */
Fast_Expression _Fast_Parser_parseExpression(Fast_Parser _this, cx_string expr, Fast_Block block, cx_object scope, cx_uint32 line, cx_uint32 column);
#define Fast_Parser_parseExpression(_this, expr, block, scope, line, column) _Fast_Parser_parseExpression(Fast_Parser(_this), expr, Fast_Block(block), scope, line, column)

/* ::corto::Fast::Parser::parseLine(string expr,object scope,word value) */
cx_int16 _Fast_Parser_parseLine(cx_string expr, cx_object scope, cx_word value);
#define Fast_Parser_parseLine(expr, scope, value) _Fast_Parser_parseLine(expr, scope, value)

/* ::corto::Fast::Parser::popComplexType() */
cx_void _Fast_Parser_popComplexType(Fast_Parser _this);
#define Fast_Parser_popComplexType(_this) _Fast_Parser_popComplexType(Fast_Parser(_this))

/* ::corto::Fast::Parser::popLvalue() */
cx_void _Fast_Parser_popLvalue(Fast_Parser _this);
#define Fast_Parser_popLvalue(_this) _Fast_Parser_popLvalue(Fast_Parser(_this))

/* ::corto::Fast::Parser::popScope(object previous) */
cx_void _Fast_Parser_popScope(Fast_Parser _this, cx_object previous);
#define Fast_Parser_popScope(_this, previous) _Fast_Parser_popScope(Fast_Parser(_this), previous)

/* ::corto::Fast::Parser::postfixExpr(Fast::Expression lvalue,operatorKind operator) */
Fast_Expression _Fast_Parser_postfixExpr(Fast_Parser _this, Fast_Expression lvalue, cx_operatorKind operator);
#define Fast_Parser_postfixExpr(_this, lvalue, operator) _Fast_Parser_postfixExpr(Fast_Parser(_this), Fast_Expression(lvalue), operator)

/* ::corto::Fast::Parser::pushComplexType(Fast::Expression lvalue) */
cx_void _Fast_Parser_pushComplexType(Fast_Parser _this, Fast_Expression lvalue);
#define Fast_Parser_pushComplexType(_this, lvalue) _Fast_Parser_pushComplexType(Fast_Parser(_this), Fast_Expression(lvalue))

/* ::corto::Fast::Parser::pushLvalue(Fast::Expression lvalue,bool isAssignment) */
cx_void _Fast_Parser_pushLvalue(Fast_Parser _this, Fast_Expression lvalue, cx_bool isAssignment);
#define Fast_Parser_pushLvalue(_this, lvalue, isAssignment) _Fast_Parser_pushLvalue(Fast_Parser(_this), Fast_Expression(lvalue), isAssignment)

/* ::corto::Fast::Parser::pushPackage(string name) */
cx_int16 _Fast_Parser_pushPackage(Fast_Parser _this, cx_string name);
#define Fast_Parser_pushPackage(_this, name) _Fast_Parser_pushPackage(Fast_Parser(_this), name)

/* ::corto::Fast::Parser::pushReturnAsLvalue(function function) */
cx_void _Fast_Parser_pushReturnAsLvalue(Fast_Parser _this, cx_function function);
#define Fast_Parser_pushReturnAsLvalue(_this, function) _Fast_Parser_pushReturnAsLvalue(Fast_Parser(_this), cx_function(function))

/* ::corto::Fast::Parser::pushScope() */
cx_object _Fast_Parser_pushScope(Fast_Parser _this);
#define Fast_Parser_pushScope(_this) _Fast_Parser_pushScope(Fast_Parser(_this))

/* ::corto::Fast::Parser::reset() */
cx_void _Fast_Parser_reset(Fast_Parser _this);
#define Fast_Parser_reset(_this) _Fast_Parser_reset(Fast_Parser(_this))

/* ::corto::Fast::Parser::ternaryExpr(Fast::Expression cond,Fast::Expression iftrue,Fast::Expression iffalse) */
Fast_Expression _Fast_Parser_ternaryExpr(Fast_Parser _this, Fast_Expression cond, Fast_Expression iftrue, Fast_Expression iffalse);
#define Fast_Parser_ternaryExpr(_this, cond, iftrue, iffalse) _Fast_Parser_ternaryExpr(Fast_Parser(_this), Fast_Expression(cond), Fast_Expression(iftrue), Fast_Expression(iffalse))

/* ::corto::Fast::Parser::unaryExpr(Fast::Expression lvalue,operatorKind operator) */
Fast_Expression _Fast_Parser_unaryExpr(Fast_Parser _this, Fast_Expression lvalue, cx_operatorKind operator);
#define Fast_Parser_unaryExpr(_this, lvalue, operator) _Fast_Parser_unaryExpr(Fast_Parser(_this), Fast_Expression(lvalue), operator)

/* ::corto::Fast::Parser::updateStatement(Fast::Expression expr,Fast::Block block) */
Fast_Node _Fast_Parser_updateStatement(Fast_Parser _this, Fast_Expression expr, Fast_Block block);
#define Fast_Parser_updateStatement(_this, expr, block) _Fast_Parser_updateStatement(Fast_Parser(_this), Fast_Expression(expr), Fast_Block(block))

/* ::corto::Fast::Parser::waitExpr(Fast::Expression expr,Fast::Expression timeout) */
Fast_Expression _Fast_Parser_waitExpr(Fast_Parser _this, Fast_Expression expr, Fast_Expression timeout);
#define Fast_Parser_waitExpr(_this, expr, timeout) _Fast_Parser_waitExpr(Fast_Parser(_this), Fast_Expression(expr), Fast_Expression(timeout))

/* ::corto::Fast::Parser::whileStatement(Fast::Expression condition,Fast::Block trueBranch,bool isUntil) */
Fast_Node _Fast_Parser_whileStatement(Fast_Parser _this, Fast_Expression condition, Fast_Block trueBranch, cx_bool isUntil);
#define Fast_Parser_whileStatement(_this, condition, trueBranch, isUntil) _Fast_Parser_whileStatement(Fast_Parser(_this), Fast_Expression(condition), Fast_Block(trueBranch), isUntil)

#ifdef __cplusplus
}
#endif
#endif

