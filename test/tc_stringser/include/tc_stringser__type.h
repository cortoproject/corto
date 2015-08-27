/* tc_stringser__type.h
 *
 *    Type-definitions for C-language.
 *    This file contains generated code. Do not modify!
 */

#ifndef tc_stringser__type_H
#define tc_stringser__type_H

#include "corto.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Casting macro's for classes */
#define tc_stringser_classCompositeCollection(o) ((tc_stringser_classCompositeCollection)o)
#define tc_stringser_classInherit(o) ((tc_stringser_classInherit)o)
#define tc_stringser_classNested(o) ((tc_stringser_classNested)o)
#define tc_stringser_classPrimitives(o) ((tc_stringser_classPrimitives)o)

/* Type definitions */
typedef cx_bool tc_stringser_arrayOfBool[3];

typedef cx_char tc_stringser_arrayOfChar[3];

/* ::tc_stringser::color */
typedef enum tc_stringser_color {
    TC_STRINGSER_RED = 0,
    TC_STRINGSER_YELLOW = 1,
    TC_STRINGSER_BLUE = 2
} tc_stringser_color;

/* ::tc_stringser::moveMode */
CX_BITMASK(tc_stringser_moveMode);
    #define TC_STRINGSER_WALK (0x1)
    #define TC_STRINGSER_SWIM (0x2)
    #define TC_STRINGSER_FLY (0x4)

/*  ::tc_stringser::classPrimitives */
CX_CLASS(tc_stringser_classPrimitives);

CX_CLASS_DEF(tc_stringser_classPrimitives) {
    cx_bool a;
    cx_char b;
    cx_int32 c;
    cx_float32 d;
    cx_string e;
    tc_stringser_color f;
    tc_stringser_moveMode g;
};

/*  ::tc_stringser::classInherit */
CX_CLASS(tc_stringser_classInherit);

CX_CLASS_DEF(tc_stringser_classInherit) {
    CX_EXTEND(tc_stringser_classPrimitives);
    cx_bool a;
    cx_char b;
    cx_int32 c;
    cx_float32 d;
    cx_string e;
    tc_stringser_color f;
    tc_stringser_moveMode g;
};

typedef tc_stringser_classInherit tc_stringser_arrayOfClassInherit[3];

typedef cx_int32 tc_stringser_arrayOfInt[3];

CX_SEQUENCE(tc_stringser_sequenceOfInt, cx_int32,);

CX_LIST(tc_stringser_listOfInt);

/*  ::tc_stringser::classNested */
CX_CLASS(tc_stringser_classNested);

CX_CLASS_DEF(tc_stringser_classNested) {
    tc_stringser_classPrimitives a;
    tc_stringser_classInherit b;
    tc_stringser_arrayOfInt c;
    tc_stringser_sequenceOfInt d;
    tc_stringser_listOfInt e;
};

typedef tc_stringser_classNested tc_stringser_arrayOfClassNested[3];

typedef tc_stringser_classPrimitives tc_stringser_arrayOfClassPrimitives[3];

typedef tc_stringser_color tc_stringser_arrayOfColor[3];

typedef cx_float32 tc_stringser_arrayOfFloat[3];

typedef tc_stringser_moveMode tc_stringser_arrayOfMoveMode[3];

typedef cx_string tc_stringser_arrayOfString[3];

CX_SEQUENCE(tc_stringser_sequenceOfClassInherit, tc_stringser_classInherit,);

CX_LIST(tc_stringser_listOfClassNested);

CX_LIST(tc_stringser_listOfClassInherit);

/*  ::tc_stringser::classCompositeCollection */
CX_CLASS(tc_stringser_classCompositeCollection);

CX_CLASS_DEF(tc_stringser_classCompositeCollection) {
    tc_stringser_arrayOfClassInherit a;
    tc_stringser_arrayOfClassNested b;
    tc_stringser_sequenceOfClassInherit c;
    tc_stringser_listOfClassNested d;
    tc_stringser_listOfClassInherit e;
};

CX_LIST(tc_stringser_listOfBool);

CX_LIST(tc_stringser_listOfChar);

CX_LIST(tc_stringser_listOfClassPrimitives);

CX_LIST(tc_stringser_listOfColor);

CX_LIST(tc_stringser_listOfFloat);

CX_LIST(tc_stringser_listOfMoveMode);

CX_LIST(tc_stringser_listOfString);

CX_SEQUENCE(tc_stringser_sequenceOfBool, cx_bool,);

CX_SEQUENCE(tc_stringser_sequenceOfChar, cx_char,);

CX_SEQUENCE(tc_stringser_sequenceOfClassNested, tc_stringser_classNested,);

CX_SEQUENCE(tc_stringser_sequenceOfClassPrimitives, tc_stringser_classPrimitives,);

CX_SEQUENCE(tc_stringser_sequenceOfColor, tc_stringser_color,);

CX_SEQUENCE(tc_stringser_sequenceOfFloat, cx_float32,);

CX_SEQUENCE(tc_stringser_sequenceOfMoveMode, tc_stringser_moveMode,);

CX_SEQUENCE(tc_stringser_sequenceOfString, cx_string,);

#ifdef __cplusplus
}
#endif
#endif

