/*
 * db_struct.c
 *
 *  Created on: Oct 10, 2012
 *      Author: sander
 */

#include "db_type.h"
#include "db__interface.h"
#include "db_err.h"
#include "db_util.h"
#include "db_mem.h"
#include "db_object.h"
#include "db__meta.h"

#include "stdlib.h"

db_bool db_type_compatible_v(db_type _this, db_type type);

db_int16 db_struct_init(db_struct object) {

    /* If not bootstrapping, set baseAccess to GLOBAL | PUBLIC */
    if (db_checkState(db_type_o, DB_DEFINED)) {
        object->baseAccess = DB_GLOBAL;
    }

    if (db_interface_init(db_interface(object))) {
    	goto error;
    }

    db_interface(object)->kind = DB_STRUCT;
    db_type(object)->reference = FALSE;

    return 0;
error:
    return -1;
}

/* class::construct -> struct::construct */
db_int16 db_struct_construct(db_struct object) {
    db_struct base;
    db_uint16 alignment;
    db_uint32 size;

    size = 0;

    /* Insert members */
    if (db__interface_insertMembers(db_interface(object))) {
        goto error;
    }

    /* Calculate alignment of self */
    alignment = db__interface_calculateAlignment(db_interface(object));

    /* Check if struct inherits from another struct */
    base = (db_struct)db_interface(object)->base;

    /* Get maximum alignment from self and base-class and copy template parameters */
    if (base) {
        if (!db_instanceof(db_typedef(db_struct_o), base)) {
        	db_id id, id2;
        	db_error("struct '%s' inherits from non-struct type '%s'", db_fullname(object, id), db_fullname(base, id2));
        	goto error;
        }

        if (db_type(base)->alignment) {
            if (alignment < db_type(base)->alignment) {
                alignment = db_type(base)->alignment;
            }
        }
    }

    /* Set alignment of self */
    db_type(object)->alignment = alignment;

    /* Get size of base-class */
    if (base) {
        size = db_type(base)->size;

        if (db_type(base)->hasResources) {
        	db_type(object)->hasResources = TRUE;
        }
    }

    /* Calculate size of self */
    size = db__interface_calculateSize(db_interface(object), size);

    /* If a class has no members and no base-class, the class will have the size of one word. */
    if (!size) {
        db_assert(db_interface(object)->members.length == 0, "struct can't have members and be of size zero.");
        /*size = sizeof(db_word);*/
    }

    /* Set size of self */
    db_type(object)->size = size;

    return db_interface_construct(db_interface(object));
error:
    return -1;
}

/* virtual struct::compatible */
db_bool db_struct_compatible(db_struct _this, db_type type) {
    db_bool result;

    db_assert(db_class_instanceof(db_struct_o, _this), "struct::compatible called on non-struct object.");
    result = FALSE;

    /* Call overloaded type::compatible function first to check for generic compatibility. */
    if (!db_type_compatible_v(db_type(_this), type)) {
        /* Type must be at least struct for it to be compatible. */
        if (db_class_instanceof(db_struct_o, type)) {
            db_interface e;

            /* Check if '_this' is superclass of 'type' */
            e = db_interface(type);
            do {
                e = db_interface(e)->base;
            }while(e && (e != db_interface(_this)));
            result = (e == (db_interface)_this);
        }
    } else {
        result = TRUE;
    }

    return result;
}

/* virtual struct::castable */
db_bool db_struct_castable(db_struct _this, db_type type) {
    return db_struct_compatible(_this, type);
}

/* virtual struct::resolveMember */
db_member db_struct_resolveMember(db_struct _this, db_string member) {
    db_interface base;
    db_member m;

    m = NULL;
    base = db_interface(_this);
    do {
        m = db_interface_resolveMember_v(db_interface(base), member);
    }while(!m && (base=db_interface(base)->base));

    return m;
}
