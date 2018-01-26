/* This is a managed file. Do not delete this comment. */

#include <include/test.h>


static corto_object testScope;

#define DECLARE_ORPHAN(p, i, t)\
    corto(CORTO_DECLARE|CORTO_ORPHAN|CORTO_FORCE_TYPE, {.parent=p, .id=i, .type=t})

void test_Event_setup(
    test_Event this)
{
    this->prevAttr = corto_set_attr(CORTO_ATTR_DEFAULT);
    testScope = corto_void__create(root_o, "testScope");
    test_assert(testScope != NULL);
    test_EventTest et = test_EventTestCreate(testScope);
    test_assert(et != NULL);
    corto_set_ref(&this->et, et);
    corto_release(et);

}

void test_Event_tc_onDeclare(
    test_Event this)
{
    corto_int16 ret;

    test_assertint(this->et->countDeclare, 1);

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

}

void test_Event_tc_onDeclareOrphan(
    test_Event this)
{
    corto_int16 ret;

    test_assert(this->et->countDeclare == 1);

    corto_object o = DECLARE_ORPHAN(testScope, "o", corto_int32_o);
    test_assert(o != NULL);
    test_assert(this->et->countDeclare == 1);

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assert(this->et->countDeclare == 1);

    ret = corto_update_begin(o);
    test_assert(ret == 0);
    test_assert(this->et->countDeclare == 1);
    ret = corto_update_end(o);
    test_assert(ret == 0);
    test_assert(this->et->countDeclare == 1);

    ret = corto_delete(o);
    test_assert(ret == 0);
    test_assert(this->et->countDeclare == 1);

}

void test_Event_tc_onDeclareScope(
    test_Event this)
{
    corto_int16 ret;
    test_assertint(this->et->countDeclareScope, 0);

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

}

void test_Event_tc_onDeclareScopeNotObservable(
    test_Event this)
{
    corto_int16 ret;
    corto_attr prevAttr = corto_set_attr(CORTO_ATTR_WRITABLE); /* Create non-observable objects */

    test_assert(this->et->countDeclareScope == 0);

    corto_object o = corto_int32DeclareChild(testScope, "o");
    test_assert(o != NULL);
    test_assert(this->et->countDeclareScope == 1);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == o);
    test_assert(!corto_check_attr(o, CORTO_ATTR_OBSERVABLE));

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assert(this->et->countDeclareScope == 1);

    corto_object p = corto_int32CreateChild(testScope, "p", 0);
    test_assert(p != NULL);
    test_assert(this->et->countDeclareScope == 2);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == p);
    test_assert(!corto_check_attr(p, CORTO_ATTR_OBSERVABLE));

    corto_object q = corto_int32DeclareChild(p, "q");
    test_assert(q != NULL);
    test_assert(this->et->countDeclareScope == 2);
    test_assert(!corto_check_attr(q, CORTO_ATTR_OBSERVABLE));

    corto_define(q);
    test_assert(this->et->countDeclareScope == 2);

    corto_delete(o);
    corto_delete(p);

    test_assert(this->et->countDeclareScope == 2);

    corto_set_attr(prevAttr);

}

void test_Event_tc_onDeclareScopeOrphan(
    test_Event this)
{
    corto_int16 ret;

    test_assert(this->et->countDeclareScope == 0);

    corto_object o = DECLARE_ORPHAN(testScope, "o", corto_int32_o);
    test_assert(o != NULL);
    test_assert(this->et->countDeclareScope == 0);

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assert(this->et->countDeclareScope == 0);

    ret = corto_update_begin(o);
    test_assert(ret == 0);
    test_assert(this->et->countDeclareScope == 0);
    ret = corto_update_end(o);
    test_assert(ret == 0);
    test_assert(this->et->countDeclareScope == 0);

    ret = corto_delete(o);
    test_assert(ret == 0);
    test_assert(this->et->countDeclareScope == 0);

}

void test_Event_tc_onDeclareSelf(
    test_Event this)
{
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

}

void test_Event_tc_onDeclareSelfOrphan(
    test_Event this)
{
    corto_int16 ret;

    test_assert(this->et->countDeclareSelf == 1);

    corto_object o = DECLARE_ORPHAN(testScope, "o", corto_int32_o);
    test_assert(o != NULL);
    test_assert(this->et->countDeclareSelf == 1);

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assert(this->et->countDeclareSelf == 1);

    ret = corto_update_begin(o);
    test_assert(ret == 0);
    test_assert(this->et->countDeclareSelf == 1);
    ret = corto_update_end(o);
    test_assert(ret == 0);
    test_assert(this->et->countDeclareSelf == 1);

    ret = corto_delete(o);
    test_assert(ret == 0);
    test_assert(this->et->countDeclareSelf == 1);

}

void test_Event_tc_onDeclareTree(
    test_Event this)
{
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

}

void test_Event_tc_onDeclareTreeNotObservable(
    test_Event this)
{
    corto_int16 ret;
    corto_attr prevAttr = corto_set_attr(CORTO_ATTR_WRITABLE); /* Create non-observable objects */

    test_assert(this->et->countDeclareTree == 0);

    corto_object o = corto_int32DeclareChild(testScope, "o");
    test_assert(o != NULL);
    test_assert(this->et->countDeclareTree == 1);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == o);
    test_assert(!corto_check_attr(o, CORTO_ATTR_OBSERVABLE));

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assert(this->et->countDeclareTree == 1);

    corto_object p = corto_int32CreateChild(testScope, "p", 0);
    test_assert(p != NULL);
    test_assert(this->et->countDeclareTree == 2);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == p);
    test_assert(!corto_check_attr(p, CORTO_ATTR_OBSERVABLE));

    corto_object q = corto_int32DeclareChild(p, "q");
    test_assert(q != NULL);
    test_assert(this->et->countDeclareTree == 3);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == q);
    test_assert(!corto_check_attr(q, CORTO_ATTR_OBSERVABLE));

    ret = corto_define(q);
    test_assert(ret == 0);
    test_assert(this->et->countDeclareTree == 3);

    corto_delete(o);
    corto_delete(p);

    test_assert(this->et->countDeclareTree == 3);

    corto_set_attr(prevAttr);

}

void test_Event_tc_onDeclareTreeOrphan(
    test_Event this)
{
    corto_int16 ret;

    test_assert(this->et->countDeclareTree == 0);

    corto_object o = DECLARE_ORPHAN(testScope, "o", corto_int32_o);
    test_assert(o != NULL);
    test_assert(this->et->countDeclareTree == 0);

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assert(this->et->countDeclareTree == 0);

    ret = corto_update_begin(o);
    test_assert(ret == 0);
    test_assert(this->et->countDeclareTree == 0);
    ret = corto_update_end(o);
    test_assert(ret == 0);
    test_assert(this->et->countDeclareTree == 0);

    ret = corto_delete(o);
    test_assert(ret == 0);
    test_assert(this->et->countDeclareTree == 0);

}

void test_Event_tc_onDefine(
    test_Event this)
{
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

}

void test_Event_tc_onDefineOrphan(
    test_Event this)
{
    corto_int16 ret;

    test_assert(this->et->countDefine == 1);

    corto_object o = DECLARE_ORPHAN(testScope, "o", corto_int32_o);
    test_assert(o != NULL);
    test_assert(this->et->countDefine == 1);

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assert(this->et->countDefine == 1);

    ret = corto_update_begin(o);
    test_assert(ret == 0);
    test_assert(this->et->countDefine == 1);
    ret = corto_update_end(o);
    test_assert(ret == 0);
    test_assert(this->et->countDefine == 1);

    ret = corto_delete(o);
    test_assert(ret == 0);
    test_assert(this->et->countDefine == 1);

}

void test_Event_tc_onDefineScope(
    test_Event this)
{
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

}

void test_Event_tc_onDefineScopeNotObservable(
    test_Event this)
{
    corto_int16 ret;
    corto_attr attr = corto_set_attr(CORTO_ATTR_WRITABLE); /* Create non-observable objects */

    test_assert(this->et->countDefineScope == 0);

    corto_object o = corto_int32DeclareChild(testScope, "o");
    test_assert(o != NULL);
    test_assert(this->et->countDefineScope == 0);
    test_assert(!corto_check_attr(o, CORTO_ATTR_OBSERVABLE));

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
    test_assert(!corto_check_attr(p, CORTO_ATTR_OBSERVABLE));

    corto_object q = corto_int32DeclareChild(p, "q");
    test_assert(q != NULL);
    test_assert(this->et->countDefineScope == 2);
    test_assert(!corto_check_attr(q, CORTO_ATTR_OBSERVABLE));

    ret = corto_define(q);
    test_assert(ret == 0);
    test_assert(this->et->countDefineScope == 2);

    corto_delete(o);
    corto_delete(p);

    test_assert(this->et->countDefineScope == 2);

    corto_set_attr(attr);

}

void test_Event_tc_onDefineScopeOrphan(
    test_Event this)
{
    corto_int16 ret;

    test_assert(this->et->countDefineScope == 0);

    corto_object o = DECLARE_ORPHAN(testScope, "o", corto_int32_o);
    test_assert(o != NULL);
    test_assert(this->et->countDefineScope == 0);

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assert(this->et->countDefineScope == 0);

    ret = corto_update_begin(o);
    test_assert(ret == 0);
    test_assert(this->et->countDefineScope == 0);
    ret = corto_update_end(o);
    test_assert(ret == 0);
    test_assert(this->et->countDefineScope == 0);

    ret = corto_delete(o);
    test_assert(ret == 0);
    test_assert(this->et->countDefineScope == 0);

}

void test_Event_tc_onDefineSelf(
    test_Event this)
{
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

}

void test_Event_tc_onDefineSelfOrphan(
    test_Event this)
{
    corto_int16 ret;

    test_assert(this->et->countDefineSelf == 1);

    corto_object o = DECLARE_ORPHAN(testScope, "o", corto_int32_o);
    test_assert(o != NULL);
    test_assert(this->et->countDefineSelf == 1);

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assert(this->et->countDefineSelf == 1);

    ret = corto_update_begin(o);
    test_assert(ret == 0);
    test_assert(this->et->countDefineSelf == 1);
    ret = corto_update_end(o);
    test_assert(ret == 0);
    test_assert(this->et->countDefineSelf == 1);

    ret = corto_delete(o);
    test_assert(ret == 0);
    test_assert(this->et->countDefineSelf == 1);

}

void test_Event_tc_onDefineTree(
    test_Event this)
{
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

}

void test_Event_tc_onDefineTreeNotObservable(
    test_Event this)
{
    corto_int16 ret;
    corto_attr prevAttr = corto_set_attr(CORTO_ATTR_WRITABLE); /* Create non-observable objects */

    test_assert(this->et->countDefineTree == 0);

    corto_object o = corto_int32DeclareChild(testScope, "o");
    test_assert(o != NULL);
    test_assert(this->et->countDefineTree == 0);
    test_assert(!corto_check_attr(o, CORTO_ATTR_OBSERVABLE));

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
    test_assert(!corto_check_attr(p, CORTO_ATTR_OBSERVABLE));

    corto_object q = corto_int32DeclareChild(p, "q");
    test_assert(q != NULL);
    test_assert(this->et->countDefineTree == 2);
    test_assert(!corto_check_attr(q, CORTO_ATTR_OBSERVABLE));

    ret = corto_define(q);
    test_assert(ret == 0);
    test_assert(this->et->countDefineTree == 3);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == q);

    corto_delete(o);
    corto_delete(p);

    test_assert(this->et->countDefineTree == 3);

    corto_set_attr(prevAttr);

}

void test_Event_tc_onDefineTreeOrphan(
    test_Event this)
{
    corto_int16 ret;

    test_assert(this->et->countDefineTree == 0);

    corto_object o = DECLARE_ORPHAN(testScope, "o", corto_int32_o);
    test_assert(o != NULL);
    test_assert(this->et->countDefineTree == 0);

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assert(this->et->countDefineTree == 0);

    ret = corto_update_begin(o);
    test_assert(ret == 0);
    test_assert(this->et->countDefineTree == 0);
    ret = corto_update_end(o);
    test_assert(ret == 0);
    test_assert(this->et->countDefineTree == 0);

    ret = corto_delete(o);
    test_assert(ret == 0);
    test_assert(this->et->countDefineTree == 0);

}

void test_Event_tc_onDelete(
    test_Event this)
{
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

}

void test_Event_tc_onDeleteOrphan(
    test_Event this)
{
    corto_int16 ret;

    test_assert(this->et->countDelete == 0);

    corto_object o = DECLARE_ORPHAN(testScope, "o", corto_int32_o);
    test_assert(o != NULL);
    test_assert(this->et->countDelete == 0);

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assert(this->et->countDelete == 0);

    ret = corto_update_begin(o);
    test_assert(ret == 0);
    test_assert(this->et->countDelete == 0);
    ret = corto_update_end(o);
    test_assert(ret == 0);
    test_assert(this->et->countDelete == 0);

    ret = corto_delete(o);
    test_assert(ret == 0);
    test_assert(this->et->countDelete == 0);

}

void test_Event_tc_onDeleteScope(
    test_Event this)
{
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

}

void test_Event_tc_onDeleteScopeNotObservable(
    test_Event this)
{
    corto_int16 ret;
    corto_attr prevAttr = corto_set_attr(CORTO_ATTR_WRITABLE); /* Create non-observable objects */

    test_assert(this->et->countDeleteScope == 0);

    corto_object o = corto_int32DeclareChild(testScope, "o");
    test_assert(o != NULL);
    test_assert(this->et->countDeleteScope == 0);
    test_assert(!corto_check_attr(o, CORTO_ATTR_OBSERVABLE));

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assert(this->et->countDeleteScope == 0);

    corto_object p = corto_int32CreateChild(testScope, "p", 0);
    test_assert(p != NULL);
    test_assert(this->et->countDeleteScope == 0);
    test_assert(!corto_check_attr(p, CORTO_ATTR_OBSERVABLE));

    corto_object q = corto_int32DeclareChild(p, "q");
    test_assert(q != NULL);
    test_assert(this->et->countDeleteScope == 0);
    test_assert(!corto_check_attr(q, CORTO_ATTR_OBSERVABLE));

    ret = corto_define(q);
    test_assert(ret == 0);
    test_assert(this->et->countDeleteScope == 0);

    corto_delete(o);
    test_assert(this->et->countDeleteScope == 1);

    corto_delete(p);
    test_assert(this->et->countDeleteScope == 2);

    corto_set_attr(prevAttr);

}

void test_Event_tc_onDeleteScopeOrphan(
    test_Event this)
{
    corto_int16 ret;

    test_assert(this->et->countDeleteScope == 0);

    corto_object o = DECLARE_ORPHAN(testScope, "o", corto_int32_o);
    test_assert(o != NULL);
    test_assert(this->et->countDeleteScope == 0);

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assert(this->et->countDeleteScope == 0);

    ret = corto_update_begin(o);
    test_assert(ret == 0);
    test_assert(this->et->countDeleteScope == 0);
    ret = corto_update_end(o);
    test_assert(ret == 0);
    test_assert(this->et->countDeleteScope == 0);

    ret = corto_delete(o);
    test_assert(ret == 0);
    test_assert(this->et->countDeleteScope == 0);

}

void test_Event_tc_onDeleteSelf(
    test_Event this)
{
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

}

void test_Event_tc_onDeleteSelfOrphan(
    test_Event this)
{
    corto_int16 ret;

    test_assert(this->et->countDeleteSelf == 0);

    corto_object o = DECLARE_ORPHAN(testScope, "o", corto_int32_o);
    test_assert(o != NULL);
    test_assert(this->et->countDeleteSelf == 0);

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assert(this->et->countDeleteSelf == 0);

    ret = corto_update_begin(o);
    test_assert(ret == 0);
    test_assert(this->et->countDeleteSelf == 0);
    ret = corto_update_end(o);
    test_assert(ret == 0);
    test_assert(this->et->countDeleteSelf == 0);

    ret = corto_delete(o);
    test_assert(ret == 0);
    test_assert(this->et->countDeleteSelf == 0);

}

void test_Event_tc_onDeleteTree(
    test_Event this)
{
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

}

void test_Event_tc_onDeleteTreeNotObservable(
    test_Event this)
{
    corto_int16 ret;
    corto_attr prevAttr = corto_set_attr(CORTO_ATTR_WRITABLE); /* Create non-observable objects */

    test_assert(this->et->countDeleteTree == 0);

    corto_object o = corto_int32DeclareChild(testScope, "o");
    test_assert(o != NULL);
    test_assert(this->et->countDeleteTree == 0);
    test_assert(!corto_check_attr(o, CORTO_ATTR_OBSERVABLE));

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assert(this->et->countDeleteTree == 0);

    corto_object p = corto_int32CreateChild(testScope, "p", 0);
    test_assert(p != NULL);
    test_assert(this->et->countDeleteTree == 0);
    test_assert(!corto_check_attr(p, CORTO_ATTR_OBSERVABLE));

    corto_object q = corto_int32DeclareChild(p, "q");
    test_assert(q != NULL);
    test_assert(this->et->countDeleteTree == 0);
    test_assert(!corto_check_attr(q, CORTO_ATTR_OBSERVABLE));

    ret = corto_define(q);
    test_assert(ret == 0);
    test_assert(this->et->countDeleteTree == 0);

    corto_delete(o);
    test_assert(this->et->countDeleteTree == 1);

    corto_delete(p);
    test_assert(this->et->countDeleteTree == 3);

    corto_set_attr(prevAttr);

}

void test_Event_tc_onDeleteTreeOrphan(
    test_Event this)
{
    corto_int16 ret;

    test_assert(this->et->countDeleteTree == 0);

    corto_object o = DECLARE_ORPHAN(testScope, "o", corto_int32_o);
    test_assert(o != NULL);
    test_assert(this->et->countDeleteTree == 0);

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assert(this->et->countDeleteTree == 0);

    ret = corto_update_begin(o);
    test_assert(ret == 0);
    test_assert(this->et->countDeleteTree == 0);
    ret = corto_update_end(o);
    test_assert(ret == 0);
    test_assert(this->et->countDeleteTree == 0);

    ret = corto_delete(o);
    test_assert(ret == 0);
    test_assert(this->et->countDeleteTree == 0);

}

void test_Event_tc_onUpdate(
    test_Event this)
{
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

    ret = corto_update_begin(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdate == 1);

    corto_update_end(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdate == 2);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == o);

    corto_object p = corto_int32CreateChild(testScope, "p", 0);
    test_assert(p != NULL);
    test_assert(this->et->countUpdate == 2);

    ret = corto_update_begin(p);
    test_assert(ret == 0);
    test_assert(this->et->countUpdate == 2);

    corto_update_end(p);
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

    ret = corto_update_begin(q);
    test_assert(ret == 0);
    test_assert(this->et->countUpdate == 3);

    corto_update_end(q);
    test_assert(ret == 0);
    test_assert(this->et->countUpdate == 4);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == q);

    corto_delete(o);
    corto_delete(p);

    test_assert(this->et->countUpdate == 4);

}

void test_Event_tc_onUpdateDefine(
    test_Event this)
{
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

    ret = corto_update_begin(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefine == 3);

    corto_update_end(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefine == 4);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == o);

    corto_object p = corto_int32CreateChild(testScope, "p", 0);
    test_assert(p != NULL);
    test_assert(this->et->countUpdateDefine == 5);

    ret = corto_update_begin(p);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefine == 5);

    corto_update_end(p);
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

    ret = corto_update_begin(q);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefine == 7);

    corto_update_end(q);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefine == 8);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == q);

    corto_delete(o);
    corto_delete(p);

    test_assert(this->et->countUpdateDefine == 8);

}

void test_Event_tc_onUpdateDefineOrphan(
    test_Event this)
{
    corto_int16 ret;

    test_assert(this->et->countUpdateDefine == 1);

    corto_object o = DECLARE_ORPHAN(testScope, "o", corto_int32_o);
    test_assert(o != NULL);
    test_assert(this->et->countUpdateDefine == 1);

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefine == 1);

    ret = corto_update_begin(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefine == 1);
    ret = corto_update_end(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefine == 2);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == testScope);

    ret = corto_delete(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefine == 2);

}

void test_Event_tc_onUpdateDefineScope(
    test_Event this)
{
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

    ret = corto_update_begin(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineScope == 1);

    corto_update_end(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineScope == 2);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == o);

    corto_object p = corto_int32CreateChild(testScope, "p", 0);
    test_assert(p != NULL);
    test_assert(this->et->countUpdateDefineScope == 3);

    ret = corto_update_begin(p);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineScope == 3);

    corto_update_end(p);
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

    ret = corto_update_begin(q);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineScope == 4);

    corto_update_end(q);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineScope == 4);

    corto_delete(o);
    corto_delete(p);

    test_assert(this->et->countUpdateDefineScope == 4);

}

void test_Event_tc_onUpdateDefineScopeNotObservable(
    test_Event this)
{
    int ret;
    corto_attr prevAttr = corto_set_attr(CORTO_ATTR_WRITABLE); /* Create non-observable objects */

    test_assert(this->et->countUpdateDefineScope == 0);

    ret = corto_update(testScope);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineScope == 0);

    corto_object o = corto_int32DeclareChild(testScope, "o");
    test_assert(o != NULL);
    test_assert(this->et->countUpdateDefineScope == 0);
    test_assert(!corto_check_attr(o, CORTO_ATTR_OBSERVABLE));

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineScope == 1);

    ret = corto_update_begin(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineScope == 1);

    corto_update_end(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineScope == 2);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == o);

    corto_object p = corto_int32CreateChild(testScope, "p", 0);
    test_assert(p != NULL);
    test_assert(this->et->countUpdateDefineScope == 3);
    test_assert(!corto_check_attr(p, CORTO_ATTR_OBSERVABLE));

    ret = corto_update_begin(p);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineScope == 3);

    corto_update_end(p);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineScope == 4);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == p);

    corto_object q = corto_int32DeclareChild(p, "q");
    test_assert(q != NULL);
    test_assert(this->et->countUpdateDefineScope == 4);
    test_assert(!corto_check_attr(q, CORTO_ATTR_OBSERVABLE));

    ret = corto_define(q);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineScope == 4);

    ret = corto_update_begin(q);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineScope == 4);

    corto_update_end(q);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineScope == 4);

    corto_delete(o);
    corto_delete(p);

    test_assert(this->et->countUpdateDefineScope == 4);

    corto_set_attr(prevAttr);

}

void test_Event_tc_onUpdateDefineScopeOrphan(
    test_Event this)
{
    corto_int16 ret;

    test_assert(this->et->countUpdateDefineScope == 0);

    corto_object o = DECLARE_ORPHAN(testScope, "o", corto_int32_o);
    test_assert(o != NULL);
    test_assert(this->et->countUpdateDefineScope == 0);

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineScope == 0);

    ret = corto_update_begin(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineScope == 0);
    ret = corto_update_end(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineScope == 0);

    ret = corto_delete(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineScope == 0);

}

void test_Event_tc_onUpdateDefineSelf(
    test_Event this)
{
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

    ret = corto_update_begin(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineSelf == 2);

    corto_update_end(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineSelf == 2);

    corto_object p = corto_int32CreateChild(testScope, "p", 0);
    test_assert(p != NULL);
    test_assert(this->et->countUpdateDefineSelf == 2);

    ret = corto_update_begin(p);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineSelf == 2);

    corto_update_end(p);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineSelf == 2);

    corto_object q = corto_int32DeclareChild(p, "q");
    test_assert(q != NULL);
    test_assert(this->et->countUpdateDefineSelf == 2);

    ret = corto_define(q);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineSelf == 2);

    ret = corto_update_begin(q);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineSelf == 2);

    corto_update_end(q);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineSelf == 2);

    corto_delete(o);
    corto_delete(p);

    test_assert(this->et->countUpdateDefineSelf == 2);

}

void test_Event_tc_onUpdateDefineSelfOrphan(
    test_Event this)
{
    corto_int16 ret;

    test_assert(this->et->countUpdateDefineSelf == 1);

    corto_object o = DECLARE_ORPHAN(testScope, "o", corto_int32_o);
    test_assert(o != NULL);
    test_assert(this->et->countUpdateDefineSelf == 1);

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineSelf == 1);

    ret = corto_update_begin(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineSelf == 1);
    ret = corto_update_end(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineSelf == 2);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == testScope);

    ret = corto_delete(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineSelf == 2);

}

void test_Event_tc_onUpdateDefineTree(
    test_Event this)
{
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

    ret = corto_update_begin(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineTree == 1);

    corto_update_end(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineTree == 2);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == o);

    corto_object p = corto_int32CreateChild(testScope, "p", 0);
    test_assert(p != NULL);
    test_assert(this->et->countUpdateDefineTree == 3);

    ret = corto_update_begin(p);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineTree == 3);

    corto_update_end(p);
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

    ret = corto_update_begin(q);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineTree == 5);

    corto_update_end(q);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineTree == 6);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == q);

    corto_delete(o);
    corto_delete(p);

    test_assert(this->et->countUpdateDefineTree == 6);

}

void test_Event_tc_onUpdateDefineTreeNotObservable(
    test_Event this)
{
    int ret;
    corto_attr prevAttr = corto_set_attr(CORTO_ATTR_WRITABLE); /* Create non-observable objects */

    test_assert(this->et->countUpdateDefineTree == 0);

    ret = corto_update(testScope);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineTree == 0);

    corto_object o = corto_int32DeclareChild(testScope, "o");
    test_assert(o != NULL);
    test_assert(this->et->countUpdateDefineTree == 0);
    test_assert(!corto_check_attr(o, CORTO_ATTR_OBSERVABLE));

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineTree == 1);

    ret = corto_update_begin(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineTree == 1);

    corto_update_end(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineTree == 2);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == o);

    corto_object p = corto_int32CreateChild(testScope, "p", 0);
    test_assert(p != NULL);
    test_assert(this->et->countUpdateDefineTree == 3);
    test_assert(!corto_check_attr(p, CORTO_ATTR_OBSERVABLE));

    ret = corto_update_begin(p);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineTree == 3);

    corto_update_end(p);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineTree == 4);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == p);

    corto_object q = corto_int32DeclareChild(p, "q");
    test_assert(q != NULL);
    test_assert(this->et->countUpdateDefineTree == 4);
    test_assert(!corto_check_attr(q, CORTO_ATTR_OBSERVABLE));

    ret = corto_define(q);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineTree == 5);

    ret = corto_update_begin(q);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineTree == 5);

    corto_update_end(q);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineTree == 6);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == q);

    corto_delete(o);
    corto_delete(p);

    test_assert(this->et->countUpdateDefineTree == 6);

    corto_set_attr(prevAttr);

}

void test_Event_tc_onUpdateDefineTreeOrphan(
    test_Event this)
{
    corto_int16 ret;

    test_assert(this->et->countUpdateDefineTree == 0);

    corto_object o = DECLARE_ORPHAN(testScope, "o", corto_int32_o);
    test_assert(o != NULL);
    test_assert(this->et->countUpdateDefineTree == 0);

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineTree == 0);

    ret = corto_update_begin(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineTree == 0);
    ret = corto_update_end(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineTree == 0);

    ret = corto_delete(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateDefineTree == 0);

}

void test_Event_tc_onUpdateOrphan(
    test_Event this)
{
    corto_int16 ret;

    test_assert(this->et->countUpdate == 0);

    corto_object o = DECLARE_ORPHAN(testScope, "o", corto_int32_o);
    test_assert(o != NULL);
    test_assert(this->et->countUpdate == 0);

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdate == 0);

    ret = corto_update_begin(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdate == 0);
    ret = corto_update_end(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdate == 1);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == testScope);

    ret = corto_delete(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdate == 1);

}

void test_Event_tc_onUpdateScope(
    test_Event this)
{
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

    ret = corto_update_begin(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateScope == 0);

    corto_update_end(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateScope == 1);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == o);

    corto_object p = corto_int32CreateChild(testScope, "p", 0);
    test_assert(p != NULL);
    test_assert(this->et->countUpdateScope == 1);

    ret = corto_update_begin(p);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateScope == 1);

    corto_update_end(p);
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

    ret = corto_update_begin(q);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateScope == 2);

    corto_update_end(q);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateScope == 2);

    corto_delete(o);
    corto_delete(p);

    test_assert(this->et->countUpdateScope == 2);

}

void test_Event_tc_onUpdateScopeNotObservable(
    test_Event this)
{
    int ret;
    corto_attr prevAttr = corto_set_attr(CORTO_ATTR_WRITABLE); /* Create non-observable objects */

    test_assert(this->et->countUpdateScope == 0);

    ret = corto_update(testScope);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateScope == 0);

    corto_object o = corto_int32DeclareChild(testScope, "o");
    test_assert(o != NULL);
    test_assert(this->et->countUpdateScope == 0);
    test_assert(!corto_check_attr(o, CORTO_ATTR_OBSERVABLE));

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateScope == 0);

    ret = corto_update_begin(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateScope == 0);

    corto_update_end(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateScope == 1);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == o);

    corto_object p = corto_int32CreateChild(testScope, "p", 0);
    test_assert(p != NULL);
    test_assert(this->et->countUpdateScope == 1);
    test_assert(!corto_check_attr(p, CORTO_ATTR_OBSERVABLE));

    ret = corto_update_begin(p);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateScope == 1);

    corto_update_end(p);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateScope == 2);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == p);

    corto_object q = corto_int32DeclareChild(p, "q");
    test_assert(q != NULL);
    test_assert(this->et->countUpdateScope == 2);
    test_assert(!corto_check_attr(q, CORTO_ATTR_OBSERVABLE));

    ret = corto_define(q);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateScope == 2);

    ret = corto_update_begin(q);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateScope == 2);

    corto_update_end(q);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateScope == 2);

    corto_delete(o);
    corto_delete(p);

    test_assert(this->et->countUpdateScope == 2);

    corto_set_attr(prevAttr);

}

void test_Event_tc_onUpdateScopeOrphan(
    test_Event this)
{
    corto_int16 ret;

    test_assert(this->et->countUpdateScope == 0);

    corto_object o = DECLARE_ORPHAN(testScope, "o", corto_int32_o);
    test_assert(o != NULL);
    test_assert(this->et->countUpdateScope == 0);

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateScope == 0);

    ret = corto_update_begin(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateScope == 0);
    ret = corto_update_end(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateScope == 0);

    ret = corto_delete(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateScope == 0);

}

void test_Event_tc_onUpdateSelf(
    test_Event this)
{
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

    ret = corto_update_begin(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateSelf == 1);

    corto_update_end(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateSelf == 1);

    corto_object p = corto_int32CreateChild(testScope, "p", 0);
    test_assert(p != NULL);
    test_assert(this->et->countUpdateSelf == 1);

    ret = corto_update_begin(p);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateSelf == 1);

    corto_update_end(p);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateSelf == 1);

    corto_object q = corto_int32DeclareChild(p, "q");
    test_assert(q != NULL);
    test_assert(this->et->countUpdateSelf == 1);

    ret = corto_define(q);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateSelf == 1);

    ret = corto_update_begin(q);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateSelf == 1);

    corto_update_end(q);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateSelf == 1);

    corto_delete(o);
    corto_delete(p);

    test_assert(this->et->countUpdateSelf == 1);

}

void test_Event_tc_onUpdateSelfOrphan(
    test_Event this)
{
    corto_int16 ret;

    test_assert(this->et->countUpdateSelf == 0);

    corto_object o = DECLARE_ORPHAN(testScope, "o", corto_int32_o);
    test_assert(o != NULL);
    test_assert(this->et->countUpdateSelf == 0);

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateSelf == 0);

    ret = corto_update_begin(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateSelf == 0);
    ret = corto_update_end(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateSelf == 1);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == testScope);

    ret = corto_delete(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateSelf == 1);

}

void test_Event_tc_onUpdateTree(
    test_Event this)
{
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

    ret = corto_update_begin(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateTree == 0);

    corto_update_end(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateTree == 1);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == o);

    corto_object p = corto_int32CreateChild(testScope, "p", 0);
    test_assert(p != NULL);
    test_assert(this->et->countUpdateTree == 1);

    ret = corto_update_begin(p);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateTree == 1);

    corto_update_end(p);
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

    ret = corto_update_begin(q);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateTree == 2);

    corto_update_end(q);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateTree == 3);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == q);

    corto_delete(o);
    corto_delete(p);

    test_assert(this->et->countUpdateTree == 3);

}

void test_Event_tc_onUpdateTreeNotObservable(
    test_Event this)
{
    int ret;
    corto_attr prevAttr = corto_set_attr(CORTO_ATTR_WRITABLE); /* Create non-observable objects */

    test_assert(this->et->countUpdateTree == 0);

    ret = corto_update(testScope);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateTree == 0);

    corto_object o = corto_int32DeclareChild(testScope, "o");
    test_assert(o != NULL);
    test_assert(this->et->countUpdateTree == 0);
    test_assert(!corto_check_attr(o, CORTO_ATTR_OBSERVABLE));

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateTree == 0);

    ret = corto_update_begin(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateTree == 0);

    corto_update_end(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateTree == 1);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == o);

    corto_object p = corto_int32CreateChild(testScope, "p", 0);
    test_assert(p != NULL);
    test_assert(this->et->countUpdateTree == 1);
    test_assert(!corto_check_attr(p, CORTO_ATTR_OBSERVABLE));

    ret = corto_update_begin(p);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateTree == 1);

    corto_update_end(p);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateTree == 2);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == p);

    corto_object q = corto_int32DeclareChild(p, "q");
    test_assert(q != NULL);
    test_assert(this->et->countUpdateTree == 2);
    test_assert(!corto_check_attr(q, CORTO_ATTR_OBSERVABLE));

    ret = corto_define(q);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateTree == 2);

    ret = corto_update_begin(q);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateTree == 2);

    corto_update_end(q);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateTree == 3);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == q);

    corto_delete(o);
    corto_delete(p);

    test_assert(this->et->countUpdateTree == 3);

    corto_set_attr(prevAttr);

}

void test_Event_tc_onUpdateTreeOrphan(
    test_Event this)
{
    corto_int16 ret;

    test_assert(this->et->countUpdateTree == 0);

    corto_object o = DECLARE_ORPHAN(testScope, "o", corto_int32_o);
    test_assert(o != NULL);
    test_assert(this->et->countUpdateTree == 0);

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateTree == 0);

    ret = corto_update_begin(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateTree == 0);
    ret = corto_update_end(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateTree == 0);

    ret = corto_delete(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdateTree == 0);

}


void test_Event_tc_postponeListenForUndefinedCallback(corto_observerEvent *e)
{
    *corto_int32(e->instance) = *corto_int32(e->data);
}

void test_Event_tc_postponeListenForUndefined(
    test_Event this)
{
    corto_int32 *observable = corto_int32CreateChild(root_o, "observable", 0);
    corto_int32 *instance = corto_int32Declare();

    corto_observer observer = corto_observe(CORTO_UPDATE, observable)
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

}

void test_Event_tc_postponeListenSilence(
    test_Event this)
{
    corto_int32 *observable = corto_int32CreateChild(root_o, "observable", 0);
    corto_int32 *instance = corto_int32Declare();

    corto_observer observer = corto_observe(CORTO_UPDATE, observable)
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
}

void test_Event_tc_updateUndefined(
    test_Event this)
{
    test_assert(this->et->countDefine == 1);

    corto_object o = corto_int32DeclareChild(testScope, "o");
    test_assert(this->et->countUpdate == 0);
    test_assert(this->et->countDefine == 1);
    test_assert(o != NULL);

    corto_int16 ret = corto_update_begin(o);
    test_assert(ret == 0);
    test_assert(this->et->countUpdate == 0);
    test_assert(this->et->countDefine == 1);
    test_assert(!corto_check_state(o, CORTO_VALID));

    ret = corto_update_end(o);
    test_assert(ret == 0);
    test_assert(corto_check_state(o, CORTO_VALID));
    test_assert(this->et->countUpdate == 0);
    test_assert(this->et->countDefine == 2);

    corto_delete(o);

}

void test_Event_tc_updateVoid(
    test_Event this)
{

    corto_object o = corto_int32CreateChild(root_o, "o", 10);
    test_assert(o != NULL);

    corto_int16 ret = corto_update(o);
    test_assert(ret == 0);
}

void test_Event_teardown(
    test_Event this)
{
    corto_uint32 countDelete = this->et->countDelete;

    corto_delete(testScope);
    test_assertint(this->et->countDelete, countDelete + 1);
    test_assertint(this->et->countDeleteSelf, 1);
    test_assert(this->et->lastThis == this->et);
    test_assert(this->et->lastObservable == testScope);
    corto_delete(this->et);
    this->et = NULL;
    corto_set_attr(this->prevAttr);

}
