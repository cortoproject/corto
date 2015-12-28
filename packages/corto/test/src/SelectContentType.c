/* $CORTO_GENERATED
 *
 * SelectContentType.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include "test.h"

corto_void _test_SelectContentType_setup(test_SelectContentType this) {
/* $begin(test/SelectContentType/setup) */

    /* Create 'json' scope for JSON replicator */
    corto_object json_o = corto_voidCreateChild(root_o, "json");

    /* Create 'string' scope for Corto string replicator */
    corto_object str_o = corto_voidCreateChild(root_o, "str");

    /* Create 'obj' scope with Corto objects */
    corto_object obj_o = corto_voidCreateChild(root_o, "obj");

    /* Attach json replicator to json scope */
    test_JsonReplicatorCreate(json_o);

    /* Attach str replicator to str scope */
    test_StringReplicatorCreate(str_o);

    /* Create three objects in 'obj' scope */
    test_PointCreateChild(obj_o, "a", 10, 20);
    test_PointCreateChild(obj_o, "b", 30, 40);
    test_PointCreateChild(obj_o, "c", 50, 60);

/* $end */
}

corto_void _test_SelectContentType_tc_selectJsonFromJson(test_SelectContentType this) {
/* $begin(test/SelectContentType/tc_selectJsonFromJson) */
    corto_iter iter;
    corto_int16 ret;
    corto_result *result;
    corto_string json;

    ret = corto_select(root_o, "/json/*", &iter);
    test_assert(ret == 0);

    ret = corto_selectContentType(&iter, "application/json");
    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->name != NULL);
    test_assert(!strcmp(result->name, "a"));
    test_assert(!strcmp(result->parent, "json"));
    test_assert(!strcmp(result->type, "/test/Point"));
    json = corto_result_getText(result);
    test_assert(json != NULL);
    test_assert(!strcmp(json, "{\"x\":10,\"y\":20}"));

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->name != NULL);
    test_assert(!strcmp(result->name, "b"));
    test_assert(!strcmp(result->parent, "json"));
    test_assert(!strcmp(result->type, "/test/Point"));
    json = corto_result_getText(result);
    test_assert(json != NULL);
    test_assert(!strcmp(json, "{\"x\":30,\"y\":40}"));

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->name != NULL);
    test_assert(!strcmp(result->name, "c"));
    test_assert(!strcmp(result->parent, "json"));
    test_assert(!strcmp(result->type, "/test/Point"));
    json = corto_result_getText(result);
    test_assert(json != NULL);
    test_assert(!strcmp(json, "{\"x\":50,\"y\":60}"));

/* $end */
}

corto_void _test_SelectContentType_tc_selectJsonFromObjects(test_SelectContentType this) {
/* $begin(test/SelectContentType/tc_selectJsonFromObjects) */
    corto_iter iter;
    corto_int16 ret;
    corto_result *result;
    corto_string json;

    ret = corto_select(root_o, "/obj/*", &iter);
    test_assert(ret == 0);

    ret = corto_selectContentType(&iter, "application/json");
    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->name != NULL);
    test_assert(!strcmp(result->name, "a"));
    test_assert(!strcmp(result->parent, "obj"));
    test_assert(!strcmp(result->type, "/test/Point"));
    json = corto_result_getText(result);
    test_assert(json != NULL);
    test_assert(!strcmp(json, "{\"x\":10,\"y\":20}"));

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->name != NULL);
    test_assert(!strcmp(result->name, "b"));
    test_assert(!strcmp(result->parent, "obj"));
    test_assert(!strcmp(result->type, "/test/Point"));
    json = corto_result_getText(result);
    test_assert(json != NULL);
    test_assert(!strcmp(json, "{\"x\":30,\"y\":40}"));

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->name != NULL);
    test_assert(!strcmp(result->name, "c"));
    test_assert(!strcmp(result->parent, "obj"));
    test_assert(!strcmp(result->type, "/test/Point"));
    json = corto_result_getText(result);
    test_assert(json != NULL);
    test_assert(!strcmp(json, "{\"x\":50,\"y\":60}"));

/* $end */
}

corto_void _test_SelectContentType_tc_selectJsonFromString(test_SelectContentType this) {
/* $begin(test/SelectContentType/tc_selectJsonFromString) */
    corto_iter iter;
    corto_int16 ret;
    corto_result *result;
    corto_string json;

    ret = corto_select(root_o, "/str/*", &iter);
    test_assert(ret == 0);

    ret = corto_selectContentType(&iter, "application/json");
    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->name != NULL);
    test_assert(!strcmp(result->name, "a"));
    test_assert(!strcmp(result->parent, "str"));
    test_assert(!strcmp(result->type, "/test/Point"));
    json = corto_result_getText(result);
    test_assert(json != NULL);
    test_assert(!strcmp(json, "{\"x\":10,\"y\":20}"));

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->name != NULL);
    test_assert(!strcmp(result->name, "b"));
    test_assert(!strcmp(result->parent, "str"));
    test_assert(!strcmp(result->type, "/test/Point"));
    json = corto_result_getText(result);
    test_assert(json != NULL);
    test_assert(!strcmp(json, "{\"x\":30,\"y\":40}"));

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->name != NULL);
    test_assert(!strcmp(result->name, "c"));
    test_assert(!strcmp(result->parent, "str"));
    test_assert(!strcmp(result->type, "/test/Point"));
    json = corto_result_getText(result);
    test_assert(json != NULL);
    test_assert(!strcmp(json, "{\"x\":50,\"y\":60}"));

/* $end */
}

corto_void _test_SelectContentType_tc_selectStringFromJson(test_SelectContentType this) {
/* $begin(test/SelectContentType/tc_selectStringFromJson) */
    corto_iter iter;
    corto_int16 ret;
    corto_result *result;
    corto_string str;

    ret = corto_select(root_o, "/json/*", &iter);
    test_assert(ret == 0);

    ret = corto_selectContentType(&iter, "application/corto");
    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->name != NULL);
    test_assert(!strcmp(result->name, "a"));
    test_assert(!strcmp(result->parent, "json"));
    test_assert(!strcmp(result->type, "/test/Point"));
    str = corto_result_getText(result);
    test_assert(str != NULL);
    test_assert(!strcmp(str, "{10,20}"));

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->name != NULL);
    test_assert(!strcmp(result->name, "b"));
    test_assert(!strcmp(result->parent, "json"));
    test_assert(!strcmp(result->type, "/test/Point"));
    str = corto_result_getText(result);
    test_assert(str != NULL);
    test_assert(!strcmp(str, "{30,40}"));

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->name != NULL);
    test_assert(!strcmp(result->name, "c"));
    test_assert(!strcmp(result->parent, "json"));
    test_assert(!strcmp(result->type, "/test/Point"));
    str = corto_result_getText(result);
    test_assert(str != NULL);
    test_assert(!strcmp(str, "{50,60}"));

/* $end */
}

corto_void _test_SelectContentType_tc_selectStringFromObjects(test_SelectContentType this) {
/* $begin(test/SelectContentType/tc_selectStringFromObjects) */
    corto_iter iter;
    corto_int16 ret;
    corto_result *result;
    corto_string str;

    ret = corto_select(root_o, "/obj/*", &iter);
    test_assert(ret == 0);

    ret = corto_selectContentType(&iter, "application/corto");
    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->name != NULL);
    test_assert(!strcmp(result->name, "a"));
    test_assert(!strcmp(result->parent, "obj"));
    test_assert(!strcmp(result->type, "/test/Point"));
    str = corto_result_getText(result);
    test_assert(str != NULL);
    test_assert(!strcmp(str, "{10,20}"));

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->name != NULL);
    test_assert(!strcmp(result->name, "b"));
    test_assert(!strcmp(result->parent, "obj"));
    test_assert(!strcmp(result->type, "/test/Point"));
    str = corto_result_getText(result);
    test_assert(str != NULL);
    test_assert(!strcmp(str, "{30,40}"));

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->name != NULL);
    test_assert(!strcmp(result->name, "c"));
    test_assert(!strcmp(result->parent, "obj"));
    test_assert(!strcmp(result->type, "/test/Point"));
    str = corto_result_getText(result);
    test_assert(str != NULL);
    test_assert(!strcmp(str, "{50,60}"));

/* $end */
}

corto_void _test_SelectContentType_tc_selectStringFromString(test_SelectContentType this) {
/* $begin(test/SelectContentType/tc_selectStringFromString) */
    corto_iter iter;
    corto_int16 ret;
    corto_result *result;
    corto_string str;

    ret = corto_select(root_o, "/str/*", &iter);
    test_assert(ret == 0);

    ret = corto_selectContentType(&iter, "application/corto");
    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->name != NULL);
    test_assert(!strcmp(result->name, "a"));
    test_assert(!strcmp(result->parent, "str"));
    test_assert(!strcmp(result->type, "/test/Point"));
    str = corto_result_getText(result);
    test_assert(str != NULL);
    test_assert(!strcmp(str, "{10,20}"));

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->name != NULL);
    test_assert(!strcmp(result->name, "b"));
    test_assert(!strcmp(result->parent, "str"));
    test_assert(!strcmp(result->type, "/test/Point"));
    str = corto_result_getText(result);
    test_assert(str != NULL);
    test_assert(!strcmp(str, "{30,40}"));

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->name != NULL);
    test_assert(!strcmp(result->name, "c"));
    test_assert(!strcmp(result->parent, "str"));
    test_assert(!strcmp(result->type, "/test/Point"));
    str = corto_result_getText(result);
    test_assert(str != NULL);
    test_assert(!strcmp(str, "{50,60}"));

/* $end */
}
