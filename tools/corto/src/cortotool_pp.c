
#include "cortotool_pp.h"
#include "corto/g/g.h"
#include "corto/argparse/argparse.h"

static corto_ll silent, mute, attributes, names, prefixes, generators, scopes;
static corto_ll objects, languages, includes, imports;
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
        corto_llAppend(generators, "c/project");
        corto_llAppend(generators, "c/type");
        corto_llAppend(generators, "c/interface");
        corto_llAppend(generators, "c/load");
        corto_llAppend(generators, "c/api");
        corto_llAppend(attributes, "c=src");
        corto_llAppend(attributes, "h=include");
    } else if (!strcmp(language, "c4cpp")) {
        corto_llAppend(generators, "c/project");
        corto_llAppend(generators, "c/type");
        corto_llAppend(generators, "c/interface");
        corto_llAppend(generators, "c/load");
        corto_llAppend(generators, "c/api");
        corto_llAppend(attributes, "c=src");
        corto_llAppend(attributes, "cpp=src");
        corto_llAppend(attributes, "h=include");
        corto_llAppend(attributes, "c4cpp=true");
    } else if (!strcmp(language, "cpp") || (!strcmp(language, "c++"))) {
        if (!prefixes) {
            prefixes = corto_llNew();
        }
        corto_llAppend(prefixes, "");
        corto_llAppend(generators, "c/type");
        corto_llAppend(generators, "c/load");
        corto_llAppend(generators, "c/project");
        corto_llAppend(generators, "cpp/class");
        corto_llAppend(attributes, "c=src");
        corto_llAppend(attributes, "h=include");
        corto_llAppend(attributes, "cpp=src");
        corto_llAppend(attributes, "hpp=include");
        corto_llAppend(attributes, "c4cpp=true");
        corto_llAppend(attributes, "lang=cpp");
    } else {
        corto_error("unknown language '%s'", language);
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
      "-g", "c/interface",
      "-g", "c/type",
      NULL
    });
    if (corto_procwait(pid, &ret) || ret) {
        corto_error("failed to generate code for corto/core (%d)", ret);
        printf("   command: corto pp --prefix corto --name corto --scope corto/core --attr c=src/core --attr h=include/core --attr bootstrap=true --attr stubs=false -g c/interface -g c/api -g c/type\n");
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
      "-g", "c/interface",
      "-g", "c/type",
      NULL
    });
    if (corto_procwait(pid, &ret) || ret) {
        corto_error("failed to generate code for corto/lang (%d)", ret);
        printf("   command: corto pp --prefix corto --name corto --scope corto/lang --attr c=src/lang --attr h=include/lang --attr bootstrap=true --attr stubs=false -g c/interface -g c/api -g c/type\n");
        goto error;
    }

    pid = corto_procrun("corto", (char*[]){
      "corto",
      "pp",
      "--prefix", "corto_native",
      "--name", "corto",
      "--scope", "corto/native",
      "--attr", "c=src/native",
      "--attr", "h=include/native",
      "--attr", "bootstrap=true",
      "--attr", "stubs=false",
      "-g", "c/interface",
      "-g", "c/type",
      NULL
    });
    if (corto_procwait(pid, &ret) || ret) {
        corto_error("failed to generate code for corto/native (%d)", ret);
        printf("   command: corto pp --prefix corto_native --name corto --scope corto/native --attr c=src/native --attr h=include/native --attr bootstrap=true --attr stubs=false -g c/interface -g c/api -g c/type\n");
        goto error;
    }

    pid = corto_procrun("corto", (char*[]){
      "corto",
      "pp",
      "--prefix", "corto_secure",
      "--name", "corto",
      "--scope", "corto/secure",
      "--attr", "c=src/secure",
      "--attr", "h=include/secure",
      "--attr", "bootstrap=true",
      "--attr", "stubs=false",
      "-g", "c/interface",
      "-g", "c/type",
      NULL
    });
    if (corto_procwait(pid, &ret) || ret) {
        corto_error("failed to generate code for corto/native (%d)", ret);
        printf("   command: corto pp --prefix corto_secure --name corto --scope corto/secure --attr c=src/secure --attr h=include/secure --attr bootstrap=true --attr stubs=false -g c/interface -g c/api -g c/type\n");
        goto error;
    }

    /* Generate C API */
    pid = corto_procrun("corto", (char*[]){
      "corto",
      "pp",
      "--name", "corto",
      "--scope", "corto/lang,corto/core,corto/secure,corto/native",
      "--attr", "c=src",
      "--attr", "h=include",
      "--attr", "bootstrap=true",
      "--attr", "stubs=false",
      "-g", "c/api",
      NULL
    });
    if (corto_procwait(pid, &ret) || ret) {
        corto_error("failed to generate code for corto/c (%d)", ret);
        printf("   command: corto pp --prefix corto --name corto --scope corto/core --attr c=src/core --attr h=include/core --attr bootstrap=true --attr stubs=false -g c/interface -g c/api -g c/type\n");
        goto error;
    }

    return 0;
error:
    return -1;
}

corto_int16 cortotool_ppParse(
    g_generator g,
    corto_ll list,
    corto_bool parseSelf,
    corto_bool parseScope)
{
    corto_iter it = corto_llIter(list);
    while (corto_iterHasNext(&it)) {
        corto_id id;
        char *objId = corto_iterNext(&it);

        /* Ensure the scope is fully qualified */
        if ((objId[0] != '/') && (objId[0] != ':')) {
            sprintf(id, "/%s", objId);
        } else {
            strcpy(id, objId);
        }

        /* Resolve object */
        corto_object o = corto_resolve(NULL, id);
        if (!o) {
            if (includes && corto_llSize(includes)) {
                if (corto_llSize(includes) == 1) {
                    corto_error("'%s' does not define object '%s'",
                      corto_llGet(includes, 0),
                      id);
                } else {
                    corto_error("object '%s' is not in loaded definitions",
                      id);
                }
            } else {
                corto_error("unresolved object '%s' (did you forget to load the definitions?)", id);
            }
            goto error;
        }

        /* Parse object as scope, with provided prefix */
        g_parse(g, o, parseSelf, parseScope, prefix);
        
        corto_release(o);
    }

    return 0;
error:
    return -1;
}

void cortotool_splitId(corto_string path, char **parent, char **id) {
    *id = strrchr(path, '/');
    *parent = NULL;
    if (*id) {
        if (*id != path) {
            *parent = path;
        } else {
            *parent = "/";
        }
        *id[0] = '\0';
        (*id) ++;
    } else {
        *id = path;
        *parent = "/";
    }
}

/* Add imports to parser */
corto_int16 cortotool_ppParseImports(g_generator g, corto_ll imports) {
    corto_iter it = corto_llIter(imports);

    while (corto_iterHasNext(&it)) {
        corto_string import = corto_iterNext(&it);

        if (strcmp(import, "corto") && strcmp(import, "/corto")) {
            corto_object package = corto_lookup(NULL, import);
            if (!package) {
                corto_seterr("package '%s' not found", import);
                goto error;
            }

            if (g_import(g, package)) {
                goto error;
            }

            corto_release(package);
        }
    }

    return 0;
error:
    return -1;
}

corto_int16 cortotool_pp(int argc, char *argv[]) {
    g_generator g;
    corto_string lib, include;
    corto_iter it;
    corto_string attr;
    corto_ll core;

    CORTO_UNUSED(argc);

    /* If a definition file contains a package that is not in the imports
     * specified on the commandline, don't automatically load it, but throw an
     * error. This guarantees that the definition file cannot use packages that
     * are not part of the project dependencies. */
    corto_autoload(FALSE);

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
        {"--object", NULL, &objects},
        {"--import", NULL, &imports},
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
        corto_seterr("%s", corto_lasterr());
        goto error;
    }

    if (prefixes) {
        prefix = corto_llGet(prefixes, 0);
    }

    if (names) {
        name = corto_llGet(names, 0);
    }

    if (core) {
        corto_trace("pp: regenerate core");
        return cortotool_core();
    }

    if (languages) {
        cortotool_language(corto_llGet(languages, 0));
    }

    corto_trace("pp: start generator from '%s'", corto_cwd());

    /* Load imports */
    if (imports) {
        corto_iter it = corto_llIter(imports);
        while (corto_iterHasNext(&it)) {
            corto_string import = corto_iterNext(&it);
            if (strcmp(import, "corto") && strcmp(import, "/corto")) {
                if (corto_load(import, 0, NULL)) {
                    corto_seterr("importing '%s' failed: %s", import, corto_lasterr());
                    goto error;
                }
            }
        }
    }

    /* Load includes */
    if (includes) {
        it = corto_llIter(includes);
        while (corto_iterHasNext(&it)) {
            include = corto_iterNext(&it);

            corto_trace("pp: loading '%s'", include);
            if (corto_load(include, 0, NULL)) {
                corto_seterr("%s: %s", include, corto_lasterr());
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
            g = g_new(name, NULL);

            /* Load interface */
            if (g_load(g, lib)) {
                corto_seterr("corto: pp: %s", corto_lasterr());
                goto error;
            }

            /* Generate for all scopes */
            if (scopes) {
                if (cortotool_ppParse(g, scopes, TRUE, TRUE)) {
                    goto error;
                }
            }
            if (objects) {
                if (cortotool_ppParse(g, objects, TRUE, FALSE)) {
                    goto error;
                }
            }

            /* Load imports */
            if (imports) {
                if (cortotool_ppParseImports(g, imports)) {
                    goto error;
                }
            }

            /* Set attributes */
            if (attributes) {
                it = corto_llIter(attributes);
                while (corto_iterHasNext(&it)) {
                    corto_string ptr;

                    attr = corto_strdup(corto_iterNext(&it));

                    ptr = strchr(attr, '=');
                    if (ptr) {
                        *ptr = '\0';
                        g_setAttribute(g, attr, ptr+1);
                    }
                    *ptr = '=';
                    corto_dealloc(attr);
                }
            }

            /* Start generator */
            corto_trace("pp: run generator '%s'", lib);
            if (g_start(g)) {
                corto_seterr("%s: %s", lib, corto_lasterr());
                g_free(g);
                goto error;
            }

            /* Free generator */
            g_free(g);
            g = NULL;
        }
    }

    /* Cleanup application resources */
    corto_argclean(data);

    return 0;
error:
    corto_error("pp: %s", corto_lasterr());
    return -1;
}
