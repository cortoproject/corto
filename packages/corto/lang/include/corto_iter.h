
/*
 * corto_iter.h
 */

#ifndef CORTO_ITER_H_
#define CORTO_ITER_H_

#ifdef __cplusplus
extern "C" {
#endif

#define CORTO_ITER_STACK_LIMIT (64)

#define CORTO_ITERATOR(_name)\
typedef struct _name _name;\
struct _name {\
    void *udata;\
    void (*moveFirst)(_name*);\
    void* (*move)(_name*, unsigned int);\
    int (*hasNext)(_name*);\
    void* (*next)(_name*);\
    void* (*nextPtr)(_name*);\
    void* (*remove)(_name*);\
    void (*insert)(_name*, void*);\
    void (*set)(_name*, void*);\
}\

CORTO_ITERATOR(corto_iter);

/* Generic iterator implementation */
void corto_iterMoveFirst(corto_iter* iter);
void* corto_iterMove(corto_iter* iter, unsigned int index);
int corto_iterHasNext(corto_iter* iter);
void* corto_iterNext(corto_iter* iter);
void* corto_iterNextPtr(corto_iter* iter);
void* corto_iterRemove(corto_iter* iter);
void corto_iterInsert(corto_iter* iter, void* o);
void corto_iterSet(corto_iter* iter, void* o);

#ifdef __cplusplus
}
#endif

#endif
