/* tc_app/_project.h
 *
 * This file contains generated code. Do not modify!
 */

#if BUILDING_TC_APP && defined _MSC_VER
#define TC_APP_EXPORT __declspec(dllexport)
#elif BUILDING_TC_APP
#define TC_APP_EXPORT __attribute__((__visibility__("default")))
#elif defined _MSC_VER
#define TC_APP_EXPORT __declspec(dllimport)
#else
#define TC_APP_EXPORT
#endif

