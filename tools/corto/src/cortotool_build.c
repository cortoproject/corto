
#include "cortotool_build.h"
#include "corto/argparse/argparse.h"

static char *errfmt = "[ %l %c%m ]";

/* Run a command for multiple projects */
static corto_int16 cortotool_runcmd(
  char *argv[], corto_bool silent, corto_bool mute)
{
    corto_pid pid = 0;
    corto_int32 sig = 0;
    corto_int8 ret = 0;

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
        corto_seterr("%s: %s %d", argv[0],
            sig ? "signal" : "returncode", sig ? sig : ret);
        goto error;
    }

    return 0;
error:
    return -1;
}

static corto_int16 cortotool_printCortoListAsRubyArray(corto_file f, const char* rubyName, corto_ll list)
{
    fprintf((FILE*)f, "%s = [\n", rubyName);
    {
        corto_iter it = corto_llIter(list);
        while (corto_iterHasNext(&it)) {
            corto_string elem = corto_iterNext(&it);
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
    if (corto_llSize(package->definitions)) {
        cortotool_printCortoListAsRubyArray(rakefile, "PP_SCOPES", package->definitions);
    }
    if (corto_llSize(package->cflags)) {
        cortotool_printCortoListAsRubyArray(rakefile, "CFLAGS", package->cflags);
    }
    if (package->nocorto) {
        fprintf((FILE*)rakefile, "NOCORTO = true\n");
    }
    if (package->noapi) {
        fprintf((FILE*)rakefile, "NOAPI = true\n");
    }

    fprintf((FILE*)rakefile, "require \"#{ENV['CORTO_BUILD']}/%s\"\n", corto_idof(corto_typeof(package)));
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

    char* json = corto_fileLoad("project.json");
    if (!json) {
        goto error_fileLoad;
    }

    /* Extract id from JSON. If the package is nested, and its parent does not
     * exist, a directory must be created for the parent before the JSON can be
     * parsed. */
    corto_result r;
    memset(&r, 0, sizeof(r));
    if (corto_result_fromcontent(&r, "text/json", json)) {
        goto error_result_fromcontent;
    }

    if (!strcmp(r.type, "package")) {
        if (corto_mkdir("$CORTO_TARGET/lib/corto/$CORTO_VERSION/%s/%s", r.parent, r.id)) {
            goto error_mkdir;
        }
    } else if (!strcmp(r.type, "application")) {
        if (corto_mkdir("$CORTO_TARGET/cortobin/corto/$CORTO_VERSION/%s/%s", r.parent, r.id)) {
            goto error_mkdir;
        }        
    }

    corto_package package = corto_package(corto_createFromContent("text/json", json));
    if (!package) {
        goto error_createFromContent;
    }

    if (cortotool_writeRakefileFromPackage(package)) {
        goto error_createRakefile;
    }

    corto_release(package);
    corto_dealloc(json);
    corto_deinitp(&r, corto_result_o);

skip:
    return 0;

error_createRakefile:
    corto_delete(package);
error_mkdir:
error_result_fromcontent:
    corto_deinitp(&r, corto_result_o);
error_createFromContent:
    corto_dealloc(json);
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
        if (dirs) {
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
    corto_error("%s", corto_lasterr());
    return -1;
}

/* Build a project */
corto_int16 cortotool_build(int argc, char *argv[]) {
    corto_int8 ret = 0;
    corto_ll silent, mute, coverage, dirs, release, debug, debug_build, verbose, singlethread;
    corto_bool rebuild = !strcmp(argv[0], "rebuild");
    corto_iter iter;
    corto_id cwd;

    CORTO_UNUSED(argc);

    corto_errfmt(errfmt);

    corto_argdata *data = corto_argparse(
      argv,
      (corto_argdata[]){
        {"$0", NULL, NULL}, /* Ignore first argument */
        {"--silent", &silent, NULL},
        {"--mute", &mute, NULL},
        {"--verbose", &verbose, NULL},
        {"--coverage", &coverage, NULL},
        {"--release", &release, NULL},
        {"--debug", &debug, NULL},
        {"--debug-build", &debug_build, NULL},
        {"--singlethread", &singlethread, NULL},
        {"*", &dirs, NULL},
        {NULL}
      }
    );

    if (!data) {
        corto_seterr("invalid arguments: %s", corto_lasterr());
        goto error;
    }

    strcpy(cwd, corto_cwd());

    if (dirs) {
        iter = corto_llIter(dirs);
    }

    do {
        if (dirs) {
            corto_string dir = corto_iterNext(&iter);

            /* Change working directory to project */
            if (corto_chdir(dir)) {
                goto error;
            }
        }

        corto_trace("build %s: %s %s %s",
            corto_cwd(),
            coverage ? "coverage=true" : "coverage=false",
            release ? "config=release" : "config=debug",
            debug_build ? "debug=true" : "debug=false",
            singlethread ? "multithread=false" : "multithread=true"
        );

        if (cortotool_rakefile(1, (char*[]){"rakefile", NULL})) {
            goto error;
        }

        if (rebuild) {
          ret = cortotool_runcmd(
            (char*[])
            {
                "rake",
                "clobber",
                "default",
                coverage ? "coverage=true" : "coverage=false",
                release ? "config=release" : "config=debug",
                verbose ? "verbose=true" : "verbose=false",
                singlethread ? "multithread=false" : "multithread=true",
                "softlinks=true",
                NULL
            }, silent != NULL, mute != NULL);
        } else {
            ret = cortotool_runcmd(
              (char*[])
              {
                  "rake",
                  coverage ? "coverage=true" : "coverage=false",
                  release ? "config=release" : "config=debug",
                  verbose ? "verbose=true" : "verbose=false",
                  singlethread ? "multithread=false" : "multithread=true",
                  "softlinks=true",
                  NULL
              }, silent != NULL, mute != NULL);
        }

        /* Reset to previous CWD if there is more than one project to build */
        corto_chdir(cwd);

    } while (!ret && dirs && corto_iterHasNext(&iter));

    corto_argclean(data);

    if (ret) {
        goto error;
    }

    return 0;
error:
    corto_error("%s", corto_lasterr());
    return -1;
}

corto_int16 cortotool_clean(int argc, char *argv[]) {
    corto_int8 ret = 0;
    corto_ll dirs, verbose, silent, mute;
    corto_iter iter;
    corto_id cwd;

    CORTO_UNUSED(argc);

    corto_errfmt(errfmt);

    corto_argdata *data = corto_argparse(
      argv,
      (corto_argdata[]){
        {"$0", NULL, NULL}, /* Ignore first argument */
        {"--silent", &silent, NULL},
        {"--mute", &mute, NULL},
        {"--verbose", &verbose, NULL},
        {"--coverage", NULL, NULL}, /* Ignore coverage */
        {"--release", NULL, NULL}, /* Ignore release */
        {"--debug", NULL, NULL}, /* Ignore debug */
        {"--singlethread", NULL, NULL}, /* Ignore singlethread */
        {"*", &dirs, NULL},
        {NULL}
      }
    );

    strcpy(cwd, corto_cwd());

    if (dirs) {
        iter = corto_llIter(dirs);
    }

    do {
        if (dirs) {
            corto_string dir = corto_iterNext(&iter);

            /* Change working directory to project */
            if (corto_chdir(dir)) {
                goto error;
            }
        }

        if (cortotool_rakefile(1, (char*[]){"rakefile", NULL})) {
            goto error;
        }

        ret = cortotool_runcmd(
          (char*[])
          {
            "rake",
            "clobber",
            verbose ? "verbose=true" : "verbose=false",
            NULL
          }, silent != NULL, mute != NULL);
        
        /* Reset to previous CWD if there is more than one project to build */
        corto_chdir(cwd);

    } while (!ret && dirs && corto_iterHasNext(&iter));

    corto_argclean(data);
    if (ret) {
        goto error;
    }

    return 0;
error:
    corto_error("%s", corto_lasterr());
    return -1;
}

corto_int16 cortotool_coverage(int argc, char *argv[]) {
    corto_int8 ret = 0;
    corto_ll dirs, verbose;
    corto_iter iter;
    corto_id cwd;

    CORTO_UNUSED(argc);

    corto_errfmt(errfmt);

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

    strcpy(cwd, corto_cwd());

    do {
        if (dirs) {
            corto_string dir = corto_iterNext(&iter);

            /* Change working directory to project */
            if (corto_chdir(dir)) {
                goto error;
            }
        }

        if (cortotool_rakefile(1, (char*[]){"rakefile", NULL})) {
            goto error;
        }


        ret = cortotool_runcmd(
          (char*[])
          {
            "rake",
            "gcov",
            "silent=true",
            verbose ? "verbose=true" : "verbose=false",
            NULL
          }, FALSE, FALSE);

        /* Reset to previous CWD if there is more than one project to build */
        corto_chdir(cwd);

    } while (!ret && dirs && corto_iterHasNext(&iter));


    corto_argclean(data);

    if (ret) {
        goto error;
    }

    return 0;
error:
    corto_error("%s", corto_lasterr());
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
