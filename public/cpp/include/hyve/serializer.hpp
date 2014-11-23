/*
 * serialize.hpp
 *
 *  Created on: Feb 3, 2013
 *      Author: sander
 */

#ifndef SERIALIZE_HPP_
#define SERIALIZE_HPP_

#include "hyve/def.hpp"
#include "hyve/lang/_type.hpp"

namespace hyve {
	DB_CLASS(serializer);

	enum valueKind {
	    OBJECT = 0,
	    BASE = 1,
	    VALUE = 2,
	    LITERAL = 3,
	    MEMBER = 4,
	    CALL = 5,
	    ELEMENT = 6,
	    MAP_ELEMENT = 7,
	    CONSTANT = 8/* must be last */
	};

	enum literalKind {
	    LITERAL_BOOLEAN,
	    LITERAL_CHARACTER,
	    LITERAL_INTEGER,
	    LITERAL_UNSIGNED_INTEGER,
	    LITERAL_FLOATING_POINT,
	    LITERAL_STRING,
	    LITERAL_NULL
	};

	/* lang::value
	 *  Structure that is capable of expressing values in a metadata-organized stack. Used by serializer and as expression result.
	 */
	struct value {
	    value* parent;
	    valueKind kind;
	    union {
	        lang::object o;
	        struct {
	            lang::object o;
	            lang::_typedef t;
	            lang::_void* *v;
	        }base;
	        struct {
	            lang::object o;
	            lang::_typedef t;
	            lang::_void* v;
	            lang::uint64 storage;
	        }value;
	        struct {
	            literalKind kind;
	            union {
	                lang::_bool _boolean;
	                lang::_char _character;
	                lang::int64 _integer;
	                lang::uint64 _unsigned_integer;
	                lang::float64 _floating_point;
	                lang::string _string;
	            }v;
	        }literal;
	        struct {
	            lang::object o;
	            lang::member t;
	            lang::_void* v;
	        }member;
	        struct {
	        	lang::object o;
	        	lang::function t;
	        }call;
	        struct {
	            lang::object o;
	            lang::constant* t;
	            lang::_void* v;
	        }constant;
	        struct {
	            lang::object o;
	            struct {
	                lang::_typedef type;
	                lang::uint32 index;
	            } t;
	            lang::_void* v;
	        }element;
	        struct {
	            lang::object o;
	            struct {
	                lang::_typedef type;
	                lang::_typedef keyType;
	                lang::_void *key;
	            }t;
	            lang::_void* v;
	        }mapElement;
	    } is;
        lang::_typedef type();
        void* ptr();
        lang::object object();
        lang::_char* string(lang::_char* buffer, unsigned int length);
        lang::_char* expr(lang::_char* buffer, unsigned int length);
	};

	typedef value valueStack[64];

	typedef enum serializerTraceKind {
		SERIALIZER_TRACE_ALWAYS,
		SERIALIZER_TRACE_ON_FAIL,
		SERIALIZER_TRACE_NEVER
	}serializerTraceKind;

	class Serializer {
	public:
		Serializer(hyve::lang::modifier access, hyve::lang::operatorKind accessKind, serializerTraceKind traceKind);
		virtual ~Serializer();
		virtual lang::int16 construct() {return 0;}
		virtual lang::int16 destruct() {return 0;}
		lang::int16 serialize(hyve::lang::object);
		lang::int16 serializeMembers(value* info);
		lang::int16 serializeElements(value* info);
		lang::int16 serializeValue(value* info);

		/* Overridable serializer-callbacks */
		virtual lang::int16 serializePrimitive(value* info) {(void)info;return 0;}
		virtual lang::int16 serializeComposite(value* info) {(void)info;return this->serializeMembers(info);}
		virtual lang::int16 serializeCollection(value* info) {(void)info;return this->serializeElements(info);}
		virtual lang::int16 serializeReference(value* info) {(void)info;return 0;}
		virtual lang::int16 serializeObject(value* info) {(void)info;return this->serializeValue(info);}
		virtual lang::int16 serializeBase(value *info) {(void)info;return this->serializeValue(info);}
		virtual lang::int16 serializeMember(value* info) {(void)info;return 0;}
		virtual lang::int16 serializeElement(value* info) {(void)info;return 0;}
		virtual lang::int16 serializeConstant(value* info) {(void)info;return 0;}

		/* Static functions for internal usage */
        static lang::int16 _serializePrimitive(serializer s, value* info, void* userData);
        static lang::int16 _serializeComposite(serializer s, value* info, void* userData);
        static lang::int16 _serializeCollection(serializer s, value* info, void* userData);
        static lang::int16 _serializeReference(serializer s, value* info, void* userData);
        static lang::int16 _serializeObject(serializer s, value* info, void* userData);
        static lang::int16 _serializeBase(serializer s, value* info, void* userData);
        static lang::int16 _serializeMember(serializer s, value* info, void* userData);
        static lang::int16 _serializeElement(serializer s, value* info, void* userData);
        static lang::int16 _serializeConstant(serializer s, value* info, void* userData);
	protected:
        serializer s;
		hyve::lang::modifier access;
		hyve::lang::operatorKind accessKind;
		serializerTraceKind traceKind;
	};
}

#endif /* SERIALIZE_HPP_ */
