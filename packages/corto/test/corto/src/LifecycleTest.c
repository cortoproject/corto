/* This is a managed file. Do not delete this comment. */

#include <include/test.h>
int16_t test_LifecycleTest_construct(
    test_LifecycleTest this)
{
    test_assert(this->admin != NULL);    
    test_assert(corto_stateof(this) == CORTO_DECLARED);
    test_assertint(this->admin->hooksCalled, TEST_INIT_CALLED);
    this->admin->hooksCalled |= TEST_CONSTRUCT_CALLED;
    return this->constructFail;
}

void test_LifecycleTest_define(
    test_LifecycleTest this)
{
    test_assert(this->admin != NULL);        
    test_assert(corto_stateof(this) == (CORTO_DECLARED|CORTO_VALID|CORTO_DEFINED));   
    test_assertint(this->admin->hooksCalled, TEST_INIT_CALLED|TEST_CONSTRUCT_CALLED);    
    this->admin->hooksCalled |= TEST_DEFINE_CALLED;
}

void test_LifecycleTest_delete(
    test_LifecycleTest this)
{
    test_assert(this->admin != NULL);
    test_assertint(corto_stateof(this), (CORTO_DECLARED|CORTO_VALID|CORTO_DESTRUCTED));
    test_assertint(this->admin->hooksCalled, 
        TEST_INIT_CALLED|TEST_CONSTRUCT_CALLED|TEST_DEFINE_CALLED|
        TEST_VALIDATE_CALLED|TEST_UPDATE_CALLED|TEST_DESTRUCT_CALLED);    
    
    this->admin->hooksCalled |= TEST_DELETE_CALLED;
}

void test_LifecycleTest_destruct(
    test_LifecycleTest this)
{
    test_assert(this->admin != NULL);
    test_assert(corto_stateof(this) == (CORTO_DECLARED|CORTO_VALID|CORTO_DEFINED));
    test_assertint(this->admin->hooksCalled, 
        TEST_INIT_CALLED|TEST_CONSTRUCT_CALLED|TEST_DEFINE_CALLED|TEST_VALIDATE_CALLED|TEST_UPDATE_CALLED);   
    
    this->admin->hooksCalled |= TEST_DESTRUCT_CALLED;
}

int16_t test_LifecycleTest_init(
    test_LifecycleTest this)
{
    test_assert(!this->admin);
    this->admin = corto_create(test_LifecycleAdmin_o);
    test_assert(corto_stateof(this) == CORTO_DECLARED);
    test_assertint(this->admin->hooksCalled, 0);    
    
    this->admin->hooksCalled |= TEST_INIT_CALLED;
    return !strcmp(corto_idof(this), "fail");
}

void test_LifecycleTest_update(
    test_LifecycleTest this)
{
    test_assert(this->admin != NULL);
    test_assert(corto_stateof(this) == (CORTO_DECLARED|CORTO_VALID|CORTO_DEFINED));
    test_assertint(this->admin->hooksCalled, 
        TEST_INIT_CALLED|TEST_CONSTRUCT_CALLED|TEST_DEFINE_CALLED|TEST_VALIDATE_CALLED);    

    this->admin->hooksCalled |= TEST_UPDATE_CALLED;
}

int16_t test_LifecycleTest_validate(
    test_LifecycleTest this)
{
    test_assert(this->admin != NULL);
    test_assertint(corto_stateof(this), (CORTO_DECLARED|CORTO_VALID|CORTO_DEFINED));
    test_assertint(this->admin->hooksCalled, 
        TEST_INIT_CALLED|TEST_CONSTRUCT_CALLED|TEST_DEFINE_CALLED);      

    this->admin->hooksCalled |= TEST_VALIDATE_CALLED;
    return this->validateFail;
}

void test_LifecycleTest_deinit(
    test_LifecycleTest this)
{
    test_assert(this->admin != NULL);    
    test_assert(corto_stateof(this) == (CORTO_DECLARED|CORTO_VALID|CORTO_DESTRUCTED));    
    test_assertint(this->admin->hooksCalled, 
        TEST_INIT_CALLED|TEST_CONSTRUCT_CALLED|TEST_DEFINE_CALLED|TEST_VALIDATE_CALLED|
        TEST_UPDATE_CALLED|TEST_DESTRUCT_CALLED|TEST_DELETE_CALLED);   

    this->admin->hooksCalled |= TEST_DEINIT_CALLED;
}

