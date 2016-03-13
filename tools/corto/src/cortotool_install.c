
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
    fprintf(install, "rake silent=%s verbose=%s\n",
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

    if (argc > 1) {
        if (strchr(argv[1], ':') || corto_chdir(argv[1])) {
            installRemote = TRUE;
        } else {
            if (!cortotool_validProject()) {
                installRemote = TRUE;
            }
        }
    }

    if (!installRemote) {
        if (cortotool_installFromSource(FALSE)) {
            goto error;
        }
    } else {
        if (cortotool_installFromRemote(argv[1])) {
            goto error;
        }
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

corto_int16 cortotool_uninstaller(corto_string dir) {
    corto_bool err = FALSE;

    corto_string uninstall;
    corto_asprintf(&uninstall, "%s/uninstall.txt", dir);
    if (corto_fileTest(uninstall)) {
        corto_id name;
        /* Remove files of package */
        corto_file f = corto_fileRead(uninstall);
        char *dependency;
        while ((dependency = corto_fileReadLine(f, name, sizeof(name)))) {
            if (corto_rm(dependency)) {
                corto_error("failed to remove %s: %s", dependency, corto_lasterr());
                err = TRUE;
            }
        }
        corto_fileClose(f);
    }
    corto_dealloc(uninstall);

    return err;
}

corto_int16 cortotool_uninstall(int argc, char *argv[]) {
    corto_bool err = FALSE, found = FALSE;

    if (argc > 1) {
        corto_string dir;

        /* Look in local environment */
        dir = corto_envparse(
            "$CORTO_TARGET/lib/corto/%s.%s/%s",
            CORTO_VERSION_MAJOR,
            CORTO_VERSION_MINOR,
            argv[1]);
        if (corto_fileTest(dir)) {
            err = cortotool_uninstaller(dir);
            corto_rm(dir);
            found = TRUE;
        }
        corto_dealloc(dir);

        /* Look in global environment */
        dir = corto_envparse(
            "/usr/local/lib/corto/%s.%s/%s",
            CORTO_VERSION_MAJOR,
            CORTO_VERSION_MINOR,
            argv[1]);
        if (corto_fileTest(dir)) {
            err = cortotool_uninstaller(dir);
            corto_rm(dir);
            found = TRUE;
        }
        corto_dealloc(dir);

        if (!err) {
            corto_print(CORTO_PROMPT "package '%s' uninstalled", argv[1]);
        } else if (!found) {
            corto_error("corto: package '%s' not found", argv[1]);
            goto error;
        }
    } else {
        if (cortotool_uninstallAll()) {
            goto error;
        }
    }

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
        if (!silent) printf(CORTO_PROMPT "package '%s' not found\n", argv[1]);
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
