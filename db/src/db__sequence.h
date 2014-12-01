#ifndef DB__SEQUENCE_H_
#define DB__SEQUENCE_H_

#include "db__type.h"

#ifdef __cplusplus
extern "C" {
#endif

int db_sequence_alloc(db_collection _this, db_void* collection, db_uint32 elements);

#ifdef __cplusplus
}
#endif

#endif /* DB__SEQUENCE_H_ */
