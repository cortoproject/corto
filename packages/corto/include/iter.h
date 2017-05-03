
/*
 * corto_iter.h
 */

#ifndef CORTO_ITER_H_
#define CORTO_ITER_H_

#ifdef __cplusplus
extern "C" {
#endif

#define CORTO_ITER_STACK_LIMIT (64)
#define CORTO_ITER_EMPTY (corto_iter){NULL}

CORTO_EXPORT int corto_iter_hasNext(corto_iter* iter);
CORTO_EXPORT void* corto_iter_next(corto_iter* iter);
CORTO_EXPORT void* corto_iter_nextPtr(corto_iter* iter);
CORTO_EXPORT void corto_iter_release(corto_iter* iter);

#ifdef __cplusplus
}
#endif

#endif
