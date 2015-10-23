/* ast_Object.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "ast.h"

/* $header() */
#include "ast__private.h"
/* $end */

/* ::corto::ast::Object::construct() */
corto_int16 _ast_Object_construct(ast_Object this) {
/* $begin(::corto::ast::Object::construct) */
    corto_type t = corto_typeof(ast_Object(this)->value);

    /* TODO: this is not nice */
    if(t == corto_type(corto_constant_o)) {
        t = corto_parentof(ast_Object(this)->value);
    }

    ast_Storage(this)->kind = Ast_ObjectStorage;
    corto_setref(&ast_Expression(this)->type, t);
    ast_Expression(this)->isReference = TRUE;

    return ast_Storage_construct(ast_Storage(this));
/* $end */
}

/* ::corto::ast::Object::getValue() */
corto_word _ast_Object_getValue(ast_Object this) {
/* $begin(::corto::ast::Object::getValue) */
    corto_word result = 0;

    /* Value of objects can only be used at compiletime when object is of
     * type constant. */
    if (corto_instanceof(corto_type(corto_constant_o), ast_Object(this)->value)) {
        result = (corto_word)ast_Object(this)->value;
    }

    return result;
/* $end */
}

/* ::corto::ast::Object::serialize(type dstType,word dst) */
corto_int16 _ast_Object_serialize(ast_Object this, corto_type dstType, corto_word dst) {
/* $begin(::corto::ast::Object::serialize) */
    ast_valueKind kind;

    if (!dstType->reference) {
        corto_bool srcIsDelegate = FALSE, dstIsDelegate = FALSE;
        corto_object obj = ast_Object(this)->value;
        corto_type srcType = corto_typeof(obj);

        /* Handle delegates */
        if ((srcType->kind == CORTO_COMPOSITE) && (corto_interface(srcType)->kind == CORTO_DELEGATE)) {
            srcIsDelegate = TRUE;
        }
        if ((dstType->kind == CORTO_COMPOSITE) && (corto_interface(dstType)->kind == CORTO_DELEGATE)) {
            dstIsDelegate = TRUE;
        }

        /* Handle iterators */
        if ((dstType->kind == CORTO_ITERATOR) && (srcType->kind == CORTO_COLLECTION)) {
            corto_iterator_set((void*)dst, obj, corto_collection(srcType));
        } else if (dstIsDelegate) {
            if (srcIsDelegate) {
                corto_value vDst, vSrc;
                corto_valueValueInit(&vDst, NULL, corto_type(dstType), (void *)dst);
                corto_valueValueInit(&vSrc, NULL, corto_type(srcType), ast_Object(this)->value);
                corto_copyv(&vDst, &vSrc);
            } else if ((srcType->kind == CORTO_COMPOSITE) && (corto_interface(srcType)->kind == CORTO_PROCEDURE)) {
                corto_setref(&((corto_delegatedata *)dst)->procedure, ast_Object(this)->value);
                corto_setref(&((corto_delegatedata *)dst)->instance, NULL);
            }

        } else if (corto_instanceof((corto_type)dstType, ast_Object(this)->value)) {
            /* If object is not of a reference type and object is of dstType, copy value */
            corto_value vDst, vSrc;
            corto_valueValueInit(&vDst, NULL, corto_type(dstType), (void *)dst);
            corto_valueValueInit(&vSrc, NULL, corto_type(srcType), obj);
            corto_copyv(&vDst, &vSrc);

        } else {
            corto_id id, id2;
            ast_Parser_error(yparser(), "type '%s' of object does not match destinationtype '%s'",
                    ast_Parser_id(corto_typeof(ast_Object(this)->value), id),
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
            *(corto_bool*)dst = ast_Object(this)->value ? TRUE : FALSE;
            break;
        case Ast_Text: {
            corto_id id;
            if (*(corto_string*)dst) {
                corto_dealloc(*(corto_string*)dst);
            }
            *(corto_string*)dst = corto_strdup(ast_Parser_id(ast_Object(this)->value, id));
            break;
        }
        case Ast_Ref:
            if (*(corto_object*)dst) {
                corto_release(*(corto_object*)dst);
            }
            corto_setref((corto_object*)dst, ast_Object(this)->value);
            break;
        default: {
            corto_id id;
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
ic_node _ast_Object_toIc_v(ast_Object this, ic_program program, ic_storage storage, corto_bool stored) {
/* $begin(::corto::ast::Object::toIc) */
    CORTO_UNUSED(program);
    CORTO_UNUSED(storage);
    CORTO_UNUSED(stored);
    return ic_node(ic_program_getObject(program, this->value));;
/* $end */
}
