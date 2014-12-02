/* Fast_Object.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "Fast.h"
#include "Fast__meta.h"

/* $header() */
#include "Fast__api.h"
#include "Fast.h"
#include "Fast_Parser.h"
Fast_Parser yparser(void);
void Fast_Parser_error(Fast_Parser _this, char* fmt, ...);
/* $end */

/* callback ::hyve::lang::class::construct(lang::object object) -> ::hyve::Fast::Object::construct(Object object) */
db_int16 Fast_Object_construct(Fast_Object object) {
/* $begin(::hyve::Fast::Object::construct) */

    Fast_Expression(object)->type = Fast_Variable(Fast_ObjectBase__create(db_typeof(Fast_ObjectBase(object)->value)->real));
    Fast_Expression(object)->isReference = TRUE;

    return Fast_ObjectBase_construct(Fast_ObjectBase(object));
/* $end */
}

/* ::hyve::Fast::Object::getValue() */
db_word Fast_Object_getValue(Fast_Object _this) {
/* $begin(::hyve::Fast::Object::getValue) */
	db_word result = 0;

	/* Value of objects can only be used at compiletime when object is of
	 * type constant. */
    if (db_instanceof(db_typedef(db_constant_o), Fast_ObjectBase(_this)->value)) {
        result = (db_word)Fast_ObjectBase(_this)->value;
    }

    return result;
/* $end */
}

/* ::hyve::Fast::Object::serialize(lang::type dstType,lang::word dst) */
db_int16 Fast_Object_serialize(Fast_Object _this, db_type dstType, db_word dst) {
/* $begin(::hyve::Fast::Object::serialize) */
	Fast_valueKind kind;

	if (!dstType->reference) {
		if (db_instanceof((db_typedef)dstType, Fast_ObjectBase(_this)->value)) {
			/* If object is not of a reference type and object is of dstType, copy value */
			memcpy((void*)dst, Fast_ObjectBase(_this)->value, db_type_sizeof(dstType));
		} else {
			db_id id, id2;
			Fast_Parser_error(yparser(), "type '%s' of object does not match destinationtype '%s'",
					db_fullname(db_typeof(Fast_ObjectBase(_this)->value), id),
					db_fullname(dstType, id2));
		}
	} else {
	    if (Fast_Expression(_this)->isReference) {
	        kind = FAST_Reference;
	    } else {
	        kind = Fast_valueKindFromType(dstType);
	    }

		switch(kind) {
		case FAST_Boolean:
			*(db_bool*)dst = Fast_ObjectBase(_this)->value ? TRUE : FALSE;
			break;
		case FAST_String: {
			db_id id;
			if (*(db_string*)dst) {
				db_dealloc(*(db_string*)dst);
			}
			*(db_string*)dst = db_strdup(db_fullname(Fast_ObjectBase(_this)->value, id));
			break;
		}
		case FAST_Reference:
			if (*(db_object*)dst) {
				db_free(*(db_object*)dst);
			}
			*(db_object*)dst = Fast_ObjectBase(_this)->value;
			db_keep_ext(NULL, *(db_object*)dst, "Serialize object value");
			break;
		default: {
            db_id id;
            Fast_Parser_error(yparser(), "cannot serialize object value to storage of type '%s'", db_fullname(dstType, id));
            goto error;
			break;
		}
		}
	}

	return 0;
error:
    return -1;
/* $end */
}

/* ::hyve::Fast::Object::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_Object_toIc_v(Fast_Object _this, db_icProgram program, db_icStorage storage, db_bool stored) {
/* $begin(::hyve::Fast::Object::toIc) */
	db_ic result;
	DB_UNUSED(storage);
	DB_UNUSED(stored);

	result = (db_ic)db_icObject__create(program, Fast_Node(_this)->line, _this->_parent.value);

	return result;
/* $end */
}
