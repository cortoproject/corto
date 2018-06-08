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
bool corto_type_is_collection(
    corto_type type)
{
    return !type->reference && type->kind == CORTO_COLLECTION;
}

static
bool corto_type_is_complex(
    corto_type type)
{
    return !type->reference &&
      (type->kind == CORTO_COMPOSITE || type->kind == CORTO_COLLECTION);
}

static
bool corto_type_is_growable(
    corto_type type)
{
    return (type->kind == CORTO_COLLECTION &&
      (corto_collection(type)->kind == CORTO_SEQUENCE ||
       corto_collection(type)->kind == CORTO_LIST));
}

corto_rw _corto_rw_init(
    corto_type type,
    void *ptr)
{
    corto_rw result = {
        .rw_type = type,
        .rw_ptr = ptr,
    };

    return result;
}

void corto_rw_deinit(
    corto_rw *this)
{
    while (this->current) {
        corto_rw_pop(this);
    }
}

static
int16_t corto_scope_cache_member(
    corto_walk_opt *opt,
    corto_value *value,
    void *members)
{
    /* Simply append members for the current type-scope. Nested type-scopes will
     * be collected once the writer moves to another scope. */
    corto_ll_append(members, value->is.member.member);
    return 0;
}

static
int16_t corto_scope_cache_build(
    corto_rw *this,
    corto_type type)
{
    /* Initializer order is determined by taking all non-private, non-readonly
     * non-local and non-hidden members. */
    corto_walk_opt opt = {0};

    corto_walk_init(&opt);

    opt.access = CORTO_PRIVATE | CORTO_READONLY | CORTO_HIDDEN | CORTO_LOCAL;
    opt.accessKind = CORTO_NOT;
    opt.aliasAction = CORTO_WALK_ALIAS_FOLLOW;
    opt.optionalAction = CORTO_WALK_OPTIONAL_ALWAYS;
    opt.metaprogram[CORTO_MEMBER] = corto_scope_cache_member;

    /* Collect members in temporary linked list so we have O(1) appends */
    corto_ll members = corto_ll_new();

    /* Walk over metadata */
    corto_try(corto_metawalk(&opt, type, members), NULL);

    this->current->max_index = corto_ll_count(members);
    this->current->cache = corto_calloc(
        sizeof(corto_member) * this->current->max_index);

    /* Store members in contiguous array so we have O(1) read access */
    uint32_t count = 0;
    corto_iter it = corto_ll_iter(members);
    corto_member member = this->current->field.member;
    while (corto_iter_hasNext(&it)) {
        this->current->cache[count].member = corto_iter_next(&it);

        /* If a member was already set, update index to the current member */
        if (member) {
            if (this->current->cache[count].member == member) {
                this->current->field.index = count;
            }
        }

        count ++;
    }

    corto_ll_free(members);
    return 0;
error:
    corto_ll_free(members);
    return -1;
}

int16_t corto_rw_index(
    corto_rw *this,
    uint32_t index)
{
    if (!this->current) {
        corto_throw("cannot set index, no scope pushed");
        goto error;
    }

    corto_type type = this->current->scope_type;
    int32_t count = corto_rw_count(this);
    if (count < 0) {
        goto error;
    }

    if (index >= count && this->current->scope_ptr) {
        /* Try to append a new element if index is one ahead of count */
        if ((index != count) || !corto_type_is_growable(type)) {
            /* If unable to append a new element, fail */
            corto_throw("index %d out of bounds (%d) for type '%s'",
                index, count, corto_fullpath(NULL, type));
            goto error;
        }

        /* If index exceeds count, but isn't out of bounds, append element */
        if (corto_rw_append(this)) {
            goto error;
        }
    } else {
        if (type->kind == CORTO_COMPOSITE) {
            this->current->field.member = this->current->cache[index].member;
            this->current->field.type = this->current->field.member->type;
            this->current->field.is_super = false;
            if (this->current->scope_ptr) {
                this->current->field.ptr = CORTO_OFFSET(
                    this->current->scope_ptr,
                    this->current->field.member->offset);
            }
        } else {
            corto_field field = {0};

            /* If a member was selected, the pointer should have been set
             * with it. So if the pointer isn't set yet, this must be a
             * collection element. */
            if (this->current->scope_ptr) {
                corto_try( corto_field_lookup_index(
                    index,
                    corto_collection(type),
                    this->current->scope_ptr,
                    &field),
                    NULL);
            }

            /* Assign resolved field pointer */
            this->current->field.ptr = field.ptr;
            this->current->field.member = NULL;
            this->current->field.is_super = false;
        }
    }

    this->current->field.index = index;

    return 0;
error:
    return -1;
}

int32_t corto_rw_count(
    corto_rw *this)
{
    if (!this->current) {
        if (corto_type_is_complex(this->rw_type)) {
            /* Complex values have no values in the root scope */
            return 0;
        } else {
            /* Primitive values have a single value in the root scope */
            return 1;
        }
    } else {
        corto_type type = this->current->scope_type;

        /* Ignore whether types are a reference or not. When a type is pushed
         * as a scope, it is accessed by value. */
        bool is_collection = type->kind == CORTO_COLLECTION;
        bool is_composite = type->kind == CORTO_COMPOSITE;

        if (is_composite && !this->current->cache) {
            /* If cache hasn't been built yet and this is a composite type,
             * build cache so we know how many members are in the scope. */
            corto_try(
                corto_scope_cache_build(this, this->current->scope_type), NULL);
        }

        if (is_composite && this->current->max_index >= 0) {
            /* If current scope is a composite return the max
             * number of members in this scope. */
            return this->current->max_index;
        } else if (is_collection) {
            /* If current scope is a collection return the current number of
             * elements in the collection. */
            corto_type type = this->current->scope_type;
            void *ptr = this->current->scope_ptr;
            if (ptr) {
                return corto_ptr_count(ptr, type);
            } else {
                return 0;
            }
        }
    }

error:
    return -1;
}

CORTO_SEQUENCE(dummy_seq, char,);

static
void* corto_rw_seq_append(
    void *ptr,
    corto_collection type,
    uint32_t *index)
{
    dummy_seq *seq = ptr;

    if (type->max && seq->length >= type->max) {
        corto_throw(
            "cannot append to value of sequence type '%s', bounds reached (%d)",
            corto_fullpath(NULL, type),
            type->max);
        goto error;
    }

    corto_type elem_type = type->elementType;
    uint32_t elem_size = corto_type_sizeof(elem_type);

    /* Allocate space for new element */
    seq->buffer = corto_realloc(seq->buffer, (seq->length + 1) * elem_size);

    /* Initialize element */
    void *elem = CORTO_OFFSET(seq->buffer, seq->length * elem_size);
    if (corto_ptr_init(elem, elem_type)) {
        goto error;
    }

    seq->length ++ ;

    *index = seq->length - 1;

    return elem;
error:
    return NULL;
}

static
void* corto_rw_list_append(
    void *ptr,
    corto_collection type,
    uint32_t *index)
{
    corto_ll list = *(corto_ll*)ptr;

    if (type->max && corto_ll_count(list) >= type->max) {
        corto_throw(
            "cannot append to value of list type '%s', bounds reached (%d)",
            corto_fullpath(NULL, type),
            type->max);
        goto error;
    }

    corto_type elem_type = type->elementType;

    void *elem = NULL;
    if (corto_collection_requiresAlloc(elem_type)) {
        elem = corto_ptr_new(elem_type);
        corto_ll_append(list, elem);
    } else {
        elem = corto_ll_append(list, 0);
    }

    *index = corto_ll_count(list) - 1;

    return elem;
error:
    return NULL;
}

int16_t corto_rw_append(
    corto_rw *this)
{
    if (!this->current) {
        corto_throw("no scope to append to");
        goto error;
    }

    corto_type type = this->current->scope_type;

    if (type->kind != CORTO_COLLECTION) {
        corto_throw("cannot append to non-collection value of type '%s'",
            corto_fullpath(NULL, type));
        goto error;
    }

    corto_collection ctype = corto_collection(type);

    if (ctype->kind == CORTO_ARRAY) {
        corto_throw("cannot append to array value of type '%s'",
            corto_fullpath(NULL, ctype));
        goto error;
    }

    void *ptr = this->current->scope_ptr;
    void *elem_ptr = NULL;
    uint32_t index;

    if (ctype->kind == CORTO_SEQUENCE) {
        if (!(elem_ptr = corto_rw_seq_append(ptr, ctype, &index))) {
            goto error;
        }
    } else if (ctype->kind == CORTO_LIST) {
        if (!(elem_ptr = corto_rw_list_append(ptr, ctype, &index))) {
            goto error;
        }
    }

    this->current->field.ptr = elem_ptr;
    this->current->field.index = index;

    return 0;
error:
    return -1;
}

int16_t corto_rw_next(
    corto_rw *this)
{
    if (this->current) {
        uint32_t i;

        if (this->current->field.is_super) {
            /* If the current field is a 'super' field, we need to skip over the
             * fields of the base type(s) to get to the first member in the
             * scope of the current type */

            corto_type scope_type = this->current->scope_type;

            /* To find the next field, we need a member cache */
            corto_try( corto_scope_cache_build(this, scope_type), NULL);

            for (i = 0; i < this->current->max_index; i ++) {
                if (corto_parentof(
                      this->current->cache[i].member) == scope_type) {
                    /* Found first member of the current type */
                    break;
                }
            }
        } else {
            i = corto_rw_get_index(this) + 1;
        }

        corto_try(corto_rw_index(this, i), NULL);
    } else {
        corto_throw("invalid use of 'next': no scope pushed");
        goto error;
    }
    return 0;
error:
    return -1;
}

bool corto_rw_has_next(
    corto_rw *this)
{
    if (!this->current) {
        return false;
    } else {
        int32_t count = corto_rw_count(this);
        if (count < 0) {
            goto error;
        }

        if (this->current->field.index + 1 >= count) {
            return false;
        } else {
            return true;
        }
    }

error:
    return false;
}

int16_t corto_rw_field(
    corto_rw *this,
    const char *field_expr)
{
    if (!this->current) {
        corto_throw("cannot set field, no scope pushed");
        goto error;
    }

    corto_type type = this->current->scope_type;
    if (!type) {
        goto error;
    }

    void *ptr = this->current->scope_ptr;

    corto_field field = {0};

    corto_try(corto_field_lookup(
        field_expr,
        type,
        ptr,
        &field
    ), NULL);

    this->current->field.ptr = field.ptr;
    this->current->field.member = field.member;
    this->current->field.type = field.type;
    this->current->field.is_super = field.is_super;

    if (field.index != -1) {
        this->current->field.index = field.index;
    } else if (this->current->cache) {
        /* If cache is set, lookup member and set correct index */
        int i;
        for (i = 0; i < this->current->max_index; i ++) {
            if (this->current->cache[i].member == field.member) {
                this->current->field.index = i;
                break;
            }
        }

        /* If member wasn't found in cache, the expression must've pointed to a
         * nested field that doesn't appear in the current scope. Indicate that
         * the index cannot be interpreted with value -1. */
        if (i == this->current->max_index) {
            this->current->field.index = -1;
        }
    }

    return 0;
error:
    return -1;
}

int16_t corto_rw_push(
    corto_rw *this,
    bool as_collection)
{
    corto_type cur_type = NULL;
    void *cur_ptr = NULL;
    corto_rw_scope *scope = NULL;
    bool is_collection = false;

    if (!this->current) {
        cur_type = this->rw_type;

        /* Ignore if the type is a reference type for the root scope */
        if (cur_type->kind != CORTO_COMPOSITE &&
            cur_type->kind != CORTO_COLLECTION)
        {
            corto_throw(
              "cannot push scope for non-complex type '%s'", cur_type);
            goto error;
        }
    } else {
        cur_type = corto_rw_get_type(this);
        if (!corto_type_is_complex(cur_type)) {
            corto_throw(
              "cannot push scope for non-complex type '%s'", cur_type);
            goto error;
        }
    }

    is_collection = corto_type_is_collection(cur_type);

    if (as_collection && !is_collection) {
        corto_throw("cannot push scope of type '%s' as collection",
            corto_fullpath(NULL, cur_type));
        goto error;
    }

    if (!this->current) {
        scope = &this->root_scope;
        cur_ptr = this->rw_ptr;
    } else {
        scope = corto_calloc(sizeof(corto_rw_scope));
        cur_ptr = this->current->field.ptr;
    }

    scope->scope_type = cur_type;
    scope->scope_ptr = cur_ptr;
    scope->parent = this->current;
    this->current = scope;

    if (is_collection) {
        corto_collection col_type = corto_collection(cur_type);
        uint32_t max = col_type->max;
        if (max) {
            this->current->max_index = max;
        } else {
            /* If collection is unbounded, scope can have unlimited elements */
            this->current->max_index = -1;
        }

        this->current->field.type = col_type->elementType;

        /* If pushing a list scope, ensure a linked-list object is allocated */
        if (cur_ptr && col_type->kind == CORTO_LIST) {
            if (!*(corto_ll*)cur_ptr) {
                *(corto_ll*)cur_ptr = corto_ll_new();
            }
        }
    }

    return 0;
error:
    return -1;
}

int16_t corto_rw_pop(
    corto_rw *this)
{
    if (this->current) {
        corto_rw_scope *parent = this->current->parent;
        if (this->current->cache) {
            free(this->current->cache);
        }
        if (this->current->parent) {
            /* The root scope is not separately allocated */
            free(this->current);
        }
        this->current = parent;
    } else {
        corto_throw("cannot pop root scope");
        goto error;
    }

    return 0;
error:
    return -1;
}

corto_type corto_rw_get_type(
    corto_rw *this)
{
    if (!this->current) {
        return this->rw_type;
    } else if (this->current->field.type) {
        return this->current->field.type;
    } else if (this->current->scope_type->kind == CORTO_COMPOSITE) {
        uint32_t index = this->current->field.index;
        if (!this->current->cache) {
            corto_try( corto_rw_index(this, index), NULL);
        }

        if (this->current->max_index >= index) {
            return this->current->cache[index].member->type;
        } else {
            corto_throw("no value at index %d in scope of type '%s'",
                index, corto_fullpath(NULL, this->current->scope_type));
        }
    }

error:
    return NULL;
}

bool corto_rw_in_scope(
    corto_rw *_this)
{
    return _this->current != NULL;
}

corto_type corto_rw_get_scope_type(
    corto_rw *this)
{
    if (!this->current) {
        return this->rw_type;
    } else {
        return this->current->scope_type;
    }
}

corto_member corto_rw_get_member(
    corto_rw *this)
{
    if (!this->current) {
        return NULL;
    } else if (this->current->field.member) {
        return this->current->field.member;
    } else if (this->current->scope_type->kind == CORTO_COMPOSITE) {
        uint32_t index = this->current->field.index;
        if (!this->current->cache) {
            corto_try(
                corto_rw_index(this, index), NULL);
        }

        if (this->current->max_index >= index) {
            return this->current->cache[index].member;
        } else {
            corto_throw("no value at index %d in scope of type '%s'",
                index, corto_fullpath(NULL, this->current->scope_type));
        }
    } else {
        corto_throw("cannot obtain member, scope is of non-composite type '%s'",
            corto_fullpath(NULL, this->current->scope_type));
    }

error:
    return NULL;
}

int32_t corto_rw_get_index(
    corto_rw *this)
{
    if (!this->current) {
        if (corto_type_is_complex(this->rw_type)) {
            /* Indicate that index cannot be interpreted, as root scope doesn't
             * have any complex values that can be initialized */
            return -1;
        } else {
            /* If readerwriter is not a complex type, it has exactly one value
             * in the root scope, and will thus always be at index 0 */
            return 0;
        }
    } else {
        if (!this->current->cache &&
            this->current->scope_type->kind == CORTO_COMPOSITE)
        {
            corto_scope_cache_build(this, this->current->scope_type);
        }
        return this->current->field.index;
    }
}

void* corto_rw_get_ptr(
    corto_rw *this)
{
    if (!this->current) {
        return this->rw_ptr;
    } else {
        if (this->current->scope_ptr) {
            if (!this->current->field.ptr) {
                corto_try(corto_rw_index(this, this->current->field.index), NULL);
            }

            return this->current->field.ptr;
        } else {
            return NULL;
        }
    }

error:
    return NULL;
}

uintptr_t corto_rw_set_value(
    corto_rw *this,
    corto_value *value)
{
    corto_type type = corto_rw_get_type(this);
    void *ptr = corto_rw_get_ptr(this);

    corto_value field = corto_value_pointer(ptr, type);

    if (corto_value_binaryOp(CORTO_ASSIGN, &field, value, NULL)) {
        if (this->current) {
            char *str = NULL;
            corto_value_to_string(value, &str);
            if (this->current->field.member) {
                corto_throw(
                    "failed to set value of member '%s' to '%s'",
                    corto_fullpath(NULL, this->current->field.member),
                    str);
            } else if (this->current->field.is_super) {
                corto_throw(
                    "failed to set value of super member to '%s'", str);
            } else {
              corto_throw(
                  "failed to set value at index %d to '%s'",
                  this->current->field.index,
                  str);
            }
            free(str);
        }
        goto error;
    }

    return 0;
error:
    return -1;
}

uintptr_t corto_rw_set_bool(
    corto_rw *this,
    bool value)
{
    corto_value v = corto_value_bool(value);
    return corto_rw_set_value(this, &v);
}

uintptr_t corto_rw_set_char(
    corto_rw *this,
    char value)
{
    corto_value v = corto_value_char(value);
    return corto_rw_set_value(this, &v);
}

uintptr_t corto_rw_set_int(
    corto_rw *this,
    int64_t value)
{
    corto_value v = corto_value_int(value);
    return corto_rw_set_value(this, &v);
}

uintptr_t corto_rw_set_uint(
    corto_rw *this,
    uint64_t value)
{
    corto_value v = corto_value_uint(value);
    return corto_rw_set_value(this, &v);
}

uintptr_t corto_rw_set_float(
    corto_rw *this,
    double value)
{
    corto_value v = corto_value_float(value);
    return corto_rw_set_value(this, &v);
}

uintptr_t corto_rw_set_string(
    corto_rw *this,
    const char *value)
{
    corto_value v = corto_value_string((char*)value);
    return corto_rw_set_value(this, &v);
}

uintptr_t corto_rw_set_ref(
    corto_rw *this,
    corto_object value)
{
    corto_value v = corto_value_object((char*)value, NULL);
    return corto_rw_set_value(this, &v);
}
