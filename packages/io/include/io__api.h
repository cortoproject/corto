/* io__api.h
 *
 *    API convenience functions for C-language.
 *    This file contains generated code. Do not modify!
 */

#ifndef io__API_H
#define io__API_H

#include "io__type.h"
#include "cortex.h"

#ifdef __cplusplus
extern "C" {
#endif
/* ::cortex::io::file */
io_file io_file__new(void);
io_file io_file__declare(cx_object _parent, cx_string _name);
int io_file__define(io_file _this, cx_string name, io_fileMode mode, cx_bool binary);
io_file io_file__create(cx_string name, io_fileMode mode, cx_bool binary);


/* <0x9a27b30> */
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

