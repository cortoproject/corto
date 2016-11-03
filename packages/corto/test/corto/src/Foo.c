/* $CORTO_GENERATED
 *
 * Foo.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <test.h>

corto_int16 _test_Foo_construct(
    test_Foo this)
{
/* $begin(test/Foo/construct) */

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

corto_void _test_Foo_destruct(
    test_Foo this)
{
/* $begin(test/Foo/destruct) */
    CORTO_UNUSED(this);
    (*test_destructCalled_o)++;
/* $end */
}

corto_int16 _test_Foo_init(
    test_Foo this)
{
/* $begin(test/Foo/init) */
    this->x = 1;
    this->y = 2;

    (*test_initCalled_o)++;

	return 0;
/* $end */
}
