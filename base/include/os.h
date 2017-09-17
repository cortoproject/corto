/* Copyright (c) 2010-2017 the corto developers
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef CORTO_OS_H
#define CORTO_OS_H

/* UNSTABLE API */

#ifdef __cplusplus
extern "C" {
#endif

#if INTPTR_MAX == INT32_MAX
#define CORTO_CPU_32BIT
#elif INTPTR_MAX == INT64_MAX
#define CORTO_CPU_64BIT
#else
#warning "corto is not supported on platforms which are neither 32- nor 64-bit."
#endif

#if defined(WIN32) || defined(WIN64)
#define CORTO_OS_WINDOWS
#elif defined(__linux__)
#define CORTO_OS_LINUX
#elif defined(__APPLE__) && defined(__MACH__)
#define CORTO_OS_OSX
#else
#warning "corto is not supported on non-unix or windows operating systems."
#endif

#ifdef __i386__
#define CORTO_CPU_STRING "x86"
#elif __x86_64__
#define CORTO_CPU_STRING "x64"
#elif defined(__arm__) && defined(CORTO_CPU_32BIT)
#define CORTO_CPU_STRING "Arm"
#elif defined(__arm__) && defined(CORTO_CPU_64BIT)
#define CORTO_CPU_STRING "Arm64"
#endif

#ifdef CORTO_OS_WINDOWS
#define CORTO_OS_STRING "windows"
#elif defined(CORTO_OS_LINUX)
#define CORTO_OS_STRING "linux"
#define CORTO_DLL_CONSTRUCT void __attribute__ ((constructor)) DllMain(void)
#elif defined(CORTO_OS_OSX)
#define CORTO_OS_STRING "darwin"
#define CORTO_DLL_CONSTRUCT void __attribute__ ((constructor)) DllMain(void)
#endif

#define CORTO_PLATFORM_STRING CORTO_CPU_STRING "-" CORTO_OS_STRING

/* Set environment variable */
CORTO_EXPORT int16_t corto_setenv(const char *varname, const char *value, ...);

/* Get environment variable */
CORTO_EXPORT char* corto_getenv(const char *varname);

/* Parse string with environment variable references */
CORTO_EXPORT char* corto_envparse(const char* str, ...);

/* Same as envparse with va_list */
CORTO_EXPORT char* corto_venvparse(const char* str, va_list args);

/* Get hostname of current machine */
CORTO_EXPORT char* corto_hostname(void);

typedef struct corto_file_s* corto_file;

/* File functions */
CORTO_EXPORT char* corto_fileLoad(const char* file);
CORTO_EXPORT corto_file corto_fileOpen(const char* file);
CORTO_EXPORT corto_file corto_fileAppend(const char* file);
CORTO_EXPORT corto_file corto_fileRead(const char* file);

CORTO_EXPORT FILE* corto_fileGet(corto_file file);
CORTO_EXPORT void corto_fileClose(corto_file);
CORTO_EXPORT char* corto_fileSearch(const char* file, corto_ll locations);
CORTO_EXPORT int corto_fileTest(const char* filefmt, ...);

CORTO_EXPORT unsigned int corto_fileSize(corto_file);
CORTO_EXPORT unsigned int corto_fileTell(corto_file);
CORTO_EXPORT bool corto_fileEof(corto_file);

CORTO_EXPORT char* corto_fileReadLine(corto_file file, char* buf, unsigned int length);

CORTO_EXPORT char* corto_fileExtension(char* file, char* buffer);
CORTO_EXPORT char* corto_filePath(char* file, char* buffer);
CORTO_EXPORT char* corto_fileBase(char* file, char* buffer);

#ifdef __cplusplus
}
#endif

#endif
