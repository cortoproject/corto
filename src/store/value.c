/* Copyright (c) 2010-2018 the corto developers
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include <corto/corto.h>

#include "object.h"
#include "compare_ser.h"
#include "copy_ser.h"
#include "init_ser.h"

corto_type corto_value_typeof(corto_value* val) {
    corto_type result;

    switch(val->kind) {
    case CORTO_OBJECT:
        result = val->is.object.t;
        break;
    case CORTO_BASE:
        result = val->is.base.t;
        break;
    case CORTO_VALUE:
    case CORTO_MEM:
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
            corto_critical("corto_value_typeof: invalid corto_literalKind(%d)", val->is.literal.kind);
            result = NULL;
            break;
        }
        break;
    case CORTO_MEMBER:
        result = val->is.member.t->type;
        break;
    case CORTO_CONSTANT:
        result = corto_value_typeof(val->parent);
        break;
    case CORTO_ELEMENT:
        result = val->is.element.t.type;
        break;
    case CORTO_MAP_ELEMENT:
        result = val->is.mapElement.t.type;
        break;
    default:
        corto_critical("corto_value_typeof: invalid corto_valueKind(%d).", val->kind);
        result = NULL;
        break;
    }

    return result;
}

corto_void* corto_value_ptrof(corto_value* val) {
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
    case CORTO_MEM:
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
        corto_critical("corto_value_ptrof: invalid corto_valueKind(%d).", val->kind);
        result = NULL;
        break;
    }
    return result;
}

corto_int16 corto_value_ptrset(corto_value *val, void *ptr) {
    switch(val->kind) {
    case CORTO_OBJECT:
        val->is.object.o = ptr;
        break;
    case CORTO_BASE:
        val->is.base.v = ptr;
        break;
    case CORTO_VALUE:
    case CORTO_MEM:
        val->is.value.v = ptr;
        break;
    case CORTO_MEMBER:
        val->is.member.v = ptr;
        break;
    case CORTO_CONSTANT:
        val->is.constant.v = ptr;
        break;
    case CORTO_ELEMENT:
        val->is.element.v = ptr;
        break;
    case CORTO_MAP_ELEMENT:
        val->is.mapElement.v = ptr;
        break;
    case CORTO_LITERAL:
        corto_throw("cannot set pointer for literal");
        goto error;
    default:
        corto_critical("corto_value_ptrset: invalid corto_valueKind(%d).", val->kind);
        break;
    }
    return 0;
error:
    return -1;
}

corto_object corto_value_objectof(corto_value* val) {
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
    case CORTO_MEM:
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
        corto_critical("corto_value_objectof: invalid corto_valueKind(%d).", val->kind);
        result = NULL;
        break;
    }
    return result;
}

corto_int16 corto_value_memberExpr(corto_value *val, corto_string member, corto_value *out) {
    corto_type t = corto_value_typeof(val);
    corto_object o = corto_value_objectof(val);
    void *ptr = corto_value_ptrof(val);

    corto_id tokens;
    strncpy(tokens, member, sizeof(corto_id));

    char *cur = tokens, *prev = tokens;
    do {
        if (cur && (cur = strchr(cur + 1, '.'))) *cur = '\0';

        if (!corto_instanceof(corto_interface_o, t)) {
            corto_throw(
                "cannot get member from a non-composite value (type is '%s')",
                corto_fullpath(NULL, t));
            goto error;
        }

        if (!strcmp(prev, "super")) {
            if (!(t = (corto_type)corto_interface(t)->base)) {
                corto_throw("super unpexpected: interface '%s' does not have a base",
                    corto_fullpath(NULL, t));
                goto error;
            } else {
                *out = corto_value_base(ptr, t);
            }
        } else {
            corto_member m = corto_interface_resolveMember(t, prev);
            if (!m) {
                corto_throw(
                    "unresolved member '%s' in type '%s'",
                    prev,
                    corto_fullpath(NULL, t));
                goto error;
            }

            ptr = CORTO_OFFSET(ptr, m->offset);
            t = m->type;

            *out = corto_value_member(o, m, ptr);
        }

        prev = cur + 1;
    } while (cur);

    return 0;
error:
    return -1;
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

corto_value _corto_value_base(void *v, corto_type t) {
    corto_value val;
    val.kind = CORTO_BASE;
    val.parent = NULL;
    val.is.base.v = v;
    val.is.base.t = t;
    return val;
}

corto_value _corto_value_value(void* v, corto_type t) {
    corto_value val;
    val.kind = CORTO_VALUE;
    val.parent = NULL;
    val.is.value.storage = 0;
    val.is.value.o = NULL;
    val.is.value.t = t;
    val.is.value.v = v;
    return val;
}

corto_value _corto_value_mem(void* v, corto_type t) {
    corto_value val = _corto_value_value(v, t);
    val.kind = CORTO_MEM;
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

corto_value corto_value_bool(corto_bool value) {
    return corto_value_literal(CORTO_LITERAL_BOOLEAN, &value);
}
corto_value corto_value_char(corto_char value) {
    return corto_value_literal(CORTO_LITERAL_CHARACTER, &value);
}
corto_value corto_value_int(corto_uint64 value) {
    return corto_value_literal(CORTO_LITERAL_INTEGER, &value);
}
corto_value corto_value_uint(corto_uint64 value) {
    return corto_value_literal(CORTO_LITERAL_UNSIGNED_INTEGER, &value);
}
corto_value corto_value_float(corto_float64 value) {
    return corto_value_literal(CORTO_LITERAL_FLOATING_POINT, &value);
}
corto_value corto_value_string(corto_string value) {
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
    case CORTO_VALUE:
    case CORTO_MEM:
        val->is.value.v = v; // ??
        break;
    default:
        corto_assert(0, "corto_valueSetValue: invalid valueKind %d.", val->kind);
        break;
    }
}

corto_int16 corto_value_unaryOp(
    corto_operatorKind _operator,
    corto_value *value,
    corto_value *result)
{
    corto_uint64 *v = &result->is.value.storage;

    corto_type t = corto_value_typeof(value);
    corto_type returnType = t;

    if (corto_operator_is_conditional(_operator)) {
        returnType = corto_type(corto_bool_o);
    }

    if (corto_ptr_unaryOp(t, _operator, corto_value_ptrof(value), v)) {
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
    void *src = corto_value_ptrof(in);
    corto_type srcType = corto_value_typeof(in);

    if (corto_ptr_cast(srcType, src, dstType, dst)) {
        goto error;
    }

    out->kind = CORTO_VALUE;
    out->is.value.v = (void*)&out->is.value.storage;
    out->is.value.t = dstType;

    return 0;
error:
    return -1;
}

corto_int16 corto_value_binaryOp(
    corto_operatorKind _operator,
    corto_value *left,
    corto_value *right,
    corto_value *result)
{
    corto_value dummy = corto_value_empty();
    corto_uint64 *v = &dummy.is.value.storage;
    corto_type leftType = corto_value_typeof(left);
    corto_type rightType = corto_value_typeof(right);
    corto_value *lPtr = left, *rPtr = right;
    corto_type operType = NULL, returnType = NULL;

    if (result) {
        v = corto_value_ptrof(result);
        if (!v) {
            v = &result->is.value.storage;
        }
    }

    if (!result || ((result->kind == CORTO_VALUE) || (result->kind == CORTO_LITERAL) || !corto_value_ptrof(result))) {
        if (corto_expr_binary_typeof(leftType, FALSE, rightType, FALSE, _operator, &operType, &returnType)) {
            goto error;
        }
    } else {
        corto_type resultType = corto_value_typeof(result);
        if (corto_expr_binary_typeof(resultType, FALSE, resultType, FALSE, _operator, &operType, &returnType)) {
            goto error;
        }
    }

    corto_value leftCast = corto_value_empty(), rightCast = corto_value_empty();
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

    if (corto_ptr_binaryOp(
        operType,
        _operator,
        corto_value_ptrof(lPtr),
        corto_value_ptrof(rPtr),
        v))
    {
        goto error;
    }

    if (result && ((result->kind == CORTO_VALUE) || (result->kind == CORTO_LITERAL))) {
        result->is.value.storage = *(corto_uint64*)v;
        result->kind = CORTO_VALUE;
        result->is.value.t = returnType;
        result->is.value.v = &result->is.value.storage;
    }

    corto_value_free(&dummy);

    return 0;
error:
    return -1;
}

corto_value corto_value_empty(void) {
    corto_value v;
    memset(&v, 0, sizeof(corto_value));
    v.kind = CORTO_VALUE;
    return v;
}

void corto_value_free(corto_value *v) {
    corto_type t = NULL;
    switch(v->kind) {
    case CORTO_LITERAL:
    case CORTO_VALUE:
    case CORTO_MEM:
        t = corto_value_typeof(v);
        break;
    default:
        break;
    }

    if (t) {
        void *ptr = corto_value_ptrof(v);
        corto_ptr_deinit(ptr, t);
        if (v->kind == CORTO_VALUE) {
            if (ptr != (void*)&v->is.value.storage) {
                corto_dealloc(ptr);
            }
        }
    }
    *v = corto_value_empty();
}

int16_t corto_value_compare(
    corto_value *dst,
    corto_value *src)
{
    corto_compare_ser_t data;
    corto_walk_opt s;

    data.value = *dst;
    s = corto_compare_ser(CORTO_PRIVATE, CORTO_NOT, CORTO_WALK_TRACE_NEVER);

    corto_walk_value(&s, src, &data);

    return data.result;
}

int16_t corto_value_copy(
    corto_value *dst,
    corto_value *src)
{
    corto_walk_opt s = corto_copy_ser(CORTO_PRIVATE, CORTO_NOT, CORTO_WALK_TRACE_ON_FAIL);
    corto_copy_ser_t data;
    corto_int16 result;
    corto_bool newObject = FALSE;

    if (!corto_value_ptrof(dst)) {
        corto_type t = corto_value_typeof(src);
        *dst = corto_value_value(corto_declare(NULL, NULL, t), t);
        newObject = TRUE;
    }

    data.value = *dst;
    result = corto_walk_value(&s, src, &data);

    if (newObject) {
        corto_define(corto_value_ptrof(dst));
    }

    return result;
}
