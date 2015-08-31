/* Fast_Block.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "Fast.h"

/* $header() */
#include "Fast__private.h"
/* $end */

/* ::corto::Fast::Block::addStatement(Fast::Node statement) */
cx_void _Fast_Block_addStatement(Fast_Block _this, Fast_Node statement) {
/* $begin(::corto::Fast::Block::addStatement) */
    if (statement) {
        cx_assert(_this->statements != NULL, "initialization failed");
        Fast_Node_listAppend(_this->statements, statement);
    }
/* $end */
}

/* ::corto::Fast::Block::declare(string id,type type,bool isParameter,bool isReference) */
Fast_Local _Fast_Block_declare(Fast_Block _this, cx_string id, cx_type type, cx_bool isParameter, cx_bool isReference) {
/* $begin(::corto::Fast::Block::declare) */
    Fast_Local result;
    Fast_LocalKind kind = 0;

    cx_assert(_this->locals != NULL, "initialization failed");
    
    /* Check if variable already exists. Use lookupLocal instead of lookup since the ordinary lookup also
     * looks for member-variables if the block is part of a function. */
    if (Fast_Block_lookupLocal(_this, id)) {
        printf("%s:%d:%d: local '%s' already declared\n", yparser()->filename, yparser()->line, yparser()->column, id);
        goto error;
    }

    /* If variable did not exist, declare it in this block */
    kind = isParameter ? Fast_LocalParameter : Fast_LocalDefault;
    result = Fast_LocalCreate(id, type, kind, isReference);
    if (result) {
        cx_llAppend(_this->locals, result);
    } else {
        goto error;
    }

    return result;
error:
    return NULL;
/* $end */
}

/* ::corto::Fast::Block::declareReturnVariable(function function) */
Fast_Local _Fast_Block_declareReturnVariable(Fast_Block _this, cx_function function) {
/* $begin(::corto::Fast::Block::declareReturnVariable) */
    Fast_Local result;
    cx_id id;

    /* Get name of function from signature */
    cx_signatureName(cx_nameof(function), id);

    cx_assert(_this->locals != NULL, "initialization failed");

    /* If variable did not exist, declare it in this block */
    result = Fast_LocalCreate(id, function->returnType, Fast_LocalReturn, function->returnsReference);
    if (result) {
        cx_llAppend(_this->locals, result);
    }

    return result;
/* $end */
}

/* ::corto::Fast::Block::declareTemplate(string id,type type,bool isParameter,bool isReference) */
Fast_Template _Fast_Block_declareTemplate(Fast_Block _this, cx_string id, cx_type type, cx_bool isParameter, cx_bool isReference) {
/* $begin(::corto::Fast::Block::declareTemplate) */
    Fast_Template result;

    cx_assert(_this->locals != NULL, "initialization failed");

    /* Check if variable already exists */
    if (Fast_Block_lookup(_this, id)) {
        printf("%s:%d:%d: variable '%s' already declared\n", yparser()->filename, yparser()->line, yparser()->column, id);
        goto error;
    }

    /* If variable did not exist, declare it in this block */
    result = Fast_TemplateCreate(id, type, isParameter, isReference);
    if (result) {
        cx_llInsert(_this->locals, result);
    }

    return result;
error:
    return NULL;
/* $end */
}

/* ::corto::Fast::Block::lookup(string id) */
Fast_Expression _Fast_Block_lookup(Fast_Block _this, cx_string id) {
/* $begin(::corto::Fast::Block::lookup) */
    Fast_Expression result = NULL;

    result = Fast_Expression(Fast_Block_lookupLocal(_this, id));

    if (!result) {
        if (_this->function) {
            if ((cx_procedure(cx_typeof(_this->function))->kind == CX_METHOD) ||
               ((cx_procedure(cx_typeof(_this->function))->kind == CX_OBSERVER) && 
               cx_observer(_this->function)->template)) {
                if (strcmp(id, "this")) {
                    cx_object parent;
                    cx_member m;
                    Fast_Expression thisLocal;

                    thisLocal = Fast_Block_lookup(_this, "this");

                    /* If function is scoped use the parentof function to determine it's parent. The current scope can point
                     * to a different object since functions can be forward declared. If the function is anonymous (for example
                     * in the case of anonymous observers) using the parser-scope is safe since these functions can't be forward
                     * declared.
                     */
                    if (cx_checkAttr(_this->function, CX_ATTR_SCOPED)) {
                        parent = cx_parentof(_this->function);
                    } else {
                        parent = yparser()->scope;
                    }

                    /* If parent is not of an interface type, this could be a
                     * delegate member implementation. Get type of the parent
                     * instead. */
                    if (!cx_instanceof(cx_type(cx_interface_o), parent)) {
                        parent = cx_typeof(parent);
                    }

                    /* If parent is still not of an interface type, resolving
                     * a 'this' from either a method or observer is illegal */
                    if (!cx_instanceof(cx_type(cx_interface_o), parent)) {
                        cx_id id;
                        Fast_Parser_error(yparser(), 
                            "'this' illegal in procedure '%s'", 
                            Fast_Parser_id(_this->function, id));
                        goto error;
                    }                    

                    m = cx_interface_resolveMember(cx_interface(parent), id);

                    /* If 'this' is not yet declared, lookup is used while declaring
                     * function parameters. */
                    if (thisLocal) {
                        /* If a member is found, create memberexpression */
                        if (m) {
                            Fast_String memberIdExpr;
                            memberIdExpr = Fast_StringCreate(id);
                            result = Fast_Expression(Fast_MemberCreate(
                                     thisLocal, Fast_Expression(memberIdExpr)));
                            Fast_Parser_collect(yparser(), memberIdExpr);
                            Fast_Parser_collect(yparser(), result);
                        } else {
                            cx_method m;
                            /* If no member is found, lookup method */
                            m = cx_interface_resolveMethod(cx_interface(parent), id);
                            if (m) {
                                Fast_String memberIdExpr;
                                memberIdExpr = Fast_StringCreate(id);
                                result = Fast_Expression(Fast_MemberCreate(
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
error:
    return NULL;
/* $end */
}

/* ::corto::Fast::Block::lookupLocal(string id) */
Fast_Local _Fast_Block_lookupLocal(Fast_Block _this, cx_string id) {
/* $begin(::corto::Fast::Block::lookupLocal) */
    Fast_Local result = NULL;

    if (_this->locals) {
        cx_iter iter;
        Fast_Local local;
        iter = cx_llIter(_this->locals);
        while(cx_iterHasNext(&iter)) {
            local = cx_iterNext(&iter);
            if (!strcmp(local->name, id)) {
                result = local;
                break;
            }
        }
    }

    return result;
/* $end */
}

/* ::corto::Fast::Block::resolve(string id) */
Fast_Expression _Fast_Block_resolve(Fast_Block _this, cx_string id) {
/* $begin(::corto::Fast::Block::resolve) */
    Fast_Expression result = NULL;

    if (!(result = Fast_Block_lookup(_this, id))) {
        if (_this->parent && !_this->function) {
            result = Fast_Block_resolve(_this->parent, id);
        }
    }

    return result;
/* $end */
}

/* ::corto::Fast::Block::resolveLocal(string id) */
Fast_Local _Fast_Block_resolveLocal(Fast_Block _this, cx_string id) {
/* $begin(::corto::Fast::Block::resolveLocal) */
    Fast_Local result = NULL;

    if (!(result = Fast_Block_lookupLocal(_this, id))) {
        if (_this->parent && !_this->function) {
            result = Fast_Block_resolveLocal(_this->parent, id);
        }
    }

    return result;
/* $end */
}

/* ::corto::Fast::Block::setFunction(function function */
cx_void _Fast_Block_setFunction(Fast_Block _this, cx_function function) {
/* $begin(::corto::Fast::Block::setFunction) */
    cx_setref(&_this->function, function);
/* $end */
}

/* ::corto::Fast::Block::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node _Fast_Block_toIc_v(Fast_Block _this, ic_program program, ic_storage storage, cx_bool stored) {
/* $begin(::corto::Fast::Block::toIc) */
    ic_scope scope;
    CX_UNUSED(storage);
    CX_UNUSED(stored);
    
    scope = ic_program_pushScope(program);
    
    if (!_this->_while) {
        Fast_Block_toIcBody_v(_this, program, storage, stored);
    } else {
        Fast_While_toIc(_this->_while, program, storage, stored);
    }

    ic_program_popScope(program);

    return (ic_node)scope;
/* $end */
}

/* ::corto::Fast::Block::toIcBody(ic::program program,ic::storage storage,bool stored) */
ic_node _Fast_Block_toIcBody_v(Fast_Block _this, ic_program program, ic_storage storage, cx_bool stored) {
/* $begin(::corto::Fast::Block::toIcBody) */
    Fast_Node statement;
    cx_iter statementIter;
    cx_iter localIter;
    Fast_Local local;
    CX_UNUSED(storage);
    CX_UNUSED(stored);
    
    /* Declare locals */
    if (_this->locals) {
        localIter = cx_llIter(_this->locals);
        while(cx_iterHasNext(&localIter)) {
            local = cx_iterNext(&localIter);
            ic_program_declareVariable(
                    program,
                    local->name,
                    Fast_Expression_getType(Fast_Expression(local)),
                    Fast_Expression(local)->isReference,
                    FALSE,
                    local->kind == Fast_LocalParameter,
                    local->kind == Fast_LocalReturn);
        }
    }
    
    if (_this->statements) {
        statementIter = cx_llIter(_this->statements);
        while(cx_iterHasNext(&statementIter)) {
            statement = cx_iterNext(&statementIter);
            Fast_Node_toIc(statement, program, NULL, FALSE);
        }
    }

    return NULL;
/* $end */
}
