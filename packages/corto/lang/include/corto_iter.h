
/*
 * corto_iter.h
 */

#ifndef CORTO_ITER_H_
#define CORTO_ITER_H_

#ifdef __cplusplus
extern "C" {
#endif

#define CORTO_ITER_STACK_LIMIT (64)

/* Create a typedef, so generic iterator functions can be used with user
 * defined iterator types */
#define CORTO_ITERATOR(_name) typedef corto_iter _name

typedef struct corto_iter corto_iter;
struct corto_iter {
    void *udata;
    void (*moveFirst)(corto_iter*);
    void* (*move)(corto_iter*, unsigned int);
    int (*hasNext)(corto_iter*);
    void* (*next)(corto_iter*);
    void* (*nextPtr)(corto_iter*);
    void* (*remove)(corto_iter*);
    void (*insert)(corto_iter*, void*);
    void (*set)(corto_iter*, void*);
    void (*release)(corto_iter*);
};

/* Generic iterator implementation */
void corto_iterMoveFirst(corto_iter* iter);
void* corto_iterMove(corto_iter* iter, unsigned int index);
int corto_iterHasNext(corto_iter* iter);
void* corto_iterNext(corto_iter* iter);
void* corto_iterNextPtr(corto_iter* iter);
void* corto_iterRemove(corto_iter* iter);
void corto_iterInsert(corto_iter* iter, void* o);
void corto_iterSet(corto_iter* iter, void* o);
void corto_iterRelease(corto_iter* iter);

#ifdef __cplusplus
}
#endif

#endif
