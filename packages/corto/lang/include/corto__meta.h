/*
 * corto_meta.h
 *
 *  Created on: Aug 6, 2012
 *      Author: sander
 */

#ifndef CORTO_META_H_
#define CORTO_META_H_

#include "corto__type.h"

#ifdef __cplusplus
extern "C" {
#endif

#define CORTO_META_OBJECT(type, name) extern corto_##type corto_##name##_o

extern corto_package root_o;
extern corto_package corto_o;
extern corto_package corto_lang_o;

/* Forward declarations of classes */
CORTO_META_OBJECT(class, typedef);
CORTO_META_OBJECT(class, type);
CORTO_META_OBJECT(class, template);
CORTO_META_OBJECT(class, primitive);
CORTO_META_OBJECT(class, collection);
CORTO_META_OBJECT(class, interface);
CORTO_META_OBJECT(class, binary);
CORTO_META_OBJECT(class, boolean);
CORTO_META_OBJECT(class, character);
CORTO_META_OBJECT(class, int);
CORTO_META_OBJECT(class, uint);
CORTO_META_OBJECT(class, float);
CORTO_META_OBJECT(class, text);
CORTO_META_OBJECT(class, enum);
CORTO_META_OBJECT(class, bitmask);
CORTO_META_OBJECT(class, struct);
CORTO_META_OBJECT(class, class);
CORTO_META_OBJECT(class, delegate);
CORTO_META_OBJECT(class, procedure);
CORTO_META_OBJECT(class, array);
CORTO_META_OBJECT(class, sequence);
CORTO_META_OBJECT(class, list);
CORTO_META_OBJECT(class, map);
CORTO_META_OBJECT(class, iterator);
CORTO_META_OBJECT(class, member);
CORTO_META_OBJECT(class, alias);
CORTO_META_OBJECT(class, event);
CORTO_META_OBJECT(class, observableEvent);
CORTO_META_OBJECT(class, invokeEvent);
CORTO_META_OBJECT(class, package);
CORTO_META_OBJECT(class, query);
CORTO_META_OBJECT(class, replicator);
CORTO_META_OBJECT(struct, interfaceVector);
CORTO_META_OBJECT(struct, delegatedata);
CORTO_META_OBJECT(struct, parameter);
CORTO_META_OBJECT(struct, result);
CORTO_META_OBJECT(interface, dispatcher);

CORTO_META_OBJECT(binary, octet);
CORTO_META_OBJECT(boolean, bool);
CORTO_META_OBJECT(character, char);
CORTO_META_OBJECT(uint, uint8);
CORTO_META_OBJECT(uint, uint16);
CORTO_META_OBJECT(uint, uint32);
CORTO_META_OBJECT(uint, uint64);
CORTO_META_OBJECT(int, int8);
CORTO_META_OBJECT(int, int16);
CORTO_META_OBJECT(int, int32);
CORTO_META_OBJECT(int, int64);
CORTO_META_OBJECT(float, float32);
CORTO_META_OBJECT(float, float64);
CORTO_META_OBJECT(text, string);
CORTO_META_OBJECT(binary, word);
CORTO_META_OBJECT(int, constant);

CORTO_META_OBJECT(type, any);
CORTO_META_OBJECT(class, alias);
CORTO_META_OBJECT(type, void);
CORTO_META_OBJECT(type, object);

CORTO_META_OBJECT(enum, width);
CORTO_META_OBJECT(enum, typeKind);
CORTO_META_OBJECT(enum, primitiveKind);
CORTO_META_OBJECT(enum, compositeKind);
CORTO_META_OBJECT(enum, collectionKind);
CORTO_META_OBJECT(enum, procedureKind);
CORTO_META_OBJECT(enum, equalityKind);
CORTO_META_OBJECT(enum, operatorKind);
CORTO_META_OBJECT(bitmask, eventMask);
CORTO_META_OBJECT(bitmask, modifier);
CORTO_META_OBJECT(bitmask, state);
CORTO_META_OBJECT(bitmask, attr);

CORTO_META_OBJECT(sequence, objectseq);
CORTO_META_OBJECT(sequence, abstractseq);
CORTO_META_OBJECT(sequence, memberseq);
CORTO_META_OBJECT(sequence, parameterseq);
CORTO_META_OBJECT(sequence, interfaceVectorseq);
CORTO_META_OBJECT(sequence, interfaceseq);
CORTO_META_OBJECT(sequence, observerseq);
CORTO_META_OBJECT(sequence, vtable);
CORTO_META_OBJECT(sequence, octetseq);
CORTO_META_OBJECT(list, resultList);

CORTO_META_OBJECT(delegate, initAction);
CORTO_META_OBJECT(delegate, destructAction);
CORTO_META_OBJECT(delegate, notifyAction);
CORTO_META_OBJECT(delegate, invokeAction);
CORTO_META_OBJECT(delegate, requestAction);

CORTO_META_OBJECT(procedure, function);
CORTO_META_OBJECT(procedure, method);
CORTO_META_OBJECT(procedure, virtual);
CORTO_META_OBJECT(procedure, observer);
CORTO_META_OBJECT(procedure, metaprocedure);

CORTO_META_OBJECT(observer, replicator_on_declare);
CORTO_META_OBJECT(observer, replicator_on_update);
CORTO_META_OBJECT(observer, replicator_on_delete);

CORTO_META_OBJECT(iterator, resultIter);

#ifdef __cplusplus
}
#endif

#endif /* CORTO_META_H_ */
