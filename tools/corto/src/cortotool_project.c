
#include "cortotool_create.h"
#include "cortotool_package.h"
#include "cortotool_build.h"

static corto_int16 cortotool_setupProject(const char *name, corto_bool isLocal, corto_bool isSilent) {
    CORTO_UNUSED(isLocal);

    if (!isSilent) {
        printf ("corto: create project '%s'\n", name);
    }

    if (corto_fileTest(name)) {
        corto_id id;
        sprintf(id, "%s/.corto", name);
        if (corto_fileTest(id)) {
            corto_error("corto: a project with the name '%s' already exists!", name);
            goto error;
        }
    } else if (corto_mkdir(name)) {
        corto_error("corto: couldn't create project directory '%s' (check permissions)", name);
        goto error;
    }

/*    if (!isLocal) {
        corto_pid pid = corto_procrun("git", (char*[]){"git", "init", (char *)name, NULL});
        if (pid && corto_procwait(pid, NULL)) {
            corto_error("corto: failed to initialize git repository (is git installed?)\n");
            goto error;
        }
    }*/

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
        (char*[]){"create", "package", "::test", "--empty", "--notest", "--local", "--silent", "--nobuild"}
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
        (char*[]){"add", "::corto::test", "--silent", "--nobuild"}
    )) {
        goto error;
    }

    if (isComponent) {
        if (cortotool_add(
            5,
            (char*[]){"add", name, "--component", "--silent", "--nobuild"}
        )) {
            goto error;
        }
    } else if (isPackage) {
        if (cortotool_add(
            3,
            (char*[]){"add", name, "--silent", "--nobuild"}
        )) {
            goto error;
        }
    }

    /* Timestamps of the files are likely too close to trigger a build, so explicitly
     * do a rebuild of the test project */
    cortotool_rebuild(1, (char*[]){"rebuild"});

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

static corto_int16 cortotool_parseProjectArgs(
    int argc, 
    char *argv[], 
    corto_bool *isEmpty, 
    corto_bool *isLocal, 
    corto_bool *noTest, 
    corto_bool *silent,
    corto_bool *nobuild) 
{
    corto_int32 i;
    for (i = 0; i < argc; i++) {
        if (!strcmp(argv[i], "--empty")) {
            if (isEmpty) *isEmpty = TRUE;
        } else if (!strcmp(argv[i], "--local")) {
            if (isLocal) *isLocal = TRUE;
        } else if (!strcmp(argv[i], "--notest")) {
            if (noTest) *noTest = TRUE;
        } else if (!strcmp(argv[i], "--silent")) {
            if (silent) *silent = TRUE;
        } else if (!strcmp(argv[i], "--nobuild")) {
            *nobuild = TRUE;
        } else {
            corto_error("corto: unknown option '%s'", argv[i]);
            goto error;
        }
    }
    return 0;
error:
    return -1;
}

static corto_int16 cortotool_application(int argc, char *argv[]) {
    corto_id buff;
    FILE *file;
    corto_bool isApplication = !strcmp(argv[0], "create") || !strcmp(argv[0], CORTO_APPLICATION);
    corto_uint32 optionsStartFrom = 1;
    char *name;
    corto_bool isLocal = FALSE, noTest = FALSE, isSilent = FALSE, noBuild = TRUE;

    if ((argc <= 1) || (*argv[1] == '-')) {
        name = cortotool_randomName();
    } else {
        name = argv[1];
        optionsStartFrom = 2;
    }

    /* Parse options */
    if (cortotool_parseProjectArgs(argc - optionsStartFrom, &argv[optionsStartFrom], NULL, &isLocal, &noTest, &isSilent, &noBuild)) {
        goto error;
    }

    if (cortotool_setupProject(name, isLocal, isSilent)) {
        goto error;
    }

    if (cortotool_createRakefile(isApplication ? CORTO_APPLICATION : argv[0], name, name, isLocal)) {
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

    if (!noBuild) {
        if (cortotool_build(0, NULL)) {
            goto error;
        }
    }

    if (!noTest) {
        if (cortotool_createTest(name, !isApplication, FALSE)) {
            goto error;
        }
    }

    if (!isSilent) {
        printf("corto: done\n\n");
    }

    return 0;
error:
    return -1;
}

static corto_int16 cortotool_package(int argc, char *argv[]) {
    corto_id cxfile, srcfile, srcdir;
    corto_char *ptr, *name;
    FILE *file;
    corto_uint32 i;
    corto_char *include = NULL;
    corto_uint32 optionsStartFrom = 1;
    corto_bool isEmpty = FALSE, isLocal = FALSE, noTest = FALSE, isSilent = FALSE, noBuild = FALSE;

    if ((argc <= 1) || (*(argv[1])) == '-') {
        include = cortotool_randomName();
    } else {
        include = argv[1];
        optionsStartFrom = 2;
    }

    /* Ignore initial colons */
    if (include[0] == ':') {
        if (include[1] == ':') {
            include += 2;
        } else {
            corto_error("corto: invalid package name");
            goto error;
        }
    }

    /* Parse options */
    if (cortotool_parseProjectArgs(argc - optionsStartFrom, &argv[optionsStartFrom], &isEmpty, &isLocal, &noTest, &isSilent, &noBuild)) {
        goto error;
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

       if (cortotool_setupProject(name, isLocal, isSilent)) {
        goto error;
    }

    if (cortotool_createRakefile(CORTO_PACKAGE, include, name, isLocal)) {
        goto error;
    }

    /* Write definition file */
    if (snprintf(cxfile, sizeof(cxfile), "%s/%s.cx", name, name) >= (int)sizeof(cxfile)) {
        corto_error("corto: package name '%s' is too long", name);
        goto error;
    }

    if (corto_fileTest(cxfile)) {
        corto_error("corto: package '%s' already exists", cxfile);
        goto error;
    }

    if (corto_mkdir(name)) {
        corto_error("corto: failed to create directory '%s' (check permissions)", name);
        goto error;
    }

    file = fopen(cxfile, "w");
    if (file) {
        fprintf(file, "#package ::%s\n\n", include);
        if (!isEmpty) {
            fprintf(file, "class RedPanda::\n");
            fprintf(file, "    weight: int32\n");
            fprintf(file, "    int16 construct()\n");
            fprintf(file, "    void chew()\n");
        }
        fclose(file);
    } else {
        corto_error("corto: failed to open file '%s' (check permissions)", cxfile);
        goto error;
    }

    /* Write class implementation */
    sprintf(srcdir, "%s/src", name);
    if (corto_mkdir(srcdir)) {
        corto_error("corto: failed to create directory '%s' (check permissions)", srcdir);
        goto error;
    }

    if (!isEmpty) {
        if (snprintf(srcfile, sizeof(srcfile), "%s/src/%s_RedPanda.c", name, name) >= (int)sizeof(srcfile)) {
            corto_error("corto: package name '%s' is too long", name);
            goto error;
        }

        if (corto_fileTest(srcfile)) {
            corto_error("corto: file '%s' already exists", srcfile);
            goto error;
        }

        file = fopen(srcfile, "w");
        if (file) {
            fprintf(file, "/* $begin(::%s::RedPanda::construct) */\n", include);
            fprintf(file, "    printf(\"Hurray, %%s the panda is born!\\n\", corto_nameof(this));\n");
            fprintf(file, "    return 0;\n");
            fprintf(file, "/* $end */\n");
            fprintf(file, "/* $begin(::%s::RedPanda::chew) */\n", include);
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
        corto_error("corto: failed to load '%s'", cxfile);
        goto error;
    }

    /* Change working directory */
    if (corto_chdir(name)) {
        corto_error("corto: can't change working directory to '%s' (check permissions)", name);
        goto error;        
    }

    if (!noBuild) {
        if (cortotool_build(0, NULL)) {
            goto error;
        }
    }

    if (!noTest) {
        if (cortotool_createTest(include, FALSE, TRUE)) {
            goto error;
        }
    }

    if (!isSilent) {
        printf("corto: done\n\n");
    }

    return 0;
error:
    return -1;
}

static corto_int16 cortotool_createEnvironment(int argc, char *argv[]) {
    char* activeEnvironment = getenv("CORTO_ENVIRONMENT");
    if (activeEnvironment) {
        corto_error("cannot create environment if %s is active", activeEnvironment);
        goto error;
    }
    if (argc < 2) {
        corto_error("did not provide environment name to create");
        goto error;
    }
    
    char* name = argv[1];
    puts(name);
    FILE* script = fopen("./.cortocreateenvironment", "w");
    if (!script) {
        goto error;
    }
    if (setenv("CORTO_CREATE_ENVIRONMENT", name, FALSE)) {
        corto_error("could not set environment variables to create corto environment");
        goto error;
    }
    fprintf(
        script,
        "env_path=\"$CORTO_HOME/env/$CORTO_CREATE_ENVIRONMENT\"\n"
        "mkdir -p \"$env_path/lib\"\n"
        "mkdir -p \"$env_path/include\"\n"
        "mkdir -p \"$env_path/bin\"\n"
        "mkdir -p \"$env_path/etc\"\n"
        "ln -s \"$CORTO_HOME/bin/corto\" \"$env_path/bin/corto\"\n"
    );
    if (fclose(script)) {
        corto_error("could not close script");
        goto error;
    }

    corto_pid pid = corto_procrun("sh", (char*[]){"sh", "./.cortocreateenvironment", NULL});
    corto_int8 procResult = 0;
    if (corto_procwait(pid, &procResult) || procResult) {
        corto_error("could not execute script");
        goto error;
    }
    if (unsetenv("CORTO_CREATE_ENVIRONMENT")) {
        corto_error("could not clean up environment variables");
        goto error;
    }
    if (corto_rm("./.cortocreateenvironment")) {
        corto_error("could not remove script");
        goto error;
    }
    return 0;
error:
    return 1;
}

corto_int16 cortotool_create(int argc, char *argv[]) {

    if (argc <= 1) {
        if (cortotool_application(argc-1, &argv[0])) {
            goto error;
        }
    } else  if (!strcmp(argv[1], CORTO_COMPONENT)) {
        if (cortotool_application(argc-1, &argv[1])) {
            goto error;
        }
    } else if (!strcmp(argv[1], CORTO_PACKAGE)) {
        if (cortotool_package(argc-1, &argv[1])) {
            goto error;
        }
    } else if (!strcmp(argv[1], CORTO_ENVIRONMENT)) {
        if (cortotool_createEnvironment(argc-1, &argv[1])) {
            goto error;
        }
    } else {
        if (cortotool_application(argc, &argv[0])) {
            goto error;
        }
    }

    return 0;
error:
    return -1;
}

corto_int16 cortotool_deleteEnvironment(int argc, char *argv[]) {
    char* activeEnvironment = getenv("CORTO_ENVIRONMENT");
    if (activeEnvironment) {
        corto_error("cannot delete environment if %s is active", activeEnvironment);
        goto error;
    }
    if (argc < 2) {
        corto_error("did not provide environment name to delete");
        goto error;
    }
    
    char* name = argv[1];
    FILE* script = fopen("./.cortodeleteenvironment", "w");
    if (!script) {
        goto error;
    }
    if (setenv("CORTO_DELETE_ENVIRONMENT", name, FALSE)) {
        corto_error("could not set environment variables to delete corto environment");
        goto error;
    }
    fprintf(
        script,
        "env_path=\"$CORTO_HOME/env/$CORTO_DELETE_ENVIRONMENT\"\n"
        "echo $CORTO_DELETE_ENVIRONMENT\n"
        "rm -rf \"$env_path\"\n"
    );
    if (fclose(script)) {
        corto_error("could not close script");
        goto error;
    }

    corto_pid pid = corto_procrun("sh", (char*[]){"sh", "./.cortodeleteenvironment", NULL});
    corto_int8 procResult = 0;
    if (corto_procwait(pid, &procResult) || procResult) {
        corto_error("could not execute script");
        goto error;
    }
    if (unsetenv("CORTO_DELETE_ENVIRONMENT")) {
        corto_error("could not clean up environment variables");
        goto error;
    }
    if (corto_rm("./.cortodeleteenvironment")) {
        corto_error("could not remove script");
        goto error;
    }
    return 0;
error:
    return 1;
}

corto_int16 cortotool_delete(int argc, char *argv[]) {
    if (argc <= 1) {
        goto error;
    } else if (!strcmp(argv[1], CORTO_ENVIRONMENT)) {
        if (cortotool_deleteEnvironment(argc-1, &argv[1])) {
            goto error;
        }
    }
    return 0;
error:
    return -1;
}

void cortotool_createHelp(void) {
    printf("Usage: corto create\n");
    printf("Usage: corto create <name> [--notest]\n");
    printf("Usage: corto create <command> <name> [--empty] [--local] [--notest]\n");
    printf("Usage: corto create <command> [--empty] [--local] [--notest]\n");
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
