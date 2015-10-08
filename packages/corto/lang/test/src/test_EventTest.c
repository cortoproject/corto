/* test_EventTest.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "test.h"

/* ::test::EventTest::construct() */
cx_int16 _test_EventTest_construct(test_EventTest this) {
/* $begin(::test::EventTest::construct) */
    cx_any thisAny = {cx_typeof(this), this, FALSE};

    cx_class_setObservable(thisAny, test_EventTest_onDeclare_o, this->scope);
    cx_class_setObservable(thisAny, test_EventTest_onDeclareSelf_o, this->scope);
    cx_class_setObservable(thisAny, test_EventTest_onDeclareScope_o, this->scope);
    cx_class_setObservable(thisAny, test_EventTest_onDeclareTree_o, this->scope);

    cx_class_setObservable(thisAny, test_EventTest_onDefine_o, this->scope);
    cx_class_setObservable(thisAny, test_EventTest_onDefineSelf_o, this->scope);
    cx_class_setObservable(thisAny, test_EventTest_onDefineScope_o, this->scope);
    cx_class_setObservable(thisAny, test_EventTest_onDefineTree_o, this->scope); 

    cx_class_setObservable(thisAny, test_EventTest_onUpdate_o, this->scope);
    cx_class_setObservable(thisAny, test_EventTest_onUpdateSelf_o, this->scope);
    cx_class_setObservable(thisAny, test_EventTest_onUpdateScope_o, this->scope);
    cx_class_setObservable(thisAny, test_EventTest_onUpdateTree_o, this->scope);   

    cx_class_setObservable(thisAny, test_EventTest_onDelete_o, this->scope);
    cx_class_setObservable(thisAny, test_EventTest_onDeleteSelf_o, this->scope);
    cx_class_setObservable(thisAny, test_EventTest_onDeleteScope_o, this->scope);
    cx_class_setObservable(thisAny, test_EventTest_onDeleteTree_o, this->scope);

    return 0;
/* $end */
}

/* ::test::EventTest::onDeclare */
cx_void _test_EventTest_onDeclare(test_EventTest this, cx_object observable) {
/* $begin(::test::EventTest::onDeclare) */
   cx_setref(&this->lastThis, this);
   cx_setref(&this->lastObservable, observable);
   this->countDeclare++;
/* $end */
}

/* ::test::EventTest::onDeclareScope */
cx_void _test_EventTest_onDeclareScope(test_EventTest this, cx_object observable) {
/* $begin(::test::EventTest::onDeclareScope) */
   cx_setref(&this->lastThis, this);
   cx_setref(&this->lastObservable, observable);
   this->countDeclareScope++;
/* $end */
}

/* ::test::EventTest::onDeclareSelf */
cx_void _test_EventTest_onDeclareSelf(test_EventTest this, cx_object observable) {
/* $begin(::test::EventTest::onDeclareSelf) */
   cx_setref(&this->lastThis, this);
   cx_setref(&this->lastObservable, observable);
   this->countDeclareSelf++;
/* $end */
}

/* ::test::EventTest::onDeclareTree */
cx_void _test_EventTest_onDeclareTree(test_EventTest this, cx_object observable) {
/* $begin(::test::EventTest::onDeclareTree) */
   cx_setref(&this->lastThis, this);
   cx_setref(&this->lastObservable, observable);
   this->countDeclareTree++;
/* $end */
}

/* ::test::EventTest::onDefine */
cx_void _test_EventTest_onDefine(test_EventTest this, cx_object observable) {
/* $begin(::test::EventTest::onDefine) */
   cx_setref(&this->lastThis, this);
   cx_setref(&this->lastObservable, observable);
   this->countDefine++;
/* $end */
}

/* ::test::EventTest::onDefineScope */
cx_void _test_EventTest_onDefineScope(test_EventTest this, cx_object observable) {
/* $begin(::test::EventTest::onDefineScope) */
   cx_setref(&this->lastThis, this);
   cx_setref(&this->lastObservable, observable);
   this->countDefineScope++;
/* $end */
}

/* ::test::EventTest::onDefineSelf */
cx_void _test_EventTest_onDefineSelf(test_EventTest this, cx_object observable) {
/* $begin(::test::EventTest::onDefineSelf) */
   cx_setref(&this->lastThis, this);
   cx_setref(&this->lastObservable, observable);
   this->countDefineSelf++;
/* $end */
}

/* ::test::EventTest::onDefineTree */
cx_void _test_EventTest_onDefineTree(test_EventTest this, cx_object observable) {
/* $begin(::test::EventTest::onDefineTree) */
   cx_setref(&this->lastThis, this);
   cx_setref(&this->lastObservable, observable);
   this->countDefineTree++;
/* $end */
}

/* ::test::EventTest::onDelete */
cx_void _test_EventTest_onDelete(test_EventTest this, cx_object observable) {
/* $begin(::test::EventTest::onDelete) */
   cx_setref(&this->lastThis, this);
   cx_setref(&this->lastObservable, observable);
   this->countDelete++;
/* $end */
}

/* ::test::EventTest::onDeleteScope */
cx_void _test_EventTest_onDeleteScope(test_EventTest this, cx_object observable) {
/* $begin(::test::EventTest::onDeleteScope) */
   cx_setref(&this->lastThis, this);
   cx_setref(&this->lastObservable, observable);
   this->countDeleteScope++;
/* $end */
}

/* ::test::EventTest::onDeleteSelf */
cx_void _test_EventTest_onDeleteSelf(test_EventTest this, cx_object observable) {
/* $begin(::test::EventTest::onDeleteSelf) */
   cx_setref(&this->lastThis, this);
   cx_setref(&this->lastObservable, observable);
   this->countDeleteSelf++;
/* $end */
}

/* ::test::EventTest::onDeleteTree */
cx_void _test_EventTest_onDeleteTree(test_EventTest this, cx_object observable) {
/* $begin(::test::EventTest::onDeleteTree) */
   cx_setref(&this->lastThis, this);
   cx_setref(&this->lastObservable, observable);
   this->countDeleteTree++;
/* $end */
}

/* ::test::EventTest::onUpdate */
cx_void _test_EventTest_onUpdate(test_EventTest this, cx_object observable) {
/* $begin(::test::EventTest::onUpdate) */
   cx_setref(&this->lastThis, this);
   cx_setref(&this->lastObservable, observable);
   this->countUpdate++;
/* $end */
}

/* ::test::EventTest::onUpdateScope */
cx_void _test_EventTest_onUpdateScope(test_EventTest this, cx_object observable) {
/* $begin(::test::EventTest::onUpdateScope) */
   cx_setref(&this->lastThis, this);
   cx_setref(&this->lastObservable, observable);
   this->countUpdateScope++;
/* $end */
}

/* ::test::EventTest::onUpdateSelf */
cx_void _test_EventTest_onUpdateSelf(test_EventTest this, cx_object observable) {
/* $begin(::test::EventTest::onUpdateSelf) */
   cx_setref(&this->lastThis, this);
   cx_setref(&this->lastObservable, observable);
   this->countUpdateSelf++;
/* $end */
}

/* ::test::EventTest::onUpdateTree */
cx_void _test_EventTest_onUpdateTree(test_EventTest this, cx_object observable) {
/* $begin(::test::EventTest::onUpdateTree) */
   cx_setref(&this->lastThis, this);
   cx_setref(&this->lastObservable, observable);
   this->countUpdateTree++;
/* $end */
}
