/*
 * serializer.cpp
 *
 *  Created on: Feb 4, 2013
 *      Author: sander
 */

#include "hyve/serializer.hpp"
#include "hyve.hpp"

/* Link to C-functions */
extern "C" {
namespace hyve {
    typedef lang::int16(*serializerCallback)(serializer _this, value* v, void* userData);
    typedef lang::int16(*serializerConstruct)(void* userData);
    typedef lang::int16(*serializerDestruct)(void* userData);
    lang::int16 db_serialize(serializer s, lang::object o, void* userData);
    lang::int16 db_serializerInit(serializer s);
    lang::int16 db_serializeMembers(serializer s, value* info, void* userData);
    lang::int16 db_serializeElements(serializer s, value* info, void* userData);
    lang::int16 db_serializeValue(serializer s, value* info, void* userData);

    /* This must exactly match the C-struct */
    DB_CLASS_DEF(serializer) {
        lang::_bool initialized;
        lang::modifier access;
        lang::operatorKind accessKind;
        serializerTraceKind traceKind;
        serializerConstruct construct;
        serializerDestruct destruct;
        serializerCallback program[lang::COLLECTION+1];
        serializerCallback metaprogram[CONSTANT+1];
        serializerCallback reference;
    };
    lang::_typedef db_valueType(value* val);
    lang::_void* db_valueValue(value* val);
    lang::object db_valueObject(value* val);
    lang::_char* db_valueString(value* val, lang::_char* buffer, unsigned int length);
    lang::_char* db_valueExpr(value* val, lang::_char* buffer, unsigned int length);
}
}

namespace hyve {

    lang::_typedef value::type() {
        return db_valueType(this);
    }
    void* value::ptr() {
        return db_valueValue(this);
    }
    lang::object value::object() {
        return db_valueObject(this);
    }
    lang::_char* value::string(lang::_char* buffer, unsigned int length){
        return db_valueString(this, buffer, length);
    }
    lang::_char* value::expr(lang::_char* buffer, unsigned int length) {
        return db_valueExpr(this, buffer, length);
    }

    Serializer::Serializer(hyve::lang::modifier access, hyve::lang::operatorKind accessKind, serializerTraceKind traceKind) {
        this->s = NULL;
        this->traceKind = traceKind;
        this->access = access;
        this->accessKind = accessKind;
    }
    Serializer::~Serializer() {
    }

    /* Serialize object */
    lang::int16 Serializer::serialize(lang::object o) {
        struct serializer_s s;
        db_serializerInit(&s);
        s.access = this->access;
        s.accessKind = this->accessKind;
        s.traceKind = this->traceKind;
        s.program[lang::VOID] = NULL;
        s.program[lang::PRIMITIVE] = Serializer::_serializePrimitive;
        s.program[lang::COMPOSITE] = Serializer::_serializeComposite;
        s.program[lang::COLLECTION] = Serializer::_serializeCollection;
        s.metaprogram[hyve::OBJECT] = Serializer::_serializeObject;
        s.metaprogram[hyve::BASE] = Serializer::_serializeBase;
        s.metaprogram[hyve::MEMBER] = Serializer::_serializeMember;
        s.metaprogram[hyve::ELEMENT] = Serializer::_serializeElement;
        s.metaprogram[hyve::CONSTANT] = Serializer::_serializeConstant;
        s.reference = Serializer::_serializeReference;
        this->s = &s;
        return db_serialize(&s, o, this);
    }

    /* Serialize members, elements and values */
    lang::int16 Serializer::serializeMembers(value* info) {
        return db_serializeMembers(this->s, info, this);
    }
    lang::int16 Serializer::serializeElements(value* info) {
        return db_serializeElements(this->s, info, this);
    }
    lang::int16 Serializer::serializeValue(value* info) {
    	lang::int16 result;
    	if (!this->s) {
            struct serializer_s s;
            db_serializerInit(&s);
            s.access = this->access;
            s.accessKind = this->accessKind;
            s.traceKind = this->traceKind;
            s.program[lang::VOID] = NULL;
            s.program[lang::PRIMITIVE] = Serializer::_serializePrimitive;
            s.program[lang::COMPOSITE] = Serializer::_serializeComposite;
            s.program[lang::COLLECTION] = Serializer::_serializeCollection;
            s.metaprogram[hyve::OBJECT] = Serializer::_serializeObject;
            s.metaprogram[hyve::BASE] = Serializer::_serializeBase;
            s.metaprogram[hyve::MEMBER] = Serializer::_serializeMember;
            s.metaprogram[hyve::ELEMENT] = Serializer::_serializeElement;
            s.metaprogram[hyve::CONSTANT] = Serializer::_serializeConstant;
            s.reference = Serializer::_serializeReference;
            this->s = &s;

            /* Statement must be placed here, otherwise this->s would run out of scope */
            result = db_serializeValue(this->s, info, this);
            this->s = NULL;
    	} else {
    		result = db_serializeValue(this->s, info, this);
    	}
    	return result;
    }

    /* Callbacks */
    lang::int16 Serializer::_serializePrimitive(serializer s, value* info, void* userData) {
        (void)s;
        return ((Serializer*)userData)->serializePrimitive(info);
    }
    lang::int16 Serializer::_serializeComposite(serializer s, value* info, void* userData) {
        (void)s;
        return ((Serializer*)userData)->serializeComposite(info);
    }
    lang::int16 Serializer::_serializeCollection(serializer s, value* info, void* userData) {
        (void)s;
        return ((Serializer*)userData)->serializeCollection(info);
    }
    lang::int16 Serializer::_serializeReference(serializer s, value* info, void* userData) {
        (void)s;
        return ((Serializer*)userData)->serializeReference(info);
    }
    lang::int16 Serializer::_serializeObject(serializer s, value* info, void* userData) {
        (void)s;
        return ((Serializer*)userData)->serializeObject(info);
    }
    lang::int16 Serializer::_serializeBase(serializer s, value* info, void* userData) {
        (void)s;
        return ((Serializer*)userData)->serializeBase(info);
    }
    lang::int16 Serializer::_serializeMember(serializer s, value* info, void* userData) {
        (void)s;
        return ((Serializer*)userData)->serializeMember(info);
    }
    lang::int16 Serializer::_serializeElement(serializer s, value* info, void* userData) {
        (void)s;
        return ((Serializer*)userData)->serializeElement(info);
    }
    lang::int16 Serializer::_serializeConstant(serializer s, value* info, void* userData) {
        (void)s;
        return ((Serializer*)userData)->serializeReference(info);
    }
}


