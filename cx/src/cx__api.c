/* cx__api.c
 *
 * API convenience functions for C-language.
 * This file contains generated code. Do not modify!
 */

#include "cx.h"

cx_alias cx_alias__new(void) {
    return cx_new(cx_type(cx_alias_o));
}

cx_alias cx_alias__declare(cx_object _parent, cx_string _name) {
    return cx_declare(_parent, _name, cx_type(cx_alias_o));
}

int cx_alias__define(cx_alias _this, cx_string typeName) {
    _this->typeName = (typeName ? cx_strdup(typeName) : NULL);
    return cx_define(_this);
}

cx_alias cx_alias__create(cx_string typeName) {
    cx_alias _this;
    _this = cx_new(cx_type(cx_alias_o));
    _this->typeName = (typeName ? cx_strdup(typeName) : NULL);
    if (cx_define(_this)) {
        cx_free(_this);
        _this = NULL;
    }
    return _this;
}

cx_string cx_alias__str(cx_alias value) {
    cx_string result;
    result = cx_toString(value, 0);
    return result;
}

cx_string cx_any__str(cx_any value) {
    cx_string result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_any_o), &value);
    result = cx_valueToString(&v, 0);
    return result;
}

cx_array cx_array__new(void) {
    return cx_new(cx_type(cx_array_o));
}

cx_array cx_array__declare(cx_object _parent, cx_string _name) {
    return cx_declare(_parent, _name, cx_type(cx_array_o));
}

int cx_array__define(cx_array _this, cx_type elementType, cx_uint32 max) {
    elementType ? cx_keep_ext(_this, elementType, "element <0x7f87a97020a8>.elementType") : 0;
    cx_collection(_this)->elementType = cx_type(elementType);
    cx_collection(_this)->max = max;
    return cx_define(_this);
}

cx_array cx_array__create(cx_type elementType, cx_uint32 max) {
    cx_array _this;
    _this = cx_new(cx_type(cx_array_o));
    elementType ? cx_keep_ext(_this, elementType, "element <0x7f87a97020a8>.elementType") : 0;
    cx_collection(_this)->elementType = cx_type(elementType);
    cx_collection(_this)->max = max;
    if (cx_define(_this)) {
        cx_free(_this);
        _this = NULL;
    }
    return _this;
}

cx_string cx_array__str(cx_array value) {
    cx_string result;
    result = cx_toString(value, 0);
    return result;
}

cx_string cx_attr__str(cx_attr value) {
    cx_string result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_attr_o), &value);
    result = cx_valueToString(&v, 0);
    return result;
}

cx_binary cx_binary__new(void) {
    return cx_new(cx_type(cx_binary_o));
}

cx_binary cx_binary__declare(cx_object _parent, cx_string _name) {
    return cx_declare(_parent, _name, cx_type(cx_binary_o));
}

int cx_binary__define(cx_binary _this, cx_width width) {
    cx_primitive(_this)->width = width;
    return cx_define(_this);
}

cx_binary cx_binary__create(cx_width width) {
    cx_binary _this;
    _this = cx_new(cx_type(cx_binary_o));
    cx_primitive(_this)->width = width;
    if (cx_define(_this)) {
        cx_free(_this);
        _this = NULL;
    }
    return _this;
}

cx_string cx_binary__str(cx_binary value) {
    cx_string result;
    result = cx_toString(value, 0);
    return result;
}

cx_bitmask cx_bitmask__new(void) {
    return cx_new(cx_type(cx_bitmask_o));
}

cx_bitmask cx_bitmask__declare(cx_object _parent, cx_string _name) {
    return cx_declare(_parent, _name, cx_type(cx_bitmask_o));
}

int cx_bitmask__define(cx_bitmask _this) {
    return cx_define(_this);
}

cx_bitmask cx_bitmask__create(void) {
    cx_bitmask _this;
    _this = cx_new(cx_type(cx_bitmask_o));
    if (cx_define(_this)) {
        cx_free(_this);
        _this = NULL;
    }
    return _this;
}

cx_string cx_bitmask__str(cx_bitmask value) {
    cx_string result;
    result = cx_toString(value, 0);
    return result;
}

cx_string cx_bool__str(cx_bool value) {
    cx_string result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_bool_o), &value);
    result = cx_valueToString(&v, 0);
    return result;
}

cx_boolean cx_boolean__new(void) {
    return cx_new(cx_type(cx_boolean_o));
}

cx_boolean cx_boolean__declare(cx_object _parent, cx_string _name) {
    return cx_declare(_parent, _name, cx_type(cx_boolean_o));
}

int cx_boolean__define(cx_boolean _this) {
    return cx_define(_this);
}

cx_boolean cx_boolean__create(void) {
    cx_boolean _this;
    _this = cx_new(cx_type(cx_boolean_o));
    if (cx_define(_this)) {
        cx_free(_this);
        _this = NULL;
    }
    return _this;
}

cx_string cx_boolean__str(cx_boolean value) {
    cx_string result;
    result = cx_toString(value, 0);
    return result;
}

void cx_callbackDestruct__init(cx_callbackDestruct *_this) {
    cx_value v;
    memset(_this, 0, sizeof(*_this));
    cx_valueValueInit(&v, NULL, cx_type(cx_callbackDestruct_o), _this);
    cx_initValue(&v);
}

void cx_callbackDestruct__deinit(cx_callbackDestruct *_this) {
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_callbackDestruct_o), _this);
    cx_deinitValue(&v);
}

cx_string cx_callbackDestruct__str(cx_callbackDestruct value) {
    cx_string result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_callbackDestruct_o), &value);
    result = cx_valueToString(&v, 0);
    return result;
}

void cx_callbackInit__init(cx_callbackInit *_this) {
    cx_value v;
    memset(_this, 0, sizeof(*_this));
    cx_valueValueInit(&v, NULL, cx_type(cx_callbackInit_o), _this);
    cx_initValue(&v);
}

void cx_callbackInit__deinit(cx_callbackInit *_this) {
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_callbackInit_o), _this);
    cx_deinitValue(&v);
}

cx_string cx_callbackInit__str(cx_callbackInit value) {
    cx_string result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_callbackInit_o), &value);
    result = cx_valueToString(&v, 0);
    return result;
}

cx_string cx_char__str(cx_char value) {
    cx_string result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_char_o), &value);
    result = cx_valueToString(&v, 0);
    return result;
}

cx_character cx_character__new(void) {
    return cx_new(cx_type(cx_character_o));
}

cx_character cx_character__declare(cx_object _parent, cx_string _name) {
    return cx_declare(_parent, _name, cx_type(cx_character_o));
}

int cx_character__define(cx_character _this, cx_width width) {
    cx_primitive(_this)->width = width;
    return cx_define(_this);
}

cx_character cx_character__create(cx_width width) {
    cx_character _this;
    _this = cx_new(cx_type(cx_character_o));
    cx_primitive(_this)->width = width;
    if (cx_define(_this)) {
        cx_free(_this);
        _this = NULL;
    }
    return _this;
}

cx_string cx_character__str(cx_character value) {
    cx_string result;
    result = cx_toString(value, 0);
    return result;
}

cx_class cx_class__new(void) {
    return cx_new(cx_type(cx_class_o));
}

cx_class cx_class__declare(cx_object _parent, cx_string _name) {
    return cx_declare(_parent, _name, cx_type(cx_class_o));
}

int cx_class__define(cx_class _this, cx_interface base, cx_modifier baseAccess, cx_interfaceSeq implements) {
    base ? cx_keep_ext(_this, base, "element <0x7f87a9700e08>.base") : 0;
    cx_interface(_this)->base = cx_interface(base);
    cx_struct(_this)->baseAccess = baseAccess;
    _this->implements = implements;
    return cx_define(_this);
}

cx_class cx_class__create(cx_interface base, cx_modifier baseAccess, cx_interfaceSeq implements) {
    cx_class _this;
    _this = cx_new(cx_type(cx_class_o));
    base ? cx_keep_ext(_this, base, "element <0x7f87a9700e08>.base") : 0;
    cx_interface(_this)->base = cx_interface(base);
    cx_struct(_this)->baseAccess = baseAccess;
    _this->implements = implements;
    if (cx_define(_this)) {
        cx_free(_this);
        _this = NULL;
    }
    return _this;
}

cx_string cx_class__str(cx_class value) {
    cx_string result;
    result = cx_toString(value, 0);
    return result;
}

cx_collection cx_collection__new(void) {
    return cx_new(cx_type(cx_collection_o));
}

cx_collection cx_collection__declare(cx_object _parent, cx_string _name) {
    return cx_declare(_parent, _name, cx_type(cx_collection_o));
}

int cx_collection__define(cx_collection _this, cx_type elementType, cx_uint32 max) {
    elementType ? cx_keep_ext(_this, elementType, "element <0x7f87a97020a8>.elementType") : 0;
    _this->elementType = cx_type(elementType);
    _this->max = max;
    return cx_define(_this);
}

cx_collection cx_collection__create(cx_type elementType, cx_uint32 max) {
    cx_collection _this;
    _this = cx_new(cx_type(cx_collection_o));
    elementType ? cx_keep_ext(_this, elementType, "element <0x7f87a97020a8>.elementType") : 0;
    _this->elementType = cx_type(elementType);
    _this->max = max;
    if (cx_define(_this)) {
        cx_free(_this);
        _this = NULL;
    }
    return _this;
}

cx_string cx_collection__str(cx_collection value) {
    cx_string result;
    result = cx_toString(value, 0);
    return result;
}

cx_string cx_collectionKind__str(cx_collectionKind value) {
    cx_string result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_collectionKind_o), &value);
    result = cx_valueToString(&v, 0);
    return result;
}

cx_string cx_compositeKind__str(cx_compositeKind value) {
    cx_string result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_compositeKind_o), &value);
    result = cx_valueToString(&v, 0);
    return result;
}

cx_string cx_constant__str(cx_constant value) {
    cx_string result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_constant_o), &value);
    result = cx_valueToString(&v, 0);
    return result;
}

cx_delegate cx_delegate__new(void) {
    return cx_new(cx_type(cx_delegate_o));
}

cx_delegate cx_delegate__declare(cx_object _parent, cx_string _name) {
    return cx_declare(_parent, _name, cx_type(cx_delegate_o));
}

int cx_delegate__define(cx_delegate _this, cx_type returnType, cx_bool returnsReference, cx_parameterSeq parameters) {
    returnType ? cx_keep_ext(_this, returnType, "element <0x7f87a9703178>.returnType") : 0;
    _this->returnType = cx_type(returnType);
    _this->returnsReference = returnsReference;
    _this->parameters = parameters;
    return cx_define(_this);
}

cx_delegate cx_delegate__create(cx_type returnType, cx_bool returnsReference, cx_parameterSeq parameters) {
    cx_delegate _this;
    _this = cx_new(cx_type(cx_delegate_o));
    returnType ? cx_keep_ext(_this, returnType, "element <0x7f87a9703178>.returnType") : 0;
    _this->returnType = cx_type(returnType);
    _this->returnsReference = returnsReference;
    _this->parameters = parameters;
    if (cx_define(_this)) {
        cx_free(_this);
        _this = NULL;
    }
    return _this;
}

cx_string cx_delegate__str(cx_delegate value) {
    cx_string result;
    result = cx_toString(value, 0);
    return result;
}

void cx_delegatedata__init(cx_delegatedata *_this, cx_object instance, cx_function procedure) {
    cx_value v;
    memset(_this, 0, sizeof(*_this));
    cx_valueValueInit(&v, NULL, cx_type(cx_delegatedata_o), _this);
    cx_initValue(&v);
    instance ? cx_keep_ext(_this, instance, "element <0x7f87a97024b8>.instance") : 0;
    _this->instance = instance;
    procedure ? cx_keep_ext(_this, procedure, "element <0x7f87a97024b8>.procedure") : 0;
    _this->procedure = cx_function(procedure);
}

void cx_delegatedata__deinit(cx_delegatedata *_this) {
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_delegatedata_o), _this);
    cx_deinitValue(&v);
}

cx_string cx_delegatedata__str(cx_delegatedata value) {
    cx_string result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_delegatedata_o), &value);
    result = cx_valueToString(&v, 0);
    return result;
}

cx_dispatcher cx_dispatcher__new(void) {
    return cx_new(cx_type(cx_dispatcher_o));
}

cx_dispatcher cx_dispatcher__declare(cx_object _parent, cx_string _name) {
    return cx_declare(_parent, _name, cx_type(cx_dispatcher_o));
}

int cx_dispatcher__define(cx_dispatcher _this) {
    return cx_define(_this);
}

cx_dispatcher cx_dispatcher__create(void) {
    cx_dispatcher _this;
    _this = cx_new(cx_type(cx_dispatcher_o));
    if (cx_define(_this)) {
        cx_free(_this);
        _this = NULL;
    }
    return _this;
}

cx_string cx_dispatcher__str(cx_dispatcher value) {
    cx_string result;
    result = cx_toString(value, 0);
    return result;
}

cx_enum cx_enum__new(void) {
    return cx_new(cx_type(cx_enum_o));
}

cx_enum cx_enum__declare(cx_object _parent, cx_string _name) {
    return cx_declare(_parent, _name, cx_type(cx_enum_o));
}

int cx_enum__define(cx_enum _this) {
    return cx_define(_this);
}

cx_enum cx_enum__create(void) {
    cx_enum _this;
    _this = cx_new(cx_type(cx_enum_o));
    if (cx_define(_this)) {
        cx_free(_this);
        _this = NULL;
    }
    return _this;
}

cx_string cx_enum__str(cx_enum value) {
    cx_string result;
    result = cx_toString(value, 0);
    return result;
}

cx_string cx_equalityKind__str(cx_equalityKind value) {
    cx_string result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_equalityKind_o), &value);
    result = cx_valueToString(&v, 0);
    return result;
}

cx_event cx_event__new(void) {
    return cx_new(cx_type(cx_event_o));
}

cx_event cx_event__declare(cx_object _parent, cx_string _name) {
    return cx_declare(_parent, _name, cx_type(cx_event_o));
}

int cx_event__define(cx_event _this, cx_uint16 kind) {
    _this->kind = kind;
    return cx_define(_this);
}

cx_event cx_event__create(cx_uint16 kind) {
    cx_event _this;
    _this = cx_new(cx_type(cx_event_o));
    _this->kind = kind;
    if (cx_define(_this)) {
        cx_free(_this);
        _this = NULL;
    }
    return _this;
}

cx_string cx_event__str(cx_event value) {
    cx_string result;
    result = cx_toString(value, 0);
    return result;
}

cx_string cx_eventMask__str(cx_eventMask value) {
    cx_string result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_eventMask_o), &value);
    result = cx_valueToString(&v, 0);
    return result;
}

cx_float cx_float__new(void) {
    return cx_new(cx_type(cx_float_o));
}

cx_float cx_float__declare(cx_object _parent, cx_string _name) {
    return cx_declare(_parent, _name, cx_type(cx_float_o));
}

int cx_float__define(cx_float _this, cx_width width, cx_float64 min, cx_float64 max) {
    cx_primitive(_this)->width = width;
    _this->min = min;
    _this->max = max;
    return cx_define(_this);
}

cx_float cx_float__create(cx_width width, cx_float64 min, cx_float64 max) {
    cx_float _this;
    _this = cx_new(cx_type(cx_float_o));
    cx_primitive(_this)->width = width;
    _this->min = min;
    _this->max = max;
    if (cx_define(_this)) {
        cx_free(_this);
        _this = NULL;
    }
    return _this;
}

cx_string cx_float__str(cx_float value) {
    cx_string result;
    result = cx_toString(value, 0);
    return result;
}

cx_string cx_float32__str(cx_float32 value) {
    cx_string result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_float32_o), &value);
    result = cx_valueToString(&v, 0);
    return result;
}

cx_string cx_float64__str(cx_float64 value) {
    cx_string result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_float64_o), &value);
    result = cx_valueToString(&v, 0);
    return result;
}

cx_function cx_function__new(void) {
    return cx_new(cx_type(cx_function_o));
}

cx_function cx_function__declare(cx_object _parent, cx_string _name) {
    return cx_declare(_parent, _name, cx_type(cx_function_o));
}

int cx_function__define(cx_function _this, cx_type returnType, cx_bool returnsReference) {
    returnType ? cx_keep_ext(_this, returnType, "element <0x7f87a9702698>.returnType") : 0;
    _this->returnType = cx_type(returnType);
    _this->returnsReference = returnsReference;
    return cx_define(_this);
}

cx_function cx_function__create(cx_type returnType, cx_bool returnsReference) {
    cx_function _this;
    _this = cx_new(cx_type(cx_function_o));
    returnType ? cx_keep_ext(_this, returnType, "element <0x7f87a97037c8>.returnType") : 0;
    _this->returnType = cx_type(returnType);
    _this->returnsReference = returnsReference;
    if (cx_define(_this)) {
        cx_free(_this);
        _this = NULL;
    }
    return _this;
}

cx_string cx_function__str(cx_function value) {
    cx_string result;
    result = cx_toString(value, 0);
    return result;
}

cx_int cx_int__new(void) {
    return cx_new(cx_type(cx_int_o));
}

cx_int cx_int__declare(cx_object _parent, cx_string _name) {
    return cx_declare(_parent, _name, cx_type(cx_int_o));
}

int cx_int__define(cx_int _this, cx_width width, cx_int64 min, cx_int64 max) {
    cx_primitive(_this)->width = width;
    _this->min = min;
    _this->max = max;
    return cx_define(_this);
}

cx_int cx_int__create(cx_width width, cx_int64 min, cx_int64 max) {
    cx_int _this;
    _this = cx_new(cx_type(cx_int_o));
    cx_primitive(_this)->width = width;
    _this->min = min;
    _this->max = max;
    if (cx_define(_this)) {
        cx_free(_this);
        _this = NULL;
    }
    return _this;
}

cx_string cx_int__str(cx_int value) {
    cx_string result;
    result = cx_toString(value, 0);
    return result;
}

cx_string cx_int16__str(cx_int16 value) {
    cx_string result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_int16_o), &value);
    result = cx_valueToString(&v, 0);
    return result;
}

cx_string cx_int32__str(cx_int32 value) {
    cx_string result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_int32_o), &value);
    result = cx_valueToString(&v, 0);
    return result;
}

cx_string cx_int64__str(cx_int64 value) {
    cx_string result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_int64_o), &value);
    result = cx_valueToString(&v, 0);
    return result;
}

cx_string cx_int8__str(cx_int8 value) {
    cx_string result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_int8_o), &value);
    result = cx_valueToString(&v, 0);
    return result;
}

cx_interface cx_interface__new(void) {
    return cx_new(cx_type(cx_interface_o));
}

cx_interface cx_interface__declare(cx_object _parent, cx_string _name) {
    return cx_declare(_parent, _name, cx_type(cx_interface_o));
}

int cx_interface__define(cx_interface _this, cx_interface base) {
    base ? cx_keep_ext(_this, base, "element <0x7f87a9702148>.base") : 0;
    _this->base = cx_interface(base);
    return cx_define(_this);
}

cx_interface cx_interface__create(cx_interface base) {
    cx_interface _this;
    _this = cx_new(cx_type(cx_interface_o));
    base ? cx_keep_ext(_this, base, "element <0x7f87a9702148>.base") : 0;
    _this->base = cx_interface(base);
    if (cx_define(_this)) {
        cx_free(_this);
        _this = NULL;
    }
    return _this;
}

cx_string cx_interface__str(cx_interface value) {
    cx_string result;
    result = cx_toString(value, 0);
    return result;
}

cx_string cx_interfaceSeq__str(cx_interfaceSeq value) {
    cx_string result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_interfaceSeq_o), &value);
    result = cx_valueToString(&v, 0);
    return result;
}

void cx_interfaceVector__init(cx_interfaceVector *_this, cx_interface interface, cx_vtable vector) {
    cx_value v;
    memset(_this, 0, sizeof(*_this));
    cx_valueValueInit(&v, NULL, cx_type(cx_interfaceVector_o), _this);
    cx_initValue(&v);
    interface ? cx_keep_ext(_this, interface, "element <0x7f87a97024b8>.interface") : 0;
    _this->interface = cx_interface(interface);
    _this->vector = vector;
}

void cx_interfaceVector__deinit(cx_interfaceVector *_this) {
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_interfaceVector_o), _this);
    cx_deinitValue(&v);
}

cx_string cx_interfaceVector__str(cx_interfaceVector value) {
    cx_string result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_interfaceVector_o), &value);
    result = cx_valueToString(&v, 0);
    return result;
}

cx_string cx_interfaceVectorSeq__str(cx_interfaceVectorSeq value) {
    cx_string result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_interfaceVectorSeq_o), &value);
    result = cx_valueToString(&v, 0);
    return result;
}

cx_iterator cx_iterator__new(void) {
    return cx_new(cx_type(cx_iterator_o));
}

cx_iterator cx_iterator__declare(cx_object _parent, cx_string _name) {
    return cx_declare(_parent, _name, cx_type(cx_iterator_o));
}

int cx_iterator__define(cx_iterator _this, cx_type elementType) {
    elementType ? cx_keep_ext(_this, elementType, "element <0x7f87a97003b8>.elementType") : 0;
    _this->elementType = cx_type(elementType);
    return cx_define(_this);
}

cx_iterator cx_iterator__create(cx_type elementType) {
    cx_iterator _this;
    _this = cx_new(cx_type(cx_iterator_o));
    elementType ? cx_keep_ext(_this, elementType, "element <0x7f87a97003b8>.elementType") : 0;
    _this->elementType = cx_type(elementType);
    if (cx_define(_this)) {
        cx_free(_this);
        _this = NULL;
    }
    return _this;
}

cx_string cx_iterator__str(cx_iterator value) {
    cx_string result;
    result = cx_toString(value, 0);
    return result;
}

cx_list cx_list__new(void) {
    return cx_new(cx_type(cx_list_o));
}

cx_list cx_list__declare(cx_object _parent, cx_string _name) {
    return cx_declare(_parent, _name, cx_type(cx_list_o));
}

int cx_list__define(cx_list _this, cx_type elementType, cx_uint32 max) {
    elementType ? cx_keep_ext(_this, elementType, "element <0x7f87a97020a8>.elementType") : 0;
    cx_collection(_this)->elementType = cx_type(elementType);
    cx_collection(_this)->max = max;
    return cx_define(_this);
}

cx_list cx_list__create(cx_type elementType, cx_uint32 max) {
    cx_list _this;
    _this = cx_new(cx_type(cx_list_o));
    elementType ? cx_keep_ext(_this, elementType, "element <0x7f87a97020a8>.elementType") : 0;
    cx_collection(_this)->elementType = cx_type(elementType);
    cx_collection(_this)->max = max;
    if (cx_define(_this)) {
        cx_free(_this);
        _this = NULL;
    }
    return _this;
}

cx_string cx_list__str(cx_list value) {
    cx_string result;
    result = cx_toString(value, 0);
    return result;
}

cx_map cx_map__new(void) {
    return cx_new(cx_type(cx_map_o));
}

cx_map cx_map__declare(cx_object _parent, cx_string _name) {
    return cx_declare(_parent, _name, cx_type(cx_map_o));
}

int cx_map__define(cx_map _this, cx_type elementType, cx_type keyType, cx_uint32 max) {
    elementType ? cx_keep_ext(_this, elementType, "element <0x7f87a9702148>.elementType") : 0;
    _this->elementType = cx_type(elementType);
    keyType ? cx_keep_ext(_this, keyType, "element <0x7f87a9702148>.keyType") : 0;
    _this->keyType = cx_type(keyType);
    _this->max = max;
    return cx_define(_this);
}

cx_map cx_map__create(cx_type elementType, cx_type keyType, cx_uint32 max) {
    cx_map _this;
    _this = cx_new(cx_type(cx_map_o));
    elementType ? cx_keep_ext(_this, elementType, "element <0x7f87a9702148>.elementType") : 0;
    _this->elementType = cx_type(elementType);
    keyType ? cx_keep_ext(_this, keyType, "element <0x7f87a9702148>.keyType") : 0;
    _this->keyType = cx_type(keyType);
    _this->max = max;
    if (cx_define(_this)) {
        cx_free(_this);
        _this = NULL;
    }
    return _this;
}

cx_string cx_map__str(cx_map value) {
    cx_string result;
    result = cx_toString(value, 0);
    return result;
}

cx_member cx_member__new(void) {
    return cx_new(cx_type(cx_member_o));
}

cx_member cx_member__declare(cx_object _parent, cx_string _name) {
    return cx_declare(_parent, _name, cx_type(cx_member_o));
}

int cx_member__define(cx_member _this, cx_type type, cx_modifier modifiers, cx_state state, cx_bool weak) {
    type ? cx_keep_ext(_this, type, "element <0x7f87a97024b8>.type") : 0;
    _this->type = cx_type(type);
    _this->modifiers = modifiers;
    _this->state = state;
    _this->weak = weak;
    return cx_define(_this);
}

cx_member cx_member__create(cx_type type, cx_modifier modifiers, cx_state state, cx_bool weak) {
    cx_member _this;
    _this = cx_new(cx_type(cx_member_o));
    type ? cx_keep_ext(_this, type, "element <0x7f87a97024b8>.type") : 0;
    _this->type = cx_type(type);
    _this->modifiers = modifiers;
    _this->state = state;
    _this->weak = weak;
    if (cx_define(_this)) {
        cx_free(_this);
        _this = NULL;
    }
    return _this;
}

cx_string cx_member__str(cx_member value) {
    cx_string result;
    result = cx_toString(value, 0);
    return result;
}

cx_string cx_memberSeq__str(cx_memberSeq value) {
    cx_string result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_memberSeq_o), &value);
    result = cx_valueToString(&v, 0);
    return result;
}

cx_metaprocedure cx_metaprocedure__new(void) {
    return cx_new(cx_type(cx_metaprocedure_o));
}

cx_metaprocedure cx_metaprocedure__declare(cx_object _parent, cx_string _name) {
    return cx_declare(_parent, _name, cx_type(cx_metaprocedure_o));
}

int cx_metaprocedure__define(cx_metaprocedure _this, cx_type returnType, cx_bool returnsReference, cx_bool referenceOnly) {
    returnType ? cx_keep_ext(_this, returnType, "element <0x7f87a97003b8>.returnType") : 0;
    cx_function(_this)->returnType = cx_type(returnType);
    cx_function(_this)->returnsReference = returnsReference;
    _this->referenceOnly = referenceOnly;
    return cx_define(_this);
}

cx_metaprocedure cx_metaprocedure__create(cx_type returnType, cx_bool returnsReference, cx_bool referenceOnly) {
    cx_metaprocedure _this;
    _this = cx_new(cx_type(cx_metaprocedure_o));
    returnType ? cx_keep_ext(_this, returnType, "element <0x7f87a97003b8>.returnType") : 0;
    cx_function(_this)->returnType = cx_type(returnType);
    cx_function(_this)->returnsReference = returnsReference;
    _this->referenceOnly = referenceOnly;
    if (cx_define(_this)) {
        cx_free(_this);
        _this = NULL;
    }
    return _this;
}

cx_string cx_metaprocedure__str(cx_metaprocedure value) {
    cx_string result;
    result = cx_toString(value, 0);
    return result;
}

cx_method cx_method__new(void) {
    return cx_new(cx_type(cx_method_o));
}

cx_method cx_method__declare(cx_object _parent, cx_string _name) {
    return cx_declare(_parent, _name, cx_type(cx_method_o));
}

int cx_method__define(cx_method _this, cx_type returnType, cx_bool returnsReference, cx_bool virtual) {
    returnType ? cx_keep_ext(_this, returnType, "element <0x7f87a97003b8>.returnType") : 0;
    cx_function(_this)->returnType = cx_type(returnType);
    cx_function(_this)->returnsReference = returnsReference;
    _this->virtual = virtual;
    return cx_define(_this);
}

cx_method cx_method__create(cx_type returnType, cx_bool returnsReference, cx_bool virtual) {
    cx_method _this;
    _this = cx_new(cx_type(cx_method_o));
    returnType ? cx_keep_ext(_this, returnType, "element <0x7f87a97003b8>.returnType") : 0;
    cx_function(_this)->returnType = cx_type(returnType);
    cx_function(_this)->returnsReference = returnsReference;
    _this->virtual = virtual;
    if (cx_define(_this)) {
        cx_free(_this);
        _this = NULL;
    }
    return _this;
}

cx_string cx_method__str(cx_method value) {
    cx_string result;
    result = cx_toString(value, 0);
    return result;
}

cx_string cx_modifier__str(cx_modifier value) {
    cx_string result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_modifier_o), &value);
    result = cx_valueToString(&v, 0);
    return result;
}

cx_string cx_objectSeq__str(cx_objectSeq value) {
    cx_string result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_objectSeq_o), &value);
    result = cx_valueToString(&v, 0);
    return result;
}

cx_observableEvent cx_observableEvent__new(void) {
    return cx_new(cx_type(cx_observableEvent_o));
}

cx_observableEvent cx_observableEvent__declare(cx_object _parent, cx_string _name) {
    return cx_declare(_parent, _name, cx_type(cx_observableEvent_o));
}

int cx_observableEvent__define(cx_observableEvent _this, cx_uint16 kind, cx_observer observer, cx_object me, cx_object source, cx_object observable) {
    cx_event(_this)->kind = kind;
    observer ? cx_keep_ext(_this, observer, "element <0x7f87a97037c8>.observer") : 0;
    _this->observer = cx_observer(observer);
    me ? cx_keep_ext(_this, me, "element <0x7f87a97037c8>.me") : 0;
    _this->me = me;
    source ? cx_keep_ext(_this, source, "element <0x7f87a97037c8>.source") : 0;
    _this->source = source;
    observable ? cx_keep_ext(_this, observable, "element <0x7f87a97037c8>.observable") : 0;
    _this->observable = observable;
    return cx_define(_this);
}

cx_observableEvent cx_observableEvent__create(cx_uint16 kind, cx_observer observer, cx_object me, cx_object source, cx_object observable) {
    cx_observableEvent _this;
    _this = cx_new(cx_type(cx_observableEvent_o));
    cx_event(_this)->kind = kind;
    observer ? cx_keep_ext(_this, observer, "element <0x7f87a9702698>.observer") : 0;
    _this->observer = cx_observer(observer);
    me ? cx_keep_ext(_this, me, "element <0x7f87a9702698>.me") : 0;
    _this->me = me;
    source ? cx_keep_ext(_this, source, "element <0x7f87a9702698>.source") : 0;
    _this->source = source;
    observable ? cx_keep_ext(_this, observable, "element <0x7f87a9702698>.observable") : 0;
    _this->observable = observable;
    if (cx_define(_this)) {
        cx_free(_this);
        _this = NULL;
    }
    return _this;
}

cx_string cx_observableEvent__str(cx_observableEvent value) {
    cx_string result;
    result = cx_toString(value, 0);
    return result;
}

cx_observer cx_observer__new(void) {
    return cx_new(cx_type(cx_observer_o));
}

cx_observer cx_observer__declare(cx_object _parent, cx_string _name) {
    return cx_declare(_parent, _name, cx_type(cx_observer_o));
}

int cx_observer__define(cx_observer _this, cx_object observable, cx_eventMask mask, cx_string expression, cx_uint32 template, cx_dispatcher dispatcher, cx_object me) {
    observable ? cx_keep_ext(_this, observable, "element <0x7f87a9702148>.observable") : 0;
    _this->observable = observable;
    _this->mask = mask;
    _this->expression = (expression ? cx_strdup(expression) : NULL);
    _this->template = template;
    dispatcher ? cx_keep_ext(_this, dispatcher, "element <0x7f87a9702148>.dispatcher") : 0;
    _this->dispatcher = cx_dispatcher(dispatcher);
    me ? cx_keep_ext(_this, me, "element <0x7f87a9702148>.me") : 0;
    _this->me = me;
    return cx_define(_this);
}

cx_observer cx_observer__create(cx_object observable, cx_eventMask mask, cx_string expression, cx_uint32 template, cx_dispatcher dispatcher, cx_object me) {
    cx_observer _this;
    _this = cx_new(cx_type(cx_observer_o));
    observable ? cx_keep_ext(_this, observable, "element <0x7f87a9702148>.observable") : 0;
    _this->observable = observable;
    _this->mask = mask;
    _this->expression = (expression ? cx_strdup(expression) : NULL);
    _this->template = template;
    dispatcher ? cx_keep_ext(_this, dispatcher, "element <0x7f87a9702148>.dispatcher") : 0;
    _this->dispatcher = cx_dispatcher(dispatcher);
    me ? cx_keep_ext(_this, me, "element <0x7f87a9702148>.me") : 0;
    _this->me = me;
    if (cx_define(_this)) {
        cx_free(_this);
        _this = NULL;
    }
    return _this;
}

cx_string cx_observer__str(cx_observer value) {
    cx_string result;
    result = cx_toString(value, 0);
    return result;
}

cx_string cx_observerSeq__str(cx_observerSeq value) {
    cx_string result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_observerSeq_o), &value);
    result = cx_valueToString(&v, 0);
    return result;
}

cx_string cx_octet__str(cx_octet value) {
    cx_string result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_octet_o), &value);
    result = cx_valueToString(&v, 0);
    return result;
}

cx_string cx_operatorKind__str(cx_operatorKind value) {
    cx_string result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_operatorKind_o), &value);
    result = cx_valueToString(&v, 0);
    return result;
}

cx_package cx_package__new(void) {
    return cx_new(cx_type(cx_package_o));
}

cx_package cx_package__declare(cx_object _parent, cx_string _name) {
    return cx_declare(_parent, _name, cx_type(cx_package_o));
}

int cx_package__define(cx_package _this, cx_string url) {
    _this->url = (url ? cx_strdup(url) : NULL);
    return cx_define(_this);
}

cx_package cx_package__create(cx_string url) {
    cx_package _this;
    _this = cx_new(cx_type(cx_package_o));
    _this->url = (url ? cx_strdup(url) : NULL);
    if (cx_define(_this)) {
        cx_free(_this);
        _this = NULL;
    }
    return _this;
}

cx_string cx_package__str(cx_package value) {
    cx_string result;
    result = cx_toString(value, 0);
    return result;
}

void cx_parameter__init(cx_parameter *_this, cx_string name, cx_type type, cx_bool passByReference) {
    cx_value v;
    memset(_this, 0, sizeof(*_this));
    cx_valueValueInit(&v, NULL, cx_type(cx_parameter_o), _this);
    cx_initValue(&v);
    _this->name = (name ? cx_strdup(name) : NULL);
    type ? cx_keep_ext(_this, type, "element <0x7f87a97037e8>.type") : 0;
    _this->type = cx_type(type);
    _this->passByReference = passByReference;
}

void cx_parameter__deinit(cx_parameter *_this) {
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_parameter_o), _this);
    cx_deinitValue(&v);
}

cx_string cx_parameter__str(cx_parameter value) {
    cx_string result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_parameter_o), &value);
    result = cx_valueToString(&v, 0);
    return result;
}

cx_string cx_parameterSeq__str(cx_parameterSeq value) {
    cx_string result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_parameterSeq_o), &value);
    result = cx_valueToString(&v, 0);
    return result;
}

cx_primitive cx_primitive__new(void) {
    return cx_new(cx_type(cx_primitive_o));
}

cx_primitive cx_primitive__declare(cx_object _parent, cx_string _name) {
    return cx_declare(_parent, _name, cx_type(cx_primitive_o));
}

int cx_primitive__define(cx_primitive _this, cx_width width) {
    _this->width = width;
    return cx_define(_this);
}

cx_primitive cx_primitive__create(cx_width width) {
    cx_primitive _this;
    _this = cx_new(cx_type(cx_primitive_o));
    _this->width = width;
    if (cx_define(_this)) {
        cx_free(_this);
        _this = NULL;
    }
    return _this;
}

cx_string cx_primitive__str(cx_primitive value) {
    cx_string result;
    result = cx_toString(value, 0);
    return result;
}

cx_string cx_primitiveKind__str(cx_primitiveKind value) {
    cx_string result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_primitiveKind_o), &value);
    result = cx_valueToString(&v, 0);
    return result;
}

cx_procedure cx_procedure__new(void) {
    return cx_new(cx_type(cx_procedure_o));
}

cx_procedure cx_procedure__declare(cx_object _parent, cx_string _name) {
    return cx_declare(_parent, _name, cx_type(cx_procedure_o));
}

int cx_procedure__define(cx_procedure _this, cx_interface base, cx_modifier baseAccess, cx_procedureKind kind) {
    base ? cx_keep_ext(_this, base, "element <0x7f87a9703178>.base") : 0;
    cx_interface(_this)->base = cx_interface(base);
    cx_struct(_this)->baseAccess = baseAccess;
    _this->kind = kind;
    return cx_define(_this);
}

cx_procedure cx_procedure__create(cx_interface base, cx_modifier baseAccess, cx_procedureKind kind) {
    cx_procedure _this;
    _this = cx_new(cx_type(cx_procedure_o));
    base ? cx_keep_ext(_this, base, "element <0x7f87a9703178>.base") : 0;
    cx_interface(_this)->base = cx_interface(base);
    cx_struct(_this)->baseAccess = baseAccess;
    _this->kind = kind;
    if (cx_define(_this)) {
        cx_free(_this);
        _this = NULL;
    }
    return _this;
}

cx_string cx_procedure__str(cx_procedure value) {
    cx_string result;
    result = cx_toString(value, 0);
    return result;
}

cx_string cx_procedureKind__str(cx_procedureKind value) {
    cx_string result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_procedureKind_o), &value);
    result = cx_valueToString(&v, 0);
    return result;
}

cx_sequence cx_sequence__new(void) {
    return cx_new(cx_type(cx_sequence_o));
}

cx_sequence cx_sequence__declare(cx_object _parent, cx_string _name) {
    return cx_declare(_parent, _name, cx_type(cx_sequence_o));
}

int cx_sequence__define(cx_sequence _this, cx_type elementType, cx_uint32 max) {
    elementType ? cx_keep_ext(_this, elementType, "element <0x7f87a97020a8>.elementType") : 0;
    cx_collection(_this)->elementType = cx_type(elementType);
    cx_collection(_this)->max = max;
    return cx_define(_this);
}

cx_sequence cx_sequence__create(cx_type elementType, cx_uint32 max) {
    cx_sequence _this;
    _this = cx_new(cx_type(cx_sequence_o));
    elementType ? cx_keep_ext(_this, elementType, "element <0x7f87a97020a8>.elementType") : 0;
    cx_collection(_this)->elementType = cx_type(elementType);
    cx_collection(_this)->max = max;
    if (cx_define(_this)) {
        cx_free(_this);
        _this = NULL;
    }
    return _this;
}

cx_string cx_sequence__str(cx_sequence value) {
    cx_string result;
    result = cx_toString(value, 0);
    return result;
}

cx_string cx_state__str(cx_state value) {
    cx_string result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_state_o), &value);
    result = cx_valueToString(&v, 0);
    return result;
}

cx_string cx_string__str(cx_string value) {
    cx_string result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_string_o), &value);
    result = cx_valueToString(&v, 0);
    return result;
}

cx_struct cx_struct__new(void) {
    return cx_new(cx_type(cx_struct_o));
}

cx_struct cx_struct__declare(cx_object _parent, cx_string _name) {
    return cx_declare(_parent, _name, cx_type(cx_struct_o));
}

int cx_struct__define(cx_struct _this, cx_interface base, cx_modifier baseAccess) {
    base ? cx_keep_ext(_this, base, "element <0x7f87a9702148>.base") : 0;
    cx_interface(_this)->base = cx_interface(base);
    _this->baseAccess = baseAccess;
    return cx_define(_this);
}

cx_struct cx_struct__create(cx_interface base, cx_modifier baseAccess) {
    cx_struct _this;
    _this = cx_new(cx_type(cx_struct_o));
    base ? cx_keep_ext(_this, base, "element <0x7f87a9702148>.base") : 0;
    cx_interface(_this)->base = cx_interface(base);
    _this->baseAccess = baseAccess;
    if (cx_define(_this)) {
        cx_free(_this);
        _this = NULL;
    }
    return _this;
}

cx_string cx_struct__str(cx_struct value) {
    cx_string result;
    result = cx_toString(value, 0);
    return result;
}

cx_text cx_text__new(void) {
    return cx_new(cx_type(cx_text_o));
}

cx_text cx_text__declare(cx_object _parent, cx_string _name) {
    return cx_declare(_parent, _name, cx_type(cx_text_o));
}

int cx_text__define(cx_text _this, cx_width charWidth, cx_uint64 length) {
    _this->charWidth = charWidth;
    _this->length = length;
    return cx_define(_this);
}

cx_text cx_text__create(cx_width charWidth, cx_uint64 length) {
    cx_text _this;
    _this = cx_new(cx_type(cx_text_o));
    _this->charWidth = charWidth;
    _this->length = length;
    if (cx_define(_this)) {
        cx_free(_this);
        _this = NULL;
    }
    return _this;
}

cx_string cx_text__str(cx_text value) {
    cx_string result;
    result = cx_toString(value, 0);
    return result;
}

cx_type cx_type__new(void) {
    return cx_new(cx_type(cx_type_o));
}

cx_type cx_type__declare(cx_object _parent, cx_string _name) {
    return cx_declare(_parent, _name, cx_type(cx_type_o));
}

int cx_type__define(cx_type _this, cx_type defaultType, cx_type parentType, cx_state parentState) {
    defaultType ? cx_keep_ext(_this, defaultType, "element <0x7f87a97003b8>.defaultType") : 0;
    _this->defaultType = cx_type(defaultType);
    parentType ? cx_keep_ext(_this, parentType, "element <0x7f87a97003b8>.parentType") : 0;
    _this->parentType = cx_type(parentType);
    _this->parentState = parentState;
    return cx_define(_this);
}

cx_type cx_type__create(cx_type defaultType, cx_type parentType, cx_state parentState) {
    cx_type _this;
    _this = cx_new(cx_type(cx_type_o));
    defaultType ? cx_keep_ext(_this, defaultType, "element <0x7f87a97003b8>.defaultType") : 0;
    _this->defaultType = cx_type(defaultType);
    parentType ? cx_keep_ext(_this, parentType, "element <0x7f87a97003b8>.parentType") : 0;
    _this->parentType = cx_type(parentType);
    _this->parentState = parentState;
    if (cx_define(_this)) {
        cx_free(_this);
        _this = NULL;
    }
    return _this;
}

cx_string cx_type__str(cx_type value) {
    cx_string result;
    result = cx_toString(value, 0);
    return result;
}

cx_string cx_typeKind__str(cx_typeKind value) {
    cx_string result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_typeKind_o), &value);
    result = cx_valueToString(&v, 0);
    return result;
}

cx_uint cx_uint__new(void) {
    return cx_new(cx_type(cx_uint_o));
}

cx_uint cx_uint__declare(cx_object _parent, cx_string _name) {
    return cx_declare(_parent, _name, cx_type(cx_uint_o));
}

int cx_uint__define(cx_uint _this, cx_width width, cx_uint64 min, cx_uint64 max) {
    cx_primitive(_this)->width = width;
    _this->min = min;
    _this->max = max;
    return cx_define(_this);
}

cx_uint cx_uint__create(cx_width width, cx_uint64 min, cx_uint64 max) {
    cx_uint _this;
    _this = cx_new(cx_type(cx_uint_o));
    cx_primitive(_this)->width = width;
    _this->min = min;
    _this->max = max;
    if (cx_define(_this)) {
        cx_free(_this);
        _this = NULL;
    }
    return _this;
}

cx_string cx_uint__str(cx_uint value) {
    cx_string result;
    result = cx_toString(value, 0);
    return result;
}

cx_string cx_uint16__str(cx_uint16 value) {
    cx_string result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_uint16_o), &value);
    result = cx_valueToString(&v, 0);
    return result;
}

cx_string cx_uint32__str(cx_uint32 value) {
    cx_string result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_uint32_o), &value);
    result = cx_valueToString(&v, 0);
    return result;
}

cx_string cx_uint64__str(cx_uint64 value) {
    cx_string result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_uint64_o), &value);
    result = cx_valueToString(&v, 0);
    return result;
}

cx_string cx_uint8__str(cx_uint8 value) {
    cx_string result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_uint8_o), &value);
    result = cx_valueToString(&v, 0);
    return result;
}

cx_virtual cx_virtual__new(void) {
    return cx_new(cx_type(cx_virtual_o));
}

cx_virtual cx_virtual__declare(cx_object _parent, cx_string _name) {
    return cx_declare(_parent, _name, cx_type(cx_virtual_o));
}

int cx_virtual__define(cx_virtual _this, cx_type returnType, cx_bool returnsReference, cx_bool virtual) {
    returnType ? cx_keep_ext(_this, returnType, "element <0x7f87a97003b8>.returnType") : 0;
    cx_function(_this)->returnType = cx_type(returnType);
    cx_function(_this)->returnsReference = returnsReference;
    cx_method(_this)->virtual = virtual;
    return cx_define(_this);
}

cx_virtual cx_virtual__create(cx_type returnType, cx_bool returnsReference, cx_bool virtual) {
    cx_virtual _this;
    _this = cx_new(cx_type(cx_virtual_o));
    returnType ? cx_keep_ext(_this, returnType, "element <0x7f87a97003b8>.returnType") : 0;
    cx_function(_this)->returnType = cx_type(returnType);
    cx_function(_this)->returnsReference = returnsReference;
    cx_method(_this)->virtual = virtual;
    if (cx_define(_this)) {
        cx_free(_this);
        _this = NULL;
    }
    return _this;
}

cx_string cx_virtual__str(cx_virtual value) {
    cx_string result;
    result = cx_toString(value, 0);
    return result;
}

cx_string cx_vtable__str(cx_vtable value) {
    cx_string result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_vtable_o), &value);
    result = cx_valueToString(&v, 0);
    return result;
}

cx_string cx_width__str(cx_width value) {
    cx_string result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_width_o), &value);
    result = cx_valueToString(&v, 0);
    return result;
}

cx_string cx_word__str(cx_word value) {
    cx_string result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_word_o), &value);
    result = cx_valueToString(&v, 0);
    return result;
}

cx_interface cx_interfaceSeq__append(cx_interfaceSeq *seq) {
    cx_uint32 size;
    seq->length++;
    seq->buffer = cx_realloc(seq->buffer, seq->length * (size=cx_type_sizeof(cx_type(cx_interface_o))));
    memset(seq->buffer[seq->length-1], 0, size);
    return seq->buffer[seq->length-1];
}

void cx_interfaceSeq__size(cx_interfaceSeq *seq, cx_uint32 length) {
    cx_uint32 size;
    seq->buffer = cx_realloc(seq->buffer, length * (size=cx_type_sizeof(cx_type(cx_interface_o))));
    if (length > seq->length) {
        cx_uint32 i;
        memset(&seq->buffer[seq->length], 0, size * (length - seq->length));
        for(i=seq->length; i<length; i++) {
            {
                cx_value v;
                cx_valueValueInit(&v, NULL, cx_type(cx_interface_o), &seq->buffer[i]);
                cx_deinitValue(&v);
            }
        }
    }
    seq->length = length;
}

void cx_interfaceSeq__clear(cx_interfaceSeq *seq) {
    cx_interfaceSeq__size(seq, 0);
}

cx_interfaceVector* cx_interfaceVectorSeq__append(cx_interfaceVectorSeq *seq) {
    cx_uint32 size;
    seq->length++;
    seq->buffer = cx_realloc(seq->buffer, seq->length * (size=cx_type_sizeof(cx_type(cx_interfaceVector_o))));
    memset(&seq->buffer[seq->length-1], 0, size);
    {
        cx_value v;
        cx_valueValueInit(&v, NULL, cx_type(cx_interfaceVector_o), &seq->buffer[seq->length-1]);
        cx_initValue(&v);
    }
    return &seq->buffer[seq->length-1];
}

void cx_interfaceVectorSeq__size(cx_interfaceVectorSeq *seq, cx_uint32 length) {
    cx_uint32 size;
    if (length < seq->length) {
        cx_uint32 i;
        for(i=length; i<seq->length; i++) {
            {
                cx_value v;
                cx_valueValueInit(&v, NULL, cx_type(cx_interfaceVector_o), &seq->buffer[i]);
                cx_deinitValue(&v);
            }
        }
    }
    seq->buffer = cx_realloc(seq->buffer, length * (size=cx_type_sizeof(cx_type(cx_interfaceVector_o))));
    if (length > seq->length) {
        cx_uint32 i;
        memset(&seq->buffer[seq->length], 0, size * (length - seq->length));
        for(i=seq->length; i<length; i++) {
            {
                cx_value v;
                cx_valueValueInit(&v, NULL, cx_type(cx_interfaceVector_o), &seq->buffer[i]);
                cx_deinitValue(&v);
            }
        }
    }
    seq->length = length;
}

void cx_interfaceVectorSeq__clear(cx_interfaceVectorSeq *seq) {
    cx_interfaceVectorSeq__size(seq, 0);
}

cx_member cx_memberSeq__append(cx_memberSeq *seq) {
    cx_uint32 size;
    seq->length++;
    seq->buffer = cx_realloc(seq->buffer, seq->length * (size=cx_type_sizeof(cx_type(cx_member_o))));
    memset(seq->buffer[seq->length-1], 0, size);
    return seq->buffer[seq->length-1];
}

void cx_memberSeq__size(cx_memberSeq *seq, cx_uint32 length) {
    cx_uint32 size;
    seq->buffer = cx_realloc(seq->buffer, length * (size=cx_type_sizeof(cx_type(cx_member_o))));
    if (length > seq->length) {
        cx_uint32 i;
        memset(&seq->buffer[seq->length], 0, size * (length - seq->length));
        for(i=seq->length; i<length; i++) {
            {
                cx_value v;
                cx_valueValueInit(&v, NULL, cx_type(cx_member_o), &seq->buffer[i]);
                cx_deinitValue(&v);
            }
        }
    }
    seq->length = length;
}

void cx_memberSeq__clear(cx_memberSeq *seq) {
    cx_memberSeq__size(seq, 0);
}

cx_object cx_objectSeq__append(cx_objectSeq *seq) {
    cx_uint32 size;
    seq->length++;
    seq->buffer = cx_realloc(seq->buffer, seq->length * (size=cx_type_sizeof(cx_type(cx_object_o))));
    memset(seq->buffer[seq->length-1], 0, size);
    return seq->buffer[seq->length-1];
}

void cx_objectSeq__size(cx_objectSeq *seq, cx_uint32 length) {
    cx_uint32 size;
    seq->buffer = cx_realloc(seq->buffer, length * (size=cx_type_sizeof(cx_type(cx_object_o))));
    if (length > seq->length) {
        cx_uint32 i;
        memset(&seq->buffer[seq->length], 0, size * (length - seq->length));
        for(i=seq->length; i<length; i++) {
            {
                cx_value v;
                cx_valueValueInit(&v, NULL, cx_type(cx_object_o), &seq->buffer[i]);
                cx_deinitValue(&v);
            }
        }
    }
    seq->length = length;
}

void cx_objectSeq__clear(cx_objectSeq *seq) {
    cx_objectSeq__size(seq, 0);
}

cx_observer cx_observerSeq__append(cx_observerSeq *seq) {
    cx_uint32 size;
    seq->length++;
    seq->buffer = cx_realloc(seq->buffer, seq->length * (size=cx_type_sizeof(cx_type(cx_observer_o))));
    memset(seq->buffer[seq->length-1], 0, size);
    return seq->buffer[seq->length-1];
}

void cx_observerSeq__size(cx_observerSeq *seq, cx_uint32 length) {
    cx_uint32 size;
    seq->buffer = cx_realloc(seq->buffer, length * (size=cx_type_sizeof(cx_type(cx_observer_o))));
    if (length > seq->length) {
        cx_uint32 i;
        memset(&seq->buffer[seq->length], 0, size * (length - seq->length));
        for(i=seq->length; i<length; i++) {
            {
                cx_value v;
                cx_valueValueInit(&v, NULL, cx_type(cx_observer_o), &seq->buffer[i]);
                cx_deinitValue(&v);
            }
        }
    }
    seq->length = length;
}

void cx_observerSeq__clear(cx_observerSeq *seq) {
    cx_observerSeq__size(seq, 0);
}

cx_parameter* cx_parameterSeq__append(cx_parameterSeq *seq) {
    cx_uint32 size;
    seq->length++;
    seq->buffer = cx_realloc(seq->buffer, seq->length * (size=cx_type_sizeof(cx_type(cx_parameter_o))));
    memset(&seq->buffer[seq->length-1], 0, size);
    {
        cx_value v;
        cx_valueValueInit(&v, NULL, cx_type(cx_parameter_o), &seq->buffer[seq->length-1]);
        cx_initValue(&v);
    }
    return &seq->buffer[seq->length-1];
}

void cx_parameterSeq__size(cx_parameterSeq *seq, cx_uint32 length) {
    cx_uint32 size;
    if (length < seq->length) {
        cx_uint32 i;
        for(i=length; i<seq->length; i++) {
            {
                cx_value v;
                cx_valueValueInit(&v, NULL, cx_type(cx_parameter_o), &seq->buffer[i]);
                cx_deinitValue(&v);
            }
        }
    }
    seq->buffer = cx_realloc(seq->buffer, length * (size=cx_type_sizeof(cx_type(cx_parameter_o))));
    if (length > seq->length) {
        cx_uint32 i;
        memset(&seq->buffer[seq->length], 0, size * (length - seq->length));
        for(i=seq->length; i<length; i++) {
            {
                cx_value v;
                cx_valueValueInit(&v, NULL, cx_type(cx_parameter_o), &seq->buffer[i]);
                cx_deinitValue(&v);
            }
        }
    }
    seq->length = length;
}

void cx_parameterSeq__clear(cx_parameterSeq *seq) {
    cx_parameterSeq__size(seq, 0);
}

cx_function cx_vtable__append(cx_vtable *seq) {
    cx_uint32 size;
    seq->length++;
    seq->buffer = cx_realloc(seq->buffer, seq->length * (size=cx_type_sizeof(cx_type(cx_function_o))));
    memset(seq->buffer[seq->length-1], 0, size);
    return seq->buffer[seq->length-1];
}

void cx_vtable__size(cx_vtable *seq, cx_uint32 length) {
    cx_uint32 size;
    seq->buffer = cx_realloc(seq->buffer, length * (size=cx_type_sizeof(cx_type(cx_function_o))));
    if (length > seq->length) {
        cx_uint32 i;
        memset(&seq->buffer[seq->length], 0, size * (length - seq->length));
        for(i=seq->length; i<length; i++) {
            {
                cx_value v;
                cx_valueValueInit(&v, NULL, cx_type(cx_function_o), &seq->buffer[i]);
                cx_deinitValue(&v);
            }
        }
    }
    seq->length = length;
}

void cx_vtable__clear(cx_vtable *seq) {
    cx_vtable__size(seq, 0);
}

