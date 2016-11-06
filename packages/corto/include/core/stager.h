/* stager.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef CORTO_CORE_STAGER_H
#define CORTO_CORE_STAGER_H

#include <corto/corto.h>
#include <corto/_interface.h>
#include <corto/core/_type.h>
#include <corto/core/_api.h>
#include <corto/core/_meta.h>

#ifdef __cplusplus
extern "C" {
#endif


CORTO_EXPORT corto_int16 _corto_stager_add(
    corto_stager _this,
    corto_string id,
    corto_string type,
    corto_string contentType,
    corto_word content,
    corto_uint64 childcount);
#define corto_stager_add(_this, id, type, contentType, content, childcount) _corto_stager_add(corto_stager(_this), id, type, contentType, content, childcount)

CORTO_EXPORT corto_int16 _corto_stager_construct(
    corto_stager _this);
#define corto_stager_construct(_this) _corto_stager_construct(corto_stager(_this))

CORTO_EXPORT corto_void _corto_stager_destruct(
    corto_stager _this);
#define corto_stager_destruct(_this) _corto_stager_destruct(corto_stager(_this))

#ifdef __cplusplus
}
#endif
#endif

