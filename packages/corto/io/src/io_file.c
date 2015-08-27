/* io_file.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "io.h"

/* $header() */
#include "stdio.h"
/* $end */

/* ::corto::io::file::construct() */
cx_int16 _io_file_construct(io_file _this) {
/* $begin(::corto::io::file::construct) */
    if (_this->name) {\
        /* Special directive, for opening stdout, stdin and stderr */
        if (*_this->name == '#') {
            if (!strcmp(_this->name, "#out")) {
                _this->handle = (cx_word)stdout;
            } else if (!strcmp(_this->name, "#in")) {
                _this->handle = (cx_word)stdin;
            } else if (!strcmp(_this->name, "#err")) {
                _this->handle = (cx_word)stderr;
            } else {
                cx_error("unknown file-directive '%s'", _this->name);
                goto error;
            }
        } else {
            if (!_this->binary) {
                switch(_this->mode) {
                case Io_Read:   _this->handle = (cx_word)fopen(_this->name, "r"); break;
                case Io_Write:  _this->handle = (cx_word)fopen(_this->name, "w"); break;
                case Io_Append: _this->handle = (cx_word)fopen(_this->name, "a"); break;
                default: cx_error("invalid filemode specified."); break;
                }
            } else {
                switch(_this->mode) {
                case Io_Read:   _this->handle = (cx_word)fopen(_this->name, "rb"); break;
                case Io_Write:  _this->handle = (cx_word)fopen(_this->name, "wb"); break;
                case Io_Append: _this->handle = (cx_word)fopen(_this->name, "ab"); break;
                default: cx_error("invalid filemode specified."); break;
                }
            }
            if (!_this->handle) {
                cx_error("failed to open file '%s'", _this->name);
            }
        }
    } else {
        cx_error("invalid filename.");
        goto error;
    }

    return 0;
error:
    return -1;
/* $end */
}

/* ::corto::io::file::destruct() */
cx_void _io_file_destruct(io_file _this) {
/* $begin(::corto::io::file::destruct) */
    if (_this->handle) {
        fclose((FILE*)_this->handle);
    }
/* $end */
}

/* ::corto::io::file::flush() */
cx_void _io_file_flush(io_file _this) {
/* $begin(::corto::io::file::flush) */
    fflush((FILE*)_this->handle);
/* $end */
}

/* ::corto::io::file::read(uint32 bytes) */
cx_octet_seq _io_file_read(io_file _this, cx_uint32 bytes) {
/* $begin(::corto::io::file::read) */
    cx_octet_seq result;

    result.buffer = cx_alloc(bytes);
    result.length = fread(result.buffer, bytes, 1, (FILE*)_this->handle);

    return result;
/* $end */
}

/* ::corto::io::file::readAll() */
cx_octet_seq _io_file_readAll(io_file _this) {
/* $begin(::corto::io::file::readAll) */
    cx_octet_seq result;

    CX_UNUSED(_this);

    result.length = 0;
    result.buffer = NULL;

    cx_trace("io::File::readAll not yet implemented.");

    return result;
/* $end */
}

/* ::corto::io::file::readLn() */
cx_string _io_file_readLn(io_file _this) {
/* $begin(::corto::io::file::readLn) */
    CX_UNUSED(_this);

    cx_trace("io::File::readLn not yet implemented.");

    return NULL;
/* $end */
}

/* ::corto::io::file::readText() */
cx_string _io_file_readText(io_file _this) {
/* $begin(::corto::io::file::readText) */
    CX_UNUSED(_this);

    cx_trace("io::File::readText not yet implemented.");

    return NULL;
/* $end */
}

/* ::corto::io::file::write(sequence{octet,0} data) */
cx_uint32 _io_file_write(io_file _this, cx_octet_seq data) {
/* $begin(::corto::io::file::write) */
    CX_UNUSED(_this);
    CX_UNUSED(data);

    cx_trace("io::File::write not yet implemented.");

    return -1;
/* $end */
}

/* ::corto::io::file::writeText(string txt) */
cx_uint32 _io_file_writeText(io_file _this, cx_string txt) {
/* $begin(::corto::io::file::writeText) */
    return fwrite(txt, strlen(txt), 1, (FILE*)_this->handle);
/* $end */
}
