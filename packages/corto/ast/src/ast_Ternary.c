/* ast_Ternary.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "ast.h"

/* $header() */
#include "ast__private.h"

ast_Parser yparser(void);
void ast_Parser_error(ast_Parser this, char* fmt, ...);
void ast_Parser_warning(ast_Parser this, char* fmt, ...);

/* Create if statement based on ternary operator expressions */
ast_If ast_Ternary_createIf(ast_Expression condition, ast_Node ifTrue, ast_Node ifFalse) {
    ast_Block trueBlock;
    ast_Block falseBlock;
    ast_If falseIf;
    ast_If result;
    
    if (cx_instanceof(cx_type(ast_Block_o), ifTrue)) {
        trueBlock = ast_BlockCreate(yparser()->block);
        falseBlock = ast_BlockCreate(yparser()->block);
        ast_Block_addStatement(trueBlock, ast_Node(ifTrue));
        ast_Block_addStatement(falseBlock, ast_Node(ifFalse));
        ast_Parser_collect(yparser(), trueBlock);
        ast_Parser_collect(yparser(), falseBlock);
    } else {
        trueBlock = ast_Block(ifTrue);
        falseBlock = ast_Block(ifFalse);
    }
    
    falseIf = ast_IfCreate(NULL, falseBlock, NULL);
    result = ast_IfCreate(condition, trueBlock, falseIf);
    
    /* Because a ternary operator always has a true and false branch it there is not much use
     * in reporting unreachable code. If a ternary operator has a compile-time resolvable
     * condition, it is probably intended. */
    ast_If_noWarnUnreachable(result);

    ast_Parser_collect(yparser(), falseIf);
    
    return result;
}


/* $end */

/* ::corto::ast::Ternary::construct() */
cx_int16 _ast_Ternary_construct(ast_Ternary this) {
/* $begin(::corto::ast::Ternary::construct) */
    ast_Node trueBranch=NULL, falseBranch=NULL;
    ast_Expression trueExpr, falseExpr;
    cx_type resultType = ast_Expression_getType(this->result);

    ast_Node(this)->kind = Ast_TernaryExpr;
    
    /* Create true statement */
    trueBranch = ast_Node(ast_Parser_blockPush(yparser(), FALSE));
    trueExpr = ast_Expression(ast_Parser_binaryExpr(yparser(), this->result, this->ifTrue, CX_ASSIGN));
    ast_Block_addStatement(ast_Block(trueBranch), ast_Node(trueExpr));
    ast_Parser_blockPop(yparser());
    
    /* Create false statement */
    falseBranch = ast_Node(ast_Parser_blockPush(yparser(), FALSE));
    falseExpr = ast_Expression(ast_Parser_binaryExpr(yparser(), this->result, this->ifFalse, CX_ASSIGN));
    ast_Block_addStatement(ast_Block(falseBranch), ast_Node(falseExpr));
    ast_Parser_blockPop(yparser());

    /* Store both expressions in this */
    cx_setref(&this->ifTrueExpr, trueExpr);
    cx_setref(&this->ifFalseExpr, falseExpr);
    
    /* Create condition */
    this->ifstmt = ast_Ternary_createIf(this->condition, trueBranch, falseBranch);
    cx_setref(&ast_Expression(this)->type, resultType);

    return 0;
/* $end */
}

/* ::corto::ast::Ternary::hasReturnedResource() */
cx_bool _ast_Ternary_hasReturnedResource_v(ast_Ternary this) {
/* $begin(::corto::ast::Ternary::hasReturnedResource) */
    return ast_Expression_hasReturnedResource(this->condition) ||
           ast_Expression_hasReturnedResource(this->ifTrue) ||
           ast_Expression_hasReturnedResource(this->ifFalse);
/* $end */
}

/* ::corto::ast::Ternary::hasSideEffects() */
cx_bool _ast_Ternary_hasSideEffects_v(ast_Ternary this) {
/* $begin(::corto::ast::Ternary::hasSideEffects) */
    return ast_Expression_hasSideEffects(this->condition) ||
           ast_Expression_hasSideEffects(this->ifTrue) ||
           ast_Expression_hasSideEffects(this->ifFalse);
/* $end */
}

/* ::corto::ast::Ternary::setOperator(operatorKind kind) */
cx_void _ast_Ternary_setOperator(ast_Ternary this, cx_operatorKind kind) {
/* $begin(::corto::ast::Ternary::setOperator) */

    if (this->ifTrueExpr && cx_instanceof(cx_type(ast_Binary_o), this->ifTrueExpr)) {
        ast_Binary_setOperator(ast_Binary(this->ifTrueExpr), kind);
    }
    if (this->ifFalseExpr && cx_instanceof(cx_type(ast_Binary_o), this->ifFalseExpr)) {
        ast_Binary_setOperator(ast_Binary(this->ifFalseExpr), kind);
    }

/* $end */
}

/* ::corto::ast::Ternary::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node _ast_Ternary_toIc_v(ast_Ternary this, ic_program program, ic_storage storage, cx_bool stored) {
/* $begin(::corto::ast::Ternary::toIc) */
    ast_If_toIc(this->ifstmt, program, storage, stored);
    return ast_Node_toIc(ast_Node(this->result), program, storage, stored);
/* $end */
}
