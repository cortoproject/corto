/* cx_iterator.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef CORTO_LANG_ITERATOR_H
#define CORTO_LANG_ITERATOR_H

#include "corto.h"
#include "cx_type.h"
#include "cx__interface.h"

#ifdef __cplusplus
extern "C" {
#endif

/* $header() */
cx_int16 cx_iterator_set(void *_this, void *collection, cx_collection collectionType);
cx_bool cx_iterator_next(void *_this);
/* $end */

/* virtual ::corto::lang::iterator::castable(type type) */
CORTO_LANG_EXPORT cx_bool _cx_iterator_castable(cx_iterator _this, cx_type type);
#define cx_iterator_castable(_this, type) _cx_iterator_castable(cx_iterator(_this), cx_type(type))

/* ::corto::lang::iterator::castable(type type) */
CORTO_LANG_EXPORT cx_bool _cx_iterator_castable_v(cx_iterator _this, cx_type type);
#define cx_iterator_castable_v(_this, type) _cx_iterator_castable_v(cx_iterator(_this), cx_type(type))

/* virtual ::corto::lang::iterator::compatible(type type) */
CORTO_LANG_EXPORT cx_bool _cx_iterator_compatible(cx_iterator _this, cx_type type);
#define cx_iterator_compatible(_this, type) _cx_iterator_compatible(cx_iterator(_this), cx_type(type))

/* ::corto::lang::iterator::compatible(type type) */
CORTO_LANG_EXPORT cx_bool _cx_iterator_compatible_v(cx_iterator _this, cx_type type);
#define cx_iterator_compatible_v(_this, type) _cx_iterator_compatible_v(cx_iterator(_this), cx_type(type))

/* ::corto::lang::iterator::init() */
CORTO_LANG_EXPORT cx_int16 _cx_iterator_init(cx_iterator _this);
#define cx_iterator_init(_this) _cx_iterator_init(cx_iterator(_this))

#ifdef __cplusplus
}
#endif
#endif

