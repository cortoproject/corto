/*
 * corto.h
 *
 *  Created on: Aug 21, 2012
 *      Author: sander
 */

#ifndef CX_OVERLOAD_H_
#define CX_OVERLOAD_H_

#include "cx_object.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Parameter kinds */
#define CX_PARAMETER_REFERENCE          (1)
#define CX_PARAMETER_FORCEREFERENCE     (2)
#define CX_PARAMETER_WILDCARD           (4)
#define CX_PARAMETER_NULL               (8)

/* Calculate the distance between a function and a request signature */
cx_int16 cx_overload(cx_object object, cx_string name, cx_int32* distance);

/* Obtain information from signature.
 *   Signatures can be of the following form:
 *     name(type name,type name)
 *     name(type,type)
 *     name --> Only allowed for non-overloaded functions
 *
 *   No extra whitespaces are allowed.
 */
cx_int32 cx_signatureName(cx_string signature, cx_id buffer);
cx_int32 cx_signatureParamCount(cx_string signature);
cx_int32 cx_signatureParamName(cx_string signature, cx_uint32 id, cx_id buffer);
cx_int32 cx_signatureParamType(cx_string signature, cx_uint32 id, cx_id buffer, int* reference);

/* Create request signature */
cx_string cx_signatureOpen(cx_string name);
cx_string cx_signatureAdd(cx_string sig, cx_type type, int flags);
cx_string cx_signatureAddWildcard(cx_string sig, cx_bool isReference);
cx_string cx_signatureClose(cx_string sig);

/* Obtain signature from object */
cx_int16 cx_signature(cx_object o, cx_id buffer);

/* Find a function that matches a signature */
cx_object cx_lookupFunction(cx_object scope, cx_string requested, cx_int32 *d);
cx_object *cx_lookupFunctionFromSequence(cx_objectseq scopeContents, cx_string requested, cx_int32* d);

#ifdef __cplusplus
}
#endif

#endif
