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

corto_int16 corto_ser_keepReference(corto_walk_opt* s, corto_value* v, void* userData) {
    corto_object o;
    CORTO_UNUSED(s);
    CORTO_UNUSED(userData);

    o = *(corto_object*)corto_value_ptrof(v);
    if (o) {
        corto_bool weak = FALSE;
        if (v->kind == CORTO_MEMBER) {
            if (v->is.member.t->weak) {
                weak = TRUE;
            }
        }
        if (!weak) {
            corto_claim(o);
        }
    }

    return 0;
}

corto_int16 corto_ser_keepCollection(corto_walk_opt* s, corto_value* v, void* userData) {
    CORTO_UNUSED(s);
    CORTO_UNUSED(userData);
    corto_object ptr = corto_value_ptrof(v);
    corto_type t = corto_value_typeof(v);

    if (corto_collection(t)->kind == CORTO_LIST) {
        *(corto_ll*)ptr = corto_ll_new();
    }

    return 0;
}

corto_int16 corto_ser_freePrimitive(corto_walk_opt* s, corto_value* v, void* ctx) {
    corto_type t;
    void* o;

    CORTO_UNUSED(s);
    CORTO_UNUSED(ctx);

    t = corto_value_typeof(v);
    o = corto_value_ptrof(v);

    /* Free strings */
    switch(corto_primitive(t)->kind) {
    case CORTO_TEXT: {
        corto_string str;
        if ((str = *(corto_string*)o)) {
            corto_dealloc(str);
        }
        break;
    }
    default:
        break;
    }

    return 0;
}

int corto_ser_clear(void* o, void* ctx) {
    CORTO_UNUSED(ctx);
    corto_dealloc(o);
    return 1;
}

corto_int16 corto_ser_freeCollection(corto_walk_opt* s, corto_value* v, void* userData) {
    corto_type t;
    void* o;

    t = corto_value_typeof(v);
    o = corto_value_ptrof(v);

    /* Serialize elements */
    if (corto_walk_elements(s, v, userData)) {
        goto error;
    }

    switch(corto_collection(t)->kind) {
    case CORTO_ARRAY:
        break;
    case CORTO_SEQUENCE: {
        void* buffer;
        buffer = ((struct{corto_uint32 length; void* buffer;}*)o)->buffer;
        if (buffer) {
            corto_dealloc(buffer);
        }
        break;
    }
    case CORTO_LIST:
        if (*(corto_ll*)o) {
            /* Free memory allocated for listnodes */
            if (corto_collection_requiresAlloc(corto_collection(t)->elementType)) {
                corto_ll_walk(*(corto_ll*)o, corto_ser_clear,NULL);
            }
            corto_ll_free(*(corto_ll*)o);
        }
        break;
    case CORTO_MAP:
        if (*(corto_rb*)o) {
            /* Free memory allocated for mapnodes */
            if (corto_collection_requiresAlloc(corto_collection(t)->elementType)) {
                corto_rb_walk(*(corto_rb*)o, corto_ser_clear,NULL);
            }
            corto_rb_free(*(corto_rb*)o);
        }
        break;

    /* Free collection object */
    default:
        corto_error("invalid collection object!");
        goto error;
        break;
    }

    return 0;
error:
    return -1;
}

corto_int16 corto_ser_freeReference(corto_walk_opt* s, corto_value* v, void* userData) {
    corto_object *optr, o;

    CORTO_UNUSED(s);
    CORTO_UNUSED(userData);
    optr = corto_value_ptrof(v);

    if ((o = *optr)) {
        corto_bool weak = FALSE;
        if (v->kind == CORTO_MEMBER) {
            if (v->is.member.t->weak) {
                weak = TRUE;
            }
        }
        if (!weak) {
            corto_release(o);
        }
    }

    return 0;
}

corto_int16 corto_ser_freeMember(corto_walk_opt* s, corto_value* v, void* userData) {
    corto_member m = v->is.member.t;
    void *ptr = corto_value_ptrof(v);

    corto_walk_value(s, v, userData);

    if (m->modifiers & CORTO_OPTIONAL) {
        corto_dealloc(ptr);
    }

    return 0;
}


corto_walk_opt corto_ser_keep(corto_modifier access, corto_operatorKind accessKind, corto_walk_traceKind trace) {
    corto_walk_opt s;

    corto_walk_init(&s);

    s.access = access;
    s.accessKind = accessKind;
    s.traceKind = trace;
    s.aliasAction = CORTO_WALK_ALIAS_IGNORE;
    s.optionalAction = CORTO_WALK_OPTIONAL_IF_SET;
    s.program[CORTO_COLLECTION] = corto_ser_keepCollection;
    s.reference = corto_ser_keepReference;
    return s;
}

corto_walk_opt corto_ser_free(corto_modifier access, corto_operatorKind accessKind, corto_walk_traceKind trace) {
    corto_walk_opt s;

    corto_walk_init(&s);

    s.access = access;
    s.accessKind = accessKind;
    s.traceKind = trace;
    s.aliasAction = CORTO_WALK_ALIAS_IGNORE;
    s.optionalAction = CORTO_WALK_OPTIONAL_IF_SET;
    s.reference = corto_ser_freeReference;
    s.observable = corto_ser_freeReference;

    return s;
}

corto_walk_opt corto_ser_freeResources(corto_modifier access, corto_operatorKind accessKind, corto_walk_traceKind trace) {
    corto_walk_opt s;

    corto_walk_init(&s);

    s.access = access;
    s.accessKind = accessKind;
    s.traceKind = trace;
    s.aliasAction = CORTO_WALK_ALIAS_IGNORE;
    s.optionalAction = CORTO_WALK_OPTIONAL_IF_SET;
    s.program[CORTO_PRIMITIVE] = corto_ser_freePrimitive;
    s.program[CORTO_COLLECTION] = corto_ser_freeCollection;
    s.metaprogram[CORTO_MEMBER] = corto_ser_freeMember;
    s.reference = corto_ser_freeReference;
    s.observable = corto_ser_freeReference;

    return s;
}
