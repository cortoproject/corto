/* db_observer.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef db_observer_H
#define db_observer_H

#include "cortex.h"
#include "db__type.h"

#include "db__api.h"

#include "db__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* callback ::cortex::lang::procedure::bind(lang::object object) -> ::cortex::lang::observer::bind(lang::observer object) */
db_int16 db_observer_bind(db_observer object);

/* callback ::cortex::lang::type::init(lang::object object) -> ::cortex::lang::observer::init(lang::observer object) */
db_int16 db_observer_init(db_observer object);

/* ::cortex::lang::observer::listen(lang::object observable,lang::object me) */
db_int16 db_observer_listen(db_observer _this, db_object observable, db_object me);

/* ::cortex::lang::observer::setDispatcher(lang::dispatcher dispatcher) */
db_void db_observer_setDispatcher(db_observer _this, db_dispatcher dispatcher);

/* ::cortex::lang::observer::silence(lang::object me) */
db_int16 db_observer_silence(db_observer _this, db_object me);

/* ::cortex::lang::observer::unbind(lang::observer object) */
db_void db_observer_unbind(db_observer object);

#ifdef __cplusplus
}
#endif
#endif

