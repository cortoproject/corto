
#include <corto/corto.h>
#include "object.h"

#define CORTO_MAX_CYCLE_BUFFER (256)

static
int corto_collect_traverse(
    corto_object o,
    void *userData);

typedef struct corto_collect_t {
    bool collect_cycles;
    corto_object stack[CORTO_MAX_CYCLE_BUFFER];
    uint16_t stack_ptr;
    corto_ll to_collect;
    corto_ll types_to_collect;
} corto_collect_t;

static
void corto_collect_push(
    corto_object o,
    corto_collect_t *data)
{
    data->stack[data->stack_ptr] = o;
    data->stack_ptr ++;
    if (data->stack_ptr == CORTO_MAX_CYCLE_BUFFER) {
        printf("max cycle depth reached\n");
        abort();
    }
}

static
void corto_collect_pop(
    corto_object o,
    corto_collect_t *data)
{
    data->stack_ptr --;
    data->stack[data->stack_ptr] = NULL;
}

static
uint32_t corto_collect_onstack(
    corto_object o,
    corto_collect_t *data)
{
    int i;
    for (i = 0; i < data->stack_ptr; i ++) {
        if (data->stack[i] == o) return i + 1;
    }
    return 0;
}

static
bool corto_collect_eval(
    corto_object o,
    void *userData)
{
    corto_collect_t *data = userData;
    corto__object *_o = CORTO_OFFSET(o, -sizeof(corto__object));
    if (!_o->cycles && corto_collect_onstack(o, data)) {
        _o->cycles = true;

        /* Distinguish between objects, types and "meta-types". This will
         * ensure that type information that is still required for cleaning
         * up objects isn't broken down while objects are still being
         * collected. The order of cleaning up is:
         * objects -> types -> metatypes */
        if (corto_instanceof(corto_type_o, o)) {
            if (!data->types_to_collect) {
                data->types_to_collect = corto_ll_new();
            }

            /* Meta types inherit from corto/lang/type */
            if (corto_instanceof(corto_interface_o, o) &&
                safe_corto_interface_baseof(o, corto_type_o))
            {
                /* Always clean up metatypes after normal types */
                corto_ll_append(data->types_to_collect, o);
            } else {
                corto_ll_insert(data->types_to_collect, o);
            }
        } else {
            /* Normal objects */
            if (!data->to_collect) {
                data->to_collect = corto_ll_new();
            }
            corto_ll_append(data->to_collect, o);
        }
        if (CORTO_TRACE_MEM) {
            corto_info(strarg("CYCLE DETECTED: %s", corto_fullpath(NULL, o)));
        }
        return 1;
    }
    return false;
}

static
int16_t corto_collect_eval_ref(
    corto_walk_opt *opt,
    corto_value *info,
    void *userData)
{
    corto_object *ptr = corto_value_ptrof(info);
    if (*ptr) {
        corto_ll *refs = userData;
        if (!*refs) {
            *refs = corto_ll_new();
        }
        corto_ll_append(*refs, ptr);
    }
    return 0;
}

/* Evaluate all references in the value of an object */
static
void corto_collect_eval_refs(
    corto_object o,
    void *userData)
{
    corto_type type = corto_typeof(o);
    if (type->flags & CORTO_TYPE_HAS_RESOURCES) {
        /* First collect references, then traverse them, to limit stack depth */
        corto_ll refs = NULL;
        corto_walk_opt opt;
        corto_walk_init(&opt);
        opt.access = 0;
        opt.accessKind = CORTO_NOT;
        opt.aliasAction = CORTO_WALK_ALIAS_IGNORE;
        opt.reference = corto_collect_eval_ref;
        corto_walk(&opt, o, &refs);

        if (refs) {
            corto_iter it = corto_ll_iter(refs);
            while (corto_iter_hasNext(&it)) {
                void *ptr = corto_iter_next(&it);
                corto_collect_traverse(*(void**)ptr, userData);
            }
            corto_ll_free(refs);
        }
    }
}

/* Traverse over all discovered objects from a provided root */
static
int corto_collect_traverse(
    corto_object o,
    void *userData)
{
    corto__object *_o = CORTO_OFFSET(o, -sizeof(corto__object));

    /* Don't process object twice */
    if (_o->marked) {
        corto_collect_eval(o, userData);
        return 1;
    } else {
        _o->marked = true;
    }

    corto_collect_t *data = userData;
    bool named = corto_check_attr(o, CORTO_ATTR_NAMED);
    bool builtin = corto_isbuiltin(o);
    bool resumed = corto_isresumed(o);
    uint32_t count = 0;

    if (CORTO_TRACE_MEM) {
        corto_log_push(strarg("TRAVERSE %s", corto_fullpath(NULL, o)));
    }

    /* First, invoke delete/destruct hook, notify and tear down scope admin */
    if (!corto_check_state(o, CORTO_DELETED)) {
        if (corto_destruct(o, false, false)) {
            /* There's a chance that calling the destructor broke a cycle that
             * deleted the object. If not, decrease reference count */
            if (named && !resumed) {
                /* Only decrease refcount for named objects. Named objects have
                 * an initial refcount of 1 that keeps them alive in the object
                 * hierachy. Anonymous objects are only kept alive by other
                 * objects that refer to them.
                 *
                 * Also do not release object when it is automatically resumed.
                 * Resumed objects do not receive an initial reference count,
                 * thus should not be released here.
                 */

                count = corto_release(o);
            } else {
                count = corto_countof(o);
            }
        }
    } else {
        /* Destruct was already called on object */
        count = corto_countof(o);
    }

    /* If count is non-zero, object has not yet been deleted. It either
     * participates in a cycle or is kept alive by objects that participate in a
     * cycle. */
    if (count && !builtin && data->collect_cycles) {
        /* Check if object is part of cycle */
        if (!corto_collect_eval(o, data)) {
            /* If object is not part of (detected) cycle, keep looking */
            corto_collect_push(o, data);

            /* Check if parent is part of cycle */
            corto_object parent = corto_parentof(o);
            if (parent) {
                corto_collect_eval(parent, data);
            }

            /* Evaluate refs in object value */
            corto_log_push("WALK_REFS");
            corto_collect_eval_refs(o, data);
            corto_log_pop();

            /* Note that even though cycles might have been detected, they
             * are not yet broken down in order to guarantee that data from
             * referenced objects is still consistent while lifecycle hooks
             * are being invoked. */

            corto_collect_pop(o, data);
        }
    }

    /* Walk over all objects in hierarchy. If count is zero, object was already
     * freed, which means it cannot have had any children. */
    if (count && named) {
        int i;
        corto_objectseq seq = corto_scope_claim(o);
        for (i = 0; i < seq.length; i ++) {
            corto_collect_traverse(seq.buffer[i], data);
        }
        corto_scope_release(seq);
    }

    if (CORTO_TRACE_MEM) {
        corto_log_pop();
    }

    return 1;
}

static
void corto_collect_objects(
    corto_ll objects)
{
    corto_iter it = corto_ll_iter(objects);
    while (corto_iter_hasNext(&it)) {
        corto_object o = corto_iter_next(&it);
        if (CORTO_TRACE_MEM) {
            corto_log_push(strarg("COLLECT %s", corto_fullpath(NULL, o)));
            corto_info("DEINIT");
        }
        corto_claim(o);
        corto_deinit(o);
        corto_release(o);
        if (CORTO_TRACE_MEM) {
            corto_log_pop();
        }
    }

    corto_ll_free(objects);
}

int16_t corto_collect(
    corto_object root,
    bool collect_cycles)
{
    corto_collect_t walkData = {collect_cycles};

    corto_collect_traverse(root, &walkData);

    if (collect_cycles) {
        /* Clean non-type objects first  */
        corto_collect_objects(walkData.to_collect);

        /* Clean types (normal types first, then meta types) */
        corto_collect_objects(walkData.types_to_collect);
    }

    return 0;
}
