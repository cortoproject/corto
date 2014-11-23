/* Sigar__api.c
 *
 *  Generated on Feb  5 2014
 *    API convenience functions for C-language.
 *    This file contains generated code. Do not modify!
 */

#include "Sigar__meta.h"
#include "Sigar__api.h"

Sigar_Host Sigar_Host__new(void) {
    return db_new(db_typedef(Sigar_Host_o));
}

Sigar_Host Sigar_Host__declare(db_object _parent, db_string _name) {
    return db_declare(_parent, _name, db_typedef(Sigar_Host_o));
}

int Sigar_Host__define(Sigar_Host _this, db_string name, Sigar_Stats stats) {
    _this->name = (name ? db_strdup(name) : NULL);
    _this->stats = stats;
    return db_define(_this);
}

Sigar_Host Sigar_Host__create(db_string name, Sigar_Stats stats) {
    Sigar_Host _this;
    _this = db_new(db_typedef(Sigar_Host_o));
    _this->name = (name ? db_strdup(name) : NULL);
    _this->stats = stats;
    if (db_define(_this)) {
        db_free(_this);
        _this = NULL;
    }
    return _this;
}

Sigar_Process Sigar_Process__new(void) {
    return db_new(db_typedef(Sigar_Process_o));
}

Sigar_Process Sigar_Process__declare(db_object _parent, db_string _name) {
    return db_declare(_parent, _name, db_typedef(Sigar_Process_o));
}

int Sigar_Process__define(Sigar_Process _this, Sigar_Pid pid) {
    _this->pid = pid;
    return db_define(_this);
}

Sigar_Process Sigar_Process__create(Sigar_Pid pid) {
    Sigar_Process _this;
    _this = db_new(db_typedef(Sigar_Process_o));
    _this->pid = pid;
    if (db_define(_this)) {
        db_free(_this);
        _this = NULL;
    }
    return _this;
}

