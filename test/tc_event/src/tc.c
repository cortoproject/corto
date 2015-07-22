/* tc.c
 *
 *  Generated on Feb  5 2014
 *    This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "tc.h"
#include "tc_event__meta.h"


/* $begin($header) */
#include "tc__event.h"

tc_data tcResult[observableLast];

void tc_reset(void) {
    memset(tcResult, 0, sizeof(tcResult));
}

cx_string tc_observableKindName(tc_observableKind kind) {
    switch(kind) {
    case observableOnUpdateBoth:
        return "ON_UPDATE|ON_SELF|ON_CHILDS";
    case observableOnUpdateChild:
        return "ON_UPDATE|ON_CHILDS";
    case observableOnUpdateSelf:
        return "ON_UPDATE|ON_SELF";
    case observableOnUpdateRootChilds:
        return "ON_UPDATE|ON_CHILDS root";
    case observableOnUpdateRootSelf:
        return "ON_UPDATE|ON_SELF root";
    case observableOnUpdateThis:
        return "ON_UPDATE|ON_SELF this";
    case observableOnNewBoth:
        return "ON_DECLARE|ON_SELF|ON_CHILDS";
    case observableOnNewChild:
        return "ON_DECLARE|ON_CHILDS";
    case observableOnNewSelf:
        return "ON_DECLARE|ON_SELF";
    case observableOnNewRootChilds:
        return "ON_DECLARE|ON_CHILDS root";
    case observableOnNewRootSelf:
        return "ON_DECLARE|ON_SELF root";
    case observableOnNewThis:
        return "ON_DECLARE|ON_SELF this";
    case observableOnConstructBoth:
        return "ON_DEFINE|ON_SELF|ON_CHILDS";
    case observableOnConstructChild:
        return "ON_DEFINE|ON_CHILDS";
    case observableOnConstructSelf:
        return "ON_DEFINE|ON_SELF";
    case observableOnConstructRootChilds:
        return "ON_DEFINE|ON_CHILDS root";
    case observableOnConstructRootSelf:
        return "ON_DEFINE|ON_SELF root";
    case observableOnConstructThis:
        return "ON_DEFINE|ON_SELF this";
    case observableOnDestructBoth:
        return "ON_DESTRUCT|ON_SELF|ON_CHILDS";
    case observableOnDestructChild:
        return "ON_DESTRUCT|ON_CHILDS";
    case observableOnDestructSelf:
        return "ON_DESTRUCT|ON_SELF";
    case observableOnDestructRootChilds:
        return "ON_DESTRUCT|ON_CHILDS root";
    case observableOnDestructRootSelf:
        return "ON_DESTRUCT|ON_SELF root";
    case observableOnDestructThis:
        return "ON_DESTRUCT|ON_SELF this";
    default:
        return "invalid observer";
    }
}

void tc_check(cx_string name, tc_observableKind kind, cx_uint32 count, cx_object _this, cx_object observable, cx_object source, cx_bool *result) {
    if (tcResult[kind].count != count) {
        printf("%s: %s: count mismatch: expected %d, got %d\n", name, tc_observableKindName(kind), count, tcResult[kind].count);
        *result = FALSE;
    }
    if (tcResult[kind]._this != _this) {
        cx_id id, id2;
        printf("%s: %s: _this mismatch: expected '%s', got '%s'\n",
                name, tc_observableKindName(kind), cx_fullname(_this, id), cx_fullname(tcResult[kind]._this, id2));
        *result = FALSE;
    }
    if (tcResult[kind].observable != observable) {
        cx_id id, id2;
        printf("%s: %s: observable mismatch: expected '%s', got '%s'\n",
                name, tc_observableKindName(kind), cx_fullname(observable, id), cx_fullname(tcResult[kind].observable, id2));
        *result = FALSE;
    }
    if (tcResult[kind].source != source) {
        cx_id id, id2;
        printf("%s: %s: source mismatch: expected '%s', got '%s'\n",
                name, tc_observableKindName(kind), cx_fullname(source, id), cx_fullname(tcResult[kind].source, id2));
        *result = FALSE;
    }
}

cx_bool tc_update(void) {
    cx_uint32 i;
    cx_bool success = TRUE;

    tc_reset();

    /* Do 10000 updates of parent */
    for(i=0; i<10000; i++) {
        cx_update(tc_parent_o);
    }

    tc_check("update parent", observableOnUpdateBoth, 10000, NULL, tc_parent_o, tc_parent_o, &success);
    tc_check("update parent", observableOnUpdateChild, 0, NULL, NULL, NULL, &success);
    tc_check("update parent", observableOnUpdateSelf, 10000, NULL, tc_parent_o, tc_parent_o, &success);
    tc_check("update parent", observableOnUpdateRootChilds, 10000, NULL, tc_parent_o, tc_parent_o, &success);
    tc_check("update parent", observableOnUpdateRootSelf, 0, NULL, NULL, NULL, &success);
    tc_check("update parent", observableOnUpdateThis, 0, NULL, NULL, NULL, &success);
    tc_reset();

    /* Do 10000 updates of child */
    for(i=0; i<10000; i++) {
        cx_update(tc_parent_child_o);
    }

    tc_check("update child", observableOnUpdateBoth, 10000, NULL, tc_parent_child_o, tc_parent_child_o, &success);
    tc_check("update child", observableOnUpdateChild, 10000, NULL, tc_parent_child_o, tc_parent_child_o, &success);
    tc_check("update child", observableOnUpdateSelf, 0, NULL, NULL, NULL, &success);
    tc_check("update child", observableOnUpdateRootChilds, 10000, NULL, tc_parent_child_o, tc_parent_child_o, &success);
    tc_check("update child", observableOnUpdateRootSelf, 0, NULL, NULL, NULL, &success);
    tc_check("update child", observableOnUpdateThis, 0, NULL, NULL, NULL, &success);
    tc_reset();

    /* Do 10000 updates of parent from child */
    for(i=0; i<10000; i++) {
        cx_updateFrom(tc_parent_o, tc_parent_child_o);
    }

    tc_check("update parent from child", observableOnUpdateBoth, 10000, NULL, tc_parent_o, tc_parent_child_o, &success);
    tc_check("update parent from child", observableOnUpdateChild, 0, NULL, NULL, NULL, &success);
    tc_check("update parent from child", observableOnUpdateSelf, 10000, NULL, tc_parent_o, tc_parent_child_o, &success);
    tc_check("update parent from child", observableOnUpdateRootChilds, 10000, NULL, tc_parent_o, tc_parent_child_o, &success);
    tc_check("update parent from child", observableOnUpdateRootSelf, 0, NULL, NULL, NULL, &success);
    tc_check("update parent from child", observableOnUpdateThis, 10000, tc_parent_o, tc_parent_o, tc_parent_child_o, &success);
    tc_reset();

    /* Do 10000 updates of root */
    for(i=0; i<10000; i++) {
        cx_update(root_o);
    }

    tc_check("update root", observableOnUpdateBoth, 0, NULL, NULL, NULL, &success);
    tc_check("update root", observableOnUpdateChild, 0, NULL, NULL, NULL, &success);
    tc_check("update root", observableOnUpdateSelf, 0, NULL, NULL, NULL, &success);
    tc_check("update root", observableOnUpdateRootChilds, 0, NULL, NULL, NULL, &success);
    tc_check("update root", observableOnUpdateRootSelf, 10000, NULL, root_o, root_o, &success);
    tc_check("update root", observableOnUpdateThis, 0, NULL, NULL, NULL, &success);
    tc_reset();

    return success;
}

cx_bool tc_new(void) {
    cx_uint32 i;
    cx_bool success = TRUE;
    cx_object o;
    cx_id id;

    tc_reset();

    /* Add 10000 childs to parent */
    for(i=0; i<10000; i++) {
        sprintf(id, "%d", i);
        o = cx_declare(tc_parent_o, id, cx_type(tc_value_o));
    }

    tc_check("new parent", observableOnNewBoth, 10000, NULL, tc_parent_o, o, &success);
    tc_check("new parent", observableOnNewChild, 0, NULL, NULL, NULL, &success);
    tc_check("new parent", observableOnNewSelf, 10000, NULL, tc_parent_o, o, &success);
    tc_check("new parent", observableOnNewRootChilds, 10000, NULL, tc_parent_o, o, &success);
    tc_check("new parent", observableOnNewRootSelf, 0, NULL, NULL, NULL, &success);
    tc_check("new parent", observableOnNewThis, 10000, tc_parent_o, tc_parent_o, o, &success);
    tc_reset();

    /* Add 10000 childs to child */
    for(i=0; i<10000; i++) {
        sprintf(id, "%d", i);
        o = cx_declare(tc_parent_child_o, id, cx_type(tc_value_o));
    }

    tc_check("new child", observableOnNewBoth, 10000, NULL, tc_parent_child_o, o, &success);
    tc_check("new child", observableOnNewChild, 10000, NULL, tc_parent_child_o, o, &success);
    tc_check("new child", observableOnNewSelf, 0, NULL, NULL, NULL, &success);
    tc_check("new child", observableOnNewRootChilds, 10000, NULL, tc_parent_child_o, o, &success);
    tc_check("new child", observableOnNewRootSelf, 0, NULL, NULL, NULL, &success);
    tc_check("new child", observableOnNewThis, 10000, tc_parent_child_o, tc_parent_child_o, o, &success);
    tc_reset();

    /* Add 10000 childs to root */
    for(i=0; i<10000; i++) {
        sprintf(id, "%d", i);
        o = cx_declare(root_o, id, cx_type(tc_value_o));
    }

    tc_check("new root", observableOnNewBoth, 0, NULL, NULL, NULL, &success);
    tc_check("new root", observableOnNewChild, 0, NULL, NULL, NULL, &success);
    tc_check("new root", observableOnNewSelf, 0, NULL, NULL, NULL, &success);
    tc_check("new root", observableOnNewRootChilds, 0, NULL, NULL, NULL, &success);
    tc_check("new root", observableOnNewRootSelf, 10000, NULL, root_o, o, &success);
    tc_check("new root", observableOnNewThis, 0, NULL, NULL, NULL, &success);
    tc_reset();

    return success;
}

/* This function implicitly tests whether no events are generated for objects that are already defined.
 * Additionally, if the load-routine did not define an object this function will also pick it up. */
cx_bool tc_construct(void) {
    cx_bool success = TRUE;
    cx_object o;
    cx_ll scope;
    cx_iter iter;

    tc_reset();

    /* Construct 10000 objects in parent */
    o = cx_resolve(NULL, "::tc_event::parent::9999"); cx_release(o);
    scope = cx_scopeClaim(tc_parent_o);
    iter = cx_llIter(scope);
    while(cx_iterHasNext(&iter)) {
        cx_define(cx_iterNext(&iter));
    }
    cx_scopeRelease(scope);

    tc_check("construct parent", observableOnConstructBoth, 10000, NULL, o, o, &success);
    tc_check("construct parent", observableOnConstructChild, 10000, NULL, o, o, &success);
    tc_check("construct parent", observableOnConstructSelf, 0, NULL, NULL, NULL, &success);
    tc_check("construct parent", observableOnConstructRootChilds, 10000, NULL, o, o, &success);
    tc_check("construct parent", observableOnConstructRootSelf, 0, NULL, NULL, NULL, &success);
    tc_check("construct parent", observableOnConstructThis, 0, NULL, NULL, NULL, &success);
    tc_reset();

    /* Construct 10000 objects in child */
    o = cx_resolve(NULL, "::tc_event::parent::child::9999");
    cx_release(o);
    scope = cx_scopeClaim(tc_parent_child_o);
    iter = cx_llIter(scope);
    while(cx_iterHasNext(&iter)) {
        cx_define(cx_iterNext(&iter));
    }
    cx_scopeRelease(scope);

    tc_check("construct child", observableOnConstructBoth, 10000, NULL, o, o, &success);
    tc_check("construct child", observableOnConstructChild, 10000, NULL, o, o, &success);
    tc_check("construct child", observableOnConstructSelf, 0, NULL, NULL, NULL, &success);
    tc_check("construct child", observableOnConstructRootChilds, 10000, NULL, o, o, &success);
    tc_check("construct child", observableOnConstructRootSelf, 0, NULL, NULL, NULL, &success);
    tc_check("construct child", observableOnConstructThis, 0, NULL, NULL, NULL, &success);
    tc_reset();

    /* Construct 10000 objects in root */
    o = cx_resolve(NULL, "::9999"); cx_release(o);
    scope = cx_scopeClaim(root_o);
    iter = cx_llIter(scope);
    while(cx_iterHasNext(&iter)) {
        cx_define(cx_iterNext(&iter));
    }
    cx_scopeRelease(scope);

    tc_check("construct root", observableOnConstructBoth, 0, NULL, NULL, NULL, &success);
    tc_check("construct root", observableOnConstructChild, 0, NULL, NULL, NULL, &success);
    tc_check("construct root", observableOnConstructSelf, 0, NULL, NULL, NULL, &success);
    tc_check("construct root", observableOnConstructRootChilds, 10000, NULL, o, o, &success);
    tc_check("construct root", observableOnConstructRootSelf, 0, NULL, NULL, NULL, &success);
    tc_check("construct root", observableOnConstructThis, 0, NULL, NULL, NULL, &success);
    tc_reset();

    return success;
}

cx_bool tc_destruct(void) {
    cx_bool success = TRUE;
    cx_object o, p;
    cx_ll scope;
    cx_iter iter;

    tc_reset();

    /* Destruct 10000 objects in parent */
    o = cx_resolve(NULL, "::tc_event::parent::9999"); cx_release(o);
    scope = cx_scopeClaim(tc_parent_o);
    iter = cx_llIter(scope);
    while(cx_iterHasNext(&iter)) {
        p = cx_iterNext(&iter);
        if (cx_typeof(p) == cx_type(tc_value_o)) {
            cx_delete(p);
        }
    }
    cx_scopeRelease(scope);

    tc_check("destruct parent", observableOnDestructBoth, 10000, NULL, o, o, &success);
    tc_check("destruct parent", observableOnDestructChild, 10000, NULL, o, o, &success);
    tc_check("destruct parent", observableOnDestructSelf, 0, NULL, NULL, NULL, &success);
    tc_check("destruct parent", observableOnDestructRootChilds, 10000, NULL, o, o, &success);
    tc_check("destruct parent", observableOnDestructRootSelf, 0, NULL, NULL, NULL, &success);
    tc_check("destruct parent", observableOnDestructThis, 0, NULL, NULL, NULL, &success);
    tc_reset();

    /* Destruct 10000 objects in child */
    o = cx_resolve(NULL, "::tc_event::parent::child::9999"); cx_release(o);
    scope = cx_scopeClaim(tc_parent_child_o);
    iter = cx_llIter(scope);
    while(cx_iterHasNext(&iter)) {
        p = cx_iterNext(&iter);
        if (cx_typeof(p) == cx_type(tc_value_o)) {
            cx_delete(p);
        }
    }
    cx_scopeRelease(scope);

    tc_check("destruct child", observableOnDestructBoth, 10000, NULL, o, o, &success);
    tc_check("destruct child", observableOnDestructChild, 10000, NULL, o, o, &success);
    tc_check("destruct child", observableOnDestructSelf, 0, NULL, NULL, NULL, &success);
    tc_check("destruct child", observableOnDestructRootChilds, 10000, NULL, o, o, &success);
    tc_check("destruct child", observableOnDestructRootSelf, 0, NULL, NULL, NULL, &success);
    tc_check("destruct child", observableOnDestructThis, 0, NULL, NULL, NULL, &success);
    tc_reset();

    /* Destruct 10000 objects in root */
    o = cx_resolve(NULL, "::9999"); cx_release(o);
    scope = cx_scopeClaim(root_o);
    iter = cx_llIter(scope);
    while(cx_iterHasNext(&iter)) {
        p = cx_iterNext(&iter);
        if (cx_typeof(p) == cx_type(tc_value_o)) {
            cx_delete(p);
        }
    }
    cx_scopeRelease(scope);

    tc_check("destruct root", observableOnDestructBoth, 0, NULL, NULL, NULL, &success);
    tc_check("destruct root", observableOnDestructChild, 0, NULL, NULL, NULL, &success);
    tc_check("destruct root", observableOnDestructSelf, 0, NULL, NULL, NULL, &success);
    tc_check("destruct root", observableOnDestructRootChilds, 10000, NULL, o, o, &success);
    tc_check("destruct root", observableOnDestructRootSelf, 0, NULL, NULL, NULL, &success);
    tc_check("destruct root", observableOnDestructThis, 0, NULL, NULL, NULL, &success);
    tc_reset();

    return success;
}

int main(int argc, char* argv[]) {
    cx_bool success = TRUE;
    CX_UNUSED(argc);
    CX_UNUSED(argv);

    cx_start();
    tc_event_load();

    if (!tc_update()) {
        printf("tc_update failed.\n");
        success = FALSE;
    }

    if (!tc_new()) {
        printf("tc_new failed.\n");
        success = FALSE;
    }

    if (!tc_construct()) {
        printf("tc_construct failed.\n");
        success = FALSE;
    }

    if (!tc_destruct()) {
        printf("tc_destruct failed.\n");
        success = FALSE;
    }

    if (success) {
        printf("tc_event success.\n");
    }

    cx_stop();

    return 0;
}
/* $end */

/* ::tc_event::construct_onBoth */
cx_void tc_construct_onBoth(cx_object *observable, cx_object *source) {
/* $begin(::tc_event::construct_onBoth) */
    tcResult[observableOnConstructBoth].count++;
    tcResult[observableOnConstructBoth]._this = NULL;
    tcResult[observableOnConstructBoth].observable = observable;
    tcResult[observableOnConstructBoth].source = source;
/* $end */
}

/* ::tc_event::construct_onChild */
cx_void tc_construct_onChild(cx_object *observable, cx_object *source) {
/* $begin(::tc_event::construct_onChild) */
    tcResult[observableOnConstructChild].count++;
    tcResult[observableOnConstructChild]._this = NULL;
    tcResult[observableOnConstructChild].observable = observable;
    tcResult[observableOnConstructChild].source = source;
/* $end */
}

/* ::tc_event::construct_onRootChilds */
cx_void tc_construct_onRootChilds(cx_object *observable, cx_object *source) {
/* $begin(::tc_event::construct_onRootChilds) */
    tcResult[observableOnConstructRootChilds].count++;
    tcResult[observableOnConstructRootChilds]._this = NULL;
    tcResult[observableOnConstructRootChilds].observable = observable;
    tcResult[observableOnConstructRootChilds].source = source;
/* $end */
}

/* ::tc_event::construct_onRootSelf */
cx_void tc_construct_onRootSelf(cx_object *observable, cx_object *source) {
/* $begin(::tc_event::construct_onRootSelf) */
    tcResult[observableOnConstructRootSelf].count++;
    tcResult[observableOnConstructRootSelf]._this = NULL;
    tcResult[observableOnConstructRootSelf].observable = observable;
    tcResult[observableOnConstructRootSelf].source = source;
/* $end */
}

/* ::tc_event::construct_onSelf */
cx_void tc_construct_onSelf(tc_Point *observable, cx_object *source) {
/* $begin(::tc_event::construct_onSelf) */
    tcResult[observableOnConstructSelf].count++;
    tcResult[observableOnConstructSelf]._this = NULL;
    tcResult[observableOnConstructSelf].observable = observable;
    tcResult[observableOnConstructSelf].source = source;
/* $end */
}

/* ::tc_event::destruct_onBoth */
cx_void tc_destruct_onBoth(cx_object *observable, cx_object *source) {
/* $begin(::tc_event::destruct_onBoth) */
    tcResult[observableOnDestructBoth].count++;
    tcResult[observableOnDestructBoth]._this = NULL;
    tcResult[observableOnDestructBoth].observable = observable;
    tcResult[observableOnDestructBoth].source = source;
/* $end */
}

/* ::tc_event::destruct_onChild */
cx_void tc_destruct_onChild(cx_object *observable, cx_object *source) {
/* $begin(::tc_event::destruct_onChild) */
    tcResult[observableOnDestructChild].count++;
    tcResult[observableOnDestructChild]._this = NULL;
    tcResult[observableOnDestructChild].observable = observable;
    tcResult[observableOnDestructChild].source = source;
/* $end */
}

/* ::tc_event::destruct_onRootChilds */
cx_void tc_destruct_onRootChilds(cx_object *observable, cx_object *source) {
/* $begin(::tc_event::destruct_onRootChilds) */
    tcResult[observableOnDestructRootChilds].count++;
    tcResult[observableOnDestructRootChilds]._this = NULL;
    tcResult[observableOnDestructRootChilds].observable = observable;
    tcResult[observableOnDestructRootChilds].source = source;
/* $end */
}

/* ::tc_event::destruct_onRootSelf */
cx_void tc_destruct_onRootSelf(cx_object *observable, cx_object *source) {
/* $begin(::tc_event::destruct_onRootSelf) */
    tcResult[observableOnDestructRootSelf].count++;
    tcResult[observableOnDestructRootSelf]._this = NULL;
    tcResult[observableOnDestructRootSelf].observable = observable;
    tcResult[observableOnDestructRootSelf].source = source;
/* $end */
}

/* ::tc_event::destruct_onSelf */
cx_void tc_destruct_onSelf(tc_Point *observable, cx_object *source) {
/* $begin(::tc_event::destruct_onSelf) */
    tcResult[observableOnDestructSelf].count++;
    tcResult[observableOnDestructSelf]._this = NULL;
    tcResult[observableOnDestructSelf].observable = observable;
    tcResult[observableOnDestructSelf].source = source;
/* $end */
}

/* ::tc_event::new_onBoth */
cx_void tc_new_onBoth(cx_object *observable, cx_object *source) {
/* $begin(::tc_event::new_onBoth) */
    tcResult[observableOnNewBoth].count++;
    tcResult[observableOnNewBoth]._this = NULL;
    tcResult[observableOnNewBoth].observable = observable;
    tcResult[observableOnNewBoth].source = source;
/* $end */
}

/* ::tc_event::new_onChild */
cx_void tc_new_onChild(cx_object *observable, cx_object *source) {
/* $begin(::tc_event::new_onChild) */
    tcResult[observableOnNewChild].count++;
    tcResult[observableOnNewChild]._this = NULL;
    tcResult[observableOnNewChild].observable = observable;
    tcResult[observableOnNewChild].source = source;
/* $end */
}

/* ::tc_event::new_onRootChilds */
cx_void tc_new_onRootChilds(cx_object *observable, cx_object *source) {
/* $begin(::tc_event::new_onRootChilds) */
    tcResult[observableOnNewRootChilds].count++;
    tcResult[observableOnNewRootChilds]._this = NULL;
    tcResult[observableOnNewRootChilds].observable = observable;
    tcResult[observableOnNewRootChilds].source = source;
/* $end */
}

/* ::tc_event::new_onRootSelf */
cx_void tc_new_onRootSelf(cx_object *observable, cx_object *source) {
/* $begin(::tc_event::new_onRootSelf) */
    tcResult[observableOnNewRootSelf].count++;
    tcResult[observableOnNewRootSelf]._this = NULL;
    tcResult[observableOnNewRootSelf].observable = observable;
    tcResult[observableOnNewRootSelf].source = source;
/* $end */
}

/* ::tc_event::new_onSelf */
cx_void tc_new_onSelf(cx_object *observable, cx_object *source) {
/* $begin(::tc_event::new_onSelf) */
    tcResult[observableOnNewSelf].count++;
    tcResult[observableOnNewSelf]._this = NULL;
    tcResult[observableOnNewSelf].observable = observable;
    tcResult[observableOnNewSelf].source = source;
/* $end */
}

/* ::tc_event::update_onBoth */
cx_void tc_update_onBoth(cx_object *observable, cx_object *source) {
/* $begin(::tc_event::update_onBoth) */
    tcResult[observableOnUpdateBoth].count++;
    tcResult[observableOnUpdateBoth]._this = NULL;
    tcResult[observableOnUpdateBoth].observable = observable;
    tcResult[observableOnUpdateBoth].source = source;
/* $end */
}

/* ::tc_event::update_onChild */
cx_void tc_update_onChild(cx_object *observable, cx_object *source) {
/* $begin(::tc_event::update_onChild) */
    tcResult[observableOnUpdateChild].count++;
    tcResult[observableOnUpdateChild]._this = NULL;
    tcResult[observableOnUpdateChild].observable = observable;
    tcResult[observableOnUpdateChild].source = source;
/* $end */
}

/* ::tc_event::update_onRootChilds */
cx_void tc_update_onRootChilds(cx_object *observable, cx_object *source) {
/* $begin(::tc_event::update_onRootChilds) */
    tcResult[observableOnUpdateRootChilds].count++;
    tcResult[observableOnUpdateRootChilds]._this = NULL;
    tcResult[observableOnUpdateRootChilds].observable = observable;
    tcResult[observableOnUpdateRootChilds].source = source;
/* $end */
}

/* ::tc_event::update_onRootSelf */
cx_void tc_update_onRootSelf(cx_object *observable, cx_object *source) {
/* $begin(::tc_event::update_onRootSelf) */
    tcResult[observableOnUpdateRootSelf].count++;
    tcResult[observableOnUpdateRootSelf]._this = NULL;
    tcResult[observableOnUpdateRootSelf].observable = observable;
    tcResult[observableOnUpdateRootSelf].source = source;
/* $end */
}

/* ::tc_event::update_onSelf */
cx_void tc_update_onSelf(tc_Point *observable, cx_object *source) {
/* $begin(::tc_event::update_onSelf) */
    tcResult[observableOnUpdateSelf].count++;
    tcResult[observableOnUpdateSelf]._this = NULL;
    tcResult[observableOnUpdateSelf].observable = observable;
    tcResult[observableOnUpdateSelf].source = source;
/* $end */
}
