
#include "cortotool_create.h"
#include "cortotool_package.h"
#include "cortotool_build.h"

static corto_int16 cortotool_setupProject(
    const char *projectKind,
    const char *name,
    corto_bool isLocal,
    corto_bool isSilent)
{
    CORTO_UNUSED(isLocal);

    if (!isSilent) {
        printf ("corto: create %s '%s'\n", projectKind, name);
    }

    if (corto_fileTest(name)) {
        corto_id id;
        sprintf(id, "%s/.corto", name);
        if (corto_fileTest(id)) {
            corto_error(
                "corto: a project with the name '%s' already exists!",
                name);
            goto error;
        }
    } else if (!corto_mkdir(name)) {
        corto_id id;
        sprintf(id, "%s/.corto", name);
        if (corto_mkdir(id)) {
            corto_error(
                "corto: couldn't create '%s/.corto (check permissions)'",
                name);
            goto error;
        }

        /* Write version.txt */
        sprintf(id, "%s/.corto/version.txt", name);
        FILE *f = fopen(id, "w");
        if (!f) {
            corto_error("corto: couldn't create '%s' (check permissions)",
              id);
        }
        fprintf(f, "%s", "0.0.0\n");
        fclose(f);
    } else {
        corto_error(
            "corto: couldn't create project directory '%s' (check permissions)",
            name);
        goto error;
    }

    return 0;
error:
    return -1;
}

static corto_int16 cortotool_createRakefile(const char *projectKind, const char *name, const char *shortName, corto_bool isLocal) {
    FILE *file;
    corto_id buff;

    sprintf(buff, "%s/rakefile", shortName);
    file = fopen(buff, "w");
    if(!file) {
        corto_error("corto: couldn't create %s/rakefile (check permissions)", buff);
        goto error;
    }

    fprintf(file, "\n");
    if (!strcmp(projectKind, CORTO_PACKAGE)) {
        fprintf(file, "PACKAGE = '%s'\n\n", name);
    } else {
        fprintf(file, "TARGET = '%s'\n\n", name);
    }

    if (isLocal) {
        fprintf(file, "LOCAL = true\n\n");
    }

    fprintf(file, "require \"#{ENV['CORTO_BUILD']}/%s\"\n", projectKind);
    fclose(file);

    return 0;
error:
    return -1;
}

static corto_int16 cortotool_createTest(corto_string name, corto_bool isComponent, corto_bool isPackage) {
    FILE *file;

    if (corto_mkdir("test")) {
        corto_error("corto: couldn't create test directory for '%s' (check permissions)", name);
        goto error;
    }
    if (corto_mkdir("test/src")) {
        corto_error("corto: couldn't create test/src directory for '%s' (check permissions)", name);
        goto error;
    }

    if (cortotool_create(
        8,
        (char*[]){"create", "package", "::test", "--empty", "--notest", "--local", "--silent", "--nobuild", NULL}
    )) {
        corto_error("corto: couldn't create test skeleton (check permissions)");
        goto error;
    }

    file = fopen("src/test.c", "w");
    if (file) {
        fprintf(file, "/* $begin(main) */\n");
        fprintf(file, "    int result = 0;\n");
        fprintf(file, "    test_Runner runner = test_RunnerCreate(\"%s\", argv[0], (argc > 1) ? argv[1] : NULL);\n", name);
        fprintf(file, "    if (!runner) return -1;\n");
        fprintf(file, "    if (corto_llSize(runner->failures)) {\n");
        fprintf(file, "        result = -1;\n");
        fprintf(file, "    }\n");
        fprintf(file, "    corto_delete(runner);\n");
        fprintf(file, "    return result;\n");
        fprintf(file, "/* $end */\n");
        fclose(file);
    } else {
        corto_error("corto: couldn't create 'test/src/test.c' (check permissions)");
        goto error;
    }

    file = fopen("test.cx", "w");
    if (file) {
        fprintf(file, "#package ::test\n\n");
        fprintf(file, "test::Suite MySuite::\n");
        fprintf(file, "    void testSomething()\n\n");
        fclose(file);
    } else {
        corto_error("corto: couldn't create 'test/test.cx' (check permissions)");
        goto error;
    }

    if (cortotool_add(
        4,
        (char*[]){"add", "::corto::test", "--silent", "--nobuild", NULL}
    )) {
        goto error;
    }

    if (isComponent) {
        if (cortotool_add(
            5,
            (char*[]){"add", "component", name, "--silent", "--nobuild", NULL}
        )) {
            goto error;
        }
    } else if (isPackage) {
        if (cortotool_add(
            3,
            (char*[]){"add", name, "--silent", "--nobuild", NULL}
        )) {
            goto error;
        }
    }

    /* Timestamps of the files are likely too close to trigger a build, so explicitly
     * do a rebuild of the test project */
    cortotool_rebuild(2, (char*[]){"rebuild", "--silent", NULL});

    if (corto_chdir("..")) {
        corto_error("corto: failed to change directory to parent");
        goto error;
    }

    return 0;
error:
    return -1;
}

static char* cortotool_randomName(void) {
    char buffer[256];

    char *colors[] = {
        "Cayenne",
        "Maroon",
        "Orchid",
        "Magenta",
        "Tangerine",
        "Salmon",
        "Lemon",
        "Clover",
        "Lime",
        "Teal",
        "Turquoise"};

    char *animals[] = {
        "Buffalo",
        "Eagle",
        "Lynx",
        "Porcupine",
        "Lizard",
        "Alpaca",
        "Lemming",
        "Armadillo",
        "Mongoose",
        "Gecko",
        "Beaver",
        "Owl",
        "Cat",
        "Emu",
        "Vulture",
        "Kangaroo",
        "Badger",
        "Hawk",
        "Baboon",
        "Otter",
        "Ibis",
        "Goose",
        "Lemur",
        "Hog",
        "Herring",
        "Sloth",
        "Peacock",
        "Koala",
        "Moose",
        "Tapir"
        };

    strcpy(buffer, colors[rand() % (sizeof(colors) / sizeof(char*))]);
    strcat(buffer, animals[rand() % (sizeof(animals) / sizeof(char*))]);

    return strdup(buffer);
}

static corto_int16 cortotool_app (
    const char *projectKind,
    char *name,
    corto_bool silent,
    corto_bool mute,
    corto_bool nobuild,
    corto_bool notest,
    corto_bool local,
    corto_bool empty)
{
    corto_id buff;
    FILE *file;

    CORTO_UNUSED(empty);

    silent |= mute;

    if (cortotool_setupProject(projectKind, name, local, silent)) {
        goto error;
    }

    if (cortotool_createRakefile(projectKind, name, name, local)) {
        goto error;
    }

    sprintf(buff, "%s/src", name);
    if (corto_mkdir(buff)) {
        corto_error("corto: couldn't create %s directory (check permissions)", buff);
        goto error;
    }

    sprintf(buff, "%s/src/%s.c", name, name);
    file = fopen(buff, "w");
    if (file) {
        fprintf(file, "#include \"%s.h\"\n\n", name);
        fprintf(file, "int %sMain(int argc, char *argv[]) {\n\n", name);
        fprintf(file, "    printf(\"Hello Corto!\\n\");\n\n");
        fprintf(file, "    return 0;\n");
        fprintf(file, "}\n");
        fclose(file);
    } else {
        corto_error("corto: couldn't create '%s' (check permissions)", buff);
        goto error;
    }

    if (corto_chdir(name)) {
        corto_error("corto: can't change working directory to '%s' (check permissions)", buff);
        goto error;
    }

    if (!nobuild) {
        if (cortotool_build(2, (char*[]){"build", "--silent", NULL})) {
            goto error;
        }
    }

    if (!notest) {
        if (cortotool_createTest(
            name,
            !strcmp(projectKind, CORTO_COMPONENT),
            FALSE))
        {
            goto error;
        }
    }

    if (!silent) {
        printf("corto: done\n\n");
    }

    return 0;
error:
    return -1;
}

static corto_int16 cortotool_package(
    char *projectname,
    corto_bool silent,
    corto_bool mute,
    corto_bool nobuild,
    corto_bool notest,
    corto_bool local,
    corto_bool empty)
{
    corto_id cxfile, srcfile, srcdir;
    corto_char *ptr, *name;
    FILE *file;
    corto_uint32 i;
    corto_char *include = projectname;

    silent |= mute;

    /* Ignore initial colons */
    if (include[0] == ':') {
        if (include[1] == ':') {
            include += 2;
        } else {
            if (!mute) {
                corto_error("corto: invalid package name");
            }
            goto error;
        }
    }

    /* Extract left-most name from include variable */
    ptr = include;
    name = include;
    for (i = 0; i < strlen(include); i++) {
        if (*ptr == ':') {
            name = ptr+1;
        }
        ptr++;
    }

    if (cortotool_setupProject(CORTO_PACKAGE, name, local, silent)) {
        goto error;
    }

    if (cortotool_createRakefile(CORTO_PACKAGE, include, name, local)) {
        goto error;
    }

    /* Write definition file */
    if (snprintf(cxfile, sizeof(cxfile), "%s/%s.cx", name, name) >=
        (int)sizeof(cxfile))
    {
        if (!mute) {
            corto_error("corto: package name '%s' is too long", name);
        }
        goto error;
    }

    if (corto_fileTest(cxfile)) {
        if (!mute) {
            corto_error("corto: package '%s' already exists", cxfile);
        }
        goto error;
    }

    if (corto_mkdir(name)) {
        if (!mute) {
            corto_error(
                "corto: failed to create directory '%s' (check permissions)",
                name);
        }
        goto error;
    }

    file = fopen(cxfile, "w");
    if (file) {
        fprintf(file, "#package ::%s\n\n", include);
        if (!empty) {
            fprintf(file, "class RedPanda::\n");
            fprintf(file, "    weight: int32\n");
            fprintf(file, "    int16 construct()\n");
            fprintf(file, "    void chew()\n");
        }
        fclose(file);
    } else {
        corto_error(
            "corto: failed to open file '%s' (check permissions)",
            cxfile);
        goto error;
    }

    /* Write class implementation */
    sprintf(srcdir, "%s/src", name);
    if (corto_mkdir(srcdir)) {
        corto_error(
          "corto: failed to create directory '%s' (check permissions)",
          srcdir);
        goto error;
    }

    if (!empty) {
        if (snprintf(srcfile,
            sizeof(srcfile),
            "%s/src/RedPanda.c",
            name) >= (int)sizeof(srcfile))
        {
            if (!mute) {
                corto_error("corto: package name '%s' is too long", name);
            }
            goto error;
        }

        if (corto_fileTest(srcfile)) {
            if (!mute) {
                corto_error("corto: file '%s' already exists", srcfile);
            }
            goto error;
        }

        file = fopen(srcfile, "w");
        if (file) {
            fprintf(file, "/* $begin(/%s/RedPanda/construct) */\n", include);
            fprintf(file, "    printf(\"Hurray, %%s the panda is born!\\n\", corto_nameof(this));\n");
            fprintf(file, "    return 0;\n");
            fprintf(file, "/* $end */\n");
            fprintf(file, "/* $begin(/%s/RedPanda/chew) */\n", include);
            fprintf(file, "    this->weight++;\n");
            fprintf(file, "    printf(\"%%s the panda is chewing on something omnomnom (his weight: %%d)\\n\",\n");
            fprintf(file, "            corto_nameof(this), this->weight);\n");
            fprintf(file, "/* $end */\n");
            fclose(file);
        } else {
            corto_error("corto: failed to open file '%s'", cxfile);
            goto error;
        }
    }

    if (corto_load(cxfile, 0, NULL)) {
        if (!mute) {
            corto_error("corto: failed to load '%s'", cxfile);
        }
        goto error;
    }

    /* Change working directory */
    if (corto_chdir(name)) {
        if (!mute) {
            corto_error(
              "corto: can't change directory to '%s' (check permissions)",
              name);
        }
        goto error;
    }

    if (!nobuild) {
        if (cortotool_build(2, (char*[]){"build", "--silent", NULL})) {
            goto error;
        }
    }

    if (!notest) {
        if (cortotool_createTest(include, FALSE, TRUE)) {
            goto error;
        }
    }

    if (!silent) {
        printf("corto: done\n\n");
    }

    return 0;
error:
    return -1;
}

corto_int16 cortotool_create(int argc, char *argv[]) {
    corto_ll silent, mute, nobuild, notest, local, empty;
    corto_ll apps, components, packages;
    corto_ll apps_noname, components_noname, packages_noname;

    CORTO_UNUSED(argc);

    corto_argdata *data = corto_argparse(
      argv,
      (corto_argdata[]){
        {"$0", NULL, NULL}, /* Ignore 'create' */
        {"--silent", &silent, NULL},
        {"--mute", &mute, NULL},
        {"--nobuild", &nobuild, NULL},
        {"--notest", &notest, NULL},
        {"--local", &local, NULL},
        {"--empty", &empty, NULL},
        {"--nopanda", &empty, NULL},
        {CORTO_APPLICATION, NULL, &apps},
        {CORTO_COMPONENT, NULL, &components},
        {CORTO_PACKAGE, NULL, &packages},
        {CORTO_APPLICATION, &apps_noname, NULL},
        {CORTO_COMPONENT, &components_noname, NULL},
        {CORTO_PACKAGE, &packages_noname, NULL},
        {"$1", &apps, NULL},
        {NULL}
      }
    );

    if (!data) {
        corto_error("corto: %s", corto_lasterr());
        goto error;
    }

    /* If no arguments are provided, create an application with a random name */
    if (!apps && !components && !packages && !apps_noname &&
        components_noname && !packages_noname)
    {
        char *name = cortotool_randomName();
        if (cortotool_app(
            CORTO_APPLICATION,
            name,
            silent != NULL,
            mute != NULL,
            nobuild != NULL,
            notest != NULL,
            local != NULL,
            empty != NULL))
        {
            goto error;
        }
    }

    if (apps) {
        corto_iter iter = corto_llIter(apps);
        while (corto_iterHasNext(&iter)) {
            char *name = corto_iterNext(&iter);
            if (cortotool_app(
                CORTO_APPLICATION,
                name,
                silent != NULL,
                mute != NULL,
                nobuild != NULL,
                notest != NULL,
                local != NULL,
                empty != NULL))
            {
                goto error;
            }
        }
    }

    if (apps_noname) {
        corto_iter iter = corto_llIter(apps_noname);
        while (corto_iterHasNext(&iter)) {
            char *name = cortotool_randomName();
            corto_iterNext(&iter);
            if (cortotool_app(
                CORTO_APPLICATION,
                name,
                silent != NULL,
                mute != NULL,
                nobuild != NULL,
                notest != NULL,
                local != NULL,
                empty != NULL))
            {
                goto error;
            }
        }
    }

    if (components) {
        corto_iter iter = corto_llIter(components);
        while (corto_iterHasNext(&iter)) {
            char *name = corto_iterNext(&iter);
            if (cortotool_app(
                CORTO_COMPONENT,
                name,
                silent != NULL,
                mute != NULL,
                nobuild != NULL,
                notest != NULL,
                local != NULL,
                empty != NULL))
            {
                goto error;
            }
        }
    }

    if (components_noname) {
        corto_iter iter = corto_llIter(components_noname);
        while (corto_iterHasNext(&iter)) {
            char *name = cortotool_randomName();
            corto_iterNext(&iter);
            if (cortotool_app(
                CORTO_COMPONENT,
                name,
                silent != NULL,
                mute != NULL,
                nobuild != NULL,
                notest != NULL,
                local != NULL,
                empty != NULL))
            {
                goto error;
            }
        }
    }

    if (packages) {
        corto_iter iter = corto_llIter(packages);
        while (corto_iterHasNext(&iter)) {
            char *name = corto_iterNext(&iter);
            if (cortotool_package(
                name,
                silent != NULL,
                mute != NULL,
                nobuild != NULL,
                notest != NULL,
                local != NULL,
                empty != NULL))
            {
                goto error;
            }
        }
    }

    if (packages_noname) {
        corto_iter iter = corto_llIter(packages_noname);
        while (corto_iterHasNext(&iter)) {
            char *name = cortotool_randomName();
            corto_iterNext(&iter);
            if (cortotool_package(
                name,
                silent != NULL,
                mute != NULL,
                nobuild != NULL,
                notest != NULL,
                local != NULL,
                empty != NULL))
            {
                goto error;
            }
        }
    }

    corto_argclean(data);

    return 0;
error:
    return -1;
}

void cortotool_createHelp(void) {
    printf("Usage: corto create\n");
    printf("Usage: corto create <name> [options]\n");
    printf("Usage: corto create <command> <name> [options]\n");
    printf("Usage: corto create <command> [options]\n");
    printf("\n");
    printf("When no name is passed to create, corto will choose a random name.\n");
    printf("\n");
    printf("Commands:\n");
    printf("   app:           Create a new application project. An app is a standalone\n");
    printf("                  executable that links with the corto libraries. You can\n");
    printf("                  run your application by typing 'corto run' in the app directory\n");
    printf("   package:       Create a new package. Use when you're about to create\n");
    printf("                  functionality that must be shared between apps, or\n");
    printf("                  other packages.\n");
    printf("   component:     Create a new component. A component is a shared library\n");
    printf("                  that contains a cortomain function which is executed\n");
    printf("                  upon loading the library.\n");
    printf("\n");
    printf("Options:\n");
    printf("   --empty        Create an empty project instead of an example project\n");
    printf("   --local        Create a project that won't be installed in the Corto repository\n");
    printf("   --notest       Do not create a test skeleton\n");
    printf("\n");
}
