/* $CORTO_GENERATED
 *
 * test_RelativeName.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include "test.h"

corto_void _test_RelativeName_setup(test_RelativeName this) {
/* $begin(::test::RelativeName::setup) */

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

corto_void _test_RelativeName_tc_fromChild(test_RelativeName this) {
/* $begin(::test::RelativeName::tc_fromChild) */
    corto_id id;
    corto_string result;

    result = corto_relname(this->child, this->obj, id);
    test_assert(result == NULL);
    corto_string err = corto_lasterr();
    test_assert(!strcmp(err, "origin is not in path of object"));

/* $end */
}

corto_void _test_RelativeName_tc_fromDisjunct(test_RelativeName this) {
/* $begin(::test::RelativeName::tc_fromDisjunct) */
    corto_id id;
    corto_string result;

    result = corto_relname(this->disjunct, this->obj, id);
    test_assert(result != NULL);
    test_assert(!strcmp(result, "tier2::tier3::obj"));

/* $end */
}

corto_void _test_RelativeName_tc_fromOneUp(test_RelativeName this) {
/* $begin(::test::RelativeName::tc_fromOneUp) */

    corto_id id;
    corto_string result;

    result = corto_relname(this->tier2, this->obj, id);
    test_assert(result != NULL);
    test_assert(!strcmp(result, "tier3::obj"));

/* $end */
}

corto_void _test_RelativeName_tc_fromParent(test_RelativeName this) {
/* $begin(::test::RelativeName::tc_fromParent) */

    corto_id id;
    corto_string result;

    result = corto_relname(this->tier3, this->obj, id);
    test_assert(result != NULL);
    test_assert(!strcmp(result, "obj"));

/* $end */
}

corto_void _test_RelativeName_tc_fromRoot(test_RelativeName this) {
/* $begin(::test::RelativeName::tc_fromRoot) */
    corto_id id;
    corto_string result;

    result = corto_relname(root_o, this->obj, id);
    test_assert(result != NULL);
    test_assert(!strcmp(result, "tier1::tier2::tier3::obj"));

/* $end */
}

corto_void _test_RelativeName_tc_fromSelf(test_RelativeName this) {
/* $begin(::test::RelativeName::tc_fromSelf) */
    corto_id id;
    corto_string result;

    result = corto_relname(this->obj, this->obj, id);
    test_assert(result != NULL);
    test_assert(!strcmp(result, "."));

/* $end */
}

corto_void _test_RelativeName_tc_fromThreeUp(test_RelativeName this) {
/* $begin(::test::RelativeName::tc_fromThreeUp) */
    corto_id id;
    corto_string result;

    result = corto_relname(this->tier1, this->child, id);
    test_assert(result != NULL);
    test_assert(!strcmp(result, "tier2::tier3::obj::child"));

/* $end */
}

corto_void _test_RelativeName_tc_fromTwoUp(test_RelativeName this) {
/* $begin(::test::RelativeName::tc_fromTwoUp) */
    corto_id id;
    corto_string result;

    result = corto_relname(this->tier1, this->obj, id);
    test_assert(result != NULL);
    test_assert(!strcmp(result, "tier2::tier3::obj"));

/* $end */
}

corto_void _test_RelativeName_teardown(test_RelativeName this) {
/* $begin(::test::RelativeName::teardown) */

    corto_delete(this->tier1);
    corto_delete(this->tier2);
    corto_delete(this->tier3);
    corto_delete(this->obj);
    corto_delete(this->disjunct);
    corto_delete(this->child);

    corto_setref(&this->tier1, NULL);
    corto_setref(&this->tier2, NULL);
    corto_setref(&this->tier3, NULL);
    corto_setref(&this->obj, NULL);
    corto_setref(&this->disjunct, NULL);
    corto_setref(&this->child, NULL);

/* $end */
}
