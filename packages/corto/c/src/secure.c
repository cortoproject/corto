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

corto_secure_accessKind* _corto_secure_accessKindAssign(corto_secure_accessKind* _this, corto_secure_accessKind value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
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

corto_secure_actionKind* _corto_secure_actionKindAssign(corto_secure_actionKind* _this, corto_secure_actionKind value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
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

corto_secure_key _corto_secure_keyAssign(corto_secure_key _this) {
    CORTO_UNUSED(_this);
    return _this;
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

corto_secure_lock _corto_secure_lockCreate(corto_string mount, corto_string expr, int16_t priority) {
    corto_secure_lock _this;
    _this = corto_secure_lock(corto_declare(corto_secure_lock_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_ptr_setstr(&((corto_secure_lock)_this)->mount, mount);
        corto_ptr_setstr(&((corto_secure_lock)_this)->expr, expr);
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
        corto_ptr_setstr(&((corto_secure_lock)_this)->mount, mount);
        corto_ptr_setstr(&((corto_secure_lock)_this)->expr, expr);
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
            corto_ptr_setstr(&((corto_secure_lock)((corto_secure_lock)CORTO_OFFSET(_this, ((corto_type)corto_secure_lock_o)->size)))->mount, mount);
            corto_ptr_setstr(&((corto_secure_lock)((corto_secure_lock)CORTO_OFFSET(_this, ((corto_type)corto_secure_lock_o)->size)))->expr, expr);
            ((corto_secure_lock)((corto_secure_lock)CORTO_OFFSET(_this, ((corto_type)corto_secure_lock_o)->size)))->priority = priority;
        } else {
            corto_ptr_setstr(&((corto_secure_lock)_this)->mount, mount);
            corto_ptr_setstr(&((corto_secure_lock)_this)->expr, expr);
            ((corto_secure_lock)_this)->priority = priority;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_secure_lock _corto_secure_lockAssign(corto_secure_lock _this, corto_string mount, corto_string expr, int16_t priority) {
    CORTO_UNUSED(_this);
    corto_ptr_setstr(&((corto_secure_lock)_this)->mount, mount);
    corto_ptr_setstr(&((corto_secure_lock)_this)->expr, expr);
    ((corto_secure_lock)_this)->priority = priority;
    return _this;
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
    corto_ptr_setstr(&((corto_secure_lock)_this)->mount, mount);
    corto_ptr_setstr(&((corto_secure_lock)_this)->expr, expr);
    ((corto_secure_lock)_this)->priority = priority;
    return corto_define(_this);
}

