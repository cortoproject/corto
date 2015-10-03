/* test_MethodResolver.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "test.h"

/* ::test::MethodResolver::tc_inheritOverload() */
cx_void _test_MethodResolver_tc_inheritOverload(test_MethodResolver this) {
/* $begin(::test::MethodResolver::tc_inheritOverload) */

    cx_method m = cx_interface_resolveMethod(test_MethodTesterInherit_o, "overload(string,string)");
    test_assert(m != NULL);
    test_assert(m == cx_method(test_MethodTesterInherit_overload_string_string_o));

/* $end */
}

/* ::test::MethodResolver::tc_inheritOverloadBaseClass() */
cx_void _test_MethodResolver_tc_inheritOverloadBaseClass(test_MethodResolver this) {
/* $begin(::test::MethodResolver::tc_inheritOverloadBaseClass) */

    cx_method m = cx_interface_resolveMethod(test_MethodTesterInherit_o, "overload(MethodTester)");
    test_assert(m != NULL);
    test_assert(m == cx_method(test_MethodTester_overload__test_MethodTester_o));

/* $end */
}

/* ::test::MethodResolver::tc_inheritOverloadBaseInt() */
cx_void _test_MethodResolver_tc_inheritOverloadBaseInt(test_MethodResolver this) {
/* $begin(::test::MethodResolver::tc_inheritOverloadBaseInt) */

    cx_method m = cx_interface_resolveMethod(test_MethodTesterInherit_o, "overload(int32)");
    test_assert(m != NULL);
    test_assert(m == cx_method(test_MethodTester_overload_int32_o));

/* $end */
}

/* ::test::MethodResolver::tc_inheritOverloadBaseString() */
cx_void _test_MethodResolver_tc_inheritOverloadBaseString(test_MethodResolver this) {
/* $begin(::test::MethodResolver::tc_inheritOverloadBaseString) */

    cx_method m = cx_interface_resolveMethod(test_MethodTesterInherit_o, "overload(string)");
    test_assert(m != NULL);
    test_assert(m == cx_method(test_MethodTester_overload_string_o));

/* $end */
}

/* ::test::MethodResolver::tc_inheritOverloadBaseTwoArgs() */
cx_void _test_MethodResolver_tc_inheritOverloadBaseTwoArgs(test_MethodResolver this) {
/* $begin(::test::MethodResolver::tc_inheritOverloadBaseTwoArgs) */

    cx_method m = cx_interface_resolveMethod(test_MethodTesterInherit_o, "overload(int32,int32)");
    test_assert(m != NULL);
    test_assert(m == cx_method(test_MethodTester_overload_int32_int32_o));

/* $end */
}

/* ::test::MethodResolver::tc_inheritOverloadClass() */
cx_void _test_MethodResolver_tc_inheritOverloadClass(test_MethodResolver this) {
/* $begin(::test::MethodResolver::tc_inheritOverloadClass) */

    cx_method m = cx_interface_resolveMethod(test_MethodTesterInherit_o, "overload(MethodTesterInherit)");
    test_assert(m != NULL);
    test_assert(m == cx_method(test_MethodTesterInherit_overload__test_MethodTesterInherit_o));

/* $end */
}

/* ::test::MethodResolver::tc_inheritOverloadNoArgs() */
cx_void _test_MethodResolver_tc_inheritOverloadNoArgs(test_MethodResolver this) {
/* $begin(::test::MethodResolver::tc_inheritOverloadNoArgs) */

    cx_method m = cx_interface_resolveMethod(test_MethodTesterInherit_o, "overload");
    test_assert(m == NULL);
    test_assert(cx_lasterr() != NULL);
    test_assert(!strcmp(cx_lasterr(), "ambiguous reference 'overload'"));

/* $end */
}

/* ::test::MethodResolver::tc_inheritSimple() */
cx_void _test_MethodResolver_tc_inheritSimple(test_MethodResolver this) {
/* $begin(::test::MethodResolver::tc_inheritSimple) */

    cx_method m = cx_interface_resolveMethod(test_MethodTesterInherit_o, "simple()");
    test_assert(m != NULL);
    test_assert(m == cx_method(test_MethodTesterInherit_simple_o));

/* $end */
}

/* ::test::MethodResolver::tc_inheritSimpleNoArgs() */
cx_void _test_MethodResolver_tc_inheritSimpleNoArgs(test_MethodResolver this) {
/* $begin(::test::MethodResolver::tc_inheritSimpleNoArgs) */

    cx_method m = cx_interface_resolveMethod(test_MethodTesterInherit_o, "simple");
    test_assert(m != NULL);
    test_assert(m == cx_method(test_MethodTesterInherit_simple_o));

/* $end */
}

/* ::test::MethodResolver::tc_inheritVirtualOverload() */
cx_void _test_MethodResolver_tc_inheritVirtualOverload(test_MethodResolver this) {
/* $begin(::test::MethodResolver::tc_inheritVirtualOverload) */

    cx_method m = cx_interface_resolveMethod(test_MethodTesterInherit_o, "virtualOverload(int32)");
    test_assert(m != NULL);
    test_assert(m == cx_method(test_MethodTesterInherit_virtualOverload_o));

/* $end */
}

/* ::test::MethodResolver::tc_inheritVirtualOverloadNoArgs() */
cx_void _test_MethodResolver_tc_inheritVirtualOverloadNoArgs(test_MethodResolver this) {
/* $begin(::test::MethodResolver::tc_inheritVirtualOverloadNoArgs) */

    cx_method m = cx_interface_resolveMethod(test_MethodTesterInherit_o, "virtualOverload");
    test_assert(m == NULL);
    test_assert(cx_lasterr() != NULL);
    test_assert(!strcmp(cx_lasterr(), "ambiguous reference 'virtualOverload'"));

/* $end */
}

/* ::test::MethodResolver::tc_nonexisting() */
cx_void _test_MethodResolver_tc_nonexisting(test_MethodResolver this) {
/* $begin(::test::MethodResolver::tc_nonexisting) */

    cx_method m = cx_interface_resolveMethod(test_MethodTesterInherit_o, "foo()");
    test_assert(m == NULL);

/* $end */
}

/* ::test::MethodResolver::tc_onearg() */
cx_void _test_MethodResolver_tc_onearg(test_MethodResolver this) {
/* $begin(::test::MethodResolver::tc_onearg) */

    cx_method m = cx_interface_resolveMethod(test_MethodTester_o, "onearg(int32)");
    test_assert(m != NULL);
    test_assert(m == cx_method(test_MethodTester_onearg_o));

/* $end */
}

/* ::test::MethodResolver::tc_oneargErr() */
cx_void _test_MethodResolver_tc_oneargErr(test_MethodResolver this) {
/* $begin(::test::MethodResolver::tc_oneargErr) */

    cx_method m = cx_interface_resolveMethod(test_MethodTester_o, "onearg(string)");
    test_assert(m == NULL);

/* $end */
}

/* ::test::MethodResolver::tc_oneargErrType() */
cx_void _test_MethodResolver_tc_oneargErrType(test_MethodResolver this) {
/* $begin(::test::MethodResolver::tc_oneargErrType) */

    cx_method m = cx_interface_resolveMethod(test_MethodTester_o, "onearg(footype)");
    test_assert(m == NULL);
    test_assert(cx_lasterr() != NULL);
    test_assert(!strcmp(cx_lasterr(), "unresolved type 'footype' in signature 'onearg(footype)'"));

/* $end */
}

/* ::test::MethodResolver::tc_oneargNoArgs() */
cx_void _test_MethodResolver_tc_oneargNoArgs(test_MethodResolver this) {
/* $begin(::test::MethodResolver::tc_oneargNoArgs) */

    cx_method m = cx_interface_resolveMethod(test_MethodTester_o, "onearg");
    test_assert(m != NULL);
    test_assert(m == cx_method(test_MethodTester_onearg_o));

/* $end */
}

/* ::test::MethodResolver::tc_overloadAmbiguous() */
cx_void _test_MethodResolver_tc_overloadAmbiguous(test_MethodResolver this) {
/* $begin(::test::MethodResolver::tc_overloadAmbiguous) */

    cx_method m = cx_interface_resolveMethod(test_MethodTester_o, "overload");
    test_assert(m == NULL);
    test_assert(cx_lasterr() != NULL);
    test_assert(!strcmp(cx_lasterr(), "ambiguous reference 'overload'"));

/* $end */
}

/* ::test::MethodResolver::tc_overloadClass() */
cx_void _test_MethodResolver_tc_overloadClass(test_MethodResolver this) {
/* $begin(::test::MethodResolver::tc_overloadClass) */

    cx_method m = cx_interface_resolveMethod(test_MethodTester_o, "overload(MethodTester)");
    test_assert(m != NULL);
    test_assert(m == cx_method(test_MethodTester_overload__test_MethodTester_o));

/* $end */
}

/* ::test::MethodResolver::tc_overloadInt() */
cx_void _test_MethodResolver_tc_overloadInt(test_MethodResolver this) {
/* $begin(::test::MethodResolver::tc_overloadInt) */

    cx_method m = cx_interface_resolveMethod(test_MethodTester_o, "overload(int32)");
    test_assert(m != NULL);
    test_assert(m == cx_method(test_MethodTester_overload_int32_o));

/* $end */
}

/* ::test::MethodResolver::tc_overloadString() */
cx_void _test_MethodResolver_tc_overloadString(test_MethodResolver this) {
/* $begin(::test::MethodResolver::tc_overloadString) */

    cx_method m = cx_interface_resolveMethod(test_MethodTester_o, "overload(string)");
    test_assert(m != NULL);
    test_assert(m == cx_method(test_MethodTester_overload_string_o));

/* $end */
}

/* ::test::MethodResolver::tc_overloadTwoArgs() */
cx_void _test_MethodResolver_tc_overloadTwoArgs(test_MethodResolver this) {
/* $begin(::test::MethodResolver::tc_overloadTwoArgs) */

    cx_method m = cx_interface_resolveMethod(test_MethodTester_o, "overload(int32,int32)");
    test_assert(m != NULL);
    test_assert(m == cx_method(test_MethodTester_overload_int32_int32_o));

/* $end */
}

/* ::test::MethodResolver::tc_simple() */
cx_void _test_MethodResolver_tc_simple(test_MethodResolver this) {
/* $begin(::test::MethodResolver::tc_simple) */

    cx_method m = cx_interface_resolveMethod(test_MethodTester_o, "simple()");
    test_assert(m != NULL);
    test_assert(m == test_MethodTester_simple_o);

/* $end */
}

/* ::test::MethodResolver::tc_simpleErr() */
cx_void _test_MethodResolver_tc_simpleErr(test_MethodResolver this) {
/* $begin(::test::MethodResolver::tc_simpleErr) */

    cx_method m = cx_interface_resolveMethod(test_MethodTester_o, "simple(int32)");
    test_assert(m == NULL);

/* $end */
}

/* ::test::MethodResolver::tc_simpleErrType() */
cx_void _test_MethodResolver_tc_simpleErrType(test_MethodResolver this) {
/* $begin(::test::MethodResolver::tc_simpleErrType) */

    cx_method m = cx_interface_resolveMethod(test_MethodTester_o, "simple(footype)");
    test_assert(m == NULL);

/* $end */
}

/* ::test::MethodResolver::tc_simpleNoArgs() */
cx_void _test_MethodResolver_tc_simpleNoArgs(test_MethodResolver this) {
/* $begin(::test::MethodResolver::tc_simpleNoArgs) */

    cx_method m = cx_interface_resolveMethod(test_MethodTester_o, "simple");
    test_assert(m != NULL);
    test_assert(m == test_MethodTester_simple_o);

/* $end */
}

/* ::test::MethodResolver::tc_twoargs() */
cx_void _test_MethodResolver_tc_twoargs(test_MethodResolver this) {
/* $begin(::test::MethodResolver::tc_twoargs) */

    cx_method m = cx_interface_resolveMethod(test_MethodTester_o, "twoargs(int32,int32)");
    test_assert(m != NULL);
    test_assert(m == test_MethodTester_twoargs_o);

/* $end */
}

/* ::test::MethodResolver::tc_twoargsNoArgs() */
cx_void _test_MethodResolver_tc_twoargsNoArgs(test_MethodResolver this) {
/* $begin(::test::MethodResolver::tc_twoargsNoArgs) */

    cx_method m = cx_interface_resolveMethod(test_MethodTester_o, "twoargs");
    test_assert(m != NULL);
    test_assert(m == test_MethodTester_twoargs_o);

/* $end */
}

/* ::test::MethodResolver::tc_twoargsSpaces() */
cx_void _test_MethodResolver_tc_twoargsSpaces(test_MethodResolver this) {
/* $begin(::test::MethodResolver::tc_twoargsSpaces) */

    cx_method m = cx_interface_resolveMethod(test_MethodTester_o, "twoargs(int32, int32)");
    test_assert(m != NULL);
    test_assert(m == test_MethodTester_twoargs_o);

/* $end */
}

/* ::test::MethodResolver::tc_virtualOverload() */
cx_void _test_MethodResolver_tc_virtualOverload(test_MethodResolver this) {
/* $begin(::test::MethodResolver::tc_virtualOverload) */

    cx_method m = cx_interface_resolveMethod(test_MethodTester_o, "virtualOverload()");
    test_assert(m != NULL);
    test_assert(m == cx_method(test_MethodTester_virtualOverload__o));

/* $end */
}

/* ::test::MethodResolver::tc_virtualOverloadArg() */
cx_void _test_MethodResolver_tc_virtualOverloadArg(test_MethodResolver this) {
/* $begin(::test::MethodResolver::tc_virtualOverloadArg) */

    cx_method m = cx_interface_resolveMethod(test_MethodTester_o, "virtualOverload(int32)");
    test_assert(m != NULL);
    test_assert(m == cx_method(test_MethodTester_virtualOverload_int32_o));

/* $end */
}

/* ::test::MethodResolver::tc_virtualOverloadNoArgs() */
cx_void _test_MethodResolver_tc_virtualOverloadNoArgs(test_MethodResolver this) {
/* $begin(::test::MethodResolver::tc_virtualOverloadNoArgs) */

    cx_method m = cx_interface_resolveMethod(test_MethodTester_o, "virtualOverload");
    test_assert(m == NULL);
    test_assert(cx_lasterr() != NULL);
    test_assert(!strcmp(cx_lasterr(), "ambiguous reference 'virtualOverload'"));

/* $end */
}

/* ::test::MethodResolver::tc_virtualSimple() */
cx_void _test_MethodResolver_tc_virtualSimple(test_MethodResolver this) {
/* $begin(::test::MethodResolver::tc_virtualSimple) */

    cx_method m = cx_interface_resolveMethod(test_MethodTester_o, "virtualSimple()");
    test_assert(m != NULL);
    test_assert(m == cx_method(test_MethodTester_virtualSimple_o));

/* $end */
}

/* ::test::MethodResolver::tc_virtualSimpleNoArgs() */
cx_void _test_MethodResolver_tc_virtualSimpleNoArgs(test_MethodResolver this) {
/* $begin(::test::MethodResolver::tc_virtualSimpleNoArgs) */

    cx_method m = cx_interface_resolveMethod(test_MethodTester_o, "virtualSimple");
    test_assert(m != NULL);
    test_assert(m == cx_method(test_MethodTester_virtualSimple_o));

/* $end */
}
