/* lang__api.c
 *
 *  Generated on Nov 30 2014
 *    API convenience functions for C-language.
 *    This file contains generated code. Do not modify!
 */

#include "lang__meta.h"
#include "lang__api.h"

db_alias db_alias__new(void) {
    return db_new(db_typedef(db_alias_o));
}

db_alias db_alias__declare(db_object _parent, db_string _name) {
    return db_declare(_parent, _name, db_typedef(db_alias_o));
}

int db_alias__define(db_alias _this, db_string typeName) {
    _this->typeName = (typeName ? db_strdup(typeName) : NULL);
    return db_define(_this);
}

db_alias db_alias__create(db_string typeName) {
    db_alias _this;
    _this = db_new(db_typedef(db_alias_o));
    _this->typeName = (typeName ? db_strdup(typeName) : NULL);
    if (db_define(_this)) {
        db_free(_this);
        _this = NULL;
    }
    return _this;
}

db_array db_array__new(void) {
    return db_new(db_typedef(db_array_o));
}

db_array db_array__declare(db_object _parent, db_string _name) {
    return db_declare(_parent, _name, db_typedef(db_array_o));
}

int db_array__define(db_array _this, db_typedef elementType, db_uint32 max) {
    elementType ? db_keep_ext(_this, elementType, "element <0x9373f78>.elementType") : 0; db_collection(_this)->elementType = elementType;
    db_collection(_this)->max = max;
    return db_define(_this);
}

db_array db_array__create(db_typedef elementType, db_uint32 max) {
    db_array _this;
    _this = db_new(db_typedef(db_array_o));
    elementType ? db_keep_ext(_this, elementType, "element <0x9373f78>.elementType") : 0; db_collection(_this)->elementType = elementType;
    db_collection(_this)->max = max;
    if (db_define(_this)) {
        db_free(_this);
        _this = NULL;
    }
    return _this;
}

db_binary db_binary__new(void) {
    return db_new(db_typedef(db_binary_o));
}

db_binary db_binary__declare(db_object _parent, db_string _name) {
    return db_declare(_parent, _name, db_typedef(db_binary_o));
}

int db_binary__define(db_binary _this, db_width width) {
    db_primitive(_this)->width = width;
    return db_define(_this);
}

db_binary db_binary__create(db_width width) {
    db_binary _this;
    _this = db_new(db_typedef(db_binary_o));
    db_primitive(_this)->width = width;
    if (db_define(_this)) {
        db_free(_this);
        _this = NULL;
    }
    return _this;
}

db_bitmask db_bitmask__new(void) {
    return db_new(db_typedef(db_bitmask_o));
}

db_bitmask db_bitmask__declare(db_object _parent, db_string _name) {
    return db_declare(_parent, _name, db_typedef(db_bitmask_o));
}

int db_bitmask__define(db_bitmask _this) {
    return db_define(_this);
}

db_bitmask db_bitmask__create(void) {
    db_bitmask _this;
    _this = db_new(db_typedef(db_bitmask_o));
    if (db_define(_this)) {
        db_free(_this);
        _this = NULL;
    }
    return _this;
}

db_boolean db_boolean__new(void) {
    return db_new(db_typedef(db_boolean_o));
}

db_boolean db_boolean__declare(db_object _parent, db_string _name) {
    return db_declare(_parent, _name, db_typedef(db_boolean_o));
}

int db_boolean__define(db_boolean _this) {
    return db_define(_this);
}

db_boolean db_boolean__create(void) {
    db_boolean _this;
    _this = db_new(db_typedef(db_boolean_o));
    if (db_define(_this)) {
        db_free(_this);
        _this = NULL;
    }
    return _this;
}

db_callback db_callback__new(void) {
    return db_new(db_typedef(db_callback_o));
}

db_callback db_callback__declare(db_object _parent, db_string _name) {
    return db_declare(_parent, _name, db_typedef(db_callback_o));
}

int db_callback__define(db_callback _this, db_typedef returnType, db_bool returnsReference, db_delegate delegate) {
    returnType ? db_keep_ext(_this, returnType, "element <0x937c6e8>.returnType") : 0; db_function(_this)->returnType = returnType;
    db_function(_this)->returnsReference = returnsReference;
    delegate ? db_keep_ext(_this, delegate, "element <0x937c6e8>.delegate") : 0; _this->delegate = delegate;
    return db_define(_this);
}

db_callback db_callback__create(db_typedef returnType, db_bool returnsReference, db_delegate delegate) {
    db_callback _this;
    _this = db_new(db_typedef(db_callback_o));
    returnType ? db_keep_ext(_this, returnType, "element <0x937c6e8>.returnType") : 0; db_function(_this)->returnType = returnType;
    db_function(_this)->returnsReference = returnsReference;
    delegate ? db_keep_ext(_this, delegate, "element <0x937c6e8>.delegate") : 0; _this->delegate = delegate;
    if (db_define(_this)) {
        db_free(_this);
        _this = NULL;
    }
    return _this;
}

db_character db_character__new(void) {
    return db_new(db_typedef(db_character_o));
}

db_character db_character__declare(db_object _parent, db_string _name) {
    return db_declare(_parent, _name, db_typedef(db_character_o));
}

int db_character__define(db_character _this, db_width width) {
    db_primitive(_this)->width = width;
    return db_define(_this);
}

db_character db_character__create(db_width width) {
    db_character _this;
    _this = db_new(db_typedef(db_character_o));
    db_primitive(_this)->width = width;
    if (db_define(_this)) {
        db_free(_this);
        _this = NULL;
    }
    return _this;
}

db_class db_class__new(void) {
    return db_new(db_typedef(db_class_o));
}

db_class db_class__declare(db_object _parent, db_string _name) {
    return db_declare(_parent, _name, db_typedef(db_class_o));
}

int db_class__define(db_class _this, db_interface base, db_modifier baseAccess, db_interfaceSeq implements) {
    base ? db_keep_ext(_this, base, "element <0x9382730>.base") : 0; db_interface(_this)->base = base;
    db_struct(_this)->baseAccess = baseAccess;
    _this->implements = implements;
    return db_define(_this);
}

db_class db_class__create(db_interface base, db_modifier baseAccess, db_interfaceSeq implements) {
    db_class _this;
    _this = db_new(db_typedef(db_class_o));
    base ? db_keep_ext(_this, base, "element <0x9382730>.base") : 0; db_interface(_this)->base = base;
    db_struct(_this)->baseAccess = baseAccess;
    _this->implements = implements;
    if (db_define(_this)) {
        db_free(_this);
        _this = NULL;
    }
    return _this;
}

db_collection db_collection__new(void) {
    return db_new(db_typedef(db_collection_o));
}

db_collection db_collection__declare(db_object _parent, db_string _name) {
    return db_declare(_parent, _name, db_typedef(db_collection_o));
}

int db_collection__define(db_collection _this, db_typedef elementType, db_uint32 max) {
    elementType ? db_keep_ext(_this, elementType, "element <0x93824d0>.elementType") : 0; _this->elementType = elementType;
    _this->max = max;
    return db_define(_this);
}

db_collection db_collection__create(db_typedef elementType, db_uint32 max) {
    db_collection _this;
    _this = db_new(db_typedef(db_collection_o));
    elementType ? db_keep_ext(_this, elementType, "element <0x93824d0>.elementType") : 0; _this->elementType = elementType;
    _this->max = max;
    if (db_define(_this)) {
        db_free(_this);
        _this = NULL;
    }
    return _this;
}

db_delegate db_delegate__new(void) {
    return db_new(db_typedef(db_delegate_o));
}

db_delegate db_delegate__declare(db_object _parent, db_string _name) {
    return db_declare(_parent, _name, db_typedef(db_delegate_o));
}

int db_delegate__define(db_delegate _this, db_typedef returnType, db_bool returnsReference) {
    returnType ? db_keep_ext(_this, returnType, "element <0x937c6e8>.returnType") : 0; db_function(_this)->returnType = returnType;
    db_function(_this)->returnsReference = returnsReference;
    return db_define(_this);
}

db_delegate db_delegate__create(db_typedef returnType, db_bool returnsReference) {
    db_delegate _this;
    _this = db_new(db_typedef(db_delegate_o));
    returnType ? db_keep_ext(_this, returnType, "element <0x937c6e8>.returnType") : 0; db_function(_this)->returnType = returnType;
    db_function(_this)->returnsReference = returnsReference;
    if (db_define(_this)) {
        db_free(_this);
        _this = NULL;
    }
    return _this;
}

db_dispatcher db_dispatcher__new(void) {
    return db_new(db_typedef(db_dispatcher_o));
}

db_dispatcher db_dispatcher__declare(db_object _parent, db_string _name) {
    return db_declare(_parent, _name, db_typedef(db_dispatcher_o));
}

int db_dispatcher__define(db_dispatcher _this) {
    return db_define(_this);
}

db_dispatcher db_dispatcher__create(void) {
    db_dispatcher _this;
    _this = db_new(db_typedef(db_dispatcher_o));
    if (db_define(_this)) {
        db_free(_this);
        _this = NULL;
    }
    return _this;
}

db_enum db_enum__new(void) {
    return db_new(db_typedef(db_enum_o));
}

db_enum db_enum__declare(db_object _parent, db_string _name) {
    return db_declare(_parent, _name, db_typedef(db_enum_o));
}

int db_enum__define(db_enum _this) {
    return db_define(_this);
}

db_enum db_enum__create(void) {
    db_enum _this;
    _this = db_new(db_typedef(db_enum_o));
    if (db_define(_this)) {
        db_free(_this);
        _this = NULL;
    }
    return _this;
}

db_event db_event__new(void) {
    return db_new(db_typedef(db_event_o));
}

db_event db_event__declare(db_object _parent, db_string _name) {
    return db_declare(_parent, _name, db_typedef(db_event_o));
}

int db_event__define(db_event _this, db_uint16 kind) {
    _this->kind = kind;
    return db_define(_this);
}

db_event db_event__create(db_uint16 kind) {
    db_event _this;
    _this = db_new(db_typedef(db_event_o));
    _this->kind = kind;
    if (db_define(_this)) {
        db_free(_this);
        _this = NULL;
    }
    return _this;
}

db_float db_float__new(void) {
    return db_new(db_typedef(db_float_o));
}

db_float db_float__declare(db_object _parent, db_string _name) {
    return db_declare(_parent, _name, db_typedef(db_float_o));
}

int db_float__define(db_float _this, db_width width, db_float64 min, db_float64 max) {
    db_primitive(_this)->width = width;
    _this->min = min;
    _this->max = max;
    return db_define(_this);
}

db_float db_float__create(db_width width, db_float64 min, db_float64 max) {
    db_float _this;
    _this = db_new(db_typedef(db_float_o));
    db_primitive(_this)->width = width;
    _this->min = min;
    _this->max = max;
    if (db_define(_this)) {
        db_free(_this);
        _this = NULL;
    }
    return _this;
}

db_function db_function__new(void) {
    return db_new(db_typedef(db_function_o));
}

db_function db_function__declare(db_object _parent, db_string _name) {
    return db_declare(_parent, _name, db_typedef(db_function_o));
}

int db_function__define(db_function _this, db_typedef returnType, db_bool returnsReference) {
    returnType ? db_keep_ext(_this, returnType, "element <0x937c6e8>.returnType") : 0; _this->returnType = returnType;
    _this->returnsReference = returnsReference;
    return db_define(_this);
}

db_function db_function__create(db_typedef returnType, db_bool returnsReference) {
    db_function _this;
    _this = db_new(db_typedef(db_function_o));
    returnType ? db_keep_ext(_this, returnType, "element <0x937c6e8>.returnType") : 0; _this->returnType = returnType;
    _this->returnsReference = returnsReference;
    if (db_define(_this)) {
        db_free(_this);
        _this = NULL;
    }
    return _this;
}

db_int db_int__new(void) {
    return db_new(db_typedef(db_int_o));
}

db_int db_int__declare(db_object _parent, db_string _name) {
    return db_declare(_parent, _name, db_typedef(db_int_o));
}

int db_int__define(db_int _this, db_width width, db_int64 min, db_int64 max) {
    db_primitive(_this)->width = width;
    _this->min = min;
    _this->max = max;
    return db_define(_this);
}

db_int db_int__create(db_width width, db_int64 min, db_int64 max) {
    db_int _this;
    _this = db_new(db_typedef(db_int_o));
    db_primitive(_this)->width = width;
    _this->min = min;
    _this->max = max;
    if (db_define(_this)) {
        db_free(_this);
        _this = NULL;
    }
    return _this;
}

db_interface db_interface__new(void) {
    return db_new(db_typedef(db_interface_o));
}

db_interface db_interface__declare(db_object _parent, db_string _name) {
    return db_declare(_parent, _name, db_typedef(db_interface_o));
}

int db_interface__define(db_interface _this, db_interface base) {
    base ? db_keep_ext(_this, base, "element <0x93824d0>.base") : 0; _this->base = base;
    return db_define(_this);
}

db_interface db_interface__create(db_interface base) {
    db_interface _this;
    _this = db_new(db_typedef(db_interface_o));
    base ? db_keep_ext(_this, base, "element <0x93824d0>.base") : 0; _this->base = base;
    if (db_define(_this)) {
        db_free(_this);
        _this = NULL;
    }
    return _this;
}

db_list db_list__new(void) {
    return db_new(db_typedef(db_list_o));
}

db_list db_list__declare(db_object _parent, db_string _name) {
    return db_declare(_parent, _name, db_typedef(db_list_o));
}

int db_list__define(db_list _this, db_typedef elementType, db_uint32 max) {
    elementType ? db_keep_ext(_this, elementType, "element <0x9382448>.elementType") : 0; db_collection(_this)->elementType = elementType;
    db_collection(_this)->max = max;
    return db_define(_this);
}

db_list db_list__create(db_typedef elementType, db_uint32 max) {
    db_list _this;
    _this = db_new(db_typedef(db_list_o));
    elementType ? db_keep_ext(_this, elementType, "element <0x9382448>.elementType") : 0; db_collection(_this)->elementType = elementType;
    db_collection(_this)->max = max;
    if (db_define(_this)) {
        db_free(_this);
        _this = NULL;
    }
    return _this;
}

db_map db_map__new(void) {
    return db_new(db_typedef(db_map_o));
}

db_map db_map__declare(db_object _parent, db_string _name) {
    return db_declare(_parent, _name, db_typedef(db_map_o));
}

int db_map__define(db_map _this, db_typedef elementType, db_typedef keyType, db_uint32 max) {
    elementType ? db_keep_ext(_this, elementType, "element <0x93824d0>.elementType") : 0; _this->elementType = elementType;
    keyType ? db_keep_ext(_this, keyType, "element <0x93824d0>.keyType") : 0; _this->keyType = keyType;
    _this->max = max;
    return db_define(_this);
}

db_map db_map__create(db_typedef elementType, db_typedef keyType, db_uint32 max) {
    db_map _this;
    _this = db_new(db_typedef(db_map_o));
    elementType ? db_keep_ext(_this, elementType, "element <0x93824d0>.elementType") : 0; _this->elementType = elementType;
    keyType ? db_keep_ext(_this, keyType, "element <0x93824d0>.keyType") : 0; _this->keyType = keyType;
    _this->max = max;
    if (db_define(_this)) {
        db_free(_this);
        _this = NULL;
    }
    return _this;
}

db_member db_member__new(void) {
    return db_new(db_typedef(db_member_o));
}

db_member db_member__declare(db_object _parent, db_string _name) {
    return db_declare(_parent, _name, db_typedef(db_member_o));
}

int db_member__define(db_member _this, db_typedef type, db_modifier modifiers, db_state state, db_bool weak) {
    type ? db_keep_ext(_this, type, "element <0x9365b70>.type") : 0; _this->type = type;
    _this->modifiers = modifiers;
    _this->state = state;
    _this->weak = weak;
    return db_define(_this);
}

db_member db_member__create(db_typedef type, db_modifier modifiers, db_state state, db_bool weak) {
    db_member _this;
    _this = db_new(db_typedef(db_member_o));
    type ? db_keep_ext(_this, type, "element <0x9365b70>.type") : 0; _this->type = type;
    _this->modifiers = modifiers;
    _this->state = state;
    _this->weak = weak;
    if (db_define(_this)) {
        db_free(_this);
        _this = NULL;
    }
    return _this;
}

db_metaprocedure db_metaprocedure__new(void) {
    return db_new(db_typedef(db_metaprocedure_o));
}

db_metaprocedure db_metaprocedure__declare(db_object _parent, db_string _name) {
    return db_declare(_parent, _name, db_typedef(db_metaprocedure_o));
}

int db_metaprocedure__define(db_metaprocedure _this, db_typedef returnType, db_bool returnsReference, db_bool referenceOnly) {
    returnType ? db_keep_ext(_this, returnType, "element <0x937c6e8>.returnType") : 0; db_function(_this)->returnType = returnType;
    db_function(_this)->returnsReference = returnsReference;
    _this->referenceOnly = referenceOnly;
    return db_define(_this);
}

db_metaprocedure db_metaprocedure__create(db_typedef returnType, db_bool returnsReference, db_bool referenceOnly) {
    db_metaprocedure _this;
    _this = db_new(db_typedef(db_metaprocedure_o));
    returnType ? db_keep_ext(_this, returnType, "element <0x937c6e8>.returnType") : 0; db_function(_this)->returnType = returnType;
    db_function(_this)->returnsReference = returnsReference;
    _this->referenceOnly = referenceOnly;
    if (db_define(_this)) {
        db_free(_this);
        _this = NULL;
    }
    return _this;
}

db_method db_method__new(void) {
    return db_new(db_typedef(db_method_o));
}

db_method db_method__declare(db_object _parent, db_string _name) {
    return db_declare(_parent, _name, db_typedef(db_method_o));
}

int db_method__define(db_method _this, db_typedef returnType, db_bool returnsReference, db_bool virtual) {
    returnType ? db_keep_ext(_this, returnType, "element <0x937c6e8>.returnType") : 0; db_function(_this)->returnType = returnType;
    db_function(_this)->returnsReference = returnsReference;
    _this->virtual = virtual;
    return db_define(_this);
}

db_method db_method__create(db_typedef returnType, db_bool returnsReference, db_bool virtual) {
    db_method _this;
    _this = db_new(db_typedef(db_method_o));
    returnType ? db_keep_ext(_this, returnType, "element <0x937c6e8>.returnType") : 0; db_function(_this)->returnType = returnType;
    db_function(_this)->returnsReference = returnsReference;
    _this->virtual = virtual;
    if (db_define(_this)) {
        db_free(_this);
        _this = NULL;
    }
    return _this;
}

db_observableEvent db_observableEvent__new(void) {
    return db_new(db_typedef(db_observableEvent_o));
}

db_observableEvent db_observableEvent__declare(db_object _parent, db_string _name) {
    return db_declare(_parent, _name, db_typedef(db_observableEvent_o));
}

int db_observableEvent__define(db_observableEvent _this, db_uint16 kind, db_observer observer, db_object me, db_object source, db_object observable) {
    db_event(_this)->kind = kind;
    observer ? db_keep_ext(_this, observer, "element <0x93744b8>.observer") : 0; _this->observer = observer;
    me ? db_keep_ext(_this, me, "element <0x93744b8>.me") : 0; _this->me = me;
    source ? db_keep_ext(_this, source, "element <0x93744b8>.source") : 0; _this->source = source;
    observable ? db_keep_ext(_this, observable, "element <0x93744b8>.observable") : 0; _this->observable = observable;
    return db_define(_this);
}

db_observableEvent db_observableEvent__create(db_uint16 kind, db_observer observer, db_object me, db_object source, db_object observable) {
    db_observableEvent _this;
    _this = db_new(db_typedef(db_observableEvent_o));
    db_event(_this)->kind = kind;
    observer ? db_keep_ext(_this, observer, "element <0x93744b8>.observer") : 0; _this->observer = observer;
    me ? db_keep_ext(_this, me, "element <0x93744b8>.me") : 0; _this->me = me;
    source ? db_keep_ext(_this, source, "element <0x93744b8>.source") : 0; _this->source = source;
    observable ? db_keep_ext(_this, observable, "element <0x93744b8>.observable") : 0; _this->observable = observable;
    if (db_define(_this)) {
        db_free(_this);
        _this = NULL;
    }
    return _this;
}

db_observer db_observer__new(void) {
    return db_new(db_typedef(db_observer_o));
}

db_observer db_observer__declare(db_object _parent, db_string _name) {
    return db_declare(_parent, _name, db_typedef(db_observer_o));
}

int db_observer__define(db_observer _this, db_object observable, db_eventMask mask, db_string expression, db_uint32 template, db_dispatcher dispatcher, db_object me) {
    observable ? db_keep_ext(_this, observable, "element <0x93824d0>.observable") : 0; _this->observable = observable;
    _this->mask = mask;
    _this->expression = (expression ? db_strdup(expression) : NULL);
    _this->template = template;
    dispatcher ? db_keep_ext(_this, dispatcher, "element <0x93824d0>.dispatcher") : 0; _this->dispatcher = dispatcher;
    me ? db_keep_ext(_this, me, "element <0x93824d0>.me") : 0; _this->me = me;
    return db_define(_this);
}

db_observer db_observer__create(db_object observable, db_eventMask mask, db_string expression, db_uint32 template, db_dispatcher dispatcher, db_object me) {
    db_observer _this;
    _this = db_new(db_typedef(db_observer_o));
    observable ? db_keep_ext(_this, observable, "element <0x93824d0>.observable") : 0; _this->observable = observable;
    _this->mask = mask;
    _this->expression = (expression ? db_strdup(expression) : NULL);
    _this->template = template;
    dispatcher ? db_keep_ext(_this, dispatcher, "element <0x93824d0>.dispatcher") : 0; _this->dispatcher = dispatcher;
    me ? db_keep_ext(_this, me, "element <0x93824d0>.me") : 0; _this->me = me;
    if (db_define(_this)) {
        db_free(_this);
        _this = NULL;
    }
    return _this;
}

db_primitive db_primitive__new(void) {
    return db_new(db_typedef(db_primitive_o));
}

db_primitive db_primitive__declare(db_object _parent, db_string _name) {
    return db_declare(_parent, _name, db_typedef(db_primitive_o));
}

int db_primitive__define(db_primitive _this, db_width width) {
    _this->width = width;
    return db_define(_this);
}

db_primitive db_primitive__create(db_width width) {
    db_primitive _this;
    _this = db_new(db_typedef(db_primitive_o));
    _this->width = width;
    if (db_define(_this)) {
        db_free(_this);
        _this = NULL;
    }
    return _this;
}

db_procedure db_procedure__new(void) {
    return db_new(db_typedef(db_procedure_o));
}

db_procedure db_procedure__declare(db_object _parent, db_string _name) {
    return db_declare(_parent, _name, db_typedef(db_procedure_o));
}

int db_procedure__define(db_procedure _this, db_procedureKind kind) {
    _this->kind = kind;
    return db_define(_this);
}

db_procedure db_procedure__create(db_procedureKind kind) {
    db_procedure _this;
    _this = db_new(db_typedef(db_procedure_o));
    _this->kind = kind;
    if (db_define(_this)) {
        db_free(_this);
        _this = NULL;
    }
    return _this;
}

db_sequence db_sequence__new(void) {
    return db_new(db_typedef(db_sequence_o));
}

db_sequence db_sequence__declare(db_object _parent, db_string _name) {
    return db_declare(_parent, _name, db_typedef(db_sequence_o));
}

int db_sequence__define(db_sequence _this, db_typedef elementType, db_uint32 max) {
    elementType ? db_keep_ext(_this, elementType, "element <0x93824d0>.elementType") : 0; db_collection(_this)->elementType = elementType;
    db_collection(_this)->max = max;
    return db_define(_this);
}

db_sequence db_sequence__create(db_typedef elementType, db_uint32 max) {
    db_sequence _this;
    _this = db_new(db_typedef(db_sequence_o));
    elementType ? db_keep_ext(_this, elementType, "element <0x93824d0>.elementType") : 0; db_collection(_this)->elementType = elementType;
    db_collection(_this)->max = max;
    if (db_define(_this)) {
        db_free(_this);
        _this = NULL;
    }
    return _this;
}

db_struct db_struct__new(void) {
    return db_new(db_typedef(db_struct_o));
}

db_struct db_struct__declare(db_object _parent, db_string _name) {
    return db_declare(_parent, _name, db_typedef(db_struct_o));
}

int db_struct__define(db_struct _this, db_interface base, db_modifier baseAccess) {
    base ? db_keep_ext(_this, base, "element <0x93824d0>.base") : 0; db_interface(_this)->base = base;
    _this->baseAccess = baseAccess;
    return db_define(_this);
}

db_struct db_struct__create(db_interface base, db_modifier baseAccess) {
    db_struct _this;
    _this = db_new(db_typedef(db_struct_o));
    base ? db_keep_ext(_this, base, "element <0x93824d0>.base") : 0; db_interface(_this)->base = base;
    _this->baseAccess = baseAccess;
    if (db_define(_this)) {
        db_free(_this);
        _this = NULL;
    }
    return _this;
}

db_text db_text__new(void) {
    return db_new(db_typedef(db_text_o));
}

db_text db_text__declare(db_object _parent, db_string _name) {
    return db_declare(_parent, _name, db_typedef(db_text_o));
}

int db_text__define(db_text _this, db_width charWidth, db_uint64 length) {
    _this->charWidth = charWidth;
    _this->length = length;
    return db_define(_this);
}

db_text db_text__create(db_width charWidth, db_uint64 length) {
    db_text _this;
    _this = db_new(db_typedef(db_text_o));
    _this->charWidth = charWidth;
    _this->length = length;
    if (db_define(_this)) {
        db_free(_this);
        _this = NULL;
    }
    return _this;
}

db_type db_type__new(void) {
    return db_new(db_typedef(db_type_o));
}

db_type db_type__declare(db_object _parent, db_string _name) {
    return db_declare(_parent, _name, db_typedef(db_type_o));
}

int db_type__define(db_type _this, db_typedef defaultType, db_typedef parentType, db_state parentState) {
    defaultType ? db_keep_ext(_this, defaultType, "element <0x93824d0>.defaultType") : 0; _this->defaultType = defaultType;
    parentType ? db_keep_ext(_this, parentType, "element <0x93824d0>.parentType") : 0; _this->parentType = parentType;
    _this->parentState = parentState;
    return db_define(_this);
}

db_type db_type__create(db_typedef defaultType, db_typedef parentType, db_state parentState) {
    db_type _this;
    _this = db_new(db_typedef(db_type_o));
    defaultType ? db_keep_ext(_this, defaultType, "element <0x93824d0>.defaultType") : 0; _this->defaultType = defaultType;
    parentType ? db_keep_ext(_this, parentType, "element <0x93824d0>.parentType") : 0; _this->parentType = parentType;
    _this->parentState = parentState;
    if (db_define(_this)) {
        db_free(_this);
        _this = NULL;
    }
    return _this;
}

db_typedef db_typedef__new(void) {
    return db_new(db_typedef(db_typedef_o));
}

db_typedef db_typedef__declare(db_object _parent, db_string _name) {
    return db_declare(_parent, _name, db_typedef(db_typedef_o));
}

int db_typedef__define(db_typedef _this, db_typedef type) {
    type ? db_keep_ext(_this, type, "element <0x9365b50>.type") : 0; _this->type = type;
    return db_define(_this);
}

db_typedef db_typedef__create(db_typedef type) {
    db_typedef _this;
    _this = db_new(db_typedef(db_typedef_o));
    type ? db_keep_ext(_this, type, "element <0x9365b50>.type") : 0; _this->type = type;
    if (db_define(_this)) {
        db_free(_this);
        _this = NULL;
    }
    return _this;
}

db_uint db_uint__new(void) {
    return db_new(db_typedef(db_uint_o));
}

db_uint db_uint__declare(db_object _parent, db_string _name) {
    return db_declare(_parent, _name, db_typedef(db_uint_o));
}

int db_uint__define(db_uint _this, db_width width, db_uint64 min, db_uint64 max) {
    db_primitive(_this)->width = width;
    _this->min = min;
    _this->max = max;
    return db_define(_this);
}

db_uint db_uint__create(db_width width, db_uint64 min, db_uint64 max) {
    db_uint _this;
    _this = db_new(db_typedef(db_uint_o));
    db_primitive(_this)->width = width;
    _this->min = min;
    _this->max = max;
    if (db_define(_this)) {
        db_free(_this);
        _this = NULL;
    }
    return _this;
}

db_virtual db_virtual__new(void) {
    return db_new(db_typedef(db_virtual_o));
}

db_virtual db_virtual__declare(db_object _parent, db_string _name) {
    return db_declare(_parent, _name, db_typedef(db_virtual_o));
}

int db_virtual__define(db_virtual _this, db_typedef returnType, db_bool returnsReference, db_bool virtual) {
    returnType ? db_keep_ext(_this, returnType, "element <0x937c6e8>.returnType") : 0; db_function(_this)->returnType = returnType;
    db_function(_this)->returnsReference = returnsReference;
    db_method(_this)->virtual = virtual;
    return db_define(_this);
}

db_virtual db_virtual__create(db_typedef returnType, db_bool returnsReference, db_bool virtual) {
    db_virtual _this;
    _this = db_new(db_typedef(db_virtual_o));
    returnType ? db_keep_ext(_this, returnType, "element <0x937c6e8>.returnType") : 0; db_function(_this)->returnType = returnType;
    db_function(_this)->returnsReference = returnsReference;
    db_method(_this)->virtual = virtual;
    if (db_define(_this)) {
        db_free(_this);
        _this = NULL;
    }
    return _this;
}

db_interface db_interfaceSeq__append(db_interfaceSeq *seq) {
    db_uint32 size;
    seq->length++;
    seq->buffer = db_realloc(seq->buffer, seq->length * (size=db_type_sizeof(db_type(db_interface_o))));
    memset(seq->buffer[seq->length-1], 0, size);
    return seq->buffer[seq->length-1];
}

void db_interfaceSeq__size(db_interfaceSeq *seq, db_uint32 length) {
    db_uint32 size;
    seq->buffer = db_realloc(seq->buffer, length * (size=db_type_sizeof(db_type(db_interface_o))));
    if (length > seq->length) {
        db_uint32 i;
        memset(&seq->buffer[seq->length], 0, size * (length - seq->length));
        for(i=seq->length; i<length; i++) {
            {
                db_value v;
                v.kind = DB_VALUE;
                v.is.value.o = NULL;
                v.is.value.t = db_typedef(db_interface_o);
                v.is.value.v = &seq->buffer[i];
                db_deinitValue(&v);
            }
        }
    }
    seq->length = length;
}

void db_interfaceSeq__clear(db_interfaceSeq *seq) {
    db_interfaceSeq__size(seq, 0);
}

db_interfaceVector* db_interfaceVectorSeq__append(db_interfaceVectorSeq *seq) {
    db_uint32 size;
    seq->length++;
    seq->buffer = db_realloc(seq->buffer, seq->length * (size=db_type_sizeof(db_type(db_interfaceVector_o))));
    memset(&seq->buffer[seq->length-1], 0, size);
    {
        db_value v;
        v.kind = DB_VALUE;
        v.is.value.o = NULL;
        v.is.value.t = db_typedef(db_interfaceVector_o);
        v.is.value.v = &seq->buffer[seq->length-1];
        db_initValue(&v);
    }
    return &seq->buffer[seq->length-1];
}

void db_interfaceVectorSeq__size(db_interfaceVectorSeq *seq, db_uint32 length) {
    db_uint32 size;
    if (length < seq->length) {
        db_uint32 i;
        for(i=length; i<seq->length; i++) {
            {
                db_value v;
                v.kind = DB_VALUE;
                v.is.value.o = NULL;
                v.is.value.t = db_typedef(db_interfaceVector_o);
                v.is.value.v = &seq->buffer[i];
                db_deinitValue(&v);
            }
        }
    }
    seq->buffer = db_realloc(seq->buffer, length * (size=db_type_sizeof(db_type(db_interfaceVector_o))));
    if (length > seq->length) {
        db_uint32 i;
        memset(&seq->buffer[seq->length], 0, size * (length - seq->length));
        for(i=seq->length; i<length; i++) {
            {
                db_value v;
                v.kind = DB_VALUE;
                v.is.value.o = NULL;
                v.is.value.t = db_typedef(db_interfaceVector_o);
                v.is.value.v = &seq->buffer[i];
                db_deinitValue(&v);
            }
        }
    }
    seq->length = length;
}

void db_interfaceVectorSeq__clear(db_interfaceVectorSeq *seq) {
    db_interfaceVectorSeq__size(seq, 0);
}

db_member db_memberSeq__append(db_memberSeq *seq) {
    db_uint32 size;
    seq->length++;
    seq->buffer = db_realloc(seq->buffer, seq->length * (size=db_type_sizeof(db_type(db_member_o))));
    memset(seq->buffer[seq->length-1], 0, size);
    return seq->buffer[seq->length-1];
}

void db_memberSeq__size(db_memberSeq *seq, db_uint32 length) {
    db_uint32 size;
    seq->buffer = db_realloc(seq->buffer, length * (size=db_type_sizeof(db_type(db_member_o))));
    if (length > seq->length) {
        db_uint32 i;
        memset(&seq->buffer[seq->length], 0, size * (length - seq->length));
        for(i=seq->length; i<length; i++) {
            {
                db_value v;
                v.kind = DB_VALUE;
                v.is.value.o = NULL;
                v.is.value.t = db_typedef(db_member_o);
                v.is.value.v = &seq->buffer[i];
                db_deinitValue(&v);
            }
        }
    }
    seq->length = length;
}

void db_memberSeq__clear(db_memberSeq *seq) {
    db_memberSeq__size(seq, 0);
}

db_object db_objectSeq__append(db_objectSeq *seq) {
    db_uint32 size;
    seq->length++;
    seq->buffer = db_realloc(seq->buffer, seq->length * (size=db_type_sizeof(db_type(db_object_o))));
    memset(seq->buffer[seq->length-1], 0, size);
    return seq->buffer[seq->length-1];
}

void db_objectSeq__size(db_objectSeq *seq, db_uint32 length) {
    db_uint32 size;
    seq->buffer = db_realloc(seq->buffer, length * (size=db_type_sizeof(db_type(db_object_o))));
    if (length > seq->length) {
        db_uint32 i;
        memset(&seq->buffer[seq->length], 0, size * (length - seq->length));
        for(i=seq->length; i<length; i++) {
            {
                db_value v;
                v.kind = DB_VALUE;
                v.is.value.o = NULL;
                v.is.value.t = db_typedef(db_object_o);
                v.is.value.v = &seq->buffer[i];
                db_deinitValue(&v);
            }
        }
    }
    seq->length = length;
}

void db_objectSeq__clear(db_objectSeq *seq) {
    db_objectSeq__size(seq, 0);
}

db_observer db_observerSeq__append(db_observerSeq *seq) {
    db_uint32 size;
    seq->length++;
    seq->buffer = db_realloc(seq->buffer, seq->length * (size=db_type_sizeof(db_type(db_observer_o))));
    memset(seq->buffer[seq->length-1], 0, size);
    return seq->buffer[seq->length-1];
}

void db_observerSeq__size(db_observerSeq *seq, db_uint32 length) {
    db_uint32 size;
    seq->buffer = db_realloc(seq->buffer, length * (size=db_type_sizeof(db_type(db_observer_o))));
    if (length > seq->length) {
        db_uint32 i;
        memset(&seq->buffer[seq->length], 0, size * (length - seq->length));
        for(i=seq->length; i<length; i++) {
            {
                db_value v;
                v.kind = DB_VALUE;
                v.is.value.o = NULL;
                v.is.value.t = db_typedef(db_observer_o);
                v.is.value.v = &seq->buffer[i];
                db_deinitValue(&v);
            }
        }
    }
    seq->length = length;
}

void db_observerSeq__clear(db_observerSeq *seq) {
    db_observerSeq__size(seq, 0);
}

db_parameter* db_parameterSeq__append(db_parameterSeq *seq) {
    db_uint32 size;
    seq->length++;
    seq->buffer = db_realloc(seq->buffer, seq->length * (size=db_type_sizeof(db_type(db_parameter_o))));
    memset(&seq->buffer[seq->length-1], 0, size);
    {
        db_value v;
        v.kind = DB_VALUE;
        v.is.value.o = NULL;
        v.is.value.t = db_typedef(db_parameter_o);
        v.is.value.v = &seq->buffer[seq->length-1];
        db_initValue(&v);
    }
    return &seq->buffer[seq->length-1];
}

void db_parameterSeq__size(db_parameterSeq *seq, db_uint32 length) {
    db_uint32 size;
    if (length < seq->length) {
        db_uint32 i;
        for(i=length; i<seq->length; i++) {
            {
                db_value v;
                v.kind = DB_VALUE;
                v.is.value.o = NULL;
                v.is.value.t = db_typedef(db_parameter_o);
                v.is.value.v = &seq->buffer[i];
                db_deinitValue(&v);
            }
        }
    }
    seq->buffer = db_realloc(seq->buffer, length * (size=db_type_sizeof(db_type(db_parameter_o))));
    if (length > seq->length) {
        db_uint32 i;
        memset(&seq->buffer[seq->length], 0, size * (length - seq->length));
        for(i=seq->length; i<length; i++) {
            {
                db_value v;
                v.kind = DB_VALUE;
                v.is.value.o = NULL;
                v.is.value.t = db_typedef(db_parameter_o);
                v.is.value.v = &seq->buffer[i];
                db_deinitValue(&v);
            }
        }
    }
    seq->length = length;
}

void db_parameterSeq__clear(db_parameterSeq *seq) {
    db_parameterSeq__size(seq, 0);
}

db_function db_vtable__append(db_vtable *seq) {
    db_uint32 size;
    seq->length++;
    seq->buffer = db_realloc(seq->buffer, seq->length * (size=db_type_sizeof(db_type(db_function_o))));
    memset(seq->buffer[seq->length-1], 0, size);
    return seq->buffer[seq->length-1];
}

void db_vtable__size(db_vtable *seq, db_uint32 length) {
    db_uint32 size;
    seq->buffer = db_realloc(seq->buffer, length * (size=db_type_sizeof(db_type(db_function_o))));
    if (length > seq->length) {
        db_uint32 i;
        memset(&seq->buffer[seq->length], 0, size * (length - seq->length));
        for(i=seq->length; i<length; i++) {
            {
                db_value v;
                v.kind = DB_VALUE;
                v.is.value.o = NULL;
                v.is.value.t = db_typedef(db_function_o);
                v.is.value.v = &seq->buffer[i];
                db_deinitValue(&v);
            }
        }
    }
    seq->length = length;
}

void db_vtable__clear(db_vtable *seq) {
    db_vtable__size(seq, 0);
}

