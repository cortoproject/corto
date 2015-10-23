
/*
 * corto_generatorDepWalk.c
 *
 *  Created on: Sep 25, 2012
 *      Author: sander
 */

#include "corto.h"

#define CYCLE_DEPTH (1024)

typedef struct g_item* g_item;
struct g_item {
    void* o;
    corto_bool declared;
    corto_bool defined;
    corto_int32 declareCount;
    corto_int32 defineCount;
    corto_ll onDeclared;
    corto_ll onDefined;
};

typedef struct g_dependency* g_dependency;
struct g_dependency {
    corto_uint8 kind;
    g_item item;
    g_item dependency;
    corto_bool weak; /* A weak dependency may be degraded to DECLARED if a cycle can otherwise not be broken. */
    corto_bool marked;
    corto_bool processed; /* When a cycles are broken, it can occur that a dependency is resolved twice, as
                          a cycle is broken by resolving a dependency. This could cause refcounts to dive below
                          zero which is undesired. */
};

struct corto_depresolver_s {
    corto_ll items;
    corto_ll toPrint;
    corto_depresolver_action onDeclare;
    corto_depresolver_action onDefine;
    void* userData;
    g_dependency stack[CYCLE_DEPTH]; /* For cycle detection */
    corto_uint32 sp;
    corto_bool bootstrap; /* If a bootstrap is detected, disregard all dependencies. This can only mean that
                          the builtin-types are being generated, since these are the only ones that can
                          introduce a bootstrap (typeof(class) == class).
                          In this case, dependencies don't matter (and are non-resolvable)*/
};

static int g_itemPrint(void* o, void* userData);

/* Create new item */
g_item g_itemNew(corto_object o, corto_depresolver data) {
    g_item result;

    result = corto_alloc(sizeof(struct g_item));
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

    corto_llInsert(data->items, result);

    return result;
}

/* Delete item */
void g_itemFree(g_item item) {
    g_dependency dep;

    /* Free onDeclared list */
    if (item->onDeclared) {
        while((dep = corto_llTakeFirst(item->onDeclared))) {
            corto_dealloc(dep);
        }
        corto_llFree(item->onDeclared);
    }

    /* Free onDefined list */
    if (item->onDefined) {
        while((dep = corto_llTakeFirst(item->onDefined))) {
            corto_dealloc(dep);
        }
        corto_llFree(item->onDefined);
    }

    corto_dealloc(item);
}

/* Lookup item in administration */
g_item g_itemLookup(corto_object o, corto_depresolver data) {
    corto_iter iter;
    g_item item;

    /* Lookup item for 'o' in items list */
    item = NULL;
    iter = corto_llIter(data->items);
    while(!item && corto_iterHasNext(&iter)) {
        item = corto_iterNext(&iter);
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
    corto_depresolver data;

    dep = o;
    data = userData;

    if (!dep->processed) {
        switch(dep->kind) {
        case CORTO_DECLARED:
            dep->item->declareCount--;

            corto_assert(dep->item->declareCount >= 0, "negative declareCount for item '%s'.", corto_nameof(dep->item->o));

            if (!dep->item->declareCount) {
                corto_llInsert(data->toPrint, dep->item);
            }
            break;
        case CORTO_DEFINED:
            dep->item->defineCount--;

            corto_assert(dep->item->defineCount >= 0, "negative defineCount for item '%s'.", corto_nameof(dep->item->o));

            if (!dep->item->defineCount) {
                corto_llInsert(data->toPrint, dep->item);
            }
            break;
        }
    }

    dep->processed = TRUE;

    return 1;
}

/* Declare item */
static void g_itemDeclare(g_item item, corto_depresolver data) {
    if (data->onDeclare) {
        data->onDeclare(item->o, data->userData);
    }
}

/* Define item */
static void g_itemDefine(g_item item, corto_depresolver data) {
    if (data->onDefine) {
        data->onDefine(item->o, data->userData);
    }
}

/* Declare an item */
static int g_itemPrint(void* o, void* userData) {
    g_item item;
    corto_depresolver data;

    item = o;
    data = userData;

    /* Walk DECLARED dependencies */
    if (!item->declared && !item->declareCount) {
        item->declared = TRUE;
        g_itemDeclare(item, data);
        if (item->onDeclared) {
            corto_llWalk(item->onDeclared, g_itemResolveDependency, data);
        }
    }

    /* Walk DECLARED | DEFINED dependencies */
    if (item->declared && !item->defined && !item->defineCount) {
        item->defined = TRUE;
        g_itemDefine(item, data);
        if (item->onDefined) {
            corto_llWalk(item->onDefined, g_itemResolveDependency, data);
        }
    }

    return 1;
}

/* Collect initial objects */
int g_itemCollectinitial(void* o, void* userData) {
    g_item item;
    corto_depresolver data;

    item = o;
    data = userData;

    if (!item->declareCount) {
        corto_llInsert(data->toPrint, item);
    }

    return 1;
}

/* Print items (forward them to declare & define callbacks) */
int g_itemPrintItems(struct corto_depresolver_s* data) {
    g_item item;

    /* Collect initial items */
    if (!corto_llWalk(data->items, g_itemCollectinitial, data)) {
        goto error;
    }

    /* Print items */
    while((item = corto_llTakeFirst(data->toPrint))) {
        if (!g_itemPrint(item, data)) {
            goto error;
        }
    }

    return 0;
error:
    return -1;
}

static int g_itemResolveCycles(g_item item, struct corto_depresolver_s* data);

/* Scan stack for occurrence of dependency. */
corto_uint32 g_dependencyOnStack(g_dependency dep, struct corto_depresolver_s* data) {
    corto_uint32 i;
    corto_bool found;

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
static void g_itemResolveDependencyCycles(g_dependency dep, struct corto_depresolver_s* data) {
    corto_uint32 sp;

    /* If item is already marked, there is no need to investigate it further. */
    if (!dep->marked) {
        /* If dependency is not on stack, scan further, if on stack, a cycle is found. */
        if (!(sp = g_dependencyOnStack(dep, data))) {
            data->stack[data->sp] = dep;
            data->sp++;
            corto_assert(data->sp < CYCLE_DEPTH, "stack-bound overflow.");

            /* Forward item and mark it. */
            g_itemResolveCycles(dep->item, data);
            dep->marked = TRUE;
            data->sp--;
        /* If a cycle is found, look on the stack for a weak dependency. */
        } else {
            corto_uint32 i;

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
static int g_itemResolveCycles(g_item item, struct corto_depresolver_s* data) {
    corto_iter iter;
    g_dependency dep;
    corto_uint32 sp;

    sp = data->sp;

    /* If item has not yet been declared, search onDeclared list. If the item is already declared, the
     * dependencies in this list have already been resolved, thus need not to be evaluated again. */
    if (!item->declared && item->onDeclared) {

        /* Walk dependencies */
        iter = corto_llIter(item->onDeclared);
        while((corto_iterHasNext(&iter))) {
            dep = corto_iterNext(&iter);
            g_itemResolveDependencyCycles(dep, data);
        }
    }

    /* Walk onDefined list if item is not yet defined. */
    if (!item->defined && item->onDefined) {

        /* Walk dependencies */
        iter = corto_llIter(item->onDefined);
        while((corto_iterHasNext(&iter))) {
            dep = corto_iterNext(&iter);
            g_itemResolveDependencyCycles(dep, data);
        }
     }

    data->sp = sp;

    return 0;
}

/* Walk objects in correct dependency order. */
corto_depresolver corto_depresolverCreate(corto_depresolver_action onDeclare, corto_depresolver_action onDefine, void* userData) {
    corto_depresolver result;

    result = corto_alloc(sizeof(struct corto_depresolver_s));

    result->items = corto_llNew();
    result->toPrint = corto_llNew();
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
void corto_depresolver_depend(corto_depresolver this, void* o, corto_uint8 kind, void* d, corto_uint8 dependencyKind) {
    g_dependency dep;
    g_item dependent, dependency;

    dependent = g_itemLookup(o, this);
    dependency = g_itemLookup(d, this);

    if (dependent->o != dependency->o) {

        /* Create dependency object */
        dep = corto_alloc(sizeof(struct g_dependency));
        dep->kind = kind;
        dep->item = dependent;
        dep->dependency = dependency;
        dep->weak = FALSE;
        dep->marked = FALSE;
        dep->processed = FALSE;

        /* Increase corresponding counter */
        switch(kind) {
        case CORTO_DECLARED:
            dependent->declareCount++;
            break;
        case CORTO_DEFINED:
            dependent->defineCount++;
            break;
        default:
            corto_assert(0, "invalid dependee-kind.");
            break;
        }

        /* Insert in corresponding list of dependency */
        switch(dependencyKind) {
        case CORTO_DECLARED:
            if (!dependency->onDeclared) {
                dependency->onDeclared = corto_llNew();
            }
            corto_llInsert(dependency->onDeclared, dep);
            break;
        case CORTO_DECLARED | CORTO_DEFINED:
            dep->weak = TRUE;
            /* no break */
        case CORTO_DEFINED:
            if (!dependency->onDefined) {
                dependency->onDefined = corto_llNew();
            }
            corto_llInsert(dependency->onDefined, dep);
            break;
        default:
            corto_assert(0, "invalid dependency-kind.");
            break;
        }
    } else {
        corto_error("cannot have dependency on self");
    }
}

void corto_depresolver_insert(corto_depresolver this, void *item) {
    g_itemLookup(item, this);   
}

int corto_depresolver_walk(corto_depresolver this) {
    corto_iter iter;
    g_item item;
    corto_uint32 unresolved = 0;

    /* Print initial items */
    if (g_itemPrintItems(this)) {
        goto error;
    }

    /* Resolve items with cycles */
    iter = corto_llIter(this->items);
    while(corto_iterHasNext(&iter)) {
        item = corto_iterNext(&iter);

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
    while((item = corto_llTakeFirst(this->items))) {
        if (!item->defined) {
            if (!item->declared) {
                corto_id id;
                corto_warning("not declared/defined: '%s'", corto_fullname(item->o, id));
                unresolved++;
            } else if (!item->defined){
                corto_id id;
                corto_warning("not defined: '%s'", corto_fullname(item->o, id));
                unresolved++;
            }
        }
        g_itemFree(item);
    }

    /* Free lists */
    corto_llFree(this->toPrint);
    corto_llFree(this->items);

    /* Free this */
    corto_dealloc(this);

    if (unresolved) {
        corto_error("unsolvable dependecy cycles encountered");
        goto error;
    }

    return 0;
error:
    return -1;
}

