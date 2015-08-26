/* ic_program.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "ic.h"

/* $header() */
#include "ic_assemble.h"
/* $end */

/* ::cortex::ic::program::add(node n) */
cx_void _ic_program_add(ic_program _this, ic_node n) {
/* $begin(::cortex::ic::program::add) */

    if (n->kind == IC_OP) {
        if (!ic_op_validate(ic_op(n))) {
            _this->errors++;
        }
    }

    if (cx_instanceof(cx_type(ic_storage_o), n)) {
        ic_node_list__append(_this->scope->storages, n);
    } else {
        ic_node_list__append(_this->scope->program, n);
    }

/* $end */
}

/* ::cortex::ic::program::assemble() */
cx_int16 _ic_program_assemble(ic_program _this) {
/* $begin(::cortex::ic::program::assemble) */

    if (CX_DEBUG_ENABLED) {
        cx_string str = ic_program_str(_this);
        if (str) {
            printf("%s\n", str);
            cx_dealloc(str);
        }
    }

    _this->vmprogram = (cx_word)ic_vmAssemble(_this);
    if (!_this->vmprogram) {
        goto error;
    }

    return 0;
error:
    return -1;
/* $end */
}

/* ::cortex::ic::program::construct() */
cx_int16 _ic_program_construct(ic_program _this) {
/* $begin(::cortex::ic::program::construct) */
    extern cx_threadKey IC_PROGRAM_KEY;
    cx_threadTlsSet(IC_PROGRAM_KEY, _this);
    return 0;
/* $end */
}

/* ::cortex::ic::program::declareVariable(string name,type type,bool isReference,bool holdsReturn,bool isParameter,bool isReturn) */
ic_variable _ic_program_declareVariable(ic_program _this, cx_string name, cx_type type, cx_bool isReference, cx_bool holdsReturn, cx_bool isParameter, cx_bool isReturn) {
/* $begin(::cortex::ic::program::declareVariable) */
    ic_variable result = ic_variable(ic_scope_lookupStorage(_this->scope, name, FALSE));
    if (!result) {
        result = ic_variable__create(name, type, isReference, holdsReturn, isParameter, isReturn);
        ic_scope_addStorage(_this->scope, ic_storage(result));
    }
    return result;
/* $end */
}

/* ::cortex::ic::program::get() */
ic_program _ic_program_get(void) {
/* $begin(::cortex::ic::program::get) */
    extern cx_threadKey IC_PROGRAM_KEY;
    return (ic_program)cx_threadTlsGet(IC_PROGRAM_KEY);
/* $end */
}

/* ::cortex::ic::program::getAccId() */
cx_uint32 _ic_program_getAccId(ic_program _this) {
/* $begin(::cortex::ic::program::getAccId) */
    return ++_this->autoAccId;
/* $end */
}

/* ::cortex::ic::program::getElement(storage base,node index) */
ic_element _ic_program_getElement(ic_program _this, ic_storage base, ic_node index) {
/* $begin(::cortex::ic::program::getElement) */
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
        result = ic_element__create(base, index);
        ic_scope_addStorage(_this->scope, ic_storage(result));
    }
    return result;
/* $end */
}

/* ::cortex::ic::program::getLabel() */
cx_uint32 _ic_program_getLabel(ic_program _this) {
/* $begin(::cortex::ic::program::getLabel) */
    return ++_this->labelCount;
/* $end */
}

/* ::cortex::ic::program::getMember(storage base,member m) */
ic_member _ic_program_getMember(ic_program _this, ic_storage base, cx_member m) {
/* $begin(::cortex::ic::program::getMember) */
    cx_id name;
    ic_member result;
    sprintf(name, "%s.%s", base->name, cx_nameof(m));
    result = ic_member(ic_scope_lookupStorage(base->scope, name, FALSE));
    if (!result) {
        result = ic_member__create(base, m);
        ic_scope_addStorage(_this->scope, ic_storage(result));
    }
    return result;
/* $end */
}

/* ::cortex::ic::program::getObject(object o) */
ic_object _ic_program_getObject(ic_program _this, cx_object o) {
/* $begin(::cortex::ic::program::getObject) */
    cx_id id;
    ic_scope root = _this->scope;
    ic_object result = NULL;
    while(root->parent) {
        root = root->parent;
    }
    result = ic_object(ic_scope_lookupStorage(root, cx_fullname(o, id), FALSE));
    if (!result) {
        result = ic_object__create(o);
        ic_scope_addStorage(root, ic_storage(result));
    }
    return result;
/* $end */
}

/* ::cortex::ic::program::getVariable(string name) */
ic_variable _ic_program_getVariable(ic_program _this, cx_string name) {
/* $begin(::cortex::ic::program::getVariable) */
    return ic_variable(ic_scope_lookupStorage(_this->scope, name, TRUE));
/* $end */
}

/* ::cortex::ic::program::popAccumulator() */
cx_void _ic_program_popAccumulator(ic_program _this) {
/* $begin(::cortex::ic::program::popAccumulator) */
    ic_storage acc;
    
    _this->accumulatorSp--;
    acc = ic_storage(_this->accumulatorStack[_this->accumulatorSp]);
    
    if (acc->holdsReturn) {
        ic_storage_free(acc);
    }
/* $end */
}

/* ::cortex::ic::program::popScope() */
cx_void _ic_program_popScope(ic_program _this) {
/* $begin(::cortex::ic::program::popScope) */
    if (_this->scope->storages) {
        cx_iter storageIter;
        ic_storage storage;

        storageIter = cx_llIter(_this->scope->storages);
        while(cx_iterHasNext(&storageIter)) {
            storage = cx_iterNext(&storageIter);
            if ((storage->kind == IC_VARIABLE) && !((ic_variable)storage)->isReturn && !((ic_variable)storage)->isParameter) {
                ic_storage_free(storage);
            }
        }
    }

    if (_this->scope->parent) {
        _this->scope = _this->scope->parent;
    }
/* $end */
}

/* ::cortex::ic::program::pushAccumulator(type type,bool isReference,bool holdsReturn) */
ic_accumulator _ic_program_pushAccumulator(ic_program _this, cx_type type, cx_bool isReference, cx_bool holdsReturn) {
/* $begin(::cortex::ic::program::pushAccumulator) */
    cx_id name;

    sprintf(name, "#%d", _this->autoAccId);
    _this->autoAccId++;

    _this->accumulatorStack[_this->accumulatorSp] = 
        ic_accumulator__create(name, type ? type : cx_void_o, isReference, holdsReturn);

    _this->accumulatorSp++;
    return _this->accumulatorStack[_this->accumulatorSp-1];
/* $end */
}

/* ::cortex::ic::program::pushFunction(function function) */
ic_scope _ic_program_pushFunction(ic_program _this, cx_function function) {
/* $begin(::cortex::ic::program::pushFunction) */
    ic_function label;
    ic_scope scope;

    /* Add function-label */
    label = ic_function__create(function);
    ic_program_add(_this, ic_node(label));

    /* Push function-scope */
    scope = ic_program_pushScope(_this);
    scope->isFunction = TRUE;

    return scope;
/* $end */
}

/* ::cortex::ic::program::pushScope() */
ic_scope _ic_program_pushScope(ic_program _this) {
/* $begin(::cortex::ic::program::pushScope) */
    _this->scope = ic_scope__create(_this->scope, FALSE);

    if (_this->scope->parent) {
        cx_llAppend(_this->scope->parent->program, _this->scope);
    }

    return _this->scope;
/* $end */
}

/* ::cortex::ic::program::run(word result) */
cx_int16 _ic_program_run(ic_program _this, cx_word result) {
/* $begin(::cortex::ic::program::run) */
    vm_program program = (vm_program)_this->vmprogram;
    vm_run(program, (void*)result);
    return 0;
/* $end */
}

/* ::cortex::ic::program::str() */
cx_string _ic_program_str(ic_program _this) {
/* $begin(::cortex::ic::program::str) */
    cx_string result = NULL;

#ifdef CX_IC_TRACING
    result = strappend(result, "%%file %s\n", _this->filename);
    result = ic_scope_str(_this->scope, result);
#endif
    return result;
/* $end */
}
