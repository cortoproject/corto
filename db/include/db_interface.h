/*
 * db_interface.h
 *
 *  Created on: Aug 17, 2012
 *      Author: sander
 */

#ifndef DB_INTERFACE_H_
#define DB_INTERFACE_H_

#include "db__type.h"
#include "db_class.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Callbacks */
db_int16 db_interface_init(db_interface object);
db_int16 db_interface_construct(db_interface object);
void db_interface_destruct(db_interface object);

db_method db_interface_resolveMethod(db_interface _this, db_string method);
db_uint32 db_interface_resolveMethodId(db_interface _this, db_string method);
db_method db_interface_resolveMethodById(db_interface _this, db_uint32 id);

db_bool db_interface_compatible(db_interface _this, db_type type);
db_bool db_interface_baseof(db_interface _this, db_interface type);
db_int16 db_interface_bindMethod(db_interface _this, db_method method);
db_bool db_interface_checkProcedureCompatibility(db_function o1, db_function o2);

/* Metaprocedures */
db_equalityKind db_interface_compare(db_any _this, db_any value);

/* Virtuals */
db_member db_interface_resolveMember(db_interface _this, db_string name);

#ifdef __cplusplus
}
#endif

#endif /* DB_INTERFACE_H_ */
