/*
 * corto_generator.h
 *
 *  Created on: Sep 17, 2012
 *      Author: sander
 */

#ifndef CORTO_GEN_H_
#define CORTO_GEN_H_

#include "corto/lang/lang__type.h"
#include "corto/file.h"
#include "corto/dl.h"

#ifdef __cplusplus
extern "C" {
#endif

CORTO_CLASS(corto_generator);

typedef int (*g_walkAction)(corto_object o, void* userData);
typedef corto_string ___ (*g_idAction)(corto_string in, corto_id out);
typedef corto_int16 ___ (*g_startAction)(corto_generator g);
typedef void (*g_stopAction)(corto_generator g);

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

CORTO_CLASS_DEF(corto_generator) {
    corto_ll objects;
    corto_ll files;
    corto_dl library;
    corto_ll imports;
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
    corto_generator generator;
};

/* Create generator object. */
corto_generator gen_new(corto_string name, corto_string language);

/* Control how id's are generated */
g_idKind g_setIdKind(corto_generator g, g_idKind kind);

/* Obtain generator name. */
corto_string g_getName(corto_generator g);

/* Obtain generator object that is currently parsed. */
corto_object g_getCurrent(corto_generator g);

/* Get generator language. */
corto_string g_getLanguage(corto_generator g);

/* Instruct the generator to generate for an object. */
void gen_parse(corto_generator generator, corto_object object, corto_bool parseSelf, corto_bool parseScope, corto_string prefix);

/* Set attribute of generator */
void gen_setAttribute(corto_generator g, corto_string key, corto_string value);

/* Get attribute from generator */
corto_string gen_getAttribute(corto_generator g, corto_string key);

/* Load a generator library. */
corto_int16 gen_load(corto_generator generator, corto_string library);

/* Free generator. */
void gen_free(corto_generator generator);

/* Start generating. */
corto_int16 gen_start(corto_generator generator);

/* === Generator utility functions */

/* Resolve imports */
corto_int16 g_resolveImports(corto_generator generator);

/* Walk generator objects. Parse scopes of generator objects when configured. */
int g_walk(corto_generator generator, g_walkAction o, void* userData);

/* Walk generator objects, do not parse scopes even if configured. */
int g_walkNoScope(corto_generator g, g_walkAction action, void* userData);

/* Recursively walk objects, will walk all objects under the scope of generator objects. */
int g_walkRecursive(corto_generator generator, g_walkAction o, void* userData);

/* Lookup prefix for object. */
corto_string g_getPrefix(corto_generator g, corto_object o);

/* Translate an object to a language-specific identifier. */
corto_string g_fullOid(corto_generator g, corto_object o, corto_id id);

/* Translate an object to a language-specific identifier with idKind provided. */
corto_string g_fullOidExt(corto_generator g, corto_object o, corto_id id, g_idKind kind);

/* Translate an class-identifier to a language-specific identifier. */
corto_string g_oid(corto_generator g, corto_object o, corto_id id);

/* Translate an identifier to a language-specific identifier. */
corto_string g_id(corto_generator g, corto_string str, corto_id id);

/* A check on whether an object must be parsed or not. */
corto_bool g_mustParse(corto_generator g, corto_object o);


/* === Generator file-utility class */

/* Open a file for writing. */
g_file g_fileOpen(corto_generator generator, corto_string name);

/* Open hidden file for writing. */
g_file g_hiddenFileOpen(corto_generator generator, corto_string name);

/* Close a file. */
void g_fileClose(g_file file);

/* Return contents of a file. */
corto_string g_fileRead(corto_generator generator, corto_string name);

/* Lookup an open file. */
void g_fileGet(corto_generator generator, corto_string name);

/* Lookup an existing code-snippet */
corto_string g_fileLookupSnippet(g_file file, corto_string snippetId);

/* Lookup an existing code-header */
corto_string g_fileLookupHeader(g_file file, corto_string snippetId);

/* Increase indentation. */
void g_fileIndent(g_file file);

/* Decrease indentation. */
void g_fileDedent(g_file file);

/* Set scope of file */
void g_fileScopeSet(g_file file, corto_object o);

/* Get scope of file */
corto_object g_fileScopeGet(g_file file);

/* Write to a file. */
int g_fileWrite(g_file file, char* fmt, ...);

/* Get generator */
corto_generator g_fileGetGenerator(g_file file);


/* == Generator unique name-generator for members utility */

/* Get name of member */
corto_char* corto_genMemberName(corto_generator g, corto_ll cache, corto_member m, corto_char *result);

/* Build cache to determine whether membernames occur more than once (due to inheritance) */
corto_ll corto_genMemberCacheBuild(corto_interface o);

/* Clean cache */
void corto_genMemberCacheClean(corto_ll cache);


#ifdef __cplusplus
}
#endif

#endif /* CORTO_GEN_H_ */
