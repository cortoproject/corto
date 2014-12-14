/* Fast_Block.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef Fast_Block_H
#define Fast_Block_H

#include "hyve.h"
#include "Fast_Node.h"
#include "Fast__type.h"

#include "Fast__api.h"

#include "Fast__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::hyve::Fast::Block::addStatement(Fast::Node statement) */
void Fast_Block_addStatement(Fast_Block _this, Fast_Node statement);

/* ::hyve::Fast::Block::declare(lang::string id,Fast::Variable type,lang::bool isParameter,bool isReference) */
Fast_Local Fast_Block_declare(Fast_Block _this, db_string id, Fast_Variable type, db_bool isParameter, db_bool isReference);

/* ::hyve::Fast::Block::declareReturnVariable(lang::function function) */
Fast_Local Fast_Block_declareReturnVariable(Fast_Block _this, db_function function);

/* ::hyve::Fast::Block::declareTemplate(lang::string id,Fast::Variable type,lang::bool isParameter,bool isReference) */
Fast_Template Fast_Block_declareTemplate(Fast_Block _this, db_string id, Fast_Variable type, db_bool isParameter, db_bool isReference);

/* ::hyve::Fast::Block::lookup(lang::string id) */
Fast_Expression Fast_Block_lookup(Fast_Block _this, db_string id);

/* ::hyve::Fast::Block::lookupLocal(lang::string id) */
Fast_Expression Fast_Block_lookupLocal(Fast_Block _this, db_string id);

/* ::hyve::Fast::Block::resolve(lang::string id) */
Fast_Expression Fast_Block_resolve(Fast_Block _this, db_string id);

/* ::hyve::Fast::Block::setFunction(lang::function function */
void Fast_Block_setFunction(Fast_Block _this, db_function function);

/* virtual ::hyve::Fast::Block::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_Block_toIc(Fast_Block _this, db_icProgram program, db_icStorage storage, db_bool stored);

/* ::hyve::Fast::Block::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_Block_toIc_v(Fast_Block _this, db_icProgram program, db_icStorage storage, db_bool stored);

/* virtual ::hyve::Fast::Block::toIcBody(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_Block_toIcBody(Fast_Block _this, db_icProgram program, db_icStorage storage, db_bool stored);

/* ::hyve::Fast::Block::toIcBody(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_Block_toIcBody_v(Fast_Block _this, db_icProgram program, db_icStorage storage, db_bool stored);

#ifdef __cplusplus
}
#endif
#endif

