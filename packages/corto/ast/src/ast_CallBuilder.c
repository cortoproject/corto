/* ast_CallBuilder.c
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

ast_Call ast_CallBuilder_buildMethod(ast_CallBuilder *this) {
    ast_Call result = NULL;
    cx_member m;
    cx_function f;
    cx_type t = ast_Expression_getType(this->instance);

    /* First try to resolve a member with a delegate type */
    if (t->kind == CX_COMPOSITE) {
        m = cx_interface_resolveMember(cx_interface(t), this->name);
        if (m) {
            ast_String nameExpr = ast_StringCreate(this->name);
            ast_Parser_collect(yparser(), nameExpr);
            if ((m->type->kind == CX_COMPOSITE) && (cx_interface(m->type)->kind == CX_DELEGATE)) {
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
        f = cx_function(cx_type_resolveProcedure(t, this->signature));
        if (!f) {
            if (!result) {
                cx_id id;
                ast_Parser_error(yparser(), "no procedure with signature '%s' found in type '%s'",
                    this->signature,
                    ast_Parser_id(t, id));
                goto error;
            }
        }

        /* If function is a metaprocedure, validate whether the instance pointer should be a refernce */
        if (cx_procedure(cx_typeof(f))->kind == CX_METAPROCEDURE) {
            if (cx_metaprocedure(f)->referenceOnly && !this->instance->isReference) {
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

/* ::corto::ast::CallBuilder::build() */
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
                if ((l->type->kind == CX_COMPOSITE) && (cx_interface(l->type)->kind == CX_DELEGATE)) {
                    result = ast_Call(ast_DelegateCallCreate(NULL, this->arguments, ast_Expression(l)));
                    if (!result) {
                        goto error;
                    }
                }

            /* If no local is found and block has this-local, try the corresponding interface */
            } else if ((l = ast_Block_resolveLocal(this->block, "this"))) {
                if (cx_type_resolveProcedure(l->type, this->signature)) {
                    /* Set instance to 'this' */
                    cx_setref(&this->instance, l);
                    result = ast_CallBuilder_buildMethod(this);
                }           
            }
        }

        /* If function is not found (implicitly) in interface or in block, look in scope */
        if (!result) {
            cx_object f = cx_resolve(this->scope, this->signature);
            if (!f) {
                cx_id id;
                ast_Parser_error(yparser(), "no procedure found with signature '%s' in scope '%s'", 
                    this->signature,
                    ast_Parser_id(this->scope, id));
                goto error;
            }
            if ((cx_typeof(f)->kind == CX_COMPOSITE) && (cx_interface(cx_typeof(f))->kind == CX_DELEGATE)) {
                ast_Expression fExpr = ast_Expression(ast_ObjectCreate(f));
                result = ast_Call(ast_DelegateCallCreate(NULL, this->arguments, fExpr));   
            } else {
                if (cx_function(f)->overloaded) {
                    /* If function is overloaded, re-resolve with explicit reference requests in signature */
                    this->overloaded = TRUE;
                    if (ast_CallBuilder_buildSignature(this)) {
                        goto error;
                    }
                    cx_release(f);
                    f = cx_resolve(this->scope, this->signature);
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

/* ::corto::ast::CallBuilder::buildSignature() */
cx_int16 _ast_CallBuilder_buildSignature(ast_CallBuilder *this) {
/* $begin(::corto::ast::CallBuilder::buildSignature) */
    cx_string signature;
    cx_iter argumentIter;
    ast_Expression argument;
    cx_type argumentType;

    if (!strchr(this->name, '(')) {
        /* Build request-signature */
        signature = cx_signatureOpen(this->name);

        if (this->arguments) {
            cx_ll arguments = ast_Expression_toList(this->arguments);
            argumentIter = cx_llIter(arguments);
            while(cx_iterHasNext(&argumentIter)) {
                int flags = 0;
                argument = cx_iterNext(&argumentIter);
                argumentType = ast_Expression_narrowType(argument);

                /* If there is no type and the argument is an initializer, insert a wildcard */
                if (!argumentType && (ast_Node(argument)->kind == Ast_InitializerExpr)) {
                    flags |= CX_PARAMETER_WILDCARD;
                }
                flags |= argument->isReference ? CX_PARAMETER_REFERENCE : 0;
                flags |= (argument->deref == Ast_ByReference) ? CX_PARAMETER_FORCEREFERENCE : 0;
                signature = cx_signatureAdd(signature, cx_type(argumentType), flags);
            }
            ast_Expression_cleanList(arguments);
        }

        /* Store signature for when a method needs to be resolved at runtime */
        this->signature = cx_signatureClose(signature);
    } else {
        this->signature = cx_strdup(this->name);
    }

    return 0;
/* $end */
}
