/* tier1.h
 * This is the main package file. Include this file in other projects.
 * Only modify inside the header-end and body-end sections.
 */

#ifndef TIER1_H
#define TIER1_H

#include "bake_config.h"

#define TIER1_ETC ut_locate("tier1", NULL, UT_LOCATE_ETC)

/* $header() */
/* Enter additional code here. */
/* $end */

#include "_type.h"
#include "_interface.h"
#include "_load.h"
#include "_binding.h"

#include <tier1.c>

/* $body() */
/* Enter code that requires types here */
/* $end */

#endif

