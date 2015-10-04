/* test_MarkdownParseTest.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "test.h"

/* $header() */

void test__countTree(cx_object o, size_t* count) {
    *count += 1;
    cx_objectseq oseq = cx_scopeClaim(o);
    {
        cx_objectseqForeach(oseq, child) {
            test__countTree(child, count);
        }
    }
    cx_scopeRelease(oseq);
}

size_t test_countTree(cx_object o) {
    size_t count = 0;
    test__countTree(o, &count);
    return count;
}

/* $end */

/* ::test::MarkdownParseTest::testDeeperHierarchy1() */
cx_void _test_MarkdownParseTest_testDeeperHierarchy1(test_MarkdownParseTest this) {
/* $begin(::test::MarkdownParseTest::testDeeperHierarchy1) */
    char text[] =
        "# test::Package3\n"
        "## Class0\n"
        "### method0\n"
        "## Class1\n"
        "### method0\n"
        "# test::Package3::Package0\n"
        "# test::Package3::Package0::Package0\n"
        ;
    md_parse(test_docs_o, text);
    test_assert(test_countTree(test_docs_o) == 9);
    {
        cx_object o;
        test_assert((o = cx_resolve(test_docs_o, "test::Package3")) != NULL);
        test_assert(cx_instanceof(cx_type(md_PackageDoc_o), o));
        test_assert(md_Doc(o)->o == test_Package3_o);
        cx_release(o);
    }
    {
        cx_object o;
        test_assert((o = cx_resolve(test_docs_o, "test::Package3::Class0")) != NULL);
        test_assert(cx_instanceof(cx_type(md_TypeDoc_o), o));
        test_assert(md_Doc(o)->o == test_Package3_Class0_o);
        cx_release(o);
    }
    {
        cx_object o;
        test_assert((o = cx_resolve(test_docs_o, "test::Package3::Class0::method0")) != NULL);
        test_assert(cx_instanceof(cx_type(md_MethodDoc_o), o));
        test_assert(md_Doc(o)->o == test_Package3_Class0_method0_o);
        cx_release(o);
    }
    {
        cx_object o;
        test_assert((o = cx_resolve(test_docs_o, "test::Package3::Class1")) != NULL);
        test_assert(cx_instanceof(cx_type(md_TypeDoc_o), o));
        test_assert(md_Doc(o)->o == test_Package3_Class1_o);
        cx_release(o);
    }
/* $end */
}

/* ::test::MarkdownParseTest::testNoRootDestination() */
cx_void _test_MarkdownParseTest_testNoRootDestination(test_MarkdownParseTest this) {
/* $begin(::test::MarkdownParseTest::testNoRootDestination) */
    char text[] =
        "# test::Package0\n"
        "## Class0\n"
        ;
    md_parse(NULL, text);
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
        "# test::Package0\n"
        "## Class0\n"
        ;
    md_parse(test_docs_o, text);
    test_assert(test_countTree(test_docs_o) == 4);
    {
        cx_object o;
        test_assert((o = cx_resolve(test_docs_o, "test::Package0")) != NULL);
        test_assert(cx_instanceof(cx_type(md_PackageDoc_o), o));
        test_assert(md_Doc(o)->o == test_Package0_o);
        cx_release(o);
    }
    {
        cx_object o;
        test_assert((o = cx_resolve(test_docs_o, "test::Package0::Class0")) != NULL);
        test_assert(cx_instanceof(cx_type(md_TypeDoc_o), o));
        test_assert(md_Doc(o)->o == test_Package0_Class0_o);
        cx_release(o);
    }
/* $end */
}

/* ::test::MarkdownParseTest::testPackageAndClassAndMethod() */
cx_void _test_MarkdownParseTest_testPackageAndClassAndMethod(test_MarkdownParseTest this) {
/* $begin(::test::MarkdownParseTest::testPackageAndClassAndMethod) */
    char text[] =
        "# test::Package2\n"
        "## Class0\n"
        "### method0\n"
        ;
    md_parse(test_docs_o, text);
    test_assert(test_countTree(test_docs_o) == 5);
    {
        cx_object o;
        test_assert((o = cx_resolve(test_docs_o, "test::Package2")) != NULL);
        test_assert(cx_instanceof(cx_type(md_PackageDoc_o), o));
        test_assert(md_Doc(o)->o == test_Package2_o);
        cx_release(o);
    }
    {
        cx_object o;
        test_assert((o = cx_resolve(test_docs_o, "test::Package2::Class0")) != NULL);
        test_assert(cx_instanceof(cx_type(md_TypeDoc_o), o));
        test_assert(md_Doc(o)->o == test_Package2_Class0_o);
        cx_release(o);
    }
    {
        cx_object o;
        test_assert((o = cx_resolve(test_docs_o, "test::Package2::Class0::method0")) != NULL);
        test_assert(cx_instanceof(cx_type(md_MethodDoc_o), o));
        test_assert(md_Doc(o)->o == test_Package2_Class0_method0_o);
        cx_release(o);
    }
/* $end */
}

/* ::test::MarkdownParseTest::testPackageWithParagraph() */
cx_void _test_MarkdownParseTest_testPackageWithParagraph(test_MarkdownParseTest this) {
/* $begin(::test::MarkdownParseTest::testPackageWithParagraph) */
    char text[] =
        "# test::Package4\n"
        "This is a very awesome package\n"
        ;
    md_parse(test_docs_o, text);
    test_assert(test_countTree(test_docs_o) == 3);
    cx_object o = cx_resolve(test_docs_o, "test::Package4");
    test_assert(o != NULL);
    char expectedText[] = "This is a very awesome package\n\n";
    test_assert(strcmp(md_Doc(o)->text, expectedText) == 0);
    cx_release(o);
/* $end */
}

/* ::test::MarkdownParseTest::testScopedPackage() */
cx_void _test_MarkdownParseTest_testScopedPackage(test_MarkdownParseTest this) {
/* $begin(::test::MarkdownParseTest::testScopedPackage) */
    char text[] =
        "# test::Package1\n"
        "# test::Package1::Package0\n"
        "# test::Package1::Package0::Package0\n"
        ;
    md_parse(test_docs_o, text);
    test_assert(test_countTree(test_docs_o) == 5);
    {
        cx_object o;
        test_assert((o = cx_resolve(test_docs_o, "test::Package1")) != NULL);
        test_assert(cx_instanceof(cx_type(md_PackageDoc_o), o));
        test_assert(md_Doc(o)->o == test_Package1_o);
        cx_release(o);
    }
    {
        cx_object o;
        test_assert((o = cx_resolve(test_docs_o, "test::Package1::Package0")) != NULL);
        test_assert(cx_instanceof(cx_type(md_PackageDoc_o), o));
        test_assert(md_Doc(o)->o == test_Package1_Package0_o);
        cx_release(o);
    }
    {
        cx_object o;
        test_assert((o = cx_resolve(test_docs_o, "test::Package1::Package0::Package0")) != NULL);
        test_assert(cx_instanceof(cx_type(md_PackageDoc_o), o));
        test_assert(md_Doc(o)->o == test_Package1_Package0_Package0_o);
        cx_release(o);
    }
/* $end */
}
