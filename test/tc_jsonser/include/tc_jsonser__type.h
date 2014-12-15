/* tc_jsonser__type.h
 *
 *    Type-definitions for C-language.
 *    This file contains generated code. Do not modify!
 */

#ifndef tc_jsonser__type_H
#define tc_jsonser__type_H

#include "hyve.h"
#ifdef __cplusplus
extern "C" {
#endif

/* Casting macro's for classes */
#define tc_jsonser_Dog(o) ((tc_jsonser_Dog)o)

/* Type definitions */

/* ::tc_jsonser::Djinn */
typedef enum tc_jsonser_Djinn {
    TC_JSONSER_Mercury = 0,
    TC_JSONSER_Venus = 1,
    TC_JSONSER_Mars = 2,
    TC_JSONSER_Jupiter = 3
} tc_jsonser_Djinn;
/* ::tc_jsonser::DogBreed */
typedef enum tc_jsonser_DogBreed {
    TC_JSONSER_GoldenRetriever = 0,
    TC_JSONSER_Pug = 1,
    TC_JSONSER_Chihuahua = 2
} tc_jsonser_DogBreed;

/*  ::tc_jsonser::Dog */
DB_CLASS(tc_jsonser_Dog);
DB_CLASS_DEF(tc_jsonser_Dog) {
    tc_jsonser_DogBreed breed;
    db_string name;
    db_uint8 age;
    tc_jsonser_Dog lover;
};

/*  ::tc_jsonser::point2D */
typedef struct tc_jsonser_point2D tc_jsonser_point2D;
struct tc_jsonser_point2D {
    db_int32 x;
    db_int32 y;
};

#ifdef __cplusplus
}
#endif
#endif

