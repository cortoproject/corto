/* This is a managed file. Do not delete this comment. */

#include <corto/corto.h>


corto_uint8 corto__primitive_convert_id(corto_primitiveKind kind, corto_width width) {
    corto_uint8 id = 0;

    switch(kind) {
    case CORTO_BINARY:
        id = width;
        break;
    case CORTO_BOOLEAN:
        id = 5;
        break;
    case CORTO_CHARACTER:
        id = 6 + width;
        break;
    case CORTO_INTEGER:
        id = 8 + width;
        break;
    case CORTO_UINTEGER:
        id = 14 + width;
        break;
    case CORTO_FLOAT:
        id = 20 + width - 2;
        break;
    case CORTO_TEXT:
        id = 22;
        break;
    case CORTO_ENUM:
        id = 23;
        break;
    case CORTO_BITMASK:
        id = 24;
        break;
    }
    return id;
}

bool corto_primitive_castable_v(
    corto_primitive this,
    corto_type type)
{
    corto_bool result;

    result = FALSE;

    /* Perform generic type::compatible routine first. */
    if (!corto_primitive_compatible_v(this, type)) {
        if (corto_type(this)->reference == type->reference) {
            if (type->kind == CORTO_PRIMITIVE) {
                corto_primitiveKind kind = corto_primitive(type)->kind;
                if (this->kind != kind) {
                    switch(this->kind) {
                    case CORTO_BOOLEAN:
                    case CORTO_BINARY:
                        switch(kind) {
                        case CORTO_BOOLEAN:
                        case CORTO_BINARY:
                        case CORTO_INTEGER:
                        case CORTO_UINTEGER:
                        case CORTO_FLOAT:
                        case CORTO_TEXT:
                        case CORTO_ENUM:
                        case CORTO_BITMASK:
                            result = TRUE;
                            break;
                        default:
                            break;
                        }
                        break;
                    case CORTO_CHARACTER:
                        switch(kind) {
                        case CORTO_BINARY:
                        case CORTO_INTEGER:
                        case CORTO_UINTEGER:
                        case CORTO_TEXT:
                            result = TRUE;
                            break;
                        default:
                            break;
                        }
                        break;
                    case CORTO_INTEGER:
                        switch(kind) {
                        case CORTO_ENUM:
                            result = TRUE;
                            break;
                        default:
                            break;
                        }
                    case CORTO_UINTEGER:
                        switch(kind) {
                        case CORTO_BINARY:
                        case CORTO_BOOLEAN:
                        case CORTO_CHARACTER:
                        case CORTO_INTEGER:
                        case CORTO_UINTEGER:
                        case CORTO_FLOAT:
                        case CORTO_TEXT:
                        case CORTO_BITMASK:
                            result = TRUE;
                        default:
                            break;
                        }
                        break;
                    case CORTO_FLOAT:
                        switch(kind) {
                        case CORTO_BINARY:
                        case CORTO_INTEGER:
                        case CORTO_UINTEGER:
                        case CORTO_TEXT:
                            result = TRUE;
                        default:
                            break;
                        }
                        break;
                    case CORTO_BITMASK:
                        switch(kind) {
                            case CORTO_BOOLEAN:
                                result = TRUE;
                                break;
                            default:
                                break;
                        }
                    case CORTO_ENUM:
                        switch(kind) {
                        case CORTO_INTEGER:
                        case CORTO_UINTEGER:
                        case CORTO_TEXT:
                            result = TRUE;
                            break;
                        default:
                            break;
                        }
                        break;
                    case CORTO_TEXT:
                        switch(kind) {
                        case CORTO_BINARY:
                        case CORTO_BOOLEAN:
                        case CORTO_CHARACTER:
                        case CORTO_INTEGER:
                        case CORTO_UINTEGER:
                        case CORTO_FLOAT:
                        case CORTO_ENUM:
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
}

bool corto_primitive_compatible_v(
    corto_primitive this,
    corto_type type)
{
    corto_bool result;

    result = FALSE;

    if (!corto_type_compatible_v(corto_type(this), type)) {
        if (type->kind == CORTO_PRIMITIVE) {
           if (this->kind == corto_primitive(type)->kind) { /* If kinds are equal, types are compatible */
               result = TRUE;
            } else if ((this->kind == CORTO_ENUM) && (type == corto_type(corto_constant_o))) {
                result = TRUE;
            } else {
                switch(this->kind) {
                case CORTO_BINARY:
                case CORTO_CHARACTER:
                case CORTO_ENUM:
                case CORTO_BITMASK:
                    if (corto_primitive(type)->kind == CORTO_FLOAT) {
                        break;
                    }
                case CORTO_BOOLEAN:
                case CORTO_UINTEGER:
                case CORTO_INTEGER:
                case CORTO_FLOAT:
                    switch(corto_primitive(type)->kind) {
                    case CORTO_BINARY:
                    case CORTO_CHARACTER:
                    case CORTO_ENUM:
                    case CORTO_BITMASK:
                        if (this->kind == CORTO_FLOAT) {
                            break;
                        }
                    case CORTO_BOOLEAN:
                    case CORTO_UINTEGER:
                    case CORTO_INTEGER:
                    case CORTO_FLOAT:
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
            if (this->kind == CORTO_BOOLEAN) {
                if (type->reference) {
                    result = TRUE;
                }
            }
        }
    } else {
        result = TRUE;
    }

    return result;
}

int16_t corto_primitive_construct(
    corto_primitive this)
{
    if (!corto_type(this)->reference) {
        switch(this->width) {
        case CORTO_WIDTH_8:
            corto_type(this)->size = 1;
            corto_type(this)->alignment = CORTO_ALIGNMENT(corto_char);
            break;
        case CORTO_WIDTH_16:
            corto_type(this)->size = 2;
            corto_type(this)->alignment = CORTO_ALIGNMENT(corto_int16);
            break;
        case CORTO_WIDTH_32:
            corto_type(this)->size = 4;
            corto_type(this)->alignment = CORTO_ALIGNMENT(corto_int32);
            break;
        case CORTO_WIDTH_64:
            corto_type(this)->size = 8;
            corto_type(this)->alignment = CORTO_ALIGNMENT(corto_int64);
            break;
        case CORTO_WIDTH_WORD:
            corto_type(this)->size = sizeof(void*);
            corto_type(this)->alignment = CORTO_ALIGNMENT(corto_word);
            break;
        }
    } else {
        corto_type(this)->size = sizeof(corto_object);
        corto_type(this)->alignment = CORTO_ALIGNMENT(corto_object);
    }

    /* Assign convert_id which enables quick lookups of implicit primitive conversions. */
    this->convert_id = corto__primitive_convert_id(this->kind, this->width);

    return corto_type_construct(corto_type(this));
}

int16_t corto_primitive_init(
    corto_primitive this)
{
    corto_type(this)->kind = CORTO_PRIMITIVE;
    return corto_type_init((corto_type)this);
}

bool corto_primitive_isInteger(
    corto_primitive this)
{

    switch(this->kind) {
    case CORTO_BINARY:
    case CORTO_INTEGER:
    case CORTO_UINTEGER:
        return TRUE;
        break;
    default:
        return FALSE;
    }

}

bool corto_primitive_isNumber(
    corto_primitive this)
{

    switch(this->kind) {
    case CORTO_BINARY:
    case CORTO_INTEGER:
    case CORTO_UINTEGER:
    case CORTO_FLOAT:
        return TRUE;
        break;
    default:
        return FALSE;
    }

}
