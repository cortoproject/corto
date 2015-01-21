/* tc_iterator__meta.c
 *
 * Loads objects in database.
 * This file contains generated code. Do not modify!
 */

#include "tc_iterator__type.h"

/* Variable definitions */
cx_object tc_iterator_o;
tc_iterator_intArray (*tc_iterator_array1_o);
cx_array tc_iterator_intArray_o;
cx_iterator tc_iterator_intIterator_o;
cx_list tc_iterator_intList_o;
tc_iterator_intList (*tc_iterator_list1_o);
cx_function tc_iterator_testArray_o;
cx_function tc_iterator_testList_o;

/* Load objects in database */
int tc_iterator_load(void) {
    cx_object _a_; /* Used for resolving anonymous objects */
    _a_ = NULL;

    /* Declare ::tc_iterator */
    tc_iterator_o = cx_declare(root_o, "tc_iterator", cx_typedef(cx_object_o));
    if (!tc_iterator_o) {
        cx_error("tc_iterator_load: failed to declare object '::tc_iterator'.");
        goto error;
    }

    /* Define ::tc_iterator */
    if (!cx_checkState(tc_iterator_o, CX_DEFINED)) {
        if (cx_define(tc_iterator_o)) {
            cx_error("tc_iterator_load: failed to define object '::tc_iterator'.");
            goto error;
        }
    }

    /* Declare ::tc_iterator::intArray */
    tc_iterator_intArray_o = cx_declare(tc_iterator_o, "intArray", cx_typedef(cx_array_o));
    if (!tc_iterator_intArray_o) {
        cx_error("tc_iterator_load: failed to declare object '::tc_iterator::intArray'.");
        goto error;
    }

    /* Define ::tc_iterator::intArray */
    if (!cx_checkState(tc_iterator_intArray_o, CX_DEFINED)) {
        cx_collection(tc_iterator_intArray_o)->elementType = cx_resolve_ext(tc_iterator_intArray_o, NULL, "::cortex::lang::int32", FALSE, "element ::tc_iterator::intArray.elementType");
        cx_collection(tc_iterator_intArray_o)->max = 3;
        tc_iterator_intArray_o->elementType = cx_resolve_ext(tc_iterator_intArray_o, NULL, "::cortex::lang::int32", FALSE, "element ::tc_iterator::intArray.elementType");
        if (cx_define(tc_iterator_intArray_o)) {
            cx_error("tc_iterator_load: failed to define object '::tc_iterator::intArray'.");
            goto error;
        }
    }

    if (cx_type(tc_iterator_intArray_o)->size != sizeof(tc_iterator_intArray)) {
        cx_error("tc_iterator_load: calculated size '%d' of type '::tc_iterator::intArray' doesn't match C-type size '%d'", cx_type(tc_iterator_intArray_o)->size, sizeof(tc_iterator_intArray));
    }

    /* Declare ::tc_iterator::array1 */
    tc_iterator_array1_o = cx_declare(tc_iterator_o, "array1", cx_typedef(tc_iterator_intArray_o));
    if (!tc_iterator_array1_o) {
        cx_error("tc_iterator_load: failed to declare object '::tc_iterator::array1'.");
        goto error;
    }

    /* Define ::tc_iterator::array1 */
    if (!cx_checkState(tc_iterator_array1_o, CX_DEFINED)) {
        (*tc_iterator_array1_o)[0] = 1;
        (*tc_iterator_array1_o)[1] = 2;
        (*tc_iterator_array1_o)[2] = 3;
        if (cx_define(tc_iterator_array1_o)) {
            cx_error("tc_iterator_load: failed to define object '::tc_iterator::array1'.");
            goto error;
        }
    }

    /* Declare ::tc_iterator::intIterator */
    tc_iterator_intIterator_o = cx_declare(tc_iterator_o, "intIterator", cx_typedef(cx_iterator_o));
    if (!tc_iterator_intIterator_o) {
        cx_error("tc_iterator_load: failed to declare object '::tc_iterator::intIterator'.");
        goto error;
    }

    /* Define ::tc_iterator::intIterator */
    if (!cx_checkState(tc_iterator_intIterator_o, CX_DEFINED)) {
        tc_iterator_intIterator_o->elementType = cx_resolve_ext(tc_iterator_intIterator_o, NULL, "::cortex::lang::int32", FALSE, "element ::tc_iterator::intIterator.elementType");
        if (cx_define(tc_iterator_intIterator_o)) {
            cx_error("tc_iterator_load: failed to define object '::tc_iterator::intIterator'.");
            goto error;
        }
    }

    if (cx_type(tc_iterator_intIterator_o)->size != sizeof(tc_iterator_intIterator)) {
        cx_error("tc_iterator_load: calculated size '%d' of type '::tc_iterator::intIterator' doesn't match C-type size '%d'", cx_type(tc_iterator_intIterator_o)->size, sizeof(tc_iterator_intIterator));
    }

    /* Declare ::tc_iterator::intList */
    tc_iterator_intList_o = cx_declare(tc_iterator_o, "intList", cx_typedef(cx_list_o));
    if (!tc_iterator_intList_o) {
        cx_error("tc_iterator_load: failed to declare object '::tc_iterator::intList'.");
        goto error;
    }

    /* Define ::tc_iterator::intList */
    if (!cx_checkState(tc_iterator_intList_o, CX_DEFINED)) {
        cx_collection(tc_iterator_intList_o)->elementType = cx_resolve_ext(tc_iterator_intList_o, NULL, "::cortex::lang::int32", FALSE, "element ::tc_iterator::intList.elementType");
        cx_collection(tc_iterator_intList_o)->max = 0;
        if (cx_define(tc_iterator_intList_o)) {
            cx_error("tc_iterator_load: failed to define object '::tc_iterator::intList'.");
            goto error;
        }
    }

    if (cx_type(tc_iterator_intList_o)->size != sizeof(tc_iterator_intList)) {
        cx_error("tc_iterator_load: calculated size '%d' of type '::tc_iterator::intList' doesn't match C-type size '%d'", cx_type(tc_iterator_intList_o)->size, sizeof(tc_iterator_intList));
    }

    /* Declare ::tc_iterator::list1 */
    tc_iterator_list1_o = cx_declare(tc_iterator_o, "list1", cx_typedef(tc_iterator_intList_o));
    if (!tc_iterator_list1_o) {
        cx_error("tc_iterator_load: failed to declare object '::tc_iterator::list1'.");
        goto error;
    }

    /* Define ::tc_iterator::list1 */
    if (!cx_checkState(tc_iterator_list1_o, CX_DEFINED)) {
        (*tc_iterator_list1_o) = cx_llNew();
        {
            cx_int32 _e1_;
            
            _e1_ = 1;
            cx_llAppend((*tc_iterator_list1_o), _e1_);
            
            _e1_ = 2;
            cx_llAppend((*tc_iterator_list1_o), _e1_);
            
            _e1_ = 3;
            cx_llAppend((*tc_iterator_list1_o), _e1_);
        }
        if (cx_define(tc_iterator_list1_o)) {
            cx_error("tc_iterator_load: failed to define object '::tc_iterator::list1'.");
            goto error;
        }
    }

    /* Declare ::tc_iterator::testArray() */
    tc_iterator_testArray_o = cx_declare(tc_iterator_o, "testArray()", cx_typedef(cx_function_o));
    if (!tc_iterator_testArray_o) {
        cx_error("tc_iterator_load: failed to declare object '::tc_iterator::testArray()'.");
        goto error;
    }

    /* Define ::tc_iterator::testArray() */
    if (!cx_checkState(tc_iterator_testArray_o, CX_DEFINED)) {
        tc_iterator_testArray_o->returnType = cx_resolve_ext(tc_iterator_testArray_o, NULL, "::cortex::lang::bool", FALSE, "element ::tc_iterator::testArray().returnType");
        tc_iterator_testArray_o->returnsReference = FALSE;
        
        /* Bind ::tc_iterator::testArray() with C-function */
        cx_function(tc_iterator_testArray_o)->kind = CX_PROCEDURE_CDECL;
        void __tc_iterator_testArray(void *args, void *result);
        cx_function(tc_iterator_testArray_o)->impl = (cx_word)__tc_iterator_testArray;
        if (cx_define(tc_iterator_testArray_o)) {
            cx_error("tc_iterator_load: failed to define object '::tc_iterator::testArray()'.");
            goto error;
        }
    }

    /* Declare ::tc_iterator::testList() */
    tc_iterator_testList_o = cx_declare(tc_iterator_o, "testList()", cx_typedef(cx_function_o));
    if (!tc_iterator_testList_o) {
        cx_error("tc_iterator_load: failed to declare object '::tc_iterator::testList()'.");
        goto error;
    }

    /* Define ::tc_iterator::testList() */
    if (!cx_checkState(tc_iterator_testList_o, CX_DEFINED)) {
        tc_iterator_testList_o->returnType = cx_resolve_ext(tc_iterator_testList_o, NULL, "::cortex::lang::bool", FALSE, "element ::tc_iterator::testList().returnType");
        tc_iterator_testList_o->returnsReference = FALSE;
        
        /* Bind ::tc_iterator::testList() with C-function */
        cx_function(tc_iterator_testList_o)->kind = CX_PROCEDURE_CDECL;
        void __tc_iterator_testList(void *args, void *result);
        cx_function(tc_iterator_testList_o)->impl = (cx_word)__tc_iterator_testList;
        if (cx_define(tc_iterator_testList_o)) {
            cx_error("tc_iterator_load: failed to define object '::tc_iterator::testList()'.");
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
