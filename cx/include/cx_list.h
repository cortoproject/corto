/* cx_list.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef cx_list_H
#define cx_list_H

#include "cortex.h"
#include "cx_collection.h"
#include "cx__type.h"

#include "cx__api.h"

#include "cx__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::cortex::lang::list::append() */
cx_any cx_list_append_(cx_any _this);

/* ::cortex::lang::list::append(any element) */
cx_void cx_list_append_any(cx_any _this, cx_any element);

/* ::cortex::lang::list::clear() */
cx_void cx_list_clear(cx_any _this);

/* callback ::cortex::lang::class::construct(object object) -> ::cortex::lang::list::construct(list object) */
cx_int16 cx_list_construct(cx_list object);

/* callback ::cortex::lang::type::init(object object) -> ::cortex::lang::list::init(list object) */
cx_int16 cx_list_init(cx_list object);

/* ::cortex::lang::list::insert() */
cx_any cx_list_insert_(cx_any _this);

/* ::cortex::lang::list::insert(any element) */
cx_void cx_list_insert_any(cx_any _this, cx_any element);

/* ::cortex::lang::list::reverse() */
cx_void cx_list_reverse(cx_any _this);

#ifdef __cplusplus
}
#endif
#endif

