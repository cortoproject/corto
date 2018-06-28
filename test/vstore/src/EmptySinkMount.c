/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

int16_t test_EmptySinkMount_construct(
    test_EmptySinkMount this)
{
    /* Backwards compatibility patch for mount member */
    corto_subscriber s = corto_subscriber(this);
    if (this->mount) {
        corto_set_str(&s->query.from, corto_fullpath(NULL, this->mount));
    } else if (s->query.from) {
        this->mount = corto(CORTO_LOOKUP, {.id = s->query.from});
    }

    corto_mount(this)->ownership = CORTO_LOCAL_SOURCE;
    
    return corto_mount_construct(this);

}
