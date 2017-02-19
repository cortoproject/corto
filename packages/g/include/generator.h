/*
 * g_generator.h
 *
 *  Created on: Sep 17, 2012
 *      Author: sander
 */

#ifndef CORTO_GEN_H_
#define CORTO_GEN_H_

#include "corto/lang/_type.h"
#include "corto/file.h"
#include "corto/dl.h"

#ifdef __cplusplus
extern "C" {
#endif

CORTO_CLASS(g_generator);

typedef int (*g_walkAction)(corto_object o, void* userData);
typedef corto_string ___ (*g_idAction)(corto_string in, corto_id out);
typedef corto_int16 ___ (*g_startAction)(g_generator g);
typedef void (*g_stopAction)(g_generator g);

CORTO_STRUCT(g_object);
CORTO_STRUCT_DEF(g_object) {
    corto_object o;
    corto_bool parseSelf;
    corto_bool parseScope;
    corto_string prefix;
};

CORTO_STRUCT(g_attribute);
CORTO_STRUCT_DEF(g_attribute) {
    corto_string key;
    corto_string value;
};

typedef enum g_idKind {
    CORTO_GENERATOR_ID_DEFAULT,
    CORTO_GENERATOR_ID_CLASS_UPPER,
    CORTO_GENERATOR_ID_CLASS_LOWER
}g_idKind;

CORTO_CLASS_DEF(g_generator) {
    corto_ll objects;
    corto_ll files;
    corto_dl library;
    corto_ll imports;
    corto_ll importsNested; /* Indirect imports must be loaded for prefixes */
    corto_string name;
    corto_string language;
    g_idKind idKind;
    corto_ll attributes; /* list<generatorAttribute> */

    g_startAction start_action;
    g_idAction id_action;

    g_object* current;
};

typedef struct g_fileSnippet {
    corto_string option;
    corto_string id;
    corto_string src;
    corto_bool used;
}g_fileSnippet;

CORTO_CLASS(g_file);
CORTO_CLASS_DEF(g_file) {
    corto_file file;
    corto_string name;
    corto_uint32 indent;
    corto_object scope;
    corto_bool endLine; /* If last written character was a '\n', the next write must insert indentation spaces. */
    corto_ll snippets; /* If file already exists, load existing snippets. */
    corto_ll headers; /* If file already exists, load existing headers-snippets */
    g_generator generator;
};

/* Create generator object. */
CORTO_EXPORT g_generator g_new(corto_string name, corto_string language);

/* Control how id's are generated */
CORTO_EXPORT g_idKind g_setIdKind(g_generator g, g_idKind kind);

/* Obtain generator name. */
CORTO_EXPORT corto_string g_getName(g_generator g);

/* Obtain project name */
CORTO_EXPORT corto_string g_getProjectName(g_generator g);

/* Obtain generator object that is currently parsed. */
CORTO_EXPORT corto_object g_getCurrent(g_generator g);

/* Get generator language. */
CORTO_EXPORT corto_string g_getLanguage(g_generator g);

/* Instruct the generator to generate for an object. */
CORTO_EXPORT void g_parse(g_generator generator, corto_object object, corto_bool parseSelf, corto_bool parseScope, corto_string prefix);

/* Set attribute of generator */
CORTO_EXPORT void g_setAttribute(g_generator g, corto_string key, corto_string value);

/* Get attribute from generator */
CORTO_EXPORT corto_string g_getAttribute(g_generator g, corto_string key);

/* Load a generator library. */
CORTO_EXPORT corto_int16 g_load(g_generator generator, corto_string library);

/* Free generator. */
CORTO_EXPORT void g_free(g_generator generator);

/* Start generating. */
CORTO_EXPORT corto_int16 g_start(g_generator generator);

/* === Generator utility functions */

/* Add import */
CORTO_EXPORT corto_int16 g_import(g_generator generator, corto_object package);

/* Walk generator objects. Parse scopes of generator objects when configured. */
CORTO_EXPORT int g_walk(g_generator generator, g_walkAction o, void* userData);

/* Walk generator objects, do not parse scopes even if configured. */
CORTO_EXPORT int g_walkNoScope(g_generator g, g_walkAction action, void* userData);

/* Recursively walk objects, will walk all objects under the scope of generator objects. */
CORTO_EXPORT int g_walkRecursive(g_generator generator, g_walkAction o, void* userData);

/* Find generator object for object */
CORTO_EXPORT g_object* g_findObject(g_generator g, corto_object o, corto_object* match);
CORTO_EXPORT g_object* g_findObjectInclusive(g_generator g, corto_object o, corto_object* match);

/* Lookup prefix for object. */
CORTO_EXPORT corto_string g_getPrefix(g_generator g, corto_object o);

/* Translate an object to a language-specific identifier. */
CORTO_EXPORT corto_string g_fullOid(g_generator g, corto_object o, corto_id id);

/* Translate an object to a language-specific identifier with idKind provided. */
CORTO_EXPORT corto_string g_fullOidExt(g_generator g, corto_object o, corto_id id, g_idKind kind);

/* Translate an class-identifier to a language-specific identifier. */
CORTO_EXPORT corto_string g_oid(g_generator g, corto_object o, corto_id id);

/* Translate an identifier to a language-specific identifier. */
CORTO_EXPORT corto_string g_id(g_generator g, corto_string str, corto_id id);

/* A check on whether an object must be parsed or not. */
CORTO_EXPORT corto_bool g_mustParse(g_generator g, corto_object o);


/* === Generator file-utility class */

/* Open a file for writing. */
CORTO_EXPORT g_file g_fileOpen(g_generator generator, corto_string name, ...);

/* Open hidden file for writing. */
CORTO_EXPORT g_file g_hiddenFileOpen(g_generator generator, corto_string name, ...);

/* Close a file. */
CORTO_EXPORT void g_fileClose(g_file file);

/* Return contents of a file. */
CORTO_EXPORT corto_string g_fileRead(g_generator generator, corto_string name);

/* Lookup an open file. */
CORTO_EXPORT void g_fileGet(g_generator generator, corto_string name);

/* Lookup an existing code-snippet */
CORTO_EXPORT corto_string g_fileLookupSnippet(g_file file, corto_string snippetId);

/* Lookup an existing code-header */
CORTO_EXPORT corto_string g_fileLookupHeader(g_file file, corto_string snippetId);

/* Increase indentation. */
CORTO_EXPORT void g_fileIndent(g_file file);

/* Decrease indentation. */
CORTO_EXPORT void g_fileDedent(g_file file);

/* Set scope of file */
CORTO_EXPORT void g_fileScopeSet(g_file file, corto_object o);

/* Get scope of file */
CORTO_EXPORT corto_object g_fileScopeGet(g_file file);

/* Write to a file. */
CORTO_EXPORT int g_fileWrite(g_file file, char* fmt, ...);

/* Get generator */
CORTO_EXPORT g_generator g_fileGetGenerator(g_file file);


/* == Generator unique name-generator for members utility */

/* Get name of member */
CORTO_EXPORT corto_char* corto_genMemberName(g_generator g, corto_ll cache, corto_member m, corto_char *result);

/* Build cache to determine whether membernames occur more than once (due to inheritance) */
CORTO_EXPORT corto_ll corto_genMemberCacheBuild(corto_interface o);

/* Clean cache */
CORTO_EXPORT void corto_genMemberCacheClean(corto_ll cache);


#ifdef __cplusplus
}
#endif

#endif /* CORTO_GEN_H_ */
