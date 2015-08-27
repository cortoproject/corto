/* tc_stringser__meta.c
 *
 * Loads objects in database.
 * This file contains generated code. Do not modify!
 */

#include "tc_stringser__type.h"

/* Variable definitions */
cx_object tc_stringser_o;
cx_array tc_stringser_arrayOfBool_o;
cx_array tc_stringser_arrayOfChar_o;
cx_array tc_stringser_arrayOfClassInherit_o;
cx_array tc_stringser_arrayOfClassNested_o;
cx_array tc_stringser_arrayOfClassPrimitives_o;
cx_array tc_stringser_arrayOfColor_o;
cx_array tc_stringser_arrayOfFloat_o;
cx_array tc_stringser_arrayOfInt_o;
cx_array tc_stringser_arrayOfMoveMode_o;
cx_array tc_stringser_arrayOfString_o;
cx_class tc_stringser_classCompositeCollection_o;
cx_member tc_stringser_classCompositeCollection_a_o;
cx_member tc_stringser_classCompositeCollection_b_o;
cx_member tc_stringser_classCompositeCollection_c_o;
cx_member tc_stringser_classCompositeCollection_d_o;
cx_member tc_stringser_classCompositeCollection_e_o;
cx_class tc_stringser_classInherit_o;
cx_member tc_stringser_classInherit_a_o;
cx_member tc_stringser_classInherit_b_o;
cx_member tc_stringser_classInherit_c_o;
cx_member tc_stringser_classInherit_d_o;
cx_member tc_stringser_classInherit_e_o;
cx_member tc_stringser_classInherit_f_o;
cx_member tc_stringser_classInherit_g_o;
cx_class tc_stringser_classNested_o;
cx_member tc_stringser_classNested_a_o;
cx_member tc_stringser_classNested_b_o;
cx_member tc_stringser_classNested_c_o;
cx_member tc_stringser_classNested_d_o;
cx_member tc_stringser_classNested_e_o;
cx_class tc_stringser_classPrimitives_o;
cx_member tc_stringser_classPrimitives_a_o;
cx_member tc_stringser_classPrimitives_b_o;
cx_member tc_stringser_classPrimitives_c_o;
cx_member tc_stringser_classPrimitives_d_o;
cx_member tc_stringser_classPrimitives_e_o;
cx_member tc_stringser_classPrimitives_f_o;
cx_member tc_stringser_classPrimitives_g_o;
cx_enum tc_stringser_color_o;
cx_constant (*tc_stringser_color_BLUE_o);
cx_constant (*tc_stringser_color_RED_o);
cx_constant (*tc_stringser_color_YELLOW_o);
cx_list tc_stringser_listOfBool_o;
cx_list tc_stringser_listOfChar_o;
cx_list tc_stringser_listOfClassInherit_o;
cx_list tc_stringser_listOfClassNested_o;
cx_list tc_stringser_listOfClassPrimitives_o;
cx_list tc_stringser_listOfColor_o;
cx_list tc_stringser_listOfFloat_o;
cx_list tc_stringser_listOfInt_o;
cx_list tc_stringser_listOfMoveMode_o;
cx_list tc_stringser_listOfString_o;
cx_bitmask tc_stringser_moveMode_o;
cx_constant (*tc_stringser_moveMode_FLY_o);
cx_constant (*tc_stringser_moveMode_SWIM_o);
cx_constant (*tc_stringser_moveMode_WALK_o);
cx_sequence tc_stringser_sequenceOfBool_o;
cx_sequence tc_stringser_sequenceOfChar_o;
cx_sequence tc_stringser_sequenceOfClassInherit_o;
cx_sequence tc_stringser_sequenceOfClassNested_o;
cx_sequence tc_stringser_sequenceOfClassPrimitives_o;
cx_sequence tc_stringser_sequenceOfColor_o;
cx_sequence tc_stringser_sequenceOfFloat_o;
cx_sequence tc_stringser_sequenceOfInt_o;
cx_sequence tc_stringser_sequenceOfMoveMode_o;
cx_sequence tc_stringser_sequenceOfString_o;

/* Load objects in database */
int tc_stringser_load(void) {
    cx_object _a_; /* Used for resolving anonymous objects */
    _a_ = NULL;

    /* Declare ::tc_stringser */
    tc_stringser_o = cx_declareChild(root_o, "tc_stringser", cx_type(cx_object_o));
    if (!tc_stringser_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser'.");
        goto error;
    }

    /* Define ::tc_stringser */
    if (!cx_checkState(tc_stringser_o, CX_DEFINED)) {
        if (cx_define(tc_stringser_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser'.");
            goto error;
        }
    }

    /* Declare ::tc_stringser::arrayOfBool */
    tc_stringser_arrayOfBool_o = cx_declareChild(tc_stringser_o, "arrayOfBool", cx_type(cx_array_o));
    if (!tc_stringser_arrayOfBool_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::arrayOfBool'.");
        goto error;
    }

    /* Define ::tc_stringser::arrayOfBool */
    if (!cx_checkState(tc_stringser_arrayOfBool_o, CX_DEFINED)) {
        cx_collection(tc_stringser_arrayOfBool_o)->elementType = cx_resolve_ext(tc_stringser_arrayOfBool_o, NULL, "::corto::lang::bool", FALSE, "element ::tc_stringser::arrayOfBool.elementType");
        cx_collection(tc_stringser_arrayOfBool_o)->max = 3;
        tc_stringser_arrayOfBool_o->elementType = cx_resolve_ext(tc_stringser_arrayOfBool_o, NULL, "::corto::lang::bool", FALSE, "element ::tc_stringser::arrayOfBool.elementType");
        if (cx_define(tc_stringser_arrayOfBool_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::arrayOfBool'.");
            goto error;
        }
    }

    if (cx_type(tc_stringser_arrayOfBool_o)->size != sizeof(tc_stringser_arrayOfBool)) {
        cx_error("tc_stringser_load: calculated size '%d' of type '::tc_stringser::arrayOfBool' doesn't match C-type size '%d'", cx_type(tc_stringser_arrayOfBool_o)->size, sizeof(tc_stringser_arrayOfBool));
    }

    /* Declare ::tc_stringser::arrayOfChar */
    tc_stringser_arrayOfChar_o = cx_declareChild(tc_stringser_o, "arrayOfChar", cx_type(cx_array_o));
    if (!tc_stringser_arrayOfChar_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::arrayOfChar'.");
        goto error;
    }

    /* Define ::tc_stringser::arrayOfChar */
    if (!cx_checkState(tc_stringser_arrayOfChar_o, CX_DEFINED)) {
        cx_collection(tc_stringser_arrayOfChar_o)->elementType = cx_resolve_ext(tc_stringser_arrayOfChar_o, NULL, "::corto::lang::char", FALSE, "element ::tc_stringser::arrayOfChar.elementType");
        cx_collection(tc_stringser_arrayOfChar_o)->max = 3;
        tc_stringser_arrayOfChar_o->elementType = cx_resolve_ext(tc_stringser_arrayOfChar_o, NULL, "::corto::lang::char", FALSE, "element ::tc_stringser::arrayOfChar.elementType");
        if (cx_define(tc_stringser_arrayOfChar_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::arrayOfChar'.");
            goto error;
        }
    }

    if (cx_type(tc_stringser_arrayOfChar_o)->size != sizeof(tc_stringser_arrayOfChar)) {
        cx_error("tc_stringser_load: calculated size '%d' of type '::tc_stringser::arrayOfChar' doesn't match C-type size '%d'", cx_type(tc_stringser_arrayOfChar_o)->size, sizeof(tc_stringser_arrayOfChar));
    }

    /* Declare ::tc_stringser::arrayOfClassInherit */
    tc_stringser_arrayOfClassInherit_o = cx_declareChild(tc_stringser_o, "arrayOfClassInherit", cx_type(cx_array_o));
    if (!tc_stringser_arrayOfClassInherit_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::arrayOfClassInherit'.");
        goto error;
    }

    /* Declare ::tc_stringser::arrayOfClassNested */
    tc_stringser_arrayOfClassNested_o = cx_declareChild(tc_stringser_o, "arrayOfClassNested", cx_type(cx_array_o));
    if (!tc_stringser_arrayOfClassNested_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::arrayOfClassNested'.");
        goto error;
    }

    /* Declare ::tc_stringser::arrayOfClassPrimitives */
    tc_stringser_arrayOfClassPrimitives_o = cx_declareChild(tc_stringser_o, "arrayOfClassPrimitives", cx_type(cx_array_o));
    if (!tc_stringser_arrayOfClassPrimitives_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::arrayOfClassPrimitives'.");
        goto error;
    }

    /* Declare ::tc_stringser::arrayOfColor */
    tc_stringser_arrayOfColor_o = cx_declareChild(tc_stringser_o, "arrayOfColor", cx_type(cx_array_o));
    if (!tc_stringser_arrayOfColor_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::arrayOfColor'.");
        goto error;
    }

    /* Declare ::tc_stringser::arrayOfFloat */
    tc_stringser_arrayOfFloat_o = cx_declareChild(tc_stringser_o, "arrayOfFloat", cx_type(cx_array_o));
    if (!tc_stringser_arrayOfFloat_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::arrayOfFloat'.");
        goto error;
    }

    /* Define ::tc_stringser::arrayOfFloat */
    if (!cx_checkState(tc_stringser_arrayOfFloat_o, CX_DEFINED)) {
        cx_collection(tc_stringser_arrayOfFloat_o)->elementType = cx_resolve_ext(tc_stringser_arrayOfFloat_o, NULL, "::corto::lang::float32", FALSE, "element ::tc_stringser::arrayOfFloat.elementType");
        cx_collection(tc_stringser_arrayOfFloat_o)->max = 3;
        tc_stringser_arrayOfFloat_o->elementType = cx_resolve_ext(tc_stringser_arrayOfFloat_o, NULL, "::corto::lang::float32", FALSE, "element ::tc_stringser::arrayOfFloat.elementType");
        if (cx_define(tc_stringser_arrayOfFloat_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::arrayOfFloat'.");
            goto error;
        }
    }

    if (cx_type(tc_stringser_arrayOfFloat_o)->size != sizeof(tc_stringser_arrayOfFloat)) {
        cx_error("tc_stringser_load: calculated size '%d' of type '::tc_stringser::arrayOfFloat' doesn't match C-type size '%d'", cx_type(tc_stringser_arrayOfFloat_o)->size, sizeof(tc_stringser_arrayOfFloat));
    }

    /* Declare ::tc_stringser::arrayOfInt */
    tc_stringser_arrayOfInt_o = cx_declareChild(tc_stringser_o, "arrayOfInt", cx_type(cx_array_o));
    if (!tc_stringser_arrayOfInt_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::arrayOfInt'.");
        goto error;
    }

    /* Define ::tc_stringser::arrayOfInt */
    if (!cx_checkState(tc_stringser_arrayOfInt_o, CX_DEFINED)) {
        cx_collection(tc_stringser_arrayOfInt_o)->elementType = cx_resolve_ext(tc_stringser_arrayOfInt_o, NULL, "::corto::lang::int32", FALSE, "element ::tc_stringser::arrayOfInt.elementType");
        cx_collection(tc_stringser_arrayOfInt_o)->max = 3;
        tc_stringser_arrayOfInt_o->elementType = cx_resolve_ext(tc_stringser_arrayOfInt_o, NULL, "::corto::lang::int32", FALSE, "element ::tc_stringser::arrayOfInt.elementType");
        if (cx_define(tc_stringser_arrayOfInt_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::arrayOfInt'.");
            goto error;
        }
    }

    if (cx_type(tc_stringser_arrayOfInt_o)->size != sizeof(tc_stringser_arrayOfInt)) {
        cx_error("tc_stringser_load: calculated size '%d' of type '::tc_stringser::arrayOfInt' doesn't match C-type size '%d'", cx_type(tc_stringser_arrayOfInt_o)->size, sizeof(tc_stringser_arrayOfInt));
    }

    /* Declare ::tc_stringser::arrayOfMoveMode */
    tc_stringser_arrayOfMoveMode_o = cx_declareChild(tc_stringser_o, "arrayOfMoveMode", cx_type(cx_array_o));
    if (!tc_stringser_arrayOfMoveMode_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::arrayOfMoveMode'.");
        goto error;
    }

    /* Declare ::tc_stringser::arrayOfString */
    tc_stringser_arrayOfString_o = cx_declareChild(tc_stringser_o, "arrayOfString", cx_type(cx_array_o));
    if (!tc_stringser_arrayOfString_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::arrayOfString'.");
        goto error;
    }

    /* Define ::tc_stringser::arrayOfString */
    if (!cx_checkState(tc_stringser_arrayOfString_o, CX_DEFINED)) {
        cx_collection(tc_stringser_arrayOfString_o)->elementType = cx_resolve_ext(tc_stringser_arrayOfString_o, NULL, "::corto::lang::string", FALSE, "element ::tc_stringser::arrayOfString.elementType");
        cx_collection(tc_stringser_arrayOfString_o)->max = 3;
        tc_stringser_arrayOfString_o->elementType = cx_resolve_ext(tc_stringser_arrayOfString_o, NULL, "::corto::lang::string", FALSE, "element ::tc_stringser::arrayOfString.elementType");
        if (cx_define(tc_stringser_arrayOfString_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::arrayOfString'.");
            goto error;
        }
    }

    if (cx_type(tc_stringser_arrayOfString_o)->size != sizeof(tc_stringser_arrayOfString)) {
        cx_error("tc_stringser_load: calculated size '%d' of type '::tc_stringser::arrayOfString' doesn't match C-type size '%d'", cx_type(tc_stringser_arrayOfString_o)->size, sizeof(tc_stringser_arrayOfString));
    }

    /* Declare ::tc_stringser::classCompositeCollection */
    tc_stringser_classCompositeCollection_o = cx_declareChild(tc_stringser_o, "classCompositeCollection", cx_type(cx_class_o));
    if (!tc_stringser_classCompositeCollection_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::classCompositeCollection'.");
        goto error;
    }

    /* Declare ::tc_stringser::classCompositeCollection::a */
    tc_stringser_classCompositeCollection_a_o = cx_declareChild(tc_stringser_classCompositeCollection_o, "a", cx_type(cx_member_o));
    if (!tc_stringser_classCompositeCollection_a_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::classCompositeCollection::a'.");
        goto error;
    }

    /* Declare ::tc_stringser::classCompositeCollection::b */
    tc_stringser_classCompositeCollection_b_o = cx_declareChild(tc_stringser_classCompositeCollection_o, "b", cx_type(cx_member_o));
    if (!tc_stringser_classCompositeCollection_b_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::classCompositeCollection::b'.");
        goto error;
    }

    /* Declare ::tc_stringser::classCompositeCollection::c */
    tc_stringser_classCompositeCollection_c_o = cx_declareChild(tc_stringser_classCompositeCollection_o, "c", cx_type(cx_member_o));
    if (!tc_stringser_classCompositeCollection_c_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::classCompositeCollection::c'.");
        goto error;
    }

    /* Declare ::tc_stringser::classCompositeCollection::d */
    tc_stringser_classCompositeCollection_d_o = cx_declareChild(tc_stringser_classCompositeCollection_o, "d", cx_type(cx_member_o));
    if (!tc_stringser_classCompositeCollection_d_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::classCompositeCollection::d'.");
        goto error;
    }

    /* Declare ::tc_stringser::classCompositeCollection::e */
    tc_stringser_classCompositeCollection_e_o = cx_declareChild(tc_stringser_classCompositeCollection_o, "e", cx_type(cx_member_o));
    if (!tc_stringser_classCompositeCollection_e_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::classCompositeCollection::e'.");
        goto error;
    }

    /* Declare ::tc_stringser::classInherit */
    tc_stringser_classInherit_o = cx_declareChild(tc_stringser_o, "classInherit", cx_type(cx_class_o));
    if (!tc_stringser_classInherit_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::classInherit'.");
        goto error;
    }

    /* Declare ::tc_stringser::classInherit::a */
    tc_stringser_classInherit_a_o = cx_declareChild(tc_stringser_classInherit_o, "a", cx_type(cx_member_o));
    if (!tc_stringser_classInherit_a_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::classInherit::a'.");
        goto error;
    }

    /* Define ::tc_stringser::classInherit::a */
    if (!cx_checkState(tc_stringser_classInherit_a_o, CX_DEFINED)) {
        tc_stringser_classInherit_a_o->type = cx_resolve_ext(tc_stringser_classInherit_a_o, NULL, "::corto::lang::bool", FALSE, "element ::tc_stringser::classInherit::a.type");
        tc_stringser_classInherit_a_o->modifiers = 0x0;
        tc_stringser_classInherit_a_o->state = 0x6;
        tc_stringser_classInherit_a_o->weak = FALSE;
        tc_stringser_classInherit_a_o->id = 0;
        if (cx_define(tc_stringser_classInherit_a_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::classInherit::a'.");
            goto error;
        }
    }

    /* Declare ::tc_stringser::classInherit::b */
    tc_stringser_classInherit_b_o = cx_declareChild(tc_stringser_classInherit_o, "b", cx_type(cx_member_o));
    if (!tc_stringser_classInherit_b_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::classInherit::b'.");
        goto error;
    }

    /* Define ::tc_stringser::classInherit::b */
    if (!cx_checkState(tc_stringser_classInherit_b_o, CX_DEFINED)) {
        tc_stringser_classInherit_b_o->type = cx_resolve_ext(tc_stringser_classInherit_b_o, NULL, "::corto::lang::char", FALSE, "element ::tc_stringser::classInherit::b.type");
        tc_stringser_classInherit_b_o->modifiers = 0x0;
        tc_stringser_classInherit_b_o->state = 0x6;
        tc_stringser_classInherit_b_o->weak = FALSE;
        tc_stringser_classInherit_b_o->id = 1;
        if (cx_define(tc_stringser_classInherit_b_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::classInherit::b'.");
            goto error;
        }
    }

    /* Declare ::tc_stringser::classInherit::c */
    tc_stringser_classInherit_c_o = cx_declareChild(tc_stringser_classInherit_o, "c", cx_type(cx_member_o));
    if (!tc_stringser_classInherit_c_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::classInherit::c'.");
        goto error;
    }

    /* Define ::tc_stringser::classInherit::c */
    if (!cx_checkState(tc_stringser_classInherit_c_o, CX_DEFINED)) {
        tc_stringser_classInherit_c_o->type = cx_resolve_ext(tc_stringser_classInherit_c_o, NULL, "::corto::lang::int32", FALSE, "element ::tc_stringser::classInherit::c.type");
        tc_stringser_classInherit_c_o->modifiers = 0x0;
        tc_stringser_classInherit_c_o->state = 0x6;
        tc_stringser_classInherit_c_o->weak = FALSE;
        tc_stringser_classInherit_c_o->id = 2;
        if (cx_define(tc_stringser_classInherit_c_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::classInherit::c'.");
            goto error;
        }
    }

    /* Declare ::tc_stringser::classInherit::d */
    tc_stringser_classInherit_d_o = cx_declareChild(tc_stringser_classInherit_o, "d", cx_type(cx_member_o));
    if (!tc_stringser_classInherit_d_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::classInherit::d'.");
        goto error;
    }

    /* Define ::tc_stringser::classInherit::d */
    if (!cx_checkState(tc_stringser_classInherit_d_o, CX_DEFINED)) {
        tc_stringser_classInherit_d_o->type = cx_resolve_ext(tc_stringser_classInherit_d_o, NULL, "::corto::lang::float32", FALSE, "element ::tc_stringser::classInherit::d.type");
        tc_stringser_classInherit_d_o->modifiers = 0x0;
        tc_stringser_classInherit_d_o->state = 0x6;
        tc_stringser_classInherit_d_o->weak = FALSE;
        tc_stringser_classInherit_d_o->id = 3;
        if (cx_define(tc_stringser_classInherit_d_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::classInherit::d'.");
            goto error;
        }
    }

    /* Declare ::tc_stringser::classInherit::e */
    tc_stringser_classInherit_e_o = cx_declareChild(tc_stringser_classInherit_o, "e", cx_type(cx_member_o));
    if (!tc_stringser_classInherit_e_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::classInherit::e'.");
        goto error;
    }

    /* Define ::tc_stringser::classInherit::e */
    if (!cx_checkState(tc_stringser_classInherit_e_o, CX_DEFINED)) {
        tc_stringser_classInherit_e_o->type = cx_resolve_ext(tc_stringser_classInherit_e_o, NULL, "::corto::lang::string", FALSE, "element ::tc_stringser::classInherit::e.type");
        tc_stringser_classInherit_e_o->modifiers = 0x0;
        tc_stringser_classInherit_e_o->state = 0x6;
        tc_stringser_classInherit_e_o->weak = FALSE;
        tc_stringser_classInherit_e_o->id = 4;
        if (cx_define(tc_stringser_classInherit_e_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::classInherit::e'.");
            goto error;
        }
    }

    /* Declare ::tc_stringser::classInherit::f */
    tc_stringser_classInherit_f_o = cx_declareChild(tc_stringser_classInherit_o, "f", cx_type(cx_member_o));
    if (!tc_stringser_classInherit_f_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::classInherit::f'.");
        goto error;
    }

    /* Declare ::tc_stringser::classInherit::g */
    tc_stringser_classInherit_g_o = cx_declareChild(tc_stringser_classInherit_o, "g", cx_type(cx_member_o));
    if (!tc_stringser_classInherit_g_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::classInherit::g'.");
        goto error;
    }

    /* Declare ::tc_stringser::listOfClassInherit */
    tc_stringser_listOfClassInherit_o = cx_declareChild(tc_stringser_o, "listOfClassInherit", cx_type(cx_list_o));
    if (!tc_stringser_listOfClassInherit_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::listOfClassInherit'.");
        goto error;
    }

    /* Define ::tc_stringser::listOfClassInherit */
    if (!cx_checkState(tc_stringser_listOfClassInherit_o, CX_DEFINED)) {
        cx_collection(tc_stringser_listOfClassInherit_o)->elementType = cx_resolve_ext(tc_stringser_listOfClassInherit_o, NULL, "::tc_stringser::classInherit", FALSE, "element ::tc_stringser::listOfClassInherit.elementType");
        cx_collection(tc_stringser_listOfClassInherit_o)->max = 3;
        if (cx_define(tc_stringser_listOfClassInherit_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::listOfClassInherit'.");
            goto error;
        }
    }

    if (cx_type(tc_stringser_listOfClassInherit_o)->size != sizeof(tc_stringser_listOfClassInherit)) {
        cx_error("tc_stringser_load: calculated size '%d' of type '::tc_stringser::listOfClassInherit' doesn't match C-type size '%d'", cx_type(tc_stringser_listOfClassInherit_o)->size, sizeof(tc_stringser_listOfClassInherit));
    }

    /* Define ::tc_stringser::classCompositeCollection::e */
    if (!cx_checkState(tc_stringser_classCompositeCollection_e_o, CX_DEFINED)) {
        tc_stringser_classCompositeCollection_e_o->type = cx_resolve_ext(tc_stringser_classCompositeCollection_e_o, NULL, "::tc_stringser::listOfClassInherit", FALSE, "element ::tc_stringser::classCompositeCollection::e.type");
        tc_stringser_classCompositeCollection_e_o->modifiers = 0x0;
        tc_stringser_classCompositeCollection_e_o->state = 0x6;
        tc_stringser_classCompositeCollection_e_o->weak = FALSE;
        tc_stringser_classCompositeCollection_e_o->id = 4;
        if (cx_define(tc_stringser_classCompositeCollection_e_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::classCompositeCollection::e'.");
            goto error;
        }
    }

    /* Declare ::tc_stringser::sequenceOfClassInherit */
    tc_stringser_sequenceOfClassInherit_o = cx_declareChild(tc_stringser_o, "sequenceOfClassInherit", cx_type(cx_sequence_o));
    if (!tc_stringser_sequenceOfClassInherit_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::sequenceOfClassInherit'.");
        goto error;
    }

    /* Define ::tc_stringser::sequenceOfClassInherit */
    if (!cx_checkState(tc_stringser_sequenceOfClassInherit_o, CX_DEFINED)) {
        cx_collection(tc_stringser_sequenceOfClassInherit_o)->elementType = cx_resolve_ext(tc_stringser_sequenceOfClassInherit_o, NULL, "::tc_stringser::classInherit", FALSE, "element ::tc_stringser::sequenceOfClassInherit.elementType");
        cx_collection(tc_stringser_sequenceOfClassInherit_o)->max = 3;
        if (cx_define(tc_stringser_sequenceOfClassInherit_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::sequenceOfClassInherit'.");
            goto error;
        }
    }

    if (cx_type(tc_stringser_sequenceOfClassInherit_o)->size != sizeof(tc_stringser_sequenceOfClassInherit)) {
        cx_error("tc_stringser_load: calculated size '%d' of type '::tc_stringser::sequenceOfClassInherit' doesn't match C-type size '%d'", cx_type(tc_stringser_sequenceOfClassInherit_o)->size, sizeof(tc_stringser_sequenceOfClassInherit));
    }

    /* Define ::tc_stringser::classCompositeCollection::c */
    if (!cx_checkState(tc_stringser_classCompositeCollection_c_o, CX_DEFINED)) {
        tc_stringser_classCompositeCollection_c_o->type = cx_resolve_ext(tc_stringser_classCompositeCollection_c_o, NULL, "::tc_stringser::sequenceOfClassInherit", FALSE, "element ::tc_stringser::classCompositeCollection::c.type");
        tc_stringser_classCompositeCollection_c_o->modifiers = 0x0;
        tc_stringser_classCompositeCollection_c_o->state = 0x6;
        tc_stringser_classCompositeCollection_c_o->weak = FALSE;
        tc_stringser_classCompositeCollection_c_o->id = 2;
        if (cx_define(tc_stringser_classCompositeCollection_c_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::classCompositeCollection::c'.");
            goto error;
        }
    }

    /* Declare ::tc_stringser::classNested */
    tc_stringser_classNested_o = cx_declareChild(tc_stringser_o, "classNested", cx_type(cx_class_o));
    if (!tc_stringser_classNested_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::classNested'.");
        goto error;
    }

    /* Declare ::tc_stringser::classNested::a */
    tc_stringser_classNested_a_o = cx_declareChild(tc_stringser_classNested_o, "a", cx_type(cx_member_o));
    if (!tc_stringser_classNested_a_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::classNested::a'.");
        goto error;
    }

    /* Declare ::tc_stringser::classNested::b */
    tc_stringser_classNested_b_o = cx_declareChild(tc_stringser_classNested_o, "b", cx_type(cx_member_o));
    if (!tc_stringser_classNested_b_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::classNested::b'.");
        goto error;
    }

    /* Declare ::tc_stringser::classNested::c */
    tc_stringser_classNested_c_o = cx_declareChild(tc_stringser_classNested_o, "c", cx_type(cx_member_o));
    if (!tc_stringser_classNested_c_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::classNested::c'.");
        goto error;
    }

    /* Define ::tc_stringser::classNested::c */
    if (!cx_checkState(tc_stringser_classNested_c_o, CX_DEFINED)) {
        tc_stringser_classNested_c_o->type = cx_resolve_ext(tc_stringser_classNested_c_o, NULL, "::tc_stringser::arrayOfInt", FALSE, "element ::tc_stringser::classNested::c.type");
        tc_stringser_classNested_c_o->modifiers = 0x0;
        tc_stringser_classNested_c_o->state = 0x6;
        tc_stringser_classNested_c_o->weak = FALSE;
        tc_stringser_classNested_c_o->id = 2;
        if (cx_define(tc_stringser_classNested_c_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::classNested::c'.");
            goto error;
        }
    }

    /* Declare ::tc_stringser::classNested::d */
    tc_stringser_classNested_d_o = cx_declareChild(tc_stringser_classNested_o, "d", cx_type(cx_member_o));
    if (!tc_stringser_classNested_d_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::classNested::d'.");
        goto error;
    }

    /* Declare ::tc_stringser::classNested::e */
    tc_stringser_classNested_e_o = cx_declareChild(tc_stringser_classNested_o, "e", cx_type(cx_member_o));
    if (!tc_stringser_classNested_e_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::classNested::e'.");
        goto error;
    }

    /* Declare ::tc_stringser::listOfClassNested */
    tc_stringser_listOfClassNested_o = cx_declareChild(tc_stringser_o, "listOfClassNested", cx_type(cx_list_o));
    if (!tc_stringser_listOfClassNested_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::listOfClassNested'.");
        goto error;
    }

    /* Define ::tc_stringser::listOfClassNested */
    if (!cx_checkState(tc_stringser_listOfClassNested_o, CX_DEFINED)) {
        cx_collection(tc_stringser_listOfClassNested_o)->elementType = cx_resolve_ext(tc_stringser_listOfClassNested_o, NULL, "::tc_stringser::classNested", FALSE, "element ::tc_stringser::listOfClassNested.elementType");
        cx_collection(tc_stringser_listOfClassNested_o)->max = 3;
        if (cx_define(tc_stringser_listOfClassNested_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::listOfClassNested'.");
            goto error;
        }
    }

    if (cx_type(tc_stringser_listOfClassNested_o)->size != sizeof(tc_stringser_listOfClassNested)) {
        cx_error("tc_stringser_load: calculated size '%d' of type '::tc_stringser::listOfClassNested' doesn't match C-type size '%d'", cx_type(tc_stringser_listOfClassNested_o)->size, sizeof(tc_stringser_listOfClassNested));
    }

    /* Define ::tc_stringser::classCompositeCollection::d */
    if (!cx_checkState(tc_stringser_classCompositeCollection_d_o, CX_DEFINED)) {
        tc_stringser_classCompositeCollection_d_o->type = cx_resolve_ext(tc_stringser_classCompositeCollection_d_o, NULL, "::tc_stringser::listOfClassNested", FALSE, "element ::tc_stringser::classCompositeCollection::d.type");
        tc_stringser_classCompositeCollection_d_o->modifiers = 0x0;
        tc_stringser_classCompositeCollection_d_o->state = 0x6;
        tc_stringser_classCompositeCollection_d_o->weak = FALSE;
        tc_stringser_classCompositeCollection_d_o->id = 3;
        if (cx_define(tc_stringser_classCompositeCollection_d_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::classCompositeCollection::d'.");
            goto error;
        }
    }

    /* Declare ::tc_stringser::sequenceOfClassNested */
    tc_stringser_sequenceOfClassNested_o = cx_declareChild(tc_stringser_o, "sequenceOfClassNested", cx_type(cx_sequence_o));
    if (!tc_stringser_sequenceOfClassNested_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::sequenceOfClassNested'.");
        goto error;
    }

    /* Define ::tc_stringser::sequenceOfClassNested */
    if (!cx_checkState(tc_stringser_sequenceOfClassNested_o, CX_DEFINED)) {
        cx_collection(tc_stringser_sequenceOfClassNested_o)->elementType = cx_resolve_ext(tc_stringser_sequenceOfClassNested_o, NULL, "::tc_stringser::classNested", FALSE, "element ::tc_stringser::sequenceOfClassNested.elementType");
        cx_collection(tc_stringser_sequenceOfClassNested_o)->max = 3;
        if (cx_define(tc_stringser_sequenceOfClassNested_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::sequenceOfClassNested'.");
            goto error;
        }
    }

    if (cx_type(tc_stringser_sequenceOfClassNested_o)->size != sizeof(tc_stringser_sequenceOfClassNested)) {
        cx_error("tc_stringser_load: calculated size '%d' of type '::tc_stringser::sequenceOfClassNested' doesn't match C-type size '%d'", cx_type(tc_stringser_sequenceOfClassNested_o)->size, sizeof(tc_stringser_sequenceOfClassNested));
    }

    /* Declare ::tc_stringser::classPrimitives */
    tc_stringser_classPrimitives_o = cx_declareChild(tc_stringser_o, "classPrimitives", cx_type(cx_class_o));
    if (!tc_stringser_classPrimitives_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::classPrimitives'.");
        goto error;
    }

    /* Declare ::tc_stringser::classPrimitives::a */
    tc_stringser_classPrimitives_a_o = cx_declareChild(tc_stringser_classPrimitives_o, "a", cx_type(cx_member_o));
    if (!tc_stringser_classPrimitives_a_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::classPrimitives::a'.");
        goto error;
    }

    /* Define ::tc_stringser::classPrimitives::a */
    if (!cx_checkState(tc_stringser_classPrimitives_a_o, CX_DEFINED)) {
        tc_stringser_classPrimitives_a_o->type = cx_resolve_ext(tc_stringser_classPrimitives_a_o, NULL, "::corto::lang::bool", FALSE, "element ::tc_stringser::classPrimitives::a.type");
        tc_stringser_classPrimitives_a_o->modifiers = 0x0;
        tc_stringser_classPrimitives_a_o->state = 0x6;
        tc_stringser_classPrimitives_a_o->weak = FALSE;
        tc_stringser_classPrimitives_a_o->id = 0;
        if (cx_define(tc_stringser_classPrimitives_a_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::classPrimitives::a'.");
            goto error;
        }
    }

    /* Declare ::tc_stringser::classPrimitives::b */
    tc_stringser_classPrimitives_b_o = cx_declareChild(tc_stringser_classPrimitives_o, "b", cx_type(cx_member_o));
    if (!tc_stringser_classPrimitives_b_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::classPrimitives::b'.");
        goto error;
    }

    /* Define ::tc_stringser::classPrimitives::b */
    if (!cx_checkState(tc_stringser_classPrimitives_b_o, CX_DEFINED)) {
        tc_stringser_classPrimitives_b_o->type = cx_resolve_ext(tc_stringser_classPrimitives_b_o, NULL, "::corto::lang::char", FALSE, "element ::tc_stringser::classPrimitives::b.type");
        tc_stringser_classPrimitives_b_o->modifiers = 0x0;
        tc_stringser_classPrimitives_b_o->state = 0x6;
        tc_stringser_classPrimitives_b_o->weak = FALSE;
        tc_stringser_classPrimitives_b_o->id = 1;
        if (cx_define(tc_stringser_classPrimitives_b_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::classPrimitives::b'.");
            goto error;
        }
    }

    /* Declare ::tc_stringser::classPrimitives::c */
    tc_stringser_classPrimitives_c_o = cx_declareChild(tc_stringser_classPrimitives_o, "c", cx_type(cx_member_o));
    if (!tc_stringser_classPrimitives_c_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::classPrimitives::c'.");
        goto error;
    }

    /* Define ::tc_stringser::classPrimitives::c */
    if (!cx_checkState(tc_stringser_classPrimitives_c_o, CX_DEFINED)) {
        tc_stringser_classPrimitives_c_o->type = cx_resolve_ext(tc_stringser_classPrimitives_c_o, NULL, "::corto::lang::int32", FALSE, "element ::tc_stringser::classPrimitives::c.type");
        tc_stringser_classPrimitives_c_o->modifiers = 0x0;
        tc_stringser_classPrimitives_c_o->state = 0x6;
        tc_stringser_classPrimitives_c_o->weak = FALSE;
        tc_stringser_classPrimitives_c_o->id = 2;
        if (cx_define(tc_stringser_classPrimitives_c_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::classPrimitives::c'.");
            goto error;
        }
    }

    /* Declare ::tc_stringser::classPrimitives::d */
    tc_stringser_classPrimitives_d_o = cx_declareChild(tc_stringser_classPrimitives_o, "d", cx_type(cx_member_o));
    if (!tc_stringser_classPrimitives_d_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::classPrimitives::d'.");
        goto error;
    }

    /* Define ::tc_stringser::classPrimitives::d */
    if (!cx_checkState(tc_stringser_classPrimitives_d_o, CX_DEFINED)) {
        tc_stringser_classPrimitives_d_o->type = cx_resolve_ext(tc_stringser_classPrimitives_d_o, NULL, "::corto::lang::float32", FALSE, "element ::tc_stringser::classPrimitives::d.type");
        tc_stringser_classPrimitives_d_o->modifiers = 0x0;
        tc_stringser_classPrimitives_d_o->state = 0x6;
        tc_stringser_classPrimitives_d_o->weak = FALSE;
        tc_stringser_classPrimitives_d_o->id = 3;
        if (cx_define(tc_stringser_classPrimitives_d_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::classPrimitives::d'.");
            goto error;
        }
    }

    /* Declare ::tc_stringser::classPrimitives::e */
    tc_stringser_classPrimitives_e_o = cx_declareChild(tc_stringser_classPrimitives_o, "e", cx_type(cx_member_o));
    if (!tc_stringser_classPrimitives_e_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::classPrimitives::e'.");
        goto error;
    }

    /* Define ::tc_stringser::classPrimitives::e */
    if (!cx_checkState(tc_stringser_classPrimitives_e_o, CX_DEFINED)) {
        tc_stringser_classPrimitives_e_o->type = cx_resolve_ext(tc_stringser_classPrimitives_e_o, NULL, "::corto::lang::string", FALSE, "element ::tc_stringser::classPrimitives::e.type");
        tc_stringser_classPrimitives_e_o->modifiers = 0x0;
        tc_stringser_classPrimitives_e_o->state = 0x6;
        tc_stringser_classPrimitives_e_o->weak = FALSE;
        tc_stringser_classPrimitives_e_o->id = 4;
        if (cx_define(tc_stringser_classPrimitives_e_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::classPrimitives::e'.");
            goto error;
        }
    }

    /* Declare ::tc_stringser::classPrimitives::f */
    tc_stringser_classPrimitives_f_o = cx_declareChild(tc_stringser_classPrimitives_o, "f", cx_type(cx_member_o));
    if (!tc_stringser_classPrimitives_f_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::classPrimitives::f'.");
        goto error;
    }

    /* Declare ::tc_stringser::classPrimitives::g */
    tc_stringser_classPrimitives_g_o = cx_declareChild(tc_stringser_classPrimitives_o, "g", cx_type(cx_member_o));
    if (!tc_stringser_classPrimitives_g_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::classPrimitives::g'.");
        goto error;
    }

    /* Declare ::tc_stringser::listOfClassPrimitives */
    tc_stringser_listOfClassPrimitives_o = cx_declareChild(tc_stringser_o, "listOfClassPrimitives", cx_type(cx_list_o));
    if (!tc_stringser_listOfClassPrimitives_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::listOfClassPrimitives'.");
        goto error;
    }

    /* Define ::tc_stringser::listOfClassPrimitives */
    if (!cx_checkState(tc_stringser_listOfClassPrimitives_o, CX_DEFINED)) {
        cx_collection(tc_stringser_listOfClassPrimitives_o)->elementType = cx_resolve_ext(tc_stringser_listOfClassPrimitives_o, NULL, "::tc_stringser::classPrimitives", FALSE, "element ::tc_stringser::listOfClassPrimitives.elementType");
        cx_collection(tc_stringser_listOfClassPrimitives_o)->max = 3;
        if (cx_define(tc_stringser_listOfClassPrimitives_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::listOfClassPrimitives'.");
            goto error;
        }
    }

    if (cx_type(tc_stringser_listOfClassPrimitives_o)->size != sizeof(tc_stringser_listOfClassPrimitives)) {
        cx_error("tc_stringser_load: calculated size '%d' of type '::tc_stringser::listOfClassPrimitives' doesn't match C-type size '%d'", cx_type(tc_stringser_listOfClassPrimitives_o)->size, sizeof(tc_stringser_listOfClassPrimitives));
    }

    /* Declare ::tc_stringser::sequenceOfClassPrimitives */
    tc_stringser_sequenceOfClassPrimitives_o = cx_declareChild(tc_stringser_o, "sequenceOfClassPrimitives", cx_type(cx_sequence_o));
    if (!tc_stringser_sequenceOfClassPrimitives_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::sequenceOfClassPrimitives'.");
        goto error;
    }

    /* Define ::tc_stringser::sequenceOfClassPrimitives */
    if (!cx_checkState(tc_stringser_sequenceOfClassPrimitives_o, CX_DEFINED)) {
        cx_collection(tc_stringser_sequenceOfClassPrimitives_o)->elementType = cx_resolve_ext(tc_stringser_sequenceOfClassPrimitives_o, NULL, "::tc_stringser::classPrimitives", FALSE, "element ::tc_stringser::sequenceOfClassPrimitives.elementType");
        cx_collection(tc_stringser_sequenceOfClassPrimitives_o)->max = 3;
        if (cx_define(tc_stringser_sequenceOfClassPrimitives_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::sequenceOfClassPrimitives'.");
            goto error;
        }
    }

    if (cx_type(tc_stringser_sequenceOfClassPrimitives_o)->size != sizeof(tc_stringser_sequenceOfClassPrimitives)) {
        cx_error("tc_stringser_load: calculated size '%d' of type '::tc_stringser::sequenceOfClassPrimitives' doesn't match C-type size '%d'", cx_type(tc_stringser_sequenceOfClassPrimitives_o)->size, sizeof(tc_stringser_sequenceOfClassPrimitives));
    }

    /* Declare ::tc_stringser::color */
    tc_stringser_color_o = cx_declareChild(tc_stringser_o, "color", cx_type(cx_enum_o));
    if (!tc_stringser_color_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::color'.");
        goto error;
    }

    /* Declare ::tc_stringser::color::BLUE */
    tc_stringser_color_BLUE_o = cx_declareChild(tc_stringser_color_o, "BLUE", cx_type(cx_constant_o));
    if (!tc_stringser_color_BLUE_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::color::BLUE'.");
        goto error;
    } else {
        (*tc_stringser_color_BLUE_o) = 2;
    }

    /* Declare ::tc_stringser::color::RED */
    tc_stringser_color_RED_o = cx_declareChild(tc_stringser_color_o, "RED", cx_type(cx_constant_o));
    if (!tc_stringser_color_RED_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::color::RED'.");
        goto error;
    } else {
        (*tc_stringser_color_RED_o) = 0;
    }

    /* Declare ::tc_stringser::color::YELLOW */
    tc_stringser_color_YELLOW_o = cx_declareChild(tc_stringser_color_o, "YELLOW", cx_type(cx_constant_o));
    if (!tc_stringser_color_YELLOW_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::color::YELLOW'.");
        goto error;
    } else {
        (*tc_stringser_color_YELLOW_o) = 1;
    }

    /* Define ::tc_stringser::color */
    if (!cx_checkState(tc_stringser_color_o, CX_DEFINED)) {
        if (cx_define(tc_stringser_color_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::color'.");
            goto error;
        }
    }

    if (cx_type(tc_stringser_color_o)->size != sizeof(tc_stringser_color)) {
        cx_error("tc_stringser_load: calculated size '%d' of type '::tc_stringser::color' doesn't match C-type size '%d'", cx_type(tc_stringser_color_o)->size, sizeof(tc_stringser_color));
    }

    /* Define ::tc_stringser::arrayOfColor */
    if (!cx_checkState(tc_stringser_arrayOfColor_o, CX_DEFINED)) {
        cx_collection(tc_stringser_arrayOfColor_o)->elementType = cx_resolve_ext(tc_stringser_arrayOfColor_o, NULL, "::tc_stringser::color", FALSE, "element ::tc_stringser::arrayOfColor.elementType");
        cx_collection(tc_stringser_arrayOfColor_o)->max = 3;
        tc_stringser_arrayOfColor_o->elementType = cx_resolve_ext(tc_stringser_arrayOfColor_o, NULL, "::tc_stringser::color", FALSE, "element ::tc_stringser::arrayOfColor.elementType");
        if (cx_define(tc_stringser_arrayOfColor_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::arrayOfColor'.");
            goto error;
        }
    }

    if (cx_type(tc_stringser_arrayOfColor_o)->size != sizeof(tc_stringser_arrayOfColor)) {
        cx_error("tc_stringser_load: calculated size '%d' of type '::tc_stringser::arrayOfColor' doesn't match C-type size '%d'", cx_type(tc_stringser_arrayOfColor_o)->size, sizeof(tc_stringser_arrayOfColor));
    }

    /* Define ::tc_stringser::classInherit::f */
    if (!cx_checkState(tc_stringser_classInherit_f_o, CX_DEFINED)) {
        tc_stringser_classInherit_f_o->type = cx_resolve_ext(tc_stringser_classInherit_f_o, NULL, "::tc_stringser::color", FALSE, "element ::tc_stringser::classInherit::f.type");
        tc_stringser_classInherit_f_o->modifiers = 0x0;
        tc_stringser_classInherit_f_o->state = 0x6;
        tc_stringser_classInherit_f_o->weak = FALSE;
        tc_stringser_classInherit_f_o->id = 5;
        if (cx_define(tc_stringser_classInherit_f_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::classInherit::f'.");
            goto error;
        }
    }

    /* Define ::tc_stringser::classPrimitives::f */
    if (!cx_checkState(tc_stringser_classPrimitives_f_o, CX_DEFINED)) {
        tc_stringser_classPrimitives_f_o->type = cx_resolve_ext(tc_stringser_classPrimitives_f_o, NULL, "::tc_stringser::color", FALSE, "element ::tc_stringser::classPrimitives::f.type");
        tc_stringser_classPrimitives_f_o->modifiers = 0x0;
        tc_stringser_classPrimitives_f_o->state = 0x6;
        tc_stringser_classPrimitives_f_o->weak = FALSE;
        tc_stringser_classPrimitives_f_o->id = 5;
        if (cx_define(tc_stringser_classPrimitives_f_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::classPrimitives::f'.");
            goto error;
        }
    }

    /* Declare ::tc_stringser::listOfColor */
    tc_stringser_listOfColor_o = cx_declareChild(tc_stringser_o, "listOfColor", cx_type(cx_list_o));
    if (!tc_stringser_listOfColor_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::listOfColor'.");
        goto error;
    }

    /* Define ::tc_stringser::listOfColor */
    if (!cx_checkState(tc_stringser_listOfColor_o, CX_DEFINED)) {
        cx_collection(tc_stringser_listOfColor_o)->elementType = cx_resolve_ext(tc_stringser_listOfColor_o, NULL, "::tc_stringser::color", FALSE, "element ::tc_stringser::listOfColor.elementType");
        cx_collection(tc_stringser_listOfColor_o)->max = 3;
        if (cx_define(tc_stringser_listOfColor_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::listOfColor'.");
            goto error;
        }
    }

    if (cx_type(tc_stringser_listOfColor_o)->size != sizeof(tc_stringser_listOfColor)) {
        cx_error("tc_stringser_load: calculated size '%d' of type '::tc_stringser::listOfColor' doesn't match C-type size '%d'", cx_type(tc_stringser_listOfColor_o)->size, sizeof(tc_stringser_listOfColor));
    }

    /* Declare ::tc_stringser::sequenceOfColor */
    tc_stringser_sequenceOfColor_o = cx_declareChild(tc_stringser_o, "sequenceOfColor", cx_type(cx_sequence_o));
    if (!tc_stringser_sequenceOfColor_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::sequenceOfColor'.");
        goto error;
    }

    /* Define ::tc_stringser::sequenceOfColor */
    if (!cx_checkState(tc_stringser_sequenceOfColor_o, CX_DEFINED)) {
        cx_collection(tc_stringser_sequenceOfColor_o)->elementType = cx_resolve_ext(tc_stringser_sequenceOfColor_o, NULL, "::tc_stringser::color", FALSE, "element ::tc_stringser::sequenceOfColor.elementType");
        cx_collection(tc_stringser_sequenceOfColor_o)->max = 3;
        if (cx_define(tc_stringser_sequenceOfColor_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::sequenceOfColor'.");
            goto error;
        }
    }

    if (cx_type(tc_stringser_sequenceOfColor_o)->size != sizeof(tc_stringser_sequenceOfColor)) {
        cx_error("tc_stringser_load: calculated size '%d' of type '::tc_stringser::sequenceOfColor' doesn't match C-type size '%d'", cx_type(tc_stringser_sequenceOfColor_o)->size, sizeof(tc_stringser_sequenceOfColor));
    }

    /* Declare ::tc_stringser::listOfBool */
    tc_stringser_listOfBool_o = cx_declareChild(tc_stringser_o, "listOfBool", cx_type(cx_list_o));
    if (!tc_stringser_listOfBool_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::listOfBool'.");
        goto error;
    }

    /* Define ::tc_stringser::listOfBool */
    if (!cx_checkState(tc_stringser_listOfBool_o, CX_DEFINED)) {
        cx_collection(tc_stringser_listOfBool_o)->elementType = cx_resolve_ext(tc_stringser_listOfBool_o, NULL, "::corto::lang::bool", FALSE, "element ::tc_stringser::listOfBool.elementType");
        cx_collection(tc_stringser_listOfBool_o)->max = 3;
        if (cx_define(tc_stringser_listOfBool_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::listOfBool'.");
            goto error;
        }
    }

    if (cx_type(tc_stringser_listOfBool_o)->size != sizeof(tc_stringser_listOfBool)) {
        cx_error("tc_stringser_load: calculated size '%d' of type '::tc_stringser::listOfBool' doesn't match C-type size '%d'", cx_type(tc_stringser_listOfBool_o)->size, sizeof(tc_stringser_listOfBool));
    }

    /* Declare ::tc_stringser::listOfChar */
    tc_stringser_listOfChar_o = cx_declareChild(tc_stringser_o, "listOfChar", cx_type(cx_list_o));
    if (!tc_stringser_listOfChar_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::listOfChar'.");
        goto error;
    }

    /* Define ::tc_stringser::listOfChar */
    if (!cx_checkState(tc_stringser_listOfChar_o, CX_DEFINED)) {
        cx_collection(tc_stringser_listOfChar_o)->elementType = cx_resolve_ext(tc_stringser_listOfChar_o, NULL, "::corto::lang::char", FALSE, "element ::tc_stringser::listOfChar.elementType");
        cx_collection(tc_stringser_listOfChar_o)->max = 3;
        if (cx_define(tc_stringser_listOfChar_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::listOfChar'.");
            goto error;
        }
    }

    if (cx_type(tc_stringser_listOfChar_o)->size != sizeof(tc_stringser_listOfChar)) {
        cx_error("tc_stringser_load: calculated size '%d' of type '::tc_stringser::listOfChar' doesn't match C-type size '%d'", cx_type(tc_stringser_listOfChar_o)->size, sizeof(tc_stringser_listOfChar));
    }

    /* Declare ::tc_stringser::listOfFloat */
    tc_stringser_listOfFloat_o = cx_declareChild(tc_stringser_o, "listOfFloat", cx_type(cx_list_o));
    if (!tc_stringser_listOfFloat_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::listOfFloat'.");
        goto error;
    }

    /* Define ::tc_stringser::listOfFloat */
    if (!cx_checkState(tc_stringser_listOfFloat_o, CX_DEFINED)) {
        cx_collection(tc_stringser_listOfFloat_o)->elementType = cx_resolve_ext(tc_stringser_listOfFloat_o, NULL, "::corto::lang::float32", FALSE, "element ::tc_stringser::listOfFloat.elementType");
        cx_collection(tc_stringser_listOfFloat_o)->max = 3;
        if (cx_define(tc_stringser_listOfFloat_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::listOfFloat'.");
            goto error;
        }
    }

    if (cx_type(tc_stringser_listOfFloat_o)->size != sizeof(tc_stringser_listOfFloat)) {
        cx_error("tc_stringser_load: calculated size '%d' of type '::tc_stringser::listOfFloat' doesn't match C-type size '%d'", cx_type(tc_stringser_listOfFloat_o)->size, sizeof(tc_stringser_listOfFloat));
    }

    /* Declare ::tc_stringser::listOfInt */
    tc_stringser_listOfInt_o = cx_declareChild(tc_stringser_o, "listOfInt", cx_type(cx_list_o));
    if (!tc_stringser_listOfInt_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::listOfInt'.");
        goto error;
    }

    /* Define ::tc_stringser::listOfInt */
    if (!cx_checkState(tc_stringser_listOfInt_o, CX_DEFINED)) {
        cx_collection(tc_stringser_listOfInt_o)->elementType = cx_resolve_ext(tc_stringser_listOfInt_o, NULL, "::corto::lang::int32", FALSE, "element ::tc_stringser::listOfInt.elementType");
        cx_collection(tc_stringser_listOfInt_o)->max = 3;
        if (cx_define(tc_stringser_listOfInt_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::listOfInt'.");
            goto error;
        }
    }

    if (cx_type(tc_stringser_listOfInt_o)->size != sizeof(tc_stringser_listOfInt)) {
        cx_error("tc_stringser_load: calculated size '%d' of type '::tc_stringser::listOfInt' doesn't match C-type size '%d'", cx_type(tc_stringser_listOfInt_o)->size, sizeof(tc_stringser_listOfInt));
    }

    /* Define ::tc_stringser::classNested::e */
    if (!cx_checkState(tc_stringser_classNested_e_o, CX_DEFINED)) {
        tc_stringser_classNested_e_o->type = cx_resolve_ext(tc_stringser_classNested_e_o, NULL, "::tc_stringser::listOfInt", FALSE, "element ::tc_stringser::classNested::e.type");
        tc_stringser_classNested_e_o->modifiers = 0x0;
        tc_stringser_classNested_e_o->state = 0x6;
        tc_stringser_classNested_e_o->weak = FALSE;
        tc_stringser_classNested_e_o->id = 4;
        if (cx_define(tc_stringser_classNested_e_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::classNested::e'.");
            goto error;
        }
    }

    /* Declare ::tc_stringser::listOfMoveMode */
    tc_stringser_listOfMoveMode_o = cx_declareChild(tc_stringser_o, "listOfMoveMode", cx_type(cx_list_o));
    if (!tc_stringser_listOfMoveMode_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::listOfMoveMode'.");
        goto error;
    }

    /* Declare ::tc_stringser::listOfString */
    tc_stringser_listOfString_o = cx_declareChild(tc_stringser_o, "listOfString", cx_type(cx_list_o));
    if (!tc_stringser_listOfString_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::listOfString'.");
        goto error;
    }

    /* Define ::tc_stringser::listOfString */
    if (!cx_checkState(tc_stringser_listOfString_o, CX_DEFINED)) {
        cx_collection(tc_stringser_listOfString_o)->elementType = cx_resolve_ext(tc_stringser_listOfString_o, NULL, "::corto::lang::string", FALSE, "element ::tc_stringser::listOfString.elementType");
        cx_collection(tc_stringser_listOfString_o)->max = 3;
        if (cx_define(tc_stringser_listOfString_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::listOfString'.");
            goto error;
        }
    }

    if (cx_type(tc_stringser_listOfString_o)->size != sizeof(tc_stringser_listOfString)) {
        cx_error("tc_stringser_load: calculated size '%d' of type '::tc_stringser::listOfString' doesn't match C-type size '%d'", cx_type(tc_stringser_listOfString_o)->size, sizeof(tc_stringser_listOfString));
    }

    /* Declare ::tc_stringser::moveMode */
    tc_stringser_moveMode_o = cx_declareChild(tc_stringser_o, "moveMode", cx_type(cx_bitmask_o));
    if (!tc_stringser_moveMode_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::moveMode'.");
        goto error;
    }

    /* Define ::tc_stringser::listOfMoveMode */
    if (!cx_checkState(tc_stringser_listOfMoveMode_o, CX_DEFINED)) {
        cx_collection(tc_stringser_listOfMoveMode_o)->elementType = cx_resolve_ext(tc_stringser_listOfMoveMode_o, NULL, "::tc_stringser::moveMode", FALSE, "element ::tc_stringser::listOfMoveMode.elementType");
        cx_collection(tc_stringser_listOfMoveMode_o)->max = 3;
        if (cx_define(tc_stringser_listOfMoveMode_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::listOfMoveMode'.");
            goto error;
        }
    }

    if (cx_type(tc_stringser_listOfMoveMode_o)->size != sizeof(tc_stringser_listOfMoveMode)) {
        cx_error("tc_stringser_load: calculated size '%d' of type '::tc_stringser::listOfMoveMode' doesn't match C-type size '%d'", cx_type(tc_stringser_listOfMoveMode_o)->size, sizeof(tc_stringser_listOfMoveMode));
    }

    /* Declare ::tc_stringser::moveMode::FLY */
    tc_stringser_moveMode_FLY_o = cx_declareChild(tc_stringser_moveMode_o, "FLY", cx_type(cx_constant_o));
    if (!tc_stringser_moveMode_FLY_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::moveMode::FLY'.");
        goto error;
    } else {
        (*tc_stringser_moveMode_FLY_o) = 4;
    }

    /* Declare ::tc_stringser::moveMode::SWIM */
    tc_stringser_moveMode_SWIM_o = cx_declareChild(tc_stringser_moveMode_o, "SWIM", cx_type(cx_constant_o));
    if (!tc_stringser_moveMode_SWIM_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::moveMode::SWIM'.");
        goto error;
    } else {
        (*tc_stringser_moveMode_SWIM_o) = 2;
    }

    /* Declare ::tc_stringser::moveMode::WALK */
    tc_stringser_moveMode_WALK_o = cx_declareChild(tc_stringser_moveMode_o, "WALK", cx_type(cx_constant_o));
    if (!tc_stringser_moveMode_WALK_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::moveMode::WALK'.");
        goto error;
    } else {
        (*tc_stringser_moveMode_WALK_o) = 1;
    }

    /* Define ::tc_stringser::moveMode */
    if (!cx_checkState(tc_stringser_moveMode_o, CX_DEFINED)) {
        if (cx_define(tc_stringser_moveMode_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::moveMode'.");
            goto error;
        }
    }

    if (cx_type(tc_stringser_moveMode_o)->size != sizeof(tc_stringser_moveMode)) {
        cx_error("tc_stringser_load: calculated size '%d' of type '::tc_stringser::moveMode' doesn't match C-type size '%d'", cx_type(tc_stringser_moveMode_o)->size, sizeof(tc_stringser_moveMode));
    }

    /* Define ::tc_stringser::arrayOfMoveMode */
    if (!cx_checkState(tc_stringser_arrayOfMoveMode_o, CX_DEFINED)) {
        cx_collection(tc_stringser_arrayOfMoveMode_o)->elementType = cx_resolve_ext(tc_stringser_arrayOfMoveMode_o, NULL, "::tc_stringser::moveMode", FALSE, "element ::tc_stringser::arrayOfMoveMode.elementType");
        cx_collection(tc_stringser_arrayOfMoveMode_o)->max = 3;
        tc_stringser_arrayOfMoveMode_o->elementType = cx_resolve_ext(tc_stringser_arrayOfMoveMode_o, NULL, "::tc_stringser::moveMode", FALSE, "element ::tc_stringser::arrayOfMoveMode.elementType");
        if (cx_define(tc_stringser_arrayOfMoveMode_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::arrayOfMoveMode'.");
            goto error;
        }
    }

    if (cx_type(tc_stringser_arrayOfMoveMode_o)->size != sizeof(tc_stringser_arrayOfMoveMode)) {
        cx_error("tc_stringser_load: calculated size '%d' of type '::tc_stringser::arrayOfMoveMode' doesn't match C-type size '%d'", cx_type(tc_stringser_arrayOfMoveMode_o)->size, sizeof(tc_stringser_arrayOfMoveMode));
    }

    /* Define ::tc_stringser::classInherit::g */
    if (!cx_checkState(tc_stringser_classInherit_g_o, CX_DEFINED)) {
        tc_stringser_classInherit_g_o->type = cx_resolve_ext(tc_stringser_classInherit_g_o, NULL, "::tc_stringser::moveMode", FALSE, "element ::tc_stringser::classInherit::g.type");
        tc_stringser_classInherit_g_o->modifiers = 0x0;
        tc_stringser_classInherit_g_o->state = 0x6;
        tc_stringser_classInherit_g_o->weak = FALSE;
        tc_stringser_classInherit_g_o->id = 6;
        if (cx_define(tc_stringser_classInherit_g_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::classInherit::g'.");
            goto error;
        }
    }

    /* Define ::tc_stringser::classPrimitives::g */
    if (!cx_checkState(tc_stringser_classPrimitives_g_o, CX_DEFINED)) {
        tc_stringser_classPrimitives_g_o->type = cx_resolve_ext(tc_stringser_classPrimitives_g_o, NULL, "::tc_stringser::moveMode", FALSE, "element ::tc_stringser::classPrimitives::g.type");
        tc_stringser_classPrimitives_g_o->modifiers = 0x0;
        tc_stringser_classPrimitives_g_o->state = 0x6;
        tc_stringser_classPrimitives_g_o->weak = FALSE;
        tc_stringser_classPrimitives_g_o->id = 6;
        if (cx_define(tc_stringser_classPrimitives_g_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::classPrimitives::g'.");
            goto error;
        }
    }

    /* Define ::tc_stringser::classPrimitives */
    if (!cx_checkState(tc_stringser_classPrimitives_o, CX_DEFINED)) {
        cx_type(tc_stringser_classPrimitives_o)->defaultType = cx_resolve_ext(tc_stringser_classPrimitives_o, NULL, "::corto::lang::member", FALSE, "element ::tc_stringser::classPrimitives.defaultType");
        cx_type(tc_stringser_classPrimitives_o)->parentType = NULL;
        cx_type(tc_stringser_classPrimitives_o)->parentState = 0x0;
        cx_interface(tc_stringser_classPrimitives_o)->base = NULL;
        cx_struct(tc_stringser_classPrimitives_o)->baseAccess = 0x0;
        tc_stringser_classPrimitives_o->implements.length = 0;
        tc_stringser_classPrimitives_o->implements.buffer = NULL;
        if (cx_define(tc_stringser_classPrimitives_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::classPrimitives'.");
            goto error;
        }
    }

    if (cx_type(tc_stringser_classPrimitives_o)->size != sizeof(struct tc_stringser_classPrimitives_s)) {
        cx_error("tc_stringser_load: calculated size '%d' of type '::tc_stringser::classPrimitives' doesn't match C-type size '%d'", cx_type(tc_stringser_classPrimitives_o)->size, sizeof(struct tc_stringser_classPrimitives_s));
    }

    /* Define ::tc_stringser::arrayOfClassPrimitives */
    if (!cx_checkState(tc_stringser_arrayOfClassPrimitives_o, CX_DEFINED)) {
        cx_collection(tc_stringser_arrayOfClassPrimitives_o)->elementType = cx_resolve_ext(tc_stringser_arrayOfClassPrimitives_o, NULL, "::tc_stringser::classPrimitives", FALSE, "element ::tc_stringser::arrayOfClassPrimitives.elementType");
        cx_collection(tc_stringser_arrayOfClassPrimitives_o)->max = 3;
        tc_stringser_arrayOfClassPrimitives_o->elementType = cx_resolve_ext(tc_stringser_arrayOfClassPrimitives_o, NULL, "::tc_stringser::classPrimitives", FALSE, "element ::tc_stringser::arrayOfClassPrimitives.elementType");
        if (cx_define(tc_stringser_arrayOfClassPrimitives_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::arrayOfClassPrimitives'.");
            goto error;
        }
    }

    if (cx_type(tc_stringser_arrayOfClassPrimitives_o)->size != sizeof(tc_stringser_arrayOfClassPrimitives)) {
        cx_error("tc_stringser_load: calculated size '%d' of type '::tc_stringser::arrayOfClassPrimitives' doesn't match C-type size '%d'", cx_type(tc_stringser_arrayOfClassPrimitives_o)->size, sizeof(tc_stringser_arrayOfClassPrimitives));
    }

    /* Define ::tc_stringser::classInherit */
    if (!cx_checkState(tc_stringser_classInherit_o, CX_DEFINED)) {
        cx_type(tc_stringser_classInherit_o)->defaultType = cx_resolve_ext(tc_stringser_classInherit_o, NULL, "::corto::lang::member", FALSE, "element ::tc_stringser::classInherit.defaultType");
        cx_type(tc_stringser_classInherit_o)->parentType = NULL;
        cx_type(tc_stringser_classInherit_o)->parentState = 0x0;
        cx_interface(tc_stringser_classInherit_o)->base = cx_resolve_ext(tc_stringser_classInherit_o, NULL, "::tc_stringser::classPrimitives", FALSE, "element ::tc_stringser::classInherit.base");
        cx_struct(tc_stringser_classInherit_o)->baseAccess = 0x0;
        tc_stringser_classInherit_o->implements.length = 0;
        tc_stringser_classInherit_o->implements.buffer = NULL;
        if (cx_define(tc_stringser_classInherit_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::classInherit'.");
            goto error;
        }
    }

    if (cx_type(tc_stringser_classInherit_o)->size != sizeof(struct tc_stringser_classInherit_s)) {
        cx_error("tc_stringser_load: calculated size '%d' of type '::tc_stringser::classInherit' doesn't match C-type size '%d'", cx_type(tc_stringser_classInherit_o)->size, sizeof(struct tc_stringser_classInherit_s));
    }

    /* Define ::tc_stringser::arrayOfClassInherit */
    if (!cx_checkState(tc_stringser_arrayOfClassInherit_o, CX_DEFINED)) {
        cx_collection(tc_stringser_arrayOfClassInherit_o)->elementType = cx_resolve_ext(tc_stringser_arrayOfClassInherit_o, NULL, "::tc_stringser::classInherit", FALSE, "element ::tc_stringser::arrayOfClassInherit.elementType");
        cx_collection(tc_stringser_arrayOfClassInherit_o)->max = 3;
        tc_stringser_arrayOfClassInherit_o->elementType = cx_resolve_ext(tc_stringser_arrayOfClassInherit_o, NULL, "::tc_stringser::classInherit", FALSE, "element ::tc_stringser::arrayOfClassInherit.elementType");
        if (cx_define(tc_stringser_arrayOfClassInherit_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::arrayOfClassInherit'.");
            goto error;
        }
    }

    if (cx_type(tc_stringser_arrayOfClassInherit_o)->size != sizeof(tc_stringser_arrayOfClassInherit)) {
        cx_error("tc_stringser_load: calculated size '%d' of type '::tc_stringser::arrayOfClassInherit' doesn't match C-type size '%d'", cx_type(tc_stringser_arrayOfClassInherit_o)->size, sizeof(tc_stringser_arrayOfClassInherit));
    }

    /* Define ::tc_stringser::classCompositeCollection::a */
    if (!cx_checkState(tc_stringser_classCompositeCollection_a_o, CX_DEFINED)) {
        tc_stringser_classCompositeCollection_a_o->type = cx_resolve_ext(tc_stringser_classCompositeCollection_a_o, NULL, "::tc_stringser::arrayOfClassInherit", FALSE, "element ::tc_stringser::classCompositeCollection::a.type");
        tc_stringser_classCompositeCollection_a_o->modifiers = 0x0;
        tc_stringser_classCompositeCollection_a_o->state = 0x6;
        tc_stringser_classCompositeCollection_a_o->weak = FALSE;
        tc_stringser_classCompositeCollection_a_o->id = 0;
        if (cx_define(tc_stringser_classCompositeCollection_a_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::classCompositeCollection::a'.");
            goto error;
        }
    }

    /* Define ::tc_stringser::classNested::b */
    if (!cx_checkState(tc_stringser_classNested_b_o, CX_DEFINED)) {
        tc_stringser_classNested_b_o->type = cx_resolve_ext(tc_stringser_classNested_b_o, NULL, "::tc_stringser::classInherit", FALSE, "element ::tc_stringser::classNested::b.type");
        tc_stringser_classNested_b_o->modifiers = 0x0;
        tc_stringser_classNested_b_o->state = 0x6;
        tc_stringser_classNested_b_o->weak = FALSE;
        tc_stringser_classNested_b_o->id = 1;
        if (cx_define(tc_stringser_classNested_b_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::classNested::b'.");
            goto error;
        }
    }

    /* Define ::tc_stringser::classNested::a */
    if (!cx_checkState(tc_stringser_classNested_a_o, CX_DEFINED)) {
        tc_stringser_classNested_a_o->type = cx_resolve_ext(tc_stringser_classNested_a_o, NULL, "::tc_stringser::classPrimitives", FALSE, "element ::tc_stringser::classNested::a.type");
        tc_stringser_classNested_a_o->modifiers = 0x0;
        tc_stringser_classNested_a_o->state = 0x6;
        tc_stringser_classNested_a_o->weak = FALSE;
        tc_stringser_classNested_a_o->id = 0;
        if (cx_define(tc_stringser_classNested_a_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::classNested::a'.");
            goto error;
        }
    }

    /* Declare ::tc_stringser::sequenceOfMoveMode */
    tc_stringser_sequenceOfMoveMode_o = cx_declareChild(tc_stringser_o, "sequenceOfMoveMode", cx_type(cx_sequence_o));
    if (!tc_stringser_sequenceOfMoveMode_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::sequenceOfMoveMode'.");
        goto error;
    }

    /* Define ::tc_stringser::sequenceOfMoveMode */
    if (!cx_checkState(tc_stringser_sequenceOfMoveMode_o, CX_DEFINED)) {
        cx_collection(tc_stringser_sequenceOfMoveMode_o)->elementType = cx_resolve_ext(tc_stringser_sequenceOfMoveMode_o, NULL, "::tc_stringser::moveMode", FALSE, "element ::tc_stringser::sequenceOfMoveMode.elementType");
        cx_collection(tc_stringser_sequenceOfMoveMode_o)->max = 3;
        if (cx_define(tc_stringser_sequenceOfMoveMode_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::sequenceOfMoveMode'.");
            goto error;
        }
    }

    if (cx_type(tc_stringser_sequenceOfMoveMode_o)->size != sizeof(tc_stringser_sequenceOfMoveMode)) {
        cx_error("tc_stringser_load: calculated size '%d' of type '::tc_stringser::sequenceOfMoveMode' doesn't match C-type size '%d'", cx_type(tc_stringser_sequenceOfMoveMode_o)->size, sizeof(tc_stringser_sequenceOfMoveMode));
    }

    /* Declare ::tc_stringser::sequenceOfBool */
    tc_stringser_sequenceOfBool_o = cx_declareChild(tc_stringser_o, "sequenceOfBool", cx_type(cx_sequence_o));
    if (!tc_stringser_sequenceOfBool_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::sequenceOfBool'.");
        goto error;
    }

    /* Define ::tc_stringser::sequenceOfBool */
    if (!cx_checkState(tc_stringser_sequenceOfBool_o, CX_DEFINED)) {
        cx_collection(tc_stringser_sequenceOfBool_o)->elementType = cx_resolve_ext(tc_stringser_sequenceOfBool_o, NULL, "::corto::lang::bool", FALSE, "element ::tc_stringser::sequenceOfBool.elementType");
        cx_collection(tc_stringser_sequenceOfBool_o)->max = 3;
        if (cx_define(tc_stringser_sequenceOfBool_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::sequenceOfBool'.");
            goto error;
        }
    }

    if (cx_type(tc_stringser_sequenceOfBool_o)->size != sizeof(tc_stringser_sequenceOfBool)) {
        cx_error("tc_stringser_load: calculated size '%d' of type '::tc_stringser::sequenceOfBool' doesn't match C-type size '%d'", cx_type(tc_stringser_sequenceOfBool_o)->size, sizeof(tc_stringser_sequenceOfBool));
    }

    /* Declare ::tc_stringser::sequenceOfChar */
    tc_stringser_sequenceOfChar_o = cx_declareChild(tc_stringser_o, "sequenceOfChar", cx_type(cx_sequence_o));
    if (!tc_stringser_sequenceOfChar_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::sequenceOfChar'.");
        goto error;
    }

    /* Define ::tc_stringser::sequenceOfChar */
    if (!cx_checkState(tc_stringser_sequenceOfChar_o, CX_DEFINED)) {
        cx_collection(tc_stringser_sequenceOfChar_o)->elementType = cx_resolve_ext(tc_stringser_sequenceOfChar_o, NULL, "::corto::lang::char", FALSE, "element ::tc_stringser::sequenceOfChar.elementType");
        cx_collection(tc_stringser_sequenceOfChar_o)->max = 3;
        if (cx_define(tc_stringser_sequenceOfChar_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::sequenceOfChar'.");
            goto error;
        }
    }

    if (cx_type(tc_stringser_sequenceOfChar_o)->size != sizeof(tc_stringser_sequenceOfChar)) {
        cx_error("tc_stringser_load: calculated size '%d' of type '::tc_stringser::sequenceOfChar' doesn't match C-type size '%d'", cx_type(tc_stringser_sequenceOfChar_o)->size, sizeof(tc_stringser_sequenceOfChar));
    }

    /* Declare ::tc_stringser::sequenceOfFloat */
    tc_stringser_sequenceOfFloat_o = cx_declareChild(tc_stringser_o, "sequenceOfFloat", cx_type(cx_sequence_o));
    if (!tc_stringser_sequenceOfFloat_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::sequenceOfFloat'.");
        goto error;
    }

    /* Define ::tc_stringser::sequenceOfFloat */
    if (!cx_checkState(tc_stringser_sequenceOfFloat_o, CX_DEFINED)) {
        cx_collection(tc_stringser_sequenceOfFloat_o)->elementType = cx_resolve_ext(tc_stringser_sequenceOfFloat_o, NULL, "::corto::lang::float32", FALSE, "element ::tc_stringser::sequenceOfFloat.elementType");
        cx_collection(tc_stringser_sequenceOfFloat_o)->max = 3;
        if (cx_define(tc_stringser_sequenceOfFloat_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::sequenceOfFloat'.");
            goto error;
        }
    }

    if (cx_type(tc_stringser_sequenceOfFloat_o)->size != sizeof(tc_stringser_sequenceOfFloat)) {
        cx_error("tc_stringser_load: calculated size '%d' of type '::tc_stringser::sequenceOfFloat' doesn't match C-type size '%d'", cx_type(tc_stringser_sequenceOfFloat_o)->size, sizeof(tc_stringser_sequenceOfFloat));
    }

    /* Declare ::tc_stringser::sequenceOfInt */
    tc_stringser_sequenceOfInt_o = cx_declareChild(tc_stringser_o, "sequenceOfInt", cx_type(cx_sequence_o));
    if (!tc_stringser_sequenceOfInt_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::sequenceOfInt'.");
        goto error;
    }

    /* Define ::tc_stringser::sequenceOfInt */
    if (!cx_checkState(tc_stringser_sequenceOfInt_o, CX_DEFINED)) {
        cx_collection(tc_stringser_sequenceOfInt_o)->elementType = cx_resolve_ext(tc_stringser_sequenceOfInt_o, NULL, "::corto::lang::int32", FALSE, "element ::tc_stringser::sequenceOfInt.elementType");
        cx_collection(tc_stringser_sequenceOfInt_o)->max = 3;
        if (cx_define(tc_stringser_sequenceOfInt_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::sequenceOfInt'.");
            goto error;
        }
    }

    if (cx_type(tc_stringser_sequenceOfInt_o)->size != sizeof(tc_stringser_sequenceOfInt)) {
        cx_error("tc_stringser_load: calculated size '%d' of type '::tc_stringser::sequenceOfInt' doesn't match C-type size '%d'", cx_type(tc_stringser_sequenceOfInt_o)->size, sizeof(tc_stringser_sequenceOfInt));
    }

    /* Define ::tc_stringser::classNested::d */
    if (!cx_checkState(tc_stringser_classNested_d_o, CX_DEFINED)) {
        tc_stringser_classNested_d_o->type = cx_resolve_ext(tc_stringser_classNested_d_o, NULL, "::tc_stringser::sequenceOfInt", FALSE, "element ::tc_stringser::classNested::d.type");
        tc_stringser_classNested_d_o->modifiers = 0x0;
        tc_stringser_classNested_d_o->state = 0x6;
        tc_stringser_classNested_d_o->weak = FALSE;
        tc_stringser_classNested_d_o->id = 3;
        if (cx_define(tc_stringser_classNested_d_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::classNested::d'.");
            goto error;
        }
    }

    /* Define ::tc_stringser::classNested */
    if (!cx_checkState(tc_stringser_classNested_o, CX_DEFINED)) {
        cx_type(tc_stringser_classNested_o)->defaultType = cx_resolve_ext(tc_stringser_classNested_o, NULL, "::corto::lang::member", FALSE, "element ::tc_stringser::classNested.defaultType");
        cx_type(tc_stringser_classNested_o)->parentType = NULL;
        cx_type(tc_stringser_classNested_o)->parentState = 0x0;
        cx_interface(tc_stringser_classNested_o)->base = NULL;
        cx_struct(tc_stringser_classNested_o)->baseAccess = 0x0;
        tc_stringser_classNested_o->implements.length = 0;
        tc_stringser_classNested_o->implements.buffer = NULL;
        if (cx_define(tc_stringser_classNested_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::classNested'.");
            goto error;
        }
    }

    if (cx_type(tc_stringser_classNested_o)->size != sizeof(struct tc_stringser_classNested_s)) {
        cx_error("tc_stringser_load: calculated size '%d' of type '::tc_stringser::classNested' doesn't match C-type size '%d'", cx_type(tc_stringser_classNested_o)->size, sizeof(struct tc_stringser_classNested_s));
    }

    /* Define ::tc_stringser::arrayOfClassNested */
    if (!cx_checkState(tc_stringser_arrayOfClassNested_o, CX_DEFINED)) {
        cx_collection(tc_stringser_arrayOfClassNested_o)->elementType = cx_resolve_ext(tc_stringser_arrayOfClassNested_o, NULL, "::tc_stringser::classNested", FALSE, "element ::tc_stringser::arrayOfClassNested.elementType");
        cx_collection(tc_stringser_arrayOfClassNested_o)->max = 3;
        tc_stringser_arrayOfClassNested_o->elementType = cx_resolve_ext(tc_stringser_arrayOfClassNested_o, NULL, "::tc_stringser::classNested", FALSE, "element ::tc_stringser::arrayOfClassNested.elementType");
        if (cx_define(tc_stringser_arrayOfClassNested_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::arrayOfClassNested'.");
            goto error;
        }
    }

    if (cx_type(tc_stringser_arrayOfClassNested_o)->size != sizeof(tc_stringser_arrayOfClassNested)) {
        cx_error("tc_stringser_load: calculated size '%d' of type '::tc_stringser::arrayOfClassNested' doesn't match C-type size '%d'", cx_type(tc_stringser_arrayOfClassNested_o)->size, sizeof(tc_stringser_arrayOfClassNested));
    }

    /* Define ::tc_stringser::classCompositeCollection::b */
    if (!cx_checkState(tc_stringser_classCompositeCollection_b_o, CX_DEFINED)) {
        tc_stringser_classCompositeCollection_b_o->type = cx_resolve_ext(tc_stringser_classCompositeCollection_b_o, NULL, "::tc_stringser::arrayOfClassNested", FALSE, "element ::tc_stringser::classCompositeCollection::b.type");
        tc_stringser_classCompositeCollection_b_o->modifiers = 0x0;
        tc_stringser_classCompositeCollection_b_o->state = 0x6;
        tc_stringser_classCompositeCollection_b_o->weak = FALSE;
        tc_stringser_classCompositeCollection_b_o->id = 1;
        if (cx_define(tc_stringser_classCompositeCollection_b_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::classCompositeCollection::b'.");
            goto error;
        }
    }

    /* Define ::tc_stringser::classCompositeCollection */
    if (!cx_checkState(tc_stringser_classCompositeCollection_o, CX_DEFINED)) {
        cx_type(tc_stringser_classCompositeCollection_o)->defaultType = cx_resolve_ext(tc_stringser_classCompositeCollection_o, NULL, "::corto::lang::member", FALSE, "element ::tc_stringser::classCompositeCollection.defaultType");
        cx_type(tc_stringser_classCompositeCollection_o)->parentType = NULL;
        cx_type(tc_stringser_classCompositeCollection_o)->parentState = 0x0;
        cx_interface(tc_stringser_classCompositeCollection_o)->base = NULL;
        cx_struct(tc_stringser_classCompositeCollection_o)->baseAccess = 0x0;
        tc_stringser_classCompositeCollection_o->implements.length = 0;
        tc_stringser_classCompositeCollection_o->implements.buffer = NULL;
        if (cx_define(tc_stringser_classCompositeCollection_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::classCompositeCollection'.");
            goto error;
        }
    }

    if (cx_type(tc_stringser_classCompositeCollection_o)->size != sizeof(struct tc_stringser_classCompositeCollection_s)) {
        cx_error("tc_stringser_load: calculated size '%d' of type '::tc_stringser::classCompositeCollection' doesn't match C-type size '%d'", cx_type(tc_stringser_classCompositeCollection_o)->size, sizeof(struct tc_stringser_classCompositeCollection_s));
    }

    /* Declare ::tc_stringser::sequenceOfString */
    tc_stringser_sequenceOfString_o = cx_declareChild(tc_stringser_o, "sequenceOfString", cx_type(cx_sequence_o));
    if (!tc_stringser_sequenceOfString_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::sequenceOfString'.");
        goto error;
    }

    /* Define ::tc_stringser::sequenceOfString */
    if (!cx_checkState(tc_stringser_sequenceOfString_o, CX_DEFINED)) {
        cx_collection(tc_stringser_sequenceOfString_o)->elementType = cx_resolve_ext(tc_stringser_sequenceOfString_o, NULL, "::corto::lang::string", FALSE, "element ::tc_stringser::sequenceOfString.elementType");
        cx_collection(tc_stringser_sequenceOfString_o)->max = 3;
        if (cx_define(tc_stringser_sequenceOfString_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::sequenceOfString'.");
            goto error;
        }
    }

    if (cx_type(tc_stringser_sequenceOfString_o)->size != sizeof(tc_stringser_sequenceOfString)) {
        cx_error("tc_stringser_load: calculated size '%d' of type '::tc_stringser::sequenceOfString' doesn't match C-type size '%d'", cx_type(tc_stringser_sequenceOfString_o)->size, sizeof(tc_stringser_sequenceOfString));
    }

    if (_a_) {
        cx_release(_a_);
    }

    return 0;
error:
    return -1;
}
