/* ic.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef ic_H
#define ic_H

#include "corto.h"
#include "ic__type.h"
#include "ic__api.h"
#include "ic__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::corto::ic::opKindFromOperator(operatorKind operator) */
ic_opKind _ic_opKindFromOperator(cx_operatorKind operator);
#define ic_opKindFromOperator(operator) _ic_opKindFromOperator(operator)

#ifdef __cplusplus
}
#endif
#endif

#include "ic_accumulator.h"
#include "ic_address.h"
#include "ic_element.h"
#include "ic_function.h"
#include "ic_label.h"
#include "ic_literal.h"
#include "ic_member.h"
#include "ic_node.h"
#include "ic_object.h"
#include "ic_op.h"
#include "ic_program.h"
#include "ic_scope.h"
#include "ic_storage.h"
#include "ic_variable.h"
