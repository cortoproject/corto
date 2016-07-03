/*
 * corto_meta.h
 *
 *  Created on: Aug 6, 2012
 *      Author: sander
 */

#ifndef CORTO_CORE_META_H_
#define CORTO_CORE_META_H_

#include "corto/lang/_type.h"
#include "corto/core/_type.h"

#ifdef __cplusplus
extern "C" {
#endif

#define CORTO_META_OBJECT(type, name) extern corto_##type corto_##name##_o

extern corto_package root_o;
extern corto_package corto_o;
extern corto_package corto_core_o;

/* Forward declarations of classes */
CORTO_META_OBJECT(class, event);
CORTO_META_OBJECT(class, observableEvent);
CORTO_META_OBJECT(class, invokeEvent);
CORTO_META_OBJECT(class, package);
CORTO_META_OBJECT(class, query);
CORTO_META_OBJECT(class, mount);
CORTO_META_OBJECT(class, loader);
CORTO_META_OBJECT(struct, augmentData);
CORTO_META_OBJECT(struct, result);
CORTO_META_OBJECT(struct, request);
CORTO_META_OBJECT(interface, dispatcher);

CORTO_META_OBJECT(enum, equalityKind);
CORTO_META_OBJECT(enum, operatorKind);
CORTO_META_OBJECT(bitmask, eventMask);
CORTO_META_OBJECT(bitmask, modifier);
CORTO_META_OBJECT(enum, mountKind);
CORTO_META_OBJECT(bitmask, state);
CORTO_META_OBJECT(bitmask, attr);

CORTO_META_OBJECT(list, resultList);
CORTO_META_OBJECT(sequence, augmentseq);

CORTO_META_OBJECT(delegate, notifyAction);
CORTO_META_OBJECT(delegate, invokeAction);
CORTO_META_OBJECT(delegate, requestAction);

CORTO_META_OBJECT(procedure, remote);
CORTO_META_OBJECT(procedure, observer);
CORTO_META_OBJECT(struct, time);
CORTO_META_OBJECT(struct, position);

#ifdef __cplusplus
}
#endif

#endif /* CORTO_META_H_ */
