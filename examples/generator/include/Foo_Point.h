/* Foo_Point.h
 *
 *  Generated on Jan 17 2014
 *    This file contains generated code. Do not modify!
 */

#ifndef Foo_Point_H
#define Foo_Point_H

#include "hyve.h"
#include "Foo__type.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::Foo::Point::add(::Foo::Point p) */
db_void Foo_Point_add(Foo_Point _this, Foo_Point p);

/* callback ::hyve::lang::class::construct(lang::object object) -> ::Foo::Point::construct(::Foo::Point object) */
db_int16 Foo_Point_construct(Foo_Point object);

/* ::Foo::Point::getX() */
db_uint32 Foo_Point_getX(Foo_Point _this);

/* ::Foo::Point::getY() */
db_uint32 Foo_Point_getY(Foo_Point _this);

/* ::Foo::Point::printX() */
db_void Foo_Point_printX(Foo_Point _this);

/* ::Foo::Point::printY() */
db_void Foo_Point_printY(Foo_Point _this);

/* ::Foo::Point::set(::hyve::lang::uint32 x,::hyve::lang::uint32 y) */
db_void Foo_Point_set(Foo_Point _this, db_uint32 x, db_uint32 y);

#ifdef __cplusplus
}
#endif
#endif

