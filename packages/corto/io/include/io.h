/* io.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef io_H
#define io_H

#include "corto.h"
#include "io__type.h"
#include "io__api.h"
#include "io__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::corto::io::print(string str) */
cx_void _io_print(cx_string str);
#define io_print(str) _io_print(str)

/* ::corto::io::println(string str) */
cx_void _io_println(cx_string str);
#define io_println(str) _io_println(str)

/* ::corto::io::readln() */
cx_string _io_readln(void);
#define io_readln() _io_readln()

#ifdef __cplusplus
}
#endif
#endif

#include "io_file.h"
