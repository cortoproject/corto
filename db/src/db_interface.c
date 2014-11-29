/*
 * db_interface.c
 *
 *  Created on: Aug 9, 2012
 *      Author: sander
 */

#include "db_class.h"
#include "db_object.h"
#include "db_type.h"
#include "db__interface.h"
#include "db__meta.h"
#include "db_collection.h"
#include "db_err.h"
#include "db_util.h"
#include "db_mem.h"
#include "db_serializer.h"
#include "db_call.h"

static db_uint32 db_interface_resolveMember_id = 0;

static db_vtable *db_interface_vtableFromBase(db_interface _this) {
    db_interface base;
    db_vtable *myTable, *baseTable;
    db_uint32 size;

    myTable = NULL;

    /* Lookup first vtable in inheritance hierarchy */
    base = db_interface(_this);
    baseTable = NULL;
    while(!baseTable && (base = base->base)) {
        baseTable = (db_vtable*)&(db_interface(base)->methods);
    }

    /* If found, copy it */
    if (baseTable) {
        size = baseTable->length * sizeof(db_method);

        /* Create own vtable. */
        myTable = db_malloc(sizeof(db_vtable));
        myTable->length = 0;
        myTable->buffer = NULL;

        /* Copy from base vtable. */
        if (size) {
            db_uint32 i;
            myTable->buffer = db_malloc(size);
            myTable->length = baseTable->length;
            memcpy(myTable->buffer, baseTable->buffer, size);

            /* Keep functions */
            for(i=0; i<myTable->length; i++) {
                db_keep_ext(_this, myTable->buffer[i], "Keep function from inherited vtable.");
            }
        } else {
            myTable->buffer = NULL;
        }
    }

    return myTable;
}

/* Lookup method in table */
db_function* db_vtableLookup(db_vtable* vtable, db_string member, db_int32* i_out, db_int32* d_out) {
    db_int32 i;
    db_function *result, *buffer;
    db_int32 d, d_t;

    result = NULL;
    buffer = vtable->buffer;
    d = 0x7FFFFFFF;

    /* Searching backwards will ensure that when the member-string contains no arguments and the
     * vtable has multiple matches, the most specific function is selected. */
    for(i=vtable->length-1; i>=0 && d; i--) {
        if (buffer[i]) {
        	if (db_overload(buffer[i], member, &d_t, FALSE)) {
        		goto error;
        	}

            if (d_t != -1) {
            	if (d_t < d) {
            		result = &buffer[i];
            		d = d_t;
            	}
            	if (!d) {
            		break;
            	}
            }
        }
    }

    if (i_out && result) {
        *i_out = i;
    }

    if (d_out && result) {
        *d_out = d;
    }

    return result;
error:
	if (i_out) {
		*i_out = -1;
	}
	return NULL;
}

/* Insert method in vtable at first free spot (normal behavior). */
db_bool db_vtableInsert(db_vtable* vtable, db_function method) {
    db_uint32 i;

    /* Check if function is not already in vtable */
    for(i=0; i<vtable->length; i++) {
        if (vtable->buffer[i] == method) {
            break;
        }
    }
    if (i != vtable->length) {
        goto found;
    }

    /* Find first empty spot in vtable */
    for(i=0; i<vtable->length; i++) {
        if (!vtable->buffer[i]) {
            break;
        }
    }

    if (i == vtable->length) {
        vtable->buffer = db_realloc(vtable->buffer, sizeof(db_member) * (vtable->length + 1));
        vtable->length++;
    }

    vtable->buffer[i] = method;

    return TRUE;
found:
    return FALSE;
}

/* Bind methods in scope */
int db_interface_walkScope(db_object o, void* userData) {
	db_interface _this;
	_this = userData;

	if (db_class_instanceof(db_procedure_o, db_typeof(o)) && ((db_procedure(db_typeof(o))->kind == DB_METHOD) || (db_procedure(db_typeof(o))->kind == DB_DELEGATE))) {
		if (!db_checkState(o, DB_DEFINED)) {
			if (db_interface_bindMethod_v(_this, o)) {
			    goto error;
			}
		}
	}

	return 1;
error:
    return 0;
}

/* type::init -> interface::init */
db_int16 db_interface_init(db_interface object) {
    db_type(object)->reference = TRUE;
    db_type(object)->kind = DB_COMPOSITE;
    db_set(&db_type(object)->defaultType, db_member_o);
    object->kind = DB_INTERFACE;
    return db_type__init(db_type(object));
}

/* private class::bindDelegate
 *   Same as db__class_bindDelegate, but does not generate a new delegateId.
 *   When a class is defined, it's vtable will be merged with it's super-class. In this process,
 *   all it's own methods and delegates will be re-binded to the new vtable. This should not
 *   generate new delegateId's as this would make the callback vtable's of objects unneccesary
 *   large.
 */
static db_int16 db__interface_bindDelegate_noId(db_interface _this, db_delegate delegate) {
    db_delegate* found;

    /* Check if a method with the same name is already in the vtable */
    found = (db_delegate*)db_vtableLookup(&_this->methods, db_nameof(delegate), NULL, NULL);

    if (found) {
        /* Function is reentrant */
        if (*found != delegate) {
            db_id id;
            db_critical("class::bindDelegate: cannot override method '%s': delegates can't be overridden", db_fullname(delegate, id));
            goto error;
        }
    } else {
        /* Insert delegate */
        if (db_vtableInsert(&_this->methods, db_function(delegate))) {
            db_keep_ext(_this, delegate, "Bind delegate.");
        }
    }

    return 0;
error:
    return -1;
}

/* class::construct -> interface::construct */
db_int16 db_interface_construct(db_interface object) {
    db_vtable *superTable, ownTable;
    db_uint32 i;

    superTable = NULL;

    /* If a vtable exists on a super-class, merge it with my own. */
    superTable = db_interface_vtableFromBase(object);
    if (superTable) {
        ownTable = object->methods;
        object->methods = *superTable;

        /* re-bind methods and delegates */
        if (ownTable.length) {
            for(i=0; i<ownTable.length; i++) {
                if (db_instanceof(db_typedef(db_method_o), ownTable.buffer[i])) {
                    db_interface_bindMethod_v(object, db_method(ownTable.buffer[i]));
                } else {
                    db_assert(db_instanceof(db_typedef(db_delegate_o), ownTable.buffer[i]),
                            "only methods and delegates are allowed in a class-vtable (found '%s' of type %s).", db_nameof(ownTable.buffer[i]), db_nameof(db_typeof(ownTable.buffer[i])));
                    db__interface_bindDelegate_noId(object, db_delegate(ownTable.buffer[i]));
                }
                db_free_ext(object, ownTable.buffer[i], "Free method from temporary vtable.");
            }

            db_dealloc(ownTable.buffer);
        }
        db_dealloc(superTable);
    }

	if (!db_scopeWalk(object, db_interface_walkScope, object)) {
	    goto error;
	}

	return db_type_construct(db_type(object));
error:
    return -1;
}

/* class::destruct -> interface::destruct */
void db_interface_destruct(db_interface object) {
	db_uint32 i;

	/* Free members */
	for(i=0; i<object->members.length; i++) {
	    db_free_ext(object, object->members.buffer[i], "Free member for interface");
	}

    if (object->members.buffer) {
        db_dealloc(object->members.buffer);
        object->members.buffer = NULL;
    }

    /* Free methods */
    for(i=0; i<object->methods.length; i++) {
    	db_free_ext(object, object->methods.buffer[i], "Remove method from vtable.");
    }

    if (object->methods.buffer) {
		db_dealloc(object->methods.buffer);
		object->methods.buffer = NULL;
    }

	db_type__destruct(db_type(object));
}

db_int16 db__interface_bindMember(db_interface _this, db_member o) {
    o->id = _this->nextMemberId;
    _this->nextMemberId++;
    return 0;
}

/* private interface::calculateAlignment */
db_uint16 db__interface_calculateAlignment(db_interface _this) {
    db_uint32 i;
    db_uint16 alignment;
    db_member member;

    alignment = 0;

    for(i=0; i<_this->members.length; i++) {
    	db_uint16 memberAlignment;
        member = _this->members.buffer[i];
        memberAlignment = db_type_alignmentof(member->type->real);
        if (memberAlignment) {
			if (memberAlignment > alignment) {
				alignment = memberAlignment;
			}
        } else {
        	db_id id, id2;
        	db_error("member '%s' has type '%s' with zero-alignment.", db_fullname(member, id), db_fullname(member->type->real, id2));
        	goto error;
        }
    }

    return alignment;
error:
	return 0;
}

/* private interface::calculateSize */
db_uint32 db__interface_calculateSize(db_interface _this, db_uint32 base) {
	db_uint32 i, memberSize, size, alignment;
	db_member m;
	db_type memberType;

	alignment = db_type(_this)->alignment;

	/* Calculate size from members */
	size = base;
	for(i=0; i<_this->members.length; i++) {
		m = _this->members.buffer[i];
		memberType = m->type->real;

		memberSize = db_type_sizeof(memberType);
		if (!memberSize) {
			db_id id1, id2;
			db_warning("type '%s' has a member of type '%s' which has size 0.", db_fullname(_this, id1), db_fullname(memberType, id2));
		}

		/* Align size */
		if (DB_ALIGN(size + memberSize, alignment) != DB_ALIGN(size, alignment)) {
			size = DB_ALIGN(size, alignment);
		}

		if (m->type->real->hasResources || m->type->real->reference) {
			db_type(_this)->hasResources = TRUE;
		}

		m->offset = size;
		size += memberSize;
	}

	return alignment ? DB_ALIGN(size, alignment) : 0;
}

static int db_interface_insertMemberAction(void* o, void* userData) {
    /* If object is a member, add it to members sequence */
    if (db_class_instanceof(db_member_o, o)) {
    	db_member m = o;
    	if (!m->type) {
    		db_id id;
    		db_error("member '%s' has no type", db_fullname(m, id));
    		goto error;
    	}
        db_keep_ext((db_object)userData, o, "Keep member.");
        db_interface(userData)->members.buffer[db_member(o)->id] = o;
        db_interface(userData)->members.length++;
    }

    return 1;
error:
	return 0;
}

/* private interface::insertMembers */
db_int16 db__interface_insertMembers(db_interface _this) {
    /* Create sequence with size nextMemberId */
    if (_this->nextMemberId) {
        if (db_sequenceAlloc(db_collection(db_memberSeq_o), &_this->members, _this->nextMemberId)) {
            goto error;
        }

        /* Fill interface.members with members in scope */
        if (!db_scopeWalk(_this, db_interface_insertMemberAction, _this)) {
            goto error;
        }
    }

    db_assert(_this->nextMemberId == _this->members.length, "not all members were added to interface object.");

    return 0;
error:
    return -1;
}



/* virtual interface::resolveMember */
db_member db_interface_resolveMember_v(db_interface _this, db_string name) {
    db_uint32 i;
    db_member result;

    result = NULL;

    for(i=0; i<_this->members.length; i++) {
        if (!strcmp(db_nameof(_this->members.buffer[i]), name)) {
            result = _this->members.buffer[i];
            break;
        }
    }

    return result;
}

/* interface::resolveMember */
db_member db_interface_resolveMember(db_interface _this, db_string name) {
    db_method resolveMember;
    db_member result;

    result = NULL;

    /* Lookup method Id */
    if (!db_interface_resolveMember_id) {
        db_interface_resolveMember_id = db_interface_resolveMethodId(db_interface(db_typeof(_this)->real), "resolveMember");
    }
    db_assert(db_interface_resolveMember_id, "type '%s' has no resolveMember function.", db_nameof(db_typeof(_this)));

    /* Lookup method */
    resolveMember = db_interface_resolveMethodById(db_interface(db_typeof(_this)), db_interface_resolveMember_id);
    db_assert(resolveMember != NULL, "unresolved method '%s::resolveMember@%d'", db_nameof(_this), db_interface_resolveMember_id);

    db_call(db_function(resolveMember), &result, _this, name);

    return result;
}



/* interface::resolveMethod */
db_method db_interface_resolveMethod(db_interface _this, db_string method) {
    db_method result;
    db_method* found;

    result = NULL;

    /* Lookup method */
    if ((found = (db_method*)db_vtableLookup(&_this->methods, method, NULL, NULL))) {
        result = *found;
    }

    return result;
}

/* interface::resolveMethodId */
db_uint32 db_interface_resolveMethodId(db_interface _this, db_string method) {
    db_int32 result;

    result = 0;

    if (!db_checkState(_this, DB_DEFINED)) {
        db_id id;
        db_error("cannot resolve methodId for method '%s' from undefined interface '%s'", method, db_fullname(_this, id));
        goto error;
    }

    /* Lookup method */
    if (db_vtableLookup(&_this->methods, method, &result, NULL)) {
    	if (result == -1) {
    		goto error;
    	}
        result++; /* Id's start at 1 */
    }

    return (db_uint32)result;
error:
    return 0;
}

/* interface::resolveMethodId */
db_method db_interface_resolveMethodById(db_interface _this, db_uint32 id) {
    db_method result;
    db_vtable* vtable;

    db_assert(id != 0, "interface::resolveMethodById: invalid methodId provided to db_interface_resolveMethodById");
    result = NULL;

    /* Lookup method */
    vtable = &_this->methods;
    if (id <= vtable->length) {
        result = db_method(vtable->buffer[id-1]);
    } else {
        db_id _id;
        db_uint32 i;
        db_error("interface::resolveMethodById: invalid vtable-index %d for interface %s", id, db_fullname(_this, _id));
        printf("%s.vtable:\n", db_fullname(_this, _id));
        for(i=0; i<vtable->length; i++) {
            printf("   (%d) %s\n", i+1, db_fullname(vtable->buffer[i], _id));
        }
    }

    return result;
}

/* ::interface::bindMethod */
db_int16 db_interface_bindMethod(db_interface _this, db_method method) {
    db_method _method;
    db_int16 result;
    static db_uint32 methodId;

    DB_UNUSED(_this);

    result = 0;

    /* Lookup method Id */
    if (!methodId) {
        methodId = db_interface_resolveMethodId(db_interface(db_typeof(_this)->real), "bindMethod");
    }
    db_assert(methodId, "type '%s' has no bindMethod function.", db_nameof(db_typeof(_this)));

    /* Lookup method */
    _method = db_interface_resolveMethodById(db_interface(db_typeof(_this)), methodId);
    db_assert(_method != NULL, "unresolved method '%s::bindMethod@%d'", db_nameof(_this), methodId);

    db_call(db_function(_method), &result, _this, method);

    return result;
}

/* Check if parameters of procedures match */
static db_bool db_interface_checkProcedureParameters(db_function o1, db_function o2) {
    db_bool result;

    result = TRUE;

    if (o1->parameters.length != o2->parameters.length) {
        db_id id1, id2;
        db_error("number of parameters does not match for functions '%s' (%d) and '%s' (%d)",
                db_fullname(o1, id1), o1->parameters.length,
                db_fullname(o2, id2), o2->parameters.length);
        result = FALSE;
    } else {
        db_uint32 i;
        db_id id1, id2;

        for(i=0; i<o1->parameters.length; i++) {
            db_type p1, p2;
            /* Check if names of parameters are compatible */
            if (strcmp(o1->parameters.buffer[i].name, o2->parameters.buffer[i].name)) {
                db_warning("parameter %d of function '%s' and '%s' differs in name (%s vs %s)",
                        i,
                        db_fullname(o1, id1),
                        db_fullname(o2, id2),
                        o1->parameters.buffer[i].name,
                        o2->parameters.buffer[i].name);
            }

            /* Check if types of parameters are compatible */
            p1 = o1->parameters.buffer[i].type->real;
            p2 = o2->parameters.buffer[i].type->real;
            if (p1 != p2) {
                /* Perform a stricter check during bootstrap. This is because the db_type_compatible method
                 * is not yet available during bootstrap, because the vtable of type is not yet final, resulting
                 * in unstable methodId's. */
                if (!db_checkState(db_type_o, DB_DEFINED)) { /* If lang::type is not yet defined, we're still bootstrapping. */
                    if (p1 != p2) {
                        if (!(p1 == db_object_o) && (p2->reference)) {
                            db_error("bootstrap failure: types of parameters '%s' and '%s' are not compatible.",
                                    o1->parameters.buffer[i].name,
                                    o2->parameters.buffer[i].name);
                        }
                    }
                } else if (!db_type_castable(p1, p2)) { /* This virtual function can only be called after the bootstrap is complete. */
                    printf("p1=%s, p2=%s\n", db_nameof(p1), db_nameof(p2));
                    db_error("type of parameter %s of function '%s' is incompatible with function '%s'",
                            db_nameof(o2->parameters.buffer[i].type),
                            db_fullname(o2, id1),
                            db_fullname(o1, id2));
                }
            }

            /* Check if both parameters have equal reference semantics */
            if (o1->parameters.buffer[i].passByReference != o2->parameters.buffer[i].passByReference) {
                db_error("parameter '%s' of function '%s' and '%s' has conflicting pass-by-reference semantics.",
                        o1->parameters.buffer[i].name,
                        db_fullname(o1, id1),
                        db_fullname(o2, id2));
            }
        }
    }

    return result;
}

/* Check whether two procedure objects are compatible */
db_bool db_interface_checkProcedureCompatibility(db_function o1, db_function o2) {
    db_type t1, t2;
    db_bool result;
    db_typedef returnType1, returnType2;

    t1 = db_typeof(o1)->real;
    t2 = db_typeof(o2)->real;

    result = TRUE;

    returnType1 = o1->returnType ? o1->returnType : (db_typedef)db_void_o;
    returnType2 = o2->returnType ? o1->returnType : (db_typedef)db_void_o;

    if (returnType1->real != returnType2->real) {
        db_id id1, id2, id3, id4;
        db_error("function '%s' and '%s' have conflicting returntypes (%s vs %s).",
                db_fullname(o1, id1),
                db_fullname(o2, id2),
                db_fullname(returnType1, id3),
                db_fullname(returnType2, id4));
        result = FALSE; /* Returntypes must match exactly (save for typedefs) */
    } else {
        switch(db_procedure(t1)->kind) {
        case DB_METAPROCEDURE:
        case DB_FUNCTION:
            result = FALSE; /* Static functions will never be overridden. */
            break;
        case DB_METHOD:
            result = db_interface_checkProcedureParameters(o1, o2);
            break;
        case DB_DELEGATE:
            if (db_procedure(t2)->kind != DB_CALLBACK) {
                result = FALSE;
            } else {
                result = db_interface_checkProcedureParameters(o1, o2);
            }
            break;
        case DB_CALLBACK:
            result = FALSE; /* Callbacks will never be compared to eachother */
            break;
        case DB_OBSERVER:
            result = FALSE; /* Observers are not overridable and thus never need to be compared. */
            break;
        }
    }

    return result;
}

/* Bind method with interface class */
db_int16 db_interface_bindMethod_v(db_interface _this, db_method method) {
    db_method* virtual;
    db_int32 i;
    db_int32 d;

    /* Check if a method with the same name is already in the vtable */
    i = 0;
    virtual = (db_method*)db_vtableLookup(&db_interface(_this)->methods, db_nameof(method), &i, &d);

    /* vtableLookup failed (probably due to a failed overloading request) */
    if (i == -1) {
    	goto error;
    }

    /* Function is reentrant */
    if (virtual && (*virtual != method)) {
        /* If distance is zero, override method (from base-class) */
        if (!d) {
            /* Cannot override method if in the same scope */
            if (db_parentof(*virtual) != db_parentof(method)) {
                if ((*virtual)->virtual) {
                    /* Check if overriding method is compatible */
                    if (!db_interface_checkProcedureCompatibility(db_function(*virtual), db_function(method))) {
                        goto error;
                    }
                }
                db_keep_ext(_this, method, "Bind method to class after overriding old.");
                db_free_ext(_this, *virtual, "Free overridden method.");
                *virtual = method;
            } else {
                db_id id, id2;
                db_error("definition of method '%s' conflicts with existing method '%s'", db_fullname(method, id), db_fullname(*virtual, id2));
                goto error;
            }
        }
    } else {
        d = -1;
    }

    if (!virtual || (d > 0)) {
        /* If distance is non-zero, bind new method */
        if (virtual) {
            db_function(*virtual)->overloaded = TRUE; /* Flag found and passed function as overloaded. */
            db_function(method)->overloaded = TRUE;
        }

        if (db_vtableInsert(&_this->methods, db_function(method))) {
            db_keep_ext(_this, method, "Bind method to interface.");
        }
    }

    if (db_interface(_this)->kind == DB_INTERFACE) {
    	method->virtual = TRUE;
    }

    return 0;
error:
    return -1;
}

/* In addition to inheritance, introduce implement-relations */
db_bool db_interface_compatible(db_interface _this, db_type type) {
    db_bool result;

    /* First test if types are compatible using the rules that are
     * inherited from type. */
    if (!(result = db_type_compatible_v(db_type(_this), type))) {
        /* If not compatible, check if the type is a class, in which case
         * an implement-relation could make it compatible. */
        if (db_class_instanceof(db_class_o, type)) {
            db_uint32 i;
            for(i=0; (i<db_class(type)->implements.length) && !result; i++) {
                if (db_class(type)->implements.buffer[i] == _this) {
                    result = TRUE;
                }
            }
        }
    }

    return result;
}

/* Is type a base of interface */
db_bool db_interface_baseof(db_interface _this, db_interface type) {
    db_interface ptr = _this->base;
    db_bool result = FALSE;
    
    while(ptr && !result) {
        if (ptr == type) {
            result = TRUE;
        } else {
            ptr = ptr->base;
        }
    }
    
    return result;
}

