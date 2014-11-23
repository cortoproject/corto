/* tc_call__meta.h
 *
 *  Generated on Feb  5 2014
 *    Loads objects in database.
 *    This file contains generated code. Do not modify!
 */

#ifndef tc_call_META_H
#define tc_call_META_H

#include "hyve.h"

#include "tc_call__type.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::tc_call */
extern db_object tc_o;

/* ::tc_call::Animal */
extern db_class tc_Animal_o;

/* ::tc_call::Animal::getKind() */
extern db_method tc_Animal_getKind_o;

/* ::tc_call::Animal::kind */
extern db_member tc_Animal_kind_o;

/* ::tc_call::Animal::matesWith(::tc_call::Animal m) */
extern db_method tc_Animal_matesWith_o;

/* ::tc_call::AnimalKind */
extern db_enum tc_AnimalKind_o;

/* ::tc_call::AnimalKind::FISH */
extern db_constant (*tc_AnimalKind_FISH_o);

/* ::tc_call::AnimalKind::INSECT */
extern db_constant (*tc_AnimalKind_INSECT_o);

/* ::tc_call::AnimalKind::MAMMAL */
extern db_constant (*tc_AnimalKind_MAMMAL_o);

/* ::tc_call::AnimalKind::REPTILE */
extern db_constant (*tc_AnimalKind_REPTILE_o);

/* ::tc_call::HabitatKind */
extern db_enum tc_HabitatKind_o;

/* ::tc_call::HabitatKind::AIR */
extern db_constant (*tc_HabitatKind_AIR_o);

/* ::tc_call::HabitatKind::LAND */
extern db_constant (*tc_HabitatKind_LAND_o);

/* ::tc_call::HabitatKind::WATER */
extern db_constant (*tc_HabitatKind_WATER_o);

/* ::tc_call::Mammal */
extern db_class tc_Mammal_o;

/* ::tc_call::Mammal::getKind() */
extern db_method tc_Mammal_getKind_o;

/* ::tc_call::Mammal::getProps(::hyve::lang::uint32 someValue) */
extern db_method tc_Mammal_getProps_o;

/* ::tc_call::Mammal::getSpeed() */
extern db_method tc_Mammal_getSpeed_o;

/* ::tc_call::Mammal::init(::tc_call::Mammal object) */
extern db_callback tc_Mammal_init_o;

/* ::tc_call::Mammal::kind */
extern db_member tc_Mammal_kind_o;

/* ::tc_call::Mammal::matesWith(::tc_call::Animal m) */
extern db_method tc_Mammal_matesWith_o;

/* ::tc_call::Mammal::props */
extern db_member tc_Mammal_props_o;

/* ::tc_call::Mammal::setProps(::tc_call::MammalProps props) */
extern db_method tc_Mammal_setProps_o;

/* ::tc_call::Mammal::setSpeed(::hyve::lang::float64 speed) */
extern db_method tc_Mammal_setSpeed_o;

/* ::tc_call::MammalKind */
extern db_enum tc_MammalKind_o;

/* ::tc_call::MammalKind::CARNIVORA */
extern db_constant (*tc_MammalKind_CARNIVORA_o);

/* ::tc_call::MammalKind::CHIROPTERA */
extern db_constant (*tc_MammalKind_CHIROPTERA_o);

/* ::tc_call::MammalKind::PRIMATE */
extern db_constant (*tc_MammalKind_PRIMATE_o);

/* ::tc_call::MammalKind::RODENTIA */
extern db_constant (*tc_MammalKind_RODENTIA_o);

/* ::tc_call::MammalProps */
extern db_struct tc_MammalProps_o;

/* ::tc_call::MammalProps::habitat */
extern db_member tc_MammalProps_habitat_o;

/* ::tc_call::MammalProps::legs */
extern db_member tc_MammalProps_legs_o;

/* ::tc_call::MammalProps::speed */
extern db_member tc_MammalProps_speed_o;

int tc_call_load(void);
#ifdef __cplusplus
}
#endif
#endif

