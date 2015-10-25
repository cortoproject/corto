/* $CORTO_GENERATED
 *
 * test_MethodResolver.c
 *
 * Code written between the begin and end tags will be preserved when the
 * file is regenerated.
 */

#include "test.h"

corto_void _test_MethodResolver_tc_inheritOverload(test_MethodResolver this) {
/* $begin(::test::MethodResolver::tc_inheritOverload) */

    corto_method m = corto_interface_resolveMethod(test_MethodTesterInherit_o, "overload(string,string)");
    test_assert(m != NULL);
    test_assert(m == corto_method(test_MethodTesterInherit_overload_string_string_o));

/* $end */
}

corto_void _test_MethodResolver_tc_inheritOverloadBaseClass(test_MethodResolver this) {
/* $begin(::test::MethodResolver::tc_inheritOverloadBaseClass) */

    corto_method m = corto_interface_resolveMethod(test_MethodTesterInherit_o, "overload(MethodTester)");
    test_assert(m != NULL);
    test_assert(m == corto_method(test_MethodTester_overload__test_MethodTester_o));

/* $end */
}

corto_void _test_MethodResolver_tc_inheritOverloadBaseInt(test_MethodResolver this) {
/* $begin(::test::MethodResolver::tc_inheritOverloadBaseInt) */

    corto_method m = corto_interface_resolveMethod(test_MethodTesterInherit_o, "overload(int32)");
    test_assert(m != NULL);
    test_assert(m == corto_method(test_MethodTester_overload_int32_o));

/* $end */
}

corto_void _test_MethodResolver_tc_inheritOverloadBaseString(test_MethodResolver this) {
/* $begin(::test::MethodResolver::tc_inheritOverloadBaseString) */

    corto_method m = corto_interface_resolveMethod(test_MethodTesterInherit_o, "overload(string)");
    test_assert(m != NULL);
    test_assert(m == corto_method(test_MethodTester_overload_string_o));

/* $end */
}

corto_void _test_MethodResolver_tc_inheritOverloadBaseTwoArgs(test_MethodResolver this) {
/* $begin(::test::MethodResolver::tc_inheritOverloadBaseTwoArgs) */

    corto_method m = corto_interface_resolveMethod(test_MethodTesterInherit_o, "overload(int32,int32)");
    test_assert(m != NULL);
    test_assert(m == corto_method(test_MethodTester_overload_int32_int32_o));

/* $end */
}

corto_void _test_MethodResolver_tc_inheritOverloadClass(test_MethodResolver this) {
/* $begin(::test::MethodResolver::tc_inheritOverloadClass) */

    corto_method m = corto_interface_resolveMethod(test_MethodTesterInherit_o, "overload(MethodTesterInherit)");
    test_assert(m != NULL);
    test_assert(m == corto_method(test_MethodTesterInherit_overload__test_MethodTesterInherit_o));

/* $end */
}

corto_void _test_MethodResolver_tc_inheritOverloadNoArgs(test_MethodResolver this) {
/* $begin(::test::MethodResolver::tc_inheritOverloadNoArgs) */

    corto_method m = corto_interface_resolveMethod(test_MethodTesterInherit_o, "overload");
    test_assert(m == NULL);
    test_assert(corto_lasterr() != NULL);
    test_assert(!strcmp(corto_lasterr(), "ambiguous reference 'overload'"));

/* $end */
}

corto_void _test_MethodResolver_tc_inheritSimple(test_MethodResolver this) {
/* $begin(::test::MethodResolver::tc_inheritSimple) */

    corto_method m = corto_interface_resolveMethod(test_MethodTesterInherit_o, "simple()");
    test_assert(m != NULL);
    test_assert(m == corto_method(test_MethodTesterInherit_simple_o));

/* $end */
}

corto_void _test_MethodResolver_tc_inheritSimpleNoArgs(test_MethodResolver this) {
/* $begin(::test::MethodResolver::tc_inheritSimpleNoArgs) */

    corto_method m = corto_interface_resolveMethod(test_MethodTesterInherit_o, "simple");
    test_assert(m != NULL);
    test_assert(m == corto_method(test_MethodTesterInherit_simple_o));

/* $end */
}

corto_void _test_MethodResolver_tc_inheritVirtualOverload(test_MethodResolver this) {
/* $begin(::test::MethodResolver::tc_inheritVirtualOverload) */

    corto_method m = corto_interface_resolveMethod(test_MethodTesterInherit_o, "virtualOverload(int32)");
    test_assert(m != NULL);
    test_assert(m == corto_method(test_MethodTesterInherit_virtualOverload_o));

/* $end */
}

corto_void _test_MethodResolver_tc_inheritVirtualOverloadNoArgs(test_MethodResolver this) {
/* $begin(::test::MethodResolver::tc_inheritVirtualOverloadNoArgs) */

    corto_method m = corto_interface_resolveMethod(test_MethodTesterInherit_o, "virtualOverload");
    test_assert(m == NULL);
    test_assert(corto_lasterr() != NULL);
    test_assert(!strcmp(corto_lasterr(), "ambiguous reference 'virtualOverload'"));

/* $end */
}

corto_void _test_MethodResolver_tc_nonexisting(test_MethodResolver this) {
/* $begin(::test::MethodResolver::tc_nonexisting) */

    corto_method m = corto_interface_resolveMethod(test_MethodTesterInherit_o, "foo()");
    test_assert(m == NULL);

/* $end */
}

corto_void _test_MethodResolver_tc_onearg(test_MethodResolver this) {
/* $begin(::test::MethodResolver::tc_onearg) */

    corto_method m = corto_interface_resolveMethod(test_MethodTester_o, "onearg(int32)");
    test_assert(m != NULL);
    test_assert(m == corto_method(test_MethodTester_onearg_o));

/* $end */
}

corto_void _test_MethodResolver_tc_oneargErr(test_MethodResolver this) {
/* $begin(::test::MethodResolver::tc_oneargErr) */

    corto_method m = corto_interface_resolveMethod(test_MethodTester_o, "onearg(string)");
    test_assert(m == NULL);

/* $end */
}

corto_void _test_MethodResolver_tc_oneargErrType(test_MethodResolver this) {
/* $begin(::test::MethodResolver::tc_oneargErrType) */

    corto_method m = corto_interface_resolveMethod(test_MethodTester_o, "onearg(footype)");
    test_assert(m == NULL);
    test_assert(corto_lasterr() != NULL);
    test_assert(!strcmp(corto_lasterr(), "unresolved type 'footype' in signature 'onearg(footype)'"));

/* $end */
}

corto_void _test_MethodResolver_tc_oneargNoArgs(test_MethodResolver this) {
/* $begin(::test::MethodResolver::tc_oneargNoArgs) */

    corto_method m = corto_interface_resolveMethod(test_MethodTester_o, "onearg");
    test_assert(m != NULL);
    test_assert(m == corto_method(test_MethodTester_onearg_o));

/* $end */
}

corto_void _test_MethodResolver_tc_overloadAmbiguous(test_MethodResolver this) {
/* $begin(::test::MethodResolver::tc_overloadAmbiguous) */

    corto_method m = corto_interface_resolveMethod(test_MethodTester_o, "overload");
    test_assert(m == NULL);
    test_assert(corto_lasterr() != NULL);
    test_assert(!strcmp(corto_lasterr(), "ambiguous reference 'overload'"));

/* $end */
}

corto_void _test_MethodResolver_tc_overloadClass(test_MethodResolver this) {
/* $begin(::test::MethodResolver::tc_overloadClass) */

    corto_method m = corto_interface_resolveMethod(test_MethodTester_o, "overload(MethodTester)");
    test_assert(m != NULL);
    test_assert(m == corto_method(test_MethodTester_overload__test_MethodTester_o));

/* $end */
}

corto_void _test_MethodResolver_tc_overloadInt(test_MethodResolver this) {
/* $begin(::test::MethodResolver::tc_overloadInt) */

    corto_method m = corto_interface_resolveMethod(test_MethodTester_o, "overload(int32)");
    test_assert(m != NULL);
    test_assert(m == corto_method(test_MethodTester_overload_int32_o));

/* $end */
}

corto_void _test_MethodResolver_tc_overloadString(test_MethodResolver this) {
/* $begin(::test::MethodResolver::tc_overloadString) */

    corto_method m = corto_interface_resolveMethod(test_MethodTester_o, "overload(string)");
    test_assert(m != NULL);
    test_assert(m == corto_method(test_MethodTester_overload_string_o));

/* $end */
}

corto_void _test_MethodResolver_tc_overloadTwoArgs(test_MethodResolver this) {
/* $begin(::test::MethodResolver::tc_overloadTwoArgs) */

    corto_method m = corto_interface_resolveMethod(test_MethodTester_o, "overload(int32,int32)");
    test_assert(m != NULL);
    test_assert(m == corto_method(test_MethodTester_overload_int32_int32_o));

/* $end */
}

corto_void _test_MethodResolver_tc_redeclare(test_MethodResolver this) {
/* $begin(::test::MethodResolver::tc_redeclare) */

    corto_struct s = corto_structDeclareChild(NULL, "TestStruct");
    test_assert(s != NULL);

    corto_object m = corto_methodDeclareChild(s, "bar()");
    test_assert(m != NULL);
    test_assert(corto_instanceof(corto_method_o, m));

    corto_object n = corto_methodDeclareChild(s, "bar()");
    test_assert(n != NULL);
    test_assert(corto_instanceof(corto_method_o, n));
    test_assert(m == n);

    corto_delete(m);
    corto_delete(n);
    corto_delete(s);

/* $end */
}

corto_void _test_MethodResolver_tc_simple(test_MethodResolver this) {
/* $begin(::test::MethodResolver::tc_simple) */

    corto_method m = corto_interface_resolveMethod(test_MethodTester_o, "simple()");
    test_assert(m != NULL);
    test_assert(m == test_MethodTester_simple_o);

/* $end */
}

corto_void _test_MethodResolver_tc_simpleErr(test_MethodResolver this) {
/* $begin(::test::MethodResolver::tc_simpleErr) */

    corto_method m = corto_interface_resolveMethod(test_MethodTester_o, "simple(int32)");
    test_assert(m == NULL);

/* $end */
}

corto_void _test_MethodResolver_tc_simpleErrType(test_MethodResolver this) {
/* $begin(::test::MethodResolver::tc_simpleErrType) */

    corto_method m = corto_interface_resolveMethod(test_MethodTester_o, "simple(footype)");
    test_assert(m == NULL);

/* $end */
}

corto_void _test_MethodResolver_tc_simpleNoArgs(test_MethodResolver this) {
/* $begin(::test::MethodResolver::tc_simpleNoArgs) */

    corto_method m = corto_interface_resolveMethod(test_MethodTester_o, "simple");
    test_assert(m != NULL);
    test_assert(m == test_MethodTester_simple_o);

/* $end */
}

corto_void _test_MethodResolver_tc_twoargs(test_MethodResolver this) {
/* $begin(::test::MethodResolver::tc_twoargs) */

    corto_method m = corto_interface_resolveMethod(test_MethodTester_o, "twoargs(int32,int32)");
    test_assert(m != NULL);
    test_assert(m == test_MethodTester_twoargs_o);

/* $end */
}

corto_void _test_MethodResolver_tc_twoargsNoArgs(test_MethodResolver this) {
/* $begin(::test::MethodResolver::tc_twoargsNoArgs) */

    corto_method m = corto_interface_resolveMethod(test_MethodTester_o, "twoargs");
    test_assert(m != NULL);
    test_assert(m == test_MethodTester_twoargs_o);

/* $end */
}

corto_void _test_MethodResolver_tc_twoargsSpaces(test_MethodResolver this) {
/* $begin(::test::MethodResolver::tc_twoargsSpaces) */

    corto_method m = corto_interface_resolveMethod(test_MethodTester_o, "twoargs(int32, int32)");
    test_assert(m != NULL);
    test_assert(m == test_MethodTester_twoargs_o);

/* $end */
}

corto_void _test_MethodResolver_tc_virtualOverload(test_MethodResolver this) {
/* $begin(::test::MethodResolver::tc_virtualOverload) */

    corto_method m = corto_interface_resolveMethod(test_MethodTester_o, "virtualOverload()");
    test_assert(m != NULL);
    test_assert(m == corto_method(test_MethodTester_virtualOverload__o));

/* $end */
}

corto_void _test_MethodResolver_tc_virtualOverloadArg(test_MethodResolver this) {
/* $begin(::test::MethodResolver::tc_virtualOverloadArg) */

    corto_method m = corto_interface_resolveMethod(test_MethodTester_o, "virtualOverload(int32)");
    test_assert(m != NULL);
    test_assert(m == corto_method(test_MethodTester_virtualOverload_int32_o));

/* $end */
}

corto_void _test_MethodResolver_tc_virtualOverloadNoArgs(test_MethodResolver this) {
/* $begin(::test::MethodResolver::tc_virtualOverloadNoArgs) */

    corto_method m = corto_interface_resolveMethod(test_MethodTester_o, "virtualOverload");
    test_assert(m == NULL);
    test_assert(corto_lasterr() != NULL);
    test_assert(!strcmp(corto_lasterr(), "ambiguous reference 'virtualOverload'"));

/* $end */
}

corto_void _test_MethodResolver_tc_virtualSimple(test_MethodResolver this) {
/* $begin(::test::MethodResolver::tc_virtualSimple) */

    corto_method m = corto_interface_resolveMethod(test_MethodTester_o, "virtualSimple()");
    test_assert(m != NULL);
    test_assert(m == corto_method(test_MethodTester_virtualSimple_o));

/* $end */
}

corto_void _test_MethodResolver_tc_virtualSimpleNoArgs(test_MethodResolver this) {
/* $begin(::test::MethodResolver::tc_virtualSimpleNoArgs) */

    corto_method m = corto_interface_resolveMethod(test_MethodTester_o, "virtualSimple");
    test_assert(m != NULL);
    test_assert(m == corto_method(test_MethodTester_virtualSimple_o));

/* $end */
}
