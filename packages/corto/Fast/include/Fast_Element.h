/* Fast_Element.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef Fast_Element_H
#define Fast_Element_H

#include "corto.h"
#include "Fast_Storage.h"
#include "Fast__type.h"
#include "Fast__api.h"
#include "Fast__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::corto::Fast::Element::construct() */
cx_int16 _Fast_Element_construct(Fast_Element _this);
#define Fast_Element_construct(_this) _Fast_Element_construct(Fast_Element(_this))

/* virtual ::corto::Fast::Element::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node Fast_Element_toIc(Fast_Element _this, ic_program program, ic_storage storage, cx_bool stored);

/* ::corto::Fast::Element::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node _Fast_Element_toIc_v(Fast_Element _this, ic_program program, ic_storage storage, cx_bool stored);
#define Fast_Element_toIc_v(_this, program, storage, stored) _Fast_Element_toIc_v(Fast_Element(_this), ic_program(program), ic_storage(storage), stored)

#ifdef __cplusplus
}
#endif
#endif

