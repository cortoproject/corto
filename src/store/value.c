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

corto_type corto_value_typeof(
    corto_value* val)
{
    corto_type result;

    switch(val->kind) {
    case CORTO_OBJECT:
        result = val->is.object.type;
        break;
    case CORTO_BASE:
        result = val->is.base.type;
        break;
    case CORTO_POINTER:
        result = val->is.pointer.type;
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
            corto_critical(
              "corto_value_typeof: invalid corto_literal_kind(%d)",
              val->is.literal.kind);
            result = NULL;
            break;
        }
        break;
    case CORTO_MEMBER:
        result = val->is.member.member->type;
        break;
    case CORTO_CONSTANT:
        result = corto_value_typeof(val->parent);
        break;
    case CORTO_ELEMENT:
        result = val->is.element.type;
        break;
    case CORTO_MAP_ELEMENT:
        result = val->is.map_element.type;
        break;
    default:
        corto_critical(
          "corto_value_typeof: invalid corto_value_kind(%d).", val->kind);
        result = NULL;
        break;
    }

    return result;
}

void* corto_value_ptrof(
    corto_value* val)
{
    void* result;
    switch(val->kind) {
    case CORTO_OBJECT:
        result = val->is.object.ref;
        break;
    case CORTO_BASE:
        result = val->is.base.ptr;
        break;
    case CORTO_LITERAL:
        if (val->is.literal.kind != CORTO_LITERAL_NULL) {
            result = &val->is.literal.as;
        } else {
            result = NULL;
        }
        break;
    case CORTO_POINTER:
        result = val->is.pointer.ptr;
        break;
    case CORTO_MEMBER:
        result = val->is.member.ptr;
        break;
    case CORTO_CONSTANT:
        result = val->is.constant.ptr;
        break;
    case CORTO_ELEMENT:
        result = val->is.element.ptr;
        break;
    case CORTO_MAP_ELEMENT:
        result = val->is.map_element.ptr;
        break;
    default:
        corto_critical(
          "corto_value_ptrof: invalid corto_value_kind(%d).", val->kind);
        result = NULL;
        break;
    }
    return result;
}

int16_t corto_value_ptrset(
    corto_value *val,
    void *ptr)
{
    switch(val->kind) {
    case CORTO_OBJECT:
        val->is.object.ref = ptr;
        break;
    case CORTO_BASE:
        val->is.base.ptr = ptr;
        break;
    case CORTO_POINTER:
        val->is.pointer.ptr = ptr;
        break;
    case CORTO_MEMBER:
        val->is.member.ptr = ptr;
        break;
    case CORTO_CONSTANT:
        val->is.constant.ptr = ptr;
        break;
    case CORTO_ELEMENT:
        val->is.element.ptr = ptr;
        break;
    case CORTO_MAP_ELEMENT:
        val->is.map_element.ptr = ptr;
        break;
    case CORTO_LITERAL:
        corto_throw("cannot set pointer for literal");
        goto error;
    default:
        corto_critical(
          "corto_value_ptrset: invalid corto_value_kind(%d).", val->kind);
        break;
    }
    return 0;
error:
    return -1;
}

corto_object corto_value_objectof(
    corto_value* val)
{
    corto_object result;

    switch(val->kind) {
    case CORTO_OBJECT:
        result = val->is.object.ref;
        break;
    case CORTO_BASE:
        result = val->is.base.ref;
        break;
    case CORTO_LITERAL:
        result = NULL;
        break;
    case CORTO_POINTER:
        result = val->is.pointer.ref;
        break;
    case CORTO_MEMBER:
        result = val->is.member.ref;
        break;
    case CORTO_CONSTANT:
        result = val->is.constant.ref;
        break;
    case CORTO_ELEMENT:
        result = val->is.element.ref;
        break;
    case CORTO_MAP_ELEMENT:
        result = val->is.map_element.ref;
        break;
    default:
        corto_critical(
          "corto_value_objectof: invalid corto_value_kind(%d).", val->kind);
        result = NULL;
        break;
    }

    return result;
}

int16_t corto_value_field(
    corto_value *val,
    const char* field_expr,
    corto_value *out)
{
    corto_type t = corto_value_typeof(val);
    corto_object o = corto_value_objectof(val);
    void *ptr = corto_value_ptrof(val);

    corto_field field = {0};

    corto_try(corto_field_lookup(field_expr, t, ptr, &field), NULL);

    if (field.index != -1) {
        *out = corto_value_element(o, field.type, field.index, field.ptr);
    } else if (!field.member) {
        if (o == ptr) {
            *out = corto_value_base(field.ptr, field.type);
        } else {
            /* super member of a nested sub-struct */
            *out = corto_value_pointer(field.ptr, field.type);
        }
    } else {
        *out = corto_value_member(o, field.member, field.ptr);
    }

    return 0;
error:
    return -1;
}

corto_value _corto_value_object(
    corto_object o,
    corto_type t)
{
    corto_value val = {
        .kind = CORTO_OBJECT,
        .ref_kind = CORTO_BY_TYPE,
        .parent = NULL,
        .is.object.ref = o,
        .is.object.type = t ? t : corto_typeof(o)
    };

    return val;
}

corto_value _corto_value_base(
    void *v,
    corto_type t)
{
    corto_value val = {
        .kind = CORTO_BASE,
        .ref_kind = CORTO_BY_TYPE,
        .parent = NULL,
        .is.base.ref = v,
        .is.base.type = t,
        .is.base.ptr = v
    };

    return val;
}

corto_value _corto_value_pointer(
    void* v,
    corto_type t)
{
    corto_value val = {
        .kind = CORTO_POINTER,
        .ref_kind = CORTO_BY_TYPE,
        .parent = NULL,
        .is.pointer.storage = 0,
        .is.pointer.ref = NULL,
        .is.pointer.type = t,
        .is.pointer.ptr = v
    };

    return val;
}

corto_value _corto_value_ptr(
    void* v,
    corto_type t)
{
    corto_value val = _corto_value_pointer(v, t);
    val.ref_kind = CORTO_BY_TYPE;
    return val;
}

corto_value _corto_value_mem(
    void* v,
    corto_type t)
{
    corto_value val = _corto_value_pointer(v, t);
    val.ref_kind = CORTO_BY_VALUE;
    return val;
}

corto_value corto_value_member(
    corto_object o,
    corto_member t,
    void* v)
{
    corto_value val = {
        .kind = CORTO_MEMBER,
        .ref_kind = CORTO_BY_TYPE,
        .parent = NULL,
        .is.member.ref = o,
        .is.member.member = t,
        .is.member.ptr = v
    };

    return val;
}

corto_value corto_value_constant(
    corto_object o,
    corto_constant* t,
    void* v)
{
    corto_value val = {
        .kind = CORTO_CONSTANT,
        .ref_kind = CORTO_BY_TYPE,
        .parent = NULL,
        .is.constant.ref = o,
        .is.constant.constant = t,
        .is.constant.ptr = v
    };

    return val;
}

corto_value _corto_value_element(
    corto_object o,
    corto_type t,
    uint32_t index,
    void* v)
{
    corto_value val = {
        .kind = CORTO_ELEMENT,
        .ref_kind = CORTO_BY_TYPE,
        .parent = NULL,
        .is.element.ref = o,
        .is.element.type = t,
        .is.element.index = index,
        .is.element.ptr = v
    };

    return val;
}

corto_value _corto_value_mapElement(
    corto_object o,
    corto_type t,
    corto_type keyType,
    void *key,
    void* v)
{
    corto_value val = {
        .kind = CORTO_ELEMENT,
        .ref_kind = CORTO_BY_TYPE,
        .parent = NULL,
        .is.map_element.ref = o,
        .is.map_element.type = t,
        .is.map_element.key_type = keyType,
        .is.map_element.key = key,
        .is.map_element.ptr = v
    };

    return val;
}

corto_value corto_value_literal(
    corto_literal_kind kind,
    void* value)
{
    corto_value val = {
        .kind = CORTO_LITERAL,
        .ref_kind = CORTO_BY_TYPE,
        .is.literal.kind = kind,
        .parent = NULL
    };

    switch(kind) {
    case CORTO_LITERAL_BOOLEAN:
        val.is.literal.as._boolean = *(corto_bool*)value;
        break;
    case CORTO_LITERAL_CHARACTER:
        val.is.literal.as._character = *(corto_char*)value;
        break;
    case CORTO_LITERAL_INTEGER:
        val.is.literal.as._integer = *(corto_int64*)value;
        break;
    case CORTO_LITERAL_UNSIGNED_INTEGER:
        val.is.literal.as._unsigned_integer = *(corto_uint64*)value;
        break;
    case CORTO_LITERAL_FLOATING_POINT:
        val.is.literal.as._floating_point = *(corto_float64*)value;
        break;
    case CORTO_LITERAL_STRING:
        if (*(corto_string*)value) {
            val.is.literal.as._string = corto_strdup(*(corto_string*)value);
        } else {
            val.is.literal.as._string = NULL;
        }
        break;
    case CORTO_LITERAL_NULL:
        break;
    }
    return val;
}

corto_value corto_value_bool(
    corto_bool value)
{
    return corto_value_literal(CORTO_LITERAL_BOOLEAN, &value);
}

corto_value corto_value_char(
    corto_char value)
{
    return corto_value_literal(CORTO_LITERAL_CHARACTER, &value);
}

corto_value corto_value_int(
    corto_uint64 value)
{
    return corto_value_literal(CORTO_LITERAL_INTEGER, &value);
}

corto_value corto_value_uint(
    corto_uint64 value)
{
    return corto_value_literal(CORTO_LITERAL_UNSIGNED_INTEGER, &value);
}

corto_value corto_value_float(
    corto_float64 value)
{
    return corto_value_literal(CORTO_LITERAL_FLOATING_POINT, &value);
}

corto_value corto_value_string(
    corto_string value)
{
    return corto_value_literal(CORTO_LITERAL_STRING, &value);
}

corto_value corto_value_null(void)
{
    return corto_value_literal(CORTO_LITERAL_NULL, NULL);
}

int16_t corto_value_unaryOp(
    corto_operatorKind _operator,
    corto_value *value,
    corto_value *result)
{
    corto_uint64 *v = &result->is.pointer.storage;

    corto_type t = corto_value_typeof(value);
    corto_type returnType = t;

    if (corto_operator_is_conditional(_operator)) {
        returnType = corto_type(corto_bool_o);
    }

    if (corto_ptr_unaryOp(t, _operator, corto_value_ptrof(value), v)) {
        goto error;
    }

    result->kind = CORTO_POINTER;
    result->is.pointer.type = returnType;
    result->is.pointer.ptr = (void*)v;

    return 0;
error:
    return -1;
}

corto_value corto_value_init(void) {
    corto_value v;
    memset(&v, 0, sizeof(corto_value));
    v.kind = CORTO_POINTER;
    v.ref_kind = CORTO_BY_TYPE;
    return v;
}

void corto_value_free(
    corto_value *v)
{
    corto_type t = NULL;
    switch(v->kind) {
    case CORTO_LITERAL:
    case CORTO_POINTER:
        t = corto_value_typeof(v);
        break;
    default:
        break;
    }

    if (t) {
        void *ptr = corto_value_ptrof(v);
        corto_ptr_deinit(ptr, t);
        if (v->kind == CORTO_POINTER) {
            if (ptr != (void*)&v->is.pointer.storage) {
                if (v->is.pointer.owned) {
                    corto_dealloc(ptr);
                }
            }
        }
    }
    *v = corto_value_init();
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
    corto_walk_opt s = corto_copy_ser(
      CORTO_PRIVATE, CORTO_NOT, CORTO_WALK_TRACE_ON_FAIL);
    corto_copy_ser_t data;
    int16_t result;
    corto_bool newObject = FALSE;

    if (!corto_value_ptrof(dst)) {
        corto_type t = corto_value_typeof(src);
        *dst = corto_value_ptr(corto_declare(NULL, NULL, t), t);
        newObject = TRUE;
    }

    data.value = *dst;
    result = corto_walk_value(&s, src, &data);

    if (newObject) {
        corto_define(corto_value_ptrof(dst));
    }

    return result;
}

int16_t corto_value_to_boolean(
    corto_value *value,
    bool *out)
{
    corto_value result = corto_value_init();

    if (corto_value_cast(value, corto_bool_o, &result)) {
        return -1;
    }

    *out = *(bool*)corto_value_ptrof(&result);

    return 0;
}

int16_t corto_value_to_character(
    corto_value *value,
    char *out)
{
    corto_value result = corto_value_init();

    if (corto_value_cast(value, corto_char_o, &result)) {
        return -1;
    }

    *out = *(char*)corto_value_ptrof(&result);

    return 0;
}

int16_t corto_value_to_int(
    corto_value *value,
    int64_t *out)
{
    corto_value result = corto_value_init();

    if (corto_value_cast(value, corto_int64_o, &result)) {
        return -1;
    }

    *out = *(int64_t*)corto_value_ptrof(&result);

    return 0;
}

int16_t corto_value_to_uint(
    corto_value *value,
    uint64_t *out)
{
    corto_value result = corto_value_init();

    if (corto_value_cast(value, corto_uint64_o, &result)) {
        return -1;
    }

    *out = *(uint64_t*)corto_value_ptrof(&result);

    return 0;
}

int16_t corto_value_to_float(
    corto_value *value,
    double *out)
{
    corto_value result = corto_value_init();

    if (corto_value_cast(value, corto_float64_o, &result)) {
        return -1;
    }

    *out = *(double*)corto_value_ptrof(&result);

    return 0;
}

int16_t corto_value_to_string(
    corto_value *value,
    char **out)
{
    corto_value result = corto_value_init();

    if (corto_value_cast(value, corto_string_o, &result)) {
        return -1;
    }

    *out = *(char**)corto_value_ptrof(&result);

    return 0;
}

int16_t corto_value_unit(
    corto_value *value,
    char *unit)
{
    if (value->kind == CORTO_POINTER) {
        value->is.pointer.unit = unit;
    } else if (value->kind == CORTO_LITERAL) {
        value->is.literal.unit = unit;
    } else {
        corto_throw("cannot set unit of non-literal value");
        goto error;
    }

    return 0;
error:
    return -1;
}

char* corto_value_unitof(
    corto_value *value)
{
    char *result = NULL;

    switch(value->kind) {
    case CORTO_OBJECT:
    case CORTO_BASE:
    case CORTO_CONSTANT:
    case CORTO_ELEMENT:
    case CORTO_MAP_ELEMENT:
        result = NULL;
        break;
    case CORTO_LITERAL:
        result = value->is.literal.unit;
        break;
    case CORTO_POINTER:
        result = value->is.pointer.unit;
        break;
    case CORTO_MEMBER:
        if (value->is.member.member->unit) {
            result = value->is.member.member->unit->symbol;
        }
        break;
    default:
        corto_critical(
            "corto_value_unitof: invalid corto_value_kind (%d)", value->kind);
        result = NULL;
        break;
    }

    return result;
}

static
bool corto_is_ref_container(
    corto_type type)
{
    return type &&
        ((type->kind == CORTO_VOID && type->reference) ||
        (type->kind == CORTO_COMPOSITE &&
            corto_interface(type)->kind == CORTO_INTERFACE));
}

int16_t corto_value_is_ref(
    corto_value *v,
    bool *result)
{
    return corto_expr_is_ref(
        v->kind, v->ref_kind, corto_value_typeof(v), result);
}

int16_t _corto_value_cast(
    corto_value *in,
    corto_type dst_type,
    corto_value *out)
{
    void *dst = (void*)&out->is.pointer.storage;
    void *src = corto_value_ptrof(in);
    corto_type src_type = corto_value_typeof(in);
    bool dst_is_refcontainer = corto_is_ref_container(dst_type);
    bool dst_is_bool = dst_type->kind == CORTO_PRIMITIVE &&
        corto_primitive(dst_type)->kind == CORTO_BOOLEAN;
    bool src_is_ref = false;
    corto_try(corto_value_is_ref(in, &src_is_ref), NULL);

    if ((!src || src_is_ref) && dst_is_bool) {
        if (src) {
            *out = corto_value_bool(true);
        } else {
            *out = corto_value_bool(false);
        }
    } else
    if (dst_is_refcontainer ||
        (corto_type_instanceof(dst_type, src_type) && src_is_ref))
    {
        bool any_ref = dst_type->kind == CORTO_VOID && dst_type->reference;
        if ((any_ref && src_is_ref) || corto_type_castable(dst_type, src_type))
        {
            if (in->kind == CORTO_OBJECT) {
                *out = corto_value_object(src, dst_type);
            } else {
                *out = corto_value_pointer(src, dst_type);
            }
        } else {
            corto_throw("cannot cast from '%s%s' to '%s'",
                corto_fullpath(NULL, src_type), src_is_ref ? "&" : "",
                corto_fullpath(NULL, dst_type));
            goto error;
        }
    } else {
        void *src_addr;
        void *src_ptr = src;

        if (in->kind == CORTO_OBJECT && src_is_ref) {
            src_addr = src;
            src_ptr = &src_addr;
        }

        if (corto_ptr_cast(src_type, src_ptr, dst_type, dst)) {
            goto error;
        }

        out->kind = CORTO_POINTER;
        out->ref_kind = CORTO_BY_TYPE;
        out->is.pointer.ptr = (void*)&out->is.pointer.storage;
        out->is.pointer.type = dst_type;
    }

    return 0;
error:
    return -1;
}

int16_t corto_value_binaryOp(
    corto_operatorKind _operator,
    corto_value *left,
    corto_value *right,
    corto_value *result)
{
    corto_value
        dummy = corto_value_init(),
        *left_casted = left,
        *right_casted = right;

    corto_type
        left_type = corto_value_typeof(left),
        right_type = corto_value_typeof(right),
        oper_type = NULL,
        result_type = NULL;

    corto_ref_kind
        left_ref_kind = left->ref_kind,
        right_ref_kind = right->ref_kind;

    corto_value left_val, right_val;
    bool is_assignment = _operator == CORTO_ASSIGN;

    uintptr_t *result_ptr = NULL;
    bool use_left_as_result = false;
    bool result_owned = false;

    bool left_isref, right_isref, right_isnull = !corto_value_ptrof(right) ||
        (right->kind == CORTO_LITERAL &&
         right->is.literal.kind == CORTO_LITERAL_NULL);

    bool left_is_refcontainer = corto_is_ref_container(left_type);

    if (is_assignment) {
        if (left->kind == CORTO_OBJECT) {
            if (left->ref_kind == CORTO_BY_REFERENCE) {
                corto_throw("cannot assign objects as reference");
                goto error;
            } else {
                /* If operation is an assignment and left operand is an object,
                 * assign by value unless BY_REFERENCE is explicitly set */
                left_ref_kind = CORTO_BY_VALUE;
            }
        }

        if (left_type->reference &&
            left_ref_kind == CORTO_BY_VALUE && right_isnull)
        {
            corto_throw("cannot assign null to value of reference");
            goto error;
        }

        /* If the left type kind is a reference container, the default for the
         * right value reference kind is BY_REFERENCE */
        if (left_is_refcontainer && right_ref_kind == CORTO_BY_TYPE) {
            right_ref_kind = CORTO_BY_REFERENCE;
        }

        /* If right operand is BY_TYPE and is of a reference type, and the type
         * of the right operand is an instance of the type of the left operand,
         * and the left operand is BY_VALUE, the right operand ref_kind will
         * change to BY_VALUE as well. */
        else
        if (right_ref_kind == CORTO_BY_TYPE &&
            left_ref_kind == CORTO_BY_VALUE &&
            left_type && right_type &&
            corto_type_instanceof(left_type, right_type))
        {
            right_ref_kind = CORTO_BY_VALUE;
        }

        left_val = *left;
        right_val = *right;
        left_val.ref_kind = left_ref_kind;
        right_val.ref_kind = right_ref_kind;
        left = &left_val;
        right = &right_val;
    }

    /* Is left operand a reference */
    corto_try (corto_value_is_ref(left, &left_isref), NULL);

    /* Is right operand a reference? */
    corto_try (corto_value_is_ref(right, &right_isref), NULL);

    /* Determine type of binary expression and types to cast operands to */
    if (!result ||
        ((result->kind == CORTO_POINTER) ||
        (result->kind == CORTO_LITERAL) ||
        !corto_value_ptrof(result)))
    {
        /* If result is not provided, use types of operands */
        corto_try (corto_expr_binary_typeof(
            left_type,
            left_isref,
            right_type,
            right_isref,
            _operator,
            &oper_type,
            &result_type), NULL);
    } else {
        /* If result is required, cast operands to result type */
        result_type = corto_value_typeof(result);
        corto_try (corto_expr_binary_typeof(
            result_type,
            left_isref,
            result_type,
            right_isref,
            _operator,
            &oper_type,
            &result_type), NULL);
    }

    /* Cast left operand */
    if (!left_type) {
        left_type = oper_type;
        left_isref = right_isref;
    } else
    if (left_type != oper_type) {
        if (corto_value_cast(left, oper_type, &left_val)) {
            goto error;
        }
        left_casted = &left_val;
        corto_try(corto_value_is_ref(left_casted, &left_isref), NULL);
        left_type = oper_type;
    }

    /* Cast right operand */
    if (!right_type) {
        right_type = oper_type;
        right_isref = left_isref;
    } else
    if (right_type != oper_type ||
       (is_assignment && right_isref && !left_isref))
    {
        if (corto_value_cast(right, oper_type, &right_val)) {
            goto error;
        }
        right_casted = &right_val;
        corto_try(corto_value_is_ref(right_casted, &right_isref), NULL);
        right_type = oper_type;
    }

    /* Test if operands are either by_reference or by_value */
    if (left_isref != right_isref) {
        if (left_isref && right_type) {
            corto_throw(
                "left operand is by reference but right operand is by value");
            goto error;
        } else
        if (right_isref && left_type && !left_is_refcontainer) {
            corto_throw(
                "right operand is by reference but left operand is by value");
            goto error;
        }
    }

    void *left_ptr = corto_value_ptrof(left_casted), *left_arg = left_ptr;
    void *right_ptr = corto_value_ptrof(right_casted), *right_arg = right_ptr;

    if (left->kind == CORTO_OBJECT && left_isref) {
        left_arg = &left_ptr;
    }
    if (right->kind == CORTO_OBJECT && right_isref) {
        right_arg = &right_ptr;
    }
    if (left->kind != CORTO_OBJECT &&
        left_type &&
        left_type->reference &&
        !left_isref)
    {
        left_arg = left_ptr ? *(corto_object*)left_ptr : NULL;
    }
    if (right->kind != CORTO_OBJECT &&
        right_type &&
        right_type->reference &&
        !right_isref)
    {
        right_arg = right_ptr ? *(corto_object*)right_ptr : NULL;
    }

    /* Get pointer for storing the result */
    if (result) {
        if (result->kind != CORTO_LITERAL) {
            result_ptr = corto_value_ptrof(result);
            if (!result_ptr) {
                if (!result_type || result_type->kind == CORTO_PRIMITIVE) {
                    result_ptr = &result->is.pointer.storage;
                } else {
                    if (_operator == CORTO_ASSIGN) {
                        use_left_as_result = true;
                    } else {
                        /* If result value is provided, but it does not contain
                         * a pointer that can hold the result value, allocate
                         * memory */
                        result_ptr = corto_calloc(result_type->size);
                    }
                }
                result_owned = true;
            }
        } else {
            result_ptr = &result->is.pointer.storage;
            result_owned = true;
        }
    } else if (result_type->kind == CORTO_PRIMITIVE) {
        result_ptr = &dummy.is.pointer.storage;
        result_owned = true;
    }

    /* Perform operation */
    if (left_isref) {
        /* If this is a reference operation, use ptr with a reference type */
        corto_try (corto_ptr_binaryOp(
            corto_object_o, _operator, left_arg, right_arg, result_ptr), NULL);
    } else {
        /* If this is a value operation, use mem with original type */
        corto_try (corto_mem_binaryOp(
            oper_type, _operator, left_arg, right_arg, result_ptr), NULL);
    }

    /* Populate result value */
    if (result && ((result->kind == CORTO_POINTER) ||
        (result->kind == CORTO_LITERAL)))
    {
        result->kind = CORTO_POINTER;
        result->is.pointer.type = result_type;
        result->is.pointer.owned = result_owned;

        if (use_left_as_result) {
            if (result_type->reference) {
                result->is.pointer.storage = (uintptr_t)left_arg;
                result->is.pointer.ptr = &result->is.pointer.storage;
            } else {
                result->is.pointer.ptr = left_arg;
            }
        } else if (result_type && result_type->reference) {
            result->is.pointer.storage = *(uintptr_t*)result_ptr;
            result->is.pointer.ptr = &result->is.pointer.storage;
        } else {
            result->is.pointer.ptr = result_ptr;
        }
    }

    corto_value_free(&dummy);

    return 0;
error:
    return -1;
}
