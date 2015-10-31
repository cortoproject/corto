/* $CORTO_GENERATED
 *
 * ic.c
 *
 * Only ode written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include "ic.h"

/* $header() */
corto_threadKey IC_PROGRAM_KEY;
/* $end */

ic_opKind _ic_opKindFromOperator(corto_operatorKind _operator) {
/* $begin(::corto::ic::opKindFromOperator) */

    switch(_operator) {
    case CORTO_ASSIGN: return ic_set;
    case CORTO_ADD: return ic_add;
    case CORTO_SUB: return ic_sub;
    case CORTO_MUL: return ic_mul;
    case CORTO_DIV: return ic_div;
    case CORTO_MOD: return ic_mod;
    case CORTO_INC: return ic_inc;
    case CORTO_DEC: return ic_dec;
    case CORTO_XOR: return ic_xor;
    case CORTO_OR: return ic_or;
    case CORTO_AND: return ic_and;
    case CORTO_NOT: return ic_not;
    case CORTO_SHIFT_LEFT: return ic_shift_left;
    case CORTO_SHIFT_RIGHT: return ic_shift_right;
    case CORTO_COND_OR: return ic_cond_or;
    case CORTO_COND_AND: return ic_cond_and;
    case CORTO_COND_NOT: return ic_cond_not;
    case CORTO_COND_EQ: return ic_cond_eq;
    case CORTO_COND_NEQ: return ic_cond_neq;
    case CORTO_COND_GT: return ic_cond_gt;
    case CORTO_COND_LT: return ic_cond_lt;
    case CORTO_COND_GTEQ: return ic_cond_gteq;
    case CORTO_COND_LTEQ: return ic_cond_lteq;
    default:
        corto_assert(0, "invalid operatorkind (%d)", _operator);
        break;
    }

    return ic_set;
/* $end */
}

int icMain(int argc, char* argv[]) {
/* $begin(main) */
    CORTO_UNUSED(argc);
    CORTO_UNUSED(argv);
    if (corto_threadTlsKey(&IC_PROGRAM_KEY, NULL)) {
        return -1;
    }
    return 0;
/* $end */
}
