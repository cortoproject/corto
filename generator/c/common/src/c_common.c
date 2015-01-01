/*
 * c_common.c
 *
 *  Created on: Dec 21, 2012
 *      Author: sander
 */

#include "c_common.h"

/* Escape language keywords */
static int c_typeKeywordEscape(db_string inputName, db_string buffer) {

    if ( !strcmp(inputName, "auto") ||
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

db_string cortex_genId(db_string str, db_id id) {
    db_char *ptr, ch, *idptr;

    ptr = str;
	idptr = id;

    /* Strip scope-operator for rootscope */
    if (*ptr) {
		if (*(db_int16*)ptr == DB_SCOPE_HEX) {
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
db_char* c_primitiveId(db_primitive t, db_char* buff) {
    db_bool appendWidth, appendT;

    appendWidth = FALSE;
    appendT = FALSE;

    switch(t->kind) {
    case DB_BOOLEAN:
    case DB_CHARACTER:
        switch(t->width) {
        case DB_WIDTH_8:
            strcpy(buff, "char");
            break;
        case DB_WIDTH_16:
            strcpy(buff, "wchar");
            appendT = TRUE;
            break;
        default: {
            db_id id;
            db_error("c_typePrimitivePlatformType: unsupported width for primitive type '%s'.", db_fullname(t, id));
            goto error;
            break;
        }
        }
        break;
    case DB_BINARY:
    case DB_UINTEGER:
        strcpy(buff, "uint");
        appendWidth = TRUE;
        appendT = TRUE;
        break;
    case DB_INTEGER:
        strcpy(buff, "int");
        appendWidth = TRUE;
        appendT = TRUE;
        break;
    case DB_FLOAT:
        switch(t->width) {
        case DB_WIDTH_32:
            strcpy(buff, "float");
            break;
        case DB_WIDTH_64:
            strcpy(buff, "double");
            break;
        default: {
            db_id id;
            db_error("c_typePrimitivePlatformType: unsupported width for floating point type '%s'", db_fullname(t, id));
            goto error;
            break;
        }
        }
        break;
    case DB_ENUM:
    case DB_BITMASK:
        db_error("c_typePrimitivePlatformType: enumeration\\bitmasks types must be defined using the 'enum' keyword.");
        goto error;
        break;
    case DB_TEXT:
        strcpy(buff, "char*");
        break;
    case DB_ALIAS:
    	strcpy(buff, db_alias(t)->typeName);
    	break;
    }

    /* Append width */
    if (appendWidth) {
        switch(t->width) {
        case DB_WIDTH_8:
            strcat(buff, "8");
            break;
        case DB_WIDTH_16:
            strcat(buff, "16");
            break;
        case DB_WIDTH_32:
            strcat(buff, "32");
            break;
        case DB_WIDTH_64:
            strcat(buff, "64");
            break;
        case DB_WIDTH_WORD:
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
static db_string c_typeToUpper(db_string str, db_id buffer) {
    db_char *ptr, *bptr, ch;

    ptr = str;
    bptr = buffer;
    while((ch = *ptr)) {
        if (ch >= 97) {
            ch -= 32;
        }
        *bptr = ch;
        bptr++;
        ptr++;
    }
    *bptr = '\0';

    return buffer;
}

/* Translate constant to C-language id */
db_char* c_constantId(db_generator g, db_constant* c, db_char* buffer) {
    db_string prefix;
    db_id prefixUpper;

    prefix = g_getPrefix(g, c);
    if (prefix) {
        sprintf(buffer, "%s_%s", c_typeToUpper(prefix, prefixUpper), db_nameof(c));
    } else {
        c_typeToUpper(db_nameof(g_getCurrent(g)), prefixUpper);
        sprintf(buffer, "%s_%s", prefixUpper, db_nameof(c));
    }

    return buffer;
}

/* Parse type into C-specifier */
db_int16 c_specifierId(db_generator g, db_typedef t, db_char* specifier, db_bool* prefix, db_char* postfix) {

    if (postfix) {
        *postfix = '\0';
    }

    /* If type is not a reference, objects that are defined with it need to add a prefix. This
     * won't be used for members or nested type-specifiers. */
    if (prefix) {
        if (t->real->reference) {
            *prefix = FALSE;
        } else {
            *prefix = TRUE;
        }
    }

    /* Check if object is scoped */
    if (db_checkAttr(t, DB_ATTR_SCOPED)) {
        g_fullOid(g, t, specifier);
    } else {
        if (t != db_typedef(t->real)) {
            db_error("c_type: anonymous typedefs are not allowed.");
            goto error;
        }

        switch(db_type(t)->kind) {
        case DB_PRIMITIVE:
            c_primitiveId(db_primitive(t), specifier);
            break;
        case DB_COLLECTION: {
            db_id _specifier, _postfix;
            db_type elementType = db_collection(t)->elementType->real;
            switch(db_collection(t)->kind) {
            case DB_ARRAY:
                /* Get specifier of elementType */
                if (c_specifierId(g, db_collection(t)->elementType, _specifier, NULL, _postfix)) {
                    goto error;
                }
                if ((elementType->kind == DB_COLLECTION) && (db_collection(elementType)->kind == DB_ARRAY)) {
                    sprintf(specifier, "%s_%d", _specifier, db_collection(t)->max);
                } else {
                    sprintf(specifier, "%s_array%d", _specifier, db_collection(t)->max);
                }
                break;
            case DB_SEQUENCE:
                /* Get specifier of elementType */
                if (c_specifierId(g, db_collection(t)->elementType, _specifier, NULL, _postfix)) {
                    goto error;
                }
                if ((elementType->kind == DB_COLLECTION) && (db_collection(elementType)->kind == DB_SEQUENCE)) {
                    sprintf(specifier, "%s_%d", _specifier, db_collection(t)->max);
                } else {
                    if (db_collection(t)->max) {
                        sprintf(specifier, "%s_seq%d", _specifier, db_collection(t)->max);
                    } else {
                        sprintf(specifier, "%s_seq", _specifier);
                    }
                }
                break;
            case DB_LIST:
                if (c_specifierId(g, db_collection(t)->elementType, _specifier, NULL, _postfix)) {
                    goto error;
                }
                if ((elementType->kind == DB_COLLECTION) && (db_collection(elementType)->kind == DB_LIST)) {
                    sprintf(specifier, "%s_%d", _specifier, db_collection(t)->max);
                } else {
                    if (db_collection(t)->max) {
                        sprintf(specifier, "%s_list%d", _specifier, db_collection(t)->max);
                    } else {
                        sprintf(specifier, "%s_list", _specifier);
                    }
                }
                break;
            case DB_MAP:
                strcpy(specifier, "db_rbtree");
                break;
            }
            break;
        }
        default:
            db_error("c_type: anonymous type of kind '%s' not allowed.", db_nameof(db_enum_constant(db_typeKind_o, db_type(t)->kind)));
            goto error;
            break;
        }
    }

    return 0;
error:
    return -1;
}

db_char* c_escapeString(db_string str, db_id id) {
	db_char *ptr, *bptr, ch;

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

db_bool c_procedureHasThis(db_function o) {
    db_bool result;
    if (db_typeof(o) != db_typedef(db_observer_o)) {
        result = (db_instanceof(db_typedef(db_method_o), o) || 
                  db_instanceof(db_typedef(db_delegate_o), o) ||
                  db_instanceof(db_typedef(db_metaprocedure_o), o));
    } else {
        result = db_class_instanceof(db_class_o, db_parentof(o));
    }
    return result;
}

/* Translate a scope to a path */
db_char* c_topath(db_object o, db_id id) {
	db_uint32 offset;
	db_char ch, *ptr;
	db_fullname(o, id);

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

