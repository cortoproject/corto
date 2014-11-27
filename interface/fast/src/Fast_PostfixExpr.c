/* Fast_PostfixExpr.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "Fast_PostfixExpr.h"
#include "Fast__meta.h"


/* $header() */
#include "Fast__api.h"
#include "Fast.h"
#include "Fast_Parser.h"
Fast_Parser yparser(void);
void Fast_Parser_error(Fast_Parser _this, char* fmt, ...);
/* $end */

/* callback ::hyve::lang::class::construct(lang::object object) -> ::hyve::Fast::PostfixExpr::construct(Fast::PostfixExpr object) */
db_int16 Fast_PostfixExpr_construct(Fast_PostfixExpr object) {
/* $begin(::hyve::Fast::PostfixExpr::construct) */
	db_type lvalueType;

    Fast_Node(object)->kind = FAST_Postfix;
    lvalueType = Fast_Expression_getType(object->lvalue);
    Fast_Expression(object)->type = Fast_Variable(Fast_Object__create(lvalueType));

    return 0;
/* $end */
}

/* ::hyve::Fast::PostfixExpr::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_PostfixExpr_toIc_v(Fast_PostfixExpr _this, db_icProgram program, db_icStorage storage, db_bool stored) {
/* $begin(::hyve::Fast::PostfixExpr::toIc) */
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

    op = db_icOp__create(program, Fast_Node(_this)->line, db_icOpKindFromOperator(_this->operator), (db_icValue)lvalue, NULL, NULL);
    db_icProgram_addIc(program, (db_ic)op);

    if (!storage) {
    	db_icProgram_accumulatorPop(program, Fast_Node(_this)->line);
    }

    return (db_ic)lvalue;
/* $end */
}
