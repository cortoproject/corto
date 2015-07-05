/* Fast_Expression.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "Fast.h"

/* $header() */
#include "Fast__private.h"

/* Rate types based on expressibility */
cx_int8 Fast_Expression_getTypeScore(cx_primitive t) {
    cx_int8 result = 0;
    switch(t->kind) {
    case CX_ENUM:
    case CX_BITMASK:
        result = 1;
        break;
    case CX_BOOLEAN:
    case CX_BINARY:
    case CX_INTEGER:
    case CX_UINTEGER:
    case CX_ALIAS:
        result = 2;
        break;
    case CX_CHARACTER:
        result = 3;
        break;
    case CX_FLOAT:
        result = 4;
        break;
    case CX_TEXT:
        result = 5;
        break;
    }
    return result;
}

/* Categorize types on castability - if equal no cast is required when width is equal */
cx_int8 Fast_Expression_getCastScore(cx_primitive t) {
    cx_int8 result = 0;
    switch(t->kind) {
        case CX_ENUM:
        case CX_BITMASK:
            result = 1;
            break;
        case CX_BOOLEAN:
        case CX_BINARY:
        case CX_INTEGER:
        case CX_UINTEGER:
        case CX_ALIAS:
        case CX_CHARACTER:
            result = 2;
            break;
        case CX_FLOAT:
            result = 3;
            break;
        case CX_TEXT:
            result = 4;
            break;
    }
    return result;
}

/* Obtain inttype from value */
cx_type Fast_Expression_getIntTypeFromValue(cx_int64 v, cx_primitive t) {
    cx_type result = NULL;

    if (v < 0) {
        if(t->kind == CX_UINTEGER) {
            /* Overflow */
            if (((cx_uint64)v) <= 4294967295) {
                result = cx_type(cx_uint32_o);
            } else {
                result = cx_type(cx_uint64_o);
            }
        } else if (v >= -128) {
            result = cx_type(cx_int8_o);
        } else if (v >= -32768) {
            result = cx_type(cx_int16_o);
        } else if (v >= -2147483648) {
            result = cx_type(cx_int32_o);
        } else {
            result = cx_type(cx_int64_o);
        }
    } else {
        if (v <= 255) {
            result = cx_type(cx_uint8_o);
        } else if (v <= 65535) {
            result = cx_type(cx_uint16_o);
        } else {
            result = cx_type(cx_uint32_o);
        }
    }

    return result;
}

cx_type Fast_Expression_narrowType(Fast_Expression expr) {
    cx_int64 v;
    cx_type t = Fast_Expression_getType(expr);
    if (Fast_Node(expr)->kind == Fast_LiteralExpr) {
        if (t && (t->kind == CX_PRIMITIVE)) {
            switch(cx_primitive(t)->kind) {
            case CX_INTEGER:
            case CX_UINTEGER:
                Fast_Expression_serialize(expr, cx_type(cx_int64_o), (cx_word)&v);
                t = Fast_Expression_getIntTypeFromValue(v, cx_primitive(t));
                break;
            default:
                break;
            }
        }
    }

    return t;
}

/* Check if expression is integer literal that is eligible to changing type, if this is the case do the cast */
Fast_Expression Fast_Expression_narrow(Fast_Expression expr, cx_type target) {

    if (Fast_Node(expr)->kind == Fast_LiteralExpr) {
        if (!target) {
            target = Fast_Expression_narrowType(expr);
        }
        cx_type t = Fast_Expression_getType_type(expr, target);
        if (target && (t != target) &&
           (target->kind == CX_PRIMITIVE) &&
           (cx_primitive(target)->kind == cx_primitive(t)->kind)) {
            cx_width width = cx_primitive(target)->width;

            if (t->kind == CX_PRIMITIVE) {
                switch(cx_primitive(t)->kind) {
                case CX_INTEGER: {
                    cx_int64 v = *(cx_int64*)Fast_Expression_getValue(expr);
                    switch(width) {
                    case CX_WIDTH_8:
                        if ((v <= 127) && (v >= -128)) {
                            cx_set(&expr->type, target);
                        }
                        break;
                    case CX_WIDTH_16:
                        if ((v <= 32767) && (v >= -32768)) {
                            cx_set(&expr->type, target);
                        }
                        break;
                    case CX_WIDTH_32:
                        if ((v <= 2147483647) && (v >= -2147483648)) {
                            cx_set(&expr->type, target);
                        }
                        break;
                    default:
                        break;
                    }
                    break;
                }
                case CX_UINTEGER: {
                    cx_uint64 v = *(cx_uint64*)Fast_Expression_getValue(expr);
                    switch(width) {
                    case CX_WIDTH_8:
                        if (v <= 255) {
                            cx_set(&expr->type, target);
                        }
                        break;
                    case CX_WIDTH_16:
                        if (v <= 65535) {
                            cx_set(&expr->type, target);
                        }
                        break;
                    case CX_WIDTH_32:
                        if (v <= 4294967295) {
                            cx_set(&expr->type, target);
                        }
                        break;
                    default:
                        break;
                    }
                    break;
                }
                default:
                    break;
                }
            }
        }
    }

    return expr;
}

/* $end */

/* ::cortex::Fast::Expression::cast(type type,bool isReference) */
Fast_Expression Fast_Expression_cast(Fast_Expression _this, cx_type type, cx_bool isReference) {
/* $begin(::cortex::Fast::Expression::cast) */
    cx_type exprType, refType;
    Fast_Expression result = NULL;
    cx_bool castRequired = TRUE;
    
    cx_assert(type != NULL, "cannot cast to unknown type NULL");

    exprType = Fast_Expression_getType(_this);
    if((_this->deref == Fast_ByReference) && !isReference && !exprType->reference) {
        refType = cx_object_o;
    } else {
        refType = exprType;
    }

    /* If types are different, cast */
    if (refType != type) {
        if (!exprType) {
            /* If expression is an untyped initializer, create an anonymous variable of the destination type 
             * and assign it to the initializer. */
            if(Fast_Node(_this)->kind == Fast_InitializerExpr) {
                Fast_Expression local = Fast_Expression(Fast_Temporary__create(type, FALSE));
                Fast_InitializerExpression_insert(Fast_InitializerExpression(_this), local);
                result = local;
                castRequired = TRUE;
            }else {
                castRequired = FALSE;
            }
        } else if (cx_type_castable(type, refType)) {
            void *value = NULL;

            /* If expression is a literal or constant create new literal of right type */
            value = (void*)Fast_Expression_getValue(_this);
            if (value) {
                if (type->reference && (Fast_Node(_this)->kind == Fast_LiteralExpr)) {
                    /* If destination type is a reference and the literal is a string this results
                     * in a resolve at run-time. */
                    switch(Fast_Literal(_this)->kind) {
                    case Fast_Text:
                        break;
                    case Fast_Nothing:
                        /* No cast required */
                        break;
                    default: {
                        cx_id id1, id2;
                        /* Invalid cast */
                        Fast_Parser_error(yparser(), "cannot cast from '%s' to '%s'", Fast_Parser_id(exprType, id1), Fast_Parser_id(type, id2));
                        break;
                    }
                    }
                }

                /* Create literal expressions based on destination type */
                switch(cx_primitive(type)->kind) {
                case CX_BOOLEAN: {
                    cx_bool dstValue = FALSE;
                    cx_convert(cx_primitive(exprType), value, cx_primitive(cx_bool_o), &dstValue);
                    result = Fast_Expression(Fast_Boolean__create(dstValue));
                    break;
                }
                case CX_CHARACTER: {
                    cx_char dstValue;
                    cx_convert(cx_primitive(exprType), value, cx_primitive(cx_char_o), &dstValue);
                    result = Fast_Expression(Fast_Character__create(dstValue));
                    break;
                }
                case CX_BINARY:
                case CX_UINTEGER: {
                    cx_uint64 dstValue;
                    cx_convert(cx_primitive(exprType), value, cx_primitive(cx_uint64_o), &dstValue);
                    result = Fast_Expression(Fast_Integer__create(dstValue));
                    break;
                }
                case CX_INTEGER: {
                    cx_int64 dstValue;
                    cx_convert(cx_primitive(exprType), value, cx_primitive(cx_int64_o), &dstValue);
                    result = Fast_Expression(Fast_SignedInteger__create(dstValue));
                    break;
                }
                case CX_FLOAT: {
                    cx_float64 dstValue;
                    cx_convert(cx_primitive(exprType), value, cx_primitive(cx_float64_o), &dstValue);
                    result = Fast_Expression(Fast_FloatingPoint__create(dstValue));
                    break;
                }
                case CX_TEXT: {
                    cx_string dstValue;
                    cx_convert(cx_primitive(exprType), value, cx_primitive(cx_string_o), &dstValue);
                    result = Fast_Expression(Fast_String__create(dstValue));
                    break;
                }
                case CX_ENUM:
                case CX_BITMASK: {
                    cx_int32 dstValue;
                    cx_convert(cx_primitive(exprType), value, cx_primitive(cx_int32_o), &dstValue);
                    result = Fast_Expression(Fast_SignedInteger__create(dstValue));
                    break;
                }
                case CX_ALIAS: {
                    cx_int32 dstValue;
                    cx_convert(cx_primitive(exprType), value, cx_primitive(cx_word_o), &dstValue);
                    result = Fast_Expression(Fast_SignedInteger__create(dstValue));
                    break;
                }
                }

                if (result){
                    cx_set_ext(result, &Fast_Expression(result)->type, type, "Set correct type after cast");
                }
            } else {
                /* TODO: This functionality must be pushed down to the assembler. For all this function is concerned a cast
                 should only be required when a type is a) castable and b) not compatible. */

                /* If both types are primitive make sure that no cast is inserted for primitives
                 * of the same kind or 'score' to the same width */
                if ((refType->kind == CX_PRIMITIVE) &&
                   (type->kind == CX_PRIMITIVE) &&
                   (Fast_Expression_getCastScore(cx_primitive(refType)) == 
                    Fast_Expression_getCastScore(cx_primitive(type)))) {
                    if (cx_primitive(exprType)->width != cx_primitive(type)->width) {
                        result = Fast_Expression(Fast_Cast__create(type, _this, isReference));
                    } else {
                        /* Types have the same width, so no cast required */
                        castRequired = FALSE;
                    }

                /* Interface-downcasting doesn't require an explicit cast */
                } else if (!cx_instanceof(cx_type(cx_interface_o), type)) {
                    result = Fast_Expression(Fast_Cast__create(type, _this, isReference));
                } else {
                    castRequired = FALSE;
                }
            }
        /* If object is a reference and targetType is string, insert toString operation */
        } else /*if (_this->isReference || Fast_Expression_getType(_this)->reference)*/ {
            if ((type->kind == CX_PRIMITIVE) && (cx_primitive(type)->kind == CX_TEXT)) {

                /* Create call-expression */
                result = Fast_Expression(Fast_createCallWithArguments(_this, "toString", NULL));
                if (!result) {
                    goto error;
                }
                cx_keep(result);

            /* If type is of a generic reference type, accept any reference without cast */
            } else if (type->kind == CX_VOID && type->reference) {
                castRequired = FALSE;

            /* If assigning to a generic reference, insert cast */
            } else if (exprType->kind == CX_VOID && exprType->reference && isReference) {
                result = Fast_Expression(Fast_Cast__create(type, _this, isReference));    
            }
        }
    } else {
        castRequired = FALSE;
    }

    if (result && castRequired) {
        Fast_Parser_collect(yparser(), result);
    } else {
        if (castRequired) {
            cx_id id1, id2;
                Fast_Parser_error(yparser(), "no conversion from '%s' to '%s'",
                        Fast_Parser_id(exprType, id1),
                        Fast_Parser_id(type, id2));
        }
    }

    return result;
error:
    return NULL;
/* $end */
}

/* ::cortex::Fast::Expression::cleanList(list{Expression} list) */
cx_void Fast_Expression_cleanList(Fast_Expression_list list) {
/* $begin(::cortex::Fast::Expression::cleanList) */
    if (list) {
        cx_iter iter = cx_llIter(list);
        while(cx_iterHasNext(&iter)) {
            cx_free_ext(NULL, cx_iterNext(&iter), "free expression from list");
        }
        cx_llFree(list);
    }
/* $end */
}

/* ::cortex::Fast::Expression::fold() */
Fast_Expression Fast_Expression_fold_v(Fast_Expression _this) {
/* $begin(::cortex::Fast::Expression::fold) */
    CX_UNUSED(_this);
    return _this;
/* $end */
}

/* ::cortex::Fast::Expression::fromList(list{Expression} list) */
Fast_Expression Fast_Expression_fromList(Fast_Expression_list list) {
/* $begin(::cortex::Fast::Expression::fromList) */
    Fast_Expression result = NULL;

    /* Convert list to comma expression */
    if (list) {
        if (cx_llSize(list) == 1) {
            result = cx_llGet(list, 0);
        } else {
            cx_ll toList = cx_llNew(); /* Copy list */
            cx_iter iter;
            Fast_Expression expr;
            
            result = Fast_Expression(Fast_Comma__create());

            iter = cx_llIter(list);
            while(cx_iterHasNext(&iter)) {
                expr = cx_iterNext(&iter);
                cx_llAppend(toList, expr); cx_keep_ext(result, expr, "add expression from list to comma-expression");
            }
            Fast_Comma(result)->expressions = toList;
            Fast_Parser_collect(yparser(), result);
        }
    }
    
    return result;
/* $end */
}

/* ::cortex::Fast::Expression::getType() */
cx_type Fast_Expression_getType(Fast_Expression _this) {
/* $begin(::cortex::Fast::Expression::getType) */
    return _this->type;
/* $end */
}

/* ::cortex::Fast::Expression::getType_expr(Expression target) */
/* $header(::cortex::Fast::Expression::getType_expr) */
cx_type Fast_Expression_getType_intern(Fast_Expression _this, cx_type target, Fast_Expression targetExpr) {
    cx_type result = Fast_Expression_getType(_this);

    if (!result) {
        if ((Fast_Node(_this)->kind == Fast_LiteralExpr) && (Fast_Literal(_this)->kind == Fast_Nothing)) {
            if (target) {
                if (target->reference) {
                    result = target;
                } else if ((target->kind == CX_PRIMITIVE) && (cx_primitive(target)->kind == CX_TEXT)) {
                    result = cx_type(cx_string_o);
                } else {
                    if (targetExpr && targetExpr->isReference) {
                        result = target;
                    } else {
                        goto error;
                    }
                }
            } else {
                goto error;
            }
        } else if (Fast_Node(_this)->kind == Fast_InitializerExpr) {
            result = target;
        } else {
            goto error;
        }
    } else if ((target && (target->kind == CX_VOID) && target->reference)) {
        result = cx_object_o;
    }

    return result;
error: 
    Fast_Parser_error(yparser(), "inconsistent usage of references");
    return NULL;  
}
/* $end */
cx_type Fast_Expression_getType_expr(Fast_Expression _this, Fast_Expression target) {
/* $begin(::cortex::Fast::Expression::getType_expr) */
    cx_type type,result;

    result = Fast_Expression_getType(_this);
    type = Fast_Expression_getType(target);

    if (!result) {
        if (type) {
            result = Fast_Expression_getType_intern(_this, type, target);
        } else {
            result = cx_void_o;
        }
    } else {
        result = Fast_Expression_getType_intern(_this, type, target);
    }

    return result;
/* $end */
}

/* ::cortex::Fast::Expression::getType_type(type target) */
cx_type Fast_Expression_getType_type(Fast_Expression _this, cx_type target) {
/* $begin(::cortex::Fast::Expression::getType_type) */
    return Fast_Expression_getType_intern(_this, target, NULL);
/* $end */
}

/* ::cortex::Fast::Expression::getValue() */
cx_word Fast_Expression_getValue_v(Fast_Expression _this) {
/* $begin(::cortex::Fast::Expression::getValue) */
    CX_UNUSED(_this);
    return 0;
/* $end */
}

/* ::cortex::Fast::Expression::hasSideEffects() */
cx_bool Fast_Expression_hasSideEffects_v(Fast_Expression _this) {
/* $begin(::cortex::Fast::Expression::hasSideEffects) */
    CX_UNUSED(_this);
    return FALSE;
/* $end */
}

/* ::cortex::Fast::Expression::serialize(type dstType,word dst) */
cx_int16 Fast_Expression_serialize_v(Fast_Expression _this, cx_type dstType, cx_word dst) {
/* $begin(::cortex::Fast::Expression::serialize) */
    CX_UNUSED(_this);
    CX_UNUSED(dstType);
    CX_UNUSED(dst);
    cx_assert(0, "call to pure virtual function Fast::Expression::serialize");
    return 0;
/* $end */
}

/* ::cortex::Fast::Expression::toList() */
Fast_Expression_list Fast_Expression_toList_v(Fast_Expression _this) {
/* $begin(::cortex::Fast::Expression::toList) */
    Fast_Node_list result = NULL;
    
    if (_this) {
        result = cx_llNew();
        cx_llInsert(result, _this); cx_keep_ext(NULL, _this, "convert single expression to list");
    }
    
    return result;
/* $end */
}
