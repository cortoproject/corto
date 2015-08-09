/* MyApp__api.h
 *
 * API convenience functions for C-language.
 * This file contains generated code. Do not modify!
 */

#ifndef MyApp__API_H
#define MyApp__API_H

#include "MyApp__type.h"
#include "cortex.h"

#ifdef __cplusplus
extern "C" {
#endif
/* ::MyApp::RedPanda */
MyApp_RedPanda MyApp_RedPanda__create(cx_int32 weight);
MyApp_RedPanda MyApp_RedPanda__createChild(cx_object _parent, cx_string _name, cx_int32 weight);

MyApp_RedPanda MyApp_RedPanda__declare(void);
MyApp_RedPanda MyApp_RedPanda__declareChild(cx_object _parent, cx_string _name);
cx_int16 MyApp_RedPanda__define(MyApp_RedPanda _this, cx_int32 weight);
void MyApp_RedPanda__update(MyApp_RedPanda _this, cx_int32 weight);
void MyApp_RedPanda__set(MyApp_RedPanda _this, cx_int32 weight);
cx_string MyApp_RedPanda__str(MyApp_RedPanda value);
MyApp_RedPanda MyApp_RedPanda__fromStr(MyApp_RedPanda value, cx_string str);
cx_int16 MyApp_RedPanda__copy(MyApp_RedPanda *dst, MyApp_RedPanda src);
cx_int16 MyApp_RedPanda__compare(MyApp_RedPanda dst, MyApp_RedPanda src);


#ifdef __cplusplus
}
#endif
#endif

