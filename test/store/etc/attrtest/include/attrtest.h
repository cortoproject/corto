/* attrtest.h
 * This is the main package file. Include this file in other projects.
 * Only modify inside the header-end and body-end sections.
 */

#ifndef ATTRTEST_H
#define ATTRTEST_H

#include "bake_config.h"

#define ATTRTEST_ETC ut_locate("attrtest", NULL, UT_LOCATE_ETC)

/* $header() */
/* Enter additional code here. */
/* $end */

#include "_type.h"
#include "_interface.h"
#include "_load.h"
#include "_binding.h"

#include <attrtest.c>

/* $body() */
/* Enter code that requires types here */
/* $end */

#endif

