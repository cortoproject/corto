/* test_MarkdownParseTest.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "test.h"

/* ::test::MarkdownParseTest::testSingleHeading() */
cx_void _test_MarkdownParseTest_testSingleHeading(test_MarkdownParseTest this) {
/* $begin(::test::MarkdownParseTest::testSingleHeading) */
    char text[] =
        "# FirstHeading\n"
        ;
    md_parse(test_docs_o, text);
    {
        cx_object o = cx_resolve(test_docs_o, "FirstHeading");
        test_assert(o != NULL);
        cx_release(o);
    }
/* $end */
}

/* ::test::MarkdownParseTest::testTwoHeadings() */
cx_void _test_MarkdownParseTest_testTwoHeadings(test_MarkdownParseTest this) {
/* $begin(::test::MarkdownParseTest::testTwoHeadings) */
    char text[] =
        "# FirstHeading\n"
        "## SecondHeading\n"
        ;
    md_parse(test_docs_o, text);
    {
        cx_object o = cx_resolve(test_docs_o, "FirstHeading");
        test_assert(o != NULL);
        cx_release(o);
    }
    {
        cx_object o = cx_resolve(test_docs_o, "FirstHeading::SecondHeading");
        test_assert(o != NULL);
        cx_release(o);
    }
/* $end */
}
