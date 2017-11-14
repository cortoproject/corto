/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

double test_Boat_move(
    test_Boat this,
    double x,
    double y)
{
    this->cur_x += x;
    this->cur_y += y;
    return x + y;
}

