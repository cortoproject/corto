/* This is a managed file. Do not delete this comment. */

#include <corto/corto.h>
#include "interface.h"
#include "sequence.h"
#include "src/store/object.h"

corto_objectseq corto_interface_vtableFromBase(corto_interface this) {
    corto_interface base;
    corto_uint32 size;

    corto_objectseq *baseTable, myTable = {0, NULL};

    /* Lookup first vtable in inheritance hierarchy */
    base = corto_interface(this);
    baseTable = NULL;
    while (!baseTable && (base = base->base)) {
        baseTable = (corto_objectseq*)&(corto_interface(base)->methods);
    }

    /* If found, copy it */
    if (baseTable) {
        size = baseTable->length * sizeof(corto_method);
        /* Create own vtable. */
        myTable.length = 0;
        myTable.buffer = NULL;
        /* Copy from base vtable. */
        if (size) {
            corto_uint32 i;
            myTable.buffer = corto_alloc(size);
            myTable.length = baseTable->length;
            memcpy(myTable.buffer, baseTable->buffer, size);
            for (i=0; i<myTable.length; i++) {
                corto_claim(myTable.buffer[i]);
            }

        } else {
            myTable.buffer = NULL;
        }

    }

    return myTable;
}

/* Lookup method in table */
corto_function* corto_vtableLookup(corto_objectseq* vtable, const char *member, corto_int32* d_out) {
    corto_objectseq s;
    corto_function *result;
    s.buffer = (corto_object *)vtable->buffer;
    s.length = vtable->length;
    result = (corto_function*)corto_lookup_functionFromSequence(s, member, d_out, NULL);
    return result;
}

/* Insert method in vtable at first free spot (normal behavior). */
corto_bool corto_vtableInsert(corto_objectseq* vtable, corto_function method) {
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

/* Pull delegates from base-classes to subclass if undefined */
bool corto_interface_pullDelegate(corto_interface this, corto_member m) {
    corto_delegatedata *myDelegate = CORTO_OFFSET(this, m->offset);

    if (corto_instanceof(corto_delegate_o, m->type) && corto_instanceof(corto_parentof(m), this)) {
        corto_interface base = this;
        corto_delegatedata *delegate = NULL;

        do {
            delegate = CORTO_OFFSET(base, m->offset);

            /* If a constructor has been created but has no implementation,
             * skip it. A typical scenario where this happens is in definition
             * files, where an instance is created from a type with a
             * constructor that is defined in the same file. */
            if (delegate->procedure && delegate->procedure->kind == CORTO_PROCEDURE_STUB) {
                delegate = NULL;
            }

        } while ((!delegate || !delegate->procedure) && (base = corto_interface(base)->base));
        if (base && (base != this) && corto_instanceof(corto_parentof(m), base)) {
            corto_set_ref(&myDelegate->procedure, delegate->procedure);
        }

    }

    return myDelegate->procedure != NULL;
}

/* Bind methods in scope */
int corto_interface_walkScope(corto_object o, void* userData) {
    corto_interface this;
    this = userData;

    if (corto_instanceof(corto_method_o, o)) {
        if (corto_interface_bindMethod(this, o)) {
            goto error;
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
        if (member->modifiers & CORTO_OPTIONAL) {
            memberAlignment = CORTO_ALIGNMENT(void*);
        } else if (member->modifiers & CORTO_OBSERVABLE) {
            memberAlignment = CORTO_ALIGNMENT(void*);
        } else {
            memberAlignment = corto_type_alignmentof(member->type);
        }

        if (memberAlignment) {
            if (memberAlignment > alignment) {
                alignment = memberAlignment;
            }

        } else {
            corto_throw("member '%s' has type '%s' with zero-alignment.",
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
            if (m->modifiers & CORTO_OPTIONAL) {
                memberSize = sizeof(void*);
            } else if (m->modifiers & CORTO_OBSERVABLE) {
                memberSize = sizeof(void*);
            } else {
                memberSize = corto_type_sizeof(memberType);
            }

            if (!memberSize) {
                corto_throw("member '%s' of type '%s' is of invalid type '%s'",
                    corto_idof(m),
                    corto_fullpath(NULL, this),
                    corto_fullpath(NULL, memberType));
                goto error;
            }

            alignment = corto_type_alignmentof(memberType);
            if (!alignment) {
                goto error;
            }

            size = CORTO_ALIGN(size, alignment);

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
    corto_member super = ((corto_member)this);
    /* Find the member we're aliassing and verify access */
    if (!this->member) {
        corto_throw("alias '%s' does not point to a member",
            corto_fullpath(NULL, this));
        goto error;
    } else {
        if (this->member == corto_member(this)) {
            corto_throw("alias member '%s' refers to itself",
                corto_fullpath(NULL, this));
            goto error;
        }

        if (this->member->modifiers & CORTO_PRIVATE) {
            corto_throw("cannot alias private member in alias '%s'",
                corto_fullpath(NULL, this));
        }

        if (super->modifiers & CORTO_HIDDEN) {
            corto_throw("invalid hidden modifier for alias '%s'",
                corto_fullpath(NULL, this));
        }

        if (!super->modifiers) {
            super->modifiers = this->member->modifiers;

            /* When copying modifiers, don't copy hidden */
            super->modifiers &= ~CORTO_HIDDEN;
        }

        if ((this->member->modifiers & ~CORTO_HIDDEN) != super->modifiers) {
            corto_throw("alias '%s' modifiers differ from member '%s'",
                corto_fullpath(NULL, this), corto_fullpath(NULL, this->member));
            goto error;
        }

        corto_interface base = corto_parentof(this);
        while (base && (base != corto_parentof(this->member))) {
            m |= corto_struct(base)->baseAccess;
            base = base->base;
        }

        if (!base) {
            corto_throw("alias '%s' points to member of another interface",
                corto_fullpath(NULL, this));
            goto error;
        }

        if (m && m != CORTO_HIDDEN) {
            corto_throw("alias '%s' doesn't have write-access to member '%s'",
                corto_fullpath(NULL, this), corto_fullpath(NULL, this->member));
            goto error;
        }

        corto_claim(this->member->type); /* TODO: memory leak outside of bootstrap */
        corto_member(this)->type = this->member->type;
        corto_member(this)->state = this->member->state;
    }

    return 0;
error:
    return -1;
}

static int corto_interface_insertMemberAction(void* o, void* userData) {
    corto_interface this = corto_interface(userData);

    /* If object is a member, add it to members sequence */
    if (corto_class_instanceof(corto_member_o, o)) {
        corto_member m = o;
        if (corto_instanceof(corto_alias_o, m)) {
            if (corto_interface_validateAlias(corto_alias(m))) {
                goto error;
            }
        }

        if (!m->type) {
            corto_throw("member '%s' has no type", corto_fullpath(NULL, m));
            goto error;
        }

        if ((m->type->flags & CORTO_TYPE_HAS_RESOURCES) || m->type->reference) {
            corto_type(this)->flags |= CORTO_TYPE_HAS_RESOURCES;
        }

        if (!m->type->reference && (m->type->flags & CORTO_TYPE_NEEDS_INIT)) {
            /* Only initialize non-composite members if they set NOT_NULL */
            if (m->modifiers & CORTO_NOT_NULL || m->type->kind == CORTO_COMPOSITE) {
                corto_type(this)->flags |= CORTO_TYPE_NEEDS_INIT;
            }
        }

        if (m->_default) {
            /* If default value is set, initializer needs to assign it */
            corto_type(this)->flags |= CORTO_TYPE_NEEDS_INIT;
        }

        if (m->modifiers & CORTO_OBSERVABLE) {
            corto_type(this)->flags |= CORTO_TYPE_NEEDS_INIT;
        }

        if (!m->type->reference && m->type->flags & CORTO_TYPE_HAS_INIT) {
            /* Init serializer will invoke init routine of member */
            corto_type(this)->flags |= CORTO_TYPE_NEEDS_INIT;
        }

        corto_claim(o);
        this->members.buffer[corto_member(o)->id] = o;
        this->members.length++;
    }

    return 1;
error:
    return 0;
}

/* private interface::insertMembers */
corto_int16 corto__interface_insertMembers(corto_interface this) {
    /* Create sequence with size nextMemberId */

    if (this->nextMemberId) {
        if (corto_sequence_alloc(corto_collection(corto_objectseq_o), &this->members, this->nextMemberId)) {
            goto error;
        }

        /* Fill interface.members with members in scope */
        if (!corto_scope_walk(this, corto_interface_insertMemberAction, this)) {
            goto error;
        }
    }

    corto_assert(this->nextMemberId == this->members.length, "not all members were added to interface object.");
    return 0;
error:
    return -1;
}

/* Check if parameters of procedures match */
static corto_int16 corto_interface_checkProcedureParameters(corto_function o1, corto_function o2) {
    corto_bool result;
    result = TRUE;
    if (o1->parameters.length != o2->parameters.length) {
        corto_throw("number of parameters does not match for functions '%s' (%d) and '%s' (%d)",
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
                if (!corto_check_state(corto_type_o, CORTO_VALID)) { /* If lang::type is not yet defined, we're still bootstrapping. */
                    if (p1 != p2) {
                        if (!(p1 == corto_object_o) && (p2->reference)) {
                            corto_throw("bootstrap failure: types of parameters '%s' and '%s' are not compatible.",
                                o1->parameters.buffer[i].name,
                                o2->parameters.buffer[i].name);
                            result = FALSE;
                        }

                    }

                } else if (!corto_type_castable(p1, p2)) { /* This virtual function can only be called after the bootstrap is complete. */
                    corto_throw("type of parameter %s of function '%s' is incompatible with function '%s'",
                        corto_idof(o2->parameters.buffer[i].type),
                        corto_fullpath(NULL, o2),
                        corto_fullpath(NULL, o1));
                    result = FALSE;
                }

            }

            /* Check if both parameters have equal reference semantics */
            if (o1->parameters.buffer[i].passByReference != o2->parameters.buffer[i].passByReference) {
                if ((((p1->kind == CORTO_VOID) && (p1->reference)) && o2->parameters.buffer[i].passByReference) ||
                    (((p2->kind == CORTO_VOID) && (p2->reference)) && o1->parameters.buffer[i].passByReference)) {
                } else {
                    corto_throw("parameter '%s' of function '%s' and '%s' has conflicting pass-by-reference semantics.",
                        o1->parameters.buffer[i].name,
                        corto_fullpath(NULL, o1),
                        corto_fullpath(NULL, o2));
                    result = FALSE;
                }

            }

        }

    }

    return result;
}

/* Check whether two procedure objects are compatible */
corto_bool corto_interface_checkProcedureCompatibility(corto_function o1, corto_function o2) {
    corto_bool result;
    corto_type returnType1, returnType2;

    result = TRUE;

    returnType1 = o1->returnType ? o1->returnType : (corto_type)corto_void_o;
    returnType2 = o2->returnType ? o2->returnType : (corto_type)corto_void_o;

    if (returnType1 != returnType2) {
        if (!corto_type_compatible(returnType1, returnType2)) {
            corto_throw("function '%s' and '%s' have conflicting returntypes ('%s' vs '%s').",
                corto_fullpath(NULL, o1),
                corto_fullpath(NULL, o2),
                corto_fullpath(NULL, returnType1),
                corto_fullpath(NULL, returnType2));
            result = FALSE; /* Returntypes must match exactly (save for typedefs) */
        }

    } else {
        if (o1->overridable) {
            result = corto_interface_checkProcedureParameters(o1, o2);
        } else {
            result = FALSE;
        }

    }

    return result;
}

int16_t corto_interface_baseof(
    corto_interface this,
    corto_interface type)
{
    corto_interface ptr = this->base;
    corto_bool result = this == type;

    while (ptr && !result) {
        result = ptr == type;
        ptr = ptr->base;
    }

    return result;
}

int16_t corto_interface_bindMethod(
    corto_interface this,
    corto_method method)
{
    corto_function* found = NULL;
    corto_int32 d = 0;
    corto_procedure procedureType = corto_procedure(corto_typeof(method));
    corto_bool added = FALSE;

    /* If parent is INTERFACE, method must be overridable */
    if (this->kind == CORTO_INTERFACE) {
        if (!corto_function(method)->overridable) {
            corto_throw("can't bind '%s': interfaces may only contain overridable methods",
                corto_fullpath(NULL, method));
            goto error;
        }

    }

    /* Check if an overridable method exists in the vtable */
    found = (corto_function *)corto_vtableLookup(&this->methods, corto_idof(method), &d);
    /* vtableLookup failed (probably due to a failed overloading request) */
    if (d == CORTO_OVERLOAD_ERROR) {
        corto_throw("method lookup error for '%s'", corto_idof(method));
        goto error;
    }

    /* If type is override, it must override a method */
    if (procedureType == corto_override_o) {
        if (!found || !*found || d < 0) {
            if (found && *found) {
                corto_throw("no overridable method found for '%s'\n  closest match: '%s'",
                    corto_fullpath(NULL, method),
                    corto_fullpath(NULL, *found));
            } else {
                corto_throw("no overridable method found for '%s'",
                    corto_fullpath(NULL, method));
            }

            goto error;
        } else if (*found && (*found != (corto_function)method) && !(*found)->overridable) {
            corto_throw("method '%s' is not overridable by '%s'",
                corto_fullpath(NULL, *found),
                corto_fullpath(NULL, method));
            goto error;
        }

    }

    /* Function is reentrant */
    if (found && (*found != (corto_function)method)) {
        /* If distance is zero, override method (from base-class) */
        if (!d) {
            /* Cannot override method if in the same scope */
            if (corto_parentof(*found) != corto_parentof(method)) {
                if ((*found)->overridable) {
                    /* Check if overriding method is compatible */
                    if (!corto_interface_checkProcedureCompatibility(
                        *found,
                        corto_function(method)))
                    {
                        goto error;
                    }
                }

                corto_set_ref(found, method);
                added = TRUE;
            } else {
                corto_id id, id2;
                corto_fullpath(id, method);
                corto_fullpath(id2, *found);
                if (strcmp(id, id2)) {
                    corto_throw("method '%s' conflicts with '%s'", id, id2);
                    goto error;
                }

            }

        }

    }

    if (!added) {
        if (found && (d > 0 || d == CORTO_OVERLOAD_NOMATCH_OVERLOAD)) {
            (*found)->overloaded = TRUE;
            corto_function(method)->overloaded = TRUE;
        }

        if (corto_vtableInsert(&this->methods, corto_function(method))) {
            corto_claim(method);
        }

    }

    /* Set method index to enable quick lookups */
    found = (corto_function *)corto_vtableLookup(&this->methods, corto_idof(method), &d);
    corto_assert(found != NULL, "cannot find method in vtable after it was inserted");
    corto_assert(d != -1, "error occurred while looking up inserted method");
    method->index =
        ((corto_word)found -
         (corto_word)this->methods.buffer) / sizeof(corto_function) + 1;
    return 0;
error:
    return -1;
}

bool corto_interface_compatible_v(
    corto_interface this,
    corto_type type)
{
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
}

int16_t corto_interface_construct(
    corto_interface this)
{
    this->methods = corto_interface_vtableFromBase(this);

    if (!corto_scope_walk(this, corto_interface_walkScope, this)) {
        goto error;
    }

    /* The reason that these delegates are pulled on lang/interface and not on
     * lang/type is because pulling delegates forward only makes sense for types
     * that support inheritance. Inheritance is the highest class in the
     * type-inheritance hierarchy that supports inheritance. */
    if (corto_interface_pullDelegate(this, corto_type_init_o)) {
        corto_type(this)->flags |= CORTO_TYPE_HAS_INIT;
    }

    if (corto_interface_pullDelegate(this, corto_type_deinit_o)) {
        corto_type(this)->flags |= CORTO_TYPE_HAS_DEINIT;
    }

    if (this->base) {
        if (corto_type(this->base)->flags & CORTO_TYPE_HAS_DELEGATE) {
            corto_type(this)->flags |= CORTO_TYPE_HAS_DELEGATE;
        }
    }

    return safe_corto_type_construct(this);
error:
    return -1;
}

void corto_interface_destruct(
    corto_interface this)
{
    corto_type_destruct(corto_type(this));
}

void corto_interface_deinit(
    corto_interface this)
{
    if (corto_isbuiltin(this)) {
        corto_uint32 i;

        /* Free members */
        for (i=0; i<this->members.length; i++) {
            corto_set_ref(&this->members.buffer[i], NULL);
        }

        if (this->members.buffer) {
            corto_dealloc(this->members.buffer);
            this->members.buffer = NULL;
            this->members.length = 0;
        }

        /* Free methods */
        for (i=0; i<this->methods.length; i++) {
            corto_set_ref(&this->methods.buffer[i], NULL);
        }

        if (this->methods.buffer) {
            corto_dealloc(this->methods.buffer);
            this->methods.buffer = NULL;
            this->methods.length = 0;
        }
    }

}

int16_t corto_interface_init(
    corto_interface this)
{
    corto_type(this)->reference = TRUE;
    corto_type(this)->kind = CORTO_COMPOSITE;
    this->kind = CORTO_INTERFACE;
    return _corto_type_init((corto_type)this);
}

corto_member corto_interface_resolveMember_v(
    corto_interface this,
    const char *name)
{
    corto_uint32 i;
    corto_member result = NULL;
    char *dot = strchr(name, '.');

    for (i=0; i<this->members.length; i++) {
        if (!strcmp(name, corto_idof(this->members.buffer[i]))) {
            result = this->members.buffer[i];
            break;
        }

    }

    if (dot && result) {
        if (result->type->kind == CORTO_COMPOSITE) {
            result = corto_interface_resolveMember(result->type, dot + 1);
        } else {
            corto_throw("cannot resolve member '%s' on non-composite type '%s'",
                dot + 1,
                corto_fullpath(NULL, result->type));
            goto error;
        }

    }

    return result;
error:
    return NULL;
}

corto_method corto_interface_resolveMethod(
    corto_interface this,
    const char *name)
{
    corto_method result;
    corto_method* found;
    corto_int32 d = 0;

    result = NULL;

    /* Lookup method */
    if ((found = (corto_method*)corto_vtableLookup(&this->methods, name, &d))) {
        if (d >= 0) {
            result = *found;
        }

    }

    return result;
}

corto_method corto_interface_resolveMethodById(
    corto_interface this,
    uint32_t id)
{
    corto_method result;
    corto_objectseq* vtable;

    corto_assert(id != 0, "interface::resolveMethodById: invalid methodId provided to corto_interface_resolveMethodById");
    result = NULL;

    /* Lookup method */
    vtable = &this->methods;
    if (id <= vtable->length) {
        result = corto_method(vtable->buffer[id-1]);
    } else {
        corto_uint32 i;
        corto_throw(
            "interface::resolveMethodById: invalid vtable-index %d for interface %s",
            id, corto_fullpath(NULL, this));
        printf("%s.vtable:\n", corto_fullpath(NULL, this));
        for (i=0; i<vtable->length; i++) {
            printf("  (%d) %s\n", i+1, corto_fullpath(NULL, vtable->buffer[i]));
        }

    }

    return result;
}

uint32_t corto_interface_resolveMethodId(
    corto_interface this,
    const char *name)
{
    corto_int32 result;
    corto_function *f;
    corto_int32 d;

    result = 0;

    if (!corto_check_state(this, CORTO_VALID)) {
        corto_throw(
            "cannot resolve methodId for method '%s' from undefined interface '%s'",
            name,
            corto_fullpath(NULL, this));
        abort();
        goto notfound;
    }

    /* Lookup method */
    if ((f = corto_vtableLookup(&this->methods, name, &d))) {
        result = ((corto_word)f - (corto_word)this->methods.buffer) / sizeof(corto_function);
        result++; /* Id's start at 1 */
    } else if (d == -1) {
        goto error;
    }

    return (corto_uint32)result;
notfound:
    return 0;
error:
    return -1;
}

struct corto_interface_findTag_t {
    corto_tag tag;
    corto_member result;
};

static
int16_t corto_interface_findTag_member(
    corto_walk_opt *opt,
    corto_value *info,
    void *userData)
{
    struct corto_interface_findTag_t *data = userData;
    corto_member m = info->is.member.t;

    if (corto_ll_count(m->tags)) {
        if (corto_ll_hasObject(m->tags, data->tag)) {
            data->result = m;
            return 1;
        }
    }

    return 0;
}

corto_member corto_interface_resolveMemberByTag(
    corto_interface this,
    corto_tag tag)
{
    corto_walk_opt walk_members;

    corto_walk_init(&walk_members);
    walk_members.metaprogram[CORTO_MEMBER] = corto_interface_findTag_member;

    struct corto_interface_findTag_t walkData = {
        .tag = tag
    };
    corto_metawalk(&walk_members, this, &walkData);

    return walkData.result;
}
