/* tc_call__meta.h
 *
 *  Generated on Feb  5 2014
 *    Loads objects in database.
 *    This file contains generated code. Do not modify!
 */

#ifndef tc_call_META_H
#define tc_call_META_H

#include "cortex.h"

#include "tc_call__type.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::tc_call */
extern cx_object tc_o;

/* ::tc_call::Animal */
extern cx_class tc_Animal_o;

/* ::tc_call::Animal::getKind() */
extern cx_method tc_Animal_getKind_o;

/* ::tc_call::Animal::kind */
extern cx_member tc_Animal_kind_o;

/* ::tc_call::Animal::matesWith(::tc_call::Animal m) */
extern cx_method tc_Animal_matesWith_o;

/* ::tc_call::AnimalKind */
extern cx_enum tc_AnimalKind_o;

/* ::tc_call::AnimalKind::FISH */
extern cx_constant (*tc_AnimalKind_FISH_o);

/* ::tc_call::AnimalKind::INSECT */
extern cx_constant (*tc_AnimalKind_INSECT_o);

/* ::tc_call::AnimalKind::MAMMAL */
extern cx_constant (*tc_AnimalKind_MAMMAL_o);

/* ::tc_call::AnimalKind::REPTILE */
extern cx_constant (*tc_AnimalKind_REPTILE_o);

/* ::tc_call::HabitatKind */
extern cx_enum tc_HabitatKind_o;

/* ::tc_call::HabitatKind::AIR */
extern cx_constant (*tc_HabitatKind_AIR_o);

/* ::tc_call::HabitatKind::LAND */
extern cx_constant (*tc_HabitatKind_LAND_o);

/* ::tc_call::HabitatKind::WATER */
extern cx_constant (*tc_HabitatKind_WATER_o);

/* ::tc_call::Mammal */
extern cx_class tc_Mammal_o;

/* ::tc_call::Mammal::getKind() */
extern cx_method tc_Mammal_getKind_o;

/* ::tc_call::Mammal::getProps(::cortex::lang::uint32 someValue) */
extern cx_method tc_Mammal_getProps_o;

/* ::tc_call::Mammal::getSpeed() */
extern cx_method tc_Mammal_getSpeed_o;

/* ::tc_call::Mammal::init(::tc_call::Mammal object) */
extern cx_callback tc_Mammal_init_o;

/* ::tc_call::Mammal::kind */
extern cx_member tc_Mammal_kind_o;

/* ::tc_call::Mammal::matesWith(::tc_call::Animal m) */
extern cx_method tc_Mammal_matesWith_o;

/* ::tc_call::Mammal::props */
extern cx_member tc_Mammal_props_o;

/* ::tc_call::Mammal::setProps(::tc_call::MammalProps props) */
extern cx_method tc_Mammal_setProps_o;

/* ::tc_call::Mammal::setSpeed(::cortex::lang::float64 speed) */
extern cx_method tc_Mammal_setSpeed_o;

/* ::tc_call::MammalKind */
extern cx_enum tc_MammalKind_o;

/* ::tc_call::MammalKind::CARNIVORA */
extern cx_constant (*tc_MammalKind_CARNIVORA_o);

/* ::tc_call::MammalKind::CHIROPTERA */
extern cx_constant (*tc_MammalKind_CHIROPTERA_o);

/* ::tc_call::MammalKind::PRIMATE */
extern cx_constant (*tc_MammalKind_PRIMATE_o);

/* ::tc_call::MammalKind::RODENTIA */
extern cx_constant (*tc_MammalKind_RODENTIA_o);

/* ::tc_call::MammalProps */
extern cx_struct tc_MammalProps_o;

/* ::tc_call::MammalProps::habitat */
extern cx_member tc_MammalProps_habitat_o;

/* ::tc_call::MammalProps::legs */
extern cx_member tc_MammalProps_legs_o;

/* ::tc_call::MammalProps::speed */
extern cx_member tc_MammalProps_speed_o;

int tc_call_load(void);
#ifdef __cplusplus
}
#endif
#endif

