/* ast_Block.c
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
/* $end */

/* ::corto::ast::Block::addStatement(ast::Node statement) */
cx_void _ast_Block_addStatement(ast_Block this, ast_Node statement) {
/* $begin(::corto::ast::Block::addStatement) */
    if (statement) {
        cx_assert(this->statements != NULL, "initialization failed");
        ast_NodeListAppend(this->statements, statement);
    }
/* $end */
}

/* ::corto::ast::Block::declare(string id,type type,bool isParameter,bool isReference) */
ast_Local _ast_Block_declare(ast_Block this, cx_string id, cx_type type, cx_bool isParameter, cx_bool isReference) {
/* $begin(::corto::ast::Block::declare) */
    ast_Local result;
    ast_LocalKind kind = 0;

    cx_assert(this->locals != NULL, "initialization failed");
    
    /* Check if variable already exists. Use lookupLocal instead of lookup since the ordinary lookup also
     * looks for member-variables if the block is part of a function. */
    if (ast_Block_lookupLocal(this, id)) {
        printf("%s:%d:%d: local '%s' already declared\n", yparser()->filename, yparser()->line, yparser()->column, id);
        goto error;
    }

    /* If variable did not exist, declare it in this block */
    kind = isParameter ? Ast_LocalParameter : Ast_LocalDefault;
    result = ast_LocalCreate(id, type, kind, isReference);
    if (result) {
        cx_llAppend(this->locals, result);
    } else {
        goto error;
    }

    return result;
error:
    return NULL;
/* $end */
}

/* ::corto::ast::Block::declareReturnVariable(function function) */
ast_Local _ast_Block_declareReturnVariable(ast_Block this, cx_function function) {
/* $begin(::corto::ast::Block::declareReturnVariable) */
    ast_Local result;
    cx_id id;

    /* Get name of function from signature */
    cx_signatureName(cx_nameof(function), id);

    cx_assert(this->locals != NULL, "initialization failed");

    /* If variable did not exist, declare it in this block */
    result = ast_LocalCreate(id, function->returnType, Ast_LocalReturn, function->returnsReference);
    if (result) {
        cx_llAppend(this->locals, result);
    }

    return result;
/* $end */
}

/* ::corto::ast::Block::declareTemplate(string id,type type,bool isParameter,bool isReference) */
ast_Template _ast_Block_declareTemplate(ast_Block this, cx_string id, cx_type type, cx_bool isParameter, cx_bool isReference) {
/* $begin(::corto::ast::Block::declareTemplate) */
    ast_Template result;

    cx_assert(this->locals != NULL, "initialization failed");

    /* Check if variable already exists */
    if (ast_Block_lookup(this, id)) {
        printf("%s:%d:%d: variable '%s' already declared\n", yparser()->filename, yparser()->line, yparser()->column, id);
        goto error;
    }

    /* If variable did not exist, declare it in this block */
    result = ast_TemplateCreate(id, type, isParameter, isReference);
    if (result) {
        cx_llInsert(this->locals, result);
    }

    return result;
error:
    return NULL;
/* $end */
}

/* ::corto::ast::Block::lookup(string id) */
ast_Expression _ast_Block_lookup(ast_Block this, cx_string id) {
/* $begin(::corto::ast::Block::lookup) */
    ast_Expression result = NULL;

    result = ast_Expression(ast_Block_lookupLocal(this, id));

    if (!result) {
        if (this->function) {
            if ((cx_procedure(cx_typeof(this->function))->kind == CX_METHOD) ||
               ((cx_procedure(cx_typeof(this->function))->kind == CX_OBSERVER) && 
               cx_observer(this->function)->template)) {
                if (strcmp(id, "this")) {
                    cx_object parent;
                    cx_member m;
                    ast_Expression thisLocal;

                    thisLocal = ast_Block_lookup(this, "this");

                    /* If function is scoped use the parentof function to determine it's parent. The current scope can point
                     * to a different object since functions can be forward declared. If the function is anonymous (for example
                     * in the case of anonymous observers) using the parser-scope is safe since these functions can't be forward
                     * declared.
                     */
                    if (cx_checkAttr(this->function, CX_ATTR_SCOPED)) {
                        parent = cx_parentof(this->function);
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
                        ast_Parser_error(yparser(), 
                            "'this' illegal in procedure '%s'", 
                            ast_Parser_id(this->function, id));
                        goto error;
                    }                    

                    m = cx_interface_resolveMember(cx_interface(parent), id);

                    /* If 'this' is not yet declared, lookup is used while declaring
                     * function parameters. */
                    if (thisLocal) {
                        /* If a member is found, create memberexpression */
                        if (m) {
                            ast_String memberIdExpr;
                            memberIdExpr = ast_StringCreate(id);
                            result = ast_Expression(ast_MemberCreate(
                                     thisLocal, ast_Expression(memberIdExpr)));
                            ast_Parser_collect(yparser(), memberIdExpr);
                            ast_Parser_collect(yparser(), result);
                        } else {
                            cx_method m;
                            /* If no member is found, lookup method */
                            m = cx_interface_resolveMethod(cx_interface(parent), id);
                            if (m) {
                                ast_String memberIdExpr;
                                memberIdExpr = ast_StringCreate(id);
                                result = ast_Expression(ast_MemberCreate(
                                         thisLocal, ast_Expression(memberIdExpr)));
                                ast_Parser_collect(yparser(), memberIdExpr);
                                ast_Parser_collect(yparser(), result);
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

/* ::corto::ast::Block::lookupLocal(string id) */
ast_Local _ast_Block_lookupLocal(ast_Block this, cx_string id) {
/* $begin(::corto::ast::Block::lookupLocal) */
    ast_Local result = NULL;

    if (this->locals) {
        cx_iter iter;
        ast_Local local;
        iter = cx_llIter(this->locals);
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

/* ::corto::ast::Block::resolve(string id) */
ast_Expression _ast_Block_resolve(ast_Block this, cx_string id) {
/* $begin(::corto::ast::Block::resolve) */
    ast_Expression result = NULL;

    if (!(result = ast_Block_lookup(this, id))) {
        if (this->parent && !this->function) {
            result = ast_Block_resolve(this->parent, id);
        }
    }

    return result;
/* $end */
}

/* ::corto::ast::Block::resolveLocal(string id) */
ast_Local _ast_Block_resolveLocal(ast_Block this, cx_string id) {
/* $begin(::corto::ast::Block::resolveLocal) */
    ast_Local result = NULL;

    if (!(result = ast_Block_lookupLocal(this, id))) {
        if (this->parent && !this->function) {
            result = ast_Block_resolveLocal(this->parent, id);
        }
    }

    return result;
/* $end */
}

/* ::corto::ast::Block::setFunction(function function */
cx_void _ast_Block_setFunction(ast_Block this, cx_function function) {
/* $begin(::corto::ast::Block::setFunction) */
    cx_setref(&this->function, function);
/* $end */
}

/* ::corto::ast::Block::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node _ast_Block_toIc_v(ast_Block this, ic_program program, ic_storage storage, cx_bool stored) {
/* $begin(::corto::ast::Block::toIc) */
    ic_scope scope;
    CX_UNUSED(storage);
    CX_UNUSED(stored);
    
    scope = ic_program_pushScope(program);
    
    if (!this->_while) {
        ast_Block_toIcBody_v(this, program, storage, stored);
    } else {
        ast_While_toIc(this->_while, program, storage, stored);
    }

    ic_program_popScope(program);

    return (ic_node)scope;
/* $end */
}

/* ::corto::ast::Block::toIcBody(ic::program program,ic::storage storage,bool stored) */
ic_node _ast_Block_toIcBody_v(ast_Block this, ic_program program, ic_storage storage, cx_bool stored) {
/* $begin(::corto::ast::Block::toIcBody) */
    ast_Node statement;
    cx_iter statementIter;
    cx_iter localIter;
    ast_Local local;
    CX_UNUSED(storage);
    CX_UNUSED(stored);
    
    /* Declare locals */
    if (this->locals) {
        localIter = cx_llIter(this->locals);
        while(cx_iterHasNext(&localIter)) {
            local = cx_iterNext(&localIter);
            ic_program_declareVariable(
                    program,
                    local->name,
                    ast_Expression_getType(ast_Expression(local)),
                    ast_Expression(local)->isReference,
                    FALSE,
                    local->kind == Ast_LocalParameter,
                    local->kind == Ast_LocalReturn);
        }
    }
    
    if (this->statements) {
        statementIter = cx_llIter(this->statements);
        while(cx_iterHasNext(&statementIter)) {
            statement = cx_iterNext(&statementIter);
            ast_Node_toIc(statement, program, NULL, FALSE);
        }
    }

    return NULL;
/* $end */
}
