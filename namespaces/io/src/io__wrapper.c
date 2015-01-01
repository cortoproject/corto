/* io__wrapper.c
 *
 * This file contains wrapper functions for ::cortex::io.
 */

#include "io.h"
#include "io__meta.h"

void __io_print(cx_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(result);
    io_print(
        *(cx_string*)args);
}

void __io_println(cx_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(result);
    io_println(
        *(cx_string*)args);
}

void __io_readln(cx_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(args);
    *(cx_string*)result = io_readln(
        );
}

void __io_file_construct(cx_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(cx_int16*)result = io_file_construct(
        *(io_file*)args);
}

void __io_file_destruct(cx_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(result);
    io_file_destruct(
        *(io_file*)args);
}

void __io_file_flush(cx_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(args);
    DB_UNUSED(result);
    io_file_flush(
        *(io_file*)args);
}

void __io_file_read(cx_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(cx_octet_seq*)result = io_file_read(
        *(io_file*)args,
        *(cx_uint32*)((intptr_t)args + sizeof(io_file)));
}

void __io_file_readAll(cx_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(args);
    *(cx_octet_seq*)result = io_file_readAll(
        *(io_file*)args);
}

void __io_file_readLn(cx_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(args);
    *(cx_string*)result = io_file_readLn(
        *(io_file*)args);
}

void __io_file_readText(cx_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(args);
    *(cx_string*)result = io_file_readText(
        *(io_file*)args);
}

void __io_file_write(cx_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(cx_uint32*)result = io_file_write(
        *(io_file*)args,
        *(cx_octet_seq*)((intptr_t)args + sizeof(io_file)));
}

void __io_file_writeText(cx_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(cx_uint32*)result = io_file_writeText(
        *(io_file*)args,
        *(cx_string*)((intptr_t)args + sizeof(io_file)));
}
