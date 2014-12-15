/* tc_jsonser__meta.c
 *
 * Loads objects in database.
 * This file contains generated code. Do not modify!
 */

#include "tc_jsonser__type.h"

/* Variable definitions */
db_object tc_jsonser_o;
db_bool (*tc_jsonser_bf_o);
db_bool (*tc_jsonser_bt_o);
db_enum tc_jsonser_Djinn_o;
db_constant (*tc_jsonser_Djinn_Jupiter_o);
db_constant (*tc_jsonser_Djinn_Mars_o);
db_constant (*tc_jsonser_Djinn_Mercury_o);
db_constant (*tc_jsonser_Djinn_Venus_o);
db_class tc_jsonser_Dog_o;
db_member tc_jsonser_Dog_age_o;
db_member tc_jsonser_Dog_breed_o;
db_member tc_jsonser_Dog_lover_o;
db_member tc_jsonser_Dog_name_o;
tc_jsonser_Dog tc_jsonser_dog1_o;
tc_jsonser_Dog tc_jsonser_dog2_o;
tc_jsonser_Dog tc_jsonser_dog3_o;
db_enum tc_jsonser_DogBreed_o;
db_constant (*tc_jsonser_DogBreed_Chihuahua_o);
db_constant (*tc_jsonser_DogBreed_GoldenRetriever_o);
db_constant (*tc_jsonser_DogBreed_Pug_o);
db_float32 (*tc_jsonser_f32n_o);
db_float32 (*tc_jsonser_f32p_o);
db_float32 (*tc_jsonser_f32z_o);
db_float32 (*tc_jsonser_f64n_o);
db_float32 (*tc_jsonser_f64p_o);
db_float32 (*tc_jsonser_f64z_o);
tc_jsonser_Djinn (*tc_jsonser_Flint_o);
tc_jsonser_Djinn (*tc_jsonser_Forge_o);
tc_jsonser_Djinn (*tc_jsonser_Gust_o);
db_int16 (*tc_jsonser_i16n_o);
db_int16 (*tc_jsonser_i16p_o);
db_int16 (*tc_jsonser_i16z_o);
db_int32 (*tc_jsonser_i32n_o);
db_int32 (*tc_jsonser_i32p_o);
db_int32 (*tc_jsonser_i32z_o);
db_int64 (*tc_jsonser_i64n_o);
db_int64 (*tc_jsonser_i64p_o);
db_int64 (*tc_jsonser_i64z_o);
db_int8 (*tc_jsonser_i8n_o);
db_int8 (*tc_jsonser_i8p_o);
db_int8 (*tc_jsonser_i8z_o);
db_void (*tc_jsonser_namesp_o);
db_int16 (*tc_jsonser_namesp_a_o);
db_string (*tc_jsonser_namesp_b_o);
tc_jsonser_point2D (*tc_jsonser_p_o);
db_struct tc_jsonser_point2D_o;
db_member tc_jsonser_point2D_x_o;
db_member tc_jsonser_point2D_y_o;
db_string (*tc_jsonser_s1_o);
db_string (*tc_jsonser_s10_o);
db_string (*tc_jsonser_s11_o);
db_string (*tc_jsonser_s12_o);
db_string (*tc_jsonser_s13_o);
db_string (*tc_jsonser_s14_o);
db_string (*tc_jsonser_s2_o);
db_string (*tc_jsonser_s3_o);
db_string (*tc_jsonser_s4_o);
db_string (*tc_jsonser_s5_o);
db_string (*tc_jsonser_s6_o);
db_string (*tc_jsonser_s7_o);
db_string (*tc_jsonser_s8_o);
db_string (*tc_jsonser_s9_o);
tc_jsonser_Djinn (*tc_jsonser_Sleet_o);
db_string (*tc_jsonser_sn_o);
db_uint16 (*tc_jsonser_u16p_o);
db_uint16 (*tc_jsonser_u16z_o);
db_uint32 (*tc_jsonser_u32p_o);
db_uint32 (*tc_jsonser_u32z_o);
db_uint64 (*tc_jsonser_u64p_o);
db_uint64 (*tc_jsonser_u64z_o);
db_uint8 (*tc_jsonser_u8p_o);
db_uint8 (*tc_jsonser_u8z_o);

/* Load objects in database */
int tc_jsonser_load(void) {
    db_object _a_; /* Used for resolving anonymous objects */
    _a_ = NULL;

    /* Declare ::tc_jsonser */
    tc_jsonser_o = db_declare(root_o, "tc_jsonser", db_typedef(db_object_o));
    if (!tc_jsonser_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser'.");
        goto error;
    }

    /* Define ::tc_jsonser */
    if (!db_checkState(tc_jsonser_o, DB_DEFINED)) {
        if (db_define(tc_jsonser_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::bf */
    tc_jsonser_bf_o = db_declare(tc_jsonser_o, "bf", db_typedef(db_bool_o));
    if (!tc_jsonser_bf_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::bf'.");
        goto error;
    } else {
        (*tc_jsonser_bf_o) = FALSE;
    }

    /* Define ::tc_jsonser::bf */
    if (!db_checkState(tc_jsonser_bf_o, DB_DEFINED)) {
        if (db_define(tc_jsonser_bf_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::bf'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::bt */
    tc_jsonser_bt_o = db_declare(tc_jsonser_o, "bt", db_typedef(db_bool_o));
    if (!tc_jsonser_bt_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::bt'.");
        goto error;
    } else {
        (*tc_jsonser_bt_o) = TRUE;
    }

    /* Define ::tc_jsonser::bt */
    if (!db_checkState(tc_jsonser_bt_o, DB_DEFINED)) {
        if (db_define(tc_jsonser_bt_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::bt'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::Djinn */
    tc_jsonser_Djinn_o = db_declare(tc_jsonser_o, "Djinn", db_typedef(db_enum_o));
    if (!tc_jsonser_Djinn_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::Djinn'.");
        goto error;
    }

    /* Declare ::tc_jsonser::Djinn::Jupiter */
    tc_jsonser_Djinn_Jupiter_o = db_declare(tc_jsonser_Djinn_o, "Jupiter", db_typedef(db_constant_o));
    if (!tc_jsonser_Djinn_Jupiter_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::Djinn::Jupiter'.");
        goto error;
    } else {
        (*tc_jsonser_Djinn_Jupiter_o) = 3;
    }

    /* Define ::tc_jsonser::Djinn::Jupiter */
    if (!db_checkState(tc_jsonser_Djinn_Jupiter_o, DB_DEFINED)) {
        if (db_define(tc_jsonser_Djinn_Jupiter_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::Djinn::Jupiter'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::Djinn::Mars */
    tc_jsonser_Djinn_Mars_o = db_declare(tc_jsonser_Djinn_o, "Mars", db_typedef(db_constant_o));
    if (!tc_jsonser_Djinn_Mars_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::Djinn::Mars'.");
        goto error;
    } else {
        (*tc_jsonser_Djinn_Mars_o) = 2;
    }

    /* Define ::tc_jsonser::Djinn::Mars */
    if (!db_checkState(tc_jsonser_Djinn_Mars_o, DB_DEFINED)) {
        if (db_define(tc_jsonser_Djinn_Mars_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::Djinn::Mars'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::Djinn::Mercury */
    tc_jsonser_Djinn_Mercury_o = db_declare(tc_jsonser_Djinn_o, "Mercury", db_typedef(db_constant_o));
    if (!tc_jsonser_Djinn_Mercury_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::Djinn::Mercury'.");
        goto error;
    } else {
        (*tc_jsonser_Djinn_Mercury_o) = 0;
    }

    /* Define ::tc_jsonser::Djinn::Mercury */
    if (!db_checkState(tc_jsonser_Djinn_Mercury_o, DB_DEFINED)) {
        if (db_define(tc_jsonser_Djinn_Mercury_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::Djinn::Mercury'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::Djinn::Venus */
    tc_jsonser_Djinn_Venus_o = db_declare(tc_jsonser_Djinn_o, "Venus", db_typedef(db_constant_o));
    if (!tc_jsonser_Djinn_Venus_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::Djinn::Venus'.");
        goto error;
    } else {
        (*tc_jsonser_Djinn_Venus_o) = 1;
    }

    /* Define ::tc_jsonser::Djinn::Venus */
    if (!db_checkState(tc_jsonser_Djinn_Venus_o, DB_DEFINED)) {
        if (db_define(tc_jsonser_Djinn_Venus_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::Djinn::Venus'.");
            goto error;
        }
    }
    /* Define ::tc_jsonser::Djinn */
    if (!db_checkState(tc_jsonser_Djinn_o, DB_DEFINED)) {
        if (db_define(tc_jsonser_Djinn_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::Djinn'.");
            goto error;
        }
    }
    if (db_type(tc_jsonser_Djinn_o)->size != sizeof(tc_jsonser_Djinn)) {
        db_error("tc_jsonser_load: calculated size '%d' of type '::tc_jsonser::Djinn' doesn't match C-type size '%d'", db_type(tc_jsonser_Djinn_o)->size, sizeof(tc_jsonser_Djinn));
    }
    /* Declare ::tc_jsonser::Flint */
    tc_jsonser_Flint_o = db_declare(tc_jsonser_o, "Flint", db_typedef(tc_jsonser_Djinn_o));
    if (!tc_jsonser_Flint_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::Flint'.");
        goto error;
    } else {
        (*tc_jsonser_Flint_o) = TC_JSONSER_Venus;
    }

    /* Define ::tc_jsonser::Flint */
    if (!db_checkState(tc_jsonser_Flint_o, DB_DEFINED)) {
        if (db_define(tc_jsonser_Flint_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::Flint'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::Forge */
    tc_jsonser_Forge_o = db_declare(tc_jsonser_o, "Forge", db_typedef(tc_jsonser_Djinn_o));
    if (!tc_jsonser_Forge_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::Forge'.");
        goto error;
    } else {
        (*tc_jsonser_Forge_o) = TC_JSONSER_Mars;
    }

    /* Define ::tc_jsonser::Forge */
    if (!db_checkState(tc_jsonser_Forge_o, DB_DEFINED)) {
        if (db_define(tc_jsonser_Forge_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::Forge'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::Gust */
    tc_jsonser_Gust_o = db_declare(tc_jsonser_o, "Gust", db_typedef(tc_jsonser_Djinn_o));
    if (!tc_jsonser_Gust_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::Gust'.");
        goto error;
    } else {
        (*tc_jsonser_Gust_o) = TC_JSONSER_Jupiter;
    }

    /* Define ::tc_jsonser::Gust */
    if (!db_checkState(tc_jsonser_Gust_o, DB_DEFINED)) {
        if (db_define(tc_jsonser_Gust_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::Gust'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::Sleet */
    tc_jsonser_Sleet_o = db_declare(tc_jsonser_o, "Sleet", db_typedef(tc_jsonser_Djinn_o));
    if (!tc_jsonser_Sleet_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::Sleet'.");
        goto error;
    } else {
        (*tc_jsonser_Sleet_o) = TC_JSONSER_Mercury;
    }

    /* Define ::tc_jsonser::Sleet */
    if (!db_checkState(tc_jsonser_Sleet_o, DB_DEFINED)) {
        if (db_define(tc_jsonser_Sleet_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::Sleet'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::Dog */
    tc_jsonser_Dog_o = db_declare(tc_jsonser_o, "Dog", db_typedef(db_class_o));
    if (!tc_jsonser_Dog_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::Dog'.");
        goto error;
    }

    /* Declare ::tc_jsonser::Dog::age */
    tc_jsonser_Dog_age_o = db_declare(tc_jsonser_Dog_o, "age", db_typedef(db_member_o));
    if (!tc_jsonser_Dog_age_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::Dog::age'.");
        goto error;
    }

    /* Define ::tc_jsonser::Dog::age */
    if (!db_checkState(tc_jsonser_Dog_age_o, DB_DEFINED)) {
        tc_jsonser_Dog_age_o->type = db_resolve_ext(tc_jsonser_Dog_age_o, NULL, "::hyve::lang::uint8", FALSE, "element ::tc_jsonser::Dog::age.type");
        tc_jsonser_Dog_age_o->modifiers = 0x0;
        tc_jsonser_Dog_age_o->state = 0x6;
        tc_jsonser_Dog_age_o->weak = FALSE;
        tc_jsonser_Dog_age_o->id = 2;
        if (db_define(tc_jsonser_Dog_age_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::Dog::age'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::Dog::breed */
    tc_jsonser_Dog_breed_o = db_declare(tc_jsonser_Dog_o, "breed", db_typedef(db_member_o));
    if (!tc_jsonser_Dog_breed_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::Dog::breed'.");
        goto error;
    }

    /* Declare ::tc_jsonser::Dog::lover */
    tc_jsonser_Dog_lover_o = db_declare(tc_jsonser_Dog_o, "lover", db_typedef(db_member_o));
    if (!tc_jsonser_Dog_lover_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::Dog::lover'.");
        goto error;
    }

    /* Declare ::tc_jsonser::Dog::name */
    tc_jsonser_Dog_name_o = db_declare(tc_jsonser_Dog_o, "name", db_typedef(db_member_o));
    if (!tc_jsonser_Dog_name_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::Dog::name'.");
        goto error;
    }

    /* Define ::tc_jsonser::Dog::name */
    if (!db_checkState(tc_jsonser_Dog_name_o, DB_DEFINED)) {
        tc_jsonser_Dog_name_o->type = db_resolve_ext(tc_jsonser_Dog_name_o, NULL, "::hyve::lang::string", FALSE, "element ::tc_jsonser::Dog::name.type");
        tc_jsonser_Dog_name_o->modifiers = 0x0;
        tc_jsonser_Dog_name_o->state = 0x6;
        tc_jsonser_Dog_name_o->weak = FALSE;
        tc_jsonser_Dog_name_o->id = 1;
        if (db_define(tc_jsonser_Dog_name_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::Dog::name'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::DogBreed */
    tc_jsonser_DogBreed_o = db_declare(tc_jsonser_o, "DogBreed", db_typedef(db_enum_o));
    if (!tc_jsonser_DogBreed_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::DogBreed'.");
        goto error;
    }

    /* Declare ::tc_jsonser::DogBreed::Chihuahua */
    tc_jsonser_DogBreed_Chihuahua_o = db_declare(tc_jsonser_DogBreed_o, "Chihuahua", db_typedef(db_constant_o));
    if (!tc_jsonser_DogBreed_Chihuahua_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::DogBreed::Chihuahua'.");
        goto error;
    } else {
        (*tc_jsonser_DogBreed_Chihuahua_o) = 2;
    }

    /* Define ::tc_jsonser::DogBreed::Chihuahua */
    if (!db_checkState(tc_jsonser_DogBreed_Chihuahua_o, DB_DEFINED)) {
        if (db_define(tc_jsonser_DogBreed_Chihuahua_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::DogBreed::Chihuahua'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::DogBreed::GoldenRetriever */
    tc_jsonser_DogBreed_GoldenRetriever_o = db_declare(tc_jsonser_DogBreed_o, "GoldenRetriever", db_typedef(db_constant_o));
    if (!tc_jsonser_DogBreed_GoldenRetriever_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::DogBreed::GoldenRetriever'.");
        goto error;
    } else {
        (*tc_jsonser_DogBreed_GoldenRetriever_o) = 0;
    }

    /* Define ::tc_jsonser::DogBreed::GoldenRetriever */
    if (!db_checkState(tc_jsonser_DogBreed_GoldenRetriever_o, DB_DEFINED)) {
        if (db_define(tc_jsonser_DogBreed_GoldenRetriever_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::DogBreed::GoldenRetriever'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::DogBreed::Pug */
    tc_jsonser_DogBreed_Pug_o = db_declare(tc_jsonser_DogBreed_o, "Pug", db_typedef(db_constant_o));
    if (!tc_jsonser_DogBreed_Pug_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::DogBreed::Pug'.");
        goto error;
    } else {
        (*tc_jsonser_DogBreed_Pug_o) = 1;
    }

    /* Define ::tc_jsonser::DogBreed::Pug */
    if (!db_checkState(tc_jsonser_DogBreed_Pug_o, DB_DEFINED)) {
        if (db_define(tc_jsonser_DogBreed_Pug_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::DogBreed::Pug'.");
            goto error;
        }
    }
    /* Define ::tc_jsonser::DogBreed */
    if (!db_checkState(tc_jsonser_DogBreed_o, DB_DEFINED)) {
        if (db_define(tc_jsonser_DogBreed_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::DogBreed'.");
            goto error;
        }
    }
    if (db_type(tc_jsonser_DogBreed_o)->size != sizeof(tc_jsonser_DogBreed)) {
        db_error("tc_jsonser_load: calculated size '%d' of type '::tc_jsonser::DogBreed' doesn't match C-type size '%d'", db_type(tc_jsonser_DogBreed_o)->size, sizeof(tc_jsonser_DogBreed));
    }
    /* Define ::tc_jsonser::Dog::breed */
    if (!db_checkState(tc_jsonser_Dog_breed_o, DB_DEFINED)) {
        tc_jsonser_Dog_breed_o->type = db_resolve_ext(tc_jsonser_Dog_breed_o, NULL, "::tc_jsonser::DogBreed", FALSE, "element ::tc_jsonser::Dog::breed.type");
        tc_jsonser_Dog_breed_o->modifiers = 0x0;
        tc_jsonser_Dog_breed_o->state = 0x6;
        tc_jsonser_Dog_breed_o->weak = FALSE;
        tc_jsonser_Dog_breed_o->id = 0;
        if (db_define(tc_jsonser_Dog_breed_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::Dog::breed'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::f32n */
    tc_jsonser_f32n_o = db_declare(tc_jsonser_o, "f32n", db_typedef(db_float32_o));
    if (!tc_jsonser_f32n_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::f32n'.");
        goto error;
    } else {
        (*tc_jsonser_f32n_o) = -2.450000;
    }

    /* Define ::tc_jsonser::f32n */
    if (!db_checkState(tc_jsonser_f32n_o, DB_DEFINED)) {
        if (db_define(tc_jsonser_f32n_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::f32n'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::f32p */
    tc_jsonser_f32p_o = db_declare(tc_jsonser_o, "f32p", db_typedef(db_float32_o));
    if (!tc_jsonser_f32p_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::f32p'.");
        goto error;
    } else {
        (*tc_jsonser_f32p_o) = 45.200001;
    }

    /* Define ::tc_jsonser::f32p */
    if (!db_checkState(tc_jsonser_f32p_o, DB_DEFINED)) {
        if (db_define(tc_jsonser_f32p_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::f32p'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::f32z */
    tc_jsonser_f32z_o = db_declare(tc_jsonser_o, "f32z", db_typedef(db_float32_o));
    if (!tc_jsonser_f32z_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::f32z'.");
        goto error;
    } else {
        (*tc_jsonser_f32z_o) = 0.000000;
    }

    /* Define ::tc_jsonser::f32z */
    if (!db_checkState(tc_jsonser_f32z_o, DB_DEFINED)) {
        if (db_define(tc_jsonser_f32z_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::f32z'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::f64n */
    tc_jsonser_f64n_o = db_declare(tc_jsonser_o, "f64n", db_typedef(db_float32_o));
    if (!tc_jsonser_f64n_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::f64n'.");
        goto error;
    } else {
        (*tc_jsonser_f64n_o) = -2.450000;
    }

    /* Define ::tc_jsonser::f64n */
    if (!db_checkState(tc_jsonser_f64n_o, DB_DEFINED)) {
        if (db_define(tc_jsonser_f64n_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::f64n'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::f64p */
    tc_jsonser_f64p_o = db_declare(tc_jsonser_o, "f64p", db_typedef(db_float32_o));
    if (!tc_jsonser_f64p_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::f64p'.");
        goto error;
    } else {
        (*tc_jsonser_f64p_o) = 45.200001;
    }

    /* Define ::tc_jsonser::f64p */
    if (!db_checkState(tc_jsonser_f64p_o, DB_DEFINED)) {
        if (db_define(tc_jsonser_f64p_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::f64p'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::f64z */
    tc_jsonser_f64z_o = db_declare(tc_jsonser_o, "f64z", db_typedef(db_float32_o));
    if (!tc_jsonser_f64z_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::f64z'.");
        goto error;
    } else {
        (*tc_jsonser_f64z_o) = 0.000000;
    }

    /* Define ::tc_jsonser::f64z */
    if (!db_checkState(tc_jsonser_f64z_o, DB_DEFINED)) {
        if (db_define(tc_jsonser_f64z_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::f64z'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::i16n */
    tc_jsonser_i16n_o = db_declare(tc_jsonser_o, "i16n", db_typedef(db_int16_o));
    if (!tc_jsonser_i16n_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::i16n'.");
        goto error;
    } else {
        (*tc_jsonser_i16n_o) = -2;
    }

    /* Define ::tc_jsonser::i16n */
    if (!db_checkState(tc_jsonser_i16n_o, DB_DEFINED)) {
        if (db_define(tc_jsonser_i16n_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::i16n'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::i16p */
    tc_jsonser_i16p_o = db_declare(tc_jsonser_o, "i16p", db_typedef(db_int16_o));
    if (!tc_jsonser_i16p_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::i16p'.");
        goto error;
    } else {
        (*tc_jsonser_i16p_o) = 45;
    }

    /* Define ::tc_jsonser::i16p */
    if (!db_checkState(tc_jsonser_i16p_o, DB_DEFINED)) {
        if (db_define(tc_jsonser_i16p_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::i16p'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::i16z */
    tc_jsonser_i16z_o = db_declare(tc_jsonser_o, "i16z", db_typedef(db_int16_o));
    if (!tc_jsonser_i16z_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::i16z'.");
        goto error;
    } else {
        (*tc_jsonser_i16z_o) = 0;
    }

    /* Define ::tc_jsonser::i16z */
    if (!db_checkState(tc_jsonser_i16z_o, DB_DEFINED)) {
        if (db_define(tc_jsonser_i16z_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::i16z'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::i32n */
    tc_jsonser_i32n_o = db_declare(tc_jsonser_o, "i32n", db_typedef(db_int32_o));
    if (!tc_jsonser_i32n_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::i32n'.");
        goto error;
    } else {
        (*tc_jsonser_i32n_o) = -2;
    }

    /* Define ::tc_jsonser::i32n */
    if (!db_checkState(tc_jsonser_i32n_o, DB_DEFINED)) {
        if (db_define(tc_jsonser_i32n_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::i32n'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::i32p */
    tc_jsonser_i32p_o = db_declare(tc_jsonser_o, "i32p", db_typedef(db_int32_o));
    if (!tc_jsonser_i32p_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::i32p'.");
        goto error;
    } else {
        (*tc_jsonser_i32p_o) = 45;
    }

    /* Define ::tc_jsonser::i32p */
    if (!db_checkState(tc_jsonser_i32p_o, DB_DEFINED)) {
        if (db_define(tc_jsonser_i32p_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::i32p'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::i32z */
    tc_jsonser_i32z_o = db_declare(tc_jsonser_o, "i32z", db_typedef(db_int32_o));
    if (!tc_jsonser_i32z_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::i32z'.");
        goto error;
    } else {
        (*tc_jsonser_i32z_o) = 0;
    }

    /* Define ::tc_jsonser::i32z */
    if (!db_checkState(tc_jsonser_i32z_o, DB_DEFINED)) {
        if (db_define(tc_jsonser_i32z_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::i32z'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::i64n */
    tc_jsonser_i64n_o = db_declare(tc_jsonser_o, "i64n", db_typedef(db_int64_o));
    if (!tc_jsonser_i64n_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::i64n'.");
        goto error;
    } else {
        (*tc_jsonser_i64n_o) = -2;
    }

    /* Define ::tc_jsonser::i64n */
    if (!db_checkState(tc_jsonser_i64n_o, DB_DEFINED)) {
        if (db_define(tc_jsonser_i64n_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::i64n'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::i64p */
    tc_jsonser_i64p_o = db_declare(tc_jsonser_o, "i64p", db_typedef(db_int64_o));
    if (!tc_jsonser_i64p_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::i64p'.");
        goto error;
    } else {
        (*tc_jsonser_i64p_o) = 45;
    }

    /* Define ::tc_jsonser::i64p */
    if (!db_checkState(tc_jsonser_i64p_o, DB_DEFINED)) {
        if (db_define(tc_jsonser_i64p_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::i64p'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::i64z */
    tc_jsonser_i64z_o = db_declare(tc_jsonser_o, "i64z", db_typedef(db_int64_o));
    if (!tc_jsonser_i64z_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::i64z'.");
        goto error;
    } else {
        (*tc_jsonser_i64z_o) = 0;
    }

    /* Define ::tc_jsonser::i64z */
    if (!db_checkState(tc_jsonser_i64z_o, DB_DEFINED)) {
        if (db_define(tc_jsonser_i64z_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::i64z'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::i8n */
    tc_jsonser_i8n_o = db_declare(tc_jsonser_o, "i8n", db_typedef(db_int8_o));
    if (!tc_jsonser_i8n_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::i8n'.");
        goto error;
    } else {
        (*tc_jsonser_i8n_o) = -2;
    }

    /* Define ::tc_jsonser::i8n */
    if (!db_checkState(tc_jsonser_i8n_o, DB_DEFINED)) {
        if (db_define(tc_jsonser_i8n_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::i8n'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::i8p */
    tc_jsonser_i8p_o = db_declare(tc_jsonser_o, "i8p", db_typedef(db_int8_o));
    if (!tc_jsonser_i8p_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::i8p'.");
        goto error;
    } else {
        (*tc_jsonser_i8p_o) = 45;
    }

    /* Define ::tc_jsonser::i8p */
    if (!db_checkState(tc_jsonser_i8p_o, DB_DEFINED)) {
        if (db_define(tc_jsonser_i8p_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::i8p'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::i8z */
    tc_jsonser_i8z_o = db_declare(tc_jsonser_o, "i8z", db_typedef(db_int8_o));
    if (!tc_jsonser_i8z_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::i8z'.");
        goto error;
    } else {
        (*tc_jsonser_i8z_o) = 0;
    }

    /* Define ::tc_jsonser::i8z */
    if (!db_checkState(tc_jsonser_i8z_o, DB_DEFINED)) {
        if (db_define(tc_jsonser_i8z_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::i8z'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::namesp */
    tc_jsonser_namesp_o = db_declare(tc_jsonser_o, "namesp", db_typedef(db_void_o));
    if (!tc_jsonser_namesp_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::namesp'.");
        goto error;
    }

    /* Declare ::tc_jsonser::namesp::a */
    tc_jsonser_namesp_a_o = db_declare(tc_jsonser_namesp_o, "a", db_typedef(db_int16_o));
    if (!tc_jsonser_namesp_a_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::namesp::a'.");
        goto error;
    } else {
        (*tc_jsonser_namesp_a_o) = 9;
    }

    /* Define ::tc_jsonser::namesp::a */
    if (!db_checkState(tc_jsonser_namesp_a_o, DB_DEFINED)) {
        if (db_define(tc_jsonser_namesp_a_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::namesp::a'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::namesp::b */
    tc_jsonser_namesp_b_o = db_declare(tc_jsonser_namesp_o, "b", db_typedef(db_string_o));
    if (!tc_jsonser_namesp_b_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::namesp::b'.");
        goto error;
    } else {
        (*tc_jsonser_namesp_b_o) = db_strdup("b");
    }

    /* Define ::tc_jsonser::namesp::b */
    if (!db_checkState(tc_jsonser_namesp_b_o, DB_DEFINED)) {
        if (db_define(tc_jsonser_namesp_b_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::namesp::b'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::point2D */
    tc_jsonser_point2D_o = db_declare(tc_jsonser_o, "point2D", db_typedef(db_struct_o));
    if (!tc_jsonser_point2D_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::point2D'.");
        goto error;
    }

    /* Declare ::tc_jsonser::point2D::x */
    tc_jsonser_point2D_x_o = db_declare(tc_jsonser_point2D_o, "x", db_typedef(db_member_o));
    if (!tc_jsonser_point2D_x_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::point2D::x'.");
        goto error;
    }

    /* Define ::tc_jsonser::point2D::x */
    if (!db_checkState(tc_jsonser_point2D_x_o, DB_DEFINED)) {
        tc_jsonser_point2D_x_o->type = db_resolve_ext(tc_jsonser_point2D_x_o, NULL, "::hyve::lang::int32", FALSE, "element ::tc_jsonser::point2D::x.type");
        tc_jsonser_point2D_x_o->modifiers = 0x0;
        tc_jsonser_point2D_x_o->state = 0x6;
        tc_jsonser_point2D_x_o->weak = FALSE;
        tc_jsonser_point2D_x_o->id = 0;
        if (db_define(tc_jsonser_point2D_x_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::point2D::x'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::point2D::y */
    tc_jsonser_point2D_y_o = db_declare(tc_jsonser_point2D_o, "y", db_typedef(db_member_o));
    if (!tc_jsonser_point2D_y_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::point2D::y'.");
        goto error;
    }

    /* Define ::tc_jsonser::point2D::y */
    if (!db_checkState(tc_jsonser_point2D_y_o, DB_DEFINED)) {
        tc_jsonser_point2D_y_o->type = db_resolve_ext(tc_jsonser_point2D_y_o, NULL, "::hyve::lang::int32", FALSE, "element ::tc_jsonser::point2D::y.type");
        tc_jsonser_point2D_y_o->modifiers = 0x0;
        tc_jsonser_point2D_y_o->state = 0x6;
        tc_jsonser_point2D_y_o->weak = FALSE;
        tc_jsonser_point2D_y_o->id = 1;
        if (db_define(tc_jsonser_point2D_y_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::point2D::y'.");
            goto error;
        }
    }
    /* Define ::tc_jsonser::point2D */
    if (!db_checkState(tc_jsonser_point2D_o, DB_DEFINED)) {
        db_type(tc_jsonser_point2D_o)->defaultType = db_resolve_ext(tc_jsonser_point2D_o, NULL, "::hyve::lang::member", FALSE, "element ::tc_jsonser::point2D.defaultType");
        db_type(tc_jsonser_point2D_o)->parentType = NULL;
        db_type(tc_jsonser_point2D_o)->parentState = 0x0;
        db_interface(tc_jsonser_point2D_o)->base = NULL;
        tc_jsonser_point2D_o->baseAccess = 0x0;
        if (db_define(tc_jsonser_point2D_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::point2D'.");
            goto error;
        }
    }
    if (db_type(tc_jsonser_point2D_o)->size != sizeof(tc_jsonser_point2D)) {
        db_error("tc_jsonser_load: calculated size '%d' of type '::tc_jsonser::point2D' doesn't match C-type size '%d'", db_type(tc_jsonser_point2D_o)->size, sizeof(tc_jsonser_point2D));
    }
    /* Declare ::tc_jsonser::p */
    tc_jsonser_p_o = db_declare(tc_jsonser_o, "p", db_typedef(tc_jsonser_point2D_o));
    if (!tc_jsonser_p_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::p'.");
        goto error;
    }

    /* Define ::tc_jsonser::p */
    if (!db_checkState(tc_jsonser_p_o, DB_DEFINED)) {
        tc_jsonser_p_o->x = 3;
        tc_jsonser_p_o->y = 4;
        if (db_define(tc_jsonser_p_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::p'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::s1 */
    tc_jsonser_s1_o = db_declare(tc_jsonser_o, "s1", db_typedef(db_string_o));
    if (!tc_jsonser_s1_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::s1'.");
        goto error;
    } else {
        (*tc_jsonser_s1_o) = db_strdup("hello world");
    }

    /* Define ::tc_jsonser::s1 */
    if (!db_checkState(tc_jsonser_s1_o, DB_DEFINED)) {
        if (db_define(tc_jsonser_s1_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::s1'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::s10 */
    tc_jsonser_s10_o = db_declare(tc_jsonser_o, "s10", db_typedef(db_string_o));
    if (!tc_jsonser_s10_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::s10'.");
        goto error;
    } else {
        (*tc_jsonser_s10_o) = db_strdup("@@hey you");
    }

    /* Define ::tc_jsonser::s10 */
    if (!db_checkState(tc_jsonser_s10_o, DB_DEFINED)) {
        if (db_define(tc_jsonser_s10_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::s10'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::s11 */
    tc_jsonser_s11_o = db_declare(tc_jsonser_o, "s11", db_typedef(db_string_o));
    if (!tc_jsonser_s11_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::s11'.");
        goto error;
    } else {
        (*tc_jsonser_s11_o) = db_strdup("@@@@@");
    }

    /* Define ::tc_jsonser::s11 */
    if (!db_checkState(tc_jsonser_s11_o, DB_DEFINED)) {
        if (db_define(tc_jsonser_s11_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::s11'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::s12 */
    tc_jsonser_s12_o = db_declare(tc_jsonser_o, "s12", db_typedef(db_string_o));
    if (!tc_jsonser_s12_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::s12'.");
        goto error;
    } else {
        (*tc_jsonser_s12_o) = db_strdup("@@@@@ hey");
    }

    /* Define ::tc_jsonser::s12 */
    if (!db_checkState(tc_jsonser_s12_o, DB_DEFINED)) {
        if (db_define(tc_jsonser_s12_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::s12'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::s13 */
    tc_jsonser_s13_o = db_declare(tc_jsonser_o, "s13", db_typedef(db_string_o));
    if (!tc_jsonser_s13_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::s13'.");
        goto error;
    } else {
        (*tc_jsonser_s13_o) = db_strdup("@@@@@hey");
    }

    /* Define ::tc_jsonser::s13 */
    if (!db_checkState(tc_jsonser_s13_o, DB_DEFINED)) {
        if (db_define(tc_jsonser_s13_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::s13'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::s14 */
    tc_jsonser_s14_o = db_declare(tc_jsonser_o, "s14", db_typedef(db_string_o));
    if (!tc_jsonser_s14_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::s14'.");
        goto error;
    } else {
        (*tc_jsonser_s14_o) = db_strdup("@@@@@hey you");
    }

    /* Define ::tc_jsonser::s14 */
    if (!db_checkState(tc_jsonser_s14_o, DB_DEFINED)) {
        if (db_define(tc_jsonser_s14_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::s14'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::s2 */
    tc_jsonser_s2_o = db_declare(tc_jsonser_o, "s2", db_typedef(db_string_o));
    if (!tc_jsonser_s2_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::s2'.");
        goto error;
    } else {
        (*tc_jsonser_s2_o) = db_strdup("hello, world!");
    }

    /* Define ::tc_jsonser::s2 */
    if (!db_checkState(tc_jsonser_s2_o, DB_DEFINED)) {
        if (db_define(tc_jsonser_s2_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::s2'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::s3 */
    tc_jsonser_s3_o = db_declare(tc_jsonser_o, "s3", db_typedef(db_string_o));
    if (!tc_jsonser_s3_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::s3'.");
        goto error;
    } else {
        (*tc_jsonser_s3_o) = db_strdup("@");
    }

    /* Define ::tc_jsonser::s3 */
    if (!db_checkState(tc_jsonser_s3_o, DB_DEFINED)) {
        if (db_define(tc_jsonser_s3_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::s3'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::s4 */
    tc_jsonser_s4_o = db_declare(tc_jsonser_o, "s4", db_typedef(db_string_o));
    if (!tc_jsonser_s4_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::s4'.");
        goto error;
    } else {
        (*tc_jsonser_s4_o) = db_strdup("@ hey");
    }

    /* Define ::tc_jsonser::s4 */
    if (!db_checkState(tc_jsonser_s4_o, DB_DEFINED)) {
        if (db_define(tc_jsonser_s4_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::s4'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::s5 */
    tc_jsonser_s5_o = db_declare(tc_jsonser_o, "s5", db_typedef(db_string_o));
    if (!tc_jsonser_s5_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::s5'.");
        goto error;
    } else {
        (*tc_jsonser_s5_o) = db_strdup("@hey");
    }

    /* Define ::tc_jsonser::s5 */
    if (!db_checkState(tc_jsonser_s5_o, DB_DEFINED)) {
        if (db_define(tc_jsonser_s5_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::s5'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::s6 */
    tc_jsonser_s6_o = db_declare(tc_jsonser_o, "s6", db_typedef(db_string_o));
    if (!tc_jsonser_s6_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::s6'.");
        goto error;
    } else {
        (*tc_jsonser_s6_o) = db_strdup("@hey you");
    }

    /* Define ::tc_jsonser::s6 */
    if (!db_checkState(tc_jsonser_s6_o, DB_DEFINED)) {
        if (db_define(tc_jsonser_s6_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::s6'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::s7 */
    tc_jsonser_s7_o = db_declare(tc_jsonser_o, "s7", db_typedef(db_string_o));
    if (!tc_jsonser_s7_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::s7'.");
        goto error;
    } else {
        (*tc_jsonser_s7_o) = db_strdup("@@");
    }

    /* Define ::tc_jsonser::s7 */
    if (!db_checkState(tc_jsonser_s7_o, DB_DEFINED)) {
        if (db_define(tc_jsonser_s7_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::s7'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::s8 */
    tc_jsonser_s8_o = db_declare(tc_jsonser_o, "s8", db_typedef(db_string_o));
    if (!tc_jsonser_s8_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::s8'.");
        goto error;
    } else {
        (*tc_jsonser_s8_o) = db_strdup("@@ hey");
    }

    /* Define ::tc_jsonser::s8 */
    if (!db_checkState(tc_jsonser_s8_o, DB_DEFINED)) {
        if (db_define(tc_jsonser_s8_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::s8'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::s9 */
    tc_jsonser_s9_o = db_declare(tc_jsonser_o, "s9", db_typedef(db_string_o));
    if (!tc_jsonser_s9_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::s9'.");
        goto error;
    } else {
        (*tc_jsonser_s9_o) = db_strdup("@@hey");
    }

    /* Define ::tc_jsonser::s9 */
    if (!db_checkState(tc_jsonser_s9_o, DB_DEFINED)) {
        if (db_define(tc_jsonser_s9_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::s9'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::sn */
    tc_jsonser_sn_o = db_declare(tc_jsonser_o, "sn", db_typedef(db_string_o));
    if (!tc_jsonser_sn_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::sn'.");
        goto error;
    } else {
        (*tc_jsonser_sn_o) = NULL;
    }

    /* Define ::tc_jsonser::sn */
    if (!db_checkState(tc_jsonser_sn_o, DB_DEFINED)) {
        if (db_define(tc_jsonser_sn_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::sn'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::u16p */
    tc_jsonser_u16p_o = db_declare(tc_jsonser_o, "u16p", db_typedef(db_uint16_o));
    if (!tc_jsonser_u16p_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::u16p'.");
        goto error;
    } else {
        (*tc_jsonser_u16p_o) = 45;
    }

    /* Define ::tc_jsonser::u16p */
    if (!db_checkState(tc_jsonser_u16p_o, DB_DEFINED)) {
        if (db_define(tc_jsonser_u16p_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::u16p'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::u16z */
    tc_jsonser_u16z_o = db_declare(tc_jsonser_o, "u16z", db_typedef(db_uint16_o));
    if (!tc_jsonser_u16z_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::u16z'.");
        goto error;
    } else {
        (*tc_jsonser_u16z_o) = 0;
    }

    /* Define ::tc_jsonser::u16z */
    if (!db_checkState(tc_jsonser_u16z_o, DB_DEFINED)) {
        if (db_define(tc_jsonser_u16z_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::u16z'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::u32p */
    tc_jsonser_u32p_o = db_declare(tc_jsonser_o, "u32p", db_typedef(db_uint32_o));
    if (!tc_jsonser_u32p_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::u32p'.");
        goto error;
    } else {
        (*tc_jsonser_u32p_o) = 45;
    }

    /* Define ::tc_jsonser::u32p */
    if (!db_checkState(tc_jsonser_u32p_o, DB_DEFINED)) {
        if (db_define(tc_jsonser_u32p_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::u32p'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::u32z */
    tc_jsonser_u32z_o = db_declare(tc_jsonser_o, "u32z", db_typedef(db_uint32_o));
    if (!tc_jsonser_u32z_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::u32z'.");
        goto error;
    } else {
        (*tc_jsonser_u32z_o) = 0;
    }

    /* Define ::tc_jsonser::u32z */
    if (!db_checkState(tc_jsonser_u32z_o, DB_DEFINED)) {
        if (db_define(tc_jsonser_u32z_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::u32z'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::u64p */
    tc_jsonser_u64p_o = db_declare(tc_jsonser_o, "u64p", db_typedef(db_uint64_o));
    if (!tc_jsonser_u64p_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::u64p'.");
        goto error;
    } else {
        (*tc_jsonser_u64p_o) = 45;
    }

    /* Define ::tc_jsonser::u64p */
    if (!db_checkState(tc_jsonser_u64p_o, DB_DEFINED)) {
        if (db_define(tc_jsonser_u64p_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::u64p'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::u64z */
    tc_jsonser_u64z_o = db_declare(tc_jsonser_o, "u64z", db_typedef(db_uint64_o));
    if (!tc_jsonser_u64z_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::u64z'.");
        goto error;
    } else {
        (*tc_jsonser_u64z_o) = 0;
    }

    /* Define ::tc_jsonser::u64z */
    if (!db_checkState(tc_jsonser_u64z_o, DB_DEFINED)) {
        if (db_define(tc_jsonser_u64z_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::u64z'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::u8p */
    tc_jsonser_u8p_o = db_declare(tc_jsonser_o, "u8p", db_typedef(db_uint8_o));
    if (!tc_jsonser_u8p_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::u8p'.");
        goto error;
    } else {
        (*tc_jsonser_u8p_o) = 45;
    }

    /* Define ::tc_jsonser::u8p */
    if (!db_checkState(tc_jsonser_u8p_o, DB_DEFINED)) {
        if (db_define(tc_jsonser_u8p_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::u8p'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::u8z */
    tc_jsonser_u8z_o = db_declare(tc_jsonser_o, "u8z", db_typedef(db_uint8_o));
    if (!tc_jsonser_u8z_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::u8z'.");
        goto error;
    } else {
        (*tc_jsonser_u8z_o) = 0;
    }

    /* Define ::tc_jsonser::u8z */
    if (!db_checkState(tc_jsonser_u8z_o, DB_DEFINED)) {
        if (db_define(tc_jsonser_u8z_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::u8z'.");
            goto error;
        }
    }
    /* Define ::tc_jsonser::Dog::lover */
    if (!db_checkState(tc_jsonser_Dog_lover_o, DB_DEFINED)) {
        tc_jsonser_Dog_lover_o->type = db_resolve_ext(tc_jsonser_Dog_lover_o, NULL, "::tc_jsonser::Dog", FALSE, "element ::tc_jsonser::Dog::lover.type");
        tc_jsonser_Dog_lover_o->modifiers = 0x0;
        tc_jsonser_Dog_lover_o->state = 0x6;
        tc_jsonser_Dog_lover_o->weak = FALSE;
        tc_jsonser_Dog_lover_o->id = 3;
        if (db_define(tc_jsonser_Dog_lover_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::Dog::lover'.");
            goto error;
        }
    }
    /* Define ::tc_jsonser::Dog */
    if (!db_checkState(tc_jsonser_Dog_o, DB_DEFINED)) {
        db_type(tc_jsonser_Dog_o)->defaultType = db_resolve_ext(tc_jsonser_Dog_o, NULL, "::hyve::lang::member", FALSE, "element ::tc_jsonser::Dog.defaultType");
        db_type(tc_jsonser_Dog_o)->parentType = NULL;
        db_type(tc_jsonser_Dog_o)->parentState = 0x0;
        db_interface(tc_jsonser_Dog_o)->base = NULL;
        db_struct(tc_jsonser_Dog_o)->baseAccess = 0x0;
        tc_jsonser_Dog_o->implements.length = 0;
        tc_jsonser_Dog_o->implements.buffer = NULL;
        if (db_define(tc_jsonser_Dog_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::Dog'.");
            goto error;
        }
    }
    if (db_type(tc_jsonser_Dog_o)->size != sizeof(struct tc_jsonser_Dog_s)) {
        db_error("tc_jsonser_load: calculated size '%d' of type '::tc_jsonser::Dog' doesn't match C-type size '%d'", db_type(tc_jsonser_Dog_o)->size, sizeof(struct tc_jsonser_Dog_s));
    }
    /* Declare ::tc_jsonser::dog1 */
    tc_jsonser_dog1_o = db_declare(tc_jsonser_o, "dog1", db_typedef(tc_jsonser_Dog_o));
    if (!tc_jsonser_dog1_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::dog1'.");
        goto error;
    }

    /* Define ::tc_jsonser::dog1 */
    if (!db_checkState(tc_jsonser_dog1_o, DB_DEFINED)) {
        tc_jsonser_dog1_o->breed = TC_JSONSER_GoldenRetriever;
        tc_jsonser_dog1_o->name = db_strdup("Gijs");
        tc_jsonser_dog1_o->age = 10;
        tc_jsonser_dog1_o->lover = NULL;
        if (db_define(tc_jsonser_dog1_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::dog1'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::dog2 */
    tc_jsonser_dog2_o = db_declare(tc_jsonser_o, "dog2", db_typedef(tc_jsonser_Dog_o));
    if (!tc_jsonser_dog2_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::dog2'.");
        goto error;
    }

    /* Define ::tc_jsonser::dog2 */
    if (!db_checkState(tc_jsonser_dog2_o, DB_DEFINED)) {
        tc_jsonser_dog2_o->breed = TC_JSONSER_Pug;
        tc_jsonser_dog2_o->name = db_strdup("Lolly");
        tc_jsonser_dog2_o->age = 4;
        tc_jsonser_dog2_o->lover = NULL;
        if (db_define(tc_jsonser_dog2_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::dog2'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::dog3 */
    tc_jsonser_dog3_o = db_declare(tc_jsonser_o, "dog3", db_typedef(tc_jsonser_Dog_o));
    if (!tc_jsonser_dog3_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::dog3'.");
        goto error;
    }

    /* Define ::tc_jsonser::dog3 */
    if (!db_checkState(tc_jsonser_dog3_o, DB_DEFINED)) {
        tc_jsonser_dog3_o->breed = TC_JSONSER_Chihuahua;
        tc_jsonser_dog3_o->name = db_strdup("I'm annoying");
        tc_jsonser_dog3_o->age = 3;
        tc_jsonser_dog3_o->lover = db_resolve_ext(tc_jsonser_dog3_o, NULL, "::tc_jsonser::dog2", FALSE, "element ::tc_jsonser::dog3.lover");
        if (db_define(tc_jsonser_dog3_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::dog3'.");
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
