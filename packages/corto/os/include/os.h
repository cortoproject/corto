/* os.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef os_H
#define os_H

#include "corto.h"
#include "os__type.h"
#include "os__api.h"
#include "os__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::corto::os::exit(bool success) */
cx_void _os_exit(cx_bool success);
#define os_exit(success) _os_exit(success)

/* ::corto::os::sleep(uint32 sec,uint32 nsec) */
cx_void _os_sleep(cx_uint32 sec, cx_uint32 nsec);
#define os_sleep(sec, nsec) _os_sleep(sec, nsec)

/* ::corto::os::system(string cmd) */
cx_void _os_system(cx_string cmd);
#define os_system(cmd) _os_system(cmd)

#ifdef __cplusplus
}
#endif
#endif

#include "os_thread.h"
#include "os_time.h"
#include "os_timer.h"
