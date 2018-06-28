/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

void test_Tags_tc_findTag(
    test_Tags this)
{
    /* Find three tags on type */
    corto_member m = corto_interface_resolve_member_by_tag(test_TagTest_o, test_foo_tag_o);
    test_assert(m != NULL);
    test_assert(m == test_TagTest_foo_o);

    m = corto_interface_resolve_member_by_tag(test_TagTest_o, test_hello_tag_o);
    test_assert(m != NULL);
    test_assert(m == test_TagTest_foo_o);

    m = corto_interface_resolve_member_by_tag(test_TagTest_o, test_bar_tag_o);
    test_assert(m != NULL);
    test_assert(m == test_TagTest_bar_o);
}

void test_Tags_tc_tagNotFound(
    test_Tags this)
{
    corto_member m = corto_interface_resolve_member_by_tag(test_TagTest_o, test_world_tag_o);
    test_assert(m == NULL);
}
