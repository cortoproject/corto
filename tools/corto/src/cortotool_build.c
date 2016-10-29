
#include "cortotool_build.h"

/* Run a command for multiple projects */
corto_int16 cortotool_runcmd(
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

/* Build a project */
corto_int16 cortotool_build(int argc, char *argv[]) {
    corto_int8 ret = 0;
    corto_ll silent, mute, coverage, dirs, release, debug, verbose, singlethread;

    CORTO_UNUSED(argc);

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

    corto_trace("corto: build %s: %s %s %s",
        corto_cwd(),
        coverage ? "coverage=false" : "coverage=true",
        release ? "target=release" : "target=debug",
        singlethread ? "multithread=false" : "multithread=true"
    );

    ret = cortotool_runcmd(
      dirs,
      (char*[])
      {
          "rake",
          coverage ? "coverage=false" : "coverage=true",
          release ? "target=release" : "target=debug",
          verbose ? "verbose=true" : "verbose=false",
          singlethread ? "multithread=false" : "multithread=true",
          "softlinks=true",
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

corto_int16 cortotool_clean(int argc, char *argv[]) {
    corto_int8 ret = 0;
    corto_ll dirs, verbose, silent, mute;

    CORTO_UNUSED(argc);

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
    if (cortotool_clean(argc, argv)) {
        goto error;
    }

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
