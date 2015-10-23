/* test_Packages.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "test.h"

/* ::test::Packages::tc_class() */
corto_void _test_Packages_tc_class(test_Packages this) {
/* $begin(::test::Packages::tc_class) */

    char text[] =
        "# test::Package0\n"
        "## Class0\n"
        "Description of class\n"
        ;
    md_parse(test_docs_o, text);

    corto_object h1 = corto_resolve(test_docs_o, "test_Package0");
    test_assert(h1 != NULL);
    test_assert(corto_instanceof(md_Doc_o, h1));
    test_assert(md_Doc(h1)->o != NULL);
    test_assert(!strcmp(corto_nameof(md_Doc(h1)->o), "Package0"));
    test_assert(corto_parentof(md_Doc(h1)->o) == test_o);
    test_assert(md_Doc(h1)->text == NULL);
    test_assert(md_Doc(h1)->level == 1);
    corto_release(h1);

    corto_object h2 = corto_resolve(test_docs_o, "test_Package0::Class0");
    test_assert(h2 != NULL);
    test_assert(corto_instanceof(md_Doc_o, h2));
    test_assert(md_Doc(h2)->o != NULL);
    test_assert(!strcmp(corto_nameof(md_Doc(h2)->o), "Class0"));
    test_assert(corto_parentof(md_Doc(h2)->o) == md_Doc(h1)->o);
    test_assert(!strcmp(md_Doc(h2)->description, "Description of class\n"));
    test_assert(md_Doc(h2)->level == 2);
    corto_release(h2);

/* $end */
}

/* ::test::Packages::tc_method() */
corto_void _test_Packages_tc_method(test_Packages this) {
/* $begin(::test::Packages::tc_method) */

    char text[] =
        "# test::Package0\n"
        "## Class0\n"
        "Description of class\n"
        "### method0\n"
        "Description of method0\n"
        "### method1\n"
        "Description of method1\n"
        ;
    md_parse(test_docs_o, text);

    corto_object h1 = corto_resolve(test_docs_o, "test_Package0");
    test_assert(h1 != NULL);
    test_assert(corto_instanceof(md_Doc_o, h1));
    test_assert(md_Doc(h1)->o != NULL);
    test_assert(!strcmp(corto_nameof(md_Doc(h1)->o), "Package0"));
    test_assert(corto_parentof(md_Doc(h1)->o) == test_o);
    test_assert(md_Doc(h1)->text == NULL);
    test_assert(md_Doc(h1)->level == 1);
    corto_release(h1);

    corto_object h2 = corto_resolve(test_docs_o, "test_Package0::Class0");
    test_assert(h2 != NULL);
    test_assert(corto_instanceof(md_Doc_o, h2));
    test_assert(md_Doc(h2)->o != NULL);
    test_assert(!strcmp(corto_nameof(md_Doc(h2)->o), "Class0"));
    test_assert(corto_parentof(md_Doc(h2)->o) == md_Doc(h1)->o);
    test_assert(!strcmp(md_Doc(h2)->description, "Description of class\n"));
    test_assert(md_Doc(h2)->text == NULL);
    test_assert(md_Doc(h2)->level == 2);
    corto_release(h2);

    corto_object h3 = corto_resolve(test_docs_o, "test_Package0::Class0::method0");
    test_assert(h3 != NULL);
    test_assert(corto_instanceof(md_Doc_o, h3));
    test_assert(md_Doc(h3)->o != NULL);
    test_assert(!strcmp(corto_nameof(md_Doc(h3)->o), "method0()"));
    test_assert(corto_parentof(md_Doc(h3)->o) == md_Doc(h2)->o);
    test_assert(!strcmp(md_Doc(h3)->description, "Description of method0\n"));
    test_assert(md_Doc(h3)->text == NULL);
    test_assert(md_Doc(h3)->level == 3);
    corto_release(h3);

    h3 = corto_resolve(test_docs_o, "test_Package0::Class0::method1");
    test_assert(h3 != NULL);
    test_assert(corto_instanceof(md_Doc_o, h3));
    test_assert(md_Doc(h3)->o != NULL);
    test_assert(!strcmp(corto_nameof(md_Doc(h3)->o), "method1()"));
    test_assert(corto_parentof(md_Doc(h3)->o) == md_Doc(h2)->o);
    test_assert(!strcmp(md_Doc(h3)->description, "Description of method1\n"));
    test_assert(md_Doc(h3)->text == NULL);
    test_assert(md_Doc(h3)->level == 3);
    corto_release(h3);

/* $end */
}

/* ::test::Packages::tc_nestedPackage() */
corto_void _test_Packages_tc_nestedPackage(test_Packages this) {
/* $begin(::test::Packages::tc_nestedPackage) */

    char text[] =
        "# test::Package1\n"
        "Description of Package1\n"
        "# test::Package1::Package0\n"
        "Description of Package1/Package0\n"
        "# test::Package1::Package0::Package0\n"
        "Description of Package1/Package0/Package0\n"
        ;
    md_parse(test_docs_o, text);

    corto_object h1 = corto_resolve(test_docs_o, "test_Package1");
    test_assert(h1 != NULL);
    test_assert(corto_instanceof(md_Doc_o, h1));
    test_assert(md_Doc(h1)->o != NULL);
    test_assert(!strcmp(corto_nameof(md_Doc(h1)->o), "Package1"));
    test_assert(corto_parentof(md_Doc(h1)->o) == test_o);
    test_assert(md_Doc(h1)->text == NULL);
    test_assert(md_Doc(h1)->level == 1);
    corto_release(h1);

    corto_object h2 = corto_resolve(test_docs_o, "test_Package1_Package0");
    test_assert(h2 != NULL);
    test_assert(corto_instanceof(md_Doc_o, h2));
    test_assert(md_Doc(h2)->o != NULL);
    test_assert(!strcmp(corto_nameof(md_Doc(h2)->o), "Package0"));
    test_assert(corto_parentof(md_Doc(h2)->o) == md_Doc(h1)->o);
    test_assert(!strcmp(md_Doc(h2)->description, "Description of Package1/Package0\n"));
    test_assert(md_Doc(h2)->text == NULL);
    test_assert(md_Doc(h2)->level == 1);
    corto_release(h2);

    corto_object h3 = corto_resolve(test_docs_o, "test_Package1_Package0_Package0");
    test_assert(h3 != NULL);
    test_assert(corto_instanceof(md_Doc_o, h3));
    test_assert(md_Doc(h3)->o != NULL);
    test_assert(!strcmp(corto_nameof(md_Doc(h3)->o), "Package0"));
    test_assert(corto_parentof(md_Doc(h3)->o) == md_Doc(h2)->o);
    test_assert(!strcmp(md_Doc(h3)->description, "Description of Package1/Package0/Package0\n"));
    test_assert(md_Doc(h3)->text == NULL);
    test_assert(md_Doc(h3)->level == 1);
    corto_release(h3);

/* $end */
}

/* ::test::Packages::tc_twoClasses() */
corto_void _test_Packages_tc_twoClasses(test_Packages this) {
/* $begin(::test::Packages::tc_twoClasses) */

    char text[] =
        "# test::Package2\n"
        "## Class0\n"
        "Description of class0\n"
        "### method0\n"
        "Description for method0 of Class0\n"
        "## Class1\n"
        "Description of class1\n"
        "### method0\n"
        "Description for method0 of Class1\n"
        ;
    md_parse(test_docs_o, text);

    corto_object h1 = corto_resolve(test_docs_o, "test_Package2");
    test_assert(h1 != NULL);
    test_assert(corto_instanceof(md_Doc_o, h1));
    test_assert(md_Doc(h1)->o != NULL);
    test_assert(!strcmp(corto_nameof(md_Doc(h1)->o), "Package2"));
    test_assert(corto_parentof(md_Doc(h1)->o) == test_o);
    test_assert(md_Doc(h1)->text == NULL);
    test_assert(md_Doc(h1)->level == 1);
    corto_release(h1);

    corto_object h2 = corto_resolve(test_docs_o, "test_Package2::Class0");
    test_assert(h2 != NULL);
    test_assert(corto_instanceof(md_Doc_o, h2));
    test_assert(md_Doc(h2)->o != NULL);
    test_assert(!strcmp(corto_nameof(md_Doc(h2)->o), "Class0"));
    test_assert(corto_parentof(md_Doc(h2)->o) == md_Doc(h1)->o);
    test_assert(!strcmp(md_Doc(h2)->description, "Description of class0\n"));
    test_assert(md_Doc(h2)->level == 2);
    corto_release(h2);

    corto_object h3 = corto_resolve(test_docs_o, "test_Package2::Class0::method0");
    test_assert(h3 != NULL);
    test_assert(corto_instanceof(md_Doc_o, h3));
    test_assert(md_Doc(h3)->o != NULL);
    test_assert(!strcmp(corto_nameof(md_Doc(h3)->o), "method0()"));
    test_assert(corto_parentof(md_Doc(h3)->o) == md_Doc(h2)->o);
    test_assert(!strcmp(md_Doc(h3)->description, "Description for method0 of Class0\n"));
    test_assert(md_Doc(h3)->level == 3);
    corto_release(h3);

    h2 = corto_resolve(test_docs_o, "test_Package2::Class1");
    test_assert(h2 != NULL);
    test_assert(corto_instanceof(md_Doc_o, h2));
    test_assert(md_Doc(h2)->o != NULL);
    test_assert(!strcmp(corto_nameof(md_Doc(h2)->o), "Class1"));
    test_assert(corto_parentof(md_Doc(h2)->o) == md_Doc(h1)->o);
    test_assert(!strcmp(md_Doc(h2)->description, "Description of class1\n"));
    test_assert(md_Doc(h2)->level == 2);
    corto_release(h2);

    h3 = corto_resolve(test_docs_o, "test_Package2::Class1::method0");
    test_assert(h3 != NULL);
    test_assert(corto_instanceof(md_Doc_o, h3));
    test_assert(md_Doc(h3)->o != NULL);
    test_assert(!strcmp(corto_nameof(md_Doc(h3)->o), "method0()"));
    test_assert(corto_parentof(md_Doc(h3)->o) == md_Doc(h2)->o);
    test_assert(!strcmp(md_Doc(h3)->description, "Description for method0 of Class1\n"));
    test_assert(md_Doc(h3)->level == 3);
    corto_release(h3);
    
/* $end */
}
