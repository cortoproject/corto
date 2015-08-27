/* tc.h
 *
 *  Generated on Feb  5 2014
 *    This file contains generated code. Do not modify!
 */

#ifndef tc_H
#define tc_H

#include "corto.h"
#include "tc_event__type.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::tc_event::construct_onBoth */
cx_void tc_construct_onBoth(cx_object *observable, cx_object *source);

/* ::tc_event::construct_onChild */
cx_void tc_construct_onChild(cx_object *observable, cx_object *source);

/* ::tc_event::construct_onRootChilds */
cx_void tc_construct_onRootChilds(cx_object *observable, cx_object *source);

/* ::tc_event::construct_onRootSelf */
cx_void tc_construct_onRootSelf(cx_object *observable, cx_object *source);

/* ::tc_event::construct_onSelf */
cx_void tc_construct_onSelf(tc_Point *observable, cx_object *source);

/* ::tc_event::destruct_onBoth */
cx_void tc_destruct_onBoth(cx_object *observable, cx_object *source);

/* ::tc_event::destruct_onChild */
cx_void tc_destruct_onChild(cx_object *observable, cx_object *source);

/* ::tc_event::destruct_onRootChilds */
cx_void tc_destruct_onRootChilds(cx_object *observable, cx_object *source);

/* ::tc_event::destruct_onRootSelf */
cx_void tc_destruct_onRootSelf(cx_object *observable, cx_object *source);

/* ::tc_event::destruct_onSelf */
cx_void tc_destruct_onSelf(tc_Point *observable, cx_object *source);

/* ::tc_event::new_onBoth */
cx_void tc_new_onBoth(cx_object *observable, cx_object *source);

/* ::tc_event::new_onChild */
cx_void tc_new_onChild(cx_object *observable, cx_object *source);

/* ::tc_event::new_onRootChilds */
cx_void tc_new_onRootChilds(cx_object *observable, cx_object *source);

/* ::tc_event::new_onRootSelf */
cx_void tc_new_onRootSelf(cx_object *observable, cx_object *source);

/* ::tc_event::new_onSelf */
cx_void tc_new_onSelf(cx_object *observable, cx_object *source);

/* ::tc_event::update_onBoth */
cx_void tc_update_onBoth(cx_object *observable, cx_object *source);

/* ::tc_event::update_onChild */
cx_void tc_update_onChild(cx_object *observable, cx_object *source);

/* ::tc_event::update_onRootChilds */
cx_void tc_update_onRootChilds(cx_object *observable, cx_object *source);

/* ::tc_event::update_onRootSelf */
cx_void tc_update_onRootSelf(cx_object *observable, cx_object *source);

/* ::tc_event::update_onSelf */
cx_void tc_update_onSelf(tc_Point *observable, cx_object *source);

#ifdef __cplusplus
}
#endif
#endif

