/* This is a managed file. Do not delete this comment. */

#include <include/test.h>
#include <math.h>
void test_ReplicatorEvent_tc_event(
    test_ReplicatorEvent this)
{
    corto_int16 ret;

    corto_void__create_auto(root_o, parent);
    test_assert(parent != NULL);

    corto_query q = {.select = "/", .from = corto_fullpath(NULL, parent)};
    test_EventReplicator__create_auto(NULL, mount, &q, NULL);
    test_assert(mount != NULL);
    int32_t *a = corto_declare(parent, "a", corto_int32_o);
    test_assert(a != NULL);
    test_assert(corto_check_attr(a, CORTO_ATTR_PERSISTENT));
    test_assertint(mount->declareCount, 0);
    test_assertint(mount->updateCount, 0);
    test_assertint(mount->deleteCount, 0);
    ret = corto_define(a);
    test_assert(ret == 0);
    test_assert(corto_sourceof(a) == NULL);
    test_assertint(mount->declareCount, 0);
    test_assertint(mount->updateCount, 1);
    test_assertint(mount->deleteCount, 0);
    ret = corto_int32__update(a, 20);
    test_assert(ret == 0);
    test_assertint(mount->declareCount, 0);
    test_assertint(mount->updateCount, 2);
    test_assertint(mount->deleteCount, 0);
    ret = corto_delete(a);
    test_assert(ret == 0);
    test_assertint(mount->declareCount, 0);
    test_assertint(mount->updateCount, 2);
    test_assertint(mount->deleteCount, 1);
    ret = corto_delete(mount);
    test_assert(ret == 0);
    ret = corto_delete(parent);
    test_assert(ret == 0);
}

void test_ReplicatorEvent_tc_eventDefineWith__update(
    test_ReplicatorEvent this)
{
    corto_int16 ret;

    corto_void__create_auto(root_o, parent);
    test_assert(parent != NULL);

    corto_query q = {.select = "/", .from = corto_fullpath(NULL, parent)};
    test_EventReplicator__create_auto(NULL, mount, &q, NULL);
    test_assert(mount != NULL);
    int32_t *a = corto_declare(parent, "a", corto_int32_o);
    test_assert(a != NULL);
    test_assertint(mount->declareCount, 0);
    test_assert(mount->updateCount == 0);
    test_assert(mount->deleteCount == 0);
    ret = corto_int32__update(a, 20);
    test_assert(ret == 0);
    test_assertint(mount->declareCount, 0);
    test_assert(mount->updateCount == 1);
    test_assert(mount->deleteCount == 0);
    ret = corto_delete(a);
    test_assert(ret == 0);
    test_assertint(mount->declareCount, 0);
    test_assert(mount->updateCount == 1);
    test_assert(mount->deleteCount == 1);
    ret = corto_delete(mount);
    test_assert(ret == 0);
    ret = corto_delete(parent);
    test_assert(ret == 0);
}

void test_ReplicatorEvent_tc_eventTree(
    test_ReplicatorEvent this)
{
    corto_int16 ret;

    corto_void__create_auto(root_o, parent);
    test_assert(parent != NULL);

    corto_query q = {.select = "/", .from = corto_fullpath(NULL, parent)};
    test_EventReplicator__create_auto(NULL, mount, &q, NULL);
    test_assert(mount != NULL);
    int32_t *a = corto_declare(parent, "a", corto_int32_o);
    test_assert(a != NULL);
    test_assert(corto_check_attr(a, CORTO_ATTR_PERSISTENT));
    test_assertint(mount->declareCount, 0);
    test_assertint(mount->updateCount, 0);
    test_assertint(mount->deleteCount, 0);
    int32_t *a_a = corto_declare(a, "a_a", corto_int32_o);
    test_assert(a_a != NULL);
    test_assert(corto_check_attr(a_a, CORTO_ATTR_PERSISTENT));
    test_assertint(mount->declareCount, 0);
    test_assertint(mount->updateCount, 0);
    test_assertint(mount->deleteCount, 0);
    ret = corto_define(a);
    test_assert(ret == 0);
    test_assert(corto_sourceof(a) == NULL);
    test_assertint(mount->declareCount, 0);
    test_assertint(mount->updateCount, 1);
    test_assertint(mount->deleteCount, 0);
    ret = corto_define(a_a);
    test_assert(corto_sourceof(a_a) == NULL);
    test_assert(ret == 0);
    test_assertint(mount->declareCount, 0);
    test_assertint(mount->updateCount, 1);
    test_assertint(mount->deleteCount, 0);
    ret = corto_int32__update(a, 20);
    test_assert(ret == 0);
    test_assertint(mount->declareCount, 0);
    test_assertint(mount->updateCount, 2);
    test_assertint(mount->deleteCount, 0);
    ret = corto_int32__update(a_a, 20);
    test_assert(ret == 0);
    test_assertint(mount->declareCount, 0);
    test_assertint(mount->updateCount, 2);
    test_assertint(mount->deleteCount, 0);
    ret = corto_delete(a);
    test_assert(ret == 0);
    test_assertint(mount->declareCount, 0);
    test_assertint(mount->updateCount, 2);
    test_assertint(mount->deleteCount, 1);
    ret = corto_delete(mount);
    test_assert(ret == 0);
    ret = corto_delete(parent);
    test_assert(ret == 0);
}

void test_ReplicatorEvent_tc_eventTreeWithTree(
    test_ReplicatorEvent this)
{
    corto_int16 ret;

    corto_void__create_auto(root_o, parent);
    test_assert(parent != NULL);

    corto_query q = {.select = "//", .from = corto_fullpath(NULL, parent)};
    test_EventReplicator__create_auto(NULL, mount, &q, NULL);
    test_assert(mount != NULL);
    int32_t *a = corto_declare(parent, "a", corto_int32_o);
    test_assert(a != NULL);
    test_assert(corto_check_attr(a, CORTO_ATTR_PERSISTENT));
    test_assertint(mount->declareCount, 0);
    test_assertint(mount->updateCount, 0);
    test_assertint(mount->deleteCount, 0);
    int32_t *a_a = corto_declare(a, "a_a", corto_int32_o);
    test_assert(a_a != NULL);
    test_assert(corto_check_attr(a_a, CORTO_ATTR_PERSISTENT));
    test_assertint(mount->declareCount, 0);
    test_assertint(mount->updateCount, 0);
    test_assertint(mount->deleteCount, 0);
    ret = corto_define(a);
    test_assert(corto_sourceof(a) == NULL);
    test_assert(ret == 0);
    test_assertint(mount->declareCount, 0);
    test_assertint(mount->updateCount, 1);
    test_assertint(mount->deleteCount, 0);
    ret = corto_define(a_a);
    test_assert(corto_sourceof(a_a) == NULL);
    test_assert(ret == 0);
    test_assertint(mount->declareCount, 0);
    test_assertint(mount->updateCount, 2);
    test_assertint(mount->deleteCount, 0);
    ret = corto_int32__update(a, 20);
    test_assert(ret == 0);
    test_assertint(mount->declareCount, 0);
    test_assertint(mount->updateCount, 3);
    test_assertint(mount->deleteCount, 0);
    ret = corto_int32__update(a_a, 20);
    test_assert(ret == 0);
    test_assertint(mount->declareCount, 0);
    test_assertint(mount->updateCount, 4);
    test_assertint(mount->deleteCount, 0);
    ret = corto_delete(a);
    test_assert(ret == 0);
    test_assertint(mount->declareCount, 0);
    test_assertint(mount->updateCount, 4);
    test_assertint(mount->deleteCount, 2);
    ret = corto_delete(mount);
    test_assert(ret == 0);
    ret = corto_delete(parent);
    test_assert(ret == 0);
}

void test_ReplicatorEvent_tc_eventWithTree(
    test_ReplicatorEvent this)
{
    corto_int16 ret;

    corto_void__create_auto(root_o, parent);
    test_assert(parent != NULL);

    corto_query q = {.select = "//", .from = corto_fullpath(NULL, parent)};
    test_EventReplicator__create_auto(NULL, mount, &q, NULL);
    test_assert(mount != NULL);
    int32_t *a = corto_declare(parent, "a", corto_int32_o);
    test_assert(a != NULL);
    test_assert(corto_check_attr(a, CORTO_ATTR_PERSISTENT));
    test_assertint(mount->declareCount, 0);
    test_assertint(mount->updateCount, 0);
    test_assertint(mount->deleteCount, 0);
    ret = corto_define(a);
    test_assert(corto_sourceof(a) == NULL);
    test_assert(ret == 0);
    test_assertint(mount->declareCount, 0);
    test_assertint(mount->updateCount, 1);
    test_assertint(mount->deleteCount, 0);
    ret = corto_int32__update(a, 20);
    test_assert(ret == 0);
    test_assertint(mount->declareCount, 0);
    test_assertint(mount->updateCount, 2);
    test_assertint(mount->deleteCount, 0);
    ret = corto_delete(a);
    test_assert(ret == 0);
    test_assertint(mount->declareCount, 0);
    test_assertint(mount->updateCount, 2);
    test_assertint(mount->deleteCount, 1);
    ret = corto_delete(mount);
    test_assert(ret == 0);
    ret = corto_delete(parent);
    test_assert(ret == 0);
}

void test_ReplicatorEvent_tc_matchingType(
    test_ReplicatorEvent this)
{
    corto_int16 ret;

    corto_void__create_auto(root_o, parent);
    test_assert(parent != NULL);

    corto_query q = {.select = "/", .from = corto_fullpath(NULL, parent), .type = "int32"};
    test_EventReplicator__create_auto(NULL, mount, &q, NULL);
    test_assert(mount != NULL);
    int32_t *a = corto_declare(parent, "a", corto_int32_o);
    test_assert(a != NULL);
    test_assert(corto_check_attr(a, CORTO_ATTR_PERSISTENT));
    test_assertint(mount->declareCount, 0);
    test_assertint(mount->updateCount, 0);
    test_assertint(mount->deleteCount, 0);
    float *b = corto_declare(parent, "b", corto_float32_o);
    test_assert(a != NULL);
    test_assert(corto_check_attr(b, CORTO_ATTR_PERSISTENT));
    test_assertint(mount->declareCount, 0);
    test_assertint(mount->updateCount, 0);
    test_assertint(mount->deleteCount, 0);
    ret = corto_define(a);
    test_assert(corto_sourceof(a) == NULL);
    test_assert(ret == 0);
    test_assertint(mount->declareCount, 0);
    test_assertint(mount->updateCount, 1);
    test_assertint(mount->deleteCount, 0);
    ret = corto_define(b);
    test_assert(corto_sourceof(b) == NULL);
    test_assert(ret == 0);
    test_assertint(mount->declareCount, 0);
    test_assertint(mount->updateCount, 1);
    test_assertint(mount->deleteCount, 0);
    ret = corto_int32__update(a, 20);
    test_assert(ret == 0);
    test_assertint(mount->declareCount, 0);
    test_assertint(mount->updateCount, 2);
    test_assertint(mount->deleteCount, 0);
    ret = corto_float32__update(b, 10.5);
    test_assert(ret == 0);
    test_assertint(mount->declareCount, 0);
    test_assertint(mount->updateCount, 2);
    test_assertint(mount->deleteCount, 0);
    ret = corto_delete(a);
    test_assert(ret == 0);
    test_assertint(mount->declareCount, 0);
    test_assertint(mount->updateCount, 2);
    test_assertint(mount->deleteCount, 1);
    ret = corto_delete(b);
    test_assert(ret == 0);
    test_assertint(mount->declareCount, 0);
    test_assertint(mount->updateCount, 2);
    test_assertint(mount->deleteCount, 1);
    ret = corto_delete(mount);
    test_assert(ret == 0);
    ret = corto_delete(parent);
    test_assert(ret == 0);
}

void test_ReplicatorEvent_tc_nonPersistent(
    test_ReplicatorEvent this)
{
    corto_int16 ret;

    corto_void__create_auto(root_o, parent);
    test_assert(parent != NULL);

    corto_query q = {.select = "/", .from = corto_fullpath(NULL, parent)};
    test_EventReplicator__create_auto(NULL, mount, &q, NULL);
    test_assert(mount != NULL);
    int32_t *a = corto_declare(parent, "a", corto_int32_o);
    test_assert(a != NULL);
    test_assert(corto_check_attr(a, CORTO_ATTR_PERSISTENT));
    test_assertint(mount->declareCount, 0);
    test_assertint(mount->updateCount, 0);
    test_assertint(mount->deleteCount, 0);
    corto_attr prev = corto_set_attr(CORTO_ATTR_WRITABLE);
    float *b = corto_declare(parent, "b", corto_float32_o);
    corto_set_attr(prev);
    test_assert(a != NULL);
    test_assert(!corto_check_attr(b, CORTO_ATTR_PERSISTENT));
    test_assertint(mount->declareCount, 0);
    test_assertint(mount->updateCount, 0);
    test_assertint(mount->deleteCount, 0);
    ret = corto_define(a);
    test_assert(corto_sourceof(a) == NULL);
    test_assert(ret == 0);
    test_assertint(mount->declareCount, 0);
    test_assertint(mount->updateCount, 1);
    test_assertint(mount->deleteCount, 0);
    ret = corto_define(b);
    test_assert(corto_sourceof(b) == NULL);
    test_assert(ret == 0);
    test_assertint(mount->declareCount, 0);
    test_assertint(mount->updateCount, 1);
    test_assertint(mount->deleteCount, 0);
    ret = corto_int32__update(a, 20);
    test_assert(ret == 0);
    test_assertint(mount->declareCount, 0);
    test_assertint(mount->updateCount, 2);
    test_assertint(mount->deleteCount, 0);
    ret = corto_float32__update(b, 10.5);
    test_assert(ret == 0);
    test_assertint(mount->declareCount, 0);
    test_assertint(mount->updateCount, 2);
    test_assertint(mount->deleteCount, 0);
    ret = corto_delete(a);
    test_assert(ret == 0);
    test_assertint(mount->declareCount, 0);
    test_assertint(mount->updateCount, 2);
    test_assertint(mount->deleteCount, 1);
    ret = corto_delete(b);
    test_assert(ret == 0);
    test_assertint(mount->declareCount, 0);
    test_assertint(mount->updateCount, 2);
    test_assertint(mount->deleteCount, 1);
    ret = corto_delete(mount);
    test_assert(ret == 0);
    ret = corto_delete(parent);
    test_assert(ret == 0);
}

void test_ReplicatorEvent_tc_ownedByMount(
    test_ReplicatorEvent this)
{
    corto_int16 ret;

    corto_void__create_auto(root_o, parent);
    test_assert(parent != NULL);

    corto_query q = {.select = "/", .from = corto_fullpath(NULL, parent)};
    test_EventReplicator__create_auto(NULL, mount, &q, NULL);
    test_assert(mount != NULL);
    int32_t *a = corto_declare(parent, "a", corto_int32_o);
    test_assert(a != NULL);
    test_assert(corto_check_attr(a, CORTO_ATTR_PERSISTENT));
    test_assertint(mount->declareCount, 0);
    test_assertint(mount->updateCount, 0);
    test_assertint(mount->deleteCount, 0);
    float *b = corto_declare(parent, "b", corto_float32_o);
    test_assert(a != NULL);
    test_assert(corto_check_attr(b, CORTO_ATTR_PERSISTENT));
    test_assertint(mount->declareCount, 0);
    test_assertint(mount->updateCount, 0);
    test_assertint(mount->deleteCount, 0);
    ret = corto_define(a);
    test_assert(ret == 0);
    test_assert(corto_sourceof(a) == NULL);
    test_assertint(mount->declareCount, 0);
    test_assertint(mount->updateCount, 1);
    test_assertint(mount->deleteCount, 0);
    corto_set_source(mount);
    ret = corto_define(b);
    corto_set_source(NULL);
    test_assert(ret == 0);
    test_assert(corto_sourceof(b) == mount);
    test_assertint(mount->declareCount, 0);
    test_assertint(mount->updateCount, 1);
    test_assertint(mount->deleteCount, 0);
    ret = corto_int32__update(a, 20);
    test_assert(ret == 0);
    test_assertint(mount->declareCount, 0);
    test_assertint(mount->updateCount, 2);
    test_assertint(mount->deleteCount, 0);
    corto_set_source(mount);
    ret = corto_float32__update(b, 10.5);
    corto_set_source(NULL);
    test_assert(ret == 0);
    test_assertint(mount->declareCount, 0);
    test_assertint(mount->updateCount, 2);
    test_assertint(mount->deleteCount, 0);
    ret = corto_delete(a);
    test_assert(ret == 0);
    test_assertint(mount->declareCount, 0);
    test_assertint(mount->updateCount, 2);
    test_assertint(mount->deleteCount, 1);
    corto_set_source(mount);
    ret = corto_delete(b);
    corto_set_source(NULL);
    test_assert(ret == 0);
    test_assertint(mount->declareCount, 0);
    test_assertint(mount->updateCount, 2);
    test_assertint(mount->deleteCount, 1);
    ret = corto_delete(mount);
    test_assert(ret == 0);
    ret = corto_delete(parent);
    test_assert(ret == 0);
}

void test_ReplicatorEvent_tc_rateLimitOneObject(
    test_ReplicatorEvent this)
{
    corto_int16 ret;
    int cycles = 50000;

    corto_time timeout = {60, 0};
    test_setTimeout(&timeout);
    if (test_runslow()) {
        cycles = 100;
    }

    corto_void__create_auto(root_o, parent);
    test_assert(parent != NULL);
    corto_mountPolicy policy = {.sampleRate = 5};
    corto_query q = {.select = "/", .from = corto_fullpath(NULL, parent)};
    test_EventReplicator__create_auto(NULL, mount, &q, &policy);
    test_assert(mount != NULL);
    int32_t *a = corto_declare(parent, "a", corto_int32_o);
    test_assert(a != NULL);
    test_assert(corto_check_attr(a, CORTO_ATTR_PERSISTENT));
    /* Send 100K updates */
    corto_time start, stop;
    corto_time_get(&start);
    corto_int32 i; for (i = 0; i < cycles; i ++) {
        ret = corto_int32__update(a, 20);
        test_assert(ret == 0);
    }

    corto_time_get(&stop);
    // Wait 2/frequency to ensure mount has processed all data
    corto_sleep(0, 400000000);
    corto_float64 t = corto_time_toDouble(corto_time_sub(stop, start));
    test_assert(mount->updateCount <= ceil(t * 5.0 + 1.0));
    test_assert(mount->updateCount >= floor(t * 5.0 - 1.0));
    ret = corto_delete(a);
    test_assert(ret == 0);
    ret = corto_delete(mount);
    test_assert(ret == 0);
    ret = corto_delete(parent);
    test_assert(ret == 0);
}

void test_ReplicatorEvent_tc_rateLimitThreeObjects(
    test_ReplicatorEvent this)
{
    corto_int16 ret;
    int cycles = 50000;
    corto_time timeout = {60, 0};
    test_setTimeout(&timeout);
    if (test_runslow()) {
        cycles = 100;
    }

    corto_void__create_auto(root_o, parent);
    test_assert(parent != NULL);
    corto_mountPolicy policy = {.sampleRate = 5};
    corto_query q = {.select = "/", .from = corto_fullpath(NULL, parent)};
    test_EventReplicator__create_auto(NULL, mount, &q, &policy);
    test_assert(mount != NULL);
    int32_t *a = corto_declare(parent, "a", corto_int32_o);
    test_assert(a != NULL);
    test_assert(corto_check_attr(a, CORTO_ATTR_PERSISTENT));
    int32_t *b = corto_declare(parent, "b", corto_int32_o);
    test_assert(a != NULL);
    test_assert(corto_check_attr(a, CORTO_ATTR_PERSISTENT));
    int32_t *c = corto_declare(parent, "c", corto_int32_o);
    test_assert(a != NULL);
    test_assert(corto_check_attr(a, CORTO_ATTR_PERSISTENT));
    /* Send 100K updates */
    corto_time start, stop;
    corto_time_get(&start);
    corto_int32 i; for (i = 0; i < cycles; i ++) {
        ret = corto_int32__update(a, 20);
        ret = corto_int32__update(b, 20);
        ret = corto_int32__update(c, 20);
        test_assert(ret == 0);
    }

    corto_time_get(&stop);
    // Wait 2/frequency to ensure mount has processed all data
    corto_sleep(0, 400000000);
    corto_float64 t = corto_time_toDouble(corto_time_sub(stop, start));
    test_assert(mount->updateCount <= 3.0 * ceil(t * 5.0 + 1.0));
    test_assert(mount->updateCount >= 3.0 * floor(t * 5.0 - 1.0));
    ret = corto_delete(a);
    test_assert(ret == 0);
    ret = corto_delete(mount);
    test_assert(ret == 0);
    ret = corto_delete(parent);
    test_assert(ret == 0);
}

void test_ReplicatorEvent_tc_rateLimitAlign(
    test_ReplicatorEvent this)
{
    /* Test issue #634 */
    test_assert(corto_create(root_o, "data/obj", corto_void_o) != NULL);
    corto_mount mnt = corto_declare(root_o, "config/influx", corto_mount_o);
    test_assert(mnt != NULL);
    mnt->super.query = (corto_query){
        .select = corto_strdup("/"),
        .from = corto_strdup("data")
    };
    mnt->policy = (corto_mountPolicy){
        .mask = CORTO_MOUNT_HISTORY_BATCH_NOTIFY,
        .sampleRate = 20.0,
    };
    test_assert(corto_define(mnt) == 0);
}
