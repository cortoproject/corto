/* tc_stringser__meta.c
 *
 * Loads objects in object store.
 * This file contains generated code. Do not modify!
 */

#define tc_stringser_LIB
#include "tc.h"

/* Variable definitions */
cx_package tc_o;
cx_array tc_arrayOfBool_o;
cx_array tc_arrayOfChar_o;
cx_array tc_arrayOfClassInherit_o;
cx_array tc_arrayOfClassNested_o;
cx_array tc_arrayOfClassPrimitives_o;
cx_array tc_arrayOfColor_o;
cx_array tc_arrayOfFloat_o;
cx_array tc_arrayOfInt_o;
cx_array tc_arrayOfMoveMode_o;
cx_array tc_arrayOfString_o;
cx_class tc_classCompositeCollection_o;
cx_member tc_classCompositeCollection_a_o;
cx_member tc_classCompositeCollection_b_o;
cx_member tc_classCompositeCollection_c_o;
cx_member tc_classCompositeCollection_d_o;
cx_member tc_classCompositeCollection_e_o;
cx_member tc_classCompositeCollection_f_o;
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
cx_constant ___ (*tc_color_BLUE_o);
cx_constant ___ (*tc_color_RED_o);
cx_constant ___ (*tc_color_YELLOW_o);
cx_list tc_listOfBool_o;
cx_list tc_listOfChar_o;
cx_list tc_listOfClassInherit_o;
cx_list tc_listOfClassNested_o;
cx_list tc_listOfClassPrimitives_o;
cx_list tc_listOfColor_o;
cx_list tc_listOfFloat_o;
cx_list tc_listOfInt_o;
cx_list tc_listOfMoveMode_o;
cx_list tc_listOfString_o;
cx_bitmask tc_moveMode_o;
cx_constant ___ (*tc_moveMode_FLY_o);
cx_constant ___ (*tc_moveMode_SWIM_o);
cx_constant ___ (*tc_moveMode_WALK_o);
cx_sequence tc_sequenceOfBool_o;
cx_sequence tc_sequenceOfChar_o;
cx_sequence tc_sequenceOfClassInherit_o;
cx_sequence tc_sequenceOfClassNested_o;
cx_sequence tc_sequenceOfClassPrimitives_o;
cx_sequence tc_sequenceOfColor_o;
cx_sequence tc_sequenceOfFloat_o;
cx_sequence tc_sequenceOfInt_o;
cx_sequence tc_sequenceOfMoveMode_o;
cx_sequence tc_sequenceOfString_o;

/* Load objects in object store. */
int tc_stringser_load(void) {
    cx_object _a_; /* Used for resolving anonymous objects */
    _a_ = NULL;

    /* Declare ::tc_stringser */
    tc_o = cx_declareChild(root_o, "tc_stringser", cx_package_o);
    if (!tc_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser'.");
        goto error;
    }

    /* Define ::tc_stringser */
    if (!cx_checkState(tc_o, CX_DEFINED)) {
        tc_o->url = NULL;
        if (cx_define(tc_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser'.");
            goto error;
        }
    }

    /* Declare ::tc_stringser::arrayOfBool */
    tc_arrayOfBool_o = cx_declareChild(tc_o, "arrayOfBool", cx_array_o);
    if (!tc_arrayOfBool_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::arrayOfBool'.");
        goto error;
    }

    /* Define ::tc_stringser::arrayOfBool */
    if (!cx_checkState(tc_arrayOfBool_o, CX_DEFINED)) {
        cx_collection(tc_arrayOfBool_o)->elementType = cx_resolve(NULL, "::corto::lang::bool");
        cx_collection(tc_arrayOfBool_o)->max = 3;
        tc_arrayOfBool_o->elementType = cx_resolve(NULL, "::corto::lang::bool");
        if (cx_define(tc_arrayOfBool_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::arrayOfBool'.");
            goto error;
        }
    }

    if (cx_type(tc_arrayOfBool_o)->size != sizeof(tc_arrayOfBool)) {
        cx_error("tc_stringser_load: calculated size '%d' of type '::tc_stringser::arrayOfBool' doesn't match C-type size '%d'", cx_type(tc_arrayOfBool_o)->size, sizeof(tc_arrayOfBool));
    }

    /* Declare ::tc_stringser::arrayOfChar */
    tc_arrayOfChar_o = cx_declareChild(tc_o, "arrayOfChar", cx_array_o);
    if (!tc_arrayOfChar_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::arrayOfChar'.");
        goto error;
    }

    /* Define ::tc_stringser::arrayOfChar */
    if (!cx_checkState(tc_arrayOfChar_o, CX_DEFINED)) {
        cx_collection(tc_arrayOfChar_o)->elementType = cx_resolve(NULL, "::corto::lang::char");
        cx_collection(tc_arrayOfChar_o)->max = 3;
        tc_arrayOfChar_o->elementType = cx_resolve(NULL, "::corto::lang::char");
        if (cx_define(tc_arrayOfChar_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::arrayOfChar'.");
            goto error;
        }
    }

    if (cx_type(tc_arrayOfChar_o)->size != sizeof(tc_arrayOfChar)) {
        cx_error("tc_stringser_load: calculated size '%d' of type '::tc_stringser::arrayOfChar' doesn't match C-type size '%d'", cx_type(tc_arrayOfChar_o)->size, sizeof(tc_arrayOfChar));
    }

    /* Declare ::tc_stringser::arrayOfClassInherit */
    tc_arrayOfClassInherit_o = cx_declareChild(tc_o, "arrayOfClassInherit", cx_array_o);
    if (!tc_arrayOfClassInherit_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::arrayOfClassInherit'.");
        goto error;
    }

    /* Declare ::tc_stringser::arrayOfClassNested */
    tc_arrayOfClassNested_o = cx_declareChild(tc_o, "arrayOfClassNested", cx_array_o);
    if (!tc_arrayOfClassNested_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::arrayOfClassNested'.");
        goto error;
    }

    /* Declare ::tc_stringser::arrayOfClassPrimitives */
    tc_arrayOfClassPrimitives_o = cx_declareChild(tc_o, "arrayOfClassPrimitives", cx_array_o);
    if (!tc_arrayOfClassPrimitives_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::arrayOfClassPrimitives'.");
        goto error;
    }

    /* Declare ::tc_stringser::arrayOfColor */
    tc_arrayOfColor_o = cx_declareChild(tc_o, "arrayOfColor", cx_array_o);
    if (!tc_arrayOfColor_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::arrayOfColor'.");
        goto error;
    }

    /* Declare ::tc_stringser::arrayOfFloat */
    tc_arrayOfFloat_o = cx_declareChild(tc_o, "arrayOfFloat", cx_array_o);
    if (!tc_arrayOfFloat_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::arrayOfFloat'.");
        goto error;
    }

    /* Define ::tc_stringser::arrayOfFloat */
    if (!cx_checkState(tc_arrayOfFloat_o, CX_DEFINED)) {
        cx_collection(tc_arrayOfFloat_o)->elementType = cx_resolve(NULL, "::corto::lang::float32");
        cx_collection(tc_arrayOfFloat_o)->max = 3;
        tc_arrayOfFloat_o->elementType = cx_resolve(NULL, "::corto::lang::float32");
        if (cx_define(tc_arrayOfFloat_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::arrayOfFloat'.");
            goto error;
        }
    }

    if (cx_type(tc_arrayOfFloat_o)->size != sizeof(tc_arrayOfFloat)) {
        cx_error("tc_stringser_load: calculated size '%d' of type '::tc_stringser::arrayOfFloat' doesn't match C-type size '%d'", cx_type(tc_arrayOfFloat_o)->size, sizeof(tc_arrayOfFloat));
    }

    /* Declare ::tc_stringser::arrayOfInt */
    tc_arrayOfInt_o = cx_declareChild(tc_o, "arrayOfInt", cx_array_o);
    if (!tc_arrayOfInt_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::arrayOfInt'.");
        goto error;
    }

    /* Define ::tc_stringser::arrayOfInt */
    if (!cx_checkState(tc_arrayOfInt_o, CX_DEFINED)) {
        cx_collection(tc_arrayOfInt_o)->elementType = cx_resolve(NULL, "::corto::lang::int32");
        cx_collection(tc_arrayOfInt_o)->max = 3;
        tc_arrayOfInt_o->elementType = cx_resolve(NULL, "::corto::lang::int32");
        if (cx_define(tc_arrayOfInt_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::arrayOfInt'.");
            goto error;
        }
    }

    if (cx_type(tc_arrayOfInt_o)->size != sizeof(tc_arrayOfInt)) {
        cx_error("tc_stringser_load: calculated size '%d' of type '::tc_stringser::arrayOfInt' doesn't match C-type size '%d'", cx_type(tc_arrayOfInt_o)->size, sizeof(tc_arrayOfInt));
    }

    /* Declare ::tc_stringser::arrayOfMoveMode */
    tc_arrayOfMoveMode_o = cx_declareChild(tc_o, "arrayOfMoveMode", cx_array_o);
    if (!tc_arrayOfMoveMode_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::arrayOfMoveMode'.");
        goto error;
    }

    /* Declare ::tc_stringser::arrayOfString */
    tc_arrayOfString_o = cx_declareChild(tc_o, "arrayOfString", cx_array_o);
    if (!tc_arrayOfString_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::arrayOfString'.");
        goto error;
    }

    /* Define ::tc_stringser::arrayOfString */
    if (!cx_checkState(tc_arrayOfString_o, CX_DEFINED)) {
        cx_collection(tc_arrayOfString_o)->elementType = cx_resolve(NULL, "::corto::lang::string");
        cx_collection(tc_arrayOfString_o)->max = 3;
        tc_arrayOfString_o->elementType = cx_resolve(NULL, "::corto::lang::string");
        if (cx_define(tc_arrayOfString_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::arrayOfString'.");
            goto error;
        }
    }

    if (cx_type(tc_arrayOfString_o)->size != sizeof(tc_arrayOfString)) {
        cx_error("tc_stringser_load: calculated size '%d' of type '::tc_stringser::arrayOfString' doesn't match C-type size '%d'", cx_type(tc_arrayOfString_o)->size, sizeof(tc_arrayOfString));
    }

    /* Declare ::tc_stringser::classCompositeCollection */
    tc_classCompositeCollection_o = cx_declareChild(tc_o, "classCompositeCollection", cx_class_o);
    if (!tc_classCompositeCollection_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::classCompositeCollection'.");
        goto error;
    }

    /* Declare ::tc_stringser::classCompositeCollection::a */
    tc_classCompositeCollection_a_o = cx_declareChild(tc_classCompositeCollection_o, "a", cx_member_o);
    if (!tc_classCompositeCollection_a_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::classCompositeCollection::a'.");
        goto error;
    }

    /* Declare ::tc_stringser::classCompositeCollection::b */
    tc_classCompositeCollection_b_o = cx_declareChild(tc_classCompositeCollection_o, "b", cx_member_o);
    if (!tc_classCompositeCollection_b_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::classCompositeCollection::b'.");
        goto error;
    }

    /* Declare ::tc_stringser::classCompositeCollection::c */
    tc_classCompositeCollection_c_o = cx_declareChild(tc_classCompositeCollection_o, "c", cx_member_o);
    if (!tc_classCompositeCollection_c_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::classCompositeCollection::c'.");
        goto error;
    }

    /* Declare ::tc_stringser::classCompositeCollection::d */
    tc_classCompositeCollection_d_o = cx_declareChild(tc_classCompositeCollection_o, "d", cx_member_o);
    if (!tc_classCompositeCollection_d_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::classCompositeCollection::d'.");
        goto error;
    }

    /* Declare ::tc_stringser::classCompositeCollection::e */
    tc_classCompositeCollection_e_o = cx_declareChild(tc_classCompositeCollection_o, "e", cx_member_o);
    if (!tc_classCompositeCollection_e_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::classCompositeCollection::e'.");
        goto error;
    }

    /* Declare ::tc_stringser::classCompositeCollection::f */
    tc_classCompositeCollection_f_o = cx_declareChild(tc_classCompositeCollection_o, "f", cx_member_o);
    if (!tc_classCompositeCollection_f_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::classCompositeCollection::f'.");
        goto error;
    }

    /* Declare ::tc_stringser::classInherit */
    tc_classInherit_o = cx_declareChild(tc_o, "classInherit", cx_class_o);
    if (!tc_classInherit_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::classInherit'.");
        goto error;
    }

    /* Declare ::tc_stringser::classInherit::a */
    tc_classInherit_a_o = cx_declareChild(tc_classInherit_o, "a", cx_member_o);
    if (!tc_classInherit_a_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::classInherit::a'.");
        goto error;
    }

    /* Define ::tc_stringser::classInherit::a */
    if (!cx_checkState(tc_classInherit_a_o, CX_DEFINED)) {
        tc_classInherit_a_o->type = cx_resolve(NULL, "::corto::lang::bool");
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
    tc_classInherit_b_o = cx_declareChild(tc_classInherit_o, "b", cx_member_o);
    if (!tc_classInherit_b_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::classInherit::b'.");
        goto error;
    }

    /* Define ::tc_stringser::classInherit::b */
    if (!cx_checkState(tc_classInherit_b_o, CX_DEFINED)) {
        tc_classInherit_b_o->type = cx_resolve(NULL, "::corto::lang::char");
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
    tc_classInherit_c_o = cx_declareChild(tc_classInherit_o, "c", cx_member_o);
    if (!tc_classInherit_c_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::classInherit::c'.");
        goto error;
    }

    /* Define ::tc_stringser::classInherit::c */
    if (!cx_checkState(tc_classInherit_c_o, CX_DEFINED)) {
        tc_classInherit_c_o->type = cx_resolve(NULL, "::corto::lang::int32");
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
    tc_classInherit_d_o = cx_declareChild(tc_classInherit_o, "d", cx_member_o);
    if (!tc_classInherit_d_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::classInherit::d'.");
        goto error;
    }

    /* Define ::tc_stringser::classInherit::d */
    if (!cx_checkState(tc_classInherit_d_o, CX_DEFINED)) {
        tc_classInherit_d_o->type = cx_resolve(NULL, "::corto::lang::float32");
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
    tc_classInherit_e_o = cx_declareChild(tc_classInherit_o, "e", cx_member_o);
    if (!tc_classInherit_e_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::classInherit::e'.");
        goto error;
    }

    /* Define ::tc_stringser::classInherit::e */
    if (!cx_checkState(tc_classInherit_e_o, CX_DEFINED)) {
        tc_classInherit_e_o->type = cx_resolve(NULL, "::corto::lang::string");
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
    tc_classInherit_f_o = cx_declareChild(tc_classInherit_o, "f", cx_member_o);
    if (!tc_classInherit_f_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::classInherit::f'.");
        goto error;
    }

    /* Declare ::tc_stringser::classInherit::g */
    tc_classInherit_g_o = cx_declareChild(tc_classInherit_o, "g", cx_member_o);
    if (!tc_classInherit_g_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::classInherit::g'.");
        goto error;
    }

    /* Declare ::tc_stringser::listOfClassInherit */
    tc_listOfClassInherit_o = cx_declareChild(tc_o, "listOfClassInherit", cx_list_o);
    if (!tc_listOfClassInherit_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::listOfClassInherit'.");
        goto error;
    }

    /* Define ::tc_stringser::listOfClassInherit */
    if (!cx_checkState(tc_listOfClassInherit_o, CX_DEFINED)) {
        cx_collection(tc_listOfClassInherit_o)->elementType = cx_resolve(NULL, "::tc_stringser::classInherit");
        cx_collection(tc_listOfClassInherit_o)->max = 3;
        if (cx_define(tc_listOfClassInherit_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::listOfClassInherit'.");
            goto error;
        }
    }

    if (cx_type(tc_listOfClassInherit_o)->size != sizeof(tc_listOfClassInherit)) {
        cx_error("tc_stringser_load: calculated size '%d' of type '::tc_stringser::listOfClassInherit' doesn't match C-type size '%d'", cx_type(tc_listOfClassInherit_o)->size, sizeof(tc_listOfClassInherit));
    }

    /* Define ::tc_stringser::classCompositeCollection::e */
    if (!cx_checkState(tc_classCompositeCollection_e_o, CX_DEFINED)) {
        tc_classCompositeCollection_e_o->type = cx_resolve(NULL, "::tc_stringser::listOfClassInherit");
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
    tc_sequenceOfClassInherit_o = cx_declareChild(tc_o, "sequenceOfClassInherit", cx_sequence_o);
    if (!tc_sequenceOfClassInherit_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::sequenceOfClassInherit'.");
        goto error;
    }

    /* Define ::tc_stringser::sequenceOfClassInherit */
    if (!cx_checkState(tc_sequenceOfClassInherit_o, CX_DEFINED)) {
        cx_collection(tc_sequenceOfClassInherit_o)->elementType = cx_resolve(NULL, "::tc_stringser::classInherit");
        cx_collection(tc_sequenceOfClassInherit_o)->max = 3;
        if (cx_define(tc_sequenceOfClassInherit_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::sequenceOfClassInherit'.");
            goto error;
        }
    }

    if (cx_type(tc_sequenceOfClassInherit_o)->size != sizeof(tc_sequenceOfClassInherit)) {
        cx_error("tc_stringser_load: calculated size '%d' of type '::tc_stringser::sequenceOfClassInherit' doesn't match C-type size '%d'", cx_type(tc_sequenceOfClassInherit_o)->size, sizeof(tc_sequenceOfClassInherit));
    }

    /* Define ::tc_stringser::classCompositeCollection::c */
    if (!cx_checkState(tc_classCompositeCollection_c_o, CX_DEFINED)) {
        tc_classCompositeCollection_c_o->type = cx_resolve(NULL, "::tc_stringser::sequenceOfClassInherit");
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
    tc_classNested_o = cx_declareChild(tc_o, "classNested", cx_class_o);
    if (!tc_classNested_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::classNested'.");
        goto error;
    }

    /* Declare ::tc_stringser::classNested::a */
    tc_classNested_a_o = cx_declareChild(tc_classNested_o, "a", cx_member_o);
    if (!tc_classNested_a_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::classNested::a'.");
        goto error;
    }

    /* Declare ::tc_stringser::classNested::b */
    tc_classNested_b_o = cx_declareChild(tc_classNested_o, "b", cx_member_o);
    if (!tc_classNested_b_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::classNested::b'.");
        goto error;
    }

    /* Declare ::tc_stringser::classNested::c */
    tc_classNested_c_o = cx_declareChild(tc_classNested_o, "c", cx_member_o);
    if (!tc_classNested_c_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::classNested::c'.");
        goto error;
    }

    /* Define ::tc_stringser::classNested::c */
    if (!cx_checkState(tc_classNested_c_o, CX_DEFINED)) {
        tc_classNested_c_o->type = cx_resolve(NULL, "::tc_stringser::arrayOfInt");
        tc_classNested_c_o->modifiers = 0x0;
        tc_classNested_c_o->state = 0x6;
        tc_classNested_c_o->weak = FALSE;
        tc_classNested_c_o->id = 2;
        if (cx_define(tc_classNested_c_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::classNested::c'.");
            goto error;
        }
    }

    /* Declare ::tc_stringser::classNested::d */
    tc_classNested_d_o = cx_declareChild(tc_classNested_o, "d", cx_member_o);
    if (!tc_classNested_d_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::classNested::d'.");
        goto error;
    }

    /* Declare ::tc_stringser::classNested::e */
    tc_classNested_e_o = cx_declareChild(tc_classNested_o, "e", cx_member_o);
    if (!tc_classNested_e_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::classNested::e'.");
        goto error;
    }

    /* Declare ::tc_stringser::listOfClassNested */
    tc_listOfClassNested_o = cx_declareChild(tc_o, "listOfClassNested", cx_list_o);
    if (!tc_listOfClassNested_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::listOfClassNested'.");
        goto error;
    }

    /* Define ::tc_stringser::listOfClassNested */
    if (!cx_checkState(tc_listOfClassNested_o, CX_DEFINED)) {
        cx_collection(tc_listOfClassNested_o)->elementType = cx_resolve(NULL, "::tc_stringser::classNested");
        cx_collection(tc_listOfClassNested_o)->max = 3;
        if (cx_define(tc_listOfClassNested_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::listOfClassNested'.");
            goto error;
        }
    }

    if (cx_type(tc_listOfClassNested_o)->size != sizeof(tc_listOfClassNested)) {
        cx_error("tc_stringser_load: calculated size '%d' of type '::tc_stringser::listOfClassNested' doesn't match C-type size '%d'", cx_type(tc_listOfClassNested_o)->size, sizeof(tc_listOfClassNested));
    }

    /* Define ::tc_stringser::classCompositeCollection::f */
    if (!cx_checkState(tc_classCompositeCollection_f_o, CX_DEFINED)) {
        tc_classCompositeCollection_f_o->type = cx_resolve(NULL, "::tc_stringser::listOfClassNested");
        tc_classCompositeCollection_f_o->modifiers = 0x0;
        tc_classCompositeCollection_f_o->state = 0x6;
        tc_classCompositeCollection_f_o->weak = FALSE;
        tc_classCompositeCollection_f_o->id = 5;
        if (cx_define(tc_classCompositeCollection_f_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::classCompositeCollection::f'.");
            goto error;
        }
    }

    /* Declare ::tc_stringser::sequenceOfClassNested */
    tc_sequenceOfClassNested_o = cx_declareChild(tc_o, "sequenceOfClassNested", cx_sequence_o);
    if (!tc_sequenceOfClassNested_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::sequenceOfClassNested'.");
        goto error;
    }

    /* Define ::tc_stringser::sequenceOfClassNested */
    if (!cx_checkState(tc_sequenceOfClassNested_o, CX_DEFINED)) {
        cx_collection(tc_sequenceOfClassNested_o)->elementType = cx_resolve(NULL, "::tc_stringser::classNested");
        cx_collection(tc_sequenceOfClassNested_o)->max = 3;
        if (cx_define(tc_sequenceOfClassNested_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::sequenceOfClassNested'.");
            goto error;
        }
    }

    if (cx_type(tc_sequenceOfClassNested_o)->size != sizeof(tc_sequenceOfClassNested)) {
        cx_error("tc_stringser_load: calculated size '%d' of type '::tc_stringser::sequenceOfClassNested' doesn't match C-type size '%d'", cx_type(tc_sequenceOfClassNested_o)->size, sizeof(tc_sequenceOfClassNested));
    }

    /* Define ::tc_stringser::classCompositeCollection::d */
    if (!cx_checkState(tc_classCompositeCollection_d_o, CX_DEFINED)) {
        tc_classCompositeCollection_d_o->type = cx_resolve(NULL, "::tc_stringser::sequenceOfClassNested");
        tc_classCompositeCollection_d_o->modifiers = 0x0;
        tc_classCompositeCollection_d_o->state = 0x6;
        tc_classCompositeCollection_d_o->weak = FALSE;
        tc_classCompositeCollection_d_o->id = 3;
        if (cx_define(tc_classCompositeCollection_d_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::classCompositeCollection::d'.");
            goto error;
        }
    }

    /* Declare ::tc_stringser::classPrimitives */
    tc_classPrimitives_o = cx_declareChild(tc_o, "classPrimitives", cx_class_o);
    if (!tc_classPrimitives_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::classPrimitives'.");
        goto error;
    }

    /* Declare ::tc_stringser::classPrimitives::a */
    tc_classPrimitives_a_o = cx_declareChild(tc_classPrimitives_o, "a", cx_member_o);
    if (!tc_classPrimitives_a_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::classPrimitives::a'.");
        goto error;
    }

    /* Define ::tc_stringser::classPrimitives::a */
    if (!cx_checkState(tc_classPrimitives_a_o, CX_DEFINED)) {
        tc_classPrimitives_a_o->type = cx_resolve(NULL, "::corto::lang::bool");
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
    tc_classPrimitives_b_o = cx_declareChild(tc_classPrimitives_o, "b", cx_member_o);
    if (!tc_classPrimitives_b_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::classPrimitives::b'.");
        goto error;
    }

    /* Define ::tc_stringser::classPrimitives::b */
    if (!cx_checkState(tc_classPrimitives_b_o, CX_DEFINED)) {
        tc_classPrimitives_b_o->type = cx_resolve(NULL, "::corto::lang::char");
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
    tc_classPrimitives_c_o = cx_declareChild(tc_classPrimitives_o, "c", cx_member_o);
    if (!tc_classPrimitives_c_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::classPrimitives::c'.");
        goto error;
    }

    /* Define ::tc_stringser::classPrimitives::c */
    if (!cx_checkState(tc_classPrimitives_c_o, CX_DEFINED)) {
        tc_classPrimitives_c_o->type = cx_resolve(NULL, "::corto::lang::int32");
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
    tc_classPrimitives_d_o = cx_declareChild(tc_classPrimitives_o, "d", cx_member_o);
    if (!tc_classPrimitives_d_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::classPrimitives::d'.");
        goto error;
    }

    /* Define ::tc_stringser::classPrimitives::d */
    if (!cx_checkState(tc_classPrimitives_d_o, CX_DEFINED)) {
        tc_classPrimitives_d_o->type = cx_resolve(NULL, "::corto::lang::float32");
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
    tc_classPrimitives_e_o = cx_declareChild(tc_classPrimitives_o, "e", cx_member_o);
    if (!tc_classPrimitives_e_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::classPrimitives::e'.");
        goto error;
    }

    /* Define ::tc_stringser::classPrimitives::e */
    if (!cx_checkState(tc_classPrimitives_e_o, CX_DEFINED)) {
        tc_classPrimitives_e_o->type = cx_resolve(NULL, "::corto::lang::string");
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
    tc_classPrimitives_f_o = cx_declareChild(tc_classPrimitives_o, "f", cx_member_o);
    if (!tc_classPrimitives_f_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::classPrimitives::f'.");
        goto error;
    }

    /* Declare ::tc_stringser::classPrimitives::g */
    tc_classPrimitives_g_o = cx_declareChild(tc_classPrimitives_o, "g", cx_member_o);
    if (!tc_classPrimitives_g_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::classPrimitives::g'.");
        goto error;
    }

    /* Declare ::tc_stringser::listOfClassPrimitives */
    tc_listOfClassPrimitives_o = cx_declareChild(tc_o, "listOfClassPrimitives", cx_list_o);
    if (!tc_listOfClassPrimitives_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::listOfClassPrimitives'.");
        goto error;
    }

    /* Define ::tc_stringser::listOfClassPrimitives */
    if (!cx_checkState(tc_listOfClassPrimitives_o, CX_DEFINED)) {
        cx_collection(tc_listOfClassPrimitives_o)->elementType = cx_resolve(NULL, "::tc_stringser::classPrimitives");
        cx_collection(tc_listOfClassPrimitives_o)->max = 3;
        if (cx_define(tc_listOfClassPrimitives_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::listOfClassPrimitives'.");
            goto error;
        }
    }

    if (cx_type(tc_listOfClassPrimitives_o)->size != sizeof(tc_listOfClassPrimitives)) {
        cx_error("tc_stringser_load: calculated size '%d' of type '::tc_stringser::listOfClassPrimitives' doesn't match C-type size '%d'", cx_type(tc_listOfClassPrimitives_o)->size, sizeof(tc_listOfClassPrimitives));
    }

    /* Declare ::tc_stringser::sequenceOfClassPrimitives */
    tc_sequenceOfClassPrimitives_o = cx_declareChild(tc_o, "sequenceOfClassPrimitives", cx_sequence_o);
    if (!tc_sequenceOfClassPrimitives_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::sequenceOfClassPrimitives'.");
        goto error;
    }

    /* Define ::tc_stringser::sequenceOfClassPrimitives */
    if (!cx_checkState(tc_sequenceOfClassPrimitives_o, CX_DEFINED)) {
        cx_collection(tc_sequenceOfClassPrimitives_o)->elementType = cx_resolve(NULL, "::tc_stringser::classPrimitives");
        cx_collection(tc_sequenceOfClassPrimitives_o)->max = 3;
        if (cx_define(tc_sequenceOfClassPrimitives_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::sequenceOfClassPrimitives'.");
            goto error;
        }
    }

    if (cx_type(tc_sequenceOfClassPrimitives_o)->size != sizeof(tc_sequenceOfClassPrimitives)) {
        cx_error("tc_stringser_load: calculated size '%d' of type '::tc_stringser::sequenceOfClassPrimitives' doesn't match C-type size '%d'", cx_type(tc_sequenceOfClassPrimitives_o)->size, sizeof(tc_sequenceOfClassPrimitives));
    }

    /* Declare ::tc_stringser::color */
    tc_color_o = cx_declareChild(tc_o, "color", cx_enum_o);
    if (!tc_color_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::color'.");
        goto error;
    }

    /* Declare ::tc_stringser::color::BLUE */
    tc_color_BLUE_o = cx_declareChild(tc_color_o, "BLUE", cx_constant_o);
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
    tc_color_RED_o = cx_declareChild(tc_color_o, "RED", cx_constant_o);
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
    tc_color_YELLOW_o = cx_declareChild(tc_color_o, "YELLOW", cx_constant_o);
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

    if (cx_type(tc_color_o)->size != sizeof(tc_color)) {
        cx_error("tc_stringser_load: calculated size '%d' of type '::tc_stringser::color' doesn't match C-type size '%d'", cx_type(tc_color_o)->size, sizeof(tc_color));
    }

    /* Define ::tc_stringser::arrayOfColor */
    if (!cx_checkState(tc_arrayOfColor_o, CX_DEFINED)) {
        cx_collection(tc_arrayOfColor_o)->elementType = cx_resolve(NULL, "::tc_stringser::color");
        cx_collection(tc_arrayOfColor_o)->max = 3;
        tc_arrayOfColor_o->elementType = cx_resolve(NULL, "::tc_stringser::color");
        if (cx_define(tc_arrayOfColor_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::arrayOfColor'.");
            goto error;
        }
    }

    if (cx_type(tc_arrayOfColor_o)->size != sizeof(tc_arrayOfColor)) {
        cx_error("tc_stringser_load: calculated size '%d' of type '::tc_stringser::arrayOfColor' doesn't match C-type size '%d'", cx_type(tc_arrayOfColor_o)->size, sizeof(tc_arrayOfColor));
    }

    /* Define ::tc_stringser::classInherit::f */
    if (!cx_checkState(tc_classInherit_f_o, CX_DEFINED)) {
        tc_classInherit_f_o->type = cx_resolve(NULL, "::tc_stringser::color");
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
        tc_classPrimitives_f_o->type = cx_resolve(NULL, "::tc_stringser::color");
        tc_classPrimitives_f_o->modifiers = 0x0;
        tc_classPrimitives_f_o->state = 0x6;
        tc_classPrimitives_f_o->weak = FALSE;
        tc_classPrimitives_f_o->id = 5;
        if (cx_define(tc_classPrimitives_f_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::classPrimitives::f'.");
            goto error;
        }
    }

    /* Declare ::tc_stringser::listOfColor */
    tc_listOfColor_o = cx_declareChild(tc_o, "listOfColor", cx_list_o);
    if (!tc_listOfColor_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::listOfColor'.");
        goto error;
    }

    /* Define ::tc_stringser::listOfColor */
    if (!cx_checkState(tc_listOfColor_o, CX_DEFINED)) {
        cx_collection(tc_listOfColor_o)->elementType = cx_resolve(NULL, "::tc_stringser::color");
        cx_collection(tc_listOfColor_o)->max = 3;
        if (cx_define(tc_listOfColor_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::listOfColor'.");
            goto error;
        }
    }

    if (cx_type(tc_listOfColor_o)->size != sizeof(tc_listOfColor)) {
        cx_error("tc_stringser_load: calculated size '%d' of type '::tc_stringser::listOfColor' doesn't match C-type size '%d'", cx_type(tc_listOfColor_o)->size, sizeof(tc_listOfColor));
    }

    /* Declare ::tc_stringser::sequenceOfColor */
    tc_sequenceOfColor_o = cx_declareChild(tc_o, "sequenceOfColor", cx_sequence_o);
    if (!tc_sequenceOfColor_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::sequenceOfColor'.");
        goto error;
    }

    /* Define ::tc_stringser::sequenceOfColor */
    if (!cx_checkState(tc_sequenceOfColor_o, CX_DEFINED)) {
        cx_collection(tc_sequenceOfColor_o)->elementType = cx_resolve(NULL, "::tc_stringser::color");
        cx_collection(tc_sequenceOfColor_o)->max = 3;
        if (cx_define(tc_sequenceOfColor_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::sequenceOfColor'.");
            goto error;
        }
    }

    if (cx_type(tc_sequenceOfColor_o)->size != sizeof(tc_sequenceOfColor)) {
        cx_error("tc_stringser_load: calculated size '%d' of type '::tc_stringser::sequenceOfColor' doesn't match C-type size '%d'", cx_type(tc_sequenceOfColor_o)->size, sizeof(tc_sequenceOfColor));
    }

    /* Declare ::tc_stringser::listOfBool */
    tc_listOfBool_o = cx_declareChild(tc_o, "listOfBool", cx_list_o);
    if (!tc_listOfBool_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::listOfBool'.");
        goto error;
    }

    /* Define ::tc_stringser::listOfBool */
    if (!cx_checkState(tc_listOfBool_o, CX_DEFINED)) {
        cx_collection(tc_listOfBool_o)->elementType = cx_resolve(NULL, "::corto::lang::bool");
        cx_collection(tc_listOfBool_o)->max = 3;
        if (cx_define(tc_listOfBool_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::listOfBool'.");
            goto error;
        }
    }

    if (cx_type(tc_listOfBool_o)->size != sizeof(tc_listOfBool)) {
        cx_error("tc_stringser_load: calculated size '%d' of type '::tc_stringser::listOfBool' doesn't match C-type size '%d'", cx_type(tc_listOfBool_o)->size, sizeof(tc_listOfBool));
    }

    /* Declare ::tc_stringser::listOfChar */
    tc_listOfChar_o = cx_declareChild(tc_o, "listOfChar", cx_list_o);
    if (!tc_listOfChar_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::listOfChar'.");
        goto error;
    }

    /* Define ::tc_stringser::listOfChar */
    if (!cx_checkState(tc_listOfChar_o, CX_DEFINED)) {
        cx_collection(tc_listOfChar_o)->elementType = cx_resolve(NULL, "::corto::lang::char");
        cx_collection(tc_listOfChar_o)->max = 3;
        if (cx_define(tc_listOfChar_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::listOfChar'.");
            goto error;
        }
    }

    if (cx_type(tc_listOfChar_o)->size != sizeof(tc_listOfChar)) {
        cx_error("tc_stringser_load: calculated size '%d' of type '::tc_stringser::listOfChar' doesn't match C-type size '%d'", cx_type(tc_listOfChar_o)->size, sizeof(tc_listOfChar));
    }

    /* Declare ::tc_stringser::listOfFloat */
    tc_listOfFloat_o = cx_declareChild(tc_o, "listOfFloat", cx_list_o);
    if (!tc_listOfFloat_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::listOfFloat'.");
        goto error;
    }

    /* Define ::tc_stringser::listOfFloat */
    if (!cx_checkState(tc_listOfFloat_o, CX_DEFINED)) {
        cx_collection(tc_listOfFloat_o)->elementType = cx_resolve(NULL, "::corto::lang::float32");
        cx_collection(tc_listOfFloat_o)->max = 3;
        if (cx_define(tc_listOfFloat_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::listOfFloat'.");
            goto error;
        }
    }

    if (cx_type(tc_listOfFloat_o)->size != sizeof(tc_listOfFloat)) {
        cx_error("tc_stringser_load: calculated size '%d' of type '::tc_stringser::listOfFloat' doesn't match C-type size '%d'", cx_type(tc_listOfFloat_o)->size, sizeof(tc_listOfFloat));
    }

    /* Declare ::tc_stringser::listOfInt */
    tc_listOfInt_o = cx_declareChild(tc_o, "listOfInt", cx_list_o);
    if (!tc_listOfInt_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::listOfInt'.");
        goto error;
    }

    /* Define ::tc_stringser::listOfInt */
    if (!cx_checkState(tc_listOfInt_o, CX_DEFINED)) {
        cx_collection(tc_listOfInt_o)->elementType = cx_resolve(NULL, "::corto::lang::int32");
        cx_collection(tc_listOfInt_o)->max = 3;
        if (cx_define(tc_listOfInt_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::listOfInt'.");
            goto error;
        }
    }

    if (cx_type(tc_listOfInt_o)->size != sizeof(tc_listOfInt)) {
        cx_error("tc_stringser_load: calculated size '%d' of type '::tc_stringser::listOfInt' doesn't match C-type size '%d'", cx_type(tc_listOfInt_o)->size, sizeof(tc_listOfInt));
    }

    /* Define ::tc_stringser::classNested::e */
    if (!cx_checkState(tc_classNested_e_o, CX_DEFINED)) {
        tc_classNested_e_o->type = cx_resolve(NULL, "::tc_stringser::listOfInt");
        tc_classNested_e_o->modifiers = 0x0;
        tc_classNested_e_o->state = 0x6;
        tc_classNested_e_o->weak = FALSE;
        tc_classNested_e_o->id = 4;
        if (cx_define(tc_classNested_e_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::classNested::e'.");
            goto error;
        }
    }

    /* Declare ::tc_stringser::listOfMoveMode */
    tc_listOfMoveMode_o = cx_declareChild(tc_o, "listOfMoveMode", cx_list_o);
    if (!tc_listOfMoveMode_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::listOfMoveMode'.");
        goto error;
    }

    /* Declare ::tc_stringser::listOfString */
    tc_listOfString_o = cx_declareChild(tc_o, "listOfString", cx_list_o);
    if (!tc_listOfString_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::listOfString'.");
        goto error;
    }

    /* Define ::tc_stringser::listOfString */
    if (!cx_checkState(tc_listOfString_o, CX_DEFINED)) {
        cx_collection(tc_listOfString_o)->elementType = cx_resolve(NULL, "::corto::lang::string");
        cx_collection(tc_listOfString_o)->max = 3;
        if (cx_define(tc_listOfString_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::listOfString'.");
            goto error;
        }
    }

    if (cx_type(tc_listOfString_o)->size != sizeof(tc_listOfString)) {
        cx_error("tc_stringser_load: calculated size '%d' of type '::tc_stringser::listOfString' doesn't match C-type size '%d'", cx_type(tc_listOfString_o)->size, sizeof(tc_listOfString));
    }

    /* Declare ::tc_stringser::moveMode */
    tc_moveMode_o = cx_declareChild(tc_o, "moveMode", cx_bitmask_o);
    if (!tc_moveMode_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::moveMode'.");
        goto error;
    }

    /* Define ::tc_stringser::listOfMoveMode */
    if (!cx_checkState(tc_listOfMoveMode_o, CX_DEFINED)) {
        cx_collection(tc_listOfMoveMode_o)->elementType = cx_resolve(NULL, "::tc_stringser::moveMode");
        cx_collection(tc_listOfMoveMode_o)->max = 3;
        if (cx_define(tc_listOfMoveMode_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::listOfMoveMode'.");
            goto error;
        }
    }

    if (cx_type(tc_listOfMoveMode_o)->size != sizeof(tc_listOfMoveMode)) {
        cx_error("tc_stringser_load: calculated size '%d' of type '::tc_stringser::listOfMoveMode' doesn't match C-type size '%d'", cx_type(tc_listOfMoveMode_o)->size, sizeof(tc_listOfMoveMode));
    }

    /* Declare ::tc_stringser::moveMode::FLY */
    tc_moveMode_FLY_o = cx_declareChild(tc_moveMode_o, "FLY", cx_constant_o);
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
    tc_moveMode_SWIM_o = cx_declareChild(tc_moveMode_o, "SWIM", cx_constant_o);
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
    tc_moveMode_WALK_o = cx_declareChild(tc_moveMode_o, "WALK", cx_constant_o);
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

    if (cx_type(tc_moveMode_o)->size != sizeof(tc_moveMode)) {
        cx_error("tc_stringser_load: calculated size '%d' of type '::tc_stringser::moveMode' doesn't match C-type size '%d'", cx_type(tc_moveMode_o)->size, sizeof(tc_moveMode));
    }

    /* Define ::tc_stringser::arrayOfMoveMode */
    if (!cx_checkState(tc_arrayOfMoveMode_o, CX_DEFINED)) {
        cx_collection(tc_arrayOfMoveMode_o)->elementType = cx_resolve(NULL, "::tc_stringser::moveMode");
        cx_collection(tc_arrayOfMoveMode_o)->max = 3;
        tc_arrayOfMoveMode_o->elementType = cx_resolve(NULL, "::tc_stringser::moveMode");
        if (cx_define(tc_arrayOfMoveMode_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::arrayOfMoveMode'.");
            goto error;
        }
    }

    if (cx_type(tc_arrayOfMoveMode_o)->size != sizeof(tc_arrayOfMoveMode)) {
        cx_error("tc_stringser_load: calculated size '%d' of type '::tc_stringser::arrayOfMoveMode' doesn't match C-type size '%d'", cx_type(tc_arrayOfMoveMode_o)->size, sizeof(tc_arrayOfMoveMode));
    }

    /* Define ::tc_stringser::classInherit::g */
    if (!cx_checkState(tc_classInherit_g_o, CX_DEFINED)) {
        tc_classInherit_g_o->type = cx_resolve(NULL, "::tc_stringser::moveMode");
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
        tc_classPrimitives_g_o->type = cx_resolve(NULL, "::tc_stringser::moveMode");
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
        cx_type(tc_classPrimitives_o)->parentState = 0x6;
        cx_type(tc_classPrimitives_o)->defaultType = NULL;
        cx_interface(tc_classPrimitives_o)->base = NULL;
        cx_struct(tc_classPrimitives_o)->baseAccess = 0x0;
        tc_classPrimitives_o->implements.length = 0;
        tc_classPrimitives_o->implements.buffer = NULL;
        if (cx_define(tc_classPrimitives_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::classPrimitives'.");
            goto error;
        }
    }

    if (cx_type(tc_classPrimitives_o)->size != sizeof(struct tc_classPrimitives_s)) {
        cx_error("tc_stringser_load: calculated size '%d' of type '::tc_stringser::classPrimitives' doesn't match C-type size '%d'", cx_type(tc_classPrimitives_o)->size, sizeof(struct tc_classPrimitives_s));
    }

    /* Define ::tc_stringser::arrayOfClassPrimitives */
    if (!cx_checkState(tc_arrayOfClassPrimitives_o, CX_DEFINED)) {
        cx_collection(tc_arrayOfClassPrimitives_o)->elementType = cx_resolve(NULL, "::tc_stringser::classPrimitives");
        cx_collection(tc_arrayOfClassPrimitives_o)->max = 3;
        tc_arrayOfClassPrimitives_o->elementType = cx_resolve(NULL, "::tc_stringser::classPrimitives");
        if (cx_define(tc_arrayOfClassPrimitives_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::arrayOfClassPrimitives'.");
            goto error;
        }
    }

    if (cx_type(tc_arrayOfClassPrimitives_o)->size != sizeof(tc_arrayOfClassPrimitives)) {
        cx_error("tc_stringser_load: calculated size '%d' of type '::tc_stringser::arrayOfClassPrimitives' doesn't match C-type size '%d'", cx_type(tc_arrayOfClassPrimitives_o)->size, sizeof(tc_arrayOfClassPrimitives));
    }

    /* Define ::tc_stringser::classInherit */
    if (!cx_checkState(tc_classInherit_o, CX_DEFINED)) {
        cx_type(tc_classInherit_o)->parentType = NULL;
        cx_type(tc_classInherit_o)->parentState = 0x6;
        cx_type(tc_classInherit_o)->defaultType = NULL;
        cx_interface(tc_classInherit_o)->base = cx_resolve(NULL, "::tc_stringser::classPrimitives");
        cx_struct(tc_classInherit_o)->baseAccess = 0x0;
        tc_classInherit_o->implements.length = 0;
        tc_classInherit_o->implements.buffer = NULL;
        if (cx_define(tc_classInherit_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::classInherit'.");
            goto error;
        }
    }

    if (cx_type(tc_classInherit_o)->size != sizeof(struct tc_classInherit_s)) {
        cx_error("tc_stringser_load: calculated size '%d' of type '::tc_stringser::classInherit' doesn't match C-type size '%d'", cx_type(tc_classInherit_o)->size, sizeof(struct tc_classInherit_s));
    }

    /* Define ::tc_stringser::arrayOfClassInherit */
    if (!cx_checkState(tc_arrayOfClassInherit_o, CX_DEFINED)) {
        cx_collection(tc_arrayOfClassInherit_o)->elementType = cx_resolve(NULL, "::tc_stringser::classInherit");
        cx_collection(tc_arrayOfClassInherit_o)->max = 3;
        tc_arrayOfClassInherit_o->elementType = cx_resolve(NULL, "::tc_stringser::classInherit");
        if (cx_define(tc_arrayOfClassInherit_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::arrayOfClassInherit'.");
            goto error;
        }
    }

    if (cx_type(tc_arrayOfClassInherit_o)->size != sizeof(tc_arrayOfClassInherit)) {
        cx_error("tc_stringser_load: calculated size '%d' of type '::tc_stringser::arrayOfClassInherit' doesn't match C-type size '%d'", cx_type(tc_arrayOfClassInherit_o)->size, sizeof(tc_arrayOfClassInherit));
    }

    /* Define ::tc_stringser::classCompositeCollection::a */
    if (!cx_checkState(tc_classCompositeCollection_a_o, CX_DEFINED)) {
        tc_classCompositeCollection_a_o->type = cx_resolve(NULL, "::tc_stringser::arrayOfClassInherit");
        tc_classCompositeCollection_a_o->modifiers = 0x0;
        tc_classCompositeCollection_a_o->state = 0x6;
        tc_classCompositeCollection_a_o->weak = FALSE;
        tc_classCompositeCollection_a_o->id = 0;
        if (cx_define(tc_classCompositeCollection_a_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::classCompositeCollection::a'.");
            goto error;
        }
    }

    /* Define ::tc_stringser::classNested::b */
    if (!cx_checkState(tc_classNested_b_o, CX_DEFINED)) {
        tc_classNested_b_o->type = cx_resolve(NULL, "::tc_stringser::classInherit");
        tc_classNested_b_o->modifiers = 0x0;
        tc_classNested_b_o->state = 0x6;
        tc_classNested_b_o->weak = FALSE;
        tc_classNested_b_o->id = 1;
        if (cx_define(tc_classNested_b_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::classNested::b'.");
            goto error;
        }
    }

    /* Define ::tc_stringser::classNested::a */
    if (!cx_checkState(tc_classNested_a_o, CX_DEFINED)) {
        tc_classNested_a_o->type = cx_resolve(NULL, "::tc_stringser::classPrimitives");
        tc_classNested_a_o->modifiers = 0x0;
        tc_classNested_a_o->state = 0x6;
        tc_classNested_a_o->weak = FALSE;
        tc_classNested_a_o->id = 0;
        if (cx_define(tc_classNested_a_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::classNested::a'.");
            goto error;
        }
    }

    /* Declare ::tc_stringser::sequenceOfMoveMode */
    tc_sequenceOfMoveMode_o = cx_declareChild(tc_o, "sequenceOfMoveMode", cx_sequence_o);
    if (!tc_sequenceOfMoveMode_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::sequenceOfMoveMode'.");
        goto error;
    }

    /* Define ::tc_stringser::sequenceOfMoveMode */
    if (!cx_checkState(tc_sequenceOfMoveMode_o, CX_DEFINED)) {
        cx_collection(tc_sequenceOfMoveMode_o)->elementType = cx_resolve(NULL, "::tc_stringser::moveMode");
        cx_collection(tc_sequenceOfMoveMode_o)->max = 3;
        if (cx_define(tc_sequenceOfMoveMode_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::sequenceOfMoveMode'.");
            goto error;
        }
    }

    if (cx_type(tc_sequenceOfMoveMode_o)->size != sizeof(tc_sequenceOfMoveMode)) {
        cx_error("tc_stringser_load: calculated size '%d' of type '::tc_stringser::sequenceOfMoveMode' doesn't match C-type size '%d'", cx_type(tc_sequenceOfMoveMode_o)->size, sizeof(tc_sequenceOfMoveMode));
    }

    /* Declare ::tc_stringser::sequenceOfBool */
    tc_sequenceOfBool_o = cx_declareChild(tc_o, "sequenceOfBool", cx_sequence_o);
    if (!tc_sequenceOfBool_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::sequenceOfBool'.");
        goto error;
    }

    /* Define ::tc_stringser::sequenceOfBool */
    if (!cx_checkState(tc_sequenceOfBool_o, CX_DEFINED)) {
        cx_collection(tc_sequenceOfBool_o)->elementType = cx_resolve(NULL, "::corto::lang::bool");
        cx_collection(tc_sequenceOfBool_o)->max = 3;
        if (cx_define(tc_sequenceOfBool_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::sequenceOfBool'.");
            goto error;
        }
    }

    if (cx_type(tc_sequenceOfBool_o)->size != sizeof(tc_sequenceOfBool)) {
        cx_error("tc_stringser_load: calculated size '%d' of type '::tc_stringser::sequenceOfBool' doesn't match C-type size '%d'", cx_type(tc_sequenceOfBool_o)->size, sizeof(tc_sequenceOfBool));
    }

    /* Declare ::tc_stringser::sequenceOfChar */
    tc_sequenceOfChar_o = cx_declareChild(tc_o, "sequenceOfChar", cx_sequence_o);
    if (!tc_sequenceOfChar_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::sequenceOfChar'.");
        goto error;
    }

    /* Define ::tc_stringser::sequenceOfChar */
    if (!cx_checkState(tc_sequenceOfChar_o, CX_DEFINED)) {
        cx_collection(tc_sequenceOfChar_o)->elementType = cx_resolve(NULL, "::corto::lang::char");
        cx_collection(tc_sequenceOfChar_o)->max = 3;
        if (cx_define(tc_sequenceOfChar_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::sequenceOfChar'.");
            goto error;
        }
    }

    if (cx_type(tc_sequenceOfChar_o)->size != sizeof(tc_sequenceOfChar)) {
        cx_error("tc_stringser_load: calculated size '%d' of type '::tc_stringser::sequenceOfChar' doesn't match C-type size '%d'", cx_type(tc_sequenceOfChar_o)->size, sizeof(tc_sequenceOfChar));
    }

    /* Declare ::tc_stringser::sequenceOfFloat */
    tc_sequenceOfFloat_o = cx_declareChild(tc_o, "sequenceOfFloat", cx_sequence_o);
    if (!tc_sequenceOfFloat_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::sequenceOfFloat'.");
        goto error;
    }

    /* Define ::tc_stringser::sequenceOfFloat */
    if (!cx_checkState(tc_sequenceOfFloat_o, CX_DEFINED)) {
        cx_collection(tc_sequenceOfFloat_o)->elementType = cx_resolve(NULL, "::corto::lang::float32");
        cx_collection(tc_sequenceOfFloat_o)->max = 3;
        if (cx_define(tc_sequenceOfFloat_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::sequenceOfFloat'.");
            goto error;
        }
    }

    if (cx_type(tc_sequenceOfFloat_o)->size != sizeof(tc_sequenceOfFloat)) {
        cx_error("tc_stringser_load: calculated size '%d' of type '::tc_stringser::sequenceOfFloat' doesn't match C-type size '%d'", cx_type(tc_sequenceOfFloat_o)->size, sizeof(tc_sequenceOfFloat));
    }

    /* Declare ::tc_stringser::sequenceOfInt */
    tc_sequenceOfInt_o = cx_declareChild(tc_o, "sequenceOfInt", cx_sequence_o);
    if (!tc_sequenceOfInt_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::sequenceOfInt'.");
        goto error;
    }

    /* Define ::tc_stringser::sequenceOfInt */
    if (!cx_checkState(tc_sequenceOfInt_o, CX_DEFINED)) {
        cx_collection(tc_sequenceOfInt_o)->elementType = cx_resolve(NULL, "::corto::lang::int32");
        cx_collection(tc_sequenceOfInt_o)->max = 3;
        if (cx_define(tc_sequenceOfInt_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::sequenceOfInt'.");
            goto error;
        }
    }

    if (cx_type(tc_sequenceOfInt_o)->size != sizeof(tc_sequenceOfInt)) {
        cx_error("tc_stringser_load: calculated size '%d' of type '::tc_stringser::sequenceOfInt' doesn't match C-type size '%d'", cx_type(tc_sequenceOfInt_o)->size, sizeof(tc_sequenceOfInt));
    }

    /* Define ::tc_stringser::classNested::d */
    if (!cx_checkState(tc_classNested_d_o, CX_DEFINED)) {
        tc_classNested_d_o->type = cx_resolve(NULL, "::tc_stringser::sequenceOfInt");
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
        cx_type(tc_classNested_o)->parentState = 0x6;
        cx_type(tc_classNested_o)->defaultType = NULL;
        cx_interface(tc_classNested_o)->base = NULL;
        cx_struct(tc_classNested_o)->baseAccess = 0x0;
        tc_classNested_o->implements.length = 0;
        tc_classNested_o->implements.buffer = NULL;
        if (cx_define(tc_classNested_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::classNested'.");
            goto error;
        }
    }

    if (cx_type(tc_classNested_o)->size != sizeof(struct tc_classNested_s)) {
        cx_error("tc_stringser_load: calculated size '%d' of type '::tc_stringser::classNested' doesn't match C-type size '%d'", cx_type(tc_classNested_o)->size, sizeof(struct tc_classNested_s));
    }

    /* Define ::tc_stringser::arrayOfClassNested */
    if (!cx_checkState(tc_arrayOfClassNested_o, CX_DEFINED)) {
        cx_collection(tc_arrayOfClassNested_o)->elementType = cx_resolve(NULL, "::tc_stringser::classNested");
        cx_collection(tc_arrayOfClassNested_o)->max = 3;
        tc_arrayOfClassNested_o->elementType = cx_resolve(NULL, "::tc_stringser::classNested");
        if (cx_define(tc_arrayOfClassNested_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::arrayOfClassNested'.");
            goto error;
        }
    }

    if (cx_type(tc_arrayOfClassNested_o)->size != sizeof(tc_arrayOfClassNested)) {
        cx_error("tc_stringser_load: calculated size '%d' of type '::tc_stringser::arrayOfClassNested' doesn't match C-type size '%d'", cx_type(tc_arrayOfClassNested_o)->size, sizeof(tc_arrayOfClassNested));
    }

    /* Define ::tc_stringser::classCompositeCollection::b */
    if (!cx_checkState(tc_classCompositeCollection_b_o, CX_DEFINED)) {
        tc_classCompositeCollection_b_o->type = cx_resolve(NULL, "::tc_stringser::arrayOfClassNested");
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
        cx_type(tc_classCompositeCollection_o)->parentState = 0x6;
        cx_type(tc_classCompositeCollection_o)->defaultType = NULL;
        cx_interface(tc_classCompositeCollection_o)->base = NULL;
        cx_struct(tc_classCompositeCollection_o)->baseAccess = 0x0;
        tc_classCompositeCollection_o->implements.length = 0;
        tc_classCompositeCollection_o->implements.buffer = NULL;
        if (cx_define(tc_classCompositeCollection_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::classCompositeCollection'.");
            goto error;
        }
    }

    if (cx_type(tc_classCompositeCollection_o)->size != sizeof(struct tc_classCompositeCollection_s)) {
        cx_error("tc_stringser_load: calculated size '%d' of type '::tc_stringser::classCompositeCollection' doesn't match C-type size '%d'", cx_type(tc_classCompositeCollection_o)->size, sizeof(struct tc_classCompositeCollection_s));
    }

    /* Declare ::tc_stringser::sequenceOfString */
    tc_sequenceOfString_o = cx_declareChild(tc_o, "sequenceOfString", cx_sequence_o);
    if (!tc_sequenceOfString_o) {
        cx_error("tc_stringser_load: failed to declare object '::tc_stringser::sequenceOfString'.");
        goto error;
    }

    /* Define ::tc_stringser::sequenceOfString */
    if (!cx_checkState(tc_sequenceOfString_o, CX_DEFINED)) {
        cx_collection(tc_sequenceOfString_o)->elementType = cx_resolve(NULL, "::corto::lang::string");
        cx_collection(tc_sequenceOfString_o)->max = 3;
        if (cx_define(tc_sequenceOfString_o)) {
            cx_error("tc_stringser_load: failed to define object '::tc_stringser::sequenceOfString'.");
            goto error;
        }
    }

    if (cx_type(tc_sequenceOfString_o)->size != sizeof(tc_sequenceOfString)) {
        cx_error("tc_stringser_load: calculated size '%d' of type '::tc_stringser::sequenceOfString' doesn't match C-type size '%d'", cx_type(tc_sequenceOfString_o)->size, sizeof(tc_sequenceOfString));
    }

    if (_a_) {
        cx_release(_a_);
    }

    return 0;
error:
    return -1;
}
