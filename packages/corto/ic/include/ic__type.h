/* ic__type.h
 *
 * Type definitions for C-language.
 * This file contains generated code. Do not modify!
 */

#ifndef ic__type_H
#define ic__type_H

#include "corto.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Casting macro's for classes */
#define ic_accumulator(o) ((ic_accumulator)cx_assertType((cx_type)ic_accumulator_o, o))
#define ic_address(o) ((ic_address)cx_assertType((cx_type)ic_address_o, o))
#define ic_element(o) ((ic_element)cx_assertType((cx_type)ic_element_o, o))
#define ic_function(o) ((ic_function)cx_assertType((cx_type)ic_function_o, o))
#define ic_label(o) ((ic_label)cx_assertType((cx_type)ic_label_o, o))
#define ic_literal(o) ((ic_literal)cx_assertType((cx_type)ic_literal_o, o))
#define ic_member(o) ((ic_member)cx_assertType((cx_type)ic_member_o, o))
#define ic_node(o) ((ic_node)cx_assertType((cx_type)ic_node_o, o))
#define ic_object(o) ((ic_object)cx_assertType((cx_type)ic_object_o, o))
#define ic_op(o) ((ic_op)cx_assertType((cx_type)ic_op_o, o))
#define ic_program(o) ((ic_program)cx_assertType((cx_type)ic_program_o, o))
#define ic_scope(o) ((ic_scope)cx_assertType((cx_type)ic_scope_o, o))
#define ic_storage(o) ((ic_storage)cx_assertType((cx_type)ic_storage_o, o))
#define ic_variable(o) ((ic_variable)cx_assertType((cx_type)ic_variable_o, o))

/* Type definitions */
/* ::corto::ic::kind */
typedef enum ic_kind {
    IC_STORAGE = 0,
    IC_LITERAL = 1,
    IC_LABEL = 2,
    IC_ADDRESS = 3,
    IC_FUNCTION = 4,
    IC_OP = 5,
    IC_SCOPE = 6
} ic_kind;

/*  ::corto::ic::node */
CX_CLASS(ic_node);

CX_CLASS_DEF(ic_node) {
    ic_kind kind;
};

/* ::corto::ic::storageKind */
typedef enum ic_storageKind {
    IC_OBJECT = 0,
    IC_VARIABLE = 1,
    IC_ACCUMULATOR = 2,
    IC_MEMBER = 3,
    IC_ELEMENT = 4
} ic_storageKind;

/*  ::corto::ic::storage */
CX_CLASS(ic_storage);

/*  ::corto::ic::scope */
CX_CLASS(ic_scope);

CX_LIST(ic_storage_list);

CX_LIST(ic_node_list);

CX_CLASS_DEF(ic_scope) {
    CX_EXTEND(ic_node);
    ic_scope parent;
    cx_bool isFunction;
    ic_storage_list storages;
    ic_node_list program;
};

CX_CLASS_DEF(ic_storage) {
    CX_EXTEND(ic_node);
    cx_string name;
    cx_type type;
    cx_bool isReference;
    cx_bool holdsReturn;
    ic_storageKind kind;
    ic_storage base;
    cx_uint32 used;
    ic_scope scope;
};

/*  ::corto::ic::accumulator */
CX_CLASS(ic_accumulator);

CX_CLASS_DEF(ic_accumulator) {
    CX_EXTEND(ic_storage);
};

/*  ::corto::ic::address */
CX_CLASS(ic_address);

CX_CLASS_DEF(ic_address) {
    CX_EXTEND(ic_node);
    cx_word value;
};

/* ::corto::ic::derefKind */
typedef enum ic_derefKind {
    IC_DEREF_VALUE = 0,
    IC_DEREF_ADDRESS = 1
} ic_derefKind;

/*  ::corto::ic::element */
CX_CLASS(ic_element);

CX_CLASS_DEF(ic_element) {
    CX_EXTEND(ic_storage);
    ic_storage base;
    ic_node index;
    cx_bool variableIndex;
};

/*  ::corto::ic::function */
CX_CLASS(ic_function);

CX_CLASS_DEF(ic_function) {
    CX_EXTEND(ic_node);
    cx_function function;
};

/*  ::corto::ic::label */
CX_CLASS(ic_label);

CX_CLASS_DEF(ic_label) {
    CX_EXTEND(ic_node);
    cx_uint32 id;
};

/*  ::corto::ic::literal */
CX_CLASS(ic_literal);

CX_CLASS_DEF(ic_literal) {
    CX_EXTEND(ic_node);
    cx_any value;
};

/*  ::corto::ic::member */
CX_CLASS(ic_member);

CX_CLASS_DEF(ic_member) {
    CX_EXTEND(ic_storage);
    ic_storage base;
    cx_member member;
};

/*  ::corto::ic::object */
CX_CLASS(ic_object);

CX_CLASS_DEF(ic_object) {
    CX_EXTEND(ic_storage);
    cx_object ptr;
};

/* ::corto::ic::opKind */
typedef enum ic_opKind {
    ic_set = 0,
    ic_cast = 1,
    ic_strcat = 2,
    ic_strcpy = 3,
    ic_new = 4,
    ic_define = 5,
    ic_free = 6,
    ic_keep = 7,
    ic_init = 8,
    ic_deinit = 9,
    ic_update = 10,
    ic_updatebegin = 11,
    ic_updateend = 12,
    ic_updatecancel = 13,
    ic_waitfor = 14,
    ic_wait = 15,
    ic_add = 16,
    ic_sub = 17,
    ic_mul = 18,
    ic_div = 19,
    ic_mod = 20,
    ic_inc = 21,
    ic_dec = 22,
    ic_xor = 23,
    ic_or = 24,
    ic_and = 25,
    ic_not = 26,
    ic_shift_left = 27,
    ic_shift_right = 28,
    ic_cond_or = 29,
    ic_cond_and = 30,
    ic_cond_not = 31,
    ic_cond_eq = 32,
    ic_cond_neq = 33,
    ic_cond_gt = 34,
    ic_cond_lt = 35,
    ic_cond_gteq = 36,
    ic_cond_lteq = 37,
    ic_jump = 38,
    ic_jeq = 39,
    ic_jneq = 40,
    ic_stop = 41,
    ic_push = 42,
    ic_call = 43,
    ic_ret = 44
} ic_opKind;

/*  ::corto::ic::op */
CX_CLASS(ic_op);

CX_CLASS_DEF(ic_op) {
    CX_EXTEND(ic_node);
    cx_uint32 line;
    ic_opKind kind;
    ic_node s1;
    ic_node s2;
    ic_node s3;
    ic_derefKind s1Deref;
    ic_derefKind s2Deref;
    ic_derefKind s3Deref;
    cx_bool s1Any;
};

CX_LIST(ic_scope_list);

CX_LIST(ic_label_list);

CX_LIST(cx_function_list);

CX_LIST(ic_literal_list);

CX_LIST(ic_op_list);

typedef ic_accumulator ic_accumulator_array256[256];

/*  ::corto::ic::program */
CX_CLASS(ic_program);

CX_CLASS_DEF(ic_program) {
    cx_string filename;
    ic_storage_list storages;
    ic_scope_list scopes;
    ic_label_list labels;
    cx_function_list functions;
    ic_literal_list literals;
    ic_op_list ops;
    cx_uint32 labelCount;
    cx_uint32 accumulatorSp;
    ic_accumulator_array256 accumulatorStack;
    cx_uint32 autoAccId;
    ic_scope scope;
    cx_uint32 errors;
    cx_word vmprogram;
};

/*  ::corto::ic::variable */
CX_CLASS(ic_variable);

CX_CLASS_DEF(ic_variable) {
    CX_EXTEND(ic_storage);
    cx_bool isParameter;
    cx_bool isReturn;
};

#ifdef __cplusplus
}
#endif
#endif

