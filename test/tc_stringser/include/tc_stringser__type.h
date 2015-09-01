/* tc_stringser__type.h
 *
 * Type definitions for C-language.
 * This file contains generated code. Do not modify!
 */

#ifndef tc_stringser__type_H
#define tc_stringser__type_H

#include "corto.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Casting macro's for classes */
#define tc_arrayOfBool(o) ((tc_arrayOfBool *)cx_assertType((cx_type)tc_arrayOfBool_o, o))
#define tc_arrayOfChar(o) ((tc_arrayOfChar *)cx_assertType((cx_type)tc_arrayOfChar_o, o))
#define tc_arrayOfClassInherit(o) ((tc_arrayOfClassInherit *)cx_assertType((cx_type)tc_arrayOfClassInherit_o, o))
#define tc_arrayOfClassNested(o) ((tc_arrayOfClassNested *)cx_assertType((cx_type)tc_arrayOfClassNested_o, o))
#define tc_arrayOfClassPrimitives(o) ((tc_arrayOfClassPrimitives *)cx_assertType((cx_type)tc_arrayOfClassPrimitives_o, o))
#define tc_arrayOfColor(o) ((tc_arrayOfColor *)cx_assertType((cx_type)tc_arrayOfColor_o, o))
#define tc_arrayOfFloat(o) ((tc_arrayOfFloat *)cx_assertType((cx_type)tc_arrayOfFloat_o, o))
#define tc_arrayOfInt(o) ((tc_arrayOfInt *)cx_assertType((cx_type)tc_arrayOfInt_o, o))
#define tc_arrayOfMoveMode(o) ((tc_arrayOfMoveMode *)cx_assertType((cx_type)tc_arrayOfMoveMode_o, o))
#define tc_arrayOfString(o) ((tc_arrayOfString *)cx_assertType((cx_type)tc_arrayOfString_o, o))
#define tc_classCompositeCollection(o) ((tc_classCompositeCollection)cx_assertType((cx_type)tc_classCompositeCollection_o, o))
#define tc_classInherit(o) ((tc_classInherit)cx_assertType((cx_type)tc_classInherit_o, o))
#define tc_classNested(o) ((tc_classNested)cx_assertType((cx_type)tc_classNested_o, o))
#define tc_classPrimitives(o) ((tc_classPrimitives)cx_assertType((cx_type)tc_classPrimitives_o, o))
#define tc_color(o) ((tc_color *)cx_assertType((cx_type)tc_color_o, o))
#define tc_listOfBool(o) ((tc_listOfBool *)cx_assertType((cx_type)tc_listOfBool_o, o))
#define tc_listOfChar(o) ((tc_listOfChar *)cx_assertType((cx_type)tc_listOfChar_o, o))
#define tc_listOfClassInherit(o) ((tc_listOfClassInherit *)cx_assertType((cx_type)tc_listOfClassInherit_o, o))
#define tc_listOfClassNested(o) ((tc_listOfClassNested *)cx_assertType((cx_type)tc_listOfClassNested_o, o))
#define tc_listOfClassPrimitives(o) ((tc_listOfClassPrimitives *)cx_assertType((cx_type)tc_listOfClassPrimitives_o, o))
#define tc_listOfColor(o) ((tc_listOfColor *)cx_assertType((cx_type)tc_listOfColor_o, o))
#define tc_listOfFloat(o) ((tc_listOfFloat *)cx_assertType((cx_type)tc_listOfFloat_o, o))
#define tc_listOfInt(o) ((tc_listOfInt *)cx_assertType((cx_type)tc_listOfInt_o, o))
#define tc_listOfMoveMode(o) ((tc_listOfMoveMode *)cx_assertType((cx_type)tc_listOfMoveMode_o, o))
#define tc_listOfString(o) ((tc_listOfString *)cx_assertType((cx_type)tc_listOfString_o, o))
#define tc_moveMode(o) ((tc_moveMode *)cx_assertType((cx_type)tc_moveMode_o, o))
#define tc_sequenceOfBool(o) ((tc_sequenceOfBool *)cx_assertType((cx_type)tc_sequenceOfBool_o, o))
#define tc_sequenceOfChar(o) ((tc_sequenceOfChar *)cx_assertType((cx_type)tc_sequenceOfChar_o, o))
#define tc_sequenceOfClassInherit(o) ((tc_sequenceOfClassInherit *)cx_assertType((cx_type)tc_sequenceOfClassInherit_o, o))
#define tc_sequenceOfClassNested(o) ((tc_sequenceOfClassNested *)cx_assertType((cx_type)tc_sequenceOfClassNested_o, o))
#define tc_sequenceOfClassPrimitives(o) ((tc_sequenceOfClassPrimitives *)cx_assertType((cx_type)tc_sequenceOfClassPrimitives_o, o))
#define tc_sequenceOfColor(o) ((tc_sequenceOfColor *)cx_assertType((cx_type)tc_sequenceOfColor_o, o))
#define tc_sequenceOfFloat(o) ((tc_sequenceOfFloat *)cx_assertType((cx_type)tc_sequenceOfFloat_o, o))
#define tc_sequenceOfInt(o) ((tc_sequenceOfInt *)cx_assertType((cx_type)tc_sequenceOfInt_o, o))
#define tc_sequenceOfMoveMode(o) ((tc_sequenceOfMoveMode *)cx_assertType((cx_type)tc_sequenceOfMoveMode_o, o))
#define tc_sequenceOfString(o) ((tc_sequenceOfString *)cx_assertType((cx_type)tc_sequenceOfString_o, o))

/* Type definitions */
typedef cx_bool tc_arrayOfBool[3];

typedef cx_char tc_arrayOfChar[3];

/* ::tc_stringser::color */
typedef enum tc_color {
    TC_RED = 0,
    TC_YELLOW = 1,
    TC_BLUE = 2
} tc_color;

/* ::tc_stringser::moveMode */
CX_BITMASK(tc_moveMode);
    #define TC_WALK (0x1)
    #define TC_SWIM (0x2)
    #define TC_FLY (0x4)

/*  ::tc_stringser::classPrimitives */
CX_CLASS(tc_classPrimitives);

CX_CLASS_DEF(tc_classPrimitives) {
    cx_bool a;
    cx_char b;
    cx_int32 c;
    cx_float32 d;
    cx_string e;
    tc_color f;
    tc_moveMode g;
};

/*  ::tc_stringser::classInherit */
CX_CLASS(tc_classInherit);

CX_CLASS_DEF(tc_classInherit) {
    CX_EXTEND(tc_classPrimitives);
    cx_bool a;
    cx_char b;
    cx_int32 c;
    cx_float32 d;
    cx_string e;
    tc_color f;
    tc_moveMode g;
};

typedef tc_classInherit tc_arrayOfClassInherit[3];

typedef cx_int32 tc_arrayOfInt[3];

CX_SEQUENCE(tc_sequenceOfInt, cx_int32,);

CX_LIST(tc_listOfInt);

/*  ::tc_stringser::classNested */
CX_CLASS(tc_classNested);

CX_CLASS_DEF(tc_classNested) {
    tc_classPrimitives a;
    tc_classInherit b;
    tc_arrayOfInt c;
    tc_sequenceOfInt d;
    tc_listOfInt e;
};

typedef tc_classNested tc_arrayOfClassNested[3];

typedef tc_classPrimitives tc_arrayOfClassPrimitives[3];

typedef tc_color tc_arrayOfColor[3];

typedef cx_float32 tc_arrayOfFloat[3];

typedef tc_moveMode tc_arrayOfMoveMode[3];

typedef cx_string tc_arrayOfString[3];

CX_SEQUENCE(tc_sequenceOfClassInherit, tc_classInherit,);

CX_SEQUENCE(tc_sequenceOfClassNested, tc_classNested,);

CX_LIST(tc_listOfClassInherit);

CX_LIST(tc_listOfClassNested);

/*  ::tc_stringser::classCompositeCollection */
CX_CLASS(tc_classCompositeCollection);

CX_CLASS_DEF(tc_classCompositeCollection) {
    tc_arrayOfClassInherit a;
    tc_arrayOfClassNested b;
    tc_sequenceOfClassInherit c;
    tc_sequenceOfClassNested d;
    tc_listOfClassInherit e;
    tc_listOfClassNested f;
};

CX_LIST(tc_listOfBool);

CX_LIST(tc_listOfChar);

CX_LIST(tc_listOfClassPrimitives);

CX_LIST(tc_listOfColor);

CX_LIST(tc_listOfFloat);

CX_LIST(tc_listOfMoveMode);

CX_LIST(tc_listOfString);

CX_SEQUENCE(tc_sequenceOfBool, cx_bool,);

CX_SEQUENCE(tc_sequenceOfChar, cx_char,);

CX_SEQUENCE(tc_sequenceOfClassPrimitives, tc_classPrimitives,);

CX_SEQUENCE(tc_sequenceOfColor, tc_color,);

CX_SEQUENCE(tc_sequenceOfFloat, cx_float32,);

CX_SEQUENCE(tc_sequenceOfMoveMode, tc_moveMode,);

CX_SEQUENCE(tc_sequenceOfString, cx_string,);

#ifdef __cplusplus
}
#endif
#endif

