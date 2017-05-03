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

#ifndef CORTO_BASE_H
#define CORTO_BASE_H

#include <alloca.h>
#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <math.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <fnmatch.h>
#include <inttypes.h>
#include <execinfo.h>
#include <dlfcn.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ptrace.h>
#include <dirent.h>
#include <unistd.h>
#include <signal.h>
#include <ftw.h>

#ifdef __MACH__
#include <mach/clock.h>
#include <mach/mach.h>
#endif

#ifndef NDEBUG
#define CORTO_MAGIC (0x6B6F7274)
#define CORTO_MAGIC_DESTRUCT (0x74726F6B)
#endif

#ifdef __cplusplus
#ifndef CORTO_CPP_H
#include <utility>
#endif
extern "C" {
#endif

/*
 * Configuration parameters
 *   Increasing these numbers will increase memory usage of Corto in various
 *   scenario's.
 */

/* The maximum nesting level of objects in the hierarchy. There are in total
 * 62 orders of magnitude in the universe, so 64 should be adequate to organize
 * most information sets.
 */
#define CORTO_MAX_SCOPE_DEPTH (64)

/* The maximum inheritance depth. Think 16 is too small? The Java world record
 * is set at 12 levels of inheritance:
 * http://www.javaspecialists.eu/records/index.jsp
 *
 * Please don't use 16 levels of inheritance.
 */
#define CORTO_MAX_INHERITANCE_DEPTH (16)

/* The maximum number of languages you can construct to a single Corto process. */
#define CORTO_MAX_BINDINGS (16)

/* The maximum number of threads that can make use of the Corto
 * API simultaneously. */
#define CORTO_MAX_THREADS (64)

/* The maximum number of nested notifications. */
#define CORTO_MAX_NOTIFY_DEPTH (16)

/* The max length of a scoped identifier (incl \0). When combining this with the
 * MAX_SCOPE_DEPTH, and taking into consideration the scope separator (/) you
 * can have a tree that is 64 levels deep, where each object has a 7-character
 * name, and one object with 6, to compensate for \0. Or, you can have an object
 * in the root with a 510 character name with no children. */
#define CORTO_MAX_PATH_LENGTH (512)

/* The maximum number of objects that a thread can wait for simultaneously */
#define CORTO_MAX_WAIT_FOR_OBJECTS (32)

/* Corto can't load files with extensions longer than 16 characters */
#define CORTO_MAX_FILE_EXTENSION (16)

/* Maximum number of OLS extensions that is supported by the core */
#define CORTO_MAX_OLS_KEY (256)

/* Maximum number of TLS keys that is supported by the core */
#define CORTO_MAX_THREAD_KEY (256)

/* The maximum number of arguments that can be passed to the Corto arg parser */
#define CORTO_ARG_MAX (256)

/* The maximum number of TLS strings that can exist simultaneously */
#define CORTO_MAX_TLS_STRINGS (5)

/* Maximum retained buffer length for TLS string. This ensures that when a very
 * large string is stored in TLS, it will be cleaned up eventually. Keeping it
 * around would be wasteful since chances are low that a string of similar
 * length will take advantage of the memory. */
#define CORTO_MAX_TLS_STRINGS_MAX (1024)

/* Maximum length of a command (to run a process) */
#define CORTO_MAX_CMD (1024)

/* Maximum number of arguments for command */
#define CORTO_MAX_CMD_ARGS (64)

/* Maximum number of operations in an id expression */
#define CORTO_MATCHER_MAX_OP (32)

/* Maximum number of content types in a process */
#define CORTO_MAX_CONTENTTYPE (32)

/* Maximum number of simultaneous benchmarks */
#define CORTO_MAX_BENCHMARK (64)

/* Maximum number of components in logmsg, like: "comp1: comp2: comp3: msg" */
#define CORTO_MAX_LOG_COMPONENTS (16)

/* #define CORTO_WALK_TRACING */
#define CORTO_IC_TRACING
#define CORTO_VM_DEBUG
#define CORTO_VM
#define CORTO_API
#define CORTO_GENERATOR
#define CORTO_CONVERSIONS
#define CORTO_OPERATORS
#define CORTO_LOADER
#define CORTO_VM_BOUNDSCHECK
extern int8_t CORTO_DEBUG_ENABLED;

/* Boolean definitions (compatible with C++ and C99 stdbool) */
#ifndef __cplusplus
#undef bool
#undef true
#undef false
#define bool char
#define false 0
#define true !false
#endif

#ifndef FALSE
#define FALSE (0)
#endif

#ifndef TRUE
#define TRUE (!FALSE)
#endif

/* NULL pointer value */
#ifndef NULL
#define NULL (0x0)
#endif

/* Color constants */
#define CORTO_BLACK   "\033[1;30m"
#define CORTO_RED     "\033[0;31m"
#define CORTO_GREEN   "\033[0;32m"
#define CORTO_YELLOW  "\033[0;33m"
#define CORTO_BLUE    "\033[0;34m"
#define CORTO_MAGENTA "\033[0;35m"
#define CORTO_CYAN    "\033[0;36m"
#define CORTO_WHITE   "\033[1;37m"
#define CORTO_GREY    "\033[0;37m"
#define CORTO_NORMAL  "\033[0;49m"
#define CORTO_BOLD    "\033[1;49m"

/* Macro used to prevent type checking macro's from expanding */
#define ___ 
/* Macro used to annotate parameters in _bootstrap.h */
#define _(txt) 

/* Corto string representing null */
#define CORTO_NULL_STRING ("null")

/* String type that is large enough to hold any corto identifier */
typedef char corto_id[CORTO_MAX_PATH_LENGTH];

/* Builtin collection-implementation definitions */
typedef struct corto_rbtree_s* corto_rbtree;
typedef struct corto_ll_s* corto_ll;

/* Builtin procedure kinds */
#define CORTO_PROCEDURE_STUB (0)
#define CORTO_PROCEDURE_CDECL (1)

/* C language binding type definition macro's */
#define CORTO_ANY(__type) typedef struct __type {corto_type type; void *value; uint8_t owner;} __type
#define CORTO_SEQUENCE(type, subtype, postexpr) typedef struct type {uint32_t length; subtype _()(*buffer) postexpr;} type
#define CORTO_SEQUENCE_EMPTY(type) (type){0}

/* Iterator type */
typedef struct corto_iter corto_iter;
struct corto_iter {
    int (*hasNext)(corto_iter*);
    void *udata;
    void* (*next)(corto_iter*);
    void* (*nextPtr)(corto_iter*);
    void (*release)(corto_iter*);
};

/* Callback used to compare values */
typedef int (*corto_compare_cb)(void* o1, void* o2);

/* Callback used to walk elements in collection */
typedef int (*corto_elementWalk_cb)(void* o, void* userData);


#ifdef __cplusplus
}
#endif

#endif /* CORTO_BASE_H */
