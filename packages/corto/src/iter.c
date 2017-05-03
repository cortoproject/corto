
#include "corto/corto.h"

int corto_iter_hasNext(corto_iter* iter) {
    if (iter->hasNext) {
        if (!iter->hasNext(iter)) {
            corto_iter_release(iter);
            iter->hasNext = NULL;
            return 0;
        } else {
            return 1;
        }
    } else {
        return 0;
    }
}

void* corto_iter_next(corto_iter* iter) {
    return iter->next(iter);
}

void* corto_iter_nextPtr(corto_iter* iter) {
    return iter->nextPtr(iter);
}

void corto_iter_release(corto_iter* iter) {
    if (iter->release) {
        iter->release(iter);
        iter->release = NULL;
    }
}
