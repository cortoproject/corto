/*
 * corto__project.h
 *
 *  Created on: Aug 9, 2012
 *      Author: sander
 */

#ifndef CORTO__INTERFACE_H_
#define CORTO__INTERFACE_H_

#include "corto/corto.h"

#ifdef __cplusplus
extern "C" {
#endif

corto_int16 corto__interface_bindMember(corto_interface _this, corto_member o);
corto_int16 corto__interface_insertMembers(corto_interface _this);
corto_uint16 corto__interface_calculateAlignment(corto_interface _this);
corto_uint32 corto__interface_calculateSize(corto_interface _this, corto_uint32 base);
corto_bool corto_interface_checkProcedureCompatibility(corto_function o1, corto_function o2);
corto_function* corto_vtableLookup(corto_objectseq* vtable, corto_string member, corto_int32* d_out);
corto_bool corto_vtableInsert(corto_objectseq* vtable, corto_function method);
corto_objectseq corto_interface_vtableFromBase(corto_interface this);
bool corto_interface_pullDelegate(corto_interface this, corto_member member);

extern corto_member corto_type_init_o;
extern corto_member corto_type_deinit_o;
extern corto_member corto_class_construct_o;
extern corto_member corto_class_validate_o;
extern corto_member corto_class_update_o;
extern corto_member corto_class_define_o;
extern corto_member corto_class_destruct_o;
extern corto_member corto_class_delete_o;

#ifdef __cplusplus
}
#endif

#endif /* CORTO__INTERFACE_H_ */
