/* _interface.h
 *
 * This file contains generated code. Do not modify!
 */

#if BUILDING_CORTO && defined _MSC_VER
#define CORTO_DLL_EXPORTED __declspec(dllexport)
#elif BUILDING_CORTO
#define CORTO_EXPORT __attribute__((__visibility__("default")))
#elif defined _MSC_VER
#define CORTO_EXPORT __declspec(dllimport)
#else
#define CORTO_EXPORT
#endif

