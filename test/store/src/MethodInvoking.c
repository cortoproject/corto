/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

void test_MethodInvoking_tc_interfaceMethod(
    test_MethodInvoking this)
{
    test_Boat v1 = test_BoatCreate(10.0, 20.0);
    test_assert(v1 != NULL);
    test_assertflt(v1->cur_x, 10.0);
    test_assertflt(v1->cur_y, 20.0);

    test_Plane v2 = test_PlaneCreate(30.0, 40.0);
    test_assert(v2 != NULL);
    test_assertflt(v2->cur_x, 30.0);
    test_assertflt(v2->cur_y, 40.0);

    double r1 = test_Vehicle_move(v1, 1.0, 2.0);
    test_assertflt(r1, 1.0 + 2.0);
    test_assertflt(v1->cur_x, 10.0 + 1.0);
    test_assertflt(v1->cur_y, 20.0 + 2.0);

    double r2 = test_Vehicle_move(v2, 3.0, 4.0);
    test_assertflt(r2, 3.0 + 4.0);
    test_assertflt(v2->cur_x, 30.0 + 3.0);
    test_assertflt(v2->cur_y, 40.0 + 4.0);

    test_assert(corto_delete(v1) == 0);
    test_assert(corto_delete(v2) == 0);
}

