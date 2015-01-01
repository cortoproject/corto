/* io_file.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "io.h"
#include "io__meta.h"

/* $header() */
#include "stdio.h"
/* $end */

/* callback ::cortex::lang::class::construct(lang::object object) -> ::cortex::io::file::construct(::cortex::io::file object) */
db_int16 io_file_construct(io_file object) {
/* $begin(::cortex::io::file::construct) */
    if (object->name) {\
        /* Special directive, for opening stdout, stdin and stderr */
        if (*object->name == '#') {
            if (!strcmp(object->name, "#out")) {
                object->handle = (db_word)stdout;
            } else if (!strcmp(object->name, "#in")) {
                object->handle = (db_word)stdin;
            } else if (!strcmp(object->name, "#err")) {
                object->handle = (db_word)stderr;
            } else {
                db_error("unknown file-directive '%s'", object->name);
                goto error;
            }
        } else {
            if (!object->binary) {
                switch(object->mode) {
                case IO_Read:   object->handle = (db_word)fopen(object->name, "r"); break;
                case IO_Write:  object->handle = (db_word)fopen(object->name, "w"); break;
                case IO_Append: object->handle = (db_word)fopen(object->name, "a"); break;
                default: db_error("invalid filemode specified."); break;
                }
            } else {
                switch(object->mode) {
                case IO_Read:   object->handle = (db_word)fopen(object->name, "rb"); break;
                case IO_Write:  object->handle = (db_word)fopen(object->name, "wb"); break;
                case IO_Append: object->handle = (db_word)fopen(object->name, "ab"); break;
                default: db_error("invalid filemode specified."); break;
                }
            }
            if (!object->handle) {
                db_error("failed to open file '%s'", object->name);
            }
        }
    } else {
        db_error("invalid filename.");
        goto error;
    }

    return 0;
error:
    return -1;
/* $end */
}

/* callback ::cortex::lang::class::destruct(lang::object object) -> ::cortex::io::file::destruct(::cortex::io::file object) */
db_void io_file_destruct(io_file object) {
/* $begin(::cortex::io::file::destruct) */
    if (object->handle) {
        fclose((FILE*)object->handle);
    }
/* $end */
}

/* ::cortex::io::file::flush() */
db_void io_file_flush(io_file _this) {
/* $begin(::cortex::io::file::flush) */
    fflush((FILE*)_this->handle);
/* $end */
}

/* ::cortex::io::file::read(::cortex::lang::uint32 bytes) */
db_octet_seq io_file_read(io_file _this, db_uint32 bytes) {
/* $begin(::cortex::io::file::read) */
	db_octet_seq result;

    result.buffer = db_malloc(bytes);
    result.length = fread(result.buffer, bytes, 1, (FILE*)_this->handle);

    return result;
/* $end */
}

/* ::cortex::io::file::readAll() */
db_octet_seq io_file_readAll(io_file _this) {
/* $begin(::cortex::io::file::readAll) */
	db_octet_seq result;

	DB_UNUSED(_this);

	result.length = 0;
	result.buffer = NULL;

    db_trace("io::File::readAll not yet implemented.");

    return result;
/* $end */
}

/* ::cortex::io::file::readLn() */
db_string io_file_readLn(io_file _this) {
/* $begin(::cortex::io::file::readLn) */
	DB_UNUSED(_this);

    db_trace("io::File::readLn not yet implemented.");

	return NULL;
/* $end */
}

/* ::cortex::io::file::readText() */
db_string io_file_readText(io_file _this) {
/* $begin(::cortex::io::file::readText) */
	DB_UNUSED(_this);

    db_trace("io::File::readText not yet implemented.");

	return NULL;
/* $end */
}

/* ::cortex::io::file::write(::cortex::lang::sequence{::cortex::lang::octet,0} data) */
db_uint32 io_file_write(io_file _this, db_octet_seq data) {
/* $begin(::cortex::io::file::write) */
    DB_UNUSED(_this);
    DB_UNUSED(data);

    db_trace("io::File::write not yet implemented.");

    return -1;
/* $end */
}

/* ::cortex::io::file::writeText(::cortex::lang::string txt) */
db_uint32 io_file_writeText(io_file _this, db_string txt) {
/* $begin(::cortex::io::file::writeText) */
    return fwrite(txt, strlen(txt), 1, (FILE*)_this->handle);
/* $end */
}
