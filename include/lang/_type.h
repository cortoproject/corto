/* _type.h
 * This file is generated. Do not modify its contents.
 */

#ifndef CORTO_LANG_TYPE_H
#define CORTO_LANG_TYPE_H

#include <corto/platform.h>
#ifdef __cplusplus
extern "C" {
#endif

/* -- Type definitions -- */

/* enum corto/lang/typeKind */
typedef enum corto_typeKind {
    CORTO_VOID = 0,
    CORTO_ANY = 1,
    CORTO_PRIMITIVE = 2,
    CORTO_COMPOSITE = 3,
    CORTO_COLLECTION = 4,
    CORTO_ITERATOR = 5
} corto_typeKind;

/* boolean corto/lang/bool */
typedef bool corto_bool;

/* bitmask corto/lang/attr */
typedef uint32_t corto_attr;
    #define CORTO_ATTR_NAMED (0x1)
    #define CORTO_ATTR_WRITABLE (0x2)
    #define CORTO_ATTR_OBSERVABLE (0x4)
    #define CORTO_ATTR_PERSISTENT (0x8)
    #define CORTO_ATTR_DEFAULT (0x10)

/* class corto/lang/type */
typedef struct corto_type_s *corto_type;

/* bitmask corto/lang/state */
typedef uint32_t corto_state;
    #define CORTO_VALID (0x1)
    #define CORTO_DELETED (0x2)
    #define CORTO_DECLARED (0x4)

/* uint corto/lang/uint16 */
typedef uint16_t corto_uint16;

/* uint corto/lang/uint32 */
typedef uint32_t corto_uint32;

/* object */
typedef void *corto_object;

typedef struct corto_objectseq {uint32_t length; corto_object *buffer;} corto_objectseq;

/* binary corto/lang/word */
typedef uintptr_t corto_word;

/* text corto/lang/string */
typedef char* corto_string;

/* enum corto/lang/inout */
typedef enum corto_inout {
    CORTO_IN = 0,
    CORTO_OUT = 1,
    CORTO_INOUT = 2
} corto_inout;

/* struct corto/lang/parameter */
typedef struct corto_parameter {
    corto_string name;
    corto_type type;
    corto_inout inout;
    bool is_reference;
} corto_parameter;

typedef struct corto_parameterseq {uint32_t length; corto_parameter *buffer;} corto_parameterseq;

/* procedure corto/lang/function */
typedef struct corto_function_s {
    corto_type return_type;
    bool is_reference;
    corto_parameterseq parameters;
    bool overridable;
    bool overloaded;
    uint32_t kind;
    uintptr_t impl;
    uintptr_t fptr;
    uintptr_t fdata;
    uint16_t size;
} *corto_function;

/* struct corto/lang/delegatedata */
typedef struct corto_delegatedata {
    corto_object instance;
    corto_function procedure;
} corto_delegatedata;

/* delegate corto/lang/pre_action */
typedef struct corto_pre_action {
    corto_delegatedata super;
} corto_pre_action;

/* delegate corto/lang/post_action */
typedef struct corto_post_action {
    corto_delegatedata super;
} corto_post_action;

/* delegate corto/lang/name_action */
typedef struct corto_name_action {
    corto_delegatedata super;
} corto_name_action;

/* class corto/lang/type */
struct corto_type_s {
    corto_typeKind kind;
    bool reference;
    corto_attr attr;
    corto_type parent_type;
    corto_state parent_state;
    corto_type scope_type;
    corto_type scope_procedure_type;
    uint16_t flags;
    uint32_t size;
    uint16_t alignment;
    corto_objectseq metaprocedures;
    uintptr_t typecache;
    corto_pre_action init;
    corto_post_action deinit;
    corto_name_action nameof;
};

/* bitmask corto/lang/modifierMask */
typedef uint32_t corto_modifierMask;
    #define CORTO_GLOBAL (0x0)
    #define CORTO_LOCAL (0x1)
    #define CORTO_PRIVATE (0x2)
    #define CORTO_READONLY (0x4)
    #define CORTO_CONST (0x8)
    #define CORTO_NOT_NULL (0x10)
    #define CORTO_HIDDEN (0x20)
    #define CORTO_OPTIONAL (0x40)
    #define CORTO_OBSERVABLE (0x80)
    #define CORTO_KEY (0x104)
    #define CORTO_SINGLETON (0x280)

/* class corto/lang/unit */
typedef struct corto_unit_s *corto_unit;

/* class corto/lang/quantity */
typedef struct corto_quantity_s {
    corto_unit base_unit;
} *corto_quantity;

/* class corto/lang/unit */
struct corto_unit_s {
    corto_quantity quantity;
    corto_string symbol;
    corto_string conversion;
    corto_type type;
    uintptr_t toQuantity;
    uintptr_t fromQuantity;
};

/* int corto/lang/int8 */
typedef int8_t corto_int8;

/* class corto/lang/tag */
typedef struct corto_tag_s {
    int8_t __dummy;
} *corto_tag;

#ifndef corto_taglist_DEFINED
#define corto_taglist_DEFINED
typedef corto_ll corto_taglist;
#endif

/* class corto/lang/member */
typedef struct corto_member_s {
    corto_type type;
    corto_modifierMask modifiers;
    corto_string _default;
    corto_unit unit;
    corto_taglist tags;
    corto_state state;
    corto_string stateCondExpr;
    uint32_t id;
    uint32_t offset;
} *corto_member;

/* class corto/lang/alias */
typedef struct corto_alias_s {
    struct corto_member_s super;
    corto_member member;
} *corto_alias;

/* any */
typedef struct corto_any {corto_type type; void *value; uint8_t owner;} corto_any;

#ifndef corto_stringlist_DEFINED
#define corto_stringlist_DEFINED
typedef corto_ll corto_stringlist;
#endif

/* class corto/lang/package */
typedef struct corto_package_s {
    corto_string description;
    corto_string version;
    corto_string author;
    corto_string organization;
    corto_string url;
    corto_string repository;
    corto_string license;
    corto_string icon;
    corto_stringlist use;
    bool _public;
    bool managed;
} *corto_package;

/* class corto/lang/application */
typedef struct corto_application_s {
    struct corto_package_s super;
} *corto_application;

/* enum corto/lang/collectionKind */
typedef enum corto_collectionKind {
    CORTO_ARRAY = 0,
    CORTO_SEQUENCE = 1,
    CORTO_LIST = 2,
    CORTO_MAP = 3
} corto_collectionKind;

/* class corto/lang/collection */
typedef struct corto_collection_s {
    struct corto_type_s super;
    corto_collectionKind kind;
    corto_type element_type;
    uint32_t max;
} *corto_collection;

/* class corto/lang/array */
typedef struct corto_array_s {
    struct corto_collection_s super;
    corto_type element_type;
} *corto_array;

/* enum corto/lang/primitiveKind */
typedef enum corto_primitiveKind {
    CORTO_BINARY = 0,
    CORTO_BOOLEAN = 1,
    CORTO_CHARACTER = 2,
    CORTO_INTEGER = 3,
    CORTO_UINTEGER = 4,
    CORTO_FLOAT = 5,
    CORTO_TEXT = 6,
    CORTO_ENUM = 7,
    CORTO_BITMASK = 8
} corto_primitiveKind;

/* enum corto/lang/width */
typedef enum corto_width {
    CORTO_WIDTH_8 = 0,
    CORTO_WIDTH_16 = 1,
    CORTO_WIDTH_32 = 2,
    CORTO_WIDTH_64 = 3,
    CORTO_WIDTH_WORD = 4
} corto_width;

/* uint corto/lang/uint8 */
typedef uint8_t corto_uint8;

/* class corto/lang/primitive */
typedef struct corto_primitive_s {
    struct corto_type_s super;
    corto_primitiveKind kind;
    corto_width width;
    uint8_t convert_id;
} *corto_primitive;

/* class corto/lang/binary */
typedef struct corto_binary_s {
    struct corto_primitive_s super;
} *corto_binary;

/* class corto/lang/enum */
typedef struct corto_enum_s {
    struct corto_primitive_s super;
    corto_objectseq constants;
} *corto_enum;

/* class corto/lang/bitmask */
typedef struct corto_bitmask_s {
    struct corto_enum_s super;
} *corto_bitmask;

/* class corto/lang/boolean */
typedef struct corto_boolean_s {
    struct corto_primitive_s super;
} *corto_boolean;

/* int corto/lang/int32 */
typedef int32_t corto_int32;

typedef struct corto_int32seq {uint32_t length; int32_t *buffer;} corto_int32seq;

/* class corto/lang/case */
typedef struct corto_case_s {
    struct corto_member_s super;
    corto_int32seq discriminator;
} *corto_case;

/* character corto/lang/char */
typedef char corto_char;

/* class corto/lang/character */
typedef struct corto_character_s {
    struct corto_primitive_s super;
} *corto_character;

/* enum corto/lang/compositeKind */
typedef enum corto_compositeKind {
    CORTO_INTERFACE = 0,
    CORTO_STRUCT = 1,
    CORTO_UNION = 2,
    CORTO_CLASS = 3,
    CORTO_DELEGATE = 4,
    CORTO_PROCEDURE = 5
} corto_compositeKind;

/* class corto/lang/interface */
typedef struct corto_interface_s *corto_interface;

/* class corto/lang/interface */
struct corto_interface_s {
    struct corto_type_s super;
    corto_compositeKind kind;
    uint32_t next_member_id;
    corto_objectseq members;
    corto_objectseq methods;
    corto_interface base;
};

typedef struct corto_stringseq {uint32_t length; corto_string *buffer;} corto_stringseq;

/* class corto/lang/struct */
typedef struct corto_struct_s {
    struct corto_interface_s super;
    corto_modifierMask base_modifiers;
    corto_stringseq keys;
    corto_objectseq keycache;
} *corto_struct;

typedef struct corto_interfaceseq {uint32_t length; corto_interface *buffer;} corto_interfaceseq;

/* struct corto/lang/interfaceVector */
typedef struct corto_interfaceVector {
    corto_interface interface;
    corto_objectseq vector;
} corto_interfaceVector;

typedef struct corto_interfaceVectorseq {uint32_t length; corto_interfaceVector *buffer;} corto_interfaceVectorseq;

/* class corto/lang/class */
typedef struct corto_class_s {
    struct corto_struct_s super;
    corto_interfaceseq implements;
    corto_interfaceVectorseq interfaceVector;
    corto_pre_action construct;
    corto_post_action define;
    corto_pre_action validate;
    corto_post_action update;
    corto_post_action destruct;
    corto_post_action _delete;
} *corto_class;

/* int corto/lang/constant */
typedef int32_t corto_constant;

/* class corto/lang/container */
typedef struct corto_container_s {
    struct corto_class_s super;
    corto_type type;
    corto_string value;
} *corto_container;

/* class corto/lang/default */
typedef struct corto_default_s {
    struct corto_case_s super;
} *corto_default;

/* class corto/lang/delegate */
typedef struct corto_delegate_s {
    struct corto_struct_s super;
    corto_type return_type;
    bool is_reference;
    corto_parameterseq parameters;
} *corto_delegate;

/* enum corto/lang/equalityKind */
typedef enum corto_equalityKind {
    CORTO_EQ = 0,
    CORTO_LT = -1,
    CORTO_GT = 1,
    CORTO_NEQ = 2
} corto_equalityKind;

/* float corto/lang/float64 */
typedef double corto_float64;

/* class corto/lang/float */
typedef struct corto_float_s {
    struct corto_primitive_s super;
    double min;
    double max;
} *corto_float;

/* float corto/lang/float32 */
typedef float corto_float32;

/* int corto/lang/int64 */
typedef int64_t corto_int64;

/* class corto/lang/int */
typedef struct corto_int_s {
    struct corto_primitive_s super;
    int64_t min;
    int64_t max;
} *corto_int;

/* int corto/lang/int16 */
typedef int16_t corto_int16;

/* class corto/lang/iterator */
typedef struct corto_iterator_s {
    struct corto_type_s super;
    corto_type element_type;
} *corto_iterator;

/* class corto/lang/leaf */
typedef struct corto_leaf_s {
    struct corto_container_s super;
} *corto_leaf;

/* class corto/lang/list */
typedef struct corto_list_s {
    struct corto_collection_s super;
} *corto_list;

/* class corto/lang/map */
typedef struct corto_map_s {
    struct corto_collection_s super;
    corto_type key_type;
    corto_type element_type;
    uint32_t max;
} *corto_map;

/* procedure corto/lang/metaprocedure */
typedef struct corto_metaprocedure_s {
    struct corto_function_s super;
    bool referenceOnly;
} *corto_metaprocedure;

/* procedure corto/lang/method */
typedef struct corto_method_s {
    struct corto_function_s super;
    uint32_t index;
} *corto_method;

#ifndef corto_objectlist_DEFINED
#define corto_objectlist_DEFINED
typedef corto_ll corto_objectlist;
#endif

/* binary corto/lang/octet */
typedef uint8_t corto_octet;

/* procedure corto/lang/overridable */
typedef struct corto_overridable_s {
    struct corto_method_s super;
} *corto_overridable;

/* procedure corto/lang/override */
typedef struct corto_override_s {
    struct corto_method_s super;
} *corto_override;

/* class corto/lang/procedure */
typedef struct corto_procedure_s {
    struct corto_class_s super;
    bool has_this;
    corto_type this_type;
} *corto_procedure;

/* enum corto/lang/ref_kind */
typedef enum corto_ref_kind {
    CORTO_BY_TYPE = 0,
    CORTO_BY_VALUE = 1,
    CORTO_BY_REFERENCE = 2
} corto_ref_kind;

/* class corto/lang/sequence */
typedef struct corto_sequence_s {
    struct corto_collection_s super;
} *corto_sequence;

/* class corto/lang/table */
typedef struct corto_table_s {
    struct corto_container_s super;
} *corto_table;

/* class corto/lang/tableinstance */
typedef struct corto_tableinstance_s {
    corto_type type;
} *corto_tableinstance;

/* class corto/lang/target */
typedef struct corto_target_s {
    struct corto_struct_s super;
    corto_type type;
} *corto_target;

/* uint corto/lang/uint64 */
typedef uint64_t corto_uint64;

/* class corto/lang/text */
typedef struct corto_text_s {
    struct corto_primitive_s super;
    corto_width char_width;
    uint64_t length;
} *corto_text;

/* class corto/lang/tool */
typedef struct corto_tool_s {
    struct corto_package_s super;
} *corto_tool;

/* class corto/lang/uint */
typedef struct corto_uint_s {
    struct corto_primitive_s super;
    uint64_t min;
    uint64_t max;
} *corto_uint;

/* class corto/lang/union */
typedef struct corto_union_s {
    struct corto_interface_s super;
    corto_type discriminator;
} *corto_union;

/* unknown */
typedef void corto_unknown;

/* class corto/lang/verbatim */
typedef struct corto_verbatim_s {
    struct corto_primitive_s super;
    corto_string format;
} *corto_verbatim;

/* void */
typedef void corto_void;

typedef struct corto_wordseq {uint32_t length; uintptr_t *buffer;} corto_wordseq;


#ifdef __cplusplus
}
#endif
#endif
