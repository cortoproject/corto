/*
 * db_expr.c
 *
 *  Created on: Aug 7, 2013
 *      Author: sander
 */

/* Fractal expressions provide a dynamic framework for querying, manipulating and calculating values from the object store.
 * The hyve expression interpreter has support for resolving objects\members\elements, invoke functions\methods and operator evaluation.
 * The output of an expression is a db_value which makes expressions compatible with the serialization framework. In other words, the
 * result of an expression can be run through a serializer, making it a very powerful tool for data manipulation and visualization.
 *
 * The hyve expression syntax is a subset of the hyve language.
 *
 * The implementation does not use yacc\flex\other parser frameworks because of performance reasons. The complexity of the expression syntax
 * allows for a handwritten parser.
 */

#include "db__meta.h"
#include "db_object.h"
#include "db_util.h"
#include "db_err.h"
#include "db_mem.h"
#include "db_operator.h"
#include "db_convert.h"
#include "db_interface.h"
#include "db_type.h"
#include "db_call.h"
#include "alloca.h"
#include "inttypes.h"

#include "string.h"
#include "stdlib.h"
#include "stdarg.h"

typedef enum db_exprTokenKind {
    DB_TOKEN_BOOLEAN,
    DB_TOKEN_CHARACTER,
    DB_TOKEN_INTEGER,
    DB_TOKEN_UNSIGNED_INTEGER,
    DB_TOKEN_FLOATING_POINT,
    DB_TOKEN_STRING,
    DB_TOKEN_NULL,
    DB_TOKEN_OPERATOR,
    DB_TOKEN_IDENTIFIER,
}db_exprTokenKind;

typedef union db_exprValue {
    db_bool _boolean;
    db_char _character;
    db_uint64 _integer;
    db_int64 _unsigned_integer;
    db_float64 _floating_point;
    db_string _string;
    db_operatorKind _operator;
    db_string _identifier;
}db_exprValue;

typedef struct db_exprToken {
    db_exprTokenKind kind;
    db_exprValue value;
}db_exprToken;

typedef struct db_exprContext {
    db_object scope;
    db_string expr;
    db_value *valueStack;
    db_uint32 valueCount;
    db_exprToken tokenStack[1024];
    db_uint32 tokenCount;
    db_operatorKind precedence;
    db_ll participants;
}db_exprContext;

typedef struct db_exprTokenClass {
    db_bool identifier[128]; /* Characters that identify a token */
    db_bool valid[128]; /* Characters that are valid for a token */
    db_string(*tokenize)(db_string expr, db_exprToken *token_out, db_bool *matched, db_exprContext *context);
}db_exprTokenClass;

/* Token classes must be evaluated in this order: */
static db_exprTokenClass db_tokenFloatingPoint;
static db_exprTokenClass db_tokenInteger;
static db_exprTokenClass db_tokenString;
static db_exprTokenClass db_tokenOperator;
static db_exprTokenClass db_tokenIdentifier;
static db_exprTokenClass *db_tokenClasses[] = {&db_tokenFloatingPoint, &db_tokenInteger, &db_tokenString, &db_tokenOperator, &db_tokenIdentifier};
static db_bool db_tokenClassesInitialized = FALSE;
#define DB_TOKEN_CLASS_COUNT (5)

static db_uint8 db_operatorPrecedence[DB_BRACKET_CLOSE+1];

static db_string db_tokenizeFloatingPoint(db_string expr, db_exprToken *token_out, db_bool *matched, db_exprContext *context);
static db_string db_tokenizeInteger(db_string expr, db_exprToken *token_out, db_bool *matched, db_exprContext *context);
static db_string db_tokenizeString(db_string expr, db_exprToken *token_out, db_bool *matched, db_exprContext *context);
static db_string db_tokenizeOperator(db_string expr, db_exprToken *token_out, db_bool *matched, db_exprContext *context);
static db_string db_tokenizeIdentifier(db_string expr, db_exprToken *token_out, db_bool *matched, db_exprContext *context);
static db_string db_exprExprRecur(db_string expr, db_bool singleExpression, db_value *result, db_exprContext *context);
static db_string db_exprPrimaryExpr(db_string expr, db_exprToken *lvalue, db_value *result, db_exprContext *context);

static void db_exprTokenFree(db_exprToken *token) {
    switch(token->kind) {
    case DB_TOKEN_STRING:
        db_dealloc(token->value._string);
        break;
    case DB_TOKEN_IDENTIFIER:
        db_dealloc(token->value._identifier);
        break;
    default:
        break;
    }
}

static void db_tokenMaskSet(db_bool *mask, db_string chars) {
    db_char *ptr, ch;
    memset(mask, FALSE, sizeof(db_bool) * 128);
    ptr = chars;
    while((ch = *ptr)) {
        mask[(int)ch] = TRUE;
        ptr++;
    }
}

static void db_tokenClassInitialize(db_exprTokenClass *class, db_string identifiers, db_string valids, db_string(*tokenize)(db_string,db_exprToken*,db_bool*,db_exprContext*)) {
    /* Set masks */
    db_tokenMaskSet(class->identifier, identifiers);
    db_tokenMaskSet(class->valid, valids);
    class->tokenize = tokenize;
}

/* Initialize token-classes */
static void db_tokenClassesInitialize(void) {
    db_tokenClassInitialize(&db_tokenFloatingPoint, "0123456789", "0123456789.", db_tokenizeFloatingPoint);
    db_tokenClassInitialize(&db_tokenInteger, "0123456789", "0123456789", db_tokenizeInteger);
    db_tokenClassInitialize(&db_tokenString, "\"", "", db_tokenizeString);
    db_tokenClassInitialize(&db_tokenOperator, "+-*/%~&|!<>=.[](),", "+-<>=&|.", db_tokenizeOperator);
    db_tokenClassInitialize(&db_tokenIdentifier, ":abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_", ":abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_1234567890{}", db_tokenizeIdentifier);
    db_tokenClassesInitialized=TRUE;
}

/* Initialize operator precedence */
static void db_operatorPrecedenceInitialize(void) {
	/* postfix expression */
	db_operatorPrecedence[DB_INC] = 0;
	db_operatorPrecedence[DB_DEC] = 0;
	db_operatorPrecedence[DB_MEMBER_RESOLVE] = 0;
	db_operatorPrecedence[DB_ELEMENT_OPEN] = 0;
	db_operatorPrecedence[DB_ELEMENT_CLOSE] = 0;
	db_operatorPrecedence[DB_BRACKET_OPEN] = 0;
	db_operatorPrecedence[DB_BRACKET_CLOSE] = 0;

	/* unary expression */
	db_operatorPrecedence[DB_NOT] = 1;
	db_operatorPrecedence[DB_COND_NOT] = 1;

	/* multiplicative expression */
	db_operatorPrecedence[DB_MUL] = 2;
	db_operatorPrecedence[DB_DIV] = 2;
	db_operatorPrecedence[DB_MOD] = 2;

	/* additive expression */
	db_operatorPrecedence[DB_ADD] = 3;
	db_operatorPrecedence[DB_SUB] = 3;

	/* shift expression */
	db_operatorPrecedence[DB_SHIFT_LEFT] = 4;
	db_operatorPrecedence[DB_SHIFT_RIGHT] = 4;

	/* boolean expression */
	db_operatorPrecedence[DB_COND_GT] = 5;
	db_operatorPrecedence[DB_COND_LT] = 5;
	db_operatorPrecedence[DB_COND_GTEQ] = 5;
	db_operatorPrecedence[DB_COND_LTEQ] = 5;

	/* equality expression */
	db_operatorPrecedence[DB_COND_EQ] = 5;
	db_operatorPrecedence[DB_COND_NEQ] = 5;

	/* bitwise ops */
	db_operatorPrecedence[DB_AND] = 6;
	db_operatorPrecedence[DB_XOR] = 7;
	db_operatorPrecedence[DB_OR] = 8;

	/* conditional and & or */
	db_operatorPrecedence[DB_COND_AND] = 9;
	db_operatorPrecedence[DB_COND_OR] = 10;

	/* assignments */
	db_operatorPrecedence[DB_ASSIGN] = 11;
	db_operatorPrecedence[DB_ASSIGN_ADD] = 11;
	db_operatorPrecedence[DB_ASSIGN_SUB] = 11;
	db_operatorPrecedence[DB_ASSIGN_MUL] = 11;
	db_operatorPrecedence[DB_ASSIGN_DIV] = 11;
	db_operatorPrecedence[DB_ASSIGN_MOD] = 11;
	db_operatorPrecedence[DB_ASSIGN_XOR] = 11;
	db_operatorPrecedence[DB_ASSIGN_OR] = 11;
	db_operatorPrecedence[DB_ASSIGN_AND] = 11;

	/* comma */
	db_operatorPrecedence[DB_COMMA] = 12;
}

static void db_exprerr(db_exprContext *context, db_char *ptr, db_string fmt, ...) {
    db_char head[1024];
    db_char msg[1024];
    va_list arglist;

    sprintf(head, "'%s':%" PRIuPTR ": ", context->expr, ptr - context->expr);

    va_start(arglist, fmt);
    vsprintf(msg, fmt, arglist);
    va_end(arglist);

    db_error("%s%s", head, msg);
}

static db_string db_skipWhitespace(db_string expr) {
    db_char *ptr, *result = NULL, ch;
    ptr = expr;
    do {
    	ch = *ptr;
        switch(ch) {
        case ' ':
        case '\t':
        case '\n':
            ptr++;
            break;
        default:
            result = ptr;
            break;
        }
    }while(!result && ch);

    return result;
}

static db_string db_tokenizeScanNested(db_string str, db_char open) {
    db_char close;
    db_char *ptr, ch;

    switch(open) {
    case '{':
        close = '}';
        break;
    case '(':
        close = ')';
        break;
    case '[':
        close = ']';
        break;
    default:
    	db_error("invalid opening character '%c'", open);
    	goto error;
        break;
    }

    ptr = str;
    while((ch = *ptr) && (ch != close)) {
        ptr++;
        switch(ch) {
        case '{':
        case '(':
        case '[':
            ptr = db_tokenizeScanNested(ptr, ch);
            break;
        }
    }

    return ptr;
error:
	return NULL;
}

static db_string db_tokenizeScan(db_exprTokenClass *class, db_string expr) {
    db_char *ptr, ch;

    /* First character is identifier, and already matched */
    ptr = expr+1;
    while((ch = *ptr)) {
        if (class->valid[(int)ch]) {
            ptr++;
            switch(ch) {
            case '{':
            case '(':
            case '[':
                ptr = db_tokenizeScanNested(ptr, ch);
                break;
            default:
                break;
            }
        } else {
            break;
        }
    }
    return ptr;
}

static db_string db_tokenizeFloatingPoint(db_string expr, db_exprToken *token_out, db_bool *matched, db_exprContext *context) {
    db_char *ptr, *validate, ch;
    DB_UNUSED(context);

    ptr = db_tokenizeScan(&db_tokenFloatingPoint, expr);

    /* Validate if parsed string is indeed a floating-point value */
    validate = expr;
    while((ch = *validate) && (validate < ptr)) {
        if (ch == '.') break;
        validate++;
    }

    if (validate == ptr) {
        goto nofloat;
    }

    token_out->kind = DB_TOKEN_FLOATING_POINT;
    token_out->value._floating_point = atof(expr);

    *matched = TRUE;
    return ptr;
nofloat:
    *matched = FALSE;
    return expr;
}

static db_string db_tokenizeInteger(db_string expr, db_exprToken *token_out, db_bool *matched, db_exprContext *context) {
    db_char *ptr;
    DB_UNUSED(context);

    ptr = db_tokenizeScan(&db_tokenInteger, expr);
    token_out->kind = DB_TOKEN_INTEGER;
    token_out->value._integer = atoi(expr);
    *matched = TRUE;
    return ptr;
}

static db_string db_tokenizeString(db_string expr, db_exprToken *token_out, db_bool *matched, db_exprContext *context) {
    char *yptr, *ptr, ch;
    db_char str_out[DB_MAX_STRING_LITERAL_LENGTH]; /* Can allocate sizable amount of space on stack. Safe because function is not recursive. */
    DB_UNUSED(context);

    *matched = TRUE;

    /* Do escape sequences */
    ptr = str_out;
    yptr = expr + 1; /* skip " */
    while((ch = *yptr) && (ch != '"')) {
        switch(ch) {
        case '\\':
            yptr++; ch = *yptr;
            switch(ch) {
            case 'a':
                *ptr = '\a';
                break;
            case 'b':
                *ptr = '\b';
                break;
            case 'f':
                *ptr = '\f';
                break;
            case 'n':
                *ptr = '\n';
                break;
            case 'r':
                *ptr = '\r';
                break;
            case 't':
                *ptr = '\t';
                break;
            case 'v':
                *ptr = '\v';
                break;
            case '\'':
                *ptr = '\'';
                break;
            case '"':
                *ptr = '"';
                break;
            case '\\':
                *ptr = '\\';
                break;
            case '?':
                *ptr = '?';
                break;
            default:
                db_exprerr(context, yptr, "invalid escape sequence '%c'",  ch);
                goto error;
                break;
            }
            ptr++;
            break;
        case '"':
            break;
        default:
            *ptr = ch;
            ptr++;
            break;
        }
        yptr++;
    }
    *ptr = '\0';

    token_out->kind = DB_TOKEN_STRING;
    token_out->value._string = db_strdup(str_out);

    return yptr+1;
error:
    return NULL;
}

static db_string db_tokenizeOperator(db_string expr, db_exprToken *token_out, db_bool *matched, db_exprContext *context) {
    *matched = TRUE;
    token_out->kind = DB_TOKEN_OPERATOR;

	switch(*expr) {
	case '=':
		switch(*(expr+1)) {
		case '=': token_out->value._operator = DB_COND_EQ; expr++; break;
		default: token_out->value._operator = DB_ASSIGN; break;
		}break;
	case '+':
		switch(*(expr+1)) {
		case '=': token_out->value._operator = DB_ASSIGN_ADD; expr++; break;
		case '+': token_out->value._operator = DB_INC; expr++; break;
		default: token_out->value._operator = DB_ADD; break;
		}break;
	case '-':
		switch(*(expr+1)) {
		case '=': token_out->value._operator = DB_ASSIGN_SUB; expr++; break;
		case '-': token_out->value._operator = DB_DEC; expr++; break;
		default: token_out->value._operator = DB_SUB; break;
		}break;
	case '*':
		switch(*(expr+1)) {
		case '=': token_out->value._operator = DB_ASSIGN_MUL; expr++; break;
		default: token_out->value._operator = DB_MUL; break;
		}break;
	case '/':
		switch(*(expr+1)) {
		case '=': token_out->value._operator = DB_ASSIGN_DIV; expr++; break;
		default: token_out->value._operator = DB_DIV; break;
		}break;
	case '%':
		switch(*(expr+1)) {
		case '=': token_out->value._operator = DB_ASSIGN_MOD; expr++; break;
		default: token_out->value._operator = DB_MOD; break;
		}break;
	case '~': token_out->value._operator = DB_NOT; break;
	case '^':
		switch(*(expr+1)) {
		case '=': token_out->value._operator = DB_ASSIGN_XOR; expr++; break;
		default: token_out->value._operator = DB_XOR; break;
		}break;
	case '&':
		switch(*(expr+1)) {
		case '=': token_out->value._operator = DB_ASSIGN_AND; expr++; break;
		case '&': token_out->value._operator = DB_COND_AND; expr++; break;
		default: token_out->value._operator = DB_AND; break;
		}break;
	case '|':
		switch(*(expr+1)) {
		case '=': token_out->value._operator = DB_ASSIGN_OR; expr++; break;
		case '|': token_out->value._operator = DB_COND_OR; expr++; break;
		default: token_out->value._operator = DB_OR; break;
		}break;
	case '<':
		switch(*(expr+1)) {
		case '=': token_out->value._operator = DB_COND_LTEQ; expr++; break;
		case '<': token_out->value._operator = DB_SHIFT_LEFT; expr++; break;
		default: token_out->value._operator = DB_COND_LT; break;
		}break;
	case '>':
		switch(*(expr+1)) {
		case '=': token_out->value._operator = DB_COND_GTEQ; expr++; break;
		case '>': token_out->value._operator = DB_SHIFT_RIGHT; expr++; break;
		default: token_out->value._operator = DB_COND_GT; break;
		}break;
	case '!':
		switch(*(expr+1)) {
		case '=': token_out->value._operator = DB_COND_NEQ; expr++; break;
		default: token_out->value._operator = DB_COND_NOT; break;
		}break;
	case '.': token_out->value._operator = DB_MEMBER_RESOLVE; break;
	case '[': token_out->value._operator = DB_ELEMENT_OPEN; break;
	case ']': token_out->value._operator = DB_ELEMENT_CLOSE; break;
	case '(': token_out->value._operator = DB_BRACKET_OPEN; break;
	case ')': token_out->value._operator = DB_BRACKET_CLOSE; break;
	case ',': token_out->value._operator = DB_COMMA; break;
	default:
		db_exprerr(context, expr, "invalid operator");
		goto error;
		break;
	}

	expr++;

    return expr;
error:
    return NULL;
}

static db_string db_tokenizeIdentifier(db_string expr, db_exprToken *token_out, db_bool *matched, db_exprContext *context) {
    db_char *ptr;
    db_uint32 length;

    DB_UNUSED(context);

    ptr = db_tokenizeScan(&db_tokenIdentifier, expr);
    length = ptr - expr;

    *matched = TRUE;

    /* Check for true & false, which are the only keywords */
    if (!strncmp(expr, "true", length)) {
        token_out->kind = DB_TOKEN_BOOLEAN;
        token_out->value._boolean = TRUE;
    } else if (!strncmp(expr, "false", length)) {
        token_out->kind = DB_TOKEN_BOOLEAN;
        token_out->value._boolean = FALSE;
    } else {
        db_id id;
        strncpy(id, expr, ptr - expr);
        id[ptr-expr] = '\0';
        token_out->kind = DB_TOKEN_IDENTIFIER;
        token_out->value._identifier = db_strdup(id);
    }

    return ptr;
}

static db_string db_tokenize(db_string expr, db_exprToken *token_out, db_exprContext *context) {
    db_char *ptr;
    db_bool matched = FALSE;
    db_uint32 i;

    ptr = expr = db_skipWhitespace(expr);

    /* Loop token classes, find one that matches */
    if (*expr) {
        for(i=0; i<DB_TOKEN_CLASS_COUNT; i++) {
            if (db_tokenClasses[i]->identifier[(int)*expr]) {
                ptr = db_tokenClasses[i]->tokenize(expr, token_out, &matched, context);
                if (matched) {
                    break;
                }
            }
        }

        if (!matched) {
            db_exprerr(context, expr, "unknown token");
            goto error;
        }
    }

    ptr = db_skipWhitespace(ptr);

    return ptr;
error:
    return NULL;
}

/* Member expression */
static db_string db_exprMemberExpr(db_string expr, db_exprContext *context) {
    db_char *ptr = expr;
    db_exprToken rvalue;
    db_value *lvalue = &context->valueStack[context->valueCount-1];
    db_type type = db_valueType(lvalue)->real;

    /* Members can only be resolved on composite objects */
    if (type->kind == DB_COMPOSITE) {
        ptr = db_tokenize(ptr, &rvalue, context);
        if (ptr) {
            if (rvalue.kind == DB_TOKEN_IDENTIFIER) {
                /* The super-keyword is used to move up the inheritance hierarchy */
                if (!strcmp(rvalue.value._identifier, "super")) {
                    if (db_interface(type)->base) {
                        db_value *base = &context->valueStack[context->valueCount];
                        context->valueCount++;

                        /* Push object again to stack, indicating that value is moving up the inheritance hierarchy */
                        base->kind = DB_OBJECT;
                        base->is.o = lvalue->is.o;
                        base->parent = lvalue;
                    } else {
                        db_id id;
                        db_exprerr(context, expr, "interface type '%s' has no base", db_fullname(type, id));
                        goto error;
                    }
                /* Resolve member */
                } else {
                    db_member m;
                    m = db_interface_resolveMember(db_interface(type), rvalue.value._identifier);
                    if (m) {
                        db_value *member = &context->valueStack[context->valueCount];
                        db_valueMemberInit(member, db_valueObject(lvalue), m, DB_OFFSET(db_valueValue(lvalue), m->offset));
                        member->parent = &context->valueStack[context->valueCount-1];
                        context->valueCount++;
                    } else {
                    	/* Look for method */
                    	db_function m;
                    	m = db_type_resolveProcedure(type, rvalue.value._identifier);
                    	if (m) {
                    		db_value *method = &context->valueStack[context->valueCount];
                    		method->parent = &context->valueStack[context->valueCount-1];
                            db_valueCallInit(method, db_valueObject(lvalue), db_function(m));
                            context->valueCount++;
                    	} else {
							db_id id;
							db_exprerr(context, expr, "unresolved member '%s' for type '%s'", rvalue.value._identifier, db_fullname(type, id));
							goto error;
                    	}
                    }
                }
            } else {
                db_exprerr(context, expr, "expected identifier after member operator");
                goto error;
            }
        } else {
            /* Tokenize returned with error */
            goto error;
        }
    } else {
        db_id id;
        db_exprerr(context, expr, "member operator invalid for non-interface type '%s'", db_fullname(type, id));
        goto error;
    }

    return ptr;
error:
    return NULL;
}

/* Utility function that gets integer-index from value */
static db_int16 db_exprGetIntegerIndex(db_char *ptr, db_value *v, db_uint32 *index_out, db_exprContext *context) {
    db_type keyType = db_valueType(v)->real;
    db_void *keyVal = db_valueValue(v);

    if (keyType->kind == DB_PRIMITIVE) {
        switch(db_primitive(keyType)->kind) {
        case DB_INTEGER:
            if (*(db_int32*)keyVal < 0) {
                db_exprerr(context, ptr, "negative index value (%d)", *(db_int32*)keyVal);
                goto error;
            }
            /* no break */
        case DB_UINTEGER:
            *index_out = *(db_uint32*)keyVal;
            break;
        default: {
            db_id id;
            db_exprerr(context, ptr, "index-expression is of type '%s' (expected integer)", db_fullname(keyType, id));
            goto error;
        }
        }
    } else {
        db_id id;
        db_exprerr(context, ptr, "index-expression is of non-primitive type '%s' (expected integer)", db_fullname(keyType, id));
        goto error;
    }

    return 0;
error:
    return -1;
}

/* Element expression */
static db_string db_exprElementExpr(db_string expr, db_exprContext *context) {
    db_char *ptr = expr;
    db_value key;

    /* Recursively call exprExpr for element-key expression */
    ptr = db_exprExprRecur(ptr, FALSE, &key, context);
    if (ptr) {
        db_value *lvalue = &context->valueStack[context->valueCount-1];
        db_type type = db_valueType(lvalue)->real;

        if (type->kind == DB_COLLECTION) {
            db_type elementType = db_collection(type)->elementType->real;
            db_uint32 elementSize = db_type_sizeof(elementType);
            db_void *ptr = db_valueValue(lvalue);
            db_void *keyVal = db_valueValue(&key);

            switch(db_collection(type)->kind) {
            case DB_SEQUENCE: {
                void *array = ((db_objectSeq*)ptr)->buffer;
                db_uint32 length = ((db_objectSeq*)ptr)->length, index = 0;
            case DB_ARRAY:
                if (db_collection(type)->kind == DB_ARRAY) {
                    array = ptr;
                    length = db_collection(type)->max;
                }
                if (db_exprGetIntegerIndex(ptr, &key, &index, context)) {
                    goto error;
                }

                if (index >= length) {
                    db_exprerr(context, expr, "index(%d) out of bounds(%d)", index, length);
                    goto error;
                }
                db_valueElementInit(&context->valueStack[context->valueCount], db_valueObject(lvalue), (db_typedef)elementType, index, DB_OFFSET(array, elementSize * index));
                context->valueStack[context->valueCount].parent = lvalue;
                context->valueCount++;
                break;
            }
            case DB_LIST: {
                db_ll list;

                list = *(db_ll*)ptr;
                if (list) {
                    db_uint32 length, index;
                    length = db_llSize(list);
                    if (db_exprGetIntegerIndex(ptr, &key, &index, context)) {
                        goto error;
                    }
                    if (index >= length) {
                        db_exprerr(context, expr, "index(%d) out of bounds(%d)", index, length);
                        goto error;
                    }
                    db_valueElementInit(&context->valueStack[context->valueCount], db_valueObject(lvalue), (db_typedef)elementType, index, db_llGet(list, index));
                    context->valueStack[context->valueCount].parent = lvalue;
                    context->valueCount++;
                } else {
                    db_exprerr(context, expr, "list is empty");
                    goto error;
                }

                break;
            }
            case DB_MAP: {
                db_rbtree map = *(db_rbtree*)ptr;
                if (map) {
                    db_type keyType = db_map(type)->keyType->real;
                    db_type keyTypeFrom = db_valueType(&key)->real;

                    /* If type of key doesn't match, convert value */
                    if (keyType != keyTypeFrom) {
                    	if ((keyType->kind == DB_PRIMITIVE) && (keyTypeFrom->kind == DB_PRIMITIVE)) {
                        	void *keyValPtr = alloca(db_type_sizeof(keyType));
                        	if (db_convert(db_primitive(keyTypeFrom), keyVal, db_primitive(keyType), keyValPtr)) {
                        		goto error;
                        	}
                            if (!db_rbtreeHasKey(map, keyValPtr, &ptr)) {
                                db_exprerr(context, expr, "key not set in map");
                                goto error;
                            }
                    	} else {
                    		db_exprerr(context, expr, "cannot convert non-primitive types for keyvalue");
                    		goto error;
                    	}
                    } else {
                        if (!db_rbtreeHasKey(map, keyVal, &ptr)) {
                            db_exprerr(context, expr, "key not set in map");
                            goto error;
                        }
                    }

                    db_valueMapElementInit(&context->valueStack[context->valueCount], db_valueObject(lvalue), (db_typedef)elementType, (db_typedef)keyType, keyVal, ptr);
                    context->valueStack[context->valueCount].parent = lvalue;
                    context->valueCount++;
                } else {
                    db_exprerr(context, expr, "map is empty");
                    goto error;
                }
                break;
            }
            }
        } else {
            db_id id;
            db_exprerr(context, expr, "invalid element expression for value of non-collection type '%s'", db_fullname(type, id));
            goto error;
        }
    }

    return ptr + 1; /* Skip ']' */
error:
    return NULL;
}

/* Parse call-expression */
static db_string db_exprCallExpr(db_string expr, db_exprContext *context) {
    db_char *ptr;
    db_value result, *lvalue;
    db_void *argbuffer, *argbufferPtr, *resultPtr;
    db_void *_this = NULL;
    db_function function;
    db_uint32 argumentCount;

    /* Obtain function */
    lvalue = &context->valueStack[context->valueCount-1];
    function = db_valueFunction(lvalue);

    if (!function) {
        goto error;
    } else {
        switch(db_procedure(db_typeof(function))->kind) {
        case DB_FUNCTION:
        case DB_CALLBACK:
        case DB_METAPROCEDURE:
            /* no _this */
            break;
        case DB_OBSERVER: {
            db_id id;
            db_exprerr(context, expr, "invalid call to '%s', observers cannot be called directly", db_fullname(function, id));
            break;
        }
        case DB_METHOD:
        case DB_DELEGATE:
            _this = db_valueThis(lvalue);
            break;
        }
    }

    /* Allocate memory for arguments */
    argbuffer = alloca(function->size);
    argbufferPtr = argbuffer;

    if (_this) {
        *(void**)argbufferPtr = _this;
        argbufferPtr = DB_OFFSET(argbufferPtr, sizeof(void*));
    }

    /* TODO: function overloading */

    context->precedence = DB_COMMA;
    argumentCount = 0;
    ptr = expr;
    while(*ptr != ')') {
        if (argumentCount >= function->parameters.length) {
            db_id id;
            db_exprerr(context, expr, "too many arguments for function %s (expected %d)", db_fullname(function, id), function->parameters.length);
            goto error;
        }
        ptr = db_exprExprRecur(ptr, TRUE, &result, context);
        if (ptr) {
            db_type exprType, parameterType;

            exprType = db_valueType(&result)->real;
            parameterType = function->parameters.buffer[argumentCount].type->real;

            /* Convert argument-type */
            if (db_type_castable(parameterType, exprType)) {
                if (!db_convert(db_primitive(exprType), db_valueValue(&result), db_primitive(parameterType), argbufferPtr)) {
                    argbufferPtr = DB_OFFSET(argbufferPtr, db_type_sizeof(parameterType));
                } else {
                    goto error;
                }
            } else {
                db_id id, id2, id3;
                db_exprerr(context, expr, "no conversion between '%s' and '%s' of argument %d of '%s'",
                        db_fullname(exprType, id),
                        db_fullname(parameterType, id2),
                        argumentCount+1,
                        db_fullname(function, id3));
                goto error;
            }

        } else {
            goto error;
        }
        if (*ptr == ',') {
            ptr += 1; /* Skip , */
        }
        argumentCount++;
    }

    if (argumentCount < function->parameters.length) {
        db_id id;
        db_exprerr(context, expr, "too few arguments for function %s (expected %d)", db_fullname(function, id), function->parameters.length);
        goto error;
    }

    /* If arguments parsed without errors, call function */
    if (!function->returnType->real->reference) {
        context->valueStack[0].kind = DB_VALUE;
        context->valueStack[0].is.value.o = NULL;
        context->valueStack[0].is.value.t = function->returnType;

        switch(function->returnType->real->kind) {
        case DB_PRIMITIVE:
            context->valueStack[0].is.value.v = &context->valueStack[0].is.value.storage;
            break;
        default:
            context->valueStack[0].is.value.v = db_malloc(db_type_sizeof(function->returnType->real));
            break;
        }
        resultPtr = context->valueStack[0].is.value.v;
    } else {
        context->valueStack[0].kind = DB_OBJECT;
        context->valueStack[0].is.o = NULL;
        resultPtr = &context->valueStack[0].is.o;
    }

    context->valueCount = 1;
    db_callb(function, resultPtr, argbuffer);

    if (function->returnType->real->reference) {
        if (!*(db_object*)resultPtr) {
            db_id id;
            db_exprerr(context, expr, "function '%s' returned NULL", db_fullname(function, id));
            goto error;
        } else {
            db_keep(*(db_object*)resultPtr);
        }
    }

	return ptr + 1; /* Skip '(' */
error:
    return NULL;
}

/* Postfix expression */
static db_string db_exprPostfixExpr(db_string expr, db_exprToken *operator, db_exprContext *context) {
    db_char *ptr = expr;
    db_value *lvalue = &context->valueStack[context->valueCount-1];

    switch(operator->value._operator) {
    /* The increment and decrement operators require an lvalue */
    case DB_INC:
    case DB_DEC:
        if (lvalue->kind != DB_LITERAL) {
            db_void *ptr = db_valueValue(lvalue);
            if (db_unaryOperator(db_valueType(lvalue)->real, operator->value._operator, ptr, ptr)) {
                goto error;
            }
        } else {
            db_exprerr(context, ptr, "lvalue required for operator");
            goto error;
        }
        break;

    /* Resolve member of an interface */
    case DB_MEMBER_RESOLVE:
        ptr = db_exprMemberExpr(expr, context);
        break;
    case DB_ELEMENT_OPEN:
        ptr = db_exprElementExpr(expr, context);
        break;
    case DB_BRACKET_OPEN:
    	ptr = db_exprCallExpr(expr, context);
        break;
    default:
        db_exprerr(context, ptr, "invalid operator for postfix expression");
        break;
    }

    return ptr;
error:
    return NULL;
}

db_int8 db_exprPrecedence(db_operatorKind op1, db_operatorKind op2) {
    return db_operatorPrecedence[op1] > db_operatorPrecedence[op2] ? -1 : db_operatorPrecedence[op1] == db_operatorPrecedence[op2] ? 0 : 1;
}

static db_string db_exprRvalueExpr(db_string expr, db_exprToken *leftOperator, db_value *rvalue_out, db_exprContext *context) {
    db_char *ptr = expr, *lookaheadPtr;
    db_exprToken rvalue, rightOperator;

    /* Parse rvalue */
    ptr = db_tokenize(expr, &rvalue, context);
    if (ptr) {
        /* Instead of a value, a bracket can be parsed */
        if (rvalue.kind == DB_TOKEN_OPERATOR) {
            switch(rvalue.value._operator) {
            case DB_BRACKET_OPEN:
                /* Brackets always take precedence */
                ptr = db_exprExprRecur(ptr, FALSE, rvalue_out, context);
                break;
            default:
                db_exprerr(context, ptr, "unexpected operator");
                goto error;
            }
        } else {
            /* Lookahead one token to compare operator precedence */
            lookaheadPtr = db_tokenize(ptr, &rightOperator, context);
            if (lookaheadPtr &&  *lookaheadPtr) {
                if (rightOperator.kind == DB_TOKEN_OPERATOR) {
                    switch(rightOperator.value._operator) {
                    case DB_BRACKET_CLOSE:
                        /* Avoid consuming the ')' */
                        ptr = db_exprPrimaryExpr(ptr, &rvalue, rvalue_out, context);
                        break;
                    default:
                        /* If left operator takes precedence, evaluate left-side first. Otherwise evaluate right-side */
                        switch(db_exprPrecedence(leftOperator->value._operator, rightOperator.value._operator)) {
                        case -1:
                            context->precedence = leftOperator->value._operator;
                            ptr = db_exprExprRecur(expr, TRUE, rvalue_out, context);
                            break;
                        case 0:
                            /* TODO: Implement left\right associativity, for now, fallthrough */
                        case 1:
                            ptr = db_exprPrimaryExpr(ptr, &rvalue, rvalue_out, context);
                            break;
                        }
                        break;
                    }
                } else {
                    db_exprerr(context, ptr, "expected operator for right-hand side of expression (%d,%s)", rightOperator.kind, ptr);
                    goto error;
                }
            } else {
                /* End of expression */
                ptr = db_exprPrimaryExpr(ptr, &rvalue, rvalue_out, context);
            }
        }
    }

    return ptr;
error:
    return NULL;
}

static db_int16 db_exprDoOperator(db_string expr, db_operatorKind operator, db_value *lvalue, db_value *rvalue, db_value *result, db_exprContext *context) {
	db_void *lptr = db_valueValue(lvalue);
	db_void *rptr = db_valueValue(rvalue);
	db_type ltype = db_valueType(lvalue)->real;
	db_type rtype = db_valueType(rvalue)->real;
	db_void *resultPtr = &result->is.value.storage;

	/* If types of operands are different, convert to type of left operand */
	if (ltype != rtype) {
		if ((ltype->kind == DB_PRIMITIVE) && (rtype->kind == DB_PRIMITIVE)) {
			db_void *rptrToLeft = alloca(db_type_sizeof(ltype));
			db_convert(db_primitive(rtype), rptr, db_primitive(ltype), rptrToLeft);
			if (db_binaryOperator(ltype, operator, lptr, rptrToLeft, resultPtr)) {
				goto error;
			}
		} else {
			db_id id, id2;
			db_exprerr(context, expr, "cannot convert between non-primitive types '%s' and '%s'", db_fullname(ltype, id), db_fullname(rtype, id2));
			goto error;
		}
	} else {
		if (db_binaryOperator(ltype, operator, lptr, rptr, resultPtr)) {
			goto error;
		}
	}

	result->kind = DB_VALUE;
	result->is.value.v = resultPtr;
	result->is.value.o = NULL;

	/* If the result is a conditional expression, resultType is a boolean */
	switch(operator) {
    case DB_COND_LT:
    case DB_COND_GT:
    case DB_COND_LTEQ:
    case DB_COND_GTEQ:
    case DB_COND_EQ:
    case DB_COND_NEQ:
    case DB_COND_AND:
    case DB_COND_OR:
    	result->is.value.t = (db_typedef)db_bool_o;
    	break;
    default:
    	result->is.value.t = (db_typedef)ltype;
    	break;
	}

	return 0;
error:
	return -1;
}

static db_string db_exprBinaryExpr(db_string expr, db_exprToken *operator, db_exprContext *context) {
	db_char *ptr = expr;
	db_value rvalue;
	db_value *lvalue = &context->valueStack[context->valueCount-1];
	db_value *result = &context->valueStack[0]; /* expression resets stack to zero */

	/* Get rvalue */
	ptr = db_exprRvalueExpr(ptr, operator, &rvalue, context);
	if (ptr) {
		if (db_exprDoOperator(expr, operator->value._operator, lvalue, &rvalue, result, context)) {
			goto error;
		}
		context->valueCount = 1;
	}

    return ptr;
error:
	return NULL;
}

static db_string db_exprPrimaryExpr(db_string expr, db_exprToken *lvalue, db_value *result, db_exprContext *context) {
    result->kind = DB_LITERAL;
    switch(lvalue->kind) {
        case DB_TOKEN_BOOLEAN:
            result->is.literal.kind = DB_LITERAL_BOOLEAN;
            result->is.literal.v._boolean = lvalue->value._boolean;
            break;
        case DB_TOKEN_CHARACTER:
            result->is.literal.kind = DB_LITERAL_CHARACTER;
            result->is.literal.v._character = lvalue->value._character;
            break;
        case DB_TOKEN_INTEGER:
            result->is.literal.kind = DB_LITERAL_INTEGER;
            result->is.literal.v._integer = lvalue->value._integer;
            break;
        case DB_TOKEN_UNSIGNED_INTEGER:
            result->is.literal.kind = DB_LITERAL_UNSIGNED_INTEGER;
            result->is.literal.v._unsigned_integer = lvalue->value._unsigned_integer;
            break;
        case DB_TOKEN_FLOATING_POINT:
            result->is.literal.kind = DB_LITERAL_FLOATING_POINT;
            result->is.literal.v._floating_point = lvalue->value._floating_point;
            break;
        case DB_TOKEN_STRING:
            result->is.literal.kind = DB_LITERAL_STRING;
            result->is.literal.v._string = lvalue->value._string;
            break;
        case DB_TOKEN_NULL:
            result->is.literal.kind = DB_LITERAL_NULL;
            break;
        default:
            db_exprerr(context, expr, "invalid primary expression");
            break;
    }
	return expr;
}

static db_string db_exprObjectExpr(db_string expr, db_exprToken *lvalue, db_value *result, db_exprContext *context) {
    if (lvalue->kind == DB_TOKEN_IDENTIFIER) {
        db_object o;
        o = db_resolve_ext(NULL, context->scope, lvalue->value._identifier, FALSE, "Resolve object for expression");
        if (o) {
            result->kind = DB_OBJECT;
            result->is.o = o;
            result->parent = NULL;
            if (context->participants) {
            	db_llAppend(context->participants, o);
            }
        } else {
            db_exprerr(context, expr, "identifier '%s' does not resolve to object", lvalue->value._identifier);
            goto error;
        }
    } else {
        db_exprerr(context, expr, "invalid object expression");
        goto error;
    }
    return expr;
error:
    return NULL;
}

static db_string db_exprExpr(db_string expr, db_bool rvalue, db_bool firstTokenParsed, db_exprContext *context) {
    db_exprToken token, operator;
    db_value *result = &context->valueStack[0];
    db_char *ptr;
    db_bool endOfExpression = FALSE;

    /* Parse first token */
    if (!firstTokenParsed) {
        /* Initialize to valid value. If parsing fails before value is set, the error-handling will be
         * able to tell that there is nothing to clean up. */
        ptr = db_tokenize(expr, &token, context);
        if (ptr) {
            switch(token.kind) {
            case DB_TOKEN_BOOLEAN:
            case DB_TOKEN_CHARACTER:
            case DB_TOKEN_INTEGER:
            case DB_TOKEN_UNSIGNED_INTEGER:
            case DB_TOKEN_FLOATING_POINT:
            case DB_TOKEN_STRING:
            case DB_TOKEN_NULL:
                ptr = db_exprPrimaryExpr(ptr, &token, result, context);
                break;
            case DB_TOKEN_IDENTIFIER:
                ptr = db_exprObjectExpr(ptr, &token, result, context);
                break;
            case DB_TOKEN_OPERATOR:
                switch(token.value._operator) {
                case DB_BRACKET_OPEN:
                    ptr = db_exprExpr(ptr, FALSE, FALSE, context);
                    break;
                case DB_BRACKET_CLOSE:
                    endOfExpression = TRUE;
                    break;
                default:
                    db_exprerr(context, ptr, "unexpected operator");
                    goto error;
                    break;
                }
                break;
            }
        }
        context->valueCount = 1;
        db_exprTokenFree(&token);
    } else {
        ptr = expr;
    }

    /* Parse next tokens. This loop should only encounter operators. */
    while(!endOfExpression && ptr && *ptr) {
        db_char *rvaluePtr;
    	expr = ptr;
    	rvaluePtr = db_tokenize(ptr, &operator, context);
        if (ptr) {
            switch(operator.kind) {
            case DB_TOKEN_OPERATOR:
                /* If expression is rvalue, parse as long as operator takes precedence */
                if (!rvalue || (db_exprPrecedence(context->precedence, operator.value._operator) < 0)) {
                    switch(operator.value._operator) {

                    /* Postfix operators */
                    case DB_INC:
                    case DB_DEC:
                    case DB_MEMBER_RESOLVE:
                    case DB_ELEMENT_OPEN:
                    case DB_BRACKET_OPEN:
                        ptr = rvaluePtr;
                        ptr = db_exprPostfixExpr(ptr, &operator, context);
                        break;

                    /* Binary operators */
                    case DB_ADD:
                    case DB_SUB:
                    case DB_MUL:
                    case DB_DIV:
                    case DB_MOD:
                    case DB_SHIFT_LEFT:
                    case DB_SHIFT_RIGHT:
                    case DB_COND_LT:
                    case DB_COND_GT:
                    case DB_COND_LTEQ:
                    case DB_COND_GTEQ:
                    case DB_COND_EQ:
                    case DB_COND_NEQ:
                    case DB_AND:
                    case DB_XOR:
                    case DB_OR:
                    case DB_COND_AND:
                    case DB_COND_OR:
                    case DB_ASSIGN_ADD:
                    case DB_ASSIGN_SUB:
                    case DB_ASSIGN_MUL:
                    case DB_ASSIGN_DIV:
                    case DB_ASSIGN_MOD:
                    case DB_ASSIGN_AND:
                    case DB_ASSIGN_OR:
                    case DB_ASSIGN:
                        ptr = rvaluePtr;
                        ptr = db_exprBinaryExpr(ptr, &operator, context);
                        break;

                    /* Expression close */
                    case DB_ELEMENT_CLOSE:
                    case DB_BRACKET_CLOSE:
                    case DB_COMMA:
                        endOfExpression = TRUE;
                        break;

                    default:
                        db_exprerr(context, expr, "unexpected operator");
                        goto error;
                    }
                    break;
                default:
                    db_exprerr(context, expr, "expected operator");
                    goto error;
                } else {
                    endOfExpression = TRUE;
                }
                break;
            }
        }

    }
    if (!ptr) {
        goto error;
    }

    return ptr;
error:
    if (context->valueCount) {
        db_object o;
        if ((o = db_valueObject(&context->valueStack[0]))) {
            db_free(o);
        }
    }
    return NULL;
}

static db_string db_exprExprRecur(db_string expr, db_bool singleExpression, db_value *result, db_exprContext *context) {
    db_char *ptr;
    db_valueStack stack;
    db_exprContext recurContext = *context;

    recurContext.valueStack = stack;
    recurContext.valueCount = 0;
    ptr = db_exprExpr(expr, singleExpression, FALSE, &recurContext);
    if (ptr) {
        *result = recurContext.valueStack[recurContext.valueCount-1];
    }
    db_valueStackFree(stack, recurContext.valueCount);

    return ptr;
}

db_value *db_expr(db_object scope, db_string expr, db_valueStack stack, db_uint32 *stackSize, db_ll participants) {
    db_exprContext context;

    if (!db_tokenClassesInitialized) {
        db_tokenClassesInitialize();
        db_operatorPrecedenceInitialize();
    }

    context.scope = scope;
    context.expr = expr;
    context.participants = participants;
    stack[0].kind = DB_LITERAL;

    /* If no expression is provided, return scope */
    if (!strlen(db_skipWhitespace(expr))) {
        if (scope) {
            stack[0].kind = DB_OBJECT;
            stack[0].is.o = scope; db_keep_ext(NULL, scope, "keep scope for empty expression result");
            stack[0].parent = NULL;
            *stackSize = 1;
        } else {
            db_exprerr(&context, expr, "empty expression");
            goto error;
        }
    } else {
        context.valueStack = stack;
        context.valueCount = 0;

        /* If a scope is provided, set scope as first element */
        if (scope) {
            db_exprToken token;
            stack[0].kind = DB_OBJECT;
            stack[0].is.o = scope; db_keep_ext(NULL, scope, "keep scope for expression result");
            stack[0].parent = NULL;
            context.valueCount = 1;

            /* Parse first token. If first token is an operator, skip parsing first token. Parser will
             * then treat the scope-object as the first parsed token. */
            db_tokenize(expr, &token, &context);

            /* Parse expression-statement */
            if (token.kind != DB_TOKEN_OPERATOR) {
                db_exprTokenFree(&token);
                if (!db_exprExpr(expr, FALSE, FALSE, &context)) {
                    goto error;
                }
            } else {
                if (!db_exprExpr(expr, FALSE, TRUE, &context)) {
                    goto error;
                }
            }
        } else {
            /* Parse expression-statement */
            if (!db_exprExpr(expr, FALSE, FALSE, &context)) {
                goto error;
            }
        }

        *stackSize = context.valueCount;

        if (stack[context.valueCount-1].kind == DB_CALL) {
            db_exprerr(&context, expr, "missing arguments for method call");
            goto error;
        }
    }

    {
        db_value *v = &stack[*stackSize - 1];
        if (stack[0].parent != NULL) {
            db_trace("root of valueStack does not point to zero!");
        }
        while((v = v->parent));
    }

    return &stack[*stackSize - 1];
error:
	if (stack[0].is.o != scope) {
		db_free_ext(NULL, scope, "free scope - different object returned from expression");
	}
    return NULL;
}


