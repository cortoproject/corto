/* io__api.h
 *
 *  Generated on Sep 13 2014
 *    API convenience functions for C-language.
 *    This file contains generated code. Do not modify!
 */

#ifndef io__API_H
#define io__API_H

#include "io__type.h"
#include "hyve.h"

#ifdef __cplusplus
extern "C" {
#endif
/* ::hyve::io::file */
io_file io_file__new(void);
io_file io_file__declare(db_object _parent, db_string _name);
int io_file__define(io_file _this, db_string name, io_fileMode mode, db_bool binary);
io_file io_file__create(db_string name, io_fileMode mode, db_bool binary);


/* <0x9b81758> */
#define db_octet_seq__foreach(seq, elem) \
    db_uint32 elem##_iter;\
    db_octet *elem;\
    for(elem##_iter=0; elem##_iter<seq.length; elem##_iter++) {\
        elem = &seq.buffer[elem##_iter];

db_octet* db_octet_seq__append(db_octet_seq *seq);
void db_octet_seq__size(db_octet_seq *seq, db_uint32 length);
void db_octet_seq__clear(db_octet_seq *seq);

#ifdef __cplusplus
}
#endif
#endif

