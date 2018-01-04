/* lang.c
 *
 * API convenience functions for C-language.
 * This file contains generated code. Do not modify!
 */

#include <corto/c/c.h>

corto_alias _corto_aliasCreate(corto_member member) {
    corto_alias _this;
    _this = (corto_alias)corto_declare(NULL, NULL, corto_alias_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_ref(&((corto_alias)_this)->member, member);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_alias _corto_aliasCreateChild(corto_object _parent, const char *_id, corto_member member) {
    corto_alias _this;
    _this = (corto_alias)corto_declare(_parent, _id, corto_alias_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_ref(&((corto_alias)_this)->member, member);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_aliasUpdate(corto_alias _this, corto_member member) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_set_ref(&((corto_alias)((corto_alias)CORTO_OFFSET(_this, ((corto_type)corto_alias_o)->size)))->member, member);
        } else {
            corto_set_ref(&((corto_alias)_this)->member, member);
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

corto_alias _corto_aliasDeclare(void) {
    corto_alias _this;
    _this = (corto_alias)corto_declare(NULL, NULL, corto_alias_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_alias _corto_aliasDeclareChild(corto_object _parent, const char *_id) {
    corto_alias _this;
    _this = (corto_alias)corto_declare(_parent, _id, corto_alias_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_aliasDefine(corto_alias _this, corto_member member) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_alias)_this)->member, member);
    return corto_define(_this);
}

corto_alias _corto_aliasAssign(corto_alias _this, corto_member member) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_alias)_this)->member, member);
    return _this;
}

corto_any* _corto_anyCreate(corto_type type, void *value) {
    corto_any* _this;
    _this = (corto_any*)corto_declare(NULL, NULL, corto_any_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_any v;
        v.value = value;
        v.type = type;
        _this->owner = TRUE;
        corto_ptr_copy(_this, corto_any_o, &v);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_any* _corto_anyCreateChild(corto_object _parent, const char *_id, corto_type type, void *value) {
    corto_any* _this;
    _this = (corto_any*)corto_declare(_parent, _id, corto_any_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_any v;
        v.value = value;
        v.type = type;
        _this->owner = TRUE;
        corto_ptr_copy(_this, corto_any_o, &v);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_anyUpdate(corto_any* _this, corto_type type, void *value) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_any v;
            v.value = value;
            v.type = type;
            ((corto_any*)CORTO_OFFSET(_this, ((corto_type)corto_any_o)->size))->owner = TRUE;
            corto_ptr_copy(((corto_any*)CORTO_OFFSET(_this, ((corto_type)corto_any_o)->size)), corto_any_o, &v);
        } else {
            corto_any v;
            v.value = value;
            v.type = type;
            _this->owner = TRUE;
            corto_ptr_copy(_this, corto_any_o, &v);
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

corto_any* _corto_anyDeclare(void) {
    corto_any* _this;
    _this = (corto_any*)corto_declare(NULL, NULL, corto_any_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_any* _corto_anyDeclareChild(corto_object _parent, const char *_id) {
    corto_any* _this;
    _this = (corto_any*)corto_declare(_parent, _id, corto_any_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_anyDefine(corto_any* _this, corto_type type, void *value) {
    CORTO_UNUSED(_this);
    corto_any v;
    v.value = value;
    v.type = type;
    _this->owner = TRUE;
    corto_ptr_copy(_this, corto_any_o, &v);
    return corto_define(_this);
}

corto_any* _corto_anyAssign(corto_any* _this, corto_type type, void *value) {
    CORTO_UNUSED(_this);
    corto_any v;
    v.value = value;
    v.type = type;
    _this->owner = TRUE;
    corto_ptr_copy(_this, corto_any_o, &v);
    return _this;
}

corto_application _corto_applicationCreate(void) {
    corto_application _this;
    _this = (corto_application)corto_declare(NULL, NULL, corto_application_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_application _corto_applicationCreateChild(corto_object _parent, const char *_id) {
    corto_application _this;
    _this = (corto_application)corto_declare(_parent, _id, corto_application_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_applicationUpdate(corto_application _this) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
        } else {
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

corto_application _corto_applicationDeclare(void) {
    corto_application _this;
    _this = (corto_application)corto_declare(NULL, NULL, corto_application_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_application _corto_applicationDeclareChild(corto_object _parent, const char *_id) {
    corto_application _this;
    _this = (corto_application)corto_declare(_parent, _id, corto_application_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_applicationDefine(corto_application _this) {
    CORTO_UNUSED(_this);
    return corto_define(_this);
}

corto_application _corto_applicationAssign(corto_application _this) {
    CORTO_UNUSED(_this);
    return _this;
}

corto_array _corto_arrayCreate(corto_type elementType, uint32_t max) {
    corto_array _this;
    _this = (corto_array)corto_declare(NULL, NULL, corto_array_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_ref(&((corto_collection)_this)->elementType, elementType);
        ((corto_collection)_this)->max = max;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_array _corto_arrayCreateChild(corto_object _parent, const char *_id, corto_type elementType, uint32_t max) {
    corto_array _this;
    _this = (corto_array)corto_declare(_parent, _id, corto_array_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_ref(&((corto_collection)_this)->elementType, elementType);
        ((corto_collection)_this)->max = max;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_arrayUpdate(corto_array _this, corto_type elementType, uint32_t max) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_set_ref(&((corto_collection)((corto_array)CORTO_OFFSET(_this, ((corto_type)corto_array_o)->size)))->elementType, elementType);
            ((corto_collection)((corto_array)CORTO_OFFSET(_this, ((corto_type)corto_array_o)->size)))->max = max;
        } else {
            corto_set_ref(&((corto_collection)_this)->elementType, elementType);
            ((corto_collection)_this)->max = max;
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

corto_array _corto_arrayDeclare(void) {
    corto_array _this;
    _this = (corto_array)corto_declare(NULL, NULL, corto_array_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_array _corto_arrayDeclareChild(corto_object _parent, const char *_id) {
    corto_array _this;
    _this = (corto_array)corto_declare(_parent, _id, corto_array_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_arrayDefine(corto_array _this, corto_type elementType, uint32_t max) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_collection)_this)->elementType, elementType);
    ((corto_collection)_this)->max = max;
    return corto_define(_this);
}

corto_array _corto_arrayAssign(corto_array _this, corto_type elementType, uint32_t max) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_collection)_this)->elementType, elementType);
    ((corto_collection)_this)->max = max;
    return _this;
}

corto_attr* _corto_attrCreate(corto_attr value) {
    corto_attr* _this;
    _this = (corto_attr*)corto_declare(NULL, NULL, corto_attr_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        *_this = value;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_attr* _corto_attrCreateChild(corto_object _parent, const char *_id, corto_attr value) {
    corto_attr* _this;
    _this = (corto_attr*)corto_declare(_parent, _id, corto_attr_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        *_this = value;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_attrUpdate(corto_attr* _this, corto_attr value) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            *((corto_attr*)CORTO_OFFSET(_this, ((corto_type)corto_attr_o)->size)) = value;
        } else {
            *_this = value;
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

corto_attr* _corto_attrDeclare(void) {
    corto_attr* _this;
    _this = (corto_attr*)corto_declare(NULL, NULL, corto_attr_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_attr* _corto_attrDeclareChild(corto_object _parent, const char *_id) {
    corto_attr* _this;
    _this = (corto_attr*)corto_declare(_parent, _id, corto_attr_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_attrDefine(corto_attr* _this, corto_attr value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return corto_define(_this);
}

corto_attr* _corto_attrAssign(corto_attr* _this, corto_attr value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

corto_binary _corto_binaryCreate(corto_width width) {
    corto_binary _this;
    _this = (corto_binary)corto_declare(NULL, NULL, corto_binary_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        ((corto_primitive)_this)->width = width;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_binary _corto_binaryCreateChild(corto_object _parent, const char *_id, corto_width width) {
    corto_binary _this;
    _this = (corto_binary)corto_declare(_parent, _id, corto_binary_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        ((corto_primitive)_this)->width = width;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_binaryUpdate(corto_binary _this, corto_width width) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            ((corto_primitive)((corto_binary)CORTO_OFFSET(_this, ((corto_type)corto_binary_o)->size)))->width = width;
        } else {
            ((corto_primitive)_this)->width = width;
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

corto_binary _corto_binaryDeclare(void) {
    corto_binary _this;
    _this = (corto_binary)corto_declare(NULL, NULL, corto_binary_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_binary _corto_binaryDeclareChild(corto_object _parent, const char *_id) {
    corto_binary _this;
    _this = (corto_binary)corto_declare(_parent, _id, corto_binary_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_binaryDefine(corto_binary _this, corto_width width) {
    CORTO_UNUSED(_this);
    ((corto_primitive)_this)->width = width;
    return corto_define(_this);
}

corto_binary _corto_binaryAssign(corto_binary _this, corto_width width) {
    CORTO_UNUSED(_this);
    ((corto_primitive)_this)->width = width;
    return _this;
}

corto_bitmask _corto_bitmaskCreate(void) {
    corto_bitmask _this;
    _this = (corto_bitmask)corto_declare(NULL, NULL, corto_bitmask_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_bitmask _corto_bitmaskCreateChild(corto_object _parent, const char *_id) {
    corto_bitmask _this;
    _this = (corto_bitmask)corto_declare(_parent, _id, corto_bitmask_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_bitmaskUpdate(corto_bitmask _this) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
        } else {
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

corto_bitmask _corto_bitmaskDeclare(void) {
    corto_bitmask _this;
    _this = (corto_bitmask)corto_declare(NULL, NULL, corto_bitmask_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_bitmask _corto_bitmaskDeclareChild(corto_object _parent, const char *_id) {
    corto_bitmask _this;
    _this = (corto_bitmask)corto_declare(_parent, _id, corto_bitmask_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_bitmaskDefine(corto_bitmask _this) {
    CORTO_UNUSED(_this);
    return corto_define(_this);
}

corto_bitmask _corto_bitmaskAssign(corto_bitmask _this) {
    CORTO_UNUSED(_this);
    return _this;
}

bool* _corto_boolCreate(bool value) {
    bool* _this;
    _this = (bool*)corto_declare(NULL, NULL, corto_bool_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        *_this = value;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

bool* _corto_boolCreateChild(corto_object _parent, const char *_id, bool value) {
    bool* _this;
    _this = (bool*)corto_declare(_parent, _id, corto_bool_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        *_this = value;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_boolUpdate(bool* _this, bool value) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            *((bool*)CORTO_OFFSET(_this, ((corto_type)corto_bool_o)->size)) = value;
        } else {
            *_this = value;
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

bool* _corto_boolDeclare(void) {
    bool* _this;
    _this = (bool*)corto_declare(NULL, NULL, corto_bool_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

bool* _corto_boolDeclareChild(corto_object _parent, const char *_id) {
    bool* _this;
    _this = (bool*)corto_declare(_parent, _id, corto_bool_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_boolDefine(bool* _this, bool value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return corto_define(_this);
}

bool* _corto_boolAssign(bool* _this, bool value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

corto_boolean _corto_booleanCreate(void) {
    corto_boolean _this;
    _this = (corto_boolean)corto_declare(NULL, NULL, corto_boolean_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_boolean _corto_booleanCreateChild(corto_object _parent, const char *_id) {
    corto_boolean _this;
    _this = (corto_boolean)corto_declare(_parent, _id, corto_boolean_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_booleanUpdate(corto_boolean _this) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
        } else {
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

corto_boolean _corto_booleanDeclare(void) {
    corto_boolean _this;
    _this = (corto_boolean)corto_declare(NULL, NULL, corto_boolean_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_boolean _corto_booleanDeclareChild(corto_object _parent, const char *_id) {
    corto_boolean _this;
    _this = (corto_boolean)corto_declare(_parent, _id, corto_boolean_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_booleanDefine(corto_boolean _this) {
    CORTO_UNUSED(_this);
    return corto_define(_this);
}

corto_boolean _corto_booleanAssign(corto_boolean _this) {
    CORTO_UNUSED(_this);
    return _this;
}

corto_case _corto_caseCreate(corto_int32seq discriminator, corto_type type, corto_modifier modifiers) {
    corto_case _this;
    _this = (corto_case)corto_declare(NULL, NULL, corto_case_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_ptr_copy(&((corto_case)_this)->discriminator, corto_int32seq_o, &discriminator);
        corto_set_ref(&((corto_member)_this)->type, type);
        ((corto_member)_this)->modifiers = modifiers;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_case _corto_caseCreateChild(corto_object _parent, const char *_id, corto_int32seq discriminator, corto_type type, corto_modifier modifiers) {
    corto_case _this;
    _this = (corto_case)corto_declare(_parent, _id, corto_case_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_ptr_copy(&((corto_case)_this)->discriminator, corto_int32seq_o, &discriminator);
        corto_set_ref(&((corto_member)_this)->type, type);
        ((corto_member)_this)->modifiers = modifiers;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_caseUpdate(corto_case _this, corto_int32seq discriminator, corto_type type, corto_modifier modifiers) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_ptr_copy(&((corto_case)((corto_case)CORTO_OFFSET(_this, ((corto_type)corto_case_o)->size)))->discriminator, corto_int32seq_o, &discriminator);
            corto_set_ref(&((corto_member)((corto_case)CORTO_OFFSET(_this, ((corto_type)corto_case_o)->size)))->type, type);
            ((corto_member)((corto_case)CORTO_OFFSET(_this, ((corto_type)corto_case_o)->size)))->modifiers = modifiers;
        } else {
            corto_ptr_copy(&((corto_case)_this)->discriminator, corto_int32seq_o, &discriminator);
            corto_set_ref(&((corto_member)_this)->type, type);
            ((corto_member)_this)->modifiers = modifiers;
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

corto_case _corto_caseDeclare(void) {
    corto_case _this;
    _this = (corto_case)corto_declare(NULL, NULL, corto_case_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_case _corto_caseDeclareChild(corto_object _parent, const char *_id) {
    corto_case _this;
    _this = (corto_case)corto_declare(_parent, _id, corto_case_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_caseDefine(corto_case _this, corto_int32seq discriminator, corto_type type, corto_modifier modifiers) {
    CORTO_UNUSED(_this);
    corto_ptr_copy(&((corto_case)_this)->discriminator, corto_int32seq_o, &discriminator);
    corto_set_ref(&((corto_member)_this)->type, type);
    ((corto_member)_this)->modifiers = modifiers;
    return corto_define(_this);
}

corto_case _corto_caseAssign(corto_case _this, corto_int32seq discriminator, corto_type type, corto_modifier modifiers) {
    CORTO_UNUSED(_this);
    corto_ptr_copy(&((corto_case)_this)->discriminator, corto_int32seq_o, &discriminator);
    corto_set_ref(&((corto_member)_this)->type, type);
    ((corto_member)_this)->modifiers = modifiers;
    return _this;
}

char* _corto_charCreate(char value) {
    char* _this;
    _this = (char*)corto_declare(NULL, NULL, corto_char_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        *_this = value;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

char* _corto_charCreateChild(corto_object _parent, const char *_id, char value) {
    char* _this;
    _this = (char*)corto_declare(_parent, _id, corto_char_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        *_this = value;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_charUpdate(char* _this, char value) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            *((char*)CORTO_OFFSET(_this, ((corto_type)corto_char_o)->size)) = value;
        } else {
            *_this = value;
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

char* _corto_charDeclare(void) {
    char* _this;
    _this = (char*)corto_declare(NULL, NULL, corto_char_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

char* _corto_charDeclareChild(corto_object _parent, const char *_id) {
    char* _this;
    _this = (char*)corto_declare(_parent, _id, corto_char_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_charDefine(char* _this, char value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return corto_define(_this);
}

char* _corto_charAssign(char* _this, char value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

corto_character _corto_characterCreate(corto_width width) {
    corto_character _this;
    _this = (corto_character)corto_declare(NULL, NULL, corto_character_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        ((corto_primitive)_this)->width = width;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_character _corto_characterCreateChild(corto_object _parent, const char *_id, corto_width width) {
    corto_character _this;
    _this = (corto_character)corto_declare(_parent, _id, corto_character_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        ((corto_primitive)_this)->width = width;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_characterUpdate(corto_character _this, corto_width width) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            ((corto_primitive)((corto_character)CORTO_OFFSET(_this, ((corto_type)corto_character_o)->size)))->width = width;
        } else {
            ((corto_primitive)_this)->width = width;
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

corto_character _corto_characterDeclare(void) {
    corto_character _this;
    _this = (corto_character)corto_declare(NULL, NULL, corto_character_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_character _corto_characterDeclareChild(corto_object _parent, const char *_id) {
    corto_character _this;
    _this = (corto_character)corto_declare(_parent, _id, corto_character_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_characterDefine(corto_character _this, corto_width width) {
    CORTO_UNUSED(_this);
    ((corto_primitive)_this)->width = width;
    return corto_define(_this);
}

corto_character _corto_characterAssign(corto_character _this, corto_width width) {
    CORTO_UNUSED(_this);
    ((corto_primitive)_this)->width = width;
    return _this;
}

corto_class _corto_classCreate(corto_interface base, corto_modifier baseAccess, corto_interfaceseq implements) {
    corto_class _this;
    _this = (corto_class)corto_declare(NULL, NULL, corto_class_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_ref(&((corto_interface)_this)->base, base);
        ((corto_struct)_this)->baseAccess = baseAccess;
        corto_ptr_copy(&((corto_class)_this)->implements, corto_interfaceseq_o, &implements);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_class _corto_classCreateChild(corto_object _parent, const char *_id, corto_interface base, corto_modifier baseAccess, corto_interfaceseq implements) {
    corto_class _this;
    _this = (corto_class)corto_declare(_parent, _id, corto_class_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_ref(&((corto_interface)_this)->base, base);
        ((corto_struct)_this)->baseAccess = baseAccess;
        corto_ptr_copy(&((corto_class)_this)->implements, corto_interfaceseq_o, &implements);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_classUpdate(corto_class _this, corto_interface base, corto_modifier baseAccess, corto_interfaceseq implements) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_set_ref(&((corto_interface)((corto_class)CORTO_OFFSET(_this, ((corto_type)corto_class_o)->size)))->base, base);
            ((corto_struct)((corto_class)CORTO_OFFSET(_this, ((corto_type)corto_class_o)->size)))->baseAccess = baseAccess;
            corto_ptr_copy(&((corto_class)((corto_class)CORTO_OFFSET(_this, ((corto_type)corto_class_o)->size)))->implements, corto_interfaceseq_o, &implements);
        } else {
            corto_set_ref(&((corto_interface)_this)->base, base);
            ((corto_struct)_this)->baseAccess = baseAccess;
            corto_ptr_copy(&((corto_class)_this)->implements, corto_interfaceseq_o, &implements);
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

corto_class _corto_classDeclare(void) {
    corto_class _this;
    _this = (corto_class)corto_declare(NULL, NULL, corto_class_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_class _corto_classDeclareChild(corto_object _parent, const char *_id) {
    corto_class _this;
    _this = (corto_class)corto_declare(_parent, _id, corto_class_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_classDefine(corto_class _this, corto_interface base, corto_modifier baseAccess, corto_interfaceseq implements) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_interface)_this)->base, base);
    ((corto_struct)_this)->baseAccess = baseAccess;
    corto_ptr_copy(&((corto_class)_this)->implements, corto_interfaceseq_o, &implements);
    return corto_define(_this);
}

corto_class _corto_classAssign(corto_class _this, corto_interface base, corto_modifier baseAccess, corto_interfaceseq implements) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_interface)_this)->base, base);
    ((corto_struct)_this)->baseAccess = baseAccess;
    corto_ptr_copy(&((corto_class)_this)->implements, corto_interfaceseq_o, &implements);
    return _this;
}

corto_collection _corto_collectionCreate(corto_type elementType, uint32_t max) {
    corto_collection _this;
    _this = (corto_collection)corto_declare(NULL, NULL, corto_collection_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_ref(&((corto_collection)_this)->elementType, elementType);
        ((corto_collection)_this)->max = max;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_collection _corto_collectionCreateChild(corto_object _parent, const char *_id, corto_type elementType, uint32_t max) {
    corto_collection _this;
    _this = (corto_collection)corto_declare(_parent, _id, corto_collection_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_ref(&((corto_collection)_this)->elementType, elementType);
        ((corto_collection)_this)->max = max;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_collectionUpdate(corto_collection _this, corto_type elementType, uint32_t max) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_set_ref(&((corto_collection)((corto_collection)CORTO_OFFSET(_this, ((corto_type)corto_collection_o)->size)))->elementType, elementType);
            ((corto_collection)((corto_collection)CORTO_OFFSET(_this, ((corto_type)corto_collection_o)->size)))->max = max;
        } else {
            corto_set_ref(&((corto_collection)_this)->elementType, elementType);
            ((corto_collection)_this)->max = max;
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

corto_collection _corto_collectionDeclare(void) {
    corto_collection _this;
    _this = (corto_collection)corto_declare(NULL, NULL, corto_collection_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_collection _corto_collectionDeclareChild(corto_object _parent, const char *_id) {
    corto_collection _this;
    _this = (corto_collection)corto_declare(_parent, _id, corto_collection_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_collectionDefine(corto_collection _this, corto_type elementType, uint32_t max) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_collection)_this)->elementType, elementType);
    ((corto_collection)_this)->max = max;
    return corto_define(_this);
}

corto_collection _corto_collectionAssign(corto_collection _this, corto_type elementType, uint32_t max) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_collection)_this)->elementType, elementType);
    ((corto_collection)_this)->max = max;
    return _this;
}

corto_collectionKind* _corto_collectionKindCreate(corto_collectionKind value) {
    corto_collectionKind* _this;
    _this = (corto_collectionKind*)corto_declare(NULL, NULL, corto_collectionKind_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        *_this = value;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_collectionKind* _corto_collectionKindCreateChild(corto_object _parent, const char *_id, corto_collectionKind value) {
    corto_collectionKind* _this;
    _this = (corto_collectionKind*)corto_declare(_parent, _id, corto_collectionKind_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        *_this = value;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_collectionKindUpdate(corto_collectionKind* _this, corto_collectionKind value) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            *((corto_collectionKind*)CORTO_OFFSET(_this, ((corto_type)corto_collectionKind_o)->size)) = value;
        } else {
            *_this = value;
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

corto_collectionKind* _corto_collectionKindDeclare(void) {
    corto_collectionKind* _this;
    _this = (corto_collectionKind*)corto_declare(NULL, NULL, corto_collectionKind_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_collectionKind* _corto_collectionKindDeclareChild(corto_object _parent, const char *_id) {
    corto_collectionKind* _this;
    _this = (corto_collectionKind*)corto_declare(_parent, _id, corto_collectionKind_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_collectionKindDefine(corto_collectionKind* _this, corto_collectionKind value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return corto_define(_this);
}

corto_collectionKind* _corto_collectionKindAssign(corto_collectionKind* _this, corto_collectionKind value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

corto_compositeKind* _corto_compositeKindCreate(corto_compositeKind value) {
    corto_compositeKind* _this;
    _this = (corto_compositeKind*)corto_declare(NULL, NULL, corto_compositeKind_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        *_this = value;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_compositeKind* _corto_compositeKindCreateChild(corto_object _parent, const char *_id, corto_compositeKind value) {
    corto_compositeKind* _this;
    _this = (corto_compositeKind*)corto_declare(_parent, _id, corto_compositeKind_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        *_this = value;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_compositeKindUpdate(corto_compositeKind* _this, corto_compositeKind value) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            *((corto_compositeKind*)CORTO_OFFSET(_this, ((corto_type)corto_compositeKind_o)->size)) = value;
        } else {
            *_this = value;
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

corto_compositeKind* _corto_compositeKindDeclare(void) {
    corto_compositeKind* _this;
    _this = (corto_compositeKind*)corto_declare(NULL, NULL, corto_compositeKind_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_compositeKind* _corto_compositeKindDeclareChild(corto_object _parent, const char *_id) {
    corto_compositeKind* _this;
    _this = (corto_compositeKind*)corto_declare(_parent, _id, corto_compositeKind_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_compositeKindDefine(corto_compositeKind* _this, corto_compositeKind value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return corto_define(_this);
}

corto_compositeKind* _corto_compositeKindAssign(corto_compositeKind* _this, corto_compositeKind value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

int32_t* _corto_constantCreate(int32_t value) {
    int32_t* _this;
    _this = (int32_t*)corto_declare(NULL, NULL, corto_constant_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        *_this = value;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

int32_t* _corto_constantCreateChild(corto_object _parent, const char *_id, int32_t value) {
    int32_t* _this;
    _this = (int32_t*)corto_declare(_parent, _id, corto_constant_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        *_this = value;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_constantUpdate(int32_t* _this, int32_t value) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            *((int32_t*)CORTO_OFFSET(_this, ((corto_type)corto_constant_o)->size)) = value;
        } else {
            *_this = value;
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

int32_t* _corto_constantDeclare(void) {
    int32_t* _this;
    _this = (int32_t*)corto_declare(NULL, NULL, corto_constant_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

int32_t* _corto_constantDeclareChild(corto_object _parent, const char *_id) {
    int32_t* _this;
    _this = (int32_t*)corto_declare(_parent, _id, corto_constant_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_constantDefine(int32_t* _this, int32_t value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return corto_define(_this);
}

int32_t* _corto_constantAssign(int32_t* _this, int32_t value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

corto_container _corto_containerCreate(corto_interface base, corto_modifier baseAccess, corto_interfaceseq implements, corto_type type, const char * value) {
    corto_container _this;
    _this = (corto_container)corto_declare(NULL, NULL, corto_container_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_ref(&((corto_interface)_this)->base, base);
        ((corto_struct)_this)->baseAccess = baseAccess;
        corto_ptr_copy(&((corto_class)_this)->implements, corto_interfaceseq_o, &implements);
        corto_set_ref(&((corto_container)_this)->type, type);
        corto_set_str(&((corto_container)_this)->value, value);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_container _corto_containerCreateChild(corto_object _parent, const char *_id, corto_interface base, corto_modifier baseAccess, corto_interfaceseq implements, corto_type type, const char * value) {
    corto_container _this;
    _this = (corto_container)corto_declare(_parent, _id, corto_container_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_ref(&((corto_interface)_this)->base, base);
        ((corto_struct)_this)->baseAccess = baseAccess;
        corto_ptr_copy(&((corto_class)_this)->implements, corto_interfaceseq_o, &implements);
        corto_set_ref(&((corto_container)_this)->type, type);
        corto_set_str(&((corto_container)_this)->value, value);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_containerUpdate(corto_container _this, corto_interface base, corto_modifier baseAccess, corto_interfaceseq implements, corto_type type, const char * value) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_set_ref(&((corto_interface)((corto_container)CORTO_OFFSET(_this, ((corto_type)corto_container_o)->size)))->base, base);
            ((corto_struct)((corto_container)CORTO_OFFSET(_this, ((corto_type)corto_container_o)->size)))->baseAccess = baseAccess;
            corto_ptr_copy(&((corto_class)((corto_container)CORTO_OFFSET(_this, ((corto_type)corto_container_o)->size)))->implements, corto_interfaceseq_o, &implements);
            corto_set_ref(&((corto_container)((corto_container)CORTO_OFFSET(_this, ((corto_type)corto_container_o)->size)))->type, type);
            corto_set_str(&((corto_container)((corto_container)CORTO_OFFSET(_this, ((corto_type)corto_container_o)->size)))->value, value);
        } else {
            corto_set_ref(&((corto_interface)_this)->base, base);
            ((corto_struct)_this)->baseAccess = baseAccess;
            corto_ptr_copy(&((corto_class)_this)->implements, corto_interfaceseq_o, &implements);
            corto_set_ref(&((corto_container)_this)->type, type);
            corto_set_str(&((corto_container)_this)->value, value);
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

corto_container _corto_containerDeclare(void) {
    corto_container _this;
    _this = (corto_container)corto_declare(NULL, NULL, corto_container_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_container _corto_containerDeclareChild(corto_object _parent, const char *_id) {
    corto_container _this;
    _this = (corto_container)corto_declare(_parent, _id, corto_container_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_containerDefine(corto_container _this, corto_interface base, corto_modifier baseAccess, corto_interfaceseq implements, corto_type type, const char * value) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_interface)_this)->base, base);
    ((corto_struct)_this)->baseAccess = baseAccess;
    corto_ptr_copy(&((corto_class)_this)->implements, corto_interfaceseq_o, &implements);
    corto_set_ref(&((corto_container)_this)->type, type);
    corto_set_str(&((corto_container)_this)->value, value);
    return corto_define(_this);
}

corto_container _corto_containerAssign(corto_container _this, corto_interface base, corto_modifier baseAccess, corto_interfaceseq implements, corto_type type, const char * value) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_interface)_this)->base, base);
    ((corto_struct)_this)->baseAccess = baseAccess;
    corto_ptr_copy(&((corto_class)_this)->implements, corto_interfaceseq_o, &implements);
    corto_set_ref(&((corto_container)_this)->type, type);
    corto_set_str(&((corto_container)_this)->value, value);
    return _this;
}

corto_default _corto_defaultCreate(corto_type type) {
    corto_default _this;
    _this = (corto_default)corto_declare(NULL, NULL, corto_default_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_ref(&((corto_member)_this)->type, type);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_default _corto_defaultCreateChild(corto_object _parent, const char *_id, corto_type type) {
    corto_default _this;
    _this = (corto_default)corto_declare(_parent, _id, corto_default_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_ref(&((corto_member)_this)->type, type);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_defaultUpdate(corto_default _this, corto_type type) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_set_ref(&((corto_member)((corto_default)CORTO_OFFSET(_this, ((corto_type)corto_default_o)->size)))->type, type);
        } else {
            corto_set_ref(&((corto_member)_this)->type, type);
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

corto_default _corto_defaultDeclare(void) {
    corto_default _this;
    _this = (corto_default)corto_declare(NULL, NULL, corto_default_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_default _corto_defaultDeclareChild(corto_object _parent, const char *_id) {
    corto_default _this;
    _this = (corto_default)corto_declare(_parent, _id, corto_default_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_defaultDefine(corto_default _this, corto_type type) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_member)_this)->type, type);
    return corto_define(_this);
}

corto_default _corto_defaultAssign(corto_default _this, corto_type type) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_member)_this)->type, type);
    return _this;
}

corto_delegate _corto_delegateCreate(corto_type returnType, bool returnsReference, corto_parameterseq parameters) {
    corto_delegate _this;
    _this = (corto_delegate)corto_declare(NULL, NULL, corto_delegate_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_ref(&((corto_delegate)_this)->returnType, returnType);
        ((corto_delegate)_this)->returnsReference = returnsReference;
        corto_ptr_copy(&((corto_delegate)_this)->parameters, corto_parameterseq_o, &parameters);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_delegate _corto_delegateCreateChild(corto_object _parent, const char *_id, corto_type returnType, bool returnsReference, corto_parameterseq parameters) {
    corto_delegate _this;
    _this = (corto_delegate)corto_declare(_parent, _id, corto_delegate_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_ref(&((corto_delegate)_this)->returnType, returnType);
        ((corto_delegate)_this)->returnsReference = returnsReference;
        corto_ptr_copy(&((corto_delegate)_this)->parameters, corto_parameterseq_o, &parameters);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_delegateUpdate(corto_delegate _this, corto_type returnType, bool returnsReference, corto_parameterseq parameters) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_set_ref(&((corto_delegate)((corto_delegate)CORTO_OFFSET(_this, ((corto_type)corto_delegate_o)->size)))->returnType, returnType);
            ((corto_delegate)((corto_delegate)CORTO_OFFSET(_this, ((corto_type)corto_delegate_o)->size)))->returnsReference = returnsReference;
            corto_ptr_copy(&((corto_delegate)((corto_delegate)CORTO_OFFSET(_this, ((corto_type)corto_delegate_o)->size)))->parameters, corto_parameterseq_o, &parameters);
        } else {
            corto_set_ref(&((corto_delegate)_this)->returnType, returnType);
            ((corto_delegate)_this)->returnsReference = returnsReference;
            corto_ptr_copy(&((corto_delegate)_this)->parameters, corto_parameterseq_o, &parameters);
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

corto_delegate _corto_delegateDeclare(void) {
    corto_delegate _this;
    _this = (corto_delegate)corto_declare(NULL, NULL, corto_delegate_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_delegate _corto_delegateDeclareChild(corto_object _parent, const char *_id) {
    corto_delegate _this;
    _this = (corto_delegate)corto_declare(_parent, _id, corto_delegate_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_delegateDefine(corto_delegate _this, corto_type returnType, bool returnsReference, corto_parameterseq parameters) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_delegate)_this)->returnType, returnType);
    ((corto_delegate)_this)->returnsReference = returnsReference;
    corto_ptr_copy(&((corto_delegate)_this)->parameters, corto_parameterseq_o, &parameters);
    return corto_define(_this);
}

corto_delegate _corto_delegateAssign(corto_delegate _this, corto_type returnType, bool returnsReference, corto_parameterseq parameters) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_delegate)_this)->returnType, returnType);
    ((corto_delegate)_this)->returnsReference = returnsReference;
    corto_ptr_copy(&((corto_delegate)_this)->parameters, corto_parameterseq_o, &parameters);
    return _this;
}

corto_delegatedata* _corto_delegatedataCreate(corto_object instance, corto_function procedure) {
    corto_delegatedata* _this;
    _this = (corto_delegatedata*)corto_declare(NULL, NULL, corto_delegatedata_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_ref(&((corto_delegatedata*)_this)->instance, instance);
        corto_set_ref(&((corto_delegatedata*)_this)->procedure, procedure);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_delegatedata* _corto_delegatedataCreateChild(corto_object _parent, const char *_id, corto_object instance, corto_function procedure) {
    corto_delegatedata* _this;
    _this = (corto_delegatedata*)corto_declare(_parent, _id, corto_delegatedata_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_ref(&((corto_delegatedata*)_this)->instance, instance);
        corto_set_ref(&((corto_delegatedata*)_this)->procedure, procedure);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_delegatedataUpdate(corto_delegatedata* _this, corto_object instance, corto_function procedure) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_set_ref(&((corto_delegatedata*)((corto_delegatedata*)CORTO_OFFSET(_this, ((corto_type)corto_delegatedata_o)->size)))->instance, instance);
            corto_set_ref(&((corto_delegatedata*)((corto_delegatedata*)CORTO_OFFSET(_this, ((corto_type)corto_delegatedata_o)->size)))->procedure, procedure);
        } else {
            corto_set_ref(&((corto_delegatedata*)_this)->instance, instance);
            corto_set_ref(&((corto_delegatedata*)_this)->procedure, procedure);
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

corto_delegatedata* _corto_delegatedataDeclare(void) {
    corto_delegatedata* _this;
    _this = (corto_delegatedata*)corto_declare(NULL, NULL, corto_delegatedata_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_delegatedata* _corto_delegatedataDeclareChild(corto_object _parent, const char *_id) {
    corto_delegatedata* _this;
    _this = (corto_delegatedata*)corto_declare(_parent, _id, corto_delegatedata_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_delegatedataDefine(corto_delegatedata* _this, corto_object instance, corto_function procedure) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_delegatedata*)_this)->instance, instance);
    corto_set_ref(&((corto_delegatedata*)_this)->procedure, procedure);
    return corto_define(_this);
}

corto_delegatedata* _corto_delegatedataAssign(corto_delegatedata* _this, corto_object instance, corto_function procedure) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_delegatedata*)_this)->instance, instance);
    corto_set_ref(&((corto_delegatedata*)_this)->procedure, procedure);
    return _this;
}

corto_enum _corto_enumCreate(void) {
    corto_enum _this;
    _this = (corto_enum)corto_declare(NULL, NULL, corto_enum_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_enum _corto_enumCreateChild(corto_object _parent, const char *_id) {
    corto_enum _this;
    _this = (corto_enum)corto_declare(_parent, _id, corto_enum_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_enumUpdate(corto_enum _this) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
        } else {
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

corto_enum _corto_enumDeclare(void) {
    corto_enum _this;
    _this = (corto_enum)corto_declare(NULL, NULL, corto_enum_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_enum _corto_enumDeclareChild(corto_object _parent, const char *_id) {
    corto_enum _this;
    _this = (corto_enum)corto_declare(_parent, _id, corto_enum_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_enumDefine(corto_enum _this) {
    CORTO_UNUSED(_this);
    return corto_define(_this);
}

corto_enum _corto_enumAssign(corto_enum _this) {
    CORTO_UNUSED(_this);
    return _this;
}

corto_equalityKind* _corto_equalityKindCreate(corto_equalityKind value) {
    corto_equalityKind* _this;
    _this = (corto_equalityKind*)corto_declare(NULL, NULL, corto_equalityKind_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        *_this = value;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_equalityKind* _corto_equalityKindCreateChild(corto_object _parent, const char *_id, corto_equalityKind value) {
    corto_equalityKind* _this;
    _this = (corto_equalityKind*)corto_declare(_parent, _id, corto_equalityKind_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        *_this = value;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_equalityKindUpdate(corto_equalityKind* _this, corto_equalityKind value) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            *((corto_equalityKind*)CORTO_OFFSET(_this, ((corto_type)corto_equalityKind_o)->size)) = value;
        } else {
            *_this = value;
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

corto_equalityKind* _corto_equalityKindDeclare(void) {
    corto_equalityKind* _this;
    _this = (corto_equalityKind*)corto_declare(NULL, NULL, corto_equalityKind_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_equalityKind* _corto_equalityKindDeclareChild(corto_object _parent, const char *_id) {
    corto_equalityKind* _this;
    _this = (corto_equalityKind*)corto_declare(_parent, _id, corto_equalityKind_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_equalityKindDefine(corto_equalityKind* _this, corto_equalityKind value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return corto_define(_this);
}

corto_equalityKind* _corto_equalityKindAssign(corto_equalityKind* _this, corto_equalityKind value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

corto_float _corto_floatCreate(corto_width width, double min, double max) {
    corto_float _this;
    _this = (corto_float)corto_declare(NULL, NULL, corto_float_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        ((corto_primitive)_this)->width = width;
        ((corto_float)_this)->min = min;
        ((corto_float)_this)->max = max;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_float _corto_floatCreateChild(corto_object _parent, const char *_id, corto_width width, double min, double max) {
    corto_float _this;
    _this = (corto_float)corto_declare(_parent, _id, corto_float_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        ((corto_primitive)_this)->width = width;
        ((corto_float)_this)->min = min;
        ((corto_float)_this)->max = max;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_floatUpdate(corto_float _this, corto_width width, double min, double max) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            ((corto_primitive)((corto_float)CORTO_OFFSET(_this, ((corto_type)corto_float_o)->size)))->width = width;
            ((corto_float)((corto_float)CORTO_OFFSET(_this, ((corto_type)corto_float_o)->size)))->min = min;
            ((corto_float)((corto_float)CORTO_OFFSET(_this, ((corto_type)corto_float_o)->size)))->max = max;
        } else {
            ((corto_primitive)_this)->width = width;
            ((corto_float)_this)->min = min;
            ((corto_float)_this)->max = max;
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

corto_float _corto_floatDeclare(void) {
    corto_float _this;
    _this = (corto_float)corto_declare(NULL, NULL, corto_float_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_float _corto_floatDeclareChild(corto_object _parent, const char *_id) {
    corto_float _this;
    _this = (corto_float)corto_declare(_parent, _id, corto_float_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_floatDefine(corto_float _this, corto_width width, double min, double max) {
    CORTO_UNUSED(_this);
    ((corto_primitive)_this)->width = width;
    ((corto_float)_this)->min = min;
    ((corto_float)_this)->max = max;
    return corto_define(_this);
}

corto_float _corto_floatAssign(corto_float _this, corto_width width, double min, double max) {
    CORTO_UNUSED(_this);
    ((corto_primitive)_this)->width = width;
    ((corto_float)_this)->min = min;
    ((corto_float)_this)->max = max;
    return _this;
}

float* _corto_float32Create(float value) {
    float* _this;
    _this = (float*)corto_declare(NULL, NULL, corto_float32_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        *_this = value;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

float* _corto_float32CreateChild(corto_object _parent, const char *_id, float value) {
    float* _this;
    _this = (float*)corto_declare(_parent, _id, corto_float32_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        *_this = value;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_float32Update(float* _this, float value) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            *((float*)CORTO_OFFSET(_this, ((corto_type)corto_float32_o)->size)) = value;
        } else {
            *_this = value;
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

float* _corto_float32Declare(void) {
    float* _this;
    _this = (float*)corto_declare(NULL, NULL, corto_float32_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

float* _corto_float32DeclareChild(corto_object _parent, const char *_id) {
    float* _this;
    _this = (float*)corto_declare(_parent, _id, corto_float32_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_float32Define(float* _this, float value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return corto_define(_this);
}

float* _corto_float32Assign(float* _this, float value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

double* _corto_float64Create(double value) {
    double* _this;
    _this = (double*)corto_declare(NULL, NULL, corto_float64_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        *_this = value;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

double* _corto_float64CreateChild(corto_object _parent, const char *_id, double value) {
    double* _this;
    _this = (double*)corto_declare(_parent, _id, corto_float64_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        *_this = value;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_float64Update(double* _this, double value) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            *((double*)CORTO_OFFSET(_this, ((corto_type)corto_float64_o)->size)) = value;
        } else {
            *_this = value;
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

double* _corto_float64Declare(void) {
    double* _this;
    _this = (double*)corto_declare(NULL, NULL, corto_float64_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

double* _corto_float64DeclareChild(corto_object _parent, const char *_id) {
    double* _this;
    _this = (double*)corto_declare(_parent, _id, corto_float64_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_float64Define(double* _this, double value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return corto_define(_this);
}

double* _corto_float64Assign(double* _this, double value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

corto_function _corto_functionCreate(corto_type returnType, bool returnsReference, void(*_impl)(void)) {
    corto_function _this;
    _this = (corto_function)corto_declare(NULL, NULL, corto_function_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_ref(&((corto_function)_this)->returnType, returnType);
        ((corto_function)_this)->returnsReference = returnsReference;
        corto_function(_this)->kind = CORTO_PROCEDURE_CDECL;
        corto_function(_this)->fptr = (corto_word)_impl;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_function _corto_functionCreateChild(corto_object _parent, const char *_id, corto_type returnType, bool returnsReference, void(*_impl)(void)) {
    corto_function _this;
    _this = (corto_function)corto_declare(_parent, _id, corto_function_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_ref(&((corto_function)_this)->returnType, returnType);
        ((corto_function)_this)->returnsReference = returnsReference;
        corto_function(_this)->kind = CORTO_PROCEDURE_CDECL;
        corto_function(_this)->fptr = (corto_word)_impl;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_functionUpdate(corto_function _this, corto_type returnType, bool returnsReference, void(*_impl)(void)) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_set_ref(&((corto_function)((corto_function)CORTO_OFFSET(_this, ((corto_type)corto_function_o)->size)))->returnType, returnType);
            ((corto_function)((corto_function)CORTO_OFFSET(_this, ((corto_type)corto_function_o)->size)))->returnsReference = returnsReference;
            corto_function(((corto_function)CORTO_OFFSET(_this, ((corto_type)corto_function_o)->size)))->kind = CORTO_PROCEDURE_CDECL;
            corto_function(((corto_function)CORTO_OFFSET(_this, ((corto_type)corto_function_o)->size)))->fptr = (corto_word)_impl;
        } else {
            corto_set_ref(&((corto_function)_this)->returnType, returnType);
            ((corto_function)_this)->returnsReference = returnsReference;
            corto_function(_this)->kind = CORTO_PROCEDURE_CDECL;
            corto_function(_this)->fptr = (corto_word)_impl;
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

corto_function _corto_functionDeclare(void) {
    corto_function _this;
    _this = (corto_function)corto_declare(NULL, NULL, corto_function_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_function _corto_functionDeclareChild(corto_object _parent, const char *_id) {
    corto_function _this;
    _this = (corto_function)corto_declare(_parent, _id, corto_function_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_functionDefine(corto_function _this, corto_type returnType, bool returnsReference, void(*_impl)(void)) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_function)_this)->returnType, returnType);
    ((corto_function)_this)->returnsReference = returnsReference;
    corto_function(_this)->kind = CORTO_PROCEDURE_CDECL;
    corto_function(_this)->fptr = (corto_word)_impl;
    return corto_define(_this);
}

corto_function _corto_functionAssign(corto_function _this, corto_type returnType, bool returnsReference, void(*_impl)(void)) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_function)_this)->returnType, returnType);
    ((corto_function)_this)->returnsReference = returnsReference;
    corto_function(_this)->kind = CORTO_PROCEDURE_CDECL;
    corto_function(_this)->fptr = (corto_word)_impl;
    return _this;
}

corto_inout* _corto_inoutCreate(corto_inout value) {
    corto_inout* _this;
    _this = (corto_inout*)corto_declare(NULL, NULL, corto_inout_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        *_this = value;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_inout* _corto_inoutCreateChild(corto_object _parent, const char *_id, corto_inout value) {
    corto_inout* _this;
    _this = (corto_inout*)corto_declare(_parent, _id, corto_inout_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        *_this = value;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_inoutUpdate(corto_inout* _this, corto_inout value) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            *((corto_inout*)CORTO_OFFSET(_this, ((corto_type)corto_inout_o)->size)) = value;
        } else {
            *_this = value;
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

corto_inout* _corto_inoutDeclare(void) {
    corto_inout* _this;
    _this = (corto_inout*)corto_declare(NULL, NULL, corto_inout_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_inout* _corto_inoutDeclareChild(corto_object _parent, const char *_id) {
    corto_inout* _this;
    _this = (corto_inout*)corto_declare(_parent, _id, corto_inout_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_inoutDefine(corto_inout* _this, corto_inout value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return corto_define(_this);
}

corto_inout* _corto_inoutAssign(corto_inout* _this, corto_inout value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

corto_int _corto_intCreate(corto_width width, int64_t min, int64_t max) {
    corto_int _this;
    _this = (corto_int)corto_declare(NULL, NULL, corto_int_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        ((corto_primitive)_this)->width = width;
        ((corto_int)_this)->min = min;
        ((corto_int)_this)->max = max;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int _corto_intCreateChild(corto_object _parent, const char *_id, corto_width width, int64_t min, int64_t max) {
    corto_int _this;
    _this = (corto_int)corto_declare(_parent, _id, corto_int_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        ((corto_primitive)_this)->width = width;
        ((corto_int)_this)->min = min;
        ((corto_int)_this)->max = max;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_intUpdate(corto_int _this, corto_width width, int64_t min, int64_t max) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            ((corto_primitive)((corto_int)CORTO_OFFSET(_this, ((corto_type)corto_int_o)->size)))->width = width;
            ((corto_int)((corto_int)CORTO_OFFSET(_this, ((corto_type)corto_int_o)->size)))->min = min;
            ((corto_int)((corto_int)CORTO_OFFSET(_this, ((corto_type)corto_int_o)->size)))->max = max;
        } else {
            ((corto_primitive)_this)->width = width;
            ((corto_int)_this)->min = min;
            ((corto_int)_this)->max = max;
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

corto_int _corto_intDeclare(void) {
    corto_int _this;
    _this = (corto_int)corto_declare(NULL, NULL, corto_int_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int _corto_intDeclareChild(corto_object _parent, const char *_id) {
    corto_int _this;
    _this = (corto_int)corto_declare(_parent, _id, corto_int_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_intDefine(corto_int _this, corto_width width, int64_t min, int64_t max) {
    CORTO_UNUSED(_this);
    ((corto_primitive)_this)->width = width;
    ((corto_int)_this)->min = min;
    ((corto_int)_this)->max = max;
    return corto_define(_this);
}

corto_int _corto_intAssign(corto_int _this, corto_width width, int64_t min, int64_t max) {
    CORTO_UNUSED(_this);
    ((corto_primitive)_this)->width = width;
    ((corto_int)_this)->min = min;
    ((corto_int)_this)->max = max;
    return _this;
}

int16_t* _corto_int16Create(int16_t value) {
    int16_t* _this;
    _this = (int16_t*)corto_declare(NULL, NULL, corto_int16_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        *_this = value;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

int16_t* _corto_int16CreateChild(corto_object _parent, const char *_id, int16_t value) {
    int16_t* _this;
    _this = (int16_t*)corto_declare(_parent, _id, corto_int16_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        *_this = value;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_int16Update(int16_t* _this, int16_t value) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            *((int16_t*)CORTO_OFFSET(_this, ((corto_type)corto_int16_o)->size)) = value;
        } else {
            *_this = value;
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

int16_t* _corto_int16Declare(void) {
    int16_t* _this;
    _this = (int16_t*)corto_declare(NULL, NULL, corto_int16_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

int16_t* _corto_int16DeclareChild(corto_object _parent, const char *_id) {
    int16_t* _this;
    _this = (int16_t*)corto_declare(_parent, _id, corto_int16_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_int16Define(int16_t* _this, int16_t value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return corto_define(_this);
}

int16_t* _corto_int16Assign(int16_t* _this, int16_t value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

int32_t* _corto_int32Create(int32_t value) {
    int32_t* _this;
    _this = (int32_t*)corto_declare(NULL, NULL, corto_int32_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        *_this = value;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

int32_t* _corto_int32CreateChild(corto_object _parent, const char *_id, int32_t value) {
    int32_t* _this;
    _this = (int32_t*)corto_declare(_parent, _id, corto_int32_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        *_this = value;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_int32Update(int32_t* _this, int32_t value) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            *((int32_t*)CORTO_OFFSET(_this, ((corto_type)corto_int32_o)->size)) = value;
        } else {
            *_this = value;
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

int32_t* _corto_int32Declare(void) {
    int32_t* _this;
    _this = (int32_t*)corto_declare(NULL, NULL, corto_int32_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

int32_t* _corto_int32DeclareChild(corto_object _parent, const char *_id) {
    int32_t* _this;
    _this = (int32_t*)corto_declare(_parent, _id, corto_int32_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_int32Define(int32_t* _this, int32_t value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return corto_define(_this);
}

int32_t* _corto_int32Assign(int32_t* _this, int32_t value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

corto_int32seq* _corto_int32seqCreate(corto_uint32 length, int32_t* elements) {
    corto_int32seq* _this;
    _this = (corto_int32seq*)corto_declare(NULL, NULL, corto_int32seq_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_int32seqResize(_this, length);
        corto_uint32 i = 0;
        for (i = 0; i < length; i ++) {
            _this->buffer[i] = elements[i];
        }
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int32seq* _corto_int32seqCreateChild(corto_object _parent, const char *_id, corto_uint32 length, int32_t* elements) {
    corto_int32seq* _this;
    _this = (corto_int32seq*)corto_declare(_parent, _id, corto_int32seq_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_int32seqResize(_this, length);
        corto_uint32 i = 0;
        for (i = 0; i < length; i ++) {
            _this->buffer[i] = elements[i];
        }
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_int32seqUpdate(corto_int32seq* _this, corto_uint32 length, int32_t* elements) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_int32seqResize(((corto_int32seq*)CORTO_OFFSET(_this, ((corto_type)corto_int32seq_o)->size)), length);
            corto_uint32 i = 0;
            for (i = 0; i < length; i ++) {
                ((corto_int32seq*)CORTO_OFFSET(_this, ((corto_type)corto_int32seq_o)->size))->buffer[i] = elements[i];
            }
        } else {
            corto_int32seqResize(_this, length);
            corto_uint32 i = 0;
            for (i = 0; i < length; i ++) {
                _this->buffer[i] = elements[i];
            }
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

corto_int32seq* _corto_int32seqDeclare(void) {
    corto_int32seq* _this;
    _this = (corto_int32seq*)corto_declare(NULL, NULL, corto_int32seq_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int32seq* _corto_int32seqDeclareChild(corto_object _parent, const char *_id) {
    corto_int32seq* _this;
    _this = (corto_int32seq*)corto_declare(_parent, _id, corto_int32seq_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_int32seqDefine(corto_int32seq* _this, corto_uint32 length, int32_t* elements) {
    CORTO_UNUSED(_this);
    corto_int32seqResize(_this, length);
    corto_uint32 i = 0;
    for (i = 0; i < length; i ++) {
        _this->buffer[i] = elements[i];
    }
    return corto_define(_this);
}

corto_int32seq* _corto_int32seqAssign(corto_int32seq* _this, corto_uint32 length, int32_t* elements) {
    CORTO_UNUSED(_this);
    corto_int32seqResize(_this, length);
    corto_uint32 i = 0;
    for (i = 0; i < length; i ++) {
        _this->buffer[i] = elements[i];
    }
    return _this;
}

int64_t* _corto_int64Create(int64_t value) {
    int64_t* _this;
    _this = (int64_t*)corto_declare(NULL, NULL, corto_int64_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        *_this = value;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

int64_t* _corto_int64CreateChild(corto_object _parent, const char *_id, int64_t value) {
    int64_t* _this;
    _this = (int64_t*)corto_declare(_parent, _id, corto_int64_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        *_this = value;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_int64Update(int64_t* _this, int64_t value) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            *((int64_t*)CORTO_OFFSET(_this, ((corto_type)corto_int64_o)->size)) = value;
        } else {
            *_this = value;
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

int64_t* _corto_int64Declare(void) {
    int64_t* _this;
    _this = (int64_t*)corto_declare(NULL, NULL, corto_int64_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

int64_t* _corto_int64DeclareChild(corto_object _parent, const char *_id) {
    int64_t* _this;
    _this = (int64_t*)corto_declare(_parent, _id, corto_int64_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_int64Define(int64_t* _this, int64_t value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return corto_define(_this);
}

int64_t* _corto_int64Assign(int64_t* _this, int64_t value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

int8_t* _corto_int8Create(int8_t value) {
    int8_t* _this;
    _this = (int8_t*)corto_declare(NULL, NULL, corto_int8_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        *_this = value;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

int8_t* _corto_int8CreateChild(corto_object _parent, const char *_id, int8_t value) {
    int8_t* _this;
    _this = (int8_t*)corto_declare(_parent, _id, corto_int8_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        *_this = value;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_int8Update(int8_t* _this, int8_t value) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            *((int8_t*)CORTO_OFFSET(_this, ((corto_type)corto_int8_o)->size)) = value;
        } else {
            *_this = value;
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

int8_t* _corto_int8Declare(void) {
    int8_t* _this;
    _this = (int8_t*)corto_declare(NULL, NULL, corto_int8_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

int8_t* _corto_int8DeclareChild(corto_object _parent, const char *_id) {
    int8_t* _this;
    _this = (int8_t*)corto_declare(_parent, _id, corto_int8_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_int8Define(int8_t* _this, int8_t value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return corto_define(_this);
}

int8_t* _corto_int8Assign(int8_t* _this, int8_t value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

corto_interface _corto_interfaceCreate(corto_interface base) {
    corto_interface _this;
    _this = (corto_interface)corto_declare(NULL, NULL, corto_interface_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_ref(&((corto_interface)_this)->base, base);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_interface _corto_interfaceCreateChild(corto_object _parent, const char *_id, corto_interface base) {
    corto_interface _this;
    _this = (corto_interface)corto_declare(_parent, _id, corto_interface_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_ref(&((corto_interface)_this)->base, base);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_interfaceUpdate(corto_interface _this, corto_interface base) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_set_ref(&((corto_interface)((corto_interface)CORTO_OFFSET(_this, ((corto_type)corto_interface_o)->size)))->base, base);
        } else {
            corto_set_ref(&((corto_interface)_this)->base, base);
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

corto_interface _corto_interfaceDeclare(void) {
    corto_interface _this;
    _this = (corto_interface)corto_declare(NULL, NULL, corto_interface_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_interface _corto_interfaceDeclareChild(corto_object _parent, const char *_id) {
    corto_interface _this;
    _this = (corto_interface)corto_declare(_parent, _id, corto_interface_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_interfaceDefine(corto_interface _this, corto_interface base) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_interface)_this)->base, base);
    return corto_define(_this);
}

corto_interface _corto_interfaceAssign(corto_interface _this, corto_interface base) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_interface)_this)->base, base);
    return _this;
}

corto_interfaceseq* _corto_interfaceseqCreate(corto_uint32 length, corto_interface* elements) {
    corto_interfaceseq* _this;
    _this = (corto_interfaceseq*)corto_declare(NULL, NULL, corto_interfaceseq_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_interfaceseqResize(_this, length);
        corto_uint32 i = 0;
        for (i = 0; i < length; i ++) {
            corto_set_ref(&_this->buffer[i], elements[i]);
        }
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_interfaceseq* _corto_interfaceseqCreateChild(corto_object _parent, const char *_id, corto_uint32 length, corto_interface* elements) {
    corto_interfaceseq* _this;
    _this = (corto_interfaceseq*)corto_declare(_parent, _id, corto_interfaceseq_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_interfaceseqResize(_this, length);
        corto_uint32 i = 0;
        for (i = 0; i < length; i ++) {
            corto_set_ref(&_this->buffer[i], elements[i]);
        }
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_interfaceseqUpdate(corto_interfaceseq* _this, corto_uint32 length, corto_interface* elements) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_interfaceseqResize(((corto_interfaceseq*)CORTO_OFFSET(_this, ((corto_type)corto_interfaceseq_o)->size)), length);
            corto_uint32 i = 0;
            for (i = 0; i < length; i ++) {
                corto_set_ref(&((corto_interfaceseq*)CORTO_OFFSET(_this, ((corto_type)corto_interfaceseq_o)->size))->buffer[i], elements[i]);
            }
        } else {
            corto_interfaceseqResize(_this, length);
            corto_uint32 i = 0;
            for (i = 0; i < length; i ++) {
                corto_set_ref(&_this->buffer[i], elements[i]);
            }
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

corto_interfaceseq* _corto_interfaceseqDeclare(void) {
    corto_interfaceseq* _this;
    _this = (corto_interfaceseq*)corto_declare(NULL, NULL, corto_interfaceseq_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_interfaceseq* _corto_interfaceseqDeclareChild(corto_object _parent, const char *_id) {
    corto_interfaceseq* _this;
    _this = (corto_interfaceseq*)corto_declare(_parent, _id, corto_interfaceseq_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_interfaceseqDefine(corto_interfaceseq* _this, corto_uint32 length, corto_interface* elements) {
    CORTO_UNUSED(_this);
    corto_interfaceseqResize(_this, length);
    corto_uint32 i = 0;
    for (i = 0; i < length; i ++) {
        corto_set_ref(&_this->buffer[i], elements[i]);
    }
    return corto_define(_this);
}

corto_interfaceseq* _corto_interfaceseqAssign(corto_interfaceseq* _this, corto_uint32 length, corto_interface* elements) {
    CORTO_UNUSED(_this);
    corto_interfaceseqResize(_this, length);
    corto_uint32 i = 0;
    for (i = 0; i < length; i ++) {
        corto_set_ref(&_this->buffer[i], elements[i]);
    }
    return _this;
}

corto_interfaceVector* _corto_interfaceVectorCreate(corto_interface interface, corto_objectseq vector) {
    corto_interfaceVector* _this;
    _this = (corto_interfaceVector*)corto_declare(NULL, NULL, corto_interfaceVector_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_ref(&((corto_interfaceVector*)_this)->interface, interface);
        corto_ptr_copy(&((corto_interfaceVector*)_this)->vector, corto_objectseq_o, &vector);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_interfaceVector* _corto_interfaceVectorCreateChild(corto_object _parent, const char *_id, corto_interface interface, corto_objectseq vector) {
    corto_interfaceVector* _this;
    _this = (corto_interfaceVector*)corto_declare(_parent, _id, corto_interfaceVector_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_ref(&((corto_interfaceVector*)_this)->interface, interface);
        corto_ptr_copy(&((corto_interfaceVector*)_this)->vector, corto_objectseq_o, &vector);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_interfaceVectorUpdate(corto_interfaceVector* _this, corto_interface interface, corto_objectseq vector) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_set_ref(&((corto_interfaceVector*)((corto_interfaceVector*)CORTO_OFFSET(_this, ((corto_type)corto_interfaceVector_o)->size)))->interface, interface);
            corto_ptr_copy(&((corto_interfaceVector*)((corto_interfaceVector*)CORTO_OFFSET(_this, ((corto_type)corto_interfaceVector_o)->size)))->vector, corto_objectseq_o, &vector);
        } else {
            corto_set_ref(&((corto_interfaceVector*)_this)->interface, interface);
            corto_ptr_copy(&((corto_interfaceVector*)_this)->vector, corto_objectseq_o, &vector);
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

corto_interfaceVector* _corto_interfaceVectorDeclare(void) {
    corto_interfaceVector* _this;
    _this = (corto_interfaceVector*)corto_declare(NULL, NULL, corto_interfaceVector_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_interfaceVector* _corto_interfaceVectorDeclareChild(corto_object _parent, const char *_id) {
    corto_interfaceVector* _this;
    _this = (corto_interfaceVector*)corto_declare(_parent, _id, corto_interfaceVector_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_interfaceVectorDefine(corto_interfaceVector* _this, corto_interface interface, corto_objectseq vector) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_interfaceVector*)_this)->interface, interface);
    corto_ptr_copy(&((corto_interfaceVector*)_this)->vector, corto_objectseq_o, &vector);
    return corto_define(_this);
}

corto_interfaceVector* _corto_interfaceVectorAssign(corto_interfaceVector* _this, corto_interface interface, corto_objectseq vector) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_interfaceVector*)_this)->interface, interface);
    corto_ptr_copy(&((corto_interfaceVector*)_this)->vector, corto_objectseq_o, &vector);
    return _this;
}

corto_interfaceVectorseq* _corto_interfaceVectorseqCreate(corto_uint32 length, corto_interfaceVector* elements) {
    corto_interfaceVectorseq* _this;
    _this = (corto_interfaceVectorseq*)corto_declare(NULL, NULL, corto_interfaceVectorseq_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_interfaceVectorseqResize(_this, length);
        corto_uint32 i = 0;
        for (i = 0; i < length; i ++) {
            if (&elements[i]) {
                corto_ptr_copy(&_this->buffer[i], corto_interfaceVector_o, &elements[i]);
            }
        }
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_interfaceVectorseq* _corto_interfaceVectorseqCreateChild(corto_object _parent, const char *_id, corto_uint32 length, corto_interfaceVector* elements) {
    corto_interfaceVectorseq* _this;
    _this = (corto_interfaceVectorseq*)corto_declare(_parent, _id, corto_interfaceVectorseq_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_interfaceVectorseqResize(_this, length);
        corto_uint32 i = 0;
        for (i = 0; i < length; i ++) {
            if (&elements[i]) {
                corto_ptr_copy(&_this->buffer[i], corto_interfaceVector_o, &elements[i]);
            }
        }
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_interfaceVectorseqUpdate(corto_interfaceVectorseq* _this, corto_uint32 length, corto_interfaceVector* elements) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_interfaceVectorseqResize(((corto_interfaceVectorseq*)CORTO_OFFSET(_this, ((corto_type)corto_interfaceVectorseq_o)->size)), length);
            corto_uint32 i = 0;
            for (i = 0; i < length; i ++) {
                if (&elements[i]) {
                    corto_ptr_copy(&((corto_interfaceVectorseq*)CORTO_OFFSET(_this, ((corto_type)corto_interfaceVectorseq_o)->size))->buffer[i], corto_interfaceVector_o, &elements[i]);
                }
            }
        } else {
            corto_interfaceVectorseqResize(_this, length);
            corto_uint32 i = 0;
            for (i = 0; i < length; i ++) {
                if (&elements[i]) {
                    corto_ptr_copy(&_this->buffer[i], corto_interfaceVector_o, &elements[i]);
                }
            }
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

corto_interfaceVectorseq* _corto_interfaceVectorseqDeclare(void) {
    corto_interfaceVectorseq* _this;
    _this = (corto_interfaceVectorseq*)corto_declare(NULL, NULL, corto_interfaceVectorseq_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_interfaceVectorseq* _corto_interfaceVectorseqDeclareChild(corto_object _parent, const char *_id) {
    corto_interfaceVectorseq* _this;
    _this = (corto_interfaceVectorseq*)corto_declare(_parent, _id, corto_interfaceVectorseq_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_interfaceVectorseqDefine(corto_interfaceVectorseq* _this, corto_uint32 length, corto_interfaceVector* elements) {
    CORTO_UNUSED(_this);
    corto_interfaceVectorseqResize(_this, length);
    corto_uint32 i = 0;
    for (i = 0; i < length; i ++) {
        if (&elements[i]) {
            corto_ptr_copy(&_this->buffer[i], corto_interfaceVector_o, &elements[i]);
        }
    }
    return corto_define(_this);
}

corto_interfaceVectorseq* _corto_interfaceVectorseqAssign(corto_interfaceVectorseq* _this, corto_uint32 length, corto_interfaceVector* elements) {
    CORTO_UNUSED(_this);
    corto_interfaceVectorseqResize(_this, length);
    corto_uint32 i = 0;
    for (i = 0; i < length; i ++) {
        if (&elements[i]) {
            corto_ptr_copy(&_this->buffer[i], corto_interfaceVector_o, &elements[i]);
        }
    }
    return _this;
}

corto_iterator _corto_iteratorCreate(corto_type elementType) {
    corto_iterator _this;
    _this = (corto_iterator)corto_declare(NULL, NULL, corto_iterator_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_ref(&((corto_iterator)_this)->elementType, elementType);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_iterator _corto_iteratorCreateChild(corto_object _parent, const char *_id, corto_type elementType) {
    corto_iterator _this;
    _this = (corto_iterator)corto_declare(_parent, _id, corto_iterator_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_ref(&((corto_iterator)_this)->elementType, elementType);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_iteratorUpdate(corto_iterator _this, corto_type elementType) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_set_ref(&((corto_iterator)((corto_iterator)CORTO_OFFSET(_this, ((corto_type)corto_iterator_o)->size)))->elementType, elementType);
        } else {
            corto_set_ref(&((corto_iterator)_this)->elementType, elementType);
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

corto_iterator _corto_iteratorDeclare(void) {
    corto_iterator _this;
    _this = (corto_iterator)corto_declare(NULL, NULL, corto_iterator_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_iterator _corto_iteratorDeclareChild(corto_object _parent, const char *_id) {
    corto_iterator _this;
    _this = (corto_iterator)corto_declare(_parent, _id, corto_iterator_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_iteratorDefine(corto_iterator _this, corto_type elementType) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_iterator)_this)->elementType, elementType);
    return corto_define(_this);
}

corto_iterator _corto_iteratorAssign(corto_iterator _this, corto_type elementType) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_iterator)_this)->elementType, elementType);
    return _this;
}

corto_leaf _corto_leafCreate(corto_interface base, corto_modifier baseAccess, corto_interfaceseq implements, corto_type type, const char * value) {
    corto_leaf _this;
    _this = (corto_leaf)corto_declare(NULL, NULL, corto_leaf_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_ref(&((corto_interface)_this)->base, base);
        ((corto_struct)_this)->baseAccess = baseAccess;
        corto_ptr_copy(&((corto_class)_this)->implements, corto_interfaceseq_o, &implements);
        corto_set_ref(&((corto_container)_this)->type, type);
        corto_set_str(&((corto_container)_this)->value, value);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_leaf _corto_leafCreateChild(corto_object _parent, const char *_id, corto_interface base, corto_modifier baseAccess, corto_interfaceseq implements, corto_type type, const char * value) {
    corto_leaf _this;
    _this = (corto_leaf)corto_declare(_parent, _id, corto_leaf_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_ref(&((corto_interface)_this)->base, base);
        ((corto_struct)_this)->baseAccess = baseAccess;
        corto_ptr_copy(&((corto_class)_this)->implements, corto_interfaceseq_o, &implements);
        corto_set_ref(&((corto_container)_this)->type, type);
        corto_set_str(&((corto_container)_this)->value, value);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_leafUpdate(corto_leaf _this, corto_interface base, corto_modifier baseAccess, corto_interfaceseq implements, corto_type type, const char * value) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_set_ref(&((corto_interface)((corto_leaf)CORTO_OFFSET(_this, ((corto_type)corto_leaf_o)->size)))->base, base);
            ((corto_struct)((corto_leaf)CORTO_OFFSET(_this, ((corto_type)corto_leaf_o)->size)))->baseAccess = baseAccess;
            corto_ptr_copy(&((corto_class)((corto_leaf)CORTO_OFFSET(_this, ((corto_type)corto_leaf_o)->size)))->implements, corto_interfaceseq_o, &implements);
            corto_set_ref(&((corto_container)((corto_leaf)CORTO_OFFSET(_this, ((corto_type)corto_leaf_o)->size)))->type, type);
            corto_set_str(&((corto_container)((corto_leaf)CORTO_OFFSET(_this, ((corto_type)corto_leaf_o)->size)))->value, value);
        } else {
            corto_set_ref(&((corto_interface)_this)->base, base);
            ((corto_struct)_this)->baseAccess = baseAccess;
            corto_ptr_copy(&((corto_class)_this)->implements, corto_interfaceseq_o, &implements);
            corto_set_ref(&((corto_container)_this)->type, type);
            corto_set_str(&((corto_container)_this)->value, value);
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

corto_leaf _corto_leafDeclare(void) {
    corto_leaf _this;
    _this = (corto_leaf)corto_declare(NULL, NULL, corto_leaf_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_leaf _corto_leafDeclareChild(corto_object _parent, const char *_id) {
    corto_leaf _this;
    _this = (corto_leaf)corto_declare(_parent, _id, corto_leaf_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_leafDefine(corto_leaf _this, corto_interface base, corto_modifier baseAccess, corto_interfaceseq implements, corto_type type, const char * value) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_interface)_this)->base, base);
    ((corto_struct)_this)->baseAccess = baseAccess;
    corto_ptr_copy(&((corto_class)_this)->implements, corto_interfaceseq_o, &implements);
    corto_set_ref(&((corto_container)_this)->type, type);
    corto_set_str(&((corto_container)_this)->value, value);
    return corto_define(_this);
}

corto_leaf _corto_leafAssign(corto_leaf _this, corto_interface base, corto_modifier baseAccess, corto_interfaceseq implements, corto_type type, const char * value) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_interface)_this)->base, base);
    ((corto_struct)_this)->baseAccess = baseAccess;
    corto_ptr_copy(&((corto_class)_this)->implements, corto_interfaceseq_o, &implements);
    corto_set_ref(&((corto_container)_this)->type, type);
    corto_set_str(&((corto_container)_this)->value, value);
    return _this;
}

corto_list _corto_listCreate(corto_type elementType, uint32_t max) {
    corto_list _this;
    _this = (corto_list)corto_declare(NULL, NULL, corto_list_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_ref(&((corto_collection)_this)->elementType, elementType);
        ((corto_collection)_this)->max = max;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_list _corto_listCreateChild(corto_object _parent, const char *_id, corto_type elementType, uint32_t max) {
    corto_list _this;
    _this = (corto_list)corto_declare(_parent, _id, corto_list_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_ref(&((corto_collection)_this)->elementType, elementType);
        ((corto_collection)_this)->max = max;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_listUpdate(corto_list _this, corto_type elementType, uint32_t max) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_set_ref(&((corto_collection)((corto_list)CORTO_OFFSET(_this, ((corto_type)corto_list_o)->size)))->elementType, elementType);
            ((corto_collection)((corto_list)CORTO_OFFSET(_this, ((corto_type)corto_list_o)->size)))->max = max;
        } else {
            corto_set_ref(&((corto_collection)_this)->elementType, elementType);
            ((corto_collection)_this)->max = max;
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

corto_list _corto_listDeclare(void) {
    corto_list _this;
    _this = (corto_list)corto_declare(NULL, NULL, corto_list_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_list _corto_listDeclareChild(corto_object _parent, const char *_id) {
    corto_list _this;
    _this = (corto_list)corto_declare(_parent, _id, corto_list_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_listDefine(corto_list _this, corto_type elementType, uint32_t max) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_collection)_this)->elementType, elementType);
    ((corto_collection)_this)->max = max;
    return corto_define(_this);
}

corto_list _corto_listAssign(corto_list _this, corto_type elementType, uint32_t max) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_collection)_this)->elementType, elementType);
    ((corto_collection)_this)->max = max;
    return _this;
}

corto_map _corto_mapCreate(corto_type elementType, corto_type keyType, uint32_t max) {
    corto_map _this;
    _this = (corto_map)corto_declare(NULL, NULL, corto_map_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_ref(&((corto_map)_this)->elementType, elementType);
        corto_set_ref(&((corto_map)_this)->keyType, keyType);
        ((corto_map)_this)->max = max;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_map _corto_mapCreateChild(corto_object _parent, const char *_id, corto_type elementType, corto_type keyType, uint32_t max) {
    corto_map _this;
    _this = (corto_map)corto_declare(_parent, _id, corto_map_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_ref(&((corto_map)_this)->elementType, elementType);
        corto_set_ref(&((corto_map)_this)->keyType, keyType);
        ((corto_map)_this)->max = max;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_mapUpdate(corto_map _this, corto_type elementType, corto_type keyType, uint32_t max) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_set_ref(&((corto_map)((corto_map)CORTO_OFFSET(_this, ((corto_type)corto_map_o)->size)))->elementType, elementType);
            corto_set_ref(&((corto_map)((corto_map)CORTO_OFFSET(_this, ((corto_type)corto_map_o)->size)))->keyType, keyType);
            ((corto_map)((corto_map)CORTO_OFFSET(_this, ((corto_type)corto_map_o)->size)))->max = max;
        } else {
            corto_set_ref(&((corto_map)_this)->elementType, elementType);
            corto_set_ref(&((corto_map)_this)->keyType, keyType);
            ((corto_map)_this)->max = max;
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

corto_map _corto_mapDeclare(void) {
    corto_map _this;
    _this = (corto_map)corto_declare(NULL, NULL, corto_map_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_map _corto_mapDeclareChild(corto_object _parent, const char *_id) {
    corto_map _this;
    _this = (corto_map)corto_declare(_parent, _id, corto_map_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_mapDefine(corto_map _this, corto_type elementType, corto_type keyType, uint32_t max) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_map)_this)->elementType, elementType);
    corto_set_ref(&((corto_map)_this)->keyType, keyType);
    ((corto_map)_this)->max = max;
    return corto_define(_this);
}

corto_map _corto_mapAssign(corto_map _this, corto_type elementType, corto_type keyType, uint32_t max) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_map)_this)->elementType, elementType);
    corto_set_ref(&((corto_map)_this)->keyType, keyType);
    ((corto_map)_this)->max = max;
    return _this;
}

corto_member _corto_memberCreate(corto_type type, corto_modifier modifiers) {
    corto_member _this;
    _this = (corto_member)corto_declare(NULL, NULL, corto_member_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_ref(&((corto_member)_this)->type, type);
        ((corto_member)_this)->modifiers = modifiers;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_member _corto_memberCreateChild(corto_object _parent, const char *_id, corto_type type, corto_modifier modifiers) {
    corto_member _this;
    _this = (corto_member)corto_declare(_parent, _id, corto_member_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_ref(&((corto_member)_this)->type, type);
        ((corto_member)_this)->modifiers = modifiers;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_memberUpdate(corto_member _this, corto_type type, corto_modifier modifiers) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_set_ref(&((corto_member)((corto_member)CORTO_OFFSET(_this, ((corto_type)corto_member_o)->size)))->type, type);
            ((corto_member)((corto_member)CORTO_OFFSET(_this, ((corto_type)corto_member_o)->size)))->modifiers = modifiers;
        } else {
            corto_set_ref(&((corto_member)_this)->type, type);
            ((corto_member)_this)->modifiers = modifiers;
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

corto_member _corto_memberDeclare(void) {
    corto_member _this;
    _this = (corto_member)corto_declare(NULL, NULL, corto_member_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_member _corto_memberDeclareChild(corto_object _parent, const char *_id) {
    corto_member _this;
    _this = (corto_member)corto_declare(_parent, _id, corto_member_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_memberDefine(corto_member _this, corto_type type, corto_modifier modifiers) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_member)_this)->type, type);
    ((corto_member)_this)->modifiers = modifiers;
    return corto_define(_this);
}

corto_member _corto_memberAssign(corto_member _this, corto_type type, corto_modifier modifiers) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_member)_this)->type, type);
    ((corto_member)_this)->modifiers = modifiers;
    return _this;
}

corto_metaprocedure _corto_metaprocedureCreate(corto_type returnType, bool returnsReference, bool referenceOnly, void(*_impl)(void)) {
    corto_metaprocedure _this;
    _this = (corto_metaprocedure)corto_declare(NULL, NULL, corto_metaprocedure_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_ref(&((corto_function)_this)->returnType, returnType);
        ((corto_function)_this)->returnsReference = returnsReference;
        ((corto_metaprocedure)_this)->referenceOnly = referenceOnly;
        corto_function(_this)->kind = CORTO_PROCEDURE_CDECL;
        corto_function(_this)->fptr = (corto_word)_impl;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_metaprocedure _corto_metaprocedureCreateChild(corto_object _parent, const char *_id, corto_type returnType, bool returnsReference, bool referenceOnly, void(*_impl)(void)) {
    corto_metaprocedure _this;
    _this = (corto_metaprocedure)corto_declare(_parent, _id, corto_metaprocedure_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_ref(&((corto_function)_this)->returnType, returnType);
        ((corto_function)_this)->returnsReference = returnsReference;
        ((corto_metaprocedure)_this)->referenceOnly = referenceOnly;
        corto_function(_this)->kind = CORTO_PROCEDURE_CDECL;
        corto_function(_this)->fptr = (corto_word)_impl;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_metaprocedureUpdate(corto_metaprocedure _this, corto_type returnType, bool returnsReference, bool referenceOnly, void(*_impl)(void)) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_set_ref(&((corto_function)((corto_metaprocedure)CORTO_OFFSET(_this, ((corto_type)corto_metaprocedure_o)->size)))->returnType, returnType);
            ((corto_function)((corto_metaprocedure)CORTO_OFFSET(_this, ((corto_type)corto_metaprocedure_o)->size)))->returnsReference = returnsReference;
            ((corto_metaprocedure)((corto_metaprocedure)CORTO_OFFSET(_this, ((corto_type)corto_metaprocedure_o)->size)))->referenceOnly = referenceOnly;
            corto_function(((corto_metaprocedure)CORTO_OFFSET(_this, ((corto_type)corto_metaprocedure_o)->size)))->kind = CORTO_PROCEDURE_CDECL;
            corto_function(((corto_metaprocedure)CORTO_OFFSET(_this, ((corto_type)corto_metaprocedure_o)->size)))->fptr = (corto_word)_impl;
        } else {
            corto_set_ref(&((corto_function)_this)->returnType, returnType);
            ((corto_function)_this)->returnsReference = returnsReference;
            ((corto_metaprocedure)_this)->referenceOnly = referenceOnly;
            corto_function(_this)->kind = CORTO_PROCEDURE_CDECL;
            corto_function(_this)->fptr = (corto_word)_impl;
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

corto_metaprocedure _corto_metaprocedureDeclare(void) {
    corto_metaprocedure _this;
    _this = (corto_metaprocedure)corto_declare(NULL, NULL, corto_metaprocedure_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_metaprocedure _corto_metaprocedureDeclareChild(corto_object _parent, const char *_id) {
    corto_metaprocedure _this;
    _this = (corto_metaprocedure)corto_declare(_parent, _id, corto_metaprocedure_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_metaprocedureDefine(corto_metaprocedure _this, corto_type returnType, bool returnsReference, bool referenceOnly, void(*_impl)(void)) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_function)_this)->returnType, returnType);
    ((corto_function)_this)->returnsReference = returnsReference;
    ((corto_metaprocedure)_this)->referenceOnly = referenceOnly;
    corto_function(_this)->kind = CORTO_PROCEDURE_CDECL;
    corto_function(_this)->fptr = (corto_word)_impl;
    return corto_define(_this);
}

corto_metaprocedure _corto_metaprocedureAssign(corto_metaprocedure _this, corto_type returnType, bool returnsReference, bool referenceOnly, void(*_impl)(void)) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_function)_this)->returnType, returnType);
    ((corto_function)_this)->returnsReference = returnsReference;
    ((corto_metaprocedure)_this)->referenceOnly = referenceOnly;
    corto_function(_this)->kind = CORTO_PROCEDURE_CDECL;
    corto_function(_this)->fptr = (corto_word)_impl;
    return _this;
}

corto_method _corto_methodCreate(corto_type returnType, bool returnsReference, void(*_impl)(void)) {
    corto_method _this;
    _this = (corto_method)corto_declare(NULL, NULL, corto_method_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_ref(&((corto_function)_this)->returnType, returnType);
        ((corto_function)_this)->returnsReference = returnsReference;
        corto_function(_this)->kind = CORTO_PROCEDURE_CDECL;
        corto_function(_this)->fptr = (corto_word)_impl;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_method _corto_methodCreateChild(corto_object _parent, const char *_id, corto_type returnType, bool returnsReference, void(*_impl)(void)) {
    corto_method _this;
    _this = (corto_method)corto_declare(_parent, _id, corto_method_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_ref(&((corto_function)_this)->returnType, returnType);
        ((corto_function)_this)->returnsReference = returnsReference;
        corto_function(_this)->kind = CORTO_PROCEDURE_CDECL;
        corto_function(_this)->fptr = (corto_word)_impl;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_methodUpdate(corto_method _this, corto_type returnType, bool returnsReference, void(*_impl)(void)) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_set_ref(&((corto_function)((corto_method)CORTO_OFFSET(_this, ((corto_type)corto_method_o)->size)))->returnType, returnType);
            ((corto_function)((corto_method)CORTO_OFFSET(_this, ((corto_type)corto_method_o)->size)))->returnsReference = returnsReference;
            corto_function(((corto_method)CORTO_OFFSET(_this, ((corto_type)corto_method_o)->size)))->kind = CORTO_PROCEDURE_CDECL;
            corto_function(((corto_method)CORTO_OFFSET(_this, ((corto_type)corto_method_o)->size)))->fptr = (corto_word)_impl;
        } else {
            corto_set_ref(&((corto_function)_this)->returnType, returnType);
            ((corto_function)_this)->returnsReference = returnsReference;
            corto_function(_this)->kind = CORTO_PROCEDURE_CDECL;
            corto_function(_this)->fptr = (corto_word)_impl;
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

corto_method _corto_methodDeclare(void) {
    corto_method _this;
    _this = (corto_method)corto_declare(NULL, NULL, corto_method_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_method _corto_methodDeclareChild(corto_object _parent, const char *_id) {
    corto_method _this;
    _this = (corto_method)corto_declare(_parent, _id, corto_method_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_methodDefine(corto_method _this, corto_type returnType, bool returnsReference, void(*_impl)(void)) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_function)_this)->returnType, returnType);
    ((corto_function)_this)->returnsReference = returnsReference;
    corto_function(_this)->kind = CORTO_PROCEDURE_CDECL;
    corto_function(_this)->fptr = (corto_word)_impl;
    return corto_define(_this);
}

corto_method _corto_methodAssign(corto_method _this, corto_type returnType, bool returnsReference, void(*_impl)(void)) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_function)_this)->returnType, returnType);
    ((corto_function)_this)->returnsReference = returnsReference;
    corto_function(_this)->kind = CORTO_PROCEDURE_CDECL;
    corto_function(_this)->fptr = (corto_word)_impl;
    return _this;
}

corto_modifier* _corto_modifierCreate(corto_modifier value) {
    corto_modifier* _this;
    _this = (corto_modifier*)corto_declare(NULL, NULL, corto_modifier_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        *_this = value;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_modifier* _corto_modifierCreateChild(corto_object _parent, const char *_id, corto_modifier value) {
    corto_modifier* _this;
    _this = (corto_modifier*)corto_declare(_parent, _id, corto_modifier_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        *_this = value;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_modifierUpdate(corto_modifier* _this, corto_modifier value) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            *((corto_modifier*)CORTO_OFFSET(_this, ((corto_type)corto_modifier_o)->size)) = value;
        } else {
            *_this = value;
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

corto_modifier* _corto_modifierDeclare(void) {
    corto_modifier* _this;
    _this = (corto_modifier*)corto_declare(NULL, NULL, corto_modifier_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_modifier* _corto_modifierDeclareChild(corto_object _parent, const char *_id) {
    corto_modifier* _this;
    _this = (corto_modifier*)corto_declare(_parent, _id, corto_modifier_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_modifierDefine(corto_modifier* _this, corto_modifier value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return corto_define(_this);
}

corto_modifier* _corto_modifierAssign(corto_modifier* _this, corto_modifier value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

corto_name_action* _corto_name_actionCreate(corto_object instance, corto_function procedure) {
    corto_name_action* _this;
    _this = (corto_name_action*)corto_declare(NULL, NULL, corto_name_action_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_ref(&((corto_delegatedata*)_this)->instance, instance);
        corto_set_ref(&((corto_delegatedata*)_this)->procedure, procedure);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_name_action* _corto_name_actionCreateChild(corto_object _parent, const char *_id, corto_object instance, corto_function procedure) {
    corto_name_action* _this;
    _this = (corto_name_action*)corto_declare(_parent, _id, corto_name_action_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_ref(&((corto_delegatedata*)_this)->instance, instance);
        corto_set_ref(&((corto_delegatedata*)_this)->procedure, procedure);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_name_actionUpdate(corto_name_action* _this, corto_object instance, corto_function procedure) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_set_ref(&((corto_delegatedata*)((corto_name_action*)CORTO_OFFSET(_this, ((corto_type)corto_name_action_o)->size)))->instance, instance);
            corto_set_ref(&((corto_delegatedata*)((corto_name_action*)CORTO_OFFSET(_this, ((corto_type)corto_name_action_o)->size)))->procedure, procedure);
        } else {
            corto_set_ref(&((corto_delegatedata*)_this)->instance, instance);
            corto_set_ref(&((corto_delegatedata*)_this)->procedure, procedure);
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

corto_name_action* _corto_name_actionDeclare(void) {
    corto_name_action* _this;
    _this = (corto_name_action*)corto_declare(NULL, NULL, corto_name_action_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_name_action* _corto_name_actionDeclareChild(corto_object _parent, const char *_id) {
    corto_name_action* _this;
    _this = (corto_name_action*)corto_declare(_parent, _id, corto_name_action_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_name_actionDefine(corto_name_action* _this, corto_object instance, corto_function procedure) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_delegatedata*)_this)->instance, instance);
    corto_set_ref(&((corto_delegatedata*)_this)->procedure, procedure);
    return corto_define(_this);
}

corto_name_action* _corto_name_actionAssign(corto_name_action* _this, corto_object instance, corto_function procedure) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_delegatedata*)_this)->instance, instance);
    corto_set_ref(&((corto_delegatedata*)_this)->procedure, procedure);
    return _this;
}

corto_int16 corto_name_actionCall(corto_name_action *_delegate, corto_string* _result) {
    if (_delegate->super.procedure) {
        if (_delegate->super.instance) {
            corto_invoke(_delegate->super.procedure, _result, _delegate->super.instance);
        } else {
            corto_invoke(_delegate->super.procedure, _result);
        }
    } else {
        return -1;
    }
    return 0;
}

corto_int16 corto_name_actionInitC(corto_name_action *d, corto_string ___ (*callback)(void)) {
    d->super.instance = NULL;
    d->super.procedure = corto_declare(NULL, NULL, corto_function_o);
    d->super.procedure->kind = CORTO_PROCEDURE_CDECL;
    corto_set_ref(&d->super.procedure->returnType, corto_string_o);
    corto_function_parseParamString(d->super.procedure, "()");
    d->super.procedure->fptr = (corto_word)callback;
    corto_define(d->super.procedure);
    return 0;
}

corto_int16 corto_name_actionInitCInstance(corto_name_action *d, corto_object instance, corto_string ___ (*callback)(corto_object)) {
    d->super.instance = instance;
    corto_claim(instance);
    d->super.procedure = corto_declare(NULL, NULL, corto_function_o);
    d->super.procedure->kind = CORTO_PROCEDURE_CDECL;
    corto_set_ref(&d->super.procedure->returnType, corto_string_o);
    corto_function_parseParamString(d->super.procedure, "(object instance)");
    d->super.procedure->fptr = (corto_word)callback;
    corto_define(d->super.procedure);
    return 0;
}

corto_object _corto_objectCreate(corto_object value) {
    corto_object _this;
    _this = (corto_object)corto_declare(NULL, NULL, corto_object_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_ref(_this, value);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_object _corto_objectCreateChild(corto_object _parent, const char *_id, corto_object value) {
    corto_object _this;
    _this = (corto_object)corto_declare(_parent, _id, corto_object_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_ref(_this, value);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_objectUpdate(corto_object _this, corto_object value) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_set_ref(((corto_object)CORTO_OFFSET(_this, ((corto_type)corto_object_o)->size)), value);
        } else {
            corto_set_ref(_this, value);
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

corto_object _corto_objectDeclare(void) {
    corto_object _this;
    _this = (corto_object)corto_declare(NULL, NULL, corto_object_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_object _corto_objectDeclareChild(corto_object _parent, const char *_id) {
    corto_object _this;
    _this = (corto_object)corto_declare(_parent, _id, corto_object_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_objectDefine(corto_object _this, corto_object value) {
    CORTO_UNUSED(_this);
    corto_set_ref(_this, value);
    return corto_define(_this);
}

corto_object _corto_objectAssign(corto_object _this, corto_object value) {
    CORTO_UNUSED(_this);
    corto_set_ref(_this, value);
    return _this;
}

corto_objectlist* _corto_objectlistCreate(corto_uint32 length, corto_object* elements) {
    corto_objectlist* _this;
    _this = (corto_objectlist*)corto_declare(NULL, NULL, corto_objectlist_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_uint32 i = 0;
        corto_objectlistClear(*_this);
        for (i = 0; i < length; i ++) {
            corto_objectlistAppend(*_this, elements[i]);
        }
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_objectlist* _corto_objectlistCreateChild(corto_object _parent, const char *_id, corto_uint32 length, corto_object* elements) {
    corto_objectlist* _this;
    _this = (corto_objectlist*)corto_declare(_parent, _id, corto_objectlist_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_uint32 i = 0;
        corto_objectlistClear(*_this);
        for (i = 0; i < length; i ++) {
            corto_objectlistAppend(*_this, elements[i]);
        }
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_objectlistUpdate(corto_objectlist* _this, corto_uint32 length, corto_object* elements) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_uint32 i = 0;
            corto_objectlistClear(*((corto_objectlist*)CORTO_OFFSET(_this, ((corto_type)corto_objectlist_o)->size)));
            for (i = 0; i < length; i ++) {
                corto_objectlistAppend(*((corto_objectlist*)CORTO_OFFSET(_this, ((corto_type)corto_objectlist_o)->size)), elements[i]);
            }
        } else {
            corto_uint32 i = 0;
            corto_objectlistClear(*_this);
            for (i = 0; i < length; i ++) {
                corto_objectlistAppend(*_this, elements[i]);
            }
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

corto_objectlist* _corto_objectlistDeclare(void) {
    corto_objectlist* _this;
    _this = (corto_objectlist*)corto_declare(NULL, NULL, corto_objectlist_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_objectlist* _corto_objectlistDeclareChild(corto_object _parent, const char *_id) {
    corto_objectlist* _this;
    _this = (corto_objectlist*)corto_declare(_parent, _id, corto_objectlist_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_objectlistDefine(corto_objectlist* _this, corto_uint32 length, corto_object* elements) {
    CORTO_UNUSED(_this);
    corto_uint32 i = 0;
    corto_objectlistClear(*_this);
    for (i = 0; i < length; i ++) {
        corto_objectlistAppend(*_this, elements[i]);
    }
    return corto_define(_this);
}

corto_objectlist* _corto_objectlistAssign(corto_objectlist* _this, corto_uint32 length, corto_object* elements) {
    CORTO_UNUSED(_this);
    corto_uint32 i = 0;
    corto_objectlistClear(*_this);
    for (i = 0; i < length; i ++) {
        corto_objectlistAppend(*_this, elements[i]);
    }
    return _this;
}

corto_objectseq* _corto_objectseqCreate(corto_uint32 length, corto_object* elements) {
    corto_objectseq* _this;
    _this = (corto_objectseq*)corto_declare(NULL, NULL, corto_objectseq_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_objectseqResize(_this, length);
        corto_uint32 i = 0;
        for (i = 0; i < length; i ++) {
            corto_set_ref(&_this->buffer[i], elements[i]);
        }
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_objectseq* _corto_objectseqCreateChild(corto_object _parent, const char *_id, corto_uint32 length, corto_object* elements) {
    corto_objectseq* _this;
    _this = (corto_objectseq*)corto_declare(_parent, _id, corto_objectseq_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_objectseqResize(_this, length);
        corto_uint32 i = 0;
        for (i = 0; i < length; i ++) {
            corto_set_ref(&_this->buffer[i], elements[i]);
        }
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_objectseqUpdate(corto_objectseq* _this, corto_uint32 length, corto_object* elements) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_objectseqResize(((corto_objectseq*)CORTO_OFFSET(_this, ((corto_type)corto_objectseq_o)->size)), length);
            corto_uint32 i = 0;
            for (i = 0; i < length; i ++) {
                corto_set_ref(&((corto_objectseq*)CORTO_OFFSET(_this, ((corto_type)corto_objectseq_o)->size))->buffer[i], elements[i]);
            }
        } else {
            corto_objectseqResize(_this, length);
            corto_uint32 i = 0;
            for (i = 0; i < length; i ++) {
                corto_set_ref(&_this->buffer[i], elements[i]);
            }
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

corto_objectseq* _corto_objectseqDeclare(void) {
    corto_objectseq* _this;
    _this = (corto_objectseq*)corto_declare(NULL, NULL, corto_objectseq_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_objectseq* _corto_objectseqDeclareChild(corto_object _parent, const char *_id) {
    corto_objectseq* _this;
    _this = (corto_objectseq*)corto_declare(_parent, _id, corto_objectseq_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_objectseqDefine(corto_objectseq* _this, corto_uint32 length, corto_object* elements) {
    CORTO_UNUSED(_this);
    corto_objectseqResize(_this, length);
    corto_uint32 i = 0;
    for (i = 0; i < length; i ++) {
        corto_set_ref(&_this->buffer[i], elements[i]);
    }
    return corto_define(_this);
}

corto_objectseq* _corto_objectseqAssign(corto_objectseq* _this, corto_uint32 length, corto_object* elements) {
    CORTO_UNUSED(_this);
    corto_objectseqResize(_this, length);
    corto_uint32 i = 0;
    for (i = 0; i < length; i ++) {
        corto_set_ref(&_this->buffer[i], elements[i]);
    }
    return _this;
}

uint8_t* _corto_octetCreate(uint8_t value) {
    uint8_t* _this;
    _this = (uint8_t*)corto_declare(NULL, NULL, corto_octet_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        *_this = value;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

uint8_t* _corto_octetCreateChild(corto_object _parent, const char *_id, uint8_t value) {
    uint8_t* _this;
    _this = (uint8_t*)corto_declare(_parent, _id, corto_octet_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        *_this = value;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_octetUpdate(uint8_t* _this, uint8_t value) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            *((uint8_t*)CORTO_OFFSET(_this, ((corto_type)corto_octet_o)->size)) = value;
        } else {
            *_this = value;
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

uint8_t* _corto_octetDeclare(void) {
    uint8_t* _this;
    _this = (uint8_t*)corto_declare(NULL, NULL, corto_octet_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

uint8_t* _corto_octetDeclareChild(corto_object _parent, const char *_id) {
    uint8_t* _this;
    _this = (uint8_t*)corto_declare(_parent, _id, corto_octet_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_octetDefine(uint8_t* _this, uint8_t value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return corto_define(_this);
}

uint8_t* _corto_octetAssign(uint8_t* _this, uint8_t value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

corto_overridable _corto_overridableCreate(corto_type returnType, bool returnsReference, void(*_impl)(void)) {
    corto_overridable _this;
    _this = (corto_overridable)corto_declare(NULL, NULL, corto_overridable_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_ref(&((corto_function)_this)->returnType, returnType);
        ((corto_function)_this)->returnsReference = returnsReference;
        corto_function(_this)->kind = CORTO_PROCEDURE_CDECL;
        corto_function(_this)->fptr = (corto_word)_impl;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_overridable _corto_overridableCreateChild(corto_object _parent, const char *_id, corto_type returnType, bool returnsReference, void(*_impl)(void)) {
    corto_overridable _this;
    _this = (corto_overridable)corto_declare(_parent, _id, corto_overridable_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_ref(&((corto_function)_this)->returnType, returnType);
        ((corto_function)_this)->returnsReference = returnsReference;
        corto_function(_this)->kind = CORTO_PROCEDURE_CDECL;
        corto_function(_this)->fptr = (corto_word)_impl;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_overridableUpdate(corto_overridable _this, corto_type returnType, bool returnsReference, void(*_impl)(void)) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_set_ref(&((corto_function)((corto_overridable)CORTO_OFFSET(_this, ((corto_type)corto_overridable_o)->size)))->returnType, returnType);
            ((corto_function)((corto_overridable)CORTO_OFFSET(_this, ((corto_type)corto_overridable_o)->size)))->returnsReference = returnsReference;
            corto_function(((corto_overridable)CORTO_OFFSET(_this, ((corto_type)corto_overridable_o)->size)))->kind = CORTO_PROCEDURE_CDECL;
            corto_function(((corto_overridable)CORTO_OFFSET(_this, ((corto_type)corto_overridable_o)->size)))->fptr = (corto_word)_impl;
        } else {
            corto_set_ref(&((corto_function)_this)->returnType, returnType);
            ((corto_function)_this)->returnsReference = returnsReference;
            corto_function(_this)->kind = CORTO_PROCEDURE_CDECL;
            corto_function(_this)->fptr = (corto_word)_impl;
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

corto_overridable _corto_overridableDeclare(void) {
    corto_overridable _this;
    _this = (corto_overridable)corto_declare(NULL, NULL, corto_overridable_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_overridable _corto_overridableDeclareChild(corto_object _parent, const char *_id) {
    corto_overridable _this;
    _this = (corto_overridable)corto_declare(_parent, _id, corto_overridable_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_overridableDefine(corto_overridable _this, corto_type returnType, bool returnsReference, void(*_impl)(void)) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_function)_this)->returnType, returnType);
    ((corto_function)_this)->returnsReference = returnsReference;
    corto_function(_this)->kind = CORTO_PROCEDURE_CDECL;
    corto_function(_this)->fptr = (corto_word)_impl;
    return corto_define(_this);
}

corto_overridable _corto_overridableAssign(corto_overridable _this, corto_type returnType, bool returnsReference, void(*_impl)(void)) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_function)_this)->returnType, returnType);
    ((corto_function)_this)->returnsReference = returnsReference;
    corto_function(_this)->kind = CORTO_PROCEDURE_CDECL;
    corto_function(_this)->fptr = (corto_word)_impl;
    return _this;
}

corto_override _corto_overrideCreate(corto_type returnType, bool returnsReference, void(*_impl)(void)) {
    corto_override _this;
    _this = (corto_override)corto_declare(NULL, NULL, corto_override_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_ref(&((corto_function)_this)->returnType, returnType);
        ((corto_function)_this)->returnsReference = returnsReference;
        corto_function(_this)->kind = CORTO_PROCEDURE_CDECL;
        corto_function(_this)->fptr = (corto_word)_impl;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_override _corto_overrideCreateChild(corto_object _parent, const char *_id, corto_type returnType, bool returnsReference, void(*_impl)(void)) {
    corto_override _this;
    _this = (corto_override)corto_declare(_parent, _id, corto_override_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_ref(&((corto_function)_this)->returnType, returnType);
        ((corto_function)_this)->returnsReference = returnsReference;
        corto_function(_this)->kind = CORTO_PROCEDURE_CDECL;
        corto_function(_this)->fptr = (corto_word)_impl;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_overrideUpdate(corto_override _this, corto_type returnType, bool returnsReference, void(*_impl)(void)) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_set_ref(&((corto_function)((corto_override)CORTO_OFFSET(_this, ((corto_type)corto_override_o)->size)))->returnType, returnType);
            ((corto_function)((corto_override)CORTO_OFFSET(_this, ((corto_type)corto_override_o)->size)))->returnsReference = returnsReference;
            corto_function(((corto_override)CORTO_OFFSET(_this, ((corto_type)corto_override_o)->size)))->kind = CORTO_PROCEDURE_CDECL;
            corto_function(((corto_override)CORTO_OFFSET(_this, ((corto_type)corto_override_o)->size)))->fptr = (corto_word)_impl;
        } else {
            corto_set_ref(&((corto_function)_this)->returnType, returnType);
            ((corto_function)_this)->returnsReference = returnsReference;
            corto_function(_this)->kind = CORTO_PROCEDURE_CDECL;
            corto_function(_this)->fptr = (corto_word)_impl;
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

corto_override _corto_overrideDeclare(void) {
    corto_override _this;
    _this = (corto_override)corto_declare(NULL, NULL, corto_override_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_override _corto_overrideDeclareChild(corto_object _parent, const char *_id) {
    corto_override _this;
    _this = (corto_override)corto_declare(_parent, _id, corto_override_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_overrideDefine(corto_override _this, corto_type returnType, bool returnsReference, void(*_impl)(void)) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_function)_this)->returnType, returnType);
    ((corto_function)_this)->returnsReference = returnsReference;
    corto_function(_this)->kind = CORTO_PROCEDURE_CDECL;
    corto_function(_this)->fptr = (corto_word)_impl;
    return corto_define(_this);
}

corto_override _corto_overrideAssign(corto_override _this, corto_type returnType, bool returnsReference, void(*_impl)(void)) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_function)_this)->returnType, returnType);
    ((corto_function)_this)->returnsReference = returnsReference;
    corto_function(_this)->kind = CORTO_PROCEDURE_CDECL;
    corto_function(_this)->fptr = (corto_word)_impl;
    return _this;
}

corto_package _corto_packageCreate(void) {
    corto_package _this;
    _this = (corto_package)corto_declare(NULL, NULL, corto_package_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_package _corto_packageCreateChild(corto_object _parent, const char *_id) {
    corto_package _this;
    _this = (corto_package)corto_declare(_parent, _id, corto_package_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_packageUpdate(corto_package _this) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
        } else {
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

corto_package _corto_packageDeclare(void) {
    corto_package _this;
    _this = (corto_package)corto_declare(NULL, NULL, corto_package_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_package _corto_packageDeclareChild(corto_object _parent, const char *_id) {
    corto_package _this;
    _this = (corto_package)corto_declare(_parent, _id, corto_package_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_packageDefine(corto_package _this) {
    CORTO_UNUSED(_this);
    return corto_define(_this);
}

corto_package _corto_packageAssign(corto_package _this) {
    CORTO_UNUSED(_this);
    return _this;
}

corto_parameter* _corto_parameterCreate(const char * name, corto_type type, corto_inout inout, bool passByReference) {
    corto_parameter* _this;
    _this = (corto_parameter*)corto_declare(NULL, NULL, corto_parameter_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_str(&((corto_parameter*)_this)->name, name);
        corto_set_ref(&((corto_parameter*)_this)->type, type);
        ((corto_parameter*)_this)->inout = inout;
        ((corto_parameter*)_this)->passByReference = passByReference;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_parameter* _corto_parameterCreateChild(corto_object _parent, const char *_id, const char * name, corto_type type, corto_inout inout, bool passByReference) {
    corto_parameter* _this;
    _this = (corto_parameter*)corto_declare(_parent, _id, corto_parameter_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_str(&((corto_parameter*)_this)->name, name);
        corto_set_ref(&((corto_parameter*)_this)->type, type);
        ((corto_parameter*)_this)->inout = inout;
        ((corto_parameter*)_this)->passByReference = passByReference;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_parameterUpdate(corto_parameter* _this, const char * name, corto_type type, corto_inout inout, bool passByReference) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_set_str(&((corto_parameter*)((corto_parameter*)CORTO_OFFSET(_this, ((corto_type)corto_parameter_o)->size)))->name, name);
            corto_set_ref(&((corto_parameter*)((corto_parameter*)CORTO_OFFSET(_this, ((corto_type)corto_parameter_o)->size)))->type, type);
            ((corto_parameter*)((corto_parameter*)CORTO_OFFSET(_this, ((corto_type)corto_parameter_o)->size)))->inout = inout;
            ((corto_parameter*)((corto_parameter*)CORTO_OFFSET(_this, ((corto_type)corto_parameter_o)->size)))->passByReference = passByReference;
        } else {
            corto_set_str(&((corto_parameter*)_this)->name, name);
            corto_set_ref(&((corto_parameter*)_this)->type, type);
            ((corto_parameter*)_this)->inout = inout;
            ((corto_parameter*)_this)->passByReference = passByReference;
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

corto_parameter* _corto_parameterDeclare(void) {
    corto_parameter* _this;
    _this = (corto_parameter*)corto_declare(NULL, NULL, corto_parameter_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_parameter* _corto_parameterDeclareChild(corto_object _parent, const char *_id) {
    corto_parameter* _this;
    _this = (corto_parameter*)corto_declare(_parent, _id, corto_parameter_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_parameterDefine(corto_parameter* _this, const char * name, corto_type type, corto_inout inout, bool passByReference) {
    CORTO_UNUSED(_this);
    corto_set_str(&((corto_parameter*)_this)->name, name);
    corto_set_ref(&((corto_parameter*)_this)->type, type);
    ((corto_parameter*)_this)->inout = inout;
    ((corto_parameter*)_this)->passByReference = passByReference;
    return corto_define(_this);
}

corto_parameter* _corto_parameterAssign(corto_parameter* _this, const char * name, corto_type type, corto_inout inout, bool passByReference) {
    CORTO_UNUSED(_this);
    corto_set_str(&((corto_parameter*)_this)->name, name);
    corto_set_ref(&((corto_parameter*)_this)->type, type);
    ((corto_parameter*)_this)->inout = inout;
    ((corto_parameter*)_this)->passByReference = passByReference;
    return _this;
}

corto_parameterseq* _corto_parameterseqCreate(corto_uint32 length, corto_parameter* elements) {
    corto_parameterseq* _this;
    _this = (corto_parameterseq*)corto_declare(NULL, NULL, corto_parameterseq_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_parameterseqResize(_this, length);
        corto_uint32 i = 0;
        for (i = 0; i < length; i ++) {
            if (&elements[i]) {
                corto_ptr_copy(&_this->buffer[i], corto_parameter_o, &elements[i]);
            }
        }
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_parameterseq* _corto_parameterseqCreateChild(corto_object _parent, const char *_id, corto_uint32 length, corto_parameter* elements) {
    corto_parameterseq* _this;
    _this = (corto_parameterseq*)corto_declare(_parent, _id, corto_parameterseq_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_parameterseqResize(_this, length);
        corto_uint32 i = 0;
        for (i = 0; i < length; i ++) {
            if (&elements[i]) {
                corto_ptr_copy(&_this->buffer[i], corto_parameter_o, &elements[i]);
            }
        }
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_parameterseqUpdate(corto_parameterseq* _this, corto_uint32 length, corto_parameter* elements) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_parameterseqResize(((corto_parameterseq*)CORTO_OFFSET(_this, ((corto_type)corto_parameterseq_o)->size)), length);
            corto_uint32 i = 0;
            for (i = 0; i < length; i ++) {
                if (&elements[i]) {
                    corto_ptr_copy(&((corto_parameterseq*)CORTO_OFFSET(_this, ((corto_type)corto_parameterseq_o)->size))->buffer[i], corto_parameter_o, &elements[i]);
                }
            }
        } else {
            corto_parameterseqResize(_this, length);
            corto_uint32 i = 0;
            for (i = 0; i < length; i ++) {
                if (&elements[i]) {
                    corto_ptr_copy(&_this->buffer[i], corto_parameter_o, &elements[i]);
                }
            }
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

corto_parameterseq* _corto_parameterseqDeclare(void) {
    corto_parameterseq* _this;
    _this = (corto_parameterseq*)corto_declare(NULL, NULL, corto_parameterseq_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_parameterseq* _corto_parameterseqDeclareChild(corto_object _parent, const char *_id) {
    corto_parameterseq* _this;
    _this = (corto_parameterseq*)corto_declare(_parent, _id, corto_parameterseq_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_parameterseqDefine(corto_parameterseq* _this, corto_uint32 length, corto_parameter* elements) {
    CORTO_UNUSED(_this);
    corto_parameterseqResize(_this, length);
    corto_uint32 i = 0;
    for (i = 0; i < length; i ++) {
        if (&elements[i]) {
            corto_ptr_copy(&_this->buffer[i], corto_parameter_o, &elements[i]);
        }
    }
    return corto_define(_this);
}

corto_parameterseq* _corto_parameterseqAssign(corto_parameterseq* _this, corto_uint32 length, corto_parameter* elements) {
    CORTO_UNUSED(_this);
    corto_parameterseqResize(_this, length);
    corto_uint32 i = 0;
    for (i = 0; i < length; i ++) {
        if (&elements[i]) {
            corto_ptr_copy(&_this->buffer[i], corto_parameter_o, &elements[i]);
        }
    }
    return _this;
}

corto_post_action* _corto_post_actionCreate(corto_object instance, corto_function procedure) {
    corto_post_action* _this;
    _this = (corto_post_action*)corto_declare(NULL, NULL, corto_post_action_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_ref(&((corto_delegatedata*)_this)->instance, instance);
        corto_set_ref(&((corto_delegatedata*)_this)->procedure, procedure);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_post_action* _corto_post_actionCreateChild(corto_object _parent, const char *_id, corto_object instance, corto_function procedure) {
    corto_post_action* _this;
    _this = (corto_post_action*)corto_declare(_parent, _id, corto_post_action_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_ref(&((corto_delegatedata*)_this)->instance, instance);
        corto_set_ref(&((corto_delegatedata*)_this)->procedure, procedure);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_post_actionUpdate(corto_post_action* _this, corto_object instance, corto_function procedure) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_set_ref(&((corto_delegatedata*)((corto_post_action*)CORTO_OFFSET(_this, ((corto_type)corto_post_action_o)->size)))->instance, instance);
            corto_set_ref(&((corto_delegatedata*)((corto_post_action*)CORTO_OFFSET(_this, ((corto_type)corto_post_action_o)->size)))->procedure, procedure);
        } else {
            corto_set_ref(&((corto_delegatedata*)_this)->instance, instance);
            corto_set_ref(&((corto_delegatedata*)_this)->procedure, procedure);
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

corto_post_action* _corto_post_actionDeclare(void) {
    corto_post_action* _this;
    _this = (corto_post_action*)corto_declare(NULL, NULL, corto_post_action_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_post_action* _corto_post_actionDeclareChild(corto_object _parent, const char *_id) {
    corto_post_action* _this;
    _this = (corto_post_action*)corto_declare(_parent, _id, corto_post_action_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_post_actionDefine(corto_post_action* _this, corto_object instance, corto_function procedure) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_delegatedata*)_this)->instance, instance);
    corto_set_ref(&((corto_delegatedata*)_this)->procedure, procedure);
    return corto_define(_this);
}

corto_post_action* _corto_post_actionAssign(corto_post_action* _this, corto_object instance, corto_function procedure) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_delegatedata*)_this)->instance, instance);
    corto_set_ref(&((corto_delegatedata*)_this)->procedure, procedure);
    return _this;
}

corto_int16 corto_post_actionCall(corto_post_action *_delegate) {
    if (_delegate->super.procedure) {
        if (_delegate->super.instance) {
            corto_invoke(_delegate->super.procedure, NULL, _delegate->super.instance);
        } else {
            corto_invoke(_delegate->super.procedure, NULL);
        }
    } else {
        return -1;
    }
    return 0;
}

corto_int16 corto_post_actionInitC(corto_post_action *d, corto_void ___ (*callback)(void)) {
    d->super.instance = NULL;
    d->super.procedure = corto_declare(NULL, NULL, corto_function_o);
    d->super.procedure->kind = CORTO_PROCEDURE_CDECL;
    corto_set_ref(&d->super.procedure->returnType, corto_void_o);
    corto_function_parseParamString(d->super.procedure, "()");
    d->super.procedure->fptr = (corto_word)callback;
    corto_define(d->super.procedure);
    return 0;
}

corto_int16 corto_post_actionInitCInstance(corto_post_action *d, corto_object instance, corto_void ___ (*callback)(corto_object)) {
    d->super.instance = instance;
    corto_claim(instance);
    d->super.procedure = corto_declare(NULL, NULL, corto_function_o);
    d->super.procedure->kind = CORTO_PROCEDURE_CDECL;
    corto_set_ref(&d->super.procedure->returnType, corto_void_o);
    corto_function_parseParamString(d->super.procedure, "(object instance)");
    d->super.procedure->fptr = (corto_word)callback;
    corto_define(d->super.procedure);
    return 0;
}

corto_pre_action* _corto_pre_actionCreate(corto_object instance, corto_function procedure) {
    corto_pre_action* _this;
    _this = (corto_pre_action*)corto_declare(NULL, NULL, corto_pre_action_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_ref(&((corto_delegatedata*)_this)->instance, instance);
        corto_set_ref(&((corto_delegatedata*)_this)->procedure, procedure);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_pre_action* _corto_pre_actionCreateChild(corto_object _parent, const char *_id, corto_object instance, corto_function procedure) {
    corto_pre_action* _this;
    _this = (corto_pre_action*)corto_declare(_parent, _id, corto_pre_action_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_ref(&((corto_delegatedata*)_this)->instance, instance);
        corto_set_ref(&((corto_delegatedata*)_this)->procedure, procedure);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_pre_actionUpdate(corto_pre_action* _this, corto_object instance, corto_function procedure) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_set_ref(&((corto_delegatedata*)((corto_pre_action*)CORTO_OFFSET(_this, ((corto_type)corto_pre_action_o)->size)))->instance, instance);
            corto_set_ref(&((corto_delegatedata*)((corto_pre_action*)CORTO_OFFSET(_this, ((corto_type)corto_pre_action_o)->size)))->procedure, procedure);
        } else {
            corto_set_ref(&((corto_delegatedata*)_this)->instance, instance);
            corto_set_ref(&((corto_delegatedata*)_this)->procedure, procedure);
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

corto_pre_action* _corto_pre_actionDeclare(void) {
    corto_pre_action* _this;
    _this = (corto_pre_action*)corto_declare(NULL, NULL, corto_pre_action_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_pre_action* _corto_pre_actionDeclareChild(corto_object _parent, const char *_id) {
    corto_pre_action* _this;
    _this = (corto_pre_action*)corto_declare(_parent, _id, corto_pre_action_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_pre_actionDefine(corto_pre_action* _this, corto_object instance, corto_function procedure) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_delegatedata*)_this)->instance, instance);
    corto_set_ref(&((corto_delegatedata*)_this)->procedure, procedure);
    return corto_define(_this);
}

corto_pre_action* _corto_pre_actionAssign(corto_pre_action* _this, corto_object instance, corto_function procedure) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_delegatedata*)_this)->instance, instance);
    corto_set_ref(&((corto_delegatedata*)_this)->procedure, procedure);
    return _this;
}

corto_int16 corto_pre_actionCall(corto_pre_action *_delegate, corto_int16* _result) {
    if (_delegate->super.procedure) {
        if (_delegate->super.instance) {
            corto_invoke(_delegate->super.procedure, _result, _delegate->super.instance);
        } else {
            corto_invoke(_delegate->super.procedure, _result);
        }
    } else {
        return -1;
    }
    return 0;
}

corto_int16 corto_pre_actionInitC(corto_pre_action *d, corto_int16 ___ (*callback)(void)) {
    d->super.instance = NULL;
    d->super.procedure = corto_declare(NULL, NULL, corto_function_o);
    d->super.procedure->kind = CORTO_PROCEDURE_CDECL;
    corto_set_ref(&d->super.procedure->returnType, corto_int16_o);
    corto_function_parseParamString(d->super.procedure, "()");
    d->super.procedure->fptr = (corto_word)callback;
    corto_define(d->super.procedure);
    return 0;
}

corto_int16 corto_pre_actionInitCInstance(corto_pre_action *d, corto_object instance, corto_int16 ___ (*callback)(corto_object)) {
    d->super.instance = instance;
    corto_claim(instance);
    d->super.procedure = corto_declare(NULL, NULL, corto_function_o);
    d->super.procedure->kind = CORTO_PROCEDURE_CDECL;
    corto_set_ref(&d->super.procedure->returnType, corto_int16_o);
    corto_function_parseParamString(d->super.procedure, "(object instance)");
    d->super.procedure->fptr = (corto_word)callback;
    corto_define(d->super.procedure);
    return 0;
}

corto_primitive _corto_primitiveCreate(corto_width width) {
    corto_primitive _this;
    _this = (corto_primitive)corto_declare(NULL, NULL, corto_primitive_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        ((corto_primitive)_this)->width = width;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_primitive _corto_primitiveCreateChild(corto_object _parent, const char *_id, corto_width width) {
    corto_primitive _this;
    _this = (corto_primitive)corto_declare(_parent, _id, corto_primitive_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        ((corto_primitive)_this)->width = width;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_primitiveUpdate(corto_primitive _this, corto_width width) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            ((corto_primitive)((corto_primitive)CORTO_OFFSET(_this, ((corto_type)corto_primitive_o)->size)))->width = width;
        } else {
            ((corto_primitive)_this)->width = width;
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

corto_primitive _corto_primitiveDeclare(void) {
    corto_primitive _this;
    _this = (corto_primitive)corto_declare(NULL, NULL, corto_primitive_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_primitive _corto_primitiveDeclareChild(corto_object _parent, const char *_id) {
    corto_primitive _this;
    _this = (corto_primitive)corto_declare(_parent, _id, corto_primitive_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_primitiveDefine(corto_primitive _this, corto_width width) {
    CORTO_UNUSED(_this);
    ((corto_primitive)_this)->width = width;
    return corto_define(_this);
}

corto_primitive _corto_primitiveAssign(corto_primitive _this, corto_width width) {
    CORTO_UNUSED(_this);
    ((corto_primitive)_this)->width = width;
    return _this;
}

corto_primitiveKind* _corto_primitiveKindCreate(corto_primitiveKind value) {
    corto_primitiveKind* _this;
    _this = (corto_primitiveKind*)corto_declare(NULL, NULL, corto_primitiveKind_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        *_this = value;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_primitiveKind* _corto_primitiveKindCreateChild(corto_object _parent, const char *_id, corto_primitiveKind value) {
    corto_primitiveKind* _this;
    _this = (corto_primitiveKind*)corto_declare(_parent, _id, corto_primitiveKind_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        *_this = value;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_primitiveKindUpdate(corto_primitiveKind* _this, corto_primitiveKind value) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            *((corto_primitiveKind*)CORTO_OFFSET(_this, ((corto_type)corto_primitiveKind_o)->size)) = value;
        } else {
            *_this = value;
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

corto_primitiveKind* _corto_primitiveKindDeclare(void) {
    corto_primitiveKind* _this;
    _this = (corto_primitiveKind*)corto_declare(NULL, NULL, corto_primitiveKind_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_primitiveKind* _corto_primitiveKindDeclareChild(corto_object _parent, const char *_id) {
    corto_primitiveKind* _this;
    _this = (corto_primitiveKind*)corto_declare(_parent, _id, corto_primitiveKind_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_primitiveKindDefine(corto_primitiveKind* _this, corto_primitiveKind value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return corto_define(_this);
}

corto_primitiveKind* _corto_primitiveKindAssign(corto_primitiveKind* _this, corto_primitiveKind value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

corto_procedure _corto_procedureCreate(bool hasThis, corto_type thisType) {
    corto_procedure _this;
    _this = (corto_procedure)corto_declare(NULL, NULL, corto_procedure_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        ((corto_procedure)_this)->hasThis = hasThis;
        corto_set_ref(&((corto_procedure)_this)->thisType, thisType);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_procedure _corto_procedureCreateChild(corto_object _parent, const char *_id, bool hasThis, corto_type thisType) {
    corto_procedure _this;
    _this = (corto_procedure)corto_declare(_parent, _id, corto_procedure_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        ((corto_procedure)_this)->hasThis = hasThis;
        corto_set_ref(&((corto_procedure)_this)->thisType, thisType);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_procedureUpdate(corto_procedure _this, bool hasThis, corto_type thisType) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            ((corto_procedure)((corto_procedure)CORTO_OFFSET(_this, ((corto_type)corto_procedure_o)->size)))->hasThis = hasThis;
            corto_set_ref(&((corto_procedure)((corto_procedure)CORTO_OFFSET(_this, ((corto_type)corto_procedure_o)->size)))->thisType, thisType);
        } else {
            ((corto_procedure)_this)->hasThis = hasThis;
            corto_set_ref(&((corto_procedure)_this)->thisType, thisType);
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

corto_procedure _corto_procedureDeclare(void) {
    corto_procedure _this;
    _this = (corto_procedure)corto_declare(NULL, NULL, corto_procedure_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_procedure _corto_procedureDeclareChild(corto_object _parent, const char *_id) {
    corto_procedure _this;
    _this = (corto_procedure)corto_declare(_parent, _id, corto_procedure_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_procedureDefine(corto_procedure _this, bool hasThis, corto_type thisType) {
    CORTO_UNUSED(_this);
    ((corto_procedure)_this)->hasThis = hasThis;
    corto_set_ref(&((corto_procedure)_this)->thisType, thisType);
    return corto_define(_this);
}

corto_procedure _corto_procedureAssign(corto_procedure _this, bool hasThis, corto_type thisType) {
    CORTO_UNUSED(_this);
    ((corto_procedure)_this)->hasThis = hasThis;
    corto_set_ref(&((corto_procedure)_this)->thisType, thisType);
    return _this;
}

corto_quantity _corto_quantityCreate(corto_unit base_unit) {
    corto_quantity _this;
    _this = (corto_quantity)corto_declare(NULL, NULL, corto_quantity_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_ref(&((corto_quantity)_this)->base_unit, base_unit);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_quantity _corto_quantityCreateChild(corto_object _parent, const char *_id, corto_unit base_unit) {
    corto_quantity _this;
    _this = (corto_quantity)corto_declare(_parent, _id, corto_quantity_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_ref(&((corto_quantity)_this)->base_unit, base_unit);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_quantityUpdate(corto_quantity _this, corto_unit base_unit) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_set_ref(&((corto_quantity)((corto_quantity)CORTO_OFFSET(_this, ((corto_type)corto_quantity_o)->size)))->base_unit, base_unit);
        } else {
            corto_set_ref(&((corto_quantity)_this)->base_unit, base_unit);
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

corto_quantity _corto_quantityDeclare(void) {
    corto_quantity _this;
    _this = (corto_quantity)corto_declare(NULL, NULL, corto_quantity_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_quantity _corto_quantityDeclareChild(corto_object _parent, const char *_id) {
    corto_quantity _this;
    _this = (corto_quantity)corto_declare(_parent, _id, corto_quantity_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_quantityDefine(corto_quantity _this, corto_unit base_unit) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_quantity)_this)->base_unit, base_unit);
    return corto_define(_this);
}

corto_quantity _corto_quantityAssign(corto_quantity _this, corto_unit base_unit) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_quantity)_this)->base_unit, base_unit);
    return _this;
}

corto_sequence _corto_sequenceCreate(corto_type elementType, uint32_t max) {
    corto_sequence _this;
    _this = (corto_sequence)corto_declare(NULL, NULL, corto_sequence_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_ref(&((corto_collection)_this)->elementType, elementType);
        ((corto_collection)_this)->max = max;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_sequence _corto_sequenceCreateChild(corto_object _parent, const char *_id, corto_type elementType, uint32_t max) {
    corto_sequence _this;
    _this = (corto_sequence)corto_declare(_parent, _id, corto_sequence_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_ref(&((corto_collection)_this)->elementType, elementType);
        ((corto_collection)_this)->max = max;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_sequenceUpdate(corto_sequence _this, corto_type elementType, uint32_t max) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_set_ref(&((corto_collection)((corto_sequence)CORTO_OFFSET(_this, ((corto_type)corto_sequence_o)->size)))->elementType, elementType);
            ((corto_collection)((corto_sequence)CORTO_OFFSET(_this, ((corto_type)corto_sequence_o)->size)))->max = max;
        } else {
            corto_set_ref(&((corto_collection)_this)->elementType, elementType);
            ((corto_collection)_this)->max = max;
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

corto_sequence _corto_sequenceDeclare(void) {
    corto_sequence _this;
    _this = (corto_sequence)corto_declare(NULL, NULL, corto_sequence_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_sequence _corto_sequenceDeclareChild(corto_object _parent, const char *_id) {
    corto_sequence _this;
    _this = (corto_sequence)corto_declare(_parent, _id, corto_sequence_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_sequenceDefine(corto_sequence _this, corto_type elementType, uint32_t max) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_collection)_this)->elementType, elementType);
    ((corto_collection)_this)->max = max;
    return corto_define(_this);
}

corto_sequence _corto_sequenceAssign(corto_sequence _this, corto_type elementType, uint32_t max) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_collection)_this)->elementType, elementType);
    ((corto_collection)_this)->max = max;
    return _this;
}

corto_state* _corto_stateCreate(corto_state value) {
    corto_state* _this;
    _this = (corto_state*)corto_declare(NULL, NULL, corto_state_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        *_this = value;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_state* _corto_stateCreateChild(corto_object _parent, const char *_id, corto_state value) {
    corto_state* _this;
    _this = (corto_state*)corto_declare(_parent, _id, corto_state_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        *_this = value;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_stateUpdate(corto_state* _this, corto_state value) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            *((corto_state*)CORTO_OFFSET(_this, ((corto_type)corto_state_o)->size)) = value;
        } else {
            *_this = value;
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

corto_state* _corto_stateDeclare(void) {
    corto_state* _this;
    _this = (corto_state*)corto_declare(NULL, NULL, corto_state_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_state* _corto_stateDeclareChild(corto_object _parent, const char *_id) {
    corto_state* _this;
    _this = (corto_state*)corto_declare(_parent, _id, corto_state_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_stateDefine(corto_state* _this, corto_state value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return corto_define(_this);
}

corto_state* _corto_stateAssign(corto_state* _this, corto_state value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

corto_string* _corto_stringCreate(corto_string value) {
    corto_string* _this;
    _this = (corto_string*)corto_declare(NULL, NULL, corto_string_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_str(_this, value);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_string* _corto_stringCreateChild(corto_object _parent, const char *_id, corto_string value) {
    corto_string* _this;
    _this = (corto_string*)corto_declare(_parent, _id, corto_string_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_str(_this, value);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_stringUpdate(corto_string* _this, corto_string value) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_set_str(((corto_string*)CORTO_OFFSET(_this, ((corto_type)corto_string_o)->size)), value);
        } else {
            corto_set_str(_this, value);
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

corto_string* _corto_stringDeclare(void) {
    corto_string* _this;
    _this = (corto_string*)corto_declare(NULL, NULL, corto_string_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_string* _corto_stringDeclareChild(corto_object _parent, const char *_id) {
    corto_string* _this;
    _this = (corto_string*)corto_declare(_parent, _id, corto_string_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_stringDefine(corto_string* _this, corto_string value) {
    CORTO_UNUSED(_this);
    corto_set_str(_this, value);
    return corto_define(_this);
}

corto_string* _corto_stringAssign(corto_string* _this, corto_string value) {
    CORTO_UNUSED(_this);
    corto_set_str(_this, value);
    return _this;
}

corto_stringlist* _corto_stringlistCreate(corto_uint32 length, corto_string* elements) {
    corto_stringlist* _this;
    _this = (corto_stringlist*)corto_declare(NULL, NULL, corto_stringlist_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_uint32 i = 0;
        corto_stringlistClear(*_this);
        for (i = 0; i < length; i ++) {
            corto_stringlistAppend(*_this, elements[i]);
        }
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_stringlist* _corto_stringlistCreateChild(corto_object _parent, const char *_id, corto_uint32 length, corto_string* elements) {
    corto_stringlist* _this;
    _this = (corto_stringlist*)corto_declare(_parent, _id, corto_stringlist_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_uint32 i = 0;
        corto_stringlistClear(*_this);
        for (i = 0; i < length; i ++) {
            corto_stringlistAppend(*_this, elements[i]);
        }
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_stringlistUpdate(corto_stringlist* _this, corto_uint32 length, corto_string* elements) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_uint32 i = 0;
            corto_stringlistClear(*((corto_stringlist*)CORTO_OFFSET(_this, ((corto_type)corto_stringlist_o)->size)));
            for (i = 0; i < length; i ++) {
                corto_stringlistAppend(*((corto_stringlist*)CORTO_OFFSET(_this, ((corto_type)corto_stringlist_o)->size)), elements[i]);
            }
        } else {
            corto_uint32 i = 0;
            corto_stringlistClear(*_this);
            for (i = 0; i < length; i ++) {
                corto_stringlistAppend(*_this, elements[i]);
            }
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

corto_stringlist* _corto_stringlistDeclare(void) {
    corto_stringlist* _this;
    _this = (corto_stringlist*)corto_declare(NULL, NULL, corto_stringlist_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_stringlist* _corto_stringlistDeclareChild(corto_object _parent, const char *_id) {
    corto_stringlist* _this;
    _this = (corto_stringlist*)corto_declare(_parent, _id, corto_stringlist_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_stringlistDefine(corto_stringlist* _this, corto_uint32 length, corto_string* elements) {
    CORTO_UNUSED(_this);
    corto_uint32 i = 0;
    corto_stringlistClear(*_this);
    for (i = 0; i < length; i ++) {
        corto_stringlistAppend(*_this, elements[i]);
    }
    return corto_define(_this);
}

corto_stringlist* _corto_stringlistAssign(corto_stringlist* _this, corto_uint32 length, corto_string* elements) {
    CORTO_UNUSED(_this);
    corto_uint32 i = 0;
    corto_stringlistClear(*_this);
    for (i = 0; i < length; i ++) {
        corto_stringlistAppend(*_this, elements[i]);
    }
    return _this;
}

corto_stringseq* _corto_stringseqCreate(corto_uint32 length, corto_string* elements) {
    corto_stringseq* _this;
    _this = (corto_stringseq*)corto_declare(NULL, NULL, corto_stringseq_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_stringseqResize(_this, length);
        corto_uint32 i = 0;
        for (i = 0; i < length; i ++) {
            corto_set_str(&_this->buffer[i], elements[i]);
        }
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_stringseq* _corto_stringseqCreateChild(corto_object _parent, const char *_id, corto_uint32 length, corto_string* elements) {
    corto_stringseq* _this;
    _this = (corto_stringseq*)corto_declare(_parent, _id, corto_stringseq_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_stringseqResize(_this, length);
        corto_uint32 i = 0;
        for (i = 0; i < length; i ++) {
            corto_set_str(&_this->buffer[i], elements[i]);
        }
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_stringseqUpdate(corto_stringseq* _this, corto_uint32 length, corto_string* elements) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_stringseqResize(((corto_stringseq*)CORTO_OFFSET(_this, ((corto_type)corto_stringseq_o)->size)), length);
            corto_uint32 i = 0;
            for (i = 0; i < length; i ++) {
                corto_set_str(&((corto_stringseq*)CORTO_OFFSET(_this, ((corto_type)corto_stringseq_o)->size))->buffer[i], elements[i]);
            }
        } else {
            corto_stringseqResize(_this, length);
            corto_uint32 i = 0;
            for (i = 0; i < length; i ++) {
                corto_set_str(&_this->buffer[i], elements[i]);
            }
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

corto_stringseq* _corto_stringseqDeclare(void) {
    corto_stringseq* _this;
    _this = (corto_stringseq*)corto_declare(NULL, NULL, corto_stringseq_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_stringseq* _corto_stringseqDeclareChild(corto_object _parent, const char *_id) {
    corto_stringseq* _this;
    _this = (corto_stringseq*)corto_declare(_parent, _id, corto_stringseq_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_stringseqDefine(corto_stringseq* _this, corto_uint32 length, corto_string* elements) {
    CORTO_UNUSED(_this);
    corto_stringseqResize(_this, length);
    corto_uint32 i = 0;
    for (i = 0; i < length; i ++) {
        corto_set_str(&_this->buffer[i], elements[i]);
    }
    return corto_define(_this);
}

corto_stringseq* _corto_stringseqAssign(corto_stringseq* _this, corto_uint32 length, corto_string* elements) {
    CORTO_UNUSED(_this);
    corto_stringseqResize(_this, length);
    corto_uint32 i = 0;
    for (i = 0; i < length; i ++) {
        corto_set_str(&_this->buffer[i], elements[i]);
    }
    return _this;
}

corto_struct _corto_structCreate(corto_interface base, corto_modifier baseAccess) {
    corto_struct _this;
    _this = (corto_struct)corto_declare(NULL, NULL, corto_struct_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_ref(&((corto_interface)_this)->base, base);
        ((corto_struct)_this)->baseAccess = baseAccess;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_struct _corto_structCreateChild(corto_object _parent, const char *_id, corto_interface base, corto_modifier baseAccess) {
    corto_struct _this;
    _this = (corto_struct)corto_declare(_parent, _id, corto_struct_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_ref(&((corto_interface)_this)->base, base);
        ((corto_struct)_this)->baseAccess = baseAccess;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_structUpdate(corto_struct _this, corto_interface base, corto_modifier baseAccess) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_set_ref(&((corto_interface)((corto_struct)CORTO_OFFSET(_this, ((corto_type)corto_struct_o)->size)))->base, base);
            ((corto_struct)((corto_struct)CORTO_OFFSET(_this, ((corto_type)corto_struct_o)->size)))->baseAccess = baseAccess;
        } else {
            corto_set_ref(&((corto_interface)_this)->base, base);
            ((corto_struct)_this)->baseAccess = baseAccess;
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

corto_struct _corto_structDeclare(void) {
    corto_struct _this;
    _this = (corto_struct)corto_declare(NULL, NULL, corto_struct_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_struct _corto_structDeclareChild(corto_object _parent, const char *_id) {
    corto_struct _this;
    _this = (corto_struct)corto_declare(_parent, _id, corto_struct_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_structDefine(corto_struct _this, corto_interface base, corto_modifier baseAccess) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_interface)_this)->base, base);
    ((corto_struct)_this)->baseAccess = baseAccess;
    return corto_define(_this);
}

corto_struct _corto_structAssign(corto_struct _this, corto_interface base, corto_modifier baseAccess) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_interface)_this)->base, base);
    ((corto_struct)_this)->baseAccess = baseAccess;
    return _this;
}

corto_table _corto_tableCreate(corto_interface base, corto_modifier baseAccess, corto_interfaceseq implements, corto_type type, const char * value) {
    corto_table _this;
    _this = (corto_table)corto_declare(NULL, NULL, corto_table_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_ref(&((corto_interface)_this)->base, base);
        ((corto_struct)_this)->baseAccess = baseAccess;
        corto_ptr_copy(&((corto_class)_this)->implements, corto_interfaceseq_o, &implements);
        corto_set_ref(&((corto_container)_this)->type, type);
        corto_set_str(&((corto_container)_this)->value, value);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_table _corto_tableCreateChild(corto_object _parent, const char *_id, corto_interface base, corto_modifier baseAccess, corto_interfaceseq implements, corto_type type, const char * value) {
    corto_table _this;
    _this = (corto_table)corto_declare(_parent, _id, corto_table_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_ref(&((corto_interface)_this)->base, base);
        ((corto_struct)_this)->baseAccess = baseAccess;
        corto_ptr_copy(&((corto_class)_this)->implements, corto_interfaceseq_o, &implements);
        corto_set_ref(&((corto_container)_this)->type, type);
        corto_set_str(&((corto_container)_this)->value, value);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_tableUpdate(corto_table _this, corto_interface base, corto_modifier baseAccess, corto_interfaceseq implements, corto_type type, const char * value) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_set_ref(&((corto_interface)((corto_table)CORTO_OFFSET(_this, ((corto_type)corto_table_o)->size)))->base, base);
            ((corto_struct)((corto_table)CORTO_OFFSET(_this, ((corto_type)corto_table_o)->size)))->baseAccess = baseAccess;
            corto_ptr_copy(&((corto_class)((corto_table)CORTO_OFFSET(_this, ((corto_type)corto_table_o)->size)))->implements, corto_interfaceseq_o, &implements);
            corto_set_ref(&((corto_container)((corto_table)CORTO_OFFSET(_this, ((corto_type)corto_table_o)->size)))->type, type);
            corto_set_str(&((corto_container)((corto_table)CORTO_OFFSET(_this, ((corto_type)corto_table_o)->size)))->value, value);
        } else {
            corto_set_ref(&((corto_interface)_this)->base, base);
            ((corto_struct)_this)->baseAccess = baseAccess;
            corto_ptr_copy(&((corto_class)_this)->implements, corto_interfaceseq_o, &implements);
            corto_set_ref(&((corto_container)_this)->type, type);
            corto_set_str(&((corto_container)_this)->value, value);
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

corto_table _corto_tableDeclare(void) {
    corto_table _this;
    _this = (corto_table)corto_declare(NULL, NULL, corto_table_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_table _corto_tableDeclareChild(corto_object _parent, const char *_id) {
    corto_table _this;
    _this = (corto_table)corto_declare(_parent, _id, corto_table_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_tableDefine(corto_table _this, corto_interface base, corto_modifier baseAccess, corto_interfaceseq implements, corto_type type, const char * value) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_interface)_this)->base, base);
    ((corto_struct)_this)->baseAccess = baseAccess;
    corto_ptr_copy(&((corto_class)_this)->implements, corto_interfaceseq_o, &implements);
    corto_set_ref(&((corto_container)_this)->type, type);
    corto_set_str(&((corto_container)_this)->value, value);
    return corto_define(_this);
}

corto_table _corto_tableAssign(corto_table _this, corto_interface base, corto_modifier baseAccess, corto_interfaceseq implements, corto_type type, const char * value) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_interface)_this)->base, base);
    ((corto_struct)_this)->baseAccess = baseAccess;
    corto_ptr_copy(&((corto_class)_this)->implements, corto_interfaceseq_o, &implements);
    corto_set_ref(&((corto_container)_this)->type, type);
    corto_set_str(&((corto_container)_this)->value, value);
    return _this;
}

corto_tableinstance _corto_tableinstanceCreate(corto_struct type) {
    corto_tableinstance _this;
    _this = (corto_tableinstance)corto_declare(NULL, NULL, corto_tableinstance_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_ref(&((corto_tableinstance)_this)->type, type);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_tableinstance _corto_tableinstanceCreateChild(corto_object _parent, const char *_id, corto_struct type) {
    corto_tableinstance _this;
    _this = (corto_tableinstance)corto_declare(_parent, _id, corto_tableinstance_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_ref(&((corto_tableinstance)_this)->type, type);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_tableinstanceUpdate(corto_tableinstance _this, corto_struct type) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_set_ref(&((corto_tableinstance)((corto_tableinstance)CORTO_OFFSET(_this, ((corto_type)corto_tableinstance_o)->size)))->type, type);
        } else {
            corto_set_ref(&((corto_tableinstance)_this)->type, type);
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

corto_tableinstance _corto_tableinstanceDeclare(void) {
    corto_tableinstance _this;
    _this = (corto_tableinstance)corto_declare(NULL, NULL, corto_tableinstance_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_tableinstance _corto_tableinstanceDeclareChild(corto_object _parent, const char *_id) {
    corto_tableinstance _this;
    _this = (corto_tableinstance)corto_declare(_parent, _id, corto_tableinstance_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_tableinstanceDefine(corto_tableinstance _this, corto_struct type) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_tableinstance)_this)->type, type);
    return corto_define(_this);
}

corto_tableinstance _corto_tableinstanceAssign(corto_tableinstance _this, corto_struct type) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_tableinstance)_this)->type, type);
    return _this;
}

corto_target _corto_targetCreate(corto_type type) {
    corto_target _this;
    _this = (corto_target)corto_declare(NULL, NULL, corto_target_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_ref(&((corto_target)_this)->type, type);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_target _corto_targetCreateChild(corto_object _parent, const char *_id, corto_type type) {
    corto_target _this;
    _this = (corto_target)corto_declare(_parent, _id, corto_target_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_ref(&((corto_target)_this)->type, type);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_targetUpdate(corto_target _this, corto_type type) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_set_ref(&((corto_target)((corto_target)CORTO_OFFSET(_this, ((corto_type)corto_target_o)->size)))->type, type);
        } else {
            corto_set_ref(&((corto_target)_this)->type, type);
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

corto_target _corto_targetDeclare(void) {
    corto_target _this;
    _this = (corto_target)corto_declare(NULL, NULL, corto_target_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_target _corto_targetDeclareChild(corto_object _parent, const char *_id) {
    corto_target _this;
    _this = (corto_target)corto_declare(_parent, _id, corto_target_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_targetDefine(corto_target _this, corto_type type) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_target)_this)->type, type);
    return corto_define(_this);
}

corto_target _corto_targetAssign(corto_target _this, corto_type type) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_target)_this)->type, type);
    return _this;
}

corto_text _corto_textCreate(corto_width charWidth, uint64_t length) {
    corto_text _this;
    _this = (corto_text)corto_declare(NULL, NULL, corto_text_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        ((corto_text)_this)->charWidth = charWidth;
        ((corto_text)_this)->length = length;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_text _corto_textCreateChild(corto_object _parent, const char *_id, corto_width charWidth, uint64_t length) {
    corto_text _this;
    _this = (corto_text)corto_declare(_parent, _id, corto_text_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        ((corto_text)_this)->charWidth = charWidth;
        ((corto_text)_this)->length = length;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_textUpdate(corto_text _this, corto_width charWidth, uint64_t length) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            ((corto_text)((corto_text)CORTO_OFFSET(_this, ((corto_type)corto_text_o)->size)))->charWidth = charWidth;
            ((corto_text)((corto_text)CORTO_OFFSET(_this, ((corto_type)corto_text_o)->size)))->length = length;
        } else {
            ((corto_text)_this)->charWidth = charWidth;
            ((corto_text)_this)->length = length;
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

corto_text _corto_textDeclare(void) {
    corto_text _this;
    _this = (corto_text)corto_declare(NULL, NULL, corto_text_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_text _corto_textDeclareChild(corto_object _parent, const char *_id) {
    corto_text _this;
    _this = (corto_text)corto_declare(_parent, _id, corto_text_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_textDefine(corto_text _this, corto_width charWidth, uint64_t length) {
    CORTO_UNUSED(_this);
    ((corto_text)_this)->charWidth = charWidth;
    ((corto_text)_this)->length = length;
    return corto_define(_this);
}

corto_text _corto_textAssign(corto_text _this, corto_width charWidth, uint64_t length) {
    CORTO_UNUSED(_this);
    ((corto_text)_this)->charWidth = charWidth;
    ((corto_text)_this)->length = length;
    return _this;
}

corto_tool _corto_toolCreate(void) {
    corto_tool _this;
    _this = (corto_tool)corto_declare(NULL, NULL, corto_tool_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_tool _corto_toolCreateChild(corto_object _parent, const char *_id) {
    corto_tool _this;
    _this = (corto_tool)corto_declare(_parent, _id, corto_tool_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_toolUpdate(corto_tool _this) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
        } else {
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

corto_tool _corto_toolDeclare(void) {
    corto_tool _this;
    _this = (corto_tool)corto_declare(NULL, NULL, corto_tool_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_tool _corto_toolDeclareChild(corto_object _parent, const char *_id) {
    corto_tool _this;
    _this = (corto_tool)corto_declare(_parent, _id, corto_tool_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_toolDefine(corto_tool _this) {
    CORTO_UNUSED(_this);
    return corto_define(_this);
}

corto_tool _corto_toolAssign(corto_tool _this) {
    CORTO_UNUSED(_this);
    return _this;
}

corto_type _corto_typeCreate(corto_typeKind kind, bool reference, corto_attr attr) {
    corto_type _this;
    _this = (corto_type)corto_declare(NULL, NULL, corto_type_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        ((corto_type)_this)->kind = kind;
        ((corto_type)_this)->reference = reference;
        ((corto_type)_this)->attr = attr;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_type _corto_typeCreateChild(corto_object _parent, const char *_id, corto_typeKind kind, bool reference, corto_attr attr) {
    corto_type _this;
    _this = (corto_type)corto_declare(_parent, _id, corto_type_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        ((corto_type)_this)->kind = kind;
        ((corto_type)_this)->reference = reference;
        ((corto_type)_this)->attr = attr;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_typeUpdate(corto_type _this, corto_typeKind kind, bool reference, corto_attr attr) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            ((corto_type)((corto_type)CORTO_OFFSET(_this, ((corto_type)corto_type_o)->size)))->kind = kind;
            ((corto_type)((corto_type)CORTO_OFFSET(_this, ((corto_type)corto_type_o)->size)))->reference = reference;
            ((corto_type)((corto_type)CORTO_OFFSET(_this, ((corto_type)corto_type_o)->size)))->attr = attr;
        } else {
            ((corto_type)_this)->kind = kind;
            ((corto_type)_this)->reference = reference;
            ((corto_type)_this)->attr = attr;
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

corto_type _corto_typeDeclare(void) {
    corto_type _this;
    _this = (corto_type)corto_declare(NULL, NULL, corto_type_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_type _corto_typeDeclareChild(corto_object _parent, const char *_id) {
    corto_type _this;
    _this = (corto_type)corto_declare(_parent, _id, corto_type_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_typeDefine(corto_type _this, corto_typeKind kind, bool reference, corto_attr attr) {
    CORTO_UNUSED(_this);
    ((corto_type)_this)->kind = kind;
    ((corto_type)_this)->reference = reference;
    ((corto_type)_this)->attr = attr;
    return corto_define(_this);
}

corto_type _corto_typeAssign(corto_type _this, corto_typeKind kind, bool reference, corto_attr attr) {
    CORTO_UNUSED(_this);
    ((corto_type)_this)->kind = kind;
    ((corto_type)_this)->reference = reference;
    ((corto_type)_this)->attr = attr;
    return _this;
}

corto_typeKind* _corto_typeKindCreate(corto_typeKind value) {
    corto_typeKind* _this;
    _this = (corto_typeKind*)corto_declare(NULL, NULL, corto_typeKind_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        *_this = value;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_typeKind* _corto_typeKindCreateChild(corto_object _parent, const char *_id, corto_typeKind value) {
    corto_typeKind* _this;
    _this = (corto_typeKind*)corto_declare(_parent, _id, corto_typeKind_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        *_this = value;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_typeKindUpdate(corto_typeKind* _this, corto_typeKind value) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            *((corto_typeKind*)CORTO_OFFSET(_this, ((corto_type)corto_typeKind_o)->size)) = value;
        } else {
            *_this = value;
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

corto_typeKind* _corto_typeKindDeclare(void) {
    corto_typeKind* _this;
    _this = (corto_typeKind*)corto_declare(NULL, NULL, corto_typeKind_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_typeKind* _corto_typeKindDeclareChild(corto_object _parent, const char *_id) {
    corto_typeKind* _this;
    _this = (corto_typeKind*)corto_declare(_parent, _id, corto_typeKind_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_typeKindDefine(corto_typeKind* _this, corto_typeKind value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return corto_define(_this);
}

corto_typeKind* _corto_typeKindAssign(corto_typeKind* _this, corto_typeKind value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

corto_typeOptions* _corto_typeOptionsCreate(corto_type parentType, corto_state parentState, corto_type defaultType, corto_type defaultProcedureType) {
    corto_typeOptions* _this;
    _this = (corto_typeOptions*)corto_declare(NULL, NULL, corto_typeOptions_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_ref(&((corto_typeOptions*)_this)->parentType, parentType);
        ((corto_typeOptions*)_this)->parentState = parentState;
        corto_set_ref(&((corto_typeOptions*)_this)->defaultType, defaultType);
        corto_set_ref(&((corto_typeOptions*)_this)->defaultProcedureType, defaultProcedureType);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_typeOptions* _corto_typeOptionsCreateChild(corto_object _parent, const char *_id, corto_type parentType, corto_state parentState, corto_type defaultType, corto_type defaultProcedureType) {
    corto_typeOptions* _this;
    _this = (corto_typeOptions*)corto_declare(_parent, _id, corto_typeOptions_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_ref(&((corto_typeOptions*)_this)->parentType, parentType);
        ((corto_typeOptions*)_this)->parentState = parentState;
        corto_set_ref(&((corto_typeOptions*)_this)->defaultType, defaultType);
        corto_set_ref(&((corto_typeOptions*)_this)->defaultProcedureType, defaultProcedureType);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_typeOptionsUpdate(corto_typeOptions* _this, corto_type parentType, corto_state parentState, corto_type defaultType, corto_type defaultProcedureType) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_set_ref(&((corto_typeOptions*)((corto_typeOptions*)CORTO_OFFSET(_this, ((corto_type)corto_typeOptions_o)->size)))->parentType, parentType);
            ((corto_typeOptions*)((corto_typeOptions*)CORTO_OFFSET(_this, ((corto_type)corto_typeOptions_o)->size)))->parentState = parentState;
            corto_set_ref(&((corto_typeOptions*)((corto_typeOptions*)CORTO_OFFSET(_this, ((corto_type)corto_typeOptions_o)->size)))->defaultType, defaultType);
            corto_set_ref(&((corto_typeOptions*)((corto_typeOptions*)CORTO_OFFSET(_this, ((corto_type)corto_typeOptions_o)->size)))->defaultProcedureType, defaultProcedureType);
        } else {
            corto_set_ref(&((corto_typeOptions*)_this)->parentType, parentType);
            ((corto_typeOptions*)_this)->parentState = parentState;
            corto_set_ref(&((corto_typeOptions*)_this)->defaultType, defaultType);
            corto_set_ref(&((corto_typeOptions*)_this)->defaultProcedureType, defaultProcedureType);
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

corto_typeOptions* _corto_typeOptionsDeclare(void) {
    corto_typeOptions* _this;
    _this = (corto_typeOptions*)corto_declare(NULL, NULL, corto_typeOptions_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_typeOptions* _corto_typeOptionsDeclareChild(corto_object _parent, const char *_id) {
    corto_typeOptions* _this;
    _this = (corto_typeOptions*)corto_declare(_parent, _id, corto_typeOptions_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_typeOptionsDefine(corto_typeOptions* _this, corto_type parentType, corto_state parentState, corto_type defaultType, corto_type defaultProcedureType) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_typeOptions*)_this)->parentType, parentType);
    ((corto_typeOptions*)_this)->parentState = parentState;
    corto_set_ref(&((corto_typeOptions*)_this)->defaultType, defaultType);
    corto_set_ref(&((corto_typeOptions*)_this)->defaultProcedureType, defaultProcedureType);
    return corto_define(_this);
}

corto_typeOptions* _corto_typeOptionsAssign(corto_typeOptions* _this, corto_type parentType, corto_state parentState, corto_type defaultType, corto_type defaultProcedureType) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_typeOptions*)_this)->parentType, parentType);
    ((corto_typeOptions*)_this)->parentState = parentState;
    corto_set_ref(&((corto_typeOptions*)_this)->defaultType, defaultType);
    corto_set_ref(&((corto_typeOptions*)_this)->defaultProcedureType, defaultProcedureType);
    return _this;
}

corto_uint _corto_uintCreate(corto_width width, uint64_t min, uint64_t max) {
    corto_uint _this;
    _this = (corto_uint)corto_declare(NULL, NULL, corto_uint_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        ((corto_primitive)_this)->width = width;
        ((corto_uint)_this)->min = min;
        ((corto_uint)_this)->max = max;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_uint _corto_uintCreateChild(corto_object _parent, const char *_id, corto_width width, uint64_t min, uint64_t max) {
    corto_uint _this;
    _this = (corto_uint)corto_declare(_parent, _id, corto_uint_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        ((corto_primitive)_this)->width = width;
        ((corto_uint)_this)->min = min;
        ((corto_uint)_this)->max = max;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_uintUpdate(corto_uint _this, corto_width width, uint64_t min, uint64_t max) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            ((corto_primitive)((corto_uint)CORTO_OFFSET(_this, ((corto_type)corto_uint_o)->size)))->width = width;
            ((corto_uint)((corto_uint)CORTO_OFFSET(_this, ((corto_type)corto_uint_o)->size)))->min = min;
            ((corto_uint)((corto_uint)CORTO_OFFSET(_this, ((corto_type)corto_uint_o)->size)))->max = max;
        } else {
            ((corto_primitive)_this)->width = width;
            ((corto_uint)_this)->min = min;
            ((corto_uint)_this)->max = max;
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

corto_uint _corto_uintDeclare(void) {
    corto_uint _this;
    _this = (corto_uint)corto_declare(NULL, NULL, corto_uint_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_uint _corto_uintDeclareChild(corto_object _parent, const char *_id) {
    corto_uint _this;
    _this = (corto_uint)corto_declare(_parent, _id, corto_uint_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_uintDefine(corto_uint _this, corto_width width, uint64_t min, uint64_t max) {
    CORTO_UNUSED(_this);
    ((corto_primitive)_this)->width = width;
    ((corto_uint)_this)->min = min;
    ((corto_uint)_this)->max = max;
    return corto_define(_this);
}

corto_uint _corto_uintAssign(corto_uint _this, corto_width width, uint64_t min, uint64_t max) {
    CORTO_UNUSED(_this);
    ((corto_primitive)_this)->width = width;
    ((corto_uint)_this)->min = min;
    ((corto_uint)_this)->max = max;
    return _this;
}

uint16_t* _corto_uint16Create(uint16_t value) {
    uint16_t* _this;
    _this = (uint16_t*)corto_declare(NULL, NULL, corto_uint16_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        *_this = value;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

uint16_t* _corto_uint16CreateChild(corto_object _parent, const char *_id, uint16_t value) {
    uint16_t* _this;
    _this = (uint16_t*)corto_declare(_parent, _id, corto_uint16_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        *_this = value;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_uint16Update(uint16_t* _this, uint16_t value) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            *((uint16_t*)CORTO_OFFSET(_this, ((corto_type)corto_uint16_o)->size)) = value;
        } else {
            *_this = value;
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

uint16_t* _corto_uint16Declare(void) {
    uint16_t* _this;
    _this = (uint16_t*)corto_declare(NULL, NULL, corto_uint16_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

uint16_t* _corto_uint16DeclareChild(corto_object _parent, const char *_id) {
    uint16_t* _this;
    _this = (uint16_t*)corto_declare(_parent, _id, corto_uint16_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_uint16Define(uint16_t* _this, uint16_t value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return corto_define(_this);
}

uint16_t* _corto_uint16Assign(uint16_t* _this, uint16_t value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

uint32_t* _corto_uint32Create(uint32_t value) {
    uint32_t* _this;
    _this = (uint32_t*)corto_declare(NULL, NULL, corto_uint32_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        *_this = value;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

uint32_t* _corto_uint32CreateChild(corto_object _parent, const char *_id, uint32_t value) {
    uint32_t* _this;
    _this = (uint32_t*)corto_declare(_parent, _id, corto_uint32_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        *_this = value;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_uint32Update(uint32_t* _this, uint32_t value) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            *((uint32_t*)CORTO_OFFSET(_this, ((corto_type)corto_uint32_o)->size)) = value;
        } else {
            *_this = value;
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

uint32_t* _corto_uint32Declare(void) {
    uint32_t* _this;
    _this = (uint32_t*)corto_declare(NULL, NULL, corto_uint32_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

uint32_t* _corto_uint32DeclareChild(corto_object _parent, const char *_id) {
    uint32_t* _this;
    _this = (uint32_t*)corto_declare(_parent, _id, corto_uint32_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_uint32Define(uint32_t* _this, uint32_t value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return corto_define(_this);
}

uint32_t* _corto_uint32Assign(uint32_t* _this, uint32_t value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

uint64_t* _corto_uint64Create(uint64_t value) {
    uint64_t* _this;
    _this = (uint64_t*)corto_declare(NULL, NULL, corto_uint64_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        *_this = value;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

uint64_t* _corto_uint64CreateChild(corto_object _parent, const char *_id, uint64_t value) {
    uint64_t* _this;
    _this = (uint64_t*)corto_declare(_parent, _id, corto_uint64_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        *_this = value;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_uint64Update(uint64_t* _this, uint64_t value) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            *((uint64_t*)CORTO_OFFSET(_this, ((corto_type)corto_uint64_o)->size)) = value;
        } else {
            *_this = value;
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

uint64_t* _corto_uint64Declare(void) {
    uint64_t* _this;
    _this = (uint64_t*)corto_declare(NULL, NULL, corto_uint64_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

uint64_t* _corto_uint64DeclareChild(corto_object _parent, const char *_id) {
    uint64_t* _this;
    _this = (uint64_t*)corto_declare(_parent, _id, corto_uint64_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_uint64Define(uint64_t* _this, uint64_t value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return corto_define(_this);
}

uint64_t* _corto_uint64Assign(uint64_t* _this, uint64_t value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

uint8_t* _corto_uint8Create(uint8_t value) {
    uint8_t* _this;
    _this = (uint8_t*)corto_declare(NULL, NULL, corto_uint8_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        *_this = value;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

uint8_t* _corto_uint8CreateChild(corto_object _parent, const char *_id, uint8_t value) {
    uint8_t* _this;
    _this = (uint8_t*)corto_declare(_parent, _id, corto_uint8_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        *_this = value;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_uint8Update(uint8_t* _this, uint8_t value) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            *((uint8_t*)CORTO_OFFSET(_this, ((corto_type)corto_uint8_o)->size)) = value;
        } else {
            *_this = value;
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

uint8_t* _corto_uint8Declare(void) {
    uint8_t* _this;
    _this = (uint8_t*)corto_declare(NULL, NULL, corto_uint8_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

uint8_t* _corto_uint8DeclareChild(corto_object _parent, const char *_id) {
    uint8_t* _this;
    _this = (uint8_t*)corto_declare(_parent, _id, corto_uint8_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_uint8Define(uint8_t* _this, uint8_t value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return corto_define(_this);
}

uint8_t* _corto_uint8Assign(uint8_t* _this, uint8_t value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

corto_union _corto_unionCreate(corto_type discriminator) {
    corto_union _this;
    _this = (corto_union)corto_declare(NULL, NULL, corto_union_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_ref(&((corto_union)_this)->discriminator, discriminator);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_union _corto_unionCreateChild(corto_object _parent, const char *_id, corto_type discriminator) {
    corto_union _this;
    _this = (corto_union)corto_declare(_parent, _id, corto_union_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_ref(&((corto_union)_this)->discriminator, discriminator);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_unionUpdate(corto_union _this, corto_type discriminator) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_set_ref(&((corto_union)((corto_union)CORTO_OFFSET(_this, ((corto_type)corto_union_o)->size)))->discriminator, discriminator);
        } else {
            corto_set_ref(&((corto_union)_this)->discriminator, discriminator);
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

corto_union _corto_unionDeclare(void) {
    corto_union _this;
    _this = (corto_union)corto_declare(NULL, NULL, corto_union_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_union _corto_unionDeclareChild(corto_object _parent, const char *_id) {
    corto_union _this;
    _this = (corto_union)corto_declare(_parent, _id, corto_union_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_unionDefine(corto_union _this, corto_type discriminator) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_union)_this)->discriminator, discriminator);
    return corto_define(_this);
}

corto_union _corto_unionAssign(corto_union _this, corto_type discriminator) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_union)_this)->discriminator, discriminator);
    return _this;
}

corto_unit _corto_unitCreate(corto_quantity quantity, const char * symbol, const char * conversion, corto_type type) {
    corto_unit _this;
    _this = (corto_unit)corto_declare(NULL, NULL, corto_unit_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_ref(&((corto_unit)_this)->quantity, quantity);
        corto_set_str(&((corto_unit)_this)->symbol, symbol);
        corto_set_str(&((corto_unit)_this)->conversion, conversion);
        corto_set_ref(&((corto_unit)_this)->type, type);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_unit _corto_unitCreateChild(corto_object _parent, const char *_id, corto_quantity quantity, const char * symbol, const char * conversion, corto_type type) {
    corto_unit _this;
    _this = (corto_unit)corto_declare(_parent, _id, corto_unit_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_ref(&((corto_unit)_this)->quantity, quantity);
        corto_set_str(&((corto_unit)_this)->symbol, symbol);
        corto_set_str(&((corto_unit)_this)->conversion, conversion);
        corto_set_ref(&((corto_unit)_this)->type, type);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_unitUpdate(corto_unit _this, corto_quantity quantity, const char * symbol, const char * conversion, corto_type type) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_set_ref(&((corto_unit)((corto_unit)CORTO_OFFSET(_this, ((corto_type)corto_unit_o)->size)))->quantity, quantity);
            corto_set_str(&((corto_unit)((corto_unit)CORTO_OFFSET(_this, ((corto_type)corto_unit_o)->size)))->symbol, symbol);
            corto_set_str(&((corto_unit)((corto_unit)CORTO_OFFSET(_this, ((corto_type)corto_unit_o)->size)))->conversion, conversion);
            corto_set_ref(&((corto_unit)((corto_unit)CORTO_OFFSET(_this, ((corto_type)corto_unit_o)->size)))->type, type);
        } else {
            corto_set_ref(&((corto_unit)_this)->quantity, quantity);
            corto_set_str(&((corto_unit)_this)->symbol, symbol);
            corto_set_str(&((corto_unit)_this)->conversion, conversion);
            corto_set_ref(&((corto_unit)_this)->type, type);
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

corto_unit _corto_unitDeclare(void) {
    corto_unit _this;
    _this = (corto_unit)corto_declare(NULL, NULL, corto_unit_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_unit _corto_unitDeclareChild(corto_object _parent, const char *_id) {
    corto_unit _this;
    _this = (corto_unit)corto_declare(_parent, _id, corto_unit_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_unitDefine(corto_unit _this, corto_quantity quantity, const char * symbol, const char * conversion, corto_type type) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_unit)_this)->quantity, quantity);
    corto_set_str(&((corto_unit)_this)->symbol, symbol);
    corto_set_str(&((corto_unit)_this)->conversion, conversion);
    corto_set_ref(&((corto_unit)_this)->type, type);
    return corto_define(_this);
}

corto_unit _corto_unitAssign(corto_unit _this, corto_quantity quantity, const char * symbol, const char * conversion, corto_type type) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_unit)_this)->quantity, quantity);
    corto_set_str(&((corto_unit)_this)->symbol, symbol);
    corto_set_str(&((corto_unit)_this)->conversion, conversion);
    corto_set_ref(&((corto_unit)_this)->type, type);
    return _this;
}

void* _corto_unknownCreate(void) {
    void* _this;
    _this = (void*)corto_declare(NULL, NULL, corto_unknown_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
    }
    return _this;
}

void* _corto_unknownCreateChild(corto_object _parent, const char *_id) {
    void* _this;
    _this = (void*)corto_declare(_parent, _id, corto_unknown_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
    }
    return _this;
}

corto_int16 _corto_unknownUpdate(void* _this) {
    CORTO_UNUSED(_this);
    return corto_update(_this);
}

corto_verbatim _corto_verbatimCreate(const char * contentType) {
    corto_verbatim _this;
    _this = (corto_verbatim)corto_declare(NULL, NULL, corto_verbatim_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_str(&((corto_verbatim)_this)->contentType, contentType);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_verbatim _corto_verbatimCreateChild(corto_object _parent, const char *_id, const char * contentType) {
    corto_verbatim _this;
    _this = (corto_verbatim)corto_declare(_parent, _id, corto_verbatim_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_str(&((corto_verbatim)_this)->contentType, contentType);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_verbatimUpdate(corto_verbatim _this, const char * contentType) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_set_str(&((corto_verbatim)((corto_verbatim)CORTO_OFFSET(_this, ((corto_type)corto_verbatim_o)->size)))->contentType, contentType);
        } else {
            corto_set_str(&((corto_verbatim)_this)->contentType, contentType);
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

corto_verbatim _corto_verbatimDeclare(void) {
    corto_verbatim _this;
    _this = (corto_verbatim)corto_declare(NULL, NULL, corto_verbatim_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_verbatim _corto_verbatimDeclareChild(corto_object _parent, const char *_id) {
    corto_verbatim _this;
    _this = (corto_verbatim)corto_declare(_parent, _id, corto_verbatim_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_verbatimDefine(corto_verbatim _this, const char * contentType) {
    CORTO_UNUSED(_this);
    corto_set_str(&((corto_verbatim)_this)->contentType, contentType);
    return corto_define(_this);
}

corto_verbatim _corto_verbatimAssign(corto_verbatim _this, const char * contentType) {
    CORTO_UNUSED(_this);
    corto_set_str(&((corto_verbatim)_this)->contentType, contentType);
    return _this;
}

void* _corto_voidCreate(void) {
    void* _this;
    _this = (void*)corto_declare(NULL, NULL, corto_void_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
    }
    return _this;
}

void* _corto_voidCreateChild(corto_object _parent, const char *_id) {
    void* _this;
    _this = (void*)corto_declare(_parent, _id, corto_void_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
    }
    return _this;
}

corto_int16 _corto_voidUpdate(void* _this) {
    CORTO_UNUSED(_this);
    return corto_update(_this);
}

corto_width* _corto_widthCreate(corto_width value) {
    corto_width* _this;
    _this = (corto_width*)corto_declare(NULL, NULL, corto_width_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        *_this = value;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_width* _corto_widthCreateChild(corto_object _parent, const char *_id, corto_width value) {
    corto_width* _this;
    _this = (corto_width*)corto_declare(_parent, _id, corto_width_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        *_this = value;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_widthUpdate(corto_width* _this, corto_width value) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            *((corto_width*)CORTO_OFFSET(_this, ((corto_type)corto_width_o)->size)) = value;
        } else {
            *_this = value;
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

corto_width* _corto_widthDeclare(void) {
    corto_width* _this;
    _this = (corto_width*)corto_declare(NULL, NULL, corto_width_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_width* _corto_widthDeclareChild(corto_object _parent, const char *_id) {
    corto_width* _this;
    _this = (corto_width*)corto_declare(_parent, _id, corto_width_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_widthDefine(corto_width* _this, corto_width value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return corto_define(_this);
}

corto_width* _corto_widthAssign(corto_width* _this, corto_width value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

uintptr_t* _corto_wordCreate(uintptr_t value) {
    uintptr_t* _this;
    _this = (uintptr_t*)corto_declare(NULL, NULL, corto_word_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        *_this = value;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

uintptr_t* _corto_wordCreateChild(corto_object _parent, const char *_id, uintptr_t value) {
    uintptr_t* _this;
    _this = (uintptr_t*)corto_declare(_parent, _id, corto_word_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        *_this = value;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_wordUpdate(uintptr_t* _this, uintptr_t value) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            *((uintptr_t*)CORTO_OFFSET(_this, ((corto_type)corto_word_o)->size)) = value;
        } else {
            *_this = value;
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

uintptr_t* _corto_wordDeclare(void) {
    uintptr_t* _this;
    _this = (uintptr_t*)corto_declare(NULL, NULL, corto_word_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

uintptr_t* _corto_wordDeclareChild(corto_object _parent, const char *_id) {
    uintptr_t* _this;
    _this = (uintptr_t*)corto_declare(_parent, _id, corto_word_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_wordDefine(uintptr_t* _this, uintptr_t value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return corto_define(_this);
}

uintptr_t* _corto_wordAssign(uintptr_t* _this, uintptr_t value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

corto_wordseq* _corto_wordseqCreate(corto_uint32 length, uintptr_t* elements) {
    corto_wordseq* _this;
    _this = (corto_wordseq*)corto_declare(NULL, NULL, corto_wordseq_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_wordseqResize(_this, length);
        corto_uint32 i = 0;
        for (i = 0; i < length; i ++) {
            _this->buffer[i] = elements[i];
        }
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_wordseq* _corto_wordseqCreateChild(corto_object _parent, const char *_id, corto_uint32 length, uintptr_t* elements) {
    corto_wordseq* _this;
    _this = (corto_wordseq*)corto_declare(_parent, _id, corto_wordseq_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_wordseqResize(_this, length);
        corto_uint32 i = 0;
        for (i = 0; i < length; i ++) {
            _this->buffer[i] = elements[i];
        }
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_wordseqUpdate(corto_wordseq* _this, corto_uint32 length, uintptr_t* elements) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_wordseqResize(((corto_wordseq*)CORTO_OFFSET(_this, ((corto_type)corto_wordseq_o)->size)), length);
            corto_uint32 i = 0;
            for (i = 0; i < length; i ++) {
                ((corto_wordseq*)CORTO_OFFSET(_this, ((corto_type)corto_wordseq_o)->size))->buffer[i] = elements[i];
            }
        } else {
            corto_wordseqResize(_this, length);
            corto_uint32 i = 0;
            for (i = 0; i < length; i ++) {
                _this->buffer[i] = elements[i];
            }
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

corto_wordseq* _corto_wordseqDeclare(void) {
    corto_wordseq* _this;
    _this = (corto_wordseq*)corto_declare(NULL, NULL, corto_wordseq_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_wordseq* _corto_wordseqDeclareChild(corto_object _parent, const char *_id) {
    corto_wordseq* _this;
    _this = (corto_wordseq*)corto_declare(_parent, _id, corto_wordseq_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_wordseqDefine(corto_wordseq* _this, corto_uint32 length, uintptr_t* elements) {
    CORTO_UNUSED(_this);
    corto_wordseqResize(_this, length);
    corto_uint32 i = 0;
    for (i = 0; i < length; i ++) {
        _this->buffer[i] = elements[i];
    }
    return corto_define(_this);
}

corto_wordseq* _corto_wordseqAssign(corto_wordseq* _this, corto_uint32 length, uintptr_t* elements) {
    CORTO_UNUSED(_this);
    corto_wordseqResize(_this, length);
    corto_uint32 i = 0;
    for (i = 0; i < length; i ++) {
        _this->buffer[i] = elements[i];
    }
    return _this;
}

int32_t* corto_int32seqAppend(corto_int32seq *seq, int32_t element) {
    corto_uint32 size;
    seq->length++;
    seq->buffer = (int32_t*)corto_realloc(seq->buffer, seq->length * (size=corto_type_sizeof(corto_type(corto_int32_o))));
    memset(&seq->buffer[seq->length-1], 0, size);
    corto_ptr_copy(&seq->buffer[seq->length-1], corto_int32_o, &element);
    return &seq->buffer[seq->length-1];
}

int32_t* corto_int32seqAppendAlloc(corto_int32seq *seq) {
    corto_uint32 size;
    seq->length++;
    seq->buffer = (int32_t*)corto_realloc(seq->buffer, seq->length * (size=corto_type_sizeof(corto_type(corto_int32_o))));
    memset(&seq->buffer[seq->length-1], 0, size);
    return &seq->buffer[seq->length-1];
}

void corto_int32seqResize(corto_int32seq *seq, corto_uint32 length) {
    corto_uint32 size;
    seq->buffer = (int32_t*)corto_realloc(seq->buffer, length * (size=corto_type_sizeof(corto_type(corto_int32_o))));
    if (length > seq->length) {
        memset(&seq->buffer[seq->length], 0, size * (length - seq->length));
    }
    seq->length = length;
}

void corto_int32seqClear(corto_int32seq *seq) {
    corto_int32seqResize(seq, 0);
}

corto_interface* corto_interfaceseqAppend(corto_interfaceseq *seq, corto_interface element) {
    corto_uint32 size;
    seq->length++;
    seq->buffer = (corto_interface*)corto_realloc(seq->buffer, seq->length * (size=corto_type_sizeof(corto_type(corto_interface_o))));
    memset(seq->buffer[seq->length-1], 0, size);
    corto_set_ref(&seq->buffer[seq->length-1], element);
    return &seq->buffer[seq->length-1];
}

corto_interface* corto_interfaceseqAppendAlloc(corto_interfaceseq *seq) {
    corto_uint32 size;
    seq->length++;
    seq->buffer = (corto_interface*)corto_realloc(seq->buffer, seq->length * (size=corto_type_sizeof(corto_type(corto_interface_o))));
    memset(seq->buffer[seq->length-1], 0, size);
    return &seq->buffer[seq->length-1];
}

void corto_interfaceseqResize(corto_interfaceseq *seq, corto_uint32 length) {
    corto_uint32 size;
    seq->buffer = (corto_interface*)corto_realloc(seq->buffer, length * (size=corto_type_sizeof(corto_type(corto_interface_o))));
    if (length > seq->length) {
        corto_uint32 i;
        memset(&seq->buffer[seq->length], 0, size * (length - seq->length));
        for(i=seq->length; i<length; i++) {
            {
                corto_ptr_deinit(&seq->buffer[i], corto_interface_o);
            }
        }
    }
    seq->length = length;
}

void corto_interfaceseqClear(corto_interfaceseq *seq) {
    corto_interfaceseqResize(seq, 0);
}

corto_interfaceVector* corto_interfaceVectorseqAppend(corto_interfaceVectorseq *seq, corto_interfaceVector element) {
    corto_uint32 size;
    seq->length++;
    seq->buffer = (corto_interfaceVector*)corto_realloc(seq->buffer, seq->length * (size=corto_type_sizeof(corto_type(corto_interfaceVector_o))));
    memset(&seq->buffer[seq->length-1], 0, size);
    {
        corto_ptr_init(&seq->buffer[seq->length-1], corto_interfaceVector_o);
    }
    corto_ptr_copy(&seq->buffer[seq->length-1], corto_interfaceVector_o, &element);
    return &seq->buffer[seq->length-1];
}

corto_interfaceVector* corto_interfaceVectorseqAppendAlloc(corto_interfaceVectorseq *seq) {
    corto_uint32 size;
    seq->length++;
    seq->buffer = (corto_interfaceVector*)corto_realloc(seq->buffer, seq->length * (size=corto_type_sizeof(corto_type(corto_interfaceVector_o))));
    memset(&seq->buffer[seq->length-1], 0, size);
    {
        corto_ptr_init(&seq->buffer[seq->length-1], corto_interfaceVector_o);
    }
    return &seq->buffer[seq->length-1];
}

void corto_interfaceVectorseqResize(corto_interfaceVectorseq *seq, corto_uint32 length) {
    corto_uint32 size;
    if (length < seq->length) {
        corto_uint32 i;
        for(i=length; i<seq->length; i++) {
            {
                corto_ptr_deinit(&seq->buffer[i], corto_interfaceVector_o);
            }
        }
    }
    seq->buffer = (corto_interfaceVector*)corto_realloc(seq->buffer, length * (size=corto_type_sizeof(corto_type(corto_interfaceVector_o))));
    if (length > seq->length) {
        corto_uint32 i;
        memset(&seq->buffer[seq->length], 0, size * (length - seq->length));
        for(i=seq->length; i<length; i++) {
            {
                corto_ptr_deinit(&seq->buffer[i], corto_interfaceVector_o);
            }
        }
    }
    seq->length = length;
}

void corto_interfaceVectorseqClear(corto_interfaceVectorseq *seq) {
    corto_interfaceVectorseqResize(seq, 0);
}

void corto_objectlistInsert(corto_objectlist list, corto_object element) {
    corto_ll_insert(list, (void*)(corto_word)element);
    if (element) {
        corto_claim(element);
    }
}

void corto_objectlistAppend(corto_objectlist list, corto_object element) {
    corto_ll_append(list, (void*)(corto_word)element);
    if (element) {
        corto_claim(element);
    }
}

void corto_objectlistRemove(corto_objectlist list, corto_object element) {
    corto_ll_remove(list, element);
    corto_release(element);
}

corto_object corto_objectlistTakeFirst(corto_objectlist list) {
    return (corto_object)(corto_word)corto_ll_takeFirst(list);
}

corto_object corto_objectlistLast(corto_objectlist list) {
    return (corto_object)(corto_word)corto_ll_last(list);
}

corto_object corto_objectlistGet(corto_objectlist list, corto_uint32 index) {
    return (corto_object)(corto_word)corto_ll_get(list, index);
}

void corto_objectlistClear(corto_objectlist list) {
    corto_iter iter = corto_ll_iter(list);
    while(corto_iter_hasNext(&iter)) {
        void *ptr = corto_iter_next(&iter);
        corto_release(ptr);
    }
    corto_ll_clear(list);
}

corto_object* corto_objectseqAppend(corto_objectseq *seq, corto_object element) {
    corto_uint32 size;
    seq->length++;
    seq->buffer = (corto_object*)corto_realloc(seq->buffer, seq->length * (size=corto_type_sizeof(corto_type(corto_object_o))));
    memset(seq->buffer[seq->length-1], 0, size);
    corto_set_ref(&seq->buffer[seq->length-1], element);
    return &seq->buffer[seq->length-1];
}

corto_object* corto_objectseqAppendAlloc(corto_objectseq *seq) {
    corto_uint32 size;
    seq->length++;
    seq->buffer = (corto_object*)corto_realloc(seq->buffer, seq->length * (size=corto_type_sizeof(corto_type(corto_object_o))));
    memset(seq->buffer[seq->length-1], 0, size);
    return &seq->buffer[seq->length-1];
}

void corto_objectseqResize(corto_objectseq *seq, corto_uint32 length) {
    corto_uint32 size;
    seq->buffer = (corto_object*)corto_realloc(seq->buffer, length * (size=corto_type_sizeof(corto_type(corto_object_o))));
    if (length > seq->length) {
        corto_uint32 i;
        memset(&seq->buffer[seq->length], 0, size * (length - seq->length));
        for(i=seq->length; i<length; i++) {
            {
                corto_ptr_deinit(&seq->buffer[i], corto_object_o);
            }
        }
    }
    seq->length = length;
}

void corto_objectseqClear(corto_objectseq *seq) {
    corto_objectseqResize(seq, 0);
}

corto_parameter* corto_parameterseqAppend(corto_parameterseq *seq, corto_parameter element) {
    corto_uint32 size;
    seq->length++;
    seq->buffer = (corto_parameter*)corto_realloc(seq->buffer, seq->length * (size=corto_type_sizeof(corto_type(corto_parameter_o))));
    memset(&seq->buffer[seq->length-1], 0, size);
    {
        corto_ptr_init(&seq->buffer[seq->length-1], corto_parameter_o);
    }
    corto_ptr_copy(&seq->buffer[seq->length-1], corto_parameter_o, &element);
    return &seq->buffer[seq->length-1];
}

corto_parameter* corto_parameterseqAppendAlloc(corto_parameterseq *seq) {
    corto_uint32 size;
    seq->length++;
    seq->buffer = (corto_parameter*)corto_realloc(seq->buffer, seq->length * (size=corto_type_sizeof(corto_type(corto_parameter_o))));
    memset(&seq->buffer[seq->length-1], 0, size);
    {
        corto_ptr_init(&seq->buffer[seq->length-1], corto_parameter_o);
    }
    return &seq->buffer[seq->length-1];
}

void corto_parameterseqResize(corto_parameterseq *seq, corto_uint32 length) {
    corto_uint32 size;
    if (length < seq->length) {
        corto_uint32 i;
        for(i=length; i<seq->length; i++) {
            {
                corto_ptr_deinit(&seq->buffer[i], corto_parameter_o);
            }
        }
    }
    seq->buffer = (corto_parameter*)corto_realloc(seq->buffer, length * (size=corto_type_sizeof(corto_type(corto_parameter_o))));
    if (length > seq->length) {
        corto_uint32 i;
        memset(&seq->buffer[seq->length], 0, size * (length - seq->length));
        for(i=seq->length; i<length; i++) {
            {
                corto_ptr_deinit(&seq->buffer[i], corto_parameter_o);
            }
        }
    }
    seq->length = length;
}

void corto_parameterseqClear(corto_parameterseq *seq) {
    corto_parameterseqResize(seq, 0);
}

void corto_stringlistInsert(corto_stringlist list, corto_string element) {
    if (element) {
        corto_ll_insert(list, (void*)corto_strdup(element));
    } else {
    corto_ll_insert(list, (void*)element);
    }
}

void corto_stringlistAppend(corto_stringlist list, corto_string element) {
    if (element) {
        corto_ll_append(list, (void*)corto_strdup(element));
    } else {
    corto_ll_append(list, (void*)element);
    }
}

corto_string corto_stringlistTakeFirst(corto_stringlist list) {
    return (corto_string)(corto_word)corto_ll_takeFirst(list);
}

corto_string corto_stringlistLast(corto_stringlist list) {
    return (corto_string)(corto_word)corto_ll_last(list);
}

corto_string corto_stringlistGet(corto_stringlist list, corto_uint32 index) {
    return (corto_string)(corto_word)corto_ll_get(list, index);
}

void corto_stringlistClear(corto_stringlist list) {
    corto_iter iter = corto_ll_iter(list);
    while(corto_iter_hasNext(&iter)) {
        void *ptr = corto_iter_next(&iter);
        corto_ptr_deinit(ptr, corto_string_o);
    }
    corto_ll_clear(list);
}

corto_string* corto_stringseqAppend(corto_stringseq *seq, corto_string element) {
    corto_uint32 size;
    seq->length++;
    seq->buffer = (corto_string*)corto_realloc(seq->buffer, seq->length * (size=corto_type_sizeof(corto_type(corto_string_o))));
    memset(&seq->buffer[seq->length-1], 0, size);
    corto_ptr_copy(&seq->buffer[seq->length-1], corto_string_o, &element);
    return &seq->buffer[seq->length-1];
}

corto_string* corto_stringseqAppendAlloc(corto_stringseq *seq) {
    corto_uint32 size;
    seq->length++;
    seq->buffer = (corto_string*)corto_realloc(seq->buffer, seq->length * (size=corto_type_sizeof(corto_type(corto_string_o))));
    memset(&seq->buffer[seq->length-1], 0, size);
    return &seq->buffer[seq->length-1];
}

void corto_stringseqResize(corto_stringseq *seq, corto_uint32 length) {
    corto_uint32 size;
    seq->buffer = (corto_string*)corto_realloc(seq->buffer, length * (size=corto_type_sizeof(corto_type(corto_string_o))));
    if (length > seq->length) {
        memset(&seq->buffer[seq->length], 0, size * (length - seq->length));
    }
    seq->length = length;
}

void corto_stringseqClear(corto_stringseq *seq) {
    corto_stringseqResize(seq, 0);
}

uintptr_t* corto_wordseqAppend(corto_wordseq *seq, uintptr_t element) {
    corto_uint32 size;
    seq->length++;
    seq->buffer = (uintptr_t*)corto_realloc(seq->buffer, seq->length * (size=corto_type_sizeof(corto_type(corto_word_o))));
    memset(&seq->buffer[seq->length-1], 0, size);
    corto_ptr_copy(&seq->buffer[seq->length-1], corto_word_o, &element);
    return &seq->buffer[seq->length-1];
}

uintptr_t* corto_wordseqAppendAlloc(corto_wordseq *seq) {
    corto_uint32 size;
    seq->length++;
    seq->buffer = (uintptr_t*)corto_realloc(seq->buffer, seq->length * (size=corto_type_sizeof(corto_type(corto_word_o))));
    memset(&seq->buffer[seq->length-1], 0, size);
    return &seq->buffer[seq->length-1];
}

void corto_wordseqResize(corto_wordseq *seq, corto_uint32 length) {
    corto_uint32 size;
    seq->buffer = (uintptr_t*)corto_realloc(seq->buffer, length * (size=corto_type_sizeof(corto_type(corto_word_o))));
    if (length > seq->length) {
        memset(&seq->buffer[seq->length], 0, size * (length - seq->length));
    }
    seq->length = length;
}

void corto_wordseqClear(corto_wordseq *seq) {
    corto_wordseqResize(seq, 0);
}

