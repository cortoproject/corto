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

#include "cortotool_package.h"
#include "cortotool_build.h"
#include "corto/argparse/argparse.h"

#define CORTO_PROMPT CORTO_CYAN "corto: " CORTO_NORMAL

static corto_string cortotool_lookupPackage(corto_string str) {
    corto_string package = NULL;

    corto_object p = corto_resolve(NULL, str);

    if (!p) {
        if (!corto_locate(str, NULL, CORTO_LOCATION_LIB)) {
            corto_seterr("package '%s' not found", str);
            goto error;
        } else {
            package = str;
        }
    } else {
        if (!corto_instanceof(corto_package_o, p)) {
            corto_seterr("object '%s' is not a package", str);
            goto error;
        } else {
            package = corto_fullpath(NULL, p);
        }
        corto_release(p);
    }

    return package;
error:
    return NULL;
}

corto_int16 cortotool_add(int argc, char* argv[]) {
    corto_ll silent, mute, nobuild, nocoverage, project, packages;
    corto_bool build = FALSE;
    CORTO_UNUSED(argc);

    corto_argdata *data = corto_argparse(
      argv,
      (corto_argdata[]){
        /* Ignore first argument */
        {"$0", NULL, NULL},
        {"--silent", &silent, NULL},
        {"--mute", &mute, NULL},
        {"--nobuild", &nobuild, NULL},
        {"--nocoverage", &nocoverage, NULL},

        /* Match at most one project directory */
        {"$?*", &project, NULL},

        /* At least one package must be specified */
        {"$+*", &packages, NULL},
        {NULL}
      }
    );

    if (!data) {
        goto error;
    }

    /* Move to project directory */
    if (project) {
        if (corto_chdir(corto_llGet(project, 0))) {
            goto error;
        }
    }

    /* Load packages */
    if (packages) {
        corto_iter iter = corto_llIter(packages);
        while (corto_iter_hasNext(&iter)) {
            /* Test whether package exists */
            corto_string package =
                cortotool_lookupPackage(corto_iter_next(&iter));
            if (!package) {
                goto error;
            }

            /* Use fully scoped name from here */
            if (!corto_loadRequiresPackage(package)) {
                corto_mkdir(".corto");
                corto_file f = corto_fileAppend(".corto/packages.txt");
                if (!f) {
                    corto_seterr("failed to open .corto/packages.txt (check permissions)");
                    goto error;
                }

                /* Only add fully scoped names to package file */
                if (*package != '/') {
                    fprintf(corto_fileGet(f), "/%s\n", package);
                } else {
                    fprintf(corto_fileGet(f), "%s\n", package);
                }
                corto_fileClose(f);
                build = TRUE;

                if (!silent) {
                    printf(CORTO_PROMPT "package '%s' added to project\n", package);
                }
            } else {
                if (!silent) {
                    printf(CORTO_PROMPT "package '%s' is already added to the project\n", package);
                }
            }

        }
    }

    if (build && !nobuild) {
        cortotool_build(3, (char*[]){
          "build",
          silent ? "--silent" : "",
          mute ? "--mute" : "",
          nocoverage ? "--nocoverage" : "",
          NULL
        });
    }

    corto_argclean(data);

    return 0;
error:
    corto_error(CORTO_PROMPT "add: %s", corto_lasterr());
    return -1;
}

static corto_bool cortotool_removeEntry(corto_file file, corto_ll list, corto_string entry) {
    corto_bool found = FALSE;
    corto_iter iter = corto_llIter(list);

    while (corto_iter_hasNext(&iter)) {
        corto_string str = corto_iter_next(&iter);
        if (strcmp(str, entry)) {
            fprintf(corto_fileGet(file), "%s\n", str);
        } else {
            found = TRUE;
        }
    }

    return found;
}

corto_int16 cortotool_remove(int argc, char* argv[]) {
    corto_ll silent, mute, nobuild, project, packages;
    corto_bool build = FALSE;

    CORTO_UNUSED(argc);

    corto_argdata *data = corto_argparse(
      argv,
      (corto_argdata[]){
        /* Ignore first argument */
        {"$0", NULL, NULL},
        {"--silent", &silent, NULL},
        {"--mute", &mute, NULL},
        {"--nobuild", &nobuild, NULL},

        /* Match at most one project directory */
        {"$?*", &project, NULL},

        /* At least one package must be specified */
        {"$+*", &packages, NULL},
        {NULL}
      }
    );

    /* Move to project directory */
    if (project) {
        if (corto_chdir(corto_llGet(project, 0))) {
            goto error;
        }
    }

    if (packages) {
        corto_iter iter = corto_llIter(packages);
        while (corto_iter_hasNext(&iter)) {
            corto_string arg = corto_iter_next(&iter);
            corto_string package = cortotool_lookupPackage(arg);
            if (!package) {
                package = arg; /* Try to remove by matching string */
            }

            corto_ll packages = corto_loadGetPackages();
            corto_file file = corto_fileOpen(".corto/packages.txt");
            corto_bool found = cortotool_removeEntry(file, packages, package);
            corto_fileClose(file);
            corto_loadFreePackages(packages);

            if (!found) {
                corto_error("'%s' ('%s') not found in package file", arg, package);
                goto error;
            } else {
                build = TRUE;
                printf(CORTO_PROMPT "package '%s' removed from project\n", package);
            }
        }
    }

    if (build && !nobuild) {
        cortotool_build(3, (char*[]){
          "build",
          silent ? "--silent" : "",
          mute ? "--mute" : "",
          NULL
        });
    }

    corto_argclean(data);

    return 0;
error:
    return -1;
}

corto_int16 cortotool_list(int argc, char* argv[]) {
    corto_ll locate, project;

    CORTO_UNUSED(argc);

    corto_argdata *data = corto_argparse(
      argv,
      (corto_argdata[]){
        /* Ignore first argument */
        {"$0", NULL, NULL},
        {"--locate", &locate, NULL},

        /* Match at most one project directory */
        {"$?*", &project, NULL},
        {NULL}
      }
    );

    if (project) {
        corto_chdir(corto_llGet(project, 0));
        corto_ll packages = corto_loadGetPackages();
        if (packages && corto_llSize(packages)) {
            corto_iter iter = corto_llIter(packages);
            while (corto_iter_hasNext(&iter)) {
                corto_string str = corto_iter_next(&iter);
                corto_string package = corto_locate(str, NULL, CORTO_LOCATION_LIB);
                if (package) {
                    printf("  %s%s%s  =>  %s\n", CORTO_CYAN, str, CORTO_NORMAL, package);
                } else {
                  printf("  %s%s%s  =>  %smissing%s\n", CORTO_CYAN, str, CORTO_NORMAL, CORTO_RED, CORTO_NORMAL);
                }
            }
        } else {
            printf(CORTO_PROMPT "no packages to list\n");
        }

        if (packages) {
            corto_loadFreePackages(packages);
        }
    } else {
        corto_iter it;
        corto_int32 count = 0, globalCount = 0;
        if (corto_select(NULL, "//").type("/corto/core/package").iter(&it)) {
            goto error;
        }
        while (corto_iter_hasNext(&it)) {
            corto_result *r = corto_iter_next(&it);
            corto_id id; sprintf(id, "%s/%s", r->parent, r->id);
            char *lib = corto_locate(id, NULL, CORTO_LOCATION_LIB);
            if (lib) {
                if (locate) {
                    char *env = corto_locate(id, NULL, CORTO_LOCATION_ENV);
                    corto_bool isGlobal = !strcmp(env, "/usr/local");
                    count ++;
                    if (isGlobal) globalCount ++;
                    printf("%s%s%s  %s=>%s  %s\n", 
                        CORTO_CYAN, id, CORTO_NORMAL, 
                        isGlobal ? CORTO_GREEN : CORTO_MAGENTA, CORTO_NORMAL,
                        lib);
                } else {
                    printf("%s\n", id);
                }
            } else if (corto_lasterr()) {
                printf("%s%s%s%s\n", 
                    CORTO_RED, id, CORTO_NORMAL, corto_lasterr());                
            }
            corto_dealloc(lib);
        }
        if (locate) {
            printf("\nTotal: %d packages (%d %sglobal%s, %d %slocal%s)\n", 
                count, 
                globalCount, CORTO_GREEN, CORTO_NORMAL, 
                count - globalCount, CORTO_MAGENTA, CORTO_NORMAL);
        }
    }

    corto_argclean(data);

    return 0;
error:
    corto_error("%s", corto_lasterr());
    return -1;
}

void cortotool_addHelp(void) {
    printf("Usage: corto add <package>\n");
    printf("       corto add <project> <package>\n");
    printf("\n");
    printf("Add packages to your Corto project.\n");
    printf("\n");
}

void cortotool_removeHelp(void) {
    printf("Usage: corto remove <package>\n");
    printf("       corto remove <project> <package>\n");
    printf("\n");
    printf("Remove a previously added package from your Corto project.\n");
    printf("\n");
}

void cortotool_listHelp(void) {
    printf("Usage: corto list\n");
    printf("       corto list <project>\n");
    printf("\n");
    printf("List the packages added to your Corto project.\n");
    printf("\n");
}
