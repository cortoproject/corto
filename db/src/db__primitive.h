/*
 * db__primitive.h
 *
 *  Created on: Aug 28, 2012
 *      Author: sander
 */

#ifndef DB__PRIMITIVE_H_
#define DB__PRIMITIVE_H_

#include "db_primitive.h"

#ifdef __cplusplus
extern "C" {
#endif

#define DB_PRIMITIVE_MAX_CONVERTID (24)

db_uint8 db__primitive_convertId(db_primitiveKind kind, db_width width);
db_int16 db__enum_bindConstant(db_enum _this, db_constant* c);
db_int16 db__bitmask_bindConstant(db_bitmask _this, db_constant* c);

#ifdef __cplusplus
}
#endif

#endif /* DB__PRIMITIVE_H_ */
