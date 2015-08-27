/* ic_program.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef ic_program_H
#define ic_program_H

#include "corto.h"
#include "ic__type.h"
#include "ic__api.h"
#include "ic__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::corto::ic::program::add(node n) */
cx_void _ic_program_add(ic_program _this, ic_node n);
#define ic_program_add(_this, n) _ic_program_add(ic_program(_this), ic_node(n))

/* ::corto::ic::program::assemble() */
cx_int16 _ic_program_assemble(ic_program _this);
#define ic_program_assemble(_this) _ic_program_assemble(ic_program(_this))

/* ::corto::ic::program::construct() */
cx_int16 _ic_program_construct(ic_program _this);
#define ic_program_construct(_this) _ic_program_construct(ic_program(_this))

/* ::corto::ic::program::declareVariable(string name,type type,bool isReference,bool holdsReturn,bool isParameter,bool isReturn) */
ic_variable _ic_program_declareVariable(ic_program _this, cx_string name, cx_type type, cx_bool isReference, cx_bool holdsReturn, cx_bool isParameter, cx_bool isReturn);
#define ic_program_declareVariable(_this, name, type, isReference, holdsReturn, isParameter, isReturn) _ic_program_declareVariable(ic_program(_this), name, cx_type(type), isReference, holdsReturn, isParameter, isReturn)

/* ::corto::ic::program::get() */
ic_program _ic_program_get(void);
#define ic_program_get() _ic_program_get()

/* ::corto::ic::program::getAccId() */
cx_uint32 _ic_program_getAccId(ic_program _this);
#define ic_program_getAccId(_this) _ic_program_getAccId(ic_program(_this))

/* ::corto::ic::program::getElement(storage base,node index) */
ic_element _ic_program_getElement(ic_program _this, ic_storage base, ic_node index);
#define ic_program_getElement(_this, base, index) _ic_program_getElement(ic_program(_this), ic_storage(base), ic_node(index))

/* ::corto::ic::program::getLabel() */
cx_uint32 _ic_program_getLabel(ic_program _this);
#define ic_program_getLabel(_this) _ic_program_getLabel(ic_program(_this))

/* ::corto::ic::program::getMember(storage base,member m) */
ic_member _ic_program_getMember(ic_program _this, ic_storage base, cx_member m);
#define ic_program_getMember(_this, base, m) _ic_program_getMember(ic_program(_this), ic_storage(base), cx_member(m))

/* ::corto::ic::program::getObject(object o) */
ic_object _ic_program_getObject(ic_program _this, cx_object o);
#define ic_program_getObject(_this, o) _ic_program_getObject(ic_program(_this), o)

/* ::corto::ic::program::getVariable(string name) */
ic_variable _ic_program_getVariable(ic_program _this, cx_string name);
#define ic_program_getVariable(_this, name) _ic_program_getVariable(ic_program(_this), name)

/* ::corto::ic::program::popAccumulator() */
cx_void _ic_program_popAccumulator(ic_program _this);
#define ic_program_popAccumulator(_this) _ic_program_popAccumulator(ic_program(_this))

/* ::corto::ic::program::popScope() */
cx_void _ic_program_popScope(ic_program _this);
#define ic_program_popScope(_this) _ic_program_popScope(ic_program(_this))

/* ::corto::ic::program::pushAccumulator(type type,bool isReference,bool holdsReturn) */
ic_accumulator _ic_program_pushAccumulator(ic_program _this, cx_type type, cx_bool isReference, cx_bool holdsReturn);
#define ic_program_pushAccumulator(_this, type, isReference, holdsReturn) _ic_program_pushAccumulator(ic_program(_this), cx_type(type), isReference, holdsReturn)

/* ::corto::ic::program::pushFunction(function function) */
ic_scope _ic_program_pushFunction(ic_program _this, cx_function function);
#define ic_program_pushFunction(_this, function) _ic_program_pushFunction(ic_program(_this), cx_function(function))

/* ::corto::ic::program::pushScope() */
ic_scope _ic_program_pushScope(ic_program _this);
#define ic_program_pushScope(_this) _ic_program_pushScope(ic_program(_this))

/* ::corto::ic::program::run(word result) */
cx_int16 _ic_program_run(ic_program _this, cx_word result);
#define ic_program_run(_this, result) _ic_program_run(ic_program(_this), result)

/* ::corto::ic::program::str() */
cx_string _ic_program_str(ic_program _this);
#define ic_program_str(_this) _ic_program_str(ic_program(_this))

#ifdef __cplusplus
}
#endif
#endif

