/* $CORTO_GENERATED
 *
 * method.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <corto/lang/lang.h>

corto_int16 _corto_method_construct(
    corto_method this)
{
/* $begin(corto/lang/method/construct) */

    /* Bind function */
    if (corto_function_construct(corto_function(this))) {
        goto error;
    }

    return 0;
error:
    return -1;
/* $end */
}

corto_int16 _corto_method_init(
    corto_method this)
{
/* $begin(corto/lang/method/init) */
    extern int CORTO_BENCHMARK_METHOD_INIT;
    corto_benchmark_start(CORTO_BENCHMARK_METHOD_INIT);

    corto_object parent;
    corto_int16 result;

    /* Locate parent class object */
    parent = corto_parentof(this);

    /* Parent of method must be an interface type */
    if (corto_class_instanceof(corto_interface_o, parent)) {
        if (corto_interface_bindMethod(corto_interface(parent), this)) {
            goto error;
        }
    }

    result = corto_function_init(corto_function(this));
    corto_benchmark_stop(CORTO_BENCHMARK_METHOD_INIT);
    return result;
error:
    corto_benchmark_stop(CORTO_BENCHMARK_METHOD_INIT);
    return -1;
/* $end */
}
