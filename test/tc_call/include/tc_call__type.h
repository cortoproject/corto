/* tc_call__type.h
 *
 *  Generated on Feb  5 2014
 *    Type-definitions for C-language.
 *    This file contains generated code. Do not modify!
 */

#ifndef tc_call__type_H
#define tc_call__type_H

#include "cortex.h"
#ifdef __cplusplus
extern "C" {
#endif

/* Casting macro's for classes */
#define tc_Animal(o) ((tc_Animal)o)
#define tc_Mammal(o) ((tc_Mammal)o)

/* Type definitions */

/* ::tc_call::AnimalKind */
typedef enum tc_AnimalKind {
    TC_MAMMAL = 0,
    TC_REPTILE = 1,
    TC_INSECT = 2,
    TC_FISH = 3
} tc_AnimalKind;

/*  ::tc_call::Animal */
CX_CLASS(tc_Animal);
CX_CLASS_DEF(tc_Animal) {
    tc_AnimalKind kind;
};
/* ::tc_call::HabitatKind */
typedef enum tc_HabitatKind {
    TC_LAND = 0,
    TC_WATER = 1,
    TC_AIR = 2
} tc_HabitatKind;
/* ::tc_call::MammalKind */
typedef enum tc_MammalKind {
    TC_PRIMATE = 0,
    TC_RODENTIA = 1,
    TC_CHIROPTERA = 2,
    TC_CARNIVORA = 3
} tc_MammalKind;

/*  ::tc_call::MammalProps */
typedef struct tc_MammalProps tc_MammalProps;
struct tc_MammalProps {
    cx_uint32 legs;
    tc_HabitatKind habitat;
    cx_float64 speed;
};

/*  ::tc_call::Mammal */
CX_CLASS(tc_Mammal);
CX_CLASS_DEF(tc_Mammal) {
    CX_EXTEND(tc_Animal);
    tc_MammalKind kind;
    tc_MammalProps props;
};

#ifdef __cplusplus
}
#endif
#endif

