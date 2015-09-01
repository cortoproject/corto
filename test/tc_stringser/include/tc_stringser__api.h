/* tc_stringser__api.h
 *
 * API convenience functions for C-language.
 * This file contains generated code. Do not modify!
 */

#ifndef tc_stringser__API_H
#define tc_stringser__API_H

#include "tc_stringser__type.h"
#include "corto.h"

#ifdef __cplusplus
extern "C" {
#endif
/* ::tc_stringser::arrayOfBool */
tc_arrayOfBool* tc_arrayOfBoolCreate(void);
tc_arrayOfBool* tc_arrayOfBoolCreateChild(cx_object _parent, cx_string _name);

tc_arrayOfBool* tc_arrayOfBoolDeclare(void);
tc_arrayOfBool* tc_arrayOfBoolDeclareChild(cx_object _parent, cx_string _name);
cx_int16 tc_arrayOfBoolDefine(tc_arrayOfBool* _this, tc_arrayOfBool value);
void tc_arrayOfBoolUpdate(tc_arrayOfBool* _this, tc_arrayOfBool value);
void tc_arrayOfBoolSet(tc_arrayOfBool* _this, tc_arrayOfBool value);
cx_string tc_arrayOfBoolStr(tc_arrayOfBool value);
tc_arrayOfBool* tc_arrayOfBoolFromStr(tc_arrayOfBool* value, cx_string str);
cx_int16 tc_arrayOfBoolCopy(tc_arrayOfBool* *dst, tc_arrayOfBool* src);
cx_int16 tc_arrayOfBoolCompare(tc_arrayOfBool* dst, tc_arrayOfBool* src);

cx_int16 tc_arrayOfBoolInit(tc_arrayOfBool* value);
cx_int16 tc_arrayOfBoolDeinit(tc_arrayOfBool* value);

/* ::tc_stringser::arrayOfChar */
tc_arrayOfChar* tc_arrayOfCharCreate(void);
tc_arrayOfChar* tc_arrayOfCharCreateChild(cx_object _parent, cx_string _name);

tc_arrayOfChar* tc_arrayOfCharDeclare(void);
tc_arrayOfChar* tc_arrayOfCharDeclareChild(cx_object _parent, cx_string _name);
cx_int16 tc_arrayOfCharDefine(tc_arrayOfChar* _this, tc_arrayOfChar value);
void tc_arrayOfCharUpdate(tc_arrayOfChar* _this, tc_arrayOfChar value);
void tc_arrayOfCharSet(tc_arrayOfChar* _this, tc_arrayOfChar value);
cx_string tc_arrayOfCharStr(tc_arrayOfChar value);
tc_arrayOfChar* tc_arrayOfCharFromStr(tc_arrayOfChar* value, cx_string str);
cx_int16 tc_arrayOfCharCopy(tc_arrayOfChar* *dst, tc_arrayOfChar* src);
cx_int16 tc_arrayOfCharCompare(tc_arrayOfChar* dst, tc_arrayOfChar* src);

cx_int16 tc_arrayOfCharInit(tc_arrayOfChar* value);
cx_int16 tc_arrayOfCharDeinit(tc_arrayOfChar* value);

/* ::tc_stringser::arrayOfClassInherit */
tc_arrayOfClassInherit* tc_arrayOfClassInheritCreate(void);
tc_arrayOfClassInherit* tc_arrayOfClassInheritCreateChild(cx_object _parent, cx_string _name);

tc_arrayOfClassInherit* tc_arrayOfClassInheritDeclare(void);
tc_arrayOfClassInherit* tc_arrayOfClassInheritDeclareChild(cx_object _parent, cx_string _name);
cx_int16 tc_arrayOfClassInheritDefine(tc_arrayOfClassInherit* _this, tc_arrayOfClassInherit value);
void tc_arrayOfClassInheritUpdate(tc_arrayOfClassInherit* _this, tc_arrayOfClassInherit value);
void tc_arrayOfClassInheritSet(tc_arrayOfClassInherit* _this, tc_arrayOfClassInherit value);
cx_string tc_arrayOfClassInheritStr(tc_arrayOfClassInherit value);
tc_arrayOfClassInherit* tc_arrayOfClassInheritFromStr(tc_arrayOfClassInherit* value, cx_string str);
cx_int16 tc_arrayOfClassInheritCopy(tc_arrayOfClassInherit* *dst, tc_arrayOfClassInherit* src);
cx_int16 tc_arrayOfClassInheritCompare(tc_arrayOfClassInherit* dst, tc_arrayOfClassInherit* src);

cx_int16 tc_arrayOfClassInheritInit(tc_arrayOfClassInherit* value);
cx_int16 tc_arrayOfClassInheritDeinit(tc_arrayOfClassInherit* value);

/* ::tc_stringser::arrayOfClassNested */
tc_arrayOfClassNested* tc_arrayOfClassNestedCreate(void);
tc_arrayOfClassNested* tc_arrayOfClassNestedCreateChild(cx_object _parent, cx_string _name);

tc_arrayOfClassNested* tc_arrayOfClassNestedDeclare(void);
tc_arrayOfClassNested* tc_arrayOfClassNestedDeclareChild(cx_object _parent, cx_string _name);
cx_int16 tc_arrayOfClassNestedDefine(tc_arrayOfClassNested* _this, tc_arrayOfClassNested value);
void tc_arrayOfClassNestedUpdate(tc_arrayOfClassNested* _this, tc_arrayOfClassNested value);
void tc_arrayOfClassNestedSet(tc_arrayOfClassNested* _this, tc_arrayOfClassNested value);
cx_string tc_arrayOfClassNestedStr(tc_arrayOfClassNested value);
tc_arrayOfClassNested* tc_arrayOfClassNestedFromStr(tc_arrayOfClassNested* value, cx_string str);
cx_int16 tc_arrayOfClassNestedCopy(tc_arrayOfClassNested* *dst, tc_arrayOfClassNested* src);
cx_int16 tc_arrayOfClassNestedCompare(tc_arrayOfClassNested* dst, tc_arrayOfClassNested* src);

cx_int16 tc_arrayOfClassNestedInit(tc_arrayOfClassNested* value);
cx_int16 tc_arrayOfClassNestedDeinit(tc_arrayOfClassNested* value);

/* ::tc_stringser::arrayOfClassPrimitives */
tc_arrayOfClassPrimitives* tc_arrayOfClassPrimitivesCreate(void);
tc_arrayOfClassPrimitives* tc_arrayOfClassPrimitivesCreateChild(cx_object _parent, cx_string _name);

tc_arrayOfClassPrimitives* tc_arrayOfClassPrimitivesDeclare(void);
tc_arrayOfClassPrimitives* tc_arrayOfClassPrimitivesDeclareChild(cx_object _parent, cx_string _name);
cx_int16 tc_arrayOfClassPrimitivesDefine(tc_arrayOfClassPrimitives* _this, tc_arrayOfClassPrimitives value);
void tc_arrayOfClassPrimitivesUpdate(tc_arrayOfClassPrimitives* _this, tc_arrayOfClassPrimitives value);
void tc_arrayOfClassPrimitivesSet(tc_arrayOfClassPrimitives* _this, tc_arrayOfClassPrimitives value);
cx_string tc_arrayOfClassPrimitivesStr(tc_arrayOfClassPrimitives value);
tc_arrayOfClassPrimitives* tc_arrayOfClassPrimitivesFromStr(tc_arrayOfClassPrimitives* value, cx_string str);
cx_int16 tc_arrayOfClassPrimitivesCopy(tc_arrayOfClassPrimitives* *dst, tc_arrayOfClassPrimitives* src);
cx_int16 tc_arrayOfClassPrimitivesCompare(tc_arrayOfClassPrimitives* dst, tc_arrayOfClassPrimitives* src);

cx_int16 tc_arrayOfClassPrimitivesInit(tc_arrayOfClassPrimitives* value);
cx_int16 tc_arrayOfClassPrimitivesDeinit(tc_arrayOfClassPrimitives* value);

/* ::tc_stringser::arrayOfColor */
tc_arrayOfColor* tc_arrayOfColorCreate(void);
tc_arrayOfColor* tc_arrayOfColorCreateChild(cx_object _parent, cx_string _name);

tc_arrayOfColor* tc_arrayOfColorDeclare(void);
tc_arrayOfColor* tc_arrayOfColorDeclareChild(cx_object _parent, cx_string _name);
cx_int16 tc_arrayOfColorDefine(tc_arrayOfColor* _this, tc_arrayOfColor value);
void tc_arrayOfColorUpdate(tc_arrayOfColor* _this, tc_arrayOfColor value);
void tc_arrayOfColorSet(tc_arrayOfColor* _this, tc_arrayOfColor value);
cx_string tc_arrayOfColorStr(tc_arrayOfColor value);
tc_arrayOfColor* tc_arrayOfColorFromStr(tc_arrayOfColor* value, cx_string str);
cx_int16 tc_arrayOfColorCopy(tc_arrayOfColor* *dst, tc_arrayOfColor* src);
cx_int16 tc_arrayOfColorCompare(tc_arrayOfColor* dst, tc_arrayOfColor* src);

cx_int16 tc_arrayOfColorInit(tc_arrayOfColor* value);
cx_int16 tc_arrayOfColorDeinit(tc_arrayOfColor* value);

/* ::tc_stringser::arrayOfFloat */
tc_arrayOfFloat* tc_arrayOfFloatCreate(void);
tc_arrayOfFloat* tc_arrayOfFloatCreateChild(cx_object _parent, cx_string _name);

tc_arrayOfFloat* tc_arrayOfFloatDeclare(void);
tc_arrayOfFloat* tc_arrayOfFloatDeclareChild(cx_object _parent, cx_string _name);
cx_int16 tc_arrayOfFloatDefine(tc_arrayOfFloat* _this, tc_arrayOfFloat value);
void tc_arrayOfFloatUpdate(tc_arrayOfFloat* _this, tc_arrayOfFloat value);
void tc_arrayOfFloatSet(tc_arrayOfFloat* _this, tc_arrayOfFloat value);
cx_string tc_arrayOfFloatStr(tc_arrayOfFloat value);
tc_arrayOfFloat* tc_arrayOfFloatFromStr(tc_arrayOfFloat* value, cx_string str);
cx_int16 tc_arrayOfFloatCopy(tc_arrayOfFloat* *dst, tc_arrayOfFloat* src);
cx_int16 tc_arrayOfFloatCompare(tc_arrayOfFloat* dst, tc_arrayOfFloat* src);

cx_int16 tc_arrayOfFloatInit(tc_arrayOfFloat* value);
cx_int16 tc_arrayOfFloatDeinit(tc_arrayOfFloat* value);

/* ::tc_stringser::arrayOfInt */
tc_arrayOfInt* tc_arrayOfIntCreate(void);
tc_arrayOfInt* tc_arrayOfIntCreateChild(cx_object _parent, cx_string _name);

tc_arrayOfInt* tc_arrayOfIntDeclare(void);
tc_arrayOfInt* tc_arrayOfIntDeclareChild(cx_object _parent, cx_string _name);
cx_int16 tc_arrayOfIntDefine(tc_arrayOfInt* _this, tc_arrayOfInt value);
void tc_arrayOfIntUpdate(tc_arrayOfInt* _this, tc_arrayOfInt value);
void tc_arrayOfIntSet(tc_arrayOfInt* _this, tc_arrayOfInt value);
cx_string tc_arrayOfIntStr(tc_arrayOfInt value);
tc_arrayOfInt* tc_arrayOfIntFromStr(tc_arrayOfInt* value, cx_string str);
cx_int16 tc_arrayOfIntCopy(tc_arrayOfInt* *dst, tc_arrayOfInt* src);
cx_int16 tc_arrayOfIntCompare(tc_arrayOfInt* dst, tc_arrayOfInt* src);

cx_int16 tc_arrayOfIntInit(tc_arrayOfInt* value);
cx_int16 tc_arrayOfIntDeinit(tc_arrayOfInt* value);

/* ::tc_stringser::arrayOfMoveMode */
tc_arrayOfMoveMode* tc_arrayOfMoveModeCreate(void);
tc_arrayOfMoveMode* tc_arrayOfMoveModeCreateChild(cx_object _parent, cx_string _name);

tc_arrayOfMoveMode* tc_arrayOfMoveModeDeclare(void);
tc_arrayOfMoveMode* tc_arrayOfMoveModeDeclareChild(cx_object _parent, cx_string _name);
cx_int16 tc_arrayOfMoveModeDefine(tc_arrayOfMoveMode* _this, tc_arrayOfMoveMode value);
void tc_arrayOfMoveModeUpdate(tc_arrayOfMoveMode* _this, tc_arrayOfMoveMode value);
void tc_arrayOfMoveModeSet(tc_arrayOfMoveMode* _this, tc_arrayOfMoveMode value);
cx_string tc_arrayOfMoveModeStr(tc_arrayOfMoveMode value);
tc_arrayOfMoveMode* tc_arrayOfMoveModeFromStr(tc_arrayOfMoveMode* value, cx_string str);
cx_int16 tc_arrayOfMoveModeCopy(tc_arrayOfMoveMode* *dst, tc_arrayOfMoveMode* src);
cx_int16 tc_arrayOfMoveModeCompare(tc_arrayOfMoveMode* dst, tc_arrayOfMoveMode* src);

cx_int16 tc_arrayOfMoveModeInit(tc_arrayOfMoveMode* value);
cx_int16 tc_arrayOfMoveModeDeinit(tc_arrayOfMoveMode* value);

/* ::tc_stringser::arrayOfString */
tc_arrayOfString* tc_arrayOfStringCreate(void);
tc_arrayOfString* tc_arrayOfStringCreateChild(cx_object _parent, cx_string _name);

tc_arrayOfString* tc_arrayOfStringDeclare(void);
tc_arrayOfString* tc_arrayOfStringDeclareChild(cx_object _parent, cx_string _name);
cx_int16 tc_arrayOfStringDefine(tc_arrayOfString* _this, tc_arrayOfString value);
void tc_arrayOfStringUpdate(tc_arrayOfString* _this, tc_arrayOfString value);
void tc_arrayOfStringSet(tc_arrayOfString* _this, tc_arrayOfString value);
cx_string tc_arrayOfStringStr(tc_arrayOfString value);
tc_arrayOfString* tc_arrayOfStringFromStr(tc_arrayOfString* value, cx_string str);
cx_int16 tc_arrayOfStringCopy(tc_arrayOfString* *dst, tc_arrayOfString* src);
cx_int16 tc_arrayOfStringCompare(tc_arrayOfString* dst, tc_arrayOfString* src);

cx_int16 tc_arrayOfStringInit(tc_arrayOfString* value);
cx_int16 tc_arrayOfStringDeinit(tc_arrayOfString* value);

/* ::tc_stringser::classCompositeCollection */
tc_classCompositeCollection tc_classCompositeCollectionCreate(tc_arrayOfClassInherit a, tc_arrayOfClassNested b, tc_sequenceOfClassInherit c, tc_sequenceOfClassNested d, tc_listOfClassInherit e, tc_listOfClassNested f);
tc_classCompositeCollection tc_classCompositeCollectionCreateChild(cx_object _parent, cx_string _name, tc_arrayOfClassInherit a, tc_arrayOfClassNested b, tc_sequenceOfClassInherit c, tc_sequenceOfClassNested d, tc_listOfClassInherit e, tc_listOfClassNested f);

tc_classCompositeCollection tc_classCompositeCollectionDeclare(void);
tc_classCompositeCollection tc_classCompositeCollectionDeclareChild(cx_object _parent, cx_string _name);
cx_int16 tc_classCompositeCollectionDefine(tc_classCompositeCollection _this, tc_arrayOfClassInherit a, tc_arrayOfClassNested b, tc_sequenceOfClassInherit c, tc_sequenceOfClassNested d, tc_listOfClassInherit e, tc_listOfClassNested f);
void tc_classCompositeCollectionUpdate(tc_classCompositeCollection _this, tc_arrayOfClassInherit a, tc_arrayOfClassNested b, tc_sequenceOfClassInherit c, tc_sequenceOfClassNested d, tc_listOfClassInherit e, tc_listOfClassNested f);
void tc_classCompositeCollectionSet(tc_classCompositeCollection _this, tc_arrayOfClassInherit a, tc_arrayOfClassNested b, tc_sequenceOfClassInherit c, tc_sequenceOfClassNested d, tc_listOfClassInherit e, tc_listOfClassNested f);
cx_string tc_classCompositeCollectionStr(tc_classCompositeCollection value);
tc_classCompositeCollection tc_classCompositeCollectionFromStr(tc_classCompositeCollection value, cx_string str);
cx_int16 tc_classCompositeCollectionCopy(tc_classCompositeCollection *dst, tc_classCompositeCollection src);
cx_int16 tc_classCompositeCollectionCompare(tc_classCompositeCollection dst, tc_classCompositeCollection src);

/* ::tc_stringser::classInherit */
tc_classInherit tc_classInheritCreate(cx_bool a, cx_char b, cx_int32 c, cx_float32 d, cx_string e, tc_color f, tc_moveMode g, cx_bool a_1, cx_char b_1, cx_int32 c_1, cx_float32 d_1, cx_string e_1, tc_color f_1, tc_moveMode g_1);
tc_classInherit tc_classInheritCreateChild(cx_object _parent, cx_string _name, cx_bool a, cx_char b, cx_int32 c, cx_float32 d, cx_string e, tc_color f, tc_moveMode g, cx_bool a_1, cx_char b_1, cx_int32 c_1, cx_float32 d_1, cx_string e_1, tc_color f_1, tc_moveMode g_1);

tc_classInherit tc_classInheritDeclare(void);
tc_classInherit tc_classInheritDeclareChild(cx_object _parent, cx_string _name);
cx_int16 tc_classInheritDefine(tc_classInherit _this, cx_bool a, cx_char b, cx_int32 c, cx_float32 d, cx_string e, tc_color f, tc_moveMode g, cx_bool a_1, cx_char b_1, cx_int32 c_1, cx_float32 d_1, cx_string e_1, tc_color f_1, tc_moveMode g_1);
void tc_classInheritUpdate(tc_classInherit _this, cx_bool a, cx_char b, cx_int32 c, cx_float32 d, cx_string e, tc_color f, tc_moveMode g, cx_bool a_1, cx_char b_1, cx_int32 c_1, cx_float32 d_1, cx_string e_1, tc_color f_1, tc_moveMode g_1);
void tc_classInheritSet(tc_classInherit _this, cx_bool a, cx_char b, cx_int32 c, cx_float32 d, cx_string e, tc_color f, tc_moveMode g, cx_bool a_1, cx_char b_1, cx_int32 c_1, cx_float32 d_1, cx_string e_1, tc_color f_1, tc_moveMode g_1);
cx_string tc_classInheritStr(tc_classInherit value);
tc_classInherit tc_classInheritFromStr(tc_classInherit value, cx_string str);
cx_int16 tc_classInheritCopy(tc_classInherit *dst, tc_classInherit src);
cx_int16 tc_classInheritCompare(tc_classInherit dst, tc_classInherit src);

/* ::tc_stringser::classNested */
tc_classNested tc_classNestedCreate(tc_classPrimitives a, tc_classInherit b, tc_arrayOfInt c, tc_sequenceOfInt d, tc_listOfInt e);
tc_classNested tc_classNestedCreateChild(cx_object _parent, cx_string _name, tc_classPrimitives a, tc_classInherit b, tc_arrayOfInt c, tc_sequenceOfInt d, tc_listOfInt e);

tc_classNested tc_classNestedDeclare(void);
tc_classNested tc_classNestedDeclareChild(cx_object _parent, cx_string _name);
cx_int16 tc_classNestedDefine(tc_classNested _this, tc_classPrimitives a, tc_classInherit b, tc_arrayOfInt c, tc_sequenceOfInt d, tc_listOfInt e);
void tc_classNestedUpdate(tc_classNested _this, tc_classPrimitives a, tc_classInherit b, tc_arrayOfInt c, tc_sequenceOfInt d, tc_listOfInt e);
void tc_classNestedSet(tc_classNested _this, tc_classPrimitives a, tc_classInherit b, tc_arrayOfInt c, tc_sequenceOfInt d, tc_listOfInt e);
cx_string tc_classNestedStr(tc_classNested value);
tc_classNested tc_classNestedFromStr(tc_classNested value, cx_string str);
cx_int16 tc_classNestedCopy(tc_classNested *dst, tc_classNested src);
cx_int16 tc_classNestedCompare(tc_classNested dst, tc_classNested src);

/* ::tc_stringser::classPrimitives */
tc_classPrimitives tc_classPrimitivesCreate(cx_bool a, cx_char b, cx_int32 c, cx_float32 d, cx_string e, tc_color f, tc_moveMode g);
tc_classPrimitives tc_classPrimitivesCreateChild(cx_object _parent, cx_string _name, cx_bool a, cx_char b, cx_int32 c, cx_float32 d, cx_string e, tc_color f, tc_moveMode g);

tc_classPrimitives tc_classPrimitivesDeclare(void);
tc_classPrimitives tc_classPrimitivesDeclareChild(cx_object _parent, cx_string _name);
cx_int16 tc_classPrimitivesDefine(tc_classPrimitives _this, cx_bool a, cx_char b, cx_int32 c, cx_float32 d, cx_string e, tc_color f, tc_moveMode g);
void tc_classPrimitivesUpdate(tc_classPrimitives _this, cx_bool a, cx_char b, cx_int32 c, cx_float32 d, cx_string e, tc_color f, tc_moveMode g);
void tc_classPrimitivesSet(tc_classPrimitives _this, cx_bool a, cx_char b, cx_int32 c, cx_float32 d, cx_string e, tc_color f, tc_moveMode g);
cx_string tc_classPrimitivesStr(tc_classPrimitives value);
tc_classPrimitives tc_classPrimitivesFromStr(tc_classPrimitives value, cx_string str);
cx_int16 tc_classPrimitivesCopy(tc_classPrimitives *dst, tc_classPrimitives src);
cx_int16 tc_classPrimitivesCompare(tc_classPrimitives dst, tc_classPrimitives src);

/* ::tc_stringser::color */
tc_color* tc_colorCreate(void);
tc_color* tc_colorCreateChild(cx_object _parent, cx_string _name);

tc_color* tc_colorDeclare(void);
tc_color* tc_colorDeclareChild(cx_object _parent, cx_string _name);
cx_int16 tc_colorDefine(tc_color* _this, tc_color value);
void tc_colorUpdate(tc_color* _this, tc_color value);
void tc_colorSet(tc_color* _this, tc_color value);
cx_string tc_colorStr(tc_color value);
tc_color* tc_colorFromStr(tc_color* value, cx_string str);
cx_int16 tc_colorCopy(tc_color* *dst, tc_color* src);
cx_int16 tc_colorCompare(tc_color* dst, tc_color* src);

cx_int16 tc_colorInit(tc_color* value);
cx_int16 tc_colorDeinit(tc_color* value);

/* ::tc_stringser::listOfBool */
tc_listOfBool* tc_listOfBoolCreate(void);
tc_listOfBool* tc_listOfBoolCreateChild(cx_object _parent, cx_string _name);

tc_listOfBool* tc_listOfBoolDeclare(void);
tc_listOfBool* tc_listOfBoolDeclareChild(cx_object _parent, cx_string _name);
cx_int16 tc_listOfBoolDefine(tc_listOfBool* _this, tc_listOfBool value);
void tc_listOfBoolUpdate(tc_listOfBool* _this, tc_listOfBool value);
void tc_listOfBoolSet(tc_listOfBool* _this, tc_listOfBool value);
cx_string tc_listOfBoolStr(tc_listOfBool value);
tc_listOfBool* tc_listOfBoolFromStr(tc_listOfBool* value, cx_string str);
cx_int16 tc_listOfBoolCopy(tc_listOfBool* *dst, tc_listOfBool* src);
cx_int16 tc_listOfBoolCompare(tc_listOfBool* dst, tc_listOfBool* src);

cx_int16 tc_listOfBoolInit(tc_listOfBool* value);
cx_int16 tc_listOfBoolDeinit(tc_listOfBool* value);

/* ::tc_stringser::listOfChar */
tc_listOfChar* tc_listOfCharCreate(void);
tc_listOfChar* tc_listOfCharCreateChild(cx_object _parent, cx_string _name);

tc_listOfChar* tc_listOfCharDeclare(void);
tc_listOfChar* tc_listOfCharDeclareChild(cx_object _parent, cx_string _name);
cx_int16 tc_listOfCharDefine(tc_listOfChar* _this, tc_listOfChar value);
void tc_listOfCharUpdate(tc_listOfChar* _this, tc_listOfChar value);
void tc_listOfCharSet(tc_listOfChar* _this, tc_listOfChar value);
cx_string tc_listOfCharStr(tc_listOfChar value);
tc_listOfChar* tc_listOfCharFromStr(tc_listOfChar* value, cx_string str);
cx_int16 tc_listOfCharCopy(tc_listOfChar* *dst, tc_listOfChar* src);
cx_int16 tc_listOfCharCompare(tc_listOfChar* dst, tc_listOfChar* src);

cx_int16 tc_listOfCharInit(tc_listOfChar* value);
cx_int16 tc_listOfCharDeinit(tc_listOfChar* value);

/* ::tc_stringser::listOfClassInherit */
tc_listOfClassInherit* tc_listOfClassInheritCreate(void);
tc_listOfClassInherit* tc_listOfClassInheritCreateChild(cx_object _parent, cx_string _name);

tc_listOfClassInherit* tc_listOfClassInheritDeclare(void);
tc_listOfClassInherit* tc_listOfClassInheritDeclareChild(cx_object _parent, cx_string _name);
cx_int16 tc_listOfClassInheritDefine(tc_listOfClassInherit* _this, tc_listOfClassInherit value);
void tc_listOfClassInheritUpdate(tc_listOfClassInherit* _this, tc_listOfClassInherit value);
void tc_listOfClassInheritSet(tc_listOfClassInherit* _this, tc_listOfClassInherit value);
cx_string tc_listOfClassInheritStr(tc_listOfClassInherit value);
tc_listOfClassInherit* tc_listOfClassInheritFromStr(tc_listOfClassInherit* value, cx_string str);
cx_int16 tc_listOfClassInheritCopy(tc_listOfClassInherit* *dst, tc_listOfClassInherit* src);
cx_int16 tc_listOfClassInheritCompare(tc_listOfClassInherit* dst, tc_listOfClassInherit* src);

cx_int16 tc_listOfClassInheritInit(tc_listOfClassInherit* value);
cx_int16 tc_listOfClassInheritDeinit(tc_listOfClassInherit* value);

/* ::tc_stringser::listOfClassNested */
tc_listOfClassNested* tc_listOfClassNestedCreate(void);
tc_listOfClassNested* tc_listOfClassNestedCreateChild(cx_object _parent, cx_string _name);

tc_listOfClassNested* tc_listOfClassNestedDeclare(void);
tc_listOfClassNested* tc_listOfClassNestedDeclareChild(cx_object _parent, cx_string _name);
cx_int16 tc_listOfClassNestedDefine(tc_listOfClassNested* _this, tc_listOfClassNested value);
void tc_listOfClassNestedUpdate(tc_listOfClassNested* _this, tc_listOfClassNested value);
void tc_listOfClassNestedSet(tc_listOfClassNested* _this, tc_listOfClassNested value);
cx_string tc_listOfClassNestedStr(tc_listOfClassNested value);
tc_listOfClassNested* tc_listOfClassNestedFromStr(tc_listOfClassNested* value, cx_string str);
cx_int16 tc_listOfClassNestedCopy(tc_listOfClassNested* *dst, tc_listOfClassNested* src);
cx_int16 tc_listOfClassNestedCompare(tc_listOfClassNested* dst, tc_listOfClassNested* src);

cx_int16 tc_listOfClassNestedInit(tc_listOfClassNested* value);
cx_int16 tc_listOfClassNestedDeinit(tc_listOfClassNested* value);

/* ::tc_stringser::listOfClassPrimitives */
tc_listOfClassPrimitives* tc_listOfClassPrimitivesCreate(void);
tc_listOfClassPrimitives* tc_listOfClassPrimitivesCreateChild(cx_object _parent, cx_string _name);

tc_listOfClassPrimitives* tc_listOfClassPrimitivesDeclare(void);
tc_listOfClassPrimitives* tc_listOfClassPrimitivesDeclareChild(cx_object _parent, cx_string _name);
cx_int16 tc_listOfClassPrimitivesDefine(tc_listOfClassPrimitives* _this, tc_listOfClassPrimitives value);
void tc_listOfClassPrimitivesUpdate(tc_listOfClassPrimitives* _this, tc_listOfClassPrimitives value);
void tc_listOfClassPrimitivesSet(tc_listOfClassPrimitives* _this, tc_listOfClassPrimitives value);
cx_string tc_listOfClassPrimitivesStr(tc_listOfClassPrimitives value);
tc_listOfClassPrimitives* tc_listOfClassPrimitivesFromStr(tc_listOfClassPrimitives* value, cx_string str);
cx_int16 tc_listOfClassPrimitivesCopy(tc_listOfClassPrimitives* *dst, tc_listOfClassPrimitives* src);
cx_int16 tc_listOfClassPrimitivesCompare(tc_listOfClassPrimitives* dst, tc_listOfClassPrimitives* src);

cx_int16 tc_listOfClassPrimitivesInit(tc_listOfClassPrimitives* value);
cx_int16 tc_listOfClassPrimitivesDeinit(tc_listOfClassPrimitives* value);

/* ::tc_stringser::listOfColor */
tc_listOfColor* tc_listOfColorCreate(void);
tc_listOfColor* tc_listOfColorCreateChild(cx_object _parent, cx_string _name);

tc_listOfColor* tc_listOfColorDeclare(void);
tc_listOfColor* tc_listOfColorDeclareChild(cx_object _parent, cx_string _name);
cx_int16 tc_listOfColorDefine(tc_listOfColor* _this, tc_listOfColor value);
void tc_listOfColorUpdate(tc_listOfColor* _this, tc_listOfColor value);
void tc_listOfColorSet(tc_listOfColor* _this, tc_listOfColor value);
cx_string tc_listOfColorStr(tc_listOfColor value);
tc_listOfColor* tc_listOfColorFromStr(tc_listOfColor* value, cx_string str);
cx_int16 tc_listOfColorCopy(tc_listOfColor* *dst, tc_listOfColor* src);
cx_int16 tc_listOfColorCompare(tc_listOfColor* dst, tc_listOfColor* src);

cx_int16 tc_listOfColorInit(tc_listOfColor* value);
cx_int16 tc_listOfColorDeinit(tc_listOfColor* value);

/* ::tc_stringser::listOfFloat */
tc_listOfFloat* tc_listOfFloatCreate(void);
tc_listOfFloat* tc_listOfFloatCreateChild(cx_object _parent, cx_string _name);

tc_listOfFloat* tc_listOfFloatDeclare(void);
tc_listOfFloat* tc_listOfFloatDeclareChild(cx_object _parent, cx_string _name);
cx_int16 tc_listOfFloatDefine(tc_listOfFloat* _this, tc_listOfFloat value);
void tc_listOfFloatUpdate(tc_listOfFloat* _this, tc_listOfFloat value);
void tc_listOfFloatSet(tc_listOfFloat* _this, tc_listOfFloat value);
cx_string tc_listOfFloatStr(tc_listOfFloat value);
tc_listOfFloat* tc_listOfFloatFromStr(tc_listOfFloat* value, cx_string str);
cx_int16 tc_listOfFloatCopy(tc_listOfFloat* *dst, tc_listOfFloat* src);
cx_int16 tc_listOfFloatCompare(tc_listOfFloat* dst, tc_listOfFloat* src);

cx_int16 tc_listOfFloatInit(tc_listOfFloat* value);
cx_int16 tc_listOfFloatDeinit(tc_listOfFloat* value);

/* ::tc_stringser::listOfInt */
tc_listOfInt* tc_listOfIntCreate(void);
tc_listOfInt* tc_listOfIntCreateChild(cx_object _parent, cx_string _name);

tc_listOfInt* tc_listOfIntDeclare(void);
tc_listOfInt* tc_listOfIntDeclareChild(cx_object _parent, cx_string _name);
cx_int16 tc_listOfIntDefine(tc_listOfInt* _this, tc_listOfInt value);
void tc_listOfIntUpdate(tc_listOfInt* _this, tc_listOfInt value);
void tc_listOfIntSet(tc_listOfInt* _this, tc_listOfInt value);
cx_string tc_listOfIntStr(tc_listOfInt value);
tc_listOfInt* tc_listOfIntFromStr(tc_listOfInt* value, cx_string str);
cx_int16 tc_listOfIntCopy(tc_listOfInt* *dst, tc_listOfInt* src);
cx_int16 tc_listOfIntCompare(tc_listOfInt* dst, tc_listOfInt* src);

cx_int16 tc_listOfIntInit(tc_listOfInt* value);
cx_int16 tc_listOfIntDeinit(tc_listOfInt* value);

/* ::tc_stringser::listOfMoveMode */
tc_listOfMoveMode* tc_listOfMoveModeCreate(void);
tc_listOfMoveMode* tc_listOfMoveModeCreateChild(cx_object _parent, cx_string _name);

tc_listOfMoveMode* tc_listOfMoveModeDeclare(void);
tc_listOfMoveMode* tc_listOfMoveModeDeclareChild(cx_object _parent, cx_string _name);
cx_int16 tc_listOfMoveModeDefine(tc_listOfMoveMode* _this, tc_listOfMoveMode value);
void tc_listOfMoveModeUpdate(tc_listOfMoveMode* _this, tc_listOfMoveMode value);
void tc_listOfMoveModeSet(tc_listOfMoveMode* _this, tc_listOfMoveMode value);
cx_string tc_listOfMoveModeStr(tc_listOfMoveMode value);
tc_listOfMoveMode* tc_listOfMoveModeFromStr(tc_listOfMoveMode* value, cx_string str);
cx_int16 tc_listOfMoveModeCopy(tc_listOfMoveMode* *dst, tc_listOfMoveMode* src);
cx_int16 tc_listOfMoveModeCompare(tc_listOfMoveMode* dst, tc_listOfMoveMode* src);

cx_int16 tc_listOfMoveModeInit(tc_listOfMoveMode* value);
cx_int16 tc_listOfMoveModeDeinit(tc_listOfMoveMode* value);

/* ::tc_stringser::listOfString */
tc_listOfString* tc_listOfStringCreate(void);
tc_listOfString* tc_listOfStringCreateChild(cx_object _parent, cx_string _name);

tc_listOfString* tc_listOfStringDeclare(void);
tc_listOfString* tc_listOfStringDeclareChild(cx_object _parent, cx_string _name);
cx_int16 tc_listOfStringDefine(tc_listOfString* _this, tc_listOfString value);
void tc_listOfStringUpdate(tc_listOfString* _this, tc_listOfString value);
void tc_listOfStringSet(tc_listOfString* _this, tc_listOfString value);
cx_string tc_listOfStringStr(tc_listOfString value);
tc_listOfString* tc_listOfStringFromStr(tc_listOfString* value, cx_string str);
cx_int16 tc_listOfStringCopy(tc_listOfString* *dst, tc_listOfString* src);
cx_int16 tc_listOfStringCompare(tc_listOfString* dst, tc_listOfString* src);

cx_int16 tc_listOfStringInit(tc_listOfString* value);
cx_int16 tc_listOfStringDeinit(tc_listOfString* value);

/* ::tc_stringser::moveMode */
tc_moveMode* tc_moveModeCreate(void);
tc_moveMode* tc_moveModeCreateChild(cx_object _parent, cx_string _name);

tc_moveMode* tc_moveModeDeclare(void);
tc_moveMode* tc_moveModeDeclareChild(cx_object _parent, cx_string _name);
cx_int16 tc_moveModeDefine(tc_moveMode* _this, tc_moveMode value);
void tc_moveModeUpdate(tc_moveMode* _this, tc_moveMode value);
void tc_moveModeSet(tc_moveMode* _this, tc_moveMode value);
cx_string tc_moveModeStr(tc_moveMode value);
tc_moveMode* tc_moveModeFromStr(tc_moveMode* value, cx_string str);
cx_int16 tc_moveModeCopy(tc_moveMode* *dst, tc_moveMode* src);
cx_int16 tc_moveModeCompare(tc_moveMode* dst, tc_moveMode* src);

cx_int16 tc_moveModeInit(tc_moveMode* value);
cx_int16 tc_moveModeDeinit(tc_moveMode* value);

/* ::tc_stringser::sequenceOfBool */
tc_sequenceOfBool* tc_sequenceOfBoolCreate(void);
tc_sequenceOfBool* tc_sequenceOfBoolCreateChild(cx_object _parent, cx_string _name);

tc_sequenceOfBool* tc_sequenceOfBoolDeclare(void);
tc_sequenceOfBool* tc_sequenceOfBoolDeclareChild(cx_object _parent, cx_string _name);
cx_int16 tc_sequenceOfBoolDefine(tc_sequenceOfBool* _this, tc_sequenceOfBool value);
void tc_sequenceOfBoolUpdate(tc_sequenceOfBool* _this, tc_sequenceOfBool value);
void tc_sequenceOfBoolSet(tc_sequenceOfBool* _this, tc_sequenceOfBool value);
cx_string tc_sequenceOfBoolStr(tc_sequenceOfBool value);
tc_sequenceOfBool* tc_sequenceOfBoolFromStr(tc_sequenceOfBool* value, cx_string str);
cx_int16 tc_sequenceOfBoolCopy(tc_sequenceOfBool* *dst, tc_sequenceOfBool* src);
cx_int16 tc_sequenceOfBoolCompare(tc_sequenceOfBool* dst, tc_sequenceOfBool* src);

cx_int16 tc_sequenceOfBoolInit(tc_sequenceOfBool* value);
cx_int16 tc_sequenceOfBoolDeinit(tc_sequenceOfBool* value);

/* ::tc_stringser::sequenceOfChar */
tc_sequenceOfChar* tc_sequenceOfCharCreate(void);
tc_sequenceOfChar* tc_sequenceOfCharCreateChild(cx_object _parent, cx_string _name);

tc_sequenceOfChar* tc_sequenceOfCharDeclare(void);
tc_sequenceOfChar* tc_sequenceOfCharDeclareChild(cx_object _parent, cx_string _name);
cx_int16 tc_sequenceOfCharDefine(tc_sequenceOfChar* _this, tc_sequenceOfChar value);
void tc_sequenceOfCharUpdate(tc_sequenceOfChar* _this, tc_sequenceOfChar value);
void tc_sequenceOfCharSet(tc_sequenceOfChar* _this, tc_sequenceOfChar value);
cx_string tc_sequenceOfCharStr(tc_sequenceOfChar value);
tc_sequenceOfChar* tc_sequenceOfCharFromStr(tc_sequenceOfChar* value, cx_string str);
cx_int16 tc_sequenceOfCharCopy(tc_sequenceOfChar* *dst, tc_sequenceOfChar* src);
cx_int16 tc_sequenceOfCharCompare(tc_sequenceOfChar* dst, tc_sequenceOfChar* src);

cx_int16 tc_sequenceOfCharInit(tc_sequenceOfChar* value);
cx_int16 tc_sequenceOfCharDeinit(tc_sequenceOfChar* value);

/* ::tc_stringser::sequenceOfClassInherit */
tc_sequenceOfClassInherit* tc_sequenceOfClassInheritCreate(void);
tc_sequenceOfClassInherit* tc_sequenceOfClassInheritCreateChild(cx_object _parent, cx_string _name);

tc_sequenceOfClassInherit* tc_sequenceOfClassInheritDeclare(void);
tc_sequenceOfClassInherit* tc_sequenceOfClassInheritDeclareChild(cx_object _parent, cx_string _name);
cx_int16 tc_sequenceOfClassInheritDefine(tc_sequenceOfClassInherit* _this, tc_sequenceOfClassInherit value);
void tc_sequenceOfClassInheritUpdate(tc_sequenceOfClassInherit* _this, tc_sequenceOfClassInherit value);
void tc_sequenceOfClassInheritSet(tc_sequenceOfClassInherit* _this, tc_sequenceOfClassInherit value);
cx_string tc_sequenceOfClassInheritStr(tc_sequenceOfClassInherit value);
tc_sequenceOfClassInherit* tc_sequenceOfClassInheritFromStr(tc_sequenceOfClassInherit* value, cx_string str);
cx_int16 tc_sequenceOfClassInheritCopy(tc_sequenceOfClassInherit* *dst, tc_sequenceOfClassInherit* src);
cx_int16 tc_sequenceOfClassInheritCompare(tc_sequenceOfClassInherit* dst, tc_sequenceOfClassInherit* src);

cx_int16 tc_sequenceOfClassInheritInit(tc_sequenceOfClassInherit* value);
cx_int16 tc_sequenceOfClassInheritDeinit(tc_sequenceOfClassInherit* value);

/* ::tc_stringser::sequenceOfClassNested */
tc_sequenceOfClassNested* tc_sequenceOfClassNestedCreate(void);
tc_sequenceOfClassNested* tc_sequenceOfClassNestedCreateChild(cx_object _parent, cx_string _name);

tc_sequenceOfClassNested* tc_sequenceOfClassNestedDeclare(void);
tc_sequenceOfClassNested* tc_sequenceOfClassNestedDeclareChild(cx_object _parent, cx_string _name);
cx_int16 tc_sequenceOfClassNestedDefine(tc_sequenceOfClassNested* _this, tc_sequenceOfClassNested value);
void tc_sequenceOfClassNestedUpdate(tc_sequenceOfClassNested* _this, tc_sequenceOfClassNested value);
void tc_sequenceOfClassNestedSet(tc_sequenceOfClassNested* _this, tc_sequenceOfClassNested value);
cx_string tc_sequenceOfClassNestedStr(tc_sequenceOfClassNested value);
tc_sequenceOfClassNested* tc_sequenceOfClassNestedFromStr(tc_sequenceOfClassNested* value, cx_string str);
cx_int16 tc_sequenceOfClassNestedCopy(tc_sequenceOfClassNested* *dst, tc_sequenceOfClassNested* src);
cx_int16 tc_sequenceOfClassNestedCompare(tc_sequenceOfClassNested* dst, tc_sequenceOfClassNested* src);

cx_int16 tc_sequenceOfClassNestedInit(tc_sequenceOfClassNested* value);
cx_int16 tc_sequenceOfClassNestedDeinit(tc_sequenceOfClassNested* value);

/* ::tc_stringser::sequenceOfClassPrimitives */
tc_sequenceOfClassPrimitives* tc_sequenceOfClassPrimitivesCreate(void);
tc_sequenceOfClassPrimitives* tc_sequenceOfClassPrimitivesCreateChild(cx_object _parent, cx_string _name);

tc_sequenceOfClassPrimitives* tc_sequenceOfClassPrimitivesDeclare(void);
tc_sequenceOfClassPrimitives* tc_sequenceOfClassPrimitivesDeclareChild(cx_object _parent, cx_string _name);
cx_int16 tc_sequenceOfClassPrimitivesDefine(tc_sequenceOfClassPrimitives* _this, tc_sequenceOfClassPrimitives value);
void tc_sequenceOfClassPrimitivesUpdate(tc_sequenceOfClassPrimitives* _this, tc_sequenceOfClassPrimitives value);
void tc_sequenceOfClassPrimitivesSet(tc_sequenceOfClassPrimitives* _this, tc_sequenceOfClassPrimitives value);
cx_string tc_sequenceOfClassPrimitivesStr(tc_sequenceOfClassPrimitives value);
tc_sequenceOfClassPrimitives* tc_sequenceOfClassPrimitivesFromStr(tc_sequenceOfClassPrimitives* value, cx_string str);
cx_int16 tc_sequenceOfClassPrimitivesCopy(tc_sequenceOfClassPrimitives* *dst, tc_sequenceOfClassPrimitives* src);
cx_int16 tc_sequenceOfClassPrimitivesCompare(tc_sequenceOfClassPrimitives* dst, tc_sequenceOfClassPrimitives* src);

cx_int16 tc_sequenceOfClassPrimitivesInit(tc_sequenceOfClassPrimitives* value);
cx_int16 tc_sequenceOfClassPrimitivesDeinit(tc_sequenceOfClassPrimitives* value);

/* ::tc_stringser::sequenceOfColor */
tc_sequenceOfColor* tc_sequenceOfColorCreate(void);
tc_sequenceOfColor* tc_sequenceOfColorCreateChild(cx_object _parent, cx_string _name);

tc_sequenceOfColor* tc_sequenceOfColorDeclare(void);
tc_sequenceOfColor* tc_sequenceOfColorDeclareChild(cx_object _parent, cx_string _name);
cx_int16 tc_sequenceOfColorDefine(tc_sequenceOfColor* _this, tc_sequenceOfColor value);
void tc_sequenceOfColorUpdate(tc_sequenceOfColor* _this, tc_sequenceOfColor value);
void tc_sequenceOfColorSet(tc_sequenceOfColor* _this, tc_sequenceOfColor value);
cx_string tc_sequenceOfColorStr(tc_sequenceOfColor value);
tc_sequenceOfColor* tc_sequenceOfColorFromStr(tc_sequenceOfColor* value, cx_string str);
cx_int16 tc_sequenceOfColorCopy(tc_sequenceOfColor* *dst, tc_sequenceOfColor* src);
cx_int16 tc_sequenceOfColorCompare(tc_sequenceOfColor* dst, tc_sequenceOfColor* src);

cx_int16 tc_sequenceOfColorInit(tc_sequenceOfColor* value);
cx_int16 tc_sequenceOfColorDeinit(tc_sequenceOfColor* value);

/* ::tc_stringser::sequenceOfFloat */
tc_sequenceOfFloat* tc_sequenceOfFloatCreate(void);
tc_sequenceOfFloat* tc_sequenceOfFloatCreateChild(cx_object _parent, cx_string _name);

tc_sequenceOfFloat* tc_sequenceOfFloatDeclare(void);
tc_sequenceOfFloat* tc_sequenceOfFloatDeclareChild(cx_object _parent, cx_string _name);
cx_int16 tc_sequenceOfFloatDefine(tc_sequenceOfFloat* _this, tc_sequenceOfFloat value);
void tc_sequenceOfFloatUpdate(tc_sequenceOfFloat* _this, tc_sequenceOfFloat value);
void tc_sequenceOfFloatSet(tc_sequenceOfFloat* _this, tc_sequenceOfFloat value);
cx_string tc_sequenceOfFloatStr(tc_sequenceOfFloat value);
tc_sequenceOfFloat* tc_sequenceOfFloatFromStr(tc_sequenceOfFloat* value, cx_string str);
cx_int16 tc_sequenceOfFloatCopy(tc_sequenceOfFloat* *dst, tc_sequenceOfFloat* src);
cx_int16 tc_sequenceOfFloatCompare(tc_sequenceOfFloat* dst, tc_sequenceOfFloat* src);

cx_int16 tc_sequenceOfFloatInit(tc_sequenceOfFloat* value);
cx_int16 tc_sequenceOfFloatDeinit(tc_sequenceOfFloat* value);

/* ::tc_stringser::sequenceOfInt */
tc_sequenceOfInt* tc_sequenceOfIntCreate(void);
tc_sequenceOfInt* tc_sequenceOfIntCreateChild(cx_object _parent, cx_string _name);

tc_sequenceOfInt* tc_sequenceOfIntDeclare(void);
tc_sequenceOfInt* tc_sequenceOfIntDeclareChild(cx_object _parent, cx_string _name);
cx_int16 tc_sequenceOfIntDefine(tc_sequenceOfInt* _this, tc_sequenceOfInt value);
void tc_sequenceOfIntUpdate(tc_sequenceOfInt* _this, tc_sequenceOfInt value);
void tc_sequenceOfIntSet(tc_sequenceOfInt* _this, tc_sequenceOfInt value);
cx_string tc_sequenceOfIntStr(tc_sequenceOfInt value);
tc_sequenceOfInt* tc_sequenceOfIntFromStr(tc_sequenceOfInt* value, cx_string str);
cx_int16 tc_sequenceOfIntCopy(tc_sequenceOfInt* *dst, tc_sequenceOfInt* src);
cx_int16 tc_sequenceOfIntCompare(tc_sequenceOfInt* dst, tc_sequenceOfInt* src);

cx_int16 tc_sequenceOfIntInit(tc_sequenceOfInt* value);
cx_int16 tc_sequenceOfIntDeinit(tc_sequenceOfInt* value);

/* ::tc_stringser::sequenceOfMoveMode */
tc_sequenceOfMoveMode* tc_sequenceOfMoveModeCreate(void);
tc_sequenceOfMoveMode* tc_sequenceOfMoveModeCreateChild(cx_object _parent, cx_string _name);

tc_sequenceOfMoveMode* tc_sequenceOfMoveModeDeclare(void);
tc_sequenceOfMoveMode* tc_sequenceOfMoveModeDeclareChild(cx_object _parent, cx_string _name);
cx_int16 tc_sequenceOfMoveModeDefine(tc_sequenceOfMoveMode* _this, tc_sequenceOfMoveMode value);
void tc_sequenceOfMoveModeUpdate(tc_sequenceOfMoveMode* _this, tc_sequenceOfMoveMode value);
void tc_sequenceOfMoveModeSet(tc_sequenceOfMoveMode* _this, tc_sequenceOfMoveMode value);
cx_string tc_sequenceOfMoveModeStr(tc_sequenceOfMoveMode value);
tc_sequenceOfMoveMode* tc_sequenceOfMoveModeFromStr(tc_sequenceOfMoveMode* value, cx_string str);
cx_int16 tc_sequenceOfMoveModeCopy(tc_sequenceOfMoveMode* *dst, tc_sequenceOfMoveMode* src);
cx_int16 tc_sequenceOfMoveModeCompare(tc_sequenceOfMoveMode* dst, tc_sequenceOfMoveMode* src);

cx_int16 tc_sequenceOfMoveModeInit(tc_sequenceOfMoveMode* value);
cx_int16 tc_sequenceOfMoveModeDeinit(tc_sequenceOfMoveMode* value);

/* ::tc_stringser::sequenceOfString */
tc_sequenceOfString* tc_sequenceOfStringCreate(void);
tc_sequenceOfString* tc_sequenceOfStringCreateChild(cx_object _parent, cx_string _name);

tc_sequenceOfString* tc_sequenceOfStringDeclare(void);
tc_sequenceOfString* tc_sequenceOfStringDeclareChild(cx_object _parent, cx_string _name);
cx_int16 tc_sequenceOfStringDefine(tc_sequenceOfString* _this, tc_sequenceOfString value);
void tc_sequenceOfStringUpdate(tc_sequenceOfString* _this, tc_sequenceOfString value);
void tc_sequenceOfStringSet(tc_sequenceOfString* _this, tc_sequenceOfString value);
cx_string tc_sequenceOfStringStr(tc_sequenceOfString value);
tc_sequenceOfString* tc_sequenceOfStringFromStr(tc_sequenceOfString* value, cx_string str);
cx_int16 tc_sequenceOfStringCopy(tc_sequenceOfString* *dst, tc_sequenceOfString* src);
cx_int16 tc_sequenceOfStringCompare(tc_sequenceOfString* dst, tc_sequenceOfString* src);

cx_int16 tc_sequenceOfStringInit(tc_sequenceOfString* value);
cx_int16 tc_sequenceOfStringDeinit(tc_sequenceOfString* value);


/* ::tc_stringser::listOfClassInherit */
#define tc_listOfClassInheritForeach(list, elem) \
    cx_iter elem##_iter = cx_llIter(list);\
    tc_classInherit elem;\
    while(cx_iterHasNext(&elem##_iter)) {\
        elem = cx_iterNext(&elem##_iter);

void tc_listOfClassInheritInsert(tc_listOfClassInherit list, tc_classInherit element);
void tc_listOfClassInheritAppend(tc_listOfClassInherit list, tc_classInherit element);
tc_classInherit tc_listOfClassInheritTakeFirst(tc_listOfClassInherit list);
tc_classInherit tc_listOfClassInheritLast(tc_listOfClassInherit list);
void tc_listOfClassInheritClear(tc_listOfClassInherit list);
tc_classInherit tc_listOfClassInheritGet(tc_listOfClassInherit list, cx_uint32 index);
cx_uint32 tc_listOfClassInheritSize(tc_listOfClassInherit list);

/* ::tc_stringser::sequenceOfClassInherit */
#define tc_sequenceOfClassInheritForeach(seq, elem) \
    cx_uint32 elem##_iter;\
    tc_classInherit elem;\
    for(elem##_iter=0; elem##_iter<seq.length; elem##_iter++) {\
        elem = &seq.buffer[elem##_iter];

tc_classInherit tc_sequenceOfClassInheritAppend(tc_sequenceOfClassInherit *seq);
void tc_sequenceOfClassInheritSize(tc_sequenceOfClassInherit *seq, cx_uint32 length);
void tc_sequenceOfClassInheritClear(tc_sequenceOfClassInherit *seq);

/* ::tc_stringser::listOfClassNested */
#define tc_listOfClassNestedForeach(list, elem) \
    cx_iter elem##_iter = cx_llIter(list);\
    tc_classNested elem;\
    while(cx_iterHasNext(&elem##_iter)) {\
        elem = cx_iterNext(&elem##_iter);

void tc_listOfClassNestedInsert(tc_listOfClassNested list, tc_classNested element);
void tc_listOfClassNestedAppend(tc_listOfClassNested list, tc_classNested element);
tc_classNested tc_listOfClassNestedTakeFirst(tc_listOfClassNested list);
tc_classNested tc_listOfClassNestedLast(tc_listOfClassNested list);
void tc_listOfClassNestedClear(tc_listOfClassNested list);
tc_classNested tc_listOfClassNestedGet(tc_listOfClassNested list, cx_uint32 index);
cx_uint32 tc_listOfClassNestedSize(tc_listOfClassNested list);

/* ::tc_stringser::sequenceOfClassNested */
#define tc_sequenceOfClassNestedForeach(seq, elem) \
    cx_uint32 elem##_iter;\
    tc_classNested elem;\
    for(elem##_iter=0; elem##_iter<seq.length; elem##_iter++) {\
        elem = &seq.buffer[elem##_iter];

tc_classNested tc_sequenceOfClassNestedAppend(tc_sequenceOfClassNested *seq);
void tc_sequenceOfClassNestedSize(tc_sequenceOfClassNested *seq, cx_uint32 length);
void tc_sequenceOfClassNestedClear(tc_sequenceOfClassNested *seq);

/* ::tc_stringser::listOfClassPrimitives */
#define tc_listOfClassPrimitivesForeach(list, elem) \
    cx_iter elem##_iter = cx_llIter(list);\
    tc_classPrimitives elem;\
    while(cx_iterHasNext(&elem##_iter)) {\
        elem = cx_iterNext(&elem##_iter);

void tc_listOfClassPrimitivesInsert(tc_listOfClassPrimitives list, tc_classPrimitives element);
void tc_listOfClassPrimitivesAppend(tc_listOfClassPrimitives list, tc_classPrimitives element);
tc_classPrimitives tc_listOfClassPrimitivesTakeFirst(tc_listOfClassPrimitives list);
tc_classPrimitives tc_listOfClassPrimitivesLast(tc_listOfClassPrimitives list);
void tc_listOfClassPrimitivesClear(tc_listOfClassPrimitives list);
tc_classPrimitives tc_listOfClassPrimitivesGet(tc_listOfClassPrimitives list, cx_uint32 index);
cx_uint32 tc_listOfClassPrimitivesSize(tc_listOfClassPrimitives list);

/* ::tc_stringser::sequenceOfClassPrimitives */
#define tc_sequenceOfClassPrimitivesForeach(seq, elem) \
    cx_uint32 elem##_iter;\
    tc_classPrimitives elem;\
    for(elem##_iter=0; elem##_iter<seq.length; elem##_iter++) {\
        elem = &seq.buffer[elem##_iter];

tc_classPrimitives tc_sequenceOfClassPrimitivesAppend(tc_sequenceOfClassPrimitives *seq);
void tc_sequenceOfClassPrimitivesSize(tc_sequenceOfClassPrimitives *seq, cx_uint32 length);
void tc_sequenceOfClassPrimitivesClear(tc_sequenceOfClassPrimitives *seq);

/* ::tc_stringser::listOfColor */
#define tc_listOfColorForeach(list, elem) \
    cx_iter elem##_iter = cx_llIter(list);\
    tc_color *elem;\
    while(cx_iterHasNext(&elem##_iter)) {\
        elem = cx_iterNext(&elem##_iter);

void tc_listOfColorInsert(tc_listOfColor list, tc_color element);
void tc_listOfColorAppend(tc_listOfColor list, tc_color element);
tc_color tc_listOfColorTakeFirst(tc_listOfColor list);
tc_color tc_listOfColorLast(tc_listOfColor list);
void tc_listOfColorClear(tc_listOfColor list);
tc_color tc_listOfColorGet(tc_listOfColor list, cx_uint32 index);
cx_uint32 tc_listOfColorSize(tc_listOfColor list);

/* ::tc_stringser::sequenceOfColor */
#define tc_sequenceOfColorForeach(seq, elem) \
    cx_uint32 elem##_iter;\
    tc_color *elem;\
    for(elem##_iter=0; elem##_iter<seq.length; elem##_iter++) {\
        elem = &seq.buffer[elem##_iter];

tc_color* tc_sequenceOfColorAppend(tc_sequenceOfColor *seq);
void tc_sequenceOfColorSize(tc_sequenceOfColor *seq, cx_uint32 length);
void tc_sequenceOfColorClear(tc_sequenceOfColor *seq);

/* ::tc_stringser::listOfBool */
#define tc_listOfBoolForeach(list, elem) \
    cx_iter elem##_iter = cx_llIter(list);\
    cx_bool *elem;\
    while(cx_iterHasNext(&elem##_iter)) {\
        elem = cx_iterNext(&elem##_iter);

void tc_listOfBoolInsert(tc_listOfBool list, cx_bool element);
void tc_listOfBoolAppend(tc_listOfBool list, cx_bool element);
cx_bool tc_listOfBoolTakeFirst(tc_listOfBool list);
cx_bool tc_listOfBoolLast(tc_listOfBool list);
void tc_listOfBoolClear(tc_listOfBool list);
cx_bool tc_listOfBoolGet(tc_listOfBool list, cx_uint32 index);
cx_uint32 tc_listOfBoolSize(tc_listOfBool list);

/* ::tc_stringser::listOfChar */
#define tc_listOfCharForeach(list, elem) \
    cx_iter elem##_iter = cx_llIter(list);\
    cx_char *elem;\
    while(cx_iterHasNext(&elem##_iter)) {\
        elem = cx_iterNext(&elem##_iter);

void tc_listOfCharInsert(tc_listOfChar list, cx_char element);
void tc_listOfCharAppend(tc_listOfChar list, cx_char element);
cx_char tc_listOfCharTakeFirst(tc_listOfChar list);
cx_char tc_listOfCharLast(tc_listOfChar list);
void tc_listOfCharClear(tc_listOfChar list);
cx_char tc_listOfCharGet(tc_listOfChar list, cx_uint32 index);
cx_uint32 tc_listOfCharSize(tc_listOfChar list);

/* ::tc_stringser::listOfFloat */
#define tc_listOfFloatForeach(list, elem) \
    cx_iter elem##_iter = cx_llIter(list);\
    cx_float32 *elem;\
    while(cx_iterHasNext(&elem##_iter)) {\
        elem = cx_iterNext(&elem##_iter);

void tc_listOfFloatInsert(tc_listOfFloat list, cx_float32 element);
void tc_listOfFloatAppend(tc_listOfFloat list, cx_float32 element);
cx_float32 tc_listOfFloatTakeFirst(tc_listOfFloat list);
cx_float32 tc_listOfFloatLast(tc_listOfFloat list);
void tc_listOfFloatClear(tc_listOfFloat list);
cx_float32 tc_listOfFloatGet(tc_listOfFloat list, cx_uint32 index);
cx_uint32 tc_listOfFloatSize(tc_listOfFloat list);

/* ::tc_stringser::listOfInt */
#define tc_listOfIntForeach(list, elem) \
    cx_iter elem##_iter = cx_llIter(list);\
    cx_int32 *elem;\
    while(cx_iterHasNext(&elem##_iter)) {\
        elem = cx_iterNext(&elem##_iter);

void tc_listOfIntInsert(tc_listOfInt list, cx_int32 element);
void tc_listOfIntAppend(tc_listOfInt list, cx_int32 element);
cx_int32 tc_listOfIntTakeFirst(tc_listOfInt list);
cx_int32 tc_listOfIntLast(tc_listOfInt list);
void tc_listOfIntClear(tc_listOfInt list);
cx_int32 tc_listOfIntGet(tc_listOfInt list, cx_uint32 index);
cx_uint32 tc_listOfIntSize(tc_listOfInt list);

/* ::tc_stringser::listOfMoveMode */
#define tc_listOfMoveModeForeach(list, elem) \
    cx_iter elem##_iter = cx_llIter(list);\
    tc_moveMode *elem;\
    while(cx_iterHasNext(&elem##_iter)) {\
        elem = cx_iterNext(&elem##_iter);

void tc_listOfMoveModeInsert(tc_listOfMoveMode list, tc_moveMode element);
void tc_listOfMoveModeAppend(tc_listOfMoveMode list, tc_moveMode element);
tc_moveMode tc_listOfMoveModeTakeFirst(tc_listOfMoveMode list);
tc_moveMode tc_listOfMoveModeLast(tc_listOfMoveMode list);
void tc_listOfMoveModeClear(tc_listOfMoveMode list);
tc_moveMode tc_listOfMoveModeGet(tc_listOfMoveMode list, cx_uint32 index);
cx_uint32 tc_listOfMoveModeSize(tc_listOfMoveMode list);

/* ::tc_stringser::listOfString */
#define tc_listOfStringForeach(list, elem) \
    cx_iter elem##_iter = cx_llIter(list);\
    cx_string *elem;\
    while(cx_iterHasNext(&elem##_iter)) {\
        elem = cx_iterNext(&elem##_iter);

void tc_listOfStringInsert(tc_listOfString list, cx_string element);
void tc_listOfStringAppend(tc_listOfString list, cx_string element);
cx_string tc_listOfStringTakeFirst(tc_listOfString list);
cx_string tc_listOfStringLast(tc_listOfString list);
void tc_listOfStringClear(tc_listOfString list);
cx_string tc_listOfStringGet(tc_listOfString list, cx_uint32 index);
cx_uint32 tc_listOfStringSize(tc_listOfString list);

/* ::tc_stringser::sequenceOfMoveMode */
#define tc_sequenceOfMoveModeForeach(seq, elem) \
    cx_uint32 elem##_iter;\
    tc_moveMode *elem;\
    for(elem##_iter=0; elem##_iter<seq.length; elem##_iter++) {\
        elem = &seq.buffer[elem##_iter];

tc_moveMode* tc_sequenceOfMoveModeAppend(tc_sequenceOfMoveMode *seq);
void tc_sequenceOfMoveModeSize(tc_sequenceOfMoveMode *seq, cx_uint32 length);
void tc_sequenceOfMoveModeClear(tc_sequenceOfMoveMode *seq);

/* ::tc_stringser::sequenceOfBool */
#define tc_sequenceOfBoolForeach(seq, elem) \
    cx_uint32 elem##_iter;\
    cx_bool *elem;\
    for(elem##_iter=0; elem##_iter<seq.length; elem##_iter++) {\
        elem = &seq.buffer[elem##_iter];

cx_bool* tc_sequenceOfBoolAppend(tc_sequenceOfBool *seq);
void tc_sequenceOfBoolSize(tc_sequenceOfBool *seq, cx_uint32 length);
void tc_sequenceOfBoolClear(tc_sequenceOfBool *seq);

/* ::tc_stringser::sequenceOfChar */
#define tc_sequenceOfCharForeach(seq, elem) \
    cx_uint32 elem##_iter;\
    cx_char *elem;\
    for(elem##_iter=0; elem##_iter<seq.length; elem##_iter++) {\
        elem = &seq.buffer[elem##_iter];

cx_char* tc_sequenceOfCharAppend(tc_sequenceOfChar *seq);
void tc_sequenceOfCharSize(tc_sequenceOfChar *seq, cx_uint32 length);
void tc_sequenceOfCharClear(tc_sequenceOfChar *seq);

/* ::tc_stringser::sequenceOfFloat */
#define tc_sequenceOfFloatForeach(seq, elem) \
    cx_uint32 elem##_iter;\
    cx_float32 *elem;\
    for(elem##_iter=0; elem##_iter<seq.length; elem##_iter++) {\
        elem = &seq.buffer[elem##_iter];

cx_float32* tc_sequenceOfFloatAppend(tc_sequenceOfFloat *seq);
void tc_sequenceOfFloatSize(tc_sequenceOfFloat *seq, cx_uint32 length);
void tc_sequenceOfFloatClear(tc_sequenceOfFloat *seq);

/* ::tc_stringser::sequenceOfInt */
#define tc_sequenceOfIntForeach(seq, elem) \
    cx_uint32 elem##_iter;\
    cx_int32 *elem;\
    for(elem##_iter=0; elem##_iter<seq.length; elem##_iter++) {\
        elem = &seq.buffer[elem##_iter];

cx_int32* tc_sequenceOfIntAppend(tc_sequenceOfInt *seq);
void tc_sequenceOfIntSize(tc_sequenceOfInt *seq, cx_uint32 length);
void tc_sequenceOfIntClear(tc_sequenceOfInt *seq);

/* ::tc_stringser::sequenceOfString */
#define tc_sequenceOfStringForeach(seq, elem) \
    cx_uint32 elem##_iter;\
    cx_string *elem;\
    for(elem##_iter=0; elem##_iter<seq.length; elem##_iter++) {\
        elem = &seq.buffer[elem##_iter];

cx_string* tc_sequenceOfStringAppend(tc_sequenceOfString *seq);
void tc_sequenceOfStringSize(tc_sequenceOfString *seq, cx_uint32 length);
void tc_sequenceOfStringClear(tc_sequenceOfString *seq);

#ifdef __cplusplus
}
#endif
#endif

