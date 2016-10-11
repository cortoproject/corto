/* $CORTO_GENERATED
 *
 * Matcher.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <test.h>

corto_void _test_Matcher_tc_filterA(
    test_Matcher this)
{
/* $begin(test/Matcher/tc_filterA) */
    corto_bool result = corto_match("*", "ax");
    test_assertint(result, TRUE);

/* $end */
}

corto_void _test_Matcher_tc_filterAnd(
    test_Matcher this)
{
/* $begin(test/Matcher/tc_filterAnd) */
    corto_bool result = corto_match("a*&*x", "ax");
    test_assertint(result, TRUE);

/* $end */
}

corto_void _test_Matcher_tc_filterAndFail(
    test_Matcher this)
{
/* $begin(test/Matcher/tc_filterAndFail) */
    corto_bool result = corto_match("a*&*y", "ax");
    test_assertint(result, FALSE);

/* $end */
}

corto_void _test_Matcher_tc_filterAQ(
    test_Matcher this)
{
/* $begin(test/Matcher/tc_filterAQ) */
    corto_bool result = corto_match("*?", "ax");
    test_assertint(result, TRUE);

/* $end */
}

corto_void _test_Matcher_tc_filterFail(
    test_Matcher this)
{
/* $begin(test/Matcher/tc_filterFail) */
    corto_bool result = corto_match("b*", "ax");
    test_assertint(result, FALSE);

/* $end */
}

corto_void _test_Matcher_tc_filterIdA(
    test_Matcher this)
{
/* $begin(test/Matcher/tc_filterIdA) */
    corto_bool result = corto_match("a*", "ax");
    test_assertint(result, TRUE);

/* $end */
}

corto_void _test_Matcher_tc_filterIdAFail(
    test_Matcher this)
{
/* $begin(test/Matcher/tc_filterIdAFail) */
    corto_bool result = corto_match("a*", "bx");
    test_assertint(result, FALSE);

/* $end */
}

corto_void _test_Matcher_tc_filterIdQ(
    test_Matcher this)
{
/* $begin(test/Matcher/tc_filterIdQ) */
    corto_bool result = corto_match("a?", "ax");
    test_assertint(result, TRUE);

/* $end */
}

corto_void _test_Matcher_tc_filterIdQFail(
    test_Matcher this)
{
/* $begin(test/Matcher/tc_filterIdQFail) */
    corto_bool result = corto_match("a?", "bx");
    test_assertint(result, FALSE);

/* $end */
}

corto_void _test_Matcher_tc_filterNot(
    test_Matcher this)
{
/* $begin(test/Matcher/tc_filterNot) */
    corto_bool result = corto_match("^b*", "ax");
    test_assertint(result, TRUE);

/* $end */
}

corto_void _test_Matcher_tc_filterNotAnd(
    test_Matcher this)
{
/* $begin(test/Matcher/tc_filterNotAnd) */
    corto_bool result = corto_match("^a*&*y", "ax");
    test_assertint(result, TRUE);

/* $end */
}

corto_void _test_Matcher_tc_filterNotAndFail(
    test_Matcher this)
{
/* $begin(test/Matcher/tc_filterNotAndFail) */
    corto_bool result = corto_match("^a*&*x", "ax");
    test_assertint(result, FALSE);

/* $end */
}

corto_void _test_Matcher_tc_filterNotFail(
    test_Matcher this)
{
/* $begin(test/Matcher/tc_filterNotFail) */
    corto_bool result = corto_match("^b*", "bx");
    test_assertint(result, FALSE);

/* $end */
}

corto_void _test_Matcher_tc_filterNotFilter(
    test_Matcher this)
{
/* $begin(test/Matcher/tc_filterNotFilter) */
    corto_bool result = corto_match("*x^b*", "ax");
    test_assertint(result, TRUE);

    result = corto_match("*x^b*", "cx");
    test_assertint(result, TRUE);

/* $end */
}

corto_void _test_Matcher_tc_filterNotFilterFail(
    test_Matcher this)
{
/* $begin(test/Matcher/tc_filterNotFilterFail) */
    corto_bool result = corto_match("*x^a*", "ax");
    test_assertint(result, FALSE);

    result = corto_match("*x^a*", "by");
    test_assertint(result, FALSE);

/* $end */
}

corto_void _test_Matcher_tc_filterNotOr(
    test_Matcher this)
{
/* $begin(test/Matcher/tc_filterNotOr) */
    corto_bool result = corto_match("^b*|c*", "ax");
    test_assertint(result, TRUE);

/* $end */
}

corto_void _test_Matcher_tc_filterNotOrFail(
    test_Matcher this)
{
/* $begin(test/Matcher/tc_filterNotOrFail) */
    corto_bool result = corto_match("^a*|b*", "ax");
    test_assertint(result, FALSE);

    result = corto_match("^a*|b*", "by");
    test_assertint(result, FALSE);

    result = corto_match("^a*|b*", "bx");
    test_assertint(result, FALSE);

/* $end */
}

corto_void _test_Matcher_tc_filterOr(
    test_Matcher this)
{
/* $begin(test/Matcher/tc_filterOr) */
    corto_bool result = corto_match("a*|b*", "ax");
    test_assertint(result, TRUE);

    result = corto_match("a*|b*", "ay");
    test_assertint(result, TRUE);

    result = corto_match("a*|b*", "bx");
    test_assertint(result, TRUE);

    result = corto_match("a*|*x", "ax");
    test_assertint(result, TRUE);

    result = corto_match("a*|*x", "abcx");
    test_assertint(result, TRUE);

/* $end */
}

corto_void _test_Matcher_tc_filterOrFail(
    test_Matcher this)
{
/* $begin(test/Matcher/tc_filterOrFail) */
    corto_bool result = corto_match("a*|b*", "cx");
    test_assertint(result, FALSE);

    result = corto_match("a*|*y", "cx");
    test_assertint(result, FALSE);

/* $end */
}

corto_void _test_Matcher_tc_filterQA(
    test_Matcher this)
{
/* $begin(test/Matcher/tc_filterQA) */
    corto_bool result = corto_match("?*", "ax");
    test_assertint(result, TRUE);

    result = corto_match("?*", "abc");
    test_assertint(result, TRUE);

/* $end */
}

corto_void _test_Matcher_tc_filterQFail(
    test_Matcher this)
{
/* $begin(test/Matcher/tc_filterQFail) */
    corto_bool result = corto_match("?", "ax");
    test_assertint(result, FALSE);

/* $end */
}

corto_void _test_Matcher_tc_filterQQ(
    test_Matcher this)
{
/* $begin(test/Matcher/tc_filterQQ) */
    corto_bool result = corto_match("??", "ax");
    test_assertint(result, TRUE);

/* $end */
}

corto_void _test_Matcher_tc_filterQQFail(
    test_Matcher this)
{
/* $begin(test/Matcher/tc_filterQQFail) */
    corto_bool result = corto_match("??", "a");
    test_assertint(result, FALSE);

/* $end */
}

corto_void _test_Matcher_tc_id(
    test_Matcher this)
{
/* $begin(test/Matcher/tc_id) */
    corto_bool result = corto_match("a", "a");
    test_assertint(result, TRUE);

/* $end */
}

corto_void _test_Matcher_tc_idAnd(
    test_Matcher this)
{
/* $begin(test/Matcher/tc_idAnd) */
    corto_bool result = corto_match("a&a", "a");
    test_assertint(result, TRUE);

/* $end */
}

corto_void _test_Matcher_tc_idAndFail(
    test_Matcher this)
{
/* $begin(test/Matcher/tc_idAndFail) */
    corto_bool result = corto_match("a&b", "a");
    test_assertint(result, FALSE);

/* $end */
}

corto_void _test_Matcher_tc_idFail(
    test_Matcher this)
{
/* $begin(test/Matcher/tc_idFail) */
    corto_bool result = corto_match("b", "a");
    test_assertint(result, FALSE);

/* $end */
}

corto_void _test_Matcher_tc_idNot(
    test_Matcher this)
{
/* $begin(test/Matcher/tc_idNot) */
    corto_bool result = corto_match("^b", "a");
    test_assertint(result, TRUE);

/* $end */
}

corto_void _test_Matcher_tc_idNotAnd(
    test_Matcher this)
{
/* $begin(test/Matcher/tc_idNotAnd) */
    corto_bool result = corto_match("^a&b", "a");
    test_assertint(result, TRUE);

/* $end */
}

corto_void _test_Matcher_tc_idNotAndFail(
    test_Matcher this)
{
/* $begin(test/Matcher/tc_idNotAndFail) */
    corto_bool result = corto_match("^a&a", "a");
    test_assertint(result, FALSE);

/* $end */
}

corto_void _test_Matcher_tc_idNotFail(
    test_Matcher this)
{
/* $begin(test/Matcher/tc_idNotFail) */
    corto_bool result = corto_match("^b", "b");
    test_assertint(result, FALSE);

/* $end */
}

corto_void _test_Matcher_tc_idNotOr(
    test_Matcher this)
{
/* $begin(test/Matcher/tc_idNotOr) */
    corto_bool result = corto_match("^b|c", "a");
    test_assertint(result, TRUE);

/* $end */
}

corto_void _test_Matcher_tc_idNotOrFail(
    test_Matcher this)
{
/* $begin(test/Matcher/tc_idNotOrFail) */
    corto_bool result = corto_match("^a|b", "a");
    test_assertint(result, FALSE);

/* $end */
}

corto_void _test_Matcher_tc_idOr(
    test_Matcher this)
{
/* $begin(test/Matcher/tc_idOr) */
    corto_bool result = corto_match("a|b", "a");
    test_assertint(result, TRUE);

    result = corto_match("a|b", "b");
    test_assertint(result, TRUE);

/* $end */
}

corto_void _test_Matcher_tc_idOrFail(
    test_Matcher this)
{
/* $begin(test/Matcher/tc_idOrFail) */
    corto_bool result = corto_match("a|b", "c");
    test_assertint(result, FALSE);

/* $end */
}

corto_void _test_Matcher_tc_idOrMulti(
    test_Matcher this)
{
/* $begin(test/Matcher/tc_idOrMulti) */
    corto_bool result = corto_match("a|b|c|d|e|f", "a");
    test_assertint(result, TRUE);

    result = corto_match("a|b|c|d|e|f", "b");
    test_assertint(result, TRUE);

    result = corto_match("a|b|c|d|e|f", "c");
    test_assertint(result, TRUE);

    result = corto_match("a|b|c|d|e|f", "d");
    test_assertint(result, TRUE);

    result = corto_match("a|b|c|d|e|f", "e");
    test_assertint(result, TRUE);

    result = corto_match("a|b|c|d|e|f", "f");
    test_assertint(result, TRUE);

/* $end */
}

corto_void _test_Matcher_tc_idOrMultiFail(
    test_Matcher this)
{
/* $begin(test/Matcher/tc_idOrMultiFail) */
    corto_bool result = corto_match("a|b|c|d|e|f", "g");
    test_assertint(result, FALSE);

/* $end */
}

corto_void _test_Matcher_tc_scopeFilter(
    test_Matcher this)
{
/* $begin(test/Matcher/tc_scopeFilter) */
    corto_bool result = corto_match("/a*", "/ax");
    test_assertint(result, TRUE);

    result = corto_match("/a*", "/ay");
    test_assertint(result, TRUE);

    result = corto_match("/a*", "/abc");
    test_assertint(result, TRUE);

/* $end */
}

corto_void _test_Matcher_tc_scopeFilterFail(
    test_Matcher this)
{
/* $begin(test/Matcher/tc_scopeFilterFail) */
    corto_bool result = corto_match("/a*", "/bx");
    test_assertint(result, FALSE);

/* $end */
}

corto_void _test_Matcher_tc_scopeFilterMulti(
    test_Matcher this)
{
/* $begin(test/Matcher/tc_scopeFilterMulti) */
    corto_bool result = corto_match("/*x/b", "/ax/b");
    test_assertint(result, TRUE);

    result = corto_match("/*x/b", "/bx/b");
    test_assertint(result, TRUE);

/* $end */
}

corto_void _test_Matcher_tc_scopeFilterMultiFail1(
    test_Matcher this)
{
/* $begin(test/Matcher/tc_scopeFilterMultiFail1) */
    corto_bool result = corto_match("/*y/b", "/ax/b");
    test_assertint(result, FALSE);

    result = corto_match("/*y/b", "/ayx/b");
    test_assertint(result, FALSE);

    result = corto_match("/*y/b", "/a/y/b");
    test_assertint(result, FALSE);

/* $end */
}

corto_void _test_Matcher_tc_scopeFilterMultiFail2(
    test_Matcher this)
{
/* $begin(test/Matcher/tc_scopeFilterMultiFail2) */
    corto_bool result = corto_match("/*x/c", "/ax/b");
    test_assertint(result, FALSE);

    result = corto_match("/*x/c", "/axy/c");
    test_assertint(result, FALSE);

/* $end */
}

corto_void _test_Matcher_tc_scopeFilterMultiSingleFail(
    test_Matcher this)
{
/* $begin(test/Matcher/tc_scopeFilterMultiSingleFail) */
    corto_bool result = corto_match("/a", "/a/b");
    test_assertint(result, FALSE);

/* $end */
}

corto_void _test_Matcher_tc_scopeFilterSingleMultiFail(
    test_Matcher this)
{
/* $begin(test/Matcher/tc_scopeFilterSingleMultiFail) */
    corto_bool result = corto_match("/a/b", "/a");
    test_assertint(result, FALSE);

/* $end */
}

corto_void _test_Matcher_tc_scopeId(
    test_Matcher this)
{
/* $begin(test/Matcher/tc_scopeId) */
    corto_bool result = corto_match("/a", "/a");
    test_assertint(result, TRUE);

/* $end */
}

corto_void _test_Matcher_tc_scopeIdFail(
    test_Matcher this)
{
/* $begin(test/Matcher/tc_scopeIdFail) */
    corto_bool result = corto_match("/b", "/a");
    test_assertint(result, FALSE);

/* $end */
}

corto_void _test_Matcher_tc_scopeIdMulti(
    test_Matcher this)
{
/* $begin(test/Matcher/tc_scopeIdMulti) */
    corto_bool result = corto_match("/a/b", "/a/b");
    test_assertint(result, TRUE);

/* $end */
}

corto_void _test_Matcher_tc_scopeIdMultiFail(
    test_Matcher this)
{
/* $begin(test/Matcher/tc_scopeIdMultiFail) */
    corto_bool result = corto_match("/a/c", "/a/b");
    test_assertint(result, FALSE);

/* $end */
}

corto_void _test_Matcher_tc_scopeIdMultiSingleFail(
    test_Matcher this)
{
/* $begin(test/Matcher/tc_scopeIdMultiSingleFail) */
    corto_bool result = corto_match("/a", "/a/b");
    test_assertint(result, FALSE);

/* $end */
}

corto_void _test_Matcher_tc_scopeIdSingleMultiFail(
    test_Matcher this)
{
/* $begin(test/Matcher/tc_scopeIdSingleMultiFail) */
    corto_bool result = corto_match("/a/b", "/a");
    test_assertint(result, FALSE);

/* $end */
}

corto_void _test_Matcher_tc_scopeOr(
    test_Matcher this)
{
/* $begin(test/Matcher/tc_scopeOr) */
    corto_bool result = corto_match("/a|b", "/a");
    test_assertint(result, TRUE);

    result = corto_match("/a|b", "/b");
    test_assertint(result, TRUE);

/* $end */
}

corto_void _test_Matcher_tc_scopeOrFail(
    test_Matcher this)
{
/* $begin(test/Matcher/tc_scopeOrFail) */
    corto_bool result = corto_match("/a|b", "/c");
    test_assertint(result, FALSE);

/* $end */
}

corto_void _test_Matcher_tc_scopeOrMulti(
    test_Matcher this)
{
/* $begin(test/Matcher/tc_scopeOrMulti) */
    corto_bool result = corto_match("/a/b|c", "/a/b");
    test_assertint(result, TRUE);

    result = corto_match("/a/b|c", "/a/c");
    test_assertint(result, TRUE);

/* $end */
}

corto_void _test_Matcher_tc_scopeOrMultiFail(
    test_Matcher this)
{
/* $begin(test/Matcher/tc_scopeOrMultiFail) */
    corto_bool result = corto_match("/a/b|c", "/a/d");
    test_assertint(result, FALSE);

    result = corto_match("/a/b|c", "/b/b");
    test_assertint(result, FALSE);

/* $end */
}

corto_void _test_Matcher_tc_separatorFilter(
    test_Matcher this)
{
/* $begin(test/Matcher/tc_separatorFilter) */
    corto_bool result = corto_match("b*,*x", "ax");
    test_assertint(result, TRUE);

    result = corto_match("b*,*x", "bx");
    test_assertint(result, TRUE);

    result = corto_match("b*,*x", "by");
    test_assertint(result, TRUE);

/* $end */
}

corto_void _test_Matcher_tc_separatorFilterFail(
    test_Matcher this)
{
/* $begin(test/Matcher/tc_separatorFilterFail) */
    corto_bool result = corto_match("b*,*y", "ax");
    test_assertint(result, FALSE);

/* $end */
}

corto_void _test_Matcher_tc_separatorId(
    test_Matcher this)
{
/* $begin(test/Matcher/tc_separatorId) */
    corto_bool result = corto_match("a,b", "a");
    test_assertint(result, TRUE);

    result = corto_match("a,b", "b");
    test_assertint(result, TRUE);

/* $end */
}

corto_void _test_Matcher_tc_separatorIdFail(
    test_Matcher this)
{
/* $begin(test/Matcher/tc_separatorIdFail) */
    corto_bool result = corto_match("a,b", "c");
    test_assertint(result, FALSE);

/* $end */
}

corto_void _test_Matcher_tc_separatorNotFilter(
    test_Matcher this)
{
/* $begin(test/Matcher/tc_separatorNotFilter) */
    corto_bool result = corto_match("^b*,*y", "ax");
    test_assertint(result, TRUE);

    result = corto_match("^b*,*y", "by");
    test_assertint(result, TRUE);

/* $end */
}

corto_void _test_Matcher_tc_separatorNotFilterFail(
    test_Matcher this)
{
/* $begin(test/Matcher/tc_separatorNotFilterFail) */
    corto_bool result = corto_match("^a*,*y", "ax");
    test_assertint(result, FALSE);

/* $end */
}

corto_void _test_Matcher_tc_treeId(
    test_Matcher this)
{
/* $begin(test/Matcher/tc_treeId) */
    corto_bool result = corto_match("//a", "/a");
    test_assertint(result, TRUE);

/* $end */
}

corto_void _test_Matcher_tc_treeIdFail(
    test_Matcher this)
{
/* $begin(test/Matcher/tc_treeIdFail) */
    corto_bool result = corto_match("//b", "/a");
    test_assertint(result, FALSE);

/* $end */
}

corto_void _test_Matcher_tc_treeNested(
    test_Matcher this)
{
/* $begin(test/Matcher/tc_treeNested) */
    corto_bool result = corto_match("//b", "/a/b");
    test_assertint(result, TRUE);

    result = corto_match("//c", "/a/b/c");
    test_assertint(result, TRUE);

    result = corto_match("//c", "/a/b/c/c");
    test_assertint(result, TRUE);

/* $end */
}

corto_void _test_Matcher_tc_treeNestedFail(
    test_Matcher this)
{
/* $begin(test/Matcher/tc_treeNestedFail) */
    corto_bool result = corto_match("//a", "/a/b");
    test_assertint(result, FALSE);

/* $end */
}

corto_void _test_Matcher_tc_treeNestedScope(
    test_Matcher this)
{
/* $begin(test/Matcher/tc_treeNestedScope) */
    corto_bool result = corto_match("//b/c", "/a/b/c");
    test_assertint(result, TRUE);

    result = corto_match("//b/c", "/a/x/b/c");
    test_assertint(result, TRUE);

    result = corto_match("//b/c", "/b/c");
    test_assertint(result, TRUE);

/* $end */
}

corto_void _test_Matcher_tc_treeNestedScopeFail(
    test_Matcher this)
{
/* $begin(test/Matcher/tc_treeNestedScopeFail) */
    corto_bool result = corto_match("//b/c", "/a/b");
    test_assertint(result, FALSE);

    result = corto_match("//b/c", "/a/b/c/c");
    test_assertint(result, FALSE);

/* $end */
}
