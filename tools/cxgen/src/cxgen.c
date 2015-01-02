/*
 * cxgen.c
 *
 *  Created on: Sep 17, 2012
 *      Author: sander
 */

#include "cortex.h"
#include "cx_generator.h"
#include "cx_loader.h"
#include "cx_arg.h"

static char* name = NULL;
static char* language = NULL;
static char* prefix = NULL;
static char* lang = NULL;
static cx_ll generators = NULL;
static cx_ll scopes = NULL;
static cx_ll includes = NULL;
static cx_ll attributes = NULL;

int cx_arg_attributes(char* arg, int argc, char* argv[]) {
    if (argc) {
        if (!attributes) {
            attributes = cx_llNew();
        }
        cx_llInsert(attributes, argv[1]);
    } else {
        cx_error("missing argument for '%s'.", arg);
    }
    return 1;
}

int cx_arg_name(char* arg, int argc, char* argv[]) {
    if (argc) {
        name = argv[1];
    } else {
        cx_error("missing argument for '%s'.", arg);
    }
    return 1;
}

int cx_arg_prefix(char* arg, int argc, char* argv[]) {
    if (argc) {
        prefix = argv[1];
    } else {
        cx_error("missing argument for '%s'.", arg);
    }
    return 1;
}

int cx_arg_generator(char* arg, int argc, char* argv[]) {
    if (argc) {
        if (!generators) {
            generators = cx_llNew();
        }
        cx_llAppend(generators, argv[1]);
    } else {
        cx_error("missing argument for '%s'.", arg);
    }
    return 1;
}

int cx_arg_scope(char* arg, int argc, char* argv[]) {
    if (argc) {
        if (!scopes) {
            scopes = cx_llNew();
        }
        cx_llInsert(scopes, argv[1]);
    } else {
        cx_error("missing argument for '%s'.", arg);
    }
    return 1;
}

int cx_arg_include(char* arg, int argc, char* argv[]) {
    if (argc) {
        if (!includes) {
            includes = cx_llNew();
        }
        cx_llAppend(includes, argv[0]);
    } else {
        cx_error("missing argument for '%s'.", arg);
    }
    return 1;
}

int cx_arg_language(char* arg, int argc, char* argv[]) {
    if (argc == 2) {
        if (!generators) {
            generators = cx_llNew();
        }
        if (!strcmp(argv[1], "c")) {
            if (!attributes) {
                attributes = cx_llNew();
            }
            cx_llAppend(generators, "c_project");
            cx_llAppend(generators, "c_type");
            cx_llAppend(generators, "c_interface");
            cx_llAppend(generators, "c_load");
            cx_llAppend(generators, "c_api");
            cx_llAppend(attributes, "c=src");
            cx_llAppend(attributes, "h=include");

            lang = "c";
        } else if (!strcmp(argv[1], "cpp")) {
            cx_llAppend(generators, "cpp_type");
            cx_llAppend(generators, "cpp_class");
            cx_llAppend(generators, "cpp_load");
        } else {
            cx_error("unknown language '%s'.", argv[1]);
            goto error;
        }
    } else {
        cx_error("invalid number of argument for '%s'.", arg);
        goto error;
    }
    return 1;
error:
    return 0;
}


/* Parse arguments */
static int cx_parseArguments(int argc, char* argv[]) {
    /* Specifiy arguments and callbacks */
    cx_argSet("attr", cx_arg_attributes, 0, -1);
    cx_argSet("name", cx_arg_name, 0, 1);
    cx_argSet("prefix", cx_arg_prefix, 0, 1);
    cx_argSet("g", cx_arg_generator, 0, -1);
    cx_argSet("scope", cx_arg_scope, 0, -1);
    cx_argSet("lang", cx_arg_language, 0, 1);
    cx_argSet(NULL, cx_arg_include, 0, -1);

    /* Parse commandline */
    if (cx_argParse(argc, argv)) {
        return -1;
    }
    return 0;
}

void printUsage(void) {
    printf("Usage:\n");
    printf("   cxgen [file 0..n] --scope [scope] --prefix [prefix] --lang [language] -g [generator 1..n] -attr [key=value]\n");
    printf("     file:     Any file that is loadable by Cortex (optional).\n");
    printf("     --scope:  Provide the scope for which code will be generated.\n");
    printf("     --prefix: Provide a prefix for the generated code (optional).\n");
    printf("     --lang:   Provide the language. Possible choices are c and cpp (optional).\n");
    printf("               Note that --lang is a shortcut to common generators and attributes for the chosen language.\n");
    printf("     -g:       Any code generator located in generator/bin (optional).\n");
    printf("     --attr:   Specify attributes that will be passed on to the generator (optional).\n");
    printf("               Attributes are specified using a key=value syntax.\n");
    printf("\n");
    printf("Examples:\n");
    printf("   cxgen Foo.cortex --scope Foo --lang c\n");
    printf("   cxgen Foo.cortex --scope Foo -g c_type -g c_interface -g c_load -g c_api --attr c=src --attr h=include\n");
    printf("   cxgen Foo.cortex --scope Foo --lang cpp\n");
    printf("   cxgen Foo.cortex --scope Foo --prefix Bar --lang cpp (replaces 'Foo' by 'Bar' in generated code)\n");
    printf("\n");
}

int main(int argc, char* argv[]) {
    cx_generator g;
    cx_string lib, include;
    cx_iter iter;
    cx_string scope, attr;
    cx_object o;

    if (cx_parseArguments(argc, argv)) {
        cx_error("invalid commandline specified.");
        printUsage();
        return -1;
    }

    if (!generators) {
        cx_error("cxgen: no generators provided");
        return -1;
    }

    /* Start database */
    cx_start();

    /* Load includes */
    if (includes) {
        iter = cx_llIter(includes);
        while(cx_iterHasNext(&iter)) {
            include = cx_iterNext(&iter);
            if (cx_load(include)) {
                cx_error("cxgen: error(s) occurred while loading file '%s', abort generation.", include);
                return -1;
            } else {
                /* Add name to scope list if none provided */
                if (!scopes && (cx_llSize(includes) == 1) && !strchr(include, '.')) {
                    scopes = cx_llNew();
                    cx_llInsert(scopes, include);
                }
                /* Add prefix to scope if none provided */
                if (!prefix && (cx_llSize(includes) == 1) && !strchr(include, '.')) {
                    prefix = include;                 
                }
            }
        }
    }

    /* Load library */
    while((lib = cx_llTakeFirst(generators))) {

        /* Create generator for each provided generator library */
        g = gen_new(name, language);

        /* Load interface */
        if (gen_load(g, lib)) {
            cx_error("cxgen: cannot load generator '%s'.", lib);
            return -1;
        }

        /* Generate for all scopes */
        iter = cx_llIter(scopes);
        while(cx_iterHasNext(&iter)) {
            scope = cx_iterNext(&iter);

            /* Resolve object */
            o = cx_resolve(NULL, scope);
            if (!o) {
                o = cx_resolve(NULL, scope);
                if (!o) {
                    cx_error("cxgen: unresolved scope '%s' .", scope);
                    return -1;
                }
            }
            cx_free(o);

            /* Parse object as scope, with provided prefix */
            gen_parse(g, o, TRUE, TRUE, prefix);
        }

        /* Add output directories */
        if (attributes) {
            iter = cx_llIter(attributes);
            while(cx_iterHasNext(&iter)) {
                cx_string ptr;

                attr = cx_strdup(cx_iterNext(&iter));

                ptr = strchr(attr, '=');
                if (ptr) {
                    *ptr = '\0';
                    gen_setAttribute(g, attr, ptr+1);
                }
                *ptr = '=';
                cx_dealloc(attr);
            }
        }

        /* Start generator */
        if (gen_start(g)) {
            cx_error("cxgen: error(s) occurred while running generator '%s', abort generation.", lib);
            gen_free(g);
            break;
        }

        /* Free generator */
        gen_free(g);
        g = NULL;
    }

    /* Cleanup application resources */
    cx_argClear();

    if (generators) {
        cx_llFree(generators);
    }

    if (includes) {
        cx_llFree(includes);
    }

    if (scopes) {
        cx_llFree(scopes);
    }

    if (attributes) {
        cx_llFree(attributes);
    }

    /* Stop database */
    cx_stop();

    return 0;
}
