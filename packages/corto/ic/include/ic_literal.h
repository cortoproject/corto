/* ic_literal.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef ic_literal_H
#define ic_literal_H

#include "corto.h"
#include "ic_node.h"
#include "ic__type.h"
#include "ic__api.h"
#include "ic__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::corto::ic::literal::construct() */
cx_int16 _ic_literal_construct(ic_literal _this);
#define ic_literal_construct(_this) _ic_literal_construct(ic_literal(_this))

/* ::corto::ic::literal::str(string in) */
cx_string _ic_literal_str(ic_literal _this, cx_string in);
#define ic_literal_str(_this, in) _ic_literal_str(ic_literal(_this), in)

#ifdef __cplusplus
}
#endif
#endif

