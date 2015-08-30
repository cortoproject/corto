
#include "corto_help.h"
#include "corto_build.h"
#include "corto_install.h"
#include "corto_project.h"
#include "corto_run.h"
#include "corto_shell.h"

int corto_help(int argc, char* argv[]) {
	CX_UNUSED(argc);

	if (argc <= 1) {
		cx_error("corto: no command provided!");
		cx_error("Use 'corto --help' to get a list of available commands");
		goto error;
	}

	if (!strcmp(argv[1], "create")) {
		corto_createHelp();
	} else if (!strcmp(argv[1], "run")) {
		corto_runHelp();
	} else if (!strcmp(argv[1], "install")) {
		corto_installHelp();
	} else if (!strcmp(argv[1], "uninstall")) {
		corto_uninstallHelp();
	} else if (!strcmp(argv[1], "locate")) {
		corto_locateHelp();
	} else if (!strcmp(argv[1], "shell")) {
		corto_shellHelp();
	} else if (!strcmp(argv[1], "tar")) {
		corto_tarHelp();
	} else if (!strcmp(argv[1], "untar")) {
		corto_untarHelp();
	} else if (!strcmp(argv[1], "build")) {
		corto_buildHelp();
	} else {
		cx_error("corto: unknown command\n");
		cx_error("Use 'corto --help' to get a list of available commands");
		goto error;
	}

	return 0;
error:
	return -1;
}
