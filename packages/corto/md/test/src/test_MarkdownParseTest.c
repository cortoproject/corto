/* test_MarkdownParseTest.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "test.h"

/* $header() */

/* $end */

/* ::test::MarkdownParseTest::testNoRootDestination() */
cx_void _test_MarkdownParseTest_testNoRootDestination(test_MarkdownParseTest this) {
/* $begin(::test::MarkdownParseTest::testNoRootDestination) */
    char text[] =
        "# test::Package0\n\n"
        "## Class0\n"
        ;
    md_parse(NULL, text);
    /* TODO assert that nothing was created, or that error was submitted */
    cx_object o = cx_resolve(NULL, "test");
    test_assert(cx_instanceof(md_PackageDoc_o, o) == FALSE);
    test_assert(strcmp(cx_lasterr(), "must specify a destination different from root") == 0);
    cx_release(o);
/* $end */
}

/* ::test::MarkdownParseTest::testPackageAndClass() */
cx_void _test_MarkdownParseTest_testPackageAndClass(test_MarkdownParseTest this) {
/* $begin(::test::MarkdownParseTest::testPackageAndClass) */
    char text[] =
        "# test::Package0\n\n"
        "## Class0\n"
        ;
    md_parse(test_docs_o, text);
    md_PackageDoc o;
    test_assert((o = cx_resolve(test_docs_o, "test::Package0")) != NULL);
    test_assert(cx_instanceof(md_PackageDoc_o, o));
    test_assert(md_Doc(o)->o == test_Package0_o);
    cx_release(o);
    
    md_TypeDoc p;
    test_assert((p = cx_resolve(test_docs_o, "test::Package0::Class0")) != NULL);
    test_assert(cx_instanceof(md_TypeDoc_o, p));
    test_assert(md_Doc(p)->o == test_Package0_Class0_o);
    cx_release(o);
/* $end */
}

/* ::test::MarkdownParseTest::testPackageAndClassAndMethod() */
cx_void _test_MarkdownParseTest_testPackageAndClassAndMethod(test_MarkdownParseTest this) {
/* $begin(::test::MarkdownParseTest::testPackageAndClassAndMethod) */
    char text[] =
        "# test::Package1\n"
        "This is a package.\n\n"
        "## Class1\n"
        "This is a class.\n\n"
        "### method1\n"
        "This is a method\n\n"
        ;
    md_parse(test_docs_o, text);
    
    md_MethodDoc o;
    test_assert((o = cx_resolve(test_docs_o, "test::Package1::Class1::method1")) != NULL);
    test_assert(cx_instanceof(md_MethodDoc_o, o));
    test_assert(md_Doc(o)->o == test_Package1_Class1_method1_o);
    cx_release(o);
/* $end */
}

/* ::test::MarkdownParseTest::testScopedPackage() */
cx_void _test_MarkdownParseTest_testScopedPackage(test_MarkdownParseTest this) {
/* $begin(::test::MarkdownParseTest::testScopedPackage) */
    char text[] =
        "# test::Package1::Package11::Package111\n"
        "This package is very cool\n"
        ;
    md_parse(test_docs_o, text);

    cx_object o;
    test_assert((o = cx_resolve(test_docs_o, "test::Package1")) != NULL);
    test_assert(cx_typeof(o) == cx_type(md_PackageDoc_o));
    test_assert(md_Doc(o)->o == test_Package1_o);
    cx_release(o);

    cx_object p;
    test_assert((p = cx_resolve(test_docs_o, "test::Package1::Package11")) != NULL);
    test_assert(cx_typeof(p) == cx_type(md_PackageDoc_o));
    test_assert(md_Doc(p)->o == test_Package1_Package11_o);
    cx_release(p);

    cx_object q;
    test_assert((q = cx_resolve(test_docs_o, "test::Package1::Package11::Package111")) != NULL);
    test_assert(cx_typeof(q) == cx_type(md_PackageDoc_o));
    test_assert(md_Doc(q)->o == test_Package1_Package11_Package111_o);
    cx_release(q);

/* $end */
}
