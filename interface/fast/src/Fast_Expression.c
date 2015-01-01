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
Fast_Expression Fast_Parser_getAnonymousLocal(Fast_Parser _this, Fast_Variable type, db_bool isReference);

/* Rate types based on expressibility */
db_int8 Fast_Expression_getTypeScore(db_primitive t) {
	db_int8 result = 0;
	switch(t->kind) {
	case DB_BOOLEAN:
	case DB_BINARY:
	case DB_INTEGER:
	case DB_UINTEGER:
	case DB_ALIAS:
		result = 1;
		break;
	case DB_ENUM:
	case DB_BITMASK:
	case DB_CHARACTER:
		result = 2;
		break;
	case DB_FLOAT:
		result = 3;
		break;
	case DB_TEXT:
		result = 4;
		break;
	}
	return result;
}

/* Categorize types on castability - if equal no cast is required when width is equal */
db_int16 Fast_Expression_getCastScore(db_primitive t) {
	db_int8 result = 0;
	switch(t->kind) {
        case DB_BOOLEAN:
        case DB_BINARY:
        case DB_INTEGER:
        case DB_UINTEGER:
        case DB_ALIAS:
        case DB_ENUM:
        case DB_BITMASK:
        case DB_CHARACTER:
            result = 1;
            break;
        case DB_FLOAT:
            result = 2;
            break;
        case DB_TEXT:
            result = 3;
            break;
	}
	return result;
}

db_icDerefMode Fast_Expression_getDerefMode(Fast_Expression _this, Fast_Expression rvalue, db_int32 *check) {
	db_icDerefMode result = DB_IC_DEREF_VALUE;
    
	if (_this->forceReference) {
		result = DB_IC_DEREF_ADDRESS;
	} else {
		db_type t = Fast_Expression_getType(_this);
        
		if (rvalue->forceReference || (t && t->reference)) {
			if (Fast_Node(_this)->kind == FAST_Variable) {
                if (Fast_Variable(_this)->kind == FAST_Object) {
                    result = DB_IC_DEREF_ADDRESS;
                } else if ((Fast_Variable(_this)->kind == FAST_Local) && (*Fast_Local(_this)->name == '<') && Fast_Local(_this)->isReference) {
                    result = DB_IC_DEREF_ADDRESS; /* Anonymous locals are treated as objects */
                } else if (_this->isReference && !(t && t->reference)) {
                    result = DB_IC_DEREF_ADDRESS;
                } else {
                    if (check) *check = -1;
                }
            } else if (t && !t->reference) {
                if (check) *check = -1;
            }
		}
	}
    
    /*{
        db_id id,id2;
        db_type l = Fast_Expression_getType(_this);
        db_type r = Fast_Expression_getType(rvalue);
        printf("%d[pass=%d]: l->forceRef/isRef=%d/%d(%s,%s), r->forceRef/isRef=%d/%d(%s,%s), isValue=%d, check=%d\n",
           yparser()->line, yparser()->pass, _this->forceReference, _this->isReference, db_fullname(l,id),
           	   db_nameof(db_typeof(_this)),
               rvalue->forceReference, rvalue->isReference, db_fullname(r,id2), 
               db_nameof(db_typeof(rvalue)),
               result == DB_IC_DEREF_VALUE, check?*check:0);
    }*/
	return result;
}

/* $end */

/* ::cortex::Fast::Expression::cast(lang::type type) */
Fast_Expression Fast_Expression_cast(Fast_Expression _this, db_type type) {
/* $begin(::cortex::Fast::Expression::cast) */
	db_type exprType;
	Fast_Expression result = NULL;
	db_bool castRequired = TRUE;
    
    db_assert(type != NULL, "cannot cast to unknown type NULL");

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
        } else if (db_type_castable(type, exprType)) {
			void *value = NULL;
            void *valueAddr = NULL;

			/* If expression is a literal or constant create new literal of right type */
			value = (void*)Fast_Expression_getValue(_this);
            if (value && (exprType->kind == DB_PRIMITIVE) && (db_primitive(exprType)->kind == DB_TEXT)) {
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
						db_id id1, id2;
						/* Invalid cast */
						Fast_Parser_error(yparser(), "cannot cast from '%s' to '%s'", db_fullname(exprType, id1), db_fullname(type, id2));
						break;
					}
					}
				}

				/* Create literal expressions based on destination type */
				switch(db_primitive(type)->kind) {
				case DB_BOOLEAN: {
					db_bool dstValue = FALSE;
					db_convert(db_primitive(exprType), value, db_primitive(db_bool_o), &dstValue);
					result = Fast_Expression(Fast_Boolean__create(dstValue));
					break;
				}
				case DB_CHARACTER: {
					db_char dstValue;
					db_convert(db_primitive(exprType), value, db_primitive(db_char_o), &dstValue);
					result = Fast_Expression(Fast_Character__create(dstValue));
					break;
				}
                case DB_BINARY:
				case DB_UINTEGER: {
					db_uint64 dstValue;
					db_convert(db_primitive(exprType), value, db_primitive(db_uint64_o), &dstValue);
					result = Fast_Expression(Fast_Integer__create(dstValue));
					break;
				}
				case DB_INTEGER: {
					db_int64 dstValue;
					db_convert(db_primitive(exprType), value, db_primitive(db_int64_o), &dstValue);
					result = Fast_Expression(Fast_SignedInteger__create(dstValue));
					break;
				}
				case DB_FLOAT: {
					db_float64 dstValue;
					db_convert(db_primitive(exprType), value, db_primitive(db_float64_o), &dstValue);
					result = Fast_Expression(Fast_FloatingPoint__create(dstValue));
					break;
				}
				case DB_TEXT: {
					db_string dstValue;
					db_convert(db_primitive(exprType), value, db_primitive(db_string_o), &dstValue);
					result = Fast_Expression(Fast_String__create(dstValue));
					break;
				}
				case DB_ENUM:
				case DB_BITMASK: {
					db_int32 dstValue;
					db_convert(db_primitive(exprType), value, db_primitive(db_int32_o), &dstValue);
					result = Fast_Expression(Fast_SignedInteger__create(dstValue));
					break;
				}
				case DB_ALIAS: {
					db_int32 dstValue;
					db_convert(db_primitive(exprType), value, db_primitive(db_word_o), &dstValue);
					result = Fast_Expression(Fast_SignedInteger__create(dstValue));
					break;
				}
				}

				if (result){
					Fast_Variable typeVar = Fast_Variable(Fast_Object__create(type));
					db_set_ext(result, &Fast_Expression(result)->type, typeVar, "Set correct type after cast");
					db_free(typeVar);
				}
			} else {
                /* TODO: This functionality must be pushed down to the assembler. For all this function is concerned a cast
                 should only be required when a type is a) castable and b) not compatible. */
                db_int8 exprCastScore = Fast_Expression_getCastScore(db_primitive(exprType));
                db_int8 castCastScore = Fast_Expression_getCastScore(db_primitive(type));

				/* If both types are primitive make sure that no cast is inserted for primitives
				 * of the same kind or 'score' to the same width */
				if ((exprType->kind == DB_PRIMITIVE) &&
				   (type->kind == DB_PRIMITIVE) &&
				   (exprCastScore == castCastScore)) {
					if (db_primitive(exprType)->width != db_primitive(type)->width) {
						Fast_Object dstTypeObject = Fast_Object__create(type);
						result = Fast_Expression(Fast_CastExpr__create(Fast_Expression(dstTypeObject), _this));
						Fast_Parser_collect(yparser(), dstTypeObject);
					} else {
						/* Types have the same width, so no cast required */
						castRequired = FALSE;
					}

				/* Interface-downcasting doesn't require an explicit cast */
				} else if (!db_instanceof(db_typedef(db_interface_o), type)) {
					Fast_Object dstTypeObject = Fast_Object__create(type);
					result = Fast_Expression(Fast_CastExpr__create(Fast_Expression(dstTypeObject), _this));
					Fast_Parser_collect(yparser(), dstTypeObject);
				} else {
					castRequired = FALSE;
				}
			}
		/* If object is a reference and targetType is string, insert toString operation */
		} else /*if (_this->isReference || Fast_Expression_getType(_this)->reference)*/ {
			if ((type->kind == DB_PRIMITIVE) && (db_primitive(type)->kind == DB_TEXT)) {
				Fast_Expression member;
				Fast_String operation;

				/* Lookup insert or append */
				operation = Fast_String__create("toString");

				/* Create memberexpression */
				member = Fast_Expression(Fast_MemberExpr__create(_this, Fast_Expression(operation)));
				if (!member) {
					/* TODO: free resources */
					goto error;
				}

				/* Create call-expression */
				result = Fast_Expression(Fast_Call__create(member, NULL));

				/* Garbage collect objects */
				Fast_Parser_collect(yparser(), operation);
				Fast_Parser_collect(yparser(), member);

			/* If type is of a generic reference type, accept any reference without cast */
			} else if (type->kind == DB_VOID && type->reference) {
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
			db_id id1, id2;
				Fast_Parser_error(yparser(), "no conversion from '%s' to '%s'",
						db_fullname(exprType, id1),
						db_fullname(type, id2));
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
        db_iter iter = db_llIter(list);
        while(db_iterHasNext(&iter)) {
            db_free_ext(NULL, db_iterNext(&iter), "free expression from list");
        }
        db_llFree(list);
    }
/* $end */
}

/* ::cortex::Fast::Expression::fold() */
Fast_Expression Fast_Expression_fold_v(Fast_Expression _this) {
/* $begin(::cortex::Fast::Expression::fold) */
	DB_UNUSED(_this);
    return _this;
/* $end */
}

/* ::cortex::Fast::Expression::fromList(list{Expression} list) */
Fast_Expression Fast_Expression_fromList(Fast_Expression_list list) {
/* $begin(::cortex::Fast::Expression::fromList) */
    Fast_Expression result = NULL;

    /* Convert list to comma expression */
    if (list) {
        if (db_llSize(list) == 1) {
            result = db_llGet(list, 0);
        } else {
            db_ll toList = db_llNew(); /* Copy list */
            db_iter iter;
            Fast_Expression expr;
            
            result = Fast_Expression(Fast_CommaExpr__create());

            iter = db_llIter(list);
            while(db_iterHasNext(&iter)) {
                expr = db_iterNext(&iter);
                db_llAppend(toList, expr); db_keep_ext(result, expr, "add expression from list to comma-expression");
            }
            Fast_CommaExpr(result)->expressions = toList;
            Fast_Parser_collect(yparser(), result);
        }
    }
    
    return result;
/* $end */
}

/* ::cortex::Fast::Expression::getType() */
db_type Fast_Expression_getType(Fast_Expression _this) {
/* $begin(::cortex::Fast::Expression::getType) */
	db_type result = NULL;
	if (_this->type && (_this->type->kind == FAST_Object)) {
		result = Fast_ObjectBase(_this->type)->value;
	}
    return result;
/* $end */
}

/* ::cortex::Fast::Expression::getType_expr(Expression target) */
db_type Fast_Expression_getType_expr(Fast_Expression _this, Fast_Expression target) {
/* $begin(::cortex::Fast::Expression::getType_expr) */
	db_type type,result;

	result = Fast_Expression_getType(_this);
	type = Fast_Expression_getType(target);

	if (!result && target) {
		if (type) {
			result = Fast_Expression_getType_type(_this, type);
		} else {
			result = db_void_o;
		}
	} else {
		result = Fast_Expression_getType_type(_this, type);
	}

	return result;
/* $end */
}

/* ::cortex::Fast::Expression::getType_type(lang::type target) */
db_type Fast_Expression_getType_type(Fast_Expression _this, db_type target) {
/* $begin(::cortex::Fast::Expression::getType_type) */
	db_type result=Fast_Expression_getType(_this);

	if (!result) {
		if (Fast_Node(_this)->kind == FAST_Literal) {
			if (Fast_Literal(_this)->kind == FAST_Null) {
				if (target) {
					if (target->reference) {
						result = target;
					} else if ((target->kind == DB_PRIMITIVE) && (db_primitive(target)->kind == DB_TEXT)){
						result = db_type(db_string_o);
					} else {
						result = target;
					}
				}
			}
		}
	} else {
		if (!result->reference) {
			if (target && target->kind == DB_VOID) {
				if (_this->isReference) {
					result = db_object_o;
				}
			}
		}
	}

	return result;
/* $end */
}

/* ::cortex::Fast::Expression::getValue() */
db_word Fast_Expression_getValue_v(Fast_Expression _this) {
/* $begin(::cortex::Fast::Expression::getValue) */
	DB_UNUSED(_this);
    return 0;
/* $end */
}

/* ::cortex::Fast::Expression::hasSideEffects() */
db_bool Fast_Expression_hasSideEffects_v(Fast_Expression _this) {
/* $begin(::cortex::Fast::Expression::hasSideEffects) */
    DB_UNUSED(_this);
    return FALSE;
/* $end */
}

/* callback ::cortex::lang::type::init(lang::object object) -> ::cortex::Fast::Expression::init(Expression object) */
db_int16 Fast_Expression_init(Fast_Expression object) {
/* $begin(::cortex::Fast::Expression::init) */
    return Fast_Node_init((Fast_Node)object);
/* $end */
}

/* ::cortex::Fast::Expression::serialize(lang::type dstType,lang::word dst) */
db_int16 Fast_Expression_serialize_v(Fast_Expression _this, db_type dstType, db_word dst) {
/* $begin(::cortex::Fast::Expression::serialize) */
	DB_UNUSED(_this);
	DB_UNUSED(dstType);
	DB_UNUSED(dst);
	db_assert(0, "call to pure virtual function Fast::Expression::serialize");
	return 0;
/* $end */
}

/* ::cortex::Fast::Expression::toList() */
Fast_Expression_list Fast_Expression_toList_v(Fast_Expression _this) {
/* $begin(::cortex::Fast::Expression::toList) */
    Fast_Node_list result = NULL;
    
    if (_this) {
        result = db_llNew();
        db_llInsert(result, _this); db_keep_ext(NULL, _this, "convert single expression to list");
    }
    
    return result;
/* $end */
}
