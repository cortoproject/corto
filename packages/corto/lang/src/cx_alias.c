/* cx_alias.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "cx.h"

/* ::corto::lang::alias::construct() */
cx_int16 _cx_alias_construct(cx_alias this) {
/* $begin(::corto::lang::alias::construct) */
	cx_modifier m = 0;
	
	/* Find the member we're aliassing and verify access */
    if (!this->member) {
    	cx_id id;
    	cx_seterr("alias '%s' doesn't point to anything", cx_fullname(this, id));
    	goto error;
    } else {
    	if (this->member->modifiers & (CX_PRIVATE|CX_LOCAL|CX_READONLY|CX_CONST)) {
    		cx_id id1, id2;
    		cx_seterr("alias '%s' doesn't have write-access to member '%s'",
    			cx_fullname(this, id1), cx_fullname(this->member, id2));
    		goto error;
    	}

    	cx_interface base = cx_parentof(this);
    	while (base && (base != cx_parentof(this->member))) {
    		m |= cx_struct(base)->baseAccess;
    		base = base->base;
    	}

    	if (!base) {
    		cx_id id;
    		cx_seterr("alias '%s' points to member of another interface",
    			cx_fullname(this, id));
    		goto error;
    	}

    	if (m && m != CX_HIDDEN) {
    		cx_id id1, id2;
    		cx_seterr("alias '%s' doesn't have write-access to member '%s'",
    			cx_fullname(this, id1), cx_fullname(this->member, id2));
    		goto error;
    	}

        cx_claim(this->member->type); /* TODO: memory leak outside of bootstrap */
    	cx_member(this)->type = this->member->type;
    	cx_member(this)->modifiers = this->member->modifiers;
    	cx_member(this)->state = this->member->state;
    	cx_member(this)->weak = this->member->weak;
    }

    return 0;
error:
	return -1;
/* $end */
}

/* ::corto::lang::alias::init() */
cx_int16 _cx_alias_init(cx_alias this) {
/* $begin(::corto::lang::alias::init) */

    return cx_member_init(this);

/* $end */
}
