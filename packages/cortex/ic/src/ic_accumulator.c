/* ic_accumulator.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "ic.h"

/* ::cortex::ic::accumulator::construct() */
cx_int16 ic_accumulator_construct(ic_accumulator _this) {
/* $begin(::cortex::ic::accumulator::construct) */
    char name[15];
    ic_storage(_this)->kind = IC_ACCUMULATOR;
    sprintf(name, "#%d", ic_program_getAccId(ic_program_get()));
    ic_storage(_this)->name = cx_strdup(name);

    ic_scope_addStorage(ic_program_get()->scope, ic_storage(_this));

    return ic_storage_construct(ic_storage(_this));
/* $end */
}
