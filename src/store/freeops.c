#include <corto/corto.h>
#include "object.h"

// #define DEBUG_FREEOPS

/* Instruction kinds of freeops program */
typedef enum freeops_kind {
    FREEOPS_STRING,
    FREEOPS_REF,
    FREEOPS_OPTIONAL,
    FREEOPS_ARRAY_STRING,        /* string */
    FREEOPS_ARRAY_REF,           /* reference */
    FREEOPS_ARRAY_W_RES,         /* nested resources */
    FREEOPS_ARRAY_STRUCT,        /* struct w/nested resources */
    FREEOPS_SEQ,                 /* no nested resources */
    FREEOPS_SEQ_STRING,          /* string */
    FREEOPS_SEQ_REF,             /* reference */
    FREEOPS_SEQ_W_RES,           /* nested resources */
    FREEOPS_SEQ_STRUCT,          /* struct w/nested resources */
    FREEOPS_LIST,                /* don't free element, no nested resources */
    FREEOPS_LIST_NO_RES,         /* free element, no nested resources */
    FREEOPS_LIST_W_RES,          /* free element, nested resources */
    FREEOPS_LIST_STRING,         /* string */
    FREEOPS_LIST_REF,            /* reference */
    FREEOPS_LIST_STRUCT,         /* struct w/nested resources (free element) */
    FREEOPS_UNION
} freeops_kind;

/* Single operation */
struct freeops_op {
    freeops_kind kind;
    uint16_t offset;
    uint32_t count;
    corto_type subtype;
#ifdef DEBUG_FREEOPS
    corto_member member;
#endif
};

/* freeops program (Free Operations) */
struct freeops {
    freeops_op *ops;
    uint32_t size;
    uint32_t opcount;
#ifdef DEBUG_FREEOPS
    corto_type type;
#endif
};

#ifdef DEBUG_FREEOPS
static char* freeops_tostr(freeops_kind kind) {
    switch(kind) {
    case FREEOPS_STRING: return "STRING";
    case FREEOPS_REF: return "REF";
    case FREEOPS_OPTIONAL: return "OPTIONAL";
    case FREEOPS_ARRAY_STRING: return "ARRAY_STRING";
    case FREEOPS_ARRAY_REF: return "ARRAY_REF";
    case FREEOPS_ARRAY_W_RES: return "ARRAY_W_RES";
    case FREEOPS_ARRAY_STRUCT: return "ARRAY_STRUCT";
    case FREEOPS_SEQ: return "SEQ";
    case FREEOPS_SEQ_STRING: return "SEQ_STRING";
    case FREEOPS_SEQ_REF: return "SEQ_REF";
    case FREEOPS_SEQ_W_RES: return "SEQ_W_RES";
    case FREEOPS_SEQ_STRUCT: return "SEQ_STRUCT";
    case FREEOPS_LIST: return "LIST";
    case FREEOPS_LIST_NO_RES: return "LIST_NO_RES";
    case FREEOPS_LIST_W_RES: return "LIST_W_RES";
    case FREEOPS_LIST_STRING: return "LIST_STRING";
    case FREEOPS_LIST_REF: return "LIST_REF";
    case FREEOPS_LIST_STRUCT: return "LIST_STRUCT";
    case FREEOPS_UNION: return "UNION";
    default: return "???";
    }
}
#endif

/* Calculate member offset based on a corto_value */
static uintptr_t freeops_computeOffset(corto_value *v) {
    void *ptr = corto_value_ptrof(v);
    uintptr_t base = (uintptr_t)corto_value_objectof(v);
    return (uintptr_t)CORTO_OFFSET(ptr, -base);
}

/* Add new instruction to freeops sequence */
static freeops_op* freeops_add(freeops *r) {
    if (r->size <= r->opcount) {
        if (!r->size) {
            r->size = 1;
        }
        r->size *= 2;
        r->ops = realloc(r->ops, (r->size) * sizeof(freeops_op));
    }
    r->opcount ++;
    return &r->ops[r->opcount - 1];
}

/* For primitive values, only strings are relevant for resource mgmt */
static int16_t freeops_primitive(corto_walk_opt *s, corto_value *info, void *ctx) {
    CORTO_UNUSED(s);

    freeops *r = ctx;
    corto_primitive t = corto_primitive(corto_value_typeof(info));
    if (t->kind == CORTO_TEXT) {
        freeops_op* op = freeops_add(r);
        op->kind = FREEOPS_STRING;
        op->offset = freeops_computeOffset(info);
        op->subtype = NULL;
#ifdef DEBUG_FREEOPS
        op->member = info->is.member.t;
#endif
    }
    return 0;
}

/* Inser instruction to free reference value */
static int16_t freeops_reference(corto_walk_opt *s, corto_value *info, void *ctx) {
    CORTO_UNUSED(s);
    freeops *r = ctx;

    freeops_op* op = freeops_add(r);
    op->kind = FREEOPS_REF;
    op->offset = freeops_computeOffset(info);
    op->subtype = NULL;
#ifdef DEBUG_FREEOPS
    op->member = info->is.member.t;
#endif
    return 0;
}

/* Insert instruction to free collection value */
static int16_t freeops_collection(corto_walk_opt *s, corto_value *info, void *ctx) {
    CORTO_UNUSED(s);

    freeops *r = ctx;
    corto_collection t = corto_collection(corto_value_typeof(info));
    corto_type elementType = t->elementType;

    if (!t->elementType->reference) {
        corto_assert(
            corto_check_state(elementType, CORTO_VALID),
            "cannot create free-program: elementType '%s' of '%s' is not valid",
            corto_fullpath(NULL, elementType),
            corto_fullpath(NULL, t));
    }

    if (corto_type(t)->flags & CORTO_TYPE_HAS_RESOURCES) {
        freeops_op* op = NULL;
        bool elemIsStr = elementType->kind == CORTO_PRIMITIVE && corto_primitive(elementType)->kind == CORTO_TEXT;
        bool elemIsRef = elementType->reference;
        bool elemHasRes = elementType->flags & CORTO_TYPE_HAS_RESOURCES;

        switch(t->kind) {
        case CORTO_ARRAY:
            if (elemIsStr) {
                op = freeops_add(r);
                op->kind = FREEOPS_ARRAY_STRING;
            } else if (elemIsRef) {
                op = freeops_add(r);
                op->kind = FREEOPS_ARRAY_REF;
            } else if (elemHasRes) {
                op = freeops_add(r);
                if (corto_instanceof(corto_struct_o, elementType)) {
                    op->kind = FREEOPS_ARRAY_STRUCT;
                } else {
                    op->kind = FREEOPS_ARRAY_W_RES;
                }
            }
            op->count = t->max;
            break;
        case CORTO_SEQUENCE:
            op = freeops_add(r);
            if (elemIsStr) {
                op->kind = FREEOPS_SEQ_STRING;
            } else if (elemIsRef) {
                op->kind = FREEOPS_SEQ_REF;
            } else if (elemHasRes) {
                if (corto_instanceof(corto_struct_o, elementType)) {
                    op->kind = FREEOPS_SEQ_STRUCT;
                } else {
                    op->kind = FREEOPS_SEQ_W_RES;
                }
            } else {
                op->kind = FREEOPS_SEQ;
            }
            op->count = 0;
            break;
        case CORTO_LIST:
            op = freeops_add(r);
            if (elemIsStr) {
                op->kind = FREEOPS_LIST_STRING;
            } else if (elemIsRef) {
                op->kind = FREEOPS_LIST_REF;
            } else if (corto_instanceof(corto_struct_o, elementType)) {
                if (elemHasRes) {
                    op->kind = FREEOPS_LIST_STRUCT;
                } else {
                    op->kind = FREEOPS_LIST_NO_RES;
                }
            } else {
                if (elemHasRes) {
                    op->kind = FREEOPS_LIST_W_RES;
                } else {
                    if (corto_collection_requiresAlloc(elementType)) {
                        op->kind = FREEOPS_LIST_NO_RES;
                    } else {
                        op->kind = FREEOPS_LIST;
                    }
                }
            }
            op->count = 0;
            break;
        default:
            break;
        }

        if (op) {
            op->offset = freeops_computeOffset(info);
            op->subtype = elementType;
#ifdef DEBUG_FREEOPS
            op->member = info->is.member.t;
#endif
        }
    }

    return 0;
}

/* Insert instruction to free optional or union member, or forward */
static int16_t freeops_member(corto_walk_opt *s, corto_value *info, void *ctx) {
    CORTO_UNUSED(s);
    freeops *r = ctx;
    corto_member m = info->is.member.t;

    if (m->modifiers & CORTO_OPTIONAL) {
        freeops_op* op = freeops_add(r);
        op->kind = FREEOPS_OPTIONAL;
        op->offset = freeops_computeOffset(info);
        op->subtype = m->type;
#ifdef DEBUG_FREEOPS
        op->member = info->is.member.t;
#endif
    } else if (m->type->kind == CORTO_COMPOSITE && corto_interface(m->type)->kind == CORTO_UNION) {
        freeops_op* op = freeops_add(r);
        op->kind = FREEOPS_UNION;
        op->offset = freeops_computeOffset(info);
        op->subtype = m->type;
#ifdef DEBUG_FREEOPS
        op->member = info->is.member.t;
#endif
    } else {
        corto_walk_value(s, info, ctx);
    }

    return 0;
}

/* Create new freeops program */
void freeops_create(freeops *r, corto_type type) {
    corto_walk_opt s;

    corto_walk_init(&s);
    s.access = 0;
    s.accessKind = CORTO_NOT;
    s.optionalAction = CORTO_WALK_OPTIONAL_PASSTHROUGH;
    s.aliasAction = CORTO_WALK_ALIAS_IGNORE;
    s.program[CORTO_PRIMITIVE] = freeops_primitive;
    s.program[CORTO_COLLECTION] = freeops_collection;
    s.metaprogram[CORTO_MEMBER] = freeops_member;
    s.reference = freeops_reference;
    s.observable = freeops_reference;

    freeops *result = r
        ? r
        : corto_calloc(sizeof(freeops))
        ;

    corto_metawalk(&s, type, result);

#ifdef DEBUG_FREEOPS
    result->type = type;
#endif

    if (!r) ((corto_struct)type)->freeops = (uintptr_t)result;
}

CORTO_SEQUENCE(dummySeq,void*,);

/* Macro's that expand to instruction implementations */
#define ARRAY_FREE(action)\
    elem = aptr, end = CORTO_OFFSET(elem, size * count);\
    for (; elem != end; elem = CORTO_OFFSET(elem, size)) {\
       action;\
    }

#define SEQ_FREE()\
    if (seq->buffer) corto_dealloc(seq->buffer);\
    break;

#define LIST_FREE()\
    corto_ll_free(*(corto_ll*)ptr);

#define ARRAY_OP(size_of, action)\
    aptr = ptr;\
    count = op->count;\
    size = size_of;\
    ARRAY_FREE(action);\
    break

#define SEQ_PREP()\
    seq = ptr;\
    aptr = seq->buffer;\
    count = seq->length;\

#define SEQ_OP(size_of, action)\
    SEQ_PREP();\
    size = size_of;\
    ARRAY_FREE(action);\
    SEQ_FREE();

#define LIST_OP(size_of, action) {\
    if (*(corto_ll*)ptr) {\
        corto_ll_node n = (*(corto_ll*)ptr)->first;\
        while (n) {\
            elem = n->data;\
            n = n->next;\
            (void)elem;\
            action;\
        }\
        LIST_FREE();\
    }\
    break;\
}

#define ARRAY_OPS(op, size_of, action)\
    case FREEOPS_ARRAY##op: ARRAY_OP(size_of, action);\
    case FREEOPS_SEQ##op: SEQ_OP(size_of, action);\

#define ARRAY_OPS_NOITER(op, size_of, action)\
    case FREEOPS_SEQ##op: SEQ_PREP(); SEQ_FREE();

#define LIST_OPS(postfix, size_of, action)\
    case FREEOPS_LIST##postfix: LIST_OP(size_of, action);

#define LIST_OPS_NOITER(postfix, size_of, action)\
    case FREEOPS_LIST##postfix: if (*(corto_ll*)ptr) {LIST_FREE();} break;

/* Macro's that facilitate safe freeing of values */
#define deref_mem_free(ptr) deref = *(void**)ptr; if (deref) free(deref);
#define deref_ref_free(ptr) deref = *(void**)ptr; if (deref) corto_release(deref);
#define mem_free(ptr) if (ptr) free(ptr);
#define ref_free(ptr) if (ptr) corto_release(ptr);

/* Obtain a program from a type */
static
freeops *nestops(
    corto_type type)
{
    freeops *r = (freeops*)((corto_struct)type)->freeops;
    if (!r) {
        freeops_create(NULL, type);
        r = (freeops*)((corto_struct)type)->freeops;
        corto_assert(r != NULL, "failed to create freeops program");
    }
    return r;
}

/* Run a program */
static void freeops_run(freeops *r, void *v) {
    int i, size, count;
    void *aptr, *elem, *end, *deref;
    dummySeq *seq;

#ifdef DEBUG_FREEOPS
    //printf(">> free %p of type '%s' with program %p\n", v, corto_fullpath(NULL, r->type), r);
#endif
    for (i = 0; i < r->opcount; i++) {
        freeops_op* op = &r->ops[i];
        void *ptr = CORTO_OFFSET(v, op->offset);

#ifdef DEBUG_FREEOPS
        //printf("    %s: v = %p, offset = %d, ptr = %p [%s], member = %s\n", freeops_tostr(op->kind), v, op->offset, ptr, corto_fullpath(NULL, op->subtype), corto_fullpath(NULL, op->member));
#endif

        switch(op->kind) {
        case FREEOPS_REF:
            deref_ref_free(ptr);
            break;
        case FREEOPS_STRING:
            deref_mem_free(ptr);
            break;

        /* Collections */
        ARRAY_OPS_NOITER(, op->subtype->size,);
        ARRAY_OPS(_STRING, sizeof(char*), deref_mem_free(elem));
        ARRAY_OPS(_REF, sizeof(corto_object), deref_ref_free(elem));
        ARRAY_OPS(_W_RES, op->subtype->size, (freeops_ptr_free(op->subtype, elem)));
        ARRAY_OPS(_STRUCT, op->subtype->size, (freeops_run(nestops(op->subtype), elem)));

        LIST_OPS_NOITER(, op->subtype->size,);
        LIST_OPS(_NO_RES, op->subtype->size, free(elem));
        LIST_OPS(_W_RES, op->subtype->size, (freeops_ptr_free(op->subtype, elem)));
        LIST_OPS(_STRING, , mem_free(elem));
        LIST_OPS(_REF, , ref_free(elem));
        LIST_OPS(_STRUCT, op->subtype->size, (freeops_run(nestops(op->subtype), elem), free(elem)));

        case FREEOPS_UNION: {
            int32_t discriminator = *(int32_t*)v;
            corto_member m = safe_corto_union_findCase(op->subtype, discriminator);
            freeops_ptr_free(m->type, CORTO_OFFSET(ptr, sizeof(int32_t)));
            break;
        }
        case FREEOPS_OPTIONAL:
            if (op->subtype) {
                void *elem = *(void**)ptr;
                if (elem) {
                    freeops_ptr_free(op->subtype, elem);
                    free(elem);
                }
            }
            break;
        }
    }

#ifdef DEBUG_FREEOPS
    //printf("<< done with %p of type '%s' with program %p\n", v, corto_fullpath(NULL, r->type), r);
#endif
}

/* Free a value */
void freeops_ptr_free(corto_type t, void *ptr) {
    if (t->kind == CORTO_COMPOSITE && ((corto_interface)t)->kind != CORTO_INTERFACE) {
        freeops *r = (freeops*)((corto_struct)t)->freeops;
        if (!r) {
            corto_critical("cannot free instance of '%s', instructions not defined",
                corto_fullpath(NULL, t));
        }
#ifdef DEBUG_FREEOPS
        //printf(">> free instance of '%s'\n", corto_fullpath(NULL, t));
#endif
        freeops_run(r, ptr);
    } else {
        if (t->reference && t->kind == CORTO_VOID) {
            corto_object obj = *(corto_object*)ptr;
            if (obj) corto_release(obj);
        } else if (t->kind == CORTO_PRIMITIVE && ((corto_primitive)t)->kind == CORTO_TEXT) {
            char *str = *(char**)ptr;
            if (str) free(str);
        } else {
            /* Generate program on the fly */
            freeops_op op;
            freeops ops = {&op, 1, 0};
            freeops_create(&ops, t);
            freeops_run(&ops, ptr);
        }
    }
}

/* Delete a program */
void freeops_delete(corto_struct t) {
    corto_struct s = (corto_struct)t;
    if (s->freeops) {
        freeops *r = (freeops*)t->freeops;
        free(r->ops);
        free(r);
        s->freeops = 0;
    }
}
