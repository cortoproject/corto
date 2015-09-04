
#include "corto_build.h"

cx_int16 corto_build(int argc, char *argv[]) {
    if (argc > 1) {
        cx_chdir(argv[1]);
    }

	system ("rake silent=true");

	return 0;
}

cx_int16 corto_rebuild(int argc, char *argv[]) {
    if (argc > 1) {
        cx_chdir(argv[1]);
    }

    system ("rake clobber default silent=true 2> /dev/null");

    return 0;
}

cx_int16 corto_clean(int argc, char *argv[]) {
    if (argc > 1) {
        cx_chdir(argv[1]);
    }

    system ("rake clobber silent=true 2> /dev/null");

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
