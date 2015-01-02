/* tc_stringser__api.h
 *
 *  Generated on Feb  5 2014
 *    API convenience functions for C-language.
 *    This file contains generated code. Do not modify!
 */

#ifndef tc_stringser__API_H
#define tc_stringser__API_H

#include "tc_stringser__type.h"
#include "cortex.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::tc_stringser::classCompositeCollection */
tc_classCompositeCollection tc_classCompositeCollection__new(void);
tc_classCompositeCollection tc_classCompositeCollection__declare(cx_object _parent, cx_string _name);
int tc_classCompositeCollection__define(tc_classCompositeCollection _this, tc_arrayOfClassInherit a, tc_arrayOfClassNested b, tc_sequenceOfClassInherit c, tc_listOfClassNested d, tc_listOfClassInherit e);
tc_classCompositeCollection tc_classCompositeCollection__create(tc_arrayOfClassInherit a, tc_arrayOfClassNested b, tc_sequenceOfClassInherit c, tc_listOfClassNested d, tc_listOfClassInherit e);

/* ::tc_stringser::classInherit */
tc_classInherit tc_classInherit__new(void);
tc_classInherit tc_classInherit__declare(cx_object _parent, cx_string _name);
int tc_classInherit__define(tc_classInherit _this, cx_bool a, cx_char b, cx_int32 c, cx_float32 d, cx_string e, tc_color f, tc_moveMode g, cx_bool a_1, cx_char b_1, cx_int32 c_1, cx_float32 d_1, cx_string e_1, tc_color f_1, tc_moveMode g_1);
tc_classInherit tc_classInherit__create(cx_bool a, cx_char b, cx_int32 c, cx_float32 d, cx_string e, tc_color f, tc_moveMode g, cx_bool a_1, cx_char b_1, cx_int32 c_1, cx_float32 d_1, cx_string e_1, tc_color f_1, tc_moveMode g_1);

/* ::tc_stringser::classNested */
tc_classNested tc_classNested__new(void);
tc_classNested tc_classNested__declare(cx_object _parent, cx_string _name);
int tc_classNested__define(tc_classNested _this, tc_classPrimitives a, tc_classInherit b, tc_arrayOfInt c, tc_sequenceOfInt d, tc_listOfInt e);
tc_classNested tc_classNested__create(tc_classPrimitives a, tc_classInherit b, tc_arrayOfInt c, tc_sequenceOfInt d, tc_listOfInt e);

/* ::tc_stringser::classPrimitives */
tc_classPrimitives tc_classPrimitives__new(void);
tc_classPrimitives tc_classPrimitives__declare(cx_object _parent, cx_string _name);
int tc_classPrimitives__define(tc_classPrimitives _this, cx_bool a, cx_char b, cx_int32 c, cx_float32 d, cx_string e, tc_color f, tc_moveMode g);
tc_classPrimitives tc_classPrimitives__create(cx_bool a, cx_char b, cx_int32 c, cx_float32 d, cx_string e, tc_color f, tc_moveMode g);


#ifdef __cplusplus
}
#endif
#endif

