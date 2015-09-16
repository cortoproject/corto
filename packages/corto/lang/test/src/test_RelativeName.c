/* test_RelativeName.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#define test_LIB
#include "test.h"

/* ::test::RelativeName::setup() */
cx_void _test_RelativeName_setup(test_RelativeName this) {
/* $begin(::test::RelativeName::setup) */

    cx_setref(&this->tier1, cx_voidCreateChild(NULL, "tier1"));
    cx_setref(&this->tier2, cx_voidCreateChild(this->tier1, "tier2"));
    cx_setref(&this->tier3, cx_voidCreateChild(this->tier2, "tier3"));
    cx_setref(&this->obj, cx_voidCreateChild(this->tier3, "obj"));
    cx_setref(&this->disjunct, cx_voidCreateChild(this->tier1, "disjunct"));
    cx_setref(&this->child, cx_voidCreateChild(this->obj, "child"));

    test_assert(this->tier1 != NULL);
    test_assert(this->tier2 != NULL);
    test_assert(this->tier3 != NULL);
    test_assert(this->obj != NULL);
    test_assert(this->disjunct != NULL);
    test_assert(this->child != NULL);

/* $end */
}

/* ::test::RelativeName::tc_fromChild() */
cx_void _test_RelativeName_tc_fromChild(test_RelativeName this) {
/* $begin(::test::RelativeName::tc_fromChild) */
    cx_id id;
    cx_string result;

    result = cx_relname(this->child, this->obj, id);
    test_assert(result == NULL);
    cx_string err = cx_lasterr();
    test_assert(!strcmp(err, "origin is not in path of object"));

/* $end */
}

/* ::test::RelativeName::tc_fromDisjunct() */
cx_void _test_RelativeName_tc_fromDisjunct(test_RelativeName this) {
/* $begin(::test::RelativeName::tc_fromDisjunct) */
    cx_id id;
    cx_string result;

    result = cx_relname(this->disjunct, this->obj, id);
    test_assert(result != NULL);
    test_assert(!strcmp(result, "tier2::tier3::obj"));

/* $end */
}

/* ::test::RelativeName::tc_fromOneUp() */
cx_void _test_RelativeName_tc_fromOneUp(test_RelativeName this) {
/* $begin(::test::RelativeName::tc_fromOneUp) */

    cx_id id;
    cx_string result;

    result = cx_relname(this->tier2, this->obj, id);
    test_assert(result != NULL);
    test_assert(!strcmp(result, "tier3::obj"));

/* $end */
}

/* ::test::RelativeName::tc_fromParent() */
cx_void _test_RelativeName_tc_fromParent(test_RelativeName this) {
/* $begin(::test::RelativeName::tc_fromParent) */

    cx_id id;
    cx_string result;

    result = cx_relname(this->tier3, this->obj, id);
    test_assert(result != NULL);
    test_assert(!strcmp(result, "obj"));

/* $end */
}

/* ::test::RelativeName::tc_fromRoot() */
cx_void _test_RelativeName_tc_fromRoot(test_RelativeName this) {
/* $begin(::test::RelativeName::tc_fromRoot) */
    cx_id id;
    cx_string result;

    result = cx_relname(root_o, this->obj, id);
    test_assert(result != NULL);
    test_assert(!strcmp(result, "tier1::tier2::tier3::obj"));

/* $end */
}

/* ::test::RelativeName::tc_fromSelf() */
cx_void _test_RelativeName_tc_fromSelf(test_RelativeName this) {
/* $begin(::test::RelativeName::tc_fromSelf) */
    cx_id id;
    cx_string result;

    result = cx_relname(this->obj, this->obj, id);
    test_assert(result != NULL);
    test_assert(!strcmp(result, "."));

/* $end */
}

/* ::test::RelativeName::tc_fromThreeUp() */
cx_void _test_RelativeName_tc_fromThreeUp(test_RelativeName this) {
/* $begin(::test::RelativeName::tc_fromThreeUp) */
    cx_id id;
    cx_string result;

    result = cx_relname(this->tier1, this->child, id);
    test_assert(result != NULL);
    test_assert(!strcmp(result, "tier2::tier3::obj::child"));

/* $end */
}

/* ::test::RelativeName::tc_fromTwoUp() */
cx_void _test_RelativeName_tc_fromTwoUp(test_RelativeName this) {
/* $begin(::test::RelativeName::tc_fromTwoUp) */
    cx_id id;
    cx_string result;

    result = cx_relname(this->tier1, this->obj, id);
    test_assert(result != NULL);
    test_assert(!strcmp(result, "tier2::tier3::obj"));

/* $end */
}

/* ::test::RelativeName::teardown() */
cx_void _test_RelativeName_teardown(test_RelativeName this) {
/* $begin(::test::RelativeName::teardown) */

    cx_delete(this->tier1);
    cx_delete(this->tier2);
    cx_delete(this->tier3);
    cx_delete(this->obj);
    cx_delete(this->disjunct);
    cx_delete(this->child);

    cx_setref(&this->tier1, NULL);
    cx_setref(&this->tier2, NULL);
    cx_setref(&this->tier3, NULL);
    cx_setref(&this->obj, NULL);
    cx_setref(&this->disjunct, NULL);
    cx_setref(&this->child, NULL);

/* $end */
}
