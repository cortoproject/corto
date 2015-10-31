/* $CORTO_GENERATED
 *
 * ic_label.c
 *
 * Only ode written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include "ic.h"

corto_int16 _ic_label_construct(ic_label this) {
/* $begin(::corto::ic::label::construct) */
    ic_node(this)->kind = IC_LABEL;
    this->id = ic_program_getLabel(ic_program_get());
    return ic_node_construct(ic_node(this));
/* $end */
}

corto_string _ic_label_str(ic_label this, corto_string in) {
/* $begin(::corto::ic::label::str) */
    in = strappend(in, "%%L%d", this->id);
    return in;
/* $end */
}
