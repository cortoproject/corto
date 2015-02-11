/* cx_iterator.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef cx_iterator_H
#define cx_iterator_H

#include "cortex.h"
#include "cx_type.h"
#include "cx__type.h"

#include "cx__api.h"

#include "cx__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* $header() */
cx_int16 cx_iterator_set(void *_this, void *collection, cx_collection collectionType);
/* $end */

/* virtual ::cortex::lang::iterator::castable(type type) */
cx_bool cx_iterator_castable(cx_iterator _this, cx_type type);

/* ::cortex::lang::iterator::castable(type type) */
cx_bool cx_iterator_castable_v(cx_iterator _this, cx_type type);

/* virtual ::cortex::lang::iterator::compatible(type type) */
cx_bool cx_iterator_compatible(cx_iterator _this, cx_type type);

/* ::cortex::lang::iterator::compatible(type type) */
cx_bool cx_iterator_compatible_v(cx_iterator _this, cx_type type);

/* ::cortex::lang::iterator::init() */
cx_int16 cx_iterator_init(cx_iterator _this);


#ifdef __cplusplus
}
#endif
#endif

