/* lang.h
 *
 * API convenience functions for C-language.
 * This file contains generated code. Do not modify!
 */

#ifndef CORTO_LANG__API_H
#define CORTO_LANG__API_H

#include <corto/corto.h>
#include <corto/_project.h>
#ifdef __cplusplus
extern "C" {
#endif
/* alias */
CORTO_EXPORT corto_alias _corto_aliasCreate(corto_member member);
#define corto_aliasCreate(member) _corto_aliasCreate(corto_member(member))
#define corto_aliasCreate_auto(_id, member) corto_alias _id = corto_aliasCreate(member); (void)_id
CORTO_EXPORT corto_alias _corto_aliasCreateChild(corto_object _parent, corto_string _id, corto_member member);
#define corto_aliasCreateChild(_parent, _id, member) _corto_aliasCreateChild(_parent, _id, corto_member(member))
#define corto_aliasCreateChild_auto(_parent, _id, member) corto_alias _id = corto_aliasCreateChild(_parent, #_id, member); (void)_id
CORTO_EXPORT corto_int16 _corto_aliasUpdate(corto_alias _this, corto_member member);
#define corto_aliasUpdate(_this, member) _corto_aliasUpdate(corto_alias(_this), corto_member(member))
CORTO_EXPORT corto_alias _corto_aliasAssign(corto_alias _this, corto_member member);
#define corto_alias__optional_NotSet NULL
#define corto_alias__optional_Set(member) corto_aliasAssign((corto_alias*)corto_ptr_new(corto_alias_o)), member)
#define corto_alias__optional_SetCond(cond, member) cond ? corto_aliasAssign((corto_alias*)corto_ptr_new(corto_alias_o), member) : NULL
#define corto_aliasUnset(_this) _this ? corto_ptr_free(_this, corto_alias_o), 0 : 0; _this = NULL;
#define corto_aliasAssign(_this, member) _corto_aliasAssign(_this, corto_member(member))
#define corto_aliasSet(_this, member) _this = _this ? _this : (corto_alias*)corto_ptr_new(corto_alias_o); _corto_aliasAssign(_this, corto_member(member))

CORTO_EXPORT corto_alias _corto_aliasDeclare(void);
#define corto_aliasDeclare() _corto_aliasDeclare()
#define corto_aliasDeclare_auto(_id) corto_alias _id = corto_aliasDeclare(); (void)_id
CORTO_EXPORT corto_alias _corto_aliasDeclareChild(corto_object _parent, corto_string _id);
#define corto_aliasDeclareChild(_parent, _id) _corto_aliasDeclareChild(_parent, _id)
#define corto_aliasDeclareChild_auto(_parent, _id) corto_alias _id = corto_aliasDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_aliasDefine(corto_alias _this, corto_member member);
#define corto_aliasDefine(_this, member) _corto_aliasDefine(corto_alias(_this), corto_member(member))

/* any */
CORTO_EXPORT corto_any* _corto_anyCreate(corto_type type, void *value);
#define corto_anyCreate(type, value) _corto_anyCreate(corto_type(type), value)
#define corto_anyCreate_auto(_id, type, value) corto_any* _id = corto_anyCreate(type, value); (void)_id
CORTO_EXPORT corto_any* _corto_anyCreateChild(corto_object _parent, corto_string _id, corto_type type, void *value);
#define corto_anyCreateChild(_parent, _id, type, value) _corto_anyCreateChild(_parent, _id, corto_type(type), value)
#define corto_anyCreateChild_auto(_parent, _id, type, value) corto_any* _id = corto_anyCreateChild(_parent, #_id, type, value); (void)_id
CORTO_EXPORT corto_int16 _corto_anyUpdate(corto_any* _this, corto_type type, void *value);
#define corto_anyUpdate(_this, type, value) _corto_anyUpdate(corto_any(_this), corto_type(type), value)
CORTO_EXPORT corto_any* _corto_anyAssign(corto_any* _this, corto_type type, void *value);
#define corto_any__optional_NotSet NULL
#define corto_any__optional_Set(type, value) corto_anyAssign((corto_any*)corto_ptr_new(corto_any_o)), type, value)
#define corto_any__optional_SetCond(cond, type, value) cond ? corto_anyAssign((corto_any*)corto_ptr_new(corto_any_o), type, value) : NULL
#define corto_anyUnset(_this) _this ? corto_ptr_free(_this, corto_any_o), 0 : 0; _this = NULL;
#define corto_anyAssign(_this, type, value) _corto_anyAssign(_this, corto_type(type), value)
#define corto_anySet(_this, type, value) _this = _this ? _this : (corto_any*)corto_ptr_new(corto_any_o); _corto_anyAssign(_this, corto_type(type), value)

CORTO_EXPORT corto_any* _corto_anyDeclare(void);
#define corto_anyDeclare() _corto_anyDeclare()
#define corto_anyDeclare_auto(_id) corto_any* _id = corto_anyDeclare(); (void)_id
CORTO_EXPORT corto_any* _corto_anyDeclareChild(corto_object _parent, corto_string _id);
#define corto_anyDeclareChild(_parent, _id) _corto_anyDeclareChild(_parent, _id)
#define corto_anyDeclareChild_auto(_parent, _id) corto_any* _id = corto_anyDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_anyDefine(corto_any* _this, corto_type type, void *value);
#define corto_anyDefine(_this, type, value) _corto_anyDefine(corto_any(_this), corto_type(type), value)

/* array */
CORTO_EXPORT corto_array _corto_arrayCreate(corto_type elementType, uint32_t max);
#define corto_arrayCreate(elementType, max) _corto_arrayCreate(corto_type(elementType), max)
#define corto_arrayCreate_auto(_id, elementType, max) corto_array _id = corto_arrayCreate(elementType, max); (void)_id
CORTO_EXPORT corto_array _corto_arrayCreateChild(corto_object _parent, corto_string _id, corto_type elementType, uint32_t max);
#define corto_arrayCreateChild(_parent, _id, elementType, max) _corto_arrayCreateChild(_parent, _id, corto_type(elementType), max)
#define corto_arrayCreateChild_auto(_parent, _id, elementType, max) corto_array _id = corto_arrayCreateChild(_parent, #_id, elementType, max); (void)_id
CORTO_EXPORT corto_int16 _corto_arrayUpdate(corto_array _this, corto_type elementType, uint32_t max);
#define corto_arrayUpdate(_this, elementType, max) _corto_arrayUpdate(corto_array(_this), corto_type(elementType), max)
CORTO_EXPORT corto_array _corto_arrayAssign(corto_array _this, corto_type elementType, uint32_t max);
#define corto_array__optional_NotSet NULL
#define corto_array__optional_Set(elementType, max) corto_arrayAssign((corto_array*)corto_ptr_new(corto_array_o)), elementType, max)
#define corto_array__optional_SetCond(cond, elementType, max) cond ? corto_arrayAssign((corto_array*)corto_ptr_new(corto_array_o), elementType, max) : NULL
#define corto_arrayUnset(_this) _this ? corto_ptr_free(_this, corto_array_o), 0 : 0; _this = NULL;
#define corto_arrayAssign(_this, elementType, max) _corto_arrayAssign(_this, corto_type(elementType), max)
#define corto_arraySet(_this, elementType, max) _this = _this ? _this : (corto_array*)corto_ptr_new(corto_array_o); _corto_arrayAssign(_this, corto_type(elementType), max)

CORTO_EXPORT corto_array _corto_arrayDeclare(void);
#define corto_arrayDeclare() _corto_arrayDeclare()
#define corto_arrayDeclare_auto(_id) corto_array _id = corto_arrayDeclare(); (void)_id
CORTO_EXPORT corto_array _corto_arrayDeclareChild(corto_object _parent, corto_string _id);
#define corto_arrayDeclareChild(_parent, _id) _corto_arrayDeclareChild(_parent, _id)
#define corto_arrayDeclareChild_auto(_parent, _id) corto_array _id = corto_arrayDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_arrayDefine(corto_array _this, corto_type elementType, uint32_t max);
#define corto_arrayDefine(_this, elementType, max) _corto_arrayDefine(corto_array(_this), corto_type(elementType), max)

/* attr */
CORTO_EXPORT corto_attr* _corto_attrCreate(corto_attr value);
#define corto_attrCreate(value) _corto_attrCreate(value)
#define corto_attrCreate_auto(_id, value) corto_attr* _id = corto_attrCreate(value); (void)_id
CORTO_EXPORT corto_attr* _corto_attrCreateChild(corto_object _parent, corto_string _id, corto_attr value);
#define corto_attrCreateChild(_parent, _id, value) _corto_attrCreateChild(_parent, _id, value)
#define corto_attrCreateChild_auto(_parent, _id, value) corto_attr* _id = corto_attrCreateChild(_parent, #_id, value); (void)_id
CORTO_EXPORT corto_int16 _corto_attrUpdate(corto_attr* _this, corto_attr value);
#define corto_attrUpdate(_this, value) _corto_attrUpdate(corto_attr(_this), value)
CORTO_EXPORT corto_attr* _corto_attrAssign(corto_attr* _this, corto_attr value);
#define corto_attr__optional_NotSet NULL
#define corto_attr__optional_Set(value) corto_attrAssign((corto_attr*)corto_ptr_new(corto_attr_o)), value)
#define corto_attr__optional_SetCond(cond, value) cond ? corto_attrAssign((corto_attr*)corto_ptr_new(corto_attr_o), value) : NULL
#define corto_attrUnset(_this) _this ? corto_ptr_free(_this, corto_attr_o), 0 : 0; _this = NULL;
#define corto_attrAssign(_this, value) _corto_attrAssign(_this, value)
#define corto_attrSet(_this, value) _this = _this ? _this : (corto_attr*)corto_ptr_new(corto_attr_o); _corto_attrAssign(_this, value)

CORTO_EXPORT corto_attr* _corto_attrDeclare(void);
#define corto_attrDeclare() _corto_attrDeclare()
#define corto_attrDeclare_auto(_id) corto_attr* _id = corto_attrDeclare(); (void)_id
CORTO_EXPORT corto_attr* _corto_attrDeclareChild(corto_object _parent, corto_string _id);
#define corto_attrDeclareChild(_parent, _id) _corto_attrDeclareChild(_parent, _id)
#define corto_attrDeclareChild_auto(_parent, _id) corto_attr* _id = corto_attrDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_attrDefine(corto_attr* _this, corto_attr value);
#define corto_attrDefine(_this, value) _corto_attrDefine(corto_attr(_this), value)

/* binary */
CORTO_EXPORT corto_binary _corto_binaryCreate(corto_width width);
#define corto_binaryCreate(width) _corto_binaryCreate(width)
#define corto_binaryCreate_auto(_id, width) corto_binary _id = corto_binaryCreate(width); (void)_id
CORTO_EXPORT corto_binary _corto_binaryCreateChild(corto_object _parent, corto_string _id, corto_width width);
#define corto_binaryCreateChild(_parent, _id, width) _corto_binaryCreateChild(_parent, _id, width)
#define corto_binaryCreateChild_auto(_parent, _id, width) corto_binary _id = corto_binaryCreateChild(_parent, #_id, width); (void)_id
CORTO_EXPORT corto_int16 _corto_binaryUpdate(corto_binary _this, corto_width width);
#define corto_binaryUpdate(_this, width) _corto_binaryUpdate(corto_binary(_this), width)
CORTO_EXPORT corto_binary _corto_binaryAssign(corto_binary _this, corto_width width);
#define corto_binary__optional_NotSet NULL
#define corto_binary__optional_Set(width) corto_binaryAssign((corto_binary*)corto_ptr_new(corto_binary_o)), width)
#define corto_binary__optional_SetCond(cond, width) cond ? corto_binaryAssign((corto_binary*)corto_ptr_new(corto_binary_o), width) : NULL
#define corto_binaryUnset(_this) _this ? corto_ptr_free(_this, corto_binary_o), 0 : 0; _this = NULL;
#define corto_binaryAssign(_this, width) _corto_binaryAssign(_this, width)
#define corto_binarySet(_this, width) _this = _this ? _this : (corto_binary*)corto_ptr_new(corto_binary_o); _corto_binaryAssign(_this, width)

CORTO_EXPORT corto_binary _corto_binaryDeclare(void);
#define corto_binaryDeclare() _corto_binaryDeclare()
#define corto_binaryDeclare_auto(_id) corto_binary _id = corto_binaryDeclare(); (void)_id
CORTO_EXPORT corto_binary _corto_binaryDeclareChild(corto_object _parent, corto_string _id);
#define corto_binaryDeclareChild(_parent, _id) _corto_binaryDeclareChild(_parent, _id)
#define corto_binaryDeclareChild_auto(_parent, _id) corto_binary _id = corto_binaryDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_binaryDefine(corto_binary _this, corto_width width);
#define corto_binaryDefine(_this, width) _corto_binaryDefine(corto_binary(_this), width)

/* bitmask */
CORTO_EXPORT corto_bitmask _corto_bitmaskCreate(void);
#define corto_bitmaskCreate() _corto_bitmaskCreate()
#define corto_bitmaskCreate_auto(_id) corto_bitmask _id = corto_bitmaskCreate(); (void)_id
CORTO_EXPORT corto_bitmask _corto_bitmaskCreateChild(corto_object _parent, corto_string _id);
#define corto_bitmaskCreateChild(_parent, _id) _corto_bitmaskCreateChild(_parent, _id)
#define corto_bitmaskCreateChild_auto(_parent, _id) corto_bitmask _id = corto_bitmaskCreateChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_bitmaskUpdate(corto_bitmask _this);
#define corto_bitmaskUpdate(_this) _corto_bitmaskUpdate(corto_bitmask(_this))
CORTO_EXPORT corto_bitmask _corto_bitmaskAssign(corto_bitmask _this);
#define corto_bitmask__optional_NotSet NULL
#define corto_bitmask__optional_Set() corto_bitmaskAssign((corto_bitmask*)corto_ptr_new(corto_bitmask_o)))
#define corto_bitmask__optional_SetCond(cond) cond ? corto_bitmaskAssign((corto_bitmask*)corto_ptr_new(corto_bitmask_o)) : NULL
#define corto_bitmaskUnset(_this) _this ? corto_ptr_free(_this, corto_bitmask_o), 0 : 0; _this = NULL;
#define corto_bitmaskAssign(_this) _corto_bitmaskAssign(_this)
#define corto_bitmaskSet(_this) _this = _this ? _this : (corto_bitmask*)corto_ptr_new(corto_bitmask_o); _corto_bitmaskAssign(_this)

CORTO_EXPORT corto_bitmask _corto_bitmaskDeclare(void);
#define corto_bitmaskDeclare() _corto_bitmaskDeclare()
#define corto_bitmaskDeclare_auto(_id) corto_bitmask _id = corto_bitmaskDeclare(); (void)_id
CORTO_EXPORT corto_bitmask _corto_bitmaskDeclareChild(corto_object _parent, corto_string _id);
#define corto_bitmaskDeclareChild(_parent, _id) _corto_bitmaskDeclareChild(_parent, _id)
#define corto_bitmaskDeclareChild_auto(_parent, _id) corto_bitmask _id = corto_bitmaskDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_bitmaskDefine(corto_bitmask _this);
#define corto_bitmaskDefine(_this) _corto_bitmaskDefine(corto_bitmask(_this))

/* bool */
CORTO_EXPORT bool* _corto_boolCreate(bool value);
#define corto_boolCreate(value) _corto_boolCreate(value)
#define corto_boolCreate_auto(_id, value) bool* _id = corto_boolCreate(value); (void)_id
CORTO_EXPORT bool* _corto_boolCreateChild(corto_object _parent, corto_string _id, bool value);
#define corto_boolCreateChild(_parent, _id, value) _corto_boolCreateChild(_parent, _id, value)
#define corto_boolCreateChild_auto(_parent, _id, value) bool* _id = corto_boolCreateChild(_parent, #_id, value); (void)_id
CORTO_EXPORT corto_int16 _corto_boolUpdate(bool* _this, bool value);
#define corto_boolUpdate(_this, value) _corto_boolUpdate(corto_bool(_this), value)
CORTO_EXPORT bool* _corto_boolAssign(bool* _this, bool value);
#define corto_bool__optional_NotSet NULL
#define corto_bool__optional_Set(value) corto_boolAssign((corto_bool*)corto_ptr_new(corto_bool_o)), value)
#define corto_bool__optional_SetCond(cond, value) cond ? corto_boolAssign((corto_bool*)corto_ptr_new(corto_bool_o), value) : NULL
#define corto_boolUnset(_this) _this ? corto_ptr_free(_this, corto_bool_o), 0 : 0; _this = NULL;
#define corto_boolAssign(_this, value) _corto_boolAssign(_this, value)
#define corto_boolSet(_this, value) _this = _this ? _this : (corto_bool*)corto_ptr_new(corto_bool_o); _corto_boolAssign(_this, value)

CORTO_EXPORT bool* _corto_boolDeclare(void);
#define corto_boolDeclare() _corto_boolDeclare()
#define corto_boolDeclare_auto(_id) bool* _id = corto_boolDeclare(); (void)_id
CORTO_EXPORT bool* _corto_boolDeclareChild(corto_object _parent, corto_string _id);
#define corto_boolDeclareChild(_parent, _id) _corto_boolDeclareChild(_parent, _id)
#define corto_boolDeclareChild_auto(_parent, _id) bool* _id = corto_boolDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_boolDefine(bool* _this, bool value);
#define corto_boolDefine(_this, value) _corto_boolDefine(corto_bool(_this), value)

/* boolean */
CORTO_EXPORT corto_boolean _corto_booleanCreate(void);
#define corto_booleanCreate() _corto_booleanCreate()
#define corto_booleanCreate_auto(_id) corto_boolean _id = corto_booleanCreate(); (void)_id
CORTO_EXPORT corto_boolean _corto_booleanCreateChild(corto_object _parent, corto_string _id);
#define corto_booleanCreateChild(_parent, _id) _corto_booleanCreateChild(_parent, _id)
#define corto_booleanCreateChild_auto(_parent, _id) corto_boolean _id = corto_booleanCreateChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_booleanUpdate(corto_boolean _this);
#define corto_booleanUpdate(_this) _corto_booleanUpdate(corto_boolean(_this))
CORTO_EXPORT corto_boolean _corto_booleanAssign(corto_boolean _this);
#define corto_boolean__optional_NotSet NULL
#define corto_boolean__optional_Set() corto_booleanAssign((corto_boolean*)corto_ptr_new(corto_boolean_o)))
#define corto_boolean__optional_SetCond(cond) cond ? corto_booleanAssign((corto_boolean*)corto_ptr_new(corto_boolean_o)) : NULL
#define corto_booleanUnset(_this) _this ? corto_ptr_free(_this, corto_boolean_o), 0 : 0; _this = NULL;
#define corto_booleanAssign(_this) _corto_booleanAssign(_this)
#define corto_booleanSet(_this) _this = _this ? _this : (corto_boolean*)corto_ptr_new(corto_boolean_o); _corto_booleanAssign(_this)

CORTO_EXPORT corto_boolean _corto_booleanDeclare(void);
#define corto_booleanDeclare() _corto_booleanDeclare()
#define corto_booleanDeclare_auto(_id) corto_boolean _id = corto_booleanDeclare(); (void)_id
CORTO_EXPORT corto_boolean _corto_booleanDeclareChild(corto_object _parent, corto_string _id);
#define corto_booleanDeclareChild(_parent, _id) _corto_booleanDeclareChild(_parent, _id)
#define corto_booleanDeclareChild_auto(_parent, _id) corto_boolean _id = corto_booleanDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_booleanDefine(corto_boolean _this);
#define corto_booleanDefine(_this) _corto_booleanDefine(corto_boolean(_this))

/* case */
CORTO_EXPORT corto_case _corto_caseCreate(corto_int32seq discriminator, corto_type type);
#define corto_caseCreate(discriminator, type) _corto_caseCreate(discriminator, corto_type(type))
#define corto_caseCreate_auto(_id, discriminator, type) corto_case _id = corto_caseCreate(discriminator, type); (void)_id
CORTO_EXPORT corto_case _corto_caseCreateChild(corto_object _parent, corto_string _id, corto_int32seq discriminator, corto_type type);
#define corto_caseCreateChild(_parent, _id, discriminator, type) _corto_caseCreateChild(_parent, _id, discriminator, corto_type(type))
#define corto_caseCreateChild_auto(_parent, _id, discriminator, type) corto_case _id = corto_caseCreateChild(_parent, #_id, discriminator, type); (void)_id
CORTO_EXPORT corto_int16 _corto_caseUpdate(corto_case _this, corto_int32seq discriminator, corto_type type);
#define corto_caseUpdate(_this, discriminator, type) _corto_caseUpdate(corto_case(_this), discriminator, corto_type(type))
CORTO_EXPORT corto_case _corto_caseAssign(corto_case _this, corto_int32seq discriminator, corto_type type);
#define corto_case__optional_NotSet NULL
#define corto_case__optional_Set(discriminator, type) corto_caseAssign((corto_case*)corto_ptr_new(corto_case_o)), discriminator, type)
#define corto_case__optional_SetCond(cond, discriminator, type) cond ? corto_caseAssign((corto_case*)corto_ptr_new(corto_case_o), discriminator, type) : NULL
#define corto_caseUnset(_this) _this ? corto_ptr_free(_this, corto_case_o), 0 : 0; _this = NULL;
#define corto_caseAssign(_this, discriminator, type) _corto_caseAssign(_this, discriminator, corto_type(type))
#define corto_caseSet(_this, discriminator, type) _this = _this ? _this : (corto_case*)corto_ptr_new(corto_case_o); _corto_caseAssign(_this, discriminator, corto_type(type))

CORTO_EXPORT corto_case _corto_caseDeclare(void);
#define corto_caseDeclare() _corto_caseDeclare()
#define corto_caseDeclare_auto(_id) corto_case _id = corto_caseDeclare(); (void)_id
CORTO_EXPORT corto_case _corto_caseDeclareChild(corto_object _parent, corto_string _id);
#define corto_caseDeclareChild(_parent, _id) _corto_caseDeclareChild(_parent, _id)
#define corto_caseDeclareChild_auto(_parent, _id) corto_case _id = corto_caseDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_caseDefine(corto_case _this, corto_int32seq discriminator, corto_type type);
#define corto_caseDefine(_this, discriminator, type) _corto_caseDefine(corto_case(_this), discriminator, corto_type(type))

/* char */
CORTO_EXPORT char* _corto_charCreate(char value);
#define corto_charCreate(value) _corto_charCreate(value)
#define corto_charCreate_auto(_id, value) char* _id = corto_charCreate(value); (void)_id
CORTO_EXPORT char* _corto_charCreateChild(corto_object _parent, corto_string _id, char value);
#define corto_charCreateChild(_parent, _id, value) _corto_charCreateChild(_parent, _id, value)
#define corto_charCreateChild_auto(_parent, _id, value) char* _id = corto_charCreateChild(_parent, #_id, value); (void)_id
CORTO_EXPORT corto_int16 _corto_charUpdate(char* _this, char value);
#define corto_charUpdate(_this, value) _corto_charUpdate(corto_char(_this), value)
CORTO_EXPORT char* _corto_charAssign(char* _this, char value);
#define corto_char__optional_NotSet NULL
#define corto_char__optional_Set(value) corto_charAssign((corto_char*)corto_ptr_new(corto_char_o)), value)
#define corto_char__optional_SetCond(cond, value) cond ? corto_charAssign((corto_char*)corto_ptr_new(corto_char_o), value) : NULL
#define corto_charUnset(_this) _this ? corto_ptr_free(_this, corto_char_o), 0 : 0; _this = NULL;
#define corto_charAssign(_this, value) _corto_charAssign(_this, value)
#define corto_charSet(_this, value) _this = _this ? _this : (corto_char*)corto_ptr_new(corto_char_o); _corto_charAssign(_this, value)

CORTO_EXPORT char* _corto_charDeclare(void);
#define corto_charDeclare() _corto_charDeclare()
#define corto_charDeclare_auto(_id) char* _id = corto_charDeclare(); (void)_id
CORTO_EXPORT char* _corto_charDeclareChild(corto_object _parent, corto_string _id);
#define corto_charDeclareChild(_parent, _id) _corto_charDeclareChild(_parent, _id)
#define corto_charDeclareChild_auto(_parent, _id) char* _id = corto_charDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_charDefine(char* _this, char value);
#define corto_charDefine(_this, value) _corto_charDefine(corto_char(_this), value)

/* character */
CORTO_EXPORT corto_character _corto_characterCreate(corto_width width);
#define corto_characterCreate(width) _corto_characterCreate(width)
#define corto_characterCreate_auto(_id, width) corto_character _id = corto_characterCreate(width); (void)_id
CORTO_EXPORT corto_character _corto_characterCreateChild(corto_object _parent, corto_string _id, corto_width width);
#define corto_characterCreateChild(_parent, _id, width) _corto_characterCreateChild(_parent, _id, width)
#define corto_characterCreateChild_auto(_parent, _id, width) corto_character _id = corto_characterCreateChild(_parent, #_id, width); (void)_id
CORTO_EXPORT corto_int16 _corto_characterUpdate(corto_character _this, corto_width width);
#define corto_characterUpdate(_this, width) _corto_characterUpdate(corto_character(_this), width)
CORTO_EXPORT corto_character _corto_characterAssign(corto_character _this, corto_width width);
#define corto_character__optional_NotSet NULL
#define corto_character__optional_Set(width) corto_characterAssign((corto_character*)corto_ptr_new(corto_character_o)), width)
#define corto_character__optional_SetCond(cond, width) cond ? corto_characterAssign((corto_character*)corto_ptr_new(corto_character_o), width) : NULL
#define corto_characterUnset(_this) _this ? corto_ptr_free(_this, corto_character_o), 0 : 0; _this = NULL;
#define corto_characterAssign(_this, width) _corto_characterAssign(_this, width)
#define corto_characterSet(_this, width) _this = _this ? _this : (corto_character*)corto_ptr_new(corto_character_o); _corto_characterAssign(_this, width)

CORTO_EXPORT corto_character _corto_characterDeclare(void);
#define corto_characterDeclare() _corto_characterDeclare()
#define corto_characterDeclare_auto(_id) corto_character _id = corto_characterDeclare(); (void)_id
CORTO_EXPORT corto_character _corto_characterDeclareChild(corto_object _parent, corto_string _id);
#define corto_characterDeclareChild(_parent, _id) _corto_characterDeclareChild(_parent, _id)
#define corto_characterDeclareChild_auto(_parent, _id) corto_character _id = corto_characterDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_characterDefine(corto_character _this, corto_width width);
#define corto_characterDefine(_this, width) _corto_characterDefine(corto_character(_this), width)

/* class */
CORTO_EXPORT corto_class _corto_classCreate(corto_interface base, corto_modifier baseAccess, corto_interfaceseq implements);
#define corto_classCreate(base, baseAccess, implements) _corto_classCreate(corto_interface(base), baseAccess, implements)
#define corto_classCreate_auto(_id, base, baseAccess, implements) corto_class _id = corto_classCreate(base, baseAccess, implements); (void)_id
CORTO_EXPORT corto_class _corto_classCreateChild(corto_object _parent, corto_string _id, corto_interface base, corto_modifier baseAccess, corto_interfaceseq implements);
#define corto_classCreateChild(_parent, _id, base, baseAccess, implements) _corto_classCreateChild(_parent, _id, corto_interface(base), baseAccess, implements)
#define corto_classCreateChild_auto(_parent, _id, base, baseAccess, implements) corto_class _id = corto_classCreateChild(_parent, #_id, base, baseAccess, implements); (void)_id
CORTO_EXPORT corto_int16 _corto_classUpdate(corto_class _this, corto_interface base, corto_modifier baseAccess, corto_interfaceseq implements);
#define corto_classUpdate(_this, base, baseAccess, implements) _corto_classUpdate(corto_class(_this), corto_interface(base), baseAccess, implements)
CORTO_EXPORT corto_class _corto_classAssign(corto_class _this, corto_interface base, corto_modifier baseAccess, corto_interfaceseq implements);
#define corto_class__optional_NotSet NULL
#define corto_class__optional_Set(base, baseAccess, implements) corto_classAssign((corto_class*)corto_ptr_new(corto_class_o)), base, baseAccess, implements)
#define corto_class__optional_SetCond(cond, base, baseAccess, implements) cond ? corto_classAssign((corto_class*)corto_ptr_new(corto_class_o), base, baseAccess, implements) : NULL
#define corto_classUnset(_this) _this ? corto_ptr_free(_this, corto_class_o), 0 : 0; _this = NULL;
#define corto_classAssign(_this, base, baseAccess, implements) _corto_classAssign(_this, corto_interface(base), baseAccess, implements)
#define corto_classSet(_this, base, baseAccess, implements) _this = _this ? _this : (corto_class*)corto_ptr_new(corto_class_o); _corto_classAssign(_this, corto_interface(base), baseAccess, implements)

CORTO_EXPORT corto_class _corto_classDeclare(void);
#define corto_classDeclare() _corto_classDeclare()
#define corto_classDeclare_auto(_id) corto_class _id = corto_classDeclare(); (void)_id
CORTO_EXPORT corto_class _corto_classDeclareChild(corto_object _parent, corto_string _id);
#define corto_classDeclareChild(_parent, _id) _corto_classDeclareChild(_parent, _id)
#define corto_classDeclareChild_auto(_parent, _id) corto_class _id = corto_classDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_classDefine(corto_class _this, corto_interface base, corto_modifier baseAccess, corto_interfaceseq implements);
#define corto_classDefine(_this, base, baseAccess, implements) _corto_classDefine(corto_class(_this), corto_interface(base), baseAccess, implements)

/* collection */
CORTO_EXPORT corto_collection _corto_collectionCreate(corto_type elementType, uint32_t max);
#define corto_collectionCreate(elementType, max) _corto_collectionCreate(corto_type(elementType), max)
#define corto_collectionCreate_auto(_id, elementType, max) corto_collection _id = corto_collectionCreate(elementType, max); (void)_id
CORTO_EXPORT corto_collection _corto_collectionCreateChild(corto_object _parent, corto_string _id, corto_type elementType, uint32_t max);
#define corto_collectionCreateChild(_parent, _id, elementType, max) _corto_collectionCreateChild(_parent, _id, corto_type(elementType), max)
#define corto_collectionCreateChild_auto(_parent, _id, elementType, max) corto_collection _id = corto_collectionCreateChild(_parent, #_id, elementType, max); (void)_id
CORTO_EXPORT corto_int16 _corto_collectionUpdate(corto_collection _this, corto_type elementType, uint32_t max);
#define corto_collectionUpdate(_this, elementType, max) _corto_collectionUpdate(corto_collection(_this), corto_type(elementType), max)
CORTO_EXPORT corto_collection _corto_collectionAssign(corto_collection _this, corto_type elementType, uint32_t max);
#define corto_collection__optional_NotSet NULL
#define corto_collection__optional_Set(elementType, max) corto_collectionAssign((corto_collection*)corto_ptr_new(corto_collection_o)), elementType, max)
#define corto_collection__optional_SetCond(cond, elementType, max) cond ? corto_collectionAssign((corto_collection*)corto_ptr_new(corto_collection_o), elementType, max) : NULL
#define corto_collectionUnset(_this) _this ? corto_ptr_free(_this, corto_collection_o), 0 : 0; _this = NULL;
#define corto_collectionAssign(_this, elementType, max) _corto_collectionAssign(_this, corto_type(elementType), max)
#define corto_collectionSet(_this, elementType, max) _this = _this ? _this : (corto_collection*)corto_ptr_new(corto_collection_o); _corto_collectionAssign(_this, corto_type(elementType), max)

CORTO_EXPORT corto_collection _corto_collectionDeclare(void);
#define corto_collectionDeclare() _corto_collectionDeclare()
#define corto_collectionDeclare_auto(_id) corto_collection _id = corto_collectionDeclare(); (void)_id
CORTO_EXPORT corto_collection _corto_collectionDeclareChild(corto_object _parent, corto_string _id);
#define corto_collectionDeclareChild(_parent, _id) _corto_collectionDeclareChild(_parent, _id)
#define corto_collectionDeclareChild_auto(_parent, _id) corto_collection _id = corto_collectionDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_collectionDefine(corto_collection _this, corto_type elementType, uint32_t max);
#define corto_collectionDefine(_this, elementType, max) _corto_collectionDefine(corto_collection(_this), corto_type(elementType), max)

/* collectionKind */
CORTO_EXPORT corto_collectionKind* _corto_collectionKindCreate(corto_collectionKind value);
#define corto_collectionKindCreate(value) _corto_collectionKindCreate(value)
#define corto_collectionKindCreate_auto(_id, value) corto_collectionKind* _id = corto_collectionKindCreate(value); (void)_id
CORTO_EXPORT corto_collectionKind* _corto_collectionKindCreateChild(corto_object _parent, corto_string _id, corto_collectionKind value);
#define corto_collectionKindCreateChild(_parent, _id, value) _corto_collectionKindCreateChild(_parent, _id, value)
#define corto_collectionKindCreateChild_auto(_parent, _id, value) corto_collectionKind* _id = corto_collectionKindCreateChild(_parent, #_id, value); (void)_id
CORTO_EXPORT corto_int16 _corto_collectionKindUpdate(corto_collectionKind* _this, corto_collectionKind value);
#define corto_collectionKindUpdate(_this, value) _corto_collectionKindUpdate(corto_collectionKind(_this), value)
CORTO_EXPORT corto_collectionKind* _corto_collectionKindAssign(corto_collectionKind* _this, corto_collectionKind value);
#define corto_collectionKind__optional_NotSet NULL
#define corto_collectionKind__optional_Set(value) corto_collectionKindAssign((corto_collectionKind*)corto_ptr_new(corto_collectionKind_o)), value)
#define corto_collectionKind__optional_SetCond(cond, value) cond ? corto_collectionKindAssign((corto_collectionKind*)corto_ptr_new(corto_collectionKind_o), value) : NULL
#define corto_collectionKindUnset(_this) _this ? corto_ptr_free(_this, corto_collectionKind_o), 0 : 0; _this = NULL;
#define corto_collectionKindAssign(_this, value) _corto_collectionKindAssign(_this, value)
#define corto_collectionKindSet(_this, value) _this = _this ? _this : (corto_collectionKind*)corto_ptr_new(corto_collectionKind_o); _corto_collectionKindAssign(_this, value)

CORTO_EXPORT corto_collectionKind* _corto_collectionKindDeclare(void);
#define corto_collectionKindDeclare() _corto_collectionKindDeclare()
#define corto_collectionKindDeclare_auto(_id) corto_collectionKind* _id = corto_collectionKindDeclare(); (void)_id
CORTO_EXPORT corto_collectionKind* _corto_collectionKindDeclareChild(corto_object _parent, corto_string _id);
#define corto_collectionKindDeclareChild(_parent, _id) _corto_collectionKindDeclareChild(_parent, _id)
#define corto_collectionKindDeclareChild_auto(_parent, _id) corto_collectionKind* _id = corto_collectionKindDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_collectionKindDefine(corto_collectionKind* _this, corto_collectionKind value);
#define corto_collectionKindDefine(_this, value) _corto_collectionKindDefine(corto_collectionKind(_this), value)

/* compositeKind */
CORTO_EXPORT corto_compositeKind* _corto_compositeKindCreate(corto_compositeKind value);
#define corto_compositeKindCreate(value) _corto_compositeKindCreate(value)
#define corto_compositeKindCreate_auto(_id, value) corto_compositeKind* _id = corto_compositeKindCreate(value); (void)_id
CORTO_EXPORT corto_compositeKind* _corto_compositeKindCreateChild(corto_object _parent, corto_string _id, corto_compositeKind value);
#define corto_compositeKindCreateChild(_parent, _id, value) _corto_compositeKindCreateChild(_parent, _id, value)
#define corto_compositeKindCreateChild_auto(_parent, _id, value) corto_compositeKind* _id = corto_compositeKindCreateChild(_parent, #_id, value); (void)_id
CORTO_EXPORT corto_int16 _corto_compositeKindUpdate(corto_compositeKind* _this, corto_compositeKind value);
#define corto_compositeKindUpdate(_this, value) _corto_compositeKindUpdate(corto_compositeKind(_this), value)
CORTO_EXPORT corto_compositeKind* _corto_compositeKindAssign(corto_compositeKind* _this, corto_compositeKind value);
#define corto_compositeKind__optional_NotSet NULL
#define corto_compositeKind__optional_Set(value) corto_compositeKindAssign((corto_compositeKind*)corto_ptr_new(corto_compositeKind_o)), value)
#define corto_compositeKind__optional_SetCond(cond, value) cond ? corto_compositeKindAssign((corto_compositeKind*)corto_ptr_new(corto_compositeKind_o), value) : NULL
#define corto_compositeKindUnset(_this) _this ? corto_ptr_free(_this, corto_compositeKind_o), 0 : 0; _this = NULL;
#define corto_compositeKindAssign(_this, value) _corto_compositeKindAssign(_this, value)
#define corto_compositeKindSet(_this, value) _this = _this ? _this : (corto_compositeKind*)corto_ptr_new(corto_compositeKind_o); _corto_compositeKindAssign(_this, value)

CORTO_EXPORT corto_compositeKind* _corto_compositeKindDeclare(void);
#define corto_compositeKindDeclare() _corto_compositeKindDeclare()
#define corto_compositeKindDeclare_auto(_id) corto_compositeKind* _id = corto_compositeKindDeclare(); (void)_id
CORTO_EXPORT corto_compositeKind* _corto_compositeKindDeclareChild(corto_object _parent, corto_string _id);
#define corto_compositeKindDeclareChild(_parent, _id) _corto_compositeKindDeclareChild(_parent, _id)
#define corto_compositeKindDeclareChild_auto(_parent, _id) corto_compositeKind* _id = corto_compositeKindDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_compositeKindDefine(corto_compositeKind* _this, corto_compositeKind value);
#define corto_compositeKindDefine(_this, value) _corto_compositeKindDefine(corto_compositeKind(_this), value)

/* constant */
CORTO_EXPORT int32_t* _corto_constantCreate(int32_t value);
#define corto_constantCreate(value) _corto_constantCreate(value)
#define corto_constantCreate_auto(_id, value) int32_t* _id = corto_constantCreate(value); (void)_id
CORTO_EXPORT int32_t* _corto_constantCreateChild(corto_object _parent, corto_string _id, int32_t value);
#define corto_constantCreateChild(_parent, _id, value) _corto_constantCreateChild(_parent, _id, value)
#define corto_constantCreateChild_auto(_parent, _id, value) int32_t* _id = corto_constantCreateChild(_parent, #_id, value); (void)_id
CORTO_EXPORT corto_int16 _corto_constantUpdate(int32_t* _this, int32_t value);
#define corto_constantUpdate(_this, value) _corto_constantUpdate(corto_constant(_this), value)
CORTO_EXPORT int32_t* _corto_constantAssign(int32_t* _this, int32_t value);
#define corto_constant__optional_NotSet NULL
#define corto_constant__optional_Set(value) corto_constantAssign((corto_constant*)corto_ptr_new(corto_constant_o)), value)
#define corto_constant__optional_SetCond(cond, value) cond ? corto_constantAssign((corto_constant*)corto_ptr_new(corto_constant_o), value) : NULL
#define corto_constantUnset(_this) _this ? corto_ptr_free(_this, corto_constant_o), 0 : 0; _this = NULL;
#define corto_constantAssign(_this, value) _corto_constantAssign(_this, value)
#define corto_constantSet(_this, value) _this = _this ? _this : (corto_constant*)corto_ptr_new(corto_constant_o); _corto_constantAssign(_this, value)

CORTO_EXPORT int32_t* _corto_constantDeclare(void);
#define corto_constantDeclare() _corto_constantDeclare()
#define corto_constantDeclare_auto(_id) int32_t* _id = corto_constantDeclare(); (void)_id
CORTO_EXPORT int32_t* _corto_constantDeclareChild(corto_object _parent, corto_string _id);
#define corto_constantDeclareChild(_parent, _id) _corto_constantDeclareChild(_parent, _id)
#define corto_constantDeclareChild_auto(_parent, _id) int32_t* _id = corto_constantDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_constantDefine(int32_t* _this, int32_t value);
#define corto_constantDefine(_this, value) _corto_constantDefine(corto_constant(_this), value)

/* container */
CORTO_EXPORT corto_container _corto_containerCreate(corto_interface base, corto_modifier baseAccess, corto_interfaceseq implements, corto_type type, corto_string value);
#define corto_containerCreate(base, baseAccess, implements, type, value) _corto_containerCreate(corto_interface(base), baseAccess, implements, corto_type(type), value)
#define corto_containerCreate_auto(_id, base, baseAccess, implements, type, value) corto_container _id = corto_containerCreate(base, baseAccess, implements, type, value); (void)_id
CORTO_EXPORT corto_container _corto_containerCreateChild(corto_object _parent, corto_string _id, corto_interface base, corto_modifier baseAccess, corto_interfaceseq implements, corto_type type, corto_string value);
#define corto_containerCreateChild(_parent, _id, base, baseAccess, implements, type, value) _corto_containerCreateChild(_parent, _id, corto_interface(base), baseAccess, implements, corto_type(type), value)
#define corto_containerCreateChild_auto(_parent, _id, base, baseAccess, implements, type, value) corto_container _id = corto_containerCreateChild(_parent, #_id, base, baseAccess, implements, type, value); (void)_id
CORTO_EXPORT corto_int16 _corto_containerUpdate(corto_container _this, corto_interface base, corto_modifier baseAccess, corto_interfaceseq implements, corto_type type, corto_string value);
#define corto_containerUpdate(_this, base, baseAccess, implements, type, value) _corto_containerUpdate(corto_container(_this), corto_interface(base), baseAccess, implements, corto_type(type), value)
CORTO_EXPORT corto_container _corto_containerAssign(corto_container _this, corto_interface base, corto_modifier baseAccess, corto_interfaceseq implements, corto_type type, corto_string value);
#define corto_container__optional_NotSet NULL
#define corto_container__optional_Set(base, baseAccess, implements, type, value) corto_containerAssign((corto_container*)corto_ptr_new(corto_container_o)), base, baseAccess, implements, type, value)
#define corto_container__optional_SetCond(cond, base, baseAccess, implements, type, value) cond ? corto_containerAssign((corto_container*)corto_ptr_new(corto_container_o), base, baseAccess, implements, type, value) : NULL
#define corto_containerUnset(_this) _this ? corto_ptr_free(_this, corto_container_o), 0 : 0; _this = NULL;
#define corto_containerAssign(_this, base, baseAccess, implements, type, value) _corto_containerAssign(_this, corto_interface(base), baseAccess, implements, corto_type(type), value)
#define corto_containerSet(_this, base, baseAccess, implements, type, value) _this = _this ? _this : (corto_container*)corto_ptr_new(corto_container_o); _corto_containerAssign(_this, corto_interface(base), baseAccess, implements, corto_type(type), value)

CORTO_EXPORT corto_container _corto_containerDeclare(void);
#define corto_containerDeclare() _corto_containerDeclare()
#define corto_containerDeclare_auto(_id) corto_container _id = corto_containerDeclare(); (void)_id
CORTO_EXPORT corto_container _corto_containerDeclareChild(corto_object _parent, corto_string _id);
#define corto_containerDeclareChild(_parent, _id) _corto_containerDeclareChild(_parent, _id)
#define corto_containerDeclareChild_auto(_parent, _id) corto_container _id = corto_containerDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_containerDefine(corto_container _this, corto_interface base, corto_modifier baseAccess, corto_interfaceseq implements, corto_type type, corto_string value);
#define corto_containerDefine(_this, base, baseAccess, implements, type, value) _corto_containerDefine(corto_container(_this), corto_interface(base), baseAccess, implements, corto_type(type), value)

/* default */
CORTO_EXPORT corto_default _corto_defaultCreate(corto_type type);
#define corto_defaultCreate(type) _corto_defaultCreate(corto_type(type))
#define corto_defaultCreate_auto(_id, type) corto_default _id = corto_defaultCreate(type); (void)_id
CORTO_EXPORT corto_default _corto_defaultCreateChild(corto_object _parent, corto_string _id, corto_type type);
#define corto_defaultCreateChild(_parent, _id, type) _corto_defaultCreateChild(_parent, _id, corto_type(type))
#define corto_defaultCreateChild_auto(_parent, _id, type) corto_default _id = corto_defaultCreateChild(_parent, #_id, type); (void)_id
CORTO_EXPORT corto_int16 _corto_defaultUpdate(corto_default _this, corto_type type);
#define corto_defaultUpdate(_this, type) _corto_defaultUpdate(corto_default(_this), corto_type(type))
CORTO_EXPORT corto_default _corto_defaultAssign(corto_default _this, corto_type type);
#define corto_default__optional_NotSet NULL
#define corto_default__optional_Set(type) corto_defaultAssign((corto_default*)corto_ptr_new(corto_default_o)), type)
#define corto_default__optional_SetCond(cond, type) cond ? corto_defaultAssign((corto_default*)corto_ptr_new(corto_default_o), type) : NULL
#define corto_defaultUnset(_this) _this ? corto_ptr_free(_this, corto_default_o), 0 : 0; _this = NULL;
#define corto_defaultAssign(_this, type) _corto_defaultAssign(_this, corto_type(type))
#define corto_defaultSet(_this, type) _this = _this ? _this : (corto_default*)corto_ptr_new(corto_default_o); _corto_defaultAssign(_this, corto_type(type))

CORTO_EXPORT corto_default _corto_defaultDeclare(void);
#define corto_defaultDeclare() _corto_defaultDeclare()
#define corto_defaultDeclare_auto(_id) corto_default _id = corto_defaultDeclare(); (void)_id
CORTO_EXPORT corto_default _corto_defaultDeclareChild(corto_object _parent, corto_string _id);
#define corto_defaultDeclareChild(_parent, _id) _corto_defaultDeclareChild(_parent, _id)
#define corto_defaultDeclareChild_auto(_parent, _id) corto_default _id = corto_defaultDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_defaultDefine(corto_default _this, corto_type type);
#define corto_defaultDefine(_this, type) _corto_defaultDefine(corto_default(_this), corto_type(type))

/* delegate */
CORTO_EXPORT corto_delegate _corto_delegateCreate(corto_type returnType, bool returnsReference, corto_parameterseq parameters);
#define corto_delegateCreate(returnType, returnsReference, parameters) _corto_delegateCreate(corto_type(returnType), returnsReference, parameters)
#define corto_delegateCreate_auto(_id, returnType, returnsReference, parameters) corto_delegate _id = corto_delegateCreate(returnType, returnsReference, parameters); (void)_id
CORTO_EXPORT corto_delegate _corto_delegateCreateChild(corto_object _parent, corto_string _id, corto_type returnType, bool returnsReference, corto_parameterseq parameters);
#define corto_delegateCreateChild(_parent, _id, returnType, returnsReference, parameters) _corto_delegateCreateChild(_parent, _id, corto_type(returnType), returnsReference, parameters)
#define corto_delegateCreateChild_auto(_parent, _id, returnType, returnsReference, parameters) corto_delegate _id = corto_delegateCreateChild(_parent, #_id, returnType, returnsReference, parameters); (void)_id
CORTO_EXPORT corto_int16 _corto_delegateUpdate(corto_delegate _this, corto_type returnType, bool returnsReference, corto_parameterseq parameters);
#define corto_delegateUpdate(_this, returnType, returnsReference, parameters) _corto_delegateUpdate(corto_delegate(_this), corto_type(returnType), returnsReference, parameters)
CORTO_EXPORT corto_delegate _corto_delegateAssign(corto_delegate _this, corto_type returnType, bool returnsReference, corto_parameterseq parameters);
#define corto_delegate__optional_NotSet NULL
#define corto_delegate__optional_Set(returnType, returnsReference, parameters) corto_delegateAssign((corto_delegate*)corto_ptr_new(corto_delegate_o)), returnType, returnsReference, parameters)
#define corto_delegate__optional_SetCond(cond, returnType, returnsReference, parameters) cond ? corto_delegateAssign((corto_delegate*)corto_ptr_new(corto_delegate_o), returnType, returnsReference, parameters) : NULL
#define corto_delegateUnset(_this) _this ? corto_ptr_free(_this, corto_delegate_o), 0 : 0; _this = NULL;
#define corto_delegateAssign(_this, returnType, returnsReference, parameters) _corto_delegateAssign(_this, corto_type(returnType), returnsReference, parameters)
#define corto_delegateSet(_this, returnType, returnsReference, parameters) _this = _this ? _this : (corto_delegate*)corto_ptr_new(corto_delegate_o); _corto_delegateAssign(_this, corto_type(returnType), returnsReference, parameters)

CORTO_EXPORT corto_delegate _corto_delegateDeclare(void);
#define corto_delegateDeclare() _corto_delegateDeclare()
#define corto_delegateDeclare_auto(_id) corto_delegate _id = corto_delegateDeclare(); (void)_id
CORTO_EXPORT corto_delegate _corto_delegateDeclareChild(corto_object _parent, corto_string _id);
#define corto_delegateDeclareChild(_parent, _id) _corto_delegateDeclareChild(_parent, _id)
#define corto_delegateDeclareChild_auto(_parent, _id) corto_delegate _id = corto_delegateDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_delegateDefine(corto_delegate _this, corto_type returnType, bool returnsReference, corto_parameterseq parameters);
#define corto_delegateDefine(_this, returnType, returnsReference, parameters) _corto_delegateDefine(corto_delegate(_this), corto_type(returnType), returnsReference, parameters)

/* delegatedata */
CORTO_EXPORT corto_delegatedata* _corto_delegatedataCreate(corto_object instance, corto_function procedure);
#define corto_delegatedataCreate(instance, procedure) _corto_delegatedataCreate(instance, corto_function(procedure))
#define corto_delegatedataCreate_auto(_id, instance, procedure) corto_delegatedata* _id = corto_delegatedataCreate(instance, procedure); (void)_id
CORTO_EXPORT corto_delegatedata* _corto_delegatedataCreateChild(corto_object _parent, corto_string _id, corto_object instance, corto_function procedure);
#define corto_delegatedataCreateChild(_parent, _id, instance, procedure) _corto_delegatedataCreateChild(_parent, _id, instance, corto_function(procedure))
#define corto_delegatedataCreateChild_auto(_parent, _id, instance, procedure) corto_delegatedata* _id = corto_delegatedataCreateChild(_parent, #_id, instance, procedure); (void)_id
CORTO_EXPORT corto_int16 _corto_delegatedataUpdate(corto_delegatedata* _this, corto_object instance, corto_function procedure);
#define corto_delegatedataUpdate(_this, instance, procedure) _corto_delegatedataUpdate(corto_delegatedata(_this), instance, corto_function(procedure))
CORTO_EXPORT corto_delegatedata* _corto_delegatedataAssign(corto_delegatedata* _this, corto_object instance, corto_function procedure);
#define corto_delegatedata__optional_NotSet NULL
#define corto_delegatedata__optional_Set(instance, procedure) corto_delegatedataAssign((corto_delegatedata*)corto_ptr_new(corto_delegatedata_o)), instance, procedure)
#define corto_delegatedata__optional_SetCond(cond, instance, procedure) cond ? corto_delegatedataAssign((corto_delegatedata*)corto_ptr_new(corto_delegatedata_o), instance, procedure) : NULL
#define corto_delegatedataUnset(_this) _this ? corto_ptr_free(_this, corto_delegatedata_o), 0 : 0; _this = NULL;
#define corto_delegatedataAssign(_this, instance, procedure) _corto_delegatedataAssign(_this, instance, corto_function(procedure))
#define corto_delegatedataSet(_this, instance, procedure) _this = _this ? _this : (corto_delegatedata*)corto_ptr_new(corto_delegatedata_o); _corto_delegatedataAssign(_this, instance, corto_function(procedure))

CORTO_EXPORT corto_delegatedata* _corto_delegatedataDeclare(void);
#define corto_delegatedataDeclare() _corto_delegatedataDeclare()
#define corto_delegatedataDeclare_auto(_id) corto_delegatedata* _id = corto_delegatedataDeclare(); (void)_id
CORTO_EXPORT corto_delegatedata* _corto_delegatedataDeclareChild(corto_object _parent, corto_string _id);
#define corto_delegatedataDeclareChild(_parent, _id) _corto_delegatedataDeclareChild(_parent, _id)
#define corto_delegatedataDeclareChild_auto(_parent, _id) corto_delegatedata* _id = corto_delegatedataDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_delegatedataDefine(corto_delegatedata* _this, corto_object instance, corto_function procedure);
#define corto_delegatedataDefine(_this, instance, procedure) _corto_delegatedataDefine(corto_delegatedata(_this), instance, corto_function(procedure))

/* destructAction */
CORTO_EXPORT corto_destructAction* _corto_destructActionCreate(corto_object instance, corto_function procedure);
#define corto_destructActionCreate(instance, procedure) _corto_destructActionCreate(instance, corto_function(procedure))
#define corto_destructActionCreate_auto(_id, instance, procedure) corto_destructAction* _id = corto_destructActionCreate(instance, procedure); (void)_id
CORTO_EXPORT corto_destructAction* _corto_destructActionCreateChild(corto_object _parent, corto_string _id, corto_object instance, corto_function procedure);
#define corto_destructActionCreateChild(_parent, _id, instance, procedure) _corto_destructActionCreateChild(_parent, _id, instance, corto_function(procedure))
#define corto_destructActionCreateChild_auto(_parent, _id, instance, procedure) corto_destructAction* _id = corto_destructActionCreateChild(_parent, #_id, instance, procedure); (void)_id
CORTO_EXPORT corto_int16 _corto_destructActionUpdate(corto_destructAction* _this, corto_object instance, corto_function procedure);
#define corto_destructActionUpdate(_this, instance, procedure) _corto_destructActionUpdate(corto_destructAction(_this), instance, corto_function(procedure))
CORTO_EXPORT corto_destructAction* _corto_destructActionAssign(corto_destructAction* _this, corto_object instance, corto_function procedure);
#define corto_destructAction__optional_NotSet NULL
#define corto_destructAction__optional_Set(instance, procedure) corto_destructActionAssign((corto_destructAction*)corto_ptr_new(corto_destructAction_o)), instance, procedure)
#define corto_destructAction__optional_SetCond(cond, instance, procedure) cond ? corto_destructActionAssign((corto_destructAction*)corto_ptr_new(corto_destructAction_o), instance, procedure) : NULL
#define corto_destructActionUnset(_this) _this ? corto_ptr_free(_this, corto_destructAction_o), 0 : 0; _this = NULL;
#define corto_destructActionAssign(_this, instance, procedure) _corto_destructActionAssign(_this, instance, corto_function(procedure))
#define corto_destructActionSet(_this, instance, procedure) _this = _this ? _this : (corto_destructAction*)corto_ptr_new(corto_destructAction_o); _corto_destructActionAssign(_this, instance, corto_function(procedure))

CORTO_EXPORT corto_destructAction* _corto_destructActionDeclare(void);
#define corto_destructActionDeclare() _corto_destructActionDeclare()
#define corto_destructActionDeclare_auto(_id) corto_destructAction* _id = corto_destructActionDeclare(); (void)_id
CORTO_EXPORT corto_destructAction* _corto_destructActionDeclareChild(corto_object _parent, corto_string _id);
#define corto_destructActionDeclareChild(_parent, _id) _corto_destructActionDeclareChild(_parent, _id)
#define corto_destructActionDeclareChild_auto(_parent, _id) corto_destructAction* _id = corto_destructActionDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_destructActionDefine(corto_destructAction* _this, corto_object instance, corto_function procedure);
#define corto_destructActionDefine(_this, instance, procedure) _corto_destructActionDefine(corto_destructAction(_this), instance, corto_function(procedure))

corto_int16 corto_destructActionCall(corto_destructAction *_delegate);
#define corto_destructActionInitC_auto(d, callback) corto_destructAction d; corto_destructActionInitC(&d, callback)
CORTO_EXPORT corto_int16 corto_destructActionInitC(corto_destructAction *d, corto_void ___ (*callback)(void));
#define corto_destructActionInitCInstance_auto(d, instance, callback)corto_destructAction d; corto_destructActionInitCInstance(&d, instance, callback)
CORTO_EXPORT corto_int16 corto_destructActionInitCInstance(corto_destructAction *d, corto_object instance, corto_void ___ (*callback)(corto_object));
/* enum */
CORTO_EXPORT corto_enum _corto_enumCreate(void);
#define corto_enumCreate() _corto_enumCreate()
#define corto_enumCreate_auto(_id) corto_enum _id = corto_enumCreate(); (void)_id
CORTO_EXPORT corto_enum _corto_enumCreateChild(corto_object _parent, corto_string _id);
#define corto_enumCreateChild(_parent, _id) _corto_enumCreateChild(_parent, _id)
#define corto_enumCreateChild_auto(_parent, _id) corto_enum _id = corto_enumCreateChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_enumUpdate(corto_enum _this);
#define corto_enumUpdate(_this) _corto_enumUpdate(corto_enum(_this))
CORTO_EXPORT corto_enum _corto_enumAssign(corto_enum _this);
#define corto_enum__optional_NotSet NULL
#define corto_enum__optional_Set() corto_enumAssign((corto_enum*)corto_ptr_new(corto_enum_o)))
#define corto_enum__optional_SetCond(cond) cond ? corto_enumAssign((corto_enum*)corto_ptr_new(corto_enum_o)) : NULL
#define corto_enumUnset(_this) _this ? corto_ptr_free(_this, corto_enum_o), 0 : 0; _this = NULL;
#define corto_enumAssign(_this) _corto_enumAssign(_this)
#define corto_enumSet(_this) _this = _this ? _this : (corto_enum*)corto_ptr_new(corto_enum_o); _corto_enumAssign(_this)

CORTO_EXPORT corto_enum _corto_enumDeclare(void);
#define corto_enumDeclare() _corto_enumDeclare()
#define corto_enumDeclare_auto(_id) corto_enum _id = corto_enumDeclare(); (void)_id
CORTO_EXPORT corto_enum _corto_enumDeclareChild(corto_object _parent, corto_string _id);
#define corto_enumDeclareChild(_parent, _id) _corto_enumDeclareChild(_parent, _id)
#define corto_enumDeclareChild_auto(_parent, _id) corto_enum _id = corto_enumDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_enumDefine(corto_enum _this);
#define corto_enumDefine(_this) _corto_enumDefine(corto_enum(_this))

/* equalityKind */
CORTO_EXPORT corto_equalityKind* _corto_equalityKindCreate(corto_equalityKind value);
#define corto_equalityKindCreate(value) _corto_equalityKindCreate(value)
#define corto_equalityKindCreate_auto(_id, value) corto_equalityKind* _id = corto_equalityKindCreate(value); (void)_id
CORTO_EXPORT corto_equalityKind* _corto_equalityKindCreateChild(corto_object _parent, corto_string _id, corto_equalityKind value);
#define corto_equalityKindCreateChild(_parent, _id, value) _corto_equalityKindCreateChild(_parent, _id, value)
#define corto_equalityKindCreateChild_auto(_parent, _id, value) corto_equalityKind* _id = corto_equalityKindCreateChild(_parent, #_id, value); (void)_id
CORTO_EXPORT corto_int16 _corto_equalityKindUpdate(corto_equalityKind* _this, corto_equalityKind value);
#define corto_equalityKindUpdate(_this, value) _corto_equalityKindUpdate(corto_equalityKind(_this), value)
CORTO_EXPORT corto_equalityKind* _corto_equalityKindAssign(corto_equalityKind* _this, corto_equalityKind value);
#define corto_equalityKind__optional_NotSet NULL
#define corto_equalityKind__optional_Set(value) corto_equalityKindAssign((corto_equalityKind*)corto_ptr_new(corto_equalityKind_o)), value)
#define corto_equalityKind__optional_SetCond(cond, value) cond ? corto_equalityKindAssign((corto_equalityKind*)corto_ptr_new(corto_equalityKind_o), value) : NULL
#define corto_equalityKindUnset(_this) _this ? corto_ptr_free(_this, corto_equalityKind_o), 0 : 0; _this = NULL;
#define corto_equalityKindAssign(_this, value) _corto_equalityKindAssign(_this, value)
#define corto_equalityKindSet(_this, value) _this = _this ? _this : (corto_equalityKind*)corto_ptr_new(corto_equalityKind_o); _corto_equalityKindAssign(_this, value)

CORTO_EXPORT corto_equalityKind* _corto_equalityKindDeclare(void);
#define corto_equalityKindDeclare() _corto_equalityKindDeclare()
#define corto_equalityKindDeclare_auto(_id) corto_equalityKind* _id = corto_equalityKindDeclare(); (void)_id
CORTO_EXPORT corto_equalityKind* _corto_equalityKindDeclareChild(corto_object _parent, corto_string _id);
#define corto_equalityKindDeclareChild(_parent, _id) _corto_equalityKindDeclareChild(_parent, _id)
#define corto_equalityKindDeclareChild_auto(_parent, _id) corto_equalityKind* _id = corto_equalityKindDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_equalityKindDefine(corto_equalityKind* _this, corto_equalityKind value);
#define corto_equalityKindDefine(_this, value) _corto_equalityKindDefine(corto_equalityKind(_this), value)

/* float */
CORTO_EXPORT corto_float _corto_floatCreate(corto_width width, double min, double max);
#define corto_floatCreate(width, min, max) _corto_floatCreate(width, min, max)
#define corto_floatCreate_auto(_id, width, min, max) corto_float _id = corto_floatCreate(width, min, max); (void)_id
CORTO_EXPORT corto_float _corto_floatCreateChild(corto_object _parent, corto_string _id, corto_width width, double min, double max);
#define corto_floatCreateChild(_parent, _id, width, min, max) _corto_floatCreateChild(_parent, _id, width, min, max)
#define corto_floatCreateChild_auto(_parent, _id, width, min, max) corto_float _id = corto_floatCreateChild(_parent, #_id, width, min, max); (void)_id
CORTO_EXPORT corto_int16 _corto_floatUpdate(corto_float _this, corto_width width, double min, double max);
#define corto_floatUpdate(_this, width, min, max) _corto_floatUpdate(corto_float(_this), width, min, max)
CORTO_EXPORT corto_float _corto_floatAssign(corto_float _this, corto_width width, double min, double max);
#define corto_float__optional_NotSet NULL
#define corto_float__optional_Set(width, min, max) corto_floatAssign((corto_float*)corto_ptr_new(corto_float_o)), width, min, max)
#define corto_float__optional_SetCond(cond, width, min, max) cond ? corto_floatAssign((corto_float*)corto_ptr_new(corto_float_o), width, min, max) : NULL
#define corto_floatUnset(_this) _this ? corto_ptr_free(_this, corto_float_o), 0 : 0; _this = NULL;
#define corto_floatAssign(_this, width, min, max) _corto_floatAssign(_this, width, min, max)
#define corto_floatSet(_this, width, min, max) _this = _this ? _this : (corto_float*)corto_ptr_new(corto_float_o); _corto_floatAssign(_this, width, min, max)

CORTO_EXPORT corto_float _corto_floatDeclare(void);
#define corto_floatDeclare() _corto_floatDeclare()
#define corto_floatDeclare_auto(_id) corto_float _id = corto_floatDeclare(); (void)_id
CORTO_EXPORT corto_float _corto_floatDeclareChild(corto_object _parent, corto_string _id);
#define corto_floatDeclareChild(_parent, _id) _corto_floatDeclareChild(_parent, _id)
#define corto_floatDeclareChild_auto(_parent, _id) corto_float _id = corto_floatDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_floatDefine(corto_float _this, corto_width width, double min, double max);
#define corto_floatDefine(_this, width, min, max) _corto_floatDefine(corto_float(_this), width, min, max)

/* float32 */
CORTO_EXPORT float* _corto_float32Create(float value);
#define corto_float32Create(value) _corto_float32Create(value)
#define corto_float32Create_auto(_id, value) float* _id = corto_float32Create(value); (void)_id
CORTO_EXPORT float* _corto_float32CreateChild(corto_object _parent, corto_string _id, float value);
#define corto_float32CreateChild(_parent, _id, value) _corto_float32CreateChild(_parent, _id, value)
#define corto_float32CreateChild_auto(_parent, _id, value) float* _id = corto_float32CreateChild(_parent, #_id, value); (void)_id
CORTO_EXPORT corto_int16 _corto_float32Update(float* _this, float value);
#define corto_float32Update(_this, value) _corto_float32Update(corto_float32(_this), value)
CORTO_EXPORT float* _corto_float32Assign(float* _this, float value);
#define corto_float32__optional_NotSet NULL
#define corto_float32__optional_Set(value) corto_float32Assign((corto_float32*)corto_ptr_new(corto_float32_o)), value)
#define corto_float32__optional_SetCond(cond, value) cond ? corto_float32Assign((corto_float32*)corto_ptr_new(corto_float32_o), value) : NULL
#define corto_float32Unset(_this) _this ? corto_ptr_free(_this, corto_float32_o), 0 : 0; _this = NULL;
#define corto_float32Assign(_this, value) _corto_float32Assign(_this, value)
#define corto_float32Set(_this, value) _this = _this ? _this : (corto_float32*)corto_ptr_new(corto_float32_o); _corto_float32Assign(_this, value)

CORTO_EXPORT float* _corto_float32Declare(void);
#define corto_float32Declare() _corto_float32Declare()
#define corto_float32Declare_auto(_id) float* _id = corto_float32Declare(); (void)_id
CORTO_EXPORT float* _corto_float32DeclareChild(corto_object _parent, corto_string _id);
#define corto_float32DeclareChild(_parent, _id) _corto_float32DeclareChild(_parent, _id)
#define corto_float32DeclareChild_auto(_parent, _id) float* _id = corto_float32DeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_float32Define(float* _this, float value);
#define corto_float32Define(_this, value) _corto_float32Define(corto_float32(_this), value)

/* float64 */
CORTO_EXPORT double* _corto_float64Create(double value);
#define corto_float64Create(value) _corto_float64Create(value)
#define corto_float64Create_auto(_id, value) double* _id = corto_float64Create(value); (void)_id
CORTO_EXPORT double* _corto_float64CreateChild(corto_object _parent, corto_string _id, double value);
#define corto_float64CreateChild(_parent, _id, value) _corto_float64CreateChild(_parent, _id, value)
#define corto_float64CreateChild_auto(_parent, _id, value) double* _id = corto_float64CreateChild(_parent, #_id, value); (void)_id
CORTO_EXPORT corto_int16 _corto_float64Update(double* _this, double value);
#define corto_float64Update(_this, value) _corto_float64Update(corto_float64(_this), value)
CORTO_EXPORT double* _corto_float64Assign(double* _this, double value);
#define corto_float64__optional_NotSet NULL
#define corto_float64__optional_Set(value) corto_float64Assign((corto_float64*)corto_ptr_new(corto_float64_o)), value)
#define corto_float64__optional_SetCond(cond, value) cond ? corto_float64Assign((corto_float64*)corto_ptr_new(corto_float64_o), value) : NULL
#define corto_float64Unset(_this) _this ? corto_ptr_free(_this, corto_float64_o), 0 : 0; _this = NULL;
#define corto_float64Assign(_this, value) _corto_float64Assign(_this, value)
#define corto_float64Set(_this, value) _this = _this ? _this : (corto_float64*)corto_ptr_new(corto_float64_o); _corto_float64Assign(_this, value)

CORTO_EXPORT double* _corto_float64Declare(void);
#define corto_float64Declare() _corto_float64Declare()
#define corto_float64Declare_auto(_id) double* _id = corto_float64Declare(); (void)_id
CORTO_EXPORT double* _corto_float64DeclareChild(corto_object _parent, corto_string _id);
#define corto_float64DeclareChild(_parent, _id) _corto_float64DeclareChild(_parent, _id)
#define corto_float64DeclareChild_auto(_parent, _id) double* _id = corto_float64DeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_float64Define(double* _this, double value);
#define corto_float64Define(_this, value) _corto_float64Define(corto_float64(_this), value)

/* function */
CORTO_EXPORT corto_function _corto_functionCreate(corto_type returnType, bool returnsReference, void(*_impl)(void));
#define corto_functionCreate(returnType, returnsReference, _impl) _corto_functionCreate(corto_type(returnType), returnsReference, (void(*)(void))_impl)
#define corto_functionCreate_auto(_id, returnType, returnsReference, _impl) corto_function _id = corto_functionCreate(returnType, returnsReference, _impl); (void)_id
CORTO_EXPORT corto_function _corto_functionCreateChild(corto_object _parent, corto_string _id, corto_type returnType, bool returnsReference, void(*_impl)(void));
#define corto_functionCreateChild(_parent, _id, returnType, returnsReference, _impl) _corto_functionCreateChild(_parent, _id, corto_type(returnType), returnsReference, (void(*)(void))_impl)
#define corto_functionCreateChild_auto(_parent, _id, returnType, returnsReference, _impl) corto_function _id = corto_functionCreateChild(_parent, #_id, returnType, returnsReference, _impl); (void)_id
CORTO_EXPORT corto_int16 _corto_functionUpdate(corto_function _this, corto_type returnType, bool returnsReference, void(*_impl)(void));
#define corto_functionUpdate(_this, returnType, returnsReference, _impl) _corto_functionUpdate(corto_function(_this), corto_type(returnType), returnsReference, (void(*)(void))_impl)
CORTO_EXPORT corto_function _corto_functionAssign(corto_function _this, corto_type returnType, bool returnsReference, void(*_impl)(void));
#define corto_function__optional_NotSet NULL
#define corto_function__optional_Set(returnType, returnsReference, _impl) corto_functionAssign((corto_function*)corto_ptr_new(corto_function_o)), returnType, returnsReference, _impl)
#define corto_function__optional_SetCond(cond, returnType, returnsReference, _impl) cond ? corto_functionAssign((corto_function*)corto_ptr_new(corto_function_o), returnType, returnsReference, _impl) : NULL
#define corto_functionUnset(_this) _this ? corto_ptr_free(_this, corto_function_o), 0 : 0; _this = NULL;
#define corto_functionAssign(_this, returnType, returnsReference, _impl) _corto_functionAssign(_this, corto_type(returnType), returnsReference, (void(*)(void))_impl)
#define corto_functionSet(_this, returnType, returnsReference, _impl) _this = _this ? _this : (corto_function*)corto_ptr_new(corto_function_o); _corto_functionAssign(_this, corto_type(returnType), returnsReference, (void(*)(void))_impl)

CORTO_EXPORT corto_function _corto_functionDeclare(void);
#define corto_functionDeclare() _corto_functionDeclare()
#define corto_functionDeclare_auto(_id) corto_function _id = corto_functionDeclare(); (void)_id
CORTO_EXPORT corto_function _corto_functionDeclareChild(corto_object _parent, corto_string _id);
#define corto_functionDeclareChild(_parent, _id) _corto_functionDeclareChild(_parent, _id)
#define corto_functionDeclareChild_auto(_parent, _id) corto_function _id = corto_functionDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_functionDefine(corto_function _this, corto_type returnType, bool returnsReference, void(*_impl)(void));
#define corto_functionDefine(_this, returnType, returnsReference, _impl) _corto_functionDefine(corto_function(_this), corto_type(returnType), returnsReference, (void(*)(void))_impl)

/* initAction */
CORTO_EXPORT corto_initAction* _corto_initActionCreate(corto_object instance, corto_function procedure);
#define corto_initActionCreate(instance, procedure) _corto_initActionCreate(instance, corto_function(procedure))
#define corto_initActionCreate_auto(_id, instance, procedure) corto_initAction* _id = corto_initActionCreate(instance, procedure); (void)_id
CORTO_EXPORT corto_initAction* _corto_initActionCreateChild(corto_object _parent, corto_string _id, corto_object instance, corto_function procedure);
#define corto_initActionCreateChild(_parent, _id, instance, procedure) _corto_initActionCreateChild(_parent, _id, instance, corto_function(procedure))
#define corto_initActionCreateChild_auto(_parent, _id, instance, procedure) corto_initAction* _id = corto_initActionCreateChild(_parent, #_id, instance, procedure); (void)_id
CORTO_EXPORT corto_int16 _corto_initActionUpdate(corto_initAction* _this, corto_object instance, corto_function procedure);
#define corto_initActionUpdate(_this, instance, procedure) _corto_initActionUpdate(corto_initAction(_this), instance, corto_function(procedure))
CORTO_EXPORT corto_initAction* _corto_initActionAssign(corto_initAction* _this, corto_object instance, corto_function procedure);
#define corto_initAction__optional_NotSet NULL
#define corto_initAction__optional_Set(instance, procedure) corto_initActionAssign((corto_initAction*)corto_ptr_new(corto_initAction_o)), instance, procedure)
#define corto_initAction__optional_SetCond(cond, instance, procedure) cond ? corto_initActionAssign((corto_initAction*)corto_ptr_new(corto_initAction_o), instance, procedure) : NULL
#define corto_initActionUnset(_this) _this ? corto_ptr_free(_this, corto_initAction_o), 0 : 0; _this = NULL;
#define corto_initActionAssign(_this, instance, procedure) _corto_initActionAssign(_this, instance, corto_function(procedure))
#define corto_initActionSet(_this, instance, procedure) _this = _this ? _this : (corto_initAction*)corto_ptr_new(corto_initAction_o); _corto_initActionAssign(_this, instance, corto_function(procedure))

CORTO_EXPORT corto_initAction* _corto_initActionDeclare(void);
#define corto_initActionDeclare() _corto_initActionDeclare()
#define corto_initActionDeclare_auto(_id) corto_initAction* _id = corto_initActionDeclare(); (void)_id
CORTO_EXPORT corto_initAction* _corto_initActionDeclareChild(corto_object _parent, corto_string _id);
#define corto_initActionDeclareChild(_parent, _id) _corto_initActionDeclareChild(_parent, _id)
#define corto_initActionDeclareChild_auto(_parent, _id) corto_initAction* _id = corto_initActionDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_initActionDefine(corto_initAction* _this, corto_object instance, corto_function procedure);
#define corto_initActionDefine(_this, instance, procedure) _corto_initActionDefine(corto_initAction(_this), instance, corto_function(procedure))

corto_int16 corto_initActionCall(corto_initAction *_delegate, corto_int16* _result);
#define corto_initActionInitC_auto(d, callback) corto_initAction d; corto_initActionInitC(&d, callback)
CORTO_EXPORT corto_int16 corto_initActionInitC(corto_initAction *d, corto_int16 ___ (*callback)(void));
#define corto_initActionInitCInstance_auto(d, instance, callback)corto_initAction d; corto_initActionInitCInstance(&d, instance, callback)
CORTO_EXPORT corto_int16 corto_initActionInitCInstance(corto_initAction *d, corto_object instance, corto_int16 ___ (*callback)(corto_object));
/* inout */
CORTO_EXPORT corto_inout* _corto_inoutCreate(corto_inout value);
#define corto_inoutCreate(value) _corto_inoutCreate(value)
#define corto_inoutCreate_auto(_id, value) corto_inout* _id = corto_inoutCreate(value); (void)_id
CORTO_EXPORT corto_inout* _corto_inoutCreateChild(corto_object _parent, corto_string _id, corto_inout value);
#define corto_inoutCreateChild(_parent, _id, value) _corto_inoutCreateChild(_parent, _id, value)
#define corto_inoutCreateChild_auto(_parent, _id, value) corto_inout* _id = corto_inoutCreateChild(_parent, #_id, value); (void)_id
CORTO_EXPORT corto_int16 _corto_inoutUpdate(corto_inout* _this, corto_inout value);
#define corto_inoutUpdate(_this, value) _corto_inoutUpdate(corto_inout(_this), value)
CORTO_EXPORT corto_inout* _corto_inoutAssign(corto_inout* _this, corto_inout value);
#define corto_inout__optional_NotSet NULL
#define corto_inout__optional_Set(value) corto_inoutAssign((corto_inout*)corto_ptr_new(corto_inout_o)), value)
#define corto_inout__optional_SetCond(cond, value) cond ? corto_inoutAssign((corto_inout*)corto_ptr_new(corto_inout_o), value) : NULL
#define corto_inoutUnset(_this) _this ? corto_ptr_free(_this, corto_inout_o), 0 : 0; _this = NULL;
#define corto_inoutAssign(_this, value) _corto_inoutAssign(_this, value)
#define corto_inoutSet(_this, value) _this = _this ? _this : (corto_inout*)corto_ptr_new(corto_inout_o); _corto_inoutAssign(_this, value)

CORTO_EXPORT corto_inout* _corto_inoutDeclare(void);
#define corto_inoutDeclare() _corto_inoutDeclare()
#define corto_inoutDeclare_auto(_id) corto_inout* _id = corto_inoutDeclare(); (void)_id
CORTO_EXPORT corto_inout* _corto_inoutDeclareChild(corto_object _parent, corto_string _id);
#define corto_inoutDeclareChild(_parent, _id) _corto_inoutDeclareChild(_parent, _id)
#define corto_inoutDeclareChild_auto(_parent, _id) corto_inout* _id = corto_inoutDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_inoutDefine(corto_inout* _this, corto_inout value);
#define corto_inoutDefine(_this, value) _corto_inoutDefine(corto_inout(_this), value)

/* int */
CORTO_EXPORT corto_int _corto_intCreate(corto_width width, int64_t min, int64_t max);
#define corto_intCreate(width, min, max) _corto_intCreate(width, min, max)
#define corto_intCreate_auto(_id, width, min, max) corto_int _id = corto_intCreate(width, min, max); (void)_id
CORTO_EXPORT corto_int _corto_intCreateChild(corto_object _parent, corto_string _id, corto_width width, int64_t min, int64_t max);
#define corto_intCreateChild(_parent, _id, width, min, max) _corto_intCreateChild(_parent, _id, width, min, max)
#define corto_intCreateChild_auto(_parent, _id, width, min, max) corto_int _id = corto_intCreateChild(_parent, #_id, width, min, max); (void)_id
CORTO_EXPORT corto_int16 _corto_intUpdate(corto_int _this, corto_width width, int64_t min, int64_t max);
#define corto_intUpdate(_this, width, min, max) _corto_intUpdate(corto_int(_this), width, min, max)
CORTO_EXPORT corto_int _corto_intAssign(corto_int _this, corto_width width, int64_t min, int64_t max);
#define corto_int__optional_NotSet NULL
#define corto_int__optional_Set(width, min, max) corto_intAssign((corto_int*)corto_ptr_new(corto_int_o)), width, min, max)
#define corto_int__optional_SetCond(cond, width, min, max) cond ? corto_intAssign((corto_int*)corto_ptr_new(corto_int_o), width, min, max) : NULL
#define corto_intUnset(_this) _this ? corto_ptr_free(_this, corto_int_o), 0 : 0; _this = NULL;
#define corto_intAssign(_this, width, min, max) _corto_intAssign(_this, width, min, max)
#define corto_intSet(_this, width, min, max) _this = _this ? _this : (corto_int*)corto_ptr_new(corto_int_o); _corto_intAssign(_this, width, min, max)

CORTO_EXPORT corto_int _corto_intDeclare(void);
#define corto_intDeclare() _corto_intDeclare()
#define corto_intDeclare_auto(_id) corto_int _id = corto_intDeclare(); (void)_id
CORTO_EXPORT corto_int _corto_intDeclareChild(corto_object _parent, corto_string _id);
#define corto_intDeclareChild(_parent, _id) _corto_intDeclareChild(_parent, _id)
#define corto_intDeclareChild_auto(_parent, _id) corto_int _id = corto_intDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_intDefine(corto_int _this, corto_width width, int64_t min, int64_t max);
#define corto_intDefine(_this, width, min, max) _corto_intDefine(corto_int(_this), width, min, max)

/* int16 */
CORTO_EXPORT int16_t* _corto_int16Create(int16_t value);
#define corto_int16Create(value) _corto_int16Create(value)
#define corto_int16Create_auto(_id, value) int16_t* _id = corto_int16Create(value); (void)_id
CORTO_EXPORT int16_t* _corto_int16CreateChild(corto_object _parent, corto_string _id, int16_t value);
#define corto_int16CreateChild(_parent, _id, value) _corto_int16CreateChild(_parent, _id, value)
#define corto_int16CreateChild_auto(_parent, _id, value) int16_t* _id = corto_int16CreateChild(_parent, #_id, value); (void)_id
CORTO_EXPORT corto_int16 _corto_int16Update(int16_t* _this, int16_t value);
#define corto_int16Update(_this, value) _corto_int16Update(corto_int16(_this), value)
CORTO_EXPORT int16_t* _corto_int16Assign(int16_t* _this, int16_t value);
#define corto_int16__optional_NotSet NULL
#define corto_int16__optional_Set(value) corto_int16Assign((corto_int16*)corto_ptr_new(corto_int16_o)), value)
#define corto_int16__optional_SetCond(cond, value) cond ? corto_int16Assign((corto_int16*)corto_ptr_new(corto_int16_o), value) : NULL
#define corto_int16Unset(_this) _this ? corto_ptr_free(_this, corto_int16_o), 0 : 0; _this = NULL;
#define corto_int16Assign(_this, value) _corto_int16Assign(_this, value)
#define corto_int16Set(_this, value) _this = _this ? _this : (corto_int16*)corto_ptr_new(corto_int16_o); _corto_int16Assign(_this, value)

CORTO_EXPORT int16_t* _corto_int16Declare(void);
#define corto_int16Declare() _corto_int16Declare()
#define corto_int16Declare_auto(_id) int16_t* _id = corto_int16Declare(); (void)_id
CORTO_EXPORT int16_t* _corto_int16DeclareChild(corto_object _parent, corto_string _id);
#define corto_int16DeclareChild(_parent, _id) _corto_int16DeclareChild(_parent, _id)
#define corto_int16DeclareChild_auto(_parent, _id) int16_t* _id = corto_int16DeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_int16Define(int16_t* _this, int16_t value);
#define corto_int16Define(_this, value) _corto_int16Define(corto_int16(_this), value)

/* int32 */
CORTO_EXPORT int32_t* _corto_int32Create(int32_t value);
#define corto_int32Create(value) _corto_int32Create(value)
#define corto_int32Create_auto(_id, value) int32_t* _id = corto_int32Create(value); (void)_id
CORTO_EXPORT int32_t* _corto_int32CreateChild(corto_object _parent, corto_string _id, int32_t value);
#define corto_int32CreateChild(_parent, _id, value) _corto_int32CreateChild(_parent, _id, value)
#define corto_int32CreateChild_auto(_parent, _id, value) int32_t* _id = corto_int32CreateChild(_parent, #_id, value); (void)_id
CORTO_EXPORT corto_int16 _corto_int32Update(int32_t* _this, int32_t value);
#define corto_int32Update(_this, value) _corto_int32Update(corto_int32(_this), value)
CORTO_EXPORT int32_t* _corto_int32Assign(int32_t* _this, int32_t value);
#define corto_int32__optional_NotSet NULL
#define corto_int32__optional_Set(value) corto_int32Assign((corto_int32*)corto_ptr_new(corto_int32_o)), value)
#define corto_int32__optional_SetCond(cond, value) cond ? corto_int32Assign((corto_int32*)corto_ptr_new(corto_int32_o), value) : NULL
#define corto_int32Unset(_this) _this ? corto_ptr_free(_this, corto_int32_o), 0 : 0; _this = NULL;
#define corto_int32Assign(_this, value) _corto_int32Assign(_this, value)
#define corto_int32Set(_this, value) _this = _this ? _this : (corto_int32*)corto_ptr_new(corto_int32_o); _corto_int32Assign(_this, value)

CORTO_EXPORT int32_t* _corto_int32Declare(void);
#define corto_int32Declare() _corto_int32Declare()
#define corto_int32Declare_auto(_id) int32_t* _id = corto_int32Declare(); (void)_id
CORTO_EXPORT int32_t* _corto_int32DeclareChild(corto_object _parent, corto_string _id);
#define corto_int32DeclareChild(_parent, _id) _corto_int32DeclareChild(_parent, _id)
#define corto_int32DeclareChild_auto(_parent, _id) int32_t* _id = corto_int32DeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_int32Define(int32_t* _this, int32_t value);
#define corto_int32Define(_this, value) _corto_int32Define(corto_int32(_this), value)

/* int32seq */
CORTO_EXPORT corto_int32seq* _corto_int32seqCreate(corto_uint32 length, corto_int32* elements);
#define corto_int32seqCreate(length, elements) _corto_int32seqCreate(length, elements)
#define corto_int32seqCreate_auto(_id, length, elements) corto_int32seq* _id = corto_int32seqCreate(length, elements); (void)_id
CORTO_EXPORT corto_int32seq* _corto_int32seqCreateChild(corto_object _parent, corto_string _id, corto_uint32 length, corto_int32* elements);
#define corto_int32seqCreateChild(_parent, _id, length, elements) _corto_int32seqCreateChild(_parent, _id, length, elements)
#define corto_int32seqCreateChild_auto(_parent, _id, length, elements) corto_int32seq* _id = corto_int32seqCreateChild(_parent, #_id, length, elements); (void)_id
CORTO_EXPORT corto_int16 _corto_int32seqUpdate(corto_int32seq* _this, corto_uint32 length, corto_int32* elements);
#define corto_int32seqUpdate(_this, length, elements) _corto_int32seqUpdate(corto_int32seq(_this), length, elements)
CORTO_EXPORT corto_int32seq* _corto_int32seqAssign(corto_int32seq* _this, corto_uint32 length, corto_int32* elements);
#define corto_int32seq__optional_NotSet NULL
#define corto_int32seq__optional_Set(length, elements) corto_int32seqAssign((corto_int32seq*)corto_ptr_new(corto_int32seq_o)), length, elements)
#define corto_int32seq__optional_SetCond(cond, length, elements) cond ? corto_int32seqAssign((corto_int32seq*)corto_ptr_new(corto_int32seq_o), length, elements) : NULL
#define corto_int32seqUnset(_this) _this ? corto_ptr_free(_this, corto_int32seq_o), 0 : 0; _this = NULL;
#define corto_int32seqAssign(_this, length, elements) _corto_int32seqAssign(_this, length, elements)
#define corto_int32seqSet(_this, length, elements) _this = _this ? _this : (corto_int32seq*)corto_ptr_new(corto_int32seq_o); _corto_int32seqAssign(_this, length, elements)

CORTO_EXPORT corto_int32seq* _corto_int32seqDeclare(void);
#define corto_int32seqDeclare() _corto_int32seqDeclare()
#define corto_int32seqDeclare_auto(_id) corto_int32seq* _id = corto_int32seqDeclare(); (void)_id
CORTO_EXPORT corto_int32seq* _corto_int32seqDeclareChild(corto_object _parent, corto_string _id);
#define corto_int32seqDeclareChild(_parent, _id) _corto_int32seqDeclareChild(_parent, _id)
#define corto_int32seqDeclareChild_auto(_parent, _id) corto_int32seq* _id = corto_int32seqDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_int32seqDefine(corto_int32seq* _this, corto_uint32 length, corto_int32* elements);
#define corto_int32seqDefine(_this, length, elements) _corto_int32seqDefine(corto_int32seq(_this), length, elements)

/* int64 */
CORTO_EXPORT int64_t* _corto_int64Create(int64_t value);
#define corto_int64Create(value) _corto_int64Create(value)
#define corto_int64Create_auto(_id, value) int64_t* _id = corto_int64Create(value); (void)_id
CORTO_EXPORT int64_t* _corto_int64CreateChild(corto_object _parent, corto_string _id, int64_t value);
#define corto_int64CreateChild(_parent, _id, value) _corto_int64CreateChild(_parent, _id, value)
#define corto_int64CreateChild_auto(_parent, _id, value) int64_t* _id = corto_int64CreateChild(_parent, #_id, value); (void)_id
CORTO_EXPORT corto_int16 _corto_int64Update(int64_t* _this, int64_t value);
#define corto_int64Update(_this, value) _corto_int64Update(corto_int64(_this), value)
CORTO_EXPORT int64_t* _corto_int64Assign(int64_t* _this, int64_t value);
#define corto_int64__optional_NotSet NULL
#define corto_int64__optional_Set(value) corto_int64Assign((corto_int64*)corto_ptr_new(corto_int64_o)), value)
#define corto_int64__optional_SetCond(cond, value) cond ? corto_int64Assign((corto_int64*)corto_ptr_new(corto_int64_o), value) : NULL
#define corto_int64Unset(_this) _this ? corto_ptr_free(_this, corto_int64_o), 0 : 0; _this = NULL;
#define corto_int64Assign(_this, value) _corto_int64Assign(_this, value)
#define corto_int64Set(_this, value) _this = _this ? _this : (corto_int64*)corto_ptr_new(corto_int64_o); _corto_int64Assign(_this, value)

CORTO_EXPORT int64_t* _corto_int64Declare(void);
#define corto_int64Declare() _corto_int64Declare()
#define corto_int64Declare_auto(_id) int64_t* _id = corto_int64Declare(); (void)_id
CORTO_EXPORT int64_t* _corto_int64DeclareChild(corto_object _parent, corto_string _id);
#define corto_int64DeclareChild(_parent, _id) _corto_int64DeclareChild(_parent, _id)
#define corto_int64DeclareChild_auto(_parent, _id) int64_t* _id = corto_int64DeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_int64Define(int64_t* _this, int64_t value);
#define corto_int64Define(_this, value) _corto_int64Define(corto_int64(_this), value)

/* int8 */
CORTO_EXPORT int8_t* _corto_int8Create(int8_t value);
#define corto_int8Create(value) _corto_int8Create(value)
#define corto_int8Create_auto(_id, value) int8_t* _id = corto_int8Create(value); (void)_id
CORTO_EXPORT int8_t* _corto_int8CreateChild(corto_object _parent, corto_string _id, int8_t value);
#define corto_int8CreateChild(_parent, _id, value) _corto_int8CreateChild(_parent, _id, value)
#define corto_int8CreateChild_auto(_parent, _id, value) int8_t* _id = corto_int8CreateChild(_parent, #_id, value); (void)_id
CORTO_EXPORT corto_int16 _corto_int8Update(int8_t* _this, int8_t value);
#define corto_int8Update(_this, value) _corto_int8Update(corto_int8(_this), value)
CORTO_EXPORT int8_t* _corto_int8Assign(int8_t* _this, int8_t value);
#define corto_int8__optional_NotSet NULL
#define corto_int8__optional_Set(value) corto_int8Assign((corto_int8*)corto_ptr_new(corto_int8_o)), value)
#define corto_int8__optional_SetCond(cond, value) cond ? corto_int8Assign((corto_int8*)corto_ptr_new(corto_int8_o), value) : NULL
#define corto_int8Unset(_this) _this ? corto_ptr_free(_this, corto_int8_o), 0 : 0; _this = NULL;
#define corto_int8Assign(_this, value) _corto_int8Assign(_this, value)
#define corto_int8Set(_this, value) _this = _this ? _this : (corto_int8*)corto_ptr_new(corto_int8_o); _corto_int8Assign(_this, value)

CORTO_EXPORT int8_t* _corto_int8Declare(void);
#define corto_int8Declare() _corto_int8Declare()
#define corto_int8Declare_auto(_id) int8_t* _id = corto_int8Declare(); (void)_id
CORTO_EXPORT int8_t* _corto_int8DeclareChild(corto_object _parent, corto_string _id);
#define corto_int8DeclareChild(_parent, _id) _corto_int8DeclareChild(_parent, _id)
#define corto_int8DeclareChild_auto(_parent, _id) int8_t* _id = corto_int8DeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_int8Define(int8_t* _this, int8_t value);
#define corto_int8Define(_this, value) _corto_int8Define(corto_int8(_this), value)

/* interface */
CORTO_EXPORT corto_interface _corto_interfaceCreate(corto_interface base);
#define corto_interfaceCreate(base) _corto_interfaceCreate(corto_interface(base))
#define corto_interfaceCreate_auto(_id, base) corto_interface _id = corto_interfaceCreate(base); (void)_id
CORTO_EXPORT corto_interface _corto_interfaceCreateChild(corto_object _parent, corto_string _id, corto_interface base);
#define corto_interfaceCreateChild(_parent, _id, base) _corto_interfaceCreateChild(_parent, _id, corto_interface(base))
#define corto_interfaceCreateChild_auto(_parent, _id, base) corto_interface _id = corto_interfaceCreateChild(_parent, #_id, base); (void)_id
CORTO_EXPORT corto_int16 _corto_interfaceUpdate(corto_interface _this, corto_interface base);
#define corto_interfaceUpdate(_this, base) _corto_interfaceUpdate(corto_interface(_this), corto_interface(base))
CORTO_EXPORT corto_interface _corto_interfaceAssign(corto_interface _this, corto_interface base);
#define corto_interface__optional_NotSet NULL
#define corto_interface__optional_Set(base) corto_interfaceAssign((corto_interface*)corto_ptr_new(corto_interface_o)), base)
#define corto_interface__optional_SetCond(cond, base) cond ? corto_interfaceAssign((corto_interface*)corto_ptr_new(corto_interface_o), base) : NULL
#define corto_interfaceUnset(_this) _this ? corto_ptr_free(_this, corto_interface_o), 0 : 0; _this = NULL;
#define corto_interfaceAssign(_this, base) _corto_interfaceAssign(_this, corto_interface(base))
#define corto_interfaceSet(_this, base) _this = _this ? _this : (corto_interface*)corto_ptr_new(corto_interface_o); _corto_interfaceAssign(_this, corto_interface(base))

CORTO_EXPORT corto_interface _corto_interfaceDeclare(void);
#define corto_interfaceDeclare() _corto_interfaceDeclare()
#define corto_interfaceDeclare_auto(_id) corto_interface _id = corto_interfaceDeclare(); (void)_id
CORTO_EXPORT corto_interface _corto_interfaceDeclareChild(corto_object _parent, corto_string _id);
#define corto_interfaceDeclareChild(_parent, _id) _corto_interfaceDeclareChild(_parent, _id)
#define corto_interfaceDeclareChild_auto(_parent, _id) corto_interface _id = corto_interfaceDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_interfaceDefine(corto_interface _this, corto_interface base);
#define corto_interfaceDefine(_this, base) _corto_interfaceDefine(corto_interface(_this), corto_interface(base))

/* interfaceseq */
CORTO_EXPORT corto_interfaceseq* _corto_interfaceseqCreate(corto_uint32 length, corto_interface* elements);
#define corto_interfaceseqCreate(length, elements) _corto_interfaceseqCreate(length, elements)
#define corto_interfaceseqCreate_auto(_id, length, elements) corto_interfaceseq* _id = corto_interfaceseqCreate(length, elements); (void)_id
CORTO_EXPORT corto_interfaceseq* _corto_interfaceseqCreateChild(corto_object _parent, corto_string _id, corto_uint32 length, corto_interface* elements);
#define corto_interfaceseqCreateChild(_parent, _id, length, elements) _corto_interfaceseqCreateChild(_parent, _id, length, elements)
#define corto_interfaceseqCreateChild_auto(_parent, _id, length, elements) corto_interfaceseq* _id = corto_interfaceseqCreateChild(_parent, #_id, length, elements); (void)_id
CORTO_EXPORT corto_int16 _corto_interfaceseqUpdate(corto_interfaceseq* _this, corto_uint32 length, corto_interface* elements);
#define corto_interfaceseqUpdate(_this, length, elements) _corto_interfaceseqUpdate(corto_interfaceseq(_this), length, elements)
CORTO_EXPORT corto_interfaceseq* _corto_interfaceseqAssign(corto_interfaceseq* _this, corto_uint32 length, corto_interface* elements);
#define corto_interfaceseq__optional_NotSet NULL
#define corto_interfaceseq__optional_Set(length, elements) corto_interfaceseqAssign((corto_interfaceseq*)corto_ptr_new(corto_interfaceseq_o)), length, elements)
#define corto_interfaceseq__optional_SetCond(cond, length, elements) cond ? corto_interfaceseqAssign((corto_interfaceseq*)corto_ptr_new(corto_interfaceseq_o), length, elements) : NULL
#define corto_interfaceseqUnset(_this) _this ? corto_ptr_free(_this, corto_interfaceseq_o), 0 : 0; _this = NULL;
#define corto_interfaceseqAssign(_this, length, elements) _corto_interfaceseqAssign(_this, length, elements)
#define corto_interfaceseqSet(_this, length, elements) _this = _this ? _this : (corto_interfaceseq*)corto_ptr_new(corto_interfaceseq_o); _corto_interfaceseqAssign(_this, length, elements)

CORTO_EXPORT corto_interfaceseq* _corto_interfaceseqDeclare(void);
#define corto_interfaceseqDeclare() _corto_interfaceseqDeclare()
#define corto_interfaceseqDeclare_auto(_id) corto_interfaceseq* _id = corto_interfaceseqDeclare(); (void)_id
CORTO_EXPORT corto_interfaceseq* _corto_interfaceseqDeclareChild(corto_object _parent, corto_string _id);
#define corto_interfaceseqDeclareChild(_parent, _id) _corto_interfaceseqDeclareChild(_parent, _id)
#define corto_interfaceseqDeclareChild_auto(_parent, _id) corto_interfaceseq* _id = corto_interfaceseqDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_interfaceseqDefine(corto_interfaceseq* _this, corto_uint32 length, corto_interface* elements);
#define corto_interfaceseqDefine(_this, length, elements) _corto_interfaceseqDefine(corto_interfaceseq(_this), length, elements)

/* interfaceVector */
CORTO_EXPORT corto_interfaceVector* _corto_interfaceVectorCreate(corto_interface interface, corto_objectseq vector);
#define corto_interfaceVectorCreate(interface, vector) _corto_interfaceVectorCreate(corto_interface(interface), vector)
#define corto_interfaceVectorCreate_auto(_id, interface, vector) corto_interfaceVector* _id = corto_interfaceVectorCreate(interface, vector); (void)_id
CORTO_EXPORT corto_interfaceVector* _corto_interfaceVectorCreateChild(corto_object _parent, corto_string _id, corto_interface interface, corto_objectseq vector);
#define corto_interfaceVectorCreateChild(_parent, _id, interface, vector) _corto_interfaceVectorCreateChild(_parent, _id, corto_interface(interface), vector)
#define corto_interfaceVectorCreateChild_auto(_parent, _id, interface, vector) corto_interfaceVector* _id = corto_interfaceVectorCreateChild(_parent, #_id, interface, vector); (void)_id
CORTO_EXPORT corto_int16 _corto_interfaceVectorUpdate(corto_interfaceVector* _this, corto_interface interface, corto_objectseq vector);
#define corto_interfaceVectorUpdate(_this, interface, vector) _corto_interfaceVectorUpdate(corto_interfaceVector(_this), corto_interface(interface), vector)
CORTO_EXPORT corto_interfaceVector* _corto_interfaceVectorAssign(corto_interfaceVector* _this, corto_interface interface, corto_objectseq vector);
#define corto_interfaceVector__optional_NotSet NULL
#define corto_interfaceVector__optional_Set(interface, vector) corto_interfaceVectorAssign((corto_interfaceVector*)corto_ptr_new(corto_interfaceVector_o)), interface, vector)
#define corto_interfaceVector__optional_SetCond(cond, interface, vector) cond ? corto_interfaceVectorAssign((corto_interfaceVector*)corto_ptr_new(corto_interfaceVector_o), interface, vector) : NULL
#define corto_interfaceVectorUnset(_this) _this ? corto_ptr_free(_this, corto_interfaceVector_o), 0 : 0; _this = NULL;
#define corto_interfaceVectorAssign(_this, interface, vector) _corto_interfaceVectorAssign(_this, corto_interface(interface), vector)
#define corto_interfaceVectorSet(_this, interface, vector) _this = _this ? _this : (corto_interfaceVector*)corto_ptr_new(corto_interfaceVector_o); _corto_interfaceVectorAssign(_this, corto_interface(interface), vector)

CORTO_EXPORT corto_interfaceVector* _corto_interfaceVectorDeclare(void);
#define corto_interfaceVectorDeclare() _corto_interfaceVectorDeclare()
#define corto_interfaceVectorDeclare_auto(_id) corto_interfaceVector* _id = corto_interfaceVectorDeclare(); (void)_id
CORTO_EXPORT corto_interfaceVector* _corto_interfaceVectorDeclareChild(corto_object _parent, corto_string _id);
#define corto_interfaceVectorDeclareChild(_parent, _id) _corto_interfaceVectorDeclareChild(_parent, _id)
#define corto_interfaceVectorDeclareChild_auto(_parent, _id) corto_interfaceVector* _id = corto_interfaceVectorDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_interfaceVectorDefine(corto_interfaceVector* _this, corto_interface interface, corto_objectseq vector);
#define corto_interfaceVectorDefine(_this, interface, vector) _corto_interfaceVectorDefine(corto_interfaceVector(_this), corto_interface(interface), vector)

/* interfaceVectorseq */
CORTO_EXPORT corto_interfaceVectorseq* _corto_interfaceVectorseqCreate(corto_uint32 length, corto_interfaceVector* elements);
#define corto_interfaceVectorseqCreate(length, elements) _corto_interfaceVectorseqCreate(length, elements)
#define corto_interfaceVectorseqCreate_auto(_id, length, elements) corto_interfaceVectorseq* _id = corto_interfaceVectorseqCreate(length, elements); (void)_id
CORTO_EXPORT corto_interfaceVectorseq* _corto_interfaceVectorseqCreateChild(corto_object _parent, corto_string _id, corto_uint32 length, corto_interfaceVector* elements);
#define corto_interfaceVectorseqCreateChild(_parent, _id, length, elements) _corto_interfaceVectorseqCreateChild(_parent, _id, length, elements)
#define corto_interfaceVectorseqCreateChild_auto(_parent, _id, length, elements) corto_interfaceVectorseq* _id = corto_interfaceVectorseqCreateChild(_parent, #_id, length, elements); (void)_id
CORTO_EXPORT corto_int16 _corto_interfaceVectorseqUpdate(corto_interfaceVectorseq* _this, corto_uint32 length, corto_interfaceVector* elements);
#define corto_interfaceVectorseqUpdate(_this, length, elements) _corto_interfaceVectorseqUpdate(corto_interfaceVectorseq(_this), length, elements)
CORTO_EXPORT corto_interfaceVectorseq* _corto_interfaceVectorseqAssign(corto_interfaceVectorseq* _this, corto_uint32 length, corto_interfaceVector* elements);
#define corto_interfaceVectorseq__optional_NotSet NULL
#define corto_interfaceVectorseq__optional_Set(length, elements) corto_interfaceVectorseqAssign((corto_interfaceVectorseq*)corto_ptr_new(corto_interfaceVectorseq_o)), length, elements)
#define corto_interfaceVectorseq__optional_SetCond(cond, length, elements) cond ? corto_interfaceVectorseqAssign((corto_interfaceVectorseq*)corto_ptr_new(corto_interfaceVectorseq_o), length, elements) : NULL
#define corto_interfaceVectorseqUnset(_this) _this ? corto_ptr_free(_this, corto_interfaceVectorseq_o), 0 : 0; _this = NULL;
#define corto_interfaceVectorseqAssign(_this, length, elements) _corto_interfaceVectorseqAssign(_this, length, elements)
#define corto_interfaceVectorseqSet(_this, length, elements) _this = _this ? _this : (corto_interfaceVectorseq*)corto_ptr_new(corto_interfaceVectorseq_o); _corto_interfaceVectorseqAssign(_this, length, elements)

CORTO_EXPORT corto_interfaceVectorseq* _corto_interfaceVectorseqDeclare(void);
#define corto_interfaceVectorseqDeclare() _corto_interfaceVectorseqDeclare()
#define corto_interfaceVectorseqDeclare_auto(_id) corto_interfaceVectorseq* _id = corto_interfaceVectorseqDeclare(); (void)_id
CORTO_EXPORT corto_interfaceVectorseq* _corto_interfaceVectorseqDeclareChild(corto_object _parent, corto_string _id);
#define corto_interfaceVectorseqDeclareChild(_parent, _id) _corto_interfaceVectorseqDeclareChild(_parent, _id)
#define corto_interfaceVectorseqDeclareChild_auto(_parent, _id) corto_interfaceVectorseq* _id = corto_interfaceVectorseqDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_interfaceVectorseqDefine(corto_interfaceVectorseq* _this, corto_uint32 length, corto_interfaceVector* elements);
#define corto_interfaceVectorseqDefine(_this, length, elements) _corto_interfaceVectorseqDefine(corto_interfaceVectorseq(_this), length, elements)

/* iterator */
CORTO_EXPORT corto_iterator _corto_iteratorCreate(corto_type elementType);
#define corto_iteratorCreate(elementType) _corto_iteratorCreate(corto_type(elementType))
#define corto_iteratorCreate_auto(_id, elementType) corto_iterator _id = corto_iteratorCreate(elementType); (void)_id
CORTO_EXPORT corto_iterator _corto_iteratorCreateChild(corto_object _parent, corto_string _id, corto_type elementType);
#define corto_iteratorCreateChild(_parent, _id, elementType) _corto_iteratorCreateChild(_parent, _id, corto_type(elementType))
#define corto_iteratorCreateChild_auto(_parent, _id, elementType) corto_iterator _id = corto_iteratorCreateChild(_parent, #_id, elementType); (void)_id
CORTO_EXPORT corto_int16 _corto_iteratorUpdate(corto_iterator _this, corto_type elementType);
#define corto_iteratorUpdate(_this, elementType) _corto_iteratorUpdate(corto_iterator(_this), corto_type(elementType))
CORTO_EXPORT corto_iterator _corto_iteratorAssign(corto_iterator _this, corto_type elementType);
#define corto_iterator__optional_NotSet NULL
#define corto_iterator__optional_Set(elementType) corto_iteratorAssign((corto_iterator*)corto_ptr_new(corto_iterator_o)), elementType)
#define corto_iterator__optional_SetCond(cond, elementType) cond ? corto_iteratorAssign((corto_iterator*)corto_ptr_new(corto_iterator_o), elementType) : NULL
#define corto_iteratorUnset(_this) _this ? corto_ptr_free(_this, corto_iterator_o), 0 : 0; _this = NULL;
#define corto_iteratorAssign(_this, elementType) _corto_iteratorAssign(_this, corto_type(elementType))
#define corto_iteratorSet(_this, elementType) _this = _this ? _this : (corto_iterator*)corto_ptr_new(corto_iterator_o); _corto_iteratorAssign(_this, corto_type(elementType))

CORTO_EXPORT corto_iterator _corto_iteratorDeclare(void);
#define corto_iteratorDeclare() _corto_iteratorDeclare()
#define corto_iteratorDeclare_auto(_id) corto_iterator _id = corto_iteratorDeclare(); (void)_id
CORTO_EXPORT corto_iterator _corto_iteratorDeclareChild(corto_object _parent, corto_string _id);
#define corto_iteratorDeclareChild(_parent, _id) _corto_iteratorDeclareChild(_parent, _id)
#define corto_iteratorDeclareChild_auto(_parent, _id) corto_iterator _id = corto_iteratorDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_iteratorDefine(corto_iterator _this, corto_type elementType);
#define corto_iteratorDefine(_this, elementType) _corto_iteratorDefine(corto_iterator(_this), corto_type(elementType))

/* leaf */
CORTO_EXPORT corto_leaf _corto_leafCreate(corto_interface base, corto_modifier baseAccess, corto_interfaceseq implements, corto_type type, corto_string value);
#define corto_leafCreate(base, baseAccess, implements, type, value) _corto_leafCreate(corto_interface(base), baseAccess, implements, corto_type(type), value)
#define corto_leafCreate_auto(_id, base, baseAccess, implements, type, value) corto_leaf _id = corto_leafCreate(base, baseAccess, implements, type, value); (void)_id
CORTO_EXPORT corto_leaf _corto_leafCreateChild(corto_object _parent, corto_string _id, corto_interface base, corto_modifier baseAccess, corto_interfaceseq implements, corto_type type, corto_string value);
#define corto_leafCreateChild(_parent, _id, base, baseAccess, implements, type, value) _corto_leafCreateChild(_parent, _id, corto_interface(base), baseAccess, implements, corto_type(type), value)
#define corto_leafCreateChild_auto(_parent, _id, base, baseAccess, implements, type, value) corto_leaf _id = corto_leafCreateChild(_parent, #_id, base, baseAccess, implements, type, value); (void)_id
CORTO_EXPORT corto_int16 _corto_leafUpdate(corto_leaf _this, corto_interface base, corto_modifier baseAccess, corto_interfaceseq implements, corto_type type, corto_string value);
#define corto_leafUpdate(_this, base, baseAccess, implements, type, value) _corto_leafUpdate(corto_leaf(_this), corto_interface(base), baseAccess, implements, corto_type(type), value)
CORTO_EXPORT corto_leaf _corto_leafAssign(corto_leaf _this, corto_interface base, corto_modifier baseAccess, corto_interfaceseq implements, corto_type type, corto_string value);
#define corto_leaf__optional_NotSet NULL
#define corto_leaf__optional_Set(base, baseAccess, implements, type, value) corto_leafAssign((corto_leaf*)corto_ptr_new(corto_leaf_o)), base, baseAccess, implements, type, value)
#define corto_leaf__optional_SetCond(cond, base, baseAccess, implements, type, value) cond ? corto_leafAssign((corto_leaf*)corto_ptr_new(corto_leaf_o), base, baseAccess, implements, type, value) : NULL
#define corto_leafUnset(_this) _this ? corto_ptr_free(_this, corto_leaf_o), 0 : 0; _this = NULL;
#define corto_leafAssign(_this, base, baseAccess, implements, type, value) _corto_leafAssign(_this, corto_interface(base), baseAccess, implements, corto_type(type), value)
#define corto_leafSet(_this, base, baseAccess, implements, type, value) _this = _this ? _this : (corto_leaf*)corto_ptr_new(corto_leaf_o); _corto_leafAssign(_this, corto_interface(base), baseAccess, implements, corto_type(type), value)

CORTO_EXPORT corto_leaf _corto_leafDeclare(void);
#define corto_leafDeclare() _corto_leafDeclare()
#define corto_leafDeclare_auto(_id) corto_leaf _id = corto_leafDeclare(); (void)_id
CORTO_EXPORT corto_leaf _corto_leafDeclareChild(corto_object _parent, corto_string _id);
#define corto_leafDeclareChild(_parent, _id) _corto_leafDeclareChild(_parent, _id)
#define corto_leafDeclareChild_auto(_parent, _id) corto_leaf _id = corto_leafDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_leafDefine(corto_leaf _this, corto_interface base, corto_modifier baseAccess, corto_interfaceseq implements, corto_type type, corto_string value);
#define corto_leafDefine(_this, base, baseAccess, implements, type, value) _corto_leafDefine(corto_leaf(_this), corto_interface(base), baseAccess, implements, corto_type(type), value)

/* list */
CORTO_EXPORT corto_list _corto_listCreate(corto_type elementType, uint32_t max);
#define corto_listCreate(elementType, max) _corto_listCreate(corto_type(elementType), max)
#define corto_listCreate_auto(_id, elementType, max) corto_list _id = corto_listCreate(elementType, max); (void)_id
CORTO_EXPORT corto_list _corto_listCreateChild(corto_object _parent, corto_string _id, corto_type elementType, uint32_t max);
#define corto_listCreateChild(_parent, _id, elementType, max) _corto_listCreateChild(_parent, _id, corto_type(elementType), max)
#define corto_listCreateChild_auto(_parent, _id, elementType, max) corto_list _id = corto_listCreateChild(_parent, #_id, elementType, max); (void)_id
CORTO_EXPORT corto_int16 _corto_listUpdate(corto_list _this, corto_type elementType, uint32_t max);
#define corto_listUpdate(_this, elementType, max) _corto_listUpdate(corto_list(_this), corto_type(elementType), max)
CORTO_EXPORT corto_list _corto_listAssign(corto_list _this, corto_type elementType, uint32_t max);
#define corto_list__optional_NotSet NULL
#define corto_list__optional_Set(elementType, max) corto_listAssign((corto_list*)corto_ptr_new(corto_list_o)), elementType, max)
#define corto_list__optional_SetCond(cond, elementType, max) cond ? corto_listAssign((corto_list*)corto_ptr_new(corto_list_o), elementType, max) : NULL
#define corto_listUnset(_this) _this ? corto_ptr_free(_this, corto_list_o), 0 : 0; _this = NULL;
#define corto_listAssign(_this, elementType, max) _corto_listAssign(_this, corto_type(elementType), max)
#define corto_listSet(_this, elementType, max) _this = _this ? _this : (corto_list*)corto_ptr_new(corto_list_o); _corto_listAssign(_this, corto_type(elementType), max)

CORTO_EXPORT corto_list _corto_listDeclare(void);
#define corto_listDeclare() _corto_listDeclare()
#define corto_listDeclare_auto(_id) corto_list _id = corto_listDeclare(); (void)_id
CORTO_EXPORT corto_list _corto_listDeclareChild(corto_object _parent, corto_string _id);
#define corto_listDeclareChild(_parent, _id) _corto_listDeclareChild(_parent, _id)
#define corto_listDeclareChild_auto(_parent, _id) corto_list _id = corto_listDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_listDefine(corto_list _this, corto_type elementType, uint32_t max);
#define corto_listDefine(_this, elementType, max) _corto_listDefine(corto_list(_this), corto_type(elementType), max)

/* map */
CORTO_EXPORT corto_map _corto_mapCreate(corto_type elementType, corto_type keyType, uint32_t max);
#define corto_mapCreate(elementType, keyType, max) _corto_mapCreate(corto_type(elementType), corto_type(keyType), max)
#define corto_mapCreate_auto(_id, elementType, keyType, max) corto_map _id = corto_mapCreate(elementType, keyType, max); (void)_id
CORTO_EXPORT corto_map _corto_mapCreateChild(corto_object _parent, corto_string _id, corto_type elementType, corto_type keyType, uint32_t max);
#define corto_mapCreateChild(_parent, _id, elementType, keyType, max) _corto_mapCreateChild(_parent, _id, corto_type(elementType), corto_type(keyType), max)
#define corto_mapCreateChild_auto(_parent, _id, elementType, keyType, max) corto_map _id = corto_mapCreateChild(_parent, #_id, elementType, keyType, max); (void)_id
CORTO_EXPORT corto_int16 _corto_mapUpdate(corto_map _this, corto_type elementType, corto_type keyType, uint32_t max);
#define corto_mapUpdate(_this, elementType, keyType, max) _corto_mapUpdate(corto_map(_this), corto_type(elementType), corto_type(keyType), max)
CORTO_EXPORT corto_map _corto_mapAssign(corto_map _this, corto_type elementType, corto_type keyType, uint32_t max);
#define corto_map__optional_NotSet NULL
#define corto_map__optional_Set(elementType, keyType, max) corto_mapAssign((corto_map*)corto_ptr_new(corto_map_o)), elementType, keyType, max)
#define corto_map__optional_SetCond(cond, elementType, keyType, max) cond ? corto_mapAssign((corto_map*)corto_ptr_new(corto_map_o), elementType, keyType, max) : NULL
#define corto_mapUnset(_this) _this ? corto_ptr_free(_this, corto_map_o), 0 : 0; _this = NULL;
#define corto_mapAssign(_this, elementType, keyType, max) _corto_mapAssign(_this, corto_type(elementType), corto_type(keyType), max)
#define corto_mapSet(_this, elementType, keyType, max) _this = _this ? _this : (corto_map*)corto_ptr_new(corto_map_o); _corto_mapAssign(_this, corto_type(elementType), corto_type(keyType), max)

CORTO_EXPORT corto_map _corto_mapDeclare(void);
#define corto_mapDeclare() _corto_mapDeclare()
#define corto_mapDeclare_auto(_id) corto_map _id = corto_mapDeclare(); (void)_id
CORTO_EXPORT corto_map _corto_mapDeclareChild(corto_object _parent, corto_string _id);
#define corto_mapDeclareChild(_parent, _id) _corto_mapDeclareChild(_parent, _id)
#define corto_mapDeclareChild_auto(_parent, _id) corto_map _id = corto_mapDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_mapDefine(corto_map _this, corto_type elementType, corto_type keyType, uint32_t max);
#define corto_mapDefine(_this, elementType, keyType, max) _corto_mapDefine(corto_map(_this), corto_type(elementType), corto_type(keyType), max)

/* member */
CORTO_EXPORT corto_member _corto_memberCreate(corto_type type, corto_modifier modifiers);
#define corto_memberCreate(type, modifiers) _corto_memberCreate(corto_type(type), modifiers)
#define corto_memberCreate_auto(_id, type, modifiers) corto_member _id = corto_memberCreate(type, modifiers); (void)_id
CORTO_EXPORT corto_member _corto_memberCreateChild(corto_object _parent, corto_string _id, corto_type type, corto_modifier modifiers);
#define corto_memberCreateChild(_parent, _id, type, modifiers) _corto_memberCreateChild(_parent, _id, corto_type(type), modifiers)
#define corto_memberCreateChild_auto(_parent, _id, type, modifiers) corto_member _id = corto_memberCreateChild(_parent, #_id, type, modifiers); (void)_id
CORTO_EXPORT corto_int16 _corto_memberUpdate(corto_member _this, corto_type type, corto_modifier modifiers);
#define corto_memberUpdate(_this, type, modifiers) _corto_memberUpdate(corto_member(_this), corto_type(type), modifiers)
CORTO_EXPORT corto_member _corto_memberAssign(corto_member _this, corto_type type, corto_modifier modifiers);
#define corto_member__optional_NotSet NULL
#define corto_member__optional_Set(type, modifiers) corto_memberAssign((corto_member*)corto_ptr_new(corto_member_o)), type, modifiers)
#define corto_member__optional_SetCond(cond, type, modifiers) cond ? corto_memberAssign((corto_member*)corto_ptr_new(corto_member_o), type, modifiers) : NULL
#define corto_memberUnset(_this) _this ? corto_ptr_free(_this, corto_member_o), 0 : 0; _this = NULL;
#define corto_memberAssign(_this, type, modifiers) _corto_memberAssign(_this, corto_type(type), modifiers)
#define corto_memberSet(_this, type, modifiers) _this = _this ? _this : (corto_member*)corto_ptr_new(corto_member_o); _corto_memberAssign(_this, corto_type(type), modifiers)

CORTO_EXPORT corto_member _corto_memberDeclare(void);
#define corto_memberDeclare() _corto_memberDeclare()
#define corto_memberDeclare_auto(_id) corto_member _id = corto_memberDeclare(); (void)_id
CORTO_EXPORT corto_member _corto_memberDeclareChild(corto_object _parent, corto_string _id);
#define corto_memberDeclareChild(_parent, _id) _corto_memberDeclareChild(_parent, _id)
#define corto_memberDeclareChild_auto(_parent, _id) corto_member _id = corto_memberDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_memberDefine(corto_member _this, corto_type type, corto_modifier modifiers);
#define corto_memberDefine(_this, type, modifiers) _corto_memberDefine(corto_member(_this), corto_type(type), modifiers)

/* metaprocedure */
CORTO_EXPORT corto_metaprocedure _corto_metaprocedureCreate(corto_type returnType, bool returnsReference, bool referenceOnly, void(*_impl)(void));
#define corto_metaprocedureCreate(returnType, returnsReference, referenceOnly, _impl) _corto_metaprocedureCreate(corto_type(returnType), returnsReference, referenceOnly, (void(*)(void))_impl)
#define corto_metaprocedureCreate_auto(_id, returnType, returnsReference, referenceOnly, _impl) corto_metaprocedure _id = corto_metaprocedureCreate(returnType, returnsReference, referenceOnly, _impl); (void)_id
CORTO_EXPORT corto_metaprocedure _corto_metaprocedureCreateChild(corto_object _parent, corto_string _id, corto_type returnType, bool returnsReference, bool referenceOnly, void(*_impl)(void));
#define corto_metaprocedureCreateChild(_parent, _id, returnType, returnsReference, referenceOnly, _impl) _corto_metaprocedureCreateChild(_parent, _id, corto_type(returnType), returnsReference, referenceOnly, (void(*)(void))_impl)
#define corto_metaprocedureCreateChild_auto(_parent, _id, returnType, returnsReference, referenceOnly, _impl) corto_metaprocedure _id = corto_metaprocedureCreateChild(_parent, #_id, returnType, returnsReference, referenceOnly, _impl); (void)_id
CORTO_EXPORT corto_int16 _corto_metaprocedureUpdate(corto_metaprocedure _this, corto_type returnType, bool returnsReference, bool referenceOnly, void(*_impl)(void));
#define corto_metaprocedureUpdate(_this, returnType, returnsReference, referenceOnly, _impl) _corto_metaprocedureUpdate(corto_metaprocedure(_this), corto_type(returnType), returnsReference, referenceOnly, (void(*)(void))_impl)
CORTO_EXPORT corto_metaprocedure _corto_metaprocedureAssign(corto_metaprocedure _this, corto_type returnType, bool returnsReference, bool referenceOnly, void(*_impl)(void));
#define corto_metaprocedure__optional_NotSet NULL
#define corto_metaprocedure__optional_Set(returnType, returnsReference, referenceOnly, _impl) corto_metaprocedureAssign((corto_metaprocedure*)corto_ptr_new(corto_metaprocedure_o)), returnType, returnsReference, referenceOnly, _impl)
#define corto_metaprocedure__optional_SetCond(cond, returnType, returnsReference, referenceOnly, _impl) cond ? corto_metaprocedureAssign((corto_metaprocedure*)corto_ptr_new(corto_metaprocedure_o), returnType, returnsReference, referenceOnly, _impl) : NULL
#define corto_metaprocedureUnset(_this) _this ? corto_ptr_free(_this, corto_metaprocedure_o), 0 : 0; _this = NULL;
#define corto_metaprocedureAssign(_this, returnType, returnsReference, referenceOnly, _impl) _corto_metaprocedureAssign(_this, corto_type(returnType), returnsReference, referenceOnly, (void(*)(void))_impl)
#define corto_metaprocedureSet(_this, returnType, returnsReference, referenceOnly, _impl) _this = _this ? _this : (corto_metaprocedure*)corto_ptr_new(corto_metaprocedure_o); _corto_metaprocedureAssign(_this, corto_type(returnType), returnsReference, referenceOnly, (void(*)(void))_impl)

CORTO_EXPORT corto_metaprocedure _corto_metaprocedureDeclare(void);
#define corto_metaprocedureDeclare() _corto_metaprocedureDeclare()
#define corto_metaprocedureDeclare_auto(_id) corto_metaprocedure _id = corto_metaprocedureDeclare(); (void)_id
CORTO_EXPORT corto_metaprocedure _corto_metaprocedureDeclareChild(corto_object _parent, corto_string _id);
#define corto_metaprocedureDeclareChild(_parent, _id) _corto_metaprocedureDeclareChild(_parent, _id)
#define corto_metaprocedureDeclareChild_auto(_parent, _id) corto_metaprocedure _id = corto_metaprocedureDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_metaprocedureDefine(corto_metaprocedure _this, corto_type returnType, bool returnsReference, bool referenceOnly, void(*_impl)(void));
#define corto_metaprocedureDefine(_this, returnType, returnsReference, referenceOnly, _impl) _corto_metaprocedureDefine(corto_metaprocedure(_this), corto_type(returnType), returnsReference, referenceOnly, (void(*)(void))_impl)

/* method */
CORTO_EXPORT corto_method _corto_methodCreate(corto_type returnType, bool returnsReference, void(*_impl)(void));
#define corto_methodCreate(returnType, returnsReference, _impl) _corto_methodCreate(corto_type(returnType), returnsReference, (void(*)(void))_impl)
#define corto_methodCreate_auto(_id, returnType, returnsReference, _impl) corto_method _id = corto_methodCreate(returnType, returnsReference, _impl); (void)_id
CORTO_EXPORT corto_method _corto_methodCreateChild(corto_object _parent, corto_string _id, corto_type returnType, bool returnsReference, void(*_impl)(void));
#define corto_methodCreateChild(_parent, _id, returnType, returnsReference, _impl) _corto_methodCreateChild(_parent, _id, corto_type(returnType), returnsReference, (void(*)(void))_impl)
#define corto_methodCreateChild_auto(_parent, _id, returnType, returnsReference, _impl) corto_method _id = corto_methodCreateChild(_parent, #_id, returnType, returnsReference, _impl); (void)_id
CORTO_EXPORT corto_int16 _corto_methodUpdate(corto_method _this, corto_type returnType, bool returnsReference, void(*_impl)(void));
#define corto_methodUpdate(_this, returnType, returnsReference, _impl) _corto_methodUpdate(corto_method(_this), corto_type(returnType), returnsReference, (void(*)(void))_impl)
CORTO_EXPORT corto_method _corto_methodAssign(corto_method _this, corto_type returnType, bool returnsReference, void(*_impl)(void));
#define corto_method__optional_NotSet NULL
#define corto_method__optional_Set(returnType, returnsReference, _impl) corto_methodAssign((corto_method*)corto_ptr_new(corto_method_o)), returnType, returnsReference, _impl)
#define corto_method__optional_SetCond(cond, returnType, returnsReference, _impl) cond ? corto_methodAssign((corto_method*)corto_ptr_new(corto_method_o), returnType, returnsReference, _impl) : NULL
#define corto_methodUnset(_this) _this ? corto_ptr_free(_this, corto_method_o), 0 : 0; _this = NULL;
#define corto_methodAssign(_this, returnType, returnsReference, _impl) _corto_methodAssign(_this, corto_type(returnType), returnsReference, (void(*)(void))_impl)
#define corto_methodSet(_this, returnType, returnsReference, _impl) _this = _this ? _this : (corto_method*)corto_ptr_new(corto_method_o); _corto_methodAssign(_this, corto_type(returnType), returnsReference, (void(*)(void))_impl)

CORTO_EXPORT corto_method _corto_methodDeclare(void);
#define corto_methodDeclare() _corto_methodDeclare()
#define corto_methodDeclare_auto(_id) corto_method _id = corto_methodDeclare(); (void)_id
CORTO_EXPORT corto_method _corto_methodDeclareChild(corto_object _parent, corto_string _id);
#define corto_methodDeclareChild(_parent, _id) _corto_methodDeclareChild(_parent, _id)
#define corto_methodDeclareChild_auto(_parent, _id) corto_method _id = corto_methodDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_methodDefine(corto_method _this, corto_type returnType, bool returnsReference, void(*_impl)(void));
#define corto_methodDefine(_this, returnType, returnsReference, _impl) _corto_methodDefine(corto_method(_this), corto_type(returnType), returnsReference, (void(*)(void))_impl)

/* modifier */
CORTO_EXPORT corto_modifier* _corto_modifierCreate(corto_modifier value);
#define corto_modifierCreate(value) _corto_modifierCreate(value)
#define corto_modifierCreate_auto(_id, value) corto_modifier* _id = corto_modifierCreate(value); (void)_id
CORTO_EXPORT corto_modifier* _corto_modifierCreateChild(corto_object _parent, corto_string _id, corto_modifier value);
#define corto_modifierCreateChild(_parent, _id, value) _corto_modifierCreateChild(_parent, _id, value)
#define corto_modifierCreateChild_auto(_parent, _id, value) corto_modifier* _id = corto_modifierCreateChild(_parent, #_id, value); (void)_id
CORTO_EXPORT corto_int16 _corto_modifierUpdate(corto_modifier* _this, corto_modifier value);
#define corto_modifierUpdate(_this, value) _corto_modifierUpdate(corto_modifier(_this), value)
CORTO_EXPORT corto_modifier* _corto_modifierAssign(corto_modifier* _this, corto_modifier value);
#define corto_modifier__optional_NotSet NULL
#define corto_modifier__optional_Set(value) corto_modifierAssign((corto_modifier*)corto_ptr_new(corto_modifier_o)), value)
#define corto_modifier__optional_SetCond(cond, value) cond ? corto_modifierAssign((corto_modifier*)corto_ptr_new(corto_modifier_o), value) : NULL
#define corto_modifierUnset(_this) _this ? corto_ptr_free(_this, corto_modifier_o), 0 : 0; _this = NULL;
#define corto_modifierAssign(_this, value) _corto_modifierAssign(_this, value)
#define corto_modifierSet(_this, value) _this = _this ? _this : (corto_modifier*)corto_ptr_new(corto_modifier_o); _corto_modifierAssign(_this, value)

CORTO_EXPORT corto_modifier* _corto_modifierDeclare(void);
#define corto_modifierDeclare() _corto_modifierDeclare()
#define corto_modifierDeclare_auto(_id) corto_modifier* _id = corto_modifierDeclare(); (void)_id
CORTO_EXPORT corto_modifier* _corto_modifierDeclareChild(corto_object _parent, corto_string _id);
#define corto_modifierDeclareChild(_parent, _id) _corto_modifierDeclareChild(_parent, _id)
#define corto_modifierDeclareChild_auto(_parent, _id) corto_modifier* _id = corto_modifierDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_modifierDefine(corto_modifier* _this, corto_modifier value);
#define corto_modifierDefine(_this, value) _corto_modifierDefine(corto_modifier(_this), value)

/* nameAction */
CORTO_EXPORT corto_nameAction* _corto_nameActionCreate(corto_object instance, corto_function procedure);
#define corto_nameActionCreate(instance, procedure) _corto_nameActionCreate(instance, corto_function(procedure))
#define corto_nameActionCreate_auto(_id, instance, procedure) corto_nameAction* _id = corto_nameActionCreate(instance, procedure); (void)_id
CORTO_EXPORT corto_nameAction* _corto_nameActionCreateChild(corto_object _parent, corto_string _id, corto_object instance, corto_function procedure);
#define corto_nameActionCreateChild(_parent, _id, instance, procedure) _corto_nameActionCreateChild(_parent, _id, instance, corto_function(procedure))
#define corto_nameActionCreateChild_auto(_parent, _id, instance, procedure) corto_nameAction* _id = corto_nameActionCreateChild(_parent, #_id, instance, procedure); (void)_id
CORTO_EXPORT corto_int16 _corto_nameActionUpdate(corto_nameAction* _this, corto_object instance, corto_function procedure);
#define corto_nameActionUpdate(_this, instance, procedure) _corto_nameActionUpdate(corto_nameAction(_this), instance, corto_function(procedure))
CORTO_EXPORT corto_nameAction* _corto_nameActionAssign(corto_nameAction* _this, corto_object instance, corto_function procedure);
#define corto_nameAction__optional_NotSet NULL
#define corto_nameAction__optional_Set(instance, procedure) corto_nameActionAssign((corto_nameAction*)corto_ptr_new(corto_nameAction_o)), instance, procedure)
#define corto_nameAction__optional_SetCond(cond, instance, procedure) cond ? corto_nameActionAssign((corto_nameAction*)corto_ptr_new(corto_nameAction_o), instance, procedure) : NULL
#define corto_nameActionUnset(_this) _this ? corto_ptr_free(_this, corto_nameAction_o), 0 : 0; _this = NULL;
#define corto_nameActionAssign(_this, instance, procedure) _corto_nameActionAssign(_this, instance, corto_function(procedure))
#define corto_nameActionSet(_this, instance, procedure) _this = _this ? _this : (corto_nameAction*)corto_ptr_new(corto_nameAction_o); _corto_nameActionAssign(_this, instance, corto_function(procedure))

CORTO_EXPORT corto_nameAction* _corto_nameActionDeclare(void);
#define corto_nameActionDeclare() _corto_nameActionDeclare()
#define corto_nameActionDeclare_auto(_id) corto_nameAction* _id = corto_nameActionDeclare(); (void)_id
CORTO_EXPORT corto_nameAction* _corto_nameActionDeclareChild(corto_object _parent, corto_string _id);
#define corto_nameActionDeclareChild(_parent, _id) _corto_nameActionDeclareChild(_parent, _id)
#define corto_nameActionDeclareChild_auto(_parent, _id) corto_nameAction* _id = corto_nameActionDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_nameActionDefine(corto_nameAction* _this, corto_object instance, corto_function procedure);
#define corto_nameActionDefine(_this, instance, procedure) _corto_nameActionDefine(corto_nameAction(_this), instance, corto_function(procedure))

corto_int16 corto_nameActionCall(corto_nameAction *_delegate, corto_string* _result);
#define corto_nameActionInitC_auto(d, callback) corto_nameAction d; corto_nameActionInitC(&d, callback)
CORTO_EXPORT corto_int16 corto_nameActionInitC(corto_nameAction *d, corto_string ___ (*callback)(void));
#define corto_nameActionInitCInstance_auto(d, instance, callback)corto_nameAction d; corto_nameActionInitCInstance(&d, instance, callback)
CORTO_EXPORT corto_int16 corto_nameActionInitCInstance(corto_nameAction *d, corto_object instance, corto_string ___ (*callback)(corto_object));
/* object */
CORTO_EXPORT corto_object _corto_objectCreate(void);
#define corto_objectCreate() _corto_objectCreate()
#define corto_objectCreate_auto(_id) corto_object _id = corto_objectCreate(); (void)_id
CORTO_EXPORT corto_object _corto_objectCreateChild(corto_object _parent, corto_string _id);
#define corto_objectCreateChild(_parent, _id) _corto_objectCreateChild(_parent, _id)
#define corto_objectCreateChild_auto(_parent, _id) corto_object _id = corto_objectCreateChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_objectUpdate(corto_object _this);
#define corto_objectUpdate(_this) _corto_objectUpdate(corto_object(_this))
CORTO_EXPORT corto_object _corto_objectAssign(corto_object _this);
#define corto_object__optional_NotSet NULL
#define corto_object__optional_Set() corto_objectAssign((corto_object*)corto_ptr_new(corto_object_o)))
#define corto_object__optional_SetCond(cond) cond ? corto_objectAssign((corto_object*)corto_ptr_new(corto_object_o)) : NULL
#define corto_objectUnset(_this) _this ? corto_ptr_free(_this, corto_object_o), 0 : 0; _this = NULL;
#define corto_objectAssign(_this) _corto_objectAssign(_this)
#define corto_objectSet(_this) _this = _this ? _this : (corto_object*)corto_ptr_new(corto_object_o); _corto_objectAssign(_this)

/* objectlist */
CORTO_EXPORT corto_objectlist* _corto_objectlistCreate(corto_uint32 length, corto_object* elements);
#define corto_objectlistCreate(length, elements) _corto_objectlistCreate(length, elements)
#define corto_objectlistCreate_auto(_id, length, elements) corto_objectlist* _id = corto_objectlistCreate(length, elements); (void)_id
CORTO_EXPORT corto_objectlist* _corto_objectlistCreateChild(corto_object _parent, corto_string _id, corto_uint32 length, corto_object* elements);
#define corto_objectlistCreateChild(_parent, _id, length, elements) _corto_objectlistCreateChild(_parent, _id, length, elements)
#define corto_objectlistCreateChild_auto(_parent, _id, length, elements) corto_objectlist* _id = corto_objectlistCreateChild(_parent, #_id, length, elements); (void)_id
CORTO_EXPORT corto_int16 _corto_objectlistUpdate(corto_objectlist* _this, corto_uint32 length, corto_object* elements);
#define corto_objectlistUpdate(_this, length, elements) _corto_objectlistUpdate(corto_objectlist(_this), length, elements)
CORTO_EXPORT corto_objectlist* _corto_objectlistAssign(corto_objectlist* _this, corto_uint32 length, corto_object* elements);
#define corto_objectlist__optional_NotSet NULL
#define corto_objectlist__optional_Set(length, elements) corto_objectlistAssign((corto_objectlist*)corto_ptr_new(corto_objectlist_o)), length, elements)
#define corto_objectlist__optional_SetCond(cond, length, elements) cond ? corto_objectlistAssign((corto_objectlist*)corto_ptr_new(corto_objectlist_o), length, elements) : NULL
#define corto_objectlistUnset(_this) _this ? corto_ptr_free(_this, corto_objectlist_o), 0 : 0; _this = NULL;
#define corto_objectlistAssign(_this, length, elements) _corto_objectlistAssign(_this, length, elements)
#define corto_objectlistSet(_this, length, elements) _this = _this ? _this : (corto_objectlist*)corto_ptr_new(corto_objectlist_o); _corto_objectlistAssign(_this, length, elements)

CORTO_EXPORT corto_objectlist* _corto_objectlistDeclare(void);
#define corto_objectlistDeclare() _corto_objectlistDeclare()
#define corto_objectlistDeclare_auto(_id) corto_objectlist* _id = corto_objectlistDeclare(); (void)_id
CORTO_EXPORT corto_objectlist* _corto_objectlistDeclareChild(corto_object _parent, corto_string _id);
#define corto_objectlistDeclareChild(_parent, _id) _corto_objectlistDeclareChild(_parent, _id)
#define corto_objectlistDeclareChild_auto(_parent, _id) corto_objectlist* _id = corto_objectlistDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_objectlistDefine(corto_objectlist* _this, corto_uint32 length, corto_object* elements);
#define corto_objectlistDefine(_this, length, elements) _corto_objectlistDefine(corto_objectlist(_this), length, elements)

/* objectseq */
CORTO_EXPORT corto_objectseq* _corto_objectseqCreate(corto_uint32 length, corto_object* elements);
#define corto_objectseqCreate(length, elements) _corto_objectseqCreate(length, elements)
#define corto_objectseqCreate_auto(_id, length, elements) corto_objectseq* _id = corto_objectseqCreate(length, elements); (void)_id
CORTO_EXPORT corto_objectseq* _corto_objectseqCreateChild(corto_object _parent, corto_string _id, corto_uint32 length, corto_object* elements);
#define corto_objectseqCreateChild(_parent, _id, length, elements) _corto_objectseqCreateChild(_parent, _id, length, elements)
#define corto_objectseqCreateChild_auto(_parent, _id, length, elements) corto_objectseq* _id = corto_objectseqCreateChild(_parent, #_id, length, elements); (void)_id
CORTO_EXPORT corto_int16 _corto_objectseqUpdate(corto_objectseq* _this, corto_uint32 length, corto_object* elements);
#define corto_objectseqUpdate(_this, length, elements) _corto_objectseqUpdate(corto_objectseq(_this), length, elements)
CORTO_EXPORT corto_objectseq* _corto_objectseqAssign(corto_objectseq* _this, corto_uint32 length, corto_object* elements);
#define corto_objectseq__optional_NotSet NULL
#define corto_objectseq__optional_Set(length, elements) corto_objectseqAssign((corto_objectseq*)corto_ptr_new(corto_objectseq_o)), length, elements)
#define corto_objectseq__optional_SetCond(cond, length, elements) cond ? corto_objectseqAssign((corto_objectseq*)corto_ptr_new(corto_objectseq_o), length, elements) : NULL
#define corto_objectseqUnset(_this) _this ? corto_ptr_free(_this, corto_objectseq_o), 0 : 0; _this = NULL;
#define corto_objectseqAssign(_this, length, elements) _corto_objectseqAssign(_this, length, elements)
#define corto_objectseqSet(_this, length, elements) _this = _this ? _this : (corto_objectseq*)corto_ptr_new(corto_objectseq_o); _corto_objectseqAssign(_this, length, elements)

CORTO_EXPORT corto_objectseq* _corto_objectseqDeclare(void);
#define corto_objectseqDeclare() _corto_objectseqDeclare()
#define corto_objectseqDeclare_auto(_id) corto_objectseq* _id = corto_objectseqDeclare(); (void)_id
CORTO_EXPORT corto_objectseq* _corto_objectseqDeclareChild(corto_object _parent, corto_string _id);
#define corto_objectseqDeclareChild(_parent, _id) _corto_objectseqDeclareChild(_parent, _id)
#define corto_objectseqDeclareChild_auto(_parent, _id) corto_objectseq* _id = corto_objectseqDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_objectseqDefine(corto_objectseq* _this, corto_uint32 length, corto_object* elements);
#define corto_objectseqDefine(_this, length, elements) _corto_objectseqDefine(corto_objectseq(_this), length, elements)

/* octet */
CORTO_EXPORT uint8_t* _corto_octetCreate(uint8_t value);
#define corto_octetCreate(value) _corto_octetCreate(value)
#define corto_octetCreate_auto(_id, value) uint8_t* _id = corto_octetCreate(value); (void)_id
CORTO_EXPORT uint8_t* _corto_octetCreateChild(corto_object _parent, corto_string _id, uint8_t value);
#define corto_octetCreateChild(_parent, _id, value) _corto_octetCreateChild(_parent, _id, value)
#define corto_octetCreateChild_auto(_parent, _id, value) uint8_t* _id = corto_octetCreateChild(_parent, #_id, value); (void)_id
CORTO_EXPORT corto_int16 _corto_octetUpdate(uint8_t* _this, uint8_t value);
#define corto_octetUpdate(_this, value) _corto_octetUpdate(corto_octet(_this), value)
CORTO_EXPORT uint8_t* _corto_octetAssign(uint8_t* _this, uint8_t value);
#define corto_octet__optional_NotSet NULL
#define corto_octet__optional_Set(value) corto_octetAssign((corto_octet*)corto_ptr_new(corto_octet_o)), value)
#define corto_octet__optional_SetCond(cond, value) cond ? corto_octetAssign((corto_octet*)corto_ptr_new(corto_octet_o), value) : NULL
#define corto_octetUnset(_this) _this ? corto_ptr_free(_this, corto_octet_o), 0 : 0; _this = NULL;
#define corto_octetAssign(_this, value) _corto_octetAssign(_this, value)
#define corto_octetSet(_this, value) _this = _this ? _this : (corto_octet*)corto_ptr_new(corto_octet_o); _corto_octetAssign(_this, value)

CORTO_EXPORT uint8_t* _corto_octetDeclare(void);
#define corto_octetDeclare() _corto_octetDeclare()
#define corto_octetDeclare_auto(_id) uint8_t* _id = corto_octetDeclare(); (void)_id
CORTO_EXPORT uint8_t* _corto_octetDeclareChild(corto_object _parent, corto_string _id);
#define corto_octetDeclareChild(_parent, _id) _corto_octetDeclareChild(_parent, _id)
#define corto_octetDeclareChild_auto(_parent, _id) uint8_t* _id = corto_octetDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_octetDefine(uint8_t* _this, uint8_t value);
#define corto_octetDefine(_this, value) _corto_octetDefine(corto_octet(_this), value)

/* overridable */
CORTO_EXPORT corto_overridable _corto_overridableCreate(corto_type returnType, bool returnsReference, void(*_impl)(void));
#define corto_overridableCreate(returnType, returnsReference, _impl) _corto_overridableCreate(corto_type(returnType), returnsReference, (void(*)(void))_impl)
#define corto_overridableCreate_auto(_id, returnType, returnsReference, _impl) corto_overridable _id = corto_overridableCreate(returnType, returnsReference, _impl); (void)_id
CORTO_EXPORT corto_overridable _corto_overridableCreateChild(corto_object _parent, corto_string _id, corto_type returnType, bool returnsReference, void(*_impl)(void));
#define corto_overridableCreateChild(_parent, _id, returnType, returnsReference, _impl) _corto_overridableCreateChild(_parent, _id, corto_type(returnType), returnsReference, (void(*)(void))_impl)
#define corto_overridableCreateChild_auto(_parent, _id, returnType, returnsReference, _impl) corto_overridable _id = corto_overridableCreateChild(_parent, #_id, returnType, returnsReference, _impl); (void)_id
CORTO_EXPORT corto_int16 _corto_overridableUpdate(corto_overridable _this, corto_type returnType, bool returnsReference, void(*_impl)(void));
#define corto_overridableUpdate(_this, returnType, returnsReference, _impl) _corto_overridableUpdate(corto_overridable(_this), corto_type(returnType), returnsReference, (void(*)(void))_impl)
CORTO_EXPORT corto_overridable _corto_overridableAssign(corto_overridable _this, corto_type returnType, bool returnsReference, void(*_impl)(void));
#define corto_overridable__optional_NotSet NULL
#define corto_overridable__optional_Set(returnType, returnsReference, _impl) corto_overridableAssign((corto_overridable*)corto_ptr_new(corto_overridable_o)), returnType, returnsReference, _impl)
#define corto_overridable__optional_SetCond(cond, returnType, returnsReference, _impl) cond ? corto_overridableAssign((corto_overridable*)corto_ptr_new(corto_overridable_o), returnType, returnsReference, _impl) : NULL
#define corto_overridableUnset(_this) _this ? corto_ptr_free(_this, corto_overridable_o), 0 : 0; _this = NULL;
#define corto_overridableAssign(_this, returnType, returnsReference, _impl) _corto_overridableAssign(_this, corto_type(returnType), returnsReference, (void(*)(void))_impl)
#define corto_overridableSet(_this, returnType, returnsReference, _impl) _this = _this ? _this : (corto_overridable*)corto_ptr_new(corto_overridable_o); _corto_overridableAssign(_this, corto_type(returnType), returnsReference, (void(*)(void))_impl)

CORTO_EXPORT corto_overridable _corto_overridableDeclare(void);
#define corto_overridableDeclare() _corto_overridableDeclare()
#define corto_overridableDeclare_auto(_id) corto_overridable _id = corto_overridableDeclare(); (void)_id
CORTO_EXPORT corto_overridable _corto_overridableDeclareChild(corto_object _parent, corto_string _id);
#define corto_overridableDeclareChild(_parent, _id) _corto_overridableDeclareChild(_parent, _id)
#define corto_overridableDeclareChild_auto(_parent, _id) corto_overridable _id = corto_overridableDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_overridableDefine(corto_overridable _this, corto_type returnType, bool returnsReference, void(*_impl)(void));
#define corto_overridableDefine(_this, returnType, returnsReference, _impl) _corto_overridableDefine(corto_overridable(_this), corto_type(returnType), returnsReference, (void(*)(void))_impl)

/* override */
CORTO_EXPORT corto_override _corto_overrideCreate(corto_type returnType, bool returnsReference, void(*_impl)(void));
#define corto_overrideCreate(returnType, returnsReference, _impl) _corto_overrideCreate(corto_type(returnType), returnsReference, (void(*)(void))_impl)
#define corto_overrideCreate_auto(_id, returnType, returnsReference, _impl) corto_override _id = corto_overrideCreate(returnType, returnsReference, _impl); (void)_id
CORTO_EXPORT corto_override _corto_overrideCreateChild(corto_object _parent, corto_string _id, corto_type returnType, bool returnsReference, void(*_impl)(void));
#define corto_overrideCreateChild(_parent, _id, returnType, returnsReference, _impl) _corto_overrideCreateChild(_parent, _id, corto_type(returnType), returnsReference, (void(*)(void))_impl)
#define corto_overrideCreateChild_auto(_parent, _id, returnType, returnsReference, _impl) corto_override _id = corto_overrideCreateChild(_parent, #_id, returnType, returnsReference, _impl); (void)_id
CORTO_EXPORT corto_int16 _corto_overrideUpdate(corto_override _this, corto_type returnType, bool returnsReference, void(*_impl)(void));
#define corto_overrideUpdate(_this, returnType, returnsReference, _impl) _corto_overrideUpdate(corto_override(_this), corto_type(returnType), returnsReference, (void(*)(void))_impl)
CORTO_EXPORT corto_override _corto_overrideAssign(corto_override _this, corto_type returnType, bool returnsReference, void(*_impl)(void));
#define corto_override__optional_NotSet NULL
#define corto_override__optional_Set(returnType, returnsReference, _impl) corto_overrideAssign((corto_override*)corto_ptr_new(corto_override_o)), returnType, returnsReference, _impl)
#define corto_override__optional_SetCond(cond, returnType, returnsReference, _impl) cond ? corto_overrideAssign((corto_override*)corto_ptr_new(corto_override_o), returnType, returnsReference, _impl) : NULL
#define corto_overrideUnset(_this) _this ? corto_ptr_free(_this, corto_override_o), 0 : 0; _this = NULL;
#define corto_overrideAssign(_this, returnType, returnsReference, _impl) _corto_overrideAssign(_this, corto_type(returnType), returnsReference, (void(*)(void))_impl)
#define corto_overrideSet(_this, returnType, returnsReference, _impl) _this = _this ? _this : (corto_override*)corto_ptr_new(corto_override_o); _corto_overrideAssign(_this, corto_type(returnType), returnsReference, (void(*)(void))_impl)

CORTO_EXPORT corto_override _corto_overrideDeclare(void);
#define corto_overrideDeclare() _corto_overrideDeclare()
#define corto_overrideDeclare_auto(_id) corto_override _id = corto_overrideDeclare(); (void)_id
CORTO_EXPORT corto_override _corto_overrideDeclareChild(corto_object _parent, corto_string _id);
#define corto_overrideDeclareChild(_parent, _id) _corto_overrideDeclareChild(_parent, _id)
#define corto_overrideDeclareChild_auto(_parent, _id) corto_override _id = corto_overrideDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_overrideDefine(corto_override _this, corto_type returnType, bool returnsReference, void(*_impl)(void));
#define corto_overrideDefine(_this, returnType, returnsReference, _impl) _corto_overrideDefine(corto_override(_this), corto_type(returnType), returnsReference, (void(*)(void))_impl)

/* parameter */
CORTO_EXPORT corto_parameter* _corto_parameterCreate(corto_string name, corto_type type, corto_inout inout, bool passByReference);
#define corto_parameterCreate(name, type, inout, passByReference) _corto_parameterCreate(name, corto_type(type), inout, passByReference)
#define corto_parameterCreate_auto(_id, name, type, inout, passByReference) corto_parameter* _id = corto_parameterCreate(name, type, inout, passByReference); (void)_id
CORTO_EXPORT corto_parameter* _corto_parameterCreateChild(corto_object _parent, corto_string _id, corto_string name, corto_type type, corto_inout inout, bool passByReference);
#define corto_parameterCreateChild(_parent, _id, name, type, inout, passByReference) _corto_parameterCreateChild(_parent, _id, name, corto_type(type), inout, passByReference)
#define corto_parameterCreateChild_auto(_parent, _id, name, type, inout, passByReference) corto_parameter* _id = corto_parameterCreateChild(_parent, #_id, name, type, inout, passByReference); (void)_id
CORTO_EXPORT corto_int16 _corto_parameterUpdate(corto_parameter* _this, corto_string name, corto_type type, corto_inout inout, bool passByReference);
#define corto_parameterUpdate(_this, name, type, inout, passByReference) _corto_parameterUpdate(corto_parameter(_this), name, corto_type(type), inout, passByReference)
CORTO_EXPORT corto_parameter* _corto_parameterAssign(corto_parameter* _this, corto_string name, corto_type type, corto_inout inout, bool passByReference);
#define corto_parameter__optional_NotSet NULL
#define corto_parameter__optional_Set(name, type, inout, passByReference) corto_parameterAssign((corto_parameter*)corto_ptr_new(corto_parameter_o)), name, type, inout, passByReference)
#define corto_parameter__optional_SetCond(cond, name, type, inout, passByReference) cond ? corto_parameterAssign((corto_parameter*)corto_ptr_new(corto_parameter_o), name, type, inout, passByReference) : NULL
#define corto_parameterUnset(_this) _this ? corto_ptr_free(_this, corto_parameter_o), 0 : 0; _this = NULL;
#define corto_parameterAssign(_this, name, type, inout, passByReference) _corto_parameterAssign(_this, name, corto_type(type), inout, passByReference)
#define corto_parameterSet(_this, name, type, inout, passByReference) _this = _this ? _this : (corto_parameter*)corto_ptr_new(corto_parameter_o); _corto_parameterAssign(_this, name, corto_type(type), inout, passByReference)

CORTO_EXPORT corto_parameter* _corto_parameterDeclare(void);
#define corto_parameterDeclare() _corto_parameterDeclare()
#define corto_parameterDeclare_auto(_id) corto_parameter* _id = corto_parameterDeclare(); (void)_id
CORTO_EXPORT corto_parameter* _corto_parameterDeclareChild(corto_object _parent, corto_string _id);
#define corto_parameterDeclareChild(_parent, _id) _corto_parameterDeclareChild(_parent, _id)
#define corto_parameterDeclareChild_auto(_parent, _id) corto_parameter* _id = corto_parameterDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_parameterDefine(corto_parameter* _this, corto_string name, corto_type type, corto_inout inout, bool passByReference);
#define corto_parameterDefine(_this, name, type, inout, passByReference) _corto_parameterDefine(corto_parameter(_this), name, corto_type(type), inout, passByReference)

/* parameterseq */
CORTO_EXPORT corto_parameterseq* _corto_parameterseqCreate(corto_uint32 length, corto_parameter* elements);
#define corto_parameterseqCreate(length, elements) _corto_parameterseqCreate(length, elements)
#define corto_parameterseqCreate_auto(_id, length, elements) corto_parameterseq* _id = corto_parameterseqCreate(length, elements); (void)_id
CORTO_EXPORT corto_parameterseq* _corto_parameterseqCreateChild(corto_object _parent, corto_string _id, corto_uint32 length, corto_parameter* elements);
#define corto_parameterseqCreateChild(_parent, _id, length, elements) _corto_parameterseqCreateChild(_parent, _id, length, elements)
#define corto_parameterseqCreateChild_auto(_parent, _id, length, elements) corto_parameterseq* _id = corto_parameterseqCreateChild(_parent, #_id, length, elements); (void)_id
CORTO_EXPORT corto_int16 _corto_parameterseqUpdate(corto_parameterseq* _this, corto_uint32 length, corto_parameter* elements);
#define corto_parameterseqUpdate(_this, length, elements) _corto_parameterseqUpdate(corto_parameterseq(_this), length, elements)
CORTO_EXPORT corto_parameterseq* _corto_parameterseqAssign(corto_parameterseq* _this, corto_uint32 length, corto_parameter* elements);
#define corto_parameterseq__optional_NotSet NULL
#define corto_parameterseq__optional_Set(length, elements) corto_parameterseqAssign((corto_parameterseq*)corto_ptr_new(corto_parameterseq_o)), length, elements)
#define corto_parameterseq__optional_SetCond(cond, length, elements) cond ? corto_parameterseqAssign((corto_parameterseq*)corto_ptr_new(corto_parameterseq_o), length, elements) : NULL
#define corto_parameterseqUnset(_this) _this ? corto_ptr_free(_this, corto_parameterseq_o), 0 : 0; _this = NULL;
#define corto_parameterseqAssign(_this, length, elements) _corto_parameterseqAssign(_this, length, elements)
#define corto_parameterseqSet(_this, length, elements) _this = _this ? _this : (corto_parameterseq*)corto_ptr_new(corto_parameterseq_o); _corto_parameterseqAssign(_this, length, elements)

CORTO_EXPORT corto_parameterseq* _corto_parameterseqDeclare(void);
#define corto_parameterseqDeclare() _corto_parameterseqDeclare()
#define corto_parameterseqDeclare_auto(_id) corto_parameterseq* _id = corto_parameterseqDeclare(); (void)_id
CORTO_EXPORT corto_parameterseq* _corto_parameterseqDeclareChild(corto_object _parent, corto_string _id);
#define corto_parameterseqDeclareChild(_parent, _id) _corto_parameterseqDeclareChild(_parent, _id)
#define corto_parameterseqDeclareChild_auto(_parent, _id) corto_parameterseq* _id = corto_parameterseqDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_parameterseqDefine(corto_parameterseq* _this, corto_uint32 length, corto_parameter* elements);
#define corto_parameterseqDefine(_this, length, elements) _corto_parameterseqDefine(corto_parameterseq(_this), length, elements)

/* primitive */
CORTO_EXPORT corto_primitive _corto_primitiveCreate(corto_width width);
#define corto_primitiveCreate(width) _corto_primitiveCreate(width)
#define corto_primitiveCreate_auto(_id, width) corto_primitive _id = corto_primitiveCreate(width); (void)_id
CORTO_EXPORT corto_primitive _corto_primitiveCreateChild(corto_object _parent, corto_string _id, corto_width width);
#define corto_primitiveCreateChild(_parent, _id, width) _corto_primitiveCreateChild(_parent, _id, width)
#define corto_primitiveCreateChild_auto(_parent, _id, width) corto_primitive _id = corto_primitiveCreateChild(_parent, #_id, width); (void)_id
CORTO_EXPORT corto_int16 _corto_primitiveUpdate(corto_primitive _this, corto_width width);
#define corto_primitiveUpdate(_this, width) _corto_primitiveUpdate(corto_primitive(_this), width)
CORTO_EXPORT corto_primitive _corto_primitiveAssign(corto_primitive _this, corto_width width);
#define corto_primitive__optional_NotSet NULL
#define corto_primitive__optional_Set(width) corto_primitiveAssign((corto_primitive*)corto_ptr_new(corto_primitive_o)), width)
#define corto_primitive__optional_SetCond(cond, width) cond ? corto_primitiveAssign((corto_primitive*)corto_ptr_new(corto_primitive_o), width) : NULL
#define corto_primitiveUnset(_this) _this ? corto_ptr_free(_this, corto_primitive_o), 0 : 0; _this = NULL;
#define corto_primitiveAssign(_this, width) _corto_primitiveAssign(_this, width)
#define corto_primitiveSet(_this, width) _this = _this ? _this : (corto_primitive*)corto_ptr_new(corto_primitive_o); _corto_primitiveAssign(_this, width)

CORTO_EXPORT corto_primitive _corto_primitiveDeclare(void);
#define corto_primitiveDeclare() _corto_primitiveDeclare()
#define corto_primitiveDeclare_auto(_id) corto_primitive _id = corto_primitiveDeclare(); (void)_id
CORTO_EXPORT corto_primitive _corto_primitiveDeclareChild(corto_object _parent, corto_string _id);
#define corto_primitiveDeclareChild(_parent, _id) _corto_primitiveDeclareChild(_parent, _id)
#define corto_primitiveDeclareChild_auto(_parent, _id) corto_primitive _id = corto_primitiveDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_primitiveDefine(corto_primitive _this, corto_width width);
#define corto_primitiveDefine(_this, width) _corto_primitiveDefine(corto_primitive(_this), width)

/* primitiveKind */
CORTO_EXPORT corto_primitiveKind* _corto_primitiveKindCreate(corto_primitiveKind value);
#define corto_primitiveKindCreate(value) _corto_primitiveKindCreate(value)
#define corto_primitiveKindCreate_auto(_id, value) corto_primitiveKind* _id = corto_primitiveKindCreate(value); (void)_id
CORTO_EXPORT corto_primitiveKind* _corto_primitiveKindCreateChild(corto_object _parent, corto_string _id, corto_primitiveKind value);
#define corto_primitiveKindCreateChild(_parent, _id, value) _corto_primitiveKindCreateChild(_parent, _id, value)
#define corto_primitiveKindCreateChild_auto(_parent, _id, value) corto_primitiveKind* _id = corto_primitiveKindCreateChild(_parent, #_id, value); (void)_id
CORTO_EXPORT corto_int16 _corto_primitiveKindUpdate(corto_primitiveKind* _this, corto_primitiveKind value);
#define corto_primitiveKindUpdate(_this, value) _corto_primitiveKindUpdate(corto_primitiveKind(_this), value)
CORTO_EXPORT corto_primitiveKind* _corto_primitiveKindAssign(corto_primitiveKind* _this, corto_primitiveKind value);
#define corto_primitiveKind__optional_NotSet NULL
#define corto_primitiveKind__optional_Set(value) corto_primitiveKindAssign((corto_primitiveKind*)corto_ptr_new(corto_primitiveKind_o)), value)
#define corto_primitiveKind__optional_SetCond(cond, value) cond ? corto_primitiveKindAssign((corto_primitiveKind*)corto_ptr_new(corto_primitiveKind_o), value) : NULL
#define corto_primitiveKindUnset(_this) _this ? corto_ptr_free(_this, corto_primitiveKind_o), 0 : 0; _this = NULL;
#define corto_primitiveKindAssign(_this, value) _corto_primitiveKindAssign(_this, value)
#define corto_primitiveKindSet(_this, value) _this = _this ? _this : (corto_primitiveKind*)corto_ptr_new(corto_primitiveKind_o); _corto_primitiveKindAssign(_this, value)

CORTO_EXPORT corto_primitiveKind* _corto_primitiveKindDeclare(void);
#define corto_primitiveKindDeclare() _corto_primitiveKindDeclare()
#define corto_primitiveKindDeclare_auto(_id) corto_primitiveKind* _id = corto_primitiveKindDeclare(); (void)_id
CORTO_EXPORT corto_primitiveKind* _corto_primitiveKindDeclareChild(corto_object _parent, corto_string _id);
#define corto_primitiveKindDeclareChild(_parent, _id) _corto_primitiveKindDeclareChild(_parent, _id)
#define corto_primitiveKindDeclareChild_auto(_parent, _id) corto_primitiveKind* _id = corto_primitiveKindDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_primitiveKindDefine(corto_primitiveKind* _this, corto_primitiveKind value);
#define corto_primitiveKindDefine(_this, value) _corto_primitiveKindDefine(corto_primitiveKind(_this), value)

/* procedure */
CORTO_EXPORT corto_procedure _corto_procedureCreate(bool hasThis, corto_type thisType);
#define corto_procedureCreate(hasThis, thisType) _corto_procedureCreate(hasThis, corto_type(thisType))
#define corto_procedureCreate_auto(_id, hasThis, thisType) corto_procedure _id = corto_procedureCreate(hasThis, thisType); (void)_id
CORTO_EXPORT corto_procedure _corto_procedureCreateChild(corto_object _parent, corto_string _id, bool hasThis, corto_type thisType);
#define corto_procedureCreateChild(_parent, _id, hasThis, thisType) _corto_procedureCreateChild(_parent, _id, hasThis, corto_type(thisType))
#define corto_procedureCreateChild_auto(_parent, _id, hasThis, thisType) corto_procedure _id = corto_procedureCreateChild(_parent, #_id, hasThis, thisType); (void)_id
CORTO_EXPORT corto_int16 _corto_procedureUpdate(corto_procedure _this, bool hasThis, corto_type thisType);
#define corto_procedureUpdate(_this, hasThis, thisType) _corto_procedureUpdate(corto_procedure(_this), hasThis, corto_type(thisType))
CORTO_EXPORT corto_procedure _corto_procedureAssign(corto_procedure _this, bool hasThis, corto_type thisType);
#define corto_procedure__optional_NotSet NULL
#define corto_procedure__optional_Set(hasThis, thisType) corto_procedureAssign((corto_procedure*)corto_ptr_new(corto_procedure_o)), hasThis, thisType)
#define corto_procedure__optional_SetCond(cond, hasThis, thisType) cond ? corto_procedureAssign((corto_procedure*)corto_ptr_new(corto_procedure_o), hasThis, thisType) : NULL
#define corto_procedureUnset(_this) _this ? corto_ptr_free(_this, corto_procedure_o), 0 : 0; _this = NULL;
#define corto_procedureAssign(_this, hasThis, thisType) _corto_procedureAssign(_this, hasThis, corto_type(thisType))
#define corto_procedureSet(_this, hasThis, thisType) _this = _this ? _this : (corto_procedure*)corto_ptr_new(corto_procedure_o); _corto_procedureAssign(_this, hasThis, corto_type(thisType))

CORTO_EXPORT corto_procedure _corto_procedureDeclare(void);
#define corto_procedureDeclare() _corto_procedureDeclare()
#define corto_procedureDeclare_auto(_id) corto_procedure _id = corto_procedureDeclare(); (void)_id
CORTO_EXPORT corto_procedure _corto_procedureDeclareChild(corto_object _parent, corto_string _id);
#define corto_procedureDeclareChild(_parent, _id) _corto_procedureDeclareChild(_parent, _id)
#define corto_procedureDeclareChild_auto(_parent, _id) corto_procedure _id = corto_procedureDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_procedureDefine(corto_procedure _this, bool hasThis, corto_type thisType);
#define corto_procedureDefine(_this, hasThis, thisType) _corto_procedureDefine(corto_procedure(_this), hasThis, corto_type(thisType))

/* quantity */
CORTO_EXPORT corto_quantity _corto_quantityCreate(corto_string description);
#define corto_quantityCreate(description) _corto_quantityCreate(description)
#define corto_quantityCreate_auto(_id, description) corto_quantity _id = corto_quantityCreate(description); (void)_id
CORTO_EXPORT corto_quantity _corto_quantityCreateChild(corto_object _parent, corto_string _id, corto_string description);
#define corto_quantityCreateChild(_parent, _id, description) _corto_quantityCreateChild(_parent, _id, description)
#define corto_quantityCreateChild_auto(_parent, _id, description) corto_quantity _id = corto_quantityCreateChild(_parent, #_id, description); (void)_id
CORTO_EXPORT corto_int16 _corto_quantityUpdate(corto_quantity _this, corto_string description);
#define corto_quantityUpdate(_this, description) _corto_quantityUpdate(corto_quantity(_this), description)
CORTO_EXPORT corto_quantity _corto_quantityAssign(corto_quantity _this, corto_string description);
#define corto_quantity__optional_NotSet NULL
#define corto_quantity__optional_Set(description) corto_quantityAssign((corto_quantity*)corto_ptr_new(corto_quantity_o)), description)
#define corto_quantity__optional_SetCond(cond, description) cond ? corto_quantityAssign((corto_quantity*)corto_ptr_new(corto_quantity_o), description) : NULL
#define corto_quantityUnset(_this) _this ? corto_ptr_free(_this, corto_quantity_o), 0 : 0; _this = NULL;
#define corto_quantityAssign(_this, description) _corto_quantityAssign(_this, description)
#define corto_quantitySet(_this, description) _this = _this ? _this : (corto_quantity*)corto_ptr_new(corto_quantity_o); _corto_quantityAssign(_this, description)

CORTO_EXPORT corto_quantity _corto_quantityDeclare(void);
#define corto_quantityDeclare() _corto_quantityDeclare()
#define corto_quantityDeclare_auto(_id) corto_quantity _id = corto_quantityDeclare(); (void)_id
CORTO_EXPORT corto_quantity _corto_quantityDeclareChild(corto_object _parent, corto_string _id);
#define corto_quantityDeclareChild(_parent, _id) _corto_quantityDeclareChild(_parent, _id)
#define corto_quantityDeclareChild_auto(_parent, _id) corto_quantity _id = corto_quantityDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_quantityDefine(corto_quantity _this, corto_string description);
#define corto_quantityDefine(_this, description) _corto_quantityDefine(corto_quantity(_this), description)

/* sequence */
CORTO_EXPORT corto_sequence _corto_sequenceCreate(corto_type elementType, uint32_t max);
#define corto_sequenceCreate(elementType, max) _corto_sequenceCreate(corto_type(elementType), max)
#define corto_sequenceCreate_auto(_id, elementType, max) corto_sequence _id = corto_sequenceCreate(elementType, max); (void)_id
CORTO_EXPORT corto_sequence _corto_sequenceCreateChild(corto_object _parent, corto_string _id, corto_type elementType, uint32_t max);
#define corto_sequenceCreateChild(_parent, _id, elementType, max) _corto_sequenceCreateChild(_parent, _id, corto_type(elementType), max)
#define corto_sequenceCreateChild_auto(_parent, _id, elementType, max) corto_sequence _id = corto_sequenceCreateChild(_parent, #_id, elementType, max); (void)_id
CORTO_EXPORT corto_int16 _corto_sequenceUpdate(corto_sequence _this, corto_type elementType, uint32_t max);
#define corto_sequenceUpdate(_this, elementType, max) _corto_sequenceUpdate(corto_sequence(_this), corto_type(elementType), max)
CORTO_EXPORT corto_sequence _corto_sequenceAssign(corto_sequence _this, corto_type elementType, uint32_t max);
#define corto_sequence__optional_NotSet NULL
#define corto_sequence__optional_Set(elementType, max) corto_sequenceAssign((corto_sequence*)corto_ptr_new(corto_sequence_o)), elementType, max)
#define corto_sequence__optional_SetCond(cond, elementType, max) cond ? corto_sequenceAssign((corto_sequence*)corto_ptr_new(corto_sequence_o), elementType, max) : NULL
#define corto_sequenceUnset(_this) _this ? corto_ptr_free(_this, corto_sequence_o), 0 : 0; _this = NULL;
#define corto_sequenceAssign(_this, elementType, max) _corto_sequenceAssign(_this, corto_type(elementType), max)
#define corto_sequenceSet(_this, elementType, max) _this = _this ? _this : (corto_sequence*)corto_ptr_new(corto_sequence_o); _corto_sequenceAssign(_this, corto_type(elementType), max)

CORTO_EXPORT corto_sequence _corto_sequenceDeclare(void);
#define corto_sequenceDeclare() _corto_sequenceDeclare()
#define corto_sequenceDeclare_auto(_id) corto_sequence _id = corto_sequenceDeclare(); (void)_id
CORTO_EXPORT corto_sequence _corto_sequenceDeclareChild(corto_object _parent, corto_string _id);
#define corto_sequenceDeclareChild(_parent, _id) _corto_sequenceDeclareChild(_parent, _id)
#define corto_sequenceDeclareChild_auto(_parent, _id) corto_sequence _id = corto_sequenceDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_sequenceDefine(corto_sequence _this, corto_type elementType, uint32_t max);
#define corto_sequenceDefine(_this, elementType, max) _corto_sequenceDefine(corto_sequence(_this), corto_type(elementType), max)

/* state */
CORTO_EXPORT corto_state* _corto_stateCreate(corto_state value);
#define corto_stateCreate(value) _corto_stateCreate(value)
#define corto_stateCreate_auto(_id, value) corto_state* _id = corto_stateCreate(value); (void)_id
CORTO_EXPORT corto_state* _corto_stateCreateChild(corto_object _parent, corto_string _id, corto_state value);
#define corto_stateCreateChild(_parent, _id, value) _corto_stateCreateChild(_parent, _id, value)
#define corto_stateCreateChild_auto(_parent, _id, value) corto_state* _id = corto_stateCreateChild(_parent, #_id, value); (void)_id
CORTO_EXPORT corto_int16 _corto_stateUpdate(corto_state* _this, corto_state value);
#define corto_stateUpdate(_this, value) _corto_stateUpdate(corto_state(_this), value)
CORTO_EXPORT corto_state* _corto_stateAssign(corto_state* _this, corto_state value);
#define corto_state__optional_NotSet NULL
#define corto_state__optional_Set(value) corto_stateAssign((corto_state*)corto_ptr_new(corto_state_o)), value)
#define corto_state__optional_SetCond(cond, value) cond ? corto_stateAssign((corto_state*)corto_ptr_new(corto_state_o), value) : NULL
#define corto_stateUnset(_this) _this ? corto_ptr_free(_this, corto_state_o), 0 : 0; _this = NULL;
#define corto_stateAssign(_this, value) _corto_stateAssign(_this, value)
#define corto_stateSet(_this, value) _this = _this ? _this : (corto_state*)corto_ptr_new(corto_state_o); _corto_stateAssign(_this, value)

CORTO_EXPORT corto_state* _corto_stateDeclare(void);
#define corto_stateDeclare() _corto_stateDeclare()
#define corto_stateDeclare_auto(_id) corto_state* _id = corto_stateDeclare(); (void)_id
CORTO_EXPORT corto_state* _corto_stateDeclareChild(corto_object _parent, corto_string _id);
#define corto_stateDeclareChild(_parent, _id) _corto_stateDeclareChild(_parent, _id)
#define corto_stateDeclareChild_auto(_parent, _id) corto_state* _id = corto_stateDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_stateDefine(corto_state* _this, corto_state value);
#define corto_stateDefine(_this, value) _corto_stateDefine(corto_state(_this), value)

/* string */
CORTO_EXPORT corto_string* _corto_stringCreate(corto_string value);
#define corto_stringCreate(value) _corto_stringCreate(value)
#define corto_stringCreate_auto(_id, value) corto_string* _id = corto_stringCreate(value); (void)_id
CORTO_EXPORT corto_string* _corto_stringCreateChild(corto_object _parent, corto_string _id, corto_string value);
#define corto_stringCreateChild(_parent, _id, value) _corto_stringCreateChild(_parent, _id, value)
#define corto_stringCreateChild_auto(_parent, _id, value) corto_string* _id = corto_stringCreateChild(_parent, #_id, value); (void)_id
CORTO_EXPORT corto_int16 _corto_stringUpdate(corto_string* _this, corto_string value);
#define corto_stringUpdate(_this, value) _corto_stringUpdate(corto_string(_this), value)
CORTO_EXPORT corto_string* _corto_stringAssign(corto_string* _this, corto_string value);
#define corto_string__optional_NotSet NULL
#define corto_string__optional_Set(value) corto_stringAssign((corto_string*)corto_ptr_new(corto_string_o)), value)
#define corto_string__optional_SetCond(cond, value) cond ? corto_stringAssign((corto_string*)corto_ptr_new(corto_string_o), value) : NULL
#define corto_stringUnset(_this) _this ? corto_ptr_free(_this, corto_string_o), 0 : 0; _this = NULL;
#define corto_stringAssign(_this, value) _corto_stringAssign(_this, value)
#define corto_stringSet(_this, value) _this = _this ? _this : (corto_string*)corto_ptr_new(corto_string_o); _corto_stringAssign(_this, value)

CORTO_EXPORT corto_string* _corto_stringDeclare(void);
#define corto_stringDeclare() _corto_stringDeclare()
#define corto_stringDeclare_auto(_id) corto_string* _id = corto_stringDeclare(); (void)_id
CORTO_EXPORT corto_string* _corto_stringDeclareChild(corto_object _parent, corto_string _id);
#define corto_stringDeclareChild(_parent, _id) _corto_stringDeclareChild(_parent, _id)
#define corto_stringDeclareChild_auto(_parent, _id) corto_string* _id = corto_stringDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_stringDefine(corto_string* _this, corto_string value);
#define corto_stringDefine(_this, value) _corto_stringDefine(corto_string(_this), value)

/* stringlist */
CORTO_EXPORT corto_stringlist* _corto_stringlistCreate(corto_uint32 length, corto_string* elements);
#define corto_stringlistCreate(length, elements) _corto_stringlistCreate(length, elements)
#define corto_stringlistCreate_auto(_id, length, elements) corto_stringlist* _id = corto_stringlistCreate(length, elements); (void)_id
CORTO_EXPORT corto_stringlist* _corto_stringlistCreateChild(corto_object _parent, corto_string _id, corto_uint32 length, corto_string* elements);
#define corto_stringlistCreateChild(_parent, _id, length, elements) _corto_stringlistCreateChild(_parent, _id, length, elements)
#define corto_stringlistCreateChild_auto(_parent, _id, length, elements) corto_stringlist* _id = corto_stringlistCreateChild(_parent, #_id, length, elements); (void)_id
CORTO_EXPORT corto_int16 _corto_stringlistUpdate(corto_stringlist* _this, corto_uint32 length, corto_string* elements);
#define corto_stringlistUpdate(_this, length, elements) _corto_stringlistUpdate(corto_stringlist(_this), length, elements)
CORTO_EXPORT corto_stringlist* _corto_stringlistAssign(corto_stringlist* _this, corto_uint32 length, corto_string* elements);
#define corto_stringlist__optional_NotSet NULL
#define corto_stringlist__optional_Set(length, elements) corto_stringlistAssign((corto_stringlist*)corto_ptr_new(corto_stringlist_o)), length, elements)
#define corto_stringlist__optional_SetCond(cond, length, elements) cond ? corto_stringlistAssign((corto_stringlist*)corto_ptr_new(corto_stringlist_o), length, elements) : NULL
#define corto_stringlistUnset(_this) _this ? corto_ptr_free(_this, corto_stringlist_o), 0 : 0; _this = NULL;
#define corto_stringlistAssign(_this, length, elements) _corto_stringlistAssign(_this, length, elements)
#define corto_stringlistSet(_this, length, elements) _this = _this ? _this : (corto_stringlist*)corto_ptr_new(corto_stringlist_o); _corto_stringlistAssign(_this, length, elements)

CORTO_EXPORT corto_stringlist* _corto_stringlistDeclare(void);
#define corto_stringlistDeclare() _corto_stringlistDeclare()
#define corto_stringlistDeclare_auto(_id) corto_stringlist* _id = corto_stringlistDeclare(); (void)_id
CORTO_EXPORT corto_stringlist* _corto_stringlistDeclareChild(corto_object _parent, corto_string _id);
#define corto_stringlistDeclareChild(_parent, _id) _corto_stringlistDeclareChild(_parent, _id)
#define corto_stringlistDeclareChild_auto(_parent, _id) corto_stringlist* _id = corto_stringlistDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_stringlistDefine(corto_stringlist* _this, corto_uint32 length, corto_string* elements);
#define corto_stringlistDefine(_this, length, elements) _corto_stringlistDefine(corto_stringlist(_this), length, elements)

/* stringseq */
CORTO_EXPORT corto_stringseq* _corto_stringseqCreate(corto_uint32 length, corto_string* elements);
#define corto_stringseqCreate(length, elements) _corto_stringseqCreate(length, elements)
#define corto_stringseqCreate_auto(_id, length, elements) corto_stringseq* _id = corto_stringseqCreate(length, elements); (void)_id
CORTO_EXPORT corto_stringseq* _corto_stringseqCreateChild(corto_object _parent, corto_string _id, corto_uint32 length, corto_string* elements);
#define corto_stringseqCreateChild(_parent, _id, length, elements) _corto_stringseqCreateChild(_parent, _id, length, elements)
#define corto_stringseqCreateChild_auto(_parent, _id, length, elements) corto_stringseq* _id = corto_stringseqCreateChild(_parent, #_id, length, elements); (void)_id
CORTO_EXPORT corto_int16 _corto_stringseqUpdate(corto_stringseq* _this, corto_uint32 length, corto_string* elements);
#define corto_stringseqUpdate(_this, length, elements) _corto_stringseqUpdate(corto_stringseq(_this), length, elements)
CORTO_EXPORT corto_stringseq* _corto_stringseqAssign(corto_stringseq* _this, corto_uint32 length, corto_string* elements);
#define corto_stringseq__optional_NotSet NULL
#define corto_stringseq__optional_Set(length, elements) corto_stringseqAssign((corto_stringseq*)corto_ptr_new(corto_stringseq_o)), length, elements)
#define corto_stringseq__optional_SetCond(cond, length, elements) cond ? corto_stringseqAssign((corto_stringseq*)corto_ptr_new(corto_stringseq_o), length, elements) : NULL
#define corto_stringseqUnset(_this) _this ? corto_ptr_free(_this, corto_stringseq_o), 0 : 0; _this = NULL;
#define corto_stringseqAssign(_this, length, elements) _corto_stringseqAssign(_this, length, elements)
#define corto_stringseqSet(_this, length, elements) _this = _this ? _this : (corto_stringseq*)corto_ptr_new(corto_stringseq_o); _corto_stringseqAssign(_this, length, elements)

CORTO_EXPORT corto_stringseq* _corto_stringseqDeclare(void);
#define corto_stringseqDeclare() _corto_stringseqDeclare()
#define corto_stringseqDeclare_auto(_id) corto_stringseq* _id = corto_stringseqDeclare(); (void)_id
CORTO_EXPORT corto_stringseq* _corto_stringseqDeclareChild(corto_object _parent, corto_string _id);
#define corto_stringseqDeclareChild(_parent, _id) _corto_stringseqDeclareChild(_parent, _id)
#define corto_stringseqDeclareChild_auto(_parent, _id) corto_stringseq* _id = corto_stringseqDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_stringseqDefine(corto_stringseq* _this, corto_uint32 length, corto_string* elements);
#define corto_stringseqDefine(_this, length, elements) _corto_stringseqDefine(corto_stringseq(_this), length, elements)

/* struct */
CORTO_EXPORT corto_struct _corto_structCreate(corto_interface base, corto_modifier baseAccess);
#define corto_structCreate(base, baseAccess) _corto_structCreate(corto_interface(base), baseAccess)
#define corto_structCreate_auto(_id, base, baseAccess) corto_struct _id = corto_structCreate(base, baseAccess); (void)_id
CORTO_EXPORT corto_struct _corto_structCreateChild(corto_object _parent, corto_string _id, corto_interface base, corto_modifier baseAccess);
#define corto_structCreateChild(_parent, _id, base, baseAccess) _corto_structCreateChild(_parent, _id, corto_interface(base), baseAccess)
#define corto_structCreateChild_auto(_parent, _id, base, baseAccess) corto_struct _id = corto_structCreateChild(_parent, #_id, base, baseAccess); (void)_id
CORTO_EXPORT corto_int16 _corto_structUpdate(corto_struct _this, corto_interface base, corto_modifier baseAccess);
#define corto_structUpdate(_this, base, baseAccess) _corto_structUpdate(corto_struct(_this), corto_interface(base), baseAccess)
CORTO_EXPORT corto_struct _corto_structAssign(corto_struct _this, corto_interface base, corto_modifier baseAccess);
#define corto_struct__optional_NotSet NULL
#define corto_struct__optional_Set(base, baseAccess) corto_structAssign((corto_struct*)corto_ptr_new(corto_struct_o)), base, baseAccess)
#define corto_struct__optional_SetCond(cond, base, baseAccess) cond ? corto_structAssign((corto_struct*)corto_ptr_new(corto_struct_o), base, baseAccess) : NULL
#define corto_structUnset(_this) _this ? corto_ptr_free(_this, corto_struct_o), 0 : 0; _this = NULL;
#define corto_structAssign(_this, base, baseAccess) _corto_structAssign(_this, corto_interface(base), baseAccess)
#define corto_structSet(_this, base, baseAccess) _this = _this ? _this : (corto_struct*)corto_ptr_new(corto_struct_o); _corto_structAssign(_this, corto_interface(base), baseAccess)

CORTO_EXPORT corto_struct _corto_structDeclare(void);
#define corto_structDeclare() _corto_structDeclare()
#define corto_structDeclare_auto(_id) corto_struct _id = corto_structDeclare(); (void)_id
CORTO_EXPORT corto_struct _corto_structDeclareChild(corto_object _parent, corto_string _id);
#define corto_structDeclareChild(_parent, _id) _corto_structDeclareChild(_parent, _id)
#define corto_structDeclareChild_auto(_parent, _id) corto_struct _id = corto_structDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_structDefine(corto_struct _this, corto_interface base, corto_modifier baseAccess);
#define corto_structDefine(_this, base, baseAccess) _corto_structDefine(corto_struct(_this), corto_interface(base), baseAccess)

/* table */
CORTO_EXPORT corto_table _corto_tableCreate(corto_interface base, corto_modifier baseAccess, corto_interfaceseq implements, corto_type type, corto_string value);
#define corto_tableCreate(base, baseAccess, implements, type, value) _corto_tableCreate(corto_interface(base), baseAccess, implements, corto_type(type), value)
#define corto_tableCreate_auto(_id, base, baseAccess, implements, type, value) corto_table _id = corto_tableCreate(base, baseAccess, implements, type, value); (void)_id
CORTO_EXPORT corto_table _corto_tableCreateChild(corto_object _parent, corto_string _id, corto_interface base, corto_modifier baseAccess, corto_interfaceseq implements, corto_type type, corto_string value);
#define corto_tableCreateChild(_parent, _id, base, baseAccess, implements, type, value) _corto_tableCreateChild(_parent, _id, corto_interface(base), baseAccess, implements, corto_type(type), value)
#define corto_tableCreateChild_auto(_parent, _id, base, baseAccess, implements, type, value) corto_table _id = corto_tableCreateChild(_parent, #_id, base, baseAccess, implements, type, value); (void)_id
CORTO_EXPORT corto_int16 _corto_tableUpdate(corto_table _this, corto_interface base, corto_modifier baseAccess, corto_interfaceseq implements, corto_type type, corto_string value);
#define corto_tableUpdate(_this, base, baseAccess, implements, type, value) _corto_tableUpdate(corto_table(_this), corto_interface(base), baseAccess, implements, corto_type(type), value)
CORTO_EXPORT corto_table _corto_tableAssign(corto_table _this, corto_interface base, corto_modifier baseAccess, corto_interfaceseq implements, corto_type type, corto_string value);
#define corto_table__optional_NotSet NULL
#define corto_table__optional_Set(base, baseAccess, implements, type, value) corto_tableAssign((corto_table*)corto_ptr_new(corto_table_o)), base, baseAccess, implements, type, value)
#define corto_table__optional_SetCond(cond, base, baseAccess, implements, type, value) cond ? corto_tableAssign((corto_table*)corto_ptr_new(corto_table_o), base, baseAccess, implements, type, value) : NULL
#define corto_tableUnset(_this) _this ? corto_ptr_free(_this, corto_table_o), 0 : 0; _this = NULL;
#define corto_tableAssign(_this, base, baseAccess, implements, type, value) _corto_tableAssign(_this, corto_interface(base), baseAccess, implements, corto_type(type), value)
#define corto_tableSet(_this, base, baseAccess, implements, type, value) _this = _this ? _this : (corto_table*)corto_ptr_new(corto_table_o); _corto_tableAssign(_this, corto_interface(base), baseAccess, implements, corto_type(type), value)

CORTO_EXPORT corto_table _corto_tableDeclare(void);
#define corto_tableDeclare() _corto_tableDeclare()
#define corto_tableDeclare_auto(_id) corto_table _id = corto_tableDeclare(); (void)_id
CORTO_EXPORT corto_table _corto_tableDeclareChild(corto_object _parent, corto_string _id);
#define corto_tableDeclareChild(_parent, _id) _corto_tableDeclareChild(_parent, _id)
#define corto_tableDeclareChild_auto(_parent, _id) corto_table _id = corto_tableDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_tableDefine(corto_table _this, corto_interface base, corto_modifier baseAccess, corto_interfaceseq implements, corto_type type, corto_string value);
#define corto_tableDefine(_this, base, baseAccess, implements, type, value) _corto_tableDefine(corto_table(_this), corto_interface(base), baseAccess, implements, corto_type(type), value)

/* tablescope */
CORTO_EXPORT corto_tablescope _corto_tablescopeCreate(corto_struct type);
#define corto_tablescopeCreate(type) _corto_tablescopeCreate(corto_struct(type))
#define corto_tablescopeCreate_auto(_id, type) corto_tablescope _id = corto_tablescopeCreate(type); (void)_id
CORTO_EXPORT corto_tablescope _corto_tablescopeCreateChild(corto_object _parent, corto_string _id, corto_struct type);
#define corto_tablescopeCreateChild(_parent, _id, type) _corto_tablescopeCreateChild(_parent, _id, corto_struct(type))
#define corto_tablescopeCreateChild_auto(_parent, _id, type) corto_tablescope _id = corto_tablescopeCreateChild(_parent, #_id, type); (void)_id
CORTO_EXPORT corto_int16 _corto_tablescopeUpdate(corto_tablescope _this, corto_struct type);
#define corto_tablescopeUpdate(_this, type) _corto_tablescopeUpdate(corto_tablescope(_this), corto_struct(type))
CORTO_EXPORT corto_tablescope _corto_tablescopeAssign(corto_tablescope _this, corto_struct type);
#define corto_tablescope__optional_NotSet NULL
#define corto_tablescope__optional_Set(type) corto_tablescopeAssign((corto_tablescope*)corto_ptr_new(corto_tablescope_o)), type)
#define corto_tablescope__optional_SetCond(cond, type) cond ? corto_tablescopeAssign((corto_tablescope*)corto_ptr_new(corto_tablescope_o), type) : NULL
#define corto_tablescopeUnset(_this) _this ? corto_ptr_free(_this, corto_tablescope_o), 0 : 0; _this = NULL;
#define corto_tablescopeAssign(_this, type) _corto_tablescopeAssign(_this, corto_struct(type))
#define corto_tablescopeSet(_this, type) _this = _this ? _this : (corto_tablescope*)corto_ptr_new(corto_tablescope_o); _corto_tablescopeAssign(_this, corto_struct(type))

CORTO_EXPORT corto_tablescope _corto_tablescopeDeclare(void);
#define corto_tablescopeDeclare() _corto_tablescopeDeclare()
#define corto_tablescopeDeclare_auto(_id) corto_tablescope _id = corto_tablescopeDeclare(); (void)_id
CORTO_EXPORT corto_tablescope _corto_tablescopeDeclareChild(corto_object _parent, corto_string _id);
#define corto_tablescopeDeclareChild(_parent, _id) _corto_tablescopeDeclareChild(_parent, _id)
#define corto_tablescopeDeclareChild_auto(_parent, _id) corto_tablescope _id = corto_tablescopeDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_tablescopeDefine(corto_tablescope _this, corto_struct type);
#define corto_tablescopeDefine(_this, type) _corto_tablescopeDefine(corto_tablescope(_this), corto_struct(type))

/* target */
CORTO_EXPORT corto_target _corto_targetCreate(corto_type type);
#define corto_targetCreate(type) _corto_targetCreate(corto_type(type))
#define corto_targetCreate_auto(_id, type) corto_target _id = corto_targetCreate(type); (void)_id
CORTO_EXPORT corto_target _corto_targetCreateChild(corto_object _parent, corto_string _id, corto_type type);
#define corto_targetCreateChild(_parent, _id, type) _corto_targetCreateChild(_parent, _id, corto_type(type))
#define corto_targetCreateChild_auto(_parent, _id, type) corto_target _id = corto_targetCreateChild(_parent, #_id, type); (void)_id
CORTO_EXPORT corto_int16 _corto_targetUpdate(corto_target _this, corto_type type);
#define corto_targetUpdate(_this, type) _corto_targetUpdate(corto_target(_this), corto_type(type))
CORTO_EXPORT corto_target _corto_targetAssign(corto_target _this, corto_type type);
#define corto_target__optional_NotSet NULL
#define corto_target__optional_Set(type) corto_targetAssign((corto_target*)corto_ptr_new(corto_target_o)), type)
#define corto_target__optional_SetCond(cond, type) cond ? corto_targetAssign((corto_target*)corto_ptr_new(corto_target_o), type) : NULL
#define corto_targetUnset(_this) _this ? corto_ptr_free(_this, corto_target_o), 0 : 0; _this = NULL;
#define corto_targetAssign(_this, type) _corto_targetAssign(_this, corto_type(type))
#define corto_targetSet(_this, type) _this = _this ? _this : (corto_target*)corto_ptr_new(corto_target_o); _corto_targetAssign(_this, corto_type(type))

CORTO_EXPORT corto_target _corto_targetDeclare(void);
#define corto_targetDeclare() _corto_targetDeclare()
#define corto_targetDeclare_auto(_id) corto_target _id = corto_targetDeclare(); (void)_id
CORTO_EXPORT corto_target _corto_targetDeclareChild(corto_object _parent, corto_string _id);
#define corto_targetDeclareChild(_parent, _id) _corto_targetDeclareChild(_parent, _id)
#define corto_targetDeclareChild_auto(_parent, _id) corto_target _id = corto_targetDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_targetDefine(corto_target _this, corto_type type);
#define corto_targetDefine(_this, type) _corto_targetDefine(corto_target(_this), corto_type(type))

/* text */
CORTO_EXPORT corto_text _corto_textCreate(corto_width charWidth, uint64_t length);
#define corto_textCreate(charWidth, length) _corto_textCreate(charWidth, length)
#define corto_textCreate_auto(_id, charWidth, length) corto_text _id = corto_textCreate(charWidth, length); (void)_id
CORTO_EXPORT corto_text _corto_textCreateChild(corto_object _parent, corto_string _id, corto_width charWidth, uint64_t length);
#define corto_textCreateChild(_parent, _id, charWidth, length) _corto_textCreateChild(_parent, _id, charWidth, length)
#define corto_textCreateChild_auto(_parent, _id, charWidth, length) corto_text _id = corto_textCreateChild(_parent, #_id, charWidth, length); (void)_id
CORTO_EXPORT corto_int16 _corto_textUpdate(corto_text _this, corto_width charWidth, uint64_t length);
#define corto_textUpdate(_this, charWidth, length) _corto_textUpdate(corto_text(_this), charWidth, length)
CORTO_EXPORT corto_text _corto_textAssign(corto_text _this, corto_width charWidth, uint64_t length);
#define corto_text__optional_NotSet NULL
#define corto_text__optional_Set(charWidth, length) corto_textAssign((corto_text*)corto_ptr_new(corto_text_o)), charWidth, length)
#define corto_text__optional_SetCond(cond, charWidth, length) cond ? corto_textAssign((corto_text*)corto_ptr_new(corto_text_o), charWidth, length) : NULL
#define corto_textUnset(_this) _this ? corto_ptr_free(_this, corto_text_o), 0 : 0; _this = NULL;
#define corto_textAssign(_this, charWidth, length) _corto_textAssign(_this, charWidth, length)
#define corto_textSet(_this, charWidth, length) _this = _this ? _this : (corto_text*)corto_ptr_new(corto_text_o); _corto_textAssign(_this, charWidth, length)

CORTO_EXPORT corto_text _corto_textDeclare(void);
#define corto_textDeclare() _corto_textDeclare()
#define corto_textDeclare_auto(_id) corto_text _id = corto_textDeclare(); (void)_id
CORTO_EXPORT corto_text _corto_textDeclareChild(corto_object _parent, corto_string _id);
#define corto_textDeclareChild(_parent, _id) _corto_textDeclareChild(_parent, _id)
#define corto_textDeclareChild_auto(_parent, _id) corto_text _id = corto_textDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_textDefine(corto_text _this, corto_width charWidth, uint64_t length);
#define corto_textDefine(_this, charWidth, length) _corto_textDefine(corto_text(_this), charWidth, length)

/* type */
CORTO_EXPORT corto_type _corto_typeCreate(corto_typeKind kind, bool reference, corto_attr attr);
#define corto_typeCreate(kind, reference, attr) _corto_typeCreate(kind, reference, attr)
#define corto_typeCreate_auto(_id, kind, reference, attr) corto_type _id = corto_typeCreate(kind, reference, attr); (void)_id
CORTO_EXPORT corto_type _corto_typeCreateChild(corto_object _parent, corto_string _id, corto_typeKind kind, bool reference, corto_attr attr);
#define corto_typeCreateChild(_parent, _id, kind, reference, attr) _corto_typeCreateChild(_parent, _id, kind, reference, attr)
#define corto_typeCreateChild_auto(_parent, _id, kind, reference, attr) corto_type _id = corto_typeCreateChild(_parent, #_id, kind, reference, attr); (void)_id
CORTO_EXPORT corto_int16 _corto_typeUpdate(corto_type _this, corto_typeKind kind, bool reference, corto_attr attr);
#define corto_typeUpdate(_this, kind, reference, attr) _corto_typeUpdate(corto_type(_this), kind, reference, attr)
CORTO_EXPORT corto_type _corto_typeAssign(corto_type _this, corto_typeKind kind, bool reference, corto_attr attr);
#define corto_type__optional_NotSet NULL
#define corto_type__optional_Set(kind, reference, attr) corto_typeAssign((corto_type*)corto_ptr_new(corto_type_o)), kind, reference, attr)
#define corto_type__optional_SetCond(cond, kind, reference, attr) cond ? corto_typeAssign((corto_type*)corto_ptr_new(corto_type_o), kind, reference, attr) : NULL
#define corto_typeUnset(_this) _this ? corto_ptr_free(_this, corto_type_o), 0 : 0; _this = NULL;
#define corto_typeAssign(_this, kind, reference, attr) _corto_typeAssign(_this, kind, reference, attr)
#define corto_typeSet(_this, kind, reference, attr) _this = _this ? _this : (corto_type*)corto_ptr_new(corto_type_o); _corto_typeAssign(_this, kind, reference, attr)

CORTO_EXPORT corto_type _corto_typeDeclare(void);
#define corto_typeDeclare() _corto_typeDeclare()
#define corto_typeDeclare_auto(_id) corto_type _id = corto_typeDeclare(); (void)_id
CORTO_EXPORT corto_type _corto_typeDeclareChild(corto_object _parent, corto_string _id);
#define corto_typeDeclareChild(_parent, _id) _corto_typeDeclareChild(_parent, _id)
#define corto_typeDeclareChild_auto(_parent, _id) corto_type _id = corto_typeDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_typeDefine(corto_type _this, corto_typeKind kind, bool reference, corto_attr attr);
#define corto_typeDefine(_this, kind, reference, attr) _corto_typeDefine(corto_type(_this), kind, reference, attr)

/* typeKind */
CORTO_EXPORT corto_typeKind* _corto_typeKindCreate(corto_typeKind value);
#define corto_typeKindCreate(value) _corto_typeKindCreate(value)
#define corto_typeKindCreate_auto(_id, value) corto_typeKind* _id = corto_typeKindCreate(value); (void)_id
CORTO_EXPORT corto_typeKind* _corto_typeKindCreateChild(corto_object _parent, corto_string _id, corto_typeKind value);
#define corto_typeKindCreateChild(_parent, _id, value) _corto_typeKindCreateChild(_parent, _id, value)
#define corto_typeKindCreateChild_auto(_parent, _id, value) corto_typeKind* _id = corto_typeKindCreateChild(_parent, #_id, value); (void)_id
CORTO_EXPORT corto_int16 _corto_typeKindUpdate(corto_typeKind* _this, corto_typeKind value);
#define corto_typeKindUpdate(_this, value) _corto_typeKindUpdate(corto_typeKind(_this), value)
CORTO_EXPORT corto_typeKind* _corto_typeKindAssign(corto_typeKind* _this, corto_typeKind value);
#define corto_typeKind__optional_NotSet NULL
#define corto_typeKind__optional_Set(value) corto_typeKindAssign((corto_typeKind*)corto_ptr_new(corto_typeKind_o)), value)
#define corto_typeKind__optional_SetCond(cond, value) cond ? corto_typeKindAssign((corto_typeKind*)corto_ptr_new(corto_typeKind_o), value) : NULL
#define corto_typeKindUnset(_this) _this ? corto_ptr_free(_this, corto_typeKind_o), 0 : 0; _this = NULL;
#define corto_typeKindAssign(_this, value) _corto_typeKindAssign(_this, value)
#define corto_typeKindSet(_this, value) _this = _this ? _this : (corto_typeKind*)corto_ptr_new(corto_typeKind_o); _corto_typeKindAssign(_this, value)

CORTO_EXPORT corto_typeKind* _corto_typeKindDeclare(void);
#define corto_typeKindDeclare() _corto_typeKindDeclare()
#define corto_typeKindDeclare_auto(_id) corto_typeKind* _id = corto_typeKindDeclare(); (void)_id
CORTO_EXPORT corto_typeKind* _corto_typeKindDeclareChild(corto_object _parent, corto_string _id);
#define corto_typeKindDeclareChild(_parent, _id) _corto_typeKindDeclareChild(_parent, _id)
#define corto_typeKindDeclareChild_auto(_parent, _id) corto_typeKind* _id = corto_typeKindDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_typeKindDefine(corto_typeKind* _this, corto_typeKind value);
#define corto_typeKindDefine(_this, value) _corto_typeKindDefine(corto_typeKind(_this), value)

/* typeOptions */
CORTO_EXPORT corto_typeOptions* _corto_typeOptionsCreate(corto_type parentType, corto_state parentState, corto_type defaultType, corto_type defaultProcedureType);
#define corto_typeOptionsCreate(parentType, parentState, defaultType, defaultProcedureType) _corto_typeOptionsCreate(corto_type(parentType), parentState, corto_type(defaultType), corto_type(defaultProcedureType))
#define corto_typeOptionsCreate_auto(_id, parentType, parentState, defaultType, defaultProcedureType) corto_typeOptions* _id = corto_typeOptionsCreate(parentType, parentState, defaultType, defaultProcedureType); (void)_id
CORTO_EXPORT corto_typeOptions* _corto_typeOptionsCreateChild(corto_object _parent, corto_string _id, corto_type parentType, corto_state parentState, corto_type defaultType, corto_type defaultProcedureType);
#define corto_typeOptionsCreateChild(_parent, _id, parentType, parentState, defaultType, defaultProcedureType) _corto_typeOptionsCreateChild(_parent, _id, corto_type(parentType), parentState, corto_type(defaultType), corto_type(defaultProcedureType))
#define corto_typeOptionsCreateChild_auto(_parent, _id, parentType, parentState, defaultType, defaultProcedureType) corto_typeOptions* _id = corto_typeOptionsCreateChild(_parent, #_id, parentType, parentState, defaultType, defaultProcedureType); (void)_id
CORTO_EXPORT corto_int16 _corto_typeOptionsUpdate(corto_typeOptions* _this, corto_type parentType, corto_state parentState, corto_type defaultType, corto_type defaultProcedureType);
#define corto_typeOptionsUpdate(_this, parentType, parentState, defaultType, defaultProcedureType) _corto_typeOptionsUpdate(corto_typeOptions(_this), corto_type(parentType), parentState, corto_type(defaultType), corto_type(defaultProcedureType))
CORTO_EXPORT corto_typeOptions* _corto_typeOptionsAssign(corto_typeOptions* _this, corto_type parentType, corto_state parentState, corto_type defaultType, corto_type defaultProcedureType);
#define corto_typeOptions__optional_NotSet NULL
#define corto_typeOptions__optional_Set(parentType, parentState, defaultType, defaultProcedureType) corto_typeOptionsAssign((corto_typeOptions*)corto_ptr_new(corto_typeOptions_o)), parentType, parentState, defaultType, defaultProcedureType)
#define corto_typeOptions__optional_SetCond(cond, parentType, parentState, defaultType, defaultProcedureType) cond ? corto_typeOptionsAssign((corto_typeOptions*)corto_ptr_new(corto_typeOptions_o), parentType, parentState, defaultType, defaultProcedureType) : NULL
#define corto_typeOptionsUnset(_this) _this ? corto_ptr_free(_this, corto_typeOptions_o), 0 : 0; _this = NULL;
#define corto_typeOptionsAssign(_this, parentType, parentState, defaultType, defaultProcedureType) _corto_typeOptionsAssign(_this, corto_type(parentType), parentState, corto_type(defaultType), corto_type(defaultProcedureType))
#define corto_typeOptionsSet(_this, parentType, parentState, defaultType, defaultProcedureType) _this = _this ? _this : (corto_typeOptions*)corto_ptr_new(corto_typeOptions_o); _corto_typeOptionsAssign(_this, corto_type(parentType), parentState, corto_type(defaultType), corto_type(defaultProcedureType))

CORTO_EXPORT corto_typeOptions* _corto_typeOptionsDeclare(void);
#define corto_typeOptionsDeclare() _corto_typeOptionsDeclare()
#define corto_typeOptionsDeclare_auto(_id) corto_typeOptions* _id = corto_typeOptionsDeclare(); (void)_id
CORTO_EXPORT corto_typeOptions* _corto_typeOptionsDeclareChild(corto_object _parent, corto_string _id);
#define corto_typeOptionsDeclareChild(_parent, _id) _corto_typeOptionsDeclareChild(_parent, _id)
#define corto_typeOptionsDeclareChild_auto(_parent, _id) corto_typeOptions* _id = corto_typeOptionsDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_typeOptionsDefine(corto_typeOptions* _this, corto_type parentType, corto_state parentState, corto_type defaultType, corto_type defaultProcedureType);
#define corto_typeOptionsDefine(_this, parentType, parentState, defaultType, defaultProcedureType) _corto_typeOptionsDefine(corto_typeOptions(_this), corto_type(parentType), parentState, corto_type(defaultType), corto_type(defaultProcedureType))

/* uint */
CORTO_EXPORT corto_uint _corto_uintCreate(corto_width width, uint64_t min, uint64_t max);
#define corto_uintCreate(width, min, max) _corto_uintCreate(width, min, max)
#define corto_uintCreate_auto(_id, width, min, max) corto_uint _id = corto_uintCreate(width, min, max); (void)_id
CORTO_EXPORT corto_uint _corto_uintCreateChild(corto_object _parent, corto_string _id, corto_width width, uint64_t min, uint64_t max);
#define corto_uintCreateChild(_parent, _id, width, min, max) _corto_uintCreateChild(_parent, _id, width, min, max)
#define corto_uintCreateChild_auto(_parent, _id, width, min, max) corto_uint _id = corto_uintCreateChild(_parent, #_id, width, min, max); (void)_id
CORTO_EXPORT corto_int16 _corto_uintUpdate(corto_uint _this, corto_width width, uint64_t min, uint64_t max);
#define corto_uintUpdate(_this, width, min, max) _corto_uintUpdate(corto_uint(_this), width, min, max)
CORTO_EXPORT corto_uint _corto_uintAssign(corto_uint _this, corto_width width, uint64_t min, uint64_t max);
#define corto_uint__optional_NotSet NULL
#define corto_uint__optional_Set(width, min, max) corto_uintAssign((corto_uint*)corto_ptr_new(corto_uint_o)), width, min, max)
#define corto_uint__optional_SetCond(cond, width, min, max) cond ? corto_uintAssign((corto_uint*)corto_ptr_new(corto_uint_o), width, min, max) : NULL
#define corto_uintUnset(_this) _this ? corto_ptr_free(_this, corto_uint_o), 0 : 0; _this = NULL;
#define corto_uintAssign(_this, width, min, max) _corto_uintAssign(_this, width, min, max)
#define corto_uintSet(_this, width, min, max) _this = _this ? _this : (corto_uint*)corto_ptr_new(corto_uint_o); _corto_uintAssign(_this, width, min, max)

CORTO_EXPORT corto_uint _corto_uintDeclare(void);
#define corto_uintDeclare() _corto_uintDeclare()
#define corto_uintDeclare_auto(_id) corto_uint _id = corto_uintDeclare(); (void)_id
CORTO_EXPORT corto_uint _corto_uintDeclareChild(corto_object _parent, corto_string _id);
#define corto_uintDeclareChild(_parent, _id) _corto_uintDeclareChild(_parent, _id)
#define corto_uintDeclareChild_auto(_parent, _id) corto_uint _id = corto_uintDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_uintDefine(corto_uint _this, corto_width width, uint64_t min, uint64_t max);
#define corto_uintDefine(_this, width, min, max) _corto_uintDefine(corto_uint(_this), width, min, max)

/* uint16 */
CORTO_EXPORT uint16_t* _corto_uint16Create(uint16_t value);
#define corto_uint16Create(value) _corto_uint16Create(value)
#define corto_uint16Create_auto(_id, value) uint16_t* _id = corto_uint16Create(value); (void)_id
CORTO_EXPORT uint16_t* _corto_uint16CreateChild(corto_object _parent, corto_string _id, uint16_t value);
#define corto_uint16CreateChild(_parent, _id, value) _corto_uint16CreateChild(_parent, _id, value)
#define corto_uint16CreateChild_auto(_parent, _id, value) uint16_t* _id = corto_uint16CreateChild(_parent, #_id, value); (void)_id
CORTO_EXPORT corto_int16 _corto_uint16Update(uint16_t* _this, uint16_t value);
#define corto_uint16Update(_this, value) _corto_uint16Update(corto_uint16(_this), value)
CORTO_EXPORT uint16_t* _corto_uint16Assign(uint16_t* _this, uint16_t value);
#define corto_uint16__optional_NotSet NULL
#define corto_uint16__optional_Set(value) corto_uint16Assign((corto_uint16*)corto_ptr_new(corto_uint16_o)), value)
#define corto_uint16__optional_SetCond(cond, value) cond ? corto_uint16Assign((corto_uint16*)corto_ptr_new(corto_uint16_o), value) : NULL
#define corto_uint16Unset(_this) _this ? corto_ptr_free(_this, corto_uint16_o), 0 : 0; _this = NULL;
#define corto_uint16Assign(_this, value) _corto_uint16Assign(_this, value)
#define corto_uint16Set(_this, value) _this = _this ? _this : (corto_uint16*)corto_ptr_new(corto_uint16_o); _corto_uint16Assign(_this, value)

CORTO_EXPORT uint16_t* _corto_uint16Declare(void);
#define corto_uint16Declare() _corto_uint16Declare()
#define corto_uint16Declare_auto(_id) uint16_t* _id = corto_uint16Declare(); (void)_id
CORTO_EXPORT uint16_t* _corto_uint16DeclareChild(corto_object _parent, corto_string _id);
#define corto_uint16DeclareChild(_parent, _id) _corto_uint16DeclareChild(_parent, _id)
#define corto_uint16DeclareChild_auto(_parent, _id) uint16_t* _id = corto_uint16DeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_uint16Define(uint16_t* _this, uint16_t value);
#define corto_uint16Define(_this, value) _corto_uint16Define(corto_uint16(_this), value)

/* uint32 */
CORTO_EXPORT uint32_t* _corto_uint32Create(uint32_t value);
#define corto_uint32Create(value) _corto_uint32Create(value)
#define corto_uint32Create_auto(_id, value) uint32_t* _id = corto_uint32Create(value); (void)_id
CORTO_EXPORT uint32_t* _corto_uint32CreateChild(corto_object _parent, corto_string _id, uint32_t value);
#define corto_uint32CreateChild(_parent, _id, value) _corto_uint32CreateChild(_parent, _id, value)
#define corto_uint32CreateChild_auto(_parent, _id, value) uint32_t* _id = corto_uint32CreateChild(_parent, #_id, value); (void)_id
CORTO_EXPORT corto_int16 _corto_uint32Update(uint32_t* _this, uint32_t value);
#define corto_uint32Update(_this, value) _corto_uint32Update(corto_uint32(_this), value)
CORTO_EXPORT uint32_t* _corto_uint32Assign(uint32_t* _this, uint32_t value);
#define corto_uint32__optional_NotSet NULL
#define corto_uint32__optional_Set(value) corto_uint32Assign((corto_uint32*)corto_ptr_new(corto_uint32_o)), value)
#define corto_uint32__optional_SetCond(cond, value) cond ? corto_uint32Assign((corto_uint32*)corto_ptr_new(corto_uint32_o), value) : NULL
#define corto_uint32Unset(_this) _this ? corto_ptr_free(_this, corto_uint32_o), 0 : 0; _this = NULL;
#define corto_uint32Assign(_this, value) _corto_uint32Assign(_this, value)
#define corto_uint32Set(_this, value) _this = _this ? _this : (corto_uint32*)corto_ptr_new(corto_uint32_o); _corto_uint32Assign(_this, value)

CORTO_EXPORT uint32_t* _corto_uint32Declare(void);
#define corto_uint32Declare() _corto_uint32Declare()
#define corto_uint32Declare_auto(_id) uint32_t* _id = corto_uint32Declare(); (void)_id
CORTO_EXPORT uint32_t* _corto_uint32DeclareChild(corto_object _parent, corto_string _id);
#define corto_uint32DeclareChild(_parent, _id) _corto_uint32DeclareChild(_parent, _id)
#define corto_uint32DeclareChild_auto(_parent, _id) uint32_t* _id = corto_uint32DeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_uint32Define(uint32_t* _this, uint32_t value);
#define corto_uint32Define(_this, value) _corto_uint32Define(corto_uint32(_this), value)

/* uint64 */
CORTO_EXPORT uint64_t* _corto_uint64Create(uint64_t value);
#define corto_uint64Create(value) _corto_uint64Create(value)
#define corto_uint64Create_auto(_id, value) uint64_t* _id = corto_uint64Create(value); (void)_id
CORTO_EXPORT uint64_t* _corto_uint64CreateChild(corto_object _parent, corto_string _id, uint64_t value);
#define corto_uint64CreateChild(_parent, _id, value) _corto_uint64CreateChild(_parent, _id, value)
#define corto_uint64CreateChild_auto(_parent, _id, value) uint64_t* _id = corto_uint64CreateChild(_parent, #_id, value); (void)_id
CORTO_EXPORT corto_int16 _corto_uint64Update(uint64_t* _this, uint64_t value);
#define corto_uint64Update(_this, value) _corto_uint64Update(corto_uint64(_this), value)
CORTO_EXPORT uint64_t* _corto_uint64Assign(uint64_t* _this, uint64_t value);
#define corto_uint64__optional_NotSet NULL
#define corto_uint64__optional_Set(value) corto_uint64Assign((corto_uint64*)corto_ptr_new(corto_uint64_o)), value)
#define corto_uint64__optional_SetCond(cond, value) cond ? corto_uint64Assign((corto_uint64*)corto_ptr_new(corto_uint64_o), value) : NULL
#define corto_uint64Unset(_this) _this ? corto_ptr_free(_this, corto_uint64_o), 0 : 0; _this = NULL;
#define corto_uint64Assign(_this, value) _corto_uint64Assign(_this, value)
#define corto_uint64Set(_this, value) _this = _this ? _this : (corto_uint64*)corto_ptr_new(corto_uint64_o); _corto_uint64Assign(_this, value)

CORTO_EXPORT uint64_t* _corto_uint64Declare(void);
#define corto_uint64Declare() _corto_uint64Declare()
#define corto_uint64Declare_auto(_id) uint64_t* _id = corto_uint64Declare(); (void)_id
CORTO_EXPORT uint64_t* _corto_uint64DeclareChild(corto_object _parent, corto_string _id);
#define corto_uint64DeclareChild(_parent, _id) _corto_uint64DeclareChild(_parent, _id)
#define corto_uint64DeclareChild_auto(_parent, _id) uint64_t* _id = corto_uint64DeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_uint64Define(uint64_t* _this, uint64_t value);
#define corto_uint64Define(_this, value) _corto_uint64Define(corto_uint64(_this), value)

/* uint8 */
CORTO_EXPORT uint8_t* _corto_uint8Create(uint8_t value);
#define corto_uint8Create(value) _corto_uint8Create(value)
#define corto_uint8Create_auto(_id, value) uint8_t* _id = corto_uint8Create(value); (void)_id
CORTO_EXPORT uint8_t* _corto_uint8CreateChild(corto_object _parent, corto_string _id, uint8_t value);
#define corto_uint8CreateChild(_parent, _id, value) _corto_uint8CreateChild(_parent, _id, value)
#define corto_uint8CreateChild_auto(_parent, _id, value) uint8_t* _id = corto_uint8CreateChild(_parent, #_id, value); (void)_id
CORTO_EXPORT corto_int16 _corto_uint8Update(uint8_t* _this, uint8_t value);
#define corto_uint8Update(_this, value) _corto_uint8Update(corto_uint8(_this), value)
CORTO_EXPORT uint8_t* _corto_uint8Assign(uint8_t* _this, uint8_t value);
#define corto_uint8__optional_NotSet NULL
#define corto_uint8__optional_Set(value) corto_uint8Assign((corto_uint8*)corto_ptr_new(corto_uint8_o)), value)
#define corto_uint8__optional_SetCond(cond, value) cond ? corto_uint8Assign((corto_uint8*)corto_ptr_new(corto_uint8_o), value) : NULL
#define corto_uint8Unset(_this) _this ? corto_ptr_free(_this, corto_uint8_o), 0 : 0; _this = NULL;
#define corto_uint8Assign(_this, value) _corto_uint8Assign(_this, value)
#define corto_uint8Set(_this, value) _this = _this ? _this : (corto_uint8*)corto_ptr_new(corto_uint8_o); _corto_uint8Assign(_this, value)

CORTO_EXPORT uint8_t* _corto_uint8Declare(void);
#define corto_uint8Declare() _corto_uint8Declare()
#define corto_uint8Declare_auto(_id) uint8_t* _id = corto_uint8Declare(); (void)_id
CORTO_EXPORT uint8_t* _corto_uint8DeclareChild(corto_object _parent, corto_string _id);
#define corto_uint8DeclareChild(_parent, _id) _corto_uint8DeclareChild(_parent, _id)
#define corto_uint8DeclareChild_auto(_parent, _id) uint8_t* _id = corto_uint8DeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_uint8Define(uint8_t* _this, uint8_t value);
#define corto_uint8Define(_this, value) _corto_uint8Define(corto_uint8(_this), value)

/* union */
CORTO_EXPORT corto_union _corto_unionCreate(corto_type discriminator);
#define corto_unionCreate(discriminator) _corto_unionCreate(corto_type(discriminator))
#define corto_unionCreate_auto(_id, discriminator) corto_union _id = corto_unionCreate(discriminator); (void)_id
CORTO_EXPORT corto_union _corto_unionCreateChild(corto_object _parent, corto_string _id, corto_type discriminator);
#define corto_unionCreateChild(_parent, _id, discriminator) _corto_unionCreateChild(_parent, _id, corto_type(discriminator))
#define corto_unionCreateChild_auto(_parent, _id, discriminator) corto_union _id = corto_unionCreateChild(_parent, #_id, discriminator); (void)_id
CORTO_EXPORT corto_int16 _corto_unionUpdate(corto_union _this, corto_type discriminator);
#define corto_unionUpdate(_this, discriminator) _corto_unionUpdate(corto_union(_this), corto_type(discriminator))
CORTO_EXPORT corto_union _corto_unionAssign(corto_union _this, corto_type discriminator);
#define corto_union__optional_NotSet NULL
#define corto_union__optional_Set(discriminator) corto_unionAssign((corto_union*)corto_ptr_new(corto_union_o)), discriminator)
#define corto_union__optional_SetCond(cond, discriminator) cond ? corto_unionAssign((corto_union*)corto_ptr_new(corto_union_o), discriminator) : NULL
#define corto_unionUnset(_this) _this ? corto_ptr_free(_this, corto_union_o), 0 : 0; _this = NULL;
#define corto_unionAssign(_this, discriminator) _corto_unionAssign(_this, corto_type(discriminator))
#define corto_unionSet(_this, discriminator) _this = _this ? _this : (corto_union*)corto_ptr_new(corto_union_o); _corto_unionAssign(_this, corto_type(discriminator))

CORTO_EXPORT corto_union _corto_unionDeclare(void);
#define corto_unionDeclare() _corto_unionDeclare()
#define corto_unionDeclare_auto(_id) corto_union _id = corto_unionDeclare(); (void)_id
CORTO_EXPORT corto_union _corto_unionDeclareChild(corto_object _parent, corto_string _id);
#define corto_unionDeclareChild(_parent, _id) _corto_unionDeclareChild(_parent, _id)
#define corto_unionDeclareChild_auto(_parent, _id) corto_union _id = corto_unionDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_unionDefine(corto_union _this, corto_type discriminator);
#define corto_unionDefine(_this, discriminator) _corto_unionDefine(corto_union(_this), corto_type(discriminator))

/* unit */
CORTO_EXPORT corto_unit _corto_unitCreate(corto_quantity quantity, corto_string symbol, corto_string conversion, corto_type type);
#define corto_unitCreate(quantity, symbol, conversion, type) _corto_unitCreate(corto_quantity(quantity), symbol, conversion, corto_type(type))
#define corto_unitCreate_auto(_id, quantity, symbol, conversion, type) corto_unit _id = corto_unitCreate(quantity, symbol, conversion, type); (void)_id
CORTO_EXPORT corto_unit _corto_unitCreateChild(corto_object _parent, corto_string _id, corto_quantity quantity, corto_string symbol, corto_string conversion, corto_type type);
#define corto_unitCreateChild(_parent, _id, quantity, symbol, conversion, type) _corto_unitCreateChild(_parent, _id, corto_quantity(quantity), symbol, conversion, corto_type(type))
#define corto_unitCreateChild_auto(_parent, _id, quantity, symbol, conversion, type) corto_unit _id = corto_unitCreateChild(_parent, #_id, quantity, symbol, conversion, type); (void)_id
CORTO_EXPORT corto_int16 _corto_unitUpdate(corto_unit _this, corto_quantity quantity, corto_string symbol, corto_string conversion, corto_type type);
#define corto_unitUpdate(_this, quantity, symbol, conversion, type) _corto_unitUpdate(corto_unit(_this), corto_quantity(quantity), symbol, conversion, corto_type(type))
CORTO_EXPORT corto_unit _corto_unitAssign(corto_unit _this, corto_quantity quantity, corto_string symbol, corto_string conversion, corto_type type);
#define corto_unit__optional_NotSet NULL
#define corto_unit__optional_Set(quantity, symbol, conversion, type) corto_unitAssign((corto_unit*)corto_ptr_new(corto_unit_o)), quantity, symbol, conversion, type)
#define corto_unit__optional_SetCond(cond, quantity, symbol, conversion, type) cond ? corto_unitAssign((corto_unit*)corto_ptr_new(corto_unit_o), quantity, symbol, conversion, type) : NULL
#define corto_unitUnset(_this) _this ? corto_ptr_free(_this, corto_unit_o), 0 : 0; _this = NULL;
#define corto_unitAssign(_this, quantity, symbol, conversion, type) _corto_unitAssign(_this, corto_quantity(quantity), symbol, conversion, corto_type(type))
#define corto_unitSet(_this, quantity, symbol, conversion, type) _this = _this ? _this : (corto_unit*)corto_ptr_new(corto_unit_o); _corto_unitAssign(_this, corto_quantity(quantity), symbol, conversion, corto_type(type))

CORTO_EXPORT corto_unit _corto_unitDeclare(void);
#define corto_unitDeclare() _corto_unitDeclare()
#define corto_unitDeclare_auto(_id) corto_unit _id = corto_unitDeclare(); (void)_id
CORTO_EXPORT corto_unit _corto_unitDeclareChild(corto_object _parent, corto_string _id);
#define corto_unitDeclareChild(_parent, _id) _corto_unitDeclareChild(_parent, _id)
#define corto_unitDeclareChild_auto(_parent, _id) corto_unit _id = corto_unitDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_unitDefine(corto_unit _this, corto_quantity quantity, corto_string symbol, corto_string conversion, corto_type type);
#define corto_unitDefine(_this, quantity, symbol, conversion, type) _corto_unitDefine(corto_unit(_this), corto_quantity(quantity), symbol, conversion, corto_type(type))

/* verbatim */
CORTO_EXPORT corto_verbatim _corto_verbatimCreate(corto_string contentType);
#define corto_verbatimCreate(contentType) _corto_verbatimCreate(contentType)
#define corto_verbatimCreate_auto(_id, contentType) corto_verbatim _id = corto_verbatimCreate(contentType); (void)_id
CORTO_EXPORT corto_verbatim _corto_verbatimCreateChild(corto_object _parent, corto_string _id, corto_string contentType);
#define corto_verbatimCreateChild(_parent, _id, contentType) _corto_verbatimCreateChild(_parent, _id, contentType)
#define corto_verbatimCreateChild_auto(_parent, _id, contentType) corto_verbatim _id = corto_verbatimCreateChild(_parent, #_id, contentType); (void)_id
CORTO_EXPORT corto_int16 _corto_verbatimUpdate(corto_verbatim _this, corto_string contentType);
#define corto_verbatimUpdate(_this, contentType) _corto_verbatimUpdate(corto_verbatim(_this), contentType)
CORTO_EXPORT corto_verbatim _corto_verbatimAssign(corto_verbatim _this, corto_string contentType);
#define corto_verbatim__optional_NotSet NULL
#define corto_verbatim__optional_Set(contentType) corto_verbatimAssign((corto_verbatim*)corto_ptr_new(corto_verbatim_o)), contentType)
#define corto_verbatim__optional_SetCond(cond, contentType) cond ? corto_verbatimAssign((corto_verbatim*)corto_ptr_new(corto_verbatim_o), contentType) : NULL
#define corto_verbatimUnset(_this) _this ? corto_ptr_free(_this, corto_verbatim_o), 0 : 0; _this = NULL;
#define corto_verbatimAssign(_this, contentType) _corto_verbatimAssign(_this, contentType)
#define corto_verbatimSet(_this, contentType) _this = _this ? _this : (corto_verbatim*)corto_ptr_new(corto_verbatim_o); _corto_verbatimAssign(_this, contentType)

CORTO_EXPORT corto_verbatim _corto_verbatimDeclare(void);
#define corto_verbatimDeclare() _corto_verbatimDeclare()
#define corto_verbatimDeclare_auto(_id) corto_verbatim _id = corto_verbatimDeclare(); (void)_id
CORTO_EXPORT corto_verbatim _corto_verbatimDeclareChild(corto_object _parent, corto_string _id);
#define corto_verbatimDeclareChild(_parent, _id) _corto_verbatimDeclareChild(_parent, _id)
#define corto_verbatimDeclareChild_auto(_parent, _id) corto_verbatim _id = corto_verbatimDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_verbatimDefine(corto_verbatim _this, corto_string contentType);
#define corto_verbatimDefine(_this, contentType) _corto_verbatimDefine(corto_verbatim(_this), contentType)

/* void */
CORTO_EXPORT void* _corto_voidCreate(void);
#define corto_voidCreate() _corto_voidCreate()
#define corto_voidCreate_auto(_id) void* _id = corto_voidCreate(); (void)_id
CORTO_EXPORT void* _corto_voidCreateChild(corto_object _parent, corto_string _id);
#define corto_voidCreateChild(_parent, _id) _corto_voidCreateChild(_parent, _id)
#define corto_voidCreateChild_auto(_parent, _id) void* _id = corto_voidCreateChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_voidUpdate(void* _this);
#define corto_voidUpdate(_this) _corto_voidUpdate(corto_void(_this))

/* width */
CORTO_EXPORT corto_width* _corto_widthCreate(corto_width value);
#define corto_widthCreate(value) _corto_widthCreate(value)
#define corto_widthCreate_auto(_id, value) corto_width* _id = corto_widthCreate(value); (void)_id
CORTO_EXPORT corto_width* _corto_widthCreateChild(corto_object _parent, corto_string _id, corto_width value);
#define corto_widthCreateChild(_parent, _id, value) _corto_widthCreateChild(_parent, _id, value)
#define corto_widthCreateChild_auto(_parent, _id, value) corto_width* _id = corto_widthCreateChild(_parent, #_id, value); (void)_id
CORTO_EXPORT corto_int16 _corto_widthUpdate(corto_width* _this, corto_width value);
#define corto_widthUpdate(_this, value) _corto_widthUpdate(corto_width(_this), value)
CORTO_EXPORT corto_width* _corto_widthAssign(corto_width* _this, corto_width value);
#define corto_width__optional_NotSet NULL
#define corto_width__optional_Set(value) corto_widthAssign((corto_width*)corto_ptr_new(corto_width_o)), value)
#define corto_width__optional_SetCond(cond, value) cond ? corto_widthAssign((corto_width*)corto_ptr_new(corto_width_o), value) : NULL
#define corto_widthUnset(_this) _this ? corto_ptr_free(_this, corto_width_o), 0 : 0; _this = NULL;
#define corto_widthAssign(_this, value) _corto_widthAssign(_this, value)
#define corto_widthSet(_this, value) _this = _this ? _this : (corto_width*)corto_ptr_new(corto_width_o); _corto_widthAssign(_this, value)

CORTO_EXPORT corto_width* _corto_widthDeclare(void);
#define corto_widthDeclare() _corto_widthDeclare()
#define corto_widthDeclare_auto(_id) corto_width* _id = corto_widthDeclare(); (void)_id
CORTO_EXPORT corto_width* _corto_widthDeclareChild(corto_object _parent, corto_string _id);
#define corto_widthDeclareChild(_parent, _id) _corto_widthDeclareChild(_parent, _id)
#define corto_widthDeclareChild_auto(_parent, _id) corto_width* _id = corto_widthDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_widthDefine(corto_width* _this, corto_width value);
#define corto_widthDefine(_this, value) _corto_widthDefine(corto_width(_this), value)

/* word */
CORTO_EXPORT uintptr_t* _corto_wordCreate(uintptr_t value);
#define corto_wordCreate(value) _corto_wordCreate(value)
#define corto_wordCreate_auto(_id, value) uintptr_t* _id = corto_wordCreate(value); (void)_id
CORTO_EXPORT uintptr_t* _corto_wordCreateChild(corto_object _parent, corto_string _id, uintptr_t value);
#define corto_wordCreateChild(_parent, _id, value) _corto_wordCreateChild(_parent, _id, value)
#define corto_wordCreateChild_auto(_parent, _id, value) uintptr_t* _id = corto_wordCreateChild(_parent, #_id, value); (void)_id
CORTO_EXPORT corto_int16 _corto_wordUpdate(uintptr_t* _this, uintptr_t value);
#define corto_wordUpdate(_this, value) _corto_wordUpdate(corto_word(_this), value)
CORTO_EXPORT uintptr_t* _corto_wordAssign(uintptr_t* _this, uintptr_t value);
#define corto_word__optional_NotSet NULL
#define corto_word__optional_Set(value) corto_wordAssign((corto_word*)corto_ptr_new(corto_word_o)), value)
#define corto_word__optional_SetCond(cond, value) cond ? corto_wordAssign((corto_word*)corto_ptr_new(corto_word_o), value) : NULL
#define corto_wordUnset(_this) _this ? corto_ptr_free(_this, corto_word_o), 0 : 0; _this = NULL;
#define corto_wordAssign(_this, value) _corto_wordAssign(_this, value)
#define corto_wordSet(_this, value) _this = _this ? _this : (corto_word*)corto_ptr_new(corto_word_o); _corto_wordAssign(_this, value)

CORTO_EXPORT uintptr_t* _corto_wordDeclare(void);
#define corto_wordDeclare() _corto_wordDeclare()
#define corto_wordDeclare_auto(_id) uintptr_t* _id = corto_wordDeclare(); (void)_id
CORTO_EXPORT uintptr_t* _corto_wordDeclareChild(corto_object _parent, corto_string _id);
#define corto_wordDeclareChild(_parent, _id) _corto_wordDeclareChild(_parent, _id)
#define corto_wordDeclareChild_auto(_parent, _id) uintptr_t* _id = corto_wordDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_wordDefine(uintptr_t* _this, uintptr_t value);
#define corto_wordDefine(_this, value) _corto_wordDefine(corto_word(_this), value)

/* wordseq */
CORTO_EXPORT corto_wordseq* _corto_wordseqCreate(corto_uint32 length, corto_word* elements);
#define corto_wordseqCreate(length, elements) _corto_wordseqCreate(length, elements)
#define corto_wordseqCreate_auto(_id, length, elements) corto_wordseq* _id = corto_wordseqCreate(length, elements); (void)_id
CORTO_EXPORT corto_wordseq* _corto_wordseqCreateChild(corto_object _parent, corto_string _id, corto_uint32 length, corto_word* elements);
#define corto_wordseqCreateChild(_parent, _id, length, elements) _corto_wordseqCreateChild(_parent, _id, length, elements)
#define corto_wordseqCreateChild_auto(_parent, _id, length, elements) corto_wordseq* _id = corto_wordseqCreateChild(_parent, #_id, length, elements); (void)_id
CORTO_EXPORT corto_int16 _corto_wordseqUpdate(corto_wordseq* _this, corto_uint32 length, corto_word* elements);
#define corto_wordseqUpdate(_this, length, elements) _corto_wordseqUpdate(corto_wordseq(_this), length, elements)
CORTO_EXPORT corto_wordseq* _corto_wordseqAssign(corto_wordseq* _this, corto_uint32 length, corto_word* elements);
#define corto_wordseq__optional_NotSet NULL
#define corto_wordseq__optional_Set(length, elements) corto_wordseqAssign((corto_wordseq*)corto_ptr_new(corto_wordseq_o)), length, elements)
#define corto_wordseq__optional_SetCond(cond, length, elements) cond ? corto_wordseqAssign((corto_wordseq*)corto_ptr_new(corto_wordseq_o), length, elements) : NULL
#define corto_wordseqUnset(_this) _this ? corto_ptr_free(_this, corto_wordseq_o), 0 : 0; _this = NULL;
#define corto_wordseqAssign(_this, length, elements) _corto_wordseqAssign(_this, length, elements)
#define corto_wordseqSet(_this, length, elements) _this = _this ? _this : (corto_wordseq*)corto_ptr_new(corto_wordseq_o); _corto_wordseqAssign(_this, length, elements)

CORTO_EXPORT corto_wordseq* _corto_wordseqDeclare(void);
#define corto_wordseqDeclare() _corto_wordseqDeclare()
#define corto_wordseqDeclare_auto(_id) corto_wordseq* _id = corto_wordseqDeclare(); (void)_id
CORTO_EXPORT corto_wordseq* _corto_wordseqDeclareChild(corto_object _parent, corto_string _id);
#define corto_wordseqDeclareChild(_parent, _id) _corto_wordseqDeclareChild(_parent, _id)
#define corto_wordseqDeclareChild_auto(_parent, _id) corto_wordseq* _id = corto_wordseqDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_wordseqDefine(corto_wordseq* _this, corto_uint32 length, corto_word* elements);
#define corto_wordseqDefine(_this, length, elements) _corto_wordseqDefine(corto_wordseq(_this), length, elements)


#ifdef __cplusplus
}
#endif
#endif

