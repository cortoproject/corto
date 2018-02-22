#include <corto/corto.h>
#include "typecache.h"

/* Large enough so that most types don't need allocs when creating cache */
#define CORTO_TYPECACHE_BLOCK_FIELD_COUNT (64)

/* Intermediate types used to construct typecache */
typedef struct corto_typecache_block corto_typecache_block;
struct corto_typecache_block {
    uint32_t field_count;
    corto_typecache_block *next;
    corto_typecache_field fields[CORTO_TYPECACHE_BLOCK_FIELD_COUNT];
};

typedef struct corto_typecache_blocks {
    uint32_t field_count;
    corto_typecache_block *first;
    corto_typecache_block *current;
} corto_typecache_blocks;

static
uintptr_t corto_typecache_offset(corto_value *v) {
    void *ptr = corto_value_ptrof(v);
    uintptr_t base = (uintptr_t)corto_value_objectof(v);
    return (uintptr_t)CORTO_OFFSET(ptr, -base);
}

static
const char *corto_typecache_kind_str(
    corto_typecache_kind kind)
{
    switch(kind) {
    case CORTO_TC_VALUE: return "VALUE";
    case CORTO_TC_STRING: return "STRING";
    case CORTO_TC_REFERENCE: return "REFERENCE";
    case CORTO_TC_OPTIONAL: return "OPTIONAL";
    case CORTO_TC_STRUCT: return "STRUCT";
    case CORTO_TC_UNION: return "UNION";
    case CORTO_TC_ARRAY: return "ARRAY";
    case CORTO_TC_SEQUENCE: return "SEQUENCE";
    case CORTO_TC_LIST: return "LIST";
    default:
        corto_error("unknown kind (%d)", kind);
    }
    return "???";
}

static
char *corto_typecache_res_kind_str(
    corto_typecache_kind res_kind)
{
    corto_buffer buffer = CORTO_BUFFER_INIT;
    corto_buffer_appendstr(&buffer, ""); /* buffer at least has empty string */

    if (res_kind & CORTO_TC_RES_NONE) {
        corto_buffer_appendstr(&buffer, " NONE");
    }
    if (res_kind & CORTO_TC_RES_STRING) {
        corto_buffer_appendstr(&buffer, " STRING");
    }
    if (res_kind & CORTO_TC_RES_REFERENCE) {
        corto_buffer_appendstr(&buffer, " REFERENCE");
    }
    if (res_kind & CORTO_TC_RES_RESOURCE) {
        corto_buffer_appendstr(&buffer, " RESOURCE");
    }
    if (res_kind & CORTO_TC_RES_ALLOC) {
        corto_buffer_appendstr(&buffer, " ALLOC");
    }
    if (res_kind & CORTO_TC_RES_NEEDS_INIT) {
        corto_buffer_appendstr(&buffer, " NEEDS_INIT");
    }
    if (res_kind & CORTO_TC_RES_HAS_INIT) {
        corto_buffer_appendstr(&buffer, " HAS_INIT");
    }
    if (res_kind & CORTO_TC_RES_HAS_DEINIT) {
        corto_buffer_appendstr(&buffer, " HAS_DEINIT");
    }

    return corto_buffer_str(&buffer);
}

static
void corto_typecache_print_field(
    corto_typecache_field *field)
{
    const char *kind = corto_typecache_kind_str(field->kind);
    char *res_kind = corto_typecache_res_kind_str(field->res_flags);

    corto_info("%s%s '%s' [offset = %d]",
        kind, res_kind, field->name, field->offset);

    free(res_kind);
}

void corto_typecache_print(
    corto_type type)
{
    corto_typecache *cache = (corto_typecache*)type->typecache;
    if (!cache) {
        return;
    }

    corto_info("typecache for type '%s' [field_count = %d]",
        corto_fullpath(NULL, type),
        cache->field_count);

    corto_log_push("fields");

    int i;
    for (i = 0; i < cache->field_count; i ++) {
        corto_typecache_field *field = &cache->fields[i];
        corto_typecache_print_field(field);
    }

    corto_log_pop();
}

static
corto_typecache_field* corto_typecache_add(
    corto_typecache_blocks *blocks)
{
    corto_typecache_field *f;
    corto_typecache_block *fields = blocks->current;
    if (fields->field_count < CORTO_TYPECACHE_BLOCK_FIELD_COUNT) {
        f = &fields->fields[fields->field_count];
        fields->field_count ++;
    } else {
        fields->next = malloc(sizeof(corto_typecache_block));
        fields = fields->next;
        blocks->current = fields;
        fields->field_count = 0;
        fields->next = NULL;
        f = &fields->fields[0];
    }

    f->kind = 0;
    f->res_flags = 0;
    f->offset = 0;
    f->name = NULL;

    blocks->field_count ++;

    return f;
}

static
bool corto_type_is_string(
    corto_type type)
{
    return type->kind == CORTO_PRIMITIVE &&
        ((corto_primitive)type)->kind == CORTO_TEXT;
}

static
void corto_typecache_set_typeflags(
    corto_typecache_field *field,
    corto_type type)
{
    if (type->flags & CORTO_TYPE_NEEDS_INIT) {
        field->res_flags |= CORTO_TC_RES_NEEDS_INIT;
    }
    if (type->flags & CORTO_TYPE_HAS_INIT) {
        field->res_flags |= CORTO_TC_RES_HAS_INIT;
    }
    if (type->flags & CORTO_TYPE_HAS_DEINIT) {
        field->res_flags |= CORTO_TC_RES_HAS_DEINIT;
    }
}

static
int16_t corto_typecache_collection(
    corto_walk_opt *opt,
    corto_value *info,
    corto_typecache_field *field,
    corto_typecache_blocks *blocks)
{
    corto_collection type = (corto_collection)corto_value_typeof(info);
    corto_type elementType = type->elementType;
    bool elemIsStr = corto_type_is_string(elementType);
    bool elemIsRef = elementType->reference;
    bool elemHasRes = elementType->flags & CORTO_TYPE_HAS_RESOURCES;

    if (elemIsStr) {
        field->res_flags |= CORTO_TC_RES_STRING;
    } else if (elemIsRef) {
        field->res_flags |= CORTO_TC_RES_REFERENCE;
    } else if (elemHasRes) {
        field->res_flags |= CORTO_TC_RES_RESOURCE;
    } else if (type->kind == CORTO_LIST) {
        if (corto_collection_requiresAlloc(elementType)) {
            field->res_flags |= CORTO_TC_RES_ALLOC;
        }
    }

    switch(type->kind) {
    case CORTO_ARRAY:
        field->kind = CORTO_TC_ARRAY;
        field->data.array_type = (corto_array)type;
        break;
    case CORTO_SEQUENCE:
        field->kind = CORTO_TC_SEQUENCE;
        field->data.sub_type = elementType;
        break;
    case CORTO_LIST:
        field->kind = CORTO_TC_LIST;
        field->data.sub_type = elementType;
        break;
    default:
        break;
    }

    return 0;
}

static
int16_t corto_typecache_type(
    corto_walk_opt *opt,
    corto_value *info,
    corto_typecache_field *field,
    corto_typecache_blocks *blocks)
{
    corto_type type = corto_value_typeof(info);

    if (type->reference) {
        field->kind = CORTO_TC_REFERENCE;
    } else if (corto_type_is_string(type)) {
        field->kind = CORTO_TC_STRING;
    } else if (type->kind == CORTO_COLLECTION) {
        corto_typecache_collection(opt, info, field, blocks);
    } else if (type->kind == CORTO_COMPOSITE) {
        if (((corto_interface)type)->kind == CORTO_UNION) {
            field->kind = CORTO_TC_UNION;
            field->data.union_type = (corto_union)type;
        } else {
            /* Keep track of how many fields are skipped by struct */
            int current_field_count = blocks->field_count;
            field->kind = CORTO_TC_STRUCT;
            corto_walk_value(opt, info, blocks);
            field->data.skip = blocks->field_count - current_field_count;
        }
    }

    return 0;
}

static
int16_t corto_typecache_member(
    corto_walk_opt *opt,
    corto_value *info,
    void *userData)
{
    corto_typecache_blocks *blocks = userData;

    corto_type type = corto_value_typeof(info);
    corto_member m = info->is.member.t;

    corto_typecache_field *field = corto_typecache_add(blocks);
    field->offset = corto_typecache_offset(info);
    field->name = corto_idof(m);

    if (!type->reference) {
        corto_typecache_set_typeflags(field, type);
    }

    if (m->modifiers & CORTO_OPTIONAL) {
        field->kind = CORTO_TC_OPTIONAL;
        if (type->reference) {
            field->res_flags &= CORTO_TC_RES_REFERENCE;
        } else if (corto_type_is_string(type)) {
            field->res_flags &= CORTO_TC_RES_STRING;
        }
        field->data.sub_type = type;
    } else if (m->modifiers & CORTO_OBSERVABLE) {
        field->kind = CORTO_TC_REFERENCE;
    } else {
        corto_typecache_type(opt, info, field, blocks);
    }

    return 0;
}

static
int16_t corto_typecache_object(
    corto_walk_opt *opt,
    corto_value *info,
    void *userData)
{
    corto_typecache_blocks *blocks = userData;

    corto_type type = corto_value_typeof(info);

    if (type->kind == CORTO_COMPOSITE && ((corto_interface)type)->kind != CORTO_UNION) {
        /* Forward to member callback */
        corto_walk_value(opt, info, userData);
    } else {
        /* Add single instruction for non-composite type */
        corto_typecache_field *field = corto_typecache_add(blocks);
        corto_typecache_set_typeflags(field, type);
        field->offset = 0;
        corto_typecache_type(opt, info, field, blocks);
    }

    return 0;
}

corto_typecache* corto_typecache_create(
    corto_type type)
{
    corto_typecache_block block = {0, NULL};
    corto_typecache_blocks blocks = {0, &block, &block};
    corto_walk_opt opt;

    corto_walk_init(&opt);
    opt.access = 0;
    opt.accessKind = CORTO_NOT;
    opt.optionalAction = CORTO_WALK_OPTIONAL_PASSTHROUGH;
    opt.aliasAction = CORTO_WALK_ALIAS_IGNORE;
    opt.metaprogram[CORTO_OBJECT] = corto_typecache_object;
    opt.metaprogram[CORTO_MEMBER] = corto_typecache_member;
    opt.observable = corto_typecache_member; /* Passthrough observable */
    _corto_metawalk(&opt, type, &blocks);

    corto_typecache *result = NULL;

    /* If serializer found no fields, return NULL so no empty typecaches are
     * stored on type objects. */
    if (blocks.field_count) {
        /* Allocate typecache with enough memory for fields */
        result = corto_alloc(sizeof(corto_typecache) +
            sizeof(corto_typecache_field) * blocks.field_count);

        /* Copy fields into typecache */
        corto_typecache_block *block_ptr = &block, *next;
        corto_typecache_field *field_ptr = result->fields;

        do {
            memcpy(field_ptr, block_ptr->fields,
                    sizeof(corto_typecache_field) * block_ptr->field_count);
            field_ptr += block_ptr->field_count;
            next = block_ptr->next;
            if (block_ptr != &block) free(block_ptr); /* Cleanup temp admin */
        } while ((block_ptr = next));

        result->field_count = blocks.field_count;
    }

    return result;
}
