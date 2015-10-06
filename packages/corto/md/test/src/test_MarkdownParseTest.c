/* test_MarkdownParseTest.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "test.h"

/* ::test::MarkdownParseTest::testSingleHeader() */
cx_void _test_MarkdownParseTest_testSingleHeader(test_MarkdownParseTest this) {
/* $begin(::test::MarkdownParseTest::testSingleHeader) */
    char text[] =
        "# FirstHeading"
        ;
    md_parse(test_docs_o, text);
    {
        cx_object o = cx_resolve(test_docs_o, "FirstHeading");
        test_assert(o != NULL);
        cx_release(o);
    }
/* $end */
}
