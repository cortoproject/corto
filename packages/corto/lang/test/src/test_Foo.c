/* test_Foo.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "test.h"

/* ::test::Foo::construct() */
corto_int16 _test_Foo_construct(test_Foo this) {
/* $begin(::test::Foo::construct) */

	if (!this->fail) {
	    this->x += 10;
	    this->y += 20;
	} else {
		goto error;
	}

	(*test_constructCalled_o)++;

	return 0;
error:
	return -1;

/* $end */
}

/* ::test::Foo::destruct() */
corto_void _test_Foo_destruct(test_Foo this) {
/* $begin(::test::Foo::destruct) */
    CORTO_UNUSED(this);
    (*test_destructCalled_o)++;
/* $end */
}

/* ::test::Foo::init() */
corto_int16 _test_Foo_init(test_Foo this) {
/* $begin(::test::Foo::init) */
    this->x = 1;
    this->y = 2;

    (*test_initCalled_o)++;
    
	return 0;
/* $end */
}
