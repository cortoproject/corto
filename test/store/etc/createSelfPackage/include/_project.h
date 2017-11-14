/* _project.h
 *
 * This file contains generated code. Do not modify!
 */

#if BUILDING_CREATESELFPACKAGE && defined _MSC_VER
#define CREATESELFPACKAGE_EXPORT __declspec(dllexport)
#elif BUILDING_CREATESELFPACKAGE
#define CREATESELFPACKAGE_EXPORT __attribute__((__visibility__("default")))
#elif defined _MSC_VER
#define CREATESELFPACKAGE_EXPORT __declspec(dllimport)
#else
#define CREATESELFPACKAGE_EXPORT
#endif

