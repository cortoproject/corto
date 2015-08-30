
#include "corto_build.h"

cx_int16 corto_build(int argc, char *argv[]) {
	CX_UNUSED(argc);
	CX_UNUSED(argv);

	system ("rake silent=true");

	return 0;
}

void corto_buildHelp(void) {
    printf("Usage: corto build\n");
    printf("\n");
    printf("With this command you can build your project. Note that for\n");
    printf("applications, you don't need to explicitly build your code\n");
    printf("as this is done automatically with 'corto run'. This command\n");
    printf("installs your project to the local environment ($HOME/.corto).\n");
    printf("\n");
}
