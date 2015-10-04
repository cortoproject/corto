/* test_Event.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "test.h"

/* $header() */
static cx_object testScope;
/* $end */

/* ::test::Event::setup() */
cx_void _test_Event_setup(test_Event this) {
/* $begin(::test::Event::setup) */
    testScope = cx_voidCreateChild(NULL, "testScope");
    test_assert(testScope != NULL);
    test_EventTest et = test_EventTestCreate(testScope);
    test_assert(et != NULL);
    cx_setref(&this->et, et);
/* $end */
}

/* ::test::Event::tc_onDeclare() */
cx_void _test_Event_tc_onDeclare(test_Event this) {
/* $begin(::test::Event::tc_onDeclare) */
    cx_int16 ret;

    test_assert(this->et->countDeclare == 1);

    cx_object o = cx_int32DeclareChild(testScope, "o");
    test_assert(o != NULL);
    test_assert(this->et->countDeclare == 2);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == o);

    ret = cx_define(o);
    test_assert(ret == 0);
    test_assert(this->et->countDeclare == 2);

    cx_object p = cx_int32CreateChild(testScope, "p", 0);
    test_assert(p != NULL);
    test_assert(this->et->countDeclare == 3);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == p);

    cx_object q = cx_int32DeclareChild(p, "q");
    test_assert(q != NULL);
    test_assert(this->et->countDeclare == 4);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == q);

    ret = cx_define(q);
    test_assert(ret == 0);
    test_assert(this->et->countDeclare == 4);

    cx_delete(o);
    cx_delete(p);

    test_assert(this->et->countDeclare == 4);

/* $end */
}

/* ::test::Event::tc_onDeclareScope() */
cx_void _test_Event_tc_onDeclareScope(test_Event this) {
/* $begin(::test::Event::tc_onDeclareScope) */
    cx_int16 ret;
    test_assert(this->et->countDeclareScope == 0);

    cx_object o = cx_int32DeclareChild(testScope, "o");
    test_assert(o != NULL);
    test_assert(this->et->countDeclareScope == 1);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == o);

    ret = cx_define(o);
    test_assert(ret == 0);
    test_assert(this->et->countDeclareScope == 1);

    cx_object p = cx_int32CreateChild(testScope, "p", 0);
    test_assert(p != NULL);
    test_assert(this->et->countDeclareScope == 2);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == p);

    cx_object q = cx_int32DeclareChild(p, "q");
    test_assert(q != NULL);
    test_assert(this->et->countDeclareScope == 2);

    cx_define(q);
    test_assert(this->et->countDeclareScope == 2);
    
    cx_delete(o);
    cx_delete(p);

    test_assert(this->et->countDeclareScope == 2);

/* $end */
}

/* ::test::Event::tc_onDeclareSelf() */
cx_void _test_Event_tc_onDeclareSelf(test_Event this) {
/* $begin(::test::Event::tc_onDeclareSelf) */
    cx_int16 ret;

    test_assert(this->et->countDeclareSelf == 1);
    test_assert(this->et->lastObservable == testScope);

    cx_object o = cx_int32DeclareChild(testScope, "o");
    test_assert(o != NULL);
    test_assert(this->et->countDeclareSelf == 1);

    ret = cx_define(o);
    test_assert(ret == 0);
    test_assert(this->et->countDeclareSelf == 1);

    cx_object p = cx_int32CreateChild(testScope, "p", 0);
    test_assert(p != NULL);
    test_assert(this->et->countDeclareSelf == 1);

    cx_object q = cx_int32DeclareChild(p, "q");
    test_assert(q != NULL);
    test_assert(this->et->countDeclareSelf == 1);

    ret = cx_define(q);
    test_assert(ret == 0);
    test_assert(this->et->countDeclareSelf == 1);

    cx_delete(o);
    cx_delete(p);

    test_assert(this->et->countDeclareSelf == 1);

/* $end */
}

/* ::test::Event::tc_onDeclareTree() */
cx_void _test_Event_tc_onDeclareTree(test_Event this) {
/* $begin(::test::Event::tc_onDeclareTree) */
    cx_int16 ret;

    test_assert(this->et->countDeclareTree == 0);

    cx_object o = cx_int32DeclareChild(testScope, "o");
    test_assert(o != NULL);
    test_assert(this->et->countDeclareTree == 1);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == o);

    ret = cx_define(o);
    test_assert(ret == 0);
    test_assert(this->et->countDeclareTree == 1);

    cx_object p = cx_int32CreateChild(testScope, "p", 0);
    test_assert(p != NULL);
    test_assert(this->et->countDeclareTree == 2);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == p);

    cx_object q = cx_int32DeclareChild(p, "q");
    test_assert(q != NULL);
    test_assert(this->et->countDeclareTree == 3);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == q);

    ret = cx_define(q);
    test_assert(ret == 0);
    test_assert(this->et->countDeclareTree == 3);

    cx_delete(o);
    cx_delete(p);

    test_assert(this->et->countDeclareTree == 3);

/* $end */
}

/* ::test::Event::tc_onDefine() */
cx_void _test_Event_tc_onDefine(test_Event this) {
/* $begin(::test::Event::tc_onDefine) */
    cx_int16 ret;
    test_assert(this->et->countDefine == 1);

    cx_object o = cx_int32DeclareChild(testScope, "o");
    test_assert(o != NULL);
    test_assert(this->et->countDefine == 1);

    ret = cx_define(o);
    test_assert(ret == 0);
    test_assert(this->et->countDefine == 2);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == o);

    cx_object p = cx_int32CreateChild(testScope, "p", 0);
    test_assert(p != NULL);
    test_assert(this->et->countDefine == 3);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == p);

    cx_object q = cx_int32DeclareChild(p, "q");
    test_assert(q != NULL);
    test_assert(this->et->countDefine == 3);

    ret = cx_define(q);
    test_assert(ret == 0);
    test_assert(this->et->countDefine == 4);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == q);

    cx_delete(o);
    cx_delete(p);

    test_assert(this->et->countDefine == 4);

/* $end */
}

/* ::test::Event::tc_onDefineScope() */
cx_void _test_Event_tc_onDefineScope(test_Event this) {
/* $begin(::test::Event::tc_onDefineScope) */
    cx_int16 ret;

    test_assert(this->et->countDefineScope == 0);

    cx_object o = cx_int32DeclareChild(testScope, "o");
    test_assert(o != NULL);
    test_assert(this->et->countDefineScope == 0);

    ret = cx_define(o);
    test_assert(ret == 0);
    test_assert(this->et->countDefineScope == 1);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == o);

    cx_object p = cx_int32CreateChild(testScope, "p", 0);
    test_assert(p != NULL);
    test_assert(this->et->countDefineScope == 2);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == p);

    cx_object q = cx_int32DeclareChild(p, "q");
    test_assert(q != NULL);
    test_assert(this->et->countDefineScope == 2);

    ret = cx_define(q);
    test_assert(ret == 0);
    test_assert(this->et->countDefineScope == 2);

    cx_delete(o);
    cx_delete(p);

    test_assert(this->et->countDefineScope == 2);

/* $end */
}

/* ::test::Event::tc_onDefineSelf() */
cx_void _test_Event_tc_onDefineSelf(test_Event this) {
/* $begin(::test::Event::tc_onDefineSelf) */
    cx_int16 ret;

    test_assert(this->et->countDefineSelf == 1);

    cx_object o = cx_int32DeclareChild(testScope, "o");
    test_assert(o != NULL);
    test_assert(this->et->countDefineSelf == 1);

    ret = cx_define(o);
    test_assert(ret == 0);
    test_assert(this->et->countDefineSelf == 1);

    cx_object p = cx_int32CreateChild(testScope, "p", 0);
    test_assert(p != NULL);
    test_assert(this->et->countDefineSelf == 1);

    cx_object q = cx_int32DeclareChild(p, "q");
    test_assert(q != NULL);
    test_assert(this->et->countDefineSelf == 1);

    ret = cx_define(q);
    test_assert(ret == 0);
    test_assert(this->et->countDefineSelf == 1);

    cx_delete(o);
    cx_delete(p);

    test_assert(this->et->countDefineSelf == 1);

/* $end */
}

/* ::test::Event::tc_onDefineTree() */
cx_void _test_Event_tc_onDefineTree(test_Event this) {
/* $begin(::test::Event::tc_onDefineTree) */
    cx_int16 ret;

    test_assert(this->et->countDefineTree == 0);

    cx_object o = cx_int32DeclareChild(testScope, "o");
    test_assert(o != NULL);
    test_assert(this->et->countDefineTree == 0);

    ret = cx_define(o);
    test_assert(ret == 0);
    test_assert(this->et->countDefineTree == 1);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == o);

    cx_object p = cx_int32CreateChild(testScope, "p", 0);
    test_assert(p != NULL);
    test_assert(this->et->countDefineTree == 2);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == p);

    cx_object q = cx_int32DeclareChild(p, "q");
    test_assert(q != NULL);
    test_assert(this->et->countDefineTree == 2);

    ret = cx_define(q);
    test_assert(ret == 0);
    test_assert(this->et->countDefineTree == 3);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == q);

    cx_delete(o);
    cx_delete(p);

    test_assert(this->et->countDefineTree == 3);

/* $end */
}

/* ::test::Event::tc_onDelete() */
cx_void _test_Event_tc_onDelete(test_Event this) {
/* $begin(::test::Event::tc_onDelete) */
    cx_int16 ret;

    test_assert(this->et->countDelete == 0);

    cx_object o = cx_int32DeclareChild(testScope, "o");
    test_assert(o != NULL);
    test_assert(this->et->countDelete == 0);

    ret = cx_define(o);
    test_assert(ret == 0);
    test_assert(this->et->countDelete == 0);

    cx_object p = cx_int32CreateChild(testScope, "p", 0);
    test_assert(p != NULL);
    test_assert(this->et->countDelete == 0);

    cx_object q = cx_int32DeclareChild(p, "q");
    test_assert(q != NULL);
    test_assert(this->et->countDelete == 0);

    ret = cx_define(q);
    test_assert(ret == 0);
    test_assert(this->et->countDelete == 0);

    cx_delete(o);
    test_assert(this->et->countDelete == 1);

    cx_delete(p);
    test_assert(this->et->countDelete == 3);

/* $end */
}

/* ::test::Event::tc_onDeleteScope() */
cx_void _test_Event_tc_onDeleteScope(test_Event this) {
/* $begin(::test::Event::tc_onDeleteScope) */
    cx_int16 ret;

    test_assert(this->et->countDeleteScope == 0);

    cx_object o = cx_int32DeclareChild(testScope, "o");
    test_assert(o != NULL);
    test_assert(this->et->countDeleteScope == 0);

    ret = cx_define(o);
    test_assert(ret == 0);
    test_assert(this->et->countDeleteScope == 0);

    cx_object p = cx_int32CreateChild(testScope, "p", 0);
    test_assert(p != NULL);
    test_assert(this->et->countDeleteScope == 0);

    cx_object q = cx_int32DeclareChild(p, "q");
    test_assert(q != NULL);
    test_assert(this->et->countDeleteScope == 0);

    ret = cx_define(q);
    test_assert(ret == 0);
    test_assert(this->et->countDeleteScope == 0);

    cx_delete(o);
    test_assert(this->et->countDeleteScope == 1);

    cx_delete(p);
    test_assert(this->et->countDeleteScope == 2);

/* $end */
}

/* ::test::Event::tc_onDeleteSelf() */
cx_void _test_Event_tc_onDeleteSelf(test_Event this) {
/* $begin(::test::Event::tc_onDeleteSelf) */
    cx_int16 ret;

    test_assert(this->et->countDeleteSelf == 0);

    cx_object o = cx_int32DeclareChild(testScope, "o");
    test_assert(o != NULL);
    test_assert(this->et->countDeleteSelf == 0);

    ret = cx_define(o);
    test_assert(ret == 0);
    test_assert(this->et->countDeleteSelf == 0);

    cx_object p = cx_int32CreateChild(testScope, "p", 0);
    test_assert(p != NULL);
    test_assert(this->et->countDeleteSelf == 0);

    cx_object q = cx_int32DeclareChild(p, "q");
    test_assert(q != NULL);
    test_assert(this->et->countDeleteSelf == 0);

    ret = cx_define(q);
    test_assert(ret == 0);
    test_assert(this->et->countDeleteSelf == 0);

    cx_delete(o);
    test_assert(this->et->countDeleteSelf == 0);

    cx_delete(p);
    test_assert(this->et->countDeleteSelf == 0);

/* $end */
}

/* ::test::Event::tc_onDeleteTree() */
cx_void _test_Event_tc_onDeleteTree(test_Event this) {
/* $begin(::test::Event::tc_onDeleteTree) */
    cx_int16 ret;

    test_assert(this->et->countDeleteTree == 0);

    cx_object o = cx_int32DeclareChild(testScope, "o");
    test_assert(o != NULL);
    test_assert(this->et->countDeleteTree == 0);

    ret = cx_define(o);
    test_assert(ret == 0);
    test_assert(this->et->countDeleteTree == 0);

    cx_object p = cx_int32CreateChild(testScope, "p", 0);
    test_assert(p != NULL);
    test_assert(this->et->countDeleteTree == 0);

    cx_object q = cx_int32DeclareChild(p, "q");
    test_assert(q != NULL);
    test_assert(this->et->countDeleteTree == 0);

    ret = cx_define(q);
    test_assert(ret == 0);
    test_assert(this->et->countDeleteTree == 0);

    cx_delete(o);
    test_assert(this->et->countDeleteTree == 1);

    cx_delete(p);
    test_assert(this->et->countDeleteTree == 3);

/* $end */
}

/* ::test::Event::tc_onUpdate() */
cx_void _test_Event_tc_onUpdate(test_Event this) {
/* $begin(::test::Event::tc_onUpdate) */
    int ret;

    test_assert(this->et->countUpdate == 0);

    ret = cx_update(testScope);
    test_assert(ret == 0);
    test_assert(this->et->countUpdate == 1);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == testScope);

    cx_object o = cx_int32DeclareChild(testScope, "o");
    test_assert(o != NULL);
    test_assert(this->et->countUpdate == 1);

    ret = cx_updateBegin(o);
    test_assert(ret == -1);
    test_assert(this->et->countUpdate == 1);
    test_assert(!strcmp(cx_lasterr(), "cannot update undefined object"));

    ret = cx_define(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdate == 1);

    ret = cx_updateBegin(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdate == 1);

    ret = cx_updateEnd(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdate == 2);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == o);

    cx_object p = cx_int32CreateChild(testScope, "p", 0);
    test_assert(p != NULL);
    test_assert(this->et->countUpdate == 2);

    ret = cx_updateBegin(p);
    test_assert(ret == 0);
    test_assert(this->et->countUpdate == 2);

    ret = cx_updateEnd(p);
    test_assert(ret == 0);
    test_assert(this->et->countUpdate == 3);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == p);

    cx_object q = cx_int32DeclareChild(p, "q");
    test_assert(q != NULL);
    test_assert(this->et->countUpdate == 3);

    ret = cx_updateBegin(q);
    test_assert(ret == -1);
    test_assert(this->et->countUpdate == 3);
    test_assert(!strcmp(cx_lasterr(), "cannot update undefined object"));

    ret = cx_define(q);
    test_assert(ret == 0);
    test_assert(this->et->countUpdate == 3);

    ret = cx_updateBegin(q);
    test_assert(ret == 0);
    test_assert(this->et->countUpdate == 3);

    ret = cx_updateEnd(q);
    test_assert(ret == 0);
    test_assert(this->et->countUpdate == 4);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == q);

    cx_delete(o);
    cx_delete(p);

    test_assert(this->et->countUpdate == 4);

/* $end */
}

/* ::test::Event::tc_onUpdateScope() */
cx_void _test_Event_tc_onUpdateScope(test_Event this) {
/* $begin(::test::Event::tc_onUpdateScope) */
    int ret;

    test_assert(this->et->countUpdateScope == 0);

    ret = cx_update(testScope);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateScope == 0);

    cx_object o = cx_int32DeclareChild(testScope, "o");
    test_assert(o != NULL);
    test_assert(this->et->countUpdateScope == 0);

    ret = cx_updateBegin(o);
    test_assert(ret == -1);
    test_assert(this->et->countUpdateScope == 0);
    test_assert(!strcmp(cx_lasterr(), "cannot update undefined object"));

    ret = cx_define(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateScope == 0);

    ret = cx_updateBegin(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateScope == 0);

    ret = cx_updateEnd(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateScope == 1);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == o);

    cx_object p = cx_int32CreateChild(testScope, "p", 0);
    test_assert(p != NULL);
    test_assert(this->et->countUpdateScope == 1);

    ret = cx_updateBegin(p);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateScope == 1);

    ret = cx_updateEnd(p);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateScope == 2);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == p);

    cx_object q = cx_int32DeclareChild(p, "q");
    test_assert(q != NULL);
    test_assert(this->et->countUpdateScope == 2);

    ret = cx_updateBegin(q);
    test_assert(ret == -1);
    test_assert(this->et->countUpdateScope == 2);
    test_assert(!strcmp(cx_lasterr(), "cannot update undefined object"));

    ret = cx_define(q);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateScope == 2);

    ret = cx_updateBegin(q);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateScope == 2);

    ret = cx_updateEnd(q);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateScope == 2);    

    cx_delete(o);
    cx_delete(p);

    test_assert(this->et->countUpdateScope == 2);

/* $end */
}

/* ::test::Event::tc_onUpdateSelf() */
cx_void _test_Event_tc_onUpdateSelf(test_Event this) {
/* $begin(::test::Event::tc_onUpdateSelf) */
    int ret;

    test_assert(this->et->countUpdateSelf == 0);

    ret = cx_update(testScope);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateSelf == 1);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == testScope);

    cx_object o = cx_int32DeclareChild(testScope, "o");
    test_assert(o != NULL);
    test_assert(this->et->countUpdateSelf == 1);

    ret = cx_updateBegin(o);
    test_assert(ret == -1);
    test_assert(this->et->countUpdateSelf == 1);
    test_assert(!strcmp(cx_lasterr(), "cannot update undefined object"));

    ret = cx_define(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateSelf == 1);

    ret = cx_updateBegin(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateSelf == 1);

    ret = cx_updateEnd(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateSelf == 1);

    cx_object p = cx_int32CreateChild(testScope, "p", 0);
    test_assert(p != NULL);
    test_assert(this->et->countUpdateSelf == 1);

    ret = cx_updateBegin(p);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateSelf == 1);

    ret = cx_updateEnd(p);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateSelf == 1);

    cx_object q = cx_int32DeclareChild(p, "q");
    test_assert(q != NULL);
    test_assert(this->et->countUpdateSelf == 1);

    ret = cx_updateBegin(q);
    test_assert(ret == -1);
    test_assert(this->et->countUpdateSelf == 1);
    test_assert(!strcmp(cx_lasterr(), "cannot update undefined object"));

    ret = cx_define(q);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateSelf == 1);

    ret = cx_updateBegin(q);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateSelf == 1);

    ret = cx_updateEnd(q);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateSelf == 1);

    cx_delete(o);
    cx_delete(p);

    test_assert(this->et->countUpdateSelf == 1);

/* $end */
}

/* ::test::Event::tc_onUpdateTree() */
cx_void _test_Event_tc_onUpdateTree(test_Event this) {
/* $begin(::test::Event::tc_onUpdateTree) */
    int ret;

    test_assert(this->et->countUpdateTree == 0);

    ret = cx_update(testScope);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateTree == 0);

    cx_object o = cx_int32DeclareChild(testScope, "o");
    test_assert(o != NULL);
    test_assert(this->et->countUpdateTree == 0);

    ret = cx_updateBegin(o);
    test_assert(ret == -1);
    test_assert(this->et->countUpdateTree == 0);
    test_assert(!strcmp(cx_lasterr(), "cannot update undefined object"));

    ret = cx_define(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateTree == 0);

    ret = cx_updateBegin(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateTree == 0);

    ret = cx_updateEnd(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateTree == 1);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == o);

    cx_object p = cx_int32CreateChild(testScope, "p", 0);
    test_assert(p != NULL);
    test_assert(this->et->countUpdateTree == 1);

    ret = cx_updateBegin(p);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateTree == 1);

    ret = cx_updateEnd(p);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateTree == 2);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == p);

    cx_object q = cx_int32DeclareChild(p, "q");
    test_assert(q != NULL);
    test_assert(this->et->countUpdateTree == 2);

    ret = cx_updateBegin(q);
    test_assert(ret == -1);
    test_assert(this->et->countUpdateTree == 2);
    test_assert(!strcmp(cx_lasterr(), "cannot update undefined object"));

    ret = cx_define(q);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateTree == 2);

    ret = cx_updateBegin(q);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateTree == 2);

    ret = cx_updateEnd(q);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateTree == 3);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == q);

    cx_delete(o);
    cx_delete(p);

    test_assert(this->et->countUpdateTree == 3);

/* $end */
}

/* ::test::Event::tc_updateUndefined() */
cx_void _test_Event_tc_updateUndefined(test_Event this) {
/* $begin(::test::Event::tc_updateUndefined) */

    cx_object o = cx_int32DeclareChild(NULL, "o");
    test_assert(o != NULL);

    cx_int16 ret = cx_updateBegin(o);
    test_assert(ret == -1);
    test_assert(cx_lasterr() != NULL);
    test_assert(!strcmp(cx_lasterr(), "cannot update undefined object"));

/* $end */
}

/* ::test::Event::tc_updateVoidErr() */
cx_void _test_Event_tc_updateVoidErr(test_Event this) {
/* $begin(::test::Event::tc_updateVoidErr) */

    cx_object o = cx_int32CreateChild(NULL, "o", 10);
    test_assert(o != NULL);

    cx_int16 ret = cx_update(o);
    test_assert(ret == -1);
    test_assert(cx_lasterr() != NULL);
    test_assert(!strcmp(cx_lasterr(), "use updateBegin/updateEnd for non-void objects"));

/* $end */
}

/* ::test::Event::teardown() */
cx_void _test_Event_teardown(test_Event this) {
/* $begin(::test::Event::teardown) */
    cx_uint32 countDelete = this->et->countDelete;

    cx_delete(testScope);
    test_assert(countDelete + 1);
    test_assert(this->et->countDeleteSelf == 1);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == testScope);

/* $end */
}
