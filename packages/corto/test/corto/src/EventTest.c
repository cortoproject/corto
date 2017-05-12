/* $CORTO_GENERATED
 *
 * EventTest.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <include/test.h>

int16_t _test_EventTest_construct(
    test_EventTest this)
{
/* $begin(test/EventTest/construct) */
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
/* $end */
}

void _test_EventTest_destruct(
    test_EventTest this)
{
/* $begin(test/EventTest/destruct) */
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

/* $end */
}

void _test_EventTest_onDeclare(
    corto_observerEvent *e)
{
/* $begin(test/EventTest/onDeclare) */
   test_EventTest this = e->instance;
   corto_ptr_setref(&this->lastThis, e->instance);
   corto_ptr_setref(&this->lastObservable, e->data);
   this->countDeclare++;
/* $end */
}

void _test_EventTest_onDeclareScope(
    corto_observerEvent *e)
{
/* $begin(test/EventTest/onDeclareScope) */
   test_EventTest this = e->instance;
   corto_ptr_setref(&this->lastThis, e->instance);
   corto_ptr_setref(&this->lastObservable, e->data);
   this->countDeclareScope++;
/* $end */
}

void _test_EventTest_onDeclareSelf(
    corto_observerEvent *e)
{
/* $begin(test/EventTest/onDeclareSelf) */
   test_EventTest this = e->instance;
   corto_ptr_setref(&this->lastThis, e->instance);
   corto_ptr_setref(&this->lastObservable, e->data);
   this->countDeclareSelf++;
/* $end */
}

void _test_EventTest_onDeclareTree(
    corto_observerEvent *e)
{
/* $begin(test/EventTest/onDeclareTree) */
   test_EventTest this = e->instance;
   corto_ptr_setref(&this->lastThis, e->instance);
   corto_ptr_setref(&this->lastObservable, e->data);
   this->countDeclareTree++;
/* $end */
}

void _test_EventTest_onDefine(
    corto_observerEvent *e)
{
/* $begin(test/EventTest/onDefine) */
   test_EventTest this = e->instance;
   corto_ptr_setref(&this->lastThis, e->instance);
   corto_ptr_setref(&this->lastObservable, e->data);
   this->countDefine++;
/* $end */
}

void _test_EventTest_onDefineScope(
    corto_observerEvent *e)
{
/* $begin(test/EventTest/onDefineScope) */
   test_EventTest this = e->instance;
   corto_ptr_setref(&this->lastThis, e->instance);
   corto_ptr_setref(&this->lastObservable, e->data);
   this->countDefineScope++;
/* $end */
}

void _test_EventTest_onDefineSelf(
    corto_observerEvent *e)
{
/* $begin(test/EventTest/onDefineSelf) */
   test_EventTest this = e->instance;
   corto_ptr_setref(&this->lastThis, e->instance);
   corto_ptr_setref(&this->lastObservable, e->data);
   this->countDefineSelf++;
/* $end */
}

void _test_EventTest_onDefineTree(
    corto_observerEvent *e)
{
/* $begin(test/EventTest/onDefineTree) */
   test_EventTest this = e->instance;
   corto_ptr_setref(&this->lastThis, e->instance);
   corto_ptr_setref(&this->lastObservable, e->data);
   this->countDefineTree++;
/* $end */
}

void _test_EventTest_onDelete(
    corto_observerEvent *e)
{
/* $begin(test/EventTest/onDelete) */
   test_EventTest this = e->instance;
   corto_ptr_setref(&this->lastThis, e->instance);
   corto_ptr_setref(&this->lastObservable, e->data);
   this->countDelete++;
/* $end */
}

void _test_EventTest_onDeleteScope(
    corto_observerEvent *e)
{
/* $begin(test/EventTest/onDeleteScope) */
   test_EventTest this = e->instance;
   corto_ptr_setref(&this->lastThis, e->instance);
   corto_ptr_setref(&this->lastObservable, e->data);
   this->countDeleteScope++;
/* $end */
}

void _test_EventTest_onDeleteSelf(
    corto_observerEvent *e)
{
/* $begin(test/EventTest/onDeleteSelf) */
   test_EventTest this = e->instance;
   corto_ptr_setref(&this->lastThis, e->instance);
   corto_ptr_setref(&this->lastObservable, e->data);
   this->countDeleteSelf++;
/* $end */
}

void _test_EventTest_onDeleteTree(
    corto_observerEvent *e)
{
/* $begin(test/EventTest/onDeleteTree) */
   test_EventTest this = e->instance;
   corto_ptr_setref(&this->lastThis, e->instance);
   corto_ptr_setref(&this->lastObservable, e->data);
   this->countDeleteTree++;
/* $end */
}

void _test_EventTest_onUpdate(
    corto_observerEvent *e)
{
/* $begin(test/EventTest/onUpdate) */
   test_EventTest this = e->instance;
   corto_ptr_setref(&this->lastThis, e->instance);
   corto_ptr_setref(&this->lastObservable, e->data);
   this->countUpdate++;
/* $end */
}

void _test_EventTest_onUpdateDefine(
    corto_observerEvent *e)
{
/* $begin(test/EventTest/onUpdateDefine) */
   test_EventTest this = e->instance;
   corto_ptr_setref(&this->lastThis, e->instance);
   corto_ptr_setref(&this->lastObservable, e->data);
   this->countUpdateDefine++;
/* $end */
}

void _test_EventTest_onUpdateDefineScope(
    corto_observerEvent *e)
{
/* $begin(test/EventTest/onUpdateDefineScope) */
   test_EventTest this = e->instance;
   corto_ptr_setref(&this->lastThis, e->instance);
   corto_ptr_setref(&this->lastObservable, e->data);
   this->countUpdateDefineScope++;
/* $end */
}

void _test_EventTest_onUpdateDefineSelf(
    corto_observerEvent *e)
{
/* $begin(test/EventTest/onUpdateDefineSelf) */
   test_EventTest this = e->instance;
   corto_ptr_setref(&this->lastThis, e->instance);
   corto_ptr_setref(&this->lastObservable, e->data);
   this->countUpdateDefineSelf++;
/* $end */
}

void _test_EventTest_onUpdateDefineTree(
    corto_observerEvent *e)
{
/* $begin(test/EventTest/onUpdateDefineTree) */
   test_EventTest this = e->instance;
   corto_ptr_setref(&this->lastThis, e->instance);
   corto_ptr_setref(&this->lastObservable, e->data);
   this->countUpdateDefineTree++;
/* $end */
}

void _test_EventTest_onUpdateScope(
    corto_observerEvent *e)
{
/* $begin(test/EventTest/onUpdateScope) */
   test_EventTest this = e->instance;
   corto_ptr_setref(&this->lastThis, e->instance);
   corto_ptr_setref(&this->lastObservable, e->data);
   this->countUpdateScope++;
/* $end */
}

void _test_EventTest_onUpdateSelf(
    corto_observerEvent *e)
{
/* $begin(test/EventTest/onUpdateSelf) */
   test_EventTest this = e->instance;
   corto_ptr_setref(&this->lastThis, e->instance);
   corto_ptr_setref(&this->lastObservable, e->data);
   this->countUpdateSelf++;
/* $end */
}

void _test_EventTest_onUpdateTree(
    corto_observerEvent *e)
{
/* $begin(test/EventTest/onUpdateTree) */
   test_EventTest this = e->instance;
   corto_ptr_setref(&this->lastThis, e->instance);
   corto_ptr_setref(&this->lastObservable, e->data);
   this->countUpdateTree++;
/* $end */
}
