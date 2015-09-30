/* tc_stringser__load.c
 *
 * This file is generated. Do not modify.
 */

#define tc_stringser_LIB
#include "tc.h"

int cortomain(int argc, char* argv[]) {
    if (tc_stringser_load()) return -1;
    int tc_stringserMain(int argc, char* argv[]);
    if (tc_stringserMain(argc, argv)) return -1;
    return 0;
}

