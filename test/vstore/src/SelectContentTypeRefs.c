/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

void test_SelectContentTypeRefs_setup(
    test_SelectContentTypeRefs this)
{
    this->sibling = corto_lookup(NULL, "config");
    this->nested_sibling = corto_create(root_o, "config/helloworld", corto_void_o);
    this->nest0 = corto_lookup(NULL, "data");
    this->nest1 = corto_create(root_o, "data/foo", corto_void_o);
    this->nest2 = corto_create(root_o, "data/foo/bar", corto_void_o);
    this->nest3 = corto_create(root_o, "data/foo/bar/hello", corto_void_o);
    this->nest4 = corto_create(root_o, "data/foo/bar/hello/world", corto_void_o);
    this->nest5 = corto_create(root_o, "data/foo/bar/hello/world/test", corto_void_o);
}


void test_SelectContentTypeRefs_tc_selectIdWithRefsFromNested1(
    test_SelectContentTypeRefs this)
{
    test_Refs *refs = corto_create(root_o, "data/refs", test_Refs_o);
    corto_set_ref(&refs->at_from, this->nest1);
    corto_set_ref(&refs->inside_from, this->nest2);
    corto_set_ref(&refs->inside_from_nested1, this->nest3);
    corto_set_ref(&refs->inside_from_nested2, this->nest4);
    corto_set_ref(&refs->parent_from, root_o);
    corto_set_ref(&refs->at_root, this->nest0);
    corto_set_ref(&refs->sibling, this->sibling);
    corto_set_ref(&refs->nested_sibling, this->nested_sibling);
    corto_set_ref(&refs->from, this->nest0);
    corto_set_ref(&refs->root, root_o);
    corto_set_ref(&refs->null_ref, NULL);

    ut_iter it;
    corto_record *r;
    corto_select("refs").from("data").format("text/json").iter(&it);

    test_assert(ut_iter_hasNext(&it));
    r = ut_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "refs");
    test_assertstr(r->parent, ".");
    test_assertstr(r->type, "/test/Refs");
    test_assert(r->value != 0);

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

    test_assertstr((char*)r->value, json);

    test_assert(ut_iter_hasNext(&it) == 0);
    test_assert(corto_delete(refs) == 0);
}


void test_SelectContentTypeRefs_tc_selectIdWithRefsFromNested2(
    test_SelectContentTypeRefs this)
{
    test_Refs *refs = corto_create(root_o, "data/foo/refs", test_Refs_o);
    corto_set_ref(&refs->at_from, this->nest2);
    corto_set_ref(&refs->inside_from, this->nest3);
    corto_set_ref(&refs->inside_from_nested1, this->nest4);
    corto_set_ref(&refs->inside_from_nested2, this->nest5);
    corto_set_ref(&refs->parent_from, this->nest0);
    corto_set_ref(&refs->at_root, this->nest0);
    corto_set_ref(&refs->sibling, this->sibling);
    corto_set_ref(&refs->nested_sibling, this->nested_sibling);
    corto_set_ref(&refs->from, this->nest1);
    corto_set_ref(&refs->root, root_o);
    corto_set_ref(&refs->null_ref, NULL);

    ut_iter it;
    corto_record *r;
    corto_select("refs").from("data/foo").format("text/json").iter(&it);

    test_assert(ut_iter_hasNext(&it));
    r = ut_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "refs");
    test_assertstr(r->parent, ".");
    test_assertstr(r->type, "/test/Refs");
    test_assert(r->value != 0);

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

    test_assertstr((char*)r->value, json);

    test_assert(ut_iter_hasNext(&it) == 0);
    test_assert(corto_delete(refs) == 0);
}


void test_SelectContentTypeRefs_tc_selectIdWithRefsFromRoot(
    test_SelectContentTypeRefs this)
{
    test_Refs *refs = corto_create(root_o, "refs", test_Refs_o);
    corto_set_ref(&refs->at_from, this->nest0);
    corto_set_ref(&refs->inside_from, this->nest1);
    corto_set_ref(&refs->inside_from_nested1, this->nest2);
    corto_set_ref(&refs->inside_from_nested2, this->nest3);
    corto_set_ref(&refs->parent_from, NULL);
    corto_set_ref(&refs->at_root, this->nest0);
    corto_set_ref(&refs->sibling, NULL);
    corto_set_ref(&refs->nested_sibling, NULL);
    corto_set_ref(&refs->from, root_o);
    corto_set_ref(&refs->root, root_o);
    corto_set_ref(&refs->null_ref, NULL);

    ut_iter it;
    corto_record *r;
    corto_select("refs").format("text/json").iter(&it);

    test_assert(ut_iter_hasNext(&it));
    r = ut_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "refs");
    test_assertstr(r->parent, "");
    test_assertstr(r->type, "/test/Refs");
    test_assert(r->value != 0);

    char *json =
        "{\"sibling\":null,"
         "\"nested_sibling\":null,"
         "\"at_from\":\"/data\","
         "\"inside_from\":\"/data/foo\","
         "\"inside_from_nested1\":\"/data/foo/bar\","
         "\"inside_from_nested2\":\"/data/foo/bar/hello\","
         "\"parent_from\":null,"
         "\"at_root\":\"/data\","
         "\"from\":\"/\","
         "\"root\":\"/\","
         "\"null_ref\":null}";

    test_assertstr((char*)r->value, json);

    test_assert(ut_iter_hasNext(&it) == 0);
    test_assert(corto_delete(refs) == 0);
}


void test_SelectContentTypeRefs_tc_selectScopeNestedWithRefsFromNested1(
    test_SelectContentTypeRefs this)
{
    test_Refs *refs = corto_create(root_o, "data/grandparent/parent/refs", test_Refs_o);
    corto_set_ref(&refs->at_from, this->nest1);
    corto_set_ref(&refs->inside_from, this->nest2);
    corto_set_ref(&refs->inside_from_nested1, this->nest3);
    corto_set_ref(&refs->inside_from_nested2, this->nest4);
    corto_set_ref(&refs->parent_from, root_o);
    corto_set_ref(&refs->at_root, this->nest0);
    corto_set_ref(&refs->sibling, this->sibling);
    corto_set_ref(&refs->nested_sibling, this->nested_sibling);
    corto_set_ref(&refs->from, this->nest0);
    corto_set_ref(&refs->root, root_o);
    corto_set_ref(&refs->null_ref, NULL);

    ut_iter it;
    corto_record *r;
    corto_select("grandparent/parent/refs").from("data").format("text/json").iter(&it);

    test_assert(ut_iter_hasNext(&it));
    r = ut_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "refs");
    test_assertstr(r->parent, "grandparent/parent");
    test_assertstr(r->type, "/test/Refs");
    test_assert(r->value != 0);

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

    test_assertstr((char*)r->value, json);

    test_assert(ut_iter_hasNext(&it) == 0);
    test_assert(corto_delete(refs) == 0);
}


void test_SelectContentTypeRefs_tc_selectScopeNestedWithRefsFromNested2(
    test_SelectContentTypeRefs this)
{
    test_Refs *refs = corto_create(root_o, "data/foo/grandparent/parent/refs", test_Refs_o);
    corto_set_ref(&refs->at_from, this->nest2);
    corto_set_ref(&refs->inside_from, this->nest3);
    corto_set_ref(&refs->inside_from_nested1, this->nest4);
    corto_set_ref(&refs->inside_from_nested2, this->nest5);
    corto_set_ref(&refs->parent_from, this->nest0);
    corto_set_ref(&refs->at_root, this->nest0);
    corto_set_ref(&refs->sibling, this->sibling);
    corto_set_ref(&refs->nested_sibling, this->nested_sibling);
    corto_set_ref(&refs->from, this->nest1);
    corto_set_ref(&refs->root, root_o);
    corto_set_ref(&refs->null_ref, NULL);

    ut_iter it;
    corto_record *r;
    corto_select("grandparent/parent/refs").from("data/foo").format("text/json").iter(&it);

    test_assert(ut_iter_hasNext(&it));
    r = ut_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "refs");
    test_assertstr(r->parent, "grandparent/parent");
    test_assertstr(r->type, "/test/Refs");
    test_assert(r->value != 0);

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

    test_assertstr((char*)r->value, json);

    test_assert(ut_iter_hasNext(&it) == 0);
    test_assert(corto_delete(refs) == 0);
}


void test_SelectContentTypeRefs_tc_selectScopeNestedWithRefsFromRoot(
    test_SelectContentTypeRefs this)
{
    test_Refs *refs = corto_create(root_o, "grandparent/parent/refs", test_Refs_o);
    corto_set_ref(&refs->at_from, this->nest0);
    corto_set_ref(&refs->inside_from, this->nest1);
    corto_set_ref(&refs->inside_from_nested1, this->nest2);
    corto_set_ref(&refs->inside_from_nested2, this->nest3);
    corto_set_ref(&refs->parent_from, NULL);
    corto_set_ref(&refs->at_root, this->nest0);
    corto_set_ref(&refs->sibling, NULL);
    corto_set_ref(&refs->nested_sibling, NULL);
    corto_set_ref(&refs->from, root_o);
    corto_set_ref(&refs->root, root_o);
    corto_set_ref(&refs->null_ref, NULL);

    ut_iter it;
    corto_record *r;
    corto_select("grandparent/parent/").format("text/json").iter(&it);

    test_assert(ut_iter_hasNext(&it));
    r = ut_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "refs");
    test_assertstr(r->parent, "/grandparent/parent");
    test_assertstr(r->type, "/test/Refs");
    test_assert(r->value != 0);

    char *json =
        "{\"sibling\":null,"
         "\"nested_sibling\":null,"
         "\"at_from\":\"/data\","
         "\"inside_from\":\"/data/foo\","
         "\"inside_from_nested1\":\"/data/foo/bar\","
         "\"inside_from_nested2\":\"/data/foo/bar/hello\","
         "\"parent_from\":null,"
         "\"at_root\":\"/data\","
         "\"from\":\"/\","
         "\"root\":\"/\","
         "\"null_ref\":null}";

    test_assertstr((char*)r->value, json);

    test_assert(ut_iter_hasNext(&it) == 0);
    test_assert(corto_delete(refs) == 0);
}


void test_SelectContentTypeRefs_tc_selectScopeWithRefsFromNested1(
    test_SelectContentTypeRefs this)
{
    test_Refs *refs = corto_create(root_o, "data/parent/refs", test_Refs_o);
    corto_set_ref(&refs->at_from, this->nest1);
    corto_set_ref(&refs->inside_from, this->nest2);
    corto_set_ref(&refs->inside_from_nested1, this->nest3);
    corto_set_ref(&refs->inside_from_nested2, this->nest4);
    corto_set_ref(&refs->parent_from, root_o);
    corto_set_ref(&refs->at_root, this->nest0);
    corto_set_ref(&refs->sibling, this->sibling);
    corto_set_ref(&refs->nested_sibling, this->nested_sibling);
    corto_set_ref(&refs->from, this->nest0);
    corto_set_ref(&refs->root, root_o);
    corto_set_ref(&refs->null_ref, NULL);

    ut_iter it;
    corto_record *r;
    corto_select("parent/refs").from("data").format("text/json").iter(&it);

    test_assert(ut_iter_hasNext(&it));
    r = ut_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "refs");
    test_assertstr(r->parent, "parent");
    test_assertstr(r->type, "/test/Refs");
    test_assert(r->value != 0);

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

    test_assertstr((char*)r->value, json);

    test_assert(ut_iter_hasNext(&it) == 0);
    test_assert(corto_delete(refs) == 0);
}


void test_SelectContentTypeRefs_tc_selectScopeWithRefsFromNested2(
    test_SelectContentTypeRefs this)
{
    test_Refs *refs = corto_create(root_o, "data/foo/parent/refs", test_Refs_o);
    corto_set_ref(&refs->at_from, this->nest2);
    corto_set_ref(&refs->inside_from, this->nest3);
    corto_set_ref(&refs->inside_from_nested1, this->nest4);
    corto_set_ref(&refs->inside_from_nested2, this->nest5);
    corto_set_ref(&refs->parent_from, this->nest0);
    corto_set_ref(&refs->at_root, this->nest0);
    corto_set_ref(&refs->sibling, this->sibling);
    corto_set_ref(&refs->nested_sibling, this->nested_sibling);
    corto_set_ref(&refs->from, this->nest1);
    corto_set_ref(&refs->root, root_o);
    corto_set_ref(&refs->null_ref, NULL);

    ut_iter it;
    corto_record *r;
    corto_select("parent/refs").from("data/foo").format("text/json").iter(&it);

    test_assert(ut_iter_hasNext(&it));
    r = ut_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "refs");
    test_assertstr(r->parent, "parent");
    test_assertstr(r->type, "/test/Refs");
    test_assert(r->value != 0);

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

    test_assertstr((char*)r->value, json);

    test_assert(ut_iter_hasNext(&it) == 0);
    test_assert(corto_delete(refs) == 0);
}


void test_SelectContentTypeRefs_tc_selectScopeWithRefsFromRoot(
    test_SelectContentTypeRefs this)
{
    test_Refs *refs = corto_create(root_o, "parent/refs", test_Refs_o);
    corto_set_ref(&refs->at_from, this->nest0);
    corto_set_ref(&refs->inside_from, this->nest1);
    corto_set_ref(&refs->inside_from_nested1, this->nest2);
    corto_set_ref(&refs->inside_from_nested2, this->nest3);
    corto_set_ref(&refs->parent_from, NULL);
    corto_set_ref(&refs->at_root, this->nest0);
    corto_set_ref(&refs->sibling, NULL);
    corto_set_ref(&refs->nested_sibling, NULL);
    corto_set_ref(&refs->from, root_o);
    corto_set_ref(&refs->root, root_o);
    corto_set_ref(&refs->null_ref, NULL);

    ut_iter it;
    corto_record *r;
    corto_select("parent/").format("text/json").iter(&it);

    test_assert(ut_iter_hasNext(&it));
    r = ut_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "refs");
    test_assertstr(r->parent, "/parent");
    test_assertstr(r->type, "/test/Refs");
    test_assert(r->value != 0);

    char *json =
        "{\"sibling\":null,"
         "\"nested_sibling\":null,"
         "\"at_from\":\"/data\","
         "\"inside_from\":\"/data/foo\","
         "\"inside_from_nested1\":\"/data/foo/bar\","
         "\"inside_from_nested2\":\"/data/foo/bar/hello\","
         "\"parent_from\":null,"
         "\"at_root\":\"/data\","
         "\"from\":\"/\","
         "\"root\":\"/\","
         "\"null_ref\":null}";

    test_assertstr((char*)r->value, json);

    test_assert(ut_iter_hasNext(&it) == 0);
    test_assert(corto_delete(refs) == 0);
}


void test_SelectContentTypeRefs_tc_selectThisWithRefsFromNested1(
    test_SelectContentTypeRefs this)
{
    test_Refs *refs = corto_create(root_o, "data/refs", test_Refs_o);

    /* data/refs does not contain objects, so pretend like from = /data */
    corto_set_ref(&refs->at_from, this->nest1);
    corto_set_ref(&refs->inside_from, this->nest2);
    corto_set_ref(&refs->inside_from_nested1, this->nest3);
    corto_set_ref(&refs->inside_from_nested2, this->nest4);
    corto_set_ref(&refs->parent_from, root_o);
    corto_set_ref(&refs->at_root, this->nest0);
    corto_set_ref(&refs->sibling, this->sibling);
    corto_set_ref(&refs->nested_sibling, this->nested_sibling);
    corto_set_ref(&refs->from, this->nest0);
    corto_set_ref(&refs->root, root_o);
    corto_set_ref(&refs->null_ref, NULL);

    ut_iter it;
    corto_record *r;
    corto_select(".").from("data/refs").format("text/json").iter(&it);

    test_assert(ut_iter_hasNext(&it));
    r = ut_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "refs");
    test_assertstr(r->parent, "..");
    test_assertstr(r->type, "/test/Refs");
    test_assert(r->value != 0);

    char *json =
        "{\"sibling\":\"/config\","
         "\"nested_sibling\":\"/config/helloworld\","
         "\"at_from\":\"/data/foo\","
         "\"inside_from\":\"/data/foo/bar\","
         "\"inside_from_nested1\":\"/data/foo/bar/hello\","
         "\"inside_from_nested2\":\"/data/foo/bar/hello/world\","
         "\"parent_from\":\"/\","
         "\"at_root\":\"/data\","
         "\"from\":\"/data\","
         "\"root\":\"/\","
         "\"null_ref\":null}";

    test_assertstr((char*)r->value, json);

    test_assert(ut_iter_hasNext(&it) == 0);
    test_assert(corto_delete(refs) == 0);
}


void test_SelectContentTypeRefs_tc_selectThisWithRefsFromNested2(
    test_SelectContentTypeRefs this)
{
    test_Refs *refs = corto_create(root_o, "data/parent/refs", test_Refs_o);

    /* data/refs does not contain objects, so pretend like from = /data */
    corto_set_ref(&refs->at_from, this->nest1);
    corto_set_ref(&refs->inside_from, this->nest2);
    corto_set_ref(&refs->inside_from_nested1, this->nest3);
    corto_set_ref(&refs->inside_from_nested2, this->nest4);
    corto_set_ref(&refs->parent_from, root_o);
    corto_set_ref(&refs->at_root, this->nest0);
    corto_set_ref(&refs->sibling, this->sibling);
    corto_set_ref(&refs->nested_sibling, this->nested_sibling);
    corto_set_ref(&refs->from, this->nest0);
    corto_set_ref(&refs->root, root_o);
    corto_set_ref(&refs->null_ref, NULL);

    ut_iter it;
    corto_record *r;
    corto_select(".").from("data/parent/refs").format("text/json").iter(&it);

    test_assert(ut_iter_hasNext(&it));
    r = ut_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "refs");
    test_assertstr(r->parent, "..");
    test_assertstr(r->type, "/test/Refs");
    test_assert(r->value != 0);

    char *json =
        "{\"sibling\":\"/config\","
         "\"nested_sibling\":\"/config/helloworld\","
         "\"at_from\":\"/data/foo\","
         "\"inside_from\":\"/data/foo/bar\","
         "\"inside_from_nested1\":\"/data/foo/bar/hello\","
         "\"inside_from_nested2\":\"/data/foo/bar/hello/world\","
         "\"parent_from\":\"/\","
         "\"at_root\":\"/data\","
         "\"from\":\"/data\","
         "\"root\":\"/\","
         "\"null_ref\":null}";

    test_assertstr((char*)r->value, json);

    test_assert(ut_iter_hasNext(&it) == 0);
    test_assert(corto_delete(refs) == 0);
}


void test_SelectContentTypeRefs_tc_selectThisWithRefsFromRoot(
    test_SelectContentTypeRefs this)
{
    test_Refs *refs = corto_create(root_o, "refs", test_Refs_o);

    /* data/refs does not contain objects, so pretend like from = /data */
    corto_set_ref(&refs->at_from, this->nest1);
    corto_set_ref(&refs->inside_from, this->nest2);
    corto_set_ref(&refs->inside_from_nested1, this->nest3);
    corto_set_ref(&refs->inside_from_nested2, this->nest4);
    corto_set_ref(&refs->parent_from, root_o);
    corto_set_ref(&refs->at_root, this->nest0);
    corto_set_ref(&refs->sibling, this->sibling);
    corto_set_ref(&refs->nested_sibling, this->nested_sibling);
    corto_set_ref(&refs->from, this->nest0);
    corto_set_ref(&refs->root, root_o);
    corto_set_ref(&refs->null_ref, NULL);

    ut_iter it;
    corto_record *r;
    corto_select(".").from("refs").format("text/json").iter(&it);

    test_assert(ut_iter_hasNext(&it));
    r = ut_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "refs");
    test_assertstr(r->parent, "..");
    test_assertstr(r->type, "/test/Refs");
    test_assert(r->value != 0);

    char *json =
        "{\"sibling\":\"/config\","
         "\"nested_sibling\":\"/config/helloworld\","
         "\"at_from\":\"/data/foo\","
         "\"inside_from\":\"/data/foo/bar\","
         "\"inside_from_nested1\":\"/data/foo/bar/hello\","
         "\"inside_from_nested2\":\"/data/foo/bar/hello/world\","
         "\"parent_from\":\"/\","
         "\"at_root\":\"/data\","
         "\"from\":\"/data\","
         "\"root\":\"/\","
         "\"null_ref\":null}";

    test_assertstr((char*)r->value, json);

    test_assert(ut_iter_hasNext(&it) == 0);
    test_assert(corto_delete(refs) == 0);
}


void test_SelectContentTypeRefs_tc_selectTreeNestedWithRefsFromNested1(
    test_SelectContentTypeRefs this)
{
    test_Refs *refs = corto_create(root_o, "data/parent/grandparent/refs", test_Refs_o);
    corto_set_ref(&refs->at_from, this->nest1);
    corto_set_ref(&refs->inside_from, this->nest2);
    corto_set_ref(&refs->inside_from_nested1, this->nest3);
    corto_set_ref(&refs->inside_from_nested2, this->nest4);
    corto_set_ref(&refs->parent_from, root_o);
    corto_set_ref(&refs->at_root, this->nest0);
    corto_set_ref(&refs->sibling, this->sibling);
    corto_set_ref(&refs->nested_sibling, this->nested_sibling);
    corto_set_ref(&refs->from, this->nest0);
    corto_set_ref(&refs->root, root_o);
    corto_set_ref(&refs->null_ref, NULL);

    ut_iter it;
    corto_record *r;
    corto_select("//refs").from("data").format("text/json").iter(&it);

    test_assert(ut_iter_hasNext(&it));
    r = ut_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "refs");
    test_assertstr(r->parent, "parent/grandparent");
    test_assertstr(r->type, "/test/Refs");
    test_assert(r->value != 0);

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

    test_assertstr((char*)r->value, json);

    test_assert(ut_iter_hasNext(&it) == 0);
    test_assert(corto_delete(refs) == 0);
}


void test_SelectContentTypeRefs_tc_selectTreeNestedWithRefsFromNested2(
    test_SelectContentTypeRefs this)
{
    test_Refs *refs = corto_create(root_o, "data/foo/grandparent/parent/refs", test_Refs_o);
    corto_set_ref(&refs->at_from, this->nest2);
    corto_set_ref(&refs->inside_from, this->nest3);
    corto_set_ref(&refs->inside_from_nested1, this->nest4);
    corto_set_ref(&refs->inside_from_nested2, this->nest5);
    corto_set_ref(&refs->parent_from, this->nest0);
    corto_set_ref(&refs->at_root, this->nest0);
    corto_set_ref(&refs->sibling, this->sibling);
    corto_set_ref(&refs->nested_sibling, this->nested_sibling);
    corto_set_ref(&refs->from, this->nest1);
    corto_set_ref(&refs->root, root_o);
    corto_set_ref(&refs->null_ref, NULL);

    ut_iter it;
    corto_record *r;
    corto_select("//refs").from("data/foo").format("text/json").iter(&it);

    test_assert(ut_iter_hasNext(&it));
    r = ut_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "refs");
    test_assertstr(r->parent, "grandparent/parent");
    test_assertstr(r->type, "/test/Refs");
    test_assert(r->value != 0);

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

    test_assertstr((char*)r->value, json);

    test_assert(ut_iter_hasNext(&it) == 0);
    test_assert(corto_delete(refs) == 0);
}


void test_SelectContentTypeRefs_tc_selectTreeNestedWithRefsFromRoot(
    test_SelectContentTypeRefs this)
{
    test_Refs *refs = corto_create(root_o, "parent/grandparent/refs_obj", test_Refs_o);
    corto_set_ref(&refs->at_from, this->nest0);
    corto_set_ref(&refs->inside_from, this->nest1);
    corto_set_ref(&refs->inside_from_nested1, this->nest2);
    corto_set_ref(&refs->inside_from_nested2, this->nest3);
    corto_set_ref(&refs->parent_from, NULL);
    corto_set_ref(&refs->at_root, this->nest0);
    corto_set_ref(&refs->sibling, NULL);
    corto_set_ref(&refs->nested_sibling, NULL);
    corto_set_ref(&refs->from, root_o);
    corto_set_ref(&refs->root, root_o);
    corto_set_ref(&refs->null_ref, NULL);

    ut_iter it;
    corto_record *r;
    corto_select("//refs_obj").format("text/json").iter(&it);

    test_assert(ut_iter_hasNext(&it));
    r = ut_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "refs_obj");
    test_assertstr(r->parent, "/parent/grandparent");
    test_assertstr(r->type, "/test/Refs");
    test_assert(r->value != 0);

    char *json =
        "{\"sibling\":null,"
         "\"nested_sibling\":null,"
         "\"at_from\":\"/data\","
         "\"inside_from\":\"/data/foo\","
         "\"inside_from_nested1\":\"/data/foo/bar\","
         "\"inside_from_nested2\":\"/data/foo/bar/hello\","
         "\"parent_from\":null,"
         "\"at_root\":\"/data\","
         "\"from\":\"/\","
         "\"root\":\"/\","
         "\"null_ref\":null}";

    test_assertstr((char*)r->value, json);

    test_assert(ut_iter_hasNext(&it) == 0);
    test_assert(corto_delete(refs) == 0);
}


void test_SelectContentTypeRefs_tc_selectTreeWithRefsFromNested1(
    test_SelectContentTypeRefs this)
{
    test_Refs *refs = corto_create(root_o, "data/parent/refs", test_Refs_o);
    corto_set_ref(&refs->at_from, this->nest1);
    corto_set_ref(&refs->inside_from, this->nest2);
    corto_set_ref(&refs->inside_from_nested1, this->nest3);
    corto_set_ref(&refs->inside_from_nested2, this->nest4);
    corto_set_ref(&refs->parent_from, root_o);
    corto_set_ref(&refs->at_root, this->nest0);
    corto_set_ref(&refs->sibling, this->sibling);
    corto_set_ref(&refs->nested_sibling, this->nested_sibling);
    corto_set_ref(&refs->from, this->nest0);
    corto_set_ref(&refs->root, root_o);
    corto_set_ref(&refs->null_ref, NULL);

    ut_iter it;
    corto_record *r;
    corto_select("//refs").from("data").format("text/json").iter(&it);

    test_assert(ut_iter_hasNext(&it));
    r = ut_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "refs");
    test_assertstr(r->parent, "parent");
    test_assertstr(r->type, "/test/Refs");
    test_assert(r->value != 0);

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

    test_assertstr((char*)r->value, json);

    test_assert(ut_iter_hasNext(&it) == 0);
    test_assert(corto_delete(refs) == 0);
}


void test_SelectContentTypeRefs_tc_selectTreeWithRefsFromNested2(
    test_SelectContentTypeRefs this)
{
    test_Refs *refs = corto_create(root_o, "data/foo/parent/refs", test_Refs_o);
    corto_set_ref(&refs->at_from, this->nest2);
    corto_set_ref(&refs->inside_from, this->nest3);
    corto_set_ref(&refs->inside_from_nested1, this->nest4);
    corto_set_ref(&refs->inside_from_nested2, this->nest5);
    corto_set_ref(&refs->parent_from, this->nest0);
    corto_set_ref(&refs->at_root, this->nest0);
    corto_set_ref(&refs->sibling, this->sibling);
    corto_set_ref(&refs->nested_sibling, this->nested_sibling);
    corto_set_ref(&refs->from, this->nest1);
    corto_set_ref(&refs->root, root_o);
    corto_set_ref(&refs->null_ref, NULL);

    ut_iter it;
    corto_record *r;
    corto_select("//refs").from("data/foo").format("text/json").iter(&it);

    test_assert(ut_iter_hasNext(&it));
    r = ut_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "refs");
    test_assertstr(r->parent, "parent");
    test_assertstr(r->type, "/test/Refs");
    test_assert(r->value != 0);

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

    test_assertstr((char*)r->value, json);

    test_assert(ut_iter_hasNext(&it) == 0);
    test_assert(corto_delete(refs) == 0);
}


void test_SelectContentTypeRefs_tc_selectTreeWithRefsFromRoot(
    test_SelectContentTypeRefs this)
{
    test_Refs *refs = corto_create(root_o, "parent/refs_obj", test_Refs_o);
    corto_set_ref(&refs->at_from, this->nest0);
    corto_set_ref(&refs->inside_from, this->nest1);
    corto_set_ref(&refs->inside_from_nested1, this->nest2);
    corto_set_ref(&refs->inside_from_nested2, this->nest3);
    corto_set_ref(&refs->parent_from, NULL);
    corto_set_ref(&refs->at_root, this->nest0);
    corto_set_ref(&refs->sibling, NULL);
    corto_set_ref(&refs->nested_sibling, NULL);
    corto_set_ref(&refs->from, root_o);
    corto_set_ref(&refs->root, root_o);
    corto_set_ref(&refs->null_ref, NULL);

    ut_iter it;
    corto_record *r;
    corto_select("//refs_obj").format("text/json").iter(&it);

    test_assert(ut_iter_hasNext(&it));
    r = ut_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "refs_obj");
    test_assertstr(r->parent, "/parent");
    test_assertstr(r->type, "/test/Refs");
    test_assert(r->value != 0);

    char *json =
        "{\"sibling\":null,"
         "\"nested_sibling\":null,"
         "\"at_from\":\"/data\","
         "\"inside_from\":\"/data/foo\","
         "\"inside_from_nested1\":\"/data/foo/bar\","
         "\"inside_from_nested2\":\"/data/foo/bar/hello\","
         "\"parent_from\":null,"
         "\"at_root\":\"/data\","
         "\"from\":\"/\","
         "\"root\":\"/\","
         "\"null_ref\":null}";

    test_assertstr((char*)r->value, json);

    test_assert(ut_iter_hasNext(&it) == 0);
    test_assert(corto_delete(refs) == 0);
}
