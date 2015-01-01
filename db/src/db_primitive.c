/* db_primitive.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "db.h"
#include "db__meta.h"

/* $header() */
db_uint8 db__primitive_convertId(db_primitiveKind kind, db_width width) {
    db_uint8 id = 0;

    switch(kind) {
    case DB_BINARY:
        id = width;
        break;
    case DB_BOOLEAN:
        id = 5;
        break;
    case DB_CHARACTER:
        id = 6 + width;
        break;
    case DB_INTEGER:
        id = 8 + width;
        break;
    case DB_ALIAS:
    case DB_UINTEGER:
        id = 14 + width;
        break;
    case DB_FLOAT:
        id = 20 + width - 2;
        break;
    case DB_TEXT:
        id = 22;
        break;
    case DB_ENUM:
        id = 23;
        break;
    case DB_BITMASK:
        id = 24;
        break;
    }
    return id;
}
/* $end */

/* ::cortex::lang::primitive::castable(lang::type type) */
db_bool db_primitive_castable_v(db_primitive _this, db_type type) {
/* $begin(::cortex::lang::primitive::castable) */
    db_bool result;

    result = FALSE;
    
    /* Perform generic type::compatible routine first. */
    if (!db_type_compatible_v(db_type(_this), type)) {
        if (db_type(_this)->reference == type->reference) {
        	if (type->kind == DB_PRIMITIVE) {
				db_primitiveKind kind = db_primitive(type)->kind;
				if (_this->kind != kind) {
					switch(_this->kind) {
					case DB_ALIAS:
						result = FALSE;
						break;
                    case DB_BOOLEAN:
					case DB_BINARY:
						switch(kind) {
						case DB_BOOLEAN:
						case DB_BINARY:
						case DB_INTEGER:
						case DB_UINTEGER:
                        case DB_FLOAT:
						case DB_TEXT:
						case DB_ENUM:
						case DB_BITMASK:
							result = TRUE;
							break;
						default:
							break;
						}
						break;
					case DB_CHARACTER:
						switch(kind) {
						case DB_BINARY:
						case DB_INTEGER:
						case DB_UINTEGER:
						case DB_TEXT:
							result = TRUE;
							break;
						default:
							break;
						}
						break;
					case DB_INTEGER:
					case DB_UINTEGER:
						switch(kind) {
						case DB_BINARY:
						case DB_BOOLEAN:
						case DB_CHARACTER:
						case DB_INTEGER:
						case DB_UINTEGER:
						case DB_FLOAT:
						case DB_TEXT:
						case DB_ENUM:
						case DB_BITMASK:
							result = TRUE;
						default:
							break;
						}
						break;
					case DB_FLOAT:
						switch(kind) {
                        case DB_BINARY:
						case DB_INTEGER:
						case DB_UINTEGER:
						case DB_TEXT:
							result = TRUE;
						default:
							break;
						}
						break;
                    case DB_BITMASK:
                        switch(kind) {
                            case DB_BOOLEAN:
                                result = TRUE;
                                break;
                            default:
                                break;
                        }
					case DB_ENUM:
						switch(kind) {
						case DB_INTEGER:
						case DB_UINTEGER:
						case DB_TEXT:
							result = TRUE;
							break;
						default:
							break;
						}
						break;
					case DB_TEXT:
						switch(kind) {
						case DB_BINARY:
						case DB_BOOLEAN:
						case DB_CHARACTER:
						case DB_INTEGER:
						case DB_UINTEGER:
						case DB_FLOAT:
						case DB_ENUM:
							result = TRUE;
						default:
							break;
						}
						break;
					}
				} else {
					if (_this->kind == DB_ALIAS) {
						result = !strcmp(db_alias(_this)->typeName, db_alias(type)->typeName);
					} else {
						result = TRUE;
					}
				}
        	}
        }
    } else {
        result = TRUE;
    }

    return result;
/* $end */
}

/* ::cortex::lang::primitive::compatible(lang::type type) */
db_bool db_primitive_compatible_v(db_primitive _this, db_type type) {
/* $begin(::cortex::lang::primitive::compatible) */
    db_bool result;

    result = FALSE;

    if (db_class_instanceof(db_primitive_o, type)) {
       if (_this->kind == db_primitive(type)->kind) { /* If kinds are equal, types are compatible */
           result = TRUE;
        } else if (_this->kind == DB_ENUM) {
    	   if (type == db_type(db_constant_o)) {
    		   result = TRUE;
    	   }
        } else if (_this->kind == DB_BITMASK) {
           switch(db_primitive(type)->kind) {
           case DB_INTEGER:
           case DB_UINTEGER:
               result = TRUE;
               break;
           default:
               break;
           }
        } else { /* Integer types are interchangable */
       		switch(_this->kind) {
   			case DB_BINARY:
   			case DB_UINTEGER:
   			case DB_INTEGER:
   				switch(db_primitive(type)->kind) {
   				case DB_BINARY:
   				case DB_UINTEGER:
   				case DB_INTEGER:
   					result = TRUE;
       				break;
       			default:
	       			break;
   				}
       			break;
   			default:
       			break;
       		}

       }
    }

    return result;
/* $end */
}

/* callback ::cortex::lang::class::construct(lang::object object) -> ::cortex::lang::primitive::construct(lang::primitive object) */
db_int16 db_primitive_construct(db_primitive object) {
/* $begin(::cortex::lang::primitive::construct) */

	switch(object->width) {
	case DB_WIDTH_8:
		db_type(object)->size = 1;
		db_type(object)->alignment = DB_ALIGNMENT(db_char);
		break;
	case DB_WIDTH_16:
		db_type(object)->size = 2;
		db_type(object)->alignment = DB_ALIGNMENT(db_int16);
		break;
	case DB_WIDTH_32:
		db_type(object)->size = 4;
		db_type(object)->alignment = DB_ALIGNMENT(db_int32);
		break;
	case DB_WIDTH_64:
		db_type(object)->size = 8;
		db_type(object)->alignment = DB_ALIGNMENT(db_int64);
		break;
	case DB_WIDTH_WORD:
		db_type(object)->size = sizeof(void*);
		db_type(object)->alignment = DB_ALIGNMENT(db_word);
		break;
	}

	/* Assign convertId which enables quick lookups of implicit primitive conversions. */
	object->convertId = db__primitive_convertId(object->kind, object->width);

	return db_type_construct(db_type(object));
/* $end */
}

/* callback ::cortex::lang::type::init(lang::object object) -> ::cortex::lang::primitive::init(lang::primitive object) */
db_int16 db_primitive_init(db_primitive object) {
/* $begin(::cortex::lang::primitive::init) */
    db_type(object)->kind = DB_PRIMITIVE;
    return db_type__init((db_type)object);
/* $end */
}
