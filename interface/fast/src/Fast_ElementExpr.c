/* Fast_ElementExpr.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "Fast.h"
#include "Fast__meta.h"

/* $header() */
#include "db_type.h"
#include "Fast__api.h"
#include "Fast_Parser.h"
Fast_Parser yparser(void);
void Fast_Parser_error(Fast_Parser _this, char* fmt, ...);
/* $end */

/* callback ::cortex::lang::class::construct(lang::object object) -> ::cortex::Fast::ElementExpr::construct(Fast::MemberExpr object) */
db_int16 Fast_ElementExpr_construct(Fast_MemberExpr object) {
/* $begin(::cortex::Fast::ElementExpr::construct) */
	db_type lvalueType, rvalueType;

	Fast_Node(object)->kind = FAST_Element;

	lvalueType = Fast_Expression_getType(object->lvalue);

	if (lvalueType) {
    	if (lvalueType->kind == DB_COLLECTION) {
    		rvalueType = Fast_Expression_getType(object->rvalue);
    		if (rvalueType) {
    			if (db_collection(lvalueType)->kind != DB_MAP) {
					if (!db_type_castable(db_type(db_uint32_o), rvalueType)) {
						db_id id;
						Fast_Parser_error(yparser(), "expected integer expression for index, got '%s'", db_fullname(rvalueType, id));
						goto error;
					}
    			} else {
					if (!db_type_castable(db_map(lvalueType)->keyType->real, rvalueType)) {
						db_id id, id2;
						Fast_Parser_error(yparser(), "expected expression of type '%s' for key, got '%s'",
								db_fullname(db_map(lvalueType)->keyType->real, id), db_fullname(rvalueType, id2));
						goto error;
					}
    			}
    		}
    	    /* Set type of expression */
    		Fast_Expression(object)->type = Fast_Variable(Fast_Object__create(db_collection(lvalueType)->elementType->real));
    	} else {
    		db_id id;
    		Fast_Parser_error(yparser(), "cannot obtain element from object of non-collection type '%s'", db_fullname(lvalueType, id));
    		goto error;
    	}
    } else {
    	Fast_Parser_error(yparser(), "dynamic expressions are not yet supported");
    	goto error;
    }
    
    if (Fast_Expression_getType(Fast_Expression(object))->reference) {
    	Fast_Expression(object)->forceReference = TRUE;
        Fast_Expression(object)->isReference = TRUE;
    }

    return 0;
error:
	return -1;
/* $end */
}

/* ::cortex::Fast::ElementExpr::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_ElementExpr_toIc_v(Fast_ElementExpr _this, db_icProgram program, db_icStorage storage, db_bool stored) {
/* $begin(::cortex::Fast::ElementExpr::toIc) */
	db_icElement result;
	db_ic lvalue, rvalue;
	DB_UNUSED(stored);
	DB_UNUSED(storage);

	/* Get lvalue & rvalue */
	lvalue = Fast_Node_toIc(Fast_Node(_this->lvalue), program, NULL, TRUE);
	rvalue = Fast_Node_toIc(Fast_Node(_this->rvalue), program, NULL, TRUE);

	result = db_icElement__create(program, Fast_Node(_this)->line, Fast_Expression_getType(Fast_Expression(_this)), (db_icStorage)lvalue, (db_icValue)rvalue);

	return (db_ic)result;
/* $end */
}
