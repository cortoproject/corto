/* locate_self.h
 * This is the main package file. Include this file in other projects.
 * Only modify inside the header-end and body-end sections.
 */

#ifndef LOCATE_SELF_H
#define LOCATE_SELF_H

#include "bake_config.h"

#define LOCATE_SELF_ETC ut_locate("locate_self", NULL, UT_LOCATE_ETC)

/* $header() */
/* Enter additional code here. */
/* $end */

#include "_type.h"
#include "_interface.h"
#include "_load.h"
#include "_binding.h"

#include <locate_self.c>

/* $body() */
/* Enter code that requires types here */
/* $end */

#endif

