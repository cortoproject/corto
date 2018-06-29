/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

void test_SelectHistory_setup(
    test_SelectHistory this)
{
    test_HistoryMount__create(root_o, "A", NULL);
}

void test_SelectHistory_tc_selectAll(
    test_SelectHistory this)
{
    corto_iter it;
    corto_result *r;
    corto_sample *s;

    corto_int16 ret = corto_select("*")
        .from("/A")
        .format("text/corto")
        .fromNow()
        .iter(&it);

    test_assert(ret == 0);

    test_assert(corto_iter_hasNext(&it));
    r = corto_iter_next(&it);
    test_assertstr(r->id, "a");
    test_assertstr(r->parent, ".");
    test_assertstr(r->type, "/test/Point");

    test_assert(corto_iter_hasNext(&r->history));
    s = corto_iter_next(&r->history);
    test_assertint(s->timestamp.sec, 1);
    test_assertint(s->timestamp.nanosec, 0);
    test_assertstr((corto_string)s->value, "{20,22}");

    test_assert(corto_iter_hasNext(&r->history));
    s = corto_iter_next(&r->history);
    test_assertint(s->timestamp.sec, 0);
    test_assertint(s->timestamp.nanosec, 0);
    test_assertstr((corto_string)s->value, "{10,11}");

    test_assert(!corto_iter_hasNext(&r->history));


    test_assert(corto_iter_hasNext(&it));
    r = corto_iter_next(&it);
    test_assertstr(r->id, "b");
    test_assertstr(r->parent, ".");
    test_assertstr(r->type, "/test/Point");

    test_assert(corto_iter_hasNext(&r->history));
    s = corto_iter_next(&r->history);
    test_assertint(s->timestamp.sec, 2);
    test_assertint(s->timestamp.nanosec, 0);
    test_assertstr((corto_string)s->value, "{50,55}");

    test_assert(corto_iter_hasNext(&r->history));
    s = corto_iter_next(&r->history);
    test_assertint(s->timestamp.sec, 1);
    test_assertint(s->timestamp.nanosec, 0);
    test_assertstr((corto_string)s->value, "{40,44}");

    test_assert(corto_iter_hasNext(&r->history));
    s = corto_iter_next(&r->history);
    test_assertint(s->timestamp.sec, 0);
    test_assertint(s->timestamp.nanosec, 0);
    test_assertstr((corto_string)s->value, "{30,33}");

    test_assert(!corto_iter_hasNext(&r->history));


    test_assert(corto_iter_hasNext(&it));
    r = corto_iter_next(&it);
    test_assertstr(r->id, "c");
    test_assertstr(r->parent, ".");
    test_assertstr(r->type, "/test/Point");

    test_assert(corto_iter_hasNext(&r->history));
    s = corto_iter_next(&r->history);
    test_assertint(s->timestamp.sec, 3);
    test_assertint(s->timestamp.nanosec, 0);
    test_assertstr((corto_string)s->value, "{90,99}");

    test_assert(corto_iter_hasNext(&r->history));
    s = corto_iter_next(&r->history);
    test_assertint(s->timestamp.sec, 2);
    test_assertint(s->timestamp.nanosec, 0);
    test_assertstr((corto_string)s->value, "{80,88}");

    test_assert(corto_iter_hasNext(&r->history));
    s = corto_iter_next(&r->history);
    test_assertint(s->timestamp.sec, 1);
    test_assertint(s->timestamp.nanosec, 0);
    test_assertstr((corto_string)s->value, "{70,77}");

    test_assert(corto_iter_hasNext(&r->history));
    s = corto_iter_next(&r->history);
    test_assertint(s->timestamp.sec, 0);
    test_assertint(s->timestamp.nanosec, 0);
    test_assertstr((corto_string)s->value, "{60,66}");
    test_assert(!corto_iter_hasNext(&r->history));

    test_assert(!corto_iter_hasNext(&it));

}

void test_SelectHistory_tc_selectJson(
    test_SelectHistory this)
{
    corto_iter it;
    corto_result *r;
    corto_sample *s;

    corto_int16 ret = corto_select("*")
        .from("/A")
        .format("text/json")
        .fromNow()
        .slimit(2)
        .iter(&it);

    test_assert(ret == 0);

    test_assert(corto_iter_hasNext(&it));
    r = corto_iter_next(&it);
    test_assertstr(r->id, "a");
    test_assertstr(r->parent, ".");
    test_assertstr(r->type, "/test/Point");

    test_assert(corto_iter_hasNext(&r->history));
    s = corto_iter_next(&r->history);
    test_assertint(s->timestamp.sec, 1);
    test_assertint(s->timestamp.nanosec, 0);
    test_assertstr((corto_string)s->value, "{\"x\":20,\"y\":22}");

    test_assert(corto_iter_hasNext(&r->history));
    s = corto_iter_next(&r->history);
    test_assertint(s->timestamp.sec, 0);
    test_assertint(s->timestamp.nanosec, 0);
    test_assertstr((corto_string)s->value, "{\"x\":10,\"y\":11}");

    test_assert(!corto_iter_hasNext(&r->history));


    test_assert(corto_iter_hasNext(&it));
    r = corto_iter_next(&it);
    test_assertstr(r->id, "b");
    test_assertstr(r->parent, ".");
    test_assertstr(r->type, "/test/Point");

    test_assert(corto_iter_hasNext(&r->history));
    s = corto_iter_next(&r->history);
    test_assertint(s->timestamp.sec, 2);
    test_assertint(s->timestamp.nanosec, 0);
    test_assertstr((corto_string)s->value, "{\"x\":50,\"y\":55}");

    test_assert(corto_iter_hasNext(&r->history));
    s = corto_iter_next(&r->history);
    test_assertint(s->timestamp.sec, 1);
    test_assertint(s->timestamp.nanosec, 0);
    test_assertstr((corto_string)s->value, "{\"x\":40,\"y\":44}");

    test_assert(!corto_iter_hasNext(&r->history));


    test_assert(corto_iter_hasNext(&it));
    r = corto_iter_next(&it);
    test_assertstr(r->id, "c");
    test_assertstr(r->parent, ".");
    test_assertstr(r->type, "/test/Point");

    test_assert(corto_iter_hasNext(&r->history));
    s = corto_iter_next(&r->history);
    test_assertint(s->timestamp.sec, 3);
    test_assertint(s->timestamp.nanosec, 0);
    test_assertstr((corto_string)s->value, "{\"x\":90,\"y\":99}");

    test_assert(corto_iter_hasNext(&r->history));
    s = corto_iter_next(&r->history);
    test_assertint(s->timestamp.sec, 2);
    test_assertint(s->timestamp.nanosec, 0);
    test_assertstr((corto_string)s->value, "{\"x\":80,\"y\":88}");

    test_assert(!corto_iter_hasNext(&r->history));

    test_assert(!corto_iter_hasNext(&it));

}

void test_SelectHistory_tc_selectNowToDepth(
    test_SelectHistory this)
{
    corto_iter it;
    corto_result *r;
    corto_sample *s;

    corto_int16 ret = corto_select("*")
        .from("/A")
        .format("text/corto")
        .fromNow()
        .slimit(2)
        .iter(&it);

    test_assert(ret == 0);

    test_assert(corto_iter_hasNext(&it));
    r = corto_iter_next(&it);
    test_assertstr(r->id, "a");
    test_assertstr(r->parent, ".");
    test_assertstr(r->type, "/test/Point");

    test_assert(corto_iter_hasNext(&r->history));
    s = corto_iter_next(&r->history);
    test_assertint(s->timestamp.sec, 1);
    test_assertint(s->timestamp.nanosec, 0);
    test_assertstr((corto_string)s->value, "{20,22}");

    test_assert(corto_iter_hasNext(&r->history));
    s = corto_iter_next(&r->history);
    test_assertint(s->timestamp.sec, 0);
    test_assertint(s->timestamp.nanosec, 0);
    test_assertstr((corto_string)s->value, "{10,11}");

    test_assert(!corto_iter_hasNext(&r->history));


    test_assert(corto_iter_hasNext(&it));
    r = corto_iter_next(&it);
    test_assertstr(r->id, "b");
    test_assertstr(r->parent, ".");
    test_assertstr(r->type, "/test/Point");

    test_assert(corto_iter_hasNext(&r->history));
    s = corto_iter_next(&r->history);
    test_assertint(s->timestamp.sec, 2);
    test_assertint(s->timestamp.nanosec, 0);
    test_assertstr((corto_string)s->value, "{50,55}");

    test_assert(corto_iter_hasNext(&r->history));
    s = corto_iter_next(&r->history);
    test_assertint(s->timestamp.sec, 1);
    test_assertint(s->timestamp.nanosec, 0);
    test_assertstr((corto_string)s->value, "{40,44}");

    test_assert(!corto_iter_hasNext(&r->history));


    test_assert(corto_iter_hasNext(&it));
    r = corto_iter_next(&it);
    test_assertstr(r->id, "c");
    test_assertstr(r->parent, ".");
    test_assertstr(r->type, "/test/Point");

    test_assert(corto_iter_hasNext(&r->history));
    s = corto_iter_next(&r->history);
    test_assertint(s->timestamp.sec, 3);
    test_assertint(s->timestamp.nanosec, 0);
    test_assertstr((corto_string)s->value, "{90,99}");

    test_assert(corto_iter_hasNext(&r->history));
    s = corto_iter_next(&r->history);
    test_assertint(s->timestamp.sec, 2);
    test_assertint(s->timestamp.nanosec, 0);
    test_assertstr((corto_string)s->value, "{80,88}");

    test_assert(!corto_iter_hasNext(&r->history));

    test_assert(!corto_iter_hasNext(&it));

}

void test_SelectHistory_tc_selectSampleToDepth(
    test_SelectHistory this)
{
    corto_iter it;
    corto_result *r;
    corto_sample *s;

    corto_int16 ret = corto_select("*")
        .from("/A")
        .format("text/corto")
        .soffset(1)
        .slimit(2)
        .iter(&it);

    test_assert(ret == 0);

    test_assert(corto_iter_hasNext(&it));
    r = corto_iter_next(&it);
    test_assertstr(r->id, "a");
    test_assertstr(r->parent, ".");
    test_assertstr(r->type, "/test/Point");

    test_assert(corto_iter_hasNext(&r->history));
    s = corto_iter_next(&r->history);
    test_assertint(s->timestamp.sec, 0);
    test_assertint(s->timestamp.nanosec, 0);
    test_assertstr((corto_string)s->value, "{10,11}");

    test_assert(!corto_iter_hasNext(&r->history));


    test_assert(corto_iter_hasNext(&it));
    r = corto_iter_next(&it);
    test_assertstr(r->id, "b");
    test_assertstr(r->parent, ".");
    test_assertstr(r->type, "/test/Point");

    test_assert(corto_iter_hasNext(&r->history));
    s = corto_iter_next(&r->history);
    test_assertint(s->timestamp.sec, 1);
    test_assertint(s->timestamp.nanosec, 0);
    test_assertstr((corto_string)s->value, "{40,44}");

    test_assert(corto_iter_hasNext(&r->history));
    s = corto_iter_next(&r->history);
    test_assertint(s->timestamp.sec, 0);
    test_assertint(s->timestamp.nanosec, 0);
    test_assertstr((corto_string)s->value, "{30,33}");

    test_assert(!corto_iter_hasNext(&r->history));


    test_assert(corto_iter_hasNext(&it));
    r = corto_iter_next(&it);
    test_assertstr(r->id, "c");
    test_assertstr(r->parent, ".");
    test_assertstr(r->type, "/test/Point");

    test_assert(corto_iter_hasNext(&r->history));
    s = corto_iter_next(&r->history);
    test_assertint(s->timestamp.sec, 2);
    test_assertint(s->timestamp.nanosec, 0);
    test_assertstr((corto_string)s->value, "{80,88}");

    test_assert(corto_iter_hasNext(&r->history));
    s = corto_iter_next(&r->history);
    test_assertint(s->timestamp.sec, 1);
    test_assertint(s->timestamp.nanosec, 0);
    test_assertstr((corto_string)s->value, "{70,77}");

    test_assert(!corto_iter_hasNext(&r->history));

    test_assert(!corto_iter_hasNext(&it));

}
