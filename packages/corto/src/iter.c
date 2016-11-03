
#include "corto/corto.h"

int corto_iterHasNext(corto_iter* iter) {
    if (iter->hasNext) {
        if (!iter->hasNext(iter)) {
            corto_iterRelease(iter);
            iter->hasNext = NULL;
            return 0;
        } else {
            return 1;
        }
    } else {
        return 0;
    }
}

void* corto_iterNext(corto_iter* iter) {
    return iter->next(iter);
}

void* corto_iterNextPtr(corto_iter* iter) {
    return iter->nextPtr(iter);
}

void corto_iterRelease(corto_iter* iter) {
    if (iter->release) {
        iter->release(iter);
        iter->release = NULL;
    }
}
