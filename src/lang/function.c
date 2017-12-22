/* This is a managed file. Do not delete this comment. */

#include <corto/corto.h>
#include "src/store/object.h"
/* Not all types that inherit from from function are necessarily procedures. Find
 * the first procedure type in the inheritance hierarchy. */
corto_procedure corto_function_getProcedureType(corto_function this) {
    corto_interface t = (corto_interface)corto_typeof(this);

    while (!corto_instanceof(corto_procedure_o, t)) {
        t = t->base;
        corto_assert(t != NULL, "no procedure type in inheritance hierarchy of function");
    }

    return (corto_procedure)t;
}

int16_t corto_delegate_validate(
    corto_function object);
int16_t corto_function_construct(
    corto_function this)
{
    /* If no returntype is set, make it void */
    corto_procedure procedure = corto_function_getProcedureType(this);

    if (!this->returnType) {
        this->returnType = corto_void_o; /* No claim needed- builtin object */
    } else if (this->returnType->reference) {
        this->returnsReference = TRUE;
    }

    /* Count the size based on the parameters and store parameters in slots */
    if (!this->size) {
        /* Add size of this-pointer */
        if (procedure->hasThis) {
            if (procedure->thisType) {
                this->size += corto_type_sizeof(procedure->thisType);
            } else {
                this->size += sizeof(corto_object);
            }

        }

        corto_uint32 i;
        for(i=0; i<this->parameters.length; i++) {
            corto_parameter *p = &this->parameters.buffer[i];
            if (p->passByReference || p->inout)
            {
                this->size += sizeof(corto_word);
            } else {
                corto_type paramType = p->type;
                switch(paramType->kind) {
                case CORTO_ANY:
                    this->size += sizeof(corto_any);
                    break;
                case CORTO_PRIMITIVE:
                    this->size += corto_type_sizeof(paramType);
                    break;
                case CORTO_COLLECTION:
                    if (corto_collection(paramType)->kind == CORTO_SEQUENCE) {
                        this->size += sizeof(corto_objectseq);
                        break;
                    }

                default:
                    this->size += sizeof(void*);
                    break;
                }

            }

        }

    }

    /* Validate delegate */
    if (corto_check_attr(this, CORTO_ATTR_NAMED) && procedure->hasThis) {
        if (corto_delegate_validate(this)) {
            goto error;
        }

    }

    /* Initialize binding-specific data */
    if (corto_invoke_init(this)) {
        goto error;
    }

    return 0;
error:
    return -1;
}

void corto_function_destruct(
    corto_function this)
{
    corto_uint32 i;

    corto_invoke_deinit(this);

    /* Deinitialize parameters */
    for(i=0; i<this->parameters.length; i++) {
        corto_dealloc(this->parameters.buffer[i].name);
        this->parameters.buffer[i].name = NULL;
        corto_release(this->parameters.buffer[i].type);
        this->parameters.buffer[i].type = NULL;
    }

    corto_dealloc(this->parameters.buffer);
    this->parameters.buffer = NULL;
    this->parameters.length = 0;
}

typedef struct corto_functionLookup_t {
    corto_function f;
    corto_bool error;
    corto_id name;
}corto_functionLookup_t;
static int corto_functionLookupWalk(corto_object o, void* userData) {
    corto_functionLookup_t* data;
    corto_int32 d;
    data = userData;
    if (o != data->f) {
        char *id = corto_idof(data->f);
        if (corto_overload(o, id, &d)) {
            data->error = TRUE;
            goto finish;
        }

        /* Check if function matches */
        if (!d) {
            if (strcmp(id, corto_idof(o))) {
                corto_throw(
                  "function '%s' conflicts with existing declaration '%s'",
                  id, corto_idof(o));
                data->error = TRUE;
                goto finish;
            }

        } else if (d > 0 || d == CORTO_OVERLOAD_NOMATCH_OVERLOAD) {
            corto_function(o)->overloaded = TRUE;
            data->f->overloaded = TRUE;
        }

    }

    return 1;
finish:
    return 0;
}

int16_t corto_function_init(
    corto_function this)
{
    if (corto_check_attr(this, CORTO_ATTR_NAMED)) {
        if (!corto_instanceof(corto_interface_o, corto_parentof(this)) &&
            !corto_instanceof(corto_method_o, this))
        {
            corto_functionLookup_t walkData = {.f = this, .error = FALSE};
            corto_uint32 i;
            corto_objectseq scope =
                corto_scope_claimWithFilter(
                    corto_parentof(this),
                    NULL,
                    corto_idof(this)
                );
            corto_sig_name(corto_idof(this), walkData.name);
            for (i = 0; i < scope.length; i++) {
                if (!corto_functionLookupWalk(scope.buffer[i], &walkData)) {
                    break;
                }

            }

            if (walkData.error) {
                goto error;
            }

            corto_scope_release(scope);
        }

        /* Parse arguments from name */
        if (corto_function_parseParamString(this, corto_idof(this))) {
            goto error;
        }

    }

    /* Bind with interface if possible */
    if (corto_check_attr(this, CORTO_ATTR_NAMED)) {
        corto_procedure p = corto_function_getProcedureType(this);
        if (p->hasThis) {
            if (corto_delegate_bind(this)) {
                goto error;
            }

        }

    }

    return 0;
error:
    this->parameters.length = 0;
    return -1;
}

int16_t corto_function_parseParamString(
    corto_function this,
    const char *params)
{
    corto_object scope;

    if (corto_check_attr(this, CORTO_ATTR_NAMED)) {
        scope = corto_parentof(this);
    } else {
        scope = root_o;
    }

    if (!this->parameters.length) {
        this->parameters = corto_function_stringToParameterSeq(params, scope);
    }

    return this->parameters.length == (corto_uint32)-1;
}

corto_parameterseq corto_function_stringToParameterSeq(
    const char *name,
    corto_object scope)
{
    corto_parameterseq result = {0, NULL};
    corto_char* ptr;
    ptr = strchr(name, '(');
    if (ptr) {
        ptr++;
        /* Check if function has arguments */
        if (*ptr != ')') {
            corto_int32 count = 0, i = 0;
            corto_id id;
            int flags = 0;
            /* Count number of parameters for function */
            count = corto_sig_paramCount(name);
            if (count == -1) {
                goto error;
            }

            /* Allocate size for parameters */
            result.length = count;
            result.buffer = corto_calloc(sizeof(corto_parameter) * count);
            /* Parse arguments */
            for(i = 0; i < count; i++) {
                if (corto_sig_paramType(name, i, id, &flags)) {
                    corto_throw(
                        "error occurred while parsing type of parameter '%d' for signature '%s'",
                        i,
                        name);
                    goto error;
                }

                /* Set reference */
                result.buffer[i].passByReference = (flags & CORTO_PARAMETER_REFERENCE) != 0;
                if ((flags & (CORTO_PARAMETER_IN|CORTO_PARAMETER_OUT)) ==
                             (CORTO_PARAMETER_IN|CORTO_PARAMETER_OUT))
                {
                    result.buffer[i].inout = CORTO_INOUT;
                } else if (flags & CORTO_PARAMETER_OUT) {
                    result.buffer[i].inout = CORTO_OUT;
                } else {
                    /* in is default */
                }

                /* Assign type */
                result.buffer[i].type = RESOLVE(scope, id);
                if (!result.buffer[i].type) {
                    corto_throw("unresolved type '%s'", id);
                    goto error;
                }

                /* Validate whether reference is not redundantly applied */
                if (result.buffer[i].passByReference && result.buffer[i].type->reference) {
                    corto_throw(
                        "redundant '&' qualifier for parameter %d, type '%s' is already a reference",
                        i,
                        corto_fullpath(NULL, result.buffer[i].type));
                    goto error;
                }

                /* Parse name */
                if (corto_sig_paramName(name, i, id)) {
                    corto_throw(
                        "error occurred while parsing name of argument '%s' for signature '%s'",
                        name);
                    goto error;
                }

                result.buffer[i].name = corto_strdup(id);
            }

        }

    }

    return result;
error:
    result.length = -1;
    corto_dealloc(result.buffer);
    result.buffer = NULL;
    return result;
}

