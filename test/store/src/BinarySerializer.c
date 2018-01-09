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
    corto_word src = fmt->fromValue(&src_value);
    test_assert(src != 0);

    /* Copy from source */
    corto_word dst = fmt->copy(src);
    test_assert(dst != 0);

    corto_value dst_value = corto_value_mem((void*)dst, corto_package_o);

    /* Test if values are equal */
    test_assert(corto_value_compare(&src_value, &dst_value) == 0);

    corto_mem_free((void*)src);
    corto_mem_free((void*)dst);
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
