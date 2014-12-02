/* Fast_Template.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "Fast.h"
#include "Fast__meta.h"

/* callback ::hyve::lang::class::construct(lang::object object) -> ::hyve::Fast::Template::construct(Template object) */
db_int16 Fast_Template_construct(Fast_Template object) {
/* $begin(::hyve::Fast::Template::construct) */

	if (Fast_Local_construct(Fast_Local(object))) {
		goto error;
	} else {
		Fast_Variable(object)->kind = FAST_Template;
	}

    return Fast_Variable_construct(Fast_Variable(object));
error:
	return -1;
/* $end */
}
