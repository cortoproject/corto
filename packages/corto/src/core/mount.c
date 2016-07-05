/* $CORTO_GENERATED
 *
 * mount.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <corto/core/core.h>

/* $header() */
#include "_object.h"
extern corto_int8 CORTO_OLS_REPLICATOR;

/* Add mount entry to object OLS */
corto_int16 corto_mount_attach(
    corto_mount this,
    corto_object o,
    corto_eventMask mask)
{
    corto_ll mounts = corto_olsLockGet(o, CORTO_OLS_REPLICATOR);
    corto_mount_olsData_t *data;

    if (!mounts) {
        mounts = corto_llNew();
    }

    if (corto_llSize(mounts) >= CORTO_MAX_REPLICATORS) {
        corto_seterr("maximum number of replicatos for scope set");
        corto_olsUnlockSet(o, CORTO_OLS_REPLICATOR, mounts);
        goto error;
    }

    data = corto_alloc(sizeof(corto_mount_olsData_t));
    data->mount = this;
    data->mask = mask;
    corto_llAppend(mounts, data);

    corto_olsUnlockSet(o, CORTO_OLS_REPLICATOR, mounts);

    return 0;
error:
    return -1;
}
/* $end */

corto_int16 _corto_mount_construct(
    corto_mount this)
{
/* $begin(corto/core/mount/construct) */

    /* If mount isn't set, and object is scoped, mount data on itself */
    if (!this->mount && corto_checkAttr(this, CORTO_ATTR_SCOPED)) {
        corto_setref(&this->mount, this);
    }

    corto_object observable = this->mount;
    corto_eventMask mask = this->mask;

    if (observable && mask) {
        /* Attach mount to the observable if mask != ON_SELF */
        if (mask != CORTO_ON_SELF) {
            if (corto_mount_attach(this, observable, mask)) {
                goto error;
            }
        }

        if (corto_listen(this, corto_mount_on_declare_o, CORTO_ON_DECLARE | mask, observable, this)) {
            goto error;
        }
        if (corto_listen(this, corto_mount_on_update_o, CORTO_ON_DEFINE | CORTO_ON_UPDATE | mask, observable, this)) {
            goto error;
        }
        if (corto_listen(this, corto_mount_on_delete_o, CORTO_ON_DELETE | mask, observable, this)) {
            goto error;
        }
    }

    return 0;
error:
    return -1;
/* $end */
}

corto_void _corto_mount_destruct(
    corto_mount this)
{
/* $begin(corto/core/mount/destruct) */

    CORTO_UNUSED(this);

/* $end */
}

corto_int16 _corto_mount_init(
    corto_mount this)
{
/* $begin(corto/core/mount/init) */

    this->kind = CORTO_SOURCE;
    this->mask = CORTO_ON_SCOPE;

    return 0;
/* $end */
}

corto_void _corto_mount_invoke(
    corto_mount this,
    corto_object instance,
    corto_function proc,
    corto_word argptrs)
{
/* $begin(corto/core/mount/invoke) */
    corto_object owner = corto_ownerof(instance);

    if (owner == this) {
        corto_mount_onInvoke(this, instance, proc, argptrs);
    } else {
        corto_object prevowner = corto_setOwner(corto_ownerof(instance));
        corto_callb(proc, NULL, (void**)argptrs);
        corto_setOwner(prevowner);
    }

/* $end */
}

corto_void _corto_mount_on_declare(
    corto_mount this,
    corto_object observable)
{
/* $begin(corto/core/mount/on_declare) */

    if (observable != root_o) {
        if (this->type) {
            corto_id srcType; corto_fullpath(srcType, corto_typeof(observable));
            if (!strcmp(this->type, srcType)) {
                this->sent.declares ++;
                corto_mount_onDeclare(this, observable);
            }
        } else {
            this->sent.declares ++;
            corto_mount_onDeclare(this, observable);
        }
    }

/* $end */
}

corto_void _corto_mount_on_delete(
    corto_mount this,
    corto_object observable)
{
/* $begin(corto/core/mount/on_delete) */

    if (this->type) {
        corto_id srcType; corto_fullpath(srcType, corto_typeof(observable));
        if (!strcmp(this->type, srcType)) {
            this->sent.deletes ++;
            corto_mount_onDelete(this, observable);
        }
    } else {
        this->sent.deletes ++;
        corto_mount_onDelete(this, observable);
    }

/* $end */
}

corto_void _corto_mount_on_update(
    corto_mount this,
    corto_object observable)
{
/* $begin(corto/core/mount/on_update) */

    if (corto_checkAttr(observable, CORTO_ATTR_WRITABLE)) {
        if (this->type) {
            corto_id srcType; corto_fullpath(srcType, corto_typeof(observable));
            if (!strcmp(this->type, srcType)) {
                this->sent.updates ++;
                corto_mount_onUpdate(this, observable);
            }
        } else {
            this->sent.updates ++;
            corto_mount_onUpdate(this, observable);
        }
    }

/* $end */
}

corto_void _corto_mount_onDeclare_v(
    corto_mount this,
    corto_object observable)
{
/* $begin(corto/core/mount/onDeclare) */
    CORTO_UNUSED(observable);

    /* If mount doesn't implement onDeclare, nothing has been sent */
    this->sent.declares --;

/* $end */
}

corto_void _corto_mount_onDelete_v(
    corto_mount this,
    corto_object observable)
{
/* $begin(corto/core/mount/onDelete) */
    CORTO_UNUSED(observable);

    /* If mount doesn't implement onDelete, nothing has been sent */
    this->sent.deletes --;

/* $end */
}

corto_void _corto_mount_onInvoke_v(
    corto_mount this,
    corto_object instance,
    corto_function proc,
    corto_word argptrs)
{
/* $begin(corto/core/mount/onInvoke) */

    CORTO_UNUSED(this);
    CORTO_UNUSED(instance);
    CORTO_UNUSED(proc);
    CORTO_UNUSED(argptrs);

/* $end */
}

corto_resultIter _corto_mount_onRequest_v(
    corto_mount this,
    corto_request *request)
{
/* $begin(corto/core/mount/onRequest) */
    corto_resultIter result;

    CORTO_UNUSED(this);
    CORTO_UNUSED(request);

    memset(&result, 0, sizeof(corto_iter));
    return result;
/* $end */
}

corto_object _corto_mount_onResume_v(
    corto_mount this,
    corto_string parent,
    corto_string name,
    corto_object o)
{
/* $begin(corto/core/mount/onResume) */
    CORTO_UNUSED(this);
    CORTO_UNUSED(parent);
    CORTO_UNUSED(name);
    CORTO_UNUSED(o);

    return NULL;
/* $end */
}

corto_void _corto_mount_onUpdate_v(
    corto_mount this,
    corto_object observable)
{
/* $begin(corto/core/mount/onUpdate) */
    CORTO_UNUSED(observable);

    /* If mount doesn't implement onUpdate, nothing has been sent */
    this->sent.updates --;

/* $end */
}

corto_void _corto_mount_post(
    corto_mount this,
    corto_event e)
{
/* $begin(corto/core/mount/post) */

    CORTO_UNUSED(this);
    corto_event_handle(e);
    corto_release(e);

/* $end */
}

corto_resultIter _corto_mount_request(
    corto_mount this,
    corto_request *request)
{
/* $begin(corto/core/mount/request) */
    return corto_mount_onRequest(this, request);
/* $end */
}

corto_object _corto_mount_resume(
    corto_mount this,
    corto_string parent,
    corto_string name,
    corto_object o)
{
/* $begin(corto/core/mount/resume) */
    /* Ensure that if object is created, owner & attributes are set correctly */
    corto_attr prevAttr = corto_setAttr(CORTO_ATTR_PERSISTENT | corto_getAttr());
    corto_object prevOwner = corto_setOwner(this);

    /* Resume object */
    corto_object result = corto_mount_onResume(this, parent, name, o);

    /* Restore owner & attributes */
    corto_setAttr(prevAttr);
    corto_setOwner(prevOwner);

    return result;
/* $end */
}

corto_int16 _corto_mount_setContentType(
    corto_mount this,
    corto_string type)
{
/* $begin(corto/core/mount/setContentType) */
    corto_setstr(&this->contentType, type);
    return 0;
/* $end */
}
