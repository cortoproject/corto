/* Foo__meta.h
 *
 *  Generated on Jan 17 2014
 *    Loads objects in database.
 *    This file contains generated code. Do not modify!
 */

#ifndef Foo_META_H
#define Foo_META_H

#include "hyve.h"

#include "Foo__type.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::Foo */
extern db_void (*Foo_o);

/* ::Foo::Point */
extern db_class Foo_Point_o;

/* ::Foo::Point::add(::Foo::Point p) */
extern db_method Foo_Point_add_o;

/* ::Foo::Point::construct(::Foo::Point object) */
extern db_callback Foo_Point_construct_o;

/* ::Foo::Point::getX() */
extern db_method Foo_Point_getX_o;

/* ::Foo::Point::getY() */
extern db_method Foo_Point_getY_o;

/* ::Foo::Point::printX() */
extern db_method Foo_Point_printX_o;

/* ::Foo::Point::printY() */
extern db_method Foo_Point_printY_o;

/* ::Foo::Point::set(::hyve::lang::uint32 x,::hyve::lang::uint32 y) */
extern db_method Foo_Point_set_o;

/* ::Foo::Point::x */
extern db_member Foo_Point_x_o;

/* ::Foo::Point::y */
extern db_member Foo_Point_y_o;

int Foo_load(void);
#ifdef __cplusplus
}
#endif
#endif

