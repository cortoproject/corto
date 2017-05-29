/* $CORTO_GENERATED
 *
 * LoaderSimulatorMount.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <include/test.h>

int16_t _test_LoaderSimulatorMount_construct(
    test_LoaderSimulatorMount this)
{
/* $begin(test/LoaderSimulatorMount/construct) */

    corto_ptr_setref(&corto_mount(this)->mount, root_o);
    corto_observer(this)->mask = CORTO_ON_TREE;
    corto_mount(this)->policy.ownership = CORTO_LOCAL_OWNER;
    corto_ptr_setstr(&corto_subscriber(this)->query.type, "/corto/core/package");
    corto_ptr_setstr(&corto_subscriber(this)->contentType, "text/json");

    corto_resultAssign(
        corto_resultListAppendAlloc(this->packages),
        "p",
        NULL,
        ".",
        "/corto/core/package",
        0,
        FALSE
    );

    corto_resultAssign(
        corto_resultListAppendAlloc(this->packages),
        "q",
        NULL,
        "p",
        "/corto/core/package",
        0,
        FALSE
    );

    corto_resultAssign(
        corto_resultListAppendAlloc(this->packages),
        "p",
        NULL,
        "corto",
        "/corto/core/package",
        0,
        FALSE
    );
    
    corto_resultAssign(
        corto_resultListAppendAlloc(this->packages),
        "p/q",
        NULL,
        "corto/p",
        "/corto/core/package",
        0,
        FALSE
    );

    return corto_mount_construct(this);
/* $end */
}

corto_resultIter _test_LoaderSimulatorMount_onQuery(
    test_LoaderSimulatorMount this,
    corto_query *query)
{
/* $begin(test/LoaderSimulatorMount/onQuery) */

    /* << Insert implementation >> */

/* $end */
}
