/* $CORTO_GENERATED
 *
 * virtual.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include "corto/lang/lang.h"

corto_int16 _corto_virtual_init(corto_virtual this) {
/* $begin(corto/lang/virtual/init) */
    corto_method(this)->_virtual = TRUE;
    return corto_method_init(corto_method(this));
/* $end */
}
