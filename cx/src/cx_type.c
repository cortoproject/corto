/* cx_type.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "cx.h"
#include "cx__meta.h"

/* $header() */
#include "cx_compare_ser.h"
#include "cx_copy_ser.h"
#include "cx__interface.h"

cx_int16 cx_type_bindMetaprocedure(cx_type _this, cx_metaprocedure procedure) {
    cx_function* f;
    cx_int32 d = 0;

    /* Check if function is overloaded */
    if ((f = cx_vtableLookup(&_this->metaprocedures, cx_nameof(procedure), NULL, &d))) {
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

    if (cx_vtableInsert(&_this->metaprocedures, cx_function(procedure))) {
        cx_keep_ext(_this, procedure, "Bind metaprocedure to type.");
    }
    return 0;
error:
    return -1;
}
/* $end */

/* ::cortex::lang::type::alignmentof() */
cx_uint16 cx_type_alignmentof(cx_type _this) {
/* $begin(::cortex::lang::type::alignmentof) */
    cx_uint16 alignment;

    if (_this->reference) {
        alignment = CX_ALIGNMENT(cx_object);
    } else {
        alignment = _this->alignment;
    }
    return alignment;
/* $end */
}

/* ::cortex::lang::type::allocSize() */
cx_uint32 cx_type_allocSize_v(cx_type _this) {
/* $begin(::cortex::lang::type::allocSize) */
    return _this->size;
/* $end */
}

/* ::cortex::lang::type::castable(type type) */
cx_bool cx_type_castable_v(cx_type _this, cx_type type) {
/* $begin(::cortex::lang::type::castable) */
    cx_bool result = FALSE;

    if (_this->kind == CX_VOID) { /* A void reference can be casted to any reference type */
        if (_this->reference && type->reference) {
            return TRUE;
        }
    }

    if (!result) {
        result = cx_type_compatible_v(_this, type);
    }
    
    return result;
/* $end */
}

/* ::cortex::lang::type::checkAttr(attr attributes) */
cx_bool cx_type_checkAttr(cx_any _this, cx_attr attributes) {
/* $begin(::cortex::lang::type::checkAttr) */
    return cx_checkAttr(_this.value, attributes);
/* $end */
}

/* ::cortex::lang::type::checkState(state state) */
cx_bool cx_type_checkState(cx_any _this, cx_state state) {
/* $begin(::cortex::lang::type::checkState) */
    return cx_checkState(_this.value, state);
/* $end */
}

/* ::cortex::lang::type::compare(any value) */
cx_equalityKind cx_type_compare(cx_any _this, cx_any value) {
/* $begin(::cortex::lang::type::compare) */
    cx_compare_ser_t data;
    struct cx_serializer_s s;
    cx_value v1;
    
    cx_valueValueInit(&v1, NULL, cx_type(_this.type), _this.value);
    cx_valueValueInit(&data.value, NULL, cx_type(value.type), value.value);
    
    s = cx_compare_ser(CX_PRIVATE, CX_NOT, CX_SERIALIZER_TRACE_NEVER);

    cx_serializeValue(&s, &v1, &data);

    return data.result;
/* $end */
}

/* ::cortex::lang::type::compatible(type type) */
cx_bool cx_type_compatible_v(cx_type _this, cx_type type) {
/* $begin(::cortex::lang::type::compatible) */
    cx_bool result;

    result = FALSE;

    if (_this != type) {
        if (_this->kind == CX_ANY) {
            result = TRUE;
        } else if (_this->reference == type->reference) {
            if (type->reference) {
                if (_this->kind == CX_VOID) {
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

/* ::cortex::lang::type::construct() */
cx_int16 cx_type_construct(cx_type _this) {
/* $begin(::cortex::lang::type::construct) */
    switch(_this->kind) {
    case CX_ANY:
        _this->size = sizeof(cx_any);
        break;
    default:
        break;
    }
    return 0;
/* $end */
}

/* ::cortex::lang::type::copy(any value) */
cx_int16 cx_type_copy(cx_any _this, cx_any value) {
/* $begin(::cortex::lang::type::copy) */
    cx_copy_ser_t data;
    struct cx_serializer_s s;
    cx_value v1;
    cx_int16 result;

    if (_this.type->reference || value.type->reference) {
        cx_valueObjectInit(&data.value, _this.value);
        cx_valueObjectInit(&v1, value.value);       
    } else {
        cx_valueValueInit(&data.value, NULL, cx_type(_this.type), _this.value);
        cx_valueValueInit(&v1, NULL, cx_type(value.type), value.value);
    }
    
    s = cx_copy_ser(CX_PRIVATE, CX_NOT, CX_SERIALIZER_TRACE_ON_FAIL);
    
    result = cx_serializeValue(&s, &v1, &data);

    if (result) {
        cx_id id, id2;
        cx_error("type::copy: failed to copy value of type '%s' to value of type '%s'",
                 cx_fullname(_this.type, id), cx_fullname(value.type, id2));
    }
    
    return result;
/* $end */
}

/* ::cortex::lang::type::declare(string name,type type) */
cx_object cx_type_declare(cx_any _this, cx_string name, cx_type type) {
/* $begin(::cortex::lang::type::declare) */
    cx_object result = cx_declare(_this.value, name, type);
    cx_keep(result);
    return result;
/* $end */
}

/* ::cortex::lang::type::define() */
cx_int16 cx_type_define(cx_any _this) {
/* $begin(::cortex::lang::type::define) */
    return cx_define(_this.value);
/* $end */
}

/* ::cortex::lang::type::destruct() */
cx_void cx_type_destruct(cx_type _this) {
/* $begin(::cortex::lang::type::destruct) */
    cx_uint32 i;

    /* Free methods */
    for(i=0; i<_this->metaprocedures.length; i++) {
        cx_free_ext(_this, _this->metaprocedures.buffer[i], "Remove method from vtable.");
    }

    if (_this->metaprocedures.buffer) {
        cx_dealloc(_this->metaprocedures.buffer);
        _this->metaprocedures.buffer = NULL;
    }
/* $end */
}

/* ::cortex::lang::type::fullname() */
cx_string cx_type_fullname(cx_any _this) {
/* $begin(::cortex::lang::type::fullname) */
    cx_string result = NULL;

    if (_this.value) {
        cx_id id;
        result = cx_strdup(cx_fullname(_this.value, id));
    } else {
        result = cx_strdup("null");
    }

    return result;
/* $end */
}

/* ::cortex::lang::type::init() */
cx_int16 cx_type_init(cx_type _this) {
/* $begin(::cortex::lang::type::init) */
    if (!_this->parentState) {
        _this->parentState = CX_DECLARED | CX_DEFINED;
    }
    return 0;
/* $end */
}

/* ::cortex::lang::type::instanceof(type type) */
cx_bool cx_type_instanceof(cx_any _this, cx_type type) {
/* $begin(::cortex::lang::type::instanceof) */
    return cx_instanceof(type, _this.value);
/* $end */
}

/* ::cortex::lang::type::invalidate() */
cx_void cx_type_invalidate(cx_any _this) {
/* $begin(::cortex::lang::type::invalidate) */
    cx_invalidate(_this.value);
/* $end */
}

/* ::cortex::lang::type::lookup(string name) */
cx_object cx_type_lookup(cx_any _this, cx_string name) {
/* $begin(::cortex::lang::type::lookup) */
    return cx_lookup(_this.value, name);
/* $end */
}

/* ::cortex::lang::type::nameof() */
cx_string cx_type_nameof(cx_any _this) {
/* $begin(::cortex::lang::type::nameof) */
    cx_string result = NULL;

    if (_this.value) {
        result = cx_nameof(_this.value);
        if(result) {
            result = cx_strdup(result);
        }
    } else {
        result = cx_strdup("null");
    }

    return result;
/* $end */
}

/* ::cortex::lang::type::parentof() */
cx_object cx_type_parentof(cx_any _this) {
/* $begin(::cortex::lang::type::parentof) */
    cx_string result = NULL;

   if (cx_checkAttr(_this.value, CX_ATTR_SCOPED)) {
       result = cx_parentof(_this.value);
   } else {
       cx_id id;
       cx_error("cannot get parent from non-scoped object of type '%s'", cx_fullname(cx_typeof(_this.value), id));
   }
    
   if (result) {
       cx_keep(result);
   }

   return result;
/* $end */
}

/* ::cortex::lang::type::relname(object from) */
cx_string cx_type_relname(cx_any _this, cx_object from) {
/* $begin(::cortex::lang::type::relname) */
    cx_string result = NULL;
    cx_id id;

    if (_this.value) {
        result = cx_strdup(cx_relname(from, _this.value, id));
    } else {
        result = cx_strdup("null");
    }

    return result;
/* $end */
}

/* ::cortex::lang::type::resolve(string name) */
cx_object cx_type_resolve(cx_any _this, cx_string name) {
/* $begin(::cortex::lang::type::resolve) */
    return cx_resolve(_this.value, name);
/* $end */
}

/* ::cortex::lang::type::resolveProcedure(string name) */
cx_function cx_type_resolveProcedure(cx_type _this, cx_string name) {
/* $begin(::cortex::lang::type::resolveProcedure) */
    cx_function result = NULL;

    /* If type is an interface, try first to resolve a method on the interface */
    if (cx_instanceof((cx_type)cx_interface_o, _this)) {
        result = (cx_function)cx_interface_resolveMethod(cx_interface(_this), name);
    }

    /* If no method is found or type is not an interface, resolve metaprocedure */
    if (!result) {
        cx_function *f;
        cx_int32 d = 0, prevD = 9999;
        cx_class metaclass = cx_class(cx_typeof(_this));

        /* Walk inheritance of metaclass to find metaprocedure */
        do {
            if ((f = cx_vtableLookup(&cx_type(metaclass)->metaprocedures, name, NULL, &d))) {
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

/* ::cortex::lang::type::sizeof() */
cx_uint32 cx_type_sizeof(cx_type _this) {
/* $begin(::cortex::lang::type::sizeof) */
    cx_uint32 size;
    if (_this->reference) {
        size = sizeof(cx_object);
    } else {
        size = _this->size;
    }
    return size;
/* $end */
}

/* ::cortex::lang::type::toString() */
cx_string cx_type_toString(cx_any _this) {
/* $begin(::cortex::lang::type::toString) */
    cx_value value;
    cx_string result;

    if (_this.value) {
        if (_this.type->reference) {
            cx_valueObjectInit(&value, _this.value);
        } else {
            cx_valueValueInit(&value, NULL, _this.type, _this.value);
        }
        result = cx_valueToString(&value, 0);
    } else {
        result = cx_strdup("null");
    }

    return result;
/* $end */
}

/* ::cortex::lang::type::typeof() */
cx_type cx_type_typeof(cx_any _this) {
/* $begin(::cortex::lang::type::typeof) */
    cx_type result = NULL;

    result = _this.type;
    
    if (result) {
        cx_keep(result);
    }

    return result;
/* $end */
}
