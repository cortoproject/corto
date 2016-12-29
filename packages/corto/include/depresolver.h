

#ifndef CORTO__DEPRESOLVER_H_
#define CORTO__DEPRESOLVER_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef struct corto_depresolver_s* corto_depresolver;

typedef int (*corto_depresolver_action)(corto_object o, void *userData);

CORTO_EXPORT corto_depresolver corto_depresolverCreate(corto_depresolver_action onDeclare, corto_depresolver_action onDefine, void *userData);

CORTO_EXPORT void corto_depresolver_insert(corto_depresolver _this, void *item);

CORTO_EXPORT void corto_depresolver_depend(corto_depresolver _this, void *dependent, corto_state kind, void *dependency, corto_state dependencyKind);

CORTO_EXPORT int corto_depresolver_walk(corto_depresolver _this);

#ifdef __cplusplus
}
#endif

#endif
