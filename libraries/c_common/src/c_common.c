/*
 * c_common.c
 *
 *  Created on: Dec 21, 2012
 *      Author: sander
 */

#include "c_common.h"
#include "stdio.h"
#include "ctype.h"

/* Escape language keywords */
static int c_typeKeywordEscape(cx_string inputName, cx_string buffer) {

    if (!strcmp(inputName, "auto") ||
        !strcmp(inputName, "break") ||
        !strcmp(inputName, "case") ||
        !strcmp(inputName, "char") ||
        !strcmp(inputName, "const") ||
        !strcmp(inputName, "continue") ||
        !strcmp(inputName, "default") ||
        !strcmp(inputName, "do") ||
        !strcmp(inputName, "double") ||
        !strcmp(inputName, "else") ||
        !strcmp(inputName, "enum") ||
        !strcmp(inputName, "extern") ||
        !strcmp(inputName, "float") ||
        !strcmp(inputName, "for") ||
        !strcmp(inputName, "goto") ||
        !strcmp(inputName, "if") ||
        !strcmp(inputName, "int") ||
        !strcmp(inputName, "long") ||
        !strcmp(inputName, "register") ||
        !strcmp(inputName, "return") ||
        !strcmp(inputName, "short") ||
        !strcmp(inputName, "signed") ||
        !strcmp(inputName, "sizeof") ||
        !strcmp(inputName, "static") ||
        !strcmp(inputName, "struct") ||
        !strcmp(inputName, "switch") ||
        !strcmp(inputName, "typedef") ||
        !strcmp(inputName, "union") ||
        !strcmp(inputName, "unsigned") ||
        !strcmp(inputName, "void") ||
        !strcmp(inputName, "volatile") ||
        !strcmp(inputName, "while")) {
        memmove(buffer + 1, inputName, strlen(inputName) + 1);
        *buffer = '_';
    } else {
        memmove(buffer, inputName, strlen(inputName) + 1);
    }
    return 0;
}

cx_string corto_genId(cx_string str, cx_id id) {
    cx_char *ptr, ch, *idptr;

    ptr = str;
    idptr = id;

    /* Strip scope-operator for rootscope */
    if (*ptr) {
        if (*(cx_int16*)ptr == CX_SCOPE_HEX) {
            ptr += 2;
        }

        /* Replace '::' with '_' */
        while((ch = *ptr)) {
            switch(ch) {
            case ':':
                ptr++;
                /* no break */
            case ',':
            case '(':
            case ' ':
            case '{':
                *idptr = '_';
                idptr++;
                break;
            case ')':
            case '}':
                break;
            default:
                *idptr = ch;
                idptr++;
                break;
            }
            ptr++;
        }
    }
    *idptr = '\0';

    /* Check for C-keywords */
    c_typeKeywordEscape(id, id);

    return id;
}

/* Get string representing the base-platform type */
cx_char* c_primitiveId(cx_primitive t, cx_char* buff) {
    cx_bool appendWidth, appendT;

    appendWidth = FALSE;
    appendT = FALSE;

    switch(t->kind) {
    case CX_BOOLEAN:
    case CX_CHARACTER:
        switch(t->width) {
        case CX_WIDTH_8:
            strcpy(buff, "char");
            break;
        case CX_WIDTH_16:
            strcpy(buff, "wchar");
            appendT = TRUE;
            break;
        default: {
            cx_id id;
            cx_error("c_typePrimitivePlatformType: unsupported width for primitive type '%s'.", cx_fullname(t, id));
            goto error;
            break;
        }
        }
        break;
    case CX_BINARY:
    case CX_UINTEGER:
        strcpy(buff, "uint");
        appendWidth = TRUE;
        appendT = TRUE;
        break;
    case CX_INTEGER:
        strcpy(buff, "int");
        appendWidth = TRUE;
        appendT = TRUE;
        break;
    case CX_FLOAT:
        switch(t->width) {
        case CX_WIDTH_32:
            strcpy(buff, "float");
            break;
        case CX_WIDTH_64:
            strcpy(buff, "double");
            break;
        default: {
            cx_id id;
            cx_error("c_typePrimitivePlatformType: unsupported width for floating point type '%s'", cx_fullname(t, id));
            goto error;
            break;
        }
        }
        break;
    case CX_ENUM:
    case CX_BITMASK:
        cx_error("c_typePrimitivePlatformType: enumeration\\bitmasks types must be defined using the 'enum' keyword.");
        goto error;
        break;
    case CX_TEXT:
        strcpy(buff, "char*");
        break;
    }

    /* Append width */
    if (appendWidth) {
        switch(t->width) {
        case CX_WIDTH_8:
            strcat(buff, "8");
            break;
        case CX_WIDTH_16:
            strcat(buff, "16");
            break;
        case CX_WIDTH_32:
            strcat(buff, "32");
            break;
        case CX_WIDTH_64:
            strcat(buff, "64");
            break;
        case CX_WIDTH_WORD:
            strcat(buff, "ptr");
            break;
        }
    }

    /* Append _t */
    if (appendT) {
        strcat(buff, "_t");
    }

    return buff;
error:
    return NULL;
}

/* Convert string to upper. */
static cx_string c_typeToUpper(cx_string str, cx_id buffer) {
    cx_char *ptr, *bptr, ch;

    ptr = str;
    bptr = buffer;
    while((ch = *ptr)) {
        *bptr = toupper(ch);
        bptr++;
        ptr++;
    }
    *bptr = '\0';

    return buffer;
}

static cx_char c_lastLetter(cx_string str) {
    char *ptr, ch = '\0';

    ptr = str + (strlen(str) - 1);

    while ((ptr >= str) && (ch = *ptr)) {
        if ((ch >= 'a') && (ch <= 'z')) {
            break;
        } else if ((ch >= 'A') && (ch <= 'Z')) {
            break;
        }
        ptr --;
    }

    return ptr >= str ? ch : '\0';
}

/* Translate constant to C-language id */
cx_char* c_constantId(cx_generator g, cx_constant* c, cx_char* buffer) {
    cx_string prefixOrig;
    cx_enum e = cx_parentof(c);
    cx_string name = cx_nameof(e->constants.buffer[0]);
    cx_id prefix;
    cx_char ch;

    prefixOrig = g_getPrefix(g, c);
    if (!prefixOrig) {
        prefixOrig = cx_nameof(g_getCurrent(g));
    }

    strcpy(prefix, prefixOrig);

    /* Find last letter */
    ch = c_lastLetter(name);

    if (isupper(name[0])) {
        if (isupper(ch)) { /* All caps */
            c_typeToUpper(prefixOrig, prefix);
        } else { /* Initial caps */
            prefix[0] = toupper(prefix[0]);
        }
    }

    sprintf(buffer, "%s_%s", prefix, cx_nameof(c));

    return buffer;
}

/* Parse type into C-specifier */
cx_int16 c_specifierId(cx_generator g, cx_type t, cx_char* specifier, cx_bool* prefix, cx_char* postfix) {

    if (postfix) {
        *postfix = '\0';
    }

    /* If type is not a reference, objects that are defined with it need to add a prefix. This
     * won't be used for members or nested type-specifiers. */
    if (prefix) {
        if (t->reference) {
            *prefix = FALSE;
        } else {
            *prefix = TRUE;
        }
    }

    /* Check if object is scoped */
    if (cx_checkAttr(t, CX_ATTR_SCOPED)) {
        g_fullOid(g, t, specifier);
    } else {
        if (t != cx_type(t)) {
            cx_error("c_type: anonymous typedefs are not allowed.");
            goto error;
        }

        switch(cx_type(t)->kind) {
        case CX_PRIMITIVE:
            c_primitiveId(cx_primitive(t), specifier);
            break;
        case CX_COLLECTION: {
            cx_id _specifier, _postfix;
            cx_type elementType = cx_collection(t)->elementType;
            switch(cx_collection(t)->kind) {
            case CX_ARRAY:
                /* Get specifier of elementType */
                if (c_specifierId(g, cx_collection(t)->elementType, _specifier, NULL, _postfix)) {
                    goto error;
                }
                if ((elementType->kind == CX_COLLECTION) && (cx_collection(elementType)->kind == CX_ARRAY)) {
                    sprintf(specifier, "%s_%d", _specifier, cx_collection(t)->max);
                } else {
                    sprintf(specifier, "%sArray%d", _specifier, cx_collection(t)->max);
                }
                break;
            case CX_SEQUENCE:
                /* Get specifier of elementType */
                if (c_specifierId(g, cx_collection(t)->elementType, _specifier, NULL, _postfix)) {
                    goto error;
                }
                if ((elementType->kind == CX_COLLECTION) && (cx_collection(elementType)->kind == CX_SEQUENCE)) {
                    sprintf(specifier, "%s_%d", _specifier, cx_collection(t)->max);
                } else {
                    if (cx_collection(t)->max) {
                        sprintf(specifier, "%sSeq%d", _specifier, cx_collection(t)->max);
                    } else {
                        sprintf(specifier, "%sSeq", _specifier);
                    }
                }
                break;
            case CX_LIST:
                if (c_specifierId(g, cx_collection(t)->elementType, _specifier, NULL, _postfix)) {
                    goto error;
                }
                if ((elementType->kind == CX_COLLECTION) && (cx_collection(elementType)->kind == CX_LIST)) {
                    sprintf(specifier, "%s_%d", _specifier, cx_collection(t)->max);
                } else {
                    if (cx_collection(t)->max) {
                        sprintf(specifier, "%sList%d", _specifier, cx_collection(t)->max);
                    } else {
                        sprintf(specifier, "%sList", _specifier);
                    }
                }
                break;
            case CX_MAP:
                strcpy(specifier, "cx_rbtree");
                break;
            }
            break;
        }
        default:
            cx_error("c_type: anonymous type of kind '%s' not allowed.", cx_nameof(cx_enum_constant(cx_typeKind_o, cx_type(t)->kind)));
            goto error;
            break;
        }
    }

    return 0;
error:
    return -1;
}

cx_char* c_escapeString(cx_string str, cx_id id) {
    cx_char *ptr, *bptr, ch;

    ptr = str;
    bptr = id;

    while((ch = *ptr)) {
        if (ch == '"') {
            *bptr = '\\';
            bptr++;
        }
        *bptr = ch;
        bptr++;
        ptr++;
    }
    *bptr = '\0';

    return id;
}

cx_bool c_procedureHasThis(cx_function o) {
    cx_bool result;
    if (cx_typeof(o) != cx_type(cx_observer_o)) {
        result = (cx_instanceof(cx_type(cx_method_o), o) || 
                  cx_instanceof(cx_type(cx_metaprocedure_o), o));
    } else {
        result = cx_class_instanceof(cx_class_o, cx_parentof(o));
    }
    return result;
}

/* Translate a scope to a path */
cx_char* c_topath(cx_object o, cx_id id) {
    cx_uint32 offset;
    cx_char ch, *ptr;
    cx_fullname(o, id);

    ptr = id+2;
    offset = 2;
    while((ch = *ptr)) {
        switch(ch) {
        case ':':
            *(ptr-offset) = '/';
            ptr++;
            offset++;
            break;
        default:
            *(ptr-offset) = *ptr;
            break;
        }
        ptr++;
    }
    *(ptr-offset) = '\0';

    return id;
}

