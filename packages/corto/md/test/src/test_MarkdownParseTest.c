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
    char TEXT[] =
        "# hello\n\n"
        "## Class0\n"
    ;
    md_parse(test_docs_o, TEXT);
    cx_object o = cx_lookup(test_docs_o, "Package0");
    // test_assert(o != NULL);
    cx_release(o);
/* $end */
}

/* ::test::MarkdownParseTest::testPackageOnRoot() */
cx_void _test_MarkdownParseTest_testPackageOnRoot(test_MarkdownParseTest this) {
/* $begin(::test::MarkdownParseTest::testPackageOnRoot) */
    CX_UNUSED(this);
/* $end */
}
