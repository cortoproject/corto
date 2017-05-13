/* Copyright (c) 2010-2017 the corto developers
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include "cdeclhandler.h"
#include "_object.h"

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

static ffi_type* corto_ffi_type(corto_type t) {
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

corto_int16 corto_cdeclInit(corto_function this) {
    corto_uint32 argsSize = sizeof(ffi_type*) * (this->parameters.length + 1);
    ffi_cif *cif = corto_alloc(sizeof(ffi_cif) + argsSize);
    ffi_type **args = CORTO_OFFSET(cif, sizeof(ffi_cif));
    corto_uint8 hasThis = 0;


    /* Add size of this-pointer */
    corto_procedure procedure = corto_function_getProcedureType(this);

    /* Add size of this-pointer */
    if (procedure->hasThis) {
        if (procedure->thisType == corto_any_o) {
            args[0] = &corto_ffi_type_any;
        } else {
            args[0] = &ffi_type_pointer;
        }
        hasThis = 1;
    }

    corto_uint32 i;
    for(i = 0; i < this->parameters.length; i++) {
        if (this->parameters.buffer[i].passByReference) {
            args[i + hasThis] = &ffi_type_pointer;
        } else {
            corto_type paramType = this->parameters.buffer[i].type;
            switch(paramType->kind) {
            case CORTO_ANY:
                args[i + hasThis] = &corto_ffi_type_any;
                break;
            case CORTO_PRIMITIVE:
                args[i + hasThis] = corto_ffi_type(paramType);
                break;
            case CORTO_COLLECTION:
                if (corto_collection(paramType)->kind == CORTO_SEQUENCE) {
                    args[i + hasThis] = &corto_ffi_type_sequence;
                    break;
                }
            default:
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
    this->impl = (corto_word)ffi_call;

    return 0;
}

void corto_cdeclDeinit(corto_function f) {
    corto_dealloc((void*)f->fdata);
}
