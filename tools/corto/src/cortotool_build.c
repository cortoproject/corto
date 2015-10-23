
#include "cortotool_build.h"

corto_int16 cortotool_build(int argc, char *argv[]) {
    corto_int8 ret = 0;
    if (argc > 1) {
        corto_chdir(argv[1]);
    }

	corto_pid pid = corto_procrun("rake", (char*[]){"rake", "silent=true", NULL});
    if (corto_procwait(pid, &ret) || ret) {
        goto error;
    }

	return 0;
error:
    corto_error("build failed");
    return -1;
}

corto_int16 cortotool_rebuild(int argc, char *argv[]) {
    corto_int8 ret = 0;
    if (argc > 1) {
        corto_chdir(argv[1]);
    }

    system("rake clobber 2> /dev/null");
    corto_pid pid = corto_procrun("rake", (char*[]){"rake", "default", "silent=true", NULL});
    if (corto_procwait(pid, &ret) || ret) {
        goto error;
    }

    return 0;
error:
    corto_error("build failed");
    return -1;
}

corto_int16 cortotool_clean(int argc, char *argv[]) {
    if (argc > 1) {
        corto_chdir(argv[1]);
    }

    system("rake clobber >2 /dev/null");

    return 0;
}

void cortotool_buildHelp(void) {
    printf("Usage: corto build\n");
    printf("       corto build <project>\n");
    printf("\n");
    printf("Build your Corto project.\n");
    printf("\n");
}

void cortotool_rebuildHelp(void) {
    printf("Usage: corto rebuild\n");
    printf("       corto rebuild <project>\n");
    printf("\n");
    printf("Rebuild your Corto project (clean before build).\n");
    printf("\n");
}

void cortotool_cleanHelp(void) {
    printf("Usage: corto clean\n");
    printf("       corto clean <project>\n");
    printf("\n");
    printf("Cleans your Corto project.\n");
    printf("\n");
}
