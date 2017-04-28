/* secure.c
 *
 * API convenience functions for C-language.
 * This file contains generated code. Do not modify!
 */

#include <corto/c/c.h>
#include <corto/secure/_load.h>

corto_secure_accessKind* _corto_secure_accessKindCreate(corto_secure_accessKind value) {
    corto_secure_accessKind* _this;
    _this = corto_secure_accessKind(corto_declare(corto_secure_accessKind_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        *_this = value;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_secure_accessKind* _corto_secure_accessKindCreateChild(corto_object _parent, corto_string _id, corto_secure_accessKind value) {
    corto_secure_accessKind* _this;
    _this = corto_secure_accessKind(corto_declareChild(_parent, _id, corto_secure_accessKind_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        *_this = value;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_secure_accessKindUpdate(corto_secure_accessKind* _this, corto_secure_accessKind value) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            *((corto_secure_accessKind*)CORTO_OFFSET(_this, ((corto_type)corto_secure_accessKind_o)->size)) = value;
        } else {
            *_this = value;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_secure_accessKind* _corto_secure_accessKindDeclare(void) {
    corto_secure_accessKind* _this;
    _this = corto_secure_accessKind(corto_declare(corto_secure_accessKind_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_secure_accessKind* _corto_secure_accessKindDeclareChild(corto_object _parent, corto_string _id) {
    corto_secure_accessKind* _this;
    _this = corto_secure_accessKind(corto_declareChild(_parent, _id, corto_secure_accessKind_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_secure_accessKindDefine(corto_secure_accessKind* _this, corto_secure_accessKind value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return corto_define(_this);
}

corto_secure_accessKind* _corto_secure_accessKindAssign(corto_secure_accessKind* _this, corto_secure_accessKind value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

corto_string _corto_secure_accessKindStr(corto_secure_accessKind value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(&value, corto_type(corto_secure_accessKind_o));
    result = corto_strv(&v, 0);
    return result;
}

corto_secure_accessKind* corto_secure_accessKindFromStr(corto_secure_accessKind* value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_secure_accessKind_o), str);
    return value;
}

corto_equalityKind corto_secure_accessKindCompare(corto_secure_accessKind dst, corto_secure_accessKind src) {
    return corto_comparep(&dst, corto_secure_accessKind_o, &src);
}

corto_int16 _corto_secure_accessKindInit(corto_secure_accessKind* value) {
    corto_int16 result;
    memset(value, 0, corto_type(corto_secure_accessKind_o)->size);
    corto_value v;
    v = corto_value_value(value, corto_type(corto_secure_accessKind_o));
    result = corto_initv(&v);
    return result;
}

corto_int16 _corto_secure_accessKindDeinit(corto_secure_accessKind* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(value, corto_type(corto_secure_accessKind_o));
    result = corto_deinitv(&v);
    return result;
}

corto_secure_actionKind* _corto_secure_actionKindCreate(corto_secure_actionKind value) {
    corto_secure_actionKind* _this;
    _this = corto_secure_actionKind(corto_declare(corto_secure_actionKind_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        *_this = value;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_secure_actionKind* _corto_secure_actionKindCreateChild(corto_object _parent, corto_string _id, corto_secure_actionKind value) {
    corto_secure_actionKind* _this;
    _this = corto_secure_actionKind(corto_declareChild(_parent, _id, corto_secure_actionKind_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        *_this = value;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_secure_actionKindUpdate(corto_secure_actionKind* _this, corto_secure_actionKind value) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            *((corto_secure_actionKind*)CORTO_OFFSET(_this, ((corto_type)corto_secure_actionKind_o)->size)) = value;
        } else {
            *_this = value;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_secure_actionKind* _corto_secure_actionKindDeclare(void) {
    corto_secure_actionKind* _this;
    _this = corto_secure_actionKind(corto_declare(corto_secure_actionKind_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_secure_actionKind* _corto_secure_actionKindDeclareChild(corto_object _parent, corto_string _id) {
    corto_secure_actionKind* _this;
    _this = corto_secure_actionKind(corto_declareChild(_parent, _id, corto_secure_actionKind_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_secure_actionKindDefine(corto_secure_actionKind* _this, corto_secure_actionKind value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return corto_define(_this);
}

corto_secure_actionKind* _corto_secure_actionKindAssign(corto_secure_actionKind* _this, corto_secure_actionKind value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

corto_string _corto_secure_actionKindStr(corto_secure_actionKind value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(&value, corto_type(corto_secure_actionKind_o));
    result = corto_strv(&v, 0);
    return result;
}

corto_secure_actionKind* corto_secure_actionKindFromStr(corto_secure_actionKind* value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_secure_actionKind_o), str);
    return value;
}

corto_equalityKind corto_secure_actionKindCompare(corto_secure_actionKind dst, corto_secure_actionKind src) {
    return corto_comparep(&dst, corto_secure_actionKind_o, &src);
}

corto_int16 _corto_secure_actionKindInit(corto_secure_actionKind* value) {
    corto_int16 result;
    memset(value, 0, corto_type(corto_secure_actionKind_o)->size);
    corto_value v;
    v = corto_value_value(value, corto_type(corto_secure_actionKind_o));
    result = corto_initv(&v);
    return result;
}

corto_int16 _corto_secure_actionKindDeinit(corto_secure_actionKind* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(value, corto_type(corto_secure_actionKind_o));
    result = corto_deinitv(&v);
    return result;
}

corto_secure_key _corto_secure_keyCreate(void) {
    corto_secure_key _this;
    _this = corto_secure_key(corto_declare(corto_secure_key_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_secure_key _corto_secure_keyCreateChild(corto_object _parent, corto_string _id) {
    corto_secure_key _this;
    _this = corto_secure_key(corto_declareChild(_parent, _id, corto_secure_key_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_secure_keyUpdate(corto_secure_key _this) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
        } else {
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_secure_key _corto_secure_keyDeclare(void) {
    corto_secure_key _this;
    _this = corto_secure_key(corto_declare(corto_secure_key_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_secure_key _corto_secure_keyDeclareChild(corto_object _parent, corto_string _id) {
    corto_secure_key _this;
    _this = corto_secure_key(corto_declareChild(_parent, _id, corto_secure_key_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_secure_keyDefine(corto_secure_key _this) {
    CORTO_UNUSED(_this);
    return corto_define(_this);
}

corto_secure_key _corto_secure_keyAssign(corto_secure_key _this) {
    CORTO_UNUSED(_this);
    return _this;
}

corto_string _corto_secure_keyStr(corto_secure_key value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(corto_secure_key_o));
    result = corto_strv(&v, 0);
    return result;
}

corto_secure_key corto_secure_keyFromStr(corto_secure_key value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_secure_key_o), str);
    return value;
}

corto_equalityKind _corto_secure_keyCompare(corto_secure_key dst, corto_secure_key src) {
    return corto_compare(dst, src);
}

corto_secure_lock _corto_secure_lockCreate(corto_string mount, corto_string expr, int16_t priority) {
    corto_secure_lock _this;
    _this = corto_secure_lock(corto_declare(corto_secure_lock_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setstr(&((corto_secure_lock)_this)->mount, mount);
        corto_setstr(&((corto_secure_lock)_this)->expr, expr);
        ((corto_secure_lock)_this)->priority = priority;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_secure_lock _corto_secure_lockCreateChild(corto_object _parent, corto_string _id, corto_string mount, corto_string expr, int16_t priority) {
    corto_secure_lock _this;
    _this = corto_secure_lock(corto_declareChild(_parent, _id, corto_secure_lock_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setstr(&((corto_secure_lock)_this)->mount, mount);
        corto_setstr(&((corto_secure_lock)_this)->expr, expr);
        ((corto_secure_lock)_this)->priority = priority;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_secure_lockUpdate(corto_secure_lock _this, corto_string mount, corto_string expr, int16_t priority) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_setstr(&((corto_secure_lock)((corto_secure_lock)CORTO_OFFSET(_this, ((corto_type)corto_secure_lock_o)->size)))->mount, mount);
            corto_setstr(&((corto_secure_lock)((corto_secure_lock)CORTO_OFFSET(_this, ((corto_type)corto_secure_lock_o)->size)))->expr, expr);
            ((corto_secure_lock)((corto_secure_lock)CORTO_OFFSET(_this, ((corto_type)corto_secure_lock_o)->size)))->priority = priority;
        } else {
            corto_setstr(&((corto_secure_lock)_this)->mount, mount);
            corto_setstr(&((corto_secure_lock)_this)->expr, expr);
            ((corto_secure_lock)_this)->priority = priority;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_secure_lock _corto_secure_lockDeclare(void) {
    corto_secure_lock _this;
    _this = corto_secure_lock(corto_declare(corto_secure_lock_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_secure_lock _corto_secure_lockDeclareChild(corto_object _parent, corto_string _id) {
    corto_secure_lock _this;
    _this = corto_secure_lock(corto_declareChild(_parent, _id, corto_secure_lock_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_secure_lockDefine(corto_secure_lock _this, corto_string mount, corto_string expr, int16_t priority) {
    CORTO_UNUSED(_this);
    corto_setstr(&((corto_secure_lock)_this)->mount, mount);
    corto_setstr(&((corto_secure_lock)_this)->expr, expr);
    ((corto_secure_lock)_this)->priority = priority;
    return corto_define(_this);
}

corto_secure_lock _corto_secure_lockAssign(corto_secure_lock _this, corto_string mount, corto_string expr, int16_t priority) {
    CORTO_UNUSED(_this);
    corto_setstr(&((corto_secure_lock)_this)->mount, mount);
    corto_setstr(&((corto_secure_lock)_this)->expr, expr);
    ((corto_secure_lock)_this)->priority = priority;
    return _this;
}

corto_string _corto_secure_lockStr(corto_secure_lock value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(corto_secure_lock_o));
    result = corto_strv(&v, 0);
    return result;
}

corto_secure_lock corto_secure_lockFromStr(corto_secure_lock value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_secure_lock_o), str);
    return value;
}

corto_equalityKind _corto_secure_lockCompare(corto_secure_lock dst, corto_secure_lock src) {
    return corto_compare(dst, src);
}

