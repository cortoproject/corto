/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

corto_string test_TestKey_authenticate(
    test_TestKey this,
    corto_string user,
    corto_string password)
{

    if (!strcmp(user, "Ford Prefect") && !strcmp(password, "42")) {
        return "token_user01";
    } else
    if (!strcmp(user, "Marvin") && !strcmp(password, "android")) {
        return "token_user02";
    }

    return NULL;
}

