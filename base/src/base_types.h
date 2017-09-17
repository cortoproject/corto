
#ifndef CORTO__BASE_TYPES_H_
#define CORTO__BASE_TYPES_H_

#include <include/base.h>

typedef struct corto_ll_node_s {
    void* data;
    corto_ll_node next;
    corto_ll_node prev;
} corto_ll_node_s;

typedef struct corto_ll_s {
    corto_ll_node first;
    corto_ll_node last;
    unsigned int size;
} corto_ll_s;

#endif
