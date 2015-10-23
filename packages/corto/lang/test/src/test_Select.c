/* test_Select.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "test.h"

/* ::test::Select::collect(object scope,string expr) */
test_selectItemList _test_Select_collect(corto_object scope, corto_string expr) {
/* $begin(::test::Select::collect) */
	corto_iter iter;
	corto_ll result = corto_llNew();

    corto_select(scope, expr, &iter);
    while (corto_iterHasNext(&iter)) {
    	corto_selectItem *item = corto_iterNext(&iter);
    	test_selectItem *listItem = corto_alloc(sizeof(test_selectItem));
    	listItem->parent = corto_strdup(item->parent);
    	listItem->name = corto_strdup(item->name);
    	listItem->type = corto_strdup(item->type);
    	corto_llAppend(result, listItem);
    }

    return result;
/* $end */
}

/* ::test::Select::setup() */
corto_void _test_Select_setup(test_Select this) {
/* $begin(::test::Select::setup) */

    corto_object a = corto_voidCreateChild(NULL, "a");
    corto_voidCreateChild(a, "b");
    corto_object c = corto_voidCreateChild(a, "c");
    corto_voidCreateChild(c, "b");

/* $end */
}

/* ::test::Select::tc_selectErrParentAst() */
corto_void _test_Select_tc_selectErrParentAst(test_Select this) {
/* $begin(::test::Select::tc_selectErrParentAst) */
    corto_iter iter;
    
    corto_int16 ret = corto_select(NULL, "..*", &iter);
    test_assert(ret != 0);
    test_assert(corto_lasterr() != NULL);
    test_assert(!strcmp(corto_lasterr(), "select '..*' failed: unexpected '*' after '..'"));

/* $end */
}

/* ::test::Select::tc_selectErrParentId() */
corto_void _test_Select_tc_selectErrParentId(test_Select this) {
/* $begin(::test::Select::tc_selectErrParentId) */
    corto_iter iter;
    
    corto_int16 ret = corto_select(NULL, "..id", &iter);
    test_assert(ret != 0);
    test_assert(corto_lasterr() != NULL);
    test_assert(!strcmp(corto_lasterr(), "select '..id' failed: unexpected 'identifier' after '..'"));

/* $end */
}

/* ::test::Select::tc_selectErrParentTree() */
corto_void _test_Select_tc_selectErrParentTree(test_Select this) {
/* $begin(::test::Select::tc_selectErrParentTree) */
    corto_iter iter;

    corto_int16 ret = corto_select(NULL, "...", &iter);
    test_assert(ret != 0);
    test_assert(corto_lasterr() != NULL);
    test_assert(!strcmp(corto_lasterr(), "select '...' failed: unexpected '.' after '..'"));

/* $end */
}

/* ::test::Select::tc_selectErrParentWc() */
corto_void _test_Select_tc_selectErrParentWc(test_Select this) {
/* $begin(::test::Select::tc_selectErrParentWc) */
    corto_iter iter;
    
    corto_int16 ret = corto_select(NULL, "..?", &iter);
    test_assert(ret != 0);
    test_assert(corto_lasterr() != NULL);
    test_assert(!strcmp(corto_lasterr(), "select '..?' failed: unexpected '?' after '..'"));

/* $end */
}

/* ::test::Select::tc_selectErrScopeScope() */
corto_void _test_Select_tc_selectErrScopeScope(test_Select this) {
/* $begin(::test::Select::tc_selectErrScopeScope) */
    corto_iter iter;
    
    corto_int16 ret = corto_select(NULL, "::::", &iter);
    test_assert(ret != 0);
    test_assert(corto_lasterr() != NULL);
    test_assert(!strcmp(corto_lasterr(), "select '::::' failed: unexpected '::' after '::'"));

/* $end */
}

/* ::test::Select::tc_selectIdentifier() */
corto_void _test_Select_tc_selectIdentifier(test_Select this) {
/* $begin(::test::Select::tc_selectIdentifier) */

    /* << Insert implementation >> */

/* $end */
}

/* ::test::Select::tc_selectParent() */
corto_void _test_Select_tc_selectParent(test_Select this) {
/* $begin(::test::Select::tc_selectParent) */

    /* << Insert implementation >> */

/* $end */
}

/* ::test::Select::tc_selectScopedIdentifier() */
corto_void _test_Select_tc_selectScopedIdentifier(test_Select this) {
/* $begin(::test::Select::tc_selectScopedIdentifier) */

    /* << Insert implementation >> */

/* $end */
}

/* ::test::Select::tc_selectScopedParent() */
corto_void _test_Select_tc_selectScopedParent(test_Select this) {
/* $begin(::test::Select::tc_selectScopedParent) */

    /* << Insert implementation >> */

/* $end */
}

/* ::test::Select::tc_selectScopedThis() */
corto_void _test_Select_tc_selectScopedThis(test_Select this) {
/* $begin(::test::Select::tc_selectScopedThis) */

    /* << Insert implementation >> */

/* $end */
}

/* ::test::Select::tc_selectThis() */
corto_void _test_Select_tc_selectThis(test_Select this) {
/* $begin(::test::Select::tc_selectThis) */
	corto_ll results = NULL;
	test_selectItem *item;

	corto_object a = corto_resolve(NULL, "a");
	test_assert(a != NULL);

    results = test_Select_collect(a, ".");
    test_assert(results != NULL);
    test_assert(corto_llSize(results) == 1);

    item = corto_llGet(results, 0);
    test_assert(item != NULL);
    test_assert(!strcmp(item->parent, "."));
    test_assert(!strcmp(item->name, "a"));
    test_assert(!strcmp(item->type, "::corto::lang::void"));

    corto_release(a);

/* $end */
}

/* ::test::Select::teardown() */
corto_void _test_Select_teardown(test_Select this) {
/* $begin(::test::Select::teardown) */

    /* << Insert implementation >> */

/* $end */
}
