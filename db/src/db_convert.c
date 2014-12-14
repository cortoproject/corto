/*
 * db_convert.c
 *
 *  Created on: Aug 23, 2012
 *      Author: sander
 */

#include "db_object.h"
#include "db_convert.h"
#include "db_util.h"
#include "db_err.h"
#include "db_mem.h"
#include "db__primitive.h"
#include "stddef.h"
#include "stdint.h"
#include "inttypes.h"
#include "db.h"

typedef db_int16 (*db_conversion)(db_primitive fromType, void* from, db_primitive toType, void* to);

static db_conversion _conversions[DB_PRIMITIVE_MAX_CONVERTID+1][DB_PRIMITIVE_MAX_CONVERTID+1];

/* Conversion functionname */
#define DB_NAME_TRANSFORM(from, to) __db_##from##_##to##_convert

/* Templates for transformator functions */
#define DB_DECL_TRANSFORM(typeFrom, typeTo) static db_int16 DB_NAME_TRANSFORM(typeFrom, typeTo) (db_primitive fromType, void* from, db_primitive toType, void* to)

/* Conversion typedefs for char and floating point types (integer types come from stdint.h) */
typedef char char8_t;
typedef wchar_t char16_t;
typedef float float32_t;
typedef double float64_t;
typedef db_int8 bin8_t;
typedef db_int16 bin16_t;
typedef db_int32 bin32_t;
typedef db_int64 bin64_t;
typedef db_word word_t;
typedef db_bool bool_t;

/* Conversions between numeric types */
#define DB_CONVERT_NUM(typeFrom, typeTo) \
    DB_DECL_TRANSFORM(typeFrom, typeTo) {\
        DB_UNUSED(fromType);\
        DB_UNUSED(toType);\
        *(typeTo##_t*)to = *(typeFrom##_t*)from;\
        return 0;\
    }

/* Conversions between numeric and boolean types */
#define DB_CONVERT_BOOL(typeFrom, typeTo) \
    DB_DECL_TRANSFORM(typeFrom, typeTo) {\
        DB_UNUSED(fromType);\
        DB_UNUSED(toType);\
        if (*(typeFrom##_t*)from) {\
            *(typeTo##_t*)to = TRUE;\
        } else {\
            *(typeTo##_t*)to = FALSE;\
        }\
        return 0;\
    }

/* Conversions to string */
#define DB_CONVERT_TO_STR(typeFrom, fmt) \
    DB_DECL_TRANSFORM(typeFrom,string) {\
        char* str = db_malloc(128);\
        DB_UNUSED(fromType);\
        DB_UNUSED(toType);\
        sprintf(str, "%"fmt, *(typeFrom##_t*)from);\
        *(db_string*)to = str;\
        return 0;\
    }

/* Transformation from string to char */
#define DB_CONVERT_FROM_STR_CHAR(typeTo) \
    DB_DECL_TRANSFORM(string, typeTo) {\
        DB_UNUSED(fromType);\
        DB_UNUSED(toType);\
        *(typeTo##_t*)to = **(db_string*)from;\
        return 0;\
    }

/* Transformation from string to int */
#define DB_CONVERT_FROM_STR_INT(typeTo) \
    DB_DECL_TRANSFORM(string, typeTo) {\
        DB_UNUSED(fromType);\
        DB_UNUSED(toType);\
        *(typeTo##_t*)to = atoi(*(db_string*)from);\
        return 0;\
    }

/* Transformation from string to float */
#define DB_CONVERT_FROM_STR_FLOAT(typeTo) \
    DB_DECL_TRANSFORM(string, typeTo) {\
        DB_UNUSED(fromType);\
        DB_UNUSED(toType);\
        *(typeTo##_t*)to = atof(*(db_string*)from);\
        return 0;\
    }

/* string to string */
DB_DECL_TRANSFORM(string, string) {
    DB_UNUSED(toType);
    DB_UNUSED(fromType);
    if (*(db_string*)from) {
        *(db_string*)to = db_strdup(*(db_string*)from);
    } else {
    	*(db_string*)to = NULL;
    }
    return 0;
}

/* boolean to string */
DB_DECL_TRANSFORM(boolean, string) {
    DB_UNUSED(toType);
    DB_UNUSED(fromType);

    if (*(db_bool*)from) {
        *(db_string*)to = db_strdup("true");
    } else {
        *(db_string*)to = db_strdup("false");
    }
    return 0;
}

/* string to boolean */
DB_DECL_TRANSFORM(string, boolean) {
    db_string str;
    DB_UNUSED(toType);
    DB_UNUSED(fromType);
    str = *(db_string*)from;
    if (!strcmp(str, "TRUE") || !strcmp(str, "true")) {
        *(db_bool*)to = TRUE;
    } else if (!strcmp(str, "FALSE") || !strcmp(str, "false")) {
        *(db_bool*)to = FALSE;
    } else {
        return -1;
    }
    return 0;
}

/* enum to string */
DB_DECL_TRANSFORM(enum, string) {
    db_object constant;
    DB_UNUSED(toType);
    constant = db_enum_constant((db_enum)fromType, *(db_int32*)from);
    if (!constant) {
        db_id fullname;
        db_error("value %d is not valid for enumeration '%s'.", *(db_uint32*)from, db_fullname(fromType, fullname));
        return -1;
    }
    *(db_string*)to = db_strdup(db_nameof(constant));
    return 0;
}

/* string to enum */
DB_DECL_TRANSFORM(string, enum) {
    db_constant* o;
    DB_UNUSED(fromType);
    o = db_resolve_ext(NULL, toType, *(db_string*)from, FALSE, "Resolve enumeration");
    if (!o) {
        db_id fullname;
        db_error("constant identifier '%s' is not valid for enumeration '%s'.", *(db_string*)from, db_fullname(toType, fullname));
        goto error;
    } else {
        *(db_int32*)to = *o;
        db_free(o);
    }
    return 0;
error:
    return -1;
}

/* enum to int */
DB_DECL_TRANSFORM(enum, int32) {
    DB_UNUSED(fromType);
    DB_UNUSED(toType);
    *(db_int32*)to = *(db_constant*)from;
    return 0;
}

/* int to enum */
DB_DECL_TRANSFORM(int32, enum) {
    DB_UNUSED(fromType);
    DB_UNUSED(toType);
    *(db_constant*)to = *(db_int32*)from;
    return 0;
}

/* enum to int */
DB_DECL_TRANSFORM(enum, int64) {
    DB_UNUSED(fromType);
    DB_UNUSED(toType);
    *(db_int64*)to = *(db_constant*)from;
    return 0;
}

/* int to enum */
DB_DECL_TRANSFORM(int64, enum) {
    DB_UNUSED(fromType);
    DB_UNUSED(toType);
    *(db_constant*)to = *(db_int64*)from;
    return 0;
}

/* bitmask to string */
DB_DECL_TRANSFORM(bitmask, string) {
    db_object constant;
    db_constant v, cv;
    db_uint32 i, length;
    db_string result;
    DB_UNUSED(toType);

    v = *(db_constant*)from;
    result = NULL;
    length = 1; /* 0-terminator */


	for(i=0; i<db_enum(fromType)->constants.length;i++) {
		constant = db_enum(fromType)->constants.buffer[i];
		cv = *(db_constant*)constant;

		if ((((cv & v) == cv) && cv) || !(cv | v)) {
			length += strlen(db_nameof(constant));
			if (!result) {
				result = db_realloc(result, length);
				*result = '\0';
			} else {
				length+=1;
				result = db_realloc(result, length);
				strcat(result, "|");
			}

			strcat(result, db_nameof(constant));
		}
	}

	if (!result) {
		result = db_strdup("0");
	}

    *(db_string*)to = result;

    return 0;
}

/* string to bitmask */
DB_DECL_TRANSFORM(string, bitmask) {
    db_id buffer;
    db_string fromstr;
    db_char *ptr, *bptr, ch;
    db_constant v;
    db_object constant;

    DB_UNUSED(fromType);

    fromstr = *(db_string*)from;
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
                constant = db_lookup(toType, buffer);
                if (!constant) {
                    db_id fullname;
                    db_error("constant identifier '%s' is not valid for bitmask '%s'.", buffer, db_fullname(toType, fullname));
                    v = 0;
                    goto error;
                }

                /* 'or' constant-value with resultvalue. */
                v |= *(db_constant*)constant;
                bptr = buffer;

                db_free(constant);

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

    *(db_constant*)to = v;

    return 0;
error:
    return -1;
}

/* All conversion functions for numeric types */
#define DB_CONVERT_NUM_ALL(fromType, fmt)\
    DB_CONVERT_NUM(fromType,char8)\
    DB_CONVERT_NUM(fromType,int8)\
    DB_CONVERT_NUM(fromType,int16)\
    DB_CONVERT_NUM(fromType,int32)\
    DB_CONVERT_NUM(fromType,int64)\
    DB_CONVERT_NUM(fromType,intptr)\
    DB_CONVERT_NUM(fromType,uint8)\
    DB_CONVERT_NUM(fromType,uint16)\
    DB_CONVERT_NUM(fromType,uint32)\
    DB_CONVERT_NUM(fromType,uint64)\
    DB_CONVERT_NUM(fromType,uintptr)\
    DB_CONVERT_NUM(fromType,float32)\
    DB_CONVERT_NUM(fromType,float64)\
    DB_CONVERT_BOOL(fromType, bool)\
    DB_CONVERT_TO_STR(fromType, fmt)

/* Conversion functions for integer types */
#define DB_CONVERT_NUM_INT(fromType, fmt)\
    DB_CONVERT_NUM(fromType,uint8)\
    DB_CONVERT_NUM(fromType,uint16)\
    DB_CONVERT_NUM(fromType,uint32)\
    DB_CONVERT_NUM(fromType,uint64)\
    DB_CONVERT_NUM(fromType,uintptr)\
    DB_CONVERT_NUM(fromType,float32)\
    DB_CONVERT_NUM(fromType,float64)\
    DB_CONVERT_BOOL(fromType, bool)\
    DB_CONVERT_TO_STR(fromType, fmt)

DB_CONVERT_NUM_INT(bool, "d")
DB_CONVERT_NUM_INT(char8, "c")
DB_CONVERT_NUM_INT(int8, PRId8)
DB_CONVERT_NUM_INT(int16, PRId16)
DB_CONVERT_NUM_INT(int32, PRId32)
DB_CONVERT_NUM_INT(int64, PRId64)
DB_CONVERT_NUM_INT(intptr, PRIdPTR)
DB_CONVERT_NUM_INT(uint8, PRIu8)
DB_CONVERT_NUM_INT(uint16, PRIu16)
DB_CONVERT_NUM_INT(uint32, PRIu32)
DB_CONVERT_NUM_INT(uint64, PRIu64)
DB_CONVERT_NUM_INT(uintptr, PRIuPTR)
DB_CONVERT_NUM_ALL(float32, "f")
DB_CONVERT_NUM_ALL(float64, "f")
DB_CONVERT_TO_STR(bin8, "hhx")
DB_CONVERT_TO_STR(bin16, PRIx16)
DB_CONVERT_TO_STR(bin32, PRIx32)
DB_CONVERT_TO_STR(bin64, PRIx64)
DB_CONVERT_NUM_ALL(word, PRIxPTR)

/* All string to character conversions */
DB_CONVERT_FROM_STR_CHAR(char8)

/* All string to integer conversions */
DB_CONVERT_FROM_STR_INT(int8)
DB_CONVERT_FROM_STR_INT(int16)
DB_CONVERT_FROM_STR_INT(int32)
DB_CONVERT_FROM_STR_INT(int64)
DB_CONVERT_FROM_STR_INT(uint8)
DB_CONVERT_FROM_STR_INT(uint16)
DB_CONVERT_FROM_STR_INT(uint32)
DB_CONVERT_FROM_STR_INT(uint64)

/* All string to float conversions */
DB_CONVERT_FROM_STR_FLOAT(float32)
DB_CONVERT_FROM_STR_FLOAT(float64)

/* Init numeric conversion slot */
#define DB_CONVERT_INIT_NUM(kind, width, toKind, toWidth, fromType, toType)\
    _conversions[db__primitive_convertId(kind, width)][db__primitive_convertId(toKind, toWidth)] = DB_NAME_TRANSFORM(fromType, toType)

/* All numeric conversion slots */
#define DB_CONVERT_INIT_NUM_ALL(kind, width, type)\
	DB_CONVERT_INIT_NUM(kind, width, DB_BOOLEAN, DB_WIDTH_8, type, bool);\
    DB_CONVERT_INIT_NUM(kind, width, DB_BINARY, DB_WIDTH_8, type, uint8);\
    DB_CONVERT_INIT_NUM(kind, width, DB_BINARY, DB_WIDTH_16, type, uint16);\
    DB_CONVERT_INIT_NUM(kind, width, DB_BINARY, DB_WIDTH_32, type, uint32);\
    DB_CONVERT_INIT_NUM(kind, width, DB_BINARY, DB_WIDTH_64, type, uint64);\
    DB_CONVERT_INIT_NUM(kind, width, DB_BINARY, DB_WIDTH_WORD, type, uintptr);\
    DB_CONVERT_INIT_NUM(kind, width, DB_CHARACTER, DB_WIDTH_8, type, char8);\
    DB_CONVERT_INIT_NUM(kind, width, DB_INTEGER, DB_WIDTH_8, type, int8);\
    DB_CONVERT_INIT_NUM(kind, width, DB_INTEGER, DB_WIDTH_16, type, int16);\
    DB_CONVERT_INIT_NUM(kind, width, DB_INTEGER, DB_WIDTH_32, type, int32);\
    DB_CONVERT_INIT_NUM(kind, width, DB_INTEGER, DB_WIDTH_64, type, int64);\
    DB_CONVERT_INIT_NUM(kind, width, DB_INTEGER, DB_WIDTH_WORD, type, intptr);\
    DB_CONVERT_INIT_NUM(kind, width, DB_UINTEGER, DB_WIDTH_8, type, uint8);\
    DB_CONVERT_INIT_NUM(kind, width, DB_UINTEGER, DB_WIDTH_16, type, uint16);\
    DB_CONVERT_INIT_NUM(kind, width, DB_UINTEGER, DB_WIDTH_32, type, uint32);\
    DB_CONVERT_INIT_NUM(kind, width, DB_UINTEGER, DB_WIDTH_64, type, uint64);\
    DB_CONVERT_INIT_NUM(kind, width, DB_UINTEGER, DB_WIDTH_WORD, type, uintptr);\
    DB_CONVERT_INIT_NUM(kind, width, DB_FLOAT, DB_WIDTH_32, type, float32);\
    DB_CONVERT_INIT_NUM(kind, width, DB_FLOAT, DB_WIDTH_64, type, float64);\
    DB_CONVERT_INIT_NUM(kind, width, DB_TEXT, DB_WIDTH_WORD, type, string);\

/* Numeric conversion slots for integers */
#define DB_CONVERT_INIT_NUM_INT(kind, width, type)\
	DB_CONVERT_INIT_NUM(kind, width, DB_BOOLEAN, DB_WIDTH_8, type, bool);\
    DB_CONVERT_INIT_NUM(kind, width, DB_BINARY, DB_WIDTH_8, type, uint8);\
    DB_CONVERT_INIT_NUM(kind, width, DB_BINARY, DB_WIDTH_16, type, uint16);\
    DB_CONVERT_INIT_NUM(kind, width, DB_BINARY, DB_WIDTH_32, type, uint32);\
    DB_CONVERT_INIT_NUM(kind, width, DB_BINARY, DB_WIDTH_64, type, uint64);\
    DB_CONVERT_INIT_NUM(kind, width, DB_BINARY, DB_WIDTH_WORD, type, uintptr);\
    DB_CONVERT_INIT_NUM(kind, width, DB_CHARACTER, DB_WIDTH_8, type, uint8);\
    DB_CONVERT_INIT_NUM(kind, width, DB_INTEGER, DB_WIDTH_8, type, uint8);\
    DB_CONVERT_INIT_NUM(kind, width, DB_INTEGER, DB_WIDTH_16, type, uint16);\
    DB_CONVERT_INIT_NUM(kind, width, DB_INTEGER, DB_WIDTH_32, type, uint32);\
    DB_CONVERT_INIT_NUM(kind, width, DB_INTEGER, DB_WIDTH_64, type, uint64);\
    DB_CONVERT_INIT_NUM(kind, width, DB_INTEGER, DB_WIDTH_WORD, type, uintptr);\
    DB_CONVERT_INIT_NUM(kind, width, DB_UINTEGER, DB_WIDTH_8, type, uint8);\
    DB_CONVERT_INIT_NUM(kind, width, DB_UINTEGER, DB_WIDTH_16, type, uint16);\
    DB_CONVERT_INIT_NUM(kind, width, DB_UINTEGER, DB_WIDTH_32, type, uint32);\
    DB_CONVERT_INIT_NUM(kind, width, DB_UINTEGER, DB_WIDTH_64, type, uint64);\
    DB_CONVERT_INIT_NUM(kind, width, DB_UINTEGER, DB_WIDTH_WORD, type, uintptr);\
    DB_CONVERT_INIT_NUM(kind, width, DB_FLOAT, DB_WIDTH_32, type, float32);\
    DB_CONVERT_INIT_NUM(kind, width, DB_FLOAT, DB_WIDTH_64, type, float64);\
    DB_CONVERT_INIT_NUM(kind, width, DB_TEXT, DB_WIDTH_WORD, type, string);\

/* Init conversions */
void db_convertInit(void) {
    DB_CONVERT_INIT_NUM_INT(DB_BOOLEAN, DB_WIDTH_8, bool);
	DB_CONVERT_INIT_NUM_INT(DB_BINARY, DB_WIDTH_8, uint8);
	DB_CONVERT_INIT_NUM_INT(DB_BINARY, DB_WIDTH_16, int16);
	DB_CONVERT_INIT_NUM_INT(DB_BINARY, DB_WIDTH_32, uint32);
	DB_CONVERT_INIT_NUM_INT(DB_BINARY, DB_WIDTH_64, uint64);
	DB_CONVERT_INIT_NUM_ALL(DB_BINARY, DB_WIDTH_WORD, word);
	DB_CONVERT_INIT_NUM_INT(DB_CHARACTER, DB_WIDTH_8, char8);
	DB_CONVERT_INIT_NUM_INT(DB_INTEGER, DB_WIDTH_8, int8);
	DB_CONVERT_INIT_NUM_INT(DB_INTEGER, DB_WIDTH_16, int16);
    DB_CONVERT_INIT_NUM_INT(DB_INTEGER, DB_WIDTH_32, int32);
    DB_CONVERT_INIT_NUM_INT(DB_INTEGER, DB_WIDTH_64, int64);
    DB_CONVERT_INIT_NUM_INT(DB_INTEGER, DB_WIDTH_WORD, intptr);
    DB_CONVERT_INIT_NUM_INT(DB_UINTEGER, DB_WIDTH_8, uint8);
    DB_CONVERT_INIT_NUM_INT(DB_UINTEGER, DB_WIDTH_16, uint16);
    DB_CONVERT_INIT_NUM_INT(DB_UINTEGER, DB_WIDTH_32, uint32);
    DB_CONVERT_INIT_NUM_INT(DB_UINTEGER, DB_WIDTH_64, uint64);
    DB_CONVERT_INIT_NUM_INT(DB_UINTEGER, DB_WIDTH_WORD, uintptr);
    DB_CONVERT_INIT_NUM_ALL(DB_FLOAT, DB_WIDTH_32, float32);
    DB_CONVERT_INIT_NUM_ALL(DB_FLOAT, DB_WIDTH_64, float64);

    /* Binary to string */
    DB_CONVERT_INIT_NUM(DB_BINARY, DB_WIDTH_8, DB_TEXT, DB_WIDTH_WORD, bin8, string);
    DB_CONVERT_INIT_NUM(DB_BINARY, DB_WIDTH_16, DB_TEXT, DB_WIDTH_WORD, bin16, string);
    DB_CONVERT_INIT_NUM(DB_BINARY, DB_WIDTH_32, DB_TEXT, DB_WIDTH_WORD, bin32, string);
    DB_CONVERT_INIT_NUM(DB_BINARY, DB_WIDTH_64, DB_TEXT, DB_WIDTH_WORD, bin64, string);

    /* boolean to string & vice versa */
    DB_CONVERT_INIT_NUM(DB_BOOLEAN, DB_WIDTH_8, DB_TEXT, DB_WIDTH_WORD, boolean, string);
    DB_CONVERT_INIT_NUM(DB_TEXT, DB_WIDTH_WORD, DB_BOOLEAN, DB_WIDTH_8, string, boolean);

    /* enum to string & vice versa */
    DB_CONVERT_INIT_NUM(DB_ENUM, DB_WIDTH_32, DB_TEXT, DB_WIDTH_WORD, enum, string);
    DB_CONVERT_INIT_NUM(DB_TEXT, DB_WIDTH_WORD, DB_ENUM, DB_WIDTH_32, string, enum);

    /* enum to int & vice versa */
    DB_CONVERT_INIT_NUM(DB_ENUM, DB_WIDTH_32, DB_INTEGER, DB_WIDTH_32, enum, int32);
    DB_CONVERT_INIT_NUM(DB_INTEGER, DB_WIDTH_32, DB_ENUM, DB_WIDTH_32, int32, enum);
    DB_CONVERT_INIT_NUM(DB_ENUM, DB_WIDTH_32, DB_INTEGER, DB_WIDTH_64, enum, int64);
    DB_CONVERT_INIT_NUM(DB_INTEGER, DB_WIDTH_64, DB_ENUM, DB_WIDTH_32, int64, enum);
    DB_CONVERT_INIT_NUM(DB_ENUM, DB_WIDTH_32, DB_UINTEGER, DB_WIDTH_64, enum, int64);
    DB_CONVERT_INIT_NUM(DB_UINTEGER, DB_WIDTH_64, DB_ENUM, DB_WIDTH_32, int64, enum);

    /* bitmask to string & vice versa */
    DB_CONVERT_INIT_NUM(DB_BITMASK, DB_WIDTH_32, DB_TEXT, DB_WIDTH_WORD, bitmask, string);
    DB_CONVERT_INIT_NUM(DB_TEXT, DB_WIDTH_WORD, DB_BITMASK, DB_WIDTH_32, string, bitmask);

    /* bitmask to int & vice versa */
    DB_CONVERT_INIT_NUM(DB_BITMASK, DB_WIDTH_32, DB_INTEGER, DB_WIDTH_32, enum, int32);
    DB_CONVERT_INIT_NUM(DB_INTEGER, DB_WIDTH_32, DB_BITMASK, DB_WIDTH_32, int32, enum);
    DB_CONVERT_INIT_NUM(DB_BITMASK, DB_WIDTH_32, DB_INTEGER, DB_WIDTH_64, enum, int64);
    DB_CONVERT_INIT_NUM(DB_INTEGER, DB_WIDTH_64, DB_BITMASK, DB_WIDTH_32, int64, enum);
    DB_CONVERT_INIT_NUM(DB_BITMASK, DB_WIDTH_32, DB_UINTEGER, DB_WIDTH_64, enum, int64);
    DB_CONVERT_INIT_NUM(DB_UINTEGER, DB_WIDTH_64, DB_BITMASK, DB_WIDTH_32, int64, enum);
    DB_CONVERT_INIT_NUM(DB_BITMASK, DB_WIDTH_32, DB_BOOLEAN, DB_WIDTH_8, int32, bool);


    /* string to character */
    DB_CONVERT_INIT_NUM(DB_TEXT, DB_WIDTH_WORD, DB_CHARACTER, DB_WIDTH_8, string, char8);

    /* string to numeric */
    DB_CONVERT_INIT_NUM(DB_TEXT, DB_WIDTH_WORD, DB_INTEGER, DB_WIDTH_8, string, int8);
    DB_CONVERT_INIT_NUM(DB_TEXT, DB_WIDTH_WORD, DB_INTEGER, DB_WIDTH_16, string, int16);
    DB_CONVERT_INIT_NUM(DB_TEXT, DB_WIDTH_WORD, DB_INTEGER, DB_WIDTH_32, string, int32);
    DB_CONVERT_INIT_NUM(DB_TEXT, DB_WIDTH_WORD, DB_INTEGER, DB_WIDTH_64, string, int64);
    DB_CONVERT_INIT_NUM(DB_TEXT, DB_WIDTH_WORD, DB_UINTEGER, DB_WIDTH_8, string, uint8);
    DB_CONVERT_INIT_NUM(DB_TEXT, DB_WIDTH_WORD, DB_UINTEGER, DB_WIDTH_16, string, uint16);
    DB_CONVERT_INIT_NUM(DB_TEXT, DB_WIDTH_WORD, DB_UINTEGER, DB_WIDTH_32, string, uint32);
    DB_CONVERT_INIT_NUM(DB_TEXT, DB_WIDTH_WORD, DB_UINTEGER, DB_WIDTH_64, string, uint64);

    /* string to float */
    DB_CONVERT_INIT_NUM(DB_TEXT, DB_WIDTH_WORD, DB_FLOAT, DB_WIDTH_32, string, float32);
    DB_CONVERT_INIT_NUM(DB_TEXT, DB_WIDTH_WORD, DB_FLOAT, DB_WIDTH_64, string, float64);

    /* string to string */
    DB_CONVERT_INIT_NUM(DB_TEXT, DB_WIDTH_WORD, DB_TEXT, DB_WIDTH_WORD, string, string);
}

/* Convert a value from one primitive type to another */
db_int16 db_convert(db_primitive fromType, void *from, db_primitive toType, void *to) {
    db_conversion c;
    
    /* Get conversion */
    c = _conversions[fromType->convertId][toType->convertId];
    if (c) {
        if (c(fromType, from, toType, to)) {
            /* Conversion failed */
            goto error;
        }
    } else {
        db_id id1, id2;
        db_error("no conversion possible from primitive type '%s' to '%s'.", db_fullname(fromType, id1), db_fullname(toType, id2));
        goto error;
    }

    return 0;
error:
    return -1;
}
