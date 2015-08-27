/* ic_storage.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef ic_storage_H
#define ic_storage_H

#include "corto.h"
#include "ic_node.h"
#include "ic__type.h"
#include "ic__api.h"
#include "ic__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::corto::ic::storage::construct() */
cx_int16 _ic_storage_construct(ic_storage _this);
#define ic_storage_construct(_this) _ic_storage_construct(ic_storage(_this))

/* ::corto::ic::storage::free() */
cx_void _ic_storage_free(ic_storage _this);
#define ic_storage_free(_this) _ic_storage_free(ic_storage(_this))

/* ::corto::ic::storage::str(string in) */
cx_string _ic_storage_str(ic_storage _this, cx_string in);
#define ic_storage_str(_this, in) _ic_storage_str(ic_storage(_this), in)

#ifdef __cplusplus
}
#endif
#endif

