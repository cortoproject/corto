/* ast_Update.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "ast.h"

/* $header() */
#include "ast__private.h"

static ast_Expression ast_Update_getFirstReference(ast_Expression expr) {
    ast_Expression result = expr;

    if (ast_Node(expr)->kind != Ast_StorageExpr) {
        goto error;
    }

    while (!result->isReference) {
        switch(ast_Storage(expr)->kind) {
        case Ast_MemberStorage:
            result = ast_Member(result)->lvalue;
            break;
        case Ast_ElementStorage:
            result = ast_Element(result)->lvalue;
            break;
        default:
            goto error;
        }
    }

    return result;
error:
    ast_Parser_error(yparser(), "invalid argument for update expression");
    return NULL;
}

/* $end */

/* ::corto::ast::Update::construct() */
cx_int16 _ast_Update_construct(ast_Update this) {
/* $begin(::corto::ast::Update::construct) */
    cx_iter exprIter;
    ast_Expression expr;

    ast_Node(this)->kind = Ast_UpdateExpr;

    exprIter = cx_llIter(this->exprList);
    while(cx_iterHasNext(&exprIter)) {
        expr = cx_iterNext(&exprIter);

        expr = ast_Update_getFirstReference(expr);

        if (!expr->isReference) {
            ast_Parser_error(yparser(), 
                "one or more expressions in the update statement are not references (%s)",
                cx_nameof(cx_typeof(expr)));
            goto error;            
        }
    }

    return 0;
error:
    return -1;
/* $end */
}

/* ::corto::ast::Update::toIc(ic::program program,ic::storage storage,bool stored) */
/* $header(::corto::ast::Update::toIc) */
static void ast_Update_begin(ast_Update this, ic_program program, ic_node expr) {
    IC_1(program, ast_Node(this)->line, ic_updatebegin, expr, IC_DEREF_ADDRESS);
}

static void ast_Update_end(ast_Update this, ic_program program, ic_node expr, ic_node from) {
    IC_3(program, ast_Node(this)->line, ic_update, expr, from, NULL,
        IC_DEREF_ADDRESS, IC_DEREF_VALUE, IC_DEREF_VALUE);
}

/* $end */
ic_node _ast_Update_toIc_v(ast_Update this, ic_program program, ic_storage storage, cx_bool stored) {
/* $begin(::corto::ast::Update::toIc) */
    ic_node expr, from = NULL;
    cx_iter exprIter;
    CX_UNUSED(storage);
    CX_UNUSED(stored);

    /* Evaluate expression */
    if (this->from) {
        from = ast_Node_toIc(ast_Node(this->from), program, NULL, TRUE);
    }

    /* Add update statement for each expression in exprList */
    exprIter = cx_llIter(this->exprList);
    while(cx_iterHasNext(&exprIter)) {
        ast_Expression fastExpr = ast_Update_getFirstReference(cx_iterNext(&exprIter));

        /* Run binary expression between updatebegin and updateend */
        if (this->kind != Ast_UpdateDefault) {
            ic_node objExpr = ast_Node_toIc(ast_Node(fastExpr), program, NULL, TRUE);

            if (this->kind == Ast_UpdateBegin) {
                ast_Update_begin(this, program, objExpr);
            } else if (this->kind == Ast_UpdateEnd) {
                ast_Update_end(this, program, objExpr, from);
            }
        } else {
            expr = ast_Node_toIc(ast_Node(fastExpr), program, NULL, TRUE);
            if (!this->block) {
                IC_3(program, ast_Node(this)->line, ic_update, expr, from, NULL,
                    IC_DEREF_ADDRESS, IC_DEREF_VALUE, IC_DEREF_VALUE);
            } else {
                ast_Update_begin(this, program, expr);
            }
        }
    }

    if (this->block) {
        /* Translate block to ic */
        ast_Block_toIc(this->block, program, NULL, FALSE);
        exprIter = cx_llIter(this->exprList);
        while(cx_iterHasNext(&exprIter)) {
            ast_Expression fastExpr = cx_iterNext(&exprIter);
            expr = ast_Node_toIc(ast_Node(fastExpr), program, NULL, TRUE);
            ast_Update_end(this, program, expr, from);
        }
    }

    return NULL;
/* $end */
}
