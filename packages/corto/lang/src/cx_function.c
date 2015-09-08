/* cx_function.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#define corto_lang_LIB
#include "cx.h"

/* ::corto::lang::function::bind() */
cx_int16 _cx_function_bind(cx_function this) {
/* $begin(::corto::lang::function::bind) */
    /* Count the size based on the parameters and store parameters in slots */
    if (!this->size) {
        cx_uint32 i;
        for(i=0; i<this->parameters.length; i++) {
            if (this->parameters.buffer[i].passByReference) {
                this->size += sizeof(cx_word);
            } else {
                cx_type paramType = this->parameters.buffer[i].type;
                switch(paramType->kind) {
                case CX_ANY:
                    this->size += sizeof(cx_any);
                    break;
                case CX_PRIMITIVE:
                    this->size += cx_type_sizeof(paramType);
                    break;
                default:
                    this->size += sizeof(void*);
                    break;
                }
            }
        }

        /* Add size of this-pointer - this must be moved to impl of methods, delegates and callbacks. */
        if (!(cx_typeof(this) == cx_type(cx_function_o))) {
            if (cx_typeof(this) == cx_type(cx_metaprocedure_o)) {
                this->size += sizeof(cx_any);
            } else {
                this->size += sizeof(cx_object);
            }
        }
    }

    /* If no returntype is set, make it void */
    if (!this->returnType) {
        cx_setref(&this->returnType, cx_void_o);
    }

    if (this->returnType->reference) {
        this->returnsReference = TRUE;
    }

    /* Bind with interface if possible */
    if (cx_delegate_bind(this)) {
        goto error;
    }

    return 0;
error:
    return -1;
/* $end */
}

/* ::corto::lang::function::init() */
/* $header(::corto::lang::function::init) */
static cx_int16 cx_function_parseArguments(cx_function object) {
    object->parameters = cx_function_stringToParameterSeq(cx_nameof(object), cx_parentof(object));
    return object->parameters.length == (cx_uint32)-1;
}

typedef struct cx_functionLookup_t {
    cx_function f;
    cx_bool error;
    cx_id name;
}cx_functionLookup_t;

static int cx_functionLookupWalk(cx_object o, void* userData) {
    cx_functionLookup_t* data;
    cx_int32 d;

    data = userData;

    if (o != data->f) {
        if ((cx_class_instanceof(cx_procedure_o, cx_typeof(o)))) {
            if (cx_overload(o, cx_nameof(data->f), &d)) {
                data->error = TRUE;
                goto finish;
            }

            /* Check if function matches */
            if (!d) {
                cx_id id, id2;
                cx_error("function '%s' conflicts with existing declaration '%s'", cx_fullname(data->f, id), cx_fullname(o, id2));
                data->error = TRUE;
                goto finish;
            } else {
                cx_id id;

                /* Get name of function */
                cx_signatureName(cx_nameof(o), id);

                /* Set overloading flags if a function with same name is found. */
                if (!strcmp(data->name, id)) {
                    cx_function(o)->overloaded = TRUE;
                    data->f->overloaded = TRUE;
                }
            }
        }
    }

    return 1;
finish:
    return 0;
}
/* $end */
cx_int16 _cx_function_init(cx_function this) {
/* $begin(::corto::lang::function::init) */
    cx_functionLookup_t walkData;
    cx_ll scope;

    scope = cx_scopeClaim(cx_parentof(this));

    walkData.f = this;
    walkData.error = FALSE;
    cx_signatureName(cx_nameof(this), walkData.name);
    cx_llWalk(scope, cx_functionLookupWalk, &walkData);
    if (walkData.error) {
        goto error;
    }

    cx_scopeRelease(scope);

    /* Parse arguments */
    if (cx_function_parseArguments(this)) {
        goto error;
    }

    return 0;
error:
    this->parameters.length = 0;
    return -1;
/* $end */
}

/* ::corto::lang::function::stringToParameterSeq(string name,object scope) */
cx_parameterseq _cx_function_stringToParameterSeq(cx_string name, cx_object scope) {
/* $begin(::corto::lang::function::stringToParameterSeq) */
    cx_parameterseq result = {0, NULL};

    cx_char* ptr;

    ptr = strchr(name, '(');
    if (!ptr) {
        cx_error("missing argumentlist in name for signature '%s'", name);
        goto error;
    }
    ptr++;

    /* Check if function has arguments */
    if (*ptr != ')') {
        cx_int32 count = 0, i = 0;
        cx_id id;
        int flags = 0;

        /* Count number of parameters for function */
        count = cx_signatureParamCount(name);
        if (count == -1) {
            goto error;
        }

        /* Allocate size for parameters */
        result.length = count;
        result.buffer = cx_alloc(sizeof(cx_parameter) * count);
        memset(result.buffer, 0, sizeof(cx_parameter) * count);

        /* Parse arguments */
        for(i=0; i<count; i++) {
            if (cx_signatureParamType(name, i, id, &flags)) {
                cx_error("error occurred while parsing type of parameter '%d' for signature '%s'", i, name);
                goto error;
            }

            /* Set reference */
            result.buffer[i].passByReference = (flags & CX_PARAMETER_REFERENCE) != 0;

            /* Assign type */
            result.buffer[i].type = cx_resolve(scope, id);
            if (!result.buffer[i].type) {
                cx_error("type '%s' of parameter %d in signature %s not found", id, i, name);
                goto error;
            }

            /* Validate whether reference is not redundantly applied */
            if (result.buffer[i].passByReference && result.buffer[i].type->reference) {
                cx_id id;
                cx_error("redundant '&' qualifier for parameter %d, type '%s' is already a reference",
                    i, cx_fullname(result.buffer[i].type, id));
                goto error;
            }

            /* Parse name */
            if (cx_signatureParamName(name, i, id)) {
                cx_error("error occurred while parsing name of argument '%s' for signature '%s'", name);
                goto error;
            }

            result.buffer[i].name = cx_strdup(id);
        }
    }

    return result;
error:
    result.length = -1;
    cx_dealloc(result.buffer);
    result.buffer = NULL;
    return result;
/* $end */
}

/* ::corto::lang::function::unbind(function object) */
cx_void _cx_function_unbind(cx_function object) {
/* $begin(::corto::lang::function::unbind) */
    cx_uint32 i;

    cx_callDestroy(object);

    /* Deinitialize parameters */
    for(i=0; i<object->parameters.length; i++) {
        cx_dealloc(object->parameters.buffer[i].name);
        object->parameters.buffer[i].name = NULL;
        cx_release(object->parameters.buffer[i].type);
        object->parameters.buffer[i].type = NULL;
    }

    cx_dealloc(object->parameters.buffer);
    object->parameters.buffer = NULL;
/* $end */
}
