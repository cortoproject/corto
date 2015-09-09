/* ast_String.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#define corto_ast_LIB
#include "ast.h"

/* $header() */
#include "ast__private.h"

static char alphaMask[256];
static char numericMask[256];
static int maskSet = 0;

static void cx_tokenMaskSet(cx_bool *mask, cx_string chars) {
    cx_char *ptr, ch;
    memset(mask, FALSE, sizeof(cx_bool) * 128);
    ptr = chars;
    while((ch = *ptr)) {
        mask[(int)ch] = TRUE;
        ptr++;
    }
}

/* Parse embedded expression */
cx_char *ast_String_parseEmbedded(ast_String this, cx_char *expr) {
    cx_char ch, *ptr;
    cx_uint32 nesting;
    ast_Expression element;
    cx_bool bracketExpr = FALSE;

    if (!maskSet) {
        cx_tokenMaskSet(alphaMask, ":abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_");
        cx_tokenMaskSet(numericMask, "0123456789");
    }

    ptr = expr;
    if (*ptr == '{') {
        bracketExpr = TRUE;
        expr = ++ptr; /* Progress expression as well to skip the initial '{' */
        nesting = 1;
        while((ch = *ptr) && nesting) {
            switch(ch) {
            case '{':
                nesting++;
                break;
            case '}':
                nesting--;
                break;
            }
            ptr++;
        }
        ptr--; /* Skip the last '{' */
    } else {
        /* If character is not a '{' parse a variable-name which is
         * delimited by a non-alphanumeric character. Additionally
         * variable names cannot start with a number. */
        if (!alphaMask[(int)*ptr]) {
            yparser()->line = ast_Node(this)->line;
            yparser()->column = ast_Node(this)->column;
            ast_Parser_error(yparser(), "invalid embedded expression at '%s'", expr);
            goto error;
        }
        ptr++;
        while((ch = *ptr) && (alphaMask[(int)ch] || numericMask[(int)ch])) {
            if (ch == ':') {
                ptr++;
                if (*ptr != ':') {
                    ptr--;
                    break;
                }
            }
            ptr++;
        }
    }

    ch = *ptr;
    *ptr = '\0';

    element = ast_Parser_parseExpression(yparser(), expr, this->block, this->scope, ast_Node(this)->line, ast_Node(this)->column);
    if (element) {
        cx_llAppend(this->elements, element);
        cx_claim(element);
    } else {
        goto error;
    }

    *ptr = ch;
    if (bracketExpr) {
        ptr++;
    }

    return ptr;
error:
    return NULL;
}

/* Walk embedded expressions in string */
cx_int16 ast_String_parse(ast_String this) {
    cx_char *ptr, ch, *str;
    ast_String element;

    ptr = this->value;
    str = ptr; /* Keep track of beginning of string-element */
    
    if (ptr) {
        /* Walk string, split embedded expressions */
        while((ch = *ptr)) {
            switch(ch) {
            case '$':
                /* Insert string-element */
                if (str != ptr) {
                    *ptr = '\0';

                    element = ast_StringCreate(str);
                    cx_llAppend(this->elements, element);

                    *ptr = ch;
                }

                /* Parse embedded expression */
                str = ptr = ast_String_parseEmbedded(this, ptr+1);
                if (!ptr) {
                    yparser()->line = ast_Node(this)->line;
                    yparser()->column = ast_Node(this)->column;
                    ast_Parser_error(yparser(), "parsing string '%s' failed", this->value);
                    goto error;
                }
                break;
            default:
                ptr++;
                break;
            }
        }

        /* If string contains embedded expressions, add last bit of remaining
         * string to elements list */
        if ((str != this->value) && *str) {
            element = ast_StringCreate(str);
            cx_llAppend(this->elements, element);
        }
    } else {
        element = ast_StringCreate("null");
        cx_llAppend(this->elements, element);
    }

    return 0;
error:
    return -1;
}

/* $end */

/* ::corto::ast::String::construct() */
cx_int16 _ast_String_construct(ast_String this) {
/* $begin(::corto::ast::String::construct) */
    
    if (!yparser()->block || !yparser()->scope) {
        goto error;
    }

    cx_setref(&this->block, yparser()->block);
    cx_setref(&this->scope, yparser()->scope);
    
    return 0;
error:
    return -1;
/* $end */
}

/* ::corto::ast::String::getValue() */
cx_word _ast_String_getValue(ast_String this) {
/* $begin(::corto::ast::String::getValue) */
    cx_char *ptr, ch = '\0';
    cx_word result;

    /* Determine whether string has embedded expressions */
    if (this->value) {
        ptr = this->value;
        while((ch = *ptr) && ch && (ch != '$')) {
            switch((cx_uint8)ch) {
            case '\\':
                ptr++;
                break;
            }
            ptr++;
        }
    }

    /* If string contains embedded expressions it does not have a compile-time
     * defined value. */
    if (ch == '$') {
        result = 0;
    } else {
        result = (cx_word)&this->value;
    }

    return result;
/* $end */
}

/* ::corto::ast::String::init() */
cx_int16 _ast_String_init(ast_String this) {
/* $begin(::corto::ast::String::init) */
    ast_Literal(this)->kind = Ast_Text;
    return ast_Literal_init((ast_Literal)this);
/* $end */
}

/* ::corto::ast::String::serialize(type dstType,word dst) */
cx_int16 _ast_String_serialize(ast_String this, cx_type dstType, cx_word dst) {
/* $begin(::corto::ast::String::serialize) */
    ast_valueKind kind;

    kind = ast_valueKindFromType(dstType);

    switch(kind) {
    case Ast_Bool:
    case Ast_Int:
    case Ast_SignedInt:
    case Ast_Text:
        cx_convert(cx_primitive(cx_string_o), &this->value, cx_primitive(dstType), (void*)dst);
        break;
    case Ast_Ref: {
        cx_object o = cx_resolve(NULL, this->value);
        cx_setref(&dst, o);
        cx_release(o);
        break;
    }
    default: {
        cx_id id;
        ast_Parser_error(yparser(), "cannot serialize string value to storage of type '%s'", ast_Parser_id(dstType, id));
        goto error;
        break;
    }
    }

    return 0;
error:
    return -1;
/* $end */
}

/* ::corto::ast::String::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node _ast_String_toIc_v(ast_String this, ic_program program, ic_storage storage, cx_bool stored) {
/* $begin(::corto::ast::String::toIc) */
    ic_node result = NULL;
    CX_UNUSED(storage);
    CX_UNUSED(stored);

    /* Parse string after parsing script and thus not interfere with parser */
    if (ast_String_parse(this)) {
        goto error;
    }

    if (!cx_llSize(this->elements)) {
        result = (ic_node)ic_literalCreate((cx_any){cx_type(cx_string_o), &this->value, FALSE});
    } else {
        if (stored) {
            cx_iter elementIter;
            ast_Expression element;
            ic_node icElement1, icElement2;
            cx_uint32 elementCount = cx_llSize(this->elements);
            cx_bool stored = FALSE;
            ic_node dummy;
            cx_uint32 accPushCount = 0;
            cx_type elementType;

            if (storage && (storage->type != cx_type(cx_string_o))) {
                ast_Parser_error(yparser(),
                        "storage for string-expression '%s' has invalid type (%s)",
                        this->value,
                        cx_nameof(storage->type));
                goto error;
            }

            dummy = (ic_node)ic_literalCreate((cx_any){cx_type(cx_string_o), NULL, FALSE});

            result = (ic_node)storage;
            elementIter = cx_llIter(this->elements);
            while(cx_iterHasNext(&elementIter)) {
                ic_accumulator acc = ic_program_pushAccumulator(program, (cx_type)cx_string_o, FALSE, FALSE);
                accPushCount++;
                element = cx_iterNext(&elementIter);

                elementType = ast_Expression_getType(element);
                if (!elementType) {
                    element = ast_Expression(ast_StringCreate(CX_NULL_STRING));
                } else if (elementType != cx_type(cx_string_o)) {
                    element = ast_Expression_cast(element, cx_type(cx_string_o), FALSE);
                    if(!element) {
                        goto error;
                    }
                }

                icElement1 = ast_Node_toIc(ast_Node(element), program, (ic_storage)acc, TRUE);
                if (!icElement1) {
                    goto error;
                }
                if (elementCount == 1) {
                    if (storage) {
                        IC_2(program, ast_Node(this)->line, ic_strcpy, storage, icElement1, IC_DEREF_VALUE, IC_DEREF_VALUE);
                    } else {
                        result = (ic_node)icElement1;
                    }
                    stored = TRUE;
                } else {
                    if (elementCount) {
                        if (cx_iterHasNext(&elementIter)) {
                            ic_accumulator acc = ic_program_pushAccumulator(program, (cx_type)cx_string_o, FALSE, FALSE);
                            accPushCount++;
                            element = cx_iterNext(&elementIter);
                            elementType = ast_Expression_getType(element);

                            if (!elementType) {
                                element = ast_Expression(ast_StringCreate(CX_NULL_STRING));
                            } else if (elementType && (ast_Expression_getType(element) != cx_type(cx_string_o))) {
                                element = ast_Expression_cast(element, cx_type(cx_string_o), FALSE);
                                if (!element) {
                                    goto error;
                                }
                            }

                            icElement2 = ast_Node_toIc(ast_Node(element), program, (ic_storage)acc, TRUE);
                            if (!icElement2) {
                                goto error;
                            }
                            IC_2(program, ast_Node(this)->line, ic_strcat, icElement1, icElement2, IC_DEREF_VALUE, IC_DEREF_VALUE);
                            elementCount--;
                        }
                    } else {
                        IC_2(program, ast_Node(this)->line, ic_strcat, icElement1, dummy, IC_DEREF_VALUE, IC_DEREF_VALUE);
                    }
                }
                elementCount--;
            }

            /* If string is not yet copied, insert copy instruction */
            if (!stored) {
                IC_2(program, ast_Node(this)->line, ic_strcpy, storage, dummy, IC_DEREF_VALUE, IC_DEREF_VALUE);
                stored = TRUE;
            }

            while(accPushCount) {
                ic_program_popAccumulator(program);
                accPushCount--;
            }
        }
    }

    return result;
error:
    return NULL;
/* $end */
}
