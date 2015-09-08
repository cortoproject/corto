/* cx_list.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef corto_lang_list_H
#define corto_lang_list_H

#include "corto.h"
#include "cx_collection.h"
#ifdef corto_lang_LIB
#include "cx__type.h"
#include "cx__api.h"
#include "cx__meta.h"
#else
#include "corto/lang/cx__type.h"
#include "corto/lang/cx__api.h"
#include "corto/lang/cx__meta.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* ::corto::lang::list::append() */
cx_any _cx_list_append_(cx_any _this);
#define cx_list_append_(_this) _cx_list_append_(_this)

/* ::corto::lang::list::append(any element) */
cx_void _cx_list_append_any(cx_any _this, cx_any element);
#define cx_list_append_any(_this, element) _cx_list_append_any(_this, element)

/* ::corto::lang::list::clear() */
cx_void _cx_list_clear(cx_any _this);
#define cx_list_clear(_this) _cx_list_clear(_this)

/* ::corto::lang::list::construct() */
cx_int16 _cx_list_construct(cx_list _this);
#define cx_list_construct(_this) _cx_list_construct(cx_list(_this))

/* ::corto::lang::list::init() */
cx_int16 _cx_list_init(cx_list _this);
#define cx_list_init(_this) _cx_list_init(cx_list(_this))

/* ::corto::lang::list::insert() */
cx_any _cx_list_insert_(cx_any _this);
#define cx_list_insert_(_this) _cx_list_insert_(_this)

/* ::corto::lang::list::insert(any element) */
cx_void _cx_list_insert_any(cx_any _this, cx_any element);
#define cx_list_insert_any(_this, element) _cx_list_insert_any(_this, element)

/* ::corto::lang::list::reverse() */
cx_void _cx_list_reverse(cx_any _this);
#define cx_list_reverse(_this) _cx_list_reverse(_this)

#ifdef __cplusplus
}
#endif
#endif

