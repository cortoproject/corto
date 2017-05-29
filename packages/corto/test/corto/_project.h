/* _project.h
 *
 * This file contains generated code. Do not modify!
 */

#if BUILDING_TEST && defined _MSC_VER
#define TEST_EXPORT __declspec(dllexport)
#elif BUILDING_TEST
#define TEST_EXPORT __attribute__((__visibility__("default")))
#elif defined _MSC_VER
#define TEST_EXPORT __declspec(dllimport)
#else
#define TEST_EXPORT
#endif

