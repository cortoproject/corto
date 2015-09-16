/* test_Fullname.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#define test_LIB
#include "test.h"

/* ::test::Fullname::tc_null() */
cx_void _test_Fullname_tc_null(test_Fullname this) {
/* $begin(::test::Fullname::tc_null) */
    cx_id id;

    id[0] = 'a';
    cx_string result = cx_fullname(NULL, id);
    test_assert(result == NULL);
    test_assert(id[0] == 'a');
    cx_string err = cx_lasterr();
    test_assert(err != NULL);
    test_assert(!strcmp(err, "no object provided"));

/* $end */
}

/* ::test::Fullname::tc_nullBuffer() */
cx_void _test_Fullname_tc_nullBuffer(test_Fullname this) {
/* $begin(::test::Fullname::tc_nullBuffer) */

    cx_string result = cx_fullname(this, NULL);
    test_assert(result == NULL);
    cx_string err = cx_lasterr();
    test_assert(err != NULL);
    test_assert(!strcmp(err, "no buffer provided"));

/* $end */
}

/* ::test::Fullname::tc_onelevel() */
cx_void _test_Fullname_tc_onelevel(test_Fullname this) {
/* $begin(::test::Fullname::tc_onelevel) */
    cx_id id;

    cx_string result = cx_fullname(corto_o, id);
    test_assert(result == id);
    test_assert(!strcmp(result, "::corto"));

/* $end */
}

/* ::test::Fullname::tc_root() */
cx_void _test_Fullname_tc_root(test_Fullname this) {
/* $begin(::test::Fullname::tc_root) */
    cx_id id;

    cx_string result = cx_fullname(root_o, id);
    test_assert(result == id);
    test_assert(!strcmp(result, "::"));

/* $end */
}

/* ::test::Fullname::tc_twolevels() */
cx_void _test_Fullname_tc_twolevels(test_Fullname this) {
/* $begin(::test::Fullname::tc_twolevels) */
    cx_id id;

    cx_string result = cx_fullname(corto_lang_o, id);
    test_assert(result == id);
    test_assert(!strcmp(result, "::corto::lang"));

/* $end */
}
