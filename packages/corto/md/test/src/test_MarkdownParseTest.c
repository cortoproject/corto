/* test_MarkdownParseTest.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "test.h"

/* $header() */

#define TEST_DOC_OBJECT(destination, type, name, objectDocumented) \
{ \
    cx_object o; \
    cx_type((type)); \
    test_assert((o = cx_resolve((destination), (name))) != NULL); \
    test_assert(cx_instanceof((type), o)); \
    test_assert(md_Doc(o)->o == (objectDocumented)); \
    cx_release(o); \
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
    TEST_DOC_OBJECT(test_docs_o, md_PackageDoc_o, "test::Package3", test_Package3_o);
    TEST_DOC_OBJECT(test_docs_o, md_TypeDoc_o, "test::Package3::Class0", test_Package3_Class0_o);
    TEST_DOC_OBJECT(test_docs_o, md_MethodDoc_o, "test::Package3::Class0::method0", test_Package3_Class0_method0_o);
    TEST_DOC_OBJECT(test_docs_o, md_TypeDoc_o, "test::Package3::Class1", test_Package3_Class1_o);
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
    TEST_DOC_OBJECT(test_docs_o, md_PackageDoc_o, "test::Package0", test_Package0_o);
    TEST_DOC_OBJECT(test_docs_o, md_TypeDoc_o, "test::Package0::Class0", test_Package0_Class0_o);
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
    TEST_DOC_OBJECT(test_docs_o, md_PackageDoc_o, "test::Package2", test_Package2_o);
    TEST_DOC_OBJECT(test_docs_o, md_TypeDoc_o, "test::Package2::Class0", test_Package2_Class0_o);
    TEST_DOC_OBJECT(test_docs_o, md_MethodDoc_o, "test::Package2::Class0::method0", test_Package2_Class0_method0_o);
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
    TEST_DOC_OBJECT(test_docs_o, md_PackageDoc_o, "test::Package1", test_Package1_o);
    TEST_DOC_OBJECT(test_docs_o, md_PackageDoc_o, "test::Package1::Package0", test_Package1_Package0_o);
    TEST_DOC_OBJECT(test_docs_o, md_PackageDoc_o, "test::Package1::Package0::Package0", test_Package1_Package0_Package0_o);
/* $end */
}
