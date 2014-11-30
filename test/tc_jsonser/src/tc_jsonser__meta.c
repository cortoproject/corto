/* tc_jsonser__meta.c
 *
 *  Generated on Nov 29 2014
 *    Loads objects in database.
 *    This file contains generated code. Do not modify!
 */

#include "tc_jsonser__type.h"

/* Variable definitions */
db_object tc_jsonser_o;
tc_jsonser_Point tc_jsonser_p_o;
tc_jsonser_Point tc_jsonser_p_a_o;
tc_jsonser_Point tc_jsonser_p_b_o;
tc_jsonser_Point tc_jsonser_p_c_o;
tc_jsonser_Point tc_jsonser_p_d_o;
db_class tc_jsonser_Point_o;
db_member tc_jsonser_Point_x_o;
db_member tc_jsonser_Point_y_o;
db_class tc_jsonser_PointPoint_o;
db_member tc_jsonser_PointPoint_other_o;
db_member tc_jsonser_PointPoint_x_o;
db_member tc_jsonser_PointPoint_y_o;
tc_jsonser_PointPoint tc_jsonser_pp_o;

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
    /* Declare ::tc_jsonser::Point */
    tc_jsonser_Point_o = db_declare(tc_jsonser_o, "Point", db_typedef(db_class_o));
    if (!tc_jsonser_Point_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::Point'.");
        goto error;
    }

    /* Declare ::tc_jsonser::Point::x */
    tc_jsonser_Point_x_o = db_declare(tc_jsonser_Point_o, "x", db_typedef(db_member_o));
    if (!tc_jsonser_Point_x_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::Point::x'.");
        goto error;
    }

    /* Define ::tc_jsonser::Point::x */
    if (!db_checkState(tc_jsonser_Point_x_o, DB_DEFINED)) {
        tc_jsonser_Point_x_o->type = db_resolve_ext(tc_jsonser_Point_x_o, NULL, "::hyve::lang::uint32", FALSE, "element ::tc_jsonser::Point::x.type");
        tc_jsonser_Point_x_o->modifiers = 0x0;
        tc_jsonser_Point_x_o->state = 0x6;
        tc_jsonser_Point_x_o->weak = FALSE;
        tc_jsonser_Point_x_o->id = 0;
        if (db_define(tc_jsonser_Point_x_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::Point::x'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::Point::y */
    tc_jsonser_Point_y_o = db_declare(tc_jsonser_Point_o, "y", db_typedef(db_member_o));
    if (!tc_jsonser_Point_y_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::Point::y'.");
        goto error;
    }

    /* Define ::tc_jsonser::Point::y */
    if (!db_checkState(tc_jsonser_Point_y_o, DB_DEFINED)) {
        tc_jsonser_Point_y_o->type = db_resolve_ext(tc_jsonser_Point_y_o, NULL, "::hyve::lang::uint32", FALSE, "element ::tc_jsonser::Point::y.type");
        tc_jsonser_Point_y_o->modifiers = 0x0;
        tc_jsonser_Point_y_o->state = 0x6;
        tc_jsonser_Point_y_o->weak = FALSE;
        tc_jsonser_Point_y_o->id = 1;
        if (db_define(tc_jsonser_Point_y_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::Point::y'.");
            goto error;
        }
    }
    /* Define ::tc_jsonser::Point */
    if (!db_checkState(tc_jsonser_Point_o, DB_DEFINED)) {
        db_type(tc_jsonser_Point_o)->defaultType = db_resolve_ext(tc_jsonser_Point_o, NULL, "::hyve::lang::member", FALSE, "element ::tc_jsonser::Point.defaultType");
        db_type(tc_jsonser_Point_o)->parentType = NULL;
        db_type(tc_jsonser_Point_o)->parentState = 0x0;
        db_interface(tc_jsonser_Point_o)->base = NULL;
        db_struct(tc_jsonser_Point_o)->baseAccess = 0x0;
        tc_jsonser_Point_o->implements.length = 0;
        tc_jsonser_Point_o->implements.buffer = NULL;
        if (db_define(tc_jsonser_Point_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::Point'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::p */
    tc_jsonser_p_o = db_declare(tc_jsonser_o, "p", db_typedef(tc_jsonser_Point_o));
    if (!tc_jsonser_p_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::p'.");
        goto error;
    }

    /* Define ::tc_jsonser::p */
    if (!db_checkState(tc_jsonser_p_o, DB_DEFINED)) {
        tc_jsonser_p_o->x = 10;
        tc_jsonser_p_o->y = 20;
        if (db_define(tc_jsonser_p_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::p'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::p::a */
    tc_jsonser_p_a_o = db_declare(tc_jsonser_p_o, "a", db_typedef(tc_jsonser_Point_o));
    if (!tc_jsonser_p_a_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::p::a'.");
        goto error;
    }

    /* Define ::tc_jsonser::p::a */
    if (!db_checkState(tc_jsonser_p_a_o, DB_DEFINED)) {
        tc_jsonser_p_a_o->x = 34;
        tc_jsonser_p_a_o->y = 55;
        if (db_define(tc_jsonser_p_a_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::p::a'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::p::b */
    tc_jsonser_p_b_o = db_declare(tc_jsonser_p_o, "b", db_typedef(tc_jsonser_Point_o));
    if (!tc_jsonser_p_b_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::p::b'.");
        goto error;
    }

    /* Define ::tc_jsonser::p::b */
    if (!db_checkState(tc_jsonser_p_b_o, DB_DEFINED)) {
        tc_jsonser_p_b_o->x = 6;
        tc_jsonser_p_b_o->y = 7;
        if (db_define(tc_jsonser_p_b_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::p::b'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::p::c */
    tc_jsonser_p_c_o = db_declare(tc_jsonser_p_o, "c", db_typedef(tc_jsonser_Point_o));
    if (!tc_jsonser_p_c_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::p::c'.");
        goto error;
    }

    /* Define ::tc_jsonser::p::c */
    if (!db_checkState(tc_jsonser_p_c_o, DB_DEFINED)) {
        tc_jsonser_p_c_o->x = 8;
        tc_jsonser_p_c_o->y = 9;
        if (db_define(tc_jsonser_p_c_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::p::c'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::p::d */
    tc_jsonser_p_d_o = db_declare(tc_jsonser_p_o, "d", db_typedef(tc_jsonser_Point_o));
    if (!tc_jsonser_p_d_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::p::d'.");
        goto error;
    }

    /* Define ::tc_jsonser::p::d */
    if (!db_checkState(tc_jsonser_p_d_o, DB_DEFINED)) {
        tc_jsonser_p_d_o->x = 1;
        tc_jsonser_p_d_o->y = 2;
        if (db_define(tc_jsonser_p_d_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::p::d'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::PointPoint */
    tc_jsonser_PointPoint_o = db_declare(tc_jsonser_o, "PointPoint", db_typedef(db_class_o));
    if (!tc_jsonser_PointPoint_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::PointPoint'.");
        goto error;
    }

    /* Declare ::tc_jsonser::PointPoint::other */
    tc_jsonser_PointPoint_other_o = db_declare(tc_jsonser_PointPoint_o, "other", db_typedef(db_member_o));
    if (!tc_jsonser_PointPoint_other_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::PointPoint::other'.");
        goto error;
    }

    /* Define ::tc_jsonser::PointPoint::other */
    if (!db_checkState(tc_jsonser_PointPoint_other_o, DB_DEFINED)) {
        tc_jsonser_PointPoint_other_o->type = db_resolve_ext(tc_jsonser_PointPoint_other_o, NULL, "::tc_jsonser::Point", FALSE, "element ::tc_jsonser::PointPoint::other.type");
        tc_jsonser_PointPoint_other_o->modifiers = 0x0;
        tc_jsonser_PointPoint_other_o->state = 0x6;
        tc_jsonser_PointPoint_other_o->weak = FALSE;
        tc_jsonser_PointPoint_other_o->id = 2;
        if (db_define(tc_jsonser_PointPoint_other_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::PointPoint::other'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::PointPoint::x */
    tc_jsonser_PointPoint_x_o = db_declare(tc_jsonser_PointPoint_o, "x", db_typedef(db_member_o));
    if (!tc_jsonser_PointPoint_x_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::PointPoint::x'.");
        goto error;
    }

    /* Define ::tc_jsonser::PointPoint::x */
    if (!db_checkState(tc_jsonser_PointPoint_x_o, DB_DEFINED)) {
        tc_jsonser_PointPoint_x_o->type = db_resolve_ext(tc_jsonser_PointPoint_x_o, NULL, "::hyve::lang::uint32", FALSE, "element ::tc_jsonser::PointPoint::x.type");
        tc_jsonser_PointPoint_x_o->modifiers = 0x0;
        tc_jsonser_PointPoint_x_o->state = 0x6;
        tc_jsonser_PointPoint_x_o->weak = FALSE;
        tc_jsonser_PointPoint_x_o->id = 0;
        if (db_define(tc_jsonser_PointPoint_x_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::PointPoint::x'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::PointPoint::y */
    tc_jsonser_PointPoint_y_o = db_declare(tc_jsonser_PointPoint_o, "y", db_typedef(db_member_o));
    if (!tc_jsonser_PointPoint_y_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::PointPoint::y'.");
        goto error;
    }

    /* Define ::tc_jsonser::PointPoint::y */
    if (!db_checkState(tc_jsonser_PointPoint_y_o, DB_DEFINED)) {
        tc_jsonser_PointPoint_y_o->type = db_resolve_ext(tc_jsonser_PointPoint_y_o, NULL, "::hyve::lang::uint32", FALSE, "element ::tc_jsonser::PointPoint::y.type");
        tc_jsonser_PointPoint_y_o->modifiers = 0x0;
        tc_jsonser_PointPoint_y_o->state = 0x6;
        tc_jsonser_PointPoint_y_o->weak = FALSE;
        tc_jsonser_PointPoint_y_o->id = 1;
        if (db_define(tc_jsonser_PointPoint_y_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::PointPoint::y'.");
            goto error;
        }
    }
    /* Define ::tc_jsonser::PointPoint */
    if (!db_checkState(tc_jsonser_PointPoint_o, DB_DEFINED)) {
        db_type(tc_jsonser_PointPoint_o)->defaultType = db_resolve_ext(tc_jsonser_PointPoint_o, NULL, "::hyve::lang::member", FALSE, "element ::tc_jsonser::PointPoint.defaultType");
        db_type(tc_jsonser_PointPoint_o)->parentType = NULL;
        db_type(tc_jsonser_PointPoint_o)->parentState = 0x0;
        db_interface(tc_jsonser_PointPoint_o)->base = NULL;
        db_struct(tc_jsonser_PointPoint_o)->baseAccess = 0x0;
        tc_jsonser_PointPoint_o->implements.length = 0;
        tc_jsonser_PointPoint_o->implements.buffer = NULL;
        if (db_define(tc_jsonser_PointPoint_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::PointPoint'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::pp */
    tc_jsonser_pp_o = db_declare(tc_jsonser_o, "pp", db_typedef(tc_jsonser_PointPoint_o));
    if (!tc_jsonser_pp_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::pp'.");
        goto error;
    }

    /* Define ::tc_jsonser::pp */
    if (!db_checkState(tc_jsonser_pp_o, DB_DEFINED)) {
        tc_jsonser_pp_o->x = 1;
        tc_jsonser_pp_o->y = 2;
        tc_jsonser_pp_o->other = db_resolve_ext(tc_jsonser_pp_o, NULL, "::tc_jsonser::Point{5,6}", FALSE, "element ::tc_jsonser::pp.other");
        if (db_define(tc_jsonser_pp_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::pp'.");
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
