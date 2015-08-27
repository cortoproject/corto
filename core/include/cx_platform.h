/*
 * cx_platform.h
 *
 *  Created on: May 22, 2012
 *      Author: sander
 */

#ifndef CX_PLATFORM_H_
#define CX_PLATFORM_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#if INTPTR_MAX == INT32_MAX
#define CX_CPU_X86
#elif INTPTR_MAX == INT64_MAX
#define CX_CPU_X64
#else
#warning "corto is not supported on platforms which are neither 32- nor 64-bit."
#endif

#if defined(WIN32) || defined(WIN64)
#define CX_OS_WINDOWS
#elif defined(__linux__)
#define CX_OS_LINUX
#elif defined(__APPLE__) && defined(__MACH__)
#define CX_OS_OSX
#else
#warning "corto is not supported on non-unix or windows operating systems."
#endif

#ifdef CX_CPU_X86
#define CX_CPU_STRING "x86"
#else
#define CX_CPU_STRING "x64"
#endif

#ifdef CX_OS_WINDOWS
#define CX_OS_STRING "windows"
#elif defined(CX_OS_LINUX)
#define CX_OS_STRING "linux"
#define CX_DLL_CONSTRUCT void __attribute__ ((constructor)) DllMain(void)
#elif defined(CX_OS_OSX)
#define CX_OS_STRING "darwin"
#define CX_DLL_CONSTRUCT void __attribute__ ((constructor)) DllMain(void)
#endif

#define CX_PLATFORM_STRING CX_CPU_STRING "-" CX_OS_STRING

#ifdef __cplusplus
}
#endif

#endif /* CX_PLATFORM_H_ */
