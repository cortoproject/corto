/* Sigar_Host.h
 *
 *  Generated on Feb  5 2014
 *    This file contains generated code. Do not modify!
 */

#ifndef Sigar_Host_H
#define Sigar_Host_H

#include "hyve.h"
#include "Sigar__type.h"

#ifdef __cplusplus
extern "C" {
#endif

/* callback ::hyve::lang::class::construct(lang::object object) -> ::Sigar::Host::construct(::Sigar::Host object) */
db_int16 Sigar_Host_construct(Sigar_Host object);

/* callback ::hyve::lang::class::destruct(lang::object object) -> ::Sigar::Host::destruct(::Sigar::Host object) */
db_void Sigar_Host_destruct(Sigar_Host object);

/* ::Sigar::Host::refresh() */
db_void Sigar_Host_refresh(Sigar_Host _this);

#ifdef __cplusplus
}
#endif
#endif

