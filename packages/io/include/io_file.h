/* io_file.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef io_file_H
#define io_file_H

#include "cortex.h"
#include "io__type.h"

#include "io__api.h"

#include "io__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::cortex::io::file::construct() */
cx_int16 io_file_construct(io_file _this);

/* ::cortex::io::file::destruct() */
cx_void io_file_destruct(io_file _this);

/* ::cortex::io::file::flush() */
cx_void io_file_flush(io_file _this);

/* ::cortex::io::file::read(uint32 bytes) */
cx_octet_seq io_file_read(io_file _this, cx_uint32 bytes);

/* ::cortex::io::file::readAll() */
cx_octet_seq io_file_readAll(io_file _this);

/* ::cortex::io::file::readLn() */
cx_string io_file_readLn(io_file _this);

/* ::cortex::io::file::readText() */
cx_string io_file_readText(io_file _this);

/* ::cortex::io::file::write(sequence{octet,0} data) */
cx_uint32 io_file_write(io_file _this, cx_octet_seq data);

/* ::cortex::io::file::writeText(string txt) */
cx_uint32 io_file_writeText(io_file _this, cx_string txt);

#ifdef __cplusplus
}
#endif
#endif

