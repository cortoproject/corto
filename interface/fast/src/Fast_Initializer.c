/* Fast_Initializer.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "Fast_Initializer.h"
#include "Fast__meta.h"


/* $header() */
#include "Fast_Expression.h"
#include "Fast__api.h"

/*#define DB_INIT_DEBUG*/
#ifdef DB_INIT_DEBUG
static int indent;
#endif

Fast_Parser yparser(void);
void Fast_Parser_error(Fast_Parser _this, char* fmt, ...);
void Fast_Parser_warning(Fast_Parser _this, char* fmt, ...);

typedef struct Fast_Initializer_findMember_t {
	db_int32 lookForLocation;
	db_string lookForString;
	db_uint32 id;
	db_uint32 count;
	db_uint32 current;
	db_member m;
}Fast_Initializer_findMember_t;

/* Walk members, look it up */
db_int16 Fast_Initializer_findMember(db_serializer s, db_value* v, void* userData) {
	db_uint32 result;
	Fast_Initializer_findMember_t* data;

	result = 0;
	data = userData;

	switch(v->kind) {
	case DB_MEMBER:
		if (v->is.member.t->id == (db_uint32)-1) {
			result = db_serializeValue(s, v, userData);
		} else {
			if ((data->lookForLocation >= 0) && ((db_uint32)data->lookForLocation == data->count)) {
	            data->m = v->is.member.t;
	            data->id = data->count;
				goto found;
			} else if (data->lookForString && !strcmp(data->lookForString, db_nameof(v->is.member.t))) {
			    data->m = v->is.member.t;
			    data->id = data->count;
			    if (data->current >= data->count) {
					goto found;
				}
			}
			data->count++;
		}
		break;
	default:
		db_assert(0, "invalid valueKind for member-callback.");
		break;
	}

	return result;
found:
	return -1;
}

/* Create serializer */
struct db_serializer_s Fast_findMemberSerializer(void) {
	struct db_serializer_s s;
	db_serializerInit(&s);
	s.metaprogram[DB_MEMBER] = Fast_Initializer_findMember;
	s.access = DB_LOCAL | DB_PRIVATE | DB_READONLY;
	s.accessKind = DB_NOT;
	s.traceKind = DB_SERIALIZER_TRACE_NEVER;
	return s;
}

db_type Fast_Parser_initGetType(Fast_Initializer _this, db_member *m_out) {
	db_type t, result;

	result = NULL;

	if (m_out) {
		*m_out = NULL;
	}

	if (_this->fp > 0) {
	    t = _this->frames[_this->fp-1].type;
		if (_this->frames[_this->fp].isKey) {
			result = db_map(t)->keyType->real;
		} else {
			switch(t->kind) {
			case DB_COMPOSITE: {
				struct db_serializer_s s;
				Fast_Initializer_findMember_t walkData;
				s = Fast_findMemberSerializer();
				walkData.id = 0;
				walkData.count = 0;
				walkData.lookForLocation = _this->frames[_this->fp].location;
				walkData.lookForString = NULL;
				walkData.m = NULL;
				walkData.current = 0;
				db_metaWalk(&s, t, &walkData);
				if (walkData.m) {
					result = walkData.m->type->real;
					if (m_out) {
						*m_out = walkData.m;
					}
				} else {
					/* If m_out is not set this function is not used to determine the type
					 * for setting a value in an initializer. */
					if (m_out) {
						Fast_Parser_error(yparser(), "member out of range");
					}
				}
				break;
			}
			case DB_COLLECTION:
				result = db_collection(t)->elementType->real;
				break;
			default: {
				/* If value is a non-composite type it can only have one initializer value. If there are more
				 * values specified (thus location != 0) report an error. */
				if (!_this->frames[_this->fp].location) {
					result = t;
				} else {
					if (m_out) {
						db_id id;
						Fast_Parser_error(yparser(), "too many elements for non-composite\\collection type '%s'", db_fullname(t, id));
						result = NULL;
					}
				}
				break;
			}
			}
		}
	} else {
		if (_this->frames[0].location == 0) {
			result = _this->frames[0].type;
		} else {
			db_id id;
            if (_this->frames[0].type->reference) {
    			Fast_Parser_error(yparser(), "excess elements in initializer for reference type '%s' (location=%d)",
    					db_fullname(_this->frames[0].type, id), _this->frames[0].location);
            } else {
                Fast_Parser_error(yparser(), "excess elements in initializer for primitive type '%s' (location=%d)",
                            db_fullname(_this->frames[0].type, id), _this->frames[0].location);              
            }
		}
	}

	return result;
}


/* $end */

/* callback ::hyve::lang::class::construct(lang::object object) -> ::hyve::Fast::Initializer::construct(Initializer object) */
db_int16 Fast_Initializer_construct(Fast_Initializer object) {
/* $begin(::hyve::Fast::Initializer::construct) */
	db_uint32 variable;
	db_type t = Fast_Expression_getType(object->variables[0].object);
    
    if (!t) {
        Fast_Parser_error(yparser(), "parser error: invalid object in initializer"); abort();
        goto error;
    }

    /* Initialize first frame with type */
	for(variable=0; variable<object->variableCount; variable++) {
		db_set(&object->frames[variable].type, t);
        /* db_set(&_this->rvalueType, t); */
		object->frames[variable].location = 0;
	}
	object->fp = 0;

#ifdef DB_INIT_DEBUG
    {
        db_id id, id2;
        printf("%*s%d[%s %p]: construct (type=%s)\n", indent, " ", yparser()->line, db_fullname(db_typeof(object), id), object, db_fullname(t, id2));
        indent++;
    }
#endif
    
    /* If type of initializer is either a composite or a collection type, do an initial push */
    if (((t->kind == DB_COMPOSITE) || (t->kind == DB_COLLECTION))) {
        if (Fast_Initializer_push(object)) {
            goto error;
        }
    }
    
    Fast_Node(object)->kind = FAST_Initializer;
    Fast_Expression(object)->type = Fast_Variable(Fast_Object__create(t));
    
	return 0;
error:
    return -1;
/* $end */
}

/* ::hyve::Fast::Initializer::currentType() */
db_type Fast_Initializer_currentType(Fast_Initializer _this) {
/* $begin(::hyve::Fast::Initializer::currentType) */
    return Fast_Parser_initGetType(_this, NULL);
/* $end */
}

/* ::hyve::Fast::Initializer::define() */
db_int16 Fast_Initializer_define_v(Fast_Initializer _this) {
/* $begin(::hyve::Fast::Initializer::define) */
    DB_UNUSED(_this);
#ifdef DB_INIT_DEBUG
    {
        db_id id;
        indent--;
        printf("%*s%d[%s %p]: define\n",
               indent, " ", yparser()->line, db_fullname(db_typeof(_this), id), _this);
    }
#endif
	return 0;
/* $end */
}

/* ::hyve::Fast::Initializer::initFrame() */
db_uint16 Fast_Initializer_initFrame(Fast_Initializer _this) {
/* $begin(::hyve::Fast::Initializer::initFrame) */
    struct db_serializer_s s;
	db_type t;
	Fast_Initializer_findMember_t walkData;
    
	/* Lookup corresponding member for current value (if there is any) */
    if (_this->fp) {
        t = _this->frames[_this->fp-1].type;
        s = Fast_findMemberSerializer();
        walkData.id = 0;
        walkData.count = 0;
        walkData.lookForLocation = _this->frames[_this->fp].location;
        walkData.lookForString = NULL;
        walkData.m = NULL;
        walkData.current = _this->frames[_this->fp].location;
        if (t->kind == DB_COMPOSITE) {
            db_metaWalk(&s, t, &walkData);
        }
        if (walkData.m) {
            _this->frames[_this->fp].location = walkData.id;
            db_set(&_this->frames[_this->fp].member, walkData.m);
            db_set(&_this->frames[_this->fp].type, walkData.m->type->real);
            /*db_set(&yparser()->rvalueType, walkData.m->type->real);*/
        } else {
            db_set(&_this->frames[_this->fp].member, NULL);
            if (t->kind == DB_COLLECTION) {
                db_set(&_this->frames[_this->fp].type, db_collection(t)->elementType);
                /*db_set(&yparser()->rvalueType, db_collection(t)->elementType);*/
            } else {
                db_set(&_this->frames[_this->fp].type, NULL);
            }
        }
    }

    return 0;
/* $end */
}

/* ::hyve::Fast::Initializer::member(lang::string name) */
db_int32 Fast_Initializer_member_v(Fast_Initializer _this, db_string name) {
/* $begin(::hyve::Fast::Initializer::member) */
	struct db_serializer_s s;
	db_type t;
	Fast_Initializer_findMember_t walkData;

	t = _this->frames[_this->fp-1].type;
	s = Fast_findMemberSerializer();
    
	walkData.id = 0;
	walkData.count = 0;
	walkData.lookForLocation = -1;
	walkData.lookForString = name;
	walkData.m = NULL;
	walkData.current = _this->frames[_this->fp].location;
    if (t->kind == DB_COMPOSITE) {
        db_metaWalk(&s, t, &walkData);
    }
    if (walkData.m) {
        _this->frames[_this->fp].location = walkData.id;
        db_set(&_this->frames[_this->fp].member, walkData.m);
        db_set(&_this->frames[_this->fp].type, walkData.m->type->real);
        /*db_set(&yparser()->rvalueType, walkData.m->type->real);*/
    } else {
        db_id id;
        Fast_Parser_error(yparser(), "member '%s' invalid for type '%s'", name, db_fullname(t, id));
        db_set(&_this->frames[_this->fp].type, NULL);
        goto error;
    }

	return 0;
error:
	return -1;
/* $end */
}

/* ::hyve::Fast::Initializer::next() */
db_int16 Fast_Initializer_next_v(Fast_Initializer _this) {
/* $begin(::hyve::Fast::Initializer::next) */
    
    /* Increase location by one */
	_this->frames[_this->fp].location++;
    Fast_Initializer_initFrame(_this);
    
#ifdef DB_INIT_DEBUG
    {
        db_id id, id2;
        printf("%*s%d[%s %p]: next(fp=%d, location=%d, type=%s, member=%s)\n",
               indent, " ", yparser()->line, db_fullname(db_typeof(_this), id), _this, _this->fp, _this->frames[_this->fp].location,
               _this->frames[_this->fp].type?db_fullname(_this->frames[_this->fp].type, id2):NULL,
               _this->frames[_this->fp].member?db_nameof(_this->frames[_this->fp].member):NULL);
    }
#endif
    
	return 0;
/* $end */
}

/* ::hyve::Fast::Initializer::pop() */
db_int8 Fast_Initializer_pop_v(Fast_Initializer _this) {
/* $begin(::hyve::Fast::Initializer::pop) */

    if (_this->fp) {
        _this->fp--;
    
#ifdef DB_INIT_DEBUG
    {
        db_id id;
        indent--;
        printf("%*s%d[%s %p]: pop(fp=%d, location=%d)\n", indent, " ", yparser()->line, db_fullname(db_typeof(_this), id), _this, _this->fp, _this->frames[_this->fp].location);
    }
#endif
        Fast_Initializer_next(_this);
    }

	return 0;
/* $end */
}

/* ::hyve::Fast::Initializer::popKey() */
db_int16 Fast_Initializer_popKey_v(Fast_Initializer _this) {
/* $begin(::hyve::Fast::Initializer::popKey) */
    return Fast_Initializer_pop(_this);
/* $end */
}

/* ::hyve::Fast::Initializer::push() */
db_int16 Fast_Initializer_push_v(Fast_Initializer _this) {
/* $begin(::hyve::Fast::Initializer::push) */
    db_type t = Fast_Initializer_currentType(_this);

    if (!_this->fp || (_this->fp && !t->reference)) {
        _this->fp++;
        _this->frames[_this->fp].location = 0;
        db_set(&_this->frames[_this->fp].type, t);
        Fast_Initializer_initFrame(_this);
        
#ifdef DB_INIT_DEBUG
        {
            db_id id, id2;
            printf("%*s%d[%s %p]: push(fp=%d, location=%d, type=%s, member=%s)\n",
                   indent, " ", yparser()->line, db_fullname(db_typeof(_this), id), _this, _this->fp,
                   _this->frames[_this->fp].location, _this->frames[_this->fp].type?db_fullname(_this->frames[_this->fp].type, id2):NULL,
                   _this->frames[_this->fp].member?db_nameof(_this->frames[_this->fp].member):NULL);
            indent++;
        }
#endif
    } else {
        db_id id;
        Fast_Parser_error(yparser(), "unexpected initializer scope for value of referencetype '%s'", db_fullname(t, id));
        goto error;
    }
    
	return 0;
error:
    return -1;
/* $end */
}

/* ::hyve::Fast::Initializer::pushKey() */
db_int16 Fast_Initializer_pushKey_v(Fast_Initializer _this) {
/* $begin(::hyve::Fast::Initializer::pushKey) */
    _this->frames[_this->fp+1].isKey = TRUE;
    return Fast_Initializer_push(_this);
/* $end */
}

/* ::hyve::Fast::Initializer::type() */
db_type Fast_Initializer_type(Fast_Initializer _this) {
/* $begin(::hyve::Fast::Initializer::type) */
    return Fast_Expression_getType(_this->variables[0].object);
/* $end */
}

/* ::hyve::Fast::Initializer::value(Expression v) */
db_int16 Fast_Initializer_value_v(Fast_Initializer _this, Fast_Expression v) {
/* $begin(::hyve::Fast::Initializer::value) */
    DB_UNUSED(v);
    return Fast_Initializer_next(_this);
/* $end */
}

/* ::hyve::Fast::Initializer::valueKey(Expression key) */
db_int16 Fast_Initializer_valueKey_v(Fast_Initializer _this, Fast_Expression key) {
/* $begin(::hyve::Fast::Initializer::valueKey) */
    _this->frames[_this->fp].isKey = TRUE;
    return Fast_Initializer_value(_this, key);
/* $end */
}
