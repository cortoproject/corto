/*
 * cx_meta.h
 *
 *  Created on: Aug 6, 2012
 *      Author: sander
 */

#ifndef CX_META_H_
#define CX_META_H_

#include "cx__type.h"

#ifdef __cplusplus
extern "C" {
#endif

#define CX_META_OBJECT(type, name) extern cx_##type cx_##name##_o

extern cx_object root_o;
extern cx_object cortex_o;
extern cx_object cortex_lang_o;

/* Forward declarations of classes */
CX_META_OBJECT(class, typedef);
CX_META_OBJECT(class, type);
CX_META_OBJECT(class, template);
CX_META_OBJECT(class, primitive);
CX_META_OBJECT(class, collection);
CX_META_OBJECT(class, interface);
CX_META_OBJECT(class, binary);
CX_META_OBJECT(class, boolean);
CX_META_OBJECT(class, character);
CX_META_OBJECT(class, int);
CX_META_OBJECT(class, uint);
CX_META_OBJECT(class, float);
CX_META_OBJECT(class, text);
CX_META_OBJECT(class, enum);
CX_META_OBJECT(class, bitmask);
CX_META_OBJECT(class, struct);
CX_META_OBJECT(class, class);
CX_META_OBJECT(class, delegate);
CX_META_OBJECT(class, procedure);
CX_META_OBJECT(class, array);
CX_META_OBJECT(class, sequence);
CX_META_OBJECT(class, list);
CX_META_OBJECT(class, map);
CX_META_OBJECT(class, iterator);
CX_META_OBJECT(class, member);
CX_META_OBJECT(class, event);
CX_META_OBJECT(class, observableEvent);
CX_META_OBJECT(struct, parameter);
CX_META_OBJECT(struct, delegatedata);
CX_META_OBJECT(struct, interfaceVector);
CX_META_OBJECT(interface, dispatcher);

CX_META_OBJECT(binary, octet);
CX_META_OBJECT(boolean, bool);
CX_META_OBJECT(character, char);
CX_META_OBJECT(uint, uint8);
CX_META_OBJECT(uint, uint16);
CX_META_OBJECT(uint, uint32);
CX_META_OBJECT(uint, uint64);
CX_META_OBJECT(int, int8);
CX_META_OBJECT(int, int16);
CX_META_OBJECT(int, int32);
CX_META_OBJECT(int, int64);
CX_META_OBJECT(float, float32);
CX_META_OBJECT(float, float64);
CX_META_OBJECT(text, string);
CX_META_OBJECT(binary, word);
CX_META_OBJECT(int, constant);

CX_META_OBJECT(type, any);
CX_META_OBJECT(class, alias);
CX_META_OBJECT(type, void);
CX_META_OBJECT(type, object);

CX_META_OBJECT(enum, width);
CX_META_OBJECT(enum, typeKind);
CX_META_OBJECT(enum, primitiveKind);
CX_META_OBJECT(enum, compositeKind);
CX_META_OBJECT(enum, collectionKind);
CX_META_OBJECT(enum, procedureKind);
CX_META_OBJECT(enum, equalityKind);
CX_META_OBJECT(enum, operatorKind);
CX_META_OBJECT(bitmask, eventMask);
CX_META_OBJECT(bitmask, modifier);
CX_META_OBJECT(bitmask, state);
CX_META_OBJECT(bitmask, attr);

CX_META_OBJECT(sequence, objectSeq);
CX_META_OBJECT(sequence, abstractSeq);
CX_META_OBJECT(sequence, memberSeq);
CX_META_OBJECT(sequence, parameterSeq);
CX_META_OBJECT(sequence, interfaceVectorSeq);

CX_META_OBJECT(delegate, callbackInit);
CX_META_OBJECT(delegate, callbackDestruct);

CX_META_OBJECT(procedure, function);
CX_META_OBJECT(procedure, method);
CX_META_OBJECT(procedure, virtual);
CX_META_OBJECT(procedure, observer);
CX_META_OBJECT(procedure, metaprocedure);

#ifdef __cplusplus
}
#endif

#endif /* CX_META_H_ */
