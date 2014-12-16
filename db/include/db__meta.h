/*
 * db_meta.h
 *
 *  Created on: Aug 6, 2012
 *      Author: sander
 */

#ifndef DB_META_H_
#define DB_META_H_

#include "db__type.h"

#ifdef __cplusplus
extern "C" {
#endif

#define DB_META_OBJECT(type, name) extern db_##type db_##name##_o

extern db_object root_o;
extern db_object hyve_o;
extern db_object hyve_lang_o;

/* Forward declarations of classes */
DB_META_OBJECT(class, typedef);
DB_META_OBJECT(class, type);
DB_META_OBJECT(class, template);
DB_META_OBJECT(class, primitive);
DB_META_OBJECT(class, collection);
DB_META_OBJECT(class, interface);
DB_META_OBJECT(class, binary);
DB_META_OBJECT(class, boolean);
DB_META_OBJECT(class, character);
DB_META_OBJECT(class, int);
DB_META_OBJECT(class, uint);
DB_META_OBJECT(class, float);
DB_META_OBJECT(class, text);
DB_META_OBJECT(class, enum);
DB_META_OBJECT(class, bitmask);
DB_META_OBJECT(class, struct);
DB_META_OBJECT(class, class);
DB_META_OBJECT(class, procptr);
DB_META_OBJECT(class, procedure);
DB_META_OBJECT(class, array);
DB_META_OBJECT(class, sequence);
DB_META_OBJECT(class, list);
DB_META_OBJECT(class, map);
DB_META_OBJECT(class, member);
DB_META_OBJECT(class, event);
DB_META_OBJECT(class, observableEvent);
DB_META_OBJECT(struct, parameter);
DB_META_OBJECT(struct, procptrdata);
DB_META_OBJECT(struct, interfaceVector);
DB_META_OBJECT(interface, dispatcher);

DB_META_OBJECT(binary, octet);
DB_META_OBJECT(boolean, bool);
DB_META_OBJECT(character, char);
DB_META_OBJECT(uint, uint8);
DB_META_OBJECT(uint, uint16);
DB_META_OBJECT(uint, uint32);
DB_META_OBJECT(uint, uint64);
DB_META_OBJECT(int, int8);
DB_META_OBJECT(int, int16);
DB_META_OBJECT(int, int32);
DB_META_OBJECT(int, int64);
DB_META_OBJECT(float, float32);
DB_META_OBJECT(float, float64);
DB_META_OBJECT(text, string);
DB_META_OBJECT(binary, word);
DB_META_OBJECT(int, constant);

DB_META_OBJECT(type, any);
DB_META_OBJECT(class, alias);
DB_META_OBJECT(type, void);
DB_META_OBJECT(type, object);

DB_META_OBJECT(enum, width);
DB_META_OBJECT(enum, typeKind);
DB_META_OBJECT(enum, primitiveKind);
DB_META_OBJECT(enum, compositeKind);
DB_META_OBJECT(enum, collectionKind);
DB_META_OBJECT(enum, procedureKind);
DB_META_OBJECT(enum, equalityKind);
DB_META_OBJECT(enum, operatorKind);
DB_META_OBJECT(bitmask, eventMask);
DB_META_OBJECT(bitmask, modifier);
DB_META_OBJECT(bitmask, state);
DB_META_OBJECT(bitmask, attr);

DB_META_OBJECT(sequence, objectSeq);
DB_META_OBJECT(sequence, abstractSeq);
DB_META_OBJECT(sequence, memberSeq);
DB_META_OBJECT(sequence, parameterSeq);
DB_META_OBJECT(sequence, interfaceVectorSeq);

DB_META_OBJECT(procedure, function);
DB_META_OBJECT(procedure, method);
DB_META_OBJECT(procedure, virtual);
DB_META_OBJECT(procedure, delegate);
DB_META_OBJECT(procedure, callback);
DB_META_OBJECT(procedure, observer);
DB_META_OBJECT(procedure, metaprocedure);

DB_META_OBJECT(delegate, type_init);
DB_META_OBJECT(delegate, class_construct);
DB_META_OBJECT(delegate, class_destruct);
DB_META_OBJECT(delegate, procedure_bind);

#ifdef __cplusplus
}
#endif

#endif /* DB_META_H_ */
