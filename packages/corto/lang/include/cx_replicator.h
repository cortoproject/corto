/* cx_replicator.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef CORTO_LANG_REPLICATOR_H
#define CORTO_LANG_REPLICATOR_H

#include "corto.h"
#include "cx__interface.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::corto::lang::replicator::construct() */
CORTO_LANG_EXPORT cx_int16 _cx_replicator_construct(cx_replicator _this);
#define cx_replicator_construct(_this) _cx_replicator_construct(cx_replicator(_this))

/* ::corto::lang::replicator::destruct() */
CORTO_LANG_EXPORT cx_void _cx_replicator_destruct(cx_replicator _this);
#define cx_replicator_destruct(_this) _cx_replicator_destruct(cx_replicator(_this))

/* ::corto::lang::replicator::on_declare */
CORTO_LANG_EXPORT cx_void _cx_replicator_on_declare(cx_replicator _this, cx_object observable, cx_object source);
#define cx_replicator_on_declare(_this, observable, source) _cx_replicator_on_declare(cx_replicator(_this), observable, source)

/* ::corto::lang::replicator::on_delete */
CORTO_LANG_EXPORT cx_void _cx_replicator_on_delete(cx_replicator _this, cx_object observable, cx_object source);
#define cx_replicator_on_delete(_this, observable, source) _cx_replicator_on_delete(cx_replicator(_this), observable, source)

/* ::corto::lang::replicator::on_update */
CORTO_LANG_EXPORT cx_void _cx_replicator_on_update(cx_replicator _this, cx_object observable, cx_object source);
#define cx_replicator_on_update(_this, observable, source) _cx_replicator_on_update(cx_replicator(_this), observable, source)

/* ::corto::lang::replicator::post(event e) */
CORTO_LANG_EXPORT cx_void _cx_replicator_post(cx_replicator _this, cx_event e);
#define cx_replicator_post(_this, e) _cx_replicator_post(cx_replicator(_this), cx_event(e))

#ifdef __cplusplus
}
#endif
#endif

