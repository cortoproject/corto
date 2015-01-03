/* Fast_DynamicInitializer.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "Fast.h"
#include "Fast__meta.h"

/* $header() */
#include "Fast__api.h"
#include "Fast_Parser.h"
#include "Fast_Expression.h"

Fast_Parser yparser(void);
void Fast_Parser_error(Fast_Parser _this, char* fmt, ...);
void Fast_Parser_warning(Fast_Parser _this, char* fmt, ...);

cx_int16 Fast_Initializer_assign(Fast_DynamicInitializer _this, Fast_Expression lvalue, Fast_Expression rvalue) {
    CX_UNUSED(_this);
    if (rvalue) {
        Fast_BinaryExpr expr = Fast_BinaryExpr__create(lvalue, rvalue, CX_ASSIGN);
        Fast_Parser_addStatement(yparser(), Fast_Node(expr));
        Fast_Parser_collect(yparser(), expr);
    }
    return 0;
}

/* Assign or add value to expression */
Fast_Expression Fast_Initializer_expr(Fast_DynamicInitializer _this, cx_uint8 variable, Fast_Expression v) {
    Fast_Expression result, base;
    cx_uint16 fp = Fast_Initializer(_this)->fp;
    Fast_InitializerFrame *frame = &Fast_Initializer(_this)->frames[fp?fp-1:0];
    Fast_DynamicInitializerFrame *baseFrame = &(_this->frames[fp?fp-1:0]);
    Fast_InitializerFrame *thisFrame = &Fast_Initializer(_this)->frames[fp];
    
    result = 0;
    
    base = baseFrame->expr[variable];
    if (!base) {
        Fast_Parser_error(yparser(), "parser error: base is zero in offset calculation");
        goto error;
    }
    
    /* Switch on current type */
    switch(frame->type->kind) {
        case CX_PRIMITIVE:
            result = base;
            break;
        case CX_COMPOSITE:
            if (fp) {
                Fast_String memberString = Fast_String__create(cx_nameof(thisFrame->member));
                result = Fast_Expression(Fast_MemberExpr__create(base, Fast_Expression(memberString)));
                Fast_Parser_collect(yparser(), result);
                Fast_Parser_collect(yparser(), memberString);
            } else {
                result = base;
            }
            Fast_Initializer_assign(_this, result, v);
            break;
        case CX_COLLECTION: {
            if (fp) {
                switch(cx_collection(frame->type)->kind) {
                case CX_LIST: {
                    Fast_Node statement;
                    if (!(statement = Fast_Node(Fast_createCall(base, "append", 1, v)))) {
                        goto error;
                    }
                    Fast_Parser_addStatement(yparser(), statement);
                }
                case CX_SEQUENCE:
                case CX_ARRAY: {
                    Fast_Integer index = Fast_Integer__create(thisFrame->location);
                    result = Fast_Expression(Fast_ElementExpr__create(base, Fast_Expression(index)));
                    Fast_Parser_collect(yparser(), result);
                    Fast_Parser_collect(yparser(), index);
                    if (cx_collection(frame->type)->kind != CX_LIST) {
                        Fast_Initializer_assign(_this, result, v);
                    }
                    break;
                }
                case CX_MAP:
                    if (!thisFrame->isKey) {
                        result = Fast_Expression(Fast_ElementExpr__create(base, Fast_Expression(_this->frames[fp].keyExpr[variable])));
                        Fast_Parser_collect(yparser(), result);
                        thisFrame->isKey = FALSE;
                        Fast_Initializer_assign(_this, result, v);
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
                cx_id id;
                Fast_Parser_error(yparser(), "invalid initializer type '%s'", cx_fullname(frame->type, id));
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

/* callback ::cortex::lang::class::construct(lang::object object) -> ::cortex::Fast::DynamicInitializer::construct(DynamicInitializer object) */
cx_int16 Fast_DynamicInitializer_construct(Fast_DynamicInitializer object) {
/* $begin(::cortex::Fast::DynamicInitializer::construct) */
    cx_int8 variable;
    
    /* Copy offsets of variables into frames */
    for(variable=0; variable<Fast_Initializer(object)->variableCount; variable++) {
        Fast_Expression var = Fast_Initializer(object)->variables[variable].object;
        cx_set_ext(object, &object->frames[0].expr[variable], var, ".frames[0].expr[variable]");
    }
    
    return Fast_Initializer_construct(Fast_Initializer(object));
/* $end */
}

/* ::cortex::Fast::DynamicInitializer::define() */
cx_int16 Fast_DynamicInitializer_define(Fast_DynamicInitializer _this) {
/* $begin(::cortex::Fast::DynamicInitializer::define) */
    cx_int8 variable;
    cx_type t = Fast_Initializer_type(Fast_Initializer(_this));
    
    /* Copy offsets of variables into frames */
    if (!_this->assignValue && (t->kind == CX_COMPOSITE)) {
        for(variable=0; variable<Fast_Initializer(_this)->variableCount; variable++) {
            Fast_Define defineExpr = Fast_Define__create(_this->frames[0].expr[variable]);
            Fast_Parser_addStatement(yparser(), Fast_Node(defineExpr));
            Fast_Parser_collect(yparser(), defineExpr);
        }
        Fast_Initializer_define_v(Fast_Initializer(_this));
    }

    return 0;
/* $end */
}

/* ::cortex::Fast::DynamicInitializer::pop() */
cx_int16 Fast_DynamicInitializer_pop(Fast_DynamicInitializer _this) {
/* $begin(::cortex::Fast::DynamicInitializer::pop) */
    cx_uint8 fp = Fast_Initializer(_this)->fp;

    if (_this->frames[fp-1].sequenceSize) {
        Fast_Integer(_this->frames[fp-1].sequenceSize)->value = Fast_Initializer(_this)->frames[fp].location;
    }

    return Fast_Initializer_pop_v(Fast_Initializer(_this));
/* $end */
}

/* ::cortex::Fast::DynamicInitializer::push() */
cx_int16 Fast_DynamicInitializer_push(Fast_DynamicInitializer _this) {
/* $begin(::cortex::Fast::DynamicInitializer::push) */
    cx_uint8 variable;
    cx_type t = Fast_Initializer_currentType(Fast_Initializer(_this));
    cx_uint8 fp = Fast_Initializer(_this)->fp;
    Fast_Node expr = Fast_Node(_this->frames[fp].expr[0]);
    cx_bool isAnonymousLocal = expr && 
        (expr->kind == FAST_Variable) && (Fast_Variable(expr)->kind == FAST_Local) && (*Fast_Local(expr)->name == '<');
    
    /* Check if push is allowed */
    if (!(!fp && _this->assignValue) && (t->reference && !isAnonymousLocal)) {
        cx_id id;
        Fast_Parser_error(yparser(), "unexpected initializer scope for value of referencetype '%s'", cx_fullname(t, id));
        goto error;
    }

    /* Obtain expression for all variables being initialized */
    for(variable=0; variable<Fast_Initializer(_this)->variableCount; variable++) {
        cx_set_ext(_this, &_this->frames[fp].expr[variable], Fast_Initializer_expr(_this, variable, NULL), ".frames[fp].expr[variable]");
    }

    if (Fast_Initializer_push_v(Fast_Initializer(_this))) {
        goto error;
    }
    
    /* If scope contains contents of a sequence insert operation to set sequence-size. Because size is not known beforehand,
     * cache the expression that contains the size. This will be set to it's final value when sequence-scope is pop'd. */
    if ((t->kind == CX_COLLECTION) && (cx_collection(t)->kind == CX_SEQUENCE)) {
        Fast_Integer size = Fast_Integer__create(0);
        Fast_Parser_collect(yparser(), size);
        
        /* Cast the size to uint32 so that the expression won't be replaced by a cast when it is inserted in the argumentlist
        * of sequence::size(uint32). This way there is no need for keeping track of a size-expression per variable. Note: the
        * native type of a Fast::Integer is uint64. */
        size = Fast_Integer(Fast_Expression_cast(Fast_Expression(size), cx_type(cx_uint32_o), FALSE));
        cx_set_ext(_this, &_this->frames[fp].sequenceSize, size, ".frames[fp].sequenceSize");
        
        for(variable=0; variable<Fast_Initializer(_this)->variableCount; variable++) {
            Fast_Node statement;
            if(!(statement = Fast_Node(Fast_createCall(_this->frames[fp].expr[variable], "size", 1, Fast_Expression(size))))) {
                goto error;
            }
            Fast_Parser_addStatement(yparser(), statement);
        }
    } else if ((t->kind == CX_COLLECTION) && (cx_collection(t)->kind == CX_LIST)) {
        if (_this->assignValue) {
            /* If assigning a complex value to a list, clear list first */
            for(variable=0; variable<Fast_Initializer(_this)->variableCount; variable++) {
                Fast_Node statement;
                if (!(statement = Fast_Node(Fast_createCall(_this->frames[fp].expr[variable], "clear", 0)))) {
                    goto error;
                }
                Fast_Parser_addStatement(yparser(), statement);
            }
        }
    } else {
        cx_set_ext(_this, &_this->frames[fp].sequenceSize, NULL, ".frames[fp].sequenceSize");
    }
    
    return 0;
error:
    return -1;
/* $end */
}

/* ::cortex::Fast::DynamicInitializer::value(Expression v) */
cx_int16 Fast_DynamicInitializer_value(Fast_DynamicInitializer _this, Fast_Expression v) {
/* $begin(::cortex::Fast::DynamicInitializer::value) */
    cx_uint32 variable;
    cx_uint32 fp = Fast_Initializer(_this)->fp;
    cx_type type = Fast_Initializer_currentType(Fast_Initializer(_this));
    
    if (!type) {
        cx_id id;
        Fast_Parser_error(yparser(), "excess elements in initializer of type '%s'",
            cx_fullname(Fast_ObjectBase(Fast_Expression(_this)->type)->value, id));
        goto error;
    }

    /* Validate whether expression type matches current type of initializer */
    if (!cx_type_compatible(type, Fast_Expression_getType_type(v, type))) {
        cx_id id, id2;
        Fast_Parser_error(yparser(), "type '%s' invalid here (expected '%s')", 
            cx_fullname(Fast_Expression_getType(v), id), cx_fullname(type, id2));
        goto error;
    }
    
    /* Serialize value to all variables being initialized */
    for(variable=0; variable<Fast_Initializer(_this)->variableCount; variable++) {
        if (Fast_Initializer(_this)->frames[fp].isKey) {
            cx_set(&_this->frames[fp].keyExpr[variable], v);
        } else {
            Fast_Initializer_expr(_this, variable, v);
        }
    }
    
    return Fast_Initializer_next(Fast_Initializer(_this));
error:
    return -1;
/* $end */
}
