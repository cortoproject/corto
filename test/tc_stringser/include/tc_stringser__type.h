/* tc_stringser__type.h
 *
 *  Generated on Feb  5 2014
 *    Type-definitions for C-language.
 *    This file contains generated code. Do not modify!
 */

#ifndef tc_stringser__type_H
#define tc_stringser__type_H

#include "hyve.h"
#ifdef __cplusplus
extern "C" {
#endif

/* Casting macro's for classes */
#define tc_classCompositeCollection(o) ((tc_classCompositeCollection)o)
#define tc_classInherit(o) ((tc_classInherit)o)
#define tc_classNested(o) ((tc_classNested)o)
#define tc_classPrimitives(o) ((tc_classPrimitives)o)

/* Type definitions */

typedef db_bool db_bool_array3[3];
typedef db_bool_array3 tc_arrayOfBool;
typedef db_char db_char_array3[3];
typedef db_char_array3 tc_arrayOfChar;
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
    db_bool a;
    db_char b;
    db_int32 c;
    db_float32 d;
    db_string e;
    tc_color f;
    tc_moveMode g;
};

/*  ::tc_stringser::classInherit */
DB_CLASS(tc_classInherit);
DB_CLASS_DEF(tc_classInherit) {
    DB_EXTEND(tc_classPrimitives);
    db_bool a;
    db_char b;
    db_int32 c;
    db_float32 d;
    db_string e;
    tc_color f;
    tc_moveMode g;
};
typedef tc_classInherit tc_classInherit_array3[3];
typedef tc_classInherit_array3 tc_arrayOfClassInherit;
typedef db_int32 db_int32_array3[3];
typedef db_int32_array3 tc_arrayOfInt;
DB_SEQUENCE(db_int32_seq3, db_int32,);
typedef db_int32_seq3 tc_sequenceOfInt;
DB_LIST(db_int32_list3);
typedef db_int32_list3 tc_listOfInt;

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
typedef db_float32 db_float32_array3[3];
typedef db_float32_array3 tc_arrayOfFloat;
typedef tc_moveMode tc_moveMode_array3[3];
typedef tc_moveMode_array3 tc_arrayOfMoveMode;
typedef db_string db_string_array3[3];
typedef db_string_array3 tc_arrayOfString;
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
DB_LIST(db_bool_list3);
typedef db_bool_list3 tc_listOfBool;
DB_LIST(db_char_list3);
typedef db_char_list3 tc_listOfChar;
DB_LIST(tc_classPrimitives_list3);
typedef tc_classPrimitives_list3 tc_listOfClassPrimitives;
DB_LIST(tc_color_list3);
typedef tc_color_list3 tc_listOfColor;
DB_LIST(db_float32_list3);
typedef db_float32_list3 tc_listOfFloat;
DB_LIST(tc_moveMode_list3);
typedef tc_moveMode_list3 tc_listOfMoveMode;
DB_LIST(db_string_list3);
typedef db_string_list3 tc_listOfString;
DB_SEQUENCE(db_bool_seq3, db_bool,);
typedef db_bool_seq3 tc_sequenceOfBool;
DB_SEQUENCE(db_char_seq3, db_char,);
typedef db_char_seq3 tc_sequenceOfChar;
DB_SEQUENCE(tc_classNested_seq3, tc_classNested,);
typedef tc_classNested_seq3 tc_sequenceOfClassNested;
DB_SEQUENCE(tc_classPrimitives_seq3, tc_classPrimitives,);
typedef tc_classPrimitives_seq3 tc_sequenceOfClassPrimitives;
DB_SEQUENCE(tc_color_seq3, tc_color,);
typedef tc_color_seq3 tc_sequenceOfColor;
DB_SEQUENCE(db_float32_seq3, db_float32,);
typedef db_float32_seq3 tc_sequenceOfFloat;
DB_SEQUENCE(tc_moveMode_seq3, tc_moveMode,);
typedef tc_moveMode_seq3 tc_sequenceOfMoveMode;
DB_SEQUENCE(db_string_seq3, db_string,);
typedef db_string_seq3 tc_sequenceOfString;

#ifdef __cplusplus
}
#endif
#endif

