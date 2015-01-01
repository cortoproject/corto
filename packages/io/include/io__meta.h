/* io__meta.h
 *
 * Loads objects in database.
 * This file contains generated code. Do not modify!
 */

#ifndef io_META_H
#define io_META_H

#include "cortex.h"

#include "io__type.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::cortex */
extern cx_object _o;

/* ::cortex::io */
extern cx_void (*io_o);

/* ::cortex::io::err */
extern io_file io_err_o;

/* ::cortex::io::file */
extern cx_class io_file_o;

/* ::cortex::io::file::binary */
extern cx_member io_file_binary_o;

/* ::cortex::io::file::construct(::cortex::io::file object) */
extern cx_callback io_file_construct_o;

/* ::cortex::io::file::destruct(::cortex::io::file object) */
extern cx_callback io_file_destruct_o;

/* ::cortex::io::file::flush() */
extern cx_method io_file_flush_o;

/* ::cortex::io::file::handle */
extern cx_member io_file_handle_o;

/* ::cortex::io::file::mode */
extern cx_member io_file_mode_o;

/* ::cortex::io::file::name */
extern cx_member io_file_name_o;

/* ::cortex::io::file::read(::cortex::lang::uint32 bytes) */
extern cx_method io_file_read_o;

/* ::cortex::io::file::readAll() */
extern cx_method io_file_readAll_o;

/* ::cortex::io::file::readLn() */
extern cx_method io_file_readLn_o;

/* ::cortex::io::file::readText() */
extern cx_method io_file_readText_o;

/* ::cortex::io::file::write(::cortex::lang::sequence{::cortex::lang::octet,0} data) */
extern cx_method io_file_write_o;

/* ::cortex::io::file::writeText(::cortex::lang::string txt) */
extern cx_method io_file_writeText_o;

/* ::cortex::io::fileMode */
extern cx_enum io_fileMode_o;

/* ::cortex::io::fileMode::Append */
extern cx_constant (*io_fileMode_Append_o);

/* ::cortex::io::fileMode::Read */
extern cx_constant (*io_fileMode_Read_o);

/* ::cortex::io::fileMode::ReadAppend */
extern cx_constant (*io_fileMode_ReadAppend_o);

/* ::cortex::io::fileMode::ReadWrite */
extern cx_constant (*io_fileMode_ReadWrite_o);

/* ::cortex::io::fileMode::Write */
extern cx_constant (*io_fileMode_Write_o);

/* ::cortex::io::in */
extern io_file io_in_o;

/* ::cortex::io::out */
extern io_file io_out_o;

/* ::cortex::io::print(::cortex::lang::string str) */
extern cx_function io_print_o;

/* ::cortex::io::println(::cortex::lang::string str) */
extern cx_function io_println_o;

/* ::cortex::io::readln() */
extern cx_function io_readln_o;

int io_load(void);
#ifdef __cplusplus
}
#endif
#endif

