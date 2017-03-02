/* unit.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef CORTO_LANG_UNIT_H
#define CORTO_LANG_UNIT_H

#include <corto/corto.h>
#include <corto/_project.h>

#include <corto/lang/_type.h>
#include <corto/lang/_load.h>

#ifdef __cplusplus
extern "C" {
#endif

#define corto_unit_construct(_this) _corto_unit_construct(corto_unit(_this))
CORTO_EXPORT
corto_int16 _corto_unit_construct(
    corto_unit _this);

#define corto_unit_destruct(_this) _corto_unit_destruct(corto_unit(_this))
CORTO_EXPORT
corto_void _corto_unit_destruct(
    corto_unit _this);

#define corto_unit_init(_this) _corto_unit_init(corto_unit(_this))
CORTO_EXPORT
corto_int16 _corto_unit_init(
    corto_unit _this);

#ifdef __cplusplus
}
#endif

#endif

