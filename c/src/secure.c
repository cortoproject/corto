/* secure.c
 *
 * API convenience functions for C-language.
 * This file contains generated code. Do not modify!
 */

#include <corto/c/c.h>

corto_secure_accessKind* _corto_secure_accessKind__create(corto_object _parent, const char *_id, corto_secure_accessKind value) {
    corto_secure_accessKind* _this;
    _this = (corto_secure_accessKind*)corto_declare(_parent, _id, corto_secure_accessKind_o);
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

corto_int16 _corto_secure_accessKind__update(corto_secure_accessKind* _this, corto_secure_accessKind value) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            *((corto_secure_accessKind*)CORTO_OFFSET(_this, ((corto_type)corto_secure_accessKind_o)->size)) = value;
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

corto_secure_accessKind* _corto_secure_accessKind__assign(corto_secure_accessKind* _this, corto_secure_accessKind value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

corto_secure_actionKind* _corto_secure_actionKind__create(corto_object _parent, const char *_id, corto_secure_actionKind value) {
    corto_secure_actionKind* _this;
    _this = (corto_secure_actionKind*)corto_declare(_parent, _id, corto_secure_actionKind_o);
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

corto_int16 _corto_secure_actionKind__update(corto_secure_actionKind* _this, corto_secure_actionKind value) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            *((corto_secure_actionKind*)CORTO_OFFSET(_this, ((corto_type)corto_secure_actionKind_o)->size)) = value;
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

corto_secure_actionKind* _corto_secure_actionKind__assign(corto_secure_actionKind* _this, corto_secure_actionKind value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

corto_secure_key _corto_secure_key__create(corto_object _parent, const char *_id) {
    corto_secure_key _this;
    _this = (corto_secure_key)corto_declare(_parent, _id, corto_secure_key_o);
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

corto_int16 _corto_secure_key__update(corto_secure_key _this) {
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

corto_secure_key _corto_secure_key__assign(corto_secure_key _this) {
    CORTO_UNUSED(_this);
    return _this;
}

corto_secure_lock _corto_secure_lock__create(corto_object _parent, const char *_id, const char * mount, const char * expr, int16_t priority) {
    corto_secure_lock _this;
    _this = (corto_secure_lock)corto_declare(_parent, _id, corto_secure_lock_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_str(&((corto_secure_lock)_this)->mount, mount);
        corto_set_str(&((corto_secure_lock)_this)->expr, expr);
        ((corto_secure_lock)_this)->priority = priority;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_secure_lock__update(corto_secure_lock _this, const char * mount, const char * expr, int16_t priority) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_set_str(&((corto_secure_lock)((corto_secure_lock)CORTO_OFFSET(_this, ((corto_type)corto_secure_lock_o)->size)))->mount, mount);
            corto_set_str(&((corto_secure_lock)((corto_secure_lock)CORTO_OFFSET(_this, ((corto_type)corto_secure_lock_o)->size)))->expr, expr);
            ((corto_secure_lock)((corto_secure_lock)CORTO_OFFSET(_this, ((corto_type)corto_secure_lock_o)->size)))->priority = priority;
        } else {
            corto_set_str(&((corto_secure_lock)_this)->mount, mount);
            corto_set_str(&((corto_secure_lock)_this)->expr, expr);
            ((corto_secure_lock)_this)->priority = priority;
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

corto_secure_lock _corto_secure_lock__assign(corto_secure_lock _this, const char * mount, const char * expr, int16_t priority) {
    CORTO_UNUSED(_this);
    corto_set_str(&((corto_secure_lock)_this)->mount, mount);
    corto_set_str(&((corto_secure_lock)_this)->expr, expr);
    ((corto_secure_lock)_this)->priority = priority;
    return _this;
}

