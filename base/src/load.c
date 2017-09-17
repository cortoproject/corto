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

#include <include/base.h>

#ifdef CORTO_LOADER

static corto_dl corto_load_validLibrary(char* fileName, char* *build_out);
static int corto_load_fromDl(corto_dl dl, char *fileName, int argc, char *argv[]);

void corto_onexit(void(*handler)(void*),void*userData);

static corto_ll fileHandlers = NULL;
static corto_ll loadedAdmin = NULL;
static corto_ll libraries = NULL;

/* Static variables set during initialization that contain paths to packages */
static char *targetEnv, *homeEnv, *globalEnv;
static char *targetPath, *homePath, *globalPath;
static char *targetBase, *homeBase, *globalBase;

static char *majorVersion, *minorVersion;

extern corto_mutex_s corto_adminLock;

struct corto_loadedAdmin {
    char* name;
    corto_thread loading;
    int16_t result;
    corto_dl library;
    char *filename;
    char *base;
};

struct corto_fileHandler {
    char* ext;
    corto_load_cb load;
    void* userData;
};

/* Initialize paths necessary for loader */
void corto_load_init(char *target, char *home, char *global, char *major, char *minor) {
    targetEnv = target;
    homeEnv = home;
    globalEnv = global;
    majorVersion = major;
    minorVersion = minor;

    /* Target path - where packages are being built */
    targetPath = corto_asprintf(
        "$CORTO_TARGET/lib/corto/%s.%s", 
        majorVersion, 
        minorVersion);

    /* Home path - where corto is located */
    homePath = corto_asprintf(
        "$CORTO_HOME/lib/corto/%s.%s", 
        majorVersion, 
        minorVersion);

    /* Global path - where the global package repository is (all users) */
    globalPath = corto_asprintf(
        "/usr/local/lib/corto/%s.%s", 
        majorVersion, 
        minorVersion);


    /* Precompute base with parameter for lib, etc, include */
    targetBase = corto_asprintf(
        "$CORTO_TARGET/%%s/corto/%s.%s", 
        majorVersion, 
        minorVersion);

    /* Home path - where corto is located */
    homeBase = corto_asprintf(
        "$CORTO_HOME/%%s/corto/%s.%s", 
        majorVersion, 
        minorVersion);

    /* Global path - where the global package repository is (all users) */
    globalBase = corto_asprintf(
        "/usr/local/%%s/corto/%s.%s", 
        majorVersion, 
        minorVersion);    
}

static char* corto_ptr_castToPath(char* lib, corto_id path) {
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

/* Lookup loaded library by name */
static struct corto_loadedAdmin* corto_loadedAdminFind(char* name) {
    if (loadedAdmin) {
        corto_iter iter = corto_ll_iter(loadedAdmin);
        struct corto_loadedAdmin *lib;
        corto_id libPath, adminPath;

        corto_ptr_castToPath(name, libPath);

        while (corto_iter_hasNext(&iter)) {
            lib = corto_iter_next(&iter);
            corto_ptr_castToPath(lib->name, adminPath);
            if (!strcmp(adminPath, libPath)) {
                return lib;
            }
        }
    }

    return NULL;
}

/* Add file */
static struct corto_loadedAdmin* corto_loadedAdminAdd(char* library) {
    struct corto_loadedAdmin *lib = corto_calloc(sizeof(struct corto_loadedAdmin));
    lib->name = corto_strdup(library);
    lib->loading = corto_thread_self();
    if (!loadedAdmin) {
        loadedAdmin = corto_ll_new();
    }
    corto_ll_insert(loadedAdmin, lib);
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
static struct corto_fileHandler* corto_lookupExt(char* ext) {
    struct corto_fileHandler dummy, *dummy_p;

    dummy.ext = ext;
    dummy_p = &dummy;

    /* Walk handlers */
    if (fileHandlers) {
        corto_ll_walk(fileHandlers, (corto_elementWalk_cb)corto_lookupExtWalk, &dummy_p);
    }

    if (dummy_p == &dummy) {
        dummy_p = NULL;
    }

    return dummy_p;
}

/* Register a filetype */
int corto_load_register(char* ext, corto_load_cb handler, void* userData) {
    struct corto_fileHandler* h;

    /* Check if extension is already registered */
    corto_mutex_lock(&corto_adminLock);
    if ((h = corto_lookupExt(ext))) {
        if (h->load != handler) {
            corto_error("corto_load_register: extension '%s' is already registered with another loader.", ext);
            abort();
            goto error;
        }
    } else {
        h = corto_alloc(sizeof(struct corto_fileHandler));
        h->ext = ext;
        h->load = handler;
        h->userData = userData;

        if (!fileHandlers) {
            fileHandlers = corto_ll_new();
        }

        corto_trace("load: registered extension '%s'", ext);
        corto_ll_append(fileHandlers, h);
    }
    corto_mutex_unlock(&corto_adminLock);

    return 0;
error:
    return -1;
}

static char* strreplaceColons(corto_id buffer, char* package) {
    char ch, *ptr, *bptr;
    char* fileName, *start;

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
static char* corto_packageToFile(char* package) {
    char* path;
#ifdef CORTO_REDIS
    path = corto_asprintf("lib%s.so", package[0] == '/' ? package + 1 : package);
    char ch, *ptr;
    for (ptr = path; (ch = *ptr); ptr++) {
        if (ch == '/') *ptr = '_';
    }
#else
    char* fileName;
    int fileNameLength;
    path = malloc(strlen(package) * 2 + strlen("/lib.so") + 1);
    fileName = strreplaceColons(path, package);
    fileNameLength = strlen(fileName);
    memcpy(fileName + fileNameLength, "/lib", 4);
    memcpy(fileName + fileNameLength + 4, fileName, fileNameLength);
    memcpy(fileName + fileNameLength * 2 + 4, ".so\0", 4);
#endif
    return path;
}

/* Forward declaration of corto_getBuild and corto_getLibrary */
char* corto_getBuild(void);
char* corto_getLibrary(void);

static corto_dl corto_load_validLibrary(char* fileName, char* *build_out) {
    corto_dl result = NULL;
    char* ___ (*build)(void);
    char* ___ (*library)(void);

    if (build_out) {
        *build_out = NULL;
    }

    if (!(result = corto_dl_open(fileName))) {
        corto_seterr("%s", corto_dl_error());
        goto error;
    }

    /* Lookup build function */
    build = (char* ___ (*)(void))corto_dl_proc(result, "corto_getBuild");
    library = (char* ___ (*)(void))corto_dl_proc(result, "corto_getLibrary");

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
          "loader: '%s' links with correct corto library\n  build:   '%s'\n  library: '%s'\n",
          fileName, build(), library());
    } else {
        corto_trace("loader: found '%s' which doesn't link with corto", fileName);
    }

    /* If no build function is available, the library is not linked with
     * Corto, and probably represents a --nocorto package */

    return result;
error:
    if (result) corto_dl_close(result);
    return NULL;
}

static bool corto_checkLibrary(char* fileName, char* *build_out, corto_dl *dl_out) {
    corto_dl dl = corto_load_validLibrary(fileName, build_out);

    bool result = FALSE;
    if (dl) {
        result = TRUE;
        if (!dl_out) {
            corto_dl_close(dl);
        } else {
            if (*dl_out) {
                corto_dl_close(*dl_out);
            }
            *dl_out = dl;
        }
    }

    return result;
}

/* Load from a dynamic library */
static int corto_load_fromDl(corto_dl dl, char *fileName, int argc, char *argv[]) {
    int (*proc)(int argc, char* argv[]);

    corto_assert(fileName != NULL, "NULL passed to corto_load_fromDl");

    corto_debug("loader: invoke cortomain of '%s' with %d arguments", fileName, argc);

    /* Lookup main function */
    proc = (int(*)(int,char*[]))corto_dl_proc(dl, "cortomain");
    if (proc) {
        /* Call main */
        if (proc(argc, argv)) {
            if (!corto_lasterr()) {
                corto_seterr("cortomain failed");
            }
            goto error;
        }
    } else {
        char* ___ (*build)(void);

        /* Lookup build function */
        build = (char* ___ (*)(void))corto_dl_proc(dl, "corto_getBuild");
        if (build) {
            corto_seterr("library '%s' linked with corto but does not have a cortomain",
                fileName);
            goto error;
        }
    }

    /* Add library to libraries list */
    corto_mutex_lock (&corto_adminLock);    
    if (!libraries || !corto_ll_hasObject(libraries, dl)) {
        if (!libraries) {
            libraries = corto_ll_new();
        }

        corto_ll_insert(libraries, dl);
        corto_debug("loader: loaded '%s'", fileName);        
    }
    corto_mutex_unlock (&corto_adminLock);

    return 0;
error:
    return -1;
}

/*
 * Load a Corto library
 * Receives the absolute path to the lib<name>.so file.
 */
static int corto_loadLibrary(char* fileName, bool validated, corto_dl *dl_out, int argc, char* argv[]) {
    corto_dl dl = NULL;
    char* build = NULL;

    corto_assert(fileName != NULL, "NULL passed to corto_loadLibrary");

    corto_seterr(NULL);
    if (!validated) {
        dl = corto_load_validLibrary(fileName, &build);
    } else {
        dl = corto_dl_open(fileName);
    }

    if (!dl) {
        if (build) {
            corto_seterr("%s: uses a different corto build (%s)", fileName, build);
        } else {
            if (corto_lasterr()) {
                corto_seterr("%s", corto_lasterr());
            } else {
                corto_seterr("%s: %s", fileName, corto_dl_error());
            }
        }
        goto error;
    }

    if (corto_load_fromDl(dl, fileName, argc, argv)) {
        goto error;
    }

    if (dl_out) {
        *dl_out = dl;
    }

    return 0;
error:
    if (dl) corto_dl_close(dl);
    return -1;
}

/*
 * An adapter on top of corto_loadLibrary to fit the corto_load_cb signature.
 */
int corto_loadLibraryAction(char* file, int argc, char* argv[], void *data) {
    CORTO_UNUSED(data);
    return corto_loadLibrary(file, FALSE, NULL, argc, argv);
}

/* Load a package */
int corto_loadIntern(char* str, int argc, char* argv[], bool try, bool ignoreRecursive, bool alwaysRun) {
    char ext[16];
    struct corto_fileHandler* h;
    int result = -1;
    struct corto_loadedAdmin *lib = NULL;

    corto_mutex_lock(&corto_adminLock);
    lib = corto_loadedAdminFind(str);
    if (lib && lib->library) {
        if (lib->loading == corto_thread_self()) {
            goto recursive;
        } else {
            result = lib->result;
            corto_mutex_unlock(&corto_adminLock);

            /* Other thread is loading library. Wait until finished */
            while (lib->loading) {
                corto_sleep(1, 0);
            }

            if (alwaysRun) {
                result = corto_load_fromDl(lib->library, lib->filename, argc, argv);
            }

            goto loaded;
        }
    }

    corto_mutex_unlock(&corto_adminLock);

    /* Get extension from filename */
    if (!corto_file_extension(str, ext)) {
        goto error;
    }

    /* Lookup extension */
    corto_mutex_lock(&corto_adminLock);
    h = corto_lookupExt(ext);

    if (!h) {
        corto_id extPackage;
        sprintf(extPackage, "driver/ext/%s", ext);
        corto_mutex_unlock(&corto_adminLock);
        if (corto_load(extPackage, 0, NULL)) {
            if (!try) {
                corto_seterr(
                    "unable to load file '%s' with extension '%s': %s",
                    str,
                    ext,
                    corto_lasterr());
                goto error;
            }
            result = -1;            
        }
        corto_mutex_lock(&corto_adminLock);
        h = corto_lookupExt(ext);
        if (!h) {
            corto_seterr(
                "package 'driver/ext/%s' loaded but extension is not registered", 
                ext);
            corto_mutex_unlock(&corto_adminLock);
            goto error;
        }
    }

    /* Load file */
    if (!lib) {
        lib = corto_loadedAdminAdd(str);
        corto_mutex_unlock(&corto_adminLock);
        result = h->load(str, argc, argv, h->userData);
    } else if (lib->filename) {
        if (lib->loading == corto_thread_self()) {
            goto recursive;
        }
        corto_mutex_unlock(&corto_adminLock);
        lib->loading = corto_thread_self();
        result = corto_loadLibrary(lib->filename, TRUE, &lib->library, argc, argv);
    } else {
        corto_mutex_unlock(&corto_adminLock);
        corto_seterr("'%s' is not a loadable package", lib->name);
        result = -1;
    }
    
    corto_mutex_lock(&corto_adminLock);

    lib->loading = 0;
    lib->result = result;

    corto_mutex_unlock(&corto_adminLock);

    if (!result) {
        corto_trace("loader: loaded '%s'", str[0] == '/' ? &str[1] : str);
    }

    return result;
error:
    return -1;
recursive:
    if (!ignoreRecursive) {
        corto_error("illegal recursive load of file '%s' from:", lib->name);
        corto_iter iter = corto_ll_iter(loadedAdmin);
        while (corto_iter_hasNext(&iter)) {
            struct corto_loadedAdmin *lib = corto_iter_next(&iter);
            if (lib->loading) {
                fprintf(stderr, "   %s\n", lib->name);
            }
        }
        corto_backtrace(stderr);
        abort();
    } else {
        corto_mutex_unlock(&corto_adminLock);
    }
loaded:
    return result;
}

/* Load a package */
int corto_load(char* str, int argc, char* argv[]) {
    return corto_loadIntern(str, argc, argv, FALSE, FALSE, FALSE);
}

/* Run a package */
int corto_run(char* str, int argc, char* argv[]) {
    return corto_loadIntern(str, argc, argv, FALSE, FALSE, TRUE);
}

/* Try loading a package */
int corto_load_try(char* str, int argc, char* argv[]) {
    return corto_loadIntern(str, argc, argv, TRUE, FALSE, FALSE);
}

#ifndef CORTO_REDIS
static time_t corto_getModified(char* file) {
    struct stat attr;

    if (stat(file, &attr) < 0) {
        corto_error("failed to stat '%s' (%s)\n", file, strerror(errno));
    }

    return attr.st_mtime;
}

/* Locate the right environment for a corto package.
 * Input 'foo/bar'
 * Output: '/home/me/.corto/lib/corto/1.1/foo/bar'
 */
static char* corto_locatePackageIntern(
    char* lib,
    char* *base,
    corto_dl *dl_out,
    bool isLibrary)
{
    char *targetLib, *homeLib, *usrLib;
    char *result = NULL;
    char *targetBuild = NULL, *homeBuild = NULL, *usrBuild = NULL;
    char *targetErr = NULL, *homeErr = NULL, *usrErr = NULL;
    char *details = NULL;
    bool fileError = FALSE;
    corto_dl dl = NULL;
    time_t t = 0;

    corto_assert(targetPath != NULL, "targetPath is not set");
    corto_assert(homePath != NULL, "homePath is not set");
    corto_assert(globalPath != NULL, "globalPath is not set");

    /* Reset error */
    corto_seterr(NULL);

    /* Look for local packages first */
    if (!(targetLib = corto_asprintf("%s/%s", targetPath, lib))) {
        goto error;
    }    
    if (corto_file_test(targetLib)) {
        corto_debug("loader: locate '%s': found '%s'", lib, targetLib);
        if (!isLibrary || corto_checkLibrary(targetLib, &targetBuild, &dl)) {
            t = corto_getModified(targetLib);
            result = targetLib;
            if (base) {
                *base = targetBase;
            }
        } else {
            if (corto_lasterr() != NULL) {
                targetErr = corto_strdup(corto_lasterr());
                corto_seterr(NULL);
            }
        }
    } else {
        if (corto_lasterr()) {
            targetErr = corto_strdup(corto_lasterr());
            fileError = TRUE;
        } else {
            corto_debug("loader: locate '%s': '%s' not found", lib, targetLib);
        }
    }

    /* Look for packages in CORTO_HOME */
    if (strcmp(corto_getenv("CORTO_HOME"), corto_getenv("CORTO_TARGET"))) {
        if (!(homeLib = corto_asprintf("%s/%s", homePath, lib))) {
            goto error;
        }
        if (corto_file_test(homeLib)) {
            time_t myT = corto_getModified(homeLib);
            corto_debug("loader: locate '%s': found '%s'", lib, homeLib);
            if ((myT >= t) || !result) {
                if (!isLibrary || corto_checkLibrary(homeLib, &homeBuild, &dl)) {
                    t = myT;
                    result = homeLib;
                    if (base) {
                        *base = homeBase;
                    }
                } else {
                    if (corto_lasterr() != NULL) {
                        homeErr = corto_strdup(corto_lasterr());
                        corto_seterr(NULL);
                    }
                }
            } else if (!result) {
                corto_debug("loader: discarding '%s' because '%s' is newer", homeLib, result);
            }
        } else {
            if (corto_lasterr()) {
                homeErr = corto_strdup(corto_lasterr());
                fileError = TRUE;
            } else {
                corto_debug("loader: locate '%s': '%s' not found", lib, homeLib);
            }
        }
    } else {
        corto_debug("loader: locate '%s': '%s' already searched ($CORTO_HOME == $CORTO_TARGET)",
            lib, corto_getenv("CORTO_HOME"));
    }

    /* Look for global packages */
    if (strcmp("/usr/local", corto_getenv("CORTO_TARGET")) &&
        strcmp("/usr/local", corto_getenv("CORTO_HOME"))) {
        if (!(usrLib = corto_asprintf("%s/%s", globalPath, lib))) {
            goto error;
        }
        if (corto_file_test(usrLib)) {
            time_t myT = corto_getModified(usrLib);
            corto_debug("loader: locate '%s': found '%s'", usrLib, lib);
            if ((myT >= t) || !result) {
                if (!isLibrary || corto_checkLibrary(usrLib, &usrBuild, &dl)) {
                    t = myT;
                    result = usrLib;
                    if (base) {
                        *base = globalBase;
                    }
                } else {
                    if (corto_lasterr() != NULL) {
                        usrErr = corto_strdup(corto_lasterr());
                        corto_seterr(NULL);
                    }
                }
            } else if (!result) {
                corto_debug("loader: discarding '%s' because '%s' is newer", usrLib, result);
            }
        } else {
            if (corto_lasterr()) {
                usrErr = corto_strdup(corto_lasterr());
                fileError = TRUE;
            } else {
                corto_debug("loader: locate '%s': '%s' not found", lib, usrLib);
            }
        }
    } else {
        corto_debug("loader: locate '%s': '/usr/local' already searched ($CORTO_HOME='%s' $CORTO_TARGET='%s')",
            lib, corto_getenv("CORTO_HOME"), corto_getenv("CORTO_TARGET"));
    }

    char *targetDetail = NULL, *homeDetail = NULL, *usrDetail = NULL;
    if (targetBuild) {
        targetDetail = corto_asprintf(
          "\n- %s found but uses different corto build ('%s')",
          targetLib, targetBuild);
        corto_dealloc(targetBuild);
    }
    if (homeBuild) {
        homeDetail = corto_asprintf(
          "\n- %s found but uses different corto build ('%s')",
          homeLib, homeBuild);
        corto_dealloc(homeBuild);
    }
    if (usrBuild) {
        usrDetail = corto_asprintf(
          "\n- %s found but uses different corto build ('%s')",
          usrLib, usrBuild);
        corto_dealloc(usrBuild);
    }

    if (targetDetail || homeDetail || usrDetail ||
        targetErr || homeErr || usrErr)
    {
        details = corto_asprintf(
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

    if (targetLib && (targetLib != result)) corto_dealloc(targetLib);
    if (homeLib && (homeLib != result)) corto_dealloc(homeLib);
    if (usrLib && (usrLib != result)) corto_dealloc(usrLib);

    /* If there is a problem with one of the environments, don't load package */
    if (fileError) {
        if (result) {
            corto_dealloc(result);
            result = NULL;
        }
    }

    if (!result) {
        if (details) {
            if (fileError) {
                corto_seterr(details);
            }
        } else {
            corto_setinfo("library '%s' not found", lib);
        }
        if (dl) {
            corto_dl_close(dl);
            dl = NULL;
        }
    }

    if (dl_out) {
        *dl_out = dl;
    }

    if (details) {
        corto_setinfo(details);
        corto_dealloc(details);
    }

    return result;
error:
    return NULL;
}
#endif

char* corto_locateGetName(char* package, corto_load_locateKind kind) {
    char* result = corto_strdup(package);
    char* name;

    if (package[0] == '/') {
        name = strreplaceColons(result, package + 1);
    } else if (package[0] == ':') {
        name = strreplaceColons(result, package + 2);
    } else {
        name = strreplaceColons(result, package);
    }

    if (kind == CORTO_LOCATION_NAME) {
        name = corto_strdup(name);
        corto_dealloc(result);
        result = name;
    }

    return result;
}

char* corto_locate(char* package, corto_dl *dl_out, corto_load_locateKind kind) {
    char* relativePath = NULL;
    char* result = NULL;

#ifndef CORTO_REDIS
    corto_dl dl = NULL;
    char* base = NULL;
    struct corto_loadedAdmin *loaded = NULL;

    /* If package has been loaded already, don't resolve it again */
    loaded = corto_loadedAdminFind(package);
    if (loaded) {
        result = loaded->filename ? corto_strdup(loaded->filename) : NULL;
        base = loaded->base;
    }    
#endif

    if (!result) {
        relativePath = corto_packageToFile(package);
        if (!relativePath) {
            goto error;
        }
    }

#ifdef CORTO_REDIS
    if (!corto_checkLibrary(relativePath, NULL, dl_out)) {
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

    bool setLoadAdminWhenFound = TRUE;
    if (!loaded || (!result && loaded->loading)) {
        result = corto_locatePackageIntern(relativePath, &base, &dl, TRUE);
        if (!result && (kind == CORTO_LOCATION_ENV)) {
            corto_lasterr();
            result = corto_locatePackageIntern(package, &base, &dl, FALSE);
            setLoadAdminWhenFound = FALSE;
        }
    }
    if (relativePath) corto_dealloc(relativePath);

    if (result) {
        if (!loaded) {
            loaded = corto_loadedAdminAdd(package);
            loaded->loading = 0;
        }

        if (!loaded->filename && setLoadAdminWhenFound) {
            corto_mutex_lock(&corto_adminLock);
            strset(&loaded->filename, result);
            strset(&loaded->base, base);
            if (dl_out) {
                loaded->library = dl;
            }
            corto_mutex_unlock(&corto_adminLock);
        }

        switch(kind) {
        case CORTO_LOCATION_ENV:
            /* Quick & dirty trick to strip everything but the env */
            result = corto_asprintf(base, "@");
            *(strchr(result, '@') - 1) = '\0'; /* Also strip the '/' */
            break;
        case CORTO_LOCATION_LIB:
            /* Result is already pointing to the lib */
            break;
        case CORTO_LOCATION_LIBPATH: {
            char* lib;
            lib = corto_asprintf(base, "lib");
            result = corto_asprintf("%s/%s", lib, package);
            break;
        }
        case CORTO_LOCATION_INCLUDE: {
            char* include;
            include = corto_asprintf(base, "include");
            result = corto_asprintf("%s/%s", include, package);
            corto_dealloc(include);
            break;
        }
        case CORTO_LOCATION_NAME:
        case CORTO_LOCATION_FULLNAME: {
            result = corto_locateGetName(package, kind);
            break;
        }
        }
    }

    if (dl_out) {
        if (loaded) {
            *dl_out = loaded->library;
        } else {
            *dl_out = NULL;
        }
    } else if (dl) {
        corto_dl_close(dl);
    }
#endif

    return result;
error:
    return NULL;
}

void* corto_load_sym(char *package, corto_dl *dl_out, char *symbol) {
    if (!*dl_out) {
        char *location = corto_locate(package, dl_out, CORTO_LOCATION_LIB);
        if (!*dl_out) {
            if (location) {
                *dl_out = corto_load_validLibrary(location, NULL);
            }
        }
    }

    if (*dl_out) {
        return corto_dl_sym(*dl_out, symbol);
    } else {
        return NULL;
    }
}


corto_ll corto_loadGetDependencies(char* file) {
    corto_ll result = NULL;

    if (corto_file_test(file)) {
        corto_id name;
        result = corto_ll_new();
        FILE* f = fopen(file, "r");
        char *dependency;
        while ((dependency = corto_file_readln(f, name, sizeof(name)))) {
            corto_ll_append(result, corto_strdup(dependency));
        }
        fclose(f);
    }

    return result;
}

static void corto_loadFreeDependencies(corto_ll dependencies) {
    if (dependencies) {
        corto_iter iter = corto_ll_iter(dependencies);
        while (corto_iter_hasNext(&iter)) {
            corto_dealloc(corto_iter_next(&iter));
        }
        corto_dealloc(dependencies);
    }
}

static bool corto_loadRequiresDependency(corto_ll dependencies, char* query) {
    bool result = FALSE;

    if (dependencies) {
        corto_iter iter = corto_ll_iter(dependencies);
        while (!result && corto_iter_hasNext(&iter)) {
            char* package = corto_iter_next(&iter);
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

bool corto_loadRequiresPackage(char* package) {
    corto_ll packages = corto_loadGetPackages();
    bool result = corto_loadRequiresDependency(packages, package);
    corto_loadFreePackages(packages);
    return result;
}

int corto_loadPackages(void) {
    corto_ll packages = corto_loadGetPackages();
    if (packages) {
        corto_iter iter = corto_ll_iter(packages);
        while (corto_iter_hasNext(&iter)) {
            corto_load(corto_iter_next(&iter), 0, NULL);
        }
        corto_loadFreePackages(packages);
    }
    return 0;
}

/* Load file with unspecified extension */
int corto_file_loader(char* package, int argc, char* argv[], void* ctx) {
    CORTO_UNUSED(ctx);
    char* fileName;
    int result;
    corto_dl dl = NULL;

    fileName = corto_locate(package, &dl, CORTO_LOCATION_LIB);
    if (!fileName) {
        corto_seterr(corto_lastinfo());
        return -1;
    }

    corto_assert(dl != NULL, "package located but dl_out is NULL");

    result = corto_load_fromDl(dl, fileName, argc, argv);
    corto_dealloc(fileName);
    if (result) {
        corto_seterr(corto_lastinfo());
    }

    return result;
}

void corto_loaderOnExit(void* ctx) {
    struct corto_fileHandler* h;
    corto_dl dl;
    corto_iter iter;

    CORTO_UNUSED(ctx);

    /* Free loaded administration (always happens from mainthread) */

    if (loadedAdmin) {
        iter = corto_ll_iter(loadedAdmin);
         while(corto_iter_hasNext(&iter)) {
             struct corto_loadedAdmin *loaded = corto_iter_next(&iter);
             corto_dealloc(loaded->name);
             corto_dealloc(loaded);
         }
         corto_ll_free(loadedAdmin);
    }

    /* Free handlers */
    while ((h = corto_ll_takeFirst(fileHandlers))) {
        corto_dealloc(h);
    }
    corto_ll_free(fileHandlers);

    /* Free libraries */
    if (libraries) {
        while ((dl = corto_ll_takeFirst(libraries))) {
            corto_dl_close(dl);
        }
        corto_ll_free(libraries);
    }
}

#else
int corto_load(char* str) {
    CORTO_UNUSED(str);
    corto_error("corto build doesn't include loader");
    return -1;
}
#endif
