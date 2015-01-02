/* io.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef io_H
#define io_H

#include "cortex.h"
#include "io__type.h"

#include "io__api.h"

#include "io__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::cortex::io::print(::cortex::lang::string str) */
cx_void io_print(cx_string str);

/* ::cortex::io::println(::cortex::lang::string str) */
cx_void io_println(cx_string str);

/* ::cortex::io::readln() */
cx_string io_readln(void);

#ifdef __cplusplus
}
#endif
#endif

#include "io_file.h"
