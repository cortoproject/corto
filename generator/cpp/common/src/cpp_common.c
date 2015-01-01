/*
 * c_common.c
 *
 *  Created on: Dec 21, 2012
 *      Author: sander
 */

#include "cpp_common.h"
#include "cx__meta.h"

cx_bool cpp_classToUpper = FALSE;

/* Function builds a scope-stack from root to module */
static void
cpp_scopeStack(
    cx_object module,
    cx_object* stack /* cx_object[SD_MAX_SCOPE_DEPTH] */)
{
    cx_uint32 count;
    cx_object ptr;

    cx_assert(module != NULL, "NULL passed for module to sd_utilModuleStack");

    /* Count scope depth */
    ptr = module;
    count = 1; /* For self */
    while((ptr = cx_parentof(ptr))) {
        count++;
    }

    if (count > CX_MAX_SCOPE_DEPTH) {
        cx_error("sd_printXmlCollection: unsupported scope-depth (depth=%d, max=%d).", count, CX_MAX_SCOPE_DEPTH);
    }
    cx_assert(count <= CX_MAX_SCOPE_DEPTH, "MAX_SCOPE_DEPTH overflow.");

    /* Fill module stack */
    ptr = module;
    while(count) {
        stack[count-1] = ptr;
        ptr = cx_parentof(ptr);
        count--;
    }

    /* ptr should be NULL */
    cx_assert(!ptr, "ptr is NULL.");
}

/* Find first common module in two module-stacks */
static cx_object
cpp_commonScope(
    cx_object from,
    cx_object to,
    cx_object* fromStack,
    cx_object* toStack,
    cx_uint32* i_out)
{
    cx_object fromPtr, toPtr;
    cx_uint32 i;

    /* fromPtr and toPtr will initially point to base */
    i = 0;
    do {
        fromPtr = fromStack[i];
        toPtr = toStack[i];
        i++;
    }while((fromPtr != from) && (toPtr != to) && (fromStack[i] == toStack[i]));

    /* Common module is now stored in fromPtr and toPtr. */

    if (i_out) {
        *i_out = i;
    }

    return fromPtr;
}

/* Check whether a type translates to a native construct or may act as a C++ namespace */
cx_bool
cpp_nativeType(cx_object o) {
	cx_bool result = FALSE;

	if (cx_class_instanceof(cx_type_o, o)) {
		switch(cx_type(o)->kind) {
		case CX_VOID:
		    if (cx_type(o)->reference) {
		        result = TRUE;
		    }
			break;
		default:
			result = TRUE;
			break;
		}
	}

	return result;
}

/* Open a scope */
void
cpp_openScope(
    g_file file,
    cx_object to)
{
    cx_object from;

    /* Do not open namespaces for non-void type-scopes */
    while(cpp_nativeType(to)) {
    	to = cx_parentof(to);
    }

    /* If context->module is NULL, start from root */
    from = g_fileScopeGet(file);
    if (!from) {
        from = root_o;
    }

    /* If from and to are not equal, find shortest path between modules. */
    if (from != to) {
        cx_object fromStack[CX_MAX_SCOPE_DEPTH], toStack[CX_MAX_SCOPE_DEPTH];
        cx_object fromPtr, toPtr;
        cx_uint32 i;

        /* Find common module. First build up a scope-stack for the two modules which
         * are ordered base -> <module>. Then walk through these stacks to find the
         * last common module. */
        cpp_scopeStack(from, fromStack);
        cpp_scopeStack(to, toStack);
        fromPtr = toPtr = cpp_commonScope(from, to, fromStack, toStack, &i);

        /* Walk down from module 'from' to 'toPtr' */
        fromPtr = from;
        while(fromPtr != toPtr) {
            g_fileDedent(file);
            g_fileWrite(file, "}\n");
            fromPtr = cx_parentof(fromPtr);
        }

        /* Walk from toPtr to 'to' */
        while(toPtr != to) {
            cx_id id;
            toPtr = toStack[i];
            g_fileWrite(file, "namespace %s {\n", g_oid(g_fileGetGenerator(file), toPtr, id));
            g_fileIndent(file);
            i++;
        }

        /* Update context->module */
        g_fileScopeSet(file, to);
    }
}

void cpp_closeScope(g_file file) {
    cx_object ptr;

    if ((ptr = g_fileScopeGet(file))) {
        while((ptr = cx_parentof(ptr))) {
            g_fileDedent(file);
            g_fileWrite(file, "}\n");
        }

        g_fileScopeSet(file, NULL);
    }
}

/* Escape language keywords */
static int cpp_keywordEscape(cx_string inputName, cx_string buffer) {

    if ( !strcmp(inputName, "alignas") ||
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

cx_string cortex_genId(cx_string str, cx_id id) {
    cx_char *ptr, ch, *bptr;
    cx_id buff;

    ptr = str;

    *id = '\0';

    /* Translate identifier to C++ */
    bptr = buff;
    while((ch = *ptr)) {
        switch(ch) {
        case ':':
            if (bptr != buff) {
                *bptr = '\0';
                cpp_keywordEscape(buff, buff);
                strcat(id, buff);
            }
            strcat(id, "::");
            bptr = buff;
            *bptr = '\0';
            ptr++;
            break;
        default:
            *bptr = ch;
            bptr++;
            break;
        }
        ptr++;
    }
    *bptr = '\0';
    cpp_keywordEscape(buff, buff);
    strcat(id, buff);

    return id;
}

/* Get string representing the base-platform type */
cx_char* cpp_primitiveId(cx_primitive t, cx_char* buff) {
    cx_bool appendWidth, appendT;

    appendWidth = FALSE;
    appendT = FALSE;

    switch(t->kind) {
    case CX_BOOLEAN:
    	strcpy(buff, "bool");
    	break;
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
    case CX_ALIAS:
        strcpy(buff, cx_alias(t)->typeName);
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
/*static cx_string cpp_toUpper(cx_string str, cx_id buffer) {
    cx_char *ptr, *bptr, ch;

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
}*/

/* Translate constant to C++ language id */
cx_char* cpp_constantId(cx_generator g, cx_constant* c, cx_char* buffer) {
	CX_UNUSED(g);

    sprintf(buffer, "%s", cx_nameof(c));

    return buffer;
}

/* Parse type into C-specifier */
cx_char* cpp_specifierId(cx_generator g, cx_typedef t, cx_id specifier) {

    /* Check if object is scoped */
    if (cx_checkAttr(t, CX_ATTR_SCOPED)) {
        g_fullOid(g, t, specifier);
    } else {
        if (t != cx_typedef(t->real)) {
            cx_error("c_type: anonymous typedefs are not allowed.");
            goto error;
        }

        switch(cx_type(t)->kind) {
        case CX_PRIMITIVE:
            cpp_primitiveId(cx_primitive(t), specifier);
            break;
        case CX_COLLECTION: {
            cx_id _specifier;
            cx_type elementType;
            g_idKind prev;

            prev = g_setIdKind(g, CX_GENERATOR_ID_CLASS_LOWER);

            elementType = cx_collection(t)->elementType->real;
            switch(cx_collection(t)->kind) {
            case CX_ARRAY:
                /* Get specifier of elementType */
                if (!cpp_specifierId(g, cx_collection(t)->elementType, _specifier)) {
                    goto error;
                }
                if ((elementType->kind == CX_COLLECTION) && (cx_collection(elementType)->kind == CX_ARRAY)) {
                    sprintf(specifier, "%s_%d", _specifier, cx_collection(t)->max);
                } else {
                    sprintf(specifier, "%s_array%d", _specifier, cx_collection(t)->max);
                }
                break;
            case CX_SEQUENCE:
                /* Get specifier of elementType */
                if (!cpp_specifierId(g, cx_collection(t)->elementType, _specifier)) {
                    goto error;
                }
                if ((elementType->kind == CX_COLLECTION) && (cx_collection(elementType)->kind == CX_SEQUENCE)) {
                    sprintf(specifier, "%s_%d", _specifier, cx_collection(t)->max);
                } else {
                    if (cx_collection(t)->max) {
                        sprintf(specifier, "%s_seq%d", _specifier, cx_collection(t)->max);
                    } else {
                        sprintf(specifier, "%s_seq", _specifier);
                    }
                }
                break;
            case CX_LIST:
                strcpy(specifier, "cortex::ll_h");
                break;
            case CX_MAP:
                strcpy(specifier, "cortex::rbtree_h");
                break;
            }

            g_setIdKind(g, prev);
            break;
        }
        default:
            cx_error("c_type: anonymous type of kind '%s' not allowed.", cx_nameof(cx_enum_constant(cx_typeKind_o, cx_type(t)->kind)));
            goto error;
            break;
        }
    }

    return specifier;
error:
    return NULL;
}

/* Parse type to Cpp name (for use in declarations) */
cx_char* cpp_specifierDecl(cx_generator g, cx_typedef t, cx_char* specifier) {
    cx_id spec;
    cx_char *ptr;

    /* Get the complete specifier */
    cpp_specifierId(g, t, spec);

    /* Strip the scope */
    ptr = spec + strlen(spec);
    while((*ptr != ':')) {
        ptr--;
    }
    ptr++;
    strcpy(specifier, ptr);
    return specifier;
}

/* Translate a scope to a path */
cx_char* cpp_topath(cx_object o, cx_id id) {
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

static void cpp_escapeParameters(cx_char *ptr) {
	cx_char ch;
	cx_uint32 offset = 0;
	while((ch = *ptr)) {
		switch(ch) {
		case '(':
		case '{':
		case ',':
			*(ptr-offset) = '_';
			break;
		case ')':
		case '}':
			offset++;
			break;
		case ':':
			*(ptr-offset) = '_';
			offset++;
			break;
		case ' ':
			*(ptr-offset) = '_';
			break;
		default:
			*(ptr-offset) = ch;
			break;
		}
		ptr++;
	}
	*(ptr - offset) = '\0';
}

const cx_char *cpp_metaPostfix(cpp_metaIdKind kind) {\
	cx_char* postfix = NULL;
	switch(kind) {
	case CPP_DEFAULT:
		postfix = "";
		break;
	case CPP_HANDLE:
		postfix = "_h";
		break;
	case CPP_OBJECT:
		postfix = "_o";
		break;
	default:
		cx_assert(0, "invalid metaIdKind (%d)", kind);
		break;
	}

	return postfix;
}

/* Get meta-object identifier */
cx_char* cpp_metaFullname(cx_generator g, cx_object o, cpp_metaIdKind kind, cx_id id) {
	cx_char *ptr;
	const cx_char *postfix;
	g_idKind prev;

	postfix = cpp_metaPostfix(kind);
	prev = g_setIdKind(g, CX_GENERATOR_ID_DEFAULT);

	if (o != root_o) {
		if (cpp_nativeType(cx_parentof(o))) {
		    cx_id tmp;
			g_fullOid(g, cx_parentof(cx_parentof(o)), id);
			strcat(id, "::");
			strcat(id, g_oid(g, cx_parentof(o), tmp));
			strcat(id, "_");
			strcat(id, g_oid(g, o, tmp));
		} else {
			g_fullOidExt(g, o, id, CX_GENERATOR_ID_DEFAULT);
		}

		if ((ptr = strchr(id, '('))) {
			if (!cx_function(o)->overloaded) {
				*ptr = '\0';
			} else {
				cpp_escapeParameters(ptr);
			}
		}

		strcat(id, postfix);
	} else {
		strcpy(id, "::root");
		strcat(id, postfix);
	}

    /* Reset ID-kind */
    g_setIdKind(g, prev);

	return id;
}

/* Get meta-object identifier */
cx_char* cpp_metaName(cx_generator g, cx_object o, cpp_metaIdKind kind, cx_id id) {
	cx_char *ptr;
	const cx_char *postfix;
	g_idKind prev;

	postfix = cpp_metaPostfix(kind);
	prev = g_setIdKind(g, CX_GENERATOR_ID_DEFAULT);

	if (o != root_o) {
        cx_id tmp;
		if (cpp_nativeType(cx_parentof(o))) {
			g_oid(g, cx_parentof(o), id);
			strcat(id, "_");
			strcat(id, g_oid(g, o, tmp));
		} else {
			g_id(g, g_oid(g, o, tmp), id);
		}

		if ((ptr = strchr(id, '('))) {
			if (!cx_function(o)->overloaded) {
				*ptr = '\0';
			} else {
				cpp_escapeParameters(ptr);
			}
		}

		strcat(id, postfix);
	} else {
		strcpy(id, "root");
		strcat(id, postfix);
	}

	/* Reset ID-kind */
	g_setIdKind(g, prev);

	return id;
}

/* Get procedure id (without parameterlist */
cx_char* cpp_procId(cx_generator g, cx_function o, cx_id id) {
    cx_char *ptr;
    g_oid(g, o, id);
    ptr = strchr(id, '(');
    if (ptr) {
        *ptr = '\0';
    }
    return id;
}

