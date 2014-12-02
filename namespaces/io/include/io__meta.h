/* io__meta.h
 *
 * Loads objects in database.
 * This file contains generated code. Do not modify!
 */

#ifndef io_META_H
#define io_META_H

#include "hyve.h"

#include "io__type.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::hyve */
extern db_object _o;

/* ::hyve::io */
extern db_void (*io_o);

/* ::hyve::io::err */
extern io_file io_err_o;

/* ::hyve::io::file */
extern db_class io_file_o;

/* ::hyve::io::file::binary */
extern db_member io_file_binary_o;

/* ::hyve::io::file::construct(::hyve::io::file object) */
extern db_callback io_file_construct_o;

/* ::hyve::io::file::destruct(::hyve::io::file object) */
extern db_callback io_file_destruct_o;

/* ::hyve::io::file::flush() */
extern db_method io_file_flush_o;

/* ::hyve::io::file::handle */
extern db_member io_file_handle_o;

/* ::hyve::io::file::mode */
extern db_member io_file_mode_o;

/* ::hyve::io::file::name */
extern db_member io_file_name_o;

/* ::hyve::io::file::read(::hyve::lang::uint32 bytes) */
extern db_method io_file_read_o;

/* ::hyve::io::file::readAll() */
extern db_method io_file_readAll_o;

/* ::hyve::io::file::readLn() */
extern db_method io_file_readLn_o;

/* ::hyve::io::file::readText() */
extern db_method io_file_readText_o;

/* ::hyve::io::file::write(::hyve::lang::sequence{::hyve::lang::octet,0} data) */
extern db_method io_file_write_o;

/* ::hyve::io::file::writeText(::hyve::lang::string txt) */
extern db_method io_file_writeText_o;

/* ::hyve::io::fileMode */
extern db_enum io_fileMode_o;

/* ::hyve::io::fileMode::Append */
extern db_constant (*io_fileMode_Append_o);

/* ::hyve::io::fileMode::Read */
extern db_constant (*io_fileMode_Read_o);

/* ::hyve::io::fileMode::ReadAppend */
extern db_constant (*io_fileMode_ReadAppend_o);

/* ::hyve::io::fileMode::ReadWrite */
extern db_constant (*io_fileMode_ReadWrite_o);

/* ::hyve::io::fileMode::Write */
extern db_constant (*io_fileMode_Write_o);

/* ::hyve::io::in */
extern io_file io_in_o;

/* ::hyve::io::out */
extern io_file io_out_o;

/* ::hyve::io::print(::hyve::lang::string str) */
extern db_function io_print_o;

/* ::hyve::io::println(::hyve::lang::string str) */
extern db_function io_println_o;

/* ::hyve::io::readln() */
extern db_function io_readln_o;

int io_load(void);
#ifdef __cplusplus
}
#endif
#endif

