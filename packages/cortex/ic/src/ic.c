/* ic.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "ic.h"

/* $header() */
cx_threadKey IC_PROGRAM_KEY;
/* $end */

/* ::cortex::ic::opKindFromOperator(operatorKind operator) */
ic_opKind _ic_opKindFromOperator(cx_operatorKind operator) {
/* $begin(::cortex::ic::opKindFromOperator) */

    switch(operator) {
    case CX_ASSIGN: return ic_set;
    case CX_ADD: return ic_add;
    case CX_SUB: return ic_sub;
    case CX_MUL: return ic_mul;
    case CX_DIV: return ic_div;
    case CX_MOD: return ic_mod;
    case CX_INC: return ic_inc;
    case CX_DEC: return ic_dec;
    case CX_XOR: return ic_xor;
    case CX_OR: return ic_or;
    case CX_AND: return ic_and;
    case CX_NOT: return ic_not;
    case CX_SHIFT_LEFT: return ic_shift_left;
    case CX_SHIFT_RIGHT: return ic_shift_right;
    case CX_COND_OR: return ic_cond_or;
    case CX_COND_AND: return ic_cond_and;
    case CX_COND_NOT: return ic_cond_not;
    case CX_COND_EQ: return ic_cond_eq;
    case CX_COND_NEQ: return ic_cond_neq;
    case CX_COND_GT: return ic_cond_gt;
    case CX_COND_LT: return ic_cond_lt;
    case CX_COND_GTEQ: return ic_cond_gteq;
    case CX_COND_LTEQ: return ic_cond_lteq;
    default:
        cx_assert(0, "invalid operatorkind (%d)", operator);
        break;
    }

    return ic_set;
/* $end */
}

int icmain(int argc, char* argv[]) {
/* $begin(main) */
    CX_UNUSED(argc);
    CX_UNUSED(argv);
    if (cx_threadTlsKey(&IC_PROGRAM_KEY, NULL)) {
        return -1;
    }
    return 0;
/* $end */
}
