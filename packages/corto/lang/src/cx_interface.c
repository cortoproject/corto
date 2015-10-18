/* cx_interface.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "cx.h"

/* $header() */
#include "cx__interface.h"
#include "cx__sequence.h"

static cx_vtable *cx_interface_vtableFromBase(cx_interface this) {
    cx_interface base;
    cx_vtable *myTable, *baseTable;
    cx_uint32 size;

    myTable = NULL;

    /* Lookup first vtable in inheritance hierarchy */
    base = cx_interface(this);
    baseTable = NULL;
    while (!baseTable && (base = base->base)) {
        baseTable = (cx_vtable*)&(cx_interface(base)->methods);
    }

    /* If found, copy it */
    if (baseTable) {
        size = baseTable->length * sizeof(cx_method);

        /* Create own vtable. */
        myTable = cx_alloc(sizeof(cx_vtable));
        myTable->length = 0;
        myTable->buffer = NULL;

        /* Copy from base vtable. */
        if (size) {
            cx_uint32 i;
            myTable->buffer = cx_alloc(size);
            myTable->length = baseTable->length;
            memcpy(myTable->buffer, baseTable->buffer, size);

            /* Keep functions */
            for (i=0; i<myTable->length; i++) {
                cx_claim(myTable->buffer[i]);
            }
        } else {
            myTable->buffer = NULL;
        }
    }

    return myTable;
}

/* Lookup method in table */
cx_function* cx_vtableLookup(cx_vtable* vtable, cx_string member, cx_int32* d_out) {
    cx_objectseq s;
    cx_function *result;
    s.buffer = (cx_object *)vtable->buffer;
    s.length = vtable->length;

    result = (cx_function*)cx_lookupFunctionFromSequence(s, member, d_out);

    return result;
}

/* Insert method in vtable at first free spot (normal behavior). */
cx_bool cx_vtableInsert(cx_vtable* vtable, cx_function method) {
    cx_uint32 i;

    /* Check if function is not already in vtable */
    for (i=0; i<vtable->length; i++) {
        if (vtable->buffer[i] == method) {
            break;
        }
    }
    if (i != vtable->length) {
        goto found;
    }

    /* Find first empty spot in vtable */
    for (i=0; i<vtable->length; i++) {
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
    cx_interface this;
    this = userData;

    if (cx_class_instanceof(cx_procedure_o, cx_typeof(o)) && ((cx_procedure(cx_typeof(o))->kind == CX_METHOD))) {
        if (!cx_checkState(o, CX_DEFINED)) {
            if (cx_interface_bindMethod(this, o)) {
                goto error;
            }
        }
    }

    return 1;
error:
    return 0;
}

cx_int16 cx__interface_bindMember(cx_interface this, cx_member o) {
    o->id = this->nextMemberId;
    this->nextMemberId++;
    return 0;
}

/* private interface::calculateAlignment */
cx_uint16 cx__interface_calculateAlignment(cx_interface this) {
    cx_uint32 i;
    cx_uint16 alignment;
    cx_member member;

    alignment = 0;

    for (i=0; i<this->members.length; i++) {
        cx_uint16 memberAlignment;
        member = this->members.buffer[i];
        memberAlignment = cx_type_alignmentof(member->type);
        if (memberAlignment) {
            if (memberAlignment > alignment) {
                alignment = memberAlignment;
            }
        } else {
            cx_id id, id2;
            cx_seterr("member '%s' has type '%s' with zero-alignment.", cx_fullname(member, id), cx_fullname(member->type, id2));
            goto error;
        }
    }

    return alignment;
error:
    return 0;
}

/* private interface::calculateSize */
cx_uint32 cx__interface_calculateSize(cx_interface this, cx_uint32 base) {
    cx_uint32 i, memberSize, size, alignment, interfaceAlignment;
    cx_member m;
    cx_type memberType;

    interfaceAlignment = cx_type(this)->alignment;

    size = base;
    for (i=0; i<this->members.length; i++) {
        m = this->members.buffer[i];
        memberType = m->type;

        if (!cx_instanceof(cx_alias_o, m)) {
            memberSize = cx_type_sizeof(memberType);
            if (!memberSize) {
                cx_id id1, id2;
                cx_error("member '%s' of type '%s' is of invalid type '%s'", cx_nameof(m), cx_fullname(this, id1), cx_fullname(memberType, id2));
                goto error;
            }

            alignment = cx_type_alignmentof(memberType);
            if (!alignment) {
                goto error;
            }
            size = CX_ALIGN(size, alignment);

            if (m->type->hasResources || m->type->reference) {
                cx_type(this)->hasResources = TRUE;
            }

            m->offset = size;
            size += memberSize;
        } else {
            m->offset = cx_alias(m)->member->offset;
        }
    }

    return interfaceAlignment ? CX_ALIGN(size, interfaceAlignment) : 0;
error:
    return 0;
}

static int cx_interface_validateAlias(cx_alias this) {
    cx_modifier m = 0;
    
    /* Find the member we're aliassing and verify access */
    if (!this->member) {
        cx_id id;
        cx_seterr("alias '%s' doesn't point to anything", cx_fullname(this, id));
        goto error;
    } else {
        if (this->member->modifiers & (CX_PRIVATE|CX_LOCAL|CX_READONLY|CX_CONST)) {
            cx_id id1, id2;
            cx_seterr("alias '%s' doesn't have write-access to member '%s'",
                cx_fullname(this, id1), cx_fullname(this->member, id2));
            goto error;
        }

        cx_interface base = cx_parentof(this);
        while (base && (base != cx_parentof(this->member))) {
            m |= cx_struct(base)->baseAccess;
            base = base->base;
        }

        if (!base) {
            cx_id id;
            cx_seterr("alias '%s' points to member of another interface",
                cx_fullname(this, id));
            goto error;
        }

        if (m && m != CX_HIDDEN) {
            cx_id id1, id2;
            cx_seterr("alias '%s' doesn't have write-access to member '%s'",
                cx_fullname(this, id1), cx_fullname(this->member, id2));
            goto error;
        }

        cx_claim(this->member->type); /* TODO: memory leak outside of bootstrap */
        cx_member(this)->type = this->member->type;
        cx_member(this)->modifiers = this->member->modifiers;
        cx_member(this)->state = this->member->state;
        cx_member(this)->weak = this->member->weak;
    }

    return 0;
error:
    return -1;
}


static int cx_interface_insertMemberAction(void* o, void* userData) {
    /* If object is a member, add it to members sequence */
    if (cx_class_instanceof(cx_member_o, o)) {
        cx_member m = o;

        if (cx_instanceof(cx_alias_o, m)) {
            if (cx_interface_validateAlias(cx_alias(m))) {
                goto error;
            }
        }

        if (!m->type) {
            cx_id id;
            cx_error("member '%s' has no type", cx_fullname(m, id));
            goto error;
        }

        cx_claim(o);
        cx_interface(userData)->members.buffer[cx_member(o)->id] = o;
        cx_interface(userData)->members.length++;
    }

    return 1;
error:
    return 0;
}

/* private interface::insertMembers */
cx_int16 cx__interface_insertMembers(cx_interface this) {
    /* Create sequence with size nextMemberId */

    if (this->nextMemberId) {
        if (cx_sequence_alloc(cx_collection(cx_memberseq_o), &this->members, this->nextMemberId)) {
            goto error;
        }

        /* Fill interface.members with members in scope */
        if (!cx_scopeWalk(this, cx_interface_insertMemberAction, this)) {
            goto error;
        }
    }

    cx_assert(this->nextMemberId == this->members.length, "not all members were added to interface object.");

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

        for (i=0; i<o1->parameters.length; i++) {
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
            p1 = o1->parameters.buffer[i].type;
            p2 = o2->parameters.buffer[i].type;
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
    cx_type returnType1, returnType2;

    t1 = cx_typeof(o1);

    result = TRUE;

    returnType1 = o1->returnType ? o1->returnType : (cx_type)cx_void_o;
    returnType2 = o2->returnType ? o1->returnType : (cx_type)cx_void_o;

    if (returnType1 != returnType2) {
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

/* ::corto::lang::interface::baseof(interface type) */
cx_int16 _cx_interface_baseof(cx_interface this, cx_interface type) {
/* $begin(::corto::lang::interface::baseof) */
    cx_interface ptr = this->base;
    cx_bool result = this == type;
    
    while (ptr && !result) {
        result = ptr == type;
        ptr = ptr->base;
    }
    
    return result;
/* $end */
}

/* ::corto::lang::interface::bindMethod(method method) */
cx_int16 _cx_interface_bindMethod(cx_interface this, cx_method method) {
/* $begin(::corto::lang::interface::bindMethod) */
    cx_method* virtual;
    cx_int32 d;

    /* Check if a method with the same name is already in the vtable */
    virtual = (cx_method *)cx_vtableLookup(&cx_interface(this)->methods, cx_nameof(method), &d);

    /* vtableLookup failed (probably due to a failed overloading request) */
    if (!virtual && (d == -1)) {
        if (!cx_lasterr()) {
            cx_seterr("method lookup error for '%s'", cx_nameof(method));
        }
        goto error;
    }

    /* Function is reentrant */
    if (virtual && (*virtual != method)) {
        /* If distance is zero, override method (from base-class) */
        if (!d) {
            /* Cannot override method if in the same scope */
            if (cx_parentof(*virtual) != cx_parentof(method)) {
                if ((*virtual)->_virtual) {
                    /* Check if overriding method is compatible */
                    if (!cx_interface_checkProcedureCompatibility(cx_function(*virtual), cx_function(method))) {
                        goto error;
                    }
                }
                cx_setref(virtual, method);
            } else {
                cx_id id, id2;
                cx_fullname(method, id);
                cx_fullname(*virtual, id2);
                if (strcmp(id, id2)) {
                    cx_seterr("definition of method '%s' conflicts with existing method '%s'", id, id2);
                    goto error;
                }
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

        if (cx_vtableInsert(&this->methods, cx_function(method))) {
            cx_claim(method);
        }
    }

    if (cx_interface(this)->kind == CX_INTERFACE) {
        method->_virtual = TRUE;
    }

    return 0;
error:
    return -1;
/* $end */
}

/* ::corto::lang::interface::compatible(type type) */
cx_bool _cx_interface_compatible_v(cx_interface this, cx_type type) {
/* $begin(::corto::lang::interface::compatible) */
    cx_bool result;

    /* First test if types are compatible using the rules that are
     * inherited from type. */
    if (!(result = cx_type_compatible_v(cx_type(this), type))) {
        /* If not compatible, check if the type is a class, in which case
         * an implement-relation could make it compatible. */
        if (cx_class_instanceof(cx_class_o, type)) {
            cx_uint32 i;
            for (i=0; (i<cx_class(type)->implements.length) && !result; i++) {
                if (cx_class(type)->implements.buffer[i] == this) {
                    result = TRUE;
                }
            }
        }
    }

    return result;
/* $end */
}

/* ::corto::lang::interface::construct() */
cx_int16 _cx_interface_construct(cx_interface this) {
/* $begin(::corto::lang::interface::construct) */
    cx_vtable *superTable, ownTable;
    cx_uint32 i;

    superTable = NULL;

    /* If a vtable exists on a super-class, merge it with my own. */
    superTable = cx_interface_vtableFromBase(this);
    if (superTable) {
        ownTable = this->methods;
        this->methods = *superTable;

        /* re-bind methods */
        if (ownTable.length) {
            for (i=0; i<ownTable.length; i++) {
                if (cx_instanceof(cx_type(cx_method_o), ownTable.buffer[i])) {
                    cx_interface_bindMethod(this, cx_method(ownTable.buffer[i]));
                } 
                cx_release(ownTable.buffer[i]);
            }

            cx_dealloc(ownTable.buffer);
        }
        cx_dealloc(superTable);
    }

    if (!cx_scopeWalk(this, cx_interface_walkScope, this)) {
        goto error;
    }

    return cx_type_construct(cx_type(this));
error:
    return -1;
/* $end */
}

/* ::corto::lang::interface::destruct() */
cx_void _cx_interface_destruct(cx_interface this) {
/* $begin(::corto::lang::interface::destruct) */
    cx_uint32 i;

    /* Free members */
    for (i=0; i<this->members.length; i++) {
        cx_release(this->members.buffer[i]);
    }

    if (this->members.buffer) {
        cx_dealloc(this->members.buffer);
        this->members.buffer = NULL;
    }

    /* Free methods */
    for (i=0; i<this->methods.length; i++) {
        cx_release(this->methods.buffer[i]);
    }

    if (this->methods.buffer) {
        cx_dealloc(this->methods.buffer);
        this->methods.buffer = NULL;
    }

    cx_type_destruct(cx_type(this));
/* $end */
}

/* ::corto::lang::interface::init() */
cx_int16 _cx_interface_init(cx_interface this) {
/* $begin(::corto::lang::interface::init) */
    cx_type(this)->reference = TRUE;
    cx_type(this)->kind = CX_COMPOSITE;
    this->kind = CX_INTERFACE;
    return cx_type_init(cx_type(this));
/* $end */
}

/* ::corto::lang::interface::resolveMember(string name) */
cx_member _cx_interface_resolveMember_v(cx_interface this, cx_string name) {
/* $begin(::corto::lang::interface::resolveMember) */
    cx_uint32 i;
    cx_member result;

    result = NULL;

    for (i=0; i<this->members.length; i++) {
        if (!strcmp(cx_nameof(this->members.buffer[i]), name)) {
            result = this->members.buffer[i];
            break;
        }
    }

    return result;
/* $end */
}

/* ::corto::lang::interface::resolveMethod(string name) */
cx_method _cx_interface_resolveMethod(cx_interface this, cx_string name) {
/* $begin(::corto::lang::interface::resolveMethod) */
    cx_method result;
    cx_method* found;

    result = NULL;

    /* Lookup method */
    if ((found = (cx_method*)cx_vtableLookup(&this->methods, name, NULL))) {
        result = *found;
    }

    return result;
/* $end */
}

/* ::corto::lang::interface::resolveMethodById(uint32 id) */
cx_method _cx_interface_resolveMethodById(cx_interface this, cx_uint32 id) {
/* $begin(::corto::lang::interface::resolveMethodById) */
    cx_method result;
    cx_vtable* vtable;

    cx_assert(id != 0, "interface::resolveMethodById: invalid methodId provided to cx_interface_resolveMethodById");
    result = NULL;

    /* Lookup method */
    vtable = &this->methods;
    if (id <= vtable->length) {
        result = cx_method(vtable->buffer[id-1]);
    } else {
        cx_id _id;
        cx_uint32 i;
        cx_error("interface::resolveMethodById: invalid vtable-index %d for interface %s", id, cx_fullname(this, _id));
        printf("%s.vtable:\n", cx_fullname(this, _id));
        for (i=0; i<vtable->length; i++) {
            printf("   (%d) %s\n", i+1, cx_fullname(vtable->buffer[i], _id));
        }
    }

    return result;
/* $end */
}

/* ::corto::lang::interface::resolveMethodId(string name) */
cx_uint32 _cx_interface_resolveMethodId(cx_interface this, cx_string name) {
/* $begin(::corto::lang::interface::resolveMethodId) */
    cx_int32 result;
    cx_function *f;

    result = 0;

    if (!cx_checkState(this, CX_DEFINED)) {
        cx_id id;
        cx_error("cannot resolve methodId for method '%s' from undefined interface '%s'", name, cx_fullname(this, id));
        abort();
        goto error;
    }

    /* Lookup method */
    if ((f = cx_vtableLookup(&this->methods, name, NULL))) {
        result = ((cx_word)f - (cx_word)this->methods.buffer) / sizeof(cx_function);
        result++; /* Id's start at 1 */
    }

    return (cx_uint32)result;
error:
    return 0;
/* $end */
}
