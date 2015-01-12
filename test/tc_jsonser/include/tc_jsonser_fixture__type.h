/* tc_jsonser_fixture__type.h
 *
 *    Type-definitions for C-language.
 *    This file contains generated code. Do not modify!
 */

#ifndef tc_jsonser_fixture__type_H
#define tc_jsonser_fixture__type_H

#include "cortex.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Casting macro's for classes */
#define tc_jsonser_fixture_Dog(o) ((tc_jsonser_fixture_Dog)o)

/* Type definitions */
/* ::tc_jsonser_fixture::color */
CX_BITMASK(tc_jsonser_fixture_color);
    #define TC_JSONSER_FIXTURE_red (0x1)
    #define TC_JSONSER_FIXTURE_green (0x2)
    #define TC_JSONSER_FIXTURE_blue (0x4)

/* ::tc_jsonser_fixture::Djinn */
typedef enum tc_jsonser_fixture_Djinn {
    TC_JSONSER_FIXTURE_Mercury = 0,
    TC_JSONSER_FIXTURE_Venus = 1,
    TC_JSONSER_FIXTURE_Mars = 2,
    TC_JSONSER_FIXTURE_Jupiter = 3
} tc_jsonser_fixture_Djinn;

/* ::tc_jsonser_fixture::DogBreed */
typedef enum tc_jsonser_fixture_DogBreed {
    TC_JSONSER_FIXTURE_GoldenRetriever = 0,
    TC_JSONSER_FIXTURE_Pug = 1,
    TC_JSONSER_FIXTURE_Chihuahua = 2
} tc_jsonser_fixture_DogBreed;

/*  ::tc_jsonser_fixture::Dog */
CX_CLASS(tc_jsonser_fixture_Dog);

CX_CLASS_DEF(tc_jsonser_fixture_Dog) {
    tc_jsonser_fixture_DogBreed breed;
    cx_string name;
    cx_uint8 age;
    tc_jsonser_fixture_Dog lover;
};

typedef cx_int32 tc_jsonser_fixture_intarray[4];

/*  ::tc_jsonser_fixture::point2D */
typedef struct tc_jsonser_fixture_point2D tc_jsonser_fixture_point2D;

struct tc_jsonser_fixture_point2D {
    cx_int32 x;
    cx_int32 y;
};

CX_LIST(tc_jsonser_fixture_stringlist);

#ifdef __cplusplus
}
#endif
#endif

