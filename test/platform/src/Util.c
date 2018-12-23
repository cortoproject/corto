/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

#define ULLONG_MAX_STR "18446744073709551615"
#define ULONG_MAX_STR "18446744073709551615"

void test_Util_tc_ulltoa(
    test_Util this)
{
    char buffer[255];

    corto_string ullongMax = ut_asprintf("%llu", ULLONG_MAX);
    test_assert(strcmp(corto_ulltoa(ULLONG_MAX, buffer, 10), ullongMax) == 0);

    corto_string ulongMax = ut_asprintf("%lu", ULONG_MAX);
    test_assert(strcmp(corto_ulltoa(ULONG_MAX, buffer, 10), ulongMax) == 0);

    corto_string longMin = ut_asprintf("%lu", LONG_MIN);
    test_assert(strcmp(corto_ulltoa(LONG_MIN, buffer, 10), longMin) == 0);

    corto_string a1 = "15551";
    test_assert(strcmp(corto_ulltoa(15551, buffer, 10), a1) == 0);
    test_assert(strcmp(corto_ulltoa(-15551, buffer, 10), a1) != 0);

    corto_string a2 = "0";
    test_assert(strcmp(corto_ulltoa(0, buffer, 10), a2) == 0);
    test_assert(strcmp(corto_ulltoa(100, buffer, 10), a2) != 0);
    test_assert(strcmp(corto_ulltoa(-100, buffer, 10), a2) != 0);

    corto_string a3 = ut_asprintf("%d", 65535);
    test_assert(strcmp(corto_ulltoa(65535, buffer, 10), a3) == 0);

    corto_string a4 = ut_asprintf("%d", -65535);
    test_assert(strcmp(corto_ulltoa(65535, buffer, 10), a4) != 0);

}
