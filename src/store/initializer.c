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

corto_initializer corto_initializer_init(
    corto_type type,
    void *ptr)
{
    corto_initializer result = {
        .root_scope.type = type,
        .root_scope.offset = ptr,
        .current = &result.root_scope
    };

    return result;
}

void corto_initializer_deinit(
    corto_initializer *this)
{
}


static
int16_t corto_scope_cache_member(
    corto_walk_opt *opt,
    corto_value *value,
    void *members)
{
    /* Simply append members for the current type-scope. Nested type-scopes will
     * be collected once the initializer moves to another scope. */
    corto_ll_append(members, value->is.member.member);
    return 0;
}

static
int16_t corto_scope_cache_build(
    corto_initializer *this)
{
    /* Initializer order is determined by taking all non-private, non-readonly
     * non-local and non-hidden members. */
    corto_walk_opt opt = {
        .access = CORTO_PRIVATE | CORTO_READONLY | CORTO_HIDDEN | CORTO_LOCAL,
        .accessKind = CORTO_NOT,
        .aliasAction = CORTO_WALK_ALIAS_FOLLOW,
        .optionalAction = CORTO_WALK_OPTIONAL_ALWAYS,
        .metaprogram[CORTO_MEMBER] = corto_scope_cache_member
    };

    /* Collect members in temporary linked list so we have O(1) appends */
    corto_ll members = corto_ll_new();

    /* Walk over metadata */
    corto_try(corto_metawalk(&opt, this->current->type, members), NULL);

    this->current->max_index = corto_ll_count(members);
    this->current->cache = corto_calloc(
        sizeof(corto_member) * this->current->max_index);

    /* Store members in contiguous array so we have O(1) read access */
    uint32_t count = 0;
    corto_iter it = corto_ll_iter(members);
    while (corto_iter_hasNext(&it)) {
        this->current->cache[count ++].member = corto_iter_next(&it);
    }

    corto_ll_free(members);
    return 0;
error:
    corto_ll_free(members);
    return -1;
}

int16_t corto_initializer_index(
    corto_initializer *this,
    uint32_t index)
{
    corto_type type = corto_initializer_get_scope_type(this);
    if (!type) {
        goto error;
    }

    if (type->kind == CORTO_COMPOSITE) {
        if (!this->current->cache) {
            corto_try (corto_scope_cache_build(this), NULL);
        }

        if (index > this->current->max_index) {
            corto_throw("index %d exceeds number of members in composite value",
              index);
            goto error;
        }

        this->current->member =
            this->current->cache[this->current->index - 1].member;
    } else {
        if (this->current->index >= corto_collection(type)->max) {
            corto_throw("index %d exceeds maximum collection length", index);
            goto error;
        }
    }

    this->current->index = index;

    return 0;
error:
    return -1;
}

int16_t corto_initializer_next(
    corto_initializer *this)
{
    corto_try(corto_initializer_index(this, this->current->index + 1), NULL);

    return 0;
error:
    return -1;
}

int16_t corto_initializer_field(
    corto_initializer *this,
    const char *field_expr)
{
    corto_type type = corto_initializer_get_scope_type(this);
    if (!type) {
        goto error;
    }

    corto_field field = {0};

    corto_try(corto_field_lookup(
        field_expr,
        type,
        this->current->offset,
        &field
    ), NULL);

    this->current->ptr = field.ptr;
    this->current->member = field.member;

    if (field.index != -1) {
        this->current->index = field.index;
    }

    return 0;
error:
    return -1;
}

int16_t corto_initializer_push(
    corto_initializer *this)
{
    corto_type type = corto_initializer_get_scope_type(this);
    if (!type) {
        goto error;
    }

    return 0;
error:
    return -1;
}

int16_t corto_initializer_pop(
    corto_initializer *this);

corto_type corto_initializer_get_type(
    corto_initializer *this);

corto_type corto_initializer_get_scope_type(
    corto_initializer *this)
{
    return this->current->type;
}

corto_member corto_initializer_get_member(
    corto_initializer *this);

uint32_t corto_initializer_get_index(
    corto_initializer *this);

uintptr_t corto_initializer_get_offset(
    corto_initializer *this);
