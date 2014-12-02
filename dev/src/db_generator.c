/*
 * db_generator.c
 *
 *  Created on: Sep 17, 2012
 *      Author: sander
 */

#include "hyve.h"
#include "db_generator.h"
#include "stdarg.h"

/* Generator functions */
db_generator gen_new(db_string name, db_string language) {
    db_generator result;

    result = db_malloc(sizeof(struct db_generator_s));

    /* List of output directories is initially empty */
    result->attributes = NULL;

    /* List of files is initially empty */
    result->files = NULL;

    /* No imports are resolved */
    result->imports = NULL;

    /* Set objects */
    result->objects = NULL;

    /* Set name */
    if (name) {
    	result->name = strdup(name);
    } else {
    	result->name = NULL;
    }

    if (language) {
        result->language = strdup(language);
    } else {
        result->language = strdup("c"); /* Take 'c' as default language */
    }

    /* Set id-generation to default */
    result->idKind = DB_GENERATOR_ID_DEFAULT;

    /* Set action-callbacks */
    result->start_action = NULL;
    result->id_action = NULL;

    /* No library loaded */
    result->library = NULL;

    /* Current will be set by object walk */
    result->current = NULL;

    return result;
}

/* Control how id's are generated */
g_idKind g_setIdKind(db_generator g, g_idKind kind) {
	g_idKind prev;
	prev = g->idKind;
	g->idKind = kind;
	return prev;
}

/* Get name, or if no name is provided, return name of current parse-object */
db_string g_getName(db_generator g) {
	db_string result;

	result = NULL;
	if (g->name) {
		result = g->name;
	} else if (g->current) {
		result = db_nameof(g->current->o);
	}

	return result;
}

/* Get current object */
db_object g_getCurrent(db_generator g) {
	db_object result;

	result = NULL;

	if (g->current) {
		result = g->current->o;
	}

	return result;
}

/* Add to-parse object */
void gen_parse(db_generator g, db_object object, db_bool parseSelf, db_bool parseScope, db_string prefix) {
    g_object* o = NULL;
    db_iter objectIter;

    /* First do a lookup, check if the object already exists */
    if (g->objects) {
    	g_object *object;
    	objectIter = db_llIter(g->objects);
    	while(db_iterHasNext(&objectIter)) {
    		object = db_iterNext(&objectIter);
    		if (object->o == object) {
    			o = object;
    			break;
    		}
    	}
    }

    db_trace("o = %p (%s)", o, db_nameof(object));

    if (!o) {
		o = db_malloc(sizeof(g_object));
		db_keep(object);
		o->o = object;
		o->parseSelf = parseSelf;
		o->parseScope = parseScope;

		if (prefix) {
			o->prefix = strdup(prefix);
		} else {
			o->prefix = NULL;
		}

		if (!g->objects) {
			g->objects = db_llNew();
		}
		db_llAppend(g->objects, o);

		if (!g->current) {
			g->current = o;
		}
    } else {
    	/* Prefixes can be overridden if NULL. */
    	if (!o->prefix) {
    		o->prefix = db_strdup(prefix);
    	}
    }
}

static int g_genAttributeFind(void *value, void *userData) {
	g_attribute *attr = value;
	if(!strcmp(attr->key, *(db_string*)userData)) {
		*(void**)userData = attr;
		return 0;
	}
	return 1;
}

/* Set attribute */
void gen_setAttribute(db_generator g, db_string key, db_string value) {
    g_attribute* attr = NULL;

    if (!g->attributes) {
        g->attributes = db_llNew();
    }else {
    	void* userData = key;
		if(!db_llWalk(g->attributes, g_genAttributeFind, &userData)) {
			attr = userData;
		}
    }

    if(!attr) {
	    attr = db_malloc(sizeof(g_attribute));
	    attr->key = db_strdup(key);
	}else {
		db_dealloc(attr->value);
	}
    attr->value = db_strdup(value);

    db_llAppend(g->attributes, attr);
}

/* Get attribute */
db_string gen_getAttribute(db_generator g, db_string key) {
	db_string result = NULL;

	if(g->attributes) {
		void *userData = key;
		if(!db_llWalk(g->attributes, g_genAttributeFind, &userData)) {
			result = ((g_attribute*)userData)->value;
		}
	}

	return result;
}

/* Load generator actions from library */
db_int16 gen_load(db_generator g, db_string library) {

    /* Load library */
    g->library = db_dlOpen(library);
    if (!g->library) {
        db_error("%s", db_dlError());
        goto error;
    }

    /* Load actions */
    g->start_action = (g_startAction)db_dlProc(g->library, "hyve_genMain");
    if (!g->start_action) {
        db_error("g_Load: unresolved symbol 'hyve_genMain'");
        goto error;
    }
    g->id_action = (g_idAction)db_dlProc(g->library, "hyve_genId");

    /* Function is allowed to be absent. */

    return 0;
error:
    return -1;
}

static int g_freeObjects(void* _o, void* udata) {
	g_object* o;

	DB_UNUSED(udata);

	o = _o;
	if (o->prefix) {
		db_dealloc(o->prefix);
	}
	db_free(o->o);
	db_dealloc(o);

	return 1;
}

/* Free snippet */
static int g_freeSnippet(void* o, void* udata) {
	g_fileSnippet* snippet;
	g_file file;

	snippet = o;
	file = udata;

	if (!snippet->used) {
		g_fileWrite(file, "%s(%s)", snippet->option, snippet->id);
		g_fileWrite(file, "%s", snippet->src);
		g_fileWrite(file, "$end\n");
		db_warning("%s: code-snippet '%s' is not used, manually merge or remove from file.", file->name, snippet->id);
	}

	if (snippet->id) {
		db_dealloc(snippet->id);
	}
	if (snippet->src) {
		db_dealloc(snippet->src);
	}

	db_dealloc(snippet);

	return 1;
}

/* Close file */
static int g_closeFile(void* o, void* udata) {
    g_file file;
    DB_UNUSED(udata);

    file = o;

    /* Free snippets */
    if (file->snippets) {
    	db_llWalk(file->snippets, g_freeSnippet, file);
    	db_llFree(file->snippets);
    }
    if (file->headers) {
    	db_llWalk(file->headers, g_freeSnippet, file);
    	db_llFree(file->headers);
    }

    db_fileClose(file->file);
    db_dealloc(file->name);
    db_dealloc(file);

    return 1;
}

static int g_freeAttribute(void* _o, void* udata) {
    g_attribute* o;

    DB_UNUSED(udata);

    o = _o;
    if (o->key) {
        db_dealloc(o->key);
    }
    if (o->value) {
        db_dealloc(o->value);
    }

    db_dealloc(o);

    return 1;
}

/* Free generator */
void gen_free(db_generator g) {
    if (g->library) {
        db_dlClose(g->library);
        g->library = NULL;
    }

    if (g->objects) {
        db_llWalk(g->objects, g_freeObjects, NULL);
        db_llFree(g->objects);
        g->objects = NULL;
    }

    if (g->files) {
        db_llWalk(g->files, g_closeFile, NULL);
        db_llFree(g->files);
        g->files = NULL;
    }

    if (g->attributes) {
        db_llWalk(g->attributes, g_freeAttribute, NULL);
        db_llFree(g->attributes);
        g->attributes = NULL;
    }

    if (g->imports) {
    	db_llFree(g->imports);
    }

    if (g->name) {
    	db_dealloc(g->name);
    }
    if (g->language) {
        db_dealloc(g->language);
    }
    db_dealloc(g);
}

/* Start generator */
db_int16 gen_start(db_generator g) {
    return g->start_action(g);
}

/* ==== Generator utility functions */
typedef struct g_serializeImports_t {
    db_generator g;
    db_object stack[1024]; /* Maximum serializer-depth */
    db_uint32 count;
}g_serializeImports_t;
db_int16 g_serializeImportsReference(db_serializer s, db_value *v, void* userData) {
	db_object o;
	g_serializeImports_t *data = userData;
	db_generator g = data->g;

	o = *(db_object*)db_valueValue(v);
	if (o) {
	    /* Search unscoped object for references to other modules */
		if (!db_checkAttr(o, DB_ATTR_SCOPED)) {
		    db_uint32 i;

		    /* Make sure to not serialize an object twice, in case of a cycle */
		    for(i=0; i<data->count; i++) {
		        if (data->stack[i] == o) {
		            break;
		        }
		    }

		    if (i == data->count) {
                data->stack[data->count] = o;
                data->count++;
                db_serialize(s, o, userData);
                data->count--;
		    }
		} else {
			if (!g_mustParse(g, o)) {
	    		db_object parent = o;
	    		while(parent && (db_parentof(parent) != hyve_lang_o)) {
	    			parent = db_parentof(parent);
	    		}
	    		if (!parent) {
		    		parent = o;
		    		while(parent && (db_typeof(parent)->real->kind != DB_VOID)) {
		    			parent = db_parentof(parent);
		    		}
		    		if (!g->imports) {
		    			g->imports = db_llNew();
		    		}
		    		if ((parent != root_o) && !db_llHasObject(g->imports, parent)) {
		    			db_llInsert(g->imports, parent);
		    		}
	    		}
			}
		}
	}

	return 0;
}


struct db_serializer_s g_serializeImportsSerializer(void) {
	struct db_serializer_s result;
	db_serializerInit(&result);
	result.reference = g_serializeImportsReference;
	result.access = DB_PRIVATE;
	result.accessKind = DB_NOT; /* Serialize not nothing, thus everything. */
	return result;
}

struct g_walkObjects_t {
    g_walkAction action;
    void* userData;
};

/* Resolve imports */
int g_importWalk(db_object o, void* userData) {
	db_generator g = userData;
	g_serializeImports_t walkData;
	struct db_serializer_s s;

	walkData.count = 0;
	walkData.g = g;
	s = g_serializeImportsSerializer();
	db_serialize(&s, o, &walkData);
	return 1;
}

db_int16 g_resolveImports(db_generator generator) {
	g_walk(generator, g_importWalk, generator);
	return 0;
}


/* Recursively walk scopes */
int g_walkObjects(void* o, void* userData) {
    struct g_walkObjects_t* data;

    data = userData;

    if (!data->action(o, data->userData)) {
        goto stop;
    }

    return db_scopeWalk(o, g_walkObjects, userData);
stop:
    return 0;
}

/* Walk objects, choose between recursive scopewalk or only top-level objects */
static int g_walk_ext(db_generator g, g_walkAction action, void* userData, db_bool scopeWalk, db_bool recursiveWalk) {
    db_iter iter;

    if (g->objects) {
        g_object* o;

        iter = db_llIter(g->objects);
        while(db_iterHasNext(&iter)) {
            o = db_iterNext(&iter);

            /* Parse object */
            if (o->parseSelf) {
                g->current = o;
                if (!action(o->o, userData)) {
                    goto stop;
                }
            }
            /* Walk scopes */
            if (o->parseScope && scopeWalk) {
                g->current = o;
                if (!recursiveWalk) {
                    if (!db_scopeWalk(o->o, action, userData)) {
                        goto stop;
                    }
                } else {
                    struct g_walkObjects_t walkData;
                    walkData.action = action;
                    walkData.userData = userData;

                    /* Recursively walk scopes */
                    if (!db_scopeWalk(o->o, g_walkObjects, &walkData)) {
                        goto stop;
                    }
                }
            }
        }
    }

    return 1;
stop:
    return 0;
}

/* Walk objects */
int g_walk(db_generator g, g_walkAction action, void* userData) {
    return g_walk_ext(g, action, userData, TRUE, FALSE);
}

/* Walk objects, never walk scopes, even if object is required to. */
int g_walkNoScope(db_generator g, g_walkAction action, void* userData) {
    return g_walk_ext(g, action, userData, FALSE, FALSE);
}

/* Walk objects recursively */
int g_walkRecursive(db_generator g, g_walkAction action, void* userData) {
    return g_walk_ext(g, action, userData, TRUE, TRUE);
}

/* Find prefix for a given object. Search parse-object in generator
 * which is closest to the object passed to this function. */
static g_object* g_findPrefix(db_generator g, db_object o, db_object* match) {
	db_iter iter;
	g_object *result, *t;
	db_object parent;
	unsigned int distance, minDistance;

	result = NULL;
	if (g->objects) {
		minDistance = -1;
		iter = db_llIter(g->objects);
		while(db_iterHasNext(&iter)) {
			t = db_iterNext(&iter);

			/* Check if object occurs in scope of 'o' and measure distance to 'o' */
			parent = o;
			distance = 0;
			while(parent && (parent != t->o)) {
				distance++;
				parent = db_parentof(parent);
			}

			/* If a parent was found (parent of root is NULL), assign it to result if
			 * distance is smaller than minDistance */
			if (parent) {
				if ((distance < minDistance)) {
					result = t;
					minDistance = distance;
					if (match) {
						*match = parent;
					}
				}
			}
		}
	}

	return result;
}

/* Obtain prefix */
db_string g_getPrefix(db_generator g, db_object o) {
    g_object* prefix;

    /* Lookup prefix */
    prefix = g_findPrefix(g, o, NULL);

    return (prefix != NULL) ? prefix->prefix : NULL;
}

/* Object transformations */
static db_char* g_oidTransform(db_generator g, db_object o, db_id _id, g_idKind kind) {
	DB_UNUSED(g);

	/* If the object is a function with an argumentlist, cut the argumentlist
	 * from the name if the function is not overloaded. This keeps processing for
	 * generators trivial. */
	if (db_class_instanceof(db_procedure_o, db_typeof(o))) {
	    if (!db_function(o)->overloaded) {
            db_char* ptr;
            ptr = strchr(_id, '(');
            if (ptr) {
                *ptr = '\0';
            } else {
            	if (db_procedure(db_typeof(o))->kind != DB_OBSERVER) {
					db_id id;
					db_warning("function object '%s' without argument list.", db_fullname(o, id));
            	}
            }
	    } else {
	        /* If function is overloaded, construct the 'request' string, that is, the string without
	         * the argument-names. This results in a string with only the types, which is enough to
	         * generate unique names in languages which do not support overloading. */
	        db_id tmp, buff;
	        db_uint32 count, i;
	        strcpy(tmp, _id);

	        db_signatureName(tmp, _id);
	        strcat(_id, "(");

	        count = db_signatureParamCount(tmp);

	        /* strcat is not the most efficient function here, but it is the easiest, and this
	         * part of the code is not performance-critical. */
	        for(i=0; i<count; i++) {
	            db_signatureParamType(tmp, i, buff, NULL);
	            if (i) {
	                strcat(_id, ",");
	            }
	            strcat(_id, buff);
	        }
	        strcat(_id, ")");
	    }
	}

	/* Check if class-identifiers must be altered */
	if (kind != DB_GENERATOR_ID_DEFAULT) {
	    db_object i = o;
        db_char* ptr;

        ptr = _id + strlen(_id);
	    while(i) {
            while((ptr > _id) && (*ptr != ':')) {
                ptr--;
            }
            if ((db_class_instanceof(db_interface_o, i) && db_typedef(i)->real->reference) || (i == db_typedef(db_object_o))) {
            	db_char *start;
                if (*ptr == ':') {
                	start = ptr + 1;
                } else {
                	start = ptr;
                }
				if (kind == DB_GENERATOR_ID_CLASS_UPPER) {
					strtoupper(start);
				} else {
					strtolower(start);
				}
            }

            if (ptr == _id) {
            	break;
            }

            i = db_parentof(i);
            if (i) {
                if (*ptr == ':') {
                    ptr -= 2;
                }
            }
	    }
	}

	return _id;
}

/* Translate object-id */
db_string g_fullOidExt(db_generator g, db_object o, db_id id, g_idKind kind) {
	g_object* prefix;
	db_object match;
	db_id _id;

	id[0] = '\0';

	/* Find prefix for object */
	match = NULL;
	prefix = g_findPrefix(g, o, &match);

	/* TODO: prefix i.c.m. !DB_GENERATOR_ID_DEFAULT & nested classes i.c.m. !DB_GENERATOR_ID_DEFAULT */

	/* If prefix is found, replace the scope up until the found object with the prefix */
	if (prefix && prefix->prefix) {
		db_uint32 count;
		db_object scopes[DB_MAX_SCOPE_DEPTH];

		/* Obtain list of scopes from matched to object */
		count = 0;
		scopes[count] = o;
		while(scopes[count] != match) {
			scopes[count+1] = db_parentof(scopes[count]);
			count++;
		}

		/* Paste in prefix */
		strcpy(_id, prefix->prefix);
		while(count) {
			count--;
			strcat(_id, "::");
			strcat(_id, db_nameof(scopes[count]));
		}

	/* If no prefix is found for object, just use the scoped identifier */
	} else {
		db_fullname(o, _id);
	}

	g_oidTransform(g, o, _id, kind);

	if (g->id_action) {
		g->id_action(_id, id);
	} else {
		strcpy(_id, id);
	}

	return id;
}

/* Translate an object to a language-specific identifier with idKind provided. */
db_string g_fullOid(db_generator g, db_object o, db_id id) {
	return g_fullOidExt(g, o, id, g->idKind);
}

/* Translate an id to language representation */
db_string g_id(db_generator g, db_string str, db_id id) {
	db_string result;

	if (g->id_action) {
		result = g->id_action(str, id);
	} else {
		result = str;
	}

	return result;
}

/* Translate a class id to language representation */
db_string g_oid(db_generator g, db_object o, db_id id) {
	db_string result;
	db_id cid;
	g_object* prefix;
    db_object match;

    /* Find prefix for object */
    match = NULL;
    prefix = g_findPrefix(g, o, &match);

   /* If prefix is found, replace the scope up until the found object with the prefix */
    if (prefix && prefix->prefix) {
        if (prefix->o == o) {
            strcpy(cid, prefix->prefix);
        } else {
            strcpy(cid, db_nameof(o));
        }

    /* If no prefix is found for object, just use the identifier */
    } else {
        strcpy(cid, db_nameof(o));
    }

	g_oidTransform(g, o, cid, g->idKind);

	if (g->id_action) {
		result = g->id_action(cid, id);
	} else {
		result = id;
	}

	return result;
}


/* ==== Generator file-utility class */

/* Convert a filename to a filepath, depending on it's extension. */
static db_string g_filePath(db_generator g, db_string filename, db_char* buffer) {
    db_string result;

    result = filename;

    if (g->attributes) {
        db_string ext = NULL;
        db_string fext, ptr;

        /* Get file-extension */
        fext = NULL;
        ptr = filename;
        while((ptr = strchr(ptr, '.'))) {
            ptr++;
            fext = ptr;
        }

        /* Check whether there is an attribute with the file extension - determines where to put the file */
        if(fext) {
	        ext = gen_getAttribute(g, fext);
	    }

        /* Append filename to location. */
        if (ext) {
            sprintf(buffer, "%s/%s", ext, filename);
            result = buffer;
        }
    }

    return result;
}

/* Read file */
db_string g_fileRead(db_generator g, db_string name) {
    db_char filepath[512];
    return db_fileLoad(g_filePath(g, name, filepath));
}

/* Find existing pars in the code that must not be overwritten. */
db_int16 g_loadExisting(db_generator g, db_string name, db_string option, db_ll *list) {
    db_string code, ptr;

    code = g_fileRead(g, name);
    if (code) {
        ptr = code;

		while((ptr = strstr(ptr, option))) {
			ptr += strlen(option);

			/* Find begin of identifier */
			if (*ptr == '(') {
				db_string endptr;

				/* Find end of identifier */
				endptr = strstr(ptr, ") */");
				if (endptr) {
					db_id identifier;

					/* Copy identifier string */
					*endptr = '\0';
					strcpy(identifier, ptr + 1);
					ptr = endptr + 1;

					/* Find $end */
					endptr = strstr(ptr, "$end");
					if (endptr) {
						g_fileSnippet* existing;
						db_string src;

						*endptr = '\0';
						src = strdup(ptr);

						if (!*list) {
							*list = db_llNew();
						}

						existing = db_malloc(sizeof(g_fileSnippet));
						existing->option = strdup(option);
						existing->id = strdup(identifier);
						existing->src = src;
						existing->used = FALSE;
						db_llInsert(*list, existing);

						ptr = endptr + 1;

					} else {
						db_error("generator: missing $end after $begin(%s)", identifier);
						goto error;
					}
				} else {
					db_error("generator: missing ')' after %s(", option);
					goto error;
				}
			} else {
				db_error("generator: missing '(' after %s.", option);
				goto error;
			}
		}
		db_dealloc(code);
    }


    return 0;
error:
    return -1;
}

/* Open file */
g_file g_fileOpen(db_generator g, db_string name) {
	g_file result;
	db_char filepath[512];

	result = db_malloc(sizeof(struct g_file_s));
	result->snippets = NULL;
	result->headers = NULL;
	result->scope = NULL;
	result->file = NULL;
	result->indent = 0;
	result->name = db_strdup(name);
	result->generator = g;

	/* First, load existing implementation if file exists */
	if (g_loadExisting(g, name, "$header", &result->headers)) {
		db_dealloc(result);
		goto error;
	}
	if (g_loadExisting(g, name, "$begin", &result->snippets)) {
	    db_dealloc(result);
		goto error;
	}

	result->file = db_fileOpen(g_filePath(g, name, filepath));
	if (!result->file) {
	    db_dealloc(result);
	    goto error;
	}

	if (!g->files) {
		g->files = db_llNew();
	}
	db_llInsert(g->files, result);

	return result;
error:
	db_error("failed to open file '%s'", name);
	return NULL;
}


/* Lookup an existing code-snippet */
db_string g_fileLookupSnippetIntern(g_file file, db_string snippetId, db_ll list) {
    db_iter iter;
    g_fileSnippet* snippet;
    DB_UNUSED(file);

    snippet = NULL;

    if (list) {
        iter = db_llIter(list);
        while(db_iterHasNext(&iter)) {
            snippet = db_iterNext(&iter);
            if (!stricmp(snippet->id, snippetId)) {
            	snippet->used = TRUE;
                break;
            } else {
                snippet = NULL;
            }
        }
    }

    return snippet ? snippet->src : NULL;
}

db_string g_fileLookupSnippet(g_file file, db_string snippetId) {
	return g_fileLookupSnippetIntern(file, snippetId, file->snippets);
}

db_string g_fileLookupHeader(g_file file, db_string snippetId) {
	return g_fileLookupSnippetIntern(file, snippetId, file->headers);
}

/* Test if object must be parsed */
int g_checkParseWalk(void* o, void* userData) {
    g_object* _o;
    int result;

    _o = o;
    result = 1;

    /* If parseSelf, and object equals generatorObject, object must be parsed. */
    if (_o->parseSelf && (_o->o == userData)) {
        result = 0;

    /* Look for generator object in object-scope */
    } else if (_o->parseScope) {
        db_object ptr = userData;

        /* Walk object-scope */
        while((ptr = db_parentof(ptr)) && ptr != _o->o);
        if (ptr) {
            result = 0;
        }
    }

    return result;
}

db_bool g_mustParse(db_generator g, db_object o) {
	db_bool result;

	result = TRUE;
    if (db_checkAttr(o, DB_ATTR_SCOPED)) {
    	if (db_llWalk(g->objects, g_checkParseWalk, o)) {
			result = FALSE;
    	}
    }

    return result;
}

/* Increase indentation */
void g_fileIndent(g_file file) {
	file->indent++;
}

/* Decrease indentation */
void g_fileDedent(g_file file) {
	file->indent--;
}

/* Set scope of file */
void g_fileScopeSet(g_file file, db_object o) {
	file->scope = o;
}

/* Get scope of file */
db_object g_fileScopeGet(g_file file) {
	return file->scope;
}

/* Write to file */
void g_fileWrite(g_file file, char* fmt, ...) {
	va_list args;
	db_char *buffer;
	db_uint32 len;

	va_start(args, fmt);
	len = vsnprintf(NULL, 0, fmt, args);
	va_end(args);

	if (len) {
        buffer = db_malloc(len + 1);

        va_start(args, fmt);
        len = vsnprintf(buffer, len + 1, fmt, args);
        va_end(args);

        db_assert(len == strlen(buffer), "calculated length(%d) does not correspond with length of resulting string(%d)!", len, strlen(buffer));

        /*ptr = buffer;
        while((ptr = strchr(ptr, '\n'))) {
        	switch(*(ptr+1)) {
        	case '\0':
        	case '\n':
        		break;
        	default:
        		db_error("g_fileWrite: newline characters should be placed at end of string ('%s').", buffer);
        		break;
        	}
        	ptr++;
        }*/

        /* Write indentation & string */
        if (file->indent && file->endLine) {
            if (fprintf(db_fileGet(file->file), "%*s%s", file->indent * 4, " ", buffer) < 0) {
                db_error("g_fileWrite: writing to outputfile failed.");
            }
        } else {
            if (fprintf(db_fileGet(file->file), "%s", buffer) < 0) {
                db_error("g_fileWrite: writing to outputfile failed.");
            }
        }

        file->endLine = buffer[strlen(buffer)-1] == '\n';

        db_dealloc(buffer);
	}
}

/* Get generator */
db_generator g_fileGetGenerator(g_file file) {
    return file->generator;
}


/* Translate names of members so that they can be used in the same scope (for example when used as function parameter) */
typedef struct db_genWalkMember_t {
	db_member member;
	db_uint32 occurred;
}db_genWalkMember_t;

static db_uint32 db_genMemberCacheCount(db_ll cache, db_member m) {
	db_iter memberIter;
	db_genWalkMember_t *member;
	db_uint32 result = 0;

	memberIter = db_llIter(cache);
	while(db_iterHasNext(&memberIter)) {
		member = db_iterNext(&memberIter);
		if (!strcmp(db_nameof(member->member), db_nameof(m))) {
			result++;
		}
	}

	return result;
}

static db_uint32 db_genMemberCacheGet(db_ll cache, db_member m) {
	db_iter memberIter;
	db_genWalkMember_t *member;
	db_uint32 result = 0;

	memberIter = db_llIter(cache);
	while(db_iterHasNext(&memberIter)) {
		member = db_iterNext(&memberIter);
		if (member->member == m) {
			result = member->occurred;
			break;
		}
	}

	return result;
}

static db_int16 db_genMemberCache_member(db_serializer s, db_value *info, void* userData) {
	db_ll cache;
	DB_UNUSED(s);

	cache = userData;

	if (info->kind == DB_MEMBER) {
		db_genWalkMember_t *parameter;
		db_member m = info->is.member.t;

		parameter = db_malloc(sizeof(db_genWalkMember_t));
		parameter->member = m;
		parameter->occurred = db_genMemberCacheCount(cache, m);
		db_llAppend(cache, parameter);
	} else {
		db_serializeMembers(s, info, userData);
	}

	return 0;
}

db_char* db_genMemberName(db_generator g, db_ll cache, db_member m, db_char *result) {
	db_uint32 count;
	db_id temp;

	if ((count = db_genMemberCacheGet(cache, m))) {
		sprintf(temp, "%s_%d", db_nameof(m), count);
	} else {
		strcpy(temp, db_nameof(m));
	}

	g_id(g, temp, result);

	return result;
}

/* Build cache to determine whether membernames occur more than once (due to inheritance) */
db_ll db_genMemberCacheBuild(db_interface o) {
	struct db_serializer_s s;
	db_ll result;

	db_serializerInit(&s);
	s.access = DB_LOCAL | DB_PRIVATE;
	s.accessKind = DB_NOT;
	s.metaprogram[DB_MEMBER] = db_genMemberCache_member;
	result = db_llNew();

	db_metaWalk(&s, db_type(o), result);

	return result;
}

void db_genMemberCacheClean(db_ll cache) {
	db_iter memberIter;
	db_genWalkMember_t *member;

	memberIter = db_llIter(cache);
	while(db_iterHasNext(&memberIter)) {
		member = db_iterNext(&memberIter);
		db_dealloc(member);
	}
	db_llFree(cache);
}
