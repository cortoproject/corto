/*
 * db_procedure.h
 *
 *  Created on: Aug 9, 2012
 *      Author: sander
 */

#ifndef DB_PROCEDURE_H_
#define DB_PROCEDURE_H_

#include "db__type.h"

#ifdef __cplusplus
extern "C" {
#endif

db_int16 db_procedure_init(db_procedure object);
db_int16 db_parameter_init(db_parameter object);
db_int16 db_function_init(db_function object);
db_int16 db_function_bind(db_function object);
void db_function_unbind(db_function object);
db_int16 db_method_init(db_method object);
db_int16 db_method_bind(db_method object);
db_int16 db_virtual_init(db_virtual object);
db_int16 db_delegate_init(db_delegate object);
db_int16 db_callback_init(db_callback object);
db_int16 db_callback_bind(db_callback object);
db_int16 db_observer_init(db_observer object);
db_int16 db_observer_bind(db_observer object);
db_int16 db_metaprocedure_bind(db_metaprocedure object);
void db_observer_unbind(db_observer object);
db_int16 db_observer_listen(db_observer _this, db_object observable, db_object me);
db_int16 db_observer_silence(db_observer _this, db_object me);
void db_observer_setDispatcher(db_observer _this, db_dispatcher dispatcher);

db_int16 db_procedure_bind(db_procedure _this, db_object object);
void db_procedure_unbind(db_procedure _this, db_object object);
db_member db_procedure_resolveMember(db_procedure _this, db_string name);

#ifdef __cplusplus
}
#endif

#endif /* DB_PROCEDURE_H_ */
