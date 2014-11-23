/* Fast_Block.c
 *
 *  Generated on Nov 18 2014
 *    This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "Fast_Block.h"
#include "Fast__meta.h"


/* $header() */
#include "Fast_Expression.h"
#include "Fast_Parser.h"
#include "Fast_While.h"
#include "Fast__api.h"
void Fast_Parser_error(Fast_Parser _this, char* fmt, ...);
Fast_Parser yparser(void);
/* $end */

/* ::hyve::Fast::Block::addStatement(Fast::Node statement) */
void Fast_Block_addStatement(Fast_Block _this, Fast_Node statement) {
/* $begin(::hyve::Fast::Block::addStatement) */
	db_assert(_this->statements != NULL, "initialization failed");
	db_llAppend(_this->statements, statement);
	db_keep_ext(_this, statement, "Add statement to block");
/* $end */
}

/* ::hyve::Fast::Block::declare(lang::string id,Fast::Variable type,lang::bool isParameter,bool isReference) */
Fast_Local Fast_Block_declare(Fast_Block _this, db_string id, Fast_Variable type, db_bool isParameter, db_bool isReference) {
/* $begin(::hyve::Fast::Block::declare) */
	Fast_Local result;
    Fast_LocalKind kind = 0;

	db_assert(_this->locals != NULL, "initialization failed");
    
	/* Check if variable already exists. Use lookupLocal instead of lookup since the ordinary lookup also
	 * looks for member-variables if the block is part of a function. */
	if (Fast_Block_lookupLocal(_this, id)) {
		printf("%s:%d:%d: local '%s' already declared\n", yparser()->filename, yparser()->line, yparser()->column, id);
		goto error;
	}

	/* If variable did not exist, declare it in this block */
    kind = isParameter ? FAST_LocalParameter : FAST_LocalDefault;
	result = Fast_Local__create(id, type, kind, isReference);
	db_llAppend(_this->locals, result);

	return result;
error:
	return NULL;
/* $end */
}

/* ::hyve::Fast::Block::declareReturnVariable(lang::function function) */
Fast_Local Fast_Block_declareReturnVariable(Fast_Block _this, db_function function) {
/* $begin(::hyve::Fast::Block::declareReturnVariable) */
	Fast_Local result;
    Fast_Object type;
	db_id id;

	/* Get name of function from signature */
	db_signatureName(db_nameof(function), id);

	db_assert(_this->locals != NULL, "initialization failed");

	/* If variable did not exist, declare it in this block */
    type = Fast_Object__create(function->returnType);
    Fast_Parser_collect(yparser(), type);
	result = Fast_Local__create(id, Fast_Variable(type), FAST_LocalReturn, function->returnsReference);
	db_llAppend(_this->locals, result);

	return result;
/* $end */
}

/* ::hyve::Fast::Block::declareTemplate(lang::string id,Fast::Variable type,lang::bool isParameter,bool isReference) */
Fast_Template Fast_Block_declareTemplate(Fast_Block _this, db_string id, Fast_Variable type, db_bool isParameter, db_bool isReference) {
/* $begin(::hyve::Fast::Block::declareTemplate) */
	Fast_Template result;

	db_assert(_this->locals != NULL, "initialization failed");

	/* Check if variable already exists */
	if (Fast_Block_lookup(_this, id)) {
		printf("%s:%d:%d: variable '%s' already declared\n", yparser()->filename, yparser()->line, yparser()->column, id);
		goto error;
	}

	/* If variable did not exist, declare it in this block */
	result = Fast_Template__create(id, type, isParameter, isReference);
	db_llInsert(_this->locals, result);

	return result;
error:
	return NULL;
/* $end */
}

/* ::hyve::Fast::Block::lookup(lang::string id) */
Fast_Expression Fast_Block_lookup(Fast_Block _this, db_string id) {
/* $begin(::hyve::Fast::Block::lookup) */
	Fast_Expression result = NULL;

	result = Fast_Block_lookupLocal(_this, id);

    if (!result) {
    	if (_this->function) {
    		if ((db_procedure(db_typeof(_this->function))->kind == DB_METHOD) ||
    			((db_procedure(db_typeof(_this->function))->kind == DB_OBSERVER) && db_observer(_this->function)->template)) {
    			if (strcmp(id, "this")) {
					db_interface parent;
					db_member m;
					Fast_Expression thisLocal;

					thisLocal = Fast_Block_lookup(_this, "this");

					/* If function is scoped use the parentof function to determine it's parent. The current scope can point
					 * to a different object since functions can be forward declared. If the function is anonymous (for example
					 * in the case of anonymous observers) using the parser-scope is safe since these functions can't be forward
					 * declared.
					 */
					if (db_checkAttr(_this->function, DB_ATTR_SCOPED)) {
					    parent = db_parentof(_this->function);
					} else {
					    parent = Fast_ObjectBase(yparser()->scope)->value;
					}
					m = db_interface_resolveMember(parent, id);

					/* If 'this' is not yet declared, lookup is used while declaring
					 * function parameters. */
					if (thisLocal) {
						/* If a member is found, create memberexpression */
						if (m) {
							Fast_String memberIdExpr;
							memberIdExpr = Fast_String__create(id);
							result = Fast_Expression(Fast_MemberExpr__create(
									 thisLocal, Fast_Expression(memberIdExpr)));
							Fast_Parser_collect(yparser(), memberIdExpr);
							Fast_Parser_collect(yparser(), result);
						} else {
							db_method m;
							/* If no member is found, lookup method */
							m = db_interface_resolveMethod(parent, id);
							if (m) {
								Fast_String memberIdExpr;
								memberIdExpr = Fast_String__create(id);
								result = Fast_Expression(Fast_MemberExpr__create(
										 thisLocal, Fast_Expression(memberIdExpr)));
								Fast_Parser_collect(yparser(), memberIdExpr);
								Fast_Parser_collect(yparser(), result);
							}
						}
					}
				}
    		}
    	}
    }

    return result;
/* $end */
}

/* ::hyve::Fast::Block::lookupLocal(lang::string id) */
Fast_Expression Fast_Block_lookupLocal(Fast_Block _this, db_string id) {
/* $begin(::hyve::Fast::Block::lookupLocal) */
	Fast_Expression result = NULL;

    if (_this->locals) {
    	db_iter iter;
    	Fast_Local local;
    	iter = db_llIter(_this->locals);
    	while(db_iterHasNext(&iter)) {
    		local = db_iterNext(&iter);
    		if (!strcmp(local->name, id)) {
    			result = Fast_Expression(local);
    			break;
    		}
    	}
    }

    return result;
/* $end */
}

/* ::hyve::Fast::Block::resolve(lang::string id) */
Fast_Expression Fast_Block_resolve(Fast_Block _this, db_string id) {
/* $begin(::hyve::Fast::Block::resolve) */
	Fast_Expression result = NULL;

    if (!(result = Fast_Block_lookup(_this, id))) {
    	if (_this->parent && !_this->function) {
    		result = Fast_Block_resolve(_this->parent, id);
    	}
    }

    return result;
/* $end */
}

/* ::hyve::Fast::Block::setFunction(lang::function function */
void Fast_Block_setFunction(Fast_Block _this, db_function function) {
/* $begin(::hyve::Fast::Block::setFunction) */
	_this->function = function;
	db_keep_ext(_this, function, "Set function for block");
/* $end */
}

/* virtual ::hyve::Fast::Block::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_Block_toIc(Fast_Block _this, db_icProgram program, db_icStorage storage, db_bool stored) {
    static db_uint32 _methodId;
    db_method _method;
    db_ic _result;
    db_interface _abstract;

    _abstract = db_interface(db_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = db_interface_resolveMethodId(_abstract, "toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)");
    }
    db_assert(_methodId, "virtual method 'toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)' not found in abstract '%s'", db_nameof(_abstract));

    /* Lookup method-object. */
    _method = db_interface_resolveMethodById(_abstract, _methodId);
    db_assert(_method != NULL, "unresolved method '%s::toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)@%d'", db_nameof(_this), _methodId);

    /* Call method directly if it's a C-function. */
    if (_method->_parent.kind == DB_PROCEDURE_CDECL) {
        db_assert(_method->_parent.impl, "missing implementation for '%s::toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)'.", db_nameof(_this));
        _result = ((db_ic(*)(Fast_Block, db_icProgram , db_icStorage , db_bool ))_method->_parent.impl)(_this, program, storage, stored);
    } else {
        /* Function is implemented in another language. */
        db_call(db_function(_method), &_result, _this, program, storage, stored);
    }
    
    return _result;
}

/* ::hyve::Fast::Block::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_Block_toIc_v(Fast_Block _this, db_icProgram program, db_icStorage storage, db_bool stored) {
/* $begin(::hyve::Fast::Block::toIc) */
    db_icScope scope;
	DB_UNUSED(storage);
	DB_UNUSED(stored);
    
    scope = db_icProgram_scopePush(program, Fast_Node(_this)->line);
    
    if (!_this->_while) {
        Fast_Block_toIcBody_v(_this, program, storage, stored);
    } else {
        Fast_While_toIc(_this->_while, program, storage, stored);
    }

    db_icProgram_scopePop(program, Fast_Node(_this)->line);

	return (db_ic)scope;
/* $end */
}

/* virtual ::hyve::Fast::Block::toIcBody(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_Block_toIcBody(Fast_Block _this, db_icProgram program, db_icStorage storage, db_bool stored) {
    static db_uint32 _methodId;
    db_method _method;
    db_ic _result;
    db_interface _abstract;

    _abstract = db_interface(db_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = db_interface_resolveMethodId(_abstract, "toIcBody(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)");
    }
    db_assert(_methodId, "virtual method 'toIcBody(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)' not found in abstract '%s'", db_nameof(_abstract));

    /* Lookup method-object. */
    _method = db_interface_resolveMethodById(_abstract, _methodId);
    db_assert(_method != NULL, "unresolved method '%s::toIcBody(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)@%d'", db_nameof(_this), _methodId);

    /* Call method directly if it's a C-function. */
    if (_method->_parent.kind == DB_PROCEDURE_CDECL) {
        db_assert(_method->_parent.impl, "missing implementation for '%s::toIcBody(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)'.", db_nameof(_this));
        _result = ((db_ic(*)(Fast_Block, db_icProgram , db_icStorage , db_bool ))_method->_parent.impl)(_this, program, storage, stored);
    } else {
        /* Function is implemented in another language. */
        db_call(db_function(_method), &_result, _this, program, storage, stored);
    }
    
    return _result;
}

/* ::hyve::Fast::Block::toIcBody(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_Block_toIcBody_v(Fast_Block _this, db_icProgram program, db_icStorage storage, db_bool stored) {
/* $begin(::hyve::Fast::Block::toIcBody) */
	Fast_Node statement;
	db_iter statementIter;
	db_iter localIter;
	Fast_Local local;
	DB_UNUSED(storage);
	DB_UNUSED(stored);
    
    /* Declare locals */
    if (_this->locals) {
        localIter = db_llIter(_this->locals);
        while(db_iterHasNext(&localIter)) {
            local = db_iterNext(&localIter);
            db_icLocal__create(
                    program,
                    Fast_Node(_this)->line,
                    local->name,
                    Fast_Expression_getType(Fast_Expression(local)),
                    local->kind == FAST_LocalParameter,
                    local->kind == FAST_LocalReturn,
                    TRUE);
        }
    }
    
    if (_this->statements) {
        statementIter = db_llIter(_this->statements);
        while(db_iterHasNext(&statementIter)) {
            statement = db_iterNext(&statementIter);
            Fast_Node_toIc(statement, program, NULL, FALSE);
        }
    }

    return NULL;
/* $end */
}
