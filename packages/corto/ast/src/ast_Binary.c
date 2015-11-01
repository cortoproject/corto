/* $CORTO_GENERATED
 *
 * ast_Binary.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include "ast.h"

/* $header() */
#include "ast__private.h"

/* Determine whether the expression is an arithmic operation */
corto_bool ast_Binary_isArithmic(ast_Binary expr) {
    corto_bool result;
    switch(expr->_operator) {
    case CORTO_ADD:
    case CORTO_SUB:
    case CORTO_MUL:
    case CORTO_DIV:
    case CORTO_MOD:
    case CORTO_AND:
    case CORTO_OR:
    case CORTO_XOR:
        result = TRUE;
        break;
    default:
        result = FALSE;
        break;
    }
    return result;
}

/* Determine whether expression is an assignment */
corto_bool ast_Binary_isConditional(ast_Binary expr) {
    corto_bool result;
    switch(expr->_operator) {
    case CORTO_COND_EQ:
    case CORTO_COND_NEQ:
    case CORTO_COND_LT:
    case CORTO_COND_LTEQ:
    case CORTO_COND_GT:
    case CORTO_COND_GTEQ:
    case CORTO_COND_AND:
    case CORTO_COND_OR:
    case CORTO_COND_NOT:
        result = TRUE;
        break;
    default:
        result = FALSE;
        break;
    }
    return result;
}

corto_bool ast_isNull(ast_Expression e) {
    return (ast_Node(e)->kind == Ast_LiteralExpr) && (ast_Literal(e)->kind == Ast_Nothing);
}

/* Get deref mode for expression */
corto_int16 ast_Binary_getDerefKind(ast_Binary this, corto_type lvalueType, corto_type rvalueType) {

    if ((this->lvalue->deref == Ast_ByReference) && ast_isNull(this->rvalue)) {
        this->deref = Ast_ByReference;
    } else if ((this->rvalue->deref == Ast_ByReference) && ast_isNull(this->lvalue)) {
        this->deref = Ast_ByReference;
    } else if (!ast_isOperatorAssignment(this->_operator)) {
        if (this->lvalue->deref != this->rvalue->deref) {
            if (lvalueType->kind == CORTO_VOID) {
                if (this->rvalue->isReference) {
                    this->deref = Ast_ByReference;
                } else {
                    ast_Parser_error(yparser(), "cannot access right operand by reference");
                    goto error;
                }
            } else if (rvalueType->kind == CORTO_VOID) {
                if (this->lvalue->isReference) {
                    this->deref = Ast_ByReference;
                } else {
                    ast_Parser_error(yparser(), "cannot access left operand by reference");
                    goto error;
                }
            } else {
                ast_Parser_error(yparser(), "inconsistent usage of references (left = %s, right = %s)",
                    this->lvalue->deref == Ast_ByReference ? "by address" : "by value",
                    this->rvalue->deref == Ast_ByReference ? "by address" : "by value");
                goto error;
            }
        } else {
            this->deref = this->lvalue->deref;
        }
    } else {
        if (ast_Node(this->rvalue)->kind != Ast_InitializerExpr) {
            if ((this->lvalue->deref == Ast_ByReference) && (!this->rvalue->isReference)) {
                corto_id id;
                ast_Parser_error(yparser(), "cannot access right operand by reference (type = '%s', kind = '%s')",
                    ast_Parser_id(rvalueType, id),
                        corto_nameof(corto_enum_constant(ast_nodeKind_o, ast_Node(this->rvalue)->kind)));
                goto error;
            }

            this->deref = this->lvalue->deref;
        } else {
            /* Initializer expressions are always by value */
            this->deref = Ast_ByValue;
        }
    }

    return 0;
error:
    return -1;
}

/* If types of a binary expression don't match, figure out which casts are required */
corto_int16 ast_Binary_cast(ast_Binary this, corto_type *returnType) {
    corto_type lvalueType, rvalueType, castType = NULL;
    ast_Expression lvalue, rvalue;
    corto_bool referenceMismatch = FALSE;
    corto_bool equal = FALSE;
    corto_bool isNull;

    /* Get lvalueType and rvalueType */
    lvalue = this->lvalue;
    rvalue = this->rvalue;
    if (!(lvalueType = ast_Expression_getType(lvalue))) {
        goto error;
    }

    if (!(rvalueType = ast_Expression_getType_expr(rvalue, lvalue))) {
        goto error;
    }

    isNull = corto_instanceof(corto_type(ast_Null_o), lvalue) ||
        corto_instanceof(corto_type(ast_Null_o), rvalue);

    /* Narrow expressions where possible */
    if (!isNull) {
        lvalue = ast_Expression_narrow(lvalue, rvalueType);
        if (lvalue) {
            corto_setref(&this->lvalue, lvalue);
            lvalueType = ast_Expression_getType(this->lvalue);
        }

        rvalue = ast_Expression_narrow(rvalue, lvalueType);
        if (rvalue) {
            corto_setref(&this->rvalue, rvalue);
            rvalueType = ast_Expression_getType_expr(this->rvalue, this->lvalue);
        }
    }

    if (!lvalueType) {
        lvalueType = rvalueType;
    }

    /* If objects are not scoped, verify whether they're equal */
    if (!corto_checkAttr(lvalueType, CORTO_ATTR_SCOPED) && !corto_checkAttr(rvalueType, CORTO_ATTR_SCOPED)) {
        if (corto_compare(lvalueType, rvalueType) == CORTO_EQ) {
            equal = TRUE;
        }
    } else {
        equal = lvalueType == rvalueType;
    }

    if (this->_operator == CORTO_DIV) {
        castType = corto_type(corto_float64_o);
    } else if (!equal) {
        ast_nodeKind lKind = ast_Node(this->lvalue)->kind;
        ast_nodeKind rKind = ast_Node(this->rvalue)->kind;

        /* If one of the operands is a literal, always cast to the type of the non-literal */
        if ((lKind == Ast_LiteralExpr) ^ (rKind == Ast_LiteralExpr)) {
            if (lKind == Ast_LiteralExpr) {
                castType = rvalueType;
            } else {
                castType = lvalueType;
            }
        } else

        /* Can only cast between primitive types */
        if ((lvalueType->kind == CORTO_PRIMITIVE ) && (rvalueType->kind == CORTO_PRIMITIVE)) {
            corto_primitive ltype = corto_primitive(lvalueType), rtype = corto_primitive(rvalueType);
            corto_int8 lscore, rscore;
            corto_int8 lCastScore, rCastScore;

            lscore = ast_Expression_getTypeScore(ltype);
            rscore = ast_Expression_getTypeScore(rtype);
            lCastScore = ast_Expression_getCastScore(ltype);
            rCastScore = ast_Expression_getCastScore(rtype);

            /* If expression is an assignment, always take type of lvalue. Otherwise determine based on
             * expressibility score which type to cast to.
             */
            if (ast_isOperatorAssignment(this->_operator)) {
                if (lCastScore == rCastScore) {
                    if (ltype->width != rtype->width) {
                        castType = lvalueType;
                    }
                } else {
                    castType = lvalueType;
                }
            } else {
                if (lCastScore == rCastScore) {
                    if (ltype->width == rtype->width) {
                        /* If width and kind are equal, no conversion is required. */
                        if (lscore > rscore) {
                            *returnType = lvalueType;
                        } else if (lscore < rscore) {
                            *returnType = rvalueType;
                        }
                    } else {
                        /* If lvalue has a larger width than rvalue, cast rvalue to lvalueType (and vice versa) */
                        if (ltype->width > rtype->width) {
                            castType = lvalueType;
                        } else {
                            castType = rvalueType;
                        }
                    }

                /* If kinds do not match figure a cast is potentially needed. Figure out which type to cast to */
                } else {
                    if (lscore > rscore) {
                        castType = lvalueType;
                    } else {
                        castType = rvalueType;
                    }
                }
            }
        } else if (lvalueType->reference && rvalueType->reference) {
            castType = NULL;
        /* Check if types are compatible */


        } else if ((rvalueType->reference || (this->rvalue->deref == Ast_ByReference)) && !lvalueType->reference) {
            /* Enable casting references to boolean values */
            if (corto_type_castable(lvalueType, corto_object_o)) {
                castType = lvalueType;
            }
        } else {
            corto_id id1, id2;
            ast_Parser_error(yparser(), "cannot cast from '%s' to '%s'",
                    ast_Parser_id(lvalueType, id1), ast_Parser_id(rvalueType, id2));
            goto error;
        }
    } else if ((rvalueType->reference || (this->rvalue->deref == Ast_ByReference)) && !lvalueType->reference) {
        if (corto_type_castable(lvalueType, corto_object_o)) {
            castType = lvalueType;
            referenceMismatch = TRUE;
        }
    }

    /* Cast-score indicates whether a cast is required */
    if (rvalueType && castType && ((rvalueType != castType) || referenceMismatch)) {
        ast_Expression oldRvalue = this->rvalue;
        this->rvalue = ast_Expression_cast(this->rvalue, castType, this->lvalue->deref == Ast_ByReference);
        if (this->rvalue) {
            corto_claim(this->rvalue);
            corto_release(oldRvalue);
        } else {
            corto_id id, id2;
            ast_Parser_error(yparser(), "cannot cast from '%s' to '%s'",
                    ast_Parser_id(rvalueType, id), ast_Parser_id(castType, id2));
            goto error;
        }
    }
    if (lvalueType && castType && (lvalueType != castType)) {
        ast_Expression oldLvalue = this->lvalue;
        this->lvalue = ast_Expression_cast(this->lvalue, castType, this->rvalue->deref == Ast_ByReference);
        if (this->lvalue) {
            corto_claim(this->lvalue);
            corto_release(oldLvalue);
        } else {
            corto_id id, id2;
            ast_Parser_error(yparser(), "cannot cast from '%s' to '%s'",
                    ast_Parser_id(lvalueType, id), ast_Parser_id(castType, id2));
            goto error;
        }
    }

    if (castType) {
        *returnType = castType;
    }

    return 0;
error:
    return -1;
}

corto_int16 ast_Binary_complexExprCompare(ast_Binary this) {
    ast_Expression compareResult = NULL;
    ast_Expression c1 = NULL, c2 = NULL;
    compareResult = ast_Expression(ast_createCall(this->lvalue, "compare", 1, this->rvalue));
    if (!compareResult) {
        goto error;
    }
    switch (this->_operator) {
        case CORTO_COND_EQ:
            c1 = ast_Expression(ast_IntegerCreate(CORTO_EQ));
            break;
        case CORTO_COND_LT:
            c1 = ast_Expression(ast_IntegerCreate(CORTO_LT));
            break;
        case CORTO_COND_GT:
            c1 = ast_Expression(ast_IntegerCreate(CORTO_GT));
            break;
        case CORTO_COND_LTEQ:
            c1 = ast_Expression(ast_IntegerCreate(CORTO_LT));
            c2 = ast_Expression(ast_IntegerCreate(CORTO_EQ));
            break;
        case CORTO_COND_GTEQ:
            c1 = ast_Expression(ast_IntegerCreate(CORTO_GT));
            c2 = ast_Expression(ast_IntegerCreate(CORTO_EQ));
            break;
        case CORTO_COND_NEQ:
            c1 = ast_Expression(ast_IntegerCreate(CORTO_LT));
            c2 = ast_Expression(ast_IntegerCreate(CORTO_GT));
            break;
        default:
            break;
    }

    ast_Expression c1Result = NULL, c2Result = NULL, orResult, result;
    c1Result = ast_Expression(ast_BinaryCreate(compareResult, c1, CORTO_COND_EQ));
    if (!c1Result) {
        goto error;
    }
    result = c1Result;
    if (c2) {
        c2Result = ast_Expression(ast_BinaryCreate(compareResult, c2, CORTO_COND_EQ));
        if (!c2Result) {
            goto error;
        }
        orResult = ast_Expression(ast_BinaryCreate(c1Result, c2Result, CORTO_OR));
        if (!orResult) {
            goto error;
        }
        result = orResult;
    }
    ast_Parser_addStatement(yparser(), result);
    return 0;
error:
    return -1;
}

corto_int16 ast_Binary_complexExpr(ast_Binary this) {
    if (this->_operator == CORTO_ASSIGN) {
        ast_Expression result = NULL;
        if(ast_Node(this->rvalue)->kind == Ast_InitializerExpr) {
            if (ast_InitializerExpression_insert(ast_InitializerExpression(this->rvalue), this->lvalue)) {
                goto error;
            }
        } else {
            if (!(result = ast_Expression(ast_createCall(this->lvalue, "copy", 1, this->rvalue)))) {
                goto error;
            }
            ast_Parser_addStatement(yparser(), result);
        }
    } else if (this->_operator == CORTO_COND_EQ || this->_operator == CORTO_COND_EQ ||
            this->_operator == CORTO_COND_NEQ || this->_operator == CORTO_COND_GT ||
            this->_operator == CORTO_COND_LT || this->_operator == CORTO_COND_GTEQ ||
            this->_operator == CORTO_COND_LTEQ) {
        if (ast_Binary_complexExprCompare(this)) {
            goto error;
        }
    } else {
        ast_Parser_error(yparser(), "operator invalid for complex value");
        goto error;
    }

    return 0;
error:
    return -1;
}

corto_int16 ast_Binary_toIc_strOp(
        ast_Binary this,
        ic_program program,
        ic_storage storage,
        ic_node lvalue,
        ic_node rvalue) {

    switch(this->_operator) {
    /* Append strings */
    case CORTO_ADD: {
        corto_any l = {corto_type(corto_string_o), NULL, TRUE};
        ic_literal dummy = ic_literalCreate(l);
        IC_2(program, ast_Node(this)->line, ic_strcat, lvalue, rvalue, IC_DEREF_VALUE, IC_DEREF_VALUE);
        IC_2(program, ast_Node(this)->line, ic_strcpy, storage, dummy, IC_DEREF_VALUE, IC_DEREF_VALUE);
        break;
    }
    case CORTO_ASSIGN:
        IC_3(program, ast_Node(this)->line, ic_opKindFromOperator(this->_operator),
            storage, lvalue, rvalue, IC_DEREF_VALUE, IC_DEREF_VALUE, IC_DEREF_VALUE);
        break;
    default:
        ast_Parser_error(yparser(), "operator '%s' invalid for strings",
            corto_nameof(corto_enum_constant(corto_operatorKind_o, this->_operator)));
        goto error;
    }

    return 0;
error:
    return -1;
}

/* $end */

corto_int16 _ast_Binary_construct(ast_Binary this) {
/* $begin(::corto::ast::Binary::construct) */
    corto_type lvalueType, rvalueType;

    ast_Node(this)->kind = Ast_BinaryExpr;
    if (!(lvalueType = ast_Expression_getType_expr(this->lvalue, this->rvalue))) {
        goto error;
    }
    if (!(rvalueType = ast_Expression_getType_expr(this->rvalue, this->lvalue))) {
        goto error;
    }

    /* Check if operands are valid in case of arithmic operation */
    if (ast_Binary_isArithmic(this)) {
        if ((lvalueType->kind != CORTO_PRIMITIVE) || (rvalueType->kind != CORTO_PRIMITIVE) ||
            ((this->lvalue->deref == Ast_ByReference) || (this->rvalue->deref == Ast_ByReference))) {
            ast_Parser_error(yparser(), "invalid operands for arithmic operation");
            goto error;
        }
    }

    /* Check if lvalue is valid in case of assignment */
    if (ast_isOperatorAssignment(this->_operator) && (ast_Node(this->lvalue)->kind != Ast_StorageExpr)) {
        ast_Parser_error(yparser(), "invalid lvalue");
        goto error;
    }

    if (lvalueType && rvalueType) {
        if (!corto_type_castable(lvalueType, rvalueType)) {
            corto_id id, id2;
            ast_Parser_error(yparser(), "cannot convert '%s' to '%s'",
                    ast_Parser_id(rvalueType, id), ast_Parser_id(lvalueType, id2));
            goto error;
        }

        if (ast_Binary_getDerefKind(this, lvalueType, rvalueType)) {
            goto error;
        }
    }

    /* Set operator */
    ast_Binary_setOperator(this, this->_operator);

    return 0;
error:
    return -1;
/* $end */
}

ast_Expression _ast_Binary_fold(ast_Binary this) {
/* $begin(::corto::ast::Binary::fold) */
    ast_Expression result = ast_Expression(this);
    void *lptr, *rptr, *resultPtr;
    corto_type type, rtype;

    if(!this->lvalue || !this->rvalue) {
        ast_Parser_error(yparser(), "invalid binary expression");
        goto error;
    }

    type = ast_Expression_getType_expr(this->lvalue, this->rvalue);
    rtype = ast_Expression_getType_expr(this->rvalue, this->lvalue);

    lptr = (void*)ast_Expression_getValue(this->lvalue);
    rptr = (void*)ast_Expression_getValue(this->rvalue);

    if (!lptr && !rptr) {
        /* If either lvalue or rvalue do not have a compile-time defined value,
         * expression cannot be folded.
         * Only exception is null-literal of which the value is 0 */
        if ((ast_Node(this->lvalue)->kind == Ast_LiteralExpr) &&
           (ast_Node(this->rvalue)->kind == Ast_LiteralExpr)) {
                if (ast_Binary_isConditional(this)) {
                    result = ast_Expression(ast_BooleanCreate(FALSE));
                    resultPtr = (void*)ast_Literal_getValue(ast_Literal(result));
                    corto_binaryOperator(corto_object_o, this->_operator, &lptr, &rptr, resultPtr);
                } else {
                    result = ast_Expression(ast_NullCreate());
                }
           }
    } else if (lptr && rptr) {
        if (type != rtype) {
            ast_Expression rvalueCast = ast_Expression_cast(this->rvalue, type, this->lvalue->isReference);
            rptr = (void*)ast_Expression_getValue(rvalueCast);
        }

        /* Create result-expression */
        if (type->kind == CORTO_PRIMITIVE) {
            if (ast_Binary_isConditional(this)) {
                result = ast_Expression(ast_BooleanCreate(FALSE));
            } else {
                switch(corto_primitive(type)->kind) {
                case CORTO_BOOLEAN: result = ast_Expression(ast_BooleanCreate(FALSE)); break;
                case CORTO_CHARACTER: result = ast_Expression(ast_CharacterCreate('a')); break;
                case CORTO_BITMASK:
                case CORTO_UINTEGER: result = ast_Expression(ast_IntegerCreate(0)); break;
                case CORTO_ENUM:
                case CORTO_INTEGER: result = ast_Expression(ast_SignedIntegerCreate(0)); break;
                case CORTO_FLOAT: result = ast_Expression(ast_FloatingPointCreate(0)); break;
                case CORTO_TEXT: result = ast_Expression(ast_StringCreate(NULL)); break;
                default:
                    ast_Parser_error(yparser(), "Invalid primitive for folding expression");
                    goto error;
                    break;
                }
                if ((corto_primitive(type)->kind == CORTO_BITMASK) || (corto_primitive(type)->kind == CORTO_ENUM)) {
                    corto_setref(&ast_Expression(result)->type, type);
                }
            }

            /* Collect new expression */
            ast_Parser_collect(yparser(), result);

            /* Obtain pointer to value-field */
            resultPtr = (void*)ast_Literal_getValue(ast_Literal(result));

            /* Perform operation */
            if (corto_binaryOperator(type, this->_operator, lptr, rptr, resultPtr)) {
                corto_id id;
                ast_Parser_error(yparser(), "folding of binary %s operation failed", ast_Parser_id(type, id));
                goto error;
            }
        } else {
            /* Expressions of non-primitive type are not folded. */
        }
    }

    return result;
error:
    yparser()->errSet = TRUE;
    return NULL;
/* $end */
}

corto_bool _ast_Binary_hasReturnedResource_v(ast_Binary this) {
/* $begin(::corto::ast::Binary::hasReturnedResource) */

    return ast_Expression_hasReturnedResource(this->lvalue) ||
        ast_Expression_hasReturnedResource(this->rvalue);

/* $end */
}

corto_bool _ast_Binary_hasSideEffects_v(ast_Binary this) {
/* $begin(::corto::ast::Binary::hasSideEffects) */
    corto_bool result = FALSE;

    switch(this->_operator) {
        case CORTO_ASSIGN:
        case CORTO_ASSIGN_ADD:
        case CORTO_ASSIGN_SUB:
        case CORTO_ASSIGN_DIV:
        case CORTO_ASSIGN_MUL:
        case CORTO_ASSIGN_MOD:
        case CORTO_ASSIGN_OR:
        case CORTO_ASSIGN_AND:
            result = TRUE;
            break;
        default:
            break;
    }

    return result || ast_Expression_hasSideEffects(this->lvalue) || ast_Expression_hasSideEffects(this->rvalue);
/* $end */
}

corto_void _ast_Binary_setOperator(ast_Binary this, corto_operatorKind kind) {
/* $begin(::corto::ast::Binary::setOperator) */
    ast_Binary compoundExpr = NULL;
    corto_type exprType = NULL;

    exprType = ast_Expression_getType_expr(this->lvalue, this->rvalue);

    /* Assign operator before cast - it can influence the type */
    this->_operator = kind;

    /* If operator is a compound operator (assign_*), split up in two binary expressions */
    switch(this->_operator) {
    case CORTO_ASSIGN_ADD: compoundExpr = ast_BinaryCreate(this->lvalue, this->rvalue, CORTO_ADD); break;
    case CORTO_ASSIGN_SUB: compoundExpr = ast_BinaryCreate(this->lvalue, this->rvalue, CORTO_SUB); break;
    case CORTO_ASSIGN_DIV: compoundExpr = ast_BinaryCreate(this->lvalue, this->rvalue, CORTO_DIV); break;
    case CORTO_ASSIGN_MUL: compoundExpr = ast_BinaryCreate(this->lvalue, this->rvalue, CORTO_MUL); break;
    case CORTO_ASSIGN_MOD: compoundExpr = ast_BinaryCreate(this->lvalue, this->rvalue, CORTO_MOD); break;
    case CORTO_ASSIGN_OR:  compoundExpr = ast_BinaryCreate(this->lvalue, this->rvalue, CORTO_OR); break;
    case CORTO_ASSIGN_AND: compoundExpr = ast_BinaryCreate(this->lvalue, this->rvalue, CORTO_AND); break;
        break;
    default:
        break;
    }

    if (compoundExpr) {
        this->_operator = CORTO_ASSIGN;
        corto_setref(&this->rvalue, compoundExpr);
        ast_Parser_collect(yparser(), compoundExpr);
    }

    /* Apply casting on operands if necessary */
    if (exprType && (exprType->kind != CORTO_ITERATOR)) {
        if (ast_Binary_cast(this, &exprType)) {
            goto error;
        }
    }

    /* Depending on the operator, the returnType might be a bool or the type of the lvalue */
    switch(this->_operator) {
    case CORTO_COND_EQ:
    case CORTO_COND_NEQ:
    case CORTO_COND_LT:
    case CORTO_COND_GT:
    case CORTO_COND_LTEQ:
    case CORTO_COND_GTEQ:
    case CORTO_COND_AND:
    case CORTO_COND_OR:
        corto_setref(&ast_Expression(this)->type, corto_bool_o);
        break;
    default:
        corto_setref(&ast_Expression(this)->type, exprType);
        break;
    }

    /* If the expression type is not a scalar, insert complex operations */
    if ((exprType->kind != CORTO_PRIMITIVE) && (this->deref != Ast_ByReference) &&
        (ast_Node(this->rvalue)->kind != Ast_CallExpr)) {
        if (ast_Binary_complexExpr(this)) {
            goto error;
        }
        this->isScalar = FALSE;
    } else {
        this->isScalar = TRUE;
    }

error:
    return;
/* $end */
}

ic_node _ast_Binary_toIc_v(ast_Binary this, ic_program program, ic_storage storage, corto_bool stored) {
/* $begin(::corto::ast::Binary::toIc) */
    ic_node returnsResult = NULL;

    if (this->isScalar) {
        ic_node lvalue, rvalue, result, conditionLvalue, conditionRvalue = NULL;
        corto_type thisType = ast_Expression_getType(ast_Expression(this));
        corto_bool condition = ast_Binary_isConditional(this);
        corto_bool isReference = (this->lvalue->deref == Ast_ByReference) || (this->rvalue->deref == Ast_ByReference);
        ic_derefKind deref = this->deref == Ast_ByReference ? IC_DEREF_ADDRESS : IC_DEREF_VALUE;

        if (storage && (storage->type == thisType)) {
            result = (ic_node)storage;
        } else {
            result = (ic_node)ic_program_pushAccumulator(program, thisType, isReference, FALSE);
        }

        returnsResult = result;

        if (condition) {
            conditionLvalue = (ic_node)ic_program_pushAccumulator(program, ast_Expression_getType(this->lvalue), this->lvalue->isReference, FALSE);
            conditionRvalue = (ic_node)ic_program_pushAccumulator(program, ast_Expression_getType(this->rvalue), this->rvalue->isReference, FALSE);
        }

        lvalue = ast_Node_toIc(
                ast_Node(this->lvalue),
                program,
                condition ? (ic_storage)conditionLvalue : (ic_storage)result,
                TRUE);

        if (this->_operator == CORTO_ASSIGN) {
            rvalue = ast_Node_toIc(ast_Node(this->rvalue), program, (ic_storage)lvalue, TRUE);
            if (lvalue != rvalue) {
                IC_3(program, ast_Node(this)->line, ic_set,
                    stored ? result : NULL, lvalue, rvalue, IC_DEREF_VALUE, deref, deref);
            } else {
                returnsResult = rvalue;
            }
        } else if (stored && result) {
            rvalue = ast_Node_toIc(ast_Node(this->rvalue), program, (ic_storage)conditionRvalue, TRUE);
            if ((thisType->kind == CORTO_PRIMITIVE) && (corto_primitive(thisType)->kind == CORTO_TEXT)) {
                if (ast_Binary_toIc_strOp(this, program, (ic_storage)result, ic_node(lvalue), ic_node(rvalue))) {
                    goto error;
                }
            } else {
                IC_3(program, ast_Node(this)->line, ic_opKindFromOperator(this->_operator), result, lvalue, rvalue,
                    IC_DEREF_VALUE, deref, deref);
            }
        } else {
            if (ast_Expression_hasSideEffects(this->rvalue)) {
                rvalue = ast_Node_toIc(ast_Node(this->rvalue), program, (ic_storage)conditionRvalue, FALSE);
            }
        }

        if (condition) {
            ic_program_popAccumulator(program);
            ic_program_popAccumulator(program);
        }

        if ((ic_node)storage != result) {
            ic_program_popAccumulator(program);
        }
    } else {
        returnsResult = ast_Node_toIc(
            ast_Node(this->lvalue),
            program,
            NULL,
            TRUE);
    }

    return returnsResult;
error:
    return NULL;

/* $end */
}
