
#ifndef CXSTR_H_
#define CXSTR_H_

#ifdef __cplusplus
extern "C" {
#endif

corto_object cxstr_create(corto_string type, corto_string value);
corto_object cxstr_createChild(corto_string parent, corto_string name, corto_string type, corto_string value);
corto_object cxstr_declare(corto_string type);
corto_object cxstr_declareChild(corto_string parent, corto_string name, corto_string type);
corto_object cxstr_define(corto_object o, corto_string value);
void cxstr_update(corto_object o, corto_string value);

#ifdef __cplusplus
}
#endif

#endif
