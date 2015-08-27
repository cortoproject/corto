/* io__type.h
 *
 * Type definitions for C-language.
 * This file contains generated code. Do not modify!
 */

#ifndef io__type_H
#define io__type_H

#include "corto.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Casting macro's for classes */
#define io_file(o) ((io_file)cx_assertType((cx_type)io_file_o, o))

/* Type definitions */
/* ::corto::io::fileMode */
typedef enum io_fileMode {
    Io_Read = 0,
    Io_Write = 1,
    Io_Append = 2,
    Io_ReadWrite = 3,
    Io_ReadAppend = 4
} io_fileMode;

/*  ::corto::io::file */
CX_CLASS(io_file);

CX_CLASS_DEF(io_file) {
    cx_string name;
    io_fileMode mode;
    cx_bool binary;
    cx_word handle;
};

CX_SEQUENCE(cx_octet_seq, cx_octet,);

#ifdef __cplusplus
}
#endif
#endif

