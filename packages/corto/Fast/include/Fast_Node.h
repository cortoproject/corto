/* Fast_Node.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef Fast_Node_H
#define Fast_Node_H

#include "corto.h"
#include "Fast__type.h"
#include "Fast__api.h"
#include "Fast__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::corto::Fast::Node::init() */
cx_int16 _Fast_Node_init(Fast_Node _this);
#define Fast_Node_init(_this) _Fast_Node_init(Fast_Node(_this))

/* virtual ::corto::Fast::Node::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node Fast_Node_toIc(Fast_Node _this, ic_program program, ic_storage storage, cx_bool stored);

/* ::corto::Fast::Node::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node _Fast_Node_toIc_v(Fast_Node _this, ic_program program, ic_storage storage, cx_bool stored);
#define Fast_Node_toIc_v(_this, program, storage, stored) _Fast_Node_toIc_v(Fast_Node(_this), ic_program(program), ic_storage(storage), stored)

#ifdef __cplusplus
}
#endif
#endif

