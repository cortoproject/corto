/* primitive_Bool.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "primitive.h"

/* ::primitive::Bool::testCompare() */
cx_void _primitive_Bool_testCompare(primitive_Bool this) {
/* $begin(::primitive::Bool::testCompare) */

    /* << Insert implementation >> */

/* $end */
}

/* ::primitive::Bool::testCopy() */
cx_void _primitive_Bool_testCopy(primitive_Bool this) {
/* $begin(::primitive::Bool::testCopy) */

    /* << Insert implementation >> */

/* $end */
}

/* ::primitive::Bool::testCreate() */
cx_void _primitive_Bool_testCreate(primitive_Bool this) {
/* $begin(::primitive::Bool::testCreate) */

    cx_bool *o = cx_boolCreate(TRUE);
    test_assert(o != NULL);
    test_assert(cx_typeof(o) == cx_type(cx_bool_o));
    test_assert(*o == TRUE);
    cx_delete(o);

/* $end */
}

/* ::primitive::Bool::testCreateChild() */
cx_void _primitive_Bool_testCreateChild(primitive_Bool this) {
/* $begin(::primitive::Bool::testCreateChild) */

    /* << Insert implementation >> */

/* $end */
}

/* ::primitive::Bool::testDeclare() */
cx_void _primitive_Bool_testDeclare(primitive_Bool this) {
/* $begin(::primitive::Bool::testDeclare) */

    /* << Insert implementation >> */

/* $end */
}

/* ::primitive::Bool::testDeclareChild() */
cx_void _primitive_Bool_testDeclareChild(primitive_Bool this) {
/* $begin(::primitive::Bool::testDeclareChild) */

    /* << Insert implementation >> */

/* $end */
}

/* ::primitive::Bool::testDefine() */
cx_void _primitive_Bool_testDefine(primitive_Bool this) {
/* $begin(::primitive::Bool::testDefine) */

    /* << Insert implementation >> */

/* $end */
}

/* ::primitive::Bool::testDeinit() */
cx_void _primitive_Bool_testDeinit(primitive_Bool this) {
/* $begin(::primitive::Bool::testDeinit) */

    /* << Insert implementation >> */

/* $end */
}

/* ::primitive::Bool::testFalse() */
cx_void _primitive_Bool_testFalse(primitive_Bool this) {
/* $begin(::primitive::Bool::testFalse) */

    /* << Insert implementation >> */

/* $end */
}

/* ::primitive::Bool::testFromstr() */
cx_void _primitive_Bool_testFromstr(primitive_Bool this) {
/* $begin(::primitive::Bool::testFromstr) */

    /* << Insert implementation >> */

/* $end */
}

/* ::primitive::Bool::testInit() */
cx_void _primitive_Bool_testInit(primitive_Bool this) {
/* $begin(::primitive::Bool::testInit) */

    /* << Insert implementation >> */

/* $end */
}

/* ::primitive::Bool::testStr() */
cx_void _primitive_Bool_testStr(primitive_Bool this) {
/* $begin(::primitive::Bool::testStr) */

    /* << Insert implementation >> */

/* $end */
}

/* ::primitive::Bool::testTrue() */
cx_void _primitive_Bool_testTrue(primitive_Bool this) {
/* $begin(::primitive::Bool::testTrue) */

    /* << Insert implementation >> */

/* $end */
}

/* ::primitive::Bool::testUpdate() */
cx_void _primitive_Bool_testUpdate(primitive_Bool this) {
/* $begin(::primitive::Bool::testUpdate) */

    /* << Insert implementation >> */

/* $end */
}
