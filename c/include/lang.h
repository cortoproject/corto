/* lang.h
 *
 * API convenience functions for C-language.
 * This file contains generated code. Do not modify!
 */

#ifndef CORTO_LANG__API_H
#define CORTO_LANG__API_H

#include <corto>
#include <corto/_project.h>
#ifdef __cplusplus
extern "C" {
#endif

/* alias */
CORTO_EXPORT corto_alias _corto_alias__create(corto_object _parent, const char *_id, corto_member member);
#define corto_alias__create(_parent, _id, member) _corto_alias__create(_parent, _id, corto_member(member))
#define corto_alias__create_auto(_parent, _id, member) corto_alias _id = corto_alias__create(_parent, #_id, member); (void)_id
#define corto_alias__declare(parent, id) (corto_alias)corto_declare(parent, id, corto_alias_o)
CORTO_EXPORT corto_int16 _corto_alias__update(corto_alias _this, corto_member member);
#define corto_alias__update(_this, member) _corto_alias__update(corto_alias(_this), corto_member(member))
CORTO_EXPORT corto_alias _corto_alias__assign(corto_alias _this, corto_member member);
#define corto_alias__optional_not_set NULL
#define corto_alias__optional_set(member) (corto_alias*)corto_alias__assign((corto_alias*)corto_ptr_new(corto_alias_o), member)
#define corto_alias__optional_set_cond(__cond, member) __cond ? (corto_alias*)corto_alias__assign((corto_alias*)corto_ptr_new(corto_alias_o), member) : NULL
#define corto_alias__unset(_this) _this ? corto_ptr_free(_this, corto_alias_o), 0 : 0; _this = NULL;
#define corto_alias__assign(_this, member) _corto_alias__assign(_this, corto_member(member))
#define corto_alias__set(_this, member) _this = _this ? _this : (corto_alias*)corto_ptr_new(corto_alias_o); _corto_alias__assign(_this, corto_member(member))

/* any */
CORTO_EXPORT corto_any* _corto_any__create(corto_object _parent, const char *_id, corto_type type, void *value);
#define corto_any__create(_parent, _id, type, value) _corto_any__create(_parent, _id, corto_type(type), value)
#define corto_any__create_auto(_parent, _id, type, value) corto_any* _id = corto_any__create(_parent, #_id, type, value); (void)_id
#define corto_any__declare(parent, id) (corto_any*)corto_declare(parent, id, corto_any_o)
CORTO_EXPORT corto_int16 _corto_any__update(corto_any* _this, corto_type type, void *value);
#define corto_any__update(_this, type, value) _corto_any__update(corto_any(_this), corto_type(type), value)
CORTO_EXPORT corto_any* _corto_any__assign(corto_any* _this, corto_type type, void *value);
#define corto_any__optional_not_set NULL
#define corto_any__optional_set(type, value) (corto_any*)corto_any__assign((corto_any*)corto_ptr_new(corto_any_o), type, value)
#define corto_any__optional_set_cond(__cond, type, value) __cond ? (corto_any*)corto_any__assign((corto_any*)corto_ptr_new(corto_any_o), type, value) : NULL
#define corto_any__unset(_this) _this ? corto_ptr_free(_this, corto_any_o), 0 : 0; _this = NULL;
#define corto_any__assign(_this, type, value) _corto_any__assign(_this, corto_type(type), value)
#define corto_any__set(_this, type, value) _this = _this ? _this : (corto_any*)corto_ptr_new(corto_any_o); _corto_any__assign(_this, corto_type(type), value)

/* application */
CORTO_EXPORT corto_application _corto_application__create(corto_object _parent, const char *_id);
#define corto_application__create(_parent, _id) _corto_application__create(_parent, _id)
#define corto_application__create_auto(_parent, _id) corto_application _id = corto_application__create(_parent, #_id); (void)_id
#define corto_application__declare(parent, id) (corto_application)corto_declare(parent, id, corto_application_o)
CORTO_EXPORT corto_int16 _corto_application__update(corto_application _this);
#define corto_application__update(_this) _corto_application__update(corto_application(_this))
CORTO_EXPORT corto_application _corto_application__assign(corto_application _this);
#define corto_application__optional_not_set NULL
#define corto_application__optional_set() (corto_application*)corto_application__assign((corto_application*)corto_ptr_new(corto_application_o))
#define corto_application__optional_set_cond(__cond) __cond ? (corto_application*)corto_application__assign((corto_application*)corto_ptr_new(corto_application_o)) : NULL
#define corto_application__unset(_this) _this ? corto_ptr_free(_this, corto_application_o), 0 : 0; _this = NULL;
#define corto_application__assign(_this) _corto_application__assign(_this)
#define corto_application__set(_this) _this = _this ? _this : (corto_application*)corto_ptr_new(corto_application_o); _corto_application__assign(_this)

/* array */
CORTO_EXPORT corto_array _corto_array__create(corto_object _parent, const char *_id, corto_type element_type, uint32_t max);
#define corto_array__create(_parent, _id, element_type, max) _corto_array__create(_parent, _id, corto_type(element_type), max)
#define corto_array__create_auto(_parent, _id, element_type, max) corto_array _id = corto_array__create(_parent, #_id, element_type, max); (void)_id
#define corto_array__declare(parent, id) (corto_array)corto_declare(parent, id, corto_array_o)
CORTO_EXPORT corto_int16 _corto_array__update(corto_array _this, corto_type element_type, uint32_t max);
#define corto_array__update(_this, element_type, max) _corto_array__update(corto_array(_this), corto_type(element_type), max)
CORTO_EXPORT corto_array _corto_array__assign(corto_array _this, corto_type element_type, uint32_t max);
#define corto_array__optional_not_set NULL
#define corto_array__optional_set(element_type, max) (corto_array*)corto_array__assign((corto_array*)corto_ptr_new(corto_array_o), element_type, max)
#define corto_array__optional_set_cond(__cond, element_type, max) __cond ? (corto_array*)corto_array__assign((corto_array*)corto_ptr_new(corto_array_o), element_type, max) : NULL
#define corto_array__unset(_this) _this ? corto_ptr_free(_this, corto_array_o), 0 : 0; _this = NULL;
#define corto_array__assign(_this, element_type, max) _corto_array__assign(_this, corto_type(element_type), max)
#define corto_array__set(_this, element_type, max) _this = _this ? _this : (corto_array*)corto_ptr_new(corto_array_o); _corto_array__assign(_this, corto_type(element_type), max)

/* attr */
CORTO_EXPORT corto_attr* _corto_attr__create(corto_object _parent, const char *_id, corto_attr value);
#define corto_attr__create(_parent, _id, value) _corto_attr__create(_parent, _id, value)
#define corto_attr__create_auto(_parent, _id, value) corto_attr* _id = corto_attr__create(_parent, #_id, value); (void)_id
#define corto_attr__declare(parent, id) (corto_attr*)corto_declare(parent, id, corto_attr_o)
CORTO_EXPORT corto_int16 _corto_attr__update(corto_attr* _this, corto_attr value);
#define corto_attr__update(_this, value) _corto_attr__update(corto_attr(_this), value)
CORTO_EXPORT corto_attr* _corto_attr__assign(corto_attr* _this, corto_attr value);
#define corto_attr__optional_not_set NULL
#define corto_attr__optional_set(value) (corto_attr*)corto_attr__assign((corto_attr*)corto_ptr_new(corto_attr_o), value)
#define corto_attr__optional_set_cond(__cond, value) __cond ? (corto_attr*)corto_attr__assign((corto_attr*)corto_ptr_new(corto_attr_o), value) : NULL
#define corto_attr__unset(_this) _this ? corto_ptr_free(_this, corto_attr_o), 0 : 0; _this = NULL;
#define corto_attr__assign(_this, value) _corto_attr__assign(_this, value)
#define corto_attr__set(_this, value) _this = _this ? _this : (corto_attr*)corto_ptr_new(corto_attr_o); _corto_attr__assign(_this, value)

/* binary */
CORTO_EXPORT corto_binary _corto_binary__create(corto_object _parent, const char *_id, corto_width width);
#define corto_binary__create(_parent, _id, width) _corto_binary__create(_parent, _id, width)
#define corto_binary__create_auto(_parent, _id, width) corto_binary _id = corto_binary__create(_parent, #_id, width); (void)_id
#define corto_binary__declare(parent, id) (corto_binary)corto_declare(parent, id, corto_binary_o)
CORTO_EXPORT corto_int16 _corto_binary__update(corto_binary _this, corto_width width);
#define corto_binary__update(_this, width) _corto_binary__update(corto_binary(_this), width)
CORTO_EXPORT corto_binary _corto_binary__assign(corto_binary _this, corto_width width);
#define corto_binary__optional_not_set NULL
#define corto_binary__optional_set(width) (corto_binary*)corto_binary__assign((corto_binary*)corto_ptr_new(corto_binary_o), width)
#define corto_binary__optional_set_cond(__cond, width) __cond ? (corto_binary*)corto_binary__assign((corto_binary*)corto_ptr_new(corto_binary_o), width) : NULL
#define corto_binary__unset(_this) _this ? corto_ptr_free(_this, corto_binary_o), 0 : 0; _this = NULL;
#define corto_binary__assign(_this, width) _corto_binary__assign(_this, width)
#define corto_binary__set(_this, width) _this = _this ? _this : (corto_binary*)corto_ptr_new(corto_binary_o); _corto_binary__assign(_this, width)

/* bitmask */
CORTO_EXPORT corto_bitmask _corto_bitmask__create(corto_object _parent, const char *_id);
#define corto_bitmask__create(_parent, _id) _corto_bitmask__create(_parent, _id)
#define corto_bitmask__create_auto(_parent, _id) corto_bitmask _id = corto_bitmask__create(_parent, #_id); (void)_id
#define corto_bitmask__declare(parent, id) (corto_bitmask)corto_declare(parent, id, corto_bitmask_o)
CORTO_EXPORT corto_int16 _corto_bitmask__update(corto_bitmask _this);
#define corto_bitmask__update(_this) _corto_bitmask__update(corto_bitmask(_this))
CORTO_EXPORT corto_bitmask _corto_bitmask__assign(corto_bitmask _this);
#define corto_bitmask__optional_not_set NULL
#define corto_bitmask__optional_set() (corto_bitmask*)corto_bitmask__assign((corto_bitmask*)corto_ptr_new(corto_bitmask_o))
#define corto_bitmask__optional_set_cond(__cond) __cond ? (corto_bitmask*)corto_bitmask__assign((corto_bitmask*)corto_ptr_new(corto_bitmask_o)) : NULL
#define corto_bitmask__unset(_this) _this ? corto_ptr_free(_this, corto_bitmask_o), 0 : 0; _this = NULL;
#define corto_bitmask__assign(_this) _corto_bitmask__assign(_this)
#define corto_bitmask__set(_this) _this = _this ? _this : (corto_bitmask*)corto_ptr_new(corto_bitmask_o); _corto_bitmask__assign(_this)

/* bool */
CORTO_EXPORT bool* _corto_bool__create(corto_object _parent, const char *_id, bool value);
#define corto_bool__create(_parent, _id, value) _corto_bool__create(_parent, _id, value)
#define corto_bool__create_auto(_parent, _id, value) bool* _id = corto_bool__create(_parent, #_id, value); (void)_id
#define corto_bool__declare(parent, id) (bool*)corto_declare(parent, id, corto_bool_o)
CORTO_EXPORT corto_int16 _corto_bool__update(bool* _this, bool value);
#define corto_bool__update(_this, value) _corto_bool__update(corto_bool(_this), value)
CORTO_EXPORT bool* _corto_bool__assign(bool* _this, bool value);
#define corto_bool__optional_not_set NULL
#define corto_bool__optional_set(value) (corto_bool*)corto_bool__assign((corto_bool*)corto_ptr_new(corto_bool_o), value)
#define corto_bool__optional_set_cond(__cond, value) __cond ? (corto_bool*)corto_bool__assign((corto_bool*)corto_ptr_new(corto_bool_o), value) : NULL
#define corto_bool__unset(_this) _this ? corto_ptr_free(_this, corto_bool_o), 0 : 0; _this = NULL;
#define corto_bool__assign(_this, value) _corto_bool__assign(_this, value)
#define corto_bool__set(_this, value) _this = _this ? _this : (corto_bool*)corto_ptr_new(corto_bool_o); _corto_bool__assign(_this, value)

/* boolean */
CORTO_EXPORT corto_boolean _corto_boolean__create(corto_object _parent, const char *_id);
#define corto_boolean__create(_parent, _id) _corto_boolean__create(_parent, _id)
#define corto_boolean__create_auto(_parent, _id) corto_boolean _id = corto_boolean__create(_parent, #_id); (void)_id
#define corto_boolean__declare(parent, id) (corto_boolean)corto_declare(parent, id, corto_boolean_o)
CORTO_EXPORT corto_int16 _corto_boolean__update(corto_boolean _this);
#define corto_boolean__update(_this) _corto_boolean__update(corto_boolean(_this))
CORTO_EXPORT corto_boolean _corto_boolean__assign(corto_boolean _this);
#define corto_boolean__optional_not_set NULL
#define corto_boolean__optional_set() (corto_boolean*)corto_boolean__assign((corto_boolean*)corto_ptr_new(corto_boolean_o))
#define corto_boolean__optional_set_cond(__cond) __cond ? (corto_boolean*)corto_boolean__assign((corto_boolean*)corto_ptr_new(corto_boolean_o)) : NULL
#define corto_boolean__unset(_this) _this ? corto_ptr_free(_this, corto_boolean_o), 0 : 0; _this = NULL;
#define corto_boolean__assign(_this) _corto_boolean__assign(_this)
#define corto_boolean__set(_this) _this = _this ? _this : (corto_boolean*)corto_ptr_new(corto_boolean_o); _corto_boolean__assign(_this)

/* case */
CORTO_EXPORT corto_case _corto_case__create(corto_object _parent, const char *_id, corto_int32seq discriminator, corto_type type, corto_modifierMask modifiers);
#define corto_case__create(_parent, _id, discriminator, type, modifiers) _corto_case__create(_parent, _id, discriminator, corto_type(type), modifiers)
#define corto_case__create_auto(_parent, _id, discriminator, type, modifiers) corto_case _id = corto_case__create(_parent, #_id, discriminator, type, modifiers); (void)_id
#define corto_case__declare(parent, id) (corto_case)corto_declare(parent, id, corto_case_o)
CORTO_EXPORT corto_int16 _corto_case__update(corto_case _this, corto_int32seq discriminator, corto_type type, corto_modifierMask modifiers);
#define corto_case__update(_this, discriminator, type, modifiers) _corto_case__update(corto_case(_this), discriminator, corto_type(type), modifiers)
CORTO_EXPORT corto_case _corto_case__assign(corto_case _this, corto_int32seq discriminator, corto_type type, corto_modifierMask modifiers);
#define corto_case__optional_not_set NULL
#define corto_case__optional_set(discriminator, type, modifiers) (corto_case*)corto_case__assign((corto_case*)corto_ptr_new(corto_case_o), discriminator, type, modifiers)
#define corto_case__optional_set_cond(__cond, discriminator, type, modifiers) __cond ? (corto_case*)corto_case__assign((corto_case*)corto_ptr_new(corto_case_o), discriminator, type, modifiers) : NULL
#define corto_case__unset(_this) _this ? corto_ptr_free(_this, corto_case_o), 0 : 0; _this = NULL;
#define corto_case__assign(_this, discriminator, type, modifiers) _corto_case__assign(_this, discriminator, corto_type(type), modifiers)
#define corto_case__set(_this, discriminator, type, modifiers) _this = _this ? _this : (corto_case*)corto_ptr_new(corto_case_o); _corto_case__assign(_this, discriminator, corto_type(type), modifiers)

/* char */
CORTO_EXPORT char* _corto_char__create(corto_object _parent, const char *_id, char value);
#define corto_char__create(_parent, _id, value) _corto_char__create(_parent, _id, value)
#define corto_char__create_auto(_parent, _id, value) char* _id = corto_char__create(_parent, #_id, value); (void)_id
#define corto_char__declare(parent, id) (char*)corto_declare(parent, id, corto_char_o)
CORTO_EXPORT corto_int16 _corto_char__update(char* _this, char value);
#define corto_char__update(_this, value) _corto_char__update(corto_char(_this), value)
CORTO_EXPORT char* _corto_char__assign(char* _this, char value);
#define corto_char__optional_not_set NULL
#define corto_char__optional_set(value) (corto_char*)corto_char__assign((corto_char*)corto_ptr_new(corto_char_o), value)
#define corto_char__optional_set_cond(__cond, value) __cond ? (corto_char*)corto_char__assign((corto_char*)corto_ptr_new(corto_char_o), value) : NULL
#define corto_char__unset(_this) _this ? corto_ptr_free(_this, corto_char_o), 0 : 0; _this = NULL;
#define corto_char__assign(_this, value) _corto_char__assign(_this, value)
#define corto_char__set(_this, value) _this = _this ? _this : (corto_char*)corto_ptr_new(corto_char_o); _corto_char__assign(_this, value)

/* character */
CORTO_EXPORT corto_character _corto_character__create(corto_object _parent, const char *_id, corto_width width);
#define corto_character__create(_parent, _id, width) _corto_character__create(_parent, _id, width)
#define corto_character__create_auto(_parent, _id, width) corto_character _id = corto_character__create(_parent, #_id, width); (void)_id
#define corto_character__declare(parent, id) (corto_character)corto_declare(parent, id, corto_character_o)
CORTO_EXPORT corto_int16 _corto_character__update(corto_character _this, corto_width width);
#define corto_character__update(_this, width) _corto_character__update(corto_character(_this), width)
CORTO_EXPORT corto_character _corto_character__assign(corto_character _this, corto_width width);
#define corto_character__optional_not_set NULL
#define corto_character__optional_set(width) (corto_character*)corto_character__assign((corto_character*)corto_ptr_new(corto_character_o), width)
#define corto_character__optional_set_cond(__cond, width) __cond ? (corto_character*)corto_character__assign((corto_character*)corto_ptr_new(corto_character_o), width) : NULL
#define corto_character__unset(_this) _this ? corto_ptr_free(_this, corto_character_o), 0 : 0; _this = NULL;
#define corto_character__assign(_this, width) _corto_character__assign(_this, width)
#define corto_character__set(_this, width) _this = _this ? _this : (corto_character*)corto_ptr_new(corto_character_o); _corto_character__assign(_this, width)

/* class */
CORTO_EXPORT corto_class _corto_class__create(corto_object _parent, const char *_id, corto_interface base, corto_modifierMask base_modifiers, corto_interfaceseq implements);
#define corto_class__create(_parent, _id, base, base_modifiers, implements) _corto_class__create(_parent, _id, corto_interface(base), base_modifiers, implements)
#define corto_class__create_auto(_parent, _id, base, base_modifiers, implements) corto_class _id = corto_class__create(_parent, #_id, base, base_modifiers, implements); (void)_id
#define corto_class__declare(parent, id) (corto_class)corto_declare(parent, id, corto_class_o)
CORTO_EXPORT corto_int16 _corto_class__update(corto_class _this, corto_interface base, corto_modifierMask base_modifiers, corto_interfaceseq implements);
#define corto_class__update(_this, base, base_modifiers, implements) _corto_class__update(corto_class(_this), corto_interface(base), base_modifiers, implements)
CORTO_EXPORT corto_class _corto_class__assign(corto_class _this, corto_interface base, corto_modifierMask base_modifiers, corto_interfaceseq implements);
#define corto_class__optional_not_set NULL
#define corto_class__optional_set(base, base_modifiers, implements) (corto_class*)corto_class__assign((corto_class*)corto_ptr_new(corto_class_o), base, base_modifiers, implements)
#define corto_class__optional_set_cond(__cond, base, base_modifiers, implements) __cond ? (corto_class*)corto_class__assign((corto_class*)corto_ptr_new(corto_class_o), base, base_modifiers, implements) : NULL
#define corto_class__unset(_this) _this ? corto_ptr_free(_this, corto_class_o), 0 : 0; _this = NULL;
#define corto_class__assign(_this, base, base_modifiers, implements) _corto_class__assign(_this, corto_interface(base), base_modifiers, implements)
#define corto_class__set(_this, base, base_modifiers, implements) _this = _this ? _this : (corto_class*)corto_ptr_new(corto_class_o); _corto_class__assign(_this, corto_interface(base), base_modifiers, implements)

/* collection */
CORTO_EXPORT corto_collection _corto_collection__create(corto_object _parent, const char *_id, corto_type element_type, uint32_t max);
#define corto_collection__create(_parent, _id, element_type, max) _corto_collection__create(_parent, _id, corto_type(element_type), max)
#define corto_collection__create_auto(_parent, _id, element_type, max) corto_collection _id = corto_collection__create(_parent, #_id, element_type, max); (void)_id
#define corto_collection__declare(parent, id) (corto_collection)corto_declare(parent, id, corto_collection_o)
CORTO_EXPORT corto_int16 _corto_collection__update(corto_collection _this, corto_type element_type, uint32_t max);
#define corto_collection__update(_this, element_type, max) _corto_collection__update(corto_collection(_this), corto_type(element_type), max)
CORTO_EXPORT corto_collection _corto_collection__assign(corto_collection _this, corto_type element_type, uint32_t max);
#define corto_collection__optional_not_set NULL
#define corto_collection__optional_set(element_type, max) (corto_collection*)corto_collection__assign((corto_collection*)corto_ptr_new(corto_collection_o), element_type, max)
#define corto_collection__optional_set_cond(__cond, element_type, max) __cond ? (corto_collection*)corto_collection__assign((corto_collection*)corto_ptr_new(corto_collection_o), element_type, max) : NULL
#define corto_collection__unset(_this) _this ? corto_ptr_free(_this, corto_collection_o), 0 : 0; _this = NULL;
#define corto_collection__assign(_this, element_type, max) _corto_collection__assign(_this, corto_type(element_type), max)
#define corto_collection__set(_this, element_type, max) _this = _this ? _this : (corto_collection*)corto_ptr_new(corto_collection_o); _corto_collection__assign(_this, corto_type(element_type), max)

/* collectionKind */
CORTO_EXPORT corto_collectionKind* _corto_collectionKind__create(corto_object _parent, const char *_id, corto_collectionKind value);
#define corto_collectionKind__create(_parent, _id, value) _corto_collectionKind__create(_parent, _id, value)
#define corto_collectionKind__create_auto(_parent, _id, value) corto_collectionKind* _id = corto_collectionKind__create(_parent, #_id, value); (void)_id
#define corto_collectionKind__declare(parent, id) (corto_collectionKind*)corto_declare(parent, id, corto_collectionKind_o)
CORTO_EXPORT corto_int16 _corto_collectionKind__update(corto_collectionKind* _this, corto_collectionKind value);
#define corto_collectionKind__update(_this, value) _corto_collectionKind__update(corto_collectionKind(_this), value)
CORTO_EXPORT corto_collectionKind* _corto_collectionKind__assign(corto_collectionKind* _this, corto_collectionKind value);
#define corto_collectionKind__optional_not_set NULL
#define corto_collectionKind__optional_set(value) (corto_collectionKind*)corto_collectionKind__assign((corto_collectionKind*)corto_ptr_new(corto_collectionKind_o), value)
#define corto_collectionKind__optional_set_cond(__cond, value) __cond ? (corto_collectionKind*)corto_collectionKind__assign((corto_collectionKind*)corto_ptr_new(corto_collectionKind_o), value) : NULL
#define corto_collectionKind__unset(_this) _this ? corto_ptr_free(_this, corto_collectionKind_o), 0 : 0; _this = NULL;
#define corto_collectionKind__assign(_this, value) _corto_collectionKind__assign(_this, value)
#define corto_collectionKind__set(_this, value) _this = _this ? _this : (corto_collectionKind*)corto_ptr_new(corto_collectionKind_o); _corto_collectionKind__assign(_this, value)

/* compositeKind */
CORTO_EXPORT corto_compositeKind* _corto_compositeKind__create(corto_object _parent, const char *_id, corto_compositeKind value);
#define corto_compositeKind__create(_parent, _id, value) _corto_compositeKind__create(_parent, _id, value)
#define corto_compositeKind__create_auto(_parent, _id, value) corto_compositeKind* _id = corto_compositeKind__create(_parent, #_id, value); (void)_id
#define corto_compositeKind__declare(parent, id) (corto_compositeKind*)corto_declare(parent, id, corto_compositeKind_o)
CORTO_EXPORT corto_int16 _corto_compositeKind__update(corto_compositeKind* _this, corto_compositeKind value);
#define corto_compositeKind__update(_this, value) _corto_compositeKind__update(corto_compositeKind(_this), value)
CORTO_EXPORT corto_compositeKind* _corto_compositeKind__assign(corto_compositeKind* _this, corto_compositeKind value);
#define corto_compositeKind__optional_not_set NULL
#define corto_compositeKind__optional_set(value) (corto_compositeKind*)corto_compositeKind__assign((corto_compositeKind*)corto_ptr_new(corto_compositeKind_o), value)
#define corto_compositeKind__optional_set_cond(__cond, value) __cond ? (corto_compositeKind*)corto_compositeKind__assign((corto_compositeKind*)corto_ptr_new(corto_compositeKind_o), value) : NULL
#define corto_compositeKind__unset(_this) _this ? corto_ptr_free(_this, corto_compositeKind_o), 0 : 0; _this = NULL;
#define corto_compositeKind__assign(_this, value) _corto_compositeKind__assign(_this, value)
#define corto_compositeKind__set(_this, value) _this = _this ? _this : (corto_compositeKind*)corto_ptr_new(corto_compositeKind_o); _corto_compositeKind__assign(_this, value)

/* constant */
CORTO_EXPORT int32_t* _corto_constant__create(corto_object _parent, const char *_id, int32_t value);
#define corto_constant__create(_parent, _id, value) _corto_constant__create(_parent, _id, value)
#define corto_constant__create_auto(_parent, _id, value) int32_t* _id = corto_constant__create(_parent, #_id, value); (void)_id
#define corto_constant__declare(parent, id) (int32_t*)corto_declare(parent, id, corto_constant_o)
CORTO_EXPORT corto_int16 _corto_constant__update(int32_t* _this, int32_t value);
#define corto_constant__update(_this, value) _corto_constant__update(corto_constant(_this), value)
CORTO_EXPORT int32_t* _corto_constant__assign(int32_t* _this, int32_t value);
#define corto_constant__optional_not_set NULL
#define corto_constant__optional_set(value) (corto_constant*)corto_constant__assign((corto_constant*)corto_ptr_new(corto_constant_o), value)
#define corto_constant__optional_set_cond(__cond, value) __cond ? (corto_constant*)corto_constant__assign((corto_constant*)corto_ptr_new(corto_constant_o), value) : NULL
#define corto_constant__unset(_this) _this ? corto_ptr_free(_this, corto_constant_o), 0 : 0; _this = NULL;
#define corto_constant__assign(_this, value) _corto_constant__assign(_this, value)
#define corto_constant__set(_this, value) _this = _this ? _this : (corto_constant*)corto_ptr_new(corto_constant_o); _corto_constant__assign(_this, value)

/* container */
CORTO_EXPORT corto_container _corto_container__create(corto_object _parent, const char *_id, corto_interface base, corto_modifierMask base_modifiers, corto_interfaceseq implements, corto_type type, const char * value);
#define corto_container__create(_parent, _id, base, base_modifiers, implements, type, value) _corto_container__create(_parent, _id, corto_interface(base), base_modifiers, implements, corto_type(type), value)
#define corto_container__create_auto(_parent, _id, base, base_modifiers, implements, type, value) corto_container _id = corto_container__create(_parent, #_id, base, base_modifiers, implements, type, value); (void)_id
#define corto_container__declare(parent, id) (corto_container)corto_declare(parent, id, corto_container_o)
CORTO_EXPORT corto_int16 _corto_container__update(corto_container _this, corto_interface base, corto_modifierMask base_modifiers, corto_interfaceseq implements, corto_type type, const char * value);
#define corto_container__update(_this, base, base_modifiers, implements, type, value) _corto_container__update(corto_container(_this), corto_interface(base), base_modifiers, implements, corto_type(type), value)
CORTO_EXPORT corto_container _corto_container__assign(corto_container _this, corto_interface base, corto_modifierMask base_modifiers, corto_interfaceseq implements, corto_type type, const char * value);
#define corto_container__optional_not_set NULL
#define corto_container__optional_set(base, base_modifiers, implements, type, value) (corto_container*)corto_container__assign((corto_container*)corto_ptr_new(corto_container_o), base, base_modifiers, implements, type, value)
#define corto_container__optional_set_cond(__cond, base, base_modifiers, implements, type, value) __cond ? (corto_container*)corto_container__assign((corto_container*)corto_ptr_new(corto_container_o), base, base_modifiers, implements, type, value) : NULL
#define corto_container__unset(_this) _this ? corto_ptr_free(_this, corto_container_o), 0 : 0; _this = NULL;
#define corto_container__assign(_this, base, base_modifiers, implements, type, value) _corto_container__assign(_this, corto_interface(base), base_modifiers, implements, corto_type(type), value)
#define corto_container__set(_this, base, base_modifiers, implements, type, value) _this = _this ? _this : (corto_container*)corto_ptr_new(corto_container_o); _corto_container__assign(_this, corto_interface(base), base_modifiers, implements, corto_type(type), value)

/* default */
CORTO_EXPORT corto_default _corto_default__create(corto_object _parent, const char *_id, corto_type type);
#define corto_default__create(_parent, _id, type) _corto_default__create(_parent, _id, corto_type(type))
#define corto_default__create_auto(_parent, _id, type) corto_default _id = corto_default__create(_parent, #_id, type); (void)_id
#define corto_default__declare(parent, id) (corto_default)corto_declare(parent, id, corto_default_o)
CORTO_EXPORT corto_int16 _corto_default__update(corto_default _this, corto_type type);
#define corto_default__update(_this, type) _corto_default__update(corto_default(_this), corto_type(type))
CORTO_EXPORT corto_default _corto_default__assign(corto_default _this, corto_type type);
#define corto_default__optional_not_set NULL
#define corto_default__optional_set(type) (corto_default*)corto_default__assign((corto_default*)corto_ptr_new(corto_default_o), type)
#define corto_default__optional_set_cond(__cond, type) __cond ? (corto_default*)corto_default__assign((corto_default*)corto_ptr_new(corto_default_o), type) : NULL
#define corto_default__unset(_this) _this ? corto_ptr_free(_this, corto_default_o), 0 : 0; _this = NULL;
#define corto_default__assign(_this, type) _corto_default__assign(_this, corto_type(type))
#define corto_default__set(_this, type) _this = _this ? _this : (corto_default*)corto_ptr_new(corto_default_o); _corto_default__assign(_this, corto_type(type))

/* delegate */
CORTO_EXPORT corto_delegate _corto_delegate__create(corto_object _parent, const char *_id, corto_type return_type, bool is_reference, corto_parameterseq parameters);
#define corto_delegate__create(_parent, _id, return_type, is_reference, parameters) _corto_delegate__create(_parent, _id, corto_type(return_type), is_reference, parameters)
#define corto_delegate__create_auto(_parent, _id, return_type, is_reference, parameters) corto_delegate _id = corto_delegate__create(_parent, #_id, return_type, is_reference, parameters); (void)_id
#define corto_delegate__declare(parent, id) (corto_delegate)corto_declare(parent, id, corto_delegate_o)
CORTO_EXPORT corto_int16 _corto_delegate__update(corto_delegate _this, corto_type return_type, bool is_reference, corto_parameterseq parameters);
#define corto_delegate__update(_this, return_type, is_reference, parameters) _corto_delegate__update(corto_delegate(_this), corto_type(return_type), is_reference, parameters)
CORTO_EXPORT corto_delegate _corto_delegate__assign(corto_delegate _this, corto_type return_type, bool is_reference, corto_parameterseq parameters);
#define corto_delegate__optional_not_set NULL
#define corto_delegate__optional_set(return_type, is_reference, parameters) (corto_delegate*)corto_delegate__assign((corto_delegate*)corto_ptr_new(corto_delegate_o), return_type, is_reference, parameters)
#define corto_delegate__optional_set_cond(__cond, return_type, is_reference, parameters) __cond ? (corto_delegate*)corto_delegate__assign((corto_delegate*)corto_ptr_new(corto_delegate_o), return_type, is_reference, parameters) : NULL
#define corto_delegate__unset(_this) _this ? corto_ptr_free(_this, corto_delegate_o), 0 : 0; _this = NULL;
#define corto_delegate__assign(_this, return_type, is_reference, parameters) _corto_delegate__assign(_this, corto_type(return_type), is_reference, parameters)
#define corto_delegate__set(_this, return_type, is_reference, parameters) _this = _this ? _this : (corto_delegate*)corto_ptr_new(corto_delegate_o); _corto_delegate__assign(_this, corto_type(return_type), is_reference, parameters)

/* delegatedata */
CORTO_EXPORT corto_delegatedata* _corto_delegatedata__create(corto_object _parent, const char *_id, corto_object instance, corto_function procedure);
#define corto_delegatedata__create(_parent, _id, instance, procedure) _corto_delegatedata__create(_parent, _id, instance, corto_function(procedure))
#define corto_delegatedata__create_auto(_parent, _id, instance, procedure) corto_delegatedata* _id = corto_delegatedata__create(_parent, #_id, instance, procedure); (void)_id
#define corto_delegatedata__declare(parent, id) (corto_delegatedata*)corto_declare(parent, id, corto_delegatedata_o)
CORTO_EXPORT corto_int16 _corto_delegatedata__update(corto_delegatedata* _this, corto_object instance, corto_function procedure);
#define corto_delegatedata__update(_this, instance, procedure) _corto_delegatedata__update(corto_delegatedata(_this), instance, corto_function(procedure))
CORTO_EXPORT corto_delegatedata* _corto_delegatedata__assign(corto_delegatedata* _this, corto_object instance, corto_function procedure);
#define corto_delegatedata__optional_not_set NULL
#define corto_delegatedata__optional_set(instance, procedure) (corto_delegatedata*)corto_delegatedata__assign((corto_delegatedata*)corto_ptr_new(corto_delegatedata_o), instance, procedure)
#define corto_delegatedata__optional_set_cond(__cond, instance, procedure) __cond ? (corto_delegatedata*)corto_delegatedata__assign((corto_delegatedata*)corto_ptr_new(corto_delegatedata_o), instance, procedure) : NULL
#define corto_delegatedata__unset(_this) _this ? corto_ptr_free(_this, corto_delegatedata_o), 0 : 0; _this = NULL;
#define corto_delegatedata__assign(_this, instance, procedure) _corto_delegatedata__assign(_this, instance, corto_function(procedure))
#define corto_delegatedata__set(_this, instance, procedure) _this = _this ? _this : (corto_delegatedata*)corto_ptr_new(corto_delegatedata_o); _corto_delegatedata__assign(_this, instance, corto_function(procedure))

/* enum */
CORTO_EXPORT corto_enum _corto_enum__create(corto_object _parent, const char *_id);
#define corto_enum__create(_parent, _id) _corto_enum__create(_parent, _id)
#define corto_enum__create_auto(_parent, _id) corto_enum _id = corto_enum__create(_parent, #_id); (void)_id
#define corto_enum__declare(parent, id) (corto_enum)corto_declare(parent, id, corto_enum_o)
CORTO_EXPORT corto_int16 _corto_enum__update(corto_enum _this);
#define corto_enum__update(_this) _corto_enum__update(corto_enum(_this))
CORTO_EXPORT corto_enum _corto_enum__assign(corto_enum _this);
#define corto_enum__optional_not_set NULL
#define corto_enum__optional_set() (corto_enum*)corto_enum__assign((corto_enum*)corto_ptr_new(corto_enum_o))
#define corto_enum__optional_set_cond(__cond) __cond ? (corto_enum*)corto_enum__assign((corto_enum*)corto_ptr_new(corto_enum_o)) : NULL
#define corto_enum__unset(_this) _this ? corto_ptr_free(_this, corto_enum_o), 0 : 0; _this = NULL;
#define corto_enum__assign(_this) _corto_enum__assign(_this)
#define corto_enum__set(_this) _this = _this ? _this : (corto_enum*)corto_ptr_new(corto_enum_o); _corto_enum__assign(_this)

/* equalityKind */
CORTO_EXPORT corto_equalityKind* _corto_equalityKind__create(corto_object _parent, const char *_id, corto_equalityKind value);
#define corto_equalityKind__create(_parent, _id, value) _corto_equalityKind__create(_parent, _id, value)
#define corto_equalityKind__create_auto(_parent, _id, value) corto_equalityKind* _id = corto_equalityKind__create(_parent, #_id, value); (void)_id
#define corto_equalityKind__declare(parent, id) (corto_equalityKind*)corto_declare(parent, id, corto_equalityKind_o)
CORTO_EXPORT corto_int16 _corto_equalityKind__update(corto_equalityKind* _this, corto_equalityKind value);
#define corto_equalityKind__update(_this, value) _corto_equalityKind__update(corto_equalityKind(_this), value)
CORTO_EXPORT corto_equalityKind* _corto_equalityKind__assign(corto_equalityKind* _this, corto_equalityKind value);
#define corto_equalityKind__optional_not_set NULL
#define corto_equalityKind__optional_set(value) (corto_equalityKind*)corto_equalityKind__assign((corto_equalityKind*)corto_ptr_new(corto_equalityKind_o), value)
#define corto_equalityKind__optional_set_cond(__cond, value) __cond ? (corto_equalityKind*)corto_equalityKind__assign((corto_equalityKind*)corto_ptr_new(corto_equalityKind_o), value) : NULL
#define corto_equalityKind__unset(_this) _this ? corto_ptr_free(_this, corto_equalityKind_o), 0 : 0; _this = NULL;
#define corto_equalityKind__assign(_this, value) _corto_equalityKind__assign(_this, value)
#define corto_equalityKind__set(_this, value) _this = _this ? _this : (corto_equalityKind*)corto_ptr_new(corto_equalityKind_o); _corto_equalityKind__assign(_this, value)

/* float */
CORTO_EXPORT corto_float _corto_float__create(corto_object _parent, const char *_id, corto_width width, double min, double max);
#define corto_float__create(_parent, _id, width, min, max) _corto_float__create(_parent, _id, width, min, max)
#define corto_float__create_auto(_parent, _id, width, min, max) corto_float _id = corto_float__create(_parent, #_id, width, min, max); (void)_id
#define corto_float__declare(parent, id) (corto_float)corto_declare(parent, id, corto_float_o)
CORTO_EXPORT corto_int16 _corto_float__update(corto_float _this, corto_width width, double min, double max);
#define corto_float__update(_this, width, min, max) _corto_float__update(corto_float(_this), width, min, max)
CORTO_EXPORT corto_float _corto_float__assign(corto_float _this, corto_width width, double min, double max);
#define corto_float__optional_not_set NULL
#define corto_float__optional_set(width, min, max) (corto_float*)corto_float__assign((corto_float*)corto_ptr_new(corto_float_o), width, min, max)
#define corto_float__optional_set_cond(__cond, width, min, max) __cond ? (corto_float*)corto_float__assign((corto_float*)corto_ptr_new(corto_float_o), width, min, max) : NULL
#define corto_float__unset(_this) _this ? corto_ptr_free(_this, corto_float_o), 0 : 0; _this = NULL;
#define corto_float__assign(_this, width, min, max) _corto_float__assign(_this, width, min, max)
#define corto_float__set(_this, width, min, max) _this = _this ? _this : (corto_float*)corto_ptr_new(corto_float_o); _corto_float__assign(_this, width, min, max)

/* float32 */
CORTO_EXPORT float* _corto_float32__create(corto_object _parent, const char *_id, float value);
#define corto_float32__create(_parent, _id, value) _corto_float32__create(_parent, _id, value)
#define corto_float32__create_auto(_parent, _id, value) float* _id = corto_float32__create(_parent, #_id, value); (void)_id
#define corto_float32__declare(parent, id) (float*)corto_declare(parent, id, corto_float32_o)
CORTO_EXPORT corto_int16 _corto_float32__update(float* _this, float value);
#define corto_float32__update(_this, value) _corto_float32__update(corto_float32(_this), value)
CORTO_EXPORT float* _corto_float32__assign(float* _this, float value);
#define corto_float32__optional_not_set NULL
#define corto_float32__optional_set(value) (corto_float32*)corto_float32__assign((corto_float32*)corto_ptr_new(corto_float32_o), value)
#define corto_float32__optional_set_cond(__cond, value) __cond ? (corto_float32*)corto_float32__assign((corto_float32*)corto_ptr_new(corto_float32_o), value) : NULL
#define corto_float32__unset(_this) _this ? corto_ptr_free(_this, corto_float32_o), 0 : 0; _this = NULL;
#define corto_float32__assign(_this, value) _corto_float32__assign(_this, value)
#define corto_float32__set(_this, value) _this = _this ? _this : (corto_float32*)corto_ptr_new(corto_float32_o); _corto_float32__assign(_this, value)

/* float64 */
CORTO_EXPORT double* _corto_float64__create(corto_object _parent, const char *_id, double value);
#define corto_float64__create(_parent, _id, value) _corto_float64__create(_parent, _id, value)
#define corto_float64__create_auto(_parent, _id, value) double* _id = corto_float64__create(_parent, #_id, value); (void)_id
#define corto_float64__declare(parent, id) (double*)corto_declare(parent, id, corto_float64_o)
CORTO_EXPORT corto_int16 _corto_float64__update(double* _this, double value);
#define corto_float64__update(_this, value) _corto_float64__update(corto_float64(_this), value)
CORTO_EXPORT double* _corto_float64__assign(double* _this, double value);
#define corto_float64__optional_not_set NULL
#define corto_float64__optional_set(value) (corto_float64*)corto_float64__assign((corto_float64*)corto_ptr_new(corto_float64_o), value)
#define corto_float64__optional_set_cond(__cond, value) __cond ? (corto_float64*)corto_float64__assign((corto_float64*)corto_ptr_new(corto_float64_o), value) : NULL
#define corto_float64__unset(_this) _this ? corto_ptr_free(_this, corto_float64_o), 0 : 0; _this = NULL;
#define corto_float64__assign(_this, value) _corto_float64__assign(_this, value)
#define corto_float64__set(_this, value) _this = _this ? _this : (corto_float64*)corto_ptr_new(corto_float64_o); _corto_float64__assign(_this, value)

/* function */
CORTO_EXPORT corto_function _corto_function__create(corto_object _parent, const char *_id, corto_type return_type, bool is_reference, void(*_impl)(void));
#define corto_function__create(_parent, _id, return_type, is_reference, _impl) _corto_function__create(_parent, _id, corto_type(return_type), is_reference, (void(*)(void))_impl)
#define corto_function__create_auto(_parent, _id, return_type, is_reference, _impl) corto_function _id = corto_function__create(_parent, #_id, return_type, is_reference, _impl); (void)_id
#define corto_function__declare(parent, id) (corto_function)corto_declare(parent, id, corto_function_o)
CORTO_EXPORT corto_int16 _corto_function__update(corto_function _this, corto_type return_type, bool is_reference, void(*_impl)(void));
#define corto_function__update(_this, return_type, is_reference, _impl) _corto_function__update(corto_function(_this), corto_type(return_type), is_reference, (void(*)(void))_impl)
CORTO_EXPORT corto_function _corto_function__assign(corto_function _this, corto_type return_type, bool is_reference, void(*_impl)(void));
#define corto_function__optional_not_set NULL
#define corto_function__optional_set(return_type, is_reference, _impl) (corto_function*)corto_function__assign((corto_function*)corto_ptr_new(corto_function_o), return_type, is_reference, _impl)
#define corto_function__optional_set_cond(__cond, return_type, is_reference, _impl) __cond ? (corto_function*)corto_function__assign((corto_function*)corto_ptr_new(corto_function_o), return_type, is_reference, _impl) : NULL
#define corto_function__unset(_this) _this ? corto_ptr_free(_this, corto_function_o), 0 : 0; _this = NULL;
#define corto_function__assign(_this, return_type, is_reference, _impl) _corto_function__assign(_this, corto_type(return_type), is_reference, (void(*)(void))_impl)
#define corto_function__set(_this, return_type, is_reference, _impl) _this = _this ? _this : (corto_function*)corto_ptr_new(corto_function_o); _corto_function__assign(_this, corto_type(return_type), is_reference, (void(*)(void))_impl)

/* inout */
CORTO_EXPORT corto_inout* _corto_inout__create(corto_object _parent, const char *_id, corto_inout value);
#define corto_inout__create(_parent, _id, value) _corto_inout__create(_parent, _id, value)
#define corto_inout__create_auto(_parent, _id, value) corto_inout* _id = corto_inout__create(_parent, #_id, value); (void)_id
#define corto_inout__declare(parent, id) (corto_inout*)corto_declare(parent, id, corto_inout_o)
CORTO_EXPORT corto_int16 _corto_inout__update(corto_inout* _this, corto_inout value);
#define corto_inout__update(_this, value) _corto_inout__update(corto_inout(_this), value)
CORTO_EXPORT corto_inout* _corto_inout__assign(corto_inout* _this, corto_inout value);
#define corto_inout__optional_not_set NULL
#define corto_inout__optional_set(value) (corto_inout*)corto_inout__assign((corto_inout*)corto_ptr_new(corto_inout_o), value)
#define corto_inout__optional_set_cond(__cond, value) __cond ? (corto_inout*)corto_inout__assign((corto_inout*)corto_ptr_new(corto_inout_o), value) : NULL
#define corto_inout__unset(_this) _this ? corto_ptr_free(_this, corto_inout_o), 0 : 0; _this = NULL;
#define corto_inout__assign(_this, value) _corto_inout__assign(_this, value)
#define corto_inout__set(_this, value) _this = _this ? _this : (corto_inout*)corto_ptr_new(corto_inout_o); _corto_inout__assign(_this, value)

/* int */
CORTO_EXPORT corto_int _corto_int__create(corto_object _parent, const char *_id, corto_width width, int64_t min, int64_t max);
#define corto_int__create(_parent, _id, width, min, max) _corto_int__create(_parent, _id, width, min, max)
#define corto_int__create_auto(_parent, _id, width, min, max) corto_int _id = corto_int__create(_parent, #_id, width, min, max); (void)_id
#define corto_int__declare(parent, id) (corto_int)corto_declare(parent, id, corto_int_o)
CORTO_EXPORT corto_int16 _corto_int__update(corto_int _this, corto_width width, int64_t min, int64_t max);
#define corto_int__update(_this, width, min, max) _corto_int__update(corto_int(_this), width, min, max)
CORTO_EXPORT corto_int _corto_int__assign(corto_int _this, corto_width width, int64_t min, int64_t max);
#define corto_int__optional_not_set NULL
#define corto_int__optional_set(width, min, max) (corto_int*)corto_int__assign((corto_int*)corto_ptr_new(corto_int_o), width, min, max)
#define corto_int__optional_set_cond(__cond, width, min, max) __cond ? (corto_int*)corto_int__assign((corto_int*)corto_ptr_new(corto_int_o), width, min, max) : NULL
#define corto_int__unset(_this) _this ? corto_ptr_free(_this, corto_int_o), 0 : 0; _this = NULL;
#define corto_int__assign(_this, width, min, max) _corto_int__assign(_this, width, min, max)
#define corto_int__set(_this, width, min, max) _this = _this ? _this : (corto_int*)corto_ptr_new(corto_int_o); _corto_int__assign(_this, width, min, max)

/* int16 */
CORTO_EXPORT int16_t* _corto_int16__create(corto_object _parent, const char *_id, int16_t value);
#define corto_int16__create(_parent, _id, value) _corto_int16__create(_parent, _id, value)
#define corto_int16__create_auto(_parent, _id, value) int16_t* _id = corto_int16__create(_parent, #_id, value); (void)_id
#define corto_int16__declare(parent, id) (int16_t*)corto_declare(parent, id, corto_int16_o)
CORTO_EXPORT corto_int16 _corto_int16__update(int16_t* _this, int16_t value);
#define corto_int16__update(_this, value) _corto_int16__update(corto_int16(_this), value)
CORTO_EXPORT int16_t* _corto_int16__assign(int16_t* _this, int16_t value);
#define corto_int16__optional_not_set NULL
#define corto_int16__optional_set(value) (corto_int16*)corto_int16__assign((corto_int16*)corto_ptr_new(corto_int16_o), value)
#define corto_int16__optional_set_cond(__cond, value) __cond ? (corto_int16*)corto_int16__assign((corto_int16*)corto_ptr_new(corto_int16_o), value) : NULL
#define corto_int16__unset(_this) _this ? corto_ptr_free(_this, corto_int16_o), 0 : 0; _this = NULL;
#define corto_int16__assign(_this, value) _corto_int16__assign(_this, value)
#define corto_int16__set(_this, value) _this = _this ? _this : (corto_int16*)corto_ptr_new(corto_int16_o); _corto_int16__assign(_this, value)

/* int32 */
CORTO_EXPORT int32_t* _corto_int32__create(corto_object _parent, const char *_id, int32_t value);
#define corto_int32__create(_parent, _id, value) _corto_int32__create(_parent, _id, value)
#define corto_int32__create_auto(_parent, _id, value) int32_t* _id = corto_int32__create(_parent, #_id, value); (void)_id
#define corto_int32__declare(parent, id) (int32_t*)corto_declare(parent, id, corto_int32_o)
CORTO_EXPORT corto_int16 _corto_int32__update(int32_t* _this, int32_t value);
#define corto_int32__update(_this, value) _corto_int32__update(corto_int32(_this), value)
CORTO_EXPORT int32_t* _corto_int32__assign(int32_t* _this, int32_t value);
#define corto_int32__optional_not_set NULL
#define corto_int32__optional_set(value) (corto_int32*)corto_int32__assign((corto_int32*)corto_ptr_new(corto_int32_o), value)
#define corto_int32__optional_set_cond(__cond, value) __cond ? (corto_int32*)corto_int32__assign((corto_int32*)corto_ptr_new(corto_int32_o), value) : NULL
#define corto_int32__unset(_this) _this ? corto_ptr_free(_this, corto_int32_o), 0 : 0; _this = NULL;
#define corto_int32__assign(_this, value) _corto_int32__assign(_this, value)
#define corto_int32__set(_this, value) _this = _this ? _this : (corto_int32*)corto_ptr_new(corto_int32_o); _corto_int32__assign(_this, value)

/* int32seq */
CORTO_EXPORT corto_int32seq* _corto_int32seq__create(corto_object _parent, const char *_id, corto_uint32 length, int32_t* elements);
#define corto_int32seq__create(_parent, _id, length, elements) _corto_int32seq__create(_parent, _id, length, elements)
#define corto_int32seq__create_auto(_parent, _id, length, elements) corto_int32seq* _id = corto_int32seq__create(_parent, #_id, length, elements); (void)_id
#define corto_int32seq__declare(parent, id) (corto_int32seq*)corto_declare(parent, id, corto_int32seq_o)
CORTO_EXPORT corto_int16 _corto_int32seq__update(corto_int32seq* _this, corto_uint32 length, int32_t* elements);
#define corto_int32seq__update(_this, length, elements) _corto_int32seq__update(corto_int32seq(_this), length, elements)
CORTO_EXPORT corto_int32seq* _corto_int32seq__assign(corto_int32seq* _this, corto_uint32 length, int32_t* elements);
#define corto_int32seq__optional_not_set NULL
#define corto_int32seq__optional_set(length, elements) (corto_int32seq*)corto_int32seq__assign((corto_int32seq*)corto_ptr_new(corto_int32seq_o), length, elements)
#define corto_int32seq__optional_set_cond(__cond, length, elements) __cond ? (corto_int32seq*)corto_int32seq__assign((corto_int32seq*)corto_ptr_new(corto_int32seq_o), length, elements) : NULL
#define corto_int32seq__unset(_this) _this ? corto_ptr_free(_this, corto_int32seq_o), 0 : 0; _this = NULL;
#define corto_int32seq__assign(_this, length, elements) _corto_int32seq__assign(_this, length, elements)
#define corto_int32seq__set(_this, length, elements) _this = _this ? _this : (corto_int32seq*)corto_ptr_new(corto_int32seq_o); _corto_int32seq__assign(_this, length, elements)

/* int64 */
CORTO_EXPORT int64_t* _corto_int64__create(corto_object _parent, const char *_id, int64_t value);
#define corto_int64__create(_parent, _id, value) _corto_int64__create(_parent, _id, value)
#define corto_int64__create_auto(_parent, _id, value) int64_t* _id = corto_int64__create(_parent, #_id, value); (void)_id
#define corto_int64__declare(parent, id) (int64_t*)corto_declare(parent, id, corto_int64_o)
CORTO_EXPORT corto_int16 _corto_int64__update(int64_t* _this, int64_t value);
#define corto_int64__update(_this, value) _corto_int64__update(corto_int64(_this), value)
CORTO_EXPORT int64_t* _corto_int64__assign(int64_t* _this, int64_t value);
#define corto_int64__optional_not_set NULL
#define corto_int64__optional_set(value) (corto_int64*)corto_int64__assign((corto_int64*)corto_ptr_new(corto_int64_o), value)
#define corto_int64__optional_set_cond(__cond, value) __cond ? (corto_int64*)corto_int64__assign((corto_int64*)corto_ptr_new(corto_int64_o), value) : NULL
#define corto_int64__unset(_this) _this ? corto_ptr_free(_this, corto_int64_o), 0 : 0; _this = NULL;
#define corto_int64__assign(_this, value) _corto_int64__assign(_this, value)
#define corto_int64__set(_this, value) _this = _this ? _this : (corto_int64*)corto_ptr_new(corto_int64_o); _corto_int64__assign(_this, value)

/* int8 */
CORTO_EXPORT int8_t* _corto_int8__create(corto_object _parent, const char *_id, int8_t value);
#define corto_int8__create(_parent, _id, value) _corto_int8__create(_parent, _id, value)
#define corto_int8__create_auto(_parent, _id, value) int8_t* _id = corto_int8__create(_parent, #_id, value); (void)_id
#define corto_int8__declare(parent, id) (int8_t*)corto_declare(parent, id, corto_int8_o)
CORTO_EXPORT corto_int16 _corto_int8__update(int8_t* _this, int8_t value);
#define corto_int8__update(_this, value) _corto_int8__update(corto_int8(_this), value)
CORTO_EXPORT int8_t* _corto_int8__assign(int8_t* _this, int8_t value);
#define corto_int8__optional_not_set NULL
#define corto_int8__optional_set(value) (corto_int8*)corto_int8__assign((corto_int8*)corto_ptr_new(corto_int8_o), value)
#define corto_int8__optional_set_cond(__cond, value) __cond ? (corto_int8*)corto_int8__assign((corto_int8*)corto_ptr_new(corto_int8_o), value) : NULL
#define corto_int8__unset(_this) _this ? corto_ptr_free(_this, corto_int8_o), 0 : 0; _this = NULL;
#define corto_int8__assign(_this, value) _corto_int8__assign(_this, value)
#define corto_int8__set(_this, value) _this = _this ? _this : (corto_int8*)corto_ptr_new(corto_int8_o); _corto_int8__assign(_this, value)

/* interface */
CORTO_EXPORT corto_interface _corto_interface__create(corto_object _parent, const char *_id, corto_interface base);
#define corto_interface__create(_parent, _id, base) _corto_interface__create(_parent, _id, corto_interface(base))
#define corto_interface__create_auto(_parent, _id, base) corto_interface _id = corto_interface__create(_parent, #_id, base); (void)_id
#define corto_interface__declare(parent, id) (corto_interface)corto_declare(parent, id, corto_interface_o)
CORTO_EXPORT corto_int16 _corto_interface__update(corto_interface _this, corto_interface base);
#define corto_interface__update(_this, base) _corto_interface__update(corto_interface(_this), corto_interface(base))
CORTO_EXPORT corto_interface _corto_interface__assign(corto_interface _this, corto_interface base);
#define corto_interface__optional_not_set NULL
#define corto_interface__optional_set(base) (corto_interface*)corto_interface__assign((corto_interface*)corto_ptr_new(corto_interface_o), base)
#define corto_interface__optional_set_cond(__cond, base) __cond ? (corto_interface*)corto_interface__assign((corto_interface*)corto_ptr_new(corto_interface_o), base) : NULL
#define corto_interface__unset(_this) _this ? corto_ptr_free(_this, corto_interface_o), 0 : 0; _this = NULL;
#define corto_interface__assign(_this, base) _corto_interface__assign(_this, corto_interface(base))
#define corto_interface__set(_this, base) _this = _this ? _this : (corto_interface*)corto_ptr_new(corto_interface_o); _corto_interface__assign(_this, corto_interface(base))

/* interfaceseq */
CORTO_EXPORT corto_interfaceseq* _corto_interfaceseq__create(corto_object _parent, const char *_id, corto_uint32 length, corto_interface* elements);
#define corto_interfaceseq__create(_parent, _id, length, elements) _corto_interfaceseq__create(_parent, _id, length, elements)
#define corto_interfaceseq__create_auto(_parent, _id, length, elements) corto_interfaceseq* _id = corto_interfaceseq__create(_parent, #_id, length, elements); (void)_id
#define corto_interfaceseq__declare(parent, id) (corto_interfaceseq*)corto_declare(parent, id, corto_interfaceseq_o)
CORTO_EXPORT corto_int16 _corto_interfaceseq__update(corto_interfaceseq* _this, corto_uint32 length, corto_interface* elements);
#define corto_interfaceseq__update(_this, length, elements) _corto_interfaceseq__update(corto_interfaceseq(_this), length, elements)
CORTO_EXPORT corto_interfaceseq* _corto_interfaceseq__assign(corto_interfaceseq* _this, corto_uint32 length, corto_interface* elements);
#define corto_interfaceseq__optional_not_set NULL
#define corto_interfaceseq__optional_set(length, elements) (corto_interfaceseq*)corto_interfaceseq__assign((corto_interfaceseq*)corto_ptr_new(corto_interfaceseq_o), length, elements)
#define corto_interfaceseq__optional_set_cond(__cond, length, elements) __cond ? (corto_interfaceseq*)corto_interfaceseq__assign((corto_interfaceseq*)corto_ptr_new(corto_interfaceseq_o), length, elements) : NULL
#define corto_interfaceseq__unset(_this) _this ? corto_ptr_free(_this, corto_interfaceseq_o), 0 : 0; _this = NULL;
#define corto_interfaceseq__assign(_this, length, elements) _corto_interfaceseq__assign(_this, length, elements)
#define corto_interfaceseq__set(_this, length, elements) _this = _this ? _this : (corto_interfaceseq*)corto_ptr_new(corto_interfaceseq_o); _corto_interfaceseq__assign(_this, length, elements)

/* interfaceVector */
CORTO_EXPORT corto_interfaceVector* _corto_interfaceVector__create(corto_object _parent, const char *_id, corto_interface interface, corto_objectseq vector);
#define corto_interfaceVector__create(_parent, _id, interface, vector) _corto_interfaceVector__create(_parent, _id, corto_interface(interface), vector)
#define corto_interfaceVector__create_auto(_parent, _id, interface, vector) corto_interfaceVector* _id = corto_interfaceVector__create(_parent, #_id, interface, vector); (void)_id
#define corto_interfaceVector__declare(parent, id) (corto_interfaceVector*)corto_declare(parent, id, corto_interfaceVector_o)
CORTO_EXPORT corto_int16 _corto_interfaceVector__update(corto_interfaceVector* _this, corto_interface interface, corto_objectseq vector);
#define corto_interfaceVector__update(_this, interface, vector) _corto_interfaceVector__update(corto_interfaceVector(_this), corto_interface(interface), vector)
CORTO_EXPORT corto_interfaceVector* _corto_interfaceVector__assign(corto_interfaceVector* _this, corto_interface interface, corto_objectseq vector);
#define corto_interfaceVector__optional_not_set NULL
#define corto_interfaceVector__optional_set(interface, vector) (corto_interfaceVector*)corto_interfaceVector__assign((corto_interfaceVector*)corto_ptr_new(corto_interfaceVector_o), interface, vector)
#define corto_interfaceVector__optional_set_cond(__cond, interface, vector) __cond ? (corto_interfaceVector*)corto_interfaceVector__assign((corto_interfaceVector*)corto_ptr_new(corto_interfaceVector_o), interface, vector) : NULL
#define corto_interfaceVector__unset(_this) _this ? corto_ptr_free(_this, corto_interfaceVector_o), 0 : 0; _this = NULL;
#define corto_interfaceVector__assign(_this, interface, vector) _corto_interfaceVector__assign(_this, corto_interface(interface), vector)
#define corto_interfaceVector__set(_this, interface, vector) _this = _this ? _this : (corto_interfaceVector*)corto_ptr_new(corto_interfaceVector_o); _corto_interfaceVector__assign(_this, corto_interface(interface), vector)

/* interfaceVectorseq */
CORTO_EXPORT corto_interfaceVectorseq* _corto_interfaceVectorseq__create(corto_object _parent, const char *_id, corto_uint32 length, corto_interfaceVector* elements);
#define corto_interfaceVectorseq__create(_parent, _id, length, elements) _corto_interfaceVectorseq__create(_parent, _id, length, elements)
#define corto_interfaceVectorseq__create_auto(_parent, _id, length, elements) corto_interfaceVectorseq* _id = corto_interfaceVectorseq__create(_parent, #_id, length, elements); (void)_id
#define corto_interfaceVectorseq__declare(parent, id) (corto_interfaceVectorseq*)corto_declare(parent, id, corto_interfaceVectorseq_o)
CORTO_EXPORT corto_int16 _corto_interfaceVectorseq__update(corto_interfaceVectorseq* _this, corto_uint32 length, corto_interfaceVector* elements);
#define corto_interfaceVectorseq__update(_this, length, elements) _corto_interfaceVectorseq__update(corto_interfaceVectorseq(_this), length, elements)
CORTO_EXPORT corto_interfaceVectorseq* _corto_interfaceVectorseq__assign(corto_interfaceVectorseq* _this, corto_uint32 length, corto_interfaceVector* elements);
#define corto_interfaceVectorseq__optional_not_set NULL
#define corto_interfaceVectorseq__optional_set(length, elements) (corto_interfaceVectorseq*)corto_interfaceVectorseq__assign((corto_interfaceVectorseq*)corto_ptr_new(corto_interfaceVectorseq_o), length, elements)
#define corto_interfaceVectorseq__optional_set_cond(__cond, length, elements) __cond ? (corto_interfaceVectorseq*)corto_interfaceVectorseq__assign((corto_interfaceVectorseq*)corto_ptr_new(corto_interfaceVectorseq_o), length, elements) : NULL
#define corto_interfaceVectorseq__unset(_this) _this ? corto_ptr_free(_this, corto_interfaceVectorseq_o), 0 : 0; _this = NULL;
#define corto_interfaceVectorseq__assign(_this, length, elements) _corto_interfaceVectorseq__assign(_this, length, elements)
#define corto_interfaceVectorseq__set(_this, length, elements) _this = _this ? _this : (corto_interfaceVectorseq*)corto_ptr_new(corto_interfaceVectorseq_o); _corto_interfaceVectorseq__assign(_this, length, elements)

/* iterator */
CORTO_EXPORT corto_iterator _corto_iterator__create(corto_object _parent, const char *_id, corto_type element_type);
#define corto_iterator__create(_parent, _id, element_type) _corto_iterator__create(_parent, _id, corto_type(element_type))
#define corto_iterator__create_auto(_parent, _id, element_type) corto_iterator _id = corto_iterator__create(_parent, #_id, element_type); (void)_id
#define corto_iterator__declare(parent, id) (corto_iterator)corto_declare(parent, id, corto_iterator_o)
CORTO_EXPORT corto_int16 _corto_iterator__update(corto_iterator _this, corto_type element_type);
#define corto_iterator__update(_this, element_type) _corto_iterator__update(corto_iterator(_this), corto_type(element_type))
CORTO_EXPORT corto_iterator _corto_iterator__assign(corto_iterator _this, corto_type element_type);
#define corto_iterator__optional_not_set NULL
#define corto_iterator__optional_set(element_type) (corto_iterator*)corto_iterator__assign((corto_iterator*)corto_ptr_new(corto_iterator_o), element_type)
#define corto_iterator__optional_set_cond(__cond, element_type) __cond ? (corto_iterator*)corto_iterator__assign((corto_iterator*)corto_ptr_new(corto_iterator_o), element_type) : NULL
#define corto_iterator__unset(_this) _this ? corto_ptr_free(_this, corto_iterator_o), 0 : 0; _this = NULL;
#define corto_iterator__assign(_this, element_type) _corto_iterator__assign(_this, corto_type(element_type))
#define corto_iterator__set(_this, element_type) _this = _this ? _this : (corto_iterator*)corto_ptr_new(corto_iterator_o); _corto_iterator__assign(_this, corto_type(element_type))

/* leaf */
CORTO_EXPORT corto_leaf _corto_leaf__create(corto_object _parent, const char *_id, corto_interface base, corto_modifierMask base_modifiers, corto_interfaceseq implements, corto_type type, const char * value);
#define corto_leaf__create(_parent, _id, base, base_modifiers, implements, type, value) _corto_leaf__create(_parent, _id, corto_interface(base), base_modifiers, implements, corto_type(type), value)
#define corto_leaf__create_auto(_parent, _id, base, base_modifiers, implements, type, value) corto_leaf _id = corto_leaf__create(_parent, #_id, base, base_modifiers, implements, type, value); (void)_id
#define corto_leaf__declare(parent, id) (corto_leaf)corto_declare(parent, id, corto_leaf_o)
CORTO_EXPORT corto_int16 _corto_leaf__update(corto_leaf _this, corto_interface base, corto_modifierMask base_modifiers, corto_interfaceseq implements, corto_type type, const char * value);
#define corto_leaf__update(_this, base, base_modifiers, implements, type, value) _corto_leaf__update(corto_leaf(_this), corto_interface(base), base_modifiers, implements, corto_type(type), value)
CORTO_EXPORT corto_leaf _corto_leaf__assign(corto_leaf _this, corto_interface base, corto_modifierMask base_modifiers, corto_interfaceseq implements, corto_type type, const char * value);
#define corto_leaf__optional_not_set NULL
#define corto_leaf__optional_set(base, base_modifiers, implements, type, value) (corto_leaf*)corto_leaf__assign((corto_leaf*)corto_ptr_new(corto_leaf_o), base, base_modifiers, implements, type, value)
#define corto_leaf__optional_set_cond(__cond, base, base_modifiers, implements, type, value) __cond ? (corto_leaf*)corto_leaf__assign((corto_leaf*)corto_ptr_new(corto_leaf_o), base, base_modifiers, implements, type, value) : NULL
#define corto_leaf__unset(_this) _this ? corto_ptr_free(_this, corto_leaf_o), 0 : 0; _this = NULL;
#define corto_leaf__assign(_this, base, base_modifiers, implements, type, value) _corto_leaf__assign(_this, corto_interface(base), base_modifiers, implements, corto_type(type), value)
#define corto_leaf__set(_this, base, base_modifiers, implements, type, value) _this = _this ? _this : (corto_leaf*)corto_ptr_new(corto_leaf_o); _corto_leaf__assign(_this, corto_interface(base), base_modifiers, implements, corto_type(type), value)

/* list */
CORTO_EXPORT corto_list _corto_list__create(corto_object _parent, const char *_id, corto_type element_type, uint32_t max);
#define corto_list__create(_parent, _id, element_type, max) _corto_list__create(_parent, _id, corto_type(element_type), max)
#define corto_list__create_auto(_parent, _id, element_type, max) corto_list _id = corto_list__create(_parent, #_id, element_type, max); (void)_id
#define corto_list__declare(parent, id) (corto_list)corto_declare(parent, id, corto_list_o)
CORTO_EXPORT corto_int16 _corto_list__update(corto_list _this, corto_type element_type, uint32_t max);
#define corto_list__update(_this, element_type, max) _corto_list__update(corto_list(_this), corto_type(element_type), max)
CORTO_EXPORT corto_list _corto_list__assign(corto_list _this, corto_type element_type, uint32_t max);
#define corto_list__optional_not_set NULL
#define corto_list__optional_set(element_type, max) (corto_list*)corto_list__assign((corto_list*)corto_ptr_new(corto_list_o), element_type, max)
#define corto_list__optional_set_cond(__cond, element_type, max) __cond ? (corto_list*)corto_list__assign((corto_list*)corto_ptr_new(corto_list_o), element_type, max) : NULL
#define corto_list__unset(_this) _this ? corto_ptr_free(_this, corto_list_o), 0 : 0; _this = NULL;
#define corto_list__assign(_this, element_type, max) _corto_list__assign(_this, corto_type(element_type), max)
#define corto_list__set(_this, element_type, max) _this = _this ? _this : (corto_list*)corto_ptr_new(corto_list_o); _corto_list__assign(_this, corto_type(element_type), max)

/* map */
CORTO_EXPORT corto_map _corto_map__create(corto_object _parent, const char *_id, corto_type key_type, corto_type element_type, uint32_t max);
#define corto_map__create(_parent, _id, key_type, element_type, max) _corto_map__create(_parent, _id, corto_type(key_type), corto_type(element_type), max)
#define corto_map__create_auto(_parent, _id, key_type, element_type, max) corto_map _id = corto_map__create(_parent, #_id, key_type, element_type, max); (void)_id
#define corto_map__declare(parent, id) (corto_map)corto_declare(parent, id, corto_map_o)
CORTO_EXPORT corto_int16 _corto_map__update(corto_map _this, corto_type key_type, corto_type element_type, uint32_t max);
#define corto_map__update(_this, key_type, element_type, max) _corto_map__update(corto_map(_this), corto_type(key_type), corto_type(element_type), max)
CORTO_EXPORT corto_map _corto_map__assign(corto_map _this, corto_type key_type, corto_type element_type, uint32_t max);
#define corto_map__optional_not_set NULL
#define corto_map__optional_set(key_type, element_type, max) (corto_map*)corto_map__assign((corto_map*)corto_ptr_new(corto_map_o), key_type, element_type, max)
#define corto_map__optional_set_cond(__cond, key_type, element_type, max) __cond ? (corto_map*)corto_map__assign((corto_map*)corto_ptr_new(corto_map_o), key_type, element_type, max) : NULL
#define corto_map__unset(_this) _this ? corto_ptr_free(_this, corto_map_o), 0 : 0; _this = NULL;
#define corto_map__assign(_this, key_type, element_type, max) _corto_map__assign(_this, corto_type(key_type), corto_type(element_type), max)
#define corto_map__set(_this, key_type, element_type, max) _this = _this ? _this : (corto_map*)corto_ptr_new(corto_map_o); _corto_map__assign(_this, corto_type(key_type), corto_type(element_type), max)

/* member */
CORTO_EXPORT corto_member _corto_member__create(corto_object _parent, const char *_id, corto_type type, corto_modifierMask modifiers);
#define corto_member__create(_parent, _id, type, modifiers) _corto_member__create(_parent, _id, corto_type(type), modifiers)
#define corto_member__create_auto(_parent, _id, type, modifiers) corto_member _id = corto_member__create(_parent, #_id, type, modifiers); (void)_id
#define corto_member__declare(parent, id) (corto_member)corto_declare(parent, id, corto_member_o)
CORTO_EXPORT corto_int16 _corto_member__update(corto_member _this, corto_type type, corto_modifierMask modifiers);
#define corto_member__update(_this, type, modifiers) _corto_member__update(corto_member(_this), corto_type(type), modifiers)
CORTO_EXPORT corto_member _corto_member__assign(corto_member _this, corto_type type, corto_modifierMask modifiers);
#define corto_member__optional_not_set NULL
#define corto_member__optional_set(type, modifiers) (corto_member*)corto_member__assign((corto_member*)corto_ptr_new(corto_member_o), type, modifiers)
#define corto_member__optional_set_cond(__cond, type, modifiers) __cond ? (corto_member*)corto_member__assign((corto_member*)corto_ptr_new(corto_member_o), type, modifiers) : NULL
#define corto_member__unset(_this) _this ? corto_ptr_free(_this, corto_member_o), 0 : 0; _this = NULL;
#define corto_member__assign(_this, type, modifiers) _corto_member__assign(_this, corto_type(type), modifiers)
#define corto_member__set(_this, type, modifiers) _this = _this ? _this : (corto_member*)corto_ptr_new(corto_member_o); _corto_member__assign(_this, corto_type(type), modifiers)

/* metaprocedure */
CORTO_EXPORT corto_metaprocedure _corto_metaprocedure__create(corto_object _parent, const char *_id, corto_type return_type, bool is_reference, bool referenceOnly, void(*_impl)(void));
#define corto_metaprocedure__create(_parent, _id, return_type, is_reference, referenceOnly, _impl) _corto_metaprocedure__create(_parent, _id, corto_type(return_type), is_reference, referenceOnly, (void(*)(void))_impl)
#define corto_metaprocedure__create_auto(_parent, _id, return_type, is_reference, referenceOnly, _impl) corto_metaprocedure _id = corto_metaprocedure__create(_parent, #_id, return_type, is_reference, referenceOnly, _impl); (void)_id
#define corto_metaprocedure__declare(parent, id) (corto_metaprocedure)corto_declare(parent, id, corto_metaprocedure_o)
CORTO_EXPORT corto_int16 _corto_metaprocedure__update(corto_metaprocedure _this, corto_type return_type, bool is_reference, bool referenceOnly, void(*_impl)(void));
#define corto_metaprocedure__update(_this, return_type, is_reference, referenceOnly, _impl) _corto_metaprocedure__update(corto_metaprocedure(_this), corto_type(return_type), is_reference, referenceOnly, (void(*)(void))_impl)
CORTO_EXPORT corto_metaprocedure _corto_metaprocedure__assign(corto_metaprocedure _this, corto_type return_type, bool is_reference, bool referenceOnly, void(*_impl)(void));
#define corto_metaprocedure__optional_not_set NULL
#define corto_metaprocedure__optional_set(return_type, is_reference, referenceOnly, _impl) (corto_metaprocedure*)corto_metaprocedure__assign((corto_metaprocedure*)corto_ptr_new(corto_metaprocedure_o), return_type, is_reference, referenceOnly, _impl)
#define corto_metaprocedure__optional_set_cond(__cond, return_type, is_reference, referenceOnly, _impl) __cond ? (corto_metaprocedure*)corto_metaprocedure__assign((corto_metaprocedure*)corto_ptr_new(corto_metaprocedure_o), return_type, is_reference, referenceOnly, _impl) : NULL
#define corto_metaprocedure__unset(_this) _this ? corto_ptr_free(_this, corto_metaprocedure_o), 0 : 0; _this = NULL;
#define corto_metaprocedure__assign(_this, return_type, is_reference, referenceOnly, _impl) _corto_metaprocedure__assign(_this, corto_type(return_type), is_reference, referenceOnly, (void(*)(void))_impl)
#define corto_metaprocedure__set(_this, return_type, is_reference, referenceOnly, _impl) _this = _this ? _this : (corto_metaprocedure*)corto_ptr_new(corto_metaprocedure_o); _corto_metaprocedure__assign(_this, corto_type(return_type), is_reference, referenceOnly, (void(*)(void))_impl)

/* method */
CORTO_EXPORT corto_method _corto_method__create(corto_object _parent, const char *_id, corto_type return_type, bool is_reference, void(*_impl)(void));
#define corto_method__create(_parent, _id, return_type, is_reference, _impl) _corto_method__create(_parent, _id, corto_type(return_type), is_reference, (void(*)(void))_impl)
#define corto_method__create_auto(_parent, _id, return_type, is_reference, _impl) corto_method _id = corto_method__create(_parent, #_id, return_type, is_reference, _impl); (void)_id
#define corto_method__declare(parent, id) (corto_method)corto_declare(parent, id, corto_method_o)
CORTO_EXPORT corto_int16 _corto_method__update(corto_method _this, corto_type return_type, bool is_reference, void(*_impl)(void));
#define corto_method__update(_this, return_type, is_reference, _impl) _corto_method__update(corto_method(_this), corto_type(return_type), is_reference, (void(*)(void))_impl)
CORTO_EXPORT corto_method _corto_method__assign(corto_method _this, corto_type return_type, bool is_reference, void(*_impl)(void));
#define corto_method__optional_not_set NULL
#define corto_method__optional_set(return_type, is_reference, _impl) (corto_method*)corto_method__assign((corto_method*)corto_ptr_new(corto_method_o), return_type, is_reference, _impl)
#define corto_method__optional_set_cond(__cond, return_type, is_reference, _impl) __cond ? (corto_method*)corto_method__assign((corto_method*)corto_ptr_new(corto_method_o), return_type, is_reference, _impl) : NULL
#define corto_method__unset(_this) _this ? corto_ptr_free(_this, corto_method_o), 0 : 0; _this = NULL;
#define corto_method__assign(_this, return_type, is_reference, _impl) _corto_method__assign(_this, corto_type(return_type), is_reference, (void(*)(void))_impl)
#define corto_method__set(_this, return_type, is_reference, _impl) _this = _this ? _this : (corto_method*)corto_ptr_new(corto_method_o); _corto_method__assign(_this, corto_type(return_type), is_reference, (void(*)(void))_impl)

/* modifierMask */
CORTO_EXPORT corto_modifierMask* _corto_modifierMask__create(corto_object _parent, const char *_id, corto_modifierMask value);
#define corto_modifierMask__create(_parent, _id, value) _corto_modifierMask__create(_parent, _id, value)
#define corto_modifierMask__create_auto(_parent, _id, value) corto_modifierMask* _id = corto_modifierMask__create(_parent, #_id, value); (void)_id
#define corto_modifierMask__declare(parent, id) (corto_modifierMask*)corto_declare(parent, id, corto_modifierMask_o)
CORTO_EXPORT corto_int16 _corto_modifierMask__update(corto_modifierMask* _this, corto_modifierMask value);
#define corto_modifierMask__update(_this, value) _corto_modifierMask__update(corto_modifierMask(_this), value)
CORTO_EXPORT corto_modifierMask* _corto_modifierMask__assign(corto_modifierMask* _this, corto_modifierMask value);
#define corto_modifierMask__optional_not_set NULL
#define corto_modifierMask__optional_set(value) (corto_modifierMask*)corto_modifierMask__assign((corto_modifierMask*)corto_ptr_new(corto_modifierMask_o), value)
#define corto_modifierMask__optional_set_cond(__cond, value) __cond ? (corto_modifierMask*)corto_modifierMask__assign((corto_modifierMask*)corto_ptr_new(corto_modifierMask_o), value) : NULL
#define corto_modifierMask__unset(_this) _this ? corto_ptr_free(_this, corto_modifierMask_o), 0 : 0; _this = NULL;
#define corto_modifierMask__assign(_this, value) _corto_modifierMask__assign(_this, value)
#define corto_modifierMask__set(_this, value) _this = _this ? _this : (corto_modifierMask*)corto_ptr_new(corto_modifierMask_o); _corto_modifierMask__assign(_this, value)

/* name_action */
CORTO_EXPORT corto_name_action* _corto_name_action__create(corto_object _parent, const char *_id, corto_object instance, corto_function procedure);
#define corto_name_action__create(_parent, _id, instance, procedure) _corto_name_action__create(_parent, _id, instance, corto_function(procedure))
#define corto_name_action__create_auto(_parent, _id, instance, procedure) corto_name_action* _id = corto_name_action__create(_parent, #_id, instance, procedure); (void)_id
#define corto_name_action__declare(parent, id) (corto_name_action*)corto_declare(parent, id, corto_name_action_o)
CORTO_EXPORT corto_int16 _corto_name_action__update(corto_name_action* _this, corto_object instance, corto_function procedure);
#define corto_name_action__update(_this, instance, procedure) _corto_name_action__update(corto_name_action(_this), instance, corto_function(procedure))
CORTO_EXPORT corto_name_action* _corto_name_action__assign(corto_name_action* _this, corto_object instance, corto_function procedure);
#define corto_name_action__optional_not_set NULL
#define corto_name_action__optional_set(instance, procedure) (corto_name_action*)corto_name_action__assign((corto_name_action*)corto_ptr_new(corto_name_action_o), instance, procedure)
#define corto_name_action__optional_set_cond(__cond, instance, procedure) __cond ? (corto_name_action*)corto_name_action__assign((corto_name_action*)corto_ptr_new(corto_name_action_o), instance, procedure) : NULL
#define corto_name_action__unset(_this) _this ? corto_ptr_free(_this, corto_name_action_o), 0 : 0; _this = NULL;
#define corto_name_action__assign(_this, instance, procedure) _corto_name_action__assign(_this, instance, corto_function(procedure))
#define corto_name_action__set(_this, instance, procedure) _this = _this ? _this : (corto_name_action*)corto_ptr_new(corto_name_action_o); _corto_name_action__assign(_this, instance, corto_function(procedure))
corto_int16 corto_name_action__call(corto_name_action *_delegate, corto_string* _result);
#define corto_name_action__init_c_auto(d, callback) corto_name_action d; corto_name_action__init_c(&d, callback)
CORTO_EXPORT corto_int16 corto_name_action__init_c(corto_name_action *d, corto_string ___ (*callback)(void));
#define corto_name_action_init_c_instance_auto(d, instance, callback)corto_name_action d; corto_name_action_init_c_instance(&d, instance, callback)
CORTO_EXPORT corto_int16 corto_name_action_init_c_instance(corto_name_action *d, corto_object instance, corto_string ___ (*callback)(corto_object));

/* object */
CORTO_EXPORT corto_object _corto_object__create(corto_object _parent, const char *_id, corto_object value);
#define corto_object__create(_parent, _id, value) _corto_object__create(_parent, _id, value)
#define corto_object__create_auto(_parent, _id, value) corto_object _id = corto_object__create(_parent, #_id, value); (void)_id
#define corto_object__declare(parent, id) (corto_object)corto_declare(parent, id, corto_object_o)
CORTO_EXPORT corto_int16 _corto_object__update(corto_object _this, corto_object value);
#define corto_object__update(_this, value) _corto_object__update(corto_object(_this), value)
CORTO_EXPORT corto_object _corto_object__assign(corto_object _this, corto_object value);
#define corto_object__optional_not_set NULL
#define corto_object__optional_set(value) (corto_object*)corto_object__assign((corto_object*)corto_ptr_new(corto_object_o), value)
#define corto_object__optional_set_cond(__cond, value) __cond ? (corto_object*)corto_object__assign((corto_object*)corto_ptr_new(corto_object_o), value) : NULL
#define corto_object__unset(_this) _this ? corto_ptr_free(_this, corto_object_o), 0 : 0; _this = NULL;
#define corto_object__assign(_this, value) _corto_object__assign(_this, value)
#define corto_object__set(_this, value) _this = _this ? _this : (corto_object*)corto_ptr_new(corto_object_o); _corto_object__assign(_this, value)

/* objectlist */
CORTO_EXPORT corto_objectlist* _corto_objectlist__create(corto_object _parent, const char *_id, corto_uint32 length, corto_object* elements);
#define corto_objectlist__create(_parent, _id, length, elements) _corto_objectlist__create(_parent, _id, length, elements)
#define corto_objectlist__create_auto(_parent, _id, length, elements) corto_objectlist* _id = corto_objectlist__create(_parent, #_id, length, elements); (void)_id
#define corto_objectlist__declare(parent, id) (corto_objectlist*)corto_declare(parent, id, corto_objectlist_o)
CORTO_EXPORT corto_int16 _corto_objectlist__update(corto_objectlist* _this, corto_uint32 length, corto_object* elements);
#define corto_objectlist__update(_this, length, elements) _corto_objectlist__update(corto_objectlist(_this), length, elements)
CORTO_EXPORT corto_objectlist* _corto_objectlist__assign(corto_objectlist* _this, corto_uint32 length, corto_object* elements);
#define corto_objectlist__optional_not_set NULL
#define corto_objectlist__optional_set(length, elements) (corto_objectlist*)corto_objectlist__assign((corto_objectlist*)corto_ptr_new(corto_objectlist_o), length, elements)
#define corto_objectlist__optional_set_cond(__cond, length, elements) __cond ? (corto_objectlist*)corto_objectlist__assign((corto_objectlist*)corto_ptr_new(corto_objectlist_o), length, elements) : NULL
#define corto_objectlist__unset(_this) _this ? corto_ptr_free(_this, corto_objectlist_o), 0 : 0; _this = NULL;
#define corto_objectlist__assign(_this, length, elements) _corto_objectlist__assign(_this, length, elements)
#define corto_objectlist__set(_this, length, elements) _this = _this ? _this : (corto_objectlist*)corto_ptr_new(corto_objectlist_o); _corto_objectlist__assign(_this, length, elements)

/* objectseq */
CORTO_EXPORT corto_objectseq* _corto_objectseq__create(corto_object _parent, const char *_id, corto_uint32 length, corto_object* elements);
#define corto_objectseq__create(_parent, _id, length, elements) _corto_objectseq__create(_parent, _id, length, elements)
#define corto_objectseq__create_auto(_parent, _id, length, elements) corto_objectseq* _id = corto_objectseq__create(_parent, #_id, length, elements); (void)_id
#define corto_objectseq__declare(parent, id) (corto_objectseq*)corto_declare(parent, id, corto_objectseq_o)
CORTO_EXPORT corto_int16 _corto_objectseq__update(corto_objectseq* _this, corto_uint32 length, corto_object* elements);
#define corto_objectseq__update(_this, length, elements) _corto_objectseq__update(corto_objectseq(_this), length, elements)
CORTO_EXPORT corto_objectseq* _corto_objectseq__assign(corto_objectseq* _this, corto_uint32 length, corto_object* elements);
#define corto_objectseq__optional_not_set NULL
#define corto_objectseq__optional_set(length, elements) (corto_objectseq*)corto_objectseq__assign((corto_objectseq*)corto_ptr_new(corto_objectseq_o), length, elements)
#define corto_objectseq__optional_set_cond(__cond, length, elements) __cond ? (corto_objectseq*)corto_objectseq__assign((corto_objectseq*)corto_ptr_new(corto_objectseq_o), length, elements) : NULL
#define corto_objectseq__unset(_this) _this ? corto_ptr_free(_this, corto_objectseq_o), 0 : 0; _this = NULL;
#define corto_objectseq__assign(_this, length, elements) _corto_objectseq__assign(_this, length, elements)
#define corto_objectseq__set(_this, length, elements) _this = _this ? _this : (corto_objectseq*)corto_ptr_new(corto_objectseq_o); _corto_objectseq__assign(_this, length, elements)

/* octet */
CORTO_EXPORT uint8_t* _corto_octet__create(corto_object _parent, const char *_id, uint8_t value);
#define corto_octet__create(_parent, _id, value) _corto_octet__create(_parent, _id, value)
#define corto_octet__create_auto(_parent, _id, value) uint8_t* _id = corto_octet__create(_parent, #_id, value); (void)_id
#define corto_octet__declare(parent, id) (uint8_t*)corto_declare(parent, id, corto_octet_o)
CORTO_EXPORT corto_int16 _corto_octet__update(uint8_t* _this, uint8_t value);
#define corto_octet__update(_this, value) _corto_octet__update(corto_octet(_this), value)
CORTO_EXPORT uint8_t* _corto_octet__assign(uint8_t* _this, uint8_t value);
#define corto_octet__optional_not_set NULL
#define corto_octet__optional_set(value) (corto_octet*)corto_octet__assign((corto_octet*)corto_ptr_new(corto_octet_o), value)
#define corto_octet__optional_set_cond(__cond, value) __cond ? (corto_octet*)corto_octet__assign((corto_octet*)corto_ptr_new(corto_octet_o), value) : NULL
#define corto_octet__unset(_this) _this ? corto_ptr_free(_this, corto_octet_o), 0 : 0; _this = NULL;
#define corto_octet__assign(_this, value) _corto_octet__assign(_this, value)
#define corto_octet__set(_this, value) _this = _this ? _this : (corto_octet*)corto_ptr_new(corto_octet_o); _corto_octet__assign(_this, value)

/* overridable */
CORTO_EXPORT corto_overridable _corto_overridable__create(corto_object _parent, const char *_id, corto_type return_type, bool is_reference, void(*_impl)(void));
#define corto_overridable__create(_parent, _id, return_type, is_reference, _impl) _corto_overridable__create(_parent, _id, corto_type(return_type), is_reference, (void(*)(void))_impl)
#define corto_overridable__create_auto(_parent, _id, return_type, is_reference, _impl) corto_overridable _id = corto_overridable__create(_parent, #_id, return_type, is_reference, _impl); (void)_id
#define corto_overridable__declare(parent, id) (corto_overridable)corto_declare(parent, id, corto_overridable_o)
CORTO_EXPORT corto_int16 _corto_overridable__update(corto_overridable _this, corto_type return_type, bool is_reference, void(*_impl)(void));
#define corto_overridable__update(_this, return_type, is_reference, _impl) _corto_overridable__update(corto_overridable(_this), corto_type(return_type), is_reference, (void(*)(void))_impl)
CORTO_EXPORT corto_overridable _corto_overridable__assign(corto_overridable _this, corto_type return_type, bool is_reference, void(*_impl)(void));
#define corto_overridable__optional_not_set NULL
#define corto_overridable__optional_set(return_type, is_reference, _impl) (corto_overridable*)corto_overridable__assign((corto_overridable*)corto_ptr_new(corto_overridable_o), return_type, is_reference, _impl)
#define corto_overridable__optional_set_cond(__cond, return_type, is_reference, _impl) __cond ? (corto_overridable*)corto_overridable__assign((corto_overridable*)corto_ptr_new(corto_overridable_o), return_type, is_reference, _impl) : NULL
#define corto_overridable__unset(_this) _this ? corto_ptr_free(_this, corto_overridable_o), 0 : 0; _this = NULL;
#define corto_overridable__assign(_this, return_type, is_reference, _impl) _corto_overridable__assign(_this, corto_type(return_type), is_reference, (void(*)(void))_impl)
#define corto_overridable__set(_this, return_type, is_reference, _impl) _this = _this ? _this : (corto_overridable*)corto_ptr_new(corto_overridable_o); _corto_overridable__assign(_this, corto_type(return_type), is_reference, (void(*)(void))_impl)

/* override */
CORTO_EXPORT corto_override _corto_override__create(corto_object _parent, const char *_id, corto_type return_type, bool is_reference, void(*_impl)(void));
#define corto_override__create(_parent, _id, return_type, is_reference, _impl) _corto_override__create(_parent, _id, corto_type(return_type), is_reference, (void(*)(void))_impl)
#define corto_override__create_auto(_parent, _id, return_type, is_reference, _impl) corto_override _id = corto_override__create(_parent, #_id, return_type, is_reference, _impl); (void)_id
#define corto_override__declare(parent, id) (corto_override)corto_declare(parent, id, corto_override_o)
CORTO_EXPORT corto_int16 _corto_override__update(corto_override _this, corto_type return_type, bool is_reference, void(*_impl)(void));
#define corto_override__update(_this, return_type, is_reference, _impl) _corto_override__update(corto_override(_this), corto_type(return_type), is_reference, (void(*)(void))_impl)
CORTO_EXPORT corto_override _corto_override__assign(corto_override _this, corto_type return_type, bool is_reference, void(*_impl)(void));
#define corto_override__optional_not_set NULL
#define corto_override__optional_set(return_type, is_reference, _impl) (corto_override*)corto_override__assign((corto_override*)corto_ptr_new(corto_override_o), return_type, is_reference, _impl)
#define corto_override__optional_set_cond(__cond, return_type, is_reference, _impl) __cond ? (corto_override*)corto_override__assign((corto_override*)corto_ptr_new(corto_override_o), return_type, is_reference, _impl) : NULL
#define corto_override__unset(_this) _this ? corto_ptr_free(_this, corto_override_o), 0 : 0; _this = NULL;
#define corto_override__assign(_this, return_type, is_reference, _impl) _corto_override__assign(_this, corto_type(return_type), is_reference, (void(*)(void))_impl)
#define corto_override__set(_this, return_type, is_reference, _impl) _this = _this ? _this : (corto_override*)corto_ptr_new(corto_override_o); _corto_override__assign(_this, corto_type(return_type), is_reference, (void(*)(void))_impl)

/* package */
CORTO_EXPORT corto_package _corto_package__create(corto_object _parent, const char *_id);
#define corto_package__create(_parent, _id) _corto_package__create(_parent, _id)
#define corto_package__create_auto(_parent, _id) corto_package _id = corto_package__create(_parent, #_id); (void)_id
#define corto_package__declare(parent, id) (corto_package)corto_declare(parent, id, corto_package_o)
CORTO_EXPORT corto_int16 _corto_package__update(corto_package _this);
#define corto_package__update(_this) _corto_package__update(corto_package(_this))
CORTO_EXPORT corto_package _corto_package__assign(corto_package _this);
#define corto_package__optional_not_set NULL
#define corto_package__optional_set() (corto_package*)corto_package__assign((corto_package*)corto_ptr_new(corto_package_o))
#define corto_package__optional_set_cond(__cond) __cond ? (corto_package*)corto_package__assign((corto_package*)corto_ptr_new(corto_package_o)) : NULL
#define corto_package__unset(_this) _this ? corto_ptr_free(_this, corto_package_o), 0 : 0; _this = NULL;
#define corto_package__assign(_this) _corto_package__assign(_this)
#define corto_package__set(_this) _this = _this ? _this : (corto_package*)corto_ptr_new(corto_package_o); _corto_package__assign(_this)

/* parameter */
CORTO_EXPORT corto_parameter* _corto_parameter__create(corto_object _parent, const char *_id, const char * name, corto_type type, corto_inout inout, bool is_reference);
#define corto_parameter__create(_parent, _id, name, type, inout, is_reference) _corto_parameter__create(_parent, _id, name, corto_type(type), inout, is_reference)
#define corto_parameter__create_auto(_parent, _id, name, type, inout, is_reference) corto_parameter* _id = corto_parameter__create(_parent, #_id, name, type, inout, is_reference); (void)_id
#define corto_parameter__declare(parent, id) (corto_parameter*)corto_declare(parent, id, corto_parameter_o)
CORTO_EXPORT corto_int16 _corto_parameter__update(corto_parameter* _this, const char * name, corto_type type, corto_inout inout, bool is_reference);
#define corto_parameter__update(_this, name, type, inout, is_reference) _corto_parameter__update(corto_parameter(_this), name, corto_type(type), inout, is_reference)
CORTO_EXPORT corto_parameter* _corto_parameter__assign(corto_parameter* _this, const char * name, corto_type type, corto_inout inout, bool is_reference);
#define corto_parameter__optional_not_set NULL
#define corto_parameter__optional_set(name, type, inout, is_reference) (corto_parameter*)corto_parameter__assign((corto_parameter*)corto_ptr_new(corto_parameter_o), name, type, inout, is_reference)
#define corto_parameter__optional_set_cond(__cond, name, type, inout, is_reference) __cond ? (corto_parameter*)corto_parameter__assign((corto_parameter*)corto_ptr_new(corto_parameter_o), name, type, inout, is_reference) : NULL
#define corto_parameter__unset(_this) _this ? corto_ptr_free(_this, corto_parameter_o), 0 : 0; _this = NULL;
#define corto_parameter__assign(_this, name, type, inout, is_reference) _corto_parameter__assign(_this, name, corto_type(type), inout, is_reference)
#define corto_parameter__set(_this, name, type, inout, is_reference) _this = _this ? _this : (corto_parameter*)corto_ptr_new(corto_parameter_o); _corto_parameter__assign(_this, name, corto_type(type), inout, is_reference)

/* parameterseq */
CORTO_EXPORT corto_parameterseq* _corto_parameterseq__create(corto_object _parent, const char *_id, corto_uint32 length, corto_parameter* elements);
#define corto_parameterseq__create(_parent, _id, length, elements) _corto_parameterseq__create(_parent, _id, length, elements)
#define corto_parameterseq__create_auto(_parent, _id, length, elements) corto_parameterseq* _id = corto_parameterseq__create(_parent, #_id, length, elements); (void)_id
#define corto_parameterseq__declare(parent, id) (corto_parameterseq*)corto_declare(parent, id, corto_parameterseq_o)
CORTO_EXPORT corto_int16 _corto_parameterseq__update(corto_parameterseq* _this, corto_uint32 length, corto_parameter* elements);
#define corto_parameterseq__update(_this, length, elements) _corto_parameterseq__update(corto_parameterseq(_this), length, elements)
CORTO_EXPORT corto_parameterseq* _corto_parameterseq__assign(corto_parameterseq* _this, corto_uint32 length, corto_parameter* elements);
#define corto_parameterseq__optional_not_set NULL
#define corto_parameterseq__optional_set(length, elements) (corto_parameterseq*)corto_parameterseq__assign((corto_parameterseq*)corto_ptr_new(corto_parameterseq_o), length, elements)
#define corto_parameterseq__optional_set_cond(__cond, length, elements) __cond ? (corto_parameterseq*)corto_parameterseq__assign((corto_parameterseq*)corto_ptr_new(corto_parameterseq_o), length, elements) : NULL
#define corto_parameterseq__unset(_this) _this ? corto_ptr_free(_this, corto_parameterseq_o), 0 : 0; _this = NULL;
#define corto_parameterseq__assign(_this, length, elements) _corto_parameterseq__assign(_this, length, elements)
#define corto_parameterseq__set(_this, length, elements) _this = _this ? _this : (corto_parameterseq*)corto_ptr_new(corto_parameterseq_o); _corto_parameterseq__assign(_this, length, elements)

/* post_action */
CORTO_EXPORT corto_post_action* _corto_post_action__create(corto_object _parent, const char *_id, corto_object instance, corto_function procedure);
#define corto_post_action__create(_parent, _id, instance, procedure) _corto_post_action__create(_parent, _id, instance, corto_function(procedure))
#define corto_post_action__create_auto(_parent, _id, instance, procedure) corto_post_action* _id = corto_post_action__create(_parent, #_id, instance, procedure); (void)_id
#define corto_post_action__declare(parent, id) (corto_post_action*)corto_declare(parent, id, corto_post_action_o)
CORTO_EXPORT corto_int16 _corto_post_action__update(corto_post_action* _this, corto_object instance, corto_function procedure);
#define corto_post_action__update(_this, instance, procedure) _corto_post_action__update(corto_post_action(_this), instance, corto_function(procedure))
CORTO_EXPORT corto_post_action* _corto_post_action__assign(corto_post_action* _this, corto_object instance, corto_function procedure);
#define corto_post_action__optional_not_set NULL
#define corto_post_action__optional_set(instance, procedure) (corto_post_action*)corto_post_action__assign((corto_post_action*)corto_ptr_new(corto_post_action_o), instance, procedure)
#define corto_post_action__optional_set_cond(__cond, instance, procedure) __cond ? (corto_post_action*)corto_post_action__assign((corto_post_action*)corto_ptr_new(corto_post_action_o), instance, procedure) : NULL
#define corto_post_action__unset(_this) _this ? corto_ptr_free(_this, corto_post_action_o), 0 : 0; _this = NULL;
#define corto_post_action__assign(_this, instance, procedure) _corto_post_action__assign(_this, instance, corto_function(procedure))
#define corto_post_action__set(_this, instance, procedure) _this = _this ? _this : (corto_post_action*)corto_ptr_new(corto_post_action_o); _corto_post_action__assign(_this, instance, corto_function(procedure))
corto_int16 corto_post_action__call(corto_post_action *_delegate);
#define corto_post_action__init_c_auto(d, callback) corto_post_action d; corto_post_action__init_c(&d, callback)
CORTO_EXPORT corto_int16 corto_post_action__init_c(corto_post_action *d, corto_void ___ (*callback)(void));
#define corto_post_action_init_c_instance_auto(d, instance, callback)corto_post_action d; corto_post_action_init_c_instance(&d, instance, callback)
CORTO_EXPORT corto_int16 corto_post_action_init_c_instance(corto_post_action *d, corto_object instance, corto_void ___ (*callback)(corto_object));

/* pre_action */
CORTO_EXPORT corto_pre_action* _corto_pre_action__create(corto_object _parent, const char *_id, corto_object instance, corto_function procedure);
#define corto_pre_action__create(_parent, _id, instance, procedure) _corto_pre_action__create(_parent, _id, instance, corto_function(procedure))
#define corto_pre_action__create_auto(_parent, _id, instance, procedure) corto_pre_action* _id = corto_pre_action__create(_parent, #_id, instance, procedure); (void)_id
#define corto_pre_action__declare(parent, id) (corto_pre_action*)corto_declare(parent, id, corto_pre_action_o)
CORTO_EXPORT corto_int16 _corto_pre_action__update(corto_pre_action* _this, corto_object instance, corto_function procedure);
#define corto_pre_action__update(_this, instance, procedure) _corto_pre_action__update(corto_pre_action(_this), instance, corto_function(procedure))
CORTO_EXPORT corto_pre_action* _corto_pre_action__assign(corto_pre_action* _this, corto_object instance, corto_function procedure);
#define corto_pre_action__optional_not_set NULL
#define corto_pre_action__optional_set(instance, procedure) (corto_pre_action*)corto_pre_action__assign((corto_pre_action*)corto_ptr_new(corto_pre_action_o), instance, procedure)
#define corto_pre_action__optional_set_cond(__cond, instance, procedure) __cond ? (corto_pre_action*)corto_pre_action__assign((corto_pre_action*)corto_ptr_new(corto_pre_action_o), instance, procedure) : NULL
#define corto_pre_action__unset(_this) _this ? corto_ptr_free(_this, corto_pre_action_o), 0 : 0; _this = NULL;
#define corto_pre_action__assign(_this, instance, procedure) _corto_pre_action__assign(_this, instance, corto_function(procedure))
#define corto_pre_action__set(_this, instance, procedure) _this = _this ? _this : (corto_pre_action*)corto_ptr_new(corto_pre_action_o); _corto_pre_action__assign(_this, instance, corto_function(procedure))
corto_int16 corto_pre_action__call(corto_pre_action *_delegate, corto_int16* _result);
#define corto_pre_action__init_c_auto(d, callback) corto_pre_action d; corto_pre_action__init_c(&d, callback)
CORTO_EXPORT corto_int16 corto_pre_action__init_c(corto_pre_action *d, corto_int16 ___ (*callback)(void));
#define corto_pre_action_init_c_instance_auto(d, instance, callback)corto_pre_action d; corto_pre_action_init_c_instance(&d, instance, callback)
CORTO_EXPORT corto_int16 corto_pre_action_init_c_instance(corto_pre_action *d, corto_object instance, corto_int16 ___ (*callback)(corto_object));

/* primitive */
CORTO_EXPORT corto_primitive _corto_primitive__create(corto_object _parent, const char *_id, corto_width width);
#define corto_primitive__create(_parent, _id, width) _corto_primitive__create(_parent, _id, width)
#define corto_primitive__create_auto(_parent, _id, width) corto_primitive _id = corto_primitive__create(_parent, #_id, width); (void)_id
#define corto_primitive__declare(parent, id) (corto_primitive)corto_declare(parent, id, corto_primitive_o)
CORTO_EXPORT corto_int16 _corto_primitive__update(corto_primitive _this, corto_width width);
#define corto_primitive__update(_this, width) _corto_primitive__update(corto_primitive(_this), width)
CORTO_EXPORT corto_primitive _corto_primitive__assign(corto_primitive _this, corto_width width);
#define corto_primitive__optional_not_set NULL
#define corto_primitive__optional_set(width) (corto_primitive*)corto_primitive__assign((corto_primitive*)corto_ptr_new(corto_primitive_o), width)
#define corto_primitive__optional_set_cond(__cond, width) __cond ? (corto_primitive*)corto_primitive__assign((corto_primitive*)corto_ptr_new(corto_primitive_o), width) : NULL
#define corto_primitive__unset(_this) _this ? corto_ptr_free(_this, corto_primitive_o), 0 : 0; _this = NULL;
#define corto_primitive__assign(_this, width) _corto_primitive__assign(_this, width)
#define corto_primitive__set(_this, width) _this = _this ? _this : (corto_primitive*)corto_ptr_new(corto_primitive_o); _corto_primitive__assign(_this, width)

/* primitiveKind */
CORTO_EXPORT corto_primitiveKind* _corto_primitiveKind__create(corto_object _parent, const char *_id, corto_primitiveKind value);
#define corto_primitiveKind__create(_parent, _id, value) _corto_primitiveKind__create(_parent, _id, value)
#define corto_primitiveKind__create_auto(_parent, _id, value) corto_primitiveKind* _id = corto_primitiveKind__create(_parent, #_id, value); (void)_id
#define corto_primitiveKind__declare(parent, id) (corto_primitiveKind*)corto_declare(parent, id, corto_primitiveKind_o)
CORTO_EXPORT corto_int16 _corto_primitiveKind__update(corto_primitiveKind* _this, corto_primitiveKind value);
#define corto_primitiveKind__update(_this, value) _corto_primitiveKind__update(corto_primitiveKind(_this), value)
CORTO_EXPORT corto_primitiveKind* _corto_primitiveKind__assign(corto_primitiveKind* _this, corto_primitiveKind value);
#define corto_primitiveKind__optional_not_set NULL
#define corto_primitiveKind__optional_set(value) (corto_primitiveKind*)corto_primitiveKind__assign((corto_primitiveKind*)corto_ptr_new(corto_primitiveKind_o), value)
#define corto_primitiveKind__optional_set_cond(__cond, value) __cond ? (corto_primitiveKind*)corto_primitiveKind__assign((corto_primitiveKind*)corto_ptr_new(corto_primitiveKind_o), value) : NULL
#define corto_primitiveKind__unset(_this) _this ? corto_ptr_free(_this, corto_primitiveKind_o), 0 : 0; _this = NULL;
#define corto_primitiveKind__assign(_this, value) _corto_primitiveKind__assign(_this, value)
#define corto_primitiveKind__set(_this, value) _this = _this ? _this : (corto_primitiveKind*)corto_ptr_new(corto_primitiveKind_o); _corto_primitiveKind__assign(_this, value)

/* procedure */
CORTO_EXPORT corto_procedure _corto_procedure__create(corto_object _parent, const char *_id, bool has_this, corto_type this_type);
#define corto_procedure__create(_parent, _id, has_this, this_type) _corto_procedure__create(_parent, _id, has_this, corto_type(this_type))
#define corto_procedure__create_auto(_parent, _id, has_this, this_type) corto_procedure _id = corto_procedure__create(_parent, #_id, has_this, this_type); (void)_id
#define corto_procedure__declare(parent, id) (corto_procedure)corto_declare(parent, id, corto_procedure_o)
CORTO_EXPORT corto_int16 _corto_procedure__update(corto_procedure _this, bool has_this, corto_type this_type);
#define corto_procedure__update(_this, has_this, this_type) _corto_procedure__update(corto_procedure(_this), has_this, corto_type(this_type))
CORTO_EXPORT corto_procedure _corto_procedure__assign(corto_procedure _this, bool has_this, corto_type this_type);
#define corto_procedure__optional_not_set NULL
#define corto_procedure__optional_set(has_this, this_type) (corto_procedure*)corto_procedure__assign((corto_procedure*)corto_ptr_new(corto_procedure_o), has_this, this_type)
#define corto_procedure__optional_set_cond(__cond, has_this, this_type) __cond ? (corto_procedure*)corto_procedure__assign((corto_procedure*)corto_ptr_new(corto_procedure_o), has_this, this_type) : NULL
#define corto_procedure__unset(_this) _this ? corto_ptr_free(_this, corto_procedure_o), 0 : 0; _this = NULL;
#define corto_procedure__assign(_this, has_this, this_type) _corto_procedure__assign(_this, has_this, corto_type(this_type))
#define corto_procedure__set(_this, has_this, this_type) _this = _this ? _this : (corto_procedure*)corto_ptr_new(corto_procedure_o); _corto_procedure__assign(_this, has_this, corto_type(this_type))

/* quantity */
CORTO_EXPORT corto_quantity _corto_quantity__create(corto_object _parent, const char *_id, corto_unit base_unit);
#define corto_quantity__create(_parent, _id, base_unit) _corto_quantity__create(_parent, _id, corto_unit(base_unit))
#define corto_quantity__create_auto(_parent, _id, base_unit) corto_quantity _id = corto_quantity__create(_parent, #_id, base_unit); (void)_id
#define corto_quantity__declare(parent, id) (corto_quantity)corto_declare(parent, id, corto_quantity_o)
CORTO_EXPORT corto_int16 _corto_quantity__update(corto_quantity _this, corto_unit base_unit);
#define corto_quantity__update(_this, base_unit) _corto_quantity__update(corto_quantity(_this), corto_unit(base_unit))
CORTO_EXPORT corto_quantity _corto_quantity__assign(corto_quantity _this, corto_unit base_unit);
#define corto_quantity__optional_not_set NULL
#define corto_quantity__optional_set(base_unit) (corto_quantity*)corto_quantity__assign((corto_quantity*)corto_ptr_new(corto_quantity_o), base_unit)
#define corto_quantity__optional_set_cond(__cond, base_unit) __cond ? (corto_quantity*)corto_quantity__assign((corto_quantity*)corto_ptr_new(corto_quantity_o), base_unit) : NULL
#define corto_quantity__unset(_this) _this ? corto_ptr_free(_this, corto_quantity_o), 0 : 0; _this = NULL;
#define corto_quantity__assign(_this, base_unit) _corto_quantity__assign(_this, corto_unit(base_unit))
#define corto_quantity__set(_this, base_unit) _this = _this ? _this : (corto_quantity*)corto_ptr_new(corto_quantity_o); _corto_quantity__assign(_this, corto_unit(base_unit))

/* ref_kind */
CORTO_EXPORT corto_ref_kind* _corto_ref_kind__create(corto_object _parent, const char *_id, corto_ref_kind value);
#define corto_ref_kind__create(_parent, _id, value) _corto_ref_kind__create(_parent, _id, value)
#define corto_ref_kind__create_auto(_parent, _id, value) corto_ref_kind* _id = corto_ref_kind__create(_parent, #_id, value); (void)_id
#define corto_ref_kind__declare(parent, id) (corto_ref_kind*)corto_declare(parent, id, corto_ref_kind_o)
CORTO_EXPORT corto_int16 _corto_ref_kind__update(corto_ref_kind* _this, corto_ref_kind value);
#define corto_ref_kind__update(_this, value) _corto_ref_kind__update(corto_ref_kind(_this), value)
CORTO_EXPORT corto_ref_kind* _corto_ref_kind__assign(corto_ref_kind* _this, corto_ref_kind value);
#define corto_ref_kind__optional_not_set NULL
#define corto_ref_kind__optional_set(value) (corto_ref_kind*)corto_ref_kind__assign((corto_ref_kind*)corto_ptr_new(corto_ref_kind_o), value)
#define corto_ref_kind__optional_set_cond(__cond, value) __cond ? (corto_ref_kind*)corto_ref_kind__assign((corto_ref_kind*)corto_ptr_new(corto_ref_kind_o), value) : NULL
#define corto_ref_kind__unset(_this) _this ? corto_ptr_free(_this, corto_ref_kind_o), 0 : 0; _this = NULL;
#define corto_ref_kind__assign(_this, value) _corto_ref_kind__assign(_this, value)
#define corto_ref_kind__set(_this, value) _this = _this ? _this : (corto_ref_kind*)corto_ptr_new(corto_ref_kind_o); _corto_ref_kind__assign(_this, value)

/* sequence */
CORTO_EXPORT corto_sequence _corto_sequence__create(corto_object _parent, const char *_id, corto_type element_type, uint32_t max);
#define corto_sequence__create(_parent, _id, element_type, max) _corto_sequence__create(_parent, _id, corto_type(element_type), max)
#define corto_sequence__create_auto(_parent, _id, element_type, max) corto_sequence _id = corto_sequence__create(_parent, #_id, element_type, max); (void)_id
#define corto_sequence__declare(parent, id) (corto_sequence)corto_declare(parent, id, corto_sequence_o)
CORTO_EXPORT corto_int16 _corto_sequence__update(corto_sequence _this, corto_type element_type, uint32_t max);
#define corto_sequence__update(_this, element_type, max) _corto_sequence__update(corto_sequence(_this), corto_type(element_type), max)
CORTO_EXPORT corto_sequence _corto_sequence__assign(corto_sequence _this, corto_type element_type, uint32_t max);
#define corto_sequence__optional_not_set NULL
#define corto_sequence__optional_set(element_type, max) (corto_sequence*)corto_sequence__assign((corto_sequence*)corto_ptr_new(corto_sequence_o), element_type, max)
#define corto_sequence__optional_set_cond(__cond, element_type, max) __cond ? (corto_sequence*)corto_sequence__assign((corto_sequence*)corto_ptr_new(corto_sequence_o), element_type, max) : NULL
#define corto_sequence__unset(_this) _this ? corto_ptr_free(_this, corto_sequence_o), 0 : 0; _this = NULL;
#define corto_sequence__assign(_this, element_type, max) _corto_sequence__assign(_this, corto_type(element_type), max)
#define corto_sequence__set(_this, element_type, max) _this = _this ? _this : (corto_sequence*)corto_ptr_new(corto_sequence_o); _corto_sequence__assign(_this, corto_type(element_type), max)

/* state */
CORTO_EXPORT corto_state* _corto_state__create(corto_object _parent, const char *_id, corto_state value);
#define corto_state__create(_parent, _id, value) _corto_state__create(_parent, _id, value)
#define corto_state__create_auto(_parent, _id, value) corto_state* _id = corto_state__create(_parent, #_id, value); (void)_id
#define corto_state__declare(parent, id) (corto_state*)corto_declare(parent, id, corto_state_o)
CORTO_EXPORT corto_int16 _corto_state__update(corto_state* _this, corto_state value);
#define corto_state__update(_this, value) _corto_state__update(corto_state(_this), value)
CORTO_EXPORT corto_state* _corto_state__assign(corto_state* _this, corto_state value);
#define corto_state__optional_not_set NULL
#define corto_state__optional_set(value) (corto_state*)corto_state__assign((corto_state*)corto_ptr_new(corto_state_o), value)
#define corto_state__optional_set_cond(__cond, value) __cond ? (corto_state*)corto_state__assign((corto_state*)corto_ptr_new(corto_state_o), value) : NULL
#define corto_state__unset(_this) _this ? corto_ptr_free(_this, corto_state_o), 0 : 0; _this = NULL;
#define corto_state__assign(_this, value) _corto_state__assign(_this, value)
#define corto_state__set(_this, value) _this = _this ? _this : (corto_state*)corto_ptr_new(corto_state_o); _corto_state__assign(_this, value)

/* string */
CORTO_EXPORT corto_string* _corto_string__create(corto_object _parent, const char *_id, corto_string value);
#define corto_string__create(_parent, _id, value) _corto_string__create(_parent, _id, value)
#define corto_string__create_auto(_parent, _id, value) corto_string* _id = corto_string__create(_parent, #_id, value); (void)_id
#define corto_string__declare(parent, id) (corto_string*)corto_declare(parent, id, corto_string_o)
CORTO_EXPORT corto_int16 _corto_string__update(corto_string* _this, corto_string value);
#define corto_string__update(_this, value) _corto_string__update(corto_string(_this), value)
CORTO_EXPORT corto_string* _corto_string__assign(corto_string* _this, corto_string value);
#define corto_string__optional_not_set NULL
#define corto_string__optional_set(value) (corto_string*)corto_string__assign((corto_string*)corto_ptr_new(corto_string_o), value)
#define corto_string__optional_set_cond(__cond, value) __cond ? (corto_string*)corto_string__assign((corto_string*)corto_ptr_new(corto_string_o), value) : NULL
#define corto_string__unset(_this) _this ? corto_ptr_free(_this, corto_string_o), 0 : 0; _this = NULL;
#define corto_string__assign(_this, value) _corto_string__assign(_this, value)
#define corto_string__set(_this, value) _this = _this ? _this : (corto_string*)corto_ptr_new(corto_string_o); _corto_string__assign(_this, value)

/* stringlist */
CORTO_EXPORT corto_stringlist* _corto_stringlist__create(corto_object _parent, const char *_id, corto_uint32 length, corto_string* elements);
#define corto_stringlist__create(_parent, _id, length, elements) _corto_stringlist__create(_parent, _id, length, elements)
#define corto_stringlist__create_auto(_parent, _id, length, elements) corto_stringlist* _id = corto_stringlist__create(_parent, #_id, length, elements); (void)_id
#define corto_stringlist__declare(parent, id) (corto_stringlist*)corto_declare(parent, id, corto_stringlist_o)
CORTO_EXPORT corto_int16 _corto_stringlist__update(corto_stringlist* _this, corto_uint32 length, corto_string* elements);
#define corto_stringlist__update(_this, length, elements) _corto_stringlist__update(corto_stringlist(_this), length, elements)
CORTO_EXPORT corto_stringlist* _corto_stringlist__assign(corto_stringlist* _this, corto_uint32 length, corto_string* elements);
#define corto_stringlist__optional_not_set NULL
#define corto_stringlist__optional_set(length, elements) (corto_stringlist*)corto_stringlist__assign((corto_stringlist*)corto_ptr_new(corto_stringlist_o), length, elements)
#define corto_stringlist__optional_set_cond(__cond, length, elements) __cond ? (corto_stringlist*)corto_stringlist__assign((corto_stringlist*)corto_ptr_new(corto_stringlist_o), length, elements) : NULL
#define corto_stringlist__unset(_this) _this ? corto_ptr_free(_this, corto_stringlist_o), 0 : 0; _this = NULL;
#define corto_stringlist__assign(_this, length, elements) _corto_stringlist__assign(_this, length, elements)
#define corto_stringlist__set(_this, length, elements) _this = _this ? _this : (corto_stringlist*)corto_ptr_new(corto_stringlist_o); _corto_stringlist__assign(_this, length, elements)

/* stringseq */
CORTO_EXPORT corto_stringseq* _corto_stringseq__create(corto_object _parent, const char *_id, corto_uint32 length, corto_string* elements);
#define corto_stringseq__create(_parent, _id, length, elements) _corto_stringseq__create(_parent, _id, length, elements)
#define corto_stringseq__create_auto(_parent, _id, length, elements) corto_stringseq* _id = corto_stringseq__create(_parent, #_id, length, elements); (void)_id
#define corto_stringseq__declare(parent, id) (corto_stringseq*)corto_declare(parent, id, corto_stringseq_o)
CORTO_EXPORT corto_int16 _corto_stringseq__update(corto_stringseq* _this, corto_uint32 length, corto_string* elements);
#define corto_stringseq__update(_this, length, elements) _corto_stringseq__update(corto_stringseq(_this), length, elements)
CORTO_EXPORT corto_stringseq* _corto_stringseq__assign(corto_stringseq* _this, corto_uint32 length, corto_string* elements);
#define corto_stringseq__optional_not_set NULL
#define corto_stringseq__optional_set(length, elements) (corto_stringseq*)corto_stringseq__assign((corto_stringseq*)corto_ptr_new(corto_stringseq_o), length, elements)
#define corto_stringseq__optional_set_cond(__cond, length, elements) __cond ? (corto_stringseq*)corto_stringseq__assign((corto_stringseq*)corto_ptr_new(corto_stringseq_o), length, elements) : NULL
#define corto_stringseq__unset(_this) _this ? corto_ptr_free(_this, corto_stringseq_o), 0 : 0; _this = NULL;
#define corto_stringseq__assign(_this, length, elements) _corto_stringseq__assign(_this, length, elements)
#define corto_stringseq__set(_this, length, elements) _this = _this ? _this : (corto_stringseq*)corto_ptr_new(corto_stringseq_o); _corto_stringseq__assign(_this, length, elements)

/* struct */
CORTO_EXPORT corto_struct _corto_struct__create(corto_object _parent, const char *_id, corto_interface base, corto_modifierMask base_modifiers);
#define corto_struct__create(_parent, _id, base, base_modifiers) _corto_struct__create(_parent, _id, corto_interface(base), base_modifiers)
#define corto_struct__create_auto(_parent, _id, base, base_modifiers) corto_struct _id = corto_struct__create(_parent, #_id, base, base_modifiers); (void)_id
#define corto_struct__declare(parent, id) (corto_struct)corto_declare(parent, id, corto_struct_o)
CORTO_EXPORT corto_int16 _corto_struct__update(corto_struct _this, corto_interface base, corto_modifierMask base_modifiers);
#define corto_struct__update(_this, base, base_modifiers) _corto_struct__update(corto_struct(_this), corto_interface(base), base_modifiers)
CORTO_EXPORT corto_struct _corto_struct__assign(corto_struct _this, corto_interface base, corto_modifierMask base_modifiers);
#define corto_struct__optional_not_set NULL
#define corto_struct__optional_set(base, base_modifiers) (corto_struct*)corto_struct__assign((corto_struct*)corto_ptr_new(corto_struct_o), base, base_modifiers)
#define corto_struct__optional_set_cond(__cond, base, base_modifiers) __cond ? (corto_struct*)corto_struct__assign((corto_struct*)corto_ptr_new(corto_struct_o), base, base_modifiers) : NULL
#define corto_struct__unset(_this) _this ? corto_ptr_free(_this, corto_struct_o), 0 : 0; _this = NULL;
#define corto_struct__assign(_this, base, base_modifiers) _corto_struct__assign(_this, corto_interface(base), base_modifiers)
#define corto_struct__set(_this, base, base_modifiers) _this = _this ? _this : (corto_struct*)corto_ptr_new(corto_struct_o); _corto_struct__assign(_this, corto_interface(base), base_modifiers)

/* table */
CORTO_EXPORT corto_table _corto_table__create(corto_object _parent, const char *_id, corto_interface base, corto_modifierMask base_modifiers, corto_interfaceseq implements, corto_type type, const char * value);
#define corto_table__create(_parent, _id, base, base_modifiers, implements, type, value) _corto_table__create(_parent, _id, corto_interface(base), base_modifiers, implements, corto_type(type), value)
#define corto_table__create_auto(_parent, _id, base, base_modifiers, implements, type, value) corto_table _id = corto_table__create(_parent, #_id, base, base_modifiers, implements, type, value); (void)_id
#define corto_table__declare(parent, id) (corto_table)corto_declare(parent, id, corto_table_o)
CORTO_EXPORT corto_int16 _corto_table__update(corto_table _this, corto_interface base, corto_modifierMask base_modifiers, corto_interfaceseq implements, corto_type type, const char * value);
#define corto_table__update(_this, base, base_modifiers, implements, type, value) _corto_table__update(corto_table(_this), corto_interface(base), base_modifiers, implements, corto_type(type), value)
CORTO_EXPORT corto_table _corto_table__assign(corto_table _this, corto_interface base, corto_modifierMask base_modifiers, corto_interfaceseq implements, corto_type type, const char * value);
#define corto_table__optional_not_set NULL
#define corto_table__optional_set(base, base_modifiers, implements, type, value) (corto_table*)corto_table__assign((corto_table*)corto_ptr_new(corto_table_o), base, base_modifiers, implements, type, value)
#define corto_table__optional_set_cond(__cond, base, base_modifiers, implements, type, value) __cond ? (corto_table*)corto_table__assign((corto_table*)corto_ptr_new(corto_table_o), base, base_modifiers, implements, type, value) : NULL
#define corto_table__unset(_this) _this ? corto_ptr_free(_this, corto_table_o), 0 : 0; _this = NULL;
#define corto_table__assign(_this, base, base_modifiers, implements, type, value) _corto_table__assign(_this, corto_interface(base), base_modifiers, implements, corto_type(type), value)
#define corto_table__set(_this, base, base_modifiers, implements, type, value) _this = _this ? _this : (corto_table*)corto_ptr_new(corto_table_o); _corto_table__assign(_this, corto_interface(base), base_modifiers, implements, corto_type(type), value)

/* tableinstance */
CORTO_EXPORT corto_tableinstance _corto_tableinstance__create(corto_object _parent, const char *_id, corto_type type);
#define corto_tableinstance__create(_parent, _id, type) _corto_tableinstance__create(_parent, _id, corto_type(type))
#define corto_tableinstance__create_auto(_parent, _id, type) corto_tableinstance _id = corto_tableinstance__create(_parent, #_id, type); (void)_id
#define corto_tableinstance__declare(parent, id) (corto_tableinstance)corto_declare(parent, id, corto_tableinstance_o)
CORTO_EXPORT corto_int16 _corto_tableinstance__update(corto_tableinstance _this, corto_type type);
#define corto_tableinstance__update(_this, type) _corto_tableinstance__update(corto_tableinstance(_this), corto_type(type))
CORTO_EXPORT corto_tableinstance _corto_tableinstance__assign(corto_tableinstance _this, corto_type type);
#define corto_tableinstance__optional_not_set NULL
#define corto_tableinstance__optional_set(type) (corto_tableinstance*)corto_tableinstance__assign((corto_tableinstance*)corto_ptr_new(corto_tableinstance_o), type)
#define corto_tableinstance__optional_set_cond(__cond, type) __cond ? (corto_tableinstance*)corto_tableinstance__assign((corto_tableinstance*)corto_ptr_new(corto_tableinstance_o), type) : NULL
#define corto_tableinstance__unset(_this) _this ? corto_ptr_free(_this, corto_tableinstance_o), 0 : 0; _this = NULL;
#define corto_tableinstance__assign(_this, type) _corto_tableinstance__assign(_this, corto_type(type))
#define corto_tableinstance__set(_this, type) _this = _this ? _this : (corto_tableinstance*)corto_ptr_new(corto_tableinstance_o); _corto_tableinstance__assign(_this, corto_type(type))

/* tag */
CORTO_EXPORT corto_tag _corto_tag__create(corto_object _parent, const char *_id);
#define corto_tag__create(_parent, _id) _corto_tag__create(_parent, _id)
#define corto_tag__create_auto(_parent, _id) corto_tag _id = corto_tag__create(_parent, #_id); (void)_id
#define corto_tag__declare(parent, id) (corto_tag)corto_declare(parent, id, corto_tag_o)
CORTO_EXPORT corto_int16 _corto_tag__update(corto_tag _this);
#define corto_tag__update(_this) _corto_tag__update(corto_tag(_this))
CORTO_EXPORT corto_tag _corto_tag__assign(corto_tag _this);
#define corto_tag__optional_not_set NULL
#define corto_tag__optional_set() (corto_tag*)corto_tag__assign((corto_tag*)corto_ptr_new(corto_tag_o))
#define corto_tag__optional_set_cond(__cond) __cond ? (corto_tag*)corto_tag__assign((corto_tag*)corto_ptr_new(corto_tag_o)) : NULL
#define corto_tag__unset(_this) _this ? corto_ptr_free(_this, corto_tag_o), 0 : 0; _this = NULL;
#define corto_tag__assign(_this) _corto_tag__assign(_this)
#define corto_tag__set(_this) _this = _this ? _this : (corto_tag*)corto_ptr_new(corto_tag_o); _corto_tag__assign(_this)

/* taglist */
CORTO_EXPORT corto_taglist* _corto_taglist__create(corto_object _parent, const char *_id, corto_uint32 length, corto_tag* elements);
#define corto_taglist__create(_parent, _id, length, elements) _corto_taglist__create(_parent, _id, length, elements)
#define corto_taglist__create_auto(_parent, _id, length, elements) corto_taglist* _id = corto_taglist__create(_parent, #_id, length, elements); (void)_id
#define corto_taglist__declare(parent, id) (corto_taglist*)corto_declare(parent, id, corto_taglist_o)
CORTO_EXPORT corto_int16 _corto_taglist__update(corto_taglist* _this, corto_uint32 length, corto_tag* elements);
#define corto_taglist__update(_this, length, elements) _corto_taglist__update(corto_taglist(_this), length, elements)
CORTO_EXPORT corto_taglist* _corto_taglist__assign(corto_taglist* _this, corto_uint32 length, corto_tag* elements);
#define corto_taglist__optional_not_set NULL
#define corto_taglist__optional_set(length, elements) (corto_taglist*)corto_taglist__assign((corto_taglist*)corto_ptr_new(corto_taglist_o), length, elements)
#define corto_taglist__optional_set_cond(__cond, length, elements) __cond ? (corto_taglist*)corto_taglist__assign((corto_taglist*)corto_ptr_new(corto_taglist_o), length, elements) : NULL
#define corto_taglist__unset(_this) _this ? corto_ptr_free(_this, corto_taglist_o), 0 : 0; _this = NULL;
#define corto_taglist__assign(_this, length, elements) _corto_taglist__assign(_this, length, elements)
#define corto_taglist__set(_this, length, elements) _this = _this ? _this : (corto_taglist*)corto_ptr_new(corto_taglist_o); _corto_taglist__assign(_this, length, elements)

/* target */
CORTO_EXPORT corto_target _corto_target__create(corto_object _parent, const char *_id, corto_type type);
#define corto_target__create(_parent, _id, type) _corto_target__create(_parent, _id, corto_type(type))
#define corto_target__create_auto(_parent, _id, type) corto_target _id = corto_target__create(_parent, #_id, type); (void)_id
#define corto_target__declare(parent, id) (corto_target)corto_declare(parent, id, corto_target_o)
CORTO_EXPORT corto_int16 _corto_target__update(corto_target _this, corto_type type);
#define corto_target__update(_this, type) _corto_target__update(corto_target(_this), corto_type(type))
CORTO_EXPORT corto_target _corto_target__assign(corto_target _this, corto_type type);
#define corto_target__optional_not_set NULL
#define corto_target__optional_set(type) (corto_target*)corto_target__assign((corto_target*)corto_ptr_new(corto_target_o), type)
#define corto_target__optional_set_cond(__cond, type) __cond ? (corto_target*)corto_target__assign((corto_target*)corto_ptr_new(corto_target_o), type) : NULL
#define corto_target__unset(_this) _this ? corto_ptr_free(_this, corto_target_o), 0 : 0; _this = NULL;
#define corto_target__assign(_this, type) _corto_target__assign(_this, corto_type(type))
#define corto_target__set(_this, type) _this = _this ? _this : (corto_target*)corto_ptr_new(corto_target_o); _corto_target__assign(_this, corto_type(type))

/* text */
CORTO_EXPORT corto_text _corto_text__create(corto_object _parent, const char *_id, corto_width char_width, uint64_t length);
#define corto_text__create(_parent, _id, char_width, length) _corto_text__create(_parent, _id, char_width, length)
#define corto_text__create_auto(_parent, _id, char_width, length) corto_text _id = corto_text__create(_parent, #_id, char_width, length); (void)_id
#define corto_text__declare(parent, id) (corto_text)corto_declare(parent, id, corto_text_o)
CORTO_EXPORT corto_int16 _corto_text__update(corto_text _this, corto_width char_width, uint64_t length);
#define corto_text__update(_this, char_width, length) _corto_text__update(corto_text(_this), char_width, length)
CORTO_EXPORT corto_text _corto_text__assign(corto_text _this, corto_width char_width, uint64_t length);
#define corto_text__optional_not_set NULL
#define corto_text__optional_set(char_width, length) (corto_text*)corto_text__assign((corto_text*)corto_ptr_new(corto_text_o), char_width, length)
#define corto_text__optional_set_cond(__cond, char_width, length) __cond ? (corto_text*)corto_text__assign((corto_text*)corto_ptr_new(corto_text_o), char_width, length) : NULL
#define corto_text__unset(_this) _this ? corto_ptr_free(_this, corto_text_o), 0 : 0; _this = NULL;
#define corto_text__assign(_this, char_width, length) _corto_text__assign(_this, char_width, length)
#define corto_text__set(_this, char_width, length) _this = _this ? _this : (corto_text*)corto_ptr_new(corto_text_o); _corto_text__assign(_this, char_width, length)

/* tool */
CORTO_EXPORT corto_tool _corto_tool__create(corto_object _parent, const char *_id);
#define corto_tool__create(_parent, _id) _corto_tool__create(_parent, _id)
#define corto_tool__create_auto(_parent, _id) corto_tool _id = corto_tool__create(_parent, #_id); (void)_id
#define corto_tool__declare(parent, id) (corto_tool)corto_declare(parent, id, corto_tool_o)
CORTO_EXPORT corto_int16 _corto_tool__update(corto_tool _this);
#define corto_tool__update(_this) _corto_tool__update(corto_tool(_this))
CORTO_EXPORT corto_tool _corto_tool__assign(corto_tool _this);
#define corto_tool__optional_not_set NULL
#define corto_tool__optional_set() (corto_tool*)corto_tool__assign((corto_tool*)corto_ptr_new(corto_tool_o))
#define corto_tool__optional_set_cond(__cond) __cond ? (corto_tool*)corto_tool__assign((corto_tool*)corto_ptr_new(corto_tool_o)) : NULL
#define corto_tool__unset(_this) _this ? corto_ptr_free(_this, corto_tool_o), 0 : 0; _this = NULL;
#define corto_tool__assign(_this) _corto_tool__assign(_this)
#define corto_tool__set(_this) _this = _this ? _this : (corto_tool*)corto_ptr_new(corto_tool_o); _corto_tool__assign(_this)

/* type */
CORTO_EXPORT corto_type _corto_type__create(corto_object _parent, const char *_id, bool reference);
#define corto_type__create(_parent, _id, reference) _corto_type__create(_parent, _id, reference)
#define corto_type__create_auto(_parent, _id, reference) corto_type _id = corto_type__create(_parent, #_id, reference); (void)_id
#define corto_type__declare(parent, id) (corto_type)corto_declare(parent, id, corto_type_o)
CORTO_EXPORT corto_int16 _corto_type__update(corto_type _this, bool reference);
#define corto_type__update(_this, reference) _corto_type__update(corto_type(_this), reference)
CORTO_EXPORT corto_type _corto_type__assign(corto_type _this, bool reference);
#define corto_type__optional_not_set NULL
#define corto_type__optional_set(reference) (corto_type*)corto_type__assign((corto_type*)corto_ptr_new(corto_type_o), reference)
#define corto_type__optional_set_cond(__cond, reference) __cond ? (corto_type*)corto_type__assign((corto_type*)corto_ptr_new(corto_type_o), reference) : NULL
#define corto_type__unset(_this) _this ? corto_ptr_free(_this, corto_type_o), 0 : 0; _this = NULL;
#define corto_type__assign(_this, reference) _corto_type__assign(_this, reference)
#define corto_type__set(_this, reference) _this = _this ? _this : (corto_type*)corto_ptr_new(corto_type_o); _corto_type__assign(_this, reference)

/* typeKind */
CORTO_EXPORT corto_typeKind* _corto_typeKind__create(corto_object _parent, const char *_id, corto_typeKind value);
#define corto_typeKind__create(_parent, _id, value) _corto_typeKind__create(_parent, _id, value)
#define corto_typeKind__create_auto(_parent, _id, value) corto_typeKind* _id = corto_typeKind__create(_parent, #_id, value); (void)_id
#define corto_typeKind__declare(parent, id) (corto_typeKind*)corto_declare(parent, id, corto_typeKind_o)
CORTO_EXPORT corto_int16 _corto_typeKind__update(corto_typeKind* _this, corto_typeKind value);
#define corto_typeKind__update(_this, value) _corto_typeKind__update(corto_typeKind(_this), value)
CORTO_EXPORT corto_typeKind* _corto_typeKind__assign(corto_typeKind* _this, corto_typeKind value);
#define corto_typeKind__optional_not_set NULL
#define corto_typeKind__optional_set(value) (corto_typeKind*)corto_typeKind__assign((corto_typeKind*)corto_ptr_new(corto_typeKind_o), value)
#define corto_typeKind__optional_set_cond(__cond, value) __cond ? (corto_typeKind*)corto_typeKind__assign((corto_typeKind*)corto_ptr_new(corto_typeKind_o), value) : NULL
#define corto_typeKind__unset(_this) _this ? corto_ptr_free(_this, corto_typeKind_o), 0 : 0; _this = NULL;
#define corto_typeKind__assign(_this, value) _corto_typeKind__assign(_this, value)
#define corto_typeKind__set(_this, value) _this = _this ? _this : (corto_typeKind*)corto_ptr_new(corto_typeKind_o); _corto_typeKind__assign(_this, value)

/* uint */
CORTO_EXPORT corto_uint _corto_uint__create(corto_object _parent, const char *_id, corto_width width, uint64_t min, uint64_t max);
#define corto_uint__create(_parent, _id, width, min, max) _corto_uint__create(_parent, _id, width, min, max)
#define corto_uint__create_auto(_parent, _id, width, min, max) corto_uint _id = corto_uint__create(_parent, #_id, width, min, max); (void)_id
#define corto_uint__declare(parent, id) (corto_uint)corto_declare(parent, id, corto_uint_o)
CORTO_EXPORT corto_int16 _corto_uint__update(corto_uint _this, corto_width width, uint64_t min, uint64_t max);
#define corto_uint__update(_this, width, min, max) _corto_uint__update(corto_uint(_this), width, min, max)
CORTO_EXPORT corto_uint _corto_uint__assign(corto_uint _this, corto_width width, uint64_t min, uint64_t max);
#define corto_uint__optional_not_set NULL
#define corto_uint__optional_set(width, min, max) (corto_uint*)corto_uint__assign((corto_uint*)corto_ptr_new(corto_uint_o), width, min, max)
#define corto_uint__optional_set_cond(__cond, width, min, max) __cond ? (corto_uint*)corto_uint__assign((corto_uint*)corto_ptr_new(corto_uint_o), width, min, max) : NULL
#define corto_uint__unset(_this) _this ? corto_ptr_free(_this, corto_uint_o), 0 : 0; _this = NULL;
#define corto_uint__assign(_this, width, min, max) _corto_uint__assign(_this, width, min, max)
#define corto_uint__set(_this, width, min, max) _this = _this ? _this : (corto_uint*)corto_ptr_new(corto_uint_o); _corto_uint__assign(_this, width, min, max)

/* uint16 */
CORTO_EXPORT uint16_t* _corto_uint16__create(corto_object _parent, const char *_id, uint16_t value);
#define corto_uint16__create(_parent, _id, value) _corto_uint16__create(_parent, _id, value)
#define corto_uint16__create_auto(_parent, _id, value) uint16_t* _id = corto_uint16__create(_parent, #_id, value); (void)_id
#define corto_uint16__declare(parent, id) (uint16_t*)corto_declare(parent, id, corto_uint16_o)
CORTO_EXPORT corto_int16 _corto_uint16__update(uint16_t* _this, uint16_t value);
#define corto_uint16__update(_this, value) _corto_uint16__update(corto_uint16(_this), value)
CORTO_EXPORT uint16_t* _corto_uint16__assign(uint16_t* _this, uint16_t value);
#define corto_uint16__optional_not_set NULL
#define corto_uint16__optional_set(value) (corto_uint16*)corto_uint16__assign((corto_uint16*)corto_ptr_new(corto_uint16_o), value)
#define corto_uint16__optional_set_cond(__cond, value) __cond ? (corto_uint16*)corto_uint16__assign((corto_uint16*)corto_ptr_new(corto_uint16_o), value) : NULL
#define corto_uint16__unset(_this) _this ? corto_ptr_free(_this, corto_uint16_o), 0 : 0; _this = NULL;
#define corto_uint16__assign(_this, value) _corto_uint16__assign(_this, value)
#define corto_uint16__set(_this, value) _this = _this ? _this : (corto_uint16*)corto_ptr_new(corto_uint16_o); _corto_uint16__assign(_this, value)

/* uint32 */
CORTO_EXPORT uint32_t* _corto_uint32__create(corto_object _parent, const char *_id, uint32_t value);
#define corto_uint32__create(_parent, _id, value) _corto_uint32__create(_parent, _id, value)
#define corto_uint32__create_auto(_parent, _id, value) uint32_t* _id = corto_uint32__create(_parent, #_id, value); (void)_id
#define corto_uint32__declare(parent, id) (uint32_t*)corto_declare(parent, id, corto_uint32_o)
CORTO_EXPORT corto_int16 _corto_uint32__update(uint32_t* _this, uint32_t value);
#define corto_uint32__update(_this, value) _corto_uint32__update(corto_uint32(_this), value)
CORTO_EXPORT uint32_t* _corto_uint32__assign(uint32_t* _this, uint32_t value);
#define corto_uint32__optional_not_set NULL
#define corto_uint32__optional_set(value) (corto_uint32*)corto_uint32__assign((corto_uint32*)corto_ptr_new(corto_uint32_o), value)
#define corto_uint32__optional_set_cond(__cond, value) __cond ? (corto_uint32*)corto_uint32__assign((corto_uint32*)corto_ptr_new(corto_uint32_o), value) : NULL
#define corto_uint32__unset(_this) _this ? corto_ptr_free(_this, corto_uint32_o), 0 : 0; _this = NULL;
#define corto_uint32__assign(_this, value) _corto_uint32__assign(_this, value)
#define corto_uint32__set(_this, value) _this = _this ? _this : (corto_uint32*)corto_ptr_new(corto_uint32_o); _corto_uint32__assign(_this, value)

/* uint64 */
CORTO_EXPORT uint64_t* _corto_uint64__create(corto_object _parent, const char *_id, uint64_t value);
#define corto_uint64__create(_parent, _id, value) _corto_uint64__create(_parent, _id, value)
#define corto_uint64__create_auto(_parent, _id, value) uint64_t* _id = corto_uint64__create(_parent, #_id, value); (void)_id
#define corto_uint64__declare(parent, id) (uint64_t*)corto_declare(parent, id, corto_uint64_o)
CORTO_EXPORT corto_int16 _corto_uint64__update(uint64_t* _this, uint64_t value);
#define corto_uint64__update(_this, value) _corto_uint64__update(corto_uint64(_this), value)
CORTO_EXPORT uint64_t* _corto_uint64__assign(uint64_t* _this, uint64_t value);
#define corto_uint64__optional_not_set NULL
#define corto_uint64__optional_set(value) (corto_uint64*)corto_uint64__assign((corto_uint64*)corto_ptr_new(corto_uint64_o), value)
#define corto_uint64__optional_set_cond(__cond, value) __cond ? (corto_uint64*)corto_uint64__assign((corto_uint64*)corto_ptr_new(corto_uint64_o), value) : NULL
#define corto_uint64__unset(_this) _this ? corto_ptr_free(_this, corto_uint64_o), 0 : 0; _this = NULL;
#define corto_uint64__assign(_this, value) _corto_uint64__assign(_this, value)
#define corto_uint64__set(_this, value) _this = _this ? _this : (corto_uint64*)corto_ptr_new(corto_uint64_o); _corto_uint64__assign(_this, value)

/* uint8 */
CORTO_EXPORT uint8_t* _corto_uint8__create(corto_object _parent, const char *_id, uint8_t value);
#define corto_uint8__create(_parent, _id, value) _corto_uint8__create(_parent, _id, value)
#define corto_uint8__create_auto(_parent, _id, value) uint8_t* _id = corto_uint8__create(_parent, #_id, value); (void)_id
#define corto_uint8__declare(parent, id) (uint8_t*)corto_declare(parent, id, corto_uint8_o)
CORTO_EXPORT corto_int16 _corto_uint8__update(uint8_t* _this, uint8_t value);
#define corto_uint8__update(_this, value) _corto_uint8__update(corto_uint8(_this), value)
CORTO_EXPORT uint8_t* _corto_uint8__assign(uint8_t* _this, uint8_t value);
#define corto_uint8__optional_not_set NULL
#define corto_uint8__optional_set(value) (corto_uint8*)corto_uint8__assign((corto_uint8*)corto_ptr_new(corto_uint8_o), value)
#define corto_uint8__optional_set_cond(__cond, value) __cond ? (corto_uint8*)corto_uint8__assign((corto_uint8*)corto_ptr_new(corto_uint8_o), value) : NULL
#define corto_uint8__unset(_this) _this ? corto_ptr_free(_this, corto_uint8_o), 0 : 0; _this = NULL;
#define corto_uint8__assign(_this, value) _corto_uint8__assign(_this, value)
#define corto_uint8__set(_this, value) _this = _this ? _this : (corto_uint8*)corto_ptr_new(corto_uint8_o); _corto_uint8__assign(_this, value)

/* union */
CORTO_EXPORT corto_union _corto_union__create(corto_object _parent, const char *_id, corto_type discriminator);
#define corto_union__create(_parent, _id, discriminator) _corto_union__create(_parent, _id, corto_type(discriminator))
#define corto_union__create_auto(_parent, _id, discriminator) corto_union _id = corto_union__create(_parent, #_id, discriminator); (void)_id
#define corto_union__declare(parent, id) (corto_union)corto_declare(parent, id, corto_union_o)
CORTO_EXPORT corto_int16 _corto_union__update(corto_union _this, corto_type discriminator);
#define corto_union__update(_this, discriminator) _corto_union__update(corto_union(_this), corto_type(discriminator))
CORTO_EXPORT corto_union _corto_union__assign(corto_union _this, corto_type discriminator);
#define corto_union__optional_not_set NULL
#define corto_union__optional_set(discriminator) (corto_union*)corto_union__assign((corto_union*)corto_ptr_new(corto_union_o), discriminator)
#define corto_union__optional_set_cond(__cond, discriminator) __cond ? (corto_union*)corto_union__assign((corto_union*)corto_ptr_new(corto_union_o), discriminator) : NULL
#define corto_union__unset(_this) _this ? corto_ptr_free(_this, corto_union_o), 0 : 0; _this = NULL;
#define corto_union__assign(_this, discriminator) _corto_union__assign(_this, corto_type(discriminator))
#define corto_union__set(_this, discriminator) _this = _this ? _this : (corto_union*)corto_ptr_new(corto_union_o); _corto_union__assign(_this, corto_type(discriminator))

/* unit */
CORTO_EXPORT corto_unit _corto_unit__create(corto_object _parent, const char *_id, corto_quantity quantity, const char * symbol, const char * conversion, corto_type type);
#define corto_unit__create(_parent, _id, quantity, symbol, conversion, type) _corto_unit__create(_parent, _id, corto_quantity(quantity), symbol, conversion, corto_type(type))
#define corto_unit__create_auto(_parent, _id, quantity, symbol, conversion, type) corto_unit _id = corto_unit__create(_parent, #_id, quantity, symbol, conversion, type); (void)_id
#define corto_unit__declare(parent, id) (corto_unit)corto_declare(parent, id, corto_unit_o)
CORTO_EXPORT corto_int16 _corto_unit__update(corto_unit _this, corto_quantity quantity, const char * symbol, const char * conversion, corto_type type);
#define corto_unit__update(_this, quantity, symbol, conversion, type) _corto_unit__update(corto_unit(_this), corto_quantity(quantity), symbol, conversion, corto_type(type))
CORTO_EXPORT corto_unit _corto_unit__assign(corto_unit _this, corto_quantity quantity, const char * symbol, const char * conversion, corto_type type);
#define corto_unit__optional_not_set NULL
#define corto_unit__optional_set(quantity, symbol, conversion, type) (corto_unit*)corto_unit__assign((corto_unit*)corto_ptr_new(corto_unit_o), quantity, symbol, conversion, type)
#define corto_unit__optional_set_cond(__cond, quantity, symbol, conversion, type) __cond ? (corto_unit*)corto_unit__assign((corto_unit*)corto_ptr_new(corto_unit_o), quantity, symbol, conversion, type) : NULL
#define corto_unit__unset(_this) _this ? corto_ptr_free(_this, corto_unit_o), 0 : 0; _this = NULL;
#define corto_unit__assign(_this, quantity, symbol, conversion, type) _corto_unit__assign(_this, corto_quantity(quantity), symbol, conversion, corto_type(type))
#define corto_unit__set(_this, quantity, symbol, conversion, type) _this = _this ? _this : (corto_unit*)corto_ptr_new(corto_unit_o); _corto_unit__assign(_this, corto_quantity(quantity), symbol, conversion, corto_type(type))

/* unknown */
CORTO_EXPORT void* _corto_unknown__create(corto_object _parent, const char *_id);
#define corto_unknown__create(_parent, _id) _corto_unknown__create(_parent, _id)
#define corto_unknown__create_auto(_parent, _id) void* _id = corto_unknown__create(_parent, #_id); (void)_id
#define corto_unknown__declare(parent, id) (void*)corto_declare(parent, id, corto_unknown_o)
CORTO_EXPORT corto_int16 _corto_unknown__update(void* _this);
#define corto_unknown__update(_this) _corto_unknown__update(corto_unknown(_this))

/* verbatim */
CORTO_EXPORT corto_verbatim _corto_verbatim__create(corto_object _parent, const char *_id, const char * format);
#define corto_verbatim__create(_parent, _id, format) _corto_verbatim__create(_parent, _id, format)
#define corto_verbatim__create_auto(_parent, _id, format) corto_verbatim _id = corto_verbatim__create(_parent, #_id, format); (void)_id
#define corto_verbatim__declare(parent, id) (corto_verbatim)corto_declare(parent, id, corto_verbatim_o)
CORTO_EXPORT corto_int16 _corto_verbatim__update(corto_verbatim _this, const char * format);
#define corto_verbatim__update(_this, format) _corto_verbatim__update(corto_verbatim(_this), format)
CORTO_EXPORT corto_verbatim _corto_verbatim__assign(corto_verbatim _this, const char * format);
#define corto_verbatim__optional_not_set NULL
#define corto_verbatim__optional_set(format) (corto_verbatim*)corto_verbatim__assign((corto_verbatim*)corto_ptr_new(corto_verbatim_o), format)
#define corto_verbatim__optional_set_cond(__cond, format) __cond ? (corto_verbatim*)corto_verbatim__assign((corto_verbatim*)corto_ptr_new(corto_verbatim_o), format) : NULL
#define corto_verbatim__unset(_this) _this ? corto_ptr_free(_this, corto_verbatim_o), 0 : 0; _this = NULL;
#define corto_verbatim__assign(_this, format) _corto_verbatim__assign(_this, format)
#define corto_verbatim__set(_this, format) _this = _this ? _this : (corto_verbatim*)corto_ptr_new(corto_verbatim_o); _corto_verbatim__assign(_this, format)

/* void */
CORTO_EXPORT void* _corto_void__create(corto_object _parent, const char *_id);
#define corto_void__create(_parent, _id) _corto_void__create(_parent, _id)
#define corto_void__create_auto(_parent, _id) void* _id = corto_void__create(_parent, #_id); (void)_id
#define corto_void__declare(parent, id) (void*)corto_declare(parent, id, corto_void_o)
CORTO_EXPORT corto_int16 _corto_void__update(void* _this);
#define corto_void__update(_this) _corto_void__update(corto_void(_this))

/* width */
CORTO_EXPORT corto_width* _corto_width__create(corto_object _parent, const char *_id, corto_width value);
#define corto_width__create(_parent, _id, value) _corto_width__create(_parent, _id, value)
#define corto_width__create_auto(_parent, _id, value) corto_width* _id = corto_width__create(_parent, #_id, value); (void)_id
#define corto_width__declare(parent, id) (corto_width*)corto_declare(parent, id, corto_width_o)
CORTO_EXPORT corto_int16 _corto_width__update(corto_width* _this, corto_width value);
#define corto_width__update(_this, value) _corto_width__update(corto_width(_this), value)
CORTO_EXPORT corto_width* _corto_width__assign(corto_width* _this, corto_width value);
#define corto_width__optional_not_set NULL
#define corto_width__optional_set(value) (corto_width*)corto_width__assign((corto_width*)corto_ptr_new(corto_width_o), value)
#define corto_width__optional_set_cond(__cond, value) __cond ? (corto_width*)corto_width__assign((corto_width*)corto_ptr_new(corto_width_o), value) : NULL
#define corto_width__unset(_this) _this ? corto_ptr_free(_this, corto_width_o), 0 : 0; _this = NULL;
#define corto_width__assign(_this, value) _corto_width__assign(_this, value)
#define corto_width__set(_this, value) _this = _this ? _this : (corto_width*)corto_ptr_new(corto_width_o); _corto_width__assign(_this, value)

/* word */
CORTO_EXPORT uintptr_t* _corto_word__create(corto_object _parent, const char *_id, uintptr_t value);
#define corto_word__create(_parent, _id, value) _corto_word__create(_parent, _id, value)
#define corto_word__create_auto(_parent, _id, value) uintptr_t* _id = corto_word__create(_parent, #_id, value); (void)_id
#define corto_word__declare(parent, id) (uintptr_t*)corto_declare(parent, id, corto_word_o)
CORTO_EXPORT corto_int16 _corto_word__update(uintptr_t* _this, uintptr_t value);
#define corto_word__update(_this, value) _corto_word__update(corto_word(_this), value)
CORTO_EXPORT uintptr_t* _corto_word__assign(uintptr_t* _this, uintptr_t value);
#define corto_word__optional_not_set NULL
#define corto_word__optional_set(value) (corto_word*)corto_word__assign((corto_word*)corto_ptr_new(corto_word_o), value)
#define corto_word__optional_set_cond(__cond, value) __cond ? (corto_word*)corto_word__assign((corto_word*)corto_ptr_new(corto_word_o), value) : NULL
#define corto_word__unset(_this) _this ? corto_ptr_free(_this, corto_word_o), 0 : 0; _this = NULL;
#define corto_word__assign(_this, value) _corto_word__assign(_this, value)
#define corto_word__set(_this, value) _this = _this ? _this : (corto_word*)corto_ptr_new(corto_word_o); _corto_word__assign(_this, value)

/* wordseq */
CORTO_EXPORT corto_wordseq* _corto_wordseq__create(corto_object _parent, const char *_id, corto_uint32 length, uintptr_t* elements);
#define corto_wordseq__create(_parent, _id, length, elements) _corto_wordseq__create(_parent, _id, length, elements)
#define corto_wordseq__create_auto(_parent, _id, length, elements) corto_wordseq* _id = corto_wordseq__create(_parent, #_id, length, elements); (void)_id
#define corto_wordseq__declare(parent, id) (corto_wordseq*)corto_declare(parent, id, corto_wordseq_o)
CORTO_EXPORT corto_int16 _corto_wordseq__update(corto_wordseq* _this, corto_uint32 length, uintptr_t* elements);
#define corto_wordseq__update(_this, length, elements) _corto_wordseq__update(corto_wordseq(_this), length, elements)
CORTO_EXPORT corto_wordseq* _corto_wordseq__assign(corto_wordseq* _this, corto_uint32 length, uintptr_t* elements);
#define corto_wordseq__optional_not_set NULL
#define corto_wordseq__optional_set(length, elements) (corto_wordseq*)corto_wordseq__assign((corto_wordseq*)corto_ptr_new(corto_wordseq_o), length, elements)
#define corto_wordseq__optional_set_cond(__cond, length, elements) __cond ? (corto_wordseq*)corto_wordseq__assign((corto_wordseq*)corto_ptr_new(corto_wordseq_o), length, elements) : NULL
#define corto_wordseq__unset(_this) _this ? corto_ptr_free(_this, corto_wordseq_o), 0 : 0; _this = NULL;
#define corto_wordseq__assign(_this, length, elements) _corto_wordseq__assign(_this, length, elements)
#define corto_wordseq__set(_this, length, elements) _this = _this ? _this : (corto_wordseq*)corto_ptr_new(corto_wordseq_o); _corto_wordseq__assign(_this, length, elements)


/* int32seq */
CORTO_EXPORT int32_t* corto_int32seq__append(corto_int32seq *seq, int32_t element);
CORTO_EXPORT int32_t* corto_int32seq__append_alloc(corto_int32seq *seq);
CORTO_EXPORT void corto_int32seq__resize(corto_int32seq *seq, corto_uint32 length);
CORTO_EXPORT void corto_int32seq__clear(corto_int32seq *seq);

/* interfaceseq */
CORTO_EXPORT corto_interface* corto_interfaceseq__append(corto_interfaceseq *seq, corto_interface element);
CORTO_EXPORT corto_interface* corto_interfaceseq__append_alloc(corto_interfaceseq *seq);
CORTO_EXPORT void corto_interfaceseq__resize(corto_interfaceseq *seq, corto_uint32 length);
CORTO_EXPORT void corto_interfaceseq__clear(corto_interfaceseq *seq);

/* interfaceVectorseq */
CORTO_EXPORT corto_interfaceVector* corto_interfaceVectorseq__append(corto_interfaceVectorseq *seq, corto_interfaceVector element);
CORTO_EXPORT corto_interfaceVector* corto_interfaceVectorseq__append_alloc(corto_interfaceVectorseq *seq);
CORTO_EXPORT void corto_interfaceVectorseq__resize(corto_interfaceVectorseq *seq, corto_uint32 length);
CORTO_EXPORT void corto_interfaceVectorseq__clear(corto_interfaceVectorseq *seq);

/* objectlist */
CORTO_EXPORT void corto_objectlist__insert(corto_objectlist list, corto_object element);
CORTO_EXPORT void corto_objectlist__append(corto_objectlist list, corto_object element);
CORTO_EXPORT void corto_objectlist__remove(corto_objectlist list, corto_object element);
CORTO_EXPORT corto_object corto_objectlist__takeFirst(corto_objectlist list);
CORTO_EXPORT corto_object corto_objectlist__last(corto_objectlist list);
CORTO_EXPORT corto_object corto_objectlist__get(corto_objectlist list, corto_uint32 index);
CORTO_EXPORT void corto_objectlist__clear(corto_objectlist list);

/* objectseq */
CORTO_EXPORT corto_object* corto_objectseq__append(corto_objectseq *seq, corto_object element);
CORTO_EXPORT corto_object* corto_objectseq__append_alloc(corto_objectseq *seq);
CORTO_EXPORT void corto_objectseq__resize(corto_objectseq *seq, corto_uint32 length);
CORTO_EXPORT void corto_objectseq__clear(corto_objectseq *seq);

/* parameterseq */
CORTO_EXPORT corto_parameter* corto_parameterseq__append(corto_parameterseq *seq, corto_parameter element);
CORTO_EXPORT corto_parameter* corto_parameterseq__append_alloc(corto_parameterseq *seq);
CORTO_EXPORT void corto_parameterseq__resize(corto_parameterseq *seq, corto_uint32 length);
CORTO_EXPORT void corto_parameterseq__clear(corto_parameterseq *seq);

/* stringlist */
CORTO_EXPORT void corto_stringlist__insert(corto_stringlist list, corto_string element);
CORTO_EXPORT void corto_stringlist__append(corto_stringlist list, corto_string element);
CORTO_EXPORT corto_string corto_stringlist__takeFirst(corto_stringlist list);
CORTO_EXPORT corto_string corto_stringlist__last(corto_stringlist list);
CORTO_EXPORT corto_string corto_stringlist__get(corto_stringlist list, corto_uint32 index);
CORTO_EXPORT void corto_stringlist__clear(corto_stringlist list);

/* stringseq */
CORTO_EXPORT corto_string* corto_stringseq__append(corto_stringseq *seq, corto_string element);
CORTO_EXPORT corto_string* corto_stringseq__append_alloc(corto_stringseq *seq);
CORTO_EXPORT void corto_stringseq__resize(corto_stringseq *seq, corto_uint32 length);
CORTO_EXPORT void corto_stringseq__clear(corto_stringseq *seq);

/* taglist */
CORTO_EXPORT void corto_taglist__insert(corto_taglist list, corto_tag element);
CORTO_EXPORT void corto_taglist__append(corto_taglist list, corto_tag element);
CORTO_EXPORT void corto_taglist__remove(corto_taglist list, corto_tag element);
CORTO_EXPORT corto_tag corto_taglist__takeFirst(corto_taglist list);
CORTO_EXPORT corto_tag corto_taglist__last(corto_taglist list);
CORTO_EXPORT corto_tag corto_taglist__get(corto_taglist list, corto_uint32 index);
CORTO_EXPORT void corto_taglist__clear(corto_taglist list);

/* wordseq */
CORTO_EXPORT uintptr_t* corto_wordseq__append(corto_wordseq *seq, uintptr_t element);
CORTO_EXPORT uintptr_t* corto_wordseq__append_alloc(corto_wordseq *seq);
CORTO_EXPORT void corto_wordseq__resize(corto_wordseq *seq, corto_uint32 length);
CORTO_EXPORT void corto_wordseq__clear(corto_wordseq *seq);

#ifdef __cplusplus
}
#endif
#endif

