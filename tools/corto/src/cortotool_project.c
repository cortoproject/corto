/* Copyright (c) 2010-2017 the corto developers
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include "cortotool_create.h"
#include "cortotool_package.h"
#include "cortotool_build.h"
#include "corto/argparse/argparse.h"

#define CORTO_PROMPT CORTO_CYAN "corto: " CORTO_NORMAL

static corto_int16 cortotool_setupProject(
    const char *projectKind,
    const char *name,
    corto_bool isLocal,
    corto_bool isSilent)
{
    CORTO_UNUSED(isLocal);

    if (!isSilent) {
        printf (CORTO_PROMPT "create %s '%s'\n", projectKind, name);
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

static corto_int16 cortotool_createProjectJson(
    const char *projectKind,
    const char *name,
    const char *shortName,
    corto_bool isLocal,
    corto_bool nocorto,
    corto_bool nocoverage,
    corto_string language)
{
    FILE *file;
    corto_id buff;
    int8_t count = 0;

    sprintf(buff, "%s/project.json", shortName);
    file = fopen(buff, "w");
    if(!file) {
        corto_error("couldn't create %s/rakefile (check permissions)", buff);
        goto error;
    }

    fprintf(file, 
        "{\n"\
        "    \"id\": \"%s\",\n"\
        "    \"type\": \"%s\",\n"\
        "    \"value\": {",
        name,
        !strcmp(projectKind, CORTO_PACKAGE) ? "package" : "application");

    fprintf(file,  "\n        \"description\": \"Making the world a better place\"");
    fprintf(file, ",\n        \"author\": \"Arthur Dent\"");
    fprintf(file, ",\n        \"version\": \"1.0.0\"");
    fprintf(file, ",\n        \"language\": \"%s\"", language);

    if (isLocal) {
        fprintf(file, ",\n        \"local\": true");
        count ++;
    }
    if (nocorto) {
        fprintf(file, ",\n        \"managed\": false");
    }
    if (nocoverage) {
        fprintf(file, ",\n        \"coverage\": false");
    }

    fprintf(file, "\n    }\n}\n");
    fclose(file);

    return 0;
error:
    return -1;
}

static corto_int16 cortotool_createTest(corto_string name, corto_bool isPackage, corto_bool isLocal, corto_string language) {
    FILE *file;

    if (corto_mkdir("test")) {
        corto_error("couldn't create test directory for '%s' (check permissions)", name);
        goto error;
    }
    if (corto_mkdir("test/src")) {
        corto_error("couldn't create test/src directory for '%s' (check permissions)", name);
        goto error;
    }

    if (cortotool_create(
        8,
        (char*[]){
            "create",
            "package",
            "/test",
            "--notest",
            "--local",
            "--silent",
            "--nobuild",
            "--nocoverage",
            "--lang",
            language,
            NULL}
    )) {
        corto_error("couldn't create test skeleton (check permissions)");
        goto error;
    }

    corto_id filename;
    if (!strcmp(language, "c")) {
        sprintf(filename, "src/test.c");
    } else {
        sprintf(filename, "src/test.cpp");
    }
    file = fopen(filename, "w");
    if (file) {
        fprintf(file, "/* $begin(main) */\n");
        fprintf(file, "    int result = 0;\n");
        fprintf(file, "    test_Runner runner = test_RunnerCreate(\"%s\", argv[0], (argc > 1) ? argv[1] : NULL);\n", name);
        fprintf(file, "    if (!runner) return -1;\n");
        fprintf(file, "    if (corto_ll_size(runner->failures)) {\n");
        fprintf(file, "        result = -1;\n");
        fprintf(file, "    }\n");
        fprintf(file, "    corto_delete(runner);\n");
        fprintf(file, "    return result;\n");
        fprintf(file, "/* $end */\n");
        fclose(file);
    } else {
        corto_error("couldn't create 'test/%s' (check permissions)", filename);
        goto error;
    }

    file = fopen("test.cx", "w");
    if (file) {
        fprintf(file, "#package ::test\n\n");
        fprintf(file, "test/Suite MySuite::\n");
        fprintf(file, "    void testSomething()\n\n");
        fclose(file);
    } else {
        corto_error("couldn't create 'test/test.cx' (check permissions)");
        goto error;
    }

    if (cortotool_add(
        4,
        (char*[]){"add", "/corto/test", "--silent", "--nobuild", NULL}
    )) {
        goto error;
    }

    if (isPackage && !isLocal) {
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
        corto_error("failed to change directory to parent");
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

static char* cortotool_fmtName(
    corto_id buffer,
    corto_id parentName,
    char *projectname,
    char **name_out)
{
    strcpy(buffer, projectname);
    char *include = buffer;

    /* Ignore initial colons and slashes */
    if (include[0] == ':') {
        if (include[1] == ':') {
            include += 2;
        } else {
            corto_seterr("invalid package name");
            goto error;
        }
    }
    if (include[0] == '/') {
        include += 1;
    }

    /* Extract left-most name from include variable & replace :: */
    char *ptr = include;
    char *name = include;
    corto_int32 i, offset = 0;
    for (i = 0; i < strlen(include); i++) {
        if (*ptr == '/') {
            name = ptr + 1;
        } else if (*ptr == ':') {
            offset ++;
            ptr++;
            *ptr = '/';
            name = &ptr[-offset] + 1;
        }
        ptr[-offset] = *ptr;
        ptr++;
    }

    if (name_out) *name_out = name;

    if (parentName) {
        parentName[0] = '\0';
    }
    if (parentName && (name != include)) {
        strcpy(parentName, include);
        if (parentName[name - include - 1] == '/') {
            parentName[name - include - 1] = '\0';
        } else {
            parentName[name - include - 2] = '\0';
        }
    }

    return include;
error:
    return NULL;
}

static corto_int16 cortotool_app (
    const char *projectKind,
    char *projectName,
    corto_bool silent,
    corto_bool mute,
    corto_bool nobuild,
    corto_bool notest,
    corto_bool local,
    corto_bool nocorto,
    corto_bool nocoverage,
    corto_string language)
{
    corto_id buff, includeMem;
    FILE *file;
    char *name = NULL, *include;

    silent |= mute;

    if (!(include = cortotool_fmtName(includeMem, NULL, projectName, &name))) {
        if (!mute) {
            corto_error("%s", corto_lasterr());
        }
        goto error;
    }

    if (cortotool_setupProject(projectKind, name, local, silent)) {
        goto error;
    }

    if (cortotool_createProjectJson(projectKind, include, name, local, nocorto, nocoverage, language)) {
        goto error;
    }

    sprintf(buff, "%s/src", name);
    if (corto_mkdir(buff)) {
        corto_error("couldn't create %s directory (check permissions)", buff);
        goto error;
    }

    if (!strcmp(language, "c")) {
        sprintf(buff, "%s/src/%s.c", name, name);
    } else {
        sprintf(buff, "%s/src/%s.cpp", name, name);
    }
    file = fopen(buff, "w");
    if (file) {
        if (!nocorto) {
            fprintf(file, "#include \"%s.h\"\n\n", name);
        }
        fprintf(file, "int %s%s(int argc, char *argv[]) {\n\n", nocorto ? "" : name, nocorto ? "main" : "Main");
        if (!nocorto) {
            fprintf(file, "    printf(\"Hello Corto!\\n\");\n\n");
        }
        fprintf(file, "    return 0;\n");
        fprintf(file, "}\n");
        fclose(file);
    } else {
        corto_error("couldn't create '%s' (check permissions)", buff);
        goto error;
    }

    if (corto_chdir(name)) {
        corto_error("can't change working directory to '%s' (check permissions)", buff);
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
            FALSE,
            local,
            language))
        {
            goto error;
        }
    }

    if (!silent) {
        printf(CORTO_PROMPT "done\n\n");
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
    corto_bool nocorto,
    corto_bool nodef,
    corto_bool nocoverage,
    corto_string language)
{
    corto_id cxfile, srcfile, srcdir, parentName;
    corto_id includeMem;
    corto_char *name = NULL, *include = NULL;
    FILE *file;

    silent |= mute;

    if (!(include = cortotool_fmtName(includeMem, parentName, projectname, &name))) {
        if (!mute) {
            corto_error("%s", corto_lasterr());
        }
        goto error;
    }

    if (cortotool_setupProject(CORTO_PACKAGE, name, local, silent)) {
        goto error;
    }

    if (cortotool_createProjectJson(CORTO_PACKAGE, include, name, local, nocorto, nocoverage, language)) {
        goto error;
    }

    /* Write definition file */
    if (!nocorto) {
        if (snprintf(cxfile, sizeof(cxfile), "%s/%s.cx", name, name) >=
            (int)sizeof(cxfile))
        {
            if (!mute) {
                corto_error("package name '%s' is too long", name);
            }
            goto error;
        }

        if (corto_fileTest(cxfile)) {
            if (!mute) {
                corto_error("package '%s' already exists", cxfile);
            }
            goto error;
        }
    }

    if (corto_mkdir(name)) {
        if (!mute) {
            corto_error(
                "corto: failed to create directory '%s' (check permissions)",
                name);
        }
        goto error;
    }

    if (!nodef && !nocorto) {
        file = fopen(cxfile, "w");
        if (file) {
            fprintf(file, "#package /%s\n\n", include);
            fclose(file);
        } else {
            corto_error(
                "corto: failed to open file '%s' (check permissions)",
                cxfile);
            goto error;
        }
    }

    /* Create src and include folders */
    sprintf(srcdir, "%s/include", name);
    if (corto_mkdir(srcdir)) {
        corto_error(
          "corto: failed to create directory '%s' (check permissions)",
          srcdir);
        goto error;
    }

    sprintf(srcdir, "%s/src", name);
    if (corto_mkdir(srcdir)) {
        corto_error(
          "corto: failed to create directory '%s' (check permissions)",
          srcdir);
        goto error;
    }

    /* When package doesn't have a definition, create an empty header and source
     * file upon creation of the package. The header is mandatory- at least one
     * header with the name of the package must exist. These files will be
     * untouched by code generation when rebuilding the package with nocorto */
    if (nocorto) {
        if (snprintf(srcfile,
            sizeof(srcfile),
            "%s/include/%s.h",
            name, name) >= (int)sizeof(srcfile))
        {
            if (!mute) {
                corto_error("package name '%s' is too long", name);
            }
            goto error;
        }

        /* Don't overwrite file if it already exists */
        if (!corto_fileTest(srcfile)) {
            file = fopen(srcfile, "w");
            if (file) {
                /* Create macro identifier the hard way */
                corto_id macro;
                char *ptr = macro, ch;
                strcpy(macro, include);
                corto_strupper(macro);
                while ((ch = *ptr)) {
                    if (ch == '/') {
                        *ptr = '_';
                    } else if (ch == ':') {
                        *ptr = '_';
                        memmove(ptr, ptr + 1, strlen(ptr + 1));
                    }
                    ptr ++;
                }

                fprintf(file, "\n");
                fprintf(file, "#ifndef %s_H\n", macro);
                fprintf(file, "#define %s_H\n", macro);
                fprintf(file, "\n");
                fprintf(file, "/* Add include files here */\n");
                fprintf(file, "\n");
                fprintf(file, "#ifdef __cplusplus\n");
                fprintf(file, "extern \"C\" {\n");
                fprintf(file, "#endif\n");
                fprintf(file, "\n");
                fprintf(file, "/* Insert definitions here */\n");
                fprintf(file, "\n");
                fprintf(file, "#ifdef __cplusplus\n");
                fprintf(file, "}\n");
                fprintf(file, "#endif\n\n");
                fprintf(file, "#endif /* %s_H */\n\n", macro);
                fclose(file);
            } else {
                if (!mute) {
                    corto_error("failed to open file '%s'", srcfile);
                }
                goto error;
            }
        }
    }

    if (!strcmp(language, "c")) {
        snprintf(srcfile, sizeof(srcfile), "%s/src/%s.c", name, name);
    } else {
        snprintf(srcfile, sizeof(srcfile), "%s/src/%s.cpp", name, name);
    }
    if (nocorto) {
        /* Don't overwrite file if it already exists */
        if (!corto_fileTest(srcfile)) {
            file = fopen(srcfile, "w");
            if (file) {
                fprintf(file, "\n");
                if (local) {
                    fprintf(file, "#include \"%s.h\"\n", name);
                } else {
                    fprintf(file, "#include \"%s/%s.h\"\n", include, name);
                }
                fprintf(file, "\n");
                fprintf(file, "/* Add implementation here */\n");
                fprintf(file, "\n");
                fprintf(file, "/* cortomain is called when the package is loaded by Corto. It is a good\n");
                fprintf(file, " * place for initialization code that needs to be executed once.\n");
                fprintf(file, " * The function can be safely removed if not needed. */\n");
                fprintf(file, "int cortomain(int argc, char *argv[]) {\n\n");
                fprintf(file, "    return 0;\n");
                fprintf(file, "}\n");
                fprintf(file, "\n");
                fclose(file);
            } else {
                if (!mute) {
                    corto_error("failed to open file '%s'", srcfile);
                }
                goto error;
            }
        }
    } else if (nodef) {
        /* Don't overwrite file if it already exists */
        if (!corto_fileTest(srcfile)) {
            file = fopen(srcfile, "w");
            if (file) {
                fprintf(file, "\n");
                if (local) {
                    fprintf(file, "#include \"%s.h\"\n", name);
                } else {
                    fprintf(file, "#include \"%s/%s.h\"\n", include, name);
                }
                fprintf(file, "\n");
                fprintf(file, "/* Add implementation here */\n");
                fprintf(file, "\n");
                fprintf(file, "/* Enter package initialization code here */\n");
                fprintf(file, "int %sMain(int argc, char *argv[]) {\n\n", name);
                fprintf(file, "    return 0;\n");
                fprintf(file, "}\n");
                fprintf(file, "\n");
                fclose(file);
            } else {
                if (!mute) {
                    corto_error("failed to open file '%s'", srcfile);
                }
                goto error;
            }
        } else {
            corto_error("file already exists, can't generate", srcfile);
            goto error;
        }
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
        if (cortotool_build(2, (char*[]){"build", "--silent", nocoverage ? "--nocoverage" : "", NULL})) {
            goto error;
        }
    }

    if (!notest) {
        if (cortotool_createTest(include, TRUE, local, language)) {
            goto error;
        }
    }

    if (!silent) {
        printf(CORTO_PROMPT " done\n\n");
    }

    return 0;
error:
    return -1;
}

corto_int16 cortotool_create(int argc, char *argv[]) {
    corto_ll silent, mute, nobuild, notest, local;
    corto_ll apps, packages, nocorto, nodef, nocoverage;
    corto_ll apps_noname, packages_noname, lang;
    corto_string language = "c";

    CORTO_UNUSED(argc);

    corto_argdata *data = corto_argparse(
      argv,
      (corto_argdata[]){
        {"$0", NULL, NULL}, /* Ignore 'create' */
        {"--silent", &silent, NULL},
        {"--mute", &mute, NULL},
        {"--nobuild", &nobuild, NULL},
        {"--notest", &notest, NULL},
        {"--unmanaged", &nocorto, NULL},
        {"--nodef", &nodef, NULL},
        {"--local", &local, NULL},
        {"--nocoverage", &nocoverage, NULL},
        {"--lang", NULL, &lang},
        {CORTO_APPLICATION, NULL, &apps},
        {CORTO_PACKAGE, NULL, &packages},
        {CORTO_APPLICATION, &apps_noname, NULL},
        {CORTO_PACKAGE, &packages_noname, NULL},
        {"$1", &apps, NULL},
        {NULL}
      }
    );

    if (!data) {
        corto_error("%s", corto_lasterr());
        goto error;
    }

    if (nocorto) {
        notest = nocorto;
    }

    if (lang) {
        language = corto_ll_get(lang, 0);
    }

    /* If no arguments are provided, create an application with a random name */
    if (!apps && !packages && !apps_noname && !packages_noname)
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
            nocorto != NULL,
            nocoverage != NULL,
            language))
        {
            goto error;
        }
    }

    if (apps) {
        corto_iter iter = corto_ll_iter(apps);
        while (corto_iter_hasNext(&iter)) {
            char *name = corto_iter_next(&iter);
            if (cortotool_app(
                CORTO_APPLICATION,
                name,
                silent != NULL,
                mute != NULL,
                nobuild != NULL,
                notest != NULL,
                local != NULL,
                nocorto != NULL,
                nocoverage != NULL,
                language))
            {
                goto error;
            }
        }
    }

    if (apps_noname) {
        corto_iter iter = corto_ll_iter(apps_noname);
        while (corto_iter_hasNext(&iter)) {
            char *name = cortotool_randomName();
            corto_iter_next(&iter);
            if (cortotool_app(
                CORTO_APPLICATION,
                name,
                silent != NULL,
                mute != NULL,
                nobuild != NULL,
                notest != NULL,
                local != NULL,
                nocorto != NULL,
                nocoverage != NULL,
                language))
            {
                goto error;
            }
        }
    }

    if (packages) {
        corto_iter iter = corto_ll_iter(packages);
        while (corto_iter_hasNext(&iter)) {
            char *name = corto_iter_next(&iter);
            if (cortotool_package(
                name,
                silent != NULL,
                mute != NULL,
                nobuild != NULL,
                notest != NULL,
                local != NULL,
                nocorto != NULL,
                nodef != NULL,
                nocoverage != NULL,
                language))
            {
                goto error;
            }
        }
    }

    if (packages_noname) {
        corto_iter iter = corto_ll_iter(packages_noname);
        while (corto_iter_hasNext(&iter)) {
            char *name = cortotool_randomName();
            corto_iter_next(&iter);
            if (cortotool_package(
                name,
                silent != NULL,
                mute != NULL,
                nobuild != NULL,
                notest != NULL,
                local != NULL,
                nocorto != NULL,
                nodef != NULL,
                nocoverage != NULL,
                language))
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
    printf("\n");
    printf("Options:\n");
    printf("   --local        Create a project that won't be installed to the package repository\n");
    printf("   --unmanaged    Create an unmanaged project that doens't use corto code generation\n");
    printf("   --notest       Do not create a test skeleton\n");
    printf("   --nodef        Do not generate a definition file\n");
    printf("   --nobuild      Do not build the project after creating it\n");
    printf("   --nocoverage   Disable coverage analysis for project\n");
    printf("   --silent       Suppress output from stdout\n");
    printf("   --mute         Suppress output from stdout and stderr\n");
    printf("\n");
}
