/* PingPong__api.c
 *
 *  Generated on Feb  5 2014
 *    API convenience functions for C-language.
 *    This file contains generated code. Do not modify!
 */

#include "PingPong__meta.h"
#include "PingPong__api.h"

pp_Dispatcher pp_Dispatcher__new(void) {
    return db_new(db_typedef(pp_Dispatcher_o));
}

pp_Dispatcher pp_Dispatcher__declare(db_object _parent, db_string _name) {
    return db_declare(_parent, _name, db_typedef(pp_Dispatcher_o));
}

int pp_Dispatcher__define(pp_Dispatcher _this, db_observableEvent event) {
    event ? db_keep_ext(_this, event, "element <0x97492a0>.event") : 0; _this->event = event;
    return db_define(_this);
}

pp_Dispatcher pp_Dispatcher__create(db_observableEvent event) {
    pp_Dispatcher _this;
    _this = db_new(db_typedef(pp_Dispatcher_o));
    event ? db_keep_ext(_this, event, "element <0x97492a0>.event") : 0; _this->event = event;
    if (db_define(_this)) {
        db_free(_this);
        _this = NULL;
    }
    return _this;
}

pp_Pinger pp_Pinger__new(void) {
    return db_new(db_typedef(pp_Pinger_o));
}

pp_Pinger pp_Pinger__declare(db_object _parent, db_string _name) {
    return db_declare(_parent, _name, db_typedef(pp_Pinger_o));
}

int pp_Pinger__define(pp_Pinger _this, db_dispatcher dispatcher, db_bool isPing, pp_time lastPing, pp_time minPing, pp_time maxPing, pp_time cummPing, db_uint32 samples) {
    dispatcher ? db_keep_ext(_this, dispatcher, "element <0x9746e28>.dispatcher") : 0; _this->dispatcher = dispatcher;
    _this->isPing = isPing;
    _this->lastPing = lastPing;
    _this->minPing = minPing;
    _this->maxPing = maxPing;
    _this->cummPing = cummPing;
    _this->samples = samples;
    return db_define(_this);
}

pp_Pinger pp_Pinger__create(db_dispatcher dispatcher, db_bool isPing, pp_time lastPing, pp_time minPing, pp_time maxPing, pp_time cummPing, db_uint32 samples) {
    pp_Pinger _this;
    _this = db_new(db_typedef(pp_Pinger_o));
    dispatcher ? db_keep_ext(_this, dispatcher, "element <0x9746e28>.dispatcher") : 0; _this->dispatcher = dispatcher;
    _this->isPing = isPing;
    _this->lastPing = lastPing;
    _this->minPing = minPing;
    _this->maxPing = maxPing;
    _this->cummPing = cummPing;
    _this->samples = samples;
    if (db_define(_this)) {
        db_free(_this);
        _this = NULL;
    }
    return _this;
}

