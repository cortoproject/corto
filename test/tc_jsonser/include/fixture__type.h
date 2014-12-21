/* fixture__type.h
 *
 *    Type-definitions for C-language.
 *    This file contains generated code. Do not modify!
 */

#ifndef fixture__type_H
#define fixture__type_H

#include "hyve.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Casting macro's for classes */
#define fixture_Dog(o) ((fixture_Dog)o)

/* Type definitions */
/* ::fixture::Djinn */
typedef enum fixture_Djinn {
    FIXTURE_Mercury = 0,
    FIXTURE_Venus = 1,
    FIXTURE_Mars = 2,
    FIXTURE_Jupiter = 3
} fixture_Djinn;

/* ::fixture::DogBreed */
typedef enum fixture_DogBreed {
    FIXTURE_GoldenRetriever = 0,
    FIXTURE_Pug = 1,
    FIXTURE_Chihuahua = 2
} fixture_DogBreed;

/*  ::fixture::Dog */
DB_CLASS(fixture_Dog);

DB_CLASS_DEF(fixture_Dog) {
    fixture_DogBreed breed;
    db_string name;
    db_uint8 age;
    fixture_Dog lover;
};

typedef db_uint32 fixture_ints[4];

/*  ::fixture::point2D */
typedef struct fixture_point2D fixture_point2D;

struct fixture_point2D {
    db_int32 x;
    db_int32 y;
};

#ifdef __cplusplus
}
#endif
#endif

