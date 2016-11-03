/* _api.c
 *
 * API convenience functions for C-language.
 * This file contains generated code. Do not modify!
 */

#include <corto/corto.h>
corto_native_type _corto_native_typeCreate(corto_string name) {
    corto_native_type _this;
    _this = corto_native_type(corto_declare(corto_native_type_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setstr(&((corto_native_type)_this)->name, name);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_native_type _corto_native_typeCreateChild(corto_object _parent, corto_string _name, corto_string name) {
    corto_native_type _this;
    _this = corto_native_type(corto_declareChild(_parent, _name, corto_native_type_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setstr(&((corto_native_type)_this)->name, name);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_native_typeUpdate(corto_native_type _this, corto_string name) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        corto_setstr(&((corto_native_type)_this)->name, name);
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_native_type _corto_native_typeDeclare(void) {
    corto_native_type _this;
    _this = corto_native_type(corto_declare(corto_native_type_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_native_type _corto_native_typeDeclareChild(corto_object _parent, corto_string _name) {
    corto_native_type _this;
    _this = corto_native_type(corto_declareChild(_parent, _name, corto_native_type_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_native_typeDefine(corto_native_type _this, corto_string name) {
    CORTO_UNUSED(_this);
    corto_setstr(&((corto_native_type)_this)->name, name);
    return corto_define(_this);
}

corto_native_type _corto_native_typeAssign(corto_native_type _this, corto_string name) {
    CORTO_UNUSED(_this);
    corto_setstr(&((corto_native_type)_this)->name, name);
    return _this;
}

corto_string _corto_native_typeStr(corto_native_type value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(corto_native_type_o));
    result = corto_strv(&v, 0);
    return result;
}

corto_native_type corto_native_typeFromStr(corto_native_type value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_native_type_o), str);
    return value;
}

corto_equalityKind _corto_native_typeCompare(corto_native_type dst, corto_native_type src) {
    return corto_compare(dst, src);
}

