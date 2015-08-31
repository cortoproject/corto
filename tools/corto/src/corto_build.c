
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

    system ("rake clobber default silent=true");

    return 0;
}

void corto_buildHelp(void) {
    printf("Usage: corto build\n");
    printf("       corto build <project>\n");
    printf("\n");
    printf("With this command you can build your project. Note that for\n");
    printf("applications, you don't need to explicitly build your code\n");
    printf("as this is done automatically with 'corto run'. This command\n");
    printf("installs your project to the local environment ($HOME/.corto).\n");
    printf("\n");
}

void corto_rebuildHelp(void) {
    printf("Usage: corto rebuild\n");
    printf("       corto rebuild <project>\n");
    printf("\n");
    printf("This command is the same as 'corto build', except that it performs\n");
    printf("a clean rebuild of the whole project.\n");
    printf("\n");
}

