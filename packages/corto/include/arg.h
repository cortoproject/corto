
#ifndef CORTO_ARG_H
#define CORTO_ARG_H

/* Command-line argument parsing utility library */

#include "corto/ll.h"

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
} corto_argdata;

corto_argdata* corto_argparse(char *argv[], corto_argdata *data);
void corto_argclean(corto_argdata *data);

#ifdef __cplusplus
}
#endif

#endif /* CORTO_ARG_H */
