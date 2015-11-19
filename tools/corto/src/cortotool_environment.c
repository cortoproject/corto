#include "cortotool_environment.h"

char* cortotool_environmentPath(char* name) {
    char* cortoHome = corto_getenv("CORTO_HOME");
    if (!cortoHome) {
        corto_seterr("could not find CORTO_HOME");
        goto error;
    }
    char* path = NULL;
    if (name) {
        if (corto_asprintf(&path, "%s/env/%s", cortoHome, name) < 0) {
            goto error;
        }
    } else {
        if (corto_asprintf(&path, "%s/env", cortoHome) < 0) {
            goto error;
        }
    }
    return path;
error:
    return NULL;
}

corto_int16 cortotool_createEnvironment(int argc, char *argv[]) {
    char* activeEnvironment = getenv("CORTO_ENVIRONMENT");
    if (activeEnvironment) {
        corto_error("cannot create environment if %s is active", activeEnvironment);
        goto error;
    }
    if (argc < 2) {
        corto_error("did not provide environment name to create");
        goto error;
    }
    
    char* name = argv[1];
    FILE* script = fopen("./.cortocreateenvironment", "w");
    if (!script) {
        goto error;
    }
    corto_setenv("CORTO_CREATE_ENVIRONMENT", name, FALSE);
    fprintf(
        script,
        "env_path=\"$CORTO_HOME/env/$CORTO_CREATE_ENVIRONMENT\"\n"
        "mkdir -p \"$env_path/lib\"\n"
        "mkdir -p \"$env_path/include\"\n"
        "mkdir -p \"$env_path/bin\"\n"
        "mkdir -p \"$env_path/etc\"\n"
        "ln -s \"$CORTO_HOME/bin/corto\" \"$env_path/bin/corto\"\n"
    );
    if (fclose(script)) {
        corto_error("could not close script");
        goto error;
    }

    corto_pid pid = corto_procrun("sh", (char*[]){"sh", "./.cortocreateenvironment", NULL});
    corto_int8 procResult = 0;
    if (corto_procwait(pid, &procResult) || procResult) {
        corto_error("could not execute script");
        goto error;
    }

    if (corto_rm("./.cortocreateenvironment")) {
        corto_error("could not remove script");
        goto error;
    }
    return 0;
error:
    return 1;
}

corto_int16 cortotool_deleteEnvironment(int argc, char *argv[]) {
    char* activeEnvironment = getenv("CORTO_ENVIRONMENT");
    if (activeEnvironment) {
        corto_error("cannot delete environment if %s is active", activeEnvironment);
        goto error;
    }
    if (argc < 2) {
        corto_error("did not provide environment name to delete");
        goto error;
    }
    
    char* name = argv[1];
    FILE* script = fopen("./.cortodeleteenvironment", "w");
    if (!script) {
        goto error;
    }
    corto_setenv("CORTO_DELETE_ENVIRONMENT", name, FALSE);
    fprintf(
        script,
        "env_path=\"$CORTO_HOME/env/$CORTO_DELETE_ENVIRONMENT\"\n"
        "rm -rf \"$env_path\"\n"
    );
    if (fclose(script)) {
        corto_error("could not close script");
        goto error;
    }

    corto_pid pid = corto_procrun("sh", (char*[]){"sh", "./.cortodeleteenvironment", NULL});
    corto_int8 procResult = 0;
    if (corto_procwait(pid, &procResult) || procResult) {
        corto_error("could not execute script");
        goto error;
    }

    if (corto_rm("./.cortodeleteenvironment")) {
        corto_error("could not remove script");
        goto error;
    }
    return 0;
error:
    return 1;
}
                                                                                                                                                
corto_int16 cortotool_activate(int argc, char *argv[]) {
    char* currentEnvironment = getenv("CORTO_ENVIRONMENT");
    if (currentEnvironment) {
        corto_error("environment %s already activate; use exit to deactivate the environment", currentEnvironment);
        goto errorNoEnv;
    }
    if (argc < 2) {
        corto_error("did not provide an environment name to activate");
        goto errorNoEnv;
    }

    char* name = argv[1];
    char* envPath = cortotool_environmentPath(name);
    if (!envPath) {
        goto errorNoEnv;
    }
    if (!corto_fileTest(envPath)) {
        corto_error("environment %s does not exist", name);
        goto errorNotFound;
    }
    
    char* oldPrompt = corto_getenv("PS1");
    char* newPrompt = NULL;
    if (corto_asprintf(&newPrompt, "(%s) %s", name, oldPrompt) < 0) {
        goto errorNotFound;
    }
    char* currentShell = corto_getenv("SHELL");
    
    corto_setenv("CORTO_ENVIRONMENT", name);
    corto_setenv("CORTO_HOME", "$HOME/.corto/env/$CORTO_ENVIRONMENT");
    corto_setenv("CORTO_TARGET", "$HOME/.corto/env/$CORTO_ENVIRONMENT");
    corto_setenv("CORTO_BUILD", "/usr/local/lib/corto/$CORTO_VERSION/build");


    /* TODO corto_setenv("PS1", "($CORTO_ENVIRONMENT)$PS1") */
    setenv("PS1", newPrompt, TRUE);

    /* TODO corto_setenv("PATH", "$CORTO_HOME:$PATH") */
    char* oldPath = getenv("PATH");
    char* newPath = NULL;
    if (corto_asprintf(&newPath, "%s:%s", getenv("CORTO_HOME"), oldPath) < 0) {
        goto errorNewPath;
    }
    setenv("PATH", newPath, TRUE);
    
    corto_pid pid = corto_procrun(currentShell, (char*[]){currentShell, NULL});
    corto_int8 procResult = 0;
    corto_procwait(pid, &procResult);

    corto_dealloc(newPath);
    corto_dealloc(newPrompt);
    corto_dealloc(envPath);
    return 0;
errorNewPath:
    if (newPath) corto_dealloc(newPath);
    if (newPrompt) corto_dealloc(newPrompt);
errorNotFound:
    corto_dealloc(envPath);
errorNoEnv:
    return -1;
}

corto_int16 cortotool_listEnvironments(int argc, char* argv[]) {
    CORTO_UNUSED(argc);
    CORTO_UNUSED(argv);
    char* home = corto_getenv("HOME");
    if (!home) {
        corto_error("could not find user home directory");
        goto error_home;
    }
    char* envPath = cortotool_environmentPath(NULL);
    if (!envPath) {
        goto error_envPath;
    }
    corto_ll files = corto_opendir(envPath);
    if (!files) {
        corto_error("could not list env directories");
        goto error_envPath;
    }
    corto_iter iter = corto_llIter(files);
    while (corto_iterHasNext(&iter)) {
        char* name = corto_iterNext(&iter);
        char* path = NULL;
        corto_asprintf(&path, "%s/%s", envPath, name);
        if (corto_isdir(path)) {
            corto_print("%s", name);
        }
        corto_dealloc(path);
    }
    corto_closedir(files);
    corto_dealloc(envPath);
    return 0;
error_envPath:
    if (envPath) corto_dealloc(envPath);
error_home:
    return -1;
}
