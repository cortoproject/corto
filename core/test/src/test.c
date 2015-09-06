/* test.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#define test_LIB
#include "test.h"

int testMain(int argc, char* argv[]) {
/* $begin(main) */
    int result = 0;
    test_Runner runner = test_RunnerCreate("core");
    if (!runner) return -1;
    if (cx_llSize(runner->failures)) {
        result = -1;
    }
    cx_delete(runner);
    return result;
/* $end */
}
