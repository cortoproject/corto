/* io__meta.h
 *
 * Loads objects in object store.
 * This file contains generated code. Do not modify!
 */

#ifndef io_META_H
#define io_META_H

#include "corto.h"

#include "io__type.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::corto */
extern cx_package _o;

/* ::corto::io */
extern cx_package io_o;

/* ::corto::io::err */
extern io_file io_err_o;

/* ::corto::io::file */
extern cx_class io_file_o;

/* ::corto::io::file::binary */
extern cx_member io_file_binary_o;

/* ::corto::io::file::construct() */
extern cx_method io_file_construct_o;

/* ::corto::io::file::destruct() */
extern cx_method io_file_destruct_o;

/* ::corto::io::file::flush() */
extern cx_method io_file_flush_o;

/* ::corto::io::file::handle */
extern cx_member io_file_handle_o;

/* ::corto::io::file::mode */
extern cx_member io_file_mode_o;

/* ::corto::io::file::name */
extern cx_member io_file_name_o;

/* ::corto::io::file::read(uint32 bytes) */
extern cx_method io_file_read_o;

/* ::corto::io::file::readAll() */
extern cx_method io_file_readAll_o;

/* ::corto::io::file::readLn() */
extern cx_method io_file_readLn_o;

/* ::corto::io::file::readText() */
extern cx_method io_file_readText_o;

/* ::corto::io::file::write(sequence{octet,0} data) */
extern cx_method io_file_write_o;

/* ::corto::io::file::writeText(string txt) */
extern cx_method io_file_writeText_o;

/* ::corto::io::fileMode */
extern cx_enum io_fileMode_o;

/* ::corto::io::fileMode::Append */
extern cx_constant (*io_fileMode_Append_o);

/* ::corto::io::fileMode::Read */
extern cx_constant (*io_fileMode_Read_o);

/* ::corto::io::fileMode::ReadAppend */
extern cx_constant (*io_fileMode_ReadAppend_o);

/* ::corto::io::fileMode::ReadWrite */
extern cx_constant (*io_fileMode_ReadWrite_o);

/* ::corto::io::fileMode::Write */
extern cx_constant (*io_fileMode_Write_o);

/* ::corto::io::in */
extern io_file io_in_o;

/* ::corto::io::out */
extern io_file io_out_o;

/* ::corto::io::print(string str) */
extern cx_function io_print_o;

/* ::corto::io::println(string str) */
extern cx_function io_println_o;

/* ::corto::io::readln() */
extern cx_function io_readln_o;

int io_load(void);
#ifdef __cplusplus
}
#endif
#endif

