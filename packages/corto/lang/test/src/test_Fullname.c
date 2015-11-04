/* $CORTO_GENERATED
 *
 * test_Fullname.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include "test.h"

corto_void _test_Fullname_tc_null(test_Fullname this) {
/* $begin(::test::Fullname::tc_null) */
    corto_id id;

    id[0] = 'a';
    corto_string result = corto_fullname(NULL, id);
    test_assert(result == NULL);
    test_assert(id[0] == 'a');
    corto_string err = corto_lasterr();
    test_assert(err != NULL);
    test_assert(!strcmp(err, "no object provided"));

/* $end */
}

corto_void _test_Fullname_tc_nullBuffer(test_Fullname this) {
/* $begin(::test::Fullname::tc_nullBuffer) */

    corto_string result = corto_fullname(this, NULL);
    test_assert(result == NULL);
    corto_string err = corto_lasterr();
    test_assert(err != NULL);
    test_assert(!strcmp(err, "no buffer provided"));

/* $end */
}

corto_void _test_Fullname_tc_onelevel(test_Fullname this) {
/* $begin(::test::Fullname::tc_onelevel) */
    corto_id id;

    corto_string result = corto_fullname(corto_o, id);
    test_assert(result == id);
    test_assert(!strcmp(result, "::corto"));

/* $end */
}

corto_void _test_Fullname_tc_root(test_Fullname this) {
/* $begin(::test::Fullname::tc_root) */
    corto_id id;

    corto_string result = corto_fullname(root_o, id);
    test_assert(result == id);
    test_assert(!strcmp(result, "::"));

/* $end */
}

corto_void _test_Fullname_tc_twolevels(test_Fullname this) {
/* $begin(::test::Fullname::tc_twolevels) */
    corto_id id;

    corto_string result = corto_fullname(corto_lang_o, id);
    test_assert(result == id);
    test_assert(!strcmp(result, "::corto::lang"));

/* $end */
}
