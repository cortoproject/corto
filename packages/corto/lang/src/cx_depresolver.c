
/*
 * cx_generatorDepWalk.c
 *
 *  Created on: Sep 25, 2012
 *      Author: sander
 */

#define corto_lang_LIB
#include "cx.h"
#include "cx_depresolver.h"

#define CYCLE_DEPTH (1024)

typedef struct g_item* g_item;
struct g_item {
    void* o;
    cx_bool declared;
    cx_bool defined;
    cx_int32 declareCount;
    cx_int32 defineCount;
    cx_ll onDeclared;
    cx_ll onDefined;
};

typedef struct g_dependency* g_dependency;
struct g_dependency {
    cx_uint8 kind;
    g_item item;
    g_item dependency;
    cx_bool weak; /* A weak dependency may be degraded to DECLARED if a cycle can otherwise not be broken. */
    cx_bool marked;
    cx_bool processed; /* When a cycles are broken, it can occur that a dependency is resolved twice, as
                          a cycle is broken by resolving a dependency. This could cause refcounts to dive below
                          zero which is undesired. */
};

struct cx_depresolver {
    cx_ll items;
    cx_ll toPrint;
    cx_depresolver_action onDeclare;
    cx_depresolver_action onDefine;
    void* userData;
    g_dependency stack[CYCLE_DEPTH]; /* For cycle detection */
    cx_uint32 sp;
    cx_bool bootstrap; /* If a bootstrap is detected, disregard all dependencies. This can only mean that
                          the builtin-types are being generated, since these are the only ones that can
                          introduce a bootstrap (typeof(class) == class).
                          In this case, dependencies don't matter (and are non-resolvable)*/
};

static int g_itemPrint(void* o, void* userData);

/* Create new item */
g_item g_itemNew(cx_object o, cx_depresolver data) {
    g_item result;

    result = cx_alloc(sizeof(struct g_item));
    result->o = o;
    result->declared = FALSE;
    result->defined = FALSE;
    result->declareCount = 0;
    result->defineCount = 0;
    result->onDeclared = NULL;
    result->onDefined = NULL;

    if (o == root_o) {
        result->declared = TRUE;
        result->defined = TRUE;
    }

    cx_llInsert(data->items, result);

    return result;
}

/* Delete item */
void g_itemFree(g_item item) {
    g_dependency dep;

    /* Free onDeclared list */
    if (item->onDeclared) {
        while((dep = cx_llTakeFirst(item->onDeclared))) {
            cx_dealloc(dep);
        }
        cx_llFree(item->onDeclared);
    }

    /* Free onDefined list */
    if (item->onDefined) {
        while((dep = cx_llTakeFirst(item->onDefined))) {
            cx_dealloc(dep);
        }
        cx_llFree(item->onDefined);
    }

    cx_dealloc(item);
}

/* Lookup item in administration */
g_item g_itemLookup(cx_object o, cx_depresolver data) {
    cx_iter iter;
    g_item item;

    /* Lookup item for 'o' in items list */
    item = NULL;
    iter = cx_llIter(data->items);
    while(!item && cx_iterHasNext(&iter)) {
        item = cx_iterNext(&iter);
        if (item->o != o) {
            item = NULL;
        }
    }

    /* If item did not yet exist, insert it in data */
    if (!item) {
        item = g_itemNew(o, data);
    }

    return item;
}

/* Resolve dependency, decrease refcount */
static int g_itemResolveDependency(void* o, void* userData) {
    g_dependency dep;
    cx_depresolver data;

    dep = o;
    data = userData;

    if (!dep->processed) {
        switch(dep->kind) {
        case CX_DECLARED:
            dep->item->declareCount--;

            cx_assert(dep->item->declareCount >= 0, "negative declareCount for item '%s'.", cx_nameof(dep->item->o));

            if (!dep->item->declareCount) {
                cx_llInsert(data->toPrint, dep->item);
            }
            break;
        case CX_DEFINED:
            dep->item->defineCount--;

            cx_assert(dep->item->defineCount >= 0, "negative defineCount for item '%s'.", cx_nameof(dep->item->o));

            if (!dep->item->defineCount) {
                cx_llInsert(data->toPrint, dep->item);
            }
            break;
        }
    }

    dep->processed = TRUE;

    return 1;
}

/* Declare item */
static void g_itemDeclare(g_item item, cx_depresolver data) {
    if (data->onDeclare) {
        data->onDeclare(item->o, data->userData);
    }
}

/* Define item */
static void g_itemDefine(g_item item, cx_depresolver data) {
    if (data->onDefine) {
        data->onDefine(item->o, data->userData);
    }
}

/* Declare an item */
static int g_itemPrint(void* o, void* userData) {
    g_item item;
    cx_depresolver data;

    item = o;
    data = userData;

    /* Walk DECLARED dependencies */
    if (!item->declared && !item->declareCount) {
        item->declared = TRUE;
        g_itemDeclare(item, data);
        if (item->onDeclared) {
            cx_llWalk(item->onDeclared, g_itemResolveDependency, data);
        }
    }

    /* Walk DECLARED | DEFINED dependencies */
    if (item->declared && !item->defined && !item->defineCount) {
        item->defined = TRUE;
        g_itemDefine(item, data);
        if (item->onDefined) {
            cx_llWalk(item->onDefined, g_itemResolveDependency, data);
        }
    }

    return 1;
}

/* Collect initial objects */
int g_itemCollectinitial(void* o, void* userData) {
    g_item item;
    cx_depresolver data;

    item = o;
    data = userData;

    if (!item->declareCount) {
        cx_llInsert(data->toPrint, item);
    }

    return 1;
}

/* Print items (forward them to declare & define callbacks) */
int g_itemPrintItems(struct cx_depresolver* data) {
    g_item item;

    /* Collect initial items */
    if (!cx_llWalk(data->items, g_itemCollectinitial, data)) {
        goto error;
    }

    /* Print items */
    while((item = cx_llTakeFirst(data->toPrint))) {
        if (!g_itemPrint(item, data)) {
            goto error;
        }
    }

    return 0;
error:
    return -1;
}

static int g_itemResolveCycles(g_item item, struct cx_depresolver* data);

/* Scan stack for occurrence of dependency. */
cx_uint32 g_dependencyOnStack(g_dependency dep, struct cx_depresolver* data) {
    cx_uint32 i;
    cx_bool found;

    i = 0;
    found = FALSE;
    for(i=0; i<data->sp; i++) {
        if (data->stack[i] == dep) {
            found = TRUE;
            break;
        }
    }

    return found ? i + 1 : 0; /* zero indicates that the dependency is not found. */
}

/* Resolve cycles for dependency */
static void g_itemResolveDependencyCycles(g_dependency dep, struct cx_depresolver* data) {
    cx_uint32 sp;

    /* If item is already marked, there is no need to investigate it further. */
    if (!dep->marked) {
        /* If dependency is not on stack, scan further, if on stack, a cycle is found. */
        if (!(sp = g_dependencyOnStack(dep, data))) {
            data->stack[data->sp] = dep;
            data->sp++;
            cx_assert(data->sp < CYCLE_DEPTH, "stack-bound overflow.");

            /* Forward item and mark it. */
            g_itemResolveCycles(dep->item, data);
            dep->marked = TRUE;
            data->sp--;
        /* If a cycle is found, look on the stack for a weak dependency. */
        } else {
            cx_uint32 i;

            for(i=sp-1; i<data->sp; i++) {
                /* Break first weak dependency */
                if (data->stack[i]->weak && data->stack[i]->dependency->declared) {
                    g_itemResolveDependency(data->stack[i], data);

                    /* This dependency is already weakened, it cannot be weakened again. */
                    data->stack[i]->weak = FALSE;
                    break;
                }
            }
        }
    }
}

/* Resolve cycles.
 *
 * If there are cycles, the only cycles that can be broken are the DECLARED | DEFINED dependencies, which
 * are stored as dependency objects with the 'weak' flag set to TRUE.
 */
static int g_itemResolveCycles(g_item item, struct cx_depresolver* data) {
    cx_iter iter;
    g_dependency dep;
    cx_uint32 sp;

    sp = data->sp;

    /* If item has not yet been declared, search onDeclared list. If the item is already declared, the
     * dependencies in this list have already been resolved, thus need not to be evaluated again. */
    if (!item->declared && item->onDeclared) {

        /* Walk dependencies */
        iter = cx_llIter(item->onDeclared);
        while((cx_iterHasNext(&iter))) {
            dep = cx_iterNext(&iter);
            g_itemResolveDependencyCycles(dep, data);
        }
    }

    /* Walk onDefined list if item is not yet defined. */
    if (!item->defined && item->onDefined) {

        /* Walk dependencies */
        iter = cx_llIter(item->onDefined);
        while((cx_iterHasNext(&iter))) {
            dep = cx_iterNext(&iter);
            g_itemResolveDependencyCycles(dep, data);
        }
     }

    data->sp = sp;

    return 0;
}

/* Walk objects in correct dependency order. */
cx_depresolver cx_depresolverCreate(cx_depresolver_action onDeclare, cx_depresolver_action onDefine, void* userData) {
    cx_depresolver result;

    result = cx_alloc(sizeof(struct cx_depresolver));

    result->items = cx_llNew();
    result->toPrint = cx_llNew();
    result->onDeclare = onDeclare;
    result->onDefine = onDefine;
    result->userData = userData;

    return result;
}

/* Insert dependency relation.
 *   @param o The dependee object.
 *   @param kind Specifies whether the dependee potentially may be defined or declared after the dependency is resolved.
 *   @param dependency The dependency object.
 *   @param dependencyKind The dependency object must reach at least this state before the dependency can be resolved.
 */
void cx_depresolver_depend(cx_depresolver this, void* o, cx_uint8 kind, void* d, cx_uint8 dependencyKind) {
    g_dependency dep;
    g_item dependent, dependency;

    dependent = g_itemLookup(o, this);
    dependency = g_itemLookup(d, this);

    if (dependent->o != dependency->o) {

        /* Create dependency object */
        dep = cx_alloc(sizeof(struct g_dependency));
        dep->kind = kind;
        dep->item = dependent;
        dep->dependency = dependency;
        dep->weak = FALSE;
        dep->marked = FALSE;
        dep->processed = FALSE;

        /* Increase corresponding counter */
        switch(kind) {
        case CX_DECLARED:
            dependent->declareCount++;
            break;
        case CX_DEFINED:
            dependent->defineCount++;
            break;
        default:
            cx_assert(0, "invalid dependee-kind.");
            break;
        }

        /* Insert in corresponding list of dependency */
        switch(dependencyKind) {
        case CX_DECLARED:
            if (!dependency->onDeclared) {
                dependency->onDeclared = cx_llNew();
            }
            cx_llInsert(dependency->onDeclared, dep);
            break;
        case CX_DECLARED | CX_DEFINED:
            dep->weak = TRUE;
            /* no break */
        case CX_DEFINED:
            if (!dependency->onDefined) {
                dependency->onDefined = cx_llNew();
            }
            cx_llInsert(dependency->onDefined, dep);
            break;
        default:
            cx_assert(0, "invalid dependency-kind.");
            break;
        }
    } else {
        cx_error("cannot have dependency on self");
    }
}

void cx_depresolver_insert(cx_depresolver this, void *item) {
    g_itemLookup(item, this);   
}

int cx_depresolver_walk(cx_depresolver this) {
    cx_iter iter;
    g_item item;
    cx_uint32 unresolved = 0;

    /* Print initial items */
    if (g_itemPrintItems(this)) {
        goto error;
    }

    /* Resolve items with cycles */
    iter = cx_llIter(this->items);
    while(cx_iterHasNext(&iter)) {
        item = cx_iterNext(&iter);

        /* Process objects that have not yet been defined or declared */
        if (!item->defined) {
            /* Locate and resolve cycles */
            this->sp = 0;
            if (g_itemResolveCycles(item, this)) {
                goto error;
            }

            /* Print items after resolving cycle(s) for item. */
            if (g_itemPrintItems(this)) {
                goto error;
            }
        }
    }


    /* Free items and check if there are still undeclared or undefined objects. */
    while((item = cx_llTakeFirst(this->items))) {
        if (!item->defined) {
            if (!item->declared) {
                cx_id id;
                cx_warning("not declared/defined: '%s'", cx_fullname(item->o, id));
                unresolved++;
            } else if (!item->defined){
                cx_id id;
                cx_warning("not defined: '%s'", cx_fullname(item->o, id));
                unresolved++;
            }
        }
        g_itemFree(item);
    }

    /* Free lists */
    cx_llFree(this->toPrint);
    cx_llFree(this->items);

    /* Free this */
    cx_dealloc(this);

    if (unresolved) {
        cx_error("unsolvable dependecy cycles encountered");
        goto error;
    }

    return 0;
error:
    return -1;
}

