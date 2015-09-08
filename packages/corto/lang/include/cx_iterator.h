/* cx_iterator.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef corto_lang_iterator_H
#define corto_lang_iterator_H

#include "corto.h"
#include "cx_type.h"
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

/* $header() */
cx_int16 cx_iterator_set(void *_this, void *collection, cx_collection collectionType);
cx_bool cx_iterator_next(void *_this);
/* $end */

/* virtual ::corto::lang::iterator::castable(type type) */
cx_bool cx_iterator_castable(cx_iterator _this, cx_type type);

/* ::corto::lang::iterator::castable(type type) */
cx_bool _cx_iterator_castable_v(cx_iterator _this, cx_type type);
#define cx_iterator_castable_v(_this, type) _cx_iterator_castable_v(cx_iterator(_this), cx_type(type))

/* virtual ::corto::lang::iterator::compatible(type type) */
cx_bool cx_iterator_compatible(cx_iterator _this, cx_type type);

/* ::corto::lang::iterator::compatible(type type) */
cx_bool _cx_iterator_compatible_v(cx_iterator _this, cx_type type);
#define cx_iterator_compatible_v(_this, type) _cx_iterator_compatible_v(cx_iterator(_this), cx_type(type))

/* ::corto::lang::iterator::init() */
cx_int16 _cx_iterator_init(cx_iterator _this);
#define cx_iterator_init(_this) _cx_iterator_init(cx_iterator(_this))

#ifdef __cplusplus
}
#endif
#endif

