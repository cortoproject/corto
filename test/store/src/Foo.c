/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

int16_t test_Foo_construct(
    test_Foo this)
{

	if (!this->fail) {
	    this->x *= 2;
	    this->y *= 2;
	} else {
		  goto error;
	}

	(*test_constructCalled_o)++;

	return 0;
error:
	return -1;

}

void test_Foo_destruct(
    test_Foo this)
{
    CORTO_UNUSED(this);
    (*test_destructCalled_o)++;
}

int16_t test_Foo_init(
    test_Foo this)
{
    /* Ensure that init is called on real object- which must be guaranteed since
     * 'Foo' is a reference type */
    corto_assert_object(this);

    this->x = 1;
    this->y = 2;

    (*test_initCalled_o)++;

	return 0;
}
