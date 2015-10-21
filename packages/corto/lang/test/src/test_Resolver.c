/* test_Resolver.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "test.h"

/* ::test::Resolver::setup() */
cx_void _test_Resolver_setup(test_Resolver this) {
/* $begin(::test::Resolver::setup) */

    /* << Insert implementation >> */

/* $end */
}

/* ::test::Resolver::tc_caseInsensitive() */
cx_void _test_Resolver_tc_caseInsensitive(test_Resolver this) {
/* $begin(::test::Resolver::tc_caseInsensitive) */

    cx_object o = cx_resolve(NULL, "COrTO");
    test_assert(o != NULL);
    test_assert(o == corto_o);
    cx_release(o);

/* $end */
}

/* ::test::Resolver::tc_resolveAll() */
/* $header(::test::Resolver::tc_resolveAll) */
int tc_resolveAllWalk(cx_object o, void *udata) {
    CX_UNUSED(udata);
    cx_id id;
    cx_object r;

    cx_fullname(o, id);
    r = cx_resolve(NULL, id);

    /* Set errormessage to ease debugging */
    cx_seterr("failed to resolve %s", id);
    test_assert(r != NULL);
    test_assert(r == o);
    cx_release(r);

    cx_scopeWalk(o, tc_resolveAllWalk, NULL);

    return 1;
}
/* $end */
cx_void _test_Resolver_tc_resolveAll(test_Resolver this) {
/* $begin(::test::Resolver::tc_resolveAll) */

    cx_scopeWalk(root_o, tc_resolveAllWalk, NULL);

/* $end */
}

/* ::test::Resolver::tc_resolveAnonymous() */
cx_void _test_Resolver_tc_resolveAnonymous(test_Resolver this) {
/* $begin(::test::Resolver::tc_resolveAnonymous) */

    cx_object o = cx_resolve(NULL, "string{\"Hello World\"}");
    test_assert(o != NULL);
    cx_release(o);

/* $end */
}

/* ::test::Resolver::tc_resolveCorto() */
cx_void _test_Resolver_tc_resolveCorto(test_Resolver this) {
/* $begin(::test::Resolver::tc_resolveCorto) */

    cx_object o = cx_resolve(NULL, "corto");
    test_assert (o == corto_o);
    cx_release(o);

/* $end */
}

/* ::test::Resolver::tc_resolveEmptyString() */
cx_void _test_Resolver_tc_resolveEmptyString(test_Resolver this) {
/* $begin(::test::Resolver::tc_resolveEmptyString) */

    cx_object o = cx_resolve(NULL, "");
    test_assert (o == NULL);
    if (o) cx_release(o);

/* $end */
}

/* ::test::Resolver::tc_resolveFunctionArgs() */
cx_void _test_Resolver_tc_resolveFunctionArgs(test_Resolver this) {
/* $begin(::test::Resolver::tc_resolveFunctionArgs) */

    cx_object o = cx_resolve(NULL, "test::functionToResolve(int32,int32)");
    test_assert(o != NULL);
    test_assert(o == test_functionToResolve_o);

/* $end */
}

/* ::test::Resolver::tc_resolveFunctionNoArgs() */
cx_void _test_Resolver_tc_resolveFunctionNoArgs(test_Resolver this) {
/* $begin(::test::Resolver::tc_resolveFunctionNoArgs) */

    cx_object o = cx_resolve(NULL, "test::functionToResolve");
    test_assert(o != NULL);
    test_assert(o == test_functionToResolve_o);

/* $end */
}

/* ::test::Resolver::tc_resolveIo() */
cx_void _test_Resolver_tc_resolveIo(test_Resolver this) {
/* $begin(::test::Resolver::tc_resolveIo) */

    cx_object o = cx_resolve(NULL, "io");
    test_assert(o != NULL);
    test_assert (!strcmp(cx_nameof(o), "io"));
    test_assert (cx_parentof(o) == corto_o);
    cx_release(o);

/* $end */
}

/* ::test::Resolver::tc_resolveLang() */
cx_void _test_Resolver_tc_resolveLang(test_Resolver this) {
/* $begin(::test::Resolver::tc_resolveLang) */

    cx_object o = cx_resolve(NULL, "lang");
    test_assert(o != NULL);    
    test_assert (!strcmp(cx_nameof(o), "lang"));
    test_assert (o == corto_lang_o);
    cx_release(o);

/* $end */
}

/* ::test::Resolver::tc_resolveNull() */
cx_void _test_Resolver_tc_resolveNull(test_Resolver this) {
/* $begin(::test::Resolver::tc_resolveNull) */

    cx_object o = cx_resolve(NULL, NULL);
    test_assert (o == root_o);
    cx_release(o);

/* $end */
}

/* ::test::Resolver::tc_resolveParenthesesNoFunction() */
cx_void _test_Resolver_tc_resolveParenthesesNoFunction(test_Resolver this) {
/* $begin(::test::Resolver::tc_resolveParenthesesNoFunction) */

    cx_object o = cx_voidCreateChild(NULL, "o()");
    test_assert(o != NULL);
    test_assert(!strcmp(cx_nameof(o), "o()"));

    cx_object p = cx_resolve(NULL, "o()");
    test_assert(p != NULL);
    test_assert(o == p);

    cx_delete(o);
    cx_release(p);

/* $end */
}

/* ::test::Resolver::tc_resolveParenthesesNoFunctionArgs() */
cx_void _test_Resolver_tc_resolveParenthesesNoFunctionArgs(test_Resolver this) {
/* $begin(::test::Resolver::tc_resolveParenthesesNoFunctionArgs) */

    cx_object o = cx_voidCreateChild(NULL, "o(uint32 a)");
    test_assert(o != NULL);
    test_assert(!strcmp(cx_nameof(o), "o(uint32 a)"));

    cx_object p = cx_resolve(NULL, "o(uint32 a)");
    test_assert(p != NULL);
    test_assert(o == p);

    cx_delete(o);
    cx_release(p);

/* $end */
}

/* ::test::Resolver::tc_resolveParenthesesNoFunctionArgsScoped() */
cx_void _test_Resolver_tc_resolveParenthesesNoFunctionArgsScoped(test_Resolver this) {
/* $begin(::test::Resolver::tc_resolveParenthesesNoFunctionArgsScoped) */
    cx_id id;

    cx_object parent = cx_voidCreateChild(NULL, "parent");
    test_assert(parent != NULL);

    cx_object o = cx_voidCreateChild(parent, "o(uint32 a)");
    test_assert(o != NULL);
    test_assert(!strcmp(cx_nameof(o), "o(uint32 a)"));
    test_assert(!strcmp(cx_fullname(o, id), "::parent::o(uint32 a)"));

    cx_object p = cx_resolve(NULL, "::parent::o(uint32 a)");
    test_assert(p != NULL);
    test_assert(o == p);

    cx_delete(o);
    cx_delete(parent);
    cx_release(p);

/* $end */
}

/* ::test::Resolver::tc_resolveParenthesesNoFunctionMatchingArgs() */
cx_void _test_Resolver_tc_resolveParenthesesNoFunctionMatchingArgs(test_Resolver this) {
/* $begin(::test::Resolver::tc_resolveParenthesesNoFunctionMatchingArgs) */

    cx_object o = cx_voidCreateChild(NULL, "o(uint32 a)");
    test_assert(o != NULL);
    test_assert(!strcmp(cx_nameof(o), "o(uint32 a)"));

    cx_object p = cx_resolve(NULL, "o(uint16 a)");
    test_assert(p == NULL);

    cx_delete(o);

/* $end */
}

/* ::test::Resolver::tc_resolveParenthesesNoFunctionMatchingArgsScoped() */
cx_void _test_Resolver_tc_resolveParenthesesNoFunctionMatchingArgsScoped(test_Resolver this) {
/* $begin(::test::Resolver::tc_resolveParenthesesNoFunctionMatchingArgsScoped) */
    cx_id id;

    cx_object parent = cx_voidCreateChild(NULL, "parent");
    test_assert(parent != NULL);

    cx_object o = cx_voidCreateChild(parent, "o(uint32 a)");
    test_assert(o != NULL);
    test_assert(!strcmp(cx_nameof(o), "o(uint32 a)"));
    test_assert(!strcmp(cx_fullname(o, id), "::parent::o(uint32 a)"));

    cx_object p = cx_resolve(NULL, "::parent::o(uint16 a)");
    test_assert(p == NULL);

    cx_delete(o);
    cx_delete(parent);

/* $end */
}

/* ::test::Resolver::tc_resolveParenthesesNoFunctionScoped() */
cx_void _test_Resolver_tc_resolveParenthesesNoFunctionScoped(test_Resolver this) {
/* $begin(::test::Resolver::tc_resolveParenthesesNoFunctionScoped) */
    cx_id id;

    cx_object parent = cx_voidCreateChild(NULL, "parent");
    test_assert(parent != NULL);

    cx_object o = cx_voidCreateChild(parent, "o()");
    test_assert(o != NULL);
    test_assert(!strcmp(cx_nameof(o), "o()"));
    test_assert(!strcmp(cx_fullname(o, id), "::parent::o()"));

    cx_object p = cx_resolve(NULL, "::parent::o()");
    test_assert(p != NULL);
    test_assert(p == o);

    cx_delete(o);
    cx_delete(parent);
    cx_release(p);

/* $end */
}

/* ::test::Resolver::tc_resolveRoot() */
cx_void _test_Resolver_tc_resolveRoot(test_Resolver this) {
/* $begin(::test::Resolver::tc_resolveRoot) */

    cx_object o = cx_resolve(NULL, "::");
    test_assert (o == root_o);
    cx_release(o);

/* $end */
}

/* ::test::Resolver::tc_resolveString() */
cx_void _test_Resolver_tc_resolveString(test_Resolver this) {
/* $begin(::test::Resolver::tc_resolveString) */

    cx_object o = cx_resolve(NULL, "string");
    test_assert (o == cx_string_o);
    cx_release(o);

/* $end */
}

/* ::test::Resolver::tc_resolveThis() */
cx_void _test_Resolver_tc_resolveThis(test_Resolver this) {
/* $begin(::test::Resolver::tc_resolveThis) */

    cx_object o = cx_resolve(corto_lang_o, ".");
    test_assert(o == corto_lang_o);
    cx_release(o);

/* $end */
}

/* ::test::Resolver::teardown() */
cx_void _test_Resolver_teardown(test_Resolver this) {
/* $begin(::test::Resolver::teardown) */

    /* << Insert implementation >> */

/* $end */
}
