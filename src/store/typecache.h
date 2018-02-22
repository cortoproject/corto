
#ifndef CORTO_TYPECACHE_H
#define CORTO_TYPECACHE_H

/* Type kinds */
typedef enum corto_typecache_kind {
    CORTO_TC_VALUE = 0,
    CORTO_TC_STRING = 10, /* Interval for fitting in resource_kind (max=8) */
    CORTO_TC_REFERENCE = 20,
    CORTO_TC_OPTIONAL = 30,
    CORTO_TC_STRUCT = 40,
    CORTO_TC_UNION = 50,
    CORTO_TC_ARRAY = 60,
    CORTO_TC_SEQUENCE = 70,
    CORTO_TC_LIST = 80
} corto_typecache_kind;

/* Additional metadata on what kind of resources are contained in the subtype */
typedef enum corto_typecache_resource_kind {
    CORTO_TC_RES_NONE = 0, /* default */
    CORTO_TC_RES_STRING = 1, /* Nested string */
    CORTO_TC_RES_REFERENCE = 2, /* Nested reference */
    CORTO_TC_RES_RESOURCE = 4, /* Nested generic resource */
    CORTO_TC_RES_ALLOC = 8, /* Value requires alloc, but holds no resource */

    /* Store information about init so serializers can quickly determine whether
     * a field needs to be initialized or deinitialized */
    CORTO_TC_RES_NEEDS_INIT = 16, /* Field needs initialization */
    CORTO_TC_RES_HAS_INIT = 32, /* Field has initializer */
    CORTO_TC_RES_HAS_DEINIT = 64 /* Field has deinitializer */
} corto_typecache_resource_kind;

typedef struct corto_typecache_field {
    uint8_t kind; /* corto_typecache_kind */
    uint8_t res_flags; /* corto_typecache_resource_kind */
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

corto_typecache* corto_typecache_create(
    corto_type type);

#endif
