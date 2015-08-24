
#include "cortex.h"

/* Resolve anonymous object */
static cx_char* cx_resolveAnonymous(cx_object scope, cx_object o, cx_string str, cx_object* out) {
    cx_object result;
    cx_string_deser_t data;

    result = cx_declare(o);
    data.out = result;
    data.scope = scope;
    data.type = NULL;
    str = cx_string_deser(str, &data);
    *out = result;

    cx_define(result);

    return str;
}

/* Resolve address-identifier */
static cx_object cx_resolveAddress(cx_string str) {
    cx_word addr;

    addr = strtoul(str+1, NULL, 16);

    cx_claim((cx_object)addr);

    return (cx_object)addr;
}

/* Resolve fully scoped name */
cx_object cx_resolve(cx_object _scope, cx_string str) {
    cx_object scope, _scope_start, o, lookup;
    const char* ptr;
    char* bptr;
    cx_id buffer;
    cx_char ch;
    cx_bool overload;
    cx_bool fullyQualified = FALSE;
    cx_bool cortexSearched = FALSE;
    int step = 2;

    if (!*str) {
        return NULL;
    }

    if (*str == '<') {
        return cx_resolveAddress(str);
    }

    _scope_start = cortex_lang_o;
    scope = _scope_start;

    if (!_scope) {
        _scope = root_o;
    }

    if (*(cx_uint16*)str == CX_SCOPE_HEX) {
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
            if (scope == cortex_o) {
                cortexSearched = TRUE;
            }

            bptr = buffer;
            while ((ch = *ptr) && (ch != ':') && (ch != '{') && (ch != '/')) {
                *bptr = ch;
                bptr++;
                ptr++;
                if (ch == '(') {
                    overload = TRUE;
                    while ((ch = *ptr) && (ch != ')')) {
                        *bptr = ch;
                        bptr++;
                        ptr++;
                    }
                }
            }
            *bptr = '\0';

            if (cx_scopeSize(o)) {
                if (!overload) {
                    cx_object prev = o;
                    int i;
                    for (i = 0; i < 2; i++) {
                        o = cx_lookup(o, buffer);
                        if (!o) {
                            o = cx_lookupFunction(prev, buffer, NULL);
                        }
                        if (lookup) {
                            cx_release(lookup); /* Free reference */
                        }
                        lookup = o;

                        if (!o) {
                            if (!i && (prev != cortex_lang_o) && cx_instanceof(cx_type(cx_package_o), prev)) {
                                cx_id load, id;
                                sprintf(load, "%s/%s", cx_fullname(prev, id), buffer);
                                int oldEcho = cx_toggleEcho(0);
                                cx_load(load);
                                cx_toggleEcho(oldEcho);
                                o = prev;
                            } else {
                                break;
                            }
                        } else {
                            break;
                        }
                    }

                    if (!o) {
                        break;
                    }
                } else {
                    /* If argumentlist is provided, look for closest match */
                    o = cx_lookupFunction(o, buffer, NULL);
                    if (lookup) {
                        cx_release(lookup);
                    }
                    lookup = o;
                    if (!o) {
                        break;
                    }
                }
            } else {
                o = NULL;
                if (lookup) {
                    cx_release(lookup);
                    lookup = NULL;
                }
                break;
            }

            /* Expect scope or serializable string */
            if (ch) {
                if (ch == '{') {
                    cx_object prev = o;
                    ptr = lookup = cx_resolveAnonymous(_scope, o, (char*)ptr, &o);
                    if (!ptr) {
                        o = NULL;
                    }
                    cx_release(prev);
                    break;
                } else if (*(cx_uint16*)ptr == CX_SCOPE_HEX) {
                    ptr += 2;
                } else if (ch == '/') {
                    ptr += 1;
                } else {
                    cx_error("cx_resolve: invalid ':' in expression '%s'", str);
                    o = NULL;
                    break;
                }
            }
        }
        if (o) break;
    } while((step == 1) && (scope = cx_parentof(scope)));

    /* Do lookup in actual scope first, then in cortex */
    if (!o && step && !fullyQualified) {
        switch(--step) {
        case 1:
            if ((_scope == cortex_o) || (_scope == cortex_lang_o)) {
                _scope_start = scope = root_o;
            } else {
                _scope_start = scope = _scope;
            }
            goto repeat;
            break;
        case 0:
            if (!cortexSearched) {
                _scope_start = scope = cortex_o;
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
        cx_claim(o);
    }

    return o;
}
