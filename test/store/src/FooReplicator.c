/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

void test_FooReplicator_on_invoke(
    test_FooReplicator this,
    corto_object instance,
    corto_function proc,
    uintptr_t argptrs)
{
    this->invoked ++;
}


int16_t test_FooReplicator_construct(
    test_FooReplicator this)
{
    corto_subscriber s = corto_subscriber(this);
    if (!this->mount && corto_check_attr(this, CORTO_ATTR_NAMED)) {
        corto_set_ref(&this->mount, this);
    }
    if (this->mount) {
        corto_set_str(&s->query.from, corto_fullpath(NULL, this->mount));
    } else if (s->query.from) {
        this->mount = corto(CORTO_LOOKUP, {.id = s->query.from});
    }

    return corto_super_construct(this);
}
