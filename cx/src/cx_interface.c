/* cx_interface.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "cx.h"
#include "cx__meta.h"

/* $header() */
#include "cx__interface.h"
#include "cx__sequence.h"

static cx_vtable *cx_interface_vtableFromBase(cx_interface _this) {
    cx_interface base;
    cx_vtable *myTable, *baseTable;
    cx_uint32 size;

    myTable = NULL;

    /* Lookup first vtable in inheritance hierarchy */
    base = cx_interface(_this);
    baseTable = NULL;
    while(!baseTable && (base = base->base)) {
        baseTable = (cx_vtable*)&(cx_interface(base)->methods);
    }

    /* If found, copy it */
    if (baseTable) {
        size = baseTable->length * sizeof(cx_method);

        /* Create own vtable. */
        myTable = cx_malloc(sizeof(cx_vtable));
        myTable->length = 0;
        myTable->buffer = NULL;

        /* Copy from base vtable. */
        if (size) {
            cx_uint32 i;
            myTable->buffer = cx_malloc(size);
            myTable->length = baseTable->length;
            memcpy(myTable->buffer, baseTable->buffer, size);

            /* Keep functions */
            for(i=0; i<myTable->length; i++) {
                cx_keep_ext(_this, myTable->buffer[i], "Keep function from inherited vtable.");
            }
        } else {
            myTable->buffer = NULL;
        }
    }

    return myTable;
}

/* Lookup method in table */
cx_function* cx_vtableLookup(cx_vtable* vtable, cx_string member, cx_int32* i_out, cx_int32* d_out) {
    cx_int32 i;
    cx_function *result, *buffer;
    cx_int32 d, d_t;

    result = NULL;
    buffer = vtable->buffer;
    d = 0x7FFFFFFF;

    /* Searching backwards will ensure that when the member-string contains no arguments and the
     * vtable has multiple matches, the most specific function is selected. */
    for(i=vtable->length-1; i>=0 && d; i--) {
        if (buffer[i]) {
            if (cx_overload(buffer[i], member, &d_t, FALSE)) {
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
cx_bool cx_vtableInsert(cx_vtable* vtable, cx_function method) {
    cx_uint32 i;

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
        vtable->buffer = cx_realloc(vtable->buffer, sizeof(cx_member) * (vtable->length + 1));
        vtable->length++;
    }

    vtable->buffer[i] = method;

    return TRUE;
found:
    return FALSE;
}

/* Bind methods in scope */
int cx_interface_walkScope(cx_object o, void* userData) {
    cx_interface _this;
    _this = userData;

    if (cx_class_instanceof(cx_procedure_o, cx_typeof(o)) && ((cx_procedure(cx_typeof(o))->kind == CX_METHOD))) {
        if (!cx_checkState(o, CX_DEFINED)) {
            if (cx_interface_bindMethod(_this, o)) {
                goto error;
            }
        }
    }

    return 1;
error:
    return 0;
}

cx_int16 cx__interface_bindMember(cx_interface _this, cx_member o) {
    o->id = _this->nextMemberId;
    _this->nextMemberId++;
    return 0;
}

/* private interface::calculateAlignment */
cx_uint16 cx__interface_calculateAlignment(cx_interface _this) {
    cx_uint32 i;
    cx_uint16 alignment;
    cx_member member;

    alignment = 0;

    for(i=0; i<_this->members.length; i++) {
        cx_uint16 memberAlignment;
        member = _this->members.buffer[i];
        memberAlignment = cx_type_alignmentof(member->type->real);
        if (memberAlignment) {
            if (memberAlignment > alignment) {
                alignment = memberAlignment;
            }
        } else {
            cx_id id, id2;
            cx_error("member '%s' has type '%s' with zero-alignment.", cx_fullname(member, id), cx_fullname(member->type->real, id2));
            goto error;
        }
    }

    return alignment;
error:
    return 0;
}

/* private interface::calculateSize */
cx_uint32 cx__interface_calculateSize(cx_interface _this, cx_uint32 base) {
    cx_uint32 i, memberSize, size, alignment, interfaceAlignment;
    cx_member m;
    cx_type memberType;

    interfaceAlignment = cx_type(_this)->alignment;

    /* Calculate size from members */
    size = base;
    for(i=0; i<_this->members.length; i++) {
        m = _this->members.buffer[i];
        memberType = m->type->real;

        memberSize = cx_type_sizeof(memberType);
        if (!memberSize) {
            cx_id id1, id2;
            cx_warning("type '%s' has a member of type '%s' which has size 0.", cx_fullname(_this, id1), cx_fullname(memberType, id2));
        }

        /* Align size */
        alignment = cx_type_alignmentof(memberType);
        size = CX_ALIGN(size, alignment);

        if (m->type->real->hasResources || m->type->real->reference) {
            cx_type(_this)->hasResources = TRUE;
        }

        m->offset = size;
        size += memberSize;
    }

    return interfaceAlignment ? CX_ALIGN(size, interfaceAlignment) : 0;
}

static int cx_interface_insertMemberAction(void* o, void* userData) {
    /* If object is a member, add it to members sequence */
    if (cx_class_instanceof(cx_member_o, o)) {
        cx_member m = o;
        if (!m->type) {
            cx_id id;
            cx_error("member '%s' has no type", cx_fullname(m, id));
            goto error;
        }

        cx_keep_ext((cx_object)userData, o, "Keep member.");
        cx_interface(userData)->members.buffer[cx_member(o)->id] = o;
        cx_interface(userData)->members.length++;
    }

    return 1;
error:
    return 0;
}

/* private interface::insertMembers */
cx_int16 cx__interface_insertMembers(cx_interface _this) {
    /* Create sequence with size nextMemberId */
    if (_this->nextMemberId) {
        if (cx_sequence_alloc(cx_collection(cx_memberSeq_o), &_this->members, _this->nextMemberId)) {
            goto error;
        }

        /* Fill interface.members with members in scope */
        if (!cx_scopeWalk(_this, cx_interface_insertMemberAction, _this)) {
            goto error;
        }
    }

    cx_assert(_this->nextMemberId == _this->members.length, "not all members were added to interface object.");

    return 0;
error:
    return -1;
}

/* Check if parameters of procedures match */
static cx_bool cx_interface_checkProcedureParameters(cx_function o1, cx_function o2) {
    cx_bool result;

    result = TRUE;

    if (o1->parameters.length != o2->parameters.length) {
        cx_id id1, id2;
        cx_error("number of parameters does not match for functions '%s' (%d) and '%s' (%d)",
                cx_fullname(o1, id1), o1->parameters.length,
                cx_fullname(o2, id2), o2->parameters.length);
        result = FALSE;
    } else {
        cx_uint32 i;
        cx_id id1, id2;

        for(i=0; i<o1->parameters.length; i++) {
            cx_type p1, p2;
            /* Check if names of parameters are compatible */
            if (strcmp(o1->parameters.buffer[i].name, o2->parameters.buffer[i].name)) {
                cx_warning("parameter %d of function '%s' and '%s' differs in name (%s vs %s)",
                        i,
                        cx_fullname(o1, id1),
                        cx_fullname(o2, id2),
                        o1->parameters.buffer[i].name,
                        o2->parameters.buffer[i].name);
            }

            /* Check if types of parameters are compatible */
            p1 = o1->parameters.buffer[i].type->real;
            p2 = o2->parameters.buffer[i].type->real;
            if (p1 != p2) {
                /* Perform a stricter check during bootstrap. This is because the cx_type_compatible method
                 * is not yet available during bootstrap, because the vtable of type is not yet final, resulting
                 * in unstable methodId's. */
                if (!cx_checkState(cx_type_o, CX_DEFINED)) { /* If lang::type is not yet defined, we're still bootstrapping. */
                    if (p1 != p2) {
                        if (!(p1 == cx_object_o) && (p2->reference)) {
                            cx_error("bootstrap failure: types of parameters '%s' and '%s' are not compatible.",
                                    o1->parameters.buffer[i].name,
                                    o2->parameters.buffer[i].name);
                        }
                    }
                } else if (!cx_type_castable(p1, p2)) { /* This virtual function can only be called after the bootstrap is complete. */
                    cx_error("type of parameter %s of function '%s' is incompatible with function '%s'",
                            cx_nameof(o2->parameters.buffer[i].type),
                            cx_fullname(o2, id1),
                            cx_fullname(o1, id2));
                }
            }

            /* Check if both parameters have equal reference semantics */
            if (o1->parameters.buffer[i].passByReference != o2->parameters.buffer[i].passByReference) {
                if ((((p1->kind == CX_VOID) && (p1->reference)) && o2->parameters.buffer[i].passByReference) ||
                    (((p2->kind == CX_VOID) && (p2->reference)) && o1->parameters.buffer[i].passByReference)) {

                } else {
                    cx_error("parameter '%s' of function '%s' and '%s' has conflicting pass-by-reference semantics.",
                            o1->parameters.buffer[i].name,
                            cx_fullname(o1, id1),
                            cx_fullname(o2, id2));
                }
            }
        }
    }

    return result;
}

/* Check whether two procedure objects are compatible */
cx_bool cx_interface_checkProcedureCompatibility(cx_function o1, cx_function o2) {
    cx_type t1;
    cx_bool result;
    cx_typedef returnType1, returnType2;

    t1 = cx_typeof(o1)->real;

    result = TRUE;

    returnType1 = o1->returnType ? o1->returnType : (cx_typedef)cx_void_o;
    returnType2 = o2->returnType ? o1->returnType : (cx_typedef)cx_void_o;

    if (returnType1->real != returnType2->real) {
        cx_id id1, id2, id3, id4;
        cx_error("function '%s' and '%s' have conflicting returntypes (%s vs %s).",
                cx_fullname(o1, id1),
                cx_fullname(o2, id2),
                cx_fullname(returnType1, id3),
                cx_fullname(returnType2, id4));
        result = FALSE; /* Returntypes must match exactly (save for typedefs) */
    } else {
        switch(cx_procedure(t1)->kind) {
        case CX_METAPROCEDURE:
        case CX_FUNCTION:
            result = FALSE; /* Static functions will never be overridden. */
            break;
        case CX_METHOD:
            result = cx_interface_checkProcedureParameters(o1, o2);
            break;
        case CX_OBSERVER:
            result = FALSE; /* Observers are not overridable and thus never need to be compared. */
            break;
        }
    }

    return result;
}


/* $end */

/* ::cortex::lang::interface::baseof(interface type) */
cx_int16 cx_interface_baseof(cx_interface _this, cx_interface type) {
/* $begin(::cortex::lang::interface::baseof) */
    cx_interface ptr = _this->base;
    cx_bool result = _this == type;
    
    while(ptr && !result) {
        if (ptr == type) {
            result = TRUE;
        } else {
            ptr = ptr->base;
        }
    }
    
    return result;
/* $end */
}

/* ::cortex::lang::interface::bindMethod(method method) */
cx_int16 cx_interface_bindMethod(cx_interface _this, cx_method method) {
/* $begin(::cortex::lang::interface::bindMethod) */
    cx_method* virtual;
    cx_int32 i;
    cx_int32 d;

    /* Check if a method with the same name is already in the vtable */
    i = 0;
    virtual = (cx_method*)cx_vtableLookup(&cx_interface(_this)->methods, cx_nameof(method), &i, &d);

    /* vtableLookup failed (probably due to a failed overloading request) */
    if (i == -1) {
        goto error;
    }

    /* Function is reentrant */
    if (virtual && (*virtual != method)) {
        /* If distance is zero, override method (from base-class) */
        if (!d) {
            /* Cannot override method if in the same scope */
            if (cx_parentof(*virtual) != cx_parentof(method)) {
                if ((*virtual)->virtual) {
                    /* Check if overriding method is compatible */
                    if (!cx_interface_checkProcedureCompatibility(cx_function(*virtual), cx_function(method))) {
                        goto error;
                    }
                }
                cx_keep_ext(_this, method, "Bind method to class after overriding old.");
                cx_free_ext(_this, *virtual, "Free overridden method.");
                *virtual = method;
            } else {
                cx_id id, id2;
                cx_error("definition of method '%s' conflicts with existing method '%s'", cx_fullname(method, id), cx_fullname(*virtual, id2));
                goto error;
            }
        }
    } else {
        d = -1;
    }

    if (!virtual || (d > 0)) {
        /* If distance is non-zero, bind new method */
        if (virtual) {
            cx_function(*virtual)->overloaded = TRUE; /* Flag found and passed function as overloaded. */
            cx_function(method)->overloaded = TRUE;
        }

        if (cx_vtableInsert(&_this->methods, cx_function(method))) {
            cx_keep_ext(_this, method, "Bind method to interface.");
        }
    }

    if (cx_interface(_this)->kind == CX_INTERFACE) {
        method->virtual = TRUE;
    }

    return 0;
error:
    return -1;
/* $end */
}

/* ::cortex::lang::interface::compatible(type type) */
cx_bool cx_interface_compatible_v(cx_interface _this, cx_type type) {
/* $begin(::cortex::lang::interface::compatible) */
    cx_bool result;

    /* First test if types are compatible using the rules that are
     * inherited from type. */
    if (!(result = cx_type_compatible_v(cx_type(_this), type))) {
        /* If not compatible, check if the type is a class, in which case
         * an implement-relation could make it compatible. */
        if (cx_class_instanceof(cx_class_o, type)) {
            cx_uint32 i;
            for(i=0; (i<cx_class(type)->implements.length) && !result; i++) {
                if (cx_class(type)->implements.buffer[i] == _this) {
                    result = TRUE;
                }
            }
        }
    }

    return result;
/* $end */
}

/* ::cortex::lang::interface::construct() */
cx_int16 cx_interface_construct(cx_interface _this) {
/* $begin(::cortex::lang::interface::construct) */
    cx_vtable *superTable, ownTable;
    cx_uint32 i;

    superTable = NULL;

    /* If a vtable exists on a super-class, merge it with my own. */
    superTable = cx_interface_vtableFromBase(_this);
    if (superTable) {
        ownTable = _this->methods;
        _this->methods = *superTable;

        /* re-bind methods */
        if (ownTable.length) {
            for(i=0; i<ownTable.length; i++) {
                if (cx_instanceof(cx_typedef(cx_method_o), ownTable.buffer[i])) {
                    cx_interface_bindMethod(_this, cx_method(ownTable.buffer[i]));
                } 
                cx_free_ext(_this, ownTable.buffer[i], "Free method from temporary vtable.");
            }

            cx_dealloc(ownTable.buffer);
        }
        cx_dealloc(superTable);
    }

    if (!cx_scopeWalk(_this, cx_interface_walkScope, _this)) {
        goto error;
    }

    return cx_type_construct(cx_type(_this));
error:
    return -1;
/* $end */
}

/* ::cortex::lang::interface::destruct() */
cx_void cx_interface_destruct(cx_interface _this) {
/* $begin(::cortex::lang::interface::destruct) */
    cx_uint32 i;

    /* Free members */
    for(i=0; i<_this->members.length; i++) {
        cx_free_ext(_this, _this->members.buffer[i], "Free member for interface");
    }

    if (_this->members.buffer) {
        cx_dealloc(_this->members.buffer);
        _this->members.buffer = NULL;
    }

    /* Free methods */
    for(i=0; i<_this->methods.length; i++) {
        cx_free_ext(_this, _this->methods.buffer[i], "Remove method from vtable.");
    }

    if (_this->methods.buffer) {
        cx_dealloc(_this->methods.buffer);
        _this->methods.buffer = NULL;
    }

    cx_type_destruct(cx_type(_this));
/* $end */
}

/* ::cortex::lang::interface::init() */
cx_int16 cx_interface_init(cx_interface _this) {
/* $begin(::cortex::lang::interface::init) */
    cx_type(_this)->reference = TRUE;
    cx_type(_this)->kind = CX_COMPOSITE;
    cx_set(&cx_type(_this)->defaultType, cx_member_o);
    _this->kind = CX_INTERFACE;
    return cx_type_init(cx_type(_this));
/* $end */
}

/* ::cortex::lang::interface::resolveMember(string name) */
cx_member cx_interface_resolveMember_v(cx_interface _this, cx_string name) {
/* $begin(::cortex::lang::interface::resolveMember) */
    cx_uint32 i;
    cx_member result;

    result = NULL;

    for(i=0; i<_this->members.length; i++) {
        if (!strcmp(cx_nameof(_this->members.buffer[i]), name)) {
            result = _this->members.buffer[i];
            break;
        }
    }

    return result;
/* $end */
}

/* ::cortex::lang::interface::resolveMethod(string name) */
cx_method cx_interface_resolveMethod(cx_interface _this, cx_string name) {
/* $begin(::cortex::lang::interface::resolveMethod) */
    cx_method result;
    cx_method* found;

    result = NULL;

    /* Lookup method */
    if ((found = (cx_method*)cx_vtableLookup(&_this->methods, name, NULL, NULL))) {
        result = *found;
    }

    return result;
/* $end */
}

/* ::cortex::lang::interface::resolveMethodById(uint32 id) */
cx_method cx_interface_resolveMethodById(cx_interface _this, cx_uint32 id) {
/* $begin(::cortex::lang::interface::resolveMethodById) */
    cx_method result;
    cx_vtable* vtable;

    cx_assert(id != 0, "interface::resolveMethodById: invalid methodId provided to cx_interface_resolveMethodById");
    result = NULL;

    /* Lookup method */
    vtable = &_this->methods;
    if (id <= vtable->length) {
        result = cx_method(vtable->buffer[id-1]);
    } else {
        cx_id _id;
        cx_uint32 i;
        cx_error("interface::resolveMethodById: invalid vtable-index %d for interface %s", id, cx_fullname(_this, _id));
        printf("%s.vtable:\n", cx_fullname(_this, _id));
        for(i=0; i<vtable->length; i++) {
            printf("   (%d) %s\n", i+1, cx_fullname(vtable->buffer[i], _id));
        }
    }

    return result;
/* $end */
}

/* ::cortex::lang::interface::resolveMethodId(string name) */
cx_uint32 cx_interface_resolveMethodId(cx_interface _this, cx_string name) {
/* $begin(::cortex::lang::interface::resolveMethodId) */
    cx_int32 result;

    result = 0;

    if (!cx_checkState(_this, CX_DEFINED)) {
        cx_id id;
        cx_error("cannot resolve methodId for method '%s' from undefined interface '%s'", name, cx_fullname(_this, id));
        abort();
        goto error;
    }

    /* Lookup method */
    if (cx_vtableLookup(&_this->methods, name, &result, NULL)) {
        if (result == -1) {
            goto error;
        }
        result++; /* Id's start at 1 */
    }

    return (cx_uint32)result;
error:
    return 0;
/* $end */
}
