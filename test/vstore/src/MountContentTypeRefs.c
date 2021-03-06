/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

void test_MountContentTypeRefs_setup(
    test_MountContentTypeRefs this)
{
    corto_create(root_o, "config/helloworld", corto_void_o);
    corto_create(root_o, "data/foo", corto_void_o);
    corto_create(root_o, "data/foo/bar", corto_void_o);
    corto_create(root_o, "data/foo/bar/hello", corto_void_o);
    corto_create(root_o, "data/foo/bar/hello/world", corto_void_o);
    corto_create(root_o, "data/foo/bar/hello/world/test", corto_void_o);
}

void test_MountContentTypeRefs_tc_selectDataFromMountAtData(
    test_MountContentTypeRefs this)
{
    test_RefMount m = test_RefMount__create(NULL, NULL, "/data");
    test_assert(m != NULL);

    ut_iter it;
    int16_t ret = corto_select("refs")
        .from("/data")
        .format("text/json")
        .iter(&it);
    test_assert(ret == 0);

    char *expect =
        "{\"sibling\":\"/config\","
         "\"nested_sibling\":\"/config/helloworld\","
         "\"at_from\":\"foo\","
         "\"inside_from\":\"foo/bar\","
         "\"inside_from_nested1\":\"foo/bar/hello\","
         "\"inside_from_nested2\":\"foo/bar/hello/world\","
         "\"parent_from\":null,"
         "\"at_root\":\"/data\","
         "\"from\":\"/data\","
         "\"root\":\"/\","
         "\"null_ref\":null}";

    test_assert(ut_iter_hasNext(&it) != 0);
    corto_record *r = ut_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "refs");
    test_assertstr(r->parent, ".");
    test_assertstr(r->type, "test/Refs");
    test_assertstr((char*)r->value, expect);

    test_assert(ut_iter_hasNext(&it) == 0);

    test_assert(corto_delete(m) == 0);
}

void test_MountContentTypeRefs_tc_selectDataFromMountAtDataNested1(
    test_MountContentTypeRefs this)
{
    test_RefMount m = test_RefMount__create(NULL, NULL, "/data/parent");
    test_assert(m != NULL);

    ut_iter it;
    int16_t ret = corto_select("parent/refs")
        .from("/data")
        .format("text/json")
        .iter(&it);
    test_assert(ret == 0);

    char *expect =
        "{\"sibling\":\"/config\","
         "\"nested_sibling\":\"/config/helloworld\","
         "\"at_from\":\"parent/foo\","
         "\"inside_from\":\"parent/foo/bar\","
         "\"inside_from_nested1\":\"parent/foo/bar/hello\","
         "\"inside_from_nested2\":\"parent/foo/bar/hello/world\","
         "\"parent_from\":null,"
         "\"at_root\":\".\","
         "\"from\":\".\","
         "\"root\":\"/\","
         "\"null_ref\":null}";

    test_assert(ut_iter_hasNext(&it) != 0);
    corto_record *r = ut_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "refs");
    test_assertstr(r->parent, "parent");
    test_assertstr(r->type, "test/Refs");
    test_assertstr((char*)r->value, expect);

    test_assert(ut_iter_hasNext(&it) == 0);

    test_assert(corto_delete(m) == 0);
}

void test_MountContentTypeRefs_tc_selectDataFromMountAtDataNested2(
    test_MountContentTypeRefs this)
{
    test_RefMount m = test_RefMount__create(NULL, NULL, "/data/grandparent/parent");
    test_assert(m != NULL);

    ut_iter it;
    int16_t ret = corto_select("grandparent/parent/refs")
        .from("/data")
        .format("text/json")
        .iter(&it);
    test_assert(ret == 0);

    char *expect =
        "{\"sibling\":\"/config\","
         "\"nested_sibling\":\"/config/helloworld\","
         "\"at_from\":\"grandparent/parent/foo\","
         "\"inside_from\":\"grandparent/parent/foo/bar\","
         "\"inside_from_nested1\":\"grandparent/parent/foo/bar/hello\","
         "\"inside_from_nested2\":\"grandparent/parent/foo/bar/hello/world\","
         "\"parent_from\":null,"
         "\"at_root\":\".\","
         "\"from\":\".\","
         "\"root\":\"/\","
         "\"null_ref\":null}";

    test_assert(ut_iter_hasNext(&it) != 0);
    corto_record *r = ut_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "refs");
    test_assertstr(r->parent, "grandparent/parent");
    test_assertstr(r->type, "test/Refs");
    test_assertstr((char*)r->value, expect);

    test_assert(ut_iter_hasNext(&it) == 0);

    test_assert(corto_delete(m) == 0);
}

void test_MountContentTypeRefs_tc_selectDataFromMountAtRoot(
    test_MountContentTypeRefs this)
{
    test_RefMount m = test_RefMount__create(NULL, NULL, "/");
    test_assert(m != NULL);

    ut_iter it;
    int16_t ret = corto_select("refs")
        .from("/")
        .format("text/json")
        .iter(&it);
    test_assert(ret == 0);

    char *expect =
        "{\"sibling\":\"/config\","
         "\"nested_sibling\":\"/config/helloworld\","
         "\"at_from\":\"foo\","
         "\"inside_from\":\"foo/bar\","
         "\"inside_from_nested1\":\"foo/bar/hello\","
         "\"inside_from_nested2\":\"foo/bar/hello/world\","
         "\"parent_from\":null,"
         "\"at_root\":\"/data\","
         "\"from\":\"/data\","
         "\"root\":\"/\","
         "\"null_ref\":null}";

    test_assert(ut_iter_hasNext(&it) != 0);
    corto_record *r = ut_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "refs");
    test_assertstr(r->parent, ".");
    test_assertstr(r->type, "test/Refs");
    test_assertstr((char*)r->value, expect);

    test_assert(ut_iter_hasNext(&it) == 0);

    test_assert(corto_delete(m) == 0);
}

void test_MountContentTypeRefs_tc_selectDataNested1FromMountAtData(
    test_MountContentTypeRefs this)
{
    test_RefMount m = test_RefMount__create(NULL, NULL, "/data");
    test_assert(m != NULL);

    ut_iter it;
    int16_t ret = corto_select("../refs")
        .from("/data/foo")
        .format("text/json")
        .iter(&it);
    test_assert(ret == 0);

    char *expect =
        "{\"sibling\":\"/config\","
         "\"nested_sibling\":\"/config/helloworld\","
         "\"at_from\":\".\","
         "\"inside_from\":\"bar\","
         "\"inside_from_nested1\":\"bar/hello\","
         "\"inside_from_nested2\":\"bar/hello/world\","
         "\"parent_from\":null,"
         "\"at_root\":\"/data\","
         "\"from\":\"/data\","
         "\"root\":\"/\","
         "\"null_ref\":null}";

    test_assert(ut_iter_hasNext(&it) != 0);
    corto_record *r = ut_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "refs");
    test_assertstr(r->parent, "..");
    test_assertstr(r->type, "test/Refs");
    test_assertstr((char*)r->value, expect);

    test_assert(ut_iter_hasNext(&it) == 0);

    test_assert(corto_delete(m) == 0);
}

void test_MountContentTypeRefs_tc_selectDataNested1FromMountAtDataNested1(
    test_MountContentTypeRefs this)
{
    test_RefMount m = test_RefMount__create(NULL, NULL, "/data/parent");
    test_assert(m != NULL);

    ut_iter it;
    int16_t ret = corto_select("refs")
        .from("/data/parent")
        .format("text/json")
        .iter(&it);
    test_assert(ret == 0);

    char *expect =
        "{\"sibling\":\"/config\","
         "\"nested_sibling\":\"/config/helloworld\","
         "\"at_from\":\"foo\","
         "\"inside_from\":\"foo/bar\","
         "\"inside_from_nested1\":\"foo/bar/hello\","
         "\"inside_from_nested2\":\"foo/bar/hello/world\","
         "\"parent_from\":null,"
         "\"at_root\":\"/data\","
         "\"from\":\"/data\","
         "\"root\":\"/\","
         "\"null_ref\":null}";

    test_assert(ut_iter_hasNext(&it) != 0);
    corto_record *r = ut_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "refs");
    test_assertstr(r->parent, ".");
    test_assertstr(r->type, "test/Refs");
    test_assertstr((char*)r->value, expect);

    test_assert(ut_iter_hasNext(&it) == 0);

    test_assert(corto_delete(m) == 0);
}

void test_MountContentTypeRefs_tc_selectDataNested1FromMountAtDataNested2(
    test_MountContentTypeRefs this)
{
    test_RefMount m = test_RefMount__create(NULL, NULL, "/data/grandparent/parent");
    test_assert(m != NULL);

    ut_iter it;
    int16_t ret = corto_select("parent/refs")
        .from("/data/grandparent")
        .format("text/json")
        .iter(&it);
    test_assert(ret == 0);

    char *expect =
        "{\"sibling\":\"/config\","
         "\"nested_sibling\":\"/config/helloworld\","
         "\"at_from\":\"parent/foo\","
         "\"inside_from\":\"parent/foo/bar\","
         "\"inside_from_nested1\":\"parent/foo/bar/hello\","
         "\"inside_from_nested2\":\"parent/foo/bar/hello/world\","
         "\"parent_from\":null,"
         "\"at_root\":\"/data\","
         "\"from\":\"/data\","
         "\"root\":\"/\","
         "\"null_ref\":null}";

    test_assert(ut_iter_hasNext(&it) != 0);
    corto_record *r = ut_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "refs");
    test_assertstr(r->parent, "parent");
    test_assertstr(r->type, "test/Refs");
    test_assertstr((char*)r->value, expect);

    test_assert(ut_iter_hasNext(&it) == 0);

    test_assert(corto_delete(m) == 0);
}

void test_MountContentTypeRefs_tc_selectDataNested1FromMountAtRoot(
    test_MountContentTypeRefs this)
{
    test_RefMount m = test_RefMount__create(NULL, NULL, "/");
    test_assert(m != NULL);

    ut_iter it;
    int16_t ret = corto_select("../../refs")
        .from("/data/parent")
        .format("text/json")
        .iter(&it);
    test_assert(ret == 0);

    char *expect =
        "{\"sibling\":\"/config\","
         "\"nested_sibling\":\"/config/helloworld\","
         "\"at_from\":\"/foo\","
         "\"inside_from\":\"/foo/bar\","
         "\"inside_from_nested1\":\"/foo/bar/hello\","
         "\"inside_from_nested2\":\"/foo/bar/hello/world\","
         "\"parent_from\":null,"
         "\"at_root\":\"/data\","
         "\"from\":\"/data\","
         "\"root\":\"/\","
         "\"null_ref\":null}";

    test_assert(ut_iter_hasNext(&it) != 0);
    corto_record *r = ut_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "refs");
    test_assertstr(r->parent, "../..");
    test_assertstr(r->type, "test/Refs");
    test_assertstr((char*)r->value, expect);

    test_assert(ut_iter_hasNext(&it) == 0);

    test_assert(corto_delete(m) == 0);
}

void test_MountContentTypeRefs_tc_selectDataNested2FromMountAtData(
    test_MountContentTypeRefs this)
{
    test_RefMount m = test_RefMount__create(NULL, NULL, "/data");
    test_assert(m != NULL);

    ut_iter it;
    int16_t ret = corto_select("../../refs")
        .from("/data/foo/bar")
        .format("text/json")
        .iter(&it);
    test_assert(ret == 0);

    char *expect =
        "{\"sibling\":\"/config\","
         "\"nested_sibling\":\"/config/helloworld\","
         "\"at_from\":\"/data/foo\","
         "\"inside_from\":\".\","
         "\"inside_from_nested1\":\"hello\","
         "\"inside_from_nested2\":\"hello/world\","
         "\"parent_from\":null,"
         "\"at_root\":\"/data\","
         "\"from\":\"/data\","
         "\"root\":\"/\","
         "\"null_ref\":null}";

    test_assert(ut_iter_hasNext(&it) != 0);
    corto_record *r = ut_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "refs");
    test_assertstr(r->parent, "../..");
    test_assertstr(r->type, "test/Refs");
    test_assertstr((char*)r->value, expect);

    test_assert(ut_iter_hasNext(&it) == 0);

    test_assert(corto_delete(m) == 0);
}

void test_MountContentTypeRefs_tc_selectDataNested2FromMountAtDataNested1(
    test_MountContentTypeRefs this)
{
    test_RefMount m = test_RefMount__create(NULL, NULL, "/data/parent");
    test_assert(m != NULL);

    ut_iter it;
    int16_t ret = corto_select("../refs")
        .from("/data/parent/foo")
        .format("text/json")
        .iter(&it);
    test_assert(ret == 0);

    char *expect =
        "{\"sibling\":\"/config\","
         "\"nested_sibling\":\"/config/helloworld\","
         "\"at_from\":\".\","
         "\"inside_from\":\"bar\","
         "\"inside_from_nested1\":\"bar/hello\","
         "\"inside_from_nested2\":\"bar/hello/world\","
         "\"parent_from\":null,"
         "\"at_root\":\"/data\","
         "\"from\":\"/data\","
         "\"root\":\"/\","
         "\"null_ref\":null}";

    test_assert(ut_iter_hasNext(&it) != 0);
    corto_record *r = ut_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "refs");
    test_assertstr(r->parent, "..");
    test_assertstr(r->type, "test/Refs");
    test_assertstr((char*)r->value, expect);

    test_assert(ut_iter_hasNext(&it) == 0);

    test_assert(corto_delete(m) == 0);
}

void test_MountContentTypeRefs_tc_selectDataNested2FromMountAtDataNested2(
    test_MountContentTypeRefs this)
{
    test_RefMount m = test_RefMount__create(NULL, NULL, "/data/grandparent/parent");
    test_assert(m != NULL);

    ut_iter it;
    int16_t ret = corto_select("refs")
        .from("/data/grandparent/parent")
        .format("text/json")
        .iter(&it);
    test_assert(ret == 0);

    char *expect =
        "{\"sibling\":\"/config\","
         "\"nested_sibling\":\"/config/helloworld\","
         "\"at_from\":\"foo\","
         "\"inside_from\":\"foo/bar\","
         "\"inside_from_nested1\":\"foo/bar/hello\","
         "\"inside_from_nested2\":\"foo/bar/hello/world\","
         "\"parent_from\":null,"
         "\"at_root\":\"/data\","
         "\"from\":\"/data\","
         "\"root\":\"/\","
         "\"null_ref\":null}";

    test_assert(ut_iter_hasNext(&it) != 0);
    corto_record *r = ut_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "refs");
    test_assertstr(r->parent, ".");
    test_assertstr(r->type, "test/Refs");
    test_assertstr((char*)r->value, expect);

    test_assert(ut_iter_hasNext(&it) == 0);

    test_assert(corto_delete(m) == 0);
}

void test_MountContentTypeRefs_tc_selectDataNested2FromMountAtRoot(
    test_MountContentTypeRefs this)
{
    test_RefMount m = test_RefMount__create(NULL, NULL, "/");
    test_assert(m != NULL);

    ut_iter it;
    int16_t ret = corto_select("../../../refs")
        .from("/data/foo/bar")
        .format("text/json")
        .iter(&it);
    test_assert(ret == 0);

    char *expect =
        "{\"sibling\":\"/config\","
         "\"nested_sibling\":\"/config/helloworld\","
         "\"at_from\":\"/foo\","
         "\"inside_from\":\"/foo/bar\","
         "\"inside_from_nested1\":\"/foo/bar/hello\","
         "\"inside_from_nested2\":\"/foo/bar/hello/world\","
         "\"parent_from\":null,"
         "\"at_root\":\"/data\","
         "\"from\":\"/data\","
         "\"root\":\"/\","
         "\"null_ref\":null}";

    test_assert(ut_iter_hasNext(&it) != 0);
    corto_record *r = ut_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "refs");
    test_assertstr(r->parent, "../../..");
    test_assertstr(r->type, "test/Refs");
    test_assertstr((char*)r->value, expect);

    test_assert(ut_iter_hasNext(&it) == 0);

    test_assert(corto_delete(m) == 0);
}

void test_MountContentTypeRefs_tc_selectRootFromMountAtData(
    test_MountContentTypeRefs this)
{
    test_RefMount m = test_RefMount__create(NULL, NULL, "/data");
    test_assert(m != NULL);

    ut_iter it;
    int16_t ret = corto_select("data/refs")
        .from("/")
        .format("text/json")
        .iter(&it);
    test_assert(ret == 0);

    char *expect =
        "{\"sibling\":\"config\","
         "\"nested_sibling\":\"config/helloworld\","
         "\"at_from\":\"data/foo\","
         "\"inside_from\":\"data/foo/bar\","
         "\"inside_from_nested1\":\"data/foo/bar/hello\","
         "\"inside_from_nested2\":\"data/foo/bar/hello/world\","
         "\"parent_from\":null,"
         "\"at_root\":\"data\","
         "\"from\":\"data\","
         "\"root\":\".\","
         "\"null_ref\":null}";

    test_assert(ut_iter_hasNext(&it) != 0);
    corto_record *r = ut_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "refs");
    test_assertstr(r->parent, "data");
    test_assertstr(r->type, "test/Refs");
    test_assertstr((char*)r->value, expect);

    test_assert(ut_iter_hasNext(&it) == 0);

    test_assert(corto_delete(m) == 0);
}

void test_MountContentTypeRefs_tc_selectRootFromMountAtDataNested1(
    test_MountContentTypeRefs this)
{
    test_RefMount m = test_RefMount__create(NULL, NULL, "/data/parent");
    test_assert(m != NULL);

    ut_iter it;
    int16_t ret = corto_select("data/parent/refs")
        .from("/")
        .format("text/json")
        .iter(&it);
    test_assert(ret == 0);

    char *expect =
        "{\"sibling\":\"config\","
         "\"nested_sibling\":\"config/helloworld\","
         "\"at_from\":\"data/parent/foo\","
         "\"inside_from\":\"data/parent/foo/bar\","
         "\"inside_from_nested1\":\"data/parent/foo/bar/hello\","
         "\"inside_from_nested2\":\"data/parent/foo/bar/hello/world\","
         "\"parent_from\":null,"
         "\"at_root\":\"data\","
         "\"from\":\"data\","
         "\"root\":\".\","
         "\"null_ref\":null}";

    test_assert(ut_iter_hasNext(&it) != 0);
    corto_record *r = ut_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "refs");
    test_assertstr(r->parent, "data/parent");
    test_assertstr(r->type, "test/Refs");
    test_assertstr((char*)r->value, expect);

    test_assert(ut_iter_hasNext(&it) == 0);

    test_assert(corto_delete(m) == 0);
}

void test_MountContentTypeRefs_tc_selectRootFromMountAtDataNested2(
    test_MountContentTypeRefs this)
{
    test_RefMount m = test_RefMount__create(NULL, NULL, "/data/grandparent/parent");
    test_assert(m != NULL);

    ut_iter it;
    int16_t ret = corto_select("data/grandparent/parent/refs")
        .from("/")
        .format("text/json")
        .iter(&it);
    test_assert(ret == 0);

    char *expect =
        "{\"sibling\":\"config\","
         "\"nested_sibling\":\"config/helloworld\","
         "\"at_from\":\"data/grandparent/parent/foo\","
         "\"inside_from\":\"data/grandparent/parent/foo/bar\","
         "\"inside_from_nested1\":\"data/grandparent/parent/foo/bar/hello\","
         "\"inside_from_nested2\":\"data/grandparent/parent/foo/bar/hello/world\","
         "\"parent_from\":null,"
         "\"at_root\":\"data\","
         "\"from\":\"data\","
         "\"root\":\".\","
         "\"null_ref\":null}";

    test_assert(ut_iter_hasNext(&it) != 0);
    corto_record *r = ut_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "refs");
    test_assertstr(r->parent, "data/grandparent/parent");
    test_assertstr(r->type, "test/Refs");
    test_assertstr((char*)r->value, expect);

    test_assert(ut_iter_hasNext(&it) == 0);

    test_assert(corto_delete(m) == 0);
}

void test_MountContentTypeRefs_tc_selectRootFromMountAtRoot(
    test_MountContentTypeRefs this)
{
    test_RefMount m = test_RefMount__create(NULL, NULL, "/");
    test_assert(m != NULL);

    ut_iter it;
    int16_t ret = corto_select("refs")
        .from("/")
        .format("text/json")
        .iter(&it);
    test_assert(ret == 0);

    /* Because the mount point and 'from' are equal, no conversion is performed.
     * This has as side-effect that the absolute references in the value are not
     * turned into relative references. This may be counter-intuitive, but is
     * still 'correct', as the identifiers still unambiguously refer to the
     * right object. */

    char *expect =
        "{\"sibling\":\"/config\","
         "\"nested_sibling\":\"/config/helloworld\","
         "\"at_from\":\"foo\","
         "\"inside_from\":\"foo/bar\","
         "\"inside_from_nested1\":\"foo/bar/hello\","
         "\"inside_from_nested2\":\"foo/bar/hello/world\","
         "\"parent_from\":null,"
         "\"at_root\":\"/data\","
         "\"from\":\"/data\","
         "\"root\":\"/\","
         "\"null_ref\":null}";

    test_assert(ut_iter_hasNext(&it) != 0);
    corto_record *r = ut_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "refs");
    test_assertstr(r->parent, ".");
    test_assertstr(r->type, "test/Refs");
    test_assertstr((char*)r->value, expect);

    test_assert(ut_iter_hasNext(&it) == 0);

    test_assert(corto_delete(m) == 0);
}

void test_MountContentTypeRefs_tc_publishFromDataNested1ToMountAtData(
    test_MountContentTypeRefs this)
{
    test_RefMount m = (test_RefMount)corto_subscribe("*")
        .from("/data")
        .queue()
        .mount(test_RefMount_o, NULL);

    test_assert(m != NULL);

    char *json =
        "{\"sibling\":\"/config\","
         "\"nested_sibling\":\"/config/helloworld\","
         "\"at_from\":\"bar\","
         "\"inside_from\":\"bar/hello\","
         "\"inside_from_nested1\":\"bar/hello/world\","
         "\"inside_from_nested2\":\"bar/hello/world/test\","
         "\"parent_from\":\"/data\","
         "\"at_root\":\"/data\","
         "\"from\":\".\","
         "\"root\":\"/\","
         "\"null_ref\":null}";

    char *expect =
        "{\"sibling\":\"/config\","
         "\"nested_sibling\":\"/config/helloworld\","
         "\"at_from\":\"foo/bar\","
         "\"inside_from\":\"foo/bar/hello\","
         "\"inside_from_nested1\":\"foo/bar/hello/world\","
         "\"inside_from_nested2\":\"foo/bar/hello/world/test\","
         "\"parent_from\":\".\","
         "\"at_root\":\".\","
         "\"from\":\"foo\","
         "\"root\":\"/\","
         "\"null_ref\":null}";

    test_assertstr(m->last_json, NULL);

    test_assert(
        corto_publish(
            CORTO_UPDATE, "/data/foo", "obj", "test/Refs", "text/json", json) == 0);

    test_assertstr(m->last_json, expect);
    test_assertstr(m->last_id, "obj");
    test_assertstr(m->last_parent, "foo");

    test_assert(corto_delete(m) == 0);
}

void test_MountContentTypeRefs_tc_publishFromDataNested1ToMountAtDataNested1(
    test_MountContentTypeRefs this)
{
    test_RefMount m = (test_RefMount)corto_subscribe("*")
        .from("/data/foo")
        .queue()
        .mount(test_RefMount_o, NULL);

    test_assert(m != NULL);

    char *json =
        "{\"sibling\":\"/config\","
         "\"nested_sibling\":\"/config/helloworld\","
         "\"at_from\":\"bar\","
         "\"inside_from\":\"bar/hello\","
         "\"inside_from_nested1\":\"bar/hello/world\","
         "\"inside_from_nested2\":\"bar/hello/world/test\","
         "\"parent_from\":\"/data\","
         "\"at_root\":\"/data\","
         "\"from\":\".\","
         "\"root\":\"/\","
         "\"null_ref\":null}";

    char *expect =
        "{\"sibling\":\"/config\","
         "\"nested_sibling\":\"/config/helloworld\","
         "\"at_from\":\"bar\","
         "\"inside_from\":\"bar/hello\","
         "\"inside_from_nested1\":\"bar/hello/world\","
         "\"inside_from_nested2\":\"bar/hello/world/test\","
         "\"parent_from\":\"/data\","
         "\"at_root\":\"/data\","
         "\"from\":\".\","
         "\"root\":\"/\","
         "\"null_ref\":null}";

    test_assertstr(m->last_json, NULL);

    test_assert(
        corto_publish(
            CORTO_UPDATE, "/data/foo", "obj", "test/Refs", "text/json", json) == 0);

    test_assertstr(m->last_json, expect);
    test_assertstr(m->last_id, "obj");
    test_assertstr(m->last_parent, ".");

    test_assert(corto_delete(m) == 0);
}

void test_MountContentTypeRefs_tc_publishFromDataNested1ToMountAtDataNested2(
    test_MountContentTypeRefs this)
{
    test_RefMount m = (test_RefMount)corto_subscribe("*")
        .from("/data/foo/bar")
        .queue()
        .mount(test_RefMount_o, NULL);

    test_assert(m != NULL);

    char *json =
        "{\"sibling\":\"/config\","
         "\"nested_sibling\":\"/config/helloworld\","
         "\"at_from\":\"bar\","
         "\"inside_from\":\"bar/hello\","
         "\"inside_from_nested1\":\"bar/hello/world\","
         "\"inside_from_nested2\":\"bar/hello/world/test\","
         "\"parent_from\":\"/data\","
         "\"at_root\":\"/data\","
         "\"from\":\".\","
         "\"root\":\"/\","
         "\"null_ref\":null}";

    char *expect =
        "{\"sibling\":\"/config\","
         "\"nested_sibling\":\"/config/helloworld\","
         "\"at_from\":\".\","
         "\"inside_from\":\"hello\","
         "\"inside_from_nested1\":\"hello/world\","
         "\"inside_from_nested2\":\"hello/world/test\","
         "\"parent_from\":\"/data\","
         "\"at_root\":\"/data\","
         "\"from\":\"/data/foo\","
         "\"root\":\"/\","
         "\"null_ref\":null}";

    test_assertstr(m->last_json, NULL);

    test_assert(
        corto_publish(
            CORTO_UPDATE, "/data/foo", "bar/obj", "test/Refs", "text/json", json) == 0);

    test_assertstr(m->last_json, expect);
    test_assertstr(m->last_id, "obj");
    test_assertstr(m->last_parent, ".");

    test_assert(corto_delete(m) == 0);
}

void test_MountContentTypeRefs_tc_publishFromDataNested1ToMountAtRoot(
    test_MountContentTypeRefs this)
{
    test_RefMount m = (test_RefMount)corto_subscribe("*")
        .from("/")
        .queue()
        .mount(test_RefMount_o, NULL);

    test_assert(m != NULL);

    char *json =
        "{\"sibling\":\"/config\","
         "\"nested_sibling\":\"/config/helloworld\","
         "\"at_from\":\"bar\","
         "\"inside_from\":\"bar/hello\","
         "\"inside_from_nested1\":\"bar/hello/world\","
         "\"inside_from_nested2\":\"bar/hello/world/test\","
         "\"parent_from\":\"/data\","
         "\"at_root\":\"/data\","
         "\"from\":\".\","
         "\"root\":\"/\","
         "\"null_ref\":null}";

    char *expect =
        "{\"sibling\":\"config\","
         "\"nested_sibling\":\"config/helloworld\","
         "\"at_from\":\"data/foo/bar\","
         "\"inside_from\":\"data/foo/bar/hello\","
         "\"inside_from_nested1\":\"data/foo/bar/hello/world\","
         "\"inside_from_nested2\":\"data/foo/bar/hello/world/test\","
         "\"parent_from\":\"data\","
         "\"at_root\":\"data\","
         "\"from\":\"data/foo\","
         "\"root\":\".\","
         "\"null_ref\":null}";

    test_assertstr(m->last_json, NULL);

    test_assert(
        corto_publish(
            CORTO_UPDATE, "/data/foo", "obj", "test/Refs", "text/json", json) == 0);

    test_assertstr(m->last_json, expect);
    test_assertstr(m->last_id, "obj");
    test_assertstr(m->last_parent, "data/foo");

    test_assert(corto_delete(m) == 0);
}

void test_MountContentTypeRefs_tc_publishFromDataNested2ToMountAtData(
    test_MountContentTypeRefs this)
{
    test_RefMount m = (test_RefMount)corto_subscribe("*")
        .from("/data")
        .queue()
        .mount(test_RefMount_o, NULL);

    test_assert(m != NULL);

    char *json =
        "{\"sibling\":\"/config\","
         "\"nested_sibling\":\"/config/helloworld\","
         "\"at_from\":\".\","
         "\"inside_from\":\"hello\","
         "\"inside_from_nested1\":\"hello/world\","
         "\"inside_from_nested2\":\"hello/world/test\","
         "\"parent_from\":\"/data\","
         "\"at_root\":\"/data\","
         "\"from\":\".\","
         "\"root\":\"/\","
         "\"null_ref\":null}";

    char *expect =
        "{\"sibling\":\"/config\","
         "\"nested_sibling\":\"/config/helloworld\","
         "\"at_from\":\"foo/bar\","
         "\"inside_from\":\"foo/bar/hello\","
         "\"inside_from_nested1\":\"foo/bar/hello/world\","
         "\"inside_from_nested2\":\"foo/bar/hello/world/test\","
         "\"parent_from\":\".\","
         "\"at_root\":\".\","
         "\"from\":\"foo/bar\","
         "\"root\":\"/\","
         "\"null_ref\":null}";

    test_assertstr(m->last_json, NULL);

    test_assert(
        corto_publish(
            CORTO_UPDATE, "/data/foo/bar", "obj", "test/Refs", "text/json", json) == 0);

    test_assertstr(m->last_json, expect);
    test_assertstr(m->last_id, "obj");
    test_assertstr(m->last_parent, "foo/bar");

    test_assert(corto_delete(m) == 0);
}

void test_MountContentTypeRefs_tc_publishFromDataNested2ToMountAtDataNested1(
    test_MountContentTypeRefs this)
{
    test_RefMount m = (test_RefMount)corto_subscribe("*")
        .from("/data/foo")
        .queue()
        .mount(test_RefMount_o, NULL);

    test_assert(m != NULL);

    char *json =
        "{\"sibling\":\"/config\","
         "\"nested_sibling\":\"/config/helloworld\","
         "\"at_from\":\".\","
         "\"inside_from\":\"hello\","
         "\"inside_from_nested1\":\"hello/world\","
         "\"inside_from_nested2\":\"hello/world/test\","
         "\"parent_from\":\"/data\","
         "\"at_root\":\"/data\","
         "\"from\":\".\","
         "\"root\":\"/\","
         "\"null_ref\":null}";

    char *expect =
        "{\"sibling\":\"/config\","
         "\"nested_sibling\":\"/config/helloworld\","
         "\"at_from\":\"bar\","
         "\"inside_from\":\"bar/hello\","
         "\"inside_from_nested1\":\"bar/hello/world\","
         "\"inside_from_nested2\":\"bar/hello/world/test\","
         "\"parent_from\":\"/data\","
         "\"at_root\":\"/data\","
         "\"from\":\"bar\","
         "\"root\":\"/\","
         "\"null_ref\":null}";

    test_assertstr(m->last_json, NULL);

    test_assert(
        corto_publish(
            CORTO_UPDATE, "/data/foo/bar", "obj", "test/Refs", "text/json", json) == 0);

    test_assertstr(m->last_json, expect);
    test_assertstr(m->last_id, "obj");
    test_assertstr(m->last_parent, "bar");

    test_assert(corto_delete(m) == 0);
}

void test_MountContentTypeRefs_tc_publishFromDataNested2ToMountAtDataNested2(
    test_MountContentTypeRefs this)
{
    test_RefMount m = (test_RefMount)corto_subscribe("*")
        .from("/data/foo/bar")
        .queue()
        .mount(test_RefMount_o, NULL);

    test_assert(m != NULL);

    char *json =
        "{\"sibling\":\"/config\","
         "\"nested_sibling\":\"/config/helloworld\","
         "\"at_from\":\".\","
         "\"inside_from\":\"hello\","
         "\"inside_from_nested1\":\"hello/world\","
         "\"inside_from_nested2\":\"hello/world/test\","
         "\"parent_from\":\"/data\","
         "\"at_root\":\"/data\","
         "\"from\":\".\","
         "\"root\":\"/\","
         "\"null_ref\":null}";

    char *expect =
        "{\"sibling\":\"/config\","
         "\"nested_sibling\":\"/config/helloworld\","
         "\"at_from\":\".\","
         "\"inside_from\":\"hello\","
         "\"inside_from_nested1\":\"hello/world\","
         "\"inside_from_nested2\":\"hello/world/test\","
         "\"parent_from\":\"/data\","
         "\"at_root\":\"/data\","
         "\"from\":\".\","
         "\"root\":\"/\","
         "\"null_ref\":null}";

    test_assertstr(m->last_json, NULL);

    test_assert(
        corto_publish(
            CORTO_UPDATE, "/data/foo/bar", "obj", "test/Refs", "text/json", json) == 0);

    test_assertstr(m->last_json, expect);
    test_assertstr(m->last_id, "obj");
    test_assertstr(m->last_parent, ".");

    test_assert(corto_delete(m) == 0);
}

void test_MountContentTypeRefs_tc_publishFromDataNested2ToMountAtRoot(
    test_MountContentTypeRefs this)
{
    test_RefMount m = (test_RefMount)corto_subscribe("*")
        .from("/")
        .queue()
        .mount(test_RefMount_o, NULL);

    test_assert(m != NULL);

    char *json =
        "{\"sibling\":\"/config\","
         "\"nested_sibling\":\"/config/helloworld\","
         "\"at_from\":\".\","
         "\"inside_from\":\"hello\","
         "\"inside_from_nested1\":\"hello/world\","
         "\"inside_from_nested2\":\"hello/world/test\","
         "\"parent_from\":\"/data\","
         "\"at_root\":\"/data\","
         "\"from\":\".\","
         "\"root\":\"/\","
         "\"null_ref\":null}";

    char *expect =
        "{\"sibling\":\"config\","
         "\"nested_sibling\":\"config/helloworld\","
         "\"at_from\":\"data/foo/bar\","
         "\"inside_from\":\"data/foo/bar/hello\","
         "\"inside_from_nested1\":\"data/foo/bar/hello/world\","
         "\"inside_from_nested2\":\"data/foo/bar/hello/world/test\","
         "\"parent_from\":\"data\","
         "\"at_root\":\"data\","
         "\"from\":\"data/foo/bar\","
         "\"root\":\".\","
         "\"null_ref\":null}";

    test_assertstr(m->last_json, NULL);

    test_assert(
        corto_publish(
            CORTO_UPDATE, "/data/foo/bar", "obj", "test/Refs", "text/json", json) == 0);

    test_assertstr(m->last_json, expect);
    test_assertstr(m->last_id, "obj");
    test_assertstr(m->last_parent, "data/foo/bar");

    test_assert(corto_delete(m) == 0);
}

void test_MountContentTypeRefs_tc_publishFromDataToMountAtData(
    test_MountContentTypeRefs this)
{
    test_RefMount m = (test_RefMount)corto_subscribe("*")
        .from("/data")
        .queue()
        .mount(test_RefMount_o, NULL);

    test_assert(m != NULL);

    char *json =
        "{\"sibling\":\"/config\","
         "\"nested_sibling\":\"/config/helloworld\","
         "\"at_from\":\"foo\","
         "\"inside_from\":\"foo/bar\","
         "\"inside_from_nested1\":\"foo/bar/hello\","
         "\"inside_from_nested2\":\"foo/bar/hello/world\","
         "\"parent_from\":\"/\","
         "\"at_root\":\"/data\"," /* Deliberately use full path to validate that
                                   * no serialization takes place (should
                                   * otherwise be '.') */
         "\"from\":\".\","
         "\"root\":\"/\","
         "\"null_ref\":null}";

    char *expect =
        "{\"sibling\":\"/config\","
         "\"nested_sibling\":\"/config/helloworld\","
         "\"at_from\":\"foo\","
         "\"inside_from\":\"foo/bar\","
         "\"inside_from_nested1\":\"foo/bar/hello\","
         "\"inside_from_nested2\":\"foo/bar/hello/world\","
         "\"parent_from\":\"/\","
         "\"at_root\":\"/data\","
         "\"from\":\".\","
         "\"root\":\"/\","
         "\"null_ref\":null}";

    test_assertstr(m->last_json, NULL);

    test_assert(
        corto_publish(
            CORTO_UPDATE, "/data", "obj", "test/Refs", "text/json", json) == 0);

    test_assertstr(m->last_json, expect);
    test_assertstr(m->last_id, "obj");
    test_assertstr(m->last_parent, ".");

    test_assert(corto_delete(m) == 0);
}

void test_MountContentTypeRefs_tc_publishFromDataToMountAtDataNested1(
    test_MountContentTypeRefs this)
{
    test_RefMount m = (test_RefMount)corto_subscribe("*")
        .from("/data/foo")
        .queue()
        .mount(test_RefMount_o, NULL);

    test_assert(m != NULL);

    char *json =
        "{\"sibling\":\"/config\","
         "\"nested_sibling\":\"/config/helloworld\","
         "\"at_from\":\"foo\","
         "\"inside_from\":\"foo/bar\","
         "\"inside_from_nested1\":\"foo/bar/hello\","
         "\"inside_from_nested2\":\"foo/bar/hello/world\","
         "\"parent_from\":\"/\","
         "\"at_root\":\".\","
         "\"from\":\".\","
         "\"root\":\"/\","
         "\"null_ref\":null}";

    char *expect =
        "{\"sibling\":\"/config\","
         "\"nested_sibling\":\"/config/helloworld\","
         "\"at_from\":\".\","
         "\"inside_from\":\"bar\","
         "\"inside_from_nested1\":\"bar/hello\","
         "\"inside_from_nested2\":\"bar/hello/world\","
         "\"parent_from\":\"/\","
         "\"at_root\":\"/data\","
         "\"from\":\"/data\","
         "\"root\":\"/\","
         "\"null_ref\":null}";

    test_assertstr(m->last_json, NULL);

    test_assert(
        corto_publish(
            CORTO_UPDATE, "/data", "foo/obj", "test/Refs", "text/json", json) == 0);

    test_assertstr(m->last_json, expect);
    test_assertstr(m->last_id, "obj");
    test_assertstr(m->last_parent, ".");

    test_assert(corto_delete(m) == 0);
}

void test_MountContentTypeRefs_tc_publishFromDataToMountAtDataNested2(
    test_MountContentTypeRefs this)
{
    test_RefMount m = (test_RefMount)corto_subscribe("*")
        .from("/data/foo/bar")
        .queue()
        .mount(test_RefMount_o, NULL);

    test_assert(m != NULL);

    char *json =
        "{\"sibling\":\"/config\","
         "\"nested_sibling\":\"/config/helloworld\","
         "\"at_from\":\"foo\","
         "\"inside_from\":\"foo/bar\","
         "\"inside_from_nested1\":\"foo/bar/hello\","
         "\"inside_from_nested2\":\"foo/bar/hello/world\","
         "\"parent_from\":\"/\","
         "\"at_root\":\".\","
         "\"from\":\".\","
         "\"root\":\"/\","
         "\"null_ref\":null}";

    char *expect =
        "{\"sibling\":\"/config\","
         "\"nested_sibling\":\"/config/helloworld\","
         "\"at_from\":\"/data/foo\","
         "\"inside_from\":\".\","
         "\"inside_from_nested1\":\"hello\","
         "\"inside_from_nested2\":\"hello/world\","
         "\"parent_from\":\"/\","
         "\"at_root\":\"/data\","
         "\"from\":\"/data\","
         "\"root\":\"/\","
         "\"null_ref\":null}";

    test_assertstr(m->last_json, NULL);

    test_assert(
        corto_publish(
            CORTO_UPDATE, "/data", "foo/bar/obj", "test/Refs", "text/json", json) == 0);

    test_assertstr(m->last_json, expect);
    test_assertstr(m->last_id, "obj");
    test_assertstr(m->last_parent, ".");

    test_assert(corto_delete(m) == 0);
}

void test_MountContentTypeRefs_tc_publishFromDataToMountAtRoot(
    test_MountContentTypeRefs this)
{
    test_RefMount m = (test_RefMount)corto_subscribe("data/*")
        .from("/")
        .queue()
        .mount(test_RefMount_o, NULL);

    test_assert(m != NULL);

    char *json =
        "{\"sibling\":\"/config\","
         "\"nested_sibling\":\"/config/helloworld\","
         "\"at_from\":\"foo\","
         "\"inside_from\":\"foo/bar\","
         "\"inside_from_nested1\":\"foo/bar/hello\","
         "\"inside_from_nested2\":\"foo/bar/hello/world\","
         "\"parent_from\":null,"
         "\"at_root\":\".\","
         "\"from\":\".\","
         "\"root\":\"/\","
         "\"null_ref\":null}";

    char *expect =
        "{\"sibling\":\"config\","
         "\"nested_sibling\":\"config/helloworld\","
         "\"at_from\":\"data/foo\","
         "\"inside_from\":\"data/foo/bar\","
         "\"inside_from_nested1\":\"data/foo/bar/hello\","
         "\"inside_from_nested2\":\"data/foo/bar/hello/world\","
         "\"parent_from\":null,"
         "\"at_root\":\"data\","
         "\"from\":\"data\","
         "\"root\":\".\","
         "\"null_ref\":null}";

    test_assertstr(m->last_json, NULL);

    test_assert(
        corto_publish(
            CORTO_UPDATE, "/data", "obj", "test/Refs", "text/json", json) == 0);

    test_assertstr(m->last_json, expect);
    test_assertstr(m->last_id, "obj");
    test_assertstr(m->last_parent, "data");

    test_assert(corto_delete(m) == 0);
}

void test_MountContentTypeRefs_tc_publishFromRootToMountAtData(
    test_MountContentTypeRefs this)
{
    test_RefMount m = (test_RefMount)corto_subscribe("*")
        .from("/data")
        .queue()
        .mount(test_RefMount_o, NULL);

    test_assert(m != NULL);

    char *json =
        "{\"sibling\":\"config\","
         "\"nested_sibling\":\"config/helloworld\","
         "\"at_from\":\"data\","
         "\"inside_from\":\"data/foo\","
         "\"inside_from_nested1\":\"data/foo/bar\","
         "\"inside_from_nested2\":\"data/foo/bar/hello\","
         "\"parent_from\":null,"
         "\"at_root\":\"data\","
         "\"from\":\".\","
         "\"root\":\".\","
         "\"null_ref\":null}";

     char *expect =
         "{\"sibling\":\"/config\","
          "\"nested_sibling\":\"/config/helloworld\","
          "\"at_from\":\".\","
          "\"inside_from\":\"foo\","
          "\"inside_from_nested1\":\"foo/bar\","
          "\"inside_from_nested2\":\"foo/bar/hello\","
          "\"parent_from\":null,"
          "\"at_root\":\".\","
          "\"from\":\"/\","
          "\"root\":\"/\","
          "\"null_ref\":null}";

    test_assertstr(m->last_json, NULL);

    test_assert(
        corto_publish(
            CORTO_UPDATE, "/", "/data/obj", "test/Refs", "text/json", json) == 0);

    test_assertstr(m->last_json, expect);
    test_assertstr(m->last_id, "obj");
    test_assertstr(m->last_parent, ".");

    test_assert(corto_delete(m) == 0);
}

void test_MountContentTypeRefs_tc_publishFromRootToMountAtDataNested1(
    test_MountContentTypeRefs this)
{
    test_RefMount m = (test_RefMount)corto_subscribe("*")
        .from("/data/foo")
        .queue()
        .mount(test_RefMount_o, NULL);

    test_assert(m != NULL);

    char *json =
        "{\"sibling\":\"config\","
         "\"nested_sibling\":\"config/helloworld\","
         "\"at_from\":\"data\","
         "\"inside_from\":\"data/foo\","
         "\"inside_from_nested1\":\"data/foo/bar\","
         "\"inside_from_nested2\":\"data/foo/bar/hello\","
         "\"parent_from\":null,"
         "\"at_root\":\"data\","
         "\"from\":\".\","
         "\"root\":\".\","
         "\"null_ref\":null}";

     char *expect =
         "{\"sibling\":\"/config\","
          "\"nested_sibling\":\"/config/helloworld\","
          "\"at_from\":\"/data\","
          "\"inside_from\":\".\","
          "\"inside_from_nested1\":\"bar\","
          "\"inside_from_nested2\":\"bar/hello\","
          "\"parent_from\":null,"
          "\"at_root\":\"/data\","
          "\"from\":\"/\","
          "\"root\":\"/\","
          "\"null_ref\":null}";

    test_assertstr(m->last_json, NULL);

    test_assert(
        corto_publish(
            CORTO_UPDATE, "/", "data/foo/obj", "test/Refs", "text/json", json) == 0);

    test_assertstr(m->last_json, expect);
    test_assertstr(m->last_id, "obj");
    test_assertstr(m->last_parent, ".");

    test_assert(corto_delete(m) == 0);
}

void test_MountContentTypeRefs_tc_publishFromRootToMountAtDataNested2(
    test_MountContentTypeRefs this)
{
    test_RefMount m = (test_RefMount)corto_subscribe("*")
        .from("/data/foo/bar")
        .queue()
        .mount(test_RefMount_o, NULL);

    test_assert(m != NULL);

    char *json =
        "{\"sibling\":\"config\","
         "\"nested_sibling\":\"config/helloworld\","
         "\"at_from\":\"data\","
         "\"inside_from\":\"data/foo\","
         "\"inside_from_nested1\":\"data/foo/bar\","
         "\"inside_from_nested2\":\"data/foo/bar/hello\","
         "\"parent_from\":null,"
         "\"at_root\":\"data\","
         "\"from\":\".\","
         "\"root\":\".\","
         "\"null_ref\":null}";

     char *expect =
         "{\"sibling\":\"/config\","
          "\"nested_sibling\":\"/config/helloworld\","
          "\"at_from\":\"/data\","
          "\"inside_from\":\"/data/foo\","
          "\"inside_from_nested1\":\".\","
          "\"inside_from_nested2\":\"hello\","
          "\"parent_from\":null,"
          "\"at_root\":\"/data\","
          "\"from\":\"/\","
          "\"root\":\"/\","
          "\"null_ref\":null}";

    test_assertstr(m->last_json, NULL);

    test_assert(
        corto_publish(
            CORTO_UPDATE, "/", "data/foo/bar/obj", "test/Refs", "text/json", json) == 0);

    test_assertstr(m->last_json, expect);
    test_assertstr(m->last_id, "obj");
    test_assertstr(m->last_parent, ".");

    test_assert(corto_delete(m) == 0);
}

void test_MountContentTypeRefs_tc_publishFromRootToMountAtRoot(
    test_MountContentTypeRefs this)
{
    test_RefMount m = (test_RefMount)corto_subscribe("*")
        .from("/")
        .queue()
        .mount(test_RefMount_o, NULL);

    test_assert(m != NULL);

    char *json =
        "{\"sibling\":\"config\","
         "\"nested_sibling\":\"config/helloworld\","
         "\"at_from\":\"data\","
         "\"inside_from\":\"data/foo\","
         "\"inside_from_nested1\":\"data/foo/bar\","
         "\"inside_from_nested2\":\"data/foo/bar/hello\","
         "\"parent_from\":null,"
         "\"at_root\":\"data\","
         "\"from\":\".\","
         "\"root\":\".\","
         "\"null_ref\":null}";

     char *expect =
         "{\"sibling\":\"config\","
          "\"nested_sibling\":\"config/helloworld\","
          "\"at_from\":\"data\","
          "\"inside_from\":\"data/foo\","
          "\"inside_from_nested1\":\"data/foo/bar\","
          "\"inside_from_nested2\":\"data/foo/bar/hello\","
          "\"parent_from\":null,"
          "\"at_root\":\"data\","
          "\"from\":\".\","
          "\"root\":\".\","
          "\"null_ref\":null}";

    test_assertstr(m->last_json, NULL);

    test_assert(
        corto_publish(
            CORTO_UPDATE, "/", "data/obj", "test/Refs", "text/json", json) == 0);

    test_assertstr(m->last_json, expect);
    test_assertstr(m->last_id, "obj");
    test_assertstr(m->last_parent, "data");

    test_assert(corto_delete(m) == 0);
}
