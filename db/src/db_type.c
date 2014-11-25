/*
 * db_type.c
 *
 *  Created on: Aug 3, 2012
 *      Author: sander
 */

#include "db_object.h"
#include "db__meta.h"
#include "db_err.h"
#include "db_typedef.h"
#include "db__type.h"
#include "db_class.h"
#include "db_util.h"
#include "db_call.h"
#include "db__interface.h" /* For vtable functions */
#include "db_mem.h"
#include "db_compare_ser.h"
#include "db_copy_ser.h"

static db_uint32 db_type_allocSize_id = 0;
static db_uint32 db_type_compatible_id = 0;
static db_uint32 db_type_castable_id = 0;
static db_delegate db_type_init_d = NULL;

/* type::sizeof() */
db_uint32 db_type_sizeof(db_type _this) {
    db_uint32 size;
    if (_this->reference) {
        size = sizeof(db_object);
    } else {
        size = _this->size;
    }
	return size;
}

/* type::alignmentof() */
db_uint16 db_type_alignmentof(db_type _this) {
	db_uint16 alignment;

	if (_this->reference) {
		alignment = DB_ALIGNMENT(db_object);
	} else {
		alignment = _this->alignment;
	}
	return alignment;
}

/* virtual type::allocSize() */
db_uint32 db_type_allocSize_v(db_type _this) {
	return _this->size;
}

/* type::allocSize */
db_uint32 db_type_allocSize(db_type _this) {
    db_method allocSize;
    db_uint32 result;

    DB_UNUSED(_this);

    result = 0;

    /* Lookup method Id */
    if (!db_type_allocSize_id) {
        db_type_allocSize_id = db_interface_resolveMethodId(db_interface(db_typeof(_this)->real), "allocSize");
    }
    db_assert(db_type_allocSize_id, "type '%s' has no allocSize function.", db_nameof(db_typeof(_this)));

    /* Lookup method */
    allocSize = db_interface_resolveMethodById(db_interface(db_typeof(_this)), db_type_allocSize_id);
    db_assert(allocSize != NULL, "unresolved method '%s::allocSize@%d'", db_nameof(_this), db_type_allocSize_id);

    /* Call function directly if it is a C-function */
    if (allocSize->_parent.kind == DB_PROCEDURE_CDECL) {
    	db_assert(allocSize->_parent.impl, "missing implementationData for type::allocSize");
        result = ((db_uint32(*)(db_object))allocSize->_parent.impl)(_this);
    } else {
        /* db_callMethod */
    }

    return result;
}

/* virtual type::compatible */
db_bool db_type_compatible(db_type _this, db_type type) {
    db_method compatible;
    db_uint32 result;

    DB_UNUSED(_this);

    result = 0;

    /* Lookup method Id */
    if (!db_type_compatible_id) {
        db_type_compatible_id = db_interface_resolveMethodId(db_interface(db_typeof(_this)->real), "compatible");
    }
    db_assert(db_type_compatible_id, "type '%s' has no compatible function.", db_nameof(db_typeof(_this)));

    /* Lookup method */
    compatible = db_interface_resolveMethodById(db_interface(db_typeof(_this)), db_type_compatible_id);
    db_assert(compatible != NULL, "unresolved method '%s::compatible@%d'", db_nameof(_this), db_type_compatible_id);

    /* Call function directly if it is a C-function */
    if (compatible->_parent.kind == DB_PROCEDURE_CDECL) {
        db_assert(compatible->_parent.impl, "missing implementationData for type::compatible");
        result = ((db_bool(*)(db_type,db_type))compatible->_parent.impl)(_this, type);
    } else {
        /* db_callMethod */
    }

    return result;
}

/* type::compatible */
db_bool db_type_compatible_v(db_type _this, db_type type) {
    db_bool result;

    result = FALSE;

    if (_this != type) {
        if (_this->kind == DB_ANY) {
            result = TRUE;
        } else if (_this->reference == type->reference) {
            if (type->reference) {
                if (_this->kind == DB_VOID) {
                    result = TRUE;
                }
            }
        }
    } else {
        result = TRUE;
    }

    return result;
}

/* type::bindMetaprocedure */
db_int16 db_type_bindMetaprocedure(db_type _this, db_metaprocedure procedure) {
    db_function* f;
    db_int32 d = 0;

    /* Check if function is overloaded */
    if ((f = db_vtableLookup(&_this->metaprocedures, db_nameof(procedure), NULL, &d))) {
        if (d) {
            db_function(*f)->overloaded = TRUE; /* Flag found and passed function as overloaded. */
            db_function(procedure)->overloaded = TRUE;
        } else {
            if (*f != db_function(procedure)) {
                /* Overriding metaprocedures is not allowed. */
                db_id id, id2;
                db_error("definition of metaprocedure '%s' conflicts with existing metaprocedure '%s'", db_fullname(*f, id), db_fullname(procedure, id2));
                goto error;
            }
        }
    }

    if (db_vtableInsert(&_this->metaprocedures, db_function(procedure))) {
        db_keep_ext(_this, procedure, "Bind metaprocedure to type.");
    }
    return 0;
error:
    return -1;
}

/* type::resolveProcedure */
db_function db_type_resolveProcedure(db_type _this, db_string name) {
    db_function result = NULL;

    /* If type is an interface, try first to resolve a method on the interface */
    if (db_instanceof((db_typedef)db_interface_o, _this)) {
        result = (db_function)db_interface_resolveMethod(db_interface(_this), name);
    }

    /* If no method is found or type is not an interface, resolve metaprocedure */
    if (!result) {
        db_function *f;
        db_int32 d = 0, prevD = 9999;
        db_class metaclass = db_class(db_typeof(_this)->real);

        /* Walk inheritance of metaclass to find metaprocedure */
        do {
            if ((f = db_vtableLookup(&db_type(metaclass)->metaprocedures, name, NULL, &d))) {
                if (d < prevD) {
                    result = *f;
                    prevD = d;
                }
            }
            metaclass = db_class(db_interface(metaclass)->base);
        }while(metaclass && !result);
    }

    return result;
}

/* virtual ::type::castable */
db_bool db_type_castable(db_type _this, db_type type) {
    db_method castable;
    db_uint32 result;

    DB_UNUSED(_this);

    result = 0;

    /* Lookup method Id */
    if (!db_type_castable_id) {
        db_type_castable_id = db_interface_resolveMethodId(db_interface(db_typeof(_this)->real), "castable");
    }
    db_assert(db_type_castable_id, "type '%s' has no castable function.", db_nameof(db_typeof(_this)));

    /* Lookup method */
    castable = db_interface_resolveMethodById(db_interface(db_typeof(_this)), db_type_castable_id);
    db_assert(castable != NULL, "unresolved method '%s::castable@%d'", db_nameof(_this), db_type_castable_id);

    /* Call function directly if it is a C-function */
    if (castable->_parent.kind == DB_PROCEDURE_CDECL) {
        db_assert(castable->_parent.impl, "missing implementationData for type::castable");
        result = ((db_bool(*)(db_type,db_type))castable->_parent.impl)(_this, type);
    } else {
        /* db_callMethod */
    }

    return result;
}

/* type::castable */
db_bool db_type_castable_v(db_type _this, db_type type) {
    db_bool result = FALSE;

    if (_this->kind == DB_VOID) { /* A void reference can be casted to any reference type */
        if (_this->reference && type->reference) {
            return TRUE;
        }
    }

    if (!result) {
        result = db_type_compatible_v(_this, type);
    }
    
    return result;
}

/* delegate type::init(object o) */
db_int16 db_type_init(db_type _this, db_object object) {
    db_callback init;
    db_uint32 result;

    result = 0;

    /* Resolve ::type::init */
    if (!db_type_init_d) {
        db_type_init_d = db_class_resolveDelegate(db_type_o, "init");
    }

    db_assert(db_type_init_d != NULL, "unresolved delegate '::type::init'");

    /* Lookup delegate in target object */
    init = db_class_resolveCallback(db_type_o, db_type_init_d, _this);
    if (init) {
        /* Call function directly if it is a C-function */
        if (init->_parent.kind == DB_PROCEDURE_CDECL) {
            if (!init->_parent.impl) {
                db_id id;
                db_critical("type::init: callback function '%s' has no implementation.", db_fullname(init, id));
            }
            result = ((db_int16(*)(db_object))init->_parent.impl)(object);
        } else {
            db_call(db_function(init), &result, object);
        }
    }

	return result;
}

#define DB_COMPARE(type,v1,v2) *(type*)v1.value > *(type*)v2.value ? DB_GT : *(type*)v1.value < *(type*)v2.value ? DB_LT : DB_EQ

/* metaprocedure type::compare(any value1, any value2) */
db_equalityKind db_type_compare(db_any _this, db_any value) {
    db_compare_ser_t data;
    struct db_serializer_s s;
    db_value v1;
    
    db_valueValueInit(&v1, NULL, db_typedef(_this.type), _this.value);
    db_valueValueInit(&data.value, NULL, db_typedef(value.type), value.value);
    
    s = db_compare_ser(DB_PRIVATE, DB_NOT, DB_SERIALIZER_TRACE_NEVER);
    
    db_serializeValue(&s, &v1, &data);

    return data.result;
}

/* metaprocedure type::copy(any value1, any value2) */
db_int16 db_type_copy(db_any _this, db_any value) {
    db_copy_ser_t data;
    struct db_serializer_s s;
    db_value v1;
    db_int16 result;
    
    db_valueValueInit(&data.value, NULL, db_typedef(_this.type), _this.value);
    db_valueValueInit(&v1, NULL, db_typedef(value.type), value.value);
    
    s = db_copy_ser(DB_PRIVATE, DB_NOT, DB_SERIALIZER_TRACE_ON_FAIL);
    
    result = db_serializeValue(&s, &v1, &data);
    
    if (result) {
        db_id id, id2;
        db_error("type::copy: failed to copy value of type '%s' to value of type '%s'",
                 db_fullname(_this.type, id), db_fullname(value.type, id2));
    }
    
    return result;
}

/* type::init -> type::init */
db_int16 db_type__init(db_type object) {
	db_keep_ext(object, object, "Keep self for type-member");
    db_typedef(object)->type = (db_typedef)object;
    return db_typedef_init(db_typedef(object));
}

/* class::construct -> type::construct */
db_int16 db_type_construct(db_type object) {
	switch(object->kind) {
	case DB_ANY:
		object->size = sizeof(db_any);
		break;
	default:
		break;
	}
	return db_typedef_construct(db_typedef(object));
}

/* class::destruct -> type::destruct */
void db_type__destruct(db_type object) {
    db_uint32 i;

    object->_parent.type = NULL;
    db_free_ext(object, object, "Free self for type-member");

    /* Free methods */
    for(i=0; i<object->metaprocedures.length; i++) {
        db_free_ext(object, object->metaprocedures.buffer[i], "Remove method from vtable.");
    }

    if (object->metaprocedures.buffer) {
        db_dealloc(object->metaprocedures.buffer);
        object->metaprocedures.buffer = NULL;
    }

    db_typedef_destruct(db_typedef(object));
}

/* metaprocedure type::nameof */
db_string db_type_nameof(db_any object) {
	db_string result = NULL;

	if (object.value) {
		result = db_nameof(object.value);
        if(result) {
            result = db_strdup(result);
        }
	} else {
		result = db_strdup("null");
	}

	return result;
}

db_string db_type_fullname(db_any object) {
    db_string result = NULL;

	if (object.value) {
		db_id id;
		result = db_strdup(db_fullname(object.value, id));
	} else {
		result = db_strdup("null");
	}

    return result;
}

db_string db_type_relname(db_any object, db_object from) {
    db_string result = NULL;
	db_id id;

	if (object.value) {
		result = db_strdup(db_relname(from, object.value, id));
	} else {
		result = db_strdup("null");
	}

    return result;
}

db_type db_type_typeof(db_any object) {
    db_type result = NULL;

    result = object.type;
    
    if (result) {
        db_keep(result);
    }

    return result;
}

db_object db_type_parentof(db_any object) {
    db_string result = NULL;

   if (db_checkAttr(object.value, DB_ATTR_SCOPED)) {
	   result = db_parentof(object.value);
   } else {
	   db_id id;
	   db_error("cannot get parent from non-scoped object of type '%s'", db_fullname(db_typeof(object.value), id));
   }
    
   if (result) {
       db_keep(result);
   }

   return result;
}

db_string db_type_toString(db_any object) {
    db_value value;
    db_string result;

    if (object.value) {
        if (object.type->reference) {
            db_valueObjectInit(&value, object.value);
        } else {
            db_valueValueInit(&value, NULL, db_typedef(object.type), object.value);
        }
        result = db_valueToString(&value, 0);
    } else {
        result = db_strdup("null");
    }

    return result;
}

db_object db_type_declare(db_any object, db_string name, db_typedef type) {
    db_object result = db_declare(object.value, name, type);
    db_keep(result);
    return result;
}

void db_type_destruct(db_any object) {
    db_destruct(object.value);
}

db_int16 db_type_define(db_any object) {
    return db_define(object.value);
}

db_object db_type_resolve(db_any object, db_string name) {
    return db_resolve(object.value, name);
}

db_object db_type_lookup(db_any object, db_string name) {
    return db_lookup(object.value, name);
}

db_bool db_type_checkAttr(db_any object, db_attr attributes) {
    return db_checkAttr(object.value, attributes);
}

db_bool db_type_checkState(db_any object, db_state state) {
    return db_checkState(object.value, state);
}



