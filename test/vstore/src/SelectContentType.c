/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

void test_SelectContentType_setup(
    test_SelectContentType this)
{

    /* Create 'json' scope for JSON mount */
    corto_object json_o = corto_void__create(root_o, "json");

    /* Create 'string' scope for Corto string mount */
    corto_object str_o = corto_void__create(root_o, "str");

    /* Create 'obj' scope with Corto objects */
    corto_object obj_o = corto_void__create(root_o, "obj");

    /* Attach json mount to json scope */
    test_JsonReplicator__create(NULL, NULL, json_o, "/test/Point");

    /* Attach str mount to str scope */
    test_StringReplicator__create(NULL, NULL, str_o);

    /* Create three objects in 'obj' scope */
    test_Point__create(obj_o, "a", 10, 20);
    test_Point__create(obj_o, "b", 30, 40);
    test_Point__create(obj_o, "c", 50, 60);
}

void test_SelectContentType_tc_selectBinaryFromJson(
    test_SelectContentType this)
{
    corto_iter iter;
    corto_record *result;
    test_Point *p;

    corto_int16 ret =
        corto_select("json/*").format("binary/corto").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "a"));
    test_assert(!strcmp(result->parent, "/json"));
    test_assert(!strcmp(result->type, "/test/Point"));
    p = (test_Point*)result->value;
    test_assert(p != NULL);
    test_assertint(p->x, 10);
    test_assertint(p->y, 20);

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "b"));
    test_assert(!strcmp(result->parent, "/json"));
    test_assert(!strcmp(result->type, "/test/Point"));
    p = (test_Point*)result->value;
    test_assert(p != NULL);
    test_assertint(p->x, 30);
    test_assertint(p->y, 40);

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "c"));
    test_assert(!strcmp(result->parent, "/json"));
    test_assert(!strcmp(result->type, "/test/Point"));
    p = (test_Point*)result->value;
    test_assert(p != NULL);
    test_assertint(p->x, 50);
    test_assertint(p->y, 60);

    test_assert(!corto_iter_hasNext(&iter));
}

void test_SelectContentType_tc_selectBinaryFromObjects(
    test_SelectContentType this)
{
    corto_iter iter;
    corto_record *result;
    test_Point *p;

    corto_int16 ret = corto_select("obj/*").format("binary/corto").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "a"));
    test_assert(!strcmp(result->parent, "/obj"));
    test_assert(!strcmp(result->type, "/test/Point"));
    p = (test_Point*)result->value;
    test_assert(p != NULL);
    test_assertint(p->x, 10);
    test_assertint(p->y, 20);

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "b"));
    test_assert(!strcmp(result->parent, "/obj"));
    test_assert(!strcmp(result->type, "/test/Point"));
    p = (test_Point*)result->value;
    test_assert(p != NULL);
    test_assertint(p->x, 30);
    test_assertint(p->y, 40);

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "c"));
    test_assert(!strcmp(result->parent, "/obj"));
    test_assert(!strcmp(result->type, "/test/Point"));
    p = (test_Point*)result->value;
    test_assert(p != NULL);
    test_assertint(p->x, 50);
    test_assertint(p->y, 60);

    test_assert(!corto_iter_hasNext(&iter));
}

void test_SelectContentType_tc_selectBinaryFromString(
    test_SelectContentType this)
{
    corto_record *result;
    corto_iter iter;
    test_Point *p;

    corto_int16 ret = corto_select("str/*").format("binary/corto").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "a"));
    test_assert(!strcmp(result->parent, "/str"));
    test_assert(!strcmp(result->type, "/test/Point"));
    p = (test_Point*)result->value;
    test_assert(p != NULL);
    test_assertint(p->x, 10);
    test_assertint(p->y, 20);

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "b"));
    test_assert(!strcmp(result->parent, "/str"));
    test_assert(!strcmp(result->type, "/test/Point"));
    p = (test_Point*)result->value;
    test_assert(p != NULL);
    test_assertint(p->x, 30);
    test_assertint(p->y, 40);

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "c"));
    test_assert(!strcmp(result->parent, "/str"));
    test_assert(!strcmp(result->type, "/test/Point"));
    p = (test_Point*)result->value;
    test_assert(p != NULL);
    test_assertint(p->x, 50);
    test_assertint(p->y, 60);

    test_assert(!corto_iter_hasNext(&iter));
}

void test_SelectContentType_tc_selectJsonFromJson(
    test_SelectContentType this)
{
    corto_iter iter;
    corto_record *result;
    corto_string json;

    corto_int16 ret = corto_select("json/*").format("text/json").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "a"));
    test_assert(!strcmp(result->parent, "/json"));
    test_assert(!strcmp(result->type, "/test/Point"));
    json = corto_record_get_text(result);
    test_assert(json != NULL);
    test_assert(!strcmp(json, "{\"x\":10,\"y\":20}"));

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "b"));
    test_assert(!strcmp(result->parent, "/json"));
    test_assert(!strcmp(result->type, "/test/Point"));
    json = corto_record_get_text(result);
    test_assert(json != NULL);
    test_assert(!strcmp(json, "{\"x\":30,\"y\":40}"));

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "c"));
    test_assert(!strcmp(result->parent, "/json"));
    test_assert(!strcmp(result->type, "/test/Point"));
    json = corto_record_get_text(result);
    test_assert(json != NULL);
    test_assert(!strcmp(json, "{\"x\":50,\"y\":60}"));

    test_assert(!corto_iter_hasNext(&iter));
}

void test_SelectContentType_tc_selectJsonFromObjects(
    test_SelectContentType this)
{
    corto_iter iter;
    corto_record *result;
    corto_string json;

    corto_int16 ret = corto_select("obj/*").format("text/json").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "a"));
    test_assert(!strcmp(result->parent, "/obj"));
    test_assert(!strcmp(result->type, "/test/Point"));
    json = corto_record_get_text(result);
    test_assert(json != NULL);
    test_assert(!strcmp(json, "{\"x\":10,\"y\":20}"));

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "b"));
    test_assert(!strcmp(result->parent, "/obj"));
    test_assert(!strcmp(result->type, "/test/Point"));
    json = corto_record_get_text(result);
    test_assert(json != NULL);
    test_assert(!strcmp(json, "{\"x\":30,\"y\":40}"));

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "c"));
    test_assert(!strcmp(result->parent, "/obj"));
    test_assert(!strcmp(result->type, "/test/Point"));
    json = corto_record_get_text(result);
    test_assert(json != NULL);
    test_assert(!strcmp(json, "{\"x\":50,\"y\":60}"));

    test_assert(!corto_iter_hasNext(&iter));
}

void test_SelectContentType_tc_selectJsonFromString(
    test_SelectContentType this)
{
    corto_record *result;
    corto_string json;
    corto_iter iter;

    corto_int16 ret = corto_select("str/*").format("text/json").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "a"));
    test_assert(!strcmp(result->parent, "/str"));
    test_assert(!strcmp(result->type, "/test/Point"));
    json = corto_record_get_text(result);
    test_assert(json != NULL);
    test_assert(!strcmp(json, "{\"x\":10,\"y\":20}"));

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "b"));
    test_assert(!strcmp(result->parent, "/str"));
    test_assert(!strcmp(result->type, "/test/Point"));
    json = corto_record_get_text(result);
    test_assert(json != NULL);
    test_assert(!strcmp(json, "{\"x\":30,\"y\":40}"));

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "c"));
    test_assert(!strcmp(result->parent, "/str"));
    test_assert(!strcmp(result->type, "/test/Point"));
    json = corto_record_get_text(result);
    test_assert(json != NULL);
    test_assert(!strcmp(json, "{\"x\":50,\"y\":60}"));

    test_assert(!corto_iter_hasNext(&iter));
}

void test_SelectContentType_tc_selectStringFromJson(
    test_SelectContentType this)
{
    corto_iter iter;
    corto_record *result;
    corto_string str;

    corto_int16 ret = corto_select("json/*").format("text/corto").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "a"));
    test_assert(!strcmp(result->parent, "/json"));
    test_assert(!strcmp(result->type, "/test/Point"));
    str = corto_record_get_text(result);
    test_assert(str != NULL);
    test_assert(!strcmp(str, "{10,20}"));

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "b"));
    test_assert(!strcmp(result->parent, "/json"));
    test_assert(!strcmp(result->type, "/test/Point"));
    str = corto_record_get_text(result);
    test_assert(str != NULL);
    test_assert(!strcmp(str, "{30,40}"));

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "c"));
    test_assert(!strcmp(result->parent, "/json"));
    test_assert(!strcmp(result->type, "/test/Point"));
    str = corto_record_get_text(result);
    test_assert(str != NULL);
    test_assert(!strcmp(str, "{50,60}"));

    test_assert(!corto_iter_hasNext(&iter));
}

void test_SelectContentType_tc_selectStringFromObjects(
    test_SelectContentType this)
{
    corto_iter iter;
    corto_record *result;
    corto_string str;

    corto_int16 ret = corto_select("obj/*").format("text/corto").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "a"));
    test_assert(!strcmp(result->parent, "/obj"));
    test_assert(!strcmp(result->type, "/test/Point"));
    str = corto_record_get_text(result);
    test_assert(str != NULL);
    test_assert(!strcmp(str, "{10,20}"));

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "b"));
    test_assert(!strcmp(result->parent, "/obj"));
    test_assert(!strcmp(result->type, "/test/Point"));
    str = corto_record_get_text(result);
    test_assert(str != NULL);
    test_assert(!strcmp(str, "{30,40}"));

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "c"));
    test_assert(!strcmp(result->parent, "/obj"));
    test_assert(!strcmp(result->type, "/test/Point"));
    str = corto_record_get_text(result);
    test_assert(str != NULL);
    test_assert(!strcmp(str, "{50,60}"));

    test_assert(!corto_iter_hasNext(&iter));
}

void test_SelectContentType_tc_selectStringFromString(
    test_SelectContentType this)
{
    corto_iter iter;
    corto_record *result;
    corto_string str;

    corto_int16 ret = corto_select("str/*").format("text/corto").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "a"));
    test_assert(!strcmp(result->parent, "/str"));
    test_assert(!strcmp(result->type, "/test/Point"));
    str = corto_record_get_text(result);
    test_assert(str != NULL);
    test_assert(!strcmp(str, "{10,20}"));

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "b"));
    test_assert(!strcmp(result->parent, "/str"));
    test_assert(!strcmp(result->type, "/test/Point"));
    str = corto_record_get_text(result);
    test_assert(str != NULL);
    test_assert(!strcmp(str, "{30,40}"));

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "c"));
    test_assert(!strcmp(result->parent, "/str"));
    test_assert(!strcmp(result->type, "/test/Point"));
    str = corto_record_get_text(result);
    test_assert(str != NULL);
    test_assert(!strcmp(str, "{50,60}"));

    test_assert(!corto_iter_hasNext(&iter));
}

void test_SelectContentType_tc_selectTypeWithConstruct(
    test_SelectContentType this)
{
    test_assertint(test_ContentTypeTest_get_construct_called_count(), 0);

    corto_object data_o = corto_lookup(NULL, "data");
    test_JsonReplicator__create(NULL, NULL, data_o, "/test/ContentTypeTest");
    corto_release(data_o);

    test_assertint(test_ContentTypeTest_get_construct_called_count(), 0);

    corto_iter iter;
    corto_record *result;
    corto_string str;
    corto_int16 ret = corto_select("data/*").format("text/corto").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "a");
    test_assertstr(result->parent, "/data");
    test_assertstr(result->type, "/test/ContentTypeTest");
    str = corto_record_get_text(result);
    test_assert(str != NULL);
    test_assertstr(str, "{10,20}");

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "b");
    test_assertstr(result->parent, "/data");
    test_assertstr(result->type, "/test/ContentTypeTest");
    str = corto_record_get_text(result);
    test_assert(str != NULL);
    test_assertstr(str, "{30,40}");

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "c");
    test_assertstr(result->parent, "/data");
    test_assertstr(result->type, "/test/ContentTypeTest");
    str = corto_record_get_text(result);
    test_assert(str != NULL);
    test_assertstr(str, "{50,60}");

    test_assertint(test_ContentTypeTest_get_construct_called_count(), 0);
}
