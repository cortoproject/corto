/* io_file.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef io_file_H
#define io_file_H

#include "corto.h"
#include "io__type.h"
#include "io__api.h"
#include "io__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::corto::io::file::construct() */
cx_int16 _io_file_construct(io_file _this);
#define io_file_construct(_this) _io_file_construct(io_file(_this))

/* ::corto::io::file::destruct() */
cx_void _io_file_destruct(io_file _this);
#define io_file_destruct(_this) _io_file_destruct(io_file(_this))

/* ::corto::io::file::flush() */
cx_void _io_file_flush(io_file _this);
#define io_file_flush(_this) _io_file_flush(io_file(_this))

/* ::corto::io::file::read(uint32 bytes) */
cx_octet_seq _io_file_read(io_file _this, cx_uint32 bytes);
#define io_file_read(_this, bytes) _io_file_read(io_file(_this), bytes)

/* ::corto::io::file::readAll() */
cx_octet_seq _io_file_readAll(io_file _this);
#define io_file_readAll(_this) _io_file_readAll(io_file(_this))

/* ::corto::io::file::readLn() */
cx_string _io_file_readLn(io_file _this);
#define io_file_readLn(_this) _io_file_readLn(io_file(_this))

/* ::corto::io::file::readText() */
cx_string _io_file_readText(io_file _this);
#define io_file_readText(_this) _io_file_readText(io_file(_this))

/* ::corto::io::file::write(sequence{octet,0} data) */
cx_uint32 _io_file_write(io_file _this, cx_octet_seq data);
#define io_file_write(_this, data) _io_file_write(io_file(_this), data)

/* ::corto::io::file::writeText(string txt) */
cx_uint32 _io_file_writeText(io_file _this, cx_string txt);
#define io_file_writeText(_this, txt) _io_file_writeText(io_file(_this), txt)

#ifdef __cplusplus
}
#endif
#endif

