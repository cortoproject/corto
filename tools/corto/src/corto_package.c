
#include "corto_package.h"
#include "corto_build.h"

static cx_object corto_lookupPackage(cx_string str) {
	cx_object package = cx_resolve(NULL, str);
	if (!package) {
		cx_error("corto: package '%s' not be found", str);
		goto error;
	}

	if (!cx_instanceof(cx_package_o, package)) {
		cx_error("corto: object '%s' is not a package", str);
		goto error;
	}

	return package;	
error:
	return NULL;
}

cx_int16 corto_add(int argc, char* argv[]) {
	int nameElem = 1;
	cx_id id;
	cx_bool isComponent = FALSE, isSilent = FALSE, noBuild = FALSE;

	if ((argc > 2) && (*argv[2] != '-')) {
		cx_chdir(argv[1]);
		nameElem = 2;
	}

	if (argc > (nameElem + 1)) {
		cx_int32 i = 0;
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
		cx_string component = cx_locateComponent(argv[nameElem]);
		if (!component) {
			cx_error("corto: component '%s' not found", argv[nameElem]);
			goto error;
		}

		if (!cx_loadRequiresComponent(argv[nameElem])) {
			cx_file f = cx_fileAppend(".corto/components.txt");
			if (!f) {
				cx_error("corto: failed to open .corto/components.txt (check permissions)");
				cx_dealloc(component);
				goto error;
			}
			fprintf(cx_fileGet(f), "%s\n", argv[nameElem]);
			cx_fileClose(f);

			if (!noBuild) {
				corto_build(argc - 1, &argv[1]);
			}

			if (!isSilent) {
				printf("corto: component '%s' added to project\n", argv[nameElem]);
			}
		} else {
			if (!isSilent) {
				printf("corto: component '%s' is already added to the project\n", argv[nameElem]);
			}
		}

		cx_dealloc(component);

	} else {
		/* Test whether package exists */
		cx_object package = corto_lookupPackage(argv[nameElem]);
		if (!package) {
			goto error;
		}

		/* Use fully scoped name from here */
		if (!cx_loadRequiresPackage(cx_fullname(package, id))) {
			cx_file f = cx_fileAppend(".corto/packages.txt");
			if (!f) {
				cx_error("corto: failed to open .corto/packages.txt (check permissions)");
				cx_release(package);
				goto error;
			}
			fprintf(cx_fileGet(f), "%s\n", id);
			cx_fileClose(f);

			if (!noBuild) {
				corto_build(argc - 1, &argv[1]);
			}

			if (!isSilent) {
				printf("corto: package '%s' added to project\n", id);
			}
		} else {
			if (!isSilent) {
				printf("corto: package '%s' is already added to the project\n", id);
			}
		}

		cx_release(package);
	}

	return 0;
error:
	return -1;
}

static cx_bool corto_removeEntry(cx_file file, cx_ll list, cx_string entry) {
	cx_bool found = FALSE;
	cx_iter iter = cx_llIter(list);

	while (cx_iterHasNext(&iter)) {
		cx_string str = cx_iterNext(&iter);
		if (strcmp(str, entry)) {
			fprintf(cx_fileGet(file), "%s\n", str);
		} else {
			found = TRUE;
		}
	}

	return found;
}

cx_int16 corto_remove(int argc, char* argv[]) {
	int nameElem = 1;
	cx_bool found = FALSE;
	cx_file file;
	cx_bool isComponent = FALSE;

	if ((argc > 2) && (*argv[2] != '-')) {
		cx_chdir(argv[1]);
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
		cx_ll components = cx_loadGetComponents();
		file = cx_fileOpen(".corto/components.txt");
		found = corto_removeEntry(file, components, argv[nameElem]);
		cx_fileClose(file);
		cx_loadFreePackages(components);

		if (!found) {
			cx_error("corto: '%s' not found in components file", argv[nameElem]);
			goto error;
		} else {
			corto_build(argc - 1, &argv[1]);
			printf("corto: component '%s' removed from project\n", argv[nameElem]);
		}
	} else {
		cx_id id;
		cx_object package = corto_lookupPackage(argv[nameElem]);
		if (!package) {
			goto error;
		}

		cx_fullname(package, id);
		cx_ll packages = cx_loadGetPackages();

		file = cx_fileOpen(".corto/packages.txt");
		found = corto_removeEntry(file, packages, id);
		cx_fileClose(file);
		cx_loadFreePackages(packages);

		if (!found) {
			cx_error("corto: '%s' ('%s') not found in package file", argv[nameElem], id);
			goto error;
		} else {
			corto_build(argc - 1, &argv[1]);
			printf("corto: package '%s' removed from project\n", id);
		}
	}

	return 0;
error:
	return -1;
}

cx_int16 corto_list(int argc, char* argv[]) {
	if (argc > 1) {
		cx_chdir(argv[1]);
	}

	cx_ll packages = cx_loadGetPackages();

	if (packages && cx_llSize(packages)) {
		cx_iter iter = cx_llIter(packages);
		printf("packages:\n");
		while (cx_iterHasNext(&iter)) {
			cx_string str = cx_iterNext(&iter);
			printf("  %s  =>  %s\n", str, cx_locate(str));
		}
	} else {
		printf("corto: no packages to list\n");
	}

	if (packages) {
		cx_loadFreePackages(packages);
	}

	return 0;
}

void corto_addHelp(void) {
    printf("Usage: corto add <package>\n");
    printf("       corto add <project> <package>\n");
    printf("\n");
    printf("Add packages to your Corto project.\n");
    printf("\n");
}

void corto_removeHelp(void) {
    printf("Usage: corto remove <package>\n");
    printf("       corto remove <project> <package>\n");
    printf("\n");
    printf("Remove a previously added package from your Corto project.\n");
    printf("\n");
}

void corto_listHelp(void) {
    printf("Usage: corto list\n");
    printf("       corto list <project>\n");
    printf("\n");
    printf("List the packages added to your Corto project.\n");
    printf("\n");
}
