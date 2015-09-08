/*
 * cx_generator.c
 *
 *  Created on: Sep 17, 2012
 *      Author: sander
 */

#define corto_lang_LIB
#include "corto.h"
#include "cx_generator.h"
#include "ctype.h"
#include "stdarg.h"
#include "stdio.h"

#ifdef CX_GENERATOR

/* Generator functions */
cx_generator gen_new(cx_string name, cx_string language) {
    cx_generator result;

    result = cx_alloc(sizeof(struct cx_generator_s));

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
        result->name = cx_strdup(name);
    } else {
        result->name = NULL;
    }

    if (language) {
        result->language = cx_strdup(language);
    } else {
        result->language = cx_strdup("c"); /* Take 'c' as default language */
    }

    /* Set id-generation to default */
    result->idKind = CX_GENERATOR_ID_DEFAULT;

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
g_idKind g_setIdKind(cx_generator g, g_idKind kind) {
    g_idKind prev;
    prev = g->idKind;
    g->idKind = kind;
    return prev;
}

/* Get name, or if no name is provided, return name of current parse-object */
cx_string g_getName(cx_generator g) {
    cx_string result;

    result = NULL;
    if (g->name) {
        result = g->name;
    } else if (g->current) {
        result = cx_nameof(g->current->o);
    }

    return result;
}

/* Get current object */
cx_object g_getCurrent(cx_generator g) {
    cx_object result;

    result = NULL;

    if (g->current) {
        result = g->current->o;
    }

    return result;
}

/* Add to-parse object */
void gen_parse(cx_generator g, cx_object object, cx_bool parseSelf, cx_bool parseScope, cx_string prefix) {
    g_object* o = NULL;
    cx_iter objectIter;

    /* First do a lookup, check if the object already exists */
    if (g->objects) {
        g_object *object;
        objectIter = cx_llIter(g->objects);
        while(cx_iterHasNext(&objectIter)) {
            object = cx_iterNext(&objectIter);
            if (object->o == object) {
                o = object;
                break;
            }
        }
    }

    if (!o) {
        o = cx_alloc(sizeof(g_object));
        cx_claim(object);
        o->o = object;
        o->parseSelf = parseSelf;
        o->parseScope = parseScope;

        if (prefix) {
            if (strlen(prefix) >= sizeof(cx_id)) {
                cx_error("prefix cannot be longer than %d characters", sizeof(cx_id));
                o->prefix = NULL;
            } else {
                o->prefix = cx_strdup(prefix);
            }
        } else {
            o->prefix = NULL;
        }

        if (!g->objects) {
            g->objects = cx_llNew();
        }
        cx_llAppend(g->objects, o);

        if (!g->current) {
            g->current = o;
        }
    } else {
        /* Prefixes can be overridden if NULL. */
        if (!o->prefix) {
            o->prefix = cx_strdup(prefix);
        }
    }
}

static int g_genAttributeFind(void *value, void *userData) {
    g_attribute *attr = value;
    if(!strcmp(attr->key, *(cx_string*)userData)) {
        *(void**)userData = attr;
        return 0;
    }
    return 1;
}

/* Set attribute */
void gen_setAttribute(cx_generator g, cx_string key, cx_string value) {
    g_attribute* attr = NULL;

    if (!g->attributes) {
        g->attributes = cx_llNew();
    }else {
        void* userData = key;
        if(!cx_llWalk(g->attributes, g_genAttributeFind, &userData)) {
            attr = userData;
        }
    }

    if(!attr) {
        attr = cx_alloc(sizeof(g_attribute));
        attr->key = cx_strdup(key);
    }else {
        cx_dealloc(attr->value);
    }
    attr->value = cx_strdup(value);

    cx_llAppend(g->attributes, attr);
}

/* Get attribute */
cx_string gen_getAttribute(cx_generator g, cx_string key) {
    cx_string result = NULL;

    if(g->attributes) {
        void *userData = key;
        if(!cx_llWalk(g->attributes, g_genAttributeFind, &userData)) {
            result = ((g_attribute*)userData)->value;
        }
    }

    if (!result) {
        result = "";
    }

    return result;
}

/* Load generator actions from library */
cx_int16 gen_load(cx_generator g, cx_string library) {

    /* Load library from generator path */
    cx_string relativePath = cx_envparse("generators/lib%s.so", library);
    cx_string path = cx_locateLibrary(relativePath);
    if (!path) {
        cx_error("generator '%s' not found", relativePath);
        goto error;
    }

    g->library = cx_dlOpen(path);
    cx_dealloc(path);
    if (!g->library) {
        cx_error("%s", cx_dlError());
        goto error;
    }

    /* Load actions */
    g->start_action = (g_startAction)cx_dlProc(g->library, "corto_genMain");
    if (!g->start_action) {
        cx_error("g_Load: unresolved symbol 'corto_genMain'");
        goto error;
    }
    g->id_action = (g_idAction)cx_dlProc(g->library, "corto_genId");

    /* Function is allowed to be absent. */

    cx_dealloc(relativePath);
    return 0;
error:
    cx_dealloc(relativePath);
    return -1;
}

static int g_freeObjects(void* _o, void* udata) {
    g_object* o;

    CX_UNUSED(udata);

    o = _o;
    if (o->prefix) {
        cx_dealloc(o->prefix);
    }
    cx_release(o->o);
    cx_dealloc(o);

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
        cx_warning("%s: code-snippet '%s' is not used, manually merge or remove from file.", file->name, snippet->id);
    }

    if (snippet->id) {
        cx_dealloc(snippet->id);
    }
    if (snippet->src) {
        cx_dealloc(snippet->src);
    }

    cx_dealloc(snippet);

    return 1;
}

/* Close file */
static int g_closeFile(void* o, void* udata) {
    g_file file;
    CX_UNUSED(udata);

    file = o;

    g_fileClose(file);

    return 1;
}

static int g_freeAttribute(void* _o, void* udata) {
    g_attribute* o;

    CX_UNUSED(udata);

    o = _o;
    if (o->key) {
        cx_dealloc(o->key);
    }
    if (o->value) {
        cx_dealloc(o->value);
    }

    cx_dealloc(o);

    return 1;
}

/* Free generator */
void gen_free(cx_generator g) {
    if (g->library) {
        cx_dlClose(g->library);
        g->library = NULL;
    }

    if (g->objects) {
        cx_llWalk(g->objects, g_freeObjects, NULL);
        cx_llFree(g->objects);
        g->objects = NULL;
    }

    if (g->files) {
        cx_llWalk(g->files, g_closeFile, NULL);
        cx_llFree(g->files);
        g->files = NULL;
    }

    if (g->attributes) {
        cx_llWalk(g->attributes, g_freeAttribute, NULL);
        cx_llFree(g->attributes);
        g->attributes = NULL;
    }

    if (g->imports) {
        cx_llFree(g->imports);
    }

    if (g->name) {
        cx_dealloc(g->name);
    }
    if (g->language) {
        cx_dealloc(g->language);
    }
    cx_dealloc(g);
}

/* Start generator */
cx_int16 gen_start(cx_generator g) {
    return g->start_action(g);
}

/* ==== Generator utility functions */
typedef struct g_serializeImports_t {
    cx_generator g;
    cx_object stack[1024]; /* Maximum serializer-depth */
    cx_uint32 count;
}g_serializeImports_t;
cx_int16 g_serializeImportsReference(cx_serializer s, cx_value *v, void* userData) {
    cx_object o;
    g_serializeImports_t *data = userData;
    cx_generator g = data->g;

    o = *(cx_object*)cx_valueValue(v);
    if (o) {
        /* Search unscoped object for references to other modules */
        if (!cx_checkAttr(o, CX_ATTR_SCOPED)) {
            cx_uint32 i;

            /* Make sure to not serialize an object twice, in case of a cycle */
            for(i=0; i<data->count; i++) {
                if (data->stack[i] == o) {
                    break;
                }
            }

            if (i == data->count) {
                data->stack[data->count] = o;
                data->count++;
                cx_serialize(s, o, userData);
                data->count--;
            }
        } else {
            if (!g_mustParse(g, o)) {
                cx_object parent = o;

                while(!cx_instanceof(cx_type(cx_package_o), parent)) {
                    parent = cx_parentof(parent);
                }

                if ((parent != root_o) && (parent != corto_o) && (parent != corto_lang_o)) {
                    if (!g->imports) {
                        g->imports = cx_llNew();
                    }
                    if (!cx_llHasObject(g->imports, parent)) {
                        cx_llInsert(g->imports, parent);
                    }
                }
            }
        }
    }

    return 0;
}

struct cx_serializer_s g_serializeImportsSerializer(void) {
    struct cx_serializer_s result;
    cx_serializerInit(&result);
    result.reference = g_serializeImportsReference;
    result.access = CX_PRIVATE;
    result.accessKind = CX_NOT; /* Serialize not nothing, thus everything. */
    return result;
}

struct g_walkObjects_t {
    g_walkAction action;
    void* userData;
};

/* Resolve imports */
int g_importWalk(cx_object o, void* userData) {
    cx_generator g = userData;
    g_serializeImports_t walkData;
    struct cx_serializer_s s;

    walkData.count = 0;
    walkData.g = g;
    s = g_serializeImportsSerializer();
    cx_serialize(&s, o, &walkData);
    return 1;
}

cx_int16 g_resolveImports(cx_generator generator) {
    g_walkRecursive(generator, g_importWalk, generator);
    return 0;
}


/* Recursively walk scopes */
int g_walkObjects(void* o, void* userData) {
    struct g_walkObjects_t* data;

    data = userData;

    if (!data->action(o, data->userData)) {
        goto stop;
    }

    return cx_scopeWalk(o, g_walkObjects, userData);
stop:
    return 0;
}

/* Walk objects, choose between recursive scopewalk or only top-level objects */
static int g_walk_ext(cx_generator g, g_walkAction action, void* userData, cx_bool scopeWalk, cx_bool recursiveWalk) {
    cx_iter iter;

    if (g->objects) {
        g_object* o;

        iter = cx_llIter(g->objects);
        while(cx_iterHasNext(&iter)) {
            o = cx_iterNext(&iter);

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
                    if (!cx_scopeWalk(o->o, action, userData)) {
                        goto stop;
                    }
                } else {
                    struct g_walkObjects_t walkData;
                    walkData.action = action;
                    walkData.userData = userData;

                    /* Recursively walk scopes */
                    if (!cx_scopeWalk(o->o, g_walkObjects, &walkData)) {
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
int g_walk(cx_generator g, g_walkAction action, void* userData) {
    return g_walk_ext(g, action, userData, TRUE, FALSE);
}

/* Walk objects, never walk scopes, even if object is required to. */
int g_walkNoScope(cx_generator g, g_walkAction action, void* userData) {
    return g_walk_ext(g, action, userData, FALSE, FALSE);
}

/* Walk objects recursively */
int g_walkRecursive(cx_generator g, g_walkAction action, void* userData) {
    return g_walk_ext(g, action, userData, TRUE, TRUE);
}

/* Find prefix for a given object. Search parse-object in generator
 * which is closest to the object passed to this function. */
static g_object* g_findPrefix(cx_generator g, cx_object o, cx_object* match) {
    cx_iter iter;
    g_object *result, *t;
    cx_object parent;
    unsigned int distance, minDistance;

    result = NULL;
    if (g->objects) {
        minDistance = -1;
        iter = cx_llIter(g->objects);
        while(cx_iterHasNext(&iter)) {
            t = cx_iterNext(&iter);

            /* Check if object occurs in scope of 'o' and measure distance to 'o' */
            parent = o;
            distance = 0;
            while(parent && (parent != t->o)) {
                distance++;
                parent = cx_parentof(parent);
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
cx_string g_getPrefix(cx_generator g, cx_object o) {
    g_object* prefix;

    /* Lookup prefix */
    prefix = g_findPrefix(g, o, NULL);

    return (prefix != NULL) ? prefix->prefix : NULL;
}

/* Object transformations */
static cx_char* g_oidTransform(cx_generator g, cx_object o, cx_id _id, g_idKind kind) {
    CX_UNUSED(g);

    /* If the object is a function with an argumentlist, cut the argumentlist
     * from the name if the function is not overloaded. This keeps processing for
     * generators trivial. */
    if (cx_class_instanceof(cx_procedure_o, cx_typeof(o))) {
        if (!cx_function(o)->overloaded) {
            cx_char* ptr;
            ptr = strchr(_id, '(');
            if (ptr) {
                *ptr = '\0';
            } else {
                if (cx_procedure(cx_typeof(o))->kind != CX_OBSERVER) {
                    cx_id id;
                    cx_warning("function object '%s' without argument list.", cx_fullname(o, id));
                }
            }
        } else {
            /* If function is overloaded, construct the 'request' string, that is, the string without
             * the argument-names. This results in a string with only the types, which is enough to
             * generate unique names in languages which do not support overloading. */
            cx_id tmp, buff;
            cx_int32 count, i;
            strcpy(tmp, _id);

            cx_signatureName(tmp, _id);
            strcat(_id, "(");

            count = cx_signatureParamCount(tmp);
            if (count == -1) {
                cx_error("invalid signature '%s'", tmp);
                goto error;
            }

            /* strcat is not the most efficient function here, but it is the easiest, and this
             * part of the code is not performance-critical. */
            for(i=0; i<count; i++) {
                cx_signatureParamType(tmp, i, buff, NULL);
                if (i) {
                    strcat(_id, ",");
                }
                strcat(_id, buff);
            }
            strcat(_id, ")");
        }
    }

    /* Check if class-identifiers must be altered */
    if (kind != CX_GENERATOR_ID_DEFAULT) {
        cx_object i = o;
        cx_char* ptr;

        ptr = _id + strlen(_id);
        while(i) {
            while((ptr > _id) && (*ptr != ':')) {
                ptr--;
            }
            if ((cx_class_instanceof(cx_interface_o, i) && cx_type(i)->reference) || (i == cx_type(cx_object_o))) {
                cx_char *start;
                if (*ptr == ':') {
                    start = ptr + 1;
                } else {
                    start = ptr;
                }
                if (kind == CX_GENERATOR_ID_CLASS_UPPER) {
                    *start = toupper(*start);
                } else {
                    *start = tolower(*start);
                }
            }

            if (ptr == _id) {
                break;
            }

            i = cx_parentof(i);
            if (i) {
                if (*ptr == ':') {
                    ptr -= 2;
                }
            }
        }
    }

    return _id;
error:
    return NULL;
}

/* Translate object-id */
cx_string g_fullOidExt(cx_generator g, cx_object o, cx_id id, g_idKind kind) {
    g_object* prefix;
    cx_object match;
    cx_id _id;

    id[0] = '\0';

    /* Find prefix for object */
    match = NULL;
    prefix = g_findPrefix(g, o, &match);

    /* TODO: prefix i.c.m. !CX_GENERATOR_ID_DEFAULT & nested classes i.c.m. !CX_GENERATOR_ID_DEFAULT */

    /* If prefix is found, replace the scope up until the found object with the prefix */
    if (prefix && prefix->prefix) {
        cx_uint32 count;
        cx_object scopes[CX_MAX_SCOPE_DEPTH];

        /* Obtain list of scopes from matched to object */
        count = 0;
        scopes[count] = o;
        while(scopes[count] != match) {
            scopes[count+1] = cx_parentof(scopes[count]);
            count++;
        }

        /* Paste in prefix */
        strcpy(_id, prefix->prefix);
        while(count) {
            count--;
            strcat(_id, "::");
            strcat(_id, cx_nameof(scopes[count]));
        }

    /* If no prefix is found for object, just use the scoped identifier */
    } else {
        cx_fullname(o, _id);
    }

    g_oidTransform(g, o, _id, kind);

    if (g->id_action) {
        g->id_action(_id, id);
    } else {
        strcpy(id, _id);
    }

    return id;
}

/* Translate an object to a language-specific identifier with idKind provided. */
cx_string g_fullOid(cx_generator g, cx_object o, cx_id id) {
    return g_fullOidExt(g, o, id, g->idKind);
}

/* Translate an id to language representation */
cx_string g_id(cx_generator g, cx_string str, cx_id id) {
    cx_string result;

    if (g->id_action) {
        result = g->id_action(str, id);
    } else {
        result = str;
    }

    return result;
}

/* Translate a class id to language representation */
cx_string g_oid(cx_generator g, cx_object o, cx_id id) {
    cx_string result;
    cx_id cid;
    g_object* prefix;
    cx_object match;

    /* Find prefix for object */
    match = NULL;
    prefix = g_findPrefix(g, o, &match);

   /* If prefix is found, replace the scope up until the found object with the prefix */
    if (prefix && prefix->prefix) {
        if (prefix->o == o) {
            strcpy(cid, prefix->prefix);
        } else {
            strcpy(cid, cx_nameof(o));
        }

    /* If no prefix is found for object, just use the identifier */
    } else {
        strcpy(cid, cx_nameof(o));
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
static cx_string g_filePath(cx_generator g, cx_string filename, cx_char* buffer) {
    cx_string result;

    result = filename;

    if (g->attributes) {
        cx_string ext = NULL;
        cx_string fext, ptr;

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
        if (ext && *ext) {
            sprintf(buffer, "%s/%s", ext, filename);
            result = buffer;
        }
    }

    return result;
}

/* Find existing parts in the code that must not be overwritten. */
cx_int16 g_loadExisting(cx_generator g, cx_string name, cx_string option, cx_ll *list) {
    cx_string code = NULL, ptr = NULL;
    CX_UNUSED(g);

    code = cx_fileLoad(name);
    if (code) {
        ptr = code;

        while((ptr = strstr(ptr, option))) {
            ptr += strlen(option);

            /* Find begin of identifier */
            if (*ptr == '(') {
                cx_string endptr;

                /* Find end of identifier */
                endptr = strstr(ptr, ") */");
                if (endptr) {
                    cx_id identifier;

                    /* Copy identifier string */
                    *endptr = '\0';

                    if (strlen(ptr) >= sizeof(cx_id)) {
                        cx_error(
                            "%s: identifier of code-snippet exceeds %d characters", sizeof(cx_id));
                        goto error;
                    }

                    strcpy(identifier, ptr + 1);
                    ptr = endptr + 1;

                    /* Find $end */
                    endptr = strstr(ptr, "$end");
                    if (endptr) {
                        g_fileSnippet* existing;
                        cx_string src;

                        *endptr = '\0';
                        src = cx_strdup(ptr);

                        if (!*list) {
                            *list = cx_llNew();
                        }

                        if(strstr(src, "$begin")) {
                            cx_error("%s: code-snippet '%s(%s)' contains nested $begin (did you forget an $end?)",
                                name, option, identifier);
                            cx_dealloc(src);
                            goto error;
                        }

                        existing = cx_alloc(sizeof(g_fileSnippet));
                        existing->option = cx_strdup(option);
                        existing->id = cx_strdup(identifier);
                        existing->src = src;
                        existing->used = FALSE;
                        cx_llInsert(*list, existing);

                        ptr = endptr + 1;

                    } else {
                        cx_error("generator: missing $end after $begin(%s)", identifier);
                        goto error;
                    }
                } else {
                    cx_error("generator: missing ')' after %s(", option);
                    goto error;
                }
            } else {
                cx_error("generator: missing '(' after %s.", option);
                goto error;
            }
        }
        cx_dealloc(code);
    }

    return 0;
error:
    if (code) {
        cx_dealloc(code);
    }
    return -1;
}

void g_fileClose(g_file file) {
    /* Remove file from generator administration */
    cx_llRemove(file->generator->files, file);

    /* Free snippets */
    if (file->snippets) {
        cx_llWalk(file->snippets, g_freeSnippet, file);
        cx_llFree(file->snippets);
    }
    if (file->headers) {
        cx_llWalk(file->headers, g_freeSnippet, file);
        cx_llFree(file->headers);
    }

    cx_fileClose(file->file);
    cx_dealloc(file->name);
    cx_dealloc(file);
}

static g_file g_fileOpenIntern(cx_generator g, cx_string name) {
    g_file result;

    result = cx_alloc(sizeof(struct g_file_s));
    result->snippets = NULL;
    result->headers = NULL;
    result->scope = NULL;
    result->file = NULL;
    result->indent = 0;
    result->name = cx_strdup(name);
    result->generator = g;

    /* First, load existing implementation if file exists */
    if (g_loadExisting(g, name, "$header", &result->headers)) {
        cx_dealloc(result);
        goto error;
    }
    if (g_loadExisting(g, name, "$begin", &result->snippets)) {
        cx_dealloc(result);
        goto error;
    }

    result->file = cx_fileOpen(name);
    if (!result->file) {
        cx_dealloc(result);
        goto error;
    }

    if (!g->files) {
        g->files = cx_llNew();
    }
    cx_llInsert(g->files, result);

    return result;
error:
    cx_error("failed to open file '%s'", name);
    return NULL;
}

/* Open file */
g_file g_fileOpen(cx_generator g, cx_string name) {
    cx_char filepath[512];
    return g_fileOpenIntern(g, g_filePath(g, name, filepath));
}

/* Open hidden file for writing. */
g_file g_hiddenFileOpen(cx_generator g, cx_string name) {
    cx_char filepath[512];
    sprintf(filepath, ".corto/%s", name);
    return g_fileOpenIntern(g, filepath);
}

/* Lookup an existing code-snippet */
cx_string g_fileLookupSnippetIntern(g_file file, cx_string snippetId, cx_ll list) {
    cx_iter iter;
    g_fileSnippet* snippet;
    CX_UNUSED(file);

    snippet = NULL;

    if (list) {
        iter = cx_llIter(list);
        while(cx_iterHasNext(&iter)) {
            snippet = cx_iterNext(&iter);
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

cx_string g_fileLookupSnippet(g_file file, cx_string snippetId) {
    return g_fileLookupSnippetIntern(file, snippetId, file->snippets);
}

cx_string g_fileLookupHeader(g_file file, cx_string snippetId) {
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
        cx_object ptr = userData;

        /* Walk object-scope */
        while((ptr = cx_parentof(ptr)) && ptr != _o->o);
        if (ptr) {
            result = 0;
        }
    }

    return result;
}

cx_bool g_mustParse(cx_generator g, cx_object o) {
    cx_bool result;

    result = TRUE;
    if (cx_checkAttr(o, CX_ATTR_SCOPED)) {
        if (cx_llWalk(g->objects, g_checkParseWalk, o)) {
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
void g_fileScopeSet(g_file file, cx_object o) {
    file->scope = o;
}

/* Get scope of file */
cx_object g_fileScopeGet(g_file file) {
    return file->scope;
}

/* Write to file */
void g_fileWrite(g_file file, char* fmt, ...) {
    va_list args;
    cx_char *buffer;
    cx_uint32 len;

    va_start(args, fmt);
    len = vsnprintf(NULL, 0, fmt, args);
    va_end(args);

    if (len) {
        buffer = cx_alloc(len + 1);

        va_start(args, fmt);
        len = vsnprintf(buffer, len + 1, fmt, args);
        va_end(args);

        cx_assert(len == strlen(buffer), "calculated length(%d) does not correspond with length of resulting string(%d)!", len, strlen(buffer));

        /*ptr = buffer;
        while((ptr = strchr(ptr, '\n'))) {
            switch(*(ptr+1)) {
            case '\0':
            case '\n':
                break;
            default:
                cx_error("g_fileWrite: newline characters should be placed at end of string ('%s').", buffer);
                break;
            }
            ptr++;
        }*/

        /* Write indentation & string */
        if (file->indent && file->endLine) {
            if (fprintf(cx_fileGet(file->file), "%*s%s", file->indent * 4, " ", buffer) < 0) {
                cx_error("g_fileWrite: writing to outputfile failed.");
            }
        } else {
            if (fprintf(cx_fileGet(file->file), "%s", buffer) < 0) {
                cx_error("g_fileWrite: writing to outputfile failed.");
            }
        }

        file->endLine = buffer[strlen(buffer)-1] == '\n';

        cx_dealloc(buffer);
    }
}

/* Get generator */
cx_generator g_fileGetGenerator(g_file file) {
    return file->generator;
}


/* Translate names of members so that they can be used in the same scope (for example when used as function parameter) */
typedef struct cx_genWalkMember_t {
    cx_member member;
    cx_uint32 occurred;
}cx_genWalkMember_t;

static cx_uint32 cx_genMemberCacheCount(cx_ll cache, cx_member m) {
    cx_iter memberIter;
    cx_genWalkMember_t *member;
    cx_uint32 result = 0;

    memberIter = cx_llIter(cache);
    while(cx_iterHasNext(&memberIter)) {
        member = cx_iterNext(&memberIter);
        if (!strcmp(cx_nameof(member->member), cx_nameof(m))) {
            result++;
        }
    }

    return result;
}

static cx_uint32 cx_genMemberCacheGet(cx_ll cache, cx_member m) {
    cx_iter memberIter;
    cx_genWalkMember_t *member;
    cx_uint32 result = 0;

    memberIter = cx_llIter(cache);
    while(cx_iterHasNext(&memberIter)) {
        member = cx_iterNext(&memberIter);
        if (member->member == m) {
            result = member->occurred;
            break;
        }
    }

    return result;
}

static cx_int16 cx_genMemberCache_member(cx_serializer s, cx_value *info, void* userData) {
    cx_ll cache;
    CX_UNUSED(s);

    cache = userData;

    if (info->kind == CX_MEMBER) {
        cx_genWalkMember_t *parameter;
        cx_member m = info->is.member.t;

        parameter = cx_alloc(sizeof(cx_genWalkMember_t));
        parameter->member = m;
        parameter->occurred = cx_genMemberCacheCount(cache, m);
        cx_llAppend(cache, parameter);
    } else {
        cx_serializeMembers(s, info, userData);
    }

    return 0;
}

cx_char* cx_genMemberName(cx_generator g, cx_ll cache, cx_member m, cx_char *result) {
    cx_uint32 count;
    cx_id temp;

    if ((count = cx_genMemberCacheGet(cache, m))) {
        sprintf(temp, "%s_%d", cx_nameof(m), count);
    } else {
        strcpy(temp, cx_nameof(m));
    }

    g_id(g, temp, result);

    return result;
}

/* Build cache to determine whether membernames occur more than once (due to inheritance) */
cx_ll cx_genMemberCacheBuild(cx_interface o) {
    struct cx_serializer_s s;
    cx_ll result;

    cx_serializerInit(&s);
    s.access = CX_LOCAL | CX_PRIVATE;
    s.accessKind = CX_NOT;
    s.metaprogram[CX_MEMBER] = cx_genMemberCache_member;
    result = cx_llNew();

    cx_metaWalk(&s, cx_type(o), result);

    return result;
}

void cx_genMemberCacheClean(cx_ll cache) {
    cx_iter memberIter;
    cx_genWalkMember_t *member;

    memberIter = cx_llIter(cache);
    while(cx_iterHasNext(&memberIter)) {
        member = cx_iterNext(&memberIter);
        cx_dealloc(member);
    }
    cx_llFree(cache);
}

#endif


