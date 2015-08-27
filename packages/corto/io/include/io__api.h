/* io__api.h
 *
 * API convenience functions for C-language.
 * This file contains generated code. Do not modify!
 */

#ifndef io__API_H
#define io__API_H

#include "io__type.h"
#include "corto.h"

#ifdef __cplusplus
extern "C" {
#endif
/* ::corto::io::file */
io_file io_file__create(cx_string name, io_fileMode mode, cx_bool binary);
io_file io_file__createChild(cx_object _parent, cx_string _name, cx_string name, io_fileMode mode, cx_bool binary);

io_file io_file__declare(void);
io_file io_file__declareChild(cx_object _parent, cx_string _name);
cx_int16 io_file__define(io_file _this, cx_string name, io_fileMode mode, cx_bool binary);
void io_file__update(io_file _this, cx_string name, io_fileMode mode, cx_bool binary);
void io_file__set(io_file _this, cx_string name, io_fileMode mode, cx_bool binary);
cx_string io_file__str(io_file value);
io_file io_file__fromStr(io_file value, cx_string str);
cx_int16 io_file__copy(io_file *dst, io_file src);
cx_int16 io_file__compare(io_file dst, io_file src);

/* ::corto::io::fileMode */
io_fileMode* io_fileMode__create(void);
io_fileMode* io_fileMode__createChild(cx_object _parent, cx_string _name);

io_fileMode* io_fileMode__declare(void);
io_fileMode* io_fileMode__declareChild(cx_object _parent, cx_string _name);
cx_int16 io_fileMode__define(io_fileMode* _this, io_fileMode value);
void io_fileMode__update(io_fileMode* _this, io_fileMode value);
void io_fileMode__set(io_fileMode* _this, io_fileMode value);
cx_string io_fileMode__str(io_fileMode value);
io_fileMode* io_fileMode__fromStr(io_fileMode* value, cx_string str);
cx_int16 io_fileMode__copy(io_fileMode* *dst, io_fileMode* src);
cx_int16 io_fileMode__compare(io_fileMode* dst, io_fileMode* src);

cx_int16 io_fileMode__init(io_fileMode* value);
cx_int16 io_fileMode__deinit(io_fileMode* value);


/* <0x7fb9d852ab08> */
#define cx_octet_seq__foreach(seq, elem) \
    cx_uint32 elem##_iter;\
    cx_octet *elem;\
    for(elem##_iter=0; elem##_iter<seq.length; elem##_iter++) {\
        elem = &seq.buffer[elem##_iter];

cx_octet* cx_octet_seq__append(cx_octet_seq *seq);
void cx_octet_seq__size(cx_octet_seq *seq, cx_uint32 length);
void cx_octet_seq__clear(cx_octet_seq *seq);

#ifdef __cplusplus
}
#endif
#endif

