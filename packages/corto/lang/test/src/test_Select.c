/* $CORTO_GENERATED
 *
 * test_Select.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include "test.h"

test_selectItemList _test_Select_collect(corto_object scope, corto_string expr) {
/* $begin(test/Select/collect) */
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

corto_bool _test_Select_hasObject(test_selectItemList items, corto_string parent, corto_string name, corto_string type) {
/* $begin(test/Select/hasObject) */

    corto_iter iter = corto_llIter(items);
    while (corto_iterHasNext(&iter)) {
        test_selectItem *item = corto_iterNext(&iter);
        if (!strcmp(item->parent, parent)) {
            if (!strcmp(item->name, name)) {
                if (!strcmp(item->type, type)) {
                    return TRUE;
                }
            }
        }
    }

    return FALSE;
/* $end */
}

corto_void _test_Select_setup(test_Select this) {
/* $begin(test/Select/setup) */
    /*     a
          / \
        b    c
              \
               b
    */

    corto_object a = corto_voidCreateChild(NULL, "a");
    corto_voidCreateChild(a, "b");
    corto_object c = corto_voidCreateChild(a, "c");

    /* Create in separate scope, to avoid contamination of root & keep test case
     * clean. */
    corto_voidCreateChild(a, "abc"); /* For matching filters */
    corto_voidCreateChild(a, "abd"); /* For wildcard testing */
    corto_voidCreateChild(a, "abdc"); /* For asterisk testing */
    corto_voidCreateChild(a, "Abab"); /* For caps testing */
    corto_voidCreateChild(a, "ab_ab"); /* Testing underscores */
    corto_voidCreateChild(a, "ab01234567890"); /* Testing numbers */
    corto_voidCreateChild(NULL, "korto"); /* For testing wildcard */
    corto_voidCreateChild(NULL, "karto"); /* For testing asterisk */

    /* Objects to test trees */
    corto_object _1 = corto_voidCreateChild(c, "b");
    corto_object _2 = corto_voidCreateChild(c, "c");
    corto_object _3 = corto_voidCreateChild(c, "abc"); /* For matching filters */
    corto_object _4 = corto_voidCreateChild(c, "abd"); /* For wildcard testing */
    corto_object _5 = corto_voidCreateChild(c, "abdc"); /* For asterisk testing */
    corto_object _6 = corto_voidCreateChild(c, "Abab"); /* For caps testing */
    corto_object _7 = corto_voidCreateChild(c, "ab_ab"); /* Testing underscores */
    corto_object _8 = corto_voidCreateChild(c, "ab01234567890"); /* Testing numbers */

    /* Add one more level of nesting */
    corto_voidCreateChild(_1, "abcdef");
    corto_voidCreateChild(_2, "abcdef");
    corto_voidCreateChild(_3, "abcdef");
    corto_voidCreateChild(_4, "abcdef");
    corto_voidCreateChild(_5, "abcdef");
    corto_voidCreateChild(_6, "abcdef");
    corto_voidCreateChild(_7, "abcdef");
    corto_voidCreateChild(_8, "abcdef");

/* $end */
}

corto_void _test_Select_tc_selectErrParentAst(test_Select this) {
/* $begin(test/Select/tc_selectErrParentAst) */
    corto_iter iter;

    corto_int16 ret = corto_select(NULL, "..*", &iter);
    test_assert(ret != 0);
    test_assert(corto_lasterr() != NULL);
    test_assert(!strcmp(corto_lasterr(), "select '..*' failed: unexpected '*' after '..'"));

/* $end */
}

corto_void _test_Select_tc_selectErrParentId(test_Select this) {
/* $begin(test/Select/tc_selectErrParentId) */
    corto_iter iter;

    corto_int16 ret = corto_select(NULL, "..id", &iter);
    test_assert(ret != 0);
    test_assert(corto_lasterr() != NULL);
    test_assert(!strcmp(corto_lasterr(), "select '..id' failed: unexpected 'identifier' after '..'"));

/* $end */
}

corto_void _test_Select_tc_selectErrParentTree(test_Select this) {
/* $begin(test/Select/tc_selectErrParentTree) */
    corto_iter iter;

    corto_int16 ret = corto_select(NULL, "...", &iter);
    test_assert(ret != 0);
    test_assert(corto_lasterr() != NULL);
    test_assert(!strcmp(corto_lasterr(), "select '...' failed: unexpected '.' after '..'"));

/* $end */
}

corto_void _test_Select_tc_selectErrParentWc(test_Select this) {
/* $begin(test/Select/tc_selectErrParentWc) */
    corto_iter iter;

    corto_int16 ret = corto_select(NULL, "..?", &iter);
    test_assert(ret != 0);
    test_assert(corto_lasterr() != NULL);
    test_assert(!strcmp(corto_lasterr(), "select '..?' failed: unexpected '?' after '..'"));

/* $end */
}

corto_void _test_Select_tc_selectErrScopeScope(test_Select this) {
/* $begin(test/Select/tc_selectErrScopeScope) */
    corto_iter iter;

    corto_int16 ret = corto_select(NULL, "::::", &iter);
    test_assert(ret != 0);
    test_assert(corto_lasterr() != NULL);
    test_assert(!strcmp(corto_lasterr(), "select '::::' failed: unexpected '/' after '/'"));

/* $end */
}

corto_void _test_Select_tc_selectFilterAsterisk(test_Select this) {
/* $begin(test/Select/tc_selectFilterAsterisk) */
    corto_ll results = NULL;

    results = test_Select_collect(NULL, "*rto");
    test_assert(results != NULL);
    test_assert(corto_llSize(results) == 3);

    test_assert(test_Select_hasObject(results, ".", "corto", "package"));
    test_assert(test_Select_hasObject(results, ".", "karto", "void"));
    test_assert(test_Select_hasObject(results, ".", "korto", "void"));

/* $end */
}

corto_void _test_Select_tc_selectFilterWildcard(test_Select this) {
/* $begin(test/Select/tc_selectFilterWildcard) */
    corto_ll results = NULL;

    results = test_Select_collect(NULL, "?orto");
    test_assert(results != NULL);
    test_assert(corto_llSize(results) == 2);

    test_assert(test_Select_hasObject(results, ".", "corto", "package"));
    test_assert(test_Select_hasObject(results, ".", "korto", "void"));

/* $end */
}

corto_void _test_Select_tc_selectIdentifier(test_Select this) {
/* $begin(test/Select/tc_selectIdentifier) */
    corto_ll results = NULL;
    test_selectItem *item;

    corto_object a = corto_resolve(NULL, "a");
    test_assert(a != NULL);

    results = test_Select_collect(NULL, "a");
    test_assert(results != NULL);
    test_assert(corto_llSize(results) == 1);

    item = corto_llGet(results, 0);
    test_assert(item != NULL);
    test_assert(!strcmp(item->parent, "."));
    test_assert(!strcmp(item->name, "a"));
    test_assert(!strcmp(item->type, "void"));

    corto_release(a);

/* $end */
}

corto_void _test_Select_tc_selectIdentifierCaps(test_Select this) {
/* $begin(test/Select/tc_selectIdentifierCaps) */
    corto_ll results = NULL;

    results = test_Select_collect(NULL, "a/ABC");
    test_assert(results != NULL);
    test_assert(corto_llSize(results) == 1);

    test_assert(test_Select_hasObject(results, "a", "abc", "void"));

/* $end */
}

corto_void _test_Select_tc_selectNumeric(test_Select this) {
/* $begin(test/Select/tc_selectNumeric) */
    corto_ll results = NULL;

    results = test_Select_collect(NULL, "a/ab01234567890");
    test_assert(results != NULL);
    test_assert(corto_llSize(results) == 1);

    test_assert(test_Select_hasObject(results, "a", "ab01234567890", "void"));

/* $end */
}

corto_void _test_Select_tc_selectParent(test_Select this) {
/* $begin(test/Select/tc_selectParent) */
    corto_ll results = NULL;
    test_selectItem *item;

    corto_object a = corto_resolve(NULL, "a");
    test_assert(a != NULL);

    results = test_Select_collect(a, "..");
    test_assert(results != NULL);
    test_assert(corto_llSize(results) == 1);

    item = corto_llGet(results, 0);
    test_assert(item != NULL);
    test_assert(!strcmp(item->parent, ""));
    test_assert(!strcmp(item->name, ""));
    test_assert(!strcmp(item->type, "package"));

    corto_release(a);

/* $end */
}

corto_void _test_Select_tc_selectScope(test_Select this) {
/* $begin(test/Select/tc_selectScope) */
    corto_ll results = NULL;

    results = test_Select_collect(NULL, "a/");
    test_assert(results != NULL);
    test_assert(corto_llSize(results) == 8);

    test_assert(test_Select_hasObject(results, "a", "b", "void"));
    test_assert(test_Select_hasObject(results, "a", "c", "void"));
    test_assert(test_Select_hasObject(results, "a", "abc", "void"));
    test_assert(test_Select_hasObject(results, "a", "abd", "void"));
    test_assert(test_Select_hasObject(results, "a", "abdc", "void"));
    test_assert(test_Select_hasObject(results, "a", "Abab", "void"));
    test_assert(test_Select_hasObject(results, "a", "ab_ab", "void"));
    test_assert(test_Select_hasObject(results, "a", "ab01234567890", "void"));

/* $end */
}

corto_void _test_Select_tc_selectScopedIdentifier(test_Select this) {
/* $begin(test/Select/tc_selectScopedIdentifier) */
    corto_ll results = NULL;
    test_selectItem *item;

    results = test_Select_collect(NULL, "a/b");
    test_assert(results != NULL);
    test_assert(corto_llSize(results) == 1);

    item = corto_llGet(results, 0);
    test_assert(item != NULL);
    test_assert(!strcmp(item->parent, "a"));
    test_assert(!strcmp(item->name, "b"));
    test_assert(!strcmp(item->type, "void"));

/* $end */
}

corto_void _test_Select_tc_selectScopedParent(test_Select this) {
/* $begin(test/Select/tc_selectScopedParent) */
    corto_ll results = NULL;
    test_selectItem *item;

    results = test_Select_collect(NULL, "a/..");
    test_assert(results != NULL);
    test_assert(corto_llSize(results) == 1);

    item = corto_llGet(results, 0);
    test_assert(item != NULL);
    test_assert(!strcmp(item->parent, ""));
    test_assert(!strcmp(item->name, ""));
    test_assert(!strcmp(item->type, "package"));

/* $end */
}

corto_void _test_Select_tc_selectScopedThis(test_Select this) {
/* $begin(test/Select/tc_selectScopedThis) */
    corto_ll results = NULL;
    test_selectItem *item;

    results = test_Select_collect(NULL, "a/.");
    test_assert(results != NULL);
    test_assert(corto_llSize(results) == 1);

    item = corto_llGet(results, 0);
    test_assert(item != NULL);
    test_assert(!strcmp(item->parent, "."));
    test_assert(!strcmp(item->name, "a"));
    test_assert(!strcmp(item->type, "void"));

/* $end */
}

corto_void _test_Select_tc_selectScopeWithAsterisk(test_Select this) {
/* $begin(test/Select/tc_selectScopeWithAsterisk) */
    corto_ll results = NULL;

    results = test_Select_collect(NULL, "a/*");
    test_assert(results != NULL);
    test_assert(corto_llSize(results) == 8);

    test_assert(test_Select_hasObject(results, "a", "b", "void"));
    test_assert(test_Select_hasObject(results, "a", "c", "void"));
    test_assert(test_Select_hasObject(results, "a", "abc", "void"));
    test_assert(test_Select_hasObject(results, "a", "abd", "void"));
    test_assert(test_Select_hasObject(results, "a", "abdc", "void"));
    test_assert(test_Select_hasObject(results, "a", "Abab", "void"));
    test_assert(test_Select_hasObject(results, "a", "ab_ab", "void"));
    test_assert(test_Select_hasObject(results, "a", "ab01234567890", "void"));

/* $end */
}

corto_void _test_Select_tc_selectScopeWithAsteriskFilter(test_Select this) {
/* $begin(test/Select/tc_selectScopeWithAsteriskFilter) */
    corto_ll results = NULL;

    results = test_Select_collect(NULL, "a/ab*");
    test_assert(results != NULL);
    test_assert(corto_llSize(results) == 6);

    test_assert(test_Select_hasObject(results, "a", "abc", "void"));
    test_assert(test_Select_hasObject(results, "a", "abd", "void"));
    test_assert(test_Select_hasObject(results, "a", "abdc", "void"));
    test_assert(test_Select_hasObject(results, "a", "Abab", "void"));
    test_assert(test_Select_hasObject(results, "a", "ab_ab", "void"));
    test_assert(test_Select_hasObject(results, "a", "ab01234567890", "void"));

/* $end */
}

corto_void _test_Select_tc_selectScopeWithWildcard(test_Select this) {
/* $begin(test/Select/tc_selectScopeWithWildcard) */
    corto_ll results = NULL;

    results = test_Select_collect(NULL, "a/?");
    test_assert(results != NULL);
    test_assert(corto_llSize(results) == 2);

    test_assert(test_Select_hasObject(results, "a", "b", "void"));
    test_assert(test_Select_hasObject(results, "a", "c", "void"));

/* $end */
}

corto_void _test_Select_tc_selectScopeWithWildcardFilter(test_Select this) {
/* $begin(test/Select/tc_selectScopeWithWildcardFilter) */
    corto_ll results = NULL;

    results = test_Select_collect(NULL, "a/ab?");
    test_assert(results != NULL);
    test_assert(corto_llSize(results) == 2);

    test_assert(test_Select_hasObject(results, "a", "abc", "void"));
    test_assert(test_Select_hasObject(results, "a", "abd", "void"));

/* $end */
}

corto_void _test_Select_tc_selectThis(test_Select this) {
/* $begin(test/Select/tc_selectThis) */
    corto_ll results = NULL;
    test_selectItem *item;

    corto_object a = corto_resolve(NULL, "a");
    test_assert(a != NULL);

    results = test_Select_collect(a, ".");
    test_assert(results != NULL);
    test_assert(corto_llSize(results) == 1);

    item = corto_llGet(results, 0);
    test_assert(item != NULL);
    test_assert(!strcmp(item->parent, ".."));
    test_assert(!strcmp(item->name, "a"));
    test_assert(!strcmp(item->type, "void"));

    corto_release(a);

/* $end */
}

corto_void _test_Select_tc_selectTree(test_Select this) {
/* $begin(test/Select/tc_selectTree) */
    corto_ll results = NULL;

    results = test_Select_collect(NULL, "a//");
    test_assert(results != NULL);
    test_assert(corto_llSize(results) == 24);

    test_assert(test_Select_hasObject(results, "a", "b", "void"));
    test_assert(test_Select_hasObject(results, "a", "c", "void"));
    test_assert(test_Select_hasObject(results, "a", "abc", "void"));
    test_assert(test_Select_hasObject(results, "a", "abd", "void"));
    test_assert(test_Select_hasObject(results, "a", "abdc", "void"));
    test_assert(test_Select_hasObject(results, "a", "Abab", "void"));
    test_assert(test_Select_hasObject(results, "a", "ab_ab", "void"));
    test_assert(test_Select_hasObject(results, "a", "ab01234567890", "void"));

    test_assert(test_Select_hasObject(results, "a/c", "b", "void"));
    test_assert(test_Select_hasObject(results, "a/c", "c", "void"));
    test_assert(test_Select_hasObject(results, "a/c", "abc", "void"));
    test_assert(test_Select_hasObject(results, "a/c", "abd", "void"));
    test_assert(test_Select_hasObject(results, "a/c", "abdc", "void"));
    test_assert(test_Select_hasObject(results, "a/c", "Abab", "void"));
    test_assert(test_Select_hasObject(results, "a/c", "ab_ab", "void"));
    test_assert(test_Select_hasObject(results, "a/c", "ab01234567890", "void"));

    test_assert(test_Select_hasObject(results, "a/c/b", "abcdef", "void"));
    test_assert(test_Select_hasObject(results, "a/c/c", "abcdef", "void"));
    test_assert(test_Select_hasObject(results, "a/c/abc", "abcdef", "void"));
    test_assert(test_Select_hasObject(results, "a/c/abd", "abcdef", "void"));
    test_assert(test_Select_hasObject(results, "a/c/abdc", "abcdef", "void"));
    test_assert(test_Select_hasObject(results, "a/c/Abab", "abcdef", "void"));
    test_assert(test_Select_hasObject(results, "a/c/ab_ab", "abcdef", "void"));
    test_assert(test_Select_hasObject(results, "a/c/ab01234567890", "abcdef", "void"));
/* $end */
}

corto_void _test_Select_tc_selectTreeWithAsterisk(test_Select this) {
/* $begin(test/Select/tc_selectTreeWithAsterisk) */
    corto_ll results = NULL;

    results = test_Select_collect(NULL, "a//*");
    test_assert(results != NULL);
    test_assert(corto_llSize(results) == 24);

    test_assert(test_Select_hasObject(results, "a", "b", "void"));
    test_assert(test_Select_hasObject(results, "a", "c", "void"));
    test_assert(test_Select_hasObject(results, "a", "abc", "void"));
    test_assert(test_Select_hasObject(results, "a", "abd", "void"));
    test_assert(test_Select_hasObject(results, "a", "abdc", "void"));
    test_assert(test_Select_hasObject(results, "a", "Abab", "void"));
    test_assert(test_Select_hasObject(results, "a", "ab_ab", "void"));
    test_assert(test_Select_hasObject(results, "a", "ab01234567890", "void"));

    test_assert(test_Select_hasObject(results, "a/c", "b", "void"));
    test_assert(test_Select_hasObject(results, "a/c", "c", "void"));
    test_assert(test_Select_hasObject(results, "a/c", "abc", "void"));
    test_assert(test_Select_hasObject(results, "a/c", "abd", "void"));
    test_assert(test_Select_hasObject(results, "a/c", "abdc", "void"));
    test_assert(test_Select_hasObject(results, "a/c", "Abab", "void"));
    test_assert(test_Select_hasObject(results, "a/c", "ab_ab", "void"));
    test_assert(test_Select_hasObject(results, "a/c", "ab01234567890", "void"));

    test_assert(test_Select_hasObject(results, "a/c/b", "abcdef", "void"));
    test_assert(test_Select_hasObject(results, "a/c/c", "abcdef", "void"));
    test_assert(test_Select_hasObject(results, "a/c/abc", "abcdef", "void"));
    test_assert(test_Select_hasObject(results, "a/c/abd", "abcdef", "void"));
    test_assert(test_Select_hasObject(results, "a/c/abdc", "abcdef", "void"));
    test_assert(test_Select_hasObject(results, "a/c/Abab", "abcdef", "void"));
    test_assert(test_Select_hasObject(results, "a/c/ab_ab", "abcdef", "void"));
    test_assert(test_Select_hasObject(results, "a/c/ab01234567890", "abcdef", "void"));

/* $end */
}

corto_void _test_Select_tc_selectTreeWithAsteriskFilter(test_Select this) {
/* $begin(test/Select/tc_selectTreeWithAsteriskFilter) */
    corto_ll results = NULL;

    results = test_Select_collect(NULL, "a//ab*");
    test_assert(results != NULL);
    test_assert(corto_llSize(results) == 20);

    test_assert(test_Select_hasObject(results, "a", "abc", "void"));
    test_assert(test_Select_hasObject(results, "a", "abd", "void"));
    test_assert(test_Select_hasObject(results, "a", "abdc", "void"));
    test_assert(test_Select_hasObject(results, "a", "Abab", "void"));
    test_assert(test_Select_hasObject(results, "a", "ab_ab", "void"));
    test_assert(test_Select_hasObject(results, "a", "ab01234567890", "void"));

    test_assert(test_Select_hasObject(results, "a/c", "abc", "void"));
    test_assert(test_Select_hasObject(results, "a/c", "abd", "void"));
    test_assert(test_Select_hasObject(results, "a/c", "abdc", "void"));
    test_assert(test_Select_hasObject(results, "a/c", "Abab", "void"));
    test_assert(test_Select_hasObject(results, "a/c", "ab_ab", "void"));
    test_assert(test_Select_hasObject(results, "a/c", "ab01234567890", "void"));

    test_assert(test_Select_hasObject(results, "a/c/b", "abcdef", "void"));
    test_assert(test_Select_hasObject(results, "a/c/c", "abcdef", "void"));
    test_assert(test_Select_hasObject(results, "a/c/abc", "abcdef", "void"));
    test_assert(test_Select_hasObject(results, "a/c/abd", "abcdef", "void"));
    test_assert(test_Select_hasObject(results, "a/c/abdc", "abcdef", "void"));
    test_assert(test_Select_hasObject(results, "a/c/Abab", "abcdef", "void"));
    test_assert(test_Select_hasObject(results, "a/c/ab_ab", "abcdef", "void"));
    test_assert(test_Select_hasObject(results, "a/c/ab01234567890", "abcdef", "void"));

/* $end */
}

corto_void _test_Select_tc_selectTreeWithWildcard(test_Select this) {
/* $begin(test/Select/tc_selectTreeWithWildcard) */
    corto_ll results = NULL;

    results = test_Select_collect(NULL, "a//?");
    test_assert(results != NULL);
    test_assert(corto_llSize(results) == 4);

    test_assert(test_Select_hasObject(results, "a", "b", "void"));
    test_assert(test_Select_hasObject(results, "a", "c", "void"));

    test_assert(test_Select_hasObject(results, "a/c", "b", "void"));
    test_assert(test_Select_hasObject(results, "a/c", "c", "void"));

/* $end */
}

corto_void _test_Select_tc_selectTreeWithWildcardFilter(test_Select this) {
/* $begin(test/Select/tc_selectTreeWithWildcardFilter) */
    corto_ll results = NULL;

    results = test_Select_collect(NULL, "a//ab?");
    test_assert(results != NULL);
    test_assert(corto_llSize(results) == 4);

    test_assert(test_Select_hasObject(results, "a", "abc", "void"));
    test_assert(test_Select_hasObject(results, "a", "abd", "void"));

    test_assert(test_Select_hasObject(results, "a/c", "abc", "void"));
    test_assert(test_Select_hasObject(results, "a/c", "abd", "void"));

/* $end */
}

corto_void _test_Select_tc_selectUnderscore(test_Select this) {
/* $begin(test/Select/tc_selectUnderscore) */
    corto_ll results = NULL;

    results = test_Select_collect(NULL, "a/ab_ab");
    test_assert(results != NULL);
    test_assert(corto_llSize(results) == 1);

    test_assert(test_Select_hasObject(results, "a", "ab_ab", "void"));

/* $end */
}

corto_void _test_Select_teardown(test_Select this) {
/* $begin(test/Select/teardown) */

    /* << Insert implementation >> */

/* $end */
}
