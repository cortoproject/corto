/* Fast_String.c
 *
 *  Generated on Nov 18 2014
 *    This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "Fast_String.h"
#include "Fast__meta.h"


/* $header() */
#include "Fast.h"
#include "Fast_Parser.h"
#include "Fast__api.h"
Fast_Parser yparser(void);
void Fast_Parser_error(Fast_Parser _this, char* fmt, ...);

static char alphaMask[256];
static char numericMask[256];
static int maskSet = 0;

static void db_tokenMaskSet(db_bool *mask, db_string chars) {
    db_char *ptr, ch;
    memset(mask, FALSE, sizeof(db_bool) * 128);
    ptr = chars;
    while((ch = *ptr)) {
        mask[(int)ch] = TRUE;
        ptr++;
    }
}

/* Parse embedded expression */
db_char *Fast_String_parseEmbedded(Fast_String _this, db_char *expr) {
	db_char ch, *ptr;
	db_uint32 nesting;
	Fast_Expression element;
	db_bool bracketExpr = FALSE;

	if (!maskSet) {
		db_tokenMaskSet(alphaMask, ":abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_");
		db_tokenMaskSet(numericMask, "0123456789");
	}

	ptr = expr;
	if (*ptr == '{') {
		bracketExpr = TRUE;
		expr = ++ptr; /* Progress expression as well to skip the initial '{' */
		nesting = 1;
		while((ch = *ptr) && nesting) {
			switch(ch) {
			case '{':
				nesting++;
				break;
			case '}':
				nesting--;
				break;
			}
			ptr++;
		}
		ptr--; /* Skip the last '{' */
	} else {
		/* If character is not a '{' parse a variable-name which is
		 * delimited by a non-alphanumeric character. Additionally
		 * variable names cannot start with a number. */
		if (!alphaMask[(int)*ptr]) {
            yparser()->line = Fast_Node(_this)->line;
            yparser()->column = Fast_Node(_this)->column;
			Fast_Parser_error(yparser(), "invalid embedded expression at '%s'", expr);
			goto error;
		}
		ptr++;
		while((ch = *ptr) && (alphaMask[(int)ch] || numericMask[(int)ch])) {
			if (ch == ':') {
				ptr++;
				if (*ptr != ':') {
					ptr--;
					break;
				}
			}
			ptr++;
		}
	}

	ch = *ptr;
	*ptr = '\0';

	element = Fast_Parser_parseExpression(yparser(), expr, _this->block, _this->scope, Fast_Node(_this)->line, Fast_Node(_this)->column);
	if (element) {
		db_llAppend(_this->elements, element);
		db_keep(element);
	} else {
		goto error;
	}

	*ptr = ch;
	if (bracketExpr) {
		ptr++;
	}

	return ptr;
error:
	return NULL;
}

/* Walk embedded expressions in string */
db_int16 Fast_String_parse(Fast_String _this) {
	db_char *ptr, ch, *str;
	Fast_String element;

	ptr = _this->value;
	str = ptr; /* Keep track of beginning of string-element */
    
    if (ptr) {
        /* Walk string, split embedded expressions */
        while((ch = *ptr)) {
            switch(ch) {
            case '$':
                /* Insert string-element */
                if (str != ptr) {
                    *ptr = '\0';

                    element = Fast_String__create(str);
                    db_llAppend(_this->elements, element);

                    *ptr = ch;
                }

                /* Parse embedded expression */
                str = ptr = Fast_String_parseEmbedded(_this, ptr+1);
                if (!ptr) {
                    yparser()->line = Fast_Node(_this)->line;
                    yparser()->column = Fast_Node(_this)->column;
                    Fast_Parser_error(yparser(), "parsing string '%s' failed", _this->value);
                    goto error;
                }
                break;
            default:
                ptr++;
                break;
            }
        }

        /* If string contains embedded expressions, add last bit of remaining
         * string to elements list */
        if ((str != _this->value) && *str) {
            element = Fast_String__create(str);
            db_llAppend(_this->elements, element);
        }
    } else {
        element = Fast_String__create("null");
        db_llAppend(_this->elements, element);
    }

	return 0;
error:
	return -1;
}

/* $end */

/* callback ::hyve::lang::class::construct(lang::object object) -> ::hyve::Fast::String::construct(String object) */
db_int16 Fast_String_construct(Fast_String object) {
/* $begin(::hyve::Fast::String::construct) */
    
	if (!yparser()->block || !yparser()->scope) {
		goto error;
	}

	object->block = yparser()->block; db_keep_ext(object, object->block, "object->block (keep block for string-expression)");
	object->scope = yparser()->scope; db_keep_ext(object, object->scope, "object->scope (keep scope for string-expression)");
    
	return 0;
error:
	return -1;
/* $end */
}

/* ::hyve::Fast::String::getValue() */
db_word Fast_String_getValue(Fast_String _this) {
/* $begin(::hyve::Fast::String::getValue) */
	db_char *ptr, ch;
	db_word result;

    /* Determine whether string has embedded expressions */
	ptr = _this->value;
	while((ch = *ptr) && ch && (ch != '$')) {
		switch((db_uint8)ch) {
		case '\\':
			ptr++;
			break;
		}
		ptr++;
	}

	/* If string contains embedded expressions it does not have a compile-time
	 * defined value. */
	if (ch == '$') {
		result = 0;
	} else {
		result = (db_word)_this->value;
	}

	return result;
/* $end */
}

/* callback ::hyve::lang::type::init(lang::object object) -> ::hyve::Fast::String::init(String object) */
db_int16 Fast_String_init(Fast_String object) {
/* $begin(::hyve::Fast::String::init) */
    Fast_Literal(object)->kind = FAST_String;
    return Fast_Literal_init((Fast_Literal)object);
/* $end */
}

/* ::hyve::Fast::String::serialize(lang::type dstType,lang::word dst) */
db_int16 Fast_String_serialize(Fast_String _this, db_type dstType, db_word dst) {
/* $begin(::hyve::Fast::String::serialize) */
	Fast_valueKind kind;

	kind = Fast_valueKindFromType(dstType);

	switch(kind) {
	case FAST_Boolean:
	case FAST_Integer:
	case FAST_SignedInteger:
	case FAST_String:
		db_convert(db_primitive(db_string_o), &_this->value, db_primitive(dstType), (void*)dst);
		break;
    case FAST_Reference: {
        db_object o = db_resolve_ext(NULL, NULL, _this->value, FALSE, "Serialize reference from string");
		db_set_ext(NULL, &dst, o, "serialize string to reference");
		break;
    }
	default: {
        db_id id;
        Fast_Parser_error(yparser(), "cannot serialize string value to storage of type '%s'", db_fullname(dstType, id));
        goto error;
		break;
	}
	}

	return 0;
error:
    return -1;
/* $end */
}

/* virtual ::hyve::Fast::String::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_String_toIc(Fast_String _this, db_icProgram program, db_icStorage storage, db_bool stored) {
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
        _result = ((db_ic(*)(Fast_String, db_icProgram , db_icStorage , db_bool ))_method->_parent.impl)(_this, program, storage, stored);
    } else {
        /* Function is implemented in another language. */
        db_call(db_function(_method), &_result, _this, program, storage, stored);
    }
    
    return _result;
}

/* ::hyve::Fast::String::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_String_toIc_v(Fast_String _this, db_icProgram program, db_icStorage storage, db_bool stored) {
/* $begin(::hyve::Fast::String::toIc) */
	db_ic result = NULL;
	db_value v;
	DB_UNUSED(storage);
	DB_UNUSED(stored);

	/* Parse string after parsing script and thus not interfere with parser */
	if (Fast_String_parse(_this)) {
		goto error;
	}

	if (!db_llSize(_this->elements)) {
		db_valueLiteralInit(&v, DB_LITERAL_STRING, &_this->value);
		result = (db_ic)db_icLiteral__create(program, Fast_Node(_this)->line, v, db_type(db_string_o));
	} else {
		if (stored) {
			db_iter elementIter;
			Fast_Expression element;
			db_ic icElement1, icElement2;
			db_icOp op;
			db_uint32 elementCount = db_llSize(_this->elements);
			db_bool stored = FALSE;
			db_ic dummy;
			db_uint32 accPushCount = 0;
			db_type elementType;

			if (storage && (storage->type != db_type(db_string_o))) {
				Fast_Parser_error(yparser(),
						"storage for string-expression '%s' has invalid type (%s)",
						_this->value,
						db_nameof(storage->type));
				goto error;
			}

			v.is.value.storage = 0; /* Create NULL-string */
			db_valueLiteralInit(&v, DB_LITERAL_STRING, &v.is.value.storage);
			dummy = (db_ic)db_icLiteral__create(program, Fast_Node(_this)->line, v, db_type(db_string_o));

			result = (db_ic)storage;
			elementIter = db_llIter(_this->elements);
			while(db_iterHasNext(&elementIter)) {
				db_icAccumulator acc = db_icProgram_accumulatorPush(program, Fast_Node(_this)->line, (db_type)db_string_o, FALSE);
				accPushCount++;
				element = db_iterNext(&elementIter);

				elementType = Fast_Expression_getType(element);
				if (!elementType) {
					element = Fast_Expression(Fast_String__create(DB_NULL_STRING));
				} else if (elementType != db_type(db_string_o)) {
					element = Fast_Expression_cast(element, db_type(db_string_o));
					if(!element) {
						goto error;
					}
				}

				icElement1 = Fast_Node_toIc(Fast_Node(element), program, (db_icStorage)acc, TRUE);
				if (!icElement1) {
					goto error;
				}
				if (elementCount == 1) {
					if (storage) {
						op = db_icOp__create(program, Fast_Node(_this)->line, DB_IC_STRCPY, NULL, (db_icValue)storage, (db_icValue)icElement1);
						db_icProgram_addIc(program, (db_ic)op);
					} else {
						result = (db_ic)icElement1;
					}
					stored = TRUE;
				} else {
					if (elementCount) {
						if (db_iterHasNext(&elementIter)) {
							db_icAccumulator acc = db_icProgram_accumulatorPush(program, Fast_Node(_this)->line, (db_type)db_string_o, FALSE);
							accPushCount++;
							element = db_iterNext(&elementIter);
							elementType = Fast_Expression_getType(element);

							if (!elementType) {
								element = Fast_Expression(Fast_String__create(DB_NULL_STRING));
							} else if (elementType && (Fast_Expression_getType(element) != db_type(db_string_o))) {
								element = Fast_Expression_cast(element, db_type(db_string_o));
								if (!element) {
									goto error;
								}
							}

							icElement2 = Fast_Node_toIc(Fast_Node(element), program, (db_icStorage)acc, TRUE);
							if (!icElement2) {
								goto error;
							}
							op = db_icOp__create(program, Fast_Node(_this)->line, DB_IC_STRCAT, NULL, (db_icValue)icElement1, (db_icValue)icElement2);
							db_icProgram_addIc(program, (db_ic)op);
							elementCount--;
						}
					} else {
						op = db_icOp__create(program, Fast_Node(_this)->line, DB_IC_STRCAT, NULL, (db_icValue)icElement1, (db_icValue)dummy);
						db_icProgram_addIc(program, (db_ic)op);
					}
				}
				elementCount--;
			}

			/* If string is not yet copied, insert copy instruction */
			if (!stored) {
				op = db_icOp__create(program, Fast_Node(_this)->line, DB_IC_STRCPY, NULL, (db_icValue)storage, (db_icValue)dummy);
				db_icProgram_addIc(program, (db_ic)op);
				stored = TRUE;
			}

			while(accPushCount) {
				db_icProgram_accumulatorPop(program, Fast_Node(_this)->line);
				accPushCount--;
			}
		}
	}

	return result;
error:
	return NULL;
/* $end */
}
