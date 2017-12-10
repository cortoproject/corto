/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

void test_Fullname_tc_anonymousAnonymous(
    test_Fullname this)
{
    corto_object o = corto_resolve(NULL, "list{int32}{10, 20, 30}");
    test_assert(o != NULL);
    test_assert(corto_typeof(o)->kind == CORTO_COLLECTION);
    corto_ll *l = o;
    test_assertint(corto_ll_count(*l), 3);

    test_assertstr(corto_fullpath(NULL, o), "list{int32,0}{10,20,30}");
    corto_int16 ret = corto_delete(o);
    test_assert(ret == 0);

}

void test_Fullname_tc_anonymousCollection(
    test_Fullname this)
{
    corto_object o = corto_resolve(NULL, "test/IntList{10, 20, 30}");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(test_IntList_o));
    test_IntList *l = test_IntList(o);
    test_assertint(corto_ll_count(*l), 3);

    test_assertstr(corto_fullpath(NULL, o), "/test/IntList{10,20,30}");
    corto_int16 ret = corto_delete(o);
    test_assert(ret == 0);

}

void test_Fullname_tc_anonymousComposite(
    test_Fullname this)
{
    corto_object o = corto_resolve(NULL, "test/Point{10, 20}");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(test_Point_o));
    test_Point *p = test_Point(o);
    test_assertint(p->x, 10);
    test_assertint(p->y, 20);

    test_assertstr(corto_fullpath(NULL, o), "/test/Point{10,20}");
    corto_int16 ret = corto_delete(o);
    test_assert(ret == 0);

}

void test_Fullname_tc_anonymousPrimitive(
    test_Fullname this)
{
    corto_object o = corto_resolve(NULL, "int32{10}");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_int32_o));
    corto_int32 *p = o;
    test_assertint(*p, 10);

    test_assertstr(corto_fullpath(NULL, o), "int32{10}");
    corto_int16 ret = corto_delete(o);
    test_assert(ret == 0);

}

void test_Fullname_tc_fromLang(
    test_Fullname this)
{
    corto_id id;

    corto_string result = corto_fullpath(id, corto_int32_o);
    test_assert(result == id);
    test_assert(!strcmp(result, "int32"));

}

void test_Fullname_tc_null(
    test_Fullname this)
{
    corto_id id;

    id[0] = 'a';
    corto_string result = corto_fullpath(id, NULL);
    test_assert(result == id);
    test_assert(!strcmp(result, ""));
}

void test_Fullname_tc_nullBuffer(
    test_Fullname this)
{

    corto_string result = corto_fullpath(NULL, NULL);
    test_assert(result != NULL);
    test_assert(!strcmp(result, ""));
}

void test_Fullname_tc_onelevel(
    test_Fullname this)
{
    corto_id id;

    corto_string result = corto_fullpath(id, corto_o);
    test_assert(result == id);
    test_assert(!strcmp(result, "/corto"));

}

void test_Fullname_tc_root(
    test_Fullname this)
{
    corto_id id;

    corto_string result = corto_fullpath(id, root_o);
    test_assert(result == id);
    test_assert(!strcmp(result, "/"));

}

void test_Fullname_tc_twolevels(
    test_Fullname this)
{
    corto_id id;

    corto_string result = corto_fullpath(id, corto_lang_o);
    test_assert(result == id);
    test_assert(!strcmp(result, "/corto/lang"));

}
