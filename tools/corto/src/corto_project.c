
#include "corto_create.h"
#include "corto_package.h"
#include "corto_build.h"

static cx_int16 corto_setupProject(const char *name, cx_bool isLocal, cx_bool isSilent) {
    if (!isSilent) {
    	printf ("corto: create project '%s'\n", name);
    }

    if (cx_fileTest(name)) {
        cx_id id;
        sprintf(id, "%s/.corto", name);
        if (cx_fileTest(id)) {
            cx_error("corto: a project with the name '%s' already exists!", name);
            goto error;
        }
    } else if (cx_mkdir(name)) {
        cx_error("corto: couldn't create project directory '%s' (check permissions)", name);
        goto error;
    }

    if (!isLocal) {
        cx_pid pid = cx_procrun("git", (char*[]){"git", "init", (char *)name, NULL});
        if (pid && cx_procwait(pid, NULL)) {
            cx_error("corto: failed to initialize git repository (is git installed?)\n");
            goto error;
        }
    }

	return 0;
error:
	return -1;
}

static cx_int16 corto_createRakefile(const char *projectKind, const char *name, const char *shortName, cx_bool isLocal) {
    FILE *file;
    cx_id buff;

    sprintf(buff, "%s/rakefile", shortName);
    file = fopen(buff, "w");
    if(!file) {
    	cx_error("corto: couldn't create %s/rakefile (check permissions)", buff);
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

static cx_int16 corto_createTest(cx_string name, cx_bool isComponent) {
    FILE *file;

    if (cx_mkdir("test")) {
        cx_error("corto: couldn't create test directory for '%s' (check permissions)", name);
        goto error;
    }
    if (cx_mkdir("test/src")) {
        cx_error("corto: couldn't create test/src directory for '%s' (check permissions)", name);
        goto error;
    }

    if (corto_create(
        7,
        (char*[]){"create", "package", "::test", "--empty", "--notest", "--local", "--silent"}
    )) {
        cx_error("corto: couldn't create test skeleton (check permissions)");
        goto error;
    }

    file = fopen("src/test.c", "w");
    if (file) {
        fprintf(file, "/* $begin(main) */\n");
        fprintf(file, "    int result = 0;\n");
        fprintf(file, "    test_Runner runner = test_RunnerCreate(\"%s\");\n", name);
        fprintf(file, "    if (!runner) return -1;\n");
        fprintf(file, "    if (cx_llSize(runner->failures)) {\n");
        fprintf(file, "        result = -1;\n");
        fprintf(file, "    }\n");
        fprintf(file, "    cx_delete(runner);\n");
        fprintf(file, "    return result;\n");
        fprintf(file, "/* $end */\n");
        fclose(file);
    } else {
        cx_error("corto: couldn't create 'test/src/test.c' (check permissions)");
        goto error;
    }

    file = fopen("test.cx", "w");
    if (file) {
        fprintf(file, "#package ::test\n\n");
        fprintf(file, "class fooSuite: test::Suite::\n"); 
        fprintf(file, "    void dummyCase() test::Case\n\n");
        fclose(file);
    } else {
        cx_error("corto: couldn't create 'test/test.cx' (check permissions)");
        goto error;
    }

    if (corto_add(
        4,
        (char*[]){"add", "::corto::test", "--silent", "--nobuild"}
    )) {
        goto error;
    }

    if (name) {
        if (isComponent) {
            if (corto_add(
                5,
                (char*[]){"add", name, "--component", "--silent", "--nobuild"}
            )) {
                goto error;
            }
        } else {
            if (corto_add(
                3,
                (char*[]){"add", name, "--silent", "--nobuild"}
            )) {
                goto error;
            }
        }
    }

    /* Timestamps of the files are likely too close to trigger a build, so explicitly
     * do a rebuild of the test project */
    corto_rebuild(1, (char*[]){"rebuild"});

    if (cx_chdir("..")) {
        cx_error("corto: failed to change directory to parent");
        goto error;
    }

    return 0;
error:
    return -1;
}

static char* corto_randomName(void) {
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

static cx_int16 corto_parseProjectArgs(
    int argc, 
    char *argv[], 
    cx_bool *isEmpty, 
    cx_bool *isLocal, 
    cx_bool *noTest, 
    cx_bool *silent) 
{
    cx_int32 i;
    for (i = 0; i < argc; i++) {
        if (!strcmp(argv[i], "--empty")) {
            if (isEmpty) *isEmpty = TRUE;
        } else if (!strcmp(argv[i], "--local")) {
            if (isLocal) *isLocal = TRUE;
        } else if (!strcmp(argv[i], "--notest")) {
            if (noTest) *noTest = TRUE;
        } else if (!strcmp(argv[i], "--silent")) {
            if (silent) *silent = TRUE;
        } else {
            cx_error("corto: unknown option '%s'", argv[i]);
            goto error;
        }
    }
    return 0;
error:
    return -1;
}

static cx_int16 corto_application(int argc, char *argv[]) {
	cx_id buff;
	FILE *file;
	cx_bool isApplication = !strcmp(argv[0], "create") || !strcmp(argv[0], CORTO_APPLICATION);
    cx_uint32 optionsStartFrom = 1;
	char *name;
    cx_bool isLocal = FALSE, noTest = FALSE, isSilent = FALSE;

	if ((argc <= 1) || (*argv[1] == '-')) {
        name = corto_randomName();
	} else {
        name = argv[1];
        optionsStartFrom = 2;
    }

    /* Parse options */
    if (corto_parseProjectArgs(argc - optionsStartFrom, &argv[optionsStartFrom], NULL, &isLocal, &noTest, &isSilent)) {
        goto error;
    }

	if (corto_setupProject(name, isLocal, isSilent)) {
		goto error;
	}

	if (corto_createRakefile(isApplication ? CORTO_APPLICATION : argv[0], name, name, isLocal)) {
		goto error;
	}

	sprintf(buff, "%s/src", name);
	if (cx_mkdir(buff)) {
		cx_error("corto: couldn't create %s directory (check permissions)", buff);
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
        cx_error("corto: couldn't create '%s' (check permissions)", buff);
        goto error;
    }

    if (cx_chdir(name)) {
    	cx_error("corto: can't change working directory to '%s' (check permissions)", buff);
    	goto error;
    }

    if (corto_build(0, NULL)) {
    	goto error;
    }

    if (!noTest) {
        if (corto_createTest(isApplication ? NULL : name, !isApplication)) {
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

static cx_int16 corto_package(int argc, char *argv[]) {
    cx_id cxfile, srcfile, srcdir;
    cx_char *ptr, *name;
    FILE *file;
    cx_uint32 i;
    cx_char *include = NULL;
    cx_uint32 optionsStartFrom = 1;
    cx_bool isEmpty = FALSE, isLocal = FALSE, noTest = FALSE, isSilent = FALSE;

    if ((argc <= 1) || (*(argv[1])) == '-') {
        include = corto_randomName();
    } else {
        include = argv[1];
        optionsStartFrom = 2;
    }

    /* Ignore initial colons */
    if (include[0] == ':') {
        if (include[1] == ':') {
            include += 2;
        } else {
            cx_error("corto: invalid package name");
            goto error;
        }
    }

    /* Parse options */
    if (corto_parseProjectArgs(argc - optionsStartFrom, &argv[optionsStartFrom], &isEmpty, &isLocal, &noTest, &isSilent)) {
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

   	if (corto_setupProject(name, isLocal, isSilent)) {
		goto error;
	}

	if (corto_createRakefile(CORTO_PACKAGE, include, name, isLocal)) {
		goto error;
	}

    /* Write definition file */
    if (snprintf(cxfile, sizeof(cxfile), "%s/%s.cx", name, name) >= (int)sizeof(cxfile)) {
        cx_error("corto: package name '%s' is too long", name);
        goto error;
    }

    if (cx_fileTest(cxfile)) {
        cx_error("corto: package '%s' already exists", cxfile);
        goto error;
    }

    if (cx_mkdir(name)) {
        cx_error("corto: failed to create directory '%s' (check permissions)", name);
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
        cx_error("corto: failed to open file '%s' (check permissions)", cxfile);
        goto error;
    }

    /* Write class implementation */
    sprintf(srcdir, "%s/src", name);
    if (cx_mkdir(srcdir)) {
        cx_error("corto: failed to create directory '%s' (check permissions)", srcdir);
        goto error;
    }

    if (!isEmpty) {
        if (snprintf(srcfile, sizeof(srcfile), "%s/src/%s_RedPanda.c", name, name) >= (int)sizeof(srcfile)) {
            cx_error("corto: package name '%s' is too long", name);
            goto error;
        }

        if (cx_fileTest(srcfile)) {
            cx_error("corto: file '%s' already exists", srcfile);
            goto error;
        }

        file = fopen(srcfile, "w");
        if (file) {
            fprintf(file, "/* $begin(::%s::RedPanda::construct) */\n", include);
            fprintf(file, "    printf(\"Hurray, %%s the panda is born!\\n\", cx_nameof(this));\n");
            fprintf(file, "    return 0;\n");
            fprintf(file, "/* $end */\n");
            fprintf(file, "/* $begin(::%s::RedPanda::chew) */\n", include);
            fprintf(file, "    this->weight++;\n");
            fprintf(file, "    printf(\"%%s the panda is chewing on something omnomnom (his weight: %%d)\\n\",\n");
            fprintf(file, "            cx_nameof(this), this->weight);\n");
            fprintf(file, "/* $end */\n");
            fclose(file);
        } else {
            cx_error("corto: failed to open file '%s'", cxfile);
            goto error;
        }
    }

    if (cx_load(cxfile)) {
        cx_error("corto: failed to load '%s'", cxfile);
        goto error;
    }

    /* Change working directory */
    if (cx_chdir(name)) {
        cx_error("corto: can't change working directory to '%s' (check permissions)", name);
        goto error;        
    }

    if (corto_build(0, NULL)) {
        goto error;
    }

    if (!noTest) {
        if (corto_createTest(include, FALSE)) {
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

cx_int16 corto_create(int argc, char *argv[]) {

	if (argc <= 1) {
        if (corto_application(argc-1, &argv[0])) {
            goto error;
        }
	} else 
	if (!strcmp(argv[1], CORTO_COMPONENT)) {
		if (corto_application(argc-1, &argv[1])) {
			goto error;
		}
	} else
	if (!strcmp(argv[1], CORTO_PACKAGE)) {
		if (corto_package(argc-1, &argv[1])) {
			goto error;
		}
	} else {
		if (corto_application(argc, &argv[0])) {
			goto error;
		}
	}

	return 0;
error:
	return -1;
}

void corto_createHelp(void) {
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
