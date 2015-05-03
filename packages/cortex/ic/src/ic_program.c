/* ic_program.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "ic.h"

/* $header() */
#include "ic_assemble.h"
/* $end */

/* ::cortex::ic::program::add(node n) */
cx_void ic_program_add(ic_program _this, ic_node n) {
/* $begin(::cortex::ic::program::add) */

    if (n->kind == IC_OP) {
        if (!ic_op_validate(ic_op(n), _this)) {
            _this->errors++;
        }
    }
    ic_node_list__append(_this->scope->program, n);

/* $end */
}

/* ::cortex::ic::program::assemble() */
cx_int16 ic_program_assemble(ic_program _this) {
/* $begin(::cortex::ic::program::assemble) */
    cx_vmProgram program;

    program = ic_vmAssemble(_this);
    if (program) {
        goto error;
    }

    return 0;
error:
    return -1;
/* $end */
}

/* ::cortex::ic::program::popAccumulator() */
cx_void ic_program_popAccumulator(ic_program _this) {
/* $begin(::cortex::ic::program::popAccumulator) */
    ic_storage acc;
    
    _this->accumulatorSp--;
    acc = ic_storage(_this->accumulatorStack[_this->accumulatorSp]);
    
    if (acc->holdsReturn) {
        ic_storage_free(acc, _this);
    }
/* $end */
}

/* ::cortex::ic::program::popScope() */
cx_void ic_program_popScope(ic_program _this) {
/* $begin(::cortex::ic::program::popScope) */
    if (_this->scope->storages) {
        cx_iter storageIter;
        ic_storage storage;

        storageIter = cx_llIter(_this->scope->storages);
        while(cx_iterHasNext(&storageIter)) {
            storage = cx_iterNext(&storageIter);
            if ((storage->kind == IC_VARIABLE) && !((ic_variable)storage)->isReturn && !((ic_variable)storage)->isParameter) {
                ic_storage_free(storage, _this);
            }
        }
    }

    if (_this->scope->parent) {
        _this->scope = _this->scope->parent;
    }
/* $end */
}

/* ::cortex::ic::program::pushAccumulator(type type,bool isReference,bool holdsReturn) */
ic_accumulator ic_program_pushAccumulator(ic_program _this, cx_type type, cx_bool isReference, cx_bool holdsReturn) {
/* $begin(::cortex::ic::program::pushAccumulator) */
    cx_id name;

    sprintf(name, "#%d", _this->autoAccId);
    _this->autoAccId++;

    _this->accumulatorStack[_this->accumulatorSp] = 
        ic_accumulator__create(NULL, name, type ? type : cx_void_o, isReference, holdsReturn);

    _this->accumulatorSp++;
    return _this->accumulatorStack[_this->accumulatorSp-1];
/* $end */
}

/* ::cortex::ic::program::pushFunction(function function) */
ic_scope ic_program_pushFunction(ic_program _this, cx_function function) {
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
ic_scope ic_program_pushScope(ic_program _this) {
/* $begin(::cortex::ic::program::pushScope) */
    _this->scope = ic_scope__create(_this->scope, FALSE);

    if (_this->scope->parent) {
        cx_llAppend(_this->scope->parent->program, _this->scope);
    }

    return _this->scope;
/* $end */
}
