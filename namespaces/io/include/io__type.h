/* io__type.h
 *
 *  Generated on Sep  5 2014
 *    Type-definitions for C-language.
 *    This file contains generated code. Do not modify!
 */

#ifndef io__type_H
#define io__type_H

#include "hyve.h"
#ifdef __cplusplus
extern "C" {
#endif

/* Casting macro's for classes */
#define io_file(o) ((io_file)o)

/* Type definitions */

/* ::hyve::io::fileMode */
typedef enum io_fileMode {
    IO_Read = 0,
    IO_Write = 1,
    IO_Append = 2,
    IO_ReadWrite = 3,
    IO_ReadAppend = 4
} io_fileMode;

/*  ::hyve::io::file */
DB_CLASS(io_file);
DB_CLASS_DEF(io_file) {
    db_string name;
    io_fileMode mode;
    db_bool binary;
    db_word handle;
};
DB_SEQUENCE(db_octet_seq, db_octet,);

#ifdef __cplusplus
}
#endif
#endif

