/* $CORTO_GENERATED
 *
 * ast_Block.c
 *
 * Code written between the begin and end tags will be preserved when the
 * file is regenerated.
 */

#include "ast.h"

/* $header() */
#include "ast__private.h"
/* $end */

corto_void _ast_Block_addStatement(ast_Block this, ast_Node statement) {
/* $begin(::corto::ast::Block::addStatement) */
    if (statement) {
        corto_assert(this->statements != NULL, "initialization failed");
        ast_NodeListAppend(this->statements, statement);
    }
/* $end */
}

ast_Local _ast_Block_declare(ast_Block this, corto_string id, corto_type type, corto_bool isParameter, corto_bool isReference) {
/* $begin(::corto::ast::Block::declare) */
    ast_Local result;
    ast_LocalKind kind = 0;

    corto_assert(this->locals != NULL, "initialization failed");
    
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
        corto_llAppend(this->locals, result);
    } else {
        goto error;
    }

    return result;
error:
    return NULL;
/* $end */
}

ast_Local _ast_Block_declareReturnVariable(ast_Block this, corto_function function) {
/* $begin(::corto::ast::Block::declareReturnVariable) */
    ast_Local result;
    corto_id id;

    /* Get name of function from signature */
    corto_signatureName(corto_nameof(function), id);

    corto_assert(this->locals != NULL, "initialization failed");

    /* If variable did not exist, declare it in this block */
    result = ast_LocalCreate(id, function->returnType, Ast_LocalReturn, function->returnsReference);
    if (result) {
        corto_llAppend(this->locals, result);
    }

    return result;
/* $end */
}

ast_Template _ast_Block_declareTemplate(ast_Block this, corto_string id, corto_type type, corto_bool isParameter, corto_bool isReference) {
/* $begin(::corto::ast::Block::declareTemplate) */
    ast_Template result;

    corto_assert(this->locals != NULL, "initialization failed");

    /* Check if variable already exists */
    if (ast_Block_lookup(this, id)) {
        printf("%s:%d:%d: variable '%s' already declared\n", yparser()->filename, yparser()->line, yparser()->column, id);
        goto error;
    }

    /* If variable did not exist, declare it in this block */
    result = ast_TemplateCreate(id, type, isParameter, isReference);
    if (result) {
        corto_llInsert(this->locals, result);
    }

    return result;
error:
    return NULL;
/* $end */
}

ast_Expression _ast_Block_lookup(ast_Block this, corto_string id) {
/* $begin(::corto::ast::Block::lookup) */
    ast_Expression result = NULL;

    result = ast_Expression(ast_Block_lookupLocal(this, id));

    if (!result) {
        if (this->function) {
            if ((corto_procedure(corto_typeof(this->function))->kind == CORTO_METHOD) ||
               ((corto_procedure(corto_typeof(this->function))->kind == CORTO_OBSERVER) && 
               corto_observer(this->function)->_template)) {
                if (strcmp(id, "this")) {
                    corto_object parent;
                    corto_member m;
                    ast_Expression thisLocal;

                    thisLocal = ast_Block_lookup(this, "this");

                    /* If function is scoped use the parentof function to determine it's parent. The current scope can point
                     * to a different object since functions can be forward declared. If the function is anonymous (for example
                     * in the case of anonymous observers) using the parser-scope is safe since these functions can't be forward
                     * declared.
                     */
                    if (corto_checkAttr(this->function, CORTO_ATTR_SCOPED)) {
                        parent = corto_parentof(this->function);
                    } else {
                        parent = yparser()->scope;
                    }

                    /* If parent is not of an interface type, this could be a
                     * delegate member implementation. Get type of the parent
                     * instead. */
                    if (!corto_instanceof(corto_type(corto_interface_o), parent)) {
                        parent = corto_typeof(parent);
                    }

                    /* If parent is still not of an interface type, resolving
                     * a 'this' from either a method or observer is illegal */
                    if (!corto_instanceof(corto_type(corto_interface_o), parent)) {
                        corto_id id;
                        ast_Parser_error(yparser(), 
                            "'this' illegal in procedure '%s'", 
                            ast_Parser_id(this->function, id));
                        goto error;
                    }                    

                    m = corto_interface_resolveMember(corto_interface(parent), id);

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
                            corto_method m;
                            /* If no member is found, lookup method */
                            m = corto_interface_resolveMethod(corto_interface(parent), id);
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

ast_Local _ast_Block_lookupLocal(ast_Block this, corto_string id) {
/* $begin(::corto::ast::Block::lookupLocal) */
    ast_Local result = NULL;

    if (this->locals) {
        corto_iter iter;
        ast_Local local;
        iter = corto_llIter(this->locals);
        while(corto_iterHasNext(&iter)) {
            local = corto_iterNext(&iter);
            if (!strcmp(local->name, id)) {
                result = local;
                break;
            }
        }
    }

    return result;
/* $end */
}

ast_Expression _ast_Block_resolve(ast_Block this, corto_string id) {
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

ast_Local _ast_Block_resolveLocal(ast_Block this, corto_string id) {
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

corto_void _ast_Block_setFunction(ast_Block this, corto_function function) {
/* $begin(::corto::ast::Block::setFunction) */
    corto_setref(&this->function, function);
/* $end */
}

ic_node _ast_Block_toIc_v(ast_Block this, ic_program program, ic_storage storage, corto_bool stored) {
/* $begin(::corto::ast::Block::toIc) */
    ic_scope scope;
    CORTO_UNUSED(storage);
    CORTO_UNUSED(stored);
    
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

ic_node _ast_Block_toIcBody_v(ast_Block this, ic_program program, ic_storage storage, corto_bool stored) {
/* $begin(::corto::ast::Block::toIcBody) */
    ast_Node statement;
    corto_iter statementIter;
    corto_iter localIter;
    ast_Local local;
    CORTO_UNUSED(storage);
    CORTO_UNUSED(stored);
    
    /* Declare locals */
    if (this->locals) {
        localIter = corto_llIter(this->locals);
        while(corto_iterHasNext(&localIter)) {
            local = corto_iterNext(&localIter);
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
        statementIter = corto_llIter(this->statements);
        while(corto_iterHasNext(&statementIter)) {
            statement = corto_iterNext(&statementIter);
            ast_Node_toIc(statement, program, NULL, FALSE);
        }
    }

    return NULL;
/* $end */
}
