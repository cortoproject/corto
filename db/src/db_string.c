/*
 * db_string.c
 *
 *  Created on: Dec 27, 2012
 *      Author: sander
 */

#include "stdarg.h"
#include "db_string.h"
#include "db_mem.h"

int stricmp(const char* str1, const char* str2) {
	return strcasecmp(str1, str2);
}

void strtoupper(char* ch) {
	if ((*ch >= 97) && (*ch <= 122)) {
		*ch -= 32;
	}
}

void strtolower(char* ch) {
	if ((*ch >= 65) && (*ch <= 90)) {
		*ch += 32;
	}
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

	src = db_realloc(src, sourceLength + strlen(buff) + 1);
	strcpy(&src[sourceLength], buff);

	return src;
}

/**
 * C++ version 0.4 char* style "itoa":
 * Written by Lukás Chmela
 * Released under GPLv3.
 */
char *itostr(int value, char* result, int base) {
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

char *utostr(unsigned int value, char* result, int base) {
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

char *stresc(char in, char* out, char delimiter) {
	char *bptr = out;

    switch(in) {
    case '\a':
        *bptr = '\\';
        *(++bptr) = 'a';
        break;
    case '\b':
        *bptr = '\\';
        *(++bptr) = 'b';
        break;
    case '\f':
        *bptr = '\\';
        *(++bptr) = 'f';
        break;
    case '\n':
        *bptr = '\\';
        *(++bptr) = 'n';
        break;
    case '\r':
        *bptr = '\\';
        *(++bptr) = 'r';
        break;
    case '\t':
        *bptr = '\\';
        *(++bptr) = 't';
        break;
    case '\v':
        *bptr = '\\';
        *(++bptr) = 'a';
        break;
    case '\\':
        *bptr = '\\';
        *(++bptr) = '\\';
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
    bptr++;

    return bptr;
}


