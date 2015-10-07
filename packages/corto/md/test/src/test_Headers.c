/* test_Headers.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "test.h"

/* ::test::Headers::tc_H1() */
cx_void _test_Headers_tc_H1(test_Headers this) {
/* $begin(::test::Headers::tc_H1) */
    char text[] =
        "# FirstHeading\n"
        ;
    md_parse(test_docs_o, text);
    {
        cx_object o = cx_resolve(test_docs_o, "FirstHeading");
        test_assert(o != NULL);
        test_assert(cx_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(md_Doc(o)->text == NULL);
        test_assert(md_Doc(o)->level == 1);
        cx_release(o);
    }
/* $end */
}

/* ::test::Headers::tc_H1H2() */
cx_void _test_Headers_tc_H1H2(test_Headers this) {
/* $begin(::test::Headers::tc_H1H2) */
    char text[] =
        "# FirstHeading\n"
        "## SecondHeading\n"
        ;
    md_parse(test_docs_o, text);
    {
        cx_object o = cx_resolve(test_docs_o, "FirstHeading");
        test_assert(o != NULL);
        test_assert(cx_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(md_Doc(o)->text == NULL);
        test_assert(md_Doc(o)->level == 1);
        cx_release(o);
    }
    {
        cx_object o = cx_resolve(test_docs_o, "FirstHeading::SecondHeading");
        test_assert(o != NULL);
        test_assert(cx_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(md_Doc(o)->text == NULL);
        test_assert(md_Doc(o)->level == 2);
        cx_release(o);
    }
/* $end */
}

/* ::test::Headers::tc_H1H2H1() */
cx_void _test_Headers_tc_H1H2H1(test_Headers this) {
/* $begin(::test::Headers::tc_H1H2H1) */

    char text[] =
        "# Heading1\n"
        "## Heading2\n"
        "# Heading3\n"
        ;
    md_parse(test_docs_o, text);
    {
        cx_object o = cx_resolve(test_docs_o, "Heading1");
        test_assert(o != NULL);
        test_assert(cx_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(md_Doc(o)->text == NULL);
        test_assert(md_Doc(o)->level == 1);
        cx_release(o);
    }
    {
        cx_object o = cx_resolve(test_docs_o, "Heading1::Heading2");
        test_assert(o != NULL);
        test_assert(cx_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(md_Doc(o)->text == NULL);
        test_assert(md_Doc(o)->level == 2);
        cx_release(o);
    }
    {
        cx_object o = cx_resolve(test_docs_o, "Heading3");
        test_assert(o != NULL);
        test_assert(cx_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(md_Doc(o)->text == NULL);
        test_assert(md_Doc(o)->level == 1);
        cx_release(o);
    }
/* $end */
}

/* ::test::Headers::tc_H1H2H1H2() */
cx_void _test_Headers_tc_H1H2H1H2(test_Headers this) {
/* $begin(::test::Headers::tc_H1H2H1H2) */

    char text[] =
        "# Heading1\n"
        "## Heading2\n"
        "# Heading3\n"
        "## Heading4\n"
        ;
    md_parse(test_docs_o, text);
    {
        cx_object o = cx_resolve(test_docs_o, "Heading1");
        test_assert(o != NULL);
        test_assert(cx_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(md_Doc(o)->text == NULL);
        test_assert(md_Doc(o)->level == 1);
        cx_release(o);
    }
    {
        cx_object o = cx_resolve(test_docs_o, "Heading1::Heading2");
        test_assert(o != NULL);
        test_assert(cx_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(md_Doc(o)->text == NULL);
        test_assert(md_Doc(o)->level == 2);
        cx_release(o);
    }
    {
        cx_object o = cx_resolve(test_docs_o, "Heading3");
        test_assert(o != NULL);
        test_assert(cx_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(md_Doc(o)->text == NULL);
        test_assert(md_Doc(o)->level == 1);
        cx_release(o);
    }
    {
        cx_object o = cx_resolve(test_docs_o, "Heading3::Heading4");
        test_assert(o != NULL);
        test_assert(cx_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(md_Doc(o)->text == NULL);
        test_assert(md_Doc(o)->level == 2);
        cx_release(o);
    }

/* $end */
}

/* ::test::Headers::tc_H1H2H3() */
cx_void _test_Headers_tc_H1H2H3(test_Headers this) {
/* $begin(::test::Headers::tc_H1H2H3) */
    char text[] =
        "# FirstHeading\n"
        "## SecondHeading\n"
        "### ThirdHeading\n"
        ;
    md_parse(test_docs_o, text);
    {
        cx_object o = cx_resolve(test_docs_o, "FirstHeading");
        test_assert(o != NULL);
        test_assert(cx_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(md_Doc(o)->text == NULL);
        test_assert(md_Doc(o)->level == 1);
        cx_release(o);
    }
    {
        cx_object o = cx_resolve(test_docs_o, "FirstHeading::SecondHeading");
        test_assert(o != NULL);
        test_assert(cx_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(md_Doc(o)->text == NULL);
        test_assert(md_Doc(o)->level == 2);
        cx_release(o);
    }
    {
        cx_object o = cx_resolve(test_docs_o, "FirstHeading::SecondHeading::ThirdHeading");
        test_assert(o != NULL);
        test_assert(cx_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(md_Doc(o)->text == NULL);
        test_assert(md_Doc(o)->level == 3);
        cx_release(o);
    }
/* $end */
}

/* ::test::Headers::tc_H1H2H3H1H2() */
cx_void _test_Headers_tc_H1H2H3H1H2(test_Headers this) {
/* $begin(::test::Headers::tc_H1H2H3H1H2) */

    char text[] =
        "# Heading1\n"
        "## Heading2\n"
        "### Heading3\n"
        "# Heading4\n"
        "## Heading5\n"
        ;
    md_parse(test_docs_o, text);
    {
        cx_object o = cx_resolve(test_docs_o, "Heading1");
        test_assert(o != NULL);
        test_assert(cx_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(md_Doc(o)->text == NULL);
        test_assert(md_Doc(o)->level == 1);
        cx_release(o);
    }
    {
        cx_object o = cx_resolve(test_docs_o, "Heading1::Heading2");
        test_assert(o != NULL);
        test_assert(cx_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(md_Doc(o)->text == NULL);
        test_assert(md_Doc(o)->level == 2);
        cx_release(o);
    }
    {
        cx_object o = cx_resolve(test_docs_o, "Heading1::Heading2::Heading3");
        test_assert(o != NULL);
        test_assert(cx_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(md_Doc(o)->text == NULL);
        test_assert(md_Doc(o)->level == 3);
        cx_release(o);
    }
    {
        cx_object o = cx_resolve(test_docs_o, "Heading4");
        test_assert(o != NULL);
        test_assert(cx_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(md_Doc(o)->text == NULL);
        test_assert(md_Doc(o)->level == 1);
        cx_release(o);
    }
    {
        cx_object o = cx_resolve(test_docs_o, "Heading4::Heading5");
        test_assert(o != NULL);
        test_assert(cx_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(md_Doc(o)->text == NULL);
        test_assert(md_Doc(o)->level == 2);
        cx_release(o);
    }
/* $end */
}

/* ::test::Headers::tc_H1H3() */
cx_void _test_Headers_tc_H1H3(test_Headers this) {
/* $begin(::test::Headers::tc_H1H3) */

    char text[] =
        "# Heading1\n"
        "### Heading2\n"
        ;
    md_parse(test_docs_o, text);
    {
        cx_object o = cx_resolve(test_docs_o, "Heading1");
        test_assert(o != NULL);
        test_assert(cx_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(md_Doc(o)->text == NULL);
        test_assert(md_Doc(o)->level == 1);
        cx_release(o);
    }
    {
        cx_object o = cx_resolve(test_docs_o, "Heading1::Heading2");
        test_assert(o != NULL);
        test_assert(cx_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(md_Doc(o)->text == NULL);
        test_assert(md_Doc(o)->level == 3);
        cx_release(o);
    }

/* $end */
}

/* ::test::Headers::tc_H1H3H1H3() */
cx_void _test_Headers_tc_H1H3H1H3(test_Headers this) {
/* $begin(::test::Headers::tc_H1H3H1H3) */

    char text[] =
        "# Heading1\n"
        "### Heading2\n"
        "# Heading3\n"
        "### Heading4\n"
        ;
    md_parse(test_docs_o, text);
    {
        cx_object o = cx_resolve(test_docs_o, "Heading1");
        test_assert(o != NULL);
        test_assert(cx_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(md_Doc(o)->text == NULL);
        test_assert(md_Doc(o)->level == 1);
        cx_release(o);
    }
    {
        cx_object o = cx_resolve(test_docs_o, "Heading1::Heading2");
        test_assert(o != NULL);
        test_assert(cx_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(md_Doc(o)->text == NULL);
        test_assert(md_Doc(o)->level == 3);
        cx_release(o);
    }
    {
        cx_object o = cx_resolve(test_docs_o, "Heading3");
        test_assert(o != NULL);
        test_assert(cx_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(md_Doc(o)->text == NULL);
        test_assert(md_Doc(o)->level == 1);
        cx_release(o);
    }
    {
        cx_object o = cx_resolve(test_docs_o, "Heading3::Heading4");
        test_assert(o != NULL);
        test_assert(cx_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(md_Doc(o)->text == NULL);
        test_assert(md_Doc(o)->level == 3);
        cx_release(o);
    }

/* $end */
}

/* ::test::Headers::tc_H1H3H2() */
cx_void _test_Headers_tc_H1H3H2(test_Headers this) {
/* $begin(::test::Headers::tc_H1H3H2) */

    char text[] =
        "# Heading1\n"
        "### Heading2\n"
        "## Heading3\n"
        ;
    md_parse(test_docs_o, text);
    {
        cx_object o = cx_resolve(test_docs_o, "Heading1");
        test_assert(o != NULL);
        test_assert(cx_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(md_Doc(o)->text == NULL);
        test_assert(md_Doc(o)->level == 1);
        cx_release(o);
    }
    {
        cx_object o = cx_resolve(test_docs_o, "Heading1::Heading2");
        test_assert(o != NULL);
        test_assert(cx_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(md_Doc(o)->text == NULL);
        test_assert(md_Doc(o)->level == 3);
        cx_release(o);
    }
    {
        cx_object o = cx_resolve(test_docs_o, "Heading1::Heading3");
        test_assert(o != NULL);
        test_assert(cx_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(md_Doc(o)->text == NULL);
        test_assert(md_Doc(o)->level == 2);
        cx_release(o);
    }

/* $end */
}

/* ::test::Headers::tc_H2() */
cx_void _test_Headers_tc_H2(test_Headers this) {
/* $begin(::test::Headers::tc_H2) */

    char text[] =
        "## FirstHeading\n"
        ;
    md_parse(test_docs_o, text);
    {
        cx_object o = cx_resolve(test_docs_o, "FirstHeading");
        test_assert(o == NULL);
        test_assert(cx_lasterr() != NULL);
        test_assert(!strcmp(cx_lasterr(), "H1 header missing (a level 2 header as document root is illegal)"));
    }

/* $end */
}

/* ::test::Headers::tc_H3() */
cx_void _test_Headers_tc_H3(test_Headers this) {
/* $begin(::test::Headers::tc_H3) */

    char text[] =
        "### FirstHeading\n"
        ;
    md_parse(test_docs_o, text);
    {
        cx_object o = cx_resolve(test_docs_o, "FirstHeading");
        test_assert(o == NULL);
        test_assert(cx_lasterr() != NULL);
        test_assert(!strcmp(cx_lasterr(), "H1 header missing (a level 3 header as document root is illegal)"));
    }

/* $end */
}
