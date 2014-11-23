/*
 * db_ic.c
 *
 *  Created on: Aug 14, 2013
 *      Author: sander
 */

#include "db_mem.h"
#include "db_ic.h"
#include "db_ll.h"
#include "db_object.h"
#include "db_string.h"
#include "db__meta.h"
#include "db_util.h"

static db_string db_icLiteral_toString(db_icLiteral _this, db_string string) {
    switch(_this->value.is.literal.kind) {
    case DB_LITERAL_BOOLEAN:
        string = strappend(string, "%s", _this->value.is.literal.v._boolean ? "true" : "false");
        break;
    case DB_LITERAL_CHARACTER:
        string = strappend(string, "%c", _this->value.is.literal.v._character);
        break;
    case DB_LITERAL_INTEGER:
        string = strappend(string, "%lld", _this->value.is.literal.v._integer);
        break;
    case DB_LITERAL_UNSIGNED_INTEGER:
        string = strappend(string, "%llu", _this->value.is.literal.v._unsigned_integer);
        break;
    case DB_LITERAL_FLOATING_POINT:
        string = strappend(string, "%f", _this->value.is.literal.v._floating_point);
        break;
    case DB_LITERAL_STRING:
        string = strappend(string, "\"%s\"", _this->value.is.literal.v._string);
        break;
    case DB_LITERAL_NULL:
        string = strappend(string, "null");
        break;
    }
    return string;
}

static db_string db_icValue_toString(db_icValue operand, db_string string) {
    switch(operand->_parent.kind) {
    case DB_IC_STORAGE:
        if (((db_icStorage)operand)->kind == DB_STORAGE_ACCUMULATOR) {
            string = strappend(string, "%%%s", ((db_icStorage)operand)->name);
        } else {
            string = strappend(string, "%s", ((db_icStorage)operand)->name);
        }
        break;
    case DB_IC_LITERAL:
        string = db_icLiteral_toString(((db_icLiteral)operand), string);
        break;
    case DB_IC_LABEL:
        string = strappend(string, "%d", ((db_icLabel)operand)->id);
        break;
    case DB_IC_FUNCTION: {
        db_id id;
        string = strappend(string, "%s", db_fullname(((db_icFunction)operand)->function, id));
        break;
    }
    default:
        string = strappend(string, "invalid operand");
        break;
    }
    return string;
}

#ifdef DB_IC_TRACING
static db_string db_opKind_toString(db_icOpKind kind) {
    switch(kind) {
    /* Set (assign) */
    case DB_IC_SET: return "set";

    /* Cast */
    case DB_IC_CAST: return "cast";

    /* String concatenation */
    case DB_IC_STRCAT: return "strcat";
    case DB_IC_STRCPY: return "strcpy";

    /* Memory management */
    case DB_IC_NEW: return "new";
    case DB_IC_DEFINE: return "define";
    case DB_IC_FREE: return "free";
    case DB_IC_KEEP: return "keep";

    /* Notifications */
    case DB_IC_UPDATE: return "update";
    case DB_IC_UPDATEBEGIN: return "updatebegin";
    case DB_IC_UPDATEEND: return "updateend";
    case DB_IC_UPDATECANCEL: return "updatecancel";

    /* Waiting */
    case DB_IC_WAITFOR: return "waitfor";
    case DB_IC_WAIT: return "wait";

    /* Operators */
    case DB_IC_ADD: return "add";
    case DB_IC_SUB: return "sub";
    case DB_IC_MUL: return "mul";
    case DB_IC_DIV: return "div";
    case DB_IC_MOD: return "mod";
    case DB_IC_INC: return "inc";
    case DB_IC_DEC: return "dec";
    case DB_IC_XOR: return "xor";
    case DB_IC_OR: return "or";
    case DB_IC_AND: return "and";
    case DB_IC_NOT: return "not";
    case DB_IC_SHIFT_LEFT: return "shiftleft";
    case DB_IC_SHIFT_RIGHT: return "shiftright";
    case DB_IC_STAGE1: return "stage1";
    case DB_IC_STAGE2: return "stage2";
    case DB_IC_COND_OR: return "cor";
    case DB_IC_COND_AND: return "cand";
    case DB_IC_COND_NOT: return "cnot";
    case DB_IC_COND_EQ: return "ceq";
    case DB_IC_COND_NEQ: return "cneq";
    case DB_IC_COND_GT: return "cgt";
    case DB_IC_COND_LT: return "clt";
    case DB_IC_COND_GTEQ: return "cgteq";
    case DB_IC_COND_LTEQ: return "clteq";

    /* Program control */
    case DB_IC_JUMP: return "jump";
    case DB_IC_JEQ: return "jeq";
    case DB_IC_JNEQ: return "jneq";
    case DB_IC_STOP: return "stop";

    /* Function calls */
    case DB_IC_PUSH: return "push";
    case DB_IC_CALL: return "call";
    case DB_IC_RET: return "ret";
    default:
        break;
    }
    return "???";
}

static db_string db_icOp_derefToString(db_string string, db_icDerefMode mode) {
    if (mode == DB_IC_DEREF_VALUE) {
        string = strappend(string, " ");
    } else if (mode == DB_IC_DEREF_ADDRESS) {
        string = strappend(string, " &");
    } else {
        string = strappend(string, " ");
    }
    return string;
}

static db_string db_icOp_toString(db_icOp _this, db_string string)  {
    string = strappend(string, "\t%s", db_opKind_toString(_this->kind));
    if (_this->s1) {
        string = db_icOp_derefToString(string, _this->s1Deref);
        string = db_icValue_toString(_this->s1, string);
    } else if (_this->s2 || _this->s3) {
        string = strappend(string, " .");
    }
    if (_this->s2) {
        string = db_icOp_derefToString(string, _this->s2Deref);
        string = db_icValue_toString(_this->s2, string);
    } else if (_this->s3) {
        string = strappend(string, " .");
    }
    if (_this->s3) {
        string = db_icOp_derefToString(string, _this->s3Deref);
        string = db_icValue_toString(_this->s3, string);
    }
    return string;
}

static db_string db_icStorage_toString(db_icStorage _this, db_string string) {
    db_id id;

    switch(_this->kind) {
    case DB_STORAGE_ACCUMULATOR:
        string = strappend(string, "%%acc %s %s", _this->name, db_fullname(_this->type, id));
        break;
    case DB_STORAGE_MEMBER:
        string = strappend(string, "%%mbr %s %s", _this->name, db_fullname(_this->type, id));
        break;
    case DB_STORAGE_ELEMENT:
        string = strappend(string, "%%elem %s %s", _this->name, db_fullname(_this->type, id));
        break;
    case DB_STORAGE_LOCAL:
        string = strappend(string, "%%local %s %s", _this->name, db_fullname(_this->type, id));
        break;
    case DB_STORAGE_OBJECT:
        string = strappend(string, "%%object %s %s", _this->name, db_fullname(_this->type, id));
        break;
    }

    return string;
}

static db_string db_icLabel_toString(db_icLabel _this, db_string string) {
    string = strappend(string, "%%label %d", _this->id);
    return string;
}

static db_string db_icFunction_toString(db_icFunction _this, db_string string) {
    db_id id;
    string = strappend(string, "\n%%function %s", db_fullname(_this->function, id));
    return string;
}

static db_string db_icScope_toString(db_icScope _this, db_string result) {
    db_iter programIter, storageIter;
    db_icStorage storage;
    db_uint32 storages = 0;
    db_ic ic;

    /* Count storages */
    storageIter = db_llIter(_this->storages);
    while(db_iterHasNext(&storageIter)) {
        storage = db_iterNext(&storageIter);
        if (storage->kind == DB_STORAGE_LOCAL) {
            storages ++;
        }
    }

    /* No need to push a scope when there are no local storages */
    if (storages) {
        result = strappend(result, "%%scopepush\n");
    }

    /* Print storages */
    storageIter = db_llIter(_this->storages);
    while(db_iterHasNext(&storageIter)) {
        storage = db_iterNext(&storageIter);
        if (storage->kind == DB_STORAGE_LOCAL) {
            db_id id;
            result = strappend(result, "%%local %s %s\n", storage->name, db_fullname(storage->type, id));
        }
    }

    /* List local storages */

    programIter = db_llIter(_this->program);
    while(db_iterHasNext(&programIter)) {
        ic = db_iterNext(&programIter);
        switch(ic->kind) {
        case DB_IC_STORAGE:
            result = db_icStorage_toString((db_icStorage)ic, result);
            result = strappend(result, "\n");
            break;
        case DB_IC_LABEL:
            result = db_icLabel_toString((db_icLabel)ic, result);
            result = strappend(result, "\n");
            break;
        case DB_IC_FUNCTION:
            result = db_icFunction_toString((db_icFunction)ic, result);
            result = strappend(result, "\n");
            break;
        case DB_IC_OP:
            result = db_icOp_toString((db_icOp)ic, result);
            result = strappend(result, "\n");
            break;
        case DB_IC_SCOPE:
            result = db_icScope_toString((db_icScope)ic, result);
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

static db_bool db_ic_validateSet(db_icOp op) {
    db_bool result = TRUE;
    op->s1 && (((db_ic)op->s1)->kind != DB_IC_STORAGE) ? result = FALSE: 0;
    !op->s2 || (((db_ic)op->s2)->kind != DB_IC_STORAGE) ? result = FALSE: 0;
    !op->s2 ? result = FALSE : 0;
    return result;
}

static db_bool db_ic_validateCast(db_icOp op) {
    db_bool result = TRUE;
    op->s1 && (((db_ic)op->s1)->kind != DB_IC_STORAGE) ? result = FALSE: 0;
    !op->s2 || (((db_ic)op->s2)->kind != DB_IC_STORAGE) ? result = FALSE: 0;
    !op->s3 || (((db_ic)op->s3)->kind != DB_IC_STORAGE) ? result = FALSE: 0;
    return result;
}

static db_bool db_ic_validateBinary(db_icOp op) {
    db_bool result = TRUE;
    op->s1 && (((db_ic)op->s1)->kind != DB_IC_STORAGE) ? result = FALSE: 0;
    !op->s2 || !op->s3 ? result = FALSE: 0;
    if (result) {
        if ((((db_ic)op->s2)->kind != DB_IC_STORAGE) && (((db_ic)op->s3)->kind != DB_IC_STORAGE)) {
            result = FALSE;
        }
    }
    return result;
}

static db_bool db_ic_validateUnary(db_icOp op) {
    db_bool result = TRUE;
    op->s1 && (((db_ic)op->s1)->kind != DB_IC_STORAGE) ? result = FALSE: 0;
    op->s2 && (((db_ic)op->s2)->kind != DB_IC_STORAGE) ? result = FALSE: 0;
    return result;
}

static db_bool db_ic_validatePush(db_icOp op) {
    if (!op->s1) {
        return FALSE;
    } else {
        return TRUE;
    }
}

db_string db_icKind_toString(db_icKind kind) {
    switch(kind) {
        case DB_IC_STORAGE: return "storage";
        case DB_IC_LITERAL: return "literal";
        case DB_IC_LABEL: return "label";
        case DB_IC_FUNCTION: return "function";
        case DB_IC_OP: return "op";
        case DB_IC_SCOPE: return "scope";
    }
    return "???";
}

static db_bool db_icValidate(db_icOp op) {
    db_bool result = TRUE;

    switch(op->kind) {
            /* Set (assign) */
        case DB_IC_SET: result = db_ic_validateSet(op); break;
            
            /* Cast */
        case DB_IC_CAST: result = db_ic_validateCast(op); break;
            
            /* String concatenation */
        case DB_IC_STRCAT: result = TRUE; break;
        case DB_IC_STRCPY: result = TRUE; break;
            
            /* Memory management */
        case DB_IC_NEW: result = TRUE; break;
        case DB_IC_DEFINE: result = TRUE; break;
        case DB_IC_FREE: result = TRUE; break;
        case DB_IC_KEEP: result = TRUE; break;
            
            /* Notifications */
        case DB_IC_UPDATE: result = TRUE; break;
        case DB_IC_UPDATEBEGIN: result = TRUE; break;
        case DB_IC_UPDATEEND: result = TRUE; break;
        case DB_IC_UPDATECANCEL: result = TRUE; break;
            
            /* Waiting */
        case DB_IC_WAITFOR: result = TRUE; break;
        case DB_IC_WAIT: result = TRUE; break;
            
            /* Operators */
        case DB_IC_ADD: result = db_ic_validateBinary(op); break;
        case DB_IC_SUB: result = db_ic_validateBinary(op); break;
        case DB_IC_MUL: result = db_ic_validateBinary(op); break;
        case DB_IC_DIV: result = db_ic_validateBinary(op); break;
        case DB_IC_MOD: result = db_ic_validateBinary(op); break;
        case DB_IC_INC: result = db_ic_validateUnary(op); break;
        case DB_IC_DEC: result = db_ic_validateUnary(op); break;
        case DB_IC_XOR: result = db_ic_validateBinary(op); break;
        case DB_IC_OR: result = db_ic_validateBinary(op); break;
        case DB_IC_AND: result = db_ic_validateBinary(op); break;
        case DB_IC_NOT: result = db_ic_validateUnary(op); break;
        case DB_IC_SHIFT_LEFT: result = db_ic_validateBinary(op); break;
        case DB_IC_SHIFT_RIGHT: result = db_ic_validateBinary(op); break;
        case DB_IC_STAGE1: result = TRUE; break;
        case DB_IC_STAGE2: result = TRUE; break;
        case DB_IC_COND_OR: result = db_ic_validateBinary(op); break;
        case DB_IC_COND_AND: result = db_ic_validateBinary(op); break;
        case DB_IC_COND_NOT: result = db_ic_validateUnary
            (op); break;
        case DB_IC_COND_EQ: result = db_ic_validateBinary(op); break;
        case DB_IC_COND_NEQ: result = db_ic_validateBinary(op); break;
        case DB_IC_COND_GT: result = db_ic_validateBinary(op); break;
        case DB_IC_COND_LT: result = db_ic_validateBinary(op); break;
        case DB_IC_COND_GTEQ: result = db_ic_validateBinary(op); break;
        case DB_IC_COND_LTEQ: result = db_ic_validateBinary(op); break;
            
            /* Program control */
        case DB_IC_JUMP: result = TRUE; break;
        case DB_IC_JEQ: result = TRUE; break;
        case DB_IC_JNEQ: result = TRUE; break;
        case DB_IC_STOP: result = TRUE; break;
            
            /* Function calls */
        case DB_IC_PUSH: result = db_ic_validatePush(op); break;
        case DB_IC_CALL: result = TRUE; break;
        case DB_IC_RET: result = TRUE; break;
        default: printf("unknown operation!\n"); result = FALSE; break;
    }

#ifdef DB_IC_TRACING
    if (!result) {
        printf("%s:%d: invalid operands for '%s' (%s, %s, %s)\n",
               ((db_ic)op)->program->filename,
               ((db_ic)op)->line, db_opKind_toString(op->kind),
               op->s1 ? db_icKind_toString(((db_ic)op->s1)->kind) : "<none>",
               op->s2 ? db_icKind_toString(((db_ic)op->s2)->kind) : "<none>",
               op->s3 ? db_icKind_toString(((db_ic)op->s3)->kind) : "<none>");
    }
#else
    if (!result) {
    printf("%s:%d: invalid operands (build with DB_IC_TRACING to get more information)\n",
           ((db_ic)op)->program->filename,
           ((db_ic)op)->line);
    }
#endif    
    return result;
}

db_string db_icProgram_toString(db_icProgram program) {
    db_string result = NULL;
    DB_UNUSED(program);

#ifdef DB_IC_TRACING
    db_iter storageIter;
    db_icStorage storage;

    result = strappend(result, "%%file %s\n", program->filename);

    /* Print storages */
    storageIter = db_llIter(program->storages);
    while(db_iterHasNext(&storageIter)) {
        storage = db_iterNext(&storageIter);
        if (storage->kind == DB_STORAGE_OBJECT) {
            db_object o;
            o = ((db_icObject)storage)->ptr;
            if (o) {
                db_string objectValue = db_toString(o, 0);
                result = strappend(result, "%%object %s %s\n", storage->name, objectValue);
                db_dealloc(objectValue);
            }
        }
    }

    result = db_icScope_toString(program->scope, result);
#endif
    return result;
}

db_icStorage db_icScope_lookupStorage(db_icScope scope, db_string name, db_bool recursive) {
	db_iter storageIter;
	db_icStorage result = NULL;

	storageIter = db_llIter(scope->storages);
	while(db_iterHasNext(&storageIter)) {
		result = db_iterNext(&storageIter);
		if (!strcmp(result->name, name)) {
			break;
		} else {
			result = NULL;
		}
	}

	if (!result && scope->parent && recursive && !scope->isFunction) {
		result = db_icScope_lookupStorage(scope->parent, name, TRUE);
	}

	return result;
}

static db_icStorage db_icProgram_lookupStorage(db_icProgram program, db_string name, db_bool recursive) {
	db_iter storageIter;
	db_icStorage result = NULL;

	if (!(result = db_icScope_lookupStorage(program->scope, name, recursive))) {
		storageIter = db_llIter(program->storages);
		while(db_iterHasNext(&storageIter)) {
			result = db_iterNext(&storageIter);
			if (!strcmp(result->name, name)) {
		        break;
			} else {
				result = NULL;
			}
		}
	}

	return result;
}

db_icProgram db_icProgram__create(db_string filename) {
	db_icProgram result;
	result = db_calloc(sizeof(db_icProgram_s));
	result->filename = db_strdup(filename);
	result->storages = db_llNew();
	result->labels = db_llNew();
	result->scopes = db_llNew();
	result->functions = db_llNew();
	result->literals = db_llNew();
	result->ops = db_llNew();
    result->errors = 0;
	return result;
}

void db_icStorage_init(
		db_icStorage storage,
		db_icProgram program,
		db_uint32 line,
		db_icStorageKind kind,
		db_string name,
		db_type type) {

    storage->_parent._parent.kind = DB_IC_STORAGE;
    storage->_parent._parent.line = line;
    storage->_parent._parent.program = program;
    storage->kind = kind;
    storage->used = 0;
    storage->name = name ? db_strdup(name) : NULL;
    storage->type = type;
    storage->isReference = type->reference;
    storage->holdsReturn = FALSE;
}

db_icObject db_icObject__create(db_icProgram program, db_uint32 line, db_object ptr) {
    db_icObject result;
    db_id name;

    db_fullname(ptr, name);

    if (!(result = (db_icObject)db_icProgram_lookupStorage(program, name, TRUE))) {
        db_type t;
        result = db_calloc(sizeof(db_icObject_s));
        if (ptr) {
            t = db_typeof(ptr)->real;
        } else {
            t = db_object_o;
        }
        db_icStorage_init((db_icStorage)result, program, line, DB_STORAGE_OBJECT, name, t);
        result->ptr = ptr;
        db_llAppend(program->storages, result);
    }

    return result;
}

db_icLocal db_icLocal__create(db_icProgram program, db_uint32 line, db_string name, db_type type, db_bool isParameter, db_bool isReturn, db_bool declare) {
    db_icLocal result;

    if (!(result = (db_icLocal)db_icProgram_lookupStorage(program, name, !declare))) {
        result = db_calloc(sizeof(db_icLocal_s));
        db_icStorage_init((db_icStorage)result, program, line, DB_STORAGE_LOCAL, name, type);
        result->isParameter = isParameter;
        result->isReturn = isReturn;
        db_llAppend(program->scope->storages, result);
    }

    return result;
}

db_icAccumulator db_icAccumulator__create(db_icProgram program, db_uint32 line, db_type type, db_uint32 accumulatorId) {
    db_icAccumulator result;
    db_id name;

    sprintf(name, "%u", accumulatorId);

    result = db_calloc(sizeof(db_icAccumulator_s));
    db_icStorage_init((db_icStorage)result, program, line, DB_STORAGE_ACCUMULATOR, name, type);
    db_llAppend(program->scope->storages, result);

    return result;
}

db_icMember db_icMember__create(db_icProgram program, db_uint32 line, db_icStorage base, db_member member) {
	db_icMember result;
	db_id name;

	sprintf(name, "%s.%s", base->name, db_nameof(member));

	if (!(result = (db_icMember)db_icProgram_lookupStorage(program, name, TRUE))) {
		result = db_calloc(sizeof(db_icMember_s));
		db_icStorage_init((db_icStorage)result, program, line, DB_STORAGE_MEMBER, name, member->type->real);
		result->base = base;
		result->member = member;
		db_llAppend(program->scope->storages, result);
	}

	return result;
}

db_icElement db_icElement__create(db_icProgram program, db_uint32 line, db_type type, db_icStorage base, db_icValue index) {
    db_icElement result;
    db_id name;
    db_string elemStr;

    elemStr = db_icValue_toString(index, NULL);
    sprintf(name, "%s[%s]", base->name, elemStr);
    db_dealloc(elemStr);

    if (!(result = (db_icElement)db_icProgram_lookupStorage(program, name, TRUE))) {
        result = db_calloc(sizeof(db_icElement_s));
        db_icStorage_init((db_icStorage)result, program, line, DB_STORAGE_ELEMENT, name, type);
        result->base = base;
        result->index = index;
        result->collectionType = (db_collection)base->type;
        result->dynamic = !(index->_parent.kind == DB_IC_LITERAL);
        db_llAppend(program->scope->storages, result);
    }

    return result;
}

db_icLiteral db_icLiteral__create(db_icProgram program, db_uint32 line, db_value value, db_type type) {
	db_icLiteral result;
    if (!line) abort();
	result = db_calloc(sizeof(db_icLiteral_s));
	result->_parent._parent.kind = DB_IC_LITERAL;
	result->_parent._parent.program = program;
	result->_parent._parent.line = line;
	result->value = value;
	result->type = type;
	db_llAppend(program->literals, result);
	return result;
}

db_icLabel db_icLabel__create(db_icProgram program, db_uint32 line) {
	db_icLabel result;
    if (!line) abort();
	result = db_calloc(sizeof(db_icLabel_s));
	result->_parent._parent.kind = DB_IC_LABEL;
	result->_parent._parent.line = line;
	result->_parent._parent.program = program;
	result->id = db_llSize(program->labels);
	db_llAppend(program->labels, result);
	return result;
}

db_icFunction db_icFunction__create(db_icProgram program, db_uint32 line, db_function function) {
    db_icFunction result;
    if (!line) abort();
    result = db_calloc(sizeof(db_icLabel_s));
    result->_parent._parent.kind = DB_IC_FUNCTION;
    result->_parent._parent.line = line;
    result->_parent._parent.program = program;
    result->function = function;
    db_llAppend(program->functions, result);
    return result;
}

db_icDerefMode db_icOp_derefMode(db_icValue value) {
	db_icDerefMode result = DB_IC_DEREF_VALUE;
	if (value && ((db_ic)value)->kind == DB_IC_STORAGE) {
		db_icStorage s = (db_icStorage)value;
		s->used++;
	}
	return result;
}

db_icOp db_icOp__create(db_icProgram program, db_uint32 line, db_icOpKind kind, db_icValue s1, db_icValue s2, db_icValue s3) {
	db_icOp result;
    if (!line) abort();
	result = db_calloc(sizeof(db_icOp_s));
	result->_parent.kind = DB_IC_OP;
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
	result->s1Deref = db_icOp_derefMode(s1);
	result->s2Deref = db_icOp_derefMode(s2);;
	result->s3Deref = db_icOp_derefMode(s3);;
	result->s1Any = FALSE;

	db_llAppend(program->ops, result);
	return result;
}

db_icScope db_icScope__create(db_icProgram program, db_uint32 line, db_icScope parent, db_bool isFunction) {
	db_icScope result;
	result = db_calloc(sizeof(db_icScope_s));
	result->_parent.kind = DB_IC_SCOPE;
	result->_parent.line = line;
	result->parent = parent;
	result->program = db_llNew();
	result->storages = db_llNew();
    result->isFunction = isFunction;
	db_llAppend(program->scopes, result);
	return result;
}

void db_icStorage__free(db_icStorage _this) {
	db_dealloc(_this->name);
	db_dealloc(_this);
}

void db_icLabel__free(db_icLabel _this) {
	db_dealloc(_this);
}

void db_icFunction__free(db_icFunction _this) {
    db_dealloc(_this);
}

void db_icLiteral__free(db_icLiteral _this) {
    db_dealloc(_this);
}

void db_icOp__free(db_icOp _this) {
	db_dealloc(_this);
}

void db_icScope__free(db_icScope _this) {
	db_iter iter;

	iter = db_llIter(_this->storages);
	while(db_iterHasNext(&iter)) {
		db_icStorage__free(db_iterNext(&iter));
	}

	db_llFree(_this->storages);
	db_llFree(_this->program);
	db_dealloc(_this);
}

void db_icProgram__free(db_icProgram _this) {
	db_iter iter;

	iter = db_llIter(_this->storages);
	while(db_iterHasNext(&iter)) {
		db_icStorage__free(db_iterNext(&iter));
	}

	iter = db_llIter(_this->labels);
	while(db_iterHasNext(&iter)) {
		db_icLabel__free(db_iterNext(&iter));
	}

	iter = db_llIter(_this->scopes);
	while(db_iterHasNext(&iter)) {
		db_icScope__free(db_iterNext(&iter));
	}

    iter = db_llIter(_this->functions);
    while(db_iterHasNext(&iter)) {
        db_icFunction__free(db_iterNext(&iter));
    }

    iter = db_llIter(_this->literals);
    while(db_iterHasNext(&iter)) {
        db_icLiteral__free(db_iterNext(&iter));
    }

	iter = db_llIter(_this->ops);
	while(db_iterHasNext(&iter)) {
		db_icOp__free(db_iterNext(&iter));
	}


	db_llFree(_this->ops);
	db_llFree(_this->storages);
	db_llFree(_this->labels);
	db_llFree(_this->functions);
	db_llFree(_this->literals);
	db_llFree(_this->scopes);
	db_dealloc(_this->filename);
	db_dealloc(_this);
}

db_icAccumulator db_icProgram_accumulatorPush(db_icProgram _this, db_uint32 line, db_type type, db_bool isReference) {
	_this->accumulatorStack[_this->accumulatorId] = db_icAccumulator__create(_this, line, type ? type : db_void_o, _this->accumulatorId);
    ((db_icStorage)_this->accumulatorStack[_this->accumulatorId])->isReference = isReference;
    _this->accumulatorId++;
	return _this->accumulatorStack[_this->accumulatorId-1];
}

static void db_icStorageFree(db_icProgram _this, db_icStorage storage, db_uint32 line) {
    db_type type = storage->type;
    if (storage->isReference || ((type->kind == DB_PRIMITIVE) && (db_primitive(type)->kind == DB_TEXT))) {
        db_ic freeIc;
        
        /* Insert free-instruction */
        freeIc = (db_ic)db_icOp__create(_this, line, DB_IC_FREE, (db_icValue)storage, NULL, NULL);
        if (storage->isReference) {
            ((db_icOp)freeIc)->s1Deref = DB_IC_DEREF_ADDRESS;
        }
        db_icProgram_addIc(_this, freeIc);
    }
}

void db_icProgram_accumulatorPop(db_icProgram _this, db_uint32 line) {
    DB_UNUSED(line);
    db_icStorage acc;
    
	_this->accumulatorId--;
    acc = (db_icStorage)_this->accumulatorStack[_this->accumulatorId];
    
    if (((db_icStorage)acc)->holdsReturn) {
        db_icStorageFree(_this, acc, line);
    }
}

db_icScope db_icProgram_scopePush(db_icProgram _this, db_uint32 line) {
	_this->scope = db_icScope__create(_this, line, _this->scope, FALSE);
	if (_this->scope->parent) {
		db_llAppend(_this->scope->parent->program, _this->scope);
	}
	return _this->scope;
}

db_icScope db_icProgram_functionPush(db_icProgram _this, db_uint32 line, db_function function) {
    db_icFunction label;
    db_icScope scope;

    /* Add function-label */
    label = db_icFunction__create(_this, line, function);
    db_icProgram_addIc(_this, (db_ic)label);

    /* Push function-scope */
    scope = db_icProgram_scopePush(_this, line);
    scope->isFunction = TRUE;
    return scope;
}

void db_icProgram_scopePop(db_icProgram _this, db_uint32 line) {
    /* If there are locals with reference types, insert free's for them */
    if (_this->scope->storages) {
        db_iter storageIter;
        db_icStorage storage;

        storageIter = db_llIter(_this->scope->storages);
        while(db_iterHasNext(&storageIter)) {
            storage = db_iterNext(&storageIter);
            if ((storage->kind == DB_STORAGE_LOCAL) && !((db_icLocal)storage)->isReturn && !((db_icLocal)storage)->isParameter) {
                db_icStorageFree(_this, storage, line);
            }
        }
    }

	if (_this->scope->parent) {
		_this->scope = _this->scope->parent;
	}
}

void db_icProgram_addIc(db_icProgram program, db_ic ic) {
    if (ic->kind == DB_IC_OP) {
        if (!db_icValidate((db_icOp)ic)) {
            program->errors++;
        }
    }
	db_llAppend(program->scope->program, ic);
}

void db_icScope_addIc(db_icScope scope, db_ic ic) {
    db_llAppend(scope->program, ic);
}

db_icOpKind db_icOpKindFromOperator(db_operatorKind operator) {

	switch(operator) {
	case DB_ASSIGN: return DB_IC_SET;
	case DB_ADD: return DB_IC_ADD;
	case DB_SUB: return DB_IC_SUB;
	case DB_MUL: return DB_IC_MUL;
	case DB_DIV: return DB_IC_DIV;
	case DB_MOD: return DB_IC_MOD;
	case DB_INC: return DB_IC_INC;
	case DB_DEC: return DB_IC_DEC;
	case DB_XOR: return DB_IC_XOR;
	case DB_OR: return DB_IC_OR;
	case DB_AND: return DB_IC_AND;
	case DB_NOT: return DB_IC_NOT;
	case DB_SHIFT_LEFT: return DB_IC_SHIFT_LEFT;
	case DB_SHIFT_RIGHT: return DB_IC_SHIFT_RIGHT;
	case DB_COND_OR: return DB_IC_COND_OR;
	case DB_COND_AND: return DB_IC_COND_AND;
	case DB_COND_NOT: return DB_IC_COND_NOT;
	case DB_COND_EQ: return DB_IC_COND_EQ;
	case DB_COND_NEQ: return DB_IC_COND_NEQ;
	case DB_COND_GT: return DB_IC_COND_GT;
	case DB_COND_LT: return DB_IC_COND_LT;
	case DB_COND_GTEQ: return DB_IC_COND_GTEQ;
	case DB_COND_LTEQ: return DB_IC_COND_LTEQ;
	default:
		db_assert(0, "invalid operatorkind (%d)", operator);
		break;
	}
	return DB_IC_SET;
}













