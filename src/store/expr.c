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

#include "object.h"

static corto_int16 ___ (*_corto_expr_compb)(
    ext_corto_expr *out, 
    ext_corto_expr_opt *opt, 
    char *expr, 
    char **types);

static corto_int16 ___ (*_corto_expr_runb)(
    ext_corto_expr *expr, 
    corto_value *out, 
    void **args);

static corto_int16 ___ (*_corto_expr_free)(
    ext_corto_expr *expr);

static corto_int16 ext_corto_expr_load() {

    if (!_corto_expr_free) {
        corto_dl dl = NULL;

        _corto_expr_compb = (corto_int16 ___ (*)(ext_corto_expr*,ext_corto_expr_opt*,char*,char**))
            corto_load_proc("driver/ext", &dl, "corto_expr_compb");
        if (!_corto_expr_compb) {
            corto_throw("corto_expr_compb not found in corto/expr");
            goto error;
        }

        _corto_expr_runb = (corto_int16 ___ (*)(ext_corto_expr*,corto_value*,void**))
            corto_load_proc("driver/ext", &dl, "corto_expr_runb");
        if (!_corto_expr_runb) {
            corto_throw("corto_expr_runb not found in corto/expr");
            goto error;
        }

        _corto_expr_free = (corto_int16 ___ (*)(ext_corto_expr*))
            corto_load_proc("driver/ext", &dl, "corto_expr_free");
        if (!_corto_expr_free) {
            corto_throw("corto_expr_free not found in corto/expr");
            goto error;
        }
    }

    return 0;
error:
    return -1;
}

ext_corto_expr* ext_corto_expr_alloc(void) {
    return corto_calloc(sizeof(ext_corto_expr));
}

corto_int16 ext_corto_expr_compb(
    ext_corto_expr *out, 
    ext_corto_expr_opt *opt, 
    char *expr, 
    char **types) 
{
    if (ext_corto_expr_load()) {
        goto error;
    }

    return _corto_expr_compb(out, opt, expr, types);
error:
    return -1;
}

corto_int16 ext_corto_expr_runb(
    ext_corto_expr *expr, 
    corto_value *out, 
    void **args) 
{
    if (ext_corto_expr_load()) {
        goto error;
    }

    return _corto_expr_runb(expr, out, args);
error:
    return -1;
}

corto_int16 ext_corto_expr_free(ext_corto_expr *expr) {
    if (ext_corto_expr_load()) {
        goto error;
    }

    _corto_expr_free(expr);

    return 0;
error:
    return -1;
}
