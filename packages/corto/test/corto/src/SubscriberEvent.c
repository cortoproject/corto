/* $CORTO_GENERATED
 *
 * SubscriberEvent.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <include/test.h>

/* $header() */
static corto_object testScope;
/* $end */

void _test_SubscriberEvent_setup(
    test_SubscriberEvent this)
{
/* $begin(test/SubscriberEvent/setup) */

    this->prevAttr = corto_setAttr(CORTO_ATTR_DEFAULT);
    corto_voidCreateChild(NULL, "shouldNotBeMatched");
    testScope = corto_voidCreateChild(NULL, "testScope");
    test_assert(testScope != NULL);
    test_SubscriberTest st = test_SubscriberTestCreate();
    test_assert(st != NULL);
    corto_ptr_setref(&this->st, st);
    corto_release(st);


/* $end */
}

void _test_SubscriberEvent_tc_onDeclare(
    test_SubscriberEvent this)
{
/* $begin(test/SubscriberEvent/tc_onDeclare) */
    corto_int16 ret;

    test_assertint(this->st->countDeclare, 0);
    test_assert(corto_ll_hasObject(this->st->triggered, test_SubscriberTest_onAll_o));
    test_SubscriberTest_clear(this->st);

    corto_object o = corto_int32DeclareChild(testScope, "o");
    test_assert(o != NULL);
    test_assertint(this->st->countDeclare, 0);

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assertint(this->st->countDeclare, 0);

    corto_object p = corto_int32CreateChild(testScope, "p", 0);
    test_assert(p != NULL);
    test_assertint(this->st->countDeclare, 0);

    corto_object q = corto_int32DeclareChild(p, "q");
    test_assert(q != NULL);
    test_assertint(this->st->countDeclare, 0);

    ret = corto_define(q);
    test_assert(ret == 0);
    test_assertint(this->st->countDeclare, 0);

    corto_delete(o);
    corto_delete(p);

    test_assertint(this->st->countDeclare, 0);

/* $end */
}

void _test_SubscriberEvent_tc_onDeclareScope(
    test_SubscriberEvent this)
{
/* $begin(test/SubscriberEvent/tc_onDeclareScope) */
    corto_int16 ret;

    test_assert(this->st->countDeclareScope == 0);
    test_assert(!corto_ll_hasObject(this->st->triggered, test_SubscriberTest_onScope_o));
    test_SubscriberTest_clear(this->st);

    corto_object o = corto_int32DeclareChild(testScope, "o");
    test_assert(o != NULL);
    test_assert(this->st->countDeclareScope == 0);

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assert(this->st->countDeclareScope == 0);

    corto_object p = corto_int32CreateChild(testScope, "p", 0);
    test_assert(p != NULL);
    test_assert(this->st->countDeclareScope == 0);

    corto_object q = corto_int32DeclareChild(p, "q");
    test_assert(q != NULL);
    test_assert(this->st->countDeclareScope == 0);

    ret = corto_define(q);
    test_assert(ret == 0);
    test_assert(this->st->countDeclareScope == 0);

    corto_delete(o);
    corto_delete(p);

    test_assert(this->st->countDeclareScope == 0);

/* $end */
}

void _test_SubscriberEvent_tc_onDeclareSelf(
    test_SubscriberEvent this)
{
/* $begin(test/SubscriberEvent/tc_onDeclareSelf) */
    corto_int16 ret;

    test_assert(this->st->countDeclareSelf == 0);
    test_assert(corto_ll_hasObject(this->st->triggered, test_SubscriberTest_onSelf_o));
    test_SubscriberTest_clear(this->st);

    corto_object o = corto_int32DeclareChild(testScope, "o");
    test_assert(o != NULL);
    test_assert(this->st->countDeclareSelf == 0);

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assert(this->st->countDeclareSelf == 0);

    corto_object p = corto_int32CreateChild(testScope, "p", 0);
    test_assert(p != NULL);
    test_assert(this->st->countDeclareSelf == 0);

    corto_object q = corto_int32DeclareChild(p, "q");
    test_assert(q != NULL);
    test_assert(this->st->countDeclareSelf == 0);

    ret = corto_define(q);
    test_assert(ret == 0);
    test_assert(this->st->countDeclareSelf == 0);

    corto_delete(o);
    corto_delete(p);

    test_assert(this->st->countDeclareSelf == 0);

/* $end */
}

void _test_SubscriberEvent_tc_onDeclareTree(
    test_SubscriberEvent this)
{
/* $begin(test/SubscriberEvent/tc_onDeclareTree) */
    corto_int16 ret;

    test_assert(this->st->countDeclareTree == 0);
    test_assert(!corto_ll_hasObject(this->st->triggered, test_SubscriberTest_onTree_o));
    test_SubscriberTest_clear(this->st);

    corto_object o = corto_int32DeclareChild(testScope, "o");
    test_assert(o != NULL);
    test_assert(this->st->countDeclareTree == 0);

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assert(this->st->countDeclareTree == 0);

    corto_object p = corto_int32CreateChild(testScope, "p", 0);
    test_assert(p != NULL);
    test_assert(this->st->countDeclareTree == 0);

    corto_object q = corto_int32DeclareChild(p, "q");
    test_assert(q != NULL);
    test_assert(this->st->countDeclareTree == 0);

    ret = corto_define(q);
    test_assert(ret == 0);
    test_assert(this->st->countDeclareTree == 0);

    corto_delete(o);
    corto_delete(p);

    test_assert(this->st->countDeclareTree == 0);

/* $end */
}

void _test_SubscriberEvent_tc_onDefine(
    test_SubscriberEvent this)
{
/* $begin(test/SubscriberEvent/tc_onDefine) */
    corto_int16 ret;

    test_assertint(this->st->countDefine, 1);
    test_assert(corto_ll_hasObject(this->st->triggered, test_SubscriberTest_onAll_o));
    test_SubscriberTest_clear(this->st);

    corto_object o = corto_int32DeclareChild(testScope, "o");
    test_assert(o != NULL);
    test_assertint(this->st->countDefine, 1);
    test_assert(!corto_ll_hasObject(this->st->triggered, test_SubscriberTest_onAll_o));

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assertint(this->st->countDefine, 2);
    test_assertstr(this->st->lastParent, ".");
    test_assertstr(this->st->lastId, "o");
    test_assert(this->st->lastMask & CORTO_ON_DEFINE);
    test_assert(corto_ll_hasObject(this->st->triggered, test_SubscriberTest_onAll_o));
    test_SubscriberTest_clear(this->st);

    corto_object p = corto_int32CreateChild(testScope, "p", 0);
    test_assert(p != NULL);
    test_assertint(this->st->countDefine, 3);
    test_assertstr(this->st->lastParent, ".");
    test_assertstr(this->st->lastId, "p");
    test_assert(this->st->lastMask & CORTO_ON_DEFINE);
    test_assert(corto_ll_hasObject(this->st->triggered, test_SubscriberTest_onAll_o));
    test_SubscriberTest_clear(this->st);

    corto_object q = corto_int32DeclareChild(p, "q");
    test_assert(q != NULL);
    test_assertint(this->st->countDefine, 3);

    ret = corto_define(q);
    test_assert(ret == 0);
    test_assertint(this->st->countDefine, 4);
    test_assertstr(this->st->lastParent, "p");
    test_assertstr(this->st->lastId, "q");
    test_assert(this->st->lastMask & CORTO_ON_DEFINE);
    test_assert(corto_ll_hasObject(this->st->triggered, test_SubscriberTest_onAll_o));
    test_SubscriberTest_clear(this->st);

    corto_delete(o);
    corto_delete(p);

    test_assertint(this->st->countDefine, 4);

/* $end */
}

void _test_SubscriberEvent_tc_onDefineScope(
    test_SubscriberEvent this)
{
/* $begin(test/SubscriberEvent/tc_onDefineScope) */
    corto_int16 ret;

    test_assert(this->st->countDefineScope == 0);
    test_assert(!corto_ll_hasObject(this->st->triggered, test_SubscriberTest_onScope_o));

    corto_object o = corto_int32DeclareChild(testScope, "o");
    test_assert(o != NULL);
    test_assert(this->st->countDefineScope == 0);
    test_assert(!corto_ll_hasObject(this->st->triggered, test_SubscriberTest_onScope_o));

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assert(this->st->countDefineScope == 1);
    test_assertstr(this->st->lastParent, ".");
    test_assertstr(this->st->lastId, "o");
    test_assert(this->st->lastMask & CORTO_ON_DEFINE);
    test_assert(corto_ll_hasObject(this->st->triggered, test_SubscriberTest_onScope_o));
    test_SubscriberTest_clear(this->st);

    corto_object p = corto_int32CreateChild(testScope, "p", 0);
    test_assert(p != NULL);
    test_assert(this->st->countDefineScope == 2);
    test_assertstr(this->st->lastParent, ".");
    test_assertstr(this->st->lastId, "p");
    test_assert(this->st->lastMask & CORTO_ON_DEFINE);
    test_assert(corto_ll_hasObject(this->st->triggered, test_SubscriberTest_onScope_o));
    test_SubscriberTest_clear(this->st);

    corto_object q = corto_int32DeclareChild(p, "q");
    test_assert(q != NULL);
    test_assert(this->st->countDefineScope == 2);

    ret = corto_define(q);
    test_assert(ret == 0);
    test_assert(this->st->countDefineScope == 2);
    test_assert(!corto_ll_hasObject(this->st->triggered, test_SubscriberTest_onScope_o));
    test_SubscriberTest_clear(this->st);

    corto_delete(o);
    corto_delete(p);

    test_assert(this->st->countDefineScope == 2);

/* $end */
}

void _test_SubscriberEvent_tc_onDefineSelf(
    test_SubscriberEvent this)
{
/* $begin(test/SubscriberEvent/tc_onDefineSelf) */
    corto_int16 ret;

    test_assert(this->st->countDefineSelf == 1);
    test_assert(corto_ll_hasObject(this->st->triggered, test_SubscriberTest_onSelf_o));
    test_SubscriberTest_clear(this->st);

    corto_object o = corto_int32DeclareChild(testScope, "o");
    test_assert(o != NULL);
    test_assert(this->st->countDefineSelf == 1);
    test_assert(!corto_ll_hasObject(this->st->triggered, test_SubscriberTest_onSelf_o));

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assert(this->st->countDefineSelf == 1);
    test_assert(!corto_ll_hasObject(this->st->triggered, test_SubscriberTest_onSelf_o));

    corto_object p = corto_int32CreateChild(testScope, "p", 0);
    test_assert(p != NULL);
    test_assert(this->st->countDefineSelf == 1);
    test_assert(!corto_ll_hasObject(this->st->triggered, test_SubscriberTest_onSelf_o));

    corto_object q = corto_int32DeclareChild(p, "q");
    test_assert(q != NULL);
    test_assert(!corto_ll_hasObject(this->st->triggered, test_SubscriberTest_onSelf_o));
    test_assert(this->st->countDefineSelf == 1);

    ret = corto_define(q);
    test_assert(ret == 0);
    test_assert(this->st->countDefineSelf == 1);
    test_assert(!corto_ll_hasObject(this->st->triggered, test_SubscriberTest_onSelf_o));

    corto_delete(o);
    corto_delete(p);

    test_assert(this->st->countDefineSelf == 1);

/* $end */
}

void _test_SubscriberEvent_tc_onDefineTree(
    test_SubscriberEvent this)
{
/* $begin(test/SubscriberEvent/tc_onDefineTree) */
    corto_int16 ret;

    test_assert(this->st->countDefineTree == 0);
    test_assert(!corto_ll_hasObject(this->st->triggered, test_SubscriberTest_onTree_o));

    corto_object o = corto_int32DeclareChild(testScope, "o");
    test_assert(o != NULL);
    test_assert(this->st->countDefineTree == 0);
    test_assert(!corto_ll_hasObject(this->st->triggered, test_SubscriberTest_onTree_o));

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assert(this->st->countDefineTree == 1);
    test_assertstr(this->st->lastParent, ".");
    test_assertstr(this->st->lastId, "o");
    test_assert(this->st->lastMask & CORTO_ON_DEFINE);
    test_assert(corto_ll_hasObject(this->st->triggered, test_SubscriberTest_onTree_o));
    test_SubscriberTest_clear(this->st);

    corto_object p = corto_int32CreateChild(testScope, "p", 0);
    test_assert(p != NULL);
    test_assert(this->st->countDefineTree == 2);
    test_assertstr(this->st->lastParent, ".");
    test_assertstr(this->st->lastId, "p");
    test_assert(this->st->lastMask & CORTO_ON_DEFINE);
    test_assert(corto_ll_hasObject(this->st->triggered, test_SubscriberTest_onTree_o));
    test_SubscriberTest_clear(this->st);

    corto_object q = corto_int32DeclareChild(p, "q");
    test_assert(q != NULL);
    test_assert(this->st->countDefineTree == 2);
    test_assert(!corto_ll_hasObject(this->st->triggered, test_SubscriberTest_onTree_o));

    ret = corto_define(q);
    test_assert(ret == 0);
    test_assert(this->st->countDefineTree == 3);
    test_assertstr(this->st->lastParent, "p");
    test_assertstr(this->st->lastId, "q");
    test_assert(this->st->lastMask & CORTO_ON_DEFINE);
    test_assert(corto_ll_hasObject(this->st->triggered, test_SubscriberTest_onTree_o));
    test_SubscriberTest_clear(this->st);

    corto_delete(o);
    corto_delete(p);

    test_assert(this->st->countDefineTree == 3);

/* $end */
}

void _test_SubscriberEvent_tc_onUpdate(
    test_SubscriberEvent this)
{
/* $begin(test/SubscriberEvent/tc_onUpdate) */
    int ret;

    test_assertint(this->st->countUpdate, 0);

    ret = corto_update(testScope);
    test_assert(ret == 0);
    test_assertint(this->st->countUpdate, 1);
    test_assertstr(this->st->lastParent, "..");
    test_assertstr(this->st->lastId, "testScope");
    test_assert(this->st->lastMask & CORTO_ON_UPDATE);
    test_assert(corto_ll_hasObject(this->st->triggered, test_SubscriberTest_onAll_o));
    test_SubscriberTest_clear(this->st);

    corto_object o = corto_int32DeclareChild(testScope, "o");
    test_assert(o != NULL);
    test_assertint(this->st->countUpdate, 1);

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assertint(this->st->countUpdate, 1);

    ret = corto_updateBegin(o);
    test_assert(ret == 0);
    test_assertint(this->st->countUpdate, 1);

    corto_updateEnd(o);
    test_assert(ret == 0);
    test_assertint(this->st->countUpdate, 2);
    test_assertstr(this->st->lastParent, ".");
    test_assertstr(this->st->lastId, "o");
    test_assert(this->st->lastMask & CORTO_ON_UPDATE);
    test_assert(corto_ll_hasObject(this->st->triggered, test_SubscriberTest_onAll_o));
    test_SubscriberTest_clear(this->st);

    corto_object p = corto_int32CreateChild(testScope, "p", 0);
    test_assert(p != NULL);
    test_assertint(this->st->countUpdate, 2);

    ret = corto_updateBegin(p);
    test_assert(ret == 0);
    test_assertint(this->st->countUpdate, 2);

    corto_updateEnd(p);
    test_assert(ret == 0);
    test_assertint(this->st->countUpdate, 3);
    test_assertstr(this->st->lastParent, ".");
    test_assertstr(this->st->lastId, "p");
    test_assert(this->st->lastMask & CORTO_ON_UPDATE);
    test_assert(corto_ll_hasObject(this->st->triggered, test_SubscriberTest_onAll_o));
    test_SubscriberTest_clear(this->st);

    corto_object q = corto_int32DeclareChild(p, "q");
    test_assert(q != NULL);
    test_assertint(this->st->countUpdate, 3);

    ret = corto_define(q);
    test_assert(ret == 0);
    test_assertint(this->st->countUpdate, 3);

    ret = corto_updateBegin(q);
    test_assert(ret == 0);
    test_assertint(this->st->countUpdate, 3);

    corto_updateEnd(q);
    test_assert(ret == 0);
    test_assertint(this->st->countUpdate, 4);
    test_assertstr(this->st->lastParent, "p");
    test_assertstr(this->st->lastId, "q");
    test_assert(this->st->lastMask & CORTO_ON_UPDATE);
    test_assert(corto_ll_hasObject(this->st->triggered, test_SubscriberTest_onAll_o));
    test_SubscriberTest_clear(this->st);

    corto_delete(o);
    corto_delete(p);

    test_assertint(this->st->countUpdate, 4);

/* $end */
}

void _test_SubscriberEvent_tc_onUpdateScope(
    test_SubscriberEvent this)
{
/* $begin(test/SubscriberEvent/tc_onUpdateScope) */
    int ret;

    test_assertint(this->st->countUpdateScope, 0);

    ret = corto_update(testScope);
    test_assert(ret == 0);
    test_assertint(this->st->countUpdateScope, 0);

    corto_object o = corto_int32DeclareChild(testScope, "o");
    test_assert(o != NULL);
    test_assertint(this->st->countUpdateScope, 0);

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assertint(this->st->countUpdateScope, 0);

    ret = corto_updateBegin(o);
    test_assert(ret == 0);
    test_assertint(this->st->countUpdateScope, 0);

    corto_updateEnd(o);
    test_assert(ret == 0);
    test_assertint(this->st->countUpdateScope, 1);
    test_assertstr(this->st->lastParent, ".");
    test_assertstr(this->st->lastId, "o");
    test_assert(this->st->lastMask & CORTO_ON_UPDATE);
    test_assert(corto_ll_hasObject(this->st->triggered, test_SubscriberTest_onAll_o));
    test_SubscriberTest_clear(this->st);

    corto_object p = corto_int32CreateChild(testScope, "p", 0);
    test_assert(p != NULL);
    test_assertint(this->st->countUpdateScope, 1);

    ret = corto_updateBegin(p);
    test_assert(ret == 0);
    test_assertint(this->st->countUpdateScope, 1);

    corto_updateEnd(p);
    test_assert(ret == 0);
    test_assertint(this->st->countUpdateScope, 2);
    test_assertstr(this->st->lastParent, ".");
    test_assertstr(this->st->lastId, "p");
    test_assert(this->st->lastMask & CORTO_ON_UPDATE);
    test_assert(corto_ll_hasObject(this->st->triggered, test_SubscriberTest_onAll_o));
    test_SubscriberTest_clear(this->st);

    corto_object q = corto_int32DeclareChild(p, "q");
    test_assert(q != NULL);
    test_assertint(this->st->countUpdateScope, 2);

    ret = corto_define(q);
    test_assert(ret == 0);
    test_assertint(this->st->countUpdateScope, 2);

    ret = corto_updateBegin(q);
    test_assert(ret == 0);
    test_assertint(this->st->countUpdateScope, 2);

    corto_updateEnd(q);
    test_assert(ret == 0);
    test_assertint(this->st->countUpdateScope, 2);
    test_assertstr(this->st->lastParent, "p");
    test_assertstr(this->st->lastId, "q");
    test_assert(this->st->lastMask & CORTO_ON_UPDATE);
    test_assert(corto_ll_hasObject(this->st->triggered, test_SubscriberTest_onAll_o));
    test_SubscriberTest_clear(this->st);

    corto_delete(o);
    corto_delete(p);

    test_assertint(this->st->countUpdateScope, 2);

/* $end */
}

void _test_SubscriberEvent_tc_onUpdateSelf(
    test_SubscriberEvent this)
{
/* $begin(test/SubscriberEvent/tc_onUpdateSelf) */
    int ret;

    test_assertint(this->st->countUpdateSelf, 0);

    ret = corto_update(testScope);
    test_assert(ret == 0);
    test_assertint(this->st->countUpdateSelf, 1);
    test_assertstr(this->st->lastParent, "..");
    test_assertstr(this->st->lastId, "testScope");
    test_assert(this->st->lastMask & CORTO_ON_UPDATE);
    test_assert(corto_ll_hasObject(this->st->triggered, test_SubscriberTest_onAll_o));
    test_SubscriberTest_clear(this->st);

    corto_object o = corto_int32DeclareChild(testScope, "o");
    test_assert(o != NULL);
    test_assertint(this->st->countUpdateSelf, 1);

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assertint(this->st->countUpdateSelf, 1);

    ret = corto_updateBegin(o);
    test_assert(ret == 0);
    test_assertint(this->st->countUpdateSelf, 1);

    corto_updateEnd(o);
    test_assert(ret == 0);
    test_assertint(this->st->countUpdateSelf, 1);

    corto_object p = corto_int32CreateChild(testScope, "p", 0);
    test_assert(p != NULL);
    test_assertint(this->st->countUpdateSelf, 1);

    ret = corto_updateBegin(p);
    test_assert(ret == 0);
    test_assertint(this->st->countUpdateSelf, 1);

    corto_updateEnd(p);
    test_assert(ret == 0);
    test_assertint(this->st->countUpdateSelf, 1);

    corto_object q = corto_int32DeclareChild(p, "q");
    test_assert(q != NULL);
    test_assertint(this->st->countUpdateSelf, 1);

    ret = corto_define(q);
    test_assert(ret == 0);
    test_assertint(this->st->countUpdateSelf, 1);

    ret = corto_updateBegin(q);
    test_assert(ret == 0);
    test_assertint(this->st->countUpdateSelf, 1);

    corto_updateEnd(q);
    test_assert(ret == 0);
    test_assertint(this->st->countUpdateSelf, 1);

    corto_delete(o);
    corto_delete(p);

    test_assertint(this->st->countUpdateSelf, 1);

/* $end */
}

void _test_SubscriberEvent_tc_onUpdateTree(
    test_SubscriberEvent this)
{
/* $begin(test/SubscriberEvent/tc_onUpdateTree) */
    int ret;

    test_assertint(this->st->countUpdateTree, 0);

    ret = corto_update(testScope);
    test_assert(ret == 0);
    test_assertint(this->st->countUpdateTree, 0);

    corto_object o = corto_int32DeclareChild(testScope, "o");
    test_assert(o != NULL);
    test_assertint(this->st->countUpdateTree, 0);

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assertint(this->st->countUpdateTree, 0);

    ret = corto_updateBegin(o);
    test_assert(ret == 0);
    test_assertint(this->st->countUpdateTree, 0);

    corto_updateEnd(o);
    test_assert(ret == 0);
    test_assertint(this->st->countUpdateTree, 1);
    test_assertstr(this->st->lastParent, ".");
    test_assertstr(this->st->lastId, "o");
    test_assert(this->st->lastMask & CORTO_ON_UPDATE);
    test_assert(corto_ll_hasObject(this->st->triggered, test_SubscriberTest_onAll_o));
    test_SubscriberTest_clear(this->st);

    corto_object p = corto_int32CreateChild(testScope, "p", 0);
    test_assert(p != NULL);
    test_assertint(this->st->countUpdateTree, 1);

    ret = corto_updateBegin(p);
    test_assert(ret == 0);
    test_assertint(this->st->countUpdateTree, 1);

    corto_updateEnd(p);
    test_assert(ret == 0);
    test_assertint(this->st->countUpdateTree, 2);
    test_assertstr(this->st->lastParent, ".");
    test_assertstr(this->st->lastId, "p");
    test_assert(this->st->lastMask & CORTO_ON_UPDATE);
    test_assert(corto_ll_hasObject(this->st->triggered, test_SubscriberTest_onAll_o));
    test_SubscriberTest_clear(this->st);

    corto_object q = corto_int32DeclareChild(p, "q");
    test_assert(q != NULL);
    test_assertint(this->st->countUpdateTree, 2);

    ret = corto_define(q);
    test_assert(ret == 0);
    test_assertint(this->st->countUpdateTree, 2);

    ret = corto_updateBegin(q);
    test_assert(ret == 0);
    test_assertint(this->st->countUpdateTree, 2);

    corto_updateEnd(q);
    test_assert(ret == 0);
    test_assertint(this->st->countUpdateTree, 3);
    test_assertstr(this->st->lastParent, "p");
    test_assertstr(this->st->lastId, "q");
    test_assert(this->st->lastMask & CORTO_ON_UPDATE);
    test_assert(corto_ll_hasObject(this->st->triggered, test_SubscriberTest_onAll_o));
    test_SubscriberTest_clear(this->st);

    corto_delete(o);
    corto_delete(p);

    test_assertint(this->st->countUpdateTree, 3);

/* $end */
}

void _test_SubscriberEvent_teardown(
    test_SubscriberEvent this)
{
/* $begin(test/SubscriberEvent/teardown) */

    corto_setAttr(this->prevAttr);

    /* Delete before stopping testcase, to catch errors while unsubscribing */
    corto_ptr_setref(&this->st, NULL);

/* $end */
}
