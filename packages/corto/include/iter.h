
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

/* Create a typedef, so generic iterator functions can be used with user
 * defined iterator types */
#define CORTO_ITERATOR(_name) typedef corto_iter _name

typedef struct corto_iter corto_iter;
struct corto_iter {
    int (*hasNext)(corto_iter*);
    void *udata;
    void* (*next)(corto_iter*);
    void* (*nextPtr)(corto_iter*);
    void (*release)(corto_iter*);
};

/* Generic iterator implementation */
int corto_iterHasNext(corto_iter* iter);
void* corto_iterNext(corto_iter* iter);
void* corto_iterNextPtr(corto_iter* iter);
void corto_iterRelease(corto_iter* iter);

#ifdef __cplusplus
}
#endif

#endif
