/* test.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "test.h"

int testMain(int argc, char* argv[]) {
/* $begin(main) */
    int result = 0;
    test_Runner runner = test_RunnerCreate("md", argv[0], (argc > 1) ? argv[1] : NULL);
    if (!runner) return -1;
    if (corto_llSize(runner->failures)) {
        result = -1;
    }
    corto_delete(runner);
    return result;
/* $end */
}
