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

#ifndef CORTO__DEPRESOLVER_H_
#define CORTO__DEPRESOLVER_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef struct corto_depresolver_s* corto_depresolver;

typedef int (*corto_depresolver_action)(corto_object o, void *userData);

CORTO_EXPORT corto_depresolver corto_depresolverCreate(corto_depresolver_action onDeclare, corto_depresolver_action onDefine, void *userData);

CORTO_EXPORT void corto_depresolver_insert(corto_depresolver _this, void *item);

CORTO_EXPORT void corto_depresolver_depend(corto_depresolver _this, void *dependent, corto_state kind, void *dependency, corto_state dependencyKind);

CORTO_EXPORT int corto_depresolver_walk(corto_depresolver _this);

#ifdef __cplusplus
}
#endif

#endif
