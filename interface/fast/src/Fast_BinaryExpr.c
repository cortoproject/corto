/* Fast_BinaryExpr.c
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
#include "Fast_Parser.h"
#include "Fast_Literal.h"
#include "cx_operator.h"

/* Determine whether expression is an assignment */
cx_bool Fast_BinaryExpr_isAssignment(Fast_BinaryExpr expr) {
    cx_bool result;
    switch(expr->operator) {
    case CX_ASSIGN:
    case CX_ASSIGN_ADD:
    case CX_ASSIGN_SUB:
    case CX_ASSIGN_DIV:
    case CX_ASSIGN_MUL:
    case CX_ASSIGN_MOD:
    case CX_ASSIGN_OR:
    case CX_ASSIGN_AND:
        result = TRUE;
        break;
    default:
        result = FALSE;
        break;
    }
    return result;
}

/* Determine whether expression is an assignment */
cx_bool Fast_BinaryExpr_isConditional(Fast_BinaryExpr expr) {
    cx_bool result;
    switch(expr->operator) {
    case CX_COND_EQ:
    case CX_COND_NEQ:
    case CX_COND_LT:
    case CX_COND_LTEQ:
    case CX_COND_GT:
    case CX_COND_GTEQ:
    case CX_COND_AND:
    case CX_COND_OR:
    case CX_COND_NOT:
        result = TRUE;
        break;
    default:
        result = FALSE;
        break;
    }
    return result;
}

/* If types of a binary expression don't match, figure out which casts are required */
cx_int16 Fast_BinaryExpr_cast(Fast_BinaryExpr _this, cx_type *returnType) {
    cx_type lvalueType, rvalueType, castType = NULL;
    Fast_Expression lvalue, rvalue;
    cx_bool referenceMismatch = FALSE;

    /* Get lvalueType and rvalueType */
    lvalue = _this->lvalue;
    rvalue = _this->rvalue;
    lvalueType = Fast_Expression_getType(lvalue);
    rvalueType = Fast_Expression_getType_expr(rvalue, lvalue);
    castType = NULL;

    /* Narrow expressions where possible */
    _this->lvalue = Fast_Expression_narrow(lvalue, rvalueType);
    if (_this->lvalue) {
        cx_keep_ext(_this, _this->lvalue, "Keep narrow'd lvalue");
        cx_free_ext(_this, lvalue, "Free old lvalue");
        lvalueType = Fast_Expression_getType(_this->lvalue);
    }

    _this->rvalue = Fast_Expression_narrow(rvalue, lvalueType);
    if (_this->rvalue) {
        cx_keep_ext(_this, _this->rvalue, "Keep narrow'd rvalue");
        cx_free_ext(_this, rvalue, "Free old rvalue");
        rvalueType = Fast_Expression_getType_expr(_this->rvalue, _this->lvalue);
    }

    if(!lvalueType) {
        lvalueType = rvalueType;
    }

    if (_this->operator == CX_DIV) {
        castType = cx_type(cx_float64_o);
    } else if (lvalueType != rvalueType) {
        Fast_nodeKind lKind = Fast_Node(_this->lvalue)->kind;
        Fast_nodeKind rKind = Fast_Node(_this->rvalue)->kind;
        
        /* If one of the operands is a literal, always cast to the type of the non-literal */
        if ((lKind == FAST_Literal) ^ (rKind == FAST_Literal)) {
            if (lKind == FAST_Literal) {
                castType = rvalueType;
            } else {
                castType = lvalueType;
            }
        } else

        /* Can only cast between primitive types */
        if ((lvalueType->kind == CX_PRIMITIVE ) && (rvalueType->kind == CX_PRIMITIVE)) {
            cx_primitive ltype = cx_primitive(lvalueType), rtype = cx_primitive(rvalueType);
            cx_int8 lscore, rscore;
            cx_int8 lCastScore, rCastScore;

            lscore = Fast_Expression_getTypeScore(ltype);
            rscore = Fast_Expression_getTypeScore(rtype);
            lCastScore = Fast_Expression_getCastScore(ltype);
            rCastScore = Fast_Expression_getCastScore(rtype);

            /* If expression is an assignment, always take type of lvalue. Otherwise determine based on
             * expressibility score which type to cast to.
             */
            if (Fast_BinaryExpr_isAssignment(_this)) {
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
        } else if ((rvalueType->reference || _this->rvalue->forceReference) && !lvalueType->reference) {
            if (cx_type_castable(lvalueType, cx_object_o)) {
                castType = lvalueType;
            }
        }  else {
            cx_id id1, id2;
            Fast_Parser_error(yparser(), "no cast between '%s' and '%s'",
                    cx_fullname(lvalueType, id1), cx_fullname(rvalueType, id2));
            goto error;
        }
    } else if ((rvalueType->reference || _this->rvalue->forceReference) && !lvalueType->reference) {
        if (cx_type_castable(lvalueType, cx_object_o)) {
            castType = lvalueType;
            referenceMismatch = TRUE;
        }
    }

    /* Cast-score indicates whether a cast is required */
    if (rvalueType && castType && ((rvalueType != castType) || referenceMismatch)) {
        Fast_Expression oldRvalue = _this->rvalue;
        _this->rvalue = Fast_Expression_cast(_this->rvalue, castType, _this->lvalue->forceReference);
        if (_this->rvalue) {
            cx_keep(_this->rvalue);
            cx_free(oldRvalue);
        } else {
            cx_id id, id2;
            Fast_Parser_error(yparser(), "failed to cast rvalue from '%s' to '%s'",
                    cx_fullname(rvalueType, id), cx_fullname(castType, id2));
            goto error;
        }
    }
    if (lvalueType && castType && (lvalueType != castType)) {
        Fast_Expression oldLvalue = _this->lvalue;
        _this->lvalue = Fast_Expression_cast(_this->lvalue, castType, _this->rvalue->forceReference);
        if (_this->lvalue) {
            cx_keep(_this->lvalue);
            cx_free(oldLvalue);
        } else {
            cx_id id, id2;
            Fast_Parser_error(yparser(), "failed to cast lvalue from '%s' to '%s'",
                    cx_fullname(lvalueType, id), cx_fullname(castType, id2));
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

cx_int16 Fast_BinaryExpr_toIc_strOp(
        Fast_BinaryExpr _this,
        cx_icProgram program,
        cx_icStorage storage,
        cx_icValue lvalue,
        cx_icValue rvalue) {
    cx_icOp op;
    cx_ic dummy;
    cx_value v;

    switch(_this->operator) {
    /* Append strings */
    case CX_ADD:
        v.is.value.storage = 0; /* Create NULL-string */
        cx_valueLiteralInit(&v, CX_LITERAL_STRING, &v.is.value.storage);
        dummy = (cx_ic)cx_icLiteral__create(program, Fast_Node(_this)->line, v, cx_type(cx_string_o));

        op = cx_icOp__create(program, Fast_Node(_this)->line, CX_IC_STRCAT, NULL, (cx_icValue)lvalue, (cx_icValue)rvalue);
        cx_icProgram_addIc(program, (cx_ic)op);

        op = cx_icOp__create(program, Fast_Node(_this)->line, CX_IC_STRCPY, NULL, (cx_icValue)storage, (cx_icValue)dummy);
        cx_icProgram_addIc(program, (cx_ic)op);
        break;

    case CX_ASSIGN:
        op = cx_icOp__create(program, Fast_Node(_this)->line, cx_icOpKindFromOperator(_this->operator), (cx_icValue)storage, (cx_icValue)lvalue, (cx_icValue)rvalue);
        cx_icProgram_addIc(program, (cx_ic)op);
        break;
    default:
        Fast_Parser_error(yparser(), "operator '%s' invalid for strings", 
            cx_nameof(cx_enum_constant(cx_operatorKind_o, _this->operator)));
        goto error;
    }

    return 0;
error:
    return -1;
}

/* $end */

/* ::cortex::Fast::BinaryExpr::construct() */
cx_int16 Fast_BinaryExpr_construct(Fast_BinaryExpr _this) {
/* $begin(::cortex::Fast::BinaryExpr::construct) */
    cx_type lvalueType, rvalueType;
    cx_int32 checkReferences=0;

    Fast_Node(_this)->kind = FAST_Binary;
    lvalueType = Fast_Expression_getType_expr(_this->lvalue, _this->rvalue);
    rvalueType = Fast_Expression_getType_expr(_this->rvalue, _this->lvalue);

    if (lvalueType && rvalueType) {
        if (!cx_type_castable(lvalueType, rvalueType)) {
            cx_id id, id2;
            Fast_Parser_error(yparser(), "cannot convert '%s' to '%s'",
                    cx_fullname(rvalueType, id), cx_fullname(lvalueType, id2));
            goto error;
        }

        /* Re-obtain lvalueType & rvalueType as they may have changed during the cast */
        lvalueType = Fast_Expression_getType_expr(_this->lvalue, _this->rvalue);
        rvalueType = Fast_Expression_getType_expr(_this->rvalue, _this->lvalue);

        /* Check for consistent usage of references */
        Fast_Expression_getDerefMode(_this->lvalue, _this->rvalue, &checkReferences);
        Fast_Expression_getDerefMode(_this->rvalue, _this->lvalue, &checkReferences);
        if (checkReferences) {
            Fast_Parser_error(yparser(), "inconsistent usage of references in binary expression");
            goto error;
        }

    }

    /* Set operator */
    Fast_BinaryExpr_setOperator(_this, _this->operator);

    return 0;
error:
    return -1;
/* $end */
}

/* ::cortex::Fast::BinaryExpr::fold() */
Fast_Expression Fast_BinaryExpr_fold(Fast_BinaryExpr _this) {
/* $begin(::cortex::Fast::BinaryExpr::fold) */
    Fast_Expression result = Fast_Expression(_this);
    void *lptr, *rptr, *resultPtr;
    cx_type type, rtype;

    if(!_this->lvalue || !_this->rvalue) {
        Fast_Parser_error(yparser(), "invalid binary expression");
        goto error;
    }

    type = Fast_Expression_getType_expr(_this->lvalue, _this->rvalue);
    rtype = Fast_Expression_getType_expr(_this->rvalue, _this->lvalue);

    lptr = (void*)Fast_Expression_getValue(_this->lvalue);
    rptr = (void*)Fast_Expression_getValue(_this->rvalue);

    if (!lptr && !rptr) {
        /* If either lvalue or rvalue do not have a compile-time defined value,
         * expression cannot be folded.
         * Only exception is null-literal of which the value is 0 */
        if ((Fast_Node(_this->lvalue)->kind == FAST_Literal) &&
           (Fast_Node(_this->rvalue)->kind == FAST_Literal)) {
                if (Fast_BinaryExpr_isConditional(_this)) {
                    result = Fast_Expression(Fast_Boolean__create(FALSE));
                    resultPtr = (void*)Fast_Literal_getValue(Fast_Literal(result));
                    cx_binaryOperator(cx_object_o, _this->operator, &lptr, &rptr, resultPtr);
                } else {
                    result = Fast_Expression(Fast_Null__create());
                }
           }
    } else if (lptr && rptr) {
        if (type != rtype) {
            Fast_Expression rvalueCast = Fast_Expression_cast(_this->rvalue, type, _this->lvalue->isReference);
            rptr = (void*)Fast_Expression_getValue(rvalueCast);
        }

        /* Create result-expression */
        if (type->kind == CX_PRIMITIVE) {
            if (Fast_BinaryExpr_isConditional(_this)) {
                result = Fast_Expression(Fast_Boolean__create(FALSE));
            } else {
                switch(cx_primitive(type)->kind) {
                case CX_BOOLEAN: result = Fast_Expression(Fast_Boolean__create(FALSE)); break;
                case CX_CHARACTER: result = Fast_Expression(Fast_Character__create('a')); break;
                case CX_BITMASK:
                case CX_UINTEGER: result = Fast_Expression(Fast_Integer__create(0)); break;
                case CX_ENUM:
                case CX_INTEGER: result = Fast_Expression(Fast_SignedInteger__create(0)); break;
                case CX_FLOAT: result = Fast_Expression(Fast_FloatingPoint__create(0)); break;
                case CX_TEXT: result = Fast_Expression(Fast_String__create(NULL)); break;
                default:
                    Fast_Parser_error(yparser(), "Invalid primitive for folding expression");
                    goto error;
                    break;
                }
                if ((cx_primitive(type)->kind == CX_BITMASK) || (cx_primitive(type)->kind == CX_ENUM)) {
                    Fast_Object typeVar = Fast_Object__create(type);
                    cx_set(&Fast_Expression(result)->type, typeVar);
                }
            }

            /* Collect new expression */
            Fast_Parser_collect(yparser(), result);

            /* Obtain pointer to value-field */
            resultPtr = (void*)Fast_Literal_getValue(Fast_Literal(result));

            /* Perform operation */
            if (cx_binaryOperator(type, _this->operator, lptr, rptr, resultPtr)) {
                cx_id id;
                Fast_Parser_error(yparser(), "folding of binary %s operation failed", cx_fullname(type, id));
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

/* ::cortex::Fast::BinaryExpr::hasSideEffects() */
cx_bool Fast_BinaryExpr_hasSideEffects_v(Fast_BinaryExpr _this) {
/* $begin(::cortex::Fast::BinaryExpr::hasSideEffects) */
    cx_bool result = FALSE;
    
    switch(_this->operator) {
        case CX_ASSIGN:
        case CX_ASSIGN_ADD:
        case CX_ASSIGN_SUB:
        case CX_ASSIGN_DIV:
        case CX_ASSIGN_MUL:
        case CX_ASSIGN_MOD:
        case CX_ASSIGN_OR:
        case CX_ASSIGN_AND:
            result = TRUE;
            break;
        default:
            break;
    }
    
    return Fast_Expression_hasSideEffects(_this->lvalue) || Fast_Expression_hasSideEffects(_this->rvalue) || result;
/* $end */
}

/* ::cortex::Fast::BinaryExpr::setOperator(operatorKind kind) */
cx_void Fast_BinaryExpr_setOperator(Fast_BinaryExpr _this, cx_operatorKind kind) {
/* $begin(::cortex::Fast::BinaryExpr::setOperator) */
    Fast_BinaryExpr compoundExpr = NULL;
    cx_type exprType = NULL;

    exprType = Fast_Expression_getType_expr(_this->lvalue, _this->rvalue);

    /* Assign operator before cast - it can influence the type */
    _this->operator = kind;

    /* If operator is a compound operator (assign_*), split up in two binary expressions */
    switch(_this->operator) {
    case CX_ASSIGN_ADD: compoundExpr = Fast_BinaryExpr__create(_this->lvalue, _this->rvalue, CX_ADD); break;
    case CX_ASSIGN_SUB: compoundExpr = Fast_BinaryExpr__create(_this->lvalue, _this->rvalue, CX_SUB); break;
    case CX_ASSIGN_DIV: compoundExpr = Fast_BinaryExpr__create(_this->lvalue, _this->rvalue, CX_DIV); break;
    case CX_ASSIGN_MUL: compoundExpr = Fast_BinaryExpr__create(_this->lvalue, _this->rvalue, CX_MUL); break;
    case CX_ASSIGN_MOD: compoundExpr = Fast_BinaryExpr__create(_this->lvalue, _this->rvalue, CX_MOD); break;
    case CX_ASSIGN_OR:  compoundExpr = Fast_BinaryExpr__create(_this->lvalue, _this->rvalue, CX_OR); break;
    case CX_ASSIGN_AND: compoundExpr = Fast_BinaryExpr__create(_this->lvalue, _this->rvalue, CX_AND); break;
        break;
    default:
        break;
    }

    if (compoundExpr) {
        _this->operator = CX_ASSIGN;
        cx_set(&_this->rvalue, compoundExpr);
        Fast_Parser_collect(yparser(), compoundExpr);
    }

    /* Apply casting on operands if necessary */
    if (exprType) {
        if (Fast_BinaryExpr_cast(_this, &exprType)) {
            goto error;
        }
    }

    /* Depending on the operator, the returnType might be a bool or the type of the lvalue */
    switch(_this->operator) {
    case CX_COND_EQ:
    case CX_COND_NEQ:
    case CX_COND_LT:
    case CX_COND_GT:
    case CX_COND_LTEQ:
    case CX_COND_GTEQ:
    case CX_COND_AND:
    case CX_COND_OR:
        cx_set(&Fast_Expression(_this)->type, Fast_Variable(Fast_Object__create(cx_bool_o)));
        break;
    default:
        cx_set(&Fast_Expression(_this)->type, Fast_Variable(Fast_Object__create(exprType)));
        break;
    }

    return;
error:
    return;
/* $end */
}

/* ::cortex::Fast::BinaryExpr::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_BinaryExpr_toIc_v(Fast_BinaryExpr _this, cx_icProgram program, cx_icStorage storage, cx_bool stored) {
/* $begin(::cortex::Fast::BinaryExpr::toIc) */
    cx_ic lvalue, rvalue, result, returnsResult, conditionLvalue, conditionRvalue = NULL;
    cx_icOp op = NULL;
    cx_type _thisType = Fast_Expression_getType(Fast_Expression(_this));
    cx_bool condition = Fast_BinaryExpr_isConditional(_this);
    cx_bool isReference = _this->lvalue->forceReference || _this->rvalue->forceReference;

    if (storage && (storage->type == _thisType)) {
        result = (cx_ic)storage;
    } else {
        result = (cx_ic)cx_icProgram_accumulatorPush(program, Fast_Node(_this)->line, _thisType, isReference);
    }

    returnsResult = result;

    if (condition) {
        conditionLvalue = (cx_ic)cx_icProgram_accumulatorPush(program, Fast_Node(_this)->line, Fast_Expression_getType(_this->lvalue), _this->lvalue->isReference);
        conditionRvalue = (cx_ic)cx_icProgram_accumulatorPush(program, Fast_Node(_this)->line, Fast_Expression_getType(_this->rvalue), _this->rvalue->isReference);
    }

    /* Parse lvalue and rvalue */
    lvalue = Fast_Node_toIc(
            Fast_Node(_this->lvalue),
            program,
            condition ? (cx_icStorage)conditionLvalue :  (cx_icStorage)result,
            TRUE);

    /* If operator is assign, pass lvalue as storage */
    if (_this->operator == CX_ASSIGN) {
        rvalue = Fast_Node_toIc(Fast_Node(_this->rvalue), program, (cx_icStorage)lvalue, TRUE);
        
        /* Add instruction to program if lvalue != rvalue */
        if (lvalue != rvalue) {
            op = cx_icOp__create(program, Fast_Node(_this)->line, cx_icOpKindFromOperator(CX_ASSIGN), stored ? (cx_icValue)result : NULL, (cx_icValue)lvalue, (cx_icValue)rvalue);
            cx_icProgram_addIc(program, (cx_ic)op);

            op->s2Deref = Fast_Expression_getDerefMode(_this->lvalue, _this->rvalue, NULL);
            op->s3Deref = Fast_Expression_getDerefMode(_this->rvalue, _this->lvalue, NULL);

            /* If lvalue is an object, never use address in assignments */
            if ((Fast_Node(_this->lvalue)->kind == FAST_Variable) && (Fast_Variable(_this->lvalue)->kind == FAST_Object)) {
                op->s2Deref = CX_IC_DEREF_VALUE;
                op->s3Deref = CX_IC_DEREF_VALUE;
            }
        } else {
            returnsResult = rvalue;
        }
    /* Only compile expression when there is a result - if it's not an assignment */
    } else if (stored && result) {
        rvalue = Fast_Node_toIc(Fast_Node(_this->rvalue), program, (cx_icStorage)conditionRvalue, TRUE);

        /* If operation is a string, insert string-specific operations */
        if ((_thisType->kind == CX_PRIMITIVE) && (cx_primitive(_thisType)->kind == CX_TEXT)) {
            if (Fast_BinaryExpr_toIc_strOp(_this, program, (cx_icStorage)result, (cx_icValue)lvalue, (cx_icValue)rvalue)) {
                goto error;
            }
        } else {
            /* Add instruction to program. */
            op = cx_icOp__create(program, Fast_Node(_this)->line, cx_icOpKindFromOperator(_this->operator), (cx_icValue)result, (cx_icValue)lvalue, (cx_icValue)rvalue);
            cx_icProgram_addIc(program, (cx_ic)op);
        }

        if (op) {
            op->s2Deref = Fast_Expression_getDerefMode(_this->lvalue, _this->rvalue, NULL);
            op->s3Deref = Fast_Expression_getDerefMode(_this->rvalue, _this->lvalue, NULL);
        }
    } else {
        if (Fast_Expression_hasSideEffects(_this->rvalue)) {
            rvalue = Fast_Node_toIc(Fast_Node(_this->rvalue), program, (cx_icStorage)conditionRvalue, FALSE);
        }
    }

    if (condition) {
        cx_icProgram_accumulatorPop(program, Fast_Node(_this)->line);
        cx_icProgram_accumulatorPop(program, Fast_Node(_this)->line);
    }

    if ((cx_ic)storage != result) {
        cx_icProgram_accumulatorPop(program, Fast_Node(_this)->line);
    }

    return returnsResult;
error:
    return NULL;
/* $end */
}
