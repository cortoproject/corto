/* test_Point.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#define test_LIB
#include "test.h"

/* ::test::Point::construct() */
cx_int16 _test_Point_construct(test_Point this) {
/* $begin(::test::Point::construct) */

	if (!this->fail) {
	    this->x += 10;
	    this->y += 20;
	} else {
		goto error;
	}

	return 0;
error:
	return -1;
/* $end */
}

/* ::test::Point::destruct() */
cx_void _test_Point_destruct(test_Point this) {
/* $begin(::test::Point::destruct) */
    CX_UNUSED(this);
/* $end */
}

/* ::test::Point::init() */
cx_int16 _test_Point_init(test_Point this) {
/* $begin(::test::Point::init) */

    this->x = 1;
    this->y = 2;

	return 0;
/* $end */
}
