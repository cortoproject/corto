/* corto_iterator.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef CORTO_LANG_ITERATOR_H
#define CORTO_LANG_ITERATOR_H

#include "corto.h"
#include "corto_type.h"
#include "corto__interface.h"

#ifdef __cplusplus
extern "C" {
#endif

/* $header() */
corto_int16 corto_iterator_set(void *_this, void *collection, corto_collection collectionType);
corto_bool corto_iterator_next(void *_this);
/* $end */

/* virtual /corto/lang/iterator/castable(type type) */
CORTO_LANG_EXPORT corto_bool _corto_iterator_castable(corto_iterator _this, corto_type type);
#define corto_iterator_castable(_this, type) _corto_iterator_castable(corto_iterator(_this), corto_type(type))

CORTO_LANG_EXPORT corto_bool _corto_iterator_castable_v(corto_iterator _this, corto_type type);
#define corto_iterator_castable_v(_this, type) _corto_iterator_castable_v(corto_iterator(_this), corto_type(type))

/* virtual /corto/lang/iterator/compatible(type type) */
CORTO_LANG_EXPORT corto_bool _corto_iterator_compatible(corto_iterator _this, corto_type type);
#define corto_iterator_compatible(_this, type) _corto_iterator_compatible(corto_iterator(_this), corto_type(type))

CORTO_LANG_EXPORT corto_bool _corto_iterator_compatible_v(corto_iterator _this, corto_type type);
#define corto_iterator_compatible_v(_this, type) _corto_iterator_compatible_v(corto_iterator(_this), corto_type(type))

CORTO_LANG_EXPORT corto_int16 _corto_iterator_init(corto_iterator _this);
#define corto_iterator_init(_this) _corto_iterator_init(corto_iterator(_this))

#ifdef __cplusplus
}
#endif
#endif

