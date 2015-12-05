/* $CORTO_GENERATED
 *
 * corto_replicator.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include "corto.h"

/* $header() */
#include "corto__object.h"
extern corto_int8 CORTO_OLS_REPLICATOR;

/* Add replicator entry to object OLS */
corto_int16 corto_replicator_attach(
    corto_replicator this,
    corto_object o,
    corto_eventMask mask)
{
    corto_ll replicators = corto_olsLockGet(o, CORTO_OLS_REPLICATOR);
    corto_replicator_olsData_t *data;

    if (!replicators) {
        replicators = corto_llNew();
    }

    if (corto_llSize(replicators) >= CORTO_MAX_REPLICATORS) {
        corto_seterr("maximum number of replicatos for scope set");
        corto_olsUnlockSet(o, CORTO_OLS_REPLICATOR, replicators);
        goto error;
    }

    data = corto_alloc(sizeof(corto_replicator_olsData_t));
    data->replicator = this;
    data->mask = mask;
    corto_llAppend(replicators, data);

    corto_olsUnlockSet(o, CORTO_OLS_REPLICATOR, replicators);

    return 0;
error:
    return -1;
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
        if (corto_replicator_attach(this, observable, mask)) {
            goto error;
        }
    }

    corto_listen(this, corto_replicator_on_declare_o, CORTO_ON_DECLARE | mask, observable, this);
    corto_listen(this, corto_replicator_on_update_o, CORTO_ON_DEFINE | CORTO_ON_UPDATE | mask, observable, this);
    corto_listen(this, corto_replicator_on_delete_o, CORTO_ON_DELETE | mask, observable, this);

    return 0;
error:
    return -1;
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
        corto_replicator_onInvoke(this, instance, proc, args);
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
        corto_replicator_onDeclare(this, observable);
    }

/* $end */
}

corto_void _corto_replicator_on_delete(corto_replicator this, corto_object observable) {
/* $begin(corto/lang/replicator/on_delete) */

    corto_replicator_onDelete(this, observable);

/* $end */
}

corto_void _corto_replicator_on_update(corto_replicator this, corto_object observable) {
/* $begin(corto/lang/replicator/on_update) */

    if (corto_checkAttr(observable, CORTO_ATTR_WRITABLE)) {
        corto_replicator_onUpdate(this, observable);
    }

/* $end */
}

corto_void _corto_replicator_onDeclare_v(corto_replicator this, corto_object observable) {
/* $begin(corto/lang/replicator/onDeclare) */

    CORTO_UNUSED(this);
    CORTO_UNUSED(observable);

/* $end */
}

corto_void _corto_replicator_onDelete_v(corto_replicator this, corto_object observable) {
/* $begin(corto/lang/replicator/onDelete) */

    CORTO_UNUSED(this);
    CORTO_UNUSED(observable);

/* $end */
}

corto_void _corto_replicator_onInvoke_v(corto_replicator this, corto_object instance, corto_function proc, corto_octetseq args) {
/* $begin(corto/lang/replicator/onInvoke) */

    CORTO_UNUSED(this);
    CORTO_UNUSED(instance);
    CORTO_UNUSED(proc);
    CORTO_UNUSED(args);

/* $end */
}

corto_resultIter _corto_replicator_onRequest_v(corto_replicator this, corto_string parent, corto_string expr, corto_bool setContent) {
/* $begin(corto/lang/replicator/onRequest) */
    corto_resultIter result;

    CORTO_UNUSED(this);
    CORTO_UNUSED(parent);
    CORTO_UNUSED(expr);
    CORTO_UNUSED(setContent);

    memset(&result, 0, sizeof(corto_iter));
    return result;
/* $end */
}

corto_void _corto_replicator_onUpdate_v(corto_replicator this, corto_object observable) {
/* $begin(corto/lang/replicator/onUpdate) */

    CORTO_UNUSED(this);
    CORTO_UNUSED(observable);

/* $end */
}

corto_void _corto_replicator_post(corto_replicator this, corto_event e) {
/* $begin(corto/lang/replicator/post) */

    CORTO_UNUSED(this);
    corto_event_handle(e);

/* $end */
}

corto_resultIter _corto_replicator_request(corto_replicator this, corto_string parent, corto_string expr, corto_bool setContent) {
/* $begin(corto/lang/replicator/request) */
    return corto_replicator_onRequest(this, parent, expr, setContent);
/* $end */
}

corto_int16 _corto_replicator_setContentType(corto_replicator this, corto_string type) {
/* $begin(corto/lang/replicator/setContentType) */
    corto_setstr(&this->contentType, type);
    return 0;
/* $end */
}
