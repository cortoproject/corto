/* Fast_Initializer.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "Fast.h"
#include "Fast__meta.h"

/* $header() */
#include "Fast_Expression.h"
#include "Fast__api.h"

/*#define CX_INIT_DEBUG*/
#ifdef CX_INIT_DEBUG
static int indent;
#endif

Fast_Parser yparser(void);
void Fast_Parser_error(Fast_Parser _this, char* fmt, ...);
void Fast_Parser_warning(Fast_Parser _this, char* fmt, ...);

typedef struct Fast_Initializer_findMember_t {
    cx_int32 lookForLocation;
    cx_string lookForString;
    cx_uint32 id;
    cx_uint32 count;
    cx_uint32 current;
    cx_member m;
}Fast_Initializer_findMember_t;

/* Walk members, look it up */
cx_int16 Fast_Initializer_findMember(cx_serializer s, cx_value* v, void* userData) {
    cx_uint32 result;
    Fast_Initializer_findMember_t* data;

    result = 0;
    data = userData;

    switch(v->kind) {
    case CX_MEMBER:
        if (v->is.member.t->id == (cx_uint32)-1) {
            result = cx_serializeValue(s, v, userData);
        } else {
            if ((data->lookForLocation >= 0) && ((cx_uint32)data->lookForLocation == data->count)) {
                data->m = v->is.member.t;
                data->id = data->count;
                goto found;
            } else if (data->lookForString && !strcmp(data->lookForString, cx_nameof(v->is.member.t))) {
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
        cx_assert(0, "invalid valueKind for member-callback.");
        break;
    }

    return result;
found:
    return -1;
}

/* Create serializer */
struct cx_serializer_s Fast_findMemberSerializer(void) {
    struct cx_serializer_s s;
    cx_serializerInit(&s);
    s.metaprogram[CX_MEMBER] = Fast_Initializer_findMember;
    s.access = CX_LOCAL | CX_PRIVATE | CX_READONLY;
    s.accessKind = CX_NOT;
    s.traceKind = CX_SERIALIZER_TRACE_NEVER;
    return s;
}

cx_type Fast_Parser_initGetType(Fast_Initializer _this, cx_member *m_out) {
    cx_type t, result;

    result = NULL;

    if (m_out) {
        *m_out = NULL;
    }

    if (_this->fp > 0) {
        t = _this->frames[_this->fp-1].type;
        if (_this->frames[_this->fp].isKey) {
            result = cx_map(t)->keyType;
        } else {
            switch(t->kind) {
            case CX_COMPOSITE: {
                struct cx_serializer_s s;
                Fast_Initializer_findMember_t walkData;
                s = Fast_findMemberSerializer();
                walkData.id = 0;
                walkData.count = 0;
                walkData.lookForLocation = _this->frames[_this->fp].location;
                walkData.lookForString = NULL;
                walkData.m = NULL;
                walkData.current = 0;
                cx_metaWalk(&s, t, &walkData);
                if (walkData.m) {
                    result = walkData.m->type;
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
            case CX_COLLECTION:
                result = cx_collection(t)->elementType;
                break;
            default: {
                /* If value is a non-composite type it can only have one initializer value. If there are more
                 * values specified (thus location != 0) report an error. */
                if (!_this->frames[_this->fp].location) {
                    result = t;
                } else {
                    if (m_out) {
                        cx_id id;
                        Fast_Parser_error(yparser(), 
                            "too many elements for non-composite\\collection type '%s'", Fast_Parser_id(t, id));
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
            cx_id id;
            if (_this->frames[0].type->reference) {
                Fast_Parser_error(yparser(), "excess elements in initializer for reference type '%s' (location=%d)",
                        Fast_Parser_id(_this->frames[0].type, id), _this->frames[0].location);
            } else {
                Fast_Parser_error(yparser(), "excess elements in initializer for primitive type '%s' (location=%d)",
                            Fast_Parser_id(_this->frames[0].type, id), _this->frames[0].location);              
            }
        }
    }

    return result;
}


/* $end */

/* ::cortex::Fast::Initializer::construct() */
cx_int16 Fast_Initializer_construct(Fast_Initializer _this) {
/* $begin(::cortex::Fast::Initializer::construct) */
    cx_uint32 variable;
    cx_type t = Fast_Expression_getType(_this->variables[0].object);
    
    if (!t) {
        Fast_Parser_error(yparser(), "parser error: invalid object in initializer"); abort();
        goto error;
    }

    /* Initialize first frame with type */
    for(variable=0; variable<_this->variableCount; variable++) {
        cx_set(&_this->frames[variable].type, t);
        /* cx_set(&_this->rvalueType, t); */
        _this->frames[variable].location = 0;
    }
    _this->fp = 0;

#ifdef CX_INIT_DEBUG
    {
        cx_id id, id2;
        printf("%*s%d[%s %p]: construct (type=%s)\n", 
            indent, " ", yparser()->line, Fast_Parser_id(cx_typeof(_this), id), _this, Fast_Parser_id(t, id2));
        indent++;
    }
#endif
    
    /* If type of initializer is either a composite or a collection type, do an initial push */
    if ((((t->kind == CX_COMPOSITE) && (cx_interface(t)->kind != CX_DELEGATE)) || (t->kind == CX_COLLECTION))) {
        if (Fast_Initializer_push(_this)) {
            goto error;
        }
    }
    
    Fast_Node(_this)->kind = Fast_InitializerExpr;
    Fast_Expression(_this)->type = Fast_Variable(Fast_Object__create(t));
    
    return 0;
error:
    return -1;
/* $end */
}

/* ::cortex::Fast::Initializer::currentType() */
cx_type Fast_Initializer_currentType(Fast_Initializer _this) {
/* $begin(::cortex::Fast::Initializer::currentType) */
    return Fast_Parser_initGetType(_this, NULL);
/* $end */
}

/* ::cortex::Fast::Initializer::define() */
cx_int16 Fast_Initializer_define_v(Fast_Initializer _this) {
/* $begin(::cortex::Fast::Initializer::define) */
    CX_UNUSED(_this);
#ifdef CX_INIT_DEBUG
    {
        cx_id id;
        indent--;
        printf("%*s%d[%s %p]: define\n",
               indent, " ", yparser()->line, Fast_Parser_id(cx_typeof(_this), id), _this);
    }
#endif
    return 0;
/* $end */
}

/* ::cortex::Fast::Initializer::initFrame() */
cx_uint16 Fast_Initializer_initFrame(Fast_Initializer _this) {
/* $begin(::cortex::Fast::Initializer::initFrame) */
    struct cx_serializer_s s;
    cx_type t;
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
        if (t->kind == CX_COMPOSITE) {
            cx_metaWalk(&s, t, &walkData);
        }
        if (walkData.m) {
            _this->frames[_this->fp].location = walkData.id;
            cx_set(&_this->frames[_this->fp].member, walkData.m);
            cx_set(&_this->frames[_this->fp].type, walkData.m->type);
            /*cx_set(&yparser()->rvalueType, walkData.m->type);*/
        } else {
            cx_set(&_this->frames[_this->fp].member, NULL);
            if (t->kind == CX_COLLECTION) {
                cx_set(&_this->frames[_this->fp].type, cx_collection(t)->elementType);
                /*cx_set(&yparser()->rvalueType, cx_collection(t)->elementType);*/
            } else {
                cx_set(&_this->frames[_this->fp].type, NULL);
            }
        }
    }

    return 0;
/* $end */
}

/* ::cortex::Fast::Initializer::member(string name) */
cx_int32 Fast_Initializer_member_v(Fast_Initializer _this, cx_string name) {
/* $begin(::cortex::Fast::Initializer::member) */
    struct cx_serializer_s s;
    cx_type t;
    Fast_Initializer_findMember_t walkData;

    if (!_this->fp) {
        Fast_Parser_error(yparser(), "unexpected member '%s' in initializer", name);
        goto error;
    }

    t = _this->frames[_this->fp-1].type;
    s = Fast_findMemberSerializer();
    
    walkData.id = 0;
    walkData.count = 0;
    walkData.lookForLocation = -1;
    walkData.lookForString = name;
    walkData.m = NULL;
    walkData.current = _this->frames[_this->fp].location;
    if (t->kind == CX_COMPOSITE) {
        cx_metaWalk(&s, t, &walkData);
    }
    if (walkData.m) {
        _this->frames[_this->fp].location = walkData.id;
        cx_set(&_this->frames[_this->fp].member, walkData.m);
        cx_set(&_this->frames[_this->fp].type, walkData.m->type);
        /*cx_set(&yparser()->rvalueType, walkData.m->type);*/
    } else {
        cx_id id;
        Fast_Parser_error(yparser(), "member '%s' invalid for type '%s'", name, Fast_Parser_id(t, id));
        cx_set(&_this->frames[_this->fp].type, NULL);
        goto error;
    }

    return 0;
error:
    return -1;
/* $end */
}

/* ::cortex::Fast::Initializer::next() */
cx_int16 Fast_Initializer_next_v(Fast_Initializer _this) {
/* $begin(::cortex::Fast::Initializer::next) */
    
    /* Increase location by one */
    _this->frames[_this->fp].location++;
    Fast_Initializer_initFrame(_this);
    
#ifdef CX_INIT_DEBUG
    {
        cx_id id, id2;
        printf("%*s%d[%s %p]: next(fp=%d, location=%d, type=%s, member=%s)\n",
               indent, " ", yparser()->line, Fast_Parser_id(cx_typeof(_this), id), _this, _this->fp, 
               _this->frames[_this->fp].location,
               _this->frames[_this->fp].type?Fast_Parser_id(_this->frames[_this->fp].type, id2):NULL,
               _this->frames[_this->fp].member?cx_nameof(_this->frames[_this->fp].member):NULL);
    }
#endif
    
    return 0;
/* $end */
}

/* ::cortex::Fast::Initializer::pop() */
cx_int8 Fast_Initializer_pop_v(Fast_Initializer _this) {
/* $begin(::cortex::Fast::Initializer::pop) */

    if (_this->fp) {
        _this->fp--;
    
#ifdef CX_INIT_DEBUG
    {
        cx_id id;
        indent--;
        printf("%*s%d[%s %p]: pop(fp=%d, location=%d)\n", 
            indent, " ", yparser()->line, 
            Fast_Parser_id(cx_typeof(_this), id), _this, _this->fp, _this->frames[_this->fp].location);
    }
#endif
        Fast_Initializer_next(_this);
    }

    return 0;
/* $end */
}

/* ::cortex::Fast::Initializer::popKey() */
cx_int16 Fast_Initializer_popKey_v(Fast_Initializer _this) {
/* $begin(::cortex::Fast::Initializer::popKey) */
    return Fast_Initializer_pop(_this);
/* $end */
}

/* ::cortex::Fast::Initializer::push() */
cx_int16 Fast_Initializer_push_v(Fast_Initializer _this) {
/* $begin(::cortex::Fast::Initializer::push) */
    cx_type t = Fast_Initializer_currentType(_this);

    if (!_this->fp || (_this->fp && !t->reference)) {
        _this->fp++;
        _this->frames[_this->fp].location = 0;
        cx_set(&_this->frames[_this->fp].type, t);
        Fast_Initializer_initFrame(_this);
        
#ifdef CX_INIT_DEBUG
        {
            cx_id id, id2;
            printf("%*s%d[%s %p]: push(fp=%d, location=%d, type=%s, member=%s)\n",
                   indent, " ", yparser()->line, Fast_Parser_id(cx_typeof(_this), id), _this, _this->fp,
                   _this->frames[_this->fp].location, 
                   _this->frames[_this->fp].type ? Fast_Parser_id(_this->frames[_this->fp].type, id2) : NULL,
                   _this->frames[_this->fp].member?cx_nameof(_this->frames[_this->fp].member):NULL);
            indent++;
        }
#endif
    } else {
        cx_id id;
        Fast_Parser_error(yparser(), "unexpected initializer scope for value of reference type '%s'", Fast_Parser_id(t, id));
        goto error;
    }
    
    return 0;
error:
    return -1;
/* $end */
}

/* ::cortex::Fast::Initializer::pushKey() */
cx_int16 Fast_Initializer_pushKey_v(Fast_Initializer _this) {
/* $begin(::cortex::Fast::Initializer::pushKey) */
    _this->frames[_this->fp+1].isKey = TRUE;
    return Fast_Initializer_push(_this);
/* $end */
}

/* ::cortex::Fast::Initializer::type() */
cx_type Fast_Initializer_type(Fast_Initializer _this) {
/* $begin(::cortex::Fast::Initializer::type) */
    return Fast_Expression_getType(_this->variables[0].object);
/* $end */
}

/* ::cortex::Fast::Initializer::value(Expression v) */
cx_int16 Fast_Initializer_value_v(Fast_Initializer _this, Fast_Expression v) {
/* $begin(::cortex::Fast::Initializer::value) */
    CX_UNUSED(v);
    return Fast_Initializer_next(_this);
/* $end */
}

/* ::cortex::Fast::Initializer::valueKey(Expression key) */
cx_int16 Fast_Initializer_valueKey_v(Fast_Initializer _this, Fast_Expression key) {
/* $begin(::cortex::Fast::Initializer::valueKey) */
    _this->frames[_this->fp].isKey = TRUE;
    return Fast_Initializer_value(_this, key);
/* $end */
}
