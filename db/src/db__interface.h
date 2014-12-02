/*
 * db__interface.h
 *
 *  Created on: Aug 9, 2012
 *      Author: sander
 */

#ifndef DB__COMPOSITE_H_
#define DB__COMPOSITE_H_

#include "db_interface.h"

#ifdef __cplusplus
extern "C" {
#endif

db_int16 db__interface_bindMember(db_interface _this, db_member o);
db_int16 db__interface_insertMembers(db_interface _this);
db_uint16 db__interface_calculateAlignment(db_interface _this);
db_uint32 db__interface_calculateSize(db_interface _this, db_uint32 base);
db_member db_interface_resolveMember_v(db_interface _this, db_string name);

db_bool db_interface_checkProcedureCompatibility(db_function o1, db_function o2);

db_function* db_vtableLookup(db_vtable* vtable, db_string member, db_int32* i_out, db_int32* d_out);
db_bool db_vtableInsert(db_vtable* vtable, db_function method);
db_int16 db_interface_bindMethod_v(db_interface _this, db_method method);

#ifdef __cplusplus
}
#endif

#endif /* DB__COMPOSITE_H_ */
