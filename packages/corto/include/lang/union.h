/* union.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef CORTO_LANG_UNION_H
#define CORTO_LANG_UNION_H

#include <corto/corto.h>
#include <corto/_interface.h>
#include <corto/lang/_type.h>
#include <corto/lang/_api.h>
#include <corto/lang/_meta.h>

#ifdef __cplusplus
extern "C" {
#endif


CORTO_EXPORT corto_int16 _corto_union_construct(
    corto_union _this);
#define corto_union_construct(_this) _corto_union_construct(corto_union(_this))

CORTO_EXPORT corto_member _corto_union_findCase(
    corto_union _this,
    corto_int32 discriminator);
#define corto_union_findCase(_this, discriminator) _corto_union_findCase(corto_union(_this), discriminator)

CORTO_EXPORT corto_int16 _corto_union_init(
    corto_union _this);
#define corto_union_init(_this) _corto_union_init(corto_union(_this))

#ifdef __cplusplus
}
#endif
#endif

