/* test_Event.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#define test_LIB
#include "test.h"

/* ::test::Event::onDeclare */
/* $header(::test::Event::onDeclare) */
static int onDeclare;
/* $end */
cx_void _test_Event_onDeclare(test_Event this, cx_object observable, cx_object source) {
/* $begin(::test::Event::onDeclare) */
    onDeclare++;
/* $end */
}

/* ::test::Event::onDeclareScope */
/* $header(::test::Event::onDeclareScope) */
static int onDeclareScope;
/* $end */
cx_void _test_Event_onDeclareScope(test_Event this, cx_object observable, cx_object source) {
/* $begin(::test::Event::onDeclareScope) */
    onDeclareScope++;
/* $end */
}

/* ::test::Event::onDeclareSelf */
/* $header(::test::Event::onDeclareSelf) */
static int onDeclareSelf;
/* $end */
cx_void _test_Event_onDeclareSelf(test_Event this, cx_object observable, cx_object source) {
/* $begin(::test::Event::onDeclareSelf) */
    onDeclareSelf++;
/* $end */
}

/* ::test::Event::onDeclareTree */
/* $header(::test::Event::onDeclareTree) */
static int onDeclareTree;
/* $end */
cx_void _test_Event_onDeclareTree(test_Event this, cx_object observable, cx_object source) {
/* $begin(::test::Event::onDeclareTree) */
    onDeclareTree++;
/* $end */
}

/* ::test::Event::onDefine */
/* $header(::test::Event::onDefine) */
static int onDefine;
/* $end */
cx_void _test_Event_onDefine(test_Event this, cx_object observable, cx_object source) {
/* $begin(::test::Event::onDefine) */
    onDefine++;
/* $end */
}

/* ::test::Event::onDefineScope */
/* $header(::test::Event::onDefineScope) */
static int onDefineScope;
/* $end */
cx_void _test_Event_onDefineScope(test_Event this, cx_object observable, cx_object source) {
/* $begin(::test::Event::onDefineScope) */
    onDefineScope++;
/* $end */
}

/* ::test::Event::onDefineSelf */
/* $header(::test::Event::onDefineSelf) */
static int onDefineSelf;
/* $end */
cx_void _test_Event_onDefineSelf(test_Event this, cx_object observable, cx_object source) {
/* $begin(::test::Event::onDefineSelf) */
    onDefineSelf++;
/* $end */
}

/* ::test::Event::onDefineTree */
/* $header(::test::Event::onDefineTree) */
static int onDefineTree;
/* $end */
cx_void _test_Event_onDefineTree(test_Event this, cx_object observable, cx_object source) {
/* $begin(::test::Event::onDefineTree) */
    onDefineTree++;
/* $end */
}

/* ::test::Event::onDelete */
/* $header(::test::Event::onDelete) */
static int onDelete;
/* $end */
cx_void _test_Event_onDelete(test_Event this, cx_object observable, cx_object source) {
/* $begin(::test::Event::onDelete) */
    onDelete++;
/* $end */
}

/* ::test::Event::onDeleteScope */
/* $header(::test::Event::onDeleteScope) */
static int onDeleteScope;
/* $end */
cx_void _test_Event_onDeleteScope(test_Event this, cx_object observable, cx_object source) {
/* $begin(::test::Event::onDeleteScope) */
    onDeleteScope++;
/* $end */
}

/* ::test::Event::onDeleteSelf */
/* $header(::test::Event::onDeleteSelf) */
static int onDeleteSelf;
/* $end */
cx_void _test_Event_onDeleteSelf(test_Event this, cx_object observable, cx_object source) {
/* $begin(::test::Event::onDeleteSelf) */
    onDeleteSelf++;
/* $end */
}

/* ::test::Event::onDeleteTree */
/* $header(::test::Event::onDeleteTree) */
static int onDeleteTree;
/* $end */
cx_void _test_Event_onDeleteTree(test_Event this, cx_object observable, cx_object source) {
/* $begin(::test::Event::onDeleteTree) */
    onDeleteTree++;
/* $end */
}

/* ::test::Event::onUpdate */
/* $header(::test::Event::onUpdate) */
static int onUpdate;
/* $end */
cx_void _test_Event_onUpdate(test_Event this, cx_object observable, cx_object source) {
/* $begin(::test::Event::onUpdate) */
    onUpdate++;
/* $end */
}

/* ::test::Event::onUpdateScope */
/* $header(::test::Event::onUpdateScope) */
static int onUpdateScope;
/* $end */
cx_void _test_Event_onUpdateScope(test_Event this, cx_object observable, cx_object source) {
/* $begin(::test::Event::onUpdateScope) */
    onUpdateScope++;
/* $end */
}

/* ::test::Event::onUpdateSelf */
/* $header(::test::Event::onUpdateSelf) */
static int onUpdateSelf;
/* $end */
cx_void _test_Event_onUpdateSelf(test_Event this, cx_object observable, cx_object source) {
/* $begin(::test::Event::onUpdateSelf) */
    onUpdateSelf++;
/* $end */
}

/* ::test::Event::onUpdateTree */
/* $header(::test::Event::onUpdateTree) */
static int onUpdateTree;
/* $end */
cx_void _test_Event_onUpdateTree(test_Event this, cx_object observable, cx_object source) {
/* $begin(::test::Event::onUpdateTree) */
    onUpdateTree++;
/* $end */
}

/* ::test::Event::setup() */
/* $header(::test::Event::setup) */
static cx_object testScope;
/* $end */
cx_void _test_Event_setup(test_Event this) {
/* $begin(::test::Event::setup) */

    testScope = cx_voidCreateChild(NULL, "testScope");

    cx_observer_listen(test_Event_onDeclare_o, testScope, this);
    cx_observer_listen(test_Event_onDeclareSelf_o, testScope, this);
    cx_observer_listen(test_Event_onDeclareScope_o, testScope, this);
    cx_observer_listen(test_Event_onDeclareTree_o, testScope, this);

    cx_observer_listen(test_Event_onDefine_o, testScope, this);
    cx_observer_listen(test_Event_onDefineSelf_o, testScope, this);
    cx_observer_listen(test_Event_onDefineScope_o, testScope, this);
    cx_observer_listen(test_Event_onDefineTree_o, testScope, this); 

    cx_observer_listen(test_Event_onUpdate_o, testScope, this);
    cx_observer_listen(test_Event_onUpdateSelf_o, testScope, this);
    cx_observer_listen(test_Event_onUpdateScope_o, testScope, this);
    cx_observer_listen(test_Event_onUpdateTree_o, testScope, this);   

    cx_observer_listen(test_Event_onDelete_o, testScope, this);
    cx_observer_listen(test_Event_onDeleteSelf_o, testScope, this);
    cx_observer_listen(test_Event_onDeleteScope_o, testScope, this);
    cx_observer_listen(test_Event_onDeleteTree_o, testScope, this);

/* $end */
}

/* ::test::Event::tc_onDeclareScope() */
cx_void _test_Event_tc_onDeclareScope(test_Event this) {
/* $begin(::test::Event::tc_onDeclareScope) */

    /* << Insert implementation >> */

/* $end */
}

/* ::test::Event::tc_onDeclareSelf() */
cx_void _test_Event_tc_onDeclareSelf(test_Event this) {
/* $begin(::test::Event::tc_onDeclareSelf) */

    /* << Insert implementation >> */

/* $end */
}

/* ::test::Event::tc_onDeclareTree() */
cx_void _test_Event_tc_onDeclareTree(test_Event this) {
/* $begin(::test::Event::tc_onDeclareTree) */

    /* << Insert implementation >> */

/* $end */
}

/* ::test::Event::tc_onDefineScope() */
cx_void _test_Event_tc_onDefineScope(test_Event this) {
/* $begin(::test::Event::tc_onDefineScope) */

    /* << Insert implementation >> */

/* $end */
}

/* ::test::Event::tc_onDefineSelf() */
cx_void _test_Event_tc_onDefineSelf(test_Event this) {
/* $begin(::test::Event::tc_onDefineSelf) */

    /* << Insert implementation >> */

/* $end */
}

/* ::test::Event::tc_onDefineTree() */
cx_void _test_Event_tc_onDefineTree(test_Event this) {
/* $begin(::test::Event::tc_onDefineTree) */

    /* << Insert implementation >> */

/* $end */
}

/* ::test::Event::tc_onDeleteScope() */
cx_void _test_Event_tc_onDeleteScope(test_Event this) {
/* $begin(::test::Event::tc_onDeleteScope) */

    /* << Insert implementation >> */

/* $end */
}

/* ::test::Event::tc_onDeleteSelf() */
cx_void _test_Event_tc_onDeleteSelf(test_Event this) {
/* $begin(::test::Event::tc_onDeleteSelf) */

    /* << Insert implementation >> */

/* $end */
}

/* ::test::Event::tc_onDeleteTree() */
cx_void _test_Event_tc_onDeleteTree(test_Event this) {
/* $begin(::test::Event::tc_onDeleteTree) */

    /* << Insert implementation >> */

/* $end */
}

/* ::test::Event::tc_onUpdateScope() */
cx_void _test_Event_tc_onUpdateScope(test_Event this) {
/* $begin(::test::Event::tc_onUpdateScope) */

    /* << Insert implementation >> */

/* $end */
}

/* ::test::Event::tc_onUpdateSelf() */
cx_void _test_Event_tc_onUpdateSelf(test_Event this) {
/* $begin(::test::Event::tc_onUpdateSelf) */

    /* << Insert implementation >> */

/* $end */
}

/* ::test::Event::tc_onUpdateTree() */
cx_void _test_Event_tc_onUpdateTree(test_Event this) {
/* $begin(::test::Event::tc_onUpdateTree) */

    /* << Insert implementation >> */

/* $end */
}
