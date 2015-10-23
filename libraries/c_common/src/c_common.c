/*
 * c_common.c
 *
 *  Created on: Dec 21, 2012
 *      Author: sander
 */

#include "c_common.h"
#include "stdio.h"
#include "ctype.h"
#include "corto_generator.h"

/* Escape language keywords */
static int c_typeKeywordEscape(corto_string inputName, corto_string buffer) {

    if( !strcmp(inputName, "alignas") ||
        !strcmp(inputName, "alignof") ||
        !strcmp(inputName, "and") ||
        !strcmp(inputName, "and_eq") ||
        !strcmp(inputName, "asm") ||
        !strcmp(inputName, "auto") ||
        !strcmp(inputName, "bitand") ||
        !strcmp(inputName, "bitor") ||
        !strcmp(inputName, "bool") ||
        !strcmp(inputName, "break") ||
        !strcmp(inputName, "case") ||
        !strcmp(inputName, "catch") ||
        !strcmp(inputName, "char") ||
        !strcmp(inputName, "char16_t") ||
        !strcmp(inputName, "char32_t") ||
        !strcmp(inputName, "class") ||
        !strcmp(inputName, "compl") ||
        !strcmp(inputName, "const") ||
        !strcmp(inputName, "constexpr") ||
        !strcmp(inputName, "const_cast") ||
        !strcmp(inputName, "continue") ||
        !strcmp(inputName, "decltype") ||
        !strcmp(inputName, "default") ||
        !strcmp(inputName, "delete") ||
        !strcmp(inputName, "do") ||
        !strcmp(inputName, "double") ||
        !strcmp(inputName, "dynamic_cast") ||
        !strcmp(inputName, "else") ||
        !strcmp(inputName, "enum") ||
        !strcmp(inputName, "explicit") ||
        !strcmp(inputName, "export") ||
        !strcmp(inputName, "extern") ||
        !strcmp(inputName, "false") ||
        !strcmp(inputName, "float") ||
        !strcmp(inputName, "for") ||
        !strcmp(inputName, "friend") ||
        !strcmp(inputName, "goto") ||
        !strcmp(inputName, "if") ||
        !strcmp(inputName, "inline") ||
        !strcmp(inputName, "int") ||
        !strcmp(inputName, "long") ||
        !strcmp(inputName, "mutable") ||
        !strcmp(inputName, "namespace") ||
        !strcmp(inputName, "new") ||
        !strcmp(inputName, "noexcept") ||
        !strcmp(inputName, "not") ||
        !strcmp(inputName, "not_eq") ||
        !strcmp(inputName, "nullptr") ||
        !strcmp(inputName, "operator") ||
        !strcmp(inputName, "or") ||
        !strcmp(inputName, "or_eq") ||
        !strcmp(inputName, "private") ||
        !strcmp(inputName, "protected") ||
        !strcmp(inputName, "public") ||
        !strcmp(inputName, "register") ||
        !strcmp(inputName, "reinterpret_cast") ||
        !strcmp(inputName, "return") ||
        !strcmp(inputName, "short") ||
        !strcmp(inputName, "signed") ||
        !strcmp(inputName, "sizeof") ||
        !strcmp(inputName, "static") ||
        !strcmp(inputName, "static_assert") ||
        !strcmp(inputName, "static_cast") ||
        !strcmp(inputName, "struct") ||
        !strcmp(inputName, "switch") ||
        !strcmp(inputName, "template") ||
        !strcmp(inputName, "this") ||
        !strcmp(inputName, "thread_local") ||
        !strcmp(inputName, "throw") ||
        !strcmp(inputName, "true") ||
        !strcmp(inputName, "try") ||
        !strcmp(inputName, "typedef") ||
        !strcmp(inputName, "typeid") ||
        !strcmp(inputName, "typename") ||
        !strcmp(inputName, "union") ||
        !strcmp(inputName, "using") ||
        !strcmp(inputName, "unsigned") ||
        !strcmp(inputName, "virtual") ||
        !strcmp(inputName, "void") ||
        !strcmp(inputName, "volatile") ||
        !strcmp(inputName, "wchar_t") ||
        !strcmp(inputName, "xor") ||
        !strcmp(inputName, "while")) {
        memmove(buffer + 1, inputName, strlen(inputName) + 1);
        *buffer = '_';
    } else {
        memmove(buffer, inputName, strlen(inputName) + 1);
    }
    return 0;
}

corto_string corto_genId(corto_string str, corto_id id) {
    corto_char *ptr, ch, *idptr;

    ptr = str;
    idptr = id;

    /* Strip scope-operator for rootscope */
    if (*ptr) {
        if (*(corto_int16*)ptr == CORTO_SCOPE_HEX) {
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
corto_char* c_primitiveId(corto_primitive t, corto_char* buff) {
    corto_bool appendWidth, appendT;

    appendWidth = FALSE;
    appendT = FALSE;

    switch(t->kind) {
    case CORTO_BOOLEAN:
    case CORTO_CHARACTER:
        switch(t->width) {
        case CORTO_WIDTH_8:
            strcpy(buff, "char");
            break;
        case CORTO_WIDTH_16:
            strcpy(buff, "wchar");
            appendT = TRUE;
            break;
        default: {
            corto_id id;
            corto_seterr("unsupported width for primitive type '%s'.", corto_fullname(t, id));
            goto error;
            break;
        }
        }
        break;
    case CORTO_BINARY:
    case CORTO_UINTEGER:
        strcpy(buff, "uint");
        appendWidth = TRUE;
        appendT = TRUE;
        break;
    case CORTO_INTEGER:
        strcpy(buff, "int");
        appendWidth = TRUE;
        appendT = TRUE;
        break;
    case CORTO_FLOAT:
        switch(t->width) {
        case CORTO_WIDTH_32:
            strcpy(buff, "float");
            break;
        case CORTO_WIDTH_64:
            strcpy(buff, "double");
            break;
        default: {
            corto_id id;
            corto_seterr("unsupported width for floating point type '%s'", corto_fullname(t, id));
            goto error;
            break;
        }
        }
        break;
    case CORTO_ENUM:
    case CORTO_BITMASK:
        corto_seterr("enumeration\\bitmasks types must be defined using the 'enum' keyword.");
        goto error;
        break;
    case CORTO_TEXT:
        strcpy(buff, "char*");
        break;
    }

    /* Append width */
    if (appendWidth) {
        switch(t->width) {
        case CORTO_WIDTH_8:
            strcat(buff, "8");
            break;
        case CORTO_WIDTH_16:
            strcat(buff, "16");
            break;
        case CORTO_WIDTH_32:
            strcat(buff, "32");
            break;
        case CORTO_WIDTH_64:
            strcat(buff, "64");
            break;
        case CORTO_WIDTH_WORD:
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
static corto_string c_typeToUpper(corto_string str, corto_id buffer) {
    corto_char *ptr, *bptr, ch;

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

static corto_char c_lastLetter(corto_string str) {
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
corto_char* c_constantId(corto_generator g, corto_constant* c, corto_char* buffer) {
    corto_string prefixOrig;
    corto_enum e = corto_parentof(c);
    corto_string name = corto_nameof(e->constants.buffer[0]);
    corto_id prefix;
    corto_char ch;

    prefixOrig = g_getPrefix(g, c);
    if (!prefixOrig) {
        prefixOrig = corto_nameof(g_getCurrent(g));
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

    sprintf(buffer, "%s_%s", prefix, corto_nameof(c));

    return buffer;
}

/* Parse type into C-specifier */
corto_int16 c_specifierId(corto_generator g, corto_type t, corto_char* specifier, corto_bool* prefix, corto_char* postfix) {

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
    if (corto_checkAttr(t, CORTO_ATTR_SCOPED)) {
        g_fullOid(g, t, specifier);
    } else {
        if (t != corto_type(t)) {
            corto_seterr("anonymous typedefs are not allowed.");
            goto error;
        }

        switch(corto_type(t)->kind) {
        case CORTO_PRIMITIVE:
            c_primitiveId(corto_primitive(t), specifier);
            break;
        case CORTO_COLLECTION: {
            corto_id _specifier, _postfix;
            corto_type elementType = corto_collection(t)->elementType;
            switch(corto_collection(t)->kind) {
            case CORTO_ARRAY:
                /* Get specifier of elementType */
                if (c_specifierId(g, corto_collection(t)->elementType, _specifier, NULL, _postfix)) {
                    goto error;
                }
                if ((elementType->kind == CORTO_COLLECTION) && (corto_collection(elementType)->kind == CORTO_ARRAY)) {
                    sprintf(specifier, "%s_%d", _specifier, corto_collection(t)->max);
                } else {
                    sprintf(specifier, "%sArray%d", _specifier, corto_collection(t)->max);
                }
                break;
            case CORTO_SEQUENCE:
                /* Get specifier of elementType */
                if (c_specifierId(g, corto_collection(t)->elementType, _specifier, NULL, _postfix)) {
                    goto error;
                }
                if ((elementType->kind == CORTO_COLLECTION) && (corto_collection(elementType)->kind == CORTO_SEQUENCE)) {
                    sprintf(specifier, "%s_%d", _specifier, corto_collection(t)->max);
                } else {
                    if (corto_collection(t)->max) {
                        sprintf(specifier, "%sSeq%d", _specifier, corto_collection(t)->max);
                    } else {
                        sprintf(specifier, "%sSeq", _specifier);
                    }
                }
                break;
            case CORTO_LIST:
                if (c_specifierId(g, corto_collection(t)->elementType, _specifier, NULL, _postfix)) {
                    goto error;
                }
                if ((elementType->kind == CORTO_COLLECTION) && (corto_collection(elementType)->kind == CORTO_LIST)) {
                    sprintf(specifier, "%s_%d", _specifier, corto_collection(t)->max);
                } else {
                    if (corto_collection(t)->max) {
                        sprintf(specifier, "%sList%d", _specifier, corto_collection(t)->max);
                    } else {
                        sprintf(specifier, "%sList", _specifier);
                    }
                }
                break;
            case CORTO_MAP:
                strcpy(specifier, "corto_rbtree");
                break;
            }
            break;
        }
        default:
            corto_seterr("anonymous type of kind '%s' not allowed.", corto_nameof(corto_enum_constant(corto_typeKind_o, corto_type(t)->kind)));
            goto error;
            break;
        }
    }

    return 0;
error:
    return -1;
}

corto_char* c_escapeString(corto_string str, corto_id id) {
    corto_char *ptr, *bptr, ch;

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

corto_bool c_procedureHasThis(corto_function o) {
    corto_bool result;
    if (corto_typeof(o) != corto_type(corto_observer_o)) {
        result = (corto_instanceof(corto_type(corto_method_o), o) || 
                  corto_instanceof(corto_type(corto_metaprocedure_o), o));
    } else {
        result = corto_class_instanceof(corto_class_o, corto_parentof(o));
    }
    return result;
}

/* Translate a scope to a path */
corto_char* c_topath(corto_object o, corto_id id, corto_char separator) {
    corto_uint32 offset;
    corto_char ch, *ptr;

    corto_fullname(o, id);

    ptr = id + 2;
    offset = 2;
    while((ch = *ptr)) {
        switch(ch) {
        case ':':
            *(ptr-offset) = separator;
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

corto_string c_paramName(corto_string name, corto_string buffer) {

    if (*name == '$') {
        if (!strcmp(name, "$__line")) {
            strcpy(buffer, name + 1);
        } else if (!strcmp(name, "$__file")) {
            strcpy(buffer, name + 1);
        } else {
            sprintf(buffer, "str_%s", name + 1);
        }
    } else {
        corto_id id;
        corto_genId(name, id);
        strcpy(buffer, id);
    }
    return buffer;
}

corto_char* c_usingName(corto_generator g, corto_object o, corto_id id) {
    corto_id buff;
    char *ptr;

    g_fullOid(g, o, buff);
    ptr = strchr(buff, '_');
    if (ptr) {
        strcpy(id, ptr + 1);
    } else {
        strcpy(id, buff);
    }

    return id;
}

corto_char* c_usingConstant(corto_generator g, corto_id id) {
    corto_id buff;
    strcpy(id, "USING_");
    char *ptr = &id[6];
    corto_object o = g_getCurrent(g);
    c_topath(o, buff, '_');
    c_typeToUpper(buff, ptr);
    return id;
}

void c_writeExport(corto_generator g, g_file file) {
    corto_id upperName;
    c_topath(g_getCurrent(g), upperName, '_');
    corto_strupper(upperName);
    g_fileWrite(file, "%s_EXPORT ", upperName);
}
