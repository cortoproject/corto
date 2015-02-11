/* io__wrapper.c
 *
 * This file contains wrapper functions for ::cortex::io.
 */

#include "io.h"
#include "io__meta.h"

void __io_print(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(result);
    io_print(
        *(cx_string*)args);
}

void __io_println(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(result);
    io_println(
        *(cx_string*)args);
}

void __io_readln(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_string*)result = io_readln(
        );
}

void __io_file_construct(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = io_file_construct(
        *(void**)args);
}

void __io_file_destruct(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    CX_UNUSED(result);
    io_file_destruct(
        *(void**)args);
}

void __io_file_flush(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    CX_UNUSED(result);
    io_file_flush(
        *(void**)args);
}

void __io_file_read(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_octet_seq*)result = io_file_read(
        *(void**)args,
        *(cx_uint32*)((intptr_t)args + sizeof(void*)));
}

void __io_file_readAll(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_octet_seq*)result = io_file_readAll(
        *(void**)args);
}

void __io_file_readLn(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_string*)result = io_file_readLn(
        *(void**)args);
}

void __io_file_readText(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_string*)result = io_file_readText(
        *(void**)args);
}

void __io_file_write(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_uint32*)result = io_file_write(
        *(void**)args,
        *(cx_octet_seq*)((intptr_t)args + sizeof(void*)));
}

void __io_file_writeText(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_uint32*)result = io_file_writeText(
        *(void**)args,
        *(cx_string*)((intptr_t)args + sizeof(void*)));
}
