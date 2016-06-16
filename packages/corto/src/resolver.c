
#include "corto/corto.h"

/* Resolve anonymous object */
static corto_char* corto_resolveAnonymous(corto_object scope, corto_object o, corto_string str, corto_object* out) {
    corto_object result;
    corto_string_deser_t data;

    result = corto_declare(o);
    data.out = result;
    data.scope = scope;
    data.type = o;

    if (corto_type(o)->kind == CORTO_PRIMITIVE) {
        str += 1;
    }

    str = corto_string_deser(str, &data);
    *out = result;

    corto_define(result);

    return str;
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
corto_object corto_lookupLowercase(corto_object o, corto_string name);

/* Resolve fully scoped name */
corto_object corto_resolve(corto_object _scope, corto_string str) {
    corto_object scope, _scope_start, o, lookup;
    const char* ptr;
    char *bptr, *bptrLc;
    corto_id buffer;
    corto_id bufferLc;
    corto_char ch;
    corto_bool overload;
    corto_bool fullyQualified = FALSE;
    corto_bool cortoSearched = FALSE, cortoCoreSearched = FALSE;
    int step = 3;

    if (!str) {
        str = "/";
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

    if (*(corto_uint16*)str == CORTO_SCOPE_HEX) {
        str += 2;
        scope = root_o;
        fullyQualified = TRUE;
    } else if (*str == '/') {
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
            overload = FALSE;
            if (scope == corto_o) {
                cortoSearched = TRUE;
            } else if (scope == corto_core_o) {
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
                    overload = TRUE;
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
                corto_setref(&lookup, o);
            } else {
                if (!overload) {
                    corto_object prev = o, prevLookup = lookup;

                    o = corto_lookupLowercase(o, bufferLc);

                    if (!o && (prev != corto_lang_o) && (prev != corto_core_o)) {
                        o = corto_resume(prev, buffer, NULL);
                    }

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
                    if (o) {
                        if (corto_instanceof(corto_function_o, o)) {
                            if (corto_function(o)->overloaded == TRUE) {
                                corto_release(o);
                                corto_seterr("ambiguous reference to '%s'", str);
                                goto error;
                            }
                        }
                    }

                    if (!o) {
                        break;
                    }
                } else {
                    /* If argumentlist is provided, look for closest match */
                    o = corto_lookupFunction(o, bufferLc, NULL);
                    if (lookup) {
                        corto_release(lookup);
                    }
                    lookup = o;
                    if (!o) {
                        break;
                    }
                }
            }

            /* Expect scope or serializable string */
            if (ch) {
                if (ch == '{') {
                    corto_object prev = o;
                    ptr = lookup = corto_resolveAnonymous(_scope, o, (char*)ptr, &o);
                    if (!ptr) {
                        o = NULL;
                    }
                    corto_release(prev);
                    break;
                } else if (*(corto_uint16*)ptr == CORTO_SCOPE_HEX) {
                    ptr += 2;
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

    /* Do lookup in actual scope first, then in corto/core, then corto */
    if (!o && step && !fullyQualified) {
        switch(--step) {
        case 2:
            if ((_scope == corto_o) || (_scope == corto_lang_o)) {
                _scope_start = scope = root_o;
            } else {
                _scope_start = scope = _scope;
            }
            goto repeat;
            break;
        case 1:
            if (!cortoCoreSearched) {
                _scope_start = scope = corto_core_o;
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

    return o;
error:
    return NULL;
}
