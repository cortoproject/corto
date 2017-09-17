/* Copyright (c) 2010-2017 the corto developers
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include <include/base.h>

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
