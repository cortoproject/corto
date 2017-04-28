/* $CORTO_GENERATED
 *
 * Observers.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <include/test.h>

void _test_Observers_customSignatureObserver(
    test_Observers this,
    corto_eventMask event,
    int32_t *observable,
    corto_observer observer)
{
/* $begin(test/Observers/customSignatureObserver) */
    this->mask = event;
    corto_setref(&this->observable, observable);
    corto_setref(&this->observer, observer);
/* $end */
}

void _test_Observers_setup(
    test_Observers this)
{
/* $begin(test/Observers/setup) */
    test_Observers_customSignatureObserver_o->mask = CORTO_ON_UPDATE;
/* $end */
}

void _test_Observers_tc_customSignatureObserver(
    test_Observers this)
{
/* $begin(test/Observers/tc_customSignatureObserver) */
    corto_object o = corto_create(corto_void_o);
    test_assert(o != NULL);

    test_assert(corto_observer_observe(test_Observers_customSignatureObserver_o, this, o) == 0);

    test_assert(corto_update(o) == 0);
    test_assert(this->mask == CORTO_ON_UPDATE);
    test_assert(this->observable == o);
    test_assert(this->observer == test_Observers_customSignatureObserver_o);

    test_assert(corto_observer_unobserve(test_Observers_customSignatureObserver_o, this, o) == 0);

    test_assert(corto_delete(o) == 0);

/* $end */
}

void _test_Observers_tc_customSignatureObserverMissingEventMask(
    test_Observers this)
{
/* $begin(test/Observers/tc_customSignatureObserverMissingEventMask) */
    corto_object o = corto_createChild(
      root_o,
      "myObserver(int32 event,int32& observable,core/observer observer)",
      corto_observer_o);
    test_assert(o == NULL);
    test_assertstr(
      corto_lasterr(),
      "init for 'myObserver(int32 event,int32& observable,core/observer observer)' of '/corto/core/observer' failed: first argument must be of type core/eventMask"
    );

/* $end */
}

void _test_Observers_tc_customSignatureObserverMissingObserver(
    test_Observers this)
{
/* $begin(test/Observers/tc_customSignatureObserverMissingObserver) */
    corto_object o = corto_createChild(
      root_o,
      "myObserver(core/eventMask event,int32& observable,object observer)",
      corto_observer_o);
    test_assert(o == NULL);
    test_assertstr(
      corto_lasterr(),
      "init for 'myObserver(core/eventMask event,int32& observable,object observer)' of '/corto/core/observer' failed: third argument must be of type core/observer"
    );

/* $end */
}

void _test_Observers_tc_customSignatureObserverObservableNotReference(
    test_Observers this)
{
/* $begin(test/Observers/tc_customSignatureObserverObservableNotReference) */
    corto_object o = corto_createChild(
      root_o,
      "myObserver(core/eventMask event,int32 observable,core/observer observer)",
      corto_observer_o);
    test_assert(o == NULL);
    test_assertstr(
      corto_lasterr(),
      "init for 'myObserver(core/eventMask event,int32 observable,core/observer observer)' of '/corto/core/observer' failed: observer parameter must be of a reference type"
    );

/* $end */
}

void _test_Observers_tc_customSignatureObserverWrongArgumentNumber(
    test_Observers this)
{
/* $begin(test/Observers/tc_customSignatureObserverWrongArgumentNumber) */
    corto_object o = corto_createChild(
      root_o,
      "myObserver(core/eventMask event,int32& observable)",
      corto_observer_o);
    test_assert(o == NULL);
    test_assertstr(
      corto_lasterr(),
      "init for 'myObserver(core/eventMask event,int32& observable)' of '/corto/core/observer' failed: observers must have three arguments"
    );

/* $end */
}

/* $header(test/Observers/tc_dispatchObserver) */
void dispatchObserver_onUpdate(
    corto_object instance,
    corto_eventMask event,
    corto_object observable,
    corto_observer observer)
{
    test_Observers this = instance;

    this->mask = event;
    corto_setref(&this->observable, observable);
    corto_setref(&this->observer, observer);
}
/* $end */
void _test_Observers_tc_dispatchObserver(
    test_Observers this)
{
/* $begin(test/Observers/tc_dispatchObserver) */
    corto_object o = corto_create(corto_void_o);
    test_assert(o != NULL);

    test_ObserverDispatcher d = corto_create(test_ObserverDispatcher_o);
    test_assert(d != NULL);

    test_assert(o != NULL);
    corto_observer observer = corto_observe(CORTO_ON_UPDATE, o)
      .dispatcher(d)
      .instance(this)
      .callback(dispatchObserver_onUpdate);
    test_assert(observer != NULL);

    test_assert(corto_update(o) == 0);

    test_assert(d->called == TRUE);
    test_assert(this->mask == CORTO_ON_UPDATE);
    test_assert(this->observable == o);
    test_assert(this->observer == observer);

    test_assert(corto_delete(observer) == 0);
    test_assert(corto_delete(o) == 0);
    test_assert(corto_delete(d) == 0);

/* $end */
}

/* $header(test/Observers/tc_notifyReadDenied) */
void notifyReadDenied_onUpdate(
    corto_object instance,
    corto_eventMask event,
    corto_object observable,
    corto_observer observer)
{
    test_Observers this = test_Observers(observer->instance);

    this->mask = event;
    corto_setref(&this->observable, observable);
    corto_setref(&this->observer, observer);
    this->count ++;
}
/* $end */
void _test_Observers_tc_notifyReadDenied(
    test_Observers this)
{
/* $begin(test/Observers/tc_notifyReadDenied) */
    test_TestKeyCreate();

    test_TestLock l = test_TestLockCreate("/o", ".", 0, NULL);
    test_AccessRule r = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_DENIED};
    test_AccessRuleListInsert(l->rules, &r);

    corto_object o = corto_createChild(root_o, "o", corto_void_o);
    test_assert(o != NULL);

    corto_observer observer = corto_observe(CORTO_ON_UPDATE, o)
      .instance(this)
      .callback(notifyReadDenied_onUpdate);
    test_assert(observer != NULL);

    /* Login & authenticate Ford Prefect */
    corto_string token = corto_login("Ford Prefect", "42");
    test_assert(token != NULL);
    test_assertstr(token, "token_user01");
    corto_string prev = corto_authenticate(token);
    test_assert(prev == NULL);

    /* Update will succeed because update is authorized */
    test_assert(corto_update(o) == 0);
    test_assert(this->count == 0);

    /* Deauthenticate process */
    corto_authenticate(prev);

    test_assert(corto_delete(observer) == 0);
    test_assert(corto_delete(o) == 0);
    test_assert(corto_delete(l) == 0);

/* $end */
}

void _test_Observers_tc_notifyUpdateDenied(
    test_Observers this)
{
/* $begin(test/Observers/tc_notifyUpdateDenied) */
    test_TestKeyCreate();

    test_TestLock l = test_TestLockCreate("/o", ".", 0, NULL);
    test_AccessRule r = {"token_user01", CORTO_SECURE_ACTION_UPDATE, CORTO_SECURE_ACCESS_DENIED};
    test_AccessRuleListInsert(l->rules, &r);

    corto_object o = corto_createChild(root_o, "o", corto_void_o);
    test_assert(o != NULL);

    corto_observer observer = corto_observe(CORTO_ON_UPDATE, o)
      .callback(NULL);
    test_assert(observer != NULL);

    /* Login & authenticate Ford Prefect */
    corto_string token = corto_login("Ford Prefect", "42");
    test_assert(token != NULL);
    test_assertstr(token, "token_user01");
    corto_string prev = corto_authenticate(token);
    test_assert(prev == NULL);

    /* Update will fail because not authorized */
    test_assert(corto_update(o) != 0);

    /* Deauthenticate process */
    corto_authenticate(prev);

    test_assert(corto_delete(observer) == 0);
    test_assert(corto_delete(o) == 0);
    test_assert(corto_delete(l) == 0);

/* $end */
}

void _test_Observers_tc_notObserving(
    test_Observers this)
{
/* $begin(test/Observers/tc_notObserving) */
    corto_observer observer = corto_observe(CORTO_ON_UPDATE, root_o)
      .callback(NULL);
    test_assert(observer != NULL);

    test_assert(corto_observer_observing(observer, NULL, corto_o) == FALSE);

    test_assert(corto_delete(observer) == 0);

/* $end */
}

void _test_Observers_tc_observeNonScopedObjectWithScopeMaskErr(
    test_Observers this)
{
/* $begin(test/Observers/tc_observeNonScopedObjectWithScopeMaskErr) */
    corto_object o = corto_create(corto_void_o);
    test_assert(o != NULL);

    test_assert(o != NULL);
    corto_observer observer = corto_observe(CORTO_ON_UPDATE | CORTO_ON_SCOPE, o)
      .callback(NULL);
    test_assert(observer == NULL);
    test_assertstr(corto_lasterr(), "invalid nested subscription, observable is not scoped");

    test_assert(corto_delete(o) == 0);

/* $end */
}

void _test_Observers_tc_observerMissingObservable(
    test_Observers this)
{
/* $begin(test/Observers/tc_observerMissingObservable) */

    corto_object o = corto_create(corto_void_o);
    test_assert(o != NULL);

    test_assert(o != NULL);
    corto_observer observer = corto_observe(CORTO_ON_UPDATE, NULL)
      .callback(NULL);
    test_assert(observer == NULL);
    test_assertstr(corto_lasterr(), "no observable provided for observer");

    test_assert(corto_delete(o) == 0);

/* $end */
}

/* $header(test/Observers/tc_observeTypeFilter) */
void observeTypeFilter_onUpdate(
    corto_object instance,
    corto_eventMask event,
    corto_object observable,
    corto_observer observer)
{
    test_Observers this = instance;

    this->mask = event;
    corto_setref(&this->observable, observable);
    corto_setref(&this->observer, observer);
}
/* $end */
void _test_Observers_tc_observeTypeFilter(
    test_Observers this)
{
/* $begin(test/Observers/tc_observeTypeFilter) */
    corto_object testRoot = corto_createChild(root_o, "testRoot", corto_void_o);
    test_assert(testRoot != NULL);

    corto_object o1 = corto_createChild(testRoot, "o1", corto_float32_o);
    test_assert(o1 != NULL);

    corto_object o2 = corto_createChild(testRoot, "o2", corto_int32_o);
    test_assert(o2 != NULL);

    corto_observer observer = corto_observe(CORTO_ON_UPDATE|CORTO_ON_SCOPE, testRoot)
      .type("int32")
      .instance(this)
      .callback(observeTypeFilter_onUpdate);
    test_assert(observer != NULL);

    test_assert(corto_update(o1) == 0);
    test_assert(this->mask == 0);
    test_assert(this->observable == NULL);
    test_assert(this->observer == NULL);

    test_assert(corto_update(o2) == 0);
    test_assert(this->mask == CORTO_ON_UPDATE);
    test_assert(this->observable == o2);
    test_assert(this->observer == observer);

    test_assert(corto_delete(testRoot) == 0);
    test_assert(corto_delete(observer) == 0);

/* $end */
}

void _test_Observers_tc_observeTypeFilterNotAType(
    test_Observers this)
{
/* $begin(test/Observers/tc_observeTypeFilterNotAType) */

    corto_observer observer = corto_observe(CORTO_ON_UPDATE|CORTO_ON_SCOPE, root_o)
      .type("/corto")
      .callback(NULL);
    test_assert(observer == NULL);
    test_assertstr(corto_lasterr(), "'/corto' is not a type");

/* $end */
}

void _test_Observers_tc_observeTypeFilterUnresolved(
    test_Observers this)
{
/* $begin(test/Observers/tc_observeTypeFilterUnresolved) */

    corto_observer observer = corto_observe(CORTO_ON_UPDATE|CORTO_ON_SCOPE, root_o)
      .type("/doesnotexist")
      .callback(NULL);
    test_assert(observer == NULL);
    test_assertstr(corto_lasterr(), "unresolved type '/doesnotexist'");

/* $end */
}

/* $header(test/Observers/tc_observeWithMultipleInstances) */
void observeWithMultipleInstances_onUpdate(
    corto_object instance,
    corto_eventMask event,
    corto_object observable,
    corto_observer observer)
{
    test_Observers this = test_Observers(observer->instance);

    this->mask = event;
    corto_setref(&this->observable, observable);
    corto_setref(&this->observer, observer);
    this->count ++;
}
/* $end */
void _test_Observers_tc_observeWithMultipleInstances(
    test_Observers this)
{
/* $begin(test/Observers/tc_observeWithMultipleInstances) */
    corto_object o = corto_create(corto_void_o);
    corto_object instance1 = corto_create(corto_void_o);
    corto_object instance2 = corto_create(corto_void_o);

    corto_observer observer = corto_observe(CORTO_ON_UPDATE, o)
      .instance(this) // Callback can access this through observer object
      .disabled()
      .callback(observeWithMultipleInstances_onUpdate);
    test_assert(observer != NULL);
    test_assert(observer->instance == this);

    test_assert(corto_observer_observe(observer, instance1, o) == 0);
    test_assert(corto_observer_observe(observer, instance2, o) == 0);

    test_assert(corto_update(o) == 0);
    test_assert(this->count == 2);
    test_assert(this->mask == CORTO_ON_UPDATE);
    test_assert(this->observable == o);
    test_assert(this->observer == observer);

    test_assert(corto_observer_unobserve(observer, instance1, o) == 0);
    test_assert(corto_observer_unobserve(observer, instance2, o) == 0);

    test_assert(corto_delete(observer) == 0);
    test_assert(corto_delete(instance1) == 0);
    test_assert(corto_delete(instance2) == 0);
    test_assert(corto_delete(o) == 0);

/* $end */
}

void _test_Observers_tc_observing(
    test_Observers this)
{
/* $begin(test/Observers/tc_observing) */
    corto_observer observer = corto_observe(CORTO_ON_UPDATE, root_o)
      .callback(NULL);
    test_assert(observer != NULL);

    test_assert(corto_observer_observing(observer, NULL, root_o) == TRUE);

    test_assert(corto_delete(observer) == 0);

/* $end */
}

void _test_Observers_tc_observingDisabled(
    test_Observers this)
{
/* $begin(test/Observers/tc_observingDisabled) */
    corto_observer observer = corto_observe(CORTO_ON_UPDATE, root_o)
      .disabled()
      .callback(NULL);
    test_assert(observer != NULL);

    test_assert(corto_observer_observing(observer, NULL, root_o) == FALSE);

    test_assert(corto_delete(observer) == 0);

/* $end */
}

void _test_Observers_tc_observingMultipleInstances(
    test_Observers this)
{
/* $begin(test/Observers/tc_observingMultipleInstances) */
    corto_object instance1 = corto_create(corto_void_o);
    corto_object instance2 = corto_create(corto_void_o);

    corto_observer observer = corto_observe(CORTO_ON_UPDATE, root_o)
      .disabled()
      .callback(NULL);
    test_assert(observer != NULL);

    test_assert(corto_observer_observing(observer, NULL, root_o) == FALSE);

    test_assert(corto_observer_observe(observer, instance1, root_o) == 0);
    test_assert(corto_observer_observe(observer, instance2, root_o) == 0);

    test_assert(corto_observer_observing(observer, instance1, root_o) == TRUE);
    test_assert(corto_observer_observing(observer, instance2, root_o) == TRUE);
    test_assert(corto_observer_observing(observer, NULL, root_o) == FALSE);

    test_assert(corto_observer_unobserve(observer, instance1, root_o) == 0);
    test_assert(corto_observer_unobserve(observer, instance2, root_o) == 0);

    test_assert(corto_delete(observer) == 0);
    test_assert(corto_delete(instance1) == 0);
    test_assert(corto_delete(instance2) == 0);

/* $end */
}

void _test_Observers_tc_observingScope(
    test_Observers this)
{
/* $begin(test/Observers/tc_observingScope) */
    corto_observer observer = corto_observe(CORTO_ON_UPDATE|CORTO_ON_SCOPE, root_o)
      .callback(NULL);
    test_assert(observer != NULL);

    test_assert(corto_observer_observing(observer, NULL, root_o) == TRUE);

    test_assert(corto_delete(observer) == 0);

/* $end */
}

void _test_Observers_tc_observingSingleInstance(
    test_Observers this)
{
/* $begin(test/Observers/tc_observingSingleInstance) */
    corto_object instance = corto_create(corto_void_o);

    corto_observer observer = corto_observe(CORTO_ON_UPDATE, root_o)
      .instance(instance)
      .callback(NULL);
    test_assert(observer != NULL);

    test_assert(corto_observer_observing(observer, instance, root_o));

    test_assert(corto_delete(observer) == 0);
    test_assert(corto_delete(instance) == 0);

/* $end */
}

void _test_Observers_tc_observingTree(
    test_Observers this)
{
/* $begin(test/Observers/tc_observingTree) */
    corto_observer observer = corto_observe(CORTO_ON_UPDATE|CORTO_ON_TREE, root_o)
      .callback(NULL);
    test_assert(observer != NULL);

    test_assert(corto_observer_observing(observer, NULL, root_o) == TRUE);

    test_assert(corto_delete(observer) == 0);

/* $end */
}
