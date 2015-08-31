/* cx_map.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "cx.h"

/* ::corto::lang::map::construct() */
cx_int16 _cx_map_construct(cx_map _this) {
/* $begin(::corto::lang::map::construct) */
    cx_type(_this)->hasResources = TRUE;
    cx_type(_this)->size = sizeof(cx_map);
    cx_type(_this)->alignment = CX_ALIGNMENT(cx_map);
    cx_collection(_this)->elementType = _this->elementType;
    cx_claim(_this->elementType);
    cx_collection(_this)->max = _this->max;
    return cx_type_construct(cx_type(_this));
/* $end */
}

/* ::corto::lang::map::init() */
cx_int16 _cx_map_init(cx_map _this) {
/* $begin(::corto::lang::map::init) */
    cx_collection(_this)->kind = CX_MAP;
    return cx_collection_init(cx_collection(_this));
/* $end */
}
