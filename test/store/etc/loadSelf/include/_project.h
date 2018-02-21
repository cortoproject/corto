/* _project.h
 * This file is generated. Do not modify the contents of this file.
 */

#if LOADSELF_IMPL && defined _MSC_VER
#define LOADSELF_EXPORT __declspec(dllexport)
#elif LOADSELF_IMPL
#define LOADSELF_EXPORT __attribute__((__visibility__("default")))
#elif defined _MSC_VER
#define LOADSELF_EXPORT __declspec(dllimport)
#else
#define LOADSELF_EXPORT
#endif

