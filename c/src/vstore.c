/* vstore.c
 *
 * API convenience functions for C-language.
 * This file contains generated code. Do not modify!
 */

#include <corto/c/c.h>

corto_application _corto_applicationCreate(void) {
    corto_application _this;
    _this = (corto_application)corto_declare(corto_application_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_VALID)) {
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_application _corto_applicationCreateChild(corto_object _parent, corto_string _id) {
    corto_application _this;
    _this = (corto_application)corto_declareChild(_parent, _id, corto_application_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_VALID)) {
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
        corto_update_end(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_application _corto_applicationDeclare(void) {
    corto_application _this;
    _this = (corto_application)corto_declare(corto_application_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_application _corto_applicationDeclareChild(corto_object _parent, corto_string _id) {
    corto_application _this;
    _this = (corto_application)corto_declareChild(_parent, _id, corto_application_o);
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

corto_dispatcher _corto_dispatcherCreate(void) {
    corto_dispatcher _this;
    _this = (corto_dispatcher)corto_declare(corto_dispatcher_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_VALID)) {
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_dispatcher _corto_dispatcherCreateChild(corto_object _parent, corto_string _id) {
    corto_dispatcher _this;
    _this = (corto_dispatcher)corto_declareChild(_parent, _id, corto_dispatcher_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_VALID)) {
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_dispatcherUpdate(corto_dispatcher _this) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
        } else {
        }
        corto_update_end(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_dispatcher _corto_dispatcherDeclare(void) {
    corto_dispatcher _this;
    _this = (corto_dispatcher)corto_declare(corto_dispatcher_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_dispatcher _corto_dispatcherDeclareChild(corto_object _parent, corto_string _id) {
    corto_dispatcher _this;
    _this = (corto_dispatcher)corto_declareChild(_parent, _id, corto_dispatcher_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_dispatcherDefine(corto_dispatcher _this) {
    CORTO_UNUSED(_this);
    return corto_define(_this);
}

corto_dispatcher _corto_dispatcherAssign(corto_dispatcher _this) {
    CORTO_UNUSED(_this);
    return _this;
}

corto_event* _corto_eventCreate(uint16_t kind) {
    corto_event* _this;
    _this = (corto_event*)corto_declare(corto_event_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_VALID)) {
        ((corto_event*)_this)->kind = kind;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_event* _corto_eventCreateChild(corto_object _parent, corto_string _id, uint16_t kind) {
    corto_event* _this;
    _this = (corto_event*)corto_declareChild(_parent, _id, corto_event_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_VALID)) {
        ((corto_event*)_this)->kind = kind;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_eventUpdate(corto_event* _this, uint16_t kind) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            ((corto_event*)((corto_event*)CORTO_OFFSET(_this, ((corto_type)corto_event_o)->size)))->kind = kind;
        } else {
            ((corto_event*)_this)->kind = kind;
        }
        corto_update_end(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_event* _corto_eventDeclare(void) {
    corto_event* _this;
    _this = (corto_event*)corto_declare(corto_event_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_event* _corto_eventDeclareChild(corto_object _parent, corto_string _id) {
    corto_event* _this;
    _this = (corto_event*)corto_declareChild(_parent, _id, corto_event_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_eventDefine(corto_event* _this, uint16_t kind) {
    CORTO_UNUSED(_this);
    ((corto_event*)_this)->kind = kind;
    return corto_define(_this);
}

corto_event* _corto_eventAssign(corto_event* _this, uint16_t kind) {
    CORTO_UNUSED(_this);
    ((corto_event*)_this)->kind = kind;
    return _this;
}

corto_eventMask* _corto_eventMaskCreate(corto_eventMask value) {
    corto_eventMask* _this;
    _this = (corto_eventMask*)corto_declare(corto_eventMask_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_VALID)) {
        *_this = value;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_eventMask* _corto_eventMaskCreateChild(corto_object _parent, corto_string _id, corto_eventMask value) {
    corto_eventMask* _this;
    _this = (corto_eventMask*)corto_declareChild(_parent, _id, corto_eventMask_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_VALID)) {
        *_this = value;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_eventMaskUpdate(corto_eventMask* _this, corto_eventMask value) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            *((corto_eventMask*)CORTO_OFFSET(_this, ((corto_type)corto_eventMask_o)->size)) = value;
        } else {
            *_this = value;
        }
        corto_update_end(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_eventMask* _corto_eventMaskDeclare(void) {
    corto_eventMask* _this;
    _this = (corto_eventMask*)corto_declare(corto_eventMask_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_eventMask* _corto_eventMaskDeclareChild(corto_object _parent, corto_string _id) {
    corto_eventMask* _this;
    _this = (corto_eventMask*)corto_declareChild(_parent, _id, corto_eventMask_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_eventMaskDefine(corto_eventMask* _this, corto_eventMask value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return corto_define(_this);
}

corto_eventMask* _corto_eventMaskAssign(corto_eventMask* _this, corto_eventMask value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

corto_frame* _corto_frameCreate(corto_frameKind kind, int64_t value) {
    corto_frame* _this;
    _this = (corto_frame*)corto_declare(corto_frame_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_VALID)) {
        ((corto_frame*)_this)->kind = kind;
        ((corto_frame*)_this)->value = value;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_frame* _corto_frameCreateChild(corto_object _parent, corto_string _id, corto_frameKind kind, int64_t value) {
    corto_frame* _this;
    _this = (corto_frame*)corto_declareChild(_parent, _id, corto_frame_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_VALID)) {
        ((corto_frame*)_this)->kind = kind;
        ((corto_frame*)_this)->value = value;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_frameUpdate(corto_frame* _this, corto_frameKind kind, int64_t value) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            ((corto_frame*)((corto_frame*)CORTO_OFFSET(_this, ((corto_type)corto_frame_o)->size)))->kind = kind;
            ((corto_frame*)((corto_frame*)CORTO_OFFSET(_this, ((corto_type)corto_frame_o)->size)))->value = value;
        } else {
            ((corto_frame*)_this)->kind = kind;
            ((corto_frame*)_this)->value = value;
        }
        corto_update_end(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_frame* _corto_frameDeclare(void) {
    corto_frame* _this;
    _this = (corto_frame*)corto_declare(corto_frame_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_frame* _corto_frameDeclareChild(corto_object _parent, corto_string _id) {
    corto_frame* _this;
    _this = (corto_frame*)corto_declareChild(_parent, _id, corto_frame_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_frameDefine(corto_frame* _this, corto_frameKind kind, int64_t value) {
    CORTO_UNUSED(_this);
    ((corto_frame*)_this)->kind = kind;
    ((corto_frame*)_this)->value = value;
    return corto_define(_this);
}

corto_frame* _corto_frameAssign(corto_frame* _this, corto_frameKind kind, int64_t value) {
    CORTO_UNUSED(_this);
    ((corto_frame*)_this)->kind = kind;
    ((corto_frame*)_this)->value = value;
    return _this;
}

corto_frameKind* _corto_frameKindCreate(corto_frameKind value) {
    corto_frameKind* _this;
    _this = (corto_frameKind*)corto_declare(corto_frameKind_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_VALID)) {
        *_this = value;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_frameKind* _corto_frameKindCreateChild(corto_object _parent, corto_string _id, corto_frameKind value) {
    corto_frameKind* _this;
    _this = (corto_frameKind*)corto_declareChild(_parent, _id, corto_frameKind_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_VALID)) {
        *_this = value;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_frameKindUpdate(corto_frameKind* _this, corto_frameKind value) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            *((corto_frameKind*)CORTO_OFFSET(_this, ((corto_type)corto_frameKind_o)->size)) = value;
        } else {
            *_this = value;
        }
        corto_update_end(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_frameKind* _corto_frameKindDeclare(void) {
    corto_frameKind* _this;
    _this = (corto_frameKind*)corto_declare(corto_frameKind_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_frameKind* _corto_frameKindDeclareChild(corto_object _parent, corto_string _id) {
    corto_frameKind* _this;
    _this = (corto_frameKind*)corto_declareChild(_parent, _id, corto_frameKind_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_frameKindDefine(corto_frameKind* _this, corto_frameKind value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return corto_define(_this);
}

corto_frameKind* _corto_frameKindAssign(corto_frameKind* _this, corto_frameKind value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

corto_handleAction* _corto_handleActionCreate(corto_object instance, corto_function procedure) {
    corto_handleAction* _this;
    _this = (corto_handleAction*)corto_declare(corto_handleAction_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_VALID)) {
        corto_ptr_setref(&((corto_delegatedata*)_this)->instance, instance);
        corto_ptr_setref(&((corto_delegatedata*)_this)->procedure, procedure);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_handleAction* _corto_handleActionCreateChild(corto_object _parent, corto_string _id, corto_object instance, corto_function procedure) {
    corto_handleAction* _this;
    _this = (corto_handleAction*)corto_declareChild(_parent, _id, corto_handleAction_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_VALID)) {
        corto_ptr_setref(&((corto_delegatedata*)_this)->instance, instance);
        corto_ptr_setref(&((corto_delegatedata*)_this)->procedure, procedure);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_handleActionUpdate(corto_handleAction* _this, corto_object instance, corto_function procedure) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_ptr_setref(&((corto_delegatedata*)((corto_handleAction*)CORTO_OFFSET(_this, ((corto_type)corto_handleAction_o)->size)))->instance, instance);
            corto_ptr_setref(&((corto_delegatedata*)((corto_handleAction*)CORTO_OFFSET(_this, ((corto_type)corto_handleAction_o)->size)))->procedure, procedure);
        } else {
            corto_ptr_setref(&((corto_delegatedata*)_this)->instance, instance);
            corto_ptr_setref(&((corto_delegatedata*)_this)->procedure, procedure);
        }
        corto_update_end(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_handleAction* _corto_handleActionDeclare(void) {
    corto_handleAction* _this;
    _this = (corto_handleAction*)corto_declare(corto_handleAction_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_handleAction* _corto_handleActionDeclareChild(corto_object _parent, corto_string _id) {
    corto_handleAction* _this;
    _this = (corto_handleAction*)corto_declareChild(_parent, _id, corto_handleAction_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_handleActionDefine(corto_handleAction* _this, corto_object instance, corto_function procedure) {
    CORTO_UNUSED(_this);
    corto_ptr_setref(&((corto_delegatedata*)_this)->instance, instance);
    corto_ptr_setref(&((corto_delegatedata*)_this)->procedure, procedure);
    return corto_define(_this);
}

corto_handleAction* _corto_handleActionAssign(corto_handleAction* _this, corto_object instance, corto_function procedure) {
    CORTO_UNUSED(_this);
    corto_ptr_setref(&((corto_delegatedata*)_this)->instance, instance);
    corto_ptr_setref(&((corto_delegatedata*)_this)->procedure, procedure);
    return _this;
}

corto_int16 corto_handleActionCall(corto_handleAction *_delegate, corto_event* event) {
    if (_delegate->super.procedure) {
        if (_delegate->super.instance) {
            corto_call(_delegate->super.procedure, NULL, _delegate->super.instance, event);
        } else {
            corto_call(_delegate->super.procedure, NULL, event);
        }
    } else {
        return -1;
    }
    return 0;
}

corto_int16 corto_handleActionInitC(corto_handleAction *d, corto_void ___ (*callback)(corto_event*)) {
    d->super.instance = NULL;
    d->super.procedure = corto_declare(corto_function_o);
    d->super.procedure->kind = CORTO_PROCEDURE_CDECL;
    corto_function_parseParamString(d->super.procedure, "(/corto/vstore/event event)");
    d->super.procedure->fptr = (corto_word)callback;
    corto_define(d->super.procedure);
    return 0;
}

corto_int16 corto_handleActionInitCInstance(corto_handleAction *d, corto_object instance, corto_void ___ (*callback)(corto_object, corto_event*)) {
    d->super.instance = instance;
    corto_claim(instance);
    d->super.procedure = corto_declare(corto_function_o);
    d->super.procedure->kind = CORTO_PROCEDURE_CDECL;
    corto_function_parseParamString(d->super.procedure, "(object instance, /corto/vstore/event event)");
    d->super.procedure->fptr = (corto_word)callback;
    corto_define(d->super.procedure);
    return 0;
}

corto_invokeEvent* _corto_invokeEventCreate(uint16_t kind, corto_mount mount, corto_object instance, corto_function function, uintptr_t args) {
    corto_invokeEvent* _this;
    _this = (corto_invokeEvent*)corto_declare(corto_invokeEvent_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_VALID)) {
        ((corto_event*)_this)->kind = kind;
        corto_ptr_setref(&((corto_invokeEvent*)_this)->mount, mount);
        corto_ptr_setref(&((corto_invokeEvent*)_this)->instance, instance);
        corto_ptr_setref(&((corto_invokeEvent*)_this)->function, function);
        ((corto_invokeEvent*)_this)->args = args;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_invokeEvent* _corto_invokeEventCreateChild(corto_object _parent, corto_string _id, uint16_t kind, corto_mount mount, corto_object instance, corto_function function, uintptr_t args) {
    corto_invokeEvent* _this;
    _this = (corto_invokeEvent*)corto_declareChild(_parent, _id, corto_invokeEvent_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_VALID)) {
        ((corto_event*)_this)->kind = kind;
        corto_ptr_setref(&((corto_invokeEvent*)_this)->mount, mount);
        corto_ptr_setref(&((corto_invokeEvent*)_this)->instance, instance);
        corto_ptr_setref(&((corto_invokeEvent*)_this)->function, function);
        ((corto_invokeEvent*)_this)->args = args;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_invokeEventUpdate(corto_invokeEvent* _this, uint16_t kind, corto_mount mount, corto_object instance, corto_function function, uintptr_t args) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            ((corto_event*)((corto_invokeEvent*)CORTO_OFFSET(_this, ((corto_type)corto_invokeEvent_o)->size)))->kind = kind;
            corto_ptr_setref(&((corto_invokeEvent*)((corto_invokeEvent*)CORTO_OFFSET(_this, ((corto_type)corto_invokeEvent_o)->size)))->mount, mount);
            corto_ptr_setref(&((corto_invokeEvent*)((corto_invokeEvent*)CORTO_OFFSET(_this, ((corto_type)corto_invokeEvent_o)->size)))->instance, instance);
            corto_ptr_setref(&((corto_invokeEvent*)((corto_invokeEvent*)CORTO_OFFSET(_this, ((corto_type)corto_invokeEvent_o)->size)))->function, function);
            ((corto_invokeEvent*)((corto_invokeEvent*)CORTO_OFFSET(_this, ((corto_type)corto_invokeEvent_o)->size)))->args = args;
        } else {
            ((corto_event*)_this)->kind = kind;
            corto_ptr_setref(&((corto_invokeEvent*)_this)->mount, mount);
            corto_ptr_setref(&((corto_invokeEvent*)_this)->instance, instance);
            corto_ptr_setref(&((corto_invokeEvent*)_this)->function, function);
            ((corto_invokeEvent*)_this)->args = args;
        }
        corto_update_end(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_invokeEvent* _corto_invokeEventDeclare(void) {
    corto_invokeEvent* _this;
    _this = (corto_invokeEvent*)corto_declare(corto_invokeEvent_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_invokeEvent* _corto_invokeEventDeclareChild(corto_object _parent, corto_string _id) {
    corto_invokeEvent* _this;
    _this = (corto_invokeEvent*)corto_declareChild(_parent, _id, corto_invokeEvent_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_invokeEventDefine(corto_invokeEvent* _this, uint16_t kind, corto_mount mount, corto_object instance, corto_function function, uintptr_t args) {
    CORTO_UNUSED(_this);
    ((corto_event*)_this)->kind = kind;
    corto_ptr_setref(&((corto_invokeEvent*)_this)->mount, mount);
    corto_ptr_setref(&((corto_invokeEvent*)_this)->instance, instance);
    corto_ptr_setref(&((corto_invokeEvent*)_this)->function, function);
    ((corto_invokeEvent*)_this)->args = args;
    return corto_define(_this);
}

corto_invokeEvent* _corto_invokeEventAssign(corto_invokeEvent* _this, uint16_t kind, corto_mount mount, corto_object instance, corto_function function, uintptr_t args) {
    CORTO_UNUSED(_this);
    ((corto_event*)_this)->kind = kind;
    corto_ptr_setref(&((corto_invokeEvent*)_this)->mount, mount);
    corto_ptr_setref(&((corto_invokeEvent*)_this)->instance, instance);
    corto_ptr_setref(&((corto_invokeEvent*)_this)->function, function);
    ((corto_invokeEvent*)_this)->args = args;
    return _this;
}

corto_loader _corto_loaderCreate(bool autoLoad) {
    corto_loader _this;
    _this = (corto_loader)corto_declare(corto_loader_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_VALID)) {
        ((corto_loader)_this)->autoLoad = autoLoad;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_loader _corto_loaderCreateChild(corto_object _parent, corto_string _id, bool autoLoad) {
    corto_loader _this;
    _this = (corto_loader)corto_declareChild(_parent, _id, corto_loader_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_VALID)) {
        ((corto_loader)_this)->autoLoad = autoLoad;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_loaderUpdate(corto_loader _this, bool autoLoad) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            ((corto_loader)((corto_loader)CORTO_OFFSET(_this, ((corto_type)corto_loader_o)->size)))->autoLoad = autoLoad;
        } else {
            ((corto_loader)_this)->autoLoad = autoLoad;
        }
        corto_update_end(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_loader _corto_loaderDeclare(void) {
    corto_loader _this;
    _this = (corto_loader)corto_declare(corto_loader_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_loader _corto_loaderDeclareChild(corto_object _parent, corto_string _id) {
    corto_loader _this;
    _this = (corto_loader)corto_declareChild(_parent, _id, corto_loader_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_loaderDefine(corto_loader _this, bool autoLoad) {
    CORTO_UNUSED(_this);
    ((corto_loader)_this)->autoLoad = autoLoad;
    return corto_define(_this);
}

corto_loader _corto_loaderAssign(corto_loader _this, bool autoLoad) {
    CORTO_UNUSED(_this);
    ((corto_loader)_this)->autoLoad = autoLoad;
    return _this;
}

corto_mount _corto_mountCreate(corto_query* query, corto_string contentType, corto_mountPolicy* policy) {
    corto_mount _this;
    _this = (corto_mount)corto_declare(corto_mount_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_VALID)) {
        if (query) {
            corto_ptr_copy(&((corto_subscriber)_this)->query, corto_query_o, query);
        }
        corto_ptr_setstr(&((corto_subscriber)_this)->contentType, contentType);
        if (policy) {
            corto_ptr_copy(&((corto_mount)_this)->policy, corto_mountPolicy_o, policy);
        }
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_mount _corto_mountCreateChild(corto_object _parent, corto_string _id, corto_query* query, corto_string contentType, corto_mountPolicy* policy) {
    corto_mount _this;
    _this = (corto_mount)corto_declareChild(_parent, _id, corto_mount_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_VALID)) {
        if (query) {
            corto_ptr_copy(&((corto_subscriber)_this)->query, corto_query_o, query);
        }
        corto_ptr_setstr(&((corto_subscriber)_this)->contentType, contentType);
        if (policy) {
            corto_ptr_copy(&((corto_mount)_this)->policy, corto_mountPolicy_o, policy);
        }
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_mountUpdate(corto_mount _this, corto_query* query, corto_string contentType, corto_mountPolicy* policy) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            if (query) {
                corto_ptr_copy(&((corto_subscriber)((corto_mount)CORTO_OFFSET(_this, ((corto_type)corto_mount_o)->size)))->query, corto_query_o, query);
            }
            corto_ptr_setstr(&((corto_subscriber)((corto_mount)CORTO_OFFSET(_this, ((corto_type)corto_mount_o)->size)))->contentType, contentType);
            if (policy) {
                corto_ptr_copy(&((corto_mount)((corto_mount)CORTO_OFFSET(_this, ((corto_type)corto_mount_o)->size)))->policy, corto_mountPolicy_o, policy);
            }
        } else {
            if (query) {
                corto_ptr_copy(&((corto_subscriber)_this)->query, corto_query_o, query);
            }
            corto_ptr_setstr(&((corto_subscriber)_this)->contentType, contentType);
            if (policy) {
                corto_ptr_copy(&((corto_mount)_this)->policy, corto_mountPolicy_o, policy);
            }
        }
        corto_update_end(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_mount _corto_mountDeclare(void) {
    corto_mount _this;
    _this = (corto_mount)corto_declare(corto_mount_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_mount _corto_mountDeclareChild(corto_object _parent, corto_string _id) {
    corto_mount _this;
    _this = (corto_mount)corto_declareChild(_parent, _id, corto_mount_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_mountDefine(corto_mount _this, corto_query* query, corto_string contentType, corto_mountPolicy* policy) {
    CORTO_UNUSED(_this);
    if (query) {
        corto_ptr_copy(&((corto_subscriber)_this)->query, corto_query_o, query);
    }
    corto_ptr_setstr(&((corto_subscriber)_this)->contentType, contentType);
    if (policy) {
        corto_ptr_copy(&((corto_mount)_this)->policy, corto_mountPolicy_o, policy);
    }
    return corto_define(_this);
}

corto_mount _corto_mountAssign(corto_mount _this, corto_query* query, corto_string contentType, corto_mountPolicy* policy) {
    CORTO_UNUSED(_this);
    if (query) {
        corto_ptr_copy(&((corto_subscriber)_this)->query, corto_query_o, query);
    }
    corto_ptr_setstr(&((corto_subscriber)_this)->contentType, contentType);
    if (policy) {
        corto_ptr_copy(&((corto_mount)_this)->policy, corto_mountPolicy_o, policy);
    }
    return _this;
}

corto_mountMask* _corto_mountMaskCreate(corto_mountMask value) {
    corto_mountMask* _this;
    _this = (corto_mountMask*)corto_declare(corto_mountMask_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_VALID)) {
        *_this = value;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_mountMask* _corto_mountMaskCreateChild(corto_object _parent, corto_string _id, corto_mountMask value) {
    corto_mountMask* _this;
    _this = (corto_mountMask*)corto_declareChild(_parent, _id, corto_mountMask_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_VALID)) {
        *_this = value;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_mountMaskUpdate(corto_mountMask* _this, corto_mountMask value) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            *((corto_mountMask*)CORTO_OFFSET(_this, ((corto_type)corto_mountMask_o)->size)) = value;
        } else {
            *_this = value;
        }
        corto_update_end(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_mountMask* _corto_mountMaskDeclare(void) {
    corto_mountMask* _this;
    _this = (corto_mountMask*)corto_declare(corto_mountMask_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_mountMask* _corto_mountMaskDeclareChild(corto_object _parent, corto_string _id) {
    corto_mountMask* _this;
    _this = (corto_mountMask*)corto_declareChild(_parent, _id, corto_mountMask_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_mountMaskDefine(corto_mountMask* _this, corto_mountMask value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return corto_define(_this);
}

corto_mountMask* _corto_mountMaskAssign(corto_mountMask* _this, corto_mountMask value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

corto_mountPolicy* _corto_mountPolicyCreate(corto_ownership ownership, corto_mountMask mask, double sampleRate, corto_queuePolicy* queue, uint64_t expiryTime, bool filterResults) {
    corto_mountPolicy* _this;
    _this = (corto_mountPolicy*)corto_declare(corto_mountPolicy_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_VALID)) {
        ((corto_mountPolicy*)_this)->ownership = ownership;
        ((corto_mountPolicy*)_this)->mask = mask;
        ((corto_mountPolicy*)_this)->sampleRate = sampleRate;
        if (queue) {
            corto_ptr_copy(&((corto_mountPolicy*)_this)->queue, corto_queuePolicy_o, queue);
        }
        ((corto_mountPolicy*)_this)->expiryTime = expiryTime;
        ((corto_mountPolicy*)_this)->filterResults = filterResults;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_mountPolicy* _corto_mountPolicyCreateChild(corto_object _parent, corto_string _id, corto_ownership ownership, corto_mountMask mask, double sampleRate, corto_queuePolicy* queue, uint64_t expiryTime, bool filterResults) {
    corto_mountPolicy* _this;
    _this = (corto_mountPolicy*)corto_declareChild(_parent, _id, corto_mountPolicy_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_VALID)) {
        ((corto_mountPolicy*)_this)->ownership = ownership;
        ((corto_mountPolicy*)_this)->mask = mask;
        ((corto_mountPolicy*)_this)->sampleRate = sampleRate;
        if (queue) {
            corto_ptr_copy(&((corto_mountPolicy*)_this)->queue, corto_queuePolicy_o, queue);
        }
        ((corto_mountPolicy*)_this)->expiryTime = expiryTime;
        ((corto_mountPolicy*)_this)->filterResults = filterResults;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_mountPolicyUpdate(corto_mountPolicy* _this, corto_ownership ownership, corto_mountMask mask, double sampleRate, corto_queuePolicy* queue, uint64_t expiryTime, bool filterResults) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            ((corto_mountPolicy*)((corto_mountPolicy*)CORTO_OFFSET(_this, ((corto_type)corto_mountPolicy_o)->size)))->ownership = ownership;
            ((corto_mountPolicy*)((corto_mountPolicy*)CORTO_OFFSET(_this, ((corto_type)corto_mountPolicy_o)->size)))->mask = mask;
            ((corto_mountPolicy*)((corto_mountPolicy*)CORTO_OFFSET(_this, ((corto_type)corto_mountPolicy_o)->size)))->sampleRate = sampleRate;
            if (queue) {
                corto_ptr_copy(&((corto_mountPolicy*)((corto_mountPolicy*)CORTO_OFFSET(_this, ((corto_type)corto_mountPolicy_o)->size)))->queue, corto_queuePolicy_o, queue);
            }
            ((corto_mountPolicy*)((corto_mountPolicy*)CORTO_OFFSET(_this, ((corto_type)corto_mountPolicy_o)->size)))->expiryTime = expiryTime;
            ((corto_mountPolicy*)((corto_mountPolicy*)CORTO_OFFSET(_this, ((corto_type)corto_mountPolicy_o)->size)))->filterResults = filterResults;
        } else {
            ((corto_mountPolicy*)_this)->ownership = ownership;
            ((corto_mountPolicy*)_this)->mask = mask;
            ((corto_mountPolicy*)_this)->sampleRate = sampleRate;
            if (queue) {
                corto_ptr_copy(&((corto_mountPolicy*)_this)->queue, corto_queuePolicy_o, queue);
            }
            ((corto_mountPolicy*)_this)->expiryTime = expiryTime;
            ((corto_mountPolicy*)_this)->filterResults = filterResults;
        }
        corto_update_end(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_mountPolicy* _corto_mountPolicyDeclare(void) {
    corto_mountPolicy* _this;
    _this = (corto_mountPolicy*)corto_declare(corto_mountPolicy_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_mountPolicy* _corto_mountPolicyDeclareChild(corto_object _parent, corto_string _id) {
    corto_mountPolicy* _this;
    _this = (corto_mountPolicy*)corto_declareChild(_parent, _id, corto_mountPolicy_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_mountPolicyDefine(corto_mountPolicy* _this, corto_ownership ownership, corto_mountMask mask, double sampleRate, corto_queuePolicy* queue, uint64_t expiryTime, bool filterResults) {
    CORTO_UNUSED(_this);
    ((corto_mountPolicy*)_this)->ownership = ownership;
    ((corto_mountPolicy*)_this)->mask = mask;
    ((corto_mountPolicy*)_this)->sampleRate = sampleRate;
    if (queue) {
        corto_ptr_copy(&((corto_mountPolicy*)_this)->queue, corto_queuePolicy_o, queue);
    }
    ((corto_mountPolicy*)_this)->expiryTime = expiryTime;
    ((corto_mountPolicy*)_this)->filterResults = filterResults;
    return corto_define(_this);
}

corto_mountPolicy* _corto_mountPolicyAssign(corto_mountPolicy* _this, corto_ownership ownership, corto_mountMask mask, double sampleRate, corto_queuePolicy* queue, uint64_t expiryTime, bool filterResults) {
    CORTO_UNUSED(_this);
    ((corto_mountPolicy*)_this)->ownership = ownership;
    ((corto_mountPolicy*)_this)->mask = mask;
    ((corto_mountPolicy*)_this)->sampleRate = sampleRate;
    if (queue) {
        corto_ptr_copy(&((corto_mountPolicy*)_this)->queue, corto_queuePolicy_o, queue);
    }
    ((corto_mountPolicy*)_this)->expiryTime = expiryTime;
    ((corto_mountPolicy*)_this)->filterResults = filterResults;
    return _this;
}

corto_mountStats* _corto_mountStatsCreate(uint64_t declares, uint64_t updates, uint64_t deletes) {
    corto_mountStats* _this;
    _this = (corto_mountStats*)corto_declare(corto_mountStats_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_VALID)) {
        ((corto_mountStats*)_this)->declares = declares;
        ((corto_mountStats*)_this)->updates = updates;
        ((corto_mountStats*)_this)->deletes = deletes;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_mountStats* _corto_mountStatsCreateChild(corto_object _parent, corto_string _id, uint64_t declares, uint64_t updates, uint64_t deletes) {
    corto_mountStats* _this;
    _this = (corto_mountStats*)corto_declareChild(_parent, _id, corto_mountStats_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_VALID)) {
        ((corto_mountStats*)_this)->declares = declares;
        ((corto_mountStats*)_this)->updates = updates;
        ((corto_mountStats*)_this)->deletes = deletes;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_mountStatsUpdate(corto_mountStats* _this, uint64_t declares, uint64_t updates, uint64_t deletes) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            ((corto_mountStats*)((corto_mountStats*)CORTO_OFFSET(_this, ((corto_type)corto_mountStats_o)->size)))->declares = declares;
            ((corto_mountStats*)((corto_mountStats*)CORTO_OFFSET(_this, ((corto_type)corto_mountStats_o)->size)))->updates = updates;
            ((corto_mountStats*)((corto_mountStats*)CORTO_OFFSET(_this, ((corto_type)corto_mountStats_o)->size)))->deletes = deletes;
        } else {
            ((corto_mountStats*)_this)->declares = declares;
            ((corto_mountStats*)_this)->updates = updates;
            ((corto_mountStats*)_this)->deletes = deletes;
        }
        corto_update_end(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_mountStats* _corto_mountStatsDeclare(void) {
    corto_mountStats* _this;
    _this = (corto_mountStats*)corto_declare(corto_mountStats_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_mountStats* _corto_mountStatsDeclareChild(corto_object _parent, corto_string _id) {
    corto_mountStats* _this;
    _this = (corto_mountStats*)corto_declareChild(_parent, _id, corto_mountStats_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_mountStatsDefine(corto_mountStats* _this, uint64_t declares, uint64_t updates, uint64_t deletes) {
    CORTO_UNUSED(_this);
    ((corto_mountStats*)_this)->declares = declares;
    ((corto_mountStats*)_this)->updates = updates;
    ((corto_mountStats*)_this)->deletes = deletes;
    return corto_define(_this);
}

corto_mountStats* _corto_mountStatsAssign(corto_mountStats* _this, uint64_t declares, uint64_t updates, uint64_t deletes) {
    CORTO_UNUSED(_this);
    ((corto_mountStats*)_this)->declares = declares;
    ((corto_mountStats*)_this)->updates = updates;
    ((corto_mountStats*)_this)->deletes = deletes;
    return _this;
}

corto_mountSubscription* _corto_mountSubscriptionCreate(corto_query* query, uint32_t mountCount, uint32_t subscriberCount, uintptr_t mountCtx, uintptr_t subscriberCtx) {
    corto_mountSubscription* _this;
    _this = (corto_mountSubscription*)corto_declare(corto_mountSubscription_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_VALID)) {
        if (query) {
            corto_ptr_copy(&((corto_mountSubscription*)_this)->query, corto_query_o, query);
        }
        ((corto_mountSubscription*)_this)->mountCount = mountCount;
        ((corto_mountSubscription*)_this)->subscriberCount = subscriberCount;
        ((corto_mountSubscription*)_this)->mountCtx = mountCtx;
        ((corto_mountSubscription*)_this)->subscriberCtx = subscriberCtx;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_mountSubscription* _corto_mountSubscriptionCreateChild(corto_object _parent, corto_string _id, corto_query* query, uint32_t mountCount, uint32_t subscriberCount, uintptr_t mountCtx, uintptr_t subscriberCtx) {
    corto_mountSubscription* _this;
    _this = (corto_mountSubscription*)corto_declareChild(_parent, _id, corto_mountSubscription_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_VALID)) {
        if (query) {
            corto_ptr_copy(&((corto_mountSubscription*)_this)->query, corto_query_o, query);
        }
        ((corto_mountSubscription*)_this)->mountCount = mountCount;
        ((corto_mountSubscription*)_this)->subscriberCount = subscriberCount;
        ((corto_mountSubscription*)_this)->mountCtx = mountCtx;
        ((corto_mountSubscription*)_this)->subscriberCtx = subscriberCtx;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_mountSubscriptionUpdate(corto_mountSubscription* _this, corto_query* query, uint32_t mountCount, uint32_t subscriberCount, uintptr_t mountCtx, uintptr_t subscriberCtx) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            if (query) {
                corto_ptr_copy(&((corto_mountSubscription*)((corto_mountSubscription*)CORTO_OFFSET(_this, ((corto_type)corto_mountSubscription_o)->size)))->query, corto_query_o, query);
            }
            ((corto_mountSubscription*)((corto_mountSubscription*)CORTO_OFFSET(_this, ((corto_type)corto_mountSubscription_o)->size)))->mountCount = mountCount;
            ((corto_mountSubscription*)((corto_mountSubscription*)CORTO_OFFSET(_this, ((corto_type)corto_mountSubscription_o)->size)))->subscriberCount = subscriberCount;
            ((corto_mountSubscription*)((corto_mountSubscription*)CORTO_OFFSET(_this, ((corto_type)corto_mountSubscription_o)->size)))->mountCtx = mountCtx;
            ((corto_mountSubscription*)((corto_mountSubscription*)CORTO_OFFSET(_this, ((corto_type)corto_mountSubscription_o)->size)))->subscriberCtx = subscriberCtx;
        } else {
            if (query) {
                corto_ptr_copy(&((corto_mountSubscription*)_this)->query, corto_query_o, query);
            }
            ((corto_mountSubscription*)_this)->mountCount = mountCount;
            ((corto_mountSubscription*)_this)->subscriberCount = subscriberCount;
            ((corto_mountSubscription*)_this)->mountCtx = mountCtx;
            ((corto_mountSubscription*)_this)->subscriberCtx = subscriberCtx;
        }
        corto_update_end(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_mountSubscription* _corto_mountSubscriptionDeclare(void) {
    corto_mountSubscription* _this;
    _this = (corto_mountSubscription*)corto_declare(corto_mountSubscription_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_mountSubscription* _corto_mountSubscriptionDeclareChild(corto_object _parent, corto_string _id) {
    corto_mountSubscription* _this;
    _this = (corto_mountSubscription*)corto_declareChild(_parent, _id, corto_mountSubscription_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_mountSubscriptionDefine(corto_mountSubscription* _this, corto_query* query, uint32_t mountCount, uint32_t subscriberCount, uintptr_t mountCtx, uintptr_t subscriberCtx) {
    CORTO_UNUSED(_this);
    if (query) {
        corto_ptr_copy(&((corto_mountSubscription*)_this)->query, corto_query_o, query);
    }
    ((corto_mountSubscription*)_this)->mountCount = mountCount;
    ((corto_mountSubscription*)_this)->subscriberCount = subscriberCount;
    ((corto_mountSubscription*)_this)->mountCtx = mountCtx;
    ((corto_mountSubscription*)_this)->subscriberCtx = subscriberCtx;
    return corto_define(_this);
}

corto_mountSubscription* _corto_mountSubscriptionAssign(corto_mountSubscription* _this, corto_query* query, uint32_t mountCount, uint32_t subscriberCount, uintptr_t mountCtx, uintptr_t subscriberCtx) {
    CORTO_UNUSED(_this);
    if (query) {
        corto_ptr_copy(&((corto_mountSubscription*)_this)->query, corto_query_o, query);
    }
    ((corto_mountSubscription*)_this)->mountCount = mountCount;
    ((corto_mountSubscription*)_this)->subscriberCount = subscriberCount;
    ((corto_mountSubscription*)_this)->mountCtx = mountCtx;
    ((corto_mountSubscription*)_this)->subscriberCtx = subscriberCtx;
    return _this;
}

corto_mountSubscriptionList* _corto_mountSubscriptionListCreate(corto_uint32 length, corto_mountSubscription* elements) {
    corto_mountSubscriptionList* _this;
    _this = (corto_mountSubscriptionList*)corto_declare(corto_mountSubscriptionList_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_VALID)) {
        corto_uint32 i = 0;
        corto_mountSubscriptionListClear(*_this);
        for (i = 0; i < length; i ++) {
            corto_mountSubscriptionListAppend(*_this, &elements[i]);
        }
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_mountSubscriptionList* _corto_mountSubscriptionListCreateChild(corto_object _parent, corto_string _id, corto_uint32 length, corto_mountSubscription* elements) {
    corto_mountSubscriptionList* _this;
    _this = (corto_mountSubscriptionList*)corto_declareChild(_parent, _id, corto_mountSubscriptionList_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_VALID)) {
        corto_uint32 i = 0;
        corto_mountSubscriptionListClear(*_this);
        for (i = 0; i < length; i ++) {
            corto_mountSubscriptionListAppend(*_this, &elements[i]);
        }
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_mountSubscriptionListUpdate(corto_mountSubscriptionList* _this, corto_uint32 length, corto_mountSubscription* elements) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_uint32 i = 0;
            corto_mountSubscriptionListClear(*((corto_mountSubscriptionList*)CORTO_OFFSET(_this, ((corto_type)corto_mountSubscriptionList_o)->size)));
            for (i = 0; i < length; i ++) {
                corto_mountSubscriptionListAppend(*((corto_mountSubscriptionList*)CORTO_OFFSET(_this, ((corto_type)corto_mountSubscriptionList_o)->size)), &elements[i]);
            }
        } else {
            corto_uint32 i = 0;
            corto_mountSubscriptionListClear(*_this);
            for (i = 0; i < length; i ++) {
                corto_mountSubscriptionListAppend(*_this, &elements[i]);
            }
        }
        corto_update_end(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_mountSubscriptionList* _corto_mountSubscriptionListDeclare(void) {
    corto_mountSubscriptionList* _this;
    _this = (corto_mountSubscriptionList*)corto_declare(corto_mountSubscriptionList_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_mountSubscriptionList* _corto_mountSubscriptionListDeclareChild(corto_object _parent, corto_string _id) {
    corto_mountSubscriptionList* _this;
    _this = (corto_mountSubscriptionList*)corto_declareChild(_parent, _id, corto_mountSubscriptionList_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_mountSubscriptionListDefine(corto_mountSubscriptionList* _this, corto_uint32 length, corto_mountSubscription* elements) {
    CORTO_UNUSED(_this);
    corto_uint32 i = 0;
    corto_mountSubscriptionListClear(*_this);
    for (i = 0; i < length; i ++) {
        corto_mountSubscriptionListAppend(*_this, &elements[i]);
    }
    return corto_define(_this);
}

corto_mountSubscriptionList* _corto_mountSubscriptionListAssign(corto_mountSubscriptionList* _this, corto_uint32 length, corto_mountSubscription* elements) {
    CORTO_UNUSED(_this);
    corto_uint32 i = 0;
    corto_mountSubscriptionListClear(*_this);
    for (i = 0; i < length; i ++) {
        corto_mountSubscriptionListAppend(*_this, &elements[i]);
    }
    return _this;
}

corto_objectIter* _corto_objectIterCreate(void) {
    corto_objectIter* _this;
    _this = (corto_objectIter*)corto_declare(corto_objectIter_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_VALID)) {
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_objectIter* _corto_objectIterCreateChild(corto_object _parent, corto_string _id) {
    corto_objectIter* _this;
    _this = (corto_objectIter*)corto_declareChild(_parent, _id, corto_objectIter_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_VALID)) {
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_objectIterUpdate(corto_objectIter* _this) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
        } else {
        }
        corto_update_end(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_objectIter* _corto_objectIterDeclare(void) {
    corto_objectIter* _this;
    _this = (corto_objectIter*)corto_declare(corto_objectIter_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_objectIter* _corto_objectIterDeclareChild(corto_object _parent, corto_string _id) {
    corto_objectIter* _this;
    _this = (corto_objectIter*)corto_declareChild(_parent, _id, corto_objectIter_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_objectIterDefine(corto_objectIter* _this) {
    CORTO_UNUSED(_this);
    return corto_define(_this);
}

corto_objectIter* _corto_objectIterAssign(corto_objectIter* _this) {
    CORTO_UNUSED(_this);
    return _this;
}

corto_observer _corto_observerCreate(corto_eventMask mask, corto_object observable, corto_object instance, corto_dispatcher dispatcher, corto_type type, bool enabled, void(*_impl)(void)) {
    corto_observer _this;
    _this = (corto_observer)corto_declare(corto_observer_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_VALID)) {
        ((corto_observer)_this)->mask = mask;
        corto_ptr_setref(&((corto_observer)_this)->observable, observable);
        corto_ptr_setref(&((corto_observer)_this)->instance, instance);
        corto_ptr_setref(&((corto_observer)_this)->dispatcher, dispatcher);
        corto_ptr_setref(&((corto_observer)_this)->type, type);
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

corto_observer _corto_observerCreateChild(corto_object _parent, corto_string _id, corto_eventMask mask, corto_object observable, corto_object instance, corto_dispatcher dispatcher, corto_type type, bool enabled, void(*_impl)(void)) {
    corto_observer _this;
    _this = (corto_observer)corto_declareChild(_parent, _id, corto_observer_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_VALID)) {
        ((corto_observer)_this)->mask = mask;
        corto_ptr_setref(&((corto_observer)_this)->observable, observable);
        corto_ptr_setref(&((corto_observer)_this)->instance, instance);
        corto_ptr_setref(&((corto_observer)_this)->dispatcher, dispatcher);
        corto_ptr_setref(&((corto_observer)_this)->type, type);
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

corto_int16 _corto_observerUpdate(corto_observer _this, corto_eventMask mask, corto_object observable, corto_object instance, corto_dispatcher dispatcher, corto_type type, bool enabled, void(*_impl)(void)) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            ((corto_observer)((corto_observer)CORTO_OFFSET(_this, ((corto_type)corto_observer_o)->size)))->mask = mask;
            corto_ptr_setref(&((corto_observer)((corto_observer)CORTO_OFFSET(_this, ((corto_type)corto_observer_o)->size)))->observable, observable);
            corto_ptr_setref(&((corto_observer)((corto_observer)CORTO_OFFSET(_this, ((corto_type)corto_observer_o)->size)))->instance, instance);
            corto_ptr_setref(&((corto_observer)((corto_observer)CORTO_OFFSET(_this, ((corto_type)corto_observer_o)->size)))->dispatcher, dispatcher);
            corto_ptr_setref(&((corto_observer)((corto_observer)CORTO_OFFSET(_this, ((corto_type)corto_observer_o)->size)))->type, type);
            ((corto_observer)((corto_observer)CORTO_OFFSET(_this, ((corto_type)corto_observer_o)->size)))->enabled = enabled;
            corto_function(((corto_observer)CORTO_OFFSET(_this, ((corto_type)corto_observer_o)->size)))->kind = CORTO_PROCEDURE_CDECL;
            corto_function(((corto_observer)CORTO_OFFSET(_this, ((corto_type)corto_observer_o)->size)))->fptr = (corto_word)_impl;
        } else {
            ((corto_observer)_this)->mask = mask;
            corto_ptr_setref(&((corto_observer)_this)->observable, observable);
            corto_ptr_setref(&((corto_observer)_this)->instance, instance);
            corto_ptr_setref(&((corto_observer)_this)->dispatcher, dispatcher);
            corto_ptr_setref(&((corto_observer)_this)->type, type);
            ((corto_observer)_this)->enabled = enabled;
            corto_function(_this)->kind = CORTO_PROCEDURE_CDECL;
            corto_function(_this)->fptr = (corto_word)_impl;
        }
        corto_update_end(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_observer _corto_observerDeclare(void) {
    corto_observer _this;
    _this = (corto_observer)corto_declare(corto_observer_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_observer _corto_observerDeclareChild(corto_object _parent, corto_string _id) {
    corto_observer _this;
    _this = (corto_observer)corto_declareChild(_parent, _id, corto_observer_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_observerDefine(corto_observer _this, corto_eventMask mask, corto_object observable, corto_object instance, corto_dispatcher dispatcher, corto_type type, bool enabled, void(*_impl)(void)) {
    CORTO_UNUSED(_this);
    ((corto_observer)_this)->mask = mask;
    corto_ptr_setref(&((corto_observer)_this)->observable, observable);
    corto_ptr_setref(&((corto_observer)_this)->instance, instance);
    corto_ptr_setref(&((corto_observer)_this)->dispatcher, dispatcher);
    corto_ptr_setref(&((corto_observer)_this)->type, type);
    ((corto_observer)_this)->enabled = enabled;
    corto_function(_this)->kind = CORTO_PROCEDURE_CDECL;
    corto_function(_this)->fptr = (corto_word)_impl;
    return corto_define(_this);
}

corto_observer _corto_observerAssign(corto_observer _this, corto_eventMask mask, corto_object observable, corto_object instance, corto_dispatcher dispatcher, corto_type type, bool enabled, void(*_impl)(void)) {
    CORTO_UNUSED(_this);
    ((corto_observer)_this)->mask = mask;
    corto_ptr_setref(&((corto_observer)_this)->observable, observable);
    corto_ptr_setref(&((corto_observer)_this)->instance, instance);
    corto_ptr_setref(&((corto_observer)_this)->dispatcher, dispatcher);
    corto_ptr_setref(&((corto_observer)_this)->type, type);
    ((corto_observer)_this)->enabled = enabled;
    corto_function(_this)->kind = CORTO_PROCEDURE_CDECL;
    corto_function(_this)->fptr = (corto_word)_impl;
    return _this;
}

corto_observerEvent* _corto_observerEventCreate(uint16_t kind, corto_observer observer, corto_object instance, corto_object source, corto_eventMask event, corto_object data, uintptr_t thread) {
    corto_observerEvent* _this;
    _this = (corto_observerEvent*)corto_declare(corto_observerEvent_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_VALID)) {
        ((corto_event*)_this)->kind = kind;
        corto_ptr_setref(&((corto_observerEvent*)_this)->observer, observer);
        corto_ptr_setref(&((corto_observerEvent*)_this)->instance, instance);
        corto_ptr_setref(&((corto_observerEvent*)_this)->source, source);
        ((corto_observerEvent*)_this)->event = event;
        corto_ptr_setref(&((corto_observerEvent*)_this)->data, data);
        ((corto_observerEvent*)_this)->thread = thread;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_observerEvent* _corto_observerEventCreateChild(corto_object _parent, corto_string _id, uint16_t kind, corto_observer observer, corto_object instance, corto_object source, corto_eventMask event, corto_object data, uintptr_t thread) {
    corto_observerEvent* _this;
    _this = (corto_observerEvent*)corto_declareChild(_parent, _id, corto_observerEvent_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_VALID)) {
        ((corto_event*)_this)->kind = kind;
        corto_ptr_setref(&((corto_observerEvent*)_this)->observer, observer);
        corto_ptr_setref(&((corto_observerEvent*)_this)->instance, instance);
        corto_ptr_setref(&((corto_observerEvent*)_this)->source, source);
        ((corto_observerEvent*)_this)->event = event;
        corto_ptr_setref(&((corto_observerEvent*)_this)->data, data);
        ((corto_observerEvent*)_this)->thread = thread;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_observerEventUpdate(corto_observerEvent* _this, uint16_t kind, corto_observer observer, corto_object instance, corto_object source, corto_eventMask event, corto_object data, uintptr_t thread) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            ((corto_event*)((corto_observerEvent*)CORTO_OFFSET(_this, ((corto_type)corto_observerEvent_o)->size)))->kind = kind;
            corto_ptr_setref(&((corto_observerEvent*)((corto_observerEvent*)CORTO_OFFSET(_this, ((corto_type)corto_observerEvent_o)->size)))->observer, observer);
            corto_ptr_setref(&((corto_observerEvent*)((corto_observerEvent*)CORTO_OFFSET(_this, ((corto_type)corto_observerEvent_o)->size)))->instance, instance);
            corto_ptr_setref(&((corto_observerEvent*)((corto_observerEvent*)CORTO_OFFSET(_this, ((corto_type)corto_observerEvent_o)->size)))->source, source);
            ((corto_observerEvent*)((corto_observerEvent*)CORTO_OFFSET(_this, ((corto_type)corto_observerEvent_o)->size)))->event = event;
            corto_ptr_setref(&((corto_observerEvent*)((corto_observerEvent*)CORTO_OFFSET(_this, ((corto_type)corto_observerEvent_o)->size)))->data, data);
            ((corto_observerEvent*)((corto_observerEvent*)CORTO_OFFSET(_this, ((corto_type)corto_observerEvent_o)->size)))->thread = thread;
        } else {
            ((corto_event*)_this)->kind = kind;
            corto_ptr_setref(&((corto_observerEvent*)_this)->observer, observer);
            corto_ptr_setref(&((corto_observerEvent*)_this)->instance, instance);
            corto_ptr_setref(&((corto_observerEvent*)_this)->source, source);
            ((corto_observerEvent*)_this)->event = event;
            corto_ptr_setref(&((corto_observerEvent*)_this)->data, data);
            ((corto_observerEvent*)_this)->thread = thread;
        }
        corto_update_end(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_observerEvent* _corto_observerEventDeclare(void) {
    corto_observerEvent* _this;
    _this = (corto_observerEvent*)corto_declare(corto_observerEvent_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_observerEvent* _corto_observerEventDeclareChild(corto_object _parent, corto_string _id) {
    corto_observerEvent* _this;
    _this = (corto_observerEvent*)corto_declareChild(_parent, _id, corto_observerEvent_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_observerEventDefine(corto_observerEvent* _this, uint16_t kind, corto_observer observer, corto_object instance, corto_object source, corto_eventMask event, corto_object data, uintptr_t thread) {
    CORTO_UNUSED(_this);
    ((corto_event*)_this)->kind = kind;
    corto_ptr_setref(&((corto_observerEvent*)_this)->observer, observer);
    corto_ptr_setref(&((corto_observerEvent*)_this)->instance, instance);
    corto_ptr_setref(&((corto_observerEvent*)_this)->source, source);
    ((corto_observerEvent*)_this)->event = event;
    corto_ptr_setref(&((corto_observerEvent*)_this)->data, data);
    ((corto_observerEvent*)_this)->thread = thread;
    return corto_define(_this);
}

corto_observerEvent* _corto_observerEventAssign(corto_observerEvent* _this, uint16_t kind, corto_observer observer, corto_object instance, corto_object source, corto_eventMask event, corto_object data, uintptr_t thread) {
    CORTO_UNUSED(_this);
    ((corto_event*)_this)->kind = kind;
    corto_ptr_setref(&((corto_observerEvent*)_this)->observer, observer);
    corto_ptr_setref(&((corto_observerEvent*)_this)->instance, instance);
    corto_ptr_setref(&((corto_observerEvent*)_this)->source, source);
    ((corto_observerEvent*)_this)->event = event;
    corto_ptr_setref(&((corto_observerEvent*)_this)->data, data);
    ((corto_observerEvent*)_this)->thread = thread;
    return _this;
}

corto_operatorKind* _corto_operatorKindCreate(corto_operatorKind value) {
    corto_operatorKind* _this;
    _this = (corto_operatorKind*)corto_declare(corto_operatorKind_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_VALID)) {
        *_this = value;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_operatorKind* _corto_operatorKindCreateChild(corto_object _parent, corto_string _id, corto_operatorKind value) {
    corto_operatorKind* _this;
    _this = (corto_operatorKind*)corto_declareChild(_parent, _id, corto_operatorKind_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_VALID)) {
        *_this = value;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_operatorKindUpdate(corto_operatorKind* _this, corto_operatorKind value) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            *((corto_operatorKind*)CORTO_OFFSET(_this, ((corto_type)corto_operatorKind_o)->size)) = value;
        } else {
            *_this = value;
        }
        corto_update_end(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_operatorKind* _corto_operatorKindDeclare(void) {
    corto_operatorKind* _this;
    _this = (corto_operatorKind*)corto_declare(corto_operatorKind_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_operatorKind* _corto_operatorKindDeclareChild(corto_object _parent, corto_string _id) {
    corto_operatorKind* _this;
    _this = (corto_operatorKind*)corto_declareChild(_parent, _id, corto_operatorKind_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_operatorKindDefine(corto_operatorKind* _this, corto_operatorKind value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return corto_define(_this);
}

corto_operatorKind* _corto_operatorKindAssign(corto_operatorKind* _this, corto_operatorKind value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

corto_ownership* _corto_ownershipCreate(corto_ownership value) {
    corto_ownership* _this;
    _this = (corto_ownership*)corto_declare(corto_ownership_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_VALID)) {
        *_this = value;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_ownership* _corto_ownershipCreateChild(corto_object _parent, corto_string _id, corto_ownership value) {
    corto_ownership* _this;
    _this = (corto_ownership*)corto_declareChild(_parent, _id, corto_ownership_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_VALID)) {
        *_this = value;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_ownershipUpdate(corto_ownership* _this, corto_ownership value) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            *((corto_ownership*)CORTO_OFFSET(_this, ((corto_type)corto_ownership_o)->size)) = value;
        } else {
            *_this = value;
        }
        corto_update_end(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_ownership* _corto_ownershipDeclare(void) {
    corto_ownership* _this;
    _this = (corto_ownership*)corto_declare(corto_ownership_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_ownership* _corto_ownershipDeclareChild(corto_object _parent, corto_string _id) {
    corto_ownership* _this;
    _this = (corto_ownership*)corto_declareChild(_parent, _id, corto_ownership_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_ownershipDefine(corto_ownership* _this, corto_ownership value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return corto_define(_this);
}

corto_ownership* _corto_ownershipAssign(corto_ownership* _this, corto_ownership value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

corto_package _corto_packageCreate(void) {
    corto_package _this;
    _this = (corto_package)corto_declare(corto_package_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_VALID)) {
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_package _corto_packageCreateChild(corto_object _parent, corto_string _id) {
    corto_package _this;
    _this = (corto_package)corto_declareChild(_parent, _id, corto_package_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_VALID)) {
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
        corto_update_end(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_package _corto_packageDeclare(void) {
    corto_package _this;
    _this = (corto_package)corto_declare(corto_package_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_package _corto_packageDeclareChild(corto_object _parent, corto_string _id) {
    corto_package _this;
    _this = (corto_package)corto_declareChild(_parent, _id, corto_package_o);
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

corto_query* _corto_queryCreate(corto_string select, corto_string from, corto_string type, corto_string member, corto_string where, uint64_t offset, uint64_t limit, corto_frame* timeBegin, corto_frame* timeEnd) {
    corto_query* _this;
    _this = (corto_query*)corto_declare(corto_query_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_VALID)) {
        corto_ptr_setstr(&((corto_query*)_this)->select, select);
        corto_ptr_setstr(&((corto_query*)_this)->from, from);
        corto_ptr_setstr(&((corto_query*)_this)->type, type);
        corto_ptr_setstr(&((corto_query*)_this)->member, member);
        corto_ptr_setstr(&((corto_query*)_this)->where, where);
        ((corto_query*)_this)->offset = offset;
        ((corto_query*)_this)->limit = limit;
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

corto_query* _corto_queryCreateChild(corto_object _parent, corto_string _id, corto_string select, corto_string from, corto_string type, corto_string member, corto_string where, uint64_t offset, uint64_t limit, corto_frame* timeBegin, corto_frame* timeEnd) {
    corto_query* _this;
    _this = (corto_query*)corto_declareChild(_parent, _id, corto_query_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_VALID)) {
        corto_ptr_setstr(&((corto_query*)_this)->select, select);
        corto_ptr_setstr(&((corto_query*)_this)->from, from);
        corto_ptr_setstr(&((corto_query*)_this)->type, type);
        corto_ptr_setstr(&((corto_query*)_this)->member, member);
        corto_ptr_setstr(&((corto_query*)_this)->where, where);
        ((corto_query*)_this)->offset = offset;
        ((corto_query*)_this)->limit = limit;
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

corto_int16 _corto_queryUpdate(corto_query* _this, corto_string select, corto_string from, corto_string type, corto_string member, corto_string where, uint64_t offset, uint64_t limit, corto_frame* timeBegin, corto_frame* timeEnd) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_ptr_setstr(&((corto_query*)((corto_query*)CORTO_OFFSET(_this, ((corto_type)corto_query_o)->size)))->select, select);
            corto_ptr_setstr(&((corto_query*)((corto_query*)CORTO_OFFSET(_this, ((corto_type)corto_query_o)->size)))->from, from);
            corto_ptr_setstr(&((corto_query*)((corto_query*)CORTO_OFFSET(_this, ((corto_type)corto_query_o)->size)))->type, type);
            corto_ptr_setstr(&((corto_query*)((corto_query*)CORTO_OFFSET(_this, ((corto_type)corto_query_o)->size)))->member, member);
            corto_ptr_setstr(&((corto_query*)((corto_query*)CORTO_OFFSET(_this, ((corto_type)corto_query_o)->size)))->where, where);
            ((corto_query*)((corto_query*)CORTO_OFFSET(_this, ((corto_type)corto_query_o)->size)))->offset = offset;
            ((corto_query*)((corto_query*)CORTO_OFFSET(_this, ((corto_type)corto_query_o)->size)))->limit = limit;
            if (timeBegin) {
                corto_ptr_copy(&((corto_query*)((corto_query*)CORTO_OFFSET(_this, ((corto_type)corto_query_o)->size)))->timeBegin, corto_frame_o, timeBegin);
            }
            if (timeEnd) {
                corto_ptr_copy(&((corto_query*)((corto_query*)CORTO_OFFSET(_this, ((corto_type)corto_query_o)->size)))->timeEnd, corto_frame_o, timeEnd);
            }
        } else {
            corto_ptr_setstr(&((corto_query*)_this)->select, select);
            corto_ptr_setstr(&((corto_query*)_this)->from, from);
            corto_ptr_setstr(&((corto_query*)_this)->type, type);
            corto_ptr_setstr(&((corto_query*)_this)->member, member);
            corto_ptr_setstr(&((corto_query*)_this)->where, where);
            ((corto_query*)_this)->offset = offset;
            ((corto_query*)_this)->limit = limit;
            if (timeBegin) {
                corto_ptr_copy(&((corto_query*)_this)->timeBegin, corto_frame_o, timeBegin);
            }
            if (timeEnd) {
                corto_ptr_copy(&((corto_query*)_this)->timeEnd, corto_frame_o, timeEnd);
            }
        }
        corto_update_end(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_query* _corto_queryDeclare(void) {
    corto_query* _this;
    _this = (corto_query*)corto_declare(corto_query_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_query* _corto_queryDeclareChild(corto_object _parent, corto_string _id) {
    corto_query* _this;
    _this = (corto_query*)corto_declareChild(_parent, _id, corto_query_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_queryDefine(corto_query* _this, corto_string select, corto_string from, corto_string type, corto_string member, corto_string where, uint64_t offset, uint64_t limit, corto_frame* timeBegin, corto_frame* timeEnd) {
    CORTO_UNUSED(_this);
    corto_ptr_setstr(&((corto_query*)_this)->select, select);
    corto_ptr_setstr(&((corto_query*)_this)->from, from);
    corto_ptr_setstr(&((corto_query*)_this)->type, type);
    corto_ptr_setstr(&((corto_query*)_this)->member, member);
    corto_ptr_setstr(&((corto_query*)_this)->where, where);
    ((corto_query*)_this)->offset = offset;
    ((corto_query*)_this)->limit = limit;
    if (timeBegin) {
        corto_ptr_copy(&((corto_query*)_this)->timeBegin, corto_frame_o, timeBegin);
    }
    if (timeEnd) {
        corto_ptr_copy(&((corto_query*)_this)->timeEnd, corto_frame_o, timeEnd);
    }
    return corto_define(_this);
}

corto_query* _corto_queryAssign(corto_query* _this, corto_string select, corto_string from, corto_string type, corto_string member, corto_string where, uint64_t offset, uint64_t limit, corto_frame* timeBegin, corto_frame* timeEnd) {
    CORTO_UNUSED(_this);
    corto_ptr_setstr(&((corto_query*)_this)->select, select);
    corto_ptr_setstr(&((corto_query*)_this)->from, from);
    corto_ptr_setstr(&((corto_query*)_this)->type, type);
    corto_ptr_setstr(&((corto_query*)_this)->member, member);
    corto_ptr_setstr(&((corto_query*)_this)->where, where);
    ((corto_query*)_this)->offset = offset;
    ((corto_query*)_this)->limit = limit;
    if (timeBegin) {
        corto_ptr_copy(&((corto_query*)_this)->timeBegin, corto_frame_o, timeBegin);
    }
    if (timeEnd) {
        corto_ptr_copy(&((corto_query*)_this)->timeEnd, corto_frame_o, timeEnd);
    }
    return _this;
}

corto_queuePolicy* _corto_queuePolicyCreate(uint32_t max) {
    corto_queuePolicy* _this;
    _this = (corto_queuePolicy*)corto_declare(corto_queuePolicy_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_VALID)) {
        ((corto_queuePolicy*)_this)->max = max;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_queuePolicy* _corto_queuePolicyCreateChild(corto_object _parent, corto_string _id, uint32_t max) {
    corto_queuePolicy* _this;
    _this = (corto_queuePolicy*)corto_declareChild(_parent, _id, corto_queuePolicy_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_VALID)) {
        ((corto_queuePolicy*)_this)->max = max;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_queuePolicyUpdate(corto_queuePolicy* _this, uint32_t max) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            ((corto_queuePolicy*)((corto_queuePolicy*)CORTO_OFFSET(_this, ((corto_type)corto_queuePolicy_o)->size)))->max = max;
        } else {
            ((corto_queuePolicy*)_this)->max = max;
        }
        corto_update_end(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_queuePolicy* _corto_queuePolicyDeclare(void) {
    corto_queuePolicy* _this;
    _this = (corto_queuePolicy*)corto_declare(corto_queuePolicy_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_queuePolicy* _corto_queuePolicyDeclareChild(corto_object _parent, corto_string _id) {
    corto_queuePolicy* _this;
    _this = (corto_queuePolicy*)corto_declareChild(_parent, _id, corto_queuePolicy_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_queuePolicyDefine(corto_queuePolicy* _this, uint32_t max) {
    CORTO_UNUSED(_this);
    ((corto_queuePolicy*)_this)->max = max;
    return corto_define(_this);
}

corto_queuePolicy* _corto_queuePolicyAssign(corto_queuePolicy* _this, uint32_t max) {
    CORTO_UNUSED(_this);
    ((corto_queuePolicy*)_this)->max = max;
    return _this;
}

corto_remote _corto_remoteCreate(corto_type returnType, bool returnsReference, void(*_impl)(void)) {
    corto_remote _this;
    _this = (corto_remote)corto_declare(corto_remote_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_VALID)) {
        corto_ptr_setref(&((corto_function)_this)->returnType, returnType);
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

corto_remote _corto_remoteCreateChild(corto_object _parent, corto_string _id, corto_type returnType, bool returnsReference, void(*_impl)(void)) {
    corto_remote _this;
    _this = (corto_remote)corto_declareChild(_parent, _id, corto_remote_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_VALID)) {
        corto_ptr_setref(&((corto_function)_this)->returnType, returnType);
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

corto_int16 _corto_remoteUpdate(corto_remote _this, corto_type returnType, bool returnsReference, void(*_impl)(void)) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_ptr_setref(&((corto_function)((corto_remote)CORTO_OFFSET(_this, ((corto_type)corto_remote_o)->size)))->returnType, returnType);
            ((corto_function)((corto_remote)CORTO_OFFSET(_this, ((corto_type)corto_remote_o)->size)))->returnsReference = returnsReference;
            corto_function(((corto_remote)CORTO_OFFSET(_this, ((corto_type)corto_remote_o)->size)))->kind = CORTO_PROCEDURE_CDECL;
            corto_function(((corto_remote)CORTO_OFFSET(_this, ((corto_type)corto_remote_o)->size)))->fptr = (corto_word)_impl;
        } else {
            corto_ptr_setref(&((corto_function)_this)->returnType, returnType);
            ((corto_function)_this)->returnsReference = returnsReference;
            corto_function(_this)->kind = CORTO_PROCEDURE_CDECL;
            corto_function(_this)->fptr = (corto_word)_impl;
        }
        corto_update_end(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_remote _corto_remoteDeclare(void) {
    corto_remote _this;
    _this = (corto_remote)corto_declare(corto_remote_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_remote _corto_remoteDeclareChild(corto_object _parent, corto_string _id) {
    corto_remote _this;
    _this = (corto_remote)corto_declareChild(_parent, _id, corto_remote_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_remoteDefine(corto_remote _this, corto_type returnType, bool returnsReference, void(*_impl)(void)) {
    CORTO_UNUSED(_this);
    corto_ptr_setref(&((corto_function)_this)->returnType, returnType);
    ((corto_function)_this)->returnsReference = returnsReference;
    corto_function(_this)->kind = CORTO_PROCEDURE_CDECL;
    corto_function(_this)->fptr = (corto_word)_impl;
    return corto_define(_this);
}

corto_remote _corto_remoteAssign(corto_remote _this, corto_type returnType, bool returnsReference, void(*_impl)(void)) {
    CORTO_UNUSED(_this);
    corto_ptr_setref(&((corto_function)_this)->returnType, returnType);
    ((corto_function)_this)->returnsReference = returnsReference;
    corto_function(_this)->kind = CORTO_PROCEDURE_CDECL;
    corto_function(_this)->fptr = (corto_word)_impl;
    return _this;
}

corto_result* _corto_resultCreate(corto_string id, corto_string name, corto_string parent, corto_string type, uintptr_t value, corto_resultMask flags) {
    corto_result* _this;
    _this = (corto_result*)corto_declare(corto_result_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_VALID)) {
        corto_ptr_setstr(&((corto_result*)_this)->id, id);
        corto_ptr_setstr(&((corto_result*)_this)->name, name);
        corto_ptr_setstr(&((corto_result*)_this)->parent, parent);
        corto_ptr_setstr(&((corto_result*)_this)->type, type);
        ((corto_result*)_this)->value = value;
        ((corto_result*)_this)->flags = flags;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_result* _corto_resultCreateChild(corto_object _parent, corto_string _id, corto_string id, corto_string name, corto_string parent, corto_string type, uintptr_t value, corto_resultMask flags) {
    corto_result* _this;
    _this = (corto_result*)corto_declareChild(_parent, _id, corto_result_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_VALID)) {
        corto_ptr_setstr(&((corto_result*)_this)->id, id);
        corto_ptr_setstr(&((corto_result*)_this)->name, name);
        corto_ptr_setstr(&((corto_result*)_this)->parent, parent);
        corto_ptr_setstr(&((corto_result*)_this)->type, type);
        ((corto_result*)_this)->value = value;
        ((corto_result*)_this)->flags = flags;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_resultUpdate(corto_result* _this, corto_string id, corto_string name, corto_string parent, corto_string type, uintptr_t value, corto_resultMask flags) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_ptr_setstr(&((corto_result*)((corto_result*)CORTO_OFFSET(_this, ((corto_type)corto_result_o)->size)))->id, id);
            corto_ptr_setstr(&((corto_result*)((corto_result*)CORTO_OFFSET(_this, ((corto_type)corto_result_o)->size)))->name, name);
            corto_ptr_setstr(&((corto_result*)((corto_result*)CORTO_OFFSET(_this, ((corto_type)corto_result_o)->size)))->parent, parent);
            corto_ptr_setstr(&((corto_result*)((corto_result*)CORTO_OFFSET(_this, ((corto_type)corto_result_o)->size)))->type, type);
            ((corto_result*)((corto_result*)CORTO_OFFSET(_this, ((corto_type)corto_result_o)->size)))->value = value;
            ((corto_result*)((corto_result*)CORTO_OFFSET(_this, ((corto_type)corto_result_o)->size)))->flags = flags;
        } else {
            corto_ptr_setstr(&((corto_result*)_this)->id, id);
            corto_ptr_setstr(&((corto_result*)_this)->name, name);
            corto_ptr_setstr(&((corto_result*)_this)->parent, parent);
            corto_ptr_setstr(&((corto_result*)_this)->type, type);
            ((corto_result*)_this)->value = value;
            ((corto_result*)_this)->flags = flags;
        }
        corto_update_end(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_result* _corto_resultDeclare(void) {
    corto_result* _this;
    _this = (corto_result*)corto_declare(corto_result_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_result* _corto_resultDeclareChild(corto_object _parent, corto_string _id) {
    corto_result* _this;
    _this = (corto_result*)corto_declareChild(_parent, _id, corto_result_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_resultDefine(corto_result* _this, corto_string id, corto_string name, corto_string parent, corto_string type, uintptr_t value, corto_resultMask flags) {
    CORTO_UNUSED(_this);
    corto_ptr_setstr(&((corto_result*)_this)->id, id);
    corto_ptr_setstr(&((corto_result*)_this)->name, name);
    corto_ptr_setstr(&((corto_result*)_this)->parent, parent);
    corto_ptr_setstr(&((corto_result*)_this)->type, type);
    ((corto_result*)_this)->value = value;
    ((corto_result*)_this)->flags = flags;
    return corto_define(_this);
}

corto_result* _corto_resultAssign(corto_result* _this, corto_string id, corto_string name, corto_string parent, corto_string type, uintptr_t value, corto_resultMask flags) {
    CORTO_UNUSED(_this);
    corto_ptr_setstr(&((corto_result*)_this)->id, id);
    corto_ptr_setstr(&((corto_result*)_this)->name, name);
    corto_ptr_setstr(&((corto_result*)_this)->parent, parent);
    corto_ptr_setstr(&((corto_result*)_this)->type, type);
    ((corto_result*)_this)->value = value;
    ((corto_result*)_this)->flags = flags;
    return _this;
}

corto_resultIter* _corto_resultIterCreate(void) {
    corto_resultIter* _this;
    _this = (corto_resultIter*)corto_declare(corto_resultIter_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_VALID)) {
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_resultIter* _corto_resultIterCreateChild(corto_object _parent, corto_string _id) {
    corto_resultIter* _this;
    _this = (corto_resultIter*)corto_declareChild(_parent, _id, corto_resultIter_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_VALID)) {
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_resultIterUpdate(corto_resultIter* _this) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
        } else {
        }
        corto_update_end(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_resultIter* _corto_resultIterDeclare(void) {
    corto_resultIter* _this;
    _this = (corto_resultIter*)corto_declare(corto_resultIter_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_resultIter* _corto_resultIterDeclareChild(corto_object _parent, corto_string _id) {
    corto_resultIter* _this;
    _this = (corto_resultIter*)corto_declareChild(_parent, _id, corto_resultIter_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_resultIterDefine(corto_resultIter* _this) {
    CORTO_UNUSED(_this);
    return corto_define(_this);
}

corto_resultIter* _corto_resultIterAssign(corto_resultIter* _this) {
    CORTO_UNUSED(_this);
    return _this;
}

corto_resultList* _corto_resultListCreate(corto_uint32 length, corto_result* elements) {
    corto_resultList* _this;
    _this = (corto_resultList*)corto_declare(corto_resultList_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_VALID)) {
        corto_uint32 i = 0;
        corto_resultListClear(*_this);
        for (i = 0; i < length; i ++) {
            corto_resultListAppend(*_this, &elements[i]);
        }
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_resultList* _corto_resultListCreateChild(corto_object _parent, corto_string _id, corto_uint32 length, corto_result* elements) {
    corto_resultList* _this;
    _this = (corto_resultList*)corto_declareChild(_parent, _id, corto_resultList_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_VALID)) {
        corto_uint32 i = 0;
        corto_resultListClear(*_this);
        for (i = 0; i < length; i ++) {
            corto_resultListAppend(*_this, &elements[i]);
        }
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_resultListUpdate(corto_resultList* _this, corto_uint32 length, corto_result* elements) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_uint32 i = 0;
            corto_resultListClear(*((corto_resultList*)CORTO_OFFSET(_this, ((corto_type)corto_resultList_o)->size)));
            for (i = 0; i < length; i ++) {
                corto_resultListAppend(*((corto_resultList*)CORTO_OFFSET(_this, ((corto_type)corto_resultList_o)->size)), &elements[i]);
            }
        } else {
            corto_uint32 i = 0;
            corto_resultListClear(*_this);
            for (i = 0; i < length; i ++) {
                corto_resultListAppend(*_this, &elements[i]);
            }
        }
        corto_update_end(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_resultList* _corto_resultListDeclare(void) {
    corto_resultList* _this;
    _this = (corto_resultList*)corto_declare(corto_resultList_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_resultList* _corto_resultListDeclareChild(corto_object _parent, corto_string _id) {
    corto_resultList* _this;
    _this = (corto_resultList*)corto_declareChild(_parent, _id, corto_resultList_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_resultListDefine(corto_resultList* _this, corto_uint32 length, corto_result* elements) {
    CORTO_UNUSED(_this);
    corto_uint32 i = 0;
    corto_resultListClear(*_this);
    for (i = 0; i < length; i ++) {
        corto_resultListAppend(*_this, &elements[i]);
    }
    return corto_define(_this);
}

corto_resultList* _corto_resultListAssign(corto_resultList* _this, corto_uint32 length, corto_result* elements) {
    CORTO_UNUSED(_this);
    corto_uint32 i = 0;
    corto_resultListClear(*_this);
    for (i = 0; i < length; i ++) {
        corto_resultListAppend(*_this, &elements[i]);
    }
    return _this;
}

corto_resultMask* _corto_resultMaskCreate(corto_resultMask value) {
    corto_resultMask* _this;
    _this = (corto_resultMask*)corto_declare(corto_resultMask_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_VALID)) {
        *_this = value;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_resultMask* _corto_resultMaskCreateChild(corto_object _parent, corto_string _id, corto_resultMask value) {
    corto_resultMask* _this;
    _this = (corto_resultMask*)corto_declareChild(_parent, _id, corto_resultMask_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_VALID)) {
        *_this = value;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_resultMaskUpdate(corto_resultMask* _this, corto_resultMask value) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            *((corto_resultMask*)CORTO_OFFSET(_this, ((corto_type)corto_resultMask_o)->size)) = value;
        } else {
            *_this = value;
        }
        corto_update_end(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_resultMask* _corto_resultMaskDeclare(void) {
    corto_resultMask* _this;
    _this = (corto_resultMask*)corto_declare(corto_resultMask_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_resultMask* _corto_resultMaskDeclareChild(corto_object _parent, corto_string _id) {
    corto_resultMask* _this;
    _this = (corto_resultMask*)corto_declareChild(_parent, _id, corto_resultMask_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_resultMaskDefine(corto_resultMask* _this, corto_resultMask value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return corto_define(_this);
}

corto_resultMask* _corto_resultMaskAssign(corto_resultMask* _this, corto_resultMask value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

corto_route _corto_routeCreate(corto_string pattern, void(*_impl)(void)) {
    corto_route _this;
    _this = (corto_route)corto_declare(corto_route_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_VALID)) {
        corto_ptr_setstr(&((corto_route)_this)->pattern, pattern);
        corto_function(_this)->kind = CORTO_PROCEDURE_CDECL;
        corto_function(_this)->fptr = (corto_word)_impl;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_route _corto_routeCreateChild(corto_object _parent, corto_string _id, corto_string pattern, void(*_impl)(void)) {
    corto_route _this;
    _this = (corto_route)corto_declareChild(_parent, _id, corto_route_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_VALID)) {
        corto_ptr_setstr(&((corto_route)_this)->pattern, pattern);
        corto_function(_this)->kind = CORTO_PROCEDURE_CDECL;
        corto_function(_this)->fptr = (corto_word)_impl;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_routeUpdate(corto_route _this, corto_string pattern, void(*_impl)(void)) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_ptr_setstr(&((corto_route)((corto_route)CORTO_OFFSET(_this, ((corto_type)corto_route_o)->size)))->pattern, pattern);
            corto_function(((corto_route)CORTO_OFFSET(_this, ((corto_type)corto_route_o)->size)))->kind = CORTO_PROCEDURE_CDECL;
            corto_function(((corto_route)CORTO_OFFSET(_this, ((corto_type)corto_route_o)->size)))->fptr = (corto_word)_impl;
        } else {
            corto_ptr_setstr(&((corto_route)_this)->pattern, pattern);
            corto_function(_this)->kind = CORTO_PROCEDURE_CDECL;
            corto_function(_this)->fptr = (corto_word)_impl;
        }
        corto_update_end(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_route _corto_routeDeclare(void) {
    corto_route _this;
    _this = (corto_route)corto_declare(corto_route_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_route _corto_routeDeclareChild(corto_object _parent, corto_string _id) {
    corto_route _this;
    _this = (corto_route)corto_declareChild(_parent, _id, corto_route_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_routeDefine(corto_route _this, corto_string pattern, void(*_impl)(void)) {
    CORTO_UNUSED(_this);
    corto_ptr_setstr(&((corto_route)_this)->pattern, pattern);
    corto_function(_this)->kind = CORTO_PROCEDURE_CDECL;
    corto_function(_this)->fptr = (corto_word)_impl;
    return corto_define(_this);
}

corto_route _corto_routeAssign(corto_route _this, corto_string pattern, void(*_impl)(void)) {
    CORTO_UNUSED(_this);
    corto_ptr_setstr(&((corto_route)_this)->pattern, pattern);
    corto_function(_this)->kind = CORTO_PROCEDURE_CDECL;
    corto_function(_this)->fptr = (corto_word)_impl;
    return _this;
}

corto_router _corto_routerCreate(corto_type returnType, corto_type paramType, corto_string paramName, corto_type routerDataType, corto_string routerDataName, corto_string elementSeparator) {
    corto_router _this;
    _this = (corto_router)corto_declare(corto_router_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_VALID)) {
        corto_ptr_setref(&((corto_router)_this)->returnType, returnType);
        corto_ptr_setref(&((corto_router)_this)->paramType, paramType);
        corto_ptr_setstr(&((corto_router)_this)->paramName, paramName);
        corto_ptr_setref(&((corto_router)_this)->routerDataType, routerDataType);
        corto_ptr_setstr(&((corto_router)_this)->routerDataName, routerDataName);
        corto_ptr_setstr(&((corto_router)_this)->elementSeparator, elementSeparator);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_router _corto_routerCreateChild(corto_object _parent, corto_string _id, corto_type returnType, corto_type paramType, corto_string paramName, corto_type routerDataType, corto_string routerDataName, corto_string elementSeparator) {
    corto_router _this;
    _this = (corto_router)corto_declareChild(_parent, _id, corto_router_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_VALID)) {
        corto_ptr_setref(&((corto_router)_this)->returnType, returnType);
        corto_ptr_setref(&((corto_router)_this)->paramType, paramType);
        corto_ptr_setstr(&((corto_router)_this)->paramName, paramName);
        corto_ptr_setref(&((corto_router)_this)->routerDataType, routerDataType);
        corto_ptr_setstr(&((corto_router)_this)->routerDataName, routerDataName);
        corto_ptr_setstr(&((corto_router)_this)->elementSeparator, elementSeparator);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_routerUpdate(corto_router _this, corto_type returnType, corto_type paramType, corto_string paramName, corto_type routerDataType, corto_string routerDataName, corto_string elementSeparator) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_ptr_setref(&((corto_router)((corto_router)CORTO_OFFSET(_this, ((corto_type)corto_router_o)->size)))->returnType, returnType);
            corto_ptr_setref(&((corto_router)((corto_router)CORTO_OFFSET(_this, ((corto_type)corto_router_o)->size)))->paramType, paramType);
            corto_ptr_setstr(&((corto_router)((corto_router)CORTO_OFFSET(_this, ((corto_type)corto_router_o)->size)))->paramName, paramName);
            corto_ptr_setref(&((corto_router)((corto_router)CORTO_OFFSET(_this, ((corto_type)corto_router_o)->size)))->routerDataType, routerDataType);
            corto_ptr_setstr(&((corto_router)((corto_router)CORTO_OFFSET(_this, ((corto_type)corto_router_o)->size)))->routerDataName, routerDataName);
            corto_ptr_setstr(&((corto_router)((corto_router)CORTO_OFFSET(_this, ((corto_type)corto_router_o)->size)))->elementSeparator, elementSeparator);
        } else {
            corto_ptr_setref(&((corto_router)_this)->returnType, returnType);
            corto_ptr_setref(&((corto_router)_this)->paramType, paramType);
            corto_ptr_setstr(&((corto_router)_this)->paramName, paramName);
            corto_ptr_setref(&((corto_router)_this)->routerDataType, routerDataType);
            corto_ptr_setstr(&((corto_router)_this)->routerDataName, routerDataName);
            corto_ptr_setstr(&((corto_router)_this)->elementSeparator, elementSeparator);
        }
        corto_update_end(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_router _corto_routerDeclare(void) {
    corto_router _this;
    _this = (corto_router)corto_declare(corto_router_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_router _corto_routerDeclareChild(corto_object _parent, corto_string _id) {
    corto_router _this;
    _this = (corto_router)corto_declareChild(_parent, _id, corto_router_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_routerDefine(corto_router _this, corto_type returnType, corto_type paramType, corto_string paramName, corto_type routerDataType, corto_string routerDataName, corto_string elementSeparator) {
    CORTO_UNUSED(_this);
    corto_ptr_setref(&((corto_router)_this)->returnType, returnType);
    corto_ptr_setref(&((corto_router)_this)->paramType, paramType);
    corto_ptr_setstr(&((corto_router)_this)->paramName, paramName);
    corto_ptr_setref(&((corto_router)_this)->routerDataType, routerDataType);
    corto_ptr_setstr(&((corto_router)_this)->routerDataName, routerDataName);
    corto_ptr_setstr(&((corto_router)_this)->elementSeparator, elementSeparator);
    return corto_define(_this);
}

corto_router _corto_routerAssign(corto_router _this, corto_type returnType, corto_type paramType, corto_string paramName, corto_type routerDataType, corto_string routerDataName, corto_string elementSeparator) {
    CORTO_UNUSED(_this);
    corto_ptr_setref(&((corto_router)_this)->returnType, returnType);
    corto_ptr_setref(&((corto_router)_this)->paramType, paramType);
    corto_ptr_setstr(&((corto_router)_this)->paramName, paramName);
    corto_ptr_setref(&((corto_router)_this)->routerDataType, routerDataType);
    corto_ptr_setstr(&((corto_router)_this)->routerDataName, routerDataName);
    corto_ptr_setstr(&((corto_router)_this)->elementSeparator, elementSeparator);
    return _this;
}

corto_routerimpl _corto_routerimplCreate(corto_interface base, corto_modifier baseAccess, corto_interfaceseq implements) {
    corto_routerimpl _this;
    _this = (corto_routerimpl)corto_declare(corto_routerimpl_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_VALID)) {
        corto_ptr_setref(&((corto_interface)_this)->base, base);
        ((corto_struct)_this)->baseAccess = baseAccess;
        corto_ptr_copy(&((corto_class)_this)->implements, corto_interfaceseq_o, &implements);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_routerimpl _corto_routerimplCreateChild(corto_object _parent, corto_string _id, corto_interface base, corto_modifier baseAccess, corto_interfaceseq implements) {
    corto_routerimpl _this;
    _this = (corto_routerimpl)corto_declareChild(_parent, _id, corto_routerimpl_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_VALID)) {
        corto_ptr_setref(&((corto_interface)_this)->base, base);
        ((corto_struct)_this)->baseAccess = baseAccess;
        corto_ptr_copy(&((corto_class)_this)->implements, corto_interfaceseq_o, &implements);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_routerimplUpdate(corto_routerimpl _this, corto_interface base, corto_modifier baseAccess, corto_interfaceseq implements) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_ptr_setref(&((corto_interface)((corto_routerimpl)CORTO_OFFSET(_this, ((corto_type)corto_routerimpl_o)->size)))->base, base);
            ((corto_struct)((corto_routerimpl)CORTO_OFFSET(_this, ((corto_type)corto_routerimpl_o)->size)))->baseAccess = baseAccess;
            corto_ptr_copy(&((corto_class)((corto_routerimpl)CORTO_OFFSET(_this, ((corto_type)corto_routerimpl_o)->size)))->implements, corto_interfaceseq_o, &implements);
        } else {
            corto_ptr_setref(&((corto_interface)_this)->base, base);
            ((corto_struct)_this)->baseAccess = baseAccess;
            corto_ptr_copy(&((corto_class)_this)->implements, corto_interfaceseq_o, &implements);
        }
        corto_update_end(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_routerimpl _corto_routerimplDeclare(void) {
    corto_routerimpl _this;
    _this = (corto_routerimpl)corto_declare(corto_routerimpl_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_routerimpl _corto_routerimplDeclareChild(corto_object _parent, corto_string _id) {
    corto_routerimpl _this;
    _this = (corto_routerimpl)corto_declareChild(_parent, _id, corto_routerimpl_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_routerimplDefine(corto_routerimpl _this, corto_interface base, corto_modifier baseAccess, corto_interfaceseq implements) {
    CORTO_UNUSED(_this);
    corto_ptr_setref(&((corto_interface)_this)->base, base);
    ((corto_struct)_this)->baseAccess = baseAccess;
    corto_ptr_copy(&((corto_class)_this)->implements, corto_interfaceseq_o, &implements);
    return corto_define(_this);
}

corto_routerimpl _corto_routerimplAssign(corto_routerimpl _this, corto_interface base, corto_modifier baseAccess, corto_interfaceseq implements) {
    CORTO_UNUSED(_this);
    corto_ptr_setref(&((corto_interface)_this)->base, base);
    ((corto_struct)_this)->baseAccess = baseAccess;
    corto_ptr_copy(&((corto_class)_this)->implements, corto_interfaceseq_o, &implements);
    return _this;
}

corto_sample* _corto_sampleCreate(corto_time* timestamp, uintptr_t value) {
    corto_sample* _this;
    _this = (corto_sample*)corto_declare(corto_sample_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_VALID)) {
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

corto_sample* _corto_sampleCreateChild(corto_object _parent, corto_string _id, corto_time* timestamp, uintptr_t value) {
    corto_sample* _this;
    _this = (corto_sample*)corto_declareChild(_parent, _id, corto_sample_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_VALID)) {
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

corto_int16 _corto_sampleUpdate(corto_sample* _this, corto_time* timestamp, uintptr_t value) {
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
        corto_update_end(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_sample* _corto_sampleDeclare(void) {
    corto_sample* _this;
    _this = (corto_sample*)corto_declare(corto_sample_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_sample* _corto_sampleDeclareChild(corto_object _parent, corto_string _id) {
    corto_sample* _this;
    _this = (corto_sample*)corto_declareChild(_parent, _id, corto_sample_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_sampleDefine(corto_sample* _this, corto_time* timestamp, uintptr_t value) {
    CORTO_UNUSED(_this);
    if (timestamp) {
        corto_ptr_copy(&((corto_sample*)_this)->timestamp, corto_time_o, timestamp);
    }
    ((corto_sample*)_this)->value = value;
    return corto_define(_this);
}

corto_sample* _corto_sampleAssign(corto_sample* _this, corto_time* timestamp, uintptr_t value) {
    CORTO_UNUSED(_this);
    if (timestamp) {
        corto_ptr_copy(&((corto_sample*)_this)->timestamp, corto_time_o, timestamp);
    }
    ((corto_sample*)_this)->value = value;
    return _this;
}

corto_sampleIter* _corto_sampleIterCreate(void) {
    corto_sampleIter* _this;
    _this = (corto_sampleIter*)corto_declare(corto_sampleIter_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_VALID)) {
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_sampleIter* _corto_sampleIterCreateChild(corto_object _parent, corto_string _id) {
    corto_sampleIter* _this;
    _this = (corto_sampleIter*)corto_declareChild(_parent, _id, corto_sampleIter_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_VALID)) {
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_sampleIterUpdate(corto_sampleIter* _this) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
        } else {
        }
        corto_update_end(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_sampleIter* _corto_sampleIterDeclare(void) {
    corto_sampleIter* _this;
    _this = (corto_sampleIter*)corto_declare(corto_sampleIter_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_sampleIter* _corto_sampleIterDeclareChild(corto_object _parent, corto_string _id) {
    corto_sampleIter* _this;
    _this = (corto_sampleIter*)corto_declareChild(_parent, _id, corto_sampleIter_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_sampleIterDefine(corto_sampleIter* _this) {
    CORTO_UNUSED(_this);
    return corto_define(_this);
}

corto_sampleIter* _corto_sampleIterAssign(corto_sampleIter* _this) {
    CORTO_UNUSED(_this);
    return _this;
}

corto_subscriber _corto_subscriberCreate(corto_query* query, corto_string contentType, corto_object instance, corto_dispatcher dispatcher, bool enabled, void(*_impl)(void)) {
    corto_subscriber _this;
    _this = (corto_subscriber)corto_declare(corto_subscriber_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_VALID)) {
        if (query) {
            corto_ptr_copy(&((corto_subscriber)_this)->query, corto_query_o, query);
        }
        corto_ptr_setstr(&((corto_subscriber)_this)->contentType, contentType);
        corto_ptr_setref(&((corto_observer)_this)->instance, instance);
        corto_ptr_setref(&((corto_observer)_this)->dispatcher, dispatcher);
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

corto_subscriber _corto_subscriberCreateChild(corto_object _parent, corto_string _id, corto_query* query, corto_string contentType, corto_object instance, corto_dispatcher dispatcher, bool enabled, void(*_impl)(void)) {
    corto_subscriber _this;
    _this = (corto_subscriber)corto_declareChild(_parent, _id, corto_subscriber_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_VALID)) {
        if (query) {
            corto_ptr_copy(&((corto_subscriber)_this)->query, corto_query_o, query);
        }
        corto_ptr_setstr(&((corto_subscriber)_this)->contentType, contentType);
        corto_ptr_setref(&((corto_observer)_this)->instance, instance);
        corto_ptr_setref(&((corto_observer)_this)->dispatcher, dispatcher);
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

corto_int16 _corto_subscriberUpdate(corto_subscriber _this, corto_query* query, corto_string contentType, corto_object instance, corto_dispatcher dispatcher, bool enabled, void(*_impl)(void)) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            if (query) {
                corto_ptr_copy(&((corto_subscriber)((corto_subscriber)CORTO_OFFSET(_this, ((corto_type)corto_subscriber_o)->size)))->query, corto_query_o, query);
            }
            corto_ptr_setstr(&((corto_subscriber)((corto_subscriber)CORTO_OFFSET(_this, ((corto_type)corto_subscriber_o)->size)))->contentType, contentType);
            corto_ptr_setref(&((corto_observer)((corto_subscriber)CORTO_OFFSET(_this, ((corto_type)corto_subscriber_o)->size)))->instance, instance);
            corto_ptr_setref(&((corto_observer)((corto_subscriber)CORTO_OFFSET(_this, ((corto_type)corto_subscriber_o)->size)))->dispatcher, dispatcher);
            ((corto_observer)((corto_subscriber)CORTO_OFFSET(_this, ((corto_type)corto_subscriber_o)->size)))->enabled = enabled;
            corto_function(((corto_subscriber)CORTO_OFFSET(_this, ((corto_type)corto_subscriber_o)->size)))->kind = CORTO_PROCEDURE_CDECL;
            corto_function(((corto_subscriber)CORTO_OFFSET(_this, ((corto_type)corto_subscriber_o)->size)))->fptr = (corto_word)_impl;
        } else {
            if (query) {
                corto_ptr_copy(&((corto_subscriber)_this)->query, corto_query_o, query);
            }
            corto_ptr_setstr(&((corto_subscriber)_this)->contentType, contentType);
            corto_ptr_setref(&((corto_observer)_this)->instance, instance);
            corto_ptr_setref(&((corto_observer)_this)->dispatcher, dispatcher);
            ((corto_observer)_this)->enabled = enabled;
            corto_function(_this)->kind = CORTO_PROCEDURE_CDECL;
            corto_function(_this)->fptr = (corto_word)_impl;
        }
        corto_update_end(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_subscriber _corto_subscriberDeclare(void) {
    corto_subscriber _this;
    _this = (corto_subscriber)corto_declare(corto_subscriber_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_subscriber _corto_subscriberDeclareChild(corto_object _parent, corto_string _id) {
    corto_subscriber _this;
    _this = (corto_subscriber)corto_declareChild(_parent, _id, corto_subscriber_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_subscriberDefine(corto_subscriber _this, corto_query* query, corto_string contentType, corto_object instance, corto_dispatcher dispatcher, bool enabled, void(*_impl)(void)) {
    CORTO_UNUSED(_this);
    if (query) {
        corto_ptr_copy(&((corto_subscriber)_this)->query, corto_query_o, query);
    }
    corto_ptr_setstr(&((corto_subscriber)_this)->contentType, contentType);
    corto_ptr_setref(&((corto_observer)_this)->instance, instance);
    corto_ptr_setref(&((corto_observer)_this)->dispatcher, dispatcher);
    ((corto_observer)_this)->enabled = enabled;
    corto_function(_this)->kind = CORTO_PROCEDURE_CDECL;
    corto_function(_this)->fptr = (corto_word)_impl;
    return corto_define(_this);
}

corto_subscriber _corto_subscriberAssign(corto_subscriber _this, corto_query* query, corto_string contentType, corto_object instance, corto_dispatcher dispatcher, bool enabled, void(*_impl)(void)) {
    CORTO_UNUSED(_this);
    if (query) {
        corto_ptr_copy(&((corto_subscriber)_this)->query, corto_query_o, query);
    }
    corto_ptr_setstr(&((corto_subscriber)_this)->contentType, contentType);
    corto_ptr_setref(&((corto_observer)_this)->instance, instance);
    corto_ptr_setref(&((corto_observer)_this)->dispatcher, dispatcher);
    ((corto_observer)_this)->enabled = enabled;
    corto_function(_this)->kind = CORTO_PROCEDURE_CDECL;
    corto_function(_this)->fptr = (corto_word)_impl;
    return _this;
}

corto_subscriberEvent* _corto_subscriberEventCreate(uint16_t kind, corto_subscriber subscriber, corto_object instance, corto_object source, corto_eventMask event, corto_result* data, uintptr_t contentTypeHandle) {
    corto_subscriberEvent* _this;
    _this = (corto_subscriberEvent*)corto_declare(corto_subscriberEvent_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_VALID)) {
        ((corto_event*)_this)->kind = kind;
        corto_ptr_setref(&((corto_subscriberEvent*)_this)->subscriber, subscriber);
        corto_ptr_setref(&((corto_subscriberEvent*)_this)->instance, instance);
        corto_ptr_setref(&((corto_subscriberEvent*)_this)->source, source);
        ((corto_subscriberEvent*)_this)->event = event;
        if (data) {
            corto_ptr_copy(&((corto_subscriberEvent*)_this)->data, corto_result_o, data);
        }
        ((corto_subscriberEvent*)_this)->contentTypeHandle = contentTypeHandle;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_subscriberEvent* _corto_subscriberEventCreateChild(corto_object _parent, corto_string _id, uint16_t kind, corto_subscriber subscriber, corto_object instance, corto_object source, corto_eventMask event, corto_result* data, uintptr_t contentTypeHandle) {
    corto_subscriberEvent* _this;
    _this = (corto_subscriberEvent*)corto_declareChild(_parent, _id, corto_subscriberEvent_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_VALID)) {
        ((corto_event*)_this)->kind = kind;
        corto_ptr_setref(&((corto_subscriberEvent*)_this)->subscriber, subscriber);
        corto_ptr_setref(&((corto_subscriberEvent*)_this)->instance, instance);
        corto_ptr_setref(&((corto_subscriberEvent*)_this)->source, source);
        ((corto_subscriberEvent*)_this)->event = event;
        if (data) {
            corto_ptr_copy(&((corto_subscriberEvent*)_this)->data, corto_result_o, data);
        }
        ((corto_subscriberEvent*)_this)->contentTypeHandle = contentTypeHandle;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_subscriberEventUpdate(corto_subscriberEvent* _this, uint16_t kind, corto_subscriber subscriber, corto_object instance, corto_object source, corto_eventMask event, corto_result* data, uintptr_t contentTypeHandle) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            ((corto_event*)((corto_subscriberEvent*)CORTO_OFFSET(_this, ((corto_type)corto_subscriberEvent_o)->size)))->kind = kind;
            corto_ptr_setref(&((corto_subscriberEvent*)((corto_subscriberEvent*)CORTO_OFFSET(_this, ((corto_type)corto_subscriberEvent_o)->size)))->subscriber, subscriber);
            corto_ptr_setref(&((corto_subscriberEvent*)((corto_subscriberEvent*)CORTO_OFFSET(_this, ((corto_type)corto_subscriberEvent_o)->size)))->instance, instance);
            corto_ptr_setref(&((corto_subscriberEvent*)((corto_subscriberEvent*)CORTO_OFFSET(_this, ((corto_type)corto_subscriberEvent_o)->size)))->source, source);
            ((corto_subscriberEvent*)((corto_subscriberEvent*)CORTO_OFFSET(_this, ((corto_type)corto_subscriberEvent_o)->size)))->event = event;
            if (data) {
                corto_ptr_copy(&((corto_subscriberEvent*)((corto_subscriberEvent*)CORTO_OFFSET(_this, ((corto_type)corto_subscriberEvent_o)->size)))->data, corto_result_o, data);
            }
            ((corto_subscriberEvent*)((corto_subscriberEvent*)CORTO_OFFSET(_this, ((corto_type)corto_subscriberEvent_o)->size)))->contentTypeHandle = contentTypeHandle;
        } else {
            ((corto_event*)_this)->kind = kind;
            corto_ptr_setref(&((corto_subscriberEvent*)_this)->subscriber, subscriber);
            corto_ptr_setref(&((corto_subscriberEvent*)_this)->instance, instance);
            corto_ptr_setref(&((corto_subscriberEvent*)_this)->source, source);
            ((corto_subscriberEvent*)_this)->event = event;
            if (data) {
                corto_ptr_copy(&((corto_subscriberEvent*)_this)->data, corto_result_o, data);
            }
            ((corto_subscriberEvent*)_this)->contentTypeHandle = contentTypeHandle;
        }
        corto_update_end(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_subscriberEvent* _corto_subscriberEventDeclare(void) {
    corto_subscriberEvent* _this;
    _this = (corto_subscriberEvent*)corto_declare(corto_subscriberEvent_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_subscriberEvent* _corto_subscriberEventDeclareChild(corto_object _parent, corto_string _id) {
    corto_subscriberEvent* _this;
    _this = (corto_subscriberEvent*)corto_declareChild(_parent, _id, corto_subscriberEvent_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_subscriberEventDefine(corto_subscriberEvent* _this, uint16_t kind, corto_subscriber subscriber, corto_object instance, corto_object source, corto_eventMask event, corto_result* data, uintptr_t contentTypeHandle) {
    CORTO_UNUSED(_this);
    ((corto_event*)_this)->kind = kind;
    corto_ptr_setref(&((corto_subscriberEvent*)_this)->subscriber, subscriber);
    corto_ptr_setref(&((corto_subscriberEvent*)_this)->instance, instance);
    corto_ptr_setref(&((corto_subscriberEvent*)_this)->source, source);
    ((corto_subscriberEvent*)_this)->event = event;
    if (data) {
        corto_ptr_copy(&((corto_subscriberEvent*)_this)->data, corto_result_o, data);
    }
    ((corto_subscriberEvent*)_this)->contentTypeHandle = contentTypeHandle;
    return corto_define(_this);
}

corto_subscriberEvent* _corto_subscriberEventAssign(corto_subscriberEvent* _this, uint16_t kind, corto_subscriber subscriber, corto_object instance, corto_object source, corto_eventMask event, corto_result* data, uintptr_t contentTypeHandle) {
    CORTO_UNUSED(_this);
    ((corto_event*)_this)->kind = kind;
    corto_ptr_setref(&((corto_subscriberEvent*)_this)->subscriber, subscriber);
    corto_ptr_setref(&((corto_subscriberEvent*)_this)->instance, instance);
    corto_ptr_setref(&((corto_subscriberEvent*)_this)->source, source);
    ((corto_subscriberEvent*)_this)->event = event;
    if (data) {
        corto_ptr_copy(&((corto_subscriberEvent*)_this)->data, corto_result_o, data);
    }
    ((corto_subscriberEvent*)_this)->contentTypeHandle = contentTypeHandle;
    return _this;
}

corto_subscriberEventIter* _corto_subscriberEventIterCreate(void) {
    corto_subscriberEventIter* _this;
    _this = (corto_subscriberEventIter*)corto_declare(corto_subscriberEventIter_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_VALID)) {
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_subscriberEventIter* _corto_subscriberEventIterCreateChild(corto_object _parent, corto_string _id) {
    corto_subscriberEventIter* _this;
    _this = (corto_subscriberEventIter*)corto_declareChild(_parent, _id, corto_subscriberEventIter_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_VALID)) {
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_subscriberEventIterUpdate(corto_subscriberEventIter* _this) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
        } else {
        }
        corto_update_end(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_subscriberEventIter* _corto_subscriberEventIterDeclare(void) {
    corto_subscriberEventIter* _this;
    _this = (corto_subscriberEventIter*)corto_declare(corto_subscriberEventIter_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_subscriberEventIter* _corto_subscriberEventIterDeclareChild(corto_object _parent, corto_string _id) {
    corto_subscriberEventIter* _this;
    _this = (corto_subscriberEventIter*)corto_declareChild(_parent, _id, corto_subscriberEventIter_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_subscriberEventIterDefine(corto_subscriberEventIter* _this) {
    CORTO_UNUSED(_this);
    return corto_define(_this);
}

corto_subscriberEventIter* _corto_subscriberEventIterAssign(corto_subscriberEventIter* _this) {
    CORTO_UNUSED(_this);
    return _this;
}

corto_time* _corto_timeCreate(int32_t sec, uint32_t nanosec) {
    corto_time* _this;
    _this = (corto_time*)corto_declare(corto_time_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_VALID)) {
        ((corto_time*)_this)->sec = sec;
        ((corto_time*)_this)->nanosec = nanosec;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_time* _corto_timeCreateChild(corto_object _parent, corto_string _id, int32_t sec, uint32_t nanosec) {
    corto_time* _this;
    _this = (corto_time*)corto_declareChild(_parent, _id, corto_time_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_VALID)) {
        ((corto_time*)_this)->sec = sec;
        ((corto_time*)_this)->nanosec = nanosec;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_timeUpdate(corto_time* _this, int32_t sec, uint32_t nanosec) {
    CORTO_UNUSED(_this);
    if (!corto_update_begin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            ((corto_time*)((corto_time*)CORTO_OFFSET(_this, ((corto_type)corto_time_o)->size)))->sec = sec;
            ((corto_time*)((corto_time*)CORTO_OFFSET(_this, ((corto_type)corto_time_o)->size)))->nanosec = nanosec;
        } else {
            ((corto_time*)_this)->sec = sec;
            ((corto_time*)_this)->nanosec = nanosec;
        }
        corto_update_end(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_time* _corto_timeDeclare(void) {
    corto_time* _this;
    _this = (corto_time*)corto_declare(corto_time_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_time* _corto_timeDeclareChild(corto_object _parent, corto_string _id) {
    corto_time* _this;
    _this = (corto_time*)corto_declareChild(_parent, _id, corto_time_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_timeDefine(corto_time* _this, int32_t sec, uint32_t nanosec) {
    CORTO_UNUSED(_this);
    ((corto_time*)_this)->sec = sec;
    ((corto_time*)_this)->nanosec = nanosec;
    return corto_define(_this);
}

corto_time* _corto_timeAssign(corto_time* _this, int32_t sec, uint32_t nanosec) {
    CORTO_UNUSED(_this);
    ((corto_time*)_this)->sec = sec;
    ((corto_time*)_this)->nanosec = nanosec;
    return _this;
}

corto_tool _corto_toolCreate(void) {
    corto_tool _this;
    _this = (corto_tool)corto_declare(corto_tool_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_VALID)) {
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_tool _corto_toolCreateChild(corto_object _parent, corto_string _id) {
    corto_tool _this;
    _this = (corto_tool)corto_declareChild(_parent, _id, corto_tool_o);
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_VALID)) {
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
        corto_update_end(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_tool _corto_toolDeclare(void) {
    corto_tool _this;
    _this = (corto_tool)corto_declare(corto_tool_o);
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_tool _corto_toolDeclareChild(corto_object _parent, corto_string _id) {
    corto_tool _this;
    _this = (corto_tool)corto_declareChild(_parent, _id, corto_tool_o);
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

corto_mountSubscription* corto_mountSubscriptionListInsertAlloc(corto_mountSubscriptionList list) {
    corto_mountSubscription* result;
    result = (corto_mountSubscription*)corto_calloc(corto_type_sizeof(corto_type(corto_mountSubscription_o)));
    {
        corto_value v;
        v = corto_value_value(result, corto_type(corto_mountSubscription_o));
        corto_value_init(&v);
    }
    corto_ll_insert(list, result);
    return result;
}

corto_mountSubscription* corto_mountSubscriptionListInsert(corto_mountSubscriptionList list, corto_mountSubscription* element) {
    corto_mountSubscription *result = corto_mountSubscriptionListInsertAlloc(list);
    corto_ptr_copy(result, corto_mountSubscription_o, element);
    return result;
}

corto_mountSubscription* corto_mountSubscriptionListAppendAlloc(corto_mountSubscriptionList list) {
    corto_mountSubscription* result;
    result = (corto_mountSubscription*)corto_calloc(corto_type_sizeof(corto_type(corto_mountSubscription_o)));
    {
        corto_value v;
        v = corto_value_value(result, corto_type(corto_mountSubscription_o));
        corto_value_init(&v);
    }
    corto_ll_append(list, result);
    return result;
}

corto_mountSubscription* corto_mountSubscriptionListAppend(corto_mountSubscriptionList list, corto_mountSubscription* element) {
    corto_mountSubscription *result = corto_mountSubscriptionListAppendAlloc(list);
    corto_ptr_copy(result, corto_mountSubscription_o, element);
    return result;
}

corto_mountSubscription* corto_mountSubscriptionListTakeFirst(corto_mountSubscriptionList list) {
    return (corto_mountSubscription*)(corto_word)corto_ll_takeFirst(list);
}

corto_mountSubscription* corto_mountSubscriptionListLast(corto_mountSubscriptionList list) {
    return (corto_mountSubscription*)(corto_word)corto_ll_last(list);
}

corto_mountSubscription* corto_mountSubscriptionListGet(corto_mountSubscriptionList list, corto_uint32 index) {
    return (corto_mountSubscription*)corto_ll_get(list, index);
}

corto_uint32 corto_mountSubscriptionListSize(corto_mountSubscriptionList list) {
    return corto_ll_size(list);
}

void corto_mountSubscriptionListClear(corto_mountSubscriptionList list) {
    corto_iter iter = corto_ll_iter(list);
    while(corto_iter_hasNext(&iter)) {
        void *ptr = corto_iter_next(&iter);
        corto_ptr_deinit(ptr, corto_mountSubscription_o);
        corto_dealloc(ptr);
    }
    corto_ll_clear(list);
}

corto_result* corto_resultListInsertAlloc(corto_resultList list) {
    corto_result* result;
    result = (corto_result*)corto_calloc(corto_type_sizeof(corto_type(corto_result_o)));
    {
        corto_value v;
        v = corto_value_value(result, corto_type(corto_result_o));
        corto_value_init(&v);
    }
    corto_ll_insert(list, result);
    return result;
}

corto_result* corto_resultListInsert(corto_resultList list, corto_result* element) {
    corto_result *result = corto_resultListInsertAlloc(list);
    corto_ptr_copy(result, corto_result_o, element);
    return result;
}

corto_result* corto_resultListAppendAlloc(corto_resultList list) {
    corto_result* result;
    result = (corto_result*)corto_calloc(corto_type_sizeof(corto_type(corto_result_o)));
    {
        corto_value v;
        v = corto_value_value(result, corto_type(corto_result_o));
        corto_value_init(&v);
    }
    corto_ll_append(list, result);
    return result;
}

corto_result* corto_resultListAppend(corto_resultList list, corto_result* element) {
    corto_result *result = corto_resultListAppendAlloc(list);
    corto_ptr_copy(result, corto_result_o, element);
    return result;
}

corto_result* corto_resultListTakeFirst(corto_resultList list) {
    return (corto_result*)(corto_word)corto_ll_takeFirst(list);
}

corto_result* corto_resultListLast(corto_resultList list) {
    return (corto_result*)(corto_word)corto_ll_last(list);
}

corto_result* corto_resultListGet(corto_resultList list, corto_uint32 index) {
    return (corto_result*)corto_ll_get(list, index);
}

corto_uint32 corto_resultListSize(corto_resultList list) {
    return corto_ll_size(list);
}

void corto_resultListClear(corto_resultList list) {
    corto_iter iter = corto_ll_iter(list);
    while(corto_iter_hasNext(&iter)) {
        void *ptr = corto_iter_next(&iter);
        corto_ptr_deinit(ptr, corto_result_o);
        corto_dealloc(ptr);
    }
    corto_ll_clear(list);
}

