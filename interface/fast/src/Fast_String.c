/* Fast_String.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "Fast.h"
#include "Fast__meta.h"

/* $header() */
#include "Fast.h"
#include "Fast_Parser.h"
#include "Fast__api.h"
Fast_Parser yparser(void);
void Fast_Parser_error(Fast_Parser _this, char* fmt, ...);

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
cx_char *Fast_String_parseEmbedded(Fast_String _this, cx_char *expr) {
    cx_char ch, *ptr;
    cx_uint32 nesting;
    Fast_Expression element;
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
            yparser()->line = Fast_Node(_this)->line;
            yparser()->column = Fast_Node(_this)->column;
            Fast_Parser_error(yparser(), "invalid embedded expression at '%s'", expr);
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

    element = Fast_Parser_parseExpression(yparser(), expr, _this->block, _this->scope, Fast_Node(_this)->line, Fast_Node(_this)->column);
    if (element) {
        cx_llAppend(_this->elements, element);
        cx_keep(element);
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
cx_int16 Fast_String_parse(Fast_String _this) {
    cx_char *ptr, ch, *str;
    Fast_String element;

    ptr = _this->value;
    str = ptr; /* Keep track of beginning of string-element */
    
    if (ptr) {
        /* Walk string, split embedded expressions */
        while((ch = *ptr)) {
            switch(ch) {
            case '$':
                /* Insert string-element */
                if (str != ptr) {
                    *ptr = '\0';

                    element = Fast_String__create(str);
                    cx_llAppend(_this->elements, element);

                    *ptr = ch;
                }

                /* Parse embedded expression */
                str = ptr = Fast_String_parseEmbedded(_this, ptr+1);
                if (!ptr) {
                    yparser()->line = Fast_Node(_this)->line;
                    yparser()->column = Fast_Node(_this)->column;
                    Fast_Parser_error(yparser(), "parsing string '%s' failed", _this->value);
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
        if ((str != _this->value) && *str) {
            element = Fast_String__create(str);
            cx_llAppend(_this->elements, element);
        }
    } else {
        element = Fast_String__create("null");
        cx_llAppend(_this->elements, element);
    }

    return 0;
error:
    return -1;
}

/* $end */

/* ::cortex::Fast::String::construct() */
cx_int16 Fast_String_construct(Fast_String _this) {
/* $begin(::cortex::Fast::String::construct) */
    
    if (!yparser()->block || !yparser()->scope) {
        goto error;
    }

    _this->block = yparser()->block; cx_keep_ext(_this, _this->block, "_this->block (keep block for string-expression)");
    _this->scope = yparser()->scope; cx_keep_ext(_this, _this->scope, "_this->scope (keep scope for string-expression)");
    
    return 0;
error:
    return -1;
/* $end */
}

/* ::cortex::Fast::String::getValue() */
cx_word Fast_String_getValue(Fast_String _this) {
/* $begin(::cortex::Fast::String::getValue) */
    cx_char *ptr, ch = '\0';
    cx_word result;

    /* Determine whether string has embedded expressions */
    if (_this->value) {
        ptr = _this->value;
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
        result = (cx_word)&_this->value;
    }

    return result;
/* $end */
}

/* ::cortex::Fast::String::init() */
cx_int16 Fast_String_init(Fast_String _this) {
/* $begin(::cortex::Fast::String::init) */
    Fast_Literal(_this)->kind = Fast_Text;
    return Fast_Literal_init((Fast_Literal)_this);
/* $end */
}

/* ::cortex::Fast::String::serialize(type dstType,word dst) */
cx_int16 Fast_String_serialize(Fast_String _this, cx_type dstType, cx_word dst) {
/* $begin(::cortex::Fast::String::serialize) */
    Fast_valueKind kind;

    kind = Fast_valueKindFromType(dstType);

    switch(kind) {
    case Fast_Bool:
    case Fast_Int:
    case Fast_SignedInt:
    case Fast_Text:
        cx_convert(cx_primitive(cx_string_o), &_this->value, cx_primitive(dstType), (void*)dst);
        break;
    case Fast_Ref: {
        cx_object o = cx_resolve_ext(NULL, NULL, _this->value, FALSE, "Serialize reference from string");
        cx_set_ext(NULL, &dst, o, "serialize string to reference");
        break;
    }
    default: {
        cx_id id;
        Fast_Parser_error(yparser(), "cannot serialize string value to storage of type '%s'", cx_fullname(dstType, id));
        goto error;
        break;
    }
    }

    return 0;
error:
    return -1;
/* $end */
}

/* ::cortex::Fast::String::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_String_toIc_v(Fast_String _this, cx_icProgram program, cx_icStorage storage, cx_bool stored) {
/* $begin(::cortex::Fast::String::toIc) */
    cx_ic result = NULL;
    cx_value v;
    CX_UNUSED(storage);
    CX_UNUSED(stored);

    /* Parse string after parsing script and thus not interfere with parser */
    if (Fast_String_parse(_this)) {
        goto error;
    }

    if (!cx_llSize(_this->elements)) {
        cx_valueLiteralInit(&v, CX_LITERAL_STRING, &_this->value);
        result = (cx_ic)cx_icLiteral__create(program, Fast_Node(_this)->line, v, cx_type(cx_string_o));
    } else {
        if (stored) {
            cx_iter elementIter;
            Fast_Expression element;
            cx_ic icElement1, icElement2;
            cx_icOp op;
            cx_uint32 elementCount = cx_llSize(_this->elements);
            cx_bool stored = FALSE;
            cx_ic dummy;
            cx_uint32 accPushCount = 0;
            cx_type elementType;

            if (storage && (storage->type != cx_type(cx_string_o))) {
                Fast_Parser_error(yparser(),
                        "storage for string-expression '%s' has invalid type (%s)",
                        _this->value,
                        cx_nameof(storage->type));
                goto error;
            }

            v.is.value.storage = 0; /* Create NULL-string */
            cx_valueLiteralInit(&v, CX_LITERAL_STRING, &v.is.value.storage);
            dummy = (cx_ic)cx_icLiteral__create(program, Fast_Node(_this)->line, v, cx_type(cx_string_o));

            result = (cx_ic)storage;
            elementIter = cx_llIter(_this->elements);
            while(cx_iterHasNext(&elementIter)) {
                cx_icAccumulator acc = cx_icProgram_accumulatorPush(program, Fast_Node(_this)->line, (cx_type)cx_string_o, FALSE);
                accPushCount++;
                element = cx_iterNext(&elementIter);

                elementType = Fast_Expression_getType(element);
                if (!elementType) {
                    element = Fast_Expression(Fast_String__create(CX_NULL_STRING));
                } else if (elementType != cx_type(cx_string_o)) {
                    element = Fast_Expression_cast(element, cx_type(cx_string_o), FALSE);
                    if(!element) {
                        goto error;
                    }
                }

                icElement1 = Fast_Node_toIc(Fast_Node(element), program, (cx_icStorage)acc, TRUE);
                if (!icElement1) {
                    goto error;
                }
                if (elementCount == 1) {
                    if (storage) {
                        op = cx_icOp__create(program, Fast_Node(_this)->line, CX_IC_STRCPY, NULL, (cx_icValue)storage, (cx_icValue)icElement1);
                        cx_icProgram_addIc(program, (cx_ic)op);
                    } else {
                        result = (cx_ic)icElement1;
                    }
                    stored = TRUE;
                } else {
                    if (elementCount) {
                        if (cx_iterHasNext(&elementIter)) {
                            cx_icAccumulator acc = cx_icProgram_accumulatorPush(program, Fast_Node(_this)->line, (cx_type)cx_string_o, FALSE);
                            accPushCount++;
                            element = cx_iterNext(&elementIter);
                            elementType = Fast_Expression_getType(element);

                            if (!elementType) {
                                element = Fast_Expression(Fast_String__create(CX_NULL_STRING));
                            } else if (elementType && (Fast_Expression_getType(element) != cx_type(cx_string_o))) {
                                element = Fast_Expression_cast(element, cx_type(cx_string_o), FALSE);
                                if (!element) {
                                    goto error;
                                }
                            }

                            icElement2 = Fast_Node_toIc(Fast_Node(element), program, (cx_icStorage)acc, TRUE);
                            if (!icElement2) {
                                goto error;
                            }
                            op = cx_icOp__create(program, Fast_Node(_this)->line, CX_IC_STRCAT, NULL, (cx_icValue)icElement1, (cx_icValue)icElement2);
                            cx_icProgram_addIc(program, (cx_ic)op);
                            elementCount--;
                        }
                    } else {
                        op = cx_icOp__create(program, Fast_Node(_this)->line, CX_IC_STRCAT, NULL, (cx_icValue)icElement1, (cx_icValue)dummy);
                        cx_icProgram_addIc(program, (cx_ic)op);
                    }
                }
                elementCount--;
            }

            /* If string is not yet copied, insert copy instruction */
            if (!stored) {
                op = cx_icOp__create(program, Fast_Node(_this)->line, CX_IC_STRCPY, NULL, (cx_icValue)storage, (cx_icValue)dummy);
                cx_icProgram_addIc(program, (cx_ic)op);
                stored = TRUE;
            }

            while(accPushCount) {
                cx_icProgram_accumulatorPop(program, Fast_Node(_this)->line);
                accPushCount--;
            }
        }
    }

    return result;
error:
    return NULL;
/* $end */
}
