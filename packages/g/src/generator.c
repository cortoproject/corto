/*
 * g_generator.c
 *
 *  Created on: Sep 17, 2012
 *      Author: sander
 */

#include "corto/g/g.h"

#ifdef CORTO_GENERATOR

/* Generator functions */
g_generator g_new(corto_string name, corto_string language) {
    g_generator result;

    result = corto_alloc(sizeof(struct g_generator_s));

    /* List of output directories is initially empty */
    result->attributes = NULL;

    /* List of files is initially empty */
    result->files = NULL;

    /* No imports are resolved */
    result->imports = NULL;
    result->importsNested = NULL;

    /* Set objects */
    result->objects = NULL;

    /* Set name */
    if (name) {
        result->name = corto_strdup(name);
    } else {
        result->name = NULL;
    }

    if (language) {
        result->language = corto_strdup(language);
    } else {
        result->language = corto_strdup("c"); /* Take 'c' as default language */
    }

    /* Set id-generation to default */
    result->idKind = CORTO_GENERATOR_ID_DEFAULT;

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
g_idKind g_setIdKind(g_generator g, g_idKind kind) {
    g_idKind prev;
    prev = g->idKind;
    g->idKind = kind;
    return prev;
}

/* Get name, or if no name is provided, return name of current parse-object */
corto_string g_getName(g_generator g) {
    corto_string result;

    result = NULL;
    if (g->name) {
        result = g->name;
    } else if (g->current) {
        result = corto_idof(g->current->o);
    }

    return result;
}

/* Get name from generator name (strip path) */
char* g_getProjectName(g_generator g) {
    char *package = g_getName(g);
    char *ptr = &package[strlen(package) - 1];
    while ((ptr != package)) {
        ptr --;
        if (*ptr == '/') {
            ptr ++;
            break;
        }
        if (*ptr == ':') {
            ptr ++;
            break;
        }
    }
    return ptr;
}

/* Get current object */
corto_object g_getCurrent(g_generator g) {
    corto_object result;

    result = NULL;

    if (g->current) {
        result = g->current->o;
    }

    return result;
}

/* Add to-parse object */
void g_parse(g_generator g, corto_object object, corto_bool parseSelf, corto_bool parseScope, corto_string prefix) {
    g_object* o = NULL;
    corto_iter objectIter;

    /* First do a lookup, check if the object already exists */
    if (g->objects) {
        g_object *object;
        objectIter = corto_llIter(g->objects);
        while(corto_iterHasNext(&objectIter)) {
            object = corto_iterNext(&objectIter);
            if (object->o == object) {
                o = object;
                break;
            }
        }
    }

    if (!o) {
        o = corto_alloc(sizeof(g_object));
        corto_claim(object);
        o->o = object;
        o->parseSelf = parseSelf;
        o->parseScope = parseScope;

        if (prefix) {
            if (strlen(prefix) >= sizeof(corto_id)) {
                corto_error("prefix cannot be longer than %d characters", sizeof(corto_id));
                o->prefix = NULL;
            } else {
                o->prefix = corto_strdup(prefix);
            }
        } else {
            o->prefix = NULL;
        }

        if (!g->objects) {
            g->objects = corto_llNew();
        }
        corto_llAppend(g->objects, o);

        if (!g->current) {
            g->current = o;
        }
    } else {
        /* Prefixes can be overridden if NULL. */
        if (!o->prefix) {
            o->prefix = corto_strdup(prefix);
        }
    }
}

static int g_genAttributeFind(void *value, void *userData) {
    g_attribute *attr = value;
    if(!strcmp(attr->key, *(corto_string*)userData)) {
        *(void**)userData = attr;
        return 0;
    }
    return 1;
}

/* Set attribute */
void g_setAttribute(g_generator g, corto_string key, corto_string value) {
    g_attribute* attr = NULL;

    if (!g->attributes) {
        g->attributes = corto_llNew();
    }else {
        void* userData = key;
        if(!corto_llWalk(g->attributes, g_genAttributeFind, &userData)) {
            attr = userData;
        }
    }

    if(!attr) {
        attr = corto_alloc(sizeof(g_attribute));
        attr->key = corto_strdup(key);
        corto_llAppend(g->attributes, attr);
    }else {
        corto_dealloc(attr->value);
    }
    attr->value = corto_strdup(value);
}

/* Get attribute */
corto_string g_getAttribute(g_generator g, corto_string key) {
    corto_string result = NULL;

    if(g->attributes) {
        void *userData = key;
        if(!corto_llWalk(g->attributes, g_genAttributeFind, &userData)) {
            result = ((g_attribute*)userData)->value;
        }
    }

    if (!result) {
        result = "";
    }

    return result;
}

/* Load generator actions from library */
corto_int16 g_load(g_generator g, corto_string library) {

    /* Load library from generator path */
    corto_string package = NULL;
    corto_asprintf(&package, "corto/gen/%s", library);
    corto_string lib = corto_locate(package, CORTO_LOCATION_LIB);
    if (!lib) {
        corto_error("generator '%s' not found", package);
        goto error;
    }

    g->library = corto_dlOpen(lib);
    if (!g->library) {
        corto_error("%s", corto_dlError());
        goto error;
    }

    /* Load actions */
    g->start_action = (g_startAction)corto_dlProc(g->library, "corto_genMain");
    if (!g->start_action) {
        corto_error("g_load: %s: unresolved SYMBOL 'corto_genMain'", lib);
        corto_dealloc(lib);
        goto error;
    }
    g->id_action = (g_idAction)corto_dlProc(g->library, "corto_genId");

    /* Function is allowed to be absent. */

    corto_dealloc(lib);
    corto_dealloc(package);
    return 0;
error:
    corto_dealloc(package);
    return -1;
}

static int g_freeObjects(void* _o, void* udata) {
    g_object* o;

    CORTO_UNUSED(udata);

    o = _o;
    if (o->prefix) {
        corto_dealloc(o->prefix);
    }
    corto_release(o->o);
    corto_dealloc(o);

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
        corto_warning("%s: code-snippet '%s' is not used, manually merge or remove from file.", file->name, snippet->id);
    }

    if (snippet->id) {
        corto_dealloc(snippet->id);
    }
    if (snippet->src) {
        corto_dealloc(snippet->src);
    }

    corto_dealloc(snippet);

    return 1;
}

/* Close file */
static int g_closeFile(void* o, void* udata) {
    g_file file;
    CORTO_UNUSED(udata);

    file = o;

    g_fileClose(file);

    return 1;
}

static int g_freeAttribute(void* _o, void* udata) {
    g_attribute* o;

    CORTO_UNUSED(udata);

    o = _o;
    if (o->key) {
        corto_dealloc(o->key);
    }
    if (o->value) {
        corto_dealloc(o->value);
    }

    corto_dealloc(o);

    return 1;
}

/* Free generator */
void g_free(g_generator g) {
    if (g->library) {
        corto_dlClose(g->library);
        g->library = NULL;
    }

    if (g->objects) {
        corto_llWalk(g->objects, g_freeObjects, NULL);
        corto_llFree(g->objects);
        g->objects = NULL;
    }

    if (g->files) {
        corto_llWalk(g->files, g_closeFile, NULL);
        corto_llFree(g->files);
        g->files = NULL;
    }

    if (g->attributes) {
        corto_llWalk(g->attributes, g_freeAttribute, NULL);
        corto_llFree(g->attributes);
        g->attributes = NULL;
    }

    if (g->imports) {
        corto_llFree(g->imports);
    }

    if (g->name) {
        corto_dealloc(g->name);
    }
    if (g->language) {
        corto_dealloc(g->language);
    }
    corto_dealloc(g);
}

corto_int16 g_loadPrefixes(g_generator g, corto_ll list) {
    corto_iter iter = corto_llIter(list);

    while (corto_iterHasNext(&iter)) {
        corto_object p = corto_iterNext(&iter);
        corto_string prefixFileStr;
        corto_string prefix;
        corto_string includePath =
            corto_locate(
                corto_path(NULL, root_o, p, "/"), CORTO_LOCATION_INCLUDE);

        if (!includePath) {
            corto_seterr("package %s not found", corto_path(NULL, root_o, p, "/"));
            goto error;
        }

        corto_asprintf(&prefixFileStr, "%s/.prefix", includePath);
        prefix = corto_fileLoad(prefixFileStr);
        if (prefix[strlen(prefix) - 1] == '\n') {
            prefix[strlen(prefix) - 1] = '\0';
        }
        if (prefix) {
            g_parse(g, p, FALSE, FALSE, prefix);
        }

        corto_dealloc(prefix);
        corto_dealloc(prefixFileStr);
        corto_dealloc(includePath);
    }

    return 0;
error:
    return -1;
}

/* Start generator */
corto_int16 g_start(g_generator g) {
    /* Find dependent packages, configure associated API prefixes */

    /* Resolve imports based on metadata. */
    if (g_resolveImports(g)) {
        if (!corto_lasterr())  {
            corto_seterr("failed to resolve imports");
        }
        goto error;
    }

    /* packages.txt may contain more packages than is found by looking at the
     * metadata, however no code will be generated based on those packages so
     * they don't have to be configured for code generators */

    /* Find include paths for packages, load prefix file into generator */
    if (g->imports) {
        if (g_loadPrefixes(g, g->imports)) {
            if (!corto_lasterr())  {
                corto_seterr("failed to load package prefixes");
            }
            goto error;
        }
    }
    if (g->importsNested) {
        if (g_loadPrefixes(g, g->importsNested)) {
            if (!corto_lasterr())  {
                corto_seterr("failed to load prefixes for nested packages");
            }
            goto error;
        }
    }

    corto_int16 ret = g->start_action(g);
    if (ret && !corto_lasterr())  {
        corto_seterr("generator failed: %s", corto_lasterr());
    }
    return ret;
error:
    return -1;
}

/* ==== Generator utility functions */
typedef struct g_serializeImports_t {
    g_generator g;
    corto_object stack[1024]; /* Maximum serializer-depth */
    corto_uint32 count;
    corto_bool nested;
}g_serializeImports_t;

corto_int16 g_leafDependencies(
    g_generator g,
    corto_object parent)
{
    corto_string packageDir = corto_locate(
        corto_fullpath(NULL, parent),
        CORTO_LOCATION_LIBPATH
    );

    corto_string packagesTxt;
    corto_asprintf(&packagesTxt, "%s/.corto/packages.txt", packageDir);

    corto_ll deps = corto_loadGetDependencies(packagesTxt);
    if (deps) {
        if (!g->importsNested) {
            g->importsNested = corto_llNew();
        }
        corto_iter it = corto_llIter(deps);
        while (corto_iterHasNext(&it)) {
            corto_string dep = corto_iterNext(&it);
            corto_object o = corto_resolve(NULL, dep);
            if (o) {
                if (!corto_llHasObject(g->importsNested, o)) {
                    corto_llAppend(g->importsNested, o);
                } else {
                    corto_release(o);
                }
            }
        }
        corto_loadFreePackages(deps);
    }

    return 0;
}

corto_int16 g_import(g_generator g, corto_object package) {
    if (!g->imports) {
        g->imports = corto_llNew();
    }
    if (!corto_llHasObject(g->imports, package)) {
        corto_llInsert(g->imports, package);

        /* Recursively obtain imports */
        g_leafDependencies(g, package);
    }

    return 0;
}

corto_int16 g_importsEvalReference(
    g_generator g,
    corto_object o)
{
    if (!g_mustParse(g, o) && (o != g_getCurrent(g))) {
        corto_object parent = o;
        while(parent && !corto_instanceof(corto_type(corto_package_o), parent)) {
            parent = corto_parentof(parent);
        }

        if (parent && (parent != root_o) && !corto_isBuiltinPackage(parent)) {
            if (!g->imports) {
                g->imports = corto_llNew();
            }
            if (!corto_llHasObject(g->imports, parent)) {
                corto_llInsert(g->imports, parent);

                /* Recursively obtain imports */
                g_leafDependencies(g, parent);
            }
        }
    }

    return 0;
}

corto_int16 g_serializeImportsReference(corto_serializer s, corto_value *v, void* userData) {
    corto_object o;
    g_serializeImports_t *data = userData;
    g_generator g = data->g;

    o = *(corto_object*)corto_value_getPtr(v);
    if (o) {
        /* Search unscoped object for references to other modules */
        if (!corto_checkAttr(o, CORTO_ATTR_SCOPED)) {
            corto_uint32 i;

            /* Make sure to not serialize an object twice, in case of a cycle */
            for(i=0; i<data->count; i++) {
                if (data->stack[i] == o) {
                    break;
                }
            }

            if (i == data->count) {
                data->stack[data->count] = o;
                data->count++;
                corto_serialize(s, o, userData);
                data->count--;
            }
        } else {
            g_importsEvalReference(g, o);
        }
    }

    return 0;
}

corto_int16 g_serializeImportsObject(corto_serializer s, corto_value *v, void* userData) {
    g_serializeImports_t *data = userData;

    corto_object o = corto_value_getObject(v);
    g_importsEvalReference(data->g, corto_typeof(o));
    if (corto_checkAttr(o, CORTO_ATTR_SCOPED)) {
        g_importsEvalReference(data->g, corto_parentof(o));
    }
    corto_serializeValue(s, v, userData);

    return 0;
}

struct corto_serializer_s g_serializeImportsSerializer(void) {
    struct corto_serializer_s result;
    corto_serializerInit(&result);
    result.metaprogram[CORTO_OBJECT] = g_serializeImportsObject;
    result.reference = g_serializeImportsReference;
    result.access = CORTO_PRIVATE;
    result.accessKind = CORTO_NOT; /* Serialize not nothing, thus everything. */
    return result;
}

struct g_walkObjects_t {
    g_walkAction action;
    void* userData;
};

/* Resolve imports */
int g_importWalk(corto_object o, void* userData) {
    g_generator g = userData;
    g_serializeImports_t walkData;
    struct corto_serializer_s s;

    walkData.count = 0;
    walkData.g = g;
    walkData.nested = FALSE;
    s = g_serializeImportsSerializer();
    corto_serialize(&s, o, &walkData);

    return 1;
}

corto_int16 g_resolveImports(g_generator generator) {
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

    return corto_scopeWalk(o, g_walkObjects, userData);
stop:
    return 0;
}

/* Walk objects, choose between recursive scopewalk or only top-level objects */
static int g_walk_ext(g_generator g, g_walkAction action, void* userData, corto_bool scopeWalk, corto_bool recursiveWalk) {
    corto_iter iter;

    if (g->objects) {
        g_object* o;

        iter = corto_llIter(g->objects);
        while(corto_iterHasNext(&iter)) {
            o = corto_iterNext(&iter);

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
                    if (!corto_scopeWalk(o->o, action, userData)) {
                        goto stop;
                    }
                } else {
                    struct g_walkObjects_t walkData;
                    walkData.action = action;
                    walkData.userData = userData;

                    /* Recursively walk scopes */
                    if (!corto_scopeWalk(o->o, g_walkObjects, &walkData)) {
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
int g_walk(g_generator g, g_walkAction action, void* userData) {
    return g_walk_ext(g, action, userData, TRUE, FALSE);
}

/* Walk objects, never walk scopes, even if object is required to. */
int g_walkNoScope(g_generator g, g_walkAction action, void* userData) {
    return g_walk_ext(g, action, userData, FALSE, FALSE);
}

/* Walk objects recursively */
int g_walkRecursive(g_generator g, g_walkAction action, void* userData) {
    return g_walk_ext(g, action, userData, TRUE, TRUE);
}

/* Find prefix for a given object. Search parse-object in generator
 * which is closest to the object passed to this function. */
static g_object* g_findObjectIntern(
    g_generator g,
    corto_object o,
    corto_object* match,
    corto_bool inclusive)
{
    corto_iter iter;
    g_object *result, *t;
    corto_object parent;
    unsigned int distance, minDistance;

    result = NULL;
    if (g->objects) {
        minDistance = -1;
        iter = corto_llIter(g->objects);
        while(corto_iterHasNext(&iter)) {
            t = corto_iterNext(&iter);

            /* Check if object occurs in scope of 'o' and measure distance to 'o' */
            parent = o;
            distance = 0;
            while(parent && (parent != t->o)) {
                distance++;
                parent = corto_parentof(parent);
            }

            /* If a parent was found (parent of root is NULL), assign it to result if
             * distance is smaller than minDistance */
            if (parent) {
                if ((distance < minDistance) && (distance || inclusive)) {
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

g_object* g_findObject(
    g_generator g,
    corto_object o,
    corto_object* match)
{
    return g_findObjectIntern(g, o, match, FALSE);
}

g_object* g_findObjectInclusive(
    g_generator g,
    corto_object o,
    corto_object* match)
{
    return g_findObjectIntern(g, o, match, TRUE);
}

/* Obtain prefix */
corto_string g_getPrefix(g_generator g, corto_object o) {
    g_object* prefix;

    /* Lookup prefix */
    prefix = g_findObject(g, o, NULL);

    return (prefix != NULL) ? prefix->prefix : NULL;
}

/* Object transformations */
static corto_char* g_oidTransform(g_generator g, corto_object o, corto_id _id, g_idKind kind) {
    CORTO_UNUSED(g);

    /* If the object is a function with an argumentlist, cut the argumentlist
     * from the name if the function is not overloaded. This keeps processing
     * for generators trivial. */
    if (corto_class_instanceof(corto_procedure_o, corto_typeof(o))) {
        if (!corto_function(o)->overloaded) {
            corto_char* ptr;
            ptr = strchr(_id, '(');
            if (ptr) {
                *ptr = '\0';
            }
        } else {
            /* If function is overloaded, construct the 'request' string, that
             * is, the string without the argument-names. This results in a
             * string with only the types, which is enough to generate unique
             * names in languages which do not support overloading. */
            corto_id tmp, buff;
            corto_int32 count, i;
            strcpy(tmp, _id);

            corto_signatureName(tmp, _id);
            strcat(_id, "(");

            count = corto_signatureParamCount(tmp);
            if (count == -1) {
                corto_error("invalid signature '%s'", tmp);
                goto error;
            }

            /* strcat is not the most efficient function here, but it is the easiest, and this
             * part of the code is not performance-critical. */
            for(i=0; i<count; i++) {
                corto_signatureParamType(tmp, i, buff, NULL);
                if (i) {
                    strcat(_id, ",");
                }
                strcat(_id, buff);
            }
            strcat(_id, ")");
        }
    }

    /* Check if class-identifiers must be altered */
    if (kind != CORTO_GENERATOR_ID_DEFAULT) {
        corto_object i = o;
        corto_char* ptr;

        ptr = _id + strlen(_id);
        while(i) {
            while((ptr > _id) && (*ptr != '/')) {
                ptr--;
            }
            if ((corto_class_instanceof(corto_interface_o, i) && corto_type(i)->reference) || (i == corto_type(corto_object_o))) {
                corto_char *start = ptr;
                if (kind == CORTO_GENERATOR_ID_CLASS_UPPER) {
                    *start = toupper(*start);
                } else {
                    *start = tolower(*start);
                }
            }

            if (ptr == _id) {
                break;
            }

            i = corto_parentof(i);
            if (i) {
                if (*ptr == '/') {
                    ptr -= 1;
                }
            }
        }
    }

    return _id;
error:
    return NULL;
}

/* Translate object-id */
corto_string g_fullOidExt(g_generator g, corto_object o, corto_id id, g_idKind kind) {
    g_object* prefix;
    corto_object match;
    corto_id _id;

    id[0] = '\0';

    /* Find prefix for object */
    match = NULL;
    prefix = g_findObject(g, o, &match);

    /* TODO: prefix i.c.m. !CORTO_GENERATOR_ID_DEFAULT & nested classes i.c.m. !CORTO_GENERATOR_ID_DEFAULT */

    /* If prefix is found, replace the scope up until the found object with the prefix */
    if (prefix && prefix->prefix) {
        if (strcmp(prefix->prefix, ".")) {
            corto_uint32 count;
            corto_object scopes[CORTO_MAX_SCOPE_DEPTH];

            /* Obtain list of scopes from matched to object */
            count = 0;
            scopes[count] = o;
            while(scopes[count] != match) {
                scopes[count+1] = corto_parentof(scopes[count]);
                count++;
            }

            /* Paste in prefix */
            strcpy(_id, prefix->prefix);
            while(count) {
                count--;
                strcat(_id, "/");
                strcat(_id, corto_idof(scopes[count]));
            }
        } else {
            corto_path(_id, g_getCurrent(g), o, "/");
        }
    /* If no prefix is found for object, just use the scoped identifier */
    } else {
        corto_fullpath(_id, o);
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
corto_string g_fullOid(g_generator g, corto_object o, corto_id id) {
    return g_fullOidExt(g, o, id, g->idKind);
}

/* Translate an id to language representation */
corto_string g_id(g_generator g, corto_string str, corto_id id) {
    corto_string result;

    if (g->id_action) {
        result = g->id_action(str, id);
    } else {
        result = str;
    }

    return result;
}

/* Translate a class id to language representation */
corto_string g_oid(g_generator g, corto_object o, corto_id id) {
    corto_string result;
    corto_id cid;
    g_object* prefix;
    corto_object match;

    /* Find prefix for object */
    match = NULL;
    prefix = g_findObject(g, o, &match);

   /* If prefix is found, replace the scope up until the found object with the prefix */
    if (prefix && prefix->prefix) {
        if (prefix->o == o) {
            strcpy(cid, prefix->prefix);
        } else {
            strcpy(cid, corto_idof(o));
        }

    /* If no prefix is found for object, just use the identifier */
    } else {
        strcpy(cid, corto_idof(o));
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
static corto_string g_filePath(g_generator g, corto_string filename, corto_char* buffer) {
    corto_string result;
    corto_id path;

    result = filename;

    if (g->attributes) {
        corto_string ext = NULL;
        corto_string fext, ptr;

        /* Get file-extension */
        fext = NULL;
        ptr = filename;
        while((ptr = strchr(ptr, '.'))) {
            ptr++;
            fext = ptr;
        }

        /* Check whether there is an attribute with the file extension - determines where to put the file */
        if(fext) {
            ext = g_getAttribute(g, fext);
        }

        /* Append filename to location. */
        if (ext && *ext) {
            sprintf(buffer, "%s/%s", ext, filename);
            result = buffer;
        }
    }

    /* Ensure path exists */
    if (corto_filePath(result, path)) {
        if (corto_mkdir(path)) {
            goto error;
        }
    }

    return result;
error:
    return NULL;
}

/* Find existing parts in the code that must not be overwritten. */
corto_int16 g_loadExisting(g_generator g, corto_string name, corto_string option, corto_ll *list) {
    corto_string code = NULL, ptr = NULL;
    CORTO_UNUSED(g);

    if (!corto_fileTest(name)) {

        /* Check if there is a .old file that can be restored */
        corto_id oldName;
        sprintf(oldName, "%s.old", name);
        if (corto_fileTest(oldName)) {
            if (corto_rename(oldName, name)) {
                corto_warning("could not rename '%s' to '%s': %s", oldName, name, corto_lasterr());
                goto ok;
            }
        } else {
            goto ok;
        }
    }

    code = corto_fileLoad(name);
    if (code) {
        ptr = code;

        while((ptr = strstr(ptr, option))) {
            ptr += strlen(option);

            /* Find begin of identifier */
            if (*ptr == '(') {
                corto_string endptr;

                /* Find end of identifier */
                endptr = strstr(ptr, ") */");
                if (endptr) {
                    corto_id identifier;

                    /* Copy identifier string */
                    *endptr = '\0';

                    if (strlen(ptr) >= sizeof(corto_id)) {
                        corto_error(
                            "%s: identifier of code-snippet exceeds %d characters", sizeof(corto_id));
                        goto error;
                    }

                    strcpy(identifier, ptr + 1);
                    ptr = endptr + 1;

                    /* Find $end */
                    endptr = strstr(ptr, "$end");
                    if (endptr) {
                        g_fileSnippet* existing;
                        corto_string src;

                        *endptr = '\0';
                        src = corto_strdup(ptr);

                        if (!*list) {
                            *list = corto_llNew();
                        }

                        if(strstr(src, "$begin")) {
                            corto_error("%s: code-snippet '%s(%s)' contains nested $begin (did you forget an $end?)",
                                name, option, identifier);
                            corto_dealloc(src);
                            goto error;
                        }

                        existing = corto_alloc(sizeof(g_fileSnippet));
                        existing->option = corto_strdup(option);
                        existing->id = corto_strdup(identifier);
                        existing->src = src;
                        existing->used = FALSE;
                        corto_llInsert(*list, existing);

                        ptr = endptr + 1;

                    } else {
                        corto_warning("generator: missing $end after $begin(%s)", identifier);
                    }
                } else {
                    corto_warning("generator: missing ')' after %s(", option);
                }
            } else {
                corto_warning("generator: missing '(' after %s.", option);
            }
        }
        corto_dealloc(code);
    } else {
        /* Catch error */
        corto_lasterr();
    }

ok:
    return 0;
error:
    if (code) {
        corto_dealloc(code);
    }
    return -1;
}

void g_fileClose(g_file file) {
    /* Remove file from generator administration */
    corto_llRemove(file->generator->files, file);

    /* Free snippets */
    if (file->snippets) {
        corto_llWalk(file->snippets, g_freeSnippet, file);
        corto_llFree(file->snippets);
    }
    if (file->headers) {
        corto_llWalk(file->headers, g_freeSnippet, file);
        corto_llFree(file->headers);
    }

    corto_fileClose(file->file);
    corto_dealloc(file->name);
    corto_dealloc(file);
}

static g_file g_fileOpenIntern(g_generator g, corto_string name) {
    g_file result;
    char ext[255];

    result = corto_alloc(sizeof(struct g_file_s));
    result->snippets = NULL;
    result->headers = NULL;
    result->scope = NULL;
    result->file = NULL;
    result->indent = 0;
    result->name = corto_strdup(name);
    result->generator = g;

    corto_fileExtension(name, ext);

    /* First, load existing implementation if file exists */
    if (!strcmp(ext, "c") || !strcmp(ext, "cpp") || !strcmp(ext, "h") || !strcmp(ext, "hpp")) {
        if (g_loadExisting(g, name, "$header", &result->headers)) {
            corto_dealloc(result);
            goto error;
        }
        if (g_loadExisting(g, name, "$begin", &result->snippets)) {
            corto_dealloc(result);
            goto error;
        }
    }

    result->file = corto_fileOpen(name);
    if (!result->file) {
        corto_dealloc(result);
        goto error;
    }

    if (!g->files) {
        g->files = corto_llNew();
    }
    corto_llInsert(g->files, result);

    return result;
error:
    corto_seterr("failed to open file '%s'", name);
    abort();
    return NULL;
}

/* Open file */
g_file g_fileOpen(g_generator g, corto_string name, ...) {
    corto_char filepath[512];
    corto_char namebuffer[512];
    va_list args;
    va_start(args, name);
    vsprintf(namebuffer, name, args);
    va_end(args);
    return g_fileOpenIntern(g, g_filePath(g, namebuffer, filepath));
}

/* Open hidden file for writing. */
g_file g_hiddenFileOpen(g_generator g, corto_string name, ...) {
    corto_char filepath[512];
    corto_char namebuffer[512];
    va_list args;
    va_start(args, name);
    vsprintf(namebuffer, name, args);
    va_end(args);
    sprintf(filepath, ".corto/%s", namebuffer);
    return g_fileOpenIntern(g, filepath);
}

/* Lookup an existing code-snippet */
corto_string g_fileLookupSnippetIntern(g_file file, corto_string snippetId, corto_ll list) {
    corto_iter iter;
    g_fileSnippet* snippet;
    CORTO_UNUSED(file);

    snippet = NULL;

    if (list) {
        iter = corto_llIter(list);
        while(corto_iterHasNext(&iter)) {
            snippet = corto_iterNext(&iter);
            corto_id path; strcpy(path, snippet->id);
            char *snippetPtr = path;

            /* Temporary workaroud: translate deprecated '::' to '/' */
            corto_pathFromFullname(path);

            /* Ignore initial scope character */
            if (*snippetPtr == '/') {
                snippetPtr = path + 1;
            }

            if (*snippetId == '/') {
                snippetId ++;
            }

            if (!stricmp(snippetPtr, snippetId) || !strcmp(path, snippetId)) {
                snippet->used = TRUE;
                break;
            } else {
                snippet = NULL;
            }
        }
    }

    return snippet ? snippet->src : NULL;
}

corto_string g_fileLookupSnippet(g_file file, corto_string snippetId) {
    return g_fileLookupSnippetIntern(file, snippetId, file->snippets);
}

corto_string g_fileLookupHeader(g_file file, corto_string snippetId) {
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
        corto_object ptr = userData;

        /* Walk object-scope */
        while((ptr = corto_parentof(ptr)) && (ptr != _o->o));
        if (ptr) {
            result = 0;
        }
    }

    return result;
}

corto_bool g_mustParse(g_generator g, corto_object o) {
    corto_bool result;

    result = TRUE;
    if (corto_checkAttr(o, CORTO_ATTR_SCOPED) && corto_childof(root_o, o)) {
        if (corto_llWalk(g->objects, g_checkParseWalk, o)) {
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
void g_fileScopeSet(g_file file, corto_object o) {
    file->scope = o;
}

/* Get scope of file */
corto_object g_fileScopeGet(g_file file) {
    return file->scope;
}

/* Write to file */
int g_fileWrite(g_file file, char* fmt, ...) {
    va_list args;
    corto_char *buffer = NULL;

    va_start(args, fmt);
    corto_vasprintf(&buffer, fmt, args);
    va_end(args);

    /* Write indentation & string */
    if (file->indent && file->endLine) {
        if (fprintf(corto_fileGet(file->file), "%*s%s", file->indent * 4, " ", buffer) < 0) {
            corto_seterr("g_fileWrite: writing to outputfile failed.");
            goto error;
        }
    } else {
        if (fprintf(corto_fileGet(file->file), "%s", buffer) < 0) {
            corto_seterr("g_fileWrite: writing to outputfile failed.");
            goto error;
        }
    }

    file->endLine = buffer[strlen(buffer)-1] == '\n';

    corto_dealloc(buffer);

    return 0;
error:
    return -1;
}

/* Get generator */
g_generator g_fileGetGenerator(g_file file) {
    return file->generator;
}


/* Translate names of members so that they can be used in the same scope (for example when used as function parameter) */
typedef struct corto_genWalkMember_t {
    corto_member member;
    corto_uint32 occurred;
}corto_genWalkMember_t;

static corto_uint32 corto_genMemberCacheCount(corto_ll cache, corto_member m) {
    corto_iter memberIter;
    corto_genWalkMember_t *member;
    corto_uint32 result = 0;

    memberIter = corto_llIter(cache);
    while(corto_iterHasNext(&memberIter)) {
        member = corto_iterNext(&memberIter);
        if (!strcmp(corto_idof(member->member), corto_idof(m))) {
            result++;
        }
    }

    return result;
}

static corto_uint32 corto_genMemberCacheGet(corto_ll cache, corto_member m) {
    corto_iter memberIter;
    corto_genWalkMember_t *member;
    corto_uint32 result = 0;

    memberIter = corto_llIter(cache);
    while(corto_iterHasNext(&memberIter)) {
        member = corto_iterNext(&memberIter);
        if (member->member == m) {
            result = member->occurred;
            break;
        }
    }

    return result;
}

static corto_int16 corto_genMemberCache_member(corto_serializer s, corto_value *info, void* userData) {
    corto_ll cache;
    CORTO_UNUSED(s);

    cache = userData;

    if (info->kind == CORTO_MEMBER) {
        corto_genWalkMember_t *parameter;
        corto_member m = info->is.member.t;

        parameter = corto_alloc(sizeof(corto_genWalkMember_t));
        parameter->member = m;
        parameter->occurred = corto_genMemberCacheCount(cache, m);
        corto_llAppend(cache, parameter);
    } else {
        corto_serializeMembers(s, info, userData);
    }

    return 0;
}

corto_char* corto_genMemberName(g_generator g, corto_ll cache, corto_member m, corto_char *result) {
    corto_uint32 count;
    corto_id temp;

    if ((count = corto_genMemberCacheGet(cache, m))) {
        sprintf(temp, "%s_%d", corto_idof(m), count);
    } else {
        strcpy(temp, corto_idof(m));
    }

    g_id(g, temp, result);

    return result;
}

/* Build cache to determine whether membernames occur more than once (due to inheritance) */
corto_ll corto_genMemberCacheBuild(corto_interface o) {
    struct corto_serializer_s s;
    corto_ll result;

    corto_serializerInit(&s);
    s.access = CORTO_LOCAL | CORTO_PRIVATE;
    s.accessKind = CORTO_NOT;
    s.metaprogram[CORTO_MEMBER] = corto_genMemberCache_member;
    result = corto_llNew();

    corto_metaWalk(&s, corto_type(o), result);

    return result;
}

void corto_genMemberCacheClean(corto_ll cache) {
    corto_iter memberIter;
    corto_genWalkMember_t *member;

    memberIter = corto_llIter(cache);
    while(corto_iterHasNext(&memberIter)) {
        member = corto_iterNext(&memberIter);
        corto_dealloc(member);
    }
    corto_llFree(cache);
}

#endif
