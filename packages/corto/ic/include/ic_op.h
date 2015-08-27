/* ic_op.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef ic_op_H
#define ic_op_H

#include "corto.h"
#include "ic_node.h"
#include "ic__type.h"
#include "ic__api.h"
#include "ic__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::corto::ic::op::construct() */
cx_int16 _ic_op_construct(ic_op _this);
#define ic_op_construct(_this) _ic_op_construct(ic_op(_this))

/* ::corto::ic::op::str(string in) */
cx_string _ic_op_str(ic_op _this, cx_string in);
#define ic_op_str(_this, in) _ic_op_str(ic_op(_this), in)

/* ::corto::ic::op::validate() */
cx_bool _ic_op_validate(ic_op _this);
#define ic_op_validate(_this) _ic_op_validate(ic_op(_this))

#ifdef __cplusplus
}
#endif
#endif

