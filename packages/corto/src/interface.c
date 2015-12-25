/* $CORTO_GENERATED
 *
 * corto_interface.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include "corto.h"

/* $header() */
#include "corto__interface.h"
#include "corto__sequence.h"

static corto_vtable *corto_interface_vtableFromBase(corto_interface this) {
    corto_interface base;
    corto_vtable *myTable, *baseTable;
    corto_uint32 size;

    myTable = NULL;

    /* Lookup first vtable in inheritance hierarchy */
    base = corto_interface(this);
    baseTable = NULL;
    while (!baseTable && (base = base->base)) {
        baseTable = (corto_vtable*)&(corto_interface(base)->methods);
    }

    /* If found, copy it */
    if (baseTable) {
        size = baseTable->length * sizeof(corto_method);

        /* Create own vtable. */
        myTable = corto_alloc(sizeof(corto_vtable));
        myTable->length = 0;
        myTable->buffer = NULL;

        /* Copy from base vtable. */
        if (size) {
            corto_uint32 i;
            myTable->buffer = corto_alloc(size);
            myTable->length = baseTable->length;
            memcpy(myTable->buffer, baseTable->buffer, size);

            /* Keep functions */
            for (i=0; i<myTable->length; i++) {
                corto_claim(myTable->buffer[i]);
            }
        } else {
            myTable->buffer = NULL;
        }
    }

    return myTable;
}

/* Lookup method in table */
corto_function* corto_vtableLookup(corto_vtable* vtable, corto_string member, corto_int32* d_out) {
    corto_objectseq s;
    corto_function *result;
    s.buffer = (corto_object *)vtable->buffer;
    s.length = vtable->length;

    result = (corto_function*)corto_lookupFunctionFromSequence(s, member, d_out);

    return result;
}

/* Insert method in vtable at first free spot (normal behavior). */
corto_bool corto_vtableInsert(corto_vtable* vtable, corto_function method) {
    corto_uint32 i;

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
        vtable->buffer = corto_realloc(vtable->buffer, sizeof(corto_member) * (vtable->length + 1));
        vtable->length++;
    }

    vtable->buffer[i] = method;

    return TRUE;
found:
    return FALSE;
}

/* Bind methods in scope */
int corto_interface_walkScope(corto_object o, void* userData) {
    corto_interface this;
    this = userData;

    if (corto_class_instanceof(corto_procedure_o, corto_typeof(o)) && ((corto_procedure(corto_typeof(o))->kind == CORTO_METHOD))) {
        if (!corto_checkState(o, CORTO_DEFINED)) {
            if (corto_interface_bindMethod(this, o)) {
                goto error;
            }
        }
    }

    return 1;
error:
    return 0;
}

corto_int16 corto__interface_bindMember(corto_interface this, corto_member o) {
    o->id = this->nextMemberId;
    this->nextMemberId++;
    return 0;
}

/* private interface::calculateAlignment */
corto_uint16 corto__interface_calculateAlignment(corto_interface this) {
    corto_uint32 i;
    corto_uint16 alignment;
    corto_member member;

    alignment = 0;

    for (i=0; i<this->members.length; i++) {
        corto_uint16 memberAlignment;
        member = this->members.buffer[i];
        memberAlignment = corto_type_alignmentof(member->type);
        if (memberAlignment) {
            if (memberAlignment > alignment) {
                alignment = memberAlignment;
            }
        } else {
            corto_seterr("member '%s' has type '%s' with zero-alignment.",
                corto_fullpath(NULL, member),
                corto_fullpath(NULL, member->type));
            goto error;
        }
    }

    return alignment;
error:
    return 0;
}

/* private interface::calculateSize */
corto_uint32 corto__interface_calculateSize(corto_interface this, corto_uint32 base) {
    corto_uint32 i, memberSize, size, alignment, interfaceAlignment;
    corto_member m;
    corto_type memberType;

    interfaceAlignment = corto_type(this)->alignment;

    size = base;
    for (i=0; i<this->members.length; i++) {
        m = this->members.buffer[i];
        memberType = m->type;

        if (!corto_instanceof(corto_alias_o, m)) {
            memberSize = corto_type_sizeof(memberType);
            if (!memberSize) {
                corto_error("member '%s' of type '%s' is of invalid type '%s'",
                    corto_nameof(m),
                    corto_fullpath(NULL, this),
                    corto_fullpath(NULL, memberType));
                goto error;
            }

            alignment = corto_type_alignmentof(memberType);
            if (!alignment) {
                goto error;
            }
            size = CORTO_ALIGN(size, alignment);

            if (m->type->hasResources || m->type->reference) {
                corto_type(this)->hasResources = TRUE;
            }

            m->offset = size;
            size += memberSize;
        } else {
            m->offset = corto_alias(m)->member->offset;
        }
    }

    return interfaceAlignment ? CORTO_ALIGN(size, interfaceAlignment) : 0;
error:
    return 0;
}

static int corto_interface_validateAlias(corto_alias this) {
    corto_modifier m = 0;

    /* Find the member we're aliassing and verify access */
    if (!this->member) {
        corto_seterr("alias '%s' doesn't point to anything",
            corto_fullpath(NULL, this));
        goto error;
    } else {
        if (this->member->modifiers & (CORTO_PRIVATE|CORTO_LOCAL|CORTO_READONLY|CORTO_CONST)) {
            corto_seterr("alias '%s' doesn't have write-access to member '%s'",
                corto_fullpath(NULL, this), corto_fullpath(NULL, this->member));
            goto error;
        }

        corto_interface base = corto_parentof(this);
        while (base && (base != corto_parentof(this->member))) {
            m |= corto_struct(base)->baseAccess;
            base = base->base;
        }

        if (!base) {
            corto_seterr("alias '%s' points to member of another interface",
                corto_fullpath(NULL, this));
            goto error;
        }

        if (m && m != CORTO_HIDDEN) {
            corto_seterr("alias '%s' doesn't have write-access to member '%s'",
                corto_fullpath(NULL, this), corto_fullpath(NULL, this->member));
            goto error;
        }

        corto_claim(this->member->type); /* TODO: memory leak outside of bootstrap */
        corto_member(this)->type = this->member->type;
        corto_member(this)->modifiers |= this->member->modifiers;
        corto_member(this)->state = this->member->state;
        corto_member(this)->weak = this->member->weak;
    }

    return 0;
error:
    return -1;
}

static int corto_interface_insertMemberAction(void* o, void* userData) {
    /* If object is a member, add it to members sequence */
    if (corto_class_instanceof(corto_member_o, o)) {
        corto_member m = o;

        if (corto_instanceof(corto_alias_o, m)) {
            if (corto_interface_validateAlias(corto_alias(m))) {
                goto error;
            }
        }

        if (!m->type) {
            corto_seterr("member '%s' has no type", corto_fullpath(NULL, m));
            goto error;
        }

        corto_claim(o);
        corto_interface(userData)->members.buffer[corto_member(o)->id] = o;
        corto_interface(userData)->members.length++;
    }

    return 1;
error:
    return 0;
}

/* private interface::insertMembers */
corto_int16 corto__interface_insertMembers(corto_interface this) {
    /* Create sequence with size nextMemberId */

    if (this->nextMemberId) {
        if (corto_sequence_alloc(corto_collection(corto_memberseq_o), &this->members, this->nextMemberId)) {
            goto error;
        }

        /* Fill interface.members with members in scope */
        if (!corto_scopeWalk(this, corto_interface_insertMemberAction, this)) {
            goto error;
        }
    }

    corto_assert(this->nextMemberId == this->members.length, "not all members were added to interface object.");

    return 0;
error:
    return -1;
}

/* Check if parameters of procedures match */
static corto_bool corto_interface_checkProcedureParameters(corto_function o1, corto_function o2) {
    corto_bool result;

    result = TRUE;

    if (o1->parameters.length != o2->parameters.length) {
        corto_seterr("number of parameters does not match for functions '%s' (%d) and '%s' (%d)",
            corto_fullpath(NULL, o1), o1->parameters.length,
            corto_fullpath(NULL, o2), o2->parameters.length);
        result = FALSE;
    } else {
        corto_uint32 i;

        for (i=0; i<o1->parameters.length; i++) {
            corto_type p1, p2;
            /* Check if names of parameters are compatible */
            if (strcmp(o1->parameters.buffer[i].name, o2->parameters.buffer[i].name)) {
                corto_warning(
                    "parameter %d of function '%s' and '%s' differs in name (%s vs %s)",
                    i,
                    corto_fullpath(NULL, o1),
                    corto_fullpath(NULL, o2),
                    o1->parameters.buffer[i].name,
                    o2->parameters.buffer[i].name);
            }

            /* Check if types of parameters are compatible */
            p1 = o1->parameters.buffer[i].type;
            p2 = o2->parameters.buffer[i].type;
            if (p1 != p2) {
                /* Perform a stricter check during bootstrap. This is because the corto_type_compatible method
                 * is not yet available during bootstrap, because the vtable of type is not yet final, resulting
                 * in unstable methodId's. */
                if (!corto_checkState(corto_type_o, CORTO_DEFINED)) { /* If lang::type is not yet defined, we're still bootstrapping. */
                    if (p1 != p2) {
                        if (!(p1 == corto_object_o) && (p2->reference)) {
                            corto_seterr("bootstrap failure: types of parameters '%s' and '%s' are not compatible.",
                                o1->parameters.buffer[i].name,
                                o2->parameters.buffer[i].name);
                        }
                    }
                } else if (!corto_type_castable(p1, p2)) { /* This virtual function can only be called after the bootstrap is complete. */
                    corto_seterr("type of parameter %s of function '%s' is incompatible with function '%s'",
                        corto_nameof(o2->parameters.buffer[i].type),
                        corto_fullpath(NULL, o2),
                        corto_fullpath(NULL, o1));
                }
            }

            /* Check if both parameters have equal reference semantics */
            if (o1->parameters.buffer[i].passByReference != o2->parameters.buffer[i].passByReference) {
                if ((((p1->kind == CORTO_VOID) && (p1->reference)) && o2->parameters.buffer[i].passByReference) ||
                    (((p2->kind == CORTO_VOID) && (p2->reference)) && o1->parameters.buffer[i].passByReference)) {

                } else {
                    corto_seterr("parameter '%s' of function '%s' and '%s' has conflicting pass-by-reference semantics.",
                        o1->parameters.buffer[i].name,
                        corto_fullpath(NULL, o1),
                        corto_fullpath(NULL, o2));
                }
            }
        }
    }

    return result;
}

/* Check whether two procedure objects are compatible */
corto_bool corto_interface_checkProcedureCompatibility(corto_function o1, corto_function o2) {
    corto_type t1;
    corto_bool result;
    corto_type returnType1, returnType2;

    t1 = corto_typeof(o1);

    result = TRUE;

    returnType1 = o1->returnType ? o1->returnType : (corto_type)corto_void_o;
    returnType2 = o2->returnType ? o1->returnType : (corto_type)corto_void_o;

    if (returnType1 != returnType2) {
        corto_error("function '%s' and '%s' have conflicting returntypes (%s vs %s).",
            corto_fullpath(NULL, o1),
            corto_fullpath(NULL, o2),
            corto_fullpath(NULL, returnType1),
            corto_fullpath(NULL, returnType2));
        result = FALSE; /* Returntypes must match exactly (save for typedefs) */
    } else {
        switch(corto_procedure(t1)->kind) {
        case CORTO_METAPROCEDURE:
        case CORTO_FUNCTION:
            result = FALSE; /* Static functions will never be overridden. */
            break;
        case CORTO_METHOD:
            result = corto_interface_checkProcedureParameters(o1, o2);
            break;
        case CORTO_OBSERVER:
            result = FALSE; /* Observers are not overridable and thus never need to be compared. */
            break;
        }
    }

    return result;
}

/* $end */

corto_int16 _corto_interface_baseof(corto_interface this, corto_interface type) {
/* $begin(corto/lang/interface/baseof) */
    corto_interface ptr = this->base;
    corto_bool result = this == type;

    while (ptr && !result) {
        result = ptr == type;
        ptr = ptr->base;
    }

    return result;
/* $end */
}

corto_int16 _corto_interface_bindMethod(corto_interface this, corto_method method) {
/* $begin(corto/lang/interface/bindMethod) */
    corto_method* virtual;
    corto_int32 d;

    /* Check if a method with the same name is already in the vtable */
    virtual = (corto_method *)corto_vtableLookup(&corto_interface(this)->methods, corto_nameof(method), &d);

    /* vtableLookup failed (probably due to a failed overloading request) */
    if (!virtual && (d == -1)) {
        if (!corto_lasterr()) {
            corto_seterr("method lookup error for '%s'", corto_nameof(method));
        }
        goto error;
    }

    /* Function is reentrant */
    if (virtual && (*virtual != method)) {
        /* If distance is zero, override method (from base-class) */
        if (!d) {
            /* Cannot override method if in the same scope */
            if (corto_parentof(*virtual) != corto_parentof(method)) {
                if ((*virtual)->_virtual) {
                    /* Check if overriding method is compatible */
                    if (!corto_interface_checkProcedureCompatibility(corto_function(*virtual), corto_function(method))) {
                        goto error;
                    }
                }
                corto_setref(virtual, method);
            } else {
                corto_id id, id2;
                corto_fullpath(id, method);
                corto_fullpath(id2, *virtual);
                if (strcmp(id, id2)) {
                    corto_seterr("definition of method '%s' conflicts with existing method '%s'", id, id2);
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
            corto_function(*virtual)->overloaded = TRUE; /* Flag found and passed function as overloaded. */
            corto_function(method)->overloaded = TRUE;
        }

        if (corto_vtableInsert(&this->methods, corto_function(method))) {
            corto_claim(method);
        }
    }

    if (corto_interface(this)->kind == CORTO_INTERFACE) {
        method->_virtual = TRUE;
    }

    return 0;
error:
    return -1;
/* $end */
}

corto_bool _corto_interface_compatible_v(corto_interface this, corto_type type) {
/* $begin(corto/lang/interface/compatible) */
    corto_bool result;

    /* First test if types are compatible using the rules that are
     * inherited from type. */
    if (!(result = corto_type_compatible_v(corto_type(this), type))) {
        /* If not compatible, check if the type is a class, in which case
         * an implement-relation could make it compatible. */
        if (corto_class_instanceof(corto_class_o, type)) {
            corto_uint32 i;
            for (i=0; (i<corto_class(type)->implements.length) && !result; i++) {
                if (corto_class(type)->implements.buffer[i] == this) {
                    result = TRUE;
                }
            }
        }
    }

    return result;
/* $end */
}

corto_int16 _corto_interface_construct(corto_interface this) {
/* $begin(corto/lang/interface/construct) */
    corto_vtable *superTable, ownTable;
    corto_uint32 i;

    superTable = NULL;

    /* If a vtable exists on a super-class, merge it with my own. */
    superTable = corto_interface_vtableFromBase(this);
    if (superTable) {
        ownTable = this->methods;
        this->methods = *superTable;

        /* re-bind methods */
        if (ownTable.length) {
            for (i=0; i<ownTable.length; i++) {
                if (corto_instanceof(corto_type(corto_method_o), ownTable.buffer[i])) {
                    corto_interface_bindMethod(this, corto_method(ownTable.buffer[i]));
                }
                corto_release(ownTable.buffer[i]);
            }

            corto_dealloc(ownTable.buffer);
        }
        corto_dealloc(superTable);
    }

    if (!corto_scopeWalk(this, corto_interface_walkScope, this)) {
        goto error;
    }

    return corto_type_construct(corto_type(this));
error:
    return -1;
/* $end */
}

corto_void _corto_interface_destruct(corto_interface this) {
/* $begin(corto/lang/interface/destruct) */
    corto_uint32 i;

    /* Free members */
    for (i=0; i<this->members.length; i++) {
        corto_release(this->members.buffer[i]);
    }

    if (this->members.buffer) {
        corto_dealloc(this->members.buffer);
        this->members.buffer = NULL;
    }

    /* Free methods */
    for (i=0; i<this->methods.length; i++) {
        corto_release(this->methods.buffer[i]);
    }

    if (this->methods.buffer) {
        corto_dealloc(this->methods.buffer);
        this->methods.buffer = NULL;
    }

    corto_type_destruct(corto_type(this));
/* $end */
}

corto_int16 _corto_interface_init(corto_interface this) {
/* $begin(corto/lang/interface/init) */
    corto_type(this)->reference = TRUE;
    corto_type(this)->kind = CORTO_COMPOSITE;
    this->kind = CORTO_INTERFACE;
    return corto_type_init(corto_type(this));
/* $end */
}

corto_member _corto_interface_resolveMember_v(corto_interface this, corto_string name) {
/* $begin(corto/lang/interface/resolveMember) */
    corto_uint32 i;
    corto_member result;

    result = NULL;

    for (i=0; i<this->members.length; i++) {
        if (!strcmp(corto_nameof(this->members.buffer[i]), name)) {
            result = this->members.buffer[i];
            break;
        }
    }

    return result;
/* $end */
}

corto_method _corto_interface_resolveMethod(corto_interface this, corto_string name) {
/* $begin(corto/lang/interface/resolveMethod) */
    corto_method result;
    corto_method* found;

    result = NULL;

    /* Lookup method */
    if ((found = (corto_method*)corto_vtableLookup(&this->methods, name, NULL))) {
        result = *found;
    }

    return result;
/* $end */
}

corto_method _corto_interface_resolveMethodById(corto_interface this, corto_uint32 id) {
/* $begin(corto/lang/interface/resolveMethodById) */
    corto_method result;
    corto_vtable* vtable;

    corto_assert(id != 0, "interface::resolveMethodById: invalid methodId provided to corto_interface_resolveMethodById");
    result = NULL;

    /* Lookup method */
    vtable = &this->methods;
    if (id <= vtable->length) {
        result = corto_method(vtable->buffer[id-1]);
    } else {
        corto_uint32 i;
        corto_seterr(
            "interface::resolveMethodById: invalid vtable-index %d for interface %s",
            id, corto_fullpath(NULL, this));
        printf("%s.vtable:\n", corto_fullpath(NULL, this));
        for (i=0; i<vtable->length; i++) {
            printf("  (%d) %s\n", i+1, corto_fullpath(NULL, vtable->buffer[i]));
        }
    }

    return result;
/* $end */
}

corto_uint32 _corto_interface_resolveMethodId(corto_interface this, corto_string name) {
/* $begin(corto/lang/interface/resolveMethodId) */
    corto_int32 result;
    corto_function *f;

    result = 0;

    if (!corto_checkState(this, CORTO_DEFINED)) {
        corto_seterr(
            "cannot resolve methodId for method '%s' from undefined interface '%s'",
            name,
            corto_fullpath(NULL, this));
        abort();
        goto error;
    }

    /* Lookup method */
    if ((f = corto_vtableLookup(&this->methods, name, NULL))) {
        result = ((corto_word)f - (corto_word)this->methods.buffer) / sizeof(corto_function);
        result++; /* Id's start at 1 */
    }

    return (corto_uint32)result;
error:
    return 0;
/* $end */
}
