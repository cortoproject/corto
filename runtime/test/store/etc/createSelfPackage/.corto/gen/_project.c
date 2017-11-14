/* _project.c
 *
 * This file contains the project entry function. Here, we
 * start/stop corto and load all dependencies, before and after
 * invoking the main function of your project.
 */

#include <createSelfPackage/createSelfPackage.h>

int createSelfPackageMain(int argc, char* argv[]);

#ifdef __cplusplus
extern "C"
#endif
int cortomain(int argc, char* argv[]) {
    if (corto_load("/corto/c", 0, NULL)) return -1;
    if (createSelfPackageMain(argc, argv)) return -1;
    return 0;
}

