/* tc_stringser__meta.c
 *
 *  Generated on Feb  5 2014
 *    Loads objects in database.
 *    This file contains generated code. Do not modify!
 */

#include "tc_stringser__type.h"

/* Variable definitions */
db_object tc_o;
db_typedef tc_arrayOfBool_o;
db_typedef tc_arrayOfChar_o;
db_typedef tc_arrayOfClassInherit_o;
db_typedef tc_arrayOfClassNested_o;
db_typedef tc_arrayOfClassPrimitives_o;
db_typedef tc_arrayOfColor_o;
db_typedef tc_arrayOfFloat_o;
db_typedef tc_arrayOfInt_o;
db_typedef tc_arrayOfMoveMode_o;
db_typedef tc_arrayOfString_o;
db_class tc_classCompositeCollection_o;
db_member tc_classCompositeCollection_a_o;
db_member tc_classCompositeCollection_b_o;
db_member tc_classCompositeCollection_c_o;
db_member tc_classCompositeCollection_d_o;
db_member tc_classCompositeCollection_e_o;
db_class tc_classInherit_o;
db_member tc_classInherit_a_o;
db_member tc_classInherit_b_o;
db_member tc_classInherit_c_o;
db_member tc_classInherit_d_o;
db_member tc_classInherit_e_o;
db_member tc_classInherit_f_o;
db_member tc_classInherit_g_o;
db_class tc_classNested_o;
db_member tc_classNested_a_o;
db_member tc_classNested_b_o;
db_member tc_classNested_c_o;
db_member tc_classNested_d_o;
db_member tc_classNested_e_o;
db_class tc_classPrimitives_o;
db_member tc_classPrimitives_a_o;
db_member tc_classPrimitives_b_o;
db_member tc_classPrimitives_c_o;
db_member tc_classPrimitives_d_o;
db_member tc_classPrimitives_e_o;
db_member tc_classPrimitives_f_o;
db_member tc_classPrimitives_g_o;
db_enum tc_color_o;
db_constant (*tc_color_BLUE_o);
db_constant (*tc_color_RED_o);
db_constant (*tc_color_YELLOW_o);
db_typedef tc_listOfBool_o;
db_typedef tc_listOfChar_o;
db_typedef tc_listOfClassInherit_o;
db_typedef tc_listOfClassNested_o;
db_typedef tc_listOfClassPrimitives_o;
db_typedef tc_listOfColor_o;
db_typedef tc_listOfFloat_o;
db_typedef tc_listOfInt_o;
db_typedef tc_listOfMoveMode_o;
db_typedef tc_listOfString_o;
db_bitmask tc_moveMode_o;
db_constant (*tc_moveMode_FLY_o);
db_constant (*tc_moveMode_SWIM_o);
db_constant (*tc_moveMode_WALK_o);
db_typedef tc_sequenceOfBool_o;
db_typedef tc_sequenceOfChar_o;
db_typedef tc_sequenceOfClassInherit_o;
db_typedef tc_sequenceOfClassNested_o;
db_typedef tc_sequenceOfClassPrimitives_o;
db_typedef tc_sequenceOfColor_o;
db_typedef tc_sequenceOfFloat_o;
db_typedef tc_sequenceOfInt_o;
db_typedef tc_sequenceOfMoveMode_o;
db_typedef tc_sequenceOfString_o;

/* Load objects in database */
int tc_stringser_load(void) {
    db_object _a_; /* Used for resolving anonymous objects */
    _a_ = NULL;

    /* Declare ::tc_stringser */
    tc_o = db_declare(root_o, "tc_stringser", db_typedef(db_object_o));
    if (!tc_o) {
        db_error("tc_stringser_load: failed to declare object '::tc_stringser'.");
        goto error;
    }

    /* Define ::tc_stringser */
    if (!db_checkState(tc_o, DB_DEFINED)) {
        if (db_define(tc_o)) {
            db_error("tc_stringser_load: failed to define object '::tc_stringser'.");
            goto error;
        }
    }
    /* Declare ::tc_stringser::arrayOfBool */
    tc_arrayOfBool_o = db_declare(tc_o, "arrayOfBool", db_typedef(db_typedef_o));
    if (!tc_arrayOfBool_o) {
        db_error("tc_stringser_load: failed to declare object '::tc_stringser::arrayOfBool'.");
        goto error;
    }

    /* Declare ::tc_stringser::arrayOfChar */
    tc_arrayOfChar_o = db_declare(tc_o, "arrayOfChar", db_typedef(db_typedef_o));
    if (!tc_arrayOfChar_o) {
        db_error("tc_stringser_load: failed to declare object '::tc_stringser::arrayOfChar'.");
        goto error;
    }

    /* Declare ::tc_stringser::arrayOfClassInherit */
    tc_arrayOfClassInherit_o = db_declare(tc_o, "arrayOfClassInherit", db_typedef(db_typedef_o));
    if (!tc_arrayOfClassInherit_o) {
        db_error("tc_stringser_load: failed to declare object '::tc_stringser::arrayOfClassInherit'.");
        goto error;
    }

    /* Declare ::tc_stringser::arrayOfClassNested */
    tc_arrayOfClassNested_o = db_declare(tc_o, "arrayOfClassNested", db_typedef(db_typedef_o));
    if (!tc_arrayOfClassNested_o) {
        db_error("tc_stringser_load: failed to declare object '::tc_stringser::arrayOfClassNested'.");
        goto error;
    }

    /* Declare ::tc_stringser::arrayOfClassPrimitives */
    tc_arrayOfClassPrimitives_o = db_declare(tc_o, "arrayOfClassPrimitives", db_typedef(db_typedef_o));
    if (!tc_arrayOfClassPrimitives_o) {
        db_error("tc_stringser_load: failed to declare object '::tc_stringser::arrayOfClassPrimitives'.");
        goto error;
    }

    /* Declare ::tc_stringser::arrayOfColor */
    tc_arrayOfColor_o = db_declare(tc_o, "arrayOfColor", db_typedef(db_typedef_o));
    if (!tc_arrayOfColor_o) {
        db_error("tc_stringser_load: failed to declare object '::tc_stringser::arrayOfColor'.");
        goto error;
    }

    /* Declare ::tc_stringser::arrayOfFloat */
    tc_arrayOfFloat_o = db_declare(tc_o, "arrayOfFloat", db_typedef(db_typedef_o));
    if (!tc_arrayOfFloat_o) {
        db_error("tc_stringser_load: failed to declare object '::tc_stringser::arrayOfFloat'.");
        goto error;
    }

    /* Declare ::tc_stringser::arrayOfInt */
    tc_arrayOfInt_o = db_declare(tc_o, "arrayOfInt", db_typedef(db_typedef_o));
    if (!tc_arrayOfInt_o) {
        db_error("tc_stringser_load: failed to declare object '::tc_stringser::arrayOfInt'.");
        goto error;
    }

    /* Declare ::tc_stringser::arrayOfMoveMode */
    tc_arrayOfMoveMode_o = db_declare(tc_o, "arrayOfMoveMode", db_typedef(db_typedef_o));
    if (!tc_arrayOfMoveMode_o) {
        db_error("tc_stringser_load: failed to declare object '::tc_stringser::arrayOfMoveMode'.");
        goto error;
    }

    /* Declare ::tc_stringser::arrayOfString */
    tc_arrayOfString_o = db_declare(tc_o, "arrayOfString", db_typedef(db_typedef_o));
    if (!tc_arrayOfString_o) {
        db_error("tc_stringser_load: failed to declare object '::tc_stringser::arrayOfString'.");
        goto error;
    }

    /* Declare ::tc_stringser::classCompositeCollection */
    tc_classCompositeCollection_o = db_declare(tc_o, "classCompositeCollection", db_typedef(db_class_o));
    if (!tc_classCompositeCollection_o) {
        db_error("tc_stringser_load: failed to declare object '::tc_stringser::classCompositeCollection'.");
        goto error;
    }

    /* Declare ::tc_stringser::classCompositeCollection::a */
    tc_classCompositeCollection_a_o = db_declare(tc_classCompositeCollection_o, "a", db_typedef(db_member_o));
    if (!tc_classCompositeCollection_a_o) {
        db_error("tc_stringser_load: failed to declare object '::tc_stringser::classCompositeCollection::a'.");
        goto error;
    }

    /* Declare ::tc_stringser::classCompositeCollection::b */
    tc_classCompositeCollection_b_o = db_declare(tc_classCompositeCollection_o, "b", db_typedef(db_member_o));
    if (!tc_classCompositeCollection_b_o) {
        db_error("tc_stringser_load: failed to declare object '::tc_stringser::classCompositeCollection::b'.");
        goto error;
    }

    /* Declare ::tc_stringser::classCompositeCollection::c */
    tc_classCompositeCollection_c_o = db_declare(tc_classCompositeCollection_o, "c", db_typedef(db_member_o));
    if (!tc_classCompositeCollection_c_o) {
        db_error("tc_stringser_load: failed to declare object '::tc_stringser::classCompositeCollection::c'.");
        goto error;
    }

    /* Declare ::tc_stringser::classCompositeCollection::d */
    tc_classCompositeCollection_d_o = db_declare(tc_classCompositeCollection_o, "d", db_typedef(db_member_o));
    if (!tc_classCompositeCollection_d_o) {
        db_error("tc_stringser_load: failed to declare object '::tc_stringser::classCompositeCollection::d'.");
        goto error;
    }

    /* Declare ::tc_stringser::classCompositeCollection::e */
    tc_classCompositeCollection_e_o = db_declare(tc_classCompositeCollection_o, "e", db_typedef(db_member_o));
    if (!tc_classCompositeCollection_e_o) {
        db_error("tc_stringser_load: failed to declare object '::tc_stringser::classCompositeCollection::e'.");
        goto error;
    }

    /* Declare ::tc_stringser::classInherit */
    tc_classInherit_o = db_declare(tc_o, "classInherit", db_typedef(db_class_o));
    if (!tc_classInherit_o) {
        db_error("tc_stringser_load: failed to declare object '::tc_stringser::classInherit'.");
        goto error;
    }

    /* Declare ::tc_stringser::classInherit::a */
    tc_classInherit_a_o = db_declare(tc_classInherit_o, "a", db_typedef(db_member_o));
    if (!tc_classInherit_a_o) {
        db_error("tc_stringser_load: failed to declare object '::tc_stringser::classInherit::a'.");
        goto error;
    }

    /* Define ::tc_stringser::classInherit::a */
    if (!db_checkState(tc_classInherit_a_o, DB_DEFINED)) {
        tc_classInherit_a_o->type = db_resolve_ext(tc_classInherit_a_o, NULL, "::cortex::lang::bool", FALSE, "element ::tc_stringser::classInherit::a.type");
        tc_classInherit_a_o->modifiers = 0x0;
        tc_classInherit_a_o->state = 0x6;
        tc_classInherit_a_o->weak = FALSE;
        tc_classInherit_a_o->id = 0;
        if (db_define(tc_classInherit_a_o)) {
            db_error("tc_stringser_load: failed to define object '::tc_stringser::classInherit::a'.");
            goto error;
        }
    }
    /* Declare ::tc_stringser::classInherit::b */
    tc_classInherit_b_o = db_declare(tc_classInherit_o, "b", db_typedef(db_member_o));
    if (!tc_classInherit_b_o) {
        db_error("tc_stringser_load: failed to declare object '::tc_stringser::classInherit::b'.");
        goto error;
    }

    /* Define ::tc_stringser::classInherit::b */
    if (!db_checkState(tc_classInherit_b_o, DB_DEFINED)) {
        tc_classInherit_b_o->type = db_resolve_ext(tc_classInherit_b_o, NULL, "::cortex::lang::char", FALSE, "element ::tc_stringser::classInherit::b.type");
        tc_classInherit_b_o->modifiers = 0x0;
        tc_classInherit_b_o->state = 0x6;
        tc_classInherit_b_o->weak = FALSE;
        tc_classInherit_b_o->id = 1;
        if (db_define(tc_classInherit_b_o)) {
            db_error("tc_stringser_load: failed to define object '::tc_stringser::classInherit::b'.");
            goto error;
        }
    }
    /* Declare ::tc_stringser::classInherit::c */
    tc_classInherit_c_o = db_declare(tc_classInherit_o, "c", db_typedef(db_member_o));
    if (!tc_classInherit_c_o) {
        db_error("tc_stringser_load: failed to declare object '::tc_stringser::classInherit::c'.");
        goto error;
    }

    /* Define ::tc_stringser::classInherit::c */
    if (!db_checkState(tc_classInherit_c_o, DB_DEFINED)) {
        tc_classInherit_c_o->type = db_resolve_ext(tc_classInherit_c_o, NULL, "::cortex::lang::int32", FALSE, "element ::tc_stringser::classInherit::c.type");
        tc_classInherit_c_o->modifiers = 0x0;
        tc_classInherit_c_o->state = 0x6;
        tc_classInherit_c_o->weak = FALSE;
        tc_classInherit_c_o->id = 2;
        if (db_define(tc_classInherit_c_o)) {
            db_error("tc_stringser_load: failed to define object '::tc_stringser::classInherit::c'.");
            goto error;
        }
    }
    /* Declare ::tc_stringser::classInherit::d */
    tc_classInherit_d_o = db_declare(tc_classInherit_o, "d", db_typedef(db_member_o));
    if (!tc_classInherit_d_o) {
        db_error("tc_stringser_load: failed to declare object '::tc_stringser::classInherit::d'.");
        goto error;
    }

    /* Define ::tc_stringser::classInherit::d */
    if (!db_checkState(tc_classInherit_d_o, DB_DEFINED)) {
        tc_classInherit_d_o->type = db_resolve_ext(tc_classInherit_d_o, NULL, "::cortex::lang::float32", FALSE, "element ::tc_stringser::classInherit::d.type");
        tc_classInherit_d_o->modifiers = 0x0;
        tc_classInherit_d_o->state = 0x6;
        tc_classInherit_d_o->weak = FALSE;
        tc_classInherit_d_o->id = 3;
        if (db_define(tc_classInherit_d_o)) {
            db_error("tc_stringser_load: failed to define object '::tc_stringser::classInherit::d'.");
            goto error;
        }
    }
    /* Declare ::tc_stringser::classInherit::e */
    tc_classInherit_e_o = db_declare(tc_classInherit_o, "e", db_typedef(db_member_o));
    if (!tc_classInherit_e_o) {
        db_error("tc_stringser_load: failed to declare object '::tc_stringser::classInherit::e'.");
        goto error;
    }

    /* Define ::tc_stringser::classInherit::e */
    if (!db_checkState(tc_classInherit_e_o, DB_DEFINED)) {
        tc_classInherit_e_o->type = db_resolve_ext(tc_classInherit_e_o, NULL, "::cortex::lang::string", FALSE, "element ::tc_stringser::classInherit::e.type");
        tc_classInherit_e_o->modifiers = 0x0;
        tc_classInherit_e_o->state = 0x6;
        tc_classInherit_e_o->weak = FALSE;
        tc_classInherit_e_o->id = 4;
        if (db_define(tc_classInherit_e_o)) {
            db_error("tc_stringser_load: failed to define object '::tc_stringser::classInherit::e'.");
            goto error;
        }
    }
    /* Declare ::tc_stringser::classInherit::f */
    tc_classInherit_f_o = db_declare(tc_classInherit_o, "f", db_typedef(db_member_o));
    if (!tc_classInherit_f_o) {
        db_error("tc_stringser_load: failed to declare object '::tc_stringser::classInherit::f'.");
        goto error;
    }

    /* Declare ::tc_stringser::classInherit::g */
    tc_classInherit_g_o = db_declare(tc_classInherit_o, "g", db_typedef(db_member_o));
    if (!tc_classInherit_g_o) {
        db_error("tc_stringser_load: failed to declare object '::tc_stringser::classInherit::g'.");
        goto error;
    }

    /* Declare ::tc_stringser::listOfClassInherit */
    tc_listOfClassInherit_o = db_declare(tc_o, "listOfClassInherit", db_typedef(db_typedef_o));
    if (!tc_listOfClassInherit_o) {
        db_error("tc_stringser_load: failed to declare object '::tc_stringser::listOfClassInherit'.");
        goto error;
    }

    /* Define ::tc_stringser::listOfClassInherit */
    if (!db_checkState(tc_listOfClassInherit_o, DB_DEFINED)) {
        tc_listOfClassInherit_o->type = db_resolve_ext(tc_listOfClassInherit_o, NULL, "::cortex::lang::list{::tc_stringser::classInherit,3}", FALSE, "element ::tc_stringser::listOfClassInherit.type");
        if (db_define(tc_listOfClassInherit_o)) {
            db_error("tc_stringser_load: failed to define object '::tc_stringser::listOfClassInherit'.");
            goto error;
        }
    }
    /* Define ::tc_stringser::classCompositeCollection::e */
    if (!db_checkState(tc_classCompositeCollection_e_o, DB_DEFINED)) {
        tc_classCompositeCollection_e_o->type = db_resolve_ext(tc_classCompositeCollection_e_o, NULL, "::tc_stringser::listOfClassInherit", FALSE, "element ::tc_stringser::classCompositeCollection::e.type");
        tc_classCompositeCollection_e_o->modifiers = 0x0;
        tc_classCompositeCollection_e_o->state = 0x6;
        tc_classCompositeCollection_e_o->weak = FALSE;
        tc_classCompositeCollection_e_o->id = 4;
        if (db_define(tc_classCompositeCollection_e_o)) {
            db_error("tc_stringser_load: failed to define object '::tc_stringser::classCompositeCollection::e'.");
            goto error;
        }
    }
    /* Declare ::tc_stringser::sequenceOfClassInherit */
    tc_sequenceOfClassInherit_o = db_declare(tc_o, "sequenceOfClassInherit", db_typedef(db_typedef_o));
    if (!tc_sequenceOfClassInherit_o) {
        db_error("tc_stringser_load: failed to declare object '::tc_stringser::sequenceOfClassInherit'.");
        goto error;
    }

    /* Define ::tc_stringser::sequenceOfClassInherit */
    if (!db_checkState(tc_sequenceOfClassInherit_o, DB_DEFINED)) {
        tc_sequenceOfClassInherit_o->type = db_resolve_ext(tc_sequenceOfClassInherit_o, NULL, "::cortex::lang::sequence{::tc_stringser::classInherit,3}", FALSE, "element ::tc_stringser::sequenceOfClassInherit.type");
        if (db_define(tc_sequenceOfClassInherit_o)) {
            db_error("tc_stringser_load: failed to define object '::tc_stringser::sequenceOfClassInherit'.");
            goto error;
        }
    }
    /* Define ::tc_stringser::classCompositeCollection::c */
    if (!db_checkState(tc_classCompositeCollection_c_o, DB_DEFINED)) {
        tc_classCompositeCollection_c_o->type = db_resolve_ext(tc_classCompositeCollection_c_o, NULL, "::tc_stringser::sequenceOfClassInherit", FALSE, "element ::tc_stringser::classCompositeCollection::c.type");
        tc_classCompositeCollection_c_o->modifiers = 0x0;
        tc_classCompositeCollection_c_o->state = 0x6;
        tc_classCompositeCollection_c_o->weak = FALSE;
        tc_classCompositeCollection_c_o->id = 2;
        if (db_define(tc_classCompositeCollection_c_o)) {
            db_error("tc_stringser_load: failed to define object '::tc_stringser::classCompositeCollection::c'.");
            goto error;
        }
    }
    /* Declare ::tc_stringser::classNested */
    tc_classNested_o = db_declare(tc_o, "classNested", db_typedef(db_class_o));
    if (!tc_classNested_o) {
        db_error("tc_stringser_load: failed to declare object '::tc_stringser::classNested'.");
        goto error;
    }

    /* Declare ::tc_stringser::classNested::a */
    tc_classNested_a_o = db_declare(tc_classNested_o, "a", db_typedef(db_member_o));
    if (!tc_classNested_a_o) {
        db_error("tc_stringser_load: failed to declare object '::tc_stringser::classNested::a'.");
        goto error;
    }

    /* Declare ::tc_stringser::classNested::b */
    tc_classNested_b_o = db_declare(tc_classNested_o, "b", db_typedef(db_member_o));
    if (!tc_classNested_b_o) {
        db_error("tc_stringser_load: failed to declare object '::tc_stringser::classNested::b'.");
        goto error;
    }

    /* Declare ::tc_stringser::classNested::c */
    tc_classNested_c_o = db_declare(tc_classNested_o, "c", db_typedef(db_member_o));
    if (!tc_classNested_c_o) {
        db_error("tc_stringser_load: failed to declare object '::tc_stringser::classNested::c'.");
        goto error;
    }

    /* Declare ::tc_stringser::classNested::d */
    tc_classNested_d_o = db_declare(tc_classNested_o, "d", db_typedef(db_member_o));
    if (!tc_classNested_d_o) {
        db_error("tc_stringser_load: failed to declare object '::tc_stringser::classNested::d'.");
        goto error;
    }

    /* Declare ::tc_stringser::classNested::e */
    tc_classNested_e_o = db_declare(tc_classNested_o, "e", db_typedef(db_member_o));
    if (!tc_classNested_e_o) {
        db_error("tc_stringser_load: failed to declare object '::tc_stringser::classNested::e'.");
        goto error;
    }

    /* Declare ::tc_stringser::listOfClassNested */
    tc_listOfClassNested_o = db_declare(tc_o, "listOfClassNested", db_typedef(db_typedef_o));
    if (!tc_listOfClassNested_o) {
        db_error("tc_stringser_load: failed to declare object '::tc_stringser::listOfClassNested'.");
        goto error;
    }

    /* Define ::tc_stringser::listOfClassNested */
    if (!db_checkState(tc_listOfClassNested_o, DB_DEFINED)) {
        tc_listOfClassNested_o->type = db_resolve_ext(tc_listOfClassNested_o, NULL, "::cortex::lang::list{::tc_stringser::classNested,3}", FALSE, "element ::tc_stringser::listOfClassNested.type");
        if (db_define(tc_listOfClassNested_o)) {
            db_error("tc_stringser_load: failed to define object '::tc_stringser::listOfClassNested'.");
            goto error;
        }
    }
    /* Define ::tc_stringser::classCompositeCollection::d */
    if (!db_checkState(tc_classCompositeCollection_d_o, DB_DEFINED)) {
        tc_classCompositeCollection_d_o->type = db_resolve_ext(tc_classCompositeCollection_d_o, NULL, "::tc_stringser::listOfClassNested", FALSE, "element ::tc_stringser::classCompositeCollection::d.type");
        tc_classCompositeCollection_d_o->modifiers = 0x0;
        tc_classCompositeCollection_d_o->state = 0x6;
        tc_classCompositeCollection_d_o->weak = FALSE;
        tc_classCompositeCollection_d_o->id = 3;
        if (db_define(tc_classCompositeCollection_d_o)) {
            db_error("tc_stringser_load: failed to define object '::tc_stringser::classCompositeCollection::d'.");
            goto error;
        }
    }
    /* Declare ::tc_stringser::sequenceOfClassNested */
    tc_sequenceOfClassNested_o = db_declare(tc_o, "sequenceOfClassNested", db_typedef(db_typedef_o));
    if (!tc_sequenceOfClassNested_o) {
        db_error("tc_stringser_load: failed to declare object '::tc_stringser::sequenceOfClassNested'.");
        goto error;
    }

    /* Define ::tc_stringser::sequenceOfClassNested */
    if (!db_checkState(tc_sequenceOfClassNested_o, DB_DEFINED)) {
        tc_sequenceOfClassNested_o->type = db_resolve_ext(tc_sequenceOfClassNested_o, NULL, "::cortex::lang::sequence{::tc_stringser::classNested,3}", FALSE, "element ::tc_stringser::sequenceOfClassNested.type");
        if (db_define(tc_sequenceOfClassNested_o)) {
            db_error("tc_stringser_load: failed to define object '::tc_stringser::sequenceOfClassNested'.");
            goto error;
        }
    }
    /* Declare ::tc_stringser::classPrimitives */
    tc_classPrimitives_o = db_declare(tc_o, "classPrimitives", db_typedef(db_class_o));
    if (!tc_classPrimitives_o) {
        db_error("tc_stringser_load: failed to declare object '::tc_stringser::classPrimitives'.");
        goto error;
    }

    /* Declare ::tc_stringser::classPrimitives::a */
    tc_classPrimitives_a_o = db_declare(tc_classPrimitives_o, "a", db_typedef(db_member_o));
    if (!tc_classPrimitives_a_o) {
        db_error("tc_stringser_load: failed to declare object '::tc_stringser::classPrimitives::a'.");
        goto error;
    }

    /* Define ::tc_stringser::classPrimitives::a */
    if (!db_checkState(tc_classPrimitives_a_o, DB_DEFINED)) {
        tc_classPrimitives_a_o->type = db_resolve_ext(tc_classPrimitives_a_o, NULL, "::cortex::lang::bool", FALSE, "element ::tc_stringser::classPrimitives::a.type");
        tc_classPrimitives_a_o->modifiers = 0x0;
        tc_classPrimitives_a_o->state = 0x6;
        tc_classPrimitives_a_o->weak = FALSE;
        tc_classPrimitives_a_o->id = 0;
        if (db_define(tc_classPrimitives_a_o)) {
            db_error("tc_stringser_load: failed to define object '::tc_stringser::classPrimitives::a'.");
            goto error;
        }
    }
    /* Declare ::tc_stringser::classPrimitives::b */
    tc_classPrimitives_b_o = db_declare(tc_classPrimitives_o, "b", db_typedef(db_member_o));
    if (!tc_classPrimitives_b_o) {
        db_error("tc_stringser_load: failed to declare object '::tc_stringser::classPrimitives::b'.");
        goto error;
    }

    /* Define ::tc_stringser::classPrimitives::b */
    if (!db_checkState(tc_classPrimitives_b_o, DB_DEFINED)) {
        tc_classPrimitives_b_o->type = db_resolve_ext(tc_classPrimitives_b_o, NULL, "::cortex::lang::char", FALSE, "element ::tc_stringser::classPrimitives::b.type");
        tc_classPrimitives_b_o->modifiers = 0x0;
        tc_classPrimitives_b_o->state = 0x6;
        tc_classPrimitives_b_o->weak = FALSE;
        tc_classPrimitives_b_o->id = 1;
        if (db_define(tc_classPrimitives_b_o)) {
            db_error("tc_stringser_load: failed to define object '::tc_stringser::classPrimitives::b'.");
            goto error;
        }
    }
    /* Declare ::tc_stringser::classPrimitives::c */
    tc_classPrimitives_c_o = db_declare(tc_classPrimitives_o, "c", db_typedef(db_member_o));
    if (!tc_classPrimitives_c_o) {
        db_error("tc_stringser_load: failed to declare object '::tc_stringser::classPrimitives::c'.");
        goto error;
    }

    /* Define ::tc_stringser::classPrimitives::c */
    if (!db_checkState(tc_classPrimitives_c_o, DB_DEFINED)) {
        tc_classPrimitives_c_o->type = db_resolve_ext(tc_classPrimitives_c_o, NULL, "::cortex::lang::int32", FALSE, "element ::tc_stringser::classPrimitives::c.type");
        tc_classPrimitives_c_o->modifiers = 0x0;
        tc_classPrimitives_c_o->state = 0x6;
        tc_classPrimitives_c_o->weak = FALSE;
        tc_classPrimitives_c_o->id = 2;
        if (db_define(tc_classPrimitives_c_o)) {
            db_error("tc_stringser_load: failed to define object '::tc_stringser::classPrimitives::c'.");
            goto error;
        }
    }
    /* Declare ::tc_stringser::classPrimitives::d */
    tc_classPrimitives_d_o = db_declare(tc_classPrimitives_o, "d", db_typedef(db_member_o));
    if (!tc_classPrimitives_d_o) {
        db_error("tc_stringser_load: failed to declare object '::tc_stringser::classPrimitives::d'.");
        goto error;
    }

    /* Define ::tc_stringser::classPrimitives::d */
    if (!db_checkState(tc_classPrimitives_d_o, DB_DEFINED)) {
        tc_classPrimitives_d_o->type = db_resolve_ext(tc_classPrimitives_d_o, NULL, "::cortex::lang::float32", FALSE, "element ::tc_stringser::classPrimitives::d.type");
        tc_classPrimitives_d_o->modifiers = 0x0;
        tc_classPrimitives_d_o->state = 0x6;
        tc_classPrimitives_d_o->weak = FALSE;
        tc_classPrimitives_d_o->id = 3;
        if (db_define(tc_classPrimitives_d_o)) {
            db_error("tc_stringser_load: failed to define object '::tc_stringser::classPrimitives::d'.");
            goto error;
        }
    }
    /* Declare ::tc_stringser::classPrimitives::e */
    tc_classPrimitives_e_o = db_declare(tc_classPrimitives_o, "e", db_typedef(db_member_o));
    if (!tc_classPrimitives_e_o) {
        db_error("tc_stringser_load: failed to declare object '::tc_stringser::classPrimitives::e'.");
        goto error;
    }

    /* Define ::tc_stringser::classPrimitives::e */
    if (!db_checkState(tc_classPrimitives_e_o, DB_DEFINED)) {
        tc_classPrimitives_e_o->type = db_resolve_ext(tc_classPrimitives_e_o, NULL, "::cortex::lang::string", FALSE, "element ::tc_stringser::classPrimitives::e.type");
        tc_classPrimitives_e_o->modifiers = 0x0;
        tc_classPrimitives_e_o->state = 0x6;
        tc_classPrimitives_e_o->weak = FALSE;
        tc_classPrimitives_e_o->id = 4;
        if (db_define(tc_classPrimitives_e_o)) {
            db_error("tc_stringser_load: failed to define object '::tc_stringser::classPrimitives::e'.");
            goto error;
        }
    }
    /* Declare ::tc_stringser::classPrimitives::f */
    tc_classPrimitives_f_o = db_declare(tc_classPrimitives_o, "f", db_typedef(db_member_o));
    if (!tc_classPrimitives_f_o) {
        db_error("tc_stringser_load: failed to declare object '::tc_stringser::classPrimitives::f'.");
        goto error;
    }

    /* Declare ::tc_stringser::classPrimitives::g */
    tc_classPrimitives_g_o = db_declare(tc_classPrimitives_o, "g", db_typedef(db_member_o));
    if (!tc_classPrimitives_g_o) {
        db_error("tc_stringser_load: failed to declare object '::tc_stringser::classPrimitives::g'.");
        goto error;
    }

    /* Declare ::tc_stringser::listOfClassPrimitives */
    tc_listOfClassPrimitives_o = db_declare(tc_o, "listOfClassPrimitives", db_typedef(db_typedef_o));
    if (!tc_listOfClassPrimitives_o) {
        db_error("tc_stringser_load: failed to declare object '::tc_stringser::listOfClassPrimitives'.");
        goto error;
    }

    /* Define ::tc_stringser::listOfClassPrimitives */
    if (!db_checkState(tc_listOfClassPrimitives_o, DB_DEFINED)) {
        tc_listOfClassPrimitives_o->type = db_resolve_ext(tc_listOfClassPrimitives_o, NULL, "::cortex::lang::list{::tc_stringser::classPrimitives,3}", FALSE, "element ::tc_stringser::listOfClassPrimitives.type");
        if (db_define(tc_listOfClassPrimitives_o)) {
            db_error("tc_stringser_load: failed to define object '::tc_stringser::listOfClassPrimitives'.");
            goto error;
        }
    }
    /* Declare ::tc_stringser::sequenceOfClassPrimitives */
    tc_sequenceOfClassPrimitives_o = db_declare(tc_o, "sequenceOfClassPrimitives", db_typedef(db_typedef_o));
    if (!tc_sequenceOfClassPrimitives_o) {
        db_error("tc_stringser_load: failed to declare object '::tc_stringser::sequenceOfClassPrimitives'.");
        goto error;
    }

    /* Define ::tc_stringser::sequenceOfClassPrimitives */
    if (!db_checkState(tc_sequenceOfClassPrimitives_o, DB_DEFINED)) {
        tc_sequenceOfClassPrimitives_o->type = db_resolve_ext(tc_sequenceOfClassPrimitives_o, NULL, "::cortex::lang::sequence{::tc_stringser::classPrimitives,3}", FALSE, "element ::tc_stringser::sequenceOfClassPrimitives.type");
        if (db_define(tc_sequenceOfClassPrimitives_o)) {
            db_error("tc_stringser_load: failed to define object '::tc_stringser::sequenceOfClassPrimitives'.");
            goto error;
        }
    }
    /* Declare ::tc_stringser::color */
    tc_color_o = db_declare(tc_o, "color", db_typedef(db_enum_o));
    if (!tc_color_o) {
        db_error("tc_stringser_load: failed to declare object '::tc_stringser::color'.");
        goto error;
    }

    /* Declare ::tc_stringser::color::BLUE */
    tc_color_BLUE_o = db_declare(tc_color_o, "BLUE", db_typedef(db_constant_o));
    if (!tc_color_BLUE_o) {
        db_error("tc_stringser_load: failed to declare object '::tc_stringser::color::BLUE'.");
        goto error;
    }

    /* Define ::tc_stringser::color::BLUE */
    if (!db_checkState(tc_color_BLUE_o, DB_DEFINED)) {
        (*tc_color_BLUE_o) = 2;
        if (db_define(tc_color_BLUE_o)) {
            db_error("tc_stringser_load: failed to define object '::tc_stringser::color::BLUE'.");
            goto error;
        }
    }
    /* Declare ::tc_stringser::color::RED */
    tc_color_RED_o = db_declare(tc_color_o, "RED", db_typedef(db_constant_o));
    if (!tc_color_RED_o) {
        db_error("tc_stringser_load: failed to declare object '::tc_stringser::color::RED'.");
        goto error;
    }

    /* Define ::tc_stringser::color::RED */
    if (!db_checkState(tc_color_RED_o, DB_DEFINED)) {
        (*tc_color_RED_o) = 0;
        if (db_define(tc_color_RED_o)) {
            db_error("tc_stringser_load: failed to define object '::tc_stringser::color::RED'.");
            goto error;
        }
    }
    /* Declare ::tc_stringser::color::YELLOW */
    tc_color_YELLOW_o = db_declare(tc_color_o, "YELLOW", db_typedef(db_constant_o));
    if (!tc_color_YELLOW_o) {
        db_error("tc_stringser_load: failed to declare object '::tc_stringser::color::YELLOW'.");
        goto error;
    }

    /* Define ::tc_stringser::color::YELLOW */
    if (!db_checkState(tc_color_YELLOW_o, DB_DEFINED)) {
        (*tc_color_YELLOW_o) = 1;
        if (db_define(tc_color_YELLOW_o)) {
            db_error("tc_stringser_load: failed to define object '::tc_stringser::color::YELLOW'.");
            goto error;
        }
    }
    /* Define ::tc_stringser::color */
    if (!db_checkState(tc_color_o, DB_DEFINED)) {
        if (db_define(tc_color_o)) {
            db_error("tc_stringser_load: failed to define object '::tc_stringser::color'.");
            goto error;
        }
    }
    /* Define ::tc_stringser::classInherit::f */
    if (!db_checkState(tc_classInherit_f_o, DB_DEFINED)) {
        tc_classInherit_f_o->type = db_resolve_ext(tc_classInherit_f_o, NULL, "::tc_stringser::color", FALSE, "element ::tc_stringser::classInherit::f.type");
        tc_classInherit_f_o->modifiers = 0x0;
        tc_classInherit_f_o->state = 0x6;
        tc_classInherit_f_o->weak = FALSE;
        tc_classInherit_f_o->id = 5;
        if (db_define(tc_classInherit_f_o)) {
            db_error("tc_stringser_load: failed to define object '::tc_stringser::classInherit::f'.");
            goto error;
        }
    }
    /* Define ::tc_stringser::classPrimitives::f */
    if (!db_checkState(tc_classPrimitives_f_o, DB_DEFINED)) {
        tc_classPrimitives_f_o->type = db_resolve_ext(tc_classPrimitives_f_o, NULL, "::tc_stringser::color", FALSE, "element ::tc_stringser::classPrimitives::f.type");
        tc_classPrimitives_f_o->modifiers = 0x0;
        tc_classPrimitives_f_o->state = 0x6;
        tc_classPrimitives_f_o->weak = FALSE;
        tc_classPrimitives_f_o->id = 5;
        if (db_define(tc_classPrimitives_f_o)) {
            db_error("tc_stringser_load: failed to define object '::tc_stringser::classPrimitives::f'.");
            goto error;
        }
    }
    /* Define ::tc_stringser::arrayOfColor */
    if (!db_checkState(tc_arrayOfColor_o, DB_DEFINED)) {
        tc_arrayOfColor_o->type = db_resolve_ext(tc_arrayOfColor_o, NULL, "::cortex::lang::array{::tc_stringser::color,3,::tc_stringser::color}", FALSE, "element ::tc_stringser::arrayOfColor.type");
        if (db_define(tc_arrayOfColor_o)) {
            db_error("tc_stringser_load: failed to define object '::tc_stringser::arrayOfColor'.");
            goto error;
        }
    }
    /* Declare ::tc_stringser::listOfColor */
    tc_listOfColor_o = db_declare(tc_o, "listOfColor", db_typedef(db_typedef_o));
    if (!tc_listOfColor_o) {
        db_error("tc_stringser_load: failed to declare object '::tc_stringser::listOfColor'.");
        goto error;
    }

    /* Define ::tc_stringser::listOfColor */
    if (!db_checkState(tc_listOfColor_o, DB_DEFINED)) {
        tc_listOfColor_o->type = db_resolve_ext(tc_listOfColor_o, NULL, "::cortex::lang::list{::tc_stringser::color,3}", FALSE, "element ::tc_stringser::listOfColor.type");
        if (db_define(tc_listOfColor_o)) {
            db_error("tc_stringser_load: failed to define object '::tc_stringser::listOfColor'.");
            goto error;
        }
    }
    /* Declare ::tc_stringser::sequenceOfColor */
    tc_sequenceOfColor_o = db_declare(tc_o, "sequenceOfColor", db_typedef(db_typedef_o));
    if (!tc_sequenceOfColor_o) {
        db_error("tc_stringser_load: failed to declare object '::tc_stringser::sequenceOfColor'.");
        goto error;
    }

    /* Define ::tc_stringser::sequenceOfColor */
    if (!db_checkState(tc_sequenceOfColor_o, DB_DEFINED)) {
        tc_sequenceOfColor_o->type = db_resolve_ext(tc_sequenceOfColor_o, NULL, "::cortex::lang::sequence{::tc_stringser::color,3}", FALSE, "element ::tc_stringser::sequenceOfColor.type");
        if (db_define(tc_sequenceOfColor_o)) {
            db_error("tc_stringser_load: failed to define object '::tc_stringser::sequenceOfColor'.");
            goto error;
        }
    }
    /* Declare ::tc_stringser::listOfBool */
    tc_listOfBool_o = db_declare(tc_o, "listOfBool", db_typedef(db_typedef_o));
    if (!tc_listOfBool_o) {
        db_error("tc_stringser_load: failed to declare object '::tc_stringser::listOfBool'.");
        goto error;
    }

    /* Declare ::tc_stringser::listOfChar */
    tc_listOfChar_o = db_declare(tc_o, "listOfChar", db_typedef(db_typedef_o));
    if (!tc_listOfChar_o) {
        db_error("tc_stringser_load: failed to declare object '::tc_stringser::listOfChar'.");
        goto error;
    }

    /* Declare ::tc_stringser::listOfFloat */
    tc_listOfFloat_o = db_declare(tc_o, "listOfFloat", db_typedef(db_typedef_o));
    if (!tc_listOfFloat_o) {
        db_error("tc_stringser_load: failed to declare object '::tc_stringser::listOfFloat'.");
        goto error;
    }

    /* Declare ::tc_stringser::listOfInt */
    tc_listOfInt_o = db_declare(tc_o, "listOfInt", db_typedef(db_typedef_o));
    if (!tc_listOfInt_o) {
        db_error("tc_stringser_load: failed to declare object '::tc_stringser::listOfInt'.");
        goto error;
    }

    /* Declare ::tc_stringser::listOfMoveMode */
    tc_listOfMoveMode_o = db_declare(tc_o, "listOfMoveMode", db_typedef(db_typedef_o));
    if (!tc_listOfMoveMode_o) {
        db_error("tc_stringser_load: failed to declare object '::tc_stringser::listOfMoveMode'.");
        goto error;
    }

    /* Declare ::tc_stringser::listOfString */
    tc_listOfString_o = db_declare(tc_o, "listOfString", db_typedef(db_typedef_o));
    if (!tc_listOfString_o) {
        db_error("tc_stringser_load: failed to declare object '::tc_stringser::listOfString'.");
        goto error;
    }

    /* Declare ::tc_stringser::moveMode */
    tc_moveMode_o = db_declare(tc_o, "moveMode", db_typedef(db_bitmask_o));
    if (!tc_moveMode_o) {
        db_error("tc_stringser_load: failed to declare object '::tc_stringser::moveMode'.");
        goto error;
    }

    /* Declare ::tc_stringser::moveMode::FLY */
    tc_moveMode_FLY_o = db_declare(tc_moveMode_o, "FLY", db_typedef(db_constant_o));
    if (!tc_moveMode_FLY_o) {
        db_error("tc_stringser_load: failed to declare object '::tc_stringser::moveMode::FLY'.");
        goto error;
    }

    /* Define ::tc_stringser::moveMode::FLY */
    if (!db_checkState(tc_moveMode_FLY_o, DB_DEFINED)) {
        (*tc_moveMode_FLY_o) = 4;
        if (db_define(tc_moveMode_FLY_o)) {
            db_error("tc_stringser_load: failed to define object '::tc_stringser::moveMode::FLY'.");
            goto error;
        }
    }
    /* Declare ::tc_stringser::moveMode::SWIM */
    tc_moveMode_SWIM_o = db_declare(tc_moveMode_o, "SWIM", db_typedef(db_constant_o));
    if (!tc_moveMode_SWIM_o) {
        db_error("tc_stringser_load: failed to declare object '::tc_stringser::moveMode::SWIM'.");
        goto error;
    }

    /* Define ::tc_stringser::moveMode::SWIM */
    if (!db_checkState(tc_moveMode_SWIM_o, DB_DEFINED)) {
        (*tc_moveMode_SWIM_o) = 2;
        if (db_define(tc_moveMode_SWIM_o)) {
            db_error("tc_stringser_load: failed to define object '::tc_stringser::moveMode::SWIM'.");
            goto error;
        }
    }
    /* Declare ::tc_stringser::moveMode::WALK */
    tc_moveMode_WALK_o = db_declare(tc_moveMode_o, "WALK", db_typedef(db_constant_o));
    if (!tc_moveMode_WALK_o) {
        db_error("tc_stringser_load: failed to declare object '::tc_stringser::moveMode::WALK'.");
        goto error;
    }

    /* Define ::tc_stringser::moveMode::WALK */
    if (!db_checkState(tc_moveMode_WALK_o, DB_DEFINED)) {
        (*tc_moveMode_WALK_o) = 1;
        if (db_define(tc_moveMode_WALK_o)) {
            db_error("tc_stringser_load: failed to define object '::tc_stringser::moveMode::WALK'.");
            goto error;
        }
    }
    /* Define ::tc_stringser::moveMode */
    if (!db_checkState(tc_moveMode_o, DB_DEFINED)) {
        if (db_define(tc_moveMode_o)) {
            db_error("tc_stringser_load: failed to define object '::tc_stringser::moveMode'.");
            goto error;
        }
    }
    /* Define ::tc_stringser::classInherit::g */
    if (!db_checkState(tc_classInherit_g_o, DB_DEFINED)) {
        tc_classInherit_g_o->type = db_resolve_ext(tc_classInherit_g_o, NULL, "::tc_stringser::moveMode", FALSE, "element ::tc_stringser::classInherit::g.type");
        tc_classInherit_g_o->modifiers = 0x0;
        tc_classInherit_g_o->state = 0x6;
        tc_classInherit_g_o->weak = FALSE;
        tc_classInherit_g_o->id = 6;
        if (db_define(tc_classInherit_g_o)) {
            db_error("tc_stringser_load: failed to define object '::tc_stringser::classInherit::g'.");
            goto error;
        }
    }
    /* Define ::tc_stringser::classPrimitives::g */
    if (!db_checkState(tc_classPrimitives_g_o, DB_DEFINED)) {
        tc_classPrimitives_g_o->type = db_resolve_ext(tc_classPrimitives_g_o, NULL, "::tc_stringser::moveMode", FALSE, "element ::tc_stringser::classPrimitives::g.type");
        tc_classPrimitives_g_o->modifiers = 0x0;
        tc_classPrimitives_g_o->state = 0x6;
        tc_classPrimitives_g_o->weak = FALSE;
        tc_classPrimitives_g_o->id = 6;
        if (db_define(tc_classPrimitives_g_o)) {
            db_error("tc_stringser_load: failed to define object '::tc_stringser::classPrimitives::g'.");
            goto error;
        }
    }
    /* Define ::tc_stringser::classPrimitives */
    if (!db_checkState(tc_classPrimitives_o, DB_DEFINED)) {
        db_type(tc_classPrimitives_o)->parentType = NULL;
        db_type(tc_classPrimitives_o)->parentState = 0x0;
        db_interface(tc_classPrimitives_o)->base = NULL;
        db_struct(tc_classPrimitives_o)->baseAccess = 0x0;
        tc_classPrimitives_o->implements.length = 0;
        tc_classPrimitives_o->implements.buffer = NULL;
        if (db_define(tc_classPrimitives_o)) {
            db_error("tc_stringser_load: failed to define object '::tc_stringser::classPrimitives'.");
            goto error;
        }
    }
    /* Define ::tc_stringser::classInherit */
    if (!db_checkState(tc_classInherit_o, DB_DEFINED)) {
        db_type(tc_classInherit_o)->parentType = NULL;
        db_type(tc_classInherit_o)->parentState = 0x0;
        db_interface(tc_classInherit_o)->base = db_resolve_ext(tc_classInherit_o, NULL, "::tc_stringser::classPrimitives", FALSE, "element ::tc_stringser::classInherit.base");
        db_struct(tc_classInherit_o)->baseAccess = 0x0;
        tc_classInherit_o->implements.length = 0;
        tc_classInherit_o->implements.buffer = NULL;
        if (db_define(tc_classInherit_o)) {
            db_error("tc_stringser_load: failed to define object '::tc_stringser::classInherit'.");
            goto error;
        }
    }
    /* Define ::tc_stringser::classNested::b */
    if (!db_checkState(tc_classNested_b_o, DB_DEFINED)) {
        tc_classNested_b_o->type = db_resolve_ext(tc_classNested_b_o, NULL, "::tc_stringser::classInherit", FALSE, "element ::tc_stringser::classNested::b.type");
        tc_classNested_b_o->modifiers = 0x0;
        tc_classNested_b_o->state = 0x6;
        tc_classNested_b_o->weak = FALSE;
        tc_classNested_b_o->id = 1;
        if (db_define(tc_classNested_b_o)) {
            db_error("tc_stringser_load: failed to define object '::tc_stringser::classNested::b'.");
            goto error;
        }
    }
    /* Define ::tc_stringser::arrayOfClassInherit */
    if (!db_checkState(tc_arrayOfClassInherit_o, DB_DEFINED)) {
        tc_arrayOfClassInherit_o->type = db_resolve_ext(tc_arrayOfClassInherit_o, NULL, "::cortex::lang::array{::tc_stringser::classInherit,3,::tc_stringser::classInherit}", FALSE, "element ::tc_stringser::arrayOfClassInherit.type");
        if (db_define(tc_arrayOfClassInherit_o)) {
            db_error("tc_stringser_load: failed to define object '::tc_stringser::arrayOfClassInherit'.");
            goto error;
        }
    }
    /* Define ::tc_stringser::classCompositeCollection::a */
    if (!db_checkState(tc_classCompositeCollection_a_o, DB_DEFINED)) {
        tc_classCompositeCollection_a_o->type = db_resolve_ext(tc_classCompositeCollection_a_o, NULL, "::tc_stringser::arrayOfClassInherit", FALSE, "element ::tc_stringser::classCompositeCollection::a.type");
        tc_classCompositeCollection_a_o->modifiers = 0x0;
        tc_classCompositeCollection_a_o->state = 0x6;
        tc_classCompositeCollection_a_o->weak = FALSE;
        tc_classCompositeCollection_a_o->id = 0;
        if (db_define(tc_classCompositeCollection_a_o)) {
            db_error("tc_stringser_load: failed to define object '::tc_stringser::classCompositeCollection::a'.");
            goto error;
        }
    }
    /* Define ::tc_stringser::classNested::a */
    if (!db_checkState(tc_classNested_a_o, DB_DEFINED)) {
        tc_classNested_a_o->type = db_resolve_ext(tc_classNested_a_o, NULL, "::tc_stringser::classPrimitives", FALSE, "element ::tc_stringser::classNested::a.type");
        tc_classNested_a_o->modifiers = 0x0;
        tc_classNested_a_o->state = 0x6;
        tc_classNested_a_o->weak = FALSE;
        tc_classNested_a_o->id = 0;
        if (db_define(tc_classNested_a_o)) {
            db_error("tc_stringser_load: failed to define object '::tc_stringser::classNested::a'.");
            goto error;
        }
    }
    /* Define ::tc_stringser::arrayOfClassPrimitives */
    if (!db_checkState(tc_arrayOfClassPrimitives_o, DB_DEFINED)) {
        tc_arrayOfClassPrimitives_o->type = db_resolve_ext(tc_arrayOfClassPrimitives_o, NULL, "::cortex::lang::array{::tc_stringser::classPrimitives,3,::tc_stringser::classPrimitives}", FALSE, "element ::tc_stringser::arrayOfClassPrimitives.type");
        if (db_define(tc_arrayOfClassPrimitives_o)) {
            db_error("tc_stringser_load: failed to define object '::tc_stringser::arrayOfClassPrimitives'.");
            goto error;
        }
    }
    /* Define ::tc_stringser::arrayOfMoveMode */
    if (!db_checkState(tc_arrayOfMoveMode_o, DB_DEFINED)) {
        tc_arrayOfMoveMode_o->type = db_resolve_ext(tc_arrayOfMoveMode_o, NULL, "::cortex::lang::array{::tc_stringser::moveMode,3,::tc_stringser::moveMode}", FALSE, "element ::tc_stringser::arrayOfMoveMode.type");
        if (db_define(tc_arrayOfMoveMode_o)) {
            db_error("tc_stringser_load: failed to define object '::tc_stringser::arrayOfMoveMode'.");
            goto error;
        }
    }
    /* Define ::tc_stringser::listOfMoveMode */
    if (!db_checkState(tc_listOfMoveMode_o, DB_DEFINED)) {
        tc_listOfMoveMode_o->type = db_resolve_ext(tc_listOfMoveMode_o, NULL, "::cortex::lang::list{::tc_stringser::moveMode,3}", FALSE, "element ::tc_stringser::listOfMoveMode.type");
        if (db_define(tc_listOfMoveMode_o)) {
            db_error("tc_stringser_load: failed to define object '::tc_stringser::listOfMoveMode'.");
            goto error;
        }
    }
    /* Declare ::tc_stringser::sequenceOfMoveMode */
    tc_sequenceOfMoveMode_o = db_declare(tc_o, "sequenceOfMoveMode", db_typedef(db_typedef_o));
    if (!tc_sequenceOfMoveMode_o) {
        db_error("tc_stringser_load: failed to declare object '::tc_stringser::sequenceOfMoveMode'.");
        goto error;
    }

    /* Define ::tc_stringser::sequenceOfMoveMode */
    if (!db_checkState(tc_sequenceOfMoveMode_o, DB_DEFINED)) {
        tc_sequenceOfMoveMode_o->type = db_resolve_ext(tc_sequenceOfMoveMode_o, NULL, "::cortex::lang::sequence{::tc_stringser::moveMode,3}", FALSE, "element ::tc_stringser::sequenceOfMoveMode.type");
        if (db_define(tc_sequenceOfMoveMode_o)) {
            db_error("tc_stringser_load: failed to define object '::tc_stringser::sequenceOfMoveMode'.");
            goto error;
        }
    }
    /* Declare ::tc_stringser::sequenceOfBool */
    tc_sequenceOfBool_o = db_declare(tc_o, "sequenceOfBool", db_typedef(db_typedef_o));
    if (!tc_sequenceOfBool_o) {
        db_error("tc_stringser_load: failed to declare object '::tc_stringser::sequenceOfBool'.");
        goto error;
    }

    /* Declare ::tc_stringser::sequenceOfChar */
    tc_sequenceOfChar_o = db_declare(tc_o, "sequenceOfChar", db_typedef(db_typedef_o));
    if (!tc_sequenceOfChar_o) {
        db_error("tc_stringser_load: failed to declare object '::tc_stringser::sequenceOfChar'.");
        goto error;
    }

    /* Declare ::tc_stringser::sequenceOfFloat */
    tc_sequenceOfFloat_o = db_declare(tc_o, "sequenceOfFloat", db_typedef(db_typedef_o));
    if (!tc_sequenceOfFloat_o) {
        db_error("tc_stringser_load: failed to declare object '::tc_stringser::sequenceOfFloat'.");
        goto error;
    }

    /* Declare ::tc_stringser::sequenceOfInt */
    tc_sequenceOfInt_o = db_declare(tc_o, "sequenceOfInt", db_typedef(db_typedef_o));
    if (!tc_sequenceOfInt_o) {
        db_error("tc_stringser_load: failed to declare object '::tc_stringser::sequenceOfInt'.");
        goto error;
    }

    /* Declare ::tc_stringser::sequenceOfString */
    tc_sequenceOfString_o = db_declare(tc_o, "sequenceOfString", db_typedef(db_typedef_o));
    if (!tc_sequenceOfString_o) {
        db_error("tc_stringser_load: failed to declare object '::tc_stringser::sequenceOfString'.");
        goto error;
    }

    /* Define ::tc_stringser::arrayOfBool */
    if (!db_checkState(tc_arrayOfBool_o, DB_DEFINED)) {
        tc_arrayOfBool_o->type = db_resolve_ext(tc_arrayOfBool_o, NULL, "::cortex::lang::array{::cortex::lang::bool,3,::cortex::lang::bool}", FALSE, "element ::tc_stringser::arrayOfBool.type");
        if (db_define(tc_arrayOfBool_o)) {
            db_error("tc_stringser_load: failed to define object '::tc_stringser::arrayOfBool'.");
            goto error;
        }
    }
    /* Define ::tc_stringser::arrayOfChar */
    if (!db_checkState(tc_arrayOfChar_o, DB_DEFINED)) {
        tc_arrayOfChar_o->type = db_resolve_ext(tc_arrayOfChar_o, NULL, "::cortex::lang::array{::cortex::lang::char,3,::cortex::lang::char}", FALSE, "element ::tc_stringser::arrayOfChar.type");
        if (db_define(tc_arrayOfChar_o)) {
            db_error("tc_stringser_load: failed to define object '::tc_stringser::arrayOfChar'.");
            goto error;
        }
    }
    /* Define ::tc_stringser::arrayOfFloat */
    if (!db_checkState(tc_arrayOfFloat_o, DB_DEFINED)) {
        tc_arrayOfFloat_o->type = db_resolve_ext(tc_arrayOfFloat_o, NULL, "::cortex::lang::array{::cortex::lang::float32,3,::cortex::lang::float32}", FALSE, "element ::tc_stringser::arrayOfFloat.type");
        if (db_define(tc_arrayOfFloat_o)) {
            db_error("tc_stringser_load: failed to define object '::tc_stringser::arrayOfFloat'.");
            goto error;
        }
    }
    /* Define ::tc_stringser::arrayOfInt */
    if (!db_checkState(tc_arrayOfInt_o, DB_DEFINED)) {
        tc_arrayOfInt_o->type = db_resolve_ext(tc_arrayOfInt_o, NULL, "::cortex::lang::array{::cortex::lang::int32,3,::cortex::lang::int32}", FALSE, "element ::tc_stringser::arrayOfInt.type");
        if (db_define(tc_arrayOfInt_o)) {
            db_error("tc_stringser_load: failed to define object '::tc_stringser::arrayOfInt'.");
            goto error;
        }
    }
    /* Define ::tc_stringser::classNested::c */
    if (!db_checkState(tc_classNested_c_o, DB_DEFINED)) {
        tc_classNested_c_o->type = db_resolve_ext(tc_classNested_c_o, NULL, "::tc_stringser::arrayOfInt", FALSE, "element ::tc_stringser::classNested::c.type");
        tc_classNested_c_o->modifiers = 0x0;
        tc_classNested_c_o->state = 0x6;
        tc_classNested_c_o->weak = FALSE;
        tc_classNested_c_o->id = 2;
        if (db_define(tc_classNested_c_o)) {
            db_error("tc_stringser_load: failed to define object '::tc_stringser::classNested::c'.");
            goto error;
        }
    }
    /* Define ::tc_stringser::arrayOfString */
    if (!db_checkState(tc_arrayOfString_o, DB_DEFINED)) {
        tc_arrayOfString_o->type = db_resolve_ext(tc_arrayOfString_o, NULL, "::cortex::lang::array{::cortex::lang::string,3,::cortex::lang::string}", FALSE, "element ::tc_stringser::arrayOfString.type");
        if (db_define(tc_arrayOfString_o)) {
            db_error("tc_stringser_load: failed to define object '::tc_stringser::arrayOfString'.");
            goto error;
        }
    }
    /* Define ::tc_stringser::listOfBool */
    if (!db_checkState(tc_listOfBool_o, DB_DEFINED)) {
        tc_listOfBool_o->type = db_resolve_ext(tc_listOfBool_o, NULL, "::cortex::lang::list{::cortex::lang::bool,3}", FALSE, "element ::tc_stringser::listOfBool.type");
        if (db_define(tc_listOfBool_o)) {
            db_error("tc_stringser_load: failed to define object '::tc_stringser::listOfBool'.");
            goto error;
        }
    }
    /* Define ::tc_stringser::listOfChar */
    if (!db_checkState(tc_listOfChar_o, DB_DEFINED)) {
        tc_listOfChar_o->type = db_resolve_ext(tc_listOfChar_o, NULL, "::cortex::lang::list{::cortex::lang::char,3}", FALSE, "element ::tc_stringser::listOfChar.type");
        if (db_define(tc_listOfChar_o)) {
            db_error("tc_stringser_load: failed to define object '::tc_stringser::listOfChar'.");
            goto error;
        }
    }
    /* Define ::tc_stringser::listOfFloat */
    if (!db_checkState(tc_listOfFloat_o, DB_DEFINED)) {
        tc_listOfFloat_o->type = db_resolve_ext(tc_listOfFloat_o, NULL, "::cortex::lang::list{::cortex::lang::float32,3}", FALSE, "element ::tc_stringser::listOfFloat.type");
        if (db_define(tc_listOfFloat_o)) {
            db_error("tc_stringser_load: failed to define object '::tc_stringser::listOfFloat'.");
            goto error;
        }
    }
    /* Define ::tc_stringser::listOfInt */
    if (!db_checkState(tc_listOfInt_o, DB_DEFINED)) {
        tc_listOfInt_o->type = db_resolve_ext(tc_listOfInt_o, NULL, "::cortex::lang::list{::cortex::lang::int32,3}", FALSE, "element ::tc_stringser::listOfInt.type");
        if (db_define(tc_listOfInt_o)) {
            db_error("tc_stringser_load: failed to define object '::tc_stringser::listOfInt'.");
            goto error;
        }
    }
    /* Define ::tc_stringser::classNested::e */
    if (!db_checkState(tc_classNested_e_o, DB_DEFINED)) {
        tc_classNested_e_o->type = db_resolve_ext(tc_classNested_e_o, NULL, "::tc_stringser::listOfInt", FALSE, "element ::tc_stringser::classNested::e.type");
        tc_classNested_e_o->modifiers = 0x0;
        tc_classNested_e_o->state = 0x6;
        tc_classNested_e_o->weak = FALSE;
        tc_classNested_e_o->id = 4;
        if (db_define(tc_classNested_e_o)) {
            db_error("tc_stringser_load: failed to define object '::tc_stringser::classNested::e'.");
            goto error;
        }
    }
    /* Define ::tc_stringser::listOfString */
    if (!db_checkState(tc_listOfString_o, DB_DEFINED)) {
        tc_listOfString_o->type = db_resolve_ext(tc_listOfString_o, NULL, "::cortex::lang::list{::cortex::lang::string,3}", FALSE, "element ::tc_stringser::listOfString.type");
        if (db_define(tc_listOfString_o)) {
            db_error("tc_stringser_load: failed to define object '::tc_stringser::listOfString'.");
            goto error;
        }
    }
    /* Define ::tc_stringser::sequenceOfBool */
    if (!db_checkState(tc_sequenceOfBool_o, DB_DEFINED)) {
        tc_sequenceOfBool_o->type = db_resolve_ext(tc_sequenceOfBool_o, NULL, "::cortex::lang::sequence{::cortex::lang::bool,3}", FALSE, "element ::tc_stringser::sequenceOfBool.type");
        if (db_define(tc_sequenceOfBool_o)) {
            db_error("tc_stringser_load: failed to define object '::tc_stringser::sequenceOfBool'.");
            goto error;
        }
    }
    /* Define ::tc_stringser::sequenceOfChar */
    if (!db_checkState(tc_sequenceOfChar_o, DB_DEFINED)) {
        tc_sequenceOfChar_o->type = db_resolve_ext(tc_sequenceOfChar_o, NULL, "::cortex::lang::sequence{::cortex::lang::char,3}", FALSE, "element ::tc_stringser::sequenceOfChar.type");
        if (db_define(tc_sequenceOfChar_o)) {
            db_error("tc_stringser_load: failed to define object '::tc_stringser::sequenceOfChar'.");
            goto error;
        }
    }
    /* Define ::tc_stringser::sequenceOfFloat */
    if (!db_checkState(tc_sequenceOfFloat_o, DB_DEFINED)) {
        tc_sequenceOfFloat_o->type = db_resolve_ext(tc_sequenceOfFloat_o, NULL, "::cortex::lang::sequence{::cortex::lang::float32,3}", FALSE, "element ::tc_stringser::sequenceOfFloat.type");
        if (db_define(tc_sequenceOfFloat_o)) {
            db_error("tc_stringser_load: failed to define object '::tc_stringser::sequenceOfFloat'.");
            goto error;
        }
    }
    /* Define ::tc_stringser::sequenceOfInt */
    if (!db_checkState(tc_sequenceOfInt_o, DB_DEFINED)) {
        tc_sequenceOfInt_o->type = db_resolve_ext(tc_sequenceOfInt_o, NULL, "::cortex::lang::sequence{::cortex::lang::int32,3}", FALSE, "element ::tc_stringser::sequenceOfInt.type");
        if (db_define(tc_sequenceOfInt_o)) {
            db_error("tc_stringser_load: failed to define object '::tc_stringser::sequenceOfInt'.");
            goto error;
        }
    }
    /* Define ::tc_stringser::classNested::d */
    if (!db_checkState(tc_classNested_d_o, DB_DEFINED)) {
        tc_classNested_d_o->type = db_resolve_ext(tc_classNested_d_o, NULL, "::tc_stringser::sequenceOfInt", FALSE, "element ::tc_stringser::classNested::d.type");
        tc_classNested_d_o->modifiers = 0x0;
        tc_classNested_d_o->state = 0x6;
        tc_classNested_d_o->weak = FALSE;
        tc_classNested_d_o->id = 3;
        if (db_define(tc_classNested_d_o)) {
            db_error("tc_stringser_load: failed to define object '::tc_stringser::classNested::d'.");
            goto error;
        }
    }
    /* Define ::tc_stringser::classNested */
    if (!db_checkState(tc_classNested_o, DB_DEFINED)) {
        db_type(tc_classNested_o)->parentType = NULL;
        db_type(tc_classNested_o)->parentState = 0x0;
        db_interface(tc_classNested_o)->base = NULL;
        db_struct(tc_classNested_o)->baseAccess = 0x0;
        tc_classNested_o->implements.length = 0;
        tc_classNested_o->implements.buffer = NULL;
        if (db_define(tc_classNested_o)) {
            db_error("tc_stringser_load: failed to define object '::tc_stringser::classNested'.");
            goto error;
        }
    }
    /* Define ::tc_stringser::arrayOfClassNested */
    if (!db_checkState(tc_arrayOfClassNested_o, DB_DEFINED)) {
        tc_arrayOfClassNested_o->type = db_resolve_ext(tc_arrayOfClassNested_o, NULL, "::cortex::lang::array{::tc_stringser::classNested,3,::tc_stringser::classNested}", FALSE, "element ::tc_stringser::arrayOfClassNested.type");
        if (db_define(tc_arrayOfClassNested_o)) {
            db_error("tc_stringser_load: failed to define object '::tc_stringser::arrayOfClassNested'.");
            goto error;
        }
    }
    /* Define ::tc_stringser::classCompositeCollection::b */
    if (!db_checkState(tc_classCompositeCollection_b_o, DB_DEFINED)) {
        tc_classCompositeCollection_b_o->type = db_resolve_ext(tc_classCompositeCollection_b_o, NULL, "::tc_stringser::arrayOfClassNested", FALSE, "element ::tc_stringser::classCompositeCollection::b.type");
        tc_classCompositeCollection_b_o->modifiers = 0x0;
        tc_classCompositeCollection_b_o->state = 0x6;
        tc_classCompositeCollection_b_o->weak = FALSE;
        tc_classCompositeCollection_b_o->id = 1;
        if (db_define(tc_classCompositeCollection_b_o)) {
            db_error("tc_stringser_load: failed to define object '::tc_stringser::classCompositeCollection::b'.");
            goto error;
        }
    }
    /* Define ::tc_stringser::classCompositeCollection */
    if (!db_checkState(tc_classCompositeCollection_o, DB_DEFINED)) {
        db_type(tc_classCompositeCollection_o)->parentType = NULL;
        db_type(tc_classCompositeCollection_o)->parentState = 0x0;
        db_interface(tc_classCompositeCollection_o)->base = NULL;
        db_struct(tc_classCompositeCollection_o)->baseAccess = 0x0;
        tc_classCompositeCollection_o->implements.length = 0;
        tc_classCompositeCollection_o->implements.buffer = NULL;
        if (db_define(tc_classCompositeCollection_o)) {
            db_error("tc_stringser_load: failed to define object '::tc_stringser::classCompositeCollection'.");
            goto error;
        }
    }
    /* Define ::tc_stringser::sequenceOfString */
    if (!db_checkState(tc_sequenceOfString_o, DB_DEFINED)) {
        tc_sequenceOfString_o->type = db_resolve_ext(tc_sequenceOfString_o, NULL, "::cortex::lang::sequence{::cortex::lang::string,3}", FALSE, "element ::tc_stringser::sequenceOfString.type");
        if (db_define(tc_sequenceOfString_o)) {
            db_error("tc_stringser_load: failed to define object '::tc_stringser::sequenceOfString'.");
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
