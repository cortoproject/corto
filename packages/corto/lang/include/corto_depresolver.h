

#ifndef CORTO__DEPRESOLVER_H_
#define CORTO__DEPRESOLVER_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef struct corto_depresolver_s* corto_depresolver;

typedef int (*corto_depresolver_action)(corto_object o, void *userData);

corto_depresolver corto_depresolverCreate(corto_depresolver_action onDeclare, corto_depresolver_action onDefine, void *userData);

void corto_depresolver_insert(corto_depresolver _this, void *item);

void corto_depresolver_depend(corto_depresolver _this, void *dependent, corto_uint8 kind, void *dependency, corto_uint8 dependencyKind);

int corto_depresolver_walk(corto_depresolver _this);

#ifdef __cplusplus
}
#endif

#endif

