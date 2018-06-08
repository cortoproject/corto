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
        uint32_t element_size = corto_type_sizeof(type->elementType);
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

        if (corto_collection_requiresAlloc(type->elementType)) {
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

            field_out->type = collection_type->elementType;
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

    } else {
        /* If not super, lookup member in the type */
        corto_member m = corto_interface_resolveMember(type, buffer);
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
            field_out->ptr = CORTO_OFFSET(ptr, m->offset);
        } else {
            field_out->ptr = NULL;
        }
        field_out->is_super = false;
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
                field_out->type, field, field_out->ptr, field_out);
        }

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

    field_out->type = type->elementType;
    field_out->ptr = ptr_param;
    field_out->index = index;
    field_out->member = NULL;

    return 0;
error:
    return -1;
}
