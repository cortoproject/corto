/* test_Select.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef TEST_SELECT_H
#define TEST_SELECT_H

#include "corto.h"
#include "corto/test/test_SuiteData.h"
#include "test__interface.h"

#ifdef __cplusplus
extern "C" {
#endif

TEST_EXPORT test_selectItemList _test_Select_collect(corto_object scope, corto_string expr);
#define test_Select_collect(scope, expr) _test_Select_collect(scope, expr)

TEST_EXPORT corto_bool _test_Select_hasObject(test_selectItemList items, corto_string parent, corto_string name, corto_string type);
#define test_Select_hasObject(items, parent, name, type) _test_Select_hasObject(items, parent, name, type)

TEST_EXPORT corto_void _test_Select_setup(test_Select _this);
#define test_Select_setup(_this) _test_Select_setup(test_Select(_this))

TEST_EXPORT corto_void _test_Select_tc_selectDeleteCurrent(test_Select _this);
#define test_Select_tc_selectDeleteCurrent(_this) _test_Select_tc_selectDeleteCurrent(test_Select(_this))

TEST_EXPORT corto_void _test_Select_tc_selectDeleteFirst(test_Select _this);
#define test_Select_tc_selectDeleteFirst(_this) _test_Select_tc_selectDeleteFirst(test_Select(_this))

TEST_EXPORT corto_void _test_Select_tc_selectDeleteNext(test_Select _this);
#define test_Select_tc_selectDeleteNext(_this) _test_Select_tc_selectDeleteNext(test_Select(_this))

TEST_EXPORT corto_void _test_Select_tc_selectDeleteParent(test_Select _this);
#define test_Select_tc_selectDeleteParent(_this) _test_Select_tc_selectDeleteParent(test_Select(_this))

TEST_EXPORT corto_void _test_Select_tc_selectDeletePrevious(test_Select _this);
#define test_Select_tc_selectDeletePrevious(_this) _test_Select_tc_selectDeletePrevious(test_Select(_this))

TEST_EXPORT corto_void _test_Select_tc_selectErrParentAst(test_Select _this);
#define test_Select_tc_selectErrParentAst(_this) _test_Select_tc_selectErrParentAst(test_Select(_this))

TEST_EXPORT corto_void _test_Select_tc_selectErrParentId(test_Select _this);
#define test_Select_tc_selectErrParentId(_this) _test_Select_tc_selectErrParentId(test_Select(_this))

TEST_EXPORT corto_void _test_Select_tc_selectErrParentTree(test_Select _this);
#define test_Select_tc_selectErrParentTree(_this) _test_Select_tc_selectErrParentTree(test_Select(_this))

TEST_EXPORT corto_void _test_Select_tc_selectErrParentWc(test_Select _this);
#define test_Select_tc_selectErrParentWc(_this) _test_Select_tc_selectErrParentWc(test_Select(_this))

TEST_EXPORT corto_void _test_Select_tc_selectErrScopeScope(test_Select _this);
#define test_Select_tc_selectErrScopeScope(_this) _test_Select_tc_selectErrScopeScope(test_Select(_this))

TEST_EXPORT corto_void _test_Select_tc_selectFilterAsterisk(test_Select _this);
#define test_Select_tc_selectFilterAsterisk(_this) _test_Select_tc_selectFilterAsterisk(test_Select(_this))

TEST_EXPORT corto_void _test_Select_tc_selectFilterWildcard(test_Select _this);
#define test_Select_tc_selectFilterWildcard(_this) _test_Select_tc_selectFilterWildcard(test_Select(_this))

TEST_EXPORT corto_void _test_Select_tc_selectIdentifier(test_Select _this);
#define test_Select_tc_selectIdentifier(_this) _test_Select_tc_selectIdentifier(test_Select(_this))

TEST_EXPORT corto_void _test_Select_tc_selectIdentifierCaps(test_Select _this);
#define test_Select_tc_selectIdentifierCaps(_this) _test_Select_tc_selectIdentifierCaps(test_Select(_this))

TEST_EXPORT corto_void _test_Select_tc_selectNumeric(test_Select _this);
#define test_Select_tc_selectNumeric(_this) _test_Select_tc_selectNumeric(test_Select(_this))

TEST_EXPORT corto_void _test_Select_tc_selectOrder(test_Select _this);
#define test_Select_tc_selectOrder(_this) _test_Select_tc_selectOrder(test_Select(_this))

TEST_EXPORT corto_void _test_Select_tc_selectParent(test_Select _this);
#define test_Select_tc_selectParent(_this) _test_Select_tc_selectParent(test_Select(_this))

TEST_EXPORT corto_void _test_Select_tc_selectScope(test_Select _this);
#define test_Select_tc_selectScope(_this) _test_Select_tc_selectScope(test_Select(_this))

TEST_EXPORT corto_void _test_Select_tc_selectScopedIdentifier(test_Select _this);
#define test_Select_tc_selectScopedIdentifier(_this) _test_Select_tc_selectScopedIdentifier(test_Select(_this))

TEST_EXPORT corto_void _test_Select_tc_selectScopedParent(test_Select _this);
#define test_Select_tc_selectScopedParent(_this) _test_Select_tc_selectScopedParent(test_Select(_this))

TEST_EXPORT corto_void _test_Select_tc_selectScopedThis(test_Select _this);
#define test_Select_tc_selectScopedThis(_this) _test_Select_tc_selectScopedThis(test_Select(_this))

TEST_EXPORT corto_void _test_Select_tc_selectScopeWithAsterisk(test_Select _this);
#define test_Select_tc_selectScopeWithAsterisk(_this) _test_Select_tc_selectScopeWithAsterisk(test_Select(_this))

TEST_EXPORT corto_void _test_Select_tc_selectScopeWithAsteriskFilter(test_Select _this);
#define test_Select_tc_selectScopeWithAsteriskFilter(_this) _test_Select_tc_selectScopeWithAsteriskFilter(test_Select(_this))

TEST_EXPORT corto_void _test_Select_tc_selectScopeWithWildcard(test_Select _this);
#define test_Select_tc_selectScopeWithWildcard(_this) _test_Select_tc_selectScopeWithWildcard(test_Select(_this))

TEST_EXPORT corto_void _test_Select_tc_selectScopeWithWildcardFilter(test_Select _this);
#define test_Select_tc_selectScopeWithWildcardFilter(_this) _test_Select_tc_selectScopeWithWildcardFilter(test_Select(_this))

TEST_EXPORT corto_void _test_Select_tc_selectThis(test_Select _this);
#define test_Select_tc_selectThis(_this) _test_Select_tc_selectThis(test_Select(_this))

TEST_EXPORT corto_void _test_Select_tc_selectTree(test_Select _this);
#define test_Select_tc_selectTree(_this) _test_Select_tc_selectTree(test_Select(_this))

TEST_EXPORT corto_void _test_Select_tc_selectTreeDeleteCurrent(test_Select _this);
#define test_Select_tc_selectTreeDeleteCurrent(_this) _test_Select_tc_selectTreeDeleteCurrent(test_Select(_this))

TEST_EXPORT corto_void _test_Select_tc_selectTreeDeleteFirst(test_Select _this);
#define test_Select_tc_selectTreeDeleteFirst(_this) _test_Select_tc_selectTreeDeleteFirst(test_Select(_this))

TEST_EXPORT corto_void _test_Select_tc_selectTreeDeleteGrandparent(test_Select _this);
#define test_Select_tc_selectTreeDeleteGrandparent(_this) _test_Select_tc_selectTreeDeleteGrandparent(test_Select(_this))

TEST_EXPORT corto_void _test_Select_tc_selectTreeDeleteNext(test_Select _this);
#define test_Select_tc_selectTreeDeleteNext(_this) _test_Select_tc_selectTreeDeleteNext(test_Select(_this))

TEST_EXPORT corto_void _test_Select_tc_selectTreeDeleteParent(test_Select _this);
#define test_Select_tc_selectTreeDeleteParent(_this) _test_Select_tc_selectTreeDeleteParent(test_Select(_this))

TEST_EXPORT corto_void _test_Select_tc_selectTreeDeletePrevious(test_Select _this);
#define test_Select_tc_selectTreeDeletePrevious(_this) _test_Select_tc_selectTreeDeletePrevious(test_Select(_this))

TEST_EXPORT corto_void _test_Select_tc_selectTreeWithAsterisk(test_Select _this);
#define test_Select_tc_selectTreeWithAsterisk(_this) _test_Select_tc_selectTreeWithAsterisk(test_Select(_this))

TEST_EXPORT corto_void _test_Select_tc_selectTreeWithAsteriskFilter(test_Select _this);
#define test_Select_tc_selectTreeWithAsteriskFilter(_this) _test_Select_tc_selectTreeWithAsteriskFilter(test_Select(_this))

TEST_EXPORT corto_void _test_Select_tc_selectTreeWithWildcard(test_Select _this);
#define test_Select_tc_selectTreeWithWildcard(_this) _test_Select_tc_selectTreeWithWildcard(test_Select(_this))

TEST_EXPORT corto_void _test_Select_tc_selectTreeWithWildcardFilter(test_Select _this);
#define test_Select_tc_selectTreeWithWildcardFilter(_this) _test_Select_tc_selectTreeWithWildcardFilter(test_Select(_this))

TEST_EXPORT corto_void _test_Select_tc_selectUnderscore(test_Select _this);
#define test_Select_tc_selectUnderscore(_this) _test_Select_tc_selectUnderscore(test_Select(_this))

TEST_EXPORT corto_void _test_Select_teardown(test_Select _this);
#define test_Select_teardown(_this) _test_Select_teardown(test_Select(_this))

#ifdef __cplusplus
}
#endif
#endif

