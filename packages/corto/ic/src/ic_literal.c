/* $CORTO_GENERATED
 *
 * ic_literal.c
 *
 * Only ode written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include "ic.h"

corto_int16 _ic_literal_construct(ic_literal this) {
/* $begin(::corto::ic::literal::construct) */
    ic_node(this)->kind = IC_LITERAL;
    return ic_node_construct(ic_node(this));
/* $end */
}

corto_string _ic_literal_str(ic_literal this, corto_string in) {
/* $begin(::corto::ic::literal::str) */
    corto_string result = NULL;

    if (this->value.value) {
        if (corto_primitive(this->value.type)->kind == CORTO_TEXT) {
            in = strappend(in, "\"");
        }
        corto_convert(corto_primitive(this->value.type), this->value.value, corto_primitive(corto_string_o), &result);
        in = strappend(in, result);
        corto_dealloc(result);
        if (corto_primitive(this->value.type)->kind == CORTO_TEXT) {
            in = strappend(in, "\"");
        }
    } else {
        in = strappend(in, "(null)");
    }

    return in;
/* $end */
}
