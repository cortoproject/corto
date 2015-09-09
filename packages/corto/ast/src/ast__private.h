#ifndef ast__Private_H
#define ast__Private_H

#include "ast.h"

#ifdef __cplusplus
extern "C" {
#endif

void ast_Parser_error(ast_Parser _this, char* fmt, ... );
void ast_Parser_warning(ast_Parser _this, char* fmt, ... );
cx_string ast_Parser_id(cx_object o, cx_id buffer);
ast_Parser yparser(void);
int fast_yparse(ast_Parser parser, cx_uint32 line, cx_uint32 column);
ast_Expression ast_Expression_narrow(ast_Expression expr, cx_type target);
cx_type ast_Expression_narrowType(ast_Expression expr);
cx_int8 ast_Expression_getCastScore(cx_primitive t);
cx_int8 ast_Expression_getTypeScore(cx_primitive t);
ast_Expression ast_Node_optimizeCondition(ast_Expression condition, cx_bool *staticResult, cx_bool *inverse);
ast_Call ast_createCall(ast_Expression instance, cx_string function, cx_uint32 numArgs, ...);
ast_Call ast_createCallWithArguments(ast_Expression instance, cx_string function, ast_Expression arguments);
ast_Call ast_createCallFromExpr(ast_Expression f, ast_Expression arguments);

/* Convenience macro's for IC generation */
#define IC_1_OP(line, opkind, _op, deref, any)\
    ic_opCreate(line, opkind, ic_node(_op), NULL, NULL, deref, IC_DEREF_VALUE, IC_DEREF_VALUE, any)

#define IC_1(program, line, opkind, op, deref)\
    ic_program_add(program, ic_node( IC_1_OP(line, opkind, op, deref, FALSE) ) );

#define IC_1_ANY(program, line, opkind, op, deref)\
    ic_program_add(program, ic_node(\
        ic_opCreate(\
            line, opkind, ic_node(op), NULL, NULL, deref, IC_DEREF_VALUE, IC_DEREF_VALUE, TRUE)));

#define IC_2(program, line, opkind, op1, op2, deref1, deref2)\
    ic_program_add(program, ic_node(\
        ic_opCreate(\
            line, opkind, NULL, ic_node(op1), ic_node(op2), IC_DEREF_VALUE, deref1, deref2, FALSE)));

#define IC_3(program, line, opkind, op1, op2, op3, deref1, deref2, deref3)\
    ic_program_add(program, ic_node(\
        ic_opCreate(\
            line, opkind, ic_node(op1), ic_node(op2), ic_node(op3), deref1, deref2, deref3, FALSE)));

#ifdef __cplusplus
}
#endif
#endif
