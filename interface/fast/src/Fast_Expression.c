/* Fast_Expression.c
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
#include "Fast_InitializerExpr.h"
Fast_Parser yparser(void);
void Fast_Parser_error(Fast_Parser _this, char* fmt, ...);
Fast_Expression Fast_Parser_getAnonymousLocal(Fast_Parser _this, Fast_Variable type, cx_bool isReference);

/* Rate types based on expressibility */
cx_int8 Fast_Expression_getTypeScore(cx_primitive t) {
	cx_int8 result = 0;
	switch(t->kind) {
	case CX_BOOLEAN:
	case CX_BINARY:
	case CX_INTEGER:
	case CX_UINTEGER:
	case CX_ALIAS:
		result = 1;
		break;
	case CX_ENUM:
	case CX_BITMASK:
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

/* Categorize types on castability - if equal no cast is required when width is equal */
cx_int16 Fast_Expression_getCastScore(cx_primitive t) {
	cx_int8 result = 0;
	switch(t->kind) {
        case CX_BOOLEAN:
        case CX_BINARY:
        case CX_INTEGER:
        case CX_UINTEGER:
        case CX_ALIAS:
        case CX_ENUM:
        case CX_BITMASK:
        case CX_CHARACTER:
            result = 1;
            break;
        case CX_FLOAT:
            result = 2;
            break;
        case CX_TEXT:
            result = 3;
            break;
	}
	return result;
}

cx_icDerefMode Fast_Expression_getDerefMode(Fast_Expression _this, Fast_Expression rvalue, cx_int32 *check) {
	cx_icDerefMode result = CX_IC_DEREF_VALUE;
    
	if (_this->forceReference) {
		result = CX_IC_DEREF_ADDRESS;
	} else {
		cx_type t = Fast_Expression_getType(_this);
        
		if (rvalue->forceReference || (t && t->reference)) {
			if (Fast_Node(_this)->kind == FAST_Variable) {
                if (Fast_Variable(_this)->kind == FAST_Object) {
                    result = CX_IC_DEREF_ADDRESS;
                } else if ((Fast_Variable(_this)->kind == FAST_Local) && (*Fast_Local(_this)->name == '<') && Fast_Local(_this)->isReference) {
                    result = CX_IC_DEREF_ADDRESS; /* Anonymous locals are treated as objects */
                } else if (_this->isReference && !(t && t->reference)) {
                    result = CX_IC_DEREF_ADDRESS;
                } else {
                    if (check) *check = -1;
                }
            } else if (t && !t->reference) {
                if (check) *check = -1;
            }
		}
	}
    
    /*{
        cx_id id,id2;
        cx_type l = Fast_Expression_getType(_this);
        cx_type r = Fast_Expression_getType(rvalue);
        printf("%d[pass=%d]: l->forceRef/isRef=%d/%d(%s,%s), r->forceRef/isRef=%d/%d(%s,%s), isValue=%d, check=%d\n",
           yparser()->line, yparser()->pass, _this->forceReference, _this->isReference, cx_fullname(l,id),
           	   cx_nameof(cx_typeof(_this)),
               rvalue->forceReference, rvalue->isReference, cx_fullname(r,id2), 
               cx_nameof(cx_typeof(rvalue)),
               result == CX_IC_DEREF_VALUE, check?*check:0);
    }*/
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
    if (Fast_Node(expr)->kind == FAST_Literal) {
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

    if (Fast_Node(expr)->kind == FAST_Literal) {
        if (!target) {
            target = Fast_Expression_narrowType(expr);
        }
        cx_type t = Fast_Expression_getType_type(expr, target);
        if (target && (t != target) &&
           (target->kind == CX_PRIMITIVE) &&
           (cx_primitive(target)->kind == cx_primitive(t)->kind)) {
            cx_width width = cx_primitive(target)->width;
            Fast_Variable targetVar = Fast_Variable(Fast_Object__create(target));
            Fast_Parser_collect(yparser(), targetVar);

            if (t->kind == CX_PRIMITIVE) {
                switch(cx_primitive(t)->kind) {
                case CX_INTEGER: {
                    cx_int64 v = *(cx_int64*)Fast_Expression_getValue(expr);
                    switch(width) {
                    case CX_WIDTH_8:
                        if ((v <= 127) && (v >= -128)) {
                            cx_set(&expr->type, targetVar);
                        }
                        break;
                    case CX_WIDTH_16:
                        if ((v <= 32767) && (v >= -32768)) {
                            cx_set(&expr->type, targetVar);
                        }
                        break;
                    case CX_WIDTH_32:
                        if ((v <= 2147483647) && (v >= -2147483648)) {
                            cx_set(&expr->type, targetVar);
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
                            cx_set(&expr->type, targetVar);
                        }
                        break;
                    case CX_WIDTH_16:
                        if (v <= 65535) {
                            cx_set(&expr->type, targetVar);
                        }
                        break;
                    case CX_WIDTH_32:
                        if (v <= 4294967295) {
                            cx_set(&expr->type, targetVar);
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

/* ::cortex::Fast::Expression::cast(lang::type type) */
Fast_Expression Fast_Expression_cast(Fast_Expression _this, cx_type type) {
/* $begin(::cortex::Fast::Expression::cast) */
	cx_type exprType;
	Fast_Expression result = NULL;
	cx_bool castRequired = TRUE;
    
    cx_assert(type != NULL, "cannot cast to unknown type NULL");

	exprType = Fast_Expression_getType(_this);

	/* If types are different, cast */
	if (exprType != type) {
        
		if (!exprType) {
			/* If expression is an untyped initializer, create an anonymous variable of the destination type 
			 * and assign it to the initializer. */
			if(Fast_Node(_this)->kind == FAST_Initializer) {
				Fast_Variable typeVar = Fast_Variable(Fast_Object__create(type));
				Fast_Expression local = Fast_Parser_getAnonymousLocal(yparser(), typeVar, FALSE);
				Fast_InitializerExpr_insert(Fast_InitializerExpr(_this), local);
				Fast_Parser_collect(yparser(), typeVar);
				result = local;
	        	castRequired = TRUE;
			}else {
				castRequired = FALSE;
			}
        } else if (cx_type_castable(type, exprType)) {
			void *value = NULL;
            void *valueAddr = NULL;

			/* If expression is a literal or constant create new literal of right type */
			value = (void*)Fast_Expression_getValue(_this);
            if (value && (exprType->kind == CX_PRIMITIVE) && (cx_primitive(exprType)->kind == CX_TEXT)) {
                valueAddr = value;
                value = &valueAddr;
            }
			if (value) {
				if (type->reference && (Fast_Node(_this)->kind == FAST_Literal)) {
					/* If destination type is a reference and the literal is a string this results
					 * in a resolve at run-time. */
					switch(Fast_Literal(_this)->kind) {
					case FAST_String:
						break;
					case FAST_Null:
						/* No cast required */
						break;
					default: {
						cx_id id1, id2;
						/* Invalid cast */
						Fast_Parser_error(yparser(), "cannot cast from '%s' to '%s'", cx_fullname(exprType, id1), cx_fullname(type, id2));
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
					Fast_Variable typeVar = Fast_Variable(Fast_Object__create(type));
					cx_set_ext(result, &Fast_Expression(result)->type, typeVar, "Set correct type after cast");
					cx_free(typeVar);
				}
			} else {
                /* TODO: This functionality must be pushed down to the assembler. For all this function is concerned a cast
                 should only be required when a type is a) castable and b) not compatible. */
                cx_int8 exprCastScore = Fast_Expression_getCastScore(cx_primitive(exprType));
                cx_int8 castCastScore = Fast_Expression_getCastScore(cx_primitive(type));

				/* If both types are primitive make sure that no cast is inserted for primitives
				 * of the same kind or 'score' to the same width */
				if ((exprType->kind == CX_PRIMITIVE) &&
				   (type->kind == CX_PRIMITIVE) &&
				   (exprCastScore == castCastScore)) {
					if (cx_primitive(exprType)->width != cx_primitive(type)->width) {
						Fast_Object dstTypeObject = Fast_Object__create(type);
						result = Fast_Expression(Fast_CastExpr__create(Fast_Expression(dstTypeObject), _this));
						Fast_Parser_collect(yparser(), dstTypeObject);
					} else {
						/* Types have the same width, so no cast required */
						castRequired = FALSE;
					}

				/* Interface-downcasting doesn't require an explicit cast */
				} else if (!cx_instanceof(cx_typedef(cx_interface_o), type)) {
					Fast_Object dstTypeObject = Fast_Object__create(type);
					result = Fast_Expression(Fast_CastExpr__create(Fast_Expression(dstTypeObject), _this));
					Fast_Parser_collect(yparser(), dstTypeObject);
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
						cx_fullname(exprType, id1),
						cx_fullname(type, id2));
		}
	}

	return result;
error:
	return NULL;
/* $end */
}

/* ::cortex::Fast::Expression::cleanList(list{Expression} list) */
void Fast_Expression_cleanList(Fast_Expression_list list) {
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
            
            result = Fast_Expression(Fast_CommaExpr__create());

            iter = cx_llIter(list);
            while(cx_iterHasNext(&iter)) {
                expr = cx_iterNext(&iter);
                cx_llAppend(toList, expr); cx_keep_ext(result, expr, "add expression from list to comma-expression");
            }
            Fast_CommaExpr(result)->expressions = toList;
            Fast_Parser_collect(yparser(), result);
        }
    }
    
    return result;
/* $end */
}

/* ::cortex::Fast::Expression::getType() */
cx_type Fast_Expression_getType(Fast_Expression _this) {
/* $begin(::cortex::Fast::Expression::getType) */
	cx_type result = NULL;
	if (_this->type && (_this->type->kind == FAST_Object)) {
		result = Fast_ObjectBase(_this->type)->value;
	}
    return result;
/* $end */
}

/* ::cortex::Fast::Expression::getType_expr(Expression target) */
cx_type Fast_Expression_getType_expr(Fast_Expression _this, Fast_Expression target) {
/* $begin(::cortex::Fast::Expression::getType_expr) */
	cx_type type,result;

	result = Fast_Expression_getType(_this);
	type = Fast_Expression_getType(target);

	if (!result && target) {
		if (type) {
			result = Fast_Expression_getType_type(_this, type);
		} else {
			result = cx_void_o;
		}
	} else {
		result = Fast_Expression_getType_type(_this, type);
	}

	return result;
/* $end */
}

/* ::cortex::Fast::Expression::getType_type(lang::type target) */
cx_type Fast_Expression_getType_type(Fast_Expression _this, cx_type target) {
/* $begin(::cortex::Fast::Expression::getType_type) */
	cx_type result=Fast_Expression_getType(_this);

	if (!result) {
		if (Fast_Node(_this)->kind == FAST_Literal) {
			if (Fast_Literal(_this)->kind == FAST_Null) {
				if (target) {
					if (target->reference) {
						result = target;
					} else if ((target->kind == CX_PRIMITIVE) && (cx_primitive(target)->kind == CX_TEXT)){
						result = cx_type(cx_string_o);
					} else {
						result = target;
					}
				}
			}
		}
	} else {
		if (!result->reference) {
			if (target && target->kind == CX_VOID) {
				if (_this->isReference) {
					result = cx_object_o;
				}
			}
		}
	}

	return result;
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

/* callback ::cortex::lang::type::init(lang::object object) -> ::cortex::Fast::Expression::init(Expression object) */
cx_int16 Fast_Expression_init(Fast_Expression object) {
/* $begin(::cortex::Fast::Expression::init) */
    return Fast_Node_init((Fast_Node)object);
/* $end */
}

/* ::cortex::Fast::Expression::serialize(lang::type dstType,lang::word dst) */
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
