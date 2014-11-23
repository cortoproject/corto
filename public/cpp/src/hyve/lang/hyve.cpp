/*
 * hyve.hpp
 *
 *  Created on: Dec 27, 2012
 *      Author: sander
 */

#include "hyve.hpp"
#include "db_util.h"
#include "stdlib.h"
#include "string.h"

/* Declare functions from C-binding.
 * The header of this cannot be include, because this would also include the
 * db__type header in which C++ keywords are used in typedefinitions. */

extern "C" {
::hyve::lang::object root_o;
::hyve::lang::object hyve_o;
#include "db_def.h"
namespace hyve {
	typedef void* db_rbtree;

	/* object lifecycle */
	lang::object db_new(lang::_typedef type);
	lang::object db_new_ext(lang::object src, lang::_typedef type, lang::uint8 attrs, lang::string context);
	lang::object db_declare(lang::object parent, const lang::_char* name, lang::_typedef type);
	void db_destruct(lang::object object);
	lang::int16 db_define(lang::object o);
	void db_invalidate(lang::object o);

	/* object-data */
	lang::_typedef db_typeof(lang::object o);
	lang::uint32 db_countof(lang::object o);
	lang::_bool db_checkState(lang::object o, lang::int8 state);
	lang::_bool db_checkAttr(lang::object o, lang::int8 attr);
	lang::_bool db_instanceof(lang::_typedef type, lang::object o);

	/* Scoped object-data */
	lang::string db_nameof(lang::object o);
	lang::object db_parentof(lang::object o);
	db_rbtree db_scopeof(lang::object o); /* Dangerous function, because it's not protected by locks */
	lang::uint32 db_scopeSize(lang::object o);
	lang::int32 db_scopeWalk(lang::object o, scopeWalkAction action, void* userData); /* Safe object-walk */
	lang::string db_fullname(lang::object o, id buffer);
	lang::string db_relname(lang::object from, lang::object o, id buffer);

	/* Lookup objects either using names or fully qualified names. */
	lang::object db_lookup(lang::object scope, const lang::_char* name);
	lang::object db_lookup_ext(lang::object src, lang::object scope, const lang::_char* name, const lang::_char* context);
	lang::function db_lookupFunction(lang::object scope, const lang::_char* requested, lang::int32 *d);
	lang::object db_resolve(lang::object scope, const lang::_char* expr);
	lang::object db_resolve_ext(lang::object src, lang::object scope, const lang::_char* expr, lang::_bool allowCastable, const lang::_char* context);

	/* Reference management */
	int db_keep(lang::object o);
	int db_free(lang::object o);
	int db_keep_ext(lang::object source, lang::object o, const lang::_char* context);
	int db_free_ext(lang::object source, lang::object o, const lang::_char* context);
	void db_set(lang::object* o, lang::object v);

	int db_ainc(int *v);
	int db_adec(int *v);

	void db_sleep(lang::uint32 sec, lang::uint32 nsec);

	/* Event handling. */
	lang::int32 db_listen(lang::object observable, lang::observer observer, lang::object _this);
	lang::int32 db_silence(lang::object observable, lang::observer observer, lang::object _this);
	lang::int32 db_update(lang::object observable);
	lang::int32 db_updateFrom(lang::object observable, lang::object _this);
	lang::int32 db_updateBegin(lang::object observable);
	lang::int32 db_updateTry(lang::object observable);
	lang::int32 db_updateEnd(lang::object observable);
	lang::int32 db_updateEndFrom(lang::object observable, lang::object _this);
	lang::int32 db_updateCancel(lang::object observable);

	/* Thread-safe reading */
	lang::int32 db_readBegin(lang::object object);
	lang::int32 db_readEnd(lang::object object);

	/* Call functions */
	void db_callv(lang::function f, void* result, va_list args);
	int db_calla(lang::function f, void* result, lang::uint32 argc, void* argv[]);
	void db_callb(lang::function f, void* result, void* args);

	/* Convert object to string */
	lang::string db_toString(lang::object o, lang::uint32 maxLength);
	lang::string db_valueToString(value* value, lang::uint32 maxLength);

	/* Parse expression */
	// value* db_parseExpr(lang::object o, lang::string expr, valueStack stack, lang::uint32 *count);
	value* db_expr(lang::object o, lang::string expr, valueStack stack, lang::uint32 *count);

    /* Primitive type conversions */
    lang::int16 db_convert(lang::primitive fromType, void* from, lang::primitive toType, void* to);

	/* Error reporting */
	void db_tracev(const lang::_char* fmt, va_list args);
	void db_warningv(const lang::_char* fmt, va_list args);
	void db_errorv(const lang::_char* fmt, va_list args);
	void db_criticalv(const lang::_char* fmt, va_list args);

	/* Exithandler */
	void db_onunload(void(*handler)(void*), void* userData);
	void db_onexit(void(*handler)(void*), void* userData);

	/* Import module */
	int db_load(const hyve::lang::_char* name);

}
}

::hyve::lang::object root_h;
::hyve::lang::object hyve_h;

namespace hyve {
	// Object attribute flags
	lang::uint8 ATTR_SCOPED = 1;
	lang::uint8 ATTR_WRITABLE = 2;
	lang::uint8 ATTR_OBSERVABLE = 4;

    lang::uint8 VALID = 1;
    lang::uint8 DECLARED = 2;
    lang::uint8 DEFINED = 4;
    lang::uint8 DESTRUCTED = 8;

	// Constants
	lang::uint32 MAX_SCOPE_DEPTH = DB_MAX_SCOPE_DEPTH;

	/* object lifecycle */
	lang::object _new(lang::_typedef type) {
		return db_new(type);
	}
	lang::object _new(lang::_typedef type, lang::uint8 attrs) {
		return db_new_ext(NULL, type, attrs, NULL);
	}

	lang::object declare(lang::object parent, const lang::_char* name, lang::_typedef type) {
		return db_declare(parent, name, type);
	}

	void destruct(lang::object object) {
		db_destruct(object);
	}

	lang::int16 define(lang::object o) {
		return db_define(o);
	}
	void invalidate(lang::object o) {
		return db_invalidate(o);
	}

	/* object-data */
	lang::_typedef _typeof(lang::object o) {
		return db_typeof(o);
	}
	lang::uint32 countof(lang::object o) {
		return db_countof(o);
	}
	lang::_bool checkState(lang::object o, lang::uint8 state) {
		return db_checkState(o, state);
	}
	lang::_bool checkAttr(lang::object o, lang::uint8 attr) {
		return db_checkAttr(o, attr);
	}
	lang::_bool instanceof(lang::_typedef type, lang::object o) {
		return db_instanceof(type, o);
	}

	/* Scoped object-data */
	lang::string nameof(lang::object o) {
		return db_nameof(o);
	}
	lang::object parentof(lang::object o) {
		return db_parentof(o);
	}
	hyve::rbtree* scopeof(lang::object o) {
		return (hyve::rbtree*)db_scopeof(o);
	}
	hyve::lang::uint32 scopeSize(lang::object o) {
	    return db_scopeSize(o);
	}
	lang::int32 scopeWalk(lang::object o, scopeWalkAction action, void* userData) {
		return db_scopeWalk(o, action, userData);
	}
	lang::string fullname(lang::object o, id buffer) {
		return db_fullname(o, buffer);
	}
    lang::string relname(lang::object from, lang::object o, id buffer) {
        return db_relname(from, o, buffer);
    }

	/* Lookup objects either using names or fully qualified names. */
	lang::object lookup(lang::object scope, const lang::_char* name) {
		return db_lookup(scope, name);
	}
	lang::object lookup_ext(lang::object src, lang::object scope, const lang::_char* name, const lang::_char* context) {
		return db_lookup_ext(src, scope, name, context);
	}
	lang::function lookupFunction(lang::object scope, const lang::_char* requested, lang::int32 *d) {
		return db_lookupFunction(scope, requested, d);
	}
	lang::object resolve(lang::object scope, const lang::_char* expr) {
		return db_resolve(scope, expr);
	}
	lang::object resolve(lang::object src, lang::object scope, const lang::_char* expr, const lang::_char* context) {
		return db_resolve_ext(src, scope, expr, FALSE, context);
	}

	/* Reference management */
	int keep(lang::object o) {
		return db_keep(o);
	}
	int free(lang::object o) {
		return db_free(o);
	}
    int keep(lang::object src, lang::object o, const lang::_char* context) {
        return db_keep_ext(src, o, context);
    }
    int free(lang::object src, lang::object o, const lang::_char* context) {
        return db_free_ext(src, o, context);
    }
	void set(lang::object* o, lang::object v) {
		return db_set(o, v);
	}

	/* Atomic increment\decrement */
	lang::int32 ainc(lang::int32 *v) {
		return db_ainc(v);
	}
	lang::int32 adec(lang::int32 *v) {
		return db_adec(v);
	}

	void sleep(lang::uint32 sec, lang::uint32 nsec) {
		db_sleep(sec,nsec);
	}

	/* Event handling. */
	lang::int32 listen(lang::object observable, lang::observer observer, lang::object _this) {
		return db_listen(observable, observer, _this);
	}
	lang::int32 silence(lang::object observable, lang::observer observer, lang::object _this) {
		return db_silence(observable, observer, _this);
	}
	lang::int32 update(lang::object observable) {
		return db_update(observable);
	}
	lang::int32 updateFrom(lang::object observable, lang::object _this) {
		return db_updateFrom(observable, _this);
	}
	lang::int32 updateBegin(lang::object observable) {
		return db_updateBegin(observable);
	}
	lang::int32 updateTry(lang::object observable) {
		return db_updateTry(observable);
	}
	lang::int32 updateEnd(lang::object observable) {
		return db_updateEnd(observable);
	}
	lang::int32 updateEndFrom(lang::object observable, lang::object _this) {
		return db_updateEndFrom(observable, _this);
	}
	lang::int32 updateCancel(lang::object observable) {
		return db_updateCancel(observable);
	}

	/* Thread-safe reading */
	lang::int32 readBegin(lang::object object) {
		return db_readBegin(object);
	}
	lang::int32 readEnd(lang::object object) {
		return db_readEnd(object);
	}

	/* Call functions */
	void call(lang::function f, void* result, ...) {
		va_list list;
		va_start(list, result);
		db_callv(f, result, list);
		va_end(list);
	}
	void callv(lang::function f, void* result, va_list args) {
		db_callv(f, result, args);
	}
	int calla(lang::function f, void* result, lang::uint32 argc, void* argv[]) {
	    DB_UNUSED(f);
	    DB_UNUSED(result);
	    DB_UNUSED(argc);
	    DB_UNUSED(argv);
		/*return db_calla(f, result, argc, argv); TODO */
	    return 0;
	}
	void callb(lang::function f, void* result, void* args) {
		return db_callb(f, result, args);
	}

	/* Convert object to string */
	lang::string toString(lang::object o, lang::uint32 maxLength) {
		return db_toString(o, maxLength);
	}

	lang::string toString(value* value, lang::uint32 maxLength) {
		return db_valueToString(value, maxLength);
	}

	/* Parse expression */
	value* parseExpr(lang::object o, lang::string expr, valueStack stack, lang::uint32 *count) {
		return db_expr(o, expr, stack, count);
	}

    /* Primitive type conversions */
    lang::int16 convert(lang::primitive fromType, void* from, lang::primitive toType, void* to) {
        return db_convert(fromType, from, toType, to);
    }

	/* Error reporting */
	void trace(const lang::_char* fmt, ...) {
		va_list list;
		va_start(list, fmt);
		db_tracev(fmt, list);
		va_end(list);

	}
	void warning(const lang::_char* fmt, ...) {
		va_list list;
		va_start(list, fmt);
		db_warningv(fmt, list);
		va_end(list);
	}
	void error(const lang::_char* fmt, ...) {
		va_list list;
		va_start(list, fmt);
		db_errorv(fmt, list);
		va_end(list);
	}
	void critical(const lang::_char* fmt, ...) {
		va_list list;
		va_start(list, fmt);
		db_criticalv(fmt, list);
		va_end(list);
	}

	void onunload(void(*handler)(void*), void* userData) {
	    db_onunload(handler, userData);
	}

    void onexit(void(*handler)(void*), void* userData) {
        db_onexit(handler, userData);
    }

    /* import module */
    int import(const hyve::lang::_char* name) {
        return db_load(name);
    }

	void* alloc(hyve::lang::uint32 size) {
		return malloc(size);
	}
	hyve::lang::string strdup(hyve::lang::string string) {
		return ::strdup(string);
	}
	void dealloc(void* ptr) {
		::free(ptr);
	}
}

extern "C" int hyvemain(int argc, char* argv[]) {
    DB_UNUSED(argc);
    DB_UNUSED(argv);
    ::root_h = ::root_o;
    ::hyve_h = ::hyve_o;
    hyve::lang::load();
    return 0;
}


