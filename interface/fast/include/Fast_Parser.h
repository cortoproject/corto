/* Fast_Parser.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef Fast_Parser_H
#define Fast_Parser_H

#include "hyve.h"
#include "Fast__type.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::hyve::Fast::Parser::addStatement(Fast::Node statement) */
void Fast_Parser_addStatement(Fast_Parser _this, Fast_Node statement);

/* ::hyve::Fast::Parser::argumentToString(Fast::Variable type,lang::string id,lang::bool reference) */
db_string Fast_Parser_argumentToString(Fast_Parser _this, Fast_Variable type, db_string id, db_bool reference);

/* ::hyve::Fast::Parser::binaryExpr(Fast::Expression lvalues,Fast::Expression rvalues,lang::operatorKind operator) */
Fast_Expression Fast_Parser_binaryExpr(Fast_Parser _this, Fast_Expression lvalues, Fast_Expression rvalues, db_operatorKind operator);

/* ::hyve::Fast::Parser::bind(Fast::Variable function,Fast::Block block) */
db_int16 Fast_Parser_bind(Fast_Parser _this, Fast_Variable function, Fast_Block block);

/* ::hyve::Fast::Parser::bindOneliner(Fast::Variable function,Fast::Block block,Fast::Expression expr) */
db_int16 Fast_Parser_bindOneliner(Fast_Parser _this, Fast_Variable function, Fast_Block block, Fast_Expression expr);

/* ::hyve::Fast::Parser::blockPop() */
void Fast_Parser_blockPop(Fast_Parser _this);

/* ::hyve::Fast::Parser::blockPush(lang::bool presetBlock) */
Fast_Block Fast_Parser_blockPush(Fast_Parser _this, db_bool presetBlock);

/* ::hyve::Fast::Parser::callExpr(Fast::Expression function,Fast::Expression arguments) */
Fast_Expression Fast_Parser_callExpr(Fast_Parser _this, Fast_Expression function, Fast_Expression arguments);

/* ::hyve::Fast::Parser::castExpr(Fast::Expression lvalue,Fast::Expression rvalue) */
Fast_Expression Fast_Parser_castExpr(Fast_Parser _this, Fast_Expression lvalue, Fast_Expression rvalue);

/* ::hyve::Fast::Parser::collect(lang::object o) */
db_void Fast_Parser_collect(Fast_Parser _this, db_object o);

/* ::hyve::Fast::Parser::collectHeap(word addr) */
db_void Fast_Parser_collectHeap(Fast_Parser _this, db_word addr);

/* callback ::hyve::lang::class::construct(lang::object object) -> ::hyve::Fast::Parser::construct(Parser object) */
db_int16 Fast_Parser_construct(Fast_Parser object);

/* ::hyve::Fast::Parser::declaration(Variable type,lang::string id,lang::bool isReference) */
Fast_Variable Fast_Parser_declaration(Fast_Parser _this, Fast_Variable type, db_string id, db_bool isReference);

/* ::hyve::Fast::Parser::declareFunction(Variable returnType,lang::string id,lang::procedure kind,bool returnsReference) */
Fast_Variable Fast_Parser_declareFunction(Fast_Parser _this, Fast_Variable returnType, db_string id, db_procedure kind, db_bool returnsReference);

/* ::hyve::Fast::Parser::declareFunctionParams(Variable function) */
Fast_Block Fast_Parser_declareFunctionParams(Fast_Parser _this, Fast_Variable function);

/* ::hyve::Fast::Parser::define() */
db_int16 Fast_Parser_define(Fast_Parser _this);

/* ::hyve::Fast::Parser::defineScope() */
db_int16 Fast_Parser_defineScope(Fast_Parser _this);

/* ::hyve::Fast::Parser::defineVariable(Variable object) */
db_int16 Fast_Parser_defineVariable(Fast_Parser _this, Fast_Variable object);

/* callback ::hyve::lang::class::destruct(lang::object object) -> ::hyve::Fast::Parser::destruct(Parser object) */
void Fast_Parser_destruct(Fast_Parser object);

/* ::hyve::Fast::Parser::elementExpr(Fast::Expression lvalue,Fast::Expression rvalue) */
Fast_Expression Fast_Parser_elementExpr(Fast_Parser _this, Fast_Expression lvalue, Fast_Expression rvalue);

/* ::hyve::Fast::Parser::foreach(lang::string loopId,Fast::Expression collection) */
db_int16 Fast_Parser_foreach(Fast_Parser _this, db_string loopId, Fast_Expression collection);

/* ::hyve::Fast::Parser::getComplexType() */
db_type Fast_Parser_getComplexType(Fast_Parser _this);

/* ::hyve::Fast::Parser::getLvalue(lang::bool assignment) */
Fast_Expression Fast_Parser_getLvalue(Fast_Parser _this, db_bool assignment);

/* ::hyve::Fast::Parser::getLvalueType(lang::bool assignment) */
db_type Fast_Parser_getLvalueType(Fast_Parser _this, db_bool assignment);

/* ::hyve::Fast::Parser::ifStatement(Fast::Expression condition,Fast::Block trueBranch,Fast::If falseBranch) */
Fast_Node Fast_Parser_ifStatement(Fast_Parser _this, Fast_Expression condition, Fast_Block trueBranch, Fast_If falseBranch);

/* ::hyve::Fast::Parser::initDeclareStaged(Fast::Expression expr) */
void Fast_Parser_initDeclareStaged(Fast_Parser _this, Fast_Expression expr);

/* ::hyve::Fast::Parser::initKeyValuePop() */
db_int16 Fast_Parser_initKeyValuePop(Fast_Parser _this);

/* ::hyve::Fast::Parser::initKeyValuePush() */
db_int16 Fast_Parser_initKeyValuePush(Fast_Parser _this);

/* ::hyve::Fast::Parser::initKeyValueSet(Fast::Expression expr) */
db_int16 Fast_Parser_initKeyValueSet(Fast_Parser _this, Fast_Expression expr);

/* ::hyve::Fast::Parser::initMember(lang::string member) */
db_int16 Fast_Parser_initMember(Fast_Parser _this, db_string member);

/* ::hyve::Fast::Parser::initPop() */
db_int16 Fast_Parser_initPop(Fast_Parser _this);

/* ::hyve::Fast::Parser::initPush() */
db_int16 Fast_Parser_initPush(Fast_Parser _this);

/* ::hyve::Fast::Parser::initPushExpression() */
Fast_Expression Fast_Parser_initPushExpression(Fast_Parser _this);

/* ::hyve::Fast::Parser::initPushIdentifier(Expression type) */
Fast_Expression Fast_Parser_initPushIdentifier(Fast_Parser _this, Fast_Expression type);

/* ::hyve::Fast::Parser::initPushStatic() */
db_int16 Fast_Parser_initPushStatic(Fast_Parser _this);

/* ::hyve::Fast::Parser::initStage(lang::string id,bool found) */
void Fast_Parser_initStage(Fast_Parser _this, db_string id, db_bool found);

/* ::hyve::Fast::Parser::initValue(Expression expr) */
db_int16 Fast_Parser_initValue(Fast_Parser _this, Fast_Expression expr);

/* ::hyve::Fast::Parser::isAbortSet() */
db_bool Fast_Parser_isAbortSet(Fast_Parser _this);

/* ::hyve::Fast::Parser::isErrSet() */
db_bool Fast_Parser_isErrSet(Fast_Parser _this);

/* ::hyve::Fast::Parser::lookup(lang::string id,lang::object source) */
Fast_Expression Fast_Parser_lookup(Fast_Parser _this, db_string id, db_object source);

/* ::hyve::Fast::Parser::memberExpr(Fast::Expression lvalue,Fast::Expression rvalue) */
Fast_Expression Fast_Parser_memberExpr(Fast_Parser _this, Fast_Expression lvalue, Fast_Expression rvalue);

/* ::hyve::Fast::Parser::observerDeclaration(lang::string id,Fast::Expression object,lang::eventMask mask,Fast::Object dispatcher) */
Fast_Variable Fast_Parser_observerDeclaration(Fast_Parser _this, db_string id, Fast_Expression object, db_eventMask mask, Fast_Object dispatcher);

/* ::hyve::Fast::Parser::observerPop() */
void Fast_Parser_observerPop(Fast_Parser _this);

/* ::hyve::Fast::Parser::observerPush() */
void Fast_Parser_observerPush(Fast_Parser _this);

/* ::hyve::Fast::Parser::parse() */
db_uint32 Fast_Parser_parse(Fast_Parser _this);

/* ::hyve::Fast::Parser::parseExpression(lang::string expr,Fast::Block block,Fast::Variable scope,uint32 line,uint32 column) */
Fast_Expression Fast_Parser_parseExpression(Fast_Parser _this, db_string expr, Fast_Block block, Fast_Variable scope, db_uint32 line, db_uint32 column);

/* ::hyve::Fast::Parser::popComplexType() */
void Fast_Parser_popComplexType(Fast_Parser _this);

/* ::hyve::Fast::Parser::popLvalue() */
void Fast_Parser_popLvalue(Fast_Parser _this);

/* ::hyve::Fast::Parser::popScope(Fast::Variable previous) */
void Fast_Parser_popScope(Fast_Parser _this, Fast_Variable previous);

/* ::hyve::Fast::Parser::postfixExpr(Fast::Expression lvalue,lang::operatorKind operator) */
Fast_Expression Fast_Parser_postfixExpr(Fast_Parser _this, Fast_Expression lvalue, db_operatorKind operator);

/* ::hyve::Fast::Parser::pushComplexType(Fast::Expression lvalue) */
void Fast_Parser_pushComplexType(Fast_Parser _this, Fast_Expression lvalue);

/* ::hyve::Fast::Parser::pushLvalue(Fast::Expression lvalue,lang::bool isAssignment) */
void Fast_Parser_pushLvalue(Fast_Parser _this, Fast_Expression lvalue, db_bool isAssignment);

/* ::hyve::Fast::Parser::pushReturnAsLvalue(lang::function function) */
void Fast_Parser_pushReturnAsLvalue(Fast_Parser _this, db_function function);

/* ::hyve::Fast::Parser::pushScope() */
Fast_Variable Fast_Parser_pushScope(Fast_Parser _this);

/* ::hyve::Fast::Parser::reset() */
void Fast_Parser_reset(Fast_Parser _this);

/* ::hyve::Fast::Parser::ternaryExpr(Fast::Expression cond,Fast::Expression iftrue,Fast::Expression iffalse) */
Fast_Expression Fast_Parser_ternaryExpr(Fast_Parser _this, Fast_Expression cond, Fast_Expression iftrue, Fast_Expression iffalse);

/* ::hyve::Fast::Parser::unaryExpr(Fast::Expression lvalue,lang::operatorKind operator) */
Fast_Expression Fast_Parser_unaryExpr(Fast_Parser _this, Fast_Expression lvalue, db_operatorKind operator);

/* ::hyve::Fast::Parser::updateStatement(Fast::Expression expr,Fast::Block block) */
Fast_Node Fast_Parser_updateStatement(Fast_Parser _this, Fast_Expression expr, Fast_Block block);

/* ::hyve::Fast::Parser::waitExpr(list{Fast::Expression} exprList,Fast::Expression timeout) */
Fast_Expression Fast_Parser_waitExpr(Fast_Parser _this, Fast_Expression_list exprList, Fast_Expression timeout);

/* ::hyve::Fast::Parser::whileStatement(Fast::Expression condition,Fast::Block trueBranch,lang::bool isUntil) */
Fast_Node Fast_Parser_whileStatement(Fast_Parser _this, Fast_Expression condition, Fast_Block trueBranch, db_bool isUntil);

#ifdef __cplusplus
}
#endif
#endif

