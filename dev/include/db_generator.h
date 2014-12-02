/*
 * db_generator.h
 *
 *  Created on: Sep 17, 2012
 *      Author: sander
 */

#ifndef DB_GEN_H_
#define DB_GEN_H_

#include "db.h"
#include "db_file.h"
#include "db_dl.h"

#ifdef __cplusplus
extern "C" {
#endif

DB_CLASS(db_generator);

typedef int (*g_walkAction)(db_object o, void* userData);
typedef db_string (*g_idAction)(db_string in, db_id out);
typedef db_int16 (*g_startAction)(db_generator g);
typedef void (*g_stopAction)(db_generator g);

DB_STRUCT(g_object);
DB_STRUCT_DEF(g_object) {
    db_object o;
    db_bool parseSelf;
    db_bool parseScope;
    db_string prefix;
};

DB_STRUCT(g_attribute);
DB_STRUCT_DEF(g_attribute) {
    db_string key;
    db_string value;
};

typedef enum g_idKind {
	DB_GENERATOR_ID_DEFAULT,
	DB_GENERATOR_ID_CLASS_UPPER,
	DB_GENERATOR_ID_CLASS_LOWER
}g_idKind;

DB_CLASS_DEF(db_generator) {
    db_ll objects;
    db_ll files;
    db_dl library;
    db_ll imports;
    db_string name;
    db_string language;
    g_idKind idKind;
    db_ll attributes; /* list<generatorAttribute> */
 
    g_startAction start_action;
    g_idAction id_action;

    g_object* current;
};

typedef struct g_fileSnippet {
	db_string option;
    db_string id;
    db_string src;
    db_bool used;
}g_fileSnippet;

DB_CLASS(g_file);
DB_CLASS_DEF(g_file) {
    db_file file;
    db_string name;
    db_uint32 indent;
    db_object scope;
    db_bool endLine; /* If last written character was a '\n', the next write must insert indentation spaces. */
    db_ll snippets; /* If file already exists, load existing snippets. */
    db_ll headers; /* If file already exists, load existing headers-snippets */
    db_generator generator;
};

/* Create generator object. */
db_generator gen_new(db_string name, db_string language);

/* Control how id's are generated */
g_idKind g_setIdKind(db_generator g, g_idKind kind);

/* Obtain generator name. */
db_string g_getName(db_generator g);

/* Obtain generator object that is currently parsed. */
db_object g_getCurrent(db_generator g);

/* Get generator language. */
db_string g_getLanguage(db_generator g);

/* Instruct the generator to generate for an object. */
void gen_parse(db_generator generator, db_object object, db_bool parseSelf, db_bool parseScope, db_string prefix);

/* Set attribute of generator */
void gen_setAttribute(db_generator g, db_string key, db_string value);

/* Get attribute from generator */
db_string gen_getAttribute(db_generator g, db_string key);

/* Load a generator library. */
db_int16 gen_load(db_generator generator, db_string library);

/* Free generator. */
void gen_free(db_generator generator);

/* Start generating. */
db_int16 gen_start(db_generator generator);

/* === Generator utility functions */

/* Resolve imports */
db_int16 g_resolveImports(db_generator generator);

/* Walk generator objects. Parse scopes of generator objects when configured. */
int g_walk(db_generator generator, g_walkAction o, void* userData);

/* Walk generator objects, do not parse scopes even if configured. */
int g_walkNoScope(db_generator g, g_walkAction action, void* userData);

/* Recursively walk objects, will walk all objects under the scope of generator objects. */
int g_walkRecursive(db_generator generator, g_walkAction o, void* userData);

/* Lookup prefix for object. */
db_string g_getPrefix(db_generator g, db_object o);

/* Translate an object to a language-specific identifier. */
db_string g_fullOid(db_generator g, db_object o, db_id id);

/* Translate an object to a language-specific identifier with idKind provided. */
db_string g_fullOidExt(db_generator g, db_object o, db_id id, g_idKind kind);

/* Translate an class-identifier to a language-specific identifier. */
db_string g_oid(db_generator g, db_object o, db_id id);

/* Translate an identifier to a language-specific identifier. */
db_string g_id(db_generator g, db_string str, db_id id);

/* A check on whether an object must be parsed or not. */
db_bool g_mustParse(db_generator g, db_object o);


/* === Generator file-utility class */

/* Open a file for writing. */
g_file g_fileOpen(db_generator generator, db_string name);

/* Return contents of a file. */
db_string g_fileRead(db_generator generator, db_string name);

/* Lookup an open file. */
void g_fileGet(db_generator generator, db_string name);

/* Lookup an existing code-snippet */
db_string g_fileLookupSnippet(g_file file, db_string snippetId);

/* Lookup an existing code-header */
db_string g_fileLookupHeader(g_file file, db_string snippetId);

/* Increase indentation. */
void g_fileIndent(g_file file);

/* Decrease indentation. */
void g_fileDedent(g_file file);

/* Set scope of file */
void g_fileScopeSet(g_file file, db_object o);

/* Get scope of file */
db_object g_fileScopeGet(g_file file);

/* Write to a file. */
void g_fileWrite(g_file file, char* fmt, ...);

/* Get generator */
db_generator g_fileGetGenerator(g_file file);


/* == Generator unique name-generator for members utility */

/* Get name of member */
db_char* db_genMemberName(db_generator g, db_ll cache, db_member m, db_char *result);

/* Build cache to determine whether membernames occur more than once (due to inheritance) */
db_ll db_genMemberCacheBuild(db_interface o);

/* Clean cache */
void db_genMemberCacheClean(db_ll cache);


#ifdef __cplusplus
}
#endif

#endif /* DB_GEN_H_ */
