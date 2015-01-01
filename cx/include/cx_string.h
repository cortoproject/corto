/*
 * cx_string.h
 *
 *  Created on: Dec 27, 2012
 *      Author: sander
 */

#ifndef CX_STRING_H_
#define CX_STRING_H_

#include "string.h"

#ifdef __cplusplus
extern "C" {
#endif

int stricmp(const char* str1, const char* str2);
void strtoupper(char* ch);
void strtolower(char* ch);
char *strappend(char *src, char *fmt, ...);
char *itostr(int value, char* result, int base);
char *utostr(unsigned int value, char* result, int base);
char *stresc(char in, char* out, char delimiter);

#ifdef __cplusplus
}
#endif

#endif /* CX_STRING_H_ */
