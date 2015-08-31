/* tc_stringser__api.h
 *
 *    API convenience functions for C-language.
 *    This file contains generated code. Do not modify!
 */

#ifndef tc_stringser__API_H
#define tc_stringser__API_H

#include "tc_stringser__type.h"
#include "corto.h"

#ifdef __cplusplus
extern "C" {
#endif
/* ::tc_stringser::classCompositeCollection */
tc_stringser_classCompositeCollection tc_stringser_classCompositeCollection__new(void);
tc_stringser_classCompositeCollection tc_stringser_classCompositeCollectionDeclare(cx_object _parent, cx_string _name);
int tc_stringser_classCompositeCollectionDefine(tc_stringser_classCompositeCollection _this, tc_stringser_arrayOfClassInherit a, tc_stringser_arrayOfClassNested b, tc_stringser_sequenceOfClassInherit c, tc_stringser_listOfClassNested d, tc_stringser_listOfClassInherit e);
tc_stringser_classCompositeCollection tc_stringser_classCompositeCollectionCreate(tc_stringser_arrayOfClassInherit a, tc_stringser_arrayOfClassNested b, tc_stringser_sequenceOfClassInherit c, tc_stringser_listOfClassNested d, tc_stringser_listOfClassInherit e);

/* ::tc_stringser::classInherit */
tc_stringser_classInherit tc_stringser_classInherit__new(void);
tc_stringser_classInherit tc_stringser_classInheritDeclare(cx_object _parent, cx_string _name);
int tc_stringser_classInheritDefine(tc_stringser_classInherit _this, cx_bool a, cx_char b, cx_int32 c, cx_float32 d, cx_string e, tc_stringser_color f, tc_stringser_moveMode g, cx_bool a_1, cx_char b_1, cx_int32 c_1, cx_float32 d_1, cx_string e_1, tc_stringser_color f_1, tc_stringser_moveMode g_1);
tc_stringser_classInherit tc_stringser_classInheritCreate(cx_bool a, cx_char b, cx_int32 c, cx_float32 d, cx_string e, tc_stringser_color f, tc_stringser_moveMode g, cx_bool a_1, cx_char b_1, cx_int32 c_1, cx_float32 d_1, cx_string e_1, tc_stringser_color f_1, tc_stringser_moveMode g_1);

/* ::tc_stringser::classNested */
tc_stringser_classNested tc_stringser_classNested__new(void);
tc_stringser_classNested tc_stringser_classNestedDeclare(cx_object _parent, cx_string _name);
int tc_stringser_classNestedDefine(tc_stringser_classNested _this, tc_stringser_classPrimitives a, tc_stringser_classInherit b, tc_stringser_arrayOfInt c, tc_stringser_sequenceOfInt d, tc_stringser_listOfInt e);
tc_stringser_classNested tc_stringser_classNestedCreate(tc_stringser_classPrimitives a, tc_stringser_classInherit b, tc_stringser_arrayOfInt c, tc_stringser_sequenceOfInt d, tc_stringser_listOfInt e);

/* ::tc_stringser::classPrimitives */
tc_stringser_classPrimitives tc_stringser_classPrimitives__new(void);
tc_stringser_classPrimitives tc_stringser_classPrimitivesDeclare(cx_object _parent, cx_string _name);
int tc_stringser_classPrimitivesDefine(tc_stringser_classPrimitives _this, cx_bool a, cx_char b, cx_int32 c, cx_float32 d, cx_string e, tc_stringser_color f, tc_stringser_moveMode g);
tc_stringser_classPrimitives tc_stringser_classPrimitivesCreate(cx_bool a, cx_char b, cx_int32 c, cx_float32 d, cx_string e, tc_stringser_color f, tc_stringser_moveMode g);


/* ::tc_stringser::listOfClassInherit */
#define tc_stringser_listOfClassInheritForeach(list, elem) \
    cx_iter elem##_iter = cx_llIter(list);\
    tc_stringser_classInherit elem;\
    while(cx_iterHasNext(&elem##_iter)) {\
        elem = cx_iterNext(&elem##_iter);

void tc_stringser_listOfClassInheritInsert(tc_stringser_listOfClassInherit list, tc_stringser_classInherit element);
void tc_stringser_listOfClassInheritAppend(tc_stringser_listOfClassInherit list, tc_stringser_classInherit element);
tc_stringser_classInherit tc_stringser_listOfClassInherit__takeFirst(tc_stringser_listOfClassInherit list);
tc_stringser_classInherit tc_stringser_listOfClassInherit__last(tc_stringser_listOfClassInherit list);
void tc_stringser_listOfClassInherit__clear(tc_stringser_listOfClassInherit list);
tc_stringser_classInherit tc_stringser_listOfClassInherit__get(tc_stringser_listOfClassInherit list, cx_uint32 index);
cx_uint32 tc_stringser_listOfClassInheritSize(tc_stringser_listOfClassInherit list);

/* ::tc_stringser::sequenceOfClassInherit */
#define tc_stringser_sequenceOfClassInheritForeach(seq, elem) \
    cx_uint32 elem##_iter;\
    tc_stringser_classInherit elem;\
    for(elem##_iter=0; elem##_iter<seq.length; elem##_iter++) {\
        elem = &seq.buffer[elem##_iter];

tc_stringser_classInherit tc_stringser_sequenceOfClassInheritAppend(tc_stringser_sequenceOfClassInherit *seq);
void tc_stringser_sequenceOfClassInheritSize(tc_stringser_sequenceOfClassInherit *seq, cx_uint32 length);
void tc_stringser_sequenceOfClassInherit__clear(tc_stringser_sequenceOfClassInherit *seq);

/* ::tc_stringser::listOfClassNested */
#define tc_stringser_listOfClassNestedForeach(list, elem) \
    cx_iter elem##_iter = cx_llIter(list);\
    tc_stringser_classNested elem;\
    while(cx_iterHasNext(&elem##_iter)) {\
        elem = cx_iterNext(&elem##_iter);

void tc_stringser_listOfClassNestedInsert(tc_stringser_listOfClassNested list, tc_stringser_classNested element);
void tc_stringser_listOfClassNestedAppend(tc_stringser_listOfClassNested list, tc_stringser_classNested element);
tc_stringser_classNested tc_stringser_listOfClassNested__takeFirst(tc_stringser_listOfClassNested list);
tc_stringser_classNested tc_stringser_listOfClassNested__last(tc_stringser_listOfClassNested list);
void tc_stringser_listOfClassNested__clear(tc_stringser_listOfClassNested list);
tc_stringser_classNested tc_stringser_listOfClassNested__get(tc_stringser_listOfClassNested list, cx_uint32 index);
cx_uint32 tc_stringser_listOfClassNestedSize(tc_stringser_listOfClassNested list);

/* ::tc_stringser::sequenceOfClassNested */
#define tc_stringser_sequenceOfClassNestedForeach(seq, elem) \
    cx_uint32 elem##_iter;\
    tc_stringser_classNested elem;\
    for(elem##_iter=0; elem##_iter<seq.length; elem##_iter++) {\
        elem = &seq.buffer[elem##_iter];

tc_stringser_classNested tc_stringser_sequenceOfClassNestedAppend(tc_stringser_sequenceOfClassNested *seq);
void tc_stringser_sequenceOfClassNestedSize(tc_stringser_sequenceOfClassNested *seq, cx_uint32 length);
void tc_stringser_sequenceOfClassNested__clear(tc_stringser_sequenceOfClassNested *seq);

/* ::tc_stringser::listOfClassPrimitives */
#define tc_stringser_listOfClassPrimitivesForeach(list, elem) \
    cx_iter elem##_iter = cx_llIter(list);\
    tc_stringser_classPrimitives elem;\
    while(cx_iterHasNext(&elem##_iter)) {\
        elem = cx_iterNext(&elem##_iter);

void tc_stringser_listOfClassPrimitivesInsert(tc_stringser_listOfClassPrimitives list, tc_stringser_classPrimitives element);
void tc_stringser_listOfClassPrimitivesAppend(tc_stringser_listOfClassPrimitives list, tc_stringser_classPrimitives element);
tc_stringser_classPrimitives tc_stringser_listOfClassPrimitives__takeFirst(tc_stringser_listOfClassPrimitives list);
tc_stringser_classPrimitives tc_stringser_listOfClassPrimitives__last(tc_stringser_listOfClassPrimitives list);
void tc_stringser_listOfClassPrimitives__clear(tc_stringser_listOfClassPrimitives list);
tc_stringser_classPrimitives tc_stringser_listOfClassPrimitives__get(tc_stringser_listOfClassPrimitives list, cx_uint32 index);
cx_uint32 tc_stringser_listOfClassPrimitivesSize(tc_stringser_listOfClassPrimitives list);

/* ::tc_stringser::sequenceOfClassPrimitives */
#define tc_stringser_sequenceOfClassPrimitivesForeach(seq, elem) \
    cx_uint32 elem##_iter;\
    tc_stringser_classPrimitives elem;\
    for(elem##_iter=0; elem##_iter<seq.length; elem##_iter++) {\
        elem = &seq.buffer[elem##_iter];

tc_stringser_classPrimitives tc_stringser_sequenceOfClassPrimitivesAppend(tc_stringser_sequenceOfClassPrimitives *seq);
void tc_stringser_sequenceOfClassPrimitivesSize(tc_stringser_sequenceOfClassPrimitives *seq, cx_uint32 length);
void tc_stringser_sequenceOfClassPrimitives__clear(tc_stringser_sequenceOfClassPrimitives *seq);

/* ::tc_stringser::listOfColor */
#define tc_stringser_listOfColorForeach(list, elem) \
    cx_iter elem##_iter = cx_llIter(list);\
    tc_stringser_color *elem;\
    while(cx_iterHasNext(&elem##_iter)) {\
        elem = cx_iterNext(&elem##_iter);

void tc_stringser_listOfColorInsert(tc_stringser_listOfColor list, tc_stringser_color element);
void tc_stringser_listOfColorAppend(tc_stringser_listOfColor list, tc_stringser_color element);
tc_stringser_color tc_stringser_listOfColor__takeFirst(tc_stringser_listOfColor list);
tc_stringser_color tc_stringser_listOfColor__last(tc_stringser_listOfColor list);
void tc_stringser_listOfColor__clear(tc_stringser_listOfColor list);
tc_stringser_color tc_stringser_listOfColor__get(tc_stringser_listOfColor list, cx_uint32 index);
cx_uint32 tc_stringser_listOfColorSize(tc_stringser_listOfColor list);

/* ::tc_stringser::sequenceOfColor */
#define tc_stringser_sequenceOfColorForeach(seq, elem) \
    cx_uint32 elem##_iter;\
    tc_stringser_color *elem;\
    for(elem##_iter=0; elem##_iter<seq.length; elem##_iter++) {\
        elem = &seq.buffer[elem##_iter];

tc_stringser_color* tc_stringser_sequenceOfColorAppend(tc_stringser_sequenceOfColor *seq);
void tc_stringser_sequenceOfColorSize(tc_stringser_sequenceOfColor *seq, cx_uint32 length);
void tc_stringser_sequenceOfColor__clear(tc_stringser_sequenceOfColor *seq);

/* ::tc_stringser::listOfBool */
#define tc_stringser_listOfBoolForeach(list, elem) \
    cx_iter elem##_iter = cx_llIter(list);\
    cx_bool *elem;\
    while(cx_iterHasNext(&elem##_iter)) {\
        elem = cx_iterNext(&elem##_iter);

void tc_stringser_listOfBoolInsert(tc_stringser_listOfBool list, cx_bool element);
void tc_stringser_listOfBoolAppend(tc_stringser_listOfBool list, cx_bool element);
cx_bool tc_stringser_listOfBool__takeFirst(tc_stringser_listOfBool list);
cx_bool tc_stringser_listOfBool__last(tc_stringser_listOfBool list);
void tc_stringser_listOfBool__clear(tc_stringser_listOfBool list);
cx_bool tc_stringser_listOfBool__get(tc_stringser_listOfBool list, cx_uint32 index);
cx_uint32 tc_stringser_listOfBoolSize(tc_stringser_listOfBool list);

/* ::tc_stringser::listOfChar */
#define tc_stringser_listOfCharForeach(list, elem) \
    cx_iter elem##_iter = cx_llIter(list);\
    cx_char *elem;\
    while(cx_iterHasNext(&elem##_iter)) {\
        elem = cx_iterNext(&elem##_iter);

void tc_stringser_listOfCharInsert(tc_stringser_listOfChar list, cx_char element);
void tc_stringser_listOfCharAppend(tc_stringser_listOfChar list, cx_char element);
cx_char tc_stringser_listOfChar__takeFirst(tc_stringser_listOfChar list);
cx_char tc_stringser_listOfChar__last(tc_stringser_listOfChar list);
void tc_stringser_listOfChar__clear(tc_stringser_listOfChar list);
cx_char tc_stringser_listOfChar__get(tc_stringser_listOfChar list, cx_uint32 index);
cx_uint32 tc_stringser_listOfCharSize(tc_stringser_listOfChar list);

/* ::tc_stringser::listOfFloat */
#define tc_stringser_listOfFloatForeach(list, elem) \
    cx_iter elem##_iter = cx_llIter(list);\
    cx_float32 *elem;\
    while(cx_iterHasNext(&elem##_iter)) {\
        elem = cx_iterNext(&elem##_iter);

void tc_stringser_listOfFloatInsert(tc_stringser_listOfFloat list, cx_float32 element);
void tc_stringser_listOfFloatAppend(tc_stringser_listOfFloat list, cx_float32 element);
cx_float32 tc_stringser_listOfFloat__takeFirst(tc_stringser_listOfFloat list);
cx_float32 tc_stringser_listOfFloat__last(tc_stringser_listOfFloat list);
void tc_stringser_listOfFloat__clear(tc_stringser_listOfFloat list);
cx_float32 tc_stringser_listOfFloat__get(tc_stringser_listOfFloat list, cx_uint32 index);
cx_uint32 tc_stringser_listOfFloatSize(tc_stringser_listOfFloat list);

/* ::tc_stringser::listOfInt */
#define tc_stringser_listOfIntForeach(list, elem) \
    cx_iter elem##_iter = cx_llIter(list);\
    cx_int32 *elem;\
    while(cx_iterHasNext(&elem##_iter)) {\
        elem = cx_iterNext(&elem##_iter);

void tc_stringser_listOfIntInsert(tc_stringser_listOfInt list, cx_int32 element);
void tc_stringser_listOfIntAppend(tc_stringser_listOfInt list, cx_int32 element);
cx_int32 tc_stringser_listOfInt__takeFirst(tc_stringser_listOfInt list);
cx_int32 tc_stringser_listOfInt__last(tc_stringser_listOfInt list);
void tc_stringser_listOfInt__clear(tc_stringser_listOfInt list);
cx_int32 tc_stringser_listOfInt__get(tc_stringser_listOfInt list, cx_uint32 index);
cx_uint32 tc_stringser_listOfIntSize(tc_stringser_listOfInt list);

/* ::tc_stringser::listOfMoveMode */
#define tc_stringser_listOfMoveModeForeach(list, elem) \
    cx_iter elem##_iter = cx_llIter(list);\
    tc_stringser_moveMode *elem;\
    while(cx_iterHasNext(&elem##_iter)) {\
        elem = cx_iterNext(&elem##_iter);

void tc_stringser_listOfMoveModeInsert(tc_stringser_listOfMoveMode list, tc_stringser_moveMode element);
void tc_stringser_listOfMoveModeAppend(tc_stringser_listOfMoveMode list, tc_stringser_moveMode element);
tc_stringser_moveMode tc_stringser_listOfMoveMode__takeFirst(tc_stringser_listOfMoveMode list);
tc_stringser_moveMode tc_stringser_listOfMoveMode__last(tc_stringser_listOfMoveMode list);
void tc_stringser_listOfMoveMode__clear(tc_stringser_listOfMoveMode list);
tc_stringser_moveMode tc_stringser_listOfMoveMode__get(tc_stringser_listOfMoveMode list, cx_uint32 index);
cx_uint32 tc_stringser_listOfMoveModeSize(tc_stringser_listOfMoveMode list);

/* ::tc_stringser::listOfString */
#define tc_stringser_listOfStringForeach(list, elem) \
    cx_iter elem##_iter = cx_llIter(list);\
    cx_string *elem;\
    while(cx_iterHasNext(&elem##_iter)) {\
        elem = cx_iterNext(&elem##_iter);

void tc_stringser_listOfStringInsert(tc_stringser_listOfString list, cx_string element);
void tc_stringser_listOfStringAppend(tc_stringser_listOfString list, cx_string element);
cx_string tc_stringser_listOfString__takeFirst(tc_stringser_listOfString list);
cx_string tc_stringser_listOfString__last(tc_stringser_listOfString list);
void tc_stringser_listOfString__clear(tc_stringser_listOfString list);
cx_string tc_stringser_listOfString__get(tc_stringser_listOfString list, cx_uint32 index);
cx_uint32 tc_stringser_listOfStringSize(tc_stringser_listOfString list);

/* ::tc_stringser::sequenceOfMoveMode */
#define tc_stringser_sequenceOfMoveModeForeach(seq, elem) \
    cx_uint32 elem##_iter;\
    tc_stringser_moveMode *elem;\
    for(elem##_iter=0; elem##_iter<seq.length; elem##_iter++) {\
        elem = &seq.buffer[elem##_iter];

tc_stringser_moveMode* tc_stringser_sequenceOfMoveModeAppend(tc_stringser_sequenceOfMoveMode *seq);
void tc_stringser_sequenceOfMoveModeSize(tc_stringser_sequenceOfMoveMode *seq, cx_uint32 length);
void tc_stringser_sequenceOfMoveMode__clear(tc_stringser_sequenceOfMoveMode *seq);

/* ::tc_stringser::sequenceOfBool */
#define tc_stringser_sequenceOfBoolForeach(seq, elem) \
    cx_uint32 elem##_iter;\
    cx_bool *elem;\
    for(elem##_iter=0; elem##_iter<seq.length; elem##_iter++) {\
        elem = &seq.buffer[elem##_iter];

cx_bool* tc_stringser_sequenceOfBoolAppend(tc_stringser_sequenceOfBool *seq);
void tc_stringser_sequenceOfBoolSize(tc_stringser_sequenceOfBool *seq, cx_uint32 length);
void tc_stringser_sequenceOfBool__clear(tc_stringser_sequenceOfBool *seq);

/* ::tc_stringser::sequenceOfChar */
#define tc_stringser_sequenceOfCharForeach(seq, elem) \
    cx_uint32 elem##_iter;\
    cx_char *elem;\
    for(elem##_iter=0; elem##_iter<seq.length; elem##_iter++) {\
        elem = &seq.buffer[elem##_iter];

cx_char* tc_stringser_sequenceOfCharAppend(tc_stringser_sequenceOfChar *seq);
void tc_stringser_sequenceOfCharSize(tc_stringser_sequenceOfChar *seq, cx_uint32 length);
void tc_stringser_sequenceOfChar__clear(tc_stringser_sequenceOfChar *seq);

/* ::tc_stringser::sequenceOfFloat */
#define tc_stringser_sequenceOfFloatForeach(seq, elem) \
    cx_uint32 elem##_iter;\
    cx_float32 *elem;\
    for(elem##_iter=0; elem##_iter<seq.length; elem##_iter++) {\
        elem = &seq.buffer[elem##_iter];

cx_float32* tc_stringser_sequenceOfFloatAppend(tc_stringser_sequenceOfFloat *seq);
void tc_stringser_sequenceOfFloatSize(tc_stringser_sequenceOfFloat *seq, cx_uint32 length);
void tc_stringser_sequenceOfFloat__clear(tc_stringser_sequenceOfFloat *seq);

/* ::tc_stringser::sequenceOfInt */
#define tc_stringser_sequenceOfIntForeach(seq, elem) \
    cx_uint32 elem##_iter;\
    cx_int32 *elem;\
    for(elem##_iter=0; elem##_iter<seq.length; elem##_iter++) {\
        elem = &seq.buffer[elem##_iter];

cx_int32* tc_stringser_sequenceOfIntAppend(tc_stringser_sequenceOfInt *seq);
void tc_stringser_sequenceOfIntSize(tc_stringser_sequenceOfInt *seq, cx_uint32 length);
void tc_stringser_sequenceOfInt__clear(tc_stringser_sequenceOfInt *seq);

/* ::tc_stringser::sequenceOfString */
#define tc_stringser_sequenceOfStringForeach(seq, elem) \
    cx_uint32 elem##_iter;\
    cx_string *elem;\
    for(elem##_iter=0; elem##_iter<seq.length; elem##_iter++) {\
        elem = &seq.buffer[elem##_iter];

cx_string* tc_stringser_sequenceOfStringAppend(tc_stringser_sequenceOfString *seq);
void tc_stringser_sequenceOfStringSize(tc_stringser_sequenceOfString *seq, cx_uint32 length);
void tc_stringser_sequenceOfString__clear(tc_stringser_sequenceOfString *seq);

#ifdef __cplusplus
}
#endif
#endif

