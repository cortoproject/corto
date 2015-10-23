/* ic_accumulator.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "ic.h"

/* ::corto::ic::accumulator::construct() */
corto_int16 _ic_accumulator_construct(ic_accumulator this) {
/* $begin(::corto::ic::accumulator::construct) */
    char name[15];
    ic_storage(this)->kind = IC_ACCUMULATOR;
    sprintf(name, "#%d", ic_program_getAccId(ic_program_get()));
    ic_storage(this)->name = corto_strdup(name);

    ic_scope_addStorage(ic_program_get()->scope, ic_storage(this));

    return ic_storage_construct(ic_storage(this));
/* $end */
}
