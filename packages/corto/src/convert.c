/*
 * corto_convert.c
 *
 *  Created on: Aug 23, 2012
 *      Author: sander
 */

#include "corto/corto.h"
#include "lang/_primitive.h"

#ifdef CORTO_CONVERSIONS

typedef corto_int16 ___ (*corto_conversion)(corto_primitive fromType, void* from, corto_primitive toType, void* to);

static corto_conversion _conversions[CORTO_PRIMITIVE_MAX_CONVERTID+1][CORTO_PRIMITIVE_MAX_CONVERTID+1];

/* Conversion functionname */
#define CORTO_NAME_TRANSFORM(from, to) __corto_##from##_##to##_convert

/* Templates for transformator functions */
#define CORTO_DECL_TRANSFORM(typeFrom, typeTo) static corto_int16 CORTO_NAME_TRANSFORM(typeFrom, typeTo) (corto_primitive fromType, void* from, corto_primitive toType, void* to)

/* Conversion typedefs for char and floating point types (integer types come from stdint.h) */
typedef char char8_t;
typedef wchar_t char16_t;
typedef float float32_t;
typedef double float64_t;
typedef corto_int8 bin8_t;
typedef corto_int16 bin16_t;
typedef corto_int32 bin32_t;
typedef corto_int64 bin64_t;
typedef corto_word word_t;
typedef corto_bool bool_t;

/* Conversions between numeric types */
#define CORTO_CONVERT_NUM(typeFrom, typeTo) \
    CORTO_DECL_TRANSFORM(typeFrom, typeTo) {\
        CORTO_UNUSED(fromType);\
        CORTO_UNUSED(toType);\
        *(typeTo##_t*)to = *(typeFrom##_t*)from;\
        return 0;\
    }

/* Conversions between numeric and boolean types */
#define CORTO_CONVERT_BOOL(typeFrom, typeTo) \
    CORTO_DECL_TRANSFORM(typeFrom, typeTo) {\
        CORTO_UNUSED(fromType);\
        CORTO_UNUSED(toType);\
        if (*(typeFrom##_t*)from) {\
            *(typeTo##_t*)to = TRUE;\
        } else {\
            *(typeTo##_t*)to = FALSE;\
        }\
        return 0;\
    }

/* Conversions to string */
#define CORTO_CONVERT_TO_STR(typeFrom, fmt) \
    CORTO_DECL_TRANSFORM(typeFrom,string) {\
        char* str = corto_alloc(128);\
        CORTO_UNUSED(fromType);\
        CORTO_UNUSED(toType);\
        sprintf(str, fmt, *(typeFrom##_t*)from);\
        *(corto_string*)to = str;\
        return 0;\
    }

/* Transformation from string to char */
#define CORTO_CONVERT_FROM_STR_CHAR(typeTo) \
    CORTO_DECL_TRANSFORM(string, typeTo) {\
        CORTO_UNUSED(fromType);\
        CORTO_UNUSED(toType);\
        *(typeTo##_t*)to = **(corto_string*)from;\
        return 0;\
    }

/* Transformation from string to int */
#define CORTO_CONVERT_FROM_STR_INT(typeTo) \
    CORTO_DECL_TRANSFORM(string, typeTo) {\
        CORTO_UNUSED(fromType);\
        CORTO_UNUSED(toType);\
        *(typeTo##_t*)to = atol(*(corto_string*)from);\
        return 0;\
    }

/* Transformation from string long uint */
#define CORTO_CONVERT_FROM_STR_LONGINT(typeTo) \
    CORTO_DECL_TRANSFORM(string, typeTo) {\
        CORTO_UNUSED(fromType);\
        CORTO_UNUSED(toType);\
        sscanf(*(corto_string*)from, "%" PRIu64, (typeTo##_t*)to);\
        return 0;\
    }

/* Transformation from string to float */
#define CORTO_CONVERT_FROM_STR_FLOAT(typeTo) \
    CORTO_DECL_TRANSFORM(string, typeTo) {\
        CORTO_UNUSED(fromType);\
        CORTO_UNUSED(toType);\
        *(typeTo##_t*)to = atof(*(corto_string*)from);\
        return 0;\
    }

/* string to string */
CORTO_DECL_TRANSFORM(string, string) {
    CORTO_UNUSED(toType);
    CORTO_UNUSED(fromType);
    if (*(corto_string*)from) {
        *(corto_string*)to = corto_strdup(*(corto_string*)from);
    } else {
        *(corto_string*)to = NULL;
    }
    return 0;
}

/* boolean to string */
CORTO_DECL_TRANSFORM(boolean, string) {
    CORTO_UNUSED(toType);
    CORTO_UNUSED(fromType);

    if (*(corto_bool*)from) {
        *(corto_string*)to = corto_strdup("true");
    } else {
        *(corto_string*)to = corto_strdup("false");
    }
    return 0;
}

/* string to octet */
CORTO_DECL_TRANSFORM(string, octet) {
    CORTO_UNUSED(toType);
    CORTO_UNUSED(fromType);
    *(corto_octet*)to = (corto_int64)strtol(*(corto_string*)from, NULL, 16);
    return 0;
}

/* string to boolean */
CORTO_DECL_TRANSFORM(string, boolean) {
    corto_string str;
    CORTO_UNUSED(toType);
    CORTO_UNUSED(fromType);
    str = *(corto_string*)from;
    if (!strcmp(str, "TRUE") || !strcmp(str, "true")) {
        *(corto_bool*)to = TRUE;
    } else if (!strcmp(str, "FALSE") || !strcmp(str, "false")) {
        *(corto_bool*)to = FALSE;
    } else {
        corto_seterr("'%s' is not a valid boolean value", str);
        return -1;
    }
    return 0;
}

/* enum to string */
CORTO_DECL_TRANSFORM(enum, string) {
    corto_object constant;
    CORTO_UNUSED(toType);
    constant = corto_enum_constant((corto_enum)fromType, *(corto_int32*)from);
    if (!constant) {
        corto_seterr("value %d is not valid for enumeration '%s'",
            *(corto_uint32*)from,
            corto_fullpath(NULL, fromType));
        return -1;
    }
    *(corto_string*)to = corto_strdup(corto_nameof(constant));
    return 0;
}

/* string to enum */
CORTO_DECL_TRANSFORM(string, enum) {
    corto_constant* o;
    CORTO_UNUSED(fromType);
    o = corto_resolve(toType, *(corto_string*)from);
    if (!o) {
        corto_seterr(
            "constant identifier '%s' is not valid for enumeration '%s'",
            *(corto_string*)from,
            corto_fullpath(NULL, toType));
        goto error;
    } else {
        *(corto_int32*)to = *o;
        corto_release(o);
    }
    return 0;
error:
    return -1;
}

/* enum to int */
CORTO_DECL_TRANSFORM(enum, int32) {
    CORTO_UNUSED(fromType);
    CORTO_UNUSED(toType);
    *(corto_int32*)to = *(corto_constant*)from;
    return 0;
}

/* int to enum */
CORTO_DECL_TRANSFORM(int32, enum) {
    CORTO_UNUSED(fromType);
    CORTO_UNUSED(toType);
    *(corto_constant*)to = *(corto_int32*)from;
    return 0;
}

/* enum to int */
CORTO_DECL_TRANSFORM(enum, int64) {
    CORTO_UNUSED(fromType);
    CORTO_UNUSED(toType);
    *(corto_int64*)to = *(corto_constant*)from;
    return 0;
}

/* int to enum */
CORTO_DECL_TRANSFORM(int64, enum) {
    CORTO_UNUSED(fromType);
    CORTO_UNUSED(toType);
    *(corto_constant*)to = *(corto_int64*)from;
    return 0;
}

/* bitmask to string */
CORTO_DECL_TRANSFORM(bitmask, string) {
    corto_object constant;
    corto_constant v, cv;
    corto_uint32 i, length;
    corto_string result;
    CORTO_UNUSED(toType);

    v = *(corto_constant*)from;
    result = NULL;
    length = 1; /* 0-terminator */


    for(i=0; i<corto_enum(fromType)->constants.length;i++) {
        constant = corto_enum(fromType)->constants.buffer[i];
        cv = *(corto_constant*)constant;

        if ((((cv & v) == cv) && cv) || !(cv | v)) {
            length += strlen(corto_nameof(constant));
            if (!result) {
                result = corto_realloc(result, length);
                *result = '\0';
            } else {
                length+=1;
                result = corto_realloc(result, length);
                strcat(result, "|");
            }

            strcat(result, corto_nameof(constant));
        }
    }

    if (!result) {
        result = corto_strdup("0");
    }

    *(corto_string*)to = result;

    return 0;
}

/* string to bitmask */
CORTO_DECL_TRANSFORM(string, bitmask) {
    corto_id buffer;
    corto_string fromstr;
    corto_char *ptr, *bptr, ch;
    corto_constant v;
    corto_object constant;

    CORTO_UNUSED(fromType);

    fromstr = *(corto_string*)from;
    bptr = buffer;
    ptr = fromstr;
    v = 0;

    ch = *ptr;
    if (ch) { /* If no value is provided, result is 0 */
        do {
            switch(ch) {
            case '|':
            case '\0':
                *bptr = '\0';
                constant = corto_lookup(toType, buffer);
                if (!constant) {
                    corto_seterr(
                        "constant identifier '%s' is not valid for bitmask '%s'.",
                        buffer, corto_fullpath(NULL, toType));
                    v = 0;
                    goto error;
                }

                /* 'or' constant-value with resultvalue. */
                v |= *(corto_constant*)constant;
                bptr = buffer;

                corto_release(constant);

                break;
            default:
                *bptr = ch;
                bptr++;
                break;
            }
            if (ch == '\0') {
                break;
            }
            ptr++;
            ch = *ptr;
        }while(1);
    }

    *(corto_constant*)to = v;

    return 0;
error:
    return -1;
}

/* All conversion functions for numeric types */
#define CORTO_CONVERT_NUM_ALL(fromType, fmt)\
    CORTO_CONVERT_NUM(fromType,char8)\
    CORTO_CONVERT_NUM(fromType,int8)\
    CORTO_CONVERT_NUM(fromType,int16)\
    CORTO_CONVERT_NUM(fromType,int32)\
    CORTO_CONVERT_NUM(fromType,int64)\
    CORTO_CONVERT_NUM(fromType,intptr)\
    CORTO_CONVERT_NUM(fromType,uint8)\
    CORTO_CONVERT_NUM(fromType,uint16)\
    CORTO_CONVERT_NUM(fromType,uint32)\
    CORTO_CONVERT_NUM(fromType,uint64)\
    CORTO_CONVERT_NUM(fromType,uintptr)\
    CORTO_CONVERT_NUM(fromType,float32)\
    CORTO_CONVERT_NUM(fromType,float64)\
    CORTO_CONVERT_BOOL(fromType, bool)\
    CORTO_CONVERT_TO_STR(fromType, fmt)

/* Conversion functions for integer types */
#define CORTO_CONVERT_NUM_INT(fromType, fmt)\
    CORTO_CONVERT_NUM(fromType,uint8)\
    CORTO_CONVERT_NUM(fromType,uint16)\
    CORTO_CONVERT_NUM(fromType,uint32)\
    CORTO_CONVERT_NUM(fromType,uint64)\
    CORTO_CONVERT_NUM(fromType,uintptr)\
    CORTO_CONVERT_NUM(fromType,float32)\
    CORTO_CONVERT_NUM(fromType,float64)\
    CORTO_CONVERT_BOOL(fromType, bool)\
    CORTO_CONVERT_TO_STR(fromType, fmt)

CORTO_CONVERT_NUM_INT(bool, "%d")
CORTO_CONVERT_NUM_INT(char8, "%c")
CORTO_CONVERT_NUM_INT(int8, "%" PRId8)
CORTO_CONVERT_NUM_INT(int16, "%" PRId16)
CORTO_CONVERT_NUM_INT(int32, "%" PRId32)
CORTO_CONVERT_NUM_INT(int64, "%" PRId64)
CORTO_CONVERT_NUM_INT(intptr, "%" PRIdPTR)
CORTO_CONVERT_NUM_INT(uint8, "%" PRIu8)
CORTO_CONVERT_NUM_INT(uint16, "%" PRIu16)
CORTO_CONVERT_NUM_INT(uint32, "%" PRIu32)
CORTO_CONVERT_NUM_INT(uint64, "%" PRIu64)
CORTO_CONVERT_NUM_INT(uintptr, "%" PRIuPTR)
CORTO_CONVERT_NUM_ALL(float32, "%f")
CORTO_CONVERT_NUM_ALL(float64, "%f")
CORTO_CONVERT_TO_STR(bin8, "0x%hhx")
CORTO_CONVERT_TO_STR(bin16, "0x%" PRIx16)
CORTO_CONVERT_TO_STR(bin32, "0x%" PRIx32)
CORTO_CONVERT_TO_STR(bin64, "0x%" PRIx64)
CORTO_CONVERT_NUM_ALL(word, "0x%" PRIxPTR)

/* All string to character conversions */
CORTO_CONVERT_FROM_STR_CHAR(char8)

/* All string to integer conversions */
CORTO_CONVERT_FROM_STR_INT(int8)
CORTO_CONVERT_FROM_STR_INT(int16)
CORTO_CONVERT_FROM_STR_INT(int32)
CORTO_CONVERT_FROM_STR_INT(int64)
CORTO_CONVERT_FROM_STR_INT(uint8)
CORTO_CONVERT_FROM_STR_INT(uint16)
CORTO_CONVERT_FROM_STR_INT(uint32)
CORTO_CONVERT_FROM_STR_LONGINT(uint64)

/* All string to float conversions */
CORTO_CONVERT_FROM_STR_FLOAT(float32)
CORTO_CONVERT_FROM_STR_FLOAT(float64)

/* Init numeric conversion slot */
#define CORTO_CONVERT_INIT_NUM(kind, width, toKind, toWidth, fromType, toType)\
    _conversions[corto__primitive_convertId(kind, width)][corto__primitive_convertId(toKind, toWidth)] = CORTO_NAME_TRANSFORM(fromType, toType)

/* All numeric conversion slots */
#define CORTO_CONVERT_INIT_NUM_ALL(kind, width, type)\
    CORTO_CONVERT_INIT_NUM(kind, width, CORTO_BOOLEAN, CORTO_WIDTH_8, type, bool);\
    CORTO_CONVERT_INIT_NUM(kind, width, CORTO_BINARY, CORTO_WIDTH_8, type, uint8);\
    CORTO_CONVERT_INIT_NUM(kind, width, CORTO_BINARY, CORTO_WIDTH_16, type, uint16);\
    CORTO_CONVERT_INIT_NUM(kind, width, CORTO_BINARY, CORTO_WIDTH_32, type, uint32);\
    CORTO_CONVERT_INIT_NUM(kind, width, CORTO_BINARY, CORTO_WIDTH_64, type, uint64);\
    CORTO_CONVERT_INIT_NUM(kind, width, CORTO_BINARY, CORTO_WIDTH_WORD, type, uintptr);\
    CORTO_CONVERT_INIT_NUM(kind, width, CORTO_CHARACTER, CORTO_WIDTH_8, type, char8);\
    CORTO_CONVERT_INIT_NUM(kind, width, CORTO_INTEGER, CORTO_WIDTH_8, type, int8);\
    CORTO_CONVERT_INIT_NUM(kind, width, CORTO_INTEGER, CORTO_WIDTH_16, type, int16);\
    CORTO_CONVERT_INIT_NUM(kind, width, CORTO_INTEGER, CORTO_WIDTH_32, type, int32);\
    CORTO_CONVERT_INIT_NUM(kind, width, CORTO_INTEGER, CORTO_WIDTH_64, type, int64);\
    CORTO_CONVERT_INIT_NUM(kind, width, CORTO_INTEGER, CORTO_WIDTH_WORD, type, intptr);\
    CORTO_CONVERT_INIT_NUM(kind, width, CORTO_UINTEGER, CORTO_WIDTH_8, type, uint8);\
    CORTO_CONVERT_INIT_NUM(kind, width, CORTO_UINTEGER, CORTO_WIDTH_16, type, uint16);\
    CORTO_CONVERT_INIT_NUM(kind, width, CORTO_UINTEGER, CORTO_WIDTH_32, type, uint32);\
    CORTO_CONVERT_INIT_NUM(kind, width, CORTO_UINTEGER, CORTO_WIDTH_64, type, uint64);\
    CORTO_CONVERT_INIT_NUM(kind, width, CORTO_UINTEGER, CORTO_WIDTH_WORD, type, uintptr);\
    CORTO_CONVERT_INIT_NUM(kind, width, CORTO_FLOAT, CORTO_WIDTH_32, type, float32);\
    CORTO_CONVERT_INIT_NUM(kind, width, CORTO_FLOAT, CORTO_WIDTH_64, type, float64);\
    CORTO_CONVERT_INIT_NUM(kind, width, CORTO_TEXT, CORTO_WIDTH_WORD, type, string);\

/* Numeric conversion slots for integers */
#define CORTO_CONVERT_INIT_NUM_INT(kind, width, type)\
    CORTO_CONVERT_INIT_NUM(kind, width, CORTO_BOOLEAN, CORTO_WIDTH_8, type, bool);\
    CORTO_CONVERT_INIT_NUM(kind, width, CORTO_BINARY, CORTO_WIDTH_8, type, uint8);\
    CORTO_CONVERT_INIT_NUM(kind, width, CORTO_BINARY, CORTO_WIDTH_16, type, uint16);\
    CORTO_CONVERT_INIT_NUM(kind, width, CORTO_BINARY, CORTO_WIDTH_32, type, uint32);\
    CORTO_CONVERT_INIT_NUM(kind, width, CORTO_BINARY, CORTO_WIDTH_64, type, uint64);\
    CORTO_CONVERT_INIT_NUM(kind, width, CORTO_BINARY, CORTO_WIDTH_WORD, type, uintptr);\
    CORTO_CONVERT_INIT_NUM(kind, width, CORTO_CHARACTER, CORTO_WIDTH_8, type, uint8);\
    CORTO_CONVERT_INIT_NUM(kind, width, CORTO_INTEGER, CORTO_WIDTH_8, type, uint8);\
    CORTO_CONVERT_INIT_NUM(kind, width, CORTO_INTEGER, CORTO_WIDTH_16, type, uint16);\
    CORTO_CONVERT_INIT_NUM(kind, width, CORTO_INTEGER, CORTO_WIDTH_32, type, uint32);\
    CORTO_CONVERT_INIT_NUM(kind, width, CORTO_INTEGER, CORTO_WIDTH_64, type, uint64);\
    CORTO_CONVERT_INIT_NUM(kind, width, CORTO_INTEGER, CORTO_WIDTH_WORD, type, uintptr);\
    CORTO_CONVERT_INIT_NUM(kind, width, CORTO_UINTEGER, CORTO_WIDTH_8, type, uint8);\
    CORTO_CONVERT_INIT_NUM(kind, width, CORTO_UINTEGER, CORTO_WIDTH_16, type, uint16);\
    CORTO_CONVERT_INIT_NUM(kind, width, CORTO_UINTEGER, CORTO_WIDTH_32, type, uint32);\
    CORTO_CONVERT_INIT_NUM(kind, width, CORTO_UINTEGER, CORTO_WIDTH_64, type, uint64);\
    CORTO_CONVERT_INIT_NUM(kind, width, CORTO_UINTEGER, CORTO_WIDTH_WORD, type, uintptr);\
    CORTO_CONVERT_INIT_NUM(kind, width, CORTO_FLOAT, CORTO_WIDTH_32, type, float32);\
    CORTO_CONVERT_INIT_NUM(kind, width, CORTO_FLOAT, CORTO_WIDTH_64, type, float64);\
    CORTO_CONVERT_INIT_NUM(kind, width, CORTO_TEXT, CORTO_WIDTH_WORD, type, string);\

/* Init conversions */
void corto_convertInit(void) {
    CORTO_CONVERT_INIT_NUM_INT(CORTO_BOOLEAN, CORTO_WIDTH_8, bool);
    CORTO_CONVERT_INIT_NUM_INT(CORTO_BINARY, CORTO_WIDTH_8, uint8);
    CORTO_CONVERT_INIT_NUM_INT(CORTO_BINARY, CORTO_WIDTH_16, int16);
    CORTO_CONVERT_INIT_NUM_INT(CORTO_BINARY, CORTO_WIDTH_32, uint32);
    CORTO_CONVERT_INIT_NUM_INT(CORTO_BINARY, CORTO_WIDTH_64, uint64);
    CORTO_CONVERT_INIT_NUM_ALL(CORTO_BINARY, CORTO_WIDTH_WORD, word);
    CORTO_CONVERT_INIT_NUM_INT(CORTO_CHARACTER, CORTO_WIDTH_8, char8);
    CORTO_CONVERT_INIT_NUM_INT(CORTO_INTEGER, CORTO_WIDTH_8, int8);
    CORTO_CONVERT_INIT_NUM_INT(CORTO_INTEGER, CORTO_WIDTH_16, int16);
    CORTO_CONVERT_INIT_NUM_INT(CORTO_INTEGER, CORTO_WIDTH_32, int32);
    CORTO_CONVERT_INIT_NUM_INT(CORTO_INTEGER, CORTO_WIDTH_64, int64);
    CORTO_CONVERT_INIT_NUM_INT(CORTO_INTEGER, CORTO_WIDTH_WORD, intptr);
    CORTO_CONVERT_INIT_NUM_INT(CORTO_UINTEGER, CORTO_WIDTH_8, uint8);
    CORTO_CONVERT_INIT_NUM_INT(CORTO_UINTEGER, CORTO_WIDTH_16, uint16);
    CORTO_CONVERT_INIT_NUM_INT(CORTO_UINTEGER, CORTO_WIDTH_32, uint32);
    CORTO_CONVERT_INIT_NUM_INT(CORTO_UINTEGER, CORTO_WIDTH_64, uint64);
    CORTO_CONVERT_INIT_NUM_INT(CORTO_UINTEGER, CORTO_WIDTH_WORD, uintptr);
    CORTO_CONVERT_INIT_NUM_ALL(CORTO_FLOAT, CORTO_WIDTH_32, float32);
    CORTO_CONVERT_INIT_NUM_ALL(CORTO_FLOAT, CORTO_WIDTH_64, float64);

    /* Binary to string */
    CORTO_CONVERT_INIT_NUM(CORTO_BINARY, CORTO_WIDTH_8, CORTO_TEXT, CORTO_WIDTH_WORD, bin8, string);
    CORTO_CONVERT_INIT_NUM(CORTO_BINARY, CORTO_WIDTH_16, CORTO_TEXT, CORTO_WIDTH_WORD, bin16, string);
    CORTO_CONVERT_INIT_NUM(CORTO_BINARY, CORTO_WIDTH_32, CORTO_TEXT, CORTO_WIDTH_WORD, bin32, string);
    CORTO_CONVERT_INIT_NUM(CORTO_BINARY, CORTO_WIDTH_64, CORTO_TEXT, CORTO_WIDTH_WORD, bin64, string);

    /* boolean to string & vice versa */
    CORTO_CONVERT_INIT_NUM(CORTO_BOOLEAN, CORTO_WIDTH_8, CORTO_TEXT, CORTO_WIDTH_WORD, boolean, string);
    CORTO_CONVERT_INIT_NUM(CORTO_TEXT, CORTO_WIDTH_WORD, CORTO_BOOLEAN, CORTO_WIDTH_8, string, boolean);

    /* enum to string & vice versa */
    CORTO_CONVERT_INIT_NUM(CORTO_ENUM, CORTO_WIDTH_32, CORTO_TEXT, CORTO_WIDTH_WORD, enum, string);
    CORTO_CONVERT_INIT_NUM(CORTO_TEXT, CORTO_WIDTH_WORD, CORTO_ENUM, CORTO_WIDTH_32, string, enum);

    /* enum to int & vice versa */
    CORTO_CONVERT_INIT_NUM(CORTO_ENUM, CORTO_WIDTH_32, CORTO_INTEGER, CORTO_WIDTH_32, enum, int32);
    CORTO_CONVERT_INIT_NUM(CORTO_INTEGER, CORTO_WIDTH_32, CORTO_ENUM, CORTO_WIDTH_32, int32, enum);
    CORTO_CONVERT_INIT_NUM(CORTO_ENUM, CORTO_WIDTH_32, CORTO_INTEGER, CORTO_WIDTH_64, enum, int64);
    CORTO_CONVERT_INIT_NUM(CORTO_INTEGER, CORTO_WIDTH_64, CORTO_ENUM, CORTO_WIDTH_32, int64, enum);
    CORTO_CONVERT_INIT_NUM(CORTO_ENUM, CORTO_WIDTH_32, CORTO_UINTEGER, CORTO_WIDTH_64, enum, int64);
    CORTO_CONVERT_INIT_NUM(CORTO_UINTEGER, CORTO_WIDTH_64, CORTO_ENUM, CORTO_WIDTH_32, int64, enum);

    /* bitmask to string & vice versa */
    CORTO_CONVERT_INIT_NUM(CORTO_BITMASK, CORTO_WIDTH_32, CORTO_TEXT, CORTO_WIDTH_WORD, bitmask, string);
    CORTO_CONVERT_INIT_NUM(CORTO_TEXT, CORTO_WIDTH_WORD, CORTO_BITMASK, CORTO_WIDTH_32, string, bitmask);

    /* bitmask to int & vice versa */
    CORTO_CONVERT_INIT_NUM(CORTO_BITMASK, CORTO_WIDTH_32, CORTO_INTEGER, CORTO_WIDTH_32, enum, int32);
    CORTO_CONVERT_INIT_NUM(CORTO_INTEGER, CORTO_WIDTH_32, CORTO_BITMASK, CORTO_WIDTH_32, int32, enum);
    CORTO_CONVERT_INIT_NUM(CORTO_BITMASK, CORTO_WIDTH_32, CORTO_INTEGER, CORTO_WIDTH_64, enum, int64);
    CORTO_CONVERT_INIT_NUM(CORTO_INTEGER, CORTO_WIDTH_64, CORTO_BITMASK, CORTO_WIDTH_32, int64, enum);
    CORTO_CONVERT_INIT_NUM(CORTO_BITMASK, CORTO_WIDTH_32, CORTO_UINTEGER, CORTO_WIDTH_64, enum, int64);
    CORTO_CONVERT_INIT_NUM(CORTO_UINTEGER, CORTO_WIDTH_64, CORTO_BITMASK, CORTO_WIDTH_32, int64, enum);
    CORTO_CONVERT_INIT_NUM(CORTO_BITMASK, CORTO_WIDTH_32, CORTO_BOOLEAN, CORTO_WIDTH_8, int32, bool);

    /* string to octet */
    CORTO_CONVERT_INIT_NUM(CORTO_TEXT, CORTO_WIDTH_WORD, CORTO_BINARY, CORTO_WIDTH_8, string, octet);

    /* string to character */
    CORTO_CONVERT_INIT_NUM(CORTO_TEXT, CORTO_WIDTH_WORD, CORTO_CHARACTER, CORTO_WIDTH_8, string, char8);

    /* string to numeric */
    CORTO_CONVERT_INIT_NUM(CORTO_TEXT, CORTO_WIDTH_WORD, CORTO_INTEGER, CORTO_WIDTH_8, string, int8);
    CORTO_CONVERT_INIT_NUM(CORTO_TEXT, CORTO_WIDTH_WORD, CORTO_INTEGER, CORTO_WIDTH_16, string, int16);
    CORTO_CONVERT_INIT_NUM(CORTO_TEXT, CORTO_WIDTH_WORD, CORTO_INTEGER, CORTO_WIDTH_32, string, int32);
    CORTO_CONVERT_INIT_NUM(CORTO_TEXT, CORTO_WIDTH_WORD, CORTO_INTEGER, CORTO_WIDTH_64, string, int64);
    CORTO_CONVERT_INIT_NUM(CORTO_TEXT, CORTO_WIDTH_WORD, CORTO_UINTEGER, CORTO_WIDTH_8, string, uint8);
    CORTO_CONVERT_INIT_NUM(CORTO_TEXT, CORTO_WIDTH_WORD, CORTO_UINTEGER, CORTO_WIDTH_16, string, uint16);
    CORTO_CONVERT_INIT_NUM(CORTO_TEXT, CORTO_WIDTH_WORD, CORTO_UINTEGER, CORTO_WIDTH_32, string, uint32);
    CORTO_CONVERT_INIT_NUM(CORTO_TEXT, CORTO_WIDTH_WORD, CORTO_UINTEGER, CORTO_WIDTH_64, string, uint64);

    /* string to float */
    CORTO_CONVERT_INIT_NUM(CORTO_TEXT, CORTO_WIDTH_WORD, CORTO_FLOAT, CORTO_WIDTH_32, string, float32);
    CORTO_CONVERT_INIT_NUM(CORTO_TEXT, CORTO_WIDTH_WORD, CORTO_FLOAT, CORTO_WIDTH_64, string, float64);

    /* string to string */
    CORTO_CONVERT_INIT_NUM(CORTO_TEXT, CORTO_WIDTH_WORD, CORTO_TEXT, CORTO_WIDTH_WORD, string, string);
}

/* Convert a value from one primitive type to another */
corto_int16 corto_convert(corto_primitive fromType, void *from, corto_primitive toType, void *to) {
    corto_conversion c;

    /* Get conversion */
    c = _conversions[fromType->convertId][toType->convertId];
    if (c) {
        if (c(fromType, from, toType, to)) {
            /* Conversion failed */
            goto error;
        }
    } else {
        corto_seterr("no conversion possible from primitive type '%s' to '%s'.",
            corto_fullpath(NULL, fromType), corto_fullpath(NULL, toType));
        goto error;
    }

    return 0;
error:
    return -1;
}

#endif
