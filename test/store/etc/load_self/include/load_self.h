/* load_self.h
 * This is the main package file. Include this file in other projects.
 * Only modify inside the header-end and body-end sections.
 */

#ifndef LOAD_SELF_H
#define LOAD_SELF_H

#include "bake_config.h"

#define LOAD_SELF_ETC ut_locate("load_self", NULL, UT_LOCATE_ETC)

/* $header() */
/* Enter additional code here. */
/* $end */

#include "_type.h"
#include "_interface.h"
#include "_load.h"
#include "_binding.h"

#include <load_self.c>

/* $body() */
/* Enter code that requires types here */
/* $end */

#endif

