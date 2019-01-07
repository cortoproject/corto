/* create_self_package.h
 * This is the main package file. Include this file in other projects.
 * Only modify inside the header-end and body-end sections.
 */

#ifndef CREATE_SELF_PACKAGE_H
#define CREATE_SELF_PACKAGE_H

#include "bake_config.h"

#define CREATE_SELF_PACKAGE_ETC ut_locate("create_self_package", NULL, UT_LOCATE_ETC)

/* $header() */
/* Enter additional code here. */
/* $end */

#include "_type.h"
#include "_interface.h"
#include "_load.h"
#include "_binding.h"

#include <create_self_package.c>

/* $body() */
/* Enter code that requires types here */
/* $end */

#endif

