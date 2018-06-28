/* vstore.c
 *
 * API convenience functions for C-language.
 * This file contains generated code. Do not modify!
 */

#include <corto/c/c.h>

corto_dispatcher _corto_dispatcher__create(corto_object _parent, const char *_id) {
    corto_dispatcher _this;
    _this = (corto_dispatcher)corto_declare(_parent, _id, corto_dispatcher_o);
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

corto_int16 _corto_dispatcher__update(corto_dispatcher _this) {
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

corto_dispatcher _corto_dispatcher__assign(corto_dispatcher _this) {
    CORTO_UNUSED(_this);
    return _this;
}

corto_event* _corto_event__create(corto_object _parent, const char *_id) {
    corto_event* _this;
    _this = (corto_event*)corto_declare(_parent, _id, corto_event_o);
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

corto_int16 _corto_event__update(corto_event* _this) {
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

corto_event* _corto_event__assign(corto_event* _this) {
    CORTO_UNUSED(_this);
    return _this;
}

corto_eventMask* _corto_eventMask__create(corto_object _parent, const char *_id, corto_eventMask value) {
    corto_eventMask* _this;
    _this = (corto_eventMask*)corto_declare(_parent, _id, corto_eventMask_o);
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

corto_int16 _corto_eventMask__update(corto_eventMask* _this, corto_eventMask value) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            *((corto_eventMask*)CORTO_OFFSET(_this, ((corto_type)corto_eventMask_o)->size)) = value;
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

corto_eventMask* _corto_eventMask__assign(corto_eventMask* _this, corto_eventMask value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

corto_fmt_data* _corto_fmt_data__create(corto_object _parent, const char *_id) {
    corto_fmt_data* _this;
    _this = (corto_fmt_data*)corto_declare(_parent, _id, corto_fmt_data_o);
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

corto_int16 _corto_fmt_data__update(corto_fmt_data* _this) {
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

corto_fmt_data* _corto_fmt_data__assign(corto_fmt_data* _this) {
    CORTO_UNUSED(_this);
    return _this;
}

corto_frame* _corto_frame__create(corto_object _parent, const char *_id, corto_frameKind kind, int64_t value) {
    corto_frame* _this;
    _this = (corto_frame*)corto_declare(_parent, _id, corto_frame_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        ((corto_frame*)_this)->kind = kind;
        ((corto_frame*)_this)->value = value;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_frame__update(corto_frame* _this, corto_frameKind kind, int64_t value) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            ((corto_frame*)((corto_frame*)CORTO_OFFSET(_this, ((corto_type)corto_frame_o)->size)))->kind = kind;
            ((corto_frame*)((corto_frame*)CORTO_OFFSET(_this, ((corto_type)corto_frame_o)->size)))->value = value;
        } else {
            ((corto_frame*)_this)->kind = kind;
            ((corto_frame*)_this)->value = value;
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

corto_frame* _corto_frame__assign(corto_frame* _this, corto_frameKind kind, int64_t value) {
    CORTO_UNUSED(_this);
    ((corto_frame*)_this)->kind = kind;
    ((corto_frame*)_this)->value = value;
    return _this;
}

corto_frameKind* _corto_frameKind__create(corto_object _parent, const char *_id, corto_frameKind value) {
    corto_frameKind* _this;
    _this = (corto_frameKind*)corto_declare(_parent, _id, corto_frameKind_o);
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

corto_int16 _corto_frameKind__update(corto_frameKind* _this, corto_frameKind value) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            *((corto_frameKind*)CORTO_OFFSET(_this, ((corto_type)corto_frameKind_o)->size)) = value;
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

corto_frameKind* _corto_frameKind__assign(corto_frameKind* _this, corto_frameKind value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

corto_handleAction* _corto_handleAction__create(corto_object _parent, const char *_id, corto_object instance, corto_function procedure) {
    corto_handleAction* _this;
    _this = (corto_handleAction*)corto_declare(_parent, _id, corto_handleAction_o);
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

corto_int16 _corto_handleAction__update(corto_handleAction* _this, corto_object instance, corto_function procedure) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_set_ref(&((corto_delegatedata*)((corto_handleAction*)CORTO_OFFSET(_this, ((corto_type)corto_handleAction_o)->size)))->instance, instance);
            corto_set_ref(&((corto_delegatedata*)((corto_handleAction*)CORTO_OFFSET(_this, ((corto_type)corto_handleAction_o)->size)))->procedure, procedure);
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

corto_handleAction* _corto_handleAction__assign(corto_handleAction* _this, corto_object instance, corto_function procedure) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_delegatedata*)_this)->instance, instance);
    corto_set_ref(&((corto_delegatedata*)_this)->procedure, procedure);
    return _this;
}

corto_int16 corto_handleAction__call(corto_handleAction *_delegate, corto_event * event) {
    if (_delegate->super.procedure) {
        if (_delegate->super.instance) {
            corto_invoke(_delegate->super.procedure, NULL, _delegate->super.instance, event);
        } else {
            corto_invoke(_delegate->super.procedure, NULL, event);
        }
    } else {
        return -1;
    }
    return 0;
}

corto_int16 corto_handleAction__init_c(corto_handleAction *d, corto_void ___ (*callback)(corto_event*)) {
    d->super.instance = NULL;
    d->super.procedure = corto_declare(NULL, NULL, corto_function_o);
    d->super.procedure->kind = CORTO_PROCEDURE_CDECL;
    corto_set_ref(&d->super.procedure->returnType, corto_void_o);
    corto_function_parseParamString(d->super.procedure, "(/corto/vstore/event event)");
    d->super.procedure->fptr = (corto_word)callback;
    corto_define(d->super.procedure);
    return 0;
}

corto_int16 corto_handleAction_init_c_instance(corto_handleAction *d, corto_object instance, corto_void ___ (*callback)(corto_object, corto_event*)) {
    d->super.instance = instance;
    corto_claim(instance);
    d->super.procedure = corto_declare(NULL, NULL, corto_function_o);
    d->super.procedure->kind = CORTO_PROCEDURE_CDECL;
    corto_set_ref(&d->super.procedure->returnType, corto_void_o);
    corto_function_parseParamString(d->super.procedure, "(object instance, /corto/vstore/event event)");
    d->super.procedure->fptr = (corto_word)callback;
    corto_define(d->super.procedure);
    return 0;
}

corto_invoke_event* _corto_invoke_event__create(corto_object _parent, const char *_id, corto_mount mount, corto_object instance, corto_function function, uintptr_t args) {
    corto_invoke_event* _this;
    _this = (corto_invoke_event*)corto_declare(_parent, _id, corto_invoke_event_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_ref(&((corto_invoke_event*)_this)->mount, mount);
        corto_set_ref(&((corto_invoke_event*)_this)->instance, instance);
        corto_set_ref(&((corto_invoke_event*)_this)->function, function);
        ((corto_invoke_event*)_this)->args = args;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_invoke_event__update(corto_invoke_event* _this, corto_mount mount, corto_object instance, corto_function function, uintptr_t args) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_set_ref(&((corto_invoke_event*)((corto_invoke_event*)CORTO_OFFSET(_this, ((corto_type)corto_invoke_event_o)->size)))->mount, mount);
            corto_set_ref(&((corto_invoke_event*)((corto_invoke_event*)CORTO_OFFSET(_this, ((corto_type)corto_invoke_event_o)->size)))->instance, instance);
            corto_set_ref(&((corto_invoke_event*)((corto_invoke_event*)CORTO_OFFSET(_this, ((corto_type)corto_invoke_event_o)->size)))->function, function);
            ((corto_invoke_event*)((corto_invoke_event*)CORTO_OFFSET(_this, ((corto_type)corto_invoke_event_o)->size)))->args = args;
        } else {
            corto_set_ref(&((corto_invoke_event*)_this)->mount, mount);
            corto_set_ref(&((corto_invoke_event*)_this)->instance, instance);
            corto_set_ref(&((corto_invoke_event*)_this)->function, function);
            ((corto_invoke_event*)_this)->args = args;
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

corto_invoke_event* _corto_invoke_event__assign(corto_invoke_event* _this, corto_mount mount, corto_object instance, corto_function function, uintptr_t args) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_invoke_event*)_this)->mount, mount);
    corto_set_ref(&((corto_invoke_event*)_this)->instance, instance);
    corto_set_ref(&((corto_invoke_event*)_this)->function, function);
    ((corto_invoke_event*)_this)->args = args;
    return _this;
}

corto_loader _corto_loader__create(corto_object _parent, const char *_id, bool autoLoad) {
    corto_loader _this;
    _this = (corto_loader)corto_declare(_parent, _id, corto_loader_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        ((corto_loader)_this)->autoLoad = autoLoad;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_loader__update(corto_loader _this, bool autoLoad) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            ((corto_loader)((corto_loader)CORTO_OFFSET(_this, ((corto_type)corto_loader_o)->size)))->autoLoad = autoLoad;
        } else {
            ((corto_loader)_this)->autoLoad = autoLoad;
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

corto_loader _corto_loader__assign(corto_loader _this, bool autoLoad) {
    CORTO_UNUSED(_this);
    ((corto_loader)_this)->autoLoad = autoLoad;
    return _this;
}

corto_mount _corto_mount__create(corto_object _parent, const char *_id) {
    corto_mount _this;
    _this = (corto_mount)corto_declare(_parent, _id, corto_mount_o);
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

corto_int16 _corto_mount__update(corto_mount _this) {
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

corto_mount _corto_mount__assign(corto_mount _this) {
    CORTO_UNUSED(_this);
    return _this;
}

corto_mount_subscription* _corto_mount_subscription__create(corto_object _parent, const char *_id, corto_query* query, uint32_t mountCount, uint32_t subscriberCount, uintptr_t mountCtx, uintptr_t subscriberCtx) {
    corto_mount_subscription* _this;
    _this = (corto_mount_subscription*)corto_declare(_parent, _id, corto_mount_subscription_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        if (query) {
            corto_ptr_copy(&((corto_mount_subscription*)_this)->query, corto_query_o, query);
        }
        ((corto_mount_subscription*)_this)->mountCount = mountCount;
        ((corto_mount_subscription*)_this)->subscriberCount = subscriberCount;
        ((corto_mount_subscription*)_this)->mountCtx = mountCtx;
        ((corto_mount_subscription*)_this)->subscriberCtx = subscriberCtx;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_mount_subscription__update(corto_mount_subscription* _this, corto_query* query, uint32_t mountCount, uint32_t subscriberCount, uintptr_t mountCtx, uintptr_t subscriberCtx) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            if (query) {
                corto_ptr_copy(&((corto_mount_subscription*)((corto_mount_subscription*)CORTO_OFFSET(_this, ((corto_type)corto_mount_subscription_o)->size)))->query, corto_query_o, query);
            }
            ((corto_mount_subscription*)((corto_mount_subscription*)CORTO_OFFSET(_this, ((corto_type)corto_mount_subscription_o)->size)))->mountCount = mountCount;
            ((corto_mount_subscription*)((corto_mount_subscription*)CORTO_OFFSET(_this, ((corto_type)corto_mount_subscription_o)->size)))->subscriberCount = subscriberCount;
            ((corto_mount_subscription*)((corto_mount_subscription*)CORTO_OFFSET(_this, ((corto_type)corto_mount_subscription_o)->size)))->mountCtx = mountCtx;
            ((corto_mount_subscription*)((corto_mount_subscription*)CORTO_OFFSET(_this, ((corto_type)corto_mount_subscription_o)->size)))->subscriberCtx = subscriberCtx;
        } else {
            if (query) {
                corto_ptr_copy(&((corto_mount_subscription*)_this)->query, corto_query_o, query);
            }
            ((corto_mount_subscription*)_this)->mountCount = mountCount;
            ((corto_mount_subscription*)_this)->subscriberCount = subscriberCount;
            ((corto_mount_subscription*)_this)->mountCtx = mountCtx;
            ((corto_mount_subscription*)_this)->subscriberCtx = subscriberCtx;
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

corto_mount_subscription* _corto_mount_subscription__assign(corto_mount_subscription* _this, corto_query* query, uint32_t mountCount, uint32_t subscriberCount, uintptr_t mountCtx, uintptr_t subscriberCtx) {
    CORTO_UNUSED(_this);
    if (query) {
        corto_ptr_copy(&((corto_mount_subscription*)_this)->query, corto_query_o, query);
    }
    ((corto_mount_subscription*)_this)->mountCount = mountCount;
    ((corto_mount_subscription*)_this)->subscriberCount = subscriberCount;
    ((corto_mount_subscription*)_this)->mountCtx = mountCtx;
    ((corto_mount_subscription*)_this)->subscriberCtx = subscriberCtx;
    return _this;
}

corto_mount_subscriptionList* _corto_mount_subscriptionList__create(corto_object _parent, const char *_id, corto_uint32 length, corto_mount_subscription* elements) {
    corto_mount_subscriptionList* _this;
    _this = (corto_mount_subscriptionList*)corto_declare(_parent, _id, corto_mount_subscriptionList_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_uint32 i = 0;
        corto_mount_subscriptionList__clear(*_this);
        for (i = 0; i < length; i ++) {
            corto_mount_subscriptionList__append(*_this, &elements[i]);
        }
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_mount_subscriptionList__update(corto_mount_subscriptionList* _this, corto_uint32 length, corto_mount_subscription* elements) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_uint32 i = 0;
            corto_mount_subscriptionList__clear(*((corto_mount_subscriptionList*)CORTO_OFFSET(_this, ((corto_type)corto_mount_subscriptionList_o)->size)));
            for (i = 0; i < length; i ++) {
                corto_mount_subscriptionList__append(*((corto_mount_subscriptionList*)CORTO_OFFSET(_this, ((corto_type)corto_mount_subscriptionList_o)->size)), &elements[i]);
            }
        } else {
            corto_uint32 i = 0;
            corto_mount_subscriptionList__clear(*_this);
            for (i = 0; i < length; i ++) {
                corto_mount_subscriptionList__append(*_this, &elements[i]);
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

corto_mount_subscriptionList* _corto_mount_subscriptionList__assign(corto_mount_subscriptionList* _this, corto_uint32 length, corto_mount_subscription* elements) {
    CORTO_UNUSED(_this);
    corto_uint32 i = 0;
    corto_mount_subscriptionList__clear(*_this);
    for (i = 0; i < length; i ++) {
        corto_mount_subscriptionList__append(*_this, &elements[i]);
    }
    return _this;
}

corto_mountCallbackMask* _corto_mountCallbackMask__create(corto_object _parent, const char *_id, corto_mountCallbackMask value) {
    corto_mountCallbackMask* _this;
    _this = (corto_mountCallbackMask*)corto_declare(_parent, _id, corto_mountCallbackMask_o);
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

corto_int16 _corto_mountCallbackMask__update(corto_mountCallbackMask* _this, corto_mountCallbackMask value) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            *((corto_mountCallbackMask*)CORTO_OFFSET(_this, ((corto_type)corto_mountCallbackMask_o)->size)) = value;
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

corto_mountCallbackMask* _corto_mountCallbackMask__assign(corto_mountCallbackMask* _this, corto_mountCallbackMask value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

corto_objectIter* _corto_objectIter__create(corto_object _parent, const char *_id) {
    corto_objectIter* _this;
    _this = (corto_objectIter*)corto_declare(_parent, _id, corto_objectIter_o);
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

corto_int16 _corto_objectIter__update(corto_objectIter* _this) {
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

corto_objectIter* _corto_objectIter__assign(corto_objectIter* _this) {
    CORTO_UNUSED(_this);
    return _this;
}

corto_observer _corto_observer__create(corto_object _parent, const char *_id, corto_eventMask mask, corto_object observable, corto_object instance, corto_dispatcher dispatcher, corto_type type, bool enabled, void(*_impl)(void)) {
    corto_observer _this;
    _this = (corto_observer)corto_declare(_parent, _id, corto_observer_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        ((corto_observer)_this)->mask = mask;
        corto_set_ref(&((corto_observer)_this)->observable, observable);
        corto_set_ref(&((corto_observer)_this)->instance, instance);
        corto_set_ref(&((corto_observer)_this)->dispatcher, dispatcher);
        corto_set_ref(&((corto_observer)_this)->type, type);
        ((corto_observer)_this)->enabled = enabled;
        corto_function(_this)->kind = CORTO_PROCEDURE_CDECL;
        corto_function(_this)->fptr = (corto_word)_impl;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_observer__update(corto_observer _this, corto_eventMask mask, corto_object observable, corto_object instance, corto_dispatcher dispatcher, corto_type type, bool enabled, void(*_impl)(void)) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            ((corto_observer)((corto_observer)CORTO_OFFSET(_this, ((corto_type)corto_observer_o)->size)))->mask = mask;
            corto_set_ref(&((corto_observer)((corto_observer)CORTO_OFFSET(_this, ((corto_type)corto_observer_o)->size)))->observable, observable);
            corto_set_ref(&((corto_observer)((corto_observer)CORTO_OFFSET(_this, ((corto_type)corto_observer_o)->size)))->instance, instance);
            corto_set_ref(&((corto_observer)((corto_observer)CORTO_OFFSET(_this, ((corto_type)corto_observer_o)->size)))->dispatcher, dispatcher);
            corto_set_ref(&((corto_observer)((corto_observer)CORTO_OFFSET(_this, ((corto_type)corto_observer_o)->size)))->type, type);
            ((corto_observer)((corto_observer)CORTO_OFFSET(_this, ((corto_type)corto_observer_o)->size)))->enabled = enabled;
            corto_function(((corto_observer)CORTO_OFFSET(_this, ((corto_type)corto_observer_o)->size)))->kind = CORTO_PROCEDURE_CDECL;
            corto_function(((corto_observer)CORTO_OFFSET(_this, ((corto_type)corto_observer_o)->size)))->fptr = (corto_word)_impl;
        } else {
            ((corto_observer)_this)->mask = mask;
            corto_set_ref(&((corto_observer)_this)->observable, observable);
            corto_set_ref(&((corto_observer)_this)->instance, instance);
            corto_set_ref(&((corto_observer)_this)->dispatcher, dispatcher);
            corto_set_ref(&((corto_observer)_this)->type, type);
            ((corto_observer)_this)->enabled = enabled;
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

corto_observer _corto_observer__assign(corto_observer _this, corto_eventMask mask, corto_object observable, corto_object instance, corto_dispatcher dispatcher, corto_type type, bool enabled, void(*_impl)(void)) {
    CORTO_UNUSED(_this);
    ((corto_observer)_this)->mask = mask;
    corto_set_ref(&((corto_observer)_this)->observable, observable);
    corto_set_ref(&((corto_observer)_this)->instance, instance);
    corto_set_ref(&((corto_observer)_this)->dispatcher, dispatcher);
    corto_set_ref(&((corto_observer)_this)->type, type);
    ((corto_observer)_this)->enabled = enabled;
    corto_function(_this)->kind = CORTO_PROCEDURE_CDECL;
    corto_function(_this)->fptr = (corto_word)_impl;
    return _this;
}

corto_observer_event* _corto_observer_event__create(corto_object _parent, const char *_id, corto_observer observer, corto_object instance, corto_object source, corto_eventMask event, corto_object data, uintptr_t thread) {
    corto_observer_event* _this;
    _this = (corto_observer_event*)corto_declare(_parent, _id, corto_observer_event_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_ref(&((corto_observer_event*)_this)->observer, observer);
        corto_set_ref(&((corto_observer_event*)_this)->instance, instance);
        corto_set_ref(&((corto_observer_event*)_this)->source, source);
        ((corto_observer_event*)_this)->event = event;
        corto_set_ref(&((corto_observer_event*)_this)->data, data);
        ((corto_observer_event*)_this)->thread = thread;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_observer_event__update(corto_observer_event* _this, corto_observer observer, corto_object instance, corto_object source, corto_eventMask event, corto_object data, uintptr_t thread) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_set_ref(&((corto_observer_event*)((corto_observer_event*)CORTO_OFFSET(_this, ((corto_type)corto_observer_event_o)->size)))->observer, observer);
            corto_set_ref(&((corto_observer_event*)((corto_observer_event*)CORTO_OFFSET(_this, ((corto_type)corto_observer_event_o)->size)))->instance, instance);
            corto_set_ref(&((corto_observer_event*)((corto_observer_event*)CORTO_OFFSET(_this, ((corto_type)corto_observer_event_o)->size)))->source, source);
            ((corto_observer_event*)((corto_observer_event*)CORTO_OFFSET(_this, ((corto_type)corto_observer_event_o)->size)))->event = event;
            corto_set_ref(&((corto_observer_event*)((corto_observer_event*)CORTO_OFFSET(_this, ((corto_type)corto_observer_event_o)->size)))->data, data);
            ((corto_observer_event*)((corto_observer_event*)CORTO_OFFSET(_this, ((corto_type)corto_observer_event_o)->size)))->thread = thread;
        } else {
            corto_set_ref(&((corto_observer_event*)_this)->observer, observer);
            corto_set_ref(&((corto_observer_event*)_this)->instance, instance);
            corto_set_ref(&((corto_observer_event*)_this)->source, source);
            ((corto_observer_event*)_this)->event = event;
            corto_set_ref(&((corto_observer_event*)_this)->data, data);
            ((corto_observer_event*)_this)->thread = thread;
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

corto_observer_event* _corto_observer_event__assign(corto_observer_event* _this, corto_observer observer, corto_object instance, corto_object source, corto_eventMask event, corto_object data, uintptr_t thread) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_observer_event*)_this)->observer, observer);
    corto_set_ref(&((corto_observer_event*)_this)->instance, instance);
    corto_set_ref(&((corto_observer_event*)_this)->source, source);
    ((corto_observer_event*)_this)->event = event;
    corto_set_ref(&((corto_observer_event*)_this)->data, data);
    ((corto_observer_event*)_this)->thread = thread;
    return _this;
}

corto_operatorKind* _corto_operatorKind__create(corto_object _parent, const char *_id, corto_operatorKind value) {
    corto_operatorKind* _this;
    _this = (corto_operatorKind*)corto_declare(_parent, _id, corto_operatorKind_o);
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

corto_int16 _corto_operatorKind__update(corto_operatorKind* _this, corto_operatorKind value) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            *((corto_operatorKind*)CORTO_OFFSET(_this, ((corto_type)corto_operatorKind_o)->size)) = value;
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

corto_operatorKind* _corto_operatorKind__assign(corto_operatorKind* _this, corto_operatorKind value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

corto_ownership* _corto_ownership__create(corto_object _parent, const char *_id, corto_ownership value) {
    corto_ownership* _this;
    _this = (corto_ownership*)corto_declare(_parent, _id, corto_ownership_o);
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

corto_int16 _corto_ownership__update(corto_ownership* _this, corto_ownership value) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            *((corto_ownership*)CORTO_OFFSET(_this, ((corto_type)corto_ownership_o)->size)) = value;
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

corto_ownership* _corto_ownership__assign(corto_ownership* _this, corto_ownership value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

corto_query* _corto_query__create(corto_object _parent, const char *_id, const char * select, const char * from, const char * type, const char * instanceof, const char * member, const char * where, uint64_t offset, uint64_t limit, uint64_t soffset, uint64_t slimit, corto_frame* timeBegin, corto_frame* timeEnd) {
    corto_query* _this;
    _this = (corto_query*)corto_declare(_parent, _id, corto_query_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_str(&((corto_query*)_this)->select, select);
        corto_set_str(&((corto_query*)_this)->from, from);
        corto_set_str(&((corto_query*)_this)->type, type);
        corto_set_str(&((corto_query*)_this)->instanceof, instanceof);
        corto_set_str(&((corto_query*)_this)->member, member);
        corto_set_str(&((corto_query*)_this)->where, where);
        ((corto_query*)_this)->offset = offset;
        ((corto_query*)_this)->limit = limit;
        ((corto_query*)_this)->soffset = soffset;
        ((corto_query*)_this)->slimit = slimit;
        if (timeBegin) {
            corto_ptr_copy(&((corto_query*)_this)->timeBegin, corto_frame_o, timeBegin);
        }
        if (timeEnd) {
            corto_ptr_copy(&((corto_query*)_this)->timeEnd, corto_frame_o, timeEnd);
        }
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_query__update(corto_query* _this, const char * select, const char * from, const char * type, const char * instanceof, const char * member, const char * where, uint64_t offset, uint64_t limit, uint64_t soffset, uint64_t slimit, corto_frame* timeBegin, corto_frame* timeEnd) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_set_str(&((corto_query*)((corto_query*)CORTO_OFFSET(_this, ((corto_type)corto_query_o)->size)))->select, select);
            corto_set_str(&((corto_query*)((corto_query*)CORTO_OFFSET(_this, ((corto_type)corto_query_o)->size)))->from, from);
            corto_set_str(&((corto_query*)((corto_query*)CORTO_OFFSET(_this, ((corto_type)corto_query_o)->size)))->type, type);
            corto_set_str(&((corto_query*)((corto_query*)CORTO_OFFSET(_this, ((corto_type)corto_query_o)->size)))->instanceof, instanceof);
            corto_set_str(&((corto_query*)((corto_query*)CORTO_OFFSET(_this, ((corto_type)corto_query_o)->size)))->member, member);
            corto_set_str(&((corto_query*)((corto_query*)CORTO_OFFSET(_this, ((corto_type)corto_query_o)->size)))->where, where);
            ((corto_query*)((corto_query*)CORTO_OFFSET(_this, ((corto_type)corto_query_o)->size)))->offset = offset;
            ((corto_query*)((corto_query*)CORTO_OFFSET(_this, ((corto_type)corto_query_o)->size)))->limit = limit;
            ((corto_query*)((corto_query*)CORTO_OFFSET(_this, ((corto_type)corto_query_o)->size)))->soffset = soffset;
            ((corto_query*)((corto_query*)CORTO_OFFSET(_this, ((corto_type)corto_query_o)->size)))->slimit = slimit;
            if (timeBegin) {
                corto_ptr_copy(&((corto_query*)((corto_query*)CORTO_OFFSET(_this, ((corto_type)corto_query_o)->size)))->timeBegin, corto_frame_o, timeBegin);
            }
            if (timeEnd) {
                corto_ptr_copy(&((corto_query*)((corto_query*)CORTO_OFFSET(_this, ((corto_type)corto_query_o)->size)))->timeEnd, corto_frame_o, timeEnd);
            }
        } else {
            corto_set_str(&((corto_query*)_this)->select, select);
            corto_set_str(&((corto_query*)_this)->from, from);
            corto_set_str(&((corto_query*)_this)->type, type);
            corto_set_str(&((corto_query*)_this)->instanceof, instanceof);
            corto_set_str(&((corto_query*)_this)->member, member);
            corto_set_str(&((corto_query*)_this)->where, where);
            ((corto_query*)_this)->offset = offset;
            ((corto_query*)_this)->limit = limit;
            ((corto_query*)_this)->soffset = soffset;
            ((corto_query*)_this)->slimit = slimit;
            if (timeBegin) {
                corto_ptr_copy(&((corto_query*)_this)->timeBegin, corto_frame_o, timeBegin);
            }
            if (timeEnd) {
                corto_ptr_copy(&((corto_query*)_this)->timeEnd, corto_frame_o, timeEnd);
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

corto_query* _corto_query__assign(corto_query* _this, const char * select, const char * from, const char * type, const char * instanceof, const char * member, const char * where, uint64_t offset, uint64_t limit, uint64_t soffset, uint64_t slimit, corto_frame* timeBegin, corto_frame* timeEnd) {
    CORTO_UNUSED(_this);
    corto_set_str(&((corto_query*)_this)->select, select);
    corto_set_str(&((corto_query*)_this)->from, from);
    corto_set_str(&((corto_query*)_this)->type, type);
    corto_set_str(&((corto_query*)_this)->instanceof, instanceof);
    corto_set_str(&((corto_query*)_this)->member, member);
    corto_set_str(&((corto_query*)_this)->where, where);
    ((corto_query*)_this)->offset = offset;
    ((corto_query*)_this)->limit = limit;
    ((corto_query*)_this)->soffset = soffset;
    ((corto_query*)_this)->slimit = slimit;
    if (timeBegin) {
        corto_ptr_copy(&((corto_query*)_this)->timeBegin, corto_frame_o, timeBegin);
    }
    if (timeEnd) {
        corto_ptr_copy(&((corto_query*)_this)->timeEnd, corto_frame_o, timeEnd);
    }
    return _this;
}

corto_remote _corto_remote__create(corto_object _parent, const char *_id, corto_type returnType, bool returnsReference, void(*_impl)(void)) {
    corto_remote _this;
    _this = (corto_remote)corto_declare(_parent, _id, corto_remote_o);
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

corto_int16 _corto_remote__update(corto_remote _this, corto_type returnType, bool returnsReference, void(*_impl)(void)) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_set_ref(&((corto_function)((corto_remote)CORTO_OFFSET(_this, ((corto_type)corto_remote_o)->size)))->returnType, returnType);
            ((corto_function)((corto_remote)CORTO_OFFSET(_this, ((corto_type)corto_remote_o)->size)))->returnsReference = returnsReference;
            corto_function(((corto_remote)CORTO_OFFSET(_this, ((corto_type)corto_remote_o)->size)))->kind = CORTO_PROCEDURE_CDECL;
            corto_function(((corto_remote)CORTO_OFFSET(_this, ((corto_type)corto_remote_o)->size)))->fptr = (corto_word)_impl;
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

corto_remote _corto_remote__assign(corto_remote _this, corto_type returnType, bool returnsReference, void(*_impl)(void)) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_function)_this)->returnType, returnType);
    ((corto_function)_this)->returnsReference = returnsReference;
    corto_function(_this)->kind = CORTO_PROCEDURE_CDECL;
    corto_function(_this)->fptr = (corto_word)_impl;
    return _this;
}

corto_result* _corto_result__create(corto_object _parent, const char *_id, const char * id, const char * name, const char * parent, const char * type, uintptr_t value, corto_resultMask flags) {
    corto_result* _this;
    _this = (corto_result*)corto_declare(_parent, _id, corto_result_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_str(&((corto_result*)_this)->id, id);
        corto_set_str(&((corto_result*)_this)->name, name);
        corto_set_str(&((corto_result*)_this)->parent, parent);
        corto_set_str(&((corto_result*)_this)->type, type);
        ((corto_result*)_this)->value = value;
        ((corto_result*)_this)->flags = flags;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_result__update(corto_result* _this, const char * id, const char * name, const char * parent, const char * type, uintptr_t value, corto_resultMask flags) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_set_str(&((corto_result*)((corto_result*)CORTO_OFFSET(_this, ((corto_type)corto_result_o)->size)))->id, id);
            corto_set_str(&((corto_result*)((corto_result*)CORTO_OFFSET(_this, ((corto_type)corto_result_o)->size)))->name, name);
            corto_set_str(&((corto_result*)((corto_result*)CORTO_OFFSET(_this, ((corto_type)corto_result_o)->size)))->parent, parent);
            corto_set_str(&((corto_result*)((corto_result*)CORTO_OFFSET(_this, ((corto_type)corto_result_o)->size)))->type, type);
            ((corto_result*)((corto_result*)CORTO_OFFSET(_this, ((corto_type)corto_result_o)->size)))->value = value;
            ((corto_result*)((corto_result*)CORTO_OFFSET(_this, ((corto_type)corto_result_o)->size)))->flags = flags;
        } else {
            corto_set_str(&((corto_result*)_this)->id, id);
            corto_set_str(&((corto_result*)_this)->name, name);
            corto_set_str(&((corto_result*)_this)->parent, parent);
            corto_set_str(&((corto_result*)_this)->type, type);
            ((corto_result*)_this)->value = value;
            ((corto_result*)_this)->flags = flags;
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

corto_result* _corto_result__assign(corto_result* _this, const char * id, const char * name, const char * parent, const char * type, uintptr_t value, corto_resultMask flags) {
    CORTO_UNUSED(_this);
    corto_set_str(&((corto_result*)_this)->id, id);
    corto_set_str(&((corto_result*)_this)->name, name);
    corto_set_str(&((corto_result*)_this)->parent, parent);
    corto_set_str(&((corto_result*)_this)->type, type);
    ((corto_result*)_this)->value = value;
    ((corto_result*)_this)->flags = flags;
    return _this;
}

corto_resultIter* _corto_resultIter__create(corto_object _parent, const char *_id) {
    corto_resultIter* _this;
    _this = (corto_resultIter*)corto_declare(_parent, _id, corto_resultIter_o);
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

corto_int16 _corto_resultIter__update(corto_resultIter* _this) {
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

corto_resultIter* _corto_resultIter__assign(corto_resultIter* _this) {
    CORTO_UNUSED(_this);
    return _this;
}

corto_resultlist* _corto_resultlist__create(corto_object _parent, const char *_id, corto_uint32 length, corto_result* elements) {
    corto_resultlist* _this;
    _this = (corto_resultlist*)corto_declare(_parent, _id, corto_resultlist_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_uint32 i = 0;
        corto_resultlist__clear(*_this);
        for (i = 0; i < length; i ++) {
            corto_resultlist__append(*_this, &elements[i]);
        }
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_resultlist__update(corto_resultlist* _this, corto_uint32 length, corto_result* elements) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_uint32 i = 0;
            corto_resultlist__clear(*((corto_resultlist*)CORTO_OFFSET(_this, ((corto_type)corto_resultlist_o)->size)));
            for (i = 0; i < length; i ++) {
                corto_resultlist__append(*((corto_resultlist*)CORTO_OFFSET(_this, ((corto_type)corto_resultlist_o)->size)), &elements[i]);
            }
        } else {
            corto_uint32 i = 0;
            corto_resultlist__clear(*_this);
            for (i = 0; i < length; i ++) {
                corto_resultlist__append(*_this, &elements[i]);
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

corto_resultlist* _corto_resultlist__assign(corto_resultlist* _this, corto_uint32 length, corto_result* elements) {
    CORTO_UNUSED(_this);
    corto_uint32 i = 0;
    corto_resultlist__clear(*_this);
    for (i = 0; i < length; i ++) {
        corto_resultlist__append(*_this, &elements[i]);
    }
    return _this;
}

corto_resultMask* _corto_resultMask__create(corto_object _parent, const char *_id, corto_resultMask value) {
    corto_resultMask* _this;
    _this = (corto_resultMask*)corto_declare(_parent, _id, corto_resultMask_o);
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

corto_int16 _corto_resultMask__update(corto_resultMask* _this, corto_resultMask value) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            *((corto_resultMask*)CORTO_OFFSET(_this, ((corto_type)corto_resultMask_o)->size)) = value;
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

corto_resultMask* _corto_resultMask__assign(corto_resultMask* _this, corto_resultMask value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

corto_route _corto_route__create(corto_object _parent, const char *_id, const char * pattern, void(*_impl)(void)) {
    corto_route _this;
    _this = (corto_route)corto_declare(_parent, _id, corto_route_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_str(&((corto_route)_this)->pattern, pattern);
        corto_function(_this)->kind = CORTO_PROCEDURE_CDECL;
        corto_function(_this)->fptr = (corto_word)_impl;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_route__update(corto_route _this, const char * pattern, void(*_impl)(void)) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_set_str(&((corto_route)((corto_route)CORTO_OFFSET(_this, ((corto_type)corto_route_o)->size)))->pattern, pattern);
            corto_function(((corto_route)CORTO_OFFSET(_this, ((corto_type)corto_route_o)->size)))->kind = CORTO_PROCEDURE_CDECL;
            corto_function(((corto_route)CORTO_OFFSET(_this, ((corto_type)corto_route_o)->size)))->fptr = (corto_word)_impl;
        } else {
            corto_set_str(&((corto_route)_this)->pattern, pattern);
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

corto_route _corto_route__assign(corto_route _this, const char * pattern, void(*_impl)(void)) {
    CORTO_UNUSED(_this);
    corto_set_str(&((corto_route)_this)->pattern, pattern);
    corto_function(_this)->kind = CORTO_PROCEDURE_CDECL;
    corto_function(_this)->fptr = (corto_word)_impl;
    return _this;
}

corto_router _corto_router__create(corto_object _parent, const char *_id, corto_type returnType, corto_type paramType, const char * paramName, corto_type routerDataType, const char * routerDataName, const char * elementSeparator) {
    corto_router _this;
    _this = (corto_router)corto_declare(_parent, _id, corto_router_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_ref(&((corto_router)_this)->returnType, returnType);
        corto_set_ref(&((corto_router)_this)->paramType, paramType);
        corto_set_str(&((corto_router)_this)->paramName, paramName);
        corto_set_ref(&((corto_router)_this)->routerDataType, routerDataType);
        corto_set_str(&((corto_router)_this)->routerDataName, routerDataName);
        corto_set_str(&((corto_router)_this)->elementSeparator, elementSeparator);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_router__update(corto_router _this, corto_type returnType, corto_type paramType, const char * paramName, corto_type routerDataType, const char * routerDataName, const char * elementSeparator) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_set_ref(&((corto_router)((corto_router)CORTO_OFFSET(_this, ((corto_type)corto_router_o)->size)))->returnType, returnType);
            corto_set_ref(&((corto_router)((corto_router)CORTO_OFFSET(_this, ((corto_type)corto_router_o)->size)))->paramType, paramType);
            corto_set_str(&((corto_router)((corto_router)CORTO_OFFSET(_this, ((corto_type)corto_router_o)->size)))->paramName, paramName);
            corto_set_ref(&((corto_router)((corto_router)CORTO_OFFSET(_this, ((corto_type)corto_router_o)->size)))->routerDataType, routerDataType);
            corto_set_str(&((corto_router)((corto_router)CORTO_OFFSET(_this, ((corto_type)corto_router_o)->size)))->routerDataName, routerDataName);
            corto_set_str(&((corto_router)((corto_router)CORTO_OFFSET(_this, ((corto_type)corto_router_o)->size)))->elementSeparator, elementSeparator);
        } else {
            corto_set_ref(&((corto_router)_this)->returnType, returnType);
            corto_set_ref(&((corto_router)_this)->paramType, paramType);
            corto_set_str(&((corto_router)_this)->paramName, paramName);
            corto_set_ref(&((corto_router)_this)->routerDataType, routerDataType);
            corto_set_str(&((corto_router)_this)->routerDataName, routerDataName);
            corto_set_str(&((corto_router)_this)->elementSeparator, elementSeparator);
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

corto_router _corto_router__assign(corto_router _this, corto_type returnType, corto_type paramType, const char * paramName, corto_type routerDataType, const char * routerDataName, const char * elementSeparator) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_router)_this)->returnType, returnType);
    corto_set_ref(&((corto_router)_this)->paramType, paramType);
    corto_set_str(&((corto_router)_this)->paramName, paramName);
    corto_set_ref(&((corto_router)_this)->routerDataType, routerDataType);
    corto_set_str(&((corto_router)_this)->routerDataName, routerDataName);
    corto_set_str(&((corto_router)_this)->elementSeparator, elementSeparator);
    return _this;
}

corto_routerimpl _corto_routerimpl__create(corto_object _parent, const char *_id, corto_interface base, corto_modifier baseAccess, corto_interfaceseq implements) {
    corto_routerimpl _this;
    _this = (corto_routerimpl)corto_declare(_parent, _id, corto_routerimpl_o);
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

corto_int16 _corto_routerimpl__update(corto_routerimpl _this, corto_interface base, corto_modifier baseAccess, corto_interfaceseq implements) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_set_ref(&((corto_interface)((corto_routerimpl)CORTO_OFFSET(_this, ((corto_type)corto_routerimpl_o)->size)))->base, base);
            ((corto_struct)((corto_routerimpl)CORTO_OFFSET(_this, ((corto_type)corto_routerimpl_o)->size)))->baseAccess = baseAccess;
            corto_ptr_copy(&((corto_class)((corto_routerimpl)CORTO_OFFSET(_this, ((corto_type)corto_routerimpl_o)->size)))->implements, corto_interfaceseq_o, &implements);
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

corto_routerimpl _corto_routerimpl__assign(corto_routerimpl _this, corto_interface base, corto_modifier baseAccess, corto_interfaceseq implements) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_interface)_this)->base, base);
    ((corto_struct)_this)->baseAccess = baseAccess;
    corto_ptr_copy(&((corto_class)_this)->implements, corto_interfaceseq_o, &implements);
    return _this;
}

corto_sample* _corto_sample__create(corto_object _parent, const char *_id, corto_time* timestamp, uintptr_t value) {
    corto_sample* _this;
    _this = (corto_sample*)corto_declare(_parent, _id, corto_sample_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        if (timestamp) {
            corto_ptr_copy(&((corto_sample*)_this)->timestamp, corto_time_o, timestamp);
        }
        ((corto_sample*)_this)->value = value;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_sample__update(corto_sample* _this, corto_time* timestamp, uintptr_t value) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            if (timestamp) {
                corto_ptr_copy(&((corto_sample*)((corto_sample*)CORTO_OFFSET(_this, ((corto_type)corto_sample_o)->size)))->timestamp, corto_time_o, timestamp);
            }
            ((corto_sample*)((corto_sample*)CORTO_OFFSET(_this, ((corto_type)corto_sample_o)->size)))->value = value;
        } else {
            if (timestamp) {
                corto_ptr_copy(&((corto_sample*)_this)->timestamp, corto_time_o, timestamp);
            }
            ((corto_sample*)_this)->value = value;
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

corto_sample* _corto_sample__assign(corto_sample* _this, corto_time* timestamp, uintptr_t value) {
    CORTO_UNUSED(_this);
    if (timestamp) {
        corto_ptr_copy(&((corto_sample*)_this)->timestamp, corto_time_o, timestamp);
    }
    ((corto_sample*)_this)->value = value;
    return _this;
}

corto_sampleIter* _corto_sampleIter__create(corto_object _parent, const char *_id) {
    corto_sampleIter* _this;
    _this = (corto_sampleIter*)corto_declare(_parent, _id, corto_sampleIter_o);
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

corto_int16 _corto_sampleIter__update(corto_sampleIter* _this) {
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

corto_sampleIter* _corto_sampleIter__assign(corto_sampleIter* _this) {
    CORTO_UNUSED(_this);
    return _this;
}

corto_subscriber _corto_subscriber__create(corto_object _parent, const char *_id, corto_query* query, const char * contentType, corto_object instance, corto_dispatcher dispatcher, bool enabled, void(*_impl)(void)) {
    corto_subscriber _this;
    _this = (corto_subscriber)corto_declare(_parent, _id, corto_subscriber_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        if (query) {
            corto_ptr_copy(&((corto_subscriber)_this)->query, corto_query_o, query);
        }
        corto_set_str(&((corto_subscriber)_this)->contentType, contentType);
        corto_set_ref(&((corto_observer)_this)->instance, instance);
        corto_set_ref(&((corto_observer)_this)->dispatcher, dispatcher);
        ((corto_observer)_this)->enabled = enabled;
        corto_function(_this)->kind = CORTO_PROCEDURE_CDECL;
        corto_function(_this)->fptr = (corto_word)_impl;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_subscriber__update(corto_subscriber _this, corto_query* query, const char * contentType, corto_object instance, corto_dispatcher dispatcher, bool enabled, void(*_impl)(void)) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            if (query) {
                corto_ptr_copy(&((corto_subscriber)((corto_subscriber)CORTO_OFFSET(_this, ((corto_type)corto_subscriber_o)->size)))->query, corto_query_o, query);
            }
            corto_set_str(&((corto_subscriber)((corto_subscriber)CORTO_OFFSET(_this, ((corto_type)corto_subscriber_o)->size)))->contentType, contentType);
            corto_set_ref(&((corto_observer)((corto_subscriber)CORTO_OFFSET(_this, ((corto_type)corto_subscriber_o)->size)))->instance, instance);
            corto_set_ref(&((corto_observer)((corto_subscriber)CORTO_OFFSET(_this, ((corto_type)corto_subscriber_o)->size)))->dispatcher, dispatcher);
            ((corto_observer)((corto_subscriber)CORTO_OFFSET(_this, ((corto_type)corto_subscriber_o)->size)))->enabled = enabled;
            corto_function(((corto_subscriber)CORTO_OFFSET(_this, ((corto_type)corto_subscriber_o)->size)))->kind = CORTO_PROCEDURE_CDECL;
            corto_function(((corto_subscriber)CORTO_OFFSET(_this, ((corto_type)corto_subscriber_o)->size)))->fptr = (corto_word)_impl;
        } else {
            if (query) {
                corto_ptr_copy(&((corto_subscriber)_this)->query, corto_query_o, query);
            }
            corto_set_str(&((corto_subscriber)_this)->contentType, contentType);
            corto_set_ref(&((corto_observer)_this)->instance, instance);
            corto_set_ref(&((corto_observer)_this)->dispatcher, dispatcher);
            ((corto_observer)_this)->enabled = enabled;
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

corto_subscriber _corto_subscriber__assign(corto_subscriber _this, corto_query* query, const char * contentType, corto_object instance, corto_dispatcher dispatcher, bool enabled, void(*_impl)(void)) {
    CORTO_UNUSED(_this);
    if (query) {
        corto_ptr_copy(&((corto_subscriber)_this)->query, corto_query_o, query);
    }
    corto_set_str(&((corto_subscriber)_this)->contentType, contentType);
    corto_set_ref(&((corto_observer)_this)->instance, instance);
    corto_set_ref(&((corto_observer)_this)->dispatcher, dispatcher);
    ((corto_observer)_this)->enabled = enabled;
    corto_function(_this)->kind = CORTO_PROCEDURE_CDECL;
    corto_function(_this)->fptr = (corto_word)_impl;
    return _this;
}

corto_subscriber_event* _corto_subscriber_event__create(corto_object _parent, const char *_id, corto_subscriber subscriber, corto_object instance, corto_object source, corto_eventMask event, corto_result* data, corto_fmt_data* fmt) {
    corto_subscriber_event* _this;
    _this = (corto_subscriber_event*)corto_declare(_parent, _id, corto_subscriber_event_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        corto_set_ref(&((corto_subscriber_event*)_this)->subscriber, subscriber);
        corto_set_ref(&((corto_subscriber_event*)_this)->instance, instance);
        corto_set_ref(&((corto_subscriber_event*)_this)->source, source);
        ((corto_subscriber_event*)_this)->event = event;
        if (data) {
            corto_ptr_copy(&((corto_subscriber_event*)_this)->data, corto_result_o, data);
        }
        if (fmt) {
            corto_ptr_copy(&((corto_subscriber_event*)_this)->fmt, corto_fmt_data_o, fmt);
        }
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_subscriber_event__update(corto_subscriber_event* _this, corto_subscriber subscriber, corto_object instance, corto_object source, corto_eventMask event, corto_result* data, corto_fmt_data* fmt) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_set_ref(&((corto_subscriber_event*)((corto_subscriber_event*)CORTO_OFFSET(_this, ((corto_type)corto_subscriber_event_o)->size)))->subscriber, subscriber);
            corto_set_ref(&((corto_subscriber_event*)((corto_subscriber_event*)CORTO_OFFSET(_this, ((corto_type)corto_subscriber_event_o)->size)))->instance, instance);
            corto_set_ref(&((corto_subscriber_event*)((corto_subscriber_event*)CORTO_OFFSET(_this, ((corto_type)corto_subscriber_event_o)->size)))->source, source);
            ((corto_subscriber_event*)((corto_subscriber_event*)CORTO_OFFSET(_this, ((corto_type)corto_subscriber_event_o)->size)))->event = event;
            if (data) {
                corto_ptr_copy(&((corto_subscriber_event*)((corto_subscriber_event*)CORTO_OFFSET(_this, ((corto_type)corto_subscriber_event_o)->size)))->data, corto_result_o, data);
            }
            if (fmt) {
                corto_ptr_copy(&((corto_subscriber_event*)((corto_subscriber_event*)CORTO_OFFSET(_this, ((corto_type)corto_subscriber_event_o)->size)))->fmt, corto_fmt_data_o, fmt);
            }
        } else {
            corto_set_ref(&((corto_subscriber_event*)_this)->subscriber, subscriber);
            corto_set_ref(&((corto_subscriber_event*)_this)->instance, instance);
            corto_set_ref(&((corto_subscriber_event*)_this)->source, source);
            ((corto_subscriber_event*)_this)->event = event;
            if (data) {
                corto_ptr_copy(&((corto_subscriber_event*)_this)->data, corto_result_o, data);
            }
            if (fmt) {
                corto_ptr_copy(&((corto_subscriber_event*)_this)->fmt, corto_fmt_data_o, fmt);
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

corto_subscriber_event* _corto_subscriber_event__assign(corto_subscriber_event* _this, corto_subscriber subscriber, corto_object instance, corto_object source, corto_eventMask event, corto_result* data, corto_fmt_data* fmt) {
    CORTO_UNUSED(_this);
    corto_set_ref(&((corto_subscriber_event*)_this)->subscriber, subscriber);
    corto_set_ref(&((corto_subscriber_event*)_this)->instance, instance);
    corto_set_ref(&((corto_subscriber_event*)_this)->source, source);
    ((corto_subscriber_event*)_this)->event = event;
    if (data) {
        corto_ptr_copy(&((corto_subscriber_event*)_this)->data, corto_result_o, data);
    }
    if (fmt) {
        corto_ptr_copy(&((corto_subscriber_event*)_this)->fmt, corto_fmt_data_o, fmt);
    }
    return _this;
}

corto_subscriber_eventIter* _corto_subscriber_eventIter__create(corto_object _parent, const char *_id) {
    corto_subscriber_eventIter* _this;
    _this = (corto_subscriber_eventIter*)corto_declare(_parent, _id, corto_subscriber_eventIter_o);
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

corto_int16 _corto_subscriber_eventIter__update(corto_subscriber_eventIter* _this) {
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

corto_subscriber_eventIter* _corto_subscriber_eventIter__assign(corto_subscriber_eventIter* _this) {
    CORTO_UNUSED(_this);
    return _this;
}

corto_time* _corto_time__create(corto_object _parent, const char *_id, int32_t sec, uint32_t nanosec) {
    corto_time* _this;
    _this = (corto_time*)corto_declare(_parent, _id, corto_time_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_check_state(_this, CORTO_VALID)) {
        ((corto_time*)_this)->sec = sec;
        ((corto_time*)_this)->nanosec = nanosec;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_time__update(corto_time* _this, int32_t sec, uint32_t nanosec) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            ((corto_time*)((corto_time*)CORTO_OFFSET(_this, ((corto_type)corto_time_o)->size)))->sec = sec;
            ((corto_time*)((corto_time*)CORTO_OFFSET(_this, ((corto_type)corto_time_o)->size)))->nanosec = nanosec;
        } else {
            ((corto_time*)_this)->sec = sec;
            ((corto_time*)_this)->nanosec = nanosec;
        }
        if (corto_update_end(_this)) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}

corto_time* _corto_time__assign(corto_time* _this, int32_t sec, uint32_t nanosec) {
    CORTO_UNUSED(_this);
    ((corto_time*)_this)->sec = sec;
    ((corto_time*)_this)->nanosec = nanosec;
    return _this;
}

corto_mount_subscription* corto_mount_subscriptionList__insert_alloc(corto_mount_subscriptionList list) {
    corto_mount_subscription* result;
    result = (corto_mount_subscription*)corto_calloc(corto_type_sizeof(corto_type(corto_mount_subscription_o)));
    {
        corto_ptr_init(result, corto_mount_subscription_o);
    }
    corto_ll_insert(list, result);
    return result;
}

corto_mount_subscription* corto_mount_subscriptionList__insert(corto_mount_subscriptionList list, corto_mount_subscription* element) {
    corto_mount_subscription *result = corto_mount_subscriptionList__insert_alloc(list);
    corto_ptr_copy(result, corto_mount_subscription_o, element);
    return result;
}

corto_mount_subscription* corto_mount_subscriptionList__append_alloc(corto_mount_subscriptionList list) {
    corto_mount_subscription* result;
    result = (corto_mount_subscription*)corto_calloc(corto_type_sizeof(corto_type(corto_mount_subscription_o)));
    {
        corto_ptr_init(result, corto_mount_subscription_o);
    }
    corto_ll_append(list, result);
    return result;
}

corto_mount_subscription* corto_mount_subscriptionList__append(corto_mount_subscriptionList list, corto_mount_subscription* element) {
    corto_mount_subscription *result = corto_mount_subscriptionList__append_alloc(list);
    corto_ptr_copy(result, corto_mount_subscription_o, element);
    return result;
}

corto_mount_subscription* corto_mount_subscriptionList__takeFirst(corto_mount_subscriptionList list) {
    return (corto_mount_subscription*)(corto_word)corto_ll_takeFirst(list);
}

corto_mount_subscription* corto_mount_subscriptionList__last(corto_mount_subscriptionList list) {
    return (corto_mount_subscription*)(corto_word)corto_ll_last(list);
}

corto_mount_subscription* corto_mount_subscriptionList__get(corto_mount_subscriptionList list, corto_uint32 index) {
    return (corto_mount_subscription*)corto_ll_get(list, index);
}

void corto_mount_subscriptionList__clear(corto_mount_subscriptionList list) {
    corto_iter iter = corto_ll_iter(list);
    while(corto_iter_hasNext(&iter)) {
        void *ptr = corto_iter_next(&iter);
        corto_ptr_deinit(ptr, corto_mount_subscription_o);
        corto_dealloc(ptr);
    }
    corto_ll_clear(list);
}

corto_result* corto_resultlist__insert_alloc(corto_resultlist list) {
    corto_result* result;
    result = (corto_result*)corto_calloc(corto_type_sizeof(corto_type(corto_result_o)));
    {
        corto_ptr_init(result, corto_result_o);
    }
    corto_ll_insert(list, result);
    return result;
}

corto_result* corto_resultlist__insert(corto_resultlist list, corto_result* element) {
    corto_result *result = corto_resultlist__insert_alloc(list);
    corto_ptr_copy(result, corto_result_o, element);
    return result;
}

corto_result* corto_resultlist__append_alloc(corto_resultlist list) {
    corto_result* result;
    result = (corto_result*)corto_calloc(corto_type_sizeof(corto_type(corto_result_o)));
    {
        corto_ptr_init(result, corto_result_o);
    }
    corto_ll_append(list, result);
    return result;
}

corto_result* corto_resultlist__append(corto_resultlist list, corto_result* element) {
    corto_result *result = corto_resultlist__append_alloc(list);
    corto_ptr_copy(result, corto_result_o, element);
    return result;
}

corto_result* corto_resultlist__takeFirst(corto_resultlist list) {
    return (corto_result*)(corto_word)corto_ll_takeFirst(list);
}

corto_result* corto_resultlist__last(corto_resultlist list) {
    return (corto_result*)(corto_word)corto_ll_last(list);
}

corto_result* corto_resultlist__get(corto_resultlist list, corto_uint32 index) {
    return (corto_result*)corto_ll_get(list, index);
}

void corto_resultlist__clear(corto_resultlist list) {
    corto_iter iter = corto_ll_iter(list);
    while(corto_iter_hasNext(&iter)) {
        void *ptr = corto_iter_next(&iter);
        corto_ptr_deinit(ptr, corto_result_o);
        corto_dealloc(ptr);
    }
    corto_ll_clear(list);
}

