
#include <corto/corto.h>
#include "object.h"

#define CORTO_MAX_CYCLE_BUFFER (64)

static
int corto_collect_traverse(
    corto_object o,
    void *userData);

typedef struct corto_collect_t {
    bool skip_named;
    corto_object stack[CORTO_MAX_CYCLE_BUFFER];
    uint16_t stack_ptr;
    void **ref_ptr;
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
bool corto_collect_onstack(
    corto_object o,
    corto_collect_t *data)
{
    int i;
    for (i = 0; i < data->stack_ptr; i ++) {
        if (data->stack[i] == o) return true;
    }
    return false;
}

static
int16_t corto_collect_walk_ref(
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

static
void corto_collect_traverse_refs(
    corto_object o,
    bool clean,
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
        opt.reference = corto_collect_walk_ref;
        corto_walk(&opt, o, &refs);

        if (refs) {
            corto_collect_t *data = userData;
            corto_iter it = corto_ll_iter(refs);
            while (corto_iter_hasNext(&it)) {
                data->ref_ptr = corto_iter_next(&it);
                if (CORTO_TRACE_MEM) {corto_info("REF '%s'", corto_fullpath(NULL, *data->ref_ptr));}
                corto_collect_traverse(*data->ref_ptr, userData);
            }
            corto_ll_free(refs);
        }
    }
}

static
int corto_collect_traverse(
    corto_object o,
    void *userData)
{
    corto_collect_t *data = userData;
    bool named = corto_check_attr(o, CORTO_ATTR_NAMED);
    bool builtin = corto_isbuiltin(o);
    corto__object *_o = CORTO_OFFSET(o, -sizeof(corto__object));

    if (CORTO_TRACE_MEM) {
        corto_log_push(strarg("TRAVERSE %s [%d]",
            corto_fullpath(NULL, o), corto_countof(o)));
    }

    if ((!named || !data->skip_named)) {
        bool on_stack = corto_collect_onstack(o, data);
        if (_o->cycles == 0 && !on_stack) {
            _o->cycles = 1; /* Prevent traversing same object twice */

            if (!builtin) {
                corto_collect_push(o, data);

                /* Each object holds a reference to its type */
                corto_collect_traverse(corto_typeof(o), data);
                if (named && corto_parentof(o)) {
                    /* Each named object holds a reference to its parent */
                    corto_collect_traverse(corto_parentof(o), data);
                }

                /* Traverse references of object */
                corto_collect_traverse_refs(o, false, data);
                corto_collect_pop(o, data);
            }

            /* If object is named, walk scope */
            if (named) {
                corto_scope_walk(o, corto_collect_traverse, data);
            }
        } else if (on_stack) {
            _o->cycles ++;

            if (CORTO_TRACE_MEM) {
                corto_info("CYCLE DETECTED: %s [%d]",
                    corto_fullpath(NULL, o), corto_countof(o));
            }

            if (data->ref_ptr) {
                corto_object ref = *data->ref_ptr;
                corto__object *_ref = CORTO_OFFSET(ref, -sizeof(corto__object));
                /* Cycle found for object, may need to reevaluate */
                _ref->cycles = 0;

                if (corto_instanceof(corto_member_o, ref)) {
                    printf("FREEING member '%s'\n", corto_fullpath(NULL, ref));
                }

                corto_release(ref);
                *data->ref_ptr = NULL;
                data->ref_ptr = NULL;
            } else {
                corto_error("ERROR - NO REFERENCE AT ROOT OF CYCLE\n");
            }
        }
    }

    if (CORTO_TRACE_MEM) {
        corto_log_pop();
    }

    return 1;
}

int16_t corto_collect(
    corto_object root)
{
    corto_collect_t walkData = {0};

    if (!corto_check_attr(root, CORTO_ATTR_NAMED)) {
        walkData.skip_named = true;
    }

    corto_collect_traverse(root, &walkData);

    return 0;
}
