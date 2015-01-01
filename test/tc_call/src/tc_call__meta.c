/* tc_call__meta.c
 *
 *  Generated on Feb  5 2014
 *    Loads objects in database.
 *    This file contains generated code. Do not modify!
 */

#include "tc_call__type.h"

/* Variable definitions */
cx_object tc_o;
cx_class tc_Animal_o;
cx_method tc_Animal_getKind_o;
cx_member tc_Animal_kind_o;
cx_method tc_Animal_matesWith_o;
cx_enum tc_AnimalKind_o;
cx_constant (*tc_AnimalKind_FISH_o);
cx_constant (*tc_AnimalKind_INSECT_o);
cx_constant (*tc_AnimalKind_MAMMAL_o);
cx_constant (*tc_AnimalKind_REPTILE_o);
cx_enum tc_HabitatKind_o;
cx_constant (*tc_HabitatKind_AIR_o);
cx_constant (*tc_HabitatKind_LAND_o);
cx_constant (*tc_HabitatKind_WATER_o);
cx_class tc_Mammal_o;
cx_method tc_Mammal_getKind_o;
cx_method tc_Mammal_getProps_o;
cx_method tc_Mammal_getSpeed_o;
cx_callback tc_Mammal_init_o;
cx_member tc_Mammal_kind_o;
cx_method tc_Mammal_matesWith_o;
cx_member tc_Mammal_props_o;
cx_method tc_Mammal_setProps_o;
cx_method tc_Mammal_setSpeed_o;
cx_enum tc_MammalKind_o;
cx_constant (*tc_MammalKind_CARNIVORA_o);
cx_constant (*tc_MammalKind_CHIROPTERA_o);
cx_constant (*tc_MammalKind_PRIMATE_o);
cx_constant (*tc_MammalKind_RODENTIA_o);
cx_struct tc_MammalProps_o;
cx_member tc_MammalProps_habitat_o;
cx_member tc_MammalProps_legs_o;
cx_member tc_MammalProps_speed_o;

/* Load objects in database */
int tc_call_load(void) {
    cx_object _a_; /* Used for resolving anonymous objects */
    _a_ = NULL;

    /* Declare ::tc_call */
    tc_o = cx_declare(root_o, "tc_call", cx_typedef(cx_object_o));
    if (!tc_o) {
        cx_error("tc_call_load: failed to declare object '::tc_call'.");
        goto error;
    }

    /* Define ::tc_call */
    if (!cx_checkState(tc_o, CX_DEFINED)) {
        if (cx_define(tc_o)) {
            cx_error("tc_call_load: failed to define object '::tc_call'.");
            goto error;
        }
    }
    /* Declare ::tc_call::Animal */
    tc_Animal_o = cx_declare(tc_o, "Animal", cx_typedef(cx_class_o));
    if (!tc_Animal_o) {
        cx_error("tc_call_load: failed to declare object '::tc_call::Animal'.");
        goto error;
    }

    /* Declare ::tc_call::Animal::getKind() */
    tc_Animal_getKind_o = cx_declare(tc_Animal_o, "getKind()", cx_typedef(cx_method_o));
    if (!tc_Animal_getKind_o) {
        cx_error("tc_call_load: failed to declare object '::tc_call::Animal::getKind()'.");
        goto error;
    }

    /* Declare ::tc_call::Animal::kind */
    tc_Animal_kind_o = cx_declare(tc_Animal_o, "kind", cx_typedef(cx_member_o));
    if (!tc_Animal_kind_o) {
        cx_error("tc_call_load: failed to declare object '::tc_call::Animal::kind'.");
        goto error;
    }

    /* Declare ::tc_call::AnimalKind */
    tc_AnimalKind_o = cx_declare(tc_o, "AnimalKind", cx_typedef(cx_enum_o));
    if (!tc_AnimalKind_o) {
        cx_error("tc_call_load: failed to declare object '::tc_call::AnimalKind'.");
        goto error;
    }

    /* Declare ::tc_call::AnimalKind::FISH */
    tc_AnimalKind_FISH_o = cx_declare(tc_AnimalKind_o, "FISH", cx_typedef(cx_constant_o));
    if (!tc_AnimalKind_FISH_o) {
        cx_error("tc_call_load: failed to declare object '::tc_call::AnimalKind::FISH'.");
        goto error;
    }

    /* Define ::tc_call::AnimalKind::FISH */
    if (!cx_checkState(tc_AnimalKind_FISH_o, CX_DEFINED)) {
        (*tc_AnimalKind_FISH_o) = 3;
        if (cx_define(tc_AnimalKind_FISH_o)) {
            cx_error("tc_call_load: failed to define object '::tc_call::AnimalKind::FISH'.");
            goto error;
        }
    }
    /* Declare ::tc_call::AnimalKind::INSECT */
    tc_AnimalKind_INSECT_o = cx_declare(tc_AnimalKind_o, "INSECT", cx_typedef(cx_constant_o));
    if (!tc_AnimalKind_INSECT_o) {
        cx_error("tc_call_load: failed to declare object '::tc_call::AnimalKind::INSECT'.");
        goto error;
    }

    /* Define ::tc_call::AnimalKind::INSECT */
    if (!cx_checkState(tc_AnimalKind_INSECT_o, CX_DEFINED)) {
        (*tc_AnimalKind_INSECT_o) = 2;
        if (cx_define(tc_AnimalKind_INSECT_o)) {
            cx_error("tc_call_load: failed to define object '::tc_call::AnimalKind::INSECT'.");
            goto error;
        }
    }
    /* Declare ::tc_call::AnimalKind::MAMMAL */
    tc_AnimalKind_MAMMAL_o = cx_declare(tc_AnimalKind_o, "MAMMAL", cx_typedef(cx_constant_o));
    if (!tc_AnimalKind_MAMMAL_o) {
        cx_error("tc_call_load: failed to declare object '::tc_call::AnimalKind::MAMMAL'.");
        goto error;
    }

    /* Define ::tc_call::AnimalKind::MAMMAL */
    if (!cx_checkState(tc_AnimalKind_MAMMAL_o, CX_DEFINED)) {
        (*tc_AnimalKind_MAMMAL_o) = 0;
        if (cx_define(tc_AnimalKind_MAMMAL_o)) {
            cx_error("tc_call_load: failed to define object '::tc_call::AnimalKind::MAMMAL'.");
            goto error;
        }
    }
    /* Declare ::tc_call::AnimalKind::REPTILE */
    tc_AnimalKind_REPTILE_o = cx_declare(tc_AnimalKind_o, "REPTILE", cx_typedef(cx_constant_o));
    if (!tc_AnimalKind_REPTILE_o) {
        cx_error("tc_call_load: failed to declare object '::tc_call::AnimalKind::REPTILE'.");
        goto error;
    }

    /* Define ::tc_call::AnimalKind::REPTILE */
    if (!cx_checkState(tc_AnimalKind_REPTILE_o, CX_DEFINED)) {
        (*tc_AnimalKind_REPTILE_o) = 1;
        if (cx_define(tc_AnimalKind_REPTILE_o)) {
            cx_error("tc_call_load: failed to define object '::tc_call::AnimalKind::REPTILE'.");
            goto error;
        }
    }
    /* Define ::tc_call::AnimalKind */
    if (!cx_checkState(tc_AnimalKind_o, CX_DEFINED)) {
        if (cx_define(tc_AnimalKind_o)) {
            cx_error("tc_call_load: failed to define object '::tc_call::AnimalKind'.");
            goto error;
        }
    }
    /* Define ::tc_call::Animal::getKind() */
    if (!cx_checkState(tc_Animal_getKind_o, CX_DEFINED)) {
        cx_function(tc_Animal_getKind_o)->returnType = cx_resolve_ext(tc_Animal_getKind_o, NULL, "::tc_call::AnimalKind", FALSE, "element ::tc_call::Animal::getKind().returnType");
        tc_Animal_getKind_o->virtual = FALSE;
        
        /* Bind tc_Animal_getKind_o with C-function */
        cx_function(tc_Animal_getKind_o)->kind = CX_PROCEDURE_CDECL;
        tc_AnimalKind tc_Animal_getKind(tc_Animal _this);
        cx_function(tc_Animal_getKind_o)->impl = (cx_word)tc_Animal_getKind;
        if (cx_define(tc_Animal_getKind_o)) {
            cx_error("tc_call_load: failed to define object '::tc_call::Animal::getKind()'.");
            goto error;
        }
    }
    /* Define ::tc_call::Animal::kind */
    if (!cx_checkState(tc_Animal_kind_o, CX_DEFINED)) {
        tc_Animal_kind_o->type = cx_resolve_ext(tc_Animal_kind_o, NULL, "::tc_call::AnimalKind", FALSE, "element ::tc_call::Animal::kind.type");
        tc_Animal_kind_o->modifiers = 0x0;
        tc_Animal_kind_o->state = 0x6;
        tc_Animal_kind_o->weak = FALSE;
        tc_Animal_kind_o->id = 0;
        if (cx_define(tc_Animal_kind_o)) {
            cx_error("tc_call_load: failed to define object '::tc_call::Animal::kind'.");
            goto error;
        }
    }
    /* Declare ::tc_call::HabitatKind */
    tc_HabitatKind_o = cx_declare(tc_o, "HabitatKind", cx_typedef(cx_enum_o));
    if (!tc_HabitatKind_o) {
        cx_error("tc_call_load: failed to declare object '::tc_call::HabitatKind'.");
        goto error;
    }

    /* Declare ::tc_call::HabitatKind::AIR */
    tc_HabitatKind_AIR_o = cx_declare(tc_HabitatKind_o, "AIR", cx_typedef(cx_constant_o));
    if (!tc_HabitatKind_AIR_o) {
        cx_error("tc_call_load: failed to declare object '::tc_call::HabitatKind::AIR'.");
        goto error;
    }

    /* Define ::tc_call::HabitatKind::AIR */
    if (!cx_checkState(tc_HabitatKind_AIR_o, CX_DEFINED)) {
        (*tc_HabitatKind_AIR_o) = 2;
        if (cx_define(tc_HabitatKind_AIR_o)) {
            cx_error("tc_call_load: failed to define object '::tc_call::HabitatKind::AIR'.");
            goto error;
        }
    }
    /* Declare ::tc_call::HabitatKind::LAND */
    tc_HabitatKind_LAND_o = cx_declare(tc_HabitatKind_o, "LAND", cx_typedef(cx_constant_o));
    if (!tc_HabitatKind_LAND_o) {
        cx_error("tc_call_load: failed to declare object '::tc_call::HabitatKind::LAND'.");
        goto error;
    }

    /* Define ::tc_call::HabitatKind::LAND */
    if (!cx_checkState(tc_HabitatKind_LAND_o, CX_DEFINED)) {
        (*tc_HabitatKind_LAND_o) = 0;
        if (cx_define(tc_HabitatKind_LAND_o)) {
            cx_error("tc_call_load: failed to define object '::tc_call::HabitatKind::LAND'.");
            goto error;
        }
    }
    /* Declare ::tc_call::HabitatKind::WATER */
    tc_HabitatKind_WATER_o = cx_declare(tc_HabitatKind_o, "WATER", cx_typedef(cx_constant_o));
    if (!tc_HabitatKind_WATER_o) {
        cx_error("tc_call_load: failed to declare object '::tc_call::HabitatKind::WATER'.");
        goto error;
    }

    /* Define ::tc_call::HabitatKind::WATER */
    if (!cx_checkState(tc_HabitatKind_WATER_o, CX_DEFINED)) {
        (*tc_HabitatKind_WATER_o) = 1;
        if (cx_define(tc_HabitatKind_WATER_o)) {
            cx_error("tc_call_load: failed to define object '::tc_call::HabitatKind::WATER'.");
            goto error;
        }
    }
    /* Define ::tc_call::HabitatKind */
    if (!cx_checkState(tc_HabitatKind_o, CX_DEFINED)) {
        if (cx_define(tc_HabitatKind_o)) {
            cx_error("tc_call_load: failed to define object '::tc_call::HabitatKind'.");
            goto error;
        }
    }
    /* Declare ::tc_call::Mammal */
    tc_Mammal_o = cx_declare(tc_o, "Mammal", cx_typedef(cx_class_o));
    if (!tc_Mammal_o) {
        cx_error("tc_call_load: failed to declare object '::tc_call::Mammal'.");
        goto error;
    }

    /* Declare ::tc_call::Mammal::kind */
    tc_Mammal_kind_o = cx_declare(tc_Mammal_o, "kind", cx_typedef(cx_member_o));
    if (!tc_Mammal_kind_o) {
        cx_error("tc_call_load: failed to declare object '::tc_call::Mammal::kind'.");
        goto error;
    }

    /* Declare ::tc_call::Mammal::props */
    tc_Mammal_props_o = cx_declare(tc_Mammal_o, "props", cx_typedef(cx_member_o));
    if (!tc_Mammal_props_o) {
        cx_error("tc_call_load: failed to declare object '::tc_call::Mammal::props'.");
        goto error;
    }

    /* Declare ::tc_call::MammalKind */
    tc_MammalKind_o = cx_declare(tc_o, "MammalKind", cx_typedef(cx_enum_o));
    if (!tc_MammalKind_o) {
        cx_error("tc_call_load: failed to declare object '::tc_call::MammalKind'.");
        goto error;
    }

    /* Declare ::tc_call::MammalKind::CARNIVORA */
    tc_MammalKind_CARNIVORA_o = cx_declare(tc_MammalKind_o, "CARNIVORA", cx_typedef(cx_constant_o));
    if (!tc_MammalKind_CARNIVORA_o) {
        cx_error("tc_call_load: failed to declare object '::tc_call::MammalKind::CARNIVORA'.");
        goto error;
    }

    /* Define ::tc_call::MammalKind::CARNIVORA */
    if (!cx_checkState(tc_MammalKind_CARNIVORA_o, CX_DEFINED)) {
        (*tc_MammalKind_CARNIVORA_o) = 3;
        if (cx_define(tc_MammalKind_CARNIVORA_o)) {
            cx_error("tc_call_load: failed to define object '::tc_call::MammalKind::CARNIVORA'.");
            goto error;
        }
    }
    /* Declare ::tc_call::MammalKind::CHIROPTERA */
    tc_MammalKind_CHIROPTERA_o = cx_declare(tc_MammalKind_o, "CHIROPTERA", cx_typedef(cx_constant_o));
    if (!tc_MammalKind_CHIROPTERA_o) {
        cx_error("tc_call_load: failed to declare object '::tc_call::MammalKind::CHIROPTERA'.");
        goto error;
    }

    /* Define ::tc_call::MammalKind::CHIROPTERA */
    if (!cx_checkState(tc_MammalKind_CHIROPTERA_o, CX_DEFINED)) {
        (*tc_MammalKind_CHIROPTERA_o) = 2;
        if (cx_define(tc_MammalKind_CHIROPTERA_o)) {
            cx_error("tc_call_load: failed to define object '::tc_call::MammalKind::CHIROPTERA'.");
            goto error;
        }
    }
    /* Declare ::tc_call::MammalKind::PRIMATE */
    tc_MammalKind_PRIMATE_o = cx_declare(tc_MammalKind_o, "PRIMATE", cx_typedef(cx_constant_o));
    if (!tc_MammalKind_PRIMATE_o) {
        cx_error("tc_call_load: failed to declare object '::tc_call::MammalKind::PRIMATE'.");
        goto error;
    }

    /* Define ::tc_call::MammalKind::PRIMATE */
    if (!cx_checkState(tc_MammalKind_PRIMATE_o, CX_DEFINED)) {
        (*tc_MammalKind_PRIMATE_o) = 0;
        if (cx_define(tc_MammalKind_PRIMATE_o)) {
            cx_error("tc_call_load: failed to define object '::tc_call::MammalKind::PRIMATE'.");
            goto error;
        }
    }
    /* Declare ::tc_call::MammalKind::RODENTIA */
    tc_MammalKind_RODENTIA_o = cx_declare(tc_MammalKind_o, "RODENTIA", cx_typedef(cx_constant_o));
    if (!tc_MammalKind_RODENTIA_o) {
        cx_error("tc_call_load: failed to declare object '::tc_call::MammalKind::RODENTIA'.");
        goto error;
    }

    /* Define ::tc_call::MammalKind::RODENTIA */
    if (!cx_checkState(tc_MammalKind_RODENTIA_o, CX_DEFINED)) {
        (*tc_MammalKind_RODENTIA_o) = 1;
        if (cx_define(tc_MammalKind_RODENTIA_o)) {
            cx_error("tc_call_load: failed to define object '::tc_call::MammalKind::RODENTIA'.");
            goto error;
        }
    }
    /* Define ::tc_call::MammalKind */
    if (!cx_checkState(tc_MammalKind_o, CX_DEFINED)) {
        if (cx_define(tc_MammalKind_o)) {
            cx_error("tc_call_load: failed to define object '::tc_call::MammalKind'.");
            goto error;
        }
    }
    /* Define ::tc_call::Mammal::kind */
    if (!cx_checkState(tc_Mammal_kind_o, CX_DEFINED)) {
        tc_Mammal_kind_o->type = cx_resolve_ext(tc_Mammal_kind_o, NULL, "::tc_call::MammalKind", FALSE, "element ::tc_call::Mammal::kind.type");
        tc_Mammal_kind_o->modifiers = 0x0;
        tc_Mammal_kind_o->state = 0x6;
        tc_Mammal_kind_o->weak = FALSE;
        tc_Mammal_kind_o->id = 0;
        if (cx_define(tc_Mammal_kind_o)) {
            cx_error("tc_call_load: failed to define object '::tc_call::Mammal::kind'.");
            goto error;
        }
    }
    /* Declare ::tc_call::MammalProps */
    tc_MammalProps_o = cx_declare(tc_o, "MammalProps", cx_typedef(cx_struct_o));
    if (!tc_MammalProps_o) {
        cx_error("tc_call_load: failed to declare object '::tc_call::MammalProps'.");
        goto error;
    }

    /* Declare ::tc_call::MammalProps::habitat */
    tc_MammalProps_habitat_o = cx_declare(tc_MammalProps_o, "habitat", cx_typedef(cx_member_o));
    if (!tc_MammalProps_habitat_o) {
        cx_error("tc_call_load: failed to declare object '::tc_call::MammalProps::habitat'.");
        goto error;
    }

    /* Define ::tc_call::MammalProps::habitat */
    if (!cx_checkState(tc_MammalProps_habitat_o, CX_DEFINED)) {
        tc_MammalProps_habitat_o->type = cx_resolve_ext(tc_MammalProps_habitat_o, NULL, "::tc_call::HabitatKind", FALSE, "element ::tc_call::MammalProps::habitat.type");
        tc_MammalProps_habitat_o->modifiers = 0x0;
        tc_MammalProps_habitat_o->state = 0x6;
        tc_MammalProps_habitat_o->weak = FALSE;
        tc_MammalProps_habitat_o->id = 1;
        if (cx_define(tc_MammalProps_habitat_o)) {
            cx_error("tc_call_load: failed to define object '::tc_call::MammalProps::habitat'.");
            goto error;
        }
    }
    /* Declare ::tc_call::MammalProps::legs */
    tc_MammalProps_legs_o = cx_declare(tc_MammalProps_o, "legs", cx_typedef(cx_member_o));
    if (!tc_MammalProps_legs_o) {
        cx_error("tc_call_load: failed to declare object '::tc_call::MammalProps::legs'.");
        goto error;
    }

    /* Define ::tc_call::MammalProps::legs */
    if (!cx_checkState(tc_MammalProps_legs_o, CX_DEFINED)) {
        tc_MammalProps_legs_o->type = cx_resolve_ext(tc_MammalProps_legs_o, NULL, "::cortex::lang::uint32", FALSE, "element ::tc_call::MammalProps::legs.type");
        tc_MammalProps_legs_o->modifiers = 0x0;
        tc_MammalProps_legs_o->state = 0x6;
        tc_MammalProps_legs_o->weak = FALSE;
        tc_MammalProps_legs_o->id = 0;
        if (cx_define(tc_MammalProps_legs_o)) {
            cx_error("tc_call_load: failed to define object '::tc_call::MammalProps::legs'.");
            goto error;
        }
    }
    /* Declare ::tc_call::MammalProps::speed */
    tc_MammalProps_speed_o = cx_declare(tc_MammalProps_o, "speed", cx_typedef(cx_member_o));
    if (!tc_MammalProps_speed_o) {
        cx_error("tc_call_load: failed to declare object '::tc_call::MammalProps::speed'.");
        goto error;
    }

    /* Define ::tc_call::MammalProps::speed */
    if (!cx_checkState(tc_MammalProps_speed_o, CX_DEFINED)) {
        tc_MammalProps_speed_o->type = cx_resolve_ext(tc_MammalProps_speed_o, NULL, "::cortex::lang::float64", FALSE, "element ::tc_call::MammalProps::speed.type");
        tc_MammalProps_speed_o->modifiers = 0x0;
        tc_MammalProps_speed_o->state = 0x6;
        tc_MammalProps_speed_o->weak = FALSE;
        tc_MammalProps_speed_o->id = 2;
        if (cx_define(tc_MammalProps_speed_o)) {
            cx_error("tc_call_load: failed to define object '::tc_call::MammalProps::speed'.");
            goto error;
        }
    }
    /* Define ::tc_call::MammalProps */
    if (!cx_checkState(tc_MammalProps_o, CX_DEFINED)) {
        cx_type(tc_MammalProps_o)->parentType = NULL;
        cx_type(tc_MammalProps_o)->parentState = 0x0;
        cx_interface(tc_MammalProps_o)->base = NULL;
        tc_MammalProps_o->baseAccess = 0x0;
        if (cx_define(tc_MammalProps_o)) {
            cx_error("tc_call_load: failed to define object '::tc_call::MammalProps'.");
            goto error;
        }
    }
    /* Define ::tc_call::Mammal::props */
    if (!cx_checkState(tc_Mammal_props_o, CX_DEFINED)) {
        tc_Mammal_props_o->type = cx_resolve_ext(tc_Mammal_props_o, NULL, "::tc_call::MammalProps", FALSE, "element ::tc_call::Mammal::props.type");
        tc_Mammal_props_o->modifiers = 0x1;
        tc_Mammal_props_o->state = 0x6;
        tc_Mammal_props_o->weak = FALSE;
        tc_Mammal_props_o->id = 1;
        if (cx_define(tc_Mammal_props_o)) {
            cx_error("tc_call_load: failed to define object '::tc_call::Mammal::props'.");
            goto error;
        }
    }
    /* Declare ::tc_call::Animal::matesWith(::tc_call::Animal m) */
    tc_Animal_matesWith_o = cx_declare(tc_Animal_o, "matesWith(::tc_call::Animal m)", cx_typedef(cx_method_o));
    if (!tc_Animal_matesWith_o) {
        cx_error("tc_call_load: failed to declare object '::tc_call::Animal::matesWith(::tc_call::Animal m)'.");
        goto error;
    }

    /* Define ::tc_call::Animal::matesWith(::tc_call::Animal m) */
    if (!cx_checkState(tc_Animal_matesWith_o, CX_DEFINED)) {
        cx_function(tc_Animal_matesWith_o)->returnType = cx_resolve_ext(tc_Animal_matesWith_o, NULL, "::cortex::lang::bool", FALSE, "element ::tc_call::Animal::matesWith(::tc_call::Animal m).returnType");
        tc_Animal_matesWith_o->virtual = TRUE;
        
        /* Bind tc_Animal_matesWith_o with C-function */
        cx_function(tc_Animal_matesWith_o)->kind = CX_PROCEDURE_CDECL;
        cx_bool tc_Animal_matesWith_v(tc_Animal _this, tc_Animal m);
        cx_function(tc_Animal_matesWith_o)->impl = (cx_word)tc_Animal_matesWith_v;
        if (cx_define(tc_Animal_matesWith_o)) {
            cx_error("tc_call_load: failed to define object '::tc_call::Animal::matesWith(::tc_call::Animal m)'.");
            goto error;
        }
    }
    /* Define ::tc_call::Animal */
    if (!cx_checkState(tc_Animal_o, CX_DEFINED)) {
        cx_type(tc_Animal_o)->parentType = NULL;
        cx_type(tc_Animal_o)->parentState = 0x0;
        cx_interface(tc_Animal_o)->base = NULL;
        cx_struct(tc_Animal_o)->baseAccess = 0x0;
        tc_Animal_o->implements.length = 0;
        tc_Animal_o->implements.buffer = NULL;
        if (cx_define(tc_Animal_o)) {
            cx_error("tc_call_load: failed to define object '::tc_call::Animal'.");
            goto error;
        }
    }
    /* Declare ::tc_call::Mammal::getKind() */
    tc_Mammal_getKind_o = cx_declare(tc_Mammal_o, "getKind()", cx_typedef(cx_method_o));
    if (!tc_Mammal_getKind_o) {
        cx_error("tc_call_load: failed to declare object '::tc_call::Mammal::getKind()'.");
        goto error;
    }

    /* Define ::tc_call::Mammal::getKind() */
    if (!cx_checkState(tc_Mammal_getKind_o, CX_DEFINED)) {
        cx_function(tc_Mammal_getKind_o)->returnType = cx_resolve_ext(tc_Mammal_getKind_o, NULL, "::tc_call::MammalKind", FALSE, "element ::tc_call::Mammal::getKind().returnType");
        tc_Mammal_getKind_o->virtual = FALSE;
        
        /* Bind tc_Mammal_getKind_o with C-function */
        cx_function(tc_Mammal_getKind_o)->kind = CX_PROCEDURE_CDECL;
        tc_MammalKind tc_Mammal_getKind(tc_Mammal _this);
        cx_function(tc_Mammal_getKind_o)->impl = (cx_word)tc_Mammal_getKind;
        if (cx_define(tc_Mammal_getKind_o)) {
            cx_error("tc_call_load: failed to define object '::tc_call::Mammal::getKind()'.");
            goto error;
        }
    }
    /* Declare ::tc_call::Mammal::getProps(::cortex::lang::uint32 someValue) */
    tc_Mammal_getProps_o = cx_declare(tc_Mammal_o, "getProps(::cortex::lang::uint32 someValue)", cx_typedef(cx_method_o));
    if (!tc_Mammal_getProps_o) {
        cx_error("tc_call_load: failed to declare object '::tc_call::Mammal::getProps(::cortex::lang::uint32 someValue)'.");
        goto error;
    }

    /* Define ::tc_call::Mammal::getProps(::cortex::lang::uint32 someValue) */
    if (!cx_checkState(tc_Mammal_getProps_o, CX_DEFINED)) {
        cx_function(tc_Mammal_getProps_o)->returnType = cx_resolve_ext(tc_Mammal_getProps_o, NULL, "::tc_call::MammalProps", FALSE, "element ::tc_call::Mammal::getProps(::cortex::lang::uint32 someValue).returnType");
        tc_Mammal_getProps_o->virtual = FALSE;
        
        /* Bind tc_Mammal_getProps_o with C-function */
        cx_function(tc_Mammal_getProps_o)->kind = CX_PROCEDURE_CDECL;
        tc_MammalProps tc_Mammal_getProps(tc_Mammal _this, cx_uint32 someValue);
        cx_function(tc_Mammal_getProps_o)->impl = (cx_word)tc_Mammal_getProps;
        if (cx_define(tc_Mammal_getProps_o)) {
            cx_error("tc_call_load: failed to define object '::tc_call::Mammal::getProps(::cortex::lang::uint32 someValue)'.");
            goto error;
        }
    }
    /* Declare ::tc_call::Mammal::getSpeed() */
    tc_Mammal_getSpeed_o = cx_declare(tc_Mammal_o, "getSpeed()", cx_typedef(cx_method_o));
    if (!tc_Mammal_getSpeed_o) {
        cx_error("tc_call_load: failed to declare object '::tc_call::Mammal::getSpeed()'.");
        goto error;
    }

    /* Define ::tc_call::Mammal::getSpeed() */
    if (!cx_checkState(tc_Mammal_getSpeed_o, CX_DEFINED)) {
        cx_function(tc_Mammal_getSpeed_o)->returnType = cx_resolve_ext(tc_Mammal_getSpeed_o, NULL, "::cortex::lang::float64", FALSE, "element ::tc_call::Mammal::getSpeed().returnType");
        tc_Mammal_getSpeed_o->virtual = FALSE;
        
        /* Bind tc_Mammal_getSpeed_o with C-function */
        cx_function(tc_Mammal_getSpeed_o)->kind = CX_PROCEDURE_CDECL;
        cx_float64 tc_Mammal_getSpeed(tc_Mammal _this);
        cx_function(tc_Mammal_getSpeed_o)->impl = (cx_word)tc_Mammal_getSpeed;
        if (cx_define(tc_Mammal_getSpeed_o)) {
            cx_error("tc_call_load: failed to define object '::tc_call::Mammal::getSpeed()'.");
            goto error;
        }
    }
    /* Declare ::tc_call::Mammal::init(::tc_call::Mammal object) */
    tc_Mammal_init_o = cx_declare(tc_Mammal_o, "init(::tc_call::Mammal object)", cx_typedef(cx_callback_o));
    if (!tc_Mammal_init_o) {
        cx_error("tc_call_load: failed to declare object '::tc_call::Mammal::init(::tc_call::Mammal object)'.");
        goto error;
    }

    /* Define ::tc_call::Mammal::init(::tc_call::Mammal object) */
    if (!cx_checkState(tc_Mammal_init_o, CX_DEFINED)) {
        cx_function(tc_Mammal_init_o)->returnType = cx_resolve_ext(tc_Mammal_init_o, NULL, "::cortex::lang::int16", FALSE, "element ::tc_call::Mammal::init(::tc_call::Mammal object).returnType");
        tc_Mammal_init_o->delegate = cx_resolve_ext(tc_Mammal_init_o, NULL, "::cortex::lang::type::init(lang::object object)", FALSE, "element ::tc_call::Mammal::init(::tc_call::Mammal object).delegate");
        
        /* Bind tc_Mammal_init_o with C-function */
        cx_function(tc_Mammal_init_o)->kind = CX_PROCEDURE_CDECL;
        cx_int16 tc_Mammal_init(tc_Mammal object);
        cx_function(tc_Mammal_init_o)->impl = (cx_word)tc_Mammal_init;
        if (cx_define(tc_Mammal_init_o)) {
            cx_error("tc_call_load: failed to define object '::tc_call::Mammal::init(::tc_call::Mammal object)'.");
            goto error;
        }
    }
    /* Declare ::tc_call::Mammal::matesWith(::tc_call::Animal m) */
    tc_Mammal_matesWith_o = cx_declare(tc_Mammal_o, "matesWith(::tc_call::Animal m)", cx_typedef(cx_method_o));
    if (!tc_Mammal_matesWith_o) {
        cx_error("tc_call_load: failed to declare object '::tc_call::Mammal::matesWith(::tc_call::Animal m)'.");
        goto error;
    }

    /* Define ::tc_call::Mammal::matesWith(::tc_call::Animal m) */
    if (!cx_checkState(tc_Mammal_matesWith_o, CX_DEFINED)) {
        cx_function(tc_Mammal_matesWith_o)->returnType = cx_resolve_ext(tc_Mammal_matesWith_o, NULL, "::cortex::lang::bool", FALSE, "element ::tc_call::Mammal::matesWith(::tc_call::Animal m).returnType");
        tc_Mammal_matesWith_o->virtual = TRUE;
        
        /* Bind tc_Mammal_matesWith_o with C-function */
        cx_function(tc_Mammal_matesWith_o)->kind = CX_PROCEDURE_CDECL;
        cx_bool tc_Mammal_matesWith_v(tc_Mammal _this, tc_Animal m);
        cx_function(tc_Mammal_matesWith_o)->impl = (cx_word)tc_Mammal_matesWith_v;
        if (cx_define(tc_Mammal_matesWith_o)) {
            cx_error("tc_call_load: failed to define object '::tc_call::Mammal::matesWith(::tc_call::Animal m)'.");
            goto error;
        }
    }
    /* Declare ::tc_call::Mammal::setProps(::tc_call::MammalProps props) */
    tc_Mammal_setProps_o = cx_declare(tc_Mammal_o, "setProps(::tc_call::MammalProps props)", cx_typedef(cx_method_o));
    if (!tc_Mammal_setProps_o) {
        cx_error("tc_call_load: failed to declare object '::tc_call::Mammal::setProps(::tc_call::MammalProps props)'.");
        goto error;
    }

    /* Define ::tc_call::Mammal::setProps(::tc_call::MammalProps props) */
    if (!cx_checkState(tc_Mammal_setProps_o, CX_DEFINED)) {
        cx_function(tc_Mammal_setProps_o)->returnType = cx_resolve_ext(tc_Mammal_setProps_o, NULL, "::cortex::lang::void", FALSE, "element ::tc_call::Mammal::setProps(::tc_call::MammalProps props).returnType");
        tc_Mammal_setProps_o->virtual = FALSE;
        
        /* Bind tc_Mammal_setProps_o with C-function */
        cx_function(tc_Mammal_setProps_o)->kind = CX_PROCEDURE_CDECL;
        cx_void tc_Mammal_setProps(tc_Mammal _this, tc_MammalProps props);
        cx_function(tc_Mammal_setProps_o)->impl = (cx_word)tc_Mammal_setProps;
        if (cx_define(tc_Mammal_setProps_o)) {
            cx_error("tc_call_load: failed to define object '::tc_call::Mammal::setProps(::tc_call::MammalProps props)'.");
            goto error;
        }
    }
    /* Declare ::tc_call::Mammal::setSpeed(::cortex::lang::float64 speed) */
    tc_Mammal_setSpeed_o = cx_declare(tc_Mammal_o, "setSpeed(::cortex::lang::float64 speed)", cx_typedef(cx_method_o));
    if (!tc_Mammal_setSpeed_o) {
        cx_error("tc_call_load: failed to declare object '::tc_call::Mammal::setSpeed(::cortex::lang::float64 speed)'.");
        goto error;
    }

    /* Define ::tc_call::Mammal::setSpeed(::cortex::lang::float64 speed) */
    if (!cx_checkState(tc_Mammal_setSpeed_o, CX_DEFINED)) {
        cx_function(tc_Mammal_setSpeed_o)->returnType = cx_resolve_ext(tc_Mammal_setSpeed_o, NULL, "::cortex::lang::void", FALSE, "element ::tc_call::Mammal::setSpeed(::cortex::lang::float64 speed).returnType");
        tc_Mammal_setSpeed_o->virtual = FALSE;
        
        /* Bind tc_Mammal_setSpeed_o with C-function */
        cx_function(tc_Mammal_setSpeed_o)->kind = CX_PROCEDURE_CDECL;
        cx_void tc_Mammal_setSpeed(tc_Mammal _this, cx_float64 speed);
        cx_function(tc_Mammal_setSpeed_o)->impl = (cx_word)tc_Mammal_setSpeed;
        if (cx_define(tc_Mammal_setSpeed_o)) {
            cx_error("tc_call_load: failed to define object '::tc_call::Mammal::setSpeed(::cortex::lang::float64 speed)'.");
            goto error;
        }
    }
    /* Define ::tc_call::Mammal */
    if (!cx_checkState(tc_Mammal_o, CX_DEFINED)) {
        cx_type(tc_Mammal_o)->parentType = NULL;
        cx_type(tc_Mammal_o)->parentState = 0x0;
        cx_interface(tc_Mammal_o)->base = cx_resolve_ext(tc_Mammal_o, NULL, "::tc_call::Animal", FALSE, "element ::tc_call::Mammal.base");
        cx_struct(tc_Mammal_o)->baseAccess = 0x1;
        tc_Mammal_o->implements.length = 0;
        tc_Mammal_o->implements.buffer = NULL;
        if (cx_define(tc_Mammal_o)) {
            cx_error("tc_call_load: failed to define object '::tc_call::Mammal'.");
            goto error;
        }
    }
    if (_a_) {
        cx_free(_a_);
    }

    return 0;
error:
    return -1;
}
