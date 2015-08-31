#ifndef Fast__Private_H
#define Fast__Private_H

#include "Fast.h"

#ifdef __cplusplus
extern "C" {
#endif

void Fast_Parser_error(Fast_Parser _this, char* fmt, ... );
void Fast_Parser_warning(Fast_Parser _this, char* fmt, ... );
cx_string Fast_Parser_id(cx_object o, cx_id buffer);
Fast_Parser yparser(void);
int fast_yparse(Fast_Parser parser, cx_uint32 line, cx_uint32 column);
Fast_Expression Fast_Expression_narrow(Fast_Expression expr, cx_type target);
cx_type Fast_Expression_narrowType(Fast_Expression expr);
cx_int8 Fast_Expression_getCastScore(cx_primitive t);
cx_int8 Fast_Expression_getTypeScore(cx_primitive t);
Fast_Expression Fast_Node_optimizeCondition(Fast_Expression condition, cx_bool *staticResult, cx_bool *inverse);
Fast_Call Fast_createCall(Fast_Expression instance, cx_string function, cx_uint32 numArgs, ...);
Fast_Call Fast_createCallWithArguments(Fast_Expression instance, cx_string function, Fast_Expression arguments);
Fast_Call Fast_createCallFromExpr(Fast_Expression f, Fast_Expression arguments);

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
