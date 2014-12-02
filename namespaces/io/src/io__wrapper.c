/* io__wrapper.c
 *
 * This file contains wrapper functions for ::hyve::io.
 */

#include "io.h"
#include "io__meta.h"

void __io_print(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(result);
    io_print(
        *(db_string*)args);
}

void __io_println(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(result);
    io_println(
        *(db_string*)args);
}

void __io_readln(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(args);
    *(db_string*)result = io_readln(
        );
}

void __io_file_construct(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = io_file_construct(
        *(io_file*)args);
}

void __io_file_destruct(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(result);
    io_file_destruct(
        *(io_file*)args);
}

void __io_file_flush(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(args);
    DB_UNUSED(result);
    io_file_flush(
        *(io_file*)args);
}

void __io_file_read(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_octet_seq*)result = io_file_read(
        *(io_file*)args,
        *(db_uint32*)((intptr_t)args + sizeof(io_file)));
}

void __io_file_readAll(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(args);
    *(db_octet_seq*)result = io_file_readAll(
        *(io_file*)args);
}

void __io_file_readLn(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(args);
    *(db_string*)result = io_file_readLn(
        *(io_file*)args);
}

void __io_file_readText(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(args);
    *(db_string*)result = io_file_readText(
        *(io_file*)args);
}

void __io_file_write(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_uint32*)result = io_file_write(
        *(io_file*)args,
        *(db_octet_seq*)((intptr_t)args + sizeof(io_file)));
}

void __io_file_writeText(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_uint32*)result = io_file_writeText(
        *(io_file*)args,
        *(db_string*)((intptr_t)args + sizeof(io_file)));
}
