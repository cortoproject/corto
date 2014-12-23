/* db_function.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "db.h"
#include "db__meta.h"

/* callback ::hyve::lang::procedure::bind(lang::object object) -> ::hyve::lang::function::bind(lang::function object) */
db_int16 db_function_bind(db_function object) {
/* $begin(::hyve::lang::function::bind) */
	/* Count the size based on the parameters and store parameters in slots */
	if (!object->size) {
	    db_uint32 i;
	    for(i=0; i<object->parameters.length; i++) {
	    	db_type paramType = object->parameters.buffer[i].type->real;
	    	switch(paramType->kind) {
	    	case DB_ANY:
	    		object->size += sizeof(db_any);
	    		break;
	    	case DB_PRIMITIVE:
		    	object->size += db_type_sizeof(paramType);
	    		break;
	    	default:
	    		object->size += sizeof(void*);
	    		break;
	    	}
	    }

	    /* Add size of this-pointer - this must be moved to impl of methods, delegates and callbacks. */
		if (!(db_typeof(object) == db_typedef(db_function_o))) {
			if (db_typeof(object) == db_typedef(db_metaprocedure_o)) {
				object->size += sizeof(db_any);
			} else {
				object->size += sizeof(db_object);
			}
		}
	}

	return 0;
/* $end */
}

/* callback ::hyve::lang::type::init(lang::object object) -> ::hyve::lang::function::init(lang::function object) */
/* $header(::hyve::lang::function::init) */
static db_int16 db_function_parseArguments(db_function object) {
    object->parameters = db_function_stringToParameterSeq(db_nameof(object), db_parentof(object));
    return 0;
}

typedef struct db_functionLookup_t {
	db_function f;
	db_bool error;
	db_id name;
}db_functionLookup_t;

static int db_functionLookupWalk(db_object o, void* userData) {
	db_functionLookup_t* data;
	db_int32 d;

	data = userData;

	if (o != data->f) {
		if ((db_class_instanceof(db_procedure_o, db_typeof(o)))) {
			if (db_overload(o, db_nameof(data->f), &d, FALSE)) {
				data->error = TRUE;
				goto finish;
			}

			/* Check if function matches */
			if (!d) {
				db_id id, id2;
				db_error("function '%s' conflicts with existing declaration '%s'", db_fullname(data->f, id), db_fullname(o, id2));
				data->error = TRUE;
				goto finish;
			} else {
				db_id id;

				/* Get name of function */
				db_signatureName(db_nameof(o), id);

				/* Set overloading flags if a function with same name is found. */
				if (!strcmp(data->name, id)) {
					db_function(o)->overloaded = TRUE;
					data->f->overloaded = TRUE;
				}
			}
		}
	}

	return 1;
finish:
	return 0;
}
/* $end */
db_int16 db_function_init(db_function object) {
/* $begin(::hyve::lang::function::init) */
	db_functionLookup_t walkData;
    db_ll scope;
	DB_UNUSED(object);

	scope = db_scopeClaim(db_parentof(object));

    walkData.f = object;
    walkData.error = FALSE;
    db_signatureName(db_nameof(object), walkData.name);
    db_llWalk(scope, db_functionLookupWalk, &walkData);
    if (walkData.error) {
    	goto error;
    }

    db_scopeRelease(scope);

    /* Parse arguments */
    if (db_function_parseArguments(object)) {
    	goto error;
    }

    return 0;
error:
	return -1;
/* $end */
}

/* ::hyve::lang::function::stringToParameterSeq(lang::string name,lang::object scope) */
db_parameterSeq db_function_stringToParameterSeq(db_string name, db_object scope) {
/* $begin(::hyve::lang::function::stringToParameterSeq) */
    db_parameterSeq result = {0, NULL};

    db_char* ptr;

    ptr = strchr(name, '(');
    if (!ptr) {
        db_error("missing argumentlist in name for signature '%s'", name);
        goto error;
    }
    ptr++;

    /* Check if function has arguments */
    if (*ptr != ')') {
        db_uint32 count, i;
        db_id id;
        db_bool reference;

        /* Count number of parameters for function */
        count = db_signatureParamCount(name);
        i = 0;
        reference = FALSE;

        /* Allocate size for parameters */
        result.length = count;
        result.buffer = db_malloc(sizeof(db_parameter) * count);
        memset(result.buffer, 0, sizeof(db_parameter) * count);

        /* Parse arguments */
        for(i=0; i<count; i++) {
            if (db_signatureParamType(name, i, id, &reference)) {
                db_error("error occurred while parsing type of argument '%s' for signature '%s'", name);
                goto error;
            }

            /* Set reference */
            result.buffer[i].passByReference = reference;

            /* Assign type */
            result.buffer[i].type = db_resolve_ext(NULL, scope, id, FALSE, "Resolve parameter-type for function");
            if (!result.buffer[i].type) {
                db_error("type '%s' of argument %d in signature %s not found", id, i, name);
                goto error;
            }

            /* Parse name */
            if (db_signatureParamName(name, i, id)) {
                db_error("error occurred while parsing name of argument '%s' for signature '%s'", name);
                goto error;
            }
            result.buffer[i].name = db_strdup(id);
        }
    }

    return result;
error:
    result.length = -1;
    db_dealloc(result.buffer);
    result.buffer = NULL;
    return result;

/* $end */
}

/* ::hyve::lang::function::unbind(lang::function object) */
db_void db_function_unbind(db_function object) {
/* $begin(::hyve::lang::function::unbind) */
    db_uint32 i;

    db_callDestroy(object);

    /* Deinitialize parameters */
    for(i=0; i<object->parameters.length; i++) {
        db_dealloc(object->parameters.buffer[i].name);
        object->parameters.buffer[i].name = NULL;
        db_free_ext(object, object->parameters.buffer[i].type, "Free function parameter-type.");
        object->parameters.buffer[i].type = NULL;
    }

    db_dealloc(object->parameters.buffer);
    object->parameters.buffer = NULL;
/* $end */
}
