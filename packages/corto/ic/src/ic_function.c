/* $CORTO_GENERATED
 *
 * ic_function.c
 *
 * Only ode written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include "ic.h"

corto_int16 _ic_function_construct(ic_function this) {
/* $begin(::corto::ic::function::construct) */
    ic_node(this)->kind = IC_FUNCTION;
    return ic_node_construct(ic_node(this));
/* $end */
}

corto_string _ic_function_str(ic_function this, corto_string in) {
/* $begin(::corto::ic::function::str) */
    corto_id id;
    in = strappend(in, "\n%%function %s", corto_fullname(this->function, id));
    return in;
/* $end */
}
