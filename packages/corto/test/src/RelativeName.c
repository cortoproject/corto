/* $CORTO_GENERATED
 *
 * RelativeName.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include "test.h"

corto_void _test_RelativeName_setup(
    test_RelativeName this)
{
/* $begin(test/RelativeName/setup) */

    corto_setref(&this->tier1, corto_voidCreateChild(NULL, "tier1"));
    corto_setref(&this->tier2, corto_voidCreateChild(this->tier1, "tier2"));
    corto_setref(&this->tier3, corto_voidCreateChild(this->tier2, "tier3"));
    corto_setref(&this->obj, corto_voidCreateChild(this->tier3, "obj"));
    corto_setref(&this->disjunct, corto_voidCreateChild(this->tier1, "disjunct"));
    corto_setref(&this->child, corto_voidCreateChild(this->obj, "child"));

    test_assert(this->tier1 != NULL);
    test_assert(this->tier2 != NULL);
    test_assert(this->tier3 != NULL);
    test_assert(this->obj != NULL);
    test_assert(this->disjunct != NULL);
    test_assert(this->child != NULL);

/* $end */
}

corto_void _test_RelativeName_tc_fromChild(
    test_RelativeName this)
{
/* $begin(test/RelativeName/tc_fromChild) */
    corto_id id;
    corto_string result;

    result = corto_path(id, this->child, this->obj, "/");
    test_assert(result != NULL);
    test_assert(result == id);
    test_assert(!strcmp(result, ".."));

/* $end */
}

corto_void _test_RelativeName_tc_fromDisjunct(
    test_RelativeName this)
{
/* $begin(test/RelativeName/tc_fromDisjunct) */
    corto_id id;
    corto_string result;

    result = corto_path(id, this->disjunct, this->obj, "/");
    test_assert(result != NULL);
    test_assert(result == id);
    test_assert(!strcmp(result, "tier2/tier3/obj"));

/* $end */
}

corto_void _test_RelativeName_tc_fromGrandchild(
    test_RelativeName this)
{
/* $begin(test/RelativeName/tc_fromGrandchild) */
    corto_id id;
    corto_string result;

    result = corto_path(id, this->child, this->tier3, "/");
    test_assert(result != NULL);
    test_assert(result == id);
    test_assert(!strcmp(result, "../.."));

/* $end */
}

corto_void _test_RelativeName_tc_fromNull(
    test_RelativeName this)
{
/* $begin(test/RelativeName/tc_fromNull) */
    corto_id id;
    corto_string result;

    result = corto_path(id, NULL, this->tier1, "/");
    test_assert(result != NULL);
    test_assert(result == id);
    test_assert(!strcmp(result, "/tier1"));

/* $end */
}

corto_void _test_RelativeName_tc_fromOneUp(
    test_RelativeName this)
{
/* $begin(test/RelativeName/tc_fromOneUp) */
    corto_id id;
    corto_string result;

    result = corto_path(id, this->tier2, this->obj, "/");
    test_assert(result != NULL);
    test_assert(result == id);
    test_assert(!strcmp(result, "tier3/obj"));

/* $end */
}

corto_void _test_RelativeName_tc_fromParent(
    test_RelativeName this)
{
/* $begin(test/RelativeName/tc_fromParent) */
    corto_id id;
    corto_string result;

    result = corto_path(id, this->tier3, this->obj, "/");
    test_assert(result != NULL);
    test_assert(result == id);
    test_assert(!strcmp(result, "obj"));

/* $end */
}

corto_void _test_RelativeName_tc_fromRoot(
    test_RelativeName this)
{
/* $begin(test/RelativeName/tc_fromRoot) */
    corto_id id;
    corto_string result;

    result = corto_path(id, root_o, this->obj, "/");
    test_assert(result != NULL);
    test_assert(result == id);
    test_assert(!strcmp(result, "tier1/tier2/tier3/obj"));

/* $end */
}

corto_void _test_RelativeName_tc_fromSelf(
    test_RelativeName this)
{
/* $begin(test/RelativeName/tc_fromSelf) */
    corto_id id;
    corto_string result;

    result = corto_path(id, this->obj, this->obj, "/");
    test_assert(result != NULL);
    test_assert(result == id);
    test_assert(!strcmp(result, "."));

/* $end */
}

corto_void _test_RelativeName_tc_fromThreeUp(
    test_RelativeName this)
{
/* $begin(test/RelativeName/tc_fromThreeUp) */
    corto_id id;
    corto_string result;

    result = corto_path(id, this->tier1, this->child, "/");
    test_assert(result != NULL);
    test_assert(result == id);
    test_assert(!strcmp(result, "tier2/tier3/obj/child"));

/* $end */
}

corto_void _test_RelativeName_tc_fromTwoUp(
    test_RelativeName this)
{
/* $begin(test/RelativeName/tc_fromTwoUp) */
    corto_id id;
    corto_string result;

    result = corto_path(id, this->tier1, this->obj, "/");
    test_assert(result != NULL);
    test_assert(result == id);
    test_assert(!strcmp(result, "tier2/tier3/obj"));

/* $end */
}

corto_void _test_RelativeName_tc_rootFromObj(
    test_RelativeName this)
{
/* $begin(test/RelativeName/tc_rootFromObj) */
    corto_id id;
    corto_string result;

    result = corto_path(id, this->tier1, root_o, "/");
    test_assert(result != NULL);
    test_assert(result == id);
    test_assert(!strcmp(result, ".."));

/* $end */
}

corto_void _test_RelativeName_teardown(
    test_RelativeName this)
{
/* $begin(test/RelativeName/teardown) */

    corto_delete(this->tier1);
    corto_setref(&this->tier1, NULL);
    corto_setref(&this->tier2, NULL);
    corto_setref(&this->tier3, NULL);
    corto_setref(&this->obj, NULL);
    corto_setref(&this->disjunct, NULL);
    corto_setref(&this->child, NULL);

/* $end */
}
