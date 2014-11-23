/*
 * db_generatorDepWalk.c
 *
 *  Created on: Sep 25, 2012
 *      Author: sander
 */

#include "hyve.h"
#include "db_generatorDepWalk.h"

#define CYCLE_DEPTH (1024)

typedef struct g_item* g_item;
struct g_item {
    db_object o;
    db_bool declared;
    db_bool defined;
    db_int32 declareCount;
    db_int32 defineCount;
    db_ll onDeclared;
    db_ll onDefined;
};

typedef struct g_dependency* g_dependency;
struct g_dependency {
    db_uint8 kind;
    g_item item;
    db_bool weak; /* A weak dependency may be degraded to DECLARED if a cycle can otherwise not be broken. */
    db_bool marked;
    db_bool processed; /* When a cycles are broken, it can occur that a dependency is resolved twice, as
                          a cycle is broken by resolving a dependency. This could cause refcounts to dive below
                          zero which is undesired. */
};

typedef struct g_itemWalk_t* g_itemWalk_t;
struct g_itemWalk_t {
    db_generator g;
    db_ll items;
    db_ll toPrint;
    g_walkAction onDeclare;
    g_walkAction onDefine;
    void* userData;
    g_dependency stack[CYCLE_DEPTH]; /* For cycle detection */
    db_uint32 sp;
    db_bool bootstrap; /* If a bootstrap is detected, disregard all dependencies. This can only mean that
    					  the builtin-types are being generated, since these are the only ones that can
    					  introduce a bootstrap (typeof(class) == class).
    					  In this case, dependencies don't matter (and are non-resolvable)*/
};

static int g_itemPrint(void* o, void* userData);

/* Create new item */
g_item g_itemNew(db_object o, g_itemWalk_t data) {
    g_item result;

    result = db_malloc(sizeof(struct g_item));
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

    db_llInsert(data->items, result);

    return result;
}

/* Delete item */
void g_itemFree(g_item item) {
    g_dependency dep;

    /* Free onDeclared list */
    if (item->onDeclared) {
        while((dep = db_llTakeFirst(item->onDeclared))) {
            db_dealloc(dep);
        }
        db_llFree(item->onDeclared);
    }

    /* Free onDefined list */
    if (item->onDefined) {
        while((dep = db_llTakeFirst(item->onDefined))) {
            db_dealloc(dep);
        }
        db_llFree(item->onDefined);
    }

    db_dealloc(item);
}

/* Lookup item in administration */
g_item g_itemLookup(db_object o, g_itemWalk_t data) {
    db_iter iter;
    g_item item;

    /* Lookup item for 'o' in items list */
    item = NULL;
    iter = db_llIter(data->items);
    while(!item && db_iterHasNext(&iter)) {
        item = db_iterNext(&iter);
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
void g_itemDepend(g_item o, db_uint8 kind, g_item dependency, db_uint8 dependencyKind) {
    g_dependency dep;

    db_assert(dependency->o != root_o, "invalid dependency on root.");

    if (o->o != dependency->o) {

		/* Create dependency object */
		dep = db_malloc(sizeof(struct g_dependency));
		dep->kind = kind;
		dep->item = o;
		dep->weak = FALSE;
		dep->marked = FALSE;
		dep->processed = FALSE;

		/* Increase corresponding counter */
		switch(kind) {
		case DB_DECLARED:
			o->declareCount++;
			break;
		case DB_DEFINED:
			o->defineCount++;
			break;
		default:
			db_assert(0, "invalid dependee-kind.");
			break;
		}

		/* Insert in corresponding list of dependency */
		switch(dependencyKind) {
		case DB_DECLARED:
			if (!dependency->onDeclared) {
				dependency->onDeclared = db_llNew();
			}
			db_llInsert(dependency->onDeclared, dep);
			break;
		case DB_DECLARED | DB_DEFINED:
			dep->weak = TRUE;
			/* no break */
		case DB_DEFINED:
			if (!dependency->onDefined) {
				dependency->onDefined = db_llNew();
			}
			db_llInsert(dependency->onDefined, dep);
			break;
		default:
			db_assert(0, "invalid dependency-kind.");
			break;
		}
    } else {
    	db_error("bootstrap detected while not in ::hyve::lang namespace - database corrupt!");
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
        case DB_DECLARED:
            dep->item->declareCount--;

            db_assert(dep->item->declareCount >= 0, "negative declareCount for item '%s'.", db_nameof(dep->item->o));

            if (!dep->item->declareCount) {
                db_llInsert(data->toPrint, dep->item);
            }
            break;
        case DB_DEFINED:
            dep->item->defineCount--;

            db_assert(dep->item->defineCount >= 0, "negative defineCount for item '%s'.", db_nameof(dep->item->o));

            if (!dep->item->defineCount) {
                db_llInsert(data->toPrint, dep->item);
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
    if ((db_typeof(item->o)->real->kind != DB_VOID) || (db_typeof(item->o)->real->reference)) {
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
            db_llWalk(item->onDeclared, g_itemResolveDependency, data);
        }
    }

    /* Walk DECLARED | DEFINED dependencies */
    if (item->declared && !item->defined && !item->defineCount) {
        item->defined = TRUE;
        g_itemDefine(item, data);
        if (item->onDefined) {
            db_llWalk(item->onDefined, g_itemResolveDependency, data);
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
db_int16 db_genDepReference(db_serializer s, db_value* info, void* userData) {
    db_object o;
    g_depWalk_t data;

    DB_UNUSED(s);

    data = userData;
    o = *(db_object*)db_valueValue(info);

    if (o && g_mustParse(data->data->g, o)) {
        g_item item;
        db_member m;

        m = NULL;
        item = g_itemLookup(o, data->data);

        if (info->kind == DB_MEMBER) {
            m = info->is.member.t;
            if (!m->type->real->reference) {
                m = NULL;
            }
        }

        /* Add dependency on item */
        if (m) {
            g_itemDepend(data->item, DB_DEFINED, item, m->state);
        } else {
            g_itemDepend(data->item, DB_DEFINED, item, DB_DEFINED);
        }
    }

    return 0;
}

/* Dependency serializer */
struct db_serializer_s db_genDepSerializer(void) {
    struct db_serializer_s s;

    db_serializerInit(&s);
    s.reference = db_genDepReference;
    s.access = DB_LOCAL;
    s.accessKind = DB_NOT;
    s.traceKind = DB_SERIALIZER_TRACE_ON_FAIL;

    return s;
}

/* Add dependencies for function arguments */
static int db_genDepBuildProc(g_item item, g_itemWalk_t data) {
    db_id typeBuff;
    db_function f;
    db_uint32 count, i;
    db_typedef t;
    g_item tItem;

    /* Walk through parameter types, add them as dependencies */
    f = item->o;

    if (db_procedure(db_typeof(f))->kind != DB_OBSERVER) {
		count = db_signatureParamCount(db_nameof(f));
		for(i=0; i<count; i++) {
			db_signatureParamType(db_nameof(f), i, typeBuff, NULL);
			t = db_resolve_ext(NULL, db_parentof(f), typeBuff, FALSE, "Resolve type for parameter in dependency builder");
			if (!t) {
				db_error("type '%s' in signature '%s' not found!", typeBuff, db_nameof(item->o));
				goto error;
			}
			if (g_mustParse(data->g, t)) {
				tItem = g_itemLookup(t, data);
				g_itemDepend(item, DB_DECLARED, tItem, DB_DECLARED | DB_DEFINED); /* The type must be at least declared when the function is declared. */
			}
			db_free_ext(NULL, t, "Free resolved parameter type for dependency builder");
		}
    }

    return 0;
error:
    return -1;
}

/* Build dependency-administration for object */
int db_genDepBuildAction(db_object o, void* userData) {
    g_itemWalk_t data;
    struct g_depWalk_t walkData;
    g_item dependee, type, parent;
    struct db_serializer_s s;
    int result;

    data = userData;

    /* If object is hyve_lang_o, signal that a bootstrap is found, indicating
     * that dependencies should be disregarded. */
    if (o == hyve_lang_o) {
    	data->bootstrap = TRUE;
    	result = 0;
    } else {
		/* Lookup item for dependee */
		dependee = g_itemLookup(o, data);

		/* Insert type-dependency: object can be declared only after it's type is defined. */
		if (g_mustParse(data->g, db_typeof(o))) {
			type = g_itemLookup(db_typeof(o), data);
			g_itemDepend(dependee, DB_DECLARED, type, DB_DEFINED);
		}

		if (db_class_instanceof(db_procedure_o, db_typeof(o))) {
			/* Insert base-dependency: methods may only be declared after the base of a class has been defined. */
			if (db_typeof(o) != db_typedef(db_function_o)) {
				if (db_class_instanceof(db_class_o, db_parentof(o)) && db_interface(db_parentof(o))->base) {
				    if (g_mustParse(data->g, db_interface(db_parentof(o))->base)) {
                        g_item base = g_itemLookup(db_interface(db_parentof(o))->base, data);
                        g_itemDepend(dependee, DB_DECLARED, base, DB_DEFINED);
				    }
				}
			}

			/* Add dependencies on function parameters - types must be declared before function is declared. */
			if (db_genDepBuildProc(dependee, data)) {
				goto error;
			}
		}

		/* Insert dependency on parent */
		if (db_checkAttr(o, DB_ATTR_SCOPED)) {
			parent = g_itemLookup(db_parentof(o), data);
			if (parent && (parent->o != root_o)) { /* Root is always available */
				switch(db_typedef(db_typeof(o))->real->parentState) {
				case 0:
				case DB_DECLARED | DB_DEFINED:
					/* If it doesn't matter whether the parent is declared or defined, mark
					 * the dependency as DECLARED, which ensures it is resolved as soon as possible. */
					g_itemDepend(dependee, DB_DECLARED, parent, DB_DECLARED);
					break;
				case DB_DECLARED:
					g_itemDepend(dependee, DB_DECLARED, parent, DB_DECLARED);

					/* If child must be declared when parent is declared, parent may only be defined after
					 * all such childs are defined. */
					g_itemDepend(parent, DB_DEFINED, dependee, DB_DEFINED);
					break;
				case DB_DEFINED:
					g_itemDepend(dependee, DB_DECLARED, parent, DB_DEFINED);
					break;
				}
			}
		}

		/* Insert dependencies on references in the object-value */
		walkData.item = dependee;
		walkData.data = data;
		s = db_genDepSerializer();
		if (db_serialize(&s, o, &walkData)) {
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
        db_llInsert(data->toPrint, item);
    }

    return 1;
}

/* Print items (forward them to declare & define callbacks) */
int g_itemPrintItems(struct g_itemWalk_t* data) {
    g_item item;

    /* Collect initial items */
    if (!db_llWalk(data->items, g_itemCollectinitial, data)) {
        goto error;
    }

    /* Print items */
    while((item = db_llTakeFirst(data->toPrint))) {
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
db_uint32 g_dependencyOnStack(g_dependency dep, struct g_itemWalk_t* data) {
    db_uint32 i;
    db_bool found;

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
    db_uint32 sp;

    /* If item is already marked, there is no need to investigate it further. */
    if (!dep->marked) {
        /* If dependency is not on stack, scan further, if on stack, a cycle is found. */
        if (!(sp = g_dependencyOnStack(dep, data))) {
            data->stack[data->sp] = dep;
            data->sp++;
            db_assert(data->sp < CYCLE_DEPTH, "stack-bound overflow.");

            /* Forward item and mark it. */
            g_itemResolveCycles(dep->item, data);
            dep->marked = TRUE;
            data->sp--;
        /* If a cycle is found, look on the stack for a weak dependency. */
        } else {
            db_uint32 i;

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
	db_iter iter;
	g_dependency dep;
	db_uint32 sp;

	sp = data->sp;

	/* If item has not yet been declared, search onDeclared list. If the item is already declared, the
	 * dependencies in this list have already been resolved, thus need not to be evaluated again. */
	if (!item->declared && item->onDeclared) {

		/* Walk dependencies */
		iter = db_llIter(item->onDeclared);
		while((db_iterHasNext(&iter))) {
			dep = db_iterNext(&iter);
			g_itemResolveDependencyCycles(dep, data);
		}
	}

	/* Walk onDefined list if item is not yet defined. */
	if (!item->defined && item->onDefined) {

        /* Walk dependencies */
        iter = db_llIter(item->onDefined);
        while((db_iterHasNext(&iter))) {
            dep = db_iterNext(&iter);
            g_itemResolveDependencyCycles(dep, data);
        }
 	}

	data->sp = sp;

	return 0;
}

static int db_genDeclareAction(db_object o, void* userData) {
    g_itemWalk_t data;
    data = userData;
    data->onDeclare(o, data->userData);
    return 1;
}

static int db_genDefineAction(db_object o, void* userData) {
    g_itemWalk_t data;
    data = userData;
    if (db_typeof(o)->real->kind != DB_VOID) {
        if (data->onDefine) {
    		data->onDefine(o, data->userData);
        }
    }
    return 1;
}

int db_genCollectAnonymous(void* o, void* userData) {
	db_ll list = userData;
	g_item item = o;

	if (!db_checkAttr(item->o, DB_ATTR_SCOPED)) {
		db_llInsert(list, item->o);
	}

	return 1;
}

/* Walk objects in correct dependency order. */
int db_genDepWalk(db_generator g, g_walkAction onDeclare, g_walkAction onDefine, void* userData) {
    struct g_itemWalk_t walkData;
    g_item item;
    db_iter iter;

    /* Prepare walkData */
    walkData.g = g;
    walkData.items = db_llNew();
    walkData.toPrint = db_llNew();
    walkData.onDeclare = onDeclare;
    walkData.onDefine = onDefine;
    walkData.userData = userData;

    /* Build dependency administration */
    if (!g_walkRecursive(g, db_genDepBuildAction, &walkData)) {
    	if (!walkData.bootstrap) {
    		db_trace("dependency-builder failed.");
    		goto error;
    	} else {
    		g_walkRecursive(g, db_genDeclareAction, &walkData);
    		g_walkRecursive(g, db_genDefineAction, &walkData);
    	}

    	/* Cleanup administration */
    	while((item = db_llTakeFirst(walkData.items))) {
    		g_itemFree(item);
    	}
    } else {
    	db_ll anonymousObjects = db_llNew();

    	/* Build dependency information for anonymous objects */
    	db_llWalk(walkData.items, db_genCollectAnonymous, anonymousObjects);
    	db_llWalk(anonymousObjects, db_genDepBuildAction, &walkData);
    	db_llFree(anonymousObjects);

		/* Print initial items */
		if (g_itemPrintItems(&walkData)) {
			goto error;
		}

		/* Resolve items with cycles */
		iter = db_llIter(walkData.items);
		while(db_iterHasNext(&iter)) {
			item = db_iterNext(&iter);

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
	    while((item = db_llTakeFirst(walkData.items))) {
	        if (!item->defined) {
	            if (!item->declared) {
	                db_id name;
	                db_warning("object '%s' has not been declared or defined.", db_fullname(item->o, name));
	            } else if (!item->defined){
	                db_id name;
	                db_warning("object '%s' has not been defined.", db_fullname(item->o, name));
	            }
	        }
	        g_itemFree(item);
	    }
    }


    /* Free lists */
    db_llFree(walkData.toPrint);
    db_llFree(walkData.items);

    return 0;
error:
    return -1;
}

