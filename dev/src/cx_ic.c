/*
 * cx_ic.c
 *
 *  Created on: Aug 14, 2013
 *      Author: sander
 */

#include "cx_mem.h"
#include "cx_ic.h"
#include "cx_ll.h"
#include "cx_object.h"
#include "cx_string.h"
#include "cx__meta.h"
#include "cx_util.h"

static cx_string cx_icLiteral_toString(cx_icLiteral _this, cx_string string) {
    switch(_this->value.is.literal.kind) {
    case CX_LITERAL_BOOLEAN:
        string = strappend(string, "%s", _this->value.is.literal.v._boolean ? "true" : "false");
        break;
    case CX_LITERAL_CHARACTER:
        string = strappend(string, "%c", _this->value.is.literal.v._character);
        break;
    case CX_LITERAL_INTEGER:
        string = strappend(string, "%lld", _this->value.is.literal.v._integer);
        break;
    case CX_LITERAL_UNSIGNED_INTEGER:
        string = strappend(string, "%llu", _this->value.is.literal.v._unsigned_integer);
        break;
    case CX_LITERAL_FLOATING_POINT:
        string = strappend(string, "%f", _this->value.is.literal.v._floating_point);
        break;
    case CX_LITERAL_STRING:
        string = strappend(string, "\"%s\"", _this->value.is.literal.v._string);
        break;
    case CX_LITERAL_NULL:
        string = strappend(string, "null");
        break;
    }
    return string;
}

static cx_string cx_icValue_toString(cx_icValue operand, cx_string string) {
    switch(operand->_parent.kind) {
    case CX_IC_STORAGE:
        if (((cx_icStorage)operand)->kind == CX_STORAGE_ACCUMULATOR) {
            string = strappend(string, "%%%s", ((cx_icStorage)operand)->name);
        } else {
            string = strappend(string, "%s", ((cx_icStorage)operand)->name);
        }
        break;
    case CX_IC_LITERAL:
        string = cx_icLiteral_toString(((cx_icLiteral)operand), string);
        break;
    case CX_IC_LABEL:
        string = strappend(string, "%d", ((cx_icLabel)operand)->id);
        break;
    case CX_IC_FUNCTION: {
        cx_id id;
        string = strappend(string, "%s", cx_fullname(((cx_icFunction)operand)->function, id));
        break;
    }
    default:
        string = strappend(string, "invalid operand");
        break;
    }
    return string;
}

#ifdef CX_IC_TRACING
static cx_string cx_opKind_toString(cx_icOpKind kind) {
    switch(kind) {
    /* Set (assign) */
    case CX_IC_SET: return "set";

    /* Cast */
    case CX_IC_CAST: return "cast";

    /* String concatenation */
    case CX_IC_STRCAT: return "strcat";
    case CX_IC_STRCPY: return "strcpy";

    /* Memory management */
    case CX_IC_NEW: return "new";
    case CX_IC_DEFINE: return "define";
    case CX_IC_FREE: return "free";
    case CX_IC_KEEP: return "keep";

    /* Notifications */
    case CX_IC_UPDATE: return "update";
    case CX_IC_UPDATEBEGIN: return "updatebegin";
    case CX_IC_UPDATEEND: return "updateend";
    case CX_IC_UPDATECANCEL: return "updatecancel";

    /* Waiting */
    case CX_IC_WAITFOR: return "waitfor";
    case CX_IC_WAIT: return "wait";

    /* Operators */
    case CX_IC_ADD: return "add";
    case CX_IC_SUB: return "sub";
    case CX_IC_MUL: return "mul";
    case CX_IC_DIV: return "div";
    case CX_IC_MOD: return "mod";
    case CX_IC_INC: return "inc";
    case CX_IC_DEC: return "dec";
    case CX_IC_XOR: return "xor";
    case CX_IC_OR: return "or";
    case CX_IC_AND: return "and";
    case CX_IC_NOT: return "not";
    case CX_IC_SHIFT_LEFT: return "shiftleft";
    case CX_IC_SHIFT_RIGHT: return "shiftright";
    case CX_IC_COND_OR: return "cor";
    case CX_IC_COND_AND: return "cand";
    case CX_IC_COND_NOT: return "cnot";
    case CX_IC_COND_EQ: return "ceq";
    case CX_IC_COND_NEQ: return "cneq";
    case CX_IC_COND_GT: return "cgt";
    case CX_IC_COND_LT: return "clt";
    case CX_IC_COND_GTEQ: return "cgteq";
    case CX_IC_COND_LTEQ: return "clteq";

    /* Program control */
    case CX_IC_JUMP: return "jump";
    case CX_IC_JEQ: return "jeq";
    case CX_IC_JNEQ: return "jneq";
    case CX_IC_STOP: return "stop";

    /* Function calls */
    case CX_IC_PUSH: return "push";
    case CX_IC_CALL: return "call";
    case CX_IC_RET: return "ret";
    default:
        break;
    }
    return "???";
}

static cx_string cx_icOp_derefToString(cx_string string, cx_icValue s, cx_icDerefMode mode) {
    if (((cx_ic)s)->kind == CX_IC_STORAGE) {
        cx_type t = ((cx_icStorage)s)->type;
        if (t->reference) {
            if (mode == CX_IC_DEREF_VALUE) {
                string = strappend(string, " *");
            } else {
                string = strappend(string, " ");
            }
        } else {
            if (mode == CX_IC_DEREF_ADDRESS) {
                string = strappend(string, " &");
            } else {
                string = strappend(string, " ");
            }
        }
    } else {
        string = strappend(string, " ");
    }

    return string;
}

cx_string cx_icOp_toString(cx_icOp _this, cx_string string)  {
    string = strappend(string, "\t%s", cx_opKind_toString(_this->kind));
    if (_this->s1) {
        string = cx_icOp_derefToString(string, _this->s1, _this->s1Deref);
        string = cx_icValue_toString(_this->s1, string);
    } else if (_this->s2 || _this->s3) {
        string = strappend(string, " .");
    }
    if (_this->s2) {
        string = cx_icOp_derefToString(string, _this->s2, _this->s2Deref);
        string = cx_icValue_toString(_this->s2, string);
    } else if (_this->s3) {
        string = strappend(string, " .");
    }
    if (_this->s3) {
        string = cx_icOp_derefToString(string, _this->s3, _this->s3Deref);
        string = cx_icValue_toString(_this->s3, string);
    }
    return string;
}

static cx_string cx_icStorage_toString(cx_icStorage _this, cx_string string) {
    cx_id id;

    switch(_this->kind) {
    case CX_STORAGE_ACCUMULATOR:
        string = strappend(string, "%%acc %s %s", _this->name, cx_fullname(_this->type, id));
        break;
    case CX_STORAGE_MEMBER:
        string = strappend(string, "%%mbr %s %s", _this->name, cx_fullname(_this->type, id));
        break;
    case CX_STORAGE_ELEMENT:
        string = strappend(string, "%%elem %s %s", _this->name, cx_fullname(_this->type, id));
        break;
    case CX_STORAGE_LOCAL:
        string = strappend(string, "%%local %s %s", _this->name, cx_fullname(_this->type, id));
        break;
    case CX_STORAGE_OBJECT:
        string = strappend(string, "%%object %s %s", _this->name, cx_fullname(_this->type, id));
        break;
    }

    return string;
}

static cx_string cx_icLabel_toString(cx_icLabel _this, cx_string string) {
    string = strappend(string, "%%label %d", _this->id);
    return string;
}

static cx_string cx_icFunction_toString(cx_icFunction _this, cx_string string) {
    cx_id id;
    string = strappend(string, "\n%%function %s", cx_fullname(_this->function, id));
    return string;
}

static cx_string cx_icScope_toString(cx_icScope _this, cx_string result) {
    cx_iter programIter, storageIter;
    cx_icStorage storage;
    cx_uint32 storages = 0;
    cx_ic ic;

    /* Count storages */
    storageIter = cx_llIter(_this->storages);
    while(cx_iterHasNext(&storageIter)) {
        storage = cx_iterNext(&storageIter);
        if (storage->kind == CX_STORAGE_LOCAL) {
            storages ++;
        }
    }

    /* No need to push a scope when there are no local storages */
    if (storages) {
        result = strappend(result, "%%scopepush\n");
    }

    /* Print storages */
    storageIter = cx_llIter(_this->storages);
    while(cx_iterHasNext(&storageIter)) {
        storage = cx_iterNext(&storageIter);
        if (storage->kind == CX_STORAGE_LOCAL) {
            cx_id id;
            result = strappend(result, "%%local %s %s\n", storage->name, cx_fullname(storage->type, id));
        }
    }

    /* List local storages */

    programIter = cx_llIter(_this->program);
    while(cx_iterHasNext(&programIter)) {
        ic = cx_iterNext(&programIter);
        switch(ic->kind) {
        case CX_IC_STORAGE:
            result = cx_icStorage_toString((cx_icStorage)ic, result);
            result = strappend(result, "\n");
            break;
        case CX_IC_LABEL:
            result = cx_icLabel_toString((cx_icLabel)ic, result);
            result = strappend(result, "\n");
            break;
        case CX_IC_FUNCTION:
            result = cx_icFunction_toString((cx_icFunction)ic, result);
            result = strappend(result, "\n");
            break;
        case CX_IC_OP:
            result = cx_icOp_toString((cx_icOp)ic, result);
            result = strappend(result, "\n");
            break;
        case CX_IC_SCOPE:
            result = cx_icScope_toString((cx_icScope)ic, result);
            break;
        default:
            result = strappend(result, "invalid instruction");
            break;
        }
    }

    if (storages) {
        result = strappend(result, "%%scopepop\n");
    }

    return result;
}
#endif

static cx_bool cx_ic_validateSet(cx_icOp op) {
    cx_bool result = TRUE;
    op->s1 && (((cx_ic)op->s1)->kind != CX_IC_STORAGE) ? result = FALSE: 0;
    !op->s2 || (((cx_ic)op->s2)->kind != CX_IC_STORAGE) ? result = FALSE: 0;
    !op->s2 ? result = FALSE : 0;
    return result;
}

static cx_bool cx_ic_validateCast(cx_icOp op) {
    cx_bool result = TRUE;
    op->s1 && (((cx_ic)op->s1)->kind != CX_IC_STORAGE) ? result = FALSE: 0;
    !op->s2 || (((cx_ic)op->s2)->kind != CX_IC_STORAGE) ? result = FALSE: 0;
    !op->s3 || (((cx_ic)op->s3)->kind != CX_IC_STORAGE) ? result = FALSE: 0;
    return result;
}

static cx_bool cx_ic_validateBinary(cx_icOp op) {
    cx_bool result = TRUE;
    op->s1 && (((cx_ic)op->s1)->kind != CX_IC_STORAGE) ? result = FALSE: 0;
    !op->s2 || !op->s3 ? result = FALSE: 0;
    if (result) {
        if ((((cx_ic)op->s2)->kind != CX_IC_STORAGE) && (((cx_ic)op->s3)->kind != CX_IC_STORAGE)) {
            result = FALSE;
        }
    }
    return result;
}

static cx_bool cx_ic_validateUnary(cx_icOp op) {
    cx_bool result = TRUE;
    op->s1 && (((cx_ic)op->s1)->kind != CX_IC_STORAGE) ? result = FALSE: 0;
    op->s2 && (((cx_ic)op->s2)->kind != CX_IC_STORAGE) ? result = FALSE: 0;
    return result;
}

static cx_bool cx_ic_validatePush(cx_icOp op) {
    if (!op->s1) {
        return FALSE;
    } else {
        return TRUE;
    }
}

cx_string cx_icKind_toString(cx_icKind kind) {
    switch(kind) {
        case CX_IC_STORAGE: return "storage";
        case CX_IC_LITERAL: return "literal";
        case CX_IC_LABEL: return "label";
        case CX_IC_ADDRESS: return "address";
        case CX_IC_FUNCTION: return "function";
        case CX_IC_OP: return "op";
        case CX_IC_SCOPE: return "scope";
    }
    return "???";
}

static cx_bool cx_icValidate(cx_icOp op) {
    cx_bool result = TRUE;

    switch(op->kind) {
            /* Set (assign) */
        case CX_IC_SET: result = cx_ic_validateSet(op); break;
            
            /* Cast */
        case CX_IC_CAST: result = cx_ic_validateCast(op); break;
            
            /* String concatenation */
        case CX_IC_STRCAT: result = TRUE; break;
        case CX_IC_STRCPY: result = TRUE; break;
            
            /* Memory management */
        case CX_IC_NEW: result = TRUE; break;
        case CX_IC_DEFINE: result = TRUE; break;
        case CX_IC_FREE: result = TRUE; break;
        case CX_IC_KEEP: result = TRUE; break;
            
            /* Notifications */
        case CX_IC_UPDATE: result = TRUE; break;
        case CX_IC_UPDATEBEGIN: result = TRUE; break;
        case CX_IC_UPDATEEND: result = TRUE; break;
        case CX_IC_UPDATECANCEL: result = TRUE; break;
            
            /* Waiting */
        case CX_IC_WAITFOR: result = TRUE; break;
        case CX_IC_WAIT: result = TRUE; break;
            
            /* Operators */
        case CX_IC_ADD: result = cx_ic_validateBinary(op); break;
        case CX_IC_SUB: result = cx_ic_validateBinary(op); break;
        case CX_IC_MUL: result = cx_ic_validateBinary(op); break;
        case CX_IC_DIV: result = cx_ic_validateBinary(op); break;
        case CX_IC_MOD: result = cx_ic_validateBinary(op); break;
        case CX_IC_INC: result = cx_ic_validateUnary(op); break;
        case CX_IC_DEC: result = cx_ic_validateUnary(op); break;
        case CX_IC_XOR: result = cx_ic_validateBinary(op); break;
        case CX_IC_OR: result = cx_ic_validateBinary(op); break;
        case CX_IC_AND: result = cx_ic_validateBinary(op); break;
        case CX_IC_NOT: result = cx_ic_validateUnary(op); break;
        case CX_IC_SHIFT_LEFT: result = cx_ic_validateBinary(op); break;
        case CX_IC_SHIFT_RIGHT: result = cx_ic_validateBinary(op); break;
        case CX_IC_COND_OR: result = cx_ic_validateBinary(op); break;
        case CX_IC_COND_AND: result = cx_ic_validateBinary(op); break;
        case CX_IC_COND_NOT: result = cx_ic_validateUnary
            (op); break;
        case CX_IC_COND_EQ: result = cx_ic_validateBinary(op); break;
        case CX_IC_COND_NEQ: result = cx_ic_validateBinary(op); break;
        case CX_IC_COND_GT: result = cx_ic_validateBinary(op); break;
        case CX_IC_COND_LT: result = cx_ic_validateBinary(op); break;
        case CX_IC_COND_GTEQ: result = cx_ic_validateBinary(op); break;
        case CX_IC_COND_LTEQ: result = cx_ic_validateBinary(op); break;
            
            /* Program control */
        case CX_IC_JUMP: result = TRUE; break;
        case CX_IC_JEQ: result = TRUE; break;
        case CX_IC_JNEQ: result = TRUE; break;
        case CX_IC_STOP: result = TRUE; break;
            
            /* Function calls */
        case CX_IC_PUSH: result = cx_ic_validatePush(op); break;
        case CX_IC_CALL: result = TRUE; break;
        case CX_IC_RET: result = TRUE; break;
        default: printf("unknown operation!\n"); result = FALSE; break;
    }

#ifdef CX_IC_TRACING
    if (!result) {
        printf("%s:%d: invalid operands for '%s' (%s, %s, %s)\n",
               ((cx_ic)op)->program->filename,
               ((cx_ic)op)->line, cx_opKind_toString(op->kind),
               op->s1 ? cx_icKind_toString(((cx_ic)op->s1)->kind) : "<none>",
               op->s2 ? cx_icKind_toString(((cx_ic)op->s2)->kind) : "<none>",
               op->s3 ? cx_icKind_toString(((cx_ic)op->s3)->kind) : "<none>");
    }
#else
    if (!result) {
    printf("%s:%d: invalid operands (build with CX_IC_TRACING to get more information)\n",
           ((cx_ic)op)->program->filename,
           ((cx_ic)op)->line);
    }
#endif    
    return result;
}

cx_string cx_icProgram_toString(cx_icProgram program) {
    cx_string result = NULL;
    CX_UNUSED(program);

#ifdef CX_IC_TRACING
    cx_iter storageIter;
    cx_icStorage storage;

    result = strappend(result, "%%file %s\n", program->filename);

    /* Print storages */
    storageIter = cx_llIter(program->storages);
    while(cx_iterHasNext(&storageIter)) {
        storage = cx_iterNext(&storageIter);
        if (storage->kind == CX_STORAGE_OBJECT) {
            cx_object o;
            o = ((cx_icObject)storage)->ptr;
            if (o) {
                cx_string objectValue = cx_toString(o, 0);
                result = strappend(result, "%%object %s %s\n", storage->name, objectValue);
                cx_dealloc(objectValue);
            }
        }
    }

    result = cx_icScope_toString(program->scope, result);
#endif
    return result;
}

cx_icStorage cx_icScope_lookupStorage(cx_icScope scope, cx_string name, cx_bool recursive) {
    cx_iter storageIter;
    cx_icStorage result = NULL;

    storageIter = cx_llIter(scope->storages);
    while(cx_iterHasNext(&storageIter)) {
        result = cx_iterNext(&storageIter);
        if (!strcmp(result->name, name)) {
            break;
        } else {
            result = NULL;
        }
    }

    if (!result && scope->parent && recursive && !scope->isFunction) {
        result = cx_icScope_lookupStorage(scope->parent, name, TRUE);
    }

    return result;
}

static cx_icStorage cx_icProgram_lookupStorage(cx_icProgram program, cx_string name, cx_bool recursive) {
    cx_iter storageIter;
    cx_icStorage result = NULL;

    if (!(result = cx_icScope_lookupStorage(program->scope, name, recursive))) {
        storageIter = cx_llIter(program->storages);
        while(cx_iterHasNext(&storageIter)) {
            result = cx_iterNext(&storageIter);
            if (!strcmp(result->name, name)) {
                break;
            } else {
                result = NULL;
            }
        }
    }

    return result;
}

cx_icProgram cx_icProgram__create(cx_string filename) {
    cx_icProgram result;
    result = cx_calloc(sizeof(cx_icProgram_s));
    result->filename = filename ? cx_strdup(filename) : NULL;
    result->storages = cx_llNew();
    result->labels = cx_llNew();
    result->scopes = cx_llNew();
    result->functions = cx_llNew();
    result->literals = cx_llNew();
    result->ops = cx_llNew();
    result->errors = 0;
    return result;
}

void cx_icStorage_init(
        cx_icStorage storage,
        cx_icProgram program,
        cx_uint32 line,
        cx_icStorageKind kind,
        cx_string name,
        cx_type type) {

    storage->_parent._parent.kind = CX_IC_STORAGE;
    storage->_parent._parent.line = line;
    storage->_parent._parent.program = program;
    storage->kind = kind;
    storage->used = 0;
    storage->name = name ? cx_strdup(name) : NULL;
    storage->type = type;
    storage->isReference = type->reference;
    storage->holdsReturn = FALSE;
}

cx_icAddress cx_icAddress__create(cx_icProgram program, cx_uint32 line, void* address) {
    cx_icAddress result = cx_malloc(sizeof(cx_icAddress_s));
    ((cx_ic)result)->line = line;
    ((cx_ic)result)->kind = CX_IC_ADDRESS;
    result->address = address;
    cx_llAppend(program->labels, result);
    return result;
}

cx_icObject cx_icObject__create(cx_icProgram program, cx_uint32 line, cx_object ptr) {
    cx_icObject result;
    cx_id name;

    cx_fullname(ptr, name);

    if (!(result = (cx_icObject)cx_icProgram_lookupStorage(program, name, TRUE))) {
        cx_type t;
        result = cx_calloc(sizeof(cx_icObject_s));
        if (ptr) {
            t = cx_typeof(ptr);
        } else {
            t = cx_object_o;
        }
        cx_icStorage_init((cx_icStorage)result, program, line, CX_STORAGE_OBJECT, name, t);
        result->ptr = ptr;
        cx_llAppend(program->storages, result);
    }

    return result;
}

cx_icLocal cx_icLocal__create(
    cx_icProgram program, cx_uint32 line, cx_string name, cx_type type, cx_bool isParameter, cx_bool isReturn, cx_bool declare) {
    cx_icLocal result;

    if (!(result = (cx_icLocal)cx_icProgram_lookupStorage(program, name, !declare))) {
        result = cx_calloc(sizeof(cx_icLocal_s));
        cx_icStorage_init((cx_icStorage)result, program, line, CX_STORAGE_LOCAL, name, type);
        result->isParameter = isParameter;
        result->isReturn = isReturn;
        cx_llAppend(program->scope->storages, result);
    }

    return result;
}

cx_icAccumulator cx_icAccumulator__create(cx_icProgram program, cx_uint32 line, cx_type type, cx_uint32 accumulatorId) {
    cx_icAccumulator result;
    cx_id name;

    sprintf(name, "%u", accumulatorId);

    result = cx_calloc(sizeof(cx_icAccumulator_s));
    cx_icStorage_init((cx_icStorage)result, program, line, CX_STORAGE_ACCUMULATOR, name, type);
    cx_llAppend(program->scope->storages, result);

    return result;
}

cx_icMember cx_icMember__create(cx_icProgram program, cx_uint32 line, cx_icStorage base, cx_member member) {
    cx_icMember result;
    cx_id name;
    cx_type t;

    sprintf(name, "%s.%s", base->name, cx_nameof(member));
    t = member->type;

    if (!(result = (cx_icMember)cx_icProgram_lookupStorage(program, name, TRUE))) {
        result = cx_calloc(sizeof(cx_icMember_s));
        cx_icStorage_init((cx_icStorage)result, program, line, CX_STORAGE_MEMBER, name, t);
        result->base = base;
        result->member = member;
        cx_llAppend(program->scope->storages, result);
    }

    return result;
}

cx_icElement cx_icElement__create(cx_icProgram program, cx_uint32 line, cx_type type, cx_icStorage base, cx_icValue index) {
    cx_icElement result;
    cx_id name;
    cx_string elemStr;

    if (index) {
        elemStr = cx_icValue_toString(index, NULL);
        sprintf(name, "%s[%s]", base->name, elemStr);
        cx_dealloc(elemStr);
    } else {
        sprintf(name, "*%s", base->name);
    }

    if (!(result = (cx_icElement)cx_icProgram_lookupStorage(program, name, TRUE))) {
        result = cx_calloc(sizeof(cx_icElement_s));
        cx_icStorage_init((cx_icStorage)result, program, line, CX_STORAGE_ELEMENT, name, type);
        result->base = base;
        result->index = index;
        result->collectionType = (cx_collection)base->type;
        result->dynamic = !index || !(index->_parent.kind == CX_IC_LITERAL);
        cx_llAppend(program->scope->storages, result);
    }

    return result;
}

cx_icLiteral cx_icLiteral__create(cx_icProgram program, cx_uint32 line, cx_value value, cx_type type) {
    cx_icLiteral result;
    if (!line) abort();
    result = cx_calloc(sizeof(cx_icLiteral_s));
    result->_parent._parent.kind = CX_IC_LITERAL;
    result->_parent._parent.program = program;
    result->_parent._parent.line = line;
    result->value = value;
    result->type = type;
    cx_llAppend(program->literals, result);
    return result;
}

cx_icLabel cx_icLabel__create(cx_icProgram program, cx_uint32 line) {
    cx_icLabel result;
    if (!line) abort();
    result = cx_calloc(sizeof(cx_icLabel_s));
    result->_parent._parent.kind = CX_IC_LABEL;
    result->_parent._parent.line = line;
    result->_parent._parent.program = program;
    result->id = cx_llSize(program->labels);
    cx_llAppend(program->labels, result);
    return result;
}

cx_icFunction cx_icFunction__create(cx_icProgram program, cx_uint32 line, cx_function function) {
    cx_icFunction result;
    if (!line) abort();
    result = cx_calloc(sizeof(cx_icLabel_s));
    result->_parent._parent.kind = CX_IC_FUNCTION;
    result->_parent._parent.line = line;
    result->_parent._parent.program = program;
    result->function = function;
    cx_llAppend(program->functions, result);
    return result;
}

cx_icDerefMode cx_icOp_derefMode(cx_icValue value) {
    cx_icDerefMode result = CX_IC_DEREF_VALUE;
    if (value && ((cx_ic)value)->kind == CX_IC_STORAGE) {
        cx_icStorage s = (cx_icStorage)value;
        s->used++;
    }
    return result;
}

cx_icOp cx_icOp__create(cx_icProgram program, cx_uint32 line, cx_icOpKind kind, cx_icValue s1, cx_icValue s2, cx_icValue s3) {
    cx_icOp result;
    if (!line) abort();
    result = cx_calloc(sizeof(cx_icOp_s));
    result->_parent.kind = CX_IC_OP;
    result->_parent.line = line;
    result->_parent.program = program;
    result->kind = kind;
    result->s1 = s1;
    result->s2 = s2;
    result->s3 = s3;

    /* The used-member is indicates whether an accumulator is used in an instruction. This is used
     * when inserting operations to release resources held by an accumulator.
     *
     * Based on the type of a storage the derefMode is set to the most commonly used value for such
     * an storage. An operation may override these initial values. */
    result->s1Deref = cx_icOp_derefMode(s1);
    result->s2Deref = cx_icOp_derefMode(s2);;
    result->s3Deref = cx_icOp_derefMode(s3);;
    result->s1Any = FALSE;

    cx_llAppend(program->ops, result);
    return result;
}

cx_icScope cx_icScope__create(cx_icProgram program, cx_uint32 line, cx_icScope parent, cx_bool isFunction) {
    cx_icScope result;
    result = cx_calloc(sizeof(cx_icScope_s));
    result->_parent.kind = CX_IC_SCOPE;
    result->_parent.line = line;
    result->parent = parent;
    result->program = cx_llNew();
    result->storages = cx_llNew();
    result->isFunction = isFunction;
    cx_llAppend(program->scopes, result);
    return result;
}

void cx_icStorage__free(cx_icStorage _this) {
    cx_dealloc(_this->name);
    cx_dealloc(_this);
}

void cx_icLabel__free(cx_icLabel _this) {
    cx_dealloc(_this);
}

void cx_icFunction__free(cx_icFunction _this) {
    cx_dealloc(_this);
}

void cx_icLiteral__free(cx_icLiteral _this) {
    cx_dealloc(_this);
}

void cx_icOp__free(cx_icOp _this) {
    cx_dealloc(_this);
}

void cx_icScope__free(cx_icScope _this) {
    cx_iter iter;

    iter = cx_llIter(_this->storages);
    while(cx_iterHasNext(&iter)) {
        cx_icStorage__free(cx_iterNext(&iter));
    }

    cx_llFree(_this->storages);
    cx_llFree(_this->program);
    cx_dealloc(_this);
}

void cx_icProgram__free(cx_icProgram _this) {
    cx_iter iter;

    iter = cx_llIter(_this->storages);
    while(cx_iterHasNext(&iter)) {
        cx_icStorage__free(cx_iterNext(&iter));
    }

    iter = cx_llIter(_this->labels);
    while(cx_iterHasNext(&iter)) {
        cx_icLabel__free(cx_iterNext(&iter));
    }

    iter = cx_llIter(_this->scopes);
    while(cx_iterHasNext(&iter)) {
        cx_icScope__free(cx_iterNext(&iter));
    }

    iter = cx_llIter(_this->functions);
    while(cx_iterHasNext(&iter)) {
        cx_icFunction__free(cx_iterNext(&iter));
    }

    iter = cx_llIter(_this->literals);
    while(cx_iterHasNext(&iter)) {
        cx_icLiteral__free(cx_iterNext(&iter));
    }

    iter = cx_llIter(_this->ops);
    while(cx_iterHasNext(&iter)) {
        cx_icOp__free(cx_iterNext(&iter));
    }


    cx_llFree(_this->ops);
    cx_llFree(_this->storages);
    cx_llFree(_this->labels);
    cx_llFree(_this->functions);
    cx_llFree(_this->literals);
    cx_llFree(_this->scopes);
    cx_dealloc(_this->filename);
    cx_dealloc(_this);
}

cx_icAccumulator cx_icProgram_accumulatorPush(cx_icProgram _this, cx_uint32 line, cx_type type, cx_bool isReference) {
    _this->accumulatorStack[_this->accumulatorId] = 
        cx_icAccumulator__create(_this, line, type ? type : cx_void_o, _this->accumulatorId);
    ((cx_icStorage)_this->accumulatorStack[_this->accumulatorId])->isReference = isReference;
    _this->accumulatorId++;
    return _this->accumulatorStack[_this->accumulatorId-1];
}

static void cx_icStorageFree(cx_icProgram _this, cx_icStorage storage, cx_uint32 line) {
    cx_type type = storage->type;
    if (storage->isReference || ((type->kind == CX_PRIMITIVE) && (cx_primitive(type)->kind == CX_TEXT))) {
        cx_ic freeIc;
        
        /* Insert free-instruction */
        freeIc = (cx_ic)cx_icOp__create(_this, line, CX_IC_FREE, (cx_icValue)storage, NULL, NULL);
        if (storage->isReference) {
            ((cx_icOp)freeIc)->s1Deref = CX_IC_DEREF_ADDRESS;
        }
        cx_icProgram_addIc(_this, freeIc);
    }
}

void cx_icProgram_accumulatorPop(cx_icProgram _this, cx_uint32 line) {
    CX_UNUSED(line);
    cx_icStorage acc;
    
    _this->accumulatorId--;
    acc = (cx_icStorage)_this->accumulatorStack[_this->accumulatorId];
    
    if (((cx_icStorage)acc)->holdsReturn) {
        cx_icStorageFree(_this, acc, line);
    }
}

cx_icScope cx_icProgram_scopePush(cx_icProgram _this, cx_uint32 line) {
    _this->scope = cx_icScope__create(_this, line, _this->scope, FALSE);
    if (_this->scope->parent) {
        cx_llAppend(_this->scope->parent->program, _this->scope);
    }
    return _this->scope;
}

cx_icScope cx_icProgram_functionPush(cx_icProgram _this, cx_uint32 line, cx_function function) {
    cx_icFunction label;
    cx_icScope scope;

    /* Add function-label */
    label = cx_icFunction__create(_this, line, function);
    cx_icProgram_addIc(_this, (cx_ic)label);

    /* Push function-scope */
    scope = cx_icProgram_scopePush(_this, line);
    scope->isFunction = TRUE;
    return scope;
}

void cx_icProgram_scopePop(cx_icProgram _this, cx_uint32 line) {
    /* If there are locals with reference types, insert free's for them */
    if (_this->scope->storages) {
        cx_iter storageIter;
        cx_icStorage storage;

        storageIter = cx_llIter(_this->scope->storages);
        while(cx_iterHasNext(&storageIter)) {
            storage = cx_iterNext(&storageIter);
            if ((storage->kind == CX_STORAGE_LOCAL) && !((cx_icLocal)storage)->isReturn && !((cx_icLocal)storage)->isParameter) {
                cx_icStorageFree(_this, storage, line);
            }
        }
    }

    if (_this->scope->parent) {
        _this->scope = _this->scope->parent;
    }
}

void cx_icProgram_addIc(cx_icProgram program, cx_ic ic) {
    if (ic->kind == CX_IC_OP) {
        if (!cx_icValidate((cx_icOp)ic)) {
            program->errors++;
        }
    }
    cx_llAppend(program->scope->program, ic);
}

void cx_icScope_addIc(cx_icScope scope, cx_ic ic) {
    cx_llAppend(scope->program, ic);
}

cx_icOpKind cx_icOpKindFromOperator(cx_operatorKind operator) {

    switch(operator) {
    case CX_ASSIGN: return CX_IC_SET;
    case CX_ADD: return CX_IC_ADD;
    case CX_SUB: return CX_IC_SUB;
    case CX_MUL: return CX_IC_MUL;
    case CX_DIV: return CX_IC_DIV;
    case CX_MOD: return CX_IC_MOD;
    case CX_INC: return CX_IC_INC;
    case CX_DEC: return CX_IC_DEC;
    case CX_XOR: return CX_IC_XOR;
    case CX_OR: return CX_IC_OR;
    case CX_AND: return CX_IC_AND;
    case CX_NOT: return CX_IC_NOT;
    case CX_SHIFT_LEFT: return CX_IC_SHIFT_LEFT;
    case CX_SHIFT_RIGHT: return CX_IC_SHIFT_RIGHT;
    case CX_COND_OR: return CX_IC_COND_OR;
    case CX_COND_AND: return CX_IC_COND_AND;
    case CX_COND_NOT: return CX_IC_COND_NOT;
    case CX_COND_EQ: return CX_IC_COND_EQ;
    case CX_COND_NEQ: return CX_IC_COND_NEQ;
    case CX_COND_GT: return CX_IC_COND_GT;
    case CX_COND_LT: return CX_IC_COND_LT;
    case CX_COND_GTEQ: return CX_IC_COND_GTEQ;
    case CX_COND_LTEQ: return CX_IC_COND_LTEQ;
    default:
        cx_assert(0, "invalid operatorkind (%d)", operator);
        break;
    }
    return CX_IC_SET;
}













