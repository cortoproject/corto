/* ast_DynamicInitializer.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "ast.h"

/* $header() */
#include "ast__private.h"

corto_int16 ast_Initializer_assign(ast_DynamicInitializer this, ast_Expression lvalue, ast_Expression rvalue) {
    CORTO_UNUSED(this);
    if (rvalue) {
        ast_Binary expr = ast_BinaryCreate(lvalue, rvalue, CORTO_ASSIGN);
        ast_Parser_addStatement(yparser(), ast_Node(expr));
        ast_Parser_collect(yparser(), expr);
    }
    return 0;
}

/* Assign or add value to expression */
ast_Expression ast_Initializer_expr(ast_DynamicInitializer this, corto_uint8 variable, ast_Expression v) {
    ast_Expression result, base;
    corto_uint16 fp = ast_Initializer(this)->fp;
    ast_InitializerFrame *frame = &ast_Initializer(this)->frames[fp?fp-1:0];
    ast_DynamicInitializerFrame *baseFrame = &(this->frames[fp?fp-1:0]);
    ast_InitializerFrame *thisFrame = &ast_Initializer(this)->frames[fp];
    
    result = 0;
    
    base = baseFrame->expr[variable];
    if (!base) {
        ast_Parser_error(yparser(), "parser error: base is zero in offset calculation");
        goto error;
    }
    
    /* Switch on current type */
    switch(frame->type->kind) {
        case CORTO_PRIMITIVE:
            result = base;
            ast_Initializer_assign(this, result, v);
            break;
        case CORTO_ITERATOR:
            result = base;
            break;
        case CORTO_COMPOSITE:
            if (fp) {
                ast_String memberString = ast_StringCreate(corto_nameof(thisFrame->member));
                result = ast_Expression(ast_MemberCreate(base, ast_Expression(memberString)));
                ast_Parser_collect(yparser(), result);
                ast_Parser_collect(yparser(), memberString);
            } else {
                result = base;
            }
            ast_Initializer_assign(this, result, v);
            break;
        case CORTO_COLLECTION: {
            if (fp) {
                switch(corto_collection(frame->type)->kind) {
                case CORTO_LIST: {
                    ast_Node statement;
                    if (!(statement = ast_Node(ast_createCall(base, "append", 1, v)))) {
                        goto error;
                    }
                    ast_Parser_addStatement(yparser(), statement);
                }
                case CORTO_SEQUENCE:
                case CORTO_ARRAY: {
                    ast_Integer index = ast_IntegerCreate(thisFrame->location);
                    result = ast_Expression(ast_ElementCreate(base, ast_Expression(index)));
                    ast_Parser_collect(yparser(), result);
                    ast_Parser_collect(yparser(), index);
                    if (corto_collection(frame->type)->kind != CORTO_LIST) {
                        ast_Initializer_assign(this, result, v);
                    }
                    break;
                }
                case CORTO_MAP:
                    if (!thisFrame->isKey) {
                        result = ast_Expression(ast_ElementCreate(base, ast_Expression(this->frames[fp].keyExpr[variable])));
                        ast_Parser_collect(yparser(), result);
                        thisFrame->isKey = FALSE;
                        ast_Initializer_assign(this, result, v);
                    }
                    break;
                }
            } else {
                result = base;
            }
            break;
        }
        default: {
            if (frame->type->reference) {
                result = base;
            } else {
                corto_id id;
                ast_Parser_error(yparser(), "invalid initializer type '%s'", ast_Parser_id(frame->type, id));
                abort();
            }
            break;
        }
    }
    
    return result;
error:
    return 0;

}

/* $end */

/* ::corto::ast::DynamicInitializer::construct() */
corto_int16 _ast_DynamicInitializer_construct(ast_DynamicInitializer this) {
/* $begin(::corto::ast::DynamicInitializer::construct) */
    corto_int8 variable;
    
    /* Copy offsets of variables into frames */
    for(variable=0; variable<ast_Initializer(this)->variableCount; variable++) {
        ast_Expression var = ast_Initializer(this)->variables[variable].object;
        corto_setref(&this->frames[0].expr[variable], var);
    }
    
    return ast_Initializer_construct(ast_Initializer(this));
/* $end */
}

/* ::corto::ast::DynamicInitializer::define() */
corto_int16 _ast_DynamicInitializer_define(ast_DynamicInitializer this) {
/* $begin(::corto::ast::DynamicInitializer::define) */
    corto_int8 variable;
    
    /* Insert define operations */
    if (!this->assignValue) {
        for(variable=0; variable<ast_Initializer(this)->variableCount; variable++) {
            ast_Define defineExpr = ast_DefineCreate(this->frames[0].expr[variable]);
            ast_Parser_addStatement(yparser(), ast_Node(defineExpr));
            ast_Parser_collect(yparser(), defineExpr);
        }
        ast_Initializer_define_v(ast_Initializer(this));
    }

    return 0;
/* $end */
}

/* ::corto::ast::DynamicInitializer::hasReturnedResource() */
corto_bool _ast_DynamicInitializer_hasReturnedResource_v(ast_DynamicInitializer this) {
/* $begin(::corto::ast::DynamicInitializer::hasReturnedResource) */
    CORTO_UNUSED(this);
    return FALSE;
/* $end */
}

/* ::corto::ast::DynamicInitializer::pop() */
corto_int16 _ast_DynamicInitializer_pop(ast_DynamicInitializer this) {
/* $begin(::corto::ast::DynamicInitializer::pop) */
    corto_uint8 fp = ast_Initializer(this)->fp;

    if (this->frames[fp-1].sequenceSize) {
        ast_Integer(this->frames[fp-1].sequenceSize)->value = ast_Initializer(this)->frames[fp].location;
    }

    return ast_Initializer_pop_v(ast_Initializer(this));
/* $end */
}

/* ::corto::ast::DynamicInitializer::push() */
corto_int16 _ast_DynamicInitializer_push(ast_DynamicInitializer this) {
/* $begin(::corto::ast::DynamicInitializer::push) */
    corto_uint8 variable;
    corto_type t = ast_Initializer_currentType(ast_Initializer(this));
    corto_uint8 fp = ast_Initializer(this)->fp;
    ast_Node expr = ast_Node(this->frames[fp].expr[0]);
    corto_bool isAnonymousLocal = expr && 
        (expr->kind == Ast_StorageExpr) && (ast_Storage(expr)->kind == Ast_TemporaryStorage);
    
    /* Check if push is allowed */
    if (!(!fp && this->assignValue) && (t->reference && !isAnonymousLocal)) {
        corto_id id;
        ast_Parser_error(yparser(), "unexpected initializer scope for value of referencetype '%s'", ast_Parser_id(t, id));
        goto error;
    }

    /* Obtain expression for all variables being initialized */
    for(variable=0; variable<ast_Initializer(this)->variableCount; variable++) {
        corto_setref(&this->frames[fp].expr[variable], ast_Initializer_expr(this, variable, NULL));
    }

    if (ast_Initializer_push_v(ast_Initializer(this))) {
        goto error;
    }
    
    /* If scope contains contents of a sequence insert operation to set sequence-size. Because size is not known beforehand,
     * cache the expression that contains the size. This will be set to it's final value when sequence-scope is pop'd. */
    if ((t->kind == CORTO_COLLECTION) && (corto_collection(t)->kind == CORTO_SEQUENCE)) {
        ast_Integer size = ast_IntegerCreate(0);
        ast_Parser_collect(yparser(), size);
        
        /* Cast the size to uint32 so that the expression won't be replaced by a cast when it is inserted in the argumentlist
        * of sequence::size(uint32). This way there is no need for keeping track of a size-expression per variable. Note: the
        * native type of a ast::Integer is uint64. */
        size = ast_Integer(ast_Expression_cast(ast_Expression(size), corto_type(corto_uint32_o), FALSE));
        corto_setref(&this->frames[fp].sequenceSize, size);
        
        for(variable=0; variable<ast_Initializer(this)->variableCount; variable++) {
            ast_Node statement;
            if(!(statement = ast_Node(ast_createCall(this->frames[fp].expr[variable], "size", 1, ast_Expression(size))))) {
                goto error;
            }
            ast_Parser_addStatement(yparser(), statement);
        }
    } else if ((t->kind == CORTO_COLLECTION) && (corto_collection(t)->kind == CORTO_LIST)) {
        if (this->assignValue) {
            /* If assigning a complex value to a list, clear list first */
            for(variable=0; variable<ast_Initializer(this)->variableCount; variable++) {
                ast_Node statement;
                if (!(statement = ast_Node(ast_createCall(this->frames[fp].expr[variable], "clear", 0)))) {
                    goto error;
                }
                ast_Parser_addStatement(yparser(), statement);
            }
        }
    } else {
        corto_setref(&this->frames[fp].sequenceSize, NULL);
    }
    
    return 0;
error:
    return -1;
/* $end */
}

/* ::corto::ast::DynamicInitializer::value(Expression v) */
corto_int16 _ast_DynamicInitializer_value(ast_DynamicInitializer this, ast_Expression v) {
/* $begin(::corto::ast::DynamicInitializer::value) */
    corto_uint32 variable;
    corto_uint32 fp = ast_Initializer(this)->fp;
    corto_type type = ast_Initializer_currentType(ast_Initializer(this));
    
    if (!type) {
        corto_id id;
        ast_Parser_error(yparser(), "excess elements in initializer of type '%s'",
            ast_Parser_id(ast_Object(ast_Expression(this)->type)->value, id));
        goto error;
    }

    /* Validate whether expression type matches current type of initializer */
    if (!corto_type_compatible(type, ast_Expression_getType_type(v, type))) {
        corto_id id, id2;
        ast_Parser_error(yparser(), "type '%s' invalid here (expected '%s')", 
            ast_Parser_id(ast_Expression_getType(v), id), ast_Parser_id(type, id2));
        goto error;
    }
    
    /* Serialize value to all variables being initialized */
    for(variable=0; variable<ast_Initializer(this)->variableCount; variable++) {
        if (ast_Initializer(this)->frames[fp].isKey) {
            corto_setref(&this->frames[fp].keyExpr[variable], v);
        } else {
            ast_Initializer_expr(this, variable, v);
        }
    }
    
    return ast_Initializer_next(ast_Initializer(this));
error:
    return -1;
/* $end */
}
