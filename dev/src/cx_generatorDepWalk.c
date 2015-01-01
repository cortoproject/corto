/*
 * cx_generatorDepWalk.c
 *
 *  Created on: Sep 25, 2012
 *      Author: sander
 */

#include "cx.h"
#include "cx_generatorDepWalk.h"

#define CYCLE_DEPTH (1024)

typedef struct g_item* g_item;
struct g_item {
    cx_object o;
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
    cx_bool weak; /* A weak dependency may be degraded to DECLARED if a cycle can otherwise not be broken. */
    cx_bool marked;
    cx_bool processed; /* When a cycles are broken, it can occur that a dependency is resolved twice, as
                          a cycle is broken by resolving a dependency. This could cause refcounts to dive below
                          zero which is undesired. */
};

typedef struct g_itemWalk_t* g_itemWalk_t;
struct g_itemWalk_t {
    cx_generator g;
    cx_ll items;
    cx_ll toPrint;
    g_walkAction onDeclare;
    g_walkAction onDefine;
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
g_item g_itemNew(cx_object o, g_itemWalk_t data) {
    g_item result;

    result = cx_malloc(sizeof(struct g_item));
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
g_item g_itemLookup(cx_object o, g_itemWalk_t data) {
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

/* Insert dependency relation.
 *   @param o The dependee object.
 *   @param kind Specifies whether the dependee potentially may be defined or declared after the dependency is resolved.
 *   @param dependency The dependency object.
 *   @param dependencyKind The dependency object must reach at least this state before the dependency can be resolved.
 */
void g_itemDepend(g_item o, cx_uint8 kind, g_item dependency, cx_uint8 dependencyKind) {
    g_dependency dep;

    cx_assert(dependency->o != root_o, "invalid dependency on root.");

    if (o->o != dependency->o) {

		/* Create dependency object */
		dep = cx_malloc(sizeof(struct g_dependency));
		dep->kind = kind;
		dep->item = o;
		dep->weak = FALSE;
		dep->marked = FALSE;
		dep->processed = FALSE;

		/* Increase corresponding counter */
		switch(kind) {
		case CX_DECLARED:
			o->declareCount++;
			break;
		case CX_DEFINED:
			o->defineCount++;
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
    	cx_error("bootstrap detected while not in ::cortex::lang namespace - database corrupt!");
    }
}

/* Resolve dependency, decrease refcount */
int g_itemResolveDependency(void* o, void* userData) {
    g_dependency dep;
    g_itemWalk_t data;

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
static void g_itemDeclare(g_item item, g_itemWalk_t data) {
    if (data->onDeclare) {
        data->onDeclare(item->o, data->userData);
    }
}

/* Define item */
static void g_itemDefine(g_item item, g_itemWalk_t data) {

    /* VOID objects are defined at the moment of declaration. */
    if ((cx_typeof(item->o)->real->kind != CX_VOID) || (cx_typeof(item->o)->real->reference)) {
        if (data->onDefine) {
            data->onDefine(item->o, data->userData);
        }
    }
}

/* Declare an item */
static int g_itemPrint(void* o, void* userData) {
    g_item item;
    g_itemWalk_t data;

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

typedef struct g_depWalk_t* g_depWalk_t;
struct g_depWalk_t  {
    g_item item;
    g_itemWalk_t data;
};

/* Serialize dependencies on references */
cx_int16 cx_genDepReference(cx_serializer s, cx_value* info, void* userData) {
    cx_object o;
    g_depWalk_t data;

    CX_UNUSED(s);

    data = userData;
    o = *(cx_object*)cx_valueValue(info);

    if (o && g_mustParse(data->data->g, o)) {
        g_item item;
        cx_member m;

        m = NULL;
        item = g_itemLookup(o, data->data);

        if (info->kind == CX_MEMBER) {
            m = info->is.member.t;
            if (!m->type->real->reference) {
                m = NULL;
            }
        }

        /* Add dependency on item */
        if (m) {
            g_itemDepend(data->item, CX_DEFINED, item, m->state);
        } else {
            g_itemDepend(data->item, CX_DEFINED, item, CX_DEFINED);
        }
    }

    return 0;
}

/* Dependency serializer */
struct cx_serializer_s cx_genDepSerializer(void) {
    struct cx_serializer_s s;

    cx_serializerInit(&s);
    s.reference = cx_genDepReference;
    s.access = CX_LOCAL;
    s.accessKind = CX_NOT;
    s.traceKind = CX_SERIALIZER_TRACE_ON_FAIL;

    return s;
}

/* Add dependencies for function arguments */
static int cx_genDepBuildProc(g_item item, g_itemWalk_t data) {
    cx_id typeBuff;
    cx_function f;
    cx_uint32 count, i;
    cx_typedef t;
    g_item tItem;

    /* Walk through parameter types, add them as dependencies */
    f = item->o;

    if (cx_procedure(cx_typeof(f))->kind != CX_OBSERVER) {
		count = cx_signatureParamCount(cx_nameof(f));
		for(i=0; i<count; i++) {
			cx_signatureParamType(cx_nameof(f), i, typeBuff, NULL);
			t = cx_resolve_ext(NULL, cx_parentof(f), typeBuff, FALSE, "Resolve type for parameter in dependency builder");
			if (!t) {
				cx_error("type '%s' in signature '%s' not found!", typeBuff, cx_nameof(item->o));
				goto error;
			}
			if (g_mustParse(data->g, t)) {
				tItem = g_itemLookup(t, data);
				g_itemDepend(item, CX_DECLARED, tItem, CX_DECLARED | CX_DEFINED); /* The type must be at least declared when the function is declared. */
			}
			cx_free_ext(NULL, t, "Free resolved parameter type for dependency builder");
		}
    }

    return 0;
error:
    return -1;
}

/* Build dependency-administration for object */
int cx_genDepBuildAction(cx_object o, void* userData) {
    g_itemWalk_t data;
    struct g_depWalk_t walkData;
    g_item dependee, type, parent;
    struct cx_serializer_s s;
    int result;

    data = userData;

    /* If object is cortex_lang_o, signal that a bootstrap is found, indicating
     * that dependencies should be disregarded. */
    if (o == cortex_lang_o) {
    	data->bootstrap = TRUE;
    	result = 0;
    } else {
		/* Lookup item for dependee */
		dependee = g_itemLookup(o, data);

		/* Insert type-dependency: object can be declared only after it's type is defined. */
		if (g_mustParse(data->g, cx_typeof(o))) {
			type = g_itemLookup(cx_typeof(o), data);
			g_itemDepend(dependee, CX_DECLARED, type, CX_DEFINED);
		}

		if (cx_class_instanceof(cx_procedure_o, cx_typeof(o))) {
			/* Insert base-dependency: methods may only be declared after the base of a class has been defined. */
			if (cx_typeof(o) != cx_typedef(cx_function_o)) {
				if (cx_class_instanceof(cx_class_o, cx_parentof(o)) && cx_interface(cx_parentof(o))->base) {
				    if (g_mustParse(data->g, cx_interface(cx_parentof(o))->base)) {
                        g_item base = g_itemLookup(cx_interface(cx_parentof(o))->base, data);
                        g_itemDepend(dependee, CX_DECLARED, base, CX_DEFINED);
				    }
				}
			}

			/* Add dependencies on function parameters - types must be declared before function is declared. */
			if (cx_genDepBuildProc(dependee, data)) {
				goto error;
			}
		}

		/* Insert dependency on parent */
		if (cx_checkAttr(o, CX_ATTR_SCOPED)) {
			parent = g_itemLookup(cx_parentof(o), data);
			if (parent && (parent->o != root_o)) { /* Root is always available */
				switch(cx_typedef(cx_typeof(o))->real->parentState) {
				case 0:
				case CX_DECLARED | CX_DEFINED:
					/* If it doesn't matter whether the parent is declared or defined, mark
					 * the dependency as DECLARED, which ensures it is resolved as soon as possible. */
					g_itemDepend(dependee, CX_DECLARED, parent, CX_DECLARED);
					break;
				case CX_DECLARED:
					g_itemDepend(dependee, CX_DECLARED, parent, CX_DECLARED);

					/* If child must be declared when parent is declared, parent may only be defined after
					 * all such childs are defined. */
					g_itemDepend(parent, CX_DEFINED, dependee, CX_DEFINED);
					break;
				case CX_DEFINED:
					g_itemDepend(dependee, CX_DECLARED, parent, CX_DEFINED);
					break;
				}
			}
		}

		/* Insert dependencies on references in the object-value */
		walkData.item = dependee;
		walkData.data = data;
		s = cx_genDepSerializer();
		if (cx_serialize(&s, o, &walkData)) {
			goto error;
		}

		result = 1;
    }

    return result;
error:
    return 0;
}

/* Collect initial objects */
int g_itemCollectinitial(void* o, void* userData) {
    g_item item;
    g_itemWalk_t data;

    item = o;
    data = userData;

    if (!item->declareCount) {
        cx_llInsert(data->toPrint, item);
    }

    return 1;
}

/* Print items (forward them to declare & define callbacks) */
int g_itemPrintItems(struct g_itemWalk_t* data) {
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

static int g_itemResolveCycles(g_item item, struct g_itemWalk_t* data);

/* Scan stack for occurrence of dependency. */
cx_uint32 g_dependencyOnStack(g_dependency dep, struct g_itemWalk_t* data) {
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
static void g_itemResolveDependencyCycles(g_dependency dep, struct g_itemWalk_t* data) {
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
                if (data->stack[i]->weak) {
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
static int g_itemResolveCycles(g_item item, struct g_itemWalk_t* data) {
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

static int cx_genDeclareAction(cx_object o, void* userData) {
    g_itemWalk_t data;
    data = userData;
    data->onDeclare(o, data->userData);
    return 1;
}

static int cx_genDefineAction(cx_object o, void* userData) {
    g_itemWalk_t data;
    data = userData;
    if (cx_typeof(o)->real->kind != CX_VOID) {
        if (data->onDefine) {
    		data->onDefine(o, data->userData);
        }
    }
    return 1;
}

int cx_genCollectAnonymous(void* o, void* userData) {
	cx_ll list = userData;
	g_item item = o;

	if (!cx_checkAttr(item->o, CX_ATTR_SCOPED)) {
		cx_llInsert(list, item->o);
	}

	return 1;
}

/* Walk objects in correct dependency order. */
int cx_genDepWalk(cx_generator g, g_walkAction onDeclare, g_walkAction onDefine, void* userData) {
    struct g_itemWalk_t walkData;
    g_item item;
    cx_iter iter;

    /* Prepare walkData */
    walkData.g = g;
    walkData.items = cx_llNew();
    walkData.toPrint = cx_llNew();
    walkData.onDeclare = onDeclare;
    walkData.onDefine = onDefine;
    walkData.userData = userData;

    /* Build dependency administration */
    if (!g_walkRecursive(g, cx_genDepBuildAction, &walkData)) {
    	if (!walkData.bootstrap) {
    		cx_trace("dependency-builder failed.");
    		goto error;
    	} else {
    		g_walkRecursive(g, cx_genDeclareAction, &walkData);
    		g_walkRecursive(g, cx_genDefineAction, &walkData);
    	}

    	/* Cleanup administration */
    	while((item = cx_llTakeFirst(walkData.items))) {
    		g_itemFree(item);
    	}
    } else {
    	cx_ll anonymousObjects = cx_llNew();

    	/* Build dependency information for anonymous objects */
    	cx_llWalk(walkData.items, cx_genCollectAnonymous, anonymousObjects);
    	cx_llWalk(anonymousObjects, cx_genDepBuildAction, &walkData);
    	cx_llFree(anonymousObjects);

		/* Print initial items */
		if (g_itemPrintItems(&walkData)) {
			goto error;
		}

		/* Resolve items with cycles */
		iter = cx_llIter(walkData.items);
		while(cx_iterHasNext(&iter)) {
			item = cx_iterNext(&iter);

			/* Process objects that have not yet been defined or declared */
			if (!item->defined) {
				/* Locate and resolve cycles */
				walkData.sp = 0;
				if (g_itemResolveCycles(item, &walkData)) {
					goto error;
				}

				/* Print items after resolving cycle(s) for item. */
				if (g_itemPrintItems(&walkData)) {
					goto error;
				}
			}
		}


	    /* Free items and check if there are still undeclared or undefined objects. */
	    while((item = cx_llTakeFirst(walkData.items))) {
	        if (!item->defined) {
	            if (!item->declared) {
	                cx_id name;
	                cx_warning("object '%s' has not been declared or defined.", cx_fullname(item->o, name));
	            } else if (!item->defined){
	                cx_id name;
	                cx_warning("object '%s' has not been defined.", cx_fullname(item->o, name));
	            }
	        }
	        g_itemFree(item);
	    }
    }


    /* Free lists */
    cx_llFree(walkData.toPrint);
    cx_llFree(walkData.items);

    return 0;
error:
    return -1;
}

