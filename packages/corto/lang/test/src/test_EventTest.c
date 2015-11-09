/* $CORTO_GENERATED
 *
 * test_EventTest.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include "test.h"

corto_int16 _test_EventTest_construct(test_EventTest this) {
/* $begin(/test/EventTest/construct) */
    corto_any thisAny = {corto_typeof(this), this, FALSE};

    corto_class_setObservable(thisAny, test_EventTest_onDeclare_o, this->scope);
    corto_class_setObservable(thisAny, test_EventTest_onDeclareSelf_o, this->scope);
    corto_class_setObservable(thisAny, test_EventTest_onDeclareScope_o, this->scope);
    corto_class_setObservable(thisAny, test_EventTest_onDeclareTree_o, this->scope);

    corto_class_setObservable(thisAny, test_EventTest_onDefine_o, this->scope);
    corto_class_setObservable(thisAny, test_EventTest_onDefineSelf_o, this->scope);
    corto_class_setObservable(thisAny, test_EventTest_onDefineScope_o, this->scope);
    corto_class_setObservable(thisAny, test_EventTest_onDefineTree_o, this->scope); 

    corto_class_setObservable(thisAny, test_EventTest_onUpdate_o, this->scope);
    corto_class_setObservable(thisAny, test_EventTest_onUpdateSelf_o, this->scope);
    corto_class_setObservable(thisAny, test_EventTest_onUpdateScope_o, this->scope);
    corto_class_setObservable(thisAny, test_EventTest_onUpdateTree_o, this->scope);   

    corto_class_setObservable(thisAny, test_EventTest_onDelete_o, this->scope);
    corto_class_setObservable(thisAny, test_EventTest_onDeleteSelf_o, this->scope);
    corto_class_setObservable(thisAny, test_EventTest_onDeleteScope_o, this->scope);
    corto_class_setObservable(thisAny, test_EventTest_onDeleteTree_o, this->scope);

    return 0;
/* $end */
}

corto_void _test_EventTest_onDeclare(test_EventTest this, corto_object observable) {
/* $begin(/test/EventTest/onDeclare) */
   corto_setref(&this->lastThis, this);
   corto_setref(&this->lastObservable, observable);
   this->countDeclare++;
/* $end */
}

corto_void _test_EventTest_onDeclareScope(test_EventTest this, corto_object observable) {
/* $begin(/test/EventTest/onDeclareScope) */
   corto_setref(&this->lastThis, this);
   corto_setref(&this->lastObservable, observable);
   this->countDeclareScope++;
/* $end */
}

corto_void _test_EventTest_onDeclareSelf(test_EventTest this, corto_object observable) {
/* $begin(/test/EventTest/onDeclareSelf) */
   corto_setref(&this->lastThis, this);
   corto_setref(&this->lastObservable, observable);
   this->countDeclareSelf++;
/* $end */
}

corto_void _test_EventTest_onDeclareTree(test_EventTest this, corto_object observable) {
/* $begin(/test/EventTest/onDeclareTree) */
   corto_setref(&this->lastThis, this);
   corto_setref(&this->lastObservable, observable);
   this->countDeclareTree++;
/* $end */
}

corto_void _test_EventTest_onDefine(test_EventTest this, corto_object observable) {
/* $begin(/test/EventTest/onDefine) */
   corto_setref(&this->lastThis, this);
   corto_setref(&this->lastObservable, observable);
   this->countDefine++;
/* $end */
}

corto_void _test_EventTest_onDefineScope(test_EventTest this, corto_object observable) {
/* $begin(/test/EventTest/onDefineScope) */
   corto_setref(&this->lastThis, this);
   corto_setref(&this->lastObservable, observable);
   this->countDefineScope++;
/* $end */
}

corto_void _test_EventTest_onDefineSelf(test_EventTest this, corto_object observable) {
/* $begin(/test/EventTest/onDefineSelf) */
   corto_setref(&this->lastThis, this);
   corto_setref(&this->lastObservable, observable);
   this->countDefineSelf++;
/* $end */
}

corto_void _test_EventTest_onDefineTree(test_EventTest this, corto_object observable) {
/* $begin(/test/EventTest/onDefineTree) */
   corto_setref(&this->lastThis, this);
   corto_setref(&this->lastObservable, observable);
   this->countDefineTree++;
/* $end */
}

corto_void _test_EventTest_onDelete(test_EventTest this, corto_object observable) {
/* $begin(/test/EventTest/onDelete) */
   corto_setref(&this->lastThis, this);
   corto_setref(&this->lastObservable, observable);
   this->countDelete++;
/* $end */
}

corto_void _test_EventTest_onDeleteScope(test_EventTest this, corto_object observable) {
/* $begin(/test/EventTest/onDeleteScope) */
   corto_setref(&this->lastThis, this);
   corto_setref(&this->lastObservable, observable);
   this->countDeleteScope++;
/* $end */
}

corto_void _test_EventTest_onDeleteSelf(test_EventTest this, corto_object observable) {
/* $begin(/test/EventTest/onDeleteSelf) */
   corto_setref(&this->lastThis, this);
   corto_setref(&this->lastObservable, observable);
   this->countDeleteSelf++;
/* $end */
}

corto_void _test_EventTest_onDeleteTree(test_EventTest this, corto_object observable) {
/* $begin(/test/EventTest/onDeleteTree) */
   corto_setref(&this->lastThis, this);
   corto_setref(&this->lastObservable, observable);
   this->countDeleteTree++;
/* $end */
}

corto_void _test_EventTest_onUpdate(test_EventTest this, corto_object observable) {
/* $begin(/test/EventTest/onUpdate) */
   corto_setref(&this->lastThis, this);
   corto_setref(&this->lastObservable, observable);
   this->countUpdate++;
/* $end */
}

corto_void _test_EventTest_onUpdateScope(test_EventTest this, corto_object observable) {
/* $begin(/test/EventTest/onUpdateScope) */
   corto_setref(&this->lastThis, this);
   corto_setref(&this->lastObservable, observable);
   this->countUpdateScope++;
/* $end */
}

corto_void _test_EventTest_onUpdateSelf(test_EventTest this, corto_object observable) {
/* $begin(/test/EventTest/onUpdateSelf) */
   corto_setref(&this->lastThis, this);
   corto_setref(&this->lastObservable, observable);
   this->countUpdateSelf++;
/* $end */
}

corto_void _test_EventTest_onUpdateTree(test_EventTest this, corto_object observable) {
/* $begin(/test/EventTest/onUpdateTree) */
   corto_setref(&this->lastThis, this);
   corto_setref(&this->lastObservable, observable);
   this->countUpdateTree++;
/* $end */
}
