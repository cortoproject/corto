/* $CORTO_GENERATED
 *
 * SelectContentType.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <include/test.h>

corto_void _test_SelectContentType_setup(
    test_SelectContentType this)
{
/* $begin(test/SelectContentType/setup) */

    /* Create 'json' scope for JSON mount */
    corto_object json_o = corto_voidCreateChild(root_o, "json");

    /* Create 'string' scope for Corto string mount */
    corto_object str_o = corto_voidCreateChild(root_o, "str");

    /* Create 'obj' scope with Corto objects */
    corto_object obj_o = corto_voidCreateChild(root_o, "obj");

    /* Attach json mount to json scope */
    test_JsonReplicatorCreate(json_o);

    /* Attach str mount to str scope */
    test_StringReplicatorCreate(str_o);

    /* Create three objects in 'obj' scope */
    test_PointCreateChild(obj_o, "a", 10, 20);
    test_PointCreateChild(obj_o, "b", 30, 40);
    test_PointCreateChild(obj_o, "c", 50, 60);

/* $end */
}

corto_void _test_SelectContentType_tc_selectJsonFromJson(
    test_SelectContentType this)
{
/* $begin(test/SelectContentType/tc_selectJsonFromJson) */
    corto_iter iter;
    corto_result *result;
    corto_string json;

    corto_int16 ret = corto_select("/", "/json/*").contentType("text/json").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "a"));
    test_assert(!strcmp(result->parent, "json"));
    test_assert(!strcmp(result->type, "/test/Point"));
    json = corto_result_getText(result);
    test_assert(json != NULL);
    test_assert(!strcmp(json, "{\"x\":10,\"y\":20}"));

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "b"));
    test_assert(!strcmp(result->parent, "json"));
    test_assert(!strcmp(result->type, "/test/Point"));
    json = corto_result_getText(result);
    test_assert(json != NULL);
    test_assert(!strcmp(json, "{\"x\":30,\"y\":40}"));

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "c"));
    test_assert(!strcmp(result->parent, "json"));
    test_assert(!strcmp(result->type, "/test/Point"));
    json = corto_result_getText(result);
    test_assert(json != NULL);
    test_assert(!strcmp(json, "{\"x\":50,\"y\":60}"));

/* $end */
}

corto_void _test_SelectContentType_tc_selectJsonFromObjects(
    test_SelectContentType this)
{
/* $begin(test/SelectContentType/tc_selectJsonFromObjects) */
    corto_iter iter;
    corto_result *result;
    corto_string json;

    corto_int16 ret = corto_select("/", "/obj/*").contentType("text/json").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "a"));
    test_assert(!strcmp(result->parent, "obj"));
    test_assert(!strcmp(result->type, "/test/Point"));
    json = corto_result_getText(result);
    test_assert(json != NULL);
    test_assert(!strcmp(json, "{\"x\":10,\"y\":20}"));

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "b"));
    test_assert(!strcmp(result->parent, "obj"));
    test_assert(!strcmp(result->type, "/test/Point"));
    json = corto_result_getText(result);
    test_assert(json != NULL);
    test_assert(!strcmp(json, "{\"x\":30,\"y\":40}"));

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "c"));
    test_assert(!strcmp(result->parent, "obj"));
    test_assert(!strcmp(result->type, "/test/Point"));
    json = corto_result_getText(result);
    test_assert(json != NULL);
    test_assert(!strcmp(json, "{\"x\":50,\"y\":60}"));

/* $end */
}

corto_void _test_SelectContentType_tc_selectJsonFromString(
    test_SelectContentType this)
{
/* $begin(test/SelectContentType/tc_selectJsonFromString) */
    corto_result *result;
    corto_string json;
    corto_iter iter;

    corto_int16 ret = corto_select("/", "/str/*").contentType("text/json").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "a"));
    test_assert(!strcmp(result->parent, "str"));
    test_assert(!strcmp(result->type, "/test/Point"));
    json = corto_result_getText(result);
    test_assert(json != NULL);
    test_assert(!strcmp(json, "{\"x\":10,\"y\":20}"));

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "b"));
    test_assert(!strcmp(result->parent, "str"));
    test_assert(!strcmp(result->type, "/test/Point"));
    json = corto_result_getText(result);
    test_assert(json != NULL);
    test_assert(!strcmp(json, "{\"x\":30,\"y\":40}"));

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "c"));
    test_assert(!strcmp(result->parent, "str"));
    test_assert(!strcmp(result->type, "/test/Point"));
    json = corto_result_getText(result);
    test_assert(json != NULL);
    test_assert(!strcmp(json, "{\"x\":50,\"y\":60}"));

/* $end */
}

corto_void _test_SelectContentType_tc_selectStringFromJson(
    test_SelectContentType this)
{
/* $begin(test/SelectContentType/tc_selectStringFromJson) */
    corto_iter iter;
    corto_result *result;
    corto_string str;

    corto_int16 ret = corto_select("/", "/json/*").contentType("text/corto").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "a"));
    test_assert(!strcmp(result->parent, "json"));
    test_assert(!strcmp(result->type, "/test/Point"));
    str = corto_result_getText(result);
    test_assert(str != NULL);
    test_assert(!strcmp(str, "{10,20}"));

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "b"));
    test_assert(!strcmp(result->parent, "json"));
    test_assert(!strcmp(result->type, "/test/Point"));
    str = corto_result_getText(result);
    test_assert(str != NULL);
    test_assert(!strcmp(str, "{30,40}"));

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "c"));
    test_assert(!strcmp(result->parent, "json"));
    test_assert(!strcmp(result->type, "/test/Point"));
    str = corto_result_getText(result);
    test_assert(str != NULL);
    test_assert(!strcmp(str, "{50,60}"));

/* $end */
}

corto_void _test_SelectContentType_tc_selectStringFromObjects(
    test_SelectContentType this)
{
/* $begin(test/SelectContentType/tc_selectStringFromObjects) */
    corto_iter iter;
    corto_result *result;
    corto_string str;

    corto_int16 ret = corto_select("/", "/obj/*").contentType("text/corto").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "a"));
    test_assert(!strcmp(result->parent, "obj"));
    test_assert(!strcmp(result->type, "/test/Point"));
    str = corto_result_getText(result);
    test_assert(str != NULL);
    test_assert(!strcmp(str, "{10,20}"));

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "b"));
    test_assert(!strcmp(result->parent, "obj"));
    test_assert(!strcmp(result->type, "/test/Point"));
    str = corto_result_getText(result);
    test_assert(str != NULL);
    test_assert(!strcmp(str, "{30,40}"));

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "c"));
    test_assert(!strcmp(result->parent, "obj"));
    test_assert(!strcmp(result->type, "/test/Point"));
    str = corto_result_getText(result);
    test_assert(str != NULL);
    test_assert(!strcmp(str, "{50,60}"));

/* $end */
}

corto_void _test_SelectContentType_tc_selectStringFromString(
    test_SelectContentType this)
{
/* $begin(test/SelectContentType/tc_selectStringFromString) */
    corto_iter iter;
    corto_result *result;
    corto_string str;

    corto_int16 ret = corto_select("/", "/str/*").contentType("text/corto").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "a"));
    test_assert(!strcmp(result->parent, "str"));
    test_assert(!strcmp(result->type, "/test/Point"));
    str = corto_result_getText(result);
    test_assert(str != NULL);
    test_assert(!strcmp(str, "{10,20}"));

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "b"));
    test_assert(!strcmp(result->parent, "str"));
    test_assert(!strcmp(result->type, "/test/Point"));
    str = corto_result_getText(result);
    test_assert(str != NULL);
    test_assert(!strcmp(str, "{30,40}"));

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "c"));
    test_assert(!strcmp(result->parent, "str"));
    test_assert(!strcmp(result->type, "/test/Point"));
    str = corto_result_getText(result);
    test_assert(str != NULL);
    test_assert(!strcmp(str, "{50,60}"));

/* $end */
}
