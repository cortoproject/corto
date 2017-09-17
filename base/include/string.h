/* Copyright (c) 2010-2017 the corto developers
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

/** @file
 * @section string utility functions.
 * @brief Various platform-independent functions for performing string operations.
 */

#ifndef CORTO_STRING_H_
#define CORTO_STRING_H_

#ifdef __cplusplus
extern "C" {
#endif

/** Compare strings insensitive of case.
 * 
 * @param str1 First string to compare
 * @param str2 Second string to compare
 * @return -1 if first unmatched character is smaller, 1 if larger and 0 if strings are equal.
 */
CORTO_EXPORT 
int stricmp(
    const char *str1, 
    const char *str2);

/** Compare fixed number of characters in strings insensitive of case.
 * 
 * @param str1 First string to compare
 * @param length Number of characters to compare
 * @param str2 Second string to compare
 * @return -1 if first unmatched character is smaller, 1 if larger and 0 if strings are equal.
 */
CORTO_EXPORT 
int strnicmp(
    const char *str1, 
    int length, const 
    char *str2);

/** Compare strings insensitive of case until specified character is found. 
 * This function is useful when comparing tokens in a string that are separated
 * by a single character. This function can also be used to compare regular strings
 * by specifying the null terminator for 'tok'. This has as advantage that the
 * caller will know at which location the strings were no longer the same.
 *
 * @param str_out First string to compare. After calling function, this will point to first unmatched character. 
 * @param str2 Second string to compare.
 * @param tok Character used to separate tokens. 
 * @return -1 if first unmatched character is smaller, 1 if larger and 0 if strings are equal. 
 */
CORTO_EXPORT 
int tokicmp(
    char ** const str_out, 
    const char *str2, 
    char tok);

/** Append string to source string.
 * This function modifies the source string with a realloc.
 *
 * @param src Source string.
 * @param fmt printf-compatible format specifier.
 * @return Source string. Pointer of source string may have changed as this function uses realloc.
 */
CORTO_EXPORT 
char *strappend(
    char *src, 
    char *fmt, ...);

/** Escape a character.
 * Escapes a character `in` and writes it to `out`. Does not not include
 * surrounding single quotes. Returns the next available location to write, 
 * usually out+1 (no escaping) or out+2 (character was escaped).
 *
 * @param out The string to write the escape sequence to.
 * @param in The character to escape.
 * @param delimiter Custom escapable character.
 * @return Next writable location in out string.
 */
CORTO_EXPORT 
char *chresc(
    char *out, 
    char in, 
    char delimiter);

/* Escape a null-terminated string.
 * Escapes a null-terminated string `in` and attempts to print it to `out`.
 * The maximum number of characters to be printed is `n` including the null
 * character, but it may be less if the following character requires escaping.
 * The resulting string is null terminated. When 0 is provided for n, the 
 * function will return the number of characters required in the out string.
 *
 * @param out Output string.
 * @param n Maximum number of characters to write to output string.
 * @param in Input string.
 * @return Number of characters written in output string.
 */
CORTO_EXPORT 
size_t stresc(
    char *out, 
    size_t n, 
    const char *in);

/** Assign one string to another string without leaking memory.
 *
 * @param out Output string.
 * @param str Input string.
 */
CORTO_EXPORT 
void strset(
    char **out, 
    const char *str);

/** Returns printf-formatted string that does not need deallocation.
 * This function utilizes internal buffers to build a string according to printf
 * style formatting. The output of this function does not need to be deallocated
 * and the function can therefore be used in a function argument. Up to 
 * CORTO_MAX_TLS_STRINGS strings can be used per thread.
 * 
 * @param fmt printf-style format string.
 * @return String formatted according to input. Does not need to be deallocated. The value will be
 * overwritten when function is called more than CORTO_MAX_TLS_STRINGS times in a thread. 
 */
CORTO_EXPORT 
char* strarg(
    const char *fmt, 
    ...);

/** Find elements in a string, separated by '/'.
 * The function returns the next element, where elements are separated by a '/'.
 * When the function encounters a '(' (argument list) it returns NULL.
 *
 * @param str Input string.
 * @return The next element when a '/' was found, otherwise NULL. 
 */
CORTO_EXPORT
char *strelem(
    char *str);

/** Convert characters in string to uppercase.
 *
 * @param str String to convert.
 * @return Input string.
 */
CORTO_EXPORT 
char* strupper(
    char *str);

/** Convert characters in string to lowercase.
 * 
 * @param str String to convert.
 * @return Input string.
 */
CORTO_EXPORT 
char* strlower(
    char *str);

/** Duplicate string.
 *
 * @param str Input string.
 * @return Duplicated string.
 */
CORTO_EXPORT 
char* corto_strdup(
    const char* str);

/** sprintf with automatic allocation.
 * 
 * @param fmt printf-style format specifier. 
 * @return Newly allocated formatted string.
 */
CORTO_EXPORT 
char* corto_asprintf (
    const char *fmt, ...);

/** vsprintf with automatic allocation.
 * 
 * @param fmt printf-style format specifier.
 * @args variable argument list.
 * @return Newly allocated formatted string.
 */
CORTO_EXPORT 
char* corto_vasprintf (
    const char *fmt, 
    va_list args);

/** Replace substring with other string.
 *  
 * @param str Input string.
 * @param replace To be replaced string.
 * @param with String to replace with.
 * @return Newly allocated string with all instances of 'replace' replaced.
 */
CORTO_EXPORT 
char* strreplace(
    char *str, 
    char *replace, 
    char *with);

#ifdef __cplusplus
}
#endif

#endif