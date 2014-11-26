/* io_file.h
 *
 *  Generated on Sep  5 2014
 *    This file contains generated code. Do not modify!
 */

#ifndef io_file_H
#define io_file_H

#include "hyve.h"
#include "io__type.h"

#ifdef __cplusplus
extern "C" {
#endif

/* callback ::hyve::lang::class::construct(lang::object object) -> ::hyve::io::file::construct(::hyve::io::file object) */
db_int16 io_file_construct(io_file object);

/* callback ::hyve::lang::class::destruct(lang::object object) -> ::hyve::io::file::destruct(::hyve::io::file object) */
db_void io_file_destruct(io_file object);

/* ::hyve::io::file::flush() */
db_void io_file_flush(io_file _this);

/* ::hyve::io::file::read(::hyve::lang::uint32 bytes) */
db_octet_seq io_file_read(io_file _this, db_uint32 bytes);

/* ::hyve::io::file::readAll() */
db_octet_seq io_file_readAll(io_file _this);

/* ::hyve::io::file::readLn() */
db_string io_file_readLn(io_file _this);

/* ::hyve::io::file::readText() */
db_string io_file_readText(io_file _this);

/* ::hyve::io::file::write(::hyve::lang::sequence{::hyve::lang::octet,0} data) */
db_uint32 io_file_write(io_file _this, db_octet_seq data);

/* ::hyve::io::file::writeText(::hyve::lang::string txt) */
db_uint32 io_file_writeText(io_file _this, db_string txt);

#ifdef __cplusplus
}
#endif
#endif

