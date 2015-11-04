/* $CORTO_GENERATED
 *
 * primitive_Bool.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include "primitive.h"

corto_void _primitive_Bool_testCompare(primitive_Bool this) {
/* $begin(::primitive::Bool::testCompare) */

    /* << Insert implementation >> */

/* $end */
}

corto_void _primitive_Bool_testCopy(primitive_Bool this) {
/* $begin(::primitive::Bool::testCopy) */

    /* << Insert implementation >> */

/* $end */
}

corto_void _primitive_Bool_testCreate(primitive_Bool this) {
/* $begin(::primitive::Bool::testCreate) */

    corto_bool *o = corto_boolCreate(TRUE);
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_bool_o));
    test_assert(*o == TRUE);
    corto_delete(o);

/* $end */
}

corto_void _primitive_Bool_testCreateChild(primitive_Bool this) {
/* $begin(::primitive::Bool::testCreateChild) */

    /* << Insert implementation >> */

/* $end */
}

corto_void _primitive_Bool_testDeclare(primitive_Bool this) {
/* $begin(::primitive::Bool::testDeclare) */

    /* << Insert implementation >> */

/* $end */
}

corto_void _primitive_Bool_testDeclareChild(primitive_Bool this) {
/* $begin(::primitive::Bool::testDeclareChild) */

    /* << Insert implementation >> */

/* $end */
}

corto_void _primitive_Bool_testDefine(primitive_Bool this) {
/* $begin(::primitive::Bool::testDefine) */

    /* << Insert implementation >> */

/* $end */
}

corto_void _primitive_Bool_testDeinit(primitive_Bool this) {
/* $begin(::primitive::Bool::testDeinit) */

    /* << Insert implementation >> */

/* $end */
}

corto_void _primitive_Bool_testFalse(primitive_Bool this) {
/* $begin(::primitive::Bool::testFalse) */

    /* << Insert implementation >> */

/* $end */
}

corto_void _primitive_Bool_testFromstr(primitive_Bool this) {
/* $begin(::primitive::Bool::testFromstr) */

    /* << Insert implementation >> */

/* $end */
}

corto_void _primitive_Bool_testInit(primitive_Bool this) {
/* $begin(::primitive::Bool::testInit) */

    /* << Insert implementation >> */

/* $end */
}

corto_void _primitive_Bool_testStr(primitive_Bool this) {
/* $begin(::primitive::Bool::testStr) */

    /* << Insert implementation >> */

/* $end */
}

corto_void _primitive_Bool_testTrue(primitive_Bool this) {
/* $begin(::primitive::Bool::testTrue) */

    /* << Insert implementation >> */

/* $end */
}

corto_void _primitive_Bool_testUpdate(primitive_Bool this) {
/* $begin(::primitive::Bool::testUpdate) */

    /* << Insert implementation >> */

/* $end */
}
