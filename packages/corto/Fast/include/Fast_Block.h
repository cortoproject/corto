/* Fast_Block.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef Fast_Block_H
#define Fast_Block_H

#include "corto.h"
#include "Fast_Node.h"
#include "Fast__type.h"
#include "Fast__api.h"
#include "Fast__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::corto::Fast::Block::addStatement(Fast::Node statement) */
cx_void _Fast_Block_addStatement(Fast_Block _this, Fast_Node statement);
#define Fast_Block_addStatement(_this, statement) _Fast_Block_addStatement(Fast_Block(_this), Fast_Node(statement))

/* ::corto::Fast::Block::declare(string id,type type,bool isParameter,bool isReference) */
Fast_Local _Fast_Block_declare(Fast_Block _this, cx_string id, cx_type type, cx_bool isParameter, cx_bool isReference);
#define Fast_Block_declare(_this, id, type, isParameter, isReference) _Fast_Block_declare(Fast_Block(_this), id, cx_type(type), isParameter, isReference)

/* ::corto::Fast::Block::declareReturnVariable(function function) */
Fast_Local _Fast_Block_declareReturnVariable(Fast_Block _this, cx_function function);
#define Fast_Block_declareReturnVariable(_this, function) _Fast_Block_declareReturnVariable(Fast_Block(_this), cx_function(function))

/* ::corto::Fast::Block::declareTemplate(string id,type type,bool isParameter,bool isReference) */
Fast_Template _Fast_Block_declareTemplate(Fast_Block _this, cx_string id, cx_type type, cx_bool isParameter, cx_bool isReference);
#define Fast_Block_declareTemplate(_this, id, type, isParameter, isReference) _Fast_Block_declareTemplate(Fast_Block(_this), id, cx_type(type), isParameter, isReference)

/* ::corto::Fast::Block::lookup(string id) */
Fast_Expression _Fast_Block_lookup(Fast_Block _this, cx_string id);
#define Fast_Block_lookup(_this, id) _Fast_Block_lookup(Fast_Block(_this), id)

/* ::corto::Fast::Block::lookupLocal(string id) */
Fast_Local _Fast_Block_lookupLocal(Fast_Block _this, cx_string id);
#define Fast_Block_lookupLocal(_this, id) _Fast_Block_lookupLocal(Fast_Block(_this), id)

/* ::corto::Fast::Block::resolve(string id) */
Fast_Expression _Fast_Block_resolve(Fast_Block _this, cx_string id);
#define Fast_Block_resolve(_this, id) _Fast_Block_resolve(Fast_Block(_this), id)

/* ::corto::Fast::Block::resolveLocal(string id) */
Fast_Local _Fast_Block_resolveLocal(Fast_Block _this, cx_string id);
#define Fast_Block_resolveLocal(_this, id) _Fast_Block_resolveLocal(Fast_Block(_this), id)

/* ::corto::Fast::Block::setFunction(function function */
cx_void _Fast_Block_setFunction(Fast_Block _this, cx_function function);
#define Fast_Block_setFunction(_this, function) _Fast_Block_setFunction(Fast_Block(_this), cx_function(function))

/* virtual ::corto::Fast::Block::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node Fast_Block_toIc(Fast_Block _this, ic_program program, ic_storage storage, cx_bool stored);

/* ::corto::Fast::Block::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node _Fast_Block_toIc_v(Fast_Block _this, ic_program program, ic_storage storage, cx_bool stored);
#define Fast_Block_toIc_v(_this, program, storage, stored) _Fast_Block_toIc_v(Fast_Block(_this), ic_program(program), ic_storage(storage), stored)

/* virtual ::corto::Fast::Block::toIcBody(ic::program program,ic::storage storage,bool stored) */
ic_node Fast_Block_toIcBody(Fast_Block _this, ic_program program, ic_storage storage, cx_bool stored);

/* ::corto::Fast::Block::toIcBody(ic::program program,ic::storage storage,bool stored) */
ic_node _Fast_Block_toIcBody_v(Fast_Block _this, ic_program program, ic_storage storage, cx_bool stored);
#define Fast_Block_toIcBody_v(_this, program, storage, stored) _Fast_Block_toIcBody_v(Fast_Block(_this), ic_program(program), ic_storage(storage), stored)

#ifdef __cplusplus
}
#endif
#endif

