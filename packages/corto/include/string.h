#ifndef DB_STRING_H_
#define DB_STRING_H_

#include "string.h"
#include <stdarg.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Case insensitive string compare */
int stricmp(const char *str1, const char *str2);

/* Convert characters in string to uppercase */
char* corto_strupper(char *str);

/* Convert characters in string to lowercase */
char* corto_strlower(char *str);

char *strappend(char *src, char *fmt, ...);
char *itostr(int value, char *result, int base);
char *utostr(unsigned int value, char *result, int base);

/*
 * Escapes a character `in` and prints it to `out`. Does not not include
 * surrounding single quotes.
 * Returns the next available location to write, usually out+1 or out+2.
 */
char *chresc(char *out, char in, char delimiter);

/*
 * Escapes a null-terminated string `in` and attempts to print it to `out`.
 * Does not include surrounding double quotes.
 * The maximum number of characters to be printed is `n` including the null
 * character, but it may be less if the following character requires escaping.
 * The resulting string is null terminated.
 */
size_t stresc(char *out, size_t n, const char *in);

/* Count the number of characters in a string that do not match a provided
 * mask. */
size_t strmask(char *str, char *mask);

/* Duplicate string */
char* corto_strdup(const char* str);

/* sprintf with automatic allocation */
int corto_asprintf (char **str, const char *fmt, ...);
int corto_vasprintf (char **str, const char *fmt, va_list args);

/* Replace substring in string */
char* corto_replace(char *orig, char *rep, char *with);

#ifdef __cplusplus
}
#endif

#endif /* DB_STRING_H_ */
