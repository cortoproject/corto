/* This is a managed file. Do not delete this comment. */

#include <include/test.h>
void test_BinarySerializer_tc_serializeReferenceType(
    test_BinarySerializer this)
{
    /* Use corto_select to serialize corto package to binary format */
    corto_iter it;
    test_assert(corto_select("corto").contentType("binary/corto").iter(&it) == 0);

    test_assert(corto_iter_hasNext(&it) != 0);
    corto_result *r = corto_iter_next(&it);
    test_assert(r != NULL);
    test_assert(r->value != 0);

    corto_value src_value = corto_value_mem(corto_o, corto_package_o);
    corto_value dst_value = corto_value_mem((void*)r->value, corto_package_o);

    /* Test if values are equal */
    test_assert(corto_value_compare(&src_value, &dst_value) == 0);
    test_assert(corto_iter_hasNext(&it) == 0);
}

void test_BinarySerializer_tc_copyReferenceType(
    test_BinarySerializer this)
{
    corto_fmt fmt = corto_fmt_lookup("binary/corto");
    test_assert(fmt != NULL);

    corto_value src_value = corto_value_mem(corto_o, corto_package_o);

    /* Serialize source to binary */
    void *src = corto_fmt_from_value(fmt, NULL, &src_value);
    test_assert(src != 0);

    /* Copy from source */
    void *dst = corto_fmt_copy(fmt, src);
    test_assert(dst != 0);

    corto_value dst_value = corto_value_mem(dst, corto_package_o);

    /* Test if values are equal */
    test_assertint(corto_value_compare(&src_value, &dst_value), 0);

    corto_mem_free(src);
    corto_mem_free(dst);
}

void test_BinarySerializer_tc_serializeReferenceTypeWithInit(
    test_BinarySerializer this)
{
    /* Use corto_select to serialize corto package to binary format */
    corto_iter it;
    test_assert(corto_select("corto/lang/class").contentType("binary/corto").iter(&it) == 0);

    test_assert(corto_iter_hasNext(&it) != 0);
    corto_result *r = corto_iter_next(&it);
    test_assert(r != NULL);
    test_assert(r->value != 0);

    corto_value src_value = corto_value_mem(corto_class_o, corto_class_o);
    corto_value dst_value = corto_value_mem((void*)r->value, corto_class_o);

    /* Test if values are equal */
    test_assert(corto_value_compare(&src_value, &dst_value) == 0);
    test_assert(corto_iter_hasNext(&it) == 0);
}

void test_BinarySerializer_tc_copyListWithReferenceType(
    test_BinarySerializer this)
{
    corto_fmt fmt = corto_fmt_lookup("binary/corto");
    test_assert(fmt != NULL);

    test_struct_listReference *o =
        corto_create(NULL, NULL, test_struct_listReference_o);

    /* Populate list */
    corto_objectlist__append(o->m, corto_o);
    corto_objectlist__append(o->m, corto_lang_o);
    corto_objectlist__append(o->m, corto_package_o);
    corto_objectlist__append(o->m, root_o);

    corto_value src_value = corto_value_mem(o, test_struct_listReference_o);

    /* Serialize source to binary */
    void *src = corto_fmt_from_value(fmt, NULL, &src_value);
    test_assert(src != 0);

    /* Copy from source */
    void *dst = corto_fmt_copy(fmt, src);
    test_assert(dst != 0);

    corto_value dst_value = corto_value_mem(dst, test_struct_listReference_o);

    /* Test if values are equal */
    test_assert(corto_value_compare(&src_value, &dst_value) == 0);

    corto_mem_free(src);
    corto_mem_free(dst);
    test_assert(corto_delete(o) == 0);
}

void test_BinarySerializer_tc_copyListWithReferenceWithInitType(
    test_BinarySerializer this)
{
    corto_fmt fmt = corto_fmt_lookup("binary/corto");
    test_assert(fmt != NULL);

    test_CompositeWithReferenceTypeWithInit *o = corto_create(NULL, NULL, test_CompositeWithReferenceTypeWithInit_o);

    test_Foo e = corto_create(NULL, NULL, test_Foo_o); /* Element */

    /* Populate list */
    test_FooList__append(o->m, e);
    test_FooList__append(o->m, e);
    test_FooList__append(o->m, e);
    test_FooList__append(o->m, e);

    corto_value src_value =
        corto_value_mem(o, test_CompositeWithReferenceTypeWithInit_o);

    /* Serialize source to binary */
    void *src = corto_fmt_from_value(fmt, NULL, &src_value);
    test_assert(src != 0);

    /* Copy from source */
    void *dst = corto_fmt_copy(fmt, src);
    test_assert(dst != 0);

    corto_value dst_value =
        corto_value_mem(dst, test_CompositeWithReferenceTypeWithInit_o);

    /* Test if values are equal */
    test_assert(corto_value_compare(&src_value, &dst_value) == 0);

    corto_mem_free(src);
    corto_mem_free(dst);
    test_assert(corto_delete(o) == 0);
}

void test_BinarySerializer_tc_copyListWithReferenceWithDefaults(
    test_BinarySerializer this)
{
    corto_fmt fmt = corto_fmt_lookup("binary/corto");
    test_assert(fmt != NULL);

    test_CompositeWithReferenceTypeDefaults *o =
        corto_create(NULL, NULL, test_CompositeWithReferenceTypeDefaults_o);

    /* Element */
    test_DefaultValues e = corto_create(NULL, NULL, test_DefaultValues_o);

    /* Populate list */
    test_DefaultValuesList__append(o->m, e);
    test_DefaultValuesList__append(o->m, e);
    test_DefaultValuesList__append(o->m, e);
    test_DefaultValuesList__append(o->m, e);

    corto_value src_value =
        corto_value_mem(o, test_CompositeWithReferenceTypeDefaults_o);

    /* Serialize source to binary */
    void *src = corto_fmt_from_value(fmt, NULL, &src_value);
    test_assert(src != 0);

    /* Copy from source */
    void *dst = corto_fmt_copy(fmt, src);
    test_assert(dst != 0);

    corto_value dst_value =
        corto_value_mem(dst, test_CompositeWithReferenceTypeDefaults_o);

    /* Test if values are equal */
    test_assert(corto_value_compare(&src_value, &dst_value) == 0);

    corto_mem_free(src);
    corto_mem_free(dst);
    test_assert(corto_delete(o) == 0);
}
