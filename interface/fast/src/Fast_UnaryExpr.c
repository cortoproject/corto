/* Fast_UnaryExpr.c
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
Fast_Parser yparser(void);
void Fast_Parser_error(Fast_Parser _this, char* fmt, ...);
/* $end */

/* callback ::hyve::lang::class::construct(lang::object object) -> ::hyve::Fast::UnaryExpr::construct(Fast::UnaryExpr object) */
db_int16 Fast_UnaryExpr_construct(Fast_UnaryExpr object) {
/* $begin(::hyve::Fast::UnaryExpr::construct) */
	db_type lvalueType;

	lvalueType = Fast_Expression_getType(object->lvalue);
    Fast_Node(object)->kind = FAST_Unary;

    if (object->operator == DB_COND_NOT) {
    	Fast_Expression(object)->type = Fast_Variable(Fast_Object__create(db_bool_o));
    } else {
    	Fast_Expression(object)->type = Fast_Variable(Fast_Object__create(lvalueType));
    }

    return 0;
/* $end */
}

/* ::hyve::Fast::UnaryExpr::hasSideEffects() */
db_bool Fast_UnaryExpr_hasSideEffects_v(Fast_UnaryExpr _this) {
/* $begin(::hyve::Fast::UnaryExpr::hasSideEffects) */

    return Fast_Expression_hasSideEffects(_this->lvalue);

/* $end */
}

/* ::hyve::Fast::UnaryExpr::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_UnaryExpr_toIc_v(Fast_UnaryExpr _this, db_icProgram program, db_icStorage storage, db_bool stored) {
/* $begin(::hyve::Fast::UnaryExpr::toIc) */
	db_icStorage result;
	db_ic lvalue;
	db_icOp op;
	DB_UNUSED(stored);

    if (storage) {
    	result = storage;
    } else {
    	result = (db_icStorage)db_icProgram_accumulatorPush(
            program, 
            Fast_Node(_this)->line, 
            Fast_Expression_getType(Fast_Expression(_this)),
            Fast_Expression(_this)->isReference);
    }

    lvalue = Fast_Node_toIc(Fast_Node(_this->lvalue), program, result, TRUE);

    switch(_this->operator) {
    case DB_INC:
    case DB_DEC:
        op = db_icOp__create(program, Fast_Node(_this)->line, db_icOpKindFromOperator(_this->operator), (db_icValue)lvalue, NULL, NULL);
        db_icProgram_addIc(program, (db_ic)op);
        result = (db_icStorage)lvalue;
    	break;
    default:
        op = db_icOp__create(program, Fast_Node(_this)->line, db_icOpKindFromOperator(_this->operator), (db_icValue)result, (db_icValue)lvalue, NULL);
        db_icProgram_addIc(program, (db_ic)op);
    	break;
    }

    if (!storage) {
    	db_icProgram_accumulatorPop(program, Fast_Node(_this)->line);
    }

    return (db_ic)result;
/* $end */
}
