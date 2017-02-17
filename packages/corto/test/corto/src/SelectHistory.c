/* $CORTO_GENERATED
 *
 * SelectHistory.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <include/test.h>

corto_void _test_SelectHistory_setup(
    test_SelectHistory this)
{
/* $begin(test/SelectHistory/setup) */

    test_HistoryMountCreateChild(root_o, "A", NULL);

/* $end */
}

corto_void _test_SelectHistory_tc_selectNowToDepth(
    test_SelectHistory this)
{
/* $begin(test/SelectHistory/tc_selectNowToDepth) */
    corto_iter it;
    corto_result *r;
    corto_sample *s;

    corto_int16 ret = corto_select("/A", "*")
        .contentType("text/corto")
        .fromNow()
        .forDepth(2)
        .iter(&it);

    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&it));
    r = corto_iterNext(&it);
    test_assertstr(r->id, "a");
    test_assertstr(r->parent, ".");
    test_assertstr(r->type, "int32");

    test_assert(corto_iterHasNext(&r->history));
    s = corto_iterNext(&r->history);
    test_assertint(s->timestamp.sec, 1);
    test_assertint(s->timestamp.nanosec, 0);
    test_assertstr((corto_string)s->value, "20");

    test_assert(corto_iterHasNext(&r->history));
    s = corto_iterNext(&r->history);
    test_assertint(s->timestamp.sec, 0);
    test_assertint(s->timestamp.nanosec, 0);
    test_assertstr((corto_string)s->value, "10");

    test_assert(!corto_iterHasNext(&r->history));


    test_assert(corto_iterHasNext(&it));
    r = corto_iterNext(&it);
    test_assertstr(r->id, "b");
    test_assertstr(r->parent, ".");
    test_assertstr(r->type, "int32");

    test_assert(corto_iterHasNext(&r->history));
    s = corto_iterNext(&r->history);
    test_assertint(s->timestamp.sec, 2);
    test_assertint(s->timestamp.nanosec, 0);
    test_assertstr((corto_string)s->value, "50");

    test_assert(corto_iterHasNext(&r->history));
    s = corto_iterNext(&r->history);
    test_assertint(s->timestamp.sec, 1);
    test_assertint(s->timestamp.nanosec, 0);
    test_assertstr((corto_string)s->value, "40");

    test_assert(!corto_iterHasNext(&r->history));


    test_assert(corto_iterHasNext(&it));
    r = corto_iterNext(&it);
    test_assertstr(r->id, "c");
    test_assertstr(r->parent, ".");
    test_assertstr(r->type, "int32");

    test_assert(corto_iterHasNext(&r->history));
    s = corto_iterNext(&r->history);
    test_assertint(s->timestamp.sec, 3);
    test_assertint(s->timestamp.nanosec, 0);
    test_assertstr((corto_string)s->value, "90");

    test_assert(corto_iterHasNext(&r->history));
    s = corto_iterNext(&r->history);
    test_assertint(s->timestamp.sec, 2);
    test_assertint(s->timestamp.nanosec, 0);
    test_assertstr((corto_string)s->value, "80");

    test_assert(!corto_iterHasNext(&r->history));

    test_assert(!corto_iterHasNext(&it));

/* $end */
}
