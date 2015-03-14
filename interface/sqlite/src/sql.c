#include "cx_string.h"

/*
 * Writes at most `n` - 1 bytes from `in` into `out`.
 * Returns the total length that should have been written without the null character.
 * Escapes all single quotes as double quotes.
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
