/* $CORTO_GENERATED
 *
 * function.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include "corto/lang/lang.h"

/* $header() */

/* Keep include local because of clashing macro's with other libraries (yacc) */
#ifdef __MACH__
#include "ffi/ffi.h"
#else
#include "ffi.h"
#endif

/* ANY type */
ffi_type *corto_ffi_type_any_elements[] = {
    &ffi_type_pointer,
    &ffi_type_pointer,
    &ffi_type_uint8,
    NULL
};
ffi_type corto_ffi_type_any = {
    .size = 0,
    .alignment = 0,
    .type = FFI_TYPE_STRUCT,
    .elements = (ffi_type**)&corto_ffi_type_any_elements
};

/* SEQUENCE type */
ffi_type *corto_ffi_type_sequence_elements[] = {
    &ffi_type_uint32,
    &ffi_type_pointer,
    NULL
};
ffi_type corto_ffi_type_sequence = {
    .size = 0,
    .alignment = 0,
    .type = FFI_TYPE_STRUCT,
    .elements = (ffi_type**)&corto_ffi_type_sequence_elements
};

/* ITERATOR type */
ffi_type *corto_ffi_type_iterator_elements[] = {
    &ffi_type_pointer,
    &ffi_type_pointer,
    &ffi_type_pointer,
    &ffi_type_pointer,
    &ffi_type_pointer,
    &ffi_type_pointer,
    &ffi_type_pointer,
    &ffi_type_pointer,
    &ffi_type_pointer,
    &ffi_type_pointer,
    NULL
};
ffi_type corto_ffi_type_iterator = {
    .size = 0,
    .alignment = 0,
    .type = FFI_TYPE_STRUCT,
    .elements = (ffi_type**)&corto_ffi_type_iterator_elements
};

ffi_type* corto_ffi_type(corto_type t) {
    ffi_type *result = NULL;

    if (t->reference) {
        result = &ffi_type_pointer;
    } else {
        switch(t->kind) {
        case CORTO_VOID:
            result = &ffi_type_void;
            break;
        case CORTO_ANY:
            result = &corto_ffi_type_any;
            break;
        case CORTO_ITERATOR:
            result = &corto_ffi_type_iterator;
            break;
        case CORTO_PRIMITIVE:
            switch(corto_primitive(t)->kind) {
            case CORTO_BINARY:
            case CORTO_BITMASK:
            case CORTO_BOOLEAN:
            case CORTO_CHARACTER:
            case CORTO_UINTEGER:
                switch(corto_primitive(t)->width) {
                case CORTO_WIDTH_8: result = &ffi_type_uint8; break;
                case CORTO_WIDTH_16: result = &ffi_type_uint16; break;
                case CORTO_WIDTH_32: result = &ffi_type_uint32; break;
                case CORTO_WIDTH_64: result = &ffi_type_uint64; break;
                case CORTO_WIDTH_WORD: result = &ffi_type_pointer; break;
                    break;
                }
                break;
            case CORTO_ENUM:
            case CORTO_INTEGER:
                switch(corto_primitive(t)->width) {
                case CORTO_WIDTH_8: result = &ffi_type_sint8; break;
                case CORTO_WIDTH_16: result = &ffi_type_sint16; break;
                case CORTO_WIDTH_32: result = &ffi_type_sint32; break;
                case CORTO_WIDTH_64: result = &ffi_type_sint64; break;
                case CORTO_WIDTH_WORD: result = &ffi_type_pointer; break;
                    break;
                }
                break;
            case CORTO_FLOAT:
                switch(corto_primitive(t)->width) {
                case CORTO_WIDTH_32: result = &ffi_type_float; break;
                case CORTO_WIDTH_64: result = &ffi_type_double; break;
                    break;
                default:
                    result = NULL;
                    break;
                }
                break;
            case CORTO_TEXT:
                result = &ffi_type_pointer;
                break;
            }
            break;
        case CORTO_COMPOSITE:
            result = &ffi_type_pointer;
            break;
        case CORTO_COLLECTION:
            if (corto_collection(t)->kind == CORTO_SEQUENCE) {
                result = &corto_ffi_type_sequence;
            } else {
                result = &ffi_type_pointer;
            }
            break;
        }
    }

    return result;
}
/* $end */

corto_int16 _corto_function_bind(
    corto_function this)
{
/* $begin(corto/lang/function/bind) */
    /* If no returntype is set, make it void */
    if (!this->returnType) {
        corto_setref(&this->returnType, corto_void_o);
    }

    if (this->returnType->reference) {
        this->returnsReference = TRUE;
    }

    /* Count the size based on the parameters and store parameters in slots */

    if (!this->size) {
        /* Allocate a single block so the arglist is freed automatically with
         * the cif */
        corto_uint32 argsSize = sizeof(ffi_type*) * (this->parameters.length + 1);
        ffi_cif *cif = corto_alloc(sizeof(ffi_cif) + argsSize);
        ffi_type **args = CORTO_OFFSET(cif, sizeof(ffi_cif));
        corto_uint8 hasThis = 0;

        /* Add size of this-pointer */
        if (!(corto_typeof(this) == corto_type(corto_function_o))) {
            if (corto_typeof(this) == corto_type(corto_metaprocedure_o)) {
                this->size += sizeof(corto_any);
                args[0] = &corto_ffi_type_any;
            } else {
                this->size += sizeof(corto_object);
                args[0] = &ffi_type_pointer;
            }
            hasThis = 1;
        }

        corto_uint32 i;
        for(i=0; i<this->parameters.length; i++) {
            if (this->parameters.buffer[i].passByReference) {
                this->size += sizeof(corto_word);
                args[i + hasThis] = &ffi_type_pointer;
            } else {
                corto_type paramType = this->parameters.buffer[i].type;
                switch(paramType->kind) {
                case CORTO_ANY:
                    this->size += sizeof(corto_any);
                    args[i + hasThis] = &corto_ffi_type_any;
                    break;
                case CORTO_PRIMITIVE:
                    this->size += corto_type_sizeof(paramType);
                    args[i + hasThis] = corto_ffi_type(paramType);
                    break;
                case CORTO_COLLECTION:
                    if (corto_collection(paramType)->kind == CORTO_SEQUENCE) {
                        this->size += sizeof(corto_objectseq);
                        args[i + hasThis] = &corto_ffi_type_sequence;
                        break;
                    }
                default:
                    this->size += sizeof(void*);
                    args[i + hasThis] = &ffi_type_pointer;
                    break;
                }
            }
        }

        /* Prepare call interface */
        ffi_prep_cif(
            cif,
            FFI_DEFAULT_ABI,
            this->parameters.length + hasThis,
            this->returnsReference ? &ffi_type_pointer : corto_ffi_type(this->returnType),
            args);

        this->fdata = (corto_word)cif;
    }

    /* Bind with interface if possible */
    if (corto_checkAttr(this, CORTO_ATTR_SCOPED)) {
        if (corto_delegate_bind(this)) {
            goto error;
        }
    }

    return 0;
error:
    return -1;
/* $end */
}

/* $header(corto/lang/function/init) */
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
        if ((corto_class_instanceof(corto_procedure_o, corto_typeof(o)))) {
            if (corto_overload(o, corto_idof(data->f), &d)) {
                data->error = TRUE;
                goto finish;
            }

            /* Check if function matches */
            if (!d) {
                corto_id id, id2;
                corto_fullpath(id, data->f);
                corto_fullpath(id2, o);
                if (strcmp(id, id2)) {
                    corto_seterr(
                      "function '%s' conflicts with existing declaration '%s'",
                      id, id2);
                    data->error = TRUE;
                    goto finish;
                }
            } else {
                corto_id id;

                /* Get name of function */
                corto_signatureName(corto_idof(o), id);

                /* Set overloading flags if a function with same name is found. */
                if (!strcmp(data->name, id)) {
                    corto_function(o)->overloaded = TRUE;
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
corto_int16 _corto_function_init(
    corto_function this)
{
/* $begin(corto/lang/function/init) */
    corto_functionLookup_t walkData;
    corto_objectseq scope;
    corto_uint32 i;

    if (corto_checkAttr(this, CORTO_ATTR_SCOPED)) {
        scope = corto_scopeClaim(corto_parentof(this));

        walkData.f = this;
        walkData.error = FALSE;
        corto_signatureName(corto_idof(this), walkData.name);

        for (i = 0; i < scope.length; i++) {
            if (!corto_functionLookupWalk(scope.buffer[i], &walkData)) {
                break;
            }
        }
        if (walkData.error) {
            goto error;
        }

        corto_scopeRelease(scope);

        /* Parse arguments from name */
        if (corto_function_parseParamString(this, corto_idof(this))) {
          goto error;
        }
    }


    return 0;
error:
    this->parameters.length = 0;
    return -1;
/* $end */
}

corto_int16 _corto_function_parseParamString(
    corto_function this,
    corto_string params)
{
/* $begin(corto/lang/function/parseParamString) */
    corto_object scope;

    if (corto_checkAttr(this, CORTO_ATTR_SCOPED)) {
        scope = corto_parentof(this);
    } else {
        scope = root_o;
    }

    if (!this->parameters.length) {
        this->parameters = corto_function_stringToParameterSeq(params, scope);
    }

    return this->parameters.length == (corto_uint32)-1;
/* $end */
}

corto_parameterseq _corto_function_stringToParameterSeq(
    corto_string name,
    corto_object scope)
{
/* $begin(corto/lang/function/stringToParameterSeq) */
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
            count = corto_signatureParamCount(name);
            if (count == -1) {
                goto error;
            }

            /* Allocate size for parameters */
            result.length = count;
            result.buffer = corto_alloc(sizeof(corto_parameter) * count);
            memset(result.buffer, 0, sizeof(corto_parameter) * count);

            /* Parse arguments */
            for(i=0; i<count; i++) {
                if (corto_signatureParamType(name, i, id, &flags)) {
                    corto_seterr(
                        "error occurred while parsing type of parameter '%d' for signature '%s'",
                        i,
                        name);
                    goto error;
                }

                /* Set reference */
                result.buffer[i].passByReference = (flags & CORTO_PARAMETER_REFERENCE) != 0;

                /* Assign type */
                result.buffer[i].type = corto_resolve(scope, id);
                if (!result.buffer[i].type) {
                    corto_seterr("%s: '%s' not found", name, id);
                    goto error;
                }

                /* Validate whether reference is not redundantly applied */
                if (result.buffer[i].passByReference && result.buffer[i].type->reference) {
                    corto_seterr(
                        "redundant '&' qualifier for parameter %d, type '%s' is already a reference",
                        i,
                        corto_fullpath(NULL, result.buffer[i].type));
                    goto error;
                }

                /* Parse name */
                if (corto_signatureParamName(name, i, id)) {
                    corto_seterr(
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
/* $end */
}

corto_void _corto_function_unbind(
    corto_function object)
{
/* $begin(corto/lang/function/unbind) */
    corto_uint32 i;

    /* Deinitialize parameters */
    for(i=0; i<object->parameters.length; i++) {
        corto_dealloc(object->parameters.buffer[i].name);
        object->parameters.buffer[i].name = NULL;
        corto_release(object->parameters.buffer[i].type);
        object->parameters.buffer[i].type = NULL;
    }

    corto_dealloc(object->parameters.buffer);
    object->parameters.buffer = NULL;
/* $end */
}
