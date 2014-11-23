/*
 * db_primitive.c
 *
 *  Created on: Aug 9, 2012
 *      Author: sander
 */

#include "db_object.h"
#include "db__meta.h"
#include "db__type.h"
#include "db__primitive.h"
#include "db_collection.h"
#include "db_class.h"
#include "db_err.h"
#include "db_util.h"
#include "db_mem.h"

db_bool db_type_compatible_v(db_type _this, db_type type);

/* The following primitiveKind\width combinations are possible:
 * [0-4]   - BINARY: 8,16,32,64,word
 * [5]     - BOOLEAN: 8
 * [6-7]   - CHAR: 8,16 (UTF-8 & UTF-16)
 * [8-13]  - INT: 8,16,32,64,word
 * [14-19] - UINT: 8,16,32,64,word
 * [20-21] - FLOAT: 32,64
 * [22]    - TEXT: word
 * [23]    - ENUM: 32
 * [24]    - BITMASK: 32
 */

db_uint8 db__primitive_convertId(db_primitiveKind kind, db_width width) {
    db_uint8 id = 0;

    switch(kind) {
    case DB_BINARY:
        id = width;
        break;
    case DB_BOOLEAN:
        id = 5;
        break;
    case DB_CHARACTER:
        id = 6 + width;
        break;
    case DB_INTEGER:
        id = 8 + width;
        break;
    case DB_ALIAS:
    case DB_UINTEGER:
        id = 14 + width;
        break;
    case DB_FLOAT:
        id = 20 + width - 2;
        break;
    case DB_TEXT:
        id = 22;
        break;
    case DB_ENUM:
        id = 23;
        break;
    case DB_BITMASK:
        id = 24;
        break;
    }
    return id;
}

/* type::init -> ::primitive::init */
db_int16 db_primitive_init(db_primitive object) {
    db_type(object)->kind = DB_PRIMITIVE;
    return db_type__init((db_type)object);
}

/* ::class::construct -> ::primitive::construct */
db_int16 db_primitive_construct(db_primitive object) {

	switch(object->width) {
	case DB_WIDTH_8:
		db_type(object)->size = 1;
		db_type(object)->alignment = DB_ALIGNMENT(db_char);
		break;
	case DB_WIDTH_16:
		db_type(object)->size = 2;
		db_type(object)->alignment = DB_ALIGNMENT(db_int16);
		break;
	case DB_WIDTH_32:
		db_type(object)->size = 4;
		db_type(object)->alignment = DB_ALIGNMENT(db_int32);
		break;
	case DB_WIDTH_64:
		db_type(object)->size = 8;
		db_type(object)->alignment = DB_ALIGNMENT(db_int64);
		break;
	case DB_WIDTH_WORD:
		db_type(object)->size = sizeof(void*);
		db_type(object)->alignment = DB_ALIGNMENT(db_word);
		break;
	}

	/* Assign convertId which enables quick lookups of implicit primitive conversions. */
	object->convertId = db__primitive_convertId(object->kind, object->width);

	return db_type_construct(db_type(object));
}

void db_primitive_destruct(db_primitive object) {
	db_type_destruct(db_type(object));
}

/* virtual primitive::castable */

/* The following conversions are valid:
 * binary -> bool,int,uint,text
 * bool -> binary,int,uint,text
 * char -> binary,int,uint,text
 * int -> binary,bool,char,uint,float,text
 * uint -> binary,bool,char,int,float,text
 * float -> int,uint,text
 * enum -> text
 * text -> binary,bool,char,int,uint,enum
 *
 * So for example, castable(bool,float) returns FALSE, where castable(uint,float) returns TRUE.
 * For references the same rules apply, as long as both compared types are a reference.
 */
db_bool db_primitive_castable(db_primitive _this, db_type type) {
    db_bool result;

    result = FALSE;
    
    /* Perform generic type::compatible routine first. */
    if (!db_type_compatible_v(db_type(_this), type)) {
        if (db_type(_this)->reference == type->reference) {
        	if (type->kind == DB_PRIMITIVE) {
				db_primitiveKind kind = db_primitive(type)->kind;
				if (_this->kind != kind) {
					switch(_this->kind) {
					case DB_ALIAS:
						result = FALSE;
						break;
                    case DB_BOOLEAN:
					case DB_BINARY:
						switch(kind) {
						case DB_BOOLEAN:
						case DB_BINARY:
						case DB_INTEGER:
						case DB_UINTEGER:
                        case DB_FLOAT:
						case DB_TEXT:
						case DB_ENUM:
						case DB_BITMASK:
							result = TRUE;
							break;
						default:
							break;
						}
						break;
					case DB_CHARACTER:
						switch(kind) {
						case DB_BINARY:
						case DB_INTEGER:
						case DB_UINTEGER:
						case DB_TEXT:
							result = TRUE;
							break;
						default:
							break;
						}
						break;
					case DB_INTEGER:
					case DB_UINTEGER:
						switch(kind) {
						case DB_BINARY:
						case DB_BOOLEAN:
						case DB_CHARACTER:
						case DB_INTEGER:
						case DB_UINTEGER:
						case DB_FLOAT:
						case DB_TEXT:
						case DB_ENUM:
						case DB_BITMASK:
							result = TRUE;
						default:
							break;
						}
						break;
					case DB_FLOAT:
						switch(kind) {
                        case DB_BINARY:
						case DB_INTEGER:
						case DB_UINTEGER:
						case DB_TEXT:
							result = TRUE;
						default:
							break;
						}
						break;
					case DB_ENUM:
					case DB_BITMASK:
						switch(kind) {
						case DB_INTEGER:
						case DB_UINTEGER:
						case DB_TEXT:
							result = TRUE;
							break;
						default:
							break;
						}
						break;
					case DB_TEXT:
						switch(kind) {
						case DB_BINARY:
						case DB_BOOLEAN:
						case DB_CHARACTER:
						case DB_INTEGER:
						case DB_UINTEGER:
						case DB_FLOAT:
						case DB_ENUM:
							result = TRUE;
						default:
							break;
						}
						break;
					}
				} else {
					if (_this->kind == DB_ALIAS) {
						result = !strcmp(db_alias(_this)->typeName, db_alias(type)->typeName);
					} else {
						result = TRUE;
					}
				}
        	}
        }
    } else {
        result = TRUE;
    }

    return result;
}

/* virtual ::primitive::compatible */
db_bool db_primitive_compatible(db_primitive _this, db_type type) {
    db_bool result;

    result = FALSE;

    if (db_class_instanceof(db_primitive_o, type)) {
       if (_this->kind == db_primitive(type)->kind) { /* If kinds are equal, types are compatible */
           result = TRUE;
        } else if (_this->kind == DB_ENUM) {
    	   if (type == db_type(db_constant_o)) {
    		   result = TRUE;
    	   }
        } else if (_this->kind == DB_BITMASK) {
           switch(db_primitive(type)->kind) {
           case DB_INTEGER:
           case DB_UINTEGER:
               result = TRUE;
               break;
           default:
               break;
           }
        } else { /* Integer types are interchangable */
       		switch(_this->kind) {
   			case DB_BINARY:
   			case DB_UINTEGER:
   			case DB_INTEGER:
   				switch(db_primitive(type)->kind) {
   				case DB_BINARY:
   				case DB_UINTEGER:
   				case DB_INTEGER:
   					result = TRUE;
       				break;
       			default:
	       			break;
   				}
       			break;
   			default:
       			break;
       		}

       }
    }

    return result;
}

/* type::init -> binary::init */
db_int16 db_binary_init(db_binary object) {
    db_primitive(object)->kind = DB_BINARY;
    return db_primitive_init((db_primitive)object);
}

/* type::init -> boolean::init */
db_int16 db_boolean_init(db_boolean object) {
    db_primitive(object)->kind = DB_BOOLEAN;
    db_primitive(object)->width = DB_WIDTH_8;
    return db_primitive_init((db_primitive)object);
}

/* type::init -> ::char::init */
db_int16 db_character_init(db_character object) {
    db_primitive(object)->kind = DB_CHARACTER;
    return db_primitive_init((db_primitive)object);
}

/* type::init -> ::int::init */
db_int16 db_int_init(db_int object) {
    db_primitive(object)->kind = DB_INTEGER;
    return db_primitive_init((db_primitive)object);
}

/* type::init -> ::uint::init */
db_int16 db_uint_init(db_uint object) {
    db_primitive(object)->kind = DB_UINTEGER;
    return db_primitive_init((db_primitive)object);
}

/* type::init -> ::float::init */
db_int16 db_float_init(db_float object) {
    db_primitive(object)->kind = DB_FLOAT;
    return db_primitive_init((db_primitive)object);
}

/* type::init -> ::text::init */
db_int16 db_text_init(db_text object) {
	db_type(object)->hasResources = TRUE;
    db_primitive(object)->kind = DB_TEXT;
    db_primitive(object)->width = DB_WIDTH_WORD;
    return db_primitive_init((db_primitive)object);
}

/* type::init -> ::enum::init */
db_int16 db_enum_init(db_enum object) {
    db_primitive(object)->kind = DB_ENUM;
    db_primitive(object)->width = DB_WIDTH_32;
    db_set(&db_type(object)->defaultType, db_constant_o);
    return db_primitive_init((db_primitive)object);
}

/* type::init -> ::bitmask::init */
db_int16 db_bitmask_init(db_bitmask object) {
    db_primitive(object)->kind = DB_BITMASK;
    db_primitive(object)->width = DB_WIDTH_32;
    return db_primitive_init((db_primitive)object);
}

/* type::init -> ::bitmask::init */
db_int16 db_alias_init(db_alias object) {
    db_primitive(object)->kind = DB_ALIAS;
    db_primitive(object)->width = DB_WIDTH_WORD;
    return db_primitive_init((db_primitive)object);
}

/* type->init -> ::constant::init */
db_int16 db_constant_init(db_constant* object) {
	db_object parent;

	parent = db_parentof(object);

	/* Parent must be an enum */
	if (db_typeof(parent) == db_typedef(db_enum_o)) {
		db__enum_bindConstant(parent, object);
	} else if (db_typeof(parent) == db_typedef(db_bitmask_o)) {
	    db__bitmask_bindConstant(parent, object);
	} else {
		db_id id;
		db_error("::constant::init: parent of constant '%s' is not an enum.", db_fullname(object, id));
		goto error;
	}

	return 0;
error:
	return -1;
}

struct db_enum_findConstant_t {
    db_int32 value;
    db_constant* o;
};

static int db_enum_findConstant(void* o, void* udata) {
    struct db_enum_findConstant_t* userData;

    userData = udata;
    if (*(db_constant*)o == userData->value) {
        userData->o = o;
    }
    return userData->o == NULL;
}

/* enum::constant */
db_object db_enum_constant(db_enum _this, db_int32 value) {
    db_rbtree scope;
    struct db_enum_findConstant_t walkData;

    /* Get scope */
    scope = db_scopeof(_this);

    /* Walk scope */
    walkData.value = value;
    walkData.o = NULL;
    db_rbtreeWalk(scope, db_enum_findConstant, &walkData);

    return walkData.o;
}

/* enum::bindConstant */
db_int16 db__enum_bindConstant(db_enum _this, db_constant* c) {
	db_rbtree scope;

    if (db_checkState(db_type_o, DB_DEFINED)) {
        scope = db_scopeof(_this);
        *c = db_rbtreeSize(scope)-1;
    }
    _this->constants.buffer = db_realloc(_this->constants.buffer, (_this->constants.length+1) * sizeof(db_constant*));
    _this->constants.buffer[_this->constants.length] = c;
    _this->constants.length++;
    
    db_keep(c);

	return 0;
}

/* enum::construct */
db_int16 db_enum_construct(db_enum object) {
	db_uint32 i;

	/* Define constants */
	for(i=0; i<object->constants.length; i++) {
		db_define(object->constants.buffer[i]);
	}

	return db_primitive_construct(db_primitive(object));
}

/* enum::destruct */
void db_enum_destruct(db_enum object) {
	db_clear(db_collection(db_objectSeq_o), &object->constants);
	db_primitive_destruct(db_primitive(object));
}


/* bitmask::bindConstant */
db_int16 db__bitmask_bindConstant(db_bitmask _this, db_constant* c) {
    db_rbtree scope;

    if (db_checkState(db_type_o, DB_DEFINED)) {
        scope = db_scopeof(_this);
        *c = 0x1 << (db_rbtreeSize(scope)-1);
    }
    db_enum(_this)->constants.buffer = db_realloc(db_enum(_this)->constants.buffer, (db_enum(_this)->constants.length+1) * sizeof(db_constant*));
    db_enum(_this)->constants.buffer[db_enum(_this)->constants.length] = c;
    db_enum(_this)->constants.length++;
    
    db_keep(c);

    return 0;
}
