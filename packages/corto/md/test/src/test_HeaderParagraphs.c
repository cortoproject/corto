/* test_HeaderParagraphs.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "test.h"

/* ::test::HeaderParagraphs::tc_H1DP() */
cx_void _test_HeaderParagraphs_tc_H1DP(test_HeaderParagraphs this) {
/* $begin(::test::HeaderParagraphs::tc_H1DP) */

    char text[] =
        "# FirstHeading\n"
        "This is a description.\n\n"
        "This is the first paragraph.\n"
        ;
    md_parse(test_docs_o, text);
    {
        cx_object o = cx_resolve(test_docs_o, "FirstHeading");
        test_assert(o != NULL);
        test_assert(cx_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(md_Doc(o)->description != NULL);
        test_assert(!strcmp(md_Doc(o)->description, 
            "This is a description.\n"));
        test_assert(!strcmp(md_Doc(o)->text, 
            "This is the first paragraph.\n"));
        test_assert(md_Doc(o)->level == 1);
        cx_release(o);
    }

/* $end */
}

/* ::test::HeaderParagraphs::tc_H1DPP() */
cx_void _test_HeaderParagraphs_tc_H1DPP(test_HeaderParagraphs this) {
/* $begin(::test::HeaderParagraphs::tc_H1DPP) */

    char text[] =
        "# FirstHeading\n"
        "This is a description.\n\n"
        "This is the first paragraph.\n\n"
        "This is the second paragraph.\n"
        ;
    md_parse(test_docs_o, text);
    {
        cx_object o = cx_resolve(test_docs_o, "FirstHeading");
        test_assert(o != NULL);
        test_assert(cx_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(md_Doc(o)->description != NULL);
        test_assert(!strcmp(md_Doc(o)->description, 
            "This is a description.\n"));
        test_assert(!strcmp(md_Doc(o)->text, 
            "This is the first paragraph.\n"
            "This is the second paragraph.\n"));
        test_assert(md_Doc(o)->level == 1);
        cx_release(o);
    }

/* $end */
}

/* ::test::HeaderParagraphs::tc_H1H2H3H4P() */
cx_void _test_HeaderParagraphs_tc_H1H2H3H4P(test_HeaderParagraphs this) {
/* $begin(::test::HeaderParagraphs::tc_H1H2H3H4P) */

    char text[] =
        "# FirstHeading\n"
        "## SecondHeading\n"
        "### ThirdHeading\n"
        "#### FourthHeading\n"
        "This is the first paragraph.\n"
        ;
    md_parse(test_docs_o, text);
    {
        cx_object o = cx_resolve(test_docs_o, "FirstHeading");
        test_assert(o != NULL);
        test_assert(cx_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(md_Doc(o)->description == NULL);
        test_assert(md_Doc(o)->level == 1);
        cx_release(o);
    }
    {
        cx_object o = cx_resolve(test_docs_o, "FirstHeading::SecondHeading");
        test_assert(o != NULL);
        test_assert(cx_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(md_Doc(o)->description == NULL);
        test_assert(md_Doc(o)->level == 2);
        cx_release(o);
    }
    {
        cx_object o = cx_resolve(test_docs_o, "FirstHeading::SecondHeading::ThirdHeading");
        test_assert(o != NULL);
        test_assert(cx_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(md_Doc(o)->description == NULL);
        test_assert(md_Doc(o)->level == 3);
        cx_release(o);
    }
    {
        cx_object o = cx_resolve(test_docs_o, "FirstHeading::SecondHeading::ThirdHeading::FourthHeading");
        test_assert(o != NULL);
        test_assert(cx_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(md_Doc(o)->description != NULL);
        test_assert(!strcmp(md_Doc(o)->description, "This is the first paragraph.\n"));
        test_assert(md_Doc(o)->level == 4);
        cx_release(o);
    }

/* $end */
}

/* ::test::HeaderParagraphs::tc_H1H2H3P() */
cx_void _test_HeaderParagraphs_tc_H1H2H3P(test_HeaderParagraphs this) {
/* $begin(::test::HeaderParagraphs::tc_H1H2H3P) */

    char text[] =
        "# FirstHeading\n"
        "## SecondHeading\n"
        "### ThirdHeading\n"
        "This is the first paragraph.\n"
        ;
    md_parse(test_docs_o, text);
    {
        cx_object o = cx_resolve(test_docs_o, "FirstHeading");
        test_assert(o != NULL);
        test_assert(cx_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(md_Doc(o)->description == NULL);
        test_assert(md_Doc(o)->level == 1);
        cx_release(o);
    }
    {
        cx_object o = cx_resolve(test_docs_o, "FirstHeading::SecondHeading");
        test_assert(o != NULL);
        test_assert(cx_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(md_Doc(o)->description == NULL);
        test_assert(md_Doc(o)->level == 2);
        cx_release(o);
    }
    {
        cx_object o = cx_resolve(test_docs_o, "FirstHeading::SecondHeading::ThirdHeading");
        test_assert(o != NULL);
        test_assert(cx_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(md_Doc(o)->description != NULL);
        test_assert(!strcmp(md_Doc(o)->description, "This is the first paragraph.\n"));
        test_assert(md_Doc(o)->level == 3);
        cx_release(o);
    }

/* $end */
}

/* ::test::HeaderParagraphs::tc_H1H4P() */
cx_void _test_HeaderParagraphs_tc_H1H4P(test_HeaderParagraphs this) {
/* $begin(::test::HeaderParagraphs::tc_H1H4P) */

    char text[] =
        "# FirstHeading\n"
        "#### SecondHeading\n"
        "This is the first paragraph.\n"
        ;
    md_parse(test_docs_o, text);
    {
        cx_object o = cx_resolve(test_docs_o, "FirstHeading");
        test_assert(o != NULL);
        test_assert(cx_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(md_Doc(o)->description == NULL);
        test_assert(md_Doc(o)->level == 1);
        cx_release(o);
    }
    {
        cx_object o = cx_resolve(test_docs_o, "FirstHeading::SecondHeading");
        test_assert(o != NULL);
        test_assert(cx_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(md_Doc(o)->description != NULL);
        test_assert(!strcmp(md_Doc(o)->description, "This is the first paragraph.\n"));
        test_assert(md_Doc(o)->level == 4);
        cx_release(o);
    }

/* $end */
}

/* ::test::HeaderParagraphs::tc_H1P() */
cx_void _test_HeaderParagraphs_tc_H1P(test_HeaderParagraphs this) {
/* $begin(::test::HeaderParagraphs::tc_H1P) */
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
        test_assert(md_Doc(o)->description != NULL);
        test_assert(!strcmp(md_Doc(o)->description, "This is the first paragraph.\n"));
        test_assert(md_Doc(o)->level == 1);
        cx_release(o);
    }
/* $end */
}

/* ::test::HeaderParagraphs::tc_H1PH1P() */
cx_void _test_HeaderParagraphs_tc_H1PH1P(test_HeaderParagraphs this) {
/* $begin(::test::HeaderParagraphs::tc_H1PH1P) */

    char text[] =
        "# FirstHeading\n"
        "This is the first paragraph.\n"
        "# SecondHeading\n"
        "This is the second paragraph.\n";
        ;
    md_parse(test_docs_o, text);
    {
        cx_object o = cx_resolve(test_docs_o, "FirstHeading");
        test_assert(o != NULL);
        test_assert(cx_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(md_Doc(o)->description != NULL);
        test_assert(!strcmp(md_Doc(o)->description, "This is the first paragraph.\n"));
        test_assert(md_Doc(o)->level == 1);
        cx_release(o);
    }
    {
        cx_object o = cx_resolve(test_docs_o, "SecondHeading");
        test_assert(o != NULL);
        test_assert(cx_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(md_Doc(o)->description != NULL);
        test_assert(!strcmp(md_Doc(o)->description, "This is the second paragraph.\n"));
        test_assert(md_Doc(o)->level == 1);
        cx_release(o);
    }

/* $end */
}

/* ::test::HeaderParagraphs::tc_H1PH2P() */
cx_void _test_HeaderParagraphs_tc_H1PH2P(test_HeaderParagraphs this) {
/* $begin(::test::HeaderParagraphs::tc_H1PH2P) */

    char text[] =
        "# FirstHeading\n"
        "This is the first paragraph.\n"
        "## SecondHeading\n"
        "This is the second paragraph.\n";
        ;
    md_parse(test_docs_o, text);
    {
        cx_object o = cx_resolve(test_docs_o, "FirstHeading");
        test_assert(o != NULL);
        test_assert(cx_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(md_Doc(o)->description != NULL);
        test_assert(!strcmp(md_Doc(o)->description, "This is the first paragraph.\n"));
        test_assert(md_Doc(o)->level == 1);
        cx_release(o);
    }
    {
        cx_object o = cx_resolve(test_docs_o, "FirstHeading::SecondHeading");
        test_assert(o != NULL);
        test_assert(cx_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(md_Doc(o)->description != NULL);
        test_assert(!strcmp(md_Doc(o)->description, "This is the second paragraph.\n"));
        test_assert(md_Doc(o)->level == 2);
        cx_release(o);
    }

/* $end */
}

/* ::test::HeaderParagraphs::tc_H1PH2PH3P() */
cx_void _test_HeaderParagraphs_tc_H1PH2PH3P(test_HeaderParagraphs this) {
/* $begin(::test::HeaderParagraphs::tc_H1PH2PH3P) */

    char text[] =
        "# FirstHeading\n"
        "This is the first paragraph.\n"
        "## SecondHeading\n"
        "This is the second paragraph.\n"
        "### ThirdHeading\n"
        "This is the third paragraph.\n";
        ;
    md_parse(test_docs_o, text);
    {
        cx_object o = cx_resolve(test_docs_o, "FirstHeading");
        test_assert(o != NULL);
        test_assert(cx_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(md_Doc(o)->description != NULL);
        test_assert(!strcmp(md_Doc(o)->description, "This is the first paragraph.\n"));
        test_assert(md_Doc(o)->level == 1);
        cx_release(o);
    }
    {
        cx_object o = cx_resolve(test_docs_o, "FirstHeading::SecondHeading");
        test_assert(o != NULL);
        test_assert(cx_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(md_Doc(o)->description != NULL);
        test_assert(!strcmp(md_Doc(o)->description, "This is the second paragraph.\n"));
        test_assert(md_Doc(o)->level == 2);
        cx_release(o);
    }
    {
        cx_object o = cx_resolve(test_docs_o, "FirstHeading::SecondHeading::ThirdHeading");
        test_assert(o != NULL);
        test_assert(cx_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(md_Doc(o)->description != NULL);
        test_assert(!strcmp(md_Doc(o)->description, "This is the third paragraph.\n"));
        test_assert(md_Doc(o)->level == 3);
        cx_release(o);
    }

/* $end */
}

/* ::test::HeaderParagraphs::tc_H1PH3P() */
cx_void _test_HeaderParagraphs_tc_H1PH3P(test_HeaderParagraphs this) {
/* $begin(::test::HeaderParagraphs::tc_H1PH3P) */

    char text[] =
        "# FirstHeading\n"
        "This is the first paragraph.\n"
        "### SecondHeading\n"
        "This is the second paragraph.\n";
        ;
    md_parse(test_docs_o, text);
    {
        cx_object o = cx_resolve(test_docs_o, "FirstHeading");
        test_assert(o != NULL);
        test_assert(cx_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(md_Doc(o)->description != NULL);
        test_assert(!strcmp(md_Doc(o)->description, "This is the first paragraph.\n"));
        test_assert(md_Doc(o)->level == 1);
        cx_release(o);
    }
    {
        cx_object o = cx_resolve(test_docs_o, "FirstHeading::SecondHeading");
        test_assert(o != NULL);
        test_assert(cx_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(md_Doc(o)->description != NULL);
        test_assert(!strcmp(md_Doc(o)->description, "This is the second paragraph.\n"));
        test_assert(md_Doc(o)->level == 3);
        cx_release(o);
    }

/* $end */
}

/* ::test::HeaderParagraphs::tc_H1PnH1P() */
cx_void _test_HeaderParagraphs_tc_H1PnH1P(test_HeaderParagraphs this) {
/* $begin(::test::HeaderParagraphs::tc_H1PnH1P) */

    char text[] =
        "# FirstHeading\n"
        "This is the first paragraph.\n\n"
        "# SecondHeading\n"
        "This is the second paragraph.\n";
        ;
    md_parse(test_docs_o, text);
    {
        cx_object o = cx_resolve(test_docs_o, "FirstHeading");
        test_assert(o != NULL);
        test_assert(cx_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(md_Doc(o)->description != NULL);
        test_assert(!strcmp(md_Doc(o)->description, "This is the first paragraph.\n"));
        test_assert(md_Doc(o)->level == 1);
        cx_release(o);
    }
    {
        cx_object o = cx_resolve(test_docs_o, "SecondHeading");
        test_assert(o != NULL);
        test_assert(cx_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(md_Doc(o)->description != NULL);
        test_assert(!strcmp(md_Doc(o)->description, "This is the second paragraph.\n"));
        test_assert(md_Doc(o)->level == 1);
        cx_release(o);
    }

/* $end */
}

/* ::test::HeaderParagraphs::tc_H1PnH2P() */
cx_void _test_HeaderParagraphs_tc_H1PnH2P(test_HeaderParagraphs this) {
/* $begin(::test::HeaderParagraphs::tc_H1PnH2P) */

    char text[] =
        "# FirstHeading\n"
        "This is the first paragraph.\n\n"
        "## SecondHeading\n"
        "This is the second paragraph.\n";
        ;
    md_parse(test_docs_o, text);
    {
        cx_object o = cx_resolve(test_docs_o, "FirstHeading");
        test_assert(o != NULL);
        test_assert(cx_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(md_Doc(o)->description != NULL);
        test_assert(!strcmp(md_Doc(o)->description, "This is the first paragraph.\n"));
        test_assert(md_Doc(o)->level == 1);
        cx_release(o);
    }
    {
        cx_object o = cx_resolve(test_docs_o, "FirstHeading::SecondHeading");
        test_assert(o != NULL);
        test_assert(cx_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(md_Doc(o)->description != NULL);
        test_assert(!strcmp(md_Doc(o)->description, "This is the second paragraph.\n"));
        test_assert(md_Doc(o)->level == 2);
        cx_release(o);
    }

/* $end */
}

/* ::test::HeaderParagraphs::tc_H1PP() */
cx_void _test_HeaderParagraphs_tc_H1PP(test_HeaderParagraphs this) {
/* $begin(::test::HeaderParagraphs::tc_H1PP) */

    char text[] =
        "# FirstHeading\n"
        "This is the first paragraph.\n"
        "This is the second paragraph.\n";
        ;
    md_parse(test_docs_o, text);
    {
        cx_object o = cx_resolve(test_docs_o, "FirstHeading");
        test_assert(o != NULL);
        test_assert(cx_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(md_Doc(o)->description != NULL);
        test_assert(!strcmp(md_Doc(o)->description, 
            "This is the first paragraph.\nThis is the second paragraph.\n"));
        test_assert(md_Doc(o)->level == 1);
        cx_release(o);
    }

/* $end */
}

/* ::test::HeaderParagraphs::tc_H1PPP() */
cx_void _test_HeaderParagraphs_tc_H1PPP(test_HeaderParagraphs this) {
/* $begin(::test::HeaderParagraphs::tc_H1PPP) */

    char text[] =
        "# FirstHeading\n"
        "This is the first paragraph.\n"
        "This is the second paragraph.\n"
        "This is the third paragraph.\n";
        ;
    md_parse(test_docs_o, text);
    {
        cx_object o = cx_resolve(test_docs_o, "FirstHeading");
        test_assert(o != NULL);
        test_assert(cx_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(md_Doc(o)->description != NULL);
        test_assert(!strcmp(md_Doc(o)->description, 
            "This is the first paragraph.\n"
            "This is the second paragraph.\n"
            "This is the third paragraph.\n"));
        test_assert(md_Doc(o)->level == 1);
        cx_release(o);
    }

/* $end */
}
