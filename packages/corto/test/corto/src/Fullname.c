/* $CORTO_GENERATED
 *
 * Fullname.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <test.h>

corto_void _test_Fullname_tc_fromLang(
    test_Fullname this)
{
/* $begin(test/Fullname/tc_fromLang) */
    corto_id id;

    corto_string result = corto_fullpath(id, corto_int32_o);
    test_assert(result == id);
    test_assert(!strcmp(result, "int32"));

/* $end */
}

corto_void _test_Fullname_tc_null(
    test_Fullname this)
{
/* $begin(test/Fullname/tc_null) */
    corto_id id;

    id[0] = 'a';
    corto_string result = corto_fullpath(id, NULL);
    test_assert(result == id);
    test_assert(!strcmp(result, ""));
    corto_string err = corto_lasterr();
    test_assert(err == NULL);

/* $end */
}

corto_void _test_Fullname_tc_nullBuffer(
    test_Fullname this)
{
/* $begin(test/Fullname/tc_nullBuffer) */

    corto_string result = corto_fullpath(NULL, NULL);
    test_assert(result != NULL);
    test_assert(!strcmp(result, ""));
    corto_string err = corto_lasterr();
    test_assert(err == NULL);

/* $end */
}

corto_void _test_Fullname_tc_onelevel(
    test_Fullname this)
{
/* $begin(test/Fullname/tc_onelevel) */
    corto_id id;

    corto_string result = corto_fullpath(id, corto_o);
    test_assert(result == id);
    test_assert(!strcmp(result, "/corto"));

/* $end */
}

corto_void _test_Fullname_tc_root(
    test_Fullname this)
{
/* $begin(test/Fullname/tc_root) */
    corto_id id;

    corto_string result = corto_fullpath(id, root_o);
    test_assert(result == id);
    test_assert(!strcmp(result, "/"));

/* $end */
}

corto_void _test_Fullname_tc_twolevels(
    test_Fullname this)
{
/* $begin(test/Fullname/tc_twolevels) */
    corto_id id;

    corto_string result = corto_fullpath(id, corto_lang_o);
    test_assert(result == id);
    test_assert(!strcmp(result, "/corto/lang"));

/* $end */
}
