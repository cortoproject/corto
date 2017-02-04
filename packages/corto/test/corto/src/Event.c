/* $CORTO_GENERATED
 *
 * Event.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <include/test.h>

/* $header() */
static corto_object testScope;
/* $end */

corto_void _test_Event_setup(
    test_Event this)
{
/* $begin(test/Event/setup) */
    this->prevAttr = corto_setAttr(CORTO_ATTR_DEFAULT);
    testScope = corto_voidCreateChild(NULL, "testScope");
    test_assert(testScope != NULL);
    test_EventTest et = test_EventTestCreate(testScope);
    test_assert(et != NULL);
    corto_setref(&this->et, et);
    corto_release(et);

/* $end */
}

corto_void _test_Event_tc_onDeclare(
    test_Event this)
{
/* $begin(test/Event/tc_onDeclare) */
    corto_int16 ret;

    test_assert(this->et->countDeclare == 1);

    corto_object o = corto_int32DeclareChild(testScope, "o");
    test_assert(o != NULL);
    test_assert(this->et->countDeclare == 2);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == o);

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assert(this->et->countDeclare == 2);

    corto_object p = corto_int32CreateChild(testScope, "p", 0);
    test_assert(p != NULL);
    test_assert(this->et->countDeclare == 3);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == p);

    corto_object q = corto_int32DeclareChild(p, "q");
    test_assert(q != NULL);
    test_assert(this->et->countDeclare == 4);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == q);

    ret = corto_define(q);
    test_assert(ret == 0);
    test_assert(this->et->countDeclare == 4);

    corto_delete(o);
    corto_delete(p);

    test_assert(this->et->countDeclare == 4);

/* $end */
}

corto_void _test_Event_tc_onDeclareOrphan(
    test_Event this)
{
/* $begin(test/Event/tc_onDeclareOrphan) */
    corto_int16 ret;

    test_assert(this->et->countDeclare == 1);

    corto_object o = corto_declareOrphan(testScope, "o", corto_int32_o);
    test_assert(o != NULL);
    test_assert(this->et->countDeclare == 1);

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assert(this->et->countDeclare == 1);

    ret = corto_updateBegin(o);
    test_assert(ret == 0);
    test_assert(this->et->countDeclare == 1);
    ret = corto_updateEnd(o);
    test_assert(ret == 0);
    test_assert(this->et->countDeclare == 1);

    ret = corto_delete(o);
    test_assert(ret == 0);
    test_assert(this->et->countDeclare == 1);

/* $end */
}

corto_void _test_Event_tc_onDeclareScope(
    test_Event this)
{
/* $begin(test/Event/tc_onDeclareScope) */
    corto_int16 ret;
    test_assert(this->et->countDeclareScope == 0);

    corto_object o = corto_int32DeclareChild(testScope, "o");
    test_assert(o != NULL);
    test_assert(this->et->countDeclareScope == 1);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == o);

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assert(this->et->countDeclareScope == 1);

    corto_object p = corto_int32CreateChild(testScope, "p", 0);
    test_assert(p != NULL);
    test_assert(this->et->countDeclareScope == 2);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == p);

    corto_object q = corto_int32DeclareChild(p, "q");
    test_assert(q != NULL);
    test_assert(this->et->countDeclareScope == 2);

    corto_define(q);
    test_assert(this->et->countDeclareScope == 2);

    corto_delete(o);
    corto_delete(p);

    test_assert(this->et->countDeclareScope == 2);

/* $end */
}

corto_void _test_Event_tc_onDeclareScopeNotObservable(
    test_Event this)
{
/* $begin(test/Event/tc_onDeclareScopeNotObservable) */
    corto_int16 ret;
    corto_attr prevAttr = corto_setAttr(CORTO_ATTR_WRITABLE); /* Create non-observable objects */

    test_assert(this->et->countDeclareScope == 0);

    corto_object o = corto_int32DeclareChild(testScope, "o");
    test_assert(o != NULL);
    test_assert(this->et->countDeclareScope == 1);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == o);
    test_assert(!corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assert(this->et->countDeclareScope == 1);

    corto_object p = corto_int32CreateChild(testScope, "p", 0);
    test_assert(p != NULL);
    test_assert(this->et->countDeclareScope == 2);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == p);
    test_assert(!corto_checkAttr(p, CORTO_ATTR_OBSERVABLE));

    corto_object q = corto_int32DeclareChild(p, "q");
    test_assert(q != NULL);
    test_assert(this->et->countDeclareScope == 2);
    test_assert(!corto_checkAttr(q, CORTO_ATTR_OBSERVABLE));

    corto_define(q);
    test_assert(this->et->countDeclareScope == 2);

    corto_delete(o);
    corto_delete(p);

    test_assert(this->et->countDeclareScope == 2);

    corto_setAttr(prevAttr);

/* $end */
}

corto_void _test_Event_tc_onDeclareScopeOrphan(
    test_Event this)
{
/* $begin(test/Event/tc_onDeclareScopeOrphan) */
    corto_int16 ret;

    test_assert(this->et->countDeclareScope == 0);

    corto_object o = corto_declareOrphan(testScope, "o", corto_int32_o);
    test_assert(o != NULL);
    test_assert(this->et->countDeclareScope == 0);

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assert(this->et->countDeclareScope == 0);

    ret = corto_updateBegin(o);
    test_assert(ret == 0);
    test_assert(this->et->countDeclareScope == 0);
    ret = corto_updateEnd(o);
    test_assert(ret == 0);
    test_assert(this->et->countDeclareScope == 0);

    ret = corto_delete(o);
    test_assert(ret == 0);
    test_assert(this->et->countDeclareScope == 0);

/* $end */
}

corto_void _test_Event_tc_onDeclareSelf(
    test_Event this)
{
/* $begin(test/Event/tc_onDeclareSelf) */
    corto_int16 ret;

    test_assert(this->et->countDeclareSelf == 1);
    test_assert(this->et->lastObservable == testScope);

    corto_object o = corto_int32DeclareChild(testScope, "o");
    test_assert(o != NULL);
    test_assert(this->et->countDeclareSelf == 1);

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assert(this->et->countDeclareSelf == 1);

    corto_object p = corto_int32CreateChild(testScope, "p", 0);
    test_assert(p != NULL);
    test_assert(this->et->countDeclareSelf == 1);

    corto_object q = corto_int32DeclareChild(p, "q");
    test_assert(q != NULL);
    test_assert(this->et->countDeclareSelf == 1);

    ret = corto_define(q);
    test_assert(ret == 0);
    test_assert(this->et->countDeclareSelf == 1);

    corto_delete(o);
    corto_delete(p);

    test_assert(this->et->countDeclareSelf == 1);

/* $end */
}

corto_void _test_Event_tc_onDeclareSelfOrphan(
    test_Event this)
{
/* $begin(test/Event/tc_onDeclareSelfOrphan) */
    corto_int16 ret;

    test_assert(this->et->countDeclareSelf == 1);

    corto_object o = corto_declareOrphan(testScope, "o", corto_int32_o);
    test_assert(o != NULL);
    test_assert(this->et->countDeclareSelf == 1);

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assert(this->et->countDeclareSelf == 1);

    ret = corto_updateBegin(o);
    test_assert(ret == 0);
    test_assert(this->et->countDeclareSelf == 1);
    ret = corto_updateEnd(o);
    test_assert(ret == 0);
    test_assert(this->et->countDeclareSelf == 1);

    ret = corto_delete(o);
    test_assert(ret == 0);
    test_assert(this->et->countDeclareSelf == 1);

/* $end */
}

corto_void _test_Event_tc_onDeclareTree(
    test_Event this)
{
/* $begin(test/Event/tc_onDeclareTree) */
    corto_int16 ret;

    test_assert(this->et->countDeclareTree == 0);

    corto_object o = corto_int32DeclareChild(testScope, "o");
    test_assert(o != NULL);
    test_assert(this->et->countDeclareTree == 1);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == o);

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assert(this->et->countDeclareTree == 1);

    corto_object p = corto_int32CreateChild(testScope, "p", 0);
    test_assert(p != NULL);
    test_assert(this->et->countDeclareTree == 2);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == p);

    corto_object q = corto_int32DeclareChild(p, "q");
    test_assert(q != NULL);
    test_assert(this->et->countDeclareTree == 3);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == q);

    ret = corto_define(q);
    test_assert(ret == 0);
    test_assert(this->et->countDeclareTree == 3);

    corto_delete(o);
    corto_delete(p);

    test_assert(this->et->countDeclareTree == 3);

/* $end */
}

corto_void _test_Event_tc_onDeclareTreeNotObservable(
    test_Event this)
{
/* $begin(test/Event/tc_onDeclareTreeNotObservable) */
    corto_int16 ret;
    corto_attr prevAttr = corto_setAttr(CORTO_ATTR_WRITABLE); /* Create non-observable objects */

    test_assert(this->et->countDeclareTree == 0);

    corto_object o = corto_int32DeclareChild(testScope, "o");
    test_assert(o != NULL);
    test_assert(this->et->countDeclareTree == 1);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == o);
    test_assert(!corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assert(this->et->countDeclareTree == 1);

    corto_object p = corto_int32CreateChild(testScope, "p", 0);
    test_assert(p != NULL);
    test_assert(this->et->countDeclareTree == 2);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == p);
    test_assert(!corto_checkAttr(p, CORTO_ATTR_OBSERVABLE));

    corto_object q = corto_int32DeclareChild(p, "q");
    test_assert(q != NULL);
    test_assert(this->et->countDeclareTree == 3);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == q);
    test_assert(!corto_checkAttr(q, CORTO_ATTR_OBSERVABLE));

    ret = corto_define(q);
    test_assert(ret == 0);
    test_assert(this->et->countDeclareTree == 3);

    corto_delete(o);
    corto_delete(p);

    test_assert(this->et->countDeclareTree == 3);

    corto_setAttr(prevAttr);

/* $end */
}

corto_void _test_Event_tc_onDeclareTreeOrphan(
    test_Event this)
{
/* $begin(test/Event/tc_onDeclareTreeOrphan) */
    corto_int16 ret;

    test_assert(this->et->countDeclareTree == 0);

    corto_object o = corto_declareOrphan(testScope, "o", corto_int32_o);
    test_assert(o != NULL);
    test_assert(this->et->countDeclareTree == 0);

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assert(this->et->countDeclareTree == 0);

    ret = corto_updateBegin(o);
    test_assert(ret == 0);
    test_assert(this->et->countDeclareTree == 0);
    ret = corto_updateEnd(o);
    test_assert(ret == 0);
    test_assert(this->et->countDeclareTree == 0);

    ret = corto_delete(o);
    test_assert(ret == 0);
    test_assert(this->et->countDeclareTree == 0);

/* $end */
}

corto_void _test_Event_tc_onDefine(
    test_Event this)
{
/* $begin(test/Event/tc_onDefine) */
    corto_int16 ret;
    test_assert(this->et->countDefine == 1);

    corto_object o = corto_int32DeclareChild(testScope, "o");
    test_assert(o != NULL);
    test_assert(this->et->countDefine == 1);

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assert(this->et->countDefine == 2);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == o);

    corto_object p = corto_int32CreateChild(testScope, "p", 0);
    test_assert(p != NULL);
    test_assert(this->et->countDefine == 3);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == p);

    corto_object q = corto_int32DeclareChild(p, "q");
    test_assert(q != NULL);
    test_assert(this->et->countDefine == 3);

    ret = corto_define(q);
    test_assert(ret == 0);
    test_assert(this->et->countDefine == 4);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == q);

    corto_delete(o);
    corto_delete(p);

    test_assert(this->et->countDefine == 4);

/* $end */
}

corto_void _test_Event_tc_onDefineOrphan(
    test_Event this)
{
/* $begin(test/Event/tc_onDefineOrphan) */
    corto_int16 ret;

    test_assert(this->et->countDefine == 1);

    corto_object o = corto_declareOrphan(testScope, "o", corto_int32_o);
    test_assert(o != NULL);
    test_assert(this->et->countDefine == 1);

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assert(this->et->countDefine == 1);

    ret = corto_updateBegin(o);
    test_assert(ret == 0);
    test_assert(this->et->countDefine == 1);
    ret = corto_updateEnd(o);
    test_assert(ret == 0);
    test_assert(this->et->countDefine == 1);

    ret = corto_delete(o);
    test_assert(ret == 0);
    test_assert(this->et->countDefine == 1);

/* $end */
}

corto_void _test_Event_tc_onDefineScope(
    test_Event this)
{
/* $begin(test/Event/tc_onDefineScope) */
    corto_int16 ret;

    test_assertint(this->et->countDefineScope, 0);

    corto_object o = corto_int32DeclareChild(testScope, "o");
    test_assert(o != NULL);
    test_assertint(this->et->countDefineScope, 0);

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assertint(this->et->countDefineScope, 1);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == o);

    corto_object p = corto_int32CreateChild(testScope, "p", 0);
    test_assert(p != NULL);
    test_assertint(this->et->countDefineScope, 2);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == p);

    corto_object q = corto_int32DeclareChild(p, "q");
    test_assert(q != NULL);
    test_assertint(this->et->countDefineScope, 2);

    ret = corto_define(q);
    test_assert(ret == 0);
    test_assertint(this->et->countDefineScope, 2);

    corto_delete(o);
    corto_delete(p);

    test_assertint(this->et->countDefineScope, 2);

/* $end */
}

corto_void _test_Event_tc_onDefineScopeNotObservable(
    test_Event this)
{
/* $begin(test/Event/tc_onDefineScopeNotObservable) */
    corto_int16 ret;
    corto_attr attr = corto_setAttr(CORTO_ATTR_WRITABLE); /* Create non-observable objects */

    test_assert(this->et->countDefineScope == 0);

    corto_object o = corto_int32DeclareChild(testScope, "o");
    test_assert(o != NULL);
    test_assert(this->et->countDefineScope == 0);
    test_assert(!corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assert(this->et->countDefineScope == 1);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == o);

    corto_object p = corto_int32CreateChild(testScope, "p", 0);
    test_assert(p != NULL);
    test_assert(this->et->countDefineScope == 2);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == p);
    test_assert(!corto_checkAttr(p, CORTO_ATTR_OBSERVABLE));

    corto_object q = corto_int32DeclareChild(p, "q");
    test_assert(q != NULL);
    test_assert(this->et->countDefineScope == 2);
    test_assert(!corto_checkAttr(q, CORTO_ATTR_OBSERVABLE));

    ret = corto_define(q);
    test_assert(ret == 0);
    test_assert(this->et->countDefineScope == 2);

    corto_delete(o);
    corto_delete(p);

    test_assert(this->et->countDefineScope == 2);

    corto_setAttr(attr);

/* $end */
}

corto_void _test_Event_tc_onDefineScopeOrphan(
    test_Event this)
{
/* $begin(test/Event/tc_onDefineScopeOrphan) */
    corto_int16 ret;

    test_assert(this->et->countDefineScope == 0);

    corto_object o = corto_declareOrphan(testScope, "o", corto_int32_o);
    test_assert(o != NULL);
    test_assert(this->et->countDefineScope == 0);

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assert(this->et->countDefineScope == 0);

    ret = corto_updateBegin(o);
    test_assert(ret == 0);
    test_assert(this->et->countDefineScope == 0);
    ret = corto_updateEnd(o);
    test_assert(ret == 0);
    test_assert(this->et->countDefineScope == 0);

    ret = corto_delete(o);
    test_assert(ret == 0);
    test_assert(this->et->countDefineScope == 0);

/* $end */
}

corto_void _test_Event_tc_onDefineSelf(
    test_Event this)
{
/* $begin(test/Event/tc_onDefineSelf) */
    corto_int16 ret;

    test_assert(this->et->countDefineSelf == 1);

    corto_object o = corto_int32DeclareChild(testScope, "o");
    test_assert(o != NULL);
    test_assert(this->et->countDefineSelf == 1);

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assert(this->et->countDefineSelf == 1);

    corto_object p = corto_int32CreateChild(testScope, "p", 0);
    test_assert(p != NULL);
    test_assert(this->et->countDefineSelf == 1);

    corto_object q = corto_int32DeclareChild(p, "q");
    test_assert(q != NULL);
    test_assert(this->et->countDefineSelf == 1);

    ret = corto_define(q);
    test_assert(ret == 0);
    test_assert(this->et->countDefineSelf == 1);

    corto_delete(o);
    corto_delete(p);

    test_assert(this->et->countDefineSelf == 1);

/* $end */
}

corto_void _test_Event_tc_onDefineSelfOrphan(
    test_Event this)
{
/* $begin(test/Event/tc_onDefineSelfOrphan) */
    corto_int16 ret;

    test_assert(this->et->countDefineSelf == 1);

    corto_object o = corto_declareOrphan(testScope, "o", corto_int32_o);
    test_assert(o != NULL);
    test_assert(this->et->countDefineSelf == 1);

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assert(this->et->countDefineSelf == 1);

    ret = corto_updateBegin(o);
    test_assert(ret == 0);
    test_assert(this->et->countDefineSelf == 1);
    ret = corto_updateEnd(o);
    test_assert(ret == 0);
    test_assert(this->et->countDefineSelf == 1);

    ret = corto_delete(o);
    test_assert(ret == 0);
    test_assert(this->et->countDefineSelf == 1);

/* $end */
}

corto_void _test_Event_tc_onDefineTree(
    test_Event this)
{
/* $begin(test/Event/tc_onDefineTree) */
    corto_int16 ret;

    test_assert(this->et->countDefineTree == 0);

    corto_object o = corto_int32DeclareChild(testScope, "o");
    test_assert(o != NULL);
    test_assert(this->et->countDefineTree == 0);

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assert(this->et->countDefineTree == 1);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == o);

    corto_object p = corto_int32CreateChild(testScope, "p", 0);
    test_assert(p != NULL);
    test_assert(this->et->countDefineTree == 2);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == p);

    corto_object q = corto_int32DeclareChild(p, "q");
    test_assert(q != NULL);
    test_assert(this->et->countDefineTree == 2);

    ret = corto_define(q);
    test_assert(ret == 0);
    test_assert(this->et->countDefineTree == 3);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == q);

    corto_delete(o);
    corto_delete(p);

    test_assert(this->et->countDefineTree == 3);

/* $end */
}

corto_void _test_Event_tc_onDefineTreeNotObservable(
    test_Event this)
{
/* $begin(test/Event/tc_onDefineTreeNotObservable) */
    corto_int16 ret;
    corto_attr prevAttr = corto_setAttr(CORTO_ATTR_WRITABLE); /* Create non-observable objects */

    test_assert(this->et->countDefineTree == 0);

    corto_object o = corto_int32DeclareChild(testScope, "o");
    test_assert(o != NULL);
    test_assert(this->et->countDefineTree == 0);
    test_assert(!corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assert(this->et->countDefineTree == 1);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == o);

    corto_object p = corto_int32CreateChild(testScope, "p", 0);
    test_assert(p != NULL);
    test_assert(this->et->countDefineTree == 2);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == p);
    test_assert(!corto_checkAttr(p, CORTO_ATTR_OBSERVABLE));

    corto_object q = corto_int32DeclareChild(p, "q");
    test_assert(q != NULL);
    test_assert(this->et->countDefineTree == 2);
    test_assert(!corto_checkAttr(q, CORTO_ATTR_OBSERVABLE));

    ret = corto_define(q);
    test_assert(ret == 0);
    test_assert(this->et->countDefineTree == 3);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == q);

    corto_delete(o);
    corto_delete(p);

    test_assert(this->et->countDefineTree == 3);

    corto_setAttr(prevAttr);

/* $end */
}

corto_void _test_Event_tc_onDefineTreeOrphan(
    test_Event this)
{
/* $begin(test/Event/tc_onDefineTreeOrphan) */
    corto_int16 ret;

    test_assert(this->et->countDefineTree == 0);

    corto_object o = corto_declareOrphan(testScope, "o", corto_int32_o);
    test_assert(o != NULL);
    test_assert(this->et->countDefineTree == 0);

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assert(this->et->countDefineTree == 0);

    ret = corto_updateBegin(o);
    test_assert(ret == 0);
    test_assert(this->et->countDefineTree == 0);
    ret = corto_updateEnd(o);
    test_assert(ret == 0);
    test_assert(this->et->countDefineTree == 0);

    ret = corto_delete(o);
    test_assert(ret == 0);
    test_assert(this->et->countDefineTree == 0);

/* $end */
}

corto_void _test_Event_tc_onDelete(
    test_Event this)
{
/* $begin(test/Event/tc_onDelete) */
    corto_int16 ret;

    test_assert(this->et->countDelete == 0);

    corto_object o = corto_int32DeclareChild(testScope, "o");
    test_assert(o != NULL);
    test_assert(this->et->countDelete == 0);

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assert(this->et->countDelete == 0);

    corto_object p = corto_int32CreateChild(testScope, "p", 0);
    test_assert(p != NULL);
    test_assert(this->et->countDelete == 0);

    corto_object q = corto_int32DeclareChild(p, "q");
    test_assert(q != NULL);
    test_assert(this->et->countDelete == 0);

    ret = corto_define(q);
    test_assert(ret == 0);
    test_assert(this->et->countDelete == 0);

    corto_delete(o);
    test_assert(this->et->countDelete == 1);

    corto_delete(p);
    test_assert(this->et->countDelete == 3);

/* $end */
}

corto_void _test_Event_tc_onDeleteOrphan(
    test_Event this)
{
/* $begin(test/Event/tc_onDeleteOrphan) */
    corto_int16 ret;

    test_assert(this->et->countDelete == 0);

    corto_object o = corto_declareOrphan(testScope, "o", corto_int32_o);
    test_assert(o != NULL);
    test_assert(this->et->countDelete == 0);

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assert(this->et->countDelete == 0);

    ret = corto_updateBegin(o);
    test_assert(ret == 0);
    test_assert(this->et->countDelete == 0);
    ret = corto_updateEnd(o);
    test_assert(ret == 0);
    test_assert(this->et->countDelete == 0);

    ret = corto_delete(o);
    test_assert(ret == 0);
    test_assert(this->et->countDelete == 0);

/* $end */
}

corto_void _test_Event_tc_onDeleteScope(
    test_Event this)
{
/* $begin(test/Event/tc_onDeleteScope) */
    corto_int16 ret;

    test_assert(this->et->countDeleteScope == 0);

    corto_object o = corto_int32DeclareChild(testScope, "o");
    test_assert(o != NULL);
    test_assert(this->et->countDeleteScope == 0);

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assert(this->et->countDeleteScope == 0);

    corto_object p = corto_int32CreateChild(testScope, "p", 0);
    test_assert(p != NULL);
    test_assert(this->et->countDeleteScope == 0);

    corto_object q = corto_int32DeclareChild(p, "q");
    test_assert(q != NULL);
    test_assert(this->et->countDeleteScope == 0);

    ret = corto_define(q);
    test_assert(ret == 0);
    test_assert(this->et->countDeleteScope == 0);

    corto_delete(o);
    test_assert(this->et->countDeleteScope == 1);

    corto_delete(p);
    test_assert(this->et->countDeleteScope == 2);

/* $end */
}

corto_void _test_Event_tc_onDeleteScopeNotObservable(
    test_Event this)
{
/* $begin(test/Event/tc_onDeleteScopeNotObservable) */
    corto_int16 ret;
    corto_attr prevAttr = corto_setAttr(CORTO_ATTR_WRITABLE); /* Create non-observable objects */

    test_assert(this->et->countDeleteScope == 0);

    corto_object o = corto_int32DeclareChild(testScope, "o");
    test_assert(o != NULL);
    test_assert(this->et->countDeleteScope == 0);
    test_assert(!corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assert(this->et->countDeleteScope == 0);

    corto_object p = corto_int32CreateChild(testScope, "p", 0);
    test_assert(p != NULL);
    test_assert(this->et->countDeleteScope == 0);
    test_assert(!corto_checkAttr(p, CORTO_ATTR_OBSERVABLE));

    corto_object q = corto_int32DeclareChild(p, "q");
    test_assert(q != NULL);
    test_assert(this->et->countDeleteScope == 0);
    test_assert(!corto_checkAttr(q, CORTO_ATTR_OBSERVABLE));

    ret = corto_define(q);
    test_assert(ret == 0);
    test_assert(this->et->countDeleteScope == 0);

    corto_delete(o);
    test_assert(this->et->countDeleteScope == 1);

    corto_delete(p);
    test_assert(this->et->countDeleteScope == 2);

    corto_setAttr(prevAttr);

/* $end */
}

corto_void _test_Event_tc_onDeleteScopeOrphan(
    test_Event this)
{
/* $begin(test/Event/tc_onDeleteScopeOrphan) */
    corto_int16 ret;

    test_assert(this->et->countDeleteScope == 0);

    corto_object o = corto_declareOrphan(testScope, "o", corto_int32_o);
    test_assert(o != NULL);
    test_assert(this->et->countDeleteScope == 0);

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assert(this->et->countDeleteScope == 0);

    ret = corto_updateBegin(o);
    test_assert(ret == 0);
    test_assert(this->et->countDeleteScope == 0);
    ret = corto_updateEnd(o);
    test_assert(ret == 0);
    test_assert(this->et->countDeleteScope == 0);

    ret = corto_delete(o);
    test_assert(ret == 0);
    test_assert(this->et->countDeleteScope == 0);

/* $end */
}

corto_void _test_Event_tc_onDeleteSelf(
    test_Event this)
{
/* $begin(test/Event/tc_onDeleteSelf) */
    corto_int16 ret;

    test_assert(this->et->countDeleteSelf == 0);

    corto_object o = corto_int32DeclareChild(testScope, "o");
    test_assert(o != NULL);
    test_assert(this->et->countDeleteSelf == 0);

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assert(this->et->countDeleteSelf == 0);

    corto_object p = corto_int32CreateChild(testScope, "p", 0);
    test_assert(p != NULL);
    test_assert(this->et->countDeleteSelf == 0);

    corto_object q = corto_int32DeclareChild(p, "q");
    test_assert(q != NULL);
    test_assert(this->et->countDeleteSelf == 0);

    ret = corto_define(q);
    test_assert(ret == 0);
    test_assert(this->et->countDeleteSelf == 0);

    corto_delete(o);
    test_assert(this->et->countDeleteSelf == 0);

    corto_delete(p);
    test_assert(this->et->countDeleteSelf == 0);

/* $end */
}

corto_void _test_Event_tc_onDeleteSelfOrphan(
    test_Event this)
{
/* $begin(test/Event/tc_onDeleteSelfOrphan) */
    corto_int16 ret;

    test_assert(this->et->countDeleteSelf == 0);

    corto_object o = corto_declareOrphan(testScope, "o", corto_int32_o);
    test_assert(o != NULL);
    test_assert(this->et->countDeleteSelf == 0);

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assert(this->et->countDeleteSelf == 0);

    ret = corto_updateBegin(o);
    test_assert(ret == 0);
    test_assert(this->et->countDeleteSelf == 0);
    ret = corto_updateEnd(o);
    test_assert(ret == 0);
    test_assert(this->et->countDeleteSelf == 0);

    ret = corto_delete(o);
    test_assert(ret == 0);
    test_assert(this->et->countDeleteSelf == 0);

/* $end */
}

corto_void _test_Event_tc_onDeleteTree(
    test_Event this)
{
/* $begin(test/Event/tc_onDeleteTree) */
    corto_int16 ret;

    test_assert(this->et->countDeleteTree == 0);

    corto_object o = corto_int32DeclareChild(testScope, "o");
    test_assert(o != NULL);
    test_assert(this->et->countDeleteTree == 0);

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assert(this->et->countDeleteTree == 0);

    corto_object p = corto_int32CreateChild(testScope, "p", 0);
    test_assert(p != NULL);
    test_assert(this->et->countDeleteTree == 0);

    corto_object q = corto_int32DeclareChild(p, "q");
    test_assert(q != NULL);
    test_assert(this->et->countDeleteTree == 0);

    ret = corto_define(q);
    test_assert(ret == 0);
    test_assert(this->et->countDeleteTree == 0);

    corto_delete(o);
    test_assert(this->et->countDeleteTree == 1);

    corto_delete(p);
    test_assert(this->et->countDeleteTree == 3);

/* $end */
}

corto_void _test_Event_tc_onDeleteTreeNotObservable(
    test_Event this)
{
/* $begin(test/Event/tc_onDeleteTreeNotObservable) */
    corto_int16 ret;
    corto_attr prevAttr = corto_setAttr(CORTO_ATTR_WRITABLE); /* Create non-observable objects */

    test_assert(this->et->countDeleteTree == 0);

    corto_object o = corto_int32DeclareChild(testScope, "o");
    test_assert(o != NULL);
    test_assert(this->et->countDeleteTree == 0);
    test_assert(!corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assert(this->et->countDeleteTree == 0);

    corto_object p = corto_int32CreateChild(testScope, "p", 0);
    test_assert(p != NULL);
    test_assert(this->et->countDeleteTree == 0);
    test_assert(!corto_checkAttr(p, CORTO_ATTR_OBSERVABLE));

    corto_object q = corto_int32DeclareChild(p, "q");
    test_assert(q != NULL);
    test_assert(this->et->countDeleteTree == 0);
    test_assert(!corto_checkAttr(q, CORTO_ATTR_OBSERVABLE));

    ret = corto_define(q);
    test_assert(ret == 0);
    test_assert(this->et->countDeleteTree == 0);

    corto_delete(o);
    test_assert(this->et->countDeleteTree == 1);

    corto_delete(p);
    test_assert(this->et->countDeleteTree == 3);

    corto_setAttr(prevAttr);

/* $end */
}

corto_void _test_Event_tc_onDeleteTreeOrphan(
    test_Event this)
{
/* $begin(test/Event/tc_onDeleteTreeOrphan) */
    corto_int16 ret;

    test_assert(this->et->countDeleteTree == 0);

    corto_object o = corto_declareOrphan(testScope, "o", corto_int32_o);
    test_assert(o != NULL);
    test_assert(this->et->countDeleteTree == 0);

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assert(this->et->countDeleteTree == 0);

    ret = corto_updateBegin(o);
    test_assert(ret == 0);
    test_assert(this->et->countDeleteTree == 0);
    ret = corto_updateEnd(o);
    test_assert(ret == 0);
    test_assert(this->et->countDeleteTree == 0);

    ret = corto_delete(o);
    test_assert(ret == 0);
    test_assert(this->et->countDeleteTree == 0);

/* $end */
}

corto_void _test_Event_tc_onUpdate(
    test_Event this)
{
/* $begin(test/Event/tc_onUpdate) */
    int ret;

    test_assert(this->et->countUpdate == 0);

    ret = corto_update(testScope);
    test_assert(ret == 0);
    test_assert(this->et->countUpdate == 1);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == testScope);

    corto_object o = corto_int32DeclareChild(testScope, "o");
    test_assert(o != NULL);
    test_assert(this->et->countUpdate == 1);

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdate == 1);

    ret = corto_updateBegin(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdate == 1);

    corto_updateEnd(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdate == 2);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == o);

    corto_object p = corto_int32CreateChild(testScope, "p", 0);
    test_assert(p != NULL);
    test_assert(this->et->countUpdate == 2);

    ret = corto_updateBegin(p);
    test_assert(ret == 0);
    test_assert(this->et->countUpdate == 2);

    corto_updateEnd(p);
    test_assert(ret == 0);
    test_assert(this->et->countUpdate == 3);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == p);

    corto_object q = corto_int32DeclareChild(p, "q");
    test_assert(q != NULL);
    test_assert(this->et->countUpdate == 3);

    ret = corto_define(q);
    test_assert(ret == 0);
    test_assert(this->et->countUpdate == 3);

    ret = corto_updateBegin(q);
    test_assert(ret == 0);
    test_assert(this->et->countUpdate == 3);

    corto_updateEnd(q);
    test_assert(ret == 0);
    test_assert(this->et->countUpdate == 4);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == q);

    corto_delete(o);
    corto_delete(p);

    test_assert(this->et->countUpdate == 4);

/* $end */
}

corto_void _test_Event_tc_onUpdateDefine(
    test_Event this)
{
/* $begin(test/Event/tc_onUpdateDefine) */
    int ret;

    test_assert(this->et->countUpdateDefine == 1);

    ret = corto_update(testScope);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefine == 2);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == testScope);

    corto_object o = corto_int32DeclareChild(testScope, "o");
    test_assert(o != NULL);
    test_assert(this->et->countUpdateDefine == 2);

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefine == 3);

    ret = corto_updateBegin(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefine == 3);

    corto_updateEnd(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefine == 4);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == o);

    corto_object p = corto_int32CreateChild(testScope, "p", 0);
    test_assert(p != NULL);
    test_assert(this->et->countUpdateDefine == 5);

    ret = corto_updateBegin(p);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefine == 5);

    corto_updateEnd(p);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefine == 6);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == p);

    corto_object q = corto_int32DeclareChild(p, "q");
    test_assert(q != NULL);
    test_assert(this->et->countUpdateDefine == 6);

    ret = corto_define(q);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefine == 7);

    ret = corto_updateBegin(q);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefine == 7);

    corto_updateEnd(q);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefine == 8);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == q);

    corto_delete(o);
    corto_delete(p);

    test_assert(this->et->countUpdateDefine == 8);

/* $end */
}

corto_void _test_Event_tc_onUpdateDefineOrphan(
    test_Event this)
{
/* $begin(test/Event/tc_onUpdateDefineOrphan) */
    corto_int16 ret;

    test_assert(this->et->countUpdateDefine == 1);

    corto_object o = corto_declareOrphan(testScope, "o", corto_int32_o);
    test_assert(o != NULL);
    test_assert(this->et->countUpdateDefine == 1);

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefine == 1);

    ret = corto_updateBegin(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefine == 1);
    ret = corto_updateEnd(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefine == 2);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == testScope);

    ret = corto_delete(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefine == 2);

/* $end */
}

corto_void _test_Event_tc_onUpdateDefineScope(
    test_Event this)
{
/* $begin(test/Event/tc_onUpdateDefineScope) */
    int ret;

    test_assert(this->et->countUpdateDefineScope == 0);

    ret = corto_update(testScope);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineScope == 0);

    corto_object o = corto_int32DeclareChild(testScope, "o");
    test_assert(o != NULL);
    test_assert(this->et->countUpdateDefineScope == 0);

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineScope == 1);

    ret = corto_updateBegin(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineScope == 1);

    corto_updateEnd(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineScope == 2);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == o);

    corto_object p = corto_int32CreateChild(testScope, "p", 0);
    test_assert(p != NULL);
    test_assert(this->et->countUpdateDefineScope == 3);

    ret = corto_updateBegin(p);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineScope == 3);

    corto_updateEnd(p);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineScope == 4);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == p);

    corto_object q = corto_int32DeclareChild(p, "q");
    test_assert(q != NULL);
    test_assert(this->et->countUpdateDefineScope == 4);

    ret = corto_define(q);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineScope == 4);

    ret = corto_updateBegin(q);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineScope == 4);

    corto_updateEnd(q);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineScope == 4);

    corto_delete(o);
    corto_delete(p);

    test_assert(this->et->countUpdateDefineScope == 4);

/* $end */
}

corto_void _test_Event_tc_onUpdateDefineScopeNotObservable(
    test_Event this)
{
/* $begin(test/Event/tc_onUpdateDefineScopeNotObservable) */
    int ret;
    corto_attr prevAttr = corto_setAttr(CORTO_ATTR_WRITABLE); /* Create non-observable objects */

    test_assert(this->et->countUpdateDefineScope == 0);

    ret = corto_update(testScope);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineScope == 0);

    corto_object o = corto_int32DeclareChild(testScope, "o");
    test_assert(o != NULL);
    test_assert(this->et->countUpdateDefineScope == 0);
    test_assert(!corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineScope == 1);

    ret = corto_updateBegin(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineScope == 1);

    corto_updateEnd(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineScope == 2);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == o);

    corto_object p = corto_int32CreateChild(testScope, "p", 0);
    test_assert(p != NULL);
    test_assert(this->et->countUpdateDefineScope == 3);
    test_assert(!corto_checkAttr(p, CORTO_ATTR_OBSERVABLE));

    ret = corto_updateBegin(p);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineScope == 3);

    corto_updateEnd(p);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineScope == 4);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == p);

    corto_object q = corto_int32DeclareChild(p, "q");
    test_assert(q != NULL);
    test_assert(this->et->countUpdateDefineScope == 4);
    test_assert(!corto_checkAttr(q, CORTO_ATTR_OBSERVABLE));

    ret = corto_define(q);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineScope == 4);

    ret = corto_updateBegin(q);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineScope == 4);

    corto_updateEnd(q);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineScope == 4);

    corto_delete(o);
    corto_delete(p);

    test_assert(this->et->countUpdateDefineScope == 4);

    corto_setAttr(prevAttr);

/* $end */
}

corto_void _test_Event_tc_onUpdateDefineScopeOrphan(
    test_Event this)
{
/* $begin(test/Event/tc_onUpdateDefineScopeOrphan) */
    corto_int16 ret;

    test_assert(this->et->countUpdateDefineScope == 0);

    corto_object o = corto_declareOrphan(testScope, "o", corto_int32_o);
    test_assert(o != NULL);
    test_assert(this->et->countUpdateDefineScope == 0);

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineScope == 0);

    ret = corto_updateBegin(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineScope == 0);
    ret = corto_updateEnd(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineScope == 0);

    ret = corto_delete(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineScope == 0);

/* $end */
}

corto_void _test_Event_tc_onUpdateDefineSelf(
    test_Event this)
{
/* $begin(test/Event/tc_onUpdateDefineSelf) */
    int ret;

    test_assert(this->et->countUpdateDefineSelf == 1);

    ret = corto_update(testScope);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineSelf == 2);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == testScope);

    corto_object o = corto_int32DeclareChild(testScope, "o");
    test_assert(o != NULL);
    test_assert(this->et->countUpdateDefineSelf == 2);

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineSelf == 2);

    ret = corto_updateBegin(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineSelf == 2);

    corto_updateEnd(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineSelf == 2);

    corto_object p = corto_int32CreateChild(testScope, "p", 0);
    test_assert(p != NULL);
    test_assert(this->et->countUpdateDefineSelf == 2);

    ret = corto_updateBegin(p);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineSelf == 2);

    corto_updateEnd(p);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineSelf == 2);

    corto_object q = corto_int32DeclareChild(p, "q");
    test_assert(q != NULL);
    test_assert(this->et->countUpdateDefineSelf == 2);

    ret = corto_define(q);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineSelf == 2);

    ret = corto_updateBegin(q);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineSelf == 2);

    corto_updateEnd(q);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineSelf == 2);

    corto_delete(o);
    corto_delete(p);

    test_assert(this->et->countUpdateDefineSelf == 2);

/* $end */
}

corto_void _test_Event_tc_onUpdateDefineSelfOrphan(
    test_Event this)
{
/* $begin(test/Event/tc_onUpdateDefineSelfOrphan) */
    corto_int16 ret;

    test_assert(this->et->countUpdateDefineSelf == 1);

    corto_object o = corto_declareOrphan(testScope, "o", corto_int32_o);
    test_assert(o != NULL);
    test_assert(this->et->countUpdateDefineSelf == 1);

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineSelf == 1);

    ret = corto_updateBegin(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineSelf == 1);
    ret = corto_updateEnd(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineSelf == 2);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == testScope);

    ret = corto_delete(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineSelf == 2);

/* $end */
}

corto_void _test_Event_tc_onUpdateDefineTree(
    test_Event this)
{
/* $begin(test/Event/tc_onUpdateDefineTree) */
    int ret;

    test_assert(this->et->countUpdateDefineTree == 0);

    ret = corto_update(testScope);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineTree == 0);

    corto_object o = corto_int32DeclareChild(testScope, "o");
    test_assert(o != NULL);
    test_assert(this->et->countUpdateDefineTree == 0);

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineTree == 1);

    ret = corto_updateBegin(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineTree == 1);

    corto_updateEnd(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineTree == 2);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == o);

    corto_object p = corto_int32CreateChild(testScope, "p", 0);
    test_assert(p != NULL);
    test_assert(this->et->countUpdateDefineTree == 3);

    ret = corto_updateBegin(p);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineTree == 3);

    corto_updateEnd(p);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineTree == 4);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == p);

    corto_object q = corto_int32DeclareChild(p, "q");
    test_assert(q != NULL);
    test_assert(this->et->countUpdateDefineTree == 4);

    ret = corto_define(q);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineTree == 5);

    ret = corto_updateBegin(q);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineTree == 5);

    corto_updateEnd(q);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineTree == 6);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == q);

    corto_delete(o);
    corto_delete(p);

    test_assert(this->et->countUpdateDefineTree == 6);

/* $end */
}

corto_void _test_Event_tc_onUpdateDefineTreeNotObservable(
    test_Event this)
{
/* $begin(test/Event/tc_onUpdateDefineTreeNotObservable) */
    int ret;
    corto_attr prevAttr = corto_setAttr(CORTO_ATTR_WRITABLE); /* Create non-observable objects */

    test_assert(this->et->countUpdateDefineTree == 0);

    ret = corto_update(testScope);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineTree == 0);

    corto_object o = corto_int32DeclareChild(testScope, "o");
    test_assert(o != NULL);
    test_assert(this->et->countUpdateDefineTree == 0);
    test_assert(!corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineTree == 1);

    ret = corto_updateBegin(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineTree == 1);

    corto_updateEnd(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineTree == 2);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == o);

    corto_object p = corto_int32CreateChild(testScope, "p", 0);
    test_assert(p != NULL);
    test_assert(this->et->countUpdateDefineTree == 3);
    test_assert(!corto_checkAttr(p, CORTO_ATTR_OBSERVABLE));

    ret = corto_updateBegin(p);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineTree == 3);

    corto_updateEnd(p);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineTree == 4);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == p);

    corto_object q = corto_int32DeclareChild(p, "q");
    test_assert(q != NULL);
    test_assert(this->et->countUpdateDefineTree == 4);
    test_assert(!corto_checkAttr(q, CORTO_ATTR_OBSERVABLE));

    ret = corto_define(q);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineTree == 5);

    ret = corto_updateBegin(q);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineTree == 5);

    corto_updateEnd(q);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineTree == 6);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == q);

    corto_delete(o);
    corto_delete(p);

    test_assert(this->et->countUpdateDefineTree == 6);

    corto_setAttr(prevAttr);

/* $end */
}

corto_void _test_Event_tc_onUpdateDefineTreeOrphan(
    test_Event this)
{
/* $begin(test/Event/tc_onUpdateDefineTreeOrphan) */
    corto_int16 ret;

    test_assert(this->et->countUpdateDefineTree == 0);

    corto_object o = corto_declareOrphan(testScope, "o", corto_int32_o);
    test_assert(o != NULL);
    test_assert(this->et->countUpdateDefineTree == 0);

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineTree == 0);

    ret = corto_updateBegin(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineTree == 0);
    ret = corto_updateEnd(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineTree == 0);

    ret = corto_delete(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineTree == 0);

/* $end */
}

corto_void _test_Event_tc_onUpdateOrphan(
    test_Event this)
{
/* $begin(test/Event/tc_onUpdateOrphan) */
    corto_int16 ret;

    test_assert(this->et->countUpdate == 0);

    corto_object o = corto_declareOrphan(testScope, "o", corto_int32_o);
    test_assert(o != NULL);
    test_assert(this->et->countUpdate == 0);

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdate == 0);

    ret = corto_updateBegin(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdate == 0);
    ret = corto_updateEnd(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdate == 1);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == testScope);

    ret = corto_delete(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdate == 1);

/* $end */
}

corto_void _test_Event_tc_onUpdateScope(
    test_Event this)
{
/* $begin(test/Event/tc_onUpdateScope) */
    int ret;

    test_assert(this->et->countUpdateScope == 0);

    ret = corto_update(testScope);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateScope == 0);

    corto_object o = corto_int32DeclareChild(testScope, "o");
    test_assert(o != NULL);
    test_assert(this->et->countUpdateScope == 0);

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateScope == 0);

    ret = corto_updateBegin(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateScope == 0);

    corto_updateEnd(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateScope == 1);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == o);

    corto_object p = corto_int32CreateChild(testScope, "p", 0);
    test_assert(p != NULL);
    test_assert(this->et->countUpdateScope == 1);

    ret = corto_updateBegin(p);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateScope == 1);

    corto_updateEnd(p);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateScope == 2);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == p);

    corto_object q = corto_int32DeclareChild(p, "q");
    test_assert(q != NULL);
    test_assert(this->et->countUpdateScope == 2);

    ret = corto_define(q);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateScope == 2);

    ret = corto_updateBegin(q);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateScope == 2);

    corto_updateEnd(q);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateScope == 2);

    corto_delete(o);
    corto_delete(p);

    test_assert(this->et->countUpdateScope == 2);

/* $end */
}

corto_void _test_Event_tc_onUpdateScopeNotObservable(
    test_Event this)
{
/* $begin(test/Event/tc_onUpdateScopeNotObservable) */
    int ret;
    corto_attr prevAttr = corto_setAttr(CORTO_ATTR_WRITABLE); /* Create non-observable objects */

    test_assert(this->et->countUpdateScope == 0);

    ret = corto_update(testScope);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateScope == 0);

    corto_object o = corto_int32DeclareChild(testScope, "o");
    test_assert(o != NULL);
    test_assert(this->et->countUpdateScope == 0);
    test_assert(!corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateScope == 0);

    ret = corto_updateBegin(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateScope == 0);

    corto_updateEnd(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateScope == 1);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == o);

    corto_object p = corto_int32CreateChild(testScope, "p", 0);
    test_assert(p != NULL);
    test_assert(this->et->countUpdateScope == 1);
    test_assert(!corto_checkAttr(p, CORTO_ATTR_OBSERVABLE));

    ret = corto_updateBegin(p);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateScope == 1);

    corto_updateEnd(p);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateScope == 2);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == p);

    corto_object q = corto_int32DeclareChild(p, "q");
    test_assert(q != NULL);
    test_assert(this->et->countUpdateScope == 2);
    test_assert(!corto_checkAttr(q, CORTO_ATTR_OBSERVABLE));

    ret = corto_define(q);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateScope == 2);

    ret = corto_updateBegin(q);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateScope == 2);

    corto_updateEnd(q);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateScope == 2);

    corto_delete(o);
    corto_delete(p);

    test_assert(this->et->countUpdateScope == 2);

    corto_setAttr(prevAttr);

/* $end */
}

corto_void _test_Event_tc_onUpdateScopeOrphan(
    test_Event this)
{
/* $begin(test/Event/tc_onUpdateScopeOrphan) */
    corto_int16 ret;

    test_assert(this->et->countUpdateScope == 0);

    corto_object o = corto_declareOrphan(testScope, "o", corto_int32_o);
    test_assert(o != NULL);
    test_assert(this->et->countUpdateScope == 0);

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateScope == 0);

    ret = corto_updateBegin(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateScope == 0);
    ret = corto_updateEnd(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateScope == 0);

    ret = corto_delete(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateScope == 0);

/* $end */
}

corto_void _test_Event_tc_onUpdateSelf(
    test_Event this)
{
/* $begin(test/Event/tc_onUpdateSelf) */
    int ret;

    test_assert(this->et->countUpdateSelf == 0);

    ret = corto_update(testScope);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateSelf == 1);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == testScope);

    corto_object o = corto_int32DeclareChild(testScope, "o");
    test_assert(o != NULL);
    test_assert(this->et->countUpdateSelf == 1);

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateSelf == 1);

    ret = corto_updateBegin(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateSelf == 1);

    corto_updateEnd(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateSelf == 1);

    corto_object p = corto_int32CreateChild(testScope, "p", 0);
    test_assert(p != NULL);
    test_assert(this->et->countUpdateSelf == 1);

    ret = corto_updateBegin(p);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateSelf == 1);

    corto_updateEnd(p);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateSelf == 1);

    corto_object q = corto_int32DeclareChild(p, "q");
    test_assert(q != NULL);
    test_assert(this->et->countUpdateSelf == 1);

    ret = corto_define(q);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateSelf == 1);

    ret = corto_updateBegin(q);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateSelf == 1);

    corto_updateEnd(q);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateSelf == 1);

    corto_delete(o);
    corto_delete(p);

    test_assert(this->et->countUpdateSelf == 1);

/* $end */
}

corto_void _test_Event_tc_onUpdateSelfOrphan(
    test_Event this)
{
/* $begin(test/Event/tc_onUpdateSelfOrphan) */
    corto_int16 ret;

    test_assert(this->et->countUpdateSelf == 0);

    corto_object o = corto_declareOrphan(testScope, "o", corto_int32_o);
    test_assert(o != NULL);
    test_assert(this->et->countUpdateSelf == 0);

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateSelf == 0);

    ret = corto_updateBegin(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateSelf == 0);
    ret = corto_updateEnd(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateSelf == 1);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == testScope);

    ret = corto_delete(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateSelf == 1);

/* $end */
}

corto_void _test_Event_tc_onUpdateTree(
    test_Event this)
{
/* $begin(test/Event/tc_onUpdateTree) */
    int ret;

    test_assert(this->et->countUpdateTree == 0);

    ret = corto_update(testScope);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateTree == 0);

    corto_object o = corto_int32DeclareChild(testScope, "o");
    test_assert(o != NULL);
    test_assert(this->et->countUpdateTree == 0);

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateTree == 0);

    ret = corto_updateBegin(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateTree == 0);

    corto_updateEnd(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateTree == 1);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == o);

    corto_object p = corto_int32CreateChild(testScope, "p", 0);
    test_assert(p != NULL);
    test_assert(this->et->countUpdateTree == 1);

    ret = corto_updateBegin(p);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateTree == 1);

    corto_updateEnd(p);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateTree == 2);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == p);

    corto_object q = corto_int32DeclareChild(p, "q");
    test_assert(q != NULL);
    test_assert(this->et->countUpdateTree == 2);

    ret = corto_define(q);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateTree == 2);

    ret = corto_updateBegin(q);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateTree == 2);

    corto_updateEnd(q);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateTree == 3);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == q);

    corto_delete(o);
    corto_delete(p);

    test_assert(this->et->countUpdateTree == 3);

/* $end */
}

corto_void _test_Event_tc_onUpdateTreeNotObservable(
    test_Event this)
{
/* $begin(test/Event/tc_onUpdateTreeNotObservable) */
    int ret;
    corto_attr prevAttr = corto_setAttr(CORTO_ATTR_WRITABLE); /* Create non-observable objects */

    test_assert(this->et->countUpdateTree == 0);

    ret = corto_update(testScope);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateTree == 0);

    corto_object o = corto_int32DeclareChild(testScope, "o");
    test_assert(o != NULL);
    test_assert(this->et->countUpdateTree == 0);
    test_assert(!corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateTree == 0);

    ret = corto_updateBegin(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateTree == 0);

    corto_updateEnd(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateTree == 1);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == o);

    corto_object p = corto_int32CreateChild(testScope, "p", 0);
    test_assert(p != NULL);
    test_assert(this->et->countUpdateTree == 1);
    test_assert(!corto_checkAttr(p, CORTO_ATTR_OBSERVABLE));

    ret = corto_updateBegin(p);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateTree == 1);

    corto_updateEnd(p);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateTree == 2);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == p);

    corto_object q = corto_int32DeclareChild(p, "q");
    test_assert(q != NULL);
    test_assert(this->et->countUpdateTree == 2);
    test_assert(!corto_checkAttr(q, CORTO_ATTR_OBSERVABLE));

    ret = corto_define(q);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateTree == 2);

    ret = corto_updateBegin(q);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateTree == 2);

    corto_updateEnd(q);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateTree == 3);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == q);

    corto_delete(o);
    corto_delete(p);

    test_assert(this->et->countUpdateTree == 3);

    corto_setAttr(prevAttr);

/* $end */
}

corto_void _test_Event_tc_onUpdateTreeOrphan(
    test_Event this)
{
/* $begin(test/Event/tc_onUpdateTreeOrphan) */
    corto_int16 ret;

    test_assert(this->et->countUpdateTree == 0);

    corto_object o = corto_declareOrphan(testScope, "o", corto_int32_o);
    test_assert(o != NULL);
    test_assert(this->et->countUpdateTree == 0);

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateTree == 0);

    ret = corto_updateBegin(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateTree == 0);
    ret = corto_updateEnd(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateTree == 0);

    ret = corto_delete(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateTree == 0);

/* $end */
}

/* $header(test/Event/tc_postponeListenForUndefined) */
void test_Event_tc_postponeListenForUndefinedCallback(
    corto_object this,
    corto_eventMask event,
    corto_object observable,
    corto_observer observer)
{
    *corto_int32(this) = *corto_int32(observable);
}
/* $end */
corto_void _test_Event_tc_postponeListenForUndefined(
    test_Event this)
{
/* $begin(test/Event/tc_postponeListenForUndefined) */
    corto_int32 *observable = corto_int32CreateChild(root_o, "observable", 0);
    corto_int32 *instance = corto_int32Declare();

    corto_observer observer = corto_observe(CORTO_ON_UPDATE, observable)
      .instance(instance)
      .callback(test_Event_tc_postponeListenForUndefinedCallback);

    test_assert(observer != NULL);
    test_assert(observer->active == 0);

    corto_int16 ret = corto_int32Update(observable, 10);
    test_assert(ret == 0);
    test_assertint(*instance, 0);

    ret = corto_define(instance);
    test_assert(ret == 0);
    test_assert(observer->active == 1);

    ret = corto_int32Update(observable, 20);
    test_assert(ret == 0);
    test_assertint(*instance, 20);

    ret = corto_unobserve(observer);
    test_assert(ret == 0);

/* $end */
}

corto_void _test_Event_tc_postponeListenSilence(
    test_Event this)
{
/* $begin(test/Event/tc_postponeListenSilence) */
    corto_int32 *observable = corto_int32CreateChild(root_o, "observable", 0);
    corto_int32 *instance = corto_int32Declare();

    corto_observer observer = corto_observe(CORTO_ON_UPDATE, observable)
      .instance(instance)
      .callback(test_Event_tc_postponeListenForUndefinedCallback);
    test_assert(observer != NULL);
    test_assert(observer->active == 0);

    corto_int16 ret = corto_unobserve(observer);
    test_assert(ret == 0);

    ret = corto_int32Update(observable, 10);
    test_assert(ret == 0);
    test_assertint(*instance, 0);

    ret = corto_define(instance);
    test_assert(ret == 0);

    ret = corto_int32Update(observable, 20);
    test_assert(ret == 0);
    test_assertint(*instance, 0);

/* $end */
}

corto_void _test_Event_tc_updateUndefined(
    test_Event this)
{
/* $begin(test/Event/tc_updateUndefined) */
    test_assert(this->et->countDefine == 1);

    corto_object o = corto_int32DeclareChild(testScope, "o");
    test_assert(this->et->countUpdate == 0);
    test_assert(this->et->countDefine == 1);
    test_assert(o != NULL);

    corto_int16 ret = corto_updateBegin(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdate == 0);
    test_assert(this->et->countDefine == 1);
    test_assert(!corto_checkState(o, CORTO_DEFINED));

    ret = corto_updateEnd(o);
    test_assert(ret == 0);
    test_assert(corto_checkState(o, CORTO_DEFINED));
    test_assert(this->et->countUpdate == 0);
    test_assert(this->et->countDefine == 2);

    corto_delete(o);

/* $end */
}

corto_void _test_Event_tc_updateVoid(
    test_Event this)
{
/* $begin(test/Event/tc_updateVoid) */

    corto_object o = corto_int32CreateChild(NULL, "o", 10);
    test_assert(o != NULL);

    corto_int16 ret = corto_update(o);
    test_assert(ret == 0);
    test_assert(corto_lasterr() == NULL);

/* $end */
}

corto_void _test_Event_teardown(
    test_Event this)
{
/* $begin(test/Event/teardown) */
    corto_uint32 countDelete = this->et->countDelete;

    corto_delete(testScope);
    test_assertint(this->et->countDelete, countDelete + 1);
    test_assertint(this->et->countDeleteSelf, 1);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == testScope);
    corto_delete(this->et);
    this->et = NULL;
    corto_setAttr(this->prevAttr);

/* $end */
}
