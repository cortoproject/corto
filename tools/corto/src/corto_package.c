
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
	int packageElem = 1;
	cx_object package;
	cx_id id;

	if (argc > 2) {
		cx_chdir(argv[1]);
		packageElem = 2;
	}

	package = corto_lookupPackage(argv[packageElem]);
	if (!package) {
		goto error;
	}

	if (!cx_loadRequiresPackage(cx_fullname(package, id))) {
		cx_file f = cx_fileAppend(".corto/packages.txt");
		if (!f) {
			cx_error("corto: failed to open .corto/packages.txt (check permissions)");
			goto error;
		}
		fprintf(cx_fileGet(f), "%s\n", id);
		cx_fileClose(f);
		corto_build(argc - 1, &argv[1]);
		printf("corto: package '%s' added to project\n", id);
	} else {
		printf("corto: package '%s' is already added to the project\n", id);
	}

	cx_release(package);

	return 0;
error:
	if (package) {
		cx_release(package);
	}
	return -1;
}

cx_int16 corto_remove(int argc, char* argv[]) {
	int packageElem = 1;
	cx_ll packages;
	cx_object package;
	cx_id id;
	cx_iter iter;
	cx_bool found = FALSE;
	cx_file file;

	if (argc > 2) {
		cx_chdir(argv[1]);
		packageElem = 2;
	}

	package = corto_lookupPackage(argv[packageElem]);
	if (!package) {
		goto error;
	}

	cx_fullname(package, id);
	packages = cx_loadGetPackages();

	file = cx_fileOpen(".corto/packages.txt");
	iter = cx_llIter(packages);
	while (cx_iterHasNext(&iter)) {
		cx_string str = cx_iterNext(&iter);
		if (strcmp(str, id)) {
			fprintf(cx_fileGet(file), "%s\n", str);
		} else {
			found = TRUE;
		}
	}

	cx_fileClose(file);
	cx_loadFreePackages(packages);

	if (!found) {
		cx_error("corto: '%s' ('%s') not found in package file", argv[packageElem], id);
		goto error;
	} else {
		corto_build(argc - 1, &argv[1]);
		printf("corto: package '%s' removed from project\n", id);
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
