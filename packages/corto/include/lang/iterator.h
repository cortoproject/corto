/* iterator.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef CORTO_LANG_ITERATOR_H
#define CORTO_LANG_ITERATOR_H

#include <corto/corto.h>
#include <corto/_project.h>
#include <corto/lang/_type.h>

#ifdef __cplusplus
extern "C" {
#endif

CORTO_EXPORT corto_bool _corto_iterator_castable(
    corto_iterator _this,
    corto_type type);
#define corto_iterator_castable(_this, type) _corto_iterator_castable(corto_iterator(_this), corto_type(type))

CORTO_EXPORT corto_bool _corto_iterator_castable_v(
    corto_iterator _this,
    corto_type type);
#define corto_iterator_castable_v(_this, type) _corto_iterator_castable_v(corto_iterator(_this), corto_type(type))
CORTO_EXPORT corto_bool _corto_iterator_compatible(
    corto_iterator _this,
    corto_type type);
#define corto_iterator_compatible(_this, type) _corto_iterator_compatible(corto_iterator(_this), corto_type(type))

CORTO_EXPORT corto_bool _corto_iterator_compatible_v(
    corto_iterator _this,
    corto_type type);
#define corto_iterator_compatible_v(_this, type) _corto_iterator_compatible_v(corto_iterator(_this), corto_type(type))

CORTO_EXPORT corto_int16 _corto_iterator_init(
    corto_iterator _this);
#define corto_iterator_init(_this) _corto_iterator_init(corto_iterator(_this))

#ifdef __cplusplus
}
#endif
#endif

