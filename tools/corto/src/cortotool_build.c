
#include "cortotool_build.h"
#include "corto/lang/c/c.h"


/* Run a command for multiple projects */
static corto_int16 cortotool_runcmd(
  corto_ll dirs, char *argv[], corto_bool silent, corto_bool mute)
{
    corto_iter iter;
    corto_id cwd;
    corto_int8 ret = 0;

    strcpy(cwd, corto_cwd());

    if (dirs) {
        iter = corto_llIter(dirs);
    }

    do {
        corto_pid pid = 0;
        corto_int32 sig = 0;

        if (dirs) {
            corto_string dir = corto_iterNext(&iter);

            /* Change working directory to project */
            if (corto_chdir(dir)) {
                goto error;
            }
        }

        if (mute) {
            pid = corto_procrunRedirect(argv[0], argv,
              stdin, NULL, NULL);
        } else if (silent) {
            pid = corto_procrunRedirect(argv[0], argv,
              stdin, NULL, stderr);
        } else {
            pid = corto_procrun(argv[0], argv);
        }

        if (!pid) {
            corto_seterr("failed to start process %s", argv[0]);
            goto error;
        }

        if ((sig = corto_procwait(pid, &ret)) || ret) {
            corto_seterr("%s failed (%s %d)", argv[0],
                sig ? "signal" : "returncode", sig ? sig : ret);
            goto error;
        }

        /* Reset to previous CWD if there is more than one project to build */
        corto_chdir(cwd);

    } while (dirs && corto_iterHasNext(&iter));

    return 0;
error:
    return -1;
}

static corto_int16 cortotool_printCortoListAsRubyArray(corto_file f, const char* rubyName, corto_ll list)
{
    fprintf((FILE*)f, "%s = [\n", rubyName);
    {
        corto_stringlistForeach(list, elem) {
            fprintf((FILE*)f, "    \"%s\",\n", elem);
        }
    }
    fprintf((FILE*)f, "]\n");
    return 0;
}

static corto_int16 cortotool_writeRakefileFromPackage(corto_package package)
{
    corto_file rakefile = corto_fileOpen("rakefile");
    fprintf((FILE*)rakefile, "PACKAGE = '%s'\n", corto_path(NULL, root_o, package, "/"));

    if (corto_llSize(package->lib)) {
        cortotool_printCortoListAsRubyArray(rakefile, "LIB", package->lib);
    }
    if (corto_llSize(package->libpath)) {
        cortotool_printCortoListAsRubyArray(rakefile, "LIBPATH", package->libpath);
    }
    if (corto_llSize(package->include)) {
        cortotool_printCortoListAsRubyArray(rakefile, "INCLUDE", package->include);
    }
    if (corto_llSize(package->link)) {
        cortotool_printCortoListAsRubyArray(rakefile, "LINK", package->link);
    }
    if (corto_llSize(package->dependencies)) {
        cortotool_printCortoListAsRubyArray(rakefile, "USE_PACKAGE", package->dependencies);
    }
    if (corto_llSize(package->cflags)) {
        cortotool_printCortoListAsRubyArray(rakefile, "CFLAGS", package->cflags);
    }

    fprintf((FILE*)rakefile, "require \"#{ENV['CORTO_BUILD']}/package\"\n");
    corto_fileClose(rakefile);
    return 0;
}

corto_int16 cortotool_loadRakefile(void) {

    if (!corto_fileTest("project.json")) {
        if (!corto_fileTest("rakefile")) {
            corto_seterr("no project.json or rakefile provided");
            goto error_fileTest;
        } else {
            goto skip;
        }
    }

    char* fileContent = corto_fileLoad("project.json");
    if (!fileContent) {
        goto error_fileLoad;
    }

    corto_package package = corto_package(corto_createFromContent("text/json", fileContent));
    if (!package) {
        goto error_createFromContent;
    }

    if (cortotool_writeRakefileFromPackage(package)) {
        goto error_createRakefile;
    }

    corto_release(package);
    corto_dealloc(fileContent);

skip:
    return 0;

error_createRakefile:
    corto_delete(package);
error_createFromContent:
    corto_dealloc(fileContent);
error_fileLoad:
error_fileTest:
    return -1;
}

/*
 * Generates a rakefile if package.json exists.
 */
corto_int16 cortotool_rakefile(int argc, char* argv[])
{
    corto_string dir = NULL;
    corto_ll dirs = NULL;
    corto_iter it;

    CORTO_UNUSED(argc);

    /* Create the package loader so that if a project.json file contains a
     * nested package, the parent is automatically loaded. */
    corto_create(corto_loader_o);

    corto_argdata *data = corto_argparse(
      argv,
      (corto_argdata[]){
        {"$0", NULL, NULL}, /* Ignore first argument */
        {"--*", NULL, NULL}, /* Ignore options */
        {"*", &dirs, NULL},
        {NULL}
      }
    );

    if (!data) {
        goto error_argparse;
    }

    if (dirs) {
        it = corto_llIter(dirs);
        if (corto_iterHasNext(&it)) {
            dir = corto_iterNext(&it);
        }
    }

    do {
        if (dir) {
            if (corto_chdir(dir)) {
                corto_seterr("can't generate rakefile for '%s': %s", dir, corto_lasterr());
                goto error_chdir;
            }
        }

        if (cortotool_loadRakefile()) {
            if (dir) {
                corto_seterr("%s: %s", dir, corto_lasterr());
            }
            goto error_loadRakefile;
        }

        if (dir) {
            corto_chdir("..");
        }
    } while (dirs && corto_iterHasNext(&it) && (dir = corto_iterNext(&it)));

    corto_argclean(data);

    return 0;
error_loadRakefile:
error_chdir:
    corto_argclean(data);
error_argparse:
    corto_error("corto: %s", corto_lasterr());
    return -1;
}

/* Build a project */
corto_int16 cortotool_build(int argc, char *argv[]) {
    corto_int8 ret = 0;
    corto_ll silent, mute, coverage, dirs, release, debug, verbose, singlethread;
    corto_bool rebuild = !strcmp(argv[0], "rebuild");

    CORTO_UNUSED(argc);

    if (cortotool_rakefile(argc, argv)) {
        goto error;
    }

    corto_argdata *data = corto_argparse(
      argv,
      (corto_argdata[]){
        {"$0", NULL, NULL}, /* Ignore first argument */
        {"--silent", &silent, NULL},
        {"--mute", &mute, NULL},
        {"--verbose", &verbose, NULL},
        {"--nocoverage", &coverage, NULL},
        {"--release", &release, NULL},
        {"--debug", &debug, NULL},
        {"--singlethread", &singlethread, NULL},
        {"*", &dirs, NULL},
        {NULL}
      }
    );

    if (!data) {
        corto_seterr("invalid arguments: %s", corto_lasterr());
        goto error;
    }

    corto_trace("corto: build %s: %s %s %s",
        corto_cwd(),
        coverage ? "coverage=false" : "coverage=true",
        release ? "config=release" : "config=debug",
        singlethread ? "multithread=false" : "multithread=true"
    );

    if (rebuild) {
      ret = cortotool_runcmd(
        dirs,
        (char*[])
        {
            "rake",
            "clobber",
            "default",
            coverage ? "coverage=false" : "coverage=true",
            release ? "config=release" : "config=debug",
            verbose ? "verbose=true" : "verbose=false",
            singlethread ? "multithread=false" : "multithread=true",
            "softlinks=true",
            NULL
        }, silent != NULL, mute != NULL);
    } else {
        ret = cortotool_runcmd(
          dirs,
          (char*[])
          {
              "rake",
              coverage ? "coverage=false" : "coverage=true",
              release ? "config=release" : "config=debug",
              verbose ? "verbose=true" : "verbose=false",
              singlethread ? "multithread=false" : "multithread=true",
              "softlinks=true",
              NULL
          }, silent != NULL, mute != NULL);
    }

    corto_argclean(data);

    if (ret) {
        goto error;
    }

    return 0;
error:
    corto_error("corto: %s", corto_lasterr());
    return -1;
}

corto_int16 cortotool_clean(int argc, char *argv[]) {
    corto_int8 ret = 0;
    corto_ll dirs, verbose, silent, mute;

    CORTO_UNUSED(argc);

    if (cortotool_rakefile(argc, argv)) {
        goto error;
    }

    corto_argdata *data = corto_argparse(
      argv,
      (corto_argdata[]){
        {"$0", NULL, NULL}, /* Ignore first argument */
        {"--silent", &silent, NULL},
        {"--mute", &mute, NULL},
        {"--verbose", &verbose, NULL},
        {"--nocoverage", NULL, NULL}, /* Ignore coverage */
        {"--release", NULL, NULL}, /* Ignore release */
        {"--debug", NULL, NULL}, /* Ignore debug */
        {"--singlethread", NULL, NULL}, /* Ignore singlethread */
        {"*", &dirs, NULL},
        {NULL}
      }
    );

    ret = cortotool_runcmd(
      dirs,
      (char*[])
      {
        "rake",
        "clobber",
        verbose ? "verbose=true" : "verbose=false",
        NULL
      }, silent != NULL, mute != NULL);

    corto_argclean(data);
    if (ret) {
        goto error;
    }

    return 0;
error:
    corto_error("corto: %s", corto_lasterr());
    return -1;
}

corto_int16 cortotool_coverage(int argc, char *argv[]) {
    corto_int8 ret = 0;
    corto_ll dirs, verbose;

    CORTO_UNUSED(argc);

    corto_argdata *data = corto_argparse(
      argv,
      (corto_argdata[]){
        {"$0", NULL, NULL}, /* Ignore first argument */
        {"--silent", NULL, NULL},
        {"--mute", NULL, NULL},
        {"--verbose", &verbose, NULL},
        {"*", &dirs, NULL},
        {NULL}
      }
    );

    ret = cortotool_runcmd(
      dirs,
      (char*[])
      {
        "rake",
        "gcov",
        verbose ? "verbose=true" : "verbose=false",
        NULL
      }, FALSE, FALSE);

    corto_argclean(data);

    if (ret) {
        goto error;
    }

    return 0;
error:
    corto_error("corto: %s", corto_lasterr());
    return -1;
}

corto_int16 cortotool_rebuild(int argc, char *argv[]) {

    if (cortotool_build(argc, argv)) {
        goto error;
    }

    return 0;
error:
    return -1;
}

void cortotool_buildHelp(void) {
    printf("Usage: corto build\n");
    printf("       corto build <project>\n");
    printf("\n");
    printf("Build your Corto project.\n");
    printf("\n");
    printf("Options:\n");
    printf("   --debug         Create a debug build [default]\n");
    printf("   --release       Create a release build\n");
    printf("   --singlethread  Disable multithreaded builds\n");
    printf("   --optimize      Enable optimizations\n");
    printf("   --verbose       Verbose output. Sets CORTO_VERBOSITY to 'TRACE'\n");
    printf("   --silent        No writing to stdout\n");
    printf("   --mute          No writing to stdout and stderr\n");
    printf("\n");
}

void cortotool_rebuildHelp(void) {
    printf("Usage: corto rebuild\n");
    printf("       corto rebuild <project>\n");
    printf("\n");
    printf("Rebuild your Corto project (clean before build).\n");
    printf("\n");
    printf("Options:\n");
    printf("   --debug         Create a debug build [default]\n");
    printf("   --release       Create a release build\n");
    printf("   --silent        Suppress output from stdout\n");
    printf("   --mute          Suppress output from stdout and stderr\n");
    printf("\n");
}

void cortotool_cleanHelp(void) {
    printf("Usage: corto clean\n");
    printf("       corto clean <project>\n");
    printf("\n");
    printf("Cleans your Corto project.\n");
    printf("\n");
}
