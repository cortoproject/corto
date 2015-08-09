/*
 * cx_generator.h
 *
 *  Created on: Sep 17, 2012
 *      Author: sander
 */

#ifndef CX_GEN_H_
#define CX_GEN_H_

#include "cx__type.h"
#include "cx_file.h"
#include "cx_dl.h"

#ifdef __cplusplus
extern "C" {
#endif

CX_CLASS(cx_generator);

typedef int (*g_walkAction)(cx_object o, void* userData);
typedef cx_string (*g_idAction)(cx_string in, cx_id out);
typedef cx_int16 (*g_startAction)(cx_generator g);
typedef void (*g_stopAction)(cx_generator g);

CX_STRUCT(g_object);
CX_STRUCT_DEF(g_object) {
    cx_object o;
    cx_bool parseSelf;
    cx_bool parseScope;
    cx_string prefix;
};

CX_STRUCT(g_attribute);
CX_STRUCT_DEF(g_attribute) {
    cx_string key;
    cx_string value;
};

typedef enum g_idKind {
    CX_GENERATOR_ID_DEFAULT,
    CX_GENERATOR_ID_CLASS_UPPER,
    CX_GENERATOR_ID_CLASS_LOWER
}g_idKind;

CX_CLASS_DEF(cx_generator) {
    cx_ll objects;
    cx_ll files;
    cx_dl library;
    cx_ll imports;
    cx_string name;
    cx_string language;
    g_idKind idKind;
    cx_ll attributes; /* list<generatorAttribute> */
 
    g_startAction start_action;
    g_idAction id_action;

    g_object* current;
};

typedef struct g_fileSnippet {
    cx_string option;
    cx_string id;
    cx_string src;
    cx_bool used;
}g_fileSnippet;

CX_CLASS(g_file);
CX_CLASS_DEF(g_file) {
    cx_file file;
    cx_string name;
    cx_uint32 indent;
    cx_object scope;
    cx_bool endLine; /* If last written character was a '\n', the next write must insert indentation spaces. */
    cx_ll snippets; /* If file already exists, load existing snippets. */
    cx_ll headers; /* If file already exists, load existing headers-snippets */
    cx_generator generator;
};

/* Create generator object. */
cx_generator gen_new(cx_string name, cx_string language);

/* Control how id's are generated */
g_idKind g_setIdKind(cx_generator g, g_idKind kind);

/* Obtain generator name. */
cx_string g_getName(cx_generator g);

/* Obtain generator object that is currently parsed. */
cx_object g_getCurrent(cx_generator g);

/* Get generator language. */
cx_string g_getLanguage(cx_generator g);

/* Instruct the generator to generate for an object. */
void gen_parse(cx_generator generator, cx_object object, cx_bool parseSelf, cx_bool parseScope, cx_string prefix);

/* Set attribute of generator */
void gen_setAttribute(cx_generator g, cx_string key, cx_string value);

/* Get attribute from generator */
cx_string gen_getAttribute(cx_generator g, cx_string key);

/* Load a generator library. */
cx_int16 gen_load(cx_generator generator, cx_string library);

/* Free generator. */
void gen_free(cx_generator generator);

/* Start generating. */
cx_int16 gen_start(cx_generator generator);

/* === Generator utility functions */

/* Resolve imports */
cx_int16 g_resolveImports(cx_generator generator);

/* Walk generator objects. Parse scopes of generator objects when configured. */
int g_walk(cx_generator generator, g_walkAction o, void* userData);

/* Walk generator objects, do not parse scopes even if configured. */
int g_walkNoScope(cx_generator g, g_walkAction action, void* userData);

/* Recursively walk objects, will walk all objects under the scope of generator objects. */
int g_walkRecursive(cx_generator generator, g_walkAction o, void* userData);

/* Lookup prefix for object. */
cx_string g_getPrefix(cx_generator g, cx_object o);

/* Translate an object to a language-specific identifier. */
cx_string g_fullOid(cx_generator g, cx_object o, cx_id id);

/* Translate an object to a language-specific identifier with idKind provided. */
cx_string g_fullOidExt(cx_generator g, cx_object o, cx_id id, g_idKind kind);

/* Translate an class-identifier to a language-specific identifier. */
cx_string g_oid(cx_generator g, cx_object o, cx_id id);

/* Translate an identifier to a language-specific identifier. */
cx_string g_id(cx_generator g, cx_string str, cx_id id);

/* A check on whether an object must be parsed or not. */
cx_bool g_mustParse(cx_generator g, cx_object o);


/* === Generator file-utility class */

/* Open a file for writing. */
g_file g_fileOpen(cx_generator generator, cx_string name);

/* Open hidden file for writing. */
g_file g_hiddenFileOpen(cx_generator generator, cx_string name);

/* Close a file. */
void g_fileClose(g_file file);

/* Return contents of a file. */
cx_string g_fileRead(cx_generator generator, cx_string name);

/* Lookup an open file. */
void g_fileGet(cx_generator generator, cx_string name);

/* Lookup an existing code-snippet */
cx_string g_fileLookupSnippet(g_file file, cx_string snippetId);

/* Lookup an existing code-header */
cx_string g_fileLookupHeader(g_file file, cx_string snippetId);

/* Increase indentation. */
void g_fileIndent(g_file file);

/* Decrease indentation. */
void g_fileDedent(g_file file);

/* Set scope of file */
void g_fileScopeSet(g_file file, cx_object o);

/* Get scope of file */
cx_object g_fileScopeGet(g_file file);

/* Write to a file. */
void g_fileWrite(g_file file, char* fmt, ...);

/* Get generator */
cx_generator g_fileGetGenerator(g_file file);


/* == Generator unique name-generator for members utility */

/* Get name of member */
cx_char* cx_genMemberName(cx_generator g, cx_ll cache, cx_member m, cx_char *result);

/* Build cache to determine whether membernames occur more than once (due to inheritance) */
cx_ll cx_genMemberCacheBuild(cx_interface o);

/* Clean cache */
void cx_genMemberCacheClean(cx_ll cache);


#ifdef __cplusplus
}
#endif

#endif /* CX_GEN_H_ */
