/* test_Select.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "test.h"

/* ::test::Select::collect(object scope,string expr) */
test_selectItemList _test_Select_collect(cx_object scope, cx_string expr) {
/* $begin(::test::Select::collect) */
	cx_iter iter;
	cx_ll result = cx_llNew();

    cx_select(scope, expr, &iter);
    while (cx_iterHasNext(&iter)) {
    	cx_selectItem *item = cx_iterNext(&iter);
    	test_selectItem *listItem = cx_alloc(sizeof(test_selectItem));
    	listItem->parent = cx_strdup(item->parent);
    	listItem->name = cx_strdup(item->name);
    	listItem->type = cx_strdup(item->type);
    	cx_llAppend(result, listItem);
    }

    return result;
/* $end */
}

/* ::test::Select::setup() */
cx_void _test_Select_setup(test_Select this) {
/* $begin(::test::Select::setup) */

    cx_object a = cx_voidCreateChild(NULL, "a");
    cx_voidCreateChild(a, "b");
    cx_object c = cx_voidCreateChild(a, "c");
    cx_voidCreateChild(c, "b");

/* $end */
}

/* ::test::Select::tc_selectErrParentAst() */
cx_void _test_Select_tc_selectErrParentAst(test_Select this) {
/* $begin(::test::Select::tc_selectErrParentAst) */
    cx_iter iter;
    
    cx_int16 ret = cx_select(NULL, "..*", &iter);
    test_assert(ret != 0);
    test_assert(cx_lasterr() != NULL);
    test_assert(!strcmp(cx_lasterr(), "select '..*' failed: unexpected '*' after '..'"));

/* $end */
}

/* ::test::Select::tc_selectErrParentId() */
cx_void _test_Select_tc_selectErrParentId(test_Select this) {
/* $begin(::test::Select::tc_selectErrParentId) */
    cx_iter iter;
    
    cx_int16 ret = cx_select(NULL, "..id", &iter);
    test_assert(ret != 0);
    test_assert(cx_lasterr() != NULL);
    test_assert(!strcmp(cx_lasterr(), "select '..id' failed: unexpected 'identifier' after '..'"));

/* $end */
}

/* ::test::Select::tc_selectErrParentTree() */
cx_void _test_Select_tc_selectErrParentTree(test_Select this) {
/* $begin(::test::Select::tc_selectErrParentTree) */
    cx_iter iter;

    cx_int16 ret = cx_select(NULL, "...", &iter);
    test_assert(ret != 0);
    test_assert(cx_lasterr() != NULL);
    test_assert(!strcmp(cx_lasterr(), "select '...' failed: unexpected '.' after '..'"));

/* $end */
}

/* ::test::Select::tc_selectErrParentWc() */
cx_void _test_Select_tc_selectErrParentWc(test_Select this) {
/* $begin(::test::Select::tc_selectErrParentWc) */
    cx_iter iter;
    
    cx_int16 ret = cx_select(NULL, "..?", &iter);
    test_assert(ret != 0);
    test_assert(cx_lasterr() != NULL);
    test_assert(!strcmp(cx_lasterr(), "select '..?' failed: unexpected '?' after '..'"));

/* $end */
}

/* ::test::Select::tc_selectErrScopeScope() */
cx_void _test_Select_tc_selectErrScopeScope(test_Select this) {
/* $begin(::test::Select::tc_selectErrScopeScope) */
    cx_iter iter;
    
    cx_int16 ret = cx_select(NULL, "::::", &iter);
    test_assert(ret != 0);
    test_assert(cx_lasterr() != NULL);
    test_assert(!strcmp(cx_lasterr(), "select '::::' failed: unexpected '::' after '::'"));

/* $end */
}

/* ::test::Select::tc_selectIdentifier() */
cx_void _test_Select_tc_selectIdentifier(test_Select this) {
/* $begin(::test::Select::tc_selectIdentifier) */

    /* << Insert implementation >> */

/* $end */
}

/* ::test::Select::tc_selectParent() */
cx_void _test_Select_tc_selectParent(test_Select this) {
/* $begin(::test::Select::tc_selectParent) */

    /* << Insert implementation >> */

/* $end */
}

/* ::test::Select::tc_selectScopedIdentifier() */
cx_void _test_Select_tc_selectScopedIdentifier(test_Select this) {
/* $begin(::test::Select::tc_selectScopedIdentifier) */

    /* << Insert implementation >> */

/* $end */
}

/* ::test::Select::tc_selectScopedParent() */
cx_void _test_Select_tc_selectScopedParent(test_Select this) {
/* $begin(::test::Select::tc_selectScopedParent) */

    /* << Insert implementation >> */

/* $end */
}

/* ::test::Select::tc_selectScopedThis() */
cx_void _test_Select_tc_selectScopedThis(test_Select this) {
/* $begin(::test::Select::tc_selectScopedThis) */

    /* << Insert implementation >> */

/* $end */
}

/* ::test::Select::tc_selectThis() */
cx_void _test_Select_tc_selectThis(test_Select this) {
/* $begin(::test::Select::tc_selectThis) */
	cx_ll results = NULL;
	test_selectItem *item;

	cx_object a = cx_resolve(NULL, "a");
	test_assert(a != NULL);

    results = test_Select_collect(a, ".");
    test_assert(results != NULL);
    test_assert(cx_llSize(results) == 1);

    item = cx_llGet(results, 0);
    test_assert(item != NULL);
    test_assert(!strcmp(item->parent, "."));
    test_assert(!strcmp(item->name, "a"));
    test_assert(!strcmp(item->type, "::corto::lang::void"));

    cx_release(a);

/* $end */
}

/* ::test::Select::teardown() */
cx_void _test_Select_teardown(test_Select this) {
/* $begin(::test::Select::teardown) */

    /* << Insert implementation >> */

/* $end */
}
