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
extern db_object _o;

/* ::cortex::io */
extern db_void (*io_o);

/* ::cortex::io::err */
extern io_file io_err_o;

/* ::cortex::io::file */
extern db_class io_file_o;

/* ::cortex::io::file::binary */
extern db_member io_file_binary_o;

/* ::cortex::io::file::construct(::cortex::io::file object) */
extern db_callback io_file_construct_o;

/* ::cortex::io::file::destruct(::cortex::io::file object) */
extern db_callback io_file_destruct_o;

/* ::cortex::io::file::flush() */
extern db_method io_file_flush_o;

/* ::cortex::io::file::handle */
extern db_member io_file_handle_o;

/* ::cortex::io::file::mode */
extern db_member io_file_mode_o;

/* ::cortex::io::file::name */
extern db_member io_file_name_o;

/* ::cortex::io::file::read(::cortex::lang::uint32 bytes) */
extern db_method io_file_read_o;

/* ::cortex::io::file::readAll() */
extern db_method io_file_readAll_o;

/* ::cortex::io::file::readLn() */
extern db_method io_file_readLn_o;

/* ::cortex::io::file::readText() */
extern db_method io_file_readText_o;

/* ::cortex::io::file::write(::cortex::lang::sequence{::cortex::lang::octet,0} data) */
extern db_method io_file_write_o;

/* ::cortex::io::file::writeText(::cortex::lang::string txt) */
extern db_method io_file_writeText_o;

/* ::cortex::io::fileMode */
extern db_enum io_fileMode_o;

/* ::cortex::io::fileMode::Append */
extern db_constant (*io_fileMode_Append_o);

/* ::cortex::io::fileMode::Read */
extern db_constant (*io_fileMode_Read_o);

/* ::cortex::io::fileMode::ReadAppend */
extern db_constant (*io_fileMode_ReadAppend_o);

/* ::cortex::io::fileMode::ReadWrite */
extern db_constant (*io_fileMode_ReadWrite_o);

/* ::cortex::io::fileMode::Write */
extern db_constant (*io_fileMode_Write_o);

/* ::cortex::io::in */
extern io_file io_in_o;

/* ::cortex::io::out */
extern io_file io_out_o;

/* ::cortex::io::print(::cortex::lang::string str) */
extern db_function io_print_o;

/* ::cortex::io::println(::cortex::lang::string str) */
extern db_function io_println_o;

/* ::cortex::io::readln() */
extern db_function io_readln_o;

int io_load(void);
#ifdef __cplusplus
}
#endif
#endif

