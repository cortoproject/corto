/*
 * cx_loader.c
 *
 *  Created on: Aug 30, 2012
 *      Author: sander
 */

#include "cortex.h"
#include "stdlib.h"
#include "string.h"

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
int cx_lookupExtWalk(struct cx_fileHandler* h, struct cx_fileHandler** data) {
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
    while(ptr >= file) {
        if (*ptr == '.') break;
        ptr--;
    }
    if (ptr >= file) {
        ptr++;
        while((ch = *ptr)) {
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
        h = cx_malloc(sizeof(struct cx_fileHandler));
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
cx_string cx_packageToFile(cx_string package) {
    cx_char ch, *ptr, *bptr;
    cx_string fileName, path, start;
    cx_string cortexHome = getenv("CORTEX_HOME");
    int fileNameLength;

    ptr = package;
    path = malloc(strlen(package) * 2 + strlen(cortexHome) + strlen("/packages/bin//lib.so") + 1);
    sprintf(path, "%s/packages/", cortexHome);
    bptr = path + strlen(path);
    start = bptr;
    fileName = bptr;

    while((ch = *ptr)) {
        switch(ch) {
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
    memcpy(fileName + fileNameLength, "/bin/lib", 8);
    memcpy(fileName + fileNameLength + 8, fileName, fileNameLength);
    memcpy(fileName + fileNameLength * 2 + 8, ".so\0", 4);

    return path;
}

/* Load a cortex library */
int cx_loadLibrary(cx_string fileName) {
    cx_dl dl = NULL;
    int (*proc)(int argc, char* argv[]);

    if (!(dl = cx_dlOpen(fileName))) {
        cx_error("%s", cx_dlError());
        goto error;
    }

    /* Lookup main function */
    proc = (int(*)(int,char*[]))cx_dlProc(dl, "cortexmain");
    if (!proc) {
        cx_error("%s: unresolved 'cortexmain'", fileName);
        goto error;
    }

    /* Call main */
    if (proc(0, NULL)) {
        cx_error("%s: cortexmain failed", fileName);
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

static cx_ll filesLoaded = NULL;

/* Load xml interface */
int cx_loadXml(void) {
    cx_string cortexHome = getenv("CORTEX_HOME");
    int result;
    cx_string path = cx_malloc(strlen(cortexHome) + strlen("/bin/libxml.so") + 1);
    sprintf(path, "%s/bin/libxml.so", cortexHome);
    result = cx_loadLibrary(path);
    cx_dealloc(path);
    return result;
}

/* Load a package */
int cx_load(cx_string str){
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
        while(cx_iterHasNext(&iter)) {
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
        cx_load("cortex::Fast");
    } else if (!strcmp(ext, "xml")) {
        cx_loadXml();
    }

    /* Lookup extension */
    h = cx_lookupExt(ext);
    if (h) {
        /* Load file */
        result = h->load(str, h->userData);
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

/* Load package */
int cx_packageLoader(cx_string file) {
    cx_string fileName;
    int result;

    fileName = cx_packageToFile(file);
    if (!fileName) {
        return -1;
    }

    result = cx_loadLibrary(fileName);
    cx_dealloc(fileName);

    return result;
}

/* Load file with unspecified extension */
int cx_fileLoader(cx_string file, void* udata) {
    CX_UNUSED(udata);
    cx_id testName;
    
    sprintf(testName, "%s.xml", file);
    if (cx_fileTest(testName)) {
        if (!cx_loadXml()) {
            return cx_load(testName);
        }
    }

    sprintf(testName, "%s.cx", file);
    if (cx_fileTest(testName)) {
        if (!cx_load("cortex/Fast")) {
            return cx_load(testName);
        }
    }

    if (!cx_packageLoader(file)) {
        return 0;
    }

    return -1;
}

void cx_loaderOnExit(void* udata) {
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
    while((h = cx_llTakeFirst(fileHandlers))) {
        cx_dealloc(h);
    }
    cx_llFree(fileHandlers);

    /* Free libraries */
    if (libraries) {
        while((dl = cx_llTakeFirst(libraries))) {
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
    cx_loaderRegister("", cx_fileLoader, NULL);
}





