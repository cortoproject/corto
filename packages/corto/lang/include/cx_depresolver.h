

#ifndef CX__DEPRESOLVER_H_
#define CX__DEPRESOLVER_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef struct cx_depresolver_s* cx_depresolver;

typedef int (*cx_depresolver_action)(cx_object o, void *userData);

cx_depresolver cx_depresolverCreate(cx_depresolver_action onDeclare, cx_depresolver_action onDefine, void *userData);

void cx_depresolver_insert(cx_depresolver _this, void *item);

void cx_depresolver_depend(cx_depresolver _this, void *dependent, cx_uint8 kind, void *dependency, cx_uint8 dependencyKind);

int cx_depresolver_walk(cx_depresolver _this);

#ifdef __cplusplus
}
#endif

#endif

