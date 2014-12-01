/* db_observer.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef db_observer_H
#define db_observer_H

#include "hyve.h"
#include "db__type.h"

#ifdef __cplusplus
extern "C" {
#endif

/* callback ::hyve::lang::procedure::bind(lang::object object) -> ::hyve::lang::observer::bind(lang::observer object) */
db_int16 db_observer_bind(db_observer object);

/* callback ::hyve::lang::type::init(lang::object object) -> ::hyve::lang::observer::init(lang::observer object) */
db_int16 db_observer_init(db_observer object);

/* ::hyve::lang::observer::listen(lang::object observable,lang::object me) */
db_int16 db_observer_listen(db_observer _this, db_object observable, db_object me);

/* ::hyve::lang::observer::setDispatcher(lang::dispatcher dispatcher) */
db_void db_observer_setDispatcher(db_observer _this, db_dispatcher dispatcher);

/* ::hyve::lang::observer::silence(lang::object me) */
db_int16 db_observer_silence(db_observer _this, db_object me);

/* ::hyve::lang::observer::unbind(lang::observer object) */
db_void db_observer_unbind(db_observer object);

#ifdef __cplusplus
}
#endif
#endif

