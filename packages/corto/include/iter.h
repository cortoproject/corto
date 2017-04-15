
/*
 * corto_iter.h
 */

#ifndef CORTO_ITER_H_
#define CORTO_ITER_H_

#ifdef __cplusplus
extern "C" {
#endif

#define CORTO_ITER_STACK_LIMIT (64)
#define CORTO_ITERATOR_EMPTY (corto_iter){NULL}

/* Generic iterator implementation */
CORTO_EXPORT int corto_iterHasNext(corto_iter* iter);
CORTO_EXPORT void* corto_iterNext(corto_iter* iter);
CORTO_EXPORT void* corto_iterNextPtr(corto_iter* iter);
CORTO_EXPORT void corto_iterRelease(corto_iter* iter);

#ifdef __cplusplus
}
#endif

#endif
