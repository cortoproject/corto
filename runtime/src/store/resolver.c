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

#include <corto/corto.h>
#include "object.h"

extern int CORTO_BENCHMARK_RESOLVE;

corto_bool corto_declaredAdminCheck(corto_object o);

/* Resolve anonymous object */
static corto_char* corto_resolveAnonymous(corto_object scope, corto_object o, corto_string str, corto_object* out) {
    char *ptr = str;
    corto_object result = corto_declare(o);
    corto_string_deser_t data = {
        .out = result,
        .scope = scope,
        .type = o,
        .isObject = TRUE
    };

    if (corto_type(o)->kind == CORTO_PRIMITIVE) {
        ptr += 1;
    }

    ptr = corto_string_deser(ptr, &data);
    *out = result;

    corto_define(result);

    return ptr;
}

/* Resolve address-identifier */
static corto_object corto_resolveAddress(corto_string str) {
    corto_word addr;

    addr = strtoul(str+1, NULL, 16);

    corto_claim((corto_object)addr);

    return (corto_object)addr;
}

/* Use private function to do a lookup with a string that is guaranteed lowercase */
#include "ctype.h"

/* Resolve fully scoped name */
corto_object corto_resolve(corto_object _scope, corto_string str) {
    corto_benchmark_start(CORTO_BENCHMARK_RESOLVE);
    corto_object scope, _scope_start, o, lookup;
    const char* ptr;
    char *bptr, *bptrLc;
    corto_id buffer;
    corto_id bufferLc;
    corto_char ch;
    corto_bool fullyQualified = FALSE;
    corto_bool cortoSearched = FALSE, cortoCoreSearched = FALSE;
    int step = 3;

    if (!str) {
        return NULL;
    }

    if (!*str) {
        return NULL;
    }

    if (*str == '<') {
        return corto_resolveAddress(str);
    }

    if (*str == '.') {
        _scope_start = _scope;
    } else {
        _scope_start = corto_lang_o;
    }
    scope = _scope_start;

    if (!_scope) {
        _scope = root_o;
    }

    if (*str == '/') {
        str += 1;
        scope = root_o;
        fullyQualified = TRUE;
    }

repeat:
    lookup = NULL;
    do {
        o = scope;

        ptr = str;
        ch = *ptr;
        if (!ch) {
            break;
        }
        while (ch) {
            if (scope == corto_o) {
                cortoSearched = TRUE;
            } else if (scope == corto_vstore_o) {
                cortoCoreSearched = TRUE;
            }

            bptr = buffer;
            bptrLc = bufferLc;
            while ((ch = *ptr) && (ch != ':') && (ch != '{') && (ch != '/')) {
                *bptr = ch;
                *bptrLc = tolower(ch);
                bptr++;
                bptrLc++;
                ptr++;
                if (ch == '(') {
                    while ((ch = *ptr) && (ch != ')')) {
                        *bptrLc = tolower(ch);
                        *bptr = ch;
                        bptrLc++;
                        bptr++;
                        ptr++;
                    }
                }
            }
            *bptr = '\0';
            *bptrLc = '\0';

            /* If buffer is empty, just return current object */
            if (!*buffer) {
                break;
            }

            if (!strcmp(buffer, ".")) {
                /* o is already set to scope, just continue */
            } else if (!strcmp(buffer, "..")) {
                o = corto_parentof(o);
                if (!o) {
                    corto_seterr("cannot resolve parent of root");
                    goto error;
                }
                corto_ptr_setref(&lookup, o);
            } else {
                corto_object prevLookup = lookup;

                o = corto_lookup(o, bufferLc);

                /* Release lookup after(!) potentially resuming an object. In
                 * case of a nested resume, a parent will have been
                 * resumed first. Releasing the parent before resuming the
                 * child will remove the parent from the store. Becuase the
                 * child claims the parent, this won't happen after the
                 * resume. */
                if (prevLookup) {
                    corto_release(prevLookup); /* Free reference */
                }

                lookup = o;

                if (!o) {
                    break;
                }
            }

            /* Expect scope or serializable string */
            if (ch) {
                if (ch == '{') {
                    do {
                        corto_object prev = o;
                        ptr = lookup = corto_resolveAnonymous(_scope, o, (char*)ptr, &o);
                        if (!ptr) {
                            o = NULL;
                        }
                        corto_release(prev);
                    } while (ptr && (ch = *ptr) && (ch == '{'));


                    break;
                } else if (ch == '/') {
                    ptr += 1;
                } else {
                    corto_seterr("invalid ':' in expression '%s'", str);
                    o = NULL;
                    break;
                }
            }
        }
        if (o) break;
    } while((step == 2) && (scope = corto_parentof(scope)));

    /* Do lookup in actual scope first, then in corto/vstore, then corto */
    if (!o && step && !fullyQualified) {
        switch(--step) {
        case 2:
            if ((_scope == corto_o) || (_scope == corto_lang_o)) {
                _scope_start = scope = root_o;
            } else {
                _scope_start = scope = _scope;
            }
            goto repeat;
        case 1:
            if (!cortoCoreSearched) {
                _scope_start = scope = corto_vstore_o;
                goto repeat;
            }
            break;
        case 0:
            if (!cortoSearched) {
                _scope_start = scope = corto_o;
                goto repeat;
            }
            break;
        }

         /* Do goto instead of a recursive call. Besides saving (a little bit of) performance,
            this also preserves the original searchscope, which is needed in anonymous type lookups, which
            uses the stringserializer. In a serialized string references to other objects may be relatively
            scoped. For example: the string sequence{F} results in an anonymous sequence object with
            elementType 'F', which is looked up in scope '_scope_start'. */
    }

    /* If the current object is not obtained by a lookup, it is not yet keeped. */
    if (!lookup && o) {
        corto_claim(o);
    }

    if (o && !corto_authorized(o, CORTO_SECURE_ACTION_READ)) {
        goto access_error;
    }

    /* If object is not defined and not declared by this thread, don't return */
    if (o && !corto_checkState(o, CORTO_VALID) && !corto_declaredAdminCheck(o)) {
        corto_debug(
            "corto: resolved undefined object '%s' is declared by another thread (%d)",
            corto_fullpath(NULL, o), corto_declaredAdminCheck(o));
        corto_release(o);
        o = NULL;
    }

    corto_benchmark_stop(CORTO_BENCHMARK_RESOLVE);
    return o;
access_error:
    corto_release(o);
error:
    corto_benchmark_stop(CORTO_BENCHMARK_RESOLVE);
    return NULL;
}
