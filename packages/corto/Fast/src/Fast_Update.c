/* Fast_Update.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#define corto_Fast_LIB
#include "Fast.h"

/* $header() */
#include "Fast__private.h"

static Fast_Expression Fast_Update_getFirstReference(Fast_Expression expr) {
    Fast_Expression result = expr;

    if (Fast_Node(expr)->kind != Fast_StorageExpr) {
        goto error;
    }

    while (!result->isReference) {
        switch(Fast_Storage(expr)->kind) {
        case Fast_MemberStorage:
            result = Fast_Member(result)->lvalue;
            break;
        case Fast_ElementStorage:
            result = Fast_Element(result)->lvalue;
            break;
        default:
            goto error;
        }
    }

    return result;
error:
    Fast_Parser_error(yparser(), "invalid argument for update expression");
    return NULL;
}

/* $end */

/* ::corto::Fast::Update::construct() */
cx_int16 _Fast_Update_construct(Fast_Update this) {
/* $begin(::corto::Fast::Update::construct) */
    cx_iter exprIter;
    Fast_Expression expr;

    Fast_Node(this)->kind = Fast_UpdateExpr;

    exprIter = cx_llIter(this->exprList);
    while(cx_iterHasNext(&exprIter)) {
        expr = cx_iterNext(&exprIter);

        expr = Fast_Update_getFirstReference(expr);

        if (!expr->isReference) {
            Fast_Parser_error(yparser(), 
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

/* ::corto::Fast::Update::toIc(ic::program program,ic::storage storage,bool stored) */
/* $header(::corto::Fast::Update::toIc) */
static void Fast_Update_begin(Fast_Update this, ic_program program, ic_node expr) {
    IC_1(program, Fast_Node(this)->line, ic_updatebegin, expr, IC_DEREF_ADDRESS);
}

static void Fast_Update_end(Fast_Update this, ic_program program, ic_node expr, ic_node from) {
    IC_3(program, Fast_Node(this)->line, ic_update, expr, from, NULL,
        IC_DEREF_ADDRESS, IC_DEREF_VALUE, IC_DEREF_VALUE);
}

/* $end */
ic_node _Fast_Update_toIc_v(Fast_Update this, ic_program program, ic_storage storage, cx_bool stored) {
/* $begin(::corto::Fast::Update::toIc) */
    ic_node expr, from = NULL;
    cx_iter exprIter;
    CX_UNUSED(storage);
    CX_UNUSED(stored);

    /* Evaluate expression */
    if (this->from) {
        from = Fast_Node_toIc(Fast_Node(this->from), program, NULL, TRUE);
    }

    /* Add update statement for each expression in exprList */
    exprIter = cx_llIter(this->exprList);
    while(cx_iterHasNext(&exprIter)) {
        Fast_Expression fastExpr = Fast_Update_getFirstReference(cx_iterNext(&exprIter));

        /* Run binary expression between updatebegin and updateend */
        if (this->kind != Fast_UpdateDefault) {
            ic_node objExpr = Fast_Node_toIc(Fast_Node(fastExpr), program, NULL, TRUE);

            if (this->kind == Fast_UpdateBegin) {
                Fast_Update_begin(this, program, objExpr);
            } else if (this->kind == Fast_UpdateEnd) {
                Fast_Update_end(this, program, objExpr, from);
            }
        } else {
            expr = Fast_Node_toIc(Fast_Node(fastExpr), program, NULL, TRUE);
            if (!this->block) {
                IC_3(program, Fast_Node(this)->line, ic_update, expr, from, NULL,
                    IC_DEREF_ADDRESS, IC_DEREF_VALUE, IC_DEREF_VALUE);
            } else {
                Fast_Update_begin(this, program, expr);
            }
        }
    }

    if (this->block) {
        /* Translate block to ic */
        Fast_Block_toIc(this->block, program, NULL, FALSE);
        exprIter = cx_llIter(this->exprList);
        while(cx_iterHasNext(&exprIter)) {
            Fast_Expression fastExpr = cx_iterNext(&exprIter);
            expr = Fast_Node_toIc(Fast_Node(fastExpr), program, NULL, TRUE);
            Fast_Update_end(this, program, expr, from);
        }
    }

    return NULL;
/* $end */
}
