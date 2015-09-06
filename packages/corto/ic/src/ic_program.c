/* ic_program.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#define corto_ic_LIB
#include "ic.h"

/* $header() */
#include "ic_assemble.h"
/* $end */

/* ::corto::ic::program::add(node n) */
cx_void _ic_program_add(ic_program this, ic_node n) {
/* $begin(::corto::ic::program::add) */

    if (n->kind == IC_OP) {
        if (!ic_op_validate(ic_op(n))) {
            this->errors++;
        }
    }

    if (cx_instanceof(cx_type(ic_storage_o), n)) {
        ic_nodeListAppend(this->scope->storages, n);
    } else {
        ic_nodeListAppend(this->scope->program, n);
    }

/* $end */
}

/* ::corto::ic::program::assemble() */
cx_int16 _ic_program_assemble(ic_program this) {
/* $begin(::corto::ic::program::assemble) */

    if (CX_DEBUG_ENABLED) {
        cx_string str = ic_program_str(this);
        if (str) {
            printf("%s\n", str);
            cx_dealloc(str);
        }
    }

    this->vmprogram = (cx_word)ic_vmAssemble(this);
    if (!this->vmprogram) {
        goto error;
    }

    return 0;
error:
    return -1;
/* $end */
}

/* ::corto::ic::program::construct() */
cx_int16 _ic_program_construct(ic_program this) {
/* $begin(::corto::ic::program::construct) */
    extern cx_threadKey IC_PROGRAM_KEY;
    cx_threadTlsSet(IC_PROGRAM_KEY, this);
    return 0;
/* $end */
}

/* ::corto::ic::program::declareVariable(string name,type type,bool isReference,bool holdsReturn,bool isParameter,bool isReturn) */
ic_variable _ic_program_declareVariable(ic_program this, cx_string name, cx_type type, cx_bool isReference, cx_bool holdsReturn, cx_bool isParameter, cx_bool isReturn) {
/* $begin(::corto::ic::program::declareVariable) */
    ic_variable result = ic_variable(ic_scope_lookupStorage(this->scope, name, FALSE));
    if (!result) {
        result = ic_variableCreate(name, type, isReference, holdsReturn, isParameter, isReturn);
        ic_scope_addStorage(this->scope, ic_storage(result));
    }
    return result;
/* $end */
}

/* ::corto::ic::program::get() */
ic_program _ic_program_get(void) {
/* $begin(::corto::ic::program::get) */
    extern cx_threadKey IC_PROGRAM_KEY;
    return (ic_program)cx_threadTlsGet(IC_PROGRAM_KEY);
/* $end */
}

/* ::corto::ic::program::getAccId() */
cx_uint32 _ic_program_getAccId(ic_program this) {
/* $begin(::corto::ic::program::getAccId) */
    return ++this->autoAccId;
/* $end */
}

/* ::corto::ic::program::getElement(storage base,node index) */
ic_element _ic_program_getElement(ic_program this, ic_storage base, ic_node index) {
/* $begin(::corto::ic::program::getElement) */
    cx_id name;
    ic_element result;
    if (index) {
        cx_string elemStr = ic_node_str(index, NULL);
        sprintf(name, "%s[%s]", base->name, elemStr);
        cx_dealloc(elemStr);
    } else {
        sprintf(name, "*%s", base->name);
    }
    result = ic_element(ic_scope_lookupStorage(base->scope, name, FALSE));
    if (!result) {
        result = ic_elementCreate(base, index);
        ic_scope_addStorage(this->scope, ic_storage(result));
    }
    return result;
/* $end */
}

/* ::corto::ic::program::getLabel() */
cx_uint32 _ic_program_getLabel(ic_program this) {
/* $begin(::corto::ic::program::getLabel) */
    return ++this->labelCount;
/* $end */
}

/* ::corto::ic::program::getMember(storage base,member m) */
ic_member _ic_program_getMember(ic_program this, ic_storage base, cx_member m) {
/* $begin(::corto::ic::program::getMember) */
    cx_id name;
    ic_member result;
    sprintf(name, "%s.%s", base->name, cx_nameof(m));
    result = ic_member(ic_scope_lookupStorage(base->scope, name, FALSE));
    if (!result) {
        result = ic_memberCreate(base, m);
        ic_scope_addStorage(this->scope, ic_storage(result));
    }
    return result;
/* $end */
}

/* ::corto::ic::program::getObject(object o) */
ic_object _ic_program_getObject(ic_program this, cx_object o) {
/* $begin(::corto::ic::program::getObject) */
    cx_id id;
    ic_scope root = this->scope;
    ic_object result = NULL;
    while(root->parent) {
        root = root->parent;
    }
    result = ic_object(ic_scope_lookupStorage(root, cx_fullname(o, id), FALSE));
    if (!result) {
        result = ic_objectCreate(o);
        ic_scope_addStorage(root, ic_storage(result));
    }
    return result;
/* $end */
}

/* ::corto::ic::program::getVariable(string name) */
ic_variable _ic_program_getVariable(ic_program this, cx_string name) {
/* $begin(::corto::ic::program::getVariable) */
    return ic_variable(ic_scope_lookupStorage(this->scope, name, TRUE));
/* $end */
}

/* ::corto::ic::program::popAccumulator() */
cx_void _ic_program_popAccumulator(ic_program this) {
/* $begin(::corto::ic::program::popAccumulator) */
    ic_storage acc;
    
    this->accumulatorSp--;
    acc = ic_storage(this->accumulatorStack[this->accumulatorSp]);
    
    if (acc->holdsReturn) {
        ic_storage_free(acc);
    }
/* $end */
}

/* ::corto::ic::program::popScope() */
cx_void _ic_program_popScope(ic_program this) {
/* $begin(::corto::ic::program::popScope) */
    if (this->scope->storages) {
        cx_iter storageIter;
        ic_storage storage;

        storageIter = cx_llIter(this->scope->storages);
        while(cx_iterHasNext(&storageIter)) {
            storage = cx_iterNext(&storageIter);
            if ((storage->kind == IC_VARIABLE) && !((ic_variable)storage)->isReturn && !((ic_variable)storage)->isParameter) {
                ic_storage_free(storage);
            }
        }
    }

    if (this->scope->parent) {
        this->scope = this->scope->parent;
    }
/* $end */
}

/* ::corto::ic::program::pushAccumulator(type type,bool isReference,bool holdsReturn) */
ic_accumulator _ic_program_pushAccumulator(ic_program this, cx_type type, cx_bool isReference, cx_bool holdsReturn) {
/* $begin(::corto::ic::program::pushAccumulator) */
    cx_id name;

    sprintf(name, "#%d", this->autoAccId);
    this->autoAccId++;

    this->accumulatorStack[this->accumulatorSp] = 
        ic_accumulatorCreate(name, type ? type : cx_void_o, isReference, holdsReturn);

    this->accumulatorSp++;
    return this->accumulatorStack[this->accumulatorSp-1];
/* $end */
}

/* ::corto::ic::program::pushFunction(function function) */
ic_scope _ic_program_pushFunction(ic_program this, cx_function function) {
/* $begin(::corto::ic::program::pushFunction) */
    ic_function label;
    ic_scope scope;

    /* Add function-label */
    label = ic_functionCreate(function);
    ic_program_add(this, ic_node(label));

    /* Push function-scope */
    scope = ic_program_pushScope(this);
    scope->isFunction = TRUE;

    return scope;
/* $end */
}

/* ::corto::ic::program::pushScope() */
ic_scope _ic_program_pushScope(ic_program this) {
/* $begin(::corto::ic::program::pushScope) */
    this->scope = ic_scopeCreate(this->scope, FALSE);

    if (this->scope->parent) {
        cx_llAppend(this->scope->parent->program, this->scope);
    }

    return this->scope;
/* $end */
}

/* ::corto::ic::program::run(word result,sequence{string} argv) */
cx_int16 _ic_program_run(ic_program this, cx_word result, cx_stringSeq argv) {
/* $begin(::corto::ic::program::run) */
    vm_program program = (vm_program)this->vmprogram;
    vm_run(program, argv, (void*)result);
    return 0;
/* $end */
}

/* ::corto::ic::program::str() */
cx_string _ic_program_str(ic_program this) {
/* $begin(::corto::ic::program::str) */
    cx_string result = NULL;

#ifdef CX_IC_TRACING
    result = strappend(result, "%%file %s\n", this->filename);
    result = ic_scope_str(this->scope, result);
#endif
    return result;
/* $end */
}
