
#include "object.h"

#define FREE_STRING(ptr) free(*(char**)ptr)
#define FREE_REFERENCE(ptr) corto_release(*(corto_object*)ptr)

#define FREE_OPTIONAL(ptr, action) {\
    void *optional_ptr = *(void**)ptr;\
    if (optional_ptr) {\
        action;\
        free(optional_ptr);\
    }\
}

#define FREE_UNION(ptr) {\
    int32_t discriminator = *(int32_t*)ptr;\
    corto_member m = \
        safe_corto_union_findCase(field->data.union_type, discriminator);\
    if (m->modifiers & CORTO_OPTIONAL) {\
        FREE_OPTIONAL(\
            CORTO_OFFSET(ptr, m->offset), corto_free(optional_ptr, m->type));\
    } else {\
        corto_free(CORTO_OFFSET(ptr, m->offset), m->type);\
    }\
}

#define FREE_ARRAY_ELEMENTS(ptr, size, action)\
    end = CORTO_OFFSET(ptr, size * count);\
    for (elem = ptr; elem != end; elem = CORTO_OFFSET(elem, size)) {\
        action;\
    }

#define FREE_ARRAY(ptr, element_size, action)\
    sub_type = field->data.array_type->elementType;\
    array_ptr = ptr;\
    count = field->data.array_type->super.max;\
    size = element_size;\
    FREE_ARRAY_ELEMENTS(array_ptr, size, action);

CORTO_SEQUENCE(dummy_seq,void*,);
#define FREE_SEQUENCE(ptr, element_size, action) {\
    sub_type = field->data.sub_type;\
    dummy_seq *seq = ptr;\
    array_ptr = seq->buffer;\
    count = seq->length;\
    size = element_size;\
    FREE_ARRAY_ELEMENTS(array_ptr, size, action);\
    free(array_ptr);\
}

/* Freeing arrays and sequences is similar. Parameterize macro for code reuse */
#define FREE_ARRAY_OP(kind, ptr, size, action)\
    case CORTO_TC_ARRAY + CORTO_TC_SUB_##kind:\
        FREE_ARRAY(ptr, size, action);\
        break;\
    case CORTO_TC_SEQUENCE + CORTO_TC_SUB_##kind:\
        FREE_SEQUENCE(ptr, size, action);\
        break;\

#define FREE_LIST(size_of, action) {\
    sub_type = field->data.sub_type;\
    corto_ll list = *(corto_ll*)ptr;\
    if (list) {\
        corto_ll_node n = list->first;\
        while (n) {\
            elem = n->data;\
            n = n->next;\
            (void)elem;\
            action;\
        }\
        corto_ll_free(list);\
    }\
}

void corto_free(
    void *base_ptr,
    corto_type type)
{
    corto_typecache *cache = (corto_typecache*)type->typecache;
    if (!cache) {
        return;
    }

    /* corto_typecache_print(type); */

    int i;
    for (i = 0; i < cache->field_count; i ++) {
        corto_typecache_field *field = &cache->fields[i];
        void *ptr = CORTO_OFFSET(base_ptr, field->offset);

        /* Variables used within macro's */
        void *array_ptr, *end, *elem;
        uint32_t size, count;
        corto_type sub_type = NULL;

        /* Combine field->kind and res_kind so that with a single switch the
         * right instruction can be selected, as opposed to having additional
         * conditional logic in the operations (which would be slower) */
        switch(field->kind) {

        /* For these field kinds res_kind is always 0 */
        case CORTO_TC_STRING: FREE_STRING(ptr); break;
        case CORTO_TC_REFERENCE: FREE_REFERENCE(ptr); break;
        case CORTO_TC_UNION: FREE_UNION(ptr); break;
        case CORTO_TC_STRUCT: /* Ignore; nesting is not relevant */ break;

        /* Optional operations */
        case CORTO_TC_OPTIONAL:
            FREE_OPTIONAL(ptr,);
            break;
        case CORTO_TC_OPTIONAL + CORTO_TC_SUB_STRING:
            FREE_OPTIONAL(ptr, FREE_STRING(optional_ptr));
            break;
        case CORTO_TC_OPTIONAL + CORTO_TC_SUB_REFERENCE:
            FREE_OPTIONAL(ptr, FREE_REFERENCE(optional_ptr));
            break;
        case CORTO_TC_OPTIONAL + CORTO_TC_SUB_RESOURCE:
            FREE_OPTIONAL(ptr, corto_free(optional_ptr, field->data.sub_type));
            break;

        /* Array & sequence operations */
        case CORTO_TC_SEQUENCE: free(((dummy_seq*)ptr)->buffer); break;
        FREE_ARRAY_OP(STRING, ptr, sizeof(char*), FREE_STRING(elem));
        FREE_ARRAY_OP(REFERENCE, ptr, sizeof(void*), FREE_REFERENCE(elem));
        FREE_ARRAY_OP(RESOURCE, ptr, sub_type->size, corto_free(elem, sub_type));

        /* List operations */
        case CORTO_TC_LIST:
        case CORTO_TC_LIST + CORTO_TC_SUB_SIMPLE_PTR:
            corto_ll_free(*(corto_ll*)ptr);
            break;
        case CORTO_TC_LIST + CORTO_TC_SUB_ALLOC:
        case CORTO_TC_LIST + CORTO_TC_SUB_STRING:
            FREE_LIST(ptr, free(elem));
            break;
        case CORTO_TC_LIST + CORTO_TC_SUB_REFERENCE:
            FREE_LIST(ptr, corto_release(elem));
            break;
        case CORTO_TC_LIST + CORTO_TC_SUB_RESOURCE:
            FREE_LIST(ptr, (corto_free(elem, sub_type), free(elem)));
            break;

        default:
            /* Ignore other instructions */
            break;
        }
    }
}
