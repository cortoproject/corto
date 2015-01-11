/* cx_procptr.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "cx.h"
#include "cx__meta.h"

/* ::cortex::lang::procptr::bind(function object) */
cx_int16 cx_procptr_bind(cx_function object) {
/* $begin(::cortex::lang::procptr::bind) */
    cx_object parent = cx_parentof(object);
    cx_bool mustBind = FALSE;

    if (cx_class_instanceof(cx_interface_o, cx_typeof(parent))) {
        cx_interface type = cx_interface(cx_typeof(parent)->real);
        cx_id functionName;
        cx_member m = NULL;

        /* Get function name, lookup delegate, assign function */
        cx_signatureName(cx_nameof(object), functionName);
        if (cx_checkState(cx_type_o, CX_DEFINED) && (m = cx_interface_resolveMember(type, functionName)) &&
            (m->type->real->kind == CX_COMPOSITE) && (cx_interface(m->type->real)->kind == CX_PROCPTR)) {
            if (cx_procptr_instanceof(cx_procptr(m->type), object)) {
                /* Bind instance of function is a method */
                if (cx_procedure(cx_typeof(object))->kind == CX_METHOD) {
                    cx_set(&((cx_procptrdata *) CX_OFFSET(parent, m->offset))->instance, parent);
                }
                /* Bind procedure */
                cx_set(&((cx_procptrdata *) CX_OFFSET(parent, m->offset))->procedure, object);    
            } else {
                /* If there is a member that corresponds to a delegate but has a non matching
                 * signature, always report error */
                cx_id id1, id2;
                cx_error("member '%s' of delegate type '%s' does not match signature of '%s'",
                    cx_nameof(m), cx_fullname(m->type, id1), cx_fullname(object, id2));
                goto error;
            }
        }
    }

    return 0;
error:
    return -1;
/* $end */
}

/* ::cortex::lang::procptr::castable(type type) */
cx_bool cx_procptr_castable_v(cx_procptr _this, cx_type type) {
/* $begin(::cortex::lang::procptr::castable) */
    return cx_procptr_compatible_v(_this, type);
/* $end */
}

/* ::cortex::lang::procptr::compatible(type type) */
cx_bool cx_procptr_compatible_v(cx_procptr _this, cx_type type) {
/* $begin(::cortex::lang::procptr::compatible) */
    cx_bool result = FALSE;
    CX_UNUSED(_this);

    if((type->kind == CX_COMPOSITE) && (cx_interface(type)->kind == CX_PROCPTR)) {
        cx_uint32 i;
        result = TRUE;

        /* Validate returntype */
        if((_this->returnType != cx_procptr(type)->returnType) || (_this->returnsReference != cx_procptr(type)->returnsReference)) {
            result = FALSE;
        }

        /* Validate number of parameters */
        if(_this->parameters.length != cx_procptr(type)->parameters.length) {
            result = FALSE;
        }

        /* Validate parameters */
        for(i = 0; !result && (i < _this->parameters.length); i++) {
            if(_this->parameters.buffer[i].type != cx_procptr(type)->parameters.buffer[i].type) {
                result = FALSE;
            }
            if(_this->parameters.buffer[i].passByReference != cx_procptr(type)->parameters.buffer[i].passByReference) {
                result = FALSE;
            }
        }   
    } else if ((type->kind == CX_COMPOSITE) && (cx_interface(type)->kind == CX_PROCEDURE)) {
        result = TRUE;
    }

    return result;
/* $end */
}

/* callback ::cortex::lang::type::init(object object) -> ::cortex::lang::procptr::init(procptr object) */
cx_int16 cx_procptr_init(cx_procptr object) {
/* $begin(::cortex::lang::procptr::init) */
    cx_int16 result;

    cx_interface(object)->base = cx_interface(cx_procptrdata_o);

    result = cx_struct_init(cx_struct(object));
    if(result) {
        goto error;
    }

    cx_interface(object)->kind = CX_PROCPTR;

    return 0;
error:
    return -1;
/* $end */
}

/* ::cortex::lang::procptr::instanceof(object object) */
/* $header(::cortex::lang::procptr::instanceof) */
cx_bool cx_procptr_matchParameter(
    cx_type t1, 
    cx_bool isRef1, 
    cx_type t2, 
    cx_bool isRef2) {

    if ((t1 != t2) || (isRef1 && !isRef2)) {
        return FALSE;
    } else {
        return TRUE;
    }
}
/* $end */
cx_bool cx_procptr_instanceof(cx_procptr _this, cx_object object) {
/* $begin(::cortex::lang::procptr::instanceof) */
    cx_type t = cx_typeof(object)->real;
    cx_bool result = TRUE;

    if ((t->kind == CX_COMPOSITE) && (cx_interface(t)->kind == CX_PROCEDURE)) {
        cx_function call = object;
        cx_uint32 i;

        /* Validate returntype */
        if (!cx_procptr_matchParameter(
            _this->returnType->real,
            _this->returnsReference,
            call->returnType->real,
            call->returnsReference)) {
            result = FALSE;
        }

        /* Validate number of parameters */
        if (_this->parameters.length != call->parameters.length) {
            result = FALSE;
        }

        /* Validate parameters */
        for (i = 0; i < _this->parameters.length; i++) {
            cx_parameter *p1, *p2;
            p1 = &_this->parameters.buffer[i];
            p2 = &call->parameters.buffer[i];
            
            if (!cx_procptr_matchParameter(
                p1->type->real,
                p1->passByReference,
                p2->type->real,
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
