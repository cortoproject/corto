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
    test_EventTest this,
    corto_eventMask event,
    corto_object object,
    corto_observer observer)
{
/* $begin(test/EventTest/onDeclare) */
   corto_setref(&this->lastThis, this);
   corto_setref(&this->lastObservable, object);
   this->countDeclare++;
/* $end */
}

void _test_EventTest_onDeclareScope(
    test_EventTest this,
    corto_eventMask event,
    corto_object object,
    corto_observer observer)
{
/* $begin(test/EventTest/onDeclareScope) */
   corto_setref(&this->lastThis, this);
   corto_setref(&this->lastObservable, object);
   this->countDeclareScope++;
/* $end */
}

void _test_EventTest_onDeclareSelf(
    test_EventTest this,
    corto_eventMask event,
    corto_object object,
    corto_observer observer)
{
/* $begin(test/EventTest/onDeclareSelf) */
   corto_setref(&this->lastThis, this);
   corto_setref(&this->lastObservable, object);
   this->countDeclareSelf++;
/* $end */
}

void _test_EventTest_onDeclareTree(
    test_EventTest this,
    corto_eventMask event,
    corto_object object,
    corto_observer observer)
{
/* $begin(test/EventTest/onDeclareTree) */
   corto_setref(&this->lastThis, this);
   corto_setref(&this->lastObservable, object);
   this->countDeclareTree++;
/* $end */
}

void _test_EventTest_onDefine(
    test_EventTest this,
    corto_eventMask event,
    corto_object object,
    corto_observer observer)
{
/* $begin(test/EventTest/onDefine) */
   corto_setref(&this->lastThis, this);
   corto_setref(&this->lastObservable, object);
   this->countDefine++;
/* $end */
}

void _test_EventTest_onDefineScope(
    test_EventTest this,
    corto_eventMask event,
    corto_object object,
    corto_observer observer)
{
/* $begin(test/EventTest/onDefineScope) */
   corto_setref(&this->lastThis, this);
   corto_setref(&this->lastObservable, object);
   this->countDefineScope++;
/* $end */
}

void _test_EventTest_onDefineSelf(
    test_EventTest this,
    corto_eventMask event,
    corto_object object,
    corto_observer observer)
{
/* $begin(test/EventTest/onDefineSelf) */
   corto_setref(&this->lastThis, this);
   corto_setref(&this->lastObservable, object);
   this->countDefineSelf++;
/* $end */
}

void _test_EventTest_onDefineTree(
    test_EventTest this,
    corto_eventMask event,
    corto_object object,
    corto_observer observer)
{
/* $begin(test/EventTest/onDefineTree) */
   corto_setref(&this->lastThis, this);
   corto_setref(&this->lastObservable, object);
   this->countDefineTree++;
/* $end */
}

void _test_EventTest_onDelete(
    test_EventTest this,
    corto_eventMask event,
    corto_object object,
    corto_observer observer)
{
/* $begin(test/EventTest/onDelete) */
   corto_setref(&this->lastThis, this);
   corto_setref(&this->lastObservable, object);
   this->countDelete++;
/* $end */
}

void _test_EventTest_onDeleteScope(
    test_EventTest this,
    corto_eventMask event,
    corto_object object,
    corto_observer observer)
{
/* $begin(test/EventTest/onDeleteScope) */
   corto_setref(&this->lastThis, this);
   corto_setref(&this->lastObservable, object);
   this->countDeleteScope++;
/* $end */
}

void _test_EventTest_onDeleteSelf(
    test_EventTest this,
    corto_eventMask event,
    corto_object object,
    corto_observer observer)
{
/* $begin(test/EventTest/onDeleteSelf) */
   corto_setref(&this->lastThis, this);
   corto_setref(&this->lastObservable, object);
   this->countDeleteSelf++;
/* $end */
}

void _test_EventTest_onDeleteTree(
    test_EventTest this,
    corto_eventMask event,
    corto_object object,
    corto_observer observer)
{
/* $begin(test/EventTest/onDeleteTree) */
   corto_setref(&this->lastThis, this);
   corto_setref(&this->lastObservable, object);
   this->countDeleteTree++;
/* $end */
}

void _test_EventTest_onUpdate(
    test_EventTest this,
    corto_eventMask event,
    corto_object object,
    corto_observer observer)
{
/* $begin(test/EventTest/onUpdate) */
   corto_setref(&this->lastThis, this);
   corto_setref(&this->lastObservable, object);
   this->countUpdate++;
/* $end */
}

void _test_EventTest_onUpdateDefine(
    test_EventTest this,
    corto_eventMask event,
    corto_object object,
    corto_observer observer)
{
/* $begin(test/EventTest/onUpdateDefine) */
   corto_setref(&this->lastThis, this);
   corto_setref(&this->lastObservable, object);
   this->countUpdateDefine++;
/* $end */
}

void _test_EventTest_onUpdateDefineScope(
    test_EventTest this,
    corto_eventMask event,
    corto_object object,
    corto_observer observer)
{
/* $begin(test/EventTest/onUpdateDefineScope) */
   corto_setref(&this->lastThis, this);
   corto_setref(&this->lastObservable, object);
   this->countUpdateDefineScope++;
/* $end */
}

void _test_EventTest_onUpdateDefineSelf(
    test_EventTest this,
    corto_eventMask event,
    corto_object object,
    corto_observer observer)
{
/* $begin(test/EventTest/onUpdateDefineSelf) */
   corto_setref(&this->lastThis, this);
   corto_setref(&this->lastObservable, object);
   this->countUpdateDefineSelf++;
/* $end */
}

void _test_EventTest_onUpdateDefineTree(
    test_EventTest this,
    corto_eventMask event,
    corto_object object,
    corto_observer observer)
{
/* $begin(test/EventTest/onUpdateDefineTree) */
   corto_setref(&this->lastThis, this);
   corto_setref(&this->lastObservable, object);
   this->countUpdateDefineTree++;
/* $end */
}

void _test_EventTest_onUpdateScope(
    test_EventTest this,
    corto_eventMask event,
    corto_object object,
    corto_observer observer)
{
/* $begin(test/EventTest/onUpdateScope) */
   corto_setref(&this->lastThis, this);
   corto_setref(&this->lastObservable, object);
   this->countUpdateScope++;
/* $end */
}

void _test_EventTest_onUpdateSelf(
    test_EventTest this,
    corto_eventMask event,
    corto_object object,
    corto_observer observer)
{
/* $begin(test/EventTest/onUpdateSelf) */
   corto_setref(&this->lastThis, this);
   corto_setref(&this->lastObservable, object);
   this->countUpdateSelf++;
/* $end */
}

void _test_EventTest_onUpdateTree(
    test_EventTest this,
    corto_eventMask event,
    corto_object object,
    corto_observer observer)
{
/* $begin(test/EventTest/onUpdateTree) */
   corto_setref(&this->lastThis, this);
   corto_setref(&this->lastObservable, object);
   this->countUpdateTree++;
/* $end */
}
