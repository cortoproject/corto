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
corto_int16 corto_ser_initAny(
    corto_walk_opt* s,
    corto_value* v,
    void* userData)
{
    corto_any *ptr = corto_value_ptrof(v);
    CORTO_UNUSED(s);
    CORTO_UNUSED(userData);
    ptr->owner = TRUE;
    return 0;
}

static
int corto_compare_key(
    void* ctx,
    const void *o1,
    const void *o2)
{
    return corto_ptr_compare(o1, ctx, o2);
}

static
int corto_compare_key_ptr(
    void* ctx,
    const void *o1,
    const void *o2)
{
    return corto_ptr_compare(&o1, ctx, &o2);
}

static
corto_int16 corto_ser_initCollection(
    corto_walk_opt* s,
    corto_value* v,
    void* userData)
{
    corto_collection t = (corto_collection)corto_value_typeof(v);
    void *o = corto_value_ptrof(v);
    corto_member m = v->is.member.member;

    switch(t->kind) {
        case CORTO_ARRAY:
            if (corto_walk_elements(s, v, userData)) {
                goto error;
            }
            break;
        case CORTO_LIST:
            if (!m || m->modifiers & CORTO_NOT_NULL) {
                *(corto_ll*)o = corto_ll_new();
            }
            break;
        case CORTO_MAP:
            if (!m || m->modifiers & CORTO_NOT_NULL) {
                corto_type key_type = corto_map(t)->key_type;
                if (key_type) {
                    if (corto_collection_requires_alloc(key_type)) {
                        *(corto_rb*)o = corto_rb_new(corto_compare_key, key_type);
                    } else {
                        *(corto_rb*)o = corto_rb_new(corto_compare_key_ptr, key_type);
                    }
                } else {
                    /* Custom compare function, app is responsible for init */
                }
                break;
            }
        default:
            break;
    }

    return 0;
error:
    return -1;
}

static
corto_int16 corto_ser_initObservable(
    corto_walk_opt* s,
    corto_value* v,
    void* userData)
{
    corto_member m = v->is.member.member;
    int create_mask = CORTO_DECLARE|CORTO_FORCE_TYPE|CORTO_DEFINE;

    /* Initialize member to a new object of member type */
    corto_type t = corto_value_typeof(v);
    corto_object p = corto_value_objectof(v);
    void* ptr = corto_value_ptrof(v);

    if ((m->modifiers & CORTO_SINGLETON) == CORTO_SINGLETON) {
        /* If member is a singleton, create observable member in the scope of
         * the composite type */
        p = corto_parentof(t);
    } else {
        /* If this is a regular observable member, create object as orphan */
        create_mask |= CORTO_ORPHAN;
    }

    /* Create observable that is not added to the scope of its parent */
    corto_object o = corto(create_mask, {
        .parent = p,
        .id = corto_idof(m),
        .type = t
    });
    if (!o) {
        goto error;
    }

    *(corto_object*)ptr = o;

    return corto_walk_observable(s, v, userData);
error:
    return -1;
}

static
corto_int16 corto_ser_initMember(
    corto_walk_opt* s,
    corto_value* v,
    void* userData)
{
    corto_member m = v->is.member.member;
    corto_type t = m->type;

    if (m->_default) {
        corto_fmt fmt;

        if (!(fmt = corto_fmt_lookup("text/corto"))) {
            corto_throw("text/corto format not found");
            goto error;
        }

        return corto_fmt_to_value(fmt, NULL, v, m->_default);
    }

    if (!t->reference && t->flags & CORTO_TYPE_HAS_INIT) {
        void *ptr = corto_value_ptrof(v);
        if (corto_ptr_init(ptr, t)) {
            goto error;
        }
    }

    return corto_walk_value(s, v, userData);
error:
    return -1;
}

corto_walk_opt corto_ser_init(
    corto_modifierMask access,
    corto_operatorKind accessKind,
    corto_walk_traceKind trace)
{
    corto_walk_opt s;

    corto_walk_init(&s);

    s.access = access;
    s.accessKind = accessKind;
    s.traceKind = trace;
    s.program[CORTO_COLLECTION] = corto_ser_initCollection;
    s.program[CORTO_ANY] = corto_ser_initAny;
    s.metaprogram[CORTO_MEMBER] = corto_ser_initMember;
    s.observable = corto_ser_initObservable;

    return s;
}
