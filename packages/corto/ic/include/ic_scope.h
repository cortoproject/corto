/* ic_scope.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef ic_scope_H
#define ic_scope_H

#include "corto.h"
#include "ic_node.h"
#include "ic__type.h"
#include "ic__api.h"
#include "ic__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::corto::ic::scope::add(node n) */
cx_void _ic_scope_add(ic_scope _this, ic_node n);
#define ic_scope_add(_this, n) _ic_scope_add(ic_scope(_this), ic_node(n))

/* ::corto::ic::scope::addStorage(storage s) */
cx_void _ic_scope_addStorage(ic_scope _this, ic_storage s);
#define ic_scope_addStorage(_this, s) _ic_scope_addStorage(ic_scope(_this), ic_storage(s))

/* ::corto::ic::scope::construct() */
cx_int16 _ic_scope_construct(ic_scope _this);
#define ic_scope_construct(_this) _ic_scope_construct(ic_scope(_this))

/* ::corto::ic::scope::lookupStorage(string name,bool recursive) */
ic_storage _ic_scope_lookupStorage(ic_scope _this, cx_string name, cx_bool recursive);
#define ic_scope_lookupStorage(_this, name, recursive) _ic_scope_lookupStorage(ic_scope(_this), name, recursive)

/* ::corto::ic::scope::str(string in) */
cx_string _ic_scope_str(ic_scope _this, cx_string in);
#define ic_scope_str(_this, in) _ic_scope_str(ic_scope(_this), in)

#ifdef __cplusplus
}
#endif
#endif

