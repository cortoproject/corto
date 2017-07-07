/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

void test_FooReplicator_onInvoke(
    test_FooReplicator this,
    corto_object instance,
    corto_function proc,
    uintptr_t argptrs)
{

        this->invoked ++;

}

