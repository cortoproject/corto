/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

void test_rw_target_tc_primitive(
    test_rw_target this)
{
    test_s_target_primitive *o = corto_create(root_o, "o", test_s_target_primitive_o);
    test_assert(o != NULL);
    test_assert(corto_check_attr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_sourceof(o) == NULL);

    corto_rw rw = corto_rw_init(test_s_target_primitive_o, o);
    test_assert(corto_rw_push(&rw, false) == 0);
    test_assert(corto_rw_next(&rw) == 0);
    test_assert(corto_rw_push(&rw, false) == 0);
    test_assert(corto_rw_field(&rw, "actual") == 0);
    test_assert(corto_rw_set_int(&rw, 10) == 0);
    test_assert(corto_rw_pop(&rw) == 0);
    test_assert(corto_rw_pop(&rw) == 0);
    corto_rw_deinit(&rw);

    test_assertint(o->m->actual, 10);
    test_assertint(o->m->target, 0);
    test_assertint(o->m->objective, 0);

    test_assert(corto_delete(o) == 0);
}

void test_rw_target_tc_reference(
    test_rw_target this)
{
    test_s_target_reference *o = corto_create(root_o, "o", test_s_target_reference_o);
    test_assert(o != NULL);
    test_assert(corto_check_attr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_sourceof(o) == NULL);

    corto_rw rw = corto_rw_init(test_s_target_reference_o, o);
    test_assert(corto_rw_push(&rw, false) == 0);
    test_assert(corto_rw_next(&rw) == 0);
    test_assert(corto_rw_push(&rw, false) == 0);
    test_assert(corto_rw_field(&rw, "actual") == 0);
    test_assert(corto_rw_set_ref(&rw, corto_lang_o) == 0);
    test_assert(corto_rw_pop(&rw) == 0);
    test_assert(corto_rw_pop(&rw) == 0);
    corto_rw_deinit(&rw);

    test_assertref(o->m->actual, corto_lang_o);
    test_assertref(o->m->target, NULL);
    test_assertref(o->m->objective, NULL);

    test_assert(corto_delete(o) == 0);
}

void test_rw_target_tc_collection(
    test_rw_target this)
{
    test_s_target_collection *o = corto_create(root_o, "o", test_s_target_collection_o);
    test_assert(o != NULL);
    test_assert(corto_check_attr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_sourceof(o) == NULL);

    corto_rw rw = corto_rw_init(test_s_target_collection_o, o);
    test_assert(corto_rw_push(&rw, false) == 0);
    test_assert(corto_rw_next(&rw) == 0);
    test_assert(corto_rw_push(&rw, false) == 0);
    test_assert(corto_rw_field(&rw, "actual") == 0);
    test_assert(corto_rw_push(&rw, true) == 0);
    test_assert(corto_rw_set_int(&rw, 10) == 0);
    test_assert(corto_rw_next(&rw) == 0);
    test_assert(corto_rw_set_int(&rw, 20) == 0);
    test_assert(corto_rw_next(&rw) == 0);
    test_assert(corto_rw_set_int(&rw, 30) == 0);
    test_assert(corto_rw_pop(&rw) == 0);
    test_assert(corto_rw_pop(&rw) == 0);
    test_assert(corto_rw_pop(&rw) == 0);
    corto_rw_deinit(&rw);

    test_assert(o->m->actual != NULL);
    test_assertint(corto_ll_count(o->m->actual), 3);
    test_assertint((uintptr_t)corto_ll_get(o->m->actual, 0), 10);
    test_assertint((uintptr_t)corto_ll_get(o->m->actual, 1), 20);
    test_assertint((uintptr_t)corto_ll_get(o->m->actual, 2), 30);
    test_assert(o->m->target != NULL);
    test_assertint(corto_ll_count(o->m->target), 0);
    test_assert(o->m->objective != NULL);
    test_assertint(corto_ll_count(o->m->objective), 0);

    test_assert(corto_delete(o) == 0);
}

void test_rw_target_tc_composite(
    test_rw_target this)
{
    test_s_target_composite *o = corto_create(root_o, "o", test_s_target_composite_o);
    test_assert(o != NULL);
    test_assert(corto_check_attr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_sourceof(o) == NULL);

    corto_rw rw = corto_rw_init(test_s_target_composite_o, o);
    test_assert(corto_rw_push(&rw, false) == 0);
    test_assert(corto_rw_next(&rw) == 0);
    test_assert(corto_rw_push(&rw, false) == 0);
    test_assert(corto_rw_field(&rw, "actual") == 0);
    test_assert(corto_rw_push(&rw, false) == 0);
    test_assert(corto_rw_set_int(&rw, 10) == 0);
    test_assert(corto_rw_next(&rw) == 0);
    test_assert(corto_rw_set_int(&rw, 20) == 0);
    test_assert(corto_rw_pop(&rw) == 0);
    test_assert(corto_rw_pop(&rw) == 0);
    test_assert(corto_rw_pop(&rw) == 0);
    corto_rw_deinit(&rw);

    test_assertint(o->m->actual.x, 10);
    test_assertint(o->m->actual.y, 20);
    test_assertint(o->m->target.x, 0);
    test_assertint(o->m->target.y, 0);
    test_assertint(o->m->objective.x, 0);
    test_assertint(o->m->objective.y, 0);

    test_assert(corto_delete(o) == 0);
}

void test_rw_target_tc_objective_app_from_app(
    test_rw_target this)
{
    /* Create object from app source */
    corto_set_source(NULL);
    test_s_target_primitive *o = corto_create(root_o, "o", test_s_target_primitive_o);
    test_assert(o != NULL);
    test_assert(corto_check_attr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_sourceof(o) == NULL);

    /* Set objective from app */
    corto_set_source(NULL);
    corto_rw rw = corto_rw_init(test_s_target_primitive_o, o);
    test_assert(corto_rw_push(&rw, false) == 0);
    test_assert(corto_rw_field(&rw, "m.objective") == 0);
    test_assert(corto_rw_set_int(&rw, 10) == 0);
    test_assert(corto_rw_pop(&rw) == 0);
    corto_rw_deinit(&rw);

    test_assertint(o->m->actual, 0);
    test_assertint(o->m->target, 0);
    test_assertint(o->m->objective, 10);

    test_assert(corto_delete(o) == 0);
}

void test_rw_target_tc_objective_app_from_local(
    test_rw_target this)
{
    /* Create mount that serves up local objects */
    corto_mount local = corto_declare(NULL, NULL, corto_mount_o);
    test_assert(local != NULL);
    local->ownership = CORTO_LOCAL_SOURCE;
    test_assert(corto_define(local) == 0);

    /* Create object from app source */
    corto_set_source(NULL);
    test_s_target_primitive *o = corto_create(root_o, "o", test_s_target_primitive_o);
    test_assert(o != NULL);
    test_assert(corto_check_attr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_sourceof(o) == NULL);

    /* Set objective from local */
    corto_set_source(local);
    corto_rw rw = corto_rw_init(test_s_target_primitive_o, o);
    test_assert(corto_rw_push(&rw, false) == 0);
    test_assert(corto_rw_field(&rw, "m.objective") == 0);
    test_assert(corto_rw_set_int(&rw, 10) == 0);
    test_assert(corto_rw_pop(&rw) == 0);
    corto_rw_deinit(&rw);

    test_assertint(o->m->actual, 0);
    test_assertint(o->m->target, 0);
    test_assertint(o->m->objective, 10);

    /* Reset source */
    corto_set_source(NULL);

    test_assert(corto_delete(o) == 0);
    test_assert(corto_delete(local) == 0);
}

void test_rw_target_tc_objective_app_from_remote(
    test_rw_target this)
{
    /* Create mount that serves up local objects */
    corto_mount remote = corto_declare(NULL, NULL, corto_mount_o);
    test_assert(remote != NULL);
    remote->ownership = CORTO_REMOTE_SOURCE;
    test_assert(corto_define(remote) == 0);

    /* Create object from app source */
    corto_set_source(NULL);
    test_s_target_primitive *o = corto_create(root_o, "o", test_s_target_primitive_o);
    test_assert(o != NULL);
    test_assert(corto_check_attr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_sourceof(o) == NULL);

    /* Set objective from remote (will fail) */
    corto_set_source(remote);
    corto_rw rw = corto_rw_init(test_s_target_primitive_o, o);
    test_assert(corto_rw_push(&rw, false) == 0);
    test_assert(corto_rw_field(&rw, "m.objective") == 0);
    test_assert(corto_rw_set_int(&rw, 10) != 0);
    test_assert(corto_catch() != 0);
    test_assert(corto_rw_pop(&rw) == 0);
    corto_rw_deinit(&rw);

    test_assertint(o->m->actual, 0);
    test_assertint(o->m->target, 0);
    test_assertint(o->m->objective, 0);

    /* Reset source */
    corto_set_source(NULL);

    test_assert(corto_delete(o) == 0);
    test_assert(corto_delete(remote) == 0);
}

void test_rw_target_tc_objective_local_from_app(
    test_rw_target this)
{
    /* Create mount that serves up local objects */
    corto_mount local = corto_declare(NULL, NULL, corto_mount_o);
    test_assert(local != NULL);
    local->ownership = CORTO_LOCAL_SOURCE;
    test_assert(corto_define(local) == 0);

    /* Create object from local source */
    corto_set_source(local);
    test_s_target_primitive *o = corto_create(root_o, "o", test_s_target_primitive_o);
    test_assert(o != NULL);
    test_assert(corto_check_attr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_sourceof(o) == local);

    /* Set objective from app */
    corto_set_source(NULL);
    corto_rw rw = corto_rw_init(test_s_target_primitive_o, o);
    test_assert(corto_rw_push(&rw, false) == 0);
    test_assert(corto_rw_field(&rw, "m.objective") == 0);
    test_assert(corto_rw_set_int(&rw, 10) == 0);
    test_assert(corto_rw_pop(&rw) == 0);
    corto_rw_deinit(&rw);

    test_assertint(o->m->actual, 0);
    test_assertint(o->m->target, 0);
    test_assertint(o->m->objective, 10);

    /* Reset source */
    corto_set_source(NULL);

    test_assert(corto_delete(o) == 0);
    test_assert(corto_delete(local) == 0);
}

void test_rw_target_tc_objective_local_from_local(
    test_rw_target this)
{
    /* Create mount that serves up local objects */
    corto_mount local = corto_declare(NULL, NULL, corto_mount_o);
    test_assert(local != NULL);
    local->ownership = CORTO_LOCAL_SOURCE;
    test_assert(corto_define(local) == 0);

    /* Create object from local source */
    corto_set_source(local);
    test_s_target_primitive *o = corto_create(root_o, "o", test_s_target_primitive_o);
    test_assert(o != NULL);
    test_assert(corto_check_attr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_sourceof(o) == local);

    corto_rw rw = corto_rw_init(test_s_target_primitive_o, o);
    test_assert(corto_rw_push(&rw, false) == 0);
    test_assert(corto_rw_field(&rw, "m.objective") == 0);
    test_assert(corto_rw_set_int(&rw, 10) == 0);
    test_assert(corto_rw_pop(&rw) == 0);
    corto_rw_deinit(&rw);

    test_assertint(o->m->actual, 0);
    test_assertint(o->m->target, 0);
    test_assertint(o->m->objective, 10);

    /* Reset source */
    corto_set_source(NULL);

    test_assert(corto_delete(o) == 0);
    test_assert(corto_delete(local) == 0);
}

void test_rw_target_tc_objective_local_from_remote(
    test_rw_target this)
{
    /* Create mount that serves up local objects */
    corto_mount local = corto_declare(NULL, NULL, corto_mount_o);
    test_assert(local != NULL);
    local->ownership = CORTO_LOCAL_SOURCE;
    test_assert(corto_define(local) == 0);

    /* Create mount that serves up remote objects */
    corto_mount remote = corto_declare(NULL, NULL, corto_mount_o);
    test_assert(remote != NULL);
    remote->ownership = CORTO_REMOTE_SOURCE;
    test_assert(corto_define(remote) == 0);

    /* Create object from local source */
    corto_set_source(local);
    test_s_target_primitive *o = corto_create(root_o, "o", test_s_target_primitive_o);
    test_assert(o != NULL);
    test_assert(corto_check_attr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_sourceof(o) == local);

    /* Set objective from remote */
    corto_set_source(remote);
    corto_rw rw = corto_rw_init(test_s_target_primitive_o, o);
    test_assert(corto_rw_push(&rw, false) == 0);
    test_assert(corto_rw_field(&rw, "m.objective") == 0);
    test_assert(corto_rw_set_int(&rw, 10) != 0);
    test_assert(corto_catch() != 0);
    test_assert(corto_rw_pop(&rw) == 0);
    corto_rw_deinit(&rw);

    test_assertint(o->m->actual, 0);
    test_assertint(o->m->target, 0);
    test_assertint(o->m->objective, 0);

    /* Reset source */
    corto_set_source(NULL);

    test_assert(corto_delete(o) == 0);
    test_assert(corto_delete(local) == 0);
    test_assert(corto_delete(remote) == 0);
}

void test_rw_target_tc_objective_remote_from_app(
    test_rw_target this)
{
    /* Create mount that serves up remote objects */
    corto_mount remote = corto_declare(NULL, NULL, corto_mount_o);
    test_assert(remote != NULL);
    remote->ownership = CORTO_REMOTE_SOURCE;
    test_assert(corto_define(remote) == 0);

    /* Create object from remote source */
    corto_set_source(remote);
    test_s_target_primitive *o = corto_create(root_o, "o", test_s_target_primitive_o);
    test_assert(o != NULL);
    test_assert(corto_check_attr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_sourceof(o) == remote);

    /* Set objective from app */
    corto_set_source(NULL);
    corto_rw rw = corto_rw_init(test_s_target_primitive_o, o);
    test_assert(corto_rw_push(&rw, false) == 0);
    test_assert(corto_rw_field(&rw, "m.objective") == 0);
    test_assert(corto_rw_set_int(&rw, 10) != 0);
    test_assert(corto_catch() != 0);
    test_assert(corto_rw_pop(&rw) == 0);
    corto_rw_deinit(&rw);

    test_assertint(o->m->actual, 0);
    test_assertint(o->m->target, 0);
    test_assertint(o->m->objective, 0);

    corto_set_source(remote);
    test_assert(corto_delete(o) == 0);

    /* Reset source */
    corto_set_source(NULL);
    test_assert(corto_delete(remote) == 0);
}

void test_rw_target_tc_objective_remote_from_local(
    test_rw_target this)
{
    /* Create mount that serves up local objects */
    corto_mount local = corto_declare(NULL, NULL, corto_mount_o);
    test_assert(local != NULL);
    local->ownership = CORTO_LOCAL_SOURCE;
    test_assert(corto_define(local) == 0);

    /* Create mount that serves up remote objects */
    corto_mount remote = corto_declare(NULL, NULL, corto_mount_o);
    test_assert(remote != NULL);
    remote->ownership = CORTO_REMOTE_SOURCE;
    test_assert(corto_define(remote) == 0);

    /* Create object from remote source */
    corto_set_source(remote);
    test_s_target_primitive *o = corto_create(root_o, "o", test_s_target_primitive_o);
    test_assert(o != NULL);
    test_assert(corto_check_attr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_sourceof(o) == remote);

    /* Set objective from app */
    corto_set_source(local);
    corto_rw rw = corto_rw_init(test_s_target_primitive_o, o);
    test_assert(corto_rw_push(&rw, false) == 0);
    test_assert(corto_rw_field(&rw, "m.objective") == 0);
    test_assert(corto_rw_set_int(&rw, 10) != 0);
    test_assert(corto_catch() != 0);
    test_assert(corto_rw_pop(&rw) == 0);
    corto_rw_deinit(&rw);

    test_assertint(o->m->actual, 0);
    test_assertint(o->m->target, 0);
    test_assertint(o->m->objective, 0);

    corto_set_source(remote);
    test_assert(corto_delete(o) == 0);

    /* Reset source */
    corto_set_source(NULL);
    test_assert(corto_delete(local) == 0);
    test_assert(corto_delete(remote) == 0);
}

void test_rw_target_tc_objective_remote_from_remote(
    test_rw_target this)
{
    /* Create mount that serves up remote objects */
    corto_mount remote = corto_declare(NULL, NULL, corto_mount_o);
    test_assert(remote != NULL);
    remote->ownership = CORTO_REMOTE_SOURCE;
    test_assert(corto_define(remote) == 0);

    /* Create object from remote source */
    corto_set_source(remote);
    test_s_target_primitive *o = corto_create(root_o, "o", test_s_target_primitive_o);
    test_assert(o != NULL);
    test_assert(corto_check_attr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_sourceof(o) == remote);

    corto_rw rw = corto_rw_init(test_s_target_primitive_o, o);
    test_assert(corto_rw_push(&rw, false) == 0);
    test_assert(corto_rw_field(&rw, "m.objective") == 0);
    test_assert(corto_rw_set_int(&rw, 10) == 0);
    test_assert(corto_rw_pop(&rw) == 0);
    corto_rw_deinit(&rw);

    test_assertint(o->m->actual, 0);
    test_assertint(o->m->target, 0);
    test_assertint(o->m->objective, 10);

    test_assert(corto_delete(o) == 0);

    /* Reset source */
    corto_set_source(NULL);
    test_assert(corto_delete(remote) == 0);
}

void test_rw_target_tc_actual_app_from_app(
    test_rw_target this)
{
    /* Create object from app source */
    corto_set_source(NULL);
    test_s_target_primitive *o = corto_create(root_o, "o", test_s_target_primitive_o);
    test_assert(o != NULL);
    test_assert(corto_check_attr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_sourceof(o) == NULL);

    /* Set actual from app */
    corto_set_source(NULL);
    corto_rw rw = corto_rw_init(test_s_target_primitive_o, o);
    test_assert(corto_rw_push(&rw, false) == 0);
    test_assert(corto_rw_field(&rw, "m.actual") == 0);
    test_assert(corto_rw_set_int(&rw, 10) == 0);
    test_assert(corto_rw_pop(&rw) == 0);
    corto_rw_deinit(&rw);

    test_assertint(o->m->objective, 0);
    test_assertint(o->m->target, 0);
    test_assertint(o->m->actual, 10);

    test_assert(corto_delete(o) == 0);
}

void test_rw_target_tc_actual_app_from_local(
    test_rw_target this)
{
    /* Create mount that serves up local objects */
    corto_mount local = corto_declare(NULL, NULL, corto_mount_o);
    test_assert(local != NULL);
    local->ownership = CORTO_LOCAL_SOURCE;
    test_assert(corto_define(local) == 0);

    /* Create object from app source */
    corto_set_source(NULL);
    test_s_target_primitive *o = corto_create(root_o, "o", test_s_target_primitive_o);
    test_assert(o != NULL);
    test_assert(corto_check_attr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_sourceof(o) == NULL);

    /* Set actual from local */
    corto_set_source(local);
    corto_rw rw = corto_rw_init(test_s_target_primitive_o, o);
    test_assert(corto_rw_push(&rw, false) == 0);
    test_assert(corto_rw_field(&rw, "m.actual") == 0);
    test_assert(corto_rw_set_int(&rw, 10) == 0);
    test_assert(corto_rw_pop(&rw) == 0);
    corto_rw_deinit(&rw);

    test_assertint(o->m->objective, 0);
    test_assertint(o->m->target, 0);
    test_assertint(o->m->actual, 10);

    /* Reset source */
    corto_set_source(NULL);

    test_assert(corto_delete(o) == 0);
    test_assert(corto_delete(local) == 0);
}

void test_rw_target_tc_actual_app_from_remote(
    test_rw_target this)
{
    /* Create mount that serves up local objects */
    corto_mount remote = corto_declare(NULL, NULL, corto_mount_o);
    test_assert(remote != NULL);
    remote->ownership = CORTO_REMOTE_SOURCE;
    test_assert(corto_define(remote) == 0);

    /* Create object from app source */
    corto_set_source(NULL);
    test_s_target_primitive *o = corto_create(root_o, "o", test_s_target_primitive_o);
    test_assert(o != NULL);
    test_assert(corto_check_attr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_sourceof(o) == NULL);

    /* Set actual from remote (will fail) */
    corto_set_source(remote);
    corto_rw rw = corto_rw_init(test_s_target_primitive_o, o);
    test_assert(corto_rw_push(&rw, false) == 0);
    test_assert(corto_rw_field(&rw, "m.actual") == 0);
    test_assert(corto_rw_set_int(&rw, 10) != 0);
    test_assert(corto_catch() != 0);
    test_assert(corto_rw_pop(&rw) == 0);
    corto_rw_deinit(&rw);

    test_assertint(o->m->objective, 0);
    test_assertint(o->m->target, 0);
    test_assertint(o->m->actual, 0);

    /* Reset source */
    corto_set_source(NULL);

    test_assert(corto_delete(o) == 0);
    test_assert(corto_delete(remote) == 0);
}

void test_rw_target_tc_actual_local_from_app(
    test_rw_target this)
{
    /* Create mount that serves up local objects */
    corto_mount local = corto_declare(NULL, NULL, corto_mount_o);
    test_assert(local != NULL);
    local->ownership = CORTO_LOCAL_SOURCE;
    test_assert(corto_define(local) == 0);

    /* Create object from local source */
    corto_set_source(local);
    test_s_target_primitive *o = corto_create(root_o, "o", test_s_target_primitive_o);
    test_assert(o != NULL);
    test_assert(corto_check_attr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_sourceof(o) == local);

    /* Set actual from app */
    corto_set_source(NULL);
    corto_rw rw = corto_rw_init(test_s_target_primitive_o, o);
    test_assert(corto_rw_push(&rw, false) == 0);
    test_assert(corto_rw_field(&rw, "m.actual") == 0);
    test_assert(corto_rw_set_int(&rw, 10) == 0);
    test_assert(corto_rw_pop(&rw) == 0);
    corto_rw_deinit(&rw);

    test_assertint(o->m->objective, 0);
    test_assertint(o->m->target, 0);
    test_assertint(o->m->actual, 10);

    /* Reset source */
    corto_set_source(NULL);

    test_assert(corto_delete(o) == 0);
    test_assert(corto_delete(local) == 0);
}

void test_rw_target_tc_actual_local_from_local(
    test_rw_target this)
{
    /* Create mount that serves up local objects */
    corto_mount local = corto_declare(NULL, NULL, corto_mount_o);
    test_assert(local != NULL);
    local->ownership = CORTO_LOCAL_SOURCE;
    test_assert(corto_define(local) == 0);

    /* Create object from local source */
    corto_set_source(local);
    test_s_target_primitive *o = corto_create(root_o, "o", test_s_target_primitive_o);
    test_assert(o != NULL);
    test_assert(corto_check_attr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_sourceof(o) == local);

    corto_rw rw = corto_rw_init(test_s_target_primitive_o, o);
    test_assert(corto_rw_push(&rw, false) == 0);
    test_assert(corto_rw_field(&rw, "m.actual") == 0);
    test_assert(corto_rw_set_int(&rw, 10) == 0);
    test_assert(corto_rw_pop(&rw) == 0);
    corto_rw_deinit(&rw);

    test_assertint(o->m->objective, 0);
    test_assertint(o->m->target, 0);
    test_assertint(o->m->actual, 10);

    /* Reset source */
    corto_set_source(NULL);

    test_assert(corto_delete(o) == 0);
    test_assert(corto_delete(local) == 0);
}

void test_rw_target_tc_actual_local_from_remote(
    test_rw_target this)
{
    /* Create mount that serves up local objects */
    corto_mount local = corto_declare(NULL, NULL, corto_mount_o);
    test_assert(local != NULL);
    local->ownership = CORTO_LOCAL_SOURCE;
    test_assert(corto_define(local) == 0);

    /* Create mount that serves up remote objects */
    corto_mount remote = corto_declare(NULL, NULL, corto_mount_o);
    test_assert(remote != NULL);
    remote->ownership = CORTO_REMOTE_SOURCE;
    test_assert(corto_define(remote) == 0);

    /* Create object from local source */
    corto_set_source(local);
    test_s_target_primitive *o = corto_create(root_o, "o", test_s_target_primitive_o);
    test_assert(o != NULL);
    test_assert(corto_check_attr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_sourceof(o) == local);

    /* Set actual from remote */
    corto_set_source(remote);
    corto_rw rw = corto_rw_init(test_s_target_primitive_o, o);
    test_assert(corto_rw_push(&rw, false) == 0);
    test_assert(corto_rw_field(&rw, "m.actual") == 0);
    test_assert(corto_rw_set_int(&rw, 10) != 0);
    test_assert(corto_catch() != 0);
    test_assert(corto_rw_pop(&rw) == 0);
    corto_rw_deinit(&rw);

    test_assertint(o->m->objective, 0);
    test_assertint(o->m->target, 0);
    test_assertint(o->m->actual, 0);

    /* Reset source */
    corto_set_source(NULL);

    test_assert(corto_delete(o) == 0);
    test_assert(corto_delete(local) == 0);
    test_assert(corto_delete(remote) == 0);
}

void test_rw_target_tc_actual_remote_from_app(
    test_rw_target this)
{
    /* Create mount that serves up remote objects */
    corto_mount remote = corto_declare(NULL, NULL, corto_mount_o);
    test_assert(remote != NULL);
    remote->ownership = CORTO_REMOTE_SOURCE;
    test_assert(corto_define(remote) == 0);

    /* Create object from remote source */
    corto_set_source(remote);
    test_s_target_primitive *o = corto_create(root_o, "o", test_s_target_primitive_o);
    test_assert(o != NULL);
    test_assert(corto_check_attr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_sourceof(o) == remote);

    /* Set actual from app */
    corto_set_source(NULL);
    corto_rw rw = corto_rw_init(test_s_target_primitive_o, o);
    test_assert(corto_rw_push(&rw, false) == 0);
    test_assert(corto_rw_field(&rw, "m.actual") == 0);
    test_assert(corto_rw_set_int(&rw, 10) != 0);
    test_assert(corto_catch() != 0);
    test_assert(corto_rw_pop(&rw) == 0);
    corto_rw_deinit(&rw);

    test_assertint(o->m->objective, 0);
    test_assertint(o->m->target, 0);
    test_assertint(o->m->actual, 0);

    corto_set_source(remote);
    test_assert(corto_delete(o) == 0);

    /* Reset source */
    corto_set_source(NULL);
    test_assert(corto_delete(remote) == 0);
}

void test_rw_target_tc_actual_remote_from_local(
    test_rw_target this)
{
    /* Create mount that serves up local objects */
    corto_mount local = corto_declare(NULL, NULL, corto_mount_o);
    test_assert(local != NULL);
    local->ownership = CORTO_LOCAL_SOURCE;
    test_assert(corto_define(local) == 0);

    /* Create mount that serves up remote objects */
    corto_mount remote = corto_declare(NULL, NULL, corto_mount_o);
    test_assert(remote != NULL);
    remote->ownership = CORTO_REMOTE_SOURCE;
    test_assert(corto_define(remote) == 0);

    /* Create object from remote source */
    corto_set_source(remote);
    test_s_target_primitive *o = corto_create(root_o, "o", test_s_target_primitive_o);
    test_assert(o != NULL);
    test_assert(corto_check_attr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_sourceof(o) == remote);

    /* Set actual from app */
    corto_set_source(local);
    corto_rw rw = corto_rw_init(test_s_target_primitive_o, o);
    test_assert(corto_rw_push(&rw, false) == 0);
    test_assert(corto_rw_field(&rw, "m.actual") == 0);
    test_assert(corto_rw_set_int(&rw, 10) != 0);
    test_assert(corto_catch() != 0);
    test_assert(corto_rw_pop(&rw) == 0);
    corto_rw_deinit(&rw);

    test_assertint(o->m->objective, 0);
    test_assertint(o->m->target, 0);
    test_assertint(o->m->actual, 0);

    corto_set_source(remote);
    test_assert(corto_delete(o) == 0);

    /* Reset source */
    corto_set_source(NULL);
    test_assert(corto_delete(local) == 0);
    test_assert(corto_delete(remote) == 0);
}

void test_rw_target_tc_actual_remote_from_remote(
    test_rw_target this)
{
    /* Create mount that serves up remote objects */
    corto_mount remote = corto_declare(NULL, NULL, corto_mount_o);
    test_assert(remote != NULL);
    remote->ownership = CORTO_REMOTE_SOURCE;
    test_assert(corto_define(remote) == 0);

    /* Create object from remote source */
    corto_set_source(remote);
    test_s_target_primitive *o = corto_create(root_o, "o", test_s_target_primitive_o);
    test_assert(o != NULL);
    test_assert(corto_check_attr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_sourceof(o) == remote);

    corto_rw rw = corto_rw_init(test_s_target_primitive_o, o);
    test_assert(corto_rw_push(&rw, false) == 0);
    test_assert(corto_rw_field(&rw, "m.actual") == 0);
    test_assert(corto_rw_set_int(&rw, 10) == 0);
    test_assert(corto_rw_pop(&rw) == 0);
    corto_rw_deinit(&rw);

    test_assertint(o->m->objective, 0);
    test_assertint(o->m->target, 0);
    test_assertint(o->m->actual, 10);

    test_assert(corto_delete(o) == 0);

    /* Reset source */
    corto_set_source(NULL);
    test_assert(corto_delete(remote) == 0);
}

void test_rw_target_tc_target_app_from_app(
    test_rw_target this)
{
    /* Create object from app source */
    corto_set_source(NULL);
    test_s_target_primitive *o = corto_create(root_o, "o", test_s_target_primitive_o);
    test_assert(o != NULL);
    test_assert(corto_check_attr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_sourceof(o) == NULL);

    /* Set target from app */
    corto_set_source(NULL);
    corto_rw rw = corto_rw_init(test_s_target_primitive_o, o);
    test_assert(corto_rw_push(&rw, false) == 0);
    test_assert(corto_rw_field(&rw, "m.target") == 0);
    test_assert(corto_rw_set_int(&rw, 10) != 0);
    test_assert(corto_catch() != 0);
    test_assert(corto_rw_pop(&rw) == 0);
    corto_rw_deinit(&rw);

    test_assertint(o->m->objective, 0);
    test_assertint(o->m->actual, 0);
    test_assertint(o->m->target, 0);

    test_assert(corto_delete(o) == 0);
}

void test_rw_target_tc_target_app_from_local(
    test_rw_target this)
{
    /* Create mount that serves up local objects */
    corto_mount local = corto_declare(NULL, NULL, corto_mount_o);
    test_assert(local != NULL);
    local->ownership = CORTO_LOCAL_SOURCE;
    test_assert(corto_define(local) == 0);

    /* Create object from app source */
    corto_set_source(NULL);
    test_s_target_primitive *o = corto_create(root_o, "o", test_s_target_primitive_o);
    test_assert(o != NULL);
    test_assert(corto_check_attr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_sourceof(o) == NULL);

    /* Set target from local */
    corto_set_source(local);
    corto_rw rw = corto_rw_init(test_s_target_primitive_o, o);
    test_assert(corto_rw_push(&rw, false) == 0);
    test_assert(corto_rw_field(&rw, "m.target") == 0);
    test_assert(corto_rw_set_int(&rw, 10) != 0);
    test_assert(corto_catch() != 0);
    test_assert(corto_rw_pop(&rw) == 0);
    corto_rw_deinit(&rw);

    test_assertint(o->m->objective, 0);
    test_assertint(o->m->actual, 0);
    test_assertint(o->m->target, 0);

    /* Reset source */
    corto_set_source(NULL);

    test_assert(corto_delete(o) == 0);
    test_assert(corto_delete(local) == 0);
}

void test_rw_target_tc_target_app_from_remote(
    test_rw_target this)
{
    /* Create mount that serves up local objects */
    corto_mount remote = corto_declare(NULL, NULL, corto_mount_o);
    test_assert(remote != NULL);
    remote->ownership = CORTO_REMOTE_SOURCE;
    test_assert(corto_define(remote) == 0);

    /* Create object from app source */
    corto_set_source(NULL);
    test_s_target_primitive *o = corto_create(root_o, "o", test_s_target_primitive_o);
    test_assert(o != NULL);
    test_assert(corto_check_attr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_sourceof(o) == NULL);

    /* Set target from remote (will fail) */
    corto_set_source(remote);
    corto_rw rw = corto_rw_init(test_s_target_primitive_o, o);
    test_assert(corto_rw_push(&rw, false) == 0);
    test_assert(corto_rw_field(&rw, "m.target") == 0);
    test_assert(corto_rw_set_int(&rw, 10) == 0);
    test_assert(corto_rw_pop(&rw) == 0);
    corto_rw_deinit(&rw);

    test_assertint(o->m->objective, 0);
    test_assertint(o->m->actual, 0);
    test_assertint(o->m->target, 10);

    /* Reset source */
    corto_set_source(NULL);

    test_assert(corto_delete(o) == 0);
    test_assert(corto_delete(remote) == 0);
}

void test_rw_target_tc_target_local_from_app(
    test_rw_target this)
{
    /* Create mount that serves up local objects */
    corto_mount local = corto_declare(NULL, NULL, corto_mount_o);
    test_assert(local != NULL);
    local->ownership = CORTO_LOCAL_SOURCE;
    test_assert(corto_define(local) == 0);

    /* Create object from local source */
    corto_set_source(local);
    test_s_target_primitive *o = corto_create(root_o, "o", test_s_target_primitive_o);
    test_assert(o != NULL);
    test_assert(corto_check_attr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_sourceof(o) == local);

    /* Set target from app */
    corto_set_source(NULL);
    corto_rw rw = corto_rw_init(test_s_target_primitive_o, o);
    test_assert(corto_rw_push(&rw, false) == 0);
    test_assert(corto_rw_field(&rw, "m.target") == 0);
    test_assert(corto_rw_set_int(&rw, 10) != 0);
    test_assert(corto_catch() != 0);
    test_assert(corto_rw_pop(&rw) == 0);
    corto_rw_deinit(&rw);

    test_assertint(o->m->objective, 0);
    test_assertint(o->m->actual, 0);
    test_assertint(o->m->target, 0);

    /* Reset source */
    corto_set_source(NULL);

    test_assert(corto_delete(o) == 0);
    test_assert(corto_delete(local) == 0);
}

void test_rw_target_tc_target_local_from_local(
    test_rw_target this)
{
    /* Create mount that serves up local objects */
    corto_mount local = corto_declare(NULL, NULL, corto_mount_o);
    test_assert(local != NULL);
    local->ownership = CORTO_LOCAL_SOURCE;
    test_assert(corto_define(local) == 0);

    /* Create object from local source */
    corto_set_source(local);
    test_s_target_primitive *o = corto_create(root_o, "o", test_s_target_primitive_o);
    test_assert(o != NULL);
    test_assert(corto_check_attr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_sourceof(o) == local);

    corto_rw rw = corto_rw_init(test_s_target_primitive_o, o);
    test_assert(corto_rw_push(&rw, false) == 0);
    test_assert(corto_rw_field(&rw, "m.target") == 0);
    test_assert(corto_rw_set_int(&rw, 10) != 0);
    test_assert(corto_catch() != 0);
    test_assert(corto_rw_pop(&rw) == 0);
    corto_rw_deinit(&rw);

    test_assertint(o->m->objective, 0);
    test_assertint(o->m->actual, 0);
    test_assertint(o->m->target, 0);

    /* Reset source */
    corto_set_source(NULL);

    test_assert(corto_delete(o) == 0);
    test_assert(corto_delete(local) == 0);
}

void test_rw_target_tc_target_local_from_remote(
    test_rw_target this)
{
    /* Create mount that serves up local objects */
    corto_mount local = corto_declare(NULL, NULL, corto_mount_o);
    test_assert(local != NULL);
    local->ownership = CORTO_LOCAL_SOURCE;
    test_assert(corto_define(local) == 0);

    /* Create mount that serves up remote objects */
    corto_mount remote = corto_declare(NULL, NULL, corto_mount_o);
    test_assert(remote != NULL);
    remote->ownership = CORTO_REMOTE_SOURCE;
    test_assert(corto_define(remote) == 0);

    /* Create object from local source */
    corto_set_source(local);
    test_s_target_primitive *o = corto_create(root_o, "o", test_s_target_primitive_o);
    test_assert(o != NULL);
    test_assert(corto_check_attr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_sourceof(o) == local);

    /* Set target from remote */
    corto_set_source(remote);
    corto_rw rw = corto_rw_init(test_s_target_primitive_o, o);
    test_assert(corto_rw_push(&rw, false) == 0);
    test_assert(corto_rw_field(&rw, "m.target") == 0);
    test_assert(corto_rw_set_int(&rw, 10) == 0);
    test_assert(corto_rw_pop(&rw) == 0);
    corto_rw_deinit(&rw);

    test_assertint(o->m->objective, 0);
    test_assertint(o->m->actual, 0);
    test_assertint(o->m->target, 10);

    /* Reset source */
    corto_set_source(NULL);

    test_assert(corto_delete(o) == 0);
    test_assert(corto_delete(local) == 0);
    test_assert(corto_delete(remote) == 0);
}

void test_rw_target_tc_target_remote_from_app(
    test_rw_target this)
{
    /* Create mount that serves up remote objects */
    corto_mount remote = corto_declare(NULL, NULL, corto_mount_o);
    test_assert(remote != NULL);
    remote->ownership = CORTO_REMOTE_SOURCE;
    test_assert(corto_define(remote) == 0);

    /* Create object from remote source */
    corto_set_source(remote);
    test_s_target_primitive *o = corto_create(root_o, "o", test_s_target_primitive_o);
    test_assert(o != NULL);
    test_assert(corto_check_attr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_sourceof(o) == remote);

    /* Set target from app */
    corto_set_source(NULL);
    corto_rw rw = corto_rw_init(test_s_target_primitive_o, o);
    test_assert(corto_rw_push(&rw, false) == 0);
    test_assert(corto_rw_field(&rw, "m.target") == 0);
    test_assert(corto_rw_set_int(&rw, 10) == 0);
    test_assert(corto_rw_pop(&rw) == 0);
    corto_rw_deinit(&rw);

    test_assertint(o->m->objective, 0);
    test_assertint(o->m->actual, 0);
    test_assertint(o->m->target, 10);

    corto_set_source(remote);
    test_assert(corto_delete(o) == 0);

    /* Reset source */
    corto_set_source(NULL);
    test_assert(corto_delete(remote) == 0);
}

void test_rw_target_tc_target_remote_from_local(
    test_rw_target this)
{
    /* Create mount that serves up local objects */
    corto_mount local = corto_declare(NULL, NULL, corto_mount_o);
    test_assert(local != NULL);
    local->ownership = CORTO_LOCAL_SOURCE;
    test_assert(corto_define(local) == 0);

    /* Create mount that serves up remote objects */
    corto_mount remote = corto_declare(NULL, NULL, corto_mount_o);
    test_assert(remote != NULL);
    remote->ownership = CORTO_REMOTE_SOURCE;
    test_assert(corto_define(remote) == 0);

    /* Create object from remote source */
    corto_set_source(remote);
    test_s_target_primitive *o = corto_create(root_o, "o", test_s_target_primitive_o);
    test_assert(o != NULL);
    test_assert(corto_check_attr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_sourceof(o) == remote);

    /* Set target from app */
    corto_set_source(local);
    corto_rw rw = corto_rw_init(test_s_target_primitive_o, o);
    test_assert(corto_rw_push(&rw, false) == 0);
    test_assert(corto_rw_field(&rw, "m.target") == 0);
    test_assert(corto_rw_set_int(&rw, 10) == 0);
    test_assert(corto_rw_pop(&rw) == 0);
    corto_rw_deinit(&rw);

    test_assertint(o->m->objective, 0);
    test_assertint(o->m->actual, 0);
    test_assertint(o->m->target, 10);

    corto_set_source(remote);
    test_assert(corto_delete(o) == 0);

    /* Reset source */
    corto_set_source(NULL);
    test_assert(corto_delete(local) == 0);
    test_assert(corto_delete(remote) == 0);
}

void test_rw_target_tc_target_remote_from_remote(
    test_rw_target this)
{
    /* Create mount that serves up remote objects */
    corto_mount remote = corto_declare(NULL, NULL, corto_mount_o);
    test_assert(remote != NULL);
    remote->ownership = CORTO_REMOTE_SOURCE;
    test_assert(corto_define(remote) == 0);

    /* Create object from remote source */
    corto_set_source(remote);
    test_s_target_primitive *o = corto_create(root_o, "o", test_s_target_primitive_o);
    test_assert(o != NULL);
    test_assert(corto_check_attr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_sourceof(o) == remote);

    corto_rw rw = corto_rw_init(test_s_target_primitive_o, o);
    test_assert(corto_rw_push(&rw, false) == 0);
    test_assert(corto_rw_field(&rw, "m.target") == 0);
    test_assert(corto_rw_set_int(&rw, 10) != 0);
    test_assert(corto_catch() != 0);
    test_assert(corto_rw_pop(&rw) == 0);
    corto_rw_deinit(&rw);

    test_assertint(o->m->objective, 0);
    test_assertint(o->m->actual, 0);
    test_assertint(o->m->target, 0);

    test_assert(corto_delete(o) == 0);

    /* Reset source */
    corto_set_source(NULL);
    test_assert(corto_delete(remote) == 0);
}

void test_rw_target_tc_actual_after_push(
    test_rw_target this)
{
    test_s_target_primitive *o = corto_create(root_o, "o", test_s_target_primitive_o);
    test_assert(o != NULL);
    test_assert(corto_check_attr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_sourceof(o) == NULL);

    corto_rw rw = corto_rw_init(test_s_target_primitive_o, o);
    test_assert(corto_rw_push(&rw, false) == 0);
    test_assert(corto_rw_next(&rw) == 0);
    test_assert(corto_rw_push(&rw, false) == 0);
    test_assert(corto_rw_field(&rw, "actual") == 0);
    test_assert(corto_rw_set_int(&rw, 10) == 0);
    test_assert(corto_rw_pop(&rw) == 0);
    test_assert(corto_rw_pop(&rw) == 0);
    corto_rw_deinit(&rw);

    test_assertint(o->m->actual, 10);
    test_assertint(o->m->target, 0);
    test_assertint(o->m->objective, 0);

    test_assert(corto_delete(o) == 0);
}

void test_rw_target_tc_objective_after_push(
    test_rw_target this)
{
    test_s_target_primitive *o = corto_create(root_o, "o", test_s_target_primitive_o);
    test_assert(o != NULL);
    test_assert(corto_check_attr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_sourceof(o) == NULL);

    corto_rw rw = corto_rw_init(test_s_target_primitive_o, o);
    test_assert(corto_rw_push(&rw, false) == 0);
    test_assert(corto_rw_next(&rw) == 0);
    test_assert(corto_rw_push(&rw, false) == 0);
    test_assert(corto_rw_field(&rw, "objective") == 0);
    test_assert(corto_rw_set_int(&rw, 10) == 0);
    test_assert(corto_rw_pop(&rw) == 0);
    test_assert(corto_rw_pop(&rw) == 0);
    corto_rw_deinit(&rw);

    test_assertint(o->m->actual, 0);
    test_assertint(o->m->target, 0);
    test_assertint(o->m->objective, 10);

    test_assert(corto_delete(o) == 0);
}

void test_rw_target_tc_target_after_push(
    test_rw_target this)
{
    test_s_target_primitive *o = corto_create(root_o, "o", test_s_target_primitive_o);
    test_assert(o != NULL);
    test_assert(corto_check_attr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_sourceof(o) == NULL);

    /* Create mount that serves up remote objects */
    corto_mount remote = corto_declare(NULL, NULL, corto_mount_o);
    test_assert(remote != NULL);
    remote->ownership = CORTO_REMOTE_SOURCE;
    test_assert(corto_define(remote) == 0);

    corto_set_source(remote);
    corto_rw rw = corto_rw_init(test_s_target_primitive_o, o);
    test_assert(corto_rw_push(&rw, false) == 0);
    test_assert(corto_rw_next(&rw) == 0);
    test_assert(corto_rw_push(&rw, false) == 0);
    test_assert(corto_rw_field(&rw, "target") == 0);
    test_assert(corto_rw_set_int(&rw, 10) == 0);
    test_assert(corto_rw_pop(&rw) == 0);
    test_assert(corto_rw_pop(&rw) == 0);
    corto_rw_deinit(&rw);
    corto_set_source(NULL);

    test_assertint(o->m->actual, 0);
    test_assertint(o->m->target, 10);
    test_assertint(o->m->objective, 0);

    test_assert(corto_delete(o) == 0);
}

void test_rw_target_tc_actual_nested(
    test_rw_target this)
{
    test_s_target_composite *o = corto_create(root_o, "o", test_s_target_composite_o);
    test_assert(o != NULL);
    test_assert(corto_check_attr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_sourceof(o) == NULL);

    corto_rw rw = corto_rw_init(test_s_target_composite_o, o);
    test_assert(corto_rw_push(&rw, false) == 0);
    test_assert(corto_rw_field(&rw, "m.actual.x") == 0);
    test_assert(corto_rw_set_int(&rw, 10) == 0);
    test_assert(corto_rw_field(&rw, "m.actual.y") == 0);
    test_assert(corto_rw_set_int(&rw, 20) == 0);
    test_assert(corto_rw_pop(&rw) == 0);
    corto_rw_deinit(&rw);

    test_assertint(o->m->actual.x, 10);
    test_assertint(o->m->actual.y, 20);
    test_assertint(o->m->target.x, 0);
    test_assertint(o->m->target.y, 0);
    test_assertint(o->m->objective.x, 0);
    test_assertint(o->m->objective.y, 0);

    test_assert(corto_delete(o) == 0);
}

void test_rw_target_tc_objective_nested(
    test_rw_target this)
{
    test_s_target_composite *o = corto_create(root_o, "o", test_s_target_composite_o);
    test_assert(o != NULL);
    test_assert(corto_check_attr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_sourceof(o) == NULL);

    corto_rw rw = corto_rw_init(test_s_target_composite_o, o);
    test_assert(corto_rw_push(&rw, false) == 0);
    test_assert(corto_rw_field(&rw, "m.objective.x") == 0);
    test_assert(corto_rw_set_int(&rw, 10) == 0);
    test_assert(corto_rw_field(&rw, "m.objective.y") == 0);
    test_assert(corto_rw_set_int(&rw, 20) == 0);
    test_assert(corto_rw_pop(&rw) == 0);
    corto_rw_deinit(&rw);

    test_assertint(o->m->actual.x, 0);
    test_assertint(o->m->actual.y, 0);
    test_assertint(o->m->target.x, 0);
    test_assertint(o->m->target.y, 0);
    test_assertint(o->m->objective.x, 10);
    test_assertint(o->m->objective.y, 20);

    test_assert(corto_delete(o) == 0);
}

void test_rw_target_tc_target_nested(
    test_rw_target this)
{
    test_s_target_composite *o = corto_create(root_o, "o", test_s_target_composite_o);
    test_assert(o != NULL);
    test_assert(corto_check_attr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_sourceof(o) == NULL);

    /* Create mount that serves up remote objects */
    corto_mount remote = corto_declare(NULL, NULL, corto_mount_o);
    test_assert(remote != NULL);
    remote->ownership = CORTO_REMOTE_SOURCE;
    test_assert(corto_define(remote) == 0);

    corto_set_source(remote);
    corto_rw rw = corto_rw_init(test_s_target_composite_o, o);
    test_assert(corto_rw_push(&rw, false) == 0);
    test_assert(corto_rw_field(&rw, "m.target.x") == 0);
    test_assert(corto_rw_set_int(&rw, 10) == 0);
    test_assert(corto_rw_field(&rw, "m.target.y") == 0);
    test_assert(corto_rw_set_int(&rw, 20) == 0);
    test_assert(corto_rw_pop(&rw) == 0);
    corto_rw_deinit(&rw);
    corto_set_source(NULL);

    test_assertint(o->m->actual.x, 0);
    test_assertint(o->m->actual.y, 0);
    test_assertint(o->m->target.x, 10);
    test_assertint(o->m->target.y, 20);
    test_assertint(o->m->objective.x, 0);
    test_assertint(o->m->objective.y, 0);

    test_assert(corto_delete(o) == 0);
}

void test_rw_target_tc_actual_no_field_expr(
    test_rw_target this)
{
    test_s_target_primitive *o = corto_create(root_o, "o", test_s_target_primitive_o);
    test_assert(o != NULL);
    test_assert(corto_check_attr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_sourceof(o) == NULL);

    corto_rw rw = corto_rw_init(test_s_target_primitive_o, o);
    test_assert(corto_rw_push(&rw, false) == 0);
    test_assert(corto_rw_next(&rw) == 0);
    test_assert(corto_rw_push(&rw, false) == 0);
    test_assert(corto_rw_set_int(&rw, 10) == 0);
    test_assert(corto_rw_pop(&rw) == 0);
    test_assert(corto_rw_pop(&rw) == 0);
    corto_rw_deinit(&rw);

    test_assertint(o->m->actual, 10);
    test_assertint(o->m->target, 0);
    test_assertint(o->m->objective, 0);

    test_assert(corto_delete(o) == 0);
}

void test_rw_target_tc_set_actual_and_objective(
    test_rw_target this)
{
    test_s_target_primitive *o = corto_create(root_o, "o", test_s_target_primitive_o);
    test_assert(o != NULL);
    test_assert(corto_check_attr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_sourceof(o) == NULL);

    corto_rw rw = corto_rw_init(test_s_target_primitive_o, o);
    test_assert(corto_rw_push(&rw, false) == 0);
    test_assert(corto_rw_next(&rw) == 0);
    test_assert(corto_rw_push(&rw, false) == 0);
    test_assert(corto_rw_field(&rw, "actual") == 0);
    test_assert(corto_rw_set_int(&rw, 10) == 0);
    test_assert(corto_rw_field(&rw, "objective") == 0);
    test_assert(corto_rw_set_int(&rw, 20) == 0);
    test_assert(corto_rw_pop(&rw) == 0);
    test_assert(corto_rw_pop(&rw) == 0);
    corto_rw_deinit(&rw);

    test_assertint(o->m->actual, 10);
    test_assertint(o->m->target, 0);
    test_assertint(o->m->objective, 20);

    test_assert(corto_delete(o) == 0);
}

void test_rw_target_tc_set_actual_no_field_expr_and_objective(
    test_rw_target this)
{
    test_s_target_primitive *o = corto_create(root_o, "o", test_s_target_primitive_o);
    test_assert(o != NULL);
    test_assert(corto_check_attr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_sourceof(o) == NULL);

    corto_rw rw = corto_rw_init(test_s_target_primitive_o, o);
    test_assert(corto_rw_push(&rw, false) == 0);
    test_assert(corto_rw_next(&rw) == 0);
    test_assert(corto_rw_push(&rw, false) == 0);
    test_assert(corto_rw_set_int(&rw, 10) == 0);
    test_assert(corto_rw_field(&rw, "objective") == 0);
    test_assert(corto_rw_set_int(&rw, 20) == 0);
    test_assert(corto_rw_pop(&rw) == 0);
    test_assert(corto_rw_pop(&rw) == 0);
    corto_rw_deinit(&rw);

    test_assertint(o->m->actual, 10);
    test_assertint(o->m->target, 0);
    test_assertint(o->m->objective, 20);

    test_assert(corto_delete(o) == 0);
}
