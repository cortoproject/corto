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

#ifndef ARGPARSE_H
#define ARGPARSE_H

/* Add include files here */

/* Command-line argument parsing utility library */

#include "corto/corto.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Argument parser that requires no callbacks
 */
typedef struct corto_argdata {
    const char *pattern;
    corto_ll *match;
    corto_ll *args;
    corto_int8 count;
    corto_ll gc;
} corto_argdata;

corto_argdata* corto_argparse(char *argv[], corto_argdata *data);
void corto_argclean(corto_argdata *data);

#ifdef __cplusplus
}
#endif

#endif /* ARGPARSE_H */
