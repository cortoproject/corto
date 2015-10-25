/* $CORTO_GENERATED
 *
 * ic_program.c
 *
 * Code written between the begin and end tags will be preserved when the
 * file is regenerated.
 */

#include "ic.h"

/* $header() */
#include "ic_assemble.h"
/* $end */

corto_void _ic_program_add(ic_program this, ic_node n) {
/* $begin(::corto::ic::program::add) */

    if (n->kind == IC_OP) {
        if (!ic_op_validate(ic_op(n))) {
            this->errors++;
        }
    }

    if (corto_instanceof(corto_type(ic_storage_o), n)) {
        ic_nodeListAppend(this->scope->storages, n);
    } else {
        ic_nodeListAppend(this->scope->program, n);
    }

/* $end */
}

corto_int16 _ic_program_assemble(ic_program this) {
/* $begin(::corto::ic::program::assemble) */

    if (CORTO_DEBUG_ENABLED) {
        corto_string str = ic_program_str(this);
        if (str) {
            printf("%s\n", str);
            corto_dealloc(str);
        }
    }

    this->vmprogram = (corto_word)ic_vmAssemble(this);
    if (!this->vmprogram) {
        goto error;
    }

    return 0;
error:
    return -1;
/* $end */
}

corto_int16 _ic_program_construct(ic_program this) {
/* $begin(::corto::ic::program::construct) */
    extern corto_threadKey IC_PROGRAM_KEY;
    corto_threadTlsSet(IC_PROGRAM_KEY, this);
    return 0;
/* $end */
}

ic_variable _ic_program_declareVariable(ic_program this, corto_string name, corto_type type, corto_bool isReference, corto_bool holdsReturn, corto_bool isParameter, corto_bool isReturn) {
/* $begin(::corto::ic::program::declareVariable) */
    ic_variable result = ic_variable(ic_scope_lookupStorage(this->scope, name, FALSE));
    if (!result) {
        result = ic_variableCreate(name, type, isReference, holdsReturn, isParameter, isReturn);
        ic_scope_addStorage(this->scope, ic_storage(result));
    }
    return result;
/* $end */
}

ic_program _ic_program_get(void) {
/* $begin(::corto::ic::program::get) */
    extern corto_threadKey IC_PROGRAM_KEY;
    return (ic_program)corto_threadTlsGet(IC_PROGRAM_KEY);
/* $end */
}

corto_uint32 _ic_program_getAccId(ic_program this) {
/* $begin(::corto::ic::program::getAccId) */
    return ++this->autoAccId;
/* $end */
}

ic_element _ic_program_getElement(ic_program this, ic_storage base, ic_node index) {
/* $begin(::corto::ic::program::getElement) */
    corto_id name;
    ic_element result;
    if (index) {
        corto_string elemStr = ic_node_str(index, NULL);
        sprintf(name, "%s[%s]", base->name, elemStr);
        corto_dealloc(elemStr);
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

corto_uint32 _ic_program_getLabel(ic_program this) {
/* $begin(::corto::ic::program::getLabel) */
    return ++this->labelCount;
/* $end */
}

ic_member _ic_program_getMember(ic_program this, ic_storage base, corto_member m) {
/* $begin(::corto::ic::program::getMember) */
    corto_id name;
    ic_member result;
    sprintf(name, "%s.%s", base->name, corto_nameof(m));
    result = ic_member(ic_scope_lookupStorage(base->scope, name, FALSE));
    if (!result) {
        result = ic_memberCreate(base, m);
        ic_scope_addStorage(this->scope, ic_storage(result));
    }
    return result;
/* $end */
}

ic_object _ic_program_getObject(ic_program this, corto_object o) {
/* $begin(::corto::ic::program::getObject) */
    corto_id id;
    ic_scope root = this->scope;
    ic_object result = NULL;
    while(root->parent) {
        root = root->parent;
    }
    result = ic_object(ic_scope_lookupStorage(root, corto_fullname(o, id), FALSE));
    if (!result) {
        result = ic_objectCreate(o);
        ic_scope_addStorage(root, ic_storage(result));
    }
    return result;
/* $end */
}

ic_variable _ic_program_getVariable(ic_program this, corto_string name) {
/* $begin(::corto::ic::program::getVariable) */
    return ic_variable(ic_scope_lookupStorage(this->scope, name, TRUE));
/* $end */
}

corto_void _ic_program_popAccumulator(ic_program this) {
/* $begin(::corto::ic::program::popAccumulator) */
    ic_storage acc;
    
    this->accumulatorSp--;
    acc = ic_storage(this->accumulatorStack[this->accumulatorSp]);
    
    if (acc->holdsReturn) {
        ic_storage_free(acc);
    }
/* $end */
}

corto_void _ic_program_popScope(ic_program this) {
/* $begin(::corto::ic::program::popScope) */
    if (this->scope->storages) {
        corto_iter storageIter;
        ic_storage storage;

        storageIter = corto_llIter(this->scope->storages);
        while(corto_iterHasNext(&storageIter)) {
            storage = corto_iterNext(&storageIter);
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

ic_accumulator _ic_program_pushAccumulator(ic_program this, corto_type type, corto_bool isReference, corto_bool holdsReturn) {
/* $begin(::corto::ic::program::pushAccumulator) */
    corto_id name;

    sprintf(name, "#%d", this->autoAccId);
    this->autoAccId++;

    this->accumulatorStack[this->accumulatorSp] = 
        ic_accumulatorCreate(name, type ? type : corto_void_o, isReference, holdsReturn);

    this->accumulatorSp++;
    return this->accumulatorStack[this->accumulatorSp-1];
/* $end */
}

ic_scope _ic_program_pushFunction(ic_program this, corto_function function) {
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

ic_scope _ic_program_pushScope(ic_program this) {
/* $begin(::corto::ic::program::pushScope) */
    this->scope = ic_scopeCreate(this->scope, FALSE);

    if (this->scope->parent) {
        corto_llAppend(this->scope->parent->program, this->scope);
    }

    return this->scope;
/* $end */
}

corto_int16 _ic_program_run(ic_program this, corto_word result, corto_stringSeq argv) {
/* $begin(::corto::ic::program::run) */
    vm_program program = (vm_program)this->vmprogram;
    vm_run(program, argv, (void*)result);
    return 0;
/* $end */
}

corto_string _ic_program_str(ic_program this) {
/* $begin(::corto::ic::program::str) */
    corto_string result = NULL;

#ifdef CORTO_IC_TRACING
    result = strappend(result, "%%file %s\n", this->filename);
    result = ic_scope_str(this->scope, result);
#endif
    return result;
/* $end */
}
