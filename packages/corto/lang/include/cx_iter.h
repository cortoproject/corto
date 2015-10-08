
/*
 * cx_iter.h
 */

#ifndef CX_ITER_H_
#define CX_ITER_H_

#ifdef __cplusplus
extern "C" {
#endif

#define CX_ITER_STACK_LIMIT (64)

typedef struct cx_iter cx_iter;
struct cx_iter {
    void *udata;
    void (*moveFirst)(cx_iter*);
    void* (*move)(cx_iter*, unsigned int);
    int (*hasNext)(cx_iter*);
    void* (*next)(cx_iter*);
    void* (*nextPtr)(cx_iter*);
    void* (*remove)(cx_iter*);
    void (*insert)(cx_iter*, void*);
    void (*set)(cx_iter*, void*);
};

/* Iterator implementation */
void cx_iterMoveFirst(cx_iter* iter);
void* cx_iterMove(cx_iter* iter, unsigned int index);
int cx_iterHasNext(cx_iter* iter);
void* cx_iterNext(cx_iter* iter);
void* cx_iterNextPtr(cx_iter* iter);
void* cx_iterRemove(cx_iter* iter);
void cx_iterInsert(cx_iter* iter, void* o);
void cx_iterSet(cx_iter* iter, void* o);

#ifdef __cplusplus
}
#endif

#endif
