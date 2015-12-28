/* $CORTO_GENERATED
 *
 * ReplicatorRequest.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include "test.h"

corto_void _test_ReplicatorRequest_setup(test_ReplicatorRequest this) {
/* $begin(test/ReplicatorRequest/setup) */

    /* Create dummy object */
    corto_attr old = corto_setAttr(CORTO_ATTR_OBSERVABLE);
    corto_object a_o = corto_voidCreateChild(root_o, "a");
    corto_setAttr(old);

    /* Create replicator */
    this->replicator = test_ListReplicatorCreate(a_o);

/* $end */
}

corto_void _test_ReplicatorRequest_tc_selectScope(test_ReplicatorRequest this) {
/* $begin(test/ReplicatorRequest/tc_selectScope) */
    corto_resultIter iter;
    corto_result *result;
    corto_int16 ret;

    ret = corto_select(root_o, "a/*", &iter);

    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->name != NULL);
    test_assert(!strcmp(result->name, "x"));
    test_assert(!strcmp(result->parent, "a"));
    test_assert(!strcmp(result->type, "/foo"));

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->name != NULL);
    test_assert(!strcmp(result->name, "yz"));
    test_assert(!strcmp(result->parent, "a"));
    test_assert(!strcmp(result->type, "/bar"));

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->name != NULL);
    test_assert(!strcmp(result->name, "xyz"));
    test_assert(!strcmp(result->parent, "a"));
    test_assert(!strcmp(result->type, "/panda"));

    test_assert(!corto_iterHasNext(&iter));

/* $end */
}

corto_void _test_ReplicatorRequest_tc_selectScopeFilter(test_ReplicatorRequest this) {
/* $begin(test/ReplicatorRequest/tc_selectScopeFilter) */
    corto_resultIter iter;
    corto_result *result;
    corto_int16 ret;

    ret = corto_select(root_o, "a/*z", &iter);

    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->name != NULL);
    test_assert(!strcmp(result->name, "yz"));
    test_assert(!strcmp(result->parent, "a"));
    test_assert(!strcmp(result->type, "/bar"));

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->name != NULL);
    test_assert(!strcmp(result->name, "xyz"));
    test_assert(!strcmp(result->parent, "a"));
    test_assert(!strcmp(result->type, "/panda"));

    test_assert(!corto_iterHasNext(&iter));

/* $end */
}

corto_void _test_ReplicatorRequest_tc_selectScopeMixed(test_ReplicatorRequest this) {
/* $begin(test/ReplicatorRequest/tc_selectScopeMixed) */
    corto_resultIter iter;
    corto_result *result;
    corto_int16 ret;

    /* Create additional three objects in scope of a */
    corto_object a = corto_resolve(NULL, "a");
    test_assert(a != NULL);
    corto_voidCreateChild(a, "b");
    corto_voidCreateChild(a, "bc");
    corto_voidCreateChild(a, "abc");
    corto_release(a);

    ret = corto_select(root_o, "a/*", &iter);

    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->name != NULL);
    test_assert(!strcmp(result->name, "abc"));
    test_assert(!strcmp(result->parent, "a"));
    test_assert(!strcmp(result->type, "void"));

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->name != NULL);
    test_assert(!strcmp(result->name, "b"));
    test_assert(!strcmp(result->parent, "a"));
    test_assert(!strcmp(result->type, "void"));

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->name != NULL);
    test_assert(!strcmp(result->name, "bc"));
    test_assert(!strcmp(result->parent, "a"));
    test_assert(!strcmp(result->type, "void"));

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->name != NULL);
    test_assert(!strcmp(result->name, "x"));
    test_assert(!strcmp(result->parent, "a"));
    test_assert(!strcmp(result->type, "/foo"));

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->name != NULL);
    test_assert(!strcmp(result->name, "yz"));
    test_assert(!strcmp(result->parent, "a"));
    test_assert(!strcmp(result->type, "/bar"));

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->name != NULL);
    test_assert(!strcmp(result->name, "xyz"));
    test_assert(!strcmp(result->parent, "a"));
    test_assert(!strcmp(result->type, "/panda"));

    test_assert(!corto_iterHasNext(&iter));

/* $end */
}

corto_void _test_ReplicatorRequest_tc_selectScopeNested(test_ReplicatorRequest this) {
/* $begin(test/ReplicatorRequest/tc_selectScopeNested) */
    corto_resultIter iter;
    corto_result *result;
    corto_int16 ret;

    ret = corto_select(root_o, "a/xyz/*", &iter);

    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->name != NULL);
    test_assert(!strcmp(result->name, "a"));
    test_assert(!strcmp(result->parent, "a/xyz"));
    test_assert(!strcmp(result->type, "/type"));

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->name != NULL);
    test_assert(!strcmp(result->name, "abc"));
    test_assert(!strcmp(result->parent, "a/xyz"));
    test_assert(!strcmp(result->type, "/type"));

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->name != NULL);
    test_assert(!strcmp(result->name, "bc"));
    test_assert(!strcmp(result->parent, "a/xyz"));
    test_assert(!strcmp(result->type, "/type"));

    test_assert(!corto_iterHasNext(&iter));

/* $end */
}

corto_void _test_ReplicatorRequest_tc_selectScopeNestedDirty(test_ReplicatorRequest this) {
/* $begin(test/ReplicatorRequest/tc_selectScopeNestedDirty) */
    corto_resultIter iter;
    corto_result *result;
    corto_int16 ret;

    ret = corto_select(root_o, "a/../a/./xyz/./*", &iter);

    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->name != NULL);
    test_assert(!strcmp(result->name, "a"));
    test_assert(!strcmp(result->parent, "a/xyz"));
    test_assert(!strcmp(result->type, "/type"));

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->name != NULL);
    test_assert(!strcmp(result->name, "abc"));
    test_assert(!strcmp(result->parent, "a/xyz"));
    test_assert(!strcmp(result->type, "/type"));

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->name != NULL);
    test_assert(!strcmp(result->name, "bc"));
    test_assert(!strcmp(result->parent, "a/xyz"));
    test_assert(!strcmp(result->type, "/type"));

    test_assert(!corto_iterHasNext(&iter));

/* $end */
}

corto_void _test_ReplicatorRequest_tc_selectSingle(test_ReplicatorRequest this) {
/* $begin(test/ReplicatorRequest/tc_selectSingle) */
    corto_resultIter iter;
    corto_result *result;
    corto_int16 ret;

    ret = corto_select(root_o, "a/xyz", &iter);

    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->name != NULL);
    test_assert(!strcmp(result->name, "xyz"));
    test_assert(!strcmp(result->parent, "a"));
    test_assert(!strcmp(result->type, "/panda"));

    test_assert(!corto_iterHasNext(&iter));

/* $end */
}

corto_void _test_ReplicatorRequest_tc_selectSingleNested(test_ReplicatorRequest this) {
/* $begin(test/ReplicatorRequest/tc_selectSingleNested) */
    corto_resultIter iter;
    corto_result *result;
    corto_int16 ret;

    ret = corto_select(root_o, "a/xyz/abc", &iter);

    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->name != NULL);
    test_assert(!strcmp(result->name, "abc"));
    test_assert(!strcmp(result->parent, "a/xyz"));
    test_assert(!strcmp(result->type, "/type"));

    test_assert(!corto_iterHasNext(&iter));

/* $end */
}

corto_void _test_ReplicatorRequest_teardown(test_ReplicatorRequest this) {
/* $begin(test/ReplicatorRequest/teardown) */

    corto_delete(this->replicator);
    this->replicator = NULL;

/* $end */
}
