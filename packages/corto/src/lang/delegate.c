/* $CORTO_GENERATED
 *
 * delegate.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <corto/lang/lang.h>

corto_int16 _corto_delegate_construct(
    corto_function object)
{
/* $begin(corto/lang/delegate/construct) */
    corto_object parent = corto_parentof(object);

    if (corto_class_instanceof(corto_interface_o, corto_typeof(parent))) {
        corto_interface type = corto_interface(corto_typeof(parent));
        corto_id functionName;
        corto_member m = NULL;

        /* Get function name, lookup delegate, assign function */
        corto_signatureName(corto_idof(object), functionName);
        if (corto_checkState(corto_type_o, CORTO_DEFINED) && (m = corto_interface_resolveMember(type, functionName)) &&
            (m->type->kind == CORTO_COMPOSITE) && (corto_interface(m->type)->kind == CORTO_DELEGATE)) {
            if (corto_delegate_instanceof(corto_delegate(m->type), object)) {
                /* Bind instance of function is a method */
                if (corto_procedure(corto_typeof(object))->kind == CORTO_METHOD) {
                    corto_setref(&((corto_delegatedata *) CORTO_OFFSET(parent, m->offset))->instance, parent);
                }
                /* Bind procedure */
                corto_setref(&((corto_delegatedata *) CORTO_OFFSET(parent, m->offset))->procedure, object);
            } else {
                /* If there is a member that corresponds to a delegate but has a non matching
                 * signature, always report error */
                corto_seterr(
                    "member '%s' of delegate type '%s' does not match signature of '%s'",
                    corto_idof(m),
                    corto_fullpath(NULL, m->type),
                    corto_fullpath(NULL, object));
                goto error;
            }
        }
    }

    return 0;
error:
    return -1;
/* $end */
}

corto_bool _corto_delegate_castable_v(
    corto_delegate this,
    corto_type type)
{
/* $begin(corto/lang/delegate/castable) */
    return corto_delegate_compatible_v(this, type);
/* $end */
}

corto_bool _corto_delegate_compatible_v(
    corto_delegate this,
    corto_type type)
{
/* $begin(corto/lang/delegate/compatible) */
    corto_bool result = FALSE;
    CORTO_UNUSED(this);

    if((type->kind == CORTO_COMPOSITE) && (corto_interface(type)->kind == CORTO_DELEGATE)) {
        corto_uint32 i;
        result = TRUE;

        /* Validate returntype */
        if((this->returnType != corto_delegate(type)->returnType) || (this->returnsReference != corto_delegate(type)->returnsReference)) {
            result = FALSE;
        }

        /* Validate number of parameters */
        if(this->parameters.length != corto_delegate(type)->parameters.length) {
            result = FALSE;
        }

        /* Validate parameters */
        for(i = 0; !result && (i < this->parameters.length); i++) {
            if(this->parameters.buffer[i].type != corto_delegate(type)->parameters.buffer[i].type) {
                result = FALSE;
            }
            if(this->parameters.buffer[i].passByReference != corto_delegate(type)->parameters.buffer[i].passByReference) {
                result = FALSE;
            }
        }
    } else if ((type->kind == CORTO_COMPOSITE) && (corto_interface(type)->kind == CORTO_PROCEDURE)) {
        result = TRUE;
    }

    return result;
/* $end */
}

corto_int16 _corto_delegate_init(
    corto_delegate this)
{
/* $begin(corto/lang/delegate/init) */
    corto_int16 result;

    corto_interface(this)->base = corto_interface(corto_delegatedata_o);
    corto_struct(this)->baseAccess = CORTO_GLOBAL;

    result = corto_struct_init(corto_struct(this));
    if(result) {
        goto error;
    }

    corto_interface(this)->kind = CORTO_DELEGATE;

    return 0;
error:
    return -1;
/* $end */
}

/* $header(corto/lang/delegate/instanceof) */
corto_bool corto_delegate_matchParameter(
    corto_type t1,
    corto_bool isRef1,
    corto_type t2,
    corto_bool isRef2) {

    if ((t1 != t2) || (isRef1 && !isRef2)) {
        return FALSE;
    } else {
        return TRUE;
    }
}
/* $end */
corto_bool _corto_delegate_instanceof(
    corto_delegate this,
    corto_object object)
{
/* $begin(corto/lang/delegate/instanceof) */
    corto_type t = corto_typeof(object);
    corto_bool result = TRUE;

    if ((t->kind == CORTO_COMPOSITE) && (corto_interface(t)->kind == CORTO_PROCEDURE)) {
        corto_function call = object;
        corto_uint32 i;

        /* Validate returntype */
        if (!corto_delegate_matchParameter(
            this->returnType,
            this->returnsReference,
            call->returnType,
            call->returnsReference)) {
            result = FALSE;
        }

        /* Validate number of parameters */
        if (this->parameters.length != call->parameters.length) {
            result = FALSE;
        }

        /* Validate parameters */
        for (i = 0; i < this->parameters.length; i++) {
            corto_parameter *p1, *p2;
            p1 = &this->parameters.buffer[i];
            p2 = &call->parameters.buffer[i];

            if (!corto_delegate_matchParameter(
                p1->type,
                p1->passByReference,
                p2->type,
                p2->passByReference)) {
                result = FALSE;
            }
        }
    } else {
        result = FALSE;
    }

    return result;
/* $end */
}
