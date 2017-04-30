/* $CORTO_GENERATED
 *
 * Resolver.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <include/test.h>

void _test_Resolver_setup(
    test_Resolver this)
{
/* $begin(test/Resolver/setup) */

/* $end */
}

void _test_Resolver_tc_caseInsensitive(
    test_Resolver this)
{
/* $begin(test/Resolver/tc_caseInsensitive) */

    corto_object o = corto_resolve(NULL, "COrTO");
    test_assert(o != NULL);
    test_assert(o == corto_o);
    corto_release(o);

/* $end */
}

/* $header(test/Resolver/tc_resolveAll) */
int tc_resolveAllWalk(corto_object o, void *udata) {
    CORTO_UNUSED(udata);
    corto_id id;
    corto_object r;

    corto_fullpath(id, o);
    r = corto_resolve(NULL, id);

    /* Set errormessage to ease debugging */
    if (!r) corto_seterr("failed to resolve %s", id);
    test_assert(r != NULL);
    if (r != o) {
        corto_seterr("got %s, expected %s",
          corto_fullpath(NULL, r),
          corto_fullpath(NULL, o));
    }
    test_assert(r == o);
    corto_release(r);

    corto_objectseq scope = corto_scopeClaim(o);
    int i;
    for (i = 0; i < scope.length; i ++) {
        tc_resolveAllWalk(scope.buffer[i], NULL);
    }
    corto_scopeRelease(scope);

    return 1;
}
/* $end */
void _test_Resolver_tc_resolveAll(
    test_Resolver this)
{
/* $begin(test/Resolver/tc_resolveAll) */
    corto_objectseq scope = corto_scopeClaim(root_o);
    int i;
    for (i = 0; i < scope.length; i ++) {
        tc_resolveAllWalk(scope.buffer[i], NULL);
    }
    corto_scopeRelease(scope);
/* $end */
}

void _test_Resolver_tc_resolveAnonymous(
    test_Resolver this)
{
/* $begin(test/Resolver/tc_resolveAnonymous) */

    corto_object o = corto_resolve(NULL, "string{\"Hello World\"}");
    test_assert(o != NULL);

    corto_type t = corto_typeof(o);
    test_assert(t->kind == CORTO_PRIMITIVE);
    test_assert(corto_primitive(t)->kind == CORTO_TEXT);

    corto_string s = *(corto_string*)o;
    test_assertstr(s, "Hello World");

    corto_release(o);

/* $end */
}

void _test_Resolver_tc_resolveAnonymousAnonymousType(
    test_Resolver this)
{
/* $begin(test/Resolver/tc_resolveAnonymousAnonymousType) */

    corto_object o = corto_resolve(NULL, "list{int32}{1, 2, 3}");
    test_assert(o != NULL);

    corto_type t = corto_typeof(o);
    test_assert(t->kind == CORTO_COLLECTION);
    test_assert(corto_collection(t)->kind == CORTO_LIST);
    test_assert(corto_collection(t)->elementType == corto_type(corto_int32_o));

    corto_ll l = *(corto_ll*)o;
    test_assert(corto_llSize(l) == 3);
    test_assertint((corto_int32)(corto_word)corto_llGet(l, 0), 1);
    test_assertint((corto_int32)(corto_word)corto_llGet(l, 1), 2);
    test_assertint((corto_int32)(corto_word)corto_llGet(l, 2), 3);

    corto_release(o);

/* $end */
}

void _test_Resolver_tc_resolveCorto(
    test_Resolver this)
{
/* $begin(test/Resolver/tc_resolveCorto) */

    corto_object o = corto_resolve(NULL, "corto");
    test_assert (o == corto_o);
    corto_release(o);

/* $end */
}

void _test_Resolver_tc_resolveEmptyString(
    test_Resolver this)
{
/* $begin(test/Resolver/tc_resolveEmptyString) */

    corto_object o = corto_resolve(NULL, "");
    test_assert (o == NULL);
    if (o) corto_release(o);

/* $end */
}

void _test_Resolver_tc_resolveFunctionArgs(
    test_Resolver this)
{
/* $begin(test/Resolver/tc_resolveFunctionArgs) */

    corto_object o = corto_resolve(NULL, "test/functionToResolve(int32,int32)");
    test_assert(o != NULL);
    test_assert(o == test_functionToResolve_o);

/* $end */
}

void _test_Resolver_tc_resolveFunctionNoArgs(
    test_Resolver this)
{
/* $begin(test/Resolver/tc_resolveFunctionNoArgs) */

    corto_object o = corto_resolve(NULL, "test/functionToResolve");
    test_assert(o != NULL);
    test_assert(o == test_functionToResolve_o);

/* $end */
}

void _test_Resolver_tc_resolveG(
    test_Resolver this)
{
/* $begin(test/Resolver/tc_resolveG) */

    /* Start loader mount */
    corto_loader p = corto_loaderCreate(FALSE);
    corto_object o = corto_resolve(NULL, "g");
    test_assert(o != NULL);
    test_assert (!strcmp(corto_idof(o), "g"));
    test_assert (corto_parentof(o) == corto_o);
    corto_release(o);

    /* Delete loader mount */
    corto_delete(p);

/* $end */
}

void _test_Resolver_tc_resolveIdFromNull(
    test_Resolver this)
{
/* $begin(test/Resolver/tc_resolveIdFromNull) */

    corto_object o = corto_resolve(NULL, "corto");
    test_assert(o != NULL);
    test_assert(o == corto_o);

/* $end */
}

void _test_Resolver_tc_resolveIdFromRoot(
    test_Resolver this)
{
/* $begin(test/Resolver/tc_resolveIdFromRoot) */

    corto_object o = corto_resolve(root_o, "corto");
    test_assert(o != NULL);
    test_assert(o == corto_o);

/* $end */
}

void _test_Resolver_tc_resolveIdFromScope(
    test_Resolver this)
{
/* $begin(test/Resolver/tc_resolveIdFromScope) */

    corto_object o = corto_resolve(corto_core_o, "mount");
    test_assert(o != NULL);
    test_assert(o != corto_word_o);

/* $end */
}

void _test_Resolver_tc_resolveLang(
    test_Resolver this)
{
/* $begin(test/Resolver/tc_resolveLang) */

    corto_object o = corto_resolve(NULL, "lang");
    test_assert(o != NULL);
    test_assert (!strcmp(corto_idof(o), "lang"));
    test_assert (o == corto_lang_o);
    corto_release(o);

/* $end */
}

void _test_Resolver_tc_resolveNested2FromNull(
    test_Resolver this)
{
/* $begin(test/Resolver/tc_resolveNested2FromNull) */

    corto_object o = corto_resolve(NULL, "corto/core/mount");
    test_assert(o != NULL);
    test_assert(o == corto_mount_o);

/* $end */
}

void _test_Resolver_tc_resolveNested2FromRoot(
    test_Resolver this)
{
/* $begin(test/Resolver/tc_resolveNested2FromRoot) */

    corto_object o = corto_resolve(root_o, "corto/core/mount");
    test_assert(o != NULL);
    test_assert(o == corto_mount_o);

/* $end */
}

void _test_Resolver_tc_resolveNested2FromScope(
    test_Resolver this)
{
/* $begin(test/Resolver/tc_resolveNested2FromScope) */

    corto_object parent = corto_createChild(corto_o, "parent", corto_void_o);
    corto_object child = corto_createChild(parent, "child", corto_void_o);
    corto_object grandchild = corto_createChild(child, "grandchild", corto_void_o);

    corto_object o = corto_resolve(corto_o, "parent/child/grandchild");
    test_assert(o != NULL);
    test_assert(o == grandchild);

    corto_release(o);
    corto_delete(parent);

/* $end */
}

void _test_Resolver_tc_resolveNestedFromNull(
    test_Resolver this)
{
/* $begin(test/Resolver/tc_resolveNestedFromNull) */

    corto_object o = corto_resolve(NULL, "corto/core");
    test_assert(o != NULL);
    test_assert(o == corto_core_o);

/* $end */
}

void _test_Resolver_tc_resolveNestedFromRoot(
    test_Resolver this)
{
/* $begin(test/Resolver/tc_resolveNestedFromRoot) */

    corto_object o = corto_resolve(root_o, "corto/core");
    test_assert(o != NULL);
    test_assert(o == corto_core_o);

/* $end */
}

void _test_Resolver_tc_resolveNestedFromScope(
    test_Resolver this)
{
/* $begin(test/Resolver/tc_resolveNestedFromScope) */

    corto_object o = corto_resolve(corto_o, "core/mount");
    test_assert(o != NULL);
    test_assert(o == corto_mount_o);

/* $end */
}

void _test_Resolver_tc_resolveNull(
    test_Resolver this)
{
/* $begin(test/Resolver/tc_resolveNull) */

    corto_object o = corto_resolve(NULL, NULL);
    test_assert (o == NULL);

/* $end */
}

void _test_Resolver_tc_resolveObjectAFromScopeWithFunctionA(
    test_Resolver this)
{
/* $begin(test/Resolver/tc_resolveObjectAFromScopeWithFunctionA) */

    corto_object o = corto_resolve(corto_o, "/corto/lang/class/construct");
    test_assert(o != NULL);
    test_assertstr("/corto/lang/class/construct", corto_fullpath(NULL, o));

/* $end */
}

void _test_Resolver_tc_resolveParent(
    test_Resolver this)
{
/* $begin(test/Resolver/tc_resolveParent) */

    corto_object o = corto_resolve(corto_lang_o, "..");
    test_assert(o == corto_o);
    corto_release(o);

/* $end */
}

void _test_Resolver_tc_resolveParentAfterExpr(
    test_Resolver this)
{
/* $begin(test/Resolver/tc_resolveParentAfterExpr) */

    corto_object o = corto_resolve(corto_o, "lang/class/..");
    test_assert(o == corto_lang_o);
    corto_release(o);

/* $end */
}

void _test_Resolver_tc_resolveParentBeforeExpr(
    test_Resolver this)
{
/* $begin(test/Resolver/tc_resolveParentBeforeExpr) */

    corto_object o = corto_resolve(corto_class_o, "../method");
    test_assert(o == corto_method_o);
    corto_release(o);

/* $end */
}

void _test_Resolver_tc_resolveParenthesesNoFunction(
    test_Resolver this)
{
/* $begin(test/Resolver/tc_resolveParenthesesNoFunction) */

    corto_object o = corto_voidCreateChild(NULL, "o()");
    test_assert(o != NULL);
    test_assert(!strcmp(corto_idof(o), "o()"));

    corto_object p = corto_resolve(NULL, "o()");
    test_assert(p != NULL);
    test_assert(o == p);

    corto_delete(o);
    corto_release(p);

/* $end */
}

void _test_Resolver_tc_resolveParenthesesNoFunctionArgs(
    test_Resolver this)
{
/* $begin(test/Resolver/tc_resolveParenthesesNoFunctionArgs) */

    corto_object o = corto_voidCreateChild(NULL, "o(uint32 a)");
    test_assert(o != NULL);
    test_assert(!strcmp(corto_idof(o), "o(uint32 a)"));

    corto_object p = corto_resolve(NULL, "o(uint32 a)");
    test_assert(p != NULL);
    test_assert(o == p);

    corto_delete(o);
    corto_release(p);

/* $end */
}

void _test_Resolver_tc_resolveParenthesesNoFunctionArgsScoped(
    test_Resolver this)
{
/* $begin(test/Resolver/tc_resolveParenthesesNoFunctionArgsScoped) */
    corto_object parent = corto_voidCreateChild(NULL, "parent");
    test_assert(parent != NULL);

    corto_object o = corto_voidCreateChild(parent, "o(uint32 a)");
    test_assert(o != NULL);
    test_assert(!strcmp(corto_idof(o), "o(uint32 a)"));
    test_assert(!strcmp(corto_fullpath(NULL, o), "/parent/o(uint32 a)"));

    corto_object p = corto_resolve(NULL, "/parent/o(uint32 a)");
    test_assert(p != NULL);
    test_assert(o == p);

    corto_delete(o);
    corto_delete(parent);
    corto_release(p);

/* $end */
}

void _test_Resolver_tc_resolveParenthesesNoFunctionMatchingArgs(
    test_Resolver this)
{
/* $begin(test/Resolver/tc_resolveParenthesesNoFunctionMatchingArgs) */

    corto_object o = corto_voidCreateChild(NULL, "o(uint32 a)");
    test_assert(o != NULL);
    test_assert(!strcmp(corto_idof(o), "o(uint32 a)"));

    corto_object p = corto_resolve(NULL, "o(uint16 a)");
    test_assert(p == NULL);

    corto_delete(o);

/* $end */
}

void _test_Resolver_tc_resolveParenthesesNoFunctionMatchingArgsScoped(
    test_Resolver this)
{
/* $begin(test/Resolver/tc_resolveParenthesesNoFunctionMatchingArgsScoped) */
    corto_object parent = corto_voidCreateChild(NULL, "parent");
    test_assert(parent != NULL);

    corto_object o = corto_voidCreateChild(parent, "o(uint32 a)");
    test_assert(o != NULL);
    test_assert(!strcmp(corto_idof(o), "o(uint32 a)"));
    test_assert(!strcmp(corto_fullpath(NULL, o), "/parent/o(uint32 a)"));

    corto_object p = corto_resolve(NULL, "/parent/o(uint16 a)");
    test_assert(p == NULL);

    corto_delete(o);
    corto_delete(parent);

/* $end */
}

void _test_Resolver_tc_resolveParenthesesNoFunctionScoped(
    test_Resolver this)
{
/* $begin(test/Resolver/tc_resolveParenthesesNoFunctionScoped) */
    corto_id id;

    corto_object parent = corto_voidCreateChild(NULL, "parent");
    test_assert(parent != NULL);

    corto_object o = corto_voidCreateChild(parent, "o()");
    test_assert(o != NULL);
    test_assert(!strcmp(corto_idof(o), "o()"));
    test_assert(!strcmp(corto_fullpath(id, o), "/parent/o()"));

    corto_object p = corto_resolve(NULL, "/parent/o()");
    test_assert(p != NULL);
    test_assert(p == o);

    corto_delete(o);
    corto_delete(parent);
    corto_release(p);

/* $end */
}

void _test_Resolver_tc_resolveParentInExpr(
    test_Resolver this)
{
/* $begin(test/Resolver/tc_resolveParentInExpr) */

    corto_object o = corto_resolve(corto_lang_o, "class/../method");
    test_assert(o == corto_method_o);
    corto_release(o);

/* $end */
}

void _test_Resolver_tc_resolveRoot(
    test_Resolver this)
{
/* $begin(test/Resolver/tc_resolveRoot) */

    corto_object o = corto_resolve(NULL, "/");
    test_assert (o == root_o);
    corto_release(o);

/* $end */
}

void _test_Resolver_tc_resolveString(
    test_Resolver this)
{
/* $begin(test/Resolver/tc_resolveString) */

    corto_object o = corto_resolve(NULL, "string");
    test_assert (o == corto_string_o);
    corto_release(o);

/* $end */
}

void _test_Resolver_tc_resolveThis(
    test_Resolver this)
{
/* $begin(test/Resolver/tc_resolveThis) */

    corto_object o = corto_resolve(corto_lang_o, ".");
    test_assert(o == corto_lang_o);
    corto_release(o);

/* $end */
}

void _test_Resolver_tc_resolveThisAfterExpr(
    test_Resolver this)
{
/* $begin(test/Resolver/tc_resolveThisAfterExpr) */

    corto_object o = corto_resolve(NULL, "corto/core/.");
    test_assert(o == corto_core_o);
    corto_release(o);

/* $end */
}

void _test_Resolver_tc_resolveThisBeforeExpr(
    test_Resolver this)
{
/* $begin(test/Resolver/tc_resolveThisBeforeExpr) */

    corto_object o = corto_resolve(corto_core_o, "./mount");
    test_assert(o == corto_mount_o);
    corto_release(o);

/* $end */
}

void _test_Resolver_tc_resolveThisInExpr(
    test_Resolver this)
{
/* $begin(test/Resolver/tc_resolveThisInExpr) */

    corto_object o = corto_resolve(corto_o, "core/./mount");
    test_assert(o == corto_mount_o);
    corto_release(o);

/* $end */
}

void _test_Resolver_teardown(
    test_Resolver this)
{
/* $begin(test/Resolver/teardown) */

/* $end */
}
