/* Fast_Element.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef Fast_Element_H
#define Fast_Element_H

#include "cortex.h"
#include "Fast_Expression.h"
#include "Fast__type.h"

#include "Fast__api.h"

#include "Fast__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::cortex::Fast::Element::construct() */
cx_int16 Fast_Element_construct(Fast_Element _this);

/* virtual ::cortex::Fast::Element::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_Element_toIc(Fast_Element _this, cx_icProgram program, cx_icStorage storage, cx_bool stored);

/* ::cortex::Fast::Element::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_Element_toIc_v(Fast_Element _this, cx_icProgram program, cx_icStorage storage, cx_bool stored);

#ifdef __cplusplus
}
#endif
#endif

