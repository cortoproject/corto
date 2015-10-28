/* $CORTO_GENERATED
 *
 * ast_Initializer.c
 *
 * Code written between the begin and end tags will be preserved when the
 * file is regenerated.
 */

#include "ast.h"

/* $header() */
#include "ast__private.h"

/*#define CORTO_INIT_DEBUG*/
#ifdef CORTO_INIT_DEBUG
static int indent;
#endif

typedef struct ast_Initializer_findMember_t {
    corto_int32 lookForLocation;
    corto_string lookForString;
    corto_uint32 id;
    corto_uint32 count;
    corto_uint32 current;
    corto_member m;
}ast_Initializer_findMember_t;

/* Walk members, look it up */
corto_int16 ast_Initializer_findMember(corto_serializer s, corto_value* v, void* userData) {
    corto_uint32 result;
    ast_Initializer_findMember_t* data;

    result = 0;
    data = userData;

    switch(v->kind) {
    case CORTO_MEMBER:
        if (v->is.member.t->id == (corto_uint32)-1) {
            result = corto_serializeValue(s, v, userData);
        } else {
            if ((data->lookForLocation >= 0) && ((corto_uint32)data->lookForLocation == data->count)) {
                data->m = v->is.member.t;
                data->id = data->count;
                goto found;
            } else if (data->lookForString && !strcmp(data->lookForString, corto_nameof(v->is.member.t))) {
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
        corto_assert(0, "invalid valueKind for member-callback.");
        break;
    }

    return result;
found:
    return -1;
}

/* Create serializer */
struct corto_serializer_s ast_findMemberSerializer(corto_bool findHidden) {
    struct corto_serializer_s s;
    corto_serializerInit(&s);
    s.metaprogram[CORTO_MEMBER] = ast_Initializer_findMember;
    s.access = CORTO_LOCAL | CORTO_PRIVATE | CORTO_READONLY;
    if (!findHidden) {
        s.access |= CORTO_HIDDEN;
    }
    s.accessKind = CORTO_NOT;
    s.traceKind = CORTO_SERIALIZER_TRACE_NEVER;
    s.aliasAction = CORTO_SERIALIZER_ALIAS_FOLLOW;
    return s;
}

corto_type ast_Parser_initGetType(ast_Initializer this, corto_member *m_out) {
    corto_type t, result;

    result = NULL;

    if (m_out) {
        *m_out = NULL;
    }

    if (this->fp > 0) {
        t = this->frames[this->fp-1].type;
        if (this->frames[this->fp].isKey) {
            result = corto_map(t)->keyType;
        } else {
            switch(t->kind) {
            case CORTO_COMPOSITE: {
                struct corto_serializer_s s;
                ast_Initializer_findMember_t walkData;

                if (!this->frames[this->fp].member) {
                    s = ast_findMemberSerializer(FALSE);
                    walkData.id = 0;
                    walkData.count = 0;
                    walkData.lookForLocation = this->frames[this->fp].location;
                    walkData.lookForString = NULL;
                    walkData.m = NULL;
                    walkData.current = 0;
                    corto_metaWalk(&s, t, &walkData);
                } else {
                    walkData.m = this->frames[this->fp].member;
                }
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
            case CORTO_COLLECTION:
                result = corto_collection(t)->elementType;
                break;
            default: {
                /* If value is a non-composite type it can only have one initializer value. If there are more
                 * values specified (thus location != 0) report an error. */
                if (!this->frames[this->fp].location) {
                    result = t;
                } else {
                    if (m_out) {
                        corto_id id;
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
            corto_id id;
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

corto_int16 _ast_Initializer_construct(ast_Initializer this) {
/* $begin(::corto::ast::Initializer::construct) */
    corto_uint32 variable;
    corto_type t = ast_Expression_getType(this->variables[0].object);
    
    if (!t) {
        ast_Parser_error(yparser(), "parser error: invalid object in initializer"); abort();
        goto error;
    }

    /* Initialize first frame with type */
    for(variable=0; variable<this->variableCount; variable++) {
        corto_setref(&this->frames[variable].type, t);
        /* corto_setref(&this->rvalueType, t); */
        this->frames[variable].location = 0;
    }
    this->fp = 0;

#ifdef CORTO_INIT_DEBUG
    {
        corto_id id, id2;
        printf("%*s%d[%s %p]: construct (type=%s)\n", 
            indent, " ", yparser()->line, ast_Parser_id(corto_typeof(this), id), this, ast_Parser_id(t, id2));
        indent++;
    }
#endif
    
    /* If type of initializer is either a composite or a collection type, do an initial push */
    if ((((t->kind == CORTO_COMPOSITE) && (corto_interface(t)->kind != CORTO_DELEGATE)) || (t->kind == CORTO_COLLECTION))) {
        if (ast_Initializer_push(this)) {
            goto error;
        }
    }
    
    ast_Node(this)->kind = Ast_InitializerExpr;
    corto_setref(&ast_Expression(this)->type, t);
    
    return 0;
error:
    return -1;
/* $end */
}

corto_type _ast_Initializer_currentType(ast_Initializer this) {
/* $begin(::corto::ast::Initializer::currentType) */
    return ast_Parser_initGetType(this, NULL);
/* $end */
}

corto_int16 _ast_Initializer_define_v(ast_Initializer this) {
/* $begin(::corto::ast::Initializer::define) */
    CORTO_UNUSED(this);
#ifdef CORTO_INIT_DEBUG
    {
        corto_id id;
        indent--;
        printf("%*s%d[%s %p]: define\n",
               indent, " ", yparser()->line, ast_Parser_id(corto_typeof(this), id), this);
    }
#endif
    return 0;
/* $end */
}

corto_uint16 _ast_Initializer_initFrame(ast_Initializer this) {
/* $begin(::corto::ast::Initializer::initFrame) */
    struct corto_serializer_s s;
    corto_type t;
    ast_Initializer_findMember_t walkData;
    
    /* Lookup corresponding member for current value (if there is any) */
    if (this->fp) {
        t = this->frames[this->fp-1].type;
        s = ast_findMemberSerializer(FALSE);
        walkData.id = 0;
        walkData.count = 0;
        walkData.lookForLocation = this->frames[this->fp].location;
        walkData.lookForString = NULL;
        walkData.m = NULL;
        walkData.current = this->frames[this->fp].location;
        if (t->kind == CORTO_COMPOSITE) {
            corto_metaWalk(&s, t, &walkData);
        }
        if (walkData.m) {
            this->frames[this->fp].location = walkData.id;
            corto_setref(&this->frames[this->fp].member, walkData.m);
            corto_setref(&this->frames[this->fp].type, walkData.m->type);
            /*corto_setref(&yparser()->rvalueType, walkData.m->type);*/
        } else {
            corto_setref(&this->frames[this->fp].member, NULL);
            if (t->kind == CORTO_COLLECTION) {
                corto_setref(&this->frames[this->fp].type, corto_collection(t)->elementType);
                /*corto_setref(&yparser()->rvalueType, corto_collection(t)->elementType);*/
            } else {
                corto_setref(&this->frames[this->fp].type, NULL);
            }
        }
    }

    return 0;
/* $end */
}

corto_int32 _ast_Initializer_member_v(ast_Initializer this, corto_string name) {
/* $begin(::corto::ast::Initializer::member) */
    struct corto_serializer_s s;
    corto_type t;
    ast_Initializer_findMember_t walkData;

    if (!this->fp) {
        ast_Parser_error(yparser(), "unexpected member '%s' in initializer", name);
        goto error;
    }

    t = this->frames[this->fp-1].type;
    s = ast_findMemberSerializer(TRUE);
    
    walkData.id = 0;
    walkData.count = 0;
    walkData.lookForLocation = -1;
    walkData.lookForString = name;
    walkData.m = NULL;
    walkData.current = this->frames[this->fp].location;
    if (t->kind == CORTO_COMPOSITE) {
        corto_metaWalk(&s, t, &walkData);
    }
    if (walkData.m) {
        /* this->frames[this->fp].location = walkData.id; */
        corto_setref(&this->frames[this->fp].member, walkData.m);
        corto_setref(&this->frames[this->fp].type, walkData.m->type);
        /*corto_setref(&yparser()->rvalueType, walkData.m->type);*/
    } else {
        corto_id id;
        ast_Parser_error(yparser(), "member '%s' invalid for type '%s'", name, ast_Parser_id(t, id));
        corto_setref(&this->frames[this->fp].type, NULL);
        goto error;
    }

    return 0;
error:
    return -1;
/* $end */
}

corto_int16 _ast_Initializer_next_v(ast_Initializer this) {
/* $begin(::corto::ast::Initializer::next) */
    
    /* Increase location by one */
    this->frames[this->fp].location++;
    ast_Initializer_initFrame(this);
    
#ifdef CORTO_INIT_DEBUG
    {
        corto_id id, id2;
        printf("%*s%d[%s %p]: next(fp=%d, location=%d, type=%s, member=%s)\n",
               indent, " ", yparser()->line, ast_Parser_id(corto_typeof(this), id), this, this->fp, 
               this->frames[this->fp].location,
               this->frames[this->fp].type?ast_Parser_id(this->frames[this->fp].type, id2):NULL,
               this->frames[this->fp].member?corto_nameof(this->frames[this->fp].member):NULL);
    }
#endif
    
    return 0;
/* $end */
}

corto_int8 _ast_Initializer_pop_v(ast_Initializer this) {
/* $begin(::corto::ast::Initializer::pop) */

    if (this->fp) {
        this->fp--;
    
#ifdef CORTO_INIT_DEBUG
    {
        corto_id id;
        indent--;
        printf("%*s%d[%s %p]: pop(fp=%d, location=%d)\n", 
            indent, " ", yparser()->line, 
            ast_Parser_id(corto_typeof(this), id), this, this->fp, this->frames[this->fp].location);
    }
#endif
        ast_Initializer_next(this);
    }

    return 0;
/* $end */
}

corto_int16 _ast_Initializer_popKey_v(ast_Initializer this) {
/* $begin(::corto::ast::Initializer::popKey) */
    return ast_Initializer_pop(this);
/* $end */
}

corto_int16 _ast_Initializer_push_v(ast_Initializer this) {
/* $begin(::corto::ast::Initializer::push) */
    corto_type t = ast_Initializer_currentType(this);

    if (!this->fp || (this->fp && !t->reference)) {
        this->fp++;
        this->frames[this->fp].location = 0;
        corto_setref(&this->frames[this->fp].type, t);
        ast_Initializer_initFrame(this);
        
#ifdef CORTO_INIT_DEBUG
        {
            corto_id id, id2;
            printf("%*s%d[%s %p]: push(fp=%d, location=%d, type=%s, member=%s)\n",
                   indent, " ", yparser()->line, ast_Parser_id(corto_typeof(this), id), this, this->fp,
                   this->frames[this->fp].location, 
                   this->frames[this->fp].type ? ast_Parser_id(this->frames[this->fp].type, id2) : NULL,
                   this->frames[this->fp].member?corto_nameof(this->frames[this->fp].member):NULL);
            indent++;
        }
#endif
    } else {
        corto_id id;
        ast_Parser_error(yparser(), "unexpected initializer scope for value of reference type '%s'", ast_Parser_id(t, id));
        goto error;
    }
    
    return 0;
error:
    return -1;
/* $end */
}

corto_int16 _ast_Initializer_pushKey_v(ast_Initializer this) {
/* $begin(::corto::ast::Initializer::pushKey) */
    this->frames[this->fp+1].isKey = TRUE;
    return ast_Initializer_push(this);
/* $end */
}

corto_type _ast_Initializer_type(ast_Initializer this) {
/* $begin(::corto::ast::Initializer::type) */
    return ast_Expression_getType(this->variables[0].object);
/* $end */
}

corto_int16 _ast_Initializer_value_v(ast_Initializer this, ast_Expression v) {
/* $begin(::corto::ast::Initializer::value) */
    CORTO_UNUSED(v);
    return ast_Initializer_next(this);
/* $end */
}

corto_int16 _ast_Initializer_valueKey_v(ast_Initializer this, ast_Expression key) {
/* $begin(::corto::ast::Initializer::valueKey) */
    this->frames[this->fp].isKey = TRUE;
    return ast_Initializer_value(this, key);
/* $end */
}
