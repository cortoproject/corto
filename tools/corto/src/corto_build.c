
#include "corto_build.h"

cx_int16 corto_build(int argc, char *argv[]) {
    cx_int8 ret = 0;
    if (argc > 1) {
        cx_chdir(argv[1]);
    }

	cx_pid pid = cx_procrun("rake", (char*[]){"rake", "silent=true", NULL});
    if (cx_procwait(pid, &ret) || ret) {
        goto error;
    }

	return 0;
error:
    cx_error("build failed");
    return -1;
}

cx_int16 corto_rebuild(int argc, char *argv[]) {
    cx_int8 ret = 0;
    if (argc > 1) {
        cx_chdir(argv[1]);
    }

    system("rake clobber 2> /dev/null");
    cx_pid pid = cx_procrun("rake", (char*[]){"rake", "default", "silent=true", NULL});
    if (cx_procwait(pid, &ret) || ret) {
        goto error;
    }

    return 0;
error:
    cx_error("build failed");
    return -1;
}

cx_int16 corto_clean(int argc, char *argv[]) {
    if (argc > 1) {
        cx_chdir(argv[1]);
    }

    system("rake clobber >2 /dev/null");

    return 0;
}

void corto_buildHelp(void) {
    printf("Usage: corto build\n");
    printf("       corto build <project>\n");
    printf("\n");
    printf("Build your Corto project.\n");
    printf("\n");
}

void corto_rebuildHelp(void) {
    printf("Usage: corto rebuild\n");
    printf("       corto rebuild <project>\n");
    printf("\n");
    printf("Rebuild your Corto project (clean before build).\n");
    printf("\n");
}

void corto_cleanHelp(void) {
    printf("Usage: corto clean\n");
    printf("       corto clean <project>\n");
    printf("\n");
    printf("Cleans your Corto project.\n");
    printf("\n");
}
