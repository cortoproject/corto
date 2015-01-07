#ifndef DB_STRING_H_
#define DB_STRING_H_

#include "string.h"

#ifdef __cplusplus
extern "C" {
#endif

int stricmp(const char *str1, const char *str2);
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
 * The recommended length to allocate for the buffer can be obtained with
 * `stresclen`, adding 2 if you surrounding double quotes.
 * The resulting string is null terminated.
 */
size_t stresc(char *out, size_t n, const char *in);

#ifdef __cplusplus
}
#endif

#endif /* DB_STRING_H_ */
