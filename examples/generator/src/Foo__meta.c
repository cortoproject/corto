/* Foo__meta.c
 *
 *  Generated on Jan 17 2014
 *    Loads objects in database.
 *    This file contains generated code. Do not modify!
 */

#include "Foo__type.h"

/* Variable definitions */
db_void (*Foo_o);
db_class Foo_Point_o;
db_method Foo_Point_add_o;
db_callback Foo_Point_construct_o;
db_method Foo_Point_getX_o;
db_method Foo_Point_getY_o;
db_method Foo_Point_printX_o;
db_method Foo_Point_printY_o;
db_method Foo_Point_set_o;
db_member Foo_Point_x_o;
db_member Foo_Point_y_o;

/* Load objects in database */
int Foo_load(void) {
    db_object _a_; /* Used for resolving anonymous objects */
    _a_ = NULL;

    /* Declare ::Foo */
    Foo_o = db_declare(root_o, "Foo", db_typedef(db_void_o));
    if (!Foo_o) {
        db_error("Foo_load: failed to declare object '::Foo'.");
        goto error;
    }

    /* Declare ::Foo::Point */
    Foo_Point_o = db_declare(Foo_o, "Point", db_typedef(db_class_o));
    if (!Foo_Point_o) {
        db_error("Foo_load: failed to declare object '::Foo::Point'.");
        goto error;
    }

    /* Declare ::Foo::Point::getX() */
    Foo_Point_getX_o = db_declare(Foo_Point_o, "getX()", db_typedef(db_method_o));
    if (!Foo_Point_getX_o) {
        db_error("Foo_load: failed to declare object '::Foo::Point::getX()'.");
        goto error;
    }

    /* Define ::Foo::Point::getX() */
    if (!db_checkState(Foo_Point_getX_o, DB_DEFINED)) {
        db_function(Foo_Point_getX_o)->returnType = db_resolve_ext(Foo_Point_getX_o, NULL, "::hyve::lang::uint32", FALSE, "element ::Foo::Point::getX().returnType");
        Foo_Point_getX_o->virtual = FALSE;
        
        /* Bind Foo_Point_getX_o with C-function */
        db_function(Foo_Point_getX_o)->kind = DB_PROCEDURE_CDECL;
        db_uint32 Foo_Point_getX(Foo_Point _this);
        db_function(Foo_Point_getX_o)->impl = (db_word)Foo_Point_getX;
        if (db_define(Foo_Point_getX_o)) {
            db_error("Foo_load: failed to define object '::Foo::Point::getX()'.");
            goto error;
        }
    }
    /* Declare ::Foo::Point::getY() */
    Foo_Point_getY_o = db_declare(Foo_Point_o, "getY()", db_typedef(db_method_o));
    if (!Foo_Point_getY_o) {
        db_error("Foo_load: failed to declare object '::Foo::Point::getY()'.");
        goto error;
    }

    /* Define ::Foo::Point::getY() */
    if (!db_checkState(Foo_Point_getY_o, DB_DEFINED)) {
        db_function(Foo_Point_getY_o)->returnType = db_resolve_ext(Foo_Point_getY_o, NULL, "::hyve::lang::uint32", FALSE, "element ::Foo::Point::getY().returnType");
        Foo_Point_getY_o->virtual = FALSE;
        
        /* Bind Foo_Point_getY_o with C-function */
        db_function(Foo_Point_getY_o)->kind = DB_PROCEDURE_CDECL;
        db_uint32 Foo_Point_getY(Foo_Point _this);
        db_function(Foo_Point_getY_o)->impl = (db_word)Foo_Point_getY;
        if (db_define(Foo_Point_getY_o)) {
            db_error("Foo_load: failed to define object '::Foo::Point::getY()'.");
            goto error;
        }
    }
    /* Declare ::Foo::Point::printX() */
    Foo_Point_printX_o = db_declare(Foo_Point_o, "printX()", db_typedef(db_method_o));
    if (!Foo_Point_printX_o) {
        db_error("Foo_load: failed to declare object '::Foo::Point::printX()'.");
        goto error;
    }

    /* Define ::Foo::Point::printX() */
    if (!db_checkState(Foo_Point_printX_o, DB_DEFINED)) {
        db_function(Foo_Point_printX_o)->returnType = db_resolve_ext(Foo_Point_printX_o, NULL, "::hyve::lang::void", FALSE, "element ::Foo::Point::printX().returnType");
        Foo_Point_printX_o->virtual = FALSE;
        
        /* Bind Foo_Point_printX_o with C-function */
        db_function(Foo_Point_printX_o)->kind = DB_PROCEDURE_CDECL;
        db_void Foo_Point_printX(Foo_Point _this);
        db_function(Foo_Point_printX_o)->impl = (db_word)Foo_Point_printX;
        if (db_define(Foo_Point_printX_o)) {
            db_error("Foo_load: failed to define object '::Foo::Point::printX()'.");
            goto error;
        }
    }
    /* Declare ::Foo::Point::printY() */
    Foo_Point_printY_o = db_declare(Foo_Point_o, "printY()", db_typedef(db_method_o));
    if (!Foo_Point_printY_o) {
        db_error("Foo_load: failed to declare object '::Foo::Point::printY()'.");
        goto error;
    }

    /* Define ::Foo::Point::printY() */
    if (!db_checkState(Foo_Point_printY_o, DB_DEFINED)) {
        db_function(Foo_Point_printY_o)->returnType = db_resolve_ext(Foo_Point_printY_o, NULL, "::hyve::lang::void", FALSE, "element ::Foo::Point::printY().returnType");
        Foo_Point_printY_o->virtual = FALSE;
        
        /* Bind Foo_Point_printY_o with C-function */
        db_function(Foo_Point_printY_o)->kind = DB_PROCEDURE_CDECL;
        db_void Foo_Point_printY(Foo_Point _this);
        db_function(Foo_Point_printY_o)->impl = (db_word)Foo_Point_printY;
        if (db_define(Foo_Point_printY_o)) {
            db_error("Foo_load: failed to define object '::Foo::Point::printY()'.");
            goto error;
        }
    }
    /* Declare ::Foo::Point::set(::hyve::lang::uint32 x,::hyve::lang::uint32 y) */
    Foo_Point_set_o = db_declare(Foo_Point_o, "set(::hyve::lang::uint32 x,::hyve::lang::uint32 y)", db_typedef(db_method_o));
    if (!Foo_Point_set_o) {
        db_error("Foo_load: failed to declare object '::Foo::Point::set(::hyve::lang::uint32 x,::hyve::lang::uint32 y)'.");
        goto error;
    }

    /* Define ::Foo::Point::set(::hyve::lang::uint32 x,::hyve::lang::uint32 y) */
    if (!db_checkState(Foo_Point_set_o, DB_DEFINED)) {
        db_function(Foo_Point_set_o)->returnType = db_resolve_ext(Foo_Point_set_o, NULL, "::hyve::lang::void", FALSE, "element ::Foo::Point::set(::hyve::lang::uint32 x,::hyve::lang::uint32 y).returnType");
        Foo_Point_set_o->virtual = FALSE;
        
        /* Bind Foo_Point_set_o with C-function */
        db_function(Foo_Point_set_o)->kind = DB_PROCEDURE_CDECL;
        db_void Foo_Point_set(Foo_Point _this, db_uint32 x, db_uint32 y);
        db_function(Foo_Point_set_o)->impl = (db_word)Foo_Point_set;
        if (db_define(Foo_Point_set_o)) {
            db_error("Foo_load: failed to define object '::Foo::Point::set(::hyve::lang::uint32 x,::hyve::lang::uint32 y)'.");
            goto error;
        }
    }
    /* Declare ::Foo::Point::x */
    Foo_Point_x_o = db_declare(Foo_Point_o, "x", db_typedef(db_member_o));
    if (!Foo_Point_x_o) {
        db_error("Foo_load: failed to declare object '::Foo::Point::x'.");
        goto error;
    }

    /* Define ::Foo::Point::x */
    if (!db_checkState(Foo_Point_x_o, DB_DEFINED)) {
        Foo_Point_x_o->type = db_resolve_ext(Foo_Point_x_o, NULL, "::hyve::lang::uint32", FALSE, "element ::Foo::Point::x.type");
        Foo_Point_x_o->modifiers = 0x0;
        Foo_Point_x_o->state = 0x6;
        Foo_Point_x_o->weak = FALSE;
        Foo_Point_x_o->id = 0;
        if (db_define(Foo_Point_x_o)) {
            db_error("Foo_load: failed to define object '::Foo::Point::x'.");
            goto error;
        }
    }
    /* Declare ::Foo::Point::y */
    Foo_Point_y_o = db_declare(Foo_Point_o, "y", db_typedef(db_member_o));
    if (!Foo_Point_y_o) {
        db_error("Foo_load: failed to declare object '::Foo::Point::y'.");
        goto error;
    }

    /* Define ::Foo::Point::y */
    if (!db_checkState(Foo_Point_y_o, DB_DEFINED)) {
        Foo_Point_y_o->type = db_resolve_ext(Foo_Point_y_o, NULL, "::hyve::lang::uint32", FALSE, "element ::Foo::Point::y.type");
        Foo_Point_y_o->modifiers = 0x0;
        Foo_Point_y_o->state = 0x6;
        Foo_Point_y_o->weak = FALSE;
        Foo_Point_y_o->id = 1;
        if (db_define(Foo_Point_y_o)) {
            db_error("Foo_load: failed to define object '::Foo::Point::y'.");
            goto error;
        }
    }
    /* Declare ::Foo::Point::add(::Foo::Point p) */
    Foo_Point_add_o = db_declare(Foo_Point_o, "add(::Foo::Point p)", db_typedef(db_method_o));
    if (!Foo_Point_add_o) {
        db_error("Foo_load: failed to declare object '::Foo::Point::add(::Foo::Point p)'.");
        goto error;
    }

    /* Define ::Foo::Point::add(::Foo::Point p) */
    if (!db_checkState(Foo_Point_add_o, DB_DEFINED)) {
        db_function(Foo_Point_add_o)->returnType = db_resolve_ext(Foo_Point_add_o, NULL, "::hyve::lang::void", FALSE, "element ::Foo::Point::add(::Foo::Point p).returnType");
        Foo_Point_add_o->virtual = FALSE;
        
        /* Bind Foo_Point_add_o with C-function */
        db_function(Foo_Point_add_o)->kind = DB_PROCEDURE_CDECL;
        db_void Foo_Point_add(Foo_Point _this, Foo_Point p);
        db_function(Foo_Point_add_o)->impl = (db_word)Foo_Point_add;
        if (db_define(Foo_Point_add_o)) {
            db_error("Foo_load: failed to define object '::Foo::Point::add(::Foo::Point p)'.");
            goto error;
        }
    }
    /* Declare ::Foo::Point::construct(::Foo::Point object) */
    Foo_Point_construct_o = db_declare(Foo_Point_o, "construct(::Foo::Point object)", db_typedef(db_callback_o));
    if (!Foo_Point_construct_o) {
        db_error("Foo_load: failed to declare object '::Foo::Point::construct(::Foo::Point object)'.");
        goto error;
    }

    /* Define ::Foo::Point::construct(::Foo::Point object) */
    if (!db_checkState(Foo_Point_construct_o, DB_DEFINED)) {
        db_function(Foo_Point_construct_o)->returnType = db_resolve_ext(Foo_Point_construct_o, NULL, "::hyve::lang::int16", FALSE, "element ::Foo::Point::construct(::Foo::Point object).returnType");
        Foo_Point_construct_o->delegate = db_resolve_ext(Foo_Point_construct_o, NULL, "::hyve::lang::class::construct(lang::object object)", FALSE, "element ::Foo::Point::construct(::Foo::Point object).delegate");
        
        /* Bind Foo_Point_construct_o with C-function */
        db_function(Foo_Point_construct_o)->kind = DB_PROCEDURE_CDECL;
        db_int16 Foo_Point_construct(Foo_Point object);
        db_function(Foo_Point_construct_o)->impl = (db_word)Foo_Point_construct;
        if (db_define(Foo_Point_construct_o)) {
            db_error("Foo_load: failed to define object '::Foo::Point::construct(::Foo::Point object)'.");
            goto error;
        }
    }
    /* Define ::Foo::Point */
    if (!db_checkState(Foo_Point_o, DB_DEFINED)) {
        db_type(Foo_Point_o)->parentType = NULL;
        db_type(Foo_Point_o)->parentState = 0x0;
        db_interface(Foo_Point_o)->base = NULL;
        db_struct(Foo_Point_o)->baseAccess = 0x0;
        db_struct(Foo_Point_o)->templateParameters.length = 0;
        db_struct(Foo_Point_o)->templateParameters.buffer = NULL;
        db_struct(Foo_Point_o)->templateMembers.length = 0;
        db_struct(Foo_Point_o)->templateMembers.buffer = NULL;
        Foo_Point_o->implements.length = 0;
        Foo_Point_o->implements.buffer = NULL;
        if (db_define(Foo_Point_o)) {
            db_error("Foo_load: failed to define object '::Foo::Point'.");
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
