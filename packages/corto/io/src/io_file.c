/* $CORTO_GENERATED
 *
 * io_file.c
 *
 * Code written between the begin and end tags will be preserved when the
 * file is regenerated.
 */

#include "io.h"

/* $header() */
#include "stdio.h"
/* $end */

corto_int16 _io_file_construct(io_file this) {
/* $begin(::corto::io::file::construct) */
    if (this->name) {
        /* Special directive, for opening stdout, stdin and stderr */
        if (*this->name == '#') {
            if (!strcmp(this->name, "#out")) {
                this->handle = (corto_word)stdout;
            } else if (!strcmp(this->name, "#in")) {
                this->handle = (corto_word)stdin;
            } else if (!strcmp(this->name, "#err")) {
                this->handle = (corto_word)stderr;
            } else {
                corto_error("unknown file-directive '%s'", this->name);
                goto error;
            }
        } else {
            if (!this->binary) {
                switch(this->mode) {
                case Io_Read:   this->handle = (corto_word)fopen(this->name, "r"); break;
                case Io_Write:  this->handle = (corto_word)fopen(this->name, "w"); break;
                case Io_Append: this->handle = (corto_word)fopen(this->name, "a"); break;
                default: corto_error("invalid filemode specified."); break;
                }
            } else {
                switch(this->mode) {
                case Io_Read:   this->handle = (corto_word)fopen(this->name, "rb"); break;
                case Io_Write:  this->handle = (corto_word)fopen(this->name, "wb"); break;
                case Io_Append: this->handle = (corto_word)fopen(this->name, "ab"); break;
                default: corto_error("invalid filemode specified."); break;
                }
            }
            if (!this->handle) {
                corto_error("failed to open file '%s'", this->name);
            }
        }
    } else {
        corto_error("invalid filename.");
        goto error;
    }

    return 0;
error:
    return -1;
/* $end */
}

corto_void _io_file_destruct(io_file this) {
/* $begin(::corto::io::file::destruct) */
    if (this->handle) {
        fclose((FILE*)this->handle);
    }
/* $end */
}

corto_void _io_file_flush(io_file this) {
/* $begin(::corto::io::file::flush) */
    fflush((FILE*)this->handle);
/* $end */
}

corto_octetSeq _io_file_read(io_file this, corto_uint32 bytes) {
/* $begin(::corto::io::file::read) */
    corto_octetSeq result;

    result.buffer = corto_alloc(bytes);
    result.length = fread(result.buffer, bytes, 1, (FILE*)this->handle);

    return result;
/* $end */
}

corto_octetSeq _io_file_readAll(io_file this) {
/* $begin(::corto::io::file::readAll) */
    corto_octetSeq result;

    CORTO_UNUSED(this);

    result.length = 0;
    result.buffer = NULL;

    corto_trace("io::File::readAll not yet implemented.");

    return result;
/* $end */
}

corto_string _io_file_readLn(io_file this) {
/* $begin(::corto::io::file::readLn) */
    CORTO_UNUSED(this);

    corto_trace("io::File::readLn not yet implemented.");

    return NULL;
/* $end */
}

corto_string _io_file_readText(io_file this) {
/* $begin(::corto::io::file::readText) */
    CORTO_UNUSED(this);

    corto_trace("io::File::readText not yet implemented.");

    return NULL;
/* $end */
}

corto_uint32 _io_file_write(io_file this, corto_octetSeq data) {
/* $begin(::corto::io::file::write) */
    CORTO_UNUSED(this);
    CORTO_UNUSED(data);

    corto_trace("io::File::write not yet implemented.");

    return -1;
/* $end */
}

corto_uint32 _io_file_writeText(io_file this, corto_string txt) {
/* $begin(::corto::io::file::writeText) */
    return fwrite(txt, strlen(txt), 1, (FILE*)this->handle);
/* $end */
}
