/* tc.h
 *
 *  Generated on Feb  5 2014
 *    This file contains generated code. Do not modify!
 */

#ifndef tc_H
#define tc_H

#include "cortex.h"
#include "tc_event__type.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::tc_event::construct_onBoth */
db_void tc_construct_onBoth(db_object *observable, db_object *source);

/* ::tc_event::construct_onChild */
db_void tc_construct_onChild(db_object *observable, db_object *source);

/* ::tc_event::construct_onRootChilds */
db_void tc_construct_onRootChilds(db_object *observable, db_object *source);

/* ::tc_event::construct_onRootSelf */
db_void tc_construct_onRootSelf(db_object *observable, db_object *source);

/* ::tc_event::construct_onSelf */
db_void tc_construct_onSelf(tc_Point *observable, db_object *source);

/* ::tc_event::destruct_onBoth */
db_void tc_destruct_onBoth(db_object *observable, db_object *source);

/* ::tc_event::destruct_onChild */
db_void tc_destruct_onChild(db_object *observable, db_object *source);

/* ::tc_event::destruct_onRootChilds */
db_void tc_destruct_onRootChilds(db_object *observable, db_object *source);

/* ::tc_event::destruct_onRootSelf */
db_void tc_destruct_onRootSelf(db_object *observable, db_object *source);

/* ::tc_event::destruct_onSelf */
db_void tc_destruct_onSelf(tc_Point *observable, db_object *source);

/* ::tc_event::new_onBoth */
db_void tc_new_onBoth(db_object *observable, db_object *source);

/* ::tc_event::new_onChild */
db_void tc_new_onChild(db_object *observable, db_object *source);

/* ::tc_event::new_onRootChilds */
db_void tc_new_onRootChilds(db_object *observable, db_object *source);

/* ::tc_event::new_onRootSelf */
db_void tc_new_onRootSelf(db_object *observable, db_object *source);

/* ::tc_event::new_onSelf */
db_void tc_new_onSelf(db_object *observable, db_object *source);

/* ::tc_event::update_onBoth */
db_void tc_update_onBoth(db_object *observable, db_object *source);

/* ::tc_event::update_onChild */
db_void tc_update_onChild(db_object *observable, db_object *source);

/* ::tc_event::update_onRootChilds */
db_void tc_update_onRootChilds(db_object *observable, db_object *source);

/* ::tc_event::update_onRootSelf */
db_void tc_update_onRootSelf(db_object *observable, db_object *source);

/* ::tc_event::update_onSelf */
db_void tc_update_onSelf(tc_Point *observable, db_object *source);

#ifdef __cplusplus
}
#endif
#endif

