/* $CORTO_GENERATED
 *
 * ast_CallBuilder.c
 *
 * Code written between the begin and end tags will be preserved when the
 * file is regenerated.
 */

#include "ast.h"

/* $header() */
#include "ast__private.h"

ast_Call ast_CallBuilder_buildMethod(ast_CallBuilder *this) {
    ast_Call result = NULL;
    corto_member m;
    corto_function f;
    corto_type t = ast_Expression_getType(this->instance);

    /* First try to resolve a member with a delegate type */
    if (t->kind == CORTO_COMPOSITE) {
        m = corto_interface_resolveMember(corto_interface(t), this->name);
        if (m) {
            ast_String nameExpr = ast_StringCreate(this->name);
            ast_Parser_collect(yparser(), nameExpr);
            if ((m->type->kind == CORTO_COMPOSITE) && (corto_interface(m->type)->kind == CORTO_DELEGATE)) {
                ast_Expression fExpr = ast_Expression(ast_MemberCreate(this->instance, ast_Expression(nameExpr)));
                if (!fExpr) {
                    goto error;
                }
                result = ast_Call(ast_DelegateCallCreate(NULL, this->arguments, fExpr));
            }
        }
    }

    /* Resolve procedure in interface */
    if (!result) {
        f = corto_function(corto_type_resolveProcedure(t, this->signature));
        if (!f) {
            if (!result) {
                corto_id id;
                ast_Parser_error(yparser(), "no procedure with signature '%s' found in type '%s'",
                    this->signature,
                    ast_Parser_id(t, id));
                goto error;
            }
        }

        /* If function is a metaprocedure, validate whether the instance pointer should be a refernce */
        if (corto_procedure(corto_typeof(f))->kind == CORTO_METAPROCEDURE) {
            if (corto_metaprocedure(f)->referenceOnly && !this->instance->isReference) {
                ast_Parser_error(yparser(), "can only call metaprocedures and methods on instances");
                goto error;
            }
        }

        /* Create call-expression */
        result = ast_Call(ast_StaticCallCreate(this->instance, this->arguments, f));
    }

    return result;
error:
    return NULL;
}

/* $end */

ast_Call _ast_CallBuilder_build(ast_CallBuilder *this) {
/* $begin(::corto::ast::CallBuilder::build) */
    ast_Call result = NULL;

    /* Obtain signature */
    if (ast_CallBuilder_buildSignature(this)) {
        goto error;
    }

    /* If instance is explicitly set call must be a named callable (method, metaprocedure) */
    if (this->instance) {
        result = ast_CallBuilder_buildMethod(this);
    } else {
        /* If block is set, test for callable variables */
        if (this->block) {
            ast_Local l = ast_Block_resolveLocal(this->block, this->name);
            if (l) {
                /* Check if l is of a delegate type */
                if ((l->type->kind == CORTO_COMPOSITE) && (corto_interface(l->type)->kind == CORTO_DELEGATE)) {
                    result = ast_Call(ast_DelegateCallCreate(NULL, this->arguments, ast_Expression(l)));
                    if (!result) {
                        goto error;
                    }
                }

            /* If no local is found and block has this-local, try the corresponding interface */
            } else if ((l = ast_Block_resolveLocal(this->block, "this"))) {
                if (corto_type_resolveProcedure(l->type, this->signature)) {
                    /* Set instance to 'this' */
                    corto_setref(&this->instance, l);
                    result = ast_CallBuilder_buildMethod(this);
                }           
            }
        }

        /* If function is not found (implicitly) in interface or in block, look in scope */
        if (!result) {
            corto_object f = corto_resolve(this->scope, this->signature);
            if (!f) {
                corto_id id;
                ast_Parser_error(yparser(), "no procedure found with signature '%s' in scope '%s'", 
                    this->signature,
                    ast_Parser_id(this->scope, id));
                goto error;
            }
            if ((corto_typeof(f)->kind == CORTO_COMPOSITE) && (corto_interface(corto_typeof(f))->kind == CORTO_DELEGATE)) {
                ast_Expression fExpr = ast_Expression(ast_ObjectCreate(f));
                result = ast_Call(ast_DelegateCallCreate(NULL, this->arguments, fExpr));   
            } else {
                if (corto_function(f)->overloaded) {
                    /* If function is overloaded, re-resolve with explicit reference requests in signature */
                    this->overloaded = TRUE;
                    if (ast_CallBuilder_buildSignature(this)) {
                        goto error;
                    }
                    corto_release(f);
                    f = corto_resolve(this->scope, this->signature);
                }
                result = ast_Call(ast_StaticCallCreate(NULL, this->arguments, f));
            }  
        }
    }

    return result;
error:
    return NULL;
/* $end */
}

corto_int16 _ast_CallBuilder_buildSignature(ast_CallBuilder *this) {
/* $begin(::corto::ast::CallBuilder::buildSignature) */
    corto_string signature;
    corto_iter argumentIter;
    ast_Expression argument;
    corto_type argumentType;

    if (!strchr(this->name, '(')) {
        /* Build request-signature */
        signature = corto_signatureOpen(this->name);

        if (this->arguments) {
            corto_ll arguments = ast_Expression_toList(this->arguments);
            argumentIter = corto_llIter(arguments);
            while(corto_iterHasNext(&argumentIter)) {
                int flags = 0;
                argument = corto_iterNext(&argumentIter);
                argumentType = ast_Expression_narrowType(argument);

                /* If there is no type and the argument is an initializer, insert a wildcard */
                if (!argumentType && (ast_Node(argument)->kind == Ast_InitializerExpr)) {
                    flags |= CORTO_PARAMETER_WILDCARD;
                }
                flags |= argument->isReference ? CORTO_PARAMETER_REFERENCE : 0;
                flags |= (argument->deref == Ast_ByReference) ? CORTO_PARAMETER_FORCEREFERENCE : 0;
                signature = corto_signatureAdd(signature, corto_type(argumentType), flags);
            }
            ast_Expression_cleanList(arguments);
        }

        /* Store signature for when a method needs to be resolved at runtime */
        this->signature = corto_signatureClose(signature);
    } else {
        this->signature = corto_strdup(this->name);
    }

    return 0;
/* $end */
}
