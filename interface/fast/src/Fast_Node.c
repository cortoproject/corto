/* Fast_Node.c
 *
 *  Generated on Nov 18 2014
 *    This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "Fast_Node.h"
#include "Fast__meta.h"


/* $header() */
#include "Fast__api.h"
#include "Fast_Parser.h"
#include "Fast_Expression.h"
Fast_Parser yparser(void);
void Fast_Parser_error(Fast_Parser _this, char* fmt, ...);

/* Optimize condition, check if condition can be evaluated at compile-time or can be unwinded */
Fast_Expression Fast_Node_optimizeCondition(Fast_Expression condition, db_bool *staticResult, db_bool *inverse) {
    Fast_Expression result = NULL;
    Fast_Expression_list conditions = Fast_Expression_toList(condition);
    *inverse = FALSE;
    
    /* If condition is an expression list, inserts && between each expression. */
    Fast_Expression_list__foreach(conditions, elem)

        /* If condition is a unary NOT inverse the condition and evaluate lvalue of NOT expression instead */
        if (Fast_Node(elem)->kind == FAST_Unary) {
            if (Fast_UnaryExpr(elem)->operator == DB_COND_NOT) {
                *inverse = TRUE;
                elem = Fast_UnaryExpr(elem)->lvalue;
            }
        }
      
        /* If condition is a literal, serialize it to a boolean and resolve condition at compile-time */
        if (elem && (Fast_Node(elem)->kind == FAST_Literal)) {
            if (Fast_Expression_serialize(elem, db_type(db_bool_o), (db_word)staticResult)) {
                Fast_Parser_error(yparser(), "failed to serialize literal condition expression");
                goto error;
            }
            if (*inverse) {
                *staticResult = !*staticResult;
            }
            elem = NULL;
        }
    
        if (!result) {
            result = elem;
        } else {
            /* If element, add element to AND expression */
            if (elem) {
                result = Fast_Expression(Fast_BinaryExpr__create(result, elem, DB_COND_AND));
                Fast_Parser_collect(yparser(), result);
                
            /* If element was a literal either ignore it (if result was TRUE) or discard all other
             * expressions if result of literal expression was FALSE. */
            } else if (!*staticResult) {
                result = NULL;
                break;
            }
        }
    }

    Fast_Expression_cleanList(conditions);
    
    return result;
error:
    return NULL;
}

/* $end */

/* callback ::hyve::lang::type::init(lang::object object) -> ::hyve::Fast::Node::init(Node object) */
db_int16 Fast_Node_init(Fast_Node object) {
/* $begin(::hyve::Fast::Node::init) */
    object->line = yparser()->line;
    object->column = yparser()->column;
    return 0;
/* $end */
}

/* virtual ::hyve::Fast::Node::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_Node_toIc(Fast_Node _this, db_icProgram program, db_icStorage storage, db_bool stored) {
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
        _result = ((db_ic(*)(Fast_Node, db_icProgram , db_icStorage , db_bool ))_method->_parent.impl)(_this, program, storage, stored);
    } else {
        /* Function is implemented in another language. */
        db_call(db_function(_method), &_result, _this, program, storage, stored);
    }
    
    return _result;
}

/* ::hyve::Fast::Node::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_Node_toIc_v(Fast_Node _this, db_icProgram program, db_icStorage storage, db_bool stored) {
/* $begin(::hyve::Fast::Node::toIc) */
	DB_UNUSED(_this);
	DB_UNUSED(program);
	DB_UNUSED(storage);
	DB_UNUSED(stored);
	/* No code is generated for statement */
	return NULL;
/* $end */
}
