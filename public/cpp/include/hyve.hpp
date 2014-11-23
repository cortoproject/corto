/*
 * hyve.hpp
 *
 *  Created on: Dec 27, 2012
 *      Author: sander
 */

#ifndef FRACTAL_HPP_
#define FRACTAL_HPP_

#include "hyve/def.hpp"
#include "hyve/ll.hpp"
#include "hyve/serializer.hpp"
#include "hyve/lang/_type.hpp"
#include "hyve/lang/_meta.hpp"
#include "stdarg.h"

// Root & hyve object
extern ::hyve::lang::object root_h;
extern ::hyve::lang::object hyve_h;

namespace hyve {
	// Object identifier
	typedef lang::_char id[512];

	// Object attribute flags
	extern lang::uint8 ATTR_SCOPED;
	extern lang::uint8 ATTR_WRITABLE;
	extern lang::uint8 ATTR_OBSERVABLE;

	/* Object state flags */
	extern lang::uint8 VALID;
	extern lang::uint8 DECLARED;
	extern lang::uint8 DEFINED;
	extern lang::uint8 DESTRUCTED;

	// Constants
	extern lang::uint32 MAX_SCOPE_DEPTH;

	/* Action-signature for scopeWalk */
	typedef int (*scopeWalkAction)(lang::object o, void* userData);

	/* object lifecycle */
	lang::object _new(lang::_typedef type);
	lang::object _new(lang::_typedef type, lang::uint8 attrs);
	lang::object declare(lang::object parent, const lang::_char* name, lang::_typedef type);
	void destruct(lang::object object);
	lang::int16 define(lang::object o);
	void invalidate(lang::object o);

	/* object-data */
	lang::_typedef _typeof(lang::object o);
	lang::uint32 countof(lang::object o);
	lang::_bool checkState(lang::object o, lang::uint8 state);
	lang::_bool checkAttr(lang::object o, lang::uint8 attr);
	lang::_bool instanceof(lang::_typedef type, lang::object o);

	/* Scoped object-data */
	lang::string nameof(lang::object o);
	lang::object parentof(lang::object o);
	hyve::rbtree* scopeof(lang::object o); /* Dangerous function, because it's not protected by locks */
	hyve::lang::uint32 scopeSize(lang::object o);
	lang::int32 scopeWalk(lang::object o, scopeWalkAction action, void* userData); /* Safe object-walk */
	lang::string fullname(lang::object o, id buffer);
	lang::string relname(lang::object from, lang::object o, id buffer);

	/* Lookup objects either using names or fully qualified names. */
	lang::object lookup(lang::object scope, const lang::_char* name);
	lang::object lookup_ext(lang::object src, lang::object scope, const lang::_char* name, const lang::_char* context);
	lang::function lookupFunction(lang::object scope, const lang::_char* requested, lang::int32 *d);
	lang::object resolve(lang::object scope, const lang::_char* expr);
	lang::object resolve(lang::object src, lang::object scope, const lang::_char* expr, const lang::_char* context);

	/* Reference management */
	int keep(lang::object o);
	int free(lang::object o);
    int keep(lang::object src, lang::object o, const lang::_char* context);
    int free(lang::object src, lang::object o, const lang::_char* context);
	void set(lang::object* o, lang::object v);

	/* Atomic increment\decrement */
	lang::int32 ainc(lang::int32 *v);
	lang::int32 adec(lang::int32 *v);

	/* Sleep */
	void sleep(lang::uint32 sec, lang::uint32 nsec);

	/* Event handling. */
	lang::int32 listen(lang::object observable, lang::observer observer, lang::object _this);
	lang::int32 silence(lang::object observable, lang::observer observer, lang::object _this);
	lang::int32 update(lang::object observable);
	lang::int32 updateFrom(lang::object observable, lang::object _this);
	lang::int32 updateBegin(lang::object observable);
	lang::int32 updateTry(lang::object observable);
	lang::int32 updateEnd(lang::object observable);
	lang::int32 updateEndFrom(lang::object observable, lang::object _this);
	lang::int32 updateCancel(lang::object observable);

	/* Thread-safe reading */
	lang::int32 readBegin(lang::object object);
	lang::int32 readEnd(lang::object object);

	/* Call functions */
	void call(lang::function f, void* result, ...);
	void callv(lang::function f, void* result, va_list args);
	int calla(lang::function f, void* result, lang::uint32 argc, void* argv[]);
	void callb(lang::function f, void* result, void* args);

	/* Convert object to string */
	lang::string toString(lang::object, lang::uint32 maxLength);
	lang::string toString(value* value, lang::uint32 maxLength);

	/* Parse expression */
	value* parseExpr(lang::object o, lang::string expr, valueStack stack, lang::uint32 *count);

	/* Primitive type conversions */
	lang::int16 convert(lang::primitive fromType, void* from, lang::primitive toType, void* to);

	/* Error reporting */
	void trace(const lang::_char* fmt, ...);
	void warning(const lang::_char* fmt, ...);
	void error(const lang::_char* fmt, ...);
	void critical(const lang::_char* fmt, ...);

	/* exithandlers */
	void onunload(void(*handler)(void*), void* userData);
	void onexit(void(*handler)(void*), void* userData);

	/* import module */
	int import(const hyve::lang::_char* name);

	/* Allocation */
	void* alloc(hyve::lang::uint32 size);
	hyve::lang::string strdup(hyve::lang::string string);
	void dealloc(void* ptr);
}

#endif /* FRACTAL_HPP_ */
