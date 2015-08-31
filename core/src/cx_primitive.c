/* cx_primitive.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "cx.h"

/* $header() */
cx_uint8 cx__primitive_convertId(cx_primitiveKind kind, cx_width width) {
    cx_uint8 id = 0;

    switch(kind) {
    case CX_BINARY:
        id = width;
        break;
    case CX_BOOLEAN:
        id = 5;
        break;
    case CX_CHARACTER:
        id = 6 + width;
        break;
    case CX_INTEGER:
        id = 8 + width;
        break;
    case CX_UINTEGER:
        id = 14 + width;
        break;
    case CX_FLOAT:
        id = 20 + width - 2;
        break;
    case CX_TEXT:
        id = 22;
        break;
    case CX_ENUM:
        id = 23;
        break;
    case CX_BITMASK:
        id = 24;
        break;
    }
    return id;
}
/* $end */

/* ::corto::lang::primitive::castable(type type) */
cx_bool _cx_primitive_castable_v(cx_primitive _this, cx_type type) {
/* $begin(::corto::lang::primitive::castable) */
    cx_bool result;

    result = FALSE;
    
    /* Perform generic type::compatible routine first. */
    if (!cx_primitive_compatible_v(_this, type)) {
        if (cx_type(_this)->reference == type->reference) {
            if (type->kind == CX_PRIMITIVE) {
                cx_primitiveKind kind = cx_primitive(type)->kind;
                if (_this->kind != kind) {
                    switch(_this->kind) {
                    case CX_BOOLEAN:
                    case CX_BINARY:
                        switch(kind) {
                        case CX_BOOLEAN:
                        case CX_BINARY:
                        case CX_INTEGER:
                        case CX_UINTEGER:
                        case CX_FLOAT:
                        case CX_TEXT:
                        case CX_ENUM:
                        case CX_BITMASK:
                            result = TRUE;
                            break;
                        default:
                            break;
                        }
                        break;
                    case CX_CHARACTER:
                        switch(kind) {
                        case CX_BINARY:
                        case CX_INTEGER:
                        case CX_UINTEGER:
                        case CX_TEXT:
                            result = TRUE;
                            break;
                        default:
                            break;
                        }
                        break;
                    case CX_INTEGER:
                        switch(kind) {
                        case CX_ENUM:
                            result = TRUE;
                            break;
                        default:
                            break;
                        }
                    case CX_UINTEGER:
                        switch(kind) {
                        case CX_BINARY:
                        case CX_BOOLEAN:
                        case CX_CHARACTER:
                        case CX_INTEGER:
                        case CX_UINTEGER:
                        case CX_FLOAT:
                        case CX_TEXT:
                        case CX_BITMASK:
                            result = TRUE;
                        default:
                            break;
                        }
                        break;
                    case CX_FLOAT:
                        switch(kind) {
                        case CX_BINARY:
                        case CX_INTEGER:
                        case CX_UINTEGER:
                        case CX_TEXT:
                            result = TRUE;
                        default:
                            break;
                        }
                        break;
                    case CX_BITMASK:
                        switch(kind) {
                            case CX_BOOLEAN:
                                result = TRUE;
                                break;
                            default:
                                break;
                        }
                    case CX_ENUM:
                        switch(kind) {
                        case CX_INTEGER:
                        case CX_UINTEGER:
                        case CX_TEXT:
                            result = TRUE;
                            break;
                        default:
                            break;
                        }
                        break;
                    case CX_TEXT:
                        switch(kind) {
                        case CX_BINARY:
                        case CX_BOOLEAN:
                        case CX_CHARACTER:
                        case CX_INTEGER:
                        case CX_UINTEGER:
                        case CX_FLOAT:
                        case CX_ENUM:
                            result = TRUE;
                        default:
                            break;
                        }
                        break;
                    }
                } else {
                    result = TRUE;
                }
            }
        }
    } else {
        result = TRUE;
    }

    return result;
/* $end */
}

/* ::corto::lang::primitive::compatible(type type) */
cx_bool _cx_primitive_compatible_v(cx_primitive _this, cx_type type) {
/* $begin(::corto::lang::primitive::compatible) */
    cx_bool result;

    result = FALSE;

    if (!cx_type_compatible_v(cx_type(_this), type)) {
        if (type->kind == CX_PRIMITIVE) {
           if (_this->kind == cx_primitive(type)->kind) { /* If kinds are equal, types are compatible */
               result = TRUE;
            } else if (_this->kind == CX_ENUM) {
               if (type == cx_type(cx_constant_o)) {
                   result = TRUE;
               }
            } else if (_this->kind == CX_BITMASK) {
               switch(cx_primitive(type)->kind) {
               case CX_INTEGER:
               case CX_UINTEGER:
                   result = TRUE;
                   break;
               default:
                   break;
               }
            } else { 
                switch(_this->kind) {
                /* Numeric types and booleans are compatible */
                case CX_BINARY:
                    if (cx_primitive(type)->kind == CX_FLOAT) {
                        break;
                    }
                case CX_BOOLEAN:
                case CX_UINTEGER:
                case CX_INTEGER:
                case CX_FLOAT:
                    switch(cx_primitive(type)->kind) {
                    case CX_BINARY:
                        if (_this->kind == CX_FLOAT) {
                            break;
                        }
                    case CX_BOOLEAN:
                    case CX_UINTEGER:
                    case CX_INTEGER:
                    case CX_FLOAT:
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
        } else {
            if (_this->kind == CX_BOOLEAN) {
                if (type->reference) {
                    result = TRUE;
                }
            }
        }
    } else {
        result = TRUE;
    }

    return result;
/* $end */
}

/* ::corto::lang::primitive::construct() */
cx_int16 _cx_primitive_construct(cx_primitive _this) {
/* $begin(::corto::lang::primitive::construct) */

    switch(_this->width) {
    case CX_WIDTH_8:
        cx_type(_this)->size = 1;
        cx_type(_this)->alignment = CX_ALIGNMENT(cx_char);
        break;
    case CX_WIDTH_16:
        cx_type(_this)->size = 2;
        cx_type(_this)->alignment = CX_ALIGNMENT(cx_int16);
        break;
    case CX_WIDTH_32:
        cx_type(_this)->size = 4;
        cx_type(_this)->alignment = CX_ALIGNMENT(cx_int32);
        break;
    case CX_WIDTH_64:
        cx_type(_this)->size = 8;
        cx_type(_this)->alignment = CX_ALIGNMENT(cx_int64);
        break;
    case CX_WIDTH_WORD:
        cx_type(_this)->size = sizeof(void*);
        cx_type(_this)->alignment = CX_ALIGNMENT(cx_word);
        break;
    }

    /* Assign convertId which enables quick lookups of implicit primitive conversions. */
    _this->convertId = cx__primitive_convertId(_this->kind, _this->width);

    return cx_type_construct(cx_type(_this));
/* $end */
}

/* ::corto::lang::primitive::init() */
cx_int16 _cx_primitive_init(cx_primitive _this) {
/* $begin(::corto::lang::primitive::init) */
    cx_type(_this)->kind = CX_PRIMITIVE;
    return cx_type_init((cx_type)_this);
/* $end */
}
