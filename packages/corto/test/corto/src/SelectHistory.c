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

corto_void _test_SelectHistory_tc_selectAll(
    test_SelectHistory this)
{
/* $begin(test/SelectHistory/tc_selectAll) */
    corto_iter it;
    corto_result *r;
    corto_sample *s;

    corto_int16 ret = corto_select("/A", "*")
        .contentType("text/corto")
        .fromNow()
        .toSample(0)
        .iter(&it);

    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&it));
    r = corto_iterNext(&it);
    test_assertstr(r->id, "a");
    test_assertstr(r->parent, ".");
    test_assertstr(r->type, "/test/Point");

    test_assert(corto_iterHasNext(&r->history));
    s = corto_iterNext(&r->history);
    test_assertint(s->timestamp.sec, 1);
    test_assertint(s->timestamp.nanosec, 0);
    test_assertstr((corto_string)s->value, "{20,22}");

    test_assert(corto_iterHasNext(&r->history));
    s = corto_iterNext(&r->history);
    test_assertint(s->timestamp.sec, 0);
    test_assertint(s->timestamp.nanosec, 0);
    test_assertstr((corto_string)s->value, "{10,11}");

    test_assert(!corto_iterHasNext(&r->history));


    test_assert(corto_iterHasNext(&it));
    r = corto_iterNext(&it);
    test_assertstr(r->id, "b");
    test_assertstr(r->parent, ".");
    test_assertstr(r->type, "/test/Point");

    test_assert(corto_iterHasNext(&r->history));
    s = corto_iterNext(&r->history);
    test_assertint(s->timestamp.sec, 2);
    test_assertint(s->timestamp.nanosec, 0);
    test_assertstr((corto_string)s->value, "{50,55}");

    test_assert(corto_iterHasNext(&r->history));
    s = corto_iterNext(&r->history);
    test_assertint(s->timestamp.sec, 1);
    test_assertint(s->timestamp.nanosec, 0);
    test_assertstr((corto_string)s->value, "{40,44}");

    test_assert(corto_iterHasNext(&r->history));
    s = corto_iterNext(&r->history);
    test_assertint(s->timestamp.sec, 0);
    test_assertint(s->timestamp.nanosec, 0);
    test_assertstr((corto_string)s->value, "{30,33}");

    test_assert(!corto_iterHasNext(&r->history));


    test_assert(corto_iterHasNext(&it));
    r = corto_iterNext(&it);
    test_assertstr(r->id, "c");
    test_assertstr(r->parent, ".");
    test_assertstr(r->type, "/test/Point");

    test_assert(corto_iterHasNext(&r->history));
    s = corto_iterNext(&r->history);
    test_assertint(s->timestamp.sec, 3);
    test_assertint(s->timestamp.nanosec, 0);
    test_assertstr((corto_string)s->value, "{90,99}");

    test_assert(corto_iterHasNext(&r->history));
    s = corto_iterNext(&r->history);
    test_assertint(s->timestamp.sec, 2);
    test_assertint(s->timestamp.nanosec, 0);
    test_assertstr((corto_string)s->value, "{80,88}");

    test_assert(corto_iterHasNext(&r->history));
    s = corto_iterNext(&r->history);
    test_assertint(s->timestamp.sec, 1);
    test_assertint(s->timestamp.nanosec, 0);
    test_assertstr((corto_string)s->value, "{70,77}");

    test_assert(corto_iterHasNext(&r->history));
    s = corto_iterNext(&r->history);
    test_assertint(s->timestamp.sec, 0);
    test_assertint(s->timestamp.nanosec, 0);
    test_assertstr((corto_string)s->value, "{60,66}");
    test_assert(!corto_iterHasNext(&it));

    test_assert(!corto_iterHasNext(&r->history));

/* $end */
}

corto_void _test_SelectHistory_tc_selectJson(
    test_SelectHistory this)
{
/* $begin(test/SelectHistory/tc_selectJson) */
    corto_iter it;
    corto_result *r;
    corto_sample *s;

    corto_int16 ret = corto_select("/A", "*")
        .contentType("text/json")
        .fromNow()
        .forDepth(2)
        .iter(&it);

    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&it));
    r = corto_iterNext(&it);
    test_assertstr(r->id, "a");
    test_assertstr(r->parent, ".");
    test_assertstr(r->type, "/test/Point");

    test_assert(corto_iterHasNext(&r->history));
    s = corto_iterNext(&r->history);
    test_assertint(s->timestamp.sec, 1);
    test_assertint(s->timestamp.nanosec, 0);
    test_assertstr((corto_string)s->value, "{\"x\":20,\"y\":22}");

    test_assert(corto_iterHasNext(&r->history));
    s = corto_iterNext(&r->history);
    test_assertint(s->timestamp.sec, 0);
    test_assertint(s->timestamp.nanosec, 0);
    test_assertstr((corto_string)s->value, "{\"x\":10,\"y\":11}");

    test_assert(!corto_iterHasNext(&r->history));


    test_assert(corto_iterHasNext(&it));
    r = corto_iterNext(&it);
    test_assertstr(r->id, "b");
    test_assertstr(r->parent, ".");
    test_assertstr(r->type, "/test/Point");

    test_assert(corto_iterHasNext(&r->history));
    s = corto_iterNext(&r->history);
    test_assertint(s->timestamp.sec, 2);
    test_assertint(s->timestamp.nanosec, 0);
    test_assertstr((corto_string)s->value, "{\"x\":50,\"y\":55}");

    test_assert(corto_iterHasNext(&r->history));
    s = corto_iterNext(&r->history);
    test_assertint(s->timestamp.sec, 1);
    test_assertint(s->timestamp.nanosec, 0);
    test_assertstr((corto_string)s->value, "{\"x\":40,\"y\":44}");

    test_assert(!corto_iterHasNext(&r->history));


    test_assert(corto_iterHasNext(&it));
    r = corto_iterNext(&it);
    test_assertstr(r->id, "c");
    test_assertstr(r->parent, ".");
    test_assertstr(r->type, "/test/Point");

    test_assert(corto_iterHasNext(&r->history));
    s = corto_iterNext(&r->history);
    test_assertint(s->timestamp.sec, 3);
    test_assertint(s->timestamp.nanosec, 0);
    test_assertstr((corto_string)s->value, "{\"x\":90,\"y\":99}");

    test_assert(corto_iterHasNext(&r->history));
    s = corto_iterNext(&r->history);
    test_assertint(s->timestamp.sec, 2);
    test_assertint(s->timestamp.nanosec, 0);
    test_assertstr((corto_string)s->value, "{\"x\":80,\"y\":88}");

    test_assert(!corto_iterHasNext(&r->history));

    test_assert(!corto_iterHasNext(&it));

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
    test_assertstr(r->type, "/test/Point");

    test_assert(corto_iterHasNext(&r->history));
    s = corto_iterNext(&r->history);
    test_assertint(s->timestamp.sec, 1);
    test_assertint(s->timestamp.nanosec, 0);
    test_assertstr((corto_string)s->value, "{20,22}");

    test_assert(corto_iterHasNext(&r->history));
    s = corto_iterNext(&r->history);
    test_assertint(s->timestamp.sec, 0);
    test_assertint(s->timestamp.nanosec, 0);
    test_assertstr((corto_string)s->value, "{10,11}");

    test_assert(!corto_iterHasNext(&r->history));


    test_assert(corto_iterHasNext(&it));
    r = corto_iterNext(&it);
    test_assertstr(r->id, "b");
    test_assertstr(r->parent, ".");
    test_assertstr(r->type, "/test/Point");

    test_assert(corto_iterHasNext(&r->history));
    s = corto_iterNext(&r->history);
    test_assertint(s->timestamp.sec, 2);
    test_assertint(s->timestamp.nanosec, 0);
    test_assertstr((corto_string)s->value, "{50,55}");

    test_assert(corto_iterHasNext(&r->history));
    s = corto_iterNext(&r->history);
    test_assertint(s->timestamp.sec, 1);
    test_assertint(s->timestamp.nanosec, 0);
    test_assertstr((corto_string)s->value, "{40,44}");

    test_assert(!corto_iterHasNext(&r->history));


    test_assert(corto_iterHasNext(&it));
    r = corto_iterNext(&it);
    test_assertstr(r->id, "c");
    test_assertstr(r->parent, ".");
    test_assertstr(r->type, "/test/Point");

    test_assert(corto_iterHasNext(&r->history));
    s = corto_iterNext(&r->history);
    test_assertint(s->timestamp.sec, 3);
    test_assertint(s->timestamp.nanosec, 0);
    test_assertstr((corto_string)s->value, "{90,99}");

    test_assert(corto_iterHasNext(&r->history));
    s = corto_iterNext(&r->history);
    test_assertint(s->timestamp.sec, 2);
    test_assertint(s->timestamp.nanosec, 0);
    test_assertstr((corto_string)s->value, "{80,88}");

    test_assert(!corto_iterHasNext(&r->history));

    test_assert(!corto_iterHasNext(&it));

/* $end */
}

corto_void _test_SelectHistory_tc_selectSampleToDepth(
    test_SelectHistory this)
{
/* $begin(test/SelectHistory/tc_selectSampleToDepth) */
    corto_iter it;
    corto_result *r;
    corto_sample *s;

    corto_int16 ret = corto_select("/A", "*")
        .contentType("text/corto")
        .fromSample(1)
        .forDepth(2)
        .iter(&it);

    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&it));
    r = corto_iterNext(&it);
    test_assertstr(r->id, "a");
    test_assertstr(r->parent, ".");
    test_assertstr(r->type, "/test/Point");

    test_assert(corto_iterHasNext(&r->history));
    s = corto_iterNext(&r->history);
    test_assertint(s->timestamp.sec, 1);
    test_assertint(s->timestamp.nanosec, 0);
    test_assertstr((corto_string)s->value, "{20,22}");

    test_assert(corto_iterHasNext(&r->history));
    s = corto_iterNext(&r->history);
    test_assertint(s->timestamp.sec, 0);
    test_assertint(s->timestamp.nanosec, 0);
    test_assertstr((corto_string)s->value, "{10,11}");

    test_assert(!corto_iterHasNext(&r->history));


    test_assert(corto_iterHasNext(&it));
    r = corto_iterNext(&it);
    test_assertstr(r->id, "b");
    test_assertstr(r->parent, ".");
    test_assertstr(r->type, "/test/Point");

    test_assert(corto_iterHasNext(&r->history));
    s = corto_iterNext(&r->history);
    test_assertint(s->timestamp.sec, 1);
    test_assertint(s->timestamp.nanosec, 0);
    test_assertstr((corto_string)s->value, "{40,44}");

    test_assert(corto_iterHasNext(&r->history));
    s = corto_iterNext(&r->history);
    test_assertint(s->timestamp.sec, 0);
    test_assertint(s->timestamp.nanosec, 0);
    test_assertstr((corto_string)s->value, "{30,33}");

    test_assert(!corto_iterHasNext(&r->history));


    test_assert(corto_iterHasNext(&it));
    r = corto_iterNext(&it);
    test_assertstr(r->id, "c");
    test_assertstr(r->parent, ".");
    test_assertstr(r->type, "/test/Point");

    test_assert(corto_iterHasNext(&r->history));
    s = corto_iterNext(&r->history);
    test_assertint(s->timestamp.sec, 1);
    test_assertint(s->timestamp.nanosec, 0);
    test_assertstr((corto_string)s->value, "{70,77}");

    test_assert(corto_iterHasNext(&r->history));
    s = corto_iterNext(&r->history);
    test_assertint(s->timestamp.sec, 0);
    test_assertint(s->timestamp.nanosec, 0);
    test_assertstr((corto_string)s->value, "{60,66}");

    test_assert(!corto_iterHasNext(&r->history));

    test_assert(!corto_iterHasNext(&it));

/* $end */
}

corto_void _test_SelectHistory_tc_selectSampleToSample(
    test_SelectHistory this)
{
/* $begin(test/SelectHistory/tc_selectSampleToSample) */
    corto_iter it;
    corto_result *r;
    corto_sample *s;

    corto_int16 ret = corto_select("/A", "*")
        .contentType("text/corto")
        .fromSample(3)
        .toSample(1)
        .iter(&it);

    test_assert(ret == 0);

    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&it));
    r = corto_iterNext(&it);
    test_assertstr(r->id, "a");
    test_assertstr(r->parent, ".");
    test_assertstr(r->type, "/test/Point");

    test_assert(corto_iterHasNext(&r->history));
    s = corto_iterNext(&r->history);
    test_assertint(s->timestamp.sec, 1);
    test_assertint(s->timestamp.nanosec, 0);
    test_assertstr((corto_string)s->value, "{20,22}");

    test_assert(!corto_iterHasNext(&r->history));


    test_assert(corto_iterHasNext(&it));
    r = corto_iterNext(&it);
    test_assertstr(r->id, "b");
    test_assertstr(r->parent, ".");
    test_assertstr(r->type, "/test/Point");

    test_assert(corto_iterHasNext(&r->history));
    s = corto_iterNext(&r->history);
    test_assertint(s->timestamp.sec, 2);
    test_assertint(s->timestamp.nanosec, 0);
    test_assertstr((corto_string)s->value, "{50,55}");

    test_assert(corto_iterHasNext(&r->history));
    s = corto_iterNext(&r->history);
    test_assertint(s->timestamp.sec, 1);
    test_assertint(s->timestamp.nanosec, 0);
    test_assertstr((corto_string)s->value, "{40,44}");

    test_assert(!corto_iterHasNext(&r->history));


    test_assert(corto_iterHasNext(&it));
    r = corto_iterNext(&it);
    test_assertstr(r->id, "c");
    test_assertstr(r->parent, ".");
    test_assertstr(r->type, "/test/Point");

    test_assert(corto_iterHasNext(&r->history));
    s = corto_iterNext(&r->history);
    test_assertint(s->timestamp.sec, 3);
    test_assertint(s->timestamp.nanosec, 0);
    test_assertstr((corto_string)s->value, "{90,99}");

    test_assert(corto_iterHasNext(&r->history));
    s = corto_iterNext(&r->history);
    test_assertint(s->timestamp.sec, 2);
    test_assertint(s->timestamp.nanosec, 0);
    test_assertstr((corto_string)s->value, "{80,88}");

    test_assert(corto_iterHasNext(&r->history));
    s = corto_iterNext(&r->history);
    test_assertint(s->timestamp.sec, 1);
    test_assertint(s->timestamp.nanosec, 0);
    test_assertstr((corto_string)s->value, "{70,77}");

    test_assert(!corto_iterHasNext(&r->history));

    test_assert(!corto_iterHasNext(&it));

/* $end */
}
