/* ast_Object.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#define corto_ast_LIB
#include "ast.h"

/* $header() */
#include "ast__private.h"
/* $end */

/* ::corto::ast::Object::construct() */
cx_int16 _ast_Object_construct(ast_Object this) {
/* $begin(::corto::ast::Object::construct) */
    cx_type t = cx_typeof(ast_Object(this)->value);

    /* TODO: this is not nice */
    if(t == cx_type(cx_constant_o)) {
        t = cx_parentof(ast_Object(this)->value);
    }

    ast_Storage(this)->kind = Ast_ObjectStorage;
    cx_setref(&ast_Expression(this)->type, t);
    ast_Expression(this)->isReference = TRUE;

    return ast_Storage_construct(ast_Storage(this));
/* $end */
}

/* ::corto::ast::Object::getValue() */
cx_word _ast_Object_getValue(ast_Object this) {
/* $begin(::corto::ast::Object::getValue) */
    cx_word result = 0;

    /* Value of objects can only be used at compiletime when object is of
     * type constant. */
    if (cx_instanceof(cx_type(cx_constant_o), ast_Object(this)->value)) {
        result = (cx_word)ast_Object(this)->value;
    }

    return result;
/* $end */
}

/* ::corto::ast::Object::serialize(type dstType,word dst) */
cx_int16 _ast_Object_serialize(ast_Object this, cx_type dstType, cx_word dst) {
/* $begin(::corto::ast::Object::serialize) */
    ast_valueKind kind;

    if (!dstType->reference) {
        cx_bool srcIsDelegate = FALSE, dstIsDelegate = FALSE;
        cx_object obj = ast_Object(this)->value;
        cx_type srcType = cx_typeof(obj);

        /* Handle delegates */
        if ((srcType->kind == CX_COMPOSITE) && (cx_interface(srcType)->kind == CX_DELEGATE)) {
            srcIsDelegate = TRUE;
        }
        if ((dstType->kind == CX_COMPOSITE) && (cx_interface(dstType)->kind == CX_DELEGATE)) {
            dstIsDelegate = TRUE;
        }

        /* Handle iterators */
        if ((dstType->kind == CX_ITERATOR) && (srcType->kind == CX_COLLECTION)) {
            cx_iterator_set((void*)dst, obj, cx_collection(srcType));
        } else if (dstIsDelegate) {
            if (srcIsDelegate) {
                cx_value vDst, vSrc;
                cx_valueValueInit(&vDst, NULL, cx_type(dstType), (void *)dst);
                cx_valueValueInit(&vSrc, NULL, cx_type(srcType), ast_Object(this)->value);
                cx_copyv(&vDst, &vSrc);
            } else if ((srcType->kind == CX_COMPOSITE) && (cx_interface(srcType)->kind == CX_PROCEDURE)) {
                cx_setref(&((cx_delegatedata *)dst)->procedure, ast_Object(this)->value);
                cx_setref(&((cx_delegatedata *)dst)->instance, NULL);
            }

        } else if (cx_instanceof((cx_type)dstType, ast_Object(this)->value)) {
            /* If object is not of a reference type and object is of dstType, copy value */
            cx_value vDst, vSrc;
            cx_valueValueInit(&vDst, NULL, cx_type(dstType), (void *)dst);
            cx_valueValueInit(&vSrc, NULL, cx_type(srcType), obj);
            cx_copyv(&vDst, &vSrc);

        } else {
            cx_id id, id2;
            ast_Parser_error(yparser(), "type '%s' of object does not match destinationtype '%s'",
                    ast_Parser_id(cx_typeof(ast_Object(this)->value), id),
                    ast_Parser_id(dstType, id2));
            goto error;
        }
    } else {
        if (ast_Expression(this)->isReference) {
            kind = Ast_Ref;
        } else {
            kind = ast_valueKindFromType(dstType);
        }

        switch(kind) {
        case Ast_Bool:
            *(cx_bool*)dst = ast_Object(this)->value ? TRUE : FALSE;
            break;
        case Ast_Text: {
            cx_id id;
            if (*(cx_string*)dst) {
                cx_dealloc(*(cx_string*)dst);
            }
            *(cx_string*)dst = cx_strdup(ast_Parser_id(ast_Object(this)->value, id));
            break;
        }
        case Ast_Ref:
            if (*(cx_object*)dst) {
                cx_release(*(cx_object*)dst);
            }
            cx_setref((cx_object*)dst, ast_Object(this)->value);
            break;
        default: {
            cx_id id;
            ast_Parser_error(yparser(), "cannot serialize object value to storage of type '%s'", ast_Parser_id(dstType, id));
            goto error;
            break;
        }
        }
    }

    return 0;
error:
    return -1;
/* $end */
}

/* ::corto::ast::Object::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node _ast_Object_toIc_v(ast_Object this, ic_program program, ic_storage storage, cx_bool stored) {
/* $begin(::corto::ast::Object::toIc) */
    CX_UNUSED(program);
    CX_UNUSED(storage);
    CX_UNUSED(stored);
    return ic_node(ic_program_getObject(program, this->value));;
/* $end */
}
