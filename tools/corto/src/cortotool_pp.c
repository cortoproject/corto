
#include "cortotool_pp.h"

static corto_ll silent, mute, attributes, names, prefixes, generators, scopes;
static corto_ll languages, includes;
static corto_string prefix = NULL;
static corto_string name = NULL;

corto_int16 cortotool_language(char *language) {
    if (!generators) {
        generators = corto_llNew();
    }

    if (!attributes) {
        attributes = corto_llNew();
    }

    if (!strcmp(language, "c")) {
        corto_llAppend(generators, "c_project");
        corto_llAppend(generators, "c_type");
        corto_llAppend(generators, "c_interface");
        corto_llAppend(generators, "c_meta");
        corto_llAppend(generators, "c_api");
        corto_llAppend(attributes, "c=src");
        corto_llAppend(attributes, "h=include");

    } else if (!strcmp(language, "cpp")) {
        corto_llAppend(generators, "cpp_class");
        corto_llAppend(generators, "c_type");
        corto_llAppend(generators, "c_meta");
        corto_llAppend(attributes, "c=src");
        corto_llAppend(attributes, "h=include");

    } else {
        corto_error("corto: unknown language '%s'", language);
        goto error;
    }

    return 0;
error:
    return -1;
}

corto_int16 cortotool_core(void) {
    corto_pid pid;
    corto_int8 ret = 0;

    /* Generate the core. This is a two-step process where files are generated
     * for both the core and lang package */
    pid = corto_procrun("corto", (char*[]){
      "corto",
      "pp",
      "--prefix", "corto",
      "--name", "corto",
      "--scope", "corto/core",
      "--attr", "c=src/core",
      "--attr", "h=include/core",
      "--attr", "bootstrap=true",
      "--attr", "stubs=false",
      "-g", "c_interface",
      "-g", "c_api",
      "-g", "c_type",
      NULL
    });
    if (corto_procwait(pid, &ret) || ret) {
        corto_error("failed to generate code for corto/core (%d)", ret);
        goto error;
    }

    pid = corto_procrun("corto", (char*[]){
      "corto",
      "pp",
      "--prefix", "corto",
      "--name", "corto",
      "--scope", "corto/lang",
      "--attr", "c=src/lang",
      "--attr", "h=include/lang",
      "--attr", "bootstrap=true",
      "--attr", "stubs=false",
      "-g", "c_interface",
      "-g", "c_api",
      "-g", "c_type",
      NULL
    });
    if (corto_procwait(pid, &ret) || ret) {
        corto_error("failed to generate code for corto/lang (%d)", ret);
        goto error;
    }

    pid = corto_procrun("corto", (char*[]){
      "corto",
      "pp",
      "--prefix", "corto",
      "--name", "corto",
      "--attr", "c=src",
      "--attr", "h=include",
      "--attr", "bootstrap=true",
      "--attr", "stubs=false",
      "-g", "c_project",
      NULL
    });
    if (corto_procwait(pid, &ret) || ret) {
        corto_error("failed to setup project for corto (%d)", ret);
        goto error;
    }

    return 0;
error:
    return -1;
}

corto_int16 cortotool_pp(int argc, char *argv[]) {
    corto_generator g;
    corto_string lib, include;
    corto_iter iter;
    corto_string scope, attr;
    corto_object o;
    corto_ll core;

    CORTO_UNUSED(argc);

    corto_argdata *data = corto_argparse(
      argv,
      (corto_argdata[]){
        {"$0", NULL, NULL}, /* Ignore 'pp' */
        {"--silent", &silent, NULL},
        {"--mute", &mute, NULL},
        {"--core", &core, NULL},
        {"--attr", NULL, &attributes},
        {"--name", NULL, &names},
        {"--prefix", NULL, &prefixes},
        {"--scope", NULL, &scopes},
        {"-p", NULL, &prefixes},
        {"-s", NULL, &scopes},
        {"$+--generator", NULL, &generators},
        {"$|-g", NULL, &generators},
        {"$|--lang", NULL, &languages},
        {"$|-l", NULL, &languages},
        {"*", &includes, NULL},
        {NULL}
      }
    );

    if (!data) {
        corto_error("corto: %s", corto_lasterr());
        goto error;
    }

    if (prefixes) {
        prefix = corto_llGet(prefixes, 0);
    }

    if (names) {
        name = corto_llGet(names, 0);
    }

    if (core) {
        return cortotool_core();
    }

    if (languages) {
        cortotool_language(corto_llGet(languages, 0));
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

        /* If there's a single include file, set an attribute to pass the name
         * of the file to a generator */
        if (corto_llSize(includes) == 1) {
            corto_string str;
            corto_asprintf(&str, "include=%s", corto_llGet(includes, 0));
            if (!attributes) {
                attributes = corto_llNew();
            }
            corto_llAppend(attributes, str);
        }
    }

    /* Load library */
    if (generators) {
        while ((lib = corto_llTakeFirst(generators))) {

            /* Create generator for each provided generator library */
            g = gen_new(name, NULL);

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
                    if ((scope[0] != '/') && (scope[0] != ':')) {
                        sprintf(scopeId, "/%s", scope);
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

            /* Set attributes */
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
    corto_argclean(data);

    return 0;
error:
    return -1;
}
