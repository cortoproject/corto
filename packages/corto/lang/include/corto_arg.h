/*
 *                         OpenSplice DDS
 *
 *   This software and documentation are Copyright 2006 to 2011 PrismTech
 *   Limited and its licensees. All rights reserved. See file:
 *
 *                     $OSPL_HOME/LICENSE
 *
 *   for full copyright notice and license terms.
 *
 */

#ifndef IDL_ARG_H_
#define IDL_ARG_H_

/* Command-line argument parsing utility library */

#ifdef __cplusplus
extern "C" {
#endif

/** Argument-callback for parser.
 *
 * @param arg The current parsed argument without the '-' or '--'.
 * @param argc The number of arguments available after the current argument.
 * @param argv The argument-vector starting from the current argument.
 * @return The consumed number of arguments. -1 if failed.
 */
typedef int (*corto_argCallback)(char* arg, int argc, char* argv[]);

/** Set callback for specific argument.
 *
 * @param arg The argument switch. Can be a single character (-a) or a string (--abc).
 * @param callback The callback to execute when the argument is encountered.
 * @param min The minimum number (>0) of occurrences.
 * @param max The maximum number (>-1) of occurrences (-1 meaning infinite).
 */
int corto_argSet(char* arg, corto_argCallback callback, int min, int max);

/** Express an exclusive relation between two arguments.
 *
 * Only one of both arguments can be specified on the commandline.
 * This relation is implicitly mutual.
 *
 * @param arg1 First argument of exclusive relation.
 * @param arg2 Second argument of exclusive relation.
 */
int corto_argExclusive(char* arg1, char* arg2);

/** Express a dependency relation between two arguments.
 *
 * When arg1 is specified, arg2 should also be specified.
 * This relation is not mutual.
 *
 * @param arg1 First argument of dependency relation.
 * @param arg2 Second argument of dependency relation.
 */
int corto_argDepend(char* arg1, char* arg2);

/** Parse arguments.
 */
int corto_argParse(int argc, char* argv[]);

/** Clear argument administration
 */
void corto_argClear(void);

#ifdef __cplusplus
}
#endif

#endif /* IDL_ARG_H_ */
