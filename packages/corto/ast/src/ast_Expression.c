/* ast_Expression.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#define corto_ast_LIB
#include "ast.h"

/* $header() */
#include "ast__private.h"

/* Rate types based on expressibility */
cx_int8 ast_Expression_getTypeScore(cx_primitive t) {
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
cx_int8 ast_Expression_getCastScore(cx_primitive t) {
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
cx_type ast_Expression_getIntTypeFromValue(cx_int64 v, cx_primitive t) {
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

cx_type ast_Expression_narrowType(ast_Expression expr) {
    cx_int64 v;
    cx_type t = ast_Expression_getType(expr);
    if (ast_Node(expr)->kind == Ast_LiteralExpr) {
        if (t && (t->kind == CX_PRIMITIVE)) {
            switch(cx_primitive(t)->kind) {
            case CX_INTEGER:
            case CX_UINTEGER:
                ast_Expression_serialize(expr, cx_type(cx_int64_o), (cx_word)&v);
                t = ast_Expression_getIntTypeFromValue(v, cx_primitive(t));
                break;
            default:
                break;
            }
        }
    }

    return t;
}

/* Check if expression is integer literal that is eligible to changing type, if this is the case do the cast */
ast_Expression ast_Expression_narrow(ast_Expression expr, cx_type target) {

    if (ast_Node(expr)->kind == Ast_LiteralExpr) {
        if (!target) {
            target = ast_Expression_narrowType(expr);
        }
        cx_type t = ast_Expression_getType_type(expr, target);
        if (target && (t != target) &&
           (target->kind == CX_PRIMITIVE) &&
           (cx_primitive(target)->kind == cx_primitive(t)->kind)) {
            cx_width width = cx_primitive(target)->width;

            if (t->kind == CX_PRIMITIVE) {
                switch(cx_primitive(t)->kind) {
                case CX_INTEGER: {
                    cx_int64 v = *(cx_int64*)ast_Expression_getValue(expr);
                    switch(width) {
                    case CX_WIDTH_8:
                        if ((v <= 127) && (v >= -128)) {
                            cx_setref(&expr->type, target);
                        }
                        break;
                    case CX_WIDTH_16:
                        if ((v <= 32767) && (v >= -32768)) {
                            cx_setref(&expr->type, target);
                        }
                        break;
                    case CX_WIDTH_32:
                        if ((v <= 2147483647) && (v >= -2147483648)) {
                            cx_setref(&expr->type, target);
                        }
                        break;
                    default:
                        break;
                    }
                    break;
                }
                case CX_UINTEGER: {
                    cx_uint64 v = *(cx_uint64*)ast_Expression_getValue(expr);
                    switch(width) {
                    case CX_WIDTH_8:
                        if (v <= 255) {
                            cx_setref(&expr->type, target);
                        }
                        break;
                    case CX_WIDTH_16:
                        if (v <= 65535) {
                            cx_setref(&expr->type, target);
                        }
                        break;
                    case CX_WIDTH_32:
                        if (v <= 4294967295) {
                            cx_setref(&expr->type, target);
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

/* ::corto::ast::Expression::cast(type type,bool isReference) */
ast_Expression _ast_Expression_cast(ast_Expression this, cx_type type, cx_bool isReference) {
/* $begin(::corto::ast::Expression::cast) */
    cx_type exprType, refType;
    ast_Expression result = NULL;
    cx_bool castRequired = TRUE;
    
    cx_assert(type != NULL, "cannot cast to unknown type NULL");

    exprType = ast_Expression_getType(this);
    if((this->deref == Ast_ByReference) && !isReference && !exprType->reference) {
        refType = cx_object_o;
    } else {
        refType = exprType;
    }

    /* If types are different, cast */
    if (refType != type) {
        if (!exprType) {
            /* If expression is an untyped initializer, create an anonymous variable of the destination type 
             * and assign it to the initializer. */
            if(ast_Node(this)->kind == Ast_InitializerExpr) {
                ast_Expression local = ast_Expression(ast_TemporaryCreate(type, FALSE));
                Ast_InitializerExpression_insert(Ast_InitializerExpression(this), local);
                result = local;
                castRequired = TRUE;
            }else {
                castRequired = FALSE;
            }
        } else if (cx_type_castable(type, refType)) {
            void *value = NULL;

            /* If expression is a literal or constant create new literal of right type */
            value = (void*)ast_Expression_getValue(this);
            if (value) {
                if (type->reference && (ast_Node(this)->kind == Ast_LiteralExpr)) {
                    /* If destination type is a reference and the literal is a string this results
                     * in a resolve at run-time. */
                    switch(ast_Literal(this)->kind) {
                    case Ast_Text:
                        break;
                    case Ast_Nothing:
                        /* No cast required */
                        break;
                    default: {
                        cx_id id1, id2;
                        /* Invalid cast */
                        ast_Parser_error(yparser(), "cannot cast from '%s' to '%s'", ast_Parser_id(exprType, id1), ast_Parser_id(type, id2));
                        break;
                    }
                    }
                }

                /* Create literal expressions based on destination type */
                switch(cx_primitive(type)->kind) {
                case CX_BOOLEAN: {
                    cx_bool dstValue = FALSE;
                    cx_convert(cx_primitive(exprType), value, cx_primitive(cx_bool_o), &dstValue);
                    result = ast_Expression(Ast_BooleanCreate(dstValue));
                    break;
                }
                case CX_CHARACTER: {
                    cx_char dstValue;
                    cx_convert(cx_primitive(exprType), value, cx_primitive(cx_char_o), &dstValue);
                    result = ast_Expression(Ast_CharacterCreate(dstValue));
                    break;
                }
                case CX_BINARY:
                case CX_UINTEGER: {
                    cx_uint64 dstValue;
                    cx_convert(cx_primitive(exprType), value, cx_primitive(cx_uint64_o), &dstValue);
                    result = ast_Expression(Ast_IntegerCreate(dstValue));
                    break;
                }
                case CX_INTEGER: {
                    cx_int64 dstValue;
                    cx_convert(cx_primitive(exprType), value, cx_primitive(cx_int64_o), &dstValue);
                    result = ast_Expression(Ast_SignedIntegerCreate(dstValue));
                    break;
                }
                case CX_FLOAT: {
                    cx_float64 dstValue;
                    cx_convert(cx_primitive(exprType), value, cx_primitive(cx_float64_o), &dstValue);
                    result = ast_Expression(Ast_FloatingPointCreate(dstValue));
                    break;
                }
                case CX_TEXT: {
                    cx_string dstValue;
                    cx_convert(cx_primitive(exprType), value, cx_primitive(cx_string_o), &dstValue);
                    result = ast_Expression(ast_StringCreate(dstValue));
                    break;
                }
                case CX_ENUM:
                case CX_BITMASK: {
                    cx_int32 dstValue;
                    cx_convert(cx_primitive(exprType), value, cx_primitive(cx_int32_o), &dstValue);
                    result = ast_Expression(Ast_SignedIntegerCreate(dstValue));
                    break;
                }
                }

                if (result){
                    cx_setref(&ast_Expression(result)->type, type);
                }
            } else {
                /* TODO: This functionality must be pushed down to the assembler. For all this function is concerned a cast
                 should only be required when a type is a) castable and b) not compatible. */

                /* If both types are primitive make sure that no cast is inserted for primitives
                 * of the same kind or 'score' to the same width */
                if ((refType->kind == CX_PRIMITIVE) &&
                   (type->kind == CX_PRIMITIVE) &&
                   (ast_Expression_getCastScore(cx_primitive(refType)) == 
                    ast_Expression_getCastScore(cx_primitive(type)))) {
                    if (cx_primitive(exprType)->width != cx_primitive(type)->width) {
                        result = ast_Expression(ast_CastCreate(type, this, isReference));
                    } else {
                        /* Types have the same width, so no cast required */
                        castRequired = FALSE;
                    }

                /* Interface-downcasting doesn't require an explicit cast */
                } else if (cx_instanceof(cx_type(cx_interface_o), type)) {
                    castRequired = FALSE;

                /* If collections are castable, they must be equivalent */
                } else if (type->kind == CX_COLLECTION) {
                    castRequired = FALSE;
                    
                /* For all other cases, insert cast */
                } else {
                    result = ast_Expression(ast_CastCreate(type, this, isReference));
                }
            }
        /* If object is a reference and targetType is string, insert toString operation */
        } else /*if (this->isReference || ast_Expression_getType(this)->reference)*/ {
            if ((type->kind == CX_PRIMITIVE) && (cx_primitive(type)->kind == CX_TEXT)) {

                /* Create call-expression */
                result = ast_Expression(ast_createCallWithArguments(this, "toString", NULL));
                if (!result) {
                    goto error;
                }
                cx_claim(result);

            /* If type is of a generic reference type, accept any reference without cast */
            } else if (type->kind == CX_VOID && type->reference) {
                castRequired = FALSE;

            /* If assigning to a generic reference, insert cast */
            } else if (exprType->kind == CX_VOID && (exprType->reference || isReference)) {
                result = ast_Expression(ast_CastCreate(type, this, isReference));    
            }
        }
    } else {
        castRequired = FALSE;
    }

    if (result && castRequired) {
        ast_Parser_collect(yparser(), result);
    } else {
        if (castRequired) {
            cx_id id1, id2;
                ast_Parser_error(yparser(), "no conversion from '%s' to '%s'",
                        ast_Parser_id(exprType, id1),
                        ast_Parser_id(type, id2));
        }
    }

    return result;
error:
    return NULL;
/* $end */
}

/* ::corto::ast::Expression::cleanList(list{Expression} list) */
cx_void _ast_Expression_cleanList(ast_ExpressionList list) {
/* $begin(::corto::ast::Expression::cleanList) */
    if (list) {
        cx_iter iter = cx_llIter(list);
        while(cx_iterHasNext(&iter)) {
            cx_release(cx_iterNext(&iter));
        }
        cx_llFree(list);
    }
/* $end */
}

/* ::corto::ast::Expression::fold() */
ast_Expression _ast_Expression_fold_v(ast_Expression this) {
/* $begin(::corto::ast::Expression::fold) */
    CX_UNUSED(this);
    return this;
/* $end */
}

/* ::corto::ast::Expression::fromList(list{Expression} list) */
ast_Expression _ast_Expression_fromList(ast_ExpressionList list) {
/* $begin(::corto::ast::Expression::fromList) */
    ast_Expression result = NULL;

    /* Convert list to comma expression */
    if (list) {
        if (cx_llSize(list) == 1) {
            result = cx_llGet(list, 0);
        } else {
            cx_ll toList = cx_llNew(); /* Copy list */
            cx_iter iter;
            ast_Expression expr;
            
            result = ast_Expression(ast_CommaCreate());

            iter = cx_llIter(list);
            while(cx_iterHasNext(&iter)) {
                expr = cx_iterNext(&iter);
                ast_ExpressionListAppend(toList, expr);
            }
            ast_Comma(result)->expressions = toList;
            ast_Parser_collect(yparser(), result);
        }
    }
    
    return result;
/* $end */
}

/* ::corto::ast::Expression::getType() */
cx_type _ast_Expression_getType(ast_Expression this) {
/* $begin(::corto::ast::Expression::getType) */
    return this->type;
/* $end */
}

/* ::corto::ast::Expression::getType_expr(Expression target) */
/* $header(::corto::ast::Expression::getType_expr) */
cx_type ast_Expression_getType_intern(ast_Expression this, cx_type target, ast_Expression targetExpr) {
    cx_type result = ast_Expression_getType(this);

    if (!result) {
        if ((ast_Node(this)->kind == Ast_LiteralExpr) && (ast_Literal(this)->kind == Ast_Nothing)) {
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
        } else if (ast_Node(this)->kind == Ast_InitializerExpr) {
            result = target;
        } else {
            goto error;
        }
    } else if ((target && (target->kind == CX_VOID) && target->reference)) {
        result = cx_object_o;
    }

    return result;
error: 
    ast_Parser_error(yparser(), "inconsistent usage of references");
    return NULL;  
}
/* $end */
cx_type _ast_Expression_getType_expr(ast_Expression this, ast_Expression target) {
/* $begin(::corto::ast::Expression::getType_expr) */
    cx_type type,result;

    result = ast_Expression_getType(this);
    type = ast_Expression_getType(target);

    if (!result) {
        if (type) {
            result = ast_Expression_getType_intern(this, type, target);
        } else {
            result = cx_void_o;
        }
    } else {
        result = ast_Expression_getType_intern(this, type, target);
    }

    return result;
/* $end */
}

/* ::corto::ast::Expression::getType_type(type target) */
cx_type _ast_Expression_getType_type(ast_Expression this, cx_type target) {
/* $begin(::corto::ast::Expression::getType_type) */
    return ast_Expression_getType_intern(this, target, NULL);
/* $end */
}

/* ::corto::ast::Expression::getValue() */
cx_word _ast_Expression_getValue_v(ast_Expression this) {
/* $begin(::corto::ast::Expression::getValue) */
    CX_UNUSED(this);
    return 0;
/* $end */
}

/* ::corto::ast::Expression::hasReturnedResource() */
cx_bool _ast_Expression_hasReturnedResource_v(ast_Expression this) {
/* $begin(::corto::ast::Expression::hasReturnedResource) */
    CX_UNUSED(this);
    return FALSE;
/* $end */
}

/* ::corto::ast::Expression::hasSideEffects() */
cx_bool _ast_Expression_hasSideEffects_v(ast_Expression this) {
/* $begin(::corto::ast::Expression::hasSideEffects) */
    CX_UNUSED(this);
    return FALSE;
/* $end */
}

/* ::corto::ast::Expression::serialize(type dstType,word dst) */
cx_int16 _ast_Expression_serialize_v(ast_Expression this, cx_type dstType, cx_word dst) {
/* $begin(::corto::ast::Expression::serialize) */
    CX_UNUSED(this);
    CX_UNUSED(dstType);
    CX_UNUSED(dst);
    cx_assert(0, "call to pure virtual function ast::Expression::serialize");
    return 0;
/* $end */
}

/* ::corto::ast::Expression::toList() */
ast_ExpressionList _ast_Expression_toList_v(ast_Expression this) {
/* $begin(::corto::ast::Expression::toList) */
    ast_NodeList result = NULL;
    
    if (this) {
        result = cx_llNew();
        ast_ExpressionListInsert(result, this);
    }
    
    return result;
/* $end */
}
