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

#include "cortotool_build.h"
#include "cortotool_install.h"
#include "corto/argparse/argparse.h"

#define CORTO_PROMPT CORTO_CYAN "corto: " CORTO_NORMAL

static corto_bool cortotool_validProject(void) {
    if (corto_fileTest("project.json")) {
        cortotool_rakefile(1, (char*[]){"rakefile", NULL});
    }

    if (!corto_fileTest("rakefile")) {
        corto_error("need a valid project directory to install (no rakefile found)!");
        goto error;
    }
    return TRUE;
error:
    return FALSE;
}

static void cortotool_promptPassword(void) {
    corto_pid pid = corto_procrun("sudo", (char*[]){"sudo", "true", NULL});
    corto_procwait(pid, NULL);
}

static corto_int16 cortotool_installFromSource(corto_bool verbose, corto_bool release) {
    corto_bool buildingCorto = FALSE;
    corto_id version;
    sprintf(version, "%s.%s", CORTO_VERSION_MAJOR, CORTO_VERSION_MINOR);

    /* Write installation script */
    FILE *install = fopen("install.sh", "w");
    if (!install) {
        corto_error("failed to create installation script (check permissions)");
        goto error;
    }

    /* Install build system from source */
    if (corto_fileTest("configure") && corto_fileTest("build")) {
        /* If installing corto itself, install buildsystem */
        fprintf(install, "mkdir -p /usr/local/lib/corto/%s\n", version);
        fprintf(install, "rc=$?; if [ $rc != 0 ]; then exit $rc; fi\n");
        fprintf(install, "cp -r ./build /usr/local/lib/corto/%s\n", version);
        fprintf(install, "rm -f /usr/local/bin/corto.%s\n", version);
        fprintf(install, "rm -f /usr/local/bin/corto\n");
        fprintf(install, "rm -rf /usr/local/lib/corto/%s/corto\n", version);
        fprintf(install, "rc=$?; if [ $rc != 0 ]; then exit $rc; fi\n");
        buildingCorto = TRUE;
    }

    /* Set the build target to the global environment */
    fprintf(install, "export CORTO_TARGET=/usr/local\n");
    fprintf(install, "export CORTO_HOME=/usr/local\n");
    fprintf(install, "export CORTO_BUILD=/usr/local/lib/corto/%s/build\n", version);
    fprintf(install, "export CORTO_VERSION=%s\n", version);

    /* This will help the buildsystem create a link to a new corto executable
     * in the current TARGET, if corto is rebuilt. While not strictly necessary,
     * the link ensures that the shell-cached location to corto still points
     * to a valid destination. Without this the user would have to start a new
     * shell after installing. */
    fprintf(install, "export CORTO_INSTALLFROM=%s\n", getenv("CORTO_TARGET"));

    /* Use current PATH in case sudo has different env */
    char *PATH = getenv("PATH");
    fprintf(install, "export PATH=%s\n", PATH);

    /* Don't do the same for LD_LIBRARY_PATH. Because installed projects should
     * work for all users, local changes to LD_LIBRARY_PATH should not be
     * required when building binaries for the global environment. */
    fprintf(install, "export LD_LIBARRY_PATH=\n");

    /* Build libraries to global environment */
    fprintf(
        install, 
        "rake default verbose=%s config=%s coverage=false softlinks=false multithread=false redistr=false show_header=false\n",
        verbose ? "true" : "false",
        release ? "release" : "debug");

    fprintf(install, "rc=$?; if [ $rc != 0 ]; then exit $rc; fi\n");

    if (buildingCorto) {
        /* Rename corto */
        fprintf(install, "mv -f /usr/local/bin/corto /usr/local/bin/corto.%s\n", version);
        fprintf(install, "ln -s /usr/local/bin/corto.%s /usr/local/bin/corto\n", version);
        fprintf(install, "rc=$?; if [ $rc != 0 ]; then exit $rc; fi\n");
    }

    fprintf(install, "rc=$?; if [ $rc != 0 ]; then exit $rc; fi\n");
#ifdef CORTO_OS_LINUX
    fprintf(install, "sudo ldconfig\n");
#endif
    fclose(install);

    return 0;
error:
    return -1;
}

static corto_int16 cortotool_installFromRemote(corto_string package) {
    corto_id path, name;

    strcpy(name, package);
    if (*package == ':') {
        strcpy(path, package + 2);
    } else if (*package == '/') {
        strcpy(path, package + 1);
    } else {
        strcpy(path, package);
    }

    corto_pathFromFullname(path);
    corto_nameFromFullname(name);

    /* Write installation script */
    FILE *install = fopen("install.sh", "w");
    if (!install) {
        corto_error("failed to create installation script (check permissions)");
        goto error;
    }
    fprintf(install, "install_fail() {\n");
    fprintf(install, "rm -rf $INSTALL_TMPDIR\n");
    fprintf(install, "exit -1\n");
    fprintf(install, "}\n");
    fprintf(install, "install() {\n");
    fprintf(install, "UNAME=$(uname)\n");
    fprintf(install, "ARCHITECTURE=$(uname -m)\n");
    fprintf(install, "INSTALL_TMPDIR=\"$HOME/.corto/.download\"\n");
    fprintf(install, "TARBALL_URL=https://raw.githubusercontent.com/cortoproject/binaries/master/packages/%s/$UNAME-$ARCHITECTURE/%s.tar.gz\n", path, name);
    fprintf(install, "trap install_fail EXIT\n");
    fprintf(install, "mkdir -p \"$INSTALL_TMPDIR\"\n");
    fprintf(install, "sudo curl -sS \"$TARBALL_URL\" -o $INSTALL_TMPDIR/install.tar.gz\n");
    fprintf(install, "if [ 0 != $? ]; then exit -1; fi;\n");
    fprintf(install, "tar -xzf $INSTALL_TMPDIR/install.tar.gz -C \"$INSTALL_TMPDIR\"\n");
    fprintf(install, "rm -rf $INSTALL_TMPDIR/install.tar.gz\n");
    fprintf(install, "sudo cp -a \"$INSTALL_TMPDIR/.\" /usr/local\n");
    fprintf(install, "rm -rf $INSTALL_TMPDIR\n");
    fprintf(install, "sudo ldconfig\n");
    fprintf(install, "trap - EXIT\n");
    fprintf(install, "}\n");
    fprintf(install, "install\n");

    fclose(install);

    return 0;
error:
    return -1;
}

corto_int16 cortotool_install(int argc, char *argv[]) {
    CORTO_UNUSED(argc);
    CORTO_UNUSED(argv);
    corto_bool installRemote = FALSE;
    corto_bool installLocal = FALSE;
    corto_ll verbose = NULL, debug = NULL, release = NULL, dirs = NULL;
    corto_int32 sig = 0;
    corto_int8 rc = 0;

    corto_argdata *data = corto_argparse(
      argv,
      (corto_argdata[]){
        {"$0", NULL, NULL}, /* Ignore 'install' */
        {"--verbose", &verbose, NULL},
        {"--debug-build", &debug, NULL},
        {"--release", &release, NULL},
        {"*", &dirs, NULL},
        {NULL}
      }
    );

    if (!data) {
        corto_error("install: %s", corto_lasterr());
        goto error;
    }

    corto_iter it;
    if (dirs && corto_ll_size(dirs)) {
        it = corto_ll_iter(dirs);
        corto_assert(corto_iter_hasNext(&it), "non-empty list returns empty iterator");
    } else {
        if (cortotool_validProject()) {
            installLocal = TRUE;
        }
    }

    /* After installing, return back to current working directory */
    char *cwd = corto_cwd();

    do {
        corto_string dir = NULL;
        if (dirs && corto_ll_size(dirs)) {
            dir = corto_iter_next(&it);
            if (corto_chdir(dir)) {
                installRemote = TRUE;
            } else {
                if (!cortotool_validProject()) {
                    installRemote = TRUE;
                } else {
                    installLocal = TRUE;
                }
            }
        }

        if (installLocal && dir) {
            printf (CORTO_PROMPT "install %s\n", dir);
        }

        cortotool_promptPassword();

        /* Generate install.sh file for either local or remote install */
        if (installLocal) {
            /* Generate object files outside of sudo so that permissions of files in
             * projects won't be set to root. */
            printf (CORTO_PROMPT "step 1: compile sources\n\n");
            corto_pid pid;
            if (release) {
                pid = corto_procrun("rake",
                    (char*[]) {
                      "rake",
                      "clobber",
                      "default",
                      verbose ? "verbose=true" : "verbose=false",
                      debug ? "debug=true" : "debug=false",
                      "config=release",
                      "coverage=false",
                      "multithread=false",
                      "redistr=false",
                      "show_header=false",
                      NULL
                });
            } else {
                pid = corto_procrun("rake",
                    (char*[]) {
                      "rake",
                      verbose ? "verbose=true" : "verbose=false",
                      debug ? "debug=true" : "debug=false",
                      "coverage=false",
                      "multithread=false",
                      "redistr=false",
                      "show_header=false",
                      NULL
                });
            }

            if ((sig = corto_procwait(pid, &rc)) || rc) {
                if (sig == -1) {
                    corto_error("failed to install (rake returned %d)", rc);
                    goto error;
                } else {
                    corto_error("failed to install (rake raised signal %d)", sig);
                    goto error;
                }
            }

            if (cortotool_installFromSource(verbose ? TRUE : FALSE, release ? TRUE : FALSE)) {
                goto error;
            }

            printf (CORTO_PROMPT "step 2: generate binaries\n\n");
        } else if (installRemote){
            corto_lasterr();
            corto_info("binary installers are currently under development! To install from source, do:")
            corto_info("   git clone <package repository>, followed by:")
            corto_info("   corto install <cloned directory>");
            corto_info("");
            corto_info("   Please mail sander@corto.io if you'd like to donate capacity to our")
            corto_info("   build infrastructure. Happy coding!");
            return 0;
            /*if (cortotool_installFromRemote(argv[1])) {
                goto error;
            }*/
        } else {
            corto_error("nothing to install");
            goto error;
        }

        corto_pid pid = corto_procrun(
            "sudo",
            (char*[]){"sudo", "sh", "install.sh", NULL});

        corto_char progress[] = {'|', '/', '-', '\\'};
        corto_int32 i = 0;
        if (installRemote) {
            printf(CORTO_PROMPT "installing %s...  ", argv[1]);
        }
        while(!(sig = corto_proccheck(pid, &rc))) {
            i++;
            if (installRemote) {
                printf("\b%c", progress[i % 4]);
                fflush(stdout);
            }
            corto_sleep(0, 200000000);
        }

        if ((sig != -1) || rc) {
            if (sig == -1) {
                printf("\bfailed! (installer returned %d)\n", rc);
            } else {
                printf("\bfailed! (installer raised signal %d)\n", sig);
            }
            goto error;
        } else {
            corto_rm("install.sh");

            if (installLocal) {
                printf(CORTO_PROMPT "done\n");
            } else {
                printf("\bdone!\n");
            }
        }
        if (dirs) {
            corto_chdir(cwd);
        }
    } while (dirs && corto_iter_hasNext(&it));

    corto_argclean(data);

    return 0;
error:
    return -1;
}

corto_int16 cortotool_uninstallAll(bool force) {
    char ch;
    if (!force) {
        printf("This will completely remove corto from your system, including all\n"
               "installed packages and applications. Proceed? [y/N] ");

        ch = getc(stdin);
    } else {
        ch = 'y';
    }

    if (ch == 'y') {
        FILE *uninstall = fopen("uninstall.sh", "w");
        if (!uninstall) {
            corto_error("failed to create uninstall script (check permissions)");
            goto error;
        }

        fprintf(uninstall, "rm -rf /usr/local/lib/corto\n");
        fprintf(uninstall, "rm -rf /usr/local/bin/corto\n");
        fprintf(uninstall, "rm -rf /usr/local/bin/corto.*\n");
        fprintf(uninstall, "rm -rf /usr/local/include/corto\n");
        fprintf(uninstall, "rm -rf /usr/local/etc/corto\n");
        fprintf(uninstall, "rm -rf ~/.corto\n");

        fclose(uninstall);

        cortotool_promptPassword();

        corto_pid pid = corto_procrun("sudo", (char*[]){"sudo", "sh", "uninstall.sh", NULL});
        corto_char progress[] = {'|', '/', '-', '\\'};
        corto_int32 i = 0;
        printf(CORTO_PROMPT "uninstalling...  ");
        while(!corto_proccheck(pid, NULL)) {
            i++;
            printf("\b%c", progress[i % 4]);
            fflush(stdout);
            corto_sleep(0, 200000000);
        }
        corto_rm("uninstall.sh");
        printf("\bdone!\n");
    } else {
        printf("Aborted.\n");
    }

    return 0;
error:
    return -1;
}

corto_bool cortotool_isDirEmpty(corto_string dir) {
    corto_bool empty = FALSE;
    corto_ll files = corto_opendir(dir);
    if (files && !corto_ll_size(files)) {
        empty = TRUE;
    }
    corto_closedir(files);
    return empty;
}

/* Return -1 when failed to remove file, 1 when uninstaller can't be found */
int cortotool_uninstaller(corto_string env, corto_string dir) {
    corto_bool err = 0;
    corto_uint32 filesTotal = 0;

    corto_string uninstall;
    corto_asprintf(&uninstall, "%s/uninstall.txt", dir);
    if (corto_fileTest(uninstall)) {
        corto_id name;
        /* Read files to remove from uninstaller */
        corto_file f = corto_fileRead(uninstall);

        /* Keep track of directories in which files are uninstalled. If empty
         * after uninstalling, also remove directory */
        corto_ll directories = corto_ll_new();
        char *dependency;
        while ((dependency = corto_fileReadLine(f, name, sizeof(name)))) {
            if (!dependency) {
                continue;
            }

            filesTotal ++;
            if (!corto_fileTest(dependency)) {
                corto_error("cannot remove %s: file does not exist");
                continue;
            }
            if (corto_rm(dependency)) {
                corto_error("cannot remove %s: %s", dependency, corto_lasterr());
                err = -1;
            } else {
                corto_trace("removed '%s'", dependency);
                corto_string dir = corto_strdup(dependency);
                char *sep = strrchr(dir, '/');
                if (sep && (sep != dir)) {
                    *sep = '\0';
                }
                if (!corto_ll_find(directories, (corto_compare_cb)strcmp, dir)) {
                    corto_ll_append(directories, dir);
                } else {
                    corto_dealloc(dir);
                }
            }
        }

        /* Loop directories, recursively remove empty ones */
        corto_iter it = corto_ll_iter(directories);
        corto_bool empty;
        corto_string root = corto_envparse(
            "%s/include/corto/%s.%s",
            env,
            CORTO_VERSION_MAJOR,
            CORTO_VERSION_MINOR);
        corto_uint32 minLen = strlen(root);
        corto_dealloc(root);
        do {
            empty = FALSE;
            while (corto_iter_hasNext(&it)) {
                corto_string dir = corto_iter_next(&it);
                if ((strlen(dir) > minLen) && cortotool_isDirEmpty(dir)) {
                    corto_rm(dir);
                    char *sep = strrchr(dir, '/');
                    if (sep && (sep != dir)) {
                        *sep = '\0';
                    }
                    if (!corto_ll_find(directories, (corto_compare_cb)strcmp, dir)) {
                        corto_ll_append(directories, dir);
                    } else {
                        corto_dealloc(dir);
                    }
                    empty = TRUE;
                }
            }
        } while(empty);

        corto_fileClose(f);
    } else {
        err = 1;
    }
    corto_dealloc(uninstall);

    return err;
}

corto_int32 cortotool_forceCleanup(corto_string env, corto_string package, corto_bool dryRun) {
    corto_bool result = 0;
    corto_string includeErr = NULL, etcErr = NULL, binErr = NULL, libErr = NULL;

    corto_string d = corto_envparse(
        "%s/include/corto/%s.%s/%s",
        env,
        CORTO_VERSION_MAJOR,
        CORTO_VERSION_MINOR,
        package);
    if (corto_fileTest(d)) {
        if (!dryRun) {
            if (corto_rm(d)) {
                corto_asprintf(&includeErr, "\n  %s: %s", d, corto_lasterr());
                result--;
            } else {
                corto_trace("removed '%s'", d);
            }
        }
        if (result >= 0) result++;
    }
    corto_dealloc(d);

    d = corto_envparse(
        "%s/etc/corto/%s.%s/%s",
        env,
        CORTO_VERSION_MAJOR,
        CORTO_VERSION_MINOR,
        package);
    if (corto_fileTest(d)) {
        if (!dryRun) {
            if (corto_rm(d)) {
                corto_asprintf(&etcErr, "\n  %s: %s", d, corto_lasterr());
                result --;
            } else {
                corto_trace("removed '%s'", d);
            }
        }
        if (result >= 0) result++;
    }
    corto_dealloc(d);

    d = corto_envparse(
        "%s/bin/corto/%s.%s/%s",
        env,
        CORTO_VERSION_MAJOR,
        CORTO_VERSION_MINOR,
        package);
    if (corto_fileTest(d)) {
        if (!dryRun) {
            if (corto_rm(d)) {
                corto_asprintf(&binErr, "\n  %s: %s", d, corto_lasterr());
                result --;
            } else {
                corto_trace("removed '%s'", d);
            }
        }
        if (result >= 0) result++;
    }
    corto_dealloc(d);

    d = corto_envparse(
        "%s/lib/corto/%s.%s/%s",
        env,
        CORTO_VERSION_MAJOR,
        CORTO_VERSION_MINOR,
        package);
    if (corto_fileTest(d)) {
        if (!dryRun) {
            if (corto_rm(d)) {
                corto_asprintf(&libErr, "\n  %s: %s", d, corto_lasterr());
                result --;
            } else {
                corto_trace("removed '%s'", d);
            }
        }
        if (result >= 0) result++;
    }
    corto_dealloc(d);

    if (result < 0) {
        corto_seterr(
            "%s%s%s%s",
            libErr ? libErr : "",
            binErr ? binErr : "",
            includeErr ? includeErr : "",
            etcErr ? etcErr : "");
        if (libErr) corto_dealloc(libErr);
        if (binErr) corto_dealloc(binErr);
        if (includeErr) corto_dealloc(includeErr);
        if (etcErr) corto_dealloc(etcErr);
    }

    /* Returns 0 if nothing found, 4 if all deleted, 0-2 if partially deleted
     * and an increasing negative number for each error found. */

    return result;
}

corto_int32 cortotool_uninstallFromEnv(corto_string env, corto_string package)
{
    corto_int16 err = 0;
    corto_int32 r = 0;

    corto_string dir = corto_envparse(
        "%s/lib/corto/%s.%s/%s",
        env,
        CORTO_VERSION_MAJOR,
        CORTO_VERSION_MINOR,
        package);

    if ((err = cortotool_uninstaller(env, dir)) == 1) {
        /* If uninstaller isn't found, manually remove directories */
        r = cortotool_forceCleanup(env, package, TRUE);
        if (r != 0) {
            printf(
                "corto: WARNING: no uninstaller found for package '%s' in '%s'\n",
                package, env);

            printf(
                "  There are however still directories found in '%s' for '%s'.\n"
                "  This is likely the result of uninstalling '%s' but not all\n"
                "  of its child packages. If you proceed, you will recursively\n"
                "  delete all child packages of '%s'.\n\n",
                env, package, package, package);

            printf("Proceed (y/N)? ");
            char ch = getchar();
            getchar(); // Get rid of newline
            if (ch != 'y') {
                goto dontdelete;
            }
        }

        r = cortotool_forceCleanup(env, package, FALSE);
        if (r == 0) {
            /* Nothing to delete */
        } else if (r < 0) {
            corto_error("not all files could be removed:%s", corto_lasterr());
        } else if (r < 4) {
            corto_warning(
                "partial installation removed for '%s' in '%s'",
                package, env);
        }
    } else if (err == -1) {
        r = -4; /* If uninstaller failed to remove files, report failure */
    } else {
        r = 4; /* If uninstaller was successfull, report success */
    }

    corto_dealloc(dir);

    return r;
dontdelete:
    return 0;
}

corto_int16 cortotool_uninstall(int argc, char *argv[]) {
    corto_ll packages, verbose, force;

    CORTO_UNUSED(argc);

    corto_argdata *data = corto_argparse(
      argv,
      (corto_argdata[]){
        {"$0", NULL, NULL}, /* Ignore 'uninstall' */
        {"--verbose", &verbose, NULL},
        {"--force", &force, NULL},
        {"*", &packages, NULL},
        {NULL}
      }
    );

    if (packages && corto_ll_size(packages)) {
        corto_iter it = corto_ll_iter(packages);
        while (corto_iter_hasNext(&it)) {
            corto_string package = corto_iter_next(&it);
            corto_int32 local = cortotool_uninstallFromEnv("$CORTO_TARGET", package);
            corto_int32 global = cortotool_uninstallFromEnv("/usr/local", package);

            if ((local == 0) && (global == 0)) {
                corto_error("package '%s' not found", package);
                continue;
            } else if ((local >= 0) && (global >= 0)) {
                corto_info("package '%s' uninstalled", package);
            } else {
              corto_error("failed to uninstall '%s'", package);
            }
        }
    } else {
        if (cortotool_uninstallAll(force != NULL)) {
            goto error;
        }
    }

    corto_argclean(data);

    return 0;
error:
    return -1;
}

corto_int16 cortotool_update(int argc, char *argv[]) {
    corto_string package = "corto";
    if (argc > 1) {
        package = argv[1];
    }

    if (cortotool_installFromRemote(package)) {
        goto error;
    }

    cortotool_promptPassword();

    corto_pid pid = corto_procrun("sudo", (char*[]){"sudo", "sh", "install.sh", NULL});
    corto_char progress[] = {'|', '/', '-', '\\'};
    corto_int32 procresult, i = 0;
    corto_int8 rc = 0;
    printf(CORTO_PROMPT "updating %s...  ", package);
    while(!(procresult = corto_proccheck(pid, &rc))) {
        i++;
        printf("\b%c", progress[i % 4]);
        fflush(stdout);
        corto_sleep(0, 200000000);
    }

    if ((procresult != -1) || rc) {
        printf("\bfailed!\n");
        goto error;
    } else {
        corto_rm("install.sh");
        printf("\bdone!\n");
    }

    return 0;
error:
    return -1;
}

void cortotool_toLibPath(char *location) {
    char *ptr, ch;
    ptr = &location[strlen(location) - 1];
    while ((ch = *ptr) && (ptr >= location)) {
        if (ch == '/') {
            *ptr = '\0';
            break;
        }
        ptr --;
    }
}

corto_int16 cortotool_locate(int argc, char* argv[]) {
    corto_string location;
    corto_bool lib = FALSE, path = FALSE, env = FALSE, silent = FALSE, lib_redistr = FALSE;
    corto_bool error_only = FALSE;

    if (argc <= 1) {
        printf(CORTO_PROMPT "please provide a package name\n");
        goto error;
    }

    if (argc > 2) {
        int i = 0;
        for (i = 2; i < argc; i++) {
            if (!strcmp(argv[i], "--lib")) {
                lib = TRUE;
            } else if (!strcmp(argv[i], "--path")) {
                path = TRUE;
            } else if (!strcmp(argv[i], "--lib-redistr")) {
                lib_redistr = TRUE;
            } else if (!strcmp(argv[i], "--env")) {
                env = TRUE;
            } else if (!strcmp(argv[i], "--silent")) {
                silent = TRUE;
            } else if (!strcmp(argv[i], "--error_only")) {
                error_only = TRUE;
            }
            if (!strcmp(argv[i], "--verbose")) {
                corto_verbosity(CORTO_DEBUG);
            }
        }
    }

    if (!lib_redistr) {
        location = corto_locate(argv[1], NULL, CORTO_LOCATION_LIB);
    } else {
        corto_id package;
        strcpy(package, argv[1][0] == '/' ? argv[1] + 1 : argv[1]);
        char *ptr = package, ch;
        while ((ch = *ptr)) {
            if (ch == '/') {
                *ptr = '_';
            }
            ptr++;
        }
        location = corto_envparse("$CORTO_TARGET/redistr/corto/$CORTO_VERSION/lib/lib%s.so", package);
        if (!corto_fileTest(location)) {
            corto_trace("library '%s' not found", location);
            corto_dealloc(location);
            location = NULL;
        }
    }

    if (location) {
        if (env) {
            char *ptr = location;
            while (*ptr) {
                if (!memcmp(ptr, "/lib", 4)) {
                    *ptr = '\0';
                    break;
                }
                ptr++;
            }
        } else if (path && !lib) {
            cortotool_toLibPath(location);
        }

        if (lib || lib_redistr || path || env) {
            if (!silent && !error_only) printf("%s\n", location);
        } else {
            if (!silent && !error_only) printf("%s%s%s  =>  %s\n", CORTO_CYAN, argv[1], CORTO_NORMAL, location);
        }
    } else {
        if (!silent) {
            if (!error_only) {
                if (lib_redistr) {
                    printf(CORTO_PROMPT "redistributable library for package '%s' not found", argv[1]);
                } else {
                    printf(CORTO_PROMPT "package '%s' not located: ", argv[1]);
                }
            }
            if (corto_lastinfo()) {
                printf("%s\n", corto_lastinfo());
            } else {
                printf("\n");
            }
        }
        goto error;
    }

    corto_dealloc(location);

    return 0;
error:
    return -1;
}

corto_int16 cortotool_tar(int argc, char* argv[]) {
    CORTO_UNUSED(argc);
    CORTO_UNUSED(argv);
    corto_id version;
    sprintf(version, "%s.%s", CORTO_VERSION_MAJOR, CORTO_VERSION_MINOR);
    corto_id name;

    /* Get name of project from current path to use as name for tar */
    strcpy(name, corto_getenv("PWD"));
    corto_nameFromFullname(name);

    if (!cortotool_validProject()) {
        goto error;
    }

    /* Write installation script */
    FILE *tar = fopen("tar.sh", "w");
    if (!tar) {
        corto_error("failed to create tar script (check permissions)");
        goto error;
    }

    /* Set the build target to the global environment */
    fprintf(tar, "export CORTO_TARGET=/usr/local\n");
    fprintf(tar, "export CORTO_HOME=/usr/local\n");
    fprintf(tar, "export CORTO_BUILD=/usr/local/lib/corto/%s/build\n", version);
    fprintf(tar, "export CORTO_VERSION=%s\n", version);
    fprintf(tar, "export PATH=/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin\n");
    fprintf(tar, "export UNAME=$(uname)\n");
    fprintf(tar, "export ARCHITECTURE=$(uname -m)\n");
    fprintf(tar, "rake collect\n");
    fprintf(tar, "DIR=`pwd`/tar/$UNAME-$ARCHITECTURE\n");
    fprintf(tar, "mkdir -p $DIR\n");
    fprintf(tar, "cd ~/.corto/pack\n");
    fprintf(tar, "tar -zcf $DIR/%s.tar.gz .\n", name);
    fprintf(tar, "rm -rf ~/.corto/pack\n");
    fclose(tar);

    cortotool_promptPassword();

    corto_pid pid = corto_procrun("sh", (char*[]){"sh", "tar.sh", NULL});
    corto_char progress[] = {'|', '/', '-', '\\'};
    corto_int32 i = 0;
    printf(CORTO_PROMPT "tarring...  ");
    while(!corto_proccheck(pid, NULL)) {
        i++;
        printf("\b%c", progress[i % 4]);
        fflush(stdout);
        corto_sleep(0, 200000000);
    }
    corto_rm("tar.sh");
    printf("\bdone!\n");

    return 0;
error:
    return -1;
}

corto_int16 cortotool_untar(int argc, char* argv[]) {
    CORTO_UNUSED(argc);
    CORTO_UNUSED(argv);
    corto_id version;
    sprintf(version, "%s.%s", CORTO_VERSION_MAJOR, CORTO_VERSION_MINOR);

    /* Write installation script */
    FILE *tar = fopen("untar.sh", "w");
    if (!tar) {
        corto_error("failed to create tar script (check permissions)");
        goto error;
    }

    /* Set the build target to the global environment */
    fprintf(tar, "export CORTO_TARGET=/usr/local\n");
    fprintf(tar, "export CORTO_HOME=/usr/local\n");
    fprintf(tar, "export CORTO_BUILD=/usr/local/lib/corto/%s/build\n", version);
    fprintf(tar, "export CORTO_VERSION=%s\n", version);
    fprintf(tar, "export PATH=/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin\n");
    fprintf(tar, "tar -zxf %s -C /usr/local\n", argv[1]);
    fclose(tar);

    cortotool_promptPassword();

    corto_pid pid = corto_procrun("sudo", (char*[]){"sudo", "sh", "untar.sh", NULL});
    corto_char progress[] = {'|', '/', '-', '\\'};
    corto_int32 i = 0;
    printf(CORTO_PROMPT "untarring...  ");
    while(!corto_proccheck(pid, NULL)) {
        i++;
        printf("\b%c", progress[i % 4]);
        fflush(stdout);
        corto_sleep(0, 200000000);
    }
    corto_rm("untar.sh");
    printf("\bdone!\n");

    return 0;
error:
    return -1;
}

void cortotool_installHelp(void) {
    printf("Usage: corto install [package]\n");
    printf("\n");
    printf("Install a new package to your machine from either source or the remote\n");
    printf("package repository.\n");
    printf("When this command is run from a project directory (or the argument points\n");
    printf("to one) corto will install your project to the global environment\n");
    printf("environment (/usr/local)\n");
    printf("The package parameter can be either a directory or a scoped name package\n");
    printf("name.\n\n");
    printf("Examples:\n");
    printf("corto install ./myPackage\n");
    printf("corto install corto/web\n");
    printf("\n");
    printf("Note: installation requires root priviledges.\n");
    printf("\n");
}

void cortotool_uninstallHelp(void) {
    printf("Usage: corto uninstall\n");
    printf("\n");
    printf("This command removes your project from\n");
    printf("the global environment (/usr/local).\n");
    printf("\n");
    printf("Note that uninstalling requires root priviledges.\n");
    printf("\n");
}

void cortotool_updateHelp(void) {
    printf("Usage: corto update [package]\n");
    printf("\n");
    printf("Updates a package to its latest published version.\n");
    printf("The package parameter must be a scoped name package name\n");
    printf("name. When no package is provided, corto itself will be\n");
    printf("updated to the latest version.\n\n");
    printf("Examples:\n");
    printf("corto update\n");
    printf("corto update corto/web\n");
    printf("\n");
    printf("Note: installation requires root priviledges.\n");
    printf("\n");
}

void cortotool_tarHelp(void) {
    printf("Usage: corto tar\n");
    printf("\n");
    printf("This command packs up your project in a redistributable tar. You\n");
    printf("will need to install your project before calling 'corto tar'.\n");
    printf("To install the tarfile, use 'corto untar'.\n");
    printf("\n");
}

void cortotool_untarHelp(void) {
    printf("Usage: corto untar\n");
    printf("\n");
    printf("This command installs the contents of a tarfile to the global\n");
    printf("environment (/usr/local). Be sure to only use tarfiles that are created\n");
    printf("with 'corto tar'.\n");
    printf("\n");
    printf("Note: installation requires root priviledges.\n");
    printf("\n");
}

void cortotool_locateHelp(void) {
    printf("Usage: corto locate <package>\n");
    printf("\n");
    printf("Returns the location of a package when it is installed. Returns -1 if the\n");
    printf("package is not installed, and 0 if the package is installed.\n");
    printf("\n");
    printf("Options:\n");
    printf("   --lib        Return the path including library name\n");
    printf("   --lib-redistr  Returns the path to a redistributable library\n");
    printf("   --path       Return only the path (no library name)\n");
    printf("   --env        Return only the environment (local or global package repository)\n");
    printf("   --silent     Do not print anything, just return if the package is installed\n");
    printf("   --verbose    Verbose logging\n");
    printf("\n");
}
