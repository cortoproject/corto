/* test_HeadersParagraphs.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "test.h"

/* ::test::HeadersParagraphs::tc_H1() */
cx_void _test_HeadersParagraphs_tc_H1(test_HeadersParagraphs this) {
/* $begin(::test::HeadersParagraphs::tc_H1) */
    char text[] =
        "# FirstHeading\n"
        "This is the first paragraph.\n"
        ;
    md_parse(test_docs_o, text);
    {
        cx_object o = cx_resolve(test_docs_o, "FirstHeading");
        test_assert(o != NULL);
        test_assert(cx_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(md_Doc(o)->text != NULL);
        test_assert(md_Doc(o)->level == 1);
        cx_release(o);
    }
/* $end */
}
