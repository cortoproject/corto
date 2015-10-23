
#ifndef CORTO_VM_EXPANSION_H_
#define CORTO_VM_EXPANSION_H_

#ifdef __cplusplus
extern "C" {
#endif

/* ---- Fallthrough PRE and POST actions */
#define _PRE(macro, arg, type, op1modes, op2modes, op3modes, n)
#define _POST(macro, arg, type, op1modes, op2modes, op3modes, n)

/* ---- Fallthrough macro's */
#define _OP1_(macro, arg, type, op1modes, op2modes, op3modes, opAction)\
    macro(type, arg)

#define _OP2_(macro, arg, type, op1, op3modes, opAction)\
    macro(type, arg, op1)

#define _OP3_(macro, arg, type, op1, op2, opAction)\
    macro(type, arg, op1, op2)
/* ---- */

/* ---- OP1 expansion macro's */
#define _OP1_R(macro, arg, type, op2modes, op3modes, opAction)\
    opAction##_PRE(macro, arg, type, op1modes, op2modes, op3modes, 1)\
    _OP2_##op2modes(macro, arg, type, R, op3modes, opAction)\
    opAction##_POST(macro, arg, type, op1modes, op2modes, op3modes, 1)

#define _OP1_V(macro, arg, type, op2modes, op3modes, opAction)\
    opAction##_PRE(macro, arg, type, op1modes, op2modes, op3modes, 1)\
    _OP2_##op2modes(macro, arg, type, V, op3modes, opAction)\
    opAction##_POST(macro, arg, type, op1modes, op2modes, op3modes, 1)

#define _OP1_A(macro, arg, type, op2modes, op3modes, opAction)\
    opAction##_PRE(macro, arg, type, op1modes, op2modes, op3modes, 1)\
    _OP2_##op2modes(macro, arg, type, A, op3modes, opAction)\
    opAction##_POST(macro, arg, type, op1modes, op2modes, op3modes, 1)

#define _OP1_PQR(macro, arg, type, op2modes, op3modes, opAction)\
    opAction##_PRE(macro, arg, type, op1modes, op2modes, op3modes, 1)\
    _OP2_##op2modes(macro, arg, type, P, op3modes, opAction)\
    _OP2_##op2modes(macro, arg, type, Q, op3modes, opAction)\
    _OP2_##op2modes(macro, arg, type, R, op3modes, opAction)\
    opAction##_POST(macro, arg, type, op1modes, op2modes, op3modes, 1)

#define _OP1_PQRV(macro, arg, type, op2modes, op3modes, opAction)\
    opAction##_PRE(macro, arg, type, op1modes, op2modes, op3modes, 1)\
    _OP1_PQR(macro, arg, type, op2modes, op3modes, opAction)\
    _OP2_##op2modes(macro, arg, type, V, op3modes, opAction)\
    opAction##_POST(macro, arg, type, op1modes, op2modes, op3modes, 1)
/* ---- */

/* ---- OP2 expansion macro's */
#define _OP2_R(macro, arg, type, op1, op3modes, opAction)\
    opAction##_PRE(macro, arg, type, op1modes, op2modes, op3modes, 2)\
    _OP3_##op3modes(macro, arg, type, op1, R, opAction)\
    opAction##_POST(macro, arg, type, op1modes, op2modes, op3modes, 2)

#define _OP2_V(macro, arg, type, op1, op3modes, opAction)\
    opAction##_PRE(macro, arg, type, op1modes, op2modes, op3modes, 2)\
    _OP3_##op3modes(macro, arg, type, op1, V, opAction)\
    opAction##_POST(macro, arg, type, op1modes, op2modes, op3modes, 2)

#define _OP2_A(macro, arg, type, op1, op3modes, opAction)\
    opAction##_PRE(macro, arg, type, op1modes, op2modes, op3modes, 2)\
    _OP3_##op3modes(macro, arg, type, op1, A, opAction)\
    opAction##_POST(macro, arg, type, op1modes, op2modes, op3modes, 2)

#define _OP2_PQR(macro, arg, type, op1, op3modes, opAction)\
    opAction##_PRE(macro, arg, type, op1modes, op2modes, op3modes, 2)\
    _OP3_##op3modes(macro, arg, type, op1, P, opAction)\
    _OP3_##op3modes(macro, arg, type, op1, Q, opAction)\
    _OP3_##op3modes(macro, arg, type, op1, R, opAction)\
    opAction##_POST(macro, arg, type, op1modes, op2modes, op3modes, 2)

#define _OP2_PQRV(macro, arg, type, op1, op3modes, opAction)\
    opAction##_PRE(macro, arg, type, op1modes, op2modes, op3modes, 2)\
    _OP3_##op3modes(macro, arg, type, op1, P, opAction)\
    _OP3_##op3modes(macro, arg, type, op1, Q, opAction)\
    _OP3_##op3modes(macro, arg, type, op1, R, opAction)\
    _OP3_##op3modes(macro, arg, type, op1, V, opAction)\
    opAction##_POST(macro, arg, type, op1modes, op2modes, op3modes, 2)

#define _OP2_PQRVA(macro, arg, type, op1, op3modes, opAction)\
    opAction##_PRE(macro, arg, type, op1modes, op2modes, op3modes, 2)\
    _OP3_##op3modes(macro, arg, type, op1, P, opAction)\
    _OP3_##op3modes(macro, arg, type, op1, Q, opAction)\
    _OP3_##op3modes(macro, arg, type, op1, R, opAction)\
    _OP3_##op3modes(macro, arg, type, op1, V, opAction)\
    _OP3_##op3modes(macro, arg, type, op1, A, opAction)\
    opAction##_POST(macro, arg, type, op1modes, op2modes, op3modes, 2)
/* ---- */

/* ---- OP3 expansion macro's */
#define _OP3_PQRV(macro, arg, type, op1, op2, opAction)\
    opAction##_PRE(macro, arg, type, op1modes, op2modes, op3modes, 3)\
    macro(type, arg, op1, op2, P)\
    macro(type, arg, op1, op2, Q)\
    macro(type, arg, op1, op2, R)\
    macro(type, arg, op1, op2, V)\
    opAction##_POST(macro, arg, type, op1modes, op2modes, op3modes, 3)
/* ---- */

/* ---- Type expansion macro's */
#define _TYPE_B(macro, arg, op1modes, op2modes, op3modes, typeAction, opAction)\
    typeAction##_PRE(macro, arg, type, op1modes, op2modes, op3modes, 0)\
    _OP1_##op1modes(macro, arg, B, op2modes, op3modes, opAction)\
    typeAction##_POST(macro, arg, type, op1modes, op2modes, op3modes, 0)

#define _TYPE_L(macro, arg, op1modes, op2modes, op3modes, typeAction, opAction)\
    typeAction##_PRE(macro, arg, type, op1modes, op2modes, op3modes, 0)\
    _OP1_##op1modes(macro, arg, L, op2modes, op3modes, opAction)\
    typeAction##_POST(macro, arg, type, op1modes, op2modes, op3modes, 0)

#define _TYPE_D(macro, arg, op1modes, op2modes, op3modes, typeAction, opAction)\
    typeAction##_PRE(macro, arg, type, op1modes, op2modes, op3modes, 0)\
    _OP1_##op1modes(macro, arg, D, op2modes, op3modes, opAction)\
    typeAction##_POST(macro, arg, type, op1modes, op2modes, op3modes, 0)

#define _TYPE_W(macro, arg, op1modes, op2modes, op3modes, typeAction, opAction)\
    typeAction##_PRE(macro, arg, type, op1modes, op2modes, op3modes, 0)\
    _OP1_##op1modes(macro, arg, W, op2modes, op3modes, opAction)\
    typeAction##_POST(macro, arg, type, op1modes, op2modes, op3modes, 0)

#define _TYPE_LD(macro, arg, op1modes, op2modes, op3modes, typeAction, opAction)\
    typeAction##_PRE(macro, arg, type, op1modes, op2modes, op3modes, 0)\
    _OP1_##op1modes(macro, arg, L, op2modes, op3modes, opAction)\
    _OP1_##op1modes(macro, arg, D, op2modes, op3modes, opAction)\
    typeAction##_POST(macro, arg, type, op1modes, op2modes, op3modes, 0)

#define _TYPE_BSL(macro, arg, op1modes, op2modes, op3modes, typeAction, opAction)\
    typeAction##_PRE(macro, arg, type, op1modes, op2modes, op3modes, 0)\
    _OP1_##op1modes(macro, arg, B, op2modes, op3modes, opAction)\
    _OP1_##op1modes(macro, arg, S, op2modes, op3modes, opAction)\
    _OP1_##op1modes(macro, arg, L, op2modes, op3modes, opAction)\
    typeAction##_POST(macro, arg, type, op1modes, op2modes, op3modes, 0)

#define _TYPE_BSLD(macro, arg, op1modes, op2modes, op3modes, typeAction, opAction)\
    typeAction##_PRE(macro, arg, type, op1modes, op2modes, op3modes, 0)\
    _OP1_##op1modes(macro, arg, B, op2modes, op3modes, opAction)\
    _OP1_##op1modes(macro, arg, S, op2modes, op3modes, opAction)\
    _OP1_##op1modes(macro, arg, L, op2modes, op3modes, opAction)\
    _OP1_##op1modes(macro, arg, D, op2modes, op3modes, opAction)\
    typeAction##_POST(macro, arg, type, op1modes, op2modes, op3modes, 0)

#define _TYPE_BSLDW(macro, arg, op1modes, op2modes, op3modes, typeAction, opAction)\
    typeAction##_PRE(macro, arg, type, op1modes, op2modes, op3modes, 0)\
    _OP1_##op1modes(macro, arg, B, op2modes, op3modes, opAction)\
    _OP1_##op1modes(macro, arg, S, op2modes, op3modes, opAction)\
    _OP1_##op1modes(macro, arg, L, op2modes, op3modes, opAction)\
    _OP1_##op1modes(macro, arg, D, op2modes, op3modes, opAction)\
    _OP1_##op1modes(macro, arg, W, op2modes, op3modes, opAction)\
    typeAction##_POST(macro, arg, type, op1modes, op2modes, op3modes, 0) 
/* ---- */

/* --- Top level expansion macro's */
#define OP0_EXP(macro, arg)\
    macro(arg)

#define OP1_EXP(macro, arg, types, op1modes, typeAction, opAction)\
    _TYPE_##types(macro, arg, op1modes, /* op2modes */, /* op3modes */, typeAction, opAction)

#define OP2_EXP(macro, arg, types, op1modes, op2modes, typeAction, opAction)\
    _TYPE_##types(macro, arg, op1modes, op2modes, /* op3modes */, typeAction, opAction)

#define OP3_EXP(macro, arg, types, op1modes, op2modes, op3modes, typeAction, opAction)\
    _TYPE_##types(macro, arg, op1modes, op2modes, op3modes, typeAction, opAction)
/* ---- */

#ifdef __cplusplus
}
#endif

#endif
