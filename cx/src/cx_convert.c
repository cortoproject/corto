/*
 * cx_convert.c
 *
 *  Created on: Aug 23, 2012
 *      Author: sander
 */

#include "cx_object.h"
#include "cx_convert.h"
#include "cx_util.h"
#include "cx_err.h"
#include "cx_mem.h"
#include "cx__primitive.h"
#include "stddef.h"
#include "stdint.h"
#include "inttypes.h"
#include "cx.h"

typedef cx_int16 (*cx_conversion)(cx_primitive fromType, void* from, cx_primitive toType, void* to);

static cx_conversion _conversions[CX_PRIMITIVE_MAX_CONVERTID+1][CX_PRIMITIVE_MAX_CONVERTID+1];

/* Conversion functionname */
#define CX_NAME_TRANSFORM(from, to) __cx_##from##_##to##_convert

/* Templates for transformator functions */
#define CX_DECL_TRANSFORM(typeFrom, typeTo) static cx_int16 CX_NAME_TRANSFORM(typeFrom, typeTo) (cx_primitive fromType, void* from, cx_primitive toType, void* to)

/* Conversion typedefs for char and floating point types (integer types come from stdint.h) */
typedef char char8_t;
typedef wchar_t char16_t;
typedef float float32_t;
typedef double float64_t;
typedef cx_int8 bin8_t;
typedef cx_int16 bin16_t;
typedef cx_int32 bin32_t;
typedef cx_int64 bin64_t;
typedef cx_word word_t;
typedef cx_bool bool_t;

/* Conversions between numeric types */
#define CX_CONVERT_NUM(typeFrom, typeTo) \
    CX_DECL_TRANSFORM(typeFrom, typeTo) {\
        CX_UNUSED(fromType);\
        CX_UNUSED(toType);\
        *(typeTo##_t*)to = *(typeFrom##_t*)from;\
        return 0;\
    }

/* Conversions between numeric and boolean types */
#define CX_CONVERT_BOOL(typeFrom, typeTo) \
    CX_DECL_TRANSFORM(typeFrom, typeTo) {\
        CX_UNUSED(fromType);\
        CX_UNUSED(toType);\
        if (*(typeFrom##_t*)from) {\
            *(typeTo##_t*)to = TRUE;\
        } else {\
            *(typeTo##_t*)to = FALSE;\
        }\
        return 0;\
    }

/* Conversions to string */
#define CX_CONVERT_TO_STR(typeFrom, fmt) \
    CX_DECL_TRANSFORM(typeFrom,string) {\
        char* str = cx_alloc(128);\
        CX_UNUSED(fromType);\
        CX_UNUSED(toType);\
        sprintf(str, fmt, *(typeFrom##_t*)from);\
        *(cx_string*)to = str;\
        return 0;\
    }

/* Transformation from string to char */
#define CX_CONVERT_FROM_STR_CHAR(typeTo) \
    CX_DECL_TRANSFORM(string, typeTo) {\
        CX_UNUSED(fromType);\
        CX_UNUSED(toType);\
        *(typeTo##_t*)to = **(cx_string*)from;\
        return 0;\
    }

/* Transformation from string to int */
#define CX_CONVERT_FROM_STR_INT(typeTo) \
    CX_DECL_TRANSFORM(string, typeTo) {\
        CX_UNUSED(fromType);\
        CX_UNUSED(toType);\
        *(typeTo##_t*)to = atoi(*(cx_string*)from);\
        return 0;\
    }

/* Transformation from string to float */
#define CX_CONVERT_FROM_STR_FLOAT(typeTo) \
    CX_DECL_TRANSFORM(string, typeTo) {\
        CX_UNUSED(fromType);\
        CX_UNUSED(toType);\
        *(typeTo##_t*)to = atof(*(cx_string*)from);\
        return 0;\
    }

/* string to string */
CX_DECL_TRANSFORM(string, string) {
    CX_UNUSED(toType);
    CX_UNUSED(fromType);
    if (*(cx_string*)from) {
        *(cx_string*)to = cx_strdup(*(cx_string*)from);
    } else {
        *(cx_string*)to = NULL;
    }
    return 0;
}

/* boolean to string */
CX_DECL_TRANSFORM(boolean, string) {
    CX_UNUSED(toType);
    CX_UNUSED(fromType);

    if (*(cx_bool*)from) {
        *(cx_string*)to = cx_strdup("true");
    } else {
        *(cx_string*)to = cx_strdup("false");
    }
    return 0;
}

/* string to boolean */
CX_DECL_TRANSFORM(string, boolean) {
    cx_string str;
    CX_UNUSED(toType);
    CX_UNUSED(fromType);
    str = *(cx_string*)from;
    if (!strcmp(str, "TRUE") || !strcmp(str, "true")) {
        *(cx_bool*)to = TRUE;
    } else if (!strcmp(str, "FALSE") || !strcmp(str, "false")) {
        *(cx_bool*)to = FALSE;
    } else {
        return -1;
    }
    return 0;
}

/* enum to string */
CX_DECL_TRANSFORM(enum, string) {
    cx_object constant;
    CX_UNUSED(toType);
    constant = cx_enum_constant((cx_enum)fromType, *(cx_int32*)from);
    if (!constant) {
        cx_id fullname;
        cx_error("value %d is not valid for enumeration '%s'.", *(cx_uint32*)from, cx_fullname(fromType, fullname));
        return -1;
    }
    *(cx_string*)to = cx_strdup(cx_nameof(constant));
    return 0;
}

/* string to enum */
CX_DECL_TRANSFORM(string, enum) {
    cx_constant* o;
    CX_UNUSED(fromType);
    o = cx_resolve_ext(NULL, toType, *(cx_string*)from, FALSE, "Resolve enumeration");
    if (!o) {
        cx_id fullname;
        cx_error("constant identifier '%s' is not valid for enumeration '%s'.", *(cx_string*)from, cx_fullname(toType, fullname));
        goto error;
    } else {
        *(cx_int32*)to = *o;
        cx_release(o);
    }
    return 0;
error:
    return -1;
}

/* enum to int */
CX_DECL_TRANSFORM(enum, int32) {
    CX_UNUSED(fromType);
    CX_UNUSED(toType);
    *(cx_int32*)to = *(cx_constant*)from;
    return 0;
}

/* int to enum */
CX_DECL_TRANSFORM(int32, enum) {
    CX_UNUSED(fromType);
    CX_UNUSED(toType);
    *(cx_constant*)to = *(cx_int32*)from;
    return 0;
}

/* enum to int */
CX_DECL_TRANSFORM(enum, int64) {
    CX_UNUSED(fromType);
    CX_UNUSED(toType);
    *(cx_int64*)to = *(cx_constant*)from;
    return 0;
}

/* int to enum */
CX_DECL_TRANSFORM(int64, enum) {
    CX_UNUSED(fromType);
    CX_UNUSED(toType);
    *(cx_constant*)to = *(cx_int64*)from;
    return 0;
}

/* bitmask to string */
CX_DECL_TRANSFORM(bitmask, string) {
    cx_object constant;
    cx_constant v, cv;
    cx_uint32 i, length;
    cx_string result;
    CX_UNUSED(toType);

    v = *(cx_constant*)from;
    result = NULL;
    length = 1; /* 0-terminator */


    for(i=0; i<cx_enum(fromType)->constants.length;i++) {
        constant = cx_enum(fromType)->constants.buffer[i];
        cv = *(cx_constant*)constant;

        if ((((cv & v) == cv) && cv) || !(cv | v)) {
            length += strlen(cx_nameof(constant));
            if (!result) {
                result = cx_realloc(result, length);
                *result = '\0';
            } else {
                length+=1;
                result = cx_realloc(result, length);
                strcat(result, "|");
            }

            strcat(result, cx_nameof(constant));
        }
    }

    if (!result) {
        result = cx_strdup("0");
    }

    *(cx_string*)to = result;

    return 0;
}

/* string to bitmask */
CX_DECL_TRANSFORM(string, bitmask) {
    cx_id buffer;
    cx_string fromstr;
    cx_char *ptr, *bptr, ch;
    cx_constant v;
    cx_object constant;

    CX_UNUSED(fromType);

    fromstr = *(cx_string*)from;
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
                constant = cx_lookup(toType, buffer);
                if (!constant) {
                    cx_id fullname;
                    cx_error("constant identifier '%s' is not valid for bitmask '%s'.", buffer, cx_fullname(toType, fullname));
                    v = 0;
                    goto error;
                }

                /* 'or' constant-value with resultvalue. */
                v |= *(cx_constant*)constant;
                bptr = buffer;

                cx_release(constant);

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

    *(cx_constant*)to = v;

    return 0;
error:
    return -1;
}

/* All conversion functions for numeric types */
#define CX_CONVERT_NUM_ALL(fromType, fmt)\
    CX_CONVERT_NUM(fromType,char8)\
    CX_CONVERT_NUM(fromType,int8)\
    CX_CONVERT_NUM(fromType,int16)\
    CX_CONVERT_NUM(fromType,int32)\
    CX_CONVERT_NUM(fromType,int64)\
    CX_CONVERT_NUM(fromType,intptr)\
    CX_CONVERT_NUM(fromType,uint8)\
    CX_CONVERT_NUM(fromType,uint16)\
    CX_CONVERT_NUM(fromType,uint32)\
    CX_CONVERT_NUM(fromType,uint64)\
    CX_CONVERT_NUM(fromType,uintptr)\
    CX_CONVERT_NUM(fromType,float32)\
    CX_CONVERT_NUM(fromType,float64)\
    CX_CONVERT_BOOL(fromType, bool)\
    CX_CONVERT_TO_STR(fromType, fmt)

/* Conversion functions for integer types */
#define CX_CONVERT_NUM_INT(fromType, fmt)\
    CX_CONVERT_NUM(fromType,uint8)\
    CX_CONVERT_NUM(fromType,uint16)\
    CX_CONVERT_NUM(fromType,uint32)\
    CX_CONVERT_NUM(fromType,uint64)\
    CX_CONVERT_NUM(fromType,uintptr)\
    CX_CONVERT_NUM(fromType,float32)\
    CX_CONVERT_NUM(fromType,float64)\
    CX_CONVERT_BOOL(fromType, bool)\
    CX_CONVERT_TO_STR(fromType, fmt)

CX_CONVERT_NUM_INT(bool, "%d")
CX_CONVERT_NUM_INT(char8, "%c")
CX_CONVERT_NUM_INT(int8, "%" PRId8)
CX_CONVERT_NUM_INT(int16, "%" PRId16)
CX_CONVERT_NUM_INT(int32, "%" PRId32)
CX_CONVERT_NUM_INT(int64, "%" PRId64)
CX_CONVERT_NUM_INT(intptr, "%" PRIdPTR)
CX_CONVERT_NUM_INT(uint8, "%" PRIu8)
CX_CONVERT_NUM_INT(uint16, "%" PRIu16)
CX_CONVERT_NUM_INT(uint32, "%" PRIu32)
CX_CONVERT_NUM_INT(uint64, "%" PRIu64)
CX_CONVERT_NUM_INT(uintptr, "%" PRIuPTR)
CX_CONVERT_NUM_ALL(float32, "%f")
CX_CONVERT_NUM_ALL(float64, "%f")
CX_CONVERT_TO_STR(bin8, "0x%hhx")
CX_CONVERT_TO_STR(bin16, "0x%" PRIx16)
CX_CONVERT_TO_STR(bin32, "0x%" PRIx32)
CX_CONVERT_TO_STR(bin64, "0x%" PRIx64)
CX_CONVERT_NUM_ALL(word, "0x%" PRIxPTR)

/* All string to character conversions */
CX_CONVERT_FROM_STR_CHAR(char8)

/* All string to integer conversions */
CX_CONVERT_FROM_STR_INT(int8)
CX_CONVERT_FROM_STR_INT(int16)
CX_CONVERT_FROM_STR_INT(int32)
CX_CONVERT_FROM_STR_INT(int64)
CX_CONVERT_FROM_STR_INT(uint8)
CX_CONVERT_FROM_STR_INT(uint16)
CX_CONVERT_FROM_STR_INT(uint32)
CX_CONVERT_FROM_STR_INT(uint64)

/* All string to float conversions */
CX_CONVERT_FROM_STR_FLOAT(float32)
CX_CONVERT_FROM_STR_FLOAT(float64)

/* Init numeric conversion slot */
#define CX_CONVERT_INIT_NUM(kind, width, toKind, toWidth, fromType, toType)\
    _conversions[cx__primitive_convertId(kind, width)][cx__primitive_convertId(toKind, toWidth)] = CX_NAME_TRANSFORM(fromType, toType)

/* All numeric conversion slots */
#define CX_CONVERT_INIT_NUM_ALL(kind, width, type)\
    CX_CONVERT_INIT_NUM(kind, width, CX_BOOLEAN, CX_WIDTH_8, type, bool);\
    CX_CONVERT_INIT_NUM(kind, width, CX_BINARY, CX_WIDTH_8, type, uint8);\
    CX_CONVERT_INIT_NUM(kind, width, CX_BINARY, CX_WIDTH_16, type, uint16);\
    CX_CONVERT_INIT_NUM(kind, width, CX_BINARY, CX_WIDTH_32, type, uint32);\
    CX_CONVERT_INIT_NUM(kind, width, CX_BINARY, CX_WIDTH_64, type, uint64);\
    CX_CONVERT_INIT_NUM(kind, width, CX_BINARY, CX_WIDTH_WORD, type, uintptr);\
    CX_CONVERT_INIT_NUM(kind, width, CX_CHARACTER, CX_WIDTH_8, type, char8);\
    CX_CONVERT_INIT_NUM(kind, width, CX_INTEGER, CX_WIDTH_8, type, int8);\
    CX_CONVERT_INIT_NUM(kind, width, CX_INTEGER, CX_WIDTH_16, type, int16);\
    CX_CONVERT_INIT_NUM(kind, width, CX_INTEGER, CX_WIDTH_32, type, int32);\
    CX_CONVERT_INIT_NUM(kind, width, CX_INTEGER, CX_WIDTH_64, type, int64);\
    CX_CONVERT_INIT_NUM(kind, width, CX_INTEGER, CX_WIDTH_WORD, type, intptr);\
    CX_CONVERT_INIT_NUM(kind, width, CX_UINTEGER, CX_WIDTH_8, type, uint8);\
    CX_CONVERT_INIT_NUM(kind, width, CX_UINTEGER, CX_WIDTH_16, type, uint16);\
    CX_CONVERT_INIT_NUM(kind, width, CX_UINTEGER, CX_WIDTH_32, type, uint32);\
    CX_CONVERT_INIT_NUM(kind, width, CX_UINTEGER, CX_WIDTH_64, type, uint64);\
    CX_CONVERT_INIT_NUM(kind, width, CX_UINTEGER, CX_WIDTH_WORD, type, uintptr);\
    CX_CONVERT_INIT_NUM(kind, width, CX_FLOAT, CX_WIDTH_32, type, float32);\
    CX_CONVERT_INIT_NUM(kind, width, CX_FLOAT, CX_WIDTH_64, type, float64);\
    CX_CONVERT_INIT_NUM(kind, width, CX_TEXT, CX_WIDTH_WORD, type, string);\

/* Numeric conversion slots for integers */
#define CX_CONVERT_INIT_NUM_INT(kind, width, type)\
    CX_CONVERT_INIT_NUM(kind, width, CX_BOOLEAN, CX_WIDTH_8, type, bool);\
    CX_CONVERT_INIT_NUM(kind, width, CX_BINARY, CX_WIDTH_8, type, uint8);\
    CX_CONVERT_INIT_NUM(kind, width, CX_BINARY, CX_WIDTH_16, type, uint16);\
    CX_CONVERT_INIT_NUM(kind, width, CX_BINARY, CX_WIDTH_32, type, uint32);\
    CX_CONVERT_INIT_NUM(kind, width, CX_BINARY, CX_WIDTH_64, type, uint64);\
    CX_CONVERT_INIT_NUM(kind, width, CX_BINARY, CX_WIDTH_WORD, type, uintptr);\
    CX_CONVERT_INIT_NUM(kind, width, CX_CHARACTER, CX_WIDTH_8, type, uint8);\
    CX_CONVERT_INIT_NUM(kind, width, CX_INTEGER, CX_WIDTH_8, type, uint8);\
    CX_CONVERT_INIT_NUM(kind, width, CX_INTEGER, CX_WIDTH_16, type, uint16);\
    CX_CONVERT_INIT_NUM(kind, width, CX_INTEGER, CX_WIDTH_32, type, uint32);\
    CX_CONVERT_INIT_NUM(kind, width, CX_INTEGER, CX_WIDTH_64, type, uint64);\
    CX_CONVERT_INIT_NUM(kind, width, CX_INTEGER, CX_WIDTH_WORD, type, uintptr);\
    CX_CONVERT_INIT_NUM(kind, width, CX_UINTEGER, CX_WIDTH_8, type, uint8);\
    CX_CONVERT_INIT_NUM(kind, width, CX_UINTEGER, CX_WIDTH_16, type, uint16);\
    CX_CONVERT_INIT_NUM(kind, width, CX_UINTEGER, CX_WIDTH_32, type, uint32);\
    CX_CONVERT_INIT_NUM(kind, width, CX_UINTEGER, CX_WIDTH_64, type, uint64);\
    CX_CONVERT_INIT_NUM(kind, width, CX_UINTEGER, CX_WIDTH_WORD, type, uintptr);\
    CX_CONVERT_INIT_NUM(kind, width, CX_FLOAT, CX_WIDTH_32, type, float32);\
    CX_CONVERT_INIT_NUM(kind, width, CX_FLOAT, CX_WIDTH_64, type, float64);\
    CX_CONVERT_INIT_NUM(kind, width, CX_TEXT, CX_WIDTH_WORD, type, string);\

/* Init conversions */
void cx_convertInit(void) {
    CX_CONVERT_INIT_NUM_INT(CX_BOOLEAN, CX_WIDTH_8, bool);
    CX_CONVERT_INIT_NUM_INT(CX_BINARY, CX_WIDTH_8, uint8);
    CX_CONVERT_INIT_NUM_INT(CX_BINARY, CX_WIDTH_16, int16);
    CX_CONVERT_INIT_NUM_INT(CX_BINARY, CX_WIDTH_32, uint32);
    CX_CONVERT_INIT_NUM_INT(CX_BINARY, CX_WIDTH_64, uint64);
    CX_CONVERT_INIT_NUM_ALL(CX_BINARY, CX_WIDTH_WORD, word);
    CX_CONVERT_INIT_NUM_INT(CX_CHARACTER, CX_WIDTH_8, char8);
    CX_CONVERT_INIT_NUM_INT(CX_INTEGER, CX_WIDTH_8, int8);
    CX_CONVERT_INIT_NUM_INT(CX_INTEGER, CX_WIDTH_16, int16);
    CX_CONVERT_INIT_NUM_INT(CX_INTEGER, CX_WIDTH_32, int32);
    CX_CONVERT_INIT_NUM_INT(CX_INTEGER, CX_WIDTH_64, int64);
    CX_CONVERT_INIT_NUM_INT(CX_INTEGER, CX_WIDTH_WORD, intptr);
    CX_CONVERT_INIT_NUM_INT(CX_UINTEGER, CX_WIDTH_8, uint8);
    CX_CONVERT_INIT_NUM_INT(CX_UINTEGER, CX_WIDTH_16, uint16);
    CX_CONVERT_INIT_NUM_INT(CX_UINTEGER, CX_WIDTH_32, uint32);
    CX_CONVERT_INIT_NUM_INT(CX_UINTEGER, CX_WIDTH_64, uint64);
    CX_CONVERT_INIT_NUM_INT(CX_UINTEGER, CX_WIDTH_WORD, uintptr);
    CX_CONVERT_INIT_NUM_ALL(CX_FLOAT, CX_WIDTH_32, float32);
    CX_CONVERT_INIT_NUM_ALL(CX_FLOAT, CX_WIDTH_64, float64);

    /* Binary to string */
    CX_CONVERT_INIT_NUM(CX_BINARY, CX_WIDTH_8, CX_TEXT, CX_WIDTH_WORD, bin8, string);
    CX_CONVERT_INIT_NUM(CX_BINARY, CX_WIDTH_16, CX_TEXT, CX_WIDTH_WORD, bin16, string);
    CX_CONVERT_INIT_NUM(CX_BINARY, CX_WIDTH_32, CX_TEXT, CX_WIDTH_WORD, bin32, string);
    CX_CONVERT_INIT_NUM(CX_BINARY, CX_WIDTH_64, CX_TEXT, CX_WIDTH_WORD, bin64, string);

    /* boolean to string & vice versa */
    CX_CONVERT_INIT_NUM(CX_BOOLEAN, CX_WIDTH_8, CX_TEXT, CX_WIDTH_WORD, boolean, string);
    CX_CONVERT_INIT_NUM(CX_TEXT, CX_WIDTH_WORD, CX_BOOLEAN, CX_WIDTH_8, string, boolean);

    /* enum to string & vice versa */
    CX_CONVERT_INIT_NUM(CX_ENUM, CX_WIDTH_32, CX_TEXT, CX_WIDTH_WORD, enum, string);
    CX_CONVERT_INIT_NUM(CX_TEXT, CX_WIDTH_WORD, CX_ENUM, CX_WIDTH_32, string, enum);

    /* enum to int & vice versa */
    CX_CONVERT_INIT_NUM(CX_ENUM, CX_WIDTH_32, CX_INTEGER, CX_WIDTH_32, enum, int32);
    CX_CONVERT_INIT_NUM(CX_INTEGER, CX_WIDTH_32, CX_ENUM, CX_WIDTH_32, int32, enum);
    CX_CONVERT_INIT_NUM(CX_ENUM, CX_WIDTH_32, CX_INTEGER, CX_WIDTH_64, enum, int64);
    CX_CONVERT_INIT_NUM(CX_INTEGER, CX_WIDTH_64, CX_ENUM, CX_WIDTH_32, int64, enum);
    CX_CONVERT_INIT_NUM(CX_ENUM, CX_WIDTH_32, CX_UINTEGER, CX_WIDTH_64, enum, int64);
    CX_CONVERT_INIT_NUM(CX_UINTEGER, CX_WIDTH_64, CX_ENUM, CX_WIDTH_32, int64, enum);

    /* bitmask to string & vice versa */
    CX_CONVERT_INIT_NUM(CX_BITMASK, CX_WIDTH_32, CX_TEXT, CX_WIDTH_WORD, bitmask, string);
    CX_CONVERT_INIT_NUM(CX_TEXT, CX_WIDTH_WORD, CX_BITMASK, CX_WIDTH_32, string, bitmask);

    /* bitmask to int & vice versa */
    CX_CONVERT_INIT_NUM(CX_BITMASK, CX_WIDTH_32, CX_INTEGER, CX_WIDTH_32, enum, int32);
    CX_CONVERT_INIT_NUM(CX_INTEGER, CX_WIDTH_32, CX_BITMASK, CX_WIDTH_32, int32, enum);
    CX_CONVERT_INIT_NUM(CX_BITMASK, CX_WIDTH_32, CX_INTEGER, CX_WIDTH_64, enum, int64);
    CX_CONVERT_INIT_NUM(CX_INTEGER, CX_WIDTH_64, CX_BITMASK, CX_WIDTH_32, int64, enum);
    CX_CONVERT_INIT_NUM(CX_BITMASK, CX_WIDTH_32, CX_UINTEGER, CX_WIDTH_64, enum, int64);
    CX_CONVERT_INIT_NUM(CX_UINTEGER, CX_WIDTH_64, CX_BITMASK, CX_WIDTH_32, int64, enum);
    CX_CONVERT_INIT_NUM(CX_BITMASK, CX_WIDTH_32, CX_BOOLEAN, CX_WIDTH_8, int32, bool);

    /* string to character */
    CX_CONVERT_INIT_NUM(CX_TEXT, CX_WIDTH_WORD, CX_CHARACTER, CX_WIDTH_8, string, char8);

    /* string to numeric */
    CX_CONVERT_INIT_NUM(CX_TEXT, CX_WIDTH_WORD, CX_INTEGER, CX_WIDTH_8, string, int8);
    CX_CONVERT_INIT_NUM(CX_TEXT, CX_WIDTH_WORD, CX_INTEGER, CX_WIDTH_16, string, int16);
    CX_CONVERT_INIT_NUM(CX_TEXT, CX_WIDTH_WORD, CX_INTEGER, CX_WIDTH_32, string, int32);
    CX_CONVERT_INIT_NUM(CX_TEXT, CX_WIDTH_WORD, CX_INTEGER, CX_WIDTH_64, string, int64);
    CX_CONVERT_INIT_NUM(CX_TEXT, CX_WIDTH_WORD, CX_UINTEGER, CX_WIDTH_8, string, uint8);
    CX_CONVERT_INIT_NUM(CX_TEXT, CX_WIDTH_WORD, CX_UINTEGER, CX_WIDTH_16, string, uint16);
    CX_CONVERT_INIT_NUM(CX_TEXT, CX_WIDTH_WORD, CX_UINTEGER, CX_WIDTH_32, string, uint32);
    CX_CONVERT_INIT_NUM(CX_TEXT, CX_WIDTH_WORD, CX_UINTEGER, CX_WIDTH_64, string, uint64);

    /* string to float */
    CX_CONVERT_INIT_NUM(CX_TEXT, CX_WIDTH_WORD, CX_FLOAT, CX_WIDTH_32, string, float32);
    CX_CONVERT_INIT_NUM(CX_TEXT, CX_WIDTH_WORD, CX_FLOAT, CX_WIDTH_64, string, float64);

    /* string to string */
    CX_CONVERT_INIT_NUM(CX_TEXT, CX_WIDTH_WORD, CX_TEXT, CX_WIDTH_WORD, string, string);
}

/* Convert a value from one primitive type to another */
cx_int16 cx_convert(cx_primitive fromType, void *from, cx_primitive toType, void *to) {
    cx_conversion c;
    
    /* Get conversion */
    c = _conversions[fromType->convertId][toType->convertId];
    if (c) {
        if (c(fromType, from, toType, to)) {
            /* Conversion failed */
            goto error;
        }
    } else {
        cx_id id1, id2;
        cx_error("no conversion possible from primitive type '%s' to '%s'.", cx_fullname(fromType, id1), cx_fullname(toType, id2));
        goto error;
    }

    return 0;
error:
    return -1;
}
