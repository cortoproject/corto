
/*
 * corto_value.c
 *
 *  Created on: Apr 13, 2012
 *      Author: sander
 */

#include "corto/corto.h"

corto_type corto_value_getType(corto_value* val) {
    corto_type result;

    switch(val->kind) {
    case CORTO_OBJECT:
        result = val->is.object.t;
        break;
    case CORTO_BASE:
        result = val->is.base.t;
        break;
    case CORTO_VALUE:
        result = val->is.value.t;
        break;
    case CORTO_LITERAL:
        switch(val->is.literal.kind) {
        case CORTO_LITERAL_BOOLEAN:
            result = corto_type(corto_bool_o);
            break;
        case CORTO_LITERAL_CHARACTER:
            result = corto_type(corto_char_o);
            break;
        case CORTO_LITERAL_INTEGER:
            result = corto_type(corto_int64_o);
            break;
        case CORTO_LITERAL_UNSIGNED_INTEGER:
            result = corto_type(corto_uint64_o);
            break;
        case CORTO_LITERAL_FLOATING_POINT:
            result = corto_type(corto_float64_o);
            break;
        case CORTO_LITERAL_STRING:
            result = corto_type(corto_string_o);
            break;
        case CORTO_LITERAL_NULL:
            result = NULL;
            break;
        default:
            corto_critical("corto_value_getType: invalid corto_literalKind(%d)", val->is.literal.kind);
            result = NULL;
            break;
        }
        break;
    case CORTO_MEMBER:
        result = val->is.member.t->type;
        break;
    case CORTO_CONSTANT:
        result = corto_value_getType(val->parent);
        break;
    case CORTO_ELEMENT:
        result = val->is.element.t.type;
        break;
    case CORTO_MAP_ELEMENT:
        result = val->is.mapElement.t.type;
        break;
    default:
        corto_critical("corto_value_getType: invalid corto_valueKind(%d).", val->kind);
        result = NULL;
        break;
    }

    return result;
}

corto_void* corto_value_getPtr(corto_value* val) {
    corto_void* result;
    switch(val->kind) {
    case CORTO_OBJECT:
        result = val->is.object.o;
        break;
    case CORTO_BASE:
        result = val->is.base.v;
        break;
    case CORTO_LITERAL:
        result = &val->is.literal.v;
        break;
    case CORTO_VALUE:
        result = val->is.value.v;
        break;
    case CORTO_MEMBER:
        result = val->is.member.v;
        break;
    case CORTO_CONSTANT:
        result = val->is.constant.v;
        break;
    case CORTO_ELEMENT:
        result = val->is.element.v;
        break;
    case CORTO_MAP_ELEMENT:
        result = val->is.mapElement.v;
        break;
    default:
        corto_critical("corto_value_getPtr: invalid corto_valueKind(%d).", val->kind);
        result = NULL;
        break;
    }
    return result;
}

corto_object corto_value_getObject(corto_value* val) {
    corto_object result;

    switch(val->kind) {
    case CORTO_OBJECT:
        result = val->is.object.o;
        break;
    case CORTO_BASE:
        result = val->is.base.o;
        break;
    case CORTO_LITERAL:
        result = NULL;
        break;
    case CORTO_VALUE:
        result = val->is.value.o;
        break;
    case CORTO_MEMBER:
        result = val->is.member.o;
        break;
    case CORTO_CONSTANT:
        result = val->is.constant.o;
        break;
    case CORTO_ELEMENT:
        result = val->is.element.o;
        break;
    case CORTO_MAP_ELEMENT:
        result = val->is.mapElement.o;
        break;
    default:
        corto_critical("corto_value_getObject: invalid corto_valueKind(%d).", val->kind);
        result = NULL;
        break;
    }
    return result;
}

corto_function corto_valueFunction(corto_value* val) {
    corto_function result;

    switch(val->kind) {
    case CORTO_OBJECT:
        if (corto_class_instanceof(corto_procedure_o, corto_typeof(val->is.object.o))) {
            result = val->is.object.o;
        } else {
            corto_seterr("object '%s' in value is not a function",
                corto_fullpath(NULL, val->is.object.o));
            result = NULL;
        }
        break;
    default:
       corto_seterr("value does not represent a function");
       result = NULL;
       break;
    }

    return result;
}

corto_uint32 corto_value_getIndex(corto_value* val) {
    corto_uint32 result = 0;
    switch(val->kind) {
    case CORTO_ELEMENT:
        result = val->is.element.t.index;
        break;
    default:
        corto_error("cannot obtain index from non-element value");
        break;
    }
    return result;
}

static char* corto_valueKindString[CORTO_CONSTANT+1] = {"object", "base", "member", "constant", "element"};

char* corto_strving(corto_value* v, char* buffer, unsigned int length) {
    corto_id object_name;
    corto_member m;
    corto_value* parents[CORTO_MAX_INHERITANCE_DEPTH];
    corto_int32 parentCount, i;
    corto_value* vptr;

    if (length < (strlen("ELEMENT") + 3)) {
        corto_error("buffer passed to corto_strving is too short.");
        goto error;
    }

    /* Put label in buffer */
    sprintf(buffer, "%s ", corto_valueKindString[v->kind]);

    /* Get name of object */
    corto_fullpath(object_name, corto_value_getObject(v));
    if ((strlen(buffer) + (strlen(object_name) + 2 + 1)) >= length) {
        corto_error("buffer passed to corto_strving is too short for object name.");
        goto error;
    }

    /* Put objectname in buffer */
    strcat(buffer, object_name);

    /* Collect parents */
    parentCount = 0;
    vptr = v;
    do{
        if (vptr->kind != CORTO_OBJECT) {
            parents[parentCount] = vptr;
            parentCount++;
        }
    }while((vptr = vptr->parent));

    /* Put name of member or branch in buffer */
    for(i=parentCount-1; i>=0; i--) {
        vptr = parents[i];
        m = NULL;
        switch(vptr->kind) {
        case CORTO_LITERAL:
        case CORTO_VALUE:
            /* Nothing to add for just a value */
            break;
        case CORTO_BASE:
            break;
        case CORTO_MEMBER:
            m = vptr->is.member.t;
            break;
        case CORTO_ELEMENT:
            sprintf(buffer, "%s[%d]", buffer, vptr->is.element.t.index);
            m = NULL;
            break;
        default:
            corto_trace("corto_strving: unhandled '%s'", corto_valueKindString[vptr->kind]);
            m = NULL;
            break;
        }
        if (m) {
            if ((strlen(buffer) + strlen(corto_idof(m)) + 1) >= length) {
                corto_error("buffer passed to corto_strving is too short for member name");
            } else {
                strcat(buffer, ".");
                strcat(buffer, corto_idof(m));
            }
        }
    }

    return buffer;
error:
    return NULL;
}

char* corto_valueExpr(corto_value* v, char* buffer, unsigned int length) {
    corto_member m;
    corto_value* parents[CORTO_MAX_INHERITANCE_DEPTH];
    corto_int32 parentCount, i;
    corto_value* vptr;

    *buffer = '\0';

    /* Collect parents */
    parentCount = 0;
    vptr = v;
    do{
        if (vptr->kind != CORTO_OBJECT) {
            parents[parentCount] = vptr;
            parentCount++;
        }
    }while((vptr = vptr->parent));

    /* Put name of member or branch in buffer */
    for(i=parentCount-1; i>=0; i--) {
        vptr = parents[i];
        m = NULL;
        switch(vptr->kind) {
        case CORTO_LITERAL:
        case CORTO_VALUE:
            break;
        case CORTO_BASE:
            break;
        case CORTO_MEMBER:
            m = vptr->is.member.t;
            break;
        case CORTO_ELEMENT:
            sprintf(buffer, "%s[%d]", buffer, vptr->is.element.t.index);
            m = NULL;
            break;
        default:
            corto_trace("corto_valueExpr: unhandled '%s'", corto_valueKindString[vptr->kind]);
            m = NULL;
            goto error;
        }
        if (m) {
            if ((strlen(buffer) + strlen(corto_idof(m)) + 1) >= length) {
                corto_error("buffer passed to corto_strving is too short for member name");
            } else {
                strcat(buffer, ".");
                strcat(buffer, corto_idof(m));
            }
        }
    }

    return buffer;
error:
    return NULL;
}

corto_value _corto_value_object(corto_object o, corto_type t) {
    corto_value val;
    val.kind = CORTO_OBJECT;
    val.parent = NULL;
    val.is.object.o = o;
    if (t) {
        val.is.object.t = t;
    } else {
        val.is.object.t = corto_typeof(o);
    }
    return val;
}

corto_value _corto_value_base(corto_void *v, corto_type t) {
    corto_value val;
    val.kind = CORTO_BASE;
    val.parent = NULL;
    val.is.base.v = v;
    val.is.base.t = t;
    return val;
}

corto_value _corto_value_value(corto_type t, corto_void* v) {
    corto_value val;
    val.kind = CORTO_VALUE;
    val.parent = NULL;
    val.is.value.storage = 0;
    val.is.value.o = NULL;
    val.is.value.t = t;
    val.is.value.v = v;
    return val;
}
corto_value corto_value_member(corto_object o, corto_member t, corto_void* v) {
    corto_value val;
    val.kind = CORTO_MEMBER;
    val.parent = NULL;
    val.is.member.o = o;
    val.is.member.t = t;
    val.is.member.v = v;
    return val;
}
corto_value corto_value_constant(corto_object o, corto_constant* t, corto_void* v) {
    corto_value val;
    val.kind = CORTO_CONSTANT;
    val.parent = NULL;
    val.is.constant.o = o;
    val.is.constant.t = t;
    val.is.constant.v = v;
    return val;
}
corto_value _corto_value_element(corto_object o, corto_type t, corto_uint32 index, corto_void* v) {
    corto_value val;
    val.kind = CORTO_ELEMENT;
    val.parent = NULL;
    val.is.element.o = o;
    val.is.element.t.type = t;
    val.is.element.t.index = index;
    val.is.element.v = v;
    return val;
}

corto_value _corto_value_mapElement(corto_object o, corto_type t, corto_type keyType, corto_void *key, corto_void* v) {
    corto_value val;
    val.kind = CORTO_MAP_ELEMENT;
    val.parent = NULL;
    val.is.mapElement.o = o;
    val.is.mapElement.t.type = t;
    val.is.mapElement.t.keyType = keyType;
    val.is.mapElement.t.key = key;
    val.is.mapElement.v = v;
    return val;
}

corto_value corto_value_literal(corto_literalKind kind, corto_void* value) {
    corto_value val;
    val.kind = CORTO_LITERAL;
    val.is.literal.kind = kind;
    val.parent = NULL;

    switch(kind) {
    case CORTO_LITERAL_BOOLEAN:
        val.is.literal.v._boolean = *(corto_bool*)value;
        break;
    case CORTO_LITERAL_CHARACTER:
        val.is.literal.v._character = *(corto_char*)value;
        break;
    case CORTO_LITERAL_INTEGER:
        val.is.literal.v._integer = *(corto_int64*)value;
        break;
    case CORTO_LITERAL_UNSIGNED_INTEGER:
        val.is.literal.v._unsigned_integer = *(corto_uint64*)value;
        break;
    case CORTO_LITERAL_FLOATING_POINT:
        val.is.literal.v._floating_point = *(corto_float64*)value;
        break;
    case CORTO_LITERAL_STRING:
        if (*(corto_string*)value) {
            val.is.literal.v._string = corto_strdup(*(corto_string*)value);
        } else {
            val.is.literal.v._string = NULL;
        }
        break;
    case CORTO_LITERAL_NULL:
        break;
    }
    return val;
}

corto_value corto_value_literalBoolean(corto_bool value) {
    return corto_value_literal(CORTO_LITERAL_BOOLEAN, &value);
}
corto_value corto_value_literalCharacter(corto_char value) {
    return corto_value_literal(CORTO_LITERAL_CHARACTER, &value);
}
corto_value corto_value_literalInteger(corto_uint64 value) {
    return corto_value_literal(CORTO_LITERAL_INTEGER, &value);
}
corto_value corto_value_literalUnsignedInteger(corto_uint64 value) {
    return corto_value_literal(CORTO_LITERAL_UNSIGNED_INTEGER, &value);
}
corto_value corto_value_literalFloatingPoint(corto_float64 value) {
    return corto_value_literal(CORTO_LITERAL_FLOATING_POINT, &value);
}
corto_value corto_value_literalString(corto_string value) {
    return corto_value_literal(CORTO_LITERAL_STRING, &value);
}

void corto_valueSetValue(corto_value* val, corto_void* v) {
    switch(val->kind) {
    case CORTO_OBJECT:
        val->is.object.o = v; /* Dangerous, but allowed */
        break;
    case CORTO_BASE:
        val->is.base.v = v;
        break;
    case CORTO_MEMBER:
        val->is.member.v = v;
        break;
    case CORTO_CONSTANT:
        val->is.constant.v = v;
        break;
    case CORTO_ELEMENT:
        val->is.element.v = v;
        break;
    case CORTO_MAP_ELEMENT:
        val->is.mapElement.v = v;
        break;
    default:
        corto_assert(0, "corto_valueSetValue: invalid valueKind %d.", val->kind);
        break;
    }
}


#include "corto/corto.h"

static corto_type corto_valueExpr_getType(corto_type src, corto_type target, corto_bool targetIsRef) {
    corto_type result = src;

    if (!src) {
        if (target) {
            if (target->reference) {
                result = target;
            } else if ((target->kind == CORTO_PRIMITIVE) && (corto_primitive(target)->kind == CORTO_TEXT)) {
                result = corto_type(corto_string_o);
            } else {
                if (targetIsRef) {
                    result = target;
                } else {
                    corto_seterr(
                      "invalid usage of null with non-string and non-reference type '%s'",
                      corto_fullpath(NULL, target));
                    goto error;
                }
            }
        } else {
            result = corto_void_o;
        }
    } else if ((target && (target->kind == CORTO_VOID) && target->reference)) {
        result = corto_object_o;
    }

    return result;
error:
    return NULL;
}

/* Rate types based on expressibility */
static corto_int8 corto_valueExpr_getTypeScore(corto_primitive t) {
    corto_int8 result = 0;
    switch(t->kind) {
    case CORTO_ENUM:
    case CORTO_BITMASK:
        result = 1;
        break;
    case CORTO_BOOLEAN:
    case CORTO_BINARY:
    case CORTO_INTEGER:
    case CORTO_UINTEGER:
        result = 2;
        break;
    case CORTO_CHARACTER:
        result = 3;
        break;
    case CORTO_FLOAT:
        result = 4;
        break;
    case CORTO_TEXT:
        result = 5;
        break;
    }
    return result;
}

/* Categorize types on castability - if equal no cast is required when width is equal */
static corto_int8 corto_valueExpr_getCastScore(corto_primitive t) {
    corto_int8 result = 0;
    switch(t->kind) {
        case CORTO_ENUM:
        case CORTO_BITMASK:
            result = 1;
            break;
        case CORTO_BOOLEAN:
        case CORTO_BINARY:
        case CORTO_INTEGER:
        case CORTO_UINTEGER:
        case CORTO_CHARACTER:
            result = 2;
            break;
        case CORTO_FLOAT:
            result = 3;
            break;
        case CORTO_TEXT:
            result = 4;
            break;
    }
    return result;
}


static corto_bool corto_valueExpr_isOperatorAssignment(
    corto_operatorKind _operator)
{
    corto_bool result;
    switch(_operator) {
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
        result = FALSE;
        break;
    }
    return result;
}

static corto_bool corto_valueExpr_isOperatorConditional(
    corto_operatorKind _operator)
{
    corto_bool result;
    switch(_operator) {
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

/* Obtain inttype from value */
/* static corto_type corto_getIntTypeFromValue(corto_int64 v, corto_primitive t) {
    corto_type result = NULL;

    if (v < 0) {
        if(t->kind == CORTO_UINTEGER) {
            if (((corto_uint64)v) <= 4294967295) {
                result = corto_type(corto_uint32_o);
            } else {
                result = corto_type(corto_uint64_o);
            }
        } else if (v >= -128) {
            result = corto_type(corto_int8_o);
        } else if (v >= -32768) {
            result = corto_type(corto_int16_o);
        } else if (v >= -2147483648) {
            result = corto_type(corto_int32_o);
        } else {
            result = corto_type(corto_int64_o);
        }
    } else {
        if (v <= 255) {
            result = corto_type(corto_uint8_o);
        } else if (v <= 65535) {
            result = corto_type(corto_uint16_o);
        } else {
            result = corto_type(corto_uint32_o);
        }
    }

    return result;
}
*/

/*corto_type corto_narrowType(ast_Expression expr) {
    corto_int64 v;
    corto_type t = ast_Expression_getType(expr);
    if (ast_Node(expr)->kind == Ast_LiteralExpr) {
        if (t && (t->kind == CORTO_PRIMITIVE)) {
            switch(corto_primitive(t)->kind) {
            case CORTO_INTEGER:
            case CORTO_UINTEGER:
                ast_Expression_serialize(expr, corto_type(corto_int64_o), (corto_word)&v);
                t = ast_Expression_getIntTypeFromValue(v, corto_primitive(t));
                break;
            default:
                break;
            }
        }
    }

    return t;
}*/

/* Check if expression is integer literal that is eligible to changing type, if this is the case do the cast */
/*corto_type corto_narrow(corto_value value, corto_type target) {

    if (ast_Node(expr)->kind == Ast_LiteralExpr) {
        if (!target) {
            target = ast_Expression_narrowType(expr);
        }
        corto_type t = ast_Expression_getType_type(expr, target);
        if (target && (t != target) &&
           (target->kind == CORTO_PRIMITIVE) &&
           (corto_primitive(target)->kind == corto_primitive(t)->kind)) {
            corto_width width = corto_primitive(target)->width;

            if (t->kind == CORTO_PRIMITIVE) {
                switch(corto_primitive(t)->kind) {
                case CORTO_INTEGER: {
                    corto_int64 v = *(corto_int64*)ast_Expression_getValue(expr);
                    switch(width) {
                    case CORTO_WIDTH_8:
                        if ((v <= 127) && (v >= -128)) {
                            corto_setref(&expr->type, target);
                        }
                        break;
                    case CORTO_WIDTH_16:
                        if ((v <= 32767) && (v >= -32768)) {
                            corto_setref(&expr->type, target);
                        }
                        break;
                    case CORTO_WIDTH_32:
                        if ((v <= 2147483647) && (v >= -2147483648)) {
                            corto_setref(&expr->type, target);
                        }
                        break;
                    default:
                        break;
                    }
                    break;
                }
                case CORTO_UINTEGER: {
                    corto_uint64 v = *(corto_uint64*)ast_Expression_getValue(expr);
                    switch(width) {
                    case CORTO_WIDTH_8:
                        if (v <= 255) {
                            corto_setref(&expr->type, target);
                        }
                        break;
                    case CORTO_WIDTH_16:
                        if (v <= 65535) {
                            corto_setref(&expr->type, target);
                        }
                        break;
                    case CORTO_WIDTH_32:
                        if (v <= 4294967295) {
                            corto_setref(&expr->type, target);
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
}*/

corto_int16 corto_valueExpr_getTypeForBinary(
    corto_type leftType,
    corto_bool t1ByRef,
    corto_type rightType,
    corto_bool t2ByRef,
    corto_operatorKind _operator,
    corto_type *operandType,
    corto_type *resultType)
{
    corto_type castType = NULL;
    corto_bool equal = FALSE;

    corto_assert(operandType != NULL, "NULL provided for out-parameter operandType");
    corto_assert(resultType != NULL, "NULL provided for out-parameter resultType");

    /* If operator is condition result type is a boolean */
    if (corto_valueExpr_isOperatorConditional(_operator)) {
        *resultType = corto_type(corto_bool_o);
    }

    /* Get leftType and rightType */
    if (!(leftType = corto_valueExpr_getType(leftType, NULL, FALSE))) {
        goto error;
    }

    if (!(rightType = corto_valueExpr_getType(rightType, leftType, t1ByRef))) {
        goto error;
    }

    if (!leftType) {
        leftType = rightType;
    }

    /* If objects are not scoped, verify whether they're equal */
    if (!corto_checkAttr(leftType, CORTO_ATTR_SCOPED) && !corto_checkAttr(rightType, CORTO_ATTR_SCOPED)) {
        if (corto_compare(leftType, rightType) == CORTO_EQ) {
            equal = TRUE;
        }
    } else {
        equal = leftType == rightType;
    }

    if (_operator == CORTO_DIV) {
        castType = corto_type(corto_float64_o);
    } else if (!equal) {
        /* Can only cast between primitive types */
        if ((leftType->kind == CORTO_PRIMITIVE ) && (rightType->kind == CORTO_PRIMITIVE)) {
            corto_primitive ltype = corto_primitive(leftType), rtype = corto_primitive(rightType);
            corto_int8 lscore, rscore;
            corto_int8 lCastScore, rCastScore;

            lscore = corto_valueExpr_getTypeScore(ltype);
            rscore = corto_valueExpr_getTypeScore(rtype);
            lCastScore = corto_valueExpr_getCastScore(ltype);
            rCastScore = corto_valueExpr_getCastScore(rtype);

            /* If expression is an assignment, always take type of lvalue.
             * Otherwise determine based on expressibility score which type to
             * cast to. */
            if (corto_valueExpr_isOperatorAssignment(_operator)) {
                if (lCastScore == rCastScore) {
                    if (ltype->width != rtype->width) {
                        castType = leftType;
                    }
                } else {
                    castType = leftType;
                }
            } else {
                if (lCastScore == rCastScore) {
                    if (ltype->width == rtype->width) {
                        /* If width and kind are equal, no conversion is required. */
                        if (lscore > rscore) {
                            *operandType = leftType;
                        } else if (lscore < rscore) {
                            *operandType = rightType;
                        }
                    } else {
                        /* If lvalue has a larger width than rvalue, cast rvalue to leftType (and vice versa) */
                        if (ltype->width > rtype->width) {
                            castType = leftType;
                        } else {
                            castType = rightType;
                        }
                    }

                /* If kinds do not match figure a cast is potentially needed. Figure out which type to cast to */
                } else {
                    if (lscore > rscore) {
                        castType = leftType;
                    } else {
                        castType = rightType;
                    }
                }
            }
        } else if (leftType->reference && rightType->reference) {
            castType = NULL;
            /* Check if types are compatible */

        } else if ((rightType->reference || (t2ByRef)) && !leftType->reference) {
            if (corto_type_castable(leftType, corto_object_o)) {
                castType = leftType;
            }
        } else {
            corto_seterr("cannot cast from '%s' to '%s'",
                    corto_fullpath(NULL, leftType),
                    corto_fullpath(NULL, rightType));
            goto error;
        }
    } else if ((rightType->reference || (t2ByRef)) && !leftType->reference) {
        if (corto_type_castable(leftType, corto_object_o)) {
            castType = leftType;
        }
    }

    if (!castType) {
        castType = leftType;
    }
    if (castType) {
        *operandType = castType;
    }
    if (!*resultType) {
        *resultType = *operandType;
    }

    return 0;
error:
    return -1;
}

corto_int16 corto_value_unaryOperator(
    corto_operatorKind _operator,
    corto_value *value,
    corto_value *result)
{
    corto_uint64 *v = &result->is.value.storage;

    corto_type t = corto_value_getType(value);
    corto_type returnType = t;

    if (corto_valueExpr_isOperatorConditional(_operator)) {
        returnType = corto_type(corto_bool_o);
    }

    if (corto_unaryOperator(t, _operator, corto_value_getPtr(value), v)) {
        goto error;
    }

    result->kind = CORTO_VALUE;
    result->is.value.t = returnType;
    result->is.value.v = (void*)v;

    return 0;
error:
    return -1;
}

corto_int16 _corto_value_cast(
    corto_value *in,
    corto_type dstType,
    corto_value *out)
{
    void *dst = (void*)&out->is.value.storage;
    void *src = corto_value_getPtr(in);
    corto_type srcType = corto_value_getType(in);

    if (corto_convert(srcType, src, dstType, dst)) {
        goto error;
    }

    out->kind = CORTO_VALUE;
    out->is.value.v = (void*)&out->is.value.storage;
    out->is.value.t = dstType;

    return 0;
error:
    return -1;
}

corto_int16 corto_value_binaryOperator(
    corto_operatorKind _operator,
    corto_value *left,
    corto_value *right,
    corto_value *result)
{
    corto_uint64 *v = &result->is.value.storage;
    corto_type leftType = corto_value_getType(left);
    corto_type rightType = corto_value_getType(right);
    corto_value *lPtr = left, *rPtr = right;
    corto_type operType = NULL, returnType = NULL;

    if (corto_valueExpr_getTypeForBinary(leftType, FALSE, rightType, FALSE, _operator, &operType, &returnType)) {
        goto error;
    }

    corto_value leftCast, rightCast;
    if (leftType != operType) {
        if (corto_value_cast(left, operType, &leftCast)) {
            goto error;
        }
        lPtr = &leftCast;
    }
    if (rightType != operType) {
        if (corto_value_cast(right, operType, &rightCast)) {
            goto error;
        }
        rPtr = &rightCast;
    }

    if (corto_binaryOperator(
        operType,
        _operator,
        corto_value_getPtr(lPtr),
        corto_value_getPtr(rPtr),
        v))
    {
        goto error;
    }

    result->kind = CORTO_VALUE;
    result->is.value.t = returnType;
    result->is.value.v = (void*)v;

    return 0;
error:
    return -1;
}

void corto_value_free(corto_value *v) {
    corto_type t = NULL;
    switch(v->kind) {
    case CORTO_LITERAL:
    case CORTO_VALUE:
        t = corto_value_getType(v);
        break;
    default:
        break;
    }

    if (t) {
        void *ptr = corto_value_getPtr(v);
        corto_deinitp(ptr, t);
        if (v->kind == CORTO_VALUE) {
            if (ptr != (void*)&v->is.value.storage) {
                corto_dealloc(ptr);
            }
        }
    }
}
