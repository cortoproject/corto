/*
 * corto__interface.h
 *
 *  Created on: Aug 9, 2012
 *      Author: sander
 */

#ifndef CORTO__COMPOSITE_H_
#define CORTO__COMPOSITE_H_

#include "corto_interface.h"

#ifdef __cplusplus
extern "C" {
#endif

corto_int16 corto__interface_bindMember(corto_interface _this, corto_member o);
corto_int16 corto__interface_insertMembers(corto_interface _this);
corto_uint16 corto__interface_calculateAlignment(corto_interface _this);
corto_uint32 corto__interface_calculateSize(corto_interface _this, corto_uint32 base);

corto_bool corto_interface_checkProcedureCompatibility(corto_function o1, corto_function o2);

corto_function* corto_vtableLookup(corto_vtable* vtable, corto_string member, corto_int32* d_out);
corto_bool corto_vtableInsert(corto_vtable* vtable, corto_function method);

#ifdef __cplusplus
}
#endif

#endif /* CORTO__COMPOSITE_H_ */
