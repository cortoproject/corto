/* tc_stringser__meta.c
 *
 *  Generated on Feb  5 2014
 *    Loads objects in database.
 *    This file contains generated code. Do not modify!
 */

#include "tc_stringser__type.h"

/* Variable definitions */
cx_object tc_o;
cx_typedef tc_arrayOfBool_o;
cx_typedef tc_arrayOfChar_o;
cx_typedef tc_arrayOfClassInherit_o;
cx_typedef tc_arrayOfClassNested_o;
cx_typedef tc_arrayOfClassPrimitives_o;
cx_typedef tc_arrayOfColor_o;
cx_typedef tc_arrayOfFloat_o;
cx_typedef tc_arrayOfInt_o;
cx_typedef tc_arrayOfMoveMode_o;
cx_typedef tc_arrayOfString_o;
cx_class tc_classCompositeCollection_o;
cx_member tc_classCompositeCollection_a_o;
cx_member tc_classCompositeCollection_b_o;
cx_member tc_classCompositeCollection_c_o;
cx_member tc_classCompositeCollection_d_o;
cx_member tc_classCompositeCollection_e_o;
cx_class tc_classInherit_o;
cx_member tc_classInherit_a_o;
cx_member tc_classInherit_b_o;
cx_member tc_classInherit_c_o;
cx_member tc_classInherit_d_o;
cx_member tc_classInherit_e_o;
cx_member tc_classInherit_f_o;
cx_member tc_classInherit_g_o;
cx_class tc_classNested_o;
cx_member tc_classNested_a_o;
cx_member tc_classNested_b_o;
cx_member tc_classNested_c_o;
cx_member tc_classNested_d_o;
cx_member tc_classNested_e_o;
cx_class tc_classPrimitives_o;
cx_member tc_classPrimitives_a_o;
cx_member tc_classPrimitives_b_o;
cx_member tc_classPrimitives_c_o;
cx_member tc_classPrimitives_d_o;
cx_member tc_classPrimitives_e_o;
cx_member tc_classPrimitives_f_o;
cx_member tc_classPrimitives_g_o;
cx_enum tc_color_o;
cx_constant (*tc_color_BLUE_o);
cx_constant (*tc_color_RED_o);
cx_constant (*tc_color_YELLOW_o);
cx_typedef tc_listOfBool_o;
cx_typedef tc_listOfChar_o;
cx_typedef tc_listOfClassInherit_o;
cx_typedef tc_listOfClassNested_o;
cx_typedef tc_listOfClassPrimitives_o;
cx_typedef tc_listOfColor_o;
cx_typedef tc_listOfFloat_o;
cx_typedef tc_listOfInt_o;
cx_typedef tc_listOfMoveMode_o;
cx_typedef tc_listOfString_o;
cx_bitmask tc_moveMode_o;
cx_constant (*tc_moveMode_FLY_o);
cx_constant (*tc_moveMode_SWIM_o);
cx_constant (*tc_moveMode_WALK_o);
cx_typedef tc_sequenceOfBool_o;
cx_typedef tc_sequenceOfChar_o;
cx_typedef tc_sequenceOfClassInherit_o;
cx_typedef tc_sequenceOfClassNested_o;
cx_typedef tc_sequenceOfClassPrimitives_o;
cx_typedef tc_sequenceOfColor_o;
cx_typedef tc_sequenceOfFloat_o;
cx_typedef tc_sequenceOfInt_o;
cx_typedef tc_sequenceOfMoveMode_o;
cx_typedef tc_sequenceOfString_o;

/* Load objects in database */
int tc_stringser_load(void) {
    cx_object _a_; /* Used for resolving anonymous objects */
    _a_ = NULL;

    /* Declare ::tc_stringser */
    tc_o = cx_declare(root_o, "tc_stringser", cx_typedef(cx_object_o));
    if (!tc_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser'.");
        goto error;
    }

    /* Define ::tc_stringser */
    if (!cx_checkState(tc_o, CX_DEFINED)) {
        if (cx_define(tc_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser'.");
            goto error;
        }
    }
    /* Declare ::tc_stringser::arrayOfBool */
    tc_arrayOfBool_o = cx_declare(tc_o, "arrayOfBool", cx_typedef(cx_typedef_o));
    if (!tc_arrayOfBool_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::arrayOfBool'.");
        goto error;
    }

    /* Declare ::tc_stringser::arrayOfChar */
    tc_arrayOfChar_o = cx_declare(tc_o, "arrayOfChar", cx_typedef(cx_typedef_o));
    if (!tc_arrayOfChar_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::arrayOfChar'.");
        goto error;
    }

    /* Declare ::tc_stringser::arrayOfClassInherit */
    tc_arrayOfClassInherit_o = cx_declare(tc_o, "arrayOfClassInherit", cx_typedef(cx_typedef_o));
    if (!tc_arrayOfClassInherit_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::arrayOfClassInherit'.");
        goto error;
    }

    /* Declare ::tc_stringser::arrayOfClassNested */
    tc_arrayOfClassNested_o = cx_declare(tc_o, "arrayOfClassNested", cx_typedef(cx_typedef_o));
    if (!tc_arrayOfClassNested_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::arrayOfClassNested'.");
        goto error;
    }

    /* Declare ::tc_stringser::arrayOfClassPrimitives */
    tc_arrayOfClassPrimitives_o = cx_declare(tc_o, "arrayOfClassPrimitives", cx_typedef(cx_typedef_o));
    if (!tc_arrayOfClassPrimitives_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::arrayOfClassPrimitives'.");
        goto error;
    }

    /* Declare ::tc_stringser::arrayOfColor */
    tc_arrayOfColor_o = cx_declare(tc_o, "arrayOfColor", cx_typedef(cx_typedef_o));
    if (!tc_arrayOfColor_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::arrayOfColor'.");
        goto error;
    }

    /* Declare ::tc_stringser::arrayOfFloat */
    tc_arrayOfFloat_o = cx_declare(tc_o, "arrayOfFloat", cx_typedef(cx_typedef_o));
    if (!tc_arrayOfFloat_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::arrayOfFloat'.");
        goto error;
    }

    /* Declare ::tc_stringser::arrayOfInt */
    tc_arrayOfInt_o = cx_declare(tc_o, "arrayOfInt", cx_typedef(cx_typedef_o));
    if (!tc_arrayOfInt_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::arrayOfInt'.");
        goto error;
    }

    /* Declare ::tc_stringser::arrayOfMoveMode */
    tc_arrayOfMoveMode_o = cx_declare(tc_o, "arrayOfMoveMode", cx_typedef(cx_typedef_o));
    if (!tc_arrayOfMoveMode_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::arrayOfMoveMode'.");
        goto error;
    }

    /* Declare ::tc_stringser::arrayOfString */
    tc_arrayOfString_o = cx_declare(tc_o, "arrayOfString", cx_typedef(cx_typedef_o));
    if (!tc_arrayOfString_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::arrayOfString'.");
        goto error;
    }

    /* Declare ::tc_stringser::classCompositeCollection */
    tc_classCompositeCollection_o = cx_declare(tc_o, "classCompositeCollection", cx_typedef(cx_class_o));
    if (!tc_classCompositeCollection_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::classCompositeCollection'.");
        goto error;
    }

    /* Declare ::tc_stringser::classCompositeCollection::a */
    tc_classCompositeCollection_a_o = cx_declare(tc_classCompositeCollection_o, "a", cx_typedef(cx_member_o));
    if (!tc_classCompositeCollection_a_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::classCompositeCollection::a'.");
        goto error;
    }

    /* Declare ::tc_stringser::classCompositeCollection::b */
    tc_classCompositeCollection_b_o = cx_declare(tc_classCompositeCollection_o, "b", cx_typedef(cx_member_o));
    if (!tc_classCompositeCollection_b_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::classCompositeCollection::b'.");
        goto error;
    }

    /* Declare ::tc_stringser::classCompositeCollection::c */
    tc_classCompositeCollection_c_o = cx_declare(tc_classCompositeCollection_o, "c", cx_typedef(cx_member_o));
    if (!tc_classCompositeCollection_c_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::classCompositeCollection::c'.");
        goto error;
    }

    /* Declare ::tc_stringser::classCompositeCollection::d */
    tc_classCompositeCollection_d_o = cx_declare(tc_classCompositeCollection_o, "d", cx_typedef(cx_member_o));
    if (!tc_classCompositeCollection_d_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::classCompositeCollection::d'.");
        goto error;
    }

    /* Declare ::tc_stringser::classCompositeCollection::e */
    tc_classCompositeCollection_e_o = cx_declare(tc_classCompositeCollection_o, "e", cx_typedef(cx_member_o));
    if (!tc_classCompositeCollection_e_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::classCompositeCollection::e'.");
        goto error;
    }

    /* Declare ::tc_stringser::classInherit */
    tc_classInherit_o = cx_declare(tc_o, "classInherit", cx_typedef(cx_class_o));
    if (!tc_classInherit_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::classInherit'.");
        goto error;
    }

    /* Declare ::tc_stringser::classInherit::a */
    tc_classInherit_a_o = cx_declare(tc_classInherit_o, "a", cx_typedef(cx_member_o));
    if (!tc_classInherit_a_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::classInherit::a'.");
        goto error;
    }

    /* Define ::tc_stringser::classInherit::a */
    if (!cx_checkState(tc_classInherit_a_o, CX_DEFINED)) {
        tc_classInherit_a_o->type = cx_resolve_ext(tc_classInherit_a_o, NULL, "::cortex::lang::bool", FALSE, "element ::tc_stringser::classInherit::a.type");
        tc_classInherit_a_o->modifiers = 0x0;
        tc_classInherit_a_o->state = 0x6;
        tc_classInherit_a_o->weak = FALSE;
        tc_classInherit_a_o->id = 0;
        if (cx_define(tc_classInherit_a_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::classInherit::a'.");
            goto error;
        }
    }
    /* Declare ::tc_stringser::classInherit::b */
    tc_classInherit_b_o = cx_declare(tc_classInherit_o, "b", cx_typedef(cx_member_o));
    if (!tc_classInherit_b_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::classInherit::b'.");
        goto error;
    }

    /* Define ::tc_stringser::classInherit::b */
    if (!cx_checkState(tc_classInherit_b_o, CX_DEFINED)) {
        tc_classInherit_b_o->type = cx_resolve_ext(tc_classInherit_b_o, NULL, "::cortex::lang::char", FALSE, "element ::tc_stringser::classInherit::b.type");
        tc_classInherit_b_o->modifiers = 0x0;
        tc_classInherit_b_o->state = 0x6;
        tc_classInherit_b_o->weak = FALSE;
        tc_classInherit_b_o->id = 1;
        if (cx_define(tc_classInherit_b_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::classInherit::b'.");
            goto error;
        }
    }
    /* Declare ::tc_stringser::classInherit::c */
    tc_classInherit_c_o = cx_declare(tc_classInherit_o, "c", cx_typedef(cx_member_o));
    if (!tc_classInherit_c_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::classInherit::c'.");
        goto error;
    }

    /* Define ::tc_stringser::classInherit::c */
    if (!cx_checkState(tc_classInherit_c_o, CX_DEFINED)) {
        tc_classInherit_c_o->type = cx_resolve_ext(tc_classInherit_c_o, NULL, "::cortex::lang::int32", FALSE, "element ::tc_stringser::classInherit::c.type");
        tc_classInherit_c_o->modifiers = 0x0;
        tc_classInherit_c_o->state = 0x6;
        tc_classInherit_c_o->weak = FALSE;
        tc_classInherit_c_o->id = 2;
        if (cx_define(tc_classInherit_c_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::classInherit::c'.");
            goto error;
        }
    }
    /* Declare ::tc_stringser::classInherit::d */
    tc_classInherit_d_o = cx_declare(tc_classInherit_o, "d", cx_typedef(cx_member_o));
    if (!tc_classInherit_d_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::classInherit::d'.");
        goto error;
    }

    /* Define ::tc_stringser::classInherit::d */
    if (!cx_checkState(tc_classInherit_d_o, CX_DEFINED)) {
        tc_classInherit_d_o->type = cx_resolve_ext(tc_classInherit_d_o, NULL, "::cortex::lang::float32", FALSE, "element ::tc_stringser::classInherit::d.type");
        tc_classInherit_d_o->modifiers = 0x0;
        tc_classInherit_d_o->state = 0x6;
        tc_classInherit_d_o->weak = FALSE;
        tc_classInherit_d_o->id = 3;
        if (cx_define(tc_classInherit_d_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::classInherit::d'.");
            goto error;
        }
    }
    /* Declare ::tc_stringser::classInherit::e */
    tc_classInherit_e_o = cx_declare(tc_classInherit_o, "e", cx_typedef(cx_member_o));
    if (!tc_classInherit_e_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::classInherit::e'.");
        goto error;
    }

    /* Define ::tc_stringser::classInherit::e */
    if (!cx_checkState(tc_classInherit_e_o, CX_DEFINED)) {
        tc_classInherit_e_o->type = cx_resolve_ext(tc_classInherit_e_o, NULL, "::cortex::lang::string", FALSE, "element ::tc_stringser::classInherit::e.type");
        tc_classInherit_e_o->modifiers = 0x0;
        tc_classInherit_e_o->state = 0x6;
        tc_classInherit_e_o->weak = FALSE;
        tc_classInherit_e_o->id = 4;
        if (cx_define(tc_classInherit_e_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::classInherit::e'.");
            goto error;
        }
    }
    /* Declare ::tc_stringser::classInherit::f */
    tc_classInherit_f_o = cx_declare(tc_classInherit_o, "f", cx_typedef(cx_member_o));
    if (!tc_classInherit_f_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::classInherit::f'.");
        goto error;
    }

    /* Declare ::tc_stringser::classInherit::g */
    tc_classInherit_g_o = cx_declare(tc_classInherit_o, "g", cx_typedef(cx_member_o));
    if (!tc_classInherit_g_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::classInherit::g'.");
        goto error;
    }

    /* Declare ::tc_stringser::listOfClassInherit */
    tc_listOfClassInherit_o = cx_declare(tc_o, "listOfClassInherit", cx_typedef(cx_typedef_o));
    if (!tc_listOfClassInherit_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::listOfClassInherit'.");
        goto error;
    }

    /* Define ::tc_stringser::listOfClassInherit */
    if (!cx_checkState(tc_listOfClassInherit_o, CX_DEFINED)) {
        tc_listOfClassInherit_o->type = cx_resolve_ext(tc_listOfClassInherit_o, NULL, "::cortex::lang::list{::tc_stringser::classInherit,3}", FALSE, "element ::tc_stringser::listOfClassInherit.type");
        if (cx_define(tc_listOfClassInherit_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::listOfClassInherit'.");
            goto error;
        }
    }
    /* Define ::tc_stringser::classCompositeCollection::e */
    if (!cx_checkState(tc_classCompositeCollection_e_o, CX_DEFINED)) {
        tc_classCompositeCollection_e_o->type = cx_resolve_ext(tc_classCompositeCollection_e_o, NULL, "::tc_stringser::listOfClassInherit", FALSE, "element ::tc_stringser::classCompositeCollection::e.type");
        tc_classCompositeCollection_e_o->modifiers = 0x0;
        tc_classCompositeCollection_e_o->state = 0x6;
        tc_classCompositeCollection_e_o->weak = FALSE;
        tc_classCompositeCollection_e_o->id = 4;
        if (cx_define(tc_classCompositeCollection_e_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::classCompositeCollection::e'.");
            goto error;
        }
    }
    /* Declare ::tc_stringser::sequenceOfClassInherit */
    tc_sequenceOfClassInherit_o = cx_declare(tc_o, "sequenceOfClassInherit", cx_typedef(cx_typedef_o));
    if (!tc_sequenceOfClassInherit_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::sequenceOfClassInherit'.");
        goto error;
    }

    /* Define ::tc_stringser::sequenceOfClassInherit */
    if (!cx_checkState(tc_sequenceOfClassInherit_o, CX_DEFINED)) {
        tc_sequenceOfClassInherit_o->type = cx_resolve_ext(tc_sequenceOfClassInherit_o, NULL, "::cortex::lang::sequence{::tc_stringser::classInherit,3}", FALSE, "element ::tc_stringser::sequenceOfClassInherit.type");
        if (cx_define(tc_sequenceOfClassInherit_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::sequenceOfClassInherit'.");
            goto error;
        }
    }
    /* Define ::tc_stringser::classCompositeCollection::c */
    if (!cx_checkState(tc_classCompositeCollection_c_o, CX_DEFINED)) {
        tc_classCompositeCollection_c_o->type = cx_resolve_ext(tc_classCompositeCollection_c_o, NULL, "::tc_stringser::sequenceOfClassInherit", FALSE, "element ::tc_stringser::classCompositeCollection::c.type");
        tc_classCompositeCollection_c_o->modifiers = 0x0;
        tc_classCompositeCollection_c_o->state = 0x6;
        tc_classCompositeCollection_c_o->weak = FALSE;
        tc_classCompositeCollection_c_o->id = 2;
        if (cx_define(tc_classCompositeCollection_c_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::classCompositeCollection::c'.");
            goto error;
        }
    }
    /* Declare ::tc_stringser::classNested */
    tc_classNested_o = cx_declare(tc_o, "classNested", cx_typedef(cx_class_o));
    if (!tc_classNested_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::classNested'.");
        goto error;
    }

    /* Declare ::tc_stringser::classNested::a */
    tc_classNested_a_o = cx_declare(tc_classNested_o, "a", cx_typedef(cx_member_o));
    if (!tc_classNested_a_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::classNested::a'.");
        goto error;
    }

    /* Declare ::tc_stringser::classNested::b */
    tc_classNested_b_o = cx_declare(tc_classNested_o, "b", cx_typedef(cx_member_o));
    if (!tc_classNested_b_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::classNested::b'.");
        goto error;
    }

    /* Declare ::tc_stringser::classNested::c */
    tc_classNested_c_o = cx_declare(tc_classNested_o, "c", cx_typedef(cx_member_o));
    if (!tc_classNested_c_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::classNested::c'.");
        goto error;
    }

    /* Declare ::tc_stringser::classNested::d */
    tc_classNested_d_o = cx_declare(tc_classNested_o, "d", cx_typedef(cx_member_o));
    if (!tc_classNested_d_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::classNested::d'.");
        goto error;
    }

    /* Declare ::tc_stringser::classNested::e */
    tc_classNested_e_o = cx_declare(tc_classNested_o, "e", cx_typedef(cx_member_o));
    if (!tc_classNested_e_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::classNested::e'.");
        goto error;
    }

    /* Declare ::tc_stringser::listOfClassNested */
    tc_listOfClassNested_o = cx_declare(tc_o, "listOfClassNested", cx_typedef(cx_typedef_o));
    if (!tc_listOfClassNested_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::listOfClassNested'.");
        goto error;
    }

    /* Define ::tc_stringser::listOfClassNested */
    if (!cx_checkState(tc_listOfClassNested_o, CX_DEFINED)) {
        tc_listOfClassNested_o->type = cx_resolve_ext(tc_listOfClassNested_o, NULL, "::cortex::lang::list{::tc_stringser::classNested,3}", FALSE, "element ::tc_stringser::listOfClassNested.type");
        if (cx_define(tc_listOfClassNested_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::listOfClassNested'.");
            goto error;
        }
    }
    /* Define ::tc_stringser::classCompositeCollection::d */
    if (!cx_checkState(tc_classCompositeCollection_d_o, CX_DEFINED)) {
        tc_classCompositeCollection_d_o->type = cx_resolve_ext(tc_classCompositeCollection_d_o, NULL, "::tc_stringser::listOfClassNested", FALSE, "element ::tc_stringser::classCompositeCollection::d.type");
        tc_classCompositeCollection_d_o->modifiers = 0x0;
        tc_classCompositeCollection_d_o->state = 0x6;
        tc_classCompositeCollection_d_o->weak = FALSE;
        tc_classCompositeCollection_d_o->id = 3;
        if (cx_define(tc_classCompositeCollection_d_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::classCompositeCollection::d'.");
            goto error;
        }
    }
    /* Declare ::tc_stringser::sequenceOfClassNested */
    tc_sequenceOfClassNested_o = cx_declare(tc_o, "sequenceOfClassNested", cx_typedef(cx_typedef_o));
    if (!tc_sequenceOfClassNested_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::sequenceOfClassNested'.");
        goto error;
    }

    /* Define ::tc_stringser::sequenceOfClassNested */
    if (!cx_checkState(tc_sequenceOfClassNested_o, CX_DEFINED)) {
        tc_sequenceOfClassNested_o->type = cx_resolve_ext(tc_sequenceOfClassNested_o, NULL, "::cortex::lang::sequence{::tc_stringser::classNested,3}", FALSE, "element ::tc_stringser::sequenceOfClassNested.type");
        if (cx_define(tc_sequenceOfClassNested_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::sequenceOfClassNested'.");
            goto error;
        }
    }
    /* Declare ::tc_stringser::classPrimitives */
    tc_classPrimitives_o = cx_declare(tc_o, "classPrimitives", cx_typedef(cx_class_o));
    if (!tc_classPrimitives_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::classPrimitives'.");
        goto error;
    }

    /* Declare ::tc_stringser::classPrimitives::a */
    tc_classPrimitives_a_o = cx_declare(tc_classPrimitives_o, "a", cx_typedef(cx_member_o));
    if (!tc_classPrimitives_a_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::classPrimitives::a'.");
        goto error;
    }

    /* Define ::tc_stringser::classPrimitives::a */
    if (!cx_checkState(tc_classPrimitives_a_o, CX_DEFINED)) {
        tc_classPrimitives_a_o->type = cx_resolve_ext(tc_classPrimitives_a_o, NULL, "::cortex::lang::bool", FALSE, "element ::tc_stringser::classPrimitives::a.type");
        tc_classPrimitives_a_o->modifiers = 0x0;
        tc_classPrimitives_a_o->state = 0x6;
        tc_classPrimitives_a_o->weak = FALSE;
        tc_classPrimitives_a_o->id = 0;
        if (cx_define(tc_classPrimitives_a_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::classPrimitives::a'.");
            goto error;
        }
    }
    /* Declare ::tc_stringser::classPrimitives::b */
    tc_classPrimitives_b_o = cx_declare(tc_classPrimitives_o, "b", cx_typedef(cx_member_o));
    if (!tc_classPrimitives_b_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::classPrimitives::b'.");
        goto error;
    }

    /* Define ::tc_stringser::classPrimitives::b */
    if (!cx_checkState(tc_classPrimitives_b_o, CX_DEFINED)) {
        tc_classPrimitives_b_o->type = cx_resolve_ext(tc_classPrimitives_b_o, NULL, "::cortex::lang::char", FALSE, "element ::tc_stringser::classPrimitives::b.type");
        tc_classPrimitives_b_o->modifiers = 0x0;
        tc_classPrimitives_b_o->state = 0x6;
        tc_classPrimitives_b_o->weak = FALSE;
        tc_classPrimitives_b_o->id = 1;
        if (cx_define(tc_classPrimitives_b_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::classPrimitives::b'.");
            goto error;
        }
    }
    /* Declare ::tc_stringser::classPrimitives::c */
    tc_classPrimitives_c_o = cx_declare(tc_classPrimitives_o, "c", cx_typedef(cx_member_o));
    if (!tc_classPrimitives_c_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::classPrimitives::c'.");
        goto error;
    }

    /* Define ::tc_stringser::classPrimitives::c */
    if (!cx_checkState(tc_classPrimitives_c_o, CX_DEFINED)) {
        tc_classPrimitives_c_o->type = cx_resolve_ext(tc_classPrimitives_c_o, NULL, "::cortex::lang::int32", FALSE, "element ::tc_stringser::classPrimitives::c.type");
        tc_classPrimitives_c_o->modifiers = 0x0;
        tc_classPrimitives_c_o->state = 0x6;
        tc_classPrimitives_c_o->weak = FALSE;
        tc_classPrimitives_c_o->id = 2;
        if (cx_define(tc_classPrimitives_c_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::classPrimitives::c'.");
            goto error;
        }
    }
    /* Declare ::tc_stringser::classPrimitives::d */
    tc_classPrimitives_d_o = cx_declare(tc_classPrimitives_o, "d", cx_typedef(cx_member_o));
    if (!tc_classPrimitives_d_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::classPrimitives::d'.");
        goto error;
    }

    /* Define ::tc_stringser::classPrimitives::d */
    if (!cx_checkState(tc_classPrimitives_d_o, CX_DEFINED)) {
        tc_classPrimitives_d_o->type = cx_resolve_ext(tc_classPrimitives_d_o, NULL, "::cortex::lang::float32", FALSE, "element ::tc_stringser::classPrimitives::d.type");
        tc_classPrimitives_d_o->modifiers = 0x0;
        tc_classPrimitives_d_o->state = 0x6;
        tc_classPrimitives_d_o->weak = FALSE;
        tc_classPrimitives_d_o->id = 3;
        if (cx_define(tc_classPrimitives_d_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::classPrimitives::d'.");
            goto error;
        }
    }
    /* Declare ::tc_stringser::classPrimitives::e */
    tc_classPrimitives_e_o = cx_declare(tc_classPrimitives_o, "e", cx_typedef(cx_member_o));
    if (!tc_classPrimitives_e_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::classPrimitives::e'.");
        goto error;
    }

    /* Define ::tc_stringser::classPrimitives::e */
    if (!cx_checkState(tc_classPrimitives_e_o, CX_DEFINED)) {
        tc_classPrimitives_e_o->type = cx_resolve_ext(tc_classPrimitives_e_o, NULL, "::cortex::lang::string", FALSE, "element ::tc_stringser::classPrimitives::e.type");
        tc_classPrimitives_e_o->modifiers = 0x0;
        tc_classPrimitives_e_o->state = 0x6;
        tc_classPrimitives_e_o->weak = FALSE;
        tc_classPrimitives_e_o->id = 4;
        if (cx_define(tc_classPrimitives_e_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::classPrimitives::e'.");
            goto error;
        }
    }
    /* Declare ::tc_stringser::classPrimitives::f */
    tc_classPrimitives_f_o = cx_declare(tc_classPrimitives_o, "f", cx_typedef(cx_member_o));
    if (!tc_classPrimitives_f_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::classPrimitives::f'.");
        goto error;
    }

    /* Declare ::tc_stringser::classPrimitives::g */
    tc_classPrimitives_g_o = cx_declare(tc_classPrimitives_o, "g", cx_typedef(cx_member_o));
    if (!tc_classPrimitives_g_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::classPrimitives::g'.");
        goto error;
    }

    /* Declare ::tc_stringser::listOfClassPrimitives */
    tc_listOfClassPrimitives_o = cx_declare(tc_o, "listOfClassPrimitives", cx_typedef(cx_typedef_o));
    if (!tc_listOfClassPrimitives_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::listOfClassPrimitives'.");
        goto error;
    }

    /* Define ::tc_stringser::listOfClassPrimitives */
    if (!cx_checkState(tc_listOfClassPrimitives_o, CX_DEFINED)) {
        tc_listOfClassPrimitives_o->type = cx_resolve_ext(tc_listOfClassPrimitives_o, NULL, "::cortex::lang::list{::tc_stringser::classPrimitives,3}", FALSE, "element ::tc_stringser::listOfClassPrimitives.type");
        if (cx_define(tc_listOfClassPrimitives_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::listOfClassPrimitives'.");
            goto error;
        }
    }
    /* Declare ::tc_stringser::sequenceOfClassPrimitives */
    tc_sequenceOfClassPrimitives_o = cx_declare(tc_o, "sequenceOfClassPrimitives", cx_typedef(cx_typedef_o));
    if (!tc_sequenceOfClassPrimitives_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::sequenceOfClassPrimitives'.");
        goto error;
    }

    /* Define ::tc_stringser::sequenceOfClassPrimitives */
    if (!cx_checkState(tc_sequenceOfClassPrimitives_o, CX_DEFINED)) {
        tc_sequenceOfClassPrimitives_o->type = cx_resolve_ext(tc_sequenceOfClassPrimitives_o, NULL, "::cortex::lang::sequence{::tc_stringser::classPrimitives,3}", FALSE, "element ::tc_stringser::sequenceOfClassPrimitives.type");
        if (cx_define(tc_sequenceOfClassPrimitives_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::sequenceOfClassPrimitives'.");
            goto error;
        }
    }
    /* Declare ::tc_stringser::color */
    tc_color_o = cx_declare(tc_o, "color", cx_typedef(cx_enum_o));
    if (!tc_color_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::color'.");
        goto error;
    }

    /* Declare ::tc_stringser::color::BLUE */
    tc_color_BLUE_o = cx_declare(tc_color_o, "BLUE", cx_typedef(cx_constant_o));
    if (!tc_color_BLUE_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::color::BLUE'.");
        goto error;
    }

    /* Define ::tc_stringser::color::BLUE */
    if (!cx_checkState(tc_color_BLUE_o, CX_DEFINED)) {
        (*tc_color_BLUE_o) = 2;
        if (cx_define(tc_color_BLUE_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::color::BLUE'.");
            goto error;
        }
    }
    /* Declare ::tc_stringser::color::RED */
    tc_color_RED_o = cx_declare(tc_color_o, "RED", cx_typedef(cx_constant_o));
    if (!tc_color_RED_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::color::RED'.");
        goto error;
    }

    /* Define ::tc_stringser::color::RED */
    if (!cx_checkState(tc_color_RED_o, CX_DEFINED)) {
        (*tc_color_RED_o) = 0;
        if (cx_define(tc_color_RED_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::color::RED'.");
            goto error;
        }
    }
    /* Declare ::tc_stringser::color::YELLOW */
    tc_color_YELLOW_o = cx_declare(tc_color_o, "YELLOW", cx_typedef(cx_constant_o));
    if (!tc_color_YELLOW_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::color::YELLOW'.");
        goto error;
    }

    /* Define ::tc_stringser::color::YELLOW */
    if (!cx_checkState(tc_color_YELLOW_o, CX_DEFINED)) {
        (*tc_color_YELLOW_o) = 1;
        if (cx_define(tc_color_YELLOW_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::color::YELLOW'.");
            goto error;
        }
    }
    /* Define ::tc_stringser::color */
    if (!cx_checkState(tc_color_o, CX_DEFINED)) {
        if (cx_define(tc_color_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::color'.");
            goto error;
        }
    }
    /* Define ::tc_stringser::classInherit::f */
    if (!cx_checkState(tc_classInherit_f_o, CX_DEFINED)) {
        tc_classInherit_f_o->type = cx_resolve_ext(tc_classInherit_f_o, NULL, "::tc_stringser::color", FALSE, "element ::tc_stringser::classInherit::f.type");
        tc_classInherit_f_o->modifiers = 0x0;
        tc_classInherit_f_o->state = 0x6;
        tc_classInherit_f_o->weak = FALSE;
        tc_classInherit_f_o->id = 5;
        if (cx_define(tc_classInherit_f_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::classInherit::f'.");
            goto error;
        }
    }
    /* Define ::tc_stringser::classPrimitives::f */
    if (!cx_checkState(tc_classPrimitives_f_o, CX_DEFINED)) {
        tc_classPrimitives_f_o->type = cx_resolve_ext(tc_classPrimitives_f_o, NULL, "::tc_stringser::color", FALSE, "element ::tc_stringser::classPrimitives::f.type");
        tc_classPrimitives_f_o->modifiers = 0x0;
        tc_classPrimitives_f_o->state = 0x6;
        tc_classPrimitives_f_o->weak = FALSE;
        tc_classPrimitives_f_o->id = 5;
        if (cx_define(tc_classPrimitives_f_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::classPrimitives::f'.");
            goto error;
        }
    }
    /* Define ::tc_stringser::arrayOfColor */
    if (!cx_checkState(tc_arrayOfColor_o, CX_DEFINED)) {
        tc_arrayOfColor_o->type = cx_resolve_ext(tc_arrayOfColor_o, NULL, "::cortex::lang::array{::tc_stringser::color,3,::tc_stringser::color}", FALSE, "element ::tc_stringser::arrayOfColor.type");
        if (cx_define(tc_arrayOfColor_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::arrayOfColor'.");
            goto error;
        }
    }
    /* Declare ::tc_stringser::listOfColor */
    tc_listOfColor_o = cx_declare(tc_o, "listOfColor", cx_typedef(cx_typedef_o));
    if (!tc_listOfColor_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::listOfColor'.");
        goto error;
    }

    /* Define ::tc_stringser::listOfColor */
    if (!cx_checkState(tc_listOfColor_o, CX_DEFINED)) {
        tc_listOfColor_o->type = cx_resolve_ext(tc_listOfColor_o, NULL, "::cortex::lang::list{::tc_stringser::color,3}", FALSE, "element ::tc_stringser::listOfColor.type");
        if (cx_define(tc_listOfColor_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::listOfColor'.");
            goto error;
        }
    }
    /* Declare ::tc_stringser::sequenceOfColor */
    tc_sequenceOfColor_o = cx_declare(tc_o, "sequenceOfColor", cx_typedef(cx_typedef_o));
    if (!tc_sequenceOfColor_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::sequenceOfColor'.");
        goto error;
    }

    /* Define ::tc_stringser::sequenceOfColor */
    if (!cx_checkState(tc_sequenceOfColor_o, CX_DEFINED)) {
        tc_sequenceOfColor_o->type = cx_resolve_ext(tc_sequenceOfColor_o, NULL, "::cortex::lang::sequence{::tc_stringser::color,3}", FALSE, "element ::tc_stringser::sequenceOfColor.type");
        if (cx_define(tc_sequenceOfColor_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::sequenceOfColor'.");
            goto error;
        }
    }
    /* Declare ::tc_stringser::listOfBool */
    tc_listOfBool_o = cx_declare(tc_o, "listOfBool", cx_typedef(cx_typedef_o));
    if (!tc_listOfBool_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::listOfBool'.");
        goto error;
    }

    /* Declare ::tc_stringser::listOfChar */
    tc_listOfChar_o = cx_declare(tc_o, "listOfChar", cx_typedef(cx_typedef_o));
    if (!tc_listOfChar_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::listOfChar'.");
        goto error;
    }

    /* Declare ::tc_stringser::listOfFloat */
    tc_listOfFloat_o = cx_declare(tc_o, "listOfFloat", cx_typedef(cx_typedef_o));
    if (!tc_listOfFloat_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::listOfFloat'.");
        goto error;
    }

    /* Declare ::tc_stringser::listOfInt */
    tc_listOfInt_o = cx_declare(tc_o, "listOfInt", cx_typedef(cx_typedef_o));
    if (!tc_listOfInt_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::listOfInt'.");
        goto error;
    }

    /* Declare ::tc_stringser::listOfMoveMode */
    tc_listOfMoveMode_o = cx_declare(tc_o, "listOfMoveMode", cx_typedef(cx_typedef_o));
    if (!tc_listOfMoveMode_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::listOfMoveMode'.");
        goto error;
    }

    /* Declare ::tc_stringser::listOfString */
    tc_listOfString_o = cx_declare(tc_o, "listOfString", cx_typedef(cx_typedef_o));
    if (!tc_listOfString_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::listOfString'.");
        goto error;
    }

    /* Declare ::tc_stringser::moveMode */
    tc_moveMode_o = cx_declare(tc_o, "moveMode", cx_typedef(cx_bitmask_o));
    if (!tc_moveMode_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::moveMode'.");
        goto error;
    }

    /* Declare ::tc_stringser::moveMode::FLY */
    tc_moveMode_FLY_o = cx_declare(tc_moveMode_o, "FLY", cx_typedef(cx_constant_o));
    if (!tc_moveMode_FLY_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::moveMode::FLY'.");
        goto error;
    }

    /* Define ::tc_stringser::moveMode::FLY */
    if (!cx_checkState(tc_moveMode_FLY_o, CX_DEFINED)) {
        (*tc_moveMode_FLY_o) = 4;
        if (cx_define(tc_moveMode_FLY_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::moveMode::FLY'.");
            goto error;
        }
    }
    /* Declare ::tc_stringser::moveMode::SWIM */
    tc_moveMode_SWIM_o = cx_declare(tc_moveMode_o, "SWIM", cx_typedef(cx_constant_o));
    if (!tc_moveMode_SWIM_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::moveMode::SWIM'.");
        goto error;
    }

    /* Define ::tc_stringser::moveMode::SWIM */
    if (!cx_checkState(tc_moveMode_SWIM_o, CX_DEFINED)) {
        (*tc_moveMode_SWIM_o) = 2;
        if (cx_define(tc_moveMode_SWIM_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::moveMode::SWIM'.");
            goto error;
        }
    }
    /* Declare ::tc_stringser::moveMode::WALK */
    tc_moveMode_WALK_o = cx_declare(tc_moveMode_o, "WALK", cx_typedef(cx_constant_o));
    if (!tc_moveMode_WALK_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::moveMode::WALK'.");
        goto error;
    }

    /* Define ::tc_stringser::moveMode::WALK */
    if (!cx_checkState(tc_moveMode_WALK_o, CX_DEFINED)) {
        (*tc_moveMode_WALK_o) = 1;
        if (cx_define(tc_moveMode_WALK_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::moveMode::WALK'.");
            goto error;
        }
    }
    /* Define ::tc_stringser::moveMode */
    if (!cx_checkState(tc_moveMode_o, CX_DEFINED)) {
        if (cx_define(tc_moveMode_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::moveMode'.");
            goto error;
        }
    }
    /* Define ::tc_stringser::classInherit::g */
    if (!cx_checkState(tc_classInherit_g_o, CX_DEFINED)) {
        tc_classInherit_g_o->type = cx_resolve_ext(tc_classInherit_g_o, NULL, "::tc_stringser::moveMode", FALSE, "element ::tc_stringser::classInherit::g.type");
        tc_classInherit_g_o->modifiers = 0x0;
        tc_classInherit_g_o->state = 0x6;
        tc_classInherit_g_o->weak = FALSE;
        tc_classInherit_g_o->id = 6;
        if (cx_define(tc_classInherit_g_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::classInherit::g'.");
            goto error;
        }
    }
    /* Define ::tc_stringser::classPrimitives::g */
    if (!cx_checkState(tc_classPrimitives_g_o, CX_DEFINED)) {
        tc_classPrimitives_g_o->type = cx_resolve_ext(tc_classPrimitives_g_o, NULL, "::tc_stringser::moveMode", FALSE, "element ::tc_stringser::classPrimitives::g.type");
        tc_classPrimitives_g_o->modifiers = 0x0;
        tc_classPrimitives_g_o->state = 0x6;
        tc_classPrimitives_g_o->weak = FALSE;
        tc_classPrimitives_g_o->id = 6;
        if (cx_define(tc_classPrimitives_g_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::classPrimitives::g'.");
            goto error;
        }
    }
    /* Define ::tc_stringser::classPrimitives */
    if (!cx_checkState(tc_classPrimitives_o, CX_DEFINED)) {
        cx_type(tc_classPrimitives_o)->parentType = NULL;
        cx_type(tc_classPrimitives_o)->parentState = 0x0;
        cx_interface(tc_classPrimitives_o)->base = NULL;
        cx_struct(tc_classPrimitives_o)->baseAccess = 0x0;
        tc_classPrimitives_o->implements.length = 0;
        tc_classPrimitives_o->implements.buffer = NULL;
        if (cx_define(tc_classPrimitives_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::classPrimitives'.");
            goto error;
        }
    }
    /* Define ::tc_stringser::classInherit */
    if (!cx_checkState(tc_classInherit_o, CX_DEFINED)) {
        cx_type(tc_classInherit_o)->parentType = NULL;
        cx_type(tc_classInherit_o)->parentState = 0x0;
        cx_interface(tc_classInherit_o)->base = cx_resolve_ext(tc_classInherit_o, NULL, "::tc_stringser::classPrimitives", FALSE, "element ::tc_stringser::classInherit.base");
        cx_struct(tc_classInherit_o)->baseAccess = 0x0;
        tc_classInherit_o->implements.length = 0;
        tc_classInherit_o->implements.buffer = NULL;
        if (cx_define(tc_classInherit_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::classInherit'.");
            goto error;
        }
    }
    /* Define ::tc_stringser::classNested::b */
    if (!cx_checkState(tc_classNested_b_o, CX_DEFINED)) {
        tc_classNested_b_o->type = cx_resolve_ext(tc_classNested_b_o, NULL, "::tc_stringser::classInherit", FALSE, "element ::tc_stringser::classNested::b.type");
        tc_classNested_b_o->modifiers = 0x0;
        tc_classNested_b_o->state = 0x6;
        tc_classNested_b_o->weak = FALSE;
        tc_classNested_b_o->id = 1;
        if (cx_define(tc_classNested_b_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::classNested::b'.");
            goto error;
        }
    }
    /* Define ::tc_stringser::arrayOfClassInherit */
    if (!cx_checkState(tc_arrayOfClassInherit_o, CX_DEFINED)) {
        tc_arrayOfClassInherit_o->type = cx_resolve_ext(tc_arrayOfClassInherit_o, NULL, "::cortex::lang::array{::tc_stringser::classInherit,3,::tc_stringser::classInherit}", FALSE, "element ::tc_stringser::arrayOfClassInherit.type");
        if (cx_define(tc_arrayOfClassInherit_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::arrayOfClassInherit'.");
            goto error;
        }
    }
    /* Define ::tc_stringser::classCompositeCollection::a */
    if (!cx_checkState(tc_classCompositeCollection_a_o, CX_DEFINED)) {
        tc_classCompositeCollection_a_o->type = cx_resolve_ext(tc_classCompositeCollection_a_o, NULL, "::tc_stringser::arrayOfClassInherit", FALSE, "element ::tc_stringser::classCompositeCollection::a.type");
        tc_classCompositeCollection_a_o->modifiers = 0x0;
        tc_classCompositeCollection_a_o->state = 0x6;
        tc_classCompositeCollection_a_o->weak = FALSE;
        tc_classCompositeCollection_a_o->id = 0;
        if (cx_define(tc_classCompositeCollection_a_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::classCompositeCollection::a'.");
            goto error;
        }
    }
    /* Define ::tc_stringser::classNested::a */
    if (!cx_checkState(tc_classNested_a_o, CX_DEFINED)) {
        tc_classNested_a_o->type = cx_resolve_ext(tc_classNested_a_o, NULL, "::tc_stringser::classPrimitives", FALSE, "element ::tc_stringser::classNested::a.type");
        tc_classNested_a_o->modifiers = 0x0;
        tc_classNested_a_o->state = 0x6;
        tc_classNested_a_o->weak = FALSE;
        tc_classNested_a_o->id = 0;
        if (cx_define(tc_classNested_a_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::classNested::a'.");
            goto error;
        }
    }
    /* Define ::tc_stringser::arrayOfClassPrimitives */
    if (!cx_checkState(tc_arrayOfClassPrimitives_o, CX_DEFINED)) {
        tc_arrayOfClassPrimitives_o->type = cx_resolve_ext(tc_arrayOfClassPrimitives_o, NULL, "::cortex::lang::array{::tc_stringser::classPrimitives,3,::tc_stringser::classPrimitives}", FALSE, "element ::tc_stringser::arrayOfClassPrimitives.type");
        if (cx_define(tc_arrayOfClassPrimitives_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::arrayOfClassPrimitives'.");
            goto error;
        }
    }
    /* Define ::tc_stringser::arrayOfMoveMode */
    if (!cx_checkState(tc_arrayOfMoveMode_o, CX_DEFINED)) {
        tc_arrayOfMoveMode_o->type = cx_resolve_ext(tc_arrayOfMoveMode_o, NULL, "::cortex::lang::array{::tc_stringser::moveMode,3,::tc_stringser::moveMode}", FALSE, "element ::tc_stringser::arrayOfMoveMode.type");
        if (cx_define(tc_arrayOfMoveMode_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::arrayOfMoveMode'.");
            goto error;
        }
    }
    /* Define ::tc_stringser::listOfMoveMode */
    if (!cx_checkState(tc_listOfMoveMode_o, CX_DEFINED)) {
        tc_listOfMoveMode_o->type = cx_resolve_ext(tc_listOfMoveMode_o, NULL, "::cortex::lang::list{::tc_stringser::moveMode,3}", FALSE, "element ::tc_stringser::listOfMoveMode.type");
        if (cx_define(tc_listOfMoveMode_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::listOfMoveMode'.");
            goto error;
        }
    }
    /* Declare ::tc_stringser::sequenceOfMoveMode */
    tc_sequenceOfMoveMode_o = cx_declare(tc_o, "sequenceOfMoveMode", cx_typedef(cx_typedef_o));
    if (!tc_sequenceOfMoveMode_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::sequenceOfMoveMode'.");
        goto error;
    }

    /* Define ::tc_stringser::sequenceOfMoveMode */
    if (!cx_checkState(tc_sequenceOfMoveMode_o, CX_DEFINED)) {
        tc_sequenceOfMoveMode_o->type = cx_resolve_ext(tc_sequenceOfMoveMode_o, NULL, "::cortex::lang::sequence{::tc_stringser::moveMode,3}", FALSE, "element ::tc_stringser::sequenceOfMoveMode.type");
        if (cx_define(tc_sequenceOfMoveMode_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::sequenceOfMoveMode'.");
            goto error;
        }
    }
    /* Declare ::tc_stringser::sequenceOfBool */
    tc_sequenceOfBool_o = cx_declare(tc_o, "sequenceOfBool", cx_typedef(cx_typedef_o));
    if (!tc_sequenceOfBool_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::sequenceOfBool'.");
        goto error;
    }

    /* Declare ::tc_stringser::sequenceOfChar */
    tc_sequenceOfChar_o = cx_declare(tc_o, "sequenceOfChar", cx_typedef(cx_typedef_o));
    if (!tc_sequenceOfChar_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::sequenceOfChar'.");
        goto error;
    }

    /* Declare ::tc_stringser::sequenceOfFloat */
    tc_sequenceOfFloat_o = cx_declare(tc_o, "sequenceOfFloat", cx_typedef(cx_typedef_o));
    if (!tc_sequenceOfFloat_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::sequenceOfFloat'.");
        goto error;
    }

    /* Declare ::tc_stringser::sequenceOfInt */
    tc_sequenceOfInt_o = cx_declare(tc_o, "sequenceOfInt", cx_typedef(cx_typedef_o));
    if (!tc_sequenceOfInt_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::sequenceOfInt'.");
        goto error;
    }

    /* Declare ::tc_stringser::sequenceOfString */
    tc_sequenceOfString_o = cx_declare(tc_o, "sequenceOfString", cx_typedef(cx_typedef_o));
    if (!tc_sequenceOfString_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::sequenceOfString'.");
        goto error;
    }

    /* Define ::tc_stringser::arrayOfBool */
    if (!cx_checkState(tc_arrayOfBool_o, CX_DEFINED)) {
        tc_arrayOfBool_o->type = cx_resolve_ext(tc_arrayOfBool_o, NULL, "::cortex::lang::array{::cortex::lang::bool,3,::cortex::lang::bool}", FALSE, "element ::tc_stringser::arrayOfBool.type");
        if (cx_define(tc_arrayOfBool_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::arrayOfBool'.");
            goto error;
        }
    }
    /* Define ::tc_stringser::arrayOfChar */
    if (!cx_checkState(tc_arrayOfChar_o, CX_DEFINED)) {
        tc_arrayOfChar_o->type = cx_resolve_ext(tc_arrayOfChar_o, NULL, "::cortex::lang::array{::cortex::lang::char,3,::cortex::lang::char}", FALSE, "element ::tc_stringser::arrayOfChar.type");
        if (cx_define(tc_arrayOfChar_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::arrayOfChar'.");
            goto error;
        }
    }
    /* Define ::tc_stringser::arrayOfFloat */
    if (!cx_checkState(tc_arrayOfFloat_o, CX_DEFINED)) {
        tc_arrayOfFloat_o->type = cx_resolve_ext(tc_arrayOfFloat_o, NULL, "::cortex::lang::array{::cortex::lang::float32,3,::cortex::lang::float32}", FALSE, "element ::tc_stringser::arrayOfFloat.type");
        if (cx_define(tc_arrayOfFloat_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::arrayOfFloat'.");
            goto error;
        }
    }
    /* Define ::tc_stringser::arrayOfInt */
    if (!cx_checkState(tc_arrayOfInt_o, CX_DEFINED)) {
        tc_arrayOfInt_o->type = cx_resolve_ext(tc_arrayOfInt_o, NULL, "::cortex::lang::array{::cortex::lang::int32,3,::cortex::lang::int32}", FALSE, "element ::tc_stringser::arrayOfInt.type");
        if (cx_define(tc_arrayOfInt_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::arrayOfInt'.");
            goto error;
        }
    }
    /* Define ::tc_stringser::classNested::c */
    if (!cx_checkState(tc_classNested_c_o, CX_DEFINED)) {
        tc_classNested_c_o->type = cx_resolve_ext(tc_classNested_c_o, NULL, "::tc_stringser::arrayOfInt", FALSE, "element ::tc_stringser::classNested::c.type");
        tc_classNested_c_o->modifiers = 0x0;
        tc_classNested_c_o->state = 0x6;
        tc_classNested_c_o->weak = FALSE;
        tc_classNested_c_o->id = 2;
        if (cx_define(tc_classNested_c_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::classNested::c'.");
            goto error;
        }
    }
    /* Define ::tc_stringser::arrayOfString */
    if (!cx_checkState(tc_arrayOfString_o, CX_DEFINED)) {
        tc_arrayOfString_o->type = cx_resolve_ext(tc_arrayOfString_o, NULL, "::cortex::lang::array{::cortex::lang::string,3,::cortex::lang::string}", FALSE, "element ::tc_stringser::arrayOfString.type");
        if (cx_define(tc_arrayOfString_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::arrayOfString'.");
            goto error;
        }
    }
    /* Define ::tc_stringser::listOfBool */
    if (!cx_checkState(tc_listOfBool_o, CX_DEFINED)) {
        tc_listOfBool_o->type = cx_resolve_ext(tc_listOfBool_o, NULL, "::cortex::lang::list{::cortex::lang::bool,3}", FALSE, "element ::tc_stringser::listOfBool.type");
        if (cx_define(tc_listOfBool_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::listOfBool'.");
            goto error;
        }
    }
    /* Define ::tc_stringser::listOfChar */
    if (!cx_checkState(tc_listOfChar_o, CX_DEFINED)) {
        tc_listOfChar_o->type = cx_resolve_ext(tc_listOfChar_o, NULL, "::cortex::lang::list{::cortex::lang::char,3}", FALSE, "element ::tc_stringser::listOfChar.type");
        if (cx_define(tc_listOfChar_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::listOfChar'.");
            goto error;
        }
    }
    /* Define ::tc_stringser::listOfFloat */
    if (!cx_checkState(tc_listOfFloat_o, CX_DEFINED)) {
        tc_listOfFloat_o->type = cx_resolve_ext(tc_listOfFloat_o, NULL, "::cortex::lang::list{::cortex::lang::float32,3}", FALSE, "element ::tc_stringser::listOfFloat.type");
        if (cx_define(tc_listOfFloat_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::listOfFloat'.");
            goto error;
        }
    }
    /* Define ::tc_stringser::listOfInt */
    if (!cx_checkState(tc_listOfInt_o, CX_DEFINED)) {
        tc_listOfInt_o->type = cx_resolve_ext(tc_listOfInt_o, NULL, "::cortex::lang::list{::cortex::lang::int32,3}", FALSE, "element ::tc_stringser::listOfInt.type");
        if (cx_define(tc_listOfInt_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::listOfInt'.");
            goto error;
        }
    }
    /* Define ::tc_stringser::classNested::e */
    if (!cx_checkState(tc_classNested_e_o, CX_DEFINED)) {
        tc_classNested_e_o->type = cx_resolve_ext(tc_classNested_e_o, NULL, "::tc_stringser::listOfInt", FALSE, "element ::tc_stringser::classNested::e.type");
        tc_classNested_e_o->modifiers = 0x0;
        tc_classNested_e_o->state = 0x6;
        tc_classNested_e_o->weak = FALSE;
        tc_classNested_e_o->id = 4;
        if (cx_define(tc_classNested_e_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::classNested::e'.");
            goto error;
        }
    }
    /* Define ::tc_stringser::listOfString */
    if (!cx_checkState(tc_listOfString_o, CX_DEFINED)) {
        tc_listOfString_o->type = cx_resolve_ext(tc_listOfString_o, NULL, "::cortex::lang::list{::cortex::lang::string,3}", FALSE, "element ::tc_stringser::listOfString.type");
        if (cx_define(tc_listOfString_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::listOfString'.");
            goto error;
        }
    }
    /* Define ::tc_stringser::sequenceOfBool */
    if (!cx_checkState(tc_sequenceOfBool_o, CX_DEFINED)) {
        tc_sequenceOfBool_o->type = cx_resolve_ext(tc_sequenceOfBool_o, NULL, "::cortex::lang::sequence{::cortex::lang::bool,3}", FALSE, "element ::tc_stringser::sequenceOfBool.type");
        if (cx_define(tc_sequenceOfBool_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::sequenceOfBool'.");
            goto error;
        }
    }
    /* Define ::tc_stringser::sequenceOfChar */
    if (!cx_checkState(tc_sequenceOfChar_o, CX_DEFINED)) {
        tc_sequenceOfChar_o->type = cx_resolve_ext(tc_sequenceOfChar_o, NULL, "::cortex::lang::sequence{::cortex::lang::char,3}", FALSE, "element ::tc_stringser::sequenceOfChar.type");
        if (cx_define(tc_sequenceOfChar_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::sequenceOfChar'.");
            goto error;
        }
    }
    /* Define ::tc_stringser::sequenceOfFloat */
    if (!cx_checkState(tc_sequenceOfFloat_o, CX_DEFINED)) {
        tc_sequenceOfFloat_o->type = cx_resolve_ext(tc_sequenceOfFloat_o, NULL, "::cortex::lang::sequence{::cortex::lang::float32,3}", FALSE, "element ::tc_stringser::sequenceOfFloat.type");
        if (cx_define(tc_sequenceOfFloat_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::sequenceOfFloat'.");
            goto error;
        }
    }
    /* Define ::tc_stringser::sequenceOfInt */
    if (!cx_checkState(tc_sequenceOfInt_o, CX_DEFINED)) {
        tc_sequenceOfInt_o->type = cx_resolve_ext(tc_sequenceOfInt_o, NULL, "::cortex::lang::sequence{::cortex::lang::int32,3}", FALSE, "element ::tc_stringser::sequenceOfInt.type");
        if (cx_define(tc_sequenceOfInt_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::sequenceOfInt'.");
            goto error;
        }
    }
    /* Define ::tc_stringser::classNested::d */
    if (!cx_checkState(tc_classNested_d_o, CX_DEFINED)) {
        tc_classNested_d_o->type = cx_resolve_ext(tc_classNested_d_o, NULL, "::tc_stringser::sequenceOfInt", FALSE, "element ::tc_stringser::classNested::d.type");
        tc_classNested_d_o->modifiers = 0x0;
        tc_classNested_d_o->state = 0x6;
        tc_classNested_d_o->weak = FALSE;
        tc_classNested_d_o->id = 3;
        if (cx_define(tc_classNested_d_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::classNested::d'.");
            goto error;
        }
    }
    /* Define ::tc_stringser::classNested */
    if (!cx_checkState(tc_classNested_o, CX_DEFINED)) {
        cx_type(tc_classNested_o)->parentType = NULL;
        cx_type(tc_classNested_o)->parentState = 0x0;
        cx_interface(tc_classNested_o)->base = NULL;
        cx_struct(tc_classNested_o)->baseAccess = 0x0;
        tc_classNested_o->implements.length = 0;
        tc_classNested_o->implements.buffer = NULL;
        if (cx_define(tc_classNested_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::classNested'.");
            goto error;
        }
    }
    /* Define ::tc_stringser::arrayOfClassNested */
    if (!cx_checkState(tc_arrayOfClassNested_o, CX_DEFINED)) {
        tc_arrayOfClassNested_o->type = cx_resolve_ext(tc_arrayOfClassNested_o, NULL, "::cortex::lang::array{::tc_stringser::classNested,3,::tc_stringser::classNested}", FALSE, "element ::tc_stringser::arrayOfClassNested.type");
        if (cx_define(tc_arrayOfClassNested_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::arrayOfClassNested'.");
            goto error;
        }
    }
    /* Define ::tc_stringser::classCompositeCollection::b */
    if (!cx_checkState(tc_classCompositeCollection_b_o, CX_DEFINED)) {
        tc_classCompositeCollection_b_o->type = cx_resolve_ext(tc_classCompositeCollection_b_o, NULL, "::tc_stringser::arrayOfClassNested", FALSE, "element ::tc_stringser::classCompositeCollection::b.type");
        tc_classCompositeCollection_b_o->modifiers = 0x0;
        tc_classCompositeCollection_b_o->state = 0x6;
        tc_classCompositeCollection_b_o->weak = FALSE;
        tc_classCompositeCollection_b_o->id = 1;
        if (cx_define(tc_classCompositeCollection_b_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::classCompositeCollection::b'.");
            goto error;
        }
    }
    /* Define ::tc_stringser::classCompositeCollection */
    if (!cx_checkState(tc_classCompositeCollection_o, CX_DEFINED)) {
        cx_type(tc_classCompositeCollection_o)->parentType = NULL;
        cx_type(tc_classCompositeCollection_o)->parentState = 0x0;
        cx_interface(tc_classCompositeCollection_o)->base = NULL;
        cx_struct(tc_classCompositeCollection_o)->baseAccess = 0x0;
        tc_classCompositeCollection_o->implements.length = 0;
        tc_classCompositeCollection_o->implements.buffer = NULL;
        if (cx_define(tc_classCompositeCollection_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::classCompositeCollection'.");
            goto error;
        }
    }
    /* Define ::tc_stringser::sequenceOfString */
    if (!cx_checkState(tc_sequenceOfString_o, CX_DEFINED)) {
        tc_sequenceOfString_o->type = cx_resolve_ext(tc_sequenceOfString_o, NULL, "::cortex::lang::sequence{::cortex::lang::string,3}", FALSE, "element ::tc_stringser::sequenceOfString.type");
        if (cx_define(tc_sequenceOfString_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::sequenceOfString'.");
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
