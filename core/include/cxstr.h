
#ifndef CXSTR_H_
#define CXSTR_H_

#ifdef __cplusplus
extern "C" {
#endif

cx_object cxstr_create(cx_string type, cx_string value);
cx_object cxstr_createChild(cx_string parent, cx_string name, cx_string type, cx_string value);
cx_object cxstr_declare(cx_string type);
cx_object cxstr_declareChild(cx_string parent, cx_string name, cx_string type);
cx_object cxstr_define(cx_object o, cx_string value);
void cxstr_update(cx_object o, cx_string value);

#endif
