
#ifndef ARGPARSE_H
#define ARGPARSE_H

/* Add include files here */

/* Command-line argument parsing utility library */

#include "corto/corto.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Argument parser that requires no callbacks
 */
typedef struct corto_argdata {
    const char *pattern;
    corto_ll *match;
    corto_ll *args;
    corto_int8 count;
    corto_ll gc;
} corto_argdata;

corto_argdata* corto_argparse(char *argv[], corto_argdata *data);
void corto_argclean(corto_argdata *data);

#ifdef __cplusplus
}
#endif

#endif /* ARGPARSE_H */
