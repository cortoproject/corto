/* Fast_CallBuilder.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "Fast.h"

/* $header() */
#include "Fast__private.h"

Fast_Call Fast_CallBuilder_buildMethod(Fast_CallBuilder *_this) {
    Fast_Call result = NULL;
    cx_member m;
    cx_function f;
    cx_type t = Fast_Expression_getType(_this->instance);

    /* First try to resolve a member with a delegate type */
    if (t->kind == CX_COMPOSITE) {
        m = cx_interface_resolveMember(cx_interface(t), _this->name);
        if (m) {
            Fast_String nameExpr = Fast_String__create(_this->name);
            Fast_Parser_collect(yparser(), nameExpr);
            if ((m->type->kind == CX_COMPOSITE) && (cx_interface(m->type)->kind == CX_DELEGATE)) {
                Fast_Expression fExpr = Fast_Expression(Fast_Member__create(_this->instance, Fast_Expression(nameExpr)));
                if (!fExpr) {
                    goto error;
                }
                result = Fast_Call(Fast_DelegateCall__create(NULL, _this->arguments, fExpr));
            }
        }
    }

    /* Resolve procedure in interface */
    if (!result) {
        f = cx_function(cx_type_resolveProcedure(t, _this->signature));
        if (!f) {
            if (!result) {
                cx_id id;
                Fast_Parser_error(yparser(), "no procedure with signature '%s' found in type '%s'",
                    _this->signature,
                    Fast_Parser_id(t, id));
                goto error;
            }
        }

        /* If function is a metaprocedure, validate whether the instance pointer should be a refernce */
        if (cx_procedure(cx_typeof(f))->kind == CX_METAPROCEDURE) {
            if (cx_metaprocedure(f)->referenceOnly && !_this->instance->isReference) {
                Fast_Parser_error(yparser(), "can only call metaprocedures and methods on instances");
                goto error;
            }
        }

        /* Create call-expression */
        result = Fast_Call(Fast_StaticCall__create(_this->instance, _this->arguments, f));
    }

    return result;
error:
    return NULL;
}

/* $end */

/* ::cortex::Fast::CallBuilder::build() */
Fast_Call _Fast_CallBuilder_build(Fast_CallBuilder *_this) {
/* $begin(::cortex::Fast::CallBuilder::build) */
    Fast_Call result = NULL;

    /* Obtain signature */
    if (Fast_CallBuilder_buildSignature(_this)) {
        goto error;
    }

    /* If instance is explicitly set call must be a named callable (method, metaprocedure) */
    if (_this->instance) {
        result = Fast_CallBuilder_buildMethod(_this);
    } else {
        /* If block is set, test for callable variables */
        if (_this->block) {
            Fast_Local l = Fast_Block_resolveLocal(_this->block, _this->name);
            if (l) {
                /* Check if l is of a delegate type */
                if ((l->type->kind == CX_COMPOSITE) && (cx_interface(l->type)->kind == CX_DELEGATE)) {
                    result = Fast_Call(Fast_DelegateCall__create(NULL, _this->arguments, Fast_Expression(l)));
                    if (!result) {
                        goto error;
                    }
                }

            /* If no local is found and block has this-local, try the corresponding interface */
            } else if ((l = Fast_Block_resolveLocal(_this->block, "this"))) {
                if (cx_type_resolveProcedure(l->type, _this->signature)) {
                    /* Set instance to 'this' */
                    cx_setref(&_this->instance, l);
                    result = Fast_CallBuilder_buildMethod(_this);
                }           
            }
        }

        /* If function is not found (implicitly) in interface or in block, look in scope */
        if (!result) {
            cx_object f = cx_resolve(_this->scope, _this->signature);
            if (!f) {
                cx_id id;
                Fast_Parser_error(yparser(), "no procedure found with signature '%s' in scope '%s'", 
                    _this->signature,
                    Fast_Parser_id(_this->scope, id));
                goto error;
            }
            if ((cx_typeof(f)->kind == CX_COMPOSITE) && (cx_interface(cx_typeof(f))->kind == CX_DELEGATE)) {
                Fast_Expression fExpr = Fast_Expression(Fast_Object__create(f));
                result = Fast_Call(Fast_DelegateCall__create(NULL, _this->arguments, fExpr));   
            } else {
                if (cx_function(f)->overloaded) {
                    /* If function is overloaded, re-resolve with explicit reference requests in signature */
                    _this->overloaded = TRUE;
                    if (Fast_CallBuilder_buildSignature(_this)) {
                        goto error;
                    }
                    cx_release(f);
                    f = cx_resolve(_this->scope, _this->signature);
                }
                result = Fast_Call(Fast_StaticCall__create(NULL, _this->arguments, f));
            }  
        }
    }

    return result;
error:
    return NULL;
/* $end */
}

/* ::cortex::Fast::CallBuilder::buildSignature() */
cx_int16 _Fast_CallBuilder_buildSignature(Fast_CallBuilder *_this) {
/* $begin(::cortex::Fast::CallBuilder::buildSignature) */
    cx_string signature;
    cx_iter argumentIter;
    Fast_Expression argument;
    cx_type argumentType;

    if (!strchr(_this->name, '(')) {
        /* Build request-signature */
        signature = cx_signatureOpen(_this->name);

        if (_this->arguments) {
            cx_ll arguments = Fast_Expression_toList(_this->arguments);
            argumentIter = cx_llIter(arguments);
            while(cx_iterHasNext(&argumentIter)) {
                int flags = 0;
                argument = cx_iterNext(&argumentIter);
                argumentType = Fast_Expression_narrowType(argument);

                /* If there is no type and the argument is an initializer, insert a wildcard */
                if (!argumentType && (Fast_Node(argument)->kind == Fast_InitializerExpr)) {
                    flags |= CX_PARAMETER_WILDCARD;
                }
                flags |= argument->isReference ? CX_PARAMETER_REFERENCE : 0;
                flags |= (argument->deref == Fast_ByReference) ? CX_PARAMETER_FORCEREFERENCE : 0;
                signature = cx_signatureAdd(signature, cx_type(argumentType), flags);
            }
            Fast_Expression_cleanList(arguments);
        }

        /* Store signature for when a method needs to be resolved at runtime */
        _this->signature = cx_signatureClose(signature);
    } else {
        _this->signature = cx_strdup(_this->name);
    }

    return 0;
/* $end */
}
