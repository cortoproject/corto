/* list.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef CORTO_LANG_LIST_H
#define CORTO_LANG_LIST_H

#include <corto/corto.h>
#include <corto/_project.h>
#include <corto/lang/_type.h>
#include <corto/lang/_api.h>
#include <corto/lang/_load.h>

#ifdef __cplusplus
extern "C" {
#endif


CORTO_EXPORT corto_any _corto_list_append_(corto_any _this);
#define corto_list_append_(_this) _corto_list_append_(_this)

CORTO_EXPORT corto_void _corto_list_append_any(corto_any _this,
    corto_any element);
#define corto_list_append_any(_this, element) _corto_list_append_any(_this, element)

CORTO_EXPORT corto_void _corto_list_clear(corto_any _this);
#define corto_list_clear(_this) _corto_list_clear(_this)

CORTO_EXPORT corto_int16 _corto_list_construct(
    corto_list _this);
#define corto_list_construct(_this) _corto_list_construct(corto_list(_this))

CORTO_EXPORT corto_int16 _corto_list_init(
    corto_list _this);
#define corto_list_init(_this) _corto_list_init(corto_list(_this))

CORTO_EXPORT corto_any _corto_list_insert_(corto_any _this);
#define corto_list_insert_(_this) _corto_list_insert_(_this)

CORTO_EXPORT corto_void _corto_list_insert_any(corto_any _this,
    corto_any element);
#define corto_list_insert_any(_this, element) _corto_list_insert_any(_this, element)

CORTO_EXPORT corto_void _corto_list_reverse(corto_any _this);
#define corto_list_reverse(_this) _corto_list_reverse(_this)

#ifdef __cplusplus
}
#endif
#endif

