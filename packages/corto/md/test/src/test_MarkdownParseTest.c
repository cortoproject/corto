/* test_MarkdownParseTest.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#define test_LIB
#include "test.h"

/* ::test::MarkdownParseTest::testPackageAndClass() */
cx_void _test_MarkdownParseTest_testPackageAndClass(test_MarkdownParseTest this) {
/* $begin(::test::MarkdownParseTest::testPackageAndClass) */
    char text[] =
        "# ::Package0\n\n"
        "## Class0\n"
        ;
    md_parse(test_docs_o, text);
    cx_object o = cx_lookup(test_docs_o, "Package0");
    test_assert(o != NULL);
    cx_release(o);
/* $end */
}

/* ::test::MarkdownParseTest::testPackageOnRoot() */
cx_void _test_MarkdownParseTest_testPackageOnRoot(test_MarkdownParseTest this) {
/* $begin(::test::MarkdownParseTest::testPackageOnRoot) */
    char text[] =
        "# ::Package0\n"
        "This package is very cool\n"
        ;
    md_parse(NULL, text);
    cx_object o = cx_lookup(root_o, "Package0");
    test_assert(o != NULL);
    cx_release(o);
/* $end */
}

/* ::test::MarkdownParseTest::testScopedPackage() */
cx_void _test_MarkdownParseTest_testScopedPackage(test_MarkdownParseTest this) {
/* $begin(::test::MarkdownParseTest::testScopedPackage) */
    char text[] =
        "# ::Package1::Package11::Package111\n"
        "This package is very cool\n"
        ;
    md_parse(NULL, text);

    cx_object o = cx_lookup(root_o, "Package1");
    test_assert(o != NULL);
    cx_release(o);

    cx_object p = cx_lookup(root_o, "Package1::Package11");
    test_assert(p != NULL);
    cx_release(p);

    cx_object q = cx_lookup(root_o, "Package1::Package11::Package111");
    test_assert(q != NULL);
    cx_release(q);

/* $end */
}
