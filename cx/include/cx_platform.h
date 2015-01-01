/*
 * cx_platform.h
 *
 *  Created on: May 22, 2012
 *      Author: sander
 */

#ifndef DB_PLATFORM_H_
#define DB_PLATFORM_H_

#include "stdint.h"

#ifdef __cplusplus
extern "C" {
#endif

#if INTPTR_MAX == INT32_MAX
#define DB_CPU_X86
#elif INTPTR_MAX == INT64_MAX
#define DB_CPU_X64
#else
#error "cortex is not supported on platforms which are neither 32- nor 64-bit."
#endif

#if defined(WIN32) || defined(WIN64)
#define DB_OS_WINDOWS
#elif defined(__linux__)
#define DB_OS_LINUX
#else
#error "cortex is not supported on non-linux or windows operating systems."
#endif

#ifdef DB_CPU_X86
#define DB_CPU_STRING "x86"
#else
#define DB_CPU_STRING "x64"
#endif

#ifdef DB_OS_WINDOWS
#define DB_OS_STRING "windows"
#else
#define DB_OS_STRING "linux2.6"
#define DB_DLL_CONSTRUCT void __attribute__ ((constructor)) DllMain(void)
#endif

#define DB_PLATFORM_STRING DB_CPU_STRING "-" DB_OS_STRING

#ifdef __cplusplus
}
#endif

#endif /* DB_PLATFORM_H_ */
