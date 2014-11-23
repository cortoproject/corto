/* Sigar__api.h
 *
 *  Generated on Feb  5 2014
 *    API convenience functions for C-language.
 *    This file contains generated code. Do not modify!
 */

#ifndef Sigar__API_H
#define Sigar__API_H

#include "Sigar__type.h"
#include "hyve.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::Sigar::Host */
Sigar_Host Sigar_Host__new(void);
Sigar_Host Sigar_Host__declare(db_object _parent, db_string _name);
int Sigar_Host__define(Sigar_Host _this, db_string name, Sigar_Stats stats);
Sigar_Host Sigar_Host__create(db_string name, Sigar_Stats stats);

/* ::Sigar::Process */
Sigar_Process Sigar_Process__new(void);
Sigar_Process Sigar_Process__declare(db_object _parent, db_string _name);
int Sigar_Process__define(Sigar_Process _this, Sigar_Pid pid);
Sigar_Process Sigar_Process__create(Sigar_Pid pid);


#ifdef __cplusplus
}
#endif
#endif

