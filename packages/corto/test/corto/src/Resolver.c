/* $CORTO_GENERATED
 *
 * Resolver.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include "test.h"

corto_void _test_Resolver_setup(
    test_Resolver this)
{
/* $begin(test/Resolver/setup) */

    /* << Insert implementation >> */

/* $end */
}

corto_void _test_Resolver_tc_caseInsensitive(
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
    corto_seterr("failed to resolve %s", id);
    test_assert(r != NULL);
    test_assert(r == o);
    corto_release(r);

    corto_objectseq scope = corto_scopeClaim(o);
    corto_objectseqForeach(scope, child) {
        tc_resolveAllWalk(child, NULL);
    }
    corto_scopeRelease(scope);

    return 1;
}
/* $end */
corto_void _test_Resolver_tc_resolveAll(
    test_Resolver this)
{
/* $begin(test/Resolver/tc_resolveAll) */
    corto_objectseq scope = corto_scopeClaim(root_o);
    corto_objectseqForeach(scope, o) {
        tc_resolveAllWalk(o, NULL);
    }
    corto_scopeRelease(scope);
/* $end */
}

corto_void _test_Resolver_tc_resolveAnonymous(
    test_Resolver this)
{
/* $begin(test/Resolver/tc_resolveAnonymous) */

    corto_object o = corto_resolve(NULL, "string{\"Hello World\"}");
    test_assert(o != NULL);
    corto_release(o);

/* $end */
}

corto_void _test_Resolver_tc_resolveCorto(
    test_Resolver this)
{
/* $begin(test/Resolver/tc_resolveCorto) */

    corto_object o = corto_resolve(NULL, "corto");
    test_assert (o == corto_o);
    corto_release(o);

/* $end */
}

corto_void _test_Resolver_tc_resolveEmptyString(
    test_Resolver this)
{
/* $begin(test/Resolver/tc_resolveEmptyString) */

    corto_object o = corto_resolve(NULL, "");
    test_assert (o == NULL);
    if (o) corto_release(o);

/* $end */
}

corto_void _test_Resolver_tc_resolveFunctionArgs(
    test_Resolver this)
{
/* $begin(test/Resolver/tc_resolveFunctionArgs) */

    corto_object o = corto_resolve(NULL, "test/functionToResolve(int32,int32)");
    test_assert(o != NULL);
    test_assert(o == test_functionToResolve_o);

/* $end */
}

corto_void _test_Resolver_tc_resolveFunctionNoArgs(
    test_Resolver this)
{
/* $begin(test/Resolver/tc_resolveFunctionNoArgs) */

    corto_object o = corto_resolve(NULL, "test/functionToResolve");
    test_assert(o != NULL);
    test_assert(o == test_functionToResolve_o);

/* $end */
}

corto_void _test_Resolver_tc_resolveIo(
    test_Resolver this)
{
/* $begin(test/Resolver/tc_resolveIo) */

    /* Start loader replicator */
    corto_loader p = corto_loaderCreate();
    corto_object o = corto_resolve(NULL, "io");
    test_assert(o != NULL);
    test_assert (!strcmp(corto_nameof(o), "io"));
    test_assert (corto_parentof(o) == corto_o);
    corto_release(o);

    /* Delete loader replicator */
    corto_delete(p);

/* $end */
}

corto_void _test_Resolver_tc_resolveLang(
    test_Resolver this)
{
/* $begin(test/Resolver/tc_resolveLang) */

    corto_object o = corto_resolve(NULL, "lang");
    test_assert(o != NULL);
    test_assert (!strcmp(corto_nameof(o), "lang"));
    test_assert (o == corto_lang_o);
    corto_release(o);

/* $end */
}

corto_void _test_Resolver_tc_resolveNull(
    test_Resolver this)
{
/* $begin(test/Resolver/tc_resolveNull) */

    corto_object o = corto_resolve(NULL, NULL);
    test_assert (o == root_o);
    corto_release(o);

/* $end */
}

corto_void _test_Resolver_tc_resolveParenthesesNoFunction(
    test_Resolver this)
{
/* $begin(test/Resolver/tc_resolveParenthesesNoFunction) */

    corto_object o = corto_voidCreateChild(NULL, "o()");
    test_assert(o != NULL);
    test_assert(!strcmp(corto_nameof(o), "o()"));

    corto_object p = corto_resolve(NULL, "o()");
    test_assert(p != NULL);
    test_assert(o == p);

    corto_delete(o);
    corto_release(p);

/* $end */
}

corto_void _test_Resolver_tc_resolveParenthesesNoFunctionArgs(
    test_Resolver this)
{
/* $begin(test/Resolver/tc_resolveParenthesesNoFunctionArgs) */

    corto_object o = corto_voidCreateChild(NULL, "o(uint32 a)");
    test_assert(o != NULL);
    test_assert(!strcmp(corto_nameof(o), "o(uint32 a)"));

    corto_object p = corto_resolve(NULL, "o(uint32 a)");
    test_assert(p != NULL);
    test_assert(o == p);

    corto_delete(o);
    corto_release(p);

/* $end */
}

corto_void _test_Resolver_tc_resolveParenthesesNoFunctionArgsScoped(
    test_Resolver this)
{
/* $begin(test/Resolver/tc_resolveParenthesesNoFunctionArgsScoped) */
    corto_object parent = corto_voidCreateChild(NULL, "parent");
    test_assert(parent != NULL);

    corto_object o = corto_voidCreateChild(parent, "o(uint32 a)");
    test_assert(o != NULL);
    test_assert(!strcmp(corto_nameof(o), "o(uint32 a)"));
    test_assert(!strcmp(corto_fullpath(NULL, o), "/parent/o(uint32 a)"));

    corto_object p = corto_resolve(NULL, "/parent/o(uint32 a)");
    test_assert(p != NULL);
    test_assert(o == p);

    corto_delete(o);
    corto_delete(parent);
    corto_release(p);

/* $end */
}

corto_void _test_Resolver_tc_resolveParenthesesNoFunctionMatchingArgs(
    test_Resolver this)
{
/* $begin(test/Resolver/tc_resolveParenthesesNoFunctionMatchingArgs) */

    corto_object o = corto_voidCreateChild(NULL, "o(uint32 a)");
    test_assert(o != NULL);
    test_assert(!strcmp(corto_nameof(o), "o(uint32 a)"));

    corto_object p = corto_resolve(NULL, "o(uint16 a)");
    test_assert(p == NULL);

    corto_delete(o);

/* $end */
}

corto_void _test_Resolver_tc_resolveParenthesesNoFunctionMatchingArgsScoped(
    test_Resolver this)
{
/* $begin(test/Resolver/tc_resolveParenthesesNoFunctionMatchingArgsScoped) */
    corto_object parent = corto_voidCreateChild(NULL, "parent");
    test_assert(parent != NULL);

    corto_object o = corto_voidCreateChild(parent, "o(uint32 a)");
    test_assert(o != NULL);
    test_assert(!strcmp(corto_nameof(o), "o(uint32 a)"));
    test_assert(!strcmp(corto_fullpath(NULL, o), "/parent/o(uint32 a)"));

    corto_object p = corto_resolve(NULL, "/parent/o(uint16 a)");
    test_assert(p == NULL);

    corto_delete(o);
    corto_delete(parent);

/* $end */
}

corto_void _test_Resolver_tc_resolveParenthesesNoFunctionScoped(
    test_Resolver this)
{
/* $begin(test/Resolver/tc_resolveParenthesesNoFunctionScoped) */
    corto_id id;

    corto_object parent = corto_voidCreateChild(NULL, "parent");
    test_assert(parent != NULL);

    corto_object o = corto_voidCreateChild(parent, "o()");
    test_assert(o != NULL);
    test_assert(!strcmp(corto_nameof(o), "o()"));
    test_assert(!strcmp(corto_fullpath(id, o), "/parent/o()"));

    corto_object p = corto_resolve(NULL, "/parent/o()");
    test_assert(p != NULL);
    test_assert(p == o);

    corto_delete(o);
    corto_delete(parent);
    corto_release(p);

/* $end */
}

corto_void _test_Resolver_tc_resolveRoot(
    test_Resolver this)
{
/* $begin(test/Resolver/tc_resolveRoot) */

    corto_object o = corto_resolve(NULL, "/");
    test_assert (o == root_o);
    corto_release(o);

/* $end */
}

corto_void _test_Resolver_tc_resolveString(
    test_Resolver this)
{
/* $begin(test/Resolver/tc_resolveString) */

    corto_object o = corto_resolve(NULL, "string");
    test_assert (o == corto_string_o);
    corto_release(o);

/* $end */
}

corto_void _test_Resolver_tc_resolveThis(
    test_Resolver this)
{
/* $begin(test/Resolver/tc_resolveThis) */

    corto_object o = corto_resolve(corto_lang_o, ".");
    test_assert(o == corto_lang_o);
    corto_release(o);

/* $end */
}

corto_void _test_Resolver_teardown(
    test_Resolver this)
{
/* $begin(test/Resolver/teardown) */

    /* << Insert implementation >> */

/* $end */
}
