/* Fast_Ternary.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "Fast.h"

/* $header() */
#include "Fast__private.h"

Fast_Parser yparser(void);
void Fast_Parser_error(Fast_Parser _this, char* fmt, ...);
void Fast_Parser_warning(Fast_Parser _this, char* fmt, ...);

/* Create if statement based on ternary operator expressions */
Fast_If Fast_Ternary_createIf(Fast_Expression condition, Fast_Node ifTrue, Fast_Node ifFalse) {
    Fast_Block trueBlock;
    Fast_Block falseBlock;
    Fast_If falseIf;
    Fast_If result;
    
    if (cx_instanceof(cx_type(Fast_Block_o), ifTrue)) {
        trueBlock = Fast_BlockCreate(yparser()->block);
        falseBlock = Fast_BlockCreate(yparser()->block);
        Fast_Block_addStatement(trueBlock, Fast_Node(ifTrue));
        Fast_Block_addStatement(falseBlock, Fast_Node(ifFalse));
        Fast_Parser_collect(yparser(), trueBlock);
        Fast_Parser_collect(yparser(), falseBlock);
    } else {
        trueBlock = Fast_Block(ifTrue);
        falseBlock = Fast_Block(ifFalse);
    }
    
    falseIf = Fast_IfCreate(NULL, falseBlock, NULL);
    result = Fast_IfCreate(condition, trueBlock, falseIf);
    
    /* Because a ternary operator always has a true and false branch it there is not much use
     * in reporting unreachable code. If a ternary operator has a compile-time resolvable
     * condition, it is probably intended. */
    Fast_If_noWarnUnreachable(result);

    Fast_Parser_collect(yparser(), falseIf);
    
    return result;
}


/* $end */

/* ::corto::Fast::Ternary::construct() */
cx_int16 _Fast_Ternary_construct(Fast_Ternary _this) {
/* $begin(::corto::Fast::Ternary::construct) */
    Fast_Node trueBranch=NULL, falseBranch=NULL;
    Fast_Expression trueExpr, falseExpr;
    cx_type resultType = Fast_Expression_getType(_this->result);

    Fast_Node(_this)->kind = Fast_TernaryExpr;
    
    /* Create true statement */
    trueBranch = Fast_Node(Fast_Parser_blockPush(yparser(), FALSE));
    trueExpr = Fast_Expression(Fast_Parser_binaryExpr(yparser(), _this->result, _this->ifTrue, CX_ASSIGN));
    Fast_Block_addStatement(Fast_Block(trueBranch), Fast_Node(trueExpr));
    Fast_Parser_blockPop(yparser());
    
    /* Create false statement */
    falseBranch = Fast_Node(Fast_Parser_blockPush(yparser(), FALSE));
    falseExpr = Fast_Expression(Fast_Parser_binaryExpr(yparser(), _this->result, _this->ifFalse, CX_ASSIGN));
    Fast_Block_addStatement(Fast_Block(falseBranch), Fast_Node(falseExpr));
    Fast_Parser_blockPop(yparser());

    /* Store both expressions in _this */
    cx_setref(&_this->ifTrueExpr, trueExpr);
    cx_setref(&_this->ifFalseExpr, falseExpr);
    
    /* Create condition */
    _this->ifstmt = Fast_Ternary_createIf(_this->condition, trueBranch, falseBranch);
    cx_setref(&Fast_Expression(_this)->type, resultType);

    return 0;
/* $end */
}

/* ::corto::Fast::Ternary::hasReturnedResource() */
cx_bool _Fast_Ternary_hasReturnedResource_v(Fast_Ternary _this) {
/* $begin(::corto::Fast::Ternary::hasReturnedResource) */
    return Fast_Expression_hasReturnedResource(_this->condition) ||
           Fast_Expression_hasReturnedResource(_this->ifTrue) ||
           Fast_Expression_hasReturnedResource(_this->ifFalse);
/* $end */
}

/* ::corto::Fast::Ternary::hasSideEffects() */
cx_bool _Fast_Ternary_hasSideEffects_v(Fast_Ternary _this) {
/* $begin(::corto::Fast::Ternary::hasSideEffects) */
    return Fast_Expression_hasSideEffects(_this->condition) ||
           Fast_Expression_hasSideEffects(_this->ifTrue) ||
           Fast_Expression_hasSideEffects(_this->ifFalse);
/* $end */
}

/* ::corto::Fast::Ternary::setOperator(operatorKind kind) */
cx_void _Fast_Ternary_setOperator(Fast_Ternary _this, cx_operatorKind kind) {
/* $begin(::corto::Fast::Ternary::setOperator) */

    if (_this->ifTrueExpr && cx_instanceof(cx_type(Fast_Binary_o), _this->ifTrueExpr)) {
        Fast_Binary_setOperator(Fast_Binary(_this->ifTrueExpr), kind);
    }
    if (_this->ifFalseExpr && cx_instanceof(cx_type(Fast_Binary_o), _this->ifFalseExpr)) {
        Fast_Binary_setOperator(Fast_Binary(_this->ifFalseExpr), kind);
    }

/* $end */
}

/* ::corto::Fast::Ternary::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node _Fast_Ternary_toIc_v(Fast_Ternary _this, ic_program program, ic_storage storage, cx_bool stored) {
/* $begin(::corto::Fast::Ternary::toIc) */
    Fast_If_toIc(_this->ifstmt, program, storage, stored);
    return Fast_Node_toIc(Fast_Node(_this->result), program, storage, stored);
/* $end */
}
