
#include "corto.h"
#include "corto_generator.h"
#include "corto_loader.h"
#include "corto_arg.h"

static char* name = NULL;
static char* language = NULL;
static char* prefix = NULL;
static char* lang = NULL;
static corto_ll generators = NULL;
static corto_ll scopes = NULL;
static corto_ll includes = NULL;
static corto_ll attributes = NULL;

int cortotool_arg_attributes(char* arg, int argc, char* argv[]) {
    if (argc) {
        if (!attributes) {
            attributes = corto_llNew();
        }
        corto_llInsert(attributes, argv[1]);
    } else {
        corto_error("missing argument for '%s'.", arg);
    }
    return 1;
}

int cortotool_arg_name(char* arg, int argc, char* argv[]) {
    if (argc) {
        name = argv[1];
    } else {
        corto_error("missing argument for '%s'.", arg);
    }
    return 1;
}

int cortotool_arg_prefix(char* arg, int argc, char* argv[]) {
    if (argc) {
        prefix = argv[1];
    } else {
        corto_error("missing argument for '%s'.", arg);
    }
    return 1;
}

int cortotool_arg_generator(char* arg, int argc, char* argv[]) {
    if (argc) {
        if (!generators) {
            generators = corto_llNew();
        }
        corto_llAppend(generators, argv[1]);
    } else {
        corto_error("missing argument for '%s'.", arg);
    }
    return 1;
}

int cortotool_arg_scope(char* arg, int argc, char* argv[]) {
    if (argc) {
        if (!scopes) {
            scopes = corto_llNew();
        }
        corto_llInsert(scopes, argv[1]);
    } else {
        corto_error("missing argument for '%s'.", arg);
    }
    return 1;
}

int cortotool_arg_include(char* arg, int argc, char* argv[]) {
    if (argc) {
        if (!includes) {
            includes = corto_llNew();
        }
        corto_llAppend(includes, argv[0]);
    } else {
        corto_error("missing argument for '%s'.", arg);
    }
    return 1;
}

int cortotool_arg_language(char* arg, int argc, char* argv[]) {
    if (argc >= 2) {
        if (!generators) {
            generators = corto_llNew();
        }

        if (!strcmp(argv[1], "c")) {
            if (!attributes) {
                attributes = corto_llNew();
            }
            corto_llAppend(generators, "c_project");
            corto_llAppend(generators, "c_type");
            corto_llAppend(generators, "c_interface");
            corto_llAppend(generators, "c_meta");
            corto_llAppend(generators, "c_api");
            corto_llAppend(attributes, "c=src");
            corto_llAppend(attributes, "h=include");

            lang = "c";

        } else if (!strcmp(argv[1], "cpp")) {
            corto_llAppend(generators, "cpp_type");
            corto_llAppend(generators, "cpp_class");
            corto_llAppend(generators, "cpp_load");

        } else {
            corto_error("unknown language '%s'.", argv[1]);
            goto error;
        }
    } else {
        corto_error("invalid number of argument for '%s' (%d).", arg, argc);
        goto error;
    }
    return 1;
error:
    return -1;
}

/* Generate code for the core */
int cortotool_arg_core(char* arg, int argc, char* argv[]) {
    CORTO_UNUSED(arg);
    CORTO_UNUSED(argc);
    CORTO_UNUSED(argv);

    if (!generators) generators = corto_llNew();
    if (!scopes) scopes = corto_llNew();
    if (!attributes) attributes = corto_llNew();
    corto_llAppend(generators, "c_interface");
    corto_llAppend(generators, "c_api");
    corto_llAppend(generators, "c_type");
    corto_llAppend(generators, "doc");
    corto_llAppend(scopes, "::corto::lang");
    corto_llAppend(attributes, "stubs=false");
    corto_llAppend(attributes, "c=src");
    corto_llAppend(attributes, "h=include");
    corto_llAppend(attributes, "bootstrap=true");
    prefix = "cx";
    name = "cx";

    return 0;
}

/* Parse arguments */
static int cortotool_parseArguments(int argc, char* argv[]) {
    /* Specifiy arguments and callbacks */
    corto_argSet("attr", cortotool_arg_attributes, 0, -1);
    corto_argSet("name", cortotool_arg_name, 0, 1);
    corto_argSet("prefix", cortotool_arg_prefix, 0, 1);
    corto_argSet("g", cortotool_arg_generator, 0, -1);
    corto_argSet("scope", cortotool_arg_scope, 0, -1);
    corto_argSet("lang", cortotool_arg_language, 0, 1);
    corto_argSet("l", cortotool_arg_language, 0, 1);
    corto_argSet("core", cortotool_arg_core, 0, 1);
    corto_argSet(NULL, cortotool_arg_include, 0, -1);

    /* Parse commandline */
    if (corto_argParse(argc, argv)) {
        return -1;
    }
    return 0;
}

corto_int16 cortotool_pp(int argc, char *argv[]) {
    corto_generator g;
    corto_string lib, include;
    corto_iter iter;
    corto_string scope, attr;
    corto_object o;

    if (cortotool_parseArguments(argc, argv)) {
        corto_error("invalid commandline specified.");
        goto error;
    }

    if (!generators) {
        corto_error("corto: no generators provided");
        goto error;
    }

    /* Load includes */
    if (includes) {
        iter = corto_llIter(includes);
        while (corto_iterHasNext(&iter)) {
            include = corto_iterNext(&iter);
			
			if (corto_load(include, 0, NULL)) {
                corto_error("corto: cannot load '%s'", include);
                goto error;
            } else {
                /* Add name to scope list if none provided */
                if (!scopes && (corto_llSize(includes) == 1) && !strchr(include, '.')) {
                    scopes = corto_llNew();
                    corto_llInsert(scopes, include);
                }
                /* Add prefix to scope if none provided */
                if (!prefix && (corto_llSize(includes) == 1) && !strchr(include, '.')) {
                    prefix = include;
                }
            }
        }
    }

    /* Load library */
    if (generators) {
        while ((lib = corto_llTakeFirst(generators))) {

            /* Create generator for each provided generator library */
            g = gen_new(name, language);

            /* Load interface */
            if (gen_load(g, lib)) {
                corto_error("corto: cannot load generator '%s'.", lib);
                goto error;
            }

            /* Generate for all scopes */
            if (scopes) {
	            iter = corto_llIter(scopes);
	            while (corto_iterHasNext(&iter)) {
                    corto_id scopeId;
	                scope = corto_iterNext(&iter);

                    /* Ensure the scope is fully qualified */
                    if (scope[0] != ':') {
                        sprintf(scopeId, "::%s", scope);
                    } else {
                        strcpy(scopeId, scope);
                    }

	                /* Resolve object */
	                o = corto_resolve(NULL, scopeId);
	                if (!o) {
	                    corto_error("corto: unresolved scope '%s'.", scopeId);
	                    goto error;
	                }
	                corto_release(o);

	                /* Parse object as scope, with provided prefix */
	                gen_parse(g, o, TRUE, TRUE, prefix);
	            }
	        }

            /* Add output directories */
            if (attributes) {
                iter = corto_llIter(attributes);
                while (corto_iterHasNext(&iter)) {
                    corto_string ptr;

                    attr = corto_strdup(corto_iterNext(&iter));

                    ptr = strchr(attr, '=');
                    if (ptr) {
                        *ptr = '\0';
                        gen_setAttribute(g, attr, ptr+1);
                    }
                    *ptr = '=';
                    corto_dealloc(attr);
                }
            }

            /* Start generator */
            if (gen_start(g)) {
                corto_error("corto: %s: %s", lib, corto_lasterr());
                gen_free(g);

                goto error;
            }

            /* Free generator */
            gen_free(g);
            g = NULL;
        }
    }

    /* Cleanup application resources */
    corto_argClear();

    if (generators) {
        corto_llFree(generators);
    }

    if (includes) {
        corto_llFree(includes);
    }

    if (scopes) {
        corto_llFree(scopes);
    }

    if (attributes) {
        corto_llFree(attributes);
    }

	return 0;
error:
    return -1;
}
