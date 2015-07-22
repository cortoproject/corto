
#include "ctype.h"
#include <stdlib.h>
#include <stdio.h>
#include "cx_mem.h"

int stricmp(const char *str1, const char *str2) {
    const char *ptr1, *ptr2;
    char ch1, ch2;
    ptr1 = str1;
    ptr2 = str2;

    while((ch1 = *ptr1) && (ch2 = *ptr2)) {
        ch1 = tolower(ch1);
        ch2 = tolower(ch2);
        if (ch1 != ch2) {
            return ch1 - ch2;
        }
        ptr1++;
        ptr2++;
    }

    return tolower(*ptr1) - tolower(*ptr2);
}

char *strappend(char *src, char *fmt, ...) {
    char buff[1024];
    va_list args;
    unsigned int sourceLength = 0;

    va_start(args, fmt);
    vsprintf(buff, fmt, args);
    va_end(args);

    if (src) {
        sourceLength = strlen(src);
    }

    src = cx_realloc(src, sourceLength + strlen(buff) + 1);
    strcpy(&src[sourceLength], buff);

    return src;
}

/**
 * C++ version 0.4 char* style "itoa":
 * Written by Lukás Chmela
 * Released under GPLv3.
 */
char *itostr(int value, char *result, int base) {
    // check that the base if valid
    if (base < 2 || base > 36) { *result = '\0'; return result; }

    char* ptr = result, *ptr1 = result, tmp_char;
    int tmp_value;

    do {
        tmp_value = value;
        value /= base;
        *ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz" [35 + (tmp_value - value * base)];
    } while ( value );

    // Apply negative sign
    if (tmp_value < 0) *ptr++ = '-';
    *ptr-- = '\0';
    while(ptr1 < ptr) {
        tmp_char = *ptr;
        *ptr--= *ptr1;
        *ptr1++ = tmp_char;
    }
    return result;
}

char *utostr(unsigned int value, char *result, int base) {
    // check that the base if valid
    if (base < 2 || base > 36) { *result = '\0'; return result; }

    char* ptr = result, *ptr1 = result, tmp_char;
    int tmp_value;

    do {
        tmp_value = value;
        value /= base;
        *ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz" [35 + (tmp_value - value * base)];
    } while ( value );

    *ptr-- = '\0';
    while(ptr1 < ptr) {
        tmp_char = *ptr;
        *ptr--= *ptr1;
        *ptr1++ = tmp_char;
    }
    return result;
}


char *chresc(char *out, char in, char delimiter) {
    char *bptr = out;
    switch(in) {
    case '\a':
        *bptr++ = '\\';
        *bptr = 'a';
        break;
    case '\b':
        *bptr++ = '\\';
        *bptr = 'b';
        break;
    case '\f':
        *bptr++ = '\\';
        *bptr = 'f';
        break;
    case '\n':
        *bptr++ = '\\';
        *bptr = 'n';
        break;
    case '\r':
        *bptr++ = '\\';
        *bptr = 'r';
        break;
    case '\t':
        *bptr++ = '\\';
        *bptr = 't';
        break;
    case '\v':
        *bptr++ = '\\';
        *bptr = 'v';
        break;
    case '\\':
        *bptr++ = '\\';
        *bptr = '\\';
        break;
    default:
        if (in == delimiter) {
            *bptr = '\\';
            *(++bptr) = delimiter;
        } else {
            *bptr = in;
        }
        break;
    }

    *(++bptr) = '\0';

    return bptr;
}

size_t stresc(char *out, size_t n, const char *in) {
    const char *ptr = in;
    char ch, *bptr = out, buff[3];
    size_t written = 0;
    while ((ch = *ptr++)) {
        if ((written += (chresc(buff, ch, '"') - buff)) <= n) {
            *bptr++ = buff[0];
            if ((ch = buff[1])) {
                *bptr = ch;
                bptr++;
            }
        }
    }

    if (bptr) {
        while (written < n) {
            *bptr = '\0';
            bptr++;
            written++;
        }
    }
    return written;
}

/* Count the number of characters in a string that do not match a provided
 * mask. */
size_t strmask(char *str, char *mask) {
    char maskbuff[256];
    memset(maskbuff, 0, sizeof(maskbuff));
    char ch, *ptr;
    size_t result = 0;

    /* Set mask */
    ptr = mask;
    while ((ch = *ptr)) {
        maskbuff[(int)ch] = 1;
        ptr++;
    }

    /* Loop string, count mismatches */
    ptr = str;
    while ((ch = *ptr)) {
        if (!maskbuff[(int)ch]) {
            result++;
        }
        ptr++;
    }

    return result;
}

/* strdup is not a standard C function, so provide own implementation. */
char* cx_strdup(const char* str) {
    char *result = cx_malloc(strlen(str) + 1);
    strcpy(result, str);
    return result;
}

/**
 * From:
 * `asprintf.c' - asprintf
 *
 * copyright (c) 2014 joseph werle <joseph.werle@gmail.com>
 */

int cx_asprintf (char **str, const char *fmt, ...) {
    int size = 0;
    va_list args;

    va_start(args, fmt);

    size = cx_vasprintf(str, fmt, args);

    va_end(args);

    return size;
}

int cx_vasprintf (char **str, const char *fmt, va_list args) {
    int size = 0;
    va_list tmpa;

    va_copy(tmpa, args);

    size = vsnprintf(NULL, size, fmt, tmpa);

    va_end(tmpa);

    // return -1 to be compliant if
    // size is less than 0
    if (size < 0) { return -1; }

    // alloc with size plus 1 for `\0'
    *str = (char *) malloc(size + 1);

    // return -1 to be compliant
    // if pointer is `NULL'
    if (NULL == *str) { return -1; }

    // format string with original
    // variadic arguments and set new size
    size = vsprintf(*str, fmt, args);
    return size;
}
