/* tc_Point.c
 *
 *  Generated on Feb  5 2014
 *    This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "tc_Point.h"
#include "tc_event__meta.h"


/* $begin($header) */
#include "tc__event.h"
/* $end */

/* ::tc_event::Point::construct_onThis */
cx_void tc_Point_construct_onThis(tc_Point _this, cx_object *observable, cx_object *source) {
/* $begin(::tc_event::Point::construct_onThis) */
    tcResult[observableOnConstructThis].count++;
    tcResult[observableOnConstructThis]._this = _this;
    tcResult[observableOnConstructThis].observable = observable;
    tcResult[observableOnConstructThis].source = source;
/* $end */
}

/* ::tc_event::Point::destruct_onThis */
cx_void tc_Point_destruct_onThis(tc_Point _this, cx_object *observable, cx_object *source) {
/* $begin(::tc_event::Point::destruct_onThis) */
    tcResult[observableOnDestructThis].count++;
    tcResult[observableOnDestructThis]._this = _this;
    tcResult[observableOnDestructThis].observable = observable;
    tcResult[observableOnDestructThis].source = source;
/* $end */
}

/* ::tc_event::Point::new_onThis */
cx_void tc_Point_new_onThis(tc_Point _this, cx_object *observable, cx_object *source) {
/* $begin(::tc_event::Point::new_onThis) */
    tcResult[observableOnNewThis].count++;
    tcResult[observableOnNewThis]._this = _this;
    tcResult[observableOnNewThis].observable = observable;
    tcResult[observableOnNewThis].source = source;
/* $end */
}

/* ::tc_event::Point::update_onThis */
cx_void tc_Point_update_onThis(tc_Point _this, cx_object *observable, cx_object *source) {
/* $begin(::tc_event::Point::update_onThis) */
    tcResult[observableOnUpdateThis].count++;
    tcResult[observableOnUpdateThis]._this = _this;
    tcResult[observableOnUpdateThis].observable = observable;
    tcResult[observableOnUpdateThis].source = source;
/* $end */
}
