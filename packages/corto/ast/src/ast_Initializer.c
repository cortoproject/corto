/* ast_Initializer.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#define corto_ast_LIB
#include "ast.h"

/* $header() */
#include "ast__private.h"

/*#define CX_INIT_DEBUG*/
#ifdef CX_INIT_DEBUG
static int indent;
#endif

typedef struct ast_Initializer_findMember_t {
    cx_int32 lookForLocation;
    cx_string lookForString;
    cx_uint32 id;
    cx_uint32 count;
    cx_uint32 current;
    cx_member m;
}ast_Initializer_findMember_t;

/* Walk members, look it up */
cx_int16 ast_Initializer_findMember(cx_serializer s, cx_value* v, void* userData) {
    cx_uint32 result;
    ast_Initializer_findMember_t* data;

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
struct cx_serializer_s ast_findMemberSerializer(void) {
    struct cx_serializer_s s;
    cx_serializerInit(&s);
    s.metaprogram[CX_MEMBER] = ast_Initializer_findMember;
    s.access = CX_LOCAL | CX_PRIVATE | CX_READONLY;
    s.accessKind = CX_NOT;
    s.traceKind = CX_SERIALIZER_TRACE_NEVER;
    return s;
}

cx_type ast_Parser_initGetType(ast_Initializer this, cx_member *m_out) {
    cx_type t, result;

    result = NULL;

    if (m_out) {
        *m_out = NULL;
    }

    if (this->fp > 0) {
        t = this->frames[this->fp-1].type;
        if (this->frames[this->fp].isKey) {
            result = cx_map(t)->keyType;
        } else {
            switch(t->kind) {
            case CX_COMPOSITE: {
                struct cx_serializer_s s;
                ast_Initializer_findMember_t walkData;
                s = ast_findMemberSerializer();
                walkData.id = 0;
                walkData.count = 0;
                walkData.lookForLocation = this->frames[this->fp].location;
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
                        ast_Parser_error(yparser(), "member out of range");
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
                if (!this->frames[this->fp].location) {
                    result = t;
                } else {
                    if (m_out) {
                        cx_id id;
                        ast_Parser_error(yparser(), 
                            "too many elements for non-composite\\collection type '%s'", ast_Parser_id(t, id));
                        result = NULL;
                    }
                }
                break;
            }
            }
        }
    } else {
        if (this->frames[0].location == 0) {
            result = this->frames[0].type;
        } else {
            cx_id id;
            if (this->frames[0].type->reference) {
                ast_Parser_error(yparser(), "excess elements in initializer for reference type '%s' (location=%d)",
                        ast_Parser_id(this->frames[0].type, id), this->frames[0].location);
            } else {
                ast_Parser_error(yparser(), "excess elements in initializer for primitive type '%s' (location=%d)",
                            ast_Parser_id(this->frames[0].type, id), this->frames[0].location);              
            }
        }
    }

    return result;
}


/* $end */

/* ::corto::ast::Initializer::construct() */
cx_int16 _ast_Initializer_construct(ast_Initializer this) {
/* $begin(::corto::ast::Initializer::construct) */
    cx_uint32 variable;
    cx_type t = ast_Expression_getType(this->variables[0].object);
    
    if (!t) {
        ast_Parser_error(yparser(), "parser error: invalid object in initializer"); abort();
        goto error;
    }

    /* Initialize first frame with type */
    for(variable=0; variable<this->variableCount; variable++) {
        cx_setref(&this->frames[variable].type, t);
        /* cx_setref(&this->rvalueType, t); */
        this->frames[variable].location = 0;
    }
    this->fp = 0;

#ifdef CX_INIT_DEBUG
    {
        cx_id id, id2;
        printf("%*s%d[%s %p]: construct (type=%s)\n", 
            indent, " ", yparser()->line, ast_Parser_id(cx_typeof(this), id), this, ast_Parser_id(t, id2));
        indent++;
    }
#endif
    
    /* If type of initializer is either a composite or a collection type, do an initial push */
    if ((((t->kind == CX_COMPOSITE) && (cx_interface(t)->kind != CX_DELEGATE)) || (t->kind == CX_COLLECTION))) {
        if (ast_Initializer_push(this)) {
            goto error;
        }
    }
    
    ast_Node(this)->kind = Ast_InitializerExpr;
    cx_setref(&ast_Expression(this)->type, t);
    
    return 0;
error:
    return -1;
/* $end */
}

/* ::corto::ast::Initializer::currentType() */
cx_type _ast_Initializer_currentType(ast_Initializer this) {
/* $begin(::corto::ast::Initializer::currentType) */
    return ast_Parser_initGetType(this, NULL);
/* $end */
}

/* ::corto::ast::Initializer::define() */
cx_int16 _ast_Initializer_define_v(ast_Initializer this) {
/* $begin(::corto::ast::Initializer::define) */
    CX_UNUSED(this);
#ifdef CX_INIT_DEBUG
    {
        cx_id id;
        indent--;
        printf("%*s%d[%s %p]: define\n",
               indent, " ", yparser()->line, ast_Parser_id(cx_typeof(this), id), this);
    }
#endif
    return 0;
/* $end */
}

/* ::corto::ast::Initializer::initFrame() */
cx_uint16 _ast_Initializer_initFrame(ast_Initializer this) {
/* $begin(::corto::ast::Initializer::initFrame) */
    struct cx_serializer_s s;
    cx_type t;
    ast_Initializer_findMember_t walkData;
    
    /* Lookup corresponding member for current value (if there is any) */
    if (this->fp) {
        t = this->frames[this->fp-1].type;
        s = ast_findMemberSerializer();
        walkData.id = 0;
        walkData.count = 0;
        walkData.lookForLocation = this->frames[this->fp].location;
        walkData.lookForString = NULL;
        walkData.m = NULL;
        walkData.current = this->frames[this->fp].location;
        if (t->kind == CX_COMPOSITE) {
            cx_metaWalk(&s, t, &walkData);
        }
        if (walkData.m) {
            this->frames[this->fp].location = walkData.id;
            cx_setref(&this->frames[this->fp].member, walkData.m);
            cx_setref(&this->frames[this->fp].type, walkData.m->type);
            /*cx_setref(&yparser()->rvalueType, walkData.m->type);*/
        } else {
            cx_setref(&this->frames[this->fp].member, NULL);
            if (t->kind == CX_COLLECTION) {
                cx_setref(&this->frames[this->fp].type, cx_collection(t)->elementType);
                /*cx_setref(&yparser()->rvalueType, cx_collection(t)->elementType);*/
            } else {
                cx_setref(&this->frames[this->fp].type, NULL);
            }
        }
    }

    return 0;
/* $end */
}

/* ::corto::ast::Initializer::member(string name) */
cx_int32 _ast_Initializer_member_v(ast_Initializer this, cx_string name) {
/* $begin(::corto::ast::Initializer::member) */
    struct cx_serializer_s s;
    cx_type t;
    ast_Initializer_findMember_t walkData;

    if (!this->fp) {
        ast_Parser_error(yparser(), "unexpected member '%s' in initializer", name);
        goto error;
    }

    t = this->frames[this->fp-1].type;
    s = ast_findMemberSerializer();
    
    walkData.id = 0;
    walkData.count = 0;
    walkData.lookForLocation = -1;
    walkData.lookForString = name;
    walkData.m = NULL;
    walkData.current = this->frames[this->fp].location;
    if (t->kind == CX_COMPOSITE) {
        cx_metaWalk(&s, t, &walkData);
    }
    if (walkData.m) {
        this->frames[this->fp].location = walkData.id;
        cx_setref(&this->frames[this->fp].member, walkData.m);
        cx_setref(&this->frames[this->fp].type, walkData.m->type);
        /*cx_setref(&yparser()->rvalueType, walkData.m->type);*/
    } else {
        cx_id id;
        ast_Parser_error(yparser(), "member '%s' invalid for type '%s'", name, ast_Parser_id(t, id));
        cx_setref(&this->frames[this->fp].type, NULL);
        goto error;
    }

    return 0;
error:
    return -1;
/* $end */
}

/* ::corto::ast::Initializer::next() */
cx_int16 _ast_Initializer_next_v(ast_Initializer this) {
/* $begin(::corto::ast::Initializer::next) */
    
    /* Increase location by one */
    this->frames[this->fp].location++;
    ast_Initializer_initFrame(this);
    
#ifdef CX_INIT_DEBUG
    {
        cx_id id, id2;
        printf("%*s%d[%s %p]: next(fp=%d, location=%d, type=%s, member=%s)\n",
               indent, " ", yparser()->line, ast_Parser_id(cx_typeof(this), id), this, this->fp, 
               this->frames[this->fp].location,
               this->frames[this->fp].type?ast_Parser_id(this->frames[this->fp].type, id2):NULL,
               this->frames[this->fp].member?cx_nameof(this->frames[this->fp].member):NULL);
    }
#endif
    
    return 0;
/* $end */
}

/* ::corto::ast::Initializer::pop() */
cx_int8 _ast_Initializer_pop_v(ast_Initializer this) {
/* $begin(::corto::ast::Initializer::pop) */

    if (this->fp) {
        this->fp--;
    
#ifdef CX_INIT_DEBUG
    {
        cx_id id;
        indent--;
        printf("%*s%d[%s %p]: pop(fp=%d, location=%d)\n", 
            indent, " ", yparser()->line, 
            ast_Parser_id(cx_typeof(this), id), this, this->fp, this->frames[this->fp].location);
    }
#endif
        ast_Initializer_next(this);
    }

    return 0;
/* $end */
}

/* ::corto::ast::Initializer::popKey() */
cx_int16 _ast_Initializer_popKey_v(ast_Initializer this) {
/* $begin(::corto::ast::Initializer::popKey) */
    return ast_Initializer_pop(this);
/* $end */
}

/* ::corto::ast::Initializer::push() */
cx_int16 _ast_Initializer_push_v(ast_Initializer this) {
/* $begin(::corto::ast::Initializer::push) */
    cx_type t = ast_Initializer_currentType(this);

    if (!this->fp || (this->fp && !t->reference)) {
        this->fp++;
        this->frames[this->fp].location = 0;
        cx_setref(&this->frames[this->fp].type, t);
        ast_Initializer_initFrame(this);
        
#ifdef CX_INIT_DEBUG
        {
            cx_id id, id2;
            printf("%*s%d[%s %p]: push(fp=%d, location=%d, type=%s, member=%s)\n",
                   indent, " ", yparser()->line, ast_Parser_id(cx_typeof(this), id), this, this->fp,
                   this->frames[this->fp].location, 
                   this->frames[this->fp].type ? ast_Parser_id(this->frames[this->fp].type, id2) : NULL,
                   this->frames[this->fp].member?cx_nameof(this->frames[this->fp].member):NULL);
            indent++;
        }
#endif
    } else {
        cx_id id;
        ast_Parser_error(yparser(), "unexpected initializer scope for value of reference type '%s'", ast_Parser_id(t, id));
        goto error;
    }
    
    return 0;
error:
    return -1;
/* $end */
}

/* ::corto::ast::Initializer::pushKey() */
cx_int16 _ast_Initializer_pushKey_v(ast_Initializer this) {
/* $begin(::corto::ast::Initializer::pushKey) */
    this->frames[this->fp+1].isKey = TRUE;
    return ast_Initializer_push(this);
/* $end */
}

/* ::corto::ast::Initializer::type() */
cx_type _ast_Initializer_type(ast_Initializer this) {
/* $begin(::corto::ast::Initializer::type) */
    return ast_Expression_getType(this->variables[0].object);
/* $end */
}

/* ::corto::ast::Initializer::value(Expression v) */
cx_int16 _ast_Initializer_value_v(ast_Initializer this, ast_Expression v) {
/* $begin(::corto::ast::Initializer::value) */
    CX_UNUSED(v);
    return ast_Initializer_next(this);
/* $end */
}

/* ::corto::ast::Initializer::valueKey(Expression key) */
cx_int16 _ast_Initializer_valueKey_v(ast_Initializer this, ast_Expression key) {
/* $begin(::corto::ast::Initializer::valueKey) */
    this->frames[this->fp].isKey = TRUE;
    return ast_Initializer_value(this, key);
/* $end */
}
