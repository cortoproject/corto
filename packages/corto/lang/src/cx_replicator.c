/* cx_replicator.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "cx.h"

/* ::corto::lang::replicator::construct() */
cx_int16 _cx_replicator_construct(cx_replicator this) {
/* $begin(::corto::lang::replicator::construct) */
    cx_object observable = this->query ? this->query->from : this->mount;
    cx_eventMask mask = this->query ? this->query->mask : CX_ON_SCOPE;

    cx_listen(this, cx_replicator_on_declare_o, CX_ON_DECLARE | mask, observable, this);
    cx_listen(this, cx_replicator_on_update_o, CX_ON_DEFINE | CX_ON_UPDATE | mask, observable, this);
    cx_listen(this, cx_replicator_on_delete_o, CX_ON_DELETE | mask, observable, this);
    
    return 0;
/* $end */
}

/* ::corto::lang::replicator::destruct() */
cx_void _cx_replicator_destruct(cx_replicator this) {
/* $begin(::corto::lang::replicator::destruct) */

    /* << Insert implementation >> */

/* $end */
}

/* ::corto::lang::replicator::on_declare */
cx_void _cx_replicator_on_declare(cx_replicator this, cx_object observable, cx_object source) {
/* $begin(::corto::lang::replicator::on_declare) */
    cx_object owner = cx_ownerof(observable);

    if (this->onDeclare._parent.procedure) {
        if (!owner || !cx_instanceof(cx_type(cx_replicator_o), owner)) {
            cx_call(this->onDeclare._parent.procedure, this->onDeclare._parent.instance, observable, source);
        }
    }

/* $end */
}

/* ::corto::lang::replicator::on_delete */
cx_void _cx_replicator_on_delete(cx_replicator this, cx_object observable, cx_object source) {
/* $begin(::corto::lang::replicator::on_delete) */
    cx_object owner = cx_ownerof(observable);

    if (this->onDelete._parent.procedure) {
        if (!owner || !cx_instanceof(cx_type(cx_replicator_o), owner)) {
            cx_call(this->onDelete._parent.procedure, this->onDelete._parent.instance, observable, source);
        }
    }

/* $end */
}

/* ::corto::lang::replicator::on_update */
cx_void _cx_replicator_on_update(cx_replicator this, cx_object observable, cx_object source) {
/* $begin(::corto::lang::replicator::on_update) */
    cx_object owner = cx_ownerof(observable);

    if (this->onUpdate._parent.procedure) {
        if (!owner || !cx_instanceof(cx_type(cx_replicator_o), owner)) {
            cx_call(this->onUpdate._parent.procedure, this->onUpdate._parent.instance, observable, source);
        }
    }

/* $end */
}

/* ::corto::lang::replicator::post(event e) */
cx_void _cx_replicator_post(cx_replicator this, cx_event e) {
/* $begin(::corto::lang::replicator::post) */

    cx_event_handle(e);

/* $end */
}
