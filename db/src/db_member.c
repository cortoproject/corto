/* db_member.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "db.h"
#include "db__meta.h"

/* $header() */
#include "db__interface.h"
/* $end */

/* callback ::cortex::lang::class::construct(lang::object object) -> ::cortex::lang::member::construct(lang::member object) */
db_int16 db_member_construct(db_member object) {
/* $begin(::cortex::lang::member::construct) */
	if (!object->type) {
	    db_id id;
	    db_error("member '%s' has no type.", db_fullname(object, id));
	    goto error;
	}

	return 0;
error:
    return -1;
/* $end */
}

/* callback ::cortex::lang::type::init(lang::object object) -> ::cortex::lang::member::init(lang::member object) */
db_int16 db_member_init(db_member object) {
/* $begin(::cortex::lang::member::init) */
    db_object parent;
    db_type parentType;

    if (db_checkAttr(object, DB_ATTR_SCOPED)) {
		parent = db_parentof(object);
		parentType = db_typeof(parent)->real;

		if (parentType->kind == DB_COMPOSITE) {
			/* Bind member with composite object */
			if (db__interface_bindMember(parent, object)) {
				goto error;
			}
			/* Set default member-modifiers - not during bootstrap */
			if (db_checkState(db_type_o, DB_DEFINED)) {
				object->modifiers = DB_GLOBAL;
				object->state = DB_DECLARED | DB_DEFINED;
			}
		} else {
			db_id id;
			db_error("invalid declaration of member '%s' in scope '%s', members can only be declared in scopes of composite objects.",
					db_nameof(object), db_fullname(parent, id));
			goto error;
		}
    }
    return 0;
error:
    return -1;
/* $end */
}
