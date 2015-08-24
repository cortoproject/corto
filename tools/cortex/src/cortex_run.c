
#include "cortex_run.h"
#include "cortex_build.h"
#include <sys/stat.h>
#include <errno.h>

static int retcode;

static void cortex_freeModified(cx_ll modified) {
	cx_iter iter = cx_llIter(modified);
	while (cx_iterHasNext(&iter)) cx_dealloc(cx_iterNext(&iter));
	cx_llFree(modified);	
}

static cx_ll cortex_getModified(cx_ll files, cx_ll modified) {
	cx_int32 i = 0;

	if (files) {
		if (modified) {
			cortex_freeModified(modified);
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
				printf("cortex: failed to stat '%s' (%s)\n", file, strerror(errno));
			}

			mtime = cx_alloc(sizeof(time_t));
			*mtime = attr.st_mtime;
			cx_llAppend(modified, mtime);

			i++;
		}
	}

	return modified;
}

static cx_int32 cortex_checkModified(cx_ll modified, cx_ll measured) {
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

static cx_ll cortex_waitForChanges(cx_pid pid, cx_ll files, cx_ll modified) {
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
			measured = cortex_getModified(files, measured);
		} else {
			continue;
		}
	}while (!measured || (changed = cortex_checkModified(modified, measured)) == -1);

	cortex_freeModified(modified);

	return measured;
}

cx_int16 cortex_run(int argc, char *argv[]) {
	cx_pid pid = 0;
	cx_ll files, modified;
	cx_uint32 retries = 0;

	CX_UNUSED(argc);

	files = cx_opendir("./src");
	if (!files || !cx_fileTest(".cortex")) {
		cx_error("cortex: this isn't a valid project directory");
		return -1;
	}

	modified = cortex_getModified(files, NULL);

	while (!retcode) {
		/* Remove executable if it already existed */
		cx_rm(".cortex/app");

		/* Build the project */
		cortex_build(0, NULL);

		/* Test whether the app exists, then start it */
		if (cx_fileTest(".cortex/app")) {
			if (retries) {
				printf("cortex: restarting app (%dx)\n", retries);
			}

			/* Start process */
			pid = cx_procrun(".cortex/app", argv);

			/* Wait until either source changes, or executable finishes */
			modified = cortex_waitForChanges(pid, files, modified);

			/* Kill existing process if file changed */
			if (!retcode) {
				/* Send interrupt signal to process */
				if (cx_prockill(pid, CX_SIGINT)) {
					/* Wait until process has exited */
					cx_procwait(pid, NULL);
				}
			}
		} else {
			cx_error("cortex: go fix your code!\n");

			/* Wait for changed before trying again */
			modified = cortex_waitForChanges(0, files, modified);
		}

		/* If the process segfaults, wait for changes and rebuild */
		if ((retcode == 11) || (retcode == 6)) {
			printf("cortex: segmentation fault, go fix your code!\n");
			modified = cortex_waitForChanges(0, files, cortex_getModified(files, NULL));
			retcode = 0;
		}

		retries++;
	}

	if (retcode != -1) {
		cx_error("cortex: process stopped with error (%d)", retcode);
	}

	if (modified) {
		cortex_freeModified(modified);
	}

	if (files) {
		cx_closedir(files);
	}

	return 0;
}
