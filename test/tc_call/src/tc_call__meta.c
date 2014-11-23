/* tc_call__meta.c
 *
 *  Generated on Feb  5 2014
 *    Loads objects in database.
 *    This file contains generated code. Do not modify!
 */

#include "tc_call__type.h"

/* Variable definitions */
db_object tc_o;
db_class tc_Animal_o;
db_method tc_Animal_getKind_o;
db_member tc_Animal_kind_o;
db_method tc_Animal_matesWith_o;
db_enum tc_AnimalKind_o;
db_constant (*tc_AnimalKind_FISH_o);
db_constant (*tc_AnimalKind_INSECT_o);
db_constant (*tc_AnimalKind_MAMMAL_o);
db_constant (*tc_AnimalKind_REPTILE_o);
db_enum tc_HabitatKind_o;
db_constant (*tc_HabitatKind_AIR_o);
db_constant (*tc_HabitatKind_LAND_o);
db_constant (*tc_HabitatKind_WATER_o);
db_class tc_Mammal_o;
db_method tc_Mammal_getKind_o;
db_method tc_Mammal_getProps_o;
db_method tc_Mammal_getSpeed_o;
db_callback tc_Mammal_init_o;
db_member tc_Mammal_kind_o;
db_method tc_Mammal_matesWith_o;
db_member tc_Mammal_props_o;
db_method tc_Mammal_setProps_o;
db_method tc_Mammal_setSpeed_o;
db_enum tc_MammalKind_o;
db_constant (*tc_MammalKind_CARNIVORA_o);
db_constant (*tc_MammalKind_CHIROPTERA_o);
db_constant (*tc_MammalKind_PRIMATE_o);
db_constant (*tc_MammalKind_RODENTIA_o);
db_struct tc_MammalProps_o;
db_member tc_MammalProps_habitat_o;
db_member tc_MammalProps_legs_o;
db_member tc_MammalProps_speed_o;

/* Load objects in database */
int tc_call_load(void) {
    db_object _a_; /* Used for resolving anonymous objects */
    _a_ = NULL;

    /* Declare ::tc_call */
    tc_o = db_declare(root_o, "tc_call", db_typedef(db_object_o));
    if (!tc_o) {
        db_error("tc_call_load: failed to declare object '::tc_call'.");
        goto error;
    }

    /* Define ::tc_call */
    if (!db_checkState(tc_o, DB_DEFINED)) {
        if (db_define(tc_o)) {
            db_error("tc_call_load: failed to define object '::tc_call'.");
            goto error;
        }
    }
    /* Declare ::tc_call::Animal */
    tc_Animal_o = db_declare(tc_o, "Animal", db_typedef(db_class_o));
    if (!tc_Animal_o) {
        db_error("tc_call_load: failed to declare object '::tc_call::Animal'.");
        goto error;
    }

    /* Declare ::tc_call::Animal::getKind() */
    tc_Animal_getKind_o = db_declare(tc_Animal_o, "getKind()", db_typedef(db_method_o));
    if (!tc_Animal_getKind_o) {
        db_error("tc_call_load: failed to declare object '::tc_call::Animal::getKind()'.");
        goto error;
    }

    /* Declare ::tc_call::Animal::kind */
    tc_Animal_kind_o = db_declare(tc_Animal_o, "kind", db_typedef(db_member_o));
    if (!tc_Animal_kind_o) {
        db_error("tc_call_load: failed to declare object '::tc_call::Animal::kind'.");
        goto error;
    }

    /* Declare ::tc_call::AnimalKind */
    tc_AnimalKind_o = db_declare(tc_o, "AnimalKind", db_typedef(db_enum_o));
    if (!tc_AnimalKind_o) {
        db_error("tc_call_load: failed to declare object '::tc_call::AnimalKind'.");
        goto error;
    }

    /* Declare ::tc_call::AnimalKind::FISH */
    tc_AnimalKind_FISH_o = db_declare(tc_AnimalKind_o, "FISH", db_typedef(db_constant_o));
    if (!tc_AnimalKind_FISH_o) {
        db_error("tc_call_load: failed to declare object '::tc_call::AnimalKind::FISH'.");
        goto error;
    }

    /* Define ::tc_call::AnimalKind::FISH */
    if (!db_checkState(tc_AnimalKind_FISH_o, DB_DEFINED)) {
        (*tc_AnimalKind_FISH_o) = 3;
        if (db_define(tc_AnimalKind_FISH_o)) {
            db_error("tc_call_load: failed to define object '::tc_call::AnimalKind::FISH'.");
            goto error;
        }
    }
    /* Declare ::tc_call::AnimalKind::INSECT */
    tc_AnimalKind_INSECT_o = db_declare(tc_AnimalKind_o, "INSECT", db_typedef(db_constant_o));
    if (!tc_AnimalKind_INSECT_o) {
        db_error("tc_call_load: failed to declare object '::tc_call::AnimalKind::INSECT'.");
        goto error;
    }

    /* Define ::tc_call::AnimalKind::INSECT */
    if (!db_checkState(tc_AnimalKind_INSECT_o, DB_DEFINED)) {
        (*tc_AnimalKind_INSECT_o) = 2;
        if (db_define(tc_AnimalKind_INSECT_o)) {
            db_error("tc_call_load: failed to define object '::tc_call::AnimalKind::INSECT'.");
            goto error;
        }
    }
    /* Declare ::tc_call::AnimalKind::MAMMAL */
    tc_AnimalKind_MAMMAL_o = db_declare(tc_AnimalKind_o, "MAMMAL", db_typedef(db_constant_o));
    if (!tc_AnimalKind_MAMMAL_o) {
        db_error("tc_call_load: failed to declare object '::tc_call::AnimalKind::MAMMAL'.");
        goto error;
    }

    /* Define ::tc_call::AnimalKind::MAMMAL */
    if (!db_checkState(tc_AnimalKind_MAMMAL_o, DB_DEFINED)) {
        (*tc_AnimalKind_MAMMAL_o) = 0;
        if (db_define(tc_AnimalKind_MAMMAL_o)) {
            db_error("tc_call_load: failed to define object '::tc_call::AnimalKind::MAMMAL'.");
            goto error;
        }
    }
    /* Declare ::tc_call::AnimalKind::REPTILE */
    tc_AnimalKind_REPTILE_o = db_declare(tc_AnimalKind_o, "REPTILE", db_typedef(db_constant_o));
    if (!tc_AnimalKind_REPTILE_o) {
        db_error("tc_call_load: failed to declare object '::tc_call::AnimalKind::REPTILE'.");
        goto error;
    }

    /* Define ::tc_call::AnimalKind::REPTILE */
    if (!db_checkState(tc_AnimalKind_REPTILE_o, DB_DEFINED)) {
        (*tc_AnimalKind_REPTILE_o) = 1;
        if (db_define(tc_AnimalKind_REPTILE_o)) {
            db_error("tc_call_load: failed to define object '::tc_call::AnimalKind::REPTILE'.");
            goto error;
        }
    }
    /* Define ::tc_call::AnimalKind */
    if (!db_checkState(tc_AnimalKind_o, DB_DEFINED)) {
        if (db_define(tc_AnimalKind_o)) {
            db_error("tc_call_load: failed to define object '::tc_call::AnimalKind'.");
            goto error;
        }
    }
    /* Define ::tc_call::Animal::getKind() */
    if (!db_checkState(tc_Animal_getKind_o, DB_DEFINED)) {
        db_function(tc_Animal_getKind_o)->returnType = db_resolve_ext(tc_Animal_getKind_o, NULL, "::tc_call::AnimalKind", FALSE, "element ::tc_call::Animal::getKind().returnType");
        tc_Animal_getKind_o->virtual = FALSE;
        
        /* Bind tc_Animal_getKind_o with C-function */
        db_function(tc_Animal_getKind_o)->kind = DB_PROCEDURE_CDECL;
        tc_AnimalKind tc_Animal_getKind(tc_Animal _this);
        db_function(tc_Animal_getKind_o)->impl = (db_word)tc_Animal_getKind;
        if (db_define(tc_Animal_getKind_o)) {
            db_error("tc_call_load: failed to define object '::tc_call::Animal::getKind()'.");
            goto error;
        }
    }
    /* Define ::tc_call::Animal::kind */
    if (!db_checkState(tc_Animal_kind_o, DB_DEFINED)) {
        tc_Animal_kind_o->type = db_resolve_ext(tc_Animal_kind_o, NULL, "::tc_call::AnimalKind", FALSE, "element ::tc_call::Animal::kind.type");
        tc_Animal_kind_o->modifiers = 0x0;
        tc_Animal_kind_o->state = 0x6;
        tc_Animal_kind_o->weak = FALSE;
        tc_Animal_kind_o->id = 0;
        if (db_define(tc_Animal_kind_o)) {
            db_error("tc_call_load: failed to define object '::tc_call::Animal::kind'.");
            goto error;
        }
    }
    /* Declare ::tc_call::HabitatKind */
    tc_HabitatKind_o = db_declare(tc_o, "HabitatKind", db_typedef(db_enum_o));
    if (!tc_HabitatKind_o) {
        db_error("tc_call_load: failed to declare object '::tc_call::HabitatKind'.");
        goto error;
    }

    /* Declare ::tc_call::HabitatKind::AIR */
    tc_HabitatKind_AIR_o = db_declare(tc_HabitatKind_o, "AIR", db_typedef(db_constant_o));
    if (!tc_HabitatKind_AIR_o) {
        db_error("tc_call_load: failed to declare object '::tc_call::HabitatKind::AIR'.");
        goto error;
    }

    /* Define ::tc_call::HabitatKind::AIR */
    if (!db_checkState(tc_HabitatKind_AIR_o, DB_DEFINED)) {
        (*tc_HabitatKind_AIR_o) = 2;
        if (db_define(tc_HabitatKind_AIR_o)) {
            db_error("tc_call_load: failed to define object '::tc_call::HabitatKind::AIR'.");
            goto error;
        }
    }
    /* Declare ::tc_call::HabitatKind::LAND */
    tc_HabitatKind_LAND_o = db_declare(tc_HabitatKind_o, "LAND", db_typedef(db_constant_o));
    if (!tc_HabitatKind_LAND_o) {
        db_error("tc_call_load: failed to declare object '::tc_call::HabitatKind::LAND'.");
        goto error;
    }

    /* Define ::tc_call::HabitatKind::LAND */
    if (!db_checkState(tc_HabitatKind_LAND_o, DB_DEFINED)) {
        (*tc_HabitatKind_LAND_o) = 0;
        if (db_define(tc_HabitatKind_LAND_o)) {
            db_error("tc_call_load: failed to define object '::tc_call::HabitatKind::LAND'.");
            goto error;
        }
    }
    /* Declare ::tc_call::HabitatKind::WATER */
    tc_HabitatKind_WATER_o = db_declare(tc_HabitatKind_o, "WATER", db_typedef(db_constant_o));
    if (!tc_HabitatKind_WATER_o) {
        db_error("tc_call_load: failed to declare object '::tc_call::HabitatKind::WATER'.");
        goto error;
    }

    /* Define ::tc_call::HabitatKind::WATER */
    if (!db_checkState(tc_HabitatKind_WATER_o, DB_DEFINED)) {
        (*tc_HabitatKind_WATER_o) = 1;
        if (db_define(tc_HabitatKind_WATER_o)) {
            db_error("tc_call_load: failed to define object '::tc_call::HabitatKind::WATER'.");
            goto error;
        }
    }
    /* Define ::tc_call::HabitatKind */
    if (!db_checkState(tc_HabitatKind_o, DB_DEFINED)) {
        if (db_define(tc_HabitatKind_o)) {
            db_error("tc_call_load: failed to define object '::tc_call::HabitatKind'.");
            goto error;
        }
    }
    /* Declare ::tc_call::Mammal */
    tc_Mammal_o = db_declare(tc_o, "Mammal", db_typedef(db_class_o));
    if (!tc_Mammal_o) {
        db_error("tc_call_load: failed to declare object '::tc_call::Mammal'.");
        goto error;
    }

    /* Declare ::tc_call::Mammal::kind */
    tc_Mammal_kind_o = db_declare(tc_Mammal_o, "kind", db_typedef(db_member_o));
    if (!tc_Mammal_kind_o) {
        db_error("tc_call_load: failed to declare object '::tc_call::Mammal::kind'.");
        goto error;
    }

    /* Declare ::tc_call::Mammal::props */
    tc_Mammal_props_o = db_declare(tc_Mammal_o, "props", db_typedef(db_member_o));
    if (!tc_Mammal_props_o) {
        db_error("tc_call_load: failed to declare object '::tc_call::Mammal::props'.");
        goto error;
    }

    /* Declare ::tc_call::MammalKind */
    tc_MammalKind_o = db_declare(tc_o, "MammalKind", db_typedef(db_enum_o));
    if (!tc_MammalKind_o) {
        db_error("tc_call_load: failed to declare object '::tc_call::MammalKind'.");
        goto error;
    }

    /* Declare ::tc_call::MammalKind::CARNIVORA */
    tc_MammalKind_CARNIVORA_o = db_declare(tc_MammalKind_o, "CARNIVORA", db_typedef(db_constant_o));
    if (!tc_MammalKind_CARNIVORA_o) {
        db_error("tc_call_load: failed to declare object '::tc_call::MammalKind::CARNIVORA'.");
        goto error;
    }

    /* Define ::tc_call::MammalKind::CARNIVORA */
    if (!db_checkState(tc_MammalKind_CARNIVORA_o, DB_DEFINED)) {
        (*tc_MammalKind_CARNIVORA_o) = 3;
        if (db_define(tc_MammalKind_CARNIVORA_o)) {
            db_error("tc_call_load: failed to define object '::tc_call::MammalKind::CARNIVORA'.");
            goto error;
        }
    }
    /* Declare ::tc_call::MammalKind::CHIROPTERA */
    tc_MammalKind_CHIROPTERA_o = db_declare(tc_MammalKind_o, "CHIROPTERA", db_typedef(db_constant_o));
    if (!tc_MammalKind_CHIROPTERA_o) {
        db_error("tc_call_load: failed to declare object '::tc_call::MammalKind::CHIROPTERA'.");
        goto error;
    }

    /* Define ::tc_call::MammalKind::CHIROPTERA */
    if (!db_checkState(tc_MammalKind_CHIROPTERA_o, DB_DEFINED)) {
        (*tc_MammalKind_CHIROPTERA_o) = 2;
        if (db_define(tc_MammalKind_CHIROPTERA_o)) {
            db_error("tc_call_load: failed to define object '::tc_call::MammalKind::CHIROPTERA'.");
            goto error;
        }
    }
    /* Declare ::tc_call::MammalKind::PRIMATE */
    tc_MammalKind_PRIMATE_o = db_declare(tc_MammalKind_o, "PRIMATE", db_typedef(db_constant_o));
    if (!tc_MammalKind_PRIMATE_o) {
        db_error("tc_call_load: failed to declare object '::tc_call::MammalKind::PRIMATE'.");
        goto error;
    }

    /* Define ::tc_call::MammalKind::PRIMATE */
    if (!db_checkState(tc_MammalKind_PRIMATE_o, DB_DEFINED)) {
        (*tc_MammalKind_PRIMATE_o) = 0;
        if (db_define(tc_MammalKind_PRIMATE_o)) {
            db_error("tc_call_load: failed to define object '::tc_call::MammalKind::PRIMATE'.");
            goto error;
        }
    }
    /* Declare ::tc_call::MammalKind::RODENTIA */
    tc_MammalKind_RODENTIA_o = db_declare(tc_MammalKind_o, "RODENTIA", db_typedef(db_constant_o));
    if (!tc_MammalKind_RODENTIA_o) {
        db_error("tc_call_load: failed to declare object '::tc_call::MammalKind::RODENTIA'.");
        goto error;
    }

    /* Define ::tc_call::MammalKind::RODENTIA */
    if (!db_checkState(tc_MammalKind_RODENTIA_o, DB_DEFINED)) {
        (*tc_MammalKind_RODENTIA_o) = 1;
        if (db_define(tc_MammalKind_RODENTIA_o)) {
            db_error("tc_call_load: failed to define object '::tc_call::MammalKind::RODENTIA'.");
            goto error;
        }
    }
    /* Define ::tc_call::MammalKind */
    if (!db_checkState(tc_MammalKind_o, DB_DEFINED)) {
        if (db_define(tc_MammalKind_o)) {
            db_error("tc_call_load: failed to define object '::tc_call::MammalKind'.");
            goto error;
        }
    }
    /* Define ::tc_call::Mammal::kind */
    if (!db_checkState(tc_Mammal_kind_o, DB_DEFINED)) {
        tc_Mammal_kind_o->type = db_resolve_ext(tc_Mammal_kind_o, NULL, "::tc_call::MammalKind", FALSE, "element ::tc_call::Mammal::kind.type");
        tc_Mammal_kind_o->modifiers = 0x0;
        tc_Mammal_kind_o->state = 0x6;
        tc_Mammal_kind_o->weak = FALSE;
        tc_Mammal_kind_o->id = 0;
        if (db_define(tc_Mammal_kind_o)) {
            db_error("tc_call_load: failed to define object '::tc_call::Mammal::kind'.");
            goto error;
        }
    }
    /* Declare ::tc_call::MammalProps */
    tc_MammalProps_o = db_declare(tc_o, "MammalProps", db_typedef(db_struct_o));
    if (!tc_MammalProps_o) {
        db_error("tc_call_load: failed to declare object '::tc_call::MammalProps'.");
        goto error;
    }

    /* Declare ::tc_call::MammalProps::habitat */
    tc_MammalProps_habitat_o = db_declare(tc_MammalProps_o, "habitat", db_typedef(db_member_o));
    if (!tc_MammalProps_habitat_o) {
        db_error("tc_call_load: failed to declare object '::tc_call::MammalProps::habitat'.");
        goto error;
    }

    /* Define ::tc_call::MammalProps::habitat */
    if (!db_checkState(tc_MammalProps_habitat_o, DB_DEFINED)) {
        tc_MammalProps_habitat_o->type = db_resolve_ext(tc_MammalProps_habitat_o, NULL, "::tc_call::HabitatKind", FALSE, "element ::tc_call::MammalProps::habitat.type");
        tc_MammalProps_habitat_o->modifiers = 0x0;
        tc_MammalProps_habitat_o->state = 0x6;
        tc_MammalProps_habitat_o->weak = FALSE;
        tc_MammalProps_habitat_o->id = 1;
        if (db_define(tc_MammalProps_habitat_o)) {
            db_error("tc_call_load: failed to define object '::tc_call::MammalProps::habitat'.");
            goto error;
        }
    }
    /* Declare ::tc_call::MammalProps::legs */
    tc_MammalProps_legs_o = db_declare(tc_MammalProps_o, "legs", db_typedef(db_member_o));
    if (!tc_MammalProps_legs_o) {
        db_error("tc_call_load: failed to declare object '::tc_call::MammalProps::legs'.");
        goto error;
    }

    /* Define ::tc_call::MammalProps::legs */
    if (!db_checkState(tc_MammalProps_legs_o, DB_DEFINED)) {
        tc_MammalProps_legs_o->type = db_resolve_ext(tc_MammalProps_legs_o, NULL, "::hyve::lang::uint32", FALSE, "element ::tc_call::MammalProps::legs.type");
        tc_MammalProps_legs_o->modifiers = 0x0;
        tc_MammalProps_legs_o->state = 0x6;
        tc_MammalProps_legs_o->weak = FALSE;
        tc_MammalProps_legs_o->id = 0;
        if (db_define(tc_MammalProps_legs_o)) {
            db_error("tc_call_load: failed to define object '::tc_call::MammalProps::legs'.");
            goto error;
        }
    }
    /* Declare ::tc_call::MammalProps::speed */
    tc_MammalProps_speed_o = db_declare(tc_MammalProps_o, "speed", db_typedef(db_member_o));
    if (!tc_MammalProps_speed_o) {
        db_error("tc_call_load: failed to declare object '::tc_call::MammalProps::speed'.");
        goto error;
    }

    /* Define ::tc_call::MammalProps::speed */
    if (!db_checkState(tc_MammalProps_speed_o, DB_DEFINED)) {
        tc_MammalProps_speed_o->type = db_resolve_ext(tc_MammalProps_speed_o, NULL, "::hyve::lang::float64", FALSE, "element ::tc_call::MammalProps::speed.type");
        tc_MammalProps_speed_o->modifiers = 0x0;
        tc_MammalProps_speed_o->state = 0x6;
        tc_MammalProps_speed_o->weak = FALSE;
        tc_MammalProps_speed_o->id = 2;
        if (db_define(tc_MammalProps_speed_o)) {
            db_error("tc_call_load: failed to define object '::tc_call::MammalProps::speed'.");
            goto error;
        }
    }
    /* Define ::tc_call::MammalProps */
    if (!db_checkState(tc_MammalProps_o, DB_DEFINED)) {
        db_type(tc_MammalProps_o)->parentType = NULL;
        db_type(tc_MammalProps_o)->parentState = 0x0;
        db_interface(tc_MammalProps_o)->base = NULL;
        tc_MammalProps_o->baseAccess = 0x0;
        if (db_define(tc_MammalProps_o)) {
            db_error("tc_call_load: failed to define object '::tc_call::MammalProps'.");
            goto error;
        }
    }
    /* Define ::tc_call::Mammal::props */
    if (!db_checkState(tc_Mammal_props_o, DB_DEFINED)) {
        tc_Mammal_props_o->type = db_resolve_ext(tc_Mammal_props_o, NULL, "::tc_call::MammalProps", FALSE, "element ::tc_call::Mammal::props.type");
        tc_Mammal_props_o->modifiers = 0x1;
        tc_Mammal_props_o->state = 0x6;
        tc_Mammal_props_o->weak = FALSE;
        tc_Mammal_props_o->id = 1;
        if (db_define(tc_Mammal_props_o)) {
            db_error("tc_call_load: failed to define object '::tc_call::Mammal::props'.");
            goto error;
        }
    }
    /* Declare ::tc_call::Animal::matesWith(::tc_call::Animal m) */
    tc_Animal_matesWith_o = db_declare(tc_Animal_o, "matesWith(::tc_call::Animal m)", db_typedef(db_method_o));
    if (!tc_Animal_matesWith_o) {
        db_error("tc_call_load: failed to declare object '::tc_call::Animal::matesWith(::tc_call::Animal m)'.");
        goto error;
    }

    /* Define ::tc_call::Animal::matesWith(::tc_call::Animal m) */
    if (!db_checkState(tc_Animal_matesWith_o, DB_DEFINED)) {
        db_function(tc_Animal_matesWith_o)->returnType = db_resolve_ext(tc_Animal_matesWith_o, NULL, "::hyve::lang::bool", FALSE, "element ::tc_call::Animal::matesWith(::tc_call::Animal m).returnType");
        tc_Animal_matesWith_o->virtual = TRUE;
        
        /* Bind tc_Animal_matesWith_o with C-function */
        db_function(tc_Animal_matesWith_o)->kind = DB_PROCEDURE_CDECL;
        db_bool tc_Animal_matesWith_v(tc_Animal _this, tc_Animal m);
        db_function(tc_Animal_matesWith_o)->impl = (db_word)tc_Animal_matesWith_v;
        if (db_define(tc_Animal_matesWith_o)) {
            db_error("tc_call_load: failed to define object '::tc_call::Animal::matesWith(::tc_call::Animal m)'.");
            goto error;
        }
    }
    /* Define ::tc_call::Animal */
    if (!db_checkState(tc_Animal_o, DB_DEFINED)) {
        db_type(tc_Animal_o)->parentType = NULL;
        db_type(tc_Animal_o)->parentState = 0x0;
        db_interface(tc_Animal_o)->base = NULL;
        db_struct(tc_Animal_o)->baseAccess = 0x0;
        tc_Animal_o->implements.length = 0;
        tc_Animal_o->implements.buffer = NULL;
        if (db_define(tc_Animal_o)) {
            db_error("tc_call_load: failed to define object '::tc_call::Animal'.");
            goto error;
        }
    }
    /* Declare ::tc_call::Mammal::getKind() */
    tc_Mammal_getKind_o = db_declare(tc_Mammal_o, "getKind()", db_typedef(db_method_o));
    if (!tc_Mammal_getKind_o) {
        db_error("tc_call_load: failed to declare object '::tc_call::Mammal::getKind()'.");
        goto error;
    }

    /* Define ::tc_call::Mammal::getKind() */
    if (!db_checkState(tc_Mammal_getKind_o, DB_DEFINED)) {
        db_function(tc_Mammal_getKind_o)->returnType = db_resolve_ext(tc_Mammal_getKind_o, NULL, "::tc_call::MammalKind", FALSE, "element ::tc_call::Mammal::getKind().returnType");
        tc_Mammal_getKind_o->virtual = FALSE;
        
        /* Bind tc_Mammal_getKind_o with C-function */
        db_function(tc_Mammal_getKind_o)->kind = DB_PROCEDURE_CDECL;
        tc_MammalKind tc_Mammal_getKind(tc_Mammal _this);
        db_function(tc_Mammal_getKind_o)->impl = (db_word)tc_Mammal_getKind;
        if (db_define(tc_Mammal_getKind_o)) {
            db_error("tc_call_load: failed to define object '::tc_call::Mammal::getKind()'.");
            goto error;
        }
    }
    /* Declare ::tc_call::Mammal::getProps(::hyve::lang::uint32 someValue) */
    tc_Mammal_getProps_o = db_declare(tc_Mammal_o, "getProps(::hyve::lang::uint32 someValue)", db_typedef(db_method_o));
    if (!tc_Mammal_getProps_o) {
        db_error("tc_call_load: failed to declare object '::tc_call::Mammal::getProps(::hyve::lang::uint32 someValue)'.");
        goto error;
    }

    /* Define ::tc_call::Mammal::getProps(::hyve::lang::uint32 someValue) */
    if (!db_checkState(tc_Mammal_getProps_o, DB_DEFINED)) {
        db_function(tc_Mammal_getProps_o)->returnType = db_resolve_ext(tc_Mammal_getProps_o, NULL, "::tc_call::MammalProps", FALSE, "element ::tc_call::Mammal::getProps(::hyve::lang::uint32 someValue).returnType");
        tc_Mammal_getProps_o->virtual = FALSE;
        
        /* Bind tc_Mammal_getProps_o with C-function */
        db_function(tc_Mammal_getProps_o)->kind = DB_PROCEDURE_CDECL;
        tc_MammalProps tc_Mammal_getProps(tc_Mammal _this, db_uint32 someValue);
        db_function(tc_Mammal_getProps_o)->impl = (db_word)tc_Mammal_getProps;
        if (db_define(tc_Mammal_getProps_o)) {
            db_error("tc_call_load: failed to define object '::tc_call::Mammal::getProps(::hyve::lang::uint32 someValue)'.");
            goto error;
        }
    }
    /* Declare ::tc_call::Mammal::getSpeed() */
    tc_Mammal_getSpeed_o = db_declare(tc_Mammal_o, "getSpeed()", db_typedef(db_method_o));
    if (!tc_Mammal_getSpeed_o) {
        db_error("tc_call_load: failed to declare object '::tc_call::Mammal::getSpeed()'.");
        goto error;
    }

    /* Define ::tc_call::Mammal::getSpeed() */
    if (!db_checkState(tc_Mammal_getSpeed_o, DB_DEFINED)) {
        db_function(tc_Mammal_getSpeed_o)->returnType = db_resolve_ext(tc_Mammal_getSpeed_o, NULL, "::hyve::lang::float64", FALSE, "element ::tc_call::Mammal::getSpeed().returnType");
        tc_Mammal_getSpeed_o->virtual = FALSE;
        
        /* Bind tc_Mammal_getSpeed_o with C-function */
        db_function(tc_Mammal_getSpeed_o)->kind = DB_PROCEDURE_CDECL;
        db_float64 tc_Mammal_getSpeed(tc_Mammal _this);
        db_function(tc_Mammal_getSpeed_o)->impl = (db_word)tc_Mammal_getSpeed;
        if (db_define(tc_Mammal_getSpeed_o)) {
            db_error("tc_call_load: failed to define object '::tc_call::Mammal::getSpeed()'.");
            goto error;
        }
    }
    /* Declare ::tc_call::Mammal::init(::tc_call::Mammal object) */
    tc_Mammal_init_o = db_declare(tc_Mammal_o, "init(::tc_call::Mammal object)", db_typedef(db_callback_o));
    if (!tc_Mammal_init_o) {
        db_error("tc_call_load: failed to declare object '::tc_call::Mammal::init(::tc_call::Mammal object)'.");
        goto error;
    }

    /* Define ::tc_call::Mammal::init(::tc_call::Mammal object) */
    if (!db_checkState(tc_Mammal_init_o, DB_DEFINED)) {
        db_function(tc_Mammal_init_o)->returnType = db_resolve_ext(tc_Mammal_init_o, NULL, "::hyve::lang::int16", FALSE, "element ::tc_call::Mammal::init(::tc_call::Mammal object).returnType");
        tc_Mammal_init_o->delegate = db_resolve_ext(tc_Mammal_init_o, NULL, "::hyve::lang::type::init(lang::object object)", FALSE, "element ::tc_call::Mammal::init(::tc_call::Mammal object).delegate");
        
        /* Bind tc_Mammal_init_o with C-function */
        db_function(tc_Mammal_init_o)->kind = DB_PROCEDURE_CDECL;
        db_int16 tc_Mammal_init(tc_Mammal object);
        db_function(tc_Mammal_init_o)->impl = (db_word)tc_Mammal_init;
        if (db_define(tc_Mammal_init_o)) {
            db_error("tc_call_load: failed to define object '::tc_call::Mammal::init(::tc_call::Mammal object)'.");
            goto error;
        }
    }
    /* Declare ::tc_call::Mammal::matesWith(::tc_call::Animal m) */
    tc_Mammal_matesWith_o = db_declare(tc_Mammal_o, "matesWith(::tc_call::Animal m)", db_typedef(db_method_o));
    if (!tc_Mammal_matesWith_o) {
        db_error("tc_call_load: failed to declare object '::tc_call::Mammal::matesWith(::tc_call::Animal m)'.");
        goto error;
    }

    /* Define ::tc_call::Mammal::matesWith(::tc_call::Animal m) */
    if (!db_checkState(tc_Mammal_matesWith_o, DB_DEFINED)) {
        db_function(tc_Mammal_matesWith_o)->returnType = db_resolve_ext(tc_Mammal_matesWith_o, NULL, "::hyve::lang::bool", FALSE, "element ::tc_call::Mammal::matesWith(::tc_call::Animal m).returnType");
        tc_Mammal_matesWith_o->virtual = TRUE;
        
        /* Bind tc_Mammal_matesWith_o with C-function */
        db_function(tc_Mammal_matesWith_o)->kind = DB_PROCEDURE_CDECL;
        db_bool tc_Mammal_matesWith_v(tc_Mammal _this, tc_Animal m);
        db_function(tc_Mammal_matesWith_o)->impl = (db_word)tc_Mammal_matesWith_v;
        if (db_define(tc_Mammal_matesWith_o)) {
            db_error("tc_call_load: failed to define object '::tc_call::Mammal::matesWith(::tc_call::Animal m)'.");
            goto error;
        }
    }
    /* Declare ::tc_call::Mammal::setProps(::tc_call::MammalProps props) */
    tc_Mammal_setProps_o = db_declare(tc_Mammal_o, "setProps(::tc_call::MammalProps props)", db_typedef(db_method_o));
    if (!tc_Mammal_setProps_o) {
        db_error("tc_call_load: failed to declare object '::tc_call::Mammal::setProps(::tc_call::MammalProps props)'.");
        goto error;
    }

    /* Define ::tc_call::Mammal::setProps(::tc_call::MammalProps props) */
    if (!db_checkState(tc_Mammal_setProps_o, DB_DEFINED)) {
        db_function(tc_Mammal_setProps_o)->returnType = db_resolve_ext(tc_Mammal_setProps_o, NULL, "::hyve::lang::void", FALSE, "element ::tc_call::Mammal::setProps(::tc_call::MammalProps props).returnType");
        tc_Mammal_setProps_o->virtual = FALSE;
        
        /* Bind tc_Mammal_setProps_o with C-function */
        db_function(tc_Mammal_setProps_o)->kind = DB_PROCEDURE_CDECL;
        db_void tc_Mammal_setProps(tc_Mammal _this, tc_MammalProps props);
        db_function(tc_Mammal_setProps_o)->impl = (db_word)tc_Mammal_setProps;
        if (db_define(tc_Mammal_setProps_o)) {
            db_error("tc_call_load: failed to define object '::tc_call::Mammal::setProps(::tc_call::MammalProps props)'.");
            goto error;
        }
    }
    /* Declare ::tc_call::Mammal::setSpeed(::hyve::lang::float64 speed) */
    tc_Mammal_setSpeed_o = db_declare(tc_Mammal_o, "setSpeed(::hyve::lang::float64 speed)", db_typedef(db_method_o));
    if (!tc_Mammal_setSpeed_o) {
        db_error("tc_call_load: failed to declare object '::tc_call::Mammal::setSpeed(::hyve::lang::float64 speed)'.");
        goto error;
    }

    /* Define ::tc_call::Mammal::setSpeed(::hyve::lang::float64 speed) */
    if (!db_checkState(tc_Mammal_setSpeed_o, DB_DEFINED)) {
        db_function(tc_Mammal_setSpeed_o)->returnType = db_resolve_ext(tc_Mammal_setSpeed_o, NULL, "::hyve::lang::void", FALSE, "element ::tc_call::Mammal::setSpeed(::hyve::lang::float64 speed).returnType");
        tc_Mammal_setSpeed_o->virtual = FALSE;
        
        /* Bind tc_Mammal_setSpeed_o with C-function */
        db_function(tc_Mammal_setSpeed_o)->kind = DB_PROCEDURE_CDECL;
        db_void tc_Mammal_setSpeed(tc_Mammal _this, db_float64 speed);
        db_function(tc_Mammal_setSpeed_o)->impl = (db_word)tc_Mammal_setSpeed;
        if (db_define(tc_Mammal_setSpeed_o)) {
            db_error("tc_call_load: failed to define object '::tc_call::Mammal::setSpeed(::hyve::lang::float64 speed)'.");
            goto error;
        }
    }
    /* Define ::tc_call::Mammal */
    if (!db_checkState(tc_Mammal_o, DB_DEFINED)) {
        db_type(tc_Mammal_o)->parentType = NULL;
        db_type(tc_Mammal_o)->parentState = 0x0;
        db_interface(tc_Mammal_o)->base = db_resolve_ext(tc_Mammal_o, NULL, "::tc_call::Animal", FALSE, "element ::tc_call::Mammal.base");
        db_struct(tc_Mammal_o)->baseAccess = 0x1;
        tc_Mammal_o->implements.length = 0;
        tc_Mammal_o->implements.buffer = NULL;
        if (db_define(tc_Mammal_o)) {
            db_error("tc_call_load: failed to define object '::tc_call::Mammal'.");
            goto error;
        }
    }
    if (_a_) {
        db_free(_a_);
    }

    return 0;
error:
    return -1;
}
