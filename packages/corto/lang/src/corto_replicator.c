/* $CORTO_GENERATED
 *
 * corto_replicator.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include "corto.h"

/* $header() */
extern corto_int8 CORTO_OLS_REPLICATOR;

typedef struct corto_replicator_olsData_t {
    corto_replicator replicator;
    corto_eventMask mask;
} corto_replicator_olsData_t;

/* Add replicator entry to object OLS */
corto_void corto_replicator_attach(
    corto_replicator this,
    corto_object o,
    corto_eventMask mask)
{
    corto_ll replicators = corto_olsLockGet(o, CORTO_OLS_REPLICATOR);
    corto_replicator_olsData_t *data;

    if (!replicators) {
        replicators = corto_llNew();
    }

    data = corto_alloc(sizeof(corto_replicator_olsData_t));
    data->replicator = this;
    data->mask = mask;
    corto_llAppend(replicators, data);

    corto_olsUnlockSet(o, CORTO_OLS_REPLICATOR, replicators);
}
/* $end */

corto_int16 _corto_replicator_construct(corto_replicator this) {
/* $begin(corto/lang/replicator/construct) */
    corto_object observable = this->query ? this->query->from : this->mount;
    corto_eventMask mask = this->query ? this->query->mask : CORTO_ON_SCOPE;

    if (!observable) {
        observable = root_o;
    }

    /* Attach replicator to the observable if mask != ON_SELF */
    if (mask != CORTO_ON_SELF) {
        corto_replicator_attach(this, observable, mask);
    }

    corto_listen(this, corto_replicator_on_declare_o, CORTO_ON_DECLARE | mask, observable, this);
    corto_listen(this, corto_replicator_on_update_o, CORTO_ON_DEFINE | CORTO_ON_UPDATE | mask, observable, this);
    corto_listen(this, corto_replicator_on_delete_o, CORTO_ON_DELETE | mask, observable, this);

    return 0;
/* $end */
}

corto_void _corto_replicator_destruct(corto_replicator this) {
/* $begin(corto/lang/replicator/destruct) */

    CORTO_UNUSED(this);

/* $end */
}

corto_void _corto_replicator_invoke(corto_replicator this, corto_object instance, corto_function proc, corto_octetseq args) {
/* $begin(corto/lang/replicator/invoke) */
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

corto_void _corto_replicator_on_declare(corto_replicator this, corto_object observable) {
/* $begin(corto/lang/replicator/on_declare) */

    if (observable != root_o) {
        corto_notifyActionCall(&this->onDeclare, observable);
    }

/* $end */
}

corto_void _corto_replicator_on_delete(corto_replicator this, corto_object observable) {
/* $begin(corto/lang/replicator/on_delete) */

    corto_notifyActionCall(&this->onDelete, observable);

/* $end */
}

corto_void _corto_replicator_on_update(corto_replicator this, corto_object observable) {
/* $begin(corto/lang/replicator/on_update) */

    if (corto_checkAttr(observable, CORTO_ATTR_WRITABLE)) {
        corto_notifyActionCall(&this->onUpdate, observable);
    }

/* $end */
}

corto_void _corto_replicator_post(corto_replicator this, corto_event e) {
/* $begin(corto/lang/replicator/post) */

    CORTO_UNUSED(this);
    corto_event_handle(e);

/* $end */
}
