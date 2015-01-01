/* os__api.c
 *
 *    API convenience functions for C-language.
 *    This file contains generated code. Do not modify!
 */

#include "os__meta.h"
#include "os__api.h"

os_thread os_thread__new(void) {
    return cx_new(cx_typedef(os_thread_o));
}

os_thread os_thread__declare(cx_object _parent, cx_string _name) {
    return cx_declare(_parent, _name, cx_typedef(os_thread_o));
}

int os_thread__define(os_thread _this) {
    return cx_define(_this);
}

os_thread os_thread__create(void) {
    os_thread _this;
    _this = cx_new(cx_typedef(os_thread_o));
    if (cx_define(_this)) {
        cx_free(_this);
        _this = NULL;
    }
    return _this;
}

os_time os_time__new(void) {
    return cx_new(cx_typedef(os_time_o));
}

os_time os_time__declare(cx_object _parent, cx_string _name) {
    return cx_declare(_parent, _name, cx_typedef(os_time_o));
}

int os_time__define(os_time _this, cx_int32 seconds, cx_uint32 nanoseconds) {
    _this->seconds = seconds;
    _this->nanoseconds = nanoseconds;
    return cx_define(_this);
}

os_time os_time__create(cx_int32 seconds, cx_uint32 nanoseconds) {
    os_time _this;
    _this = cx_new(cx_typedef(os_time_o));
    _this->seconds = seconds;
    _this->nanoseconds = nanoseconds;
    if (cx_define(_this)) {
        cx_free(_this);
        _this = NULL;
    }
    return _this;
}

os_timer os_timer__new(void) {
    return cx_new(cx_typedef(os_timer_o));
}

os_timer os_timer__declare(cx_object _parent, cx_string _name) {
    return cx_declare(_parent, _name, cx_typedef(os_timer_o));
}

int os_timer__define(os_timer _this, cx_int32 sec, cx_uint32 nanosec) {
    _this->sec = sec;
    _this->nanosec = nanosec;
    return cx_define(_this);
}

os_timer os_timer__create(cx_int32 sec, cx_uint32 nanosec) {
    os_timer _this;
    _this = cx_new(cx_typedef(os_timer_o));
    _this->sec = sec;
    _this->nanosec = nanosec;
    if (cx_define(_this)) {
        cx_free(_this);
        _this = NULL;
    }
    return _this;
}

