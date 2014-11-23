/*
 * db_struct.h
 *
 *  Created on: Oct 10, 2012
 *      Author: sander
 */

#ifndef DB_EXTENDABLE_H_
#define DB_EXTENDABLE_H_

#include "db__type.h"
#include "db_interface.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Callbacks */
db_int16 db_struct_construct(db_struct object);
db_int16 db_struct_init(db_struct object);

/* Virtual methods */
db_member db_struct_resolveMember(db_struct _this, db_string member);

/* Methods */
db_bool db_struct_compatible(db_struct _this, db_type type);
db_bool db_struct_castable(db_struct _this, db_type type);
db_int16 db_struct_declareTemplateParameter(db_struct _this, db_string name);
db_member db_struct_resolveTemplateMember(db_struct _this, db_uint32 id);
db_type db_struct_resolveTemplateType(db_struct _this, db_type T, db_object o);

#ifdef __cplusplus
}
#endif

#endif /* DB_EXTENDABLE_H_ */

