/* corto_replicator.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "cx.h"

/* ::corto::lang::replicator::construct() */
corto_int16 _corto_replicator_construct(corto_replicator this) {
/* $begin(::corto::lang::replicator::construct) */
    corto_object observable = this->query ? this->query->from : this->mount;
    corto_eventMask mask = this->query ? this->query->mask : CORTO_ON_SCOPE;

    corto_listen(this, corto_replicator_on_declare_o, CORTO_ON_DECLARE | mask, observable, this);
    corto_listen(this, corto_replicator_on_update_o, CORTO_ON_DEFINE | CORTO_ON_UPDATE | mask, observable, this);
    corto_listen(this, corto_replicator_on_delete_o, CORTO_ON_DELETE | mask, observable, this);
    
    return 0;
/* $end */
}

/* ::corto::lang::replicator::destruct() */
corto_void _corto_replicator_destruct(corto_replicator this) {
/* $begin(::corto::lang::replicator::destruct) */

    CORTO_UNUSED(this);

/* $end */
}

/* ::corto::lang::replicator::invoke(object instance,function proc,octetseq args) */
corto_void _corto_replicator_invoke(corto_replicator this, corto_object instance, corto_function proc, corto_octetseq args) {
/* $begin(::corto::lang::replicator::invoke) */
    corto_object owner = corto_ownerof(instance);

    if (owner == this) {
        if (this->onInvoke._parent.procedure) {
            corto_octetseq argbuff = args;
            argbuff.buffer = corto_alloc(args.length * sizeof(corto_octet));
            memcpy(argbuff.buffer, args.buffer, args.length * sizeof(corto_octet));
            corto_invokeEvent e = corto_invokeEventCreate(this, instance, proc, argbuff);
            corto_dispatcher_post(this, e);
        }
    } else {
        corto_object prevowner = corto_setOwner(corto_ownerof(instance));
        corto_callb(proc, NULL, args.buffer);
        corto_setOwner(prevowner);
    }

/* $end */
}

/* ::corto::lang::replicator::on_declare */
corto_void _corto_replicator_on_declare(corto_replicator this, corto_object observable) {
/* $begin(::corto::lang::replicator::on_declare) */
    
    if (observable != root_o) {
        corto_notifyActionCall(&this->onDeclare, observable);
    }

/* $end */
}

/* ::corto::lang::replicator::on_delete */
corto_void _corto_replicator_on_delete(corto_replicator this, corto_object observable) {
/* $begin(::corto::lang::replicator::on_delete) */

    corto_notifyActionCall(&this->onDelete, observable);

/* $end */
}

/* ::corto::lang::replicator::on_update */
corto_void _corto_replicator_on_update(corto_replicator this, corto_object observable) {
/* $begin(::corto::lang::replicator::on_update) */

    if (corto_checkAttr(observable, CORTO_ATTR_WRITABLE)) {
        corto_notifyActionCall(&this->onUpdate, observable);
    }
    
/* $end */
}

/* ::corto::lang::replicator::post(event e) */
corto_void _corto_replicator_post(corto_replicator this, corto_event e) {
/* $begin(::corto::lang::replicator::post) */
    
    CORTO_UNUSED(this);
    corto_event_handle(e);

/* $end */
}
