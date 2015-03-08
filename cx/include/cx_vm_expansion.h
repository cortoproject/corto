/* ---- Fallthrough macro's */
#define _OP1_(macro, arg, type, op1modes, op2modes, op3modes)\
    macro(type, arg)

#define _OP2_(macro, arg, type, op1, op3modes)\
    macro(type, arg, op1)

#define _OP3_(macro, arg, type, op1, op2)\
    macro(type, arg, op1, op2)
/* ---- */

/* ---- OP1 expansion macro's */
#define _OP1_R(macro, arg, type, op2modes, op3modes)\
    _OP2_##op2modes(macro, arg, type, R, op3modes)

#define _OP1_PQR(macro, arg, type, op2modes, op3modes)\
    _OP2_##op2modes(macro, arg, type, P, op3modes)\
    _OP2_##op2modes(macro, arg, type, Q, op3modes)\
    _OP2_##op2modes(macro, arg, type, R, op3modes)

#define _OP1_PQRV(macro, arg, type, op2modes, op3modes)\
    _OP1_PQR(macro, arg, type, op2modes, op3modes)\
    _OP2_##op2modes(macro, arg, type, V, op3modes)
/* ---- */

/* ---- OP2 expansion macro's */
#define _OP2_PQR(macro, arg, type, op1, op3modes)\
    _OP3_##op3modes(macro, arg, type, op1, P)\
    _OP3_##op3modes(macro, arg, type, op1, Q)\
    _OP3_##op3modes(macro, arg, type, op1, R)

#define _OP2_PQRV(macro, arg, type, op1, op3modes)\
    _OP2_PQR(macro, arg, type, op1, op3modes)\
    _OP3_##op3modes(macro, arg, type, op1, V)
/* ---- */

/* ---- OP3 expansion macro's */
#define _OP3_PQRV(macro, arg, type, op1, op2)\
    macro(type, arg, op1, op2, P)\
    macro(type, arg, op1, op2, Q)\
    macro(type, arg, op1, op2, R)\
    macro(type, arg, op1, op2, V)
/* ---- */

/* ---- Type expansion macro's */
#define _TYPE_B(macro, arg, op1modes, op2modes, op3modes)\
    _OP1_##op1modes(macro, arg, B, op2modes, op3modes)

#define _TYPE_W(macro, arg, op1modes, op2modes, op3modes)\
    _OP1_##op1modes(macro, arg, W, op2modes, op3modes)

#define _TYPE_L(macro, arg, op1modes, op2modes, op3modes)\
    _OP1_##op1modes(macro, arg, L, op2modes, op3modes)

#define _TYPE_D(macro, arg, op1modes, op2modes, op3modes)\
    _OP1_##op1modes(macro, arg, D, op2modes, op3modes)

#define _TYPE_LD(macro, arg, op1modes, op2modes, op3modes)\
    _OP1_##op1modes(macro, arg, L, op2modes, op3modes)\
    _OP1_##op1modes(macro, arg, D, op2modes, op3modes)

#define _TYPE_BSLD(macro, arg, op1modes, op2modes, op3modes)\
    _OP1_##op1modes(macro, arg, B, op2modes, op3modes)\
    _OP1_##op1modes(macro, arg, S, op2modes, op3modes)\
    _TYPE_LD(macro, arg, op1modes, op2modes, op3modes)

#define _TYPE_BSL(macro, arg, op1modes, op2modes, op3modes)\
    _OP1_##op1modes(macro, arg, B, op2modes, op3modes)\
    _OP1_##op1modes(macro, arg, S, op2modes, op3modes)\
    _OP1_##op1modes(macro, arg, L, op2modes, op3modes)
/* ---- */

/* --- Top level expansion macro's */
#define OP1_EXP(macro, arg, types, op1modes)\
    _TYPE_##types(macro, arg, op1modes, /* op2modes */, /* op3modes */)

#define OP2_EXP(macro, arg, types, op1modes, op2modes)\
    _TYPE_##types(macro, arg, op1modes, op2modes, /* op3modes */)

#define OP3_EXP(macro, arg, types, op1modes, op2modes, op3modes)\
    _TYPE_##types(macro, arg, op1modes, op2modes, op3modes)
/* ---- */

