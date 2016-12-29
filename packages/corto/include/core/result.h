/* result.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef CORTO_CORE_RESULT_H
#define CORTO_CORE_RESULT_H

#include <corto/corto.h>
#include <corto/_project.h>
#include <corto/core/_type.h>

#ifdef __cplusplus
extern "C" {
#endif


CORTO_EXPORT corto_string _corto_result_contentof(
    corto_result* _this,
    corto_string contentType);
#define corto_result_contentof(_this, contentType) _corto_result_contentof(_this, contentType)

CORTO_EXPORT corto_int16 _corto_result_fromcontent(
    corto_result* _this,
    corto_string contentType,
    corto_string content);
#define corto_result_fromcontent(_this, contentType, content) _corto_result_fromcontent(_this, contentType, content)

CORTO_EXPORT corto_string _corto_result_getText(
    corto_result* _this);
#define corto_result_getText(_this) _corto_result_getText(_this)

#ifdef __cplusplus
}
#endif
#endif

