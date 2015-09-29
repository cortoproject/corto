/* cx_type.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "cx.h"

/* $header() */
#include "cx_compare_ser.h"
#include "cx_copy_ser.h"
#include "cx__interface.h"

cx_int16 cx_type_bindMetaprocedure(cx_type this, cx_metaprocedure procedure) {
    cx_function* f;
    cx_int32 d = 0;

    /* Check if function is overloaded */
    if ((f = cx_vtableLookup(&this->metaprocedures, cx_nameof(procedure), &d))) {
        if (d) {
            cx_function(*f)->overloaded = TRUE; /* Flag found and passed function as overloaded. */
            cx_function(procedure)->overloaded = TRUE;
        } else {
            if (*f != cx_function(procedure)) {
                /* Overriding metaprocedures is not allowed. */
                cx_id id, id2;
                cx_error("definition of metaprocedure '%s' conflicts with existing metaprocedure '%s'", cx_fullname(*f, id), cx_fullname(procedure, id2));
                goto error;
            }
        }
    }

    if (cx_vtableInsert(&this->metaprocedures, cx_function(procedure))) {
        cx_claim(procedure);
    }
    return 0;
error:
    return -1;
}
/* $end */

/* ::corto::lang::type::alignmentof() */
cx_uint16 _cx_type_alignmentof(cx_type this) {
/* $begin(::corto::lang::type::alignmentof) */
    cx_uint16 alignment;

    if (this->reference) {
        alignment = CX_ALIGNMENT(cx_object);
    } else {
        alignment = this->alignment;
    }
    return alignment;
/* $end */
}

/* ::corto::lang::type::allocSize() */
cx_uint32 _cx_type_allocSize_v(cx_type this) {
/* $begin(::corto::lang::type::allocSize) */
    return this->size;
/* $end */
}

/* ::corto::lang::type::castable(type type) */
cx_bool _cx_type_castable_v(cx_type this, cx_type type) {
/* $begin(::corto::lang::type::castable) */
    cx_bool result = FALSE;

    if (this->kind == CX_VOID) { /* A void reference can be casted to any reference type */
        if (this->reference && type->reference) {
            return TRUE;
        }
    }

    if (!result) {
        result = cx_type_compatible_v(this, type);
    }
    
    return result;
/* $end */
}

/* ::corto::lang::type::checkAttr(attr attributes) */
cx_bool _cx_type_checkAttr(cx_any this, cx_attr attributes) {
/* $begin(::corto::lang::type::checkAttr) */
    return cx_checkAttr(this.value, attributes);
/* $end */
}

/* ::corto::lang::type::checkState(state state) */
cx_bool _cx_type_checkState(cx_any this, cx_state state) {
/* $begin(::corto::lang::type::checkState) */
    return cx_checkState(this.value, state);
/* $end */
}

/* ::corto::lang::type::compare(any value) */
cx_equalityKind _cx_type_compare(cx_any this, cx_any value) {
/* $begin(::corto::lang::type::compare) */
    cx_compare_ser_t data;
    struct cx_serializer_s s;
    cx_value v1;
    
    cx_valueValueInit(&v1, NULL, cx_type(this.type), this.value);
    cx_valueValueInit(&data.value, NULL, cx_type(value.type), value.value);
    
    s = cx_compare_ser(CX_PRIVATE, CX_NOT, CX_SERIALIZER_TRACE_NEVER);

    cx_serializeValue(&s, &v1, &data);

    return data.result;
/* $end */
}

/* ::corto::lang::type::compatible(type type) */
cx_bool _cx_type_compatible_v(cx_type this, cx_type type) {
/* $begin(::corto::lang::type::compatible) */
    cx_bool result;

    result = FALSE;

    if (this != type) {
        if (this->kind == CX_ANY) {
            result = TRUE;
        } else if (this->reference == type->reference) {
            if (type->reference) {
                if (this->kind == CX_VOID) {
                    result = TRUE;
                }
            }
        }
    } else {
        result = TRUE;
    }

    return result;
/* $end */
}

/* ::corto::lang::type::construct() */
cx_int16 _cx_type_construct(cx_type this) {
/* $begin(::corto::lang::type::construct) */
    switch(this->kind) {
    case CX_ANY:
        this->size = sizeof(cx_any);
        this->alignment = CX_ALIGNMENT(cx_any);
        break;
    default:
        break;
    }
    return 0;
/* $end */
}

/* ::corto::lang::type::copy(any value) */
cx_int16 _cx_type_copy(cx_any this, cx_any value) {
/* $begin(::corto::lang::type::copy) */
    cx_copy_ser_t data;
    struct cx_serializer_s s;
    cx_value v1;
    cx_int16 result;

    if (this.type->reference || value.type->reference) {
        cx_valueObjectInit(&data.value, this.value, NULL);
        cx_valueObjectInit(&v1, value.value, NULL);       
    } else {
        cx_valueValueInit(&data.value, NULL, cx_type(this.type), this.value);
        cx_valueValueInit(&v1, NULL, cx_type(value.type), value.value);
    }
    
    s = cx_copy_ser(CX_PRIVATE, CX_NOT, CX_SERIALIZER_TRACE_ON_FAIL);
    
    result = cx_serializeValue(&s, &v1, &data);

    if (result) {
        cx_id id, id2;
        cx_error("type::copy: failed to copy value of type '%s' to value of type '%s'",
                 cx_fullname(this.type, id), cx_fullname(value.type, id2));
    }
    
    return result;
/* $end */
}

/* ::corto::lang::type::declare(string name,type type) */
cx_object _cx_type_declare(cx_any this, cx_string name, cx_type type) {
/* $begin(::corto::lang::type::declare) */
    cx_object result = cx_declareChild(this.value, name, type);
    cx_claim(result);
    return result;
/* $end */
}

/* ::corto::lang::type::define() */
cx_int16 _cx_type_define(cx_any this) {
/* $begin(::corto::lang::type::define) */
    return cx_define(this.value);
/* $end */
}

/* ::corto::lang::type::delete() */
cx_void _cx_type_delete(cx_any this) {
/* $begin(::corto::lang::type::delete) */
    cx_delete(this.value);
/* $end */
}

/* ::corto::lang::type::destruct() */
cx_void _cx_type_destruct(cx_type this) {
/* $begin(::corto::lang::type::destruct) */
    cx_uint32 i;

    /* Free methods */
    for(i=0; i<this->metaprocedures.length; i++) {
        cx_release(this->metaprocedures.buffer[i]);
    }

    if (this->metaprocedures.buffer) {
        cx_dealloc(this->metaprocedures.buffer);
        this->metaprocedures.buffer = NULL;
    }
/* $end */
}

/* ::corto::lang::type::fullname() */
cx_string _cx_type_fullname(cx_any this) {
/* $begin(::corto::lang::type::fullname) */
    cx_string result = NULL;

    if (this.value) {
        cx_id id;
        result = cx_strdup(cx_fullname(this.value, id));
    } else {
        result = cx_strdup("null");
    }

    return result;
/* $end */
}

/* ::corto::lang::type::init() */
cx_int16 _cx_type_init(cx_type this) {
/* $begin(::corto::lang::type::init) */
    if (!this->parentState) {
        this->parentState = CX_DECLARED | CX_DEFINED;
    }
    return 0;
/* $end */
}

/* ::corto::lang::type::instanceof(type type) */
cx_bool _cx_type_instanceof(cx_any this, cx_type type) {
/* $begin(::corto::lang::type::instanceof) */
    return cx_instanceof(type, this.value);
/* $end */
}

/* ::corto::lang::type::invalidate() */
cx_void _cx_type_invalidate(cx_any this) {
/* $begin(::corto::lang::type::invalidate) */
    cx_invalidate(this.value);
/* $end */
}

/* ::corto::lang::type::lookup(string name) */
cx_object _cx_type_lookup(cx_any this, cx_string name) {
/* $begin(::corto::lang::type::lookup) */
    return cx_lookup(this.value, name);
/* $end */
}

/* ::corto::lang::type::nameof() */
cx_string _cx_type_nameof(cx_any this) {
/* $begin(::corto::lang::type::nameof) */
    cx_string result = NULL;

    if (this.value) {
        result = cx_nameof(this.value);
        if(result) {
            result = cx_strdup(result);
        }
    } else {
        result = cx_strdup("null");
    }

    return result;
/* $end */
}

/* ::corto::lang::type::parentof() */
cx_object _cx_type_parentof(cx_any this) {
/* $begin(::corto::lang::type::parentof) */
    cx_string result = NULL;

   if (cx_checkAttr(this.value, CX_ATTR_SCOPED)) {
       result = cx_parentof(this.value);
   } else {
       cx_id id;
       cx_error("cannot get parent from non-scoped object of type '%s'", cx_fullname(cx_typeof(this.value), id));
   }
    
   if (result) {
       cx_claim(result);
   }

   return result;
/* $end */
}

/* ::corto::lang::type::relname(object from) */
cx_string _cx_type_relname(cx_any this, cx_object from) {
/* $begin(::corto::lang::type::relname) */
    cx_string result = NULL;
    cx_id id;

    if (this.value) {
        result = cx_strdup(cx_relname(from, this.value, id));
    } else {
        result = cx_strdup("null");
    }

    return result;
/* $end */
}

/* ::corto::lang::type::resolve(string name) */
cx_object _cx_type_resolve(cx_any this, cx_string name) {
/* $begin(::corto::lang::type::resolve) */
    return cx_resolve(this.value, name);
/* $end */
}

/* ::corto::lang::type::resolveProcedure(string name) */
cx_function _cx_type_resolveProcedure(cx_type this, cx_string name) {
/* $begin(::corto::lang::type::resolveProcedure) */
    cx_function result = NULL;

    /* If type is an interface, try first to resolve a method on the interface */
    if (cx_instanceof((cx_type)cx_interface_o, this)) {
        result = (cx_function)cx_interface_resolveMethod(cx_interface(this), name);
    }

    /* If no method is found or type is not an interface, resolve metaprocedure */
    if (!result) {
        cx_function *f;
        cx_int32 d = 0, prevD = 9999;
        cx_class metaclass = cx_class(cx_typeof(this));

        /* Walk inheritance of metaclass to find metaprocedure */
        do {
            if ((f = cx_vtableLookup(&cx_type(metaclass)->metaprocedures, name, &d))) {
                if (d < prevD) {
                    result = *f;
                    prevD = d;
                }
            }
            metaclass = cx_class(cx_interface(metaclass)->base);
        }while(metaclass && !result);
    }

    return result;
/* $end */
}

/* ::corto::lang::type::sizeof() */
cx_uint32 _cx_type_sizeof(cx_type this) {
/* $begin(::corto::lang::type::sizeof) */
    cx_uint32 size;
    if (this->reference) {
        size = sizeof(cx_object);
    } else {
        size = this->size;
    }
    return size;
/* $end */
}

/* ::corto::lang::type::toString() */
cx_string _cx_type_toString(cx_any this) {
/* $begin(::corto::lang::type::toString) */
    cx_value value;
    cx_string result;

    if (this.value) {
        if (this.type->reference) {
            cx_valueObjectInit(&value, this.value, NULL);
        } else {
            cx_valueValueInit(&value, NULL, this.type, this.value);
        }
        result = cx_strv(&value, 0);
    } else {
        result = cx_strdup("null");
    }

    return result;
/* $end */
}

/* ::corto::lang::type::typeof() */
cx_type _cx_type_typeof(cx_any this) {
/* $begin(::corto::lang::type::typeof) */
    cx_type result = NULL;

    result = this.type;
    
    if (result) {
        cx_claim(result);
    }

    return result;
/* $end */
}
