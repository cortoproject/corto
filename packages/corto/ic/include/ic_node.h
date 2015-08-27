/* ic_node.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef ic_node_H
#define ic_node_H

#include "corto.h"
#include "ic__type.h"
#include "ic__api.h"
#include "ic__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::corto::ic::node::construct() */
cx_int16 _ic_node_construct(ic_node _this);
#define ic_node_construct(_this) _ic_node_construct(ic_node(_this))

/* virtual ::corto::ic::node::str(string in) */
cx_string ic_node_str(ic_node _this, cx_string in);

/* ::corto::ic::node::str(string in) */
cx_string _ic_node_str_v(ic_node _this, cx_string in);
#define ic_node_str_v(_this, in) _ic_node_str_v(ic_node(_this), in)

#ifdef __cplusplus
}
#endif
#endif

