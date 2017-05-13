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

#ifndef CORTO_STRING_DESER_H_
#define CORTO_STRING_DESER_H_

#ifdef __cplusplus
extern "C" {
#endif

#define CORTO_STRING_DESER_TOKEN_MAX (1024) /* Specifies the maximum length for a token */

struct corto_indexInfo;

/* Deserializer data */
typedef struct corto_string_deser_t {
    /* Public */
    void *out;
    corto_object scope;
    corto_type type;
    corto_objectseq members; /* Custom list of members to deserialize */

    /* Private */
    corto_ll_iter_s iterData;
    corto_iter currentIter;
    corto_uint32 current;
    corto_ll index;
    corto_void* ptr;
    corto_ll anonymousObjects;
    corto_bool isObject;
    void* (*allocValue)(void *ptr, struct corto_string_deser_t *udata);
    void *allocUdata;
}corto_string_deser_t;

/* Deserialize string */
corto_string corto_string_deser(corto_string str, corto_string_deser_t* data);

#ifdef __cplusplus
}
#endif

#endif /* CORTO_STRING_DESER_H_ */
