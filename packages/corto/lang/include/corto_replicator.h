/* corto_replicator.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef CORTO_LANG_REPLICATOR_H
#define CORTO_LANG_REPLICATOR_H

#include "corto.h"
#include "corto__interface.h"

#ifdef __cplusplus
extern "C" {
#endif

CORTO_LANG_EXPORT corto_int16 _corto_replicator_construct(corto_replicator _this);
#define corto_replicator_construct(_this) _corto_replicator_construct(corto_replicator(_this))

CORTO_LANG_EXPORT corto_void _corto_replicator_destruct(corto_replicator _this);
#define corto_replicator_destruct(_this) _corto_replicator_destruct(corto_replicator(_this))

CORTO_LANG_EXPORT corto_void _corto_replicator_invoke(corto_replicator _this, corto_object instance, corto_function proc, corto_octetseq args);
#define corto_replicator_invoke(_this, instance, proc, args) _corto_replicator_invoke(corto_replicator(_this), instance, corto_function(proc), args)

CORTO_LANG_EXPORT corto_void _corto_replicator_on_declare(corto_replicator _this, corto_object observable);
#define corto_replicator_on_declare(_this, observable) _corto_replicator_on_declare(corto_replicator(_this), observable)

CORTO_LANG_EXPORT corto_void _corto_replicator_on_delete(corto_replicator _this, corto_object observable);
#define corto_replicator_on_delete(_this, observable) _corto_replicator_on_delete(corto_replicator(_this), observable)

CORTO_LANG_EXPORT corto_void _corto_replicator_on_update(corto_replicator _this, corto_object observable);
#define corto_replicator_on_update(_this, observable) _corto_replicator_on_update(corto_replicator(_this), observable)

CORTO_LANG_EXPORT corto_void _corto_replicator_post(corto_replicator _this, corto_event e);
#define corto_replicator_post(_this, e) _corto_replicator_post(corto_replicator(_this), corto_event(e))

CORTO_LANG_EXPORT corto_resultIter _corto_replicator_request(corto_replicator _this, corto_object parent, corto_string expr);
#define corto_replicator_request(_this, parent, expr) _corto_replicator_request(corto_replicator(_this), parent, expr)

#ifdef __cplusplus
}
#endif
#endif

