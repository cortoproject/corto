/* io__api.c
 *
 *  Generated on Sep 13 2014
 *    API convenience functions for C-language.
 *    This file contains generated code. Do not modify!
 */

#include "io__meta.h"
#include "io__api.h"

io_file io_file__new(void) {
    return db_new(db_typedef(io_file_o));
}

io_file io_file__declare(db_object _parent, db_string _name) {
    return db_declare(_parent, _name, db_typedef(io_file_o));
}

int io_file__define(io_file _this, db_string name, io_fileMode mode, db_bool binary) {
    _this->name = (name ? db_strdup(name) : NULL);
    _this->mode = mode;
    _this->binary = binary;
    return db_define(_this);
}

io_file io_file__create(db_string name, io_fileMode mode, db_bool binary) {
    io_file _this;
    _this = db_new(db_typedef(io_file_o));
    _this->name = (name ? db_strdup(name) : NULL);
    _this->mode = mode;
    _this->binary = binary;
    if (db_define(_this)) {
        db_free(_this);
        _this = NULL;
    }
    return _this;
}

db_octet* db_octet_seq__append(db_octet_seq *seq) {
    db_uint32 size;
    seq->length++;
    seq->buffer = db_realloc(seq->buffer, seq->length * (size=db_type_sizeof(db_type(db_octet_o))));
    memset(&seq->buffer[seq->length-1], 0, size);
    return &seq->buffer[seq->length-1];
}

void db_octet_seq__size(db_octet_seq *seq, db_uint32 length) {
    db_uint32 size;
    seq->buffer = db_realloc(seq->buffer, length * (size=db_type_sizeof(db_type(db_octet_o))));
    if (length > seq->length) {
        memset(&seq->buffer[seq->length], 0, size * (length - seq->length));
    }
    seq->length = length;
}

void db_octet_seq__clear(db_octet_seq *seq) {
    db_octet_seq__size(seq, 0);
}

