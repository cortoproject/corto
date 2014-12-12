/*
 * dbgen.c
 *
 *  Created on: Sep 17, 2012
 *      Author: sander
 */

#include "hyve.h"
#include "db_generator.h"
#include "db_loader.h"
#include "db_arg.h"

static char* name = NULL;
static char* language = NULL;
static char* prefix = NULL;
static char* lang = NULL;
static db_ll generators = NULL;
static db_ll scopes = NULL;
static db_ll includes = NULL;
static db_ll attributes = NULL;

int db_arg_attributes(char* arg, int argc, char* argv[]) {
	if (argc) {
	    if (!attributes) {
	        attributes = db_llNew();
	    }
	    db_llInsert(attributes, argv[1]);
	} else {
		db_error("missing argument for '%s'.", arg);
	}
	return 1;
}

int db_arg_name(char* arg, int argc, char* argv[]) {
	if (argc) {
		name = argv[1];
	} else {
		db_error("missing argument for '%s'.", arg);
	}
	return 1;
}

int db_arg_prefix(char* arg, int argc, char* argv[]) {
	if (argc) {
		prefix = argv[1];
	} else {
		db_error("missing argument for '%s'.", arg);
	}
	return 1;
}

int db_arg_generator(char* arg, int argc, char* argv[]) {
	if (argc) {
		if (!generators) {
			generators = db_llNew();
		}
		db_llAppend(generators, argv[1]);
	} else {
		db_error("missing argument for '%s'.", arg);
	}
	return 1;
}

int db_arg_scope(char* arg, int argc, char* argv[]) {
	if (argc) {
		if (!scopes) {
			scopes = db_llNew();
		}
		db_llInsert(scopes, argv[1]);
	} else {
		db_error("missing argument for '%s'.", arg);
	}
	return 1;
}

int db_arg_include(char* arg, int argc, char* argv[]) {
	if (argc) {
		if (!includes) {
			includes = db_llNew();
		}
		db_llAppend(includes, argv[0]);
	} else {
		db_error("missing argument for '%s'.", arg);
	}
	return 1;
}

int db_arg_language(char* arg, int argc, char* argv[]) {
    if (argc == 2) {
        if (!generators) {
            generators = db_llNew();
        }
        if (!strcmp(argv[1], "c")) {
            if (!attributes) {
                attributes = db_llNew();
            }
            db_llAppend(generators, "c_project");
            db_llAppend(generators, "c_type");
            db_llAppend(generators, "c_interface");
            db_llAppend(generators, "c_load");
            db_llAppend(generators, "c_api");
            db_llAppend(attributes, "c=src");
            db_llAppend(attributes, "h=include");

            lang = "c";
        } else if (!strcmp(argv[1], "cpp")) {
            db_llAppend(generators, "cpp_type");
            db_llAppend(generators, "cpp_class");
            db_llAppend(generators, "cpp_load");
        }
    } else {
        db_error("invalid number of argument for '%s'.", arg);
        goto error;
    }
    return 1;
error:
	return 0;
}


/* Parse arguments */
static int db_parseArguments(int argc, char* argv[]) {
	/* Specifiy arguments and callbacks */
	db_argSet("attr", db_arg_attributes, 0, -1);
	db_argSet("name", db_arg_name, 0, 1);
	db_argSet("prefix", db_arg_prefix, 0, 1);
	db_argSet("g", db_arg_generator, 0, -1);
	db_argSet("scope", db_arg_scope, 1, -1);
	db_argSet("lang", db_arg_language, 0, 1);
	db_argSet(NULL, db_arg_include, 0, -1);

	/* Parse commandline */
	if (db_argParse(argc, argv)) {
		return -1;
	}
	return 0;
}

void printUsage(void) {
	printf("Usage:\n");
	printf("   dbgen [file 0..n] --scope [scope] --prefix [prefix] --lang [language] -g [generator 1..n] -o [ext=path]\n");
	printf("     file:     [optional] Can be any file that is loadable by Lyra.\n");
	printf("     --scope:  provide the scope for which code will be generated.\n");
	printf("     --prefix: [optional] provide a prefix for the generated code.\n");
	printf("     --lang:   [optional] provide the language. Possible choices are c and cpp.\n");
	printf("                 Note that --lang is a shortcut to common generators and output paths for the chosen language.\n");
	printf("     -g:       [optional] Choose a code-generator. This can be any code generator that is in generator/bin.\n");
	printf("     -o:       [optional] Provide a path for files with a specific extension.\n");
	printf("\n");
	printf("Examples:\n");
	printf("   dbgen Foo.hyve --scope Foo --lang c\n");
	printf("   dbgen Foo.hyve --scope Foo -g c_type -g c_interface -g c_load -g c_api -o c=src -o h=include (equivalent to previous)\n");
	printf("   dbgen Foo.hyve --scope Foo --lang cpp\n");
	printf("   dbgen Foo.hyve --scope Foo --prefix Bar --lang cpp (replaces 'Foo' by 'Bar' in generated code)\n");
	printf("\n");
}

int main(int argc, char* argv[]) {
	db_generator g;
	db_string lib, include;
	db_iter iter;
	db_string scope, attr;
	db_object o;

	if (db_parseArguments(argc, argv)) {
		db_error("invalid commandline specified.");
		printUsage();
		return -1;
	}

	if (!generators) {
		db_error("dbgen: no generators provided");
		return -1;
	}

	/* Start database */
	db_start();

    db_load("xml");

	/* Load includes */
	if (includes) {
		iter = db_llIter(includes);
		while(db_iterHasNext(&iter)) {
			include = db_iterNext(&iter);
			if (db_load(include)) {
			    db_error("dbgen: error(s) occurred while loading file '%s', abort generation.", include);
			    return -1;
			}
		}
	}

	/* Load library */
	while((lib = db_llTakeFirst(generators))) {

		/* Create generator for each provided generator library */
		g = gen_new(name, language);

		/* Load interface */
		if (gen_load(g, lib)) {
			db_error("dbgen: cannot load generator '%s'.", lib);
			return -1;
		}

		/* Generate for all scopes */
		iter = db_llIter(scopes);
		while(db_iterHasNext(&iter)) {
			scope = db_iterNext(&iter);

			/* Resolve object */
			o = db_resolve(NULL, scope);
			if (!o) {
				/* Be smart, look for a file that matches the requested scope by adding .hyve
				 * to the scopename. */
			    db_load("fast");
				db_id fileName; sprintf(fileName, "%s.hyve", scope);
				db_load(fileName);
				o = db_resolve(NULL, scope);
				if (!o) {
					db_error("dbgen: unresolved scope '%s' .", scope);
					return -1;
				}
			}
			db_free(o);

			/* Parse object as scope, with provided prefix */
			gen_parse(g, o, TRUE, TRUE, prefix);
		}

		/* Add output directories */
		if (attributes) {
            iter = db_llIter(attributes);
            while(db_iterHasNext(&iter)) {
                db_string ptr;

                attr = db_strdup(db_iterNext(&iter));

                ptr = strchr(attr, '=');
                if (ptr) {
                    *ptr = '\0';
                    gen_setAttribute(g, attr, ptr+1);
                }
                *ptr = '=';
                db_dealloc(attr);
            }
		}

		/* Start generator */
		if (gen_start(g)) {
		    db_error("dbgen: error(s) occurred while running generator '%s', abort generation.", lib);
		    gen_free(g);
		    break;
		}

		/* Free generator */
		gen_free(g);
		g = NULL;
	}

	/* Cleanup application resources */
	db_argClear();

	if (generators) {
		db_llFree(generators);
	}

	if (includes) {
		db_llFree(includes);
	}

	if (scopes) {
		db_llFree(scopes);
	}

	if (attributes) {
	    db_llFree(attributes);
	}

	/* Stop database */
	db_stop();

	return 0;
}
