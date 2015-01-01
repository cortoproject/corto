/* io_file.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef io_file_H
#define io_file_H

#include "cortex.h"
#include "io__type.h"

#ifdef __cplusplus
extern "C" {
#endif

/* callback ::cortex::lang::class::construct(lang::object object) -> ::cortex::io::file::construct(::cortex::io::file object) */
db_int16 io_file_construct(io_file object);

/* callback ::cortex::lang::class::destruct(lang::object object) -> ::cortex::io::file::destruct(::cortex::io::file object) */
db_void io_file_destruct(io_file object);

/* ::cortex::io::file::flush() */
db_void io_file_flush(io_file _this);

/* ::cortex::io::file::read(::cortex::lang::uint32 bytes) */
db_octet_seq io_file_read(io_file _this, db_uint32 bytes);

/* ::cortex::io::file::readAll() */
db_octet_seq io_file_readAll(io_file _this);

/* ::cortex::io::file::readLn() */
db_string io_file_readLn(io_file _this);

/* ::cortex::io::file::readText() */
db_string io_file_readText(io_file _this);

/* ::cortex::io::file::write(::cortex::lang::sequence{::cortex::lang::octet,0} data) */
db_uint32 io_file_write(io_file _this, db_octet_seq data);

/* ::cortex::io::file::writeText(::cortex::lang::string txt) */
db_uint32 io_file_writeText(io_file _this, db_string txt);

#ifdef __cplusplus
}
#endif
#endif

