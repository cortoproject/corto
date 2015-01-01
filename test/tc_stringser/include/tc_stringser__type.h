/* tc_stringser__type.h
 *
 *  Generated on Feb  5 2014
 *    Type-definitions for C-language.
 *    This file contains generated code. Do not modify!
 */

#ifndef tc_stringser__type_H
#define tc_stringser__type_H

#include "cortex.h"
#ifdef __cplusplus
extern "C" {
#endif

/* Casting macro's for classes */
#define tc_classCompositeCollection(o) ((tc_classCompositeCollection)o)
#define tc_classInherit(o) ((tc_classInherit)o)
#define tc_classNested(o) ((tc_classNested)o)
#define tc_classPrimitives(o) ((tc_classPrimitives)o)

/* Type definitions */

typedef cx_bool cx_bool_array3[3];
typedef cx_bool_array3 tc_arrayOfBool;
typedef cx_char cx_char_array3[3];
typedef cx_char_array3 tc_arrayOfChar;
/* ::tc_stringser::color */
typedef enum tc_color {
    TC_RED = 0,
    TC_YELLOW = 1,
    TC_BLUE = 2
} tc_color;
/* ::tc_stringser::moveMode */
DB_BITMASK(tc_moveMode);
#define TC_WALK (0x1)
#define TC_SWIM (0x2)
#define TC_FLY (0x4)

/*  ::tc_stringser::classPrimitives */
DB_CLASS(tc_classPrimitives);
DB_CLASS_DEF(tc_classPrimitives) {
    cx_bool a;
    cx_char b;
    cx_int32 c;
    cx_float32 d;
    cx_string e;
    tc_color f;
    tc_moveMode g;
};

/*  ::tc_stringser::classInherit */
DB_CLASS(tc_classInherit);
DB_CLASS_DEF(tc_classInherit) {
    DB_EXTEND(tc_classPrimitives);
    cx_bool a;
    cx_char b;
    cx_int32 c;
    cx_float32 d;
    cx_string e;
    tc_color f;
    tc_moveMode g;
};
typedef tc_classInherit tc_classInherit_array3[3];
typedef tc_classInherit_array3 tc_arrayOfClassInherit;
typedef cx_int32 cx_int32_array3[3];
typedef cx_int32_array3 tc_arrayOfInt;
DB_SEQUENCE(cx_int32_seq3, cx_int32,);
typedef cx_int32_seq3 tc_sequenceOfInt;
DB_LIST(cx_int32_list3);
typedef cx_int32_list3 tc_listOfInt;

/*  ::tc_stringser::classNested */
DB_CLASS(tc_classNested);
DB_CLASS_DEF(tc_classNested) {
    tc_classPrimitives a;
    tc_classInherit b;
    tc_arrayOfInt c;
    tc_sequenceOfInt d;
    tc_listOfInt e;
};
typedef tc_classNested tc_classNested_array3[3];
typedef tc_classNested_array3 tc_arrayOfClassNested;
typedef tc_classPrimitives tc_classPrimitives_array3[3];
typedef tc_classPrimitives_array3 tc_arrayOfClassPrimitives;
typedef tc_color tc_color_array3[3];
typedef tc_color_array3 tc_arrayOfColor;
typedef cx_float32 cx_float32_array3[3];
typedef cx_float32_array3 tc_arrayOfFloat;
typedef tc_moveMode tc_moveMode_array3[3];
typedef tc_moveMode_array3 tc_arrayOfMoveMode;
typedef cx_string cx_string_array3[3];
typedef cx_string_array3 tc_arrayOfString;
DB_SEQUENCE(tc_classInherit_seq3, tc_classInherit,);
typedef tc_classInherit_seq3 tc_sequenceOfClassInherit;
DB_LIST(tc_classNested_list3);
typedef tc_classNested_list3 tc_listOfClassNested;
DB_LIST(tc_classInherit_list3);
typedef tc_classInherit_list3 tc_listOfClassInherit;

/*  ::tc_stringser::classCompositeCollection */
DB_CLASS(tc_classCompositeCollection);
DB_CLASS_DEF(tc_classCompositeCollection) {
    tc_arrayOfClassInherit a;
    tc_arrayOfClassNested b;
    tc_sequenceOfClassInherit c;
    tc_listOfClassNested d;
    tc_listOfClassInherit e;
};
DB_LIST(cx_bool_list3);
typedef cx_bool_list3 tc_listOfBool;
DB_LIST(cx_char_list3);
typedef cx_char_list3 tc_listOfChar;
DB_LIST(tc_classPrimitives_list3);
typedef tc_classPrimitives_list3 tc_listOfClassPrimitives;
DB_LIST(tc_color_list3);
typedef tc_color_list3 tc_listOfColor;
DB_LIST(cx_float32_list3);
typedef cx_float32_list3 tc_listOfFloat;
DB_LIST(tc_moveMode_list3);
typedef tc_moveMode_list3 tc_listOfMoveMode;
DB_LIST(cx_string_list3);
typedef cx_string_list3 tc_listOfString;
DB_SEQUENCE(cx_bool_seq3, cx_bool,);
typedef cx_bool_seq3 tc_sequenceOfBool;
DB_SEQUENCE(cx_char_seq3, cx_char,);
typedef cx_char_seq3 tc_sequenceOfChar;
DB_SEQUENCE(tc_classNested_seq3, tc_classNested,);
typedef tc_classNested_seq3 tc_sequenceOfClassNested;
DB_SEQUENCE(tc_classPrimitives_seq3, tc_classPrimitives,);
typedef tc_classPrimitives_seq3 tc_sequenceOfClassPrimitives;
DB_SEQUENCE(tc_color_seq3, tc_color,);
typedef tc_color_seq3 tc_sequenceOfColor;
DB_SEQUENCE(cx_float32_seq3, cx_float32,);
typedef cx_float32_seq3 tc_sequenceOfFloat;
DB_SEQUENCE(tc_moveMode_seq3, tc_moveMode,);
typedef tc_moveMode_seq3 tc_sequenceOfMoveMode;
DB_SEQUENCE(cx_string_seq3, cx_string,);
typedef cx_string_seq3 tc_sequenceOfString;

#ifdef __cplusplus
}
#endif
#endif

