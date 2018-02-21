
#ifndef CORTO_TYPECACHE_H
#define CORTO_TYPECACHE_H

/* Type kinds */
typedef enum corto_typecache_kind {
    CORTO_TC_VALUE,
    CORTO_TC_STRING,
    CORTO_TC_REFERENCE,
    CORTO_TC_OPTIONAL,
    CORTO_TC_STRUCT,
    CORTO_TC_UNION,
    CORTO_TC_ARRAY,
    CORTO_TC_SEQUENCE,
    CORTO_TC_LIST
} corto_typecache_kind;

/* Additional metadata on what kind of resources are contained in the subtype */
typedef enum corto_typecache_resource_kind {
    CORTO_TC_RES_STRING = 1, /* Nested string */
    CORTO_TC_RES_REFERENCE = 2, /* Nested reference */
    CORTO_TC_RES_RESOURCE = 4, /* Nested resource */
    CORTO_TC_RES_COMPLEX_NO_RES = 8, /* Nested complex type, no resources */
    CORTO_TC_RES_COMPLEX_W_RES = 16, /* Nested complex type with resources */
    CORTO_TC_RES_NEEDS_INIT = 32, /* Field needs initialization */
    CORTO_TC_RES_HAS_INIT = 64, /* Field has initializer */
    CORTO_TC_RES_HAS_DEINIT = 128 /* Field has deinitializer */
} corto_typecache_resource_kind;

typedef struct corto_typecache_field {
    uint8_t kind; /* corto_typecache_kind */
    uint8_t res_flags; /* corto_typecache_resource_kind */
    uint32_t offset;
    union {
        corto_type sub_type; /* For optional fields, sequences and lists */
        corto_array array_type; /* For arrays - contains length */
        uint32_t skip; /* For skipping over nested fields */
    } data;
} corto_typecache_field;

typedef struct corto_typecache {
    uint32_t field_count;
    corto_typecache_field fields[];
} corto_typecache;

corto_typecache* corto_typecache_create(
    corto_type type);

#endif
