/* $CORTO_GENERATED
 *
 * ic_variable.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include "ic.h"

corto_int16 _ic_variable_construct(ic_variable this) {
/* $begin(::corto::ic::variable::construct) */
    ic_storage(this)->kind = IC_VARIABLE;
    return ic_storage_construct(ic_storage(this));
/* $end */
}
