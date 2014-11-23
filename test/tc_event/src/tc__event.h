/*
 * tc__event.h
 *
 *  Created on: Jul 24, 2013
 *      Author: sander
 */

#ifndef TC__EVENT_H_
#define TC__EVENT_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef struct tc_data {
    db_uint32 count;
    db_object _this;
    db_object observable;
    db_object source;
}tc_data;

typedef enum tc_observableKind {
    observableOnUpdateBoth,
    observableOnUpdateChild,
    observableOnUpdateSelf,
    observableOnUpdateRootChilds,
    observableOnUpdateRootSelf,
    observableOnUpdateThis,
    observableOnNewBoth,
    observableOnNewChild,
    observableOnNewSelf,
    observableOnNewRootChilds,
    observableOnNewRootSelf,
    observableOnNewThis,
    observableOnConstructBoth,
    observableOnConstructChild,
    observableOnConstructSelf,
    observableOnConstructRootChilds,
    observableOnConstructRootSelf,
    observableOnConstructThis,
    observableOnDestructBoth,
    observableOnDestructChild,
    observableOnDestructSelf,
    observableOnDestructRootChilds,
    observableOnDestructRootSelf,
    observableOnDestructThis,
    observableLast
}tc_observableKind;

extern tc_data tcResult[observableLast];

#ifdef __cplusplus
}
#endif

#endif /* TC__EVENT_H_ */
