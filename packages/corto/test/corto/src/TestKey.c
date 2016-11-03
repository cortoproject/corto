/* $CORTO_GENERATED
 *
 * TestKey.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <test.h>

corto_string _test_TestKey_authenticate(
    test_TestKey this,
    corto_string user,
    corto_string password)
{
/* $begin(test/TestKey/authenticate) */

    if (!strcmp(user, "Ford Prefect") && !strcmp(password, "42")) {
        return "token_user01";
    } else
    if (!strcmp(user, "Marvin") && !strcmp(password, "android")) {
        return "token_user02";
    }

    return NULL;
/* $end */
}
