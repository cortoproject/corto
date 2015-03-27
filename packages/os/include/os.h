/* os.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef os_H
#define os_H

#include "cortex.h"
#include "os__type.h"

#include "os__api.h"

#include "os__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::cortex::os::exit(bool success) */
cx_void os_exit(cx_bool success);

/* ::cortex::os::sleep(uint32 sec,uint32 nsec) */
cx_void os_sleep(cx_uint32 sec, cx_uint32 nsec);

/* ::cortex::os::system(string cmd) */
cx_void os_system(cx_string cmd);

#ifdef __cplusplus
}
#endif
#endif

#include "os_thread.h"
#include "os_time.h"
#include "os_timer.h"
