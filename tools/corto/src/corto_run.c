
#include "corto_run.h"
#include "corto_build.h"
#include "corto_install.h"
#include <sys/stat.h>
#include <errno.h>

static int retcode;

typedef struct corto_fileMonitor {
	char *file;
	char *lib;
	time_t mtime;
} corto_fileMonitor;

corto_fileMonitor* corto_monitorNew(char *file, char *lib) {
	corto_fileMonitor *mon = cx_alloc(sizeof(corto_fileMonitor));
	mon->file = cx_strdup(file);
	mon->lib = lib ? cx_strdup(lib) : NULL;
	mon->mtime = 0;
	return mon;
}

static void corto_addChangedLibrary(cx_ll *libs, cx_string lib) {
	if (*libs) {
		cx_iter iter = cx_llIter(*libs);
		while (cx_iterHasNext(&iter)) {
			cx_string l = cx_iterNext(&iter);
			if (!strcmp(l, lib)) {
				return;
			}
		}
	}

	if (!*libs) {
		*libs = cx_llNew();
	}
	cx_llAppend(*libs, lib);
}

static cx_ll corto_getModified(cx_ll files, cx_ll changed) {
	cx_int32 i = 0;
	cx_ll libs = NULL;

	if (changed) {
		cx_llFree(changed);
		changed = NULL;
	}

	if (files) {
		cx_iter iter = cx_llIter(files);
		while (cx_iterHasNext(&iter)) {
			struct stat attr;
			corto_fileMonitor *mon = cx_iterNext(&iter);

			if (stat(mon->file, &attr) < 0) {
				printf("corto: failed to stat '%s' (%s)\n", mon->file, strerror(errno));
			}

			if (mon->mtime) {
				if (mon->mtime != attr.st_mtime) {
					corto_addChangedLibrary(&libs, mon->lib);
				}
			}
			mon->mtime = attr.st_mtime;

			i++;
		}
	}

	return libs;
}

static cx_ll corto_waitForChanges(cx_pid pid, cx_ll files, cx_ll changed) {
	cx_int32 i = 0;

	if (changed) {
		cx_llFree(changed);
		changed = NULL;
	}

	do {
		cx_sleep(0, 50000000);

		/* Check if process is still running */
		if (pid) {
			if ((retcode = cx_proccheck(pid, NULL))) {
				break;
			}
		}

		i++;

		/* Only check files every second */
		if (!(i % 20)) {
			changed = corto_getModified(files, changed);
		} else {
			continue;
		}
	}while (!changed || (pid && retcode));

	return changed;
}

static int corto_addDirToMonitor(cx_string dir, cx_ll monitorList) {
	cx_id cortoDir, srcDir, testDir;
	sprintf(cortoDir, "%s/.corto", dir);
	sprintf(srcDir, "%s/src", dir);
	sprintf(testDir, "%s/test/src", dir);

	cx_ll files = cx_opendir(srcDir);
	if (!files || !cx_fileTest(cortoDir)) {
		cx_error("corto: '%s' isn't a valid project directory", dir);
		goto error;
	}

	cx_iter iter = cx_llIter(files);
	while (cx_iterHasNext(&iter)) {
		cx_id srcFile;
		cx_string file = cx_iterNext(&iter);
		sprintf(srcFile, "%s/src/%s", dir, file);
		corto_fileMonitor *mon = corto_monitorNew(srcFile, dir);
		cx_llAppend(monitorList, mon);
	}

	cx_ll testFiles = cx_opendir(testDir);
	if (testFiles) {
		cx_iter iter = cx_llIter(testFiles);
		while (cx_iterHasNext(&iter)) {
			cx_id srcFile;
			cx_string file = cx_iterNext(&iter);
			sprintf(srcFile, "%s/test/src/%s", dir, file);
			corto_fileMonitor *mon = corto_monitorNew(srcFile, dir);
			cx_llAppend(monitorList, mon);
		}		
	}

	cx_closedir(files);

	return 0;
error:
	return -1;
}

static int corto_buildDependency(cx_string path, cx_bool test) {
	cx_int8 procResult = 0;
	cx_id testPath;

	/* Build */
	cx_pid pid = cx_procrun("corto", (char*[]){"corto", "build", path, NULL});
	if (cx_procwait(pid, &procResult) || procResult) {
		printf("corto: failed to build '%s'\n", path);
		goto error;
	}

	/* Build test */
	sprintf(testPath, "%s/test", path);
	if (cx_fileTest(testPath)) {
		cx_pid pid = cx_procrun("corto", (char*[]){"corto", "build", testPath, NULL});
		if (cx_procwait(pid, &procResult) || procResult) {
			printf("corto: failed to build '%s'\n", testPath);
			goto error;
		}
	}

	/* Test */
	if (test) {
		pid = cx_procrun("corto", (char*[]){"corto", "test", path, NULL});
		if (cx_procwait(pid, &procResult) || procResult) {
			printf("corto: test failed for '%s'\n", path);
			goto error;
		}
	}

	return 0;
error:
	return -1;
}

static cx_ll corto_gatherFiles(void) {
	cx_ll result = cx_llNew();
	cx_ll packages;

	if (corto_addDirToMonitor(".", result)) {
		goto error;
	}

	/* Walk packages */
	packages = cx_loadGetPackages();
	cx_iter iter = cx_llIter(packages);
	while (cx_iterHasNext(&iter)) {
		cx_id sourceLink;
		cx_string package = cx_iterNext(&iter);
		cx_string file = cx_locate(package);
		corto_fileMonitor *mon = corto_monitorNew(file, NULL);
		if (file) {
			cx_llAppend(result, mon);
		} else {
			printf("couldn't find file '%s'\n", file);
		}

		/* Check if there are source files available to monitor */
		corto_toLibPath(file);
		sprintf(sourceLink, "%s/source.txt", file);
		if (cx_fileTest(sourceLink)) {
			cx_string path = cx_fileLoad(sourceLink);

			/* Strip newline */
			path[strlen(path)-1] = '\0';
			corto_buildDependency(path, FALSE);

			if (corto_addDirToMonitor(path, result)) {
				goto error;
			}
		}
	}

	return result;
error:
	cx_llFree(result);
	return NULL;	
}

cx_int16 corto_debug(int argc, char *argv[]) {
	CX_UNUSED(argc);
	CX_UNUSED(argv);

	if (argc > 1) {
		cx_chdir(argv[1]);
	}

	printf("argv[1] = %s\n", argv[1]);

	cx_pid pid = cx_procrun("lldb", (char*[]){".corto/app", NULL});
	if (pid) {
		cx_procwait(pid, NULL);
	}

	return 0;
}

cx_int16 corto_run(int argc, char *argv[]) {
	cx_pid pid = 0;
	cx_ll files;
	cx_ll changed = NULL;
	cx_uint32 retries = 0;
	cx_int32 rebuild = 0;
	cx_int32 depErrors = 0;

	if (argc > 1) {
		cx_chdir(argv[1]);
	}

	corto_build(0, NULL);

	files = corto_gatherFiles();
	if (!files) {
		return -1;
	}

	corto_getModified(files, NULL);

	while (!retcode) {

		/* Build the project */
		if (!changed) {
			cx_rm(".corto/app");
			corto_build(0, NULL);
			rebuild++;
		} else {
			depErrors = 0;
			cx_iter iter = cx_llIter(changed);
			while (cx_iterHasNext(&iter)) {
				cx_string lib = cx_iterNext(&iter);
				if (lib && strcmp(lib, ".")) {
					printf("corto: '%s' changed, rebuilding\n", lib);
					if (!corto_buildDependency(lib, TRUE)) {
						rebuild++;
					} else {
						depErrors++;
					}
				} else {
					rebuild++;
				}
			}

			/* Don't trigger on the changes in dependency binary file due to the builds */
			changed = corto_getModified(files, changed);

			/* Rebuild the app */
			if (rebuild) {
				cx_rm(".corto/app");
				corto_build(0, NULL);
			} else if (depErrors) {
				printf("corto: won't restart because dependency failed to rebuild\n");
			}
		}

		if (pid && rebuild) {
			/* Send interrupt signal to process */
			if (cx_prockill(pid, CX_SIGINT)) {
				/* Wait until process has exited */
				cx_procwait(pid, NULL);
			}
			rebuild = 0;
			pid = 0;
		}

		/* Test whether the app exists, then start it */
		if (cx_fileTest(".corto/app")) {
			if (retries && !pid) {
				printf("corto: restarting app (%dx)\n", retries);
			}

			/* Start process */
			if (!pid) {
				pid = cx_procrun(".corto/app", &argv[1]);
			}

			/* Wait until either source changes, or executable finishes */
			changed = corto_waitForChanges(pid, files, changed);

			/* Set pid to 0 if process has exited */
			if (retcode) {
				pid = 0;
			}
		} else {
			cx_error("corto: go fix your code!\n");

			/* Wait for changed before trying again */
			changed = corto_waitForChanges(0, files, changed);
		}

		/* If the process segfaults, wait for changes and rebuild */
		if ((retcode == 11) || (retcode == 6)) {
			printf("corto: segmentation fault, go fix your code!\n");
			changed = corto_waitForChanges(0, files, changed);
			retcode = 0;
			pid = 0;
		}

		retries++;
	}

	if (retcode != -1) {
		cx_error("corto: process stopped with error (%d)", retcode);
	}

	return 0;
}

void corto_runHelp(void) {
    printf("Usage: corto run\n");
    printf("       corto run <app>\n");
    printf("\n");
    printf("This command builds, runs and monitors your app. Corto will monitor both source\n");
    printf("and dependencies (packages) of your app. If a change is detected\n");
    printf("in any of these, the app is automatically rebuild and restarted.\n");
    printf("\n");
}
