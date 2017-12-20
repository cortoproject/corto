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

corto_int16 corto_ser_initAny(corto_walk_opt* s, corto_value* v, void* userData) {
    corto_any *ptr = corto_value_ptrof(v);
    CORTO_UNUSED(s);
    CORTO_UNUSED(userData);
    ptr->owner = TRUE;
    return 0;
}

corto_int16 corto_ser_initCollection(corto_walk_opt* s, corto_value* v, void* userData) {
    corto_type t;
    void* o;

    t = corto_value_typeof(v);
    o = corto_value_ptrof(v);

    switch(corto_collection(t)->kind) {
        case CORTO_ARRAY:
            if (corto_walk_elements(s, v, userData)) {
                goto error;
            }
            break;
        case CORTO_LIST:
            *(corto_ll*)o = corto_ll_new();
            break;
        case CORTO_MAP:
            /**(corto_rb*)o = corto_rb_new(t);*/
            break;
        default:
            break;
    }

    return 0;
error:
    return -1;
}

corto_int16 corto_ser_initObservable(corto_walk_opt* s, corto_value* v, void* userData) {
    corto_member m = v->is.member.t;

    /* Initialize member to a new object of member type */
    corto_type t = corto_value_typeof(v);
    corto_object p = corto_value_objectof(v);
    void* ptr = corto_value_ptrof(v);

    /* Create observable that is not added to the scope of its parent */
    corto_object o = corto(CORTO_DECLARE|CORTO_FORCE_TYPE|CORTO_ORPHAN|CORTO_DEFINE,
        {.parent = p, .id = corto_idof(m), .type = t});
    if (!o) {
        goto error;
    }

    *(corto_object*)ptr = o;

    return corto_walk_observable(s, v, userData);
error:
    return -1;
}

corto_walk_opt corto_ser_init(corto_modifier access, corto_operatorKind accessKind, corto_walk_traceKind trace) {
    corto_walk_opt s;

    corto_walk_init(&s);

    s.access = access;
    s.accessKind = accessKind;
    s.traceKind = trace;
    s.program[CORTO_COLLECTION] = corto_ser_initCollection;
    s.program[CORTO_ANY] = corto_ser_initAny;
    s.observable = corto_ser_initObservable;

    return s;
}
