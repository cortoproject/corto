/* This is a managed file. Do not delete this comment. */

#include <include/test.h>
corto_string test_TestKey_login(
    test_TestKey this,
    const char *user,
    const char *password)
{

    if (!strcmp(user, "Ford Prefect") && !strcmp(password, "42")) {
        return "token_user01";
    } else
    if (!strcmp(user, "Marvin") && !strcmp(password, "android")) {
        return "token_user02";
    }

    return NULL;
}

