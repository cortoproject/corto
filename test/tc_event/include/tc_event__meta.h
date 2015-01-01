/* tc_event__meta.h
 *
 *  Generated on Feb  5 2014
 *    Loads objects in database.
 *    This file contains generated code. Do not modify!
 */

#ifndef tc_event_META_H
#define tc_event_META_H

#include "cortex.h"

#include "tc_event__type.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::tc_event */
extern db_object tc_o;

/* ::tc_event::construct_onBoth */
extern db_observer tc_construct_onBoth_o;

/* ::tc_event::construct_onChild */
extern db_observer tc_construct_onChild_o;

/* ::tc_event::construct_onRootChilds */
extern db_observer tc_construct_onRootChilds_o;

/* ::tc_event::construct_onRootSelf */
extern db_observer tc_construct_onRootSelf_o;

/* ::tc_event::construct_onSelf */
extern db_observer tc_construct_onSelf_o;

/* ::tc_event::destruct_onBoth */
extern db_observer tc_destruct_onBoth_o;

/* ::tc_event::destruct_onChild */
extern db_observer tc_destruct_onChild_o;

/* ::tc_event::destruct_onRootChilds */
extern db_observer tc_destruct_onRootChilds_o;

/* ::tc_event::destruct_onRootSelf */
extern db_observer tc_destruct_onRootSelf_o;

/* ::tc_event::destruct_onSelf */
extern db_observer tc_destruct_onSelf_o;

/* ::tc_event::new_onBoth */
extern db_observer tc_new_onBoth_o;

/* ::tc_event::new_onChild */
extern db_observer tc_new_onChild_o;

/* ::tc_event::new_onRootChilds */
extern db_observer tc_new_onRootChilds_o;

/* ::tc_event::new_onRootSelf */
extern db_observer tc_new_onRootSelf_o;

/* ::tc_event::new_onSelf */
extern db_observer tc_new_onSelf_o;

/* ::tc_event::parent */
extern tc_Point tc_parent_o;

/* ::tc_event::parent::child */
extern tc_Point tc_parent_child_o;

/* ::tc_event::Point */
extern db_class tc_Point_o;

/* ::tc_event::Point::construct_onThis */
extern db_observer tc_Point_construct_onThis_o;

/* ::tc_event::Point::destruct_onThis */
extern db_observer tc_Point_destruct_onThis_o;

/* ::tc_event::Point::new_onThis */
extern db_observer tc_Point_new_onThis_o;

/* ::tc_event::Point::update_onThis */
extern db_observer tc_Point_update_onThis_o;

/* ::tc_event::Point::x */
extern db_member tc_Point_x_o;

/* ::tc_event::Point::y */
extern db_member tc_Point_y_o;

/* ::tc_event::update_onBoth */
extern db_observer tc_update_onBoth_o;

/* ::tc_event::update_onChild */
extern db_observer tc_update_onChild_o;

/* ::tc_event::update_onRootChilds */
extern db_observer tc_update_onRootChilds_o;

/* ::tc_event::update_onRootSelf */
extern db_observer tc_update_onRootSelf_o;

/* ::tc_event::update_onSelf */
extern db_observer tc_update_onSelf_o;

/* ::tc_event::value */
extern db_typedef tc_value_o;

int tc_event_load(void);
#ifdef __cplusplus
}
#endif
#endif

