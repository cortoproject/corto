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

    CX_UNUSED(this);

/* $end */
}

/* ::corto::lang::replicator::invoke(object instance,function proc,octetseq args) */
cx_void _cx_replicator_invoke(cx_replicator this, cx_object instance, cx_function proc, cx_octetseq args) {
/* $begin(::corto::lang::replicator::invoke) */
    cx_object owner = cx_ownerof(instance);

    if (owner == this) {
        if (this->onInvoke._parent.procedure) {
            cx_octetseq argbuff = args;
            argbuff.buffer = cx_alloc(args.length * sizeof(cx_octet));
            memcpy(argbuff.buffer, args.buffer, args.length * sizeof(cx_octet));
            cx_invokeEvent e = cx_invokeEventCreate(this, instance, proc, argbuff);
            cx_dispatcher_post(this, e);
        }
    } else {
        cx_object prevowner = cx_setOwner(cx_ownerof(instance));
        cx_callb(proc, NULL, args.buffer);
        cx_setOwner(prevowner);
    }

/* $end */
}

/* ::corto::lang::replicator::on_declare */
cx_void _cx_replicator_on_declare(cx_replicator this, cx_object observable, cx_object source) {
/* $begin(::corto::lang::replicator::on_declare) */
    
    CX_UNUSED(source);
    if (observable != root_o) {
        cx_notifyActionCall(&this->onDeclare, observable);
    }

/* $end */
}

/* ::corto::lang::replicator::on_delete */
cx_void _cx_replicator_on_delete(cx_replicator this, cx_object observable, cx_object source) {
/* $begin(::corto::lang::replicator::on_delete) */

    CX_UNUSED(source);
    cx_notifyActionCall(&this->onDelete, observable);

/* $end */
}

/* ::corto::lang::replicator::on_update */
cx_void _cx_replicator_on_update(cx_replicator this, cx_object observable, cx_object source) {
/* $begin(::corto::lang::replicator::on_update) */

    CX_UNUSED(source);
    if (cx_checkAttr(observable, CX_ATTR_WRITABLE)) {
        cx_notifyActionCall(&this->onUpdate, observable);
    }
    
/* $end */
}

/* ::corto::lang::replicator::post(event e) */
cx_void _cx_replicator_post(cx_replicator this, cx_event e) {
/* $begin(::corto::lang::replicator::post) */
    
    CX_UNUSED(this);
    cx_event_handle(e);

/* $end */
}
