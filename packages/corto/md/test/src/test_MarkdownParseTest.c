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

/* ::test::MarkdownParseTest::testPackageAndClass() */
cx_void _test_MarkdownParseTest_testPackageAndClass(test_MarkdownParseTest this) {
/* $begin(::test::MarkdownParseTest::testPackageAndClass) */
    char text[] =
        "# test::Package0\n\n"
        "## Class0\n"
        ;
    md_parse(test_docs_o, text);
    cx_object o;
    test_assert((o = cx_resolve(test_docs_o, "::test::Package0")) != NULL);
    cx_release(o);
/* $end */
}

/* ::test::MarkdownParseTest::testPackageOnRoot() */
cx_void _test_MarkdownParseTest_testPackageOnRoot(test_MarkdownParseTest this) {
/* $begin(::test::MarkdownParseTest::testPackageOnRoot) */
    /* TODO Cannot test on root because the doc is named ::test just like this ::test package */
    // char text[] =
    //     "# test::Package0\n"
    //     "This package is very cool\n"
    //     ;
    // md_parse(NULL, text);
    // cx_object o = cx_resolve(root_o, "::test::Package0");
    // test_assert(o != NULL);
    // cx_release(o);
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
    cx_release(o);

    cx_object p;
    test_assert((p = cx_resolve(test_docs_o, "test::Package1::Package11")) != NULL);
    cx_release(p);

    cx_object q;
    test_assert((q = cx_resolve(test_docs_o, "test::Package1::Package11::Package111")) != NULL);
    cx_release(q);

/* $end */
}
