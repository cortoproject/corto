/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

int16_t test_IdMount_construct(
    test_IdMount this)
{
    /* Backwards compatibility patch for mount member */
    corto_subscriber s = corto_subscriber(this);
    if (this->mount) {
        corto_set_str(&s->query.from, corto_fullpath(NULL, this->mount));
    } else if (s->query.from) {
        this->mount = corto(CORTO_LOOKUP, {.id = s->query.from});
    }

    corto_mount(this)->ownership = CORTO_LOCAL_SOURCE;
    corto_set_str(&corto_subscriber(this)->query.select, "//");

    return corto_mount_construct(this);
}

corto_string test_IdMount_on_id(
    test_IdMount this)
{
    return corto_strdup("some_unique_id");
}
