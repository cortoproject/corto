/*
 * cx_loader.c
 *
 *  Created on: Aug 30, 2012
 *      Author: sander
 */

#include "cx_loader.h"
#include "string.h"
#include "cx_err.h"
#include "cx_util.h"
#include "cx_mem.h"
#include "cx_ll.h"
#include "cx_dl.h"
#include "stdlib.h"

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

static cx_ll filesLoaded = NULL;

/* Load known filetypes */
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

/* Load library */
int cx_libraryLoader(cx_string _file, void* udata) {
	cx_dl dl;
	cx_string filename = NULL, file = NULL;
	int (*proc)(int argc, char* argv[]);

	CX_UNUSED(udata);

	/* Convert scoped name to filename */
	if (strchr(_file, ':')) {
	    cx_char ch, *ptr, *bptr;
	    ptr = _file;
	    file = malloc(strlen(_file)+1);
	    filename = file;
	    ptr = _file;
	    bptr = file;
	    while((ch=*ptr)) {
	        switch(ch) {
	        case ':':
	            *bptr = '/';
	            bptr++;
	            ptr++;
	            filename = bptr;
	            break;
	        default:
	            *bptr = ch;
	            bptr++;
	            break;
	        }
	        ptr++;
	    }
	    *bptr = '\0';
	} else {
	    file = cx_strdup(_file);
	    filename = file;
	}

	/* Load shared object from CORTEX_HOME */
	dl = cx_dlOpen(file);
	if (!dl) {
	    int length;
	    cx_char path[256];
	    cx_char str[256];
	    cx_string err;
        cx_string cortexHome = getenv("CORTEX_HOME");
	    err = cx_strdup(cx_dlError());
	    length = (cx_word)filename - (cx_word)file;
        memcpy(path, file, length);
        path[length]='\0';
        if (length) {
            sprintf(str, "%s/bin/%slib%s.so", cortexHome, path, filename);
        } else {
            sprintf(str, "lib%s.so", filename);
        }
	    if (!(dl = cx_dlOpen(str))) {
	    	cx_error("cx_libraryLoader: %s, %s", err, cx_dlError());
	        goto error;
	    }
	    cx_dealloc(err);
	}

	/* Lookup main function */
	proc = (int(*)(int,char*[]))cx_dlProc(dl, "cortexmain");
	if (!proc) {
		cx_error("unresolved 'cortexmain' in library '%s'.", file);
		goto error;
	}

	/* Call main */
	if (proc(0, NULL)) {
		cx_error("%s: cortexmain failed.", file);
		goto error;
	}

	/* Add library to libraries list */
	if (!libraries) {
		libraries = cx_llNew();
	}
	cx_llInsert(libraries, dl);

	if (file) {
	    cx_dealloc(file);
	}

	return 0;
error:
    if (file) {
        cx_dealloc(file);
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
	cx_loaderRegister("", cx_libraryLoader, NULL);
	cx_loaderRegister("so", cx_libraryLoader, NULL);
	cx_loaderRegister("dll", cx_libraryLoader, NULL);
}





