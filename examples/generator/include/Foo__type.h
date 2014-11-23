/* Foo__type.h
 *
 *  Generated on Jan 17 2014
 *    Type-definitions for C-language.
 *    This file contains generated code. Do not modify!
 */

#ifndef Foo__type_H
#define Foo__type_H

#include "hyve.h"
#ifdef __cplusplus
extern "C" {
#endif

/* Casting macro's for classes */
#define Foo_Point(o) ((Foo_Point)o)

/* Type definitions */


/*  ::Foo::Point */
DB_CLASS(Foo_Point);
DB_CLASS_DEF(Foo_Point) {
    db_uint32 x;
    db_uint32 y;
};

#ifdef __cplusplus
}
#endif
#endif

