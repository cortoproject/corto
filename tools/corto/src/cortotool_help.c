#include "cortotool_build.h"
#include "cortotool_help.h"
#include "cortotool_install.h"
#include "cortotool_package.h"
#include "cortotool_create.h"
#include "cortotool_run.h"
#include "cortotool_shell.h"
#include "cortotool_test.h"

int cortotool_help(int argc, char* argv[]) {

    if (argc <= 1) {
        corto_error("corto: no command provided!");
        corto_error("Use 'corto --help' to get a list of available commands");
        goto error;
    }

    if (!strcmp(argv[1], "create")) {
        cortotool_createHelp();
    } else if (!strcmp(argv[1], "run")) {
        cortotool_runHelp();
    } else if (!strcmp(argv[1], "add")) {
        cortotool_addHelp();
    } else if (!strcmp(argv[1], "remove")) {
        cortotool_removeHelp();
    } else if (!strcmp(argv[1], "list")) {
        cortotool_listHelp();
    } else if (!strcmp(argv[1], "install")) {
        cortotool_installHelp();
    } else if (!strcmp(argv[1], "uninstall")) {
        cortotool_uninstallHelp();
    } else if (!strcmp(argv[1], "update")) {
        cortotool_updateHelp();
    } else if (!strcmp(argv[1], "locate")) {
        cortotool_locateHelp();
    } else if (!strcmp(argv[1], "publish")) {
        cortotool_publishHelp();
    } else if (!strcmp(argv[1], "shell")) {
        cortotool_shellHelp();
    } else if (!strcmp(argv[1], "tar")) {
        cortotool_tarHelp();
    } else if (!strcmp(argv[1], "untar")) {
        cortotool_untarHelp();
    } else if (!strcmp(argv[1], "build")) {
        cortotool_buildHelp();
    } else if (!strcmp(argv[1], "rebuild")) {
        cortotool_rebuildHelp();
    } else if (!strcmp(argv[1], "clean")) {
        cortotool_cleanHelp();
    } else if (!strcmp(argv[1], "test")) {
        cortotool_testHelp();
    } else {
        corto_error("corto: unknown command\n");
        corto_error("Use 'corto --help' to get a list of available commands");
        goto error;
    }

    return 0;
error:
    return -1;
}
