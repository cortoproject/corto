/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

void test_Observers_setup(
    test_Observers this)
{

}


void dispatchObserver_onUpdate(
    corto_observerEvent *e)
{
    test_Observers this = e->instance;
    this->mask = e->event;
    corto_ptr_setref(&this->observable, e->data);
    corto_ptr_setref(&this->observer, e->observer);
}

void test_Observers_tc_dispatchObserver(
    test_Observers this)
{
    corto_object o = corto_create(corto_void_o);
    test_assert(o != NULL);

    test_ObserverDispatcher d = corto_create(test_ObserverDispatcher_o);
    test_assert(d != NULL);

    test_assert(o != NULL);
    corto_observer observer = corto_observe(CORTO_UPDATE, o)
      .dispatcher(d)
      .instance(this)
      .callback(dispatchObserver_onUpdate);
    test_assert(observer != NULL);

    test_assert(corto_update(o) == 0);

    test_assert(d->called == TRUE);
    test_assert(this->mask == CORTO_UPDATE);
    test_assert(this->observable == o);
    test_assert(this->observer == observer);

    test_assert(corto_delete(observer) == 0);
    test_assert(corto_delete(o) == 0);
    test_assert(corto_delete(d) == 0);

}


void notifyReadDenied_onUpdate(corto_observerEvent *e)
{
    test_Observers this = e->instance;
    this->mask = e->event;
    corto_ptr_setref(&this->observable, e->data);
    corto_ptr_setref(&this->observer, e->observer);
    this->count ++;
}

void test_Observers_tc_notifyReadDenied(
    test_Observers this)
{
    test_TestKeyCreate();

    test_TestLock l = test_TestLockCreate("/o", ".", 0, NULL);
    test_AccessRule r = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_DENIED};
    test_AccessRuleListInsert(l->rules, &r);

    corto_object o = corto_createChild(root_o, "o", corto_void_o);
    test_assert(o != NULL);

    corto_observer observer = corto_observe(CORTO_UPDATE, o)
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

}

void test_Observers_tc_notifyUpdateDenied(
    test_Observers this)
{
    test_TestKeyCreate();

    test_TestLock l = test_TestLockCreate("/o", ".", 0, NULL);
    test_AccessRule r = {"token_user01", CORTO_SECURE_ACTION_UPDATE, CORTO_SECURE_ACCESS_DENIED};
    test_AccessRuleListInsert(l->rules, &r);

    corto_object o = corto_createChild(root_o, "o", corto_void_o);
    test_assert(o != NULL);

    corto_observer observer = corto_observe(CORTO_UPDATE, o)
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

}

void test_Observers_tc_notObserving(
    test_Observers this)
{
    corto_observer observer = corto_observe(CORTO_UPDATE, root_o)
      .callback(NULL);
    test_assert(observer != NULL);

    test_assert(corto_observer_observing(observer, NULL, corto_o) == FALSE);

    test_assert(corto_delete(observer) == 0);

}


void tc_observeAlignCallbackSelf(corto_observerEvent *e) {
    test_assert(e->data != NULL);
    test_assertstr(corto_idof(e->data), "o");
    test_assert(e->event == CORTO_DEFINE);
}

void test_Observers_tc_observeAlignSelf(
    test_Observers this)
{
    corto_object o = corto_createChild(root_o, "o", corto_void_o);

    corto_observer observer = corto_observe(CORTO_DEFINE|CORTO_INVALIDATE, o)
      .callback(tc_observeAlignCallbackSelf);
    test_assert(observer != NULL);

    test_assert(corto_delete(observer) == 0);
    test_assert(corto_delete(o) == 0);

}


void tc_observeAlignCallbackType(corto_observerEvent *e) {
    test_Observers this = e->instance;
    test_assert(e->data != NULL);
    test_assertstr(corto_idof(e->data), "p");
    test_assert(e->event == CORTO_DEFINE);
    corto_ptr_setref(&this->observable, e->data);
}

void test_Observers_tc_observeAlignType(
    test_Observers this)
{
    corto_object o = corto_createChild(root_o, "o", corto_int32_o);
    corto_object p = corto_createChild(root_o, "p", corto_float32_o);
    corto_object q = corto_createChild(root_o, "q", corto_string_o);

    corto_observer observer = corto_observe(CORTO_DEFINE|CORTO_ON_SCOPE, root_o)
      .type("float32")
      .instance(this)
      .callback(tc_observeAlignCallbackType);
    test_assert(observer != NULL);

    test_assert(this->observable == p);

    test_assert(corto_delete(observer) == 0);
    test_assert(corto_delete(o) == 0);
    test_assert(corto_delete(p) == 0);
    test_assert(corto_delete(q) == 0);

}

void test_Observers_tc_observeNonScopedObjectWithScopeMaskErr(
    test_Observers this)
{
    corto_object o = corto_create(corto_void_o);
    test_assert(o != NULL);

    test_assert(o != NULL);
    corto_observer observer = corto_observe(CORTO_UPDATE | CORTO_ON_SCOPE, o)
      .callback(NULL);
    test_assert(observer == NULL);
    test_assertstr(corto_lasterr(), "invalid nested subscription, observable is not scoped");

    test_assert(corto_delete(o) == 0);

}

void test_Observers_tc_observerMissingObservable(
    test_Observers this)
{

    corto_object o = corto_create(corto_void_o);
    test_assert(o != NULL);

    test_assert(o != NULL);
    corto_observer observer = corto_observe(CORTO_UPDATE, NULL)
      .callback(NULL);
    test_assert(observer == NULL);
    test_assertstr(corto_lasterr(), "no observable provided for observer");

    test_assert(corto_delete(o) == 0);

}


void observeTypeFilter_onUpdate(corto_observerEvent *e)
{
    test_Observers this = e->instance;
    this->mask = e->event;
    corto_ptr_setref(&this->observable, e->data);
    corto_ptr_setref(&this->observer, e->observer);
}

void test_Observers_tc_observeTypeFilter(
    test_Observers this)
{
    corto_object testRoot = corto_createChild(root_o, "testRoot", corto_void_o);
    test_assert(testRoot != NULL);

    corto_object o1 = corto_createChild(testRoot, "o1", corto_float32_o);
    test_assert(o1 != NULL);

    corto_object o2 = corto_createChild(testRoot, "o2", corto_int32_o);
    test_assert(o2 != NULL);

    corto_observer observer = corto_observe(CORTO_UPDATE|CORTO_ON_SCOPE, testRoot)
      .type("int32")
      .instance(this)
      .callback(observeTypeFilter_onUpdate);
    test_assert(observer != NULL);

    test_assert(corto_update(o1) == 0);
    test_assert(this->mask == 0);
    test_assert(this->observable == NULL);
    test_assert(this->observer == NULL);

    test_assert(corto_update(o2) == 0);
    test_assert(this->mask == CORTO_UPDATE);
    test_assert(this->observable == o2);
    test_assert(this->observer == observer);

    test_assert(corto_delete(testRoot) == 0);
    test_assert(corto_delete(observer) == 0);

}

void test_Observers_tc_observeTypeFilterNotAType(
    test_Observers this)
{

    corto_observer observer = corto_observe(CORTO_UPDATE|CORTO_ON_SCOPE, root_o)
      .type("/corto")
      .callback(NULL);
    test_assert(observer == NULL);
    test_assertstr(corto_lasterr(), "'/corto' is not a type");

}

void test_Observers_tc_observeTypeFilterUnresolved(
    test_Observers this)
{

    corto_observer observer = corto_observe(CORTO_UPDATE|CORTO_ON_SCOPE, root_o)
      .type("/doesnotexist")
      .callback(NULL);
    test_assert(observer == NULL);
    test_assertstr(corto_lasterr(), "unresolved type '/doesnotexist'");

}


void observeWithMultipleInstances_onUpdate(
    corto_observerEvent *e)
{
    test_Observers this = corto_observer(e->observer)->instance;
    this->mask = e->event;
    corto_ptr_setref(&this->observable, e->data);
    corto_ptr_setref(&this->observer, e->observer);
    this->count ++;
}

void test_Observers_tc_observeWithMultipleInstances(
    test_Observers this)
{
    corto_object o = corto_create(corto_void_o);
    corto_object instance1 = corto_create(corto_void_o);
    corto_object instance2 = corto_create(corto_void_o);

    corto_observer observer = corto_observe(CORTO_UPDATE, o)
      .instance(this) // Callback can access this through observer object
      .disabled()
      .callback(observeWithMultipleInstances_onUpdate);
    test_assert(observer != NULL);
    test_assert(observer->instance == this);

    test_assert(corto_observer_observe(observer, instance1, o) == 0);
    test_assert(corto_observer_observe(observer, instance2, o) == 0);

    test_assert(corto_update(o) == 0);
    test_assert(this->count == 2);
    test_assert(this->mask == CORTO_UPDATE);
    test_assert(this->observable == o);
    test_assert(this->observer == observer);

    test_assert(corto_observer_unobserve(observer, instance1, o) == 0);
    test_assert(corto_observer_unobserve(observer, instance2, o) == 0);

    test_assert(corto_delete(observer) == 0);
    test_assert(corto_delete(instance1) == 0);
    test_assert(corto_delete(instance2) == 0);
    test_assert(corto_delete(o) == 0);

}

void test_Observers_tc_observing(
    test_Observers this)
{
    corto_observer observer = corto_observe(CORTO_UPDATE, root_o)
      .callback(NULL);
    test_assert(observer != NULL);

    test_assert(corto_observer_observing(observer, NULL, root_o) == TRUE);

    test_assert(corto_delete(observer) == 0);

}

void test_Observers_tc_observingDisabled(
    test_Observers this)
{
    corto_observer observer = corto_observe(CORTO_UPDATE, root_o)
      .disabled()
      .callback(NULL);
    test_assert(observer != NULL);

    test_assert(corto_observer_observing(observer, NULL, root_o) == FALSE);

    test_assert(corto_delete(observer) == 0);

}

void test_Observers_tc_observingMultipleInstances(
    test_Observers this)
{
    corto_object instance1 = corto_create(corto_void_o);
    corto_object instance2 = corto_create(corto_void_o);

    corto_observer observer = corto_observe(CORTO_UPDATE, root_o)
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

}

void test_Observers_tc_observingScope(
    test_Observers this)
{
    corto_observer observer = corto_observe(CORTO_UPDATE|CORTO_ON_SCOPE, root_o)
      .callback(NULL);
    test_assert(observer != NULL);

    test_assert(corto_observer_observing(observer, NULL, root_o) == TRUE);

    test_assert(corto_delete(observer) == 0);

}

void test_Observers_tc_observingSingleInstance(
    test_Observers this)
{
    corto_object instance = corto_create(corto_void_o);

    corto_observer observer = corto_observe(CORTO_UPDATE, root_o)
      .instance(instance)
      .callback(NULL);
    test_assert(observer != NULL);

    test_assert(corto_observer_observing(observer, instance, root_o));

    test_assert(corto_delete(observer) == 0);
    test_assert(corto_delete(instance) == 0);

}

void test_Observers_tc_observingTree(
    test_Observers this)
{
    corto_observer observer = corto_observe(CORTO_UPDATE|CORTO_ON_TREE, root_o)
      .callback(NULL);
    test_assert(observer != NULL);

    test_assert(corto_observer_observing(observer, NULL, root_o) == TRUE);

    test_assert(corto_delete(observer) == 0);

}

