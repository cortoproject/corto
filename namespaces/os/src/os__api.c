/* os__api.c
 *
 *    API convenience functions for C-language.
 *    This file contains generated code. Do not modify!
 */

#include "os__meta.h"
#include "os__api.h"

os_thread os_thread__new(void) {
    return db_new(db_typedef(os_thread_o));
}

os_thread os_thread__declare(db_object _parent, db_string _name) {
    return db_declare(_parent, _name, db_typedef(os_thread_o));
}

int os_thread__define(os_thread _this) {
    return db_define(_this);
}

os_thread os_thread__create(void) {
    os_thread _this;
    _this = db_new(db_typedef(os_thread_o));
    if (db_define(_this)) {
        db_free(_this);
        _this = NULL;
    }
    return _this;
}

os_time os_time__new(void) {
    return db_new(db_typedef(os_time_o));
}

os_time os_time__declare(db_object _parent, db_string _name) {
    return db_declare(_parent, _name, db_typedef(os_time_o));
}

int os_time__define(os_time _this, db_int32 seconds, db_uint32 nanoseconds) {
    _this->seconds = seconds;
    _this->nanoseconds = nanoseconds;
    return db_define(_this);
}

os_time os_time__create(db_int32 seconds, db_uint32 nanoseconds) {
    os_time _this;
    _this = db_new(db_typedef(os_time_o));
    _this->seconds = seconds;
    _this->nanoseconds = nanoseconds;
    if (db_define(_this)) {
        db_free(_this);
        _this = NULL;
    }
    return _this;
}

os_timer os_timer__new(void) {
    return db_new(db_typedef(os_timer_o));
}

os_timer os_timer__declare(db_object _parent, db_string _name) {
    return db_declare(_parent, _name, db_typedef(os_timer_o));
}

int os_timer__define(os_timer _this, db_int32 sec, db_uint32 nanosec) {
    _this->sec = sec;
    _this->nanosec = nanosec;
    return db_define(_this);
}

os_timer os_timer__create(db_int32 sec, db_uint32 nanosec) {
    os_timer _this;
    _this = db_new(db_typedef(os_timer_o));
    _this->sec = sec;
    _this->nanosec = nanosec;
    if (db_define(_this)) {
        db_free(_this);
        _this = NULL;
    }
    return _this;
}

