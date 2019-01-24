/* native.c
 *
 * API convenience functions for C-language.
 * This file contains generated code. Do not modify!
 */

#include <corto.c>

corto_native_type _corto_native_type__create(corto_object _parent, const char *_id, const char * name, bool is_ptr) {
    corto_native_type _this;
    _this = (corto_native_type)corto_declare(_parent, _id, corto_native_type_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_str(&((corto_native_type)_this)->name, name);
        ((corto_native_type)_this)->is_ptr = is_ptr;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_native_type__update(corto_native_type _this, const char * name, bool is_ptr) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_set_str(&((corto_native_type)((corto_native_type)CORTO_OFFSET(_this, ((corto_type)corto_native_type_o)->size)))->name, name);
            ((corto_native_type)((corto_native_type)CORTO_OFFSET(_this, ((corto_type)corto_native_type_o)->size)))->is_ptr = is_ptr;
        } else {
            corto_set_str(&((corto_native_type)_this)->name, name);
            ((corto_native_type)_this)->is_ptr = is_ptr;
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

corto_native_type _corto_native_type__assign(corto_native_type _this, const char * name, bool is_ptr) {
    CORTO_UNUSED(_this);
    corto_set_str(&((corto_native_type)_this)->name, name);
    ((corto_native_type)_this)->is_ptr = is_ptr;
    return _this;
}
