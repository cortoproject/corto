#include "cx_object.h"
#include "cx_string.h"

/*
 * Writes at most `n` - 1 bytes from `in` into `out`, plus a null character.
 * Returns the total length that should have been written without the null character.
 * Escapes all single quotes as two single quotes.
 * https://www.sqlite.org/lang_expr.html
 */
size_t escsqlstr(char *out, size_t n, const char *in) {
    size_t len = 0;
    const char *p = in;
    char *q = out;
    char c;
    while ((c = *p++)) {
        if (c != '\'') {
            len++;
            if (n && (size_t)(q - out) < n) {
                *q++ = c;
            }
        } else {
            len += 2;
            if (n && (size_t)(q - out) < n) {
                *(q + 1) = *q = '\'';
                q += 2;
            }
        }
    }
    if (n) {
        *q = '\0';
    }
    return len;
}

/*
 *
 */
int cx_sqlite_solveName(cx_object o, cx_id buffer) {
    cx_char *ptr;
    if (!o) {
        *buffer = '\0';
    } else if (!cx_checkAttr(o, CX_ATTR_SCOPED)) {
        goto error;
    } else {
        cx_object stack[CX_MAX_SCOPE_DEPTH];
        cx_uint32 depth = 0;
        do {
            stack[depth++] = o;
        } while((o = cx_parentof(o)));
        ptr = buffer;
        if (depth == 1) {
            *ptr++ = '_';
        } else {
            while (depth--) {
                cx_string name;
                o = stack[depth];
                if ((name = cx_nameof(o))) {
                    size_t len;
                    *ptr++ = '_';
                    if ((size_t)(ptr - buffer) >= (sizeof(cx_id) - 1)) {
                        goto finished;
                    }
                    len = strlen(name);
                    if ((size_t)(ptr - buffer + len) >= (sizeof(cx_id) - 1)) {
                        goto finished;
                    }
                    memcpy(ptr, name, len + 1);
                    ptr += len;
                }
            }
        }
        *ptr = '\0';
    }
    return 0;
finished:
    *ptr = '\0';
    return 1;
error:
    return -1;
}
