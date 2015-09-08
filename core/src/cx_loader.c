/*
 * cx_loader.c
 *
 *  Created on: Aug 30, 2012
 *      Author: sander
 */

#include "corto.h"
#include "stdlib.h"
#include "string.h"
#include <sys/stat.h>
#include <errno.h>

#ifdef CX_LOADER

void cx_onexit(void(*handler)(void*),void*userData);

#include "cx_platform.h"

static cx_ll fileHandlers = NULL;
static cx_ll libraries = NULL;

struct cx_fileHandler {
    cx_string ext;
    cx_loadAction load;
    void* userData;
};

/* Lookup file handler action */
static int cx_lookupExtWalk(struct cx_fileHandler* h, struct cx_fileHandler** data) {
    if (!strcmp(h->ext, (*data)->ext)) {
        *data = h;
        return 0;
    }
    return 1;
}

/* Lookup file handler */
static struct cx_fileHandler* cx_lookupExt(cx_string ext) {
    struct cx_fileHandler dummy, *dummy_p;

    dummy.ext = ext;
    dummy_p = &dummy;

    /* Walk handlers */
    if (fileHandlers) {
        cx_llWalk(fileHandlers, (cx_walkAction)cx_lookupExtWalk, &dummy_p);
    }

    if (dummy_p == &dummy) {
        dummy_p = NULL;
    }

    return dummy_p;
}

/* Get file extension */
static void cx_fileExt(cx_char* buffer, cx_string file) {
    cx_char *ptr, *bptr;
    cx_char ch;

    bptr = buffer;

    ptr = file + strlen(file);
    while (ptr >= file) {
        if (*ptr == '.') break;
        ptr--;
    }
    if (ptr >= file) {
        ptr++;
        while ((ch = *ptr)) {
            *bptr = ch;
            ptr++;
            bptr++;
        }
    }
    *bptr = '\0';
}

/* Register a filetype */
int cx_loaderRegister(cx_string ext, cx_loadAction handler, void* userData) {
    struct cx_fileHandler* h;

    /* Check if extension is already registered */
    if ((h = cx_lookupExt(ext))) {
        if (h->load != handler) {
            cx_error("cx_loaderRegister: extension '%s' is already registered with another loader.", ext);
            goto error;
        }
    } else {
        h = cx_alloc(sizeof(struct cx_fileHandler));
        h->ext = ext;
        h->load = handler;
        h->userData = userData;

        if (!fileHandlers) {
            fileHandlers = cx_llNew();
        }

        cx_llAppend(fileHandlers, h);
    }

    return 0;
error:
    return -1;
}

/* Convert package identifier to filename */
static cx_string cx_packageToFile(cx_string package) {
    cx_char ch, *ptr, *bptr;
    cx_string fileName, path, start;
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

/*
 * Load a Corto library
 * Receives the absolute path to the lib<name>.so file.
 */
static int cx_loadLibrary(cx_string fileName, int argc, char* argv[]) {
    cx_dl dl = NULL;
    int (*proc)(int argc, char* argv[]);

    if (!(dl = cx_dlOpen(fileName))) {
        cx_error("%s", cx_dlError());
        goto error;
    }

    /* Lookup main function */
    proc = (int(*)(int,char*[]))cx_dlProc(dl, "cortomain");
    if (!proc) {
        cx_seterr("unresolved 'cortomain'", fileName);
        goto error;
    }

    /* Call main */
    if (proc(argc, argv)) {
        cx_seterr("cortomain failed", fileName);
        goto error;
    }

    /* Add library to libraries list */
    if (!libraries) {
        libraries = cx_llNew();
    }
    cx_llInsert(libraries, dl);

    return 0;
error:
    if (dl) cx_dlClose(dl);
    return -1;  
}

/*
 * An adapter on top of cx_loadLibrary to fit the cx_loadAction signature.
 */
static int cx_loadLibraryAction(cx_string file, int argc, char* argv[], void *data) {
    CX_UNUSED(data);
    return cx_loadLibrary(file, argc, argv);
}

static cx_ll filesLoaded = NULL;

/* Load xml interface */
static int cx_loadXml(void) {
    int result;
    cx_string path = cx_envparse("$CORTO_TARGET/lib/corto/%s/components/libxml.so", CORTO_VERSION);
    result = cx_loadLibrary(path, 0, NULL);
    cx_dealloc(path);
    return result;
}

/* Load a package */
int cx_load(cx_string str, int argc, char* argv[]) {
    cx_char ext[16];
    struct cx_fileHandler* h;
    int result = -1;

    if (!filesLoaded) {
        filesLoaded = cx_llNew();
    } else {
        cx_iter iter;
        cx_string loaded;

        /* Lookup whether a file is already loaded */
        iter = cx_llIter(filesLoaded);
        while (cx_iterHasNext(&iter)) {
            loaded = cx_iterNext(&iter);
            if (!strcmp(loaded, str)) {
                /* File is already loaded! */
                result = 0;
                goto loaded;
            }
        }
    }

    /* Get extension from filename */
    cx_fileExt(ext, str);

    /* Handle known extensions */
    if (!strcmp(ext, "cx")) {
        cx_load("corto::Fast", 0, NULL);
    } else if (!strcmp(ext, "xml")) {
        cx_loadXml();
    }

    /* Lookup extension */
    h = cx_lookupExt(ext);
    if (h) {
        /* Load file */
        result = h->load(str, argc, argv, h->userData);
    } else {
        cx_error("file-extension '%s' not supported.", ext);
        goto error;
    }

    if (!result) {
        cx_llInsert(filesLoaded, cx_strdup(str));
    }

    return result;
error:
    return -1;
loaded:
    return 0;
}

static time_t cx_getModified(cx_string file) {
    struct stat attr;

    if (stat(file, &attr) < 0) {
        printf("failed to stat '%s' (%s)\n", file, strerror(errno));
    }

    return attr.st_mtime;    
}

cx_string cx_locateLibrary(cx_string lib) {
    cx_string targetPath = NULL, homePath = NULL, usrPath = NULL;
    cx_string result = NULL;
    time_t t = 0;

    /* Look for local packages first */
    targetPath = cx_envparse("$CORTO_TARGET/lib/corto/%s/%s", CORTO_VERSION, lib);
    if (cx_fileTest(targetPath)) {
        t = cx_getModified(targetPath);
        result = targetPath;
    }

    /* Look for packages in CORTO_HOME */
    if (strcmp(cx_getenv("CORTO_HOME"), cx_getenv("CORTO_TARGET"))) {
        cx_string homePath = cx_envparse("$CORTO_HOME/lib/corto/%s/%s", CORTO_VERSION, lib);
        if (cx_fileTest(homePath)) {
            time_t myT = cx_getModified(homePath);
            if ((myT > t) || !result) {
                t = myT;
                result = homePath;
            }
        }
    }

    /* Look for global packages */
    if (strcmp("/usr", cx_getenv("CORTO_TARGET")) && 
        strcmp("/usr", cx_getenv("CORTO_HOME"))) {
        usrPath = cx_envparse("/usr/lib/corto/%s/%s", CORTO_VERSION, lib);
        if (cx_fileTest(usrPath)) {
            time_t myT = cx_getModified(usrPath);
            if ((myT > t) || !result) {
                t = myT;
                result = usrPath;
            }
        }
    }

    if (targetPath && (targetPath != result)) cx_dealloc(targetPath);
    if (homePath && (homePath != result)) cx_dealloc(homePath);
    if (usrPath && (usrPath != result)) cx_dealloc(usrPath);

    return result;   
}

cx_string cx_locateComponent(cx_string component) {
    cx_string relativePath = NULL;
    cx_string result = NULL;

    cx_asprintf(&relativePath, "components/lib%s.so", component);
    result = cx_locateLibrary(relativePath);
    cx_dealloc(relativePath);

    return result;
}

cx_string cx_locate(cx_string package) {
    cx_string relativePath = cx_packageToFile(package);
    cx_string result = NULL;

    if (!relativePath) {
        goto error;
    }

    result = cx_locateLibrary(relativePath);
    cx_dealloc(relativePath);

    return result;
error:
    return NULL;
}

static cx_ll cx_loadGetDependencies(cx_string file) {
    cx_ll result = NULL;

    if (cx_fileTest(file)) {
        cx_id name;
        result = cx_llNew();
        cx_file f = cx_fileRead(file);
        char *dependency;
        while ((dependency = cx_fileReadLine(f, name, sizeof(name)))) {
            cx_llAppend(result, cx_strdup(dependency));
        }
        cx_fileClose(f);
    }

    return result;
}

static void cx_loadFreeDependencies(cx_ll dependencies) {
    if (dependencies) {
        cx_iter iter = cx_llIter(dependencies);
        while (cx_iterHasNext(&iter)) {
            cx_dealloc(cx_iterNext(&iter));
        }
        cx_dealloc(dependencies);
    }
}

static cx_bool cx_loadRequiresDependency(cx_ll dependencies, cx_string query) {
    cx_bool result = FALSE;

    if (dependencies) {
        cx_iter iter = cx_llIter(dependencies);
        while (!result && cx_iterHasNext(&iter)) {
            cx_string package = cx_iterNext(&iter);
            if (!strcmp(package, query)) {
                result = TRUE;
            }
        }
    }

    return result;
}

cx_ll cx_loadGetPackages(void) {
    return cx_loadGetDependencies(".corto/packages.txt");
}

void cx_loadFreePackages(cx_ll packages) {
    cx_loadFreeDependencies(packages);
}

cx_bool cx_loadRequiresPackage(cx_string package) {
    cx_ll packages = cx_loadGetPackages();
    cx_bool result = cx_loadRequiresDependency(packages, package);
    cx_loadFreePackages(packages);
    return result;
}

cx_ll cx_loadGetComponents(void) {
    return cx_loadGetDependencies(".corto/components.txt");
}

void cx_loadFreeComponents(cx_ll components) {
    cx_loadFreeDependencies(components);
}

cx_bool cx_loadRequiresComponent(cx_string component) {
    cx_ll components = cx_loadGetComponents();
    cx_bool result = cx_loadRequiresDependency(components, component);
    cx_loadFreePackages(components);
    return result; 
}

int cx_loadPackages(void) {
    cx_ll packages = cx_loadGetPackages();
    if (packages) {
        cx_iter iter = cx_llIter(packages);
        while (cx_iterHasNext(&iter)) {
            cx_load(cx_iterNext(&iter), 0, NULL);
        }
        cx_loadFreePackages(packages);
    }
    return 0;
}

/* Load package */
static int cx_packageLoader(cx_string package) {
    cx_string fileName;
    int result;

    fileName = cx_locate(package);
    if (!fileName) {
        return -1;
    }

    result = cx_loadLibrary(fileName, 0, NULL);
    cx_dealloc(fileName);

    return result;
}

/* Load file with unspecified extension */
static int cx_fileLoader(cx_string file, int argc, char* argv[], void* udata) {
    CX_UNUSED(udata);
    cx_id testName;
    
    sprintf(testName, "%s.xml", file);
    if (cx_fileTest(testName)) {
        if (!cx_loadXml()) {
            return cx_load(testName, argc, argv);
        }
    }

    sprintf(testName, "%s.cx", file);
    if (cx_fileTest(testName)) {
        if (!cx_load("corto/Fast", 0, NULL)) {
            return cx_load(testName, argc, argv);
        }
    }

    if (!cx_packageLoader(file)) {
        return 0;
    }

    return -1;
}

static void cx_loaderOnExit(void* udata) {
    struct cx_fileHandler* h;
    cx_dl dl;
    void (*proc)(int code);
    cx_iter iter;
    cx_string loaded;

    CX_UNUSED(udata);

    /* Free loaded administration */

    if (filesLoaded) {
        iter = cx_llIter(filesLoaded);
         while(cx_iterHasNext(&iter)) {
             loaded = cx_iterNext(&iter);
             cx_dealloc(loaded);
         }
         cx_llFree(filesLoaded);
    }

    /* Free handlers */
    while ((h = cx_llTakeFirst(fileHandlers))) {
        cx_dealloc(h);
    }
    cx_llFree(fileHandlers);

    /* Free libraries */
    if (libraries) {
        while ((dl = cx_llTakeFirst(libraries))) {
            /* Lookup exit function */
            proc = (void(*)(int))cx_dlProc(dl, "exit");
            if (proc) {
                proc(0);
            }
            cx_dlClose(dl);
        }
        cx_llFree(libraries);
    }
}

/* Register handlers for shared objects */
CX_DLL_CONSTRUCT {

    /* Register exit-handler */
    cx_onexit(cx_loaderOnExit, NULL);

    /* Register library-binding */
    cx_loaderRegister("so", cx_loadLibraryAction, NULL);
    cx_loaderRegister("", cx_fileLoader, NULL);
}
#else
int cx_load(cx_string str) {
    CX_UNUSED(str);
    cx_error("corto build doesn't include loader");
    return -1;
}
#endif
