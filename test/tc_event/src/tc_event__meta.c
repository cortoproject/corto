/* tc_event__meta.c
 *
 *  Generated on Feb  5 2014
 *    Loads objects in database.
 *    This file contains generated code. Do not modify!
 */

#include "tc_event__type.h"

/* Variable definitions */
db_object tc_o;
db_observer tc_construct_onBoth_o;
db_observer tc_construct_onChild_o;
db_observer tc_construct_onRootChilds_o;
db_observer tc_construct_onRootSelf_o;
db_observer tc_construct_onSelf_o;
db_observer tc_destruct_onBoth_o;
db_observer tc_destruct_onChild_o;
db_observer tc_destruct_onRootChilds_o;
db_observer tc_destruct_onRootSelf_o;
db_observer tc_destruct_onSelf_o;
db_observer tc_new_onBoth_o;
db_observer tc_new_onChild_o;
db_observer tc_new_onRootChilds_o;
db_observer tc_new_onRootSelf_o;
db_observer tc_new_onSelf_o;
tc_Point tc_parent_o;
tc_Point tc_parent_child_o;
db_class tc_Point_o;
db_observer tc_Point_construct_onThis_o;
db_observer tc_Point_destruct_onThis_o;
db_observer tc_Point_new_onThis_o;
db_observer tc_Point_update_onThis_o;
db_member tc_Point_x_o;
db_member tc_Point_y_o;
db_observer tc_update_onBoth_o;
db_observer tc_update_onChild_o;
db_observer tc_update_onRootChilds_o;
db_observer tc_update_onRootSelf_o;
db_observer tc_update_onSelf_o;
db_typedef tc_value_o;

/* Load objects in database */
int tc_event_load(void) {
    db_object _a_; /* Used for resolving anonymous objects */
    _a_ = NULL;

    /* Declare ::tc_event */
    tc_o = db_declare(root_o, "tc_event", db_typedef(db_object_o));
    if (!tc_o) {
        db_error("tc_event_load: failed to declare object '::tc_event'.");
        goto error;
    }

    /* Define ::tc_event */
    if (!db_checkState(tc_o, DB_DEFINED)) {
        if (db_define(tc_o)) {
            db_error("tc_event_load: failed to define object '::tc_event'.");
            goto error;
        }
    }
    /* Declare ::tc_event::construct_onBoth */
    tc_construct_onBoth_o = db_declare(tc_o, "construct_onBoth", db_typedef(db_observer_o));
    if (!tc_construct_onBoth_o) {
        db_error("tc_event_load: failed to declare object '::tc_event::construct_onBoth'.");
        goto error;
    }

    /* Declare ::tc_event::construct_onChild */
    tc_construct_onChild_o = db_declare(tc_o, "construct_onChild", db_typedef(db_observer_o));
    if (!tc_construct_onChild_o) {
        db_error("tc_event_load: failed to declare object '::tc_event::construct_onChild'.");
        goto error;
    }

    /* Declare ::tc_event::construct_onRootChilds */
    tc_construct_onRootChilds_o = db_declare(tc_o, "construct_onRootChilds", db_typedef(db_observer_o));
    if (!tc_construct_onRootChilds_o) {
        db_error("tc_event_load: failed to declare object '::tc_event::construct_onRootChilds'.");
        goto error;
    }

    /* Define ::tc_event::construct_onRootChilds */
    if (!db_checkState(tc_construct_onRootChilds_o, DB_DEFINED)) {
        tc_construct_onRootChilds_o->observable = db_resolve_ext(tc_construct_onRootChilds_o, NULL, "::", FALSE, "element ::tc_event::construct_onRootChilds.observable");
        tc_construct_onRootChilds_o->mask = 0xc2;
        tc_construct_onRootChilds_o->expression = NULL;
        tc_construct_onRootChilds_o->template = 0;
        tc_construct_onRootChilds_o->dispatcher = NULL;
        tc_construct_onRootChilds_o->me = NULL;
        
        /* Bind tc_construct_onRootChilds_o with C-function */
        db_function(tc_construct_onRootChilds_o)->kind = DB_PROCEDURE_CDECL;
        db_void tc_construct_onRootChilds(db_object *observable, db_object *source);
        db_function(tc_construct_onRootChilds_o)->impl = (db_word)tc_construct_onRootChilds;
        if (db_define(tc_construct_onRootChilds_o)) {
            db_error("tc_event_load: failed to define object '::tc_event::construct_onRootChilds'.");
            goto error;
        }
    }
    /* Declare ::tc_event::construct_onRootSelf */
    tc_construct_onRootSelf_o = db_declare(tc_o, "construct_onRootSelf", db_typedef(db_observer_o));
    if (!tc_construct_onRootSelf_o) {
        db_error("tc_event_load: failed to declare object '::tc_event::construct_onRootSelf'.");
        goto error;
    }

    /* Define ::tc_event::construct_onRootSelf */
    if (!db_checkState(tc_construct_onRootSelf_o, DB_DEFINED)) {
        tc_construct_onRootSelf_o->observable = db_resolve_ext(tc_construct_onRootSelf_o, NULL, "::", FALSE, "element ::tc_event::construct_onRootSelf.observable");
        tc_construct_onRootSelf_o->mask = 0xa2;
        tc_construct_onRootSelf_o->expression = NULL;
        tc_construct_onRootSelf_o->template = 0;
        tc_construct_onRootSelf_o->dispatcher = NULL;
        tc_construct_onRootSelf_o->me = NULL;
        
        /* Bind tc_construct_onRootSelf_o with C-function */
        db_function(tc_construct_onRootSelf_o)->kind = DB_PROCEDURE_CDECL;
        db_void tc_construct_onRootSelf(db_object *observable, db_object *source);
        db_function(tc_construct_onRootSelf_o)->impl = (db_word)tc_construct_onRootSelf;
        if (db_define(tc_construct_onRootSelf_o)) {
            db_error("tc_event_load: failed to define object '::tc_event::construct_onRootSelf'.");
            goto error;
        }
    }
    /* Declare ::tc_event::construct_onSelf */
    tc_construct_onSelf_o = db_declare(tc_o, "construct_onSelf", db_typedef(db_observer_o));
    if (!tc_construct_onSelf_o) {
        db_error("tc_event_load: failed to declare object '::tc_event::construct_onSelf'.");
        goto error;
    }

    /* Declare ::tc_event::destruct_onBoth */
    tc_destruct_onBoth_o = db_declare(tc_o, "destruct_onBoth", db_typedef(db_observer_o));
    if (!tc_destruct_onBoth_o) {
        db_error("tc_event_load: failed to declare object '::tc_event::destruct_onBoth'.");
        goto error;
    }

    /* Declare ::tc_event::destruct_onChild */
    tc_destruct_onChild_o = db_declare(tc_o, "destruct_onChild", db_typedef(db_observer_o));
    if (!tc_destruct_onChild_o) {
        db_error("tc_event_load: failed to declare object '::tc_event::destruct_onChild'.");
        goto error;
    }

    /* Declare ::tc_event::destruct_onRootChilds */
    tc_destruct_onRootChilds_o = db_declare(tc_o, "destruct_onRootChilds", db_typedef(db_observer_o));
    if (!tc_destruct_onRootChilds_o) {
        db_error("tc_event_load: failed to declare object '::tc_event::destruct_onRootChilds'.");
        goto error;
    }

    /* Define ::tc_event::destruct_onRootChilds */
    if (!db_checkState(tc_destruct_onRootChilds_o, DB_DEFINED)) {
        tc_destruct_onRootChilds_o->observable = db_resolve_ext(tc_destruct_onRootChilds_o, NULL, "::", FALSE, "element ::tc_event::destruct_onRootChilds.observable");
        tc_destruct_onRootChilds_o->mask = 0xc4;
        tc_destruct_onRootChilds_o->expression = NULL;
        tc_destruct_onRootChilds_o->template = 0;
        tc_destruct_onRootChilds_o->dispatcher = NULL;
        tc_destruct_onRootChilds_o->me = NULL;
        
        /* Bind tc_destruct_onRootChilds_o with C-function */
        db_function(tc_destruct_onRootChilds_o)->kind = DB_PROCEDURE_CDECL;
        db_void tc_destruct_onRootChilds(db_object *observable, db_object *source);
        db_function(tc_destruct_onRootChilds_o)->impl = (db_word)tc_destruct_onRootChilds;
        if (db_define(tc_destruct_onRootChilds_o)) {
            db_error("tc_event_load: failed to define object '::tc_event::destruct_onRootChilds'.");
            goto error;
        }
    }
    /* Declare ::tc_event::destruct_onRootSelf */
    tc_destruct_onRootSelf_o = db_declare(tc_o, "destruct_onRootSelf", db_typedef(db_observer_o));
    if (!tc_destruct_onRootSelf_o) {
        db_error("tc_event_load: failed to declare object '::tc_event::destruct_onRootSelf'.");
        goto error;
    }

    /* Define ::tc_event::destruct_onRootSelf */
    if (!db_checkState(tc_destruct_onRootSelf_o, DB_DEFINED)) {
        tc_destruct_onRootSelf_o->observable = db_resolve_ext(tc_destruct_onRootSelf_o, NULL, "::", FALSE, "element ::tc_event::destruct_onRootSelf.observable");
        tc_destruct_onRootSelf_o->mask = 0xa4;
        tc_destruct_onRootSelf_o->expression = NULL;
        tc_destruct_onRootSelf_o->template = 0;
        tc_destruct_onRootSelf_o->dispatcher = NULL;
        tc_destruct_onRootSelf_o->me = NULL;
        
        /* Bind tc_destruct_onRootSelf_o with C-function */
        db_function(tc_destruct_onRootSelf_o)->kind = DB_PROCEDURE_CDECL;
        db_void tc_destruct_onRootSelf(db_object *observable, db_object *source);
        db_function(tc_destruct_onRootSelf_o)->impl = (db_word)tc_destruct_onRootSelf;
        if (db_define(tc_destruct_onRootSelf_o)) {
            db_error("tc_event_load: failed to define object '::tc_event::destruct_onRootSelf'.");
            goto error;
        }
    }
    /* Declare ::tc_event::destruct_onSelf */
    tc_destruct_onSelf_o = db_declare(tc_o, "destruct_onSelf", db_typedef(db_observer_o));
    if (!tc_destruct_onSelf_o) {
        db_error("tc_event_load: failed to declare object '::tc_event::destruct_onSelf'.");
        goto error;
    }

    /* Declare ::tc_event::new_onBoth */
    tc_new_onBoth_o = db_declare(tc_o, "new_onBoth", db_typedef(db_observer_o));
    if (!tc_new_onBoth_o) {
        db_error("tc_event_load: failed to declare object '::tc_event::new_onBoth'.");
        goto error;
    }

    /* Declare ::tc_event::new_onChild */
    tc_new_onChild_o = db_declare(tc_o, "new_onChild", db_typedef(db_observer_o));
    if (!tc_new_onChild_o) {
        db_error("tc_event_load: failed to declare object '::tc_event::new_onChild'.");
        goto error;
    }

    /* Declare ::tc_event::new_onRootChilds */
    tc_new_onRootChilds_o = db_declare(tc_o, "new_onRootChilds", db_typedef(db_observer_o));
    if (!tc_new_onRootChilds_o) {
        db_error("tc_event_load: failed to declare object '::tc_event::new_onRootChilds'.");
        goto error;
    }

    /* Define ::tc_event::new_onRootChilds */
    if (!db_checkState(tc_new_onRootChilds_o, DB_DEFINED)) {
        tc_new_onRootChilds_o->observable = db_resolve_ext(tc_new_onRootChilds_o, NULL, "::", FALSE, "element ::tc_event::new_onRootChilds.observable");
        tc_new_onRootChilds_o->mask = 0xc1;
        tc_new_onRootChilds_o->expression = NULL;
        tc_new_onRootChilds_o->template = 0;
        tc_new_onRootChilds_o->dispatcher = NULL;
        tc_new_onRootChilds_o->me = NULL;
        
        /* Bind tc_new_onRootChilds_o with C-function */
        db_function(tc_new_onRootChilds_o)->kind = DB_PROCEDURE_CDECL;
        db_void tc_new_onRootChilds(db_object *observable, db_object *source);
        db_function(tc_new_onRootChilds_o)->impl = (db_word)tc_new_onRootChilds;
        if (db_define(tc_new_onRootChilds_o)) {
            db_error("tc_event_load: failed to define object '::tc_event::new_onRootChilds'.");
            goto error;
        }
    }
    /* Declare ::tc_event::new_onRootSelf */
    tc_new_onRootSelf_o = db_declare(tc_o, "new_onRootSelf", db_typedef(db_observer_o));
    if (!tc_new_onRootSelf_o) {
        db_error("tc_event_load: failed to declare object '::tc_event::new_onRootSelf'.");
        goto error;
    }

    /* Define ::tc_event::new_onRootSelf */
    if (!db_checkState(tc_new_onRootSelf_o, DB_DEFINED)) {
        tc_new_onRootSelf_o->observable = db_resolve_ext(tc_new_onRootSelf_o, NULL, "::", FALSE, "element ::tc_event::new_onRootSelf.observable");
        tc_new_onRootSelf_o->mask = 0xa1;
        tc_new_onRootSelf_o->expression = NULL;
        tc_new_onRootSelf_o->template = 0;
        tc_new_onRootSelf_o->dispatcher = NULL;
        tc_new_onRootSelf_o->me = NULL;
        
        /* Bind tc_new_onRootSelf_o with C-function */
        db_function(tc_new_onRootSelf_o)->kind = DB_PROCEDURE_CDECL;
        db_void tc_new_onRootSelf(db_object *observable, db_object *source);
        db_function(tc_new_onRootSelf_o)->impl = (db_word)tc_new_onRootSelf;
        if (db_define(tc_new_onRootSelf_o)) {
            db_error("tc_event_load: failed to define object '::tc_event::new_onRootSelf'.");
            goto error;
        }
    }
    /* Declare ::tc_event::new_onSelf */
    tc_new_onSelf_o = db_declare(tc_o, "new_onSelf", db_typedef(db_observer_o));
    if (!tc_new_onSelf_o) {
        db_error("tc_event_load: failed to declare object '::tc_event::new_onSelf'.");
        goto error;
    }

    /* Declare ::tc_event::Point */
    tc_Point_o = db_declare(tc_o, "Point", db_typedef(db_class_o));
    if (!tc_Point_o) {
        db_error("tc_event_load: failed to declare object '::tc_event::Point'.");
        goto error;
    }

    /* Declare ::tc_event::Point::construct_onThis */
    tc_Point_construct_onThis_o = db_declare(tc_Point_o, "construct_onThis", db_typedef(db_observer_o));
    if (!tc_Point_construct_onThis_o) {
        db_error("tc_event_load: failed to declare object '::tc_event::Point::construct_onThis'.");
        goto error;
    }

    /* Define ::tc_event::Point::construct_onThis */
    if (!db_checkState(tc_Point_construct_onThis_o, DB_DEFINED)) {
        tc_Point_construct_onThis_o->observable = NULL;
        tc_Point_construct_onThis_o->mask = 0xa2;
        tc_Point_construct_onThis_o->expression = NULL;
        tc_Point_construct_onThis_o->template = 3;
        tc_Point_construct_onThis_o->dispatcher = NULL;
        tc_Point_construct_onThis_o->me = NULL;
        
        /* Bind tc_Point_construct_onThis_o with C-function */
        db_function(tc_Point_construct_onThis_o)->kind = DB_PROCEDURE_CDECL;
        db_void tc_Point_construct_onThis(tc_Point _this, db_object *observable, db_object *source);
        db_function(tc_Point_construct_onThis_o)->impl = (db_word)tc_Point_construct_onThis;
        if (db_define(tc_Point_construct_onThis_o)) {
            db_error("tc_event_load: failed to define object '::tc_event::Point::construct_onThis'.");
            goto error;
        }
    }
    /* Declare ::tc_event::Point::destruct_onThis */
    tc_Point_destruct_onThis_o = db_declare(tc_Point_o, "destruct_onThis", db_typedef(db_observer_o));
    if (!tc_Point_destruct_onThis_o) {
        db_error("tc_event_load: failed to declare object '::tc_event::Point::destruct_onThis'.");
        goto error;
    }

    /* Define ::tc_event::Point::destruct_onThis */
    if (!db_checkState(tc_Point_destruct_onThis_o, DB_DEFINED)) {
        tc_Point_destruct_onThis_o->observable = NULL;
        tc_Point_destruct_onThis_o->mask = 0xa4;
        tc_Point_destruct_onThis_o->expression = NULL;
        tc_Point_destruct_onThis_o->template = 4;
        tc_Point_destruct_onThis_o->dispatcher = NULL;
        tc_Point_destruct_onThis_o->me = NULL;
        
        /* Bind tc_Point_destruct_onThis_o with C-function */
        db_function(tc_Point_destruct_onThis_o)->kind = DB_PROCEDURE_CDECL;
        db_void tc_Point_destruct_onThis(tc_Point _this, db_object *observable, db_object *source);
        db_function(tc_Point_destruct_onThis_o)->impl = (db_word)tc_Point_destruct_onThis;
        if (db_define(tc_Point_destruct_onThis_o)) {
            db_error("tc_event_load: failed to define object '::tc_event::Point::destruct_onThis'.");
            goto error;
        }
    }
    /* Declare ::tc_event::Point::new_onThis */
    tc_Point_new_onThis_o = db_declare(tc_Point_o, "new_onThis", db_typedef(db_observer_o));
    if (!tc_Point_new_onThis_o) {
        db_error("tc_event_load: failed to declare object '::tc_event::Point::new_onThis'.");
        goto error;
    }

    /* Define ::tc_event::Point::new_onThis */
    if (!db_checkState(tc_Point_new_onThis_o, DB_DEFINED)) {
        tc_Point_new_onThis_o->observable = NULL;
        tc_Point_new_onThis_o->mask = 0xa1;
        tc_Point_new_onThis_o->expression = NULL;
        tc_Point_new_onThis_o->template = 2;
        tc_Point_new_onThis_o->dispatcher = NULL;
        tc_Point_new_onThis_o->me = NULL;
        
        /* Bind tc_Point_new_onThis_o with C-function */
        db_function(tc_Point_new_onThis_o)->kind = DB_PROCEDURE_CDECL;
        db_void tc_Point_new_onThis(tc_Point _this, db_object *observable, db_object *source);
        db_function(tc_Point_new_onThis_o)->impl = (db_word)tc_Point_new_onThis;
        if (db_define(tc_Point_new_onThis_o)) {
            db_error("tc_event_load: failed to define object '::tc_event::Point::new_onThis'.");
            goto error;
        }
    }
    /* Declare ::tc_event::Point::update_onThis */
    tc_Point_update_onThis_o = db_declare(tc_Point_o, "update_onThis", db_typedef(db_observer_o));
    if (!tc_Point_update_onThis_o) {
        db_error("tc_event_load: failed to declare object '::tc_event::Point::update_onThis'.");
        goto error;
    }

    /* Define ::tc_event::Point::update_onThis */
    if (!db_checkState(tc_Point_update_onThis_o, DB_DEFINED)) {
        tc_Point_update_onThis_o->observable = NULL;
        tc_Point_update_onThis_o->mask = 0xb0;
        tc_Point_update_onThis_o->expression = NULL;
        tc_Point_update_onThis_o->template = 1;
        tc_Point_update_onThis_o->dispatcher = NULL;
        tc_Point_update_onThis_o->me = NULL;
        
        /* Bind tc_Point_update_onThis_o with C-function */
        db_function(tc_Point_update_onThis_o)->kind = DB_PROCEDURE_CDECL;
        db_void tc_Point_update_onThis(tc_Point _this, db_object *observable, db_object *source);
        db_function(tc_Point_update_onThis_o)->impl = (db_word)tc_Point_update_onThis;
        if (db_define(tc_Point_update_onThis_o)) {
            db_error("tc_event_load: failed to define object '::tc_event::Point::update_onThis'.");
            goto error;
        }
    }
    /* Declare ::tc_event::Point::x */
    tc_Point_x_o = db_declare(tc_Point_o, "x", db_typedef(db_member_o));
    if (!tc_Point_x_o) {
        db_error("tc_event_load: failed to declare object '::tc_event::Point::x'.");
        goto error;
    }

    /* Define ::tc_event::Point::x */
    if (!db_checkState(tc_Point_x_o, DB_DEFINED)) {
        tc_Point_x_o->type = db_resolve_ext(tc_Point_x_o, NULL, "::cortex::lang::uint32", FALSE, "element ::tc_event::Point::x.type");
        tc_Point_x_o->modifiers = 0x0;
        tc_Point_x_o->state = 0x6;
        tc_Point_x_o->weak = FALSE;
        tc_Point_x_o->id = 0;
        if (db_define(tc_Point_x_o)) {
            db_error("tc_event_load: failed to define object '::tc_event::Point::x'.");
            goto error;
        }
    }
    /* Declare ::tc_event::Point::y */
    tc_Point_y_o = db_declare(tc_Point_o, "y", db_typedef(db_member_o));
    if (!tc_Point_y_o) {
        db_error("tc_event_load: failed to declare object '::tc_event::Point::y'.");
        goto error;
    }

    /* Define ::tc_event::Point::y */
    if (!db_checkState(tc_Point_y_o, DB_DEFINED)) {
        tc_Point_y_o->type = db_resolve_ext(tc_Point_y_o, NULL, "::cortex::lang::uint32", FALSE, "element ::tc_event::Point::y.type");
        tc_Point_y_o->modifiers = 0x0;
        tc_Point_y_o->state = 0x6;
        tc_Point_y_o->weak = FALSE;
        tc_Point_y_o->id = 1;
        if (db_define(tc_Point_y_o)) {
            db_error("tc_event_load: failed to define object '::tc_event::Point::y'.");
            goto error;
        }
    }
    /* Define ::tc_event::Point */
    if (!db_checkState(tc_Point_o, DB_DEFINED)) {
        db_type(tc_Point_o)->parentType = NULL;
        db_type(tc_Point_o)->parentState = 0x0;
        db_interface(tc_Point_o)->base = NULL;
        db_struct(tc_Point_o)->baseAccess = 0x0;
        tc_Point_o->implements.length = 0;
        tc_Point_o->implements.buffer = NULL;
        if (db_define(tc_Point_o)) {
            db_error("tc_event_load: failed to define object '::tc_event::Point'.");
            goto error;
        }
    }
    /* Declare ::tc_event::parent */
    tc_parent_o = db_declare(tc_o, "parent", db_typedef(tc_Point_o));
    if (!tc_parent_o) {
        db_error("tc_event_load: failed to declare object '::tc_event::parent'.");
        goto error;
    }

    /* Define ::tc_event::parent */
    if (!db_checkState(tc_parent_o, DB_DEFINED)) {
        tc_parent_o->x = 0;
        tc_parent_o->y = 0;
        if (db_define(tc_parent_o)) {
            db_error("tc_event_load: failed to define object '::tc_event::parent'.");
            goto error;
        }
    }
    /* Define ::tc_event::construct_onBoth */
    if (!db_checkState(tc_construct_onBoth_o, DB_DEFINED)) {
        tc_construct_onBoth_o->observable = db_resolve_ext(tc_construct_onBoth_o, NULL, "::tc_event::parent", FALSE, "element ::tc_event::construct_onBoth.observable");
        tc_construct_onBoth_o->mask = 0xe2;
        tc_construct_onBoth_o->expression = NULL;
        tc_construct_onBoth_o->template = 0;
        tc_construct_onBoth_o->dispatcher = NULL;
        tc_construct_onBoth_o->me = NULL;
        
        /* Bind tc_construct_onBoth_o with C-function */
        db_function(tc_construct_onBoth_o)->kind = DB_PROCEDURE_CDECL;
        db_void tc_construct_onBoth(db_object *observable, db_object *source);
        db_function(tc_construct_onBoth_o)->impl = (db_word)tc_construct_onBoth;
        if (db_define(tc_construct_onBoth_o)) {
            db_error("tc_event_load: failed to define object '::tc_event::construct_onBoth'.");
            goto error;
        }
    }
    /* Define ::tc_event::construct_onChild */
    if (!db_checkState(tc_construct_onChild_o, DB_DEFINED)) {
        tc_construct_onChild_o->observable = db_resolve_ext(tc_construct_onChild_o, NULL, "::tc_event::parent", FALSE, "element ::tc_event::construct_onChild.observable");
        tc_construct_onChild_o->mask = 0xc2;
        tc_construct_onChild_o->expression = NULL;
        tc_construct_onChild_o->template = 0;
        tc_construct_onChild_o->dispatcher = NULL;
        tc_construct_onChild_o->me = NULL;
        
        /* Bind tc_construct_onChild_o with C-function */
        db_function(tc_construct_onChild_o)->kind = DB_PROCEDURE_CDECL;
        db_void tc_construct_onChild(db_object *observable, db_object *source);
        db_function(tc_construct_onChild_o)->impl = (db_word)tc_construct_onChild;
        if (db_define(tc_construct_onChild_o)) {
            db_error("tc_event_load: failed to define object '::tc_event::construct_onChild'.");
            goto error;
        }
    }
    /* Define ::tc_event::construct_onSelf */
    if (!db_checkState(tc_construct_onSelf_o, DB_DEFINED)) {
        tc_construct_onSelf_o->observable = db_resolve_ext(tc_construct_onSelf_o, NULL, "::tc_event::parent", FALSE, "element ::tc_event::construct_onSelf.observable");
        tc_construct_onSelf_o->mask = 0xa2;
        tc_construct_onSelf_o->expression = NULL;
        tc_construct_onSelf_o->template = 0;
        tc_construct_onSelf_o->dispatcher = NULL;
        tc_construct_onSelf_o->me = NULL;
        
        /* Bind tc_construct_onSelf_o with C-function */
        db_function(tc_construct_onSelf_o)->kind = DB_PROCEDURE_CDECL;
        db_void tc_construct_onSelf(tc_Point *observable, db_object *source);
        db_function(tc_construct_onSelf_o)->impl = (db_word)tc_construct_onSelf;
        if (db_define(tc_construct_onSelf_o)) {
            db_error("tc_event_load: failed to define object '::tc_event::construct_onSelf'.");
            goto error;
        }
    }
    /* Define ::tc_event::destruct_onBoth */
    if (!db_checkState(tc_destruct_onBoth_o, DB_DEFINED)) {
        tc_destruct_onBoth_o->observable = db_resolve_ext(tc_destruct_onBoth_o, NULL, "::tc_event::parent", FALSE, "element ::tc_event::destruct_onBoth.observable");
        tc_destruct_onBoth_o->mask = 0xe4;
        tc_destruct_onBoth_o->expression = NULL;
        tc_destruct_onBoth_o->template = 0;
        tc_destruct_onBoth_o->dispatcher = NULL;
        tc_destruct_onBoth_o->me = NULL;
        
        /* Bind tc_destruct_onBoth_o with C-function */
        db_function(tc_destruct_onBoth_o)->kind = DB_PROCEDURE_CDECL;
        db_void tc_destruct_onBoth(db_object *observable, db_object *source);
        db_function(tc_destruct_onBoth_o)->impl = (db_word)tc_destruct_onBoth;
        if (db_define(tc_destruct_onBoth_o)) {
            db_error("tc_event_load: failed to define object '::tc_event::destruct_onBoth'.");
            goto error;
        }
    }
    /* Define ::tc_event::destruct_onChild */
    if (!db_checkState(tc_destruct_onChild_o, DB_DEFINED)) {
        tc_destruct_onChild_o->observable = db_resolve_ext(tc_destruct_onChild_o, NULL, "::tc_event::parent", FALSE, "element ::tc_event::destruct_onChild.observable");
        tc_destruct_onChild_o->mask = 0xc4;
        tc_destruct_onChild_o->expression = NULL;
        tc_destruct_onChild_o->template = 0;
        tc_destruct_onChild_o->dispatcher = NULL;
        tc_destruct_onChild_o->me = NULL;
        
        /* Bind tc_destruct_onChild_o with C-function */
        db_function(tc_destruct_onChild_o)->kind = DB_PROCEDURE_CDECL;
        db_void tc_destruct_onChild(db_object *observable, db_object *source);
        db_function(tc_destruct_onChild_o)->impl = (db_word)tc_destruct_onChild;
        if (db_define(tc_destruct_onChild_o)) {
            db_error("tc_event_load: failed to define object '::tc_event::destruct_onChild'.");
            goto error;
        }
    }
    /* Define ::tc_event::destruct_onSelf */
    if (!db_checkState(tc_destruct_onSelf_o, DB_DEFINED)) {
        tc_destruct_onSelf_o->observable = db_resolve_ext(tc_destruct_onSelf_o, NULL, "::tc_event::parent", FALSE, "element ::tc_event::destruct_onSelf.observable");
        tc_destruct_onSelf_o->mask = 0xa4;
        tc_destruct_onSelf_o->expression = NULL;
        tc_destruct_onSelf_o->template = 0;
        tc_destruct_onSelf_o->dispatcher = NULL;
        tc_destruct_onSelf_o->me = NULL;
        
        /* Bind tc_destruct_onSelf_o with C-function */
        db_function(tc_destruct_onSelf_o)->kind = DB_PROCEDURE_CDECL;
        db_void tc_destruct_onSelf(tc_Point *observable, db_object *source);
        db_function(tc_destruct_onSelf_o)->impl = (db_word)tc_destruct_onSelf;
        if (db_define(tc_destruct_onSelf_o)) {
            db_error("tc_event_load: failed to define object '::tc_event::destruct_onSelf'.");
            goto error;
        }
    }
    /* Define ::tc_event::new_onBoth */
    if (!db_checkState(tc_new_onBoth_o, DB_DEFINED)) {
        tc_new_onBoth_o->observable = db_resolve_ext(tc_new_onBoth_o, NULL, "::tc_event::parent", FALSE, "element ::tc_event::new_onBoth.observable");
        tc_new_onBoth_o->mask = 0xe1;
        tc_new_onBoth_o->expression = NULL;
        tc_new_onBoth_o->template = 0;
        tc_new_onBoth_o->dispatcher = NULL;
        tc_new_onBoth_o->me = NULL;
        
        /* Bind tc_new_onBoth_o with C-function */
        db_function(tc_new_onBoth_o)->kind = DB_PROCEDURE_CDECL;
        db_void tc_new_onBoth(db_object *observable, db_object *source);
        db_function(tc_new_onBoth_o)->impl = (db_word)tc_new_onBoth;
        if (db_define(tc_new_onBoth_o)) {
            db_error("tc_event_load: failed to define object '::tc_event::new_onBoth'.");
            goto error;
        }
    }
    /* Define ::tc_event::new_onChild */
    if (!db_checkState(tc_new_onChild_o, DB_DEFINED)) {
        tc_new_onChild_o->observable = db_resolve_ext(tc_new_onChild_o, NULL, "::tc_event::parent", FALSE, "element ::tc_event::new_onChild.observable");
        tc_new_onChild_o->mask = 0xc1;
        tc_new_onChild_o->expression = NULL;
        tc_new_onChild_o->template = 0;
        tc_new_onChild_o->dispatcher = NULL;
        tc_new_onChild_o->me = NULL;
        
        /* Bind tc_new_onChild_o with C-function */
        db_function(tc_new_onChild_o)->kind = DB_PROCEDURE_CDECL;
        db_void tc_new_onChild(db_object *observable, db_object *source);
        db_function(tc_new_onChild_o)->impl = (db_word)tc_new_onChild;
        if (db_define(tc_new_onChild_o)) {
            db_error("tc_event_load: failed to define object '::tc_event::new_onChild'.");
            goto error;
        }
    }
    /* Define ::tc_event::new_onSelf */
    if (!db_checkState(tc_new_onSelf_o, DB_DEFINED)) {
        tc_new_onSelf_o->observable = db_resolve_ext(tc_new_onSelf_o, NULL, "::tc_event::parent", FALSE, "element ::tc_event::new_onSelf.observable");
        tc_new_onSelf_o->mask = 0xa1;
        tc_new_onSelf_o->expression = NULL;
        tc_new_onSelf_o->template = 0;
        tc_new_onSelf_o->dispatcher = NULL;
        tc_new_onSelf_o->me = NULL;
        
        /* Bind tc_new_onSelf_o with C-function */
        db_function(tc_new_onSelf_o)->kind = DB_PROCEDURE_CDECL;
        db_void tc_new_onSelf(db_object *observable, db_object *source);
        db_function(tc_new_onSelf_o)->impl = (db_word)tc_new_onSelf;
        if (db_define(tc_new_onSelf_o)) {
            db_error("tc_event_load: failed to define object '::tc_event::new_onSelf'.");
            goto error;
        }
    }
    /* Declare ::tc_event::update_onBoth */
    tc_update_onBoth_o = db_declare(tc_o, "update_onBoth", db_typedef(db_observer_o));
    if (!tc_update_onBoth_o) {
        db_error("tc_event_load: failed to declare object '::tc_event::update_onBoth'.");
        goto error;
    }

    /* Define ::tc_event::update_onBoth */
    if (!db_checkState(tc_update_onBoth_o, DB_DEFINED)) {
        tc_update_onBoth_o->observable = db_resolve_ext(tc_update_onBoth_o, NULL, "::tc_event::parent", FALSE, "element ::tc_event::update_onBoth.observable");
        tc_update_onBoth_o->mask = 0xf0;
        tc_update_onBoth_o->expression = NULL;
        tc_update_onBoth_o->template = 0;
        tc_update_onBoth_o->dispatcher = NULL;
        tc_update_onBoth_o->me = NULL;
        
        /* Bind tc_update_onBoth_o with C-function */
        db_function(tc_update_onBoth_o)->kind = DB_PROCEDURE_CDECL;
        db_void tc_update_onBoth(db_object *observable, db_object *source);
        db_function(tc_update_onBoth_o)->impl = (db_word)tc_update_onBoth;
        if (db_define(tc_update_onBoth_o)) {
            db_error("tc_event_load: failed to define object '::tc_event::update_onBoth'.");
            goto error;
        }
    }
    /* Declare ::tc_event::update_onChild */
    tc_update_onChild_o = db_declare(tc_o, "update_onChild", db_typedef(db_observer_o));
    if (!tc_update_onChild_o) {
        db_error("tc_event_load: failed to declare object '::tc_event::update_onChild'.");
        goto error;
    }

    /* Define ::tc_event::update_onChild */
    if (!db_checkState(tc_update_onChild_o, DB_DEFINED)) {
        tc_update_onChild_o->observable = db_resolve_ext(tc_update_onChild_o, NULL, "::tc_event::parent", FALSE, "element ::tc_event::update_onChild.observable");
        tc_update_onChild_o->mask = 0xd0;
        tc_update_onChild_o->expression = NULL;
        tc_update_onChild_o->template = 0;
        tc_update_onChild_o->dispatcher = NULL;
        tc_update_onChild_o->me = NULL;
        
        /* Bind tc_update_onChild_o with C-function */
        db_function(tc_update_onChild_o)->kind = DB_PROCEDURE_CDECL;
        db_void tc_update_onChild(db_object *observable, db_object *source);
        db_function(tc_update_onChild_o)->impl = (db_word)tc_update_onChild;
        if (db_define(tc_update_onChild_o)) {
            db_error("tc_event_load: failed to define object '::tc_event::update_onChild'.");
            goto error;
        }
    }
    /* Declare ::tc_event::update_onSelf */
    tc_update_onSelf_o = db_declare(tc_o, "update_onSelf", db_typedef(db_observer_o));
    if (!tc_update_onSelf_o) {
        db_error("tc_event_load: failed to declare object '::tc_event::update_onSelf'.");
        goto error;
    }

    /* Define ::tc_event::update_onSelf */
    if (!db_checkState(tc_update_onSelf_o, DB_DEFINED)) {
        tc_update_onSelf_o->observable = db_resolve_ext(tc_update_onSelf_o, NULL, "::tc_event::parent", FALSE, "element ::tc_event::update_onSelf.observable");
        tc_update_onSelf_o->mask = 0xb0;
        tc_update_onSelf_o->expression = NULL;
        tc_update_onSelf_o->template = 0;
        tc_update_onSelf_o->dispatcher = NULL;
        tc_update_onSelf_o->me = NULL;
        
        /* Bind tc_update_onSelf_o with C-function */
        db_function(tc_update_onSelf_o)->kind = DB_PROCEDURE_CDECL;
        db_void tc_update_onSelf(tc_Point *observable, db_object *source);
        db_function(tc_update_onSelf_o)->impl = (db_word)tc_update_onSelf;
        if (db_define(tc_update_onSelf_o)) {
            db_error("tc_event_load: failed to define object '::tc_event::update_onSelf'.");
            goto error;
        }
    }
    /* Declare ::tc_event::parent::child */
    tc_parent_child_o = db_declare(tc_parent_o, "child", db_typedef(tc_Point_o));
    if (!tc_parent_child_o) {
        db_error("tc_event_load: failed to declare object '::tc_event::parent::child'.");
        goto error;
    }

    /* Define ::tc_event::parent::child */
    if (!db_checkState(tc_parent_child_o, DB_DEFINED)) {
        tc_parent_child_o->x = 0;
        tc_parent_child_o->y = 0;
        if (db_define(tc_parent_child_o)) {
            db_error("tc_event_load: failed to define object '::tc_event::parent::child'.");
            goto error;
        }
    }
    /* Declare ::tc_event::update_onRootChilds */
    tc_update_onRootChilds_o = db_declare(tc_o, "update_onRootChilds", db_typedef(db_observer_o));
    if (!tc_update_onRootChilds_o) {
        db_error("tc_event_load: failed to declare object '::tc_event::update_onRootChilds'.");
        goto error;
    }

    /* Define ::tc_event::update_onRootChilds */
    if (!db_checkState(tc_update_onRootChilds_o, DB_DEFINED)) {
        tc_update_onRootChilds_o->observable = db_resolve_ext(tc_update_onRootChilds_o, NULL, "::", FALSE, "element ::tc_event::update_onRootChilds.observable");
        tc_update_onRootChilds_o->mask = 0xd0;
        tc_update_onRootChilds_o->expression = NULL;
        tc_update_onRootChilds_o->template = 0;
        tc_update_onRootChilds_o->dispatcher = NULL;
        tc_update_onRootChilds_o->me = NULL;
        
        /* Bind tc_update_onRootChilds_o with C-function */
        db_function(tc_update_onRootChilds_o)->kind = DB_PROCEDURE_CDECL;
        db_void tc_update_onRootChilds(db_object *observable, db_object *source);
        db_function(tc_update_onRootChilds_o)->impl = (db_word)tc_update_onRootChilds;
        if (db_define(tc_update_onRootChilds_o)) {
            db_error("tc_event_load: failed to define object '::tc_event::update_onRootChilds'.");
            goto error;
        }
    }
    /* Declare ::tc_event::update_onRootSelf */
    tc_update_onRootSelf_o = db_declare(tc_o, "update_onRootSelf", db_typedef(db_observer_o));
    if (!tc_update_onRootSelf_o) {
        db_error("tc_event_load: failed to declare object '::tc_event::update_onRootSelf'.");
        goto error;
    }

    /* Define ::tc_event::update_onRootSelf */
    if (!db_checkState(tc_update_onRootSelf_o, DB_DEFINED)) {
        tc_update_onRootSelf_o->observable = db_resolve_ext(tc_update_onRootSelf_o, NULL, "::", FALSE, "element ::tc_event::update_onRootSelf.observable");
        tc_update_onRootSelf_o->mask = 0xb0;
        tc_update_onRootSelf_o->expression = NULL;
        tc_update_onRootSelf_o->template = 0;
        tc_update_onRootSelf_o->dispatcher = NULL;
        tc_update_onRootSelf_o->me = NULL;
        
        /* Bind tc_update_onRootSelf_o with C-function */
        db_function(tc_update_onRootSelf_o)->kind = DB_PROCEDURE_CDECL;
        db_void tc_update_onRootSelf(db_object *observable, db_object *source);
        db_function(tc_update_onRootSelf_o)->impl = (db_word)tc_update_onRootSelf;
        if (db_define(tc_update_onRootSelf_o)) {
            db_error("tc_event_load: failed to define object '::tc_event::update_onRootSelf'.");
            goto error;
        }
    }
    /* Declare ::tc_event::value */
    tc_value_o = db_declare(tc_o, "value", db_typedef(db_typedef_o));
    if (!tc_value_o) {
        db_error("tc_event_load: failed to declare object '::tc_event::value'.");
        goto error;
    }

    /* Define ::tc_event::value */
    if (!db_checkState(tc_value_o, DB_DEFINED)) {
        tc_value_o->type = db_resolve_ext(tc_value_o, NULL, "::cortex::lang::uint32", FALSE, "element ::tc_event::value.type");
        if (db_define(tc_value_o)) {
            db_error("tc_event_load: failed to define object '::tc_event::value'.");
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
