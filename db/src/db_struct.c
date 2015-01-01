/* db_struct.c
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
#include "db__class.h"
/* $end */

/* ::cortex::lang::struct::castable(lang::type type) */
db_bool db_struct_castable_v(db_struct _this, db_type type) {
/* $begin(::cortex::lang::struct::castable) */
    return db_struct_compatible(_this, type);
/* $end */
}

/* ::cortex::lang::struct::compatible(lang::type type) */
db_bool db_struct_compatible_v(db_struct _this, db_type type) {
/* $begin(::cortex::lang::struct::compatible) */
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
/* $end */
}

/* callback ::cortex::lang::class::construct(lang::object object) -> ::cortex::lang::struct::construct(lang::struct object) */
db_int16 db_struct_construct(db_struct object) {
/* $begin(::cortex::lang::struct::construct) */
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
/* $end */
}

/* callback ::cortex::lang::type::init(lang::object object) -> ::cortex::lang::struct::init(lang::struct object) */
db_int16 db_struct_init(db_struct object) {
/* $begin(::cortex::lang::struct::init) */
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
/* $end */
}

/* ::cortex::lang::struct::resolveMember(lang::string name) */
db_member db_struct_resolveMember_v(db_struct _this, db_string name) {
/* $begin(::cortex::lang::struct::resolveMember) */
    db_interface base;
    db_member m;

    m = NULL;
    base = db_interface(_this);
    do {
        m = db_interface_resolveMember_v(db_interface(base), name);
    }while(!m && (base=db_interface(base)->base));

    return m;
/* $end */
}
