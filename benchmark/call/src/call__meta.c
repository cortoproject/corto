/* call__meta.c
 *
 *  Generated on Feb  5 2014
 *    Loads objects in database.
 *    This file contains generated code. Do not modify!
 */

#include "call__type.h"

/* Variable definitions */
db_void (*call_o);
db_function call_complexCall_o;
db_function call_floatCall_o;
db_function call_noargCall_o;
db_struct call_Point_o;
db_member call_Point_x_o;
db_member call_Point_y_o;
db_function call_wordCall_o;

/* Load objects in database */
int call_load(void) {
    db_object _a_; /* Used for resolving anonymous objects */
    _a_ = NULL;

    /* Declare ::call */
    call_o = db_declare(root_o, "call", db_typedef(db_void_o));
    if (!call_o) {
        db_error("call_load: failed to declare object '::call'.");
        goto error;
    }

    /* Declare ::call::complexCall(::hyve::lang::word w1,::hyve::lang::word w2,::hyve::lang::word w3,::hyve::lang::word w4) */
    call_complexCall_o = db_declare(call_o, "complexCall(::hyve::lang::word w1,::hyve::lang::word w2,::hyve::lang::word w3,::hyve::lang::word w4)", db_typedef(db_function_o));
    if (!call_complexCall_o) {
        db_error("call_load: failed to declare object '::call::complexCall(::hyve::lang::word w1,::hyve::lang::word w2,::hyve::lang::word w3,::hyve::lang::word w4)'.");
        goto error;
    }

    /* Declare ::call::floatCall(::hyve::lang::word w1,::hyve::lang::word w2,::hyve::lang::word w3,::hyve::lang::word w4) */
    call_floatCall_o = db_declare(call_o, "floatCall(::hyve::lang::word w1,::hyve::lang::word w2,::hyve::lang::word w3,::hyve::lang::word w4)", db_typedef(db_function_o));
    if (!call_floatCall_o) {
        db_error("call_load: failed to declare object '::call::floatCall(::hyve::lang::word w1,::hyve::lang::word w2,::hyve::lang::word w3,::hyve::lang::word w4)'.");
        goto error;
    }

    /* Define ::call::floatCall(::hyve::lang::word w1,::hyve::lang::word w2,::hyve::lang::word w3,::hyve::lang::word w4) */
    if (!db_checkState(call_floatCall_o, DB_DEFINED)) {
        call_floatCall_o->returnType = db_resolve_ext(call_floatCall_o, NULL, "::hyve::lang::float64", FALSE, "element ::call::floatCall(::hyve::lang::word w1,::hyve::lang::word w2,::hyve::lang::word w3,::hyve::lang::word w4).returnType");
        
        /* Bind call_floatCall_o with C-function */
        db_function(call_floatCall_o)->kind = DB_PROCEDURE_CDECL;
        db_float64 call_floatCall(db_word w1, db_word w2, db_word w3, db_word w4);
        db_function(call_floatCall_o)->impl = (db_word)call_floatCall;
        if (db_define(call_floatCall_o)) {
            db_error("call_load: failed to define object '::call::floatCall(::hyve::lang::word w1,::hyve::lang::word w2,::hyve::lang::word w3,::hyve::lang::word w4)'.");
            goto error;
        }
    }
    /* Declare ::call::noargCall() */
    call_noargCall_o = db_declare(call_o, "noargCall()", db_typedef(db_function_o));
    if (!call_noargCall_o) {
        db_error("call_load: failed to declare object '::call::noargCall()'.");
        goto error;
    }

    /* Define ::call::noargCall() */
    if (!db_checkState(call_noargCall_o, DB_DEFINED)) {
        call_noargCall_o->returnType = db_resolve_ext(call_noargCall_o, NULL, "::hyve::lang::void", FALSE, "element ::call::noargCall().returnType");
        
        /* Bind call_noargCall_o with C-function */
        db_function(call_noargCall_o)->kind = DB_PROCEDURE_CDECL;
        db_void call_noargCall(void);
        db_function(call_noargCall_o)->impl = (db_word)call_noargCall;
        if (db_define(call_noargCall_o)) {
            db_error("call_load: failed to define object '::call::noargCall()'.");
            goto error;
        }
    }
    /* Declare ::call::Point */
    call_Point_o = db_declare(call_o, "Point", db_typedef(db_struct_o));
    if (!call_Point_o) {
        db_error("call_load: failed to declare object '::call::Point'.");
        goto error;
    }

    /* Declare ::call::Point::x */
    call_Point_x_o = db_declare(call_Point_o, "x", db_typedef(db_member_o));
    if (!call_Point_x_o) {
        db_error("call_load: failed to declare object '::call::Point::x'.");
        goto error;
    }

    /* Define ::call::Point::x */
    if (!db_checkState(call_Point_x_o, DB_DEFINED)) {
        call_Point_x_o->type = db_resolve_ext(call_Point_x_o, NULL, "::hyve::lang::uint32", FALSE, "element ::call::Point::x.type");
        call_Point_x_o->modifiers = 0x0;
        call_Point_x_o->state = 0x6;
        call_Point_x_o->weak = FALSE;
        call_Point_x_o->id = 0;
        if (db_define(call_Point_x_o)) {
            db_error("call_load: failed to define object '::call::Point::x'.");
            goto error;
        }
    }
    /* Declare ::call::Point::y */
    call_Point_y_o = db_declare(call_Point_o, "y", db_typedef(db_member_o));
    if (!call_Point_y_o) {
        db_error("call_load: failed to declare object '::call::Point::y'.");
        goto error;
    }

    /* Define ::call::Point::y */
    if (!db_checkState(call_Point_y_o, DB_DEFINED)) {
        call_Point_y_o->type = db_resolve_ext(call_Point_y_o, NULL, "::hyve::lang::uint32", FALSE, "element ::call::Point::y.type");
        call_Point_y_o->modifiers = 0x0;
        call_Point_y_o->state = 0x6;
        call_Point_y_o->weak = FALSE;
        call_Point_y_o->id = 1;
        if (db_define(call_Point_y_o)) {
            db_error("call_load: failed to define object '::call::Point::y'.");
            goto error;
        }
    }
    /* Define ::call::Point */
    if (!db_checkState(call_Point_o, DB_DEFINED)) {
        db_type(call_Point_o)->parentType = NULL;
        db_type(call_Point_o)->parentState = 0x0;
        db_interface(call_Point_o)->base = NULL;
        call_Point_o->baseAccess = 0x0;
        if (db_define(call_Point_o)) {
            db_error("call_load: failed to define object '::call::Point'.");
            goto error;
        }
    }
    /* Define ::call::complexCall(::hyve::lang::word w1,::hyve::lang::word w2,::hyve::lang::word w3,::hyve::lang::word w4) */
    if (!db_checkState(call_complexCall_o, DB_DEFINED)) {
        call_complexCall_o->returnType = db_resolve_ext(call_complexCall_o, NULL, "::call::Point", FALSE, "element ::call::complexCall(::hyve::lang::word w1,::hyve::lang::word w2,::hyve::lang::word w3,::hyve::lang::word w4).returnType");
        
        /* Bind call_complexCall_o with C-function */
        db_function(call_complexCall_o)->kind = DB_PROCEDURE_CDECL;
        call_Point call_complexCall(db_word w1, db_word w2, db_word w3, db_word w4);
        db_function(call_complexCall_o)->impl = (db_word)call_complexCall;
        if (db_define(call_complexCall_o)) {
            db_error("call_load: failed to define object '::call::complexCall(::hyve::lang::word w1,::hyve::lang::word w2,::hyve::lang::word w3,::hyve::lang::word w4)'.");
            goto error;
        }
    }
    /* Declare ::call::wordCall(::hyve::lang::word w1,::hyve::lang::word w2,::hyve::lang::word w3,::hyve::lang::word w4) */
    call_wordCall_o = db_declare(call_o, "wordCall(::hyve::lang::word w1,::hyve::lang::word w2,::hyve::lang::word w3,::hyve::lang::word w4)", db_typedef(db_function_o));
    if (!call_wordCall_o) {
        db_error("call_load: failed to declare object '::call::wordCall(::hyve::lang::word w1,::hyve::lang::word w2,::hyve::lang::word w3,::hyve::lang::word w4)'.");
        goto error;
    }

    /* Define ::call::wordCall(::hyve::lang::word w1,::hyve::lang::word w2,::hyve::lang::word w3,::hyve::lang::word w4) */
    if (!db_checkState(call_wordCall_o, DB_DEFINED)) {
        call_wordCall_o->returnType = db_resolve_ext(call_wordCall_o, NULL, "::hyve::lang::word", FALSE, "element ::call::wordCall(::hyve::lang::word w1,::hyve::lang::word w2,::hyve::lang::word w3,::hyve::lang::word w4).returnType");
        
        /* Bind call_wordCall_o with C-function */
        db_function(call_wordCall_o)->kind = DB_PROCEDURE_CDECL;
        db_word call_wordCall(db_word w1, db_word w2, db_word w3, db_word w4);
        db_function(call_wordCall_o)->impl = (db_word)call_wordCall;
        if (db_define(call_wordCall_o)) {
            db_error("call_load: failed to define object '::call::wordCall(::hyve::lang::word w1,::hyve::lang::word w2,::hyve::lang::word w3,::hyve::lang::word w4)'.");
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
