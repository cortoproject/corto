
#include "cortex.h"

/* Resolve anonymous object */
static cx_char* cx_resolveAnonymous(cx_object src, cx_object scope, cx_object o, cx_string str, cx_object* out) {
    CX_UNUSED(src);
    cx_object result;
    cx_string_deser_t data;

    result = cx_new_ext(NULL, cx_type(o), (cx_type(o)->kind == CX_VOID) ? CX_ATTR_WRITABLE : 0, "Create anonymous object");
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

    cx_keep_ext(NULL, (cx_object)addr, "Resolve by address");

    return (cx_object)addr;
}

/* Resolve fully scoped name */
cx_object cx_resolve_ext(cx_object src, cx_object _scope, cx_string str, cx_bool allowCastableOverloading, cx_string context) {
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

            if (cx_scopeof(o)) {
                if (!overload) {
                    cx_object prev = o;
                    int i;
                    for (i = 0; i < 2; i++) {
                        o = cx_lookup_ext(src, o, buffer, context);
                        if (!o) {
                            o = cx_lookupFunction_ext(src, prev, buffer, allowCastableOverloading, NULL, context);
                        }
                        if (lookup) {
                            cx_free_ext(src, lookup, "Free intermediate reference for resolve"); /* Free reference */
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
                    o = cx_lookupFunction_ext(src, o, buffer, allowCastableOverloading, NULL, context);
                    if (lookup) {
                        cx_free_ext(src, lookup, "Free intermediate procedure-reference for resolve");
                    }
                    lookup = o;
                    if (!o) {
                        break;
                    }
                }
            } else {
                o = NULL;
                if (lookup) {
                    cx_free_ext(src, lookup, "Free intermediate reference (object not found) for resolve");
                    lookup = NULL;
                }
                break;
            }

            /* Expect scope or serializable string */
            if (ch) {
                if (ch == '{') {
                    cx_object prev = o;
                    ptr = lookup = cx_resolveAnonymous(src, _scope, o, (char*)ptr, &o);
                    if (!ptr) {
                        o = NULL;
                    }
                    cx_free_ext(src, prev, "Free type of anonymous identifier");
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
        cx_keep_ext(src, o, context);
    }

    return o;
}

cx_object cx_resolve(cx_object _scope, cx_string str) {
    return cx_resolve_ext(NULL, _scope, str, FALSE, NULL);
}
