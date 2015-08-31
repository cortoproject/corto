
#include "corto_run.h"
#include "corto_build.h"
#include <sys/stat.h>
#include <errno.h>

static int retcode;

static void corto_freeModified(cx_ll modified) {
	cx_iter iter = cx_llIter(modified);
	while (cx_iterHasNext(&iter)) cx_dealloc(cx_iterNext(&iter));
	cx_llFree(modified);	
}

static cx_ll corto_getModified(cx_ll files, cx_ll modified) {
	cx_int32 i = 0;

	if (files) {
		if (modified) {
			corto_freeModified(modified);
		}

		modified = cx_llNew();

		cx_iter iter = cx_llIter(files);
		while (cx_iterHasNext(&iter)) {
			struct stat attr;
			time_t *mtime;
			cx_string file = cx_iterNext(&iter);

			char buff[1024];
			sprintf(buff, "src/%s", file);
			if (stat(buff, &attr) < 0) {
				printf("corto: failed to stat '%s' (%s)\n", file, strerror(errno));
			}

			mtime = cx_alloc(sizeof(time_t));
			*mtime = attr.st_mtime;
			cx_llAppend(modified, mtime);

			i++;
		}
	}

	return modified;
}

static cx_int32 corto_checkModified(cx_ll modified, cx_ll measured) {
	cx_iter modifiedIter, measuredIter;
	time_t *date1, *date2;
	cx_int32 i = 0;

	modifiedIter = cx_llIter(modified);
	measuredIter = cx_llIter(measured);

	while (cx_iterHasNext(&modifiedIter)) {
		date1 = cx_iterNext(&modifiedIter);
		date2 = cx_iterNext(&measuredIter);

		if (*date1 != *date2) {
			return i;
		}
		i++;
	}

	return -1;
}

static cx_ll corto_waitForChanges(cx_pid pid, cx_ll files, cx_ll modified) {
	cx_ll measured = NULL;
	cx_int32 changed;
	cx_int32 i = 0;

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
			measured = corto_getModified(files, measured);
		} else {
			continue;
		}
	}while (!measured || (changed = corto_checkModified(modified, measured)) == -1);

	corto_freeModified(modified);

	return measured;
}

cx_int16 corto_run(int argc, char *argv[]) {
	cx_pid pid = 0;
	cx_ll files, modified;
	cx_uint32 retries = 0;

	if (argc > 1) {
		cx_chdir(argv[1]);
	}

	files = cx_opendir("./src");
	if (!files || !cx_fileTest(".corto")) {
		cx_error("corto: this isn't a valid project directory");
		return -1;
	}

	modified = corto_getModified(files, NULL);

	while (!retcode) {
		/* Remove executable if it already existed */
		cx_rm(".corto/app");

		/* Build the project */
		corto_build(0, NULL);

		/* Test whether the app exists, then start it */
		if (cx_fileTest(".corto/app")) {
			if (retries) {
				printf("corto: restarting app (%dx)\n", retries);
			}

			/* Start process */
			pid = cx_procrun(".corto/app", argv);

			/* Wait until either source changes, or executable finishes */
			modified = corto_waitForChanges(pid, files, modified);

			/* Kill existing process if file changed */
			if (!retcode) {
				/* Send interrupt signal to process */
				if (cx_prockill(pid, CX_SIGINT)) {
					/* Wait until process has exited */
					cx_procwait(pid, NULL);
				}
			}
		} else {
			cx_error("corto: go fix your code!\n");

			/* Wait for changed before trying again */
			modified = corto_waitForChanges(0, files, modified);
		}

		/* If the process segfaults, wait for changes and rebuild */
		if ((retcode == 11) || (retcode == 6)) {
			printf("corto: segmentation fault, go fix your code!\n");
			modified = corto_waitForChanges(0, files, corto_getModified(files, NULL));
			retcode = 0;
		}

		retries++;
	}

	if (retcode != -1) {
		cx_error("corto: process stopped with error (%d)", retcode);
	}

	if (modified) {
		corto_freeModified(modified);
	}

	if (files) {
		cx_closedir(files);
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
