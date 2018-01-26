/* This is a managed file. Do not delete this comment. */

#include <include/test.h>
static corto_object testScope;
void test_SubscriberEvent_setup(
    test_SubscriberEvent this)
{

    this->prevAttr = corto_set_attr(CORTO_ATTR_DEFAULT);
    corto_void__create(root_o, "shouldNotBeMatched");
    testScope = corto_void__create(root_o, "testScope");
    test_assert(testScope != NULL);
    test_SubscriberTest st = test_SubscriberTest__create(NULL, NULL);
    test_assert(st != NULL);
    corto_set_ref(&this->st, st);
    corto_release(st);


}

void test_SubscriberEvent_tc_onDeclare(
    test_SubscriberEvent this)
{
    corto_int16 ret;

    test_assertint(this->st->countDeclare, 0);
    test_assert(corto_ll_hasObject(this->st->triggered, test_SubscriberTest_onAll_o));
    test_SubscriberTest_clear(this->st);

    corto_object o = corto_declare(testScope, "o", corto_int32_o);
    test_assert(o != NULL);
    test_assertint(this->st->countDeclare, 0);

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assertint(this->st->countDeclare, 0);

    corto_object p = corto_int32__create(testScope, "p", 0);
    test_assert(p != NULL);
    test_assertint(this->st->countDeclare, 0);

    corto_object q = corto_declare(p, "q", corto_int32_o);
    test_assert(q != NULL);
    test_assertint(this->st->countDeclare, 0);

    ret = corto_define(q);
    test_assert(ret == 0);
    test_assertint(this->st->countDeclare, 0);

    corto_delete(o);
    corto_delete(p);

    test_assertint(this->st->countDeclare, 0);

}

void test_SubscriberEvent_tc_onDeclareScope(
    test_SubscriberEvent this)
{
    corto_int16 ret;

    test_assert(this->st->countDeclareScope == 0);
    test_assert(!corto_ll_hasObject(this->st->triggered, test_SubscriberTest_onScope_o));
    test_SubscriberTest_clear(this->st);

    corto_object o = corto_declare(testScope, "o", corto_int32_o);
    test_assert(o != NULL);
    test_assert(this->st->countDeclareScope == 0);

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assert(this->st->countDeclareScope == 0);

    corto_object p = corto_int32__create(testScope, "p", 0);
    test_assert(p != NULL);
    test_assert(this->st->countDeclareScope == 0);

    corto_object q = corto_declare(p, "q", corto_int32_o);
    test_assert(q != NULL);
    test_assert(this->st->countDeclareScope == 0);

    ret = corto_define(q);
    test_assert(ret == 0);
    test_assert(this->st->countDeclareScope == 0);

    corto_delete(o);
    corto_delete(p);

    test_assert(this->st->countDeclareScope == 0);

}

void test_SubscriberEvent_tc_onDeclareSelf(
    test_SubscriberEvent this)
{
    corto_int16 ret;

    test_assert(this->st->countDeclareSelf == 0);
    test_assert(corto_ll_hasObject(this->st->triggered, test_SubscriberTest_onSelf_o));
    test_SubscriberTest_clear(this->st);

    corto_object o = corto_declare(testScope, "o", corto_int32_o);
    test_assert(o != NULL);
    test_assert(this->st->countDeclareSelf == 0);

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assert(this->st->countDeclareSelf == 0);

    corto_object p = corto_int32__create(testScope, "p", 0);
    test_assert(p != NULL);
    test_assert(this->st->countDeclareSelf == 0);

    corto_object q = corto_declare(p, "q", corto_int32_o);
    test_assert(q != NULL);
    test_assert(this->st->countDeclareSelf == 0);

    ret = corto_define(q);
    test_assert(ret == 0);
    test_assert(this->st->countDeclareSelf == 0);

    corto_delete(o);
    corto_delete(p);

    test_assert(this->st->countDeclareSelf == 0);

}

void test_SubscriberEvent_tc_onDeclareTree(
    test_SubscriberEvent this)
{
    corto_int16 ret;

    test_assert(this->st->countDeclareTree == 0);
    test_assert(!corto_ll_hasObject(this->st->triggered, test_SubscriberTest_onTree_o));
    test_SubscriberTest_clear(this->st);

    corto_object o = corto_declare(testScope, "o", corto_int32_o);
    test_assert(o != NULL);
    test_assert(this->st->countDeclareTree == 0);

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assert(this->st->countDeclareTree == 0);

    corto_object p = corto_int32__create(testScope, "p", 0);
    test_assert(p != NULL);
    test_assert(this->st->countDeclareTree == 0);

    corto_object q = corto_declare(p, "q", corto_int32_o);
    test_assert(q != NULL);
    test_assert(this->st->countDeclareTree == 0);

    ret = corto_define(q);
    test_assert(ret == 0);
    test_assert(this->st->countDeclareTree == 0);

    corto_delete(o);
    corto_delete(p);

    test_assert(this->st->countDeclareTree == 0);

}

void test_SubscriberEvent_tc_onDefine(
    test_SubscriberEvent this)
{
    corto_int16 ret;

    test_assertint(this->st->countDefine, 1);
    test_assert(corto_ll_hasObject(this->st->triggered, test_SubscriberTest_onAll_o));
    test_SubscriberTest_clear(this->st);

    corto_object o = corto_declare(testScope, "o", corto_int32_o);
    test_assert(o != NULL);
    test_assertint(this->st->countDefine, 1);
    test_assert(!corto_ll_hasObject(this->st->triggered, test_SubscriberTest_onAll_o));

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assertint(this->st->countDefine, 2);
    test_assertstr(this->st->lastParent, ".");
    test_assertstr(this->st->lastId, "o");
    test_assert(this->st->lastMask & CORTO_DEFINE);
    test_assert(corto_ll_hasObject(this->st->triggered, test_SubscriberTest_onAll_o));
    test_SubscriberTest_clear(this->st);

    corto_object p = corto_int32__create(testScope, "p", 0);
    test_assert(p != NULL);
    test_assertint(this->st->countDefine, 3);
    test_assertstr(this->st->lastParent, ".");
    test_assertstr(this->st->lastId, "p");
    test_assert(this->st->lastMask & CORTO_DEFINE);
    test_assert(corto_ll_hasObject(this->st->triggered, test_SubscriberTest_onAll_o));
    test_SubscriberTest_clear(this->st);

    corto_object q = corto_declare(p, "q", corto_int32_o);
    test_assert(q != NULL);
    test_assertint(this->st->countDefine, 3);

    ret = corto_define(q);
    test_assert(ret == 0);
    test_assertint(this->st->countDefine, 4);
    test_assertstr(this->st->lastParent, "p");
    test_assertstr(this->st->lastId, "q");
    test_assert(this->st->lastMask & CORTO_DEFINE);
    test_assert(corto_ll_hasObject(this->st->triggered, test_SubscriberTest_onAll_o));
    test_SubscriberTest_clear(this->st);

    corto_delete(o);
    corto_delete(p);

    test_assertint(this->st->countDefine, 4);

}

void test_SubscriberEvent_tc_onDefineScope(
    test_SubscriberEvent this)
{
    corto_int16 ret;

    test_assert(this->st->countDefineScope == 0);
    test_assert(!corto_ll_hasObject(this->st->triggered, test_SubscriberTest_onScope_o));

    corto_object o = corto_declare(testScope, "o", corto_int32_o);
    test_assert(o != NULL);
    test_assert(this->st->countDefineScope == 0);
    test_assert(!corto_ll_hasObject(this->st->triggered, test_SubscriberTest_onScope_o));

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assert(this->st->countDefineScope == 1);
    test_assertstr(this->st->lastParent, ".");
    test_assertstr(this->st->lastId, "o");
    test_assert(this->st->lastMask & CORTO_DEFINE);
    test_assert(corto_ll_hasObject(this->st->triggered, test_SubscriberTest_onScope_o));
    test_SubscriberTest_clear(this->st);

    corto_object p = corto_int32__create(testScope, "p", 0);
    test_assert(p != NULL);
    test_assert(this->st->countDefineScope == 2);
    test_assertstr(this->st->lastParent, ".");
    test_assertstr(this->st->lastId, "p");
    test_assert(this->st->lastMask & CORTO_DEFINE);
    test_assert(corto_ll_hasObject(this->st->triggered, test_SubscriberTest_onScope_o));
    test_SubscriberTest_clear(this->st);

    corto_object q = corto_declare(p, "q", corto_int32_o);
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

}

void test_SubscriberEvent_tc_onDefineSelf(
    test_SubscriberEvent this)
{
    corto_int16 ret;

    test_assert(this->st->countDefineSelf == 1);
    test_assert(corto_ll_hasObject(this->st->triggered, test_SubscriberTest_onSelf_o));
    test_SubscriberTest_clear(this->st);

    corto_object o = corto_declare(testScope, "o", corto_int32_o);
    test_assert(o != NULL);
    test_assert(this->st->countDefineSelf == 1);
    test_assert(!corto_ll_hasObject(this->st->triggered, test_SubscriberTest_onSelf_o));

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assert(this->st->countDefineSelf == 1);
    test_assert(!corto_ll_hasObject(this->st->triggered, test_SubscriberTest_onSelf_o));

    corto_object p = corto_int32__create(testScope, "p", 0);
    test_assert(p != NULL);
    test_assert(this->st->countDefineSelf == 1);
    test_assert(!corto_ll_hasObject(this->st->triggered, test_SubscriberTest_onSelf_o));

    corto_object q = corto_declare(p, "q", corto_int32_o);
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

}

void test_SubscriberEvent_tc_onDefineTree(
    test_SubscriberEvent this)
{
    corto_int16 ret;

    test_assert(this->st->countDefineTree == 0);
    test_assert(!corto_ll_hasObject(this->st->triggered, test_SubscriberTest_onTree_o));

    corto_object o = corto_declare(testScope, "o", corto_int32_o);
    test_assert(o != NULL);
    test_assert(this->st->countDefineTree == 0);
    test_assert(!corto_ll_hasObject(this->st->triggered, test_SubscriberTest_onTree_o));

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assert(this->st->countDefineTree == 1);
    test_assertstr(this->st->lastParent, ".");
    test_assertstr(this->st->lastId, "o");
    test_assert(this->st->lastMask & CORTO_DEFINE);
    test_assert(corto_ll_hasObject(this->st->triggered, test_SubscriberTest_onTree_o));
    test_SubscriberTest_clear(this->st);

    corto_object p = corto_int32__create(testScope, "p", 0);
    test_assert(p != NULL);
    test_assert(this->st->countDefineTree == 2);
    test_assertstr(this->st->lastParent, ".");
    test_assertstr(this->st->lastId, "p");
    test_assert(this->st->lastMask & CORTO_DEFINE);
    test_assert(corto_ll_hasObject(this->st->triggered, test_SubscriberTest_onTree_o));
    test_SubscriberTest_clear(this->st);

    corto_object q = corto_declare(p, "q", corto_int32_o);
    test_assert(q != NULL);
    test_assert(this->st->countDefineTree == 2);
    test_assert(!corto_ll_hasObject(this->st->triggered, test_SubscriberTest_onTree_o));

    ret = corto_define(q);
    test_assert(ret == 0);
    test_assert(this->st->countDefineTree == 3);
    test_assertstr(this->st->lastParent, "p");
    test_assertstr(this->st->lastId, "q");
    test_assert(this->st->lastMask & CORTO_DEFINE);
    test_assert(corto_ll_hasObject(this->st->triggered, test_SubscriberTest_onTree_o));
    test_SubscriberTest_clear(this->st);

    corto_delete(o);
    corto_delete(p);

    test_assert(this->st->countDefineTree == 3);

}

void test_SubscriberEvent_tc_on__update(
    test_SubscriberEvent this)
{
    int ret;

    test_assertint(this->st->countUpdate, 0);

    ret = corto_update(testScope);
    test_assert(ret == 0);
    test_assertint(this->st->countUpdate, 1);
    test_assertstr(this->st->lastParent, "..");
    test_assertstr(this->st->lastId, "testScope");
    test_assert(this->st->lastMask & CORTO_UPDATE);
    test_assert(corto_ll_hasObject(this->st->triggered, test_SubscriberTest_onAll_o));
    test_SubscriberTest_clear(this->st);

    corto_object o = corto_declare(testScope, "o", corto_int32_o);
    test_assert(o != NULL);
    test_assertint(this->st->countUpdate, 1);

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assertint(this->st->countUpdate, 1);

    ret = corto_update_begin(o);
    test_assert(ret == 0);
    test_assertint(this->st->countUpdate, 1);

    corto_update_end(o);
    test_assert(ret == 0);
    test_assertint(this->st->countUpdate, 2);
    test_assertstr(this->st->lastParent, ".");
    test_assertstr(this->st->lastId, "o");
    test_assert(this->st->lastMask & CORTO_UPDATE);
    test_assert(corto_ll_hasObject(this->st->triggered, test_SubscriberTest_onAll_o));
    test_SubscriberTest_clear(this->st);

    corto_object p = corto_int32__create(testScope, "p", 0);
    test_assert(p != NULL);
    test_assertint(this->st->countUpdate, 2);

    ret = corto_update_begin(p);
    test_assert(ret == 0);
    test_assertint(this->st->countUpdate, 2);

    corto_update_end(p);
    test_assert(ret == 0);
    test_assertint(this->st->countUpdate, 3);
    test_assertstr(this->st->lastParent, ".");
    test_assertstr(this->st->lastId, "p");
    test_assert(this->st->lastMask & CORTO_UPDATE);
    test_assert(corto_ll_hasObject(this->st->triggered, test_SubscriberTest_onAll_o));
    test_SubscriberTest_clear(this->st);

    corto_object q = corto_declare(p, "q", corto_int32_o);
    test_assert(q != NULL);
    test_assertint(this->st->countUpdate, 3);

    ret = corto_define(q);
    test_assert(ret == 0);
    test_assertint(this->st->countUpdate, 3);

    ret = corto_update_begin(q);
    test_assert(ret == 0);
    test_assertint(this->st->countUpdate, 3);

    corto_update_end(q);
    test_assert(ret == 0);
    test_assertint(this->st->countUpdate, 4);
    test_assertstr(this->st->lastParent, "p");
    test_assertstr(this->st->lastId, "q");
    test_assert(this->st->lastMask & CORTO_UPDATE);
    test_assert(corto_ll_hasObject(this->st->triggered, test_SubscriberTest_onAll_o));
    test_SubscriberTest_clear(this->st);

    corto_delete(o);
    corto_delete(p);

    test_assertint(this->st->countUpdate, 4);

}

void test_SubscriberEvent_tc_onUpdateScope(
    test_SubscriberEvent this)
{
    int ret;

    test_assertint(this->st->countUpdateScope, 0);

    ret = corto_update(testScope);
    test_assert(ret == 0);
    test_assertint(this->st->countUpdateScope, 0);

    corto_object o = corto_declare(testScope, "o", corto_int32_o);
    test_assert(o != NULL);
    test_assertint(this->st->countUpdateScope, 0);

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assertint(this->st->countUpdateScope, 0);

    ret = corto_update_begin(o);
    test_assert(ret == 0);
    test_assertint(this->st->countUpdateScope, 0);

    corto_update_end(o);
    test_assert(ret == 0);
    test_assertint(this->st->countUpdateScope, 1);
    test_assertstr(this->st->lastParent, ".");
    test_assertstr(this->st->lastId, "o");
    test_assert(this->st->lastMask & CORTO_UPDATE);
    test_assert(corto_ll_hasObject(this->st->triggered, test_SubscriberTest_onAll_o));
    test_SubscriberTest_clear(this->st);

    corto_object p = corto_int32__create(testScope, "p", 0);
    test_assert(p != NULL);
    test_assertint(this->st->countUpdateScope, 1);

    ret = corto_update_begin(p);
    test_assert(ret == 0);
    test_assertint(this->st->countUpdateScope, 1);

    corto_update_end(p);
    test_assert(ret == 0);
    test_assertint(this->st->countUpdateScope, 2);
    test_assertstr(this->st->lastParent, ".");
    test_assertstr(this->st->lastId, "p");
    test_assert(this->st->lastMask & CORTO_UPDATE);
    test_assert(corto_ll_hasObject(this->st->triggered, test_SubscriberTest_onAll_o));
    test_SubscriberTest_clear(this->st);

    corto_object q = corto_declare(p, "q", corto_int32_o);
    test_assert(q != NULL);
    test_assertint(this->st->countUpdateScope, 2);

    ret = corto_define(q);
    test_assert(ret == 0);
    test_assertint(this->st->countUpdateScope, 2);

    ret = corto_update_begin(q);
    test_assert(ret == 0);
    test_assertint(this->st->countUpdateScope, 2);

    corto_update_end(q);
    test_assert(ret == 0);
    test_assertint(this->st->countUpdateScope, 2);
    test_assertstr(this->st->lastParent, "p");
    test_assertstr(this->st->lastId, "q");
    test_assert(this->st->lastMask & CORTO_UPDATE);
    test_assert(corto_ll_hasObject(this->st->triggered, test_SubscriberTest_onAll_o));
    test_SubscriberTest_clear(this->st);

    corto_delete(o);
    corto_delete(p);

    test_assertint(this->st->countUpdateScope, 2);

}

void test_SubscriberEvent_tc_onUpdateSelf(
    test_SubscriberEvent this)
{
    int ret;

    test_assertint(this->st->countUpdateSelf, 0);

    ret = corto_update(testScope);
    test_assert(ret == 0);
    test_assertint(this->st->countUpdateSelf, 1);
    test_assertstr(this->st->lastParent, "..");
    test_assertstr(this->st->lastId, "testScope");
    test_assert(this->st->lastMask & CORTO_UPDATE);
    test_assert(corto_ll_hasObject(this->st->triggered, test_SubscriberTest_onAll_o));
    test_SubscriberTest_clear(this->st);

    corto_object o = corto_declare(testScope, "o", corto_int32_o);
    test_assert(o != NULL);
    test_assertint(this->st->countUpdateSelf, 1);

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assertint(this->st->countUpdateSelf, 1);

    ret = corto_update_begin(o);
    test_assert(ret == 0);
    test_assertint(this->st->countUpdateSelf, 1);

    corto_update_end(o);
    test_assert(ret == 0);
    test_assertint(this->st->countUpdateSelf, 1);

    corto_object p = corto_int32__create(testScope, "p", 0);
    test_assert(p != NULL);
    test_assertint(this->st->countUpdateSelf, 1);

    ret = corto_update_begin(p);
    test_assert(ret == 0);
    test_assertint(this->st->countUpdateSelf, 1);

    corto_update_end(p);
    test_assert(ret == 0);
    test_assertint(this->st->countUpdateSelf, 1);

    corto_object q = corto_declare(p, "q", corto_int32_o);
    test_assert(q != NULL);
    test_assertint(this->st->countUpdateSelf, 1);

    ret = corto_define(q);
    test_assert(ret == 0);
    test_assertint(this->st->countUpdateSelf, 1);

    ret = corto_update_begin(q);
    test_assert(ret == 0);
    test_assertint(this->st->countUpdateSelf, 1);

    corto_update_end(q);
    test_assert(ret == 0);
    test_assertint(this->st->countUpdateSelf, 1);

    corto_delete(o);
    corto_delete(p);

    test_assertint(this->st->countUpdateSelf, 1);

}

void test_SubscriberEvent_tc_onUpdateTree(
    test_SubscriberEvent this)
{
    int ret;

    test_assertint(this->st->countUpdateTree, 0);

    ret = corto_update(testScope);
    test_assert(ret == 0);
    test_assertint(this->st->countUpdateTree, 0);

    corto_object o = corto_declare(testScope, "o", corto_int32_o);
    test_assert(o != NULL);
    test_assertint(this->st->countUpdateTree, 0);

    ret = corto_define(o);
    test_assert(ret == 0);
    test_assertint(this->st->countUpdateTree, 0);

    ret = corto_update_begin(o);
    test_assert(ret == 0);
    test_assertint(this->st->countUpdateTree, 0);

    corto_update_end(o);
    test_assert(ret == 0);
    test_assertint(this->st->countUpdateTree, 1);
    test_assertstr(this->st->lastParent, ".");
    test_assertstr(this->st->lastId, "o");
    test_assert(this->st->lastMask & CORTO_UPDATE);
    test_assert(corto_ll_hasObject(this->st->triggered, test_SubscriberTest_onAll_o));
    test_SubscriberTest_clear(this->st);

    corto_object p = corto_int32__create(testScope, "p", 0);
    test_assert(p != NULL);
    test_assertint(this->st->countUpdateTree, 1);

    ret = corto_update_begin(p);
    test_assert(ret == 0);
    test_assertint(this->st->countUpdateTree, 1);

    corto_update_end(p);
    test_assert(ret == 0);
    test_assertint(this->st->countUpdateTree, 2);
    test_assertstr(this->st->lastParent, ".");
    test_assertstr(this->st->lastId, "p");
    test_assert(this->st->lastMask & CORTO_UPDATE);
    test_assert(corto_ll_hasObject(this->st->triggered, test_SubscriberTest_onAll_o));
    test_SubscriberTest_clear(this->st);

    corto_object q = corto_declare(p, "q", corto_int32_o);
    test_assert(q != NULL);
    test_assertint(this->st->countUpdateTree, 2);

    ret = corto_define(q);
    test_assert(ret == 0);
    test_assertint(this->st->countUpdateTree, 2);

    ret = corto_update_begin(q);
    test_assert(ret == 0);
    test_assertint(this->st->countUpdateTree, 2);

    corto_update_end(q);
    test_assert(ret == 0);
    test_assertint(this->st->countUpdateTree, 3);
    test_assertstr(this->st->lastParent, "p");
    test_assertstr(this->st->lastId, "q");
    test_assert(this->st->lastMask & CORTO_UPDATE);
    test_assert(corto_ll_hasObject(this->st->triggered, test_SubscriberTest_onAll_o));
    test_SubscriberTest_clear(this->st);

    corto_delete(o);
    corto_delete(p);

    test_assertint(this->st->countUpdateTree, 3);

}

void test_SubscriberEvent_teardown(
    test_SubscriberEvent this)
{

    corto_set_attr(this->prevAttr);

    /* Delete before stopping testcase, to catch errors while unsubscribing */
    corto_set_ref(&this->st, NULL);

}

void test_SubscriberEvent_tc_onUpdate(
    test_SubscriberEvent this)
{
    /* Insert implementation */
}

