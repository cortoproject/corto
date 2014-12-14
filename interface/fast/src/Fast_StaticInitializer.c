/* Fast_StaticInitializer.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "Fast.h"
#include "Fast__meta.h"

/* $header() */
#include "Fast_Expression.h"
#include "Fast_Parser.h"
#include "Fast__api.h"
#include "db_collection.h"

Fast_Parser yparser(void);
void Fast_Parser_error(Fast_Parser _this, char* fmt, ...);
void Fast_Parser_warning(Fast_Parser _this, char* fmt, ...);

db_word Fast_Initializer_offset(Fast_StaticInitializer _this, db_uint32 variable) {
	db_word result, base;
    db_uint16 fp = Fast_Initializer(_this)->fp;
	Fast_InitializerFrame *frame = &Fast_Initializer(_this)->frames[fp?fp-1:0];
	Fast_StaticInitializerFrame *baseFrame = &(_this->frames[fp?fp-1:0]);
    Fast_InitializerFrame *thisFrame = &Fast_Initializer(_this)->frames[fp];
    result = 0;

	base = baseFrame->ptr[variable];
	if (!base) {
		Fast_Parser_error(yparser(), "parser error: base is zero in offset calculation");
		goto error;
	}

	/* Switch on current type */
	switch(frame->type->kind) {
	case DB_PRIMITIVE:
		result = base;
		break;
	case DB_COMPOSITE:
        if (fp) {
            result = base + thisFrame->member->offset;
        } else {
            result = base;
        }
		break;
    case DB_COLLECTION: {
        if (fp) {
            db_uint32 elementSize = db_type_sizeof(db_collection(frame->type)->elementType->real);
            switch(db_collection(frame->type)->kind) {
            case DB_SEQUENCE:
                ((db_objectSeq*)base)->length++;
                ((db_objectSeq*)base)->buffer = db_realloc(((db_objectSeq*)base)->buffer, ((db_objectSeq*)base)->length * elementSize);
                base = (db_word)((db_objectSeq*)base)->buffer;
            case DB_ARRAY:
                result = base + thisFrame->location * db_type_sizeof(db_collection(frame->type)->elementType->real);
                memset((void*)result, 0, elementSize);
                break;
            case DB_LIST: {
                if (db_collection_elementRequiresAlloc(db_collection(frame->type))) {
                    result = (db_word)db_calloc(elementSize);
                }
                if (!*(db_ll*)base) {
                    *(db_ll*)base = db_llNew();
                }
                db_llAppend(*(db_ll*)base, (void*)result);
                if (!result) {
                    result = (db_word)db_llGetPtr(*(db_ll*)base, db_llSize(*(db_ll*)base)-1);
                }
                break;
            }
            case DB_MAP: {
                db_type keyType = db_map(frame->type)->keyType->real;
                if (!thisFrame->isKey) {
                    if (db_collection_elementRequiresAlloc(db_collection(frame->type))) {
                        result = (db_word)db_calloc(elementSize);
                    }
                    if (!*(db_rbtree*)base) {
                        *(db_rbtree*)base = db_rbtreeNew(frame->type);
                    }
                    db_rbtreeSet(*(db_rbtree*)base, (void*)_this->frames[fp].keyPtr[variable], (void*)result);
                    if (!result) {
                        if (_this->frames[fp].keyPtr[variable]) {
                            result = (db_word)db_rbtreeGetPtr(*(db_rbtree*)base, (void*)_this->frames[fp].keyPtr[variable]);
                        } else {
                            Fast_Parser_error(yparser(), "cannot set element without keyvalue");
                            goto error;
                        }
                    }
                } else {
                    result = (db_word)db_calloc(db_type_sizeof(keyType));
                    _this->frames[fp].keyPtr[variable] = result;
                    thisFrame->isKey = FALSE;
                }
                break;
            }
            }
        } else {
            result = base;
        }
        break;
    }
	default: {
		db_id id;
		Fast_Parser_error(yparser(), "invalid initializer type '%s'", db_fullname(frame->type, id));
		break;
	}
	}

	return result;
error:
	return 0;
}
/* $end */

/* callback ::hyve::lang::class::construct(lang::object object) -> ::hyve::Fast::StaticInitializer::construct(StaticInitializer object) */
db_int16 Fast_StaticInitializer_construct(Fast_StaticInitializer object) {
/* $begin(::hyve::Fast::StaticInitializer::construct) */
	db_int8 variable;
    
    /* Copy offsets of variables into frames */
	for(variable=0; variable<Fast_Initializer(object)->variableCount; variable++) {
 		object->frames[0].ptr[variable] =
				(db_word)Fast_ObjectBase(Fast_Initializer(object)->variables[variable].object)->value;
		if (!object->frames[0].ptr[variable]) {
			Fast_Parser_error(yparser(), "non-static variable in static initializer");
			goto error;
		}
	}
    
    return Fast_Initializer_construct(Fast_Initializer(object));
error:
	return -1;
/* $end */
}

/* ::hyve::Fast::StaticInitializer::define() */
db_int16 Fast_StaticInitializer_define(Fast_StaticInitializer _this) {
/* $begin(::hyve::Fast::StaticInitializer::define) */
	db_uint32 variable;
	db_object o;

    /* Types are defined during 1st pass. All other objects are defined when a program starts. Defining types
     * at compile-time is required to do validity checking while parsing. On the other hand, objects cannot be
     * defined at compile-time because class constructors\destructors are not yet defined at that point. This
     * would cause object creation\destruction without calling the appropriate constructors\destructors.
     */
	for(variable=0; variable<Fast_Initializer(_this)->variableCount; variable++) {
		o = (db_object)Fast_ObjectBase(Fast_Initializer(_this)->variables[variable].object)->value;
	    if (db_instanceof(db_typedef(db_typedef_o), o)
	            || (db_checkAttr(o, DB_ATTR_SCOPED) && db_instanceof(db_typedef(db_typedef_o), db_parentof(o)))) {
	        if (db_define(o)) {
	            db_id id1, id2;
	            Fast_Parser_error(yparser(), "define of variable '%s' of type '%s' failed",
	                    db_fullname(o, id1),
	                    db_fullname(db_typeof(o), id2));
	            goto error;
	        }
	    } else {
	        /* Only composite types can have constructors. All other objects are instantaneously
	         * defined. */
	        if (db_typeof(o)->real->kind == DB_COMPOSITE) {
	            Fast_Expression refVar = Fast_Expression(Fast_Object__create(o));
	            refVar->isReference = TRUE; /* Always treat object as reference */
	            Fast_Define defineStmt = Fast_Define__create(refVar);
	            Fast_Parser_addStatement(yparser(), Fast_Node(defineStmt));
	            Fast_Parser_collect(yparser(), defineStmt);
	            Fast_Parser_collect(yparser(), refVar);
	        } else {
	            db_define(o);
	        }
	    }
	}
    
    Fast_Initializer_define_v(Fast_Initializer(_this));

	return 0;
error:
	return -1;
/* $end */
}

/* ::hyve::Fast::StaticInitializer::push() */
db_int16 Fast_StaticInitializer_push(Fast_StaticInitializer _this) {
/* $begin(::hyve::Fast::StaticInitializer::push) */
	db_uint8 variable;
    
    /* Obtain offset for all that variables being initialized */
	for(variable=0; variable<Fast_Initializer(_this)->variableCount; variable++) {
		/* Calculate the offset for the current value */
        _this->frames[Fast_Initializer(_this)->fp].ptr[variable] = Fast_Initializer_offset(_this, variable);
	}

    return Fast_Initializer_push_v(Fast_Initializer(_this));
/* $end */
}

/* ::hyve::Fast::StaticInitializer::value(Expression v) */
db_int16 Fast_StaticInitializer_value(Fast_StaticInitializer _this, Fast_Expression v) {
/* $begin(::hyve::Fast::StaticInitializer::value) */
	db_word offset;
	db_uint32 variable;
    db_uint32 fp = Fast_Initializer(_this)->fp;
    db_type type = Fast_Initializer_currentType(Fast_Initializer(_this));
    if (!type) {
        db_id id;
        Fast_Parser_error(yparser(), "excess elements in initializer of type '%s'", 
            db_fullname(Fast_ObjectBase(Fast_Expression(_this)->type)->value, id));
        goto error;
    }

    /* Validate whether expression type matches current type of initializer */
    if (!db_type_castable(type, Fast_Expression_getType_type(v, type))) {
        db_id id, id2;
        Fast_Parser_error(yparser(), "type '%s' invalid here (expected '%s')", 
            db_fullname(Fast_Expression_getType(v), id), db_fullname(type, id2));
        goto error;
    }

    /* Validate whether value has no side-effects - which are not allowed in a static initializer */
    if (Fast_Expression_hasSideEffects(v)) {
        Fast_Parser_error(yparser(), "expressions with side-effects are not allowed in static initializers.");
        goto error;
    }

	/* Serialize value to all variables being initialized */
	for(variable=0; variable<Fast_Initializer(_this)->variableCount; variable++) {
		/* Calculate the offset for the current value */
        _this->frames[fp].ptr[variable] = Fast_Initializer_offset(_this, variable);
		offset = _this->frames[fp].ptr[variable];

		if (!offset) {
			goto error;
		}
        
        if (Fast_Expression_serialize(v, type, offset)) {
            goto error;
        }
	}

	return Fast_Initializer_next(Fast_Initializer(_this));
error:
	return -1;
/* $end */
}
