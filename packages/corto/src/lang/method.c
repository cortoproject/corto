/* This is a managed file. Do not delete this comment. */

#include <corto/corto.h>

int16_t corto_method_construct(
    corto_method this)
{

    /* Bind function */
    if (corto_function_construct(corto_function(this))) {
        goto error;
    }

    return 0;
error:
    return -1;
}

int16_t corto_method_init(
    corto_method this)
{
    extern int CORTO_BENCHMARK_METHOD_INIT;
    corto_benchmark_start(CORTO_BENCHMARK_METHOD_INIT);

    corto_int16 result;

    result = corto_function_init(corto_function(this));
    corto_benchmark_stop(CORTO_BENCHMARK_METHOD_INIT);
    return result;
}

