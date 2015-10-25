/* $CORTO_GENERATED
 *
 * ic_accumulator.c
 *
 * Code written between the begin and end tags will be preserved when the
 * file is regenerated.
 */

#include "ic.h"

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
