/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

void test_MethodResolver_tc_inheritOverload(
    test_MethodResolver this)
{

    corto_method m = corto_interface_resolve_method(test_MethodTesterInherit_o, "overload(string,string)");
    test_assert(m != NULL);
    test_assert(m == corto_method(test_MethodTesterInherit_overload_string_string_o));

}

void test_MethodResolver_tc_inheritOverloadBaseClass(
    test_MethodResolver this)
{

    corto_method m = corto_interface_resolve_method(test_MethodTesterInherit_o, "overload(test/MethodTester)");
    test_assert(m != NULL);
    test_assert(m == corto_method(test_MethodTester_overload__test_MethodTester_o));

}

void test_MethodResolver_tc_inheritOverloadBaseInt(
    test_MethodResolver this)
{

    corto_method m = corto_interface_resolve_method(test_MethodTesterInherit_o, "overload(int32)");
    test_assert(m != NULL);
    test_assert(m == corto_method(test_MethodTester_overload_int32_o));

}

void test_MethodResolver_tc_inheritOverloadBaseString(
    test_MethodResolver this)
{

    corto_method m = corto_interface_resolve_method(test_MethodTesterInherit_o, "overload(string)");
    test_assert(m != NULL);
    test_assert(m == corto_method(test_MethodTester_overload_string_o));

}

void test_MethodResolver_tc_inheritOverloadBaseTwoArgs(
    test_MethodResolver this)
{

    corto_method m = corto_interface_resolve_method(test_MethodTesterInherit_o, "overload(int32,int32)");
    test_assert(m != NULL);
    test_assert(m == corto_method(test_MethodTester_overload_int32_int32_o));

}

void test_MethodResolver_tc_inheritOverloadClass(
    test_MethodResolver this)
{

    corto_method m = corto_interface_resolve_method(test_MethodTesterInherit_o, "overload(test/MethodTesterInherit)");
    test_assert(m != NULL);
    test_assert(m == corto_method(test_MethodTesterInherit_overload__test_MethodTesterInherit_o));

}

void test_MethodResolver_tc_inheritOverloadNoArgs(
    test_MethodResolver this)
{

    corto_method m = corto_interface_resolve_method(test_MethodTesterInherit_o, "overload");
    test_assert(m == NULL);
    test_assert(corto_catch());
}

void test_MethodResolver_tc_inheritSimple(
    test_MethodResolver this)
{

    corto_method m = corto_interface_resolve_method(test_MethodTesterInherit_o, "simple()");
    test_assert(m != NULL);
    test_assert(m == corto_method(test_MethodTesterInherit_simple_o));

}

void test_MethodResolver_tc_inheritSimpleNoArgs(
    test_MethodResolver this)
{

    corto_method m = corto_interface_resolve_method(test_MethodTesterInherit_o, "simple");
    test_assert(m != NULL);
    test_assert(m == corto_method(test_MethodTesterInherit_simple_o));

}

void test_MethodResolver_tc_inheritVirtualOverload(
    test_MethodResolver this)
{

    corto_method m = corto_interface_resolve_method(test_MethodTesterInherit_o, "virtualOverload(int32)");
    test_assert(m != NULL);
    test_assert(m == corto_method(test_MethodTesterInherit_virtualOverload_o));

}

void test_MethodResolver_tc_inheritVirtualOverloadNoArgs(
    test_MethodResolver this)
{

    corto_method m = corto_interface_resolve_method(test_MethodTesterInherit_o, "virtualOverload");
    test_assert(m == NULL);
    test_assert(corto_catch());
}

void test_MethodResolver_tc_nonexisting(
    test_MethodResolver this)
{

    corto_method m = corto_interface_resolve_method(test_MethodTesterInherit_o, "foo()");
    test_assert(m == NULL);
}

void test_MethodResolver_tc_onearg(
    test_MethodResolver this)
{

    corto_method m = corto_interface_resolve_method(test_MethodTester_o, "onearg(int32)");
    test_assert(m != NULL);
    test_assert(m == corto_method(test_MethodTester_onearg_o));

}

void test_MethodResolver_tc_oneargErr(
    test_MethodResolver this)
{

    corto_method m = corto_interface_resolve_method(test_MethodTester_o, "onearg(string)");
    test_assert(m == NULL);
}

void test_MethodResolver_tc_oneargErrType(
    test_MethodResolver this)
{

    corto_method m = corto_interface_resolve_method(test_MethodTester_o, "onearg(footype)");
    test_assert(m == NULL);
    test_assert(corto_catch());
}

void test_MethodResolver_tc_oneargNoArgs(
    test_MethodResolver this)
{

    corto_method m = corto_interface_resolve_method(test_MethodTester_o, "onearg");
    test_assert(m != NULL);
    test_assert(m == corto_method(test_MethodTester_onearg_o));

}

void test_MethodResolver_tc_overloadAmbiguous(
    test_MethodResolver this)
{

    corto_method m = corto_interface_resolve_method(test_MethodTester_o, "overload");
    test_assert(m == NULL);
    test_assert(corto_catch());
}

void test_MethodResolver_tc_overloadClass(
    test_MethodResolver this)
{

    corto_method m = corto_interface_resolve_method(test_MethodTester_o, "overload(test/MethodTester)");
    test_assert(m != NULL);
    test_assert(m == corto_method(test_MethodTester_overload__test_MethodTester_o));

}

void test_MethodResolver_tc_overloadInt(
    test_MethodResolver this)
{

    corto_method m = corto_interface_resolve_method(test_MethodTester_o, "overload(int32)");
    test_assert(m != NULL);
    test_assert(m == corto_method(test_MethodTester_overload_int32_o));

}

void test_MethodResolver_tc_overloadString(
    test_MethodResolver this)
{

    corto_method m = corto_interface_resolve_method(test_MethodTester_o, "overload(string)");
    test_assert(m != NULL);
    test_assert(m == corto_method(test_MethodTester_overload_string_o));

}

void test_MethodResolver_tc_overloadTwoArgs(
    test_MethodResolver this)
{

    corto_method m = corto_interface_resolve_method(test_MethodTester_o, "overload(int32,int32)");
    test_assert(m != NULL);
    test_assert(m == corto_method(test_MethodTester_overload_int32_int32_o));

}

void test_MethodResolver_tc_redeclare(
    test_MethodResolver this)
{

    corto_struct s = corto_declare(root_o, "TestStruct", corto_struct_o);
    test_assert(s != NULL);

    corto_object m = corto_declare(s, "bar()", corto_method_o);
    test_assert(m != NULL);
    test_assert(corto_instanceof(corto_method_o, m));

    corto_object n = corto_declare(s, "bar()", corto_method_o);
    test_assert(n != NULL);
    test_assert(corto_instanceof(corto_method_o, n));
    test_assert(m == n);

    corto_delete(m);
    corto_delete(n);
    corto_delete(s);

}

void test_MethodResolver_tc_simple(
    test_MethodResolver this)
{

    corto_method m = corto_interface_resolve_method(test_MethodTester_o, "simple()");
    test_assert(m != NULL);
    test_assert(m == test_MethodTester_simple_o);

}

void test_MethodResolver_tc_simpleErr(
    test_MethodResolver this)
{

    corto_method m = corto_interface_resolve_method(test_MethodTester_o, "simple(int32)");
    test_assert(m == NULL);
}

void test_MethodResolver_tc_simpleErrType(
    test_MethodResolver this)
{

    corto_method m = corto_interface_resolve_method(test_MethodTester_o, "simple(footype)");
    test_assert(m == NULL);
}

void test_MethodResolver_tc_simpleNoArgs(
    test_MethodResolver this)
{

    corto_method m = corto_interface_resolve_method(test_MethodTester_o, "simple");
    test_assert(m != NULL);
    test_assert(m == test_MethodTester_simple_o);

}

void test_MethodResolver_tc_twoargs(
    test_MethodResolver this)
{

    corto_method m = corto_interface_resolve_method(test_MethodTester_o, "twoargs(int32,int32)");
    test_assert(m != NULL);
    test_assert(m == test_MethodTester_twoargs_o);

}

void test_MethodResolver_tc_twoargsNoArgs(
    test_MethodResolver this)
{

    corto_method m = corto_interface_resolve_method(test_MethodTester_o, "twoargs");
    test_assert(m != NULL);
    test_assert(m == test_MethodTester_twoargs_o);

}

void test_MethodResolver_tc_twoargsSpaces(
    test_MethodResolver this)
{

    corto_method m = corto_interface_resolve_method(test_MethodTester_o, "twoargs(int32, int32)");
    test_assert(m != NULL);
    test_assert(m == test_MethodTester_twoargs_o);

}

void test_MethodResolver_tc_virtualOverload(
    test_MethodResolver this)
{

    corto_method m = corto_interface_resolve_method(test_MethodTester_o, "virtualOverload()");
    test_assert(m != NULL);
    test_assert(m == corto_method(test_MethodTester_virtualOverload__o));

}

void test_MethodResolver_tc_virtualOverloadArg(
    test_MethodResolver this)
{

    corto_method m = corto_interface_resolve_method(test_MethodTester_o, "virtualOverload(int32)");
    test_assert(m != NULL);
    test_assert(m == corto_method(test_MethodTester_virtualOverload_int32_o));

}

void test_MethodResolver_tc_virtualOverloadNoArgs(
    test_MethodResolver this)
{

    corto_method m = corto_interface_resolve_method(test_MethodTester_o, "virtualOverload");
    test_assert(m == NULL);
    test_assert(corto_catch());
}

void test_MethodResolver_tc_virtualSimple(
    test_MethodResolver this)
{

    corto_method m = corto_interface_resolve_method(test_MethodTester_o, "virtualSimple()");
    test_assert(m != NULL);
    test_assert(m == corto_method(test_MethodTester_virtualSimple_o));

}

void test_MethodResolver_tc_virtualSimpleNoArgs(
    test_MethodResolver this)
{

    corto_method m = corto_interface_resolve_method(test_MethodTester_o, "virtualSimple");
    test_assert(m != NULL);
    test_assert(m == corto_method(test_MethodTester_virtualSimple_o));

}
