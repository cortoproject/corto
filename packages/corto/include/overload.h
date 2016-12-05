/*
 * corto.h
 *
 *  Created on: Aug 21, 2012
 *      Author: sander
 */

#ifndef CORTO_OVERLOAD_H_
#define CORTO_OVERLOAD_H_

#include "corto/object.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Parameter kinds */
#define CORTO_PARAMETER_REFERENCE          (1)
#define CORTO_PARAMETER_FORCEREFERENCE     (2)
#define CORTO_PARAMETER_WILDCARD           (4)
#define CORTO_PARAMETER_NULL               (8)

/* Calculate the distance between a function and a request signature */
corto_int16 corto_overload(corto_object object, corto_string name, corto_int32* distance);

/* Obtain information from signature.
 *   Signatures can be of the following form:
 *     name(type name,type name)
 *     name(type,type)
 *     name --> Only allowed for non-overloaded functions
 *
 *   No extra whitespaces are allowed.
 */
corto_int32 corto_signatureName(corto_string signature, corto_id buffer);
corto_int32 corto_signatureParamCount(corto_string signature);
corto_int32 corto_signatureParamName(corto_string signature, corto_uint32 id, corto_id buffer);
corto_int32 corto_signatureParamType(corto_string signature, corto_uint32 id, corto_id buffer, int* reference);

/* Create request signature */
corto_string corto_signatureOpen(corto_string name);
corto_string corto_signatureAdd(corto_string sig, corto_type type, int flags);
corto_string corto_signatureAddWildcard(corto_string sig, corto_bool isReference);
corto_string corto_signatureClose(corto_string sig);

/* Obtain signature from object */
char* corto_signature(corto_object o, corto_id buffer);

/* Find a function that matches a signature */
corto_object corto_lookupFunction(corto_object scope, corto_string requested, corto_int32 *d, corto_int32 *diff);
corto_object *corto_lookupFunctionFromSequence(corto_objectseq scopeContents, corto_string requested, corto_int32* d, corto_int32 *diff);

#ifdef __cplusplus
}
#endif

#endif
