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

corto_modifierMask corto_field_combine_modifiers(
    corto_modifierMask parent_modifiers,
    corto_modifierMask modifiers)
{
    modifiers |=
      (CORTO_READONLY|CORTO_CONST|CORTO_PRIVATE|CORTO_LOCAL) & parent_modifiers;
    return modifiers;
}

void* corto_field_get_value_ptr(
    corto_field *field,
    corto_type *type_out)
{
    corto_type type = field->type;
    void *ptr = field->ptr;
    corto_member member = field->member;

    if (corto_typeof(type) == (corto_type)corto_target_o) {
        corto_target target_type = (corto_target)type;
        bool owned = corto_owned(ptr);

        type = target_type->type;
        ptr = *(corto_object*)ptr;

        if (owned) {
            /* If target is owned, set 'actual', which is the first member */
        } else {
            /* If not owned, set 'target', which is the second member */
            ptr = CORTO_OFFSET(ptr, corto_type_sizeof(type));
        }
    } else if (member) {
        if (member->modifiers & CORTO_OPTIONAL) {
            ptr = *(void**)ptr;
        }
        if (member->modifiers & CORTO_OBSERVABLE) {
            ptr = *(corto_object*)ptr;
        }
    }

    if (type_out) {
        *type_out = type;
    }

    return ptr;
}

static
int16_t corto_get_element_ptr(
    corto_collection type,
    uint32_t index,
    void *ptr_inout)
{
    void *result = NULL;
    uint32_t max = 0;
    void *ptr = *(void**)ptr_inout;

    if (!ptr) {
        corto_throw("cannot take index from NULL");
        goto error;
    }

    switch(type->kind) {
    case CORTO_SEQUENCE:
        ptr = ((corto_objectseq*)ptr)->buffer;
        max = ((corto_objectseq*)ptr)->length;
    case CORTO_ARRAY: {
        uint32_t element_size = corto_type_sizeof(type->element_type);
        if (!max) max = type->max;
        if (index >= max) {
            corto_throw("index %d is out of bounds (%d) for array of type '%s'",
                index,
                max,
                corto_fullpath(NULL, type));
            goto error;
        }
        result = CORTO_OFFSET(ptr, element_size * index);
        break;
    }
    case CORTO_LIST: {
        corto_ll list = *(corto_ll*)ptr;
        if (index >= corto_ll_count(list)) {
            corto_throw("index %d is out of bounds (%d) for list of type '%s'",
              index,
              corto_ll_count(list),
              corto_fullpath(NULL, type));
            goto error;
        }

        if (corto_collection_requires_alloc(type->element_type)) {
            result = corto_ll_get(list, index);
        } else {
            result = corto_ll_getPtr(list, index);
        }
        break;
    }
    default:
        break;
    }

    *(void**)ptr_inout = result;

    return 0;
error:
    return -1;
}

#define MAX_CHARS_IN_INDEX (10)

static
const char* corto_is_elem_spec_digit(
    const char *ptr)
{
    char ch;
    uint32_t count = 0;
    for (; (ch = *ptr) && isdigit(ch); ptr ++) {
        count ++;
        if (count > MAX_CHARS_IN_INDEX) {
            corto_throw("too many characters in element index");
            goto error;
        }
    }

    if (!ch || ch != ']') {
        corto_throw("missing ']' for element index");
        goto error;
    }

    return ptr;
error:
    return NULL;
}

static
const char* corto_field_lookup_element(
    corto_type type,
    const char *field,
    void *ptr,
    corto_field *field_out)
{
    if (type->kind == CORTO_COLLECTION) {
        corto_collection collection_type = corto_collection(type);
        corto_collectionKind kind = corto_collection(type)->kind;

        if (kind != CORTO_MAP) {
            uint32_t index = atoi(field);

            if (!(field = corto_is_elem_spec_digit(field))) {
                corto_throw("expected integer in element index");
                goto error;
            }

            corto_try( corto_get_element_ptr(
                collection_type, index, &field_out->ptr), NULL);

            field_out->type = collection_type->element_type;
            field_out->index = index;
            field_out->member = NULL;
        }
    } else {
        corto_throw("cannot get element from non-collection type '%s'",
            corto_fullpath(NULL, type));
        goto error;
    }

    return field;
error:
    return NULL;
}

static
const char* corto_field_lookup_member(
    corto_type type,
    const char *field,
    void *ptr,
    bool nested_field,
    corto_field *field_out)
{
    corto_id buffer;
    char *buffer_ptr = buffer;
    char ch;

    if (type->kind != CORTO_COMPOSITE) {
        corto_throw("cannot obtain member from non-composite type '%s'",
            corto_fullpath(NULL, type));
        goto error;
    }

    if (!isalpha(*field) && *field != '_') {
        corto_throw(
            "invalid character '%c' at start of member identifier", *field);
        goto error;
    }

    for (; (ch = *field); field ++) {
        if (!isalpha(ch) && ch != '_' && !isdigit(ch)) {
            break;
        }

        if (buffer_ptr - buffer >= sizeof(buffer)) {
            corto_throw("member identifier is too long");
            goto error;
        }

        *buffer_ptr = ch;
        buffer_ptr ++;
    }

    *buffer_ptr = '\0';

    bool is_target = corto_typeof(type) == (corto_type)corto_target_o;
    corto_member prev_member = field_out->member;

    if (!strcmp(buffer, "super")) {
        /* Super can be used to refer to members of a base-interface */
        corto_interface base = corto_interface(type)->base;
        if (!base) {
            corto_throw(
              "super unpexpected: interface '%s' does not have a base",
                corto_fullpath(NULL, type));
            goto error;
        }

        field_out->type = (corto_type)base;
        field_out->member = NULL;
        field_out->index = -1;
        field_out->ptr = ptr;
        field_out->is_super = true;
        if (corto_instanceof(corto_struct_o, type)) {
            field_out->modifiers = corto_field_combine_modifiers(
                field_out->modifiers, corto_struct(type)->base_modifiers);
        }

    } else {
        /* If not super, lookup member in the type */
        corto_member m = corto_interface_resolve_member(type, buffer);
        if (!m) {
            corto_throw(
                "unresolved member '%s' in type '%s'",
                buffer,
                corto_fullpath(NULL, type));
            goto error;
        }

        field_out->type = m->type;
        field_out->member = m;
        field_out->index = -1;

        if (ptr) {
            /* If the expression passed to field_lookup is nested, and this
             * is a nested field, automatically dereference. Otherwise,
             * assume that the callee already dereferenced pointer. */
            if (prev_member && nested_field) {
                if (prev_member->modifiers & CORTO_OBSERVABLE) {
                    ptr = *(corto_object*)ptr;
                }
            }

            if (is_target) {
                bool remote_field = false;
                bool owned = corto_owned(ptr);

                remote_field = !strcmp(buffer, "target");

                if ((owned && remote_field) || (!owned && !remote_field)) {
                    /* If this is a remote field but the object is owned,
                     * the field should not be assigned */
                    field_out->modifiers |= CORTO_READONLY;
                }
            }

            field_out->ptr = CORTO_OFFSET(ptr, m->offset);
        } else {
            field_out->ptr = NULL;
        }

        field_out->is_super = false;
        field_out->modifiers = corto_field_combine_modifiers(
            field_out->modifiers, m->modifiers);
    }

    return field - 1;
error:
    return NULL;
}

int16_t _corto_field_lookup(
    const char *field,
    corto_type type,
    void *ptr,
    corto_field *field_out)
{
    char ch;
    int count = 0;

    field_out->type = type;
    field_out->ptr = ptr;
    field_out->index = -1;
    field_out->is_super = false;

    for (; (ch = *field); field ++) {
        if (ch == '[') {
            field = corto_field_lookup_element(
                field_out->type, field + 1, field_out->ptr, field_out);
        } else if (ch == '.' || isalpha(ch)) {
            if (ch == '.') {
                field ++;
            }
            field = corto_field_lookup_member(
                field_out->type, field, field_out->ptr, count != 0, field_out);
        }

        count ++;

        if (!field) {
            goto error;
        }
    }

    return 0;
error:
    return -1;
}

int16_t _corto_field_lookup_index(
    uint32_t index,
    corto_collection type,
    void *ptr,
    corto_field *field_out)
{
    void *ptr_param = ptr;

    corto_try (corto_get_element_ptr(type, index, &ptr_param), NULL);

    field_out->type = type->element_type;
    field_out->ptr = ptr_param;
    field_out->index = index;
    field_out->member = NULL;

    return 0;
error:
    return -1;
}
