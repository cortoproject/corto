
#include "cortotool_run.h"
#include "cortotool_build.h"
#include "cortotool_install.h"
#include "corto/argparse/argparse.h"
#include <sys/stat.h>
#include <errno.h>

static int retcode;

typedef struct corto_fileMonitor {
    char *file;
    char *lib;
    time_t mtime;
} corto_fileMonitor;

corto_fileMonitor* cortotool_monitorNew(char *file, char *lib) {
    corto_fileMonitor *mon = corto_alloc(sizeof(corto_fileMonitor));
    mon->file = corto_strdup(file);
    mon->lib = lib ? corto_strdup(lib) : NULL;
    mon->mtime = 0;

    return mon;
}

static void cortotool_addChangedLibrary(corto_ll *libs, corto_string lib) {
    if (*libs && lib) {
        corto_iter iter = corto_llIter(*libs);
        while (corto_iter_hasNext(&iter)) {
            corto_string l = corto_iter_next(&iter);
            if (!strcmp(l, lib)) {
                return;
            }
        }
    }

    if (!*libs) {
        *libs = corto_llNew();
    }
    corto_llAppend(*libs, lib);
}

static corto_ll cortotool_getModified(corto_ll files, corto_ll changed) {
    corto_int32 i = 0;
    corto_ll libs = NULL;

    if (changed) {
        corto_llFree(changed);
        changed = NULL;
    }

    if (files) {
        corto_iter iter = corto_llIter(files);
        while (corto_iter_hasNext(&iter)) {
            struct stat attr;
            corto_fileMonitor *mon = corto_iter_next(&iter);

            if (stat(mon->file, &attr) < 0) {
                printf("corto: failed to stat '%s' (%s)\n", mon->file, strerror(errno));
            }

            if (mon->mtime) {
                if (mon->mtime != attr.st_mtime) {
                    cortotool_addChangedLibrary(&libs, mon->lib);
                }
            }
            mon->mtime = attr.st_mtime;

            i++;
        }
    }

    return libs;
}

static corto_ll cortotool_waitForChanges(corto_pid pid, corto_ll files, corto_ll changed) {
    corto_int32 i = 0;

    if (changed) {
        corto_llFree(changed);
        changed = NULL;
    }

    do {
        corto_sleep(0, 50000000);

        /* Check if process is still running */
        if (pid) {
            if ((retcode = corto_proccheck(pid, NULL))) {
                break;
            }
        }

        i++;

        /* Only check files every second */
        if (!(i % 20)) {
            changed = cortotool_getModified(files, changed);
        } else {
            continue;
        }
    }while (!changed || (pid && retcode));

    return changed;
}

static int cortotool_addDirToMonitor(corto_string dir, corto_ll monitorList) {
    corto_id cortoDir, srcDir;
    sprintf(cortoDir, "%s/.corto", dir);
    sprintf(srcDir, "%s/src", dir);

    corto_ll files = corto_opendir(srcDir);
    if (!files || !corto_fileTest(cortoDir)) {
        corto_error("'%s' isn't a valid project directory", dir);
        goto error;
    }

    corto_iter iter = corto_llIter(files);
    while (corto_iter_hasNext(&iter)) {
        corto_id srcFile;
        corto_string file = corto_iter_next(&iter);
        sprintf(srcFile, "%s/src/%s", dir, file);
        corto_fileMonitor *mon = cortotool_monitorNew(srcFile, dir);
        corto_llAppend(monitorList, mon);
    }

    corto_closedir(files);

    return 0;
error:
    return -1;
}

static int cortotool_buildDependency(corto_string path) {
    corto_int8 procResult = 0;

    /* Build */
    corto_pid pid = corto_procrun("corto", (char*[]){"corto", "build", path, "--silent", NULL});
    if (corto_procwait(pid, &procResult) || procResult) {
        printf("corto: failed to build '%s'\n", path);
        goto error;
    }

    return 0;
error:
    return -1;
}

static corto_ll cortotool_gatherFiles(void) {
    corto_ll result = corto_llNew();
    corto_ll packages;

    if (cortotool_addDirToMonitor(".", result)) {
        goto error;
    }

    /* Walk packages */
    packages = corto_loadGetPackages();
    corto_iter iter = corto_llIter(packages);
    while (corto_iter_hasNext(&iter)) {
        corto_id sourceLink;
        corto_string package = corto_iter_next(&iter);
        corto_string file = corto_locate(package, NULL, CORTO_LOCATION_LIB);
        if (!file) {
            corto_error("package '%s' could not be located\n", package);
            corto_error("  try: corto install %s", package);
            goto error;
        }
        corto_fileMonitor *mon = cortotool_monitorNew(file, NULL);
        if (file) {
            corto_llAppend(result, mon);
        } else {
            printf("couldn't find file '%s'\n", file);
        }

        /* Check if there are source files available to monitor */
        cortotool_toLibPath(file);
        sprintf(sourceLink, "%s/source.txt", file);
        if (corto_fileTest(sourceLink)) {
            corto_string path = corto_fileLoad(sourceLink);

            /* Strip newline */
            path[strlen(path)-1] = '\0';
            cortotool_buildDependency(path);

            if (cortotool_addDirToMonitor(path, result)) {
                goto error;
            }
        }
    }

    return result;
error:
    corto_llFree(result);
    return NULL;
}

corto_int16 cortotool_debug(int argc, char *argv[]) {
    CORTO_UNUSED(argc);
    CORTO_UNUSED(argv);

    if (argc > 1) {
        corto_chdir(argv[1]);
    }

    corto_pid pid = corto_procrun("lldb", (char*[]){".corto/app", NULL});
    if (pid) {
        corto_procwait(pid, NULL);
    }

    return 0;
}

corto_int16 cortotool_monitor(char *argv[]) {
    corto_pid pid = 0;
    corto_ll files;
    corto_ll changed = NULL;
    corto_uint32 retries = 0;
    corto_int32 rebuild = 0;
    corto_int32 depErrors = 0;

    files = cortotool_gatherFiles();
    if (!files) {
        return -1;
    }

    cortotool_getModified(files, NULL);

    /* Add $HOME/.corto/lib to LD_LIBRARY_PATH so that 3rd party libraries
     * installed to /usr/local/lib are also available when doing development
     * in local environment. */
    corto_setenv("LD_LIBRARY_PATH", "$HOME/.corto/lib:$LD_LIBRARY_PATH");

    while (!retcode) {

        /* Build the project */
        if (!changed) {
            corto_rm(".corto/app");
            cortotool_build(2, (char*[]){"build", "--silent", NULL});
            rebuild++;
        } else {
            depErrors = 0;
            corto_iter iter = corto_llIter(changed);
            while (corto_iter_hasNext(&iter)) {
                corto_string lib = corto_iter_next(&iter);
                if (lib && strcmp(lib, ".")) {
                    printf("corto: '%s' changed, rebuilding\n", lib);
                    if (!cortotool_buildDependency(lib)) {
                        rebuild++;
                    } else {
                        depErrors++;
                    }
                } else {
                    rebuild++;
                }
            }

            /* Don't trigger on the changes in dependency binary file due to the builds */
            changed = cortotool_getModified(files, changed);

            /* Rebuild the app */
            if (rebuild) {
                corto_rm(".corto/app");
                cortotool_build(2, (char*[]){"build", "--silent", NULL});
            } else if (depErrors) {
                printf("corto: won't restart because dependency failed to rebuild\n");
            }
        }

        if (pid && rebuild) {
            /* Send interrupt signal to process */
            if (corto_prockill(pid, CORTO_SIGINT)) {
                /* Wait until process has exited */
                corto_procwait(pid, NULL);
            }
            rebuild = 0;
            pid = 0;
        }

        /* Test whether the app exists, then start it */
        if (corto_fileTest(".corto/app")) {
            if (retries && !pid) {
                printf("corto: restarting app (%dx)\n", retries);
            }

            /* Start process */
            if (!pid) {
                pid = corto_procrun(".corto/app", &argv[1]);
            }

            /* Wait until either source changes, or executable finishes */
            changed = cortotool_waitForChanges(pid, files, changed);

            /* Set pid to 0 if process has exited */
            if (retcode) {
                pid = 0;
            }
        } else {
            corto_error("fix your code!\n");

            /* Wait for changed before trying again */
            changed = cortotool_waitForChanges(0, files, changed);
        }

        /* If the process segfaults, wait for changes and rebuild */
        if ((retcode == 11) || (retcode == 6)) {
            printf("corto: segmentation fault, fix your code!\n");
            changed = cortotool_waitForChanges(0, files, changed);
            retcode = 0;
            pid = 0;
        }

        retries++;
    }

    if (retcode != -1) {
        corto_error("process stopped with error (%d)", retcode);
    }

    return 0;
}

static void cortotool_stripPath(char *buffer, char *str) {
    char *ptr = str;
    strcpy(buffer, ptr);
    while ((ptr = strchr(ptr + 1, '/'))) {
        strcpy(buffer, ptr + 1); /* A bit of redundancy for the sake of simplicity */
    }
}

corto_int16 cortotool_run(int argc, char *argv[]) {
    corto_ll monitor, dir;
    CORTO_UNUSED(argc);
    corto_string appName = NULL;
    corto_bool runLocal = TRUE;

    corto_argdata *data = corto_argparse(
      argv,
      (corto_argdata[]){
        {"$0", NULL, NULL}, /* Ignore 'run' */
        {"--monitor", &monitor, NULL},
        {"$1", &dir, NULL},
        {"*", NULL, NULL},
        {NULL}
      }
    );

    if (!data) {
        corto_error("%s", corto_lasterr());
        goto error;
    }

    if (dir) {
        corto_string project = corto_llGet(dir, 0);

        /* Maybe this function fails, which is ok as it doesn't directly mean
         * an error. */
        corto_int16 ret = corto_chdir(project);

        /* If project is not found, lookup in package repositories */
        if (ret) {
            corto_id noPath;
            cortotool_stripPath(noPath, project);

            if (corto_fileTest(
                "$CORTO_TARGET/bin/cortobin/$CORTO_VERSION/%s/%s",
                project, noPath))
            {
                appName = corto_envparse(
                    "$CORTO_TARGET/bin/cortobin/$CORTO_VERSION/%s/%s",
                    project, noPath);
            } else if (corto_fileTest(
                "/usr/local/bin/cortobin/$CORTO_VERSION/%s/%s",
                project, noPath))
            {
                appName = corto_envparse(
                    "/usr/local/bin/cortobin/$CORTO_VERSION/%s/%s",
                    project, noPath);
            } else {
                corto_error("%s", corto_lasterr());
                goto error;
            }

            corto_lasterr(); /* Silence uncatched error */

            corto_trace("run: found installed application '%s'", project);
            runLocal = FALSE;
        } else {
            corto_trace("run: found project directory '%s'", project);
            corto_id projectName;
            cortotool_stripPath(projectName, corto_cwd());
            corto_asprintf(&appName, "./%s", projectName);
        }
    } else {
        corto_id projectName;
        cortotool_stripPath(projectName, corto_cwd());
        corto_asprintf(&appName, "./%s", projectName);
    }

    if (runLocal && (corto_fileTest("rakefile") || corto_fileTest("project.json"))) {
        corto_id noPath;
        cortotool_stripPath(noPath, corto_cwd());
        corto_asprintf(&appName, "./%s", noPath);
        sprintf(appName, "./%s", noPath);

        /* Only build when in a project */
        if (cortotool_build(2, (char*[]){"build", "--silent", NULL})) {
            return -1;
        }
    }

    if (monitor) {
        corto_trace("run: start monitor");
        if (cortotool_monitor(argv)) {
            goto error;
        }
    } else {
        corto_pid pid;
        corto_trace("run: starting process '%s'", argv[1]);
        if (argc > 1) {
            pid = corto_procrun(appName, &argv[1]);
        } else {
            pid = corto_procrun(appName, (char*[]){appName, NULL});
        }
        if (!pid) {
            corto_error("failed to start process '%s'", appName);
            goto error;
        }
        corto_ok("run: monitoring process '%s'", argv[1]);
        corto_int8 result = 0, sig = 0;
        if ((sig = corto_procwait(pid, &result)) || result) {
            if (sig > 0) {
                corto_error("process crashed (%d)", sig);
                goto error;
            } else {
                corto_error("process returned %d", result);
                goto error;
            }
        }
    }

    corto_argclean(data);

    return 0;
error:
    return -1;
}

void cortotool_runHelp(void) {
    printf("Usage: corto run\n");
    printf("       corto run <app>\n");
    printf("\n");
    printf("This command builds, runs and monitors your app. Corto will monitor both source\n");
    printf("and dependencies (packages) of your app. If a change is detected\n");
    printf("in any of these, the app is automatically rebuild and restarted.\n");
    printf("\n");
}
