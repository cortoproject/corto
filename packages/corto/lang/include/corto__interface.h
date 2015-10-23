/* corto__interface.h
 *
 * This file contains generated code. Do not modify!
 */

#ifdef BUILDING_CORTO_LANG
#include "corto__type.h"
#include "corto__api.h"
#include "corto__meta.h"
#else
#include "corto/lang/corto__type.h"
#include "corto/lang/corto__api.h"
#include "corto/lang/corto__meta.h"
#endif

#if BUILDING_CORTO_LANG && defined _MSC_VER
#define CORTO_LANG_DLL_EXPORTED __declspec(dllexport)
#elif BUILDING_CORTO_LANG
#define CORTO_LANG_EXPORT __attribute__((__visibility__("default")))
#elif defined _MSC_VER
#define CORTO_LANG_EXPORT __declspec(dllimport)
#else
#define CORTO_LANG_EXPORT
#endif

