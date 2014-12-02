/* io.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef io_H
#define io_H

#include "hyve.h"
#include "io__type.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::hyve::io::print(::hyve::lang::string str) */
db_void io_print(db_string str);

/* ::hyve::io::println(::hyve::lang::string str) */
db_void io_println(db_string str);

/* ::hyve::io::readln() */
db_string io_readln(void);

#ifdef __cplusplus
}
#endif
#endif

#include "io_file.h"
