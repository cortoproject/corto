/* Foo__api.h
 *
 *  Generated on Jan 17 2014
 *    API convenience functions for C-language.
 *    This file contains generated code. Do not modify!
 */

#ifndef Foo__API_H
#define Foo__API_H

#include "Foo__type.h"
#include "hyve.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::Foo::Point */
Foo_Point Foo_Point__new(void);
Foo_Point Foo_Point__declare(db_object _parent, db_string _name);
int Foo_Point__define(Foo_Point _this, db_uint32 x, db_uint32 y);
Foo_Point Foo_Point__create(db_uint32 x, db_uint32 y);


#ifdef __cplusplus
}
#endif
#endif

