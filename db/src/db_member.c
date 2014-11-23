/*
 * db_member.c
 *
 *  Created on: Aug 9, 2012
 *      Author: sander
 */

#include "db_member.h"
#include "db_object.h"
#include "db__meta.h"
#include "db__interface.h"
#include "db_err.h"
#include "db_util.h"

/* type::init -> member::init */
db_int16 db_member_init(db_member o) {
    db_object parent;
    db_type parentType;

    if (db_checkAttr(o, DB_ATTR_SCOPED)) {
		parent = db_parentof(o);
		parentType = db_typeof(parent)->real;

		if (parentType->kind == DB_COMPOSITE) {
			/* Bind member with composite object */
			if (db__interface_bindMember(parent, o)) {
				goto error;
			}
			/* Set default member-modifiers - not during bootstrap */
			if (db_checkState(db_type_o, DB_DEFINED)) {
				o->modifiers = DB_GLOBAL;
				o->state = DB_DECLARED | DB_DEFINED;
			}
		} else {
			db_id id;
			db_error("invalid declaration of member '%s' in scope '%s', members can only be declared in scopes of composite objects.",
					db_nameof(o), db_fullname(parent, id));
			goto error;
		}
    }
    return 0;
error:
    return -1;
}

/* class::construct -> member::construct */
db_int16 db_member_construct(db_member o) {
	DB_UNUSED(o);

	if (!o->type) {
	    db_id id;
	    db_error("member '%s' has no type.", db_fullname(o, id));
	    goto error;
	}

	return 0;
error:
    return -1;
}
