/* lang.c
 *
 * API convenience functions for C-language.
 * This file contains generated code. Do not modify!
 */

#include <corto/c/c.h>

corto_alias _corto_alias__create(corto_object _parent, const char *_id, corto_member member) {
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

corto_int16 _corto_alias__update(corto_alias _this, corto_member member) {
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

corto_alias _corto_alias__assign(corto_alias _this, corto_member member) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_alias)_this)->member, member);
    return _this;
}

corto_any* _corto_any__create(corto_object _parent, const char *_id, corto_type type, void *value) {
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

corto_int16 _corto_any__update(corto_any* _this, corto_type type, void *value) {
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

corto_any* _corto_any__assign(corto_any* _this, corto_type type, void *value) {
    CORTO_UNUSED(_this);
    corto_any v;
    v.value = value;
    v.type = type;
    _this->owner = TRUE;
    corto_ptr_copy(_this, corto_any_o, &v);
    return _this;
}

corto_application _corto_application__create(corto_object _parent, const char *_id) {
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

corto_int16 _corto_application__update(corto_application _this) {
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

corto_application _corto_application__assign(corto_application _this) {
    CORTO_UNUSED(_this);
    return _this;
}

corto_array _corto_array__create(corto_object _parent, const char *_id, corto_type element_type, uint32_t max) {
    corto_array _this;
    _this = (corto_array)corto_declare(_parent, _id, corto_array_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_ref(&((corto_collection)_this)->element_type, element_type);
        ((corto_collection)_this)->max = max;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_array__update(corto_array _this, corto_type element_type, uint32_t max) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_set_ref(&((corto_collection)((corto_array)CORTO_OFFSET(_this, ((corto_type)corto_array_o)->size)))->element_type, element_type);
            ((corto_collection)((corto_array)CORTO_OFFSET(_this, ((corto_type)corto_array_o)->size)))->max = max;
        } else {
            corto_set_ref(&((corto_collection)_this)->element_type, element_type);
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

corto_array _corto_array__assign(corto_array _this, corto_type element_type, uint32_t max) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_collection)_this)->element_type, element_type);
    ((corto_collection)_this)->max = max;
    return _this;
}

corto_attr* _corto_attr__create(corto_object _parent, const char *_id, corto_attr value) {
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

corto_int16 _corto_attr__update(corto_attr* _this, corto_attr value) {
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

corto_attr* _corto_attr__assign(corto_attr* _this, corto_attr value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

corto_binary _corto_binary__create(corto_object _parent, const char *_id, corto_width width) {
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

corto_int16 _corto_binary__update(corto_binary _this, corto_width width) {
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

corto_binary _corto_binary__assign(corto_binary _this, corto_width width) {
    CORTO_UNUSED(_this);
    ((corto_primitive)_this)->width = width;
    return _this;
}

corto_bitmask _corto_bitmask__create(corto_object _parent, const char *_id) {
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

corto_int16 _corto_bitmask__update(corto_bitmask _this) {
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

corto_bitmask _corto_bitmask__assign(corto_bitmask _this) {
    CORTO_UNUSED(_this);
    return _this;
}

bool* _corto_bool__create(corto_object _parent, const char *_id, bool value) {
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

corto_int16 _corto_bool__update(bool* _this, bool value) {
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

bool* _corto_bool__assign(bool* _this, bool value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

corto_boolean _corto_boolean__create(corto_object _parent, const char *_id) {
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

corto_int16 _corto_boolean__update(corto_boolean _this) {
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

corto_boolean _corto_boolean__assign(corto_boolean _this) {
    CORTO_UNUSED(_this);
    return _this;
}

corto_case _corto_case__create(corto_object _parent, const char *_id, corto_int32seq discriminator, corto_type type, corto_modifierMask modifiers) {
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

corto_int16 _corto_case__update(corto_case _this, corto_int32seq discriminator, corto_type type, corto_modifierMask modifiers) {
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

corto_case _corto_case__assign(corto_case _this, corto_int32seq discriminator, corto_type type, corto_modifierMask modifiers) {
    CORTO_UNUSED(_this);
    corto_ptr_copy(&((corto_case)_this)->discriminator, corto_int32seq_o, &discriminator);
    corto_set_ref(&((corto_member)_this)->type, type);
    ((corto_member)_this)->modifiers = modifiers;
    return _this;
}

char* _corto_char__create(corto_object _parent, const char *_id, char value) {
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

corto_int16 _corto_char__update(char* _this, char value) {
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

char* _corto_char__assign(char* _this, char value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

corto_character _corto_character__create(corto_object _parent, const char *_id, corto_width width) {
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

corto_int16 _corto_character__update(corto_character _this, corto_width width) {
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

corto_character _corto_character__assign(corto_character _this, corto_width width) {
    CORTO_UNUSED(_this);
    ((corto_primitive)_this)->width = width;
    return _this;
}

corto_class _corto_class__create(corto_object _parent, const char *_id, corto_interface base, corto_modifierMask base_modifiers, corto_interfaceseq implements) {
    corto_class _this;
    _this = (corto_class)corto_declare(_parent, _id, corto_class_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_ref(&((corto_interface)_this)->base, base);
        ((corto_struct)_this)->base_modifiers = base_modifiers;
        corto_ptr_copy(&((corto_class)_this)->implements, corto_interfaceseq_o, &implements);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_class__update(corto_class _this, corto_interface base, corto_modifierMask base_modifiers, corto_interfaceseq implements) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_set_ref(&((corto_interface)((corto_class)CORTO_OFFSET(_this, ((corto_type)corto_class_o)->size)))->base, base);
            ((corto_struct)((corto_class)CORTO_OFFSET(_this, ((corto_type)corto_class_o)->size)))->base_modifiers = base_modifiers;
            corto_ptr_copy(&((corto_class)((corto_class)CORTO_OFFSET(_this, ((corto_type)corto_class_o)->size)))->implements, corto_interfaceseq_o, &implements);
        } else {
            corto_set_ref(&((corto_interface)_this)->base, base);
            ((corto_struct)_this)->base_modifiers = base_modifiers;
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

corto_class _corto_class__assign(corto_class _this, corto_interface base, corto_modifierMask base_modifiers, corto_interfaceseq implements) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_interface)_this)->base, base);
    ((corto_struct)_this)->base_modifiers = base_modifiers;
    corto_ptr_copy(&((corto_class)_this)->implements, corto_interfaceseq_o, &implements);
    return _this;
}

corto_collection _corto_collection__create(corto_object _parent, const char *_id, corto_type element_type, uint32_t max) {
    corto_collection _this;
    _this = (corto_collection)corto_declare(_parent, _id, corto_collection_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_ref(&((corto_collection)_this)->element_type, element_type);
        ((corto_collection)_this)->max = max;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_collection__update(corto_collection _this, corto_type element_type, uint32_t max) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_set_ref(&((corto_collection)((corto_collection)CORTO_OFFSET(_this, ((corto_type)corto_collection_o)->size)))->element_type, element_type);
            ((corto_collection)((corto_collection)CORTO_OFFSET(_this, ((corto_type)corto_collection_o)->size)))->max = max;
        } else {
            corto_set_ref(&((corto_collection)_this)->element_type, element_type);
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

corto_collection _corto_collection__assign(corto_collection _this, corto_type element_type, uint32_t max) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_collection)_this)->element_type, element_type);
    ((corto_collection)_this)->max = max;
    return _this;
}

corto_collectionKind* _corto_collectionKind__create(corto_object _parent, const char *_id, corto_collectionKind value) {
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

corto_int16 _corto_collectionKind__update(corto_collectionKind* _this, corto_collectionKind value) {
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

corto_collectionKind* _corto_collectionKind__assign(corto_collectionKind* _this, corto_collectionKind value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

corto_compositeKind* _corto_compositeKind__create(corto_object _parent, const char *_id, corto_compositeKind value) {
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

corto_int16 _corto_compositeKind__update(corto_compositeKind* _this, corto_compositeKind value) {
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

corto_compositeKind* _corto_compositeKind__assign(corto_compositeKind* _this, corto_compositeKind value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

int32_t* _corto_constant__create(corto_object _parent, const char *_id, int32_t value) {
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

corto_int16 _corto_constant__update(int32_t* _this, int32_t value) {
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

int32_t* _corto_constant__assign(int32_t* _this, int32_t value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

corto_container _corto_container__create(corto_object _parent, const char *_id, corto_interface base, corto_modifierMask base_modifiers, corto_interfaceseq implements, corto_type type, const char * value) {
    corto_container _this;
    _this = (corto_container)corto_declare(_parent, _id, corto_container_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_ref(&((corto_interface)_this)->base, base);
        ((corto_struct)_this)->base_modifiers = base_modifiers;
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

corto_int16 _corto_container__update(corto_container _this, corto_interface base, corto_modifierMask base_modifiers, corto_interfaceseq implements, corto_type type, const char * value) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_set_ref(&((corto_interface)((corto_container)CORTO_OFFSET(_this, ((corto_type)corto_container_o)->size)))->base, base);
            ((corto_struct)((corto_container)CORTO_OFFSET(_this, ((corto_type)corto_container_o)->size)))->base_modifiers = base_modifiers;
            corto_ptr_copy(&((corto_class)((corto_container)CORTO_OFFSET(_this, ((corto_type)corto_container_o)->size)))->implements, corto_interfaceseq_o, &implements);
            corto_set_ref(&((corto_container)((corto_container)CORTO_OFFSET(_this, ((corto_type)corto_container_o)->size)))->type, type);
            corto_set_str(&((corto_container)((corto_container)CORTO_OFFSET(_this, ((corto_type)corto_container_o)->size)))->value, value);
        } else {
            corto_set_ref(&((corto_interface)_this)->base, base);
            ((corto_struct)_this)->base_modifiers = base_modifiers;
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

corto_container _corto_container__assign(corto_container _this, corto_interface base, corto_modifierMask base_modifiers, corto_interfaceseq implements, corto_type type, const char * value) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_interface)_this)->base, base);
    ((corto_struct)_this)->base_modifiers = base_modifiers;
    corto_ptr_copy(&((corto_class)_this)->implements, corto_interfaceseq_o, &implements);
    corto_set_ref(&((corto_container)_this)->type, type);
    corto_set_str(&((corto_container)_this)->value, value);
    return _this;
}

corto_default _corto_default__create(corto_object _parent, const char *_id, corto_type type) {
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

corto_int16 _corto_default__update(corto_default _this, corto_type type) {
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

corto_default _corto_default__assign(corto_default _this, corto_type type) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_member)_this)->type, type);
    return _this;
}

corto_delegate _corto_delegate__create(corto_object _parent, const char *_id, corto_type return_type, bool is_reference, corto_parameterseq parameters) {
    corto_delegate _this;
    _this = (corto_delegate)corto_declare(_parent, _id, corto_delegate_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_ref(&((corto_delegate)_this)->return_type, return_type);
        ((corto_delegate)_this)->is_reference = is_reference;
        corto_ptr_copy(&((corto_delegate)_this)->parameters, corto_parameterseq_o, &parameters);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_delegate__update(corto_delegate _this, corto_type return_type, bool is_reference, corto_parameterseq parameters) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_set_ref(&((corto_delegate)((corto_delegate)CORTO_OFFSET(_this, ((corto_type)corto_delegate_o)->size)))->return_type, return_type);
            ((corto_delegate)((corto_delegate)CORTO_OFFSET(_this, ((corto_type)corto_delegate_o)->size)))->is_reference = is_reference;
            corto_ptr_copy(&((corto_delegate)((corto_delegate)CORTO_OFFSET(_this, ((corto_type)corto_delegate_o)->size)))->parameters, corto_parameterseq_o, &parameters);
        } else {
            corto_set_ref(&((corto_delegate)_this)->return_type, return_type);
            ((corto_delegate)_this)->is_reference = is_reference;
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

corto_delegate _corto_delegate__assign(corto_delegate _this, corto_type return_type, bool is_reference, corto_parameterseq parameters) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_delegate)_this)->return_type, return_type);
    ((corto_delegate)_this)->is_reference = is_reference;
    corto_ptr_copy(&((corto_delegate)_this)->parameters, corto_parameterseq_o, &parameters);
    return _this;
}

corto_delegatedata* _corto_delegatedata__create(corto_object _parent, const char *_id, corto_object instance, corto_function procedure) {
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

corto_int16 _corto_delegatedata__update(corto_delegatedata* _this, corto_object instance, corto_function procedure) {
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

corto_delegatedata* _corto_delegatedata__assign(corto_delegatedata* _this, corto_object instance, corto_function procedure) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_delegatedata*)_this)->instance, instance);
    corto_set_ref(&((corto_delegatedata*)_this)->procedure, procedure);
    return _this;
}

corto_enum _corto_enum__create(corto_object _parent, const char *_id) {
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

corto_int16 _corto_enum__update(corto_enum _this) {
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

corto_enum _corto_enum__assign(corto_enum _this) {
    CORTO_UNUSED(_this);
    return _this;
}

corto_equalityKind* _corto_equalityKind__create(corto_object _parent, const char *_id, corto_equalityKind value) {
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

corto_int16 _corto_equalityKind__update(corto_equalityKind* _this, corto_equalityKind value) {
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

corto_equalityKind* _corto_equalityKind__assign(corto_equalityKind* _this, corto_equalityKind value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

corto_float _corto_float__create(corto_object _parent, const char *_id, corto_width width, double min, double max) {
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

corto_int16 _corto_float__update(corto_float _this, corto_width width, double min, double max) {
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

corto_float _corto_float__assign(corto_float _this, corto_width width, double min, double max) {
    CORTO_UNUSED(_this);
    ((corto_primitive)_this)->width = width;
    ((corto_float)_this)->min = min;
    ((corto_float)_this)->max = max;
    return _this;
}

float* _corto_float32__create(corto_object _parent, const char *_id, float value) {
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

corto_int16 _corto_float32__update(float* _this, float value) {
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

float* _corto_float32__assign(float* _this, float value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

double* _corto_float64__create(corto_object _parent, const char *_id, double value) {
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

corto_int16 _corto_float64__update(double* _this, double value) {
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

double* _corto_float64__assign(double* _this, double value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

corto_function _corto_function__create(corto_object _parent, const char *_id, corto_type return_type, bool is_reference, void(*_impl)(void)) {
    corto_function _this;
    _this = (corto_function)corto_declare(_parent, _id, corto_function_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_ref(&((corto_function)_this)->return_type, return_type);
        ((corto_function)_this)->is_reference = is_reference;
        corto_function(_this)->kind = CORTO_PROCEDURE_CDECL;
        corto_function(_this)->fptr = (corto_word)_impl;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_function__update(corto_function _this, corto_type return_type, bool is_reference, void(*_impl)(void)) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_set_ref(&((corto_function)((corto_function)CORTO_OFFSET(_this, ((corto_type)corto_function_o)->size)))->return_type, return_type);
            ((corto_function)((corto_function)CORTO_OFFSET(_this, ((corto_type)corto_function_o)->size)))->is_reference = is_reference;
            corto_function(((corto_function)CORTO_OFFSET(_this, ((corto_type)corto_function_o)->size)))->kind = CORTO_PROCEDURE_CDECL;
            corto_function(((corto_function)CORTO_OFFSET(_this, ((corto_type)corto_function_o)->size)))->fptr = (corto_word)_impl;
        } else {
            corto_set_ref(&((corto_function)_this)->return_type, return_type);
            ((corto_function)_this)->is_reference = is_reference;
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

corto_function _corto_function__assign(corto_function _this, corto_type return_type, bool is_reference, void(*_impl)(void)) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_function)_this)->return_type, return_type);
    ((corto_function)_this)->is_reference = is_reference;
    corto_function(_this)->kind = CORTO_PROCEDURE_CDECL;
    corto_function(_this)->fptr = (corto_word)_impl;
    return _this;
}

corto_inout* _corto_inout__create(corto_object _parent, const char *_id, corto_inout value) {
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

corto_int16 _corto_inout__update(corto_inout* _this, corto_inout value) {
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

corto_inout* _corto_inout__assign(corto_inout* _this, corto_inout value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

corto_int _corto_int__create(corto_object _parent, const char *_id, corto_width width, int64_t min, int64_t max) {
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

corto_int16 _corto_int__update(corto_int _this, corto_width width, int64_t min, int64_t max) {
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

corto_int _corto_int__assign(corto_int _this, corto_width width, int64_t min, int64_t max) {
    CORTO_UNUSED(_this);
    ((corto_primitive)_this)->width = width;
    ((corto_int)_this)->min = min;
    ((corto_int)_this)->max = max;
    return _this;
}

int16_t* _corto_int16__create(corto_object _parent, const char *_id, int16_t value) {
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

corto_int16 _corto_int16__update(int16_t* _this, int16_t value) {
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

int16_t* _corto_int16__assign(int16_t* _this, int16_t value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

int32_t* _corto_int32__create(corto_object _parent, const char *_id, int32_t value) {
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

corto_int16 _corto_int32__update(int32_t* _this, int32_t value) {
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

int32_t* _corto_int32__assign(int32_t* _this, int32_t value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

corto_int32seq* _corto_int32seq__create(corto_object _parent, const char *_id, corto_uint32 length, int32_t* elements) {
    corto_int32seq* _this;
    _this = (corto_int32seq*)corto_declare(_parent, _id, corto_int32seq_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_int32seq__resize(_this, length);
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

corto_int16 _corto_int32seq__update(corto_int32seq* _this, corto_uint32 length, int32_t* elements) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_int32seq__resize(((corto_int32seq*)CORTO_OFFSET(_this, ((corto_type)corto_int32seq_o)->size)), length);
            corto_uint32 i = 0;
            for (i = 0; i < length; i ++) {
                ((corto_int32seq*)CORTO_OFFSET(_this, ((corto_type)corto_int32seq_o)->size))->buffer[i] = elements[i];
            }
        } else {
            corto_int32seq__resize(_this, length);
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

corto_int32seq* _corto_int32seq__assign(corto_int32seq* _this, corto_uint32 length, int32_t* elements) {
    CORTO_UNUSED(_this);
    corto_int32seq__resize(_this, length);
    corto_uint32 i = 0;
    for (i = 0; i < length; i ++) {
        _this->buffer[i] = elements[i];
    }
    return _this;
}

int64_t* _corto_int64__create(corto_object _parent, const char *_id, int64_t value) {
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

corto_int16 _corto_int64__update(int64_t* _this, int64_t value) {
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

int64_t* _corto_int64__assign(int64_t* _this, int64_t value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

int8_t* _corto_int8__create(corto_object _parent, const char *_id, int8_t value) {
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

corto_int16 _corto_int8__update(int8_t* _this, int8_t value) {
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

int8_t* _corto_int8__assign(int8_t* _this, int8_t value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

corto_interface _corto_interface__create(corto_object _parent, const char *_id, corto_interface base) {
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

corto_int16 _corto_interface__update(corto_interface _this, corto_interface base) {
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

corto_interface _corto_interface__assign(corto_interface _this, corto_interface base) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_interface)_this)->base, base);
    return _this;
}

corto_interfaceseq* _corto_interfaceseq__create(corto_object _parent, const char *_id, corto_uint32 length, corto_interface* elements) {
    corto_interfaceseq* _this;
    _this = (corto_interfaceseq*)corto_declare(_parent, _id, corto_interfaceseq_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_interfaceseq__resize(_this, length);
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

corto_int16 _corto_interfaceseq__update(corto_interfaceseq* _this, corto_uint32 length, corto_interface* elements) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_interfaceseq__resize(((corto_interfaceseq*)CORTO_OFFSET(_this, ((corto_type)corto_interfaceseq_o)->size)), length);
            corto_uint32 i = 0;
            for (i = 0; i < length; i ++) {
                corto_set_ref(&((corto_interfaceseq*)CORTO_OFFSET(_this, ((corto_type)corto_interfaceseq_o)->size))->buffer[i], elements[i]);
            }
        } else {
            corto_interfaceseq__resize(_this, length);
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

corto_interfaceseq* _corto_interfaceseq__assign(corto_interfaceseq* _this, corto_uint32 length, corto_interface* elements) {
    CORTO_UNUSED(_this);
    corto_interfaceseq__resize(_this, length);
    corto_uint32 i = 0;
    for (i = 0; i < length; i ++) {
        corto_set_ref(&_this->buffer[i], elements[i]);
    }
    return _this;
}

corto_interfaceVector* _corto_interfaceVector__create(corto_object _parent, const char *_id, corto_interface interface, corto_objectseq vector) {
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

corto_int16 _corto_interfaceVector__update(corto_interfaceVector* _this, corto_interface interface, corto_objectseq vector) {
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

corto_interfaceVector* _corto_interfaceVector__assign(corto_interfaceVector* _this, corto_interface interface, corto_objectseq vector) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_interfaceVector*)_this)->interface, interface);
    corto_ptr_copy(&((corto_interfaceVector*)_this)->vector, corto_objectseq_o, &vector);
    return _this;
}

corto_interfaceVectorseq* _corto_interfaceVectorseq__create(corto_object _parent, const char *_id, corto_uint32 length, corto_interfaceVector* elements) {
    corto_interfaceVectorseq* _this;
    _this = (corto_interfaceVectorseq*)corto_declare(_parent, _id, corto_interfaceVectorseq_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_interfaceVectorseq__resize(_this, length);
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

corto_int16 _corto_interfaceVectorseq__update(corto_interfaceVectorseq* _this, corto_uint32 length, corto_interfaceVector* elements) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_interfaceVectorseq__resize(((corto_interfaceVectorseq*)CORTO_OFFSET(_this, ((corto_type)corto_interfaceVectorseq_o)->size)), length);
            corto_uint32 i = 0;
            for (i = 0; i < length; i ++) {
                if (&elements[i]) {
                    corto_ptr_copy(&((corto_interfaceVectorseq*)CORTO_OFFSET(_this, ((corto_type)corto_interfaceVectorseq_o)->size))->buffer[i], corto_interfaceVector_o, &elements[i]);
                }
            }
        } else {
            corto_interfaceVectorseq__resize(_this, length);
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

corto_interfaceVectorseq* _corto_interfaceVectorseq__assign(corto_interfaceVectorseq* _this, corto_uint32 length, corto_interfaceVector* elements) {
    CORTO_UNUSED(_this);
    corto_interfaceVectorseq__resize(_this, length);
    corto_uint32 i = 0;
    for (i = 0; i < length; i ++) {
        if (&elements[i]) {
            corto_ptr_copy(&_this->buffer[i], corto_interfaceVector_o, &elements[i]);
        }
    }
    return _this;
}

corto_iterator _corto_iterator__create(corto_object _parent, const char *_id, corto_type element_type) {
    corto_iterator _this;
    _this = (corto_iterator)corto_declare(_parent, _id, corto_iterator_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_ref(&((corto_iterator)_this)->element_type, element_type);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_iterator__update(corto_iterator _this, corto_type element_type) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_set_ref(&((corto_iterator)((corto_iterator)CORTO_OFFSET(_this, ((corto_type)corto_iterator_o)->size)))->element_type, element_type);
        } else {
            corto_set_ref(&((corto_iterator)_this)->element_type, element_type);
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

corto_iterator _corto_iterator__assign(corto_iterator _this, corto_type element_type) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_iterator)_this)->element_type, element_type);
    return _this;
}

corto_leaf _corto_leaf__create(corto_object _parent, const char *_id, corto_interface base, corto_modifierMask base_modifiers, corto_interfaceseq implements, corto_type type, const char * value) {
    corto_leaf _this;
    _this = (corto_leaf)corto_declare(_parent, _id, corto_leaf_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_ref(&((corto_interface)_this)->base, base);
        ((corto_struct)_this)->base_modifiers = base_modifiers;
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

corto_int16 _corto_leaf__update(corto_leaf _this, corto_interface base, corto_modifierMask base_modifiers, corto_interfaceseq implements, corto_type type, const char * value) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_set_ref(&((corto_interface)((corto_leaf)CORTO_OFFSET(_this, ((corto_type)corto_leaf_o)->size)))->base, base);
            ((corto_struct)((corto_leaf)CORTO_OFFSET(_this, ((corto_type)corto_leaf_o)->size)))->base_modifiers = base_modifiers;
            corto_ptr_copy(&((corto_class)((corto_leaf)CORTO_OFFSET(_this, ((corto_type)corto_leaf_o)->size)))->implements, corto_interfaceseq_o, &implements);
            corto_set_ref(&((corto_container)((corto_leaf)CORTO_OFFSET(_this, ((corto_type)corto_leaf_o)->size)))->type, type);
            corto_set_str(&((corto_container)((corto_leaf)CORTO_OFFSET(_this, ((corto_type)corto_leaf_o)->size)))->value, value);
        } else {
            corto_set_ref(&((corto_interface)_this)->base, base);
            ((corto_struct)_this)->base_modifiers = base_modifiers;
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

corto_leaf _corto_leaf__assign(corto_leaf _this, corto_interface base, corto_modifierMask base_modifiers, corto_interfaceseq implements, corto_type type, const char * value) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_interface)_this)->base, base);
    ((corto_struct)_this)->base_modifiers = base_modifiers;
    corto_ptr_copy(&((corto_class)_this)->implements, corto_interfaceseq_o, &implements);
    corto_set_ref(&((corto_container)_this)->type, type);
    corto_set_str(&((corto_container)_this)->value, value);
    return _this;
}

corto_list _corto_list__create(corto_object _parent, const char *_id, corto_type element_type, uint32_t max) {
    corto_list _this;
    _this = (corto_list)corto_declare(_parent, _id, corto_list_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_ref(&((corto_collection)_this)->element_type, element_type);
        ((corto_collection)_this)->max = max;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_list__update(corto_list _this, corto_type element_type, uint32_t max) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_set_ref(&((corto_collection)((corto_list)CORTO_OFFSET(_this, ((corto_type)corto_list_o)->size)))->element_type, element_type);
            ((corto_collection)((corto_list)CORTO_OFFSET(_this, ((corto_type)corto_list_o)->size)))->max = max;
        } else {
            corto_set_ref(&((corto_collection)_this)->element_type, element_type);
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

corto_list _corto_list__assign(corto_list _this, corto_type element_type, uint32_t max) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_collection)_this)->element_type, element_type);
    ((corto_collection)_this)->max = max;
    return _this;
}

corto_map _corto_map__create(corto_object _parent, const char *_id, corto_type key_type, corto_type element_type, uint32_t max) {
    corto_map _this;
    _this = (corto_map)corto_declare(_parent, _id, corto_map_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_ref(&((corto_map)_this)->key_type, key_type);
        corto_set_ref(&((corto_map)_this)->element_type, element_type);
        ((corto_map)_this)->max = max;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_map__update(corto_map _this, corto_type key_type, corto_type element_type, uint32_t max) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_set_ref(&((corto_map)((corto_map)CORTO_OFFSET(_this, ((corto_type)corto_map_o)->size)))->key_type, key_type);
            corto_set_ref(&((corto_map)((corto_map)CORTO_OFFSET(_this, ((corto_type)corto_map_o)->size)))->element_type, element_type);
            ((corto_map)((corto_map)CORTO_OFFSET(_this, ((corto_type)corto_map_o)->size)))->max = max;
        } else {
            corto_set_ref(&((corto_map)_this)->key_type, key_type);
            corto_set_ref(&((corto_map)_this)->element_type, element_type);
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

corto_map _corto_map__assign(corto_map _this, corto_type key_type, corto_type element_type, uint32_t max) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_map)_this)->key_type, key_type);
    corto_set_ref(&((corto_map)_this)->element_type, element_type);
    ((corto_map)_this)->max = max;
    return _this;
}

corto_member _corto_member__create(corto_object _parent, const char *_id, corto_type type, corto_modifierMask modifiers) {
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

corto_int16 _corto_member__update(corto_member _this, corto_type type, corto_modifierMask modifiers) {
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

corto_member _corto_member__assign(corto_member _this, corto_type type, corto_modifierMask modifiers) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_member)_this)->type, type);
    ((corto_member)_this)->modifiers = modifiers;
    return _this;
}

corto_metaprocedure _corto_metaprocedure__create(corto_object _parent, const char *_id, corto_type return_type, bool is_reference, bool referenceOnly, void(*_impl)(void)) {
    corto_metaprocedure _this;
    _this = (corto_metaprocedure)corto_declare(_parent, _id, corto_metaprocedure_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_ref(&((corto_function)_this)->return_type, return_type);
        ((corto_function)_this)->is_reference = is_reference;
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

corto_int16 _corto_metaprocedure__update(corto_metaprocedure _this, corto_type return_type, bool is_reference, bool referenceOnly, void(*_impl)(void)) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_set_ref(&((corto_function)((corto_metaprocedure)CORTO_OFFSET(_this, ((corto_type)corto_metaprocedure_o)->size)))->return_type, return_type);
            ((corto_function)((corto_metaprocedure)CORTO_OFFSET(_this, ((corto_type)corto_metaprocedure_o)->size)))->is_reference = is_reference;
            ((corto_metaprocedure)((corto_metaprocedure)CORTO_OFFSET(_this, ((corto_type)corto_metaprocedure_o)->size)))->referenceOnly = referenceOnly;
            corto_function(((corto_metaprocedure)CORTO_OFFSET(_this, ((corto_type)corto_metaprocedure_o)->size)))->kind = CORTO_PROCEDURE_CDECL;
            corto_function(((corto_metaprocedure)CORTO_OFFSET(_this, ((corto_type)corto_metaprocedure_o)->size)))->fptr = (corto_word)_impl;
        } else {
            corto_set_ref(&((corto_function)_this)->return_type, return_type);
            ((corto_function)_this)->is_reference = is_reference;
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

corto_metaprocedure _corto_metaprocedure__assign(corto_metaprocedure _this, corto_type return_type, bool is_reference, bool referenceOnly, void(*_impl)(void)) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_function)_this)->return_type, return_type);
    ((corto_function)_this)->is_reference = is_reference;
    ((corto_metaprocedure)_this)->referenceOnly = referenceOnly;
    corto_function(_this)->kind = CORTO_PROCEDURE_CDECL;
    corto_function(_this)->fptr = (corto_word)_impl;
    return _this;
}

corto_method _corto_method__create(corto_object _parent, const char *_id, corto_type return_type, bool is_reference, void(*_impl)(void)) {
    corto_method _this;
    _this = (corto_method)corto_declare(_parent, _id, corto_method_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_ref(&((corto_function)_this)->return_type, return_type);
        ((corto_function)_this)->is_reference = is_reference;
        corto_function(_this)->kind = CORTO_PROCEDURE_CDECL;
        corto_function(_this)->fptr = (corto_word)_impl;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_method__update(corto_method _this, corto_type return_type, bool is_reference, void(*_impl)(void)) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_set_ref(&((corto_function)((corto_method)CORTO_OFFSET(_this, ((corto_type)corto_method_o)->size)))->return_type, return_type);
            ((corto_function)((corto_method)CORTO_OFFSET(_this, ((corto_type)corto_method_o)->size)))->is_reference = is_reference;
            corto_function(((corto_method)CORTO_OFFSET(_this, ((corto_type)corto_method_o)->size)))->kind = CORTO_PROCEDURE_CDECL;
            corto_function(((corto_method)CORTO_OFFSET(_this, ((corto_type)corto_method_o)->size)))->fptr = (corto_word)_impl;
        } else {
            corto_set_ref(&((corto_function)_this)->return_type, return_type);
            ((corto_function)_this)->is_reference = is_reference;
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

corto_method _corto_method__assign(corto_method _this, corto_type return_type, bool is_reference, void(*_impl)(void)) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_function)_this)->return_type, return_type);
    ((corto_function)_this)->is_reference = is_reference;
    corto_function(_this)->kind = CORTO_PROCEDURE_CDECL;
    corto_function(_this)->fptr = (corto_word)_impl;
    return _this;
}

corto_modifierMask* _corto_modifierMask__create(corto_object _parent, const char *_id, corto_modifierMask value) {
    corto_modifierMask* _this;
    _this = (corto_modifierMask*)corto_declare(_parent, _id, corto_modifierMask_o);
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

corto_int16 _corto_modifierMask__update(corto_modifierMask* _this, corto_modifierMask value) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            *((corto_modifierMask*)CORTO_OFFSET(_this, ((corto_type)corto_modifierMask_o)->size)) = value;
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

corto_modifierMask* _corto_modifierMask__assign(corto_modifierMask* _this, corto_modifierMask value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

corto_name_action* _corto_name_action__create(corto_object _parent, const char *_id, corto_object instance, corto_function procedure) {
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

corto_int16 _corto_name_action__update(corto_name_action* _this, corto_object instance, corto_function procedure) {
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

corto_name_action* _corto_name_action__assign(corto_name_action* _this, corto_object instance, corto_function procedure) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_delegatedata*)_this)->instance, instance);
    corto_set_ref(&((corto_delegatedata*)_this)->procedure, procedure);
    return _this;
}

corto_int16 corto_name_action__call(corto_name_action *_delegate, corto_string* _result) {
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

corto_int16 corto_name_action__init_c(corto_name_action *d, corto_string ___ (*callback)(void)) {
    d->super.instance = NULL;
    d->super.procedure = corto_declare(NULL, NULL, corto_function_o);
    d->super.procedure->kind = CORTO_PROCEDURE_CDECL;
    corto_set_ref(&d->super.procedure->return_type, corto_string_o);
    corto_function_parseParamString(d->super.procedure, "()");
    d->super.procedure->fptr = (corto_word)callback;
    corto_define(d->super.procedure);
    return 0;
}

corto_int16 corto_name_action_init_c_instance(corto_name_action *d, corto_object instance, corto_string ___ (*callback)(corto_object)) {
    d->super.instance = instance;
    corto_claim(instance);
    d->super.procedure = corto_declare(NULL, NULL, corto_function_o);
    d->super.procedure->kind = CORTO_PROCEDURE_CDECL;
    corto_set_ref(&d->super.procedure->return_type, corto_string_o);
    corto_function_parseParamString(d->super.procedure, "(object instance)");
    d->super.procedure->fptr = (corto_word)callback;
    corto_define(d->super.procedure);
    return 0;
}

corto_object _corto_object__create(corto_object _parent, const char *_id, corto_object value) {
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

corto_int16 _corto_object__update(corto_object _this, corto_object value) {
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

corto_object _corto_object__assign(corto_object _this, corto_object value) {
    CORTO_UNUSED(_this);
    corto_set_ref(_this, value);
    return _this;
}

corto_objectlist* _corto_objectlist__create(corto_object _parent, const char *_id, corto_uint32 length, corto_object* elements) {
    corto_objectlist* _this;
    _this = (corto_objectlist*)corto_declare(_parent, _id, corto_objectlist_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_uint32 i = 0;
        corto_objectlist__clear(*_this);
        for (i = 0; i < length; i ++) {
            corto_objectlist__append(*_this, elements[i]);
        }
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_objectlist__update(corto_objectlist* _this, corto_uint32 length, corto_object* elements) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_uint32 i = 0;
            corto_objectlist__clear(*((corto_objectlist*)CORTO_OFFSET(_this, ((corto_type)corto_objectlist_o)->size)));
            for (i = 0; i < length; i ++) {
                corto_objectlist__append(*((corto_objectlist*)CORTO_OFFSET(_this, ((corto_type)corto_objectlist_o)->size)), elements[i]);
            }
        } else {
            corto_uint32 i = 0;
            corto_objectlist__clear(*_this);
            for (i = 0; i < length; i ++) {
                corto_objectlist__append(*_this, elements[i]);
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

corto_objectlist* _corto_objectlist__assign(corto_objectlist* _this, corto_uint32 length, corto_object* elements) {
    CORTO_UNUSED(_this);
    corto_uint32 i = 0;
    corto_objectlist__clear(*_this);
    for (i = 0; i < length; i ++) {
        corto_objectlist__append(*_this, elements[i]);
    }
    return _this;
}

corto_objectseq* _corto_objectseq__create(corto_object _parent, const char *_id, corto_uint32 length, corto_object* elements) {
    corto_objectseq* _this;
    _this = (corto_objectseq*)corto_declare(_parent, _id, corto_objectseq_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_objectseq__resize(_this, length);
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

corto_int16 _corto_objectseq__update(corto_objectseq* _this, corto_uint32 length, corto_object* elements) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_objectseq__resize(((corto_objectseq*)CORTO_OFFSET(_this, ((corto_type)corto_objectseq_o)->size)), length);
            corto_uint32 i = 0;
            for (i = 0; i < length; i ++) {
                corto_set_ref(&((corto_objectseq*)CORTO_OFFSET(_this, ((corto_type)corto_objectseq_o)->size))->buffer[i], elements[i]);
            }
        } else {
            corto_objectseq__resize(_this, length);
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

corto_objectseq* _corto_objectseq__assign(corto_objectseq* _this, corto_uint32 length, corto_object* elements) {
    CORTO_UNUSED(_this);
    corto_objectseq__resize(_this, length);
    corto_uint32 i = 0;
    for (i = 0; i < length; i ++) {
        corto_set_ref(&_this->buffer[i], elements[i]);
    }
    return _this;
}

uint8_t* _corto_octet__create(corto_object _parent, const char *_id, uint8_t value) {
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

corto_int16 _corto_octet__update(uint8_t* _this, uint8_t value) {
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

uint8_t* _corto_octet__assign(uint8_t* _this, uint8_t value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

corto_overridable _corto_overridable__create(corto_object _parent, const char *_id, corto_type return_type, bool is_reference, void(*_impl)(void)) {
    corto_overridable _this;
    _this = (corto_overridable)corto_declare(_parent, _id, corto_overridable_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_ref(&((corto_function)_this)->return_type, return_type);
        ((corto_function)_this)->is_reference = is_reference;
        corto_function(_this)->kind = CORTO_PROCEDURE_CDECL;
        corto_function(_this)->fptr = (corto_word)_impl;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_overridable__update(corto_overridable _this, corto_type return_type, bool is_reference, void(*_impl)(void)) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_set_ref(&((corto_function)((corto_overridable)CORTO_OFFSET(_this, ((corto_type)corto_overridable_o)->size)))->return_type, return_type);
            ((corto_function)((corto_overridable)CORTO_OFFSET(_this, ((corto_type)corto_overridable_o)->size)))->is_reference = is_reference;
            corto_function(((corto_overridable)CORTO_OFFSET(_this, ((corto_type)corto_overridable_o)->size)))->kind = CORTO_PROCEDURE_CDECL;
            corto_function(((corto_overridable)CORTO_OFFSET(_this, ((corto_type)corto_overridable_o)->size)))->fptr = (corto_word)_impl;
        } else {
            corto_set_ref(&((corto_function)_this)->return_type, return_type);
            ((corto_function)_this)->is_reference = is_reference;
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

corto_overridable _corto_overridable__assign(corto_overridable _this, corto_type return_type, bool is_reference, void(*_impl)(void)) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_function)_this)->return_type, return_type);
    ((corto_function)_this)->is_reference = is_reference;
    corto_function(_this)->kind = CORTO_PROCEDURE_CDECL;
    corto_function(_this)->fptr = (corto_word)_impl;
    return _this;
}

corto_override _corto_override__create(corto_object _parent, const char *_id, corto_type return_type, bool is_reference, void(*_impl)(void)) {
    corto_override _this;
    _this = (corto_override)corto_declare(_parent, _id, corto_override_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_ref(&((corto_function)_this)->return_type, return_type);
        ((corto_function)_this)->is_reference = is_reference;
        corto_function(_this)->kind = CORTO_PROCEDURE_CDECL;
        corto_function(_this)->fptr = (corto_word)_impl;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_override__update(corto_override _this, corto_type return_type, bool is_reference, void(*_impl)(void)) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_set_ref(&((corto_function)((corto_override)CORTO_OFFSET(_this, ((corto_type)corto_override_o)->size)))->return_type, return_type);
            ((corto_function)((corto_override)CORTO_OFFSET(_this, ((corto_type)corto_override_o)->size)))->is_reference = is_reference;
            corto_function(((corto_override)CORTO_OFFSET(_this, ((corto_type)corto_override_o)->size)))->kind = CORTO_PROCEDURE_CDECL;
            corto_function(((corto_override)CORTO_OFFSET(_this, ((corto_type)corto_override_o)->size)))->fptr = (corto_word)_impl;
        } else {
            corto_set_ref(&((corto_function)_this)->return_type, return_type);
            ((corto_function)_this)->is_reference = is_reference;
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

corto_override _corto_override__assign(corto_override _this, corto_type return_type, bool is_reference, void(*_impl)(void)) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_function)_this)->return_type, return_type);
    ((corto_function)_this)->is_reference = is_reference;
    corto_function(_this)->kind = CORTO_PROCEDURE_CDECL;
    corto_function(_this)->fptr = (corto_word)_impl;
    return _this;
}

corto_package _corto_package__create(corto_object _parent, const char *_id) {
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

corto_int16 _corto_package__update(corto_package _this) {
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

corto_package _corto_package__assign(corto_package _this) {
    CORTO_UNUSED(_this);
    return _this;
}

corto_parameter* _corto_parameter__create(corto_object _parent, const char *_id, const char * name, corto_type type, corto_inout inout, bool is_reference) {
    corto_parameter* _this;
    _this = (corto_parameter*)corto_declare(_parent, _id, corto_parameter_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_str(&((corto_parameter*)_this)->name, name);
        corto_set_ref(&((corto_parameter*)_this)->type, type);
        ((corto_parameter*)_this)->inout = inout;
        ((corto_parameter*)_this)->is_reference = is_reference;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_parameter__update(corto_parameter* _this, const char * name, corto_type type, corto_inout inout, bool is_reference) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_set_str(&((corto_parameter*)((corto_parameter*)CORTO_OFFSET(_this, ((corto_type)corto_parameter_o)->size)))->name, name);
            corto_set_ref(&((corto_parameter*)((corto_parameter*)CORTO_OFFSET(_this, ((corto_type)corto_parameter_o)->size)))->type, type);
            ((corto_parameter*)((corto_parameter*)CORTO_OFFSET(_this, ((corto_type)corto_parameter_o)->size)))->inout = inout;
            ((corto_parameter*)((corto_parameter*)CORTO_OFFSET(_this, ((corto_type)corto_parameter_o)->size)))->is_reference = is_reference;
        } else {
            corto_set_str(&((corto_parameter*)_this)->name, name);
            corto_set_ref(&((corto_parameter*)_this)->type, type);
            ((corto_parameter*)_this)->inout = inout;
            ((corto_parameter*)_this)->is_reference = is_reference;
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

corto_parameter* _corto_parameter__assign(corto_parameter* _this, const char * name, corto_type type, corto_inout inout, bool is_reference) {
    CORTO_UNUSED(_this);
    corto_set_str(&((corto_parameter*)_this)->name, name);
    corto_set_ref(&((corto_parameter*)_this)->type, type);
    ((corto_parameter*)_this)->inout = inout;
    ((corto_parameter*)_this)->is_reference = is_reference;
    return _this;
}

corto_parameterseq* _corto_parameterseq__create(corto_object _parent, const char *_id, corto_uint32 length, corto_parameter* elements) {
    corto_parameterseq* _this;
    _this = (corto_parameterseq*)corto_declare(_parent, _id, corto_parameterseq_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_parameterseq__resize(_this, length);
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

corto_int16 _corto_parameterseq__update(corto_parameterseq* _this, corto_uint32 length, corto_parameter* elements) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_parameterseq__resize(((corto_parameterseq*)CORTO_OFFSET(_this, ((corto_type)corto_parameterseq_o)->size)), length);
            corto_uint32 i = 0;
            for (i = 0; i < length; i ++) {
                if (&elements[i]) {
                    corto_ptr_copy(&((corto_parameterseq*)CORTO_OFFSET(_this, ((corto_type)corto_parameterseq_o)->size))->buffer[i], corto_parameter_o, &elements[i]);
                }
            }
        } else {
            corto_parameterseq__resize(_this, length);
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

corto_parameterseq* _corto_parameterseq__assign(corto_parameterseq* _this, corto_uint32 length, corto_parameter* elements) {
    CORTO_UNUSED(_this);
    corto_parameterseq__resize(_this, length);
    corto_uint32 i = 0;
    for (i = 0; i < length; i ++) {
        if (&elements[i]) {
            corto_ptr_copy(&_this->buffer[i], corto_parameter_o, &elements[i]);
        }
    }
    return _this;
}

corto_post_action* _corto_post_action__create(corto_object _parent, const char *_id, corto_object instance, corto_function procedure) {
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

corto_int16 _corto_post_action__update(corto_post_action* _this, corto_object instance, corto_function procedure) {
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

corto_post_action* _corto_post_action__assign(corto_post_action* _this, corto_object instance, corto_function procedure) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_delegatedata*)_this)->instance, instance);
    corto_set_ref(&((corto_delegatedata*)_this)->procedure, procedure);
    return _this;
}

corto_int16 corto_post_action__call(corto_post_action *_delegate) {
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

corto_int16 corto_post_action__init_c(corto_post_action *d, corto_void ___ (*callback)(void)) {
    d->super.instance = NULL;
    d->super.procedure = corto_declare(NULL, NULL, corto_function_o);
    d->super.procedure->kind = CORTO_PROCEDURE_CDECL;
    corto_set_ref(&d->super.procedure->return_type, corto_void_o);
    corto_function_parseParamString(d->super.procedure, "()");
    d->super.procedure->fptr = (corto_word)callback;
    corto_define(d->super.procedure);
    return 0;
}

corto_int16 corto_post_action_init_c_instance(corto_post_action *d, corto_object instance, corto_void ___ (*callback)(corto_object)) {
    d->super.instance = instance;
    corto_claim(instance);
    d->super.procedure = corto_declare(NULL, NULL, corto_function_o);
    d->super.procedure->kind = CORTO_PROCEDURE_CDECL;
    corto_set_ref(&d->super.procedure->return_type, corto_void_o);
    corto_function_parseParamString(d->super.procedure, "(object instance)");
    d->super.procedure->fptr = (corto_word)callback;
    corto_define(d->super.procedure);
    return 0;
}

corto_pre_action* _corto_pre_action__create(corto_object _parent, const char *_id, corto_object instance, corto_function procedure) {
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

corto_int16 _corto_pre_action__update(corto_pre_action* _this, corto_object instance, corto_function procedure) {
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

corto_pre_action* _corto_pre_action__assign(corto_pre_action* _this, corto_object instance, corto_function procedure) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_delegatedata*)_this)->instance, instance);
    corto_set_ref(&((corto_delegatedata*)_this)->procedure, procedure);
    return _this;
}

corto_int16 corto_pre_action__call(corto_pre_action *_delegate, corto_int16* _result) {
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

corto_int16 corto_pre_action__init_c(corto_pre_action *d, corto_int16 ___ (*callback)(void)) {
    d->super.instance = NULL;
    d->super.procedure = corto_declare(NULL, NULL, corto_function_o);
    d->super.procedure->kind = CORTO_PROCEDURE_CDECL;
    corto_set_ref(&d->super.procedure->return_type, corto_int16_o);
    corto_function_parseParamString(d->super.procedure, "()");
    d->super.procedure->fptr = (corto_word)callback;
    corto_define(d->super.procedure);
    return 0;
}

corto_int16 corto_pre_action_init_c_instance(corto_pre_action *d, corto_object instance, corto_int16 ___ (*callback)(corto_object)) {
    d->super.instance = instance;
    corto_claim(instance);
    d->super.procedure = corto_declare(NULL, NULL, corto_function_o);
    d->super.procedure->kind = CORTO_PROCEDURE_CDECL;
    corto_set_ref(&d->super.procedure->return_type, corto_int16_o);
    corto_function_parseParamString(d->super.procedure, "(object instance)");
    d->super.procedure->fptr = (corto_word)callback;
    corto_define(d->super.procedure);
    return 0;
}

corto_primitive _corto_primitive__create(corto_object _parent, const char *_id, corto_width width) {
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

corto_int16 _corto_primitive__update(corto_primitive _this, corto_width width) {
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

corto_primitive _corto_primitive__assign(corto_primitive _this, corto_width width) {
    CORTO_UNUSED(_this);
    ((corto_primitive)_this)->width = width;
    return _this;
}

corto_primitiveKind* _corto_primitiveKind__create(corto_object _parent, const char *_id, corto_primitiveKind value) {
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

corto_int16 _corto_primitiveKind__update(corto_primitiveKind* _this, corto_primitiveKind value) {
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

corto_primitiveKind* _corto_primitiveKind__assign(corto_primitiveKind* _this, corto_primitiveKind value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

corto_procedure _corto_procedure__create(corto_object _parent, const char *_id, bool has_this, corto_type this_type) {
    corto_procedure _this;
    _this = (corto_procedure)corto_declare(_parent, _id, corto_procedure_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        ((corto_procedure)_this)->has_this = has_this;
        corto_set_ref(&((corto_procedure)_this)->this_type, this_type);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_procedure__update(corto_procedure _this, bool has_this, corto_type this_type) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            ((corto_procedure)((corto_procedure)CORTO_OFFSET(_this, ((corto_type)corto_procedure_o)->size)))->has_this = has_this;
            corto_set_ref(&((corto_procedure)((corto_procedure)CORTO_OFFSET(_this, ((corto_type)corto_procedure_o)->size)))->this_type, this_type);
        } else {
            ((corto_procedure)_this)->has_this = has_this;
            corto_set_ref(&((corto_procedure)_this)->this_type, this_type);
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

corto_procedure _corto_procedure__assign(corto_procedure _this, bool has_this, corto_type this_type) {
    CORTO_UNUSED(_this);
    ((corto_procedure)_this)->has_this = has_this;
    corto_set_ref(&((corto_procedure)_this)->this_type, this_type);
    return _this;
}

corto_quantity _corto_quantity__create(corto_object _parent, const char *_id, corto_unit base_unit) {
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

corto_int16 _corto_quantity__update(corto_quantity _this, corto_unit base_unit) {
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

corto_quantity _corto_quantity__assign(corto_quantity _this, corto_unit base_unit) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_quantity)_this)->base_unit, base_unit);
    return _this;
}

corto_ref_kind* _corto_ref_kind__create(corto_object _parent, const char *_id, corto_ref_kind value) {
    corto_ref_kind* _this;
    _this = (corto_ref_kind*)corto_declare(_parent, _id, corto_ref_kind_o);
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

corto_int16 _corto_ref_kind__update(corto_ref_kind* _this, corto_ref_kind value) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            *((corto_ref_kind*)CORTO_OFFSET(_this, ((corto_type)corto_ref_kind_o)->size)) = value;
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

corto_ref_kind* _corto_ref_kind__assign(corto_ref_kind* _this, corto_ref_kind value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

corto_sequence _corto_sequence__create(corto_object _parent, const char *_id, corto_type element_type, uint32_t max) {
    corto_sequence _this;
    _this = (corto_sequence)corto_declare(_parent, _id, corto_sequence_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_ref(&((corto_collection)_this)->element_type, element_type);
        ((corto_collection)_this)->max = max;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_sequence__update(corto_sequence _this, corto_type element_type, uint32_t max) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_set_ref(&((corto_collection)((corto_sequence)CORTO_OFFSET(_this, ((corto_type)corto_sequence_o)->size)))->element_type, element_type);
            ((corto_collection)((corto_sequence)CORTO_OFFSET(_this, ((corto_type)corto_sequence_o)->size)))->max = max;
        } else {
            corto_set_ref(&((corto_collection)_this)->element_type, element_type);
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

corto_sequence _corto_sequence__assign(corto_sequence _this, corto_type element_type, uint32_t max) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_collection)_this)->element_type, element_type);
    ((corto_collection)_this)->max = max;
    return _this;
}

corto_state* _corto_state__create(corto_object _parent, const char *_id, corto_state value) {
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

corto_int16 _corto_state__update(corto_state* _this, corto_state value) {
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

corto_state* _corto_state__assign(corto_state* _this, corto_state value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

corto_string* _corto_string__create(corto_object _parent, const char *_id, corto_string value) {
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

corto_int16 _corto_string__update(corto_string* _this, corto_string value) {
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

corto_string* _corto_string__assign(corto_string* _this, corto_string value) {
    CORTO_UNUSED(_this);
    corto_set_str(_this, value);
    return _this;
}

corto_stringlist* _corto_stringlist__create(corto_object _parent, const char *_id, corto_uint32 length, corto_string* elements) {
    corto_stringlist* _this;
    _this = (corto_stringlist*)corto_declare(_parent, _id, corto_stringlist_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_uint32 i = 0;
        corto_stringlist__clear(*_this);
        for (i = 0; i < length; i ++) {
            corto_stringlist__append(*_this, elements[i]);
        }
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_stringlist__update(corto_stringlist* _this, corto_uint32 length, corto_string* elements) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_uint32 i = 0;
            corto_stringlist__clear(*((corto_stringlist*)CORTO_OFFSET(_this, ((corto_type)corto_stringlist_o)->size)));
            for (i = 0; i < length; i ++) {
                corto_stringlist__append(*((corto_stringlist*)CORTO_OFFSET(_this, ((corto_type)corto_stringlist_o)->size)), elements[i]);
            }
        } else {
            corto_uint32 i = 0;
            corto_stringlist__clear(*_this);
            for (i = 0; i < length; i ++) {
                corto_stringlist__append(*_this, elements[i]);
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

corto_stringlist* _corto_stringlist__assign(corto_stringlist* _this, corto_uint32 length, corto_string* elements) {
    CORTO_UNUSED(_this);
    corto_uint32 i = 0;
    corto_stringlist__clear(*_this);
    for (i = 0; i < length; i ++) {
        corto_stringlist__append(*_this, elements[i]);
    }
    return _this;
}

corto_stringseq* _corto_stringseq__create(corto_object _parent, const char *_id, corto_uint32 length, corto_string* elements) {
    corto_stringseq* _this;
    _this = (corto_stringseq*)corto_declare(_parent, _id, corto_stringseq_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_stringseq__resize(_this, length);
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

corto_int16 _corto_stringseq__update(corto_stringseq* _this, corto_uint32 length, corto_string* elements) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_stringseq__resize(((corto_stringseq*)CORTO_OFFSET(_this, ((corto_type)corto_stringseq_o)->size)), length);
            corto_uint32 i = 0;
            for (i = 0; i < length; i ++) {
                corto_set_str(&((corto_stringseq*)CORTO_OFFSET(_this, ((corto_type)corto_stringseq_o)->size))->buffer[i], elements[i]);
            }
        } else {
            corto_stringseq__resize(_this, length);
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

corto_stringseq* _corto_stringseq__assign(corto_stringseq* _this, corto_uint32 length, corto_string* elements) {
    CORTO_UNUSED(_this);
    corto_stringseq__resize(_this, length);
    corto_uint32 i = 0;
    for (i = 0; i < length; i ++) {
        corto_set_str(&_this->buffer[i], elements[i]);
    }
    return _this;
}

corto_struct _corto_struct__create(corto_object _parent, const char *_id, corto_interface base, corto_modifierMask base_modifiers) {
    corto_struct _this;
    _this = (corto_struct)corto_declare(_parent, _id, corto_struct_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_ref(&((corto_interface)_this)->base, base);
        ((corto_struct)_this)->base_modifiers = base_modifiers;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_struct__update(corto_struct _this, corto_interface base, corto_modifierMask base_modifiers) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_set_ref(&((corto_interface)((corto_struct)CORTO_OFFSET(_this, ((corto_type)corto_struct_o)->size)))->base, base);
            ((corto_struct)((corto_struct)CORTO_OFFSET(_this, ((corto_type)corto_struct_o)->size)))->base_modifiers = base_modifiers;
        } else {
            corto_set_ref(&((corto_interface)_this)->base, base);
            ((corto_struct)_this)->base_modifiers = base_modifiers;
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

corto_struct _corto_struct__assign(corto_struct _this, corto_interface base, corto_modifierMask base_modifiers) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_interface)_this)->base, base);
    ((corto_struct)_this)->base_modifiers = base_modifiers;
    return _this;
}

corto_table _corto_table__create(corto_object _parent, const char *_id, corto_interface base, corto_modifierMask base_modifiers, corto_interfaceseq implements, corto_type type, const char * value) {
    corto_table _this;
    _this = (corto_table)corto_declare(_parent, _id, corto_table_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_ref(&((corto_interface)_this)->base, base);
        ((corto_struct)_this)->base_modifiers = base_modifiers;
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

corto_int16 _corto_table__update(corto_table _this, corto_interface base, corto_modifierMask base_modifiers, corto_interfaceseq implements, corto_type type, const char * value) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_set_ref(&((corto_interface)((corto_table)CORTO_OFFSET(_this, ((corto_type)corto_table_o)->size)))->base, base);
            ((corto_struct)((corto_table)CORTO_OFFSET(_this, ((corto_type)corto_table_o)->size)))->base_modifiers = base_modifiers;
            corto_ptr_copy(&((corto_class)((corto_table)CORTO_OFFSET(_this, ((corto_type)corto_table_o)->size)))->implements, corto_interfaceseq_o, &implements);
            corto_set_ref(&((corto_container)((corto_table)CORTO_OFFSET(_this, ((corto_type)corto_table_o)->size)))->type, type);
            corto_set_str(&((corto_container)((corto_table)CORTO_OFFSET(_this, ((corto_type)corto_table_o)->size)))->value, value);
        } else {
            corto_set_ref(&((corto_interface)_this)->base, base);
            ((corto_struct)_this)->base_modifiers = base_modifiers;
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

corto_table _corto_table__assign(corto_table _this, corto_interface base, corto_modifierMask base_modifiers, corto_interfaceseq implements, corto_type type, const char * value) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_interface)_this)->base, base);
    ((corto_struct)_this)->base_modifiers = base_modifiers;
    corto_ptr_copy(&((corto_class)_this)->implements, corto_interfaceseq_o, &implements);
    corto_set_ref(&((corto_container)_this)->type, type);
    corto_set_str(&((corto_container)_this)->value, value);
    return _this;
}

corto_tableinstance _corto_tableinstance__create(corto_object _parent, const char *_id, corto_type type) {
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

corto_int16 _corto_tableinstance__update(corto_tableinstance _this, corto_type type) {
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

corto_tableinstance _corto_tableinstance__assign(corto_tableinstance _this, corto_type type) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_tableinstance)_this)->type, type);
    return _this;
}

corto_tag _corto_tag__create(corto_object _parent, const char *_id) {
    corto_tag _this;
    _this = (corto_tag)corto_declare(_parent, _id, corto_tag_o);
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

corto_int16 _corto_tag__update(corto_tag _this) {
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

corto_tag _corto_tag__assign(corto_tag _this) {
    CORTO_UNUSED(_this);
    return _this;
}

corto_taglist* _corto_taglist__create(corto_object _parent, const char *_id, corto_uint32 length, corto_tag* elements) {
    corto_taglist* _this;
    _this = (corto_taglist*)corto_declare(_parent, _id, corto_taglist_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_uint32 i = 0;
        corto_taglist__clear(*_this);
        for (i = 0; i < length; i ++) {
            corto_taglist__append(*_this, elements[i]);
        }
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_taglist__update(corto_taglist* _this, corto_uint32 length, corto_tag* elements) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_uint32 i = 0;
            corto_taglist__clear(*((corto_taglist*)CORTO_OFFSET(_this, ((corto_type)corto_taglist_o)->size)));
            for (i = 0; i < length; i ++) {
                corto_taglist__append(*((corto_taglist*)CORTO_OFFSET(_this, ((corto_type)corto_taglist_o)->size)), elements[i]);
            }
        } else {
            corto_uint32 i = 0;
            corto_taglist__clear(*_this);
            for (i = 0; i < length; i ++) {
                corto_taglist__append(*_this, elements[i]);
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

corto_taglist* _corto_taglist__assign(corto_taglist* _this, corto_uint32 length, corto_tag* elements) {
    CORTO_UNUSED(_this);
    corto_uint32 i = 0;
    corto_taglist__clear(*_this);
    for (i = 0; i < length; i ++) {
        corto_taglist__append(*_this, elements[i]);
    }
    return _this;
}

corto_target _corto_target__create(corto_object _parent, const char *_id, corto_type type) {
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

corto_int16 _corto_target__update(corto_target _this, corto_type type) {
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

corto_target _corto_target__assign(corto_target _this, corto_type type) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_target)_this)->type, type);
    return _this;
}

corto_text _corto_text__create(corto_object _parent, const char *_id, corto_width char_width, uint64_t length) {
    corto_text _this;
    _this = (corto_text)corto_declare(_parent, _id, corto_text_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        ((corto_text)_this)->char_width = char_width;
        ((corto_text)_this)->length = length;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_text__update(corto_text _this, corto_width char_width, uint64_t length) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            ((corto_text)((corto_text)CORTO_OFFSET(_this, ((corto_type)corto_text_o)->size)))->char_width = char_width;
            ((corto_text)((corto_text)CORTO_OFFSET(_this, ((corto_type)corto_text_o)->size)))->length = length;
        } else {
            ((corto_text)_this)->char_width = char_width;
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

corto_text _corto_text__assign(corto_text _this, corto_width char_width, uint64_t length) {
    CORTO_UNUSED(_this);
    ((corto_text)_this)->char_width = char_width;
    ((corto_text)_this)->length = length;
    return _this;
}

corto_tool _corto_tool__create(corto_object _parent, const char *_id) {
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

corto_int16 _corto_tool__update(corto_tool _this) {
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

corto_tool _corto_tool__assign(corto_tool _this) {
    CORTO_UNUSED(_this);
    return _this;
}

corto_type _corto_type__create(corto_object _parent, const char *_id, bool reference) {
    corto_type _this;
    _this = (corto_type)corto_declare(_parent, _id, corto_type_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        ((corto_type)_this)->reference = reference;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_type__update(corto_type _this, bool reference) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            ((corto_type)((corto_type)CORTO_OFFSET(_this, ((corto_type)corto_type_o)->size)))->reference = reference;
        } else {
            ((corto_type)_this)->reference = reference;
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

corto_type _corto_type__assign(corto_type _this, bool reference) {
    CORTO_UNUSED(_this);
    ((corto_type)_this)->reference = reference;
    return _this;
}

corto_typeKind* _corto_typeKind__create(corto_object _parent, const char *_id, corto_typeKind value) {
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

corto_int16 _corto_typeKind__update(corto_typeKind* _this, corto_typeKind value) {
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

corto_typeKind* _corto_typeKind__assign(corto_typeKind* _this, corto_typeKind value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

corto_uint _corto_uint__create(corto_object _parent, const char *_id, corto_width width, uint64_t min, uint64_t max) {
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

corto_int16 _corto_uint__update(corto_uint _this, corto_width width, uint64_t min, uint64_t max) {
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

corto_uint _corto_uint__assign(corto_uint _this, corto_width width, uint64_t min, uint64_t max) {
    CORTO_UNUSED(_this);
    ((corto_primitive)_this)->width = width;
    ((corto_uint)_this)->min = min;
    ((corto_uint)_this)->max = max;
    return _this;
}

uint16_t* _corto_uint16__create(corto_object _parent, const char *_id, uint16_t value) {
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

corto_int16 _corto_uint16__update(uint16_t* _this, uint16_t value) {
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

uint16_t* _corto_uint16__assign(uint16_t* _this, uint16_t value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

uint32_t* _corto_uint32__create(corto_object _parent, const char *_id, uint32_t value) {
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

corto_int16 _corto_uint32__update(uint32_t* _this, uint32_t value) {
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

uint32_t* _corto_uint32__assign(uint32_t* _this, uint32_t value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

uint64_t* _corto_uint64__create(corto_object _parent, const char *_id, uint64_t value) {
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

corto_int16 _corto_uint64__update(uint64_t* _this, uint64_t value) {
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

uint64_t* _corto_uint64__assign(uint64_t* _this, uint64_t value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

uint8_t* _corto_uint8__create(corto_object _parent, const char *_id, uint8_t value) {
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

corto_int16 _corto_uint8__update(uint8_t* _this, uint8_t value) {
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

uint8_t* _corto_uint8__assign(uint8_t* _this, uint8_t value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

corto_union _corto_union__create(corto_object _parent, const char *_id, corto_type discriminator) {
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

corto_int16 _corto_union__update(corto_union _this, corto_type discriminator) {
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

corto_union _corto_union__assign(corto_union _this, corto_type discriminator) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_union)_this)->discriminator, discriminator);
    return _this;
}

corto_unit _corto_unit__create(corto_object _parent, const char *_id, corto_quantity quantity, const char * symbol, const char * conversion, corto_type type) {
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

corto_int16 _corto_unit__update(corto_unit _this, corto_quantity quantity, const char * symbol, const char * conversion, corto_type type) {
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

corto_unit _corto_unit__assign(corto_unit _this, corto_quantity quantity, const char * symbol, const char * conversion, corto_type type) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_unit)_this)->quantity, quantity);
    corto_set_str(&((corto_unit)_this)->symbol, symbol);
    corto_set_str(&((corto_unit)_this)->conversion, conversion);
    corto_set_ref(&((corto_unit)_this)->type, type);
    return _this;
}

void* _corto_unknown__create(corto_object _parent, const char *_id) {
    void* _this;
    _this = (void*)corto_declare(_parent, _id, corto_unknown_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
    }
    return _this;
}

corto_int16 _corto_unknown__update(void* _this) {
    CORTO_UNUSED(_this);
    return corto_update(_this);
}

corto_verbatim _corto_verbatim__create(corto_object _parent, const char *_id, const char * format) {
    corto_verbatim _this;
    _this = (corto_verbatim)corto_declare(_parent, _id, corto_verbatim_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_str(&((corto_verbatim)_this)->format, format);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_verbatim__update(corto_verbatim _this, const char * format) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_set_str(&((corto_verbatim)((corto_verbatim)CORTO_OFFSET(_this, ((corto_type)corto_verbatim_o)->size)))->format, format);
        } else {
            corto_set_str(&((corto_verbatim)_this)->format, format);
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

corto_verbatim _corto_verbatim__assign(corto_verbatim _this, const char * format) {
    CORTO_UNUSED(_this);
    corto_set_str(&((corto_verbatim)_this)->format, format);
    return _this;
}

void* _corto_void__create(corto_object _parent, const char *_id) {
    void* _this;
    _this = (void*)corto_declare(_parent, _id, corto_void_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
    }
    return _this;
}

corto_int16 _corto_void__update(void* _this) {
    CORTO_UNUSED(_this);
    return corto_update(_this);
}

corto_width* _corto_width__create(corto_object _parent, const char *_id, corto_width value) {
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

corto_int16 _corto_width__update(corto_width* _this, corto_width value) {
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

corto_width* _corto_width__assign(corto_width* _this, corto_width value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

uintptr_t* _corto_word__create(corto_object _parent, const char *_id, uintptr_t value) {
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

corto_int16 _corto_word__update(uintptr_t* _this, uintptr_t value) {
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

uintptr_t* _corto_word__assign(uintptr_t* _this, uintptr_t value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

corto_wordseq* _corto_wordseq__create(corto_object _parent, const char *_id, corto_uint32 length, uintptr_t* elements) {
    corto_wordseq* _this;
    _this = (corto_wordseq*)corto_declare(_parent, _id, corto_wordseq_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_wordseq__resize(_this, length);
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

corto_int16 _corto_wordseq__update(corto_wordseq* _this, corto_uint32 length, uintptr_t* elements) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_wordseq__resize(((corto_wordseq*)CORTO_OFFSET(_this, ((corto_type)corto_wordseq_o)->size)), length);
            corto_uint32 i = 0;
            for (i = 0; i < length; i ++) {
                ((corto_wordseq*)CORTO_OFFSET(_this, ((corto_type)corto_wordseq_o)->size))->buffer[i] = elements[i];
            }
        } else {
            corto_wordseq__resize(_this, length);
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

corto_wordseq* _corto_wordseq__assign(corto_wordseq* _this, corto_uint32 length, uintptr_t* elements) {
    CORTO_UNUSED(_this);
    corto_wordseq__resize(_this, length);
    corto_uint32 i = 0;
    for (i = 0; i < length; i ++) {
        _this->buffer[i] = elements[i];
    }
    return _this;
}

int32_t* corto_int32seq__append(corto_int32seq *seq, int32_t element) {
    corto_uint32 size;
    seq->length++;
    seq->buffer = (int32_t*)corto_realloc(seq->buffer, seq->length * (size=corto_type_sizeof(corto_type(corto_int32_o))));
    memset(&seq->buffer[seq->length-1], 0, size);
    corto_ptr_copy(&seq->buffer[seq->length-1], corto_int32_o, &element);
    return &seq->buffer[seq->length-1];
}

int32_t* corto_int32seq__append_alloc(corto_int32seq *seq) {
    corto_uint32 size;
    seq->length++;
    seq->buffer = (int32_t*)corto_realloc(seq->buffer, seq->length * (size=corto_type_sizeof(corto_type(corto_int32_o))));
    memset(&seq->buffer[seq->length-1], 0, size);
    return &seq->buffer[seq->length-1];
}

void corto_int32seq__resize(corto_int32seq *seq, corto_uint32 length) {
    corto_uint32 size;
    seq->buffer = (int32_t*)corto_realloc(seq->buffer, length * (size=corto_type_sizeof(corto_type(corto_int32_o))));
    if (length > seq->length) {
        memset(&seq->buffer[seq->length], 0, size * (length - seq->length));
    }
    seq->length = length;
}

void corto_int32seq__clear(corto_int32seq *seq) {
    corto_int32seq__resize(seq, 0);
}

corto_interface* corto_interfaceseq__append(corto_interfaceseq *seq, corto_interface element) {
    corto_uint32 size;
    seq->length++;
    seq->buffer = (corto_interface*)corto_realloc(seq->buffer, seq->length * (size=corto_type_sizeof(corto_type(corto_interface_o))));
    memset(seq->buffer[seq->length-1], 0, size);
    corto_set_ref(&seq->buffer[seq->length-1], element);
    return &seq->buffer[seq->length-1];
}

corto_interface* corto_interfaceseq__append_alloc(corto_interfaceseq *seq) {
    corto_uint32 size;
    seq->length++;
    seq->buffer = (corto_interface*)corto_realloc(seq->buffer, seq->length * (size=corto_type_sizeof(corto_type(corto_interface_o))));
    memset(seq->buffer[seq->length-1], 0, size);
    return &seq->buffer[seq->length-1];
}

void corto_interfaceseq__resize(corto_interfaceseq *seq, corto_uint32 length) {
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

void corto_interfaceseq__clear(corto_interfaceseq *seq) {
    corto_interfaceseq__resize(seq, 0);
}

corto_interfaceVector* corto_interfaceVectorseq__append(corto_interfaceVectorseq *seq, corto_interfaceVector element) {
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

corto_interfaceVector* corto_interfaceVectorseq__append_alloc(corto_interfaceVectorseq *seq) {
    corto_uint32 size;
    seq->length++;
    seq->buffer = (corto_interfaceVector*)corto_realloc(seq->buffer, seq->length * (size=corto_type_sizeof(corto_type(corto_interfaceVector_o))));
    memset(&seq->buffer[seq->length-1], 0, size);
    {
        corto_ptr_init(&seq->buffer[seq->length-1], corto_interfaceVector_o);
    }
    return &seq->buffer[seq->length-1];
}

void corto_interfaceVectorseq__resize(corto_interfaceVectorseq *seq, corto_uint32 length) {
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

void corto_interfaceVectorseq__clear(corto_interfaceVectorseq *seq) {
    corto_interfaceVectorseq__resize(seq, 0);
}

void corto_objectlist__insert(corto_objectlist list, corto_object element) {
    corto_ll_insert(list, (void*)(corto_word)element);
    if (element) {
        corto_claim(element);
    }
}

void corto_objectlist__append(corto_objectlist list, corto_object element) {
    corto_ll_append(list, (void*)(corto_word)element);
    if (element) {
        corto_claim(element);
    }
}

void corto_objectlist__remove(corto_objectlist list, corto_object element) {
    corto_ll_remove(list, element);
    corto_release(element);
}

corto_object corto_objectlist__takeFirst(corto_objectlist list) {
    return (corto_object)(corto_word)corto_ll_takeFirst(list);
}

corto_object corto_objectlist__last(corto_objectlist list) {
    return (corto_object)(corto_word)corto_ll_last(list);
}

corto_object corto_objectlist__get(corto_objectlist list, corto_uint32 index) {
    return (corto_object)(corto_word)corto_ll_get(list, index);
}

void corto_objectlist__clear(corto_objectlist list) {
    corto_iter iter = corto_ll_iter(list);
    while(corto_iter_hasNext(&iter)) {
        void *ptr = corto_iter_next(&iter);
        corto_release(ptr);
    }
    corto_ll_clear(list);
}

corto_object* corto_objectseq__append(corto_objectseq *seq, corto_object element) {
    corto_uint32 size;
    seq->length++;
    seq->buffer = (corto_object*)corto_realloc(seq->buffer, seq->length * (size=corto_type_sizeof(corto_type(corto_object_o))));
    memset(seq->buffer[seq->length-1], 0, size);
    corto_set_ref(&seq->buffer[seq->length-1], element);
    return &seq->buffer[seq->length-1];
}

corto_object* corto_objectseq__append_alloc(corto_objectseq *seq) {
    corto_uint32 size;
    seq->length++;
    seq->buffer = (corto_object*)corto_realloc(seq->buffer, seq->length * (size=corto_type_sizeof(corto_type(corto_object_o))));
    memset(seq->buffer[seq->length-1], 0, size);
    return &seq->buffer[seq->length-1];
}

void corto_objectseq__resize(corto_objectseq *seq, corto_uint32 length) {
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

void corto_objectseq__clear(corto_objectseq *seq) {
    corto_objectseq__resize(seq, 0);
}

corto_parameter* corto_parameterseq__append(corto_parameterseq *seq, corto_parameter element) {
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

corto_parameter* corto_parameterseq__append_alloc(corto_parameterseq *seq) {
    corto_uint32 size;
    seq->length++;
    seq->buffer = (corto_parameter*)corto_realloc(seq->buffer, seq->length * (size=corto_type_sizeof(corto_type(corto_parameter_o))));
    memset(&seq->buffer[seq->length-1], 0, size);
    {
        corto_ptr_init(&seq->buffer[seq->length-1], corto_parameter_o);
    }
    return &seq->buffer[seq->length-1];
}

void corto_parameterseq__resize(corto_parameterseq *seq, corto_uint32 length) {
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

void corto_parameterseq__clear(corto_parameterseq *seq) {
    corto_parameterseq__resize(seq, 0);
}

void corto_stringlist__insert(corto_stringlist list, corto_string element) {
    if (element) {
        corto_ll_insert(list, (void*)corto_strdup(element));
    } else {
    corto_ll_insert(list, (void*)element);
    }
}

void corto_stringlist__append(corto_stringlist list, corto_string element) {
    if (element) {
        corto_ll_append(list, (void*)corto_strdup(element));
    } else {
    corto_ll_append(list, (void*)element);
    }
}

corto_string corto_stringlist__takeFirst(corto_stringlist list) {
    return (corto_string)(corto_word)corto_ll_takeFirst(list);
}

corto_string corto_stringlist__last(corto_stringlist list) {
    return (corto_string)(corto_word)corto_ll_last(list);
}

corto_string corto_stringlist__get(corto_stringlist list, corto_uint32 index) {
    return (corto_string)(corto_word)corto_ll_get(list, index);
}

void corto_stringlist__clear(corto_stringlist list) {
    corto_iter iter = corto_ll_iter(list);
    while(corto_iter_hasNext(&iter)) {
        void *ptr = corto_iter_next(&iter);
        corto_ptr_deinit(ptr, corto_string_o);
    }
    corto_ll_clear(list);
}

corto_string* corto_stringseq__append(corto_stringseq *seq, corto_string element) {
    corto_uint32 size;
    seq->length++;
    seq->buffer = (corto_string*)corto_realloc(seq->buffer, seq->length * (size=corto_type_sizeof(corto_type(corto_string_o))));
    memset(&seq->buffer[seq->length-1], 0, size);
    corto_ptr_copy(&seq->buffer[seq->length-1], corto_string_o, &element);
    return &seq->buffer[seq->length-1];
}

corto_string* corto_stringseq__append_alloc(corto_stringseq *seq) {
    corto_uint32 size;
    seq->length++;
    seq->buffer = (corto_string*)corto_realloc(seq->buffer, seq->length * (size=corto_type_sizeof(corto_type(corto_string_o))));
    memset(&seq->buffer[seq->length-1], 0, size);
    return &seq->buffer[seq->length-1];
}

void corto_stringseq__resize(corto_stringseq *seq, corto_uint32 length) {
    corto_uint32 size;
    seq->buffer = (corto_string*)corto_realloc(seq->buffer, length * (size=corto_type_sizeof(corto_type(corto_string_o))));
    if (length > seq->length) {
        memset(&seq->buffer[seq->length], 0, size * (length - seq->length));
    }
    seq->length = length;
}

void corto_stringseq__clear(corto_stringseq *seq) {
    corto_stringseq__resize(seq, 0);
}

void corto_taglist__insert(corto_taglist list, corto_tag element) {
    corto_ll_insert(list, (void*)(corto_word)element);
    if (element) {
        corto_claim(element);
    }
}

void corto_taglist__append(corto_taglist list, corto_tag element) {
    corto_ll_append(list, (void*)(corto_word)element);
    if (element) {
        corto_claim(element);
    }
}

void corto_taglist__remove(corto_taglist list, corto_tag element) {
    corto_ll_remove(list, element);
    corto_release(element);
}

corto_tag corto_taglist__takeFirst(corto_taglist list) {
    return (corto_tag)(corto_word)corto_ll_takeFirst(list);
}

corto_tag corto_taglist__last(corto_taglist list) {
    return (corto_tag)(corto_word)corto_ll_last(list);
}

corto_tag corto_taglist__get(corto_taglist list, corto_uint32 index) {
    return (corto_tag)(corto_word)corto_ll_get(list, index);
}

void corto_taglist__clear(corto_taglist list) {
    corto_iter iter = corto_ll_iter(list);
    while(corto_iter_hasNext(&iter)) {
        void *ptr = corto_iter_next(&iter);
        corto_release(ptr);
    }
    corto_ll_clear(list);
}

uintptr_t* corto_wordseq__append(corto_wordseq *seq, uintptr_t element) {
    corto_uint32 size;
    seq->length++;
    seq->buffer = (uintptr_t*)corto_realloc(seq->buffer, seq->length * (size=corto_type_sizeof(corto_type(corto_word_o))));
    memset(&seq->buffer[seq->length-1], 0, size);
    corto_ptr_copy(&seq->buffer[seq->length-1], corto_word_o, &element);
    return &seq->buffer[seq->length-1];
}

uintptr_t* corto_wordseq__append_alloc(corto_wordseq *seq) {
    corto_uint32 size;
    seq->length++;
    seq->buffer = (uintptr_t*)corto_realloc(seq->buffer, seq->length * (size=corto_type_sizeof(corto_type(corto_word_o))));
    memset(&seq->buffer[seq->length-1], 0, size);
    return &seq->buffer[seq->length-1];
}

void corto_wordseq__resize(corto_wordseq *seq, corto_uint32 length) {
    corto_uint32 size;
    seq->buffer = (uintptr_t*)corto_realloc(seq->buffer, length * (size=corto_type_sizeof(corto_type(corto_word_o))));
    if (length > seq->length) {
        memset(&seq->buffer[seq->length], 0, size * (length - seq->length));
    }
    seq->length = length;
}

void corto_wordseq__clear(corto_wordseq *seq) {
    corto_wordseq__resize(seq, 0);
}

