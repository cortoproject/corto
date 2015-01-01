/* cx_primitive.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "cx.h"
#include "cx__meta.h"

/* $header() */
cx_uint8 cx__primitive_convertId(cx_primitiveKind kind, cx_width width) {
    cx_uint8 id = 0;

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
cx_bool cx_primitive_castable_v(cx_primitive _this, cx_type type) {
/* $begin(::cortex::lang::primitive::castable) */
    cx_bool result;

    result = FALSE;
    
    /* Perform generic type::compatible routine first. */
    if (!cx_type_compatible_v(cx_type(_this), type)) {
        if (cx_type(_this)->reference == type->reference) {
        	if (type->kind == DB_PRIMITIVE) {
				cx_primitiveKind kind = cx_primitive(type)->kind;
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
						result = !strcmp(cx_alias(_this)->typeName, cx_alias(type)->typeName);
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
cx_bool cx_primitive_compatible_v(cx_primitive _this, cx_type type) {
/* $begin(::cortex::lang::primitive::compatible) */
    cx_bool result;

    result = FALSE;

    if (cx_class_instanceof(cx_primitive_o, type)) {
       if (_this->kind == cx_primitive(type)->kind) { /* If kinds are equal, types are compatible */
           result = TRUE;
        } else if (_this->kind == DB_ENUM) {
    	   if (type == cx_type(cx_constant_o)) {
    		   result = TRUE;
    	   }
        } else if (_this->kind == DB_BITMASK) {
           switch(cx_primitive(type)->kind) {
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
   				switch(cx_primitive(type)->kind) {
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
cx_int16 cx_primitive_construct(cx_primitive object) {
/* $begin(::cortex::lang::primitive::construct) */

	switch(object->width) {
	case DB_WIDTH_8:
		cx_type(object)->size = 1;
		cx_type(object)->alignment = DB_ALIGNMENT(cx_char);
		break;
	case DB_WIDTH_16:
		cx_type(object)->size = 2;
		cx_type(object)->alignment = DB_ALIGNMENT(cx_int16);
		break;
	case DB_WIDTH_32:
		cx_type(object)->size = 4;
		cx_type(object)->alignment = DB_ALIGNMENT(cx_int32);
		break;
	case DB_WIDTH_64:
		cx_type(object)->size = 8;
		cx_type(object)->alignment = DB_ALIGNMENT(cx_int64);
		break;
	case DB_WIDTH_WORD:
		cx_type(object)->size = sizeof(void*);
		cx_type(object)->alignment = DB_ALIGNMENT(cx_word);
		break;
	}

	/* Assign convertId which enables quick lookups of implicit primitive conversions. */
	object->convertId = cx__primitive_convertId(object->kind, object->width);

	return cx_type_construct(cx_type(object));
/* $end */
}

/* callback ::cortex::lang::type::init(lang::object object) -> ::cortex::lang::primitive::init(lang::primitive object) */
cx_int16 cx_primitive_init(cx_primitive object) {
/* $begin(::cortex::lang::primitive::init) */
    cx_type(object)->kind = DB_PRIMITIVE;
    return cx_type__init((cx_type)object);
/* $end */
}
