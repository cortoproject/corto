
#include "cortotool_package.h"
#include "cortotool_build.h"
#include "corto_files.h"

static corto_object cortotool_lookupPackage(corto_string str) {
    corto_object package = corto_resolve(NULL, str);
    if (!package) {
        corto_error("corto: package '%s' not be found", str);
        goto error;
    }

    if (!corto_instanceof(corto_package_o, package)) {
        corto_error("corto: object '%s' is not a package", str);
        goto error;
    }

    return package;
error:
    return NULL;
}

corto_int16 cortotool_add(int argc, char* argv[]) {
    int nameElem = 1;
    corto_id id;
    corto_bool isComponent = FALSE, isSilent = FALSE, noBuild = FALSE;

    if ((argc > 2) && (*argv[2] != '-')) {
        corto_chdir(argv[1]);
        nameElem = 2;
    }

    if (argc > (nameElem + 1)) {
        corto_int32 i = 0;
        for (i = nameElem + 1; i < argc; i++) {
            if (!strcmp(argv[i], "--component")) {
                isComponent = TRUE;
            } else if (!strcmp(argv[i], "--silent")) {
                isSilent = TRUE;
            } else if (!strcmp(argv[i], "--nobuild")) {
                noBuild = TRUE;
            }
        }
    }

    if (isComponent) {
        /* Test whether component exists */
        corto_string component = corto_locateComponent(argv[nameElem]);
        if (!component) {
            corto_error("corto: component '%s' not found", argv[nameElem]);
            goto error;
        }

        if (!corto_loadRequiresComponent(argv[nameElem])) {
            corto_mkdir(".corto");
            corto_file f = corto_fileAppend(".corto/components.txt");
            if (!f) {
                corto_error("corto: failed to open .corto/components.txt (check permissions)");
                corto_dealloc(component);
                goto error;
            }
            fprintf(corto_fileGet(f), "%s\n", argv[nameElem]);
            corto_fileClose(f);

            if (!noBuild) {
                    cortotool_build(1, (char*[]){"build"});
            }

            if (!isSilent) {
                printf("corto: component '%s' added to project\n", argv[nameElem]);
            }
        } else {
            if (!isSilent) {
                printf("corto: component '%s' is already added to the project\n", argv[nameElem]);
            }
        }

        corto_dealloc(component);

    } else {
        /* Test whether package exists */
        corto_object package = cortotool_lookupPackage(argv[nameElem]);
        if (!package) {
            goto error;
        }

        /* Use fully scoped name from here */
        if (!corto_loadRequiresPackage(corto_fullname(package, id))) {
            corto_mkdir(".corto");
            corto_file f = corto_fileAppend(".corto/packages.txt");
            if (!f) {
                corto_error("corto: failed to open .corto/packages.txt (check permissions)");
                corto_release(package);
                goto error;
            }
            fprintf(corto_fileGet(f), "%s\n", id);
            corto_fileClose(f);

            if (!noBuild) {
                cortotool_build(1, (char*[]){"build"});
            }

            if (!isSilent) {
                printf("corto: package '%s' added to project\n", id);
            }
        } else {
            if (!isSilent) {
                printf("corto: package '%s' is already added to the project\n", id);
            }
        }

        corto_release(package);
    }

    return 0;
error:
    return -1;
}

static corto_bool cortotool_removeEntry(corto_file file, corto_ll list, corto_string entry) {
    corto_bool found = FALSE;
    corto_iter iter = corto_llIter(list);

    while (corto_iterHasNext(&iter)) {
        corto_string str = corto_iterNext(&iter);
        if (strcmp(str, entry)) {
            fprintf(corto_fileGet(file), "%s\n", str);
        } else {
            found = TRUE;
        }
    }

    return found;
}

corto_int16 cortotool_remove(int argc, char* argv[]) {
    int nameElem = 1;
    corto_bool found = FALSE;
    corto_file file;
    corto_bool isComponent = FALSE;

    if ((argc > 2) && (*argv[2] != '-')) {
        corto_chdir(argv[1]);
        nameElem = 2;
    }

    if (argc > (nameElem + 1)) {
        if (argv[nameElem + 1]) {
            if (!strcmp(argv[nameElem + 1], "--component")) {
                isComponent = TRUE;
            }
        }
    }

    if (isComponent) {
        corto_ll components = corto_loadGetComponents();
        file = corto_fileOpen(".corto/components.txt");
        found = cortotool_removeEntry(file, components, argv[nameElem]);
        corto_fileClose(file);
        corto_loadFreePackages(components);

        if (!found) {
            corto_error("corto: '%s' not found in components file", argv[nameElem]);
            goto error;
        } else {
            cortotool_build(argc - 1, &argv[1]);
            printf("corto: component '%s' removed from project\n", argv[nameElem]);
        }
    } else {
        corto_id id;
        corto_object package = cortotool_lookupPackage(argv[nameElem]);
        if (!package) {
            goto error;
        }

        corto_fullname(package, id);
        corto_ll packages = corto_loadGetPackages();

        file = corto_fileOpen(".corto/packages.txt");
        found = cortotool_removeEntry(file, packages, id);
        corto_fileClose(file);
        corto_loadFreePackages(packages);

        if (!found) {
            corto_error("corto: '%s' ('%s') not found in package file", argv[nameElem], id);
            goto error;
        } else {
            cortotool_build(argc - 1, &argv[1]);
            printf("corto: package '%s' removed from project\n", id);
        }
    }

    return 0;
error:
    return -1;
}

corto_int16 cortotool_list(int argc, char* argv[]) {
    if (argc > 1) {
        corto_chdir(argv[1]);
    }

    corto_ll packages = corto_loadGetPackages();

    if (packages && corto_llSize(packages)) {
        corto_iter iter = corto_llIter(packages);
        printf("packages:\n");
        while (corto_iterHasNext(&iter)) {
            corto_string str = corto_iterNext(&iter);
            printf("  %s  =>  %s\n", str, corto_locate(str));
        }
    } else {
        printf("corto: no packages to list\n");
    }

    if (packages) {
        corto_loadFreePackages(packages);
    }

    return 0;
}

void cortotool_addHelp(void) {
    printf("Usage: corto add <package>\n");
    printf("       corto add <project> <package>\n");
    printf("\n");
    printf("Add packages to your Corto project.\n");
    printf("\n");
}

void cortotool_removeHelp(void) {
    printf("Usage: corto remove <package>\n");
    printf("       corto remove <project> <package>\n");
    printf("\n");
    printf("Remove a previously added package from your Corto project.\n");
    printf("\n");
}

void cortotool_listHelp(void) {
    printf("Usage: corto list\n");
    printf("       corto list <project>\n");
    printf("\n");
    printf("List the packages added to your Corto project.\n");
    printf("\n");
}
