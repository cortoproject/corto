#ifndef DB_STRING_H_
#define DB_STRING_H_

#include "string.h"
#include <stdarg.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Case insensitive string compare */
CORTO_EXPORT int stricmp(const char *str1, const char *str2);

/* Compare case insensitive token */
CORTO_EXPORT int tokicmp(char ** const str_out, const char *str2, char tok);

/* Case insensitive string compare, stop at / instead of \0. Returns next
 * element, NULL when no match or "\0" when reached the end */
CORTO_EXPORT char* corto_elemcmp(char *path, char *elem);

/* Search element separator in id string. Stop when argument list is found. */
char *corto_strelem(char *str);

/* Convert characters in string to uppercase */
CORTO_EXPORT char* corto_strupper(char *str);

/* Convert characters in string to lowercase */
CORTO_EXPORT char* corto_strlower(char *str);

CORTO_EXPORT char *strappend(char *src, char *fmt, ...);
CORTO_EXPORT char *itostr(int value, char *result, int base);
CORTO_EXPORT char *utostr(unsigned int value, char *result, int base);

/*
 * Escapes a character `in` and prints it to `out`. Does not not include
 * surrounding single quotes.
 * Returns the next available location to write, usually out+1 or out+2.
 */
CORTO_EXPORT char *chresc(char *out, char in, char delimiter);

/*
 * Escapes a null-terminated string `in` and attempts to print it to `out`.
 * Does not include surrounding double quotes.
 * The maximum number of characters to be printed is `n` including the null
 * character, but it may be less if the following character requires escaping.
 * The resulting string is null terminated.
 */
CORTO_EXPORT size_t stresc(char *out, size_t n, const char *in);

/* Count the number of characters in a string that do not match a provided
 * mask. */
CORTO_EXPORT size_t strmask(char *str, char *mask);

/* Duplicate string */
CORTO_EXPORT char* corto_strdup(const char* str);

/* sprintf with automatic allocation */
CORTO_EXPORT int corto_asprintf (char **str, const char *fmt, ...);
CORTO_EXPORT int corto_vasprintf (char **str, const char *fmt, va_list args);

/* Replace substring in string */
CORTO_EXPORT char* corto_replace(char *s, char *old, char *_new);

#ifdef __cplusplus
}
#endif

#endif /* DB_STRING_H_ */
