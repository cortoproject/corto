
#include "cortotool_install.h"

#define CORTO_PROMPT CORTO_CYAN "corto: " CORTO_NORMAL

static corto_bool cortotool_validProject(void) {
    if (!corto_fileTest("rakefile")) {
        corto_error("corto: need a valid project directory to install (no rakefile found)!");
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

static corto_int16 cortotool_installFromSource(corto_bool verbose) {
    corto_bool buildingCorto = FALSE;
    corto_id version;
    sprintf(version, "%s.%s", CORTO_VERSION_MAJOR, CORTO_VERSION_MINOR);

    /* Write installation script */
    FILE *install = fopen("install.sh", "w");
    if (!install) {
        corto_error("corto: failed to create installation script (check permissions)");
        goto error;
    }

    /* Install build system from source */
    if (corto_fileTest("configure") && corto_fileTest("build")) {
        /* If installing corto itself, install buildsystem */
        fprintf(install, "mkdir -p /usr/local/lib/corto/%s\n", version);
        fprintf(install, "rc=$?; if [ $rc != 0 ]; then exit $rc; fi\n");
        fprintf(install, "cp -r ./build /usr/local/lib/corto/%s\n", version);
        fprintf(install, "rc=$?; if [ $rc != 0 ]; then exit $rc; fi\n");
        buildingCorto = TRUE;
    }

    /* Set the build target to the global environment */
    fprintf(install, "export CORTO_TARGET=/usr/local\n");
    fprintf(install, "export CORTO_HOME=/usr/local\n");
    fprintf(install, "export CORTO_BUILD=/usr/local/lib/corto/%s/build\n", version);
    fprintf(install, "export CORTO_VERSION=%s\n", version);
    fprintf(install, "export PATH=/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin\n");

    /* Build libraries to global environment */
    fprintf(install, "rake clean 2> /dev/null\n");
    fprintf(install, "rake silent=%s verbose=%s coverage=false softlinks=false multithread=false\n",
        verbose ? "false" : "true",
        verbose ? "true" : "false");

    fprintf(install, "rc=$?; if [ $rc != 0 ]; then exit $rc; fi\n");

    if (buildingCorto) {
        /* Rename corto */
        fprintf(install, "mv -f /usr/local/bin/corto /usr/local/bin/corto.%s\n", version);
        fprintf(install, "ln -s /usr/local/bin/corto.%s /usr/local/bin/corto\n", version);
        fprintf(install, "rc=$?; if [ $rc != 0 ]; then exit $rc; fi\n");
    }

    fprintf(install, "rake clean 2> /dev/null\n");
    fprintf(install, "rc=$?; if [ $rc != 0 ]; then exit $rc; fi\n");
    fprintf(install, "sudo ldconfig\n");
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
        corto_error("corto: failed to create installation script (check permissions)");
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
    corto_ll verbose = NULL, dirs = NULL;

    corto_argdata *data = corto_argparse(
      argv,
      (corto_argdata[]){
        {"$0", NULL, NULL}, /* Ignore 'install' */
        {"--verbose", &verbose, NULL},
        {"*", &dirs, NULL},
        {NULL}
      }
    );

    if (dirs && corto_llSize(dirs)) {
        corto_string dir = corto_llGet(dirs, 0);
        if (strchr(dir, '/') || corto_chdir(dir)) {
            installRemote = TRUE;
        } else {
            if (!cortotool_validProject()) {
                installRemote = TRUE;
            } else {
                installLocal = TRUE;
            }
        }
    } else {
        if (cortotool_validProject()) {
            installLocal = TRUE;
        }
    }

    if (installLocal) {
        if (cortotool_installFromSource(verbose ? TRUE : FALSE)) {
            goto error;
        }
    } else if (installRemote){
        if (cortotool_installFromRemote(argv[1])) {
            goto error;
        }
    } else {
        corto_error("corto: nothing to install");
        goto error;
    }

    cortotool_promptPassword();

    corto_pid pid = corto_procrun(
        "sudo",
        (char*[]){"sudo", "sh", "install.sh", NULL});

    corto_char progress[] = {'|', '/', '-', '\\'};
    corto_int32 procresult, i = 0;
    corto_int8 rc = 0;
    if (!installRemote) {
        printf(CORTO_PROMPT "installing...  ");
    } else {
        printf(CORTO_PROMPT "installing %s...  ", argv[1]);
    }
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

    corto_argclean(data);

    return 0;
error:
    return -1;
}

corto_int16 cortotool_uninstallAll(void) {
    printf("This will completely remove corto from your system. Proceed? [Y/n] ");
    char ch = getc(stdin);

    if (ch == 'Y') {
        FILE *uninstall = fopen("uninstall.sh", "w");
        if (!uninstall) {
            corto_error("corto: failed to create uninstall script (check permissions)");
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
    if (files && !corto_llSize(files)) {
        empty = TRUE;
    }
    corto_closedir(files);
    return empty;
}

/* Return -1 when failed to remove file, 1 when uninstaller can't be found */
int cortotool_uninstaller(corto_string env, corto_string dir) {
    corto_bool err = 0;
    corto_uint32 filesTotal = 0, filesMissing = 0;

    corto_string uninstall;
    corto_asprintf(&uninstall, "%s/uninstall.txt", dir);
    if (corto_fileTest(uninstall)) {
        corto_id name;
        /* Read files to remove from uninstaller */
        corto_file f = corto_fileRead(uninstall);

        /* Keep track of directories in which files are uninstalled. If empty
         * after uninstalling, also remove directory */
        corto_ll directories = corto_llNew();
        char *dependency;
        while ((dependency = corto_fileReadLine(f, name, sizeof(name)))) {
            filesTotal ++;
            if (!corto_fileTest(dependency)) {
                corto_error("corto: cannot remove %s: file does not exist");
                filesMissing ++;
                continue;
            }
            if (corto_rm(dependency)) {
                corto_error("corto: cannot remove %s: %s", dependency, corto_lasterr());
                err = -1;
            } else {
                corto_trace("corto: removed '%s'", dependency);
                corto_string dir = corto_strdup(dependency);
                char *sep = strrchr(dir, '/');
                if (sep && (sep != dir)) {
                    *sep = '\0';
                }
                if (!corto_llFind(directories, (corto_compareAction)strcmp, dir)) {
                    corto_llAppend(directories, dir);
                } else {
                    corto_dealloc(dir);
                }
            }
        }

        /* Loop directories, recursively remove empty ones */
        corto_iter it = corto_llIter(directories);
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
            while (corto_iterHasNext(&it)) {
                corto_string dir = corto_iterNext(&it);
                if ((strlen(dir) > minLen) && cortotool_isDirEmpty(dir)) {
                    corto_rm(dir);
                    char *sep = strrchr(dir, '/');
                    if (sep && (sep != dir)) {
                        *sep = '\0';
                    }
                    if (!corto_llFind(directories, (corto_compareAction)strcmp, dir)) {
                        corto_llAppend(directories, dir);
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
                corto_trace("corto: removed '%s'", d);
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
                corto_trace("corto: removed '%s'", d);
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
                corto_trace("corto: removed '%s'", d);
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
                corto_trace("corto: removed '%s'", d);
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
            corto_warning(
                "corto: WARNING: no uninstaller found for package '%s' in '%s'",
                package, env);

            corto_warning(
                "  There are however still directories found in '%s' for '%s'.\n"
                "  This is likely the result of uninstalling '%s' but not all\n"
                "  of its child packages. If you proceed, you will recursively\n"
                "  delete all child packages of '%s'.\n",
                env, package, package, package);

            printf("Proceed (Y/n)? ");
            char ch = getchar();
            getchar(); // Get rid of newline
            if ((ch != 'y') && (ch != 'Y')) {
                goto dontdelete;
            }
        }

        r = cortotool_forceCleanup(env, package, FALSE);
        if (r == 0) {
            /* Nothing to delete */
        } else if (r < 0) {
            corto_error("corto: not all files could be removed:%s", corto_lasterr());
        } else if (r < 4) {
            corto_warning(
                "corto: partial installation removed for '%s' in '%s'",
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
    corto_ll packages, verbose;

    CORTO_UNUSED(argc);

    corto_argdata *data = corto_argparse(
      argv,
      (corto_argdata[]){
        {"$0", NULL, NULL}, /* Ignore 'uninstall' */
        {"--verbose", &verbose, NULL},
        {"*", &packages, NULL},
        {NULL}
      }
    );

    if (corto_llSize(packages)) {
        corto_iter it = corto_llIter(packages);
        while (corto_iterHasNext(&it)) {
            corto_string package = corto_iterNext(&it);
            corto_int32 local = cortotool_uninstallFromEnv("$CORTO_TARGET", package);
            corto_int32 global = cortotool_uninstallFromEnv("/usr/local", package);

            if ((local == 0) && (global == 0)) {
                corto_error("corto: package '%s' not found", package);
                continue;
            } else if ((local >= 0) && (global >= 0)) {
                corto_info(CORTO_PROMPT "package '%s' uninstalled", package);
            } else {
              corto_error("corto: failed to uninstall '%s'", package);
            }
        }
    } else {
        if (cortotool_uninstallAll()) {
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
    corto_bool lib = FALSE, path = FALSE, env = FALSE, silent = FALSE;

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
            } else if (!strcmp(argv[i], "--env")) {
                env = TRUE;
            } else if (!strcmp(argv[i], "--silent")) {
                silent = TRUE;
            }
            if (!strcmp(argv[i], "--verbose")) {
                corto_verbosity(CORTO_TRACE);
            }
        }
    }

    location = corto_locate(argv[1], CORTO_LOCATION_LIB);

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

        if (lib || path || env) {
            if (!silent) printf("%s\n", location);
        } else {
            if (!silent) printf(CORTO_PROMPT "'%s' => '%s'\n", argv[1], location);
        }
    } else {
        if (!silent) {
            printf(CORTO_PROMPT "package '%s' not found", argv[1]);
            if (corto_lasterr()) {
                printf("%s\n", corto_lasterr());
            } else {
                printf("\n");
            }
        }
        goto error;
    }

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
        corto_error("corto: failed to create tar script (check permissions)");
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
        corto_error("corto: failed to create tar script (check permissions)");
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
    printf("   --path       Return only the path (no library name)\n");
    printf("   --env        Return only the environment (local or global package repository)\n");
    printf("   --silent     Do not print anything, just return if the package is installed\n");
    printf("   --verbose    Verbose logging\n");
    printf("\n");
}
