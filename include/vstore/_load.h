/*
 * corto_load.h
 *
 *  Created on: Aug 6, 2012
 *      Author: sander
 */

#ifndef CORTO_VSTORE_META_H_
#define CORTO_VSTORE_META_H_

#include "../lang/_type.h"
#include "_type.h"

#ifdef __cplusplus
extern "C" {
#endif

#define CORTO_META_OBJECT(type, name) CORTO_EXPORT extern corto_##type corto_##name##_o

CORTO_EXPORT extern corto_package root_o;
CORTO_EXPORT extern corto_package corto_o;
CORTO_EXPORT extern corto_package corto_vstore_o;

/* Forward declarations of classes */
CORTO_META_OBJECT(class, router);
CORTO_META_OBJECT(class, routerimpl);
CORTO_META_OBJECT(struct, queue_policy);
CORTO_META_OBJECT(class, mount);
CORTO_META_OBJECT(struct, mount_policy);
CORTO_META_OBJECT(struct, mount_subscription);
CORTO_META_OBJECT(class, loader);
CORTO_META_OBJECT(struct, record);
CORTO_META_OBJECT(struct, request);
CORTO_META_OBJECT(struct, frame);
CORTO_META_OBJECT(struct, query);
CORTO_META_OBJECT(interface, dispatcher);

CORTO_META_OBJECT(enum, equalityKind);
CORTO_META_OBJECT(enum, operatorKind);
CORTO_META_OBJECT(bitmask, eventMask);
CORTO_META_OBJECT(bitmask, recordMask);
CORTO_META_OBJECT(enum, ownership);
CORTO_META_OBJECT(bitmask, mountCallbackMask);
CORTO_META_OBJECT(enum, frameKind);

CORTO_META_OBJECT(list, recordlist);
CORTO_META_OBJECT(list, mount_subscriptionList);
CORTO_META_OBJECT(sequence, augmentseq);

CORTO_META_OBJECT(delegate, notifyAction);
CORTO_META_OBJECT(delegate, invokeAction);
CORTO_META_OBJECT(delegate, requestAction);
CORTO_META_OBJECT(delegate, handleAction);

CORTO_META_OBJECT(procedure, remote);
CORTO_META_OBJECT(procedure, subscriber);
CORTO_META_OBJECT(procedure, observer);
CORTO_META_OBJECT(procedure, route);

CORTO_META_OBJECT(struct, fmt_data);
CORTO_META_OBJECT(struct, event);
CORTO_META_OBJECT(struct, observer_event);
CORTO_META_OBJECT(struct, sample);
CORTO_META_OBJECT(struct, subscriber_event);
CORTO_META_OBJECT(struct, invoke_event);
CORTO_META_OBJECT(struct, time);

CORTO_META_OBJECT(iterator, recordIter);
CORTO_META_OBJECT(iterator, sampleIter);
CORTO_META_OBJECT(iterator, subscriber_eventIter);

CORTO_META_OBJECT(function, observer_event_handle);
CORTO_META_OBJECT(function, subscriber_event_handle);

CORTO_META_OBJECT(method, routerimpl_find_route);
CORTO_META_OBJECT(method, routerimpl_match_route);
CORTO_META_OBJECT(method, mount_on_invoke);
CORTO_META_OBJECT(method, mount_on_invoke);
CORTO_META_OBJECT(method, mount_on_id);
CORTO_META_OBJECT(method, mount_on_resume);
CORTO_META_OBJECT(method, mount_on_query);
CORTO_META_OBJECT(method, mount_on_history_query);
CORTO_META_OBJECT(method, mount_on_notify);
CORTO_META_OBJECT(method, mount_on_batch_notify);
CORTO_META_OBJECT(method, mount_on_history_batch_notify);
CORTO_META_OBJECT(method, mount_on_subscribe);
CORTO_META_OBJECT(method, mount_on_unsubscribe);
CORTO_META_OBJECT(method, mount_on_mount);
CORTO_META_OBJECT(method, mount_on_unmount);

#ifdef __cplusplus
}
#endif

#endif /* CORTO_META_H_ */
