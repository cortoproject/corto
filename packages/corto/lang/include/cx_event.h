/* cx_event.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef corto_lang_event_H
#define corto_lang_event_H

#include "corto.h"
#ifdef corto_lang_LIB
#include "cx__type.h"
#include "cx__api.h"
#include "cx__meta.h"
#else
#include "corto/lang/cx__type.h"
#include "corto/lang/cx__api.h"
#include "corto/lang/cx__meta.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* virtual ::corto::lang::event::handle() */
void cx_event_handle(cx_event _this);

/* ::corto::lang::event::handle() */
cx_void _cx_event_handle_v(cx_event _this);
#define cx_event_handle_v(_this) _cx_event_handle_v(cx_event(_this))

/* ::corto::lang::event::uniqueKind() */
cx_int16 _cx_event_uniqueKind(void);
#define cx_event_uniqueKind() _cx_event_uniqueKind()

#ifdef __cplusplus
}
#endif
#endif

