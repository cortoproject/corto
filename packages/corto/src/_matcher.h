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

#ifndef CORTO__MATCHER_H_
#define CORTO__MATCHER_H_

#include <corto/corto.h>

typedef enum corto_idmatchToken {
    CORTO_MATCHER_TOKEN_NONE,
    CORTO_MATCHER_TOKEN_THIS,
    CORTO_MATCHER_TOKEN_PARENT,
    CORTO_MATCHER_TOKEN_IDENTIFIER,
    CORTO_MATCHER_TOKEN_FILTER,
    CORTO_MATCHER_TOKEN_AND,
    CORTO_MATCHER_TOKEN_OR,
    CORTO_MATCHER_TOKEN_NOT,
    CORTO_MATCHER_TOKEN_SCOPE,
    CORTO_MATCHER_TOKEN_TREE,
    CORTO_MATCHER_TOKEN_SEPARATOR
} corto_idmatchToken;

typedef struct corto_idmatchOp {
    corto_idmatchToken token;
    char *start;
    corto_bool containsWildcard;
} corto_idmatchOp;

struct corto_idmatch_program_s {
    int kind; /* 0 = default, 1 = identifier, 2 = this, 3 = /, 4 = // */
    corto_idmatchOp ops[CORTO_MATCHER_MAX_OP];
    corto_uint8 size;
    corto_string tokens;
};

corto_int16 corto_idmatchParseIntern(
    corto_idmatch_program data,
    corto_string expr,
    corto_bool allowScopes,
    corto_bool allowSeparators);

#endif
