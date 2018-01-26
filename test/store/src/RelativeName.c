/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

void test_RelativeName_setup(
    test_RelativeName this)
{

    corto_set_ref(&this->tier1, corto_void__create(root_o, "tier1"));
    corto_set_ref(&this->tier2, corto_void__create(this->tier1, "tier2"));
    corto_set_ref(&this->tier3, corto_void__create(this->tier2, "tier3"));
    corto_set_ref(&this->obj, corto_void__create(this->tier3, "obj"));
    corto_set_ref(&this->disjunct, corto_void__create(this->tier1, "disjunct"));
    corto_set_ref(&this->child, corto_void__create(this->obj, "child"));

    test_assert(this->tier1 != NULL);
    test_assert(this->tier2 != NULL);
    test_assert(this->tier3 != NULL);
    test_assert(this->obj != NULL);
    test_assert(this->disjunct != NULL);
    test_assert(this->child != NULL);

}

void test_RelativeName_tc_fromChild(
    test_RelativeName this)
{
    corto_id id;
    corto_string result;

    result = corto_path(id, this->child, this->obj, "/");
    test_assert(result != NULL);
    test_assert(result == id);
    test_assert(!strcmp(result, ".."));

}

void test_RelativeName_tc_fromDisjunct(
    test_RelativeName this)
{
    corto_id id;
    corto_string result;

    result = corto_path(id, this->disjunct, this->obj, "/");
    test_assert(result != NULL);
    test_assert(result == id);
    test_assert(!strcmp(result, "tier2/tier3/obj"));

}

void test_RelativeName_tc_fromGrandchild(
    test_RelativeName this)
{
    corto_id id;
    corto_string result;

    result = corto_path(id, this->child, this->tier3, "/");
    test_assert(result != NULL);
    test_assert(result == id);
    test_assert(!strcmp(result, "../.."));

}

void test_RelativeName_tc_fromNull(
    test_RelativeName this)
{
    corto_id id;
    corto_string result;

    result = corto_path(id, NULL, this->tier1, "/");
    test_assert(result != NULL);
    test_assert(result == id);
    test_assert(!strcmp(result, "/tier1"));

}

void test_RelativeName_tc_fromOneUp(
    test_RelativeName this)
{
    corto_id id;
    corto_string result;

    result = corto_path(id, this->tier2, this->obj, "/");
    test_assert(result != NULL);
    test_assert(result == id);
    test_assert(!strcmp(result, "tier3/obj"));

}

void test_RelativeName_tc_fromParent(
    test_RelativeName this)
{
    corto_id id;
    corto_string result;

    result = corto_path(id, this->tier3, this->obj, "/");
    test_assert(result != NULL);
    test_assert(result == id);
    test_assert(!strcmp(result, "obj"));

}

void test_RelativeName_tc_fromRoot(
    test_RelativeName this)
{
    corto_id id;
    corto_string result;

    result = corto_path(id, root_o, this->obj, "/");
    test_assert(result != NULL);
    test_assert(result == id);
    test_assert(!strcmp(result, "tier1/tier2/tier3/obj"));

}

void test_RelativeName_tc_fromSelf(
    test_RelativeName this)
{
    corto_id id;
    corto_string result;

    result = corto_path(id, this->obj, this->obj, "/");
    test_assert(result != NULL);
    test_assert(result == id);
    test_assert(!strcmp(result, "."));

}

void test_RelativeName_tc_fromThreeUp(
    test_RelativeName this)
{
    corto_id id;
    corto_string result;

    result = corto_path(id, this->tier1, this->child, "/");
    test_assert(result != NULL);
    test_assert(result == id);
    test_assert(!strcmp(result, "tier2/tier3/obj/child"));

}

void test_RelativeName_tc_fromTwoUp(
    test_RelativeName this)
{
    corto_id id;
    corto_string result;

    result = corto_path(id, this->tier1, this->obj, "/");
    test_assert(result != NULL);
    test_assert(result == id);
    test_assert(!strcmp(result, "tier2/tier3/obj"));

}

void test_RelativeName_tc_rootFromNull(
    test_RelativeName this)
{
    corto_id id;
    corto_string result;

    result = corto_path(id, NULL, root_o, "/");
    test_assert(result != NULL);
    test_assert(result == id);
    test_assert(!strcmp(result, "/"));
}

void test_RelativeName_tc_rootFromNullColon(
    test_RelativeName this)
{
    corto_id id;
    corto_string result;

    result = corto_path(id, NULL, root_o, "::");
    test_assert(result != NULL);
    test_assert(result == id);
    test_assert(!strcmp(result, "::"));
}

void test_RelativeName_tc_rootFromObj(
    test_RelativeName this)
{
    corto_id id;
    corto_string result;

    result = corto_path(id, this->tier1, root_o, "/");
    test_assert(result != NULL);
    test_assert(result == id);
    test_assert(!strcmp(result, ".."));

}

void test_RelativeName_teardown(
    test_RelativeName this)
{

    corto_delete(this->tier1);
    corto_set_ref(&this->tier1, NULL);
    corto_set_ref(&this->tier2, NULL);
    corto_set_ref(&this->tier3, NULL);
    corto_set_ref(&this->obj, NULL);
    corto_set_ref(&this->disjunct, NULL);
    corto_set_ref(&this->child, NULL);

}

