/*
 * corto_loader.c
 *
 *  Created on: Aug 30, 2012
 *      Author: sander
 */

#include "corto/corto.h"

#ifdef CORTO_LOADER

void corto_onexit(void(*handler)(void*),void*userData);

static corto_ll fileHandlers = NULL;
static corto_ll libraries = NULL;
static corto_ll fileAdmin = NULL;

extern corto_mutex_s corto_adminLock;

struct corto_fileAdmin {
    corto_string name;
    corto_thread loading;
    corto_int16 result;
};

struct corto_fileHandler {
    corto_string ext;
    corto_loadAction load;
    void* userData;
};

static char* corto_convertToPath(corto_string lib, corto_id path) {
    char *ptr, *bptr, ch;
    /* Convert '::' in library name to '/' */
    ptr = lib;
    bptr = path;

    if (ptr[0] == '/') {
        ptr++;
    } else
    if ((ptr[0] == ':') && (ptr[1] == ':')) {
        ptr += 2;
    }

    while ((ch = *ptr)) {
        if (ch == ':') {
            if (ptr[1] == ':') {
                ch = '/';
                ptr++;
            }
        }
        *bptr = ch;

        ptr++;
        bptr++;
    }
    *bptr = '\0';

    return path;
}

/* Lookup file */
static struct corto_fileAdmin* corto_fileAdminFind(corto_string library) {
    if (fileAdmin) {
        corto_iter iter = corto_llIter(fileAdmin);
        struct corto_fileAdmin *lib;
        corto_id libPath, adminPath;

        corto_convertToPath(library, libPath);

        while (corto_iterHasNext(&iter)) {
            lib = corto_iterNext(&iter);
            corto_convertToPath(lib->name, adminPath);
            if (!strcmp(adminPath, libPath)) {
                return lib;
            }
        }
    }

    return NULL;
}

/* Add file */
static struct corto_fileAdmin* corto_fileAdminAdd(corto_string library) {
    struct corto_fileAdmin *lib = corto_calloc(sizeof(struct corto_fileAdmin));
    lib->name = corto_strdup(library);
    lib->loading = corto_threadSelf();
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
    corto_mutexLock(&corto_adminLock);
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
    corto_mutexUnlock(&corto_adminLock);

    return 0;
error:
    return -1;
}

static corto_string corto_replaceColons(corto_id buffer, corto_string package) {
    corto_char ch, *ptr, *bptr;
    corto_string fileName, start;

    fileName = buffer;

    ptr = package;
    bptr = buffer;
    start = bptr;
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

    return fileName;
}

/* Convert package identifier to filename */
static corto_string corto_packageToFile(corto_string package) {
    corto_string path;
#ifdef CORTO_REDIS
    corto_asprintf(&path, "lib%s.so", package[0] == '/' ? package + 1 : package);
    char ch, *ptr;
    for (ptr = path; (ch = *ptr); ptr++) {
        if (ch == '/') *ptr = '_';
    }
#else
    corto_string fileName;
    int fileNameLength;
    path = malloc(strlen(package) * 2 + strlen("/lib.so") + 1);
    fileName = corto_replaceColons(path, package);
    fileNameLength = strlen(fileName);
    memcpy(fileName + fileNameLength, "/lib", 4);
    memcpy(fileName + fileNameLength + 4, fileName, fileNameLength);
    memcpy(fileName + fileNameLength * 2 + 4, ".so\0", 4);
#endif
    return path;
}

static corto_dl corto_loadValidLibrary(corto_string fileName, corto_string *build_out) {
    corto_dl result = NULL;
    corto_string ___ (*build)(void);
    corto_string ___ (*library)(void);

    if (build_out) {
        *build_out = NULL;
    }

    if (!(result = corto_dlOpen(fileName))) {
        corto_seterr("%s", corto_dlError());
        goto error;
    }

    /* Lookup build function */
    build = (corto_string ___ (*)(void))corto_dlProc(result, "corto_getBuild");
    library = (corto_string ___ (*)(void))corto_dlProc(result, "corto_getLibrary");

    /* Validate version */
    if (build && strcmp(build(), corto_getBuild())) {
        corto_seterr(
          "corto: library '%s' links with conflicting corto library\n"
          "  links with: '%s' (%s)\n"
          "  current:    '%s' (%s)\n",
          fileName, library ? library() : "???", build(), corto_getLibrary(), corto_getBuild());
        /* Library is linked with different Corto version */
        if (build_out) {
            *build_out = corto_strdup(build());
        }
        goto error;
    } else if (build) {
        corto_debug(
          "corto: '%s' links with correct corto library\n  build:   '%s'\n  library: '%s'\n",
          fileName, build(), library());
    } else {
        corto_trace("corto: found '%s' which doesn't link with corto", fileName);
    }

    /* If no build function is available, the library is not linked with
     * Corto, and probably represents a --nocorto package */

    return result;
error:
    if (result) corto_dlClose(result);
    return NULL;
}

static corto_bool corto_checkLibrary(corto_string fileName, corto_string *build_out) {
    corto_dl dl = corto_loadValidLibrary(fileName, build_out);
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
    corto_string build = NULL;
    corto_dl dl = NULL;
    int (*proc)(int argc, char* argv[]);

    corto_debug("corto: loader: find '%s'", fileName);

    if (!(dl = corto_loadValidLibrary(fileName, &build))) {
        if (build) {
            corto_seterr("%s: uses a different corto build (%s)", fileName, build);
        }
        goto error;
    }

    /* Lookup main function */
    proc = (int(*)(int,char*[]))corto_dlProc(dl, "cortomain");
    if (proc) {
        /* Call main */
        if (proc(argc, argv)) {
            if (!corto_lasterr()) {
                corto_seterr("cortomain failed");
            }
            goto error;
        }
    } else {
        corto_string ___ (*build)(void);

        /* Lookup build function */
        build = (corto_string ___ (*)(void))corto_dlProc(dl, "corto_getBuild");
        if (build) {
            corto_seterr("library '%s' linked with corto but does not have a cortomain",
                fileName);
            goto error;
        }
    }

    /* Add library to libraries list */
    corto_mutexLock (&corto_adminLock);
    if (!libraries) {
        libraries = corto_llNew();
    }
    corto_llInsert(libraries, dl);
    corto_mutexUnlock (&corto_adminLock);

    corto_debug("corto: library '%s' loaded", fileName);

    return 0;
error:
    if (dl) corto_dlClose(dl);
    return -1;
}

void (*corto_loaderResolveProc(corto_string procName))(void) {
    void (*result)(void) = NULL;

    /* Search libraries for specified symbol */
    corto_mutexLock (&corto_adminLock);
    corto_iter iter = corto_llIter(libraries);
    while (!result && corto_iterHasNext(&iter)) {
        corto_dl dl = corto_iterNext(&iter);
        result = (void(*)(void))corto_dlProc(dl, procName);
    }
    corto_mutexUnlock (&corto_adminLock);

    return result;
}

/*
 * An adapter on top of corto_loadLibrary to fit the corto_loadAction signature.
 */
int corto_loadLibraryAction(corto_string file, int argc, char* argv[], void *data) {
    CORTO_UNUSED(data);
    return corto_loadLibrary(file, argc, argv);
}

/* Load a package */
int corto_loadIntern(corto_string str, int argc, char* argv[], corto_bool try, corto_bool ignoreRecursive) {
    corto_char ext[16];
    struct corto_fileHandler* h;
    int result = -1;
    struct corto_fileAdmin *lib = NULL;

    corto_mutexLock(&corto_adminLock);
    lib = corto_fileAdminFind(str);
    if (lib) {
        if (lib->loading == corto_threadSelf()) {
            if (!ignoreRecursive) {
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
                corto_mutexUnlock(&corto_adminLock);
                goto loaded;
            }
        } else {
            result = lib->result;
            corto_mutexUnlock(&corto_adminLock);

            /* Other thread is loading library. Wait until finished */
            while (lib->loading) {
                corto_sleep(1, 0);
            }
            goto loaded;
        }
    }
    corto_mutexUnlock(&corto_adminLock);

    /* Get extension from filename */
    if (!corto_fileExtension(str, ext)) {
        goto error;
    }

    /* Handle known extensions */
    if (!strcmp(ext, "cx")) {
        if (corto_load("corto/ast", 0, NULL)) {
            corto_seterr("while loading .cx parser:\n  %s", corto_lasterr());
            goto error;
        }
    } else if (!strcmp(ext, "xml")) {
        if (corto_load("corto/fmt/xml", 0, NULL)) {
            corto_seterr("while loading .xml parser:\n  %s", corto_lasterr());
            goto error;
        }
    } else if (!strcmp(ext, "md")) {
        if (corto_load("corto/md", 0, NULL)) {
            corto_seterr("while loading .md parser:\n  %s", corto_lasterr());
            goto error;
        }
    }

    /* Lookup extension */
    corto_mutexLock(&corto_adminLock);
    h = corto_lookupExt(ext);
    if (h) {
        /* Load file */
        lib = corto_fileAdminAdd(str);
        corto_mutexUnlock(&corto_adminLock);
        result = h->load(str, argc, argv, h->userData);
        corto_mutexLock(&corto_adminLock);
        lib->loading = 0;
        lib->result = result;
    } else {
        if (!try) {
            corto_seterr(
                "unknown file extension '%s'",
                ext);
            corto_mutexUnlock(&corto_adminLock);
            goto error;
        }
        result = -1;
    }
    corto_mutexUnlock(&corto_adminLock);

    if (!result) {
        corto_ok("corto: '%s' loaded", str);
    }

    return result;
error:
    return -1;
loaded:
    return result;
}

/* Load a package */
int corto_load(corto_string str, int argc, char* argv[]) {
    return corto_loadIntern(str, argc, argv, FALSE, FALSE);
}

/* Try loading a package */
int corto_loadTry(corto_string str, int argc, char* argv[]) {
    return corto_loadIntern(str, argc, argv, TRUE, FALSE);
}

#ifndef CORTO_REDIS
static time_t corto_getModified(corto_string file) {
    struct stat attr;

    if (stat(file, &attr) < 0) {
        printf("failed to stat '%s' (%s)\n", file, strerror(errno));
    }

    return attr.st_mtime;
}

static corto_string corto_locatePackageIntern(
    corto_string lib,
    corto_string *base,
    corto_bool isLibrary)
{
    corto_string targetPath = NULL, homePath = NULL, usrPath = NULL;
    corto_string result = NULL;
    corto_string targetBuild = NULL, homeBuild = NULL, usrBuild = NULL;
    corto_string targetErr = NULL, homeErr = NULL, usrErr = NULL;
    corto_string details = NULL;
    time_t t = 0;

    /* Reset error */
    corto_seterr(NULL);

    /* Look for local packages first */
    targetPath = corto_envparse("$CORTO_TARGET/lib/corto/%s.%s/%s",
        CORTO_VERSION_MAJOR, CORTO_VERSION_MINOR, lib);
    if (!targetPath) {
        goto error;
    }
    if (corto_fileTest(targetPath)) {
        corto_debug("corto: found '%s' while looking for '%s'", targetPath, lib);
        if (!isLibrary || corto_checkLibrary(targetPath, &targetBuild)) {
            t = corto_getModified(targetPath);
            result = targetPath;
            if (base) {
                *base = corto_envparse("$CORTO_TARGET/%%s/corto/%s.%s",
                    CORTO_VERSION_MAJOR, CORTO_VERSION_MINOR);
            }
        } else {
            if (corto_lasterr() != NULL) {
                targetErr = corto_strdup(corto_lasterr());
                corto_seterr(NULL);
            }
        }
    } else {
        corto_debug("corto: '%s' not found while looking for '%s'", targetPath, lib);
    }

    /* Look for packages in CORTO_HOME */
    if (strcmp(corto_getenv("CORTO_HOME"), corto_getenv("CORTO_TARGET"))) {
        corto_string homePath = corto_envparse("$CORTO_HOME/lib/corto/%s.%s/%s",
            CORTO_VERSION_MAJOR, CORTO_VERSION_MINOR, lib);
        if (!homePath) {
            goto error;
        }
        if (corto_fileTest(homePath)) {
            corto_debug("corto: found '%s' while looking for '%s'", homePath, lib);
            time_t myT = corto_getModified(homePath);
            if ((myT > t) || !result) {
                if (!isLibrary || corto_checkLibrary(homePath, &homeBuild)) {
                    t = myT;
                    result = homePath;
                    if (base) {
                        *base = corto_envparse("$CORTO_HOME/%%s/corto/%s.%s",
                            CORTO_VERSION_MAJOR, CORTO_VERSION_MINOR);
                    }
                } else {
                    if (corto_lasterr() != NULL) {
                        homeErr = corto_strdup(corto_lasterr());
                        corto_seterr(NULL);
                    }
                }
            } else if (!result) {
                corto_debug("corto: discarding '%s' because '%s' is newer", homePath, result);
            }
        } else {
            corto_debug("corto: '%s' not found while looking for '%s'", homePath, lib);
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
            corto_debug("corto: found '%s' while looking for '%s'", usrPath, lib);
            time_t myT = corto_getModified(usrPath);
            if ((myT >= t) || !result) {
                if (!isLibrary || corto_checkLibrary(usrPath, &usrBuild)) {
                    t = myT;
                    result = usrPath;
                    if (base) {
                        *base = corto_envparse("/usr/local/%%s/corto/%s.%s",
                            CORTO_VERSION_MAJOR, CORTO_VERSION_MINOR);
                    }
                } else {
                    if (corto_lasterr() != NULL) {
                        usrErr = corto_strdup(corto_lasterr());
                        corto_seterr(NULL);
                    }
                }
            } else if (!result) {
                corto_debug("corto: discarding '%s' because '%s' is newer", usrPath, result);
            }
        } else {
            corto_debug("corto: '%s' not found while looking for '%s'", usrPath, lib);
        }
    }

    corto_string targetDetail = NULL, homeDetail = NULL, usrDetail = NULL;
    if (targetBuild) {
        corto_asprintf(
          &targetDetail,
          "\n- %s found but uses different corto build ('%s')",
          targetPath, targetBuild);
        corto_dealloc(targetBuild);
    }
    if (homeBuild) {
        corto_asprintf(
          &homeDetail,
          "\n- %s found but uses different corto build ('%s')",
          homePath, homeBuild);
        corto_dealloc(homeBuild);
    }
    if (usrBuild) {
        corto_asprintf(
          &usrDetail,
          "\n- %s found but uses different corto build ('%s')",
          usrPath, usrBuild);
        corto_dealloc(usrBuild);
    }

    if (targetDetail || homeDetail || usrDetail ||
        targetErr || homeErr || usrErr)
    {
        corto_asprintf(&details,
          "%s%s%s%s%s%s%s%s%s",
          targetDetail ? targetDetail : "",
          targetErr ? "\n- " : "",
          targetErr ? targetErr : "",
          homeDetail ? homeDetail : "",
          homeErr ? "\n- " : "",
          homeErr ? homeErr : "",
          usrDetail ? usrDetail : "",
          usrErr ? "\n- " : "",
          usrErr ? usrErr : "");
        if (targetDetail) corto_dealloc(targetDetail);
        if (homeDetail) corto_dealloc(homeDetail);
        if (usrDetail) corto_dealloc(usrDetail);
    }

    if (targetPath && (targetPath != result)) corto_dealloc(targetPath);
    if (homePath && (homePath != result)) corto_dealloc(homePath);
    if (usrPath && (usrPath != result)) corto_dealloc(usrPath);

    if (!result) {
        corto_seterr(details);
    }
    corto_setinfo(details);
    corto_dealloc(details);

    return result;
error:
    return NULL;
}
#endif

corto_string corto_locateGetName(corto_string package, corto_loaderLocationKind kind) {
    corto_string result = corto_strdup(package);
    corto_string name;

    if (package[0] == '/') {
        name = corto_replaceColons(result, package + 1);
    } else if (package[0] == ':') {
        name = corto_replaceColons(result, package + 2);
    } else {
        name = corto_replaceColons(result, package);
    }

    if (kind == CORTO_LOCATION_NAME) {
        name = corto_strdup(name);
        corto_dealloc(result);
        result = name;
    }

    return result;
}

corto_string corto_locate(corto_string package, corto_loaderLocationKind kind) {
    corto_string relativePath = corto_packageToFile(package);
    corto_string result = NULL;

    if (!relativePath) {
        goto error;
    }

#ifdef CORTO_REDIS
    if (!corto_checkLibrary(relativePath, NULL)) {
        goto error;
    }

    result = relativePath;
    switch(kind) {
    case CORTO_LOCATION_ENV:
    case CORTO_LOCATION_LIBPATH:
    case CORTO_LOCATION_INCLUDE:
        corto_dealloc(result);
        result = corto_strdup("");
        break;
    case CORTO_LOCATION_LIB:
        /* Result is already pointing to the lib */
        break;
    case CORTO_LOCATION_NAME:
    case CORTO_LOCATION_FULLNAME: {
        corto_dealloc(result);
        result = corto_locateGetName(package, kind);
        break;
    }
    }
#else
    corto_string base = NULL;
    result = corto_locatePackageIntern(relativePath, &base, TRUE);
    if (!result && (kind == CORTO_LOCATION_ENV)) {
        result = corto_locatePackageIntern(package, &base, FALSE);
    }
    corto_dealloc(relativePath);
    if (result) {
        switch(kind) {
        case CORTO_LOCATION_ENV:
            /* Quick & dirty trick to strip everything but the env */
            corto_dealloc(result);
            corto_asprintf(&result, base, "@");
            *(strchr(result, '@') - 1) = '\0'; /* Also strip the '/' */
            break;
        case CORTO_LOCATION_LIB:
            /* Result is already pointing to the lib */
            break;
        case CORTO_LOCATION_LIBPATH: {
            corto_dealloc(result);
            corto_string lib;
            corto_asprintf(&lib, base, "lib");
            corto_asprintf(&result, "%s/%s", lib, package);
            break;
        }
        case CORTO_LOCATION_INCLUDE: {
            corto_dealloc(result);
            corto_string include;
            corto_asprintf(&include, base, "include");
            corto_asprintf(&result, "%s/%s", include, package);
            corto_dealloc(include);
            break;
        }
        case CORTO_LOCATION_NAME:
        case CORTO_LOCATION_FULLNAME: {
            corto_dealloc(result);
            result = corto_locateGetName(package, kind);
            break;
        }
        }
        corto_dealloc(base);
    }
#endif


    return result;
error:
    return NULL;
}

corto_ll corto_loadGetDependencies(corto_string file) {
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

    fileName = corto_locate(package, CORTO_LOCATION_LIB);
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

    /* Always try loading packages before anything else */
    if (!corto_packageLoader(file)) {
        return 0;
    }

    sprintf(testName, "%s.xml", file);
    if (corto_fileTest(testName)) {
        corto_trace("corto: load '%s'", testName);
        if (!corto_load("corto/fmt/xml", 0, NULL)) {
            return corto_load(testName, argc, argv);
        }
    }

    sprintf(testName, "%s.cx", file);
    if (corto_fileTest(testName)) {
        corto_trace("corto: load '%s'", testName);
        if (!corto_load("corto/ast", 0, NULL)) {
            return corto_load(testName, argc, argv);
        }
    }

    return -1;
}

void corto_loaderOnExit(void* udata) {
    struct corto_fileHandler* h;
    corto_dl dl;
    corto_iter iter;

    CORTO_UNUSED(udata);

    /* Free loaded administration (always happens from mainthread) */

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
