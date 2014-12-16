/* db_dispatcher.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef db_dispatcher_H
#define db_dispatcher_H

#include "hyve.h"
#include "db__type.h"

#include "db__api.h"

#include "db__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* virtual ::hyve::lang::dispatcher::getEvent(lang::observer observer,lang::object me,lang::object observable,lang::object src) */
db_observableEvent db_dispatcher_getEvent(db_dispatcher _this, db_observer observer, db_object me, db_object observable, db_object src);

/* ::hyve::lang::dispatcher::getEvent(lang::observer observer,lang::object me,lang::object observable,lang::object src) */
db_observableEvent db_dispatcher_getEvent_v(db_dispatcher _this, db_observer observer, db_object me, db_object observable, db_object src);

/* virtual ::hyve::lang::dispatcher::post(lang::event event) */
void db_dispatcher_post(db_dispatcher _this, db_event event);

/* ::hyve::lang::dispatcher::post(lang::event event) */
db_void db_dispatcher_post_v(db_dispatcher _this, db_event event);

#ifdef __cplusplus
}
#endif
#endif

