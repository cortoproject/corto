/* Copyright (c) 2010-2017 the corto developers
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include "cortotool_build.h"
#include "cortotool_help.h"
#include "cortotool_install.h"
#include "cortotool_package.h"
#include "cortotool_create.h"
#include "cortotool_publish.h"
#include "cortotool_run.h"
#include "cortotool_shell.h"
#include "cortotool_test.h"

int cortotool_help(int argc, char* argv[]) {

    if (argc <= 1) {
        corto_error("no command provided!");
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
        corto_error("unknown command\n");
        corto_error("Use 'corto --help' to get a list of available commands");
        goto error;
    }

    return 0;
error:
    return -1;
}
