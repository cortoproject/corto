/* Fast_Block.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef Fast_Block_H
#define Fast_Block_H

#include "cortex.h"
#include "Fast_Node.h"
#include "Fast__type.h"

#include "Fast__api.h"

#include "Fast__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::cortex::Fast::Block::addStatement(Fast::Node statement) */
void Fast_Block_addStatement(Fast_Block _this, Fast_Node statement);

/* ::cortex::Fast::Block::declare(string id,Fast::Variable type,bool isParameter,bool isReference) */
Fast_Local Fast_Block_declare(Fast_Block _this, cx_string id, Fast_Variable type, cx_bool isParameter, cx_bool isReference);

/* ::cortex::Fast::Block::declareReturnVariable(function function) */
Fast_Local Fast_Block_declareReturnVariable(Fast_Block _this, cx_function function);

/* ::cortex::Fast::Block::declareTemplate(string id,Fast::Variable type,bool isParameter,bool isReference) */
Fast_Template Fast_Block_declareTemplate(Fast_Block _this, cx_string id, Fast_Variable type, cx_bool isParameter, cx_bool isReference);

/* ::cortex::Fast::Block::lookup(string id) */
Fast_Expression Fast_Block_lookup(Fast_Block _this, cx_string id);

/* ::cortex::Fast::Block::lookupLocal(string id) */
Fast_Local Fast_Block_lookupLocal(Fast_Block _this, cx_string id);

/* ::cortex::Fast::Block::resolve(string id) */
Fast_Expression Fast_Block_resolve(Fast_Block _this, cx_string id);

/* ::cortex::Fast::Block::resolveLocal(string id) */
Fast_Local Fast_Block_resolveLocal(Fast_Block _this, cx_string id);

/* ::cortex::Fast::Block::setFunction(function function */
void Fast_Block_setFunction(Fast_Block _this, cx_function function);

/* virtual ::cortex::Fast::Block::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_Block_toIc(Fast_Block _this, cx_icProgram program, cx_icStorage storage, cx_bool stored);

/* ::cortex::Fast::Block::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_Block_toIc_v(Fast_Block _this, cx_icProgram program, cx_icStorage storage, cx_bool stored);

/* virtual ::cortex::Fast::Block::toIcBody(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_Block_toIcBody(Fast_Block _this, cx_icProgram program, cx_icStorage storage, cx_bool stored);

/* ::cortex::Fast::Block::toIcBody(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_Block_toIcBody_v(Fast_Block _this, cx_icProgram program, cx_icStorage storage, cx_bool stored);

#ifdef __cplusplus
}
#endif
#endif

