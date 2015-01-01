/* cx_map.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "cx.h"
#include "cx__meta.h"

/* callback ::cortex::lang::class::construct(lang::object object) -> ::cortex::lang::map::construct(lang::map object) */
cx_int16 cx_map_construct(cx_map object) {
/* $begin(::cortex::lang::map::construct) */
    cx_type(object)->hasResources = TRUE;
    cx_type(object)->size = sizeof(cx_map);
    cx_type(object)->alignment = CX_ALIGNMENT(cx_map);
    cx_collection(object)->elementType = object->elementType;
    cx_keep_ext(object, object->elementType, "keep object for elementType");
    cx_collection(object)->max = object->max;
    return cx_type_construct(cx_type(object));
/* $end */
}

/* callback ::cortex::lang::type::init(lang::object object) -> ::cortex::lang::map::init(lang::map object) */
cx_int16 cx_map_init(cx_map object) {
/* $begin(::cortex::lang::map::init) */
    cx_collection(object)->kind = CX_MAP;
    return cx_collection_init(cx_collection(object));
/* $end */
}
