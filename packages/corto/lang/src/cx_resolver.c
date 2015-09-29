
#define corto_lang_LIB
#include "corto.h"

/* Resolve anonymous object */
static cx_char* cx_resolveAnonymous(cx_object scope, cx_object o, cx_string str, cx_object* out) {
    cx_object result;
    cx_string_deser_t data;

    result = cx_declare(o);
    data.out = result;
    data.scope = scope;
    data.type = o;

    if (cx_type(o)->kind == CX_PRIMITIVE) {
        str += 1;
    }

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

/* Use private function to do a lookup with a string that is guaranteed lowercase */
#include "ctype.h"
cx_object cx_lookupLowercase(cx_object o, cx_string name);

/* Resolve fully scoped name */
cx_object cx_resolve(cx_object _scope, cx_string str) {
    cx_object scope, _scope_start, o, lookup;
    const char* ptr;
    char *bptr, *bptrLc;
    cx_id buffer;
    cx_id bufferLc;
    cx_char ch;
    cx_bool overload;
    cx_bool fullyQualified = FALSE;
    cx_bool cortoSearched = FALSE;
    int step = 2;

    if (!str) {
        str = "::";
    }

    if (!*str) {
        return NULL;
    }

    if ((str[0] == '.') && (str[1] == '\0')) {
        cx_claim(_scope);
        return _scope;
    }

    if (*str == '<') {
        return cx_resolveAddress(str);
    }

    _scope_start = corto_lang_o;
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
            if (scope == corto_o) {
                cortoSearched = TRUE;
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

            if (cx_scopeSize(o)) {
                if (!overload) {
                    cx_object prev = o;
                    int i;
                    for (i = 0; i < 2; i++) {
                        o = cx_lookupLowercase(o, bufferLc);
                        if (lookup) {
                            cx_release(lookup); /* Free reference */
                        }
                        lookup = o;
                        if (o) {
                            if (cx_instanceof(cx_function_o, o)) {
                                if (cx_function(o)->overloaded == TRUE) {
                                    cx_release(o);
                                    cx_seterr("ambiguous reference to '%s'", str);
                                    goto error;
                                }
                            }
                        }

                        if (!o) {
                            if (!i && (prev != corto_lang_o) && cx_instanceof(cx_type(cx_package_o), prev)) {
                                cx_id load, id;
                                if (prev != root_o) {
                                    sprintf(load, "%s/%s", cx_fullname(prev, id), buffer);
                                } else {
                                    sprintf(load, "/%s", buffer);
                                }
                                cx_load(load, 0, NULL);
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
                    o = cx_lookupFunction(o, bufferLc, NULL);
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

    /* Do lookup in actual scope first, then in corto */
    if (!o && step && !fullyQualified) {
        switch(--step) {
        case 1:
            if ((_scope == corto_o) || (_scope == corto_lang_o)) {
                _scope_start = scope = root_o;
            } else {
                _scope_start = scope = _scope;
            }
            goto repeat;
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
        cx_claim(o);
    }

    return o;
error:
    return NULL;
}
