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
