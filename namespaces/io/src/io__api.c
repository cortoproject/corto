/* io__api.c
 *
 *  Generated on Dec  1 2014
 *    API convenience functions for C-language.
 *    This file contains generated code. Do not modify!
 */

#include "io__meta.h"
#include "io__api.h"

io_file io_file__new(void) {
    return cx_new(cx_typedef(io_file_o));
}

io_file io_file__declare(cx_object _parent, cx_string _name) {
    return cx_declare(_parent, _name, cx_typedef(io_file_o));
}

int io_file__define(io_file _this, cx_string name, io_fileMode mode, cx_bool binary) {
    _this->name = (name ? cx_strdup(name) : NULL);
    _this->mode = mode;
    _this->binary = binary;
    return cx_define(_this);
}

io_file io_file__create(cx_string name, io_fileMode mode, cx_bool binary) {
    io_file _this;
    _this = cx_new(cx_typedef(io_file_o));
    _this->name = (name ? cx_strdup(name) : NULL);
    _this->mode = mode;
    _this->binary = binary;
    if (cx_define(_this)) {
        cx_free(_this);
        _this = NULL;
    }
    return _this;
}

cx_octet* cx_octet_seq__append(cx_octet_seq *seq) {
    cx_uint32 size;
    seq->length++;
    seq->buffer = cx_realloc(seq->buffer, seq->length * (size=cx_type_sizeof(cx_type(cx_octet_o))));
    memset(&seq->buffer[seq->length-1], 0, size);
    return &seq->buffer[seq->length-1];
}

void cx_octet_seq__size(cx_octet_seq *seq, cx_uint32 length) {
    cx_uint32 size;
    seq->buffer = cx_realloc(seq->buffer, length * (size=cx_type_sizeof(cx_type(cx_octet_o))));
    if (length > seq->length) {
        memset(&seq->buffer[seq->length], 0, size * (length - seq->length));
    }
    seq->length = length;
}

void cx_octet_seq__clear(cx_octet_seq *seq) {
    cx_octet_seq__size(seq, 0);
}

