/*
 * corto_loader.c
 *
 *  Created on: Aug 30, 2012
 *      Author: sander
 */

#define corto_lang_LIB
#include "corto.h"
#include "stdlib.h"
#include "string.h"
#include <sys/stat.h>
#include <errno.h>

#ifdef CORTO_LOADER

void corto_onexit(void(*handler)(void*),void*userData);

#include "corto_platform.h"

static corto_ll fileHandlers = NULL;
static corto_ll libraries = NULL;
static corto_ll fileAdmin = NULL;

struct corto_fileAdmin {
    corto_string name;
    corto_bool loading;
};

struct corto_fileHandler {
    corto_string ext;
    corto_loadAction load;
    void* userData;
};

/* Lookup file */
static struct corto_fileAdmin* corto_fileAdminFind(corto_string library) {
    if (fileAdmin) {
        corto_iter iter = corto_llIter(fileAdmin);
        struct corto_fileAdmin *lib;

        while (corto_iterHasNext(&iter)) {
            lib = corto_iterNext(&iter);
            if (!strcmp(lib->name, library)) {
                return lib;
            }
        }
    }

    return NULL;
}

/* Add file */
static struct corto_fileAdmin* corto_fileAdminAdd(corto_string library) {
    struct corto_fileAdmin *lib = corto_alloc(sizeof(struct corto_fileAdmin));
    lib->name = corto_strdup(library);
    lib->loading = TRUE;
    if (!fileAdmin) {
        fileAdmin = corto_llNew();
    }
    corto_llInsert(fileAdmin, lib);
    return lib;
}

/* Lookup file handler action */
static int corto_lookupExtWalk(struct corto_fileHandler* h, struct corto_fileHandler** data) {
    if (!strcmp(h->ext, (*data)->ext)) {
        *data = h;
        return 0;
    }
    return 1;
}

/* Lookup file handler */
static struct corto_fileHandler* corto_lookupExt(corto_string ext) {
    struct corto_fileHandler dummy, *dummy_p;

    dummy.ext = ext;
    dummy_p = &dummy;

    /* Walk handlers */
    if (fileHandlers) {
        corto_llWalk(fileHandlers, (corto_walkAction)corto_lookupExtWalk, &dummy_p);
    }

    if (dummy_p == &dummy) {
        dummy_p = NULL;
    }

    return dummy_p;
}

/* Register a filetype */
int corto_loaderRegister(corto_string ext, corto_loadAction handler, void* userData) {
    struct corto_fileHandler* h;

    /* Check if extension is already registered */
    if ((h = corto_lookupExt(ext))) {
        if (h->load != handler) {
            corto_error("corto_loaderRegister: extension '%s' is already registered with another loader.", ext);
            abort();
            goto error;
        }
    } else {
        h = corto_alloc(sizeof(struct corto_fileHandler));
        h->ext = ext;
        h->load = handler;
        h->userData = userData;

        if (!fileHandlers) {
            fileHandlers = corto_llNew();
        }

        corto_llAppend(fileHandlers, h);
    }

    return 0;
error:
    return -1;
}

/* Convert package identifier to filename */
static corto_string corto_packageToFile(corto_string package) {
    corto_char ch, *ptr, *bptr;
    corto_string fileName, path, start;
    int fileNameLength;

    ptr = package;
    path = malloc(strlen(package) * 2 + strlen("packages//lib.so") + 1);

    strcpy(path, "packages/");
    bptr = path + strlen("packages/");
    start = bptr;
    fileName = bptr;

    while ((ch = *ptr)) {
        switch (ch) {
        case ':':
            ptr++;
        case '/':
            if (bptr != start) {
                *bptr = '/';
                bptr++;
            }
            fileName = bptr;
            break;
        default:
            *bptr = ch;
            bptr++;
            break;
        }
        ptr++;
    }
    *bptr = '\0';

    fileNameLength = strlen(fileName);
    memcpy(fileName + fileNameLength, "/lib", 4);
    memcpy(fileName + fileNameLength + 4, fileName, fileNameLength);
    memcpy(fileName + fileNameLength * 2 + 4, ".so\0", 4);

    return path;
}

static corto_dl corto_loadValidLibrary(corto_string fileName) {
    corto_dl result = NULL;
    corto_string ___ (*build)(void);

    if (!(result = corto_dlOpen(fileName))) {
        corto_error("%s", corto_dlError());
        goto error;
    }

    /* Lookup build function */
    build = (corto_string ___ (*)(void))corto_dlProc(result, "corto_getBuild");

    /* Validate version */
    if (!build || strcmp(build(), corto_getBuild())) {
        corto_seterr("%s: uses different corto library", fileName);
        goto error;
    }

    return result;
error:
    if (result) corto_dlClose(result);
    return NULL;
}

static corto_bool corto_checkLibrary(corto_string fileName) {
    corto_dl dl = corto_loadValidLibrary(fileName);
    corto_bool result = FALSE;
    if (dl) {
        result = TRUE;
        corto_dlClose(dl);
    }
    return result;
}

/*
 * Load a Corto library
 * Receives the absolute path to the lib<name>.so file.
 */
static int corto_loadLibrary(corto_string fileName, int argc, char* argv[]) {
    corto_dl dl = NULL;
    int (*proc)(int argc, char* argv[]);

    if (!(dl = corto_loadValidLibrary(fileName))) {
        goto error;
    }

    /* Lookup main function */
    proc = (int(*)(int,char*[]))corto_dlProc(dl, "cortomain");
    if (!proc) {
        corto_seterr("%s: unresolved 'cortomain'", fileName);
        goto error;
    }

    /* Call main */
    if (proc(argc, argv)) {
        corto_seterr("%s: cortomain failed", fileName);
        goto error;
    }

    /* Add library to libraries list */
    if (!libraries) {
        libraries = corto_llNew();
    }
    corto_llInsert(libraries, dl);

    return 0;
error:
    if (dl) corto_dlClose(dl);
    return -1;
}

void (*corto_loaderResolveProc(corto_string procName))(void) {
    void (*result)(void) = NULL;

    /* Search libraries for specified symbol */
    corto_iter iter = corto_llIter(libraries);
    while (!result && corto_iterHasNext(&iter)) {
        corto_dl dl = corto_iterNext(&iter);
        result = (void(*)(void))corto_dlProc(dl, procName);
    }

    return result;
}

/* Load a corto component from a default component location */
int corto_loadComponent(corto_string component, int argc, char* argv[]) {
    int result = 0;

    corto_string path = corto_envparse(
        "$CORTO_TARGET/lib/corto/%s.%s/components/lib%s.so",
        CORTO_VERSION_MAJOR, CORTO_VERSION_MINOR, component);
    if (!path) {
        goto error;
    }

    /* Don't load component twice */
    struct corto_fileAdmin *lib = corto_fileAdminFind(path);
    if (lib) {
        goto loaded;
    }

    result = corto_loadLibrary(path, argc, argv);
    corto_dealloc(path);

loaded:
    return result;
error:
    return -1;
}

/*
 * An adapter on top of corto_loadLibrary to fit the corto_loadAction signature.
 */
int corto_loadLibraryAction(corto_string file, int argc, char* argv[], void *data) {
    CORTO_UNUSED(data);
    return corto_loadLibrary(file, argc, argv);
}

/* Load xml interface */
static int corto_loadXml(void) {
    return corto_loadComponent("xml", 0, NULL);
}

/* Load a package */
int corto_load(corto_string str, int argc, char* argv[]) {
    corto_char ext[16];
    struct corto_fileHandler* h;
    int result = -1;
    struct corto_fileAdmin *lib = NULL;

    /* Packages should be loaded with minimal attributes to conserve memory */
    corto_attr prevAttr = corto_setAttr(CORTO_ATTR_PERSISTENT);

    lib = corto_fileAdminFind(str);

    if (lib) {
        if (lib->loading) {
            corto_error("illegal recursive load of file '%s' from:", lib->name);
            corto_iter iter = corto_llIter(fileAdmin);
            while (corto_iterHasNext(&iter)) {
                struct corto_fileAdmin *lib = corto_iterNext(&iter);
                if (lib->loading) {
                    fprintf(stderr, "   %s\n", lib->name);
                }
            }
            corto_backtrace(stderr);
            abort();
        } else {
            goto loaded;
        }
    }

    /* Get extension from filename */
    if (!corto_fileExtension(str, ext)) {
        goto error;
    }

    /* Handle known extensions */
    if (!strcmp(ext, "cx")) {
        corto_load("corto::ast", 0, NULL);
    } else if (!strcmp(ext, "xml")) {
        corto_loadXml();
    } else if (!strcmp(ext, "md")) {
        corto_load("corto::md", 0, NULL);
    }

    /* Lookup extension */
    h = corto_lookupExt(ext);
    if (h) {
        /* Load file */
        lib = corto_fileAdminAdd(str);
        result = h->load(str, argc, argv, h->userData);
        lib->loading = FALSE;
    } else {
        corto_seterr("file extension '%s' not supported.", ext);
        goto error;
    }

    corto_setAttr(prevAttr);
    return result;
error:
    corto_setAttr(prevAttr);
    return -1;
loaded:
    corto_setAttr(prevAttr);
    return 0;
}

static time_t corto_getModified(corto_string file) {
    struct stat attr;

    if (stat(file, &attr) < 0) {
        printf("failed to stat '%s' (%s)\n", file, strerror(errno));
    }

    return attr.st_mtime;
}

corto_string corto_locateLibrary(corto_string lib) {
    corto_string targetPath = NULL, homePath = NULL, usrPath = NULL;
    corto_string result = NULL;
    time_t t = 0;

    /* Look for local packages first */
    targetPath = corto_envparse("$CORTO_TARGET/lib/corto/%s.%s/%s",
        CORTO_VERSION_MAJOR, CORTO_VERSION_MINOR, lib);
    if (!targetPath) {
        goto error;
    }
    if (corto_fileTest(targetPath)) {
        if (corto_checkLibrary(targetPath)) {
            t = corto_getModified(targetPath);
            result = targetPath;
        }
    }

    /* Look for packages in CORTO_HOME */
    if (strcmp(corto_getenv("CORTO_HOME"), corto_getenv("CORTO_TARGET"))) {
        corto_string homePath = corto_envparse("$CORTO_HOME/lib/corto/%s.%s/%s",
            CORTO_VERSION_MAJOR, CORTO_VERSION_MINOR, lib);
        if (!homePath) {
            goto error;
        }
        if (corto_fileTest(homePath)) {
            time_t myT = corto_getModified(homePath);
            if ((myT > t) || !result) {
                if (corto_checkLibrary(homePath)) {
                    t = myT;
                    result = homePath;
                }
            }
        }
    }

    /* Look for global packages */
    if (strcmp("/usr/local", corto_getenv("CORTO_TARGET")) &&
        strcmp("/usr/local", corto_getenv("CORTO_HOME"))) {
        usrPath = corto_envparse("/usr/local/lib/corto/%s.%s/%s",
            CORTO_VERSION_MAJOR, CORTO_VERSION_MINOR, lib);
        if (!usrPath) {
            goto error;
        }
        if (corto_fileTest(usrPath)) {
            time_t myT = corto_getModified(usrPath);
            if ((myT >= t) || !result) {
                if (corto_checkLibrary(usrPath)) {
                    t = myT;
                    result = usrPath;
                }
            }
        }
    }

    if (targetPath && (targetPath != result)) corto_dealloc(targetPath);
    if (homePath && (homePath != result)) corto_dealloc(homePath);
    if (usrPath && (usrPath != result)) corto_dealloc(usrPath);

    return result;
error:
    return NULL;
}

corto_string corto_locateGenerator(corto_string component) {
    corto_string relativePath = NULL;
    corto_string result = NULL;

    corto_asprintf(&relativePath, "generators/lib%s.so", component);
    result = corto_locateLibrary(relativePath);
    corto_dealloc(relativePath);

    return result;
}

corto_string corto_locateComponent(corto_string component) {
    corto_string relativePath = NULL;
    corto_string result = NULL;

    corto_asprintf(&relativePath, "components/lib%s.so", component);
    result = corto_locateLibrary(relativePath);
    corto_dealloc(relativePath);

    return result;
}

corto_string corto_locate(corto_string package) {
    corto_string relativePath = corto_packageToFile(package);
    corto_string result = NULL;

    if (!relativePath) {
        goto error;
    }

    result = corto_locateLibrary(relativePath);
    corto_dealloc(relativePath);

    return result;
error:
    return NULL;
}

static corto_ll corto_loadGetDependencies(corto_string file) {
    corto_ll result = NULL;

    if (corto_fileTest(file)) {
        corto_id name;
        result = corto_llNew();
        corto_file f = corto_fileRead(file);
        char *dependency;
        while ((dependency = corto_fileReadLine(f, name, sizeof(name)))) {
            corto_llAppend(result, corto_strdup(dependency));
        }
        corto_fileClose(f);
    }

    return result;
}

static void corto_loadFreeDependencies(corto_ll dependencies) {
    if (dependencies) {
        corto_iter iter = corto_llIter(dependencies);
        while (corto_iterHasNext(&iter)) {
            corto_dealloc(corto_iterNext(&iter));
        }
        corto_dealloc(dependencies);
    }
}

static corto_bool corto_loadRequiresDependency(corto_ll dependencies, corto_string query) {
    corto_bool result = FALSE;

    if (dependencies) {
        corto_iter iter = corto_llIter(dependencies);
        while (!result && corto_iterHasNext(&iter)) {
            corto_string package = corto_iterNext(&iter);
            if (!strcmp(package, query)) {
                result = TRUE;
            }
        }
    }

    return result;
}

corto_ll corto_loadGetPackages(void) {
    return corto_loadGetDependencies(".corto/packages.txt");
}

void corto_loadFreePackages(corto_ll packages) {
    corto_loadFreeDependencies(packages);
}

corto_bool corto_loadRequiresPackage(corto_string package) {
    corto_ll packages = corto_loadGetPackages();
    corto_bool result = corto_loadRequiresDependency(packages, package);
    corto_loadFreePackages(packages);
    return result;
}

corto_ll corto_loadGetComponents(void) {
    return corto_loadGetDependencies(".corto/components.txt");
}

void corto_loadFreeComponents(corto_ll components) {
    corto_loadFreeDependencies(components);
}

corto_bool corto_loadRequiresComponent(corto_string component) {
    corto_ll components = corto_loadGetComponents();
    corto_bool result = corto_loadRequiresDependency(components, component);
    corto_loadFreePackages(components);
    return result;
}

int corto_loadPackages(void) {
    corto_ll packages = corto_loadGetPackages();
    if (packages) {
        corto_iter iter = corto_llIter(packages);
        while (corto_iterHasNext(&iter)) {
            corto_load(corto_iterNext(&iter), 0, NULL);
        }
        corto_loadFreePackages(packages);
    }
    return 0;
}

/* Load package */
static int corto_packageLoader(corto_string package) {
    corto_string fileName;
    int result;

    fileName = corto_locate(package);
    if (!fileName) {
        return -1;
    }

    result = corto_loadLibrary(fileName, 0, NULL);
    corto_dealloc(fileName);

    return result;
}

/* Load file with unspecified extension */
int corto_fileLoader(corto_string file, int argc, char* argv[], void* udata) {
    CORTO_UNUSED(udata);
    corto_id testName;

    sprintf(testName, "%s.xml", file);
    if (corto_fileTest(testName)) {
        if (!corto_loadXml()) {
            return corto_load(testName, argc, argv);
        }
    }

    sprintf(testName, "%s.cx", file);
    if (corto_fileTest(testName)) {
        if (!corto_load("corto/ast", 0, NULL)) {
            return corto_load(testName, argc, argv);
        }
    }

    if (!corto_packageLoader(file)) {
        return 0;
    }

    return -1;
}

void corto_loaderOnExit(void* udata) {
    struct corto_fileHandler* h;
    corto_dl dl;
    corto_iter iter;

    CORTO_UNUSED(udata);

    /* Free loaded administration */

    if (fileAdmin) {
        iter = corto_llIter(fileAdmin);
         while(corto_iterHasNext(&iter)) {
             struct corto_fileAdmin *loaded = corto_iterNext(&iter);
             corto_dealloc(loaded->name);
             corto_dealloc(loaded);
         }
         corto_llFree(fileAdmin);
    }

    /* Free handlers */
    while ((h = corto_llTakeFirst(fileHandlers))) {
        corto_dealloc(h);
    }
    corto_llFree(fileHandlers);

    /* Free libraries */
    if (libraries) {
        while ((dl = corto_llTakeFirst(libraries))) {
            corto_dlClose(dl);
        }
        corto_llFree(libraries);
    }
}

#else
int corto_load(corto_string str) {
    CORTO_UNUSED(str);
    corto_error("corto build doesn't include loader");
    return -1;
}
#endif
