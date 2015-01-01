/* db_type.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "db.h"
#include "db__meta.h"

/* $header() */
#include "db_compare_ser.h"
#include "db_copy_ser.h"
#include "db__interface.h"

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
/* $end */

/* callback ::cortex::lang::class::destruct(lang::object object) -> ::cortex::lang::type::_destruct(lang::type object) */
db_void db_type__destruct(db_type object) {
/* $begin(::cortex::lang::type::_destruct) */
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
/* $end */
}

/* callback ::cortex::lang::type::init(lang::object object) -> ::cortex::lang::type::_init(lang::type object) */
db_int16 db_type__init(db_type object) {
/* $begin(::cortex::lang::type::_init) */
    db_keep_ext(object, object, "Keep self for type-member");
    db_typedef(object)->type = (db_typedef)object;
    return db_typedef_init(db_typedef(object));
/* $end */
}

/* ::cortex::lang::type::alignmentof() */
db_uint16 db_type_alignmentof(db_type _this) {
/* $begin(::cortex::lang::type::alignmentof) */
    db_uint16 alignment;

    if (_this->reference) {
        alignment = DB_ALIGNMENT(db_object);
    } else {
        alignment = _this->alignment;
    }
    return alignment;
/* $end */
}

/* ::cortex::lang::type::allocSize() */
db_uint32 db_type_allocSize_v(db_type _this) {
/* $begin(::cortex::lang::type::allocSize) */
    return _this->size;
/* $end */
}

/* ::cortex::lang::type::castable(lang::type type) */
db_bool db_type_castable_v(db_type _this, db_type type) {
/* $begin(::cortex::lang::type::castable) */
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
/* $end */
}

/* ::cortex::lang::type::checkAttr(lang::attr attributes) */
db_bool db_type_checkAttr(db_any _this, db_attr attributes) {
/* $begin(::cortex::lang::type::checkAttr) */
    return db_checkAttr(_this.value, attributes);
/* $end */
}

/* ::cortex::lang::type::checkState(lang::state state) */
db_bool db_type_checkState(db_any _this, db_state state) {
/* $begin(::cortex::lang::type::checkState) */
    return db_checkState(_this.value, state);
/* $end */
}

/* ::cortex::lang::type::compare(lang::any value) */
db_equalityKind db_type_compare(db_any _this, db_any value) {
/* $begin(::cortex::lang::type::compare) */
    db_compare_ser_t data;
    struct db_serializer_s s;
    db_value v1;
    
    db_valueValueInit(&v1, NULL, db_typedef(_this.type), _this.value);
    db_valueValueInit(&data.value, NULL, db_typedef(value.type), value.value);
    
    s = db_compare_ser(DB_PRIVATE, DB_NOT, DB_SERIALIZER_TRACE_NEVER);

    db_serializeValue(&s, &v1, &data);

    return data.result;
/* $end */
}

/* ::cortex::lang::type::compatible(lang::type type) */
db_bool db_type_compatible_v(db_type _this, db_type type) {
/* $begin(::cortex::lang::type::compatible) */
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
/* $end */
}

/* callback ::cortex::lang::class::construct(lang::object object) -> ::cortex::lang::type::construct(lang::type object) */
db_int16 db_type_construct(db_type object) {
/* $begin(::cortex::lang::type::construct) */
    switch(object->kind) {
    case DB_ANY:
        object->size = sizeof(db_any);
        break;
    default:
        break;
    }
    return db_typedef_construct(db_typedef(object));
/* $end */
}

/* ::cortex::lang::type::copy(lang::any value) */
db_int16 db_type_copy(db_any _this, db_any value) {
/* $begin(::cortex::lang::type::copy) */
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
/* $end */
}

/* ::cortex::lang::type::declare(lang::string name,lang::typedef type) */
db_object db_type_declare(db_any _this, db_string name, db_typedef type) {
/* $begin(::cortex::lang::type::declare) */
    db_object result = db_declare(_this.value, name, type);
    db_keep(result);
    return result;
/* $end */
}

/* ::cortex::lang::type::define() */
db_int16 db_type_define(db_any _this) {
/* $begin(::cortex::lang::type::define) */
    return db_define(_this.value);
/* $end */
}

/* ::cortex::lang::type::destruct() */
db_void db_type_destruct(db_any _this) {
/* $begin(::cortex::lang::type::destruct) */
    db_destruct(_this.value);
/* $end */
}

/* ::cortex::lang::type::fullname() */
db_string db_type_fullname(db_any _this) {
/* $begin(::cortex::lang::type::fullname) */
    db_string result = NULL;

    if (_this.value) {
        db_id id;
        result = db_strdup(db_fullname(_this.value, id));
    } else {
        result = db_strdup("null");
    }

    return result;
/* $end */
}

/* ::cortex::lang::type::instanceof(lang::typedef type) */
db_bool db_type_instanceof(db_any _this, db_typedef type) {
/* $begin(::cortex::lang::type::instanceof) */
    return db_instanceof(type, _this.value);
/* $end */
}

/* ::cortex::lang::type::invalidate() */
db_void db_type_invalidate(db_any _this) {
/* $begin(::cortex::lang::type::invalidate) */
    db_invalidate(_this.value);
/* $end */
}

/* ::cortex::lang::type::lookup(lang::string name) */
db_object db_type_lookup(db_any _this, db_string name) {
/* $begin(::cortex::lang::type::lookup) */
    return db_lookup(_this.value, name);
/* $end */
}

/* ::cortex::lang::type::nameof() */
db_string db_type_nameof(db_any _this) {
/* $begin(::cortex::lang::type::nameof) */
    db_string result = NULL;

    if (_this.value) {
        result = db_nameof(_this.value);
        if(result) {
            result = db_strdup(result);
        }
    } else {
        result = db_strdup("null");
    }

    return result;
/* $end */
}

/* ::cortex::lang::type::parentof() */
db_object db_type_parentof(db_any _this) {
/* $begin(::cortex::lang::type::parentof) */
    db_string result = NULL;

   if (db_checkAttr(_this.value, DB_ATTR_SCOPED)) {
       result = db_parentof(_this.value);
   } else {
       db_id id;
       db_error("cannot get parent from non-scoped object of type '%s'", db_fullname(db_typeof(_this.value), id));
   }
    
   if (result) {
       db_keep(result);
   }

   return result;
/* $end */
}

/* ::cortex::lang::type::relname(lang::object from) */
db_string db_type_relname(db_any _this, db_object from) {
/* $begin(::cortex::lang::type::relname) */
    db_string result = NULL;
    db_id id;

    if (_this.value) {
        result = db_strdup(db_relname(from, _this.value, id));
    } else {
        result = db_strdup("null");
    }

    return result;
/* $end */
}

/* ::cortex::lang::type::resolve(lang::string name) */
db_object db_type_resolve(db_any _this, db_string name) {
/* $begin(::cortex::lang::type::resolve) */
    return db_resolve(_this.value, name);
/* $end */
}

/* ::cortex::lang::type::resolveProcedure(lang::string name) */
db_function db_type_resolveProcedure(db_type _this, db_string name) {
/* $begin(::cortex::lang::type::resolveProcedure) */
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
/* $end */
}

/* ::cortex::lang::type::sizeof() */
db_uint32 db_type_sizeof(db_type _this) {
/* $begin(::cortex::lang::type::sizeof) */
    db_uint32 size;
    if (_this->reference) {
        size = sizeof(db_object);
    } else {
        size = _this->size;
    }
    return size;
/* $end */
}

/* ::cortex::lang::type::toString() */
db_string db_type_toString(db_any _this) {
/* $begin(::cortex::lang::type::toString) */
    db_value value;
    db_string result;

    if (_this.value) {
        if (_this.type->reference) {
            db_valueObjectInit(&value, _this.value);
        } else {
            db_valueValueInit(&value, NULL, db_typedef(_this.type), _this.value);
        }
        result = db_valueToString(&value, 0);
    } else {
        result = db_strdup("null");
    }

    return result;
/* $end */
}

/* ::cortex::lang::type::typeof() */
db_type db_type_typeof(db_any _this) {
/* $begin(::cortex::lang::type::typeof) */
    db_type result = NULL;

    result = _this.type;
    
    if (result) {
        db_keep(result);
    }

    return result;
/* $end */
}
