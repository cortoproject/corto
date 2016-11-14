/* sequence.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef CORTO_LANG_SEQUENCE_H
#define CORTO_LANG_SEQUENCE_H

#include <corto/corto.h>
#include <corto/_project.h>
#include <corto/lang/_type.h>
#include <corto/lang/_api.h>
#include <corto/lang/_load.h>

#ifdef __cplusplus
extern "C" {
#endif


CORTO_EXPORT corto_int16 _corto_sequence_construct(
    corto_sequence _this);
#define corto_sequence_construct(_this) _corto_sequence_construct(corto_sequence(_this))

CORTO_EXPORT corto_int16 _corto_sequence_init(
    corto_sequence _this);
#define corto_sequence_init(_this) _corto_sequence_init(corto_sequence(_this))

CORTO_EXPORT corto_void _corto_sequence_size(corto_any _this,
    corto_uint32 size);
#define corto_sequence_size(_this, size) _corto_sequence_size(_this, size)

#ifdef __cplusplus
}
#endif
#endif

