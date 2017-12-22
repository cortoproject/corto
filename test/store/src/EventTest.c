/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

int16_t test_EventTest_construct(
    test_EventTest this)
{
    corto_int16 ret;

    ret = corto_observer_observe(test_EventTest_onDeclare_o, this, this->scope);
    test_assert(ret == 0);
    ret = corto_observer_observe(test_EventTest_onDeclareSelf_o, this, this->scope);
    test_assert(ret == 0);
    ret = corto_observer_observe(test_EventTest_onDeclareScope_o, this, this->scope);
    test_assert(ret == 0);
    ret = corto_observer_observe(test_EventTest_onDeclareTree_o, this, this->scope);
    test_assert(ret == 0);

    ret = corto_observer_observe(test_EventTest_onDefine_o, this, this->scope);
    test_assert(ret == 0);
    ret = corto_observer_observe(test_EventTest_onDefineSelf_o, this, this->scope);
    test_assert(ret == 0);
    ret = corto_observer_observe(test_EventTest_onDefineScope_o, this, this->scope);
    test_assert(ret == 0);
    ret = corto_observer_observe(test_EventTest_onDefineTree_o, this, this->scope);
    test_assert(ret == 0);

    ret = corto_observer_observe(test_EventTest_onUpdate_o, this, this->scope);
    test_assert(ret == 0);
    ret = corto_observer_observe(test_EventTest_onUpdateSelf_o, this, this->scope);
    test_assert(ret == 0);
    ret = corto_observer_observe(test_EventTest_onUpdateScope_o, this, this->scope);
    test_assert(ret == 0);
    ret = corto_observer_observe(test_EventTest_onUpdateTree_o, this, this->scope);
    test_assert(ret == 0);

    ret = corto_observer_observe(test_EventTest_onDelete_o, this, this->scope);
    test_assert(ret == 0);
    ret = corto_observer_observe(test_EventTest_onDeleteSelf_o, this, this->scope);
    test_assert(ret == 0);
    ret = corto_observer_observe(test_EventTest_onDeleteScope_o, this, this->scope);
    test_assert(ret == 0);
    ret = corto_observer_observe(test_EventTest_onDeleteTree_o, this, this->scope);
    test_assert(ret == 0);

    ret = corto_observer_observe(test_EventTest_onUpdateDefine_o, this, this->scope);
    test_assert(ret == 0);
    ret = corto_observer_observe(test_EventTest_onUpdateDefineSelf_o, this, this->scope);
    test_assert(ret == 0);
    ret = corto_observer_observe(test_EventTest_onUpdateDefineScope_o, this, this->scope);
    test_assert(ret == 0);
    ret = corto_observer_observe(test_EventTest_onUpdateDefineTree_o, this, this->scope);
    test_assert(ret == 0);

    return 0;
}

void test_EventTest_destruct(
    test_EventTest this)
{
    corto_int16 ret;

    ret = corto_observer_unobserve(test_EventTest_onDeclare_o, this, this->scope);
    test_assert(ret == 0);
    ret = corto_observer_unobserve(test_EventTest_onDeclareSelf_o, this, this->scope);
    test_assert(ret == 0);
    ret = corto_observer_unobserve(test_EventTest_onDeclareScope_o, this, this->scope);
    test_assert(ret == 0);
    ret = corto_observer_unobserve(test_EventTest_onDeclareTree_o, this, this->scope);
    test_assert(ret == 0);

    ret = corto_observer_unobserve(test_EventTest_onDefine_o, this, this->scope);
    test_assert(ret == 0);
    ret = corto_observer_unobserve(test_EventTest_onDefineSelf_o, this, this->scope);
    test_assert(ret == 0);
    ret = corto_observer_unobserve(test_EventTest_onDefineScope_o, this, this->scope);
    test_assert(ret == 0);
    ret = corto_observer_unobserve(test_EventTest_onDefineTree_o, this, this->scope);
    test_assert(ret == 0);

    ret = corto_observer_unobserve(test_EventTest_onUpdate_o, this, this->scope);
    test_assert(ret == 0);
    ret = corto_observer_unobserve(test_EventTest_onUpdateSelf_o, this, this->scope);
    test_assert(ret == 0);
    ret = corto_observer_unobserve(test_EventTest_onUpdateScope_o, this, this->scope);
    test_assert(ret == 0);
    ret = corto_observer_unobserve(test_EventTest_onUpdateTree_o, this, this->scope);
    test_assert(ret == 0);

    ret = corto_observer_unobserve(test_EventTest_onDelete_o, this, this->scope);
    test_assert(ret == 0);
    ret = corto_observer_unobserve(test_EventTest_onDeleteSelf_o, this, this->scope);
    test_assert(ret == 0);
    ret = corto_observer_unobserve(test_EventTest_onDeleteScope_o, this, this->scope);
    test_assert(ret == 0);
    ret = corto_observer_unobserve(test_EventTest_onDeleteTree_o, this, this->scope);
    test_assert(ret == 0);

    ret = corto_observer_unobserve(test_EventTest_onUpdateDefine_o, this, this->scope);
    test_assert(ret == 0);
    ret = corto_observer_unobserve(test_EventTest_onUpdateDefineSelf_o, this, this->scope);
    test_assert(ret == 0);
    ret = corto_observer_unobserve(test_EventTest_onUpdateDefineScope_o, this, this->scope);
    test_assert(ret == 0);
    ret = corto_observer_unobserve(test_EventTest_onUpdateDefineTree_o, this, this->scope);
    test_assert(ret == 0);

}

void test_EventTest_onDeclare(
    corto_observerEvent *e)
{
   test_EventTest this = e->instance;
   corto_set_ref(&this->lastThis, e->instance);
   corto_set_ref(&this->lastObservable, e->data);
   this->countDeclare++;
}

void test_EventTest_onDeclareScope(
    corto_observerEvent *e)
{
   test_EventTest this = e->instance;
   corto_set_ref(&this->lastThis, e->instance);
   corto_set_ref(&this->lastObservable, e->data);
   this->countDeclareScope++;
}

void test_EventTest_onDeclareSelf(
    corto_observerEvent *e)
{
   test_EventTest this = e->instance;
   corto_set_ref(&this->lastThis, e->instance);
   corto_set_ref(&this->lastObservable, e->data);
   this->countDeclareSelf++;
}

void test_EventTest_onDeclareTree(
    corto_observerEvent *e)
{
   test_EventTest this = e->instance;
   corto_set_ref(&this->lastThis, e->instance);
   corto_set_ref(&this->lastObservable, e->data);
   this->countDeclareTree++;
}

void test_EventTest_onDefine(
    corto_observerEvent *e)
{
   test_EventTest this = e->instance;
   corto_set_ref(&this->lastThis, e->instance);
   corto_set_ref(&this->lastObservable, e->data);
   this->countDefine++;
}

void test_EventTest_onDefineScope(
    corto_observerEvent *e)
{
   test_EventTest this = e->instance;
   corto_set_ref(&this->lastThis, e->instance);
   corto_set_ref(&this->lastObservable, e->data);
   this->countDefineScope++;
}

void test_EventTest_onDefineSelf(
    corto_observerEvent *e)
{
   test_EventTest this = e->instance;
   corto_set_ref(&this->lastThis, e->instance);
   corto_set_ref(&this->lastObservable, e->data);
   this->countDefineSelf++;
}

void test_EventTest_onDefineTree(
    corto_observerEvent *e)
{
   test_EventTest this = e->instance;
   corto_set_ref(&this->lastThis, e->instance);
   corto_set_ref(&this->lastObservable, e->data);
   this->countDefineTree++;
}

void test_EventTest_onDelete(
    corto_observerEvent *e)
{
   test_EventTest this = e->instance;
   corto_set_ref(&this->lastThis, e->instance);
   corto_set_ref(&this->lastObservable, e->data);
   this->countDelete++;
}

void test_EventTest_onDeleteScope(
    corto_observerEvent *e)
{
   test_EventTest this = e->instance;
   corto_set_ref(&this->lastThis, e->instance);
   corto_set_ref(&this->lastObservable, e->data);
   this->countDeleteScope++;
}

void test_EventTest_onDeleteSelf(
    corto_observerEvent *e)
{
   test_EventTest this = e->instance;
   corto_set_ref(&this->lastThis, e->instance);
   corto_set_ref(&this->lastObservable, e->data);
   this->countDeleteSelf++;
}

void test_EventTest_onDeleteTree(
    corto_observerEvent *e)
{
   test_EventTest this = e->instance;
   corto_set_ref(&this->lastThis, e->instance);
   corto_set_ref(&this->lastObservable, e->data);
   this->countDeleteTree++;
}

void test_EventTest_onUpdate(
    corto_observerEvent *e)
{
   test_EventTest this = e->instance;
   corto_set_ref(&this->lastThis, e->instance);
   corto_set_ref(&this->lastObservable, e->data);
   this->countUpdate++;
}

void test_EventTest_onUpdateDefine(
    corto_observerEvent *e)
{
   test_EventTest this = e->instance;
   corto_set_ref(&this->lastThis, e->instance);
   corto_set_ref(&this->lastObservable, e->data);
   this->countUpdateDefine++;
}

void test_EventTest_onUpdateDefineScope(
    corto_observerEvent *e)
{
   test_EventTest this = e->instance;
   corto_set_ref(&this->lastThis, e->instance);
   corto_set_ref(&this->lastObservable, e->data);
   this->countUpdateDefineScope++;
}

void test_EventTest_onUpdateDefineSelf(
    corto_observerEvent *e)
{
   test_EventTest this = e->instance;
   corto_set_ref(&this->lastThis, e->instance);
   corto_set_ref(&this->lastObservable, e->data);
   this->countUpdateDefineSelf++;
}

void test_EventTest_onUpdateDefineTree(
    corto_observerEvent *e)
{
   test_EventTest this = e->instance;
   corto_set_ref(&this->lastThis, e->instance);
   corto_set_ref(&this->lastObservable, e->data);
   this->countUpdateDefineTree++;
}

void test_EventTest_onUpdateScope(
    corto_observerEvent *e)
{
   test_EventTest this = e->instance;
   corto_set_ref(&this->lastThis, e->instance);
   corto_set_ref(&this->lastObservable, e->data);
   this->countUpdateScope++;
}

void test_EventTest_onUpdateSelf(
    corto_observerEvent *e)
{
   test_EventTest this = e->instance;
   corto_set_ref(&this->lastThis, e->instance);
   corto_set_ref(&this->lastObservable, e->data);
   this->countUpdateSelf++;
}

void test_EventTest_onUpdateTree(
    corto_observerEvent *e)
{
   test_EventTest this = e->instance;
   corto_set_ref(&this->lastThis, e->instance);
   corto_set_ref(&this->lastObservable, e->data);
   this->countUpdateTree++;
}

