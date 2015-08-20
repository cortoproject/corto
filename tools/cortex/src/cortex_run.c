
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
		if ((retcode = cx_proccheck(pid))) {
			break;
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

	CX_UNUSED(argc);

	files = cx_opendir("./src");
	if (!files) {
		cx_error("cortex: failed to list files in ./src, can't monitor changes :-(");
	}

	modified = cortex_getModified(files, NULL);

	while (!retcode) {
		/* Build the project */
		cortex_build(0, NULL);

		/* Test whether the app exists, then start it */
		if (cx_fileTest(".cortex/app")) {
			/* Start process */
			pid = cx_procrun(".cortex/app", argv);

			/* Wait until either source changes, or executable finishes */
			modified = cortex_waitForChanges(pid, files, modified);

			/* Kill existing process if file changed */
			if (!retcode) {
				/* Send interrupt signal to process */
				if (cx_prockill(pid, CX_SIGINT)) {
					/* Wait until process has exited */
					cx_procwait(pid);
				}
			}
		} else {
			cx_error("cortex: build error\n");
		}
	}

	if (retcode != -1) {
		cx_error("process returned with error (%d)", retcode);
	}

	if (modified) {
		cortex_freeModified(modified);
	}

	if (files) {
		cx_closedir(files);
	}

	return 0;
}
