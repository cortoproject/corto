
#ifndef CORTO_TYPECACHE_H
#define CORTO_TYPECACHE_H

/* The typecache is a faster alternative to the corto_walk API that provides a
 * static list of fields that can be iterated over. In contrast, the corto_walk
 * API offers more flexibility in expressing what needs to be walked over. In
 * many common scenarios this extra flexibility is not required however, and
 * adds unnecessary overhead.
 *
 * The typecache is optimized for generic object management usecases, like
 * releasing resources contained in an object, or initializing/deinitializing
 * members of objects that need it.
 *
 * In addition, the typecache can also be used for the most common serialization
 * task, which is serializing the public value (!(LOCAL|PRIVATE)).
 *
 * Another advantage of the typecache is that it can be used for releasing
 * and deinitializing objects even if the original type is already deleted. This
 * is useful when cycle detection is turned on, and a type is cleaned up before
 * all its instances are released.
 */

/* Type kinds */
typedef enum corto_typecache_kind {
    /* Simple values that contain a resource */
    CORTO_TC_STRING = 1,
    CORTO_TC_REFERENCE = 2,
    CORTO_TC_INLINE_REFERENCE = 3, /* Treat as value when serializing */

    /* Numeric values that combine with corto_width (has a range of 0 - 4) */
    CORTO_TC_BIN = 5, /* Binary values. Should not be byte-swapped */
    CORTO_TC_INT = 10, /* Signed integer */
    CORTO_TC_UINT = 15, /* Unsigned integer */
    CORTO_TC_FLOAT = 20, /* Floating point */

    /* Simple values that do not contain a resource */
    CORTO_TC_BOOL = 25,
    CORTO_TC_CHAR = 26,

    /* Enums & bitmasks store their type so serializers can access constants */
    CORTO_TC_ENUM = 27,
    CORTO_TC_BITMASK = 28,

    /* An any/union value does not encode sub_kind because value is dynamic */
    CORTO_TC_UNION = 29,
    CORTO_TC_ANY = 30,

    /* A struct by itself is not a value, but may require (de)initialization */
    CORTO_TC_STRUCT = 31,

    /* Kinds indicating nesting. Not encoded in cache, generated on the fly */
    CORTO_TC_PUSH_COMPOSITE = 32,
    CORTO_TC_PUSH_COLLECTION = 33,
    CORTO_TC_POP_COMPOSITE = 34,
    CORTO_TC_POP_COLLECTION = 35,

    /* Kinds that combine with a sub_kind to quickly classify element-kind */
    CORTO_TC_OPTIONAL = 40,
    CORTO_TC_ARRAY = 50,
    CORTO_TC_SEQUENCE = 60,
    CORTO_TC_LIST = 70,
    CORTO_TC_MAP = 80
} corto_typecache_kind;

typedef enum corto_typecache_sub_kind {
    CORTO_TC_SUB_SIMPLE = 0, /* Simple value, holds no resource (default) */
    CORTO_TC_SUB_STRING = 1, /* Nested string */
    CORTO_TC_SUB_REFERENCE = 2, /* Nested reference */
    CORTO_TC_SUB_RESOURCE = 3, /* Nested generic resource */
    CORTO_TC_SUB_ALLOC = 4, /* Value requires alloc, but holds no resource */
    CORTO_TC_SUB_COMPLEX = 5, /* Complex value, holds no resources */
    CORTO_TC_SUB_SIMPLE_PTR = 6 /* Simple value encoded in element pointer */
} corto_typecache_sub_kind;

/* Meta information about init so serializers can quickly determine whether
 * a field needs to be initialized or deinitialized */
typedef enum corto_typecache_meta_kind {
    CORTO_TC_META_MUST_SERIALIZE = 1, /* Fields that are not private|local */
    CORTO_TC_META_NEEDS_INIT = 2, /* Field needs initialization */
    /* There is no NEEDS_DEINIT because fields that require initialization are
     * regular resources that are already identified in kind & sub_kind */
    CORTO_TC_META_HAS_INIT = 4, /* Field has initializer hook */
    CORTO_TC_META_HAS_DEINIT = 8 /* Field has deinitializer hook */
} corto_typecache_meta_kind;

typedef struct corto_typecache_field {
    uint8_t kind; /* corto_typecache_kind + corto_typecache_sub_kind */
    uint8_t meta_flags; /* corto_typecache_meta_kind */
    uint32_t offset;
    const char *name;
    union {
        corto_type sub_type; /* For optional fields, sequences and lists */
        corto_array array_type; /* For arrays - contains length */
        corto_union union_type; /* For unions - allows for case lookup */
        uint32_t skip; /* For skipping over nested fields */
    } data;
} corto_typecache_field;

typedef struct corto_typecache {
    uint32_t field_count;

    /* Use a dynamic array that is allocated in the same block as the
     * typecache, so it can be simply cleaned up with a free() */
    corto_typecache_field fields[];
} corto_typecache;

typedef int (*corto_typecache_action)(
    corto_typecache_field *field,
    void *key,
    void *ptr,
    void *ctx);

corto_typecache* corto_typecache_create(
    corto_type type);

int corto_typecache_walk(
    corto_typecache *tc,
    void *ptr,
    corto_typecache_action field_action,
    corto_typecache_action elem_action,
    void *ctx);

#endif
