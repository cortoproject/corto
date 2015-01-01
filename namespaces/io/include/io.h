/* io.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef io_H
#define io_H

#include "cortex.h"
#include "io__type.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::cortex::io::print(::cortex::lang::string str) */
db_void io_print(db_string str);

/* ::cortex::io::println(::cortex::lang::string str) */
db_void io_println(db_string str);

/* ::cortex::io::readln() */
db_string io_readln(void);

#ifdef __cplusplus
}
#endif
#endif

#include "io_file.h"
