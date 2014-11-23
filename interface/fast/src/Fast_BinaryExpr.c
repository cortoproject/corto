/* Fast_BinaryExpr.c
 *
 *  Generated on Nov 18 2014
 *    This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "Fast_BinaryExpr.h"
#include "Fast__meta.h"


/* $header() */
#include "Fast__api.h"
#include "Fast_Parser.h"
#include "Fast_Literal.h"
#include "db_operator.h"
Fast_Parser yparser(void);
void Fast_Parser_error(Fast_Parser _this, char* fmt, ...);
void Fast_Parser_warning(Fast_Parser _this, char* fmt, ...);
db_int8 Fast_Expression_getTypeScore(db_primitive t);
db_int8 Fast_Expression_getCastScore(db_primitive t);
db_icDerefMode Fast_Expression_getDerefMode(Fast_Expression _this, Fast_Expression rvalue, db_int32 *check);


/* Determine whether expression is an assignment */
db_bool Fast_BinaryExpr_isAssignment(Fast_BinaryExpr expr) {
	db_bool result;
	switch(expr->operator) {
	case DB_ASSIGN:
	case DB_ASSIGN_ADD:
	case DB_ASSIGN_SUB:
	case DB_ASSIGN_DIV:
	case DB_ASSIGN_MUL:
	case DB_ASSIGN_MOD:
	case DB_ASSIGN_OR:
	case DB_ASSIGN_AND:
		result = TRUE;
		break;
	default:
		result = FALSE;
		break;
	}
	return result;
}

/* Determine whether expression is an assignment */
db_bool Fast_BinaryExpr_isConditional(Fast_BinaryExpr expr) {
	db_bool result;
	switch(expr->operator) {
	case DB_COND_EQ:
	case DB_COND_NEQ:
	case DB_COND_LT:
	case DB_COND_LTEQ:
	case DB_COND_GT:
	case DB_COND_GTEQ:
	case DB_COND_AND:
	case DB_COND_OR:
	case DB_COND_NOT:
		result = TRUE;
		break;
	default:
		result = FALSE;
		break;
	}
	return result;
}

/* Check if expression is integer literal that is eligible to changing type, if this is the case do the cast */
Fast_Expression Fast_BinaryExpr_narrow(Fast_Expression expr, db_type target) {
	Fast_Expression result = expr;

	if (Fast_Node(expr)->kind == FAST_Literal) {
		db_type t = Fast_Expression_getType_type(expr, target);
		if ((t != target) &&
		   (target->kind == DB_PRIMITIVE) &&
		   (db_primitive(target)->kind == db_primitive(t)->kind)) {
			db_width width = db_primitive(target)->width;

			if (t->kind == DB_PRIMITIVE) {
				switch(db_primitive(t)->kind) {
				case DB_INTEGER: {
					db_int64 v = *(db_int64*)Fast_Expression_getValue(expr);
					switch(width) {
					case DB_WIDTH_8:
						if ((v <= 127) && (v >= -128)) {
							result = Fast_Expression_cast(expr, target);
						}
						break;
					case DB_WIDTH_16:
						if ((v <= 32767) && (v >= -32768)) {
							result = Fast_Expression_cast(expr, target);
						}
						break;
					case DB_WIDTH_32:
						if ((v <= 2147483647) && (v >= 2147483648)) {
							result = Fast_Expression_cast(expr, target);
						}
						break;
					default:
						break;
					}
					break;
				}
				case DB_UINTEGER: {
					db_uint64 v = *(db_uint64*)Fast_Expression_getValue(expr);
					switch(width) {
					case DB_WIDTH_8:
						if (v <= 255) {
							result = Fast_Expression_cast(expr, target);
						}
						break;
					case DB_WIDTH_16:
						if (v <= 65535) {
							result = Fast_Expression_cast(expr, target);
						}
						break;
					case DB_WIDTH_32:
						if (v <= 4294967295) {
							result = Fast_Expression_cast(expr, target);
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

	return result;
}

/* If types of a binary expression don't match, figure out which casts are required */
db_int16 Fast_BinaryExpr_cast(Fast_BinaryExpr _this, db_type *returnType) {
	db_type lvalueType, rvalueType, castType = NULL;
	Fast_Expression lvalue, rvalue;

	/* Get lvalueType and rvalueType */
	lvalue = _this->lvalue;
	rvalue = _this->rvalue;
	lvalueType = Fast_Expression_getType_expr(lvalue, rvalue);
	rvalueType = Fast_Expression_getType_expr(rvalue, lvalue);
	castType = NULL;

	/* Narrow expressions where possible */
	_this->lvalue = Fast_BinaryExpr_narrow(lvalue, rvalueType);
	if (_this->lvalue) {
		db_keep_ext(_this, _this->lvalue, "Keep narrow'd lvalue");
		db_free_ext(_this, lvalue, "Free old lvalue");
		lvalueType = Fast_Expression_getType_expr(_this->lvalue, _this->rvalue);
	}

	_this->rvalue = Fast_BinaryExpr_narrow(rvalue, lvalueType);
	if (_this->rvalue) {
		db_keep_ext(_this, _this->rvalue, "Keep narrow'd rvalue");
		db_free_ext(_this, rvalue, "Free old rvalue");
		rvalueType = Fast_Expression_getType_expr(_this->rvalue, _this->lvalue);
	}

	if (lvalueType != rvalueType) {
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
		if ((lvalueType->kind == DB_PRIMITIVE ) && (rvalueType->kind == DB_PRIMITIVE)) {
			db_primitive ltype = db_primitive(lvalueType), rtype = db_primitive(rvalueType);
			db_int8 lscore, rscore;
            db_int8 lCastScore, rCastScore;

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
		} else {
			db_id id1, id2;
			Fast_Parser_error(yparser(), "no cast between '%s' and '%s'",
					db_fullname(lvalueType, id1), db_fullname(rvalueType, id2));
			goto error;
		}
	}

    /* Cast-score indicates whether a cast is required */
    if (castType == lvalueType) {
        Fast_Expression oldRvalue = _this->rvalue;
        _this->rvalue = Fast_Expression_cast(_this->rvalue, lvalueType);
        if (_this->rvalue) {
            db_keep(_this->rvalue);
            db_free(oldRvalue);
        } else {
            db_id id, id2;
            Fast_Parser_error(yparser(), "failed to cast rvalue from '%s' to '%s'",
                    db_fullname(rvalueType, id), db_fullname(lvalueType, id2));
            goto error;
        }
    } else if (castType == rvalueType) {
        Fast_Expression oldLvalue = _this->lvalue;
        _this->lvalue = Fast_Expression_cast(_this->lvalue, rvalueType);
        if (_this->lvalue) {
            db_keep(_this->lvalue);
            db_free(oldLvalue);
        } else {
            db_id id, id2;
            Fast_Parser_error(yparser(), "failed to cast lvalue from '%s' to '%s'",
                    db_fullname(lvalueType, id), db_fullname(rvalueType, id2));
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

void Fast_BinaryExpr_toIc_strOp(
		Fast_BinaryExpr _this,
		db_icProgram program,
		db_icStorage storage,
		db_icValue lvalue,
		db_icValue rvalue) {
	db_icOp op;
	db_ic dummy;
	db_value v;

	switch(_this->operator) {
	/* Append strings */
	case DB_ADD:
		v.is.value.storage = 0; /* Create NULL-string */
		db_valueLiteralInit(&v, DB_LITERAL_STRING, &v.is.value.storage);
		dummy = (db_ic)db_icLiteral__create(program, Fast_Node(_this)->line, v, db_type(db_string_o));

		op = db_icOp__create(program, Fast_Node(_this)->line, DB_IC_STRCAT, NULL, (db_icValue)lvalue, (db_icValue)rvalue);
		db_icProgram_addIc(program, (db_ic)op);

		op = db_icOp__create(program, Fast_Node(_this)->line, DB_IC_STRCPY, NULL, (db_icValue)storage, (db_icValue)dummy);
		db_icProgram_addIc(program, (db_ic)op);
		break;

	default:
		op = db_icOp__create(program, Fast_Node(_this)->line, db_icOpKindFromOperator(_this->operator), (db_icValue)storage, (db_icValue)lvalue, (db_icValue)rvalue);
		db_icProgram_addIc(program, (db_ic)op);
		break;
	}
}
/* $end */

/* callback ::hyve::lang::class::construct(lang::object object) -> ::hyve::Fast::BinaryExpr::construct(Fast::BinaryExpr object) */
db_int16 Fast_BinaryExpr_construct(Fast_BinaryExpr object) {
/* $begin(::hyve::Fast::BinaryExpr::construct) */
	db_type lvalueType, rvalueType;
	db_int32 checkReferences=0;
    db_type exprType = NULL;

    Fast_Node(object)->kind = FAST_Binary;
    lvalueType = Fast_Expression_getType_expr(object->lvalue, object->rvalue);
    rvalueType = Fast_Expression_getType_expr(object->rvalue, object->lvalue);
    exprType = lvalueType;

    if (lvalueType && rvalueType) {
		if (!db_type_castable(lvalueType, rvalueType)) {
			db_id id, id2;
			Fast_Parser_error(yparser(), "type '%s' of right operand cannot be converted to '%s' in binary expression",
					db_fullname(rvalueType, id), db_fullname(lvalueType, id2));
			goto error;
		}

		/* Re-obtain lvalueType & rvalueType as they may have changed during the cast */
	    lvalueType = Fast_Expression_getType_expr(object->lvalue, object->rvalue);
	    rvalueType = Fast_Expression_getType_expr(object->rvalue, object->lvalue);

	    /* Check for consistent usage of references */
	    Fast_Expression_getDerefMode(object->lvalue, object->rvalue, &checkReferences);
	    Fast_Expression_getDerefMode(object->rvalue, object->lvalue, &checkReferences);
	    if (checkReferences) {
	    	Fast_Parser_error(yparser(), "inconsistent usage of references in binary expression");
	    	goto error;
	    }

    }

    /* Set operator */
    Fast_BinaryExpr_setOperator(object, object->operator);

    return 0;
error:
	return -1;
/* $end */
}

/* ::hyve::Fast::BinaryExpr::fold() */
Fast_Expression Fast_BinaryExpr_fold(Fast_BinaryExpr _this) {
/* $begin(::hyve::Fast::BinaryExpr::fold) */
	Fast_Expression result = Fast_Expression(_this);
	void *lptr, *rptr, *resultPtr;
	db_type type, rtype;

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
		   			db_binaryOperator(db_object_o, _this->operator, &lptr, &rptr, resultPtr);
		   		} else {
					result = Fast_Expression(Fast_Null__create());
				}
		   }
	} else if (lptr && rptr) {
		if (type != rtype) {
			Fast_Expression rvalueCast = Fast_Expression_cast(_this->rvalue, type);
			rptr = (void*)Fast_Expression_getValue(rvalueCast);
		}

		/* Create result-expression */
		if (type->kind == DB_PRIMITIVE) {
			if (Fast_BinaryExpr_isConditional(_this)) {
				result = Fast_Expression(Fast_Boolean__create(FALSE));
			} else {
				switch(db_primitive(type)->kind) {
				case DB_BOOLEAN: result = Fast_Expression(Fast_Boolean__create(FALSE)); break;
				case DB_CHARACTER: result = Fast_Expression(Fast_Character__create('a')); break;
				case DB_UINTEGER: result = Fast_Expression(Fast_Integer__create(0)); break;
				case DB_ENUM:
				case DB_BITMASK:
				case DB_INTEGER: result = Fast_Expression(Fast_SignedInteger__create(0)); break;
				case DB_FLOAT: result = Fast_Expression(Fast_FloatingPoint__create(0)); break;
				case DB_TEXT: result = Fast_Expression(Fast_String__create(NULL)); break;
				default:
					Fast_Parser_error(yparser(), "Invalid primitive for folding expression");
					goto error;
					break;
				}
			}

			/* Collect new expression */
			Fast_Parser_collect(yparser(), result);

			/* Obtain pointer to value-field */
			resultPtr = (void*)Fast_Literal_getValue(Fast_Literal(result));

			/* Perform operation */
			db_binaryOperator(type, _this->operator, lptr, rptr, resultPtr);
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

/* virtual ::hyve::Fast::BinaryExpr::hasSideEffects() */
db_bool Fast_BinaryExpr_hasSideEffects(Fast_BinaryExpr _this) {
    static db_uint32 _methodId;
    db_method _method;
    db_bool _result;
    db_interface _abstract;

    _abstract = db_interface(db_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = db_interface_resolveMethodId(_abstract, "hasSideEffects()");
    }
    db_assert(_methodId, "virtual method 'hasSideEffects()' not found in abstract '%s'", db_nameof(_abstract));

    /* Lookup method-object. */
    _method = db_interface_resolveMethodById(_abstract, _methodId);
    db_assert(_method != NULL, "unresolved method '%s::hasSideEffects()@%d'", db_nameof(_this), _methodId);

    /* Call method directly if it's a C-function. */
    if (_method->_parent.kind == DB_PROCEDURE_CDECL) {
        db_assert(_method->_parent.impl, "missing implementation for '%s::hasSideEffects()'.", db_nameof(_this));
        _result = ((db_bool(*)(Fast_BinaryExpr))_method->_parent.impl)(_this);
    } else {
        /* Function is implemented in another language. */
        db_call(db_function(_method), &_result, _this);
    }
    
    return _result;
}

/* ::hyve::Fast::BinaryExpr::hasSideEffects() */
db_bool Fast_BinaryExpr_hasSideEffects_v(Fast_BinaryExpr _this) {
/* $begin(::hyve::Fast::BinaryExpr::hasSideEffects) */
    db_bool result = FALSE;
    
    switch(_this->operator) {
        case DB_ASSIGN:
        case DB_ASSIGN_ADD:
        case DB_ASSIGN_SUB:
        case DB_ASSIGN_DIV:
        case DB_ASSIGN_MUL:
        case DB_ASSIGN_MOD:
        case DB_ASSIGN_OR:
        case DB_ASSIGN_AND:
            result = TRUE;
            break;
        default:
            break;
    }
    
    return Fast_Expression_hasSideEffects(_this->lvalue) || Fast_Expression_hasSideEffects(_this->rvalue) || result;
/* $end */
}

/* ::hyve::Fast::BinaryExpr::setOperator(lang::operatorKind kind) */
db_void Fast_BinaryExpr_setOperator(Fast_BinaryExpr _this, db_operatorKind kind) {
/* $begin(::hyve::Fast::BinaryExpr::setOperator) */
	Fast_BinaryExpr compoundExpr = NULL;
    db_type exprType = NULL;

    exprType = Fast_Expression_getType_expr(_this->lvalue, _this->rvalue);

    /* Assign operator before cast - it can influence the type */
	_this->operator = kind;

	/* Apply casting on operands if necessary */
	if (exprType) {
		if (Fast_BinaryExpr_cast(_this, &exprType)) {
			goto error;
		}
	}

	/* Depending on the operator, the returnType might be a bool or the type of the lvalue */
	switch(_this->operator) {
	case DB_COND_EQ:
	case DB_COND_NEQ:
	case DB_COND_LT:
	case DB_COND_GT:
	case DB_COND_LTEQ:
	case DB_COND_GTEQ:
	case DB_COND_AND:
	case DB_COND_OR:
		db_set(&Fast_Expression(_this)->type, Fast_Variable(Fast_Object__create(db_bool_o)));
		break;
	default:
		db_set(&Fast_Expression(_this)->type, Fast_Variable(Fast_Object__create(exprType)));
		break;
	}

	/* If operator is a compound operator (assign_*), split up in two binary expressions */
	switch(_this->operator) {
	case DB_ASSIGN_ADD: compoundExpr = Fast_BinaryExpr__create(_this->lvalue, _this->rvalue, DB_ADD); break;
	case DB_ASSIGN_SUB: compoundExpr = Fast_BinaryExpr__create(_this->lvalue, _this->rvalue, DB_SUB); break;
	case DB_ASSIGN_DIV: compoundExpr = Fast_BinaryExpr__create(_this->lvalue, _this->rvalue, DB_DIV); break;
	case DB_ASSIGN_MUL: compoundExpr = Fast_BinaryExpr__create(_this->lvalue, _this->rvalue, DB_MUL); break;
	case DB_ASSIGN_MOD: compoundExpr = Fast_BinaryExpr__create(_this->lvalue, _this->rvalue, DB_MOD); break;
	case DB_ASSIGN_OR:  compoundExpr = Fast_BinaryExpr__create(_this->lvalue, _this->rvalue, DB_OR); break;
	case DB_ASSIGN_AND: compoundExpr = Fast_BinaryExpr__create(_this->lvalue, _this->rvalue, DB_AND); break;
		break;
	default:
		break;
	}

	if (compoundExpr) {
		_this->operator = DB_ASSIGN;
		db_set(&_this->rvalue, compoundExpr);
		Fast_Parser_collect(yparser(), compoundExpr);
	}

	return;
error:
	return;
/* $end */
}

/* virtual ::hyve::Fast::BinaryExpr::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_BinaryExpr_toIc(Fast_BinaryExpr _this, db_icProgram program, db_icStorage storage, db_bool stored) {
    static db_uint32 _methodId;
    db_method _method;
    db_ic _result;
    db_interface _abstract;

    _abstract = db_interface(db_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = db_interface_resolveMethodId(_abstract, "toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)");
    }
    db_assert(_methodId, "virtual method 'toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)' not found in abstract '%s'", db_nameof(_abstract));

    /* Lookup method-object. */
    _method = db_interface_resolveMethodById(_abstract, _methodId);
    db_assert(_method != NULL, "unresolved method '%s::toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)@%d'", db_nameof(_this), _methodId);

    /* Call method directly if it's a C-function. */
    if (_method->_parent.kind == DB_PROCEDURE_CDECL) {
        db_assert(_method->_parent.impl, "missing implementation for '%s::toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)'.", db_nameof(_this));
        _result = ((db_ic(*)(Fast_BinaryExpr, db_icProgram , db_icStorage , db_bool ))_method->_parent.impl)(_this, program, storage, stored);
    } else {
        /* Function is implemented in another language. */
        db_call(db_function(_method), &_result, _this, program, storage, stored);
    }
    
    return _result;
}

/* ::hyve::Fast::BinaryExpr::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_BinaryExpr_toIc_v(Fast_BinaryExpr _this, db_icProgram program, db_icStorage storage, db_bool stored) {
/* $begin(::hyve::Fast::BinaryExpr::toIc) */
	db_ic lvalue, rvalue, result, conditionLvalue, conditionRvalue = NULL;
	db_icOp op = NULL;
	db_type _thisType = Fast_Expression_getType(Fast_Expression(_this));
	db_bool condition = Fast_BinaryExpr_isConditional(_this);
	db_bool isReference = _this->lvalue->forceReference || _this->rvalue->forceReference;

	if (storage && (storage->type == _thisType)) {
		result = (db_ic)storage;
	} else {
		result = (db_ic)db_icProgram_accumulatorPush(program, Fast_Node(_this)->line, _thisType, isReference);
	}

	if (condition) {
		conditionLvalue = (db_ic)db_icProgram_accumulatorPush(program, Fast_Node(_this)->line, Fast_Expression_getType(_this->lvalue), _this->lvalue->isReference);
		conditionRvalue = (db_ic)db_icProgram_accumulatorPush(program, Fast_Node(_this)->line, Fast_Expression_getType(_this->rvalue), _this->rvalue->isReference);
	}

	/* Parse lvalue and rvalue */
	lvalue = Fast_Node_toIc(
			Fast_Node(_this->lvalue),
			program,
			condition ? (db_icStorage)conditionLvalue :  (db_icStorage)result,
			TRUE);

	/* If operator is assign, pass lvalue as storage */
	if (_this->operator == DB_ASSIGN) {
		rvalue = Fast_Node_toIc(Fast_Node(_this->rvalue), program, (db_icStorage)lvalue, TRUE);

		/* Add instruction to program if lvalue != rvalue */
		if (lvalue != rvalue) {
			op = db_icOp__create(program, Fast_Node(_this)->line, db_icOpKindFromOperator(DB_ASSIGN), stored ? (db_icValue)result : NULL, (db_icValue)lvalue, (db_icValue)rvalue);
			db_icProgram_addIc(program, (db_ic)op);

			op->s2Deref = Fast_Expression_getDerefMode(_this->lvalue, _this->rvalue, NULL);
			op->s3Deref = Fast_Expression_getDerefMode(_this->rvalue, _this->lvalue, NULL);
		}
	/* Only compile expression when there is a result - if it's not an assignment */
	} else if (stored && result) {
		rvalue = Fast_Node_toIc(Fast_Node(_this->rvalue), program, (db_icStorage)conditionRvalue, TRUE);

		/* If operation is a string, insert string-specific operations */
		if ((_thisType->kind == DB_PRIMITIVE) && (db_primitive(_thisType)->kind == DB_TEXT)) {
			Fast_BinaryExpr_toIc_strOp(_this, program, (db_icStorage)result, (db_icValue)lvalue, (db_icValue)rvalue);
		} else {
			/* Add instruction to program. */
			op = db_icOp__create(program, Fast_Node(_this)->line, db_icOpKindFromOperator(_this->operator), stored ? (db_icValue)result : NULL, (db_icValue)lvalue, (db_icValue)rvalue);
			db_icProgram_addIc(program, (db_ic)op);
		}

		if (op) {
			op->s2Deref = Fast_Expression_getDerefMode(_this->lvalue, _this->rvalue, NULL);
			op->s3Deref = Fast_Expression_getDerefMode(_this->rvalue, _this->lvalue, NULL);
		}
	} else {
		if (Fast_Expression_hasSideEffects(_this->rvalue)) {
			rvalue = Fast_Node_toIc(Fast_Node(_this->rvalue), program, (db_icStorage)conditionRvalue, FALSE);
		}
	}

	if (condition) {
		db_icProgram_accumulatorPop(program, Fast_Node(_this)->line);
		db_icProgram_accumulatorPop(program, Fast_Node(_this)->line);
	}

	if ((db_ic)storage != result) {
		db_icProgram_accumulatorPop(program, Fast_Node(_this)->line);
	}

	return result;
/* $end */
}
