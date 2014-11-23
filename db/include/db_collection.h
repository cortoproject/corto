/*
 * db_collection.h
 *
 *  Created on: Aug 2, 2012
 *      Author: sander
 */

#ifndef DB_COLLECTION_H_
#define DB_COLLECTION_H_

#include "db__type.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef int (*db_compareAction)(void* o1, void* o2);
typedef int (*db_walkAction)(void* o, void* userData);

/* Sequence specific */
int db_sequenceAlloc(db_collection _this, db_void* collection, db_uint32 elements);

/* Collection interface */
int db_walk(db_collection _this, db_void* collection, db_walkAction action, db_void* userData);
void db_clear(db_collection _this, db_void* collection);
db_uint32 db_size(db_collection _this, db_void* collection);

/* ::type::init -> ::collection::init */
db_int16 db_collection_init(db_collection object);
db_int16 db_array_init(db_array object);
db_int16 db_sequence_init(db_sequence object);
db_int16 db_list_init(db_list object);
db_int16 db_map_init(db_map object);

/* ::class::construct -> ::collection::construct */
db_int16 db_collection_construct(db_collection object);
db_int16 db_array_construct(db_array object);
void db_array_destruct(db_array object);
db_int16 db_sequence_construct(db_sequence object);
db_int16 db_list_construct(db_list object);
db_int16 db_map_construct(db_map object);

/* metaprocedures */
db_uint32 db_collection_size(db_any object);
void db_sequence_size(db_any object, db_uint32 size);
void db_list_insert(db_any object, db_any element);
void db_list_append(db_any object, db_any element);
db_any db_list_insert_(db_any object);
db_any db_list_append_(db_any object);
void db_list_reverse(db_any object);
void db_list_clear(db_any object);
    
db_bool db_collection_elementRequiresAlloc(db_collection type);
db_bool db_collection_castable(db_collection _this, db_type type);

    
#ifdef __cplusplus
}
#endif

#endif /* DB_COLLECTION_H_ */
