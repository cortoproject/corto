/* Fast_TernaryExpr.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "Fast_TernaryExpr.h"
#include "Fast__meta.h"


/* $header() */
#include "Fast__api.h"
#include "Fast_Block.h"
#include "Fast_Parser.h"
#include "Fast_If.h"
#include "Fast_BinaryExpr.h"

Fast_Parser yparser(void);
void Fast_Parser_error(Fast_Parser _this, char* fmt, ...);
void Fast_Parser_warning(Fast_Parser _this, char* fmt, ...);

/* Create if statement based on ternary operator expressions */
Fast_If Fast_TernaryExpr_createIf(Fast_Expression condition, Fast_Node ifTrue, Fast_Node ifFalse) {
    Fast_Block trueBlock;
    Fast_Block falseBlock;
    Fast_If falseIf;
    Fast_If result;
    
    if (db_instanceof(db_typedef(Fast_Block_o), ifTrue)) {
        trueBlock = Fast_Block__create(yparser()->block);
        falseBlock = Fast_Block__create(yparser()->block);
        Fast_Block_addStatement(trueBlock, Fast_Node(ifTrue));
        Fast_Block_addStatement(falseBlock, Fast_Node(ifFalse));
        Fast_Parser_collect(yparser(), trueBlock);
        Fast_Parser_collect(yparser(), falseBlock);
    } else {
        trueBlock = Fast_Block(ifTrue);
        falseBlock = Fast_Block(ifFalse);
    }
    
    falseIf = Fast_If__create(NULL, falseBlock, NULL);
    result = Fast_If__create(condition, trueBlock, falseIf);
    
    /* Because a ternary operator always has a true and false branch it there is not much use
     * in reporting unreachable code. If a ternary operator has a compile-time resolvable
     * condition, it is probably intended. */
    Fast_If_noWarnUnreachable(result);

    Fast_Parser_collect(yparser(), falseIf);
    
    return result;
}


/* $end */

/* callback ::hyve::lang::class::construct(lang::object object) -> ::hyve::Fast::TernaryExpr::construct(Fast::TernaryExpr object) */
db_int16 Fast_TernaryExpr_construct(Fast_TernaryExpr object) {
/* $begin(::hyve::Fast::TernaryExpr::construct) */
    Fast_Node trueBranch=NULL, falseBranch=NULL;
    Fast_Expression trueExpr, falseExpr;
    db_type resultType = Fast_Expression_getType(object->result);

    Fast_Node(object)->kind = FAST_Ternary;
    
    /* Create true statement */
    trueBranch = Fast_Node(Fast_Parser_blockPush(yparser(), FALSE));
    trueExpr = Fast_Expression(Fast_Parser_binaryExpr(yparser(), object->result, object->ifTrue, DB_ASSIGN));
    Fast_Block_addStatement(Fast_Block(trueBranch), Fast_Node(trueExpr));
    Fast_Parser_blockPop(yparser());
    
    /* Create false statement */
    falseBranch = Fast_Node(Fast_Parser_blockPush(yparser(), FALSE));
    falseExpr = Fast_Expression(Fast_Parser_binaryExpr(yparser(), object->result, object->ifFalse, DB_ASSIGN));
    Fast_Block_addStatement(Fast_Block(falseBranch), Fast_Node(falseExpr));
    Fast_Parser_blockPop(yparser());

    /* Store both expressions in object */
    db_set(&object->ifTrueExpr, trueExpr);
    db_set(&object->ifFalseExpr, falseExpr);
    
    /* Create condition */
    object->ifstmt = Fast_TernaryExpr_createIf(object->condition, trueBranch, falseBranch);
    Fast_Expression(object)->type = Fast_Variable(Fast_Object__create(resultType));

    return 0;
/* $end */
}

/* ::hyve::Fast::TernaryExpr::hasSideEffects() */
db_bool Fast_TernaryExpr_hasSideEffects_v(Fast_TernaryExpr _this) {
/* $begin(::hyve::Fast::TernaryExpr::hasSideEffects) */
    return Fast_Expression_hasSideEffects(_this->condition) ||
           Fast_Expression_hasSideEffects(_this->ifTrue) ||
           Fast_Expression_hasSideEffects(_this->ifFalse);
/* $end */
}

/* ::hyve::Fast::TernaryExpr::setOperator(lang::operatorKind kind) */
db_void Fast_TernaryExpr_setOperator(Fast_TernaryExpr _this, db_operatorKind kind) {
/* $begin(::hyve::Fast::TernaryExpr::setOperator) */

    if (_this->ifTrueExpr && db_instanceof(db_typedef(Fast_BinaryExpr_o), _this->ifTrueExpr)) {
        Fast_BinaryExpr_setOperator(Fast_BinaryExpr(_this->ifTrueExpr), kind);
    }
    if (_this->ifFalseExpr && db_instanceof(db_typedef(Fast_BinaryExpr_o), _this->ifFalseExpr)) {
        Fast_BinaryExpr_setOperator(Fast_BinaryExpr(_this->ifFalseExpr), kind);
    }

/* $end */
}

/* ::hyve::Fast::TernaryExpr::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_TernaryExpr_toIc_v(Fast_TernaryExpr _this, db_icProgram program, db_icStorage storage, db_bool stored) {
/* $begin(::hyve::Fast::TernaryExpr::toIc) */
    Fast_If_toIc(_this->ifstmt, program, storage, stored);
    return Fast_Node_toIc(Fast_Node(_this->result), program, storage, stored);
/* $end */
}
