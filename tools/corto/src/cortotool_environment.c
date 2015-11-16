#include "cortotool_environment.h"

char* cortotool_environmentPath(char* name) {
    char* cortoHome = getenv("CORTO_HOME");
    if (!cortoHome) {
        corto_seterr("could not find CORTO_HOME");
        goto error;
    }
    char* path = NULL;
    if (corto_asprintf(&path, "%s/env/%s", cortoHome, name) < 0) {
        goto error;
    }
    return path;
error:
    return NULL;
}
                                                                                                                                                
corto_int16 cortotool_activate(int argc, char *argv[]) {
    if (argc < 1) {
        corto_seterr("did not provide an environment name to activate");
        goto error_no_env;
    }
    char* name = argv[1];
    char* path = cortotool_environmentPath(name);
    if (!corto_fileTest(path)) {
        corto_seterr("environment %s does not exist", name);
        goto error_not_found;
    }
    setenv("CORTO_ENVIRONMENT", name, FALSE);
    corto_dealloc(path);
    return 0;
error_not_found:
    corto_dealloc(path);
error_no_env:
    return -1;
}

corto_int16 cortotool_deactivate(int argc, char *argv[]) {
    CORTO_UNUSED(argc);
    CORTO_UNUSED(argv);
    return 0;
}
