/*
 * corto_load.h
 *
 *  Created on: Aug 6, 2012
 *      Author: sander
 */

#ifndef CORTO_META_H_
#define CORTO_META_H_

#include "corto/vstore/_type.h"
#include "corto/lang/_type.h"

#ifdef __cplusplus
extern "C" {
#endif

#define CORTO_META_OBJECT(type, name) CORTO_EXPORT extern corto_##type corto_##name##_o

CORTO_EXPORT extern corto_package root_o;
CORTO_EXPORT extern corto_package corto_o;
CORTO_EXPORT extern corto_package corto_lang_o;

/* Forward declarations of classes */
CORTO_META_OBJECT(class, package);
CORTO_META_OBJECT(class, application);
CORTO_META_OBJECT(class, tool);
CORTO_META_OBJECT(class, type);
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
CORTO_META_OBJECT(class, verbatim);
CORTO_META_OBJECT(class, enum);
CORTO_META_OBJECT(class, bitmask);
CORTO_META_OBJECT(class, struct);
CORTO_META_OBJECT(class, union);
CORTO_META_OBJECT(class, class);
CORTO_META_OBJECT(class, delegate);
CORTO_META_OBJECT(class, target);
CORTO_META_OBJECT(class, procedure);
CORTO_META_OBJECT(class, array);
CORTO_META_OBJECT(class, sequence);
CORTO_META_OBJECT(class, list);
CORTO_META_OBJECT(class, map);
CORTO_META_OBJECT(class, iterator);
CORTO_META_OBJECT(class, member);
CORTO_META_OBJECT(class, alias);
CORTO_META_OBJECT(class, case);
CORTO_META_OBJECT(class, default);
CORTO_META_OBJECT(class, package);
CORTO_META_OBJECT(class, mount);
CORTO_META_OBJECT(class, quantity);
CORTO_META_OBJECT(class, unit);
CORTO_META_OBJECT(class, container);
CORTO_META_OBJECT(class, leaf);
CORTO_META_OBJECT(class, table);
CORTO_META_OBJECT(class, tableinstance);
CORTO_META_OBJECT(struct, typespec);
CORTO_META_OBJECT(struct, interfaceVector);
CORTO_META_OBJECT(struct, delegatedata);
CORTO_META_OBJECT(struct, parameter);
CORTO_META_OBJECT(struct, result);
CORTO_META_OBJECT(struct, typeOptions);
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
CORTO_META_OBJECT(type, unknown);
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
CORTO_META_OBJECT(enum, inout);
CORTO_META_OBJECT(bitmask, eventMask);
CORTO_META_OBJECT(bitmask, modifier);
CORTO_META_OBJECT(bitmask, state);
CORTO_META_OBJECT(bitmask, attr);

CORTO_META_OBJECT(sequence, objectseq);
CORTO_META_OBJECT(sequence, abstractseq);
CORTO_META_OBJECT(sequence, parameterseq);
CORTO_META_OBJECT(sequence, interfaceVectorseq);
CORTO_META_OBJECT(sequence, interfaceseq);
CORTO_META_OBJECT(sequence, stringseq);
CORTO_META_OBJECT(sequence, int32seq);
CORTO_META_OBJECT(sequence, wordseq);
CORTO_META_OBJECT(list, resultList);
CORTO_META_OBJECT(list, objectlist);
CORTO_META_OBJECT(list, stringlist);

CORTO_META_OBJECT(delegate, initAction);
CORTO_META_OBJECT(delegate, nameAction);
CORTO_META_OBJECT(delegate, destructAction);
CORTO_META_OBJECT(delegate, notifyAction);
CORTO_META_OBJECT(delegate, invokeAction);
CORTO_META_OBJECT(delegate, requestAction);

CORTO_META_OBJECT(procedure, function);
CORTO_META_OBJECT(procedure, method);
CORTO_META_OBJECT(procedure, overridable);
CORTO_META_OBJECT(procedure, override);
CORTO_META_OBJECT(procedure, observer);
CORTO_META_OBJECT(procedure, metaprocedure);

CORTO_META_OBJECT(iterator, objectIter);

#ifdef __cplusplus
}
#endif

#endif /* CORTO_META_H_ */
